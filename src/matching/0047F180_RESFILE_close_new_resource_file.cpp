// VA: 0047F180 RESFILE_close_new_resource_file (170B)
// Res_file.cpp lines 240-286
// Walks linked list, finds matching name, closes resource file node

#include <stdlib.h>
#include <string.h>

#ifndef RESFILE_MODULE_RESFILE_HDR_DEFINED
#define RESFILE_MODULE_RESFILE_HDR_DEFINED
struct resfile_header;
struct ResFileHdr {
    unsigned char* mapped_file;
    int handle;
    resfile_header* header;
    ResFileHdr* next;
    char res_name[260];
};
#endif

extern ResFileHdr* g_resFileList;
extern "C" int __cdecl close(int fd);
extern "C" __declspec(dllimport) int __stdcall UnmapViewOfFile(void* address);

void __cdecl RESFILE_close_new_resource_file(char* name) {
    ResFileHdr* cur = g_resFileList;
    ResFileHdr* prev = 0;
    
    while (cur) {
        if (strcmp(name, cur->res_name) == 0) {
            goto found;
        }
        prev = cur;
        cur = cur->next;
    }
    return;
    
found:
    if (cur->mapped_file == 0) {
        free(cur->header);
    }
    
    if (prev) {
        prev->next = cur->next;
    } else {
        g_resFileList = cur->next;
    }
    
    if (cur->handle != -1) {
        close(cur->handle);
    }
    
    if (cur->mapped_file != 0) {
        UnmapViewOfFile(cur->mapped_file);
    }
    
    free(cur);
}
