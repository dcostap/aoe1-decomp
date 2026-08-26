// rdlg_lst.cpp:331-353, 108 bytes
// attempt 1: 96 bytes, offsets wrong
// attempt 2: 96 bytes, offsets wrong
// attempt 3: 93.5%, vfunc call pattern wrong
// attempt 4: 72.2%, vfunc slot at +0xDC not +0x13C
// attempt 5: 96 bytes, too small with 52 vfuncs
// attempt 6: 70.4%, vfunc slot correct, register basin diff
// attempt 7 (SparkleSquirrel): struct+local+natural form, 60.2%, still saving sel_id
// attempt 8: remove named 'entries' local, 50.9%, still saving sel_id
// attempt 9: (i*16+i)*6 expression, same 50.9%
// attempt 10: use real rdlg_list_info type with natural member access

#ifndef RDLG_LST_TU_CONTEXT
#include "../rdlg_lst_module_context.h"
#endif

void RGE_Dialog_List::calc_list_line() {
    list_line = -1;
    short sel_id = get_cur_id();
    if (sel_id != -1) {
        for (short i = 0; i < list_size; i++) {
            if (list_info[i].id == sel_id) {
                list_line = i;
                break;
            }
        }
    }
    if (list_line == -1) {
        list_line = 0;
    }
}
