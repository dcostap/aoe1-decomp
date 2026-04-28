// 00476AB0 TEditPanel::get_trimmed_str
// PDB: pnl_edit.cpp:1017-1054, 248 bytes
// char* __thiscall get_trimmed_str(char* param_1, int param_2)
// ret 8 (2 params)
// FLAGS: default

#include <string.h>

extern "C" int __cdecl __ismbcspace(int);
extern "C" unsigned char* __cdecl __mbsinc(const unsigned char*);
extern "C" unsigned char* __cdecl __mbsncpy(unsigned char*, const unsigned char*, int);
extern "C" unsigned char* __cdecl __mbsdec(const unsigned char*, const unsigned char*);

class TEditPanel {
public:
    char _gap_000[0xFC];
    char* text;                      // +0xFC

    void update_text();
    char* get_trimmed_str(char* dst, int maxlen);
};

char* TEditPanel::get_trimmed_str(char* dst, int maxlen)
{
    char temp_str[256];
    unsigned char* base;
    unsigned char* p;
    unsigned char* cur;

    this->update_text();

    memset(temp_str, 0, sizeof(temp_str));
    strcpy(temp_str, this->text);

    // Zero dest buffer
    memset(dst, 0, maxlen);

    base = (unsigned char*)dst;
    p = base;
    cur = (unsigned char*)temp_str;

    // Skip leading whitespace
    while (__ismbcspace(*cur & 0xFF))
        cur = __mbsinc(cur);

    // Copy non-space chars
    while (*cur) {
        __mbsncpy(p, cur, 1);
        p = __mbsinc(p);
        cur = __mbsinc(cur);
    }

    // Trim trailing whitespace
    while (1) {
        *p = 0;
        if (p == base) break;
        p = __mbsdec(base, p);
        if (__ismbcspace(*p))
            continue;
        break;
    }

    return dst;
}
