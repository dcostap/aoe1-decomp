// VA: 004C1ED0 RGE_Static_Object::take_attribute_from_owner
// PDB source: stat_obj.cpp lines 772-779 (86 bytes, 36 asm lines)
// Default flags
//
// ACCEPTED_DRIFT: reviewed by Boss. Non-zero diff is limited to equivalent SIB
// base/index encodings for master+loop offsets: original emits [edi+eax+88],
// [ebp+eax+0], [esi+eax], while rebuilt emits [eax+edi+88], [eax+ebp],
// [eax+esi]. The accessed addresses are identical; call, stack cleanup, memory
// effects, loop bounds, and FPU value are unchanged. Remaining differences are
// one-byte branch-distance fallout and trailing alignment NOP.
// Earlier notes: retried offset+(int)master and char* offset variants; no improvement (char* regressed branch signedness).
// MidnightLily tries:
// - Baseline check confirmed 86/86 bytes, edit diff 8, first drift is SIB base/index at flag compare.
// - Try 1: cast offset regs to char* base terms for all three memory accesses; no codegen change.
// - Try 2: pointer locals for i/typeOffset/amountOffset forced unsigned `jb` loop branch and kept same SIB drift; worse.
// - Try 3: reversed subscript form for flag (`i[(unsigned char*)master+0x88]`); no codegen change.
// - Try 4: master held as an `int` local each iteration; no codegen change.
// - Try 5: per-access pointer temporaries (`flagp`, `typep`, `amountp`); optimized back to same codegen.
// - Try 6: temporary no-/Oy flag (`/O2` only) had no effect; removed flag file.
// - Try 7: volatile master pointer forced stack locals and wrong prologue, much worse; rolled back.
// - LemonLily pass: tried offset-as-pointer casts (`(char*)offset + master`), integer master locals, pointer-base locals, natural struct-array indexing, for/while loop spellings, commuted constant/order forms, and a pre-increment loop. Most optimized back to the same 8-edit-byte SIB/address-order basin; natural/preinc forms regressed register assignment and loop shape.
// - LemonLily flag probes: temporary /O1, /O2 without /Oy, /O2 /Os, /O2 /Ot, /Og /Oi, and /Ox did not match. /O1 and /Os regressed broadly; /Ot/Ox/Og and no-/Oy stayed in the same 8-edit-byte basin. No flag file kept.
// Blocker: VC5 consistently chooses the shorter [eax+offsetReg] SIB encoding for equivalent address expressions; source-level term/order/pointer probes did not recover original longer offsetReg-base encodings. This looks like a strong accepted_drift candidate: edit diff is only SIB base/index byte choices, three one-byte branch-distance shifts caused by the shorter encodings, and a trailing alignment nop; behavior and calls/stack/memory effects match.

#include "../../include/stat_obj_context.h"
#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
#define RGE_STAT_OBJ_SHARED_CONTEXT 1
#endif

void RGE_Static_Object::take_attribute_from_owner(void) {
    int i = 0;
    int typeOffset = 0x6A;
    int amountOffset = 0x70;
    do {
        RGE_Master_Static_Object* master = this->master_obj;
        if (*(unsigned char*)(i + (int)master + 0x88) == 2) {
            short attr = *(short*)(typeOffset + (int)master);
            if (attr >= 0) {
                this->owner->add_attribute_num(attr, -*(float*)(amountOffset + (int)master), 0);
            }
        }
        amountOffset += 4;
        i++;
        typeOffset += 2;
    } while (amountOffset < 0x7C);
}
