// TScrollBarPanel::scroll
// VA: 0047B420
// Pnl_scbr.cpp:596-643
// 159 bytes

#include "../../include/game_globals.h"

class TPanel {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(void);
    virtual void vf24(void);
    virtual void vf28(void);
    virtual void vf2C(void);
    virtual void vf30(void);
    virtual void vf34(void);
    virtual void vf38(void);
    virtual void vf3C(void);
    virtual void vf40(void);
    virtual void vf44(void);
    virtual void vf48(void);
    virtual void vf4C(void);
    virtual void vf50(void);
    virtual void vf54(void);
    virtual void vf58(void);
    virtual void vf5C(void);
    virtual void vf60(void);
    virtual void vf64(void);
    virtual void vf68(void);
    virtual void vf6C(void);
    virtual void vf70(void);
    virtual void vf74(void);
    virtual void vf78(void);
    virtual void vf7C(void);
    virtual void vf80(void);
    virtual void vf84(void);
    virtual void vf88(void);
    virtual void vf8C(void);
    virtual void vf90(void);
    virtual void vf94(void);
    virtual void vf98(void);
    virtual void vf9C(void);
    virtual void vfA0(void);
    virtual void vfA4(void);
    virtual void vfA8(void);
    virtual void vfAC(void);
    virtual void vfB0(void);
    virtual void scroll_notify(void* sender, int action, long param, int zero); // vt[0xB4/4] = vt[45]
};

class TScrollBarPanel {
public:
    char gap_00[0x40];
    TPanel* panel;                 // +0x40
    char gap_44[0xF4 - 0x44];
    TPanel* list_panel;            // +0xF4
    int list_len;                  // +0xF8
    int one_step;                  // +0xFC
    int page_step;                 // +0x100
    int list_num;                  // +0x104

    void scroll(int action, long param);
    void set_tab_pos(long param);
};

void TScrollBarPanel::scroll(int action, long param) {
    if (this->list_panel != 0) {
        this->list_panel->scroll_notify(this, action, param, 0);
        return;
    }

    long val = this->list_num;

    switch (action) {
    case 0:
        val -= this->one_step;
        break;
    case 1:
        val += this->one_step;
        break;
    case 2:
        val -= this->page_step;
        break;
    case 3:
        val += this->page_step;
        break;
    case 4:
        val = param;
        break;
    default:
        return;
    }

    if (val < 0) {
        val = 0;
    } else {
        int max = this->list_len - 1;
        if (val > max)
            val = max;
    }

    if (val != this->list_num) {
        set_tab_pos(val);
        if (this->panel != 0) {
            this->panel->scroll_notify(this, 4, val, 0);
        }
    }
}
