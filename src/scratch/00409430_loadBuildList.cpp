// 00409430 BuildAIModule::loadBuildList
// aibldmod.cpp:313-480
//
// Clean typed reset: use the original BuildAIModule parser surface, FILE
// streams, RGE master-object radii, and the BuildItem sentinel links.
//
// Baseline lead: the previous file used a TribeBuildAIModule owner, a fake
// LineFile, wrong numeric opcodes, and a fake setName call.  The executable
// instead parses A/B/C/E/G/L/R/T/U and calls BuildItem::setBuildCap.
// The binary PDB line order and jump table put the arms in B, A, R, C, U,
// T, L, E, G order.  This order is retained in the living source.
// Switch-order probe: diff 456 -> 420 -> 386 bytes; five cold blocks aligned.
// Field-pointer null/strlen probes followed Ghidra ownership but worsened
// codegen, so the parameter-based guard remains the best source basin.

#include <stdio.h>
#include <string.h>
#include <io.h>

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x2C];
    float radius_x;                         // +0x30
    float radius_y;                         // +0x34
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x1E];
    short master_object_num;                // +0x22
    RGE_Master_Static_Object** master_objects; // +0x24
};

class BaseItem {
public:
    virtual ~BaseItem();
    char gap_04[0x68];
};

class BuildItem : public BaseItem {
public:
    BuildItem* next;                         // +0x6C
    BuildItem* prev;                         // +0x70
    char gap_74[0x3C];

    BuildItem(int category, int typeID, int uniqueID, int number, int priority,
              int buildFrom, char* name, float xSize, float ySize, float zSize,
              int terrainSet, int adj0, int adj1, int elevation);
    void setBuildCap(int value);
};

struct TypesToIgnore {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0xEC];
    void logCommonHistory(char*, ...);
};

class BuildAIModule : public AIModule {
public:
    BuildItem buildList;                     // +0xF0
    int buildListLengthValue;                // +0x1A0
    char buildListNameValue[0x101];          // +0x1A4
    char gap_2A5[0x307];                     // through +0x5AB
    TypesToIgnore typesToIgnore;             // +0x5AC

    void removeOldList();
    virtual int loadBuildList(char*, RGE_Player*);
};

int BuildAIModule::loadBuildList(char* filename, RGE_Player* player)
{
    int typeID;
    int quantity;
    int buildFrom;
    int fileIn;
    char* buildListName;
    char name[64];
    char temp[256];
    FILE* fp;
    float ySize;
    float xSize;
    char commentTemp1;
    char buildCategoryAsChar;
    char commentTemp2;

    buildListName = this->buildListNameValue;
    strncpy(buildListName, filename, 0x3F);
    if (strcmp(buildListName, "NONE") == 0 ||
        filename == 0 || strlen(filename) == 0) {
        goto no_build_list;
    }

    this->logCommonHistory("Trying to load build list in file '%s'.", filename);
    sprintf(temp, "%s", buildListName);
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
        xSize = 1.5f;
        ySize = 1.5f;
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
            int i;
            for (i = 0; i < this->typesToIgnore.numberValue; ++i) {
                if (i >= this->typesToIgnore.maximumSizeValue) {
                    break;
                }
                if (this->typesToIgnore.value[i] == quantity) {
                    goto next_line;
                }
            }
        }

        if ((buildCategory == 0 || buildCategory == 2) && quantity >= 0 &&
            quantity < player->master_object_num &&
            player->master_objects[quantity] != 0) {
            RGE_Master_Static_Object* master = player->master_objects[quantity];
            ySize = master->radius_y;
            xSize = master->radius_x;
        }
        xSize += xSize;
        ySize += ySize;

        int i;
        for (i = 0; i < buildFrom; ++i) {
            BuildItem* item = new BuildItem(
                buildCategory, quantity, this->buildListLengthValue,
                1, 0, fileIn, name, xSize, ySize, 0.0f,
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
    if (strstr(buildListName, ".tmp") != 0) {
        unlink(buildListName);
    }
    return 1;

no_build_list:
    if (buildListName[0] == 0) {
        strcpy(buildListName, "NULL");
    }
    this->logCommonHistory("There is no build list to load.");
    return 1;
}
