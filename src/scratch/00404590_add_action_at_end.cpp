// VA: 00404590 RGE_Action_List::add_action_at_end(RGE_Action*)
// PDB: act_list.cpp lines 342-372 (114 bytes, 46 asm lines)
// Default flags. No inline asm/hacks.
//
// BLOCKER: Multi-axis register-allocation and control-flow differences prevent
// exact match. Not accepted_drift — diff is structural (90% positional, 75% edit)
// with different register saves, vtable call scheduling, loop structure, and
// branch displacements.
//
// Original register layout:
//   ESI = this (saved at entry, reused as loop traversal ptr)
//   ECX = action (reloaded from stack after calloc)
//   EDX = cur pointer (list traversal)
//   EAX = ephemeral (obj, node, vtable ptr)
//   No EDI save.
// Original loop: `do { next = cur->next; if (!next) append; cur = next; } while (cur);`
// with three duplicated vf7(1) tails.
//
// VC5's consistent basin (10+ variants):
//   ESI = this
//   EDI = action (preserved across calloc, forces push edi)
//   ECX/EDX = cur/next (loop traversal, swapped roles)
//   Extra push edi at offset 3 (shifts all param loads by 4 bytes on stack)
//   Loop: alternative form with extra test/je checks
//   vtable calls: loads vt[7] slot directly instead of indirect through vtable ptr
//   Only 2 vf7 tails instead of 3 (merged via shared fall-through path)

// Attempts (10+ focused variants):
// - Named void* parameter: EDI basin
// - int parameter + cast: same EDI basin
// - No intermediate nxt local: same
// - Earlier scratch tried EDI/ESI, goto/gcc-ext/register/volatile do/for/while
//   all converge to push-edi basins
//
// Retry 2026-05-18 (10 honest tries):
// - Revalidated baseline: exact-size 114 but broad mismatch 90.3509% positional / 74.5614% edit; extra push edi and EDI=action basin remain.
// - Tried typed RGE_Action with virtual vf0/vf7 to coax member-call shape; worsened register allocation to EDI=this and still push edi.
// - Tried explicit endless loop with next local and duplicated tail; still merged/reshaped loop and retained extra saved register.
// - Tried preserving action in a local after calloc and using that local for duplicated calls; still EDI basin.
// - Tried __stdcall-style vtable calls vs natural virtual calls; __stdcall baseline is less bad, but still loads slot directly and saves EDI.
// - Tried /Ob0 briefly; no change, flag removed.
// GIVEUP: exact source basin still blocked by combined constraints: original has no EDI save, reloads action from stack after calloc into ECX, traverses list with EDX/ESI, keeps three duplicated vf7 tails, and uses indirect vtable-pointer load scheduling. Current best is structural mismatch, not accepted_drift.

#include <stdlib.h>

struct RGE_Action_Node {
    void* action;
    RGE_Action_Node* next;
};

struct RGE_Action_Object {
    char pad[0x48];
    unsigned char object_state;
};

struct RGE_Action_List {
    void* vtable;
    RGE_Action_Object* obj;
    RGE_Action_Node* list;

    void add_action_at_end(void* action);
};

void* calloc(int count, int size);

void RGE_Action_List::add_action_at_end(void* action) {
    if (obj->object_state > 2) {
        if (action) {
            (*(void(__stdcall*)(int))(*(void***)action)[0])(1);
        }
        return;
    }

    RGE_Action_Node* n = (RGE_Action_Node*)calloc(1, 8);
    n->next = 0;
    n->action = action;

    RGE_Action_Node* cur = list;
    if (cur) {
        do {
            if (cur->next == 0) {
                cur->next = n;
                (*(void(__stdcall*)(int))(*(void***)action)[7])(1);
                return;
            }
            cur = cur->next;
        } while (cur);

        (*(void(__stdcall*)(int))(*(void***)action)[7])(1);
        return;
    }

    list = n;
    (*(void(__stdcall*)(int))(*(void***)action)[7])(1);
}
