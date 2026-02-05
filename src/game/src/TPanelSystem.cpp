#include <windows.h>
#include <string.h>
#include "../include/TPanelSystem.h"
#include "../include/TPanel.h"
#include "../include/PanelNode.h"
#include "../include/custom_debug.h"

// External declaration from Dib.cpp
void* ReadPalette(char* filename, long resource_id, int flag);

void* TPanelSystem::get_palette(char* file, long id) {
    CUSTOM_DEBUG_LOG_FMT("TPanelSystem::get_palette: requested file=%s, id=%d", file ? file : "NULL", (int)id);
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
    // Stub
}

void TPanelSystem::add_panel(TPanel* panel) {
    if (!panel) return;

    PanelNode* newNode = new PanelNode();
    newNode->panel = panel;
    newNode->next_node = this->panelListValue;
    newNode->prev_node = nullptr;

    if (this->panelListValue) {
        this->panelListValue->prev_node = newNode;
    }
    this->panelListValue = newNode;
    this->numberActivePanelsValue++;
    
    // Original engine sets curr_child/currentPanelValue too
    this->currentPanelValue = panel;
}

void TPanelSystem::remove_panel(TPanel* panel) {
    if (!panel || !this->panelListValue) return;

    PanelNode* curr = this->panelListValue;
    while (curr) {
        if (curr->panel == panel) {
            if (curr->prev_node) curr->prev_node->next_node = curr->next_node;
            else this->panelListValue = curr->next_node;

            if (curr->next_node) curr->next_node->prev_node = curr->prev_node;

            delete curr;
            this->numberActivePanelsValue--;
            if (this->currentPanelValue == panel) this->currentPanelValue = nullptr;
            break;
        }
        curr = curr->next_node;
    }
}

long TPanelSystem::check_message(void* hwnd, uint msg, uint wparam, long lparam) {
    if (!this->InputEnabled) return 0;

    // Dispatch to screens in reverse order (top screen first)
    // Actually, panelList is usually LIFO (newest on top)
    PanelNode* curr = this->panelListValue;
    while (curr) {
        if (curr->panel && curr->panel->active) {
            long res = curr->panel->wnd_proc(hwnd, msg, wparam, lparam);
            if (res) return res;
        }
        curr = curr->next_node;
    }

    return 0;
}
