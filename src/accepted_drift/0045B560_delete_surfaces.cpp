// VA: 0045B560 TMousePointer::delete_surfaces (105 B)
// PDB source: Mouseptr.cpp lines 494-520
// Attempt log:
// 1: Existing scratch already had correct behavior but register allocation mismatch: rebuilt this=EBX/i=EBP vs original this=EBP/i=EBX.
// 2: Declared i before self to bias register coloring; no change.
// 3: Used direct this access instead of self local; no change.
// 4: Tried register int i; no change.
// 5: Tried const self plus register i; no change.
// 6: Rewrote cursor cleanup as for-index over cursors[i] instead of pointer walk; VC5 still emitted identical best code.
// 7: Tried volatile i to perturb allocation; worsened to stack/local broad mismatch, rolled back.
// 8: Probed /O2 /Oy /Og-; produced EBP frame/wrong basin, removed flag.
// 9: Probed /O2 /Oy /Gr; no improvement, removed flag.
// 10: Probed /O2 /Oy /G6; slightly different but still worse than default, removed flag.
// ACCEPTED_DRIFT_APPROVED by Boss in top-20 retry mode: exact size, behavior-equivalent,
// and remaining drift is a benign EBX/EBP allocation swap plus corresponding one-byte
// alignment/branch-target shifts. Calls, stack cleanup, memory writes, loop bounds,
// predicates, and return behavior match.

#include "../../include/mouseptr_context.h"

void operator_delete(void* ptr);

void TMousePointer::delete_surfaces()
{
    TMousePointer* self = this;
    TDrawArea* t;
    int i;
    if (self->custom_draw != 0) {
        if ((t = self->save_area) != 0) {
            t->TDrawArea::~TDrawArea();
            operator_delete(t);
            self->save_area = 0;
        }
        for (i = 0; i < self->Max_Cursors; ++i) {
            if ((t = self->cursors[i]) != 0) {
                t->TDrawArea::~TDrawArea();
                operator_delete(t);
                self->cursors[i] = 0;
            }
        }
        self->Num_Cursors = 0;
        self->reset();
    }
}
