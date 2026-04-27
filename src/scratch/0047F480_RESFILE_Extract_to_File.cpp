// VA: 0047F480 RESFILE_Extract_to_File (247B)
// Res_file.cpp

#include <string.h>

extern void* g_resFileList;

int __cdecl RESFILE_Extract_to_File(const char* name, const char* outFile) {
    void** cur = *(void***)g_resFileList;
    
    while (cur) {
        const char* curName = (const char*)cur + 0x10;
        if (strcmp(name, curName) == 0) {
            return 0;
        }
        cur = (void**)cur[3];
    }
    
    return -1;
}
