// TRIBE_Panel_Inven::draw
// Draws the inventory panel. Renders resource values from player->float_values
// at fixed column positions, with shadow text using back_color and
// foreground text using font_color.
// changed TDrawArea to natural member-call surface; compiles but still short vs original
// reduced early locals/direct checks; got closer size but prolog still uses ebx=this instead of original esi=this

#include <stdio.h>
#include <string.h>

extern "C" int __stdcall TextOutA(void* hdc, int x, int y, const char* str, int len);
extern "C" void* __stdcall SelectObject(void* hdc, void* obj);
extern "C" int __stdcall SetBkMode(void* hdc, int mode);
extern "C" int __stdcall SetTextColor(void* hdc, int color);

class TDrawArea {
public:
    char gap_00[0x38];
    void* hdc;
    void* GetDc(const char* name);
    void ReleaseDc(const char* name);
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
    TDrawArea* area;
    void* old_font;
    int x;
    int row_y;
    char str[20];

    if (*(TDrawArea**)((char*)this + 0x20) == 0 || *(int*)((char*)this + 0x70) == 0 || *(int*)((char*)this + 0x6C) == 0) {
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

    area = *(TDrawArea**)((char*)this + 0x20);
    if (area->GetDc("tpnl_inv::draw") == 0) {
        goto do_post_draw;
    }

    old_font = SelectObject(area->hdc, this->font);
    SetBkMode(area->hdc, 1);

    x = *(int*)((char*)this + 0x0C) + 0x20;
    row_y = *(int*)((char*)this + 0x10) + 2;

    // Column 1: player->float_values[1]
    sprintf(str, "%ld", (int)this->player->float_values[1]);
    SetTextColor(area->hdc, this->back_color);
    TextOutA(area->hdc, x, row_y + 1, str, strlen(str));
    SetTextColor(area->hdc, this->font_color);
    TextOutA(area->hdc, x, row_y, str, strlen(str));

    // Column 2: player->float_values[0]
    sprintf(str, "%ld", (int)this->player->float_values[0]);
    SetTextColor(area->hdc, this->back_color);
    x = *(int*)((char*)this + 0x0C) + 0x63;
    TextOutA(area->hdc, x, row_y + 1, str, strlen(str));
    SetTextColor(area->hdc, this->font_color);
    TextOutA(area->hdc, x, row_y, str, strlen(str));

    // Column 3: player->float_values[3]
    sprintf(str, "%ld", (int)this->player->float_values[3]);
    SetTextColor(area->hdc, this->back_color);
    x = *(int*)((char*)this + 0x0C) + 0xA6;
    TextOutA(area->hdc, x, row_y + 1, str, strlen(str));
    SetTextColor(area->hdc, this->font_color);
    TextOutA(area->hdc, x, row_y, str, strlen(str));

    // Column 4: player->float_values[2]
    sprintf(str, "%ld", (int)this->player->float_values[2]);
    SetTextColor(area->hdc, this->back_color);
    x = *(int*)((char*)this + 0x0C) + 0xE9;
    TextOutA(area->hdc, x, row_y + 1, str, strlen(str));
    SetTextColor(area->hdc, this->font_color);
    TextOutA(area->hdc, x, row_y, str, strlen(str));

    SelectObject(area->hdc, old_font);
    area->ReleaseDc("tpnl_inv::draw");

do_post_draw:
    this->vf2C();
}
