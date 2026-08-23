// VA: 00480A20 RGE_Random_Map_Module::remove_module(RGE_Random_Map_Module*)
// PDB source: rmm_base.cpp lines 174-206 (90 bytes, 41 asm lines)
// PDB owner: protected ?remove_module@RGE_Random_Map_Module@@IAEEPAV1@@Z.
// Canonical owner context: src/rmm_base_tu.cpp with rmm_base_context.h.
// Default flags
//
// __thiscall: this in ecx, 1 stack param (RGE_Random_Map_Module*). ret 4 cleanup.
// Returns unsigned char (al). Removes first matching node from singly-linked list at this+8.
//
// Prior state: 77/90 edit-match bytes, 13-byte edit diff. Remaining differences were
// the head removal load using `eax` instead of just-copied `edx`, and an eax/ecx color
// swap through the list walk.
//
// 2026-05-10 focused pass on this VA only:
// - Revalidated baseline: same-size 90B function, exact prologue/branches/free/tails,
//   edit diff 13, first mismatch at head-removal `mov eax,[eax+4]` vs original
//   `mov eax,[edx+4]` immediately after `mov edx,eax`.
// - Try 1: changed head unlink to use `found->next`, explicit del local, casted found,
//   raw `*(Node**)((char*)found+4)`, and assigning `head = found`; VC5 still folded
//   the load back through eax. Volatile del spilled to stack and was much worse.
// - Try 2: changed loop to prev/curr natural form; same eax/ecx loop-color family.
// - Try 3: char*/int raw pprev, curr-first raw pprev, while/for/do loop shapes, and
//   curr-inside-loop forms all collapsed to the same pprev=ecx/curr=eax codegen.
// - Try 4: fuller RGE_Random_Map_Module layout with vtable/parent/list and later fields
//   did not affect register coloring.
// - Try 5: flag probes /Ob0, /Og, /Oa no effect; /Os and /O1 produced 72B wrong-size
//   code, so no per-function flag is kept.
// - Try 6: declaring `free` manually instead of including <stdlib.h> did not affect codegen.
// ACCEPTED_DRIFT: reviewed by Boss. Behavior and size are correct. Remaining drift
// is limited to register-color/address-source choices: (a) `mov eax,[eax+4]` vs
// original `mov eax,[edx+4]` immediately after `edx=eax`, and (b) an eax/ecx color
// swap through the list walk. The compared pointers, memory operations, branches,
// free call/cleanup, return values, and tail bytes are identical; no window/truncation issue.
//
// 2026-08-23 canonical-owner audit:
// - A fresh rmm_base_tu.cpp build preserved the 23 non-scratch owner sections
//   against the prior canonical audit object after relocation masking. This
//   protects the exact owner set, including clear_stack at 00480E50.
// - The fresh checker still proves the 00480A20-00480A79 boundary, one ordered
//   free call with ret-4 cleanup, and the protected PDB owner above.
// - Natural declaration, source-order, and pointer-shape variants did not move
//   the 13-byte register-map drift. The source stays accepted drift.

#include "../../include/rmm_base_context.h"
#include <stdlib.h>

unsigned char RGE_Random_Map_Module::remove_module(RGE_Random_Map_Module* param_1) {
    RGE_Random_Map_Module_List* head = this->list;
    RGE_Random_Map_Module_List* found = 0;

    if (head != 0) {
        if (head->module == param_1) {
            found = head;
            this->list = head->next;
        } else {
            RGE_Random_Map_Module_List* curr;
            RGE_Random_Map_Module_List** pprev = &head->next;
            curr = *pprev;
            if (curr != 0) {
                do {
                    if (curr->module == param_1) {
                        found = curr;
                        *pprev = curr->next;
                    }
                    pprev = &(*pprev)->next;
                    curr = *pprev;
                } while (curr != 0);
            }
        }
    }

    if (found != 0) {
        free(found);
        return 1;
    }
    return 0;
}
