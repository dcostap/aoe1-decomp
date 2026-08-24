// VA: 004B7330 TRIBE_Screen_Status_Message (constructor overload)
// PDB source: scr_stms.cpp
//
// Attempt log:
// - Baseline used the sibling constructor's TScreenPanel base, EH frame, 0x478 message field, and natural panel flow; 83 bytes differed.
// - Kept param_4 only for the initial -1 test and introduced local info_id for the setup argument; this reproduced the original get_info_id return flow.
// - Exact match: 464/464 bytes, all 9 calls aligned, and the 0x108 EH frame matches.

#include <string.h>
#include "../../include/scr_stms_context.h"

TRIBE_Screen_Status_Message::TRIBE_Screen_Status_Message(
    char* param_1, long param_2, char* param_3, long param_4)
    : TScreenPanel(param_1)
{
    char info_file[260];
    long info_id;
    TEasy_Panel* cur;

    message = 0;
    cur = (TEasy_Panel*)panel_system.currentPanel();

    if (param_3 == 0 && param_4 == -1) {
        if (cur != 0 && cur != (TEasy_Panel*)panel_system.panel("Achievements Screen")) {
            strcpy(info_file, cur->get_info_file());
            info_id = cur->get_info_id();
        } else {
            info_file[0] = 0;
            info_id = -1;
        }
    } else {
        strcpy(info_file, param_3);
        info_id = param_4;
    }

    if (info_file[0] == 0) {
        if (((RGE_Base_Game*)rge_base_game)->multiplayerGame()) {
            strcpy(info_file, "scr3");
            info_id = 0xC385;
        } else {
            strcpy(info_file, "scr2");
            info_id = 0xC384;
        }
    }

    if (!setup(((RGE_Base_Game*)rge_base_game)->draw_area, info_file, info_id, 0)) {
        setup_failed = 1;
    } else {
        set_ideal_size(0x280, 0x1E0);
        create_text(this, &message, (const char*)param_2,
                    0x28, 0x28, 0x230, 0x190, 4, 1, 1, 1);
    }
}
