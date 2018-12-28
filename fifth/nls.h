#ifndef __NLS_H__
#define __NLS_H__
    
struct nls_table {
    const char *charset;
    const char *alias;
    int (*uni2char) (wchar_t uni, unsigned char *out, int boundlen);
    int (*char2uni) (const unsigned char *rawstring, int boundlen,
            wchar_t *uni);
    const unsigned char *charset2lower;
    const unsigned char *charset2upper;
}; 

struct nls_table *get_nls_cp936(void);

#endif
