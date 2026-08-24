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
//   guard (191) and the loop guard (199). The natural nested while merges them
//   into one test. A natural outer-guard/inner-do-while form restores the
//   second-test basin: diff 953, size 1781/1780, shape 89.87%, calls 61/61.
//   The do-while source remains the best clean candidate, but it is not exact.
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
// - Ghidra marks the three research-presence locals as bool; changing the int
//   flags to bool moved the entry allocation and worsened diff to 1587. Restored.
// - H24 tested `do { ... } while (--remaining != 0)`: VC5 chose a different
//   register basin and worsened diff to 1104. Keep the H12 `remaining--` form.
// - Ghidra also names a separate requiredPop local for strategic 0x9B + 4;
//   separating it from the reused ironAge flag worsened diff to 1084. Restored.
// - PDB CodeView confirms the original scalar homes: bronze +0x10, count +0x14,
//   division +0x18, iron +0x1C, total +0x20, dock +0x24, transport +0x28,
//   fishing +0x2C, tool +0x30, warship +0x34, and resourceCount +0x38.
//   It also records aliases triremeUpgrade/count, warshipUpgrade/divisionSize,
//   transportUpgrade/totalPercentage, and houseCount/requiredPop.
// - H25/H28 tested a positive nested null guard and a matching cleanup goto for
//   the resource scan. Both reached 1780 bytes and an exact late loop block but
//   worsened strict diff to 964; the clean do-while source remains 953.
// - H26/H27 tested complete declaration orders from Ghidra and raw CodeView.
//   Both worsened the entry allocation (962/968); restored H12.
//
// - Exact-finish H29 changed only the tool-age do-while test to `!= 0`; VC5
//   moved to 1104 bytes, so it was restored. H30 `register count` was a
//   duplicate 953-byte basin. H31 swapped only count/warshipCount and reached
//   954 bytes. H32 declared the sentinel before item and used one natural
//   sentinel/null condition; it was a duplicate 953-byte basin. All were
//   restored.
// - H35 mirrored Ghidra's second tool-age guard and !=0 backedge: 1776 bytes,
//   diff 1104. H36 interleaved declarations: diff 962 and a worse prologue.
// - H38 used an explicit resource-fill do-while: diff 951 but wrong topology
//   and broad allocation drift. H39 kept the 0x9B value live: diff 969.
// - H42 used a scoped gatherer index: diff 958. H35-H42 were restored.

// LEFT IN SCRATCH: semantically faithful natural reconstruction with correct
// class surface (/GX EH frame, 0xB0 BuildItem), 61/61 ordered calls, and the
// best observed diff (953; 53.51%). Remaining drift includes broad register
// and frame-slot allocation differences, a one-instruction size overrun, and
// the resource-scan loop topology. Landing exact allocation is not
// evidence-backed in this pass. Strong verified-logic-tier candidate for
// orchestrator semantic review.

#ifndef TAIBLDMD_SHARED_CONTEXT
class ResourceItem;

class TRIBE_Player {
public:
    void objectCost(int type, int p2, ResourceItem* r, int p4);
    void researchCost(int type, int p2, ResourceItem* r, int p4);
};

class ResourceItem {
public:
    // BINARY NOTE: the first word is the real virtual destructor pointer.
    // Use the period C++ surface instead of a raw vtable field.
    virtual ~ResourceItem();
    ResourceItem* next;               // +0x04
    ResourceItem* prev;               // +0x08
    int valueValue[8];                // +0x0C
    int sortedValue[8];               // +0x2C
    int sortedIndexValue[8];          // +0x4C
    int numberValue;                  // +0x6C

    ResourceItem(int count);
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
#endif

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
            do {
                insert(0x0D, -1, val);
                val += step;
                remaining--;
            } while (remaining > 0);
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
