
#include "../include/aibldmod.h"
#include <string.h>

// The canonical member initializers own the BuildItem,
// scalar, ManagedArray, and derived virtual setup.
BuildAIModule::BuildAIModule(void* param_1, int param_2)
    : AIModule("Build AI", 0x3E9, param_2, param_1),
      buildList(), buildListLengthValue(0), numberItemsIntoBuildListValue(0)
{
    this->buildList.next = &this->buildList;
    this->buildList.prev = &this->buildList;
    strcpy(this->buildListNameValue, "");
    strcpy(this->lastBuildItemRequestedValue, "None");
    strcpy(this->currentBuildItemRequestedValue, "None");
    strcpy(this->nextBuildItemRequestedValue, "None");
}

// The serialized fields, local declaration order, and name
// buffer size preserve the original constructor frame and call sequence.
#include <stdlib.h>
BuildAIModule::BuildAIModule(int p1, int fd)
    : AIModule("Build AI", 0x3e9, p1, 0), buildList(),
      buildListLengthValue(0), numberItemsIntoBuildListValue(0)
{
    int buildCap;
    int buildCapValue;
    int builtValue;
    int inProgressValue;
    int buildAttemptsValue;
    int terrainAdjacencyOne;
    int skipValue;
    float zSize;
    int gameID;
    float xSize;
    float x;
    int uniqueID;
    float y;
    int buildCategory;
    float z;
    int terrainAdjacencyTwo;
    int numberBuilds;
    float ySize;
    int skipCycles;
    int typeID;
    unsigned char permanentSkip;
    int terrainSet;
    int placeOnElevation;
    int buildFrom;
    char name[257];

    this->buildList.next = &this->buildList;
    this->buildList.prev = &this->buildList;
    rge_read(fd, &this->buildListLengthValue, 4);
    rge_read(fd, &buildCap, 4);
    rge_read(fd, this->buildListNameValue, buildCap);
    this->buildListNameValue[buildCap] = 0;
    rge_read(fd, &buildCap, 4);
    rge_read(fd, this->lastBuildItemRequestedValue, buildCap);
    this->lastBuildItemRequestedValue[buildCap] = 0;
    rge_read(fd, &buildCap, 4);
    rge_read(fd, this->currentBuildItemRequestedValue, buildCap);
    this->currentBuildItemRequestedValue[buildCap] = 0;
    if (save_game_version >= version_3_1) {
        rge_read(fd, &buildCap, 4);
        rge_read(fd, this->nextBuildItemRequestedValue, buildCap);
        this->nextBuildItemRequestedValue[buildCap] = 0;
    } else {
        strcpy(this->nextBuildItemRequestedValue, "None");
    }
    rge_read(fd, &this->numberItemsIntoBuildListValue, 4);

    int i = 0;
    if (this->buildListLengthValue > 0) {
        do {
            rge_read(fd, &buildCap, 4);
            rge_read(fd, name, buildCap);
            name[buildCap] = 0;
            rge_read(fd, &typeID, 4);
            rge_read(fd, &gameID, 4);
            rge_read(fd, &uniqueID, 4);
            rge_read(fd, &x, 4);
            rge_read(fd, &y, 4);
            rge_read(fd, &z, 4);
            rge_read(fd, &xSize, 4);
            rge_read(fd, &ySize, 4);
            rge_read(fd, &zSize, 4);
            rge_read(fd, &skipValue, 4);
            rge_read(fd, &buildCategory, 4);
            rge_read(fd, &inProgressValue, 4);
            rge_read(fd, &builtValue, 4);
            rge_read(fd, &buildAttemptsValue, 4);
            rge_read(fd, &buildFrom, 4);
            rge_read(fd, &terrainSet, 4);
            rge_read(fd, &terrainAdjacencyOne, 4);
            rge_read(fd, &terrainAdjacencyTwo, 4);
            rge_read(fd, &placeOnElevation, 4);
            rge_read(fd, &numberBuilds, 4);
            buildCapValue = -1;
            if (save_game_version >= version_2_2) {
                rge_read(fd, &buildCapValue, 4);
            }
            rge_read(fd, &skipCycles, 4);
            rge_read(fd, &permanentSkip, 1);
            BuildItem* item = new BuildItem(buildCategory, typeID, uniqueID, 1, 0, buildFrom, name, xSize, ySize, zSize, terrainSet, terrainAdjacencyOne, terrainAdjacencyTwo, placeOnElevation);
            item->setBuilt(builtValue);
            item->setInProgress(inProgressValue);
            item->setBuildAttempts(buildAttemptsValue);
            item->setSkip(skipValue);
            item->setGameID(gameID);
            item->setX(x);
            item->setY(y);
            item->setZ(z);
            item->setNumberBuilds(numberBuilds);
            item->setBuildCap(buildCapValue);
            item->setSkipCycles(skipCycles);
            item->setPermanentSkip(permanentSkip);
            i++;
            item->next = &this->buildList;
            BuildItem* prev = this->buildList.prev;
            item->prev = prev;
            prev->next = item;
            this->buildList.prev = item;
        } while (i < this->buildListLengthValue);
    }
}

BuildAIModule::~BuildAIModule()
{
    if (buildListLengthValue > 0)
        removeOldList();
}

int BuildAIModule::save(int file) {
    char tempString[257];
    int tempInt; float tempFloat; int iStack_110; unsigned char local_109;
    rge_write(file, &this->buildListLengthValue, 4);
    strcpy(tempString, this->buildListNameValue); tempInt = strlen(tempString); rge_write(file, &tempInt, 4); rge_write(file, tempString, strlen(tempString));
    strcpy(tempString, this->lastBuildItemRequestedValue); tempInt = strlen(tempString); rge_write(file, &tempInt, 4); rge_write(file, tempString, strlen(tempString));
    strcpy(tempString, this->currentBuildItemRequestedValue); tempInt = strlen(tempString); rge_write(file, &tempInt, 4); rge_write(file, tempString, strlen(tempString));
    strcpy(tempString, this->nextBuildItemRequestedValue); tempInt = strlen(tempString); rge_write(file, &tempInt, 4); rge_write(file, tempString, strlen(tempString));
    rge_write(file, &this->numberItemsIntoBuildListValue, 4);
    BuildItem* item = this->buildList.next;
    BuildItem* end = &this->buildList;
    while (item != end) {
        if (item == 0) return 1;
        strcpy(tempString, item->name()); tempInt = strlen(tempString); rge_write(file, &tempInt, 4); rge_write(file, tempString, strlen(tempString));
        tempInt = item->typeID(); rge_write(file, &tempInt, 4);
        tempInt = item->gameID(); rge_write(file, &tempInt, 4);
        tempInt = item->uniqueID(); rge_write(file, &tempInt, 4);
        tempFloat = item->x(); rge_write(file, &tempFloat, 4);
        tempFloat = item->y(); rge_write(file, &tempFloat, 4);
        tempFloat = item->z(); rge_write(file, &tempFloat, 4);
        tempFloat = item->xSize(); rge_write(file, &tempFloat, 4);
        tempFloat = item->ySize(); rge_write(file, &tempFloat, 4);
        tempFloat = item->zSize(); rge_write(file, &tempFloat, 4);
        iStack_110 = item->skip(); rge_write(file, &iStack_110, 4);
        tempInt = item->buildCategory(); rge_write(file, &tempInt, 4);
        iStack_110 = item->inProgress(); rge_write(file, &iStack_110, 4);
        iStack_110 = item->built(); rge_write(file, &iStack_110, 4);
        tempInt = item->buildAttempts(); rge_write(file, &tempInt, 4);
        tempInt = item->buildFrom(); rge_write(file, &tempInt, 4);
        tempInt = item->terrainSet(); rge_write(file, &tempInt, 4);
        tempInt = item->terrainAdjacency(1); rge_write(file, &tempInt, 4);
        tempInt = item->terrainAdjacency(2); rge_write(file, &tempInt, 4);
        iStack_110 = item->placeOnElevation(); rge_write(file, &iStack_110, 4);
        tempInt = item->numberBuilds(); rge_write(file, &tempInt, 4);
        tempInt = item->buildCap(); rge_write(file, &tempInt, 4);
        tempInt = item->skipCycles(); rge_write(file, &tempInt, 4);
        local_109 = item->permanentSkip();
        rge_write(file, &local_109, 1);
        item = (BuildItem*)item->next;
    }
    return 1;
}

void BuildAIModule::displayBuildList()
{
    this->logCommonHistory("Build list '%s':", buildListNameValue);

    BuildItem* item = this->buildList.next;
    BuildItem* sentinel = &this->buildList;

    while (item != sentinel && item != 0) {
        if (item->built() == 1) {
            this->logCommonHistory(
                "BLT Type=%-4d %-20s gID=%-4d Cat=%d uID=%d InPrg=%d BlATmpt=%d Skip=%d NumBld=%d BldCap=%d From=%d PrSkp=%d SkpCyc=%d",
                item->typeID(), item->name(), item->gameID(),
                item->buildCategory(), item->uniqueID(), item->inProgress(),
                item->buildAttempts(), item->skip(), item->numberBuilds(),
                item->buildCap(), item->buildFrom(),
                (unsigned int)item->permanentSkip(), item->skipCycles());
        } else {
            this->logCommonHistory(
                "    Type=%-4d %-20s gID=%-4d Cat=%d uID=%d InPrg=%d BlATmpt=%d Skip=%d NumBld=%d BldCap=%d From=%d PrSkp=%d SkpCyc=%d",
                item->typeID(), item->name(), item->gameID(),
                item->buildCategory(), item->uniqueID(), item->inProgress(),
                item->buildAttempts(), item->skip(), item->numberBuilds(),
                item->buildCap(), item->buildFrom(),
                (unsigned int)item->permanentSkip(), item->skipCycles());
        }

        item = item->next;
    }
}

// This source retains the executable's dead NULL test against
// the in-object buildListNameValue array.
#include <stdio.h>
#include <io.h>
int BuildAIModule::loadBuildList(char* filename, RGE_Player* player)
{
    int typeID;
    int quantity;
    int buildFrom;
    int fileIn;
    char name[64];
    char temp[256];
    FILE* fp;
    float ySize;
    float xSize;
    char commentTemp1;
    char buildCategoryAsChar;
    char commentTemp2;

    strncpy(this->buildListNameValue, filename, 0x3F);
    if (strcmp(this->buildListNameValue, "NONE") == 0 ||
        this->buildListNameValue == 0 ||
        strlen(this->buildListNameValue) == 0) {
        goto no_build_list;
    }

    this->logCommonHistory("Trying to load build list in file '%s'.", filename);
    sprintf(temp, "%s", this->buildListNameValue);
    fp = fopen(temp, "r");
    if (fp == 0) {
        this->logCommonHistory("  I cannot do it cap'n!");
        return 0;
    }

    this->logCommonHistory("  File open successful, nuking any old items.");
    if (this->buildListLengthValue > 0) {
        this->removeOldList();
    }
    this->buildListLengthValue = 0;

    while (fgets(temp, 0x100, fp) != 0) {
        xSize = ySize = 1.5f;
        typeID = -1;
        sscanf(temp, " %c%c", &commentTemp1, &commentTemp2);
        if (commentTemp1 == '/' && commentTemp2 == '/') {
            continue;
        }

        sscanf(temp, " %c%d %s %d %d ", &buildCategoryAsChar,
               &quantity, name, &buildFrom, &fileIn);

        int buildCategory;
        switch (buildCategoryAsChar) {
        case '\n':
            continue;
        default:
            continue;
        case 'B':
            buildCategory = 0;
            break;
        case 'A':
            buildCategory = 0;
            sscanf(temp, "%*c%*d %*s %*d %*d %d ", &typeID);
            break;
        case 'R':
            buildCategory = 1;
            break;
        case 'C':
            buildCategory = 4;
            break;
        case 'U':
            buildCategory = 2;
            break;
        case 'T':
            buildCategory = 2;
            sscanf(temp, "%*c%*d %*s %*d %*d %d ", &typeID);
            break;
        case 'L':
            buildCategory = 3;
            break;
        case 'E':
            buildCategory = 5;
            break;
        case 'G':
            buildCategory = 6;
            break;
        }

        if (buildCategory == 0) {
            if (this->typesToIgnore.contains(quantity)) {
                goto next_line;
            }
        }

        if ((buildCategory == 0 || buildCategory == 2) && quantity >= 0 &&
            quantity < player->master_object_num &&
            player->master_objects[quantity] != 0) {
            RGE_Master_Static_Object* master = player->master_objects[quantity];
            ySize = master->radius_x;
            xSize = master->radius_y;
        }
        ySize += ySize;
        xSize += xSize;

        int i;
        for (i = 0; i < buildFrom; ++i) {
            BuildItem* item = new BuildItem(
                buildCategory, quantity, this->buildListLengthValue,
                1, 0, fileIn, name, ySize, xSize, 0.0f,
                -1, -1, -1, 0);

            ++this->buildListLengthValue;
            item->next = &this->buildList;
            BuildItem* oldTail = this->buildList.prev;
            item->prev = oldTail;
            oldTail->next = item;
            item->setBuildCap(typeID);
            this->buildList.prev = item;
        }

    next_line:
        ;
    }

    fclose(fp);
    if (strstr(this->buildListNameValue, ".tmp") != 0) {
        unlink(this->buildListNameValue);
    }
    return 1;

no_build_list:
    if (this->buildListNameValue == 0) {
        strcpy(this->buildListNameValue, "NULL");
    }
    this->logCommonHistory("There is no build list to load.");
    return 1;
}

int BuildAIModule::buildListLength() const { return this->buildListLengthValue; }

char* BuildAIModule::buildListName() { return this->buildListNameValue; }

int BuildAIModule::haveBuildList() const {
    char* name = (char*)this->buildListNameValue;
    if (name != 0 && strcmp(name, "NONE") != 0 && strcmp(name, "NULL") != 0) return 1;
    return 0;
}

static const char s_SetGatherPercentage[] = "SetGatherPercentage";
static const char s_AddedBuildListItem[] = "AddedBuildListItem";
int BuildAIModule::insertItem(RGE_Player* player, int objType, int count, int itemType, int p5, int buildCap, int index)
{
    BuildItem* pos;
    int i;
    int j;
    char name[64];
    float sx;
    float sy;

    if (index > this->buildListLengthValue) return 0;
    pos = this->buildList.next;
    i = 0;
    while (pos != &this->buildList && i < index) {
        pos = pos->next;
        i++;
    }
    // The special arm and shared strncpy tail retain the
    // original branch and call order.
    if (itemType != 6) {
        if (player->master_objects[objType] != 0) {
            strncpy(name + 4, player->master_objects[objType]->name, 0x3f);
            sx = player->master_objects[objType]->radius_x +
                 player->master_objects[objType]->radius_x;
            sy = player->master_objects[objType]->radius_y +
                 player->master_objects[objType]->radius_y;
            goto name_done;
        } else {
            strncpy(name + 4, s_AddedBuildListItem, 0x3f);
            sx = 3.0f;
            sy = 3.0f;
        }
    } else {
        strncpy(name + 4, s_SetGatherPercentage, 0x3f);
        sx = 3.0f;
        sy = 3.0f;
    }

name_done:
    int seq = this->buildListLengthValue;
    for (j = 0; j < count; ++j) {
        BuildItem* item = new BuildItem(itemType, objType, seq, 1, 0, p5, name + 4, sx, sy, 1.0f, -1, -1, -1, 0);
        if (item == 0) return 0;
        item->setBuilt(0);
        item->setInProgress(0);
        item->setBuildAttempts(0);
        item->setSkip(0);
        item->setGameID(-1);
        item->setX(-1.0f);
        item->setY(-1.0f);
        item->setZ(-1.0f);
        item->setNumberBuilds(0);
        item->setBuildCap(buildCap);
        item->setSkipCycles(0);
        item->setPermanentSkip(0);
        item->prev = pos;
        BuildItem* next = pos->next;
        item->next = next;
        seq++;
        next->prev = item;
        pos->next = item;
        this->buildListLengthValue++;
    }
    return 1;
}

int BuildAIModule::numberItemsBuilt(void) const {
    const BuildItem* current = this->buildList.next;
    const BuildItem* end = &this->buildList;
    int count = 0;
    while (current != end && current != 0) {
        if (current->built() == 1) {
            count++;
        }
        current = current->next;
    }
    return count;
}

int BuildAIModule::numberItemsInProgress(void) const {
    const BuildItem* current = this->buildList.next;
    const BuildItem* end = &this->buildList;
    int count = 0;
    while (current != end && current != 0) {
        if (current->inProgress() == 1) {
            count++;
        }
        current = current->next;
    }
    return count;
}

int BuildAIModule::numberItemsBuiltOrInProgress(void) const {
    const BuildItem* item = this->buildList.next;
    const BuildItem* end = &this->buildList;
    int count = 0;

    while (item != end && item != 0) {
        if (item->inProgress() == 1 || item->built() == 1) {
            count++;
        }
        item = item->next;
    }

    return count;
}

int BuildAIModule::numberItemsIntoBuildList() const { return this->numberItemsIntoBuildListValue; }

char* BuildAIModule::lastBuildItemRequested() const { return (char*)this->lastBuildItemRequestedValue; }

char* BuildAIModule::currentBuildItemRequested() const { return (char*)this->currentBuildItemRequestedValue; }

char* BuildAIModule::nextBuildItemRequested() const { return (char*)this->nextBuildItemRequestedValue; }

int BuildAIModule::numberItemsOfType(int typeID, int buildCategory) {
    BuildItem* cur = this->buildList.next;
    int count = 0;
    BuildItem* sentinel = &this->buildList;
    while (cur != sentinel && cur != 0) {
        if (cur->typeID() == typeID && cur->buildCategory() == buildCategory) {
            count++;
        }
        cur = cur->next;
    }
    return count;
}

int BuildAIModule::numberBuiltItemsOfType(int param_1, int param_2) {
    BuildItem* item = this->buildList.next;
    BuildItem* sentinel = &this->buildList;
    int count = 0;

    while (item != sentinel && item != 0) {
        if (item->typeID() == param_1 && item->buildCategory() == param_2 && item->built() == 1) {
            ++count;
        }
        item = item->next;
    }

    return count;
}

int BuildAIModule::numberUnbuiltItemsOfType(int param_1, int param_2) {
    BuildItem* item = this->buildList.next;
    BuildItem* sentinel = &this->buildList;
    int count = 0;

    while (item != sentinel && item != 0) {
        if (item->typeID() == param_1 && item->buildCategory() == param_2 && item->built() == 0) {
            ++count;
        }
        item = item->next;
    }

    return count;
}

int BuildAIModule::numberBuiltOrInProgressItemsOfType(int type_id, int build_category) {
    int count = 0;
    BuildItem* item = this->buildList.next;
    BuildItem* end = &this->buildList;

    while (item != end && item != 0) {
        if (item->typeID() == type_id && item->buildCategory() == build_category && (item->built() == 1 || item->inProgress() == 1)) {
            ++count;
        }
        item = item->next;
    }

    return count;
}

int BuildAIModule::numberInProgressItemsOfType(int param_1, int param_2) {
    BuildItem* item = this->buildList.next;
    BuildItem* sentinel = &this->buildList;
    int count = 0;

    while (item != sentinel && item != 0) {
        if (item->typeID() == param_1 && item->buildCategory() == param_2 && item->inProgress() == 1) {
            ++count;
        }
        item = item->next;
    }

    return count;
}

void BuildAIModule::removeOldList(void) {
    BuildItem* current = this->buildList.next;
    BuildItem* end = &this->buildList;

    while (current != end && current != 0) {
        BuildItem* next = current->next;
        delete current;
        current = next;
    }

    this->buildList.next = end;
    this->buildList.prev = end;
    this->buildListLengthValue = 0;
}

BuildItem* BuildAIModule::anyBuildListItem(int param_1, int param_2, int param_3) {
    BuildItem* item = this->buildList.next;
    BuildItem* sentinel = &this->buildList;

    while (item != sentinel && item != 0) {
        if (item->typeID() == param_1) {
            if (param_2 == 0) {
                return item;
            }
            if (param_2 == 1) {
                if (item->built() == param_3) {
                    return item;
                }
            }
        }
        item = item->next;
    }

    return 0;
}

// The original checks the sentinel before loading the id.
BuildItem* BuildAIModule::specificBuildListItem(int uniqueID)
{
    BuildItem* item = this->buildList.next;
    if (item == &this->buildList) return 0;

    int saveID = uniqueID;
    while (item != &this->buildList) {
        if (item == 0) return 0;
        if (item->uniqueID() == saveID) return item;
        item = item->next;
    }
    return 0;
}
