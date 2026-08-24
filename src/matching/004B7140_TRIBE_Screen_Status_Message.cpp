// VA: 004B7140 TRIBE_Screen_Status_Message (constructor, variant 1)
// PDB source: scr_stms.cpp
//
// Attempt log:
// - Baseline used the TScreenPanel base, EH frame, 0x478 message field, and
//   natural current-panel metadata selection; 83 bytes differed.
// - An info_id local initialized before the sentinel test kept the 83-byte
//   mismatch and was restored.
// - Same-TU overload 004B7330 showed the source shape: keep param_4 for the
//   initial sentinel test, then assign an uninitialized local info_id in both
//   selection branches and pass it to setup. This matches 464/464 bytes.
// - Exact validation: all 9 calls, the 0x108 EH frame, and all 153 instructions
//   match the original.
// FLAGS: /nologo /c /O2 /Oy /GX (EH)

#include <string.h>
#include "../../include/scr_stms_context.h"

TRIBE_Screen_Status_Message::TRIBE_Screen_Status_Message(
    char* param_1, char* param_2, char* param_3, long param_4)
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
        create_text(this, &message, param_2, 0x28, 0x28, 0x230, 0x190, 4, 1, 1, 1);
    }
}
