// 0045C010 TMousePointer::Poll
// Attempt log:
// 1: natural decompiler-based implementation with raw vtable COM-style surfaces and local RECT layout.
// 2: fixed TMousePointer active/PrimarySurface/LastDrawTime/LastddError offsets from asm; first mismatch moved past field loads to branch offsets.
// 3: changed time threshold from >0x21 to >=0x22; recovered original cmp 22/jb family.
// 4: moved restoreSurface to +0x11C and PrimarySurface to +0x124; restored blit source offsets.
// 5: tried natural RECT aggregate assignments; close copy family but body remains shifted.
// 6: kept direct vtable macros for DDraw calls; call offsets and stack cleanup match locally.
// 7: retained member calls for SetTrans/Lock/Unlock/shape_draw/GetDDBltError to get direct relocation calls.
// 8: remaining mismatch is localized/broad scheduling around MouseOnScreen branch and shape_draw address arithmetic; not accepted_drift.
// 9: no inline asm or custom flags tried.
// 10: left in scratch after natural source/offset pass; needs source-shape/field-layout refinement.

typedef unsigned long ulong;
typedef unsigned char uchar;

struct RECT4 { long left; long top; long right; long bottom; };
struct Shape_Info { int a0; int a4; int a8; int aC; int a10; int a14; int Hotspot_X; int Hotspot_Y; };

class TDrawArea {
public:
    char gap_00[0x3C];
    void* DrawSurface;
    uchar* Lock(char* name, int flag);
    void Unlock(char* name);
    void SetTrans(int a, int b);
};

class TShape {
public:
    char gap_00[0x1C];
    Shape_Info* shape_info;
    uchar shape_draw(TDrawArea* area, int x, int y, int facet, int a, uchar* b);
};

class IDirectDrawSurface;
extern "C" ulong __cdecl debug_timeGetTime(char* file, int line);
#define STR_MOUSEPTR_CPP ((char*)0x00584BD0)
#define STR_MOUSEPTR_POLL ((char*)0x00584C48)

class TMousePointer {
public:
    TDrawArea* custom_draw; TDrawArea* render_area; TDrawArea* save_area; TDrawArea* primary_area;
    char gap_10[8];
    TDrawArea* cursors[16]; TShape* Cursor_Shape; int Mouse_Mode; int Max_CX; int Max_CY;
    int cWidth; int cHeight; int gWidth; int gHeight; int mouse_x; int mouse_y; int save_x; int save_y;
    int facet; int game_facet; int next_facet; int last_facet; int d_top; int d_left; int d_bottom; int d_right;
    int g_top; int g_left; int g_bottom; int g_right; int save_area_valid;
    RECT4 save_rect; RECT4 mouse_rect; RECT4 cursor_rect; RECT4 new_save_rect; RECT4 restore_rect;
    char gap_10C[0x10];
    IDirectDrawSurface* restoreSurface;
    char gap_120[4];
    IDirectDrawSurface* PrimarySurface; int active; int drawn; int Shutdown; int Setup; int GameMode; int GameEnabled;
    int MouseOnScreen; ulong LastDrawTime; long LastddError;
    int update_mouse_position();
    int GetDDBltError(long err);
    void Poll();
};

#define VTBL(obj) (*(void***)(obj))
#define CALL_DD_CLIP(surf, out) ((long (__stdcall*)(void*, void*))VTBL(surf)[15])((surf),(out))
#define CALL_DD_SETCLIP(surf, clip) ((long (__stdcall*)(void*, void*))VTBL(surf)[28])((surf),(clip))
#define CALL_DD_BLT(surf, dst, src, srcR, flags, fx) ((long (__stdcall*)(void*, void*, void*, void*, unsigned long, void*))VTBL(surf)[5])((surf),(dst),(src),(srcR),(flags),(fx))
#define CALL_DD_BLTFAST(surf, x, y, src, srcR, flags) ((long (__stdcall*)(void*, long, long, void*, void*, unsigned long))VTBL(surf)[7])((surf),(x),(y),(src),(srcR),(flags))

void TMousePointer::Poll()
{
    void* lplpDDClipper;
    lplpDDClipper = 0;
    if (this->active != 0 && this->custom_draw != 0 && this->GameMode != 0 && this->GameEnabled != 0) {
        ulong t = debug_timeGetTime(STR_MOUSEPTR_CPP, 0x42e);
        if (t - this->LastDrawTime >= 0x22) {
            if (this->update_mouse_position() != 0) {
                this->LastDrawTime = t;
                if (this->Mouse_Mode == 0) {
                    long err = CALL_DD_CLIP(this->PrimarySurface, &lplpDDClipper);
                    if (err == (long)0x88760238) { err = 0; lplpDDClipper = 0; }
                    if (err != 0) { this->LastddError = err; return; }
                    if (lplpDDClipper != 0) {
                        err = CALL_DD_SETCLIP(this->PrimarySurface, 0);
                        if (err != 0) { this->LastddError = err; return; }
                    }
                }
                if (this->save_area_valid != 0) {
                    long err = CALL_DD_BLT(this->restoreSurface, &this->restore_rect, this->save_area->DrawSurface, &this->save_rect, 0x1000000, 0);
                    if (err != 0) { this->LastddError = err; return; }
                    if (this->restoreSurface != this->PrimarySurface) {
                        err = CALL_DD_BLT(this->PrimarySurface, &this->restore_rect, this->save_area->DrawSurface, &this->save_rect, 0x1000000, 0);
                        if (err != 0) { this->LastddError = err; return; }
                    }
                }
                if (this->MouseOnScreen == 0) {
                    this->save_area_valid = 0;
                } else {
                    RECT4* ptVar1 = &this->mouse_rect;
                    long err = CALL_DD_BLT(this->save_area->DrawSurface, &this->new_save_rect, this->PrimarySurface, ptVar1, 0x1000000, 0);
                    if (err != 0) { this->LastddError = err; this->LastddError = this->GetDDBltError(err); return; }
                    this->restoreSurface = this->PrimarySurface;
                    this->restore_rect = *ptVar1;
                    this->save_rect = this->new_save_rect;
                    this->save_area_valid = 1;
                    if (this->Mouse_Mode == 0) {
                        this->cursors[this->next_facet]->SetTrans(1, 0);
                        err = CALL_DD_BLTFAST(this->PrimarySurface, ptVar1->left, this->mouse_rect.top, this->cursors[this->next_facet]->DrawSurface, &this->cursor_rect, 0x11);
                        if (err != 0) { this->LastddError = err; return; }
                    }
                    if (this->Mouse_Mode == 1) {
                        uchar* p = this->primary_area->Lock(STR_MOUSEPTR_POLL, 1);
                        if (p != 0) {
                            int f = this->next_facet;
                            Shape_Info* si = this->Cursor_Shape->shape_info;
                            this->Cursor_Shape->shape_draw(this->primary_area, si[f].Hotspot_X + ptVar1->left, this->mouse_rect.top + si[f].Hotspot_Y, f, 0, 0);
                            this->primary_area->Unlock(STR_MOUSEPTR_POLL);
                        }
                    }
                    this->last_facet = this->next_facet;
                }
                if (this->Mouse_Mode == 0 && lplpDDClipper != 0) {
                    long err = CALL_DD_SETCLIP(this->PrimarySurface, lplpDDClipper);
                    if (err != 0) { this->LastddError = err; return; }
                }
                this->drawn = 1;
            }
        }
    }
}
