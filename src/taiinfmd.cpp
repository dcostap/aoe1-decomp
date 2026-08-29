
#include "../include/taiinfmd.h"
#include "../include/taimdmd.h"
#include "../include/game_globals.h"
#include "../include/aipbook.h"
#include "../include/ai_play_phase_command.h"
#include "../include/ai_play_phase.h"
#include "../include/action.h"
#include "../include/act_obj.h"
#include "../include/act_list.h"
#include "../include/basegame.h"
#include "../include/gameinfo.h"
#include "../include/map.h"
#include "../include/m_s_obj.h"
#include "../include/pathsys.h"
#include "../include/player.h"
#include "../include/stat_obj.h"
#include "../include/tplayer.h"
#include "../include/unit_ai_module.h"
#include "../include/xyz_point.h"
#include "../include/visible.h"
#include "../include/victory.h"
#include "../include/world.h"
#include "../include/zone_map.h"
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The compiler owns the startup wrappers and destructor registration for
InfluenceMap iMap(0xFE, 0xFE, 0);
InfluenceMap losMap(0x32, 0x32, 0);
InfluenceMap attackMap(0x32, 0x32, 0);

#include <string.h>

TribeInformationAIModule::TribeInformationAIModule(void* p, int v)
    : InformationAIModule(p, v),
      md(0),
      mapXSizeValue(-1),
      mapYSizeValue(-1),
      lastUpdateRowValue(0),
      maxImportantObjectMemory(500),
      pathMap(0xfe, 0xfe, 0xff),
      maxBuildingLots(200),
      maxAttackMemories(25),
      saveLearnInformationValue(0),
      numberFoundForestTilesValue(0)
{
    int z = 0;
    int one = 1;
    int i;
    strcpy(this->unitHistoryFilename, "learn\\Default.uh");

    this->resourceTypesValue = (int**)operator new(0x10);
    this->numberResourceTypesValue = (int*)operator new(0x10);
    for (i = 0; i < 4; i++) {
        this->numberResourceTypesValue[i] = 0;
        this->resourceTypesValue[i] = 0;
    }

    for (i = 0; i < 11; i++) {
        this->unitHistory[i] = 0;
    }
    int* playHistory = this->playHistory;
    for (int remaining = 16000; remaining != 0; --remaining) {
        *playHistory = 0;
        ++playHistory;
    }

    for (i = 0; i < 4; i++) {
        this->dropsitesByAge[0][i] = 0;
        this->dropsitesByAge[1][i] = one;
        this->dropsitesByAge[2][i] = one;
        this->dropsitesByAge[3][i] = one;
    }
    for (i = 0; i < 4; i++) {
        this->closestDropsiteValue[i] = -1;
        this->closestDropsiteResourceID[i] = -1;
    }

    this->importantObjectMemory = (ObjectMemory*)operator new(
        this->maxImportantObjectMemory * sizeof(ObjectMemory));
    if (this->importantObjectMemory != 0) {
        int k = 0;
        if (this->maxImportantObjectMemory > 0) {
            do {
                this->importantObjectMemory[k].id = -1;
                this->importantObjectMemory[k].type = -1;
                this->importantObjectMemory[k].group = -1;
                this->importantObjectMemory[k].x = 0;
                this->importantObjectMemory[k].y = 0;
                this->importantObjectMemory[k].z = 0;
                this->importantObjectMemory[k].owner = 0;
                this->importantObjectMemory[k].hitPoints = 0;
                this->importantObjectMemory[k].attackAttempts = 0;
                this->importantObjectMemory[k].kills = 0;
                this->importantObjectMemory[k].damageCapability = 0;
                this->importantObjectMemory[k].rateOfFire = 0;
                this->importantObjectMemory[k].range = 0;
                k++;
            } while (k < this->maxImportantObjectMemory);
        }
    }

    this->buildingLots = (BuildingLot*)operator new(
        this->maxBuildingLots * sizeof(BuildingLot));
    if (this->buildingLots != 0) {
        int k = 0;
        if (this->maxBuildingLots > 0) {
            do {
                this->buildingLots[k].typeID = -1;
                this->buildingLots[k].x = 0;
                this->buildingLots[k].y = 0;
                this->buildingLots[k].status = 0;
                k++;
            } while (k < this->maxBuildingLots);
        }
    }

    this->attackMemories = (AttackMemory*)operator new(
        this->maxAttackMemories * sizeof(AttackMemory));
    if (this->attackMemories != 0) {
        int off = 0;
        int k = 0;
        if (this->maxAttackMemories > 0) {
            do {
                this->attackMemories[k].id = -1;
                this->attackMemories[k].id = -1;
                this->attackMemories[k].minX = 0;
                this->attackMemories[k].minY = 0;
                this->attackMemories[k].maxX = 0;
                this->attackMemories[k].maxY = 0;
                this->attackMemories[k].attackingOwner = 0xff;
                this->attackMemories[k].targetOwner = 0xff;
                this->attackMemories[k].kills = 0;
                this->attackMemories[k].success = 0;
                this->attackMemories[k].play = -1;
                k++;
            } while (k < this->maxAttackMemories);
        }
    }

    this->lastWallPosition.x = -1;
    this->lastWallPosition.y = -1;
    this->lastWallPosition2.x = -1;
    this->lastWallPosition2.y = -1;
    this->numberGatesValue = -1;
    for (int k = 0; k < 4; k++) {
        this->minGatePosition[k].x = -1;
        this->minGatePosition[k].y = -1;
        this->maxGatePosition[k].x = -1;
        this->maxGatePosition[k].y = -1;
    }

    memset(this->fullyExploredZoneValue, 0, sizeof(this->fullyExploredZoneValue));

    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            this->quadrantLog[x][y].numberExploredTiles = 0;
            this->quadrantLog[x][y].numberAttacksOnUs = 0;
            this->quadrantLog[x][y].numberAttacksByUs = 0;
        }
    }

    for (k = 0; k < 4; k++) {
        this->resources[k] = 0;
        this->maxResources[k] = 0;
        this->numResources[k] = 0;
    }
}

#include <string.h>

TribeInformationAIModule::TribeInformationAIModule(int param1, int param2)
    : InformationAIModule(0, param1),
      md(0),
      pathMap(0xfe, 0xfe, 0xff),
      saveLearnInformationValue(0),
      numberFoundForestTilesValue(0)
{
    int tempInt;
    int tempInt_ffffffe8;
    int local_14;
    int resourceIndex;
    int i3;

    strcpy(this->unitHistoryFilename, "learn\\Default.uh");

    this->resourceTypesValue = (int**)operator new(0x10);
    this->numberResourceTypesValue = (int*)operator new(0x10);
    for (int i0 = 0; i0 < 4; i0++) {
        this->numberResourceTypesValue[i0] = 0;
        this->resourceTypesValue[i0] = 0;
    }

    for (int i10 = 0; i10 < 11; i10++) {
        this->unitHistory[i10] = 0;
    }
    memset(this->playHistory, 0, sizeof(this->playHistory));

    for (int i1 = 0; i1 < 4; i1++) {
        this->dropsitesByAge[0][i1] = 0;
        this->dropsitesByAge[1][i1] = 1;
        this->dropsitesByAge[2][i1] = 1;
        this->dropsitesByAge[3][i1] = 1;
    }

    for (int i2 = 0; i2 < 4; i2++) {
        this->closestDropsiteValue[i2] = -1;
        this->closestDropsiteResourceID[i2] = -1;
    }

    resourceIndex = 0;
    do {
        rge_read(param2, &param1, 4);
        i3 = 0;
        if (param1 > 0) {
            do {
                rge_read(param2, &local_14, 4);
                this->addResourceType(resourceIndex, local_14);
                i3++;
            } while (i3 < param1);
        }
        resourceIndex++;
    } while (resourceIndex < 4);

    rge_read(param2, &this->mapXSizeValue, 4);
    rge_read(param2, &this->mapYSizeValue, 4);
    rge_read(param2, &this->lastUpdateRowValue, 4);
    rge_read(param2, &this->maxImportantObjectMemory, 4);
    this->importantObjectMemory = (ObjectMemory*)operator new(
        this->maxImportantObjectMemory * sizeof(ObjectMemory));
    if (this->importantObjectMemory != 0) {
        for (int i4 = 0; i4 < this->maxImportantObjectMemory; i4++) {
            rge_read(param2, this->importantObjectMemory + i4, sizeof(ObjectMemory));
        }

        rge_read(param2, &this->maxBuildingLots, 4);
        this->buildingLots = (BuildingLot*)operator new(
            this->maxBuildingLots * sizeof(BuildingLot));
        if (this->buildingLots != 0) {
            for (int i5 = 0; i5 < this->maxBuildingLots; i5++) {
                rge_read(param2, this->buildingLots + i5, sizeof(BuildingLot));
            }

            rge_read(param2, &this->maxAttackMemories, 4);
            this->attackMemories = (AttackMemory*)operator new(
                this->maxAttackMemories * sizeof(AttackMemory));
            if (this->attackMemories != 0) {
                for (int i6 = 0; i6 < this->maxAttackMemories; i6++) {
                    rge_read(param2, this->attackMemories + i6, sizeof(AttackMemory));
                }

                rge_read(param2, &tempInt, 4);
                param1 = 0;
                if (tempInt > 0) {
                    do {
                        rge_read(param2, &tempInt_ffffffe8, 4);
                        this->importantObjects.add(tempInt_ffffffe8);
                        param1++;
                    } while (param1 < tempInt);
                }

                rge_read(param2, &tempInt, 4);
                param1 = 0;
                if (tempInt > 0) {
                    do {
                        rge_read(param2, &tempInt_ffffffe8, 4);
                        this->importantUnits.add(tempInt_ffffffe8);
                        param1++;
                    } while (param1 < tempInt);
                }

                rge_read(param2, &tempInt, 4);
                param1 = 0;
                if (tempInt > 0) {
                    do {
                        rge_read(param2, &tempInt_ffffffe8, 4);
                        this->importantMiscs.add(tempInt_ffffffe8);
                        param1++;
                    } while (param1 < tempInt);
                }

                rge_read(param2, &tempInt, 4);
                param1 = 0;
                if (tempInt > 0) {
                    do {
                        rge_read(param2, &tempInt_ffffffe8, 4);
                        this->itemsToDefend.add(tempInt_ffffffe8);
                        param1++;
                    } while (param1 < tempInt);
                }

                rge_read(param2, &tempInt, 4);
                param1 = 0;
                if (tempInt > 0) {
                    do {
                        rge_read(param2, &tempInt_ffffffe8, 4);
                        this->playerBuildings.add(tempInt_ffffffe8);
                        param1++;
                    } while (param1 < tempInt);
                }

                rge_read(param2, &tempInt, 4);
                param1 = 0;
                if (tempInt > 0) {
                    do {
                        rge_read(param2, &tempInt_ffffffe8, 4);
                        this->playerObjects.add(tempInt_ffffffe8);
                        param1++;
                    } while (param1 < tempInt);
                }

                this->pathMap.load(param2);
                rge_read(param2, &this->lastWallPosition, 8);
                rge_read(param2, &this->lastWallPosition2, 8);

                if (!(save_game_version < DAT_00575550)) {
                    rge_read(param2, &this->numberGatesValue, 4);
                } else {
                    rge_read(param2, &this->numberGatesValue, 8);
                }

                for (int i7 = 0; i7 < 4; i7++) {
                    rge_read(param2, &this->minGatePosition[i7], 8);
                    rge_read(param2, &this->maxGatePosition[i7], 8);
                }

                rge_read(param2, &this->saveLearnInformationValue, 4);
                if (!(save_game_version < DAT_00575550)) {
                    rge_read(param2, &tempInt_ffffffe8, 4);
                    rge_read(param2, this->learnFileName, tempInt_ffffffe8);
                    this->learnFileName[tempInt_ffffffe8] = '\0';
                } else {
                    strcpy(this->learnFileName, "");
                }

                rge_read(param2, this->fullyExploredZoneValue, 0xff);
                if (!(save_game_version < DAT_00575554)) {
                    rge_read(param2, this->quadrantLog, 0xc0);
                } else {
                    for (int i8 = 0; i8 < 4; i8++) {
                        for (int j8 = 0; j8 < 4; j8++) {
                            this->quadrantLog[i8][j8].numberExploredTiles = 0;
                            this->quadrantLog[i8][j8].numberAttacksOnUs = 0;
                            this->quadrantLog[i8][j8].numberAttacksByUs = 0;
                        }
                    }
                }

                rge_read(param2, this->maxResources, 0x10);
                rge_read(param2, this->numResources, 0x10);
                for (int i9 = 0; i9 < 4; i9++) {
                    if (this->maxResources[i9] != 0) {
                        this->resources[i9] = (ResourceMemory*)operator new(
                            this->maxResources[i9] * sizeof(ResourceMemory));
                        rge_read(param2, this->resources[i9],
                                 this->maxResources[i9] * sizeof(ResourceMemory));
                    } else {
                        this->resources[i9] = 0;
                    }
                }

                if (!(save_game_version < DAT_00575558)) {
                    rge_read(param2, this->dropsitesByAge, 0x40);
                }
                if (!(save_game_version < DAT_00575558)) {
                    rge_read(param2, this->closestDropsiteValue, 0x10);
                    rge_read(param2, this->closestDropsiteResourceID, 0x10);
                }
                if (!(save_game_version < DAT_0057555c)) {
                    rge_read(param2, &this->numberFoundForestTilesValue, 4);
                }
                if (!(save_game_version < DAT_00575560)) {
                    rge_read(param2, this->playHistory, 64000);
                }
            }
        }
    }
}

TribeInformationAIModule::~TribeInformationAIModule()
{
    int count;
    int tempInt;
    int outFile;
    int local_14;
    int i;
    int index;
    int offset;

    for (i = 0; i < 4; i++) {
        operator delete(this->resourceTypesValue[i]);
    }
    operator delete(this->resourceTypesValue);
    operator delete(this->numberResourceTypesValue);

    if (this->saveLearnInformationValue == 1) {
        int file = rge_open(this->learnFileName, 0x8301, 0x180);
        local_14 = file;
        if (file != -1) {
            rge_write(file, &this->mapXSizeValue, 4);
            rge_write(file, &this->mapYSizeValue, 4);

            count = 0;
            if (this->maxAttackMemories > 0) {
                AttackMemory* memory = this->attackMemories;
                int remaining = this->maxAttackMemories;
                do {
                    if (memory->id != -1)
                        count++;
                    memory++;
                    remaining--;
                } while (remaining != 0);
            }
            rge_write(file, &count, 4);

            index = 0;
            if (this->maxAttackMemories > 0) {
                offset = 0;
                do {
                    if (((AttackMemory*)((char*)this->attackMemories + offset))->id != -1)
                        rge_write(file,
                                  (AttackMemory*)((char*)this->attackMemories + offset),
                                  0x18);
                    index++;
                    offset += sizeof(AttackMemory);
                } while (index < this->maxAttackMemories);
            }

            count = 0;
            if (this->maxImportantObjectMemory > 0) {
                ObjectMemory* memory = this->importantObjectMemory;
                int remaining = this->maxImportantObjectMemory;
                do {
                    if (memory->id != -1 && memory->type == 0x6d)
                        count++;
                    memory++;
                    remaining--;
                } while (remaining != 0);
            }
            rge_write(file, &count, 4);

            index = 0;
            if (this->maxImportantObjectMemory > 0) {
                offset = 0;
                do {
                    if (((ObjectMemory*)(offset + (char*)this->importantObjectMemory))->id != -1 &&
                        ((ObjectMemory*)(offset + (char*)this->importantObjectMemory))->type == 0x6d)
                        rge_write(file,
                                  (ObjectMemory*)(offset + (char*)this->importantObjectMemory),
                                  0x24);
                    index++;
                    offset += sizeof(ObjectMemory);
                } while (index < this->maxImportantObjectMemory);
            }

            for (i = 0; i < 4; i++) {
                rge_write(file, &this->maxResources[i], 4);
                rge_write(file, &this->numResources[i], 4);
                if (this->maxResources[i] != 0)
                    rge_write(file, this->resources[i],
                              this->maxResources[i] * sizeof(ResourceMemory));
            }

            outFile = this->importantMiscs.numberValue;
            rge_write(file, &outFile, 4);
            for (i = 0; i < this->importantMiscs.numberValue; i++) {
                outFile = this->importantMiscs[i];
                rge_write(file, &outFile, 4);
            }

            outFile = this->itemsToDefend.numberValue;
            rge_write(file, &outFile, 4);
            for (i = 0; i < this->itemsToDefend.numberValue; i++) {
                outFile = this->itemsToDefend[i];
                rge_write(file, &outFile, 4);
            }
            rge_close(file);
        }
    }

    unsigned char currentPlayer = this->md->player->world->player_turn;
    if ((currentPlayer == this->md->player->id || currentPlayer == 0xff) &&
        (local_14 = rge_open(this->unitHistoryFilename, 0x8301, 0x180),
         local_14 != -1)) {
        rge_write(local_14, this->unitHistory, 0x2c);
        rge_close(local_14);
    }

    if (this->importantObjectMemory != 0)
        operator delete(this->importantObjectMemory);
    if (this->buildingLots != 0)
        operator delete(this->buildingLots);
    if (this->attackMemories != 0)
        operator delete(this->attackMemories);

    for (i = 0; i < 4; i++) {
        if (this->resources[i] != 0) {
            operator delete(this->resources[i]);
            this->resources[i] = 0;
        }
    }
}

#include <stdio.h>
#include <string.h>

int TribeInformationAIModule::initialize() {
    // Pointer chain: md->field_F0->field_3C->field_28 = terrain
    void* terrain = *(void**)(*(char**)(*(char**)((char*)this->md + 0xF0) + 0x3C) + 0x28);
    this->mapXSizeValue = *(int*)((char*)terrain + 8);
    this->mapYSizeValue = *(int*)((char*)terrain + 0x0C);

    // Get player game info from global
    RGE_Game_Info* game_info = rge_base_game->player_game_info;

    // Check if player name exists
    if (game_info->get_current_player_name()) {
        sprintf((char*)this + 0xFF90, "learn\\%s.uh", game_info->get_current_player_name());
    } else {
        strcpy((char*)this + 0xFF90, "learn\\Default.uh");
    }

    return 1;
}

#include <stdlib.h>

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
    int vMap;
    int newCount;
    this->md->player->tile_list.get_list_info(gMap, vMap);
    newCount = this->md->player->tile_list.get_new_count();
    vismap = this->md->player->visible;
    map = this->md->player->world->map;

    if (newCount > 0) {
        listSize = vMap - newCount;
        if (listSize < vMap) {
            do {
                row = gMap->row;
                col = gMap->col;

                visibleStatus = ((RGE_Visible_Map*)vismap)->get_visible(col, row);

                // Terrain type from tile bytes
                {
                    RGE_Tile* tile = map->map_row_offset[row] + col;
                    terrainType = tile->terrain_type & 0x1F;
                }

                // Quadrant update
                {
                    if (this->mapXSizeValue != -1) {
                        int qx = (col * 4) / this->mapXSizeValue;
                        int qy = (row * 4) / this->mapYSizeValue;
                        this->quadrantLog[qx][qy].numberExploredTiles++;
                    }
                }

                // Set influence map
                this->pathMap.setValue(col, row, 0);

                // Iterate tile objects
                forestTileCount = 0;
                {
                    RGE_Object_Node* node = map->map_row_offset[row][col].objects.list;

                    while (node != 0) {
                        RGE_Static_Object* obj = (RGE_Static_Object*)node->node;

                        if (visibleStatus == 0x80) {
                            if (((RGE_Master_Static_Object*)obj->master_obj)->fog_flag == 0) {
                                node = node->next;
                                continue;
                            }
                        }

                        RGE_Master_Static_Object* master =
                            (RGE_Master_Static_Object*)obj->master_obj;

                        int objGroup = master->object_group;

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
            } while (listSize < vMap);
        }
    }

    return 1;
}

void TribeInformationAIModule::setMainDecisionAI(TribeMainDecisionAIModule* v) {
    this->md = v;
}

#include <string.h>
#include <stdlib.h>

void rge_write(int file, void* data, int size);

int TribeInformationAIModule::save(int handle)
{
    int tmp;
    int saved_handle = handle;
    for (int k = 0; k < 4; k++) {
        tmp = this->numberResourceTypesValue[k];
        rge_write(saved_handle, &tmp, 4);
        for (int m = 0; m < this->numberResourceTypesValue[k]; m++) {
            tmp = this->resourceTypesValue[k][m];
            rge_write(saved_handle, &tmp, 4);
        }
    }

    rge_write(saved_handle, &this->mapXSizeValue, 4);
    rge_write(saved_handle, &this->mapYSizeValue, 4);
    rge_write(saved_handle, &this->lastUpdateRowValue, 4);
    rge_write(saved_handle, &this->maxImportantObjectMemory, 4);
    for (int a = 0; a < this->maxImportantObjectMemory; a++)
        rge_write(saved_handle, (char*)this->importantObjectMemory + a * 0x24, 0x24);

    rge_write(saved_handle, &this->maxBuildingLots, 4);
    for (int b = 0; b < this->maxBuildingLots; b++)
        rge_write(saved_handle, (char*)this->buildingLots + b * 8, 8);

    rge_write(saved_handle, &this->maxAttackMemories, 4);
    for (int c = 0; c < this->maxAttackMemories; c++)
        rge_write(saved_handle, (char*)this->attackMemories + c * 0x18, 0x18);

    handle = this->importantObjects.numberValue;
    rge_write(saved_handle, &handle, 4);
    for (int d = 0; d < this->importantObjects.numberValue; d++) {
        handle = this->importantObjects[d];
        rge_write(saved_handle, &handle, 4);
    }
    handle = this->importantUnits.numberValue;
    rge_write(saved_handle, &handle, 4);
    for (int e = 0; e < this->importantUnits.numberValue; e++) {
        handle = this->importantUnits[e];
        rge_write(saved_handle, &handle, 4);
    }
    handle = this->importantMiscs.numberValue;
    rge_write(saved_handle, &handle, 4);
    for (int f = 0; f < this->importantMiscs.numberValue; f++) {
        handle = this->importantMiscs[f];
        rge_write(saved_handle, &handle, 4);
    }
    handle = this->itemsToDefend.numberValue;
    rge_write(saved_handle, &handle, 4);
    for (int g = 0; g < this->itemsToDefend.numberValue; g++) {
        handle = this->itemsToDefend[g];
        rge_write(saved_handle, &handle, 4);
    }
    handle = this->playerBuildings.numberValue;
    rge_write(saved_handle, &handle, 4);
    for (int h = 0; h < this->playerBuildings.numberValue; h++) {
        handle = this->playerBuildings[h];
        rge_write(saved_handle, &handle, 4);
    }
    handle = this->playerObjects.numberValue;
    rge_write(saved_handle, &handle, 4);
    for (int w = 0; w < this->playerObjects.numberValue; w++) {
        handle = this->playerObjects[w];
        rge_write(saved_handle, &handle, 4);
    }

    this->pathMap.save(saved_handle);

    rge_write(saved_handle, &this->lastWallPosition, 8);
    rge_write(saved_handle, &this->lastWallPosition2, 8);
    rge_write(saved_handle, &this->numberGatesValue, 4);
    for (int x = 0; x < 4; x++) {
        rge_write(saved_handle, &this->minGatePosition[x], 8);
        rge_write(saved_handle, &this->maxGatePosition[x], 8);
    }
    rge_write(saved_handle, &this->saveLearnInformationValue, 4);

    handle = strlen(this->learnFileName);
    rge_write(saved_handle, &handle, 4);
    rge_write(saved_handle, this->learnFileName, strlen(this->learnFileName));

    rge_write(saved_handle, this->fullyExploredZoneValue, 0xFF);
    rge_write(saved_handle, this->quadrantLog, 0xC0);

    for (int y = 0; y < 4; y++) {
        if (this->maxResources[y] != 0 && this->resources[y] == 0)
            this->maxResources[y] = 0;
    }
    rge_write(saved_handle, &this->maxResources, 0x10);
    rge_write(saved_handle, &this->numResources, 0x10);
    for (int z = 0; z < 4; z++) {
        if (this->maxResources[z] != 0)
            rge_write(saved_handle, this->resources[z], this->maxResources[z] * 20);
    }

    rge_write(saved_handle, this->dropsitesByAge, 0x40);
    rge_write(saved_handle, this->closestDropsiteValue, 0x10);
    rge_write(saved_handle, this->closestDropsiteResourceID, 0x10);
    rge_write(saved_handle, &this->numberFoundForestTilesValue, 4);
    rge_write(saved_handle, this->playHistory, 0xFA00);

    return 1;
}

void TribeInformationAIModule::blotExploredMap(int p1, int p2, int p3, int p4)
{
    XYPoint min;
    XYPoint max;

    max.y = p1;
    max.x = p2;
    this->mapBound((XYPoint*)&max);

    min.y = p3;
    min.x = p4;
    this->mapBound((XYPoint*)&min);

    for (int y = max.y; y <= min.y; y++) {
        for (int x = max.x; x <= min.x; x++) {
            if (this->pathMap.lookupValue(y, x) != 1)
                this->pathMap.setValue(y, x, 2);
        }
    }
}

int TribeInformationAIModule::closestUnexploredTile(
    int objectId, float x, float y, float* outX, float* outY)
{
    XYPoint cPoint;
    RGE_Static_Object* obj;
    RGE_Visible_Map* visible;

    visible = this->md->player->visible;
    obj = this->md->player->world->object(objectId);

    if (obj == 0)
        return 0;

    int isBuilding = (obj->master_obj->object_group == 4);
    uchar initialZone = obj->currentZone();
    int direction = debug_rand(
        (char*)"C:\\msdev\\work\\age1_x1\\taiinfmd.cpp", 0x397) % 4;

    cPoint.x = (int)x;
    cPoint.y = (int)y;
    int offLeft = 0;
    int offRight = 0;
    int offTop = 0;
    int offBottom = 0;
    int pathDistance = 0;
    float pathResult;
    int pass;
    int i;

    for (;;) {
        if (offLeft != 0 && offRight != 0 && offTop != 0 && offBottom != 0) {
            this->setFullyExploredZone(objectId, 1);
            return 0;
        }

        ++pathDistance;
        pass = 0;
        do {
            i = 0;
            direction = (direction + 1) & 3;
            if (pathDistance > 0) {
                do {
                switch (direction) {
                case 0:
                    ++cPoint.y;
                    break;
                case 1:
                    ++cPoint.x;
                    break;
                case 2:
                    --cPoint.y;
                    break;
                case 3:
                    --cPoint.x;
                    break;
                }

                if (cPoint.x < 0) {
                    offLeft = 1;
                } else if (cPoint.x >= this->mapXSizeValue) {
                    offRight = 1;
                } else if (cPoint.y < 0) {
                    offTop = 1;
                } else if (cPoint.y >= this->mapYSizeValue) {
                    offBottom = 1;
                } else {
                    uchar explored = (uchar)this->pathMap.lookupValue(
                        cPoint.x, cPoint.y);
                    uchar visibleValue = visible->get_visible(cPoint.x, cPoint.y);
                    if (visibleValue == 0x0f)
                        goto skipTile;
                    if (isBuilding == 1) {
                        if (explored != 0xff)
                            goto skipTile;
                    } else if (isBuilding == 0) {
                        if (explored != 0xff && explored != 2)
                            goto skipTile;
                    } else {
                        goto skipTile;
                    }
                    {
                        if (obj->passableTile((float)cPoint.x,
                                              (float)cPoint.y, 1) != 0 &&
                            obj->lookupZone(cPoint.x, cPoint.y) == initialZone) {
                            XYZPoint point;
                            point.x = cPoint.x;
                            point.y = cPoint.y;
                            point.z = (int)obj->world_z;
                            if (obj->canPath(
                                    point, obj->master_obj->los - DAT_00575564,
                                    -1, &pathResult, 1, -1, -1) == 0) {
                                this->pathMap.setValue(cPoint.x, cPoint.y, 1);

                                int bestScore = -1;
                                int bestX = 0;
                                int bestY = 0;
                                int quadrantX;
                                int quadrantY;
                                QuadrantLog* quadrant = &this->quadrantLog[0][0];
                                for (quadrantX = 0; quadrantX < 4; ++quadrantX) {
                                    for (quadrantY = 0; quadrantY < 4; ++quadrantY) {
                                        int score = quadrant->numberExploredTiles +
                                            debug_rand(
                                                (char*)"C:\\msdev\\work\\age1_x1\\taiinfmd.cpp",
                                                0x420) % 100 +
                                            quadrant->numberAttacksOnUs * 25;
                                        if (bestScore == -1 || score < bestScore) {
                                            bestScore = score;
                                    bestX = this->mapXSizeValue * quadrantX / 4;
                                    bestY = this->mapYSizeValue * quadrantY / 4;
                                        }
                                        ++quadrant;
                                    }
                                }

                                int maxX = this->mapXSizeValue / 4 - 1 + bestX;
                                int maxY = this->mapYSizeValue / 4 - 1 + bestY;
                                int choice = debug_rand(
                                    (char*)"C:\\msdev\\work\\age1_x1\\taiinfmd.cpp",
                                    0x430) % 4;
                                if (choice == 0) {
                                    cPoint.x = bestX;
                                    cPoint.y = bestY;
                                } else if (choice == 1) {
                                    cPoint.x = bestX;
                                    cPoint.y = maxY;
                                } else if (choice == 2) {
                                    cPoint.x = maxX;
                                    cPoint.y = maxY;
                                } else {
                                    cPoint.x = maxX;
                                    cPoint.y = bestY;
                                }
                            } else {
                                this->pathMap.setValue(cPoint.x, cPoint.y, 0);
                            }
                            *outX = (float)cPoint.x;
                            *outY = (float)cPoint.y;
                            return 1;
                        }
                    }
skipTile:
                    ;
                }
                    ++i;
                } while (i < pathDistance);
            }
            ++pass;
        } while (pass < 2);
    }
}

int TribeInformationAIModule::fullyExploredZone(int param_1) {
    RGE_Static_Object* object = md->object(param_1);
    if (object != 0) {
        unsigned char zone = object->currentZone();
        if (fullyExploredZoneValue[zone] == 0) {
            return 1;
        }
    }
    return 0;
}

void TribeInformationAIModule::setFullyExploredZone(int param_1, int param_2) {
    RGE_Static_Object* object = md->object(param_1);
    if (object != 0) {
        unsigned char zone = object->currentZone();
        fullyExploredZoneValue[zone] = (unsigned char)param_2;
    }
}

int TribeInformationAIModule::tileUncovered(int x, int y) {
    int rv;

    if (x < 0 || y < 0 || x >= this->mapXSizeValue || y >= this->mapYSizeValue) {
        goto not_found;
    }
    if (this->pathMap.lookupValue(x, y) != 0xFF) {
        rv = 1;
        return rv;
    }
not_found:
    return 0;
}

void TribeInformationAIModule::setTileExplored(int x, int y) {
    if (x >= 0 && y >= 0 && x < this->mapXSizeValue && y < this->mapYSizeValue)
        this->pathMap.setValue(x, y, 0);
}

int TribeInformationAIModule::ownerOfGameID(int p0) { return -1; }

#include <math.h>
#include <stdlib.h>
#include <string.h>

int TribeInformationAIModule::gameIDOfResourceObject(int resType, int gathererId, float& outX, float& outY, int& outResourceId, int* exclude, int excludeCount)
{
    unsigned char zone;
    int gx;
    int gy;
    int boat;
    int score;
    int bestObject;
    ResourceMemory* bestValue;
    int fishingBoat;
    int needUpdateDropsite;
    int i;
    bool excluded;
    int j;
    int* excludePtr;
    int objectId;
    RGE_Static_Object* obj;
    int dx;
    int dy;
    short cls3;
    short cls;
    short cls2;
    int k;
    RGE_Static_Object* gatherer;

    outResourceId = -1;
    gatherer = this->md->object(gathererId);
    if (gatherer) {

    zone = gatherer->currentZone();
    gx = (int)gatherer->world_x;
    gy = (int)gatherer->world_y;
    boat = this->isBoat(gatherer);

    fishingBoat = -1;
    bestValue = 0;
    needUpdateDropsite = 0;

    i = 0;
    if (this->numResources[resType] > 0) {
        bestObject = 0;
        do {
            if (((ResourceMemory*)((char*)this->resources[resType] + bestObject))->gone == 1) goto next;
            if (((ResourceMemory*)((char*)this->resources[resType] + bestObject))->valid != 0) {
                if (((ResourceMemory*)((char*)this->resources[resType] + bestObject))->gone != 0) goto next;
                --((ResourceMemory*)((char*)this->resources[resType] + bestObject))->valid;
                goto next;
            }
            excluded = 0;
            excludePtr = exclude;
            for (j = 0; j < excludeCount; ++j, ++excludePtr) {
                if (*excludePtr == ((ResourceMemory*)((char*)this->resources[resType] + bestObject))->id) { excluded = 1; break; }
            }
            if (excluded == 1) goto next;
            obj = this->md->object(((ResourceMemory*)((char*)this->resources[resType] + bestObject))->id);
            if (!obj) {
                ((ResourceMemory*)((char*)this->resources[resType] + bestObject))->gone = 1;
                if (this->closestDropsiteResourceID[resType] ==
                    ((ResourceMemory*)((char*)this->resources[resType] + bestObject))->id)
                    needUpdateDropsite = 1;
                goto next;
            }
            if (boat == 1) {
                cls = obj->master_obj->object_group;
                if (cls != 5 && cls != 0x1f && cls != 0x21) goto next;
            }
            if (boat == 0) {
                cls2 = obj->master_obj->object_group;
                if (cls2 == 5 || cls2 == 0x1f || cls2 == 0x21) goto next;
            }
            dx = gx - ((ResourceMemory*)((char*)this->resources[resType] + bestObject))->x;
            dy = gy - ((ResourceMemory*)((char*)this->resources[resType] + bestObject))->y;
            score = dx * dx + dy * dy + ((ResourceMemory*)((char*)this->resources[resType] + bestObject))->gatherValue * 10;
            if (obj->master_obj->id == 0x3b) {
                if (((ResourceMemory*)((char*)this->resources[resType] + bestObject))->dropDistance > 0x14) goto next;
                score += ((int)((ResourceMemory*)((char*)this->resources[resType] + bestObject))->gatherAttempts) / 150;
                if (this->md->tacticalAI.numberGatherersWithTarget(obj->id) > 2) score += 200;
            } else {
                score += ((int)((ResourceMemory*)((char*)this->resources[resType] + bestObject))->gatherAttempts) / 50;
            }
            if (bestValue && score >= fishingBoat) goto next;
            cls3 = obj->master_obj->object_group;
            if ((cls3 == 9 || cls3 == 10) && obj->object_state > 2 && obj->attribute_amount_held > DAT_00575568) score += 25;
            if (this->withinXTilesOfEnemyTowncenter(obj, 25) == 1) goto next;
            if (this->withinXTilesOfAttackOnPlayer(obj, 15, this->md->player->culture) == 1) score += 500;
            if (obj->master_obj->id == 0x32) {
                if (obj->owner->culture != this->md->player->culture) goto next;
                if (obj->object_state != 2) goto next;
                if (this->md->tacticalAI.numberGatherersWithTarget(obj->id) > 0) goto next;
                objectId = obj->id;
                k = 0;
                while (k < this->farmsTaskedThisUpdate.numberValue) {
                    if (k >= this->farmsTaskedThisUpdate.maximumSizeValue) break;
                    if (this->farmsTaskedThisUpdate[k] == objectId) goto next;
                    ++k;
                }
            }
            if (resType == 1 && this->md->tacticalAI.numberGatherersWithTarget(obj->id) > 0) goto next;
            if ((resType == 3 || resType == 2) && this->md->tacticalAI.numberGatherersWithTarget(obj->id) > 3) goto next;
            if (obj->master_obj->id == 0x30 && obj->object_state == 2) {
                int want = this->md->tacticalAI.strategicNumber(0xcc);
                if (this->md->tacticalAI.actualGathererCountByRealResourceID(0) < want) goto next;
            }
            if (gatherer->lookupZone(((ResourceMemory*)((char*)this->resources[resType] + bestObject))->x,
                                     ((ResourceMemory*)((char*)this->resources[resType] + bestObject))->y) != zone) goto next;
            if (bestValue && score >= fishingBoat) goto next;
            bestValue = (ResourceMemory*)((char*)this->resources[resType] + bestObject);
            fishingBoat = score;
            outX = obj->world_x;
            outY = obj->world_y;
next:
            ++i;
            bestObject += 20;
        } while (i < this->numResources[resType]);
    }

        if (needUpdateDropsite == 1) this->updateResourceDropsites(resType);
        if (bestValue) {
            bestValue->gatherAttempts++;
            outResourceId = bestValue->dropsiteID;
            return bestValue->id;
        }
    }
    return -1;
}

#include <stddef.h>

int TribeInformationAIModule::gameIDsOfObjectType(int objectType, int** ids, int** owners, int playerFilter)
{
    *ids = 0;
    int count = 0;
    *owners = 0;
    int maxCount = 10;
    int i = 0;
    if (this->importantObjects.numberValue > 0) {
        do {
            RGE_Static_Object* obj = this->md->aiPlayer->world->object(
                this->importantObjects[i]);
            if (obj != 0) {
                if (playerFilter == -5) {
                    if (this->md->aiPlayer->id == obj->owner->id) goto next;
                }
                if (playerFilter == -6) {
                    if (this->md->aiPlayer->relation(obj->owner->id) != 0) goto next;
                }
                if (playerFilter != -1 && obj->owner->id != playerFilter) goto next;
                if (objectType != -1 && objectType !=
                    ((RGE_Master_Static_Object*)obj->master_obj)->id) goto next;
                if (count == maxCount || *ids == 0) {
                    int* newIds = (int*)operator new(maxCount * 8);
                    int* newOwners = (int*)operator new(maxCount * 8);
                    if (*ids != 0) {
                        for (int j = 0; j < maxCount; j++) {
                            newIds[j] = (*ids)[j];
                            newOwners[j] = (*owners)[j];
                        }
                    }
                    maxCount *= 2;
                    if (*ids != 0) operator delete(*ids);
                    if (*owners != 0) operator delete(*owners);
                    *ids = newIds;
                    *owners = newOwners;
                }
                (*ids)[count] = this->importantObjects[i];
                (*owners)[count++] = obj->owner->id;
            }
next:
            i++;
        } while (i < this->importantObjects.numberValue);
    }
    return count;
}

int TribeInformationAIModule::gameIDsOwnedBy(int owner_filter, int** out, int owner_id)
{
    int count = 0;
    int capacity = 10;
    int i;
    *out = 0;
    i = 0;

    if (this->maxImportantObjectMemory > 0) {
        do {
            if (this->importantObjectMemory[i].id != -1) {
                RGE_Game_World* world = this->md->aiPlayer->world;
                RGE_Static_Object* obj = world->object(
                    this->importantObjectMemory[i].id
                );
                if (obj != 0) {
                    int ownerId = obj->owner->id;
                    if (ownerId == owner_id) {
                        if (owner_filter == -1 || owner_filter == this->importantObjectMemory[i].owner) {
                            if (count == capacity || *out == 0) {
                                int* new_arr = (int*)operator_new(capacity * 8);
                                if (*out != 0) {
                                    for (int j = 0; j < capacity; j++) {
                                        new_arr[j] = (*out)[j];
                                    }
                                }
                                capacity *= 2;
                                if (*out != 0) {
                                    operator_delete(*out);
                                }
                                *out = new_arr;
                            }
                            (*out)[count] = this->importantObjectMemory[i].id;
                            count++;
                        }
                    }
                }
            }
            i++;
        } while (i < this->maxImportantObjectMemory);
    }

    return count;
}

int TribeInformationAIModule::numberGameIDsOwnedBy(int param1, int param2) {
    int result = 0;
    int i = 0;

    if (this->maxImportantObjectMemory > 0) {
        do {
            int id = this->importantObjectMemory[i].id;
            if (id != -1) {
                RGE_Game_World* world = this->md->aiPlayer->world;
                RGE_Static_Object* obj = world->object(id);
                if (obj != 0) {
                    short owner_id = obj->owner->id;
                    if (owner_id == param2 && (param1 == -1 || param1 == this->importantObjectMemory[i].owner)) {
                        result++;
                    }
                }
            }
            i++;
        } while (i < this->maxImportantObjectMemory);
    }

    return result;
}

#include <math.h>
#include <string.h>

ConstructionItem* TribeInformationAIModule::placeDock(
    BuildItem* item, float x, float targetY, int terrain_type, int tile_type)
{
    // The zone-map output and cache array use separate homes.
    RGE_Visible_Map* visible = this->md->aiPlayer->visible;
    RGE_Map* map = this->md->aiPlayer->world->map;
    int bestY;
    RGE_Zone_Map* zoneMap;
    int bestX;
    int zoneMapIndex;
    unsigned char zoneCounter[256];
    int randomOffset;
    float bestScore;
    int y;

    bestX = -1;
    bestY = -1;
    bestScore = -1.0f;
    randomOffset = -1;

    memset(zoneCounter, -1, sizeof(zoneCounter));

    zoneMap = map->map_zones->get_zone_map(
        this->md->player->world->terrains[
            this->md->player->master_objects[0x13]->terrain],
        this->md->player->world->terrain_size, zoneMapIndex);

    randomOffset = debug_rand(
        (char*)"C:\\msdev\\work\\age1_x1\\taiinfmd.cpp", 0x6A9) % 0x32;

    {
        int currentZone = 1;
        if (currentZone < visible->widthValue - 2) {
            do {
                y = 1;
                if (y < visible->heightValue - 2) {
                    do {
                        if (visible->get_visible(currentZone, y) != 0 &&
                            currentZone - 1 >= 0 && y - 1 >= 0 &&
                            currentZone + 1 <= visible->widthValue - 1 &&
                            y + 1 <= visible->heightValue - 1) {
                            if (terrain_type == -1 ||
                                (map->map_row_offset[y][currentZone].terrain_type & 0x1F) == terrain_type) {
                                unsigned char zone = zoneMap->get_zone_info(
                                    currentZone, y);
                                int numberTiles =
                                    zoneMap->numberTilesInZone(zone);
                                int minimumTiles =
                                    this->md->tacticalAI.strategicNumber(0x70);
                                if (numberTiles >= minimumTiles &&
                                    this->hasAdjacentTileType(
                                        currentZone, y, tile_type)) {
                                    ConstructionItem* lot =
                                        this->md->constructionAI.randomLot(
                                            (float)currentZone - DAT_00575570,
                                            (float)y - DAT_00575570);
                                    if (lot == 0) {
                                        float score = ((float)currentZone - x) *
                                                      ((float)currentZone - x) +
                                                      ((float)y - targetY) *
                                                      ((float)y - targetY);
                                        if (zoneCounter[zone] == 0xFF) {
                                            zoneCounter[zone] = (unsigned char)
                                                this->numberDocksInZone(
                                                    (int)zone, zoneMap);
                                        }
                                        // A positive count selects the
                                        // penalty block and emits TEST/JBE.
                                        if (zoneCounter[zone] > 0) {
                                            int zonePenalty =
                                                (int)zoneCounter[zone] * 1000;
                                            score += (float)zonePenalty;
                                        }

                                        {
                                            int closest =
                                                this->closestDockDistance(
                                                    currentZone, y);
                                            if (closest != -1) {
                                                score += (float)(100000 / closest);
                                            }
                                        }

                                        if (bestX == -1 ||
                                            score < bestScore + (float)randomOffset) {
                                            bestScore = score;
                                            bestX = currentZone;
                                            bestY = y;
                                        }
                                    }
                                }
                            }
                        }

                        y++;
                    } while (y < visible->heightValue - 2);
                }

                currentZone++;
            } while (currentZone < visible->widthValue - 2);
        }
    }

    if (bestX != -1) {
        ConstructionItem* result =
            new ConstructionItem((float)bestX - DAT_00575570,
                                 (float)bestY - DAT_00575570,
                                 0.0f, item->xSize(), item->ySize(),
                                 item->zSize(), item->typeID(), item->name());
        return result;
    }
    return 0;
}

#include <stddef.h>

int TribeInformationAIModule::numberDocksInZone(int param_1, RGE_Zone_Map* param_2)
{
    int count = 0;
    int i = 0;

    if (this->playerBuildings.numberValue > 0) {
        do {
            RGE_Static_Object* obj = this->md->object(this->playerBuildings[i]);
            if (obj != 0 && obj->master_obj->id == 0x2D) {
                unsigned char dockZone = param_2->get_zone_info(
                    (int)obj->world_x, (int)obj->world_y);
                if (dockZone == param_1) {
                    count++;
                }
            }

            i++;
        } while (i < this->playerBuildings.numberValue);
    }

    return count;
}

#include <stddef.h>
#include <math.h>

int TribeInformationAIModule::closestDockDistance(int x, int y)
{
    int i;
    int distance;

    i = 0;
    distance = -1;

    if (this->playerBuildings.numberValue > 0) {
        do {
            RGE_Static_Object* obj = this->md->object(this->playerBuildings[i]);
            if (obj != 0 && obj->master_obj->id == 0x2D) {
                int distanceSquared =
                    (x - (int)obj->world_x) * (x - (int)obj->world_x) +
                    (y - (int)obj->world_y) * (y - (int)obj->world_y);
                int currentDistance = (int)sqrt((float)distanceSquared);

                if (currentDistance != 0 &&
                    (distance == -1 || distance > currentDistance)) {
                    distance = currentDistance;
                }
            }

            i++;
        } while (i < this->playerBuildings.numberValue);
    }

    return distance;
}

int TribeInformationAIModule::hasAdjacentTileType(int param_1,int param_2,int param_3){
    RGE_Map* map = this->md->player->world->map;
    int x = param_1;
    int y = param_2;
    for (int i = 0; i < 8; i++) {
        switch (i) {
        case 0: x = param_1 - 1; y = param_2 - 1; break;
        case 1: x = param_1;     y = param_2 - 1; break;
        case 2: x = param_1 + 1; y = param_2 - 1; break;
        case 3: x = param_1 + 1; y = param_2;     break;
        case 4: x = param_1 + 1; y = param_2 + 1; break;
        case 5: x = param_1;     y = param_2 + 1; break;
        case 6: x = param_1 - 1; y = param_2 + 1; break;
        default: x = param_1 - 1; y = param_2;     break;
        }
        if (x >= 0 && y >= 0 && x < map->map_width && y < map->map_height &&
            map->get_terrain((short)x, (short)y) == param_3)
            return 1;
    }
    return 0;
}

int TribeInformationAIModule::mapXSize() {
    if (this->mapXSizeValue == -1) {
        this->mapXSizeValue = this->md->aiPlayer->world->map->map_width;
    }
    return this->mapXSizeValue;
}

int TribeInformationAIModule::mapYSize() {
    if (this->mapYSizeValue == -1) {
        this->mapYSizeValue = this->md->aiPlayer->world->map->map_height;
    }
    return this->mapYSizeValue;
}

void TribeInformationAIModule::addEnemyInfluences(int player, int excludeId)
{
    XYPoint maxLOS;
    XYPoint maxRange;
    XYPoint minLOS;
    XYPoint minRange;
    int index = 0;
    if (this->maxImportantObjectMemory <= 0) return;
    do {
        if (this->importantObjectMemory[index].owner == player) {
            int id = this->importantObjectMemory[index].id;
            if (id != excludeId) {
                RGE_Static_Object* obj = this->md->object(id);
                if (obj != 0) {
                    minLOS.x = (int)(obj->world_x - obj->master_obj->los);
                    minLOS.y = (int)(obj->world_y - obj->master_obj->los);
                    this->mapBound(&minLOS);
                    maxLOS.x = (int)(obj->master_obj->los + obj->world_x);
                    maxLOS.y = (int)(obj->master_obj->los + obj->world_y);
                    this->mapBound(&maxLOS);
                    int x = minLOS.x;
                    if (x <= maxLOS.x) {
                        do {
                            int y = minLOS.y;
                            if (y <= maxLOS.y) {
                                do {
                                    int v = (int)aiPathSystem.lookupMisc(x, y) + 10;
                                    if (v > 255) v = 255;
                                    aiPathSystem.setMisc(x, y, (unsigned char)v);
                                    y++;
                                } while (y <= maxLOS.y);
                            }
                            x++;
                        } while (x <= maxLOS.x);
                    }

                    if (this->importantObjectMemory[index].range > DAT_00575564) {
                        minRange.x = (int)(obj->world_x - this->importantObjectMemory[index].range);
                        minRange.y = (int)(obj->world_y - this->importantObjectMemory[index].range);
                        this->mapBound(&minRange);
                        maxRange.x = (int)(obj->world_x + this->importantObjectMemory[index].range);
                        maxRange.y = (int)(obj->world_y + this->importantObjectMemory[index].range);
                        this->mapBound(&maxRange);
                        int x2 = minRange.x;
                        if (x2 <= maxRange.x) {
                            do {
                                int y2 = minRange.y;
                                if (y2 <= maxRange.y) {
                                    do {
                                        int v2 = (int)aiPathSystem.lookupMisc(x2, y2) + 10;
                                        if (v2 > 255) v2 = 255;
                                        aiPathSystem.setMisc(x2, y2, (unsigned char)v2);
                                        y2++;
                                    } while (y2 <= maxRange.y);
                                }
                                x2++;
                            } while (x2 <= maxRange.x);
                        }
                    }
                }
            }
        }
        index++;
    } while (index < this->maxImportantObjectMemory);
}

void TribeInformationAIModule::addPriorAttackInfluences(int targetOwner, int unused)
{
    XYPoint max;
    XYPoint min;
    int count;

    count = 0;
    if (this->maxAttackMemories > 0) {
        do {
            if (this->attackMemories[count].id != -1 &&
                (int)this->attackMemories[count].targetOwner == targetOwner &&
                (unsigned short)this->attackMemories[count].attackingOwner ==
                    this->md->player->id) {
                min.x = this->attackMemories[count].minX;
                min.y = this->attackMemories[count].minY;
                this->mapBound(&min);

                max.x = this->attackMemories[count].maxX;
                max.y = this->attackMemories[count].maxY;
                this->mapBound(&max);

                for (int x = min.x; x <= max.x; ++x) {
                    for (int y = min.y; y <= max.y; ++y) {
                        aiPathSystem.setMisc(x, y, 0x4B);
                    }
                }

                min.x = min.x - 5;
                min.y = min.y - 5;
                this->mapBound(&min);
                max.x += 5;
                max.y += 5;
                this->mapBound(&max);

                for (int x2 = min.x; x2 <= max.x; ++x2) {
                    for (int y2 = min.y; y2 <= max.y; ++y2) {
                        aiPathSystem.setMisc(x2, y2, 0x0F);
                    }
                }
            }
            ++count;
        } while (count < this->maxAttackMemories);
    }
}

ObjectMemory* TribeInformationAIModule::objectMemory(int param_1) {
    int iVar1;
    ObjectMemory* pOVar2;
    ObjectMemory* base;

    if (param_1 != -1) {
        iVar1 = 0;
        if (0 < this->maxImportantObjectMemory) {
            base = this->importantObjectMemory;
            pOVar2 = base;
            while (iVar1 < this->maxImportantObjectMemory) {
                if (pOVar2->id == param_1) {
                    return base + iVar1;
                }
                iVar1 = iVar1 + 1;
                pOVar2 = pOVar2 + 1;
            }
            return 0;
        }
    }
    return 0;
}

ObjectMemory* TribeInformationAIModule::addObjectMemory(RGE_Static_Object* obj) {
    if (obj == 0) return 0;
    return addObjectMemory(obj->id,
                           obj->master_obj->id,
                           obj->master_obj->object_group,
                           (int)obj->world_x,
                           (int)obj->world_y,
                           (int)obj->world_z,
                           obj->owner->id,
                           (int)obj->hp,
                           0,
                           0,
                           obj->damageCapability(),
                           obj->rateOfFire(),
                           obj->weaponRange(),
                           obj);
}

ObjectMemory* TribeInformationAIModule::addObjectMemory(int id, short type, short group, uchar x, uchar y, uchar z, uchar owner, short hp, int attempts, uchar kills, float dmg, float rof, float range, RGE_Static_Object* obj)
{
    int maxMemory = this->maxImportantObjectMemory;
    int empty = -1;
    int i = 0;
    ObjectMemory* p = this->importantObjectMemory;
    while (i < maxMemory) {
        if (p->id == id) {
            goto duplicate;
        }
        if (p->id == -1 && empty == -1) empty = i;
        ++i;
        ++p;
    }

    if (obj) {
        unsigned int playerNum = this->md->player->world->player_turn;
        if (this->md->tacticalAI.strategicNumber(0xc9) == 1) {
            int myNum = this->md->player->id;
            if (playerNum == (unsigned int)myNum || playerNum == 0xff) {
                RGE_Player* op = obj->owner;
                if (op->id > 0 && op->computerPlayer() == 0 && rge_base_game->singlePlayerGame() == 1) {
                    int t = this->convertUnitToIntType(obj);
                    if (t != -1) ++this->unitHistory[t];
                }
            }
        }
    }

    if (empty == -1) {
        ObjectMemory* mem = (ObjectMemory*)operator new(this->maxImportantObjectMemory * 0x48);
        if (!mem) return 0;
        empty = 0;
        if (this->maxImportantObjectMemory > 0) {
            i = 0;
            do {
                mem[i] = this->importantObjectMemory[i];
                ++empty;
                ++i;
            } while (empty < this->maxImportantObjectMemory);
        }
        if (empty < this->maxImportantObjectMemory * 2) {
            do {
                mem[empty].id = -1;
                mem[empty].type = -1;
                mem[empty].group = -1;
                mem[empty].x = 0;
                mem[empty].y = 0;
                mem[empty].z = 0;
                mem[empty].owner = 0;
                mem[empty].hitPoints = 0;
                mem[empty].attackAttempts = 0;
                mem[empty].kills = 0;
                mem[empty].damageCapability = 0.0f;
                mem[empty].rateOfFire = 0.0f;
                mem[empty].range = 0.0f;
                ++empty;
            } while (empty < this->maxImportantObjectMemory * 2);
        }
        operator delete(this->importantObjectMemory);
        this->importantObjectMemory = mem;
        this->importantObjectMemory[this->maxImportantObjectMemory].id = id;
        this->importantObjectMemory[this->maxImportantObjectMemory].type = type;
        this->importantObjectMemory[this->maxImportantObjectMemory].group = group;
        this->importantObjectMemory[this->maxImportantObjectMemory].x = x;
        this->importantObjectMemory[this->maxImportantObjectMemory].y = y;
        this->importantObjectMemory[this->maxImportantObjectMemory].z = z;
        this->importantObjectMemory[this->maxImportantObjectMemory].owner = owner;
        this->importantObjectMemory[this->maxImportantObjectMemory].hitPoints = hp;
        this->importantObjectMemory[this->maxImportantObjectMemory].attackAttempts = attempts;
        this->importantObjectMemory[this->maxImportantObjectMemory].kills = kills;
        this->importantObjectMemory[this->maxImportantObjectMemory].damageCapability = dmg;
        this->importantObjectMemory[this->maxImportantObjectMemory].rateOfFire = rof;
        this->importantObjectMemory[this->maxImportantObjectMemory].range = range;
        int oldCount = this->maxImportantObjectMemory;
        this->maxImportantObjectMemory = oldCount * 2;
        return this->importantObjectMemory + oldCount;
    }

    this->importantObjectMemory[empty].id = id;
    this->importantObjectMemory[empty].type = type;
    this->importantObjectMemory[empty].group = group;
    this->importantObjectMemory[empty].x = x;
    this->importantObjectMemory[empty].y = y;
    this->importantObjectMemory[empty].z = z;
    this->importantObjectMemory[empty].owner = owner;
    this->importantObjectMemory[empty].hitPoints = hp;
    this->importantObjectMemory[empty].attackAttempts = attempts;
    this->importantObjectMemory[empty].kills = kills;
    this->importantObjectMemory[empty].damageCapability = dmg;
    this->importantObjectMemory[empty].rateOfFire = rof;
    this->importantObjectMemory[empty].range = range;
    return this->importantObjectMemory + empty;

duplicate:
    this->importantObjectMemory[i].id = id;
    this->importantObjectMemory[i].type = type;
    this->importantObjectMemory[i].group = group;
    this->importantObjectMemory[i].x = x;
    this->importantObjectMemory[i].y = y;
    this->importantObjectMemory[i].z = z;
    this->importantObjectMemory[i].owner = owner;
    this->importantObjectMemory[i].hitPoints = hp;
    this->importantObjectMemory[i].attackAttempts = attempts;
    this->importantObjectMemory[i].kills = kills;
    this->importantObjectMemory[i].damageCapability = dmg;
    this->importantObjectMemory[i].rateOfFire = rof;
    this->importantObjectMemory[i].range = range;
    return this->importantObjectMemory + i;
}

int TribeInformationAIModule::addImportantObject(RGE_Static_Object* obj, int recurse) {
    int oType;
    int marked;
    int id;
    int i;

    if (obj != 0 && obj->id >= 0) {
        oType = obj->master_obj->object_group;
        if (importantObject(oType) != 0) {
            RGE_Game_World* world = this->md->player->world;
            int ownerID = obj->owner->id;
            if (recurse == 0 && ownerID > 0 && this->md->player->isEnemy(ownerID) != 0 && world->player_num > 3 && this->md->tacticalAI.strategicNumber(0xC2) == 1) {
                for (i = 1; i < world->player_num; ++i) {
                    if (i != this->md->player->id) {
                        RGE_Player* other = world->players[i];
                        if (other->computerPlayer() != 0 && this->md->player->isAlly(i) != 0 && other->isAlly(this->md->player->id) != 0) {
                            static_cast<TRIBE_Player*>(other)->playerAI->informationAI
                                .addImportantObject(obj, 1);
                        }
                    }
                }
            }

            marked = checkDefend(obj);
            id = obj->id;
            i = 0;
            for (i = 0; i < this->importantObjects.numberValue; ++i) {
                if (i >= this->importantObjects.maximumSizeValue) break;
                if (this->importantObjects.value[i] == id) goto important_unit;
            }
            if (this->importantObjects.numberValue > this->importantObjects.maximumSizeValue - 1) {
                int newMaximum = this->importantObjects.numberValue + 1;
                int* newValue = (int*)operator new(newMaximum * 4);
                if (newValue != 0) {
                    int j = 0;
                    while (j < this->importantObjects.maximumSizeValue && j < newMaximum) {
                        newValue[j] = this->importantObjects.value[j];
                        ++j;
                    }
                    operator delete(this->importantObjects.value);
                    this->importantObjects.value = newValue;
                    this->importantObjects.maximumSizeValue = newMaximum;
                }
            }
            this->importantObjects.value[this->importantObjects.numberValue] = id;
            this->importantObjects.numberValue = this->importantObjects.numberValue + 1;

important_unit:
            if (importantUnit(oType) == 1) {
                id = obj->id;
                i = 0;
                for (i = 0; i < this->importantUnits.numberValue; ++i) {
                    if (i >= this->importantUnits.maximumSizeValue) break;
                    if (this->importantUnits.value[i] == id) goto end;
                }
                if (this->importantUnits.numberValue > this->importantUnits.maximumSizeValue - 1) {
                    int newMaximum = this->importantUnits.numberValue + 1;
                    int* newValue = (int*)operator new(newMaximum * 4);
                    if (newValue != 0) {
                        int j = 0;
                        while (j < this->importantUnits.maximumSizeValue && j < newMaximum) {
                            newValue[j] = this->importantUnits.value[j];
                            ++j;
                        }
                        operator delete(this->importantUnits.value);
                        this->importantUnits.value = newValue;
                        this->importantUnits.maximumSizeValue = newMaximum;
                    }
                }
                this->importantUnits.value[this->importantUnits.numberValue] = id;
                this->importantUnits.numberValue = this->importantUnits.numberValue + 1;
            } else {
                if (importantResource(oType) == 1) {
                    addResourceObject(obj);
                } else if (importantMisc(oType) == 1) {
                    id = obj->id;
                    i = 0;
                    for (i = 0; i < this->importantMiscs.numberValue; ++i) {
                        if (i >= this->importantMiscs.maximumSizeValue) break;
                        if (this->importantMiscs.value[i] == id) goto end;
                    }
                    if (this->importantMiscs.numberValue > this->importantMiscs.maximumSizeValue - 1) {
                        int newMaximum = this->importantMiscs.numberValue + 1;
                        int* newValue = (int*)operator new(newMaximum * 4);
                        if (newValue != 0) {
                            int j = 0;
                            while (j < this->importantMiscs.maximumSizeValue && j < newMaximum) {
                                newValue[j] = this->importantMiscs.value[j];
                                ++j;
                            }
                            operator delete(this->importantMiscs.value);
                            this->importantMiscs.value = newValue;
                            this->importantMiscs.maximumSizeValue = newMaximum;
                        }
                    }
                    this->importantMiscs.value[this->importantMiscs.numberValue] = id;
                    this->importantMiscs.numberValue = this->importantMiscs.numberValue + 1;
                }
            }

end:
            if (importantUnit(oType) == 1 || marked == 1) {
                addObjectMemory(obj);
            }
            return 1;
        }
    }
    return 0;
}

int TribeInformationAIModule::addImportantObject(int objectId) {
    RGE_Static_Object* obj = this->md->object(objectId);
    return this->addImportantObject(obj, 0);
}

int TribeInformationAIModule::importantObject(int param_1) {
    if (importantUnit(param_1) == 0) {
        if (importantResource(param_1) == 0) {
            if (importantMisc(param_1) == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int TribeInformationAIModule::importantUnit(int type_id) {
    if (type_id != 0 && type_id != 3 && type_id != 4 && type_id != 0x18 &&
        type_id != 0x15 && type_id != 6 && type_id != 0x19 && type_id != 0x11 &&
        type_id != 0x1A && type_id != 0xC && type_id != 0x23 && type_id != 0x17 &&
        type_id != 0x24 && type_id != 0x1C && type_id != 0x12 && type_id != 0xD &&
        type_id != 2 && type_id != 0x14 && type_id != 0x1B && type_id != 0x16 &&
        type_id != 0x27) {
        return 0;
    }
    return 1;
}

int TribeInformationAIModule::importantResource(int param_1) {
    if (param_1 == 0x1F || param_1 == 5 || param_1 == 0x21 || param_1 == 7 ||
        param_1 == 9 || param_1 == 8 || param_1 == 0x20 || param_1 == 0xF) {
        return 1;
    }
    return 0;
}

int TribeInformationAIModule::importantMisc(int value) {
    if (value != 1 && value != 0x1E) {
        return 0;
    }
    return 1;
}

int TribeInformationAIModule::isBuilding(RGE_Static_Object* obj) {
    short group;

    group = obj->master_obj->object_group;
    if (group != 3 && group != 0x1B)
        return 0;
    return 1;
}

int TribeInformationAIModule::isUnitBuilding(RGE_Static_Object* obj) {
    RGE_Master_Static_Object* mo = obj->master_obj;
    if (mo->object_group != 3) {
        return 0;
    }
    unsigned short id = mo->id;
    if (id == 0x6d || id == 0x0c || id == 0x57 || id == 0x31 || id == 0x2d || id == 0 || id == 0x65 || id == 0x68) {
        return 1;
    }
    return 0;
}

int TribeInformationAIModule::isBoat(RGE_Static_Object* obj) {
    unsigned short group = obj->master_obj->object_group;
    if (group == 0x15 || group == 2 || group == 0x14 || group == 0x16) {
        return 1;
    }
    return 0;
}

int TribeInformationAIModule::isWall(RGE_Static_Object* obj) {
    return obj->master_obj->object_group == 0x1B;
}

int TribeInformationAIModule::isTower(RGE_Static_Object* object) {
    short id = object->master_obj->id;

    if ((id == 0x4F) || (id == 0xC7) || (id == 0x45) || (id == 0x17F) || (id == 0x17C)) {
        return 1;
    }
    return 0;
}

int TribeInformationAIModule::isBoatAccessible(RGE_Static_Object* param_1, int param_2) {
    RGE_Static_Object* obj = this->md->object(param_2);
    if (obj == 0) {
        return 0;
    }
    if (obj->master_obj->object_group == 0x15 || obj->master_obj->object_group == 2 || obj->master_obj->object_group == 0x14 || obj->master_obj->object_group == 0x16 || obj->master_obj->id == 0x2d) {
        return 1;
    }
    return 0;
}

int TribeInformationAIModule::isLandAccessible(RGE_Static_Object* param_1, int param_2) {
    RGE_Static_Object* object = md->object(param_2);
    if (object != 0) {
        short group = object->master_obj->object_group;
        if (group != 0x15 && group != 2 && group != 0x14 && group != 0x16) {
            return 1;
        }
    }
    return 0;
}

int TribeInformationAIModule::influenceCanPlaceStructure(BuildItem* p0) {
    return 1;
}

#include <math.h>
#include <stdlib.h>

#pragma intrinsic(sqrt)

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
    } else if (item != 0) {
        x = item->typeID();
        buildingSize = item->xSize();
        objectName = item->name();
    } else {
        x = objectType;
        buildingSize = objectSize;
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
                                            int value = iMap.lookupValue(
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
                                            iMap.connectionCountValue;
                                        if (placement == 4 ||
                                            placement == 6) {
                                            int connections =
                                                iMap.connectionsIncluding(
                                                    minClear, maxClear,
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

void TribeInformationAIModule::addObject(RGE_Static_Object* obj)
{
    register RGE_Static_Object* object = obj;
    if (object != 0 && object->id >= 0) {
        ObjectMemory* mem = this->objectMemory(object->id);
        if (mem != 0) {
            mem->owner = object->owner->id;
        }

        int id = object->id;
        int count = this->playerObjects.numberValue;
        int i = 0;
        while (i < count && i < this->playerObjects.maximumSizeValue) {
            if (this->playerObjects.value[i] == id) goto after_objects;
            ++i;
        }
        if (count > this->playerObjects.maximumSizeValue - 1) {
            int newMax = count + 1;
            int* newArray = (int*)operator new(newMax * 4);
            if (newArray != 0) {
                i = 0;
                while (i < this->playerObjects.maximumSizeValue && i < newMax) {
                    newArray[i] = this->playerObjects.value[i];
                    ++i;
                }
                operator delete(this->playerObjects.value);
                this->playerObjects.value = newArray;
                this->playerObjects.maximumSizeValue = newMax;
            }
        }
        this->playerObjects.value[this->playerObjects.numberValue] = id;
        ++this->playerObjects.numberValue;
after_objects:

        if (this->includeObject(object) == 1) {
            id = object->id;
            count = this->playerBuildings.numberValue;
            i = 0;
            while (i < count && i < this->playerBuildings.maximumSizeValue) {
                if (this->playerBuildings.value[i] == id) goto after_buildings;
                ++i;
            }
            if (count > this->playerBuildings.maximumSizeValue - 1) {
                int newMax = count + 1;
                int* newArray = (int*)operator new(newMax * 4);
                if (newArray != 0) {
                    i = 0;
                    while (i < this->playerBuildings.maximumSizeValue && i < newMax) {
                        newArray[i] = this->playerBuildings.value[i];
                        ++i;
                    }
                    operator delete(this->playerBuildings.value);
                    this->playerBuildings.value = newArray;
                    this->playerBuildings.maximumSizeValue = newMax;
                }
            }
            this->playerBuildings.value[this->playerBuildings.numberValue] = id;
            ++this->playerBuildings.numberValue;
after_buildings:

            short type = object->master_obj->object_group;
            if (type == 0x6d || type == 0x67 || type == 0x44) {
                this->addDocks();
            }
            if (object->master_obj->object_group == 0x32) {
                this->addHouse(object);
            }
        }
    }
}

void TribeInformationAIModule::removeObject(int param_1)
{
    int idx;
    int* ptr;

    idx = 0;
    while (idx < playerBuildings.maximumSizeValue) {
        if (playerBuildings.value[idx] == param_1)
            break;
        idx++;
    }

    if (idx < playerBuildings.maximumSizeValue) {
        if (idx < playerBuildings.maximumSizeValue - 1) {
            do {
                ptr = playerBuildings.value;
                idx++;
                ptr[idx - 1] = ptr[idx];
            } while (idx < playerBuildings.maximumSizeValue - 1);
        }
        playerBuildings.numberValue--;
        if (playerBuildings.numberValue < 0)
            playerBuildings.numberValue = 0;
    }

    idx = 0;
    while (idx < playerObjects.maximumSizeValue) {
        if (playerObjects.value[idx] == param_1)
            break;
        idx++;
    }

    if (idx < playerObjects.maximumSizeValue) {
        if (idx < playerObjects.maximumSizeValue - 1) {
            do {
                ptr = playerObjects.value;
                idx++;
                ptr[idx - 1] = ptr[idx];
            } while (idx < playerObjects.maximumSizeValue - 1);
        }
        playerObjects.numberValue--;
        if (playerObjects.numberValue < 0)
            playerObjects.numberValue = 0;
    }

    RGE_Static_Object* obj = md->object(param_1);
    if (obj != 0) {
        ObjectMemory* mem = objectMemory(param_1);
        if (mem != 0) {
            unsigned char owner_id = *(unsigned char*)(*(int*)((char*)obj + 0x0C) + 0x4A);
            mem->owner = owner_id;
        }
    }
}

ObjectMemory* TribeInformationAIModule::objectToAttackWithPlay(
    int group, int* unitIds, int count, int& playNumber,
    int* outputUnits, int& outputCount, int& outputUnit)
{
    int targetNumber;
    ObjectMemory* target;
    int worldNumber;
    RGE_Game_World* world;
    AIPlayBook* playbook;

    if (count == 0) {
        return (ObjectMemory*)count;
    }

    target = this->objectToAttackByGroup2(group, unitIds, count);
    if (target == 0) {
        return 0;
    }

    targetNumber = 0;
            world = this->md->player->world;
    playbook = world->playbook;
    playNumber = -1;

    for (; targetNumber < playbook->numberPlaysValue; ++targetNumber) {
            AIPlay* play = playbook->play(targetNumber);
            if (play == 0) {
                continue;
            }
            if (play->humanPlay() == 1) {
                continue;
            }

            AIPlayStatus playStatus;
            playStatus.playNumberValue = targetNumber;
            play->fillGroups(&playStatus, unitIds, count, world);
            if (playStatus.deviationValue > 0) {
                continue;
            }

            bool invalid = false;
            worldNumber = 0;
            do {
                if (invalid != 0) {
                    break;
                }
                int phase = 0;
                do {
                    if (invalid != 0) {
                        break;
                    }
                    AIPlayPhaseCommand* command =
                        play->phase(worldNumber)->command(phase);
                    if (command->type() == 1) {
                        int x = (int)target->x + command->value1();
                        int y = (int)target->y + command->value2();
                        if (x < 0 || y < 0 ||
                            x >= this->mapXSizeValue ||
                            y >= this->mapYSizeValue) {
                            invalid = 1;
                        }
                        if (this->inRangeOfUnits(group, x, y, 0) == 1) {
                            invalid = 1;
                        }
                    }
                    ++phase;
                } while (phase < 5);
                ++worldNumber;
            } while (worldNumber < 10);

            if (invalid == 0) {
                int variation;
                int randomValue;
                int strategicValue;
                int score;
                variation = this->calculatePlayVariation(targetNumber);
                score = 100 - (int)play->deathPercentageValue + variation;
                randomValue =
                    debug_rand("C:\\msdev\\work\\age1_x1\\taiinfmd.cpp", 0xd49) % 0x32;
                strategicValue = 0;

                switch (play->typeValue) {
                case 1:
                    strategicValue =
                        this->md->tacticalAI.strategicNumber(0xbd);
                    break;
                case 2:
                    strategicValue =
                        this->md->tacticalAI.strategicNumber(0xc6);
                    break;
                case 3:
                    strategicValue =
                        this->md->tacticalAI.strategicNumber(0xc7);
                    break;
                }

                score = score * 2 + strategicValue + randomValue;
                if (playNumber == -1 || score > 0) {
                    playNumber = targetNumber;
                    playStatus.copyUnits(outputUnits, outputCount);
                    randomValue =
                        debug_rand("C:\\msdev\\work\\age1_x1\\taiinfmd.cpp", 0xd6a);
                    outputUnit = outputUnits[randomValue % outputCount];
                }
            }
    }

    if (playNumber == -1) {
        return 0;
    }
    ++this->playHistory[playNumber];
    return target;
}

#include <math.h>

ObjectMemory* TribeInformationAIModule::objectToAttack(int player, int siegeWeapons, int boats, int objnum, int& output)
{
    int* out = &output;
    RGE_Static_Object* candidate;
    RGE_Static_Object* unit;
    ObjectMemory* best;
    int specialRating3;
    uchar unitZone;
    int rangeRating;
    ObjectMemory* mem = this->wonderToAttack(-1);
    if (mem != 0) {
        *out = 1;
        return mem;
    }

    unit = this->md->object(objnum);
    if (unit == 0 || unit->unitAI() == 0) {
        return 0;
    }

    unitZone = unit->currentZone();
    if (unit->master_obj->id == 0x23 ||
        unit->master_obj->id == 0x24 ||
        unit->master_obj->id == 0x0B) {
        rangeRating = 1;
    } else {
        rangeRating = 0;
    }
    int unitIsBoat = this->isBoat(unit);
    int numberNonSiegeTargets = 0;
    if (unit->master_obj->object_group == 0x12) numberNonSiegeTargets = 1;

    int randomRating;
    int id;
    ObjectMemory oLimits = findObjectMemoryLimits(player, objnum, &randomRating, &id);

    best = 0;
    specialRating3 = -1;
    int dCRating;
    int i;
    for (dCRating = 0, i = 0; dCRating < this->maxImportantObjectMemory; dCRating++, i += 0x24) {
            if (*(uchar*)((char*)this->importantObjectMemory + i + 0x0B) == player) {
                candidate = this->md->object(*(int*)((char*)this->importantObjectMemory + i));
                if (candidate != 0 && candidate->object_state <= 2) {
                    float damage = this->damagePerSecond(objnum,
                                                         (int)candidate->world_x,
                                                         (int)candidate->world_y);
                    float fVar3 = candidate->damageCapability(unit) /
                                  unit->rateOfFire();
                    float boatWeapon;
                    float bestObject;
                    if (damage > DAT_00575580) {
                        boatWeapon = unit->hp / damage;
                    } else {
                        boatWeapon = -1.0f;
                    }
                    if (fVar3 > DAT_00575580) {
                        bestObject =
                            (float)*(short*)((char*)this->importantObjectMemory + i + 0x0C) / fVar3;
                    } else {
                        bestObject = -1.0f;
                    }
                    if (rangeRating == 0 && siegeWeapons != 0 &&
                        (candidate->master_obj->object_group == 3 ||
                         candidate->master_obj->object_group == 0x1B) &&
                        randomRating > 0) {
                        continue;
                    }
                    if (unitIsBoat == 0 && boats != 0 &&
                        (candidate->master_obj->id == 0x2D ||
                         candidate->master_obj->object_group == 2 ||
                         candidate->master_obj->object_group == 0x15 ||
                         candidate->master_obj->object_group == 0x16 ||
                         candidate->master_obj->object_group == 0x14) &&
                        id > 0) {
                        continue;
                    }
                    if (numberNonSiegeTargets != 0) {
                        float dangerousThreat;
                        if (unit->unitAI()->mostDangerousEnemy(&dangerousThreat) !=
                            this->importantObjectMemory[dCRating].id) continue;
                    }
                    int ix = (int)candidate->world_x;
                    int iy = (int)candidate->world_y;
                    int dx1 = (int)*(uchar*)((char*)this->importantObjectMemory + i + 0x08) - ix;
                    if (dx1 < 0) dx1 = -dx1;
                    int dy1 = (int)*(uchar*)((char*)this->importantObjectMemory + i + 0x09) - iy;
                    if (dy1 < 0) dy1 = -dy1;
                    if (dx1 > 5 || dy1 > 5) {
                        if (this->md->player->visible->get_visible(ix, iy) != 0x0F) {
                            continue;
                        }
                    }
                    int dx2 = (int)*(uchar*)((char*)this->importantObjectMemory + i + 0x08)
                              - (int)unit->world_x;
                    int dy2 = (int)*(uchar*)((char*)this->importantObjectMemory + i + 0x09)
                              - (int)unit->world_y;
                    int distance = (int)(sqrt(dx2 * dx2 + dy2 * dy2));
                    int unitIsPriest;
                    if (oLimits.id != 0) {
                        unitIsPriest = 100 - distance * 100 / oLimits.id;
                    } else {
                        unitIsPriest = 100;
                    }
                    int distanceRating;
                    if (oLimits.hitPoints != 0) {
                        distanceRating =
                            (int)*(short*)((char*)this->importantObjectMemory + i + 0x0C) * 100
                            / oLimits.hitPoints;
                    } else {
                        distanceRating = 100;
                    }
                    int bestAttackValue;
                    if (oLimits.kills != 0) {
                        bestAttackValue =
                            (int)*(uchar*)((char*)this->importantObjectMemory + i + 0x14) * 100
                            / (int)oLimits.kills;
                    } else {
                        bestAttackValue = 100;
                    }
                    int hpRating;
                    if (oLimits.damageCapability != DAT_00575580) {
                        hpRating =
                            (int)(*(float*)((char*)this->importantObjectMemory + i + 0x18)
                                  * DAT_00575584 / oLimits.damageCapability);
                    } else {
                        hpRating = 100;
                    }
                    int timeToKill;
                    int siegeWeapon;
                    if (*(float*)((char*)this->importantObjectMemory + i + 0x18) > DAT_00575580) {
                        if (oLimits.range != DAT_00575580) {
                            timeToKill =
                                (int)(*(float*)((char*)this->importantObjectMemory + i + 0x20)
                                      * DAT_00575584 / oLimits.range);
                        } else {
                            timeToKill = 100;
                        }
                        if (oLimits.rateOfFire != DAT_00575580) {
                            siegeWeapon =
                                100 - (int)(*(float*)((char*)this->importantObjectMemory + i + 0x1C)
                                           * DAT_00575584 / oLimits.rateOfFire);
                        } else {
                            siegeWeapon = 100;
                        }
                    } else {
                        timeToKill = 0;
                        siegeWeapon = 0;
                    }
                    int numberNonBoatTargets =
                        debug_rand((char*)"C:\\msdev\\work\\age1_x1\\taiinfmd.cpp", 0xE36) % 100;
                    int typeMatchA = 0;
                    if (*(short*)((char*)this->importantObjectMemory + i + 0x04)
                            == this->md->tacticalAI.strategicNumber(0x6A)) typeMatchA = 1;
                    int typeMatchB = 0;
                    if (*(short*)((char*)this->importantObjectMemory + i + 0x04)
                            == this->md->tacticalAI.strategicNumber(0x6B)) typeMatchB = 1;
                    int typeMatchC = 0;
                    if (*(short*)((char*)this->importantObjectMemory + i + 0x04)
                            == this->md->tacticalAI.strategicNumber(0x6C)) typeMatchC = 1;
                    int specialRating2 = 0;
                    if (unit->lookupZone((int)candidate->world_x,
                                         (int)candidate->world_y) == unitZone) {
                        specialRating2 = 1;
                    }
                    int rangeSign;
                    int boatSign;
                    if (candidate->master_obj->object_group == 3 ||
                        candidate->master_obj->object_group == 0x1B) {
                        rangeSign = rangeRating ? 1 : -1;
                    } else {
                        rangeSign = rangeRating ? -1 : 1;
                    }
                    if (candidate->master_obj->id == 0x2D ||
                        candidate->master_obj->object_group == 2 ||
                        candidate->master_obj->object_group == 0x15 ||
                        candidate->master_obj->object_group == 0x16 ||
                        candidate->master_obj->object_group == 0x14) {
                        boatSign = unitIsBoat ? 1 : -1;
                    } else {
                        boatSign = unitIsBoat ? -1 : 1;
                    }
                    int rating =
                            this->md->tacticalAI.strategicNumber(0x59)
                            * *(int*)((char*)this->importantObjectMemory + i + 0x10)
                        + this->md->tacticalAI.strategicNumber(0x90) * boatSign
                        + this->md->tacticalAI.strategicNumber(0x7B) * rangeSign
                        + this->md->tacticalAI.strategicNumber(0x7A) * specialRating2
                        + this->md->tacticalAI.strategicNumber(0x50) * bestAttackValue
                        + this->md->tacticalAI.strategicNumber(0x53) * numberNonBoatTargets
                        + this->md->tacticalAI.strategicNumber(0x4D) * unitIsPriest
                        + this->md->tacticalAI.strategicNumber(0x6F) * typeMatchC
                        + this->md->tacticalAI.strategicNumber(0x5A) * timeToKill
                        + this->md->tacticalAI.strategicNumber(0x4E) * distanceRating
                        + this->md->tacticalAI.strategicNumber(0x4F) * hpRating
                        + this->md->tacticalAI.strategicNumber(0x52) * siegeWeapon
                        + this->md->tacticalAI.strategicNumber(0x6E) * typeMatchB
                        + this->md->tacticalAI.strategicNumber(0x6D) * typeMatchA;
                    if ((bestObject > boatWeapon && boatWeapon != -1.0f) ||
                        bestObject == -1.0f) {
                        rating = 1;
                    }
                    if (best == 0 || rating > specialRating3) {
                        best = (ObjectMemory*)((char*)this->importantObjectMemory + i);
                        specialRating3 = rating;
                        *out = 1;
                    }
                }
            }
    }
    return best;
}

#include <math.h>

ObjectMemory* TribeInformationAIModule::objectToAttackByGroup(
    int owner, TacticalAIGroup* group, AttackState& stateRef, unsigned long currentTime)
{
    AttackState* state = &stateRef;
    ObjectMemory* wonder = 0;
    unsigned char commanderZone;
    RGE_Static_Object* commanderObject = this->md->object(group->commander());
    int commanderIsBoat = 0;
    float targetDistance;
    int commanderIsPriest = 0;
    int destroyIndex = 0;

    if (commanderObject == 0 || commanderObject->unitAI() == 0) {
        state->active = 0;
        goto done;
    }

    commanderZone = commanderObject->currentZone();
    if (commanderObject->master_obj->object_group == 0x12) {
        commanderIsPriest = 1;
    }
    if (this->isBoat(commanderObject) == 1) {
        commanderIsBoat = 1;
    }

    if (state->active == 0 &&
        group->objectsToDestroyOwnerValue == owner &&
        group->numberObjectsToDestroyValue > 0 &&
        group->objectsToDestroyCommanderZoneValue == (int)commanderZone) {
        int objectID = group->objectToDestroy(group->numberObjectsToDestroyValue - 1);
        RGE_Static_Object* object = this->md->object(objectID);

        if (object != 0 &&
            this->md->player->isEnemy(object->owner->id) == 1 &&
            object->object_state <= 2 &&
            commanderObject->canPath(
                group->objectToDestroy(group->numberObjectsToDestroyValue - 1),
                commanderObject->weaponRange(), 0, 0, -1, -1) == 1) {
            objectID = group->objectToDestroy(group->numberObjectsToDestroyValue - 1);
            group->numberObjectsToDestroyValue = 0;
            group->addObjectToDestroy(objectID);
            wonder = this->objectMemory(objectID);
            goto done;
        }
    }

    if (group->numberObjectsToDestroyValue - 1 > 0) {
        for (destroyIndex = 0;
             destroyIndex < group->numberObjectsToDestroyValue - 1;
             ++destroyIndex) {
            RGE_Static_Object* object = this->md->object(group->objectToDestroy(destroyIndex));
            if (object != 0 &&
                this->md->player->isEnemy(object->owner->id) == 1 &&
                object->object_state <= 2 &&
                commanderObject->canPath(
                    group->objectToDestroy(destroyIndex),
                    commanderObject->weaponRange(), 0, 0, -1, -1) == 1) {

                goto selected_destroy_object;
            }
        }
    }

    if (state->active == 0) {
        wonder = this->wonderToAttack(-1);
        if (wonder != 0) {
            unsigned char wonderZone = commanderObject->lookupZone((int)wonder->x, (int)wonder->y);
            if (wonderZone != commanderZone && commanderIsBoat == 0) {
                goto done;
            }
            if (commanderObject->canPath(wonder->id,
                                         commanderObject->weaponRange(),
                                         0, 0, -1, -1) == 1) {
                group->numberObjectsToDestroyValue = 0;
                group->addObjectToDestroy(wonder->id);
                group->objectsToDestroyOwnerValue = wonder->owner;
                group->objectsToDestroyCommanderZoneValue = (int)commanderZone;
                goto done;
            }

            ManagedArray<int> wallObjects;
            if (commanderObject->canPathWithObstructions(
                    wonder->id, commanderObject->weaponRange(), 0, 1, owner, 0x1B,
                    wallObjects) == 1) {
                group->numberObjectsToDestroyValue = 0;
                for (int i = 0; i < wallObjects.numberValue; ++i) {
                    if (this->md->object(wallObjects[i]) != 0) {
                        this->addImportantObject(wallObjects[i]);
                        group->addObjectToDestroy(wallObjects[i]);
                    }
                }
                group->addObjectToDestroy(wonder->id);
                group->objectsToDestroyCommanderZoneValue = (int)commanderZone;
                group->objectsToDestroyOwnerValue = wonder->owner;
                goto done;
            }
        }

        state->bestTargetID = -1;
        state->bestTargetValue = -1.0f;
        state->bestTargetMemoryIndex = -1;
        state->iterationIndex = 0;
        state->attackGroupID = -1;
        state->playID = -1;
        state->phase = 0;
        state->bestNonWallTargetID = -1;
        state->bestNonWallTargetValue = -1.0f;
        state->bestNonWallTargetMemoryIndex = -1;
        state->active = 1;
    }

    destroyIndex = state->iterationIndex;
    for (; destroyIndex < this->maxImportantObjectMemory; ++destroyIndex) {
        ObjectMemory* memory = this->importantObjectMemory + destroyIndex;

        if (destroyIndex > state->iterationIndex) {
            if (debug_timeGetTime("C:\\msdev\\work\\age1_x1\\taiinfmd.cpp", 0xF5A) - currentTime >=
                this->md->player->world->availableComputerPlayerUpdateTime) {
                state->iterationIndex = destroyIndex;
                goto done;
            }
        }

        if (memory->owner != owner) {
            continue;
        }

        RGE_Static_Object* target = this->md->object(memory->id);
        if (target == 0 || target->object_state > 2 || target->hp == DAT_00575580) {
            continue;
        }

        if (commanderIsBoat == 0 && this->isBoat(target) == 1) {
            continue;
        }

        int targetX = (int)target->world_x;
        int targetY = (int)target->world_y;
        unsigned char targetZone = commanderObject->lookupZone(targetX, targetY);

        if (commanderIsBoat == 0 && memory->type == 0x2D && targetZone != commanderZone) {
            continue;
        }
        if (state->phase == 0 && memory->group == 0x1B) {
            continue;
        }
        if (state->phase == 1 && memory->group != 0x1B) {
            continue;
        }

        int visibleDX = (int)memory->x - (int)target->world_x;
        if (visibleDX < 0) {
            visibleDX = -visibleDX;
        }
        int visibleDY = (int)memory->y - (int)target->world_y;
        if (visibleDY < 0) {
            visibleDY = -visibleDY;
        }
        if ((visibleDX > 5 || visibleDY > 5) &&
            this->md->player->visible->get_visible(targetX, targetY) != 0x0F) {
            continue;
        }

        if (commanderIsPriest != 0 &&
            commanderObject->unitAI()->seekAndDestroy(
                memory->id, memory->x, memory->y, 1) == 0) {
            continue;
        }

        float damage = this->damageInflictedPerSecond(group, target);
        float killTimeRatio = target->hp / damage;
        float killTime = this->timeToBeKilled(group, target);
        if (damage == DAT_00575580) {
            continue;
        }
        if (killTime == DAT_00575580) {
            continue;
        }
        killTimeRatio = killTime / killTimeRatio;

        int dx = (int)memory->x - (int)target->world_x;
        if (dx < 0) {
            dx = -dx;
        }
        int dy = (int)memory->y - (int)target->world_y;
        if (dy < 0) {
            dy = -dy;
        }
        targetDistance = (float)sqrt((double)(dx * dx + dy * dy));
        if (targetDistance < DAT_00575564) {
            targetDistance = 1.0f;
        }

        float randomFactor = 0.0f;
        if (this->md->tacticalAI.strategicNumber(0x53) > 0) {
            randomFactor = (float)(debug_rand("C:\\msdev\\work\\age1_x1\\taiinfmd.cpp", 0xFD5) %
                this->md->tacticalAI.strategicNumber(0x53));
        }

        float attackAttemptFactor =
            (float)this->md->tacticalAI.strategicNumber(0x59) * memory->attackAttempts;
        float sameZoneFactor = 0.0f;
        if (targetZone == commanderZone) {
            sameZoneFactor = (float)this->md->tacticalAI.strategicNumber(0x7A);
        }

        float currentTargetFactor = 0.0f;
        if (this->md->tacticalAI.strategicNumber(0xB9) > 0) {
            int currentTargetCount = 0;
            if (group->numberUnits() > 0) {
                int unitIndex = 0;
                do {
                    RGE_Static_Object* unit =
                        this->md->object(group->unit(unitIndex));
                    if (unit != 0 && unit->unitAI() != 0 &&
                        unit->unitAI()->currentTarget() == memory->id) {
                        ++currentTargetCount;
                    }
                    ++unitIndex;
                } while (unitIndex < group->numberUnits());
            }
            currentTargetFactor =
                (float)this->md->tacticalAI.strategicNumber(0xB9) * currentTargetCount;
        }

        float nonWallFactor = 0.0f;
        if (state->phase == 1 && state->bestNonWallTargetID != -1) {
            ObjectMemory* previous =
                this->importantObjectMemory + state->bestNonWallTargetMemoryIndex;
            int previousDX = (int)memory->x - (int)previous->x;
            int previousDY = (int)memory->y - (int)previous->y;
            float previousDistance =
                (float)sqrt((double)(previousDX * previousDX + previousDY * previousDY));
            if (previousDistance < 1.0f) {
                nonWallFactor = 1000.0f;
            } else {
                nonWallFactor = DAT_0057558c / previousDistance;
            }
        }

        if (this->isUnitBuilding(target) == 1) {
            if (target->master_obj->id == 0x6D || target->master_obj->id == 0x2D) {
                nonWallFactor -= DAT_00575594;
            } else {
                nonWallFactor -= DAT_00575590;
            }
        }

        float score =
            (float)this->md->tacticalAI.strategicNumber(0x50) * memory->kills;
        score +=
            (float)this->md->tacticalAI.strategicNumber(0x4D) / targetDistance;
        score +=
            (float)this->md->tacticalAI.strategicNumber(0xB8) * killTimeRatio;
        score += nonWallFactor + currentTargetFactor + attackAttemptFactor +
            sameZoneFactor + randomFactor;

        if (state->bestTargetID != -1 && score <= state->bestTargetValue) {
            continue;
        }

        if (state->phase == 0 && target->maximumSpeed() == DAT_00575580) {
            state->bestNonWallTargetID = memory->id;
            state->bestNonWallTargetMemoryIndex = destroyIndex;
            state->bestNonWallTargetValue = score;
        }

        int obstructionGroup = state->phase == 0 ? 0x1B : -1;
        ManagedArray<int> wallObjects;
        if (targetZone == commanderZone &&
            commanderObject->canPath(memory->id,
                                     commanderObject->weaponRange(),
                                     0, 0, -1, -1) != 1 &&
            commanderObject->canPathWithObstructions(
                memory->id, commanderObject->weaponRange(), 0, 1, owner,
                obstructionGroup, wallObjects) != 1) {
            continue;
        }

        group->numberObjectsToDestroyValue = 0;
        for (int i = 0; i < wallObjects.numberValue; ++i) {
            if (this->md->object(wallObjects[i]) != 0) {
                this->addImportantObject(wallObjects[i]);
                group->addObjectToDestroy(wallObjects[i]);
            }
        }
        group->addObjectToDestroy(memory->id);
        group->objectsToDestroyCommanderZoneValue = (int)commanderZone;
        group->objectsToDestroyOwnerValue = memory->owner;
        state->bestTargetID = memory->id;
        state->bestTargetMemoryIndex = destroyIndex;
        state->bestTargetValue = score;
    }

    if (state->bestTargetID != -1) {
        ++(this->importantObjectMemory[state->bestTargetMemoryIndex].attackAttempts);
        state->active = 0;
        destroyIndex = 0;
        goto selected_destroy_object;
    }

    if (state->phase == 0) {
        state->phase = 1;
        state->iterationIndex = 0;
    } else {
        state->active = 0;
    }
    goto done;

selected_destroy_object:
    wonder = this->objectMemory(group->objectToDestroy(destroyIndex));

done:
    return wonder;
}

#include <math.h>

ObjectMemory* TribeInformationAIModule::objectToAttackByGroup2(int group, int* ids, int count)
{
    ObjectMemory* bestObject;
    ObjectMemory* wonder = this->wonderToAttack(-1);
    if (wonder != 0) {
        return wonder;
    }

    if (count != 0) {
        RGE_Static_Object* commanderObj = this->md->object(*ids);
        if (commanderObj != 0) {
            if (commanderObj->unitAI() != 0) {
                unsigned char commanderZone = commanderObj->currentZone();
                int commanderIsPriest = 0;
                if (commanderObj->master_obj->object_group == 0x12) {
                    commanderIsPriest = 1;
                }

                bestObject = 0;
                float bestScore = -1.0f;
                float bestAttackValue = 0.0f;
                int timeTK = 0;

                if (this->maxImportantObjectMemory > 0) {
                    do {
                        if (this->importantObjectMemory[timeTK].owner == group) {
                            RGE_Static_Object* object =
                                this->md->object(this->importantObjectMemory[timeTK].id);
                            if (object != 0) {
                                int dx;
                                int dy;
                                if (object->object_state <= 2 && object->hp != DAT_00575580) {
                                    dx = (int)this->importantObjectMemory[timeTK].x - (int)object->world_x;
                                    if (dx < 0) {
                                        dx = -dx;
                                    }
                                    dy = (int)this->importantObjectMemory[timeTK].y - (int)object->world_y;
                                    if (dy < 0) {
                                        dy = -dy;
                                    }

                                    if ((dx <= 5 && dy <= 5) ||
                                        this->md->player->visible->get_visible(
                                            (int)object->world_x, (int)object->world_y) == 0x0f) {
                                        // slot +0xC4 receives ObjectMemory::id.
                                        if (commanderIsPriest == 0 ||
                                            commanderObj->unitAI()->canAttackUnit(object) != 0) {
                                            float damage;
                                            float hpOverDamage;
                                            float time;
                                            float targetTime;
                                            float targetDistance;
                                            damage = this->damageInflictedPerSecond(ids, count, object);
                                            hpOverDamage = object->hp / damage;
                                            time = this->timeToBeKilled(ids, count, object);
                                            if (damage != DAT_00575580 && time != DAT_00575580) {
                                                targetTime = time / hpOverDamage;
                                                int targetX = (int)commanderObj->world_x;
                                                int targetY = (int)commanderObj->world_y;
                                                dx = (int)this->importantObjectMemory[timeTK].x - targetX;
                                                dy = (int)this->importantObjectMemory[timeTK].y - targetY;
                                                targetDistance = (float)sqrt((float)(dx * dx + dy * dy));
                                                if (targetDistance < DAT_00575564) {
                                                    targetDistance = 1.0f;
                                                }

                                                int randomNumber = this->md->tacticalAI.strategicNumber(0x53);
                                                if (randomNumber < 1) {
                                                    bestAttackValue = 0.0f;
                                                } else {
                                                    int randomRange = this->md->tacticalAI.strategicNumber(0x53);
                                                    bestAttackValue = (float)(debug_rand("C:\\msdev\\work\\age1_x1\\taiinfmd.cpp", 0x110b) % randomRange);
                                                }

                                                int killCount =
                                                    this->importantObjectMemory[timeTK].kills;
                                                float attackAttemptFactor =
                                                    (float)this->md->tacticalAI.strategicNumber(0x59) *
                                                    (float)this->importantObjectMemory[timeTK].attackAttempts;
                                                float targetRandomization = 0.0f;
                                                int lookupX = (int)object->world_x;
                                                int lookupY = (int)object->world_y;
                                                if (commanderZone == commanderObj->lookupZone(lookupX, lookupY)) {
                                                    targetRandomization = (float)this->md->tacticalAI.strategicNumber(0x7a);
                                                }

                                                float zoneFactor = 0.0f;
                                                int strategicB9 = this->md->tacticalAI.strategicNumber(0xb9);
                                                if (strategicB9 > 0) {
                                                    int currentTargetCount = 0;
                                                    if (count > 0) {
                                                        int* currentID = ids;
                                                        int remaining = count;
                                                        do {
                                                            RGE_Static_Object* currentObject = this->md->object(*currentID);
                                                            if (currentObject != 0 && currentObject->unitAI() != 0 &&
                                                                currentObject->unitAI()->currentTarget() ==
                                                                    this->importantObjectMemory[timeTK].id) {
                                                                ++currentTargetCount;
                                                            }
                                                            ++currentID;
                                                            --remaining;
                                                        } while (remaining != 0);
                                                    }
                                                    zoneFactor = (float)this->md->tacticalAI.strategicNumber(0xb9) * (float)currentTargetCount;
                                                }

                                                float score =
                                                    (float)this->md->tacticalAI.strategicNumber(0xb8) *
                                                    targetTime;
                                                score +=
                                                    (float)this->md->tacticalAI.strategicNumber(0x4d) /
                                                    targetDistance;
                                                score +=
                                                    (float)this->md->tacticalAI.strategicNumber(0x50) *
                                                    (float)killCount;
                                                score += zoneFactor;
                                                score += targetRandomization;
                                                score += attackAttemptFactor;
                                                score += bestAttackValue;
                                                if (bestObject == 0 || score > bestScore) {
                                                    bestObject = &this->importantObjectMemory[timeTK];
                                                    bestScore = score;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        ++timeTK;
                    } while (timeTK < this->maxImportantObjectMemory);
                }
                return bestObject;
            }
        }
    }
    return 0;
}

ObjectMemory* TribeInformationAIModule::objectToDefend(int target_obj_id)
{
    ObjectMemory* bestEntry;
    int bestDefendValue;
    XYPoint pt;
    int i;
    int objectId;

    RGE_Static_Object* target = this->md->object(target_obj_id);
    if (target == 0)
        return 0;

    bestEntry = 0;
    bestDefendValue = -1;
    i = 0;

    if (this->maxImportantObjectMemory > 0) {
        do {
            objectId = this->importantObjectMemory[i].id;
            if (objectId != -1) {
                if (this->itemsToDefend.contains(objectId)) {
                    if (this->importantObjectMemory[i].attackAttempts <= 0) {
                        pt.x = (int)this->importantObjectMemory[i].x;
                        pt.y = (int)this->importantObjectMemory[i].y;

                        TacticalAIGroup* bestG =
                            this->md->tacticalAI.bestGroup(
                                -1, 4,
                                this->md->tacticalAI.strategicNumber(0x5C),
                                &pt, -1);

                        if (bestG == 0) {
                            int priority = this->defendPriority(
                                (int)this->importantObjectMemory[i].type,
                                (int)this->importantObjectMemory[i].group);
                            if (bestEntry == 0 || bestDefendValue > priority) {
                                bestEntry = &this->importantObjectMemory[i];
                                bestDefendValue = priority;
                            }
                        }
                    }
                }
            }

            i++;
        } while (i < this->maxImportantObjectMemory);
    }

    return bestEntry;
}

ObjectMemory* TribeInformationAIModule::higherPriorityObjectToDefend(int objId, int type, int group)
{
    RGE_Static_Object* mainObj = this->md->object(objId);
    ObjectMemory* best;
    if (mainObj == 0)
        return 0;

    *(unsigned char*)&objId = mainObj->currentZone();
    best = 0;
    group = this->defendPriority(type, group);
    int i = 0;
    if (this->maxImportantObjectMemory > 0) {
        do {
            ObjectMemory* entry = &this->importantObjectMemory[i];
            int id = entry->id;
            if (id != -1) {
                int j = 0;
                int defendCount = this->itemsToDefend.numberValue;
                if (defendCount > 0) {
                    while (j < defendCount) {
                        if (j >= this->itemsToDefend.maximumSizeValue)
                            break;
                        if (this->itemsToDefend.value[j] == id) {
                            if (entry->attackAttempts <= 0) {
                                RGE_Static_Object* target = this->md->object(id);
                                if (target != 0) {
                                    if (*(unsigned char*)&objId != target->currentZone()) {
                                        XYPoint pt;
                                        pt.x = (int)target->world_x;
                                        pt.y = (int)target->world_y;
                                        if (mainObj->withinRangeOfZoneAtPoint(
                                                *(unsigned char*)&objId,
                                                mainObj->getSpeed(), pt) != 1)
                                            break;
                                    }
                                    int pri = this->defendPriority(
                                        this->importantObjectMemory[i].type,
                                        this->importantObjectMemory[i].group);
                                    if (group > pri) {
                                        group = pri;
                                        best = &this->importantObjectMemory[i];
                                    }
                                }
                            }
                            break;
                        }
                        j++;
                    }
                }
            }
            i++;
        } while (i < this->maxImportantObjectMemory);
    }
    return best;
}

int TribeInformationAIModule::defendPriority(int param_1, int param_2)
{
    switch (param_1) {
    case 0x6D:
        return md->tacticalAI.strategicNumber(0x38);
    case 0x2D:
        return md->tacticalAI.strategicNumber(0x46);
    case 0x9F:
        return md->tacticalAI.strategicNumber(0x37);
    case 0x9E:
    case 0xA3:
        return md->tacticalAI.strategicNumber(0x36);
    }

    switch (param_2) {
    case 7:
        return md->tacticalAI.strategicNumber(0x34);
    case 8:
        return md->tacticalAI.strategicNumber(0x33);
    case 0x20:
        return md->tacticalAI.strategicNumber(0x32);
    default:
        return -1;
    }
}

int TribeInformationAIModule::checkDefend(RGE_Static_Object* obj)
{
    int group = obj->master_obj->object_group;
    int owner = obj->owner->id;
    int id;
    int tmp;

    switch (obj->master_obj->id) {
    case 109: {
        if (owner != this->md->player->id)
            goto checkDefend_fail;
        if (this->md->tacticalAI.strategicNumber(0x38) <= 0)
            goto checkDefend_fail;
        id = obj->id;
        {
            ManagedArray<int>* list = &this->itemsToDefend;
            int numValues = list->numberValue;
            for (int i = 0; i < numValues && i < list->maximumSizeValue; i++) {
                if (list->value[i] == id)
                    return 1;
            }
            if (list->numberValue > list->maximumSizeValue - 1)
                list->resize(list->numberValue + 1);
            list->value[list->numberValue] = id;
            list->numberValue++;
        }
        return 1;
    }
    case 45: {
        if (owner != this->md->player->id)
            goto checkDefend_fail;
        if (this->md->tacticalAI.strategicNumber(0x46) <= 0)
            goto checkDefend_fail;
        id = obj->id;
        {
            ManagedArray<int>* list = &this->itemsToDefend;
            int numValues = list->numberValue;
            for (int i = 0; i < numValues && i < list->maximumSizeValue; i++) {
                if (list->value[i] == id)
                    return 1;
            }
            if (list->numberValue > list->maximumSizeValue - 1)
                list->resize(list->numberValue + 1);
            list->value[list->numberValue] = id;
            list->numberValue++;
        }
        return 1;
    }
    case 0x9f: {
        if (this->md->tacticalAI.strategicNumber(0x37) <= 0)
            goto checkDefend_fail;
        id = obj->id;
        {
            ManagedArray<int>* list = &this->itemsToDefend;
            int numValues = list->numberValue;
            for (int i = 0; i < numValues && i < list->maximumSizeValue; i++) {
                if (list->value[i] == id)
                    return 1;
            }
            if (list->numberValue > list->maximumSizeValue - 1)
                list->resize(list->numberValue + 1);
            list->value[list->numberValue] = id;
            list->numberValue++;
        }
        return 1;
    }
    case 0x9e:
    case 0xa3: {
        if (this->md->tacticalAI.strategicNumber(0x36) <= 0)
            goto checkDefend_fail;
        id = obj->id;
        {
            ManagedArray<int>* list = &this->itemsToDefend;
            int numValues = list->numberValue;
            for (int i = 0; i < numValues && i < list->maximumSizeValue; i++) {
                if (list->value[i] == id)
                    return 1;
            }
            if (list->numberValue > list->maximumSizeValue - 1)
                list->resize(list->numberValue + 1);
            list->value[list->numberValue] = id;
            list->numberValue++;
        }
        return 1;
    }
    default:
        switch (group) {
        case 7:
            if (this->md->tacticalAI.strategicNumber(0x34) <= 0)
                goto checkDefend_fail;
            this->itemsToDefend.add(obj->id);
            return 1;
        case 8: {
            int result8 = this->md->tacticalAI.strategicNumber(0x33);
            if (result8 <= 0)
                goto checkDefend_fail;
            tmp = obj->id;
            ManagedArray<int>* list8 = &this->itemsToDefend;
            if (list8->contains(tmp) == 1)
                return 1;
            int numValues = this->itemsToDefend.numberValue;
            if (numValues > this->itemsToDefend.maximumSizeValue - 1)
                list8->resize(numValues + 1);
            list8->value[this->itemsToDefend.numberValue] = tmp;
            this->itemsToDefend.numberValue++;
            return 1;
        }
        case 32: {
            int result32 = this->md->tacticalAI.strategicNumber(0x32);
            if (result32 <= 0)
                goto checkDefend_fail;
            tmp = obj->id;
            if (this->itemsToDefend.contains(tmp) == 1)
                return 1;
            int numValues = this->itemsToDefend.numberValue;
            if (numValues > this->itemsToDefend.maximumSizeValue - 1)
                this->itemsToDefend.resize(numValues + 1);
            this->itemsToDefend.value[this->itemsToDefend.numberValue] = tmp;
            this->itemsToDefend.numberValue++;
            return 1;
        }
        default:
            goto checkDefend_fail;
        }
    }

checkDefend_fail:
    return 0;
}

int TribeInformationAIModule::numberItemsToDefend() {
    return this->itemsToDefend.numberValue;
}

ObjectMemory* TribeInformationAIModule::objectToTradeWith(int param_1)
{
    RGE_Static_Object* unit = this->md->object(param_1);
    if (unit == 0)
        return 0;

    ObjectMemory* bestDock = 0;
    int bestDockDistance = 0;
    int i = 0;

    if (this->maxImportantObjectMemory > 0) {
        do {
            if (this->importantObjectMemory[i].id != -1 &&
                this->importantObjectMemory[i].owner != this->md->player->id &&
                this->importantObjectMemory[i].type == 0x2D) {
                RGE_Static_Object* dock = this->md->object(
                    this->importantObjectMemory[i].id);
                if (dock != 0 && dock->owner->attributes[9] > DAT_00575580) {
                    ObjectMemory* candidate = &this->importantObjectMemory[i];
                    int dx = (int)candidate->x - (int)unit->world_x;
                    int dy = (int)candidate->y - (int)unit->world_y;
                    int dist = dx * dx + dy * dy;
                    if (bestDock == 0 || dist < bestDockDistance) {
                        bestDock = candidate;
                        bestDockDistance = dist;
                    }
                }
            }
            i++;
        } while (i < this->maxImportantObjectMemory);
    }

    return bestDock;
}

int TribeInformationAIModule::findGatherPosition(XYPoint& p, int group, int clearDistance, int minDistance, int maxDistance, RGE_Static_Object* obj, XYPoint& out)
{
    XYPoint max;
    XYPoint maxClear;
    XYPoint min;
    XYPoint minClear;
    XYPoint minExclude;
    XYPoint maxExclude;
    XYPoint cPosition;
    XYPoint lineCollisionPoint;
    int bestPointValue;
    int j;
    int i;
    int halfDistance;
    int blocked;
    int yy;
    int xx;
    int yy2;
    int xx2;

    if (maxDistance >= minDistance) return 0;
    min.y = p.x - minDistance - maxDistance;
    minExclude.x = p.y - minDistance - maxDistance;
    mapBound(min);
    max.y = p.x + maxDistance + minDistance;
    minClear.x = p.y + maxDistance + minDistance;
    mapBound(max);
    minExclude.y = p.x - minDistance + maxDistance;
    maxExclude.x = p.y + maxDistance - minDistance;
    mapBound(minExclude);
    maxExclude.y = p.x - maxDistance + minDistance;
    cPosition.x = p.y + minDistance - maxDistance;
    mapBound(maxExclude);
    setupInfluenceMap(0, -1, p, min, max);
    bestPointValue = -1;
    maxClear.x = groupInfluenceDimension(group);
    j = min.y;
    if (j <= max.y) do {
        i = minExclude.x;
        if (i <= minClear.x) do {
            if (minExclude.y > j || j > maxExclude.y || maxExclude.x > i || i > cPosition.x) {
                halfDistance = maxClear.x / 2;
                minClear.y = j - halfDistance;
                min.x = i - halfDistance;
                if (mapBound(minClear) != 1) {
                    maxClear.y = j + halfDistance;
                    max.x = i + halfDistance;
                    if (mapBound(maxClear) != 1) {
                        blocked = 0;
                        for (yy = minClear.y; yy < maxClear.y && !blocked; yy++) {
                            for (xx = min.x; xx < max.x && !blocked; xx++) {
                                if (obj->passableTile((float)yy, (float)xx, 1) == 0) blocked = 1;
                            }
                        }
                        if (blocked != 1) {
                            int val = 0x80;
                            cPosition.y = j;
                            lineCollisionPoint.x = i;
                            if (obj->canLinePath(cPosition, p, (float)minDistance,
                                                 lineCollisionPoint, 1) == 0) val = 0x40;
                            for (yy2 = minClear.y; yy2 <= maxClear.y && !blocked; yy2++) {
                                for (xx2 = min.x; xx2 <= max.x && !blocked; xx2++) {
                                    int v = iMap.lookupValue(yy2, xx2);
                                    if (v == 0xff) blocked = 1; else val += v;
                                }
                            }
                            if (blocked != 1 && (bestPointValue == -1 || bestPointValue < val)) {
                                bestPointValue = val;
                                out.x = j;
                                out.y = i;
                            }
                        }
                    }
                }
            }
            i++;
        } while (i <= minClear.x);
        j++;
    } while (j <= max.y);
    return bestPointValue != -1;
}

#include <stdlib.h>

void TribeInformationAIModule::setupInfluenceMap(int mode, int objectType,
                                                   XYPoint& unused,
                                                   XYPoint& from,
                                                   XYPoint& to)
{
    iMap.initialize(0x14);
    iMap.setUnchangeableLimit(0xff);

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
                    iMap.decrementValue(x, y, 10);
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

                        bMin.x = (int)(object->world_x - object->master_obj->radius_x - DAT_00575564);
                        bMin.y = (int)(object->world_y - radiusY - DAT_00575564);
                        this->mapBound(&bMin);
                        bMax.x = (int)(object->world_x + radiusY - DAT_0057556c);
                        bMax.y = (int)(object->world_y + radiusY - DAT_0057556c);
                        this->mapBound(&bMax);
                        bMinLOS.x = (int)object->master_obj->radius_x;
                        bMinLOS.y = (int)object->master_obj->radius_y;
                        this->mapBound(&bMinLOS);

                        if (mode == 1 || mode == 2) {
                            iMap.setValue(bMinLOS.x, bMinLOS.y, 0xff);
                        } else {
                            iMap.setValue(bMin.x, bMin.y, bMax.x, bMax.y, 0xff);
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
                                    iMap.incrementValue(bMin.x, bMin.y,
                                                          bMax.x, bMax.y, 8);

                                    bMin.x -= 3;
                                    bMin.y -= 3;
                                    this->mapBound(&bMin);
                                    bMax.x += 3;
                                    bMax.y += 3;
                                    this->mapBound(&bMax);
                                    iMap.incrementValue(bMin.x, bMin.y,
                                                          bMax.x, bMax.y, 4);

                                    bMin.x -= 5;
                                    bMin.y -= 5;
                                    this->mapBound(&bMin);
                                    bMax.x += 5;
                                    bMax.y += 5;
                                    this->mapBound(&bMin);
                                    iMap.incrementValue(bMin.x, bMin.y,
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
                                    iMap.decrementValue(bMin.x, bMin.y,
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
                            iMap.incrementValue(bMin.x, bMin.y,
                                                  bMax.x, bMax.y, 0x80);
                        }
                    }
                }
            }
        }
    }

    if (mode == 1 || mode == 2 || mode == 3 || mode == 4 || mode == 0 ||
        mode == 5 || mode == 6 || mode == 8) {
        int i = 0;
        if (this->playerBuildings.numberValue > 0) {
        do {
            RGE_Static_Object* object = this->md->object(this->playerBuildings[i]);
            if (object != 0) {
                int placement = this->placementCode(object->master_obj->id);
                float radiusX = object->master_obj->radius_x;
                float radiusY = object->master_obj->radius_y;
                XYPoint bMin;
                XYPoint bMax;

                if (radiusX == DAT_00575598) {
                    bMin.x = (int)object->world_x;
                    bMin.x -= 3;
                    bMin.y = (int)object->world_y;
                    bMin.y -= 3;
                    bMax.x = (int)object->world_x;
                    bMax.x += 3;
                    bMax.y = (int)object->world_y;
                    bMax.y += 3;
                } else if (radiusX == DAT_005755a0) {
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
                } else if (radiusX == DAT_00575564) {
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
                } else if (radiusX == DAT_005755a8) {
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
                    this->logCommonHistory("    Unsupported building size (%d x %d).",
                                     (double)(radiusX + radiusX),
                                     (double)((float)radiusY + (float)radiusY));
                    goto building_next;
                }

                if (placement == 0x6d) {
                    bMin.x--;
                    bMin.y--;
                    bMax.x++;
                    bMax.y++;
                }
                this->mapBound(&bMin);
                this->mapBound(&bMax);
                iMap.setValue(bMin.x, bMin.y, bMax.x, bMax.y, 0xff);

                if (mode == 3 || mode == 0) {
                    float radiusValue = object->master_obj->los;
                    if (mode == 0) {
                        radiusValue *= DAT_005755b4;
                    }
                    if (placement == 0x6d) {
                        radiusValue *= DAT_005755b4;
                    }
                    int radius = (int)radiusValue;
                    XYPoint minLOS;
                    XYPoint maxLOS;
                    minLOS.x = bMin.x - radius;
                    minLOS.y = bMin.y - radius;
                    this->mapBound(&minLOS);
                    maxLOS.x = bMax.x + radius;
                    maxLOS.y = bMax.y + radius;
                    this->mapBound(&maxLOS);
                    if (mode == 0 && placement == 3) {
                iMap.incrementValue(minLOS.x, minLOS.y,
                                              maxLOS.x, maxLOS.y, 10);
                    } else {
                iMap.decrementValue(minLOS.x, minLOS.y,
                                              maxLOS.x, maxLOS.y, 10);
                    }
                } else if (mode == 1 || mode == 2) {
                    float radiusValue = object->master_obj->los;
                    if (placement == 0x6d) {
                        radiusValue *= DAT_005755b4;
                    }
                    if (objectType == 0x44 || objectType == 0x67) {
                        radiusValue = DAT_00575578;
                    }
                    int radius = (int)radiusValue;
                    XYPoint aMax;
                    XYPoint aMin;
                    aMax.x = bMax.x - radius;
                    aMax.y = bMin.y - radius;
                    this->mapBound(&aMax);
                    aMin.x = bMin.x + radius;
                    aMin.y = bMax.y + radius;
                    this->mapBound(&aMin);
                    iMap.decrementValue(aMax.x, aMax.y,
                                          aMin.x, aMin.y, 10);
                } else if (mode == 5) {
                    float radiusValue = object->master_obj->los;
                    if (placement == 0x6d) {
                        radiusValue *= DAT_005755b0;
                    }
                    int radius = (int)radiusValue;
                    XYPoint minDC;
                    XYPoint maxDC;
                    minDC.x = bMin.x - radius * 2;
                    minDC.y = bMin.y - radius * 2;
                    this->mapBound(&minDC);
                    maxDC.x = bMax.x + radius * 2;
                    maxDC.y = bMax.y + radius * 2;
                    this->mapBound(&maxDC);
                    iMap.decrementValue(minDC.x, minDC.y,
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
                    iMap.incrementValue(minLOS.x, minLOS.y,
                                          maxLOS.x, maxLOS.y, 20);

                    radius /= 2;
                    minLOS.x = bMin.x - radius;
                    minLOS.y = bMin.y - radius;
                    this->mapBound(&minLOS);
                    maxLOS.x = bMax.x + radius;
                    maxLOS.y = bMax.y + radius;
                    this->mapBound(&maxLOS);
                    iMap.incrementValue(minLOS.x, minLOS.y,
                                          maxLOS.x, maxLOS.y, 20);

                    radius /= 3;
                    minLOS.x = bMin.x - radius;
                    minLOS.y = bMin.y - radius;
                    this->mapBound(&minLOS);
                    maxLOS.x = bMax.x + radius;
                    maxLOS.y = bMax.y + radius;
                    this->mapBound(&maxLOS);
                    iMap.incrementValue(minLOS.x, minLOS.y,
                                          maxLOS.x, maxLOS.y, 20);
                }
            }
        building_next:
            i++;
        } while (i < this->playerBuildings.numberValue);
        }
    }

    if (mode == 3 || mode == 4 || mode == 0) {
        RGE_Map* map = this->md->player->world->map;
        for (int x = from.x; x <= to.x; x++) {
            for (int y = from.y; y <= to.y; y++) {
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
                    iMap.setValue(x, y, 0xff);
                    iMap.decrementValue(minTerrain.x, minTerrain.y,
                                          maxTerrain.x, maxTerrain.y, 10);
                }
                iMap.incrementValue(x, y, x, y,
                                      (map->map_row_offset[y][x].height >> 5) * 5);
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
                iMap.incrementValue(min.x, min.y, max.x, max.y, 0x10);
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
    iMap.setConnectionCount(min, max, 0xff, 1, connectionFlag, 1);

    if (mode != 0 && this->maxBuildingLots > 0) {
        for (int i = 0; i < this->maxBuildingLots; i++) {
            BuildingLot* lot = &this->buildingLots[i];
            if (lot->typeID == objectType && lot->status == 2) {
                iMap.setValue(lot->x, lot->y, 0xff);
            }
        }
    }
}

int TribeInformationAIModule::mapBound(XYPoint& pt) {
    int ret = 0;

    if (pt.x < 0) {
        pt.x = 0;
        ret = 1;
    } else if (pt.x >= this->mapXSizeValue) {
        pt.x = this->mapXSizeValue - 1;
        ret = 1;
    }
    if (pt.y < 0) {
        pt.y = 0;
        ret = 1;
    } else if (pt.y >= this->mapYSizeValue) {
        pt.y = this->mapYSizeValue - 1;
        ret = 1;
    }
    return ret;
}

int TribeInformationAIModule::groupInfluenceDimension(int dim) {
    if (dim <= 1) return 2;
    return dim * dim;
}

ObjectMemory TribeInformationAIModule::findObjectMemoryLimits(int owner, int object_id, int& c1, int& c2)
{
    ObjectMemory rVal;
    RGE_Static_Object* target;
    RGE_Static_Object* obj;
    int i;
    uchar zone;
    XYPoint pt;
    int dx;
    int dy;
    int group;
    float dist;

    c1 = 0;
    c2 = 0;
    rVal.id = 0;
    rVal.hitPoints = 0;
    rVal.attackAttempts = 0;
    rVal.kills = 0;
    rVal.damageCapability = 0.0f;
    rVal.rateOfFire = 0.0f;
    rVal.range = 0.0f;

    target = this->md->object(object_id);
    if (target != 0) {
        zone = target->currentZone();
        i = 0;
        if (this->maxImportantObjectMemory > 0) {
            do {
                if ((int)this->importantObjectMemory[i].owner == owner) {
                    obj = this->md->object(this->importantObjectMemory[i].id);
                    if (obj != 0) {
                        if (zone != obj->currentZone()) {
                            pt.x = (int)obj->world_x;
                            pt.y = (int)obj->world_y;
                            if (target->withinRangeOfZoneAtPoint(
                                    zone, target->weaponRange(), pt) != 1)
                                goto next;
                        }
                        obj = this->md->object(this->importantObjectMemory[i].id);
                        if (obj != 0) {
                            dx = (int)this->importantObjectMemory[i].x - (int)obj->world_x;
                            if (dx < 0) dx = -dx;
                            dy = (int)this->importantObjectMemory[i].y - (int)obj->world_y;
                            if (dy < 0) dy = -dy;
                            if ((dx > 5 || dy > 5) &&
                                this->md->player->visible->get_visible(
                                    (int)obj->world_x, (int)obj->world_y) != 0x0F)
                                goto skip_visible;
                            group = this->importantObjectMemory[i].group;
                            if (group != 3 && group != 0x1B)
                                c1++;
                            group = this->importantObjectMemory[i].group;
                            if (group != 2 &&
                                group != 0x15 &&
                                group != 0x16 &&
                                group != 0x14 &&
                                this->importantObjectMemory[i].type != 0x2D)
                                c2++;
                            dist = target->distance_to_position(
                                (float)this->importantObjectMemory[i].x,
                                (float)this->importantObjectMemory[i].y,
                                (float)this->importantObjectMemory[i].z);
                            if (dist > (float)rVal.id) rVal.id = (int)dist;
                            if (this->importantObjectMemory[i].hitPoints > rVal.hitPoints)
                                rVal.hitPoints = this->importantObjectMemory[i].hitPoints;
                            if (this->importantObjectMemory[i].attackAttempts > 0)
                                rVal.hitPoints =
                                    (short)this->importantObjectMemory[i].attackAttempts;
                            if (this->importantObjectMemory[i].kills > 0)
                                rVal.hitPoints =
                                    (unsigned short)this->importantObjectMemory[i].kills;
                            if (this->importantObjectMemory[i].damageCapability > rVal.damageCapability)
                                rVal.damageCapability = this->importantObjectMemory[i].damageCapability;
                            if (this->importantObjectMemory[i].rateOfFire > rVal.rateOfFire)
                                rVal.rateOfFire = this->importantObjectMemory[i].rateOfFire;
                            if (this->importantObjectMemory[i].range > rVal.range)
                                rVal.range = this->importantObjectMemory[i].range;
                        }
                    }
                }
skip_visible:
next:
                i++;
            } while (i < this->maxImportantObjectMemory);
        }
    }
    return rVal;
}

int TribeInformationAIModule::isNextTo(XYPoint& p1, XYPoint& p2, int mode) {
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    int dist = dx * dx + dy * dy;
    if (mode == 0) {
        if (dist > 1) {
            return 0;
        }
        goto check_mode1;
    }
check_mode1:
    if (mode == 1) {
        if (dist > 2) {
            return 0;
        }
    }
    return 1;
}

int TribeInformationAIModule::facetTo(XYPoint& from, XYPoint& to) {
    int dx;
    int dy;

    dx = to.x - from.x;
    dy = to.y - from.y;

    if (dx == 0) {
        if (dy < 0) {
            return 1;
        }
        return 5;
    }
    if (dy == 0) {
        return ((dx >= 0) - 1 & 4) + 3;
    }
    if (dx < 0) {
        if (dy < 0) {
            return 0;
        }
        return 6;
    }
    if (dy < 0) {
        return 2;
    }
    return 4;
}

int TribeInformationAIModule::placementCode(int param_1) {
    switch (param_1) {
    case 0x45:
    case 0x4f:
    case 0xc7:
        return 3;
    case 0x48:
    case 0x75:
    case 0x9b:
        return 4;
    case 0x44:
        return 2;
    case 0x67:
        return 1;
    case 0x46:
    case 0x52:
    case 0x54:
    case 0x6e:
    case 0x114:
        return 6;
    case 0x2d:
        return 7;
    case 0x32:
        return 8;
    case 0x6d:
        return 9;
    default:
        return 5;
    }
}

#include <stddef.h>

void TribeInformationAIModule::storeLot(int typeID, unsigned char x,
                                        unsigned char y, unsigned char built)
{
    int freeIndex = -1;
    int i = 0;

    if (this->maxBuildingLots > 0) {
        BuildingLot* lot = this->buildingLots;
        do {
            if (lot->typeID == typeID && x == lot->x && y == lot->y) {
                this->buildingLots[i].status = built;
                return;
            }

            if (freeIndex == -1 && lot->typeID == -1) {
                freeIndex = i;
            }

            ++i;
            ++lot;
        } while (i < this->maxBuildingLots);
    }

    if (freeIndex == -1) {
        BuildingLot* newLots = (BuildingLot*)::operator new(
            this->maxBuildingLots << 4);
        if (newLots != 0) {
            i = 0;
            if (this->maxBuildingLots > 0) {
                do {
                    newLots[i].typeID = this->buildingLots[i].typeID;
                    newLots[i].x = this->buildingLots[i].x;
                    newLots[i].y = this->buildingLots[i].y;
                    newLots[i].status = this->buildingLots[i].status;
                    ++i;
                } while (i < this->maxBuildingLots);
            }

            if (i < this->maxBuildingLots * 2) {
                do {
                    newLots[i].typeID = -1;
                    newLots[i].x = 0;
                    newLots[i].y = 0;
                    newLots[i].status = built;
                    ++i;
                } while (i < this->maxBuildingLots * 2);
            }

            ::operator delete(this->buildingLots);
            this->buildingLots = newLots;

            newLots[this->maxBuildingLots].typeID = typeID;
            this->buildingLots[this->maxBuildingLots].x = x;
            this->buildingLots[this->maxBuildingLots].y = y;
            this->buildingLots[this->maxBuildingLots].status = built;
            this->maxBuildingLots <<= 1;
        }
    } else {
        this->buildingLots[freeIndex].typeID = typeID;
        this->buildingLots[freeIndex].x = x;
        this->buildingLots[freeIndex].y = y;
        this->buildingLots[freeIndex].status = built;
    }
}

#include <windows.h>

void TribeInformationAIModule::removeLot(int p1, unsigned char p2, unsigned char p3, unsigned char p4)
{
    int idx = 0;
    if (maxBuildingLots <= 0) return;

    BuildingLot* lot = buildingLots;
    goto enter;

loop:
    idx++;
    lot++;
    if (idx >= maxBuildingLots) return;

enter:
    if (lot->typeID == p1 && lot->x == p2 && lot->y == p3)
        goto found;
    goto loop;

found:
    if (p4 != 3) {
        buildingLots[idx].status = p4;
    } else {
        buildingLots[idx].typeID = -1;
        buildingLots[idx].x = 0;
        buildingLots[idx].y = 0;
        buildingLots[idx].status = 3;
    }
}

BuildingLot* TribeInformationAIModule::availableLot(int typeID) {
    int i = 0;
    int max = this->maxBuildingLots;
    BuildingLot* base;
    BuildingLot* cur;

    if (max > 0) {
        base = this->buildingLots;
        cur = base;
        while (1) {
            if (cur->typeID == typeID) {
                if (cur->status == 0) {
                    break;
                }
            }
            i++;
            cur++;
            if (i < max) {
                continue;
            }
            return 0;
        }
        return base + i;
    }
    return 0;
}

int TribeInformationAIModule::invalidLot(int typeID, unsigned char x, unsigned char y) {
    int count = this->maxBuildingLots;
    int i = 0;
    if (count <= 0) return 0;
    for (; i < count; i++) {
        if (this->buildingLots[i].typeID == typeID && this->buildingLots[i].status == 2 && this->buildingLots[i].x == x && this->buildingLots[i].y == y) {
            return 1;
        }
    }
    return 0;
}

int TribeInformationAIModule::undesirableLot(int typeID, unsigned char xRange, unsigned char yRange, int coordOffset) {
    int i = 0;
    int max = this->maxBuildingLots;
    BuildingLot* pLot;

    if (max <= 0) {
        goto ret_zero_late;
    }

    pLot = this->buildingLots;

loop:
    if (pLot->typeID == typeID && pLot->status == 1) {
        int x = (int)pLot->x;
        int y = (int)pLot->y;
        int yMinusOff = y - coordOffset;
        int offPlusX = coordOffset + x;
        int xMinusOff = x - coordOffset;
        int offPlusY = coordOffset + y;

        if (xMinusOff <= (int)xRange && offPlusX >= (int)xRange &&
            yMinusOff <= (int)yRange && offPlusY >= (int)yRange) {
            goto ret_one;
        }
    }
    pLot++;
    i++;
    if (i < max) goto loop;
    return 0;

ret_one:
    return 1;
ret_zero_late:
    return 0;
}

void TribeInformationAIModule::setupWalls(int param_1, int param_2, int param_3, int param_4,
                                           int param_5, int param_6, int param_7, int param_8)
{
    XYPoint realMaxF4;
    XYPoint realMax;
    XYPoint realMin;
    XYPoint realMinDC;
    XYPoint min;
    XYPoint max;
    int count;
    int iVar10;

    if (param_8 == 1 && param_6 > 0) {
        this->numberGatesValue = param_6;

        int slot = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\taiinfmd.cpp", 0x1731) % 4;
        int half = param_7 / 2;

        this->minGatePosition[slot].x = param_1 - half;
        this->minGatePosition[slot].y = param_2 - param_4 * 2;
        this->maxGatePosition[slot].x = param_1 + half;
        this->maxGatePosition[slot].y = param_2;

        slot = (slot + 1) % 4;
        this->minGatePosition[slot].x = param_1 - half;
        this->minGatePosition[slot].y = param_2;
        this->maxGatePosition[slot].x = param_1 + half;
        this->maxGatePosition[slot].y = param_2 + param_4 * 2;

        slot = (slot + 1) % 4;
        this->minGatePosition[slot].x = param_1;
        this->minGatePosition[slot].y = param_2 - half;
        this->maxGatePosition[slot].x = param_1 + param_4 * 2;
        this->maxGatePosition[slot].y = param_2 + half;

        slot = (slot + 1) % 4;
        this->minGatePosition[slot].x = param_1 - param_4 * 2;
        this->minGatePosition[slot].y = param_2 - half;
        this->maxGatePosition[slot].x = param_1;
        this->maxGatePosition[slot].y = param_2 + half;

        if (param_6 > 0) {
            XYPoint* gate = this->maxGatePosition;
            param_8 = param_6;
            do {
                this->mapBound(gate - 4);
                this->mapBound(gate);
                ++gate;
                --param_8;
            } while (param_8 != 0);
        }
    }

    if (param_5 == 0) {
        param_5 = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\taiinfmd.cpp", 0x176A) % 3;
    }

    if (param_5 == 1) {
        if (param_3 <= param_4) {
            int old_x = param_3 + param_2;
            int old_y = param_1 - param_2;
            param_2 = param_2 - param_3;
            param_4 = old_y;
            count = (param_4 - param_3 + 3U) / 3;
            param_3 = old_x;

            do {
                realMinDC.x = param_2;
                min.y = param_4 + param_2;
                this->mapBound(&realMinDC);

                max.y = param_4 + param_3;
                min.x = param_3;
                this->mapBound(&min);

                int y = realMinDC.y;
                int x = realMinDC.x;

                if (y < min.y) {
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        ++y;
                    } while (y < min.y);
                }
                if (x < min.x) {
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        ++x;
                    } while (x < min.x);
                }
                if (min.y < y) {
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        --y;
                    } while (min.y < y);
                }
                if (realMinDC.x < x) {
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        --x;
                    } while (realMinDC.x < x);
                }

                param_2 -= 3;
                param_3 += 3;
                --count;
            } while (count != 0);
            return;
        }
    } else if (param_5 == 2) {
        param_8 = param_3;
        if (param_3 <= param_4) {
            param_7 = param_3 + param_2;
            int old_y = param_1 - param_2;
            int offset = param_2 - param_3;
            max.y = (param_4 - param_3) + 1;
            int x = offset;
            param_3 = param_3 * 2;

            do {
                realMin.y = offset + old_y;
                realMin.x = offset;
                this->mapBound(&realMin);

                max.y = param_8 + 1;
                realMax.x = param_2 - 1 + max.y;
                realMax.y = realMax.x + old_y;
                this->mapBound(&realMax);

                realMinDC.y = x + old_y;
                realMinDC.x = x;
                this->mapBound(&realMinDC);

                realMaxF4.x = param_7;
                realMaxF4.y = param_7 + old_y;
                this->mapBound(&realMaxF4);

                int y = realMinDC.y;
                int i = param_8;

                if (param_3 > 0) {
                    iVar10 = i;
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        --x;
                        --iVar10;
                    } while (iVar10 != 0);
                }
                if (param_3 > 0) {
                    max.x = param_3;
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        ++y;
                        --max.x;
                    } while (max.x != 0);
                }
                if (param_3 > 0) {
                    max.x = i;
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        ++x;
                        --max.x;
                    } while (max.x != 0);
                }
                if (param_3 > 0) {
                    max.x = i;
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        ++y;
                        --max.x;
                    } while (max.x != 0);
                }
                if (param_3 > 0) {
                    max.x = param_3;
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        ++x;
                        --max.x;
                    } while (max.x != 0);
                }
                if (param_3 > 0) {
                    max.x = param_8;
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        --y;
                        --max.x;
                    } while (max.x != 0);
                }

                max.x = max.y;
                if (param_3 >= 0) {
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        ++x;
                        --max.x;
                    } while (max.x != 0);
                }
                max.x = param_3;
                if (param_3 > 0) {
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        --y;
                        --max.x;
                    } while (max.x != 0);
                }
                max.x = max.y;
                if (param_3 >= 0) {
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        --x;
                        --max.x;
                    } while (max.x != 0);
                }
                max.x = param_8;
                if (param_3 > 0) {
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        --y;
                        --max.x;
                    } while (max.x != 0);
                }
                max.x = param_3;
                if (param_3 > 0) {
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        ++x;
                        --max.x;
                    } while (max.x != 0);
                }
                max.x = param_8;
                if (param_3 > 0) {
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        ++y;
                        --max.x;
                    } while (max.x != 0);
                }

                param_8 += 2;
                offset -= 2;
                --x;
                ++param_7;
                param_3 += 4;
                --max.y;
            } while (max.y != 0);
            return;
        }
    } else if (param_5 == 3) {
        int half = param_3 / 2;
        if (half <= param_4) {
            int old_y = param_3 + param_2;
            int old_x = param_1 - param_2;
            param_8 = half + param_2;
            param_3 = param_2 - param_3;
            count = (param_4 - half) + 1;
            param_1 = old_y;
            param_2 = param_2 - half;
            param_4 = old_x;

            do {
                realMinDC.x = param_3;
                realMinDC.y = param_3 + param_4;
                this->mapBound(&realMinDC);

                realMaxF4.x = param_1;
                realMaxF4.y = param_1 + param_4;
                this->mapBound(&realMaxF4);

                min.x = param_2;
                min.y = param_2 + param_4;
                this->mapBound(&min);

                max.x = param_8;
                max.y = param_8 + param_4;
                this->mapBound(&max);

                int y = realMinDC.y;
                int x = min.x;
                if (y < min.y) {
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        ++y;
                        --x;
                    } while (y < min.y);
                }
                if (y < max.y) {
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        ++y;
                    } while (y < max.y);
                }
                if (x < realMinDC.x) {
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        ++y;
                        ++x;
                    } while (x < realMinDC.x);
                }
                if (x < max.x) {
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        ++x;
                    } while (x < max.x);
                }
                if (max.y < y) {
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        --y;
                        ++x;
                    } while (max.y < y);
                }
                if (min.y < y) {
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        --y;
                    } while (min.y < y);
                }
                if (max.x < x) {
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        --y;
                        --x;
                    } while (max.x < x);
                }
                if (min.x < x) {
                    do {
                        if (this->insideGate(param_6, x, y) == 0)
                            this->storeLot(0x48, x, y, 0);
                        --x;
                    } while (min.x < x);
                }

                --param_2;
                param_3 -= 2;
                param_1 += 2;
                ++param_8;
                --param_7;
                --count;
            } while (count != 0);
        }
    }
}

int TribeInformationAIModule::insideGate(int param_1, int param_2, int param_3) {
    int* p;
    int i;

    i = 0;
    if (param_1 > 0) {
        p = &this->minGatePosition[0].y;
        while (1) {
            if (!(((XYPoint*)(p - 1))->x > param_2 ||
                  *p > param_3 ||
                  param_2 > p[7] ||
                  param_3 > p[8])) {
                goto found;
            }
            i = i + 1;
            p = p + 2;
            if (i >= param_1) {
                return 0;
            }
        }
    } else {
        return 0;
    }

found:
    return 1;
loop_fail:
    return 0;
early_fail:
    return 0;
}

int TribeInformationAIModule::storeAttackMemory(
    unsigned char param_1, unsigned char param_2, unsigned char param_3,
    unsigned char param_4, unsigned char param_5, short param_6,
    unsigned char param_7, ulong param_8, int param_9) {
    return this->storeAttackMemory(param_1, param_2, param_3, param_2, param_3,
                                   param_4, param_5, param_6, param_7, param_8,
                                   param_9);
}

#include <stdlib.h>

int TribeInformationAIModule::storeAttackMemory(
    unsigned char param_1,
    unsigned char param_2,
    unsigned char param_3,
    unsigned char param_4,
    unsigned char param_5,
    unsigned char param_6,
    unsigned char param_7,
    short param_8,
    unsigned char param_9,
    unsigned long param_10,
    int param_11)
{
    int bestIdx;
    int count;

    if (this->mapXSizeValue > 0 && this->mapYSizeValue > 0) {
        int nMaxX = *(int*)&param_4;
        int nMinX = *(int*)&param_2;
        nMaxX &= 0xFF;
        nMinX &= 0xFF;
        int sum = nMaxX + nMinX;
        int product = sum * 4;
        int cx = product / this->mapXSizeValue;
        product = product / this->mapYSizeValue;
        cx /= 2;
        product /= 2;
        if (cx > 4) cx = 3;
        if (product > 4) product = 3;

        unsigned short playerID = this->md->player->id;
        if (param_7 == playerID) {
            this->quadrantLog[cx][product].numberAttacksOnUs += 1;
        } else if (param_6 == playerID) {
            this->quadrantLog[cx][product].numberAttacksByUs += 1;
        }
    }

    bestIdx = -1;
    count = 0;

    for (count = 0; count < this->maxAttackMemories; ++count) {
        if (this->attackMemories[count].id == -1) {
            bestIdx = count;
            break;
        }

        if (bestIdx == -1 ||
            this->attackMemories[bestIdx].timeStamp <
                this->attackMemories[count].timeStamp) {
            bestIdx = count;
        }
    }

    if (bestIdx != -1) {
        this->attackMemories[bestIdx].id = count;
        this->attackMemories[bestIdx].type = param_1;
        this->attackMemories[bestIdx].minX = param_2;
        this->attackMemories[bestIdx].minY = param_3;
        this->attackMemories[bestIdx].maxX = param_4;
        this->attackMemories[bestIdx].maxY = param_5;
        this->attackMemories[bestIdx].attackingOwner = param_6;
        this->attackMemories[bestIdx].targetOwner = param_7;
        this->attackMemories[bestIdx].kills = param_8;
        this->attackMemories[bestIdx].success = param_9;
        this->attackMemories[bestIdx].timeStamp = param_10;
        this->attackMemories[bestIdx].play = param_11;
    }

    return bestIdx;
}

void TribeInformationAIModule::removeAttackMemory(int index) {
    if (index < 0 || index >= this->maxAttackMemories) {
        return;
    }

    this->attackMemories[index].id = -1;
    this->attackMemories[index].type = 0;
    this->attackMemories[index].minX = 0;
    this->attackMemories[index].minY = 0;
    this->attackMemories[index].maxX = 0;
    this->attackMemories[index].maxY = 0;
    this->attackMemories[index].attackingOwner = -1;
    this->attackMemories[index].targetOwner = -1;
    this->attackMemories[index].kills = 0;
    this->attackMemories[index].success = 0;
    this->attackMemories[index].play = -1;
}

AttackMemory* TribeInformationAIModule::attackMemory(int index) {
    if (index >= 0 && index < this->maxAttackMemories)
        return this->attackMemories + index;
    return 0;
}

#include <stdio.h>

void TribeInformationAIModule::loadLearnInfo(char* suffix)
{
    int numMemoriesToLoad;
    int numToLoad;
    int tempInt;
    int local_2c;
    ObjectMemory temp;
    char* learnFileName = this->learnFileName;

    if (suffix == 0) {
        sprintf(learnFileName, "learn\\default.%d",
                (int)this->md->player->id);
    } else {
        sprintf(learnFileName, "learn\\%s%s.%d", suffix,
                rge_base_game->player_game_info->get_current_player_name(),
                (int)this->md->player->id);
    }

    int file = rge_open(learnFileName, 0x8000);
    if (file != -1) {
        rge_read(file, &this->mapXSizeValue, 4);
        rge_read(file, &this->mapYSizeValue, 4);
        rge_read(file, &numToLoad, 4);

        int i = 0;
        if (numToLoad > 0) {
            do {
                rge_read(file, &temp.type, 0x18);
                this->storeAttackMemory(
                    temp.x,
                    temp.y,
                    temp.z,
                    temp.owner,
                    *((unsigned char*)&temp.hitPoints),
                    *((unsigned char*)&temp.hitPoints + 1),
                    temp.kills,
                    *(short*)&temp.attackAttempts,
                    *((unsigned char*)&temp.attackAttempts + 2),
                    *(unsigned long*)&temp.range,
                    *(int*)&temp.damageCapability);
                i++;
            } while (i < numToLoad);
        }

        rge_read(file, &numToLoad, 4);
        suffix = 0;
        if (numToLoad > 0) {
            do {
                float local_4;
                rge_read(file, &temp.type, 0x24);
                this->addObjectMemory(
                    temp.id,
                    *(short*)&temp.x,
                    *(short*)&temp.z,
                    *((unsigned char*)&temp.hitPoints),
                    *((unsigned char*)&temp.hitPoints + 1),
                    temp.kills,
                    *((unsigned char*)&temp.kills + 1),
                    *(short*)&temp.attackAttempts,
                    *(int*)&temp.range,
                    *((unsigned char*)&temp.damageCapability),
                    temp.rateOfFire,
                    temp.range,
                    local_4,
                    0);
                this->importantUnits.add(temp.id);
                suffix = suffix + 1;
            } while ((int)suffix < numToLoad);
        }

        int* maxResources = this->maxResources;
        int resourceCount = 4;
        do {
            rge_read(file, maxResources, 4);
            rge_read(file, maxResources - 4, 4);
            ResourceMemory* resourceMemory =
                (ResourceMemory*)operator new((*maxResources) * sizeof(ResourceMemory));
            *(ResourceMemory**)(maxResources - 8) = resourceMemory;
            rge_read(file, resourceMemory, (*maxResources) * sizeof(ResourceMemory));
            maxResources++;
            resourceCount--;
        } while (resourceCount != 0);

        rge_read(file, &tempInt, 4);
        suffix = 0;
        if (tempInt > 0) {
            do {
                rge_read(file, &local_2c, 4);
                this->importantMiscs.add(local_2c);
                suffix = suffix + 1;
            } while ((int)suffix < tempInt);
        }

        rge_read(file, &tempInt, 4);
        suffix = 0;
        if (tempInt > 0) {
            do {
                rge_read(file, &local_2c, 4);
                this->itemsToDefend.add(local_2c);
                suffix = suffix + 1;
            } while ((int)suffix < tempInt);
        }

        rge_close(file);
    }
}

void TribeInformationAIModule::setSaveLearnInformation(int v) {
    this->saveLearnInformationValue = v;
}

int TribeInformationAIModule::unexploredPlayerLocation(int objectId, XYPoint& out)
{
    RGE_Static_Object* obj = (RGE_Static_Object*)this->md->object(objectId);
    if (objectId != 0) {
        *(uchar*)&objectId = obj->currentZone();
        int bestDistance;
        ObjectMemory* best;
        int index;
        best = 0;
        bestDistance = -1;
        index = 0;

        if (this->maxImportantObjectMemory > 0) {
            do {
                if (this->importantObjectMemory[index].id != -1) {
                    unsigned short owner =
                        this->importantObjectMemory[index].owner;
                    if (owner != this->md->player->id &&
                        this->importantObjectMemory[index].owner != 0) {
                        if (this->tileUncovered(
                                this->importantObjectMemory[index].x,
                                this->importantObjectMemory[index].y) != 1) {
                            if (obj->lookupZone(
                                    this->importantObjectMemory[index].x,
                                    this->importantObjectMemory[index].y) ==
                                (uchar)objectId) {
                                int dist = (int)obj->distance_to_position(
                                    (float)this->importantObjectMemory[index].x,
                                    (float)this->importantObjectMemory[index].y,
                                    (float)this->importantObjectMemory[index].z);
                                if (best == 0 || bestDistance > dist) {
                                    best = &this->importantObjectMemory[index];
                                    bestDistance = dist;
                                }
                            }
                        }
                    }
                }
                index++;
            } while (index < this->maxImportantObjectMemory);
        }

        if (best != 0) {
            out.x = best->x;
            out.y = best->y;

            int objZ = (int)obj->world_z;
            XYZPoint pt;
            pt.x = out.x;
            pt.y = out.y;
            pt.z = objZ;
            float pathResult;
            int ok = obj->canPath(pt, obj->master_obj->los - 1.0f,
                                  -1, &pathResult, 1, -1, -1);
            if (ok == 0) {
                this->pathMap.setValue(out.x, out.y, 1);
                return 0;
            }
            this->pathMap.setValue(out.x, out.y, 0);
            return 1;
        }
    }
    return 0;
}

#include <stdlib.h>

int TribeInformationAIModule::numberUnitsWithinXTiles(int playerFilter, int xCenter, int yCenter, int radius)
{
    int radiusSquared = radius * radius;
    int resultCount = 0;
    int i = 0;

    if (this->maxImportantObjectMemory > 0) {
        do {
            if ((playerFilter == -1 ||
                 (int)this->importantObjectMemory[i].owner == playerFilter) &&
                (playerFilter != -1 ||
                 this->md->player->isEnemy(this->importantObjectMemory[i].owner) != 0)) {
                int dx = (int)this->importantObjectMemory[i].x - xCenter;
                int dy = (int)this->importantObjectMemory[i].y - yCenter;
                if (dx * dx + dy * dy <= radiusSquared) {
                    resultCount++;
                }
            }
            i++;
        } while (i < this->maxImportantObjectMemory);
    }

    return resultCount;
}

int TribeInformationAIModule::withinXTilesOfAttackOnPlayer(
    RGE_Static_Object* target, int tiles, int playerId)
{
    int tilesSq = tiles * tiles;
    int tx = (int)target->world_x;
    int ty = (int)target->world_y;

    for (int i = 0; i < this->maxAttackMemories; i++) {
        AttackMemory* am = &attackMemories[i];
        if (am->id == -1 || !am->attackingOwner || (unsigned char)am->targetOwner != playerId)
            continue;

        int dxSquared = (unsigned char)am->minX - tx;
        dxSquared *= dxSquared;
        int dySquared = ((unsigned char)am->minY - ty) *
                        ((unsigned char)am->minY - ty);
        if (dySquared + dxSquared <= tilesSq) return 1;
        int dy = (unsigned char)am->minY - ty;

        dySquared = (unsigned char)am->maxY - ty;
        dySquared *= dySquared;
        if (dySquared + dxSquared <= tilesSq) return 1;

        dxSquared = (unsigned char)am->maxX - tx;
        dxSquared *= dxSquared;
        if (dySquared + dxSquared <= tilesSq) return 1;

        if (dy * dy + dxSquared <= tilesSq) return 1;
    }

    return 0;
}

int TribeInformationAIModule::withinXTilesOfEnemyTowncenter(
    RGE_Static_Object* obj, int tiles)
{
    int dsq = tiles * tiles;
    int ox = (int)obj->world_x;
    int oy = (int)obj->world_y;

    for (int i = 0; i < this->maxImportantObjectMemory; i++)
    {
        if (this->importantObjectMemory[i].type != 109)
            continue;
        if (!this->md->player->isEnemy(this->importantObjectMemory[i].owner))
            continue;
        int dx = (unsigned char)this->importantObjectMemory[i].x - ox;
        int dy = (unsigned char)this->importantObjectMemory[i].y - oy;
        if (dx * dx + dy * dy <= dsq)
            return 1;
    }
    return 0;
}

int TribeInformationAIModule::withinXTilesOfObject(
    RGE_Static_Object* obj, int tile_range,
    int type1, int type2, int type3, int type4)
{
    int tile_range_sq = tile_range * tile_range;
    int obj_x = (int)obj->world_x;
    int obj_y = (int)obj->world_y;
    int closest_id = -1;
    int closest_dist = -1;
    int i = 0;

    if (this->maxImportantObjectMemory > 0) {
        do {
            RGE_Static_Object* target = this->md->object(
                this->importantObjectMemory[i].id);

            if (target != 0 && target->object_state <= 2 && target->hp != 0.0f) {
                int type = (int)this->importantObjectMemory[i].type;
                if ((type == type1 || type == type2 ||
                     type == type3 || type == type4) &&
                    this->md->player->isEnemy(
                        this->importantObjectMemory[i].owner) != 0) {
                    int dx = (unsigned char)this->importantObjectMemory[i].x - obj_x;
                    int dy = (unsigned char)this->importantObjectMemory[i].y - obj_y;
                    int dist = dx * dx + dy * dy;

                    if (dist <= tile_range_sq &&
                        (dist < closest_dist || closest_id == -1)) {
                        closest_dist = dist;
                        closest_id = this->importantObjectMemory[i].id;
                    }
                }
            }

            i++;
        } while (i < this->maxImportantObjectMemory);
    }

    return closest_id;
}

int TribeInformationAIModule::findStagingPoint(XYPoint startPoint, XYPoint& rPoint,
                                               int useTransport,
                                               int landTerrainRequired,
                                               int targetID, int stageDistance,
                                               int unitID)
{
    ObjectMemory* target;
    RGE_Static_Object* unit;
    target = this->objectMemory(targetID);
    if (!target) return 0;
    unit = this->md->object(unitID);
    if (!unit) return 0;

    int terrainType, terrain;
    if (this->isBoat(unit) == 1 && useTransport == 0) { terrainType = 1; terrain = 0x16; }
    else { terrainType = 2; terrain = 0; }

    XYPoint zoneRefPoint;
    zoneRefPoint.x = startPoint.x; zoneRefPoint.y = startPoint.y;
    unit->findClosestPointInTerrainType(startPoint, zoneRefPoint, terrainType,
                                        terrain, 4);
    unsigned char targetZone = unit->lookupZone(zoneRefPoint.x, zoneRefPoint.y);

    int maxLOSValue = this->setupLOSMap(target->owner, target->x, target->y);
    int maxAttackValue = this->setupAttackMap(target->owner, target->x, target->y);
    XYPoint min, max, targetPoint;
    min.x = (int)target->x - stageDistance; min.y = (int)target->y - stageDistance; this->mapBound(&min);
    max.x = (int)target->x + stageDistance; max.y = (int)target->y + stageDistance; this->mapBound(&max);
    targetPoint.x = target->x; targetPoint.y = target->y; this->mapBound(&targetPoint);

    RGE_Visible_Map* vMap = this->md->player->visible;
    RGE_Map* gMap = this->md->aiPlayer->world->map;
    int bestValue = -1;

    for (int x = min.x; x <= max.x; ++x) {
        for (int y = min.y; y <= max.y; ++y) {
            unsigned char tile = (unsigned char)(gMap->map_row_offset[y][x].height & 0x1f);
            vMap->get_visible(x, y);
            if (useTransport == 1) {
                if (tile != 2) continue;
            } else if (landTerrainRequired == 1) {
                if (tile == 1 || tile == 0x16) continue;
            } else if (landTerrainRequired == 0 && tile != 1 && tile != 0x16) {
                continue;
            }
            if (unit->lookupZone(x, y) != targetZone) continue;
            if (useTransport == 1) {
                XYPoint passableMin;
                XYPoint passableMax;
                passableMin.x = x - 2; passableMin.y = y - 2; this->mapBound(&passableMin);
                passableMax.x = x + 2; passableMax.y = y + 2; this->mapBound(&passableMax);
                int good = 1;
                for (int a = passableMin.x; a <= passableMax.x && good; ++a) {
                    for (int b = passableMin.y; b <= passableMax.y && good; ++b) {
                        unsigned char t = (unsigned char)(gMap->map_row_offset[b][a].height & 0x1f);
                        if (t != 1 && t != 0x16 && unit->passableTile((float)a, (float)b, 1) == 0) good = 0;
                    }
                }
                if (!good) continue;
            }
            int dx = target->x - x;
            int dy = target->y - y;
            int d2 = dx * dx + dy * dy;
            int dist = (int)sqrt((double)d2);
            int randomization = debug_rand("C:\\msdev\\work\\age1_x1\\taiinfmd.cpp", 0x1b3f) % (stageDistance * 3);
            XYPoint temp;
            XYPoint temp2;
            temp.x = x; temp.y = y;
            // A successful line path adds stageDistance to the score.
            int pathPenalty = unit->canLinePath(temp, targetPoint, 1.0f, temp2, 1) == 1 ? stageDistance : 0;
            int losPenalty;
            int attackPenalty;
            if (maxLOSValue > 0)
                losPenalty = -(losMap.lookupValue(x, y) * stageDistance / maxLOSValue);
            else
                losPenalty = 0;
            if (maxAttackValue > 0)
                attackPenalty = -(attackMap.lookupValue(x, y) * stageDistance / maxAttackValue);
            else
                attackPenalty = 0;
            int v = attackPenalty + losPenalty + pathPenalty + randomization + dist;
            if (bestValue == -1 || bestValue < v) { bestValue = v; rPoint.x = x; rPoint.y = y; }
        }
    }
    return bestValue != -1;
}

int TribeInformationAIModule::setupLOSMap(int owner, int refX, int refY)
{
    losMap.initialize(0);
    losMap.setReferencePoint(refX, refY);

    int i = 0;
    if (this->maxImportantObjectMemory > 0) {
        do {
            if ((unsigned int)this->importantObjectMemory[i].owner ==
                (unsigned int)owner) {
                RGE_Static_Object* obj = this->md->object(
                    this->importantObjectMemory[i].id);
                if (obj != 0) {
                    int range = (int)obj->master_obj->los;
                    int minX = (int)obj->world_x - range;
                    int maxX = range + (int)obj->world_x;
                    int minY = (int)obj->world_y - range;
                    int maxY = range + (int)obj->world_y;
                    int flag;
                    if (obj->damageCapability() > 0.0f) {
                        flag = 5;
                    } else {
                        flag = 1;
                    }
                    losMap.incrementValue(minX, minY, maxX, maxY, flag);
                }
            }
            i++;
        } while (i < this->maxImportantObjectMemory);
    }
    return losMap.maxValue();
}

int TribeInformationAIModule::setupAttackMap(int param_1, int param_2, int param_3)
{
    attackMap.initialize(0);
    attackMap.setReferencePoint(param_2, param_3);

    int i = 0;
    if (this->maxAttackMemories > 0) {
        int offset = 0;
        do {
            if ((unsigned char)((char*)this->attackMemories)[offset + 0x0A] == (unsigned int)param_1) {
                unsigned short owner = (unsigned char)((char*)this->attackMemories)[offset + 0x09];
                if (owner == (unsigned short)this->md->player->id) {
                    attackMap.incrementValue(
                        (unsigned char)((char*)this->attackMemories)[offset + 0x05],
                        (unsigned char)((char*)this->attackMemories)[offset + 0x06],
                        (unsigned char)((char*)this->attackMemories)[offset + 0x07],
                        (unsigned char)((char*)this->attackMemories)[offset + 0x08],
                        1);
                }
            }
            i++;
            offset += 0x18;
        } while (i < this->maxAttackMemories);
    }

    return attackMap.maxValue();
}

#include <stdlib.h>

void TribeInformationAIModule::addResourceType(int resource_idx, int type_value)
{
    int* new_types = (int*)operator new(
        this->numberResourceTypesValue[resource_idx] * 4 + 4);

    int count = 0;
    if (this->numberResourceTypesValue[resource_idx] > 0) {
        do {
            new_types[count] = this->resourceTypesValue[resource_idx][count];
            count++;
        } while (count < this->numberResourceTypesValue[resource_idx]);
    }

    new_types[count] = type_value;

    if (this->resourceTypesValue[resource_idx]) {
        operator delete(this->resourceTypesValue[resource_idx]);
    }

    this->resourceTypesValue[resource_idx] = new_types;
    this->numberResourceTypesValue[resource_idx]++;
}

int TribeInformationAIModule::resourceType(int resourceTypeIndex, int resourceId) {
    for (int i = 0; i < this->numberResourceTypesValue[resourceTypeIndex]; i++) {
        if (this->resourceTypesValue[resourceTypeIndex][i] == resourceId) {
            return 1;
        }
    }
    return 0;
}

int TribeInformationAIModule::addResourceObject(RGE_Static_Object* obj)
{
    short group = obj->master_obj->object_group;
    int resourceType;

    if (group == 0x0f) {
        resourceType = 1;
    } else if (group == 8) {
        resourceType = 2;
    } else {
        resourceType = (group != 0x20) - 1 & 3;
    }

    if (this->numResources[resourceType] == this->maxResources[resourceType] ||
        this->resources[resourceType] == 0) {
        int newSize;
        if (this->maxResources[resourceType] == 0) {
            newSize = 100;
        } else {
            newSize = this->maxResources[resourceType] * 2;
        }

        ResourceMemory* temp = (ResourceMemory*)operator new(newSize * sizeof(ResourceMemory));
        if (temp == 0) {
            return 0;
        }

        int i = 0;
        if (this->resources[resourceType] != 0) {
            ResourceMemory* destination = temp;
            while (this->resources[resourceType] != 0) {
                if (i >= this->maxResources[resourceType]) {
                    break;
                }
                destination->id = this->resources[resourceType][i].id;
                destination->x = this->resources[resourceType][i].x;
                destination->y = this->resources[resourceType][i].y;
                destination->gatherAttempts = this->resources[resourceType][i].gatherAttempts;
                destination->gatherValue = this->resources[resourceType][i].gatherValue;
                destination->valid = this->resources[resourceType][i].valid;
                destination->gone = this->resources[resourceType][i].gone;
                destination->dropDistance = this->resources[resourceType][i].dropDistance;
                destination->resourceType = this->resources[resourceType][i].resourceType;
                destination->dropsiteID = this->resources[resourceType][i].dropsiteID;
                i++;
                destination++;
            }
        }

        if (i < newSize) {
            int count = newSize - i;
            do {
                temp[i].id = -1;
                temp[i].x = 0;
                temp[i].y = 0;
                temp[i].gatherAttempts = 0;
                temp[i].gatherValue = 0xff;
                temp[i].valid = 0;
                temp[i].gone = 0;
                temp[i].dropDistance = 0xff;
                temp[i].resourceType = 0xff;
                temp[i].dropsiteID = -1;
                i++;
                count--;
            } while (count != 0);
        }

        if (this->resources[resourceType] != 0) {
            operator delete(this->resources[resourceType]);
        }
        this->resources[resourceType] = temp;
        this->maxResources[resourceType] = newSize;
    }

    int i = 0;
    while (i < this->maxResources[resourceType]) {
        if (this->resources[resourceType][i].id == obj->id) {
                int dropsiteID = -1;
                float distance = this->findClosestDropsite(obj, 1, &dropsiteID);
                this->resources[resourceType][i].gatherValue =
                    (int)(DAT_005755bc - distance * DAT_005755b8);
                this->resources[resourceType][i].dropsiteID = dropsiteID;

                int objectGroup = obj->master_obj->object_group;
                if (objectGroup == 0x0f) {
                    int value = (int)distance;
                    if (value >= this->closestDropsiteValue[1] &&
                        this->closestDropsiteValue[1] != -1) {
                        return 1;
                    }
                    this->closestDropsiteValue[1] = value;
                    this->closestDropsiteResourceID[1] = this->resources[resourceType][i].id;
                    return 1;
                }
                if (objectGroup == 0x20) {
                    int value = (int)distance;
                    if (value >= this->closestDropsiteValue[3] &&
                        this->closestDropsiteValue[3] != -1) {
                        return 1;
                    }
                    this->closestDropsiteValue[3] = value;
                    this->closestDropsiteResourceID[3] = this->resources[resourceType][i].id;
                    return 1;
                }
                if (objectGroup == 8) {
                    int value = (int)distance;
                    if (value >= this->closestDropsiteValue[2] &&
                        this->closestDropsiteValue[2] != -1) {
                        return 1;
                    }
                    this->closestDropsiteValue[2] = value;
                    this->closestDropsiteResourceID[2] = this->resources[resourceType][i].id;
                    return 1;
                }
                if (objectGroup == 7) {
                    int value = (int)distance;
                    if (value >= this->closestDropsiteValue[0] &&
                        this->closestDropsiteValue[0] != -1) {
                        return 1;
                    }
                    this->closestDropsiteValue[0] = value;
                    this->closestDropsiteResourceID[0] = this->resources[resourceType][i].id;
                    return 1;
                }
                return 1;
            }
        i++;
    }

    this->resources[resourceType][this->numResources[resourceType]].id = obj->id;
    this->resources[resourceType][this->numResources[resourceType]].x =
        (unsigned char)(int)obj->world_x;
    this->resources[resourceType][this->numResources[resourceType]].y =
        (unsigned char)(int)obj->world_y;
    this->resources[resourceType][this->numResources[resourceType]].gatherAttempts = 0;
    this->resources[resourceType][this->numResources[resourceType]].valid = 0;
    this->resources[resourceType][this->numResources[resourceType]].gone = 0;
    this->resources[resourceType][this->numResources[resourceType]].resourceType =
        (unsigned char)resourceType;

    int dropsiteID = -1;
    float distance = this->findClosestDropsite(obj, 1, &dropsiteID);
    this->resources[resourceType][this->numResources[resourceType]].dropDistance =
        (unsigned char)distance;
    this->resources[resourceType][this->numResources[resourceType]].dropsiteID = dropsiteID;
    this->resources[resourceType][this->numResources[resourceType]].gatherValue =
        (int)(10.0f - distance * -2.0f);
    this->numResources[resourceType]++;

    int objectGroup = obj->master_obj->object_group;
    if (objectGroup == 0x0f) {
        int value = (int)distance;
        if (value < this->closestDropsiteValue[1] ||
            this->closestDropsiteValue[1] == -1) {
            this->closestDropsiteValue[1] = value;
            this->closestDropsiteResourceID[1] = obj->id;
            return 1;
        }
    } else if (objectGroup == 0x20) {
        int value = (int)distance;
        if (value < this->closestDropsiteValue[3] ||
            this->closestDropsiteValue[3] == -1) {
            this->closestDropsiteValue[3] = value;
            this->closestDropsiteResourceID[3] = obj->id;
            return 1;
        }
    } else if (objectGroup == 8) {
        int value = (int)distance;
        if (value < this->closestDropsiteValue[2] ||
            this->closestDropsiteValue[2] == -1) {
            this->closestDropsiteValue[2] = value;
            this->closestDropsiteResourceID[2] = obj->id;
            return 1;
        }
    } else if (objectGroup == 7) {
        int value = (int)distance;
        if (value < this->closestDropsiteValue[0] ||
            this->closestDropsiteValue[0] == -1) {
            this->closestDropsiteValue[0] = value;
            this->closestDropsiteResourceID[0] = obj->id;
            return 1;
        }
    }
    return 1;
}

float TribeInformationAIModule::findClosestDropsite(RGE_Static_Object* obj, int mode, int& dropsiteID)
{
    float best;
    unsigned char resourceZone;
    int i;
    RGE_Static_Object* dropsite;

    best = 1000.0f;
    resourceZone = obj->currentZone();
    dropsiteID = -1;

    i = 0;
    if (this->playerBuildings.numberValue > 0) {
        do {
            dropsite = this->md->object(this->playerBuildings[i]);
            if (dropsite != 0) {
                if (obj->lookupZone((int)dropsite->world_x, (int)dropsite->world_y) == resourceZone) {
                    int group = dropsite->master_obj->id;
                    if ((group == 0x6D && mode != 0) ||
                        (group == 0x67 && obj->master_obj->id != 0x3B && obj->master_obj->id != 0x32) ||
                        (group == 0x44 && (obj->master_obj->id == 0x3B || obj->master_obj->id == 0x32))) {
                        float dx = dropsite->world_x - obj->world_x;
                        float dy = dropsite->world_y - obj->world_y;
                        float dist = (float)sqrt(dx * dx + dy * dy);
                        if (best == DAT_00575588 || dist < best) {
                            dropsiteID = dropsite->id;
                            best = dist;
                        }
                    }
                }
            }

            i++;
        } while (i < this->playerBuildings.numberValue);
    }

    return best;
}

#include <stddef.h>
#include <math.h>

RGE_Static_Object* TribeInformationAIModule::findClosestReturnDropsite(RGE_Static_Object* unit)
{
    RGE_Static_Object* result = 0;
    float best = 1000.0f;
    unsigned char unitZone = unit->currentZone();
    int i = 0;

    if (this->playerBuildings.numberValue > 0) {
        do {
            RGE_Static_Object* obj = this->md->object(this->playerBuildings[i]);
            if (obj != 0) {
                if (unit->lookupZone((int)obj->world_x, (int)obj->world_y) == unitZone) {
                    int id = obj->master_obj->id;
                    if (id == 0x6D ||
                        (id == 0x67 && unit->attribute_type_held != 0x10) ||
                        (id == 0x44 && unit->attribute_type_held == 0x10)) {
                        float xDiff = obj->world_x - unit->world_x;
                        float yDiff = obj->world_y - unit->world_y;
                        float dist = (float)sqrt(xDiff * xDiff + yDiff * yDiff);
                        if (result == 0 || dist < best) {
                            best = dist;
                            result = obj;
                        }
                    }
                }
            }

            i++;
        } while (i < this->playerBuildings.numberValue);
    }

    return result;
}

void TribeInformationAIModule::updateAllResourceDropsites()
{
    for (int resourceType = 0; resourceType < 4; ++resourceType) {
        ResourceMemory* resources = this->resources[resourceType];
        int count = this->numResources[resourceType];
        int i = 0;
        if (resources != 0 && count > 0) {
            do {
                RGE_Static_Object* obj =
                    this->md->object(resources[i].id);
                if (obj) {
                    int dropsiteID = -1;
                    float dist = this->findClosestDropsite(obj, 1, &dropsiteID);
                    resources[i].gatherValue =
                        (int)(DAT_005755bc - dist * DAT_005755b8);
                    resources[i].dropDistance = (unsigned char)(int)dist;
                    resources[i].dropsiteID = dropsiteID;

                    int grp = obj->master_obj->object_group;
                    if (grp == 0x0F) {
                        if ((int)dist < this->closestDropsiteValue[1] || this->closestDropsiteValue[1] == -1) {
                            this->closestDropsiteValue[1] = (int)dist;
                            this->closestDropsiteResourceID[1] = obj->id;
                        }
                    } else if (grp == 0x20) {
                        if ((int)dist < this->closestDropsiteValue[3] || this->closestDropsiteValue[3] == -1) {
                            this->closestDropsiteValue[3] = (int)dist;
                            this->closestDropsiteResourceID[3] = obj->id;
                        }
                    } else if (grp == 0x08) {
                        if ((int)dist < this->closestDropsiteValue[2] || this->closestDropsiteValue[2] == -1) {
                            this->closestDropsiteValue[2] = (int)dist;
                            this->closestDropsiteResourceID[2] = obj->id;
                        }
                    } else if (grp == 0x07) {
                        if ((int)dist < this->closestDropsiteValue[0] || this->closestDropsiteValue[0] == -1) {
                            this->closestDropsiteValue[0] = (int)dist;
                            this->closestDropsiteResourceID[0] = obj->id;
                        }
                    }
                }
                i++;
            } while (i < count);
        }
    }
}

void TribeInformationAIModule::updateResourceDropsites(int idx) {
    this->closestDropsiteValue[idx] = -1;
    this->closestDropsiteResourceID[idx] = -1;

    int i = 0;
    int byte_off = 0;

    if (this->numResources[idx] > 0) {
        do {
            if (*(unsigned char*)((char*)this->resources[idx] + byte_off + 0x0D) != 1) {
                int obj_id = *(int*)((char*)this->resources[idx] + byte_off);
                RGE_Static_Object* obj = this->md->object(obj_id);

                if (obj != 0) {
                    int out_id = -1;
                    float dist = this->findClosestDropsite(obj, 1, &out_id);

                    int val = (int)(DAT_005755bc - DAT_005755b8 * dist);
                    *(int*)((char*)this->resources[idx] + byte_off + 8) = val;
                    *(unsigned char*)((char*)this->resources[idx] + byte_off + 0x0E) =
                        (unsigned char)(int)dist;
                    *(int*)((char*)this->resources[idx] + byte_off + 0x10) = out_id;

                    int grp = obj->master_obj->object_group;

                    if (grp == 0x0F) {
                        int v = (int)dist;
                        if (v < this->closestDropsiteValue[1] ||
                            this->closestDropsiteValue[1] == -1) {
                            this->closestDropsiteValue[1] = v;
                            this->closestDropsiteResourceID[1] = obj->id;
                        }
                    } else if (grp == 0x20) {
                        int v = (int)dist;
                        if (v < this->closestDropsiteValue[3] ||
                            this->closestDropsiteValue[3] == -1) {
                            this->closestDropsiteValue[3] = v;
                            this->closestDropsiteResourceID[3] = obj->id;
                        }
                    } else if (grp == 8) {
                        int v = (int)dist;
                        if (v < this->closestDropsiteValue[2] ||
                            this->closestDropsiteValue[2] == -1) {
                            this->closestDropsiteValue[2] = v;
                            this->closestDropsiteResourceID[2] = obj->id;
                        }
                    } else if (grp == 7) {
                        int v = (int)dist;
                        if (v < this->closestDropsiteValue[0] ||
                            this->closestDropsiteValue[0] == -1) {
                            this->closestDropsiteValue[0] = v;
                            this->closestDropsiteResourceID[0] = obj->id;
                        }
                    }
                }
            }

            i++;
            byte_off += 0x14;
        } while (i < this->numResources[idx]);
    }
}

int TribeInformationAIModule::setResourceObjectValid(int resourceType, int resourceId, int valid) {
    for (int i = 0; i < this->numResources[resourceType]; i++) {
        if (this->resources[resourceType][i].id == resourceId) {
            this->resources[resourceType][i].valid = (unsigned char)valid;
            return 1;
        }
    }
    return 0;
}

#include <stddef.h>

int TribeInformationAIModule::numberStoragePits() {
    int i = 0;
    int result = 0;

    if (playerBuildings.numberValue > 0) {
        do {
            RGE_Static_Object* obj = md->object(playerBuildings[i]);
            if (obj != 0 && obj->master_obj->id == 0x67) {
                result++;
            }

            i++;
        } while (i < playerBuildings.numberValue);
    }

    return result;
}

#include <stddef.h>

int TribeInformationAIModule::numberGranaries() {
    int i = 0;
    int result = 0;

    if (playerBuildings.numberValue > 0) {
        do {
            RGE_Static_Object* obj = md->object(playerBuildings[i]);
            if (obj != 0 && obj->master_obj->id == 0x44) {
                result++;
            }

            i++;
        } while (i < playerBuildings.numberValue);
    }

    return result;
}

#include <math.h>

int TribeInformationAIModule::amountForageBushesInXTiles(int x, int y, int max_distance)
{
    float total = 0.0f;
    int i = 0;
    if (this->numResources[0] > 0) {
        do {
            if (this->resources[0][i].gone != 1) {
                RGE_Static_Object* obj = this->md->object(this->resources[0][i].id);
                if (obj != 0 && obj->master_obj->id == 0x3B) {
                    float dx = obj->world_x - (float)x; float dy = obj->world_y - (float)y;
                    if ((int)(sqrt(dx * dx + dy * dy)) <= max_distance)
                        total += obj->attribute_amount_held;
                }
            }
            i++;
        } while (i < this->numResources[0]);
    }
    return (int)total;
}

#include <math.h>

int TribeInformationAIModule::amountResourceTypesInXTiles(int type_index, int x, int y, int distance)
{
    float total = 0.0f;
    int i = 0;

    if (this->numResources[type_index] > 0) {
        do {
            if (this->resources[type_index][i].gone != 1) {
                RGE_Static_Object* obj = this->md->object(
                    this->resources[type_index][i].id);
                if (obj != 0 && (type_index != 0 || obj->master_obj->id != 0x3B)) {
                    float dx = obj->world_x - (float)x;
                    float dy = obj->world_y - (float)y;
                    if ((int)(sqrt(dx * dx + dy * dy)) <= distance) {
                        total += obj->attribute_amount_held;
                    }
                }
            }
            i++;
        } while (i < this->numResources[type_index]);
    }

    return (int)total;
}

float TribeInformationAIModule::damagePerSecond(int param_1, int param_2, int param_3) {
    float rateOfFire = 0.0f;

    RGE_Static_Object* target = (RGE_Static_Object*)md->object(param_1);
    if (target == 0) {
        return 0.0f;
    }

    int i = 0;
    if (maxImportantObjectMemory > 0) {
        int base = 0;
        do {
            unsigned char owner = *(unsigned char*)(importantObjectMemory + base + 0x0B);
            if (md->player->isEnemy(owner)) {
                int id = *(int*)(importantObjectMemory + base);
                RGE_Static_Object* unit = (RGE_Static_Object*)md->object(id);
                if (unit != 0 && unit->object_state <= 2) {
                    float dist = unit->distance_to_position(
                        (float)param_2, (float)param_3, *(float*)&unit->world_z);
                    if (dist <= unit->master_obj->los) {
                        float rVal = target->damageCapability(unit);
                        float rateTmp = unit->rateOfFire();
                        if (rateTmp != 0.0f && rVal != 0.0f) {
                            rateOfFire = rVal / rateTmp + rateOfFire;
                        }
                    }
                }
            }
            i++;
            base += 0x24;
        } while (i < maxImportantObjectMemory);
    }

    return rateOfFire;
}

int TribeInformationAIModule::costToLoseUnit(int param_1) {
    RGE_Static_Object* object = md->object(param_1);
    if (object == 0) {
        return -1;
    }
    return this->md->player->objectCostByType(object->master_obj->id);
}

int TribeInformationAIModule::benefitToKillUnit(int unitId) {
    RGE_Static_Object* object = this->md->object(unitId);
    if (object == 0)
        return -1;
    return object->owner->objectCostByType(object->master_obj->id);
}

int TribeInformationAIModule::inRangeOfUnits(
    int playerFilter, int x, int y, int mapRange)
{
    int i = 0;

    if (this->maxImportantObjectMemory > 0) {
        while (true) {
            if ((playerFilter == -1 ||
                 (int)this->importantObjectMemory[i].owner == playerFilter) &&
                (playerFilter != -1 ||
                 this->md->player->isEnemy(
                     this->importantObjectMemory[i].owner) != 0)) {
                RGE_Static_Object* object = this->md->object(
                    this->importantObjectMemory[i].id);
                if (object != 0 && object->object_state <= 2) {
                    float distance = object->distance_to_position(
                        (float)x, (float)y, object->world_z);
                    float range = object->weaponRange();
                    if (mapRange == 0 && object->master_obj->los > distance) {
                        range = object->master_obj->los;
                    }
                    if (distance <= range) {
                        goto found;
                    }
                }
            }

            i++;
            if (i < this->maxImportantObjectMemory)
                continue;
            return 0;
        }

found:
        return 1;
    }

    return 0;
}

#include <stdlib.h>
#include <string.h>

ObjectMemory* TribeInformationAIModule::wonderToAttack(int player_id)
{
    ObjectMemory* bestObject;
    int bestState;
    float bestTimer;
    float bestHitpoints;
    int i;

    bestObject = 0;
    bestState = -1;
    bestTimer = 0.0f;
    bestHitpoints = 0.0f;
    i = 0;
    if (this->maxImportantObjectMemory > 0) {
        do {
            if (this->importantObjectMemory[i].type == 0x114) {
                if (player_id == -1 || this->importantObjectMemory[i].owner == player_id) {
                    if (player_id != -1 || this->md->player->isEnemy(this->importantObjectMemory[i].owner)) {
                        RGE_Static_Object* obj = this->md->object(this->importantObjectMemory[i].id);
                        if (obj != 0) {
                            if (obj->object_state <= 2) {
                                RGE_Action_Object* actionObject =
                                    static_cast<RGE_Action_Object*>(obj);
                                if (actionObject->actions->have_action()) {
                                    if (actionObject->actions->get_action()->action_type == 0x78) {
                                        int state = actionObject->actions->get_action()->state;
                                        float timer = actionObject->actions->get_action()->timer;
                                        float hp = obj->hp;
                                        if (bestObject == 0) {
                                            bestObject = &this->importantObjectMemory[i];
                                            bestState = state;
                                            bestTimer = timer;
                                            bestHitpoints = hp;
                                        } else if (bestState == 6 && state == 2) {
                                        } else if (bestState == 2 && state == 6) {
                                            bestObject = &this->importantObjectMemory[i];
                                            bestState = state;
                                            bestTimer = timer;
                                            bestHitpoints = hp;
                                        } else if (bestState == state && bestState == 2 && bestHitpoints < hp) {
                                            bestObject = &this->importantObjectMemory[i];
                                            bestState = state;
                                            bestTimer = timer;
                                            bestHitpoints = hp;
                                        // TEST AH,41h followed by JNE rejects unordered values.
                                        } else if (bestState == state && bestState == 6 && bestTimer > timer) {
                                            bestObject = &this->importantObjectMemory[i];
                                            bestState = state;
                                            bestTimer = timer;
                                            bestHitpoints = hp;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            i++;
        } while (i < this->maxImportantObjectMemory);
    }
    return bestObject;
}

#include <stdlib.h>

ObjectMemory* TribeInformationAIModule::ruinToCapture(int playerFilter)
{
    RGE_Static_Object* townCenter;
    int bestResult;
    int i;
    ObjectMemory* bestMemory;

    townCenter = this->md->object(
        -1, 0x6D, -1, -1, -1, -1, -1, -1, -1, -1);
    bestMemory = 0;
    bestResult = -1;
    i = 0;

    if (this->maxImportantObjectMemory > 0) {
        do {
            if (this->importantObjectMemory[i].type == 0x9E ||
                this->importantObjectMemory[i].type == 0xA3) {
                if ((playerFilter == -1 ||
                     (unsigned int)this->importantObjectMemory[i].owner ==
                         (unsigned int)playerFilter) &&
                    (playerFilter != -1 ||
                     this->md->player->isEnemy(
                         this->importantObjectMemory[i].owner) != 0)) {
                    RGE_Static_Object* object = this->md->object(
                        this->importantObjectMemory[i].id);

                    if (object != 0 && object->object_state <= 2) {
                        int result = this->numberUnitsWithinXTiles(
                            playerFilter,
                            this->importantObjectMemory[i].x,
                            this->importantObjectMemory[i].y, 5);

                        if (townCenter != 0) {
                            int distance = (int)townCenter->distance_to_position(
                                (float)this->importantObjectMemory[i].x,
                                (float)this->importantObjectMemory[i].y,
                                (float)this->importantObjectMemory[i].z);
                            result = distance * result;
                        }

                        if (bestMemory == 0 || result < bestResult) {
                            bestResult = result;
                            bestMemory = &this->importantObjectMemory[i];
                        }
                    }
                }
            }

            i++;
        } while (i < this->maxImportantObjectMemory);
    }

    return bestMemory;
}

ObjectMemory* TribeInformationAIModule::artifactToCapture(int player)
{
    RGE_Static_Object* townCenter;
    ObjectMemory* bestMemory;
    int bestResult;
    int i;
    RGE_Visible_Map* visibleMap;

    townCenter = this->md->object(
        -1, 0x6D, -1, -1, -1, -1, -1, -1, -1, -1);
    bestMemory = 0;
    bestResult = -1;
    i = 0;
    visibleMap = this->md->player->visible;

    if (this->maxImportantObjectMemory > 0) {
        do {
            if (this->importantObjectMemory[i].type == 0x9F) {
                if (player == -1 ||
                    (int)this->importantObjectMemory[i].owner == player) {
                    if (player != -1 ||
                        (this->md->player->mutualVisibleMask &
                         (1UL << this->importantObjectMemory[i].owner)) != 0) {
                        RGE_Static_Object* artifact = this->md->object(
                            this->importantObjectMemory[i].id);
                        if (artifact != 0 && artifact->object_state <= 2) {
                            int artifactX = (int)artifact->world_x;
                            int artifactY = (int)artifact->world_y;
                            if (visibleMap->get_visible(artifactX, artifactY) != 0) {
                                this->importantObjectMemory[i].x =
                                    (unsigned char)(int)artifact->world_x;
                                this->importantObjectMemory[i].y =
                                    (unsigned char)(int)artifact->world_y;
                                this->importantObjectMemory[i].z =
                                    (unsigned char)(int)artifact->world_z;
                                int result = this->numberUnitsWithinXTiles(
                                    player, artifactX, artifactY, 5);
                                if (townCenter != 0) {
                                    int distance = (int)townCenter->distance_to_object(
                                        artifact);
                                    result = distance * result;
                                }
                                if (bestMemory == 0 || result < bestResult) {
                                    bestResult = result;
                                    bestMemory =
                                        &this->importantObjectMemory[i];
                                }
                            }
                        }
                    }
                }
            }
            i++;
        } while (i < this->maxImportantObjectMemory);
    }
    return bestMemory;
}

int TribeInformationAIModule::resourceTypeToPlaceDropsiteBy(int param_1) {
    if (param_1 == 2) return 0;

    if (!md->buildAI.numberBuiltOrInProgressItemsOfType(0x67, 0)
        && closestDropsiteValue[1] != -1)
        return 1;

    if (param_1 == 1) {
        if (closestDropsiteValue[1] != -1) {
            int n = md->tacticalAI.strategicNumber(0xA4);
            if (closestDropsiteValue[1] > n)
                return 1;
        }
        if (closestDropsiteValue[3] != -1) {
            int n = md->tacticalAI.strategicNumber(0xA6);
            if (closestDropsiteValue[3] > n)
                return 3;
        }
        if (closestDropsiteValue[0] != -1 && closestDropsiteValue[0] > 15) return 2;
        if (closestDropsiteValue[2] != -1) {
            int n = md->tacticalAI.strategicNumber(0xA5);
            if (closestDropsiteValue[2] > n)
                return 2;
        }
        return -1;
    }
    return -1;
}

int TribeInformationAIModule::dropsitesWithinRequiredDistance(
    int& numApplicableResources, int resourceType, int requiredDistance)
{
    int totalApplicable;
    int index;

    numApplicableResources = 0;
    totalApplicable = 0;
    ManagedArray_int dropsites;
    index = 0;

    if (this->numResources[resourceType] > 0) {
        do {
            if (this->resources[resourceType][index].gone != 1) {
                if (this->md->object(this->resources[resourceType][index].id) != 0) {
                    ++totalApplicable;
                    if ((int)this->resources[resourceType][index].dropDistance <= requiredDistance) {
                        if (dropsites.contains(this->resources[resourceType][index].dropsiteID) == 0) {
                            ++numApplicableResources;
                            int dropsiteID = this->resources[resourceType][index].dropsiteID;
                            dropsites.add(dropsiteID);
                        }
                    }
                }
            }

            ++index;
        } while (index < this->numResources[resourceType]);
    }

    if (totalApplicable > 0) {
        return 1;
    } else {
        return 0;
    }
}

int TribeInformationAIModule::numberAvailableStoragePits(int param_1)
{
    int age_idx = (int)(this->md->player->attributes[6]);
    age_idx--;

    if (age_idx < 0) {
        age_idx = 0;
    } else if (age_idx > 3) {
        age_idx = 3;
    }

    if (this->dropsitesByAge[param_1][age_idx] == 0) {
        return 0;
    }

    RGE_Static_Object* obj1 = this->md->object(-1, 0x6D, -1, -1, -1, -1, -1, -1, -1, -1);

    if (obj1 != 0) {
        RGE_Static_Object* obj2 = this->md->object(this->closestDropsiteResourceID[param_1]);

        if (obj2 != 0) {
            int zone = obj1->currentZone() & 0xff;
            int y = (int)(obj2->world_y);
            int x = (int)(obj2->world_x);
            int lookup = obj1->lookupZone(x, y) & 0xff;

            if (zone != lookup) {
                return 0;
            }
        }
    }

    return this->closestDropsiteValue[param_1] >
           this->md->tacticalAI.strategicNumber(param_1 + 0xA3);
}

int TribeInformationAIModule::numberAvailableGranaries() {
    if (this->closestDropsiteValue[0] == -1) {
        return 0;
    }

    RGE_Static_Object* obj = this->md->object(
        -1, 0x6D, -1, -1, -1, -1, -1, -1, -1, -1
    );

    if (obj != 0) {
        RGE_Static_Object* filterObj = this->md->object(
            this->closestDropsiteResourceID[0]
        );

        if (filterObj != 0) {
            int zone = obj->currentZone() & 0xff;
            int val3C = (int)filterObj->world_y;
            int val38 = (int)filterObj->world_x;
            int lookup = obj->lookupZone(val38, val3C) & 0xff;
            if (zone != lookup) {
                return 0;
            }
        }
    }

    int strategicN = this->md->tacticalAI.strategicNumber(0xA3);
    return (strategicN < this->closestDropsiteValue[0]) ? 1 : 0;
}

void TribeInformationAIModule::lookAtMap()
{
    RGE_Map* map = this->md->player->world->map;
    int x = 0;

    if (this->mapXSizeValue > 0) {
        do {
            int y = 0;

            if (this->mapYSizeValue > 0) {
                do {
                    int terrainType = map->map_row_offset[y][x].terrain_type & 0x1F;

                    if (this->mapXSizeValue != -1) {
                        int qx = (x * 4) / this->mapXSizeValue;
                        int qy = (y * 4) / this->mapYSizeValue;
                        this->quadrantLog[qx][qy].numberExploredTiles++;
                    }

                    this->pathMap.setValue(x, y, 0);

                    int forestTileCount = 0;
                    RGE_Object_Node* node =
                        map->map_row_offset[y][x].objects.list;
                    while (node != 0) {
                        RGE_Static_Object* object = node->node;
                        int objectGroup = object->master_obj->object_group;

                        if (this->importantObject(objectGroup) == 1)
                            this->addImportantObject(object, 0);

                        if (objectGroup == 0x0F)
                            forestTileCount++;

                        node = node->next;
                    }

                    if (forestTileCount > 0 &&
                        (terrainType == 0x0A || terrainType == 0x13 ||
                         terrainType == 0x0D || terrainType == 0x14))
                        this->numberFoundForestTilesValue++;

                    ++y;
                } while (y < this->mapYSizeValue);
            }

            ++x;
        } while (x < this->mapXSizeValue);
    }
}

float TribeInformationAIModule::damageInflictedPerSecond(TacticalAIGroup* group, RGE_Static_Object* target) {
    float rVal = 0.0f;
    int i = 0;
    int count = group->numberUnits();

    if (count > 0) {
        do {
            int unitID = group->unit(i);
            RGE_Static_Object* obj = this->md->object(unitID);

            if (obj != 0) {
                rVal = target->damageCapability(obj) / obj->rateOfFire() + rVal;
            }

            i++;
            count = group->numberUnits();
        } while (i < count);
    }

    return rVal;
}

float TribeInformationAIModule::damageInflictedPerSecond(int* ids, int count, RGE_Static_Object* refObj)
{
    float total = 0.0f;
    for (int i = 0; i < count; i++) {
        RGE_Static_Object* obj = this->md->object(ids[i]);
        if (obj != 0) {
            total += refObj->damageCapability(obj) / obj->rateOfFire();
        }
    }
    return total;
}

float TribeInformationAIModule::timeToBeKilled(TacticalAIGroup* group, RGE_Static_Object* target) {
    float rVal = 0.0f;
    int i = 0;

    int n = group->numberUnits();
    if (n > 0) {
        do {
            int uid = group->unit(i);
            RGE_Static_Object* obj = this->md->object(uid);

            if (obj) {
                float dps = this->damagePerSecond(
                    group->unit(i),
                    (int)target->world_x,
                    (int)target->world_y);

                if (dps == 0.0f) {
                    dps = DAT_005755c0;
                } else {
                    dps = obj->hp / dps;
                }

                rVal += dps;
            }

            i++;
        } while (i < group->numberUnits());
    }

    return rVal;
}

float TribeInformationAIModule::timeToBeKilled(int* ids, int count, RGE_Static_Object* obj) {
    float total = 0.0f;
    int remaining;
    int* p;
    RGE_Static_Object* target;
    int a;
    int b;
    float dps;

    if (count > 0) {
        remaining = count;
        p = ids;
        do {
            target = this->md->object(*p);
            if (target != 0) {
                a = (int)(obj->world_y);
                b = (int)(obj->world_x);
                dps = this->damagePerSecond(*p, b, a);
                if (dps == 0.0f) {
                    dps = 600.0f;
                } else {
                    dps = target->hp / dps;
                }
                total = total + dps;
            }
            p++;
            remaining--;
        } while (remaining != 0);
    }
    return total;
}

int TribeInformationAIModule::closestDropsiteResID(int index) const {
    if (index < 0 || index > 3) {
        return -1;
    }
    return this->closestDropsiteResourceID[index];
}

int TribeInformationAIModule::calculatePlayVariation(int param_1) {
    (void)param_1;
    int totalPlays = 0;
    for (int i = 0; i < 0x3E80; ++i) {
        totalPlays += this->playHistory[i];
    }

    return 100 - (int)((float)this->unitHistory[0] / (float)totalPlays * DAT_00575584);
}

int TribeInformationAIModule::convertUnitToIntType(RGE_Static_Object* obj) const {
    int og = obj->master_obj->object_group;
    int id = obj->master_obj->id;

    if (og == 0x12) return 5;
    if (og == 0x1C) return 3;
    if (og == 0x0D) return 4;
    if (og == 0x0C) return 2;
    if (og == 0x23) return 7;

    if (id == 0x49) return 0;
    if (id == 0x4B) return 1;

    if (id == 4 || id == 5 || id == 0x27) return 6;

    if (id == 0x29) return 10;

    if (id == 0x2E || id == 0x19) return 9;

    // Fallback: returns 8 if object_group == 0x16, otherwise -1
    return (og == 0x16) ? 8 : -1;
}

#include <stdio.h>
#include <string.h>


void TribeInformationAIModule::loadUnitHistory() {
    char historyFileName[256];

    RGE_Game_Info* game_info = rge_base_game->player_game_info;

    if (game_info) {
        sprintf(historyFileName, "learn\\%s.uh", game_info->get_current_player_name());
    } else {
        strcpy(historyFileName, "learn\\Default.uh");
    }

    int fd = rge_open(historyFileName, 0x8000);
    if (fd != -1) {
        rge_read(fd, (char*)this + 0xFF64, 0x2C);
        rge_close(fd);
    }
}

void TribeInformationAIModule::unitsThatAreMostBuilt(int& out1, int& out2) {
    int* history;
    int i;
    int bestValue;

    history = this->unitHistory;
    out1 = -1;
    bestValue = -1;
    for (i = 0; i < 11; i++) {
        if (bestValue == -1 || bestValue < history[i]) {
            out1 = i;
            bestValue = history[i];
        }
    }

    out2 = -1;
    bestValue = -1;
    for (i = 0; i < 11; i++) {
        if (i != out1 && (bestValue == -1 || bestValue < history[i])) {
            out2 = i;
            bestValue = history[i];
        }
    }
}

void TribeInformationAIModule::unitsThatAreLeastBuilt(int& out1, int& out2) {
    int* history;
    int i;
    int bestValue;

    history = this->unitHistory;
    out1 = 0x7FFFFFFF;
    bestValue = -1;
    for (i = 0; i < 11; i++) {
        if (bestValue == -1 || bestValue > history[i]) {
            out1 = i;
            bestValue = history[i];
        }
    }

    out2 = 0x7FFFFFFF;
    bestValue = -1;
    for (i = 0; i < 11; i++) {
        if (i != out1 && (bestValue == -1 || bestValue > history[i])) {
            out2 = i;
            bestValue = history[i];
        }
    }
}

int TribeInformationAIModule::acceptablePotentialDropsiteArea(int param1, int param2)
{
    int strategicNumber = this->md->tacticalAI.strategicNumber(0xCA);
    int s = strategicNumber * strategicNumber;

    for (int i = 0; i < this->maxImportantObjectMemory; i++) {
        uchar owner = this->importantObjectMemory[i].owner;
        if ((this->md->player->mutualVisibleMask & (1UL << owner)) != 0) {
            short type = this->importantObjectMemory[i].type;
            if (type == 0x6D || type == 0x67 || type == 0x44 ||
                type == 0x4F || type == 0xC7 || type == 0x45) {
                int x = (int)this->importantObjectMemory[i].x;
                int y = (int)this->importantObjectMemory[i].y;
                int dx = x - param1;
                int dy = y - param2;
                if (dx * dx + dy * dy <= s)
                    return 0;
            }
        }
    }
    return 1;
}

int TribeInformationAIModule::percentTilesExploredInPositionQuadrant(int param_1, int param_2) {
    if (this->mapXSizeValue == -1) {
        return 0;
    }

    int qx = param_1 * 4 / this->mapXSizeValue;
    int numTilesInQuadrant = this->mapXSizeValue / 4 *
                             this->mapYSizeValue / 4;
    int qy = param_2 * 4 / this->mapYSizeValue;

    return this->quadrantLog[qx][qy].numberExploredTiles * 100 /
           numTilesInQuadrant;
}
