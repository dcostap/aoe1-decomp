// VA: 004AD590 TRIBE_Screen_Sed::command_open
// PDB source: scr_sed.cpp lines 3414-3422 (151 B, 41 asm)
// EH-framed function (/GX)
// Attempt log:

#include "../../include/scr_sed_context.h"

void TRIBE_Screen_Sed::command_open(void)
{
    if (this->need_to_save()) {
        this->popupYesNoCancelDialog(0x2447, s_OpenSaveDialog, 0x1C2, 100);
        return;
    }

    TRIBE_Screen_Sed_Open* open = new TRIBE_Screen_Sed_Open();
    panel_system.setCurrentPanel(s_Scenario_Editor_Open, 0);
}
