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

    // Mouse capture / hover tracking (best-effort).
    //
    // The original engine supports mouse capture so a button can receive the matching mouse-up even
    // if the cursor leaves the button while held. Our simplified `TPanel::handle_mouse_*` routing
    // only dispatches to children when `is_inside` is true, so without this a pressed button can
    // get stuck "down" and hover highlight won't clear reliably.
    if (msg == WM_MOUSEMOVE || msg == WM_LBUTTONDOWN || msg == WM_LBUTTONUP || msg == WM_RBUTTONDOWN || msg == WM_RBUTTONUP) {
        const long x = (long)(short)LOWORD(lparam);
        const long y = (long)(short)HIWORD(lparam);

        if (this->mouseOwnerValue && this->mouseOwnerValue->mouse_captured) {
            return this->mouseOwnerValue->wnd_proc(hwnd, msg, wparam, lparam);
        }

        // Clear hover focus when leaving the previous owner.
        if (msg == WM_MOUSEMOVE && this->mouseOwnerValue && !this->mouseOwnerValue->is_inside(x, y)) {
            this->mouseOwnerValue->set_focus(0);
            this->mouseOwnerValue = nullptr;
        }
    }

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

int TPanelSystem::setCurrentPanel(char* name, int modal) {
    // Source of truth: panel.cpp.decomp @ 0x00463E60
    // Find panel by name and make it current
    if (!name) return 0;

    PanelNode* curr = this->panelListValue;
    while (curr) {
        if (curr->panel && curr->panel->panelNameValue) {
            if (strcmp(curr->panel->panelNameValue, name) == 0) {
                this->setCurrentPanel(curr->panel, modal);
                return 1;
            }
        }
        curr = curr->next_node;
    }
    return 0;
}

void TPanelSystem::setCurrentPanel(TPanel* panel, int modal) {
    // Source of truth: panel.cpp.decomp @ 0x00464260
    // Set the current panel and handle modal state
    if (!panel) return;

    // Add panel to system if not already present
    // This handles the case where a newly created screen is being set as current
    bool found = false;
    PanelNode* curr = this->panelListValue;
    while (curr) {
        if (curr->panel == panel) {
            found = true;
            break;
        }
        curr = curr->next_node;
    }
    if (!found) {
        this->add_panel(panel);
    }

    this->currentPanelValue = panel;
    this->modalPanelValue = modal ? panel : nullptr;

    // Trigger redraw of the new current panel
    if (panel->active) {
        panel->set_redraw(TPanel::RedrawMode::RedrawFull);
    }
}

int TPanelSystem::destroyPanel(char* name) {
    // Source of truth: panel.cpp.decomp @ 0x00464060
    // Find panel by name and destroy it
    if (!name) return 0;

    PanelNode* curr = this->panelListValue;
    while (curr) {
        if (curr->panel && curr->panel->panelNameValue) {
            if (strcmp(curr->panel->panelNameValue, name) == 0) {
                TPanel* panel_to_delete = curr->panel;
                this->remove_panel(panel_to_delete);
                delete panel_to_delete;
                return 1;
            }
        }
        curr = curr->next_node;
    }
    return 0;
}

// From decomp: sets the modal panel (captures all input)
void TPanelSystem::setModalPanel(TPanel* panel) {
    if (panel) {
        // Save previous modal panel in the panel's own field
        panel->previousModalPanelValue = this->modalPanelValue;
    }
    this->modalPanelValue = panel;
}

// From decomp: restores the previous modal panel
int TPanelSystem::restorePreviousModalPanel() {
    if (this->modalPanelValue && this->modalPanelValue->previousModalPanelValue) {
        this->modalPanelValue = this->modalPanelValue->previousModalPanelValue;
        return 1;
    }
    this->modalPanelValue = nullptr;
    return 0;
}
