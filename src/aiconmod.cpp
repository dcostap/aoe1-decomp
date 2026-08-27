// PDB source module: C:\\msdev\\work\\age1_x1\\aiconmod.cpp
// The definitions below follow the original PDB source-line order.
// The scalar deleting destructor at 0040AB90 is compiler generated and has no
// PDB source line, so it is not a source owner here.

#include "../include/aiconmod.h"
#include <stdio.h>
#include <string.h>

extern "C" void rge_read(int fd, void* dst, int size);
extern "C" void rge_write(int fd, void* src, int size);
extern "C" int __cdecl _unlink(const char*);

union IntFloat {
    int i;
    float f;
};

// 0040AA90 ConstructionAIModule::ConstructionAIModule (aiconmod.cpp:36-43)
// FLAGS: config/flags/0040AA90_ConstructionAIModule.rsp (/GX for EH frame)
ConstructionAIModule::ConstructionAIModule(void* param_1, int param_2)
    : AIModule((char*)0x57F380, 0x3EA, param_2, param_1),
      numberConstructionLotsValue(0),
      constructionLots(),
      numberRandomConstructionLotsValue(0),
      randomConstructionLots(),
      xReferencePointValue(-1.0f),
      yReferencePointValue(-1.0f),
      zReferencePointValue(-1.0f),
      mapXSizeValue(-1),
      mapYSizeValue(-1),
      lastPlacementReturnCodeValue(PlacementOk)
{
    this->constructionLots.next = &this->constructionLots;
    this->constructionLots.prev = &this->constructionLots;
    this->randomConstructionLots.next = &this->randomConstructionLots;
    this->randomConstructionLots.prev = &this->randomConstructionLots;

    strcpy(this->constructionPlanNameValue, (const char*)0x592A40);
}

// 0040ABB0 ConstructionAIModule::ConstructionAIModule (aiconmod.cpp:57-182)
// Typed wire locals preserve the original serialized read order and raw bits.
ConstructionAIModule::ConstructionAIModule(int p1, int fd)
    : AIModule("ConAI", 0x3ea, p1, 0),
      numberConstructionLotsValue(0),
      constructionLots(),
      numberRandomConstructionLotsValue(0),
      randomConstructionLots(),
      xReferencePointValue(-1.0f),
      yReferencePointValue(-1.0f),
      zReferencePointValue(-1.0f),
      mapXSizeValue(-1),
      mapYSizeValue(-1),
      lastPlacementReturnCodeValue(PlacementOk)
{
    char name[257];
    IntFloat x;
    int n;
    ConstructionItem* item;
    ConstructionItem* prev;

    this->constructionLots.next = &this->constructionLots;
    this->constructionLots.prev = &this->constructionLots;
    this->randomConstructionLots.next = &this->randomConstructionLots;
    this->randomConstructionLots.prev = &this->randomConstructionLots;

    rge_read(fd, &this->numberConstructionLotsValue, 4);
    rge_read(fd, &x.i, 4);
    rge_read(fd, this->constructionPlanNameValue, x.i);
    this->constructionPlanNameValue[x.i] = 0;
    rge_read(fd, &this->xReferencePointValue, 4);
    rge_read(fd, &this->yReferencePointValue, 4);
    rge_read(fd, &this->zReferencePointValue, 4);
    rge_read(fd, &this->mapXSizeValue, 4);
    rge_read(fd, &this->mapYSizeValue, 4);

    for (n=0; n<this->numberConstructionLotsValue; n++) {
        IntFloat y, z, uniqueID, xSize, buildAttempts, ySize, inProgress, zSize;
        IntFloat skip;
        int typeID;
        int built;
        IntFloat gameID, i;

        rge_read(fd, &x.i, 4);
        rge_read(fd, name, x.i);
        name[x.i] = 0;
        rge_read(fd, &typeID, 4);
        rge_read(fd, &inProgress.i, 4);
        rge_read(fd, &skip.i, 4);
        rge_read(fd, &y.f, 4);
        rge_read(fd, &zSize.f, 4);
        rge_read(fd, &gameID.i, 4);
        rge_read(fd, &ySize.f, 4);
        rge_read(fd, &i.i, 4);
        rge_read(fd, &xSize.f, 4);
        rge_read(fd, &built, 4);
        rge_read(fd, &z.f, 4);
        rge_read(fd, &uniqueID.i, 4);
        rge_read(fd, &buildAttempts.i, 4);
        item = new ConstructionItem(y.f, zSize.f, gameID.f, ySize.f, i.f, xSize.f, typeID, name);
        item->setInProgress(z.i);
        item->setBuilt(uniqueID.i);
        item->setBuildAttempts(buildAttempts.i);
        item->setGameID(inProgress.i);
        item->setUniqueID(skip.i);
        item->setSkip(built);
        item->next = &this->constructionLots;
        prev = this->constructionLots.prev;
        item->prev = prev;
        prev->next = item;
        this->constructionLots.prev = item;
    }

    rge_read(fd, &this->numberRandomConstructionLotsValue, 4);
    for (n=0; n<this->numberRandomConstructionLotsValue; n++) {
        IntFloat y, z, uniqueID, xSize, buildAttempts, ySize, inProgress, zSize;
        IntFloat skip;
        int typeID;
        int built;
        IntFloat gameID, i;

        rge_read(fd, &x.i, 4);
        rge_read(fd, name, x.i);
        name[x.i] = 0;
        rge_read(fd, &built, 4);
        rge_read(fd, &i.i, 4);
        rge_read(fd, &xSize.i, 4);
        rge_read(fd, &y.f, 4);
        rge_read(fd, &z.f, 4);
        rge_read(fd, &uniqueID.i, 4);
        rge_read(fd, &buildAttempts.i, 4);
        rge_read(fd, &inProgress.i, 4);
        rge_read(fd, &skip.i, 4);
        rge_read(fd, &typeID, 4);
        rge_read(fd, &zSize.i, 4);
        rge_read(fd, &gameID.i, 4);
        rge_read(fd, &ySize.i, 4);
        item = new ConstructionItem(y.f, z.f, uniqueID.f, buildAttempts.f, inProgress.f, skip.f, built, name);
        item->setInProgress(zSize.i);
        item->setBuilt(gameID.i);
        item->setBuildAttempts(ySize.i);
        item->setGameID(i.i);
        item->setUniqueID(xSize.i);
        item->setSkip(typeID);
        item->next = &this->randomConstructionLots;
        prev = this->randomConstructionLots.prev;
        item->prev = prev;
        prev->next = item;
        this->randomConstructionLots.prev = item;
    }
}

// 0040B120 ConstructionAIModule::~ConstructionAIModule (aiconmod.cpp:187-190)
// FLAGS: /GX (EH frame)
ConstructionAIModule::~ConstructionAIModule() {
    if (this->numberConstructionLotsValue > 0) {
        removeOldLots();
    }
}

// 0040B1A0 ConstructionAIModule::save (aiconmod.cpp:195-302)
// PDB proves tempString[257], tempInt, tempBOOL, and tempFloat.
// ACCEPTED DRIFT: The same 67 ordered writes, values, widths, list traversal,
// boundaries, memory effects, fault order, and return value are preserved.
// VC5 uses different private stack homes for the three scalar temporaries.
int ConstructionAIModule::save(int fd)
{
    char tempString[257];
    int tempInt;
    int tempBOOL;
    float tempFloat;
    ConstructionItem* item;

    rge_write(fd, (void*)&this->numberConstructionLotsValue, 4);
    strcpy(tempString, this->constructionPlanNameValue);
    tempInt = strlen(tempString);
    rge_write(fd, &tempInt, 4);
    rge_write(fd, tempString, strlen(tempString));
    rge_write(fd, (void*)&this->xReferencePointValue, 4);
    rge_write(fd, (void*)&this->yReferencePointValue, 4);
    rge_write(fd, (void*)&this->zReferencePointValue, 4);
    rge_write(fd, (void*)&this->mapXSizeValue, 4);
    rge_write(fd, (void*)&this->mapYSizeValue, 4);

    item = this->constructionLots.next;
    while (item != &this->constructionLots) {
        if (item == 0) break;
        strcpy(tempString, item->name());
        tempInt = strlen(tempString);
        rge_write(fd, &tempInt, 4);
        rge_write(fd, tempString, tempInt);
        tempInt = item->typeID();
        rge_write(fd, &tempInt, 4);
        tempInt = item->gameID();
        rge_write(fd, &tempInt, 4);
        tempInt = item->uniqueID();
        rge_write(fd, &tempInt, 4);
        tempFloat = item->x();
        rge_write(fd, &tempFloat, 4);
        tempFloat = item->y();
        rge_write(fd, &tempFloat, 4);
        tempFloat = item->z();
        rge_write(fd, &tempFloat, 4);
        tempFloat = item->xSize();
        rge_write(fd, &tempFloat, 4);
        tempFloat = item->ySize();
        rge_write(fd, &tempFloat, 4);
        tempFloat = item->zSize();
        rge_write(fd, &tempFloat, 4);
        tempBOOL = item->skip();
        rge_write(fd, &tempBOOL, 4);
        tempBOOL = item->inProgress();
        rge_write(fd, &tempBOOL, 4);
        tempBOOL = item->built();
        rge_write(fd, &tempBOOL, 4);
        tempBOOL = item->buildAttempts();
        rge_write(fd, &tempBOOL, 4);
        item = item->next;
    }

    rge_write(fd, (void*)&this->numberRandomConstructionLotsValue, 4);
    item = this->randomConstructionLots.next;
    while (item != &this->randomConstructionLots) {
        if (item == 0) return 1;
        strcpy(tempString, item->name());
        tempInt = strlen(tempString);
        rge_write(fd, &tempInt, 4);
        rge_write(fd, tempString, tempInt);
        tempInt = item->typeID();
        rge_write(fd, &tempInt, 4);
        tempInt = item->gameID();
        rge_write(fd, &tempInt, 4);
        tempInt = item->uniqueID();
        rge_write(fd, &tempInt, 4);
        tempFloat = item->x();
        rge_write(fd, &tempFloat, 4);
        tempFloat = item->y();
        rge_write(fd, &tempFloat, 4);
        tempFloat = item->z();
        rge_write(fd, &tempFloat, 4);
        tempFloat = item->xSize();
        rge_write(fd, &tempFloat, 4);
        tempFloat = item->ySize();
        rge_write(fd, &tempFloat, 4);
        tempFloat = item->zSize();
        rge_write(fd, &tempFloat, 4);
        tempBOOL = item->skip();
        rge_write(fd, &tempBOOL, 4);
        tempBOOL = item->inProgress();
        rge_write(fd, &tempBOOL, 4);
        tempBOOL = item->built();
        rge_write(fd, &tempBOOL, 4);
        tempBOOL = item->buildAttempts();
        rge_write(fd, &tempBOOL, 4);
        item = item->next;
    }
    return 1;
}

// 0040B690 ConstructionAIModule::loadConstructionPlan (aiconmod.cpp:308-380)
// FLAGS: config/flags/0040B690_loadConstructionPlan.rsp (/GX for EH frame)
int ConstructionAIModule::loadConstructionPlan(char* name, int p2, int p3, float p4, float p5, float p6)
{
    char commentTemp1;
    char commentTemp2;
    float y;
    float x;
    float z;
    float zSize;
    float item_arg_6;
    int xSize;
    float ySize;
    float item_arg_5;
    char itemName[60];
    char temp[260];
    FILE* fp;
    char* plan;
    char* saved_plan;

    this->setReferencePoint(p2, p3, p4, p5, p6);
    if (this->numberConstructionLotsValue > 0) {
        this->removeOldLots();
    }

    plan = this->constructionPlanNameValue;
    saved_plan = plan;
    strncpy(plan, name, 0x3f);

    if (strcmp(plan, "NONE") == 0 || plan == 0) {
        if (plan == 0) {
            strcpy(plan, "NULL");
        }
        this->logCommonHistory("There is no construction plan to load.");
        return 1;
    }

    this->logCommonHistory("Loading construction plan in file '%s'.", name);
    sprintf(temp + 4, "%s", plan);
    fp = fopen(temp + 4, "r");
    if (fp == 0) {
        return 0;
    }

    if (fgets(temp + 4, 0x100, fp) != 0) {
        do {
            sscanf(temp + 4, " %c%c", &commentTemp1, &commentTemp2);
            if (commentTemp1 != '/' || commentTemp2 != '/') {
                sscanf(temp + 4, "%f %f %f %f %f %f %d %s ", &z, &x, &zSize, &ySize, &item_arg_5, &item_arg_6, &xSize, itemName);
                z = this->xReferencePointValue + z;
                x = this->yReferencePointValue + x;
                zSize = this->zReferencePointValue + zSize;
                if (this->lot(z, x) == 0) {
                    ConstructionItem* item;
                    ConstructionItem* prev;
                    item = new ConstructionItem(z, x, zSize, ySize, item_arg_5, item_arg_6, xSize, itemName);
                    item->next = &this->constructionLots;
                    prev = this->constructionLots.prev;
                    item->prev = prev;
                    prev->next = item;
                    this->constructionLots.prev = item;
                    this->numberConstructionLotsValue++;
                }
            }
        } while (fgets(temp + 4, 0x100, fp) != 0);
        plan = saved_plan;
    }

    fclose(fp);
    if (strstr(plan, ".tmp") != 0) {
        _unlink(plan);
    }
    return 1;
}

// 0040B970 ConstructionAIModule::constructionPlanName (aiconmod.cpp:385-387)
char* ConstructionAIModule::constructionPlanName() {
    return this->constructionPlanNameValue;
}

// 0040B980 ConstructionAIModule::setReferencePoint (aiconmod.cpp:393-443)
// ACCEPTED DRIFT: The same x/y bound calculations, floating operations,
// predicates, list edits, calls, cleanup, and 495-byte boundary are preserved.
// VC5 places two private upper-bound temporaries in different stack homes.
void ConstructionAIModule::setReferencePoint(int mapX, int mapY, float xRef, float yRef, float zRef)
{
    this->mapXSizeValue = mapX;
    this->mapYSizeValue = mapY;
    this->xReferencePointValue = xRef;
    this->yReferencePointValue = yRef;
    this->zReferencePointValue = zRef;

    if (xRef <= 0.0 || yRef <= 0.0 || (float)mapX <= xRef || (float)mapY <= yRef) {
        this->removeOldLots();
        return;
    }

    ConstructionItem* item = this->constructionLots.next;
    ConstructionItem* end = &this->constructionLots;
    while (item != end && item != 0) {
        item->setX(item->x() + xRef);
        item->setY(item->y() + yRef);
        item->setZ(item->z() + zRef);

        if (item->x() - item->xSize() * 0.5f < 0.0f ||
            item->y() - item->ySize() * 0.5f < 0.0f ||
            item->x() - item->xSize() * -0.5f > (float)(this->mapXSizeValue - 1) ||
            item->y() - item->ySize() * -0.5f > (float)(this->mapYSizeValue - 1)) {
            this->numberConstructionLotsValue--;
            ConstructionItem* next = item->next;
            item->prev->next = next;
            item->next->prev = item->prev;
            delete item;
            item = next;
        } else {
            item = item->next;
        }
    }
}

// 0040BB70 ConstructionAIModule::xReferencePoint (aiconmod.cpp:448-450)
float ConstructionAIModule::xReferencePoint() {
    return this->xReferencePointValue;
}

// 0040BB80 ConstructionAIModule::yReferencePoint (aiconmod.cpp:455-457)
float ConstructionAIModule::yReferencePoint() {
    return this->yReferencePointValue;
}

// 0040BB90 ConstructionAIModule::placeStructure (aiconmod.cpp:462-464)
// The parameter and result are unused in this shipped base implementation.
ConstructionItem* ConstructionAIModule::placeStructure(BuildItem* item) {
    return 0;
}

// 0040BBA0 ConstructionAIModule::lastPlacementReturnCode (aiconmod.cpp:470-472)
ConstructionAIModule::PlacementResult ConstructionAIModule::lastPlacementReturnCode() {
    return this->lastPlacementReturnCodeValue;
}

// 0040BBB0 ConstructionAIModule::setBuilt (aiconmod.cpp:477-486)
void ConstructionAIModule::setBuilt(ConstructionItem* item, int built) {
    ConstructionItem* current;
    ConstructionItem* end;
    ConstructionItem* target = item;

    current = this->constructionLots.next;
    end = &this->constructionLots;
    while (current != end) {
        if (current == 0) {
            break;
        }
        if (operator==(*current, *target)) {
            current->setBuilt(built);
            return;
        }
        current = current->next;
    }
}

// 0040BC00 ConstructionAIModule::unplaceStructure (aiconmod.cpp:492-508)
int ConstructionAIModule::unplaceStructure(ConstructionItem* item, int decrement) {
    ConstructionItem* current;
    ConstructionItem* end;
    ConstructionItem* target = item;
    int oldID;

    current = this->constructionLots.next;
    end = &this->constructionLots;
    while (current != end) {
        if (current == 0) {
            break;
        }
        if (operator==(*current, *target)) {
            current->setInProgress(0);
            current->setBuilt(0);
            oldID = current->uniqueID();
            current->setUniqueID(-1);
            if (decrement == 1) {
                current->decrementBuildAttempts();
            }
            return oldID;
        }
        current = current->next;
    }
    return -1;
}

// 0040BC80 ConstructionAIModule::unplaceStructure (aiconmod.cpp:513-529)
int ConstructionAIModule::unplaceStructure(float x, float y, int decrement) {
    int id;
    ConstructionItem* item;

    item = this->constructionLots.next;
    while (item != &this->constructionLots) {
        if (item == 0) {
            return -1;
        }
        if (item->x() == x && item->y() == y) {
            item->setInProgress(0);
            item->setBuilt(0);
            id = item->uniqueID();
            item->setUniqueID(-1);
            if (decrement == 1) {
                item->decrementBuildAttempts();
            }
            return id;
        }
        item = item->next;
    }
    return -1;
}

// 0040BD10 ConstructionAIModule::decrementBuildAttempts (aiconmod.cpp:534-540)
void ConstructionAIModule::decrementBuildAttempts(float x, float y, int count) {
    ConstructionItem* item = this->lot(x, y);
    if (item != 0 && count > 0) {
        do {
            item->decrementBuildAttempts();
            count = count - 1;
        } while (count != 0);
    }
}

// 0040BD40 ConstructionAIModule::incrementBuildAttempts (aiconmod.cpp:545-551)
void ConstructionAIModule::incrementBuildAttempts(float x, float y, int count) {
    ConstructionItem* item = this->lot(x, y);
    if (item != 0 && count > 0) {
        do {
            item->incrementBuildAttempts();
            count = count - 1;
        } while (count != 0);
    }
}

// 0040BD70 ConstructionAIModule::lot (aiconmod.cpp:556-570)
ConstructionItem* ConstructionAIModule::lot(float x, float y)
{
    ConstructionItem* p = this->constructionLots.next;

    while (p != &this->constructionLots && p != 0) {
        if (p->x() == x && p->y() == y)
            return p;
        p = p->next;
    }

    p = this->randomConstructionLots.next;

    while (p != &this->randomConstructionLots && p != 0) {
        if (p->x() == x && p->y() == y)
            return p;
        p = p->next;
    }

    return 0;
}

// 0040BE10 ConstructionAIModule::randomLot (aiconmod.cpp:575-583)
ConstructionItem* ConstructionAIModule::randomLot(float px, float py) {
    ConstructionItem* cur = this->randomConstructionLots.next;
    while (cur != &this->randomConstructionLots && cur != 0) {
        if (cur->x() == px && cur->y() == py) {
            return cur;
        }
        cur = cur->next;
    }
    return 0;
}

// 0040BE70 ConstructionAIModule::removeOldLots (aiconmod.cpp:588-599)
void ConstructionAIModule::removeOldLots(void) {
    ConstructionItem* item = this->constructionLots.next;
    ConstructionItem* end = &this->constructionLots;

    while (item != end && item != 0) {
        ConstructionItem* next = item->next;
        delete item;
        item = next;
    }

    this->constructionLots.next = end;
    this->constructionLots.prev = end;
    this->numberConstructionLotsValue = 0;
}
