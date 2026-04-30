// VA: 0047F230 RESFILE_locate_resource (232B)
// Res_file.cpp
// Walks the resource file linked list, finds a resource by type and ID,
// fills in output parameters.

#include <stdlib.h>

struct ResFileNode {
    int flags;        // +0x00: 0 = raw data, non-zero = memory-mapped pointer
    int fd;           // +0x04: file descriptor (-1 if none)
    void* data;       // +0x08: raw data pointer (header)
    ResFileNode* next; // +0x0C: linked list next
    char name[4];     // +0x10: name (variable length)
};

struct DirEntry {
    int type_id;
    int offset;
    int count;
};

extern ResFileNode* g_resFileList;

int __cdecl RESFILE_locate_resource(
    unsigned long type_id,
    unsigned long res_id,
    int* out_fd,
    int* out_field4,
    unsigned char** out_data,
    int* out_field8)
{
    ResFileNode* cur = g_resFileList;
    *out_fd = -1;
    *out_field4 = 0;
    *out_data = 0;
    *out_field8 = 0;
    
    if (!cur) return 0;
    
    do {
        unsigned char* hdr = (unsigned char*)cur->data;
        int numEntries = *(int*)(hdr + 0x38);
        int i = 0;
        
        if (numEntries > 0) {
            DirEntry* dirEntry = (DirEntry*)(hdr + 0x40);
            
            for (i = 0; i < numEntries; i++) {
                if (dirEntry->type_id == (int)type_id) {
                    int* subEntries = (int*)(dirEntry->offset + (int)hdr);
                    int subCount = dirEntry->count;
                    
                    if (subCount > 0) {
                        int j;
                        for (j = 0; j < subCount; j++) {
                            if (subEntries[0] == (int)res_id) {
                                *out_fd = cur->fd;
                                *out_field4 = subEntries[1];
                                *out_data = (unsigned char*)cur->flags;
                                *out_field8 = subEntries[2];
                                return 1;
                            }
                            subEntries += 3;
                        }
                    }
                }
                dirEntry++;
            }
        }
        
        cur = cur->next;
    } while (cur);
    
    return 0;
}
