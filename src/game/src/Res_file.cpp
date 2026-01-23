#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void RESFILE_build_res_file(char* path, char* file, char* tag) {
    // Stub
}
