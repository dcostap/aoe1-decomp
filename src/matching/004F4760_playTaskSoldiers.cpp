// 004F4760 TribeTacticalAIModule::playTaskSoldiers
// Initial decomp from packet. Attempt log:
// 1: natural source from Ghidra; compiles, same 823-byte size, but broad mismatch (80.56% positional / 93.68% edit).
// 2: changed outer sn_a2 guard to explicit early-return form; no byte/codegen change.
// 3: moved i declaration/initialization later; no byte/codegen change.
// 4: probed a volatile frame pad to recover original 0x1A4 frame; unused volatile optimized away, no change; rolled back.
// 5: current main blocker is first hunk: rebuilt frame is 0x1A0 not 0x1A4 and zero local is hoisted before push edi.
// 6: first soldier loop also uses edi=i+1 and ebp as byte offset; original uses ebp as integer index and ebx as i+1/new max.
// 7: array growth/copy behavior and later call sequence are semantically represented, but local/register topology is still wrong.
// 8: restored the period ManagedArray operator[] growth/copy surface and the typed informationAI subobject; this is the clean structural probe.
// Prior liveness probes: a count-first assignment changed the whole basin; a
// named element pointer and declaration reorder were codegen duplicates.
// A side-effectful soldiers[i] capacity ensure followed by direct value access
// recovered the target's count/load/store interleave.
// unplayedSoldiers[51] fixed the frame but shifted the play-unit argument;
// rolled back. playUnits[51] preserves the binary's reserved leading output
// slot and 0x1A4 local window; exact 823-byte match.
// Exact: default /O2 /Oy, 823/823 bytes, 22/22 calls, no custom flags or inline asm.

#include <stdlib.h>

extern "C" {
    void* __cdecl operator_new(unsigned int size);
    void __cdecl operator_delete(void* ptr);
}

#ifndef TAITACMD_SHARED_CONTEXT
template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    T& operator[](int index) {
        if (index > this->maximumSizeValue - 1) {
            int new_size = index + 1;
            T* new_value = (T*)operator_new(new_size * sizeof(T));
            if (new_value != 0) {
                for (int i = 0;
                     i < this->maximumSizeValue && i < new_size;
                     i++) {
                    new_value[i] = this->value[i];
                }
                operator_delete(this->value);
                this->value = new_value;
                this->maximumSizeValue = new_size;
            }
        }
        return this->value[index];
    }
};

struct ObjectMemory {
    int id;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_04[0x34];
    float world_x;
    float world_y;
    float world_z;
};

class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[0x1CC];
    int playNumberValue;

    int type();
    void setType(int type);
    void setDesiredNumberUnits(int n);
    int addUnit(int unit, class TribeMainDecisionAIModule* md);
    void setSpecificCommander(int commander, class TribeMainDecisionAIModule* md);
    void setLocation(float x, float y, float z);
    void setGatherLocation(float x, float y, float z);
    void setRetreatLocation(float x, float y, float z);
    void setTarget(int target);
    void setAction(int action);
    void setInUse(int inUse);
    int task(class TribeTacticalAIModule* tactical,
             class TribeMainDecisionAIModule* md, int a, int b, int c);
};

class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0xEC];
};

class RGE_Game_World {
public:
    RGE_Static_Object* object(int id);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;
};

class MainDecisionAIModule : public AIModule {
public:
    RGE_Player* player;
    ManagedArray<int> objects;

    RGE_Static_Object* object(int id);
};

class InformationAIModule {
public:
    virtual ~InformationAIModule();
    char gap_04[0xEC];
};

class TribeInformationAIModule : public InformationAIModule {
public:
    ObjectMemory* objectToAttackWithPlay(int playerToAttack, int* unplayedSoldiers,
        int countUnplayedSoldiers, int* unplayedOut, int* playUnits,
        int* playCommander, int* playToRun);
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    char gap_104[0xCEC - 0x104];
    TribeInformationAIModule informationAI;
};

struct UnitData {
    int id;
    int data1;
    int data2;
    int data3;
    int data4;
    int data5;
};

class TacticalAIModule {
public:
    virtual ~TacticalAIModule();
    char gap_04[0xEC];
};

class TribeTacticalAIModule : public TacticalAIModule {
public:
    TribeMainDecisionAIModule* md;
    ManagedArray<int> civilians;
    ManagedArray<int> civilianExplorers;
    ManagedArray<int> soldiers;
    ManagedArray<int> ungroupedSoldiers;
    ManagedArray<int> boats;
    ManagedArray<int> warBoats;
    ManagedArray<int> fishingBoats;
    ManagedArray<int> tradeBoats;
    ManagedArray<int> transportBoats;
    ManagedArray<int> artifacts;
    int sn[226];
    UnitData gatherers[50];
    int numberGatherersValue;
    int desiredNumberGatherersValue;
    char groups[0x330];
    int groupIDValue;
    int numberGroupsValue;
    unsigned long lastGroupAttackTime;
    unsigned long lastGroupRebalanceTime;
    unsigned long lastAttackResponseTime;
    unsigned long lastBoatAttackResponseTime;
    unsigned long lastScalingUpdateValue;
    int numberBuildUpdatesSkipped;
    int randomizedAttackSeparationTime;
    ManagedArray<int> playersToAttack;

    void playTaskSoldiers(unsigned long param_1, unsigned long param_2);
    TacticalAIGroup* groupUnitIsIn(int unit);
    TacticalAIGroup* createGroup(int kind);
};
#endif

void TribeTacticalAIModule::playTaskSoldiers(unsigned long param_1,
                                              unsigned long param_2)
{
    int* target;
    int countUnplayedSoldiers;
    ObjectMemory* targetObj;
    int* numberPlayUnits;
    int playCommander;
    int playToRun;
    int unplayedSoldiers[50];
    // objectToAttackWithPlay receives element one; the binary reserves the
    // leading output word and the full 0xCC play-unit stack window.
    int playUnits[51];
    int i;

    ManagedArray<int>& soldiers = this->soldiers;

    if (this->sn[0xa2] != 0) {
        countUnplayedSoldiers = 0;
        i = 0;
        if (soldiers.numberValue > 0) {
            numberPlayUnits = unplayedSoldiers + 1;
            do {
                TacticalAIGroup* group =
                    this->groupUnitIsIn(soldiers[i]);
                if ((group == 0) || (group->type() != 100)) {
                    soldiers[i];
                    countUnplayedSoldiers++;
                    *numberPlayUnits = soldiers.value[i];
                    numberPlayUnits++;
                }
                i++;
            } while (i < soldiers.numberValue);
        }

        if (countUnplayedSoldiers != 0) {
            unplayedSoldiers[0] = -1;
            playCommander = 0;
            playToRun = -1;
            targetObj = this->md->informationAI.objectToAttackWithPlay(
                this->playersToAttack[0], unplayedSoldiers + 1,
                countUnplayedSoldiers, unplayedSoldiers, playUnits + 1,
                &playCommander, &playToRun);
            if (targetObj != 0) {
                RGE_Static_Object* playObj = this->md->object(playToRun);
                if (playObj != 0) {
                    TacticalAIGroup* group = this->createGroup(1);
                    if (group != 0) {
                        group->setType(100);
                        group->setDesiredNumberUnits(playCommander);
                        int n = 0;
                        if (playCommander > 0) {
                            target = playUnits + 1;
                            do {
                                group->addUnit(*target, this->md);
                                n++;
                                target++;
                            } while (n < playCommander);
                        }
                        group->setSpecificCommander(playToRun, this->md);
                        group->setLocation(playObj->world_x, playObj->world_y,
                                           playObj->world_z);
                        group->setGatherLocation(playObj->world_x,
                                                 playObj->world_y,
                                                 playObj->world_z);
                        group->setRetreatLocation(playObj->world_x,
                                                  playObj->world_y,
                                                  playObj->world_z);
                        group->setTarget(targetObj->id);
                        group->playNumberValue = unplayedSoldiers[0];
                        group->setAction(2);
                        group->setInUse(1);
                        group->task(this, this->md, 2, 1, 1);
                    }
                }
            }
        }
    }
}
