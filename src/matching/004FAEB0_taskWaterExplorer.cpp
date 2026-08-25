// 004FAEB0 TribeTacticalAIModule::taskWaterExplorer (taitacmd.cpp:8951-8969, 266B)
// Records a unit ID as tasked this update, then dispatches to player.
// FLAGS: /nologo /c /O2 /Oy

void* __cdecl operator_new(unsigned int size);
void __cdecl operator_delete(void* ptr);

// ManagedArray<int> layout
#ifndef TAITACMD_SHARED_CONTEXT
struct ManagedArrayInt {
    int* value;          // +0x00
    int numberValue;     // +0x04
    int desiredValue;    // +0x08
    int maximumSizeValue;     // +0x0C
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
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float, float, float, int, int, int);
    char gap_04[0x46];
    short id;
};

struct TribeMainDecisionAIModule;

struct TribeTacticalAIModule {
    virtual ~TribeTacticalAIModule();
    char gap_00[0xEC];
    /* +0xF0 */ TribeMainDecisionAIModule* md;
    char gap_F4[0xD58 - 0xF4];
    /* +0xD58 */ ManagedArrayInt unitsTaskedThisUpdate;

    int taskWaterExplorer(int param_1);
};

struct MainDecisionAIModule {
    virtual ~MainDecisionAIModule();
    char gap_00[0xEC];
    /* +0xF0 */ RGE_Player* player;
};

struct TribeMainDecisionAIModule : MainDecisionAIModule {
    // player at +0xF0 from MainDecisionAIModule base
};

#endif
int TribeTacticalAIModule::taskWaterExplorer(int param_1) {
    if (param_1 == -1) {
        return 0;
    }

    ManagedArrayInt& arr = unitsTaskedThisUpdate;
    int i;
    for (i = 0; i < arr.numberValue; i++) {
        if (i >= arr.maximumSizeValue) break;
        if (arr.value[i] == param_1) goto done;
    }

    if (arr.numberValue > arr.maximumSizeValue - 1) {
        int newSize = arr.numberValue + 1;
        int* newArray = (int*)operator_new(newSize * 4);
        if (newArray != 0) {
            int j;
            for (j = 0; j < arr.maximumSizeValue && j < newSize; j++) {
                newArray[j] = arr.value[j];
            }
            operator_delete(arr.value);
            arr.value = newArray;
            arr.maximumSizeValue = newSize;
        }
    }

    arr.value[arr.numberValue] = param_1;
    arr.numberValue++;

done:
    {
        RGE_Player* player = md->player;
        player->sendUnitAIOrder((int)player->id, param_1, 0x2C1, -1, -1,
                                 -1.0f, -1.0f,
                                 -1.0f, 1.0f,
                                 1, 0, 1);
    }
    return 1;
}
