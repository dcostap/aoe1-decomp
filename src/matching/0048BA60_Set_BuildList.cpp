// 0048BA60 RGE_Scenario::Set_BuildList(int param_1, char* param_2, int param_3)
// Source: scenario.cpp lines 535-542
// Size: 107 bytes, 41 asm lines
//
// RGE_Scenario::Set_BuildList copies a string to BuildList[param_1], or clears the destination
// when param_2 is null, then conditionally sets byte at position strlen(param_2)-4 to 0 if
// param_3 == 1.
//
// Attempt log:
// - Initial scratch used strlen + memcpy. REP-string instructions were generated, but VC5 saved `this`,
//   computed &BuildList[param_1] after repne scasb, and emitted extra scheduling/no-op bytes (128-byte family).
// - SpruceGlow try 1: manual C loops for strlen/copy were much worse; lost compact rep-string family.
// - SpruceGlow tries 2-10: slot-before/after variants, len locals, raw void-slot arithmetic, index local,
//   hand byte-copy forms, and condition inversion were either compile-surface issues or stayed in worse scheduling families.
// - SpruceGlow try 11: explicit extern strlen/memcpy plus precomputed slot still worse.
// - SpruceGlow try 12 MATCH: natural `strcpy(*slot, param_2)` exposes the original compiler-recognized copy idiom.
//   VC5 lowers it to the exact repne scasb + rep movsd/movsb sequence with the slot LEA before the scan, and the
//   shared slot local preserves the null and param_3 tail shape.
// Result: MATCH locally with `python tools/check_function.py --va 0048BA60`.

extern "C" unsigned int __cdecl strlen(const char*);
extern "C" char* __cdecl strcpy(char*, const char*);

#ifndef SCENARIO_TU
class RGE_Scenario {
public:
    char gap_000[0x12C8];
    char* BuildList[16];

    void Set_BuildList(int param_1, char* param_2, int param_3);
};
#endif

void RGE_Scenario::Set_BuildList(int param_1, char* param_2, int param_3) {
    char** slot;

    if (param_2) {
        slot = &this->BuildList[param_1];
        strcpy(*slot, param_2);
    } else {
        slot = &this->BuildList[param_1];
        (*slot)[0] = 0;
    }

    if (param_3 == 1) {
        (*slot)[strlen(param_2) - 4] = 0;
    }
}
