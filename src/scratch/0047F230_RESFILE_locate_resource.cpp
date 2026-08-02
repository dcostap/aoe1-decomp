// VA: 0047F230 RESFILE_locate_resource (232B)
// Res_file.cpp lines 293-411
// Walks the resource file linked list; finds a resource by type and ID.
// Sets fd / itemOffset / mapped-data pointer / itemSize outputs.
//
// Attempt log:
// - baseline: typed structs (ResFileNode/resfile_header/type_dir/id_dir) but
//   pointer-walk (sub++/dir++) and explicit count guards. diff=176, size -20.
// - layout: natural for loops without explicit count guards, still sub++ walk.
//   diff=180, size -28 (worse).
// - control-flow: KEY - indexed access sub[j].id / sub[j].itemOffset etc. so the
//   found path re-derives base + j*12 from the preserved sub base (edx) and j
//   (eax), exactly as original; dir[i] indexed too. diff=71 (30.6%), size 232/232
//   exact, shape 91%, exact-block coverage 87.6%.
// - Remaining gap (localized tail layout): node-loop bottom. Original emits
//   `jne back` with a separate loop-exit return-0 epilogue (xor eax,eax FIRST,
//   at 0047F2D0) placed before the found path, and a second byte-different
//   guard-exit return-0 (xor AFTER pop ebp, at 0047F310). Rebuilt merges both
//   return-0 epilogues into one shared block at the end and emits
//   `je shared_exit; jmp loop_top` at the bottom (6 bytes of trailing nops
//   pad to size). All loops and found path are byte-identical to original.
//   Next leads: force the loop-exit epilogue to stay a separate fall-through
//   block (e.g., while(cur) rotation, goto found, or differing epilogue forms
//   so VC5 cannot merge the two return-0 blocks).

#include <stdlib.h>

struct ResFileNode {
    int flags;        // +0x00: 0 = raw data, non-zero = memory-mapped pointer
    int fd;           // +0x04: file descriptor (-1 if none)
    void* data;       // +0x08: raw data pointer (header)
    ResFileNode* next; // +0x0C: linked list next
    char name[4];     // +0x10: name (variable length)
};

struct resfile_header {   // 0x40
    char banner_msg[40];  // +0x00
    char version[4];      // +0x28
    char password[12];    // +0x2C
    int num_res_types;    // +0x38
    int directory_size;   // +0x3C
};

struct resfile_type_dir_node {  // 0xC
    unsigned long type;         // +0x00
    long dirOffset;             // +0x04
    long numID;                 // +0x08
};

struct resfile_id_dir_node {    // 0xC
    unsigned long id;           // +0x00
    long itemOffset;            // +0x04
    long itemSize;              // +0x08
};

extern ResFileNode* g_resFileList;

int __cdecl RESFILE_locate_resource(
    unsigned long type_id,
    unsigned long res_id,
    int& out_fd,
    int& out_field1,
    unsigned char*& out_data,
    int& out_field2)
{
    ResFileNode* cur = g_resFileList;
    out_fd = -1;
    out_field1 = 0;
    out_data = 0;
    out_field2 = 0;

    if (!cur) return 0;

    do {
        resfile_header* hdr = (resfile_header*)cur->data;
        resfile_type_dir_node* dir = (resfile_type_dir_node*)((char*)hdr + 0x40);

        for (int i = 0; i < hdr->num_res_types; i++) {
            if (dir[i].type == type_id) {
                resfile_id_dir_node* sub = (resfile_id_dir_node*)((char*)hdr + dir[i].dirOffset);

                for (int j = 0; j < dir[i].numID; j++) {
                    if (sub[j].id == res_id) {
                        out_fd = cur->fd;
                        out_field1 = sub[j].itemOffset;
                        out_data = (unsigned char*)cur->flags;
                        out_field2 = sub[j].itemSize;
                        return 1;
                    }
                }
            }
        }

        cur = cur->next;
    } while (cur);

    return 0;
}
