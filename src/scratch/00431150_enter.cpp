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

// Key remaining issues:
// 1. No shared tail: VC5 generates inline EH epilogues at each return instead of one shared
//    cleanup. Original has single cleanup at 0043123A shared by all paths. Shared tail saves
//    ~60 bytes (3x20 - 20 = 40 bytes of cleanup, plus jumps).
// 2. The narrow RGE_Moving_Object base declares the inherited virtual surface
//    needed for the two late slots without manual function-pointer dispatch.
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

extern "C" void* __cdecl operator_new(size_t size);

typedef unsigned char uchar;

class RGE_Action_Object;
class RGE_Task;

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

    void* object(int index);
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
};

class RGE_Action_List {
public:
    char gap_00[8];
    void* list;

    uchar have_action();
    void* get_action();
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
    virtual void* func4C();

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
    RGE_Action_Enter(RGE_Action_Object* obj, RGE_Task* task, RGE_Action_Object* target);
};

// Narrow inherited surface through the two binary-observed late virtual slots.
class RGE_Moving_Object {
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
    virtual void d60();
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
    virtual void* add_action(void* action) = 0;
    // vtable[131] = offset 0x20C (gap)
    virtual void d82();
    // vtable[132] = offset 0x210
    virtual void* make_enter_task(void* obj, int x, int y, int z) = 0;
};

class RGE_Combat_Object : public RGE_Moving_Object {
public:
    uchar gap_04[8];
    RGE_Player* owner;
    uchar gap_10[0x28];
    int world_x;
    int world_y;
    uchar gap_40[0x144];
    RGE_Action_List* actions;

    int enter(int param_1, int param_2);
};

int RGE_Combat_Object::enter(int param_1, int param_2)
{
    RGE_Static_Object* obj;
    void* task;
    RGE_Action_Enter* action_enter;
    int x;
    int y;
    int z;

    obj = (RGE_Static_Object*)this->owner->world->object(param_1);
    if (obj == 0)
        goto fail;

    if (param_2 == 0) {
        if (this->actions->have_action() == 1) {
            RGE_Action* action = (RGE_Action*)this->actions->get_action();
            void* target = action->func4C();
            if (target == obj) {
                RGE_Action* action2 = (RGE_Action*)this->actions->get_action();
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
        goto fail;

    action_enter = new RGE_Action_Enter((RGE_Action_Object*)this,
                                        (RGE_Task*)task,
                                        (RGE_Action_Object*)obj);
    if (action_enter == 0)
        goto fail;

    this->actions->delete_list();
    this->add_action(action_enter);

success:
    return 1;

fail:
    return 0;
}
