// TribeBuildAIModule::initialize
// VA: 004D3D60, taibldmd.cpp:100-434
// __thiscall void initialize(void)
//
// FLAGS: /GX (required: original has a full SEH fs:[0] frame with a destructible
//        ResourceItem local; default /O2 /Oy emitted no EH prologue -> 92% diff)
//
// Attempt log:
// - baseline: natural reconstruction (nested category/type scan, then transport /
//   tool / fishing / research / bronze / gatherer fill blocks with division steps
//   and ResourceItem subobject). Diff 1643 (92.3%), frame 0x9C matches.
// - control-flow: resource-cost block now calls buildCategory() twice (==1, ==4)
//   instead of caching a `bc` temp, restoring the 9th direct buildCategory call
//   and 100%% ordered-call parity (61/61, gap 0). Diff 1638.
// - flags: added /GX. Original prologue has push -1 / handler / fs:[0] EH state; a
//   destructible ResourceItem(4) local makes VC5 emit it. Big win: strict diff
//   1082 (60.8%), shape 84.6%, exact-block 41%, size 1770/1780.
// - variant: reordered the 11 counter declarations to the original's stack-slot
//   order -> worse (1091); reverted to baseline natural order (store order = orig).
// - orchestrator behavior audit: strategicNumber(0x9B) is called unconditionally
//   after strategicNumber(0xA0) in the executable, even when A0 is zero; moved
//   that call before the A0 guard to preserve its side effects and call topology.
// - layout audit: BuildItem must be 0xB0 bytes (buildListLength at +0x1A0), not
//   0x74; added gap_74. Fixes the fishing-block buildListLength displacement
//   (reb was +0x164). shape 85.5 -> 89.3%, blocks 41.9 -> 61.7%.
// - behavior audit: original stores ironAgeIndex = val9B + 4 unconditionally
//   (before the valA0 != 0 test); moved the store out of the if. Original also
//   resets bronzeAgeIndex = 0 in the valA0 block preheader (missing reset would
//   leak the bronze-fill count into insertGathererPercentage); added it.
// - bronze insert: if/else with duplicated insert() calls (bp>1 ? bp-1 : 1)
//   restores the original branch-pushed argument shape (lea/push vs materialized
//   selector).
// - valA0 loop: if+do-while form (matches Ghidra reconstruction) restores the
//   original instruction count (532/532) and puts the bronzeAgeIndex=0 store
//   near its original block; diff 1076, size -7, shape 90.0%%.
// - tool-age double guard: the original keeps BOTH the `if (remaining > 0)`
//   guard (191) and the while-loop guard (199); rebuilt VC5 merges them into
//   one test. Tried sibling-step-calc forms, do-while forms, inline condition,
//   register-qualified step: all add a step spill or break call parity. Left
//   the natural nested form (single merged guard); 1 missing test+jle hunk.
// - register allocation: original keeps `count` (0x66) in EBP through the first
//   loop + transport fill; rebuilt keeps `warshipCount` (0x65) there instead.
//   This flips the 11 counter frame-slot assignment (rebuilt slots: divisionSize
//   <-> totalPercentage +18/+20; four-slot rotation +24..+34) and the A0-loop
//   ironAgeIndex register home. Declaration order, branch nesting, and chained
//   initializers were all probed; VC5's slot allocation is not source-order
//   driven here.
// - direct natural lifetime probes: split the early research-presence flags from
//   the later resource threshold and scoped counter. Both variants grew to 534
//   instructions and diff 1088, while the clean source stays at 532/1076; rolled
//   back. The first paired hunk still shows the same local-slot permutation.
//
// LEFT IN SCRATCH: semantically faithful natural reconstruction with correct
// class surface (/GX EH frame, 0xB0 BuildItem), 100%% call parity (61/61), and
// matching instruction count (532/532). Remaining ~60%% positional diff is
// pervasive VC5 register/slot-allocation drift (count-vs-warshipCount EBP
// choice, frame-slot permutation, A0-loop ironAgeIndex home) plus one missing
// tool-age loop guard. Landing the exact allocation is not evidence-backed
// within a bounded session. Strong verified-logic-tier candidate for
// orchestrator semantic review.

class ResourceItem;

class TRIBE_Player {
public:
    void objectCost(int type, int p2, ResourceItem* r, int p4);
    void researchCost(int type, int p2, ResourceItem* r, int p4);
};

class ResourceItem {
public:
    void* vtable_ptr;                 // +0x00
    ResourceItem* next;               // +0x04
    ResourceItem* prev;               // +0x08
    int valueValue[8];                // +0x0C
    int sortedValue[8];               // +0x2C
    int sortedIndexValue[8];          // +0x4C
    int numberValue;                  // +0x6C

    ResourceItem(int count);
    ~ResourceItem();
    void setAllValues(int value);
    int value(int index);
};

class BaseItem {
public:
    virtual ~BaseItem();
    char gap_04[0x68];

    int typeID();
    int uniqueID();
};

class BuildItem : public BaseItem {
public:
    virtual ~BuildItem();

    BuildItem* next;                  // +0x6C
    BuildItem* prev;                  // +0x70
    char gap_74[0xB0 - 0x74];         // BuildItem is 0xB0 bytes (real layout)

    int buildCategory();
};

class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0xEC];
};

class TribeTacticalAIModule {
public:
    int strategicNumber(int value);
};

class TribeMainDecisionAIModule {
public:
    char gap_00[0x1146C];
    TribeTacticalAIModule tacticalAI;      // +0x1146C
    char gap_11470[0x1256C - 0x11470];
    TRIBE_Player* aiPlayer;                // +0x1256C
};

class BuildAIModule : public AIModule {
public:
    BuildItem buildList;                  // +0xF0
    int buildListLength;                  // +0x1A0
    char gap_1A4[0x5BC - 0x1A4];
};

class TribeBuildAIModule : public BuildAIModule {
public:
    TribeMainDecisionAIModule* md;        // +0x5BC

    int insert(int type, int count, int index);
    int insertResearch(int research, int index);
    int insertGathererPercentage(int index, int percentage, int bronzeAgeIndex);
    void initialize();
};

void TribeBuildAIModule::initialize()
{
    int bronzeAgeIndex = 0;
    int transportCount = 0;
    int toolAgeIndex = 0;
    int fishingBoatCount = 0;
    int resourceCount = 0;
    int warshipCount = -1;
    int count = -1;
    int totalPercentage = -1;
    int ironAgeIndex = 0;
    int divisionSize = 0;
    int dockCount = 0;

    BuildItem* item = this->buildList.next;
    BuildItem* sentinel = &this->buildList;

    while (item != sentinel) {
        if (item == 0) {
            break;
        }

        if (item->buildCategory() == 0) {
            if (item->typeID() == 0x46) {
                bronzeAgeIndex++;
            } else if (item->typeID() == 0x2D) {
                transportCount++;
            }
        } else if (item->buildCategory() == 2) {
            if (item->typeID() == 0x0D) {
                toolAgeIndex++;
            } else if (item->typeID() == 0x11 || item->typeID() == 0x12) {
                fishingBoatCount++;
            } else if (item->typeID() == 0x13 || item->typeID() == 0xFA) {
                resourceCount++;
            }
        } else if (item->buildCategory() == 1 || item->buildCategory() == 4) {
            if (item->typeID() == 0x65) {
                warshipCount = item->uniqueID();
            } else if (item->typeID() == 0x66) {
                count = item->uniqueID();
            } else if (item->typeID() == 0x67) {
                totalPercentage = item->uniqueID();
            } else if (item->typeID() == 5) {
                ironAgeIndex = 1;
            } else if (item->typeID() == 7) {
                divisionSize = 1;
            } else if (item->typeID() == 8) {
                dockCount = 1;
            }
        }

        item = item->next;
    }

    // Transport boats fill.
    if (transportCount < this->md->tacticalAI.strategicNumber(0xD4) &&
        this->md->tacticalAI.strategicNumber(0xD0) == 1) {
        int remaining = this->md->tacticalAI.strategicNumber(0xD4) - transportCount;
        int step;
        if (count != -1) {
            step = count / remaining;
        } else if (warshipCount != -1) {
            step = warshipCount / remaining;
        } else {
            step = 10;
        }
        int val = step;
        while (remaining > 0) {
            insert(0x2D, -1, val);
            val += step;
            remaining--;
        }
    }

    // Tool age items fill.
    if (toolAgeIndex < this->md->tacticalAI.strategicNumber(0xD5) &&
        this->md->tacticalAI.strategicNumber(0xD1) == 1) {
        int remaining = this->md->tacticalAI.strategicNumber(0xD5) - toolAgeIndex;
        if (remaining > 0) {
            int step;
            if (count != -1) {
                step = count / remaining;
            } else if (warshipCount != -1) {
                step = warshipCount / remaining;
            } else {
                step = 10;
            }
            int val = step;
            while (remaining > 0) {
                insert(0x0D, -1, val);
                val += step;
                remaining--;
            }
        }
    }

    // Fishing boats fill.
    if (fishingBoatCount < this->md->tacticalAI.strategicNumber(0xD6) &&
        this->md->tacticalAI.strategicNumber(0xD2) == 1) {
        int remaining = this->md->tacticalAI.strategicNumber(0xD6) - fishingBoatCount;
        int step;
        int first;
        if (warshipCount != -1) {
            step = (this->buildListLength - warshipCount) / (remaining * 2);
            first = count;
        } else if (count != -1) {
            step = (this->buildListLength - count) / (remaining * 2);
            first = -1;
        } else {
            step = 10;
            first = 0;
        }
        while (remaining > 0) {
            first += step;
            insert(0x11, -1, first);
            remaining--;
        }

        if (dockCount == 0 && totalPercentage != -1) {
            insertResearch(8, totalPercentage + 2);
        }
    }

    // Resource-count / research fill.
    if (resourceCount < this->md->tacticalAI.strategicNumber(0xE0) &&
        this->md->tacticalAI.strategicNumber(0xDF) == 1 &&
        (totalPercentage != -1 || count != -1)) {
        int remaining = this->md->tacticalAI.strategicNumber(0xE0) - resourceCount;
        int step = (totalPercentage != -1 ? totalPercentage : count) / remaining;
        int val = step;
        while (remaining > 0) {
            insertResearch(0x13, val);
            val += step;
            remaining--;
        }

        if (ironAgeIndex == 0 && count != -1) {
            insertResearch(5, count + 5);
        }
        if (divisionSize == 0 && totalPercentage != -1) {
            insertResearch(7, totalPercentage + 5);
        }
    }

    // Bronze age fill with its own list scan.
    if (bronzeAgeIndex == 0 && this->md->tacticalAI.strategicNumber(0xB4) == 1) {
        BuildItem* item2 = this->buildList.next;
        BuildItem* sentinel2 = &this->buildList;
        int bx = 0;
        int bp = 0;
        bronzeAgeIndex = 0;

        while (item2 != sentinel2 && item2 != 0) {
            if (item2->buildCategory() == 0 && item2->typeID() == 0x6D) {
                bx += 4;
            }
            if (item2->buildCategory() == 2) {
                bronzeAgeIndex++;
            }
            if (bronzeAgeIndex > bx) {
                int r;
                if (bp > 1) {
                    r = insert(0x46, -1, bp - 1);
                } else {
                    r = insert(0x46, -1, 1);
                }
                if (r == 1) {
                    bx += 4;
                }
            }
            if (bx > this->md->tacticalAI.strategicNumber(0x98) + 0x32) {
                break;
            }
            item2 = item2->next;
            bp++;
        }
    }

    // Resource/gatherer distribution.
    int valA0 = this->md->tacticalAI.strategicNumber(0xA0);
    int val9B = this->md->tacticalAI.strategicNumber(0x9B);
    ironAgeIndex = val9B + 4;
    if (valA0 != 0) {
        BuildItem* item2 = this->buildList.next;
        BuildItem* sentinel2 = &this->buildList;

        ResourceItem resource(4);
        divisionSize = 0;
        resource.setAllValues(0);

        if (item2 != sentinel2) {
            bronzeAgeIndex = 0;
            do {
                if (item2 == 0) break;
                if (item2->buildCategory() == 6) {
                    item2 = item2->next;
                    divisionSize++;
                } else {
                    if (item2->buildCategory() == 1 || item2->buildCategory() == 4) {
                        this->md->aiPlayer->researchCost(item2->typeID(), -1, &resource, 1);
                    } else {
                        this->md->aiPlayer->objectCost(item2->typeID(), -1, &resource, 1);
                    }
                    divisionSize++;

                    if (divisionSize >= ironAgeIndex) {
                        int total = 0;
                        for (int i = 0; i < 4; i++) {
                            total += resource.value(i);
                        }
                        if (total > 0) {
                            for (int i = 0; i < 4; i++) {
                                insertGathererPercentage(i,
                                    (resource.value(i) * valA0) / total,
                                    bronzeAgeIndex);
                            }
                            resource.setAllValues(0);
                            bronzeAgeIndex += ironAgeIndex;
                            divisionSize = 0;
                        }
                    }

                    item2 = item2->next;
                }
            } while (item2 != sentinel2);
        }
    }
}
