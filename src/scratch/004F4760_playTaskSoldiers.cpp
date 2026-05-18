// 004F4760 TribeTacticalAIModule::playTaskSoldiers
// Initial decomp from packet. Attempt log:
// 1: natural source from Ghidra; compiles, same 823-byte size, but broad mismatch (80.56% positional / 93.68% edit).
// 2: changed outer sn_a2 guard to explicit early-return form; no byte/codegen change.
// 3: moved i declaration/initialization later; no byte/codegen change.
// 4: probed a volatile frame pad to recover original 0x1A4 frame; unused volatile optimized away, no change; rolled back.
// 5: current main blocker is first hunk: rebuilt frame is 0x1A0 not 0x1A4 and zero local is hoisted before push edi.
// 6: first soldier loop also uses edi=i+1 and ebp as byte offset; original uses ebp as integer index and ebx as i+1/new max.
// 7: array growth/copy behavior and later call sequence are semantically represented, but local/register topology is still wrong.
// GIVEUP: left in scratch; needs source-shape/TU-context work to force original frame/local allocation and i/newMax register basin.

extern void* __cdecl operator_new(unsigned int size);
extern void __cdecl operator_delete(void* ptr);

struct IntArray {
    int* value;
    int numberValue;
    int unknown08;
    int maximumSizeValue;
};

class TacticalAIGroup {
public:
    char gap_000[0x1D0];
    int playNumberValue;

    int type();
    void setType(int type);
    void setDesiredNumberUnits(int n);
    int addUnit(int unit, void* md);
    void setSpecificCommander(int commander, void* md);
    void setLocation(float x, float y, float z);
    void setGatherLocation(float x, float y, float z);
    void setRetreatLocation(float x, float y, float z);
    void setTarget(int target);
    void setAction(int action);
    void setInUse(int inUse);
    int task(void* tactical, void* md, int a, int b, int c);
};

struct RGE_Static_Object {
    char gap_00[0x38];
    float world_x;
    float world_y;
    float world_z;
};

class MainDecisionAIModule {
public:
    char gap_000[0x0F0];
    void* missionObj;

    RGE_Static_Object* object(int id);
};

class TribeInformationAIModule {
public:
    char gap_000[0x0CEC];
    RGE_Static_Object* objectToAttackWithPlay(int playerToAttack, int* unplayedSoldiers,
        int countUnplayedSoldiers, int* unplayedOut, int* playUnits,
        int* playCommander, int* playToRun);
};

class TribeTacticalAIModule {
public:
    char gap_000[0x0F0];
    MainDecisionAIModule* md;
    char gap_0F4[0x114 - 0x0F4];
    IntArray soldiers;
    char gap_124[0x41C - 0x124];
    int sn_a2;
    char gap_420[0x0D28 - 0x420];
    IntArray playersToAttack;

    void playTaskSoldiers(unsigned long param_1, unsigned long param_2);
    TacticalAIGroup* groupUnitIsIn(int unit);
    TacticalAIGroup* createGroup(int kind);
};

void TribeTacticalAIModule::playTaskSoldiers(unsigned long param_1, unsigned long param_2)
{
    int countUnplayedSoldiers;
    int* target;
    int numberPlayUnits;
    int playCommander;
    int playToRun;
    int unplayedSoldiers[50];
    int playUnits[50];

    if (this->sn_a2 == 0) {
        return;
    }

    {
        int i;
        target = 0;
        countUnplayedSoldiers = 0;
        i = 0;
        if (this->soldiers.numberValue > 0) {
            numberPlayUnits = (int)(unplayedSoldiers + 1);
            do {
                if (i > this->soldiers.maximumSizeValue - 1) {
                    int newMax = i + 1;
                    int* newArray = (int*)operator_new(newMax * 4);
                    if (newArray != 0) {
                        int j = 0;
                        if (this->soldiers.maximumSizeValue > 0) {
                            do {
                                if (j >= newMax) break;
                                newArray[j] = this->soldiers.value[j];
                                j++;
                            } while (j < this->soldiers.maximumSizeValue);
                        }
                        operator_delete(this->soldiers.value);
                        this->soldiers.value = newArray;
                        this->soldiers.maximumSizeValue = newMax;
                    }
                }

                TacticalAIGroup* g = this->groupUnitIsIn(this->soldiers.value[i]);
                if (g == 0 || g->type() != 100) {
                    if (i > this->soldiers.maximumSizeValue - 1) {
                        int newMax2 = i + 1;
                        int* newArray2 = (int*)operator_new(newMax2 * 4);
                        if (newArray2 != 0) {
                            int k = 0;
                            if (this->soldiers.maximumSizeValue > 0) {
                                do {
                                    if (k >= newMax2) break;
                                    newArray2[k] = this->soldiers.value[k];
                                    k++;
                                } while (k < this->soldiers.maximumSizeValue);
                            }
                            operator_delete(this->soldiers.value);
                            this->soldiers.value = newArray2;
                            this->soldiers.maximumSizeValue = newMax2;
                        }
                    }
                    target = (int*)((int)target + 1);
                    *(int*)numberPlayUnits = this->soldiers.value[i];
                    numberPlayUnits += 4;
                }
                i++;
                countUnplayedSoldiers = (int)target;
            } while (i < this->soldiers.numberValue);
        }

        if (countUnplayedSoldiers != 0) {
            unplayedSoldiers[0] = -1;
            playCommander = 0;
            playToRun = -1;
            if (this->playersToAttack.maximumSizeValue - 1 < 0) {
                int* newPlayers = (int*)operator_new(4);
                if (newPlayers != 0) {
                    int m = 0;
                    if (this->playersToAttack.maximumSizeValue > 0) {
                        do {
                            if (m >= 1) break;
                            newPlayers[m] = this->playersToAttack.value[m];
                            m++;
                        } while (m < this->playersToAttack.maximumSizeValue);
                    }
                    operator_delete(this->playersToAttack.value);
                    this->playersToAttack.value = newPlayers;
                    this->playersToAttack.maximumSizeValue = 1;
                }
            }

            RGE_Static_Object* targetObj = ((TribeInformationAIModule*)this->md)->objectToAttackWithPlay(
                this->playersToAttack.value[0], unplayedSoldiers + 1, countUnplayedSoldiers,
                unplayedSoldiers, playUnits + 1, &playCommander, &playToRun);
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
                        group->setLocation(playObj->world_x, playObj->world_y, playObj->world_z);
                        group->setGatherLocation(playObj->world_x, playObj->world_y, playObj->world_z);
                        group->setRetreatLocation(playObj->world_x, playObj->world_y, playObj->world_z);
                        group->setTarget(*(int*)targetObj);
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
