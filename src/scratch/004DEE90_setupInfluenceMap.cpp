// 004DEE90 TribeInformationAIModule::setupInfluenceMap
// PDB: taiinfmd.cpp:4965-5522
// Attempt log:
// - Baseline reconstruction: named InfluenceMap/resource/building/attack-memory
//   ownership, map dimensions, typed record arrays, and the ordered terrain,
//   attack-memory, tactical, connection, and building-lot phases.
// - The source keeps the period-style nested scans and inline ManagedArray
//   operator[] growth instead of decompiler cursor aliases.
// - Reconstructed resource group dispatch with the binary's negative group
//   guard; this restored ordered increment/decrement call sites.
// - Same-TU RGE master donor fixes radius_x/radius_y to +0x30/+0x34, with
//   LOS at +0x28 and an intervening float.  Radius placement keeps both
//   binary-observed bound forms.
// - Building bounds use the object's world coordinates; later mode radii use
//   the master object's LOS field at +0x28.  The one-meaningful-probe volatile
//   reload experiment matched frame/call shape better but was rolled back as
//   compiler-steering scaffolding.
// - Final clean candidate remains non-exact: frame is 0x6c vs 0x70 and six
//   repeated building-coordinate ftol sites are still CSE'd by VC5.

#include <stdlib.h>

typedef unsigned char uchar;

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
            T* new_value = (T*)operator new(new_size * sizeof(T));
            if (new_value != 0) {
                for (int i = 0; i < this->maximumSizeValue && i < new_size; i++) {
                    new_value[i] = this->value[i];
                }
                operator delete(this->value);
                this->value = new_value;
                this->maximumSizeValue = new_size;
            }
        }
        return this->value[index];
    }
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
    unsigned char _pad_end[3];

    int initialize(uchar value);
    void setUnchangeableLimit(uchar value);
    void setReferencePoint(int x, int y);
    int setValue(int x, int y, uchar value);
    int setValue(int x1, int y1, int x2, int y2, uchar value);
    int incrementValue(int x, int y, int value);
    int incrementValue(int x1, int y1, int x2, int y2, int value);
    int decrementValue(int x, int y, uchar value);
    int decrementValue(int x1, int y1, int x2, int y2, int value);
    int setConnectionCount(const XYPoint& min, const XYPoint& max,
                           int threshold, int p4, int p5, int p6);
};

InfluenceMap* const iMap = (InfluenceMap*)0x86BC38;

class RGE_Map {
public:
    struct Tile {
        char gap_00[5];
        unsigned char terrain;
        char gap_06[0x12];
    };

    char gap_00[0x8D8C];
    Tile** map_row_offset;

    unsigned char get_terrain(short x, short y);
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x24];
    RGE_Map* map;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x0C];
    short id;
    short _pad_12;
    short object_group;
    char gap_16[0x12];
    float los;
    float radiusValue;
    float radius_x;
    float radius_y;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_04[4];
    RGE_Master_Static_Object* master_obj;
    char gap_0C[0x2C];
    float world_x;
    float world_y;
};

class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0xEC];
};

class BuildAIModule : public AIModule {
public:
    int numberBuiltItemsOfType(int type, int owner);
};

class TribeBuildAIModule : public BuildAIModule {
public:
    char gap_F0[0x11368 - 0xF0];
};

class MainDecisionAIModule {
public:
    virtual ~MainDecisionAIModule();
    char gap_04[0xEC];
    RGE_Player* player;
    char gap_F4[0x10];

    RGE_Static_Object* object(int id);
};

class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    void setGroupInfluences(InfluenceMap* map);
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    TribeBuildAIModule buildAI;
    TribeTacticalAIModule tacticalAI;
};

struct ResourceMemory {
    int id;
    unsigned char x;
    unsigned char y;
    unsigned char gatherAttempts;
    unsigned char _pad_07;
    int gatherValue;
    unsigned char valid;
    unsigned char gone;
    unsigned char dropDistance;
    unsigned char resourceType;
    int dropsiteID;
};

struct BuildingLot {
    int typeID;
    unsigned char status;
    unsigned char x;
    unsigned char y;
    unsigned char _pad_07;
};

struct AttackMemory {
    int id;
    unsigned char type;
    unsigned char minX;
    unsigned char minY;
    unsigned char maxX;
    unsigned char maxY;
    unsigned char attackingOwner;
    unsigned char targetOwner;
    unsigned char _pad_0B;
    short kills;
    unsigned char success;
    unsigned char _pad_0F;
    unsigned long timeStamp;
    int play;
};

class InformationAIModule : public AIModule {
public:
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
    AttackMemory* attackMemories;
    int saveLearnInformationValue;
    char learnFileName[256];
    unsigned char fullyExploredZoneValue[255];
    unsigned char _pad_407;
    int quadrantLog[16 * 3];
    int** resourceTypesValue;
    int* numberResourceTypesValue;
    ResourceMemory* resources[4];
    int numResources[4];

    int mapBound(XYPoint* point);
    int resourceTypeToPlaceDropsiteBy(int type);
    int placementCode(int type);

    void setupInfluenceMap(int mode, int objectType, XYPoint* unused,
                           XYPoint* from, XYPoint* to);
};

extern "C" void __cdecl logCommonHistory(void* self, const char* format, ...);
extern float DAT_00575564;
extern float DAT_0057556c;
extern float DAT_00575578;
extern double DAT_00575598;
extern double DAT_005755a0;
extern double DAT_005755a8;
extern float DAT_005755b0;
extern float DAT_005755b4;

void TribeInformationAIModule::setupInfluenceMap(int mode, int objectType,
                                                   XYPoint* unused,
                                                   XYPoint* from,
                                                   XYPoint* to)
{
    iMap->initialize(0x14);
    iMap->setUnchangeableLimit(0xff);

    this->md->buildAI.numberBuiltItemsOfType(0x44, 0);
    this->md->buildAI.numberBuiltItemsOfType(0x67, 0);

    XYPoint min;
    XYPoint max;
    min.x = 0;
    min.y = 0;
    max.x = this->mapXSizeValue;
    max.y = this->mapYSizeValue;

    if (mode == 3 || mode == 4 || mode == 0) {
        XYPoint innerMax;
        innerMax.x = this->mapXSizeValue - 5;
        innerMax.y = this->mapYSizeValue - 5;

        for (int x = 0; x < max.x; x++) {
            for (int y = 0; y < max.y; y++) {
                if (x < 5 || x > innerMax.x || y < 5 || y > innerMax.y) {
                    iMap->decrementValue(x, y, 10);
                }
            }
        }
    }

    if (mode == 1 || mode == 2 || mode == 9) {
        int dropsiteType = this->resourceTypeToPlaceDropsiteBy(mode);

        for (int resourceType = 0; resourceType < 4; resourceType++) {
            for (int i = 0; i < this->numResources[resourceType]; i++) {
                ResourceMemory* resource = &this->resources[resourceType][i];
                if (resource->gone != 1) {
                    RGE_Static_Object* object = this->md->object(resource->id);
                    if (object != 0) {
                        XYPoint bMin;
                        XYPoint bMax;
                        XYPoint bMinLOS;
                        float radiusY = object->master_obj->radius_y;

                        bMin.x = (int)(object->world_x - object->master_obj->radius_x - 1.0f);
                        bMin.y = (int)(object->world_y - radiusY - 1.0f);
                        this->mapBound(&bMin);
                        bMax.x = (int)(object->world_x + radiusY + 1.0f);
                        bMax.y = (int)(object->world_y + radiusY + 1.0f);
                        this->mapBound(&bMax);
                        bMinLOS.x = (int)object->master_obj->radius_x;
                        bMinLOS.y = (int)object->master_obj->radius_y;
                        this->mapBound(&bMinLOS);

                        if (mode == 1 || mode == 2) {
                            iMap->setValue(bMinLOS.x, bMinLOS.y, 0xff);
                        } else {
                            iMap->setValue(bMin.x, bMin.y, bMax.x, bMax.y, 0xff);
                        }

                        if (mode == 1) {
                            short group = object->master_obj->object_group;
                            if (group != 7) {
                                if (dropsiteType == -1 ||
                                    (dropsiteType == 3 && group == 0x20) ||
                                    (dropsiteType == 2 && group == 8) ||
                                    (dropsiteType == 1 && group == 0x0f) ||
                                    (dropsiteType == 0 && group != 0x20 &&
                                     group != 8 && group != 0x0f)) {
                                    bMin.x -= 1;
                                    bMin.y -= 1;
                                    this->mapBound(&bMin);
                                    bMax.x += 1;
                                    bMax.y += 1;
                                    this->mapBound(&bMax);
                                    iMap->incrementValue(bMin.x, bMin.y,
                                                          bMax.x, bMax.y, 8);

                                    bMin.x -= 3;
                                    bMin.y -= 3;
                                    this->mapBound(&bMin);
                                    bMax.x += 3;
                                    bMax.y += 3;
                                    this->mapBound(&bMax);
                                    iMap->incrementValue(bMin.x, bMin.y,
                                                          bMax.x, bMax.y, 4);

                                    bMin.x -= 5;
                                    bMin.y -= 5;
                                    this->mapBound(&bMin);
                                    bMax.x += 5;
                                    bMax.y += 5;
                                    this->mapBound(&bMin);
                                    iMap->incrementValue(bMin.x, bMin.y,
                                                          bMax.x, bMax.y, 2);
                                }
                            } else {
                                if (object->master_obj->object_group == 7) {
                                    bMin.x -= 5;
                                    bMin.y -= 5;
                                    this->mapBound(&bMin);
                                    bMax.x += 5;
                                    bMax.y += 5;
                                    this->mapBound(&bMax);
                                    iMap->decrementValue(bMin.x, bMin.y,
                                                          bMax.x, bMax.y, 0x80);
                                }
                            }
                        } else if (mode == 2 &&
                                   object->master_obj->object_group == 7) {
                            bMin.x -= 3;
                            bMin.y -= 3;
                            this->mapBound(&bMin);
                            bMax.x += 3;
                            bMax.y += 3;
                            this->mapBound(&bMin);
                            iMap->incrementValue(bMin.x, bMin.y,
                                                  bMax.x, bMax.y, 0x80);
                        }
                    }
                }
            }
        }
    }

    if ((mode == 1 || mode == 2 || mode == 3 || mode == 4 || mode == 0 ||
         mode == 5 || mode == 6 || mode == 8) &&
        this->playerBuildings.numberValue > 0) {
        for (int i = 0; i < this->playerBuildings.numberValue; i++) {
            RGE_Static_Object* object = this->md->object(this->playerBuildings[i]);
            if (object != 0) {
                int placement = this->placementCode(object->master_obj->id);
                float radiusX = object->master_obj->radius_x;
                float radiusY = object->master_obj->radius_y;
                XYPoint bMin;
                XYPoint bMax;

                if (radiusX == 2.5) {
                    bMin.x = (int)object->world_x;
                    bMin.x -= 3;
                    bMin.y = (int)object->world_y;
                    bMin.y -= 3;
                    bMax.x = (int)object->world_x;
                    bMax.x += 3;
                    bMax.y = (int)object->world_y;
                    bMax.y += 3;
                } else if (radiusX == 1.5) {
                    if (placement == 6) {
                        bMin.x = (int)object->world_x;
                        bMin.x -= 1;
                        bMin.y = (int)object->world_y;
                        bMin.y -= 1;
                        bMax.x = (int)object->world_x;
                        bMax.y = (int)object->world_y;
                    } else if (objectType == 0x46) {
                        bMin.x = (int)object->world_x;
                        bMin.x -= 3;
                        bMin.y = (int)object->world_y;
                        bMin.y -= 3;
                        bMax.x = (int)object->world_x;
                        bMax.x += 3;
                        bMax.y = (int)object->world_y;
                        bMax.y += 3;
                    } else {
                        bMin.x = (int)object->world_x;
                        bMin.x -= 2;
                        bMin.y = (int)object->world_y;
                        bMin.y -= 2;
                        bMax.x = (int)object->world_x;
                        bMax.x += 2;
                        bMax.y = (int)object->world_y;
                        bMax.y += 2;
                    }
                } else if (radiusX == 1.0) {
                    if (placement == 6 || placement == 3) {
                        bMin.x = (int)object->world_x;
                        bMin.x -= 1;
                        bMin.y = (int)object->world_y;
                        bMin.y -= 1;
                        bMax.x = (int)object->world_x;
                        bMax.y = (int)object->world_y;
                    } else {
                        bMin.x = (int)object->world_x;
                        bMin.x -= 2;
                        bMin.y = (int)object->world_y;
                        bMin.y -= 2;
                        bMax.x = (int)object->world_x;
                        bMax.x += 1;
                        bMax.y = (int)object->world_y;
                        bMax.y += 1;
                    }
                } else if (radiusX == 0.5) {
                    if (placement == 6 || placement == 4) {
                        bMin.x = (int)object->world_x;
                        bMin.y = (int)object->world_y;
                        bMax.x = (int)object->world_x;
                        bMax.y = (int)object->world_y;
                    } else {
                        bMin.x = (int)object->world_x;
                        bMin.x -= 1;
                        bMin.y = (int)object->world_y;
                        bMin.y -= 1;
                        bMax.x = (int)object->world_x;
                        bMax.x += 1;
                        bMax.y = (int)object->world_y;
                        bMax.y += 1;
                    }
                } else {
                    logCommonHistory(this, "    Unsupported building size (%d x %d).",
                                     (double)(radiusX + radiusX),
                                     (double)((float)radiusY + (float)radiusY));
                    continue;
                }

                if (placement == 0x6d) {
                    bMin.x--;
                    bMin.y--;
                    bMax.x++;
                    bMax.y++;
                }
                this->mapBound(&bMin);
                this->mapBound(&bMax);
                iMap->setValue(bMin.x, bMin.y, bMax.x, bMax.y, 0xff);

                if (mode == 3 || mode == 0) {
                    int radius = (int)object->master_obj->los;
                    XYPoint minLOS;
                    XYPoint maxLOS;
                    minLOS.x = bMin.x - radius;
                    minLOS.y = bMin.y - radius;
                    this->mapBound(&minLOS);
                    maxLOS.x = bMax.x + radius;
                    maxLOS.y = bMax.y + radius;
                    this->mapBound(&maxLOS);
                    if (mode == 0 && placement == 3) {
                        iMap->incrementValue(minLOS.x, minLOS.y,
                                              maxLOS.x, maxLOS.y, 10);
                    } else {
                        iMap->decrementValue(minLOS.x, minLOS.y,
                                              maxLOS.x, maxLOS.y, 10);
                    }
                } else if (mode == 1 || mode == 2) {
                    int radius = (int)object->master_obj->los;
                    XYPoint aMax;
                    XYPoint aMin;
                    aMax.x = bMax.x - radius;
                    aMax.y = bMin.y - radius;
                    this->mapBound(&aMax);
                    aMin.x = bMin.x + radius;
                    aMin.y = bMax.y + radius;
                    this->mapBound(&aMin);
                    iMap->decrementValue(aMax.x, aMax.y,
                                          aMin.x, aMin.y, 10);
                } else if (mode == 5) {
                    int radius = (int)object->master_obj->los;
                    XYPoint minDC;
                    XYPoint maxDC;
                    minDC.x = bMin.x - radius * 2;
                    minDC.y = bMin.y - radius * 2;
                    this->mapBound(&minDC);
                    maxDC.x = bMax.x + radius * 2;
                    maxDC.y = bMax.y + radius * 2;
                    this->mapBound(&maxDC);
                    iMap->decrementValue(minDC.x, minDC.y,
                                          maxDC.x, maxDC.y, 20);
                } else if (mode == 8) {
                    int radius = (int)object->master_obj->los;
                    XYPoint minLOS;
                    XYPoint maxLOS;
                    minLOS.x = bMin.x - radius;
                    minLOS.y = bMin.y - radius;
                    this->mapBound(&minLOS);
                    maxLOS.x = bMax.x + radius;
                    maxLOS.y = bMax.y + radius;
                    this->mapBound(&maxLOS);
                    iMap->incrementValue(minLOS.x, minLOS.y,
                                          maxLOS.x, maxLOS.y, 20);

                    radius /= 2;
                    minLOS.x = bMin.x - radius;
                    minLOS.y = bMin.y - radius;
                    this->mapBound(&minLOS);
                    maxLOS.x = bMax.x + radius;
                    maxLOS.y = bMax.y + radius;
                    this->mapBound(&maxLOS);
                    iMap->incrementValue(minLOS.x, minLOS.y,
                                          maxLOS.x, maxLOS.y, 20);

                    radius /= 3;
                    minLOS.x = bMin.x - radius;
                    minLOS.y = bMin.y - radius;
                    this->mapBound(&minLOS);
                    maxLOS.x = bMax.x + radius;
                    maxLOS.y = bMax.y + radius;
                    this->mapBound(&maxLOS);
                    iMap->incrementValue(minLOS.x, minLOS.y,
                                          maxLOS.x, maxLOS.y, 20);
                }
            }
        }
    }

    if (mode == 3 || mode == 4 || mode == 0) {
        RGE_Map* map = this->md->player->world->map;
        for (int x = from->x; x <= to->x; x++) {
            for (int y = from->y; y <= to->y; y++) {
                unsigned char terrain = map->get_terrain((short)x, (short)y);
                if (terrain == 1) {
                    XYPoint minTerrain;
                    XYPoint maxTerrain;
                    minTerrain.x = x - 2;
                    minTerrain.y = y - 2;
                    maxTerrain.x = x - 2;
                    maxTerrain.y = y - 2;
                    this->mapBound(&minTerrain);
                    this->mapBound(&maxTerrain);
                    iMap->setValue(x, y, 0xff);
                    iMap->decrementValue(minTerrain.x, minTerrain.y,
                                          maxTerrain.x, maxTerrain.y, 10);
                }
                iMap->incrementValue(x, y, x, y,
                                      (map->map_row_offset[y][x].terrain >> 5) * 5);
            }
        }
    }

    if (mode == 3 || mode == 4 || mode == 0 || mode == 6 || mode == 5) {
        for (int i = 0, offset = 0; i < this->maxAttackMemories;
             i++, offset += 0x18) {
            AttackMemory* memory = (AttackMemory*)((char*)this->attackMemories + offset);
            if (memory->id != -1 &&
                (unsigned short)memory->targetOwner ==
                    (unsigned short)this->md->player->id) {
                XYPoint min;
                XYPoint max;
                min.x = (unsigned char)memory->minX - 4;
                min.y = (unsigned char)memory->minY - 4;
                this->mapBound(&min);
                max.x = (unsigned char)memory->maxX + 4;
                max.y = (unsigned char)memory->maxY + 4;
                this->mapBound(&max);
                iMap->incrementValue(min.x, min.y, max.x, max.y, 0x10);
            }
        }
    }

    if (mode == 0) {
        this->md->tacticalAI.setGroupInfluences(iMap);
    }

    int connectionFlag = 1;
    if (mode == 4) {
        connectionFlag = 0;
    }
    iMap->setConnectionCount(min, max, 0xff, 1, connectionFlag, 1);

    if (mode != 0 && this->maxBuildingLots > 0) {
        for (int i = 0; i < this->maxBuildingLots; i++) {
            BuildingLot* lot = &this->buildingLots[i];
            if (lot->typeID == objectType && lot->status == 2) {
                iMap->setValue(lot->x, lot->y, 0xff);
            }
        }
    }
}
