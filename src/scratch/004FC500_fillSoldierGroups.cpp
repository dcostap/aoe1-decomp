// VA: 004FC500 TribeTacticalAIModule::fillSoldierGroups
// Baseline reconstruction: the embedded TacticalAIGroup at +0x9D4 owns the
// circular list sentinel; workingArea at +0xD48 is a ManagedArray<int> with
// value/numberValue/desiredNumberValue/maximumSizeValue at +0/+4/+8/+C.
// The function first repairs commander assignments, then fills type 100-102
// groups from ungrouped soldiers, redistributes excess soldiers, and finally
// assigns any remaining ungrouped soldiers to eligible groups.
//
// Attempt log:
// - baseline source is the period-plausible group-list/ManagedArray model; the
//   repeated growth and removal blocks are kept inline because the original
//   emits the canonical utmarray.h operator[]/remove shapes at each use site.
// - restored the commander-zone object/currentZone filter in both fill paths
//   and both excess-redistribution paths; the call set and frame then aligned.
// - added the binary-observed inUse gate before selecting a commander for an
//   underfilled group.
// - kept the initial sentinel walk scoped, and used guarded do/while list
//   traversal for the type loop and the final soldier redistribution scan.
// - matched desiredNumberUnits-before-numberUnits ordering in the final group
//   chooser and preserved its two-stage same-zone/capacity selection.
// - the final third-pass add has a shared addUnit tail but branch-local
//   ManagedArray growth/copy/delete, matching the original branch topology.
//   Matching is paused: current output is 3520/3554 bytes with the exact frame,
//   121/122 calls, and 86.07% ordered-call alignment; remaining drift begins
//   in the second group-loop register/CFG basin and one ManagedArray delete.

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

class MainDecisionAIModule;
class TribeMainDecisionAIModule;

struct Waypoint {
    float x;
    float y;
    float z;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    unsigned char currentZone();
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
    int inUse() const;
    Waypoint* gatherLocation() const;
    int addUnit(int unit, TribeMainDecisionAIModule* md);
    void setSpecificCommander(int commander, TribeMainDecisionAIModule* md);
};

class MainDecisionAIModule {
public:
    RGE_Static_Object* object(int id);
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
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
    int sn[226];
    char gatherers[50 * 0x18];
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
    char placementStatePadding[0x130];

    int numberUngroupedSoldiers();
    int numberExtraGroupedSoldiers();
    int selectBestCommander(TacticalAIGroup* group);
    int selectBestCommander(ManagedArrayInt* units);
    int setAllGroupLocations(TacticalAIGroup* group);
    int removeFromGroup(int unit);

    void fillSoldierGroups();
};

void TribeTacticalAIModule::fillSoldierGroups() {
    int bestUnit;
    TacticalAIGroup* bestGroup;

    this->numberUngroupedSoldiers();
    this->numberExtraGroupedSoldiers();

    {
        TacticalAIGroup* group = this->groups.next;
        TacticalAIGroup* sentinel = &this->groups;
        while (group != sentinel) {
            if (group == 0) {
                break;
            }
            if ((group->type() == 100 || group->type() == 101 || group->type() == 102) &&
                group->commander() == -1) {
                int ungrouped = this->numberUngroupedSoldiers();
                if (group->numberUnits() > 0) {
                    int commander = this->selectBestCommander(group);
                    group->setSpecificCommander(commander, this->md);
                    if (group->action() == 0 || group->action() == 1) {
                        this->setAllGroupLocations(group);
                    }
                }
                else {
                    if (ungrouped == 0) {
                        this->numberExtraGroupedSoldiers();
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
    }

    if (this->sn[0x28] == 0) {
        bestUnit = 100;
        do {
            bestGroup = this->groups.next;
            if (bestGroup != &this->groups) {
                do {
                if (bestGroup == 0) {
                    break;
                }
                if (bestGroup->type() == bestUnit) {
                    int desired = bestGroup->desiredNumberUnits();
                    int number = bestGroup->numberUnits();
                    if (number < desired) {
                        if (bestGroup->inUse() != 1) {
                            int groupZone = -1;
                            int groupCommander = bestGroup->commander();
                            RGE_Static_Object* groupObject = this->md->object(groupCommander);
                            if (groupObject != 0) {
                                groupZone = groupObject->currentZone();
                            }
                            int ungrouped = this->numberUngroupedSoldiers();
                            int desiredForFill = bestGroup->desiredNumberUnits();
                            int numberForFill = bestGroup->numberUnits();
                            int missing = desiredForFill - numberForFill;
                            if (missing < ungrouped) {
                                int desiredAgain = bestGroup->desiredNumberUnits();
                                int numberAgain = bestGroup->numberUnits();
                                if (numberAgain < desiredAgain) {
                                do {
                                    int i = 0;
                                    float bestDistance = -1.0f;
                                    int bestUnitID = -1;
                                    if (this->workingArea.numberValue > 0) {
                                        do {
                                            RGE_Static_Object* object =
                                                this->md->object(this->workingArea[i]);
                                            if (object != 0 &&
                                                object->currentZone() == groupZone) {
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
                                                this->workingArea.value[removeIndex - 1] =
                                                    this->workingArea.value[removeIndex];
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
                                } while (numberAgain < desiredAgain);
                                }
                            }
                            else {
                                int i = 0;
                                if (this->workingArea.numberValue > 0) {
                                    do {
                                        RGE_Static_Object* object =
                                            this->md->object(this->workingArea[i]);
                                        if (object != 0 &&
                                            object->currentZone() == groupZone) {
                                            bestGroup->addUnit(this->workingArea[i], this->md);
                                        }
                                        ++i;
                                    } while (i < this->workingArea.numberValue);
                                }
                            }

                            int desiredAfter = bestGroup->desiredNumberUnits();
                            int numberAfter = bestGroup->numberUnits();
                            if (numberAfter < desiredAfter) {
                                int extra = this->numberExtraGroupedSoldiers();
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
                                                RGE_Static_Object* object =
                                                    this->md->object(this->workingArea[i]);
                                                if (object != 0 &&
                                                    object->currentZone() == groupZone) {
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
                                                    this->workingArea.value[removeIndex - 1] =
                                                        this->workingArea.value[removeIndex];
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
                                            RGE_Static_Object* object =
                                                this->md->object(this->workingArea[i]);
                                            if (object != 0 &&
                                                object->currentZone() == groupZone) {
                                                this->removeFromGroup(this->workingArea[i]);
                                                bestGroup->addUnit(this->workingArea[i], this->md);
                                            }
                                            ++i;
                                        } while (i < this->workingArea.numberValue);
                                    }
                                }
                            }
                        }
                    }
                }
                    bestGroup = bestGroup->next;
                } while (bestGroup != &this->groups);
            }
            ++bestUnit;
        } while (bestUnit <= 0x66);
    }

    if (this->numberUngroupedSoldiers() != 0 && this->workingArea.numberValue > 0) {
        int i = 0;
        TacticalAIGroup* group;
        do {
            RGE_Static_Object* object = this->md->object(this->workingArea[i]);
            if (object != 0) {
                unsigned char unitZone = object->currentZone();
                bestGroup = 0;
                int bestDifference = 0;
                group = this->groups.next;
                while (group != &this->groups) {
                    if (group == 0) {
                        break;
                    }
                    if ((group->type() == 100 || group->type() == 101 ||
                         group->type() == 102) &&
                        group->inUse() != 1) {
                        int commander = group->commander();
                        RGE_Static_Object* commanderObject = this->md->object(commander);
                        if (commanderObject != 0 &&
                            commanderObject->currentZone() == unitZone) {
                            int desired = group->desiredNumberUnits();
                            int number = group->numberUnits();
                            if (number < desired &&
                                (group->action() == 1 || group->action() == 0)) {
                                int desiredAgain = group->desiredNumberUnits();
                                int numberAgain = group->numberUnits();
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
                    bestGroup = 0;
                    bestDifference = 0;
                    while (candidate != &this->groups) {
                        if (candidate == 0) {
                            break;
                        }
                        if ((candidate->type() == 100 || candidate->type() == 101 ||
                             candidate->type() == 102) &&
                            candidate->inUse() != 1 &&
                            (candidate->action() == 1 || candidate->action() == 0)) {
                            int type = candidate->type();
                            if (type == 100 &&
                                candidate->numberUnits() >= this->sn[0x1A]) {
                                candidate = candidate->next;
                                continue;
                            }
                            type = candidate->type();
                            if (type == 101 &&
                                candidate->numberUnits() >= this->sn[0x1C]) {
                                candidate = candidate->next;
                                continue;
                            }
                            type = candidate->type();
                            if (type == 102 &&
                                candidate->numberUnits() >= this->sn[0x2C]) {
                                candidate = candidate->next;
                                continue;
                            }
                            int commander = candidate->commander();
                            RGE_Static_Object* commanderObject = this->md->object(commander);
                            if (commanderObject != 0 &&
                                commanderObject->currentZone() == unitZone) {
                                int desired = candidate->desiredNumberUnits();
                                int number = candidate->numberUnits();
                                int difference = number - desired;
                                if (bestGroup == 0 || difference < bestDifference) {
                                    bestGroup = candidate;
                                    bestDifference = difference;
                                }
                            }
                        }
                        candidate = candidate->next;
                    }
                    if (bestGroup == 0) {
                        return;
                    }
                    if (i > this->workingArea.maximumSizeValue - 1) {
                        int newSize = i + 1;
                        int* newValue = (int*)operator new(newSize * 4);
                        if (newValue != 0) {
                            int j = 0;
                            while (j < this->workingArea.maximumSizeValue && j < newSize) {
                                newValue[j] = this->workingArea.value[j];
                                ++j;
                            }
                            operator delete(this->workingArea.value);
                            this->workingArea.value = newValue;
                            this->workingArea.maximumSizeValue = newSize;
                        }
                    }
                }
                else {
                    if (i > this->workingArea.maximumSizeValue - 1) {
                        int newSize = i + 1;
                        int* newValue = (int*)operator new(newSize * 4);
                        if (newValue != 0) {
                            int j = 0;
                            while (j < this->workingArea.maximumSizeValue && j < newSize) {
                                newValue[j] = this->workingArea.value[j];
                                ++j;
                            }
                            operator delete(this->workingArea.value);
                            this->workingArea.value = newValue;
                            this->workingArea.maximumSizeValue = newSize;
                        }
                    }
                }
                bestGroup->addUnit(this->workingArea.value[i], this->md);
            }
            ++i;
        } while (i < this->workingArea.numberValue);
    }
}
