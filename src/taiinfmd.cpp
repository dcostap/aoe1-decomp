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
#include "../include/tworld.h"
#include "../include/aiuaimod.h"
#include "../include/xyz_point.h"
#include "../include/visible.h"
#include "../include/victory.h"
#include "../include/world.h"
#include "../include/zone_map.h"
#include "../include/rge_fio.h"
#include <fcntl.h>
#include <sys/stat.h>
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

TribeInformationAIModule::TribeInformationAIModule(void* pW, int pID)
    : InformationAIModule(pW, pID),
      md(0),
      mapXSizeValue(-1),
      mapYSizeValue(-1),
      lastUpdateRowValue(0),
      maxImportantObjectMemory(500),
      pathMap(0xfe, 0xfe, 0xff),
      maxBuildingLots(200),
      maxAttackMemories(25),
      saveLearnInformationValue(0),
      numberFoundForestTilesValue(0) {
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

    this->importantObjectMemory = (ObjectMemory*)operator new(this->maxImportantObjectMemory * sizeof(ObjectMemory));
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

    this->buildingLots = (BuildingLot*)operator new(this->maxBuildingLots * sizeof(BuildingLot));
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

    this->attackMemories = (AttackMemory*)operator new(this->maxAttackMemories * sizeof(AttackMemory));
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

TribeInformationAIModule::TribeInformationAIModule(int pID, int infile)
    : InformationAIModule(0, pID),
      md(0),
      pathMap(0xfe, 0xfe, 0xff),
      saveLearnInformationValue(0),
      numberFoundForestTilesValue(0) {
    int tempInt;
    int loaded_value;
    int resource_type_id;
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
        rge_read(infile, &pID, 4);
        i3 = 0;
        if (pID > 0) {
            do {
                rge_read(infile, &resource_type_id, 4);
                this->addResourceType(resourceIndex, resource_type_id);
                i3++;
            } while (i3 < pID);
        }
        resourceIndex++;
    } while (resourceIndex < 4);

    rge_read(infile, &this->mapXSizeValue, 4);
    rge_read(infile, &this->mapYSizeValue, 4);
    rge_read(infile, &this->lastUpdateRowValue, 4);
    rge_read(infile, &this->maxImportantObjectMemory, 4);
    this->importantObjectMemory = (ObjectMemory*)operator new(this->maxImportantObjectMemory * sizeof(ObjectMemory));
    if (this->importantObjectMemory != 0) {
        for (int i4 = 0; i4 < this->maxImportantObjectMemory; i4++) {
            rge_read(infile, this->importantObjectMemory + i4, sizeof(ObjectMemory));
        }

        rge_read(infile, &this->maxBuildingLots, 4);
        this->buildingLots = (BuildingLot*)operator new(this->maxBuildingLots * sizeof(BuildingLot));
        if (this->buildingLots != 0) {
            for (int i5 = 0; i5 < this->maxBuildingLots; i5++) {
                rge_read(infile, this->buildingLots + i5, sizeof(BuildingLot));
            }

            rge_read(infile, &this->maxAttackMemories, 4);
            this->attackMemories = (AttackMemory*)operator new(this->maxAttackMemories * sizeof(AttackMemory));
            if (this->attackMemories != 0) {
                for (int i6 = 0; i6 < this->maxAttackMemories; i6++) {
                    rge_read(infile, this->attackMemories + i6, sizeof(AttackMemory));
                }

                rge_read(infile, &tempInt, 4);
                pID = 0;
                if (tempInt > 0) {
                    do {
                        rge_read(infile, &loaded_value, 4);
                        this->importantObjects.add(loaded_value);
                        pID++;
                    } while (pID < tempInt);
                }

                rge_read(infile, &tempInt, 4);
                pID = 0;
                if (tempInt > 0) {
                    do {
                        rge_read(infile, &loaded_value, 4);
                        this->importantUnits.add(loaded_value);
                        pID++;
                    } while (pID < tempInt);
                }

                rge_read(infile, &tempInt, 4);
                pID = 0;
                if (tempInt > 0) {
                    do {
                        rge_read(infile, &loaded_value, 4);
                        this->importantMiscs.add(loaded_value);
                        pID++;
                    } while (pID < tempInt);
                }

                rge_read(infile, &tempInt, 4);
                pID = 0;
                if (tempInt > 0) {
                    do {
                        rge_read(infile, &loaded_value, 4);
                        this->itemsToDefend.add(loaded_value);
                        pID++;
                    } while (pID < tempInt);
                }

                rge_read(infile, &tempInt, 4);
                pID = 0;
                if (tempInt > 0) {
                    do {
                        rge_read(infile, &loaded_value, 4);
                        this->playerBuildings.add(loaded_value);
                        pID++;
                    } while (pID < tempInt);
                }

                rge_read(infile, &tempInt, 4);
                pID = 0;
                if (tempInt > 0) {
                    do {
                        rge_read(infile, &loaded_value, 4);
                        this->playerObjects.add(loaded_value);
                        pID++;
                    } while (pID < tempInt);
                }

                this->pathMap.load(infile);
                rge_read(infile, &this->lastWallPosition, 8);
                rge_read(infile, &this->lastWallPosition2, 8);

                if (!(save_game_version < g_information_ai_save_version_1_6)) {
                    rge_read(infile, &this->numberGatesValue, 4);
                } else {
                    rge_read(infile, &this->numberGatesValue, 8);
                }

                for (int i7 = 0; i7 < 4; i7++) {
                    rge_read(infile, &this->minGatePosition[i7], 8);
                    rge_read(infile, &this->maxGatePosition[i7], 8);
                }

                rge_read(infile, &this->saveLearnInformationValue, 4);
                if (!(save_game_version < g_information_ai_save_version_1_6)) {
                    rge_read(infile, &loaded_value, 4);
                    rge_read(infile, this->learnFileName, loaded_value);
                    this->learnFileName[loaded_value] = '\0';
                } else {
                    strcpy(this->learnFileName, "");
                }

                rge_read(infile, this->fullyExploredZoneValue, 255);
                if (!(save_game_version < g_information_ai_save_version_2_5)) {
                    rge_read(infile, this->quadrantLog, 192);
                } else {
                    for (int i8 = 0; i8 < 4; i8++) {
                        for (int j8 = 0; j8 < 4; j8++) {
                            this->quadrantLog[i8][j8].numberExploredTiles = 0;
                            this->quadrantLog[i8][j8].numberAttacksOnUs = 0;
                            this->quadrantLog[i8][j8].numberAttacksByUs = 0;
                        }
                    }
                }

                rge_read(infile, this->maxResources, 16);
                rge_read(infile, this->numResources, 16);
                for (int i9 = 0; i9 < 4; i9++) {
                    if (this->maxResources[i9] != 0) {
                        this->resources[i9] = (ResourceMemory*)operator new(
                            this->maxResources[i9] * sizeof(ResourceMemory));
                        rge_read(infile, this->resources[i9], this->maxResources[i9] * sizeof(ResourceMemory));
                    } else {
                        this->resources[i9] = 0;
                    }
                }

                if (!(save_game_version < g_information_ai_save_version_6_8)) {
                    rge_read(infile, this->dropsitesByAge, 64);
                }
                if (!(save_game_version < g_information_ai_save_version_6_8)) {
                    rge_read(infile, this->closestDropsiteValue, 16);
                    rge_read(infile, this->closestDropsiteResourceID, 16);
                }
                if (!(save_game_version < g_information_ai_save_version_6_91)) {
                    rge_read(infile, &this->numberFoundForestTilesValue, 4);
                }
                if (!(save_game_version < g_information_ai_save_version_6_99)) {
                    rge_read(infile, this->playHistory, 64000);
                }
            }
        }
    }
}

TribeInformationAIModule::~TribeInformationAIModule() {
    int count;
    int tempInt;
    int outFile;
    int unit_history_file;
    int i;
    int index;
    int offset;

    for (i = 0; i < 4; i++) {
        operator delete(this->resourceTypesValue[i]);
    }
    operator delete(this->resourceTypesValue);
    operator delete(this->numberResourceTypesValue);

    if (this->saveLearnInformationValue == 1) {
        int file = rge_open(this->learnFileName, _O_BINARY | _O_WRONLY | _O_CREAT | _O_TRUNC, _S_IREAD | _S_IWRITE);
        unit_history_file = file;
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
                        rge_write(file, (AttackMemory*)((char*)this->attackMemories + offset), 24);
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
                        rge_write(file, (ObjectMemory*)(offset + (char*)this->importantObjectMemory), 36);
                    index++;
                    offset += sizeof(ObjectMemory);
                } while (index < this->maxImportantObjectMemory);
            }

            for (i = 0; i < 4; i++) {
                rge_write(file, &this->maxResources[i], 4);
                rge_write(file, &this->numResources[i], 4);
                if (this->maxResources[i] != 0)
                    rge_write(file, this->resources[i], this->maxResources[i] * sizeof(ResourceMemory));
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
        (unit_history_file = rge_open(this->unitHistoryFilename, _O_BINARY | _O_WRONLY | _O_CREAT | _O_TRUNC,
                                      _S_IREAD | _S_IWRITE),
         unit_history_file != -1)) {
        rge_write(unit_history_file, this->unitHistory, 44);
        rge_close(unit_history_file);
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

int TribeInformationAIModule::update(int timeLimit) {
    RGE_Visible_Map* vMap;
    RGE_Map* gMap;
    int gMap_slot;
    int vMap_slot;
    int listSize;
    unsigned char visibleStatus;
    int tileType;
    int numberTreesOnTile;
    int col;
    int row;
    RGE_Tile_List_Node* list;
    int i;
    int newCount;
    this->md->player->tile_list.get_list_info(list, i);
    newCount = this->md->player->tile_list.get_new_count();
    vMap = this->md->player->visible;
    gMap = this->md->player->world->map;

    if (newCount > 0) {
        listSize = i - newCount;
        if (listSize < i) {
            do {
                row = list->row;
                col = list->col;

                visibleStatus = ((RGE_Visible_Map*)vMap)->get_visible(col, row);

                // Terrain type from tile bytes
                {
                    RGE_Tile* tile = gMap->map_row_offset[row] + col;
                    tileType = tile->terrain_type & 0x1F;
                }

                // Quadrant update
                {
                    if (this->mapXSizeValue != -1) {
                        int qX = (col * 4) / this->mapXSizeValue;
                        int qy = (row * 4) / this->mapYSizeValue;
                        this->quadrantLog[qX][qy].numberExploredTiles++;
                    }
                }

                // Set influence map
                this->pathMap.setValue(col, row, 0);

                // Iterate tile objects
                numberTreesOnTile = 0;
                {
                    RGE_Object_Node* node = gMap->map_row_offset[row][col].objects.list;

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
                            numberTreesOnTile++;
                        }

                        node = node->next;
                    }
                }

                // Check forest count + terrain type
                if (numberTreesOnTile > 0) {
                    if (tileType == 0xA || tileType == 0x13 || tileType == 0xD || tileType == 0x14) {
                        this->numberFoundForestTilesValue++;
                    }
                }

                listSize++;
                list = (RGE_Tile_List_Node*)((char*)list + 8);
            } while (listSize < i);
        }
    }

    return 1;
}

void TribeInformationAIModule::setMainDecisionAI(TribeMainDecisionAIModule* m) {
    this->md = m;
}

#include <string.h>
#include <stdlib.h>

void rge_write(int file, void* data, int size);

int TribeInformationAIModule::save(int outfile) {
    int tempInt;
    int saved_handle = outfile;
    for (int k = 0; k < 4; k++) {
        tempInt = this->numberResourceTypesValue[k];
        rge_write(saved_handle, &tempInt, 4);
        for (int m = 0; m < this->numberResourceTypesValue[k]; m++) {
            tempInt = this->resourceTypesValue[k][m];
            rge_write(saved_handle, &tempInt, 4);
        }
    }

    rge_write(saved_handle, &this->mapXSizeValue, 4);
    rge_write(saved_handle, &this->mapYSizeValue, 4);
    rge_write(saved_handle, &this->lastUpdateRowValue, 4);
    rge_write(saved_handle, &this->maxImportantObjectMemory, 4);
    for (int a = 0; a < this->maxImportantObjectMemory; a++)
        rge_write(saved_handle, (char*)this->importantObjectMemory + a * 0x24, 36);

    rge_write(saved_handle, &this->maxBuildingLots, 4);
    for (int b = 0; b < this->maxBuildingLots; b++)
        rge_write(saved_handle, (char*)this->buildingLots + b * 8, 8);

    rge_write(saved_handle, &this->maxAttackMemories, 4);
    for (int c = 0; c < this->maxAttackMemories; c++)
        rge_write(saved_handle, (char*)this->attackMemories + c * 0x18, 24);

    outfile = this->importantObjects.numberValue;
    rge_write(saved_handle, &outfile, 4);
    for (int d = 0; d < this->importantObjects.numberValue; d++) {
        outfile = this->importantObjects[d];
        rge_write(saved_handle, &outfile, 4);
    }
    outfile = this->importantUnits.numberValue;
    rge_write(saved_handle, &outfile, 4);
    for (int e = 0; e < this->importantUnits.numberValue; e++) {
        outfile = this->importantUnits[e];
        rge_write(saved_handle, &outfile, 4);
    }
    outfile = this->importantMiscs.numberValue;
    rge_write(saved_handle, &outfile, 4);
    for (int f = 0; f < this->importantMiscs.numberValue; f++) {
        outfile = this->importantMiscs[f];
        rge_write(saved_handle, &outfile, 4);
    }
    outfile = this->itemsToDefend.numberValue;
    rge_write(saved_handle, &outfile, 4);
    for (int g = 0; g < this->itemsToDefend.numberValue; g++) {
        outfile = this->itemsToDefend[g];
        rge_write(saved_handle, &outfile, 4);
    }
    outfile = this->playerBuildings.numberValue;
    rge_write(saved_handle, &outfile, 4);
    for (int h = 0; h < this->playerBuildings.numberValue; h++) {
        outfile = this->playerBuildings[h];
        rge_write(saved_handle, &outfile, 4);
    }
    outfile = this->playerObjects.numberValue;
    rge_write(saved_handle, &outfile, 4);
    for (int w = 0; w < this->playerObjects.numberValue; w++) {
        outfile = this->playerObjects[w];
        rge_write(saved_handle, &outfile, 4);
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

    outfile = strlen(this->learnFileName);
    rge_write(saved_handle, &outfile, 4);
    rge_write(saved_handle, this->learnFileName, strlen(this->learnFileName));

    rge_write(saved_handle, this->fullyExploredZoneValue, 255);
    rge_write(saved_handle, this->quadrantLog, 192);

    for (int y = 0; y < 4; y++) {
        if (this->maxResources[y] != 0 && this->resources[y] == 0)
            this->maxResources[y] = 0;
    }
    rge_write(saved_handle, &this->maxResources, 16);
    rge_write(saved_handle, &this->numResources, 16);
    for (int z = 0; z < 4; z++) {
        if (this->maxResources[z] != 0)
            rge_write(saved_handle, this->resources[z], this->maxResources[z] * 20);
    }

    rge_write(saved_handle, this->dropsitesByAge, 64);
    rge_write(saved_handle, this->closestDropsiteValue, 16);
    rge_write(saved_handle, this->closestDropsiteResourceID, 16);
    rge_write(saved_handle, &this->numberFoundForestTilesValue, 4);
    rge_write(saved_handle, this->playHistory, 64000);

    return 1;
}

void TribeInformationAIModule::blotExploredMap(int minX, int minY, int maxX, int maxY) {
    XYPoint max;
    XYPoint min;

    max.x = minX;
    max.y = minY;
    this->mapBound(max);

    min.x = maxX;
    min.y = maxY;
    this->mapBound(min);

    for (int x = max.x; x <= min.x; x++) {
        for (int y = max.y; y <= min.y; y++) {
            if (this->pathMap.lookupValue(x, y) != 1)
                this->pathMap.setValue(x, y, 2);
        }
    }
}

int TribeInformationAIModule::closestUnexploredTile(
    int uID, float cX, float cY, float* uX, float* uY) {
    RGE_Visible_Map* vMap = this->md->player->visible;
    RGE_Static_Object* obj = this->md->player->world->object(uID);

    if (obj == 0)
        return 0;

    int civilianObj = obj->master_obj->object_group == 4;
    unsigned char initialZone = obj->currentZone();
    int direction = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\taiinfmd.cpp", 919) % 4;
    int x = (int)cX;
    int y = (int)cY;
    int offLeft = 0;
    int offRight = 0;
    int offTop = 0;
    int offBottom = 0;
    int stepSize = 0;

    while (offLeft == 0 || offRight == 0 || offTop == 0 || offBottom == 0) {
        ++stepSize;

        for (int side = 0; side < 2; ++side) {
            direction = (direction + 1) % 4;

            for (int step = 0; step < stepSize; ++step) {
                switch (direction) {
                case 0:
                    ++y;
                    break;
                case 1:
                    ++x;
                    break;
                case 2:
                    --y;
                    break;
                case 3:
                    --x;
                    break;
                }

                if (x < 0) {
                    offLeft = 1;
                } else if (x >= this->mapXSizeValue) {
                    offRight = 1;
                } else if (y < 0) {
                    offTop = 1;
                } else if (y >= this->mapYSizeValue) {
                    offBottom = 1;
                } else {
                    char path_value = (char)this->pathMap.lookupValue(x, y);
                    unsigned char visibility = vMap->get_visible(x, y);

                    if (visibility != 0x0f && (civilianObj == 0 || path_value == -1) &&
                        (civilianObj != 0 || path_value == -1 || path_value == 2) &&
                        obj->passableTile((float)x, (float)y, 1) != 0 && obj->lookupZone(x, y) == initialZone) {
                        XYZPoint cPoint;
                        float pathDistance;
                        cPoint.x = x;
                        cPoint.y = y;
                        cPoint.z = (int)obj->world_z;

                        if (obj->canPath(cPoint, obj->master_obj->los - 1.0f, -1, &pathDistance, 1, -1, -1) == 0) {
                            this->pathMap.setValue(x, y, 1);

                            int bestValue = -1;
                            int best_x = 0;
                            int best_y = 0;

                            for (int quadrant_x = 0; quadrant_x < 4; ++quadrant_x) {
                                for (int quadrant_y = 0; quadrant_y < 4; ++quadrant_y) {
                                    int value = this->quadrantLog
                                        [quadrant_x][quadrant_y]
                                            .numberExploredTiles;
                                    value += debug_rand((char*)"C:\\msdev\\work\\age1_x1\\taiinfmd.cpp", 1056) % 100;
                                    value += this->quadrantLog
                                        [quadrant_x][quadrant_y]
                                            .numberAttacksOnUs * 25;

                                    if (bestValue == -1 || bestValue > value) {
                                        bestValue = value;
                                        best_x = this->mapXSizeValue * quadrant_x / 4;
                                        best_y = this->mapYSizeValue * quadrant_y / 4;
                                    }
                                }
                            }

                            int max_x = best_x + this->mapXSizeValue / 4 - 1;
                            int max_y = best_y + this->mapYSizeValue / 4 - 1;

                            int corner = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\taiinfmd.cpp", 1072) % 4;
                            if (corner == 0) {
                                x = best_x;
                                y = best_y;
                            } else if (corner == 1) {
                                x = best_x;
                                y = max_y;
                            } else {
                                x = max_x;
                                if (corner == 2)
                                    y = max_y;
                                else
                                    y = best_y;
                            }
                        } else {
                            this->pathMap.setValue(x, y, 0);
                        }

                        *uX = (float)x;
                        *uY = (float)y;
                        return 1;
                    }
                }
            }
        }
    }

    this->setFullyExploredZone(uID, 1);
    return 0;
}

int TribeInformationAIModule::fullyExploredZone(int id) {
    RGE_Static_Object* object = md->object(id);
    if (object != 0) {
        unsigned char objZone = object->currentZone();
        if (fullyExploredZoneValue[objZone] == 0) {
            return 1;
        }
    }
    return 0;
}

void TribeInformationAIModule::setFullyExploredZone(int id, int v) {
    RGE_Static_Object* object = md->object(id);
    if (object != 0) {
        unsigned char objZone = object->currentZone();
        fullyExploredZoneValue[objZone] = (unsigned char)v;
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

int TribeInformationAIModule::ownerOfGameID(int id) { return -1; }

#include <math.h>
#include <stdlib.h>
#include <string.h>

int TribeInformationAIModule::gameIDOfResourceObject(
    int rType, int gathererID, float& roXPos, float& roYPos,
    int& dropsiteID, int* exclusions, int numExclusions) {
    dropsiteID = -1;

    RGE_Static_Object* gathererObj = this->md->object(gathererID);
    if (gathererObj != 0) {
        unsigned char gathererZone = gathererObj->currentZone();
        int gathererX = (int)gathererObj->world_x;
        int gathererY = (int)gathererObj->world_y;
        int fishingBoat = this->isBoat(gathererObj);
        ResourceMemory* bestObject = 0;
        int bestValue = -1;
        int update_dropsites = 0;
        int resource_offset = 0;
        int updateResourceDist = 0;

        if (this->numResources[rType] > 0) {
            do {
                ResourceMemory* resource = (ResourceMemory*)
                    ((char*)this->resources[rType] + resource_offset);
                unsigned char gone = resource->gone;

                if (gone != 1) {
                    if (resource->valid != 0) {
                        if (gone == 0)
                            --resource->valid;
                    } else {
                        int excluded_resource = 0;
                        int exclude_index = 0;

                        if (numExclusions > 0) {
                            do {
                                if (exclusions[exclude_index] == resource->id) {
                                    excluded_resource = 1;
                                    break;
                                }
                                ++exclude_index;
                            } while (exclude_index < numExclusions);
                        }

                        if (excluded_resource == 0) {
                            RGE_Static_Object* object =
                                this->md->object(resource->id);
                            if (object == 0) {
                                resource = (ResourceMemory*)
                                    ((char*)this->resources[rType] + resource_offset);
                                resource->gone = 1;
                                resource = (ResourceMemory*)
                                    ((char*)this->resources[rType] + resource_offset);
                                if (this->closestDropsiteResourceID[rType] == resource->id) {
                                    update_dropsites = 1;
                                }
                            } else {
                                if (fishingBoat == 1) {
                                    short group = object->master_obj->object_group;
                                    if (group != 5 && group != 0x1f && group != 0x21) {
                                        goto next_resource;
                                    }
                                }
                                if (fishingBoat == 0) {
                                    short group = object->master_obj->object_group;
                                    if (group == 5 || group == 0x1f || group == 0x21) {
                                        goto next_resource;
                                    }
                                }

                                resource = (ResourceMemory*)
                                    ((char*)this->resources[rType] + resource_offset);
                                int value;
                                int dx = gathererX - (int)resource->x;
                                int dy = gathererY - (int)resource->y;
                                value = dx * dx + dy * dy +
                                        resource->gatherValue * 10;

                                if (object->master_obj->id == 0x3b) {
                                    if (resource->dropDistance > 0x14)
                                        goto next_resource;
                                    value += resource->gatherAttempts / 0x96;
                                    if (this->md->tacticalAI.numberGatherersWithTarget(object->id) > 2) {
                                        value += 200;
                                    }
                                } else {
                                    value += resource->gatherAttempts / 0x32;
                                }

                                if (bestObject != 0 && value >= bestValue)
                                    goto next_resource;

                                if ((object->master_obj->object_group == 9 || object->master_obj->object_group == 10) &&
                                    object->object_state > 2 && object->attribute_amount_held > 25.0f) {
                                    value += 0x19;
                                }

                                if (this->withinXTilesOfEnemyTowncenter(object, 0x19) == 1) {
                                    goto next_resource;
                                }

                                int attacked = this->withinXTilesOfAttackOnPlayer(object, 0x0f, this->md->player->id);
                                if (attacked == 1)
                                    value += 0x1f4;

                                if (object->master_obj->id == 0x32) {
                                    if (object->owner->id != this->md->player->id || object->object_state != 2 ||
                                        this->md->tacticalAI.numberGatherersWithTarget(object->id) > 0) {
                                        goto next_resource;
                                    }

                                    int farm_index = 0;
                                    int farm_count =
                                        this->farmsTaskedThisUpdate.numberValue;
                                    if (farm_count > 0) {
                                        do {
                                            if (farm_index >= this->farmsTaskedThisUpdate.maximumSizeValue) {
                                                break;
                                            }
                                            if (this->farmsTaskedThisUpdate.value[farm_index] == object->id) {
                                                goto next_resource;
                                            }
                                            ++farm_index;
                                        } while (farm_index < this->farmsTaskedThisUpdate.numberValue);
                                    }
                                }

                                if (rType == 1 && this->md->tacticalAI.numberGatherersWithTarget(object->id) >= 1) {
                                    goto next_resource;
                                }
                                if ((rType == 3 || rType == 2) && this->md->tacticalAI
                                    .numberGatherersWithTarget(object->id) > 3) {
                                    goto next_resource;
                                }

                                if (object->master_obj->id == 0x30 && object->object_state == 2) {
                                    int desired = this->md->tacticalAI
                                        .strategicNumber(0xcc);
                                    int actual = this->md->tacticalAI
                                        .actualGathererCountByRealResourceID(0);
                                    if (actual < desired)
                                        goto next_resource;
                                }

                                resource = (ResourceMemory*)
                                    ((char*)this->resources[rType] + resource_offset);
                                if (gathererZone == gathererObj->lookupZone(resource->x, resource->y) &&
                                    (bestObject == 0 || value < bestValue)) {
                                    resource = (ResourceMemory*)
                                        ((char*)this->resources[rType] + resource_offset);
                                    bestObject = resource;
                                    roXPos = object->world_x;
                                    bestValue = value;
                                    roYPos = object->world_y;
                                }
                            }
                        }
                    }
                }

next_resource:
                ++updateResourceDist;
                resource_offset += sizeof(ResourceMemory);
            } while (updateResourceDist < this->numResources[rType]);
        }

        if (update_dropsites == 1)
            this->updateResourceDropsites(rType);

        if (bestObject != 0) {
            ++bestObject->gatherAttempts;
            dropsiteID = bestObject->dropsiteID;
            return bestObject->id;
        }
    }
    return -1;
}

#include <stddef.h>

int TribeInformationAIModule::gameIDsOfObjectType(int oType, int** objects, int** owners, int ownerNumber) {
    *objects = 0;
    int count = 0;
    *owners = 0;
    int maxCount = 10;
    int i = 0;
    if (this->importantObjects.numberValue > 0) {
        do {
            RGE_Static_Object* tempObj = this->md->aiPlayer->world->object(this->importantObjects[i]);
            if (tempObj != 0) {
                if (ownerNumber == -5) {
                    if (this->md->aiPlayer->id == tempObj->owner->id) goto next;
                }
                if (ownerNumber == -6) {
                    if (this->md->aiPlayer->isEnemy(tempObj->owner->id) != 0) goto next;
                }
                if (ownerNumber != -1 && tempObj->owner->id != ownerNumber) goto next;
                if (oType != -1 && oType != ((RGE_Master_Static_Object*)tempObj->master_obj)->id) goto next;
                if (count == maxCount || *objects == 0) {
                    int* newIds = (int*)operator new(maxCount * 8);
                    int* newOwners = (int*)operator new(maxCount * 8);
                    if (*objects != 0) {
                        for (int j = 0; j < maxCount; j++) {
                            newIds[j] = (*objects)[j];
                            newOwners[j] = (*owners)[j];
                        }
                    }
                    maxCount *= 2;
                    if (*objects != 0) operator delete(*objects);
                    if (*owners != 0) operator delete(*owners);
                    *objects = newIds;
                    *owners = newOwners;
                }
                (*objects)[count] = this->importantObjects[i];
                (*owners)[count++] = tempObj->owner->id;
            }
next:
            i++;
        } while (i < this->importantObjects.numberValue);
    }
    return count;
}

int TribeInformationAIModule::gameIDsOwnedBy(int oType, int** objects, int ownerNumber) {
    int count = 0;
    int capacity = 10;
    int i;
    *objects = 0;
    i = 0;

    if (this->maxImportantObjectMemory > 0) {
        do {
            if (this->importantObjectMemory[i].id != -1) {
                RGE_Game_World* world = this->md->aiPlayer->world;
                RGE_Static_Object* obj = world->object(this->importantObjectMemory[i].id);
                if (obj != 0) {
                    int owner_id = obj->owner->id;
                    if (owner_id == ownerNumber) {
                        if (oType == -1 || oType == this->importantObjectMemory[i].owner) {
                            if (count == capacity || *objects == 0) {
                                int* new_arr = (int*)::operator new(capacity * 8);
                                if (*objects != 0) {
                                    for (int copy_index = 0; copy_index < capacity; copy_index++) {
                                        new_arr[copy_index] = (*objects)[copy_index];
                                    }
                                }
                                capacity *= 2;
                                if (*objects != 0) {
                                    ::operator delete(*objects);
                                }
                                *objects = new_arr;
                            }
                            (*objects)[count] = this->importantObjectMemory[i].id;
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

int TribeInformationAIModule::numberGameIDsOwnedBy(int oType, int ownerNumber) {
    int count = 0;
    int i = 0;

    if (this->maxImportantObjectMemory > 0) {
        do {
            int id = this->importantObjectMemory[i].id;
            if (id != -1) {
                RGE_Game_World* world = this->md->aiPlayer->world;
                RGE_Static_Object* obj = world->object(id);
                if (obj != 0) {
                    short owner_id = obj->owner->id;
                    if (owner_id == ownerNumber && (oType == -1 || oType == this->importantObjectMemory[i].owner)) {
                        count++;
                    }
                }
            }
            i++;
        } while (i < this->maxImportantObjectMemory);
    }

    return count;
}

#include <math.h>
#include <string.h>

ConstructionItem* TribeInformationAIModule::placeDock(
    BuildItem* bi, float cX, float cY, int centerType, int edgeType) {
    // The zone-map output and cache array use separate homes.
    RGE_Visible_Map* vMap = this->md->aiPlayer->visible;
    RGE_Map* gMap = this->md->aiPlayer->world->map;
    int bYTile;
    RGE_Zone_Map* zoneMap;
    int bXTile;
    int zoneMapIndex;
    unsigned char zoneCounter[256];
    int randSelect;
    float bD;
    int y;

    bXTile = -1;
    bYTile = -1;
    bD = -1.0f;
    randSelect = -1;

    memset(zoneCounter, -1, sizeof(zoneCounter));

    zoneMap = gMap->map_zones->get_zone_map(this->md->player->world->terrains[
                                            this->md->player->master_objects[0x13]->terrain], this->md->player->world->terrain_size, zoneMapIndex);

    randSelect = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\taiinfmd.cpp", 1705) % 0x32;

    {
        int x = 1;
        if (x < vMap->widthValue - 2) {
            do {
                y = 1;
                if (y < vMap->heightValue - 2) {
                    do {
                        if (vMap->get_visible(x, y) != 0 && x - 1 >= 0 && y - 1 >= 0 && x + 1 <= vMap->widthValue - 1 &&
                            y + 1 <= vMap->heightValue - 1) {
                            if (centerType == -1 || (gMap->map_row_offset[y][x].terrain_type & 0x1F) == centerType) {
                                unsigned char currentZone = zoneMap->get_zone_info(x, y);
                                int numberTiles =
                                    zoneMap->numberTilesInZone(currentZone);
                                int minimumTiles =
                                    this->md->tacticalAI.strategicNumber(0x70);
                                if (numberTiles >= minimumTiles && this->hasAdjacentTileType(x, y, edgeType)) {
                                    ConstructionItem* lot =
                                        this->md->constructionAI.randomLot((float)x - (-0.5f),
                                                                           (float)y - (-0.5f));
                                    if (lot == 0) {
                                        float cD = ((float)x - cX) *
                                                      ((float)x - cX) +
                                                      ((float)y - cY) *
                                                      ((float)y - cY);
                                        if (zoneCounter[currentZone] == 0xFF) {
                                            zoneCounter[currentZone] = (unsigned char)
                                                this->numberDocksInZone((int)currentZone, zoneMap);
                                        }
                                        // A positive count selects the
                                        // penalty block and emits TEST/JBE.
                                        if (zoneCounter[currentZone] > 0) {
                                            int zonePenalty =
                                                (int)zoneCounter[currentZone] * 1000;
                                            cD += (float)zonePenalty;
                                        }

                                        {
                                            int closest =
                                                this->closestDockDistance(x, y);
                                            if (closest != -1) {
                                                cD += (float)(100000 / closest);
                                            }
                                        }

                                        if (bXTile == -1 || cD < bD + (float)randSelect) {
                                            bD = cD;
                                            bXTile = x;
                                            bYTile = y;
                                        }
                                    }
                                }
                            }
                        }

                        y++;
                    } while (y < vMap->heightValue - 2);
                }

                x++;
            } while (x < vMap->widthValue - 2);
        }
    }

    if (bXTile != -1) {
        ConstructionItem* result =
            new ConstructionItem((float)bXTile - (-0.5f), (float)bYTile - (-0.5f), 0.0f, bi->xSize(), bi->ySize(),
                                 bi->zSize(), bi->typeID(), bi->name());
        return result;
    }
    return 0;
}

#include <stddef.h>

int TribeInformationAIModule::numberDocksInZone(int zone, RGE_Zone_Map* zoneMap) {
    int count = 0;
    int i = 0;

    if (this->playerBuildings.numberValue > 0) {
        do {
            RGE_Static_Object* obj = this->md->object(this->playerBuildings[i]);
            if (obj != 0 && obj->master_obj->id == 0x2D) {
                unsigned char dockZone = zoneMap->get_zone_info((int)obj->world_x, (int)obj->world_y);
                if (dockZone == zone) {
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

int TribeInformationAIModule::closestDockDistance(int x, int y) {
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

                if (currentDistance != 0 && (distance == -1 || distance > currentDistance)) {
                    distance = currentDistance;
                }
            }

            i++;
        } while (i < this->playerBuildings.numberValue);
    }

    return distance;
}

int TribeInformationAIModule::hasAdjacentTileType(int x, int y, int aType) {
    RGE_Map* map = this->md->aiPlayer->world->map;
    int current_x = x;
    int current_y = y;

    for (int i = 0; i < 8; ++i) {
        switch (i) {
        case 0:
            current_x = x - 1;
            current_y = y;
            goto adjust_y;

        case 1:
        case 2:
            ++current_x;
            break;

        case 3:
        case 4:
            ++current_y;
            break;

        case 5:
        case 6:
            --current_x;
            break;

        case 7:
        adjust_y:
            --current_y;
            break;
        }

        if (current_x >= 0 && current_y >= 0 && current_x <= map->map_width - 1 && current_y <= map->map_height - 1 &&
            (map->map_row_offset[current_y][current_x].terrain_type & 0x1F) == aType) {
            return 1;
        }
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

void TribeInformationAIModule::addEnemyInfluences(int ownerID, int targetID) {
    XYPoint minLOS;
    XYPoint maxLOS;
    XYPoint minRange;
    XYPoint maxRange;

    for (int i = 0; i < this->maxImportantObjectMemory; ++i) {
        if ((int)this->importantObjectMemory[i].owner != ownerID || this->importantObjectMemory[i].id == targetID)
            continue;

        RGE_Static_Object* object =
            this->md->object(this->importantObjectMemory[i].id);
        if (object == 0)
            continue;

        minLOS.x = (int)(object->world_x - object->master_obj->los);
        minLOS.y = (int)(object->world_y - object->master_obj->los);
        this->mapBound(minLOS);

        maxLOS.x = (int)(object->master_obj->los + object->world_x);
        maxLOS.y = (int)(object->master_obj->los + object->world_y);
        this->mapBound(maxLOS);

        for (int x = minLOS.x; x <= maxLOS.x; ++x) {
            for (int y = minLOS.y; y <= maxLOS.y; ++y) {
                int influence = aiPathSystem.lookupMisc(x, y) + 10;
                if (influence > 0xff)
                    influence = 0xff;
                aiPathSystem.setMisc(x, y, (unsigned char)influence);
            }
        }

        if (this->importantObjectMemory[i].range > 1.0f) {
            minRange.x = (int)(object->world_x - this->importantObjectMemory[i].range);
            minRange.y = (int)(object->world_y - this->importantObjectMemory[i].range);
            this->mapBound(minRange);

            maxRange.x = (int)(this->importantObjectMemory[i].range + object->world_x);
            maxRange.y = (int)(this->importantObjectMemory[i].range + object->world_y);
            this->mapBound(maxRange);

            for (int x = minRange.x; x <= maxRange.x; ++x) {
                for (int y = minRange.y; y <= maxRange.y; ++y) {
                    int influence = aiPathSystem.lookupMisc(x, y) + 10;
                    if (influence > 0xff)
                        influence = 0xff;
                    aiPathSystem.setMisc(x, y, (unsigned char)influence);
                }
            }
        }
    }
}

void TribeInformationAIModule::addPriorAttackInfluences(int ownerID, int targetID) {
    XYPoint max;
    XYPoint min;
    int count;

    count = 0;
    if (this->maxAttackMemories > 0) {
        do {
            if (this->attackMemories[count].id != -1 && (int)this->attackMemories[count].targetOwner == ownerID &&
                (unsigned short)this->attackMemories[count].attackingOwner == this->md->player->id) {
                min.x = this->attackMemories[count].minX;
                min.y = this->attackMemories[count].minY;
                this->mapBound(min);

                max.x = this->attackMemories[count].maxX;
                max.y = this->attackMemories[count].maxY;
                this->mapBound(max);

                for (int x = min.x; x <= max.x; ++x) {
                    for (int y = min.y; y <= max.y; ++y) {
                        aiPathSystem.setMisc(x, y, 0x4B);
                    }
                }

                min.x = min.x - 5;
                min.y = min.y - 5;
                this->mapBound(min);
                max.x += 5;
                max.y += 5;
                this->mapBound(max);

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

ObjectMemory* TribeInformationAIModule::objectMemory(int id) {
    int index;
    ObjectMemory* memory;
    ObjectMemory* base;

    if (id != -1) {
        index = 0;
        if (0 < this->maxImportantObjectMemory) {
            base = this->importantObjectMemory;
            memory = base;
            while (index < this->maxImportantObjectMemory) {
                if (memory->id == id) {
                    return base + index;
                }
                index = index + 1;
                memory = memory + 1;
            }
            return 0;
        }
    }
    return 0;
}

ObjectMemory* TribeInformationAIModule::addObjectMemory(RGE_Static_Object* obj) {
    if (obj == 0) return 0;
    return addObjectMemory(obj->id, obj->master_obj->id, obj->master_obj->object_group, (int)obj->world_x,
                           (int)obj->world_y, (int)obj->world_z, obj->owner->id, (int)obj->hp, 0, 0,
                           obj->damageCapability(), obj->rateOfFire(), obj->weaponRange(), obj);
}

ObjectMemory* TribeInformationAIModule::addObjectMemory(
    int id, short type, short group, unsigned char x, unsigned char y,
    unsigned char z, unsigned char owner, short hp, int attempts,
    unsigned char kills, float damage, float rate, float weaponRange,
    RGE_Static_Object* object) {
    int emptyIndex = -1;
    int index = 0;

    if (this->maxImportantObjectMemory > 0) {
        do {
            if (this->importantObjectMemory[index].id == id) {
                this->importantObjectMemory[index].id = id;
                this->importantObjectMemory[index].type = type;
                this->importantObjectMemory[index].group = group;
                this->importantObjectMemory[index].x = x;
                this->importantObjectMemory[index].y = y;
                this->importantObjectMemory[index].z = z;
                this->importantObjectMemory[index].owner = owner;
                this->importantObjectMemory[index].hitPoints = hp;
                this->importantObjectMemory[index].attackAttempts = attempts;
                this->importantObjectMemory[index].kills = kills;
                this->importantObjectMemory[index].damageCapability = damage;
                this->importantObjectMemory[index].rateOfFire = rate;
                this->importantObjectMemory[index].range = weaponRange;
                return this->importantObjectMemory + index;
            }
            if (this->importantObjectMemory[index].id == -1 && emptyIndex == -1) {
                emptyIndex = index;
            }
            index++;
        } while (index < this->maxImportantObjectMemory);
    }

    if (object != 0) {
        unsigned char controllingPlayer =
            ((TRIBE_World*)this->md->player->world)->controllingComputerPlayer;
        if (this->md->tacticalAI.strategicNumber(201) == 1 && (controllingPlayer == this->md->player->id ||
             controllingPlayer == 0xff) && object->owner->id > 0 && object->owner->computerPlayer() == 0 &&
            rge_base_game->singlePlayerGame() == 1) {
            int unitType = this->convertUnitToIntType(object);
            if (unitType != -1) {
                this->unitHistory[unitType]++;
            }
        }
    }

    if (emptyIndex == -1) {
        ObjectMemory* expanded = (ObjectMemory*)operator new(this->maxImportantObjectMemory * sizeof(ObjectMemory) * 2);
        if (expanded == 0) {
            return 0;
        }

        index = 0;
        if (this->maxImportantObjectMemory > 0) {
            do {
                expanded[index].id = this->importantObjectMemory[index].id;
                expanded[index].type = this->importantObjectMemory[index].type;
                expanded[index].group = this->importantObjectMemory[index].group;
                expanded[index].x = this->importantObjectMemory[index].x;
                expanded[index].y = this->importantObjectMemory[index].y;
                expanded[index].z = this->importantObjectMemory[index].z;
                expanded[index].owner = this->importantObjectMemory[index].owner;
                expanded[index].hitPoints = this->importantObjectMemory[index].hitPoints;
                expanded[index].attackAttempts = this->importantObjectMemory[index].attackAttempts;
                expanded[index].kills = this->importantObjectMemory[index].kills;
                expanded[index].damageCapability = this->importantObjectMemory[index].damageCapability;
                expanded[index].rateOfFire = this->importantObjectMemory[index].rateOfFire;
                expanded[index].range = this->importantObjectMemory[index].range;
                index++;
            } while (index < this->maxImportantObjectMemory);
        }

        if (index < this->maxImportantObjectMemory * 2) {
            do {
                expanded[index].id = -1;
                expanded[index].type = -1;
                expanded[index].group = -1;
                expanded[index].x = 0;
                expanded[index].y = 0;
                expanded[index].z = 0;
                expanded[index].owner = 0;
                expanded[index].hitPoints = 0;
                expanded[index].attackAttempts = 0;
                expanded[index].kills = 0;
                expanded[index].damageCapability = 0.0f;
                expanded[index].rateOfFire = 0.0f;
                expanded[index].range = 0.0f;
                index++;
            } while (index < this->maxImportantObjectMemory * 2);
        }

        operator delete(this->importantObjectMemory);
        this->importantObjectMemory = expanded;
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
        this->importantObjectMemory[this->maxImportantObjectMemory].damageCapability = damage;
        this->importantObjectMemory[this->maxImportantObjectMemory].rateOfFire = rate;
        this->importantObjectMemory[this->maxImportantObjectMemory].range = weaponRange;

        index = this->maxImportantObjectMemory;
        this->maxImportantObjectMemory *= 2;
        return this->importantObjectMemory + index;
    }

    this->importantObjectMemory[emptyIndex].id = id;
    this->importantObjectMemory[emptyIndex].type = type;
    this->importantObjectMemory[emptyIndex].group = group;
    this->importantObjectMemory[emptyIndex].x = x;
    this->importantObjectMemory[emptyIndex].y = y;
    this->importantObjectMemory[emptyIndex].z = z;
    this->importantObjectMemory[emptyIndex].owner = owner;
    this->importantObjectMemory[emptyIndex].hitPoints = hp;
    this->importantObjectMemory[emptyIndex].attackAttempts = attempts;
    this->importantObjectMemory[emptyIndex].kills = kills;
    this->importantObjectMemory[emptyIndex].damageCapability = damage;
    this->importantObjectMemory[emptyIndex].rateOfFire = rate;
    this->importantObjectMemory[emptyIndex].range = weaponRange;
    return this->importantObjectMemory + emptyIndex;
}

int TribeInformationAIModule::addImportantObject(RGE_Static_Object* oObj, int addedFromAlliedCP) {
    int oType;
    int marked;
    int id;
    int i;

    if (oObj != 0 && oObj->id >= 0) {
        oType = oObj->master_obj->object_group;
        if (importantObject(oType) != 0) {
            RGE_Game_World* world = this->md->player->world;
            int ownerID = oObj->owner->id;
            if (addedFromAlliedCP == 0 && ownerID > 0 && this->md->player->isEnemy(ownerID) != 0 && world->player_num > 3 && this->md->tacticalAI.strategicNumber(0xC2) == 1) {
                for (i = 1; i < world->player_num; ++i) {
                    if (i != this->md->player->id) {
                        RGE_Player* other = world->players[i];
                        if (other->computerPlayer() != 0 && this->md->player->isAlly(i) != 0 && other->isAlly(this->md->player->id) != 0) {
                            static_cast<TRIBE_Player*>(other)->playerAI->informationAI
                                .addImportantObject(oObj, 1);
                        }
                    }
                }
            }

            marked = checkDefend(oObj);
            id = oObj->id;
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
                id = oObj->id;
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
                    addResourceObject(oObj);
                } else if (importantMisc(oType) == 1) {
                    id = oObj->id;
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
                addObjectMemory(oObj);
            }
            return 1;
        }
    }
    return 0;
}

int TribeInformationAIModule::addImportantObject(int oID) {
    RGE_Static_Object* obj = this->md->object(oID);
    return this->addImportantObject(obj, 0);
}

int TribeInformationAIModule::importantObject(int oType) {
    if (importantUnit(oType) == 0) {
        if (importantResource(oType) == 0) {
            if (importantMisc(oType) == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int TribeInformationAIModule::importantUnit(int oType) {
    if (oType != 0 && oType != 3 && oType != 4 && oType != 0x18 &&
        oType != 0x15 && oType != 6 && oType != 0x19 && oType != 0x11 &&
        oType != 0x1A && oType != 0xC && oType != 0x23 && oType != 0x17 &&
        oType != 0x24 && oType != 0x1C && oType != 0x12 && oType != 0xD &&
        oType != 2 && oType != 0x14 && oType != 0x1B && oType != 0x16 && oType != 0x27) {
        return 0;
    }
    return 1;
}

int TribeInformationAIModule::importantResource(int oType) {
    if (oType == 0x1F || oType == 5 || oType == 0x21 || oType == 7 ||
        oType == 9 || oType == 8 || oType == 0x20 || oType == 0xF) {
        return 1;
    }
    return 0;
}

int TribeInformationAIModule::importantMisc(int oType) {
    if (oType != 1 && oType != 0x1E) {
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

int TribeInformationAIModule::isTower(RGE_Static_Object* obj) {
    short id = obj->master_obj->id;

    if ((id == 0x4F) || (id == 0xC7) || (id == 0x45) || (id == 0x17F) || (id == 0x17C)) {
        return 1;
    }
    return 0;
}

int TribeInformationAIModule::isBoatAccessible(RGE_Static_Object* unit, int target) {
    RGE_Static_Object* obj = this->md->object(target);
    if (obj == 0) {
        return 0;
    }
    if (obj->master_obj->object_group == 0x15 || obj->master_obj->object_group == 2 || obj->master_obj->object_group == 0x14 || obj->master_obj->object_group == 0x16 || obj->master_obj->id == 0x2d) {
        return 1;
    }
    return 0;
}

int TribeInformationAIModule::isLandAccessible(RGE_Static_Object* unit, int target) {
    RGE_Static_Object* object = md->object(target);
    if (object != 0) {
        short group = object->master_obj->object_group;
        if (group != 0x15 && group != 2 && group != 0x14 && group != 0x16) {
            return 1;
        }
    }
    return 0;
}

int TribeInformationAIModule::influenceCanPlaceStructure(BuildItem* bi) {
    return 1;
}

#include <math.h>
#include <stdlib.h>

#pragma intrinsic(sqrt)

ConstructionItem* TribeInformationAIModule::influencePlaceStructure(
    BuildItem* bi, int builderID, int alternateType, float alternateSize,
    char* alternateName, int alternateMinD, int alternateMaxD,
    int alternateX, int alternateY, PlacementState& placementState,
    unsigned long startTime) {
    RGE_Static_Object* protoBuilder = this->md->object(-1, -1, 4, -1, -1, -1, -1, -1, -1, -1);
    if (protoBuilder == 0) {
        placementState.active = 0;
        return 0;
    }

    int buildingType;
    float buildingSize;
    char* source_name;
    if (placementState.active == 1) {
        buildingType = placementState.buildingTypeID;
        buildingSize = placementState.buildingSize;
        source_name = placementState.buildingName;
    } else if (bi != 0) {
        buildingType = bi->typeID();
        buildingSize = bi->xSize();
        source_name = bi->name();
    } else {
        buildingType = alternateType;
        buildingSize = alternateSize;
        source_name = alternateName;
    }

    char buildingName[256];
    strncpy(buildingName, source_name, 255);

    int building_size_int = (int)buildingSize;
    int minimum_placement_value =
        building_size_int * building_size_int * 20;
    RGE_Master_Static_Object* masterObj =
        this->md->player->master_objects[buildingType];
    if (masterObj == 0) {
        placementState.active = 0;
        return 0;
    }

    RGE_Static_Object* townCenter = this->md->object(-1, 0x6d, -1, -1, -1, -1, -1, -1, -1, -1);
    int actual_builder_id = builderID;
    if (placementState.active == 1) {
        actual_builder_id = placementState.builderID;
    }
    RGE_Static_Object* builder = this->md->object(actual_builder_id);

    XYPoint centerPoint;
    if (bi == 0 && placementState.active != 1) {
        centerPoint.x = alternateX;
        centerPoint.y = alternateY;
    } else {
        RGE_Static_Object* center_object = townCenter;
        if (center_object == 0) {
            center_object = builder;
        }
        if (center_object == 0) {
            center_object = protoBuilder;
        }
        centerPoint.x = (int)center_object->world_x;
        centerPoint.y = (int)center_object->world_y;
    }

    int placementType = this->placementCode(buildingType);
    if (placementType == -1) {
        this->logCommonHistory("Invalid influence placement type id (%d), bombing.", buildingType);
        placementState.active = 0;
        return 0;
    }

    int minimumDistance;
    int maximumDistance;
    if (bi == 0 && placementState.active != 1) {
        minimumDistance = alternateMinD;
        maximumDistance = alternateMaxD;
        protoBuilder->lookupZone(alternateX, alternateY);
    } else {
        if (placementType == 1) {
            minimumDistance = 7;
            int age = 1;
            if (this->md->tacticalAI.inAge(2)) {
                age = 2;
            } else if (this->md->tacticalAI.inAge(3)) {
                age = 3;
            } else if (this->md->tacticalAI.inAge(4)) {
                age = 4;
            }
            maximumDistance =
                this->md->tacticalAI.strategicNumber(0x56) * age;
        } else if (placementType == 2) {
            minimumDistance = 4;
            maximumDistance =
                this->md->tacticalAI.strategicNumber(0x57);
        } else if (placementType == 3 || placementType == 4) {
            minimumDistance =
                this->md->tacticalAI.strategicNumber(0x49);
            maximumDistance =
                this->md->tacticalAI.strategicNumber(0x4a);
        } else {
            minimumDistance = 4;
            maximumDistance =
                this->md->tacticalAI.strategicNumber(0x4a);
        }

        RGE_Static_Object* zone_object = townCenter;
        if (zone_object == 0) {
            zone_object = protoBuilder;
        }
        zone_object->currentZone();
    }

    if (minimumDistance >= maximumDistance) {
        placementState.active = 0;
        return 0;
    }

    XYPoint min;
    XYPoint max;
    XYPoint minExclude;
    XYPoint maxExclude;
    min.x = centerPoint.x - maximumDistance;
    min.y = centerPoint.y - maximumDistance;
    this->mapBound(min);
    max.x = centerPoint.x + maximumDistance;
    max.y = centerPoint.y + maximumDistance;
    this->mapBound(max);
    minExclude.x = centerPoint.x - minimumDistance;
    minExclude.y = centerPoint.y - minimumDistance;
    this->mapBound(minExclude);
    maxExclude.x = centerPoint.x + minimumDistance;
    maxExclude.y = centerPoint.y + minimumDistance;
    this->mapBound(maxExclude);

    if (bi != 0 && placementState.active == 0) {
        BuildingLot* lot = this->availableLot(buildingType);
        if (lot != 0) {
            if (placementType == 4) {
                this->lastWallPosition2 = this->lastWallPosition;
                this->lastWallPosition.x = lot->x;
                this->lastWallPosition.y = lot->y;
            }

            ConstructionItem* result;
            if (buildingSize == 2.0f) {
                result = new ConstructionItem((float)lot->x, (float)lot->y, 1.0f, buildingSize,
                                              buildingSize, 1.0f, buildingType, buildingName);
            } else {
                result = new ConstructionItem((float)lot->x - (-0.5f), (float)lot->y - (-0.5f), 1.0f,
                                              buildingSize, buildingSize, 1.0f, buildingType, buildingName);
            }
            lot->status = 1;
            placementState.active = 0;
            return result;
        }
    }

    if (placementState.active == 0) {
        this->setupInfluenceMap(placementType, buildingType, centerPoint, min, max);
    }

    int randSelect;
    XYPoint bestPoint;
    int bestPointValue;
    int x;
    if (placementState.active == 0) {
        int random_range = this->md->tacticalAI.strategicNumber(0xa8);
        if (random_range > 0) {
            randSelect = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\taiinfmd.cpp", 2760) % random_range;
        } else {
            randSelect = 0;
        }
        bestPoint.x = -1;
        bestPoint.y = -1;
        bestPointValue = -1;
        x = min.x;
    } else {
        randSelect = placementState.randomInfluence;
        bestPoint = placementState.bestPoint;
        bestPointValue = placementState.bestPointValue;
        x = placementState.iterationX;
    }

    unsigned long availableTime =
        this->md->player->world->availableComputerPlayerUpdateTime;
    unsigned long now = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\taiinfmd.cpp", 2782);
    if (placementState.active == 0 && availableTime <= now - startTime) {
        placementState.buildingTypeID = buildingType;
        strncpy(placementState.buildingName, buildingName, 255);
        placementState.buildingSize = buildingSize;
        placementState.builderID = builderID;
        placementState.minimumDistance = minimumDistance;
        placementState.maximumDistance = maximumDistance;
        placementState.bestPoint.x = bestPoint.x;
        placementState.active = 1;
        placementState.bestPoint.y = bestPoint.y;
        placementState.bestPointValue = bestPointValue;
        placementState.iterationX = x;
        placementState.randomInfluence = randSelect;
        placementState.buildItem = bi;
        return 0;
    }

    int useExcludeRegion = 0;
    if (placementType == 4 || placementType == 3) {
        useExcludeRegion = 1;
    }

    int firstTimeThrough = 1;
    for (; x <= max.x; ++x) {
        if (firstTimeThrough) {
            firstTimeThrough = 0;
        } else {
            now = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\taiinfmd.cpp", 2838);
            if (availableTime <= now - startTime) {
                placementState.buildingTypeID = buildingType;
                strncpy(placementState.buildingName, buildingName, 255);
                placementState.buildingSize = buildingSize;
                placementState.builderID = builderID;
                placementState.minimumDistance = minimumDistance;
                placementState.maximumDistance = maximumDistance;
                placementState.bestPoint.x = bestPoint.x;
                placementState.active = 1;
                placementState.bestPoint.y = bestPoint.y;
                placementState.bestPointValue = bestPointValue;
                placementState.iterationX = x;
                placementState.randomInfluence = randSelect;
                placementState.buildItem = bi;
                return 0;
            }
        }

        for (int y = min.y; y <= max.y; ++y) {
            if (useExcludeRegion == 1 && x >= minExclude.x && x <= maxExclude.x && y >= minExclude.y && y <= maxExclude.y) {
                continue;
            }

            XYPoint minClear;
            XYPoint maxClear;
            if (buildingSize == 5.0f) {
                minClear.x = x - 2;
                minClear.y = y - 2;
                maxClear.x = x + 2;
                maxClear.y = y + 2;
            } else if (buildingSize == 3.0f) {
                if (placementType == 6 || placementType == 3 || placementType == 4 || placementType == 1 ||
                    placementType == 2 || placementType == 8) {
                    minClear.x = x - 1;
                    minClear.y = y - 1;
                    maxClear.x = x + 1;
                    maxClear.y = y + 1;
                } else {
                    minClear.x = x - 2;
                    minClear.y = y - 2;
                    maxClear.x = x + 2;
                    maxClear.y = y + 2;
                }
            } else if (buildingSize == 2.0f) {
                if (placementType == 6 || placementType == 3 || placementType == 4) {
                    minClear.x = x - 1;
                    minClear.y = y - 1;
                    maxClear.x = x;
                    maxClear.y = y;
                } else {
                    minClear.x = x - 2;
                    minClear.y = y - 2;
                    maxClear.x = x + 1;
                    maxClear.y = y + 1;
                }
            } else if (buildingSize == 1.0f) {
                if (placementType == 6 || placementType == 3 || placementType == 4) {
                    minClear.x = x;
                    minClear.y = y;
                    maxClear.x = x;
                    maxClear.y = y;
                } else {
                    minClear.x = x - 1;
                    minClear.y = y - 1;
                    maxClear.x = x + 1;
                    maxClear.y = y + 1;
                }
            } else {
                this->logCommonHistory("    Unsupported building size (%d x %d), failing.", buildingSize, buildingSize);
                placementState.active = 0;
                return 0;
            }

            if (this->mapBound(minClear) == 1 || this->mapBound(maxClear) == 1) {
                continue;
            }

            int blockingObject = -1;
            if (masterObj->check_placement(this->md->player, (float)x - (-0.5f),
                                           (float)y - (-0.5f), &blockingObject, 1, 1, 1, 1, 1, 1) != 0) {
                continue;
            }

            int basePlacementTotal = 0;
            int blocked = 0;
            for (int clearX = minClear.x; clearX <= maxClear.x && blocked == 0; ++clearX) {
                for (int clearY = minClear.y; clearY <= maxClear.y && blocked == 0; ++clearY) {
                    int value = iMap.lookupValue(clearX, clearY);
                    if (value == 0xff) {
                        blocked = 1;
                    } else {
                        basePlacementTotal += value;
                    }
                }
            }
            if (blocked != 0) {
                continue;
            }

            if (placementType == 4 || placementType == 6) {
                int old_connection_count = iMap.connectionCountValue;
                int connection_count = iMap.connectionsIncluding(minClear, maxClear, 0xff, 0xff, 1, 0, 1);
                int connections_added =
                    connection_count - old_connection_count;
                if (placementType == 4 && connections_added > 6) {
                    continue;
                }
                basePlacementTotal *= connections_added;
            }

            if (placementType == 4) {
                XYPoint newPosition;
                newPosition.x = x;
                newPosition.y = y;
                if (this->lastWallPosition.x != -1 && this->isNextTo(this->lastWallPosition, newPosition, 0) == 0) {
                    basePlacementTotal /= 2;
                }

                int facet = this->facetTo(this->lastWallPosition, newPosition);
                if (facet % 2 == 1) {
                    basePlacementTotal *= 3;
                }
                if (this->facetTo(this->lastWallPosition2, this->lastWallPosition) == facet) {
                    basePlacementTotal *= 3;
                }

                int delta_x = abs(this->lastWallPosition.x - centerPoint.x);
                int delta_y = abs(this->lastWallPosition.y - centerPoint.y);
                if (delta_y < delta_x) {
                    if (facet == 1 || facet == 5) {
                        basePlacementTotal *= 3;
                    }
                } else if (delta_x < delta_y) {
                    if (facet == 3 || facet == 7) {
                        basePlacementTotal *= 3;
                    }
                }
            } else if (placementType == 1 || placementType == 2) {
                if (this->undesirableLot(buildingType, (unsigned char)x, (unsigned char)y, 10) == 1) {
                    basePlacementTotal /= 10;
                }
            } else if (placementType != 6) {
                if (this->undesirableLot(buildingType, (unsigned char)x, (unsigned char)y, building_size_int) == 1) {
                    basePlacementTotal /= 10;
                }
            }

            if (placementType == 1 || placementType == 2) {
                int delta_x = x - centerPoint.x;
                int delta_y = y - centerPoint.y;
                int distance = (int)sqrt((double)(delta_x * delta_x + delta_y * delta_y));
                distance -= 10;
                if (distance > 0) {
                    int adjusted_total = basePlacementTotal - distance / 5;
                    if (adjusted_total > minimum_placement_value) {
                        basePlacementTotal = adjusted_total;
                    }
                }
            }

            if (bestPointValue == -1 || bestPointValue < basePlacementTotal + randSelect) {
                if (basePlacementTotal <= bestPointValue) {
                    randSelect /= 2;
                }
                bestPoint.x = x;
                bestPoint.y = y;
                bestPointValue = basePlacementTotal;
            }
        }
    }

    if (bestPointValue != -1 && (bestPointValue > minimum_placement_value || placementType != 2) &&
        (bestPointValue > minimum_placement_value || placementType != 1)) {
        if (placementType == 4) {
            this->lastWallPosition2 = this->lastWallPosition;
            this->lastWallPosition = bestPoint;
        }

        if (bi == 0 && placementState.active != 1) {
            this->storeLot(buildingType, (unsigned char)bestPoint.x, (unsigned char)bestPoint.y, 0);
            placementState.active = 0;
            return (ConstructionItem*)1;
        }

        ConstructionItem* result;
        if (buildingSize == 2.0f) {
            result = new ConstructionItem((float)bestPoint.x, (float)bestPoint.y, 1.0f,
                                          buildingSize, buildingSize, 1.0f, buildingType, buildingName);
        } else {
            result = new ConstructionItem((float)bestPoint.x - (-0.5f), (float)bestPoint.y - (-0.5f), 1.0f,
                                          buildingSize, buildingSize, 1.0f, buildingType, buildingName);
        }
        this->storeLot(buildingType, (unsigned char)bestPoint.x, (unsigned char)bestPoint.y, 1);
        placementState.active = 0;
        return result;
    }

    if (placementType == 4) {
        this->lastWallPosition2 = this->lastWallPosition;
        this->lastWallPosition.x = -1;
        this->lastWallPosition.y = -1;
    }
    placementState.active = 0;
    return 0;
}

void TribeInformationAIModule::addObject(RGE_Static_Object* obj) {
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

        if (this->isBuilding(object) == 1) {
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

            short type = object->master_obj->id;
            if (type == 0x6d || type == 0x67 || type == 0x44) {
                this->updateAllResourceDropsites();
            }
            if (object->master_obj->id == 0x32) {
                this->addResourceObject(object);
            }
        }
    }
}

void TribeInformationAIModule::removeObject(int objID) {
    int idx;
    int* ptr;

    idx = 0;
    while (idx < playerBuildings.maximumSizeValue) {
        if (playerBuildings.value[idx] == objID)
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
        if (playerObjects.value[idx] == objID)
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

    RGE_Static_Object* obj = md->object(objID);
    if (obj != 0) {
        ObjectMemory* mem = objectMemory(objID);
        if (mem != 0) {
            unsigned char owner_id = *(unsigned char*)(*(int*)((char*)obj + 0x0C) + 0x4A);
            mem->owner = owner_id;
        }
    }
}

ObjectMemory* TribeInformationAIModule::objectToAttackWithPlay(
    int ownerID, int* soldiers, int numSoldiers, int& playToRun,
    int* playUnits, int& numberPlayUnits, int& playCommander) {
    if (numSoldiers == 0) {
        return 0;
    }

    ObjectMemory* target = this->objectToAttackByGroup2(ownerID, soldiers, numSoldiers);
    if (target == 0) {
        return 0;
    }

    RGE_Game_World* world = this->md->player->world;
    AIPlayBook* playbook = world->playbook;
    playToRun = -1;

    int i = 0;
    while (i < playbook->numberPlaysValue) {
        AIPlay* play = playbook->play(i);
        if (play != 0 && play->humanPlay() != 1) {
            AIPlayStatus playStatus;
            playStatus.playNumberValue = i;
            play->fillGroups(&playStatus, soldiers, numSoldiers, world);

            if (playStatus.deviationValue == 0) {
                int invalid = 0;
                int phaseIndex = 0;
                while (phaseIndex < 10) {
                    if (invalid != 0) {
                        break;
                    }

                    int commandIndex = 0;
                    while (commandIndex < 5) {
                        if (invalid != 0) {
                            break;
                        }

                        AIPlayPhaseCommand* command =
                            play->phase(phaseIndex)->command(commandIndex);
                        if (command->type() == 1) {
                            int x = command->value1() + target->x;
                            int y = command->value2() + target->y;

                            if (x < 0 || y < 0 || x >= this->mapXSizeValue || y >= this->mapYSizeValue) {
                                invalid = 1;
                            }
                            if (this->inRangeOfUnits(ownerID, x, y, 0) == 1) {
                                invalid = 1;
                            }
                        }
                        ++commandIndex;
                    }
                    ++phaseIndex;
                }

                if (invalid == 0) {
                    int variation = this->calculatePlayVariation(i);
                    int randomValue =
                        debug_rand((char*)"C:\\msdev\\work\\age1_x1\\taiinfmd.cpp", 3401) % 50;
                    int rating = 0;
                    int playType = play->typeValue;
                    if (playType == 1) {
                        rating = this->md->tacticalAI.strategicNumber(0xBD);
                    } else if (playType == 2) {
                        rating = this->md->tacticalAI.strategicNumber(0xC6);
                    } else if (playType == 3) {
                        rating = this->md->tacticalAI.strategicNumber(0xC7);
                    }

                    rating += (100 - play->deathPercentageValue + variation) * 2;
                    rating += randomValue;
                    if (playToRun == -1 || rating > 0) {
                        playToRun = i;
                        playStatus.copyUnits(playUnits, numberPlayUnits);
                        randomValue = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\taiinfmd.cpp", 3434);
                        playCommander = playUnits[randomValue % numberPlayUnits];
                    }
                }
            }
        }

        ++i;
    }

    if (playToRun == -1) {
        return 0;
    }

    this->playHistory[playToRun]++;
    return target;
}

#include <math.h>

ObjectMemory* TribeInformationAIModule::objectToAttack(
    int ownerID, int ignoreSiegeTargets, int ignoreBoatTargets, int unitID,
    int& validAttack) {
    ObjectMemory* wonder = this->wonderToAttack(-1);
    if (wonder != 0) {
        validAttack = 1;
        return wonder;
    }

    RGE_Static_Object* unit = this->md->object(unitID);
    if (unit == 0 || unit->unitAI() == 0) {
        return 0;
    }

    unsigned char unitZone = unit->currentZone();
    int siegeWeapon = 0;
    if (unit->master_obj->id == 0x23 || unit->master_obj->id == 0x24 || unit->master_obj->id == 0x0B) {
        siegeWeapon = 1;
    }
    int boatWeapon = this->isBoat(unit);
    int unitIsPriest = unit->master_obj->object_group == 0x12;

    int numberNonSiegeTargets;
    int numberNonBoatTargets;
    ObjectMemory oLimits = this->findObjectMemoryLimits(ownerID, unitID, numberNonSiegeTargets, numberNonBoatTargets);

    ObjectMemory* bestObject = 0;
    int bestAttackValue = -1;
    int i = 0;
    if (this->maxImportantObjectMemory > 0) {
        do {
            ObjectMemory* memory = &this->importantObjectMemory[i];
            if ((int)memory->owner == ownerID) {
                RGE_Static_Object* tempObj = this->md->object(memory->id);
                if (tempObj != 0 && tempObj->object_state <= 2) {
                    float potentialDamageTakenPerSecond = this->damagePerSecond(unitID, (int)tempObj->world_x,
                                                                                (int)tempObj->world_y);
                    float object_damage =
                        tempObj->damageCapability(unit) / unit->rateOfFire();

                    float timeToBeKilled;
                    if (potentialDamageTakenPerSecond > 0.0f) {
                        timeToBeKilled = unit->hp / potentialDamageTakenPerSecond;
                    } else {
                        timeToBeKilled = -1.0f;
                    }

                    float timeToKill;
                    if (object_damage > 0.0f) {
                        timeToKill = (float)memory->hitPoints / object_damage;
                    } else {
                        timeToKill = -1.0f;
                    }

                    if (siegeWeapon == 0 && ignoreSiegeTargets != 0) {
                        int object_group = tempObj->master_obj->object_group;
                        if ((object_group == 3 || object_group == 0x1B) && numberNonSiegeTargets > 0) {
                            goto next_object;
                        }
                    }

                    if (boatWeapon == 0 && ignoreBoatTargets != 0) {
                        RGE_Master_Static_Object* object_master =
                            tempObj->master_obj;
                        int boat_target = object_master->id == 0x2D;
                        if (boat_target == 0) {
                            int object_group = object_master->object_group;
                            boat_target = object_group == 2 ||
                                object_group == 0x15 || object_group == 0x16 ||
                                object_group == 0x14;
                        }
                        if (boat_target != 0 && numberNonBoatTargets > 0) {
                            goto next_object;
                        }
                    }

                    if (unitIsPriest != 0 && unit->unitAI()->canConvert(memory->id) == 0) {
                        goto next_object;
                    }

                    int object_x = (int)tempObj->world_x;
                    int dx = (int)memory->x - object_x;
                    if (dx < 0) {
                        dx = -dx;
                    }
                    int object_y = (int)tempObj->world_y;
                    int dy = (int)memory->y - object_y;
                    if (dy < 0) {
                        dy = -dy;
                    }
                    if ((dx > 5 || dy > 5) && this->md->player->visible->get_visible(object_x, object_y) != 0x0F) {
                        goto next_object;
                    }

                    dx = (int)memory->x - (int)unit->world_x;
                    dy = (int)memory->y - (int)unit->world_y;
                    int distance = (int)sqrt((float)(dx * dx + dy * dy));

                    int distanceRating;
                    if (oLimits.id != 0) {
                        distanceRating = 100 - distance * 100 / oLimits.id;
                    } else {
                        distanceRating = 100;
                    }

                    int hpRating;
                    if (oLimits.hitPoints != 0) {
                        hpRating = memory->hitPoints * 100 / oLimits.hitPoints;
                    } else {
                        hpRating = 100;
                    }

                    int killRating;
                    if (oLimits.kills != 0) {
                        killRating = memory->kills * 100 / oLimits.kills;
                    } else {
                        killRating = 100;
                    }

                    int dCRating;
                    if (oLimits.damageCapability == 0.0f) {
                        dCRating = 100;
                    } else {
                        dCRating = (int)(memory->damageCapability * 100.0f / oLimits.damageCapability);
                    }

                    int rangeRating;
                    int rOFRating;
                    if (memory->damageCapability > 0.0f) {
                        if (oLimits.range == 0.0f) {
                            rangeRating = 100;
                        } else {
                            rangeRating = (int)(memory->range * 100.0f / oLimits.range);
                        }
                        if (oLimits.rateOfFire == 0.0f) {
                            rOFRating = 100;
                        } else {
                            rOFRating = 100 - (int)(memory->rateOfFire * 100.0f / oLimits.rateOfFire);
                        }
                    } else {
                        rangeRating = 0;
                        rOFRating = 0;
                    }

                    int randomRating = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\taiinfmd.cpp", 3638) % 100;
                    int specialRating1 =
                        memory->type == this->md->tacticalAI.strategicNumber(0x6A);
                    int specialRating2 =
                        memory->type == this->md->tacticalAI.strategicNumber(0x6B);
                    int specialRating3 =
                        memory->type == this->md->tacticalAI.strategicNumber(0x6C);
                    int zoneRating = unitZone == unit->lookupZone((int)tempObj->world_x, (int)tempObj->world_y);

                    RGE_Master_Static_Object* object_master = tempObj->master_obj;
                    int rating_object_group = object_master->object_group;

                    int siegeRating;
                    if (rating_object_group == 3 || rating_object_group == 0x1B) {
                        siegeRating = siegeWeapon != 0 ? 1 : -1;
                    } else {
                        siegeRating = siegeWeapon != 0 ? -1 : 1;
                    }

                    int boatRating;
                    if (object_master->id == 0x2D || rating_object_group == 2 || rating_object_group == 0x15 ||
                        rating_object_group == 0x16 || rating_object_group == 0x14) {
                        boatRating = boatWeapon != 0 ? 1 : -1;
                    } else {
                        boatRating = boatWeapon != 0 ? -1 : 1;
                    }

                    int attack_value =
                        this->md->tacticalAI.strategicNumber(0x59) *
                        memory->attackAttempts;
                    attack_value +=
                        this->md->tacticalAI.strategicNumber(0x90) * boatRating;
                    attack_value +=
                        this->md->tacticalAI.strategicNumber(0x7B) * siegeRating;
                    attack_value +=
                        this->md->tacticalAI.strategicNumber(0x7A) * zoneRating;
                    attack_value +=
                        this->md->tacticalAI.strategicNumber(0x50) * killRating;
                    attack_value +=
                        this->md->tacticalAI.strategicNumber(0x53) * randomRating;
                    attack_value +=
                        this->md->tacticalAI.strategicNumber(0x4D) * distanceRating;
                    attack_value +=
                        this->md->tacticalAI.strategicNumber(0x6F) * specialRating3;
                    attack_value +=
                        this->md->tacticalAI.strategicNumber(0x5A) * rangeRating;
                    attack_value +=
                        this->md->tacticalAI.strategicNumber(0x4E) * hpRating;
                    attack_value +=
                        this->md->tacticalAI.strategicNumber(0x4F) *
                        dCRating;
                    attack_value +=
                        this->md->tacticalAI.strategicNumber(0x52) *
                        rOFRating;
                    attack_value +=
                        this->md->tacticalAI.strategicNumber(0x6E) * specialRating2;
                    attack_value +=
                        this->md->tacticalAI.strategicNumber(0x6D) * specialRating1;

                    if ((timeToKill > timeToBeKilled && timeToBeKilled != -1.0f) || timeToKill == -1.0f) {
                        attack_value = 1;
                    }

                    if (bestObject == 0 || attack_value > bestAttackValue) {
                        bestObject = memory;
                        bestAttackValue = attack_value;
                        validAttack = 1;
                    }
                }
            }

next_object:
            ++i;
        } while (i < this->maxImportantObjectMemory);
    }
    return bestObject;
}

#include <math.h>

ObjectMemory* TribeInformationAIModule::objectToAttackByGroup(
    int ownerID, TacticalAIGroup* group, AttackState& attackState,
    unsigned long startTime) {
    RGE_Static_Object* commanderObj = this->md->object(group->commander());
    if (commanderObj == 0 || commanderObj->unitAI() == 0) {
        attackState.active = 0;
        return 0;
    }

    unsigned char commanderZone = commanderObj->currentZone();
    int commanderIsPriest =
        commanderObj->master_obj->object_group == 0x12;
    int commanderIsBoat = this->isBoat(commanderObj) == 1;

    if (attackState.active == 0 && group->objectsToDestroyOwnerValue == ownerID && group->numberObjectsToDestroyValue > 0 &&
        group->objectsToDestroyCommanderZoneValue == commanderZone) {
        int last = group->numberObjectsToDestroyValue - 1;
        int targetID = group->objectToDestroy(last);
        RGE_Static_Object* oTDObject = this->md->object(targetID);

        if (oTDObject != 0 && this->md->player->isEnemy(oTDObject->owner->id) == 1 && oTDObject->object_state <= 2) {
            int pathIndex = group->numberObjectsToDestroyValue - 1;
            if (commanderObj->canPath(group->objectToDestroy(pathIndex), commanderObj->weaponRange(), 0, 1, -1, -1) == 1) {
                targetID = group->objectToDestroy(group->numberObjectsToDestroyValue - 1);
                group->numberObjectsToDestroyValue = 0;
                group->addObjectToDestroy(targetID);
                return this->objectMemory(targetID);
            }
        }

        int i = 0;
        if (group->numberObjectsToDestroyValue - 1 > 0) {
            do {
                targetID = group->objectToDestroy(i);
                oTDObject = this->md->object(targetID);
                if (oTDObject != 0 && this->md->player->isEnemy(oTDObject->owner->id) == 1 &&
                    oTDObject->object_state <= 2 &&
                    commanderObj->canPath(group->objectToDestroy(i), commanderObj->weaponRange(), 0, 1, -1, -1) == 1) {
                    return this->objectMemory(group->objectToDestroy(i));
                }
                ++i;
            } while (i < group->numberObjectsToDestroyValue - 1);
        }
    }

    if (attackState.active == 0) {
        ObjectMemory* wonder = this->wonderToAttack(-1);
        if (wonder != 0) {
            unsigned char wonderZone = commanderObj->lookupZone((int)wonder->x, (int)wonder->y);
            if (wonderZone != commanderZone && commanderIsBoat == 0) {
                return wonder;
            }

            if (commanderObj->canPath(wonder->id, commanderObj->weaponRange(), 0, 1, -1, -1) == 1) {
                group->numberObjectsToDestroyValue = 0;
                group->addObjectToDestroy(wonder->id);
                group->objectsToDestroyOwnerValue = wonder->owner;
                group->objectsToDestroyCommanderZoneValue = commanderZone;
                return wonder;
            }

            ManagedArray<int> wallObjects;
            if (commanderObj->canPathWithObstructions(wonder->id, commanderObj->weaponRange(), 0, 1,
                                                      ownerID, 0x1b, wallObjects) == 1) {
                group->numberObjectsToDestroyValue = 0;
                int wallIndex = 0;
                if (wallObjects.numberValue > 0) {
                    do {
                        if (this->md->object(wallObjects[wallIndex]) != 0) {
                            this->addImportantObject(wallObjects[wallIndex]);
                            group->addObjectToDestroy(wallObjects[wallIndex]);
                        }
                        ++wallIndex;
                    } while (wallIndex < wallObjects.numberValue);
                }
                group->addObjectToDestroy(wonder->id);
                unsigned char wonderOwner = wonder->owner;
                group->objectsToDestroyCommanderZoneValue = commanderZone;
                group->objectsToDestroyOwnerValue = wonderOwner;
                return wonder;
            }
        }

        attackState.bestTargetID = -1;
        attackState.bestTargetValue = -1.0f;
        attackState.bestTargetMemoryIndex = -1;
        attackState.iterationIndex = 0;
        attackState.attackGroupID = -1;
        attackState.playID = -1;
        attackState.phase = 0;
        attackState.bestNonWallTargetID = -1;
        attackState.bestNonWallTargetValue = -1.0f;
        attackState.bestNonWallTargetMemoryIndex = -1;
        attackState.active = 1;
    }

    int i = attackState.iterationIndex;
    if (i < this->maxImportantObjectMemory) {
        do {
            if (attackState.iterationIndex < i) {
                unsigned long availableTime =
                    this->md->player->world->availableComputerPlayerUpdateTime;
                if (debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\taiinfmd.cpp", 3930) - startTime >= availableTime) {
                    attackState.iterationIndex = i;
                    return 0;
                }
            }

            if ((int)this->importantObjectMemory[i].owner == ownerID) {
                RGE_Static_Object* oTDObject = this->md->object(this->importantObjectMemory[i].id);
                if (oTDObject != 0 && oTDObject->object_state <= 2 && oTDObject->hp != 0.0f &&
                    (commanderIsBoat != 0 || this->isBoat(oTDObject) != 1)) {
                    unsigned char targetZone = commanderObj->lookupZone((int)oTDObject->world_x, (int)oTDObject->world_y);

                    if ((commanderIsBoat != 0 || this->importantObjectMemory[i].type != 0x2d ||
                         commanderZone == targetZone) && (attackState.phase != 0 ||
                         this->importantObjectMemory[i].group != 0x1b) && (attackState.phase != 1 ||
                         this->importantObjectMemory[i].group == 0x1b)) {
                        int targetX = (int)oTDObject->world_x;
                        int dx =
                            (int)this->importantObjectMemory[i].x - targetX;
                        if (dx < 0)
                            dx = -dx;

                        int targetY = (int)oTDObject->world_y;
                        int dy =
                            (int)this->importantObjectMemory[i].y - targetY;
                        if (dy < 0)
                            dy = -dy;

                        if ((dx <= 5 && dy <= 5) || this->md->player->visible->get_visible(targetX, targetY) == 0x0f) {
                            if (commanderIsPriest == 0 ||
                                commanderObj->unitAI()->canConvert(this->importantObjectMemory[i].id) != 0) {
                                float damageIPS = this->damageInflictedPerSecond(group, oTDObject);
                                float targetHitPoints = oTDObject->hp;
                                float timeTK = targetHitPoints / damageIPS;
                                float timeTBK = this->timeToBeKilled(group, oTDObject);

                                if (damageIPS != 0.0f && timeTBK != 0.0f) {
                                    float timeKillRatio =
                                        timeTBK / timeTK;

                                    dx =
                                         (int)this->importantObjectMemory[i].x -
                                         (int)commanderObj->world_x;
                                    dy =
                                         (int)this->importantObjectMemory[i].y -
                                         (int)commanderObj->world_y;
                                    float targetDistance = (float)sqrt((float)(dx * dx + dy * dy));
                                    if (targetDistance < 1.0f)
                                        targetDistance = 1.0f;

                                    float killsByTarget = (float)
                                        this->importantObjectMemory[i].kills;

                                    float targetRandomization;
                                    if (this->md->tacticalAI.strategicNumber(0x53) > 0) {
                                        int randomLimit =
                                            this->md->tacticalAI.strategicNumber(0x53);
                                        targetRandomization = (float)(debug_rand(
                                            (char*)"C:\\msdev\\work\\age1_x1\\taiinfmd.cpp", 4053) % randomLimit);
                                    } else {
                                        targetRandomization = 0.0f;
                                    }

                                    float attackAttemptFactor =
                                        (float)this->md->tacticalAI.strategicNumber(0x59) *
                                        this->importantObjectMemory[i]
                                            .attackAttempts;

                                    float zoneFactor;
                                    if (commanderZone == targetZone) {
                                        zoneFactor =
                                            (float)this->md->tacticalAI.strategicNumber(0x7a);
                                    } else {
                                        zoneFactor = 0.0f;
                                    }

                                    float inProgressFactor = 0.0f;
                                    if (this->md->tacticalAI.strategicNumber(0xb9) > 0) {
                                        int inProgressCount = 0;
                                        int unit_index = 0;
                                        if (group->numberUnits() > 0) {
                                            do {
                                                RGE_Static_Object* unit =
                                                    this->md->object(group->unit(unit_index));
                                                if (unit != 0 && unit->unitAI() != 0 && unit->unitAI()->currentTarget() ==
                                                    this->importantObjectMemory[i].id) {
                                                    ++inProgressCount;
                                                }
                                                ++unit_index;
                                            } while (unit_index < group->numberUnits());
                                        }
                                        inProgressFactor =
                                            (float)this->md->tacticalAI.strategicNumber(0xb9) * inProgressCount;
                                    }

                                    float miscFactor = 0.0f;
                                    if (attackState.phase == 1 && attackState.bestNonWallTargetID != -1) {
                                        ObjectMemory* nonWall =
                                            &this->importantObjectMemory[
                                                attackState.bestNonWallTargetMemoryIndex];
                                        dx = (int)this->importantObjectMemory[
                                                 i].x - (int)nonWall->x;
                                        dy = (int)this->importantObjectMemory[
                                                 i].y - (int)nonWall->y;
                                        float distance = (float)sqrt((float)(dx * dx + dy * dy));
                                        if (distance < 1.0f)
                                            miscFactor = 1000.0f;
                                        else
                                            miscFactor = 25000.0f / distance;
                                    }

                                    if (this->isUnitBuilding(oTDObject) == 1) {
                                        if (oTDObject->master_obj->id == 0x6d || oTDObject->master_obj->id == 0x2d)
                                            miscFactor -= (-200.0f);
                                        else
                                            miscFactor -= (-300.0f);
                                    }

                                    float overallRating =
                                        (float)this->md->tacticalAI.strategicNumber(0x50) * killsByTarget;
                                    overallRating =
                                        (float)this->md->tacticalAI.strategicNumber(0x4d) / targetDistance + overallRating;
                                    overallRating =
                                        (float)this->md->tacticalAI.strategicNumber(0xb8) * timeKillRatio + overallRating;
                                    overallRating += miscFactor;
                                    overallRating += inProgressFactor;
                                    overallRating += zoneFactor;
                                    overallRating += attackAttemptFactor;
                                    overallRating += targetRandomization;

                                    if (attackState.bestTargetID == -1 || overallRating > attackState.bestTargetValue) {
                                        if (attackState.phase == 0 && oTDObject->maximumSpeed() == 0.0f) {
                                            attackState.bestNonWallTargetID =
                                                this->importantObjectMemory[
                                                    i].id;
                                            attackState.bestNonWallTargetMemoryIndex =
                                                i;
                                            attackState.bestNonWallTargetValue =
                                                overallRating;
                                        }

                                        ManagedArray<int> wallObjects;
                                        int unobstructibleGroupID =
                                            attackState.phase == 0 ? 0x1b : -1;
                                        int canReach = 1;
                                        if (commanderZone == targetZone) {
                                            if (commanderObj->canPath(this->importantObjectMemory[i].id,
                                                                      commanderObj->weaponRange(), 0, 1, -1, -1) != 1 &&
                                                commanderObj->canPathWithObstructions(this->importantObjectMemory[i].id,
                                                                                      commanderObj->weaponRange(), 0, 1, ownerID, unobstructibleGroupID,
                                                                                      wallObjects) != 1) {
                                                canReach = 0;
                                            }
                                        }

                                        if (canReach != 0) {
                                            group->numberObjectsToDestroyValue = 0;
                                            int wallIndex = 0;
                                            if (wallObjects.numberValue > 0) {
                                                do {
                                                    if (this->md->object(wallObjects[wallIndex]) != 0) {
                                                        this->addImportantObject(wallObjects[wallIndex]);
                                                        group->addObjectToDestroy(wallObjects[wallIndex]);
                                                    }
                                                    ++wallIndex;
                                                } while (wallIndex < wallObjects.numberValue);
                                            }
                                            group->addObjectToDestroy(this->importantObjectMemory[i].id);
                                            unsigned char selectedOwner =
                                                this->importantObjectMemory[
                                                    i].owner;
                                            group->objectsToDestroyCommanderZoneValue =
                                                commanderZone;
                                            group->objectsToDestroyOwnerValue =
                                                selectedOwner;
                                            attackState.bestTargetID =
                                                this->importantObjectMemory[
                                                    i].id;
                                            attackState.bestTargetMemoryIndex =
                                                i;
                                            attackState.bestTargetValue = overallRating;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }

            ++i;
        } while (i < this->maxImportantObjectMemory);
    }

    if (attackState.bestTargetID != -1) {
        ++this->importantObjectMemory[attackState.bestTargetMemoryIndex]
              .attackAttempts;
        attackState.active = 0;
        return this->objectMemory(group->objectToDestroy(0));
    }

    if (attackState.phase == 0) {
        attackState.phase = 1;
        attackState.iterationIndex = 0;
    } else {
        attackState.active = 0;
    }
    return 0;
}

#include <math.h>

ObjectMemory* TribeInformationAIModule::objectToAttackByGroup2(
    int ownerID, int* soldiers, int numberSoldiers) {
    ObjectMemory* wonder = this->wonderToAttack(-1);
    if (wonder != 0) {
        return wonder;
    }

    if (numberSoldiers == 0) {
        return 0;
    }

    RGE_Static_Object* commanderObj = this->md->object(soldiers[0]);
    if (commanderObj == 0 || commanderObj->unitAI() == 0) {
        return 0;
    }

    unsigned char commanderZone = commanderObj->currentZone();
    int commanderIsPriest = 0;
    if (commanderObj->master_obj->object_group == 0x12) {
        commanderIsPriest = 1;
    }
    ObjectMemory* bestObject = 0;
    float bestAttackValue = -1.0f;

    int i = 0;
    if (this->maxImportantObjectMemory > 0) {
        do {
            ObjectMemory* memory = &this->importantObjectMemory[i];
            if ((int)memory->owner == ownerID) {
                RGE_Static_Object* target = this->md->object(memory->id);
                if (target != 0 && target->object_state <= 2 && target->hp != 0.0f) {
                    int targetX = (int)target->world_x;
                    int dx = (int)memory->x - targetX;
                    if (dx < 0) {
                        dx = -dx;
                    }

                    int targetY = (int)target->world_y;
                    int dy = (int)memory->y - targetY;
                    if (dy < 0) {
                        dy = -dy;
                    }

                    if ((dx <= 5 && dy <= 5) || this->md->player->visible->get_visible(targetX, targetY) == 0x0f) {
                        if (!commanderIsPriest || commanderObj->unitAI()->canConvert(memory->id)) {
                            float damageIPS = this->damageInflictedPerSecond(soldiers, numberSoldiers, target);
                            float timeKillRatio = target->hp / damageIPS;
                            float timeToKill = this->timeToBeKilled(soldiers, numberSoldiers, target);

                            if (damageIPS != 0.0f && timeToKill != 0.0f) {
                                timeKillRatio = timeToKill / timeKillRatio;

                                int commanderX =
                                    (int)memory->x - (int)commanderObj->world_x;
                                int commanderY =
                                    (int)memory->y - (int)commanderObj->world_y;
                                float targetDistance = (float)sqrt((double)(commanderX * commanderX +
                                                                            commanderY * commanderY));
                                if (targetDistance < 1.0f) {
                                    targetDistance = 1.0f;
                                }

                                float killsByTarget = (float)memory->kills;
                                float targetRandomization;
                                if (this->md->tacticalAI.strategicNumber(0x53) > 0) {
                                    int randomLimit =
                                        this->md->tacticalAI.strategicNumber(0x53);
                                    targetRandomization = (float)(debug_rand("C:\\msdev\\work\\age1_x1\\taiinfmd.cpp",
                                                                             4363) % randomLimit);
                                } else {
                                    targetRandomization = 0.0f;
                                }

                                float attackAttemptFactor =
                                    (float)this->md->tacticalAI.strategicNumber(0x59) *
                                    memory->attackAttempts;

                                float zoneFactor;
                                if (commanderObj->lookupZone((int)target->world_x, (int)target->world_y) == commanderZone) {
                                    zoneFactor = (float)this->md->tacticalAI.strategicNumber(0x7a);
                                } else {
                                    zoneFactor = 0.0f;
                                }

                                float inProgressFactor = 0.0f;
                                if (this->md->tacticalAI.strategicNumber(0xb9) > 0) {
                                    int inProgressCount = 0;
                                    int unitsRemaining = numberSoldiers;
                                    if (unitsRemaining > 0) {
                                        int* unitId = soldiers;
                                        do {
                                            RGE_Static_Object* unit =
                                                this->md->object(*unitId);
                                            if (unit != 0 && unit->unitAI() != 0 &&
                                                unit->unitAI()->currentTarget() == memory->id) {
                                                ++inProgressCount;
                                            }
                                            ++unitId;
                                            --unitsRemaining;
                                        } while (unitsRemaining != 0);
                                    }
                                    inProgressFactor =
                                        (float)this->md->tacticalAI.strategicNumber(0xb9) *
                                        inProgressCount;
                                }

                                float attackValue =
                                    (float)this->md->tacticalAI.strategicNumber(0xb8) *
                                    timeKillRatio;
                                attackValue =
                                    (float)this->md->tacticalAI.strategicNumber(0x4d) /
                                    targetDistance + attackValue;
                                attackValue =
                                    (float)this->md->tacticalAI.strategicNumber(0x50) *
                                    killsByTarget + attackValue + inProgressFactor +
                                    zoneFactor + attackAttemptFactor +
                                    targetRandomization;

                                if (bestObject == 0 || attackValue > bestAttackValue) {
                                    bestObject = memory;
                                    bestAttackValue = attackValue;
                                }
                            }
                        }
                    }
                }
            }
            ++i;
        } while (i < this->maxImportantObjectMemory);
    }

    return bestObject;
}

ObjectMemory* TribeInformationAIModule::objectToDefend(int unitID) {
    ObjectMemory* bestObject;
    int bestDefendValue;
    XYPoint objPoint;
    int i;
    int objectId;

    RGE_Static_Object* target = this->md->object(unitID);
    if (target == 0)
        return 0;

    bestObject = 0;
    bestDefendValue = -1;
    i = 0;

    if (this->maxImportantObjectMemory > 0) {
        do {
            objectId = this->importantObjectMemory[i].id;
            if (objectId != -1) {
                if (this->itemsToDefend.contains(objectId)) {
                    if (this->importantObjectMemory[i].attackAttempts <= 0) {
                        objPoint.x = (int)this->importantObjectMemory[i].x;
                        objPoint.y = (int)this->importantObjectMemory[i].y;

                        TacticalAIGroup* bestG =
                            this->md->tacticalAI.bestGroup(-1, 4, this->md->tacticalAI.strategicNumber(0x5C), objPoint, -1);

                        if (bestG == 0) {
                            int priority = this->defendPriority((int)this->importantObjectMemory[i].type,
                                                                (int)this->importantObjectMemory[i].group);
                            if (bestObject == 0 || bestDefendValue > priority) {
                                bestObject = &this->importantObjectMemory[i];
                                bestDefendValue = priority;
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

ObjectMemory* TribeInformationAIModule::higherPriorityObjectToDefend(int unitID, int oType, int oGroup) {
    RGE_Static_Object* unit = this->md->object(unitID);
    unsigned char currentZone;
    ObjectMemory* bestObject;
    if (unit == 0)
        return 0;

    currentZone = unit->currentZone();
    bestObject = 0;
    oGroup = this->defendPriority(oType, oGroup);
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
                                    if (currentZone != target->currentZone()) {
                                        XYPoint pt;
                                        pt.x = (int)target->world_x;
                                        pt.y = (int)target->world_y;
                                        if (unit->withinRangeOfZoneAtPoint(currentZone, unit->weaponRange(), pt) != 1)
                                            break;
                                    }
                                    int pri = this->defendPriority(this->importantObjectMemory[i].type,
                                                                   this->importantObjectMemory[i].group);
                                    if (oGroup > pri) {
                                        oGroup = pri;
                                        bestObject = &this->importantObjectMemory[i];
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
    return bestObject;
}

int TribeInformationAIModule::defendPriority(int oType, int oGroup) {
    switch (oType) {
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

    switch (oGroup) {
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

int TribeInformationAIModule::checkDefend(RGE_Static_Object* obj) {
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
            list->add(id);
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
            list->add(id);
        }
        return 1;
    }
    case 0x9f: {
        if (this->md->tacticalAI.strategicNumber(0x37) <= 0)
            goto checkDefend_fail;
        id = obj->id;
        {
            ManagedArray<int>* list = &this->itemsToDefend;
            list->add(id);
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
            list->add(id);
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
            (*list8)[list8->numberValue] = tmp;
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
            this->itemsToDefend[this->itemsToDefend.numberValue] = tmp;
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

ObjectMemory* TribeInformationAIModule::objectToTradeWith(int unitID) {
    RGE_Static_Object* unit = this->md->object(unitID);
    if (unit == 0)
        return 0;

    ObjectMemory* bestObject = 0;
    int bestDockDistance = 0;
    int i = 0;

    if (this->maxImportantObjectMemory > 0) {
        do {
            if (this->importantObjectMemory[i].id != -1 && this->importantObjectMemory[i].owner != this->md->player->id &&
                this->importantObjectMemory[i].type == 0x2D) {
                RGE_Static_Object* dock = this->md->object(this->importantObjectMemory[i].id);
                if (dock != 0 && dock->owner->attributes[9] > 0.0f) {
                    ObjectMemory* candidate = &this->importantObjectMemory[i];
                    int dx = (int)candidate->x - (int)unit->world_x;
                    int dy = (int)candidate->y - (int)unit->world_y;
                    int dist = dx * dx + dy * dy;
                    if (bestObject == 0 || dist < bestDockDistance) {
                        bestObject = candidate;
                        bestDockDistance = dist;
                    }
                }
            }
            i++;
        } while (i < this->maxImportantObjectMemory);
    }

    return bestObject;
}

int TribeInformationAIModule::findGatherPosition(
    XYPoint& centerPoint, int num, int landTroops, int desiredDistance,
    int maximumDistanceVariation, RGE_Static_Object* testUnit,
    XYPoint& rPoint) {
    XYPoint min;
    XYPoint max;
    XYPoint minExclude;
    XYPoint maxExclude;
    XYPoint cPosition;
    XYPoint lineCollisionPoint;
    int bestPointValue;
    int halfGroupDimension;
    int x;
    int y;

    if (desiredDistance <= maximumDistanceVariation)
        return 0;

    min.x = centerPoint.x - desiredDistance - maximumDistanceVariation;
    min.y = centerPoint.y - desiredDistance - maximumDistanceVariation;
    this->mapBound(min);

    max.x = centerPoint.x + maximumDistanceVariation + desiredDistance;
    max.y = centerPoint.y + maximumDistanceVariation + desiredDistance;
    this->mapBound(max);

    minExclude.x = centerPoint.x - desiredDistance + maximumDistanceVariation;
    minExclude.y = centerPoint.y - desiredDistance + maximumDistanceVariation;
    this->mapBound(minExclude);

    maxExclude.x = centerPoint.x - maximumDistanceVariation + desiredDistance;
    maxExclude.y = centerPoint.y - maximumDistanceVariation + desiredDistance;
    this->mapBound(maxExclude);

    this->setupInfluenceMap(0, -1, centerPoint, min, max);
    bestPointValue = -1;
    halfGroupDimension = this->groupInfluenceDimension(num) / 2;

    for (x = min.x; x <= max.x; ++x) {
        for (y = min.y; y <= max.y; ++y) {
            if (x < minExclude.x || maxExclude.x < x || y < minExclude.y || maxExclude.y < y) {
                XYPoint minClear;
                XYPoint maxClear;
                minClear.x = x - halfGroupDimension;
                minClear.y = y - halfGroupDimension;
                if (this->mapBound(minClear) == 1)
                    continue;

                maxClear.x = x + halfGroupDimension;
                maxClear.y = y + halfGroupDimension;
                if (this->mapBound(maxClear) == 1)
                    continue;

                int blocked = 0;
                int clearX = minClear.x;
                while (clearX < maxClear.x && blocked == 0) {
                    int clearY = minClear.y;
                    while (clearY < maxClear.y && blocked == 0) {
                        if (testUnit->passableTile((float)clearX, (float)clearY, 1) == 0)
                            blocked = 1;
                        ++clearY;
                    }
                    ++clearX;
                }

                if (blocked == 0) {
                    cPosition.x = x;
                    cPosition.y = y;
                    int score;
                    if (testUnit->canLinePath(cPosition, centerPoint, (float)desiredDistance, lineCollisionPoint, 1) == 0)
                        score = 0x40;
                    else
                        score = 0x80;

                    int influenceX = minClear.x;
                    while (influenceX <= maxClear.x && blocked == 0) {
                        int influenceY = minClear.y;
                        while (influenceY <= maxClear.y && blocked == 0) {
                            int value = iMap.lookupValue(influenceX, influenceY);
                            if (value == 0xff)
                                blocked = 1;
                            else
                                score += value;
                            ++influenceY;
                        }
                        ++influenceX;
                    }

                    if (blocked == 0 && (bestPointValue == -1 || bestPointValue < score)) {
                        rPoint.x = x;
                        rPoint.y = y;
                        bestPointValue = score;
                    }
                }
            }
        }
    }

    return bestPointValue != -1;
}

#include <stdlib.h>

void TribeInformationAIModule::setupInfluenceMap(
    int placementType, int buildingType, XYPoint& centerPoint,
    XYPoint& minArea, XYPoint& maxArea) {
    XYPoint min;
    XYPoint max;
    int x;
    int y;

    iMap.initialize(20);
    iMap.setUnchangeableLimit(0xff);

    this->md->buildAI.numberBuiltItemsOfType(0x44, 0);
    this->md->buildAI.numberBuiltItemsOfType(0x67, 0);

    min.x = 0;
    min.y = 0;
    max.x = this->mapXSizeValue;
    max.y = this->mapYSizeValue;

    if (placementType == 3 || placementType == 4 || placementType == 0) {
        int mapWidth = this->mapXSizeValue;
        int mapHeight = this->mapYSizeValue;
        int maxX = mapWidth - 5;
        int maxY = mapHeight - 5;
        for (x = 0; x < mapWidth; ++x) {
            for (y = 0; y < mapHeight; ++y) {
                if (x < 5 || x > maxX || y < 5 || y > maxY)
                    iMap.decrementValue(x, y, 10);
            }
        }
    }

    if (placementType == 1 || placementType == 2 || placementType == 9) {
        int resourceTypeToPlaceBy = this->resourceTypeToPlaceDropsiteBy(placementType);
        int resource_list;

        for (resource_list = 0; resource_list < 4; ++resource_list) {
            int resource_index;
            for (resource_index = 0; resource_index < this->numResources[resource_list]; ++resource_index) {
                ResourceMemory* memory =
                    &this->resources[resource_list][resource_index];
                if (memory->gone == 1)
                    continue;

                RGE_Static_Object* object = this->md->object(memory->id);
                if (object == 0)
                    continue;

                RGE_Master_Static_Object* master = object->master_obj;
                XYPoint rMin;
                XYPoint rMax;
                XYPoint position;
                float resYRadius = master->radius_y;

                rMin.x = (int)(object->world_x - master->radius_x - 1.0f);
                rMin.y = (int)(object->world_y - resYRadius - 1.0f);
                this->mapBound(rMin);
                rMax.x = (int)(resYRadius + object->world_x - (-1.0f));
                rMax.y = (int)(resYRadius + object->world_y - (-1.0f));
                this->mapBound(rMax);
                position.x = (int)object->world_x;
                position.y = (int)object->world_y;
                this->mapBound(position);

                if (placementType == 1 || placementType == 2)
                    iMap.setValue(position.x, position.y, 0xff);
                else
                    iMap.setValue(rMin.x, rMin.y, rMax.x, rMax.y, 0xff);

                short group = master->object_group;
                if (placementType == 1) {
                    if (group == 7) {
                        rMin.x -= 5;
                        rMin.y -= 5;
                        this->mapBound(rMin);
                        rMax.x += 5;
                        rMax.y += 5;
                        this->mapBound(rMax);
                        iMap.decrementValue(rMin.x, rMin.y, rMax.x, rMax.y, 0x80);
                    } else {
                        int applicable = 0;
                        if (resourceTypeToPlaceBy == -1)
                            applicable = 1;
                        else if (resourceTypeToPlaceBy == 3 && group == 0x20)
                            applicable = 1;
                        else if (resourceTypeToPlaceBy == 2 && group == 8)
                            applicable = 1;
                        else if (resourceTypeToPlaceBy == 1 && group == 0x0f)
                            applicable = 1;
                        else if (resourceTypeToPlaceBy == 0 && group != 0x20 && group != 8 && group != 0x0f)
                            applicable = 1;

                        if (applicable) {
                            rMin.x--;
                            rMin.y--;
                            this->mapBound(rMin);
                            rMax.x++;
                            rMax.y++;
                            this->mapBound(rMax);
                            iMap.incrementValue(rMin.x, rMin.y, rMax.x, rMax.y, 8);

                            rMin.x -= 3;
                            rMin.y -= 3;
                            this->mapBound(rMin);
                            rMax.x += 3;
                            rMax.y += 3;
                            this->mapBound(rMax);
                            iMap.incrementValue(rMin.x, rMin.y, rMax.x, rMax.y, 4);

                            rMin.x -= 5;
                            rMin.y -= 5;
                            this->mapBound(rMin);
                            rMax.x += 5;
                            rMax.y += 5;
                            this->mapBound(rMax);
                            iMap.incrementValue(rMin.x, rMin.y, rMax.x, rMax.y, 2);
                        }
                    }
                } else if (placementType == 2 && group == 7) {
                    rMin.x -= 3;
                    rMin.y -= 3;
                    this->mapBound(rMin);
                    rMax.x += 3;
                    rMax.y += 3;
                    this->mapBound(rMax);
                    iMap.incrementValue(rMin.x, rMin.y, rMax.x, rMax.y, 0x80);
                }
            }
        }
    }

    if (placementType == 1 || placementType == 2 || placementType == 3 ||
        placementType == 4 || placementType == 0 || placementType == 5 || placementType == 6 || placementType == 8) {
        int building_index;
        for (building_index = 0; building_index < this->playerBuildings.numberValue; ++building_index) {
            RGE_Static_Object* building =
                this->md->object(this->playerBuildings[building_index]);
            if (building == 0)
                continue;

            RGE_Master_Static_Object* master = building->master_obj;
            int buildingCode = this->placementCode(master->id);
            XYPoint bMin;
            XYPoint bMax;
            float bXRadius = master->radius_x;
            float bYRadius = master->radius_y;

            if (bXRadius == 2.5) {
                bMin.x = (int)building->world_x - 3;
                bMin.y = (int)building->world_y - 3;
                bMax.x = (int)building->world_x + 3;
                bMax.y = (int)building->world_y + 3;
            } else if (bXRadius == 1.5) {
                if (buildingCode == 6) {
                    bMin.x = (int)building->world_x - 1;
                    bMin.y = (int)building->world_y - 1;
                    bMax.x = (int)building->world_x + 1;
                    bMax.y = (int)building->world_y + 1;
                } else if (buildingType == 0x46) {
                    bMin.x = (int)building->world_x - 3;
                    bMin.y = (int)building->world_y - 3;
                    bMax.x = (int)building->world_x + 3;
                    bMax.y = (int)building->world_y + 3;
                } else {
                    bMin.x = (int)building->world_x - 2;
                    bMin.y = (int)building->world_y - 2;
                    bMax.x = (int)building->world_x + 2;
                    bMax.y = (int)building->world_y + 2;
                }
            } else if (bXRadius == 1.0f) {
                if (buildingCode == 6 || buildingCode == 3) {
                    bMin.x = (int)building->world_x - 1;
                    bMin.y = (int)building->world_y - 1;
                    bMax.x = (int)building->world_x;
                    bMax.y = (int)building->world_y;
                } else {
                    bMin.x = (int)building->world_x - 2;
                    bMin.y = (int)building->world_y - 2;
                    bMax.x = (int)building->world_x + 1;
                    bMax.y = (int)building->world_y + 1;
                }
            } else if (bXRadius == 0.5) {
                if (buildingCode == 6 || buildingCode == 4) {
                    bMin.x = (int)building->world_x;
                    bMin.y = (int)building->world_y;
                    bMax.x = (int)building->world_x;
                    bMax.y = (int)building->world_y;
                } else {
                    bMin.x = (int)building->world_x - 1;
                    bMin.y = (int)building->world_y - 1;
                    bMax.x = (int)building->world_x + 1;
                    bMax.y = (int)building->world_y + 1;
                }
            } else {
                this->logCommonHistory((char*)"    Unsupported building size (%d x %d).", (double)(bXRadius + bXRadius),
                                       (double)(bYRadius + bYRadius));
                continue;
            }

            if (buildingCode == 0x6d) {
                bMin.x--;
                bMin.y--;
                bMax.x++;
                bMax.y++;
            }
            this->mapBound(bMin);
            this->mapBound(bMax);
            iMap.setValue(bMin.x, bMin.y, bMax.x, bMax.y, 0xff);

            if (placementType == 3 || placementType == 0) {
                float influence_radius = master->los;
                if (placementType != 0)
                    influence_radius *= 0.5f;
                if (buildingCode == 0x6d)
                    influence_radius *= 0.5f;
                int radius = (int)influence_radius;

                XYPoint bMinLOS;
                XYPoint bMaxLOS;
                bMinLOS.x = bMin.x - radius;
                bMinLOS.y = bMin.y - radius;
                this->mapBound(bMinLOS);
                bMaxLOS.x = bMax.x + radius;
                bMaxLOS.y = bMax.y + radius;
                this->mapBound(bMaxLOS);
                if (placementType == 0 && buildingCode == 3)
                    iMap.incrementValue(bMinLOS.x, bMinLOS.y, bMaxLOS.x, bMaxLOS.y, 10);
                else
                    iMap.decrementValue(bMinLOS.x, bMinLOS.y, bMaxLOS.x, bMaxLOS.y, 10);
            } else if (placementType == 1 || placementType == 2) {
                float influence_radius = master->los;
                if (buildingCode == 0x6d)
                    influence_radius *= 0.5f;
                else if (buildingCode == 0x44 || buildingCode == 0x67)
                    influence_radius = 5.0f;
                int radius = (int)influence_radius;

                XYPoint bMinLOS;
                XYPoint bMaxLOS;
                bMinLOS.x = bMin.x - radius;
                bMinLOS.y = bMin.y - radius;
                this->mapBound(bMinLOS);
                bMaxLOS.x = bMax.x + radius;
                bMaxLOS.y = bMax.y + radius;
                this->mapBound(bMaxLOS);
                iMap.decrementValue(bMinLOS.x, bMinLOS.y, bMaxLOS.x, bMaxLOS.y, 10);
            } else if (placementType == 5) {
                float influence_radius = master->los;
                if (buildingCode == 0x6d)
                    influence_radius *= 0.25f;
                int radius = (int)influence_radius;
                radius *= 2;

                XYPoint bMinLOS;
                XYPoint bMaxLOS;
                bMinLOS.x = bMin.x - radius;
                bMinLOS.y = bMin.y - radius;
                this->mapBound(bMinLOS);
                bMaxLOS.x = bMax.x + radius;
                bMaxLOS.y = bMax.y + radius;
                this->mapBound(bMaxLOS);
                iMap.decrementValue(bMinLOS.x, bMinLOS.y, bMaxLOS.x, bMaxLOS.y, 20);
            } else if (placementType == 8) {
                int radius = (int)master->los;
                int layer_radius = radius;
                int layer;
                for (layer = 0; layer < 3; ++layer) {
                    if (layer == 1)
                        layer_radius = radius / 2;
                    else if (layer == 2)
                        layer_radius = radius / 3;

                    XYPoint bMinLOS;
                    XYPoint bMaxLOS;
                    bMinLOS.x = bMin.x - layer_radius;
                    bMinLOS.y = bMin.y - layer_radius;
                    this->mapBound(bMinLOS);
                    bMaxLOS.x = bMax.x + layer_radius;
                    bMaxLOS.y = bMax.y + layer_radius;
                    this->mapBound(bMaxLOS);
                    iMap.incrementValue(bMinLOS.x, bMinLOS.y, bMaxLOS.x, bMaxLOS.y, 20);
                }
            }
        }
    }

    if (placementType == 3 || placementType == 4 || placementType == 0) {
        RGE_Map* map = this->md->player->world->map;
        for (x = minArea.x; x <= maxArea.x; ++x) {
            for (y = minArea.y; y <= maxArea.y; ++y) {
                unsigned char terrainType = map->get_terrain((short)x, (short)y);
                if (terrainType == 1) {
                    XYPoint tMin;
                    XYPoint tMax;
                    tMin.x = x - 2;
                    tMin.y = y - 2;
                    tMax = tMin;
                    this->mapBound(tMin);
                    this->mapBound(tMax);
                    iMap.setValue(x, y, 0xff);
                    iMap.decrementValue(tMin.x, tMin.y, tMax.x, tMax.y, 10);
                }
                iMap.incrementValue(x, y, (unsigned char)(map->map_row_offset[y][x].height * 5));
            }
        }
    }

    if (placementType == 3 || placementType == 4 || placementType == 0 || placementType == 6 || placementType == 5) {
        int memory_index;
        for (memory_index = 0; memory_index < this->maxAttackMemories; ++memory_index) {
            AttackMemory* memory = &this->attackMemories[memory_index];
            if (memory->id != -1 && memory->targetOwner == this->md->player->id) {
                XYPoint aMin;
                XYPoint aMax;
                aMin.x = memory->minX - 4;
                aMin.y = memory->minY - 4;
                this->mapBound(aMin);
                aMax.x = memory->maxX + 4;
                aMax.y = memory->maxY + 4;
                this->mapBound(aMax);
                iMap.incrementValue(aMin.x, aMin.y, aMax.x, aMax.y, 0x10);
            }
        }
    }

    if (placementType == 0)
        this->md->tacticalAI.setGroupInfluences(iMap);

    iMap.setConnectionCount(min, max, 0xff, 1, placementType != 4, 1);

    if (placementType != 0) {
        int lot_index;
        for (lot_index = 0; lot_index < this->maxBuildingLots; ++lot_index) {
            BuildingLot* lot = &this->buildingLots[lot_index];
            if (lot->typeID == buildingType && lot->status == 2)
                iMap.setValue(lot->x, lot->y, 0xff);
        }
    }

    (void)centerPoint;
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

ObjectMemory TribeInformationAIModule::findObjectMemoryLimits(
    int ownerID, int unitID, int& numberNonSiegeTargets,
    int& numberNonBoatTargets) {
    ObjectMemory rVal;
    RGE_Static_Object* unit;
    RGE_Static_Object* obj;
    int i;
    uchar currentZone;
    XYPoint pt;
    int dx;
    int dy;
    int group;
    float dist;

    numberNonSiegeTargets = 0;
    numberNonBoatTargets = 0;
    rVal.id = 0;
    rVal.hitPoints = 0;
    rVal.attackAttempts = 0;
    rVal.kills = 0;
    rVal.damageCapability = 0.0f;
    rVal.rateOfFire = 0.0f;
    rVal.range = 0.0f;

    unit = this->md->object(unitID);
    if (unit != 0) {
        currentZone = unit->currentZone();
        i = 0;
        if (this->maxImportantObjectMemory > 0) {
            do {
                if ((int)this->importantObjectMemory[i].owner == ownerID) {
                    obj = this->md->object(this->importantObjectMemory[i].id);
                    if (obj != 0) {
                        if (currentZone != obj->currentZone()) {
                            pt.x = (int)obj->world_x;
                            pt.y = (int)obj->world_y;
                            if (unit->withinRangeOfZoneAtPoint(currentZone, unit->weaponRange(), pt) != 1)
                                goto next;
                        }
                        obj = this->md->object(this->importantObjectMemory[i].id);
                        if (obj != 0) {
                            dx = (int)this->importantObjectMemory[i].x - (int)obj->world_x;
                            if (dx < 0) dx = -dx;
                            dy = (int)this->importantObjectMemory[i].y - (int)obj->world_y;
                            if (dy < 0) dy = -dy;
                            if ((dx > 5 || dy > 5) &&
                                this->md->player->visible->get_visible((int)obj->world_x, (int)obj->world_y) != 0x0F)
                                goto skip_visible;
                            group = this->importantObjectMemory[i].group;
                            if (group != 3 && group != 0x1B)
                                numberNonSiegeTargets++;
                            group = this->importantObjectMemory[i].group;
                            if (group != 2 && group != 0x15 && group != 0x16 && group != 0x14 &&
                                this->importantObjectMemory[i].type != 0x2D)
                                numberNonBoatTargets++;
                            dist = unit->distance_to_position((float)this->importantObjectMemory[i].x,
                                                              (float)this->importantObjectMemory[i].y, (float)this->importantObjectMemory[i].z);
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

int TribeInformationAIModule::isNextTo(XYPoint& one, XYPoint& two,
                                       int countDiagonal) {
    int dx = two.x - one.x;
    int dy = two.y - one.y;
    int dist = dx * dx + dy * dy;
    if (countDiagonal == 0) {
        if (dist > 1) {
            return 0;
        }
        goto check_mode1;
    }
check_mode1:
    if (countDiagonal == 1) {
        if (dist > 2) {
            return 0;
        }
    }
    return 1;
}

int TribeInformationAIModule::facetTo(XYPoint& one, XYPoint& two) {
    int dx;
    int dy;

    dx = two.x - one.x;
    dy = two.y - one.y;

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

int TribeInformationAIModule::placementCode(int typeID) {
    switch (typeID) {
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
                                        unsigned char y, unsigned char status) {
    int freeIndex = -1;
    int i = 0;

    if (this->maxBuildingLots > 0) {
        BuildingLot* lot = this->buildingLots;
        do {
            if (lot->typeID == typeID && x == lot->x && y == lot->y) {
                this->buildingLots[i].status = status;
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
        BuildingLot* newLots = (BuildingLot*)::operator new(this->maxBuildingLots << 4);
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
                    newLots[i].status = status;
                    ++i;
                } while (i < this->maxBuildingLots * 2);
            }

            ::operator delete(this->buildingLots);
            this->buildingLots = newLots;

            newLots[this->maxBuildingLots].typeID = typeID;
            this->buildingLots[this->maxBuildingLots].x = x;
            this->buildingLots[this->maxBuildingLots].y = y;
            this->buildingLots[this->maxBuildingLots].status = status;
            this->maxBuildingLots <<= 1;
        }
    } else {
        this->buildingLots[freeIndex].typeID = typeID;
        this->buildingLots[freeIndex].x = x;
        this->buildingLots[freeIndex].y = y;
        this->buildingLots[freeIndex].status = status;
    }
}

#include <windows.h>

void TribeInformationAIModule::removeLot(
    int typeID, unsigned char x, unsigned char y, unsigned char newStatus) {
    int idx = 0;
    if (maxBuildingLots <= 0) return;

    BuildingLot* lot = buildingLots;
    goto enter;

loop:
    idx++;
    lot++;
    if (idx >= maxBuildingLots) return;

enter:
    if (lot->typeID == typeID && lot->x == x && lot->y == y)
        goto found;
    goto loop;

found:
    if (newStatus != 3) {
        buildingLots[idx].status = newStatus;
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

int TribeInformationAIModule::undesirableLot(
    int typeID, unsigned char x, unsigned char y, int overlapSize) {
    int i = 0;
    int max = this->maxBuildingLots;
    BuildingLot* pLot;

    if (max <= 0) {
        goto ret_zero_late;
    }

    pLot = this->buildingLots;

loop:
    if (pLot->typeID == typeID && pLot->status == 1) {
        int lotX = (int)pLot->x;
        int lotY = (int)pLot->y;
        int yMinusOff = lotY - overlapSize;
        int offPlusX = overlapSize + lotX;
        int xMinusOff = lotX - overlapSize;
        int offPlusY = overlapSize + lotY;

        if (xMinusOff <= (int)x && offPlusX >= (int)x && yMinusOff <= (int)y && offPlusY >= (int)y) {
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

void TribeInformationAIModule::setupWalls(
    int centerX, int centerY, int minimumDistance, int maximumDistance,
    int wallShape, int numberGates, int gateSize, int setupGates) {
    int x;
    int y;

    if (setupGates == 1 && numberGates > 0) {
        this->numberGatesValue = numberGates;

        int gate = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\taiinfmd.cpp", 5937) % 4;
        int halfGateSize = gateSize / 2;

        this->minGatePosition[gate].x = centerX - halfGateSize;
        this->minGatePosition[gate].y = centerY - maximumDistance * 2;
        this->maxGatePosition[gate].x = centerX + halfGateSize;
        this->maxGatePosition[gate].y = centerY;

        gate = (gate + 1) % 4;
        this->minGatePosition[gate].x = centerX - halfGateSize;
        this->minGatePosition[gate].y = centerY;
        this->maxGatePosition[gate].x = centerX + halfGateSize;
        this->maxGatePosition[gate].y = centerY + maximumDistance * 2;

        gate = (gate + 1) % 4;
        this->minGatePosition[gate].x = centerX;
        this->minGatePosition[gate].y = centerY - halfGateSize;
        this->maxGatePosition[gate].x = centerX + maximumDistance * 2;
        this->maxGatePosition[gate].y = centerY + halfGateSize;

        gate = (gate + 1) % 4;
        this->minGatePosition[gate].x = centerX - maximumDistance * 2;
        this->minGatePosition[gate].y = centerY - halfGateSize;
        this->maxGatePosition[gate].x = centerX;
        this->maxGatePosition[gate].y = centerY + halfGateSize;

        int gatesLeft = numberGates;
        XYPoint* maximumGate = this->maxGatePosition;
        do {
            this->mapBound(maximumGate[-4]);
            this->mapBound(*maximumGate);
            ++maximumGate;
            --gatesLeft;
        } while (gatesLeft != 0);
    }

    if (wallShape == 0) {
        wallShape = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\taiinfmd.cpp", 5994) % 3;
    }

    if (wallShape == 1) {
        if (minimumDistance > maximumDistance)
            return;

        int minimumX = centerX - minimumDistance;
        int minimumY = centerY - minimumDistance;
        int maximumX = centerX + minimumDistance;
        int maximumY = centerY + minimumDistance;
        unsigned int rings =
            (unsigned int)(maximumDistance - minimumDistance + 3) / 3;

        do {
            XYPoint minimum;
            XYPoint maximum;
            minimum.x = minimumX;
            minimum.y = minimumY;
            this->mapBound(minimum);
            maximum.x = maximumX;
            maximum.y = maximumY;
            this->mapBound(maximum);

            x = minimum.x;
            y = minimum.y;
            while (x < maximum.x) {
                if (this->insideGate(numberGates, x, y) == 0)
                    this->storeLot(0x48, (unsigned char)x, (unsigned char)y, 0);
                ++x;
            }
            while (y < maximum.y) {
                if (this->insideGate(numberGates, x, y) == 0)
                    this->storeLot(0x48, (unsigned char)x, (unsigned char)y, 0);
                ++y;
            }
            while (x > minimum.x) {
                if (this->insideGate(numberGates, x, y) == 0)
                    this->storeLot(0x48, (unsigned char)x, (unsigned char)y, 0);
                --x;
            }
            while (y > minimum.y) {
                if (this->insideGate(numberGates, x, y) == 0)
                    this->storeLot(0x48, (unsigned char)x, (unsigned char)y, 0);
                --y;
            }

            minimumX -= 3;
            minimumY -= 3;
            maximumX += 3;
            maximumY += 3;
            --rings;
        } while (rings != 0);
        return;
    }

    if (wallShape == 2) {
        if (minimumDistance > maximumDistance)
            return;

        int distance = minimumDistance;
        int sideLength = minimumDistance * 2;
        int farMinimum = centerY - minimumDistance;
        int minimum = farMinimum;
        int maximum = centerY + minimumDistance;
        int centerDifference = centerX - centerY;
        int rings = maximumDistance - minimumDistance + 1;

        do {
            XYPoint farMinimumPoint;
            XYPoint farMaximumPoint;
            XYPoint minimumPoint;
            XYPoint maximumPoint;

            farMinimumPoint.x = farMinimum + centerDifference;
            farMinimumPoint.y = farMinimum;
            this->mapBound(farMinimumPoint);

            farMaximumPoint.x = centerY + distance + centerDifference;
            farMaximumPoint.y = centerY + distance;
            this->mapBound(farMaximumPoint);

            minimumPoint.x = minimum + centerDifference;
            minimumPoint.y = minimum;
            this->mapBound(minimumPoint);

            maximumPoint.x = maximum + centerDifference;
            maximumPoint.y = maximum;
            this->mapBound(maximumPoint);

            x = minimumPoint.x;
            y = minimumPoint.y;

            if (sideLength > 0) {
                int count = distance;
                do {
                    if (this->insideGate(numberGates, x, y) == 0)
                        this->storeLot(0x48, (unsigned char)x, (unsigned char)y, 0);
                    --y;
                    --count;
                } while (count != 0);
            }
            if (sideLength > 0) {
                int count = sideLength;
                do {
                    if (this->insideGate(numberGates, x, y) == 0)
                        this->storeLot(0x48, (unsigned char)x, (unsigned char)y, 0);
                    ++x;
                    --count;
                } while (count != 0);
            }
            if (sideLength > 0) {
                int count = distance;
                do {
                    if (this->insideGate(numberGates, x, y) == 0)
                        this->storeLot(0x48, (unsigned char)x, (unsigned char)y, 0);
                    ++y;
                    --count;
                } while (count != 0);
            }
            if (sideLength > 0) {
                int count = distance;
                do {
                    if (this->insideGate(numberGates, x, y) == 0)
                        this->storeLot(0x48, (unsigned char)x, (unsigned char)y, 0);
                    ++x;
                    --count;
                } while (count != 0);
            }
            if (sideLength > 0) {
                int count = sideLength;
                do {
                    if (this->insideGate(numberGates, x, y) == 0)
                        this->storeLot(0x48, (unsigned char)x, (unsigned char)y, 0);
                    ++y;
                    --count;
                } while (count != 0);
            }
            if (sideLength > 0) {
                int count = distance;
                do {
                    if (this->insideGate(numberGates, x, y) == 0)
                        this->storeLot(0x48, (unsigned char)x, (unsigned char)y, 0);
                    --x;
                    --count;
                } while (count != 0);
            }
            if (sideLength >= 0) {
                int count = distance + 1;
                do {
                    if (this->insideGate(numberGates, x, y) == 0)
                        this->storeLot(0x48, (unsigned char)x, (unsigned char)y, 0);
                    ++y;
                    --count;
                } while (count != 0);
            }
            if (sideLength > 0) {
                int count = sideLength;
                do {
                    if (this->insideGate(numberGates, x, y) == 0)
                        this->storeLot(0x48, (unsigned char)x, (unsigned char)y, 0);
                    --x;
                    --count;
                } while (count != 0);
            }
            if (sideLength >= 0) {
                int count = distance + 1;
                do {
                    if (this->insideGate(numberGates, x, y) == 0)
                        this->storeLot(0x48, (unsigned char)x, (unsigned char)y, 0);
                    --y;
                    --count;
                } while (count != 0);
            }
            if (sideLength > 0) {
                int count = distance;
                do {
                    if (this->insideGate(numberGates, x, y) == 0)
                        this->storeLot(0x48, (unsigned char)x, (unsigned char)y, 0);
                    --x;
                    --count;
                } while (count != 0);
            }
            if (sideLength > 0) {
                int count = sideLength;
                do {
                    if (this->insideGate(numberGates, x, y) == 0)
                        this->storeLot(0x48, (unsigned char)x, (unsigned char)y, 0);
                    --y;
                    --count;
                } while (count != 0);
            }
            if (sideLength > 0) {
                int count = distance;
                do {
                    if (this->insideGate(numberGates, x, y) == 0)
                        this->storeLot(0x48, (unsigned char)x, (unsigned char)y, 0);
                    ++x;
                    --count;
                } while (count != 0);
            }

            distance += 2;
            farMinimum -= 2;
            --minimum;
            ++maximum;
            sideLength += 4;
            --rings;
        } while (rings != 0);
        return;
    }

    if (wallShape == 3) {
        int halfDistance = minimumDistance / 2;
        if (halfDistance > maximumDistance)
            return;

        int farMinimum = centerY - minimumDistance;
        int farMaximum = centerY + minimumDistance;
        int innerCenter = centerY;
        int innerMaximum = centerY + halfDistance;
        int centerDifference = centerX - centerY;
        int rings = maximumDistance - halfDistance + 1;

        do {
            XYPoint farMinimumPoint;
            XYPoint farMaximumPoint;
            XYPoint innerMinimumPoint;
            XYPoint innerMaximumPoint;

            farMinimumPoint.x = farMinimum + centerDifference;
            farMinimumPoint.y = farMinimum;
            this->mapBound(farMinimumPoint);

            farMaximumPoint.x = farMaximum + centerDifference;
            farMaximumPoint.y = farMaximum;
            this->mapBound(farMaximumPoint);

            innerMinimumPoint.y = innerCenter - halfDistance;
            innerMinimumPoint.x = innerMinimumPoint.y + centerDifference;
            this->mapBound(innerMinimumPoint);

            innerMaximumPoint.x = innerMaximum + centerDifference;
            innerMaximumPoint.y = innerMaximum;
            this->mapBound(innerMaximumPoint);

            x = farMinimumPoint.x;
            y = innerMinimumPoint.y;

            while (x < innerMinimumPoint.x) {
                if (this->insideGate(numberGates, x, y) == 0)
                    this->storeLot(0x48, (unsigned char)x, (unsigned char)y, 0);
                ++x;
                --y;
            }
            while (x < innerMaximumPoint.x) {
                if (this->insideGate(numberGates, x, y) == 0)
                    this->storeLot(0x48, (unsigned char)x, (unsigned char)y, 0);
                ++x;
            }
            while (y < innerMinimumPoint.y) {
                if (this->insideGate(numberGates, x, y) == 0)
                    this->storeLot(0x48, (unsigned char)x, (unsigned char)y, 0);
                ++x;
                ++y;
            }
            while (y < innerMaximumPoint.y) {
                if (this->insideGate(numberGates, x, y) == 0)
                    this->storeLot(0x48, (unsigned char)x, (unsigned char)y, 0);
                ++y;
            }
            while (x > innerMaximumPoint.x) {
                if (this->insideGate(numberGates, x, y) == 0)
                    this->storeLot(0x48, (unsigned char)x, (unsigned char)y, 0);
                --x;
                ++y;
            }
            while (x > innerMinimumPoint.x) {
                if (this->insideGate(numberGates, x, y) == 0)
                    this->storeLot(0x48, (unsigned char)x, (unsigned char)y, 0);
                --x;
            }
            while (y > innerMaximumPoint.y) {
                if (this->insideGate(numberGates, x, y) == 0)
                    this->storeLot(0x48, (unsigned char)x, (unsigned char)y, 0);
                --x;
                --y;
            }
            while (y > innerMinimumPoint.y) {
                if (this->insideGate(numberGates, x, y) == 0)
                    this->storeLot(0x48, (unsigned char)x, (unsigned char)y, 0);
                --y;
            }

            --innerCenter;
            farMinimum -= 2;
            farMaximum += 2;
            ++innerMaximum;
            --rings;
        } while (rings != 0);
    }
}

int TribeInformationAIModule::insideGate(int numGates, int x, int y) {
    int* p;
    int i;

    i = 0;
    if (numGates > 0) {
        p = &this->minGatePosition[0].y;
        while (1) {
            if (!(((XYPoint*)(p - 1))->x > x || *p > y || x > p[7] || y > p[8])) {
                goto found;
            }
            i = i + 1;
            p = p + 2;
            if (i >= numGates) {
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
    unsigned char type, unsigned char x1, unsigned char y1,
    unsigned char attackingOwner, unsigned char targetOwner, short kills,
    unsigned char success, ulong timeStamp, int play) {
    return this->storeAttackMemory(type, x1, y1, x1, y1, attackingOwner, targetOwner, kills, success, timeStamp, play);
}

#include <stdlib.h>

int TribeInformationAIModule::storeAttackMemory(
    unsigned char type,
    unsigned char x1,
    unsigned char y1,
    unsigned char x2,
    unsigned char y2,
    unsigned char attackingOwner,
    unsigned char targetOwner,
    short kills,
    unsigned char success,
    unsigned long timeStamp,
    int play) {
    int bestIdx;
    int count;

    if (this->mapXSizeValue > 0 && this->mapYSizeValue > 0) {
        int product = ((int)x2 + (int)x1) * 4;
        int cx = product / this->mapXSizeValue;
        product = product / this->mapYSizeValue;
        cx /= 2;
        product /= 2;
        if (cx > 4) cx = 3;
        if (product > 4) product = 3;

        unsigned short playerID = this->md->player->id;
        if (targetOwner == playerID) {
            this->quadrantLog[cx][product].numberAttacksOnUs += 1;
        } else if (attackingOwner == playerID) {
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

        if (bestIdx == -1 || this->attackMemories[bestIdx].timeStamp < this->attackMemories[count].timeStamp) {
            bestIdx = count;
        }
    }

    if (bestIdx != -1) {
        this->attackMemories[bestIdx].id = count;
        this->attackMemories[bestIdx].type = type;
        this->attackMemories[bestIdx].minX = x1;
        this->attackMemories[bestIdx].minY = y1;
        this->attackMemories[bestIdx].maxX = x2;
        this->attackMemories[bestIdx].maxY = y2;
        this->attackMemories[bestIdx].attackingOwner = attackingOwner;
        this->attackMemories[bestIdx].targetOwner = targetOwner;
        this->attackMemories[bestIdx].kills = kills;
        this->attackMemories[bestIdx].success = success;
        this->attackMemories[bestIdx].timeStamp = timeStamp;
        this->attackMemories[bestIdx].play = play;
    }

    return bestIdx;
}

void TribeInformationAIModule::removeAttackMemory(int id) {
    if (id < 0 || id >= this->maxAttackMemories) {
        return;
    }

    this->attackMemories[id].id = -1;
    this->attackMemories[id].type = 0;
    this->attackMemories[id].minX = 0;
    this->attackMemories[id].minY = 0;
    this->attackMemories[id].maxX = 0;
    this->attackMemories[id].maxY = 0;
    this->attackMemories[id].attackingOwner = -1;
    this->attackMemories[id].targetOwner = -1;
    this->attackMemories[id].kills = 0;
    this->attackMemories[id].success = 0;
    this->attackMemories[id].play = -1;
}

AttackMemory* TribeInformationAIModule::attackMemory(int id) {
    if (id >= 0 && id < this->maxAttackMemories)
        return this->attackMemories + id;
    return 0;
}

#include <stdio.h>

void TribeInformationAIModule::loadLearnInfo(char* name) {
    int numToLoad;
    int tempInt;
    int object_id;
    char* learnFileName = this->learnFileName;

    if (name == 0) {
        sprintf(learnFileName, "learn\\default.%d", (int)this->md->player->id);
    } else {
        sprintf(learnFileName, "learn\\%s%s.%d", name, rge_base_game->player_game_info->get_current_player_name(),
                (int)this->md->player->id);
    }

    int file = rge_open(learnFileName, _O_BINARY);
    if (file != -1) {
        rge_read(file, &this->mapXSizeValue, 4);
        rge_read(file, &this->mapYSizeValue, 4);
        rge_read(file, &numToLoad, 4);

        int i = 0;
        if (numToLoad > 0) {
            AttackMemory temp;
            do {
                rge_read(file, &temp, 24);
                this->storeAttackMemory(temp.type, temp.minX, temp.minY, temp.maxX, temp.maxY, temp.attackingOwner,
                                        temp.targetOwner, temp.kills, temp.success, temp.timeStamp, temp.play);
                i++;
            } while (i < numToLoad);
        }

        rge_read(file, &numToLoad, 4);
        name = 0;
        if (numToLoad > 0) {
            ObjectMemory temp;
            do {
                rge_read(file, &temp, 36);
                this->addObjectMemory(temp.id, temp.type, temp.group, temp.x, temp.y, temp.z, temp.owner, temp.hitPoints,
                                      temp.attackAttempts, temp.kills, temp.damageCapability, temp.rateOfFire, temp.range, 0);
                this->importantUnits.add(temp.id);
                name = name + 1;
            } while ((int)name < numToLoad);
        }

        for (int resource_index = 0; resource_index < 4; resource_index++) {
            rge_read(file, &this->maxResources[resource_index], 4);
            rge_read(file, &this->numResources[resource_index], 4);
            this->resources[resource_index] = (ResourceMemory*)operator new(
                this->maxResources[resource_index] * sizeof(ResourceMemory));
            rge_read(file, this->resources[resource_index], this->maxResources[resource_index] * sizeof(ResourceMemory));
        }

        rge_read(file, &tempInt, 4);
        name = 0;
        if (tempInt > 0) {
            do {
                rge_read(file, &object_id, 4);
                this->importantMiscs.add(object_id);
                name = name + 1;
            } while ((int)name < tempInt);
        }

        rge_read(file, &tempInt, 4);
        name = 0;
        if (tempInt > 0) {
            do {
                rge_read(file, &object_id, 4);
                this->itemsToDefend.add(object_id);
                name = name + 1;
            } while ((int)name < tempInt);
        }

        rge_close(file);
    }
}

void TribeInformationAIModule::setSaveLearnInformation(int v) {
    this->saveLearnInformationValue = v;
}

int TribeInformationAIModule::unexploredPlayerLocation(int uID, XYPoint& rPoint) {
    RGE_Static_Object* obj = (RGE_Static_Object*)this->md->object(uID);
    if (uID != 0) {
        *(uchar*)&uID = obj->currentZone();
        int bestDistance;
        ObjectMemory* best;
        int i;
        best = 0;
        bestDistance = -1;
        i = 0;

        if (this->maxImportantObjectMemory > 0) {
            do {
                if (this->importantObjectMemory[i].id != -1) {
                    unsigned short owner =
                        this->importantObjectMemory[i].owner;
                    if (owner != this->md->player->id && this->importantObjectMemory[i].owner != 0) {
                        if (this->tileUncovered(this->importantObjectMemory[i].x, this->importantObjectMemory[i].y) != 1) {
                            if (obj->lookupZone(this->importantObjectMemory[i].x, this->importantObjectMemory[i].y) ==
                                (uchar)uID) {
                                int dist = (int)obj->distance_to_position((float)this->importantObjectMemory[i].x,
                                                                          (float)this->importantObjectMemory[i].y, (float)this->importantObjectMemory[i].z);
                                if (best == 0 || bestDistance > dist) {
                                    best = &this->importantObjectMemory[i];
                                    bestDistance = dist;
                                }
                            }
                        }
                    }
                }
                i++;
            } while (i < this->maxImportantObjectMemory);
        }

        if (best != 0) {
            rPoint.x = best->x;
            rPoint.y = best->y;

            int objZ = (int)obj->world_z;
            XYZPoint pt;
            pt.x = rPoint.x;
            pt.y = rPoint.y;
            pt.z = objZ;
            float pathResult;
            int ok = obj->canPath(pt, obj->master_obj->los - 1.0f, -1, &pathResult, 1, -1, -1);
            if (ok == 0) {
                this->pathMap.setValue(rPoint.x, rPoint.y, 1);
                return 0;
            }
            this->pathMap.setValue(rPoint.x, rPoint.y, 0);
            return 1;
        }
    }
    return 0;
}

#include <stdlib.h>

int TribeInformationAIModule::numberUnitsWithinXTiles(
    int playerID, int x, int y, int numTiles) {
    int radiusSquared = numTiles * numTiles;
    int rVal = 0;
    int i = 0;

    if (this->maxImportantObjectMemory > 0) {
        do {
            if ((playerID == -1 || (int)this->importantObjectMemory[i].owner == playerID) && (playerID != -1 ||
                 this->md->player->isEnemy(this->importantObjectMemory[i].owner) != 0)) {
                int dx = (int)this->importantObjectMemory[i].x - x;
                int dy = (int)this->importantObjectMemory[i].y - y;
                if (dx * dx + dy * dy <= radiusSquared) {
                    rVal++;
                }
            }
            i++;
        } while (i < this->maxImportantObjectMemory);
    }

    return rVal;
}

int TribeInformationAIModule::withinXTilesOfAttackOnPlayer(
    RGE_Static_Object* obj, int numTiles, int victimID) {
    int tilesSq = numTiles * numTiles;
    int tx = (int)obj->world_x;
    int objY = (int)obj->world_y;

    for (int i = 0; i < this->maxAttackMemories; i++) {
        AttackMemory* am = &attackMemories[i];
        if (am->id == -1 || !am->attackingOwner || (unsigned char)am->targetOwner != victimID)
            continue;

        int dxSquared = (unsigned char)am->minX - tx;
        dxSquared *= dxSquared;
        int dySquared = ((unsigned char)am->minY - objY) *
                        ((unsigned char)am->minY - objY);
        if (dySquared + dxSquared <= tilesSq) return 1;
        int dy = (unsigned char)am->minY - objY;

        dySquared = (unsigned char)am->maxY - objY;
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
    RGE_Static_Object* obj, int distance) {
    int dsq = distance * distance;
    int x = (int)obj->world_x;
    int y = (int)obj->world_y;

    for (int i = 0; i < this->maxImportantObjectMemory; i++) {
        if (this->importantObjectMemory[i].type != 109)
            continue;
        if (!this->md->player->isEnemy(this->importantObjectMemory[i].owner))
            continue;
        int dx = (unsigned char)this->importantObjectMemory[i].x - x;
        int dy = (unsigned char)this->importantObjectMemory[i].y - y;
        if (dx * dx + dy * dy <= dsq)
            return 1;
    }
    return 0;
}

int TribeInformationAIModule::withinXTilesOfObject(
    RGE_Static_Object* obj, int distance,
    int oT1, int oT2, int oT3, int oT4) {
    int distanceSquared = distance * distance;
    int x = (int)obj->world_x;
    int y = (int)obj->world_y;
    int rID = -1;
    int rDistance = -1;
    int i = 0;

    if (this->maxImportantObjectMemory > 0) {
        do {
            RGE_Static_Object* target = this->md->object(this->importantObjectMemory[i].id);

            if (target != 0 && target->object_state <= 2 && target->hp != 0.0f) {
                int type = (int)this->importantObjectMemory[i].type;
                    if ((type == oT1 || type == oT2 || type == oT3 || type == oT4) &&
                        this->md->player->isEnemy(this->importantObjectMemory[i].owner) != 0) {
                    int dx = (unsigned char)this->importantObjectMemory[i].x - x;
                    int dy = (unsigned char)this->importantObjectMemory[i].y - y;
                    int dist = dx * dx + dy * dy;

                    if (dist <= distanceSquared && (dist < rDistance || rID == -1)) {
                        rDistance = dist;
                        rID = this->importantObjectMemory[i].id;
                    }
                }
            }

            i++;
        } while (i < this->maxImportantObjectMemory);
    }

    return rID;
}

int TribeInformationAIModule::findStagingPoint(XYPoint startPoint, XYPoint& rPoint,
                                               int useTransport,
                                               int landTerrainRequired,
                                               int targetID, int stageDistance,
                                               int unitID) {
    ObjectMemory* target;
    RGE_Static_Object* unit;
    target = this->objectMemory(targetID);
    if (!target) return 0;
    unit = this->md->object(unitID);
    if (!unit) return 0;

    int terrain_type, terrain;
    if (this->isBoat(unit) == 1 && useTransport == 0) { terrain_type = 1; terrain = 0x16; }
    else { terrain_type = 2; terrain = 0; }

    XYPoint zoneRefPoint;
    zoneRefPoint.x = startPoint.x; zoneRefPoint.y = startPoint.y;
    unit->findClosestPointInTerrainType(startPoint, zoneRefPoint, terrain_type, terrain, 4);
    unsigned char targetZone = unit->lookupZone(zoneRefPoint.x, zoneRefPoint.y);

    int maxLOSValue = this->setupLOSMap(target->owner, target->x, target->y);
    int maxAttackValue = this->setupAttackMap(target->owner, target->x, target->y);
    XYPoint min, max, targetPoint;
    min.x = (int)target->x - stageDistance; min.y = (int)target->y - stageDistance; this->mapBound(min);
    max.x = (int)target->x + stageDistance; max.y = (int)target->y + stageDistance; this->mapBound(max);
    targetPoint.x = target->x; targetPoint.y = target->y; this->mapBound(targetPoint);

    RGE_Visible_Map* vMap = this->md->player->visible;
    RGE_Map* gMap = this->md->aiPlayer->world->map;
    int bestValue = -1;

    for (int x = min.x; x <= max.x; ++x) {
        for (int y = min.y; y <= max.y; ++y) {
            unsigned char tile = (unsigned char)(gMap->map_row_offset[y][x].terrain_type & 0x1f);
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
                passableMin.x = x - 2;
                passableMin.y = y - 2;
                this->mapBound(passableMin);
                passableMax.x = x + 2;
                passableMax.y = y + 2;
                this->mapBound(passableMax);
                int good = 1;
                for (int a = passableMin.x; a <= passableMax.x && good; ++a) {
                    for (int b = passableMin.y; b <= passableMax.y && good; ++b) {
                        unsigned char t = (unsigned char)(gMap->map_row_offset[b][a].terrain_type & 0x1f);
                        if (t != 1 && t != 0x16 && unit->passableTile((float)a, (float)b, 1) == 0) good = 0;
                    }
                }
                if (!good) continue;
            }
            int dx = target->x - x;
            int dy = target->y - y;
            int d2 = dx * dx + dy * dy;
            int dist = (int)sqrt((double)d2);
            int randomization = debug_rand("C:\\msdev\\work\\age1_x1\\taiinfmd.cpp", 6975) % (stageDistance * 3);
            XYPoint temp;
            XYPoint temp2;
            temp.x = x;
            temp.y = y;
            // A successful line path adds stageDistance to the score.
            int path_penalty = unit->canLinePath(temp, targetPoint, 1.0f, temp2, 1) == 1 ? stageDistance : 0;
            int los_penalty;
            int attack_penalty;
            if (maxLOSValue > 0)
                los_penalty = -(losMap.lookupValue(x, y) * stageDistance / maxLOSValue);
            else
                los_penalty = 0;
            if (maxAttackValue > 0)
                attack_penalty = -(attackMap.lookupValue(x, y) * stageDistance / maxAttackValue);
            else
                attack_penalty = 0;
            int v = attack_penalty + los_penalty + path_penalty + randomization + dist;
            if (bestValue == -1 || bestValue < v) {
                bestValue = v;
                rPoint.x = x;
                rPoint.y = y;
            }
        }
    }
    return bestValue != -1;
}

int TribeInformationAIModule::setupLOSMap(int ownerID, int x, int y) {
    losMap.initialize(0);
    losMap.setReferencePoint(x, y);

    int i = 0;
    if (this->maxImportantObjectMemory > 0) {
        do {
            if ((unsigned int)this->importantObjectMemory[i].owner == (unsigned int)ownerID) {
                RGE_Static_Object* obj = this->md->object(this->importantObjectMemory[i].id);
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

int TribeInformationAIModule::setupAttackMap(int ownerID, int x, int y) {
    attackMap.initialize(0);
    attackMap.setReferencePoint(x, y);

    int i = 0;
    if (this->maxAttackMemories > 0) {
        do {
            if ((unsigned char)this->attackMemories[i].targetOwner == (unsigned int)ownerID) {
                unsigned short owner = this->attackMemories[i].attackingOwner;
                if (owner == (unsigned short)this->md->player->id) {
                    attackMap.incrementValue(this->attackMemories[i].minX, this->attackMemories[i].minY,
                                             this->attackMemories[i].maxX, this->attackMemories[i].maxY, 1);
                }
            }
            i++;
        } while (i < this->maxAttackMemories);
    }

    return attackMap.maxValue();
}

#include <stdlib.h>

void TribeInformationAIModule::addResourceType(int r, int t) {
    int* new_types = (int*)operator new(this->numberResourceTypesValue[r] * 4 + 4);

    int count = 0;
    if (this->numberResourceTypesValue[r] > 0) {
        do {
            new_types[count] = this->resourceTypesValue[r][count];
            count++;
        } while (count < this->numberResourceTypesValue[r]);
    }

    new_types[count] = t;

    if (this->resourceTypesValue[r]) {
        operator delete(this->resourceTypesValue[r]);
    }

    this->resourceTypesValue[r] = new_types;
    this->numberResourceTypesValue[r]++;
}

int TribeInformationAIModule::resourceType(int r, int t) {
    for (int i = 0; i < this->numberResourceTypesValue[r]; i++) {
        if (this->resourceTypesValue[r][i] == t) {
            return 1;
        }
    }
    return 0;
}

int TribeInformationAIModule::addResourceObject(RGE_Static_Object* obj) {
    short group = obj->master_obj->object_group;
    int resourceType;

    if (group == 0x0f) {
        resourceType = 1;
    } else if (group == 8) {
        resourceType = 2;
    } else {
        resourceType = (group != 0x20) - 1 & 3;
    }

    if (this->numResources[resourceType] == this->maxResources[resourceType] || this->resources[resourceType] == 0) {
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
                float distance = this->findClosestDropsite(obj, 1, dropsiteID);
                this->resources[resourceType][i].gatherValue =
                    (int)(10.0f - distance * (-2.0f));
                this->resources[resourceType][i].dropsiteID = dropsiteID;

                int object_group = obj->master_obj->object_group;
                if (object_group == 0x0f) {
                    int value = (int)distance;
                    if (value >= this->closestDropsiteValue[1] && this->closestDropsiteValue[1] != -1) {
                        return 1;
                    }
                    this->closestDropsiteValue[1] = value;
                    this->closestDropsiteResourceID[1] = this->resources[resourceType][i].id;
                    return 1;
                }
                if (object_group == 0x20) {
                    int value = (int)distance;
                    if (value >= this->closestDropsiteValue[3] && this->closestDropsiteValue[3] != -1) {
                        return 1;
                    }
                    this->closestDropsiteValue[3] = value;
                    this->closestDropsiteResourceID[3] = this->resources[resourceType][i].id;
                    return 1;
                }
                if (object_group == 8) {
                    int value = (int)distance;
                    if (value >= this->closestDropsiteValue[2] && this->closestDropsiteValue[2] != -1) {
                        return 1;
                    }
                    this->closestDropsiteValue[2] = value;
                    this->closestDropsiteResourceID[2] = this->resources[resourceType][i].id;
                    return 1;
                }
                if (object_group == 7) {
                    int value = (int)distance;
                    if (value >= this->closestDropsiteValue[0] && this->closestDropsiteValue[0] != -1) {
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
    float distance = this->findClosestDropsite(obj, 1, dropsiteID);
    this->resources[resourceType][this->numResources[resourceType]].dropDistance =
        (unsigned char)distance;
    this->resources[resourceType][this->numResources[resourceType]].dropsiteID = dropsiteID;
    this->resources[resourceType][this->numResources[resourceType]].gatherValue =
        (int)(10.0f - distance * -2.0f);
    this->numResources[resourceType]++;

    int object_group = obj->master_obj->object_group;
    if (object_group == 0x0f) {
        int value = (int)distance;
        if (value < this->closestDropsiteValue[1] || this->closestDropsiteValue[1] == -1) {
            this->closestDropsiteValue[1] = value;
            this->closestDropsiteResourceID[1] = obj->id;
            return 1;
        }
    } else if (object_group == 0x20) {
        int value = (int)distance;
        if (value < this->closestDropsiteValue[3] || this->closestDropsiteValue[3] == -1) {
            this->closestDropsiteValue[3] = value;
            this->closestDropsiteResourceID[3] = obj->id;
            return 1;
        }
    } else if (object_group == 8) {
        int value = (int)distance;
        if (value < this->closestDropsiteValue[2] || this->closestDropsiteValue[2] == -1) {
            this->closestDropsiteValue[2] = value;
            this->closestDropsiteResourceID[2] = obj->id;
            return 1;
        }
    } else if (object_group == 7) {
        int value = (int)distance;
        if (value < this->closestDropsiteValue[0] || this->closestDropsiteValue[0] == -1) {
            this->closestDropsiteValue[0] = value;
            this->closestDropsiteResourceID[0] = obj->id;
            return 1;
        }
    }
    return 1;
}

float TribeInformationAIModule::findClosestDropsite(
    RGE_Static_Object* resourceObj, int countTownCenter, int& dropsiteID) {
    float dropDistance;
    unsigned char resourceZone;
    int i;
    RGE_Static_Object* dropsite;

    dropDistance = 1000.0f;
    resourceZone = resourceObj->currentZone();
    dropsiteID = -1;

    i = 0;
    if (this->playerBuildings.numberValue > 0) {
        do {
            dropsite = this->md->object(this->playerBuildings[i]);
            if (dropsite != 0) {
                if (resourceObj->lookupZone((int)dropsite->world_x, (int)dropsite->world_y) == resourceZone) {
                    int group = dropsite->master_obj->id;
                    if ((group == 0x6D && countTownCenter != 0) ||
                        (group == 0x67 && resourceObj->master_obj->id != 0x3B && resourceObj->master_obj->id != 0x32) ||
                        (group == 0x44 && (resourceObj->master_obj->id == 0x3B || resourceObj->master_obj->id == 0x32))) {
                        float dx = dropsite->world_x - resourceObj->world_x;
                        float dy = dropsite->world_y - resourceObj->world_y;
                        float dist = (float)sqrt(dx * dx + dy * dy);
                        if (dropDistance == 1000.0f || dist < dropDistance) {
                            dropsiteID = dropsite->id;
                            dropDistance = dist;
                        }
                    }
                }
            }

            i++;
        } while (i < this->playerBuildings.numberValue);
    }

    return dropDistance;
}

#include <stddef.h>
#include <math.h>

RGE_Static_Object* TribeInformationAIModule::findClosestReturnDropsite(
    RGE_Static_Object* unitObj) {
    RGE_Static_Object* rVal = 0;
    float dropDistance = 1000.0f;
    unsigned char unitZone = unitObj->currentZone();
    int i = 0;

    if (this->playerBuildings.numberValue > 0) {
        do {
            RGE_Static_Object* obj = this->md->object(this->playerBuildings[i]);
            if (obj != 0) {
                if (unitObj->lookupZone((int)obj->world_x, (int)obj->world_y) == unitZone) {
                    int id = obj->master_obj->id;
                    if (id == 0x6D || (id == 0x67 && unitObj->attribute_type_held != 0x10) ||
                        (id == 0x44 && unitObj->attribute_type_held == 0x10)) {
                        float xDiff = obj->world_x - unitObj->world_x;
                        float yDiff = obj->world_y - unitObj->world_y;
                        float dist = (float)sqrt(xDiff * xDiff + yDiff * yDiff);
                        if (rVal == 0 || dist < dropDistance) {
                            dropDistance = dist;
                            rVal = obj;
                        }
                    }
                }
            }

            i++;
        } while (i < this->playerBuildings.numberValue);
    }

    return rVal;
}

void TribeInformationAIModule::updateAllResourceDropsites() {
    for (int resourceType = 0; resourceType < 4; ++resourceType) {
        this->closestDropsiteValue[resourceType] = -1;
        this->closestDropsiteResourceID[resourceType] = -1;
        int i = 0;
        if (this->numResources[resourceType] > 0) {
            do {
                RGE_Static_Object* obj =
                    this->md->object(this->resources[resourceType][i].id);
                if (obj) {
                    int dropsiteID = -1;
                    float dist = this->findClosestDropsite(obj, 1, dropsiteID);
                    this->resources[resourceType][i].gatherValue =
                        (int)(10.0f - dist * (-2.0f));
                    this->resources[resourceType][i].dropDistance =
                        (unsigned char)(int)dist;
                    this->resources[resourceType][i].dropsiteID = dropsiteID;

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
            } while (i < this->numResources[resourceType]);
        }
    }
}

void TribeInformationAIModule::updateResourceDropsites(int rType) {
    this->closestDropsiteValue[rType] = -1;
    this->closestDropsiteResourceID[rType] = -1;

    int i = 0;
    int a = 0;

    if (this->numResources[rType] > 0) {
        do {
            if (*(unsigned char*)((char*)this->resources[rType] + a + 0x0D) != 1) {
                int obj_id = *(int*)((char*)this->resources[rType] + a);
                RGE_Static_Object* obj = this->md->object(obj_id);

                if (obj != 0) {
                    int dropsiteID = -1;
                    float dist = this->findClosestDropsite(obj, 1, dropsiteID);

                    int val = (int)(10.0f - (-2.0f) * dist);
                    *(int*)((char*)this->resources[rType] + a + 8) = val;
                    *(unsigned char*)((char*)this->resources[rType] + a + 0x0E) =
                        (unsigned char)(int)dist;
                    *(int*)((char*)this->resources[rType] + a + 0x10) = dropsiteID;

                    int grp = obj->master_obj->object_group;

                    if (grp == 0x0F) {
                        int v = (int)dist;
                        if (v < this->closestDropsiteValue[1] || this->closestDropsiteValue[1] == -1) {
                            this->closestDropsiteValue[1] = v;
                            this->closestDropsiteResourceID[1] = obj->id;
                        }
                    } else if (grp == 0x20) {
                        int v = (int)dist;
                        if (v < this->closestDropsiteValue[3] || this->closestDropsiteValue[3] == -1) {
                            this->closestDropsiteValue[3] = v;
                            this->closestDropsiteResourceID[3] = obj->id;
                        }
                    } else if (grp == 8) {
                        int v = (int)dist;
                        if (v < this->closestDropsiteValue[2] || this->closestDropsiteValue[2] == -1) {
                            this->closestDropsiteValue[2] = v;
                            this->closestDropsiteResourceID[2] = obj->id;
                        }
                    } else if (grp == 7) {
                        int v = (int)dist;
                        if (v < this->closestDropsiteValue[0] || this->closestDropsiteValue[0] == -1) {
                            this->closestDropsiteValue[0] = v;
                            this->closestDropsiteResourceID[0] = obj->id;
                        }
                    }
                }
            }

            i++;
            a += 0x14;
        } while (i < this->numResources[rType]);
    }
}

int TribeInformationAIModule::setResourceObjectValid(
    int rType, int id, int newValid) {
    for (int i = 0; i < this->numResources[rType]; i++) {
        if (this->resources[rType][i].id == id) {
            this->resources[rType][i].valid = (unsigned char)newValid;
            return 1;
        }
    }
    return 0;
}

#include <stddef.h>

int TribeInformationAIModule::numberStoragePits() {
    int i = 0;
    int count = 0;

    if (playerBuildings.numberValue > 0) {
        do {
            RGE_Static_Object* obj = md->object(playerBuildings[i]);
            if (obj != 0 && obj->master_obj->id == 0x67) {
                count++;
            }

            i++;
        } while (i < playerBuildings.numberValue);
    }

    return count;
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

int TribeInformationAIModule::amountForageBushesInXTiles(
    int x, int y, int distance) {
    float count = 0.0f;
    int i = 0;
    if (this->numResources[0] > 0) {
        do {
            if (this->resources[0][i].gone != 1) {
                RGE_Static_Object* obj = this->md->object(this->resources[0][i].id);
                if (obj != 0 && obj->master_obj->id == 0x3B) {
                    float dX = obj->world_x - (float)x;
                    float dy = obj->world_y - (float)y;
                    if ((int)(sqrt(dX * dX + dy * dy)) <= distance)
                        count += obj->attribute_amount_held;
                }
            }
            i++;
        } while (i < this->numResources[0]);
    }
    return (int)count;
}

#include <math.h>

int TribeInformationAIModule::amountResourceTypesInXTiles(
    int type, int x, int y, int distance) {
    float count = 0.0f;
    int i = 0;

    if (this->numResources[type] > 0) {
        do {
            if (this->resources[type][i].gone != 1) {
                RGE_Static_Object* obj = this->md->object(this->resources[type][i].id);
                if (obj != 0 && (type != 0 || obj->master_obj->id != 0x3B)) {
                    float dx = obj->world_x - (float)x;
                    float dy = obj->world_y - (float)y;
                    if ((int)(sqrt(dx * dx + dy * dy)) <= distance) {
                        count += obj->attribute_amount_held;
                    }
                }
            }
            i++;
        } while (i < this->numResources[type]);
    }

    return (int)count;
}

float TribeInformationAIModule::damagePerSecond(int id, int x, int y) {
    float rateOfFire = 0.0f;

    RGE_Static_Object* target = (RGE_Static_Object*)md->object(id);
    if (target == 0) {
        return 0.0f;
    }

    int i = 0;
    if (maxImportantObjectMemory > 0) {
        do {
            unsigned char owner = importantObjectMemory[i].owner;
            if (md->player->isEnemy(owner)) {
                int id = importantObjectMemory[i].id;
                RGE_Static_Object* unit = (RGE_Static_Object*)md->object(id);
                if (unit != 0 && unit->object_state <= 2) {
                    float dist = unit->distance_to_position((float)x, (float)y, *(float*)&unit->world_z);
                    if (dist <= unit->master_obj->los) {
                        float rVal = target->damageCapability(unit);
                        float tempDamage = unit->rateOfFire();
                        if (tempDamage != 0.0f && rVal != 0.0f) {
                            rateOfFire = rVal / tempDamage + rateOfFire;
                        }
                    }
                }
            }
            i++;
        } while (i < maxImportantObjectMemory);
    }

    return rateOfFire;
}

int TribeInformationAIModule::costToLoseUnit(int id) {
    RGE_Static_Object* object = md->object(id);
    if (object == 0) {
        return -1;
    }
    return this->md->player->objectCostByType(object->master_obj->id);
}

int TribeInformationAIModule::benefitToKillUnit(int id) {
    RGE_Static_Object* object = this->md->object(id);
    if (object == 0)
        return -1;
    return object->owner->objectCostByType(object->master_obj->id);
}

int TribeInformationAIModule::inRangeOfUnits(
    int playerID, int x, int y, int useJustRange) {
    int i = 0;

    if (this->maxImportantObjectMemory > 0) {
        while (true) {
            if ((playerID == -1 || (int)this->importantObjectMemory[i].owner == playerID) && (playerID != -1 ||
                 this->md->player->isEnemy(this->importantObjectMemory[i].owner) != 0)) {
                RGE_Static_Object* object = this->md->object(this->importantObjectMemory[i].id);
                if (object != 0 && object->object_state <= 2) {
                    float distance = object->distance_to_position((float)x, (float)y, object->world_z);
                    float range = object->weaponRange();
                    if (useJustRange == 0 && object->master_obj->los > distance) {
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

ObjectMemory* TribeInformationAIModule::wonderToAttack(int playerID) {
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
                if (playerID == -1 || this->importantObjectMemory[i].owner == playerID) {
                    if (playerID != -1 || this->md->player->isEnemy(this->importantObjectMemory[i].owner)) {
                        RGE_Static_Object* obj = this->md->object(this->importantObjectMemory[i].id);
                        if (obj != 0) {
                            if (obj->object_state <= 2) {
                                RGE_Action_Object* actionObject =
                                    static_cast<RGE_Action_Object*>(obj);
                                if (actionObject->actions->have_action()) {
                                    RGE_Action* action =
                                        actionObject->actions->get_action();
                                    if (action->type() == 0x78) {
                                        action = actionObject->actions->get_action();
                                        int state = action->state;
                                        action = actionObject->actions->get_action();
                                        float timer = action->timer;
                                        float hitpoints = obj->hp;
                                        if (bestObject == 0) {
                                            bestObject = &this->importantObjectMemory[i];
                                            bestState = state;
                                            bestTimer = timer;
                                            bestHitpoints = hitpoints;
                                        } else if (bestState == 6 && state == 2) {
                                        } else if (bestState == 2 && state == 6) {
                                            bestObject = &this->importantObjectMemory[i];
                                            bestState = state;
                                            bestTimer = timer;
                                            bestHitpoints = hitpoints;
                                        } else if (bestState == state && bestState == 2 && bestHitpoints < hitpoints) {
                                            bestObject = &this->importantObjectMemory[i];
                                            bestState = state;
                                            bestTimer = timer;
                                            bestHitpoints = hitpoints;
                                        // TEST AH,41h followed by JNE rejects unordered values.
                                        } else if (bestState == state && bestState == 6 && bestTimer > timer) {
                                            bestObject = &this->importantObjectMemory[i];
                                            bestState = state;
                                            bestTimer = timer;
                                            bestHitpoints = hitpoints;
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

ObjectMemory* TribeInformationAIModule::ruinToCapture(int playerID) {
    RGE_Static_Object* townCenter;
    int bestValue;
    int i;
    ObjectMemory* bestMem;

    townCenter = this->md->object(-1, 0x6D, -1, -1, -1, -1, -1, -1, -1, -1);
    bestMem = 0;
    bestValue = -1;
    i = 0;

    if (this->maxImportantObjectMemory > 0) {
        do {
            if (this->importantObjectMemory[i].type == 0x9E || this->importantObjectMemory[i].type == 0xA3) {
                if ((playerID == -1 || (unsigned int)this->importantObjectMemory[i].owner == (unsigned int)playerID) &&
                    (playerID != -1 || this->md->player->isEnemy(this->importantObjectMemory[i].owner) != 0)) {
                    RGE_Static_Object* object = this->md->object(this->importantObjectMemory[i].id);

                    if (object != 0 && object->object_state <= 2) {
                        int result = this->numberUnitsWithinXTiles(playerID, this->importantObjectMemory[i].x,
                                                                   this->importantObjectMemory[i].y, 5);

                        if (townCenter != 0) {
                            int distance = (int)townCenter->distance_to_position((float)this->importantObjectMemory[i].x,
                                                                                 (float)this->importantObjectMemory[i].y, (float)this->importantObjectMemory[i].z);
                            result = distance * result;
                        }

                        if (bestMem == 0 || result < bestValue) {
                            bestValue = result;
                            bestMem = &this->importantObjectMemory[i];
                        }
                    }
                }
            }

            i++;
        } while (i < this->maxImportantObjectMemory);
    }

    return bestMem;
}

ObjectMemory* TribeInformationAIModule::artifactToCapture(int playerID) {
    RGE_Static_Object* townCenter;
    ObjectMemory* bestMem;
    int bestValue;
    int i;
    RGE_Visible_Map* vMap;

    townCenter = this->md->object(-1, 0x6D, -1, -1, -1, -1, -1, -1, -1, -1);
    bestMem = 0;
    bestValue = -1;
    i = 0;
    vMap = this->md->player->visible;

    if (this->maxImportantObjectMemory > 0) {
        do {
            if (this->importantObjectMemory[i].type == 0x9F) {
                if (playerID == -1 || (int)this->importantObjectMemory[i].owner == playerID) {
                    if (playerID != -1 || this->md->player->isEnemy(this->importantObjectMemory[i].owner) != 0) {
                        RGE_Static_Object* artifact = this->md->object(this->importantObjectMemory[i].id);
                        if (artifact != 0 && artifact->object_state <= 2) {
                            int artifactX = (int)artifact->world_x;
                            int artifactY = (int)artifact->world_y;
                            if (vMap->get_visible(artifactX, artifactY) != 0) {
                                this->importantObjectMemory[i].x =
                                    (unsigned char)(int)artifact->world_x;
                                this->importantObjectMemory[i].y =
                                    (unsigned char)(int)artifact->world_y;
                                this->importantObjectMemory[i].z =
                                    (unsigned char)(int)artifact->world_z;
                                int result = this->numberUnitsWithinXTiles(playerID, artifactX, artifactY, 5);
                                if (townCenter != 0) {
                                    int distance = (int)townCenter->distance_to_object(artifact);
                                    result = distance * result;
                                }
                                if (bestMem == 0 || result < bestValue) {
                                    bestValue = result;
                                    bestMem =
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
    return bestMem;
}

int TribeInformationAIModule::resourceTypeToPlaceDropsiteBy(int dropsiteType) {
    if (dropsiteType == 2) return 0;

    if (!md->buildAI.numberBuiltOrInProgressItemsOfType(0x67, 0) && closestDropsiteValue[1] != -1)
        return 1;

    if (dropsiteType == 1) {
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
    int& numDS, int rType, int maxDistance) {
    int totalApplicable;
    int a;

    numDS = 0;
    totalApplicable = 0;
    ManagedArray_int dropsites;
    a = 0;

    if (this->numResources[rType] > 0) {
        do {
            if (this->resources[rType][a].gone != 1) {
                if (this->md->object(this->resources[rType][a].id) != 0) {
                    ++totalApplicable;
                    if ((int)this->resources[rType][a].dropDistance <= maxDistance) {
                        if (dropsites.contains(this->resources[rType][a].dropsiteID) == 0) {
                            ++numDS;
                            int dropsiteID = this->resources[rType][a].dropsiteID;
                            dropsites.add(dropsiteID);
                        }
                    }
                }
            }

            ++a;
        } while (a < this->numResources[rType]);
    }

    if (totalApplicable > 0) {
        return 1;
    } else {
        return 0;
    }
}

int TribeInformationAIModule::numberAvailableStoragePits(int rType) {
    int age_idx = (int)(this->md->player->attributes[6]);
    age_idx--;

    if (age_idx < 0) {
        age_idx = 0;
    } else if (age_idx > 3) {
        age_idx = 3;
    }

    if (this->dropsitesByAge[rType][age_idx] == 0) {
        return 0;
    }

    RGE_Static_Object* town_center = this->md->object(-1, 0x6D, -1, -1, -1, -1, -1, -1, -1, -1);

    if (town_center != 0) {
        RGE_Static_Object* closest_dropsite =
            this->md->object(this->closestDropsiteResourceID[rType]);

        if (closest_dropsite != 0) {
            int zone = town_center->currentZone() & 0xff;
            int y = (int)(closest_dropsite->world_y);
            int x = (int)(closest_dropsite->world_x);
            int lookup = town_center->lookupZone(x, y) & 0xff;

            if (zone != lookup) {
                return 0;
            }
        }
    }

    return this->closestDropsiteValue[rType] >
           this->md->tacticalAI.strategicNumber(rType + 0xA3);
}

int TribeInformationAIModule::numberAvailableGranaries() {
    if (this->closestDropsiteValue[0] == -1) {
        return 0;
    }

    RGE_Static_Object* town_center = this->md->object(-1, 0x6D, -1, -1, -1, -1, -1, -1, -1, -1);

    if (town_center != 0) {
        RGE_Static_Object* closest_dropsite = this->md->object(this->closestDropsiteResourceID[0]);

        if (closest_dropsite != 0) {
            int zone = town_center->currentZone() & 0xff;
            int dropsite_y = (int)closest_dropsite->world_y;
            int dropsite_x = (int)closest_dropsite->world_x;
            int lookup = town_center->lookupZone(dropsite_x, dropsite_y) & 0xff;
            if (zone != lookup) {
                return 0;
            }
        }
    }

    int strategic_number = this->md->tacticalAI.strategicNumber(0xA3);
    return (strategic_number < this->closestDropsiteValue[0]) ? 1 : 0;
}

void TribeInformationAIModule::lookAtMap() {
    RGE_Map* gMap = this->md->player->world->map;
    int x = 0;

    if (this->mapXSizeValue > 0) {
        do {
            int y = 0;

            if (this->mapYSizeValue > 0) {
                do {
                    int tileType = gMap->map_row_offset[y][x].terrain_type & 0x1F;

                    if (this->mapXSizeValue != -1) {
                        int qx = (x * 4) / this->mapXSizeValue;
                        int qy = (y * 4) / this->mapYSizeValue;
                        this->quadrantLog[qx][qy].numberExploredTiles++;
                    }

                    this->pathMap.setValue(x, y, 0);

                    int numberTreesOnTile = 0;
                    RGE_Object_Node* node =
                        gMap->map_row_offset[y][x].objects.list;
                    while (node != 0) {
                        RGE_Static_Object* object = node->node;
                        int object_group = object->master_obj->object_group;

                        if (this->importantObject(object_group) == 1)
                            this->addImportantObject(object, 0);

                        if (object_group == 0x0F)
                            numberTreesOnTile++;

                        node = node->next;
                    }

                    if (numberTreesOnTile > 0 && (tileType == 0x0A || tileType == 0x13 ||
                         tileType == 0x0D || tileType == 0x14))
                        this->numberFoundForestTilesValue++;

                    ++y;
                } while (y < this->mapYSizeValue);
            }

            ++x;
        } while (x < this->mapXSizeValue);
    }
}

float TribeInformationAIModule::damageInflictedPerSecond(
    TacticalAIGroup* group, RGE_Static_Object* obj) {
    float rVal = 0.0f;
    int i = 0;
    int count = group->numberUnits();

    if (count > 0) {
        do {
            int unitID = group->unit(i);
            RGE_Static_Object* unit = this->md->object(unitID);

            if (unit != 0) {
                rVal = obj->damageCapability(unit) /
                           unit->rateOfFire() +
                       rVal;
            }

            i++;
            count = group->numberUnits();
        } while (i < count);
    }

    return rVal;
}

float TribeInformationAIModule::damageInflictedPerSecond(
    int* group, int groupSize, RGE_Static_Object* obj) {
    float rVal = 0.0f;
    for (int i = 0; i < groupSize; i++) {
        RGE_Static_Object* unit = this->md->object(group[i]);
        if (unit != 0) {
            rVal += obj->damageCapability(unit) / unit->rateOfFire();
        }
    }
    return rVal;
}

float TribeInformationAIModule::timeToBeKilled(
    TacticalAIGroup* group, RGE_Static_Object* obj) {
    float rVal = 0.0f;
    int i = 0;

    int n = group->numberUnits();
    if (n > 0) {
        do {
            int uid = group->unit(i);
            RGE_Static_Object* unit = this->md->object(uid);

            if (unit) {
                float dps = this->damagePerSecond(group->unit(i), (int)obj->world_x, (int)obj->world_y);

                if (dps == 0.0f) {
                    dps = 600.0f;
                } else {
                    dps = unit->hp / dps;
                }

                rVal += dps;
            }

            i++;
        } while (i < group->numberUnits());
    }

    return rVal;
}

float TribeInformationAIModule::timeToBeKilled(
    int* group, int groupSize, RGE_Static_Object* obj) {
    float rVal = 0.0f;
    int remaining;
    int* p;
    RGE_Static_Object* unit;
    int a;
    int b;
    float dps;

    if (groupSize > 0) {
        remaining = groupSize;
        p = group;
        do {
            unit = this->md->object(*p);
            if (unit != 0) {
                a = (int)(obj->world_y);
                b = (int)(obj->world_x);
                dps = this->damagePerSecond(*p, b, a);
                if (dps == 0.0f) {
                    dps = 600.0f;
                } else {
                    dps = unit->hp / dps;
                }
                rVal = rVal + dps;
            }
            p++;
            remaining--;
        } while (remaining != 0);
    }
    return rVal;
}

int TribeInformationAIModule::closestDropsiteResID(int rType) const {
    if (rType < 0 || rType > 3) {
        return -1;
    }
    return this->closestDropsiteResourceID[rType];
}

int TribeInformationAIModule::calculatePlayVariation(int playID) {
    (void)playID;
    int totalPlays = 0;
    for (int i = 0; i < 0x3E80; ++i) {
        totalPlays += this->playHistory[i];
    }

    return 100 - (int)((float)this->unitHistory[0] / (float)totalPlays * 100.0f);
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

    int fd = rge_open(historyFileName, _O_BINARY);
    if (fd != -1) {
        rge_read(fd, (char*)this + 0xFF64, 44);
        rge_close(fd);
    }
}

void TribeInformationAIModule::unitsThatAreMostBuilt(int& rVal1, int& rVal2) {
    int* history;
    int i;
    int bestValue;

    history = this->unitHistory;
    rVal1 = -1;
    bestValue = -1;
    for (i = 0; i < 11; i++) {
        if (bestValue == -1 || bestValue < history[i]) {
            rVal1 = i;
            bestValue = history[i];
        }
    }

    rVal2 = -1;
    bestValue = -1;
    for (i = 0; i < 11; i++) {
        if (i != rVal1 && (bestValue == -1 || bestValue < history[i])) {
            rVal2 = i;
            bestValue = history[i];
        }
    }
}

void TribeInformationAIModule::unitsThatAreLeastBuilt(int& rVal1, int& rVal2) {
    int* history;
    int i;
    int bestValue;

    history = this->unitHistory;
    rVal1 = 0x7FFFFFFF;
    bestValue = -1;
    for (i = 0; i < 11; i++) {
        if (bestValue == -1 || bestValue > history[i]) {
            rVal1 = i;
            bestValue = history[i];
        }
    }

    rVal2 = 0x7FFFFFFF;
    bestValue = -1;
    for (i = 0; i < 11; i++) {
        if (i != rVal1 && (bestValue == -1 || bestValue > history[i])) {
            rVal2 = i;
            bestValue = history[i];
        }
    }
}

int TribeInformationAIModule::acceptablePotentialDropsiteArea(int x, int y) {
    int s = this->md->tacticalAI.strategicNumber(0xCA) *
            this->md->tacticalAI.strategicNumber(0xCA);

    for (int i = 0; i < this->maxImportantObjectMemory; i++) {
        uchar owner = this->importantObjectMemory[i].owner;
        if (this->md->player->isEnemy(owner) != 0) {
            short type = this->importantObjectMemory[i].type;
            if (type == 0x6D || type == 0x67 || type == 0x44 || type == 0x4F || type == 0xC7 || type == 0x45) {
                int object_x = (int)this->importantObjectMemory[i].x;
                int object_y = (int)this->importantObjectMemory[i].y;
                int dx = object_x - x;
                int dy = object_y - y;
                if (dx * dx + dy * dy <= s)
                    return 0;
            }
        }
    }
    return 1;
}

int TribeInformationAIModule::percentTilesExploredInPositionQuadrant(int x, int y) {
    if (this->mapXSizeValue == -1) {
        return 0;
    }

    int qx = x * 4 / this->mapXSizeValue;
    int numTilesInQuadrant = this->mapXSizeValue / 4 *
                             this->mapYSizeValue / 4;
    int qy = y * 4 / this->mapYSizeValue;

    return this->quadrantLog[qx][qy].numberExploredTiles * 100 /
           numTilesInQuadrant;
}
