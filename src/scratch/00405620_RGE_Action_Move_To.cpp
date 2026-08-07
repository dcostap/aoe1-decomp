// VA: 00405620 RGE_Action_Move_To::RGE_Action_Move_To
// act_move.cpp
// Retry 2026-05-26: modeled base as non-virtual destructible RGE_Action to get VC5 /GX EH frame without layout shift.
// Best result: exact size 186B, setup/base call/vptr/target/range/FPU code all match; remaining diff is late sprite fallback block layout.
// Tried 10 variants: old extern set_target surface, virtual/nonvirtual base dtor, novtable/manual vptr, this->obj reload vs saved obj,
// if(s)/else, if(!s)/else, temp-final assignment, volatile temp, two independent ifs, and goto-shaped fallback. Best is current.
// Left in scratch: MISMATCH 24 positional / 17 edit bytes at +137. Drift is localized to the final `if (spr==0)` fallback:
// original uses `jne shared_epilogue`, then inner `if(s) sprite=s; else sprite=o->sprite18;` with a shared epilogue; rebuilt emits
// equivalent fallback values but arranges the inner/outer branches differently around the EH epilogue. Not proposing accepted_drift yet
// unless reviewer accepts this localized equivalent tail-layout drift.
// 2026-05-31 retry: explicit goto-shaped fallback and inverted `if (s != 0)` worsened (outer branch jumps past the original-sized body;
// two-independent-if version adds extra tests). A final-sprite temp lowered edit diff to 13 but used a common `mov [esi+38],eax`
// store instead of the original two branch-local stores, so kept the better positional baseline.
// FLAGS: config/flags/00405620_RGE_Action_Move_To.rsp (/GX) is required for the original EH-framed constructor basin.
// 2026-08-02 Luna405620 session: fresh checker baseline is structurally 205B vs original 186B (47 positional bytes;
// entry-reachable duplicated EH epilogue past the original boundary). Inner/outer goto forms and destructor ABI/context
// variants did not change the 47B basin; an inner ternary reached 186B/31B but changed the binary's branch-local stores.
// A six-case variant lab found no invariant-eligible lead (the overloaded constructor was not selected by lab extraction).
// Final clean source restored: natural named-object + inner if/else remains the best period-plausible reconstruction.
// Paused after 10 meaningful hypotheses; remaining gap is the VC5 EH tail layout at the final sprite fallback.
// Main-agent source audit replaced the two binary-proven raw sprite offsets with
// named `sprite18`/`spriteBC` fields; emitted code and the EH-tail blocker were unchanged.
// 2026-08-02 Luna405620b sequential pass: named independent inner tests improved the tail to 188B/34B but added redundant tests;
// direct-member and reversed-test forms remained nonexact. Named ternary reached 186B/31B but merged the two branch stores.
// Outer-label/goto and natural virtual-vptr context probes did not improve the EH-tail basin (natural vptr worsened to 205B/56B).
// Restored the canonical named sprite18/spriteBC ownership and natural inner if/else; remaining blocker is shared-vs-duplicated EH epilogue layout.
// 2026-08-07 orch-w12 pass (13 probes): re-confirmed the 47B blocker. Negative evidence: inner `goto done`
// and ternary-STATEMENT forms fold to the same tail-dup; switch((int)s) case0/default is worse (85.7% shape);
// full virtual RGE_Action surface from exact donor 00407A20 leaves the tail unchanged; May-2026 raw-cast source
// still yields 47B (the old 24B was a pre-boundary-enforcement artifact); #include <stdlib.h> changes nothing;
// adding sibling ctor/dtor definitions to the TU broke checker extraction. Two focused variant labs (48 combos of
// outer-guard x inner-statement x flags): ONLY the two-independent-ifs family shares the epilogue (188B/34B,
// redundant second test + swapped o/s register coloring) and the ternary family shares with exact size (186B/31B,
// but merges the two branch-local stores). Both are metric experiments, not period source. Direct verification of
// the original binary tail bytes (jmp eb03 over the 3-byte else arm into the single FS-first EH epilogue) matches
// the packet. Sibling originals show the layout decision is per-function VC5: 004055A0 (no-EH, same fallback)
// tail-dups, 00401550 (EH, per-arm returns) tail-dups, 0044D1A0 (EH, long arms with calls) shares. The natural
// if/else reconstruction remains the best period-plausible source; the shared-epilogue layout is not reproducible
// with local source/type/flag/context changes in this VC5 basin.

class RGE_Action_Object;
class RGE_Sprite;
class RGE_Static_Object;
class RGE_Task;
class RGE_Action_List;

class RGE_Static_Object {
public:
    char gap_00[0x18];
    RGE_Sprite* sprite18;
    char gap_1C[0x1C];
    float world_x;
    float world_y;
    float world_z;
    char gap_44[0x78];
    RGE_Sprite* spriteBC;
};

class RGE_Action_Object {
public:
    char gap_00[8];
    RGE_Static_Object* obj;
};

class RGE_Action {
public:
    void* vtable_ptr;
    short action_type;
    char gap_06_07[2];
    RGE_Action_Object* obj;
    unsigned char state;
    char pad_0D_0F[3];
    RGE_Static_Object* target_obj;
    RGE_Static_Object* target_obj2;
    int targetID;
    int target2ID;
    float target_x;
    float target_y;
    float target_z;
    float timer;
    RGE_Task* task;
    RGE_Action_List* sub_actions;
    RGE_Sprite* sprite;
    unsigned char subActionValue;
    char pad_3D_3F[3];

    ~RGE_Action();
    RGE_Action(RGE_Action_Object* obj, int type);
    void set_target_obj(RGE_Static_Object* target);
};

class __declspec(novtable) RGE_Action_Move_To : public RGE_Action {
public:
    float range;

    RGE_Action_Move_To(RGE_Action_Object* obj, RGE_Static_Object* target, float range_val, RGE_Sprite* spr);
};

RGE_Action_Move_To::RGE_Action_Move_To(RGE_Action_Object* obj, RGE_Static_Object* target, float range_val, RGE_Sprite* spr)
    : RGE_Action(obj, 1)
{
    *(int*)this = 0x56E3A0;
    action_type = 1;
    set_target_obj(target);

    if (target) {
        target_x = target->world_x;
        target_y = target->world_y;
        target_z = target->world_z;
    }

    range = range_val;
    sprite = spr;

    if (range_val <= 0.0f)
        range = 0.4f;

    if (spr == 0) {
        RGE_Static_Object* o = this->obj->obj;
        RGE_Sprite* s = o->spriteBC;
        if (s == 0) {
            sprite = o->sprite18;
        } else {
            sprite = s;
        }
    }
}
