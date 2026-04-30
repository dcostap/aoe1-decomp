// 0047B970 TScrollBarPanel::draw_button_pic
// PDB: Pnl_scbr.cpp:805-836, 245 bytes
// void __thiscall draw_button_pic(int param_1, int param_2, tagRECT* param_3)
// ret 0Ch (3 params)
// FLAGS: default

#include <stdlib.h>

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TShape {
public:
    unsigned char shape_minmax(long* y_min, long* local_4, long* param_3_ref, long* y_max, int button_index);
    unsigned char shape_draw(void* draw_area, int x, int y, int button_val, int flag1, int flag2, void* null_param);
};

class TDrawArea {
public:
    void SetClipRect(tagRECT* rect);
};

class TScrollBarPanel {
public:
    char _gap_00[0x20];
    TDrawArea* draw_area;
    char _gap_24[0x1C];
    void* panel;
    char _gap_44[0xC4];
    TShape* button_pics;

    void draw_button_pic(int param_1, int param_2, tagRECT* param_3);
};

typedef unsigned long DWORD;

void TScrollBarPanel::draw_button_pic(int param_1, int param_2, tagRECT* param_3)
{
    long y_min;
    long local_4;
    long y_max;

    // Shadow params to influence register allocation
    int buttonIdx = param_1;
    tagRECT* rect = param_3;

    if (this->button_pics == 0) {
        (*(void (__fastcall**)(void*, int, tagRECT*))(*(DWORD**)this->panel + 0x3C / 4))
            (this->panel, 0, rect);
        return;
    }
    if (buttonIdx == -1) {
        (*(void (__fastcall**)(void*, int, tagRECT*))(*(DWORD**)this->panel + 0x3C / 4))
            (this->panel, 0, rect);
        return;
    }

    this->draw_area->SetClipRect(rect);

    this->button_pics->shape_minmax(&y_min, &local_4, (long*)&rect, &y_max, buttonIdx);

    long shape_w = rect->right - y_max + 1;
    long shape_h = y_min - local_4 + 1;

    short cx = (rect->right - rect->left + 1) / 2 - shape_w / 2 - (short)y_max + (short)rect->left;
    short cy = (rect->bottom - rect->top + 1) / 2 - shape_h / 2 - (short)local_4 + (short)rect->top;

    if (param_2 != 0) {
        cx++;
        cy--;
    }

    int button_val = (param_2 != 0) + buttonIdx;

    this->button_pics->shape_draw(
        this->draw_area, cx, cy, button_val, 0, 0, 0);
}
