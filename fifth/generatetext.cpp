
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

class Solution {
    public:
        int unicodetoutf8(unsigned char *buf, int utf8) {
            int ret = -1;
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
                ret = 4;
            } else if(utf8 > 0x7ff) {
                buf[0] = (utf8 >> 12) & 0x0f;
                buf[0] |= 0xe0;
                buf[1] = (utf8 >>  6) & 0x3f;
                buf[1] |= 0x80;
                buf[2] = (utf8 >>  0) & 0x3f;
                buf[2] |= 0x80;
                buf[3] = '\0';
                ret = 3;
            } else if(utf8 > 0x7f) {
                buf[0] = (utf8 >>  6) & 0x1f;
                buf[0] |= 0xc0;
                buf[1] = (utf8 >>  0) & 0x3f;
                buf[1] |= 0x80;
                buf[2] = '\0';
                ret = 2;
            } else {
                buf[0] = utf8;
                buf[1] = '\0';
                ret = 1;
            }

            return ret;
        }

        int generate(const char *filename, int maxn = 1000 * 1000) {
            unsigned char buf[1024], * ptr = buf;
            int fd, i, ret, utf8, left;

            srand(time(NULL));

            if((fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU | S_IRWXG)) < 0) {
                printf("create file:%s failed, reason:%s\n", filename, strerror(errno));
                return fd;
            }

            for(i = 0;i < maxn;i++) {
                do {
                    utf8 = rand() & 0x0ffff;
                } while(utf8 < 0x4E00 || utf8 > 0x9FA5);

                ptr += unicodetoutf8(ptr, utf8);

                if(buf + sizeof(buf) - 16 < ptr) {
                    ptr += sprintf((char *)ptr, "\n");

                    left = ptr - buf;
                    ptr = buf;
                    while(left > 0) {
                        ret = write(fd, ptr, left);
                        if(ret < 0) {
                            if(errno == EINTR)
                                continue;

                            return ret;
                        }

                        left -= ret;
                        ptr += ret;
                    }
                    ptr = buf;
                }
            }

            close(fd);

            return 0;
        }
};

int main(int argc, char **argv)
{
    Solution sol;

    if(argc < 2) {
        printf("Please enter a filename\n");
        return -EINVAL;
    }

    if(sol.generate(argv[1], 10 * 1000 * 1000) < 0) {
        printf("generate failed\n");
        return -EINVAL;
    }

    return 0;
}
