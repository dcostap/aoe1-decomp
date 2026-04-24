// TRIBE_Panel_Inven::draw
// Draws the inventory panel. Renders resource values from player->float_values
// at fixed column positions, with shadow text using back_color and
// foreground text using font_color.

#include <stdio.h>
#include <string.h>

extern "C" int __stdcall TextOutA(void* hdc, int x, int y, const char* str, int len);
extern "C" void* __stdcall SelectObject(void* hdc, void* obj);
extern "C" int __stdcall SetBkMode(void* hdc, int mode);
extern "C" int __stdcall SetTextColor(void* hdc, int color);

struct TDrawArea {
    char gap_00[0x18];
    long width;
    long height;
};

extern int TRIBE_Panel_Inven_vftable;

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
    virtual void vf28(int mode);
    virtual void vf2C(void);
    virtual void vf30(void);
    virtual void vf34(void* rect);
};

class TDrawArea;

extern void* __stdcall TDrawArea_GetDc(TDrawArea* area, const char* name);
extern void __stdcall TDrawArea_ReleaseDc(TDrawArea* area, const char* name);

class TRIBE_Player {
public:
    char gap_00[0x50];
    float float_values[4];
};

class TRIBE_Panel_Inven {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(int mode);
    virtual void vf24(void);
    virtual void vf28(int mode);
    virtual void vf2C(void);
    char gap_04[0xF4];
    TRIBE_Player* player;       // +0F8h
    short save_attr_num;        // +0FCh
    short gap_FE;
    short* save_attr;           // +100h
    int idle_time;              // +104h
    int idle_interval;          // +108h
    void* font;                 // +10Ch
    int font_color;             // +110h
    int back_color;             // +114h

    void draw();
};

void TRIBE_Panel_Inven::draw() {
    int pnl_x = *(int*)((char*)this + 0x0C);
    int pnl_y = *(int*)((char*)this + 0x10);
    TDrawArea* area = *(TDrawArea**)((char*)this + 0x20);
    int active = *(int*)((char*)this + 0x6C);
    int field_70 = *(int*)((char*)this + 0x70);
    void* hdc;
    void* old_font;
    int base_x1;
    int base_x2;
    int base_x3;
    int base_x4;
    int row_y;
    char str[20];

    if (area == 0 || field_70 == 0 || active == 0) {
        *(int*)((char*)this + 0x38) = 0;  // need_redraw = 0
        return;
    }

    TPanel* parent = *(TPanel**)((char*)this + 0x40);
    if (parent != 0) {
        parent->vf34((char*)this + 0x24);  // &clip_left
    }

    if (this->player == 0) {
        goto do_post_draw;
    }

    this->vf28(0);

    hdc = TDrawArea_GetDc(area, "tpnl_inv::draw");
    if (hdc == 0) {
        goto do_post_draw;
    }

    old_font = SelectObject(*(void**)((char*)area + 0x38), this->font);
    SetBkMode(*(void**)((char*)area + 0x38), 1);

    // Local helpers for readability using manual offset tracking
    base_x1 = pnl_x + 0x20;   // column 1
    base_x2 = pnl_x + 0x63;   // column 2
    base_x3 = pnl_x + 0xA6;   // column 3
    base_x4 = pnl_x + 0xE9;   // column 4
    row_y = pnl_y + 2;

    // Column 1: player->float_values[1]
    sprintf(str, "%ld", (int)this->player->float_values[1]);
    SetTextColor(*(void**)((char*)area + 0x38), this->back_color);
    TextOutA(*(void**)((char*)area + 0x38), base_x1, row_y + 1, str, strlen(str));
    SetTextColor(*(void**)((char*)area + 0x38), this->font_color);
    TextOutA(*(void**)((char*)area + 0x38), base_x1, row_y, str, strlen(str));

    // Column 2: player->float_values[0]
    sprintf(str, "%ld", (int)this->player->float_values[0]);
    SetTextColor(*(void**)((char*)area + 0x38), this->back_color);
    TextOutA(*(void**)((char*)area + 0x38), base_x2, row_y + 1, str, strlen(str));
    SetTextColor(*(void**)((char*)area + 0x38), this->font_color);
    TextOutA(*(void**)((char*)area + 0x38), base_x2, row_y, str, strlen(str));

    // Column 3: player->float_values[3]
    sprintf(str, "%ld", (int)this->player->float_values[3]);
    SetTextColor(*(void**)((char*)area + 0x38), this->back_color);
    TextOutA(*(void**)((char*)area + 0x38), base_x3, row_y + 1, str, strlen(str));
    SetTextColor(*(void**)((char*)area + 0x38), this->font_color);
    TextOutA(*(void**)((char*)area + 0x38), base_x3, row_y, str, strlen(str));

    // Column 4: player->float_values[2]
    sprintf(str, "%ld", (int)this->player->float_values[2]);
    SetTextColor(*(void**)((char*)area + 0x38), this->back_color);
    TextOutA(*(void**)((char*)area + 0x38), base_x4, row_y + 1, str, strlen(str));
    SetTextColor(*(void**)((char*)area + 0x38), this->font_color);
    TextOutA(*(void**)((char*)area + 0x38), base_x4, row_y, str, strlen(str));

    SelectObject(*(void**)((char*)area + 0x38), old_font);
    TDrawArea_ReleaseDc(area, "tpnl_inv::draw");

do_post_draw:
    this->vf2C();
}
