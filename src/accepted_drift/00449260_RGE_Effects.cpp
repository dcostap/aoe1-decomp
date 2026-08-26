// VA: 00449260 RGE_Effects::RGE_Effects(char* path)
// effects.cpp lines 68-129
// 478 bytes

// Attempt log:
// - Baseline retained the canonical 0x2C RGE_Effect / 0x0C command layout and
//   natural fscanf/calloc loops, but used a hand-written vtable field and the
//   command counter as the first %hd destination (552-byte output, extra scan).
// - Restored the period virtual RGE_Effects surface, reused the incoming path
//   home for the command opcode scan, kept a typed command pointer across the
//   inner fscanf, and used the positive effect-list guard.  The inner do-loop
//   still peeled into a duplicate scan, so the retained form is a top-tested
//   short loop (probe 003: 464-byte output, 85.45% shape).
// - Kept the positive fopen guard and opposite initial fscanf predicate so the
//   successful parse path falls through and the null/error paths are late.  A
//   separate fclose in each initial-fscanf arm restores all ten call sites.
//   Best current reconstruction is probe 009: 481-byte output, 100% ordered
//   call alignment, 97.60% shape, 241 strict differing bytes.
// - Tried a function-scope inner counter with the explicit do-loop (probe 010);
//   VC5 peeled/duplicated the scan and regressed to 526 bytes.  Restored the
//   probe-009 clean-source form before validation.
// - Tested the guarded infinite-loop form with a post-increment termination
//   test (probe 012); it added a duplicate fscanf, grew to 526 bytes, and was
//   restored.  The top-tested loop remains the best CFG.
// - Tried a natural early return for fopen failure to test conditional ESI
//   lifetime; it removed the late fclose call and worsened to 451 bytes, so it
//   was restored.
// - Remaining localized codegen gap: VC5 saves ESI in the prologue instead of
//   conditionally at the fopen-success edge, and loads effect_list_num into DX
//   before the inner guard where the oracle compares the field directly.  The
//   named ownership, widths, calls, CFG, and stack frame are otherwise aligned.
// - Reversed the inner bound to `effect_list_num > sVar7`; this is a natural
//   field-first spelling and restored the oracle's direct field compare.  It
//   reduced the strict diff from 241 to 47 bytes and the size gap to 1 byte.
// - Direct effect-list indexing, a typed count pointer, do-while spelling,
//   counter reset, donor declaration order, and function-scope command pointer
//   were tested.  The direct index/count-pointer/do-while forms regressed;
//   declaration order, reset, and command scope were emitted-code duplicates.
// - Best current source keeps the field-first top-tested loop.  Remaining
//   drift is conditional ESI save/restore and the loop back-edge compare
//   encoding; calls, frame, CFG count, and all named layout accesses align.
// - Normalized the command scan to its real short local. The former path-home
//   reuse passed a char** to %hd and was codegen scaffolding, not valid source.
// - Matching-worker pass: direct effect_num access, int/reference count aliases,
//   declaration-order changes, a combined fopen guard, counter-left top-tested
//   loops, and guarded do-while spelling were tested. Direct access and aliases
//   were codegen duplicates; counter-left forms added two bytes and changed the
//   loop basin; do-while added one fscanf call and 47 bytes. The clean natural
//   source remains the 479-byte basin with 47 strict differing bytes. The next
//   useful evidence is compiler/TU context or a source form that shrink-wraps
//   ESI without artificial register control; no such source form is retained.
// - Exact-finish continuation: fresh checks restored the clean source after
//   counter-left loop, negative fopen guard, explicit labels and returns,
//   narrow virtual surface, header order, reviewed game-global context, long
//   local widths, and a register-qualified count pointer.  The natural
//   counter-left loop regressed to 481 bytes and 241 differing bytes.  The
//   other forms were codegen duplicates at 479 bytes and 47 differing bytes.
//   No test changed the ten-call order, object layout, or partial-failure
//   stores.  Keep the clean parser until authentic effects.cpp TU evidence
//   explains the conditional ESI save.
// - Fresh captain probes: a scoped effect_num pointer was codegen-identical;
//   a counter-left inner loop grew to 481 bytes and 241 differing bytes; a
//   named current-effect pointer grew to 454 bytes with a 0x14 frame.  All
//   variants were restored to this natural 479-byte source basin.
// Context gate:
// - PROVED: PDB module is effects.cpp, with source span lines 68-129.
// - PROVED: source bands are fopen 68, initial scan 80, allocation 82,
//   outer loop 85-114, cleanup 119-129, in the original address sequence.
// - PROVED: owner is RGE_Effects::RGE_Effects(char*), with class size 0x0C.
// - PROVED: address sequence is 00449260-0044943D, with ten direct calls,
//   fields at +0x00, +0x04, and +0x08, and the named constructor symbol.
// - PROVED: exact TU anchors are the effects.cpp int constructor at 004490E0,
//   destructor at 00449440, save at 004494B0, and do_effect at 004495C0.
// - LIKELY: the natural typed parser is the original source family.
// - UNKNOWN: the historical compiler context that shrink-wraps the ESI save
//   and reverses the inner signed compare operands.
// ACCEPTED DRIFT: The rebuild saves ESI for all paths. The original saves it
// only after fopen succeeds. Both restore the incoming value before return.
// The parse body, frame, all 10 calls, destinations, stores, and failure paths
// match. The inner backedge only exchanges signed CMP operands and JL/JG.
// It tests the same short values and produces the same flags decision. This
// constructor has no SEH, and no call or memory effect changes order.

#include <stdio.h>
#include <stdlib.h>
#include "../../include/effects_context.h"

void convert_us(char* s);

RGE_Effects::RGE_Effects(char* path) {
    int local_4, index, count;

    FILE* fp = fopen(path, "r");
    if (fp != 0) {
        if (fscanf(fp, "%d %d", &effect_num, &local_4) != -1) {
            effects = (RGE_Effect*)calloc(effect_num, 0x2C);
            for (count = 0; count < local_4; count++) {
                short sVar7 = 0;
                fscanf(fp, "%d", &index);
                if (fscanf(fp, "%s %hd", effects[index].name, &effects[index].effect_list_num) == -1) break;
                effects[index].id = (short)index;
                if (effects[index].effect_list_num > 0) {
                    effects[index].effect_list = (RGE_Effect_Command*)calloc(effects[index].effect_list_num, 0x0C);
                    if (effects[index].effect_list_num > 0) {
                        while (effects[index].effect_list_num > sVar7) {
                            RGE_Effect_Command* command = &effects[index].effect_list[sVar7];
                            short command_num;
                            if (fscanf(fp, "%hd %hd %hd %hd %f", &command_num, &command->change_num1, &command->change_num2, &command->change_num3, &command->change_amount) == -1) break;
                            sVar7++;
                            command->command = (unsigned char)command_num;
                        }
                    }
                } else {
                    effects[index].effect_list = 0;
                }
                convert_us(effects[index].name);
            }
            fclose(fp);
        } else {
            effect_num = 0;
            effects = 0;
            fclose(fp);
        }
    } else {
        effect_num = 0;
        effects = 0;
    }
}
