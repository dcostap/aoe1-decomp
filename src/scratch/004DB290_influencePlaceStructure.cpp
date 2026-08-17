// VA: 004DB290 TribeInformationAIModule::influencePlaceStructure
// PDB: taiinfmd.cpp:2532-3206
//
// Attempt log:
// - baseline reconstruction: named information-AI, PlacementState, InfluenceMap,
//   building-lot, and master-building ownership; /GX new ConstructionItem paths;
//   ordered placement/zone/map-bound calls and nested candidate scans.
// - This claim tested 20 meaningful source, ABI, layout, control-flow, and
//   liveness hypotheses.  A diagnostic branch variant reached 3,425 diff bytes.
// - The current source is the best natural reconstruction after the probes.
//   It emits 3,834 of 3,868 bytes, 55 calls, and 67.14% shape similarity.
// - The source keeps /GX, the +0x3c player world field, and the inherited
//   AIModule logCommonHistory varargs surface from binary evidence.
// - A late timeout save label moves the second state strncpy near the original
//   block.  A late unsupported-size label preserves the original cold path.
// - The size-3 placement branch uses size-5 bounds for placements other than
//   6, 3, 4, 1, 2, and 8.  The original branch proves this behavior.
// - Direct builderID/state.builderID calls and separate currentZone fallback
//   receivers match the original branch order and improve call alignment.
// - Tested and rejected: direct master expressions, coordinate receiver
//   branches, state aliases, declaration scopes, label order, and ABI aliases.
// - Open drift: the frame is 0x188 versus 0x190.  The early register colors,
//   first cold log block, and many stack homes still differ.

#include <math.h>
#include <stdlib.h>

#pragma intrinsic(sqrt)

typedef unsigned char uchar;
typedef unsigned long ulong;

class AIModuleMessage;
class BuildItem;
class ConstructionItem;
class RGE_Game_World;
class RGE_Player;
class RGE_Static_Object;
class RGE_Master_Static_Object;
class RGE_Master_Combat_Object;
class RGE_Sprite;
class RGE_Sound;
class RGE_Color_Table;
class TDrawArea;
class XYPoint;
class RGE_Armor_Weapon_Info;
class OrderEvent;
class NotifyEvent;
class LOSTBL;

class AIModuleID {
public:
    virtual ~AIModuleID();
    int id;
    char name[64];
};

class AIModule {
public:
    virtual ~AIModule();

    AIModuleID idValue;
    int playerNumberValue;
    char playerNameValue[64];
    int runningValue;
    int pausedValue;
    int logHistoryValue;
    int logCommonHistoryValue;
    void* historyLogFile;
    char historyLogFilename[64];
    int intelligenceLevelValue;
    int priorityValue;
    int processFrameValue;
    void logCommonHistory(char* format, ...);
};

class InformationAIModule : public AIModule {
public:
    virtual ~InformationAIModule();
};

class BaseItem {
public:
    virtual ~BaseItem();

    int typeID();
    int uniqueID();
    void setTypeID(int value);
    float x();
    float y();
    float xSize();
    float ySize();
    char* name();

    int typeIDValue;
    int gameIDValue;
    int uniqueIDValue;
    char nameValue[64];
    float xValue;
    float yValue;
    float zValue;
    float xSizeValue;
    float ySizeValue;
    float zSizeValue;
    int skipValue;
};

class BuildItem : public BaseItem {
};

class ConstructionItem : public BaseItem {
public:
    virtual ~ConstructionItem();
    ConstructionItem(float p1, float p2, float p3, float p4,
                     float p5, float p6, int p7, const char* p8);
    ConstructionItem(ConstructionItem* item);

    ConstructionItem* next;
    ConstructionItem* prev;
    int inProgressValue;
    int builtValue;
    int buildAttemptsValue;
};

struct XYPoint {
    int x;
    int y;
};

class InfluenceMap {
public:
    virtual ~InfluenceMap();

    int xSizeValue;
    int ySizeValue;
    int xReferencePointValue;
    int yReferencePointValue;
    unsigned char* valueValue;
    unsigned char** rowValue;
    int coverageCountValue;
    int connectionCountValue;
    unsigned char unchangeableLimitValue;
    unsigned char pad_end[3];

    int connectionsIncluding(XYPoint* min, XYPoint* max,
                             uchar base, uchar wanted,
                             int mode1, int mode2, int allDirections);
    int lookupValue(int x, int y);
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0xF4];
    unsigned int availableComputerPlayerUpdateTime;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x20];
    RGE_Master_Static_Object** master_objects;
    char gap_28[0x10];
    RGE_Game_World* world;
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object* object);
    virtual void modify(float amount, uchar player);
    virtual void modify_delta(float amount, uchar player);
    virtual void modify_percent(float amount, uchar player);
    virtual void save(int file);
    virtual RGE_Static_Object* make_new_obj(RGE_Player* player,
                                            float x, float y, float z);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual uchar check_placement(RGE_Player* player, float x, float y,
                                  int* result, uchar p5, uchar p6,
                                  uchar p7, uchar p8, uchar p9, uchar p10);
    virtual uchar alignment(float* p1, float* p2, RGE_Game_World* world,
                            uchar value);
    virtual long calc_base_damage_ability(RGE_Master_Combat_Object* object);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void draw(TDrawArea* area, short x, short y,
                      RGE_Color_Table* colors, long p5, long p6,
                      int p7, uchar p8);
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_04[0x34];
    float world_x;
    float world_y;

    uchar currentZone();
    uchar lookupZone(int x, int y);
};

class MainDecisionAIModule : public AIModule {
public:
    RGE_Player* player;
    char gap_F4[0x10];

    RGE_Static_Object* object(int p1, int p2, int p3, int p4, int p5,
                              int p6, int p7, int p8, int p9, int p10);
    RGE_Static_Object* object(int id);
};

class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    int inAge(int age);
    int strategicNumber(int number);
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    char gap_104[0x1146c - 0x104];
    TribeTacticalAIModule tacticalAI;
};

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

struct BuildingLot {
    int typeID;
    uchar status;
    uchar x;
    uchar y;
    uchar pad_07;
};

struct PlacementState {
    int buildingTypeID;
    float buildingSize;
    char buildingName[0x100];
    int builderID;
    int minimumDistance;
    int maximumDistance;
    int active;
    XYPoint bestPoint;
    int bestPointValue;
    int iterationX;
    int randomInfluence;
    BuildItem* buildItem;
};

class TribeInformationAIModule : public InformationAIModule {
public:
    ManagedArray<int> farmsTaskedThisUpdate;
    TribeMainDecisionAIModule* md;
    int mapXSizeValue;
    int mapYSizeValue;
    int lastUpdateRowValue;
    int maxImportantObjectMemory;
    void* importantObjectMemory;
    ManagedArray<int> importantObjects;
    ManagedArray<int> importantUnits;
    ManagedArray<int> importantMiscs;
    ManagedArray<int> itemsToDefend;
    InfluenceMap pathMap;
    ManagedArray<int> playerObjects;
    ManagedArray<int> playerBuildings;
    XYPoint lastWallPosition;
    XYPoint lastWallPosition2;
    int numberGatesValue;
    XYPoint minGatePosition[4];
    XYPoint maxGatePosition[4];
    int maxBuildingLots;
    BuildingLot* buildingLots;
    int maxAttackMemories;
    void* attackMemories;
    int saveLearnInformationValue;

    int placementCode(int type);
    int mapBound(XYPoint* point);
    BuildingLot* availableLot(int type);
    void setupInfluenceMap(int mode, int objectType, XYPoint* unused,
                           XYPoint* from, XYPoint* to);
    int isNextTo(XYPoint* from, XYPoint* to, int mode);
    int facetTo(XYPoint& from, XYPoint& to);
    int undesirableLot(int type, uchar x, uchar y, int value);
    void storeLot(int type, uchar x, uchar y, uchar status);

    ConstructionItem* influencePlaceStructure(
        BuildItem* item, int builderID, int objectType, float objectSize,
        char* objectName, int minimumDistance, int centerX, int centerY,
        int maxClearX, PlacementState& state, ulong currentTime);
};

void* operator new(unsigned int size);
void operator delete(void* ptr);

extern "C" char* strncpy(char* destination, const char* source,
                          unsigned int count);
extern "C" int __cdecl debug_rand(char* file, int line);
extern "C" unsigned long __cdecl debug_timeGetTime(char* file, int line);

extern float DAT_00575564;
extern float DAT_00575570;
extern float DAT_00575574;
extern float DAT_00575578;
extern float DAT_0057557c;

InfluenceMap* const iMap = (InfluenceMap*)0x86BC38;

ConstructionItem* TribeInformationAIModule::influencePlaceStructure(
    BuildItem* item, int builderID, int objectType, float objectSize,
    char* objectName, int minimumDistance, int centerX, int centerY,
    int maxClearX, PlacementState& state, ulong currentTime)
{
    float buildingSize;
    int buildingType;
    int x;
    int randSelect;
    int placementType;
    int placement;
    XYPoint bestPoint;
    int basePlacementTotal;
    int y;
    int candidate;
    int maximumDistance;
    XYPoint centerPoint;
    XYPoint maxClear;
    XYPoint minClear;
    int bestPointValue;
    int minimumDistanceValue;
    int local_154;
    XYPoint max;
    ulong availableTime;
    int firstTimeThrough;
    int useExcludeRegion;
    XYPoint min;
    XYPoint maxExclude;
    XYPoint minExclude;
    int blockingObject;
    int local_120;
    XYPoint newPosition;
    char buildingName[0x100];
    RGE_Static_Object* townCenter;
    RGE_Static_Object* builderObject;
    RGE_Static_Object* coordinateObject;
    RGE_Static_Object* placementObject;

    placementObject = this->md->object(-1, -1, 4, -1, -1,
                                       -1, -1, -1, -1, -1);
    if (placementObject == 0) {
        state.active = 0;
    } else {
    if (state.active == 1) {
        x = state.buildingTypeID;
        buildingSize = state.buildingSize;
        objectName = state.buildingName;
    } else if (item == 0) {
        x = objectType;
        buildingSize = objectSize;
    } else {
        x = item->typeID();
        buildingSize = item->xSize();
        objectName = item->name();
    }

    strncpy(buildingName + 4, objectName, 0xff);
    buildingType = (int)buildingSize;
    newPosition.x = buildingType;
    y = buildingType * buildingType * 0x14;

    if (this->md->player->master_objects[x] != 0) {
        RGE_Master_Static_Object* masterObj =
            this->md->player->master_objects[x];
        townCenter = this->md->object(-1, 0x6d, -1, -1, -1,
                                      -1, -1, -1, -1, -1);
        if (state.active == 1)
            builderObject = this->md->object(state.builderID);
        else
            builderObject = this->md->object(builderID);

    if (item == 0 && state.active != 1) {
        centerPoint.x = centerX;
        local_154 = minimumDistance;
        centerPoint.y = centerY;
        maxClear.x = maxClearX;
    } else {
        coordinateObject = townCenter;
        if (coordinateObject == 0)
            coordinateObject = builderObject;
        if (coordinateObject == 0)
            coordinateObject = placementObject;

        centerPoint.y = (int)coordinateObject->world_x;
        maxClear.x = (int)coordinateObject->world_y;
    }

    placement = this->placementCode(x);

    if (placement == -1) {
        this->logCommonHistory(
            (char*)"Invalid influence placement type id (%d), bombing.", x);
    } else {
    if (item == 0 && state.active != 1) {
        placementObject->lookupZone(centerY, maxClearX);
    } else {
        if (placement == 1) {
            local_154 = 7;
            int placementRadius;
            placementRadius = this->md->tacticalAI.inAge(2);
            if (placementRadius == 0) {
                placementRadius = this->md->tacticalAI.inAge(3);
                if (placementRadius == 0) {
                    placementRadius = this->md->tacticalAI.inAge(4);
                    if (placementRadius != 0)
                        placementRadius = 4;
                    else
                        placementRadius = 1;
                } else {
                    placementRadius = 3;
                }
            } else {
                placementRadius = 2;
            }
            centerPoint.x = this->md->tacticalAI.strategicNumber(0x56) *
                            placementRadius;
        } else if (placement == 2) {
            int placementValue =
                this->md->tacticalAI.strategicNumber(0x57);
            local_154 = 4;
            centerPoint.x = placementValue;
        } else if (placement == 3 || placement == 4) {
            local_154 = this->md->tacticalAI.strategicNumber(0x49);
            centerPoint.x = this->md->tacticalAI.strategicNumber(0x4a);
        } else {
            local_154 = 4;
            centerPoint.x = this->md->tacticalAI.strategicNumber(0x4a);
        }

        if (townCenter == 0)
            townCenter = placementObject;
        townCenter->currentZone();

    }

    if (local_154 < centerPoint.x) {
        min.x = centerPoint.y - centerPoint.x;
        min.y = maxClear.x - centerPoint.x;
        this->mapBound(&min);

        max.x = centerPoint.y + centerPoint.x;
        max.y = maxClear.x + centerPoint.x;
        this->mapBound(&max);

        minExclude.x = centerPoint.y - local_154;
        minExclude.y = maxClear.x - local_154;
        this->mapBound(&minExclude);

        maxExclude.x = centerPoint.y + local_154;
        maxExclude.y = maxClear.x + local_154;
        this->mapBound(&maxExclude);

        if (item != 0 && state.active == 0) {
            BuildingLot* lot = this->availableLot(x);
            if (lot != 0) {
                ConstructionItem* result;
                if (placement == 4) {
                    this->lastWallPosition2.x = this->lastWallPosition.x;
                    this->lastWallPosition2.y = this->lastWallPosition.y;
                    this->lastWallPosition.x = lot->x;
                    this->lastWallPosition.y = lot->y;
                }

                if (buildingSize == DAT_00575574) {
                    result = new ConstructionItem(
                        (float)lot->x, (float)lot->y, 1.0f,
                        buildingSize, buildingSize, 1.0f, x,
                        buildingName + 4);
                } else {
                    result = new ConstructionItem(
                        (float)lot->x - DAT_00575570,
                        (float)lot->y - DAT_00575570,
                        1.0f, buildingSize, buildingSize, 1.0f, x,
                        buildingName + 4);
                }
                lot->status = 1;
                state.active = 0;
                return result;
            }
        }

        if (item == 0 && state.active == 0)
            this->setupInfluenceMap(placement, x, &centerPoint, &min, &max);

        if (state.active == 0) {
            int maxInfluence = this->md->tacticalAI.strategicNumber(0xa8);
            if (maxInfluence < 1) {
                placementType = 0;
            } else {
                placementType = debug_rand(
                    (char*)"C:\\msdev\\work\\age1_x1\\taiinfmd.cpp",
                    0xac8) % maxInfluence;
            }
            bestPoint.x = -1;
            basePlacementTotal = -1;
            minimumDistanceValue = -1;
            randSelect = min.x;
        } else {
            placementType = state.randomInfluence;
            bestPoint.x = state.bestPoint.x;
            basePlacementTotal = state.bestPoint.y;
            minimumDistanceValue = state.bestPointValue;
            randSelect = state.iterationX;
        }

        availableTime = this->md->player->world->availableComputerPlayerUpdateTime;
        firstTimeThrough = debug_timeGetTime(
            (char*)"C:\\msdev\\work\\age1_x1\\taiinfmd.cpp", 0xade);

        if (state.active == 0 && availableTime <= firstTimeThrough - currentTime) {
            state.buildingTypeID = x;
            strncpy(state.buildingName, buildingName + 4, 0xff);
            state.buildingSize = buildingSize;
            state.builderID = builderID;
            state.minimumDistance = local_154;
            state.maximumDistance = centerPoint.x;
            state.bestPoint.x = bestPoint.x;
            state.active = 1;
            state.bestPoint.y = basePlacementTotal;
            state.bestPointValue = minimumDistanceValue;
            state.iterationX = randSelect;
            state.randomInfluence = placementType;
            state.buildItem = item;
            return 0;
        }

        min.x = 0;
        if (placement == 4 || placement == 3)
            min.x = 1;

        useExcludeRegion = 1;
        if (randSelect <= max.x) {
            do {
                if (useExcludeRegion != 0) {
                    useExcludeRegion = 0;
                    maximumDistance = min.y;
                } else {
                    firstTimeThrough = debug_timeGetTime(
                        (char*)"C:\\msdev\\work\\age1_x1\\taiinfmd.cpp",
                        0xb16);
                    maximumDistance = min.y;
                    if (availableTime <= firstTimeThrough - currentTime) {
                        goto save_state_second;
                    }
                }

                candidate = maximumDistance;
                if (candidate <= max.y) {
                    do {
                        if (min.x != 1 || randSelect < minExclude.x ||
                            maxExclude.x < randSelect ||
                            candidate < minExclude.y ||
                            maxExclude.y < candidate) {
                            if (buildingSize == DAT_00575578) {
                                minClear.x = randSelect - 2;
                                minClear.y = candidate - 2;
                                maxClear.x = randSelect + 2;
                                maxClear.y = candidate + 2;
                                bestPointValue = candidate - 2;
                            } else if (buildingSize == DAT_0057557c) {
                                if (placement == 6 || placement == 3 ||
                                    placement == 4 || placement == 1 ||
                                    placement == 2 || placement == 8) {
                                    minClear.x = randSelect - 1;
                                    minClear.y = candidate - 1;
                                    maxClear.x = randSelect + 1;
                                    maxClear.y = candidate + 1;
                                    bestPointValue = candidate - 1;
                                } else {
                                    minClear.x = randSelect - 2;
                                    minClear.y = candidate - 2;
                                    maxClear.x = randSelect + 2;
                                    maxClear.y = candidate + 2;
                                    bestPointValue = candidate - 2;
                                }
                            } else if (buildingSize == DAT_00575574) {
                                if (placement == 6 || placement == 3 ||
                                    placement == 4) {
                                    minClear.x = randSelect;
                                    minClear.y = candidate - 1;
                                    maxClear.x = randSelect - 1;
                                    maxClear.y = candidate;
                                    bestPointValue = candidate - 1;
                                } else {
                                    minClear.x = randSelect + 1;
                                    minClear.y = candidate - 2;
                                    maxClear.x = randSelect - 2;
                                    maxClear.y = candidate + 1;
                                    bestPointValue = candidate - 2;
                                }
                            } else {
                                if (buildingSize != DAT_00575564) {
                                    goto unsupported_size;
                                }
                                minClear.x = randSelect;
                                minClear.y = candidate;
                                maxClear.x = randSelect;
                                maxClear.y = candidate;
                                bestPointValue = candidate;
                                if (placement != 6 &&
                                    placement != 3 && placement != 4) {
                                    minClear.x = randSelect - 1;
                                    minClear.y = candidate - 1;
                                    maxClear.x = randSelect + 1;
                                    maxClear.y = candidate + 1;
                                    bestPointValue = candidate - 1;
                                }
                            }

                            if (this->mapBound(&minClear) != 1 &&
                                this->mapBound(&maxClear) != 1) {
                                local_120 = -1;
                                if (masterObj->check_placement(
                                        this->md->player,
                                        (float)randSelect - DAT_00575570,
                                        (float)candidate - DAT_00575570,
                                        &local_120, 1, 1, 1, 1, 1, 1) == 0) {
                                    int score = 0;
                                    int blocked = 0;
                                    int row = minClear.x;

                                    while (blocked == 0 && row <= maxClear.x) {
                                        int column = minClear.y;
                                        while (blocked == 0 &&
                                               column <= maxClear.y) {
                                            int value = iMap->lookupValue(
                                                row, column);
                                            if (value == 0xff)
                                                blocked = 1;
                                            else
                                                score += value;
                                            column++;
                                        }
                                        row++;
                                    }

                                    if (blocked == 0) {
                                        int connectionsBefore =
                                            iMap->connectionCountValue;
                                        if (placement == 4 ||
                                            placement == 6) {
                                            int connections =
                                                iMap->connectionsIncluding(
                                                    &minClear, &maxClear,
                                                    0xff, 0xff, 1, 0, 1);
                                            if (placement == 4 &&
                                                6 < connections -
                                                    connectionsBefore)
                                                goto candidate_done;
                                            score = (connections -
                                                     connectionsBefore) * score;
                                        }

                                        if (placement == 4) {
                                            newPosition.y = randSelect;
                                            if (this->lastWallPosition.x != -1 &&
                                                this->isNextTo(
                                                    &this->lastWallPosition,
                                                    &newPosition, 0) == 0)
                                                score /= 2;

                                            int direction = this->facetTo(
                                                this->lastWallPosition,
                                                newPosition);
                                            if ((abs(direction) & 1) == 1)
                                                score *= 3;

                                            int previousDirection = this->facetTo(
                                                this->lastWallPosition2,
                                                this->lastWallPosition);
                                            if (previousDirection == direction)
                                                score *= 3;

                                            int dx = abs(this->lastWallPosition.x -
                                                         centerPoint.y);
                                            int dy = abs(this->lastWallPosition.y -
                                                         maxClear.x);
                                            if (dy < dx) {
                                                if (direction == 1 || direction == 5)
                                                    score *= 3;
                                            } else if (dx < dy) {
                                                if (direction == 3 || direction == 7)
                                                    score *= 3;
                                            }
                                        } else if (placement == 1 ||
                                                   placement == 2) {
                                            if (this->undesirableLot(
                                                    x, (uchar)randSelect,
                                                    (uchar)candidate, 10) == 1)
                                                score /= 10;
                                        } else if (placement != 6) {
                                            if (this->undesirableLot(
                                                    x, (uchar)randSelect,
                                                    (uchar)candidate, newPosition.x) == 1)
                                                score /= 10;
                                        }

                                        if (placement == 1 ||
                                            placement == 2) {
                                            int distanceSquared =
                                                (randSelect - centerPoint.y) *
                                                    (randSelect - centerPoint.y) +
                                                (candidate - maxClear.x) *
                                                    (candidate - maxClear.x);
                                            int distance =
                                                (int)sqrt((float)distanceSquared);
                                            if (distance > 10) {
                                                int adjusted = score -
                                                    (distance - 10) / 5;
                                                if (candidate < adjusted)
                                                    score = adjusted;
                                            }
                                        }

                                        if (minimumDistanceValue == -1 ||
                                            minimumDistanceValue <
                                                score + placementType) {
                                            if (score <= minimumDistanceValue)
                                                placementType /= 2;
                                            bestPoint.x = randSelect;
                                            minimumDistanceValue = score;
                                            basePlacementTotal = candidate;
                                        }
                                    }
                                }
                            }
                        }

candidate_done:
                        candidate++;
                    } while (candidate <= max.y);
                }

                randSelect++;
            } while (randSelect <= max.x);
        }

        if (minimumDistanceValue != -1 &&
            (y < minimumDistanceValue ||
             (placement != 2 &&
              (y < minimumDistanceValue || placement != 1)))) {
            if (placement == 4) {
                this->lastWallPosition2.x = this->lastWallPosition.x;
                this->lastWallPosition2.y = this->lastWallPosition.y;
                this->lastWallPosition.x = bestPoint.x;
                this->lastWallPosition.y = basePlacementTotal;
            }

            if (item == 0 && state.active != 1) {
                this->storeLot(x, (uchar)bestPoint.x,
                               (uchar)basePlacementTotal, 0);
                state.active = 0;
                return (ConstructionItem*)1;
            }

            ConstructionItem* result;
            if (buildingSize == DAT_00575574) {
                result = new ConstructionItem(
                    (float)bestPoint.x, (float)basePlacementTotal,
                    1.0f, buildingSize, buildingSize, 1.0f, x,
                    buildingName + 4);
            } else {
                result = new ConstructionItem(
                    (float)bestPoint.x - DAT_00575570,
                    (float)basePlacementTotal - DAT_00575570,
                    1.0f, buildingSize, buildingSize, 1.0f, x,
                    buildingName + 4);
            }
            this->storeLot(x, (uchar)bestPoint.x,
                           (uchar)basePlacementTotal, 1);
            state.active = 0;
            return result;
        }

        if (placement == 4) {
            this->lastWallPosition2.x = this->lastWallPosition.x;
            this->lastWallPosition2.y = this->lastWallPosition.y;
            this->lastWallPosition.x = -1;
            this->lastWallPosition.y = -1;
        }
    }
    }

save_state_second:
    state.buildingTypeID = x;
    strncpy(state.buildingName, buildingName + 4, 0xff);
    state.buildingSize = buildingSize;
    state.builderID = builderID;
    state.minimumDistance = local_154;
    state.maximumDistance = centerPoint.x;
    state.bestPoint.x = bestPoint.x;
    state.active = 1;
    state.bestPoint.y = basePlacementTotal;
    state.bestPointValue = minimumDistanceValue;
    state.iterationX = randSelect;
    state.randomInfluence = placementType;
    state.buildItem = item;
    return 0;

unsupported_size:
    this->logCommonHistory(
        (char*)"    Unsupported building size (%d x %d), failing.",
        buildingSize, buildingSize);
    }
    state.active = 0;
    }
    return 0;
}
