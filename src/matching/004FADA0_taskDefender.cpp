// 004FADA0 TribeTacticalAIModule::taskDefender
// taitacmd.cpp:8935-8946, 260 bytes
//
// int __thiscall TribeTacticalAIModule::taskDefender(int param_1, int param_2, float param_3, int param_4)
// ret 10h cleanup (4 stack params + this in ecx)
//
// === Attempt log ===
// 1: Initial version - class layout structs, new[]/delete[], do-while search loop
//    Prologue OK through offset 13, but register cascade: countâ†’edx vs ecx
//    Search loop uses pointer arithmetic (add ecx,4) instead of indexed [edi+eax*4]
//    Edit diff: 97/260 (37.3%), positional diff: 213/260 (81.9%)
//    Text size: 272 vs 260 (12 bytes too big)
// 2: Variant lab confirms both do-while and while-break search styles produce identical code
//    Register allocation (countâ†’edx vs ecx) is the cascade root
// 3: Restored clean source before testing a reference-local ManagedArray surface.
// 4: Reference-local indexed scan/copy plus direct operator new/delete recovered the
//    original 260-byte CFG and array ownership; exact bytes now match.
// 5: The mission slot takes an int, with the proven short field promoted before the
//    call; the typed virtual surface and argument order also match exactly.
// Main-agent audit restored canonical AI/player destructor ownership, named
// sendUnitAIOrder, and natural new[]/delete[] growth; output remains exact.

#ifndef TAITACMD_SHARED_CONTEXT
struct ManagedArrayInt {
    int* value;      // +0x00: this+0xD58
    int numberValue;  // +0x04: this+0xD5C
    int desiredNumberValue;
    int maximumSizeValue; // +0x0C: this+0xD64
};

class RGE_Player {
public:
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
    virtual void sendUnitAIOrder(int a, int b, int c, int d, int e, float f, float g, float h, float i, int j, int k, int l);
    char _gap_04[70];
    short id;
};

class TribeMainDecisionAIModule {
public:
    virtual ~TribeMainDecisionAIModule();
    char _gap_04[0x0EC];
    RGE_Player* player;
};
class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    char _gap_04[0x0EC];
    TribeMainDecisionAIModule* md;
    char _gap_0F4[0x0D58 - 0x0F4];
    ManagedArrayInt unitsTaskedThisUpdate;

    int taskDefender(int param_1, int param_2, float param_3, int param_4);
};
#endif
int TribeTacticalAIModule::taskDefender(int param_1, int param_2, float param_3, int param_4)
{
    ManagedArrayInt& arr = this->unitsTaskedThisUpdate;
    int i;

    for (i = 0; i < arr.numberValue; i++) {
        if (i >= arr.maximumSizeValue)
            break;
        if (arr.value[i] == param_1)
            goto dispatch;
    }

    if (arr.numberValue > arr.maximumSizeValue - 1) {
        int newSize = arr.numberValue + 1;
        int* newVals = new int[newSize];
        if (newVals != 0) {
            int j;
            for (j = 0; j < arr.maximumSizeValue && j < newSize; j++) {
                newVals[j] = arr.value[j];
            }
            delete[] arr.value;
            arr.value = newVals;
            arr.maximumSizeValue = newSize;
        }
    }

    arr.value[arr.numberValue] = param_1;
    arr.numberValue++;

dispatch:
    // Mission dispatch through the typed player order surface.
    {
        RGE_Player* player = this->md->player;
        player->sendUnitAIOrder(
            (int)player->id,
            param_1,
            0x2BD,
            param_2,
            -1,
            -1.0f,
            -1.0f,
            -1.0f,
            param_3,
            1,
            0,
            param_4
        );
    }

    return 1;
}
