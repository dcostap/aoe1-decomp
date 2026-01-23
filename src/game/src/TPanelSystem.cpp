#include <windows.h>
#include <string.h>
#include "../include/TPanelSystem.h"

// External declaration from Dib.cpp
void* ReadPalette(char* filename, long resource_id, int flag);

void* TPanelSystem::get_palette(char* file, long id) {
    char file_name_upper[260];
    
    if (file) {
        strncpy(file_name_upper, file, 259);
        file_name_upper[259] = '\0';
        
        // Ensure extension if missing (original ASM does this)
        if (!strchr(file_name_upper, '.')) {
            strncat(file_name_upper, ".pal", 259 - strlen(file_name_upper));
        }
        _strupr(file_name_upper);
    } else {
        file_name_upper[0] = '\0';
    }

    int free_index = -1;
    
    // Search cache
    for (int i = 0; i < 10; ++i) {
        if (this->palette[i]) {
            // Match by ID preferred if both specified? ASM logic is a bit intertwined.
            // Primarily match by filename or ID.
            if ((id != -1 && this->palette_id[i] == id) ||
                (file_name_upper[0] != '\0' && _stricmp(this->palette_file[i], file_name_upper) == 0)) {
                this->palette_use_count[i]++;
                return this->palette[i];
            }
        } else if (free_index == -1) {
            free_index = i;
        }
    }

    if (free_index == -1) return nullptr; // Cache full

    // Load new
    void* pal = ReadPalette(file_name_upper, id, 1);
    if (pal) {
        this->palette[free_index] = pal;
        this->palette_use_count[free_index] = 1;
        this->palette_id[free_index] = id;
        if (file_name_upper[0]) {
            strncpy(this->palette_file[free_index], file_name_upper, 259);
        } else {
            this->palette_file[free_index][0] = '\0';
        }
    }
    
    return pal;
}

void TPanelSystem::release_palette(void* pal) {
    if (!pal) return;

    for (int i = 0; i < 10; ++i) {
        if (this->palette[i] == pal) {
            this->palette_use_count[i]--;
            if (this->palette_use_count[i] <= 0) {
                DeleteObject((HGDIOBJ)this->palette[i]);
                this->palette[i] = nullptr;
                this->palette_use_count[i] = 0;
                this->palette_id[i] = -1;
                this->palette_file[i][0] = '\0';
            }
            break;
        }
    }
}

void TPanelSystem::DisableIME() {
    // Stub for now, per plan
}
