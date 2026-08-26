// VA: 00430D50 RGE_Combat_Object::moveTo(float,float,float,float,int)
// Source: com_obj.cpp lines 930-974
// FLAGS: config/flags/00430D50_moveTo.rsp uses /GX for original EH-framed new+ctor cleanup.
// Attempt log:
// initial natural source modeled from packet, reusing nearby 00430C30 moveTo type surface.
// added /GX flag: required to match original EH-framed new+ctor region/prologue.
// added full RGE_Action data layout: fixed operator new size from 8 to original 0x44.
// Direct action surface matches calls through targetX/Y/Z, type, move_to, and action insertion.
// tried volatile x/parameter-slot casts for early comparisons: worsened prologue/register allocation; rolled back.
// tried bool found/result style and volatile result: worsened tail or forced stack result reload; rolled back.
// tried if/else, goto fail/have_move, initialized result, and result=(int)move_action tail forms.
// best remaining diff (this file): 359 bytes, edit diff 16 (4.4568%), first mismatch at success-branch displacement.
// localized drift: after RGE_Action_Move_To ctor, rebuilt zeros eax before EH-state reset and uses test/je to shared epilogue;
// original tests edi before EH-state reset, uses jne to success body, then xor eax/jmp epilogue on null. Store does not affect flags,
// eax is overwritten on success, and null path returns 0, so this looks behavior-equivalent but is not exact.
// Fresh worker: a pointer-as-status diagnostic reached 49 strict differing bytes
// but added `mov edi,1; mov eax,edi` on success; it was rolled back to the
// natural int result candidate (54 bytes, exact size/calls).
// Main-agent audit replaced casts and raw master offsets with canonical
// inherited ownership.
// Current worker: explicit constructor-null/done-label and direct-return forms
// expanded the EH tail to 378/382 bytes and were rolled back.
// A pointer-typed constructor result with canonical ownership reproduced the
// 359-byte/49-diff basin, but retained opposite `je` polarity and the
// `mov edi,1; mov eax,edi` success conversion; restored the clean int-result form.
// The remaining exactness blocker is the VC5 EH-tail lowering around the
// constructor null test: the clean source hoists `xor eax,eax` before `test edi`
// while the oracle tests first, resets EH state, then branches `jne` to success.
// Follow-up worker: mirrored the exact 00430C30 same-TU allocation tail with direct
// returns; VC5 produced 382 bytes / 161 diff because it duplicated the EH epilogue.
// Converted the constructor pointer into an int status, matching the decompiler's
// iVar4 shape; this reached the known 359-byte / 49-diff diagnostic basin but kept
// the opposite `je` layout. Negative if/else, goto-done, pointer-only, and switch
// status forms either duplicated the epilogue or reproduced the 54-byte clean basin.
// Reordered locals to PDB int-before-pointer order; emitted bytes unchanged.
// Variant lab of six plausible tail forms under /GX found no exact or new invariant
// basin. Restored the canonical int-result source; blocker remains localized to the
// constructor null-test/EH-tail branch layout.
// Follow-up worker: retested positive constructor if/else, direct success return, and positive-goto tail forms; all entered the known 378-byte EH basin. Restored the validated 359-byte int-result source.
// Current worker: tested a same-TU-style nested allocation scope for the Move_To pointer; emitted code was unchanged and the scope was rolled back.
// Current pass: clean baseline rebuilt at 359 bytes with 54 strict differing bytes.
// Pointer-as-status `(int)(move_action = new ...)` reached 359 bytes and 49 bytes,
// but emitted `je` to the cleanup tail and `mov edi,1; mov eax,edi` on success.
// Explicit if/else, null-first, goto-done, direct-return, and do-while-zero tails
// either rebuilt 378/382 bytes or returned to the 54-byte basin. Restored clean.
// Revisit pass: the original com_obj.cpp EH tail matches the same natural pattern
// seen at 00431150 and 004CB450: test the typed constructor result, reset EH state,
// branch to typed action work, return zero on null, and return one after add_action.
// Direct-return, typed-pointer-result, explicit-goto, and result-initialization
// variants did not reproduce this VC5 layout. The clean int-result source remains
// authoritative; no shared ABI or layout change was justified.
// Bounded follow-up (sa-ade25929-r1): rechecked positive/negative if-else tails,
// boolean and integer constructor-status carriers, direct returns without the
// unused result declaration, a null-pointer assignment carrier, return-assignment
// spelling, and explicit fail/success/done labels. Results were 58, 49, 161, 71,
// or 147 differing bytes, with no exact or new useful basin. Restored the pinned
// 359-byte natural int-result source; the constructor EH-tail polarity remains
// unresolved (oracle tests edi before the EH-state reset, while clean VC5 emits
// xor eax before that test).
// ACCEPTED DRIFT: The changed tail tests the constructor result and zeros the
// failure return on opposite sides of the same EH-state reset. XOR, TEST, and
// the EH-state store cannot throw; both builds establish state -1 before the
// next memory access or call. Null returns zero. Success performs the same list
// deletion, action insertion, cleanup, and one return. All 16 calls, values,
// memory effects, EH coverage, and fault behavior match.

#include <stddef.h>

typedef unsigned char uchar;

#include "../com_obj_phase2_context.h"

int RGE_Combat_Object::moveTo(float x, float y, float z, float range, int force)
{
    RGE_Action* action;
    RGE_Action_Move_To* move_action;
    RGE_Sprite* sprite;
    int result;

    if (force == 0) {
        if (this->actions->have_action() == 1) {
            action = (RGE_Action*)this->actions->get_action();
            if (action->targetX() == x) {
                action = (RGE_Action*)this->actions->get_action();
                if (action->targetY() == y) {
                    action = (RGE_Action*)this->actions->get_action();
                    if (action->targetZ() == z) {
                        action = (RGE_Action*)this->actions->get_action();
                        if (action->type() == 1) {
                            goto success;
                        }
                    }
                }
            }
        }
    }

    if (this->actions->have_action() == 1) {
        action = (RGE_Action*)this->actions->get_action();
        if (action->move_to(this, x, y, z) == 1) {
            goto success;
        }
    }

    sprite = this->master_obj->moving_sprite;
    if (sprite == 0) {
        sprite = this->master_obj->sprite;
    }

    move_action = new RGE_Action_Move_To(this, x, y, z, range, sprite);
    result = 0;
    if (move_action != 0) {
        this->actions->delete_list();
        this->add_action(move_action);

success:
        result = 1;
    }
    return result;
}
