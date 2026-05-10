// VA: 00404590 RGE_Action_List::add_action_at_end(RGE_Action*)
// PDB source: act_list.cpp lines 342-372
// Default flags
//
// __thiscall: this in ecx, action param on stack at [esp+4]. ret 4.
// calloc(1, 8) for node allocation.
//
// Fields: obj@+0x04, list@+0x08. Node: action@+0x00, next@+0x04.
// Virtual: vf00 at vtable+0x00, vf07 at vtable+0x1C.
//
// Attempt log update:
// - Original scratch was too small for configured 114-byte comparison (112-byte text).
// - Rewrote with explicit separate vf7 call/return sites to recover original-size code;
//   now compares 114 bytes but VC5 saves `this` in edi and uses esi for list traversal,
//   unlike original which starts with esi=this then reuses esi as next-node after the
//   list head has been loaded in edx. This shifts stack parameter offsets and broadens
//   the diff.
// - Tried branch order variants (`cur != 0`, `cur == 0`, explicit else) and explicit
//   duplicated tail calls; all stayed in the push-edi/edi=this basin.
// - Behavior/calls/stack cleanup are understood; remaining blocker is register/liveness
//   basin around preserving `this` across allocation/list insertion while also needing a
//   traversal pointer. Not accepted_drift: broad register/control-flow drift.
// - 2026-05-10 current Boss-assigned pass: tried natural no-else, self/register locals,
//   head-positive branch (kept below), goto/label loop forms, do/while loop forms,
//   explicit next decl, reversed loop predicates, no-cur-name traversal, and parameter
//   alias variants. Best kept source restores original prologue/early high-state path
//   (`push esi; mov esi,ecx`, unshifted param loads) but loop/tail still differ broadly:
//   VC5 initializes traversal as `esi=head; edx=next` and emits extra loop tests/tails,
//   while original keeps `edx=head`, loads `esi=[edx+4]`, and has separate duplicated
//   vf7 return sites. No accepted_drift due to broad control-flow/register drift.

#include <stdlib.h>

struct ActionObj {
    char pad[0x48];
    unsigned char object_state;
};

class ActionVTable {
public:
    virtual void vf0(int) {}
    virtual void vf1() {}
    virtual void vf2() {}
    virtual void vf3() {}
    virtual void vf4() {}
    virtual void vf5() {}
    virtual void vf6() {}
    virtual void vf7(int) {}
};

struct ActionNode {
    ActionVTable* act;     // +0x04 (reversed by compiler)
    ActionNode* nxt;       // +0x00
};

struct RGE_Action_List {
    void* vtable;
    void* obj;
    ActionNode* list;

    void add_action_at_end(ActionVTable* action);
};

void RGE_Action_List::add_action_at_end(ActionVTable* action) {
    if (((ActionObj*)this->obj)->object_state > 2) { if (action) action->vf0(1); return; }
    ActionNode* node=(ActionNode*)calloc(1,8); node->nxt=0; node->act=action;
    ActionNode* head=this->list;
    if (head != 0) {
        ActionNode* cur=head;
        for (;;) { ActionNode* next=cur->nxt; if (next == 0) { cur->nxt=node; action->vf7(1); return; } cur=next; if (cur == 0) break; }
        action->vf7(1); return;
    }
    this->list=node; action->vf7(1);
}
