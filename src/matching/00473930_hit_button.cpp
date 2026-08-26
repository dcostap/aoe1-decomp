// VA: 00473930 TButtonPanel::hit_button(long param_1, long param_2)
// PDB source: Pnl_btn.cpp lines 1171-1182
// Default flags
//
// __thiscall: this in ecx, 2 stack params. ret 8 cleanup.

#include <stdlib.h>

// TShape - no body to avoid thunks
#ifndef PNL_BTN_SHARED_CONTEXT
class TShape {
public:
    unsigned char shape_check(int x, int y, int index);
};
#endif /* PNL_BTN_SHARED_CONTEXT */

#ifndef PNL_BTN_SHARED_CONTEXT
class TButtonPanel {
public:
    virtual ~TButtonPanel() {}
    char pad_04[8];                     // +0x04 to +0x0C
    int pnl_x;                          // +0x0C
    int pnl_y;                          // +0x10
    char pad_14[0x14C - 0x14];          // +0x14 to +0x14C
    TShape* pic[9];                     // +0x14C
    short pic_index[12];                // +0x170
    int pic_x;                          // +0x188
    int pic_y;                          // +0x18C
    int all_hot;                        // +0x190
    char pad_194[0x1F6 - 0x194];
    short cur_state;                    // +0x1F6

    int is_inside(long, long);
    virtual int hit_button(long param_1, long param_2);
};
#endif /* PNL_BTN_SHARED_CONTEXT */

int TButtonPanel::hit_button(long param_1, long param_2) {
    int hit = this->is_inside(param_1, param_2);
    if (hit == 0) {
        return 0;
    }
    if (this->all_hot != 0) {
        return 1;
    }
    if (this->pic[this->cur_state] != 0) {
        int idx = this->pic_index[this->cur_state];
        int y = (param_2 - this->pic_y) - this->pnl_y;
        int x = (param_1 - this->pic_x) - this->pnl_x;
        return this->pic[this->cur_state]->shape_check(x, y, idx) ? 1 : 0;
    }
    return 1;
}
