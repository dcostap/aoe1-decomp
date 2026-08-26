// VA: 004A68C0 TRIBE_Screen_Name::setup_tab_order
// PDB source: scr_name.cpp
// 2026-05-31: Replaced raw fastcall wrappers with natural member/virtual surface.

#include "../../include/scr_name_context.h"

void TRIBE_Screen_Name::setup_tab_order()
{
    int disabled = 0;
    if (this->name_list->numberLines() == 0) {
        disabled = 1;
    }

    this->remove_button->set_disabled(disabled);
    this->ok_button->set_disabled(disabled);

    TPanel* tab_list[5];
    tab_list[0] = this->name_list;
    tab_list[1] = this->new_button;

    int count = 2;
    if (disabled == 0) {
        tab_list[2] = this->remove_button;
        tab_list[3] = this->ok_button;
        count = 4;
    }

    tab_list[count] = this->cancel_button;
    count++;
    this->set_tab_order(tab_list, count);

    if (this->name_list->numberLines() == 0) {
        this->set_curr_child(this->new_button);
    } else {
        this->set_curr_child(this->name_list);
    }
}
