#include "common.h"
#include "Res_file.h"
#include <cstdio>
#include <cstring>
#include <malloc.h>
#include <io.h>
#include <fcntl.h>
#include <sys/stat.h>

// Resource file management
// Based on analysis of registry.cpp.asm (0047ee90+)

// External global to track opened resource files
// This is a linked list of ResourceFileNode structures
static ResourceFileNode* g_resource_files = nullptr; // Matches DAT_0086b254

void RESFILE_open_new_resource_file(const char* filename, const char* tag, const char* directory, int mode) {
    // Log FIRST THING
    FILE* log = fopen("aoe_debug.log", "a");
    if (log) {
        fprintf(log, "RESFILE_open_new_resource_file called: filename=%s, directory=%s, mode=%d\n", filename, directory, mode);
        fclose(log);
    }
    
    // Based on analysis at 0047ee90+
    
    // Construct full path: directory + filename
    char resFile[260];
    sprintf(resFile, "%s%s", directory, filename);
    
    // Log to file
    log = fopen("aoe_debug.log", "a");
    if (log) {
        fprintf(log, "Opening resource file: %s\n", resFile);
    }
    
    if (mode == 0) {
        // Memory-mapped mode (0047eed1+)
        // For now, we'll use the simpler file handle mode
        // TODO: Implement memory-mapped file support using CreateFileMapping/MapViewOfFile
        if (log) {
            fprintf(log, "Warning: Memory-mapped mode not yet implemented for %s, using file handle mode\n", filename);
            fclose(log);
        }
        mode = 1;
    }
    
    if (mode != 0) {
        // File handle mode (0047efde+)
        
        // Open file for reading
        int fHandle = _open(resFile, _O_RDONLY | _O_BINARY);
        if (fHandle == -1) {
            if (log) {
                fprintf(log, "Error: Open_new_ResFile, could not open file %s\n", filename);
                fclose(log);
            }
            return;
        }
        
        // Seek to beginning (0047efe1: lseek with SEEK_SET)
        _lseek(fHandle, 0, SEEK_SET);
        
        // Read DRS header (0047eff7: read 0x40 bytes)
        DRS_Header rHeader;
        if (_read(fHandle, &rHeader, 0x40) != 0x40) {
            if (log) {
                fprintf(log, "Error: Reading resfile header.\n");
                fclose(log);
            }
            _close(fHandle);
            return;
        }
        
        // Log header info
        log = fopen("aoe_debug.log", "a");
        if (log) {
            fprintf(log, "Header: version='%.*s', num_tables=%d, first_file_offset=%d\n",
                    4, rHeader.version, rHeader.num_table_types, rHeader.offset_first_file);
            fclose(log);
        }
        
        // Calculate size of directory data (header + table info)
        // We need to store the entire header AND the table entries
        size_t header_and_tables_size = 0x40 + (rHeader.num_table_types * sizeof(DRS_Table_Info));
        
        // Allocate directory data (0047f027+)
        void* directory_data = malloc(header_and_tables_size);
        if (!directory_data) {
            if (log) {
                fprintf(log, "Error: Out of memory allocating directory for %s\n", filename);
                fclose(log);
            }
            _close(fHandle);
            return;
        }
        
        // Seek back to start and read header + tables (0047f038+)
        _lseek(fHandle, 0, SEEK_SET);
        if (_read(fHandle, directory_data, (unsigned int)header_and_tables_size) != (int)header_and_tables_size) {
            if (log) {
                fprintf(log, "Error: Reading resfile header data.\n");
                fclose(log);
            }
            free(directory_data);
            _close(fHandle);
            return;
        }
        
        // Allocate resource file node (0047ef6f: malloc 0x114)
        ResourceFileNode* node = (ResourceFileNode*)malloc(0x114);
        if (!node) {
            if (log) {
                fprintf(log, "Error: Out of memory in Open_resfile.\n");
                fclose(log);
            }
            free(directory_data);
            _close(fHandle);
            return;
        }
        
        // Initialize node (0047ef9c+)
        memset(node, 0, 0x114);
        strcpy(node->filename, filename);
        node->next = nullptr;
        node->file_handle = fHandle;
        node->mapped_data = nullptr;
        node->directory_data = directory_data;
        
        // Add to linked list (0047f076+)
        if (g_resource_files == nullptr) {
            // First node
            g_resource_files = node;
        } else {
            // Add to end of list
            ResourceFileNode* current = g_resource_files;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = node;
        }
        
        // Verify file type tag matches (0047f0a4+)
        // Version string is at offset +0x28 in the header
        DRS_Header* dir_header = (DRS_Header*)directory_data;
        if (strncmp(dir_header->version, "1.00", 4) != 0) {
            if (log) {
                fprintf(log, "Error: Open_ResFile, Resfile version not correct for %s (version='%.*s').\n", 
                        filename, 4, dir_header->version);
                fclose(log);
            }
        } else {
            if (log) {
                fprintf(log, "Successfully opened resource file: %s\n", filename);
                fclose(log);
            }
        }
    }
}

void RESFILE_close_new_resource_file(const char* filename) {
    // TODO: Implement resource file closing
    // This should:
    // 1. Find the resource file by name
    // 2. Close file handle or unmap memory
    // 3. Free allocated memory
    // 4. Remove from linked list
}

