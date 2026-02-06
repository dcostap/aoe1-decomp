#pragma once
#include <windows.h>
#include <stdio.h>

#pragma pack(push, 1)

struct ResFile;

struct ResFile {
    unsigned char* mapped_data; // 0x00
    int file_handle;           // 0x04
    void* base_pointer;        // 0x08 (mapped_data or malloc'd buffer)
    ResFile* next;             // 0x0C
    char filename[260];        // 0x10
};

struct ResFileHeader {
    char version[4];           // "1.00"
    int num_resources;
    // ... more fields if needed based on locate_resource analysis
};

#pragma pack(pop)

void RESFILE_open_new_resource_file(char* path, char* file, char* tag, int use_mapping);
void RESFILE_close_new_resource_file(char* file);
void RESFILE_build_res_file(char* path, char* file, char* tag);
unsigned char* RESFILE_load(unsigned long type, unsigned long id, int* size, int* out_type);
int RESFILE_locate_resource(unsigned long type, unsigned long id, int* handle, int* offset, unsigned char** data, int* size);
int RESFILE_Extract_to_File(unsigned long type, unsigned long id, char* path, FILE** file);
int RESFILE_Decommit_Mapped_Memory(unsigned char* param_1, int param_2);
