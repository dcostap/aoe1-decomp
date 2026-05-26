// VA: 00404590 RGE_Action_List::add_action_at_end(RGE_Action*)
// Attempts summary: inherited 10+ variants hit EDI-preserved action basin.
// try 11 volatile parameter: no EDI but worse scheduling/length.
// try 12/13 volatile stack alias/assignment after calloc: EDI remained.
// try 14: stack reload post-calloc removed EDI; 40.35% positional, loop/call scheduling still off.
// try 15: explicit while(1) loop shortened to 112B, wrong.
// try 16: split vtable local before vf7 push; no codegen change from try 14.
// try 17: natural typed virtual RGE_Action surface shortened to 112B and kept wrong loop/vcall scheduling.
// try 18: virtual dtor/first_in_stack declaration did not improve over typed virtual basin.
// try 19: volatile parameter forced ECX reload for calls but lengthened high branch and worsened diff (71.9%).
// try 20: local alias for high branch still emitted extra parameter reload and 112B body.
// try 21: raw vtable/stdcall nonvolatile simple list shape preserved EDI for action and worsened to 89.47%; rolled back to best no-EDI stack-reload basin.
// final validation: exact size 114B but MISMATCH, 46 positional bytes / 40.35%.
// GIVEUP: best no-EDI basin has correct prologue/no saved EDI and same first branch size, but still uses EAX/EDX for action reloads instead of ECX, reshapes the list traversal (ECX next with extra tests instead of ESI next / EDX cur), and vtable-call scheduling differs. Structural enough that this is not an accepted_drift proposal.
// Retry 2026-05-19 Boss pass: 10 additional variants (natural nonvolatile param, while/goto/for loop shapes, helper-call split, pointer-to-pointer scan, low-branch volatile reload only, calloc sizeof, inverted condition, typed virtual RGE_Action). None improved the saved no-EDI stack-reload basin; most were 112B/96B short or 85%+ positional, best remains 40.35% positional.
// Retry 2026-05-20 Boss pass: revalidated baseline (114B, 40.35% positional, first mismatch 13). Tried natural typed virtual source, typed virtual with preserved action local, raw nonvolatile action local + while, explicit weird while(1) traversal, shared goto call tail, register parameter, four declaration-order permutations for action/node/cur, self-assignment to parameter, and volatile-store-only/nonvolatile-call split. Natural typed virtuals compiled to 112B short; nonvolatile/register/declaration-order families fell back to saved-EDI/action-preserved basin (~89.47% positional); volatile-store-only kept no-EDI but worsened to 41.23% and wrong tail scheduling. No improvement over saved baseline.
// Retry 2026-05-21 Boss pass: 18 more probes. Revalidated baseline. Tried direct-param while/do/goto/ptr-to-ptr/param self-assign/volatile-param/register-param plus flags /Ob0, /Oa, /Og-, /Gd, /O1, /Od (no match; /Ob0 no change, /Oa and no global opts worse). Typed virtual RGE_Action plus volatile stack-reload improved the high-state branch and moved first mismatch to offset 19 (34.21% positional). Best new source uses typed virtual RGE_Action, volatile stack store for node->action, and for/condition next scan; it matches through offset 61 and improves positional diff to 30.70%, but loop body/call-tail topology remains wrong (ECX next and shared/shortened tail instead of original ESI next, redundant EDX test, and three physical call/return tails). Tried register/outer next declarations and goto-loop variants; no improvement.
// GIVEUP 2026-05-21: left in scratch with best positional baseline (30.70%). Not accepted_drift: remaining differences are control-flow/call-tail structure, not localized benign drift.
// Retry 2026-05-24 Boss pass: revalidated current best (matches through offset 61; 30.70% positional). Tried 18 focused variants around the remaining loop/call-tail: do/decompiler loop (34.21%, first mismatch 19), while(1) top-next declaration (bad/failed shape), do+extra test/goto (44.74%), outer next declarations / while-condition / nested-if (no change from baseline), shared raw call-tail (29.82% positional but first mismatch regressed to 19 and broad call-tail drift), three duplicated goto labels (35.96%), replacing volatile func7 reloads with normal action calls (no change), volatile/register/outer-declared next (no change or 92%+ bad), volatile cur/list loads (no improvement), action local after/before calloc (112B too short). No variant produced original ESI-next/EDX-cur traversal with ECX action preserved and three physical call/return tails. Kept previous source because it preserves the longest exact prefix; still not accepted_drift due structural loop/call-tail mismatch.
// Retry 2026-05-26 Boss pass: revalidated best (114B, 35 positional, first mismatch 61). Tried 10 more loop/call-tail variants: do/while with unreachable post-loop call (39 diff, first mismatch 19), explicit ESI-named next (no change), infinite-loop redundant cur test (bad/compile-shape failure), nonvolatile action store/calls (106 diff), common post-if vcall (41 diff), member-function-pointer raw vtable slot (no change), goto-duplicated call labels (no change), do+goto set_next (39 diff), condition-inside while (no change), and no-return after store/else (no change). GIVEUP remains: best source keeps longest exact prefix, but remaining drift is broad loop topology/vcall-tail structure, not localized benign accepted_drift.

#include <stdlib.h>

struct RGE_Action_Node;

class RGE_Action {
public:
    virtual void func0(int);
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void func7(int);
};

struct RGE_Action_Node {
    RGE_Action* action;
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
    void add_action_at_end(RGE_Action* action);
};

void* calloc(int count, int size);

void RGE_Action_List::add_action_at_end(RGE_Action* action) {
    if (obj->object_state > 2) {
        if (action) {
            action->func0(1);
        }
        return;
    }

    RGE_Action_Node* n = (RGE_Action_Node*)calloc(1, 8);
    n->next = 0;
    n->action = *(RGE_Action* volatile*)&action;

    RGE_Action_Node* cur = list;
    if (cur) {
        for (RGE_Action_Node* next = cur->next; next != 0; next = cur->next) {
            cur = next;
        }
        cur->next = n;
        (*(RGE_Action* volatile*)&action)->func7(1);
        return;
    }

    list = n;
    (*(RGE_Action* volatile*)&action)->func7(1);
}
