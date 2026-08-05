// VA: 004FE950 TribeTacticalAIModule::fillBoatGroups
// Attempt log:
// baseline: natural period-plausible reconstruction using the real group list,
// ManagedArray<int> workingArea ownership, and the three boat-filling passes.
// Bounded pass: restored the group-sentinel walk, commander assignment for
// empty/nonempty boat groups, workingArea growth/removal, three type-based fill
// passes, nearest-unit selection, and excess-unit redistribution. Declaration,
// loop, predicate, count-cache, and selection-tail probes did not recover the
// original physical block order. Final validation is 2924/2959 bytes with the
// exact 0x18 frame and exact 103-call target multiset, but only 87.38% ordered
// alignment; the remaining issue is broad CFG placement around the best-unit
// loop and transition back to the group list, not a codegen-only local axis.

extern void* operator new(unsigned int);
extern void operator delete(void*);

struct ManagedArrayInt {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    int& operator[](int index) {
        if (index > this->maximumSizeValue - 1) {
            int newSize = index + 1;
            int* newValue = (int*)operator new(newSize * 4);
            if (newValue != 0) {
                int j = 0;
                while (j < this->maximumSizeValue && j < newSize) {
                    newValue[j] = this->value[j];
                    ++j;
                }
                operator delete(this->value);
                this->value = newValue;
                this->maximumSizeValue = newSize;
            }
        }
        return this->value[index];
    }
};

class TribeMainDecisionAIModule;

struct Waypoint {
    float x;
    float y;
    float z;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_04[0x34];
    float world_x;
    float world_y;
    float world_z;

    float distance_to_position(float x, float y, float z);
};

class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    TacticalAIGroup* next;
    TacticalAIGroup* prev;
    char gap_0C[0x324];

    int type() const;
    int commander() const;
    int numberUnits() const;
    int desiredNumberUnits() const;
    int action() const;
    Waypoint* gatherLocation() const;
    int addUnit(int unit, TribeMainDecisionAIModule* md);
    void setSpecificCommander(int commander, TribeMainDecisionAIModule* md);
};

class TribeMainDecisionAIModule {
public:
    RGE_Static_Object* object(int id);
};

struct UnitData {
    int id;
    int data1;
    int data2;
    int data3;
    int data4;
    int data5;
};

class TribeTacticalAIModule {
public:
    char gap_000[0xF0];
    TribeMainDecisionAIModule* md;
    ManagedArrayInt civilians;
    ManagedArrayInt civilianExplorers;
    ManagedArrayInt soldiers;
    ManagedArrayInt ungroupedSoldiers;
    ManagedArrayInt boats;
    ManagedArrayInt warBoats;
    ManagedArrayInt fishingBoats;
    ManagedArrayInt tradeBoats;
    ManagedArrayInt transportBoats;
    ManagedArrayInt artifacts;
    int strategicNumbers[226];
    UnitData gatherers[50];
    int numberGatherersValue;
    int desiredNumberGatherersValue;
    TacticalAIGroup groups;
    int groupIDValue;
    int numberGroupsValue;
    unsigned long lastGroupAttackTime;
    unsigned long lastGroupRebalanceTime;
    unsigned long lastAttackResponseTime;
    unsigned long lastBoatAttackResponseTime;
    unsigned long lastScalingUpdateValue;
    int numberBuildUpdatesSkipped;
    int randomizedAttackSeparationTime;
    ManagedArrayInt playersToAttack;
    ManagedArrayInt playersToDefend;
    ManagedArrayInt workingArea;
    ManagedArrayInt unitsTaskedThisUpdate;
    int actualGathererDistribution[4];
    int desiredGathererDistribution[4];
    int neededResourceValue[4];
    int resourceDifferenceValue[4];
    char neededResources[0x70];
    int attackEnabledValue;
    int updateArea;
    int firstNeededResourceUpdateDone;
    int numberStoragePitsBuilt[4];
    int numberGranariesBuilt[4];
    int wonderInProgressValue;
    int wonderBuiltValue;
    int sn_placement_padding[0x130 / 4];

    int numberUngroupedWarBoats();
    int numberExtraGroupedWarBoats();
    int selectBestCommander(TacticalAIGroup* group);
    int selectBestCommander(ManagedArrayInt* units);
    int setAllGroupLocations(TacticalAIGroup* group);
    int removeFromGroup(int unit);

    void fillBoatGroups();
};

void TribeTacticalAIModule::fillBoatGroups() {
    int bestUnit;
    TacticalAIGroup* bestGroup;

    this->numberUngroupedWarBoats();
    this->numberExtraGroupedWarBoats();

    TacticalAIGroup* group = this->groups.next;
    TacticalAIGroup* sentinel = &this->groups;
    while (group != sentinel) {
        if (group == 0) {
            break;
        }
        if ((group->type() == 0x67 || group->type() == 0x68 || group->type() == 0x69) &&
            group->commander() == -1) {
            int ungrouped = this->numberUngroupedWarBoats();
            if (group->numberUnits() > 0) {
                int commander = this->selectBestCommander(group);
                group->setSpecificCommander(commander, this->md);
                if (group->action() == 0 || group->action() == 1) {
                    this->setAllGroupLocations(group);
                }
            }
            else {
                if (ungrouped == 0) {
                    this->numberExtraGroupedWarBoats();
                }
                if (this->workingArea.numberValue == 0) {
                    return;
                }
                int commander = this->selectBestCommander(&this->workingArea);
                group->addUnit(commander, this->md);
                group->setSpecificCommander(commander, this->md);
                if (group->action() == 0 || group->action() == 1) {
                    this->setAllGroupLocations(group);
                }
            }
        }
        group = group->next;
    }

    if (this->strategicNumbers[0x28] == 0) {
        bestUnit = 0x67;
        do {
            bestGroup = this->groups.next;
            while (bestGroup != sentinel) {
                if (bestGroup == 0) {
                    break;
                }
                if (bestGroup->type() == bestUnit) {
                    int desired = bestGroup->desiredNumberUnits();
                    int number = bestGroup->numberUnits();
                    if (number < desired) {
                        int ungrouped = this->numberUngroupedWarBoats();
                        int desiredForFill = bestGroup->desiredNumberUnits();
                        int numberForFill = bestGroup->numberUnits();
                        int missing = desiredForFill - numberForFill;
                        if (missing < ungrouped) {
                            int desiredAgain = bestGroup->desiredNumberUnits();
                            int numberAgain = bestGroup->numberUnits();
                            if (numberAgain < desiredAgain) {
                                int i = 0;
                                float bestDistance = -1.0f;
                                int bestUnitID = -1;
                                if (this->workingArea.numberValue > 0) {
                                    do {
                                        RGE_Static_Object* object = this->md->object(this->workingArea[i]);
                                        if (object != 0) {
                                            float distance = object->distance_to_position(
                                                bestGroup->gatherLocation()->x,
                                                bestGroup->gatherLocation()->y,
                                                bestGroup->gatherLocation()->z);
                                            if (bestDistance == -1.0f || distance < bestDistance) {
                                                bestUnitID = this->workingArea[i];
                                                bestDistance = distance;
                                            }
                                        }
                                        ++i;
                                    } while (i < this->workingArea.numberValue);
                                }
                                if (bestUnitID != -1) {
                                    bestGroup->addUnit(bestUnitID, this->md);

                                int max = this->workingArea.maximumSizeValue;
                                int removeIndex = 0;
                                if (max > 0) {
                                    int* value = this->workingArea.value;
                                    do {
                                        if (*value == bestUnitID) {
                                            break;
                                        }
                                        ++removeIndex;
                                        ++value;
                                    } while (removeIndex < max);
                                }
                                if (removeIndex < max) {
                                    if (removeIndex < max - 1) {
                                        do {
                                            ++removeIndex;
                                            this->workingArea.value[removeIndex - 1] = this->workingArea.value[removeIndex];
                                        } while (removeIndex < max - 1);
                                    }
                                    int count = this->workingArea.numberValue - 1;
                                    this->workingArea.numberValue = count;
                                    if (count < 0) {
                                        this->workingArea.numberValue = 0;
                                    }
                                }

                                desiredAgain = bestGroup->desiredNumberUnits();
                                numberAgain = bestGroup->numberUnits();
                                    if (numberAgain < desiredAgain) {
                                        continue;
                                    }
                                }
                            }
                        }
                        else {
                            int i = 0;
                            if (this->workingArea.numberValue > 0) {
                                do {
                                    bestGroup->addUnit(this->workingArea[i], this->md);
                                    ++i;
                                } while (i < this->workingArea.numberValue);
                            }
                        }

                        int desiredAfter = bestGroup->desiredNumberUnits();
                        int numberAfter = bestGroup->numberUnits();
                        if (numberAfter < desiredAfter) {
                            int extra = this->numberExtraGroupedWarBoats();
                            int desiredExtra = bestGroup->desiredNumberUnits();
                            int numberExtra = bestGroup->numberUnits();
                            int missingExtra = desiredExtra - numberExtra;
                            if (missingExtra < extra) {
                                int desiredNearest = bestGroup->desiredNumberUnits();
                                int numberNearest = bestGroup->numberUnits();
                                if (numberNearest < desiredNearest) {
                                    do {
                                        int i = 0;
                                        float bestDistance = -1.0f;
                                        int bestUnitID = -1;
                                        if (this->workingArea.numberValue > 0) {
                                            do {
                                                RGE_Static_Object* object = this->md->object(this->workingArea[i]);
                                                if (object != 0) {
                                                    float distance = object->distance_to_position(
                                                        bestGroup->gatherLocation()->x,
                                                        bestGroup->gatherLocation()->y,
                                                        bestGroup->gatherLocation()->z);
                                                    if (bestDistance == -1.0f || distance < bestDistance) {
                                                        bestUnitID = this->workingArea[i];
                                                        bestDistance = distance;
                                                    }
                                                }
                                                ++i;
                                            } while (i < this->workingArea.numberValue);
                                        }
                                        if (bestUnitID == -1) {
                                            break;
                                        }
                                        this->removeFromGroup(bestUnitID);
                                        bestGroup->addUnit(bestUnitID, this->md);

                                        int max = this->workingArea.maximumSizeValue;
                                        int removeIndex = 0;
                                        if (max > 0) {
                                            int* value = this->workingArea.value;
                                            do {
                                                if (*value == bestUnitID) {
                                                    break;
                                                }
                                                ++removeIndex;
                                                ++value;
                                            } while (removeIndex < max);
                                        }
                                        if (removeIndex < max) {
                                            if (removeIndex < max - 1) {
                                                do {
                                                    ++removeIndex;
                                                    this->workingArea.value[removeIndex - 1] = this->workingArea.value[removeIndex];
                                                } while (removeIndex < max - 1);
                                            }
                                            int count = this->workingArea.numberValue - 1;
                                            this->workingArea.numberValue = count;
                                            if (count < 0) {
                                                this->workingArea.numberValue = 0;
                                            }
                                        }
                                    } while (bestGroup->numberUnits() < bestGroup->desiredNumberUnits());
                                }
                            }
                            else {
                                int i = 0;
                                if (this->workingArea.numberValue > 0) {
                                    do {
                                        this->removeFromGroup(this->workingArea[i]);
                                        bestGroup->addUnit(this->workingArea[i], this->md);
                                        ++i;
                                    } while (i < this->workingArea.numberValue);
                                }
                            }
                        }
                    }
                }
                bestGroup = bestGroup->next;
            }
            ++bestUnit;
        } while (bestUnit <= 0x6A);
    }

    if (this->numberUngroupedWarBoats() != 0 && this->workingArea.numberValue > 0) {
        int i = 0;
        do {
            bestGroup = 0;
            int bestDifference = 0;
            group = this->groups.next;
            while (group != sentinel) {
                if (group == 0) {
                    break;
                }
                if (group->type() == 0x67 || group->type() == 0x68 ||
                    group->type() == 0x69 || group->type() == 0x6A ||
                    group->type() == 0x6B || group->type() == 0x6C) {
                    int number = group->numberUnits();
                    int desired = group->desiredNumberUnits();
                    if (number < desired) {
                        if (group->action() == 1 || group->action() == 0) {
                            int numberAgain = group->numberUnits();
                            int desiredAgain = group->desiredNumberUnits();
                            int difference = numberAgain - desiredAgain;
                            if (bestGroup == 0 || difference < bestDifference) {
                                bestGroup = group;
                                bestDifference = difference;
                            }
                        }
                    }
                }
                group = group->next;
            }

            if (bestGroup == 0) {
                TacticalAIGroup* candidate = this->groups.next;
                bestDifference = 0;
                while (candidate != sentinel) {
                    if (candidate == 0) {
                        break;
                    }
                    if ((candidate->type() == 0x67 || candidate->type() == 0x68 ||
                         candidate->type() == 0x69 || candidate->type() == 0x6A ||
                         candidate->type() == 0x6B || candidate->type() == 0x6C) &&
                        (candidate->action() == 1 || candidate->action() == 0)) {
                        int type = candidate->type();
                        if (type == 0x67 && candidate->numberUnits() >= this->strategicNumbers[0x3C]) {
                            candidate = candidate->next;
                            continue;
                        }
                        type = candidate->type();
                        if (type == 0x68 && candidate->numberUnits() >= this->strategicNumbers[0x45]) {
                            candidate = candidate->next;
                            continue;
                        }
                        type = candidate->type();
                        if (type == 0x69 && candidate->numberUnits() >= this->strategicNumbers[0x3F]) {
                            candidate = candidate->next;
                            continue;
                        }
                        int difference = candidate->numberUnits() - candidate->desiredNumberUnits();
                        if (bestGroup == 0 || difference < bestDifference) {
                            bestGroup = candidate;
                            bestDifference = difference;
                        }
                    }
                    candidate = candidate->next;
                }
                if (bestGroup == 0) {
                    return;
                }
                bestGroup->addUnit(this->workingArea[i], this->md);
            }
            else {
                bestGroup->addUnit(this->workingArea[i], this->md);
            }
            ++i;
        } while (i < this->workingArea.numberValue);
    }
}
