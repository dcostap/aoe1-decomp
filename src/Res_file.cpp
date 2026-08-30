
#include "../include/Res_file.h"
#include "../include/debuglog.h"
#include "../include/game_globals.h"
#include <ctype.h>
#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern "C" int __cdecl __open(const char* path, int flags, ...);
extern "C" int __cdecl sprintf(char* buf, const char* fmt, ...);
#ifndef _INC_IO
extern "C" int __cdecl lseek(int fd, int offset, int whence);
#endif
extern "C" int __cdecl read(int fd, void* buf, unsigned size);
extern "C" int __cdecl close(int fd);
extern "C" int __cdecl write(int fd, const void* buf, unsigned size);

// The executable publishes the node before its password and version checks.
void __cdecl RESFILE_open_new_resource_file(
    char* name, char* cmpName, char* path, int isMapped)
{
    char resFile[260];
    char error_msg[80];
    resfile_header rHdr;
    unsigned char* mappedData = 0;
    int fHandle = -1;

    sprintf(resFile, "%s%s", path, name);

    if (isMapped == 0) {
        HANDLE hFile;
        HANDLE hMapping;

        hFile = CreateFileA(resFile, 0x80000000, 1, 0, 4, 0x80, 0);
        if (hFile == (HANDLE)-1) {
            sprintf(error_msg,
                "Error: Open_new_ResFile, mapped file %s not found.", name);
            MessageBoxA(0, error_msg, "RESOURCE ERROR", 0x30);
            return;
        }

        hMapping = CreateFileMappingA(hFile, 0, 2, 0, 0, 0);
        CloseHandle(hFile);

        if (hMapping == 0) {
            MessageBoxA(0, "Error: Open_Mapped_ResFile, Could not map file.",
                "RESOURCE ERROR", 0x30);
            return;
        }

        mappedData = (unsigned char*)MapViewOfFile(hMapping, 4, 0, 0, 0);
        if (mappedData == 0) {
            MessageBoxA(0, "Error: Open_Mapped_ResFile, Could not map file.",
                "RESOURCE ERROR", 0x30);
            return;
        }

        CloseHandle(hMapping);
    } else {
        fHandle = __open(resFile, 0x8000);
        if (fHandle == -1) {
            sprintf(error_msg,
                "Error: Open_new_ResFile, file %s not Found.", name);
            MessageBoxA(0, error_msg, "RESOURCE ERROR", 0x30);
            return;
        }
    }

    {
        ResFileHdr* node;
        node = (ResFileHdr*)malloc(0x114);
        if (node == 0) {
            MessageBoxA(0, "Error: Out of memory in Open_resfile.",
                "RESOURCE ERROR", 0x30);
            return;
        }

        // The shipped copy has no length guard for a malformed name.
        strcpy(node->res_name, name);
        node->next = 0;

        if (isMapped == 0) {
            node->handle = -1;
            node->mapped_file = mappedData;
            node->header = (resfile_header*)mappedData;
        } else {
            int n;
            node->handle = fHandle;
            node->mapped_file = 0;
            lseek(fHandle, 0, 1);
            n = read(fHandle, &rHdr, sizeof(rHdr));
            if (n != sizeof(rHdr)) {
                // The original reaches a parent-owned INT3 fragment here.
                MessageBoxA(0, "Error: Reading resfile header.",
                    "RESOURCE ERROR", 0x30);
                return;
            }
            node->header = (resfile_header*)malloc(rHdr.directory_size);
            lseek(fHandle, 0, 0);
            n = read(fHandle, node->header, rHdr.directory_size);
            if (n != rHdr.directory_size) {
                MessageBoxA(0, "Error: Reading resfile header data.",
                    "RESOURCE ERROR", 0x30);
                return;
            }
        }

        {
            ResFileHdr* head;
            head = DAT_0086b254;
            if (head == 0) {
                DAT_0086b254 = node;
            } else {
                ResFileHdr* cur;
                cur = head;
                while (cur->next != 0) {
                    cur = cur->next;
                }
                cur->next = node;
            }
        }

        if (strcmp(node->header->password, cmpName) != 0) {
            MessageBoxA(0,
                "Error: Open_ResFile, Corruption detected in resourcefile.",
                "RESOURCE ERROR", 0x30);
            return;
        }

        if (strncmp(node->header->version, "1.00", 4) != 0) {
            MessageBoxA(0, "Error: Open_ResFile, Resfile not correct version.",
                "RESOURCE ERROR", 0x30);
            return;
        }
    }
}

void __cdecl RESFILE_close_new_resource_file(char* name)
{
    ResFileHdr* cur = DAT_0086b254;
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
        DAT_0086b254 = cur->next;
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
    ResFileHdr* cur = DAT_0086b254;
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
        if (DAT_0086b258 != 0) {
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
    DAT_0086b258 = flag;
}

int __cdecl RESFILE_Decommit_Mapped_Memory(unsigned char* address, int size)
{
    if ((address != 0) && (size > 0)) {
        return VirtualFree(address, size, 0x4000);
    }
    return 0;
}

int __cdecl RESFILE_build_res_file(
    char* build_list_file, char* source_path, char* target_path)
{
    char build_filename[260];
    char resource_filename[260];
    char data_filename[260];
    char temp_filename[260];
    char rPassword[40];
    resfile_header theHeader;
    BuildRes_type_node* ID_List;
    BuildRes_id_node* iq;
    int numResTypes;
    unsigned long rId;

    ID_List = 0;
    numResTypes = 0;

    {
        FILE* buildFile;

        sprintf(build_filename, "%s%s", source_path, build_list_file);

        buildFile = fopen(build_filename, "r");
        if (buildFile == 0) {
            L->Log("Error: could not find resource build file: %s",
                build_list_file);
            return 0;
        }

        fscanf(buildFile, "%s %s", temp_filename, rPassword);
        sprintf(resource_filename, "%s%s", target_path, temp_filename);

        while (1) {
            if (fscanf(buildFile, "%s", temp_filename) == -1) break;
            if (fscanf(buildFile, "%d", &rId) == -1) break;
            {
                unsigned long typeID;
                BuildRes_type_node* tnode;
                BuildRes_id_node* pNode;
                BuildRes_type_node* ins;
                BuildRes_type_node* found;
                int fd;
                long size;

                sprintf(data_filename, "%s%s", source_path,
                    temp_filename);

                typeID = BUILDRES_get_files_resource_type(temp_filename);
                if (typeID == 0) {
                    L->Log("Error: could not determine file type of: %s",
                        temp_filename);
                    return 0;
                }

                ins = 0;
                found = 0;
                for (tnode = ID_List; tnode; tnode = tnode->next) {
                    if (tnode->type == typeID) {
                        found = tnode;
                        break;
                    }
                    if (tnode->type < typeID) {
                        ins = tnode;
                    }
                }

                if (found == 0) {
                    found = new BuildRes_type_node;
                    if (found == 0) {
                        L->Log("Error: out of memory #1");
                        return 0;
                    }
                    found->type = typeID;
                    found->idOffset = 0;
                    found->nIds = 0;
                    found->idList = 0;
                    found->next = 0;
                    if (ins == 0) {
                        found->next = ID_List;
                        ID_List = found;
                    } else {
                        found->next = ins->next;
                        ins->next = found;
                    }
                    numResTypes++;
                }

                iq = 0;
                for (pNode = found->idList; pNode; pNode = pNode->next) {
                    if (pNode->id == rId) {
                        L->Log("Error: duplicate resources: %s & %s",
                            pNode->fName, data_filename);
                        return 0;
                    }
                    if (pNode->id < rId) {
                        iq = pNode;
                    }
                }

                pNode = new BuildRes_id_node;
                if (pNode == 0) {
                    L->Log("Error: out of memory #2");
                    return 0;
                }
                pNode->id = rId;
                pNode->dataOffset = 0;
                pNode->resData = 0;
                pNode->resSize = 0;
                pNode->next = 0;
                strcpy(pNode->fName, data_filename);

                fd = __open(data_filename, 0x8000);
                if (fd == -1) {
                    L->Log("Error: unable to open file: %s", data_filename);
                    delete pNode;
                } else {
                    if (iq == 0) {
                        pNode->next = found->idList;
                        found->idList = pNode;
                    } else {
                        pNode->next = iq->next;
                        iq->next = pNode;
                    }
                    found->nIds++;

                    size = lseek(fd, 0, 2);
                    lseek(fd, 0, 0);
                    if (size <= 0) {
                        L->Log("Error: file is empty/NULL: %s", data_filename);
                        return 0;
                    }
                    pNode->resData = (unsigned char*)malloc(size);
                    if (pNode->resData == 0) {
                        L->Log("Error: out of memory #3");
                        return 0;
                    }
                    pNode->resSize = size;
                    if (read(fd, pNode->resData, size) != size) {
                        L->Log("Error: error reading file: %s", data_filename);
                        return 0;
                    }
                    close(fd);
                }
            }
        }

        fclose(buildFile);
    }

    {
        int resHandle;

        resHandle = __open(resource_filename, 0x8301, 0x180);
        if (resHandle == -1) {
            L->Log("Error: unable to create resource file file: %s",
                resource_filename);
            return 0;
        }

        {
            int pos;
            int dirSize;
            BuildRes_type_node* tnode;
            BuildRes_id_node* pNode;
            resfile_type_dir_node typeDirNode;
            resfile_id_dir_node idDirNode;

            tnode = ID_List;
            pos = numResTypes * 12 + 0x40;
            for (; tnode; tnode = tnode->next) {
                tnode->idOffset = pos;
                pos += tnode->nIds * 12;
            }
            dirSize = pos;
            for (tnode = ID_List; tnode; tnode = tnode->next) {
                for (pNode = tnode->idList; pNode; pNode = pNode->next) {
                    pNode->dataOffset = pos;
                    pos += pNode->resSize;
                }
            }

            memset(theHeader.banner_msg, 0, 0x40);
            strcpy(theHeader.banner_msg,
                "Copyright (c) 1997 Ensemble Studios.\x1a");
            strcpy(theHeader.password, "1.00");
            strcpy(theHeader.password + 4, rPassword);

            theHeader.num_res_types = numResTypes;
            theHeader.directory_size = dirSize;

            if (write(resHandle, theHeader.banner_msg, 0x40) != 0x40) {
                L->Log("Error writing resource file header");
                return 0;
            }

            pos = 0x40;
            for (tnode = ID_List; tnode; tnode = tnode->next) {
                typeDirNode.type = tnode->type;
                typeDirNode.dirOffset = tnode->idOffset;
                typeDirNode.numID = tnode->nIds;
                if (write(resHandle, &typeDirNode, 0xC) != 0xC) {
                    L->Log("Error writing resource file header: type node");
                    return 0;
                }
                pos += 0xC;
            }

            for (tnode = ID_List; tnode; tnode = tnode->next) {
                if (pos != tnode->idOffset) {
                    L->Log("Error writing resource file: pos out of sync 1");
                    return 0;
                }
                for (pNode = tnode->idList; pNode; pNode = pNode->next) {
                    idDirNode.id = pNode->id;
                    idDirNode.itemOffset = pNode->dataOffset;
                    idDirNode.itemSize = pNode->resSize;
                    if (write(resHandle, &idDirNode, sizeof(idDirNode)) !=
                        sizeof(idDirNode)) {
                        L->Log("Error writing resource file header: id node");
                        return 0;
                    }
                    pos += 0xC;
                }
            }

            for (tnode = ID_List; tnode; tnode = tnode->next) {
                for (pNode = tnode->idList; pNode; pNode = pNode->next) {
                    if (pos != pNode->dataOffset) {
                        L->Log("Error writing resource file data: pos out of sync 2");
                        return 0;
                    }
                    if (write(resHandle, pNode->resData, pNode->resSize) !=
                        pNode->resSize) {
                        L->Log("Error writing resource file data");
                        return 0;
                    }
                    pos += pNode->resSize;
                }
            }
        }

        close(resHandle);
    }

    {
        BuildRes_id_node* pNode;
        BuildRes_type_node* nextType;
        BuildRes_id_node* nextNode;

        while (ID_List) {
            pNode = ID_List->idList;
            while (pNode) {
                if (pNode->resData != 0) {
                    free(pNode->resData);
                }
                // The executable reads next before delete.
                nextNode = pNode->next;
                delete pNode;
                pNode = nextNode;
            }
            nextType = ID_List->next;
            delete ID_List;
            ID_List = nextType;
        }
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
