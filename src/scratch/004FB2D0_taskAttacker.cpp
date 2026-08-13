// VA: 004FB2D0 TribeTacticalAIModule::taskAttacker
// Source: taitacmd.cpp lines 9056-9125
// Attempt log:
// 1: initial packet/decompiler reconstruction with local stubs and inline ManagedArray<int> add.
// 2: rewrote early failure paths to shared fail label and corrected world pointer chain (+f0/+f0/+3c).
// 3: made attackerID parameter const to avoid early save in ebx; prologue now matches through first object lookup, but function became 1 byte short and fail block placed early.
// 4: replaced direct fail returns with result variable and done label; no placement change.
// 5: expanded RGE_Static_Object virtual surface so vf_10c call lands at vtable +0x10c.
// 6: corrected command id expression: original maps commandFlag==1 to 0x2d9, otherwise 0x2bc.
// 7: rewrote assigned-attacker duplicate scan using direct indexed array access; no size/codegen improvement.
// 8: verified object lookup chain now matches original +0xf0/+0xf0/+0x3c and first prologue matches after const attackerID.
// 9: remaining target-command branch still differs broadly; vtable +0x10c is fixed but stack argument scheduling and command vtable call are wrong.
// 10: final state compiles but check_function cannot compare because rebuilt .text is 544 bytes vs original configured 545; not accepted_drift-safe.
// 11: corrected the PDB ABI to int/float/float/int/int/Waypoint*/int/int/int, restored the
//     same-TU ManagedIntArray growth idiom, modeled md->player->world, and identified the
//     +0x10c call as the zero-argument weaponRange getter used by the 12-argument order call.
// 12: corrected the weaponRange slot count and moveUnit's float/float ABI after the
//     rebuilt call map exposed a +0x108 dispatch and two spurious __ftol calls.
// 13: hoisted the target pointer and target-branch scalar locals to the function
//     scope, matching the old-TU declaration style suggested by the PDB/decompiler.
// 14: moved the command selector ahead of target lookup as a liveness/scheduling
//     probe; the original reads commandFlag before the target dispatch setup.
// 15: retained the command selector after target validation but before distance
//     computation, isolating its scheduling point from the object lookup.
// 16: restored late command evaluation and moved the command local ahead of the
//     object locals to test declaration-order register coloring.
// 17: retained the binary-proven unitAI result as a typed local instead of testing
//     the call result directly, mirroring the donor-era declaration surface.
// 18: reordered the top-level locals to the decompiler's attacker/unitAI/target/int
//     sequence before the final validation checkpoint.
// 19: reversed the target/no-target branch order as a natural typed call-order probe;
//     it moved the no-target calls ahead of target lookup and worsened structural parity,
//     so the clean canonical branch order is restored.
// 20: explicit late command if/else after priority restored the original EBP attacker,
//     EAX target-ID, 545-byte size, and all call/relocation sites; only the no-target
//     distance temporary home differs (original [esp+20], rebuilt [esp+28]), diff 2.
// Final bounded state: the canonical typed reconstruction is retained in scratch.
// The ten-probe run established exact call count/targets, vslot 0x10c weaponRange,
// the 12-argument player order ABI, exact size, and a localized two-byte mismatch.

#include <stddef.h>

struct ManagedIntArray {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSize;
};

class RGE_Static_Object;
class RGE_Game_World;
class UnitAIModule;

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
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float,
                                 float, float, int, int, int);
    char gap_04[0x38];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short field_4A;
};

class RGE_Game_World {
public:
    RGE_Static_Object* object(int id);
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual void vB4();
    virtual void vB8();
    virtual void vBC();
    virtual void vC0();
    virtual void vC4();
    virtual void vC8();
    virtual void vCC();
    virtual void vD0();
    virtual void vD4();
    virtual void vD8();
    virtual void vDC();
    virtual void vE0();
    virtual void vE4();
    virtual void vE8();
    virtual void vEC();
    virtual float vF0();
    virtual float vF4();
    virtual float vF8();
    virtual float vFC();
    virtual float v100(RGE_Static_Object*);
    virtual float v104();
    virtual float v108();
    virtual float weaponRange();

    UnitAIModule* unitAI();
    float distance_to_object(RGE_Static_Object* other);
    float distance_to_position(float x, float y, float z);
};

class MainDecisionAIModule {
public:
    virtual ~MainDecisionAIModule();
    char gap_04[0xEC];
    RGE_Player* player;
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
};

struct Waypoint {
    float x;
    float y;
    int gap_08;
    int gap_0C;
};

class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    char gap_04[0xEC];
    TribeMainDecisionAIModule* md;
    char gap_F4[0xD58 - 0xF4];
    ManagedIntArray unitsTaskedThisUpdate;

    int taskAttacker(int attackerID, float x, float y, int targetID,
                     int arg5, Waypoint* waypoints, int waypointCount,
                     int arg8, int commandFlag);
    void addWaypoint(int unitID, int x, int y);
    int calculatePriority(float distance);
    int moveUnit(int id, float x, float y, int priority);
};

int TribeTacticalAIModule::taskAttacker(int attackerID, float x, float y,
                                        int targetID, int arg5,
                                        Waypoint* waypoints, int waypointCount,
                                        int arg8, int commandFlag)
{
    RGE_Static_Object* attacker;
    float distance;
    int priority;

    if (attackerID == -1) {
        return 0;
    }
    attacker = (RGE_Static_Object*)this->md->player->world->object(attackerID);
    if (attacker == 0 || attacker->unitAI() == 0) {
        return 0;
    }

    if (waypoints != 0 && waypointCount > 0) {
        do {
            this->addWaypoint(attackerID, (int)waypoints->x,
                              (int)waypoints->y);
            ++waypoints;
            --waypointCount;
        } while (waypointCount != 0);
    }

    if (targetID != -1) {
        RGE_Static_Object* target;
        target = (RGE_Static_Object*)this->md->player->world->object(targetID);
        if (target == 0) {
            return 0;
        }

        distance = attacker->distance_to_object(target);
        priority = this->calculatePriority(distance);
        int command;
        if (commandFlag == 1)
            command = 0x2D9;
        else
            command = 0x2BC;

        this->md->player->sendUnitAIOrder(
            (int)this->md->player->field_4A,
            attackerID,
            command,
            targetID,
            arg5,
            x,
            y,
            1.0f,
            attacker->weaponRange(),
            1,
            0,
            priority);
    } else {
        distance = attacker->distance_to_position(x, y, 1.0f);
        priority = this->calculatePriority(distance);
        this->moveUnit(attackerID, x, y, priority);
    }

    ManagedIntArray& arr = this->unitsTaskedThisUpdate;
    int i;
    for (i = 0; i < arr.numberValue; i++) {
        if (i >= arr.maximumSize)
            break;
        if (arr.value[i] == attackerID)
            return 1;
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

    arr.value[arr.numberValue] = attackerID;
    arr.numberValue++;
    return 1;
}
