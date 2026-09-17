
#include "../include/Res_file.h"
#include "../include/debuglog.h"
#include "../include/game_globals.h"
#include <ctype.h>
#include <fcntl.h>
#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

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

void __cdecl RESFILE_open_new_resource_file(char* resFileName, char* password, char* path, int open_mode) {
    char resFile[260];
    char error_msg[80];
    resfile_header rHeader;
    int fHandle = -1;
    unsigned char* mapped_file_data = 0;

    sprintf(resFile, "%s%s", path, resFileName);

    if (open_mode == 0) {
        fHandle = (int)CreateFileA(resFile, GENERIC_READ, FILE_SHARE_READ, 0,
            OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
        if (fHandle == -1) {
            sprintf(error_msg,
                "Error: Open_new_ResFile, mapped file %s not Found.", resFileName);
            MessageBoxA(0, error_msg, "RESOURCE ERROR", MB_ICONEXCLAMATION);
            return;
        }

        HANDLE mapping = CreateFileMappingA((HANDLE)fHandle, 0, PAGE_READONLY, 0, 0, 0);
        CloseHandle((HANDLE)fHandle);
        if (mapping == 0) {
            MessageBoxA(0,
                "Error: Open_Mapped_ResFile, Could not map file(1).",
                "RESOURCE ERROR", MB_ICONEXCLAMATION);
            return;
        }

        mapped_file_data = (unsigned char*)MapViewOfFile(mapping, FILE_MAP_READ, 0, 0, 0);
        if (mapped_file_data == 0) {
            MessageBoxA(0,
                "Error: Open_Mapped_ResFile, Could not map file to addr.",
                "RESOURCE ERROR", MB_ICONEXCLAMATION);
            return;
        }
        CloseHandle(mapping);
    } else {
        fHandle = _open(resFile, _O_BINARY);
        if (fHandle == -1) {
            sprintf(error_msg,
                "Error: Open_new_ResFile, file %s not Found.", resFileName);
            MessageBoxA(0, error_msg, "RESOURCE ERROR", MB_ICONEXCLAMATION);
            return;
        }
    }

    ResFileHdr* newFile = (ResFileHdr*)malloc(sizeof(ResFileHdr));
    if (newFile == 0) {
        MessageBoxA(0, "Error: Out of memory in Open_resfile.",
            "RESOURCE ERROR", MB_ICONEXCLAMATION);
        return;
    }

    strcpy(newFile->res_name, resFileName);
    newFile->next = 0;

    if (open_mode == 0) {
        newFile->handle = -1;
        newFile->mapped_file = mapped_file_data;
        newFile->header = (resfile_header*)mapped_file_data;
    } else {
        newFile->handle = fHandle;
        newFile->mapped_file = 0;
        lseek(fHandle, 0, 1);
        if (read(fHandle, &rHeader, 64) != 0x40) {
            __asm int 3
            MessageBoxA(0, "Error: Reading resfile header.",
                "RESOURCE ERROR", MB_ICONEXCLAMATION);
            return;
        }
        newFile->header = (resfile_header*)malloc(rHeader.directory_size);
        lseek(fHandle, 0, 0);
        if (read(fHandle, newFile->header, rHeader.directory_size) !=
            rHeader.directory_size) {
            MessageBoxA(0, "Error: Reading resfile header data.",
                "RESOURCE ERROR", MB_ICONEXCLAMATION);
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

    if (strcmp(newFile->header->password, password) != 0) {
        MessageBoxA(0,
            "Error: Open_ResFile, Corruption detected in resfile.",
            "RESOURCE ERROR", MB_ICONEXCLAMATION);
        return;
    }

    if (strncmp(newFile->header->version, "1.00", 4) != 0) {
        MessageBoxA(0, "Error: Open_ResFile, Resfile not correct.",
            "RESOURCE ERROR", MB_ICONEXCLAMATION);
    }
}

void __cdecl RESFILE_close_new_resource_file(char* res_file) {
    ResFileHdr* cur = Res_Files;
    ResFileHdr* prev = 0;

    while (cur) {
        if (strcmp(res_file, cur->res_name) == 0) {
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

int __cdecl RESFILE_locate_resource(unsigned long rType, unsigned long rId,
    int& file, int& offset, unsigned char*& mapped_file, int& size) {
    ResFileHdr* p = Res_Files;
    file = -1;
    offset = 0;
    mapped_file = 0;
    size = 0;

    if (!p) {
        return 0;
    }

    while (p) {
        resfile_header* hdr = p->header;
        resfile_type_dir_node* dir =
            (resfile_type_dir_node*)((char*)hdr + 0x40);

        for (int x = 0; x < hdr->num_res_types; x++) {
            if (dir[x].type == rType) {
                resfile_id_dir_node* sub =
                    (resfile_id_dir_node*)((char*)hdr + dir[x].dirOffset);

                for (int j = 0; j < dir[x].numID; j++) {
                    if (sub[j].id == rId) {
                        file = p->handle;
                        offset = sub[j].itemOffset;
                        mapped_file = p->mapped_file;
                        size = sub[j].itemSize;
                        return 1;
                    }
                }
            }
        }

        p = p->next;
    }

    return 0;
}

unsigned char* __cdecl RESFILE_load(
    unsigned long rType,
    unsigned long rId,
    int& rLoadType,
    int& rDataSize) {
    int infile;
    int offset;
    unsigned char* mapped_file;
    int datalength;
    char error_string[100];

    rLoadType = -1;
    rDataSize = 0;

    if (RESFILE_locate_resource(rType, rId, infile, offset,
            mapped_file, datalength) == 0) {
        if (resource_missing_flag != 0) {
            sprintf(error_string,
                "ERROR: res_read_bin, resource type %4.4c , id %d, not found",
                rType, rId);
            MessageBoxA(0, error_string, "RESOURCE ERROR", MB_ICONEXCLAMATION);
        }
        return 0;
    }

    if (mapped_file != 0) {
        rLoadType = 0;
        rDataSize = datalength;
        return mapped_file + offset;
    }

    rLoadType = 1;
    unsigned char* data = (unsigned char*)malloc(datalength);
    rDataSize = datalength;
    if (data == 0) {
        MessageBoxA(0, "Error: Out of memory in res_read_bin.",
            "RESOURCE ERROR", MB_ICONEXCLAMATION);
        return 0;
    }

    lseek(infile, offset, 0);
    if (read(infile, data, datalength) != datalength) {
        MessageBoxA(0, "Error: unable to read resource",
            "RESOURCE ERROR", MB_ICONEXCLAMATION);
        return 0;
    }

    return data;
}

int __cdecl RESFILE_Extract_to_File(unsigned long rType, unsigned long rId,
    char* file_name, FILE*& file) {
    int rLoadType;
    int rDataSize;
    char temp_path[260];
    unsigned char* data;

    file = 0;
    data = RESFILE_load(rType, rId, rLoadType, rDataSize);
    if (data == 0) {
        return 0;
    }

    if (GetTempPathA(MAX_PATH, temp_path) == 0) {
        strcpy(temp_path, ".");
    }

    if (GetTempFileNameA(temp_path, "temp", 0, file_name) != 0) {
        file = fopen(file_name, "w+");
        if (file != 0 && rDataSize > 0) {
            fwrite(data, rDataSize, 1, file);
            fseek(file, 0, 0);
        }
    }

    if (rLoadType == 1) {
        free(data);
    }

    return file != 0;
}

void __cdecl RESFILE_Set_Missing_Flag(int FlagVal) {
    resource_missing_flag = FlagVal;
}

int __cdecl RESFILE_Decommit_Mapped_Memory(unsigned char* ResData, int resSize) {
    if ((ResData != 0) && (resSize > 0)) {
        return VirtualFree(ResData, resSize, MEM_DECOMMIT);
    }
    return 0;
}

char header_message[] = "Copyright (c) 1997 Ensemble Studios.\x1a";

int __cdecl RESFILE_build_res_file(char* build_list_file, char* source_path, char* target_path) {
    BuildRes_type_node* ID_List = 0;
    BuildRes_type_node* typeNode;
    BuildRes_type_node* lastType;
    BuildRes_id_node* iq;
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
        iq = typeNode->idList;
        while (iq != 0) {
            if (iq->id == rId) {
                L->Log("Error: duplicate resources: %s & %s",
                    iq->fName, data_filename);
                return 0;
            }
            if (iq->id < rId) {
                lastId = iq;
            }
            iq = iq->next;
        }

        iq = new BuildRes_id_node;
        if (iq == 0) {
            L->Log("Error: out of memory #2");
            return 0;
        }

        iq->id = rId;
        iq->dataOffset = 0;
        iq->resData = 0;
        iq->resSize = 0;
        iq->next = 0;
        strcpy(iq->fName, data_filename);

        int dataHandle = _open(data_filename, _O_BINARY);
        if (dataHandle == -1) {
            L->Log("Error: unable to open file: %s", data_filename);
            delete iq;
            continue;
        }

        if (lastId == 0) {
            iq->next = typeNode->idList;
            typeNode->idList = iq;
        } else {
            iq->next = lastId->next;
            lastId->next = iq;
        }
        typeNode->nIds++;

        fileSize = lseek(dataHandle, 0, 2);
        lseek(dataHandle, 0, 0);
        if (fileSize <= 0) {
            L->Log("Error: file is empty/NULL: %s", data_filename);
            return 0;
        }

        iq->resData = (unsigned char*)malloc(fileSize);
        if (iq->resData == 0) {
            L->Log("Error: out of memory #3");
            return 0;
        }

        iq->resSize = fileSize;
        if (read(dataHandle, iq->resData, fileSize) != fileSize) {
            L->Log("Error: error reading file: %s", data_filename);
            return 0;
        }
        close(dataHandle);
    }

    fclose(buildFile);

    resHandle = _open(resource_filename,
        _O_BINARY | _O_WRONLY | _O_CREAT | _O_TRUNC,
        _S_IREAD | _S_IWRITE);
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
        iq = typeNode->idList;
        while (iq != 0) {
            iq->dataOffset = filePos;
            filePos += iq->resSize;
            iq = iq->next;
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

        iq = typeNode->idList;
        while (iq != 0) {
            idDirNode.id = iq->id;
            idDirNode.itemOffset = iq->dataOffset;
            idDirNode.itemSize = iq->resSize;
            if (write(resHandle, &idDirNode, sizeof(idDirNode)) !=
                sizeof(idDirNode)) {
                L->Log("Error writing resource file header: id node");
                return 0;
            }
            filePos += sizeof(idDirNode);
            iq = iq->next;
        }
        typeNode = typeNode->next;
    }

    typeNode = ID_List;
    while (typeNode != 0) {
        iq = typeNode->idList;
        while (iq != 0) {
            if (filePos != iq->dataOffset) {
                L->Log(
                    "Error writing resource file data: pos out of sync 2");
                return 0;
            }
            if (write(resHandle, iq->resData, iq->resSize) !=
                iq->resSize) {
                L->Log("Error writing resource file data");
                return 0;
            }
            filePos += iq->resSize;
            iq = iq->next;
        }
        typeNode = typeNode->next;
    }

    close(resHandle);

    typeNode = ID_List;
    while (typeNode != 0) {
        iq = typeNode->idList;
        while (iq != 0) {
            if (iq->resData != 0) {
                free(iq->resData);
            }
            BuildRes_id_node* nextId = iq->next;
            delete iq;
            iq = nextId;
        }
        BuildRes_type_node* nextType = typeNode->next;
        delete typeNode;
        typeNode = nextType;
    }

    return 1;
}

unsigned long __cdecl BUILDRES_get_files_resource_type(char* filename) {
    int len = strlen(filename);
    int dotPos;
    char extension[8];

    if (len < 5 || len >= 0x104) {
        return 0;
    }

    for (dotPos = len - 1; dotPos > 0; dotPos--) {
        if (filename[dotPos] == '.') {
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
            char c = filename[dotPos + 1 + i];
            if (isupper(c)) {
                c = tolower(c);
            }
            extension[i] = c;
        }

        res_file_type_info* base = res_extension_table;
        unsigned long next = res_extension_table[0].rType;
        while (next != 0) {
            if (strncmp(base->extension, extension, extLen + 1) == 0) {
                return base->rType;
            }
            next = (base + 1)->rType;
            ++base;
        }
    }

    return 0x62696e61;
}
