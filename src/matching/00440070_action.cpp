// VA: 00440070 TMessageDialog::action
// Dlg_msg.cpp lines 182-203

// Attempt log:
// 1: Existing natural action handler was exact size but differed because parent->action emitted vtable slot +4 instead of original +0xB4.
// 2: Added TPanel vtable padding so action lands at vt[45] / +0xB4; natural source then matched exactly.
// MATCH: python tools/check_function.py --va 00440070 => Result: MATCH / 0.0000%.

#ifndef DLG_MSG_CANONICAL_TU
#include "../../include/dlg_msg_context.h"
#endif

long TMessageDialog::action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4) {
    if (parent != 0 && param_2 == 1) {
        if (param_1 == button[0]) {
            parent->action(this, 0, 0, 0);
            return param_2;
        }
        if (param_1 == button[1]) {
            parent->action(this, 1, 0, 0);
            return 1;
        }
        if (param_1 == button[2]) {
            parent->action(this, 2, 0, 0);
            return 1;
        }
    }
    return TEasy_Panel::action(param_1, param_2, param_3, param_4);
}
