// VA: 0043EF80 TListDialog::setup (main)
// dlg_list.cpp lines 66-96

// attempt 1: main setup with child panel creation
// 416/420 bytes (99% size) — 4 bytes short
// attempt 2: restored the dlg_list/panel virtual surface, the nested renderArea
// evaluation, and the original list/button parameter ownership.
// attempt 3: added the proven TPanel data gap; title/list/scroll field addresses and the
// first 0xEA bytes aligned, leaving a localized button-call schedule drift.
// attempt 4: typed cancel output-pointer and receiver locals were codegen duplicates or
// worsened the suffix; rolled back to direct member ownership.
// attempt 5: restored the virtual long setup overload declaration; codegen duplicate.
// attempt 6: direct create_button result tests were tried in both orders.  The retained
// natural shape tests OK directly and assigns the cancel result; it reaches 420/420 bytes,
// 10/10 ordered calls, 97.14% shape, 88 differing bytes.  Remaining drift starts at the
// three button-argument stack displacements after scroll_cur_line and the downstream cancel tail.
// attempt 7: conditional result assignment around the cancel create_button emitted duplicate
// code; restored the separate result assignment and retained the clean source.
// attempt 8: the prior best ABI basin used binary-supported button argument ownership and a
// named cancel receiver; both stayed natural but left a localized list/create-register mismatch.
// attempt 9: removing the create_list result temporary and guarding its call directly restored the
// original vslot +0x110 register color and produced an exact 420-byte match.

#include "../../include/dlg_list_context.h"

long TListDialog::setup(TPanel* param_1, char* param_2, long param_3, long param_4,
    long param_5, long param_6, long param_7, long param_8, long param_9,
    char* param_10, long param_11, long param_12, long param_13, long param_14,
    char** param_15, short param_16, short param_17, long param_18, long param_19,
    long param_20, long param_21, long param_22) {
    
    int result = TDialogPanel::setup(param_1->renderArea(), param_1,
        param_4, param_5, param_2, param_3, 1);
    if (result == 0) return 0;
    
    if (param_10 != 0 && *param_10 != 0) {
        result = create_text((TPanel*)this, &title, param_10,
            param_6, param_7, param_8, param_9, 4, 1, 1, 1);
        if (result == 0) return 0;
    }
    
    if (create_list((TPanel*)this, &list,
        param_11, param_12, param_13, param_14, 0xB) == 0)
        return 0;
    
    result = create_auto_scrollbar((TPanel**)&extra_scroll, list, 0x14);
    if (result == 0) return 0;
    
    if (param_15 != 0) {
        list->set_text(param_15, param_16);
    }
    
    list_id = (short)param_17;
    list->scroll_cur_line(1, param_17, 1);
    
    if (create_button((TPanel*)this, &ok_btn, 0xFA1, 0,
        param_18, param_20, param_21, param_22, 0, 0, 0) == 0)
        return 0;
    
    result = create_button((TPanel*)this, &cancel_btn, 0xFA2, 0,
        param_19, param_20, param_21, param_22, 0, 0, 0);
    if (result == 0) return 0;
    
    TButtonPanel* cancel = cancel_btn;
    cancel->field_298 = 0x1B;
    cancel->field_29C = 0;
    
    TPanel::set_curr_child(list);
    return 1;
}
