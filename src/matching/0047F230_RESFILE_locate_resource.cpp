// VA: 0047F230 RESFILE_locate_resource (232B)
// Res_file.cpp lines 293-411
// Walks the resource file linked list; finds a resource by type and ID.
// Sets fd / itemOffset / mapped-data pointer / itemSize outputs.
//
// Attempt log:
// - baseline: typed directory records with pointer-walk loops and explicit
//   count guards; diff=176, size -20.
// - layout: natural count-controlled loops with pointer-walk records; diff=180,
//   size -28 (worse).
// - control-flow: indexed dir[i]/sub[j] access preserved the sub base and index
//   for the found path; diff=71, size 232/232, shape 91%.
// - probe 005: changed the outer node traversal from do/while to while after
//   the explicit initial null guard. This reproduced the original separate
//   fall-through loop-exit epilogue and matched all 232 bytes.
// - probe 006: replaced the decompiler-shaped node stub with the binary-supported
//   ResFileHdr layout (mapped_file/handle/header/next); emitted bytes unchanged.

#include <stdlib.h>

struct resfile_header;

struct ResFileHdr {
    unsigned char* mapped_file; // +0x00: mapped data pointer
    int handle;                 // +0x04: file descriptor (-1 if none)
    resfile_header* header;     // +0x08: resource-file header
    ResFileHdr* next;           // +0x0C: linked list next
    char res_name[260];         // +0x10: name
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

extern ResFileHdr* g_resFileList;

int __cdecl RESFILE_locate_resource(
    unsigned long type_id,
    unsigned long res_id,
    int& out_fd,
    int& out_field1,
    unsigned char*& out_data,
    int& out_field2)
{
    ResFileHdr* cur = g_resFileList;
    out_fd = -1;
    out_field1 = 0;
    out_data = 0;
    out_field2 = 0;

    if (!cur) return 0;

    while (cur) {
        resfile_header* hdr = cur->header;
        resfile_type_dir_node* dir = (resfile_type_dir_node*)((char*)hdr + 0x40);

        for (int i = 0; i < hdr->num_res_types; i++) {
            if (dir[i].type == type_id) {
                resfile_id_dir_node* sub = (resfile_id_dir_node*)((char*)hdr + dir[i].dirOffset);

                for (int j = 0; j < dir[i].numID; j++) {
                    if (sub[j].id == res_id) {
                        out_fd = cur->handle;
                        out_field1 = sub[j].itemOffset;
                        out_data = cur->mapped_file;
                        out_field2 = sub[j].itemSize;
                        return 1;
                    }
                }
            }
        }

        cur = cur->next;
    }

    return 0;
}
