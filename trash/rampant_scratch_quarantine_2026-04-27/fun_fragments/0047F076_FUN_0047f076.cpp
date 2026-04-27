// VA: 0047F076 FUN_0047f076 (172B)
// Res_file.cpp
// Adds a resource node to the end of the linked list

#include <stdlib.h>
#include <string.h>

extern void* g_resFileList;

void __cdecl FUN_0047f076(void* newNode) {
    void** head = *(void***)g_resFileList;
    
    if (!head) {
        *(void***)g_resFileList = (void**)newNode;
        return;
    }
    
    void** cur = head;
    while (cur[3]) {
        cur = (void**)cur[3];
    }
    cur[3] = newNode;
}
