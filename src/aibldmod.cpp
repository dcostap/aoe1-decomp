
#include "../include/aibldmod.h"
#include <string.h>

// The canonical member initializers own the BuildItem,
// scalar, ManagedArray, and derived virtual setup.
BuildAIModule::BuildAIModule(void* pW, int playerID)
    : AIModule("Build AI", 0x3E9, playerID, pW),
      buildList(), buildListLengthValue(0), numberItemsIntoBuildListValue(0) {
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
BuildAIModule::BuildAIModule(int playerID, int infile)
    : AIModule("Build AI", 0x3e9, playerID, 0), buildList(),
      buildListLengthValue(0), numberItemsIntoBuildListValue(0) {
    int tempInt;
    int buildCap;
    int builtValue;
    int inProgressValue;
    int buildAttemptsValue;
    int terrainAdjOne;
    int skipValue;
    float zSize;
    int gameID;
    float xSize;
    float x;
    int uniqueID;
    float y;
    int buildCategory;
    float z;
    int terrainAdjTwo;
    int numberBuilds;
    float ySize;
    int numberSkipCycles;
    int typeID;
    unsigned char permanentSkip;
    int terrainSet;
    int placeOnElevation;
    int buildFrom;
    char name[257];

    this->buildList.next = &this->buildList;
    this->buildList.prev = &this->buildList;
    rge_read(infile, &this->buildListLengthValue, 4);
    rge_read(infile, &tempInt, 4);
    rge_read(infile, this->buildListNameValue, tempInt);
    this->buildListNameValue[tempInt] = 0;
    rge_read(infile, &tempInt, 4);
    rge_read(infile, this->lastBuildItemRequestedValue, tempInt);
    this->lastBuildItemRequestedValue[tempInt] = 0;
    rge_read(infile, &tempInt, 4);
    rge_read(infile, this->currentBuildItemRequestedValue, tempInt);
    this->currentBuildItemRequestedValue[tempInt] = 0;
    if (save_game_version >= 3.1f) {
        rge_read(infile, &tempInt, 4);
        rge_read(infile, this->nextBuildItemRequestedValue, tempInt);
        this->nextBuildItemRequestedValue[tempInt] = 0;
    } else {
        strcpy(this->nextBuildItemRequestedValue, "None");
    }
    rge_read(infile, &this->numberItemsIntoBuildListValue, 4);

    int i = 0;
    if (this->buildListLengthValue > 0) {
        do {
            rge_read(infile, &tempInt, 4);
            rge_read(infile, name, tempInt);
            name[tempInt] = 0;
            rge_read(infile, &typeID, 4);
            rge_read(infile, &gameID, 4);
            rge_read(infile, &uniqueID, 4);
            rge_read(infile, &x, 4);
            rge_read(infile, &y, 4);
            rge_read(infile, &z, 4);
            rge_read(infile, &xSize, 4);
            rge_read(infile, &ySize, 4);
            rge_read(infile, &zSize, 4);
            rge_read(infile, &skipValue, 4);
            rge_read(infile, &buildCategory, 4);
            rge_read(infile, &inProgressValue, 4);
            rge_read(infile, &builtValue, 4);
            rge_read(infile, &buildAttemptsValue, 4);
            rge_read(infile, &buildFrom, 4);
            rge_read(infile, &terrainSet, 4);
            rge_read(infile, &terrainAdjOne, 4);
            rge_read(infile, &terrainAdjTwo, 4);
            rge_read(infile, &placeOnElevation, 4);
            rge_read(infile, &numberBuilds, 4);
            buildCap = -1;
            if (save_game_version >= 2.2f) {
                rge_read(infile, &buildCap, 4);
            }
            rge_read(infile, &numberSkipCycles, 4);
            rge_read(infile, &permanentSkip, 1);
            BuildItem* item = new BuildItem(buildCategory, typeID, uniqueID, 1, 0, buildFrom, name, xSize, ySize, zSize, terrainSet, terrainAdjOne, terrainAdjTwo, placeOnElevation);
            item->setBuilt(builtValue);
            item->setInProgress(inProgressValue);
            item->setBuildAttempts(buildAttemptsValue);
            item->setSkip(skipValue);
            item->setGameID(gameID);
            item->setX(x);
            item->setY(y);
            item->setZ(z);
            item->setNumberBuilds(numberBuilds);
            item->setBuildCap(buildCap);
            item->setSkipCycles(numberSkipCycles);
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

BuildAIModule::~BuildAIModule() {
    if (buildListLengthValue > 0)
        removeOldList();
}

int BuildAIModule::save(int outfile) {
    char tempString[257];
    int tempInt;
    float tempFloat;
    int tempBOOL;
    unsigned char tempBYTE;
    rge_write(outfile, &this->buildListLengthValue, 4);
    strcpy(tempString, this->buildListNameValue);
    tempInt = strlen(tempString);
    rge_write(outfile, &tempInt, 4);
    rge_write(outfile, tempString, strlen(tempString));
    strcpy(tempString, this->lastBuildItemRequestedValue);
    tempInt = strlen(tempString);
    rge_write(outfile, &tempInt, 4);
    rge_write(outfile, tempString, strlen(tempString));
    strcpy(tempString, this->currentBuildItemRequestedValue);
    tempInt = strlen(tempString);
    rge_write(outfile, &tempInt, 4);
    rge_write(outfile, tempString, strlen(tempString));
    strcpy(tempString, this->nextBuildItemRequestedValue);
    tempInt = strlen(tempString);
    rge_write(outfile, &tempInt, 4);
    rge_write(outfile, tempString, strlen(tempString));
    rge_write(outfile, &this->numberItemsIntoBuildListValue, 4);
    BuildItem* item = this->buildList.next;
    BuildItem* end = &this->buildList;
    while (item != end) {
        if (item == 0) return 1;
        strcpy(tempString, item->name());
        tempInt = strlen(tempString);
        rge_write(outfile, &tempInt, 4);
        rge_write(outfile, tempString, strlen(tempString));
        tempInt = item->typeID();
        rge_write(outfile, &tempInt, 4);
        tempInt = item->gameID();
        rge_write(outfile, &tempInt, 4);
        tempInt = item->uniqueID();
        rge_write(outfile, &tempInt, 4);
        tempFloat = item->x();
        rge_write(outfile, &tempFloat, 4);
        tempFloat = item->y();
        rge_write(outfile, &tempFloat, 4);
        tempFloat = item->z();
        rge_write(outfile, &tempFloat, 4);
        tempFloat = item->xSize();
        rge_write(outfile, &tempFloat, 4);
        tempFloat = item->ySize();
        rge_write(outfile, &tempFloat, 4);
        tempFloat = item->zSize();
        rge_write(outfile, &tempFloat, 4);
        tempBOOL = item->skip();
        rge_write(outfile, &tempBOOL, 4);
        tempInt = item->buildCategory();
        rge_write(outfile, &tempInt, 4);
        tempBOOL = item->inProgress();
        rge_write(outfile, &tempBOOL, 4);
        tempBOOL = item->built();
        rge_write(outfile, &tempBOOL, 4);
        tempInt = item->buildAttempts();
        rge_write(outfile, &tempInt, 4);
        tempInt = item->buildFrom();
        rge_write(outfile, &tempInt, 4);
        tempInt = item->terrainSet();
        rge_write(outfile, &tempInt, 4);
        tempInt = item->terrainAdjacency(1);
        rge_write(outfile, &tempInt, 4);
        tempInt = item->terrainAdjacency(2);
        rge_write(outfile, &tempInt, 4);
        tempBOOL = item->placeOnElevation();
        rge_write(outfile, &tempBOOL, 4);
        tempInt = item->numberBuilds();
        rge_write(outfile, &tempInt, 4);
        tempInt = item->buildCap();
        rge_write(outfile, &tempInt, 4);
        tempInt = item->skipCycles();
        rge_write(outfile, &tempInt, 4);
        tempBYTE = item->permanentSkip();
        rge_write(outfile, &tempBYTE, 1);
        item = (BuildItem*)item->next;
    }
    return 1;
}

void BuildAIModule::displayBuildList() {
    this->logCommonHistory("Build list '%s':", buildListNameValue);

    BuildItem* item = this->buildList.next;
    BuildItem* sentinel = &this->buildList;

    while (item != sentinel && item != 0) {
        if (item->built() == 1) {
            this->logCommonHistory(
                "BLT Type=%-4d %-20s gID=%-4d Cat=%d uID=%d InPrg=%d BlATmpt=%d Skip=%d NumBld=%d BldCap=%d From=%d PrSkp=%d SkpCyc=%d",
                item->typeID(), item->name(), item->gameID(), item->buildCategory(), item->uniqueID(), item->inProgress(),
                item->buildAttempts(), item->skip(), item->numberBuilds(), item->buildCap(), item->buildFrom(),
                (unsigned int)item->permanentSkip(), item->skipCycles());
        } else {
            this->logCommonHistory(
                "    Type=%-4d %-20s gID=%-4d Cat=%d uID=%d InPrg=%d BlATmpt=%d Skip=%d NumBld=%d BldCap=%d From=%d PrSkp=%d SkpCyc=%d",
                item->typeID(), item->name(), item->gameID(), item->buildCategory(), item->uniqueID(), item->inProgress(),
                item->buildAttempts(), item->skip(), item->numberBuilds(), item->buildCap(), item->buildFrom(),
                (unsigned int)item->permanentSkip(), item->skipCycles());
        }

        item = item->next;
    }
}

// This source retains the executable's dead NULL test against
// the in-object buildListNameValue array.
#include <stdio.h>
#include <io.h>
int BuildAIModule::loadBuildList(char* lName, RGE_Player* player) {
    int typeID;
    int quantity;
    int buildFrom;
    int buildCap;
    char name[64];
    char temp[256];
    FILE* fileIn;
    float ySize;
    float xSize;
    char commentTemp1;
    char buildCategoryAsChar;
    char commentTemp2;

    strncpy(this->buildListNameValue, lName, 63);
    if (strcmp(this->buildListNameValue, "NONE") == 0 || this->buildListNameValue == 0 ||
        strlen(this->buildListNameValue) == 0) {
        goto no_build_list;
    }

    this->logCommonHistory("Trying to load build list in file '%s'.", lName);
    sprintf(temp, "%s", this->buildListNameValue);
    fileIn = fopen(temp, "r");
    if (fileIn == 0) {
        this->logCommonHistory("  I cannot do it cap'n!");
        return 0;
    }

    this->logCommonHistory("  File open successful, nuking any old items.");
    if (this->buildListLengthValue > 0) {
        this->removeOldList();
    }
    this->buildListLengthValue = 0;

    while (fgets(temp, 0x100, fileIn) != 0) {
        xSize = ySize = 1.5f;
        typeID = -1;
        sscanf(temp, " %c%c", &commentTemp1, &commentTemp2);
        if (commentTemp1 == '/' && commentTemp2 == '/') {
            continue;
        }

        sscanf(temp, " %c%d %s %d %d ", &buildCategoryAsChar, &quantity, name, &buildFrom, &buildCap);

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

        if ((buildCategory == 0 || buildCategory == 2) && quantity >= 0 && quantity < player->master_object_num &&
            player->master_objects[quantity] != 0) {
            RGE_Master_Static_Object* master = player->master_objects[quantity];
            ySize = master->radius_x;
            xSize = master->radius_y;
        }
        ySize += ySize;
        xSize += xSize;

        int i;
        for (i = 0; i < buildFrom; ++i) {
            BuildItem* item = new BuildItem(buildCategory, quantity, this->buildListLengthValue,
                                            1, 0, buildCap, name, ySize, xSize, 0.0f, -1, -1, -1, 0);

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

    fclose(fileIn);
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

int BuildAIModule::insertItem(RGE_Player* player, int typeID, int quantity, int buildCategory, int buildFrom, int buildCap, int insertAfterItemNumber) {
    if (insertAfterItemNumber > this->buildListLengthValue) {
        return 0;
    }

    BuildItem* insertAfter = this->buildList.next;
    int itemNumber = 0;
    while (insertAfter != &this->buildList && itemNumber < insertAfterItemNumber) {
        insertAfter = insertAfter->next;
        itemNumber++;
    }

    char name[64];
    float xSize;
    float ySize;
    if (buildCategory != 6) {
        RGE_Master_Static_Object* master = player->master_objects[typeID];
        if (master != 0) {
            strncpy(name, master->name, 63);
            xSize = master->radius_x + master->radius_x;
            ySize = master->radius_y + master->radius_y;
        } else {
            strncpy(name, s_AddedBuildListItem, 63);
            xSize = 3.0f;
            ySize = 3.0f;
        }
    } else {
        strncpy(name, s_SetGatherPercentage, 63);
        xSize = 3.0f;
        ySize = 3.0f;
    }

    int uniqueID = this->buildListLengthValue;
    for (int i = 0; i < quantity; i++) {
        BuildItem* item = new BuildItem(buildCategory, typeID, uniqueID, 1, 0, buildFrom, name,
                                        xSize, ySize, 1.0f, -1, -1, -1, 0);
        if (item == 0) {
            return 0;
        }

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

        item->prev = insertAfter;
        item->next = insertAfter->next;
        uniqueID++;
        item->next->prev = item;
        insertAfter->next = item;
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

int BuildAIModule::numberItemsOfType(int type, int category) {
    BuildItem* cur = this->buildList.next;
    int count = 0;
    BuildItem* sentinel = &this->buildList;
    while (cur != sentinel && cur != 0) {
        if (cur->typeID() == type && cur->buildCategory() == category) {
            count++;
        }
        cur = cur->next;
    }
    return count;
}

int BuildAIModule::numberBuiltItemsOfType(int type, int category) {
    BuildItem* item = this->buildList.next;
    BuildItem* sentinel = &this->buildList;
    int count = 0;

    while (item != sentinel && item != 0) {
        if (item->typeID() == type && item->buildCategory() == category && item->built() == 1) {
            ++count;
        }
        item = item->next;
    }

    return count;
}

int BuildAIModule::numberUnbuiltItemsOfType(int type, int category) {
    BuildItem* item = this->buildList.next;
    BuildItem* sentinel = &this->buildList;
    int count = 0;

    while (item != sentinel && item != 0) {
        if (item->typeID() == type && item->buildCategory() == category && item->built() == 0) {
            ++count;
        }
        item = item->next;
    }

    return count;
}

int BuildAIModule::numberBuiltOrInProgressItemsOfType(int type, int category) {
    int count = 0;
    BuildItem* item = this->buildList.next;
    BuildItem* end = &this->buildList;

    while (item != end && item != 0) {
        if (item->typeID() == type && item->buildCategory() == category && (item->built() == 1 || item->inProgress() == 1)) {
            ++count;
        }
        item = item->next;
    }

    return count;
}

int BuildAIModule::numberInProgressItemsOfType(int type, int category) {
    BuildItem* item = this->buildList.next;
    BuildItem* sentinel = &this->buildList;
    int count = 0;

    while (item != sentinel && item != 0) {
        if (item->typeID() == type && item->buildCategory() == category && item->inProgress() == 1) {
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

BuildItem* BuildAIModule::anyBuildListItem(int id, int checkBuilt, int buildStatus) {
    BuildItem* item = this->buildList.next;
    BuildItem* sentinel = &this->buildList;

    while (item != sentinel && item != 0) {
        if (item->typeID() == id) {
            if (checkBuilt == 0) {
                return item;
            }
            if (checkBuilt == 1) {
                if (item->built() == buildStatus) {
                    return item;
                }
            }
        }
        item = item->next;
    }

    return 0;
}

// The original checks the sentinel before loading the id.
BuildItem* BuildAIModule::specificBuildListItem(int id) {
    BuildItem* item = this->buildList.next;
    if (item == &this->buildList) return 0;

    int saveID = id;
    while (item != &this->buildList) {
        if (item == 0) return 0;
        if (item->uniqueID() == saveID) return item;
        item = item->next;
    }
    return 0;
}
