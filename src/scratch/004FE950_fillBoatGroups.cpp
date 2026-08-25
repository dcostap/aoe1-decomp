#ifndef TAITACMD_SHARED_CONTEXT
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
// Later structural probes inverted direct-fill/nearest branches and the final
// best-group fallback, then scoped the second boat iterator. Ordered calls now
// align 103/103 with a 2935-byte rebuild; the remaining drift is register and
// block placement at the second boat pass, not call or memory-effect coverage.
// The final candidate keeps these natural source shapes and remains in scratch.
// Integration check: the ordered call map is aligned, but the checker still
// reports one direct-target difference at +08E7 (desiredNumberUnits versus
// numberUnits). Treat that site as the next binary-behavior lead.
// Tried the proven same-TU AIModule base surface with md at +0xF0; emitted
// code was unchanged, so restored the clean source.
// Tried a natural for-loop increment for the second boat-type scan because
// the original has separate type-skip and underfilled-false increment blocks;
// it changed diff 2472 to 2481 and was rolled back.
// Managed pass 2026-08-17: ran 22 meaningful hypotheses. The clean baseline
// remains the best codegen result: 2935 bytes, 2472 differing bytes, 92.95%
// shape, exact frame, and 103 aligned calls. The pass tested group-local
// reuse, loop polarity and do-loop forms, scope and declaration order, the
// repeated nearest-fill loop, desired/number call order, exact ManagedArray
// copy forms, C-linkage allocation helpers, and fallback cursor reuse.
// The original proves a repeated nearest-fill backedge at 004FEDCA and a
// desired-then-number call order at 004FF156. Adding that loop improved the
// behavior model but moved the result to 2937 bytes and 2481 differing bytes;
// it was restored because it did not preserve the original physical layout.
// All array, pointer, and candidate-local variants were codegen-neutral or
// worse. The remaining lead is the compiler's second-pass register and block
// allocation: original uses EBP for the sentinel and EDI for the boat group,
// while the clean source uses EBX for the sentinel and EBP for that group.
// Worker pass: the exact ManagedIntArray donor loop, global allocation
// spelling, <stddef.h> context, and mutable sentinel all emit this same
// 2935-byte baseline. An ambient declaration lab with 128 samples found one
// codegen group and no context lead. The unresolved first nearest-fill loop
// still has the proven executable backedge at 004FEDCA.

#include <stddef.h>

extern void* operator new(unsigned int);
extern void operator delete(void*);

#ifndef TAITACMD_SHARED_CONTEXT
struct ManagedArrayInt {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    int& operator[](int index) {
        if (index > this->maximumSizeValue - 1) {
            int newSize = index + 1;
            int* newValue = (int*)::operator new(newSize * 4);
            if (newValue != 0) {
                int j;
                for (j = 0; j < this->maximumSizeValue && j < newSize; j++) {
                    newValue[j] = this->value[j];
                }
                ::operator delete(this->value);
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

#endif
void TribeTacticalAIModule::fillBoatGroups() {
    int bestUnit;

    this->numberUngroupedWarBoats();
    this->numberExtraGroupedWarBoats();

    TacticalAIGroup* sentinel = &this->groups;
    TacticalAIGroup* group = this->groups.next;
    while (group != sentinel) {
        if (group == 0) {
            break;
        }
        if (group->type() == 0x67 || group->type() == 0x68 || group->type() == 0x69) {
            if (group->commander() == -1) {
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
        }
        group = group->next;
    }

    if (this->strategicNumbers[0x28] == 0) {
        bestUnit = 0x67;
        do {
            TacticalAIGroup* boatGroup = this->groups.next;
            while (boatGroup != sentinel) {
                if (boatGroup == 0) {
                    break;
                }
                if (boatGroup->type() != bestUnit) {
                    boatGroup = boatGroup->next;
                    continue;
                }
                int desired = boatGroup->desiredNumberUnits();
                int number = boatGroup->numberUnits();
                if (number < desired) {
                        int ungrouped = this->numberUngroupedWarBoats();
                        int desiredForFill = boatGroup->desiredNumberUnits();
                        int numberForFill = boatGroup->numberUnits();
                        int missing = desiredForFill - numberForFill;
                        if (missing >= ungrouped) {
                            int i = 0;
                            if (this->workingArea.numberValue > 0) {
                                do {
                                    boatGroup->addUnit(this->workingArea[i], this->md);
                                    ++i;
                                } while (i < this->workingArea.numberValue);
                            }
                        }
                        else {
                            int desiredAgain = boatGroup->desiredNumberUnits();
                            int numberAgain = boatGroup->numberUnits();
                            if (numberAgain < desiredAgain) {
                                int i = 0;
                                float bestDistance = -1.0f;
                                int bestUnitID = -1;
                                if (this->workingArea.numberValue > 0) {
                                    do {
                                        RGE_Static_Object* object = this->md->object(this->workingArea[i]);
                                        if (object != 0) {
                                            float distance = object->distance_to_position(
                                                boatGroup->gatherLocation()->x,
                                                boatGroup->gatherLocation()->y,
                                                boatGroup->gatherLocation()->z);
                                            if (bestDistance == -1.0f || distance < bestDistance) {
                                                bestUnitID = this->workingArea[i];
                                                bestDistance = distance;
                                            }
                                        }
                                        ++i;
                                    } while (i < this->workingArea.numberValue);
                                }
                                if (bestUnitID != -1) {
                                    boatGroup->addUnit(bestUnitID, this->md);

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

                                    desiredAgain = boatGroup->desiredNumberUnits();
                                    numberAgain = boatGroup->numberUnits();
                                    if (numberAgain < desiredAgain) {
                                        continue;
                                    }
                                }
                            }
                        }

                        int desiredAfter = boatGroup->desiredNumberUnits();
                        int numberAfter = boatGroup->numberUnits();
                        if (numberAfter < desiredAfter) {
                            int extra = this->numberExtraGroupedWarBoats();
                            int desiredExtra = boatGroup->desiredNumberUnits();
                            int numberExtra = boatGroup->numberUnits();
                            int missingExtra = desiredExtra - numberExtra;
                            if (missingExtra >= extra) {
                                int i = 0;
                                if (this->workingArea.numberValue > 0) {
                                    do {
                                        this->removeFromGroup(this->workingArea[i]);
                                        boatGroup->addUnit(this->workingArea[i], this->md);
                                        ++i;
                                    } while (i < this->workingArea.numberValue);
                                }
                            }
                            else {
                                int desiredNearest = boatGroup->desiredNumberUnits();
                                int numberNearest = boatGroup->numberUnits();
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
                                                        boatGroup->gatherLocation()->x,
                                                        boatGroup->gatherLocation()->y,
                                                        boatGroup->gatherLocation()->z);
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
                                        boatGroup->addUnit(bestUnitID, this->md);

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
                                    } while (boatGroup->numberUnits() < boatGroup->desiredNumberUnits());
                                }
                            }
                        }
                }
                boatGroup = boatGroup->next;
            }
            ++bestUnit;
        } while (bestUnit <= 0x6A);
    }

    if (this->numberUngroupedWarBoats() != 0 && this->workingArea.numberValue > 0) {
        TacticalAIGroup* bestGroup;
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

            if (bestGroup != 0) {
                bestGroup->addUnit(this->workingArea[i], this->md);
            }
            else {
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
                        int difference = candidate->numberUnits();
                        difference -= candidate->desiredNumberUnits();
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
            ++i;
        } while (i < this->workingArea.numberValue);
    }
}
#else
void TribeTacticalAIModule::fillBoatGroups() {}
#endif
