// 004F99B0 TribeTacticalAIModule::taskPlay
// taitacmd.cpp:8231-8251, 281 bytes
//
// Attempt log:
// - Baseline used waypoint and count temporaries plus a hand-shaped array
//   scan; it was 285 bytes and first diverged while loading the waypoint
//   parameter.
// - Probe 1: use the incoming waypoint/count parameters directly in the
//   natural do/decrement loop, then mirror the exact same-TU ManagedArray
//   scan/growth source and typed mission virtual surface.  Pending checker
//   result.

struct Waypoint {
    float x;
    float y;
    char gap_08[8];
};

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
    virtual void slot_30();
    virtual void slot_34();
    virtual void slot_38();
    virtual void slot_3C();
    virtual void slot_40();
    virtual void slot_44();
    virtual void slot_48();
    virtual void play(int id, int* object, int x, int y, int z) = 0;
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

    int taskPlay(int param_1, int* param_2, int param_3, int param_4,
                 int param_5, Waypoint* waypoints, int waypointCount);
    void addWaypoint(int id, int x, int y);
};

int TribeTacticalAIModule::taskPlay(int param_1, int* param_2, int param_3,
                                    int param_4, int param_5,
                                    Waypoint* waypoints, int waypointCount)
{
    if (waypoints != 0 && waypointCount > 0) {
        do {
            addWaypoint(param_1, (int)waypoints->x, (int)waypoints->y);
            waypoints++;
            waypointCount--;
        } while (waypointCount != 0);
    }

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
    md->missionObj->play(param_1, param_2, param_3, param_4, param_5);
    return 1;
}
