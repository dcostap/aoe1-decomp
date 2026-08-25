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

#ifndef TAITACMD_SHARED_CONTEXT
struct ManagedIntArray {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

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
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float,
                                 float, float, int, int, int);
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

    int taskToEnter(int param_1, int param_2);
};

#endif
int TribeTacticalAIModule::taskToEnter(int param_1, int param_2)
{
    ManagedIntArray& arr = unitsTaskedThisUpdate;
    int i;

    if (param_1 == -1)
        return 0;

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
    {
        RGE_Player* player = md->player;
        player->sendUnitAIOrder(
            (int)player->id,
            param_1,
            0x2CD,
            param_2,
            (int)player->id,
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
