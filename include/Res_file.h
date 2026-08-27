#ifndef AOE1_RES_FILE_H
#define AOE1_RES_FILE_H

#include <stdio.h>

class ResFileHdr;
class resfile_header;

// PDB type: ResFileHdr. Size 0x114.
// Evidence: inventory/types/dumps/ResFileHdr.txt and Res_file.cpp assembly
// at 0047F076, 0047F180, and 0047F230.
class ResFileHdr {
public:
    unsigned char* mapped_file; // +0x00
    int handle;                  // +0x04
    resfile_header* header;      // +0x08
    ResFileHdr* next;            // +0x0C
    char res_name[260];          // +0x10
};

// PDB type: resfile_header. Size 0x40.
// Evidence: inventory/types/dumps/resfile_header.txt and the 0x40-byte
// header reads and writes in RESFILE_open_new_resource_file and
// RESFILE_build_res_file.
class resfile_header {
public:
    char banner_msg[40];         // +0x00
    char version[4];             // +0x28
    char password[12];           // +0x2C
    int num_res_types;           // +0x38
    int directory_size;          // +0x3C
};

// PDB type: resfile_type_dir_node. Size 0x0C.
// Evidence: inventory/types/dumps/resfile_type_dir_node.txt and the 0x0C
// directory stride at RESFILE_locate_resource 0047F285-0047F2BD.
class resfile_type_dir_node {
public:
    unsigned long type;          // +0x00
    long dirOffset;              // +0x04
    long numID;                  // +0x08
};

// PDB type: resfile_id_dir_node. Size 0x0C.
// Evidence: inventory/types/dumps/resfile_id_dir_node.txt and the 0x0C
// resource-record stride at RESFILE_locate_resource 0047F2A0-0047F2A6.
class resfile_id_dir_node {
public:
    unsigned long id;            // +0x00
    long itemOffset;             // +0x04
    long itemSize;               // +0x08
};

// PDB type: res_file_type_info. Size 0x08.
// Evidence: inventory/types/dumps/res_file_type_info.txt and
// BUILDRES_get_files_resource_type assembly at 0047FCD9-0047FD17.
class res_file_type_info {
public:
    char extension[4];            // +0x00
    unsigned long rType;          // +0x04
};

// PDB type: BuildRes_type_node. Size 0x14.
// Evidence: inventory/types/dumps/BuildRes_type_node.txt and the 0x14-byte
// allocation and linked-list accesses in RESFILE_build_res_file.
class BuildRes_type_node;
class BuildRes_id_node;

class BuildRes_type_node {
public:
    unsigned long type;           // +0x00
    int idOffset;                 // +0x04
    int nIds;                     // +0x08
    BuildRes_id_node* idList;     // +0x0C
    BuildRes_type_node* next;     // +0x10
};

// PDB type: BuildRes_id_node. Size 0x118.
// Evidence: inventory/types/dumps/BuildRes_id_node.txt and the 0x118-byte
// allocation and field accesses in RESFILE_build_res_file.
class BuildRes_id_node {
public:
    unsigned long id;             // +0x00
    int dataOffset;               // +0x04
    unsigned char* resData;       // +0x08
    int resSize;                  // +0x0C
    BuildRes_id_node* next;       // +0x10
    char fName[260];              // +0x14
};

// Resource-file global state. The image uses DAT_0086b254 at 0047F076,
// 0047F184, 0047F1F8, and 0047F240.
extern ResFileHdr* DAT_0086b254;

// Resource-missing diagnostic flag. The image uses DAT_0086b258 at 0047F36B
// and 0047F584.
extern int DAT_0086b258;

// The image table begins at 00585520. Its first entry's type word is the
// DAT_00585524 value 0x766F6320. The table is not redefined here.
extern res_file_type_info res_extension_table[];

class TDebuggingLog;
extern TDebuggingLog* L;

void __cdecl RESFILE_open_new_resource_file(
    char* name, char* cmpName, char* path, int isMapped);
void __cdecl RESFILE_close_new_resource_file(char* name);
int __cdecl RESFILE_locate_resource(
    unsigned long type_id,
    unsigned long res_id,
    int& out_fd,
    int& out_field1,
    unsigned char*& out_data,
    int& out_field2);
unsigned char* __cdecl RESFILE_load(
    unsigned long type,
    unsigned long id,
    int& load_type,
    int& data_size);
int __cdecl RESFILE_Extract_to_File(
    unsigned long type,
    unsigned long id,
    char* name,
    FILE*& file);
void __cdecl RESFILE_Set_Missing_Flag(int flag);
int __cdecl RESFILE_Decommit_Mapped_Memory(unsigned char* address, int size);
int __cdecl RESFILE_build_res_file(
    char* build_list_file, char* source_path, char* target_path);
unsigned long __cdecl BUILDRES_get_files_resource_type(char* name);

#endif
