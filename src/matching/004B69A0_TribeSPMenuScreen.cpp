// VA: 004B69A0 TribeSPMenuScreen (constructor)
// PDB source: Scr_sing.cpp
//
// MATCHED. Exact 573-byte match.
// FLAGS: /GX required; default flags emit 560 bytes and miss EH constructor shape.
// Fix 1: close_button create call params shifted (a8 was -1, should be 0).
// Fix 2: local temp `cancel*` for hotkey assignments forced VC5 to save ecx=this between stores.

#include "../../include/scr_sing_context.h"

TribeSPMenuScreen::TribeSPMenuScreen() : TScreenPanel("Single Player Menu") {
    ((RGE_Base_Game*)rge_base_game)->setSinglePlayerGame(1);
    ((RGE_Base_Game*)rge_base_game)->setScenarioName("");

    if (!setup(((RGE_Base_Game*)rge_base_game)->draw_area, "scr2", 0xC384, 1)) {
        *(int*)((char*)this + 0xD8) = 1;
        return;
    }

    for (int i = 0; i < 7; i++)
        button[i] = 0;
    close_button = 0;

    set_ideal_size(0x280, 0x1E0);

    if (create_text(this, (TPanel**)&title, 0x2404, 0x14, 0x14, 600, 0x1E, 1, 1, 0, 0)) {
        for (int id = 0x76, i = 0; id < 0x1A2; id += 0x32, i++) {
            if (!create_button(this, (TPanel**)&button[i], "", 0, 0xAA, id, 300, 0x28, 0, 0, 0))
                return;
        }

        if (create_button(this, (TPanel**)&close_button, (const char*)0x3EA, 0, 0, 0, 0, 0, -1, -1, 0)) {
            close_button->set_active(1);
            close_button->set_positioning(9, 4, 4, 4, 4, 0x11, 0x11, 0x11, 0x11, 0, 0, 0, 0);

            ((TButtonPanel*)button[0])->set_text(0, 0x240A);
            ((TButtonPanel*)button[1])->set_text(0, 0x2408);
            ((TButtonPanel*)button[2])->set_text(0, 0x240B);
            ((TButtonPanel*)button[3])->set_text(0, 0x2405);
            ((TButtonPanel*)button[4])->set_text(0, 0x2407);
            ((TButtonPanel*)button[5])->set_text(0, 0x2409);

            // Cancel button hotkey
            TButtonPanel* cancel = (TButtonPanel*)button[5];
            *(int*)((char*)cancel + 0x298) = 0x1B;
            *(int*)((char*)cancel + 0x29C) = 0;

            set_curr_child(button[0]);

            TPanel* tabList[6];
            for (int j = 0; j < 6; j++)
                tabList[j] = button[j];
            set_tab_order(tabList, 6);
        }
    }
}
