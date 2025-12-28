#pragma once
#include "../types.h"

struct resfile_header {
    /* 0x00 */ char banner_msg[40];
    /* 0x28 */ char version[4];
    /* 0x2C */ char password[12];
    /* 0x38 */ int num_res_types;
    /* 0x3C */ int directory_size;
};

struct ResFileHdr {
    /* 0x00 */ uchar *mapped_file;
    /* 0x04 */ int handle;
    /* 0x08 */ struct resfile_header *header;
    /* 0x0C */ struct ResFileHdr *next;
    /* 0x10 */ char res_name[260];
};

// MANDATORY VERIFICATION
static_assert(sizeof(resfile_header) == 0x40, "resfile_header size mismatch");
static_assert(sizeof(ResFileHdr) == 276, "ResFileHdr size mismatch");
static_assert(offsetof(ResFileHdr, res_name) == 0x10, "res_name offset");

void RESFILE_build_res_file(const char* name, const char* dir, const char* ext);
void RESFILE_open_new_resource_file(const char* name, const char* dir, const char* ext, int flag);
uchar * RESFILE_load(ulong type, ulong id, int *size, int *out_flag);
int RESFILE_locate_resource(ulong type, ulong id, int *handle, int *offset, uchar **mapped_ptr, int *size);
void RESFILE_close_new_resource_file(const char *name);
