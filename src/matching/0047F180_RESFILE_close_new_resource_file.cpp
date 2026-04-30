// VA: 0047F180 RESFILE_close_new_resource_file (170B)
// Res_file.cpp lines 240-286
// Walks linked list, finds matching name, closes resource file node

#include <stdlib.h>
#include <string.h>

struct ResFileNode {
    int flags;        // +0x00: 0 = raw data, non-zero = memory-mapped pointer
    int fd;           // +0x04: file descriptor (-1 if none)
    void* data;       // +0x08: raw data pointer (if flags==0)
    ResFileNode* next; // +0x0C: linked list next
    char name[4];     // +0x10: name (variable length)
};

extern ResFileNode* g_resFileList;
extern int __cdecl close(int fd);
extern "C" __declspec(dllimport) int __stdcall UnmapViewOfFile(void* address);

void __cdecl RESFILE_close_new_resource_file(const char* name) {
    ResFileNode* cur = g_resFileList;
    ResFileNode* prev = 0;
    
    while (cur) {
        if (strcmp(name, cur->name) == 0) {
            goto found;
        }
        prev = cur;
        cur = cur->next;
    }
    return;
    
found:
    if (cur->flags == 0) {
        free(cur->data);
    }
    
    if (prev) {
        prev->next = cur->next;
    } else {
        g_resFileList = cur->next;
    }
    
    if (cur->fd != -1) {
        close(cur->fd);
    }
    
    if (cur->flags != 0) {
        UnmapViewOfFile((void*)cur->flags);
    }
    
    free(cur);
}
