// VA: 0047F180 RESFILE_close_new_resource_file (170B)
// Res_file.cpp lines 240-286
// Walks linked list, finds matching name, closes resource file node

#include <stdlib.h>
#include <string.h>

extern void* g_resFileList;
extern int __cdecl close(int fd);
extern void* __cdecl UnmapViewOfFile(void* ptr);

void __cdecl RESFILE_close_new_resource_file(const char* name) {
    void** cur = *(void***)g_resFileList;
    void* prev = 0;
    
    while (cur) {
        const char* curName = (const char*)cur + 0x10;
        if (strcmp(name, curName) == 0) {
            break;
        }
        prev = cur;
        cur = (void**)cur[3];  // next pointer at +0x0C
    }
    
    if (!cur) return;
    
    if (*(int*)cur == 0) {
        // Not memory-mapped, free the raw data at +8
        free(cur[2]);
    }
    
    if (prev) {
        *(void**)((char*)prev + 0x0C) = cur[3];
    } else {
        *(void***)g_resFileList = (void**)cur[3];
    }
    
    if (*(int*)((char*)cur + 4) != -1) {
        close(*(int*)((char*)cur + 4));
    }
    
    if (*(int*)cur != 0) {
        UnmapViewOfFile(*(void**)cur);
    }
    
    free(cur);
}
