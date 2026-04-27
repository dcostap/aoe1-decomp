// VA: 0047F230 RESFILE_locate_resource (232B)
// Res_file.cpp

#include <string.h>

extern void* g_resFileList;

void* __cdecl RESFILE_locate_resource(const char* name) {
    void** cur = *(void***)g_resFileList;
    
    while (cur) {
        const char* curName = (const char*)cur + 0x10;
        if (strcmp(name, curName) == 0) {
            return cur;
        }
        cur = (void**)cur[3];  // next at +0x0C
    }
    
    return 0;
}
