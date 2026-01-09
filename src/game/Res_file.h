#pragma once

#include <cstdint>

// DRS file format structures
// Based on analysis of registry.cpp.asm (0047ee90+)

#pragma pack(push, 1)

// DRS file header (64 bytes)
struct DRS_Header {
    char copyright[40];      // Copyright string
    char version[4];         // Version string (e.g., "1.00")
    char file_type[12];      // File type identifier
    uint32_t num_table_types; // Number of table types
    uint32_t offset_first_file; // Offset to first file
};

// DRS table type entry (12 bytes each)
struct DRS_Table_Info {
    uint32_t file_extension;  // File type extension ('plp\0', 'nib\0', 'wav\0', etc.)
    uint32_t file_offset;     // Offset to file table
    uint32_t num_files;       // Number of files in this table
};

// DRS file entry (12 bytes each)
struct DRS_File_Entry {
    uint32_t file_id;         // File ID number
    uint32_t file_offset;     // Offset to file data
    uint32_t file_size;       // Size of file data
};

#pragma pack(pop)

// Resource file node structure (0x114 bytes from analysis)
struct ResourceFileNode {
    void* mapped_data;        // +0x00: Pointer to mapped file data (or nullptr for file handle mode)
    int file_handle;          // +0x04: File handle (-1 for mapped mode)
    void* directory_data;     // +0x08: Pointer to directory data
    ResourceFileNode* next;   // +0x0C: Next resource file in linked list
    char filename[256];       // +0x10: Resource filename
    // Rest of structure at +0x110+
};

// External functions
extern "C" {
    void RESFILE_open_new_resource_file(const char* filename, const char* tag, const char* directory, int mode);
    void RESFILE_close_new_resource_file(const char* filename);
}
