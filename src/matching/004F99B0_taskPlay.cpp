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

#ifndef TAITACMD_SHARED_CONTEXT
struct Waypoint {
    float x;
    float y;
    char gap_08[8];
};

struct ManagedIntArray {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

class RGE_Static_Object;

struct RGE_Player {
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char);
    virtual void do_resign(int);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int);
    virtual int isEnemy(int);
    virtual int isAlly(int);
    virtual int isNeutral(int);
    virtual int isAllNeutral();
    virtual void setDiplomaticStance(int, int);
    virtual void loadAIInformation(char*, char*, char*, int, int);
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float, float, float, int, int, int);
    virtual void processAIOrder(int, int, int, int, int, float, float, float, float, int, int, int);
    virtual void kickAI(int);
    virtual int strategicNumber(int);
    virtual void sendGameOrder(RGE_Static_Object*, RGE_Static_Object*, float, float);
    virtual void sendAddWaypointCommand(int, void*, int);
    virtual void processAddWaypointCommand(int, void*, int);
    virtual void sendPlayCommand(int, int*, int, int, int);
    char gap_04[0x46];
    short id;
};

struct TribeMainDecisionAIModule {
    virtual ~TribeMainDecisionAIModule();
    char gap_04[0xEC];
    RGE_Player* player;
};

class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    char gap_04[0xEC];
    TribeMainDecisionAIModule* md;
    char gap_F4[0xD58 - 0xF4];
    ManagedIntArray unitsTaskedThisUpdate;

    int taskPlay(int param_1, int* param_2, int param_3, int param_4,
                 int param_5, Waypoint* waypoints, int waypointCount);
    void addWaypoint(int id, int x, int y);
};

#endif
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

    ManagedIntArray& arr = unitsTaskedThisUpdate;
    int i;
    for (i = 0; i < arr.numberValue; i++) {
        if (i >= arr.maximumSizeValue)
            break;
        if (arr.value[i] == param_1)
            goto dispatch;
    }

    if (arr.numberValue > arr.maximumSizeValue - 1) {
        int newSize = arr.numberValue + 1;
        int* newArray = new int[newSize];
        if (newArray != 0) {
            int j;
            for (j = 0; j < arr.maximumSizeValue && j < newSize; j++) {
                newArray[j] = arr.value[j];
            }
            delete[] arr.value;
            arr.value = newArray;
            arr.maximumSizeValue = newSize;
        }
    }

    arr.value[arr.numberValue] = param_1;
    arr.numberValue++;

dispatch:
    md->player->sendPlayCommand(param_1, param_2, param_3, param_4, param_5);
    return 1;
}
