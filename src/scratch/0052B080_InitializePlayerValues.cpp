// 0052B080 T_Scenario::InitializePlayerValues (tscenaro.cpp:260-277)
// 123 bytes, 40 asm lines
// Default flags
//
// Attempt log:
// Existing scratch had many prior attempts; retry notes 2026-05-18:
// 1: Revalidated existing pre-increment/pointer-walk form: default /O2 /Oy size-short, configured 123 exceeds .text 96.
// 2: Rewrote directly from Ghidra as piVar1/piVar2/iVar3 loop with final PlType[0]=1; improved default size to 112 but still size-short.
// 3: Introduced explicit p=piVar2-2 temp to encourage original EBP=p block pointer; no size/topology improvement.
// 4: Probed /O2 /Oy /Og-: exact 123 but wrong /Od-like EBP-frame basin, 88.6179% positional from offset 0; removed flag.
// 5: Probed /O2 /Oy /Op: still size-short 112; removed flag.
// 6: Probed /O2 /Oy /G5: still size-short 112; removed flag.
// 7: Probed /O2 /Oy /G6: still size-short 112; removed flag.
// 8: Probed /O1 /Oy: size-short 94; removed flag.
// 9: Replaced field-array member access with raw offsets 0x18CC/0x1998; no size/topology change.
// 10: Added explicit saved pointer/zero locals and reordered pointer increments before stores to mirror original; still size-short 112 under default.
// GIVEUP: no accepted_drift. Default optimized build is size-short, and exact-size diagnostic /Og- is broad from offset 0. Current source preserves broad initialization behavior but cannot reproduce original push-ecx/saved-pointer/register-heavy loop shape.

class RGE_Scenario {
public:
    char gap_000[0x18CC];
    int fields_188C[16];
    int PlType[16];
    int PlCivilization[16];
    int PlActive[16];
    char gap_198C[4];
    int player_res[16 * 4];
    char gap_1A90[0x4BA8 - 0x1A90];
    int far_fields_1[16];
    char gap_4BE8[0x5100 - 0x4BE8];
    int far_fields_2[16];
};

class T_Scenario : public RGE_Scenario {
public:
    void InitializePlayerValues();
};

void T_Scenario::InitializePlayerValues() {
    int* saved;
    int* piVar1;
    int* piVar2;
    int iVar3;
    int zero;

    saved = (int*)((char*)this + 0x18CC);
    zero = 0;
    iVar3 = 0;
    piVar1 = saved;
    piVar2 = (int*)((char*)this + 0x1998);
    do {
        int* p = piVar2 - 2;
        iVar3 = iVar3 + 1;
        piVar2 = piVar2 + 4;
        piVar1 = piVar1 + 1;
        p[0] = zero;
        p[1] = zero;
        p[2] = zero;
        p[3] = zero;
        piVar1[0x1f] = zero;
        p[0] = zero;
        p[1] = 200;
        p[2] = 200;
        p[3] = 0x96;
        piVar1[-1] = zero;
        piVar1[0xf] = iVar3;
        piVar1[-0x11] = 4;
        piVar1[0xcb6] = zero;
        piVar1[0xe0c] = zero;
    } while (iVar3 < 0x10);
    *saved = 1;
}
