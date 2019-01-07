
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

using namespace std;

#define UTF8_MAX_SIZE (0x1fffff)
class Solution {
    enum {
        CHAR_ASCII = -2000,
        CHAR_NOT_COMPLETE = -2001,
        CHAR_UNKNOWN = -2002,
        FILE_EOF = -2100,
    };
#define GET_UTF8(num, ptr, buf) do { \
                                    if(*ptr == '\0') return CHAR_NOT_COMPLETE;\
                                    if((*ptr & 0xc0) != 0x80) { *buf = ptr + 1; return CHAR_UNKNOWN;}\
                                    num = *ptr++ & 0x3f; \
                                } while(0)

    public:
        int read_data(int fd, unsigned char *buf, int size) {
            int ret;

            do {
                ret = read(fd, buf, size - 1);
                if(ret < 0) {
                    if(errno == EINTR)
                        continue;

                    return ret;
                } else if(ret == 0) {
                    return FILE_EOF;
                }
            } while(ret < 0);

            buf[ret] = '\0';

            return ret;
        }
        int unicodetoutf8(unsigned char *buf, int utf8) {
            if(utf8 > 0x1fffff) {
                return -1;
            } else if(utf8 > 0x0ffff) {
                buf[0] = (utf8 >> 18) & 0x07;
                buf[0] |= 0xf0;
                buf[1] = (utf8 >> 12) & 0x3f;
                buf[1] |= 0x80;
                buf[2] = (utf8 >>  6) & 0x3f;
                buf[2] |= 0x80;
                buf[3] = (utf8 >>  0) & 0x3f;
                buf[3] |= 0x80;
                buf[4] = '\0';
            } else if(utf8 > 0x7ff) {
                buf[0] = (utf8 >> 12) & 0x0f;
                buf[0] |= 0xe0;
                buf[1] = (utf8 >>  6) & 0x3f;
                buf[1] |= 0x80;
                buf[2] = (utf8 >>  0) & 0x3f;
                buf[2] |= 0x80;
                buf[3] = '\0';
            } else if(utf8 > 0x7f) {
                buf[0] = (utf8 >>  6) & 0x1f;
                buf[0] |= 0xc0;
                buf[1] = (utf8 >>  0) & 0x3f;
                buf[1] |= 0x80;
                buf[2] = '\0';
            } else {
                buf[0] = utf8;
                buf[1] = '\0';
            }

            return 0;
        }
        int utf8tounicode(unsigned char **buf) {
            unsigned char *ptr = *buf;
            int result = CHAR_ASCII;

            if(*ptr & 0x80) {
                int num;
                result = 0;
                if((*ptr & 0xf8) == 0xf0) {
                    result |= (*ptr++ & 0x07) << 18;
                    GET_UTF8(num, ptr, buf);
                    result |= num << 12;
                    GET_UTF8(num, ptr, buf);
                    result |= num << 6;
                    GET_UTF8(num, ptr, buf);
                    result |= num;
                } else if((*ptr & 0xf0) == 0xe0) {
                    result |= (*ptr++ & 0x0f) << 12;
                    GET_UTF8(num, ptr, buf);
                    result |= num << 6;
                    GET_UTF8(num, ptr, buf);
                    result |= num;
                } else if((*ptr & 0xe0) == 0xc0) {
                    result |= (*ptr++ & 0x1f) << 12;
                    GET_UTF8(num, ptr, buf);
                    result |= num;
                } else {
                    result = CHAR_UNKNOWN;
                    ptr++;
                }
            } else {
                result = *ptr;
                ptr++;
            }

            *buf = ptr;

            return result;
        }
        int repeatedWord(const char *filename, unsigned int *lmap) {
            unsigned char buf[1024], *ptr;
            int fd, left = 0, len, ret;

            if((fd = open(filename, O_RDONLY)) < 0) {
                printf("read file:%s error:%s\n", filename, strerror(errno));
                return fd;
            }

            while(1) {
                len = read_data(fd, buf + left, sizeof(buf) - left);
                if(len < 0)
                    break;

                ptr = buf;
                //printf("read file:%s, left:%d\n", ptr, left);
                do {
                    ret = utf8tounicode(&ptr);
                    //printf("ret:0x%x,ptr:0x%x\n", ret, *ptr);
                    switch(ret) {
                        case CHAR_ASCII:
                            break;
                        case CHAR_NOT_COMPLETE:
                            left = buf + len - ptr;
                            if(left)
                                memcpy(buf, ptr, left);
                            break;
                        case CHAR_UNKNOWN:
                            break;
                        default:
                            if(ret > 0x7f && ret < UTF8_MAX_SIZE)
                                lmap[ret] ++;
                            break;
                    }
                } while(ret != CHAR_NOT_COMPLETE && ptr < buf + len);
            }

            close(fd);

            return 0;
        }
};

int main(int argc, char **argv)
{
    unsigned int *lmap;
    int i;
    Solution sol;

    if(argc < 2) {
        printf("Please enter a filename\n");
        return -EINVAL;
    }

    lmap = (unsigned int *)malloc(UTF8_MAX_SIZE * sizeof(int));
    memset(lmap, 0, UTF8_MAX_SIZE * sizeof(int));
    if(sol.repeatedWord(argv[1], lmap) < 0) {
        printf("Please check your input file\n");
        return -EINVAL;
    }
    
    for(i = 0;i < UTF8_MAX_SIZE;i++) {
        static int line = 0;
        unsigned char num[8];
        if(lmap[i] >= 1 && sol.unicodetoutf8(num, i) == 0) {
            printf("%d:%s:%d,0x%x\n", ++line, num, lmap[i], i);
        }
    }

    return 0;
}
