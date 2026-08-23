// VA: 004B33D0 TRIBE_Screen_Sed_Open (constructor)
// PDB source: scr_sedo.cpp
//
// The shared surface uses the proven TScreenPanel and panel-member offsets.
// Remaining constructor drift is register allocation and local-buffer layout.
// BINARY NOTE: The PDB span is scr_sedo.cpp lines 45-99. The natural
// constructor keeps the original EH frame, 19 ordered calls, and +0x478-
// +0x48C member ownership without a handwritten vptr store.
// BLOCKER: The current source emits EBX = this + 0x48C instead of the
// executable's EBX = this + 0x47C and ends four bytes after the oracle.

#include <string.h>
#include "../../include/scr_sedo_context.h"

TRIBE_Screen_Sed_Open::TRIBE_Screen_Sed_Open()
    : TScreenPanel("Scenario Editor Open")
{
    TPanel* tabList[5];
    char info_file[260];

    title = 0;
    list = 0;
    scrollbar = 0;
    okButton = 0;
    cancelButton = 0;
    deleteButton = 0;

    tabList[0] = panel_system.currentPanel();
    strcpy(info_file, ((TEasy_Panel*)tabList[0])->get_info_file());

    void* draw_area = rge_base_game->draw_area;

    if (!setup(draw_area, info_file + 4,
                   ((TEasy_Panel*)tabList[0])->get_info_id(), 1)) {
        setup_error = 1;
        return;
    }

    setup_shadow_area(0);
    set_ideal_size(0x280, 0x1E0);

    if (!create_text(this, &title, 0x24CD, 0x14, 0x14, 600, 0x1E, 1, 1, 0, 0))
        return;

    if (!create_list(this, &list, 0x14, 0x46, 600, 0x154, 0x0B))
        return;

    if (!create_auto_scrollbar(&scrollbar, list, 0x14))
        return;

    TButtonPanel** okPtr = &okButton;
    if (!create_button(this, okPtr, 0xFA1, 0, 0x1E, 0x1B8, 0xB4, 0x1E, 0, 0, 0))
        return;

    if (!create_button(this, &deleteButton, 0x24C9, 0, 0xE6, 0x1B8, 0xB4, 0x1E, 0, 0, 0))
        return;

    if (!create_button(this, &cancelButton, 0xFA2, 0, 0x1AE, 0x1B8, 0xB4, 0x1E, 0, 0, 0))
        return;

    cancelButton->hotkey = 0x1B;
    cancelButton->hotkey_shift = 0;
    deleteButton->hotkey_shift = 0;
    deleteButton->hotkey = 0x2E;

    fillList();

    if (list->currentLine()[0] == 0) {
        okButton->set_disabled(1);
        deleteButton->set_disabled(1);
    }

    set_curr_child(list);

    tabList[1] = list;
    tabList[2] = okButton;
    tabList[3] = deleteButton;
    tabList[4] = cancelButton;
    set_tab_order(tabList + 1, 4);
}
