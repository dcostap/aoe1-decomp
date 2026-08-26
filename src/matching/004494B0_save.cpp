// VA: 004494B0 RGE_Effects::save(int fd)
// effects.cpp lines 140-183
// 265 bytes
// STATUS: exact match after typed array ownership for the outer record.
//
// Attempt log:
// - with RGE_Effect* eff local: first 20 bytes match (best result: 74% diff)
// - without eff local: prologue breaks (83% diff)
// - int* num = &effect_num: same 83% diff
// - natural nested for loops: 74% first 20 bytes match
// - outer do/while with typed effect[i] ownership: removed duplicate guards,
//   but introduced early EBP save and a different loop basin
// - serialized byte-cursor form: preserves the binary-observed base-name
//   access and offset-based count/list fields; frame remains 0x10 vs 0x14
// - function-scope pointer/counter declarations and virtual save ABI: no
//   emitted-code improvement; register-qualified counters were unchanged
// - ABI correction: removed the duplicate explicit vtable_ptr; the virtual
//   method now supplies the vptr, with effects at +0x04 and effect_num at +0x08
// - scoped nested-loop locals: improved diff to 236 and size to 256, but the
//   frame stayed 0x10 and the original guarded EBP/EBX topology did not return
// - outer effect/count locals and an explicit self pointer were unchanged
// - full effects.cpp virtual ABI (destructor, save, do_effect) emitted no change
// - named RGE_Effect record ownership and typed command-array access reached
//   the exact 0x14 frame and 0x109-byte body basin (224-byte diff)
// - named effect_list pointer plus byte cursor aligned the inner serialization
//   block; initializing inner before its guard recovered 99/99 instructions
// - reversing address terms, integer-address casts, declaration order, and a
//   named-name anchor did not change the final 2-byte SIB drift; all rolled back
// - typed current-record ownership removed both residual SIB bytes and
//   produced an exact match
// - Production TU validation exposed two SIB bytes from the former split
//   `effect`/`record` form.  Assigning `record` from `this->effects + index`
//   while keeping the base-name serialization bug restores grouped exactness.
// - Exact-finish walkbacks of the name expression, base calculation, and
//   record alias regressed grouped output by 201, 234, and 242 bytes.  Removing
//   the redundant `effect` alias kept the exact grouped and standalone result.
// - main review replaced the inner byte cursor with natural typed command
//   indexing; the function remains byte exact
// FLAGS: none
// NOTE: exact calls, frame, record layout, CFG, and serialization order are
// established. The typed effect[index] form also matches the oracle's SIB
// base/index order. The source keeps named ownership and the binary-proven
// base-name serialization bug; no raw-address diagnostic remains.

#include "../../include/effects_context.h"

void __cdecl rge_write(int fd, void* buf, int size);

void RGE_Effects::save(int fd) {
    long* num = &this->effect_num;
    RGE_Effect* record;
    int handle = fd;
    int index;

    rge_write(fd, num, 4);
    index = 0;
    if (*num > 0) {
        fd = 0;
        do {
            record = this->effects + index;
            rge_write(handle, this->effects->name, 0x1F);
            rge_write(handle, &record->effect_list_num, 2);
            int inner = 0;
            if (record->effect_list_num > 0) {
                do {
                    RGE_Effect_Command* command = &record->effect_list[inner];
                    rge_write(handle, &command->command, 1);
                    rge_write(handle, &command->change_num1, 2);
                    rge_write(handle, &command->change_num2, 2);
                    rge_write(handle, &command->change_num3, 2);
                    rge_write(handle, &command->change_amount, 4);
                    inner++;
                } while (inner < record->effect_list_num);
            }
            index++;
            fd += 0x2C;
        } while (index < this->effect_num);
    }
}
