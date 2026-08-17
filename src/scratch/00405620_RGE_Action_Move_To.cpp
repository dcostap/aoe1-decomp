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
// 2026-08-09 orch-luna-405620-w1 fresh pass (10 probes): early-return, canonical master-object layout, hoisted
// fallback locals, explicit joins, direct-member destination, full virtual base surface, explicit final return,
// outer switch, and address-taken destination variants all failed to change the clean 205B/47B basin. The direct
// member variant reached 186B/35B but introduced an early common sprite store, so it is diagnostic only. Restored
// the natural named-object/inner if-else source; remaining evidence-backed blocker is the EH tail's duplicated
// cleanup versus the original's single FS-first shared epilogue.
// 2026-08-09 normalization-only audit: restored the full polymorphic RGE_Action surface proven by matching/00407A20,
// removed __declspec(novtable), the raw vtable_ptr field, and the manual 0x56E3A0 store; RGE_Action_Move_To is now a
// natural derived class and VC5 owns the vptr emission. The prior manual surface's 205B/47B result and the earlier
// natural-vptr 205B/56B result remain diagnostic evidence, not source-shape justification. No new hypothesis was run.
// 2026-08-10 orch-actmove-01 fresh pass: corrected fallback ownership to the real action-object master hierarchy
// (RGE_Master_Action_Object::move_sprite/sprite), and replaced the decompiler-shaped local cursor with direct
// canonical member expressions; corrected +0xBC base sizing restored the same 205B/47B tail basin. Explicit
// branch-return spellings were codegen-identical. /Og- destroyed the exact 137-byte prefix (256B), and a boolean
// switch was worse (211B/64B). Restored natural direct master-field if/else; remaining blocker is VC5's duplicated
// EH cleanup tail versus the original single shared epilogue. Final local layout retains proven 0x194 action-object
// and 0xFC master-action sizes; these size corrections are codegen-identical.
// 2026-08-09 sa3cad3b68-ctor pass: explicit inner/outer joins, inverted and direct-member predicates, do/break,
// hoisted fallback locals, and an explicit derived-destructor declaration all stayed in the 205B/47B basin. The
// volatile-destination test was codegen-identical but is not source-plausible. Restored this natural named-object /
// local-sprite if/else; the shared-vs-duplicated EH epilogue remains the only structural blocker.
// 2026-08-10 wave21-actmove-01: same-TU lifetime-context probe (full action-object virtual surface plus the proven
// derived destructor definition) emitted identical 205B/47B; restored this canonical source before final validation.
// 2026-08-11 sa6bb323c9 pass (7 meaningful probes): inner default-arm-only goto and no-else goto forms were
// codegen-identical; positive move-arm/goto and inner pointer-switch forms worsened to 205B/53B. A narrow /Os
// overlay destroyed the optimized prefix (156B/174B), and a proper numeric #line-band context probe was identical.
// The focused variant family was not usable because its generated flags omitted required /GX (all variants lost
// the EH prologue). Restored the canonical typed if/else source; remaining evidence-backed blocker is the VC5
// duplicated EH cleanup tail versus the original single shared epilogue.
// 2026-08-12 orch-00405620-L pass: explicit outer/inner labels, typed master/move locals, inner fallback goto,
// base-constructor throw() context, and constructor early-return forms stayed in the 205B/47B basin or worsened.
// Early return plus complementary independent inner tests reached 188B/34B with one extra move-sprite test and
// wrong register/field ownership; direct repeated member tests reached 197B/44B. Restored the canonical typed
// if/else source. The remaining blocker is still the EH tail: original uses branch-local stores and one shared
// cleanup, while this VC5 source basin duplicates cleanup for the natural inner if/else.
// 2026-08-13 tu-actmove-405620 pass: fresh block and raw-byte checks confirm a 137-byte exact prefix and the
// same two branch-local stores; no new period-plausible source lead remains for the shared EH epilogue. Left the
// canonical typed source unchanged; final mismatch is 47 bytes at the inner fallback join.
// 2026-08-13 shardE-405620: reversed the natural inner arm order; VC5 kept the duplicated EH tail and worsened to
// 205B/53B. Restored the canonical zero-first if/else; no new source lead remains.
// 2026-08-14 sa224b14d6-actmove: typed the action object's master as its moving-master base; VC5 emitted the
// same 205B/47B tail. Restored the canonical action-master type; the shared EH epilogue remains unresolved.
// 2026-08-16 sa-31364047-r1: fresh baseline reconfirmed 205B/47B. An explicit inner fallback goto worsened to
// 205B/53B; exact numeric #line context was codegen-identical. Restored the clean typed if/else source; no new
// period-plausible source lead found. Next evidence needed is a matching VC5 EH-tail context or original source.

class RGE_Action_Object;
class RGE_Sprite;
class RGE_Static_Object;
class RGE_Task;
class RGE_Action_List;

class RGE_Master_Static_Object;
class RGE_Master_Animated_Object;
class RGE_Master_Moving_Object;
class RGE_Master_Action_Object;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x14];
    RGE_Sprite* sprite;             // +0x18
    char gap_1C[0x9C];
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    float speed;                    // +0xB8
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    RGE_Sprite* move_sprite;        // +0xBC
    char gap_C0[0x18];
};

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    char gap_D8[0x24];
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    long id;                        // +0x04
    RGE_Master_Static_Object* master_obj; // +0x08
    void* owner;                    // +0x0C
    RGE_Sprite* sprite;             // +0x10
    RGE_Sprite* old_sprite;         // +0x14
    void* sprite_list;              // +0x18
    char gap_1C[0x1C];
    float world_x;                  // +0x38
    float world_y;                  // +0x3C
    float world_z;                  // +0x40
    char gap_44[0x44];
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    float speed;                    // +0x88
};

class RGE_Moving_Object : public RGE_Animated_Object {
public:
    char gap_8C[0xF4];
};

class RGE_Action_Object : public RGE_Moving_Object {
public:
    unsigned char waiting;         // +0x180
    char gap_181[3];
    RGE_Action_List* actions;      // +0x184
    unsigned char command_flag;    // +0x188
    char gap_189[3];
    int last_action_value;         // +0x18C
    int last_action_state_value;   // +0x190
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int setup(RGE_Action_Object*);
    virtual int setup(int, RGE_Action_Object*);
    virtual RGE_Action_List* create_action_list(RGE_Action_Object*);
    virtual void rehook();
    virtual void save(int);
    virtual short type();
    virtual void first_in_stack(unsigned char);
    virtual unsigned char inside_obj_update();
    virtual unsigned char idle_update();
    virtual unsigned char update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object*, float, float, float);
    virtual int work(RGE_Static_Object*, float, float, float);
    virtual unsigned char attack_response(RGE_Static_Object*);
    virtual unsigned char relation_response(long, unsigned char);
    virtual void copy_obj(RGE_Master_Action_Object*);
    virtual void copy_obj_sprites(RGE_Master_Action_Object*, RGE_Task*, RGE_Task*);
    virtual void get_state_name(char*);
    virtual RGE_Static_Object* get_target_obj();
    virtual RGE_Static_Object* get_target_obj2();
    virtual void set_target_obj(RGE_Static_Object*);
    virtual void set_target_obj2(RGE_Static_Object*);
    virtual void set_state(unsigned char);

    short action_type;
    char gap_06[2];
    RGE_Action_Object* obj;
    unsigned char state;
    char gap_0D[3];
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
    char gap_3D[3];

    RGE_Action(RGE_Action_Object* obj, int type);
};

class RGE_Action_Move_To : public RGE_Action {
public:
    float range;

    RGE_Action_Move_To(RGE_Action_Object* obj, RGE_Static_Object* target, float range_val, RGE_Sprite* spr);
};

RGE_Action_Move_To::RGE_Action_Move_To(RGE_Action_Object* obj, RGE_Static_Object* target, float range_val, RGE_Sprite* spr)
    : RGE_Action(obj, 1)
{
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
        RGE_Master_Action_Object* master =
            (RGE_Master_Action_Object*)this->obj->master_obj;
        if (master->move_sprite == 0) {
            sprite = master->sprite;
        } else {
            sprite = master->move_sprite;
        }
    }
}

// 2026-08-17 sa-84432c6c-r1: natural tail probes kept the clean 205B/47B basin.
// Explicit return and label forms were codegen-identical. Master and move-sprite locals were also identical.
// A member-RMW form reached 187B/37B and one shared epilogue, but it stored move_sprite before its null test.
// That changed the proven branch-local stores, so it is diagnostic only. Restored this typed nested if/else.
// 2026-08-17 sa-2a70caf3-r1 audit: 20 semantic and control-flow probes found no natural source that shares
// VC5 cleanup and keeps the original fault order, one move-sprite null test, and two branch-local stores.
// Result locals and parameter mutation share cleanup only by merging the final store. Independent tests add a
// redundant null test. The clean typed nested if/else remains authoritative; the 19-byte duplicated EH tail is
// a VC5 code-layout blocker, not a behavior correction.
// 2026-08-17 shared-tail audit: 20 natural constructor result, null-test, assignment, and return forms were rebuilt.
// The oracle has one outer null test, one move-sprite null test, two branch-local stores, and one shared FS cleanup.
// No tested source form kept all four facts and selected one local VC5 cleanup tail. The 187-byte member-RMW form is
// rejected: it stores move_sprite before its null test. Preserve this canonical nested if/else source.
