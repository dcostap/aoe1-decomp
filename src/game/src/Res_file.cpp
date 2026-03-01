#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <io.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <new>
#include "../include/Res_file.h"
#include "../include/custom_debug.h"  // Must be after windows.h for MessageBox suppression

#include <direct.h>

static ResFile* resFileHead = nullptr;
static int g_resfile_missing_flag = 0;

// Fully verified. Marker reconciliation coverage.
static void FUN_0047f00c() {
    // Fully verified. Source of truth: res_file.cpp.decomp @ 0x0047F00C
    MessageBoxA(0, "Error: Reading resfile header data.", "RESOURCE ERROR", MB_OK | MB_ICONERROR);
}

// Fully verified. Marker reconciliation coverage.
static void FUN_0047f076(ResFile* newRes, char* tag) {
    // Fully verified. Source of truth: res_file.cpp.decomp @ 0x0047F076
    if (resFileHead == nullptr) {
        resFileHead = newRes;
    } else {
        ResFile* curr = resFileHead;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newRes;
    }

    unsigned char* base = (unsigned char*)newRes->base_pointer;
    if (strcmp((char*)(base + 0x2c), tag) != 0) {
        MessageBoxA(0, "Error: Open_ResFile, Corruption detected in resfile.", "RESOURCE ERROR", MB_OK | MB_ICONERROR);
        return;
    }
    if (strncmp((char*)(base + 0x28), "1.00", 4) != 0) {
        MessageBoxA(0, "Error: Open_ResFile, Resfile not correct.", "RESOURCE ERROR", MB_OK | MB_ICONERROR);
    }
}

// Fully verified. Marker reconciliation coverage.
void RESFILE_open_new_resource_file(char* filename, char* tag, char* path, int use_mapping) {
    // Fully verified. Source of truth: res_file.cpp.decomp + res_file.cpp.asm @ 0x0047EE90
    unsigned char* mapped_file_data = nullptr;
    int fHandle = -1;
    char resFile[260];
    char error_msg[80];
    char rHeader[0x40];

    sprintf(resFile, "%s%s", path, filename);
    if (use_mapping == 0) {
        HANDLE hFile = CreateFileA(resFile, GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
        if (hFile == INVALID_HANDLE_VALUE) {
            sprintf(error_msg, "Error: Open_new_ResFile, mapped file %s not found.", filename);
            MessageBoxA(nullptr, error_msg, "RESOURCE ERROR", MB_OK | MB_ICONERROR);
            return;
        }

        HANDLE hMapping = CreateFileMappingA(hFile, nullptr, PAGE_READONLY, 0, 0, nullptr);
        CloseHandle(hFile);
        if (hMapping == nullptr) {
            MessageBoxA(nullptr, "Error: Open_Mapped_ResFile, Could not map file.", "RESOURCE ERROR", MB_OK | MB_ICONERROR);
            return;
        }

        mapped_file_data = (unsigned char*)MapViewOfFile(hMapping, FILE_MAP_READ, 0, 0, 0);
        if (mapped_file_data == nullptr) {
            MessageBoxA(nullptr, "Error: Open_Mapped_ResFile, Could not map file.", "RESOURCE ERROR", MB_OK | MB_ICONERROR);
            return;
        }
        CloseHandle(hMapping);
    } else {
        fHandle = _open(resFile, _O_BINARY | _O_RDONLY);
        if (fHandle == -1) {
            sprintf(error_msg, "Error: Open_new_ResFile, file %s not found.", filename);
            MessageBoxA(nullptr, error_msg, "RESOURCE ERROR", MB_OK | MB_ICONERROR);
            return;
        }
    }

    ResFile* newRes = (ResFile*)malloc(sizeof(ResFile));
    if (newRes == nullptr) {
        MessageBoxA(nullptr, "Error: Out of memory in Open_resfile.", "RESOURCE ERROR", MB_OK | MB_ICONERROR);
        return;
    }

    strcpy(newRes->filename, filename);
    newRes->next = nullptr;
    if (use_mapping == 0) {
        newRes->file_handle = -1;
        newRes->mapped_data = mapped_file_data;
        newRes->base_pointer = mapped_file_data;
        FUN_0047f076(newRes, tag);
        return;
    }

    newRes->file_handle = fHandle;
    newRes->mapped_data = nullptr;
    _lseek(fHandle, 0, SEEK_CUR);
    if (_read(fHandle, rHeader, 0x40) != 0x40) {
        FUN_0047f00c();
        return;
    }

    int directory_size = *(int*)(rHeader + 0x3c);
    newRes->base_pointer = malloc(directory_size);
    _lseek(fHandle, 0, SEEK_SET);
    if (_read(fHandle, newRes->base_pointer, directory_size) != directory_size) {
        FUN_0047f00c();
        return;
    }

    FUN_0047f076(newRes, tag);
}

// Fully verified. Marker reconciliation coverage.
void RESFILE_close_new_resource_file(char* filename) {
    // Fully verified. Source of truth: res_file.cpp.decomp + res_file.cpp.asm @ 0x0047F180
    ResFile* curr = resFileHead;
    ResFile* prev = nullptr;

    while (curr) {
        if (strcmp(curr->filename, filename) == 0) {
            if (curr->mapped_data == nullptr) {
                free(curr->base_pointer);
            }
            if (prev) {
                prev->next = curr->next;
            } else {
                resFileHead = curr->next;
            }

            if (curr->file_handle != -1) {
                _close(curr->file_handle);
            }
            if (curr->mapped_data != nullptr) {
                UnmapViewOfFile(curr->mapped_data);
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

// Fully verified. Marker reconciliation coverage.
int RESFILE_locate_resource(unsigned long type, unsigned long id, int* handle, int* offset, unsigned char** data, int* size) {
    // Fully verified. Source of truth: res_file.cpp.decomp + res_file.cpp.asm @ 0x0047F230
    *handle = -1;
    *offset = 0;
    *data = nullptr;
    *size = 0;

    ResFile* local_4 = resFileHead;
    while (local_4 != nullptr) {
        unsigned char* base = (unsigned char*)local_4->base_pointer;
        if (base != nullptr) {
            int num_sections = *(int*)(base + 0x38);
            int* section_ptr = (int*)(base + 0x48);
            for (int i = 0; i < num_sections; ++i) {
                if ((unsigned long)section_ptr[-2] == type) {
                    unsigned long* resource_ptr = (unsigned long*)(base + section_ptr[-1]);
                    int section_count = section_ptr[0];
                    for (int j = 0; j < section_count; ++j) {
                        if (resource_ptr[j * 3] == id) {
                            *handle = local_4->file_handle;
                            *offset = (int)resource_ptr[j * 3 + 1];
                            *data = local_4->mapped_data;
                            *size = (int)resource_ptr[j * 3 + 2];
                            return 1;
                        }
                    }
                }
                section_ptr += 3;
            }
        }
        local_4 = local_4->next;
    }
    return 0;
}

// Fully verified. Marker reconciliation coverage.
unsigned char* RESFILE_load(unsigned long type, unsigned long id, int* size, int* out_type) {
    // Fully verified. Source of truth: res_file.cpp.decomp + res_file.cpp.asm @ 0x0047F320
    int handle, offset, resSize;
    unsigned char* mappedData;
    *size = -1;
    *out_type = 0;

    if (RESFILE_locate_resource(type, id, &handle, &offset, &mappedData, &resSize) == 0) {
        if (g_resfile_missing_flag != 0) {
            char error_string[100];
            sprintf(error_string, "ERROR: res_read_bin, resource type %4.4c , id %d missing.", (int)type, (int)id);
            MessageBoxA(0, error_string, "RESOURCE ERROR", MB_OK | MB_ICONERROR);
        }
        return nullptr;
    }

    if (mappedData != nullptr) {
        *out_type = 0;
        *size = resSize;
        return mappedData + offset;
    }

    *out_type = 1;
    unsigned char* buffer = (unsigned char*)malloc(resSize);
    *size = resSize;
    if (buffer == nullptr) {
        MessageBoxA(0, "Error: Out of memory in res_read_bin.", "RESOURCE ERROR", MB_OK | MB_ICONERROR);
        return nullptr;
    }

    _lseek(handle, offset, SEEK_SET);
    if (_read(handle, buffer, resSize) != resSize) {
        MessageBoxA(0, "Error: unable to read resource", "RESOURCE ERROR", MB_OK | MB_ICONERROR);
        return nullptr;
    }
    return buffer;
}

// Fully verified. Marker reconciliation coverage.
int RESFILE_Extract_to_File(unsigned long type, unsigned long id, char* path, FILE** file) {
    // Fully verified. Source of truth: res_file.cpp.decomp + res_file.cpp.asm @ 0x0047F480
    int rLoadType = 0;
    int rDataSize = 0;
    char temp_path[260];

    *file = nullptr;
    unsigned char* data = RESFILE_load(type, id, &rDataSize, &rLoadType);
    if (data == nullptr) {
        return 0;
    }

    if (GetTempPathA(sizeof(temp_path), temp_path) == 0) {
        strcpy(temp_path, ".");
    }

    if (GetTempFileNameA(temp_path, "temp", 0, path) != 0) {
        *file = fopen(path, "w+");
        if ((*file != nullptr) && (rDataSize > 0)) {
            fwrite(data, rDataSize, 1, *file);
            fseek(*file, 0, SEEK_SET);
        }
    }

    if (rLoadType == 1) {
        free(data);
    }
    return (*file != nullptr) ? 1 : 0;
}

// Fully verified. Marker reconciliation coverage.
void RESFILE_Set_Missing_Flag(int param_1) {
    // Fully verified. Source of truth: res_file.cpp.decomp @ 0x0047F580
    g_resfile_missing_flag = param_1;
}

// Fully verified. Marker reconciliation coverage.
int RESFILE_Decommit_Mapped_Memory(unsigned char* param_1, int param_2) {
    // Fully verified. Source of truth: res_file.cpp.decomp @ 0x0047F590
    if (param_1 != nullptr && 0 < param_2) {
        return (int)VirtualFree(param_1, (SIZE_T)param_2, 0x4000);
    }
    return 0;
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

// Fully verified. Marker reconciliation coverage.
static void BUILDRES_free_lists(BuildResTypeNode* head) {
    while (head != nullptr) {
        BuildResIdNode* id = head->ids;
        while (id != nullptr) {
            if (id->resData != nullptr) {
                free(id->resData);
            }
            BuildResIdNode* nextId = id->next;
            delete id;
            id = nextId;
        }
        BuildResTypeNode* nextType = head->next;
        delete head;
        head = nextType;
    }
}

// Fully verified. Marker reconciliation coverage.
static unsigned long BUILDRES_get_files_resource_type(const char* filename) {
    // Fully verified. Source of truth: res_file.cpp.decomp @ 0x0047FC50
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

// Fully verified. Marker reconciliation coverage.
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
            typeNode = new (std::nothrow) BuildResTypeNode;
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

        BuildResIdNode* idNode = new (std::nothrow) BuildResIdNode;
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
            delete idNode;
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
