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
// Remaining issues (112 bytes rebuilt vs 114 original):
// - Extra push edi/pop edi (saves user of edi for action param across calloc+loop)
// - calloc encodes call rel32 differently (resolved at link time)
// - Vtable call uses slot 1 instead of slot 7 (compiler vtable slot mismatch)

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
    ActionObj* pc = (ActionObj*)this->obj;
    if (pc->object_state <= 2) {
        ActionNode* node = (ActionNode*)calloc(1, 8);
        node->act = action;
        node->nxt = 0;

        if (this->list != 0) {
            ActionNode* cur = this->list;
            while (cur->nxt != 0) {
                cur = cur->nxt;
            }
            cur->nxt = node;
        } else {
            this->list = node;
        }

        action->vf7(1);
    } else if (action != 0) {
        action->vf0(1);
    }
}
