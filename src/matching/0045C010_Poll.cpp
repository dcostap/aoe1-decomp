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
// 11: made the MouseOnScreen success body the inline arm and left save_area_valid=0 in the late else arm; this restored the original far zero-save branch topology.
// 12: pre-indexed Shape_Info from the direct next_facet member (`shape_info + this->next_facet`) and passed next_facet directly; this recovered the original EDX facet/EAX scaled-index schedule and exact 747-byte body.
// 13: corrected the proven TShape::shape_draw long/long/long/uchar ABI and TDrawArea::SetTrans int/uchar ABI; bytes remained exact and decorated declarations now match the original symbols.
// 14: replaced opaque shape/custom-draw declarations with canonical field widths/ownership from exact Shape/TMousePointer donors; bytes remained exact.
// final: exact 747-byte match under default VC5 /O2 /Oy; no inline asm or custom flags.

#include "../../include/mouseptr_context.h"

extern "C" ulong __cdecl debug_timeGetTime(char* file, int line);
#define STR_MOUSEPTR_CPP ((char*)0x00584BD0)
#define STR_MOUSEPTR_POLL ((char*)0x00584C48)

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
                if (this->MouseOnScreen != 0) {
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
                            Shape_Info* si = this->Cursor_Shape->shape_info + this->next_facet;
                            this->Cursor_Shape->shape_draw(this->primary_area,
                                si->Hotspot_X + ptVar1->left,
                                this->mouse_rect.top + si->Hotspot_Y,
                                this->next_facet, 0, 0);
                            this->primary_area->Unlock(STR_MOUSEPTR_POLL);
                        }
                    }
                    this->last_facet = this->next_facet;
                } else {
                    this->save_area_valid = 0;
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
