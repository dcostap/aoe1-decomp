// 004F0190 TribeTacticalAIModule::doSomething
// Canonical baseline: named tactical-AI arrays/modules, natural switch dispatch,
// and the period source's shared update-area timing tails.
//
// Attempt log:
// - baseline: canonical md/module ownership and natural dense switch; frame 0x128,
//   73/78 calls, 83.23% shape, 182 bytes short.
// - restored case 0x15's unskip/timing/select-next terminal path and direct
//   updateBuildAIWithObjects call; size and call count became exact (2514/78).
// - branch-local mostDamaged calls recovered the binary's push/jump dispatch;
//   current best remained structurally aligned through the tactical cases.
// - direct buildListLength call predicates recovered three test-eax blocks.
// - fixed common timing average to the executable's fixed /20 division; case 0x15
//   retains its separate total/count division.
// - declaration/name and goto/break normalization were codegen-neutral; retained
//   the natural source reconstruction rather than compiler-only CFG scaffolding.
// - final bounded result: 420 positional bytes / 92.62% shape, 78 calls, frame
//   0x128, first mismatch remains the initial timing local home and late timing
//   tail/block placement. Left in scratch after the 10-hypothesis budget.
// - follow-up: out-of-line case-21 labels, switch default/case order, timing
//   declaration permutations, and declaration initialization were codegen
//   duplicates; the direct world-time guard widened the body by 102 bytes.
//   Explicit common-tail labels widened it by 94 bytes. Restored the clean
//   natural source; the structural blocker remains unchanged.
// - Restored virtual ownership and the named build-file format string. The
//   raw vtable fields and absolute string address were diagnostic surfaces.
// - Fresh pass: extern-C timer linkage, timer declaration/assignment order,
//   switch-label order, scoped timer locals, explicit loop breaks, and several
//   coordinate assignment orders were duplicate or worse.
// - The PDB-backed case-19 resource scan is best written as a for-loop with
//   cursor updates in its increment clause. This restores the original JL
//   backedge and improves the clean result to 417 differing bytes, 92.92%
//   shape, 78/78 calls, and 0x128 frame.
// - The registered context now exposes a narrow nonvirtual TribeBuildAIModule
//   surface for exact anchors. A local inherited virtual view restores the
//   original +0x44 loadBuildList call without changing shared declarations.
//   Fresh output is 2514 bytes, 78 calls, frame 0x128, and 348 differing bytes.
// - CVDump proves four stack locals and their names. They are startTime at
//   -0x11C, availableTime at -0x120, incUpdateArea at -0x128, and
//   updateAreaStartTime at -0x124.
// - CVDump also proves three branch-local XYPoint variables named position.
//   Their homes are -0x108, -0x118, and -0x110. These scopes restore all three
//   x87 conversion blocks without fake aliases.
// - Direct member timing updates restore the four timing homes and the complete
//   common timing block. Local elapsed, total, and count values were decompiler
//   artifacts.
// - The executable casts the unsigned world-time delta to signed int before
//   division. This source keeps unsigned wrap, then applies signed division and
//   the signed <= 5 test.
// - The signed age block and direct timing source restore the internal case-21
//   blocks. The remaining mismatch is the late block order and boundary.
// - Gotos, shared returns, loop forms, timer scopes, switch order, missing
//   default, nested calls, duplicate exits, 512 ambient contexts, and supported
//   flag axes did not recover that order.
// BLOCKER: The executable puts the 0xBC9 finish block before cold case 21.
// VC5 puts case 21 first, adds a loop jump, and places the finish block last.
// With the required signed age source, the rebuilt reachable boundary is 98
// bytes too large because it also includes the following switch table.

static const char s_build_file_format[] = "%s.bld";

#ifndef TAITACMD_SHARED_CONTEXT
struct XYPoint {
    int x;
    int y;
};

struct ManagedArray_int {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

class AIModuleMessage;
class RGE_Player;
class RGE_Game_World;
class TribeMainDecisionAIModule;
class TribeTacticalAIModule;
class BuildItem;
class ConstructionItem;
class RGE_Static_Object;

class BaseItem {
public:
    virtual ~BaseItem();
    char gap_04[0x68];

    char* name();
};

class BuildItem : public BaseItem {
};

class AIModule {
public:
    virtual ~AIModule();
    virtual int loggingHistory();
    virtual void setLogHistory(int);
    virtual void toggleLogHistory();
    virtual void setHistoryFilename(char*);
    virtual int loggingCommonHistory();
    virtual void setLogCommonHistory(int);
    virtual void toggleLogCommonHistory();
    virtual int loadState(char*);
    virtual int saveState(char*);
    virtual int gleanState(int);
    virtual int processMessage(AIModuleMessage*);
    virtual int update(int);
    virtual void setCallbackMessage(AIModuleMessage*);
    virtual int filterOutMessage(AIModuleMessage*);
    char gap_04[0xEC];
};

class MainDecisionAIModule : public AIModule {
public:
    RGE_Player* player; // +0xF0
    ManagedArray_int objects;

    RGE_Static_Object* object(int);
    RGE_Static_Object* object(int, int, int, int, int, int, int, int, int, int);
    int numberObjectsWithAction(int);
    RGE_Static_Object* mostDamaged(int, int);
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    int world_time; // +0x04
    char gap_08[0xF8 - 0x08];
    unsigned int availableComputerPlayerUpdateTime; // +0xF8

    void useComputerPlayerUpdateTime(unsigned int);
    void selectNextComputerPlayer(int);
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world; // +0x3C
    char gap_40[0x10];
    float* attributes; // +0x50
};

class BuildAIModule : public AIModule {
public:
    virtual ~BuildAIModule();
    virtual int save(int);
    virtual void displayBuildList();
    virtual int loadBuildList(char*, RGE_Player*);
    virtual int numberBuiltOrInProgressItemsOfType(int, int);
    char gap_F0[0x5BC - 0xF0];

    int buildListLength();
};

class TribeBuildAIModule : public BuildAIModule {
public:
    TribeMainDecisionAIModule* md;

    BuildItem* nextBuildableItem(int);
    void unskipBuildList(int, int);
};

class PlacementState {
public:
    char gap_000[0x108];
    int builderID; // +0x108
    char gap_10C[8];
    int active; // +0x114
    char gap_118[0x14];
    BuildItem* buildItem; // +0x12C
};

class ConstructionAIModule {
public:
    virtual ~ConstructionAIModule();
    char gap_04[0xEC];
};

class TribeConstructionAIModule : public ConstructionAIModule {
public:
    char gap_0F0[0x314 - 0x0F0];
    TribeMainDecisionAIModule* md;

    ConstructionItem* placeStructure(BuildItem*, int, PlacementState&, unsigned long);
};

class InformationAIModule {
public:
    virtual ~InformationAIModule();
    char gap_04[0xEC];
};

class TribeInformationAIModule : public InformationAIModule {
public:
    char gap_0F0[0x10090 - 0x0F0];

    int withinXTilesOfObject(RGE_Static_Object*, int, int, int, int, int);
    int closestDropsiteResID(int);
    void updateResourceDropsites(int);
};

class TribeResourceAIModule : public AIModule {
public:
    TribeMainDecisionAIModule* md;
    int numberResourcesValue;

    int resource(int);
};

class TribeStrategyAIModule {
public:
    char gap_000[0x5F8];
};

class TradeAIModule {
public:
    char gap_000[0xF4];
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    TribeBuildAIModule buildAI; // +0x104
    TribeConstructionAIModule constructionAI; // +0x6C4
    char gap_09DC[0xCEC - 0x9DC];
    TribeInformationAIModule informationAI; // +0xCEC
    TribeResourceAIModule resourceAI; // +0x10D7C
    TribeStrategyAIModule strategyAI; // +0x10E74
    char gap_1146C[0xF4];
    char gap_12478[0xF4];
    RGE_Player* aiPlayer; // +0x1256C

    void updateBuildAIWithObjects();
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int id; // +0x04
    char gap_08[0x38 - 0x08];
    float world_x; // +0x38
    float world_y; // +0x3C
    float world_z; // +0x40
    char gap_44[4];
    unsigned char object_state; // +0x48
};

class TacticalAIModule {
public:
    virtual ~TacticalAIModule();
    char gap_04[0xEC];
};

class TribeTacticalAIModule : public TacticalAIModule {
public:
    TribeMainDecisionAIModule* md; // +0xF0
    ManagedArray_int civilians; // +0xF4
    ManagedArray_int civilianExplorers; // +0x104
    ManagedArray_int soldiers; // +0x114
    ManagedArray_int ungroupedSoldiers; // +0x124
    ManagedArray_int boats; // +0x134
    ManagedArray_int warBoats; // +0x144
    ManagedArray_int fishingBoats; // +0x154
    ManagedArray_int tradeBoats; // +0x164
    ManagedArray_int transportBoats; // +0x174
    ManagedArray_int artifacts; // +0x184
    int sn[226]; // +0x194
    char gap_51C[0xD20 - 0x51C];
    int numberBuildUpdatesSkipped; // +0xD20
    char gap_D24[0xD98 - 0xD24];
    int resourceDifferenceValue[4]; // +0xD98
    char gap_DA8[0xE18 - 0xDA8];
    int attackEnabledValue; // +0xE18
    int updateArea; // +0xE1C
    int firstNeededResourceUpdateDone; // +0xE20
    char gap_E24[0xE44 - 0xE24];
    int wonderInProgressValue; // +0xE44
    int wonderBuiltValue; // +0xE48
    PlacementState placementStateValue; // +0xE4C
    int nextCivilianToTaskValue; // +0xF7C
    int nextIdleSoldierGroupToTaskValue; // +0xF80
    int nextActiveSoldierGroupToTaskValue; // +0xF84
    int builtFirstStoragePit; // +0xF88
    int builtFirstGranary; // +0xF8C
    unsigned long lastBuildTime; // +0xF90
    char gap_F94[0xFFC - 0xF94];
    int lastUpdateAreaTimeValue; // +0xFFC
    int averageUpdateAreaTimeValue; // +0x1000
    int updateAreaAverageCount; // +0x1004
    int updateAreaAverageTotal; // +0x1008

    int doSomething();
    void setupSoldierGroups();
    void updateNeededResources();
    void evaluateCivilianDistribution();
    int taskCivilians(unsigned long, unsigned long);
    void setupBoatGroups();
    void fillBoatGroups();
    void taskBoats();
    void fillSoldierGroups();
    void taskIdleSoldiers(unsigned long, unsigned long);
    void taskActiveSoldiers(unsigned long, unsigned long);
    void playTaskSoldiers(unsigned long, unsigned long);
    void saveTheTown(int);
    int taskResearch(BuildItem*);
    int taskTrain(BuildItem*);
    int initialExplorationSatisfied();
    int civilian(XYPoint*, int, int, int, int, int);
    int taskBuilder(int, BuildItem*, ConstructionItem*, unsigned long);
    int taskBuilder(int, RGE_Static_Object*);
    int taskRepairer(int, RGE_Static_Object*);
    void evaluateOpenTasks();
    void checkForCoopTributeDemand();
    void checkForCoopTributeGift();
    void checkForASAPAgeResearch();
    void checkTradeBoats();
    void checkStaleAttackGroups();
    void evaluateBuildListInsertions();
};

extern "C" unsigned long debug_timeGetTime(char*, int);
extern "C" int __cdecl sprintf(char*, const char*, ...);
#endif

int TribeTacticalAIModule::doSomething()
{
    unsigned long startTime;
    unsigned long availableTime;
    int incUpdateArea;
    unsigned long updateAreaStartTime;
    unsigned long currentTime;
    char tempName[256];

    availableTime = this->md->player->world->availableComputerPlayerUpdateTime;
    startTime = debug_timeGetTime((char*)0x5880C0, 0x99C);

    if (availableTime > 0) {
        do {
            updateAreaStartTime = debug_timeGetTime((char*)0x5880C0, 0x99F);
            incUpdateArea = 1;

            switch (this->updateArea) {
            case 0:
                this->setupSoldierGroups();
                break;

            case 1:
                if (this->civilians.numberValue > 0) {
                    if (this->firstNeededResourceUpdateDone == 0) {
                        this->firstNeededResourceUpdateDone = 1;
                        this->updateNeededResources();
                    }
                    this->evaluateCivilianDistribution();
                }
                break;

            case 2:
                this->taskCivilians(startTime, availableTime);
                if (this->nextCivilianToTaskValue != -1) {
                    incUpdateArea = 0;
                }
                break;

            case 3:
                if (this->boats.numberValue > 0) {
                    this->setupBoatGroups();
                }
                break;

            case 4:
                if (this->boats.numberValue > 0) {
                    this->fillBoatGroups();
                }
                break;

            case 5:
                if (this->boats.numberValue > 0) {
                    this->taskBoats();
                }
                break;

            case 6:
                if (this->boats.numberValue > 0 || this->soldiers.numberValue > 0) {
                    this->fillSoldierGroups();
                }
                break;

            case 7:
                if (this->boats.numberValue > 0 ||
                    this->soldiers.numberValue > 0 ||
                    this->artifacts.numberValue > 0) {
                    this->taskIdleSoldiers(startTime, availableTime);
                    if (this->nextIdleSoldierGroupToTaskValue != -1) {
                        incUpdateArea = 0;
                    }
                }
                break;

            case 8:
                if (this->boats.numberValue > 0 ||
                    this->soldiers.numberValue > 0 ||
                    this->artifacts.numberValue > 0) {
                    this->taskActiveSoldiers(startTime, availableTime);
                    if (this->nextActiveSoldierGroupToTaskValue != -1) {
                        incUpdateArea = 0;
                    }
                }
                break;

            case 9:
                if (this->soldiers.numberValue > 0) {
                    this->playTaskSoldiers(startTime, availableTime);
                }
                break;

            case 10: {
                RGE_Static_Object* object =
                    this->md->object(-1, 0x6D, -1, -1, -1, -1, -1, -1, -1, -1);
                if (object != 0) {
                    int distance = this->md->informationAI.withinXTilesOfObject(
                        object, 0x14, 0x4F, 0xC7, 0x45, 0x116);
                    if (distance != -1) {
                        this->saveTheTown(distance);
                    }
                }
                break;
            }

            case 11: {
                this->numberBuildUpdatesSkipped++;
                if (this->md->buildAI.buildListLength() > 0 &&
                    this->numberBuildUpdatesSkipped >= this->sn[0x65]) {
                    BuildItem* item = this->md->buildAI.nextBuildableItem(1);
                    if (item != 0) {
                        this->taskResearch(item);
                    }
                }
                break;
            }

            case 12: {
                if (this->md->player->attributes[0x0B] <
                    this->md->player->attributes[0x20]) {
                    if (this->md->buildAI.buildListLength() > 0 &&
                        this->numberBuildUpdatesSkipped >= this->sn[0x65]) {
                        BuildItem* item = this->md->buildAI.nextBuildableItem(2);
                        if (item != 0) {
                            this->taskTrain(item);
                        }
                    }
                }
                break;
            }

            case 13: {
                if (this->md->buildAI.buildListLength() > 0 &&
                    this->numberBuildUpdatesSkipped >= this->sn[0x65]) {
                    BuildItem* item = this->md->buildAI.nextBuildableItem(3);
                    if (item != 0) {
                        sprintf(tempName, s_build_file_format, item->name());
                        this->md->buildAI.loadBuildList(
                            tempName, this->md->aiPlayer);
                        this->md->updateBuildAIWithObjects();
                        this->updateNeededResources();
                    }
                    this->numberBuildUpdatesSkipped = 0;
                }
                break;
            }

            case 14: {
                if (this->initialExplorationSatisfied() != 0) {
                    if (this->md->numberObjectsWithAction(0x25A) < this->sn[4] ||
                        this->wonderInProgressValue != 0 ||
                        this->wonderBuiltValue != 0) {
                        RGE_Static_Object* object =
                            this->md->object(-1, -1, -1, -1, -1, -1, -1, -1, 0, -1);
                        if (object != 0) {
                            RGE_Static_Object* wonder = this->md->object(
                                -1, -1, -1, 0x25A, -1, object->id, -1, -1, -1, -1);
                            if (this->wonderInProgressValue != 0 || wonder == 0) {
                                // BINARY NOTE: PDB gives each branch its own position home.
                                XYPoint position;
                                position.x = (int)object->world_x;
                                position.y = (int)object->world_y;
                                int id = this->civilian(&position, 1, 0x2BE, 0x2CE, 0x2BC, 0);
                                if (id != -1) {
                                    if (this->taskBuilder(id, object) == 1) {
                                        this->lastBuildTime =
                                            this->md->player->world->world_time;
                                    }
                                }
                            }
                        }
                    }
                }
                break;
            }

            case 15: {
                if (this->initialExplorationSatisfied() != 0) {
                    if (this->md->numberObjectsWithAction(0x25A) < this->sn[4] ||
                        this->wonderInProgressValue != 0 ||
                        this->wonderBuiltValue != 0) {
                        RGE_Static_Object* object;
                        if (this->wonderBuiltValue == 1) {
                            object = this->md->mostDamaged(3, 0x114);
                        } else {
                            object = this->md->mostDamaged(3, -1);
                        }
                        if (object != 0 && object->object_state == 2) {
                            RGE_Static_Object* existing = this->md->object(
                                -1, -1, -1, 0x26A, -1, object->id, -1, -1, -1, -1);
                            if (existing == 0) {
                                XYPoint position;
                                position.x = (int)object->world_x;
                                position.y = (int)object->world_y;
                                int id = this->civilian(&position, 1, 0x2BE, 0x2CE, 0x2BC, 0);
                                if (id != -1) {
                                    this->taskRepairer(id, object);
                                }
                            }
                        }
                    }
                }
                break;
            }

            case 16: {
                if (this->initialExplorationSatisfied() != 0) {
                    if (this->md->numberObjectsWithAction(0x25A) < this->sn[4] ||
                        this->wonderInProgressValue != 0 ||
                        this->wonderBuiltValue != 0) {
                        RGE_Static_Object* object = this->md->mostDamaged(0x1B, -1);
                        if (object != 0 && object->object_state == 2) {
                            RGE_Static_Object* existing = this->md->object(
                                -1, -1, -1, 0x26A, -1, object->id, -1, -1, -1, -1);
                            if (existing == 0) {
                                XYPoint position;
                                position.x = (int)object->world_x;
                                position.y = (int)object->world_y;
                                int id = this->civilian(&position, 1, 0x2BE, 0x2CE, 0x2BC, 0);
                                if (id != -1) {
                                    this->taskRepairer(id, object);
                                }
                            }
                        }
                    }
                }
                break;
            }

            case 17: {
                if (this->initialExplorationSatisfied() != 0) {
                    if ((this->md->numberObjectsWithAction(0x25A) < this->sn[4] ||
                         this->wonderInProgressValue != 0 ||
                         this->wonderBuiltValue != 0) &&
                        this->wonderInProgressValue == 0) {
                        BuildItem* item = this->md->buildAI.nextBuildableItem(0);
                        if (item != 0 &&
                            this->taskBuilder(-1, item, 0, startTime) == 1) {
                            this->lastBuildTime =
                                this->md->player->world->world_time;
                        }
                    }
                }
                break;
            }

            case 18: {
                if (this->placementStateValue.active == 1) {
                    ConstructionItem* construction =
                        this->md->constructionAI.placeStructure(
                            this->placementStateValue.buildItem,
                            this->placementStateValue.builderID,
                            this->placementStateValue,
                            startTime);
                    if (construction != 0) {
                        if (this->taskBuilder(this->placementStateValue.builderID,
                                              this->placementStateValue.buildItem,
                                              construction, startTime) == 1) {
                            this->lastBuildTime =
                                this->md->player->world->world_time;
                        }
                    }
                    if (this->placementStateValue.active == 1) {
                        incUpdateArea = 0;
                    }
                }
                break;
            }

            case 19: {
                this->evaluateOpenTasks();
                int i = 0;
                int* difference = this->resourceDifferenceValue;
                for (; i < 4; ++i, ++difference) {
                    if (*difference > 0 &&
                        this->md->resourceAI.resource(i) + *difference < 0) {
                        this->updateNeededResources();
                        break;
                    }
                }
                this->checkForCoopTributeDemand();
                this->checkForCoopTributeGift();
                this->checkForASAPAgeResearch();
                this->checkTradeBoats();
                this->checkStaleAttackGroups();
                break;
            }

            case 20: {
                int resource = this->md->informationAI.closestDropsiteResID(0);
                RGE_Static_Object* object = this->md->object(resource);
                if (object == 0) {
                    this->md->informationAI.updateResourceDropsites(0);
                }
                break;
            }

            case 21:
                this->evaluateBuildListInsertions();
                // BINARY NOTE: Wrap as unsigned, then use signed age division.
                if (5 < (int)(this->md->player->world->world_time -
                              this->lastBuildTime) / 60000) {
                    this->md->buildAI.unskipBuildList(this->builtFirstStoragePit,
                                                       this->builtFirstGranary);
                    this->lastBuildTime = this->md->player->world->world_time;
                }

                currentTime = debug_timeGetTime((char*)0x5880C0, 0xB92);
                this->md->player->world->useComputerPlayerUpdateTime(
                    currentTime - startTime);

                this->lastUpdateAreaTimeValue =
                    currentTime - updateAreaStartTime;
                this->updateAreaAverageTotal += this->lastUpdateAreaTimeValue;
                this->updateAreaAverageCount++;
                if (this->updateAreaAverageCount >= 20) {
                    this->averageUpdateAreaTimeValue =
                        this->updateAreaAverageTotal /
                        this->updateAreaAverageCount;
                    this->updateAreaAverageTotal = 0;
                    this->updateAreaAverageCount = 0;
                }

                this->updateArea = 0;
                this->md->player->world->selectNextComputerPlayer(3);
                return 1;

            default:
                break;
            }

            currentTime = debug_timeGetTime((char*)0x5880C0, 0xBAA);
            this->lastUpdateAreaTimeValue =
                currentTime - updateAreaStartTime;
            this->updateAreaAverageTotal += this->lastUpdateAreaTimeValue;
            this->updateAreaAverageCount++;
            if (this->updateAreaAverageCount >= 20) {
                this->averageUpdateAreaTimeValue =
                    this->updateAreaAverageTotal / 20;
                this->updateAreaAverageTotal = 0;
                this->updateAreaAverageCount = 0;
            }

            if (incUpdateArea != 0) {
                this->updateArea++;
            }
        } while (currentTime - startTime < availableTime);
    }

    currentTime = debug_timeGetTime((char*)0x5880C0, 0xBC9);
    this->md->player->world->useComputerPlayerUpdateTime(currentTime - startTime);
    return 1;
}
