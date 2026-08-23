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
