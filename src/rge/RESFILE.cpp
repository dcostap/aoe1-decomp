#include "RESFILE.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <io.h>
#include <fcntl.h>

ResFileHdr *DAT_0086b254 = nullptr;

void RESFILE_build_res_file(const char* name, const char* dir, const char* ext) {
    // STUB: Original logic for building resource files from .rm files
}

void RESFILE_open_new_resource_file(const char* name, const char* dir, const char* ext, int flag) {
    char resFile[260];
    sprintf(resFile, "%s%s", ext ? ext : "", name);

    int fHandle = -1;
    uchar *mapped_file_data = nullptr;

    if (flag == 0) {
        HANDLE hFile = CreateFileA(resFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
        if (hFile != INVALID_HANDLE_VALUE) {
            HANDLE hMap = CreateFileMappingA(hFile, NULL, PAGE_READONLY, 0, 0, NULL);
            CloseHandle(hFile);
            if (hMap != NULL) {
                mapped_file_data = (uchar *)MapViewOfFile(hMap, FILE_MAP_READ, 0, 0, 0);
                CloseHandle(hMap);
            }
        }
    } else {
        fHandle = _open(resFile, _O_BINARY | _O_RDONLY);
    }

    if (fHandle == -1 && mapped_file_data == nullptr) {
        // Error handling
        return;
    }

    ResFileHdr *hdr = (ResFileHdr *)malloc(sizeof(ResFileHdr));
    if (!hdr) return;

    memset(hdr, 0, sizeof(ResFileHdr));
    strncpy(hdr->res_name, name, 259);
    hdr->next = nullptr;

    if (flag == 0) {
        hdr->handle = -1;
        hdr->mapped_file = mapped_file_data;
        hdr->header = (resfile_header *)mapped_file_data;
    } else {
        hdr->handle = fHandle;
        hdr->mapped_file = nullptr;
        
        resfile_header rHeader;
        _read(fHandle, &rHeader, sizeof(resfile_header));
        
        hdr->header = (resfile_header *)malloc(rHeader.directory_size);
        _lseek(fHandle, 0, SEEK_SET);
        _read(fHandle, hdr->header, rHeader.directory_size);
    }

    // Add to linked list
    if (DAT_0086b254 == nullptr) {
        DAT_0086b254 = hdr;
    } else {
        ResFileHdr *curr = DAT_0086b254;
        while (curr->next) curr = curr->next;
        curr->next = hdr;
    }
}

int RESFILE_locate_resource(ulong type, ulong id, int *handle, int *offset, uchar **mapped_ptr, int *size) {
    ResFileHdr *curr = DAT_0086b254;
    *handle = -1;
    *offset = 0;
    *mapped_ptr = nullptr;
    *size = 0;

    while (curr) {
        resfile_header *h = curr->header;
        if (h) {
            int num_types = h->num_res_types;
            struct type_entry {
                ulong id;
                int offset;
                int count;
            } *types = (type_entry *)((char *)h + 0x40);

            for (int i = 0; i < num_types; i++) {
                if (types[i].id == type) {
                    struct res_entry {
                        ulong id;
                        int offset;
                        int size;
                    } *res = (res_entry *)((char *)h + types[i].offset);

                    for (int j = 0; j < types[i].count; j++) {
                        if (res[j].id == id) {
                            *handle = curr->handle;
                            *offset = res[j].offset;
                            *mapped_ptr = curr->mapped_file;
                            *size = res[j].size;
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

uchar * RESFILE_load(ulong type, ulong id, int *size, int *out_flag) {
    int handle, offset, res_size;
    uchar *mapped_ptr;
    
    if (RESFILE_locate_resource(type, id, &handle, &offset, &mapped_ptr, &res_size)) {
        *size = res_size;
        if (mapped_ptr) {
            *out_flag = 0;
            return mapped_ptr + offset;
        } else {
            *out_flag = 1;
            uchar *data = (uchar *)malloc(res_size);
            if (data) {
                _lseek(handle, offset, SEEK_SET);
                _read(handle, data, res_size);
                return data;
            }
        }
    }
    return nullptr;
}

void RESFILE_close_new_resource_file(const char *name) {
    ResFileHdr *curr = DAT_0086b254;
    ResFileHdr *prev = nullptr;

    while (curr) {
        if (strcmp(curr->res_name, name) == 0) {
            if (prev) prev->next = curr->next;
            else DAT_0086b254 = curr->next;

            if (curr->handle != -1) {
                _close(curr->handle);
                free(curr->header);
            } else if (curr->mapped_file) {
                UnmapViewOfFile(curr->mapped_file);
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}
