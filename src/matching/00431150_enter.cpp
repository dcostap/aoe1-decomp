// VA: 00431150, RGE_Combat_Object::enter, 255 bytes
// Source: com_obj.cpp lines 1097-1139
// FLAGS: /nologo /c /O2 /Oy /GX
//
// Attempt log:
// - v1: initial __stdcall function pointers. vtable calls use 5 pushes (stdcall) instead of
//   4 pushes+ecx (thiscall). Returns generate inline EH epilogues. Function too large (320+ bytes).
// - v2: static helper wrappers (matching unload pattern). No improvement.
// - v3: VTableProxy with 130+ dummy virtuals to align vtable offsets. Fixes thiscall for vtable
//   calls (4 pushes+ecx for vf210, 1 push+ecx for vf208). Still inline epilogues, 320 bytes.
// - v4: single return variable pattern. Changed stack layout (push ecx for local).
// - v5: && combined conditions. Same as v1.
// - v6: goto with label. Compile error (goto skips initialization).
// - v7: variant_lab probing return_pattern (multiple_returns, single_result, goto_label, all_returns)
//   x flag-preset vc5-small (12 flag variants). Best group: multiple_returns+gx, first_mismatch=47,
//   text_size=341 (fails 255-byte target due to inline epilogues).
// - v8: function-ptr approach (matching unload style) directly. Still 320 bytes, stdcall for vtable.
//
// Current bounded session:
// - baseline rebuilt 314B with all 11 calls aligned, but explicit action vtable casts used stdcall.
// - restored donor-style RGE_Action and moving-object virtual surfaces; calls
//   use their original thiscall form without raw vtable plumbing.
// - top-declared pointers/scalars plus one `goto fail` produced the best 274B reconstruction (65 positional
//   diff, 90.32% shape, 87.21% exact-block coverage). The object lookup, action checks, task call, allocation,
//   constructor, delete-list, and add-action bodies are byte-aligned through the constructor-failure test.
// - nested-positive, direct-return, positive-success, hybrid guard, and exact RGE_Action_Enter ABI surface
//   probes did not improve the tail; some were codegen duplicates or broadened the CFG.
// - remaining blocker is structural EH-tail lowering: original routes object/task failures to the single
//   FS-first epilogue at 0043123A and only emits `xor eax,eax; jmp` for constructor failure; VC5 keeps a
//   duplicated zero-return epilogue before the success body (+19B). Calls, relocation targets, and field
//   ownership are otherwise aligned. Keep this clean, typed reconstruction in scratch.
// - Main-agent audit replaced the raw VTableProxy cast with a canonical narrow
//   RGE_Moving_Object base and named virtual calls; emitted code is unchanged.
// Fresh worker: typed shared-result pointer and integer-result forms were tested
// against the gather/transport EH-tail pattern; they worsened prologue/layout
// (101 and 243 differing bytes) and were rolled back. Keep the 274-byte natural
// goto-fail reconstruction with calls/relocations aligned.
// Fresh session probes: uninitialized integer status still expanded to 316B;
// a Ghidra-shaped pointer status (including reuse of obj and a self alias) held
// the shared tail at 257B/101 diff but swapped this/object registers and added
// an early saved-register ordering change. These alias-shaped diagnostics were
// rolled back; no opaque status cast survives in the canonical source.
// Main-agent audit removed inline empty virtual definitions and restored
// canonical destructor ownership; the shared-EH-tail blocker remains.
// Fresh replacement orch-comobj-fresh-03: direct action-result/truth-return forms
// expanded to 317B/261 diff and 298B/241 diff. A canonical typed object/result
// pointer with one shared done label reached 257B/101 diff and the correct CFG,
// but VC5 colored this=EDI and target/result=ESI, added a result move, and emitted
// an extra task-null zero/jump. Declaration-order, lookup-assignment-order,
// separate-target, and narrow register-hint variants were codegen duplicates.
// Restored the pinned 274B natural typed goto-fail reconstruction; shared EH-tail
// lowering remains the only structural blocker observed in this assignment.
//
// Fresh bounded pass (sa-4269ae07-r1): initialized int/pointer status and
// positive-guard/direct-return variants all regressed the exact body basin
// (187-261 differing bytes); pointer-result form shared the tail only after
// swapping this/object register ownership (257B/101 diff) and was not kept.
// Adding stdlib.h was codegen-neutral (274B/65 diff). A 4-case tail lab was
// diagnostic only and used default flags without the target /GX response file;
// no variant was promoted. Restored the natural typed goto-fail source.
// Fresh cfg probe (orch2-431150-cfg): combined donor-style `goto success` with
// the current object/task/constructor `goto fail` paths. This is codegen-identical
// to the pinned 274B/65-diff source; VC5 still emits separate success/failure
// epilogues, so the single original FS-first tail remains unresolved.
// Fresh cfg probe (follow-431150-r1): split constructor allocation failure into
// a direct return while retaining the shared object/task fail label, based on
// the original constructor-only `xor eax,eax` block. This expanded to 299B/182
// diff and lost the aligned task/body basin; rolled back to the donor-style
// shared fail source.
// Current bounded pass: ABI/dossier/donor review and a success/failure label
// order probe were completed. Label reversal worsened to 157 differing bytes;
// restore the natural typed goto-fail source and preserve the EH-tail lead.
//
// Session 01a0290d-3177-7e45-9539-3c25d1ddb62d: sustained EH-tail pass.
// H1 typed pointer result initialized from lookup: 255 bytes, 193 diff; the
// early result store changed the register basin. H2 uninitialized typed result
// after task/constructor calls: 259 bytes, 57 diff; it shared cleanup but used
// EBX and reloaded an invalid object-failure home. H3 int and H5/H6 opaque or
// register-qualified carriers were the same 259/57 basin. H4 initialized int
// result expanded to 255/194. H7 constructor-null-only zero assignment reached
// 263/33 with shared cleanup, but retained an unsupported uninitialized failure
// carrier and EBX result; it is diagnostic only. H8 action-pointer boolean,
// H9 explicit object-failure zero, H11 uchar result, H12/H13 boolean return,
// H14 positive constructor guard, H15 task-carrier reuse, H17 typed action
// result, H18 action pointer carrier, and H19 initialized opaque result either
// regressed or reproduced a non-natural carrier basin. H10 was covered by the
// structured source lab. The natural combined action guard was codegen-equivalent
// to the pinned 274-byte source under the target response file and was rolled
// back. A 5-way tail lab with /GX and 12 flag combinations found no exact or
// invariant-eligible result; the closest group was opaque-result, 263 bytes,
// 31 diff, still wrong size and cleanup topology. The lab's default-flag group
// lacked EH and was not evidence for promotion. Donor search confirms the
// target's final mov-eax-one and cleanup shape, but sibling direct-return
// sources do not explain this function's single shared EH tail.
// Strict drift assessment: do not recommend accepted_drift. The residual
// difference is the EH cleanup and return CFG, which policy excludes even
// though calls, predicates, fields, and fault order otherwise align. Restore
// and retain the natural typed goto-fail source below.
// Fresh ABI pass: the PDB owner type is UAEHHH, so enter is a virtual method.
// Restoring that declaration is codegen-neutral. A defined pointer-result
// shared-tail probe reached one return but changed the early object-failure
// branch and register basin. The EH-tail blocker remains.
// Final bounded pass: restored the reviewed Static -> Animated -> Moving ->
// Action -> Combat ownership chain and placed the Combat enter override at the
// inventory-proven +0x180 virtual slot. Correct object(), get_action(),
// add_action(), make_enter_task(), and RGE_Action_Enter target declarations
// are codegen-neutral and retained. The closest one-return typed result form
// is 263 bytes/33 differing bytes, but it returns an uninitialized result when
// object lookup fails; it is diagnostic only. Initializing that carrier from
// the lookup result regresses to 259 bytes/213 differing bytes. The natural
// behavior-defined goto-fail source remains 274 bytes/65 differing bytes.
// The final ABI cleanup changed task, action, target, and object pointer
// declarations to their reviewed types without changing emitted bytes.
// Reopened the 263-byte one-return carrier. The original object-failure edge
// at 0043117F branches directly after TEST EDI. EAX still holds the zero
// returned by object(); the common tail does not read the allocation home at
// [esp+20h]. The task-failure edge at 004311E5 branches directly after TEST
// EBX. EAX still holds the task call's zero result. Constructor failure is
// different: 0043121D explicitly XORs EAX before the common tail. Therefore
// no uninitialized or stale result is proved on the original failure paths.
// The 263-byte carrier instead reads [esp+20h] on object failure and returns
// EBX, so it changes the observable failure value. Restore the natural source.
// Translation-unit recovery: VC5 emits the original shared EH tail when this
// method follows another function in com_obj.cpp. The real earlier owner at
// 004304A0 is sufficient. With natural direct failure returns, the result is
// 255/255 bytes and exact. Target-only compilation keeps the old 274-byte
// duplicated-cleanup basin.
// Exact-finish walkback: a prior function plus the old shared fail label leaves
// two branch-target bytes. Making only the object or task failure direct leaves
// one byte. Making all three failure returns direct removes both differences.
// Removing the now-unused fail label stays exact. Dummy counts 1 through 40
// reproduce the same context basin, so no specific dummy or ambient declaration
// is required; the retained context is one real earlier com_obj.cpp owner.

// Key remaining issues:
// 1. No shared tail: VC5 generates inline EH epilogues at each return instead of one shared
//    cleanup. Original has single cleanup at 0043123A shared by all paths. Shared tail saves
//    ~60 bytes (3x20 - 20 = 40 bytes of cleanup, plus jumps).
// 2. The reviewed Static -> Animated -> Moving -> Action -> Combat chain
//    declares the inherited virtual surface needed for the late slots.
// 3. SEH handler address (55CE7Bh) vs 0 placeholder - masked by relocation system.
// 4. Register allocation differs from original (original: eax=world_z, ecx=world_y, edx=world_x;
//    rebuilt varies by version).
// 5. Stack layout: original reuses param_1 slot [esp+20h] as temp, my code allocates at
//    different offsets.
//
// Best guess: the original source used 'new' expression (not operator_new) and had a specific
// control-flow structure (nested ifs vs &&) that caused VC5 to merge epilogues into a shared
// tail. The matching unload also has inline epilogues (which is fine at 254 bytes), but the
// enter function must fit in 255 bytes, requiring the shared tail or ~65 fewer code bytes.
// The VTableProxy approach works for thiscall calling convention but adds code size.
// The function-ptr approach fails to generate thiscall for vtable[0x210] in this function.

#include <stddef.h>

typedef unsigned char uchar;

class RGE_Action_Object;
class RGE_Task;
class RGE_Static_Object;
class RGE_Action;

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x84];
    void** objectsValue;
    int numberObjectsValue;
    int maxNumberObjectsValue;
    void** negativeObjectsValue;
    int numberNegativeObjectsValue;
    int maxNumberNegativeObjectsValue;

    RGE_Static_Object* object(int index);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int id;
    void* master_obj;
    RGE_Player* owner;
    char gap_10[0x28];
    int world_x;
    int world_y;
    int world_z;
    uchar gap_44[0x44];
};

class RGE_Action_List {
public:
    char gap_00[8];
    void* list;

    uchar have_action();
    RGE_Action* get_action();
    void delete_list();
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual void slot_04();
    virtual void slot_08();
    virtual void slot_0C();
    virtual void slot_10();
    virtual void slot_14();
    virtual short func18();
    virtual void slot_1C();
    virtual void slot_20();
    virtual void slot_24();
    virtual void slot_28();
    virtual void slot_2C();
    virtual void slot_30();
    virtual void slot_34();
    virtual void slot_38();
    virtual void slot_3C();
    virtual void slot_40();
    virtual void slot_44();
    virtual void slot_48();
    virtual RGE_Static_Object* func4C();

    short action_type;
    uchar gap_06[2];
    void* obj;
    uchar state;
    uchar gap_0D[3];
    void* target_obj;
    void* target_obj2;
    int targetID;
    int target2ID;
    float target_x;
    float target_y;
    float target_z;
    float timer;
    void* task;
    void* sub_actions;
    void* sprite;
    uchar subActionValue;
    uchar gap_3D[3];
};

class RGE_Action_Enter : public RGE_Action {
public:
    virtual ~RGE_Action_Enter();
    RGE_Action_Enter(RGE_Action_Object* obj, RGE_Task* task, RGE_Static_Object* target);
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    float speed;
};

// Inherited surface through the two binary-observed late virtual slots.
class RGE_Moving_Object : public RGE_Animated_Object {
public:
    virtual ~RGE_Moving_Object();
    virtual void d01();
    virtual void d02();
    virtual void d03();
    virtual void d04();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual void d08();
    virtual void d09();
    virtual void d0a();
    virtual void d0b();
    virtual void d0c();
    virtual void d0d();
    virtual void d0e();
    virtual void d0f();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d1a();
    virtual void d1b();
    virtual void d1c();
    virtual void d1d();
    virtual void d1e();
    virtual void d1f();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d2a();
    virtual void d2b();
    virtual void d2c();
    virtual void d2d();
    virtual void d2e();
    virtual void d2f();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void d36();
    virtual void d37();
    virtual void d38();
    virtual void d39();
    virtual void d3a();
    virtual void d3b();
    virtual void d3c();
    virtual void d3d();
    virtual void d3e();
    virtual void d3f();
    virtual void d40();
    virtual void d41();
    virtual void d42();
    virtual void d43();
    virtual void d44();
    virtual void d45();
    virtual void d46();
    virtual void d47();
    virtual void d48();
    virtual void d49();
    virtual void d4a();
    virtual void d4b();
    virtual void d4c();
    virtual void d4d();
    virtual void d4e();
    virtual void d4f();
    virtual void d50();
    virtual void d51();
    virtual void d52();
    virtual void d53();
    virtual void d54();
    virtual void d55();
    virtual void d56();
    virtual void d57();
    virtual void d58();
    virtual void d59();
    virtual void d5a();
    virtual void d5b();
    virtual void d5c();
    virtual void d5d();
    virtual void d5e();
    virtual void d5f();
    // RGE_Combat_Object overrides this inherited slot at vtable +0x180.
    virtual int enter(int param_1, int param_2);
    virtual void d61();
    virtual void d62();
    virtual void d63();
    virtual void d64();
    virtual void d65();
    virtual void d66();
    virtual void d67();
    virtual void d68();
    virtual void d69();
    virtual void d6a();
    virtual void d6b();
    virtual void d6c();
    virtual void d6d();
    virtual void d6e();
    virtual void d6f();
    virtual void d70();
    virtual void d71();
    virtual void d72();
    virtual void d73();
    virtual void d74();
    virtual void d75();
    virtual void d76();
    virtual void d77();
    virtual void d78();
    virtual void d79();
    virtual void d7a();
    virtual void d7b();
    virtual void d7c();
    virtual void d7d();
    virtual void d7e();
    virtual void d7f();
    virtual void d80();
    virtual void d81();
    // vtable[130] = offset 0x208
    virtual void add_action(RGE_Action* action) = 0;
    // vtable[131] = offset 0x20C (gap)
    virtual void d82();
    // vtable[132] = offset 0x210
    virtual RGE_Task* make_enter_task(RGE_Static_Object* obj, int x, int y, int z) = 0;

    uchar gap_8C[0xF4];
};

class RGE_Action_Object : public RGE_Moving_Object {
public:
    virtual ~RGE_Action_Object();
    uchar waiting;
    uchar gap_181[3];
    RGE_Action_List* actions;
    uchar command_flag;
    uchar gap_189[3];
    int lastActionValue;
    int lastActionStateValue;
};

class RGE_Combat_Object : public RGE_Action_Object {
public:
    uchar gap_194[0x30];
    virtual int enter(int param_1, int param_2);
};

int RGE_Combat_Object::enter(int param_1, int param_2)
{
    RGE_Static_Object* obj;
    RGE_Task* task;
    RGE_Action_Enter* action_enter;
    int x;
    int y;
    int z;

    obj = this->owner->world->object(param_1);
    if (obj == 0)
        return 0;

    if (param_2 == 0) {
        if (this->actions->have_action() == 1) {
            RGE_Action* action = this->actions->get_action();
            RGE_Static_Object* target = action->func4C();
            if (target == obj) {
                RGE_Action* action2 = this->actions->get_action();
                short action_val = action2->func18();
                if (action_val == 3)
                    goto success;
            }
        }
    }

    z = obj->world_z;
    y = obj->world_y;
    x = obj->world_x;
    task = this->make_enter_task(obj, x, y, z);
    if (task == 0)
        return 0;

    action_enter = new RGE_Action_Enter(this,
                                        task,
                                        obj);
    if (action_enter == 0)
        return 0;

    this->actions->delete_list();
    this->add_action(action_enter);

success:
    return 1;
}
