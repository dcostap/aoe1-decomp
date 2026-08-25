#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
class XYPoint {
public:
    int x;
    int y;
};

#endif
class InformationAIModule {
public:
    char gap_00[0x1B0];
    int numberGatesValue;
    XYPoint minGatePosition[4];
    XYPoint maxGatePosition[4];
};

#ifndef TAIINFMD_PREFIX_CONTEXT
class TribeInformationAIModule : public InformationAIModule {
public:
    int insideGate(int param_1, int param_2, int param_3);
};
#endif

#endif
int TribeInformationAIModule::insideGate(int param_1, int param_2, int param_3) {
    int* p;
    int i;

    i = 0;
    if (param_1 > 0) {
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
                return 0;
            }
        }
    } else {
        return 0;
    }

found:
    return 1;
loop_fail:
    return 0;
early_fail:
    return 0;
}
