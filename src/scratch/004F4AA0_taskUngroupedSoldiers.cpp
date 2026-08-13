// Attempt log for 004F4AA0 TribeTacticalAIModule::taskUngroupedSoldiers
// Prior worker notes: a raw-offset scaffold rebuilt 736B vs 740B but used the
// wrong array ownership, object/finder shims, and manual removal/growth shape.
// The current reconstruction restores the same-TU typed ManagedArray surface,
// soldiers at +0x114, ungroupedSoldiers at +0x124, and informationAI at +0xCEC.
//
// Binary-backed oddities retained for this target:
// - the original passes the second dword of each local XYPoint to
//   findGatherPosition, as shown by the two LEAs and stack map;
// - the final moveUnit call consumes an uninitialized int local (the oracle has
//   an fild from the fixed -4 stack home with no preceding store).
//
// Claim sa-7675a699-r1 (10 meaningful hypotheses):
// - typed baseline aligned all 15 direct calls and the main array/object CFG,
//   but VC5 saved EDI at entry (760B, frame 0x18 vs 740B/0x1C).
// - >=60 elapsed spelling, split duplicate-scan labels, and donor-style
//   reference/pointer aliases were tested; the best emitted basin remains
//   501 strict-diff bytes / 83.83% shape with exact call-set parity.
// - explicit manual soldiers growth and volatile local_4 were rolled back as
//   broader/worse codegen. The remaining structural gap is the callee-save and
//   local-home topology: oracle uses EBX for the outer index, delays EDI save
//   until the positive soldiers-count arm, and reads local_4 from -4.
// shardA6 probe: moved a natural soldier-value load before the first ungrouped
// scan; this lost operator_new/operator_delete and two ordered calls, so it
// was rolled back to the clean typed source.
// BLOCKER: source/layout/callee-save topology remains unresolved; leave this
// clean typed reconstruction in scratch rather than retain codegen scaffolds.

#include <stdlib.h>

extern "C" {
    void* __cdecl operator_new(unsigned int size);
    void __cdecl operator_delete(void* block);
}

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
    int local_1c;
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
            local_1c = 0;
            if (0 < this->soldiers.numberValue) {
                ManagedArray<int>& soldiers = this->soldiers;
                do {
                    if (soldiers.maximumSizeValue - 1 < local_1c) {
                        soldiers.resize(local_1c + 1);
                    }

                    TacticalAIGroup* group =
                        this->groupUnitIsIn(soldiers.value[local_1c]);
                    if (group != 0) {
                        if (soldiers.maximumSizeValue - 1 < local_1c) {
                            soldiers.resize(local_1c + 1);
                        }
                        this->ungroupedSoldiers.remove(
                            soldiers.value[local_1c]);
                    }
                    else {
                        if (soldiers.maximumSizeValue - 1 < local_1c) {
                            soldiers.resize(local_1c + 1);
                        }
                        centerPoint.x = (int)this->md->object(
                            soldiers.value[local_1c]);
                        if (centerPoint.x != 0) {
                            if (soldiers.maximumSizeValue - 1 < local_1c) {
                                soldiers.resize(local_1c + 1);
                            }

                            ManagedArray<int>* ungrouped =
                                &this->ungroupedSoldiers;
                            i = 0;
                            if (0 < ungrouped->numberValue) {
                                do {
                                    if (ungrouped->maximumSizeValue <= i)
                                        break;
                                    if (ungrouped->value[i] ==
                                        soldiers.value[local_1c])
                                        goto next_soldier;
                                    i++;
                                } while (i < ungrouped->numberValue);
                            }

                            {
                                int soldier = soldiers[local_1c];
                                int ungroupedCount = ungrouped->numberValue;
                                if (0 < ungroupedCount) {
                                    i = 0;
                                    do {
                                        if (ungrouped->maximumSizeValue <= i)
                                            break;
                                        if (ungrouped->value[i] == soldier)
                                            goto find_position;
                                        i++;
                                    } while (i < ungroupedCount);
                                }

                                if (ungrouped->maximumSizeValue - 1 <
                                    ungroupedCount) {
                                    ungrouped->resize(ungroupedCount + 1);
                                }
                                ungrouped->value[ungrouped->numberValue] = soldier;
                                ungrouped->numberValue =
                                    ungrouped->numberValue + 1;

                            find_position:
                            {
                                int result =
                                    this->md->informationAI.findGatherPosition(
                                        *(XYPoint*)&centerPoint.y, 1, 1,
                                        this->sn[0x16], this->sn[0x48],
                                        (RGE_Static_Object*)centerPoint.x,
                                        *(XYPoint*)&gatherPoint.y);
                                if (result == 1) {
                                    if (soldiers.maximumSizeValue - 1 <
                                        local_1c) {
                                        soldiers.resize(local_1c + 1);
                                    }
                                    this->moveUnit(
                                        soldiers.value[local_1c],
                                        (float)gatherPoint.y,
                                        (float)local_4, 0x32);
                                }
                            }
                            }
                        }
                    }

                next_soldier:
                    local_1c = local_1c + 1;
                } while (local_1c < this->soldiers.numberValue);
            }
        }
    }
}
