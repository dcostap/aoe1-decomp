// 004FB8D0 TribeTacticalAIModule::taskToEnter
// taitacmd.cpp:9258-9281, 268 bytes
//
// Attempt log:
// - Baseline retained the canonical array/mission ownership but hand-shaped the
//   search and used explicit allocation helpers; it was 275 bytes and diverged
//   at the first post-guard array scan.
// - Probe 1: mirror the exact same-TU taskDefender/taskFollower
//   ManagedArray reference, indexed bounded for-loop, natural new[]/delete[],
//   and typed mission virtual surface.  Pending checker result.

struct ManagedIntArray {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSize;
};

struct MissionSubObject {
    virtual ~MissionSubObject();
    virtual void slot_04();
    virtual void slot_08();
    virtual void slot_0C();
    virtual void slot_10();
    virtual void slot_14();
    virtual void slot_18();
    virtual void slot_1C();
    virtual void slot_20();
    virtual void slot_24();
    virtual void slot_28();
    virtual void slot_2C();
    virtual int sendUnitAIOrder(int short_field, int unit_id, int cmd,
                                int a4, int a5, float x1, float y1,
                                float z1, float w1, int a10, int a11,
                                int a12) = 0;
    char gap_04[0x46];
    short field_4A;
};

struct TribeMainDecisionAIModule {
    virtual ~TribeMainDecisionAIModule();
    char gap_04[0xEC];
    MissionSubObject* missionObj;
};

class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    char gap_04[0xEC];
    TribeMainDecisionAIModule* md;
    char gap_F4[0xD58 - 0xF4];
    ManagedIntArray unitsTasked;

    int taskToEnter(int param_1, int param_2);
};

int TribeTacticalAIModule::taskToEnter(int param_1, int param_2)
{
    ManagedIntArray& arr = unitsTasked;
    int i;

    if (param_1 == -1)
        return 0;

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
        MissionSubObject* obj = md->missionObj;
        obj->sendUnitAIOrder(
            (int)obj->field_4A,
            param_1,
            0x2CD,
            param_2,
            (int)obj->field_4A,
            -1.0f,
            -1.0f,
            -1.0f,
            1.0f,
            1,
            0,
            100
        );
    }

    return 1;
}
