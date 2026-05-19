// VA: 00404590 RGE_Action_List::add_action_at_end(RGE_Action*)
// Attempts summary: inherited 10+ variants hit EDI-preserved action basin.
// try 11 volatile parameter: no EDI but worse scheduling/length.
// try 12/13 volatile stack alias/assignment after calloc: EDI remained.
// try 14: stack reload post-calloc removed EDI; 40.35% positional, loop/call scheduling still off.
// try 15: explicit while(1) loop shortened to 112B, wrong.
// try 16: split vtable local before vf7 push; no codegen change from try 14.
// final default validation: exact first 114B compared but MISMATCH, 46 positional bytes / 40.35%, 52 edit bytes / 45.61%.
// GIVEUP: best no-EDI basin now has correct prologue/no saved EDI and same first branch size, but still uses EAX/EDX for action reloads instead of ECX, reshapes the list traversal (ECX next with extra tests instead of ESI next / EDX cur), and vtable-call scheduling differs. Structural enough that this is not an accepted_drift proposal.

#include <stdlib.h>
struct RGE_Action_Node { void* action; RGE_Action_Node* next; };
struct RGE_Action_Object { char pad[0x48]; unsigned char object_state; };
struct RGE_Action_List { void* vtable; RGE_Action_Object* obj; RGE_Action_Node* list; void add_action_at_end(void* action); };
void* calloc(int count, int size);

typedef void (__stdcall *ActionFn)(int);

void RGE_Action_List::add_action_at_end(void* action) {
    if (obj->object_state > 2) {
        if (action) {
            void** vt = *(void***)action;
            ((ActionFn)vt[0])(1);
        }
        return;
    }
    RGE_Action_Node* n = (RGE_Action_Node*)calloc(1, 8);
    n->next = 0;
    n->action = *(void* volatile *)&action;
    RGE_Action_Node* cur = list;
    if (cur != 0) {
        do {
            RGE_Action_Node* next = cur->next;
            if (next == 0) {
                cur->next = n;
                void* a = *(void* volatile *)&action;
                void** vt = *(void***)a;
                ((ActionFn)vt[7])(1);
                return;
            }
            cur = next;
        } while (cur != 0);
        void* a = *(void* volatile *)&action;
        void** vt = *(void***)a;
        ((ActionFn)vt[7])(1);
        return;
    }
    list = n;
    void* a = *(void* volatile *)&action;
    void** vt = *(void***)a;
    ((ActionFn)vt[7])(1);
}
