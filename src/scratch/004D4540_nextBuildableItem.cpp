// VA: 004D4540 TribeBuildAIModule::nextBuildableItem
// PDB donor: taibldmd.cpp:464-891
// Baseline reconstruction: natural build-list sentinel walk with the canonical
// BuildItem/ResourceItem ownership and the direct AI submodule surfaces.
// FLAGS: /nologo /c /O2 /Oy /GX
// Attempt log:
// 1: default-flags baseline had no EH registration (1924 bytes, frame 0xF8).
// 2: /GX restored the constructor/destructor EH family (1936 bytes).
// 3: corrected TribeMainDecision ownership gaps to resourceAI +0x10D7C,
//    tacticalAI +0x1146C, and aiPlayer +0x1256C.
// 4: restored the missing build-attempt threshold/skip-escalation phase and
//    removed double sentinel advances; calls rose from 100 to 116.
// 5: shared the observed setBuildAttempts(0) null-return tail; call count now
//    equals the original (115).
// 6-7: cap/number-builds source-order probes recovered first-cap, second-cap,
//    number-builds call order but did not change the overall size.
// 8: inlined researchState into the switch; removed the extra state home and
//    recovered the exact 0xF4 frame (first mismatch moved from entry to +0x68).
// 9: early negative max-count guard was codegen-duplicate.
// 10: scoped the loop-bottom max-count local; exact-block coverage improved to
//     59.35%, but the remaining mismatch is broad block placement/jump-table
//     and late success-tail ordering. Left in scratch after the 10-probe budget.
// 12: audited every skip path against the original 004D489E shared tail; these
//     paths advance item before the loop-limit check rather than C++ continue.
//     All 12 skip sites now target next_item; only the category-3/resource
//     failure paths return 0, as shown by the original tail targets.
// 13-14: independent category-4 spelling and numberBuilds > buildCap probes;
//     the latter recovered the original cmp/jg hunk (+1 strict byte).
// 15-19: explicit do/while and physical-tail CFG reorderings were codegen
//     duplicates; restored the semantic-clean natural shared-tail source.
// 20: restored semantic-clean shared-tail source after no-op CFG reorder
//     probes; retained proven numberBuilds > currentCap operand spelling.
// 21: final validation of the semantic-clean source (pause).
// 22: session restart probe 1: converted the loop to do/while with the
//     sentinel check as the first body statement and the count check as the
//     loop condition, matching the original 004D48A1 bottom (call sn73; cmp
//     count; jle 004D45B0 backedge to the full top; jmp return-0). The prior
//     while+break form was loop-inverted by VC5 (sentinel re-check at bottom).
// 23: session restart probe 2: condA then-arm (setInProgress/setBuilt) now
//     falls through to the shared advance tail instead of goto next_item, and
//     the whole remaining loop body (category-4 precheck, skip logic, filters,
//     attempts escalation, cost/place check) is the else arm, mirroring the
//     original 004D488C -> 004D489E fall-through and the out-of-line part B at
//     004D49B8+. Category filter order swapped (category==1 first) to match
//     the original 004D4B21 cmp ebp,1 / jne 004D4B46 dispatch.
// 24: session restart probe 3 (big win): converted the loop to an infinite
//     `while (1)` with the sentinel check as the first body statement and the
//     count check as `loop_check: if (count > sn(0x73)) return 0;` at the
//     bottom. The do/while and while forms were loop-inverted by VC5 (sentinel
//     re-checked at the bottom, backedge to 45BE); the infinite loop has no
//     condition to invert, so the count-check backedge (jmp 0045B0) goes to
//     the FULL header and the sentinel re-check disappears. Part B's natural
//     end advances once (line 829, before the itemCost2 destructor) and jumps
//     to loop_check, skipping the shared advance at next_item (line 884) that
//     the then-arm and all goto-next_item skips use. Result: shape 79.2% ->
//     94.6%, exact-block 60.5% -> 84.7%, calls 99 -> 115/115 aligned, size
//     +32 -> +36 (the residual +36 is the ebx=-1 register allocation: VC5
//     materializes -1 in ebx in the original, used for push ebx and
//     mov [esp+10Ch],ebx; the rebuilt pushes imm8/immediates instead. This is
//     the liveness phase, deferred).
// 25: buildAttempts() < 1 -> <= 0 (test eax,jg instead of cmp eax,1,jge);
//     category-filter operand order (category != buildCategory() -> cmp ebp,eax);
//     canBuild declared before the strategicNumber(0xA1) call (mov ebp,1 before
//     the call). Recovers the 466D scheduling and the 4AAA test hunk.
// 26: tried named -1 locals (int/const/register spellings) for the cost amounts
//     and object() args; VC5 constant-folds them, so the ebx=-1 materialization
//     is an allocator decision, not a source spelling. The precheck's -1 DOES
//     materialize in ebx (or ebx,0FFFFFFFFh; push ebx matches), but the
//     itemCost2 cost block and the object() call push imm8 instead (push
//     0FFFFFFFFh) and the EH state resets use mov dword [esp+10Ch],-1 instead
//     of mov [esp+10Ch],ebx. This accounts for the full residual +36 bytes
//     (state stores +8, object pushes +7, cost amounts +2, shift effects). The
//     do-while, while, and while(1) loop forms all converge on this same
//     allocator basin; the ebx=-1 live range is the next (liveness-phase) lead.
// 27: variant lab (build/variant_lab/004D4540_nextBuildableItem/20260806_001520):
//     focused splice on the itemCost2 cost block, axes = amount spelling
//     (literal -1 / 0xFFFFFFFF / const local / assign local) under /GX with
//     size/frame/call-set gates. All 4 variants emit identical code (2172,
//     first mismatch +0x6C) - the ebx=-1 materialization is NOT a source
//     spelling axis.
// 28: negative: do-while with the count as the loop condition and the sentinel
//     as goto done (instead of return 0) still gets the sentinel re-check
//     (backedge to 45BE) - the rotation is MSVC's loop normalization of the
//     first-statement exit test, not a return-vs-goto artifact. Restored the
//     while(1) form (best: 2172, 94.56% shape, 84.72% exact-block, 115/115).
// 29-32: direct negative success guards around canPlace/object, then an integer
//     cast of the object pointer status, recovered EBX=-1 argument reuse and
//     reduced the body to 2156 bytes (97.12% shape, 95.61% exact blocks).
// 33: positive availability guards with a cost_block label recovered the
//     original 2136-byte boundary and 99.02% shape.
// 34-40: split the first research/resource guard and tested loop spellings,
//     return placement, and comparison order. The best source is 9 bytes from
//     exact: only the bottom count branch is reversed (jg/jmp versus jle/jmp).
//     It has 115/115 calls, exact size and 98.37% exact-block coverage.
// BINARY NOTE: The original bottom count test branches back to 004D45B0 and
//     then jumps to the zero return. The clean natural while(1) source emits
//     the equivalent reverse branch, despite matching every other body block.
// 41: original-TU audit. Inventory order confirms taibldmd.cpp neighbors from
//     the constructors through buildItem; exact donors are the list-walk and
//     build-list methods at 004D4460, 004D4DB0, 004D4F80, 004D5090,
//     004D5170, 004D5270, 004D57A0, 004D5BB0, and 004D5C20.
// 42: period header and macro contexts were swept with the pinned /GX flags.
//     VC5 kept one 2136-byte group for standard headers, repo headers, legacy
//     aliases, Windows macros, and pack(4)/pack(8) contexts.
// 43: exact neighboring declaration order and two natural preceding list-walk
//     definitions were tested. Both kept the 9-byte bottom branch mismatch.
// 44: canonical RGE_Player, MainDecision, AI submodule, TRIBE_Player, and
//     TribeMainDecision trailing class surfaces were tested. All variants kept
//     the 9-byte mismatch and the 0xF4 frame.
// TU CONCLUSION: No repository-supported translation-unit declaration, header,
//     macro, class-surface, or neighboring-function context selects the
//     oracle's jle/jmp normalization. Preserve the clean natural baseline.

extern "C" char* __cdecl strncpy(char* dst, const char* src, unsigned int count);

class BaseItem {
public:
    virtual ~BaseItem();
    char gap_04[0x68];

    int typeID() const;
    int skip() const;
    void setSkip(int value);
    char* name();
    int uniqueID() const;
};

class BuildItem : public BaseItem {
public:
    BuildItem* next;                 // +0x6C
    BuildItem* prev;                 // +0x70
    int buildCategoryValue;          // +0x74
    int numberValue;                 // +0x78
    int priorityValue;               // +0x7C
    int progressValue;               // +0x80
    int builtValue;                  // +0x84
    int buildAttemptsValue;          // +0x88
    int buildFromValue;              // +0x8C
    int terrainSetValue;             // +0x90
    int terrainAdjacencyValue[2];    // +0x94
    int placeOnElevationValue;       // +0x9C
    int numberBuildsValue;           // +0xA0
    int buildCapValue;               // +0xA4
    int skipCyclesValue;             // +0xA8
    unsigned char permanentSkipValue;// +0xAC
    unsigned char endPad[3];         // +0xAD

    virtual ~BuildItem();
    int buildCategory() const;
    int inProgress() const;
    int built() const;
    int buildAttempts() const;
    int buildFrom() const;
    int numberBuilds() const;
    int buildCap() const;
    unsigned char permanentSkip();
    void setInProgress(int value);
    void setBuilt(int value);
    void setBuildAttempts(int value);
    void incrementBuildAttempts();
    void decrementBuildAttempts();
};

class ResourceItem {
public:
    virtual ~ResourceItem();
    ResourceItem* next;
    ResourceItem* prev;
    int valueValue[8];
    int sortedValue[8];
    int sortedIndexValue[8];
    int numberValue;

    ResourceItem(int count);
};

class RGE_Player {
public:
    char gap_00[0x50];
    float* attributes;               // +0x50
};

class RGE_Static_Object {
};

class MainDecisionAIModule {
public:
    char gap_00[0xF0];
    RGE_Player* player;              // +0xF0
    char gap_0F4[0x10];              // through +0x104

    RGE_Static_Object* object(int p1, int p2, int p3, int p4, int p5,
                              int p6, int p7, int p8, int p9, int p10);
};

class TribeConstructionAIModule {
public:
    char gap_00[0x318];
    int canPlace(BuildItem* item);
};

class TribeResourceAIModule {
public:
    char gap_00[0xF8];
    int resource(int type);
    int resourcesAvailable(ResourceItem* item);
};

class TribeTacticalAIModule {
public:
    char gap_00[0x100C];
    int strategicNumber(int number);
    void enableAttack(int value);
    void setStrategicNumber(int number, int value);
};

class TRIBE_Player {
public:
    unsigned char researchState(int type);
    int researchEverAvailable(int type);
    int researchAvailable(int type);
    int objectAvailable(int type);
    void researchCost(int type, int amount, ResourceItem* item, int flag);
    void objectCost(int type, int amount, ResourceItem* item, int flag);
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    char gap_104[0x5C0];
    TribeConstructionAIModule constructionAI; // +0x6C4
    char gap_9DC[0x103A0];
    TribeResourceAIModule resourceAI;        // +0x10D7C
    char gap_10E74[0x5F8];
    TribeTacticalAIModule tacticalAI;        // +0x1146C
    char gap_12478[0xF4];
    TRIBE_Player* aiPlayer;                  // +0x1256C
};

class AIModuleMessage;

class AIModule {
public:
    virtual ~AIModule();
    virtual int loggingHistory();
    virtual void setLogHistory(int value);
    virtual void toggleLogHistory();
    virtual void setHistoryFilename(char* filename);
    virtual int loggingCommonHistory();
    virtual void setLogCommonHistory(int value);
    virtual void toggleLogCommonHistory();
    virtual int loadState(char* filename);
    virtual int saveState(char* filename);
    virtual int gleanState(int value);
    virtual int processMessage(AIModuleMessage* message);
    virtual int update(int value);
    virtual void setCallbackMessage(AIModuleMessage* message);
    virtual int filterOutMessage(AIModuleMessage* message);

    char gap_04[0xEC];
};

class BuildAIModule : public AIModule {
public:
    virtual int save(int value);
    virtual void displayBuildList();
    virtual int loadBuildList(char* filename, RGE_Player* player);
    virtual int numberBuiltOrInProgressItemsOfType(int type, int flag);

    BuildItem buildList;                         // +0xF0
    int buildListLengthValue;                    // +0x1A0
    char buildListNameValue[0x101];              // +0x1A4
    char lastBuildItemRequestedValue[0x101];     // +0x2A5
    char currentBuildItemRequestedValue[0x101];  // +0x3A6
    char nextBuildItemRequestedValue[0x101];     // +0x4A7
    int numberItemsIntoBuildListValue;           // +0x5A8
    char gap_5AC[0x10];                          // +0x5AC
};

class TribeBuildAIModule : public BuildAIModule {
public:
    TribeMainDecisionAIModule* md;               // +0x5BC

    int isAgeResearch(int type);
    BuildItem* nextBuildableItem(int category);
};

BuildItem* TribeBuildAIModule::nextBuildableItem(int category)
{
    int numGranaries = this->numberBuiltOrInProgressItemsOfType(0x67, 0);
    int numStoragePits = this->numberBuiltOrInProgressItemsOfType(0x44, 0);
    int numHouses = this->numberBuiltOrInProgressItemsOfType(0x46, 0);
    BuildItem* item = this->buildList.next;
    int realCount = 0;
    int count = 0;

    if (this->md->tacticalAI.strategicNumber(0x73) < 0)
        return 0;

    while (1) {
        if (item == &this->buildList || item == 0)
            return 0;
        if (item->buildCategory() == 1 || item->buildCategory() == 4) {
            if (this->isAgeResearch(item->typeID()) == 1) {
                switch (this->md->aiPlayer->researchState(item->typeID())) {
                case 0:
                case 1:
                    item->setBuilt(0);
                    item->setInProgress(0);
                    break;
                case 2:
                    item->setBuilt(0);
                    item->setInProgress(1);
                    break;
                case 3:
                    item->setBuilt(1);
                    item->setInProgress(0);
                    break;
                default:
                    break;
                }
            }
        }

        if (item->built() == 0 && item->inProgress() == 0) {
            ++realCount;
            int canBuild = 1;
            int strategy = this->md->tacticalAI.strategicNumber(0xA1);

            if (strategy == 1 && numStoragePits == 0 && numGranaries == 0)
                canBuild = 0;
            if (strategy == 2 && this->md->resourceAI.resource(1) < 250 && numGranaries == 0)
                canBuild = 0;
            if (strategy == 3 && numStoragePits == 0)
                canBuild = 0;
            if (strategy == 4 && (numStoragePits == 0 || numGranaries == 0))
                canBuild = 0;

            if (category == 0 && !canBuild && item->buildCategory() == 0 &&
                item->typeID() != 0x46 && item->typeID() != 0x6D &&
                item->typeID() != 0x67 && item->typeID() != 0x44) {
                goto next_item;
            }
            else {
                if (category == 0 && item->buildCategory() == 0 &&
                    (numStoragePits == 0 || numGranaries == 0) &&
                    numHouses >= this->md->tacticalAI.strategicNumber(0xAE) &&
                    item->typeID() != 0x6D && item->typeID() != 0x67 &&
                    item->typeID() != 0x44) {
                    goto next_item;
                }
                else {
                    if (item->buildCategory() == 5 && count == 0) {
                        this->md->tacticalAI.enableAttack(1);
                        item->setInProgress(0);
                        item->setBuilt(1);
                        goto next_item;
                    }
                    else if (item->buildCategory() == 6) {
                        if (count < 1) {
                            this->md->tacticalAI.setStrategicNumber(
                                item->typeID() + 0x9C, item->buildFrom());
                            item->setInProgress(0);
                            item->setBuilt(1);
                        }
                        goto next_item;
                    }
                    else if (category == 3 && count > 0) {
                        return 0;
                    }
                    else {
                        int buildCap = item->buildCap();
                        if (buildCap != -1) {
                            int currentCap = item->buildCap();
                            int numberBuilds = item->numberBuilds();
                            if (numberBuilds > currentCap)
                                goto next_item;
                        }

                        if (category == 1 &&
                            (item->buildCategory() == 1 || item->buildCategory() == 4) &&
                            this->md->aiPlayer->researchEverAvailable(item->typeID()) == 0) {
                            item->setInProgress(0);
                            item->setBuilt(1);
                        }
                        else {
                            if (item->buildCategory() == 4) {
                                ResourceItem itemCost(4);
                                this->md->aiPlayer->researchCost(
                                    item->typeID(), -1, &itemCost, 1);
                                if (this->md->aiPlayer->researchAvailable(item->typeID()) == 0 ||
                                    this->md->resourceAI.resourcesAvailable(&itemCost) == 0)
                                    return 0;
                                if (category != 1) {
                                    return 0;
                                }
                            }

                            if (item->skip() == 1 && item->buildAttempts() > 0 ||
                                item->permanentSkip() != 0) {
                                item->decrementBuildAttempts();
                                goto next_item;
                            }
                            else {
                                if (item->skip() == 1 && item->buildAttempts() <= 0) {
                                    item->setSkip(0);
                                    if (item->buildCategory() == 0 &&
                                        (item->typeID() == 0x67 || item->typeID() == 0x44)) {
                                        item->setBuildAttempts(
                                            this->md->tacticalAI.strategicNumber(0x72) - 1);
                                    }
                                }

                                if (this->md->player->attributes[0x0B] <
                                        this->md->player->attributes[0x20] ||
                                    item->buildCategory() != 2) {
                                    ++count;
                                }

                                if (category == 1 && item->buildCategory() != 1 &&
                                    item->buildCategory() != 4)
                                    goto next_item;
                                if (category != 1 && category != item->buildCategory())
                                    goto next_item;

                                if (category == 3 && item->buildCategory() != 3) {
                                    item->setBuildAttempts(0);
                                    return 0;
                                }

                                item->incrementBuildAttempts();
                                int buildAttempts = item->buildAttempts();
                                if (buildAttempts >
                                    this->md->tacticalAI.strategicNumber(0x72)) {
                                    if (item->skip() == 0 && item->permanentSkip() == 0) {
                                        if (category == 1 && item->buildCategory() == 4) {
                                            item->setBuildAttempts(0);
                                            return 0;
                                        }

                                        int strategic = this->md->tacticalAI.strategicNumber(0xB1);
                                        if (item->typeID() != strategic ||
                                            item->buildCategory() != 0) {
                                            item->setSkip(1);
                                            if (item->buildCategory() == 0 &&
                                                (item->typeID() == 0x67 ||
                                                 item->typeID() == 0x44)) {
                                                item->setBuildAttempts(
                                                    this->md->tacticalAI.strategicNumber(0x72) * 6);
                                            }
                                            else {
                                                item->setBuildAttempts(
                                                    this->md->tacticalAI.strategicNumber(0x72));
                                            }
                                            goto next_item;
                                        }
                                    }
                                }

                                if (category == 3 && item->buildCategory() == 3) {
                                    strncpy(this->currentBuildItemRequestedValue,
                                            item->name(), 0x3F);
                                    this->numberItemsIntoBuildListValue = item->uniqueID();
                                    strncpy(this->nextBuildItemRequestedValue,
                                            item->next->name(), 0x3F);
                                    this->numberItemsIntoBuildListValue = item->uniqueID();
                                    return item;
                                }

                                // BINARY NOTE: Success branches enter the cost
                                // block; failure branches use the shared advance.
                                if (category == 1) {
                                    if (this->md->aiPlayer->researchAvailable(item->typeID()) != 0)
                                        goto cost_block;
                                }
                                else if (this->md->aiPlayer->objectAvailable(item->typeID()) != 0) {
                                    goto cost_block;
                                }
                                goto next_item;

cost_block:
                                {
                                    ResourceItem itemCost2(4);
                                    if (category == 1) {
                                        this->md->aiPlayer->researchCost(
                                            item->typeID(), -1, &itemCost2, 1);
                                    }
                                    else {
                                        this->md->aiPlayer->objectCost(
                                            item->typeID(), -1, &itemCost2, 1);
                                    }

                                    if (this->md->resourceAI.resourcesAvailable(&itemCost2)) {
                                        int found;
                                        if (category == 2 || category == 1) {
                                            // BINARY NOTE: Keep the pointer
                                            // result as an integer status. VC5
                                            // then tests EAX directly.
                                            found = (int)this->md->object(
                                                -1, item->buildFrom(), -1, -1, -1,
                                                -1, -1, -1, 2, -1);
                                        }
                                        else {
                                            found = this->md->constructionAI.canPlace(item);
                                        }
                                        if (found != 0) {
                                            strncpy(this->currentBuildItemRequestedValue,
                                                    item->name(), 0x3F);
                                            this->numberItemsIntoBuildListValue = item->uniqueID();
                                            strncpy(this->nextBuildItemRequestedValue,
                                                    item->next->name(), 0x3F);
                                            this->numberItemsIntoBuildListValue = item->uniqueID();
                                            return item;
                                        }
                                        item = item->next;
                                        goto loop_check;
                                    }
                                    item = item->next;
                                    goto loop_check;
                                }
                            }
                        }
                    }
                }
            }
        }

next_item:
        item = item->next;
loop_check:
        if (count > this->md->tacticalAI.strategicNumber(0x73))
            return 0;
    }
}
