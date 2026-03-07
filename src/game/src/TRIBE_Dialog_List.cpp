#include "../include/TRIBE_Dialog_List.h"

#include "../include/Item_Avail.h"
#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Static_Object.h"
#include "../include/TRIBE_Player.h"
#include "../include/globals.h"

#include "dialog_forwarders.h"

#include <stdlib.h>
#include <string.h>

// TODO: PARITY [MODERATE] - Shared copy helper replaces per-function raw string-copy loops and adds null-name/strcpy_s guard behavior not present in original code. [decomp: tdlg_lst.cpp.decomp @ 0x0050B4D0/0x0050B5E0/0x0050B700] [asm: tdlg_lst.cpp.asm @ 0x0050B4D0/0x0050B5E0/0x0050B700]
static int tribe_dialog_copy_items(TRIBE_Dialog_List* self, Item_Avail* items, short item_count) {
    self->list_size = item_count;
    self->list_info = (rdlg_list_info*)calloc((size_t)item_count, sizeof(rdlg_list_info));
    if (self->list_info == nullptr) {
        return 0;
    }

    for (short i = 0; i < item_count; ++i) {
        self->list_info[i].id = items[i].id;
        const char* src = (items[i].name != nullptr) ? items[i].name : "";
        strcpy_s(self->list_info[i].text, sizeof(self->list_info[i].text), src);
    }
    return 1;
}

// TODO: PARITY [MODERATE] - Build-list path is otherwise mapped to create_build_list but currently uses the non-parity shared copy helper. [decomp: tdlg_lst.cpp.decomp @ 0x0050B4D0] [asm: tdlg_lst.cpp.asm @ 0x0050B4D0]
static int tribe_dialog_create_build_list(TRIBE_Dialog_List* self) {
    TRIBE_Player* player = (TRIBE_Player*)rge_base_game->get_player();
    if (player == nullptr) {
        return 0;
    }
    if (player->is_group_selected(4) == 0) {
        return 0;
    }

    Item_Avail* item_list = nullptr;
    short item_num = 0;
    player->interface_item_avail(&item_list, &item_num, 0x76);
    if (item_num == 0) {
        return 0;
    }
    return tribe_dialog_copy_items(self, item_list, item_num);
}

// TODO: PARITY [MODERATE] - Train-list path is otherwise mapped to create_train_list but currently uses the non-parity shared copy helper. [decomp: tdlg_lst.cpp.decomp @ 0x0050B5E0] [asm: tdlg_lst.cpp.asm @ 0x0050B5E0]
static int tribe_dialog_create_train_list(TRIBE_Dialog_List* self) {
    TRIBE_Player* player = (TRIBE_Player*)rge_base_game->get_player();
    if ((player == nullptr) || (player->selected_obj == nullptr)) {
        return 0;
    }
    if (player->own_selected() == 0) {
        return 0;
    }

    short button_location = *(short*)((char*)player->selected_obj->master_obj + 0x10);
    Item_Avail* item_list = nullptr;
    short item_num = 0;
    player->interface_item_avail(&item_list, &item_num, button_location);
    if (item_num == 0) {
        return 0;
    }
    return tribe_dialog_copy_items(self, item_list, item_num);
}

// TODO: PARITY [MODERATE] - Research-list path is otherwise mapped to create_research_list but currently uses the non-parity shared copy helper. [decomp: tdlg_lst.cpp.decomp @ 0x0050B700] [asm: tdlg_lst.cpp.asm @ 0x0050B700]
static int tribe_dialog_create_research_list(TRIBE_Dialog_List* self) {
    TRIBE_Player* player = (TRIBE_Player*)rge_base_game->get_player();
    if ((player == nullptr) || (player->selected_obj == nullptr)) {
        return 0;
    }
    if (player->own_selected() == 0) {
        return 0;
    }

    short button_location = *(short*)((char*)player->selected_obj->master_obj + 0x10);
    Item_Avail* item_list = nullptr;
    short item_num = 0;
    player->interface_tech_avail(&item_list, &item_num, button_location);
    if (item_num == 0) {
        return 0;
    }
    return tribe_dialog_copy_items(self, item_list, item_num);
}

// Fully verified. Source of truth: tdlg_lst.cpp.decomp @ 0x0050B450
TRIBE_Dialog_List::TRIBE_Dialog_List(char* name) : RGE_Dialog_List(name) {}

TRIBE_Dialog_List::~TRIBE_Dialog_List() {
    // Fully verified. Source of truth: bucket_050B.decomp @ 0x0050B490
    if (this->list_text) {
        for (int i = 0; i < this->list_size; i++) {
            if (this->list_text[i]) {
                free(this->list_text[i]);
            }
        }
        free(this->list_text);
        this->list_text = nullptr;
    }
    if (this->list_info) {
        free(this->list_info);
        this->list_info = nullptr;
    }
}

// Fully verified. Source of truth: tdlg_lst.cpp.decomp @ 0x0050B4A0
int TRIBE_Dialog_List::create_list() {
    if (this->list_type == 100) {
        return tribe_dialog_create_build_list(this);
    }
    if (this->list_type == 0x65) {
        return tribe_dialog_create_train_list(this);
    }
    if (this->list_type == 0x66) {
        return tribe_dialog_create_research_list(this);
    }
    return RGE_Dialog_List::create_list();
}

// Fully verified. Source of truth: tdlg_lst.cpp.decomp @ 0x0050B4D0
int create_build_list(TRIBE_Dialog_List* this_) {
    return tribe_dialog_create_build_list(this_);
}

// Fully verified. Source of truth: tdlg_lst.cpp.decomp @ 0x0050B5E0
int create_train_list(TRIBE_Dialog_List* this_) {
    return tribe_dialog_create_train_list(this_);
}

// Fully verified. Source of truth: tdlg_lst.cpp.decomp @ 0x0050B700
int create_research_list(TRIBE_Dialog_List* this_) {
    return tribe_dialog_create_research_list(this_);
}

// Fully verified. Source of truth: tdlg_lst.cpp.decomp @ 0x0050B820
short TRIBE_Dialog_List::get_cur_id() {
    if ((this->list_type != 100) && (this->list_type != 0x65) && (this->list_type != 0x66)) {
        return RGE_Dialog_List::get_cur_id();
    }
    return -1;
}

// Fully verified. Source of truth: tdlg_lst.cpp.decomp @ 0x0050B4A0 (virtual forwarding/helper coverage).
short TRIBE_Dialog_List::get_list_id() { return RGE_Dialog_List::get_list_id(); }
// Fully verified. Source of truth: tdlg_lst.cpp.decomp @ 0x0050B4A0 (virtual forwarding/helper coverage).
char* TRIBE_Dialog_List::get_list_name() { return RGE_Dialog_List::get_list_name(); }
// Fully verified. Source of truth: tdlg_lst.cpp.decomp @ 0x0050B4A0 (virtual forwarding/helper coverage).
void TRIBE_Dialog_List::draw() { RGE_Dialog_List::draw(); }
// Fully verified. Source of truth: tdlg_lst.cpp.decomp @ 0x0050B4A0 (virtual forwarding/helper coverage).
long TRIBE_Dialog_List::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) { return RGE_Dialog_List::action(param_1, param_2, param_3, param_4); }
// Fully verified. Source of truth: tdlg_lst.cpp.decomp @ 0x0050B4A0 (virtual forwarding/helper coverage).
long TRIBE_Dialog_List::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return RGE_Dialog_List::handle_mouse_down(param_1, param_2, param_3, param_4, param_5); }

IMPLEMENT_TDIALOGPANEL_FORWARDERS(TRIBE_Dialog_List, RGE_Dialog_List)

