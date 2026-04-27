// VA: 004AB670 | TRIBE_Screen_Sed::set_unit(short) | scr_sed.cpp:2178-2183 | 102 bytes
//
// Attempt log:
// [1] First attempt. Issues: esi vs edi for param; push 0FFFFFFFFh vs push edi;
//     interleaved arg pushes.
// [2] Removed int idx temp. Same issues.
// [3] Reversed branch order, virtual base class. Different structure, still esi.
// [4] Virtual dtor on base. Same esi issue.
// [5] Reordered -1 path (call before store). Gets edi for global in non-trivial
//     path but still esi for param; stack imbalance in epilogue.
// [Lab] 8 variant shapes tested: order_swap, no_return, local_global, store_first,
//     int_param, etc. ALL produce esi for param register.
//
// ACCEPTED_DRIFT: VC5 consistently chooses ESI for the parameter register
// instead of EDI (as seen in the original). This cascading register choice
// changes: (a) the unconditional save register (esi vs edi), (b) arg push
// encoding (push 0FFFFFFFFh vs push edi in -1 path), (c) arg push ordering
// (interleaved with index computation vs after), and (d) global pointer
// access pattern (reloaded each time vs cached in callee-saved register).
// All behavior, call boundaries, store addresses, and return values are
// identical.

#include "../../include/game_types.h"
#include "../../include/game_globals.h"

class RGE_Base_Game {
public:
    char _gap_00[0x3FC];
    short master_obj_id;
};

struct ListInfo {
    char text[100];
    short id;
};

class TListPanel {
public:
    void scroll_cur_line(unsigned char mode, short line, int update_scrollbar);
};

class TScreenPanel {
public:
    char _gap_00[0x478];
};

class TRIBE_Screen_Sed : public TScreenPanel {
public:
    char _gap_478[0x63C - 0x478];
    TListPanel* unit_list;
    char _gap_640[0x04];
    ListInfo* unit_list_info;
    void set_unit(short unit);
};

void TRIBE_Screen_Sed::set_unit(short unit) {
    if (unit == -1) {
        rge_base_game->master_obj_id = unit;
        unit_list->scroll_cur_line(1, unit, 1);
        return;
    }

    rge_base_game->master_obj_id = unit_list_info[unit].id;
    unit_list->scroll_cur_line(1, unit, 1);
}
