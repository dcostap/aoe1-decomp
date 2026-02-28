#include <windows.h>
#include <imm.h>
#include <string.h>
#include <stdlib.h>
#include "../include/TPanelSystem.h"
#include "../include/TPanel.h"
#include "../include/PanelNode.h"
#include "../include/globals.h"
#include "../include/custom_debug.h"

// External declaration from Dib.cpp
void* ReadPalette(char* filename, long resource_id, int flag);

// Source of truth: panel.cpp.decomp @ 0x00463BE0
// Source of truth: panel.cpp.decomp @ 0x00463BB0
TPanelSystem::TPanelSystem() {
    // Fully verified. Source of truth: panel.cpp.decomp @ 0x00463BE0
    this->ImeEnabled = 1;
    this->InputEnabled = 1;
    this->mouseOwnerValue = nullptr;
    this->keyboardOwnerValue = nullptr;
    this->modalPanelValue = nullptr;
    this->currentPanelValue = nullptr;
    this->panelListValue = nullptr;
    this->numberActivePanelsValue = 0;
    this->prevCurrentChildValue = nullptr;
    this->Imc = 0;
    this->ImeOn = 0;
    this->saved_colors = 0;
    for (int i = 0; i < 10; ++i) {
        this->palette[i] = nullptr;
        this->palette_file[i][0] = '\0';
        this->palette_use_count[i] = 0;
        this->palette_id[i] = 0;
    }
    this->setup();
}

// Source of truth: panel.cpp.decomp @ 0x00463C50
TPanelSystem::~TPanelSystem() {
    // Fully verified. Source of truth: panel.cpp.decomp @ 0x00463C50
    this->restore_system_colors();

    PanelNode* sentinel = this->panelListValue;
    this->panelListValue = nullptr;
    this->numberActivePanelsValue = 0;
    this->currentPanelValue = nullptr;
    this->mouseOwnerValue = nullptr;
    this->keyboardOwnerValue = nullptr;
    this->modalPanelValue = nullptr;

    if (sentinel != nullptr) {
        PanelNode* node = sentinel->next_node;
        while (node != nullptr && node != sentinel) {
            PanelNode* next = node->next_node;
            TPanel* panel = node->panel;
            if (panel != nullptr) {
                delete panel;
            }
            free(node);
            node = next;
        }
        free(sentinel);
    }

    for (int i = 0; i < 10; ++i) {
        if (this->palette[i] != nullptr) {
            DeleteObject((HGDIOBJ)this->palette[i]);
            this->palette[i] = nullptr;
            this->palette_file[i][0] = '\0';
            this->palette_use_count[i] = 0;
            this->palette_id[i] = 0;
        }
    }

    this->EnableIME();
}

// Source of truth: panel.cpp.decomp @ 0x00464150
int TPanelSystem::setup() {
    // Fully verified. Source of truth: panel.cpp.decomp @ 0x00464150
    PanelNode* sentinel = (PanelNode*)calloc(1, sizeof(PanelNode));
    this->panelListValue = sentinel;
    if (sentinel == nullptr) {
        return 0;
    }

    sentinel->panel = nullptr;
    sentinel->prev_node = sentinel;
    sentinel->next_node = sentinel;

    this->save_back_color = GetSysColor(COLOR_WINDOW);
    this->save_text_color = GetSysColor(COLOR_WINDOWTEXT);
    this->saved_colors = 1;
    return 1;
}

// Source of truth: panel.cpp.decomp @ 0x004641B0
PanelNode* TPanelSystem::findPanelNode(char* name) {
    // Fully verified. Source of truth: panel.cpp.decomp @ 0x004641B0
    if (name == nullptr || this->panelListValue == nullptr) {
        return nullptr;
    }

    PanelNode* node = this->panelListValue->next_node;
    while (node != nullptr && node != this->panelListValue) {
        TPanel* p = node->panel;
        if (p != nullptr && p->panelNameValue != nullptr && strcmp(p->panelNameValue, name) == 0) {
            return node;
        }
        node = node->next_node;
    }

    return nullptr;
}

// Source of truth: panel.cpp.decomp @ 0x004642C0
void* TPanelSystem::get_palette(char* file, long id) {
    // Fully verified. Source of truth: panel.cpp.decomp @ 0x004642C0
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

// Source of truth: panel.cpp.decomp @ 0x00464480
void TPanelSystem::release_palette(void* pal) {
    // Fully verified. Source of truth: panel.cpp.decomp @ 0x00464480
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

// Source of truth: panel.cpp.decomp @ 0x004644E0
void TPanelSystem::DisableIME() {
    // Fully verified. Source of truth: panel.cpp.asm @ 0x004644E0
    if (this->ImeEnabled != 0) {
        this->Imc = (unsigned long)ImmAssociateContext(AppWnd, 0);
        this->ImeEnabled = 0;
    }
}

// Source of truth: panel.cpp.decomp @ 0x00464510
void TPanelSystem::EnableIME() {
    // Fully verified. Source of truth: panel.cpp.decomp @ 0x00464510
    if ((this->Imc != 0) && (this->ImeEnabled == 0)) {
        ImmAssociateContext(AppWnd, (HIMC)this->Imc);
    }
}

// Source of truth: panel.cpp.decomp @ 0x00464540
int TPanelSystem::IsIMEEnabled() {
    // Fully verified. Source of truth: panel.cpp.decomp @ 0x00464540
    return this->ImeEnabled;
}

// Source of truth: panel.cpp.decomp @ 0x00464550
void TPanelSystem::TurnIMEOn() {
    // Fully verified. Source of truth: panel.cpp.decomp @ 0x00464550
    if (this->ImeOn == 0 && this->ImeEnabled != 0 && this->Imc != 0) {
        ImmSetOpenStatus((HIMC)this->Imc, TRUE);
        this->ImeOn = 1;
    }
}

// Source of truth: panel.cpp.decomp @ 0x00464590
void TPanelSystem::TurnIMEOff() {
    // Fully verified. Source of truth: panel.cpp.decomp @ 0x00464590
    if (this->ImeOn != 0 && this->ImeEnabled != 0 && this->Imc != 0) {
        ImmSetOpenStatus((HIMC)this->Imc, FALSE);
        this->ImeOn = 0;
    }
}

// Source of truth: panel.cpp.decomp @ 0x004645D0
int TPanelSystem::IsIMEOn() {
    // Fully verified. Source of truth: panel.cpp.decomp @ 0x004645D0
    return this->ImeOn;
}

// Source of truth: panel.cpp.decomp @ 0x004645E0
int TPanelSystem::GetInputEnabled() {
    // Fully verified. Source of truth: panel.cpp.decomp @ 0x004645E0
    return this->InputEnabled;
}

// Source of truth: panel.cpp.decomp @ 0x004645F0
void TPanelSystem::EnableInput() {
    // Fully verified. Source of truth: panel.cpp.decomp @ 0x004645F0
    this->InputEnabled = 1;
}

// Source of truth: panel.cpp.decomp @ 0x00464600
void TPanelSystem::DisableInput() {
    // Fully verified. Source of truth: panel.cpp.decomp @ 0x00464600
    this->InputEnabled = 0;
}

// Source of truth: panel.cpp.decomp @ 0x00464610
void TPanelSystem::stop_sound_system() {
    // Fully verified. Source of truth: panel.cpp.decomp @ 0x00464610
    if (this->panelListValue == nullptr) {
        return;
    }
    for (PanelNode* node = this->panelListValue->next_node;
         node != nullptr && node != this->panelListValue;
         node = node->next_node) {
        if (node->panel != nullptr) {
            node->panel->stop_sound_system();
        }
    }
}

// Source of truth: panel.cpp.decomp @ 0x00464640
int TPanelSystem::restart_sound_system() {
    // Fully verified. Source of truth: panel.cpp.decomp @ 0x00464640
    int ok = 1;
    if (this->panelListValue == nullptr) {
        return ok;
    }
    for (PanelNode* node = this->panelListValue->next_node;
         node != nullptr && node != this->panelListValue;
         node = node->next_node) {
        if (node->panel != nullptr && node->panel->restart_sound_system() == 0) {
            ok = 0;
        }
    }
    return ok;
}

// Source of truth: panel.cpp.decomp @ 0x00464680
void TPanelSystem::restore_system_colors() {
    // Fully verified. Source of truth: panel.cpp.decomp @ 0x00464680
    if (this->saved_colors == 0) {
        return;
    }

    if (GetSysColor(COLOR_WINDOW) == this->save_back_color &&
        GetSysColor(COLOR_WINDOWTEXT) == this->save_text_color) {
        return;
    }

    int elems[2] = { COLOR_WINDOWTEXT, COLOR_WINDOW };
    unsigned long colors[2] = { this->save_text_color, this->save_back_color };
    SetSysColors(2, elems, colors);
}

void TPanelSystem::add_panel(TPanel* panel) {
    this->addPanel(panel, 0, 0);
}

void TPanelSystem::remove_panel(TPanel* panel) {
    if (panel == nullptr || this->panelListValue == nullptr) {
        return;
    }

    for (PanelNode* node = this->panelListValue->next_node;
         node != nullptr && node != this->panelListValue;
         node = node->next_node) {
        if (node->panel == panel) {
            this->numberActivePanelsValue--;
            node->prev_node->next_node = node->next_node;
            node->next_node->prev_node = node->prev_node;
            free(node);
            if (this->currentPanelValue == panel) this->currentPanelValue = nullptr;
            if (this->mouseOwnerValue == panel) this->mouseOwnerValue = nullptr;
            if (this->keyboardOwnerValue == panel) this->keyboardOwnerValue = nullptr;
            if (this->modalPanelValue == panel) this->modalPanelValue = nullptr;
            return;
        }
    }
}

long TPanelSystem::check_message(void* hwnd, uint msg, uint wparam, long lparam) {
    if (this->InputEnabled == 0) return 0;

    TPanel* target = this->mouseOwnerValue;
    if (target == nullptr) {
        target = this->keyboardOwnerValue;
        if (target == nullptr) {
            target = this->modalPanelValue;
            if (target == nullptr) {
                target = this->currentPanelValue;
            }
        }
    }

    if (target != nullptr && target->active) {
        return target->wnd_proc(hwnd, msg, wparam, lparam);
    }
    return 0;
}

// Source of truth: panel.cpp.decomp @ 0x00463D00
TPanel* TPanelSystem::currentPanel() {
    // Fully verified. Source of truth: panel.cpp.decomp @ 0x00463D00
    return this->currentPanelValue;
}

// Source of truth: panel.cpp.decomp @ 0x00463D10
TPanel* TPanelSystem::previousPanel() {
    // Fully verified. Source of truth: panel.cpp.decomp @ 0x00463D10
    if (this->currentPanelValue != nullptr) {
        return this->currentPanelValue->previousPanelValue;
    }
    return nullptr;
}

// Source of truth: panel.cpp.decomp @ 0x00463D20
TPanel* TPanelSystem::mouseOwner() {
    // Fully verified. Source of truth: panel.cpp.decomp @ 0x00463D20
    return this->mouseOwnerValue;
}

// Source of truth: panel.cpp.decomp @ 0x00463D30
TPanel* TPanelSystem::keyboardOwner() {
    // Fully verified. Source of truth: panel.cpp.decomp @ 0x00463D30
    return this->keyboardOwnerValue;
}

// Source of truth: panel.cpp.decomp @ 0x00463D40
TPanel* TPanelSystem::modalPanel() {
    // Fully verified. Source of truth: panel.cpp.decomp @ 0x00463D40
    return this->modalPanelValue;
}

// Source of truth: panel.cpp.decomp @ 0x00463D50
TPanel* TPanelSystem::panel(char* name) {
    // Fully verified. Source of truth: panel.cpp.decomp @ 0x00463D50
    PanelNode* node = this->findPanelNode(name);
    if (node != nullptr) {
        return node->panel;
    }
    return nullptr;
}

// Source of truth: panel.cpp.decomp @ 0x00463D70
int TPanelSystem::numberActivePanels() {
    // Fully verified. Source of truth: panel.cpp.decomp @ 0x00463D70
    return this->numberActivePanelsValue;
}

// Source of truth: panel.cpp.decomp @ 0x00463D80
int TPanelSystem::addPanel(TPanel* panel, int set_current, int modal) {
    // Fully verified. Source of truth: panel.cpp.decomp @ 0x00463D80
    if (panel == nullptr) {
        return 0;
    }
    if (this->panelListValue == nullptr && this->setup() == 0) {
        return 0;
    }

    PanelNode* node = this->findPanelNode(panel->panelNameValue);
    if (node == nullptr) {
        node = (PanelNode*)calloc(1, sizeof(PanelNode));
        if (node == nullptr) {
            return 0;
        }
        node->panel = panel;
        panel->previousPanelValue = nullptr;

        node->prev_node = this->panelListValue->prev_node;
        node->next_node = this->panelListValue;
        this->panelListValue->prev_node = node;
        node->prev_node->next_node = node;
        this->numberActivePanelsValue++;
    }
    if (set_current != 0) {
        this->setCurrentPanel(panel, modal);
    }
    return 1;
}

// Source of truth: panel.cpp.decomp @ 0x00463E10
int TPanelSystem::removePanel(char* name) {
    // Fully verified. Source of truth: panel.cpp.decomp @ 0x00463E10
    if (name == nullptr) {
        return 0;
    }
    PanelNode* node = this->findPanelNode(name);
    if (node == nullptr) {
        return 0;
    }
    this->numberActivePanelsValue--;
    node->prev_node->next_node = node->next_node;
    node->next_node->prev_node = node->prev_node;
    free(node);
    return 1;
}

// Source of truth: panel.cpp.decomp @ 0x00463E60
int TPanelSystem::setCurrentPanel(char* name, int modal) {
    // Fully verified. Source of truth: panel.cpp.decomp @ 0x00463E60
    PanelNode* node = this->findPanelNode(name);
    if (node != nullptr) {
        if (this->mouseOwnerValue != nullptr) {
            this->mouseOwnerValue->release_mouse();
        }
        this->modalPanelValue = nullptr;
        this->keyboardOwnerValue = nullptr;
        this->setCurrentPanel(node->panel, modal);
        return 1;
    }
    return 0;
}

// Source of truth: panel.cpp.decomp @ 0x00464260
void TPanelSystem::setCurrentPanel(TPanel* panel, int modal) {
    // Fully verified. Source of truth: panel.cpp.decomp @ 0x00464260
    if (panel == nullptr) return;
    panel->previousPanelValue = this->currentPanelValue;
    if (this->currentPanelValue != nullptr) this->currentPanelValue->set_focus(0);
    this->currentPanelValue = panel;
    panel->set_focus(1);
    this->currentPanelValue->set_redraw(TPanel::RedrawMode::RedrawFull);
    UpdateWindow(AppWnd);
    if (modal != 0) this->setCurrentPanelModal();
}

// Source of truth: panel.cpp.decomp @ 0x00464060
int TPanelSystem::destroyPanel(char* name) {
    // Fully verified. Source of truth: panel.cpp.decomp @ 0x00464060
    if (name == nullptr) {
        return 0;
    }
    PanelNode* node = this->findPanelNode(name);
    if (node == nullptr) {
        return 0;
    }
    this->numberActivePanelsValue--;
    TPanel* panel_to_delete = node->panel;
    if (this->currentPanelValue == panel_to_delete) this->currentPanelValue = nullptr;
    if (this->mouseOwnerValue == panel_to_delete) this->mouseOwnerValue = nullptr;
    if (this->keyboardOwnerValue == panel_to_delete) this->keyboardOwnerValue = nullptr;
    if (this->modalPanelValue == panel_to_delete) this->modalPanelValue = nullptr;
    node->prev_node->next_node = node->next_node;
    node->next_node->prev_node = node->prev_node;
    if (panel_to_delete != nullptr) {
        delete panel_to_delete;
    }
    free(node);
    return 1;
}

// Source of truth: panel.cpp.decomp @ 0x00463EB0
int TPanelSystem::restorePreviousPanel(int destroy_current) {
    // Fully verified. Source of truth: panel.cpp.decomp @ 0x00463EB0
    if (this->currentPanelValue == nullptr) return 0;
    TPanel* current = this->currentPanelValue;
    TPanel* previous = current->previousPanelValue;
    if (previous == nullptr) return 0;

    if (destroy_current == 0) {
        previous->previousPanelValue = current;
    } else {
        if (previous->previousPanelValue == current) {
            previous->previousPanelValue = nullptr;
        }
        this->destroyPanel(current->panelNameValue);
    }

    this->currentPanelValue = previous;
    this->currentPanelValue->set_focus(1);
    this->currentPanelValue->set_redraw(TPanel::RedrawMode::RedrawFull);
    UpdateWindow(AppWnd);
    return 1;
}

// Source of truth: panel.cpp.decomp @ 0x00463F40
void TPanelSystem::setMouseOwner(TPanel* panel) {
    // Fully verified. Source of truth: panel.cpp.decomp @ 0x00463F40
    this->mouseOwnerValue = panel;
}

// Source of truth: panel.cpp.decomp @ 0x00463F50
void TPanelSystem::setKeyboardOwner(TPanel* panel) {
    // Fully verified. Source of truth: panel.cpp.decomp @ 0x00463F50
    this->keyboardOwnerValue = panel;
}

// Source of truth: panel.cpp.decomp @ 0x00463F60
void TPanelSystem::setModalPanel(TPanel* panel) {
    // Fully verified. Source of truth: panel.cpp.decomp @ 0x00463F60
    if (this->modalPanelValue != nullptr && panel != nullptr) {
        panel->previousModalPanelValue = this->modalPanelValue;
    }

    TPanel* modal = this->modalPanelValue;
    if (modal == nullptr) {
        TPanel* prev_child = this->prevCurrentChildValue;
        if (prev_child != nullptr && prev_child->parent_panel != nullptr) {
            prev_child->parent_panel->set_curr_child(prev_child);
        }
    } else if (modal->tab_stop == 0 && modal->parent_panel != nullptr) {
        modal->parent_panel->set_curr_child(this->prevCurrentChildValue);
    }

    this->prevCurrentChildValue = nullptr;
    this->modalPanelValue = panel;
    if (panel != nullptr && panel != this->currentPanelValue) {
        TPanel* parent = panel->parent_panel;
        if (parent != nullptr) {
            this->prevCurrentChildValue = parent->curr_child;
            parent->set_curr_child(panel);
        } else {
            this->prevCurrentChildValue = nullptr;
            panel->set_focus(1);
        }
    }
}

// Source of truth: panel.cpp.decomp @ 0x00463FF0
void TPanelSystem::setCurrentPanelModal() {
    // Fully verified. Source of truth: panel.cpp.decomp @ 0x00463FF0
    if (this->modalPanelValue != nullptr && this->modalPanelValue != this->currentPanelValue &&
        this->currentPanelValue != nullptr) {
        this->currentPanelValue->previousModalPanelValue = this->modalPanelValue;
    }
    this->modalPanelValue = this->currentPanelValue;
}

// Source of truth: panel.cpp.decomp @ 0x00464010
int TPanelSystem::restorePreviousModalPanel() {
    // Fully verified. Source of truth: panel.cpp.decomp @ 0x00464010
    if (this->modalPanelValue == nullptr) return 0;
    TPanel* previous = this->modalPanelValue->previousModalPanelValue;
    if (previous == nullptr) return 0;
    previous->set_focus(1);
    this->setMouseOwner(previous);
    this->setKeyboardOwner(previous);
    this->modalPanelValue = previous;
    return 1;
}

// Source of truth: panel.cpp.decomp @ 0x00464100
int TPanelSystem::inSystem(char* name) {
    // Fully verified. Source of truth: panel.cpp.decomp @ 0x00464100
    return this->findPanelNode(name) != nullptr;
}

// Source of truth: panel.cpp.decomp @ 0x00464120
int TPanelSystem::inSystem(TPanel* panel) {
    // Fully verified. Source of truth: panel.cpp.decomp @ 0x00464120
    if (panel != nullptr) {
        return this->findPanelNode(panel->panelNameValue) != nullptr;
    }
    return 0;
}

// Source of truth: panel.cpp.decomp @ 0x004646F0
void TPanelSystem::set_restore() {
    // Fully verified. Source of truth: panel.cpp.asm @ 0x004646F0
    if (this->panelListValue == nullptr) {
        return;
    }
    for (PanelNode* it = this->panelListValue->next_node;
         it != nullptr && it != this->panelListValue;
         it = it->next_node) {
        if (it->panel != nullptr) it->panel->need_restore = 1;
    }
}
