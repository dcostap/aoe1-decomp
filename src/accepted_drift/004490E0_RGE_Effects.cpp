// VA: 004490E0 RGE_Effects::RGE_Effects(int fd)
// effects.cpp lines 21-63
// 352 bytes
// BLOCKER: VC5 emits the inner count branch before the list publication store.
// The target keeps the same instructions but emits cmp, mov, then jle.
// The remaining four bytes are instruction order only.
//
// Attempt log:
// - natural C++ with vtable_ptr member: esi=this, ebx=&effect_num, ebp=0/running offset
// - int* peffect = &effect_num: same pattern
// - vtable_ptr before/after peffect: same
// - comma-separated for loops with explicit offset: edi=this (worse prologue)
// - Ghidra decomp literal with long* plVar1 and do-while: same esi=this
// - RGE_Effect* eff vs direct effects[i] access: same
// - (int*)(this)+2 for &effect_num: same esi=this
// - compound for(;;) with off+=0x2C: edi=this, changed frame size
// - __thiscall standalone function: does not link properly
// - vtable written first in body: esi=this
// - destroy() declared in class: no effect
// FLAGS: none
// NOTE: The int ctor and save have the same register allocation problem.
// A combined-TU compile might fix this but requires infrastructure changes.
// - corrected the binary-proven outer record ownership: the original rereads
//   `effects` for the name but applies the running byte offset only to the
//   count/list fields; the prior indexed `eff` source changed this behavior.
// - structural reconstruction now matches the 10-call set, exact 352-byte
//   boundary, frame-size neighborhood, and original zero/list CFG; the
//   remaining gap is VC5 register/local-home scheduling (this is not an
//   unresolved field-width or call-ABI question).
// - final diagnostic used a volatile list-field pointer to reproduce the
//   stack-lived field address, but that qualifier is not binary-proven source
//   and was removed from the living candidate; keep the natural typed pointer.
// Fresh pass:
// - baseline retained the prior canonical candidate at diff 321.
// - named the offset-bearing RGE_Effect owner and took list_ptr from its typed
//   effect_list field; this reached exact size/frame and diff 300.
// - combined that ownership model with the known effects.cpp polymorphic class
//   surface; diff moved to 298.
// - reread the typed count pointer in the inner loop condition. This restored
//   the original inner instruction order, reached 62.5% exact-block coverage,
//   and reduced the positional diff to 262, but left an extra outer entry jump
//   and eight bytes past the original boundary.
// - outer while form, self->effect_num as the repeated bound, typed short count,
//   and function-scope owner locals produced no new codegen.
// Fresh worker probes:
// - outer while entry form moved the mismatch to 270 bytes and was restored.
// - manual vtable storage kept the constant but reordered the prologue and moved
//   the mismatch to 272 bytes; restored to the polymorphic surface.
// - direct this ownership plus block-scoped effect/list pointers duplicated the
//   262-byte codegen basin with a slightly smaller edit diff; kept as the natural
//   source form. Reordering fields before virtual declarations was also duplicate.
// Main-agent audit replaced the byte-offset record cursor with typed effect
// indexing. The first effect still owns each name read, as the executable shows.
// The oracle's cmp/store/jle sequence proves that the allocated-list store is
// before the repeated count test. The typed source now keeps that order.
// Matching-worker pass (2026-08-16): fresh baseline rebuilt 360 bytes against
// the 352-byte target, with 10/10 ordered calls, the 0x14 frame, and 262 strict
// differing bytes. The receiver was EBX, so the prior register-color blocker
// is not the current first mismatch.
// - top-tested outer while, outer for, explicit outer bound-pointer reread,
//   infinite-loop break, and an explicit source loop label were codegen
//   duplicates; each kept the extra outer-entry restore jump.
// - moving the allocated-list store before the inner guard added one exact
//   block but kept the same strict diff; this is now the living source order.
// - virtual declaration order, a self alias, function-scope pointer locals,
//   and an explicit byte offset all produced no improvement or a 270-byte
//   diff. Inverted and continue-based zero-list guards reached 264 bytes.
// - rebuilt the assembly donor index and found no useful exact constructor or
//   inner-record donor. The clean typed source remains the best natural basin.
// - replaced the command byte cursor with typed command indexing. VC5 emitted
//   the same natural codegen, so the source no longer encodes raw byte plumbing.
// - outer while/for forms, direct effect-name access, and declaration-order
//   variants all reproduce the same codegen basin. The remaining extra outer
//   entry jump is unresolved compiler CFG scheduling, not an ABI or layout gap.
// Best current source keeps the natural typed ownership and the binary-proven
// count reread. Remaining gap is structural outer-entry sharing plus vtable
// relocation context; no unresolved field layout or call ABI issue remains.
// Accepted-drift review: all ten read/allocation calls preserve order, sizes,
// file descriptors, and member or heap destinations. The first effect still
// owns every name read. Count rereads, null-list publication, partial-load
// faults, loop progress, zero-count cleanup, vptr publication, and returns
// match. Residual drift is the four-byte inner cmp/store/jle order.
//
// Exact-finish pass:
// - The old clean source rebuilt 360 bytes with a 262-byte diff. The reduced
//   typed source below rebuilds 352 bytes with a 4-byte diff.
// - Moving list-address formation into the positive count arm recovered the
//   target outer entry, list address, boundary, and all 128 instructions.
// - Direct zero publication in the negative arm recovered the target partial
//   object state. It must not publish the list address before that guard.
// - An exact donor at 004C8490 supports a repeated counter-left guard and
//   allocation publication pattern. The target still needs its list alias.
// - Assignment-before-guard, a short inner counter, duplicate inner cleanup,
//   a named post-inner label, and allocator headers did not improve the 4-byte
//   result. The changed forms were restored.
// - Fresh validation: 10 ordered calls, exact boundary, 0x14 frame, 128
//   instructions, two returns, two jumps, and 350 equal bytes.
// - The target has no EH frame. The source keeps the authentic virtual surface
//   and vptr publication. World-level new/constructor EH owners are unchanged.

#include <stdlib.h>

void __cdecl rge_read(int fd, void* buf, int size);

struct RGE_Effect_Command {
    unsigned char command; unsigned char _pad_0;
    short change_num1; short change_num2; short change_num3; float change_amount;
};

struct RGE_Effect {
    short id; char name[31]; unsigned char _pad_0;
    short string_table_id; short effect_list_num;
    unsigned char _pad_1[2]; RGE_Effect_Command* effect_list;
};

class RGE_Player;

class RGE_Effects {
public:
    RGE_Effect* effects;
    long effect_num;
    virtual ~RGE_Effects();
    virtual void save(int fd);
    virtual void do_effect(short effect_id, RGE_Player* player);
    RGE_Effects(int fd);
};

RGE_Effects::RGE_Effects(int fd) {
    int file = fd;
    long* peffect = &this->effect_num;
    int outer_count;
    rge_read(file, peffect, 4);
    if (*peffect > 0) {
        this->effects = (RGE_Effect*)calloc(*peffect, 0x2C);
        outer_count = 0;
        if (outer_count < *peffect) {
            do {
                RGE_Effect* effect;
                RGE_Effect* fields;
                effect = this->effects;
                fields = &this->effects[outer_count];
                rge_read(file, effect->name, 0x1F);
                rge_read(file, &fields->effect_list_num, 2);
                if (fields->effect_list_num > 0) {
                    int inner_count;
                    RGE_Effect_Command*& list = fields->effect_list;
                    RGE_Effect_Command* allocated =
                        (RGE_Effect_Command*)calloc(fields->effect_list_num, 0x0C);
                    inner_count = 0;
                    if (inner_count < fields->effect_list_num) {
                        list = allocated;
                        do {
                            RGE_Effect_Command* command =
                                &list[inner_count];
                            rge_read(file, &command->command, 1);
                            rge_read(file, &command->change_num1, 2);
                            rge_read(file, &command->change_num2, 2);
                            rge_read(file, &command->change_num3, 2);
                            rge_read(file, &command->change_amount, 4);
                            inner_count++;
                        } while (inner_count < fields->effect_list_num);
                    }
                } else {
                    fields->effect_list = 0;
                }
                outer_count++;
            } while (outer_count < this->effect_num);
        }
    } else {
        this->effects = 0;
        this->effect_num = 0;
    }
}
