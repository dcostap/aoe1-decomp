// Attempt log for 004F4AA0 TribeTacticalAIModule::taskUngroupedSoldiers
// Prior worker notes: a raw-offset scaffold rebuilt 736B vs 740B but used the
// wrong array ownership, object/finder shims, and manual removal/growth shape.
// The current reconstruction restores the same-TU typed ManagedArray surface,
// soldiers at +0x114, ungroupedSoldiers at +0x124, and informationAI at +0xCEC.
//
// Binary-backed oddity retained for this target:
// - the final moveUnit call consumes an uninitialized int local. The oracle has
//   an fild from the fixed -4 stack home with no preceding store. The typed
//   source keeps that original behavior without an address cast.
//
// Claim sa-209e8cdc (21 meaningful hypotheses):
// - Probe 1 established a 760B raw-cast baseline with all 15 calls.
// - Probes 2-4 restored typed soldier objects and XYPoint references. They
//   reached the best 754B basin: 493 strict-diff bytes, 86.36% shape, 1C frame.
// - Probe 5 changed the soldiers alias to a pointer. It reached 757B and was
//   worse. Probe 6 used direct soldiers.value access and lost two allocations.
// - Probe 7 used a concrete ManagedArray_int. It stayed at the 757B basin.
// - Probe 8 used direct this->soldiers access. It reached 776B and drifted.
// - Probes 9-10 tested standard XYPoint fields and local object scope. They
//   stayed at the 757B basin. Probe 11 moved soldier loading before the scan.
//   It reached 751B but lost the original control-flow shape.
// - Probes 12-13 tested direct world_time spelling and an ungrouped reference.
//   Both were codegen duplicates of the best basin.
// - Probe 14 changed both scans to while loops. It reached 744B but changed
//   the frame to 20h and lost exact block islands.
// - Probe 15 repeated the soldier lifetime test with a function-scope local.
//   It stayed at the 751B basin. Probe 16 replaced one known class surface
//   with an explicit vptr. It was a codegen duplicate and was rejected by
//   policy. Probe 17 added math.h. It was a duplicate.
// - Probe 18 used operator[] for every soldier read. It reached 1229B and
//   added five allocation pairs. The observed resize call set requires the
//   explicit capacity touches in this source.
// - Probes 19-20 tested XYPoint declaration order and soldier declaration
//   order. They were duplicates or returned to the 751B basin.
// - Probe 21 restored the binary-supported uninitialized local_4 move. It
//   changed only two neutral bytes and remains the clean typed source.
// - The unresolved blocker is callee-save and local-home topology. The oracle
//   uses EBX for the outer index, delays EDI save until the positive arm, and
//   reads the fixed -4 home. No honest source probe recovered that basin.
//
// Main-agent pass, 2026-08-18:
// - Translation-unit tests with zero through twelve dummy predecessors and
//   exact idle/play/active predecessors emitted identical target bytes.
// - Replacing only the first ungrouped membership do-loop with the exact-donor
//   for-loop recovered the original EBX outer index and delayed EDI save. It
//   reduced the strict diff from 493 to 230 bytes.
// - Index-left capacity predicates recovered five original cmp/branch forms.
//   The best natural source is now 747/740 bytes, 15/15 ordered calls, exact
//   0x1C frame, 93.49% shape, 77.91% exact blocks, and 222 differing bytes.
// - The remaining seven-byte region is the second membership scan. VC5 turns
//   its natural cached-count do-loop into a pointer induction with one extra
//   conditional block. For/while, explicit-break, scope, pointer, and source
//   order variants either duplicate this basin or damage the frame and early
//   register allocation. Point/local declaration permutations are duplicates.
// BLOCKER: second-scan induction and point/local home ownership remain
// unresolved. Keep this clean typed reconstruction in scratch.

#include <stdlib.h>

struct XYPoint {
    int x;
    int y;
};

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
            T* new_value = new T[new_size];
            if (new_value != 0) {
                for (int i = 0;
                     i < this->maximumSizeValue && i < new_size;
                     i++) {
                    new_value[i] = this->value[i];
                }
                delete[] this->value;
                this->value = new_value;
                this->maximumSizeValue = new_size;
            }
        }
        return this->value[index];
    }

    int remove(T valueToRemove) {
        int i = 0;
        int max = this->maximumSizeValue;
        for (; i < max; ++i) {
            if (this->value[i] == valueToRemove)
                break;
        }
        if (i >= max)
            return 0;

        --max;
        if (i < max) {
            do {
                this->value[i] = this->value[i + 1];
                ++i;
            } while (i < this->maximumSizeValue - 1);
        }

        int n = this->numberValue - 1;
        this->numberValue = n;
        if (n < 0)
            this->numberValue = 0;
        return 1;
    }

    int resize(int new_size);
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    unsigned long world_time;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_04[0x34];
    float world_x;
    float world_y;
};

class TribeInformationAIModule {
public:
    virtual ~TribeInformationAIModule();
    int findGatherPosition(XYPoint& center, int desiredUnits, int flag,
                           int sn16, int sn48, RGE_Static_Object* object,
                           XYPoint& gather);
};

class MainDecisionAIModule {
public:
    virtual ~MainDecisionAIModule();
    char gap_04[0xEC];
    RGE_Player* player;

    RGE_Static_Object* object(int objectID);
    RGE_Static_Object* object(int objectID, int type, int objectClass,
                              int action, int hasOrderFilter,
                              int resourceClass, int resourceSubclass,
                              int state, int minHitPoints,
                              int civilization);
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    char gap_F4[0xCEC - 0xF4];
    TribeInformationAIModule informationAI;
};

class TacticalAIModule {
public:
    virtual ~TacticalAIModule();
    char gap_04[0xEC];
};

class TacticalAIGroup;

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
    char gap_51C[0xFA8 - 0x51C];
    unsigned long lastUngroupedSoldierTaskTime;

    TacticalAIGroup* groupUnitIsIn(int unit);
    void moveUnit(int unit, float x, float y, int priority);
    void taskUngroupedSoldiers();
};

void TribeTacticalAIModule::taskUngroupedSoldiers()
{
    int i;
    int j;
    XYPoint centerPoint;
    XYPoint gatherPoint;
    int local_4;

    unsigned long currentTime = this->md->player->world->world_time;
    if ((currentTime - this->lastUngroupedSoldierTaskTime) / 1000 >= 60) {
        this->lastUngroupedSoldierTaskTime = currentTime;
        RGE_Static_Object* object = this->md->object(
            -1, 0x6D, -1, -1, -1, -1, -1, -1, -1, -1);
        if (object != 0) {
            centerPoint.y = (int)object->world_x;
            gatherPoint.x = (int)object->world_y;
            i = 0;
            if (0 < this->soldiers.numberValue) {
                ManagedArray<int>& soldiers = this->soldiers;
                do {
                    if (i > soldiers.maximumSizeValue - 1) {
                        soldiers.resize(i + 1);
                    }

                    TacticalAIGroup* group =
                        this->groupUnitIsIn(soldiers.value[i]);
                    if (group != 0) {
                        if (i > soldiers.maximumSizeValue - 1) {
                            soldiers.resize(i + 1);
                        }
                        this->ungroupedSoldiers.remove(
                            soldiers.value[i]);
                    }
                    else {
                        if (i > soldiers.maximumSizeValue - 1) {
                            soldiers.resize(i + 1);
                        }
                        RGE_Static_Object* soldierObj =
                            this->md->object(soldiers.value[i]);
                        if (soldierObj != 0) {
                            if (i > soldiers.maximumSizeValue - 1) {
                                soldiers.resize(i + 1);
                            }

                            ManagedArray<int>* ungrouped =
                                &this->ungroupedSoldiers;
                            for (j = 0; j < ungrouped->numberValue; j++) {
                                if (j >= ungrouped->maximumSizeValue)
                                    break;
                                if (ungrouped->value[j] == soldiers.value[i])
                                    goto next_soldier;
                            }

                            {
                                int soldier = soldiers[i];
                                int ungroupedCount = ungrouped->numberValue;
                                if (0 < ungroupedCount) {
                                    j = 0;
                                    do {
                                        if (j >= ungrouped->maximumSizeValue)
                                            break;
                                        if (ungrouped->value[j] == soldier)
                                            goto find_position;
                                        j++;
                                    } while (j < ungroupedCount);
                                }

                                if (ungroupedCount >
                                    ungrouped->maximumSizeValue - 1) {
                                    ungrouped->resize(ungroupedCount + 1);
                                }
                                ungrouped->value[ungrouped->numberValue] = soldier;
                                ungrouped->numberValue =
                                    ungrouped->numberValue + 1;

                            find_position:
                            {
                                int result =
                                    this->md->informationAI.findGatherPosition(
                                        centerPoint, 1, 1,
                                        this->sn[0x16], this->sn[0x48],
                                        soldierObj, gatherPoint);
                                if (result == 1) {
                                    if (i > soldiers.maximumSizeValue - 1) {
                                        soldiers.resize(i + 1);
                                    }
                                    this->moveUnit(
                                        soldiers.value[i],
                                        (float)gatherPoint.y,
                                        (float)local_4, 0x32);
                                }
                            }
                            }
                        }
                    }

                next_soldier:
                    i = i + 1;
                } while (i < this->soldiers.numberValue);
            }
        }
    }
}
