// VA: 0047EE90 RESFILE_open_new_resource_file (541B)
// Res_file.cpp

#include <stdlib.h>
#include <string.h>

extern void* g_resFileList;
extern int __cdecl open(const char* path, int flags);
extern void* __cdecl malloc(unsigned size);

void* __cdecl RESFILE_open_new_resource_file(const char* name, int fd, int size) {
    void** node = (void**)malloc(0x10 + strlen(name) + 1);
    if (!node) return 0;
    
    node[3] = *(void***)g_resFileList;  // next = head
    *(void***)g_resFileList = node;     // head = node
    
    *(int*)((char*)node + 4) = fd;     // file handle
    *(int*)node = 0;                    // not memory-mapped
    node[2] = 0;                        // data pointer
    
    strcpy((char*)node + 0x10, name);   // name string
    
    return node;
}
