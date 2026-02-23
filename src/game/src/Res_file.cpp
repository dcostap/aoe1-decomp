#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <io.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "../include/Res_file.h"
#include "../include/custom_debug.h"  // Must be after windows.h for MessageBox suppression

#include <direct.h>

static ResFile* resFileHead = nullptr;

void RESFILE_open_new_resource_file(char* path, char* filename, char* tag, int use_mapping) {
    char fullPath[260];
    sprintf(fullPath, "%s%s", path, filename);

    unsigned char* mappedData = nullptr;
    int fHandle = -1;

    if (use_mapping == 0) {
        HANDLE hFile = CreateFileA(fullPath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
        if (hFile == INVALID_HANDLE_VALUE) {
            char errorMsg[512];
            char cwd[260];
            _getcwd(cwd, sizeof(cwd));
            sprintf(errorMsg, "Error: Open_new_ResFile, file not found: [%s]\nPath arg: [%s]\nFilename arg: [%s]\nCWD: [%s]\nGLE: %lu", 
                    fullPath, path, filename, cwd, GetLastError());
            MessageBoxA(NULL, errorMsg, "RESOURCE ERROR", MB_OK | MB_ICONERROR);
            return;
        }

        HANDLE hMapping = CreateFileMappingA(hFile, NULL, PAGE_READONLY, 0, 0, NULL);
        CloseHandle(hFile);

        if (hMapping == NULL) {
            MessageBoxA(NULL, "Error: Open_Mapped_ResFile, Could not map file.", "RESOURCE ERROR", MB_OK | MB_ICONERROR);
            return;
        }

        mappedData = (unsigned char*)MapViewOfFile(hMapping, FILE_MAP_READ, 0, 0, 0);
        if (mappedData == NULL) {
            CloseHandle(hMapping);
            MessageBoxA(NULL, "Error: Open_Mapped_ResFile, Could not map file.", "RESOURCE ERROR", MB_OK | MB_ICONERROR);
            return;
        }
        CloseHandle(hMapping);
    }

    ResFile* newRes = (ResFile*)malloc(sizeof(ResFile));
    if (!newRes) {
        MessageBoxA(NULL, "Error: Out of memory in Open_resfile.", "RESOURCE ERROR", MB_OK | MB_ICONERROR);
        return;
    }

    strcpy(newRes->filename, filename);
    if (use_mapping != 0) {
        // Non-mapped mode: open and read via file handle
        newRes->file_handle = _open(fullPath, _O_BINARY | _O_RDONLY);
        newRes->mapped_data = nullptr;
        newRes->base_pointer = nullptr;
        
        // For file-based access, we read header and validate
        if (newRes->file_handle != -1) {
            // Read header (0x40 bytes per ASM at 0047effa-0047f006)
            char header[0x40];
            _lseek(newRes->file_handle, 0, SEEK_SET);
            int bytesRead = _read(newRes->file_handle, header, 0x40);
            if (bytesRead == 0x40) {
                // ASM compares tag at header+0x2c with param_3 (the tag)
                if (strcmp(header + 0x2c, tag) != 0) {
                    MessageBoxA(NULL, "Error: Open_ResFile, Corruption detected in resfile.", "RESOURCE ERROR", MB_OK | MB_ICONERROR);
                }
                // ASM compares version at header+0x28 with "1.00"
                else if (strncmp(header + 0x28, "1.00", 4) != 0) {
                    MessageBoxA(NULL, "Error: Open_ResFile, Resfile not correct.", "RESOURCE ERROR", MB_OK | MB_ICONERROR);
                }
            }
        }
    } else {
        // Mapped mode: use memory-mapped file
        newRes->file_handle = -1;
        newRes->mapped_data = mappedData;
        newRes->base_pointer = mappedData;
    }
    newRes->next = nullptr;

    // Append to list (ASM at FUN_0047f076)
    if (!resFileHead) {
        resFileHead = newRes;
    } else {
        ResFile* curr = resFileHead;
        while (curr->next) curr = curr->next;
        curr->next = newRes;
    }

    // Validation for mapped files (ASM at 0047f09b-0047f121)
    if (newRes->base_pointer) {
        unsigned char* base = (unsigned char*)newRes->base_pointer;
        // ASM compares string at base+0x2c with the tag
        if (strcmp((char*)(base + 0x2c), tag) != 0) {
            MessageBoxA(NULL, "Error: Open_ResFile, Corruption detected in resfile.", "RESOURCE ERROR", MB_OK | MB_ICONERROR);
        }
        // ASM compares string at base+0x28 with "1.00"
        else if (strncmp((char*)(base + 0x28), "1.00", 4) != 0) {
            MessageBoxA(NULL, "Error: Open_ResFile, Resfile not correct.", "RESOURCE ERROR", MB_OK | MB_ICONERROR);
        }
    }
}

void RESFILE_close_new_resource_file(char* filename) {
    ResFile* curr = resFileHead;
    ResFile* prev = nullptr;

    while (curr) {
        if (_stricmp(curr->filename, filename) == 0) {
            if (prev) {
                prev->next = curr->next;
            } else {
                resFileHead = curr->next;
            }

            if (curr->file_handle != -1) {
                _close(curr->file_handle);
            }
            if (curr->mapped_data) {
                UnmapViewOfFile(curr->mapped_data);
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

int RESFILE_locate_resource(unsigned long type, unsigned long id, int* handle, int* offset, unsigned char** data, int* size) {
    *handle = -1;
    *offset = 0;
    *data = nullptr;
    *size = 0;

    ResFile* curr = resFileHead;
    while (curr) {
        unsigned char* base = (unsigned char*)curr->base_pointer;
        if (base) {
            int num_sections = *(int*)(base + 0x38);
            unsigned char* section_ptr = base + 0x48;

            for (int i = 0; i < num_sections; ++i) {
                unsigned long section_type = *(unsigned long*)(section_ptr - 8);
                if (section_type == type) {
                    int section_offset = *(int*)(section_ptr - 4);
                    int section_count = *(int*)(section_ptr);
                    
                    unsigned char* resource_ptr = base + section_offset;
                    for (int j = 0; j < section_count; ++j) {
                        unsigned long res_id = *(unsigned long*)(resource_ptr);
                        if (res_id == id) {
                            *handle = curr->file_handle;
                            *offset = *(int*)(resource_ptr + 4);
                            *size = *(int*)(resource_ptr + 8);
                            *data = curr->mapped_data;
                            char type_str[5] = {0};
                            memcpy(type_str, &type, 4);
                            CUSTOM_DEBUG_LOG_FMT("RESFILE_locate_resource: found %s id %d in %s", type_str, (int)id, curr->filename);
                            return 1;
                        }
                        resource_ptr += 12;
                    }
                }
                section_ptr += 12;
            }
        } else if (curr->file_handle != -1) {
            _lseek(curr->file_handle, 0x38, SEEK_SET);
            int num_sections;
            _read(curr->file_handle, &num_sections, 4);
            
            for (int i = 0; i < num_sections; ++i) {
                _lseek(curr->file_handle, 0x48 + i * 12 - 8, SEEK_SET);
                unsigned long section_type;
                int section_offset, section_count;
                _read(curr->file_handle, &section_type, 4);
                _read(curr->file_handle, &section_offset, 4);
                _read(curr->file_handle, &section_count, 4);
                
                if (section_type == type) {
                    _lseek(curr->file_handle, section_offset, SEEK_SET);
                    for (int j = 0; j < section_count; ++j) {
                        unsigned long res_id;
                        int res_offset, res_size;
                        _read(curr->file_handle, &res_id, 4);
                        _read(curr->file_handle, &res_offset, 4);
                        _read(curr->file_handle, &res_size, 4);
                        
                        if (res_id == id) {
                            *handle = curr->file_handle;
                            *offset = res_offset;
                            *size = res_size;
                            *data = nullptr;
                            char type_str[5] = {0};
                            memcpy(type_str, &type, 4);
                            CUSTOM_DEBUG_LOG_FMT("RESFILE_locate_resource: found %s id %d in %s (file mode)", type_str, (int)id, curr->filename);
                            return 1;
                        }
                    }
                }
            }
        }
        curr = curr->next;
    }
    return 0;
}

unsigned char* RESFILE_load(unsigned long type, unsigned long id, int* size, int* out_type) {
    int handle, offset, resSize;
    unsigned char* mappedData;

    if (RESFILE_locate_resource(type, id, &handle, &offset, &mappedData, &resSize)) {
        *size = resSize;
        if (mappedData) {
            *out_type = 0;
            return mappedData + offset;
        } else if (handle != -1) {
            *out_type = 1;
            unsigned char* buffer = (unsigned char*)malloc(resSize);
            _lseek(handle, offset, SEEK_SET);
            _read(handle, buffer, resSize);
            return buffer;
        }
    }
    return nullptr;
}

int RESFILE_Extract_to_File(unsigned long type, unsigned long id, char* path, FILE** file) {
    int size, out_type;
    unsigned char* data = RESFILE_load(type, id, &size, &out_type);
    if (data) {
        *file = fopen(path, "wb");
        if (*file) {
            fwrite(data, 1, size, *file);
            fclose(*file);
            if (out_type == 1) free(data);
            return 1;
        }
        if (out_type == 1) free(data);
    }
    return 0;
}

int RESFILE_Decommit_Mapped_Memory(unsigned char* param_1, int param_2) {
    // Source-of-truth note:
    // The original engine can decommit mapped resource memory. In this reimplementation,
    // mapped resource views are owned by `ResFile` and released on file close, so this is a no-op.
    // TODO(decomp): revisit if per-resource mapping ownership is reintroduced.
    (void)param_1;
    (void)param_2;
    return 1;
}

namespace {
#pragma pack(push, 1)
struct ResfileHeader {
    char banner_msg[0x28]; // 0x00
    char version[4];       // 0x28 ("1.00")
    char file_type[0x0c];  // 0x2C ("tribe" / etc)
    int num_types;         // 0x38
    int data_offset;       // 0x3C (start of resource data)
};
static_assert(sizeof(ResfileHeader) == 0x40, "ResfileHeader size mismatch");

struct ResfileTypeDirNode {
    unsigned long type;
    int id_dir_offset;
    int num_ids;
};
static_assert(sizeof(ResfileTypeDirNode) == 0x0c, "ResfileTypeDirNode size mismatch");

struct ResfileIdDirNode {
    unsigned long id;
    int data_offset;
    int data_size;
};
static_assert(sizeof(ResfileIdDirNode) == 0x0c, "ResfileIdDirNode size mismatch");
#pragma pack(pop)

struct BuildResIdNode {
    unsigned long id;       // +0x00
    int data_offset;        // +0x04
    unsigned char* resData; // +0x08
    int resSize;            // +0x0C
    BuildResIdNode* next;   // +0x10
    char filename[260];     // +0x14
};
static_assert(sizeof(BuildResIdNode) == 0x118, "BuildResIdNode size mismatch");

struct BuildResTypeNode {
    unsigned long type;   // +0x00
    int dir_offset;       // +0x04
    int num_ids;          // +0x08
    BuildResIdNode* ids;  // +0x0C
    BuildResTypeNode* next; // +0x10
};
static_assert(sizeof(BuildResTypeNode) == 0x14, "BuildResTypeNode size mismatch");

static const char header_message[] = "Copyright (c) 1997 Ensemble Studios.";

static void BUILDRES_free_lists(BuildResTypeNode* head) {
    while (head != nullptr) {
        BuildResIdNode* id = head->ids;
        while (id != nullptr) {
            if (id->resData != nullptr) {
                free(id->resData);
            }
            BuildResIdNode* nextId = id->next;
            free(id);
            id = nextId;
        }
        BuildResTypeNode* nextType = head->next;
        free(head);
        head = nextType;
    }
}

static unsigned long BUILDRES_get_files_resource_type(const char* filename) {
    // Transliteration of res_file.cpp.decomp BUILDRES_get_files_resource_type @ 0x0047FC50.
    size_t len = strlen(filename);
    if (len <= 4 || len >= 0x104) {
        return 0;
    }

    // Find '.' in the filename (from end).
    int dot = (int)len - 2;
    while (dot > 0 && filename[dot] != '.') {
        --dot;
    }
    if (dot == 0) {
        return 0;
    }

    int ext_len = ((int)len - dot) - 1;
    if (ext_len > 3) {
        return 0;
    }

    char extension[4] = {0, 0, 0, 0};
    for (int i = 0; i <= ext_len; ++i) {
        char c = filename[dot + 1 + i];
        if (isupper((unsigned char)c)) {
            c = (char)tolower((unsigned char)c);
        }
        extension[i] = c;
    }

    struct ExtEntry {
        const char ext[4];
        unsigned long type;
    };

    // NOTE: The full original table lives in the binary's .data; we implement the known types used by the codebase.
    static const ExtEntry res_extension_table[] = {
        { "voc", 0x766f6320 }, // 'voc '
        { "wav", 0x77617620 }, // 'wav '
        { "xmi", 0x786d6920 }, // 'xmi '
        { "slp", 0x736c7020 }, // 'slp '
        { "shp", 0x73687020 }, // 'shp '
        { "pal", 0x70616c20 }, // 'pal '
        { {0, 0, 0, 0}, 0 }
    };

    for (int i = 0; res_extension_table[i].type != 0; ++i) {
        if (strncmp(res_extension_table[i].ext, extension, ext_len + 1) == 0) {
            return res_extension_table[i].type;
        }
    }

    return 0x62696e61; // 'bina'
}
} // namespace

int RESFILE_build_res_file(char* path, char* resource_dir, char* tag) {
    // Fully verified. Source of truth: res_file.cpp.decomp @ 0x0047F5C0
    BuildResTypeNode* iq = nullptr;
    int numResTypes = 0;
    int outFd = -1;
    int ret = 0;

    char data_filename[260];
    char temp_filename[260];
    char resource_filename[260];
    char build_filename[260];
    char rPassword[40];

    sprintf(build_filename, "%s%s", resource_dir, tag);
    FILE* buildFile = fopen(build_filename, "r");
    if (buildFile == nullptr) {
        CUSTOM_DEBUG_LOG_FMT("Error: could not find resource build file: %s", tag);
        goto cleanup;
    }

    if (fscanf(buildFile, "%259s %39s", temp_filename, rPassword) != 2) {
        CUSTOM_DEBUG_LOG_FMT("Error: could not parse resource build file header: %s", build_filename);
        goto cleanup;
    }
    sprintf(resource_filename, "%s%s", path, temp_filename);

    int file_id;
    while (fscanf(buildFile, "%259s", temp_filename) == 1 &&
           fscanf(buildFile, "%d", &file_id) == 1) {
        unsigned long rId = (unsigned long)file_id; // build file provides numeric resource id

        sprintf(data_filename, "%s%s", resource_dir, temp_filename);
        unsigned long rType = BUILDRES_get_files_resource_type(temp_filename);
        if (rType == 0) {
            CUSTOM_DEBUG_LOG_FMT("Error: could not determine file type of: %s", temp_filename);
            goto cleanup;
        }

        BuildResTypeNode* prevType = nullptr;
        BuildResTypeNode* typeNode = nullptr;
        for (BuildResTypeNode* cur = iq; cur != nullptr; cur = cur->next) {
            if (cur->type == rType) {
                typeNode = cur;
                break;
            }
            if (cur->type < rType) {
                prevType = cur;
            }
        }

        if (typeNode == nullptr) {
            typeNode = (BuildResTypeNode*)malloc(sizeof(BuildResTypeNode));
            if (typeNode == nullptr) {
                CUSTOM_DEBUG_LOG("Error: out of memory #1");
                goto cleanup;
            }
            typeNode->type = rType;
            typeNode->dir_offset = 0;
            typeNode->num_ids = 0;
            typeNode->ids = nullptr;
            typeNode->next = nullptr;

            if (prevType == nullptr) {
                typeNode->next = iq;
                iq = typeNode;
            } else {
                typeNode->next = prevType->next;
                prevType->next = typeNode;
            }
            numResTypes += 1;
        }

        BuildResIdNode* prevId = nullptr;
        for (BuildResIdNode* cur = typeNode->ids; cur != nullptr; cur = cur->next) {
            if (cur->id == rId) {
                CUSTOM_DEBUG_LOG_FMT("Error: duplicate resources: %s & %s", cur->filename, data_filename);
                goto cleanup;
            }
            if (cur->id < rId) {
                prevId = cur;
            }
        }

        BuildResIdNode* idNode = (BuildResIdNode*)malloc(sizeof(BuildResIdNode));
        if (idNode == nullptr) {
            CUSTOM_DEBUG_LOG("Error: out of memory #2");
            goto cleanup;
        }
        memset(idNode, 0, sizeof(BuildResIdNode));
        idNode->id = rId;
        strcpy(idNode->filename, data_filename);

        int fd = _open(data_filename, _O_BINARY | _O_RDONLY);
        if (fd == -1) {
            CUSTOM_DEBUG_LOG_FMT("Error: unable to open file: %s", data_filename);
            free(idNode);
            continue;
        }

        // Insert into the per-type ID list (sorted).
        if (prevId == nullptr) {
            idNode->next = typeNode->ids;
            typeNode->ids = idNode;
        } else {
            idNode->next = prevId->next;
            prevId->next = idNode;
        }
        typeNode->num_ids += 1;

        long fileSize = _lseek(fd, 0, SEEK_END);
        _lseek(fd, 0, SEEK_SET);
        if (fileSize < 1) {
            CUSTOM_DEBUG_LOG_FMT("Error: file is empty/NULL: %s", data_filename);
            _close(fd);
            goto cleanup;
        }

        idNode->resData = (unsigned char*)malloc(fileSize);
        if (idNode->resData == nullptr) {
            CUSTOM_DEBUG_LOG("Error: out of memory #3");
            _close(fd);
            goto cleanup;
        }

        idNode->resSize = (int)fileSize;
        int bytesRead = _read(fd, idNode->resData, (unsigned int)fileSize);
        if (bytesRead != fileSize) {
            CUSTOM_DEBUG_LOG_FMT("Error: error reading file: %s", data_filename);
            _close(fd);
            goto cleanup;
        }
        _close(fd);
    }

    fclose(buildFile);
    buildFile = nullptr;

    outFd = _open(resource_filename, _O_BINARY | _O_CREAT | _O_TRUNC | _O_WRONLY, _S_IREAD | _S_IWRITE);
    if (outFd == -1) {
        CUSTOM_DEBUG_LOG_FMT("Error: unable to create resource file file: %s", resource_filename);
        goto cleanup;
    }

    int dataOffset = 0x40 + numResTypes * 0x0c;
    for (BuildResTypeNode* t = iq; t != nullptr; t = t->next) {
        t->dir_offset = dataOffset;
        dataOffset += t->num_ids * 0x0c;
    }

    int curDataPos = dataOffset;
    for (BuildResTypeNode* t = iq; t != nullptr; t = t->next) {
        for (BuildResIdNode* n = t->ids; n != nullptr; n = n->next) {
            n->data_offset = curDataPos;
            curDataPos += n->resSize;
        }
    }

    ResfileHeader theHeader;
    memset(&theHeader, 0, sizeof(theHeader));
    strncpy(theHeader.banner_msg, header_message, sizeof(theHeader.banner_msg));
    memcpy(theHeader.version, "1.00", 4);
    strcpy(theHeader.file_type, rPassword);
    theHeader.num_types = numResTypes;
    theHeader.data_offset = dataOffset;

    int pos = 0;
    pos = _write(outFd, &theHeader, 0x40);
    if (pos != 0x40) {
        CUSTOM_DEBUG_LOG("Error writing resource file header");
        goto cleanup;
    }

    pos = 0x40;
    for (BuildResTypeNode* t = iq; t != nullptr; t = t->next) {
        ResfileTypeDirNode typeDirNode;
        typeDirNode.type = t->type;
        typeDirNode.id_dir_offset = t->dir_offset;
        typeDirNode.num_ids = t->num_ids;
        int wrote = _write(outFd, &typeDirNode, sizeof(typeDirNode));
        if (wrote != sizeof(typeDirNode)) {
            CUSTOM_DEBUG_LOG("Error writing resource file header: type node");
            goto cleanup;
        }
        pos += sizeof(typeDirNode);
    }

    // Write all ID directory entries (in type list order).
    for (BuildResTypeNode* t = iq; t != nullptr; t = t->next) {
        if (pos != t->dir_offset) {
            CUSTOM_DEBUG_LOG("Error writing resource file: pos out of sync");
            goto cleanup;
        }
        for (BuildResIdNode* n = t->ids; n != nullptr; n = n->next) {
            ResfileIdDirNode idDirNode;
            idDirNode.id = n->id;
            idDirNode.data_offset = n->data_offset;
            idDirNode.data_size = n->resSize;
            int wrote = _write(outFd, &idDirNode, sizeof(idDirNode));
            if (wrote != sizeof(idDirNode)) {
                CUSTOM_DEBUG_LOG("Error writing resource file header: id node");
                goto cleanup;
            }
            pos += sizeof(idDirNode);
        }
    }

    // Write resource data.
    for (BuildResTypeNode* t = iq; t != nullptr; t = t->next) {
        for (BuildResIdNode* n = t->ids; n != nullptr; n = n->next) {
            if (pos != n->data_offset) {
                CUSTOM_DEBUG_LOG("Error writing resource file data: pos out of sync");
                goto cleanup;
            }
            int wrote = _write(outFd, n->resData, n->resSize);
            if (wrote != n->resSize) {
                CUSTOM_DEBUG_LOG("Error writing resource file data");
                goto cleanup;
            }
            pos += n->resSize;
        }
    }

    ret = 1;

cleanup:
    if (outFd != -1) {
        _close(outFd);
        outFd = -1;
    }
    if (buildFile != nullptr) {
        fclose(buildFile);
        buildFile = nullptr;
    }
    BUILDRES_free_lists(iq);
    return ret;
}
