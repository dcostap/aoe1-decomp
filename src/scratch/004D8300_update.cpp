// VA: 004D8300 TribeInformationAIModule::update
// Source: taiinfmd.cpp lines 586-732
// FLAGS: /nologo /c /O2 /Oy
//
// Attempt log:
// 1: first pass - 432 bytes, uses sub 24h + early push edi instead of sub 28h
// 2: match stack layout (sub 28h, push saved regs at correct time)

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

class PathMap {
public:
    void setValue(int col, int row, int val);
};

struct TileObjNode {
    void* obj;          // +0x00
    TileObjNode* next;  // +0x04
};

struct StaticObject {
    char gap_00[8];
    void* master_obj;   // +0x08
};

struct MasterObject {
    char gap_00[0x14];
    short objectGroup;  // +0x14
    char gap_16[0x65 - 0x16];
    unsigned char fogFlag; // +0x65
};

class PlayerObj {
public:
    char gap_00[0x38];
    void* visMap;       // +0x38
    void* somePtr;      // +0x3C
    char gap_40[0x58 - 0x40];
    RGE_Tile_List tileList; // +0x58
};

class MapObj {
public:
    char gap_00[0x104];
    int mapXSize;       // +0x104
    int mapYSize;       // +0x108
    char gap_10C[0x8D8C - 0x10C];
    int* mapRowOffset;  // +0x8D8C
};

class TribeInformationAIModule {
public:
    char gap_00[0x100];
    PlayerObj* md;       // +0x100
    char gap_104[0x158 - 0x104];
    char pathMap[0x408]; // +0x158 (InfluenceMap)
    int numberFoundForestTilesValue; // +0x560

    int update(int param_1);
    int importantObject(int objGroup);
    int addImportantObject(void* obj, int param);
};

int TribeInformationAIModule::update(int param_1)
{
    void* vismap;
    int iVal;
    int gMap_slot;
    int vMap_slot;
    int listSize;
    int visibleStatus;  // used as byte
    int terrainType;
    int forestTileCount;
    int col;
    int row;
    RGE_Tile_List_Node* gMap;
    int* vMap;
    int newCount;
    PlayerObj* playerObj;

    playerObj = this->md;
    vismap = playerObj->visMap;
    iVal = *(int*)((char*)playerObj->somePtr + 0x28);

    playerObj->tileList.get_list_info(&gMap, (int*)&vMap);
    newCount = playerObj->tileList.get_new_count();

    if (newCount > 0) {
        listSize = (int)vMap - newCount;
        if (listSize < (int)vMap) {
            do {
                col = gMap->x;
                row = gMap->y;
                
                visibleStatus = ((RGE_Visible_Map*)vismap)->get_visible(row, col);
                
                // Terrain type from tile bytes
                {
                    int* rowOffsets = *(int**)((char*)iVal + 0x8D8C);
                    int* tilePtr = &rowOffsets[col];
                    unsigned char* tileBytes = (unsigned char*)((char*)*tilePtr + row * 24);
                    terrainType = tileBytes[5] & 0x1F;
                }
                
                // Quadrant update
                {
                    MapObj* mapObj = (MapObj*)iVal;
                    if (mapObj->mapXSize != -1) {
                        int qx = (row * 4) / mapObj->mapXSize;
                        int qy = (col * 4) / mapObj->mapYSize;
                        *(int*)((char*)mapObj + qy * 12 + qx * 48 + 0x158) += 1;
                    }
                }
                
                // Set influence map
                ((PathMap*)((char*)this + 0x158))->setValue(row, col, 0);
                
                // Iterate tile objects
                forestTileCount = 0;
                {
                    int* rowOffsets2 = *(int**)((char*)iVal + 0x8D8C);
                    int* tilePtr2 = &rowOffsets2[col];
                    TileObjNode** tileObjHead = (TileObjNode**)((char*)*tilePtr2 + row * 24 + 0x10);
                    TileObjNode* node = *tileObjHead;
                    
                    while (node != 0) {
                        StaticObject* obj = (StaticObject*)node->obj;
                        MasterObject* master = (MasterObject*)obj->master_obj;
                        
                        if (visibleStatus == 0x80) {
                            if (master->fogFlag == 0) {
                                node = node->next;
                                continue;
                            }
                        }
                        
                        short objGroup = master->objectGroup;
                        
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
