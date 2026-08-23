// VA: 004E7440 VictoryConditionRuleSystem::loadRules (394B)
// taistrmd.cpp
//
// Attempt log:
// baseline: natural VC5 stdio parser with the proven NONE/empty-name guards,
// temporary filename buffer, comment/directive filter, rule-index bounds check,
// and .tmp cleanup; frame was 0x108 and the only drift was stack topology.
// widened the named temp to 260 bytes, matching the observed temp+4/0x100
// fgets window and frame 0x10C; all calls, CFG, and table accesses aligned,
// leaving four bytes of sscanf byte-local scheduling drift.
// tried an explicit ruleIndex dword/byte overlay, a two-byte comment array,
// and several declaration/argument order variants. The closest two-byte
// variants reversed the parsed comment-byte tests or otherwise changed the
// natural local ownership; they were diagnostic only and were rolled back.
// this session: rechecked reversed declarations, combined declarations,
// local declaration order, loop-scoped byte locals, and all 2x2x2 combinations
// of byte declaration/sscanf destination/predicate order; no exact variant.
// new TU evidence: the decompiler's ruleIndex byte-overlay was tested with an
// int home and with a union byte view; VC5 coalesced the two tests into a word
// load and moved the first mismatch to +0x47 (190 bytes), so both forms were
// diagnostic only and were rolled back.
// this session: reversed declaration/output names while preserving first-byte
// predicate semantics; VC5 emitted the same four-byte local-order mismatch.
// this session: reversed predicate order or sscanf destination order independently
// reached the prior two-byte basin but swapped parsed-byte semantics; the full
// natural ordering matrix, erased-use, dword/byte overlay, and volatile-array
// probes did not produce an exact or plausible source. Restored clean.
// follow-up session: declaration-only changes were codegen duplicates. Original
// string-address constants plus natural byte mapping stayed at 4 bytes; reversing
// sscanf destinations reached the known 2-byte basin. Refs and hoisted pointers
// duplicated that basin. A direct int upper-byte overlay widened drift to 190.
// restored the clean typed parser; remaining drift is still the sscanf byte order.
// The best two-byte basin is still 2 bytes but semantically reverses the
// parsed-byte tests; keep the clean first-byte/second-byte source below.
// left in scratch: canonical behavior and frame/call topology match; the
// remaining difference is the original VC5 allocation/load order for the two
// sscanf comment-byte destinations (4 bytes, 1.0152%).
// this session: standalone and combined reversed char declarations, and moving
// ruleValue before the byte locals, all reproduced the same 4-byte mismatch.
// A two-byte array or named two-byte struct forced VC5 to use a word load and
// widened drift to 190 bytes; volatile byte reads widened the frame and drift.
// Reversed destination names kept the bytes but reversed parsed-byte behavior.
// Restored and validated the clean scalar parser; no natural exact source found.
// revisit: a nested second-byte scope, reversed scalar declarations, two separate
// one-byte wrapper objects, and a typed line-buffer union all emitted the same
// four-byte mismatch. A 256-sample neutral TU-declaration sweep also produced
// one VC5 basin with the same four-byte mismatch. Positive directive filtering
// and period stdio/string/io headers with FILE* were codegen duplicates.
// Restored the clean scalar parser; the remaining drift is the two sscanf byte
// destination homes, with no policy-compliant natural exact source found.
// current revisit: local declaration-order sweeps and separate one-byte arrays produced no new basin.
// First-byte and both-byte loop scopes also produced no new basin.
// Inner ruleValue/file scopes and explicit sscanf char-pointer casts produced no new basin.
// Equivalent predicate forms produced no new basin.
// Reversing only sscanf destinations or predicate byte order reached the diagnostic two-byte basin.
// Those forms reversed emitted byte tests relative to the original.
// Reversing both returned to the four-byte basin. No exact or policy-valid source was found.
// Restored the pinned scalar parser for final validation.
// ACCEPTED DRIFT: The four differing displacement bytes exchange the two
// adjacent one-byte stack homes used for sscanf's first and second `%c`
// outputs. Each later predicate follows its corresponding parsed byte, so the
// parsed values, tests, calls, writes, cleanup, and faults are equal. The two
// one-byte outputs cannot overlap, and all remaining bytes match.
// continuation audit: the authentic taistrmd_strategy_prefix wrapper remains the
// compiler context. All ten other grouped owners still validate as MATCH.
// Original CodeView homes are temp -0x100, ruleValue -0x104, ruleIndex -0x108,
// commentTemp2 -0x109, and commentTemp1 -0x10A. The clean source uses a 260-byte
// temp and two scalar byte locals to preserve the 0x10C frame and logical output
// order. Reversed declarations, reversed destinations, reversed predicates, a
// dead ruleIndex, and a byte overlay were rechecked in the grouped context.
// The destination-only basin swaps the parsed-byte predicates. The overlay changes
// the frame or emits a word load. No natural source preserves semantics and reaches
// the original four byte homes. Keep this accepted drift and its fault order.

extern "C" int __cdecl strcmp(const char* left, const char* right);
extern "C" unsigned int __cdecl strlen(const char* text);
extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);
extern "C" void* __cdecl fopen(const char* filename, const char* mode);
extern "C" char* __cdecl fgets(char* buffer, int count, void* stream);
extern "C" int __cdecl sscanf(const char* buffer, const char* format, ...);
extern "C" int __cdecl fclose(void* stream);
extern "C" char* __cdecl strstr(const char* text, const char* search);
extern "C" int __cdecl _unlink(const char* filename);

#pragma intrinsic(strcmp)
#pragma intrinsic(strlen)

#include "../../include/taistrmd_context.h"

int VictoryConditionRuleSystem::loadRules(char* filename)
{
    char commentTemp1;
    char commentTemp2;
    int ruleValue;
    char temp[260];
    void* file;

    if (strcmp(filename, "NONE") != 0 &&
        filename != 0 &&
        strlen(filename) != 0) {
        sprintf(temp + 4, "%s", filename);
        file = fopen(temp + 4, "r");
        if (file != 0) {
            while (fgets(temp + 4, 0x100, file) != 0) {
                sscanf(temp + 4, " %c%c",
                       &commentTemp1, &commentTemp2);
                if ((commentTemp1 != '/' || commentTemp2 != '/') &&
                    (commentTemp1 != 'D' || commentTemp2 != 'E') &&
                    (commentTemp1 != 'V' || commentTemp2 != 'C')) {
                    if (commentTemp1 == 'E' && commentTemp2 == 'N') {
                        break;
                    }
                    sscanf(temp + 4, "%d %d ",
                           &ruleValue, temp);
                    if (ruleValue >= 0 && ruleValue < 0xE2) {
                        this->sn[ruleValue] = *(int*)temp;
                    }
                }
            }
            fclose(file);
            if (strstr(filename, ".tmp") != 0) {
                _unlink(filename);
            }
            return 1;
        }
    }
    return 0;
}
