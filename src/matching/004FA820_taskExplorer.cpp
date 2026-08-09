// 004FA820 TribeTacticalAIModule::taskExplorer
// taitacmd.cpp:8844-8865, 278 bytes
//
// Attempt log:
// - Baseline retained the canonical array and task-dispatch behavior but used
//   a hand-shaped count/capacity scan; it was 282 bytes and diverged at the
//   first bounded-array test.
// - Probe 1: mirror the exact same-TU taskDefender/taskToEnter
//   ManagedArray reference and natural indexed scan/growth source, while
//   retaining the typed unexplored-area and float taskExplorer overloads.
//   Pending checker result.

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
    char gap_F4[0xD58 - 0xF4];
    ManagedIntArray unitsTasked;

    int taskExplorer(int param_1, int param_2);
    int taskExplorer(int param_1, float param_2, float param_3, int param_4);
    int unexploredArea(int param_1, XYPoint* point);
};

int TribeTacticalAIModule::taskExplorer(int param_1, int param_2)
{
    ManagedIntArray& arr = unitsTasked;
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
    if (param_2 == 1) {
        XYPoint targetPoint;
        if (unexploredArea(param_1, &targetPoint) == 1) {
            return taskExplorer(param_1, (float)targetPoint.x,
                                (float)targetPoint.y, 1);
        }
        return taskExplorer(param_1, -1.0f, -1.0f, 1);
    }

    return taskExplorer(param_1, -1.0f, -1.0f, 0);
}
