// VA: 00492D70 TRIBE_Credits_Screen::action
// PDB donor: scr_cred.cpp lines 381-416

#include "../../include/scr_cred_context.h"

long TRIBE_Credits_Screen::action(TPanel* param_1, long param_2,
                                  ulong param_3, ulong param_4) {
    long lVar1;

    if (((param_1 != (TPanel*)0x0) &&
         ((TScrollTextPanel*)param_1 == this->text_panel)) &&
        (param_2 == 1)) {
        this->text_done = 1;
        return 1;
    }
    lVar1 = this->TEasy_Panel::action(param_1, param_2, param_3, param_4);
    return lVar1;
}
