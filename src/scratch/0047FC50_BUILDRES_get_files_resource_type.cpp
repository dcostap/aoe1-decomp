// VA: 0047FC50 BUILDRES_get_files_resource_type (217B)
// Res_file.cpp lines 943-990
//
// Attempt log:
// - prologue matches (sub esp,8, extBuf[8]) for first 73 bytes
// - remaining divergence: extLen ends up in ebp instead of ecx/[esp+1Ch]
//   (original reuses param_1 stack slot for extLen)
// - extension copy loop: original keeps &name[dotPos+1] in ebp as pointer,
//   rebuilt uses stack temp + reload
// - table lookup loop: original uses {strncmp; check[base+0xC]; base+=8; jne}
//   pattern. Need jne at bottom, not check-at-top pattern.
// - table base (0x585520) needs to be kept in a register (esi) and advanced
//   via add+8, not constant-folded by compiler

#include <string.h>
#include <ctype.h>

extern unsigned int DAT_00585524;

int __cdecl BUILDRES_get_files_resource_type(const char* name) {
    int len = strlen(name);
    int dotPos;
    char extBuf[8];
    
    if (len < 5 || len >= 0x104) {
        return 0;
    }
    
    for (dotPos = len - 1; dotPos > 0; dotPos--) {
        if (name[dotPos] == '.') break;
    }
    
    if (dotPos == 0) return 0;
    
    if (len - dotPos - 1 > 3) return 0;
    
    {
        int i;
        int extLen = len - dotPos - 1;
        for (i = 0; i <= extLen; i++) {
            char c = name[dotPos + 1 + i];
            if (isupper(c)) {
                c = tolower(c);
            }
            extBuf[i] = c;
        }
        
        if (DAT_00585524 != 0) {
            unsigned int base = 0x585520;
            if (strncmp((const char*)base, extBuf, extLen + 1) == 0) {
                return *(int*)(base + 4);
            }
            while (*(int*)(base + 0xC) != 0) {
                base += 8;
                if (strncmp((const char*)base, extBuf, extLen + 1) == 0) {
                    return *(int*)(base + 4);
                }
            }
        }
    }
    return 0x62696e61;
}
