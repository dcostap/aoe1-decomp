// TRIBE_Screen_Sed::command_menu — real pass (EH-framed)
// VA: 004AD270
// Attempt log:
// - Previous raw __fastcall helpers missed EH/new-expression shape and produced an 80-byte too-short body.
// - 2026-05-10 StarryZephyr pass: rewrote as natural typed /GX new-expression with virtual activation check.

#include "../../include/scr_sed_context.h"

int TRIBE_Screen_Sed::command_menu()
{
    TRIBE_Dialog_Sed_Menu* dlg = new TRIBE_Dialog_Sed_Menu(this);
    if (dlg != 0 && dlg->field_D8 != 0) {
        dlg->activate(1);
        return 0;
    }
    return 1;
}
