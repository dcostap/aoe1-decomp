// VA: 004E0F40 TribeInformationAIModule::insideGate (77B)
// give-up/pause after >10 focused attempts
// tried explicit index loop, decompiler-style pointer walk, positive-vs-negative compare spellings,
// separate early-fail vs loop-fail tails, goto/break/continue/do-while variants, and focused brute-force template sweeps
// 2026-05-04 retry improved the basin materially: the retained source below now matches the full loop body and the late no-match return block
// (`jle` success at the last compare, then `inc/add/cmp/jl`, then `xor eax; pop edi; pop esi; ret 0Ch`).
// remaining drift is only tail ownership/layout:
// - original keeps a distinct early-fail zero-return after the success block (`pop edi; pop esi; xor eax; ret 0Ch`)
// - rebuilt collapses early-fail onto the loop-fail block and emits the success epilogue as `pop edi; pop esi; mov eax,1; ret 0Ch`
// latest retained check_function: positional diff 14 / edit diff 12 / first mismatch offset 11.

class XYPoint {
public:
    int x;
    int y;
};

class InformationAIModule {
public:
    char gap_00[0x1B0];
    int numberGatesValue;
    XYPoint minGatePosition[4];
    XYPoint maxGatePosition[4];
};

class TribeInformationAIModule : public InformationAIModule {
public:
    int insideGate(int param_1, int param_2, int param_3);
};

int TribeInformationAIModule::insideGate(int param_1, int param_2, int param_3) {
    int* p;
    int i;
    int result;

    i = 0;
    if (param_1 <= 0) {
        goto loop_fail;
    }
    p = &this->minGatePosition[0].y;
    while (1) {
        if (!(((XYPoint*)(p - 1))->x > param_2 ||
              *p > param_3 ||
              param_2 > p[7] ||
              param_3 > p[8])) {
            goto found;
        }
        i = i + 1;
        p = p + 2;
        if (i >= param_1) {
            goto loop_fail;
        }
    }

found:
    result = 1;
    return result;

loop_fail:
    result = 0;
    return result;
}
