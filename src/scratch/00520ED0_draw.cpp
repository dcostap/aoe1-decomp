// 00520ED0 TRIBE_Panel_Text_Line::draw
// Source: tpnl_txl.cpp lines 53-79
//
// Attempt log:
// Probe 1: standard structure — VC5 saves all registers in prologue using `sub esp,8`,
//   original uses `push ecx`+`push esi` and saves edi/ebp/ebx later in draw path
// Probe 2: goto-based single return — still `sub esp,8` prologue, 89.7% diff
// Probe 3: deep codegen basin mismatch on register saving pattern and stack frame
//   Remaining gap: VC5 defaults to `sub esp,N` + upfront register saves (ebx,ebp,esi,edi).
//   Original uses `push ecx; push esi` at entry, saves edi/ebp/ebx inside draw path.
//   Left in scratch; suitable for source restructuring or variant_lab later.

#include "..\..\include\game_globals.h"
#include <windows.h>
#include <string.h>

extern "C" __declspec(dllimport) int __stdcall SelectClipRgn(HDC, HRGN);
extern "C" __declspec(dllimport) HGDIOBJ __stdcall SelectObject(HDC, HGDIOBJ);
extern "C" __declspec(dllimport) int __stdcall SetBkMode(HDC, int);
extern "C" __declspec(dllimport) COLORREF __stdcall SetTextColor(HDC, COLORREF);
extern "C" __declspec(dllimport) BOOL __stdcall TextOutA(HDC, int, int, LPCSTR, int);

class TDrawArea {
public:
    char _gap_00[0x38];
    HDC DrawDc;
    void* GetDc(const char* name);
    void ReleaseDc(const char* name);
};

class TPanel {
public:
    char _gap_04[8];
    long pnl_x;
    long pnl_y;
    char _gap_14[0x0C];
    TDrawArea* render_area;
    RECT clip_rect;
    char _gap_34[0x0C];
    TPanel* parent_panel;
    char _gap_44[0x28];
    int active;
    int visible;
    char _gap_74[0x80];

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
};

class TRIBE_Panel_Text_Line : public TPanel {
public:
    void* font;
    unsigned char text_type;
    char text[200];
    char _pad[3];
    long id;

    virtual ~TRIBE_Panel_Text_Line();
    virtual void* scalar_deleting_destructor(unsigned int);
    virtual long draw();
    virtual void set_info(unsigned char type, char* str, long new_id);
};

long TRIBE_Panel_Text_Line::draw()
{
    if (this->render_area == 0 || this->visible == 0 || this->active == 0)
        goto end;

    {
        if (this->parent_panel != 0) {
            void* pv = *(void**)this->parent_panel;
            ((void (__stdcall *)(RECT*))((void**)pv)[0x34/4])(&this->clip_rect);
        }

        void* vtable = *(void**)this;
        ((void (__stdcall *)(int))((void**)vtable)[0x28/4])(0);

        HDC dc = (HDC)this->render_area->GetDc("tpnl_txl::draw");

        if (dc != 0) {
            HGDIOBJ old_font = SelectObject(dc, (HGDIOBJ)this->font);
            SetBkMode(dc, 1);
            SetTextColor(dc, 0);

            if (this->text[0] != 0) {
                TextOutA(dc, this->pnl_x, this->pnl_y, this->text, strlen(this->text));
            }

            SelectObject(dc, old_font);
            this->render_area->ReleaseDc("tpnl_txl::draw");
        }

        ((void (__stdcall *)())((void**)vtable)[0x2C/4])();
    }

end:
    return 0;
}
