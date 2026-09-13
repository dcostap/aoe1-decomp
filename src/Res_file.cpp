
#include "../include/Res_file.h"
#include "../include/debuglog.h"
#include "../include/game_globals.h"
#include <ctype.h>
#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static ResFileHdr* Res_Files;
static int resource_missing_flag;

extern "C" int __cdecl _open(const char* path, int flags, ...);
extern "C" int __cdecl sprintf(char* buf, const char* fmt, ...);
#ifndef _INC_IO
extern "C" int __cdecl lseek(int fd, int offset, int whence);
#endif
extern "C" int __cdecl read(int fd, void* buf, unsigned size);
extern "C" int __cdecl close(int fd);
extern "C" int __cdecl write(int fd, const void* buf, unsigned size);

void __cdecl RESFILE_open_new_resource_file(
    char* name, char* cmpName, char* path, int isMapped)
{
    char resFile[260];
    char error_msg[80];
    resfile_header rHeader;
    int fHandle = -1;
    unsigned char* mapped_file_data = 0;

    sprintf(resFile, "%s%s", path, name);

    if (isMapped == 0) {
        fHandle = (int)CreateFileA(resFile, 0x80000000, 1, 0, 4, 0x80, 0);
        if (fHandle == -1) {
            sprintf(error_msg,
                "Error: Open_new_ResFile, mapped file %s not Found.", name);
            MessageBoxA(0, error_msg, "RESOURCE ERROR", 0x30);
            return;
        }

        HANDLE mapping = CreateFileMappingA((HANDLE)fHandle, 0, 2, 0, 0, 0);
        CloseHandle((HANDLE)fHandle);
        if (mapping == 0) {
            MessageBoxA(0,
                "Error: Open_Mapped_ResFile, Could not map file(1).",
                "RESOURCE ERROR", 0x30);
            return;
        }

        mapped_file_data = (unsigned char*)MapViewOfFile(mapping, 4, 0, 0, 0);
        if (mapped_file_data == 0) {
            MessageBoxA(0,
                "Error: Open_Mapped_ResFile, Could not map file to addr.",
                "RESOURCE ERROR", 0x30);
            return;
        }
        CloseHandle(mapping);
    } else {
        fHandle = _open(resFile, 0x8000);
        if (fHandle == -1) {
            sprintf(error_msg,
                "Error: Open_new_ResFile, file %s not Found.", name);
            MessageBoxA(0, error_msg, "RESOURCE ERROR", 0x30);
            return;
        }
    }

    ResFileHdr* newFile = (ResFileHdr*)malloc(sizeof(ResFileHdr));
    if (newFile == 0) {
        MessageBoxA(0, "Error: Out of memory in Open_resfile.",
            "RESOURCE ERROR", 0x30);
        return;
    }

    strcpy(newFile->res_name, name);
    newFile->next = 0;

    if (isMapped == 0) {
        newFile->handle = -1;
        newFile->mapped_file = mapped_file_data;
        newFile->header = (resfile_header*)mapped_file_data;
    } else {
        newFile->handle = fHandle;
        newFile->mapped_file = 0;
        lseek(fHandle, 0, 1);
        if (read(fHandle, &rHeader, 0x40) != 0x40) {
            __asm int 3
            MessageBoxA(0, "Error: Reading resfile header.",
                "RESOURCE ERROR", 0x30);
            return;
        }
        newFile->header = (resfile_header*)malloc(rHeader.directory_size);
        lseek(fHandle, 0, 0);
        if (read(fHandle, newFile->header, rHeader.directory_size) !=
            rHeader.directory_size) {
            MessageBoxA(0, "Error: Reading resfile header data.",
                "RESOURCE ERROR", 0x30);
            return;
        }
    }

    if (Res_Files == 0) {
        Res_Files = newFile;
    } else {
        ResFileHdr* cur = Res_Files;
        while (cur->next != 0) {
            cur = cur->next;
        }
        cur->next = newFile;
    }

    if (strcmp(newFile->header->password, cmpName) != 0) {
        MessageBoxA(0,
            "Error: Open_ResFile, Corruption detected in resfile.",
            "RESOURCE ERROR", 0x30);
        return;
    }

    if (strncmp(newFile->header->version, "1.00", 4) != 0) {
        MessageBoxA(0, "Error: Open_ResFile, Resfile not correct.",
            "RESOURCE ERROR", 0x30);
    }
}

void __cdecl RESFILE_close_new_resource_file(char* name)
{
    ResFileHdr* cur = Res_Files;
    ResFileHdr* prev = 0;

    while (cur) {
        if (strcmp(name, cur->res_name) == 0) {
            goto found;
        }
        prev = cur;
        cur = cur->next;
    }
    return;

found:
    if (cur->mapped_file == 0) {
        free(cur->header);
    }

    if (prev) {
        prev->next = cur->next;
    } else {
        Res_Files = cur->next;
    }

    if (cur->handle != -1) {
        close(cur->handle);
    }

    if (cur->mapped_file != 0) {
        UnmapViewOfFile(cur->mapped_file);
    }

    free(cur);
}

int __cdecl RESFILE_locate_resource(
    unsigned long type_id,
    unsigned long res_id,
    int& out_fd,
    int& out_field1,
    unsigned char*& out_data,
    int& out_field2)
{
    ResFileHdr* cur = Res_Files;
    out_fd = -1;
    out_field1 = 0;
    out_data = 0;
    out_field2 = 0;

    if (!cur) {
        return 0;
    }

    while (cur) {
        resfile_header* hdr = cur->header;
        resfile_type_dir_node* dir =
            (resfile_type_dir_node*)((char*)hdr + 0x40);

        for (int i = 0; i < hdr->num_res_types; i++) {
            if (dir[i].type == type_id) {
                resfile_id_dir_node* sub =
                    (resfile_id_dir_node*)((char*)hdr + dir[i].dirOffset);

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

unsigned char* __cdecl RESFILE_load(
    unsigned long type,
    unsigned long id,
    int& load_type,
    int& data_size)
{
    int file_handle;
    int data_offset;
    int resource_size;
    unsigned char* mapped_data;
    unsigned char* data;
    char error_string[100];

    load_type = -1;
    data_size = 0;

    if (RESFILE_locate_resource(type, id, file_handle, data_offset,
            mapped_data, resource_size) == 0) {
        if (resource_missing_flag != 0) {
            sprintf(error_string,
                "ERROR: res_read_bin, resource type %4.4c , id %d, not found",
                type, id);
            MessageBoxA(0, error_string, "RESOURCE ERROR", 0x30);
            return 0;
        }
    } else {
        if (mapped_data != 0) {
            load_type = 0;
            data = mapped_data + data_offset;
            data_size = resource_size;
        } else {
            load_type = 1;
            data = (unsigned char*)malloc(resource_size);
            data_size = resource_size;
            if (data == 0) {
                MessageBoxA(0, "Error: Out of memory in res_read_bin.",
                    "RESOURCE ERROR", 0x30);
                return 0;
            }

            lseek(file_handle, data_offset, 0);
            if (read(file_handle, data, resource_size) != resource_size) {
                MessageBoxA(0, "Error: unable to read resource",
                    "RESOURCE ERROR", 0x30);
                return 0;
            }
        }

        return data;
    }

    return 0;
}

int __cdecl RESFILE_Extract_to_File(
    unsigned long type,
    unsigned long id,
    char* name,
    FILE*& file)
{
    int load_type;
    int data_size;
    char temp_path[260];
    unsigned char* data;

    file = 0;
    data = RESFILE_load(type, id, load_type, data_size);
    if (data == 0) {
        return 0;
    }

    if (GetTempPathA(0x104, temp_path) == 0) {
        strcpy(temp_path, ".");
    }

    if (GetTempFileNameA(temp_path, "temp", 0, name) != 0) {
        file = fopen(name, "w+");
        if (file != 0 && data_size > 0) {
            fwrite(data, data_size, 1, file);
            fseek(file, 0, 0);
        }
    }

    if (load_type == 1) {
        free(data);
    }

    return file != 0;
}

void __cdecl RESFILE_Set_Missing_Flag(int flag)
{
    resource_missing_flag = flag;
}

int __cdecl RESFILE_Decommit_Mapped_Memory(unsigned char* address, int size)
{
    if ((address != 0) && (size > 0)) {
        return VirtualFree(address, size, 0x4000);
    }
    return 0;
}

char header_message[] = "Copyright (c) 1997 Ensemble Studios.\x1a";

int __cdecl RESFILE_build_res_file(
    char* build_list_file, char* source_path, char* target_path)
{
    BuildRes_type_node* ID_List = 0;
    BuildRes_type_node* typeNode;
    BuildRes_type_node* lastType;
    BuildRes_id_node* idNode;
    BuildRes_id_node* lastId;
    FILE* buildFile;
    int resHandle;
    int numResTypes = 0;
    unsigned long rId;
    int filePos;
    int dataPos;
    int fileSize;
    resfile_header theHeader;
    resfile_type_dir_node typeDirNode;
    resfile_id_dir_node idDirNode;
    char rPassword[40];
    char data_filename[260];
    char temp_filename[260];
    char resource_filename[260];
    char build_filename[260];

    sprintf(build_filename, "%s%s", source_path, build_list_file);
    buildFile = fopen(build_filename, "r");
    if (buildFile == 0) {
        L->Log("Error: could not find resource build file: %s",
            build_list_file);
        return 0;
    }

    fscanf(buildFile, "%s %s", temp_filename, rPassword);
    sprintf(resource_filename, "%s%s", target_path, temp_filename);

    while (fscanf(buildFile, "%s", temp_filename) != EOF) {
        if (fscanf(buildFile, "%d", &rId) == EOF) {
            break;
        }

        sprintf(data_filename, "%s%s", source_path, temp_filename);
        unsigned long type = BUILDRES_get_files_resource_type(temp_filename);
        if (type == 0) {
            L->Log("Error: could not determine file type of: %s",
                temp_filename);
            return 0;
        }

        typeNode = 0;
        lastType = 0;
        BuildRes_type_node* typeCursor = ID_List;
        while (typeCursor != 0) {
            if (typeCursor->type == type) {
                typeNode = typeCursor;
                break;
            }
            if (typeCursor->type < type) {
                lastType = typeCursor;
            }
            typeCursor = typeCursor->next;
        }

        if (typeNode == 0) {
            typeNode = new BuildRes_type_node;
            if (typeNode == 0) {
                L->Log("Error: out of memory #1");
                return 0;
            }

            typeNode->type = type;
            typeNode->idOffset = 0;
            typeNode->nIds = 0;
            typeNode->idList = 0;
            typeNode->next = 0;

            if (lastType == 0) {
                typeNode->next = ID_List;
                ID_List = typeNode;
            } else {
                typeNode->next = lastType->next;
                lastType->next = typeNode;
            }
            numResTypes++;
        }

        lastId = 0;
        idNode = typeNode->idList;
        while (idNode != 0) {
            if (idNode->id == rId) {
                L->Log("Error: duplicate resources: %s & %s",
                    idNode->fName, data_filename);
                return 0;
            }
            if (idNode->id < rId) {
                lastId = idNode;
            }
            idNode = idNode->next;
        }

        idNode = new BuildRes_id_node;
        if (idNode == 0) {
            L->Log("Error: out of memory #2");
            return 0;
        }

        idNode->id = rId;
        idNode->dataOffset = 0;
        idNode->resData = 0;
        idNode->resSize = 0;
        idNode->next = 0;
        strcpy(idNode->fName, data_filename);

        int dataHandle = _open(data_filename, 0x8000);
        if (dataHandle == -1) {
            L->Log("Error: unable to open file: %s", data_filename);
            delete idNode;
            continue;
        }

        if (lastId == 0) {
            idNode->next = typeNode->idList;
            typeNode->idList = idNode;
        } else {
            idNode->next = lastId->next;
            lastId->next = idNode;
        }
        typeNode->nIds++;

        fileSize = lseek(dataHandle, 0, 2);
        lseek(dataHandle, 0, 0);
        if (fileSize <= 0) {
            L->Log("Error: file is empty/NULL: %s", data_filename);
            return 0;
        }

        idNode->resData = (unsigned char*)malloc(fileSize);
        if (idNode->resData == 0) {
            L->Log("Error: out of memory #3");
            return 0;
        }

        idNode->resSize = fileSize;
        if (read(dataHandle, idNode->resData, fileSize) != fileSize) {
            L->Log("Error: error reading file: %s", data_filename);
            return 0;
        }
        close(dataHandle);
    }

    fclose(buildFile);

    resHandle = _open(resource_filename, 0x8301, 0x180);
    if (resHandle == -1) {
        L->Log("Error: unable to create resource file file: %s",
            resource_filename);
        return 0;
    }

    dataPos = numResTypes * sizeof(resfile_type_dir_node) +
        sizeof(resfile_header);
    typeNode = ID_List;
    while (typeNode != 0) {
        typeNode->idOffset = dataPos;
        dataPos += typeNode->nIds * sizeof(resfile_id_dir_node);
        typeNode = typeNode->next;
    }

    typeNode = ID_List;
    filePos = dataPos;
    while (typeNode != 0) {
        idNode = typeNode->idList;
        while (idNode != 0) {
            idNode->dataOffset = filePos;
            filePos += idNode->resSize;
            idNode = idNode->next;
        }
        typeNode = typeNode->next;
    }

    memset(&theHeader, 0, sizeof(theHeader));
    strcpy(theHeader.banner_msg, header_message);
    strcpy(theHeader.version, "1.00");
    strcpy(theHeader.password, rPassword);
    theHeader.num_res_types = numResTypes;
    theHeader.directory_size = dataPos;

    if (write(resHandle, &theHeader, sizeof(theHeader)) != sizeof(theHeader)) {
        L->Log("Error writing resource file header");
        return 0;
    }

    filePos = sizeof(resfile_header);
    typeNode = ID_List;
    while (typeNode != 0) {
        typeDirNode.type = typeNode->type;
        typeDirNode.dirOffset = typeNode->idOffset;
        typeDirNode.numID = typeNode->nIds;
        if (write(resHandle, &typeDirNode, sizeof(typeDirNode)) !=
            sizeof(typeDirNode)) {
            L->Log("Error writing resource file header: type node");
            return 0;
        }
        filePos += sizeof(typeDirNode);
        typeNode = typeNode->next;
    }

    typeNode = ID_List;
    while (typeNode != 0) {
        if (filePos != typeNode->idOffset) {
            L->Log("Error writing resource file: pos out of sync 1");
            return 0;
        }

        idNode = typeNode->idList;
        while (idNode != 0) {
            idDirNode.id = idNode->id;
            idDirNode.itemOffset = idNode->dataOffset;
            idDirNode.itemSize = idNode->resSize;
            if (write(resHandle, &idDirNode, sizeof(idDirNode)) !=
                sizeof(idDirNode)) {
                L->Log("Error writing resource file header: id node");
                return 0;
            }
            filePos += sizeof(idDirNode);
            idNode = idNode->next;
        }
        typeNode = typeNode->next;
    }

    typeNode = ID_List;
    while (typeNode != 0) {
        idNode = typeNode->idList;
        while (idNode != 0) {
            if (filePos != idNode->dataOffset) {
                L->Log(
                    "Error writing resource file data: pos out of sync 2");
                return 0;
            }
            if (write(resHandle, idNode->resData, idNode->resSize) !=
                idNode->resSize) {
                L->Log("Error writing resource file data");
                return 0;
            }
            filePos += idNode->resSize;
            idNode = idNode->next;
        }
        typeNode = typeNode->next;
    }

    close(resHandle);

    typeNode = ID_List;
    while (typeNode != 0) {
        idNode = typeNode->idList;
        while (idNode != 0) {
            if (idNode->resData != 0) {
                free(idNode->resData);
            }
            BuildRes_id_node* nextId = idNode->next;
            delete idNode;
            idNode = nextId;
        }
        BuildRes_type_node* nextType = typeNode->next;
        delete typeNode;
        typeNode = nextType;
    }

    return 1;
}

unsigned long __cdecl BUILDRES_get_files_resource_type(char* name)
{
    int len = strlen(name);
    int dotPos;
    char extBuf[8];

    if (len < 5 || len >= 0x104) {
        return 0;
    }

    for (dotPos = len - 1; dotPos > 0; dotPos--) {
        if (name[dotPos] == '.') {
            break;
        }
    }

    if (dotPos == 0) {
        return 0;
    }

    if (len - dotPos - 1 > 3) {
        return 0;
    }

    {
        int i;
        int extLen = len - dotPos - 1;
        for (i = 0; i <= extLen; i++) {
            char c = name[dotPos + 1 + i];
            if (isupper(c)) {
                c = tolower(c);
            }
            extBuf[i] = c;
        }

        res_file_type_info* base = res_extension_table;
        unsigned long next = res_extension_table[0].rType;
        while (next != 0) {
            if (strncmp(base->extension, extBuf, extLen + 1) == 0) {
                return base->rType;
            }
            next = (base + 1)->rType;
            ++base;
        }
    }

    return 0x62696e61;
}
