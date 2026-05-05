// VA: 00473930 TButtonPanel::hit_button(long param_1, long param_2)
// PDB source: Pnl_btn.cpp lines 1171-1182
// Default flags
//
// __thiscall: this in ecx, 2 stack params. ret 8 cleanup.

#include <stdlib.h>

// Virtual function table for vfBC at slot 47 (vtable+0xBC)
struct BtnVfTable {
    virtual void vf00() {}
    virtual void vf04() {}
    virtual void vf08() {}
    virtual void vf0C() {}
    virtual void vf10() {}
    virtual void vf14() {}
    virtual void vf18() {}
    virtual void vf1C() {}
    virtual void vf20() {}
    virtual void vf24() {}
    virtual void vf28() {}
    virtual void vf2C() {}
    virtual void vf30() {}
    virtual void vf34() {}
    virtual void vf38() {}
    virtual void vf3C() {}
    virtual void vf40() {}
    virtual void vf44() {}
    virtual void vf48() {}
    virtual void vf4C() {}
    virtual void vf50() {}
    virtual void vf54() {}
    virtual void vf58() {}
    virtual void vf5C() {}
    virtual void vf60() {}
    virtual void vf64() {}
    virtual void vf68() {}
    virtual void vf6C() {}
    virtual void vf70() {}
    virtual void vf74() {}
    virtual void vf78() {}
    virtual void vf7C() {}
    virtual void vf80() {}
    virtual void vf84() {}
    virtual void vf88() {}
    virtual void vf8C() {}
    virtual void vf90() {}
    virtual void vf94() {}
    virtual void vf98() {}
    virtual void vf9C() {}
    virtual void vfA0() {}
    virtual void vfA4() {}
    virtual void vfA8() {}
    virtual void vfAC() {}
    virtual void vfB0() {}
    virtual void vfB4() {}
    virtual void vfB8() {}
    virtual int vfBC(long param_1, long param_2) { return 0; }
};

// TShape - no body to avoid thunks
class TShape {
public:
    unsigned char shape_check(int x, int y, int index);
};

class TButtonPanel {
public:
    virtual ~TButtonPanel() {}
    char pad_04[8];                     // +0x04 to +0x0C
    int field_0C;                       // +0x0C
    int field_10;                       // +0x10
    char pad_14[0x14C - 0x14];          // +0x14 to +0x14C
    TShape* pic[9];                     // +0x14C
    short pic_index[12];                // +0x170
    int pic_x;                          // +0x188
    int pic_y;                          // +0x18C
    int all_hot;                        // +0x190
    char pad_194[0x1F6 - 0x194];
    short cur_state;                    // +0x1F6

    int hit_button(long param_1, long param_2);
};

int TButtonPanel::hit_button(long param_1, long param_2) {
    int hit = ((BtnVfTable*)this)->vfBC(param_1, param_2);
    if (hit == 0) {
        return 0;
    }
    if (this->all_hot != 0) {
        return 1;
    }
    if (this->pic[this->cur_state] != 0) {
        int idx = this->pic_index[this->cur_state];
        int y = (param_2 - this->pic_y) - this->field_10;
        int x = (param_1 - this->pic_x) - this->field_0C;
        return this->pic[this->cur_state]->shape_check(x, y, idx) ? 1 : 0;
    }
    return 1;
}
