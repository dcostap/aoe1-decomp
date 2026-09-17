#ifndef AOE1_RES_FILE_H
#define AOE1_RES_FILE_H

#include <stdio.h>

class ResFileHdr;
class resfile_header;

class ResFileHdr {
public:
    unsigned char* mapped_file;  // +0x00
    int handle;                  // +0x04
    resfile_header* header;      // +0x08
    ResFileHdr* next;            // +0x0C
    char res_name[260];          // +0x10
};

class resfile_header {
public:
    char banner_msg[40];         // +0x00
    char version[4];             // +0x28
    char password[12];           // +0x2C
    int num_res_types;           // +0x38
    int directory_size;          // +0x3C
};

class resfile_type_dir_node {
public:
    unsigned long type;          // +0x00
    long dirOffset;              // +0x04
    long numID;                  // +0x08
};

class resfile_id_dir_node {
public:
    unsigned long id;            // +0x00
    long itemOffset;             // +0x04
    long itemSize;               // +0x08
};

class res_file_type_info {
public:
    char extension[4];            // +0x00
    unsigned long rType;          // +0x04
};

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

class BuildRes_id_node {
public:
    unsigned long id;             // +0x00
    int dataOffset;               // +0x04
    unsigned char* resData;       // +0x08
    int resSize;                  // +0x0C
    BuildRes_id_node* next;       // +0x10
    char fName[260];              // +0x14
};

#define RES_TYPE_BINARY 0x62696E61
#define RES_TYPE_WAVE   0x77617620
#define RES_TYPE_SHAPE  0x73687020
#define RES_TYPE_SLP    0x736C7020

// The image table begins at 00585520. game_globals.cpp owns the shipped data.
extern res_file_type_info res_extension_table[];

void __cdecl RESFILE_open_new_resource_file(char* resFileName, char* password, char* path, int open_mode);
void __cdecl RESFILE_close_new_resource_file(char* res_file);
int __cdecl RESFILE_locate_resource(unsigned long rType, unsigned long rId, int& file, int& offset, unsigned char*& mapped_file, int& size);
unsigned char* __cdecl RESFILE_load(unsigned long rType, unsigned long rId, int& rLoadType, int& rDataSize);
int __cdecl RESFILE_Extract_to_File(unsigned long rType, unsigned long rId, char* file_name, FILE*& file);
void __cdecl RESFILE_Set_Missing_Flag(int FlagVal);
int __cdecl RESFILE_Decommit_Mapped_Memory(unsigned char* ResData, int resSize);
int __cdecl RESFILE_build_res_file(char* build_list_file, char* source_path, char* target_path);
unsigned long __cdecl BUILDRES_get_files_resource_type(char* filename);

#endif
