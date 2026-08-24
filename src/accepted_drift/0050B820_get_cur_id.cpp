// VA: 0050B820 get_cur_id (27B, tdlg_lst.cpp)
// ACCEPTED_DRIFT: benign control-flow pattern difference
// Original uses sub/dec/dec/je chain (switch optimization), rebuilt uses
// early-return jne pattern or range comparison. All behaviorally identical.
// The complete tdlg_lst.cpp wrapper supplies the canonical shared class surface.

#include "../../include/tdlg_lst_context.h"

short TRIBE_Dialog_List::get_cur_id() {
    int v = this->list_type - 100;
    if (v == 0) goto ret_minus_1;
    if (--v == 0) goto ret_minus_1;
    if (--v == 0) goto ret_minus_1;
    return RGE_Dialog_List::get_cur_id();
ret_minus_1:
    return -1;
}
