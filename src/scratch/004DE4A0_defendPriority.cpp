// 004DE4A0 defendPriority
// TribeInformationAIModule::defendPriority(int param_1, int param_2)
// Source: taiinfmd.cpp lines 4579-4607
// Size: 204 bytes
//
// Status: PARKED - VC5 dispatch structure / encoding drift
//
// Attempt log:
// Probe 1: switch(case) + tactical local — CSE hoisted md load to top,
//   shared call tail. 65.7% positional diff.
// Probe 2: inline cast expression in each case — same CSE.
// Probe 3: static helper fn — actually made external call (worse).
// Probe 4: proper member access md->tacticalAI.strategicNumber() — same CSE.
// Probe 5: if/else if chain — SELF-CONTAINED HANDLERS! Each handler has:
//   mov ecx, [ecx+100h]; push val; add ecx, 0x1146C; call; ret 8
//   (matching original handler pattern exactly)
//   Remaining: if/else dispatch vs switch/jump-table, add vs sub encoding,
//   test/jne vs direct je for equality checks.
//
// Key findings:
// - `switch` causes CSE (shared tail), `if/else` keeps handlers independent
// - md at +0x100, tacticalAI at +0x1146C in TribeMainDecisionAIModule
// - strategicNumber is non-virtual, direct call
// - param_1 cases: 0x2D→0x46, 0x6D→0x38, 0x9E/0xA3→0x36, 0x9F→0x37
// - param_2: 7→0x34, 8→0x33, 0x20→0x32, else -1
//
// Remaining drift (VC5 TU-context):
// - if/else dispatch (cmp/jne chain) vs switch jump table (sub+byte+table)
// - add eax,-7 / test/jne vs sub eax,7 / je encoding
// - case handler order differs from original
// No custom flags, no inline asm.

struct AIModule {
    virtual void dummy();
};

struct InformationAIModule : public AIModule {
    char pad_EC[0xEC]; // 0xF0 - 4 (vptr)
};

class TribeTacticalAIModule {
public:
    int strategicNumber(int val);
};

class TribeMainDecisionAIModule; // opaque

struct TribeInformationAIModule : public InformationAIModule {
    char farmsPad[0x10]; // ManagedArray<int> farmsTaskedThisUpdate at +0xF0
    TribeMainDecisionAIModule* md; // +0x100

    int defendPriority(int param_1, int param_2);
};

int TribeInformationAIModule::defendPriority(int param_1, int param_2)
{
    if (param_1 == 0x2D)
        return ((TribeTacticalAIModule*)((char*)md + 0x1146C))->strategicNumber(0x46);
    if (param_1 == 0x6D)
        return ((TribeTacticalAIModule*)((char*)md + 0x1146C))->strategicNumber(0x38);
    if (param_1 == 0x9E || param_1 == 0xA3)
        return ((TribeTacticalAIModule*)((char*)md + 0x1146C))->strategicNumber(0x36);
    if (param_1 == 0x9F)
        return ((TribeTacticalAIModule*)((char*)md + 0x1146C))->strategicNumber(0x37);

    int t = param_2;
    t -= 7;
    if (t == 0)
        return ((TribeTacticalAIModule*)((char*)md + 0x1146C))->strategicNumber(0x34);
    t--;
    if (t == 0)
        return ((TribeTacticalAIModule*)((char*)md + 0x1146C))->strategicNumber(0x33);
    t -= 0x18;
    if (t == 0)
        return ((TribeTacticalAIModule*)((char*)md + 0x1146C))->strategicNumber(0x32);
    return -1;
}
