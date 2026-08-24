#ifndef RES_FILE_MODULE_CONTEXT_H
#define RES_FILE_MODULE_CONTEXT_H

#include <io.h>

#ifndef RESFILE_MODULE_RESFILE_HDR_DEFINED
#define RESFILE_MODULE_RESFILE_HDR_DEFINED
struct resfile_header;
struct ResFileHdr {
    unsigned char* mapped_file;
    int handle;
    resfile_header* header;
    ResFileHdr* next;
    char res_name[260];
};
#endif

#ifndef RESFILE_MODULE_RESFILE_HEADER_DEFINED
#define RESFILE_MODULE_RESFILE_HEADER_DEFINED
struct resfile_header {
    char banner_msg[40];
    char version[4];
    char password[12];
    int num_res_types;
    int directory_size;
};
#endif

#ifndef RESFILE_MODULE_RESFILE_TYPE_DIR_DEFINED
#define RESFILE_MODULE_RESFILE_TYPE_DIR_DEFINED
struct resfile_type_dir_node {
    unsigned long type;
    long dirOffset;
    long numID;
};
#endif

#ifndef RESFILE_MODULE_RESFILE_ID_DIR_DEFINED
#define RESFILE_MODULE_RESFILE_ID_DIR_DEFINED
struct resfile_id_dir_node {
    unsigned long id;
    long itemOffset;
    long itemSize;
};
#endif

#endif
