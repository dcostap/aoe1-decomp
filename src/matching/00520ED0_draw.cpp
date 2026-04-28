// 00520ED0 TRIBE_Panel_Text_Line::draw
// Source: tpnl_txl.cpp lines 53-79
//
// Attempt log:
// Probe 1: standard structure — VC5 saves all registers in prologue using `sub esp,8`,
//   original uses `push ecx`+`push esi` and saves edi/ebp/ebx later in draw path
// Probe 2: goto-based single return — still `sub esp,8` prologue, 89.7% diff
// Probe 3: deep codegen basin mismatch on register saving pattern and stack frame
// Probe 4: void return + extern function pointers (failed VC5 syntax)
// Probe 5: eliminated dc local; GetDc used only as condition guard
// Probe 6-8: various virtual call approaches
// Probe 7: used render_area->DrawDc inline instead of cached HDC local
// Probe 8: eliminated vtable named local — lost mov ecx,esi for thiscall
// Probe 9: restored vtable local + dc elimination → push ecx prologue match!
// Probe 10: got parent_panel into ecx via typed virtual method
// Probe 11: added real virtual decls for vf28/vf2c/get_clip_rect + missing
//   vf30 slot → 0.0000% MATCH

#include "..\..\include\game_globals.h"
#include <windows.h>
#include <string.h>

extern "C" {
__declspec(dllimport) HGDIOBJ __stdcall SelectObject(HDC, HGDIOBJ);
__declspec(dllimport) int __stdcall SetBkMode(HDC, int);
__declspec(dllimport) COLORREF __stdcall SetTextColor(HDC, COLORREF);
__declspec(dllimport) BOOL __stdcall TextOutA(HDC, int, int, LPCSTR, int);
}

extern const char s_tpnl_txl_draw[];

class TDrawArea {
public:
    char gap_00[0x38];
    HDC DrawDc;
    void* GetDc(const char* name);
    void ReleaseDc(const char* name);
};

class TPanel {
public:
    char gap_04[8];
    long pnl_x;
    long pnl_y;
    char gap_14[0x0C];
    TDrawArea* render_area;
    RECT clip_rect;
    char gap_34[0x0C];
    TPanel* parent_panel;
    char gap_44[0x28];
    int active;
    int visible;
    char gap_74[0x80];

    virtual ~TPanel();
    virtual void vf04();
    virtual void vf08();
    virtual long vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void set_redraw(int);
    virtual long handle_idle();
    virtual void vf28(int);
    virtual void vf2c();
    virtual void vf30();
    virtual void get_clip_rect(RECT*);
};

class TRIBE_Panel_Text_Line : public TPanel {
public:
    void* font;
    unsigned char text_type;
    char text[200];
    char pad[3];
    long id;

    virtual ~TRIBE_Panel_Text_Line();
    virtual void scalar_deleting_destructor(unsigned int);
    virtual void draw();
    virtual void set_info(unsigned char type, char* str, long new_id);
};

void TRIBE_Panel_Text_Line::draw()
{
    if (this->render_area == 0 || this->visible == 0 || this->active == 0)
        return;

    if (this->parent_panel != 0)
        this->parent_panel->get_clip_rect(&this->clip_rect);

    this->vf28(0);

    if (this->render_area->GetDc(s_tpnl_txl_draw)) {
        HGDIOBJ old_font = SelectObject(this->render_area->DrawDc, (HGDIOBJ)this->font);
        SetBkMode(this->render_area->DrawDc, 1);
        SetTextColor(this->render_area->DrawDc, 0);

        if (this->text[0] != 0) {
            TextOutA(this->render_area->DrawDc, this->pnl_x, this->pnl_y,
                     this->text, strlen(this->text));
        }

        SelectObject(this->render_area->DrawDc, old_font);
        this->render_area->ReleaseDc(s_tpnl_txl_draw);
    }

    this->vf2c();
}
