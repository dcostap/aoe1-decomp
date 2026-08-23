// VA: 0051C220 TRIBE_Panel_Object::draw_item (442B)
// PDB: tpnl_obj.cpp:820-867
//
// Attempt log:
// - canonical baseline: typed TPanel/TRIBE_Panel_Object fields, the real
//   TDrawArea/TShape surfaces, and the ordinary four-way ValueType formatter.
// - bonus arm: spelling the comparison as `value2 > value` preserves the
//   original value2-first load/compare order; exact match.

#include "../../include/game_globals.h"
#include <stdio.h>
#include <string.h>

extern "C" int __cdecl sprintf(char*, const char*, ...);

extern const char s_tpnl_obj_draw_item[];
extern const char s_fmt_d[];
extern const char s_fmt_d_plus_d[];
extern const char s_fmt_d_slash_d[];
extern const char s_fmt_d_percent[];

extern "C" {
__declspec(dllimport) int __stdcall SetBkMode(HDC, int);
__declspec(dllimport) COLORREF __stdcall SetTextColor(HDC, COLORREF);
__declspec(dllimport) HGDIOBJ __stdcall SelectObject(HDC, HGDIOBJ);
__declspec(dllimport) BOOL __stdcall TextOutA(HDC, int, int, LPCSTR, int);
}

class TDrawArea {
public:
    char gap_00[0x38];
    HDC DrawDc;

    unsigned char* Lock(char*, int);
    void Unlock(char*);
    void* GetDc(char*);
    void ReleaseDc(char*);
};

class TShape {
public:
    unsigned char shape_draw(TDrawArea*, long, long, long, unsigned char,
                             unsigned char*);
};

class TPanel {
public:
    virtual ~TPanel();

    char gap_04[8];
    long pnl_x;
    long pnl_y;
    char gap_14[0x0C];
    TDrawArea* render_area;
    char gap_24[0xD0];
};

class TRIBE_Panel_Object : public TPanel {
public:
    enum ValueType {
        ValueTypeNumber,
        ValueTypeBonus,
        ValueTypeCompare,
        ValueTypePercent
    };

    void* font;
    long font_wid;
    long font_hgt;
    TShape* health_pic;
    TShape* item_pic;
    TShape* unit_pics;
    TShape** bldg_pics;

protected:
    virtual void draw_item(int, int, ValueType, int, int);
};

void TRIBE_Panel_Object::draw_item(int index, int frame, ValueType type,
                                   int value, int value2)
{
    char val_str[20];

    if (this->item_pic != 0 && frame != -1) {
        if (this->render_area->Lock((char*)s_tpnl_obj_draw_item, 1) != 0) {
            this->item_pic->shape_draw(
                this->render_area,
                this->pnl_x + 0x36,
                this->pnl_y + index * 0x14 + 0x1E,
                frame, 0, 0);
            this->render_area->Unlock((char*)s_tpnl_obj_draw_item);
        }
    }

    switch (type) {
    case ValueTypeNumber:
        sprintf(val_str, s_fmt_d, value);
        break;
    case ValueTypeBonus:
        if (value2 > value)
            sprintf(val_str, s_fmt_d_plus_d, value, value2 - value);
        else
            sprintf(val_str, s_fmt_d, value);
        break;
    case ValueTypeCompare:
        sprintf(val_str, s_fmt_d_slash_d, value, value2);
        break;
    case ValueTypePercent:
        sprintf(val_str, s_fmt_d_percent, value);
        break;
    default:
        val_str[0] = 0;
        break;
    }

    if (val_str[0] != 0) {
        void* dc = this->render_area->GetDc((char*)s_tpnl_obj_draw_item);
        if (dc != 0) {
            SetBkMode(this->render_area->DrawDc, 1);
            SetTextColor(this->render_area->DrawDc, 0xFFFFFF);
            HGDIOBJ old_font = SelectObject(this->render_area->DrawDc,
                                             (HGDIOBJ)this->font);

            TextOutA(this->render_area->DrawDc,
                     this->pnl_x + 0x58,
                     this->pnl_y + index * 0x14 + 0x21,
                     val_str, strlen(val_str));

            SelectObject(this->render_area->DrawDc, old_font);
            this->render_area->ReleaseDc((char*)s_tpnl_obj_draw_item);
        }
    }
}
