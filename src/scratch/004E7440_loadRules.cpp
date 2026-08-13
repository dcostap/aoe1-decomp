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
// The best two-byte basin is still 2 bytes but semantically reverses the
// parsed-byte tests; keep the clean first-byte/second-byte source below.
// left in scratch: canonical behavior and frame/call topology match; the
// remaining difference is the original VC5 allocation/load order for the two
// sscanf comment-byte destinations (4 bytes, 1.0152%).

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

class VictoryConditionRuleSystem {
public:
    virtual ~VictoryConditionRuleSystem();
    int sn[226];

    int loadRules(char* filename);
};

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
