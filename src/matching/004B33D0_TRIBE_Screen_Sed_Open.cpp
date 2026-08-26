// VA: 004B33D0 TRIBE_Screen_Sed_Open (constructor)
// PDB source: scr_sedo.cpp
//
// The shared surface uses the proven TScreenPanel and panel-member offsets.
// BINARY NOTE: The PDB span is scr_sedo.cpp lines 45-99. The natural
// constructor keeps the original EH frame, 19 ordered calls, and +0x478-
// +0x48C member ownership without a handwritten vptr store.
//
// Attempt log:
// - The first source had the right frame and calls, but used the wrong
//   callee-saved register map. It emitted EBX = this + 0x48C and four extra
//   bytes after the target boundary.
// - Natural cancel and delete child aliases recover the target EBX/ESI/EDI
//   map. The direct info_file setup pointer recovers the final one-byte LEA.
// - A real from_panel local expands the frame to 0x120 and was rejected.
// - Exact result: 683 bytes, 194 instructions, 19/19 ordered calls,
//   27/27 compatible relocations, and 0.0000% strict difference.

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

    if (!setup(draw_area, info_file,
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

    if (!create_button(this, &okButton, 0xFA1, 0, 0x1E, 0x1B8, 0xB4, 0x1E, 0, 0, 0))
        return;

    if (!create_button(this, &deleteButton, 0x24C9, 0, 0xE6, 0x1B8, 0xB4, 0x1E, 0, 0, 0))
        return;

    if (!create_button(this, &cancelButton, 0xFA2, 0, 0x1AE, 0x1B8, 0xB4, 0x1E, 0, 0, 0))
        return;

    TButtonPanel* cancel = cancelButton;
    cancel->hotkey = 0x1B;
    cancel->hotkey_shift = 0;
    TButtonPanel* delete_button = deleteButton;
    delete_button->hotkey_shift = 0;
    delete_button->hotkey = 0x2E;

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
