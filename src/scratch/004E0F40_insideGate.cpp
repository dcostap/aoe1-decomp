// tried explicit index loop with min/max comparisons; mismatch moved to prolog/register basin
// tried the decompiler-style pointer walk; got close, but VC5 still reordered the early gate and loop-exit comparisons
// remaining gap: prolog starts with different register setup and the loop/branch order still differs from the oracle
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

    if (param_1 <= 0) {
        return 0;
    }

    p = &this->minGatePosition[0].y;
    for (i = 0; i < param_1; i = i + 1) {
        if ((((XYPoint*)(p + -1))->x <= param_2) && (*p <= param_3) && (param_2 <= p[7]) && (param_3 <= p[8])) {
            return 1;
        }
        p = p + 2;
    }

    return 0;
}
