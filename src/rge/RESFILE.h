#pragma once
#include "../types.h"

#pragma pack(push, 1)

struct resfile_header {
    char banner_msg[40];
    char version[4];
    char password[12];
    int num_res_types;
    int directory_size;
};

struct ResFileHdr {
    uchar *mapped_file;
    int handle;
    struct resfile_header *header;
    struct ResFileHdr *next;
    char res_name[260];
};

#pragma pack(pop)

void RESFILE_build_res_file(const char* name, const char* dir, const char* ext);
void RESFILE_open_new_resource_file(const char* name, const char* dir, const char* ext, int flag);
uchar * RESFILE_load(ulong type, ulong id, int *size, int *out_flag);
int RESFILE_locate_resource(ulong type, ulong id, int *handle, int *offset, uchar **mapped_ptr, int *size);
void RESFILE_close_new_resource_file(const char *name);
