// VA: 0047FC50 BUILDRES_get_files_resource_type (217B)
// Res_file.cpp lines 943-990
//
// Attempt log:
// - prologue matches (sub esp,8, extBuf[8]) for first 73 bytes
// - remaining divergence: extLen ends up in ebp instead of ecx/[esp+1Ch]
//   (original reuses param_1 stack slot for extLen)
// - extension copy loop: original keeps &name[dotPos+1] in ebp as pointer,
//   rebuilt uses stack temp + reload
// - table lookup loop: original uses one strncmp call site followed by
//   check[base+0xC]; base+=8; jne. A separate first-call plus while loop
//   creates a second call site and is structurally wrong.
// - table base (0x585520) needs to be kept in a register (esi) and advanced
//   via add+8, not constant-folded by compiler
// - baseline single while condition still let VC5 peel the first strncmp;
//   probing an explicit infinite loop with a saved sentinel value.
// - explicit for(;;) also peeled into two call sites; next probe uses source
//   labels so the call is physically one loop body with found/no-match tails.
// - labels normalized to the same two-call basin; probe a do/while body with
//   the sentinel loaded before the pointer increment, matching the original
//   mov/test-after-add loop tail.
// - the decompiler exposes a separate puVar1 top guard; model that sentinel
//   as the loop condition instead of an outer DAT guard or do/while tail.
// - exact: a local res_file_type_info array surface preserves the proven 4-byte
//   inline extension / dword type layout and the sentinel loop without raw
//   cursor arithmetic; default flags are sufficient.

#include <string.h>
#include <ctype.h>

struct res_file_type_info {
    char extension[4];
    unsigned int type;
};

extern res_file_type_info res_extension_table[];

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
        
        res_file_type_info* base = res_extension_table;
        unsigned int next = res_extension_table[0].type;
        while (next != 0) {
            if (strncmp(base->extension, extBuf, extLen + 1) == 0) {
                return (int)base->type;
            }
            next = (base + 1)->type;
            ++base;
        }
    }
    return 0x62696e61;
}
