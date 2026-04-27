// TRIBE_Scenario_Editor_Panel_Object::draw_item
// VA: 004BF4D0
// PDB: spnl_obj.cpp:333-382
//
// Attempt log:
// - draft 1: first pass — 72% diff, mostly register assignment and strlen/strlen difference
// - draft 2: manual strlen, earlier guard params, register pressure reduction

#include "../../include/game_globals.h"
#include <stdio.h>

// IAT-resolved GDI32 function pointers
typedef int (__stdcall *GDI_SetBkMode)(int, int);
typedef int (__stdcall *GDI_SetTextColor)(int, int);
typedef int (__stdcall *GDI_SelectClipRgn)(int, int);
typedef int (__stdcall *GDI_SelectObject)(int, int);
typedef int (__stdcall *GDI_TextOutA)(int, int, int, char*, int);

extern GDI_SetBkMode _SetBkMode;
extern GDI_SetTextColor _SetTextColor;
extern GDI_SelectClipRgn _SelectClipRgn;
extern GDI_SelectObject _SelectObject;
extern GDI_TextOutA _TextOutA;

// Format strings
extern char _fmt_d[];
extern char _fmt_d_plus_d[];
extern char _fmt_d_slash_d[];
extern char _fmt_d_percent[];

class TShape {
public:
    char shape_draw(void* draw_area, void* src_rect, void* dst_rect, int param, int zero1, int zero2);
};

class TDrawArea {
public:
    char* Lock(char* a, int b);
    void Unlock(char* a);
    void* GetDc(char* a);
    void ReleaseDc(char* a);
};

class TRIBE_Scenario_Editor_Panel_Object {
public:
    virtual void d0();
    virtual void draw_item(int param_1, int param_2, int param_3, int param_4, int param_5);

    char pad_04[8];
    void* base_info;       // +0x0C
    void* str_pos_info;    // +0x10
    char pad_14[0x20 - 0x14];
    void* draw_area;       // +0x20 (TDrawArea*)
    char pad_24[0x88 - 0x24];
    int clip_region;       // +0x88 (HRGN)
    char pad_8C[0xF4 - 0x8C];
    int font_handle;       // +0xF4 (HFONT)
    char pad_F8[0x104 - 0xF8];
    void* shape_ptr;       // +0x104 (TShape*)
};

void TRIBE_Scenario_Editor_Panel_Object::draw_item(
    int param_1, int param_2, int param_3, int param_4, int param_5)
{
    char val_str[20];

    if (this->shape_ptr && param_2 != -1) {
        char* lock_result = ((TDrawArea*)this->draw_area)->Lock(0, 1);
        if (lock_result) {
            ((TShape*)this->shape_ptr)->shape_draw(
                this->draw_area,
                (char*)this->base_info + 0x3C,
                (char*)this->str_pos_info + param_1 * 9 * 2 + 0x1E,
                param_2, 0, 0);

            ((TDrawArea*)this->draw_area)->Unlock(0);
        }
    }

    switch (param_3) {
    case 0:
        sprintf(val_str, _fmt_d, param_4);
        break;
    case 1:
        if (param_5 > param_4)
            sprintf(val_str, _fmt_d_plus_d, param_4, param_5 - param_4);
        else
            sprintf(val_str, _fmt_d, param_4);
        break;
    case 2:
        sprintf(val_str, _fmt_d_slash_d, param_4, param_5);
        break;
    case 3:
        sprintf(val_str, _fmt_d_percent, param_4);
        break;
    default:
        val_str[0] = 0;
    }

    if (val_str[0]) {
        void* dc = ((TDrawArea*)this->draw_area)->GetDc(0);
        if (dc) {
            int len = 0;
            while (val_str[len]) len++;

            _SetBkMode(*(int*)((char*)this->draw_area + 0x38), 1);
            _SetTextColor(*(int*)((char*)this->draw_area + 0x38), 0xFFFFFF);
            _SelectClipRgn(*(int*)((char*)this->draw_area + 0x38), this->clip_region);
            int old_obj = _SelectObject(*(int*)((char*)this->draw_area + 0x38), this->font_handle);

            _TextOutA(*(int*)((char*)this->draw_area + 0x38),
                      (int)((char*)this->base_info + 0x64),
                      (int)((char*)this->str_pos_info + param_1 * 9 * 2 + 0x20),
                      val_str, len);

            _SelectObject(*(int*)((char*)this->draw_area + 0x38), old_obj);
            _SelectClipRgn(*(int*)((char*)this->draw_area + 0x38), 0);
            ((TDrawArea*)this->draw_area)->ReleaseDc(0);
        }
    }
}
