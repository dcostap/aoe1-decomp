#ifndef TAITACMD_SHARED_CONTEXT
// 004FA940 TribeTacticalAIModule::taskExplorer(int,float,float)
// taitacmd.cpp:8870-8891, 337 bytes
//
// Attempt log:
// - Replaced the decompiler-shaped two-list scaffold with the canonical
//   ManagedArray ownership and the neighboring taskExplorer overload's
//   natural indexed scan/growth form.  Baseline: exact size/frame/calls with
//   only two FPU operand-displacement bytes differing.
// - Probe 1: restored the natural XYPoint x/y argument order in the recursive
//   overload call; MATCH (337/337 bytes).  The source order accounts for VC5's
//   right-to-left evaluation and the observed y-then-x FPU pushes.
// - Final: default /O2 /Oy, typed local layout, no inline asm or codegen-only
//   scaffolding; exact bytes validated.

#ifndef TAITACMD_SHARED_CONTEXT
struct ManagedIntArray {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSize;
};

struct XYPoint {
    int x;
    int y;
};

class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    char gap_04[0xEC];
    void* md;
    ManagedIntArray civilians;
    char gap_104[0xD58 - 0x104];
    ManagedIntArray unitsTaskedThisUpdate;

    int taskExplorer(int param_1, int param_2);
    int taskExplorer(int param_1, float param_2, float param_3);
    int taskExplorer(int param_1, float param_2, float param_3, int param_4);
    int unexploredArea(int param_1, XYPoint& point);
};

#endif
int TribeTacticalAIModule::taskExplorer(int param_1, float param_2,
                                        float param_3)
{
    ManagedIntArray& arr = unitsTaskedThisUpdate;
    int i;

    for (i = 0; i < arr.numberValue; i++) {
        if (i >= arr.maximumSize)
            break;
        if (arr.value[i] == param_1)
            goto dispatch;
    }

    if (arr.numberValue > arr.maximumSize - 1) {
        int newSize = arr.numberValue + 1;
        int* newArray = new int[newSize];
        if (newArray != 0) {
            int j;
            for (j = 0; j < arr.maximumSize && j < newSize; j++) {
                newArray[j] = arr.value[j];
            }
            delete[] arr.value;
            arr.value = newArray;
            arr.maximumSize = newSize;
        }
    }

    arr.value[arr.numberValue] = param_1;
    arr.numberValue++;

dispatch:
    {
        ManagedIntArray& civiliansArray = civilians;
        int count = civiliansArray.numberValue;
        int j;
        for (j = 0; j < count; j++) {
            if (j >= civiliansArray.maximumSize)
                break;
            if (civiliansArray.value[j] == param_1) {
                XYPoint targetPoint;
                if (unexploredArea(param_1, targetPoint) == 1) {
                    return taskExplorer(param_1, (float)targetPoint.x,
                                        (float)targetPoint.y, 1);
                }
                return taskExplorer(param_1, param_2, param_3, 1);
            }
        }
    }

    return taskExplorer(param_1, param_2, param_3, 0);
}
#else
int TribeTacticalAIModule::taskExplorer(int param_1, float param_2,
                                        float param_3) {
    return 0;
}
#endif
