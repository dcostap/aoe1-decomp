// VA: 0045BA60 TMousePointer::draw(int)
// Attempt log:
// 1: natural source from packet/Poll sibling using corrected offsets and DDraw vtable calls; initial parity pass.
// 2: invert MouseOnScreen branch to keep draw body inline before save_area_valid=0 tail.
// 3: manual temp-ordered RECT stores changed prologue/register pressure badly; rolled back to aggregate copies.
// 4: declare InvalidateRect as const function pointer to emit original IAT ff15 call length; recovered exact branch distances through offset 0x11E.
// 5: stopped after near-parity pass: remaining 9.08% diff is localized to restore/save RECT copy scheduling and later shape_draw/DDraw argument register allocation; no inline asm/custom flags.
// 6: reordered aggregate copies; prologue lost EBP and shrank to 748 bytes (705-byte diff); restored.
// 7: used SDK windows.h/RECT context; emitted bytes and 69-byte baseline diff were unchanged.
// 8: direct named mouse_rect aggregate for restore_rect recovered the original +011D block and improved 69 -> 53 bytes; kept.
// 9: six natural aggregate-copy order variants produced no closer invariant candidate.
// 10: shape_info/facet declaration, width, direct-member, and typed clipper probes were duplicate or farther; seven shape-expression variants found no exact result.
// 11: matched the exact same-TU Poll shape_info pre-index and direct-facet expression; structural drift grew to 713 bytes, so rolled back.
// 12: corrected TShape::shape_draw to the exact Shape.cpp long/long/long/uchar ABI from Poll and the target packet.
// 13: promoted the real facet and Shape_Info locals to function scope, matching the period decompiler local surface; testing lifetime-driven register coloring.
// 14: replaced the single-use RECT alias in shape coordinates with direct named mouse_rect fields; testing the natural draw expression.
// 15: kept the indexed facet local but passed the canonical next_facet member directly as the shape_draw facet argument.
// 16: replaced the narrow TShape gap stub with the proven period data members before shape_info; testing canonical class context.
// 17: corrected TDrawArea::SetTrans's second parameter to the proven uchar ABI used by the exact Poll donor.
// 18: removed the facet temporary and used direct typed next_facet indexing/argument; emitted code was unchanged, so restored.
// 19: materialized typed draw_x/draw_y locals before shape_draw; emitted code was unchanged, so restored the clean call.
// left in scratch: 53-byte nonexact drift begins at 0045BC43 in shape_draw register/argument scheduling; calls, frame, size, CFG, and all 13 call sites match.

#include <windows.h>

typedef unsigned long ulong;
typedef unsigned char uchar;

typedef RECT RECT4;
struct Shape_Info {
    unsigned long Shape_Data_Offsets;
    unsigned long Shape_Outline_Offset;
    long Reserved1;
    long Reserved2;
    long Width;
    long Height;
    long Hotspot_X;
    long Hotspot_Y;
};

class IDirectDrawSurface;
class IDirectDrawClipper;

class TDrawArea {
public:
    char gap_00[0x3C];
    IDirectDrawSurface* DrawSurface;
    uchar* Lock(char* name, int flag);
    void Unlock(char* name);
    void SetTrans(int a, uchar b);
};

class TShape {
public:
    uchar* shape;
    int load_type;
    int load_size;
    void* shape_header;
    void* head;
    void* offsets;
    void* FShape;
    Shape_Info* shape_info;
    uchar shape_draw(TDrawArea* area, long x, long y, long facet, uchar a, uchar* b);
};

extern "C" ulong __cdecl debug_timeGetTime(char* file, int line);
#define STR_MOUSEPTR_CPP ((char*)0x00584BD0)
#define STR_MOUSEPTR_DRAW ((char*)0x00584C38)

#define VTBL(obj) (*(void***)(obj))
#define CALL_DD_BLT(surf, dst, src, srcR, flags, fx) ((long (__stdcall*)(void*, void*, void*, void*, unsigned long, void*))VTBL(surf)[5])((surf),(dst),(src),(srcR),(flags),(fx))
#define CALL_DD_CLIP(surf, out) ((long (__stdcall*)(void*, void*))VTBL(surf)[15])((surf),(out))
#define CALL_DD_SETCLIP(surf, clip) ((long (__stdcall*)(void*, void*))VTBL(surf)[28])((surf),(clip))
#define CALL_DD_BLTFAST(surf, x, y, src, srcR, flags) ((long (__stdcall*)(void*, long, long, void*, void*, unsigned long))VTBL(surf)[7])((surf),(x),(y),(src),(srcR),(flags))

class TMousePointer {
public:
    TDrawArea* custom_draw; TDrawArea* render_area; TDrawArea* save_area; TDrawArea* primary_area;
    int Num_Cursors; int Max_Cursors; TDrawArea* cursors[16]; TShape* Cursor_Shape; int Mouse_Mode; int Max_CX; int Max_CY;
    int cWidth; int cHeight; int gWidth; int gHeight; int mouse_x; int mouse_y; int save_x; int save_y;
    int facet; int game_facet; int next_facet; int last_facet; int d_top; int d_left; int d_bottom; int d_right;
    int g_top; int g_left; int g_bottom; int g_right; int save_area_valid;
    RECT4 save_rect; RECT4 mouse_rect; RECT4 cursor_rect; RECT4 new_save_rect; RECT4 restore_rect;
    char gap_10C[0x10];
    IDirectDrawSurface* restoreSurface;
    IDirectDrawSurface* renderSurface;
    IDirectDrawSurface* PrimarySurface; int active; int drawn; int Shutdown; int Setup; int GameMode; int GameEnabled;
    int MouseOnScreen; ulong LastDrawTime; long LastddError;
    int update_mouse_position();
    void draw(int forced);
};

void TMousePointer::draw(int forced)
{
    IDirectDrawClipper* lplpDDClipper;
    lplpDDClipper = 0;
    if (this->active != 0 && this->custom_draw != 0) {
        ulong t = debug_timeGetTime(STR_MOUSEPTR_CPP, 0x2e3);
        if (this->GameMode != 0 && this->GameEnabled != 0 && forced == 0) {
            if (t - this->LastDrawTime < 0x22) return;
        }
        if (this->update_mouse_position() != 0 || forced != 0) {
            this->LastDrawTime = t;
            if (this->save_area_valid != 0 && this->restoreSurface != this->PrimarySurface) {
                long err = CALL_DD_BLT(this->restoreSurface, &this->restore_rect, this->save_area->DrawSurface, &this->save_rect, 0x1000000, 0);
                if (err != 0) { this->LastddError = err; return; }
            }
            if (this->MouseOnScreen != 0) {
                RECT4* ptVar1 = &this->mouse_rect;
                long err = CALL_DD_BLT(this->save_area->DrawSurface, &this->new_save_rect, this->renderSurface, ptVar1, 0x1000000, 0);
                if (err != 0) { this->LastddError = err; return; }
                this->restoreSurface = this->renderSurface;
                this->restore_rect = this->mouse_rect;
                this->save_rect = this->new_save_rect;
                this->save_area_valid = 1;
                if (this->Mouse_Mode == 0) {
                    err = CALL_DD_CLIP(this->renderSurface, &lplpDDClipper);
                    if (err == (long)0x88760238) { err = 0; lplpDDClipper = 0; }
                    if (err != 0) { this->LastddError = err; return; }
                    if (lplpDDClipper != 0) {
                        err = CALL_DD_SETCLIP(this->renderSurface, 0);
                        if (err != 0) { this->LastddError = err; return; }
                    }
                }
                if (this->Mouse_Mode == 1) {
                    uchar* p = this->render_area->Lock(STR_MOUSEPTR_DRAW, 1);
                    if (p != 0) {
                        long f = this->next_facet;
                        Shape_Info* si = this->Cursor_Shape->shape_info;
                        this->Cursor_Shape->shape_draw(this->render_area, si[f].Hotspot_X + ptVar1->left, si[f].Hotspot_Y + this->mouse_rect.top, f, 0, 0);
                        this->render_area->Unlock(STR_MOUSEPTR_DRAW);
                    }
                }
                if (this->Mouse_Mode == 0) {
                    this->cursors[this->next_facet]->SetTrans(1, 0);
                    err = CALL_DD_BLTFAST(this->renderSurface, ptVar1->left, this->mouse_rect.top, this->cursors[this->next_facet]->DrawSurface, &this->cursor_rect, 0x11);
                    if (err != 0) { this->LastddError = err; return; }
                }
                this->last_facet = this->next_facet;
                if (this->Mouse_Mode == 0 && lplpDDClipper != 0) {
                    err = CALL_DD_SETCLIP(this->renderSurface, lplpDDClipper);
                    if (err != 0) { this->LastddError = err; return; }
                }
            } else {
                this->save_area_valid = 0;
            }
            if (this->GameMode == 0 || this->GameEnabled == 0) {
                InvalidateRect(*(void**)((char*)this->render_area + 4), &this->mouse_rect, 0);
            }
            this->drawn = 1;
        }
    }
}
