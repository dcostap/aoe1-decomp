// VA: 0045BE20 TMousePointer::set_facet(int)
// Source: Mouseptr.cpp lines 918-939
// Size: 91 bytes, __thiscall
//
// Attempt log (7 probes):
// Probe 1-3: Struct-based approach, facet in eax instead of edx → 16 diff bytes
// Probe 4: Raw pointer arithmetic — same 16 bytes
// Probe 5: Local idx temp — same 16 bytes
// Probe 6: Proper struct inheritance — same 16 bytes
// Probe 7: Pre-load Cursor_Shape before bounds check — much worse (74 bytes)
//
// Remaining 16 bytes: register allocation — param_1 loaded into eax instead of edx.
// This propagates: eax=idx throughout, edx=Cursor_Shape, esi=shape_info (pushed early)
// vs original: edx=idx, eax=Cursor_Shape→shape_info (reused), esi=pushed late
// All field offsets, loop structure, and control flow are identical.
// Parked in scratch per Boss direction.

#include "../../include/mouseptr_context.h"

void TMousePointer::set_facet(int f) {
    if (f < 0 || f >= this->Num_Cursors)
        return;

    this->facet = f;
    Shape_Info* info = this->Cursor_Shape->shape_info + f;
    this->cWidth = info->Width;
    this->cHeight = info->Height;
    this->d_top = info->Hotspot_Y;
    this->d_left = info->Hotspot_X;
    this->d_right = this->cWidth - info->Hotspot_X;
    this->d_bottom = this->cHeight - info->Hotspot_Y;
}
