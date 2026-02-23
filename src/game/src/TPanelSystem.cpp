#include <windows.h>
#include <string.h>
#include "../include/TPanelSystem.h"
#include "../include/TPanel.h"
#include "../include/PanelNode.h"
#include "../include/globals.h"
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
    // TODO: STUB
}

void TPanelSystem::add_panel(TPanel* panel) {
    if (!panel) return;

    // Fully verified. Source of truth: panel.cpp.decomp @ 0x00463D80 (TPanelSystem::addPanel)
    // Only add if a panel with the same name is not already present.
    if (panel->panelNameValue != nullptr && panel->panelNameValue[0] != '\0') {
        for (PanelNode* it = this->panelListValue; it != nullptr; it = it->next_node) {
            if (it->panel && it->panel->panelNameValue &&
                strcmp(it->panel->panelNameValue, panel->panelNameValue) == 0) {
                return;
            }
        }
    }

    PanelNode* newNode = new PanelNode();
    newNode->panel = panel;
    newNode->next_node = this->panelListValue;
    newNode->prev_node = nullptr;

    if (this->panelListValue) {
        this->panelListValue->prev_node = newNode;
    }
    this->panelListValue = newNode;
    this->numberActivePanelsValue++;
    // Decomp: addPanel does NOT set currentPanelValue; that's done by setCurrentPanel.
    panel->previousPanelValue = nullptr;
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

    // Original game dispatches to panel_system->currentPanel() only
    // (see panel.cpp.asm: currentPanel is called from wnd_proc at 0x00420774 etc.)
    // Modal panel takes priority if set, otherwise use current panel.
    TPanel* target = this->modalPanelValue ? this->modalPanelValue : this->currentPanelValue;
    if (target && target->active) {
        return target->wnd_proc(hwnd, msg, wparam, lparam);
    }

    return 0;
}

TPanel* TPanelSystem::currentPanel() {
    // Source of truth: panel.cpp.decomp / panel.cpp.asm (TPanelSystem::currentPanel)
    return this->currentPanelValue;
}

TPanel* TPanelSystem::panel(char* name) {
    // Source of truth: panel.cpp.decomp / panel.cpp.asm
    // Find panel by name and return it
    if (!name) return nullptr;

    PanelNode* curr = this->panelListValue;
    while (curr) {
        if (curr->panel && curr->panel->panelNameValue) {
            if (strcmp(curr->panel->panelNameValue, name) == 0) {
                return curr->panel;
            }
        }
        curr = curr->next_node;
    }
    return nullptr;
}

int TPanelSystem::setCurrentPanel(char* name, int modal) {
    // Source of truth: panel.cpp.decomp @ 0x00463E60
    // Find panel by name and make it current
    if (!name) return 0;

    PanelNode* curr = this->panelListValue;
    while (curr) {
        if (curr->panel && curr->panel->panelNameValue) {
            if (strcmp(curr->panel->panelNameValue, name) == 0) {
                // Decomp: release mouse owner, clear modal and keyboard before switching
                if (this->mouseOwnerValue != nullptr) {
                    this->mouseOwnerValue->release_mouse();
                }
                this->modalPanelValue = nullptr;
                this->keyboardOwnerValue = nullptr;
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
    if (!panel) return;

    // Decomp: save previous panel, unfocus old, focus new
    panel->previousPanelValue = this->currentPanelValue;
    if (this->currentPanelValue != nullptr) {
        this->currentPanelValue->set_focus(0);
    }
    this->currentPanelValue = panel;
    panel->set_focus(1);
    this->currentPanelValue->set_redraw(TPanel::RedrawMode::RedrawFull);
    // Decomp: UpdateWindow(AppWnd) — skip, our loop handles redraws

    // Decomp: if modal flag, set modal panel
    if (modal != 0) {
        this->setModalPanel(this->currentPanelValue);
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

int TPanelSystem::restorePreviousPanel(int destroy_current) {
    // Source of truth: panel.cpp.decomp @ 0x00463EB0
    if (this->currentPanelValue == nullptr) {
        return 0;
    }

    TPanel* current = this->currentPanelValue;
    TPanel* previous = current->previousPanelValue;
    if (previous == nullptr) {
        return 0;
    }

    if (destroy_current == 0) {
        previous->previousPanelValue = current;
    } else {
        if (previous->previousPanelValue == current) {
            previous->previousPanelValue = nullptr;
        }
        if (current->panelNameValue != nullptr) {
            this->destroyPanel(current->panelNameValue);
        }
    }

    this->currentPanelValue = previous;
    this->currentPanelValue->set_focus(1);
    this->currentPanelValue->set_redraw(TPanel::RedrawMode::RedrawFull);
    UpdateWindow(AppWnd);
    return 1;
}

// From decomp: sets the modal panel (captures all input)
void TPanelSystem::setModalPanel(TPanel* panel) {
    if (panel) {
        // Original dialogs live in the panel list so they can be found/destroyed by name.
        bool found = false;
        for (PanelNode* curr = this->panelListValue; curr; curr = curr->next_node) {
            if (curr->panel == panel) {
                found = true;
                break;
            }
        }
        if (!found) {
            this->add_panel(panel);
        }

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

void TPanelSystem::set_restore() {
    // Fully verified. Source of truth: panel.cpp.asm @ 0x004646F0
    for (PanelNode* it = this->panelListValue; it != nullptr; it = it->next_node) {
        if (it->panel != nullptr) {
            it->panel->need_restore = 1;
        }
    }
}
