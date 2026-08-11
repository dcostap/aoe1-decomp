// VA: 004D8300 TribeInformationAIModule::update
// Source: taiinfmd.cpp lines 586-732
// FLAGS: /nologo /c /O2 /Oy
//
// Attempt log:
// 1: first pass - 432 bytes, uses sub 24h + early push edi instead of sub 28h
// 2: match stack layout (sub 28h, push saved regs at correct time)
// 3: modeled the binary-backed md->player->world/map ownership and moved the
//    visible-map/map loads after the two tile-list calls; the original reads
//    [md+0xF0], [player+0x38], [player+0x3C], and [world+0x28] in that order.
// 4: an initial quadrant-log hypothesis used map +0x408; stack tracking then
//    showed that [esp+14] is the saved information-AI this pointer, so this
//    diagnostic was replaced by the typed this->quadrantLog layout in probe 6.
// 5: restored the binary-backed x/y ownership: field +0 is x, field +4 is y;
//    visible/setValue receive (x,y), map rows use y and tile stride uses x,
//    and quadrant divisions are x/mapXSize then y/mapYSize.
// 6: restored the owning types from the exact map/information layouts: map
//    rows belong to RGE_Map, while mapX/mapY, pathMap, quadrantLog, and the
//    forest counter belong to this information-AI object.
// 7: restored visibleStatus to the binary-proven unsigned-byte local; the
//    original stores AL at a byte home and reloads that byte before the fog
//    predicate.
// 8: matched the binary quadrant index order: quadrantLog[xQuadrant][yQuadrant]
//    yields qy*12 + qx*48, the original LEA/SIB topology.
// 9: delayed the master-object alias until after the fog guard while keeping
//    the node object load before the guard; this mirrors the original visible
//    byte -> object -> fog-master -> post-guard master reload topology.
// 10: widened the sign-extended object-group temporary to int; the original
//     loads the short field directly into EBX before the important-object call.

#include <stdlib.h>

struct RGE_Tile_List_Node {
    int x;      // +0x00
    int y;      // +0x04
};

class RGE_Tile_List {
public:
    void get_list_info(RGE_Tile_List_Node** list, int* count);
    int get_new_count();
};

class RGE_Visible_Map {
public:
    unsigned char get_visible(int col, int row);
};

class InfluenceMap {
public:
    void* vtable;
    int xSizeValue;
    int ySizeValue;
    int xReferencePointValue;
    int yReferencePointValue;
    unsigned char* valueValue;
    unsigned char** rowValue;
    int coverageCountValue;
    int connectionCountValue;
    unsigned char unchangeableLimitValue;
    unsigned char gap_25[3];

    void setValue(int col, int row, int val);
};

struct TileObjNode {
    void* obj;          // +0x00
    TileObjNode* next;  // +0x04
};

struct RGE_Object_List {
    void* vtable;       // +0x00
    TileObjNode* list;  // +0x04
};

struct RGE_Tile {
    char gap_00[5];
    unsigned char terrainType; // +0x05
    char gap_06[0x0C - 0x06];
    RGE_Object_List objects;   // +0x0C, list at +0x10
    char gap_14[0x18 - 0x14];
};

struct RGE_Master_Static_Object {
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x10];
    short objectGroup;  // +0x14
    char gap_16[0x65 - 0x16];
    unsigned char fogFlag; // +0x65
};

struct RGE_Static_Object {
    virtual ~RGE_Static_Object();
    long id;            // +0x04
    void* master_obj;   // +0x08
};

class RGE_Map {
public:
    char gap_00[0x08];
    int mapWidth;       // +0x08
    int mapHeight;      // +0x0C
    char gap_10[0x8D8C - 0x10];
    RGE_Tile** mapRowOffset; // +0x8D8C
};

class RGE_World {
public:
    char gap_00[0x28];
    RGE_Map* map;       // +0x28
};

class RGE_Player {
public:
    char gap_00[0x38];
    RGE_Visible_Map* visMap; // +0x38
    RGE_World* world;        // +0x3C
    char gap_40[0x58 - 0x40];
    RGE_Tile_List tileList; // +0x58
};

class MainDecisionAIModule {
public:
    char gap_00[0xF0];
    RGE_Player* player; // +0xF0
};

class TribeInformationAIModule {
public:
    char gap_00[0x100];
    MainDecisionAIModule* md; // +0x100
    int mapXSize;       // +0x104
    int mapYSize;       // +0x108
    char gap_10C[0x158 - 0x10C];
    InfluenceMap pathMap; // +0x158
    char gap_180[0x408 - 0x180];
    struct QuadrantLog {
        int numberExploredTiles;
        int numberAttacksOnUs;
        int numberAttacksByUs;
    } quadrantLog[4][4]; // +0x408
    char gap_4C8[0x560 - 0x4C8];
    int numberFoundForestTilesValue; // +0x560

    int update(int param_1);
    int importantObject(int objGroup);
    int addImportantObject(void* obj, int param);
};

int TribeInformationAIModule::update(int param_1)
{
    RGE_Visible_Map* vismap;
    RGE_Map* map;
    int gMap_slot;
    int vMap_slot;
    int listSize;
    unsigned char visibleStatus;
    int terrainType;
    int forestTileCount;
    int col;
    int row;
    RGE_Tile_List_Node* gMap;
    int* vMap;
    int newCount;
    this->md->player->tileList.get_list_info(&gMap, (int*)&vMap);
    newCount = this->md->player->tileList.get_new_count();
    vismap = this->md->player->visMap;
    map = this->md->player->world->map;

    if (newCount > 0) {
        listSize = (int)vMap - newCount;
        if (listSize < (int)vMap) {
            do {
                row = gMap->y;
                col = gMap->x;
                
                visibleStatus = ((RGE_Visible_Map*)vismap)->get_visible(col, row);
                
                // Terrain type from tile bytes
                {
                    RGE_Tile* tile = map->mapRowOffset[row] + col;
                    terrainType = tile->terrainType & 0x1F;
                }
                
                // Quadrant update
                {
                    if (this->mapXSize != -1) {
                        int qx = (col * 4) / this->mapXSize;
                        int qy = (row * 4) / this->mapYSize;
                        this->quadrantLog[qx][qy].numberExploredTiles++;
                    }
                }
                
                // Set influence map
                this->pathMap.setValue(col, row, 0);
                
                // Iterate tile objects
                forestTileCount = 0;
                {
                    TileObjNode* node = map->mapRowOffset[row][col].objects.list;
                    
                    while (node != 0) {
                        RGE_Static_Object* obj = (RGE_Static_Object*)node->obj;
                        
                        if (visibleStatus == 0x80) {
                            if (((RGE_Master_Static_Object*)obj->master_obj)->fogFlag == 0) {
                                node = node->next;
                                continue;
                            }
                        }

                        RGE_Master_Static_Object* master =
                            (RGE_Master_Static_Object*)obj->master_obj;
                        
                        int objGroup = master->objectGroup;
                        
                        if (this->importantObject(objGroup) == 1) {
                            this->addImportantObject(obj, 0);
                        }
                        
                        if (objGroup == 0xF) {
                            forestTileCount++;
                        }
                        
                        node = node->next;
                    }
                }
                
                // Check forest count + terrain type
                if (forestTileCount > 0) {
                    if (terrainType == 0xA || terrainType == 0x13 || 
                        terrainType == 0xD || terrainType == 0x14) {
                        this->numberFoundForestTilesValue++;
                    }
                }
                
                listSize++;
                gMap = (RGE_Tile_List_Node*)((char*)gMap + 8);
            } while (listSize < (int)vMap);
        }
    }
    
    return 1;
}
