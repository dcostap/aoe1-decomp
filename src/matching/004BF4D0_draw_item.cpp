// TRIBE_Scenario_Editor_Panel_Object::draw_item
// VA: 004BF4D0
// PDB: spnl_obj.cpp:333-382
//
// Attempt log:
// - draft 1: first pass — 72% diff, mostly register assignment and strlen/strlen difference
// - draft 2: manual strlen, earlier guard params, register pressure reduction
// - baseline: typed panel fields and natural switch/DC path; 488 bytes, 440-byte diff
// - ABI probe: period dllimport GDI surface, proven format-string addresses, and strlen
//   after font selection recovered the original 469 bytes exactly

#ifndef SPNL_OBJ_TU
#include "../../include/game_globals.h"
#include <stdio.h>
#include <string.h>

extern "C" {
__declspec(dllimport) int __stdcall SetBkMode(HDC hdc, int mode);
__declspec(dllimport) COLORREF __stdcall SetTextColor(HDC hdc, COLORREF color);
__declspec(dllimport) int __stdcall SelectClipRgn(HDC hdc, HRGN region);
__declspec(dllimport) HGDIOBJ __stdcall SelectObject(HDC hdc, HGDIOBJ object);
__declspec(dllimport) BOOL __stdcall TextOutA(HDC hdc, int x, int y,
                                               LPCSTR text, int len);
}

class TDrawArea;

class TShape {
public:
    char shape_draw(TDrawArea* draw_area, long x, long y, int frame,
                    int color_flag, unsigned char* color_table);
};

class TDrawArea {
public:
    char gap_00[0x38];
    HDC DrawDc;
    char* Lock(char* a, int b);
    void Unlock(char* a);
    void* GetDc(char* a);
    void ReleaseDc(char* a);
};

class TPanel {
public:
    virtual ~TPanel();
    char pad_04[8];
    long pnl_x;            // +0x0C
    long pnl_y;            // +0x10
    char pad_14[0x20 - 0x14];
    TDrawArea* render_area; // +0x20
    char pad_24[0x88 - 0x24];
    HRGN clip_region;      // +0x88
    char pad_8C[0xF4 - 0x8C];
};

class TRIBE_Panel_Object : public TPanel {
public:
    enum ValueType {
        ValueTypeNumber = 0,
        ValueTypeBonus = 1,
        ValueTypeCompare = 2,
        ValueTypePercent = 3,
        ValueTypeNone = 4
    };

    HGDIOBJ font;          // +0xF4
    char pad_F8[0x104 - 0xF8];
    TShape* item_pic;      // +0x104
};

class TRIBE_Scenario_Editor_Panel_Object : public TRIBE_Panel_Object {
public:
    virtual void draw_item(int param_1, int param_2, ValueType param_3,
                           int param_4, int param_5);
};

extern char format_decimal[];
extern char format_bonus[];
extern char format_ratio[];
extern char format_signed[];
#endif

void TRIBE_Scenario_Editor_Panel_Object::draw_item(
    int param_1, int param_2, ValueType param_3, int param_4, int param_5)
{
    char val_str[20];

    if (this->item_pic && param_2 != -1) {
#ifdef SPNL_OBJ_TU
        unsigned char* lock_result = this->render_area->Lock(0, 1);
#else
        char* lock_result = this->render_area->Lock(0, 1);
#endif
        if (lock_result) {
            this->item_pic->shape_draw(
                this->render_area,
                this->pnl_x + 0x3C,
                this->pnl_y + param_1 * 9 * 2 + 0x1E,
                param_2, 0, 0);

            this->render_area->Unlock(0);
        }
    }

    switch (param_3) {
    case 0:
        sprintf(val_str, format_decimal, param_4);
        break;
    case 1:
        if (param_5 > param_4)
            sprintf(val_str, format_bonus, param_4, param_5 - param_4);
        else
            sprintf(val_str, format_decimal, param_4);
        break;
    case 2:
        sprintf(val_str, format_ratio, param_4, param_5);
        break;
    case 3:
        sprintf(val_str, format_signed, param_4);
        break;
    default:
        val_str[0] = 0;
    }

    if (val_str[0]) {
        void* dc = this->render_area->GetDc(0);
        if (dc) {
            SetBkMode(this->render_area->DrawDc, 1);
            SetTextColor(this->render_area->DrawDc, 0xFFFFFF);
            SelectClipRgn(this->render_area->DrawDc, this->clip_region);
            HGDIOBJ old_obj = SelectObject(this->render_area->DrawDc, this->font);

            int len = strlen(val_str);

            TextOutA(this->render_area->DrawDc,
                      this->pnl_x + 0x64,
                      this->pnl_y + param_1 * 9 * 2 + 0x20,
                      val_str, len);

            SelectObject(this->render_area->DrawDc, old_obj);
            SelectClipRgn(this->render_area->DrawDc, 0);
            this->render_area->ReleaseDc(0);
        }
    }
}
