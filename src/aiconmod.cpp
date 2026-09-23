
#include "../include/aiconmod.h"
#include <stdio.h>
#include <string.h>

#include "../include/rge_fio.h"
extern "C" int __cdecl _unlink(const char*);

union IntFloat {
    int i;
    float f;
};

ConstructionAIModule::ConstructionAIModule(void* pW, int playerID)
    : AIModule("ConAI", 0x3EA, playerID, pW),
      numberConstructionLotsValue(0),
      constructionLots(),
      numberRandomConstructionLotsValue(0),
      randomConstructionLots(),
      xReferencePointValue(-1.0f),
      yReferencePointValue(-1.0f),
      zReferencePointValue(-1.0f),
      mapXSizeValue(-1),
      mapYSizeValue(-1),
      lastPlacementReturnCodeValue(PlacementOk) {
    this->constructionLots.next = &this->constructionLots;
    this->constructionLots.prev = &this->constructionLots;
    this->randomConstructionLots.next = &this->randomConstructionLots;
    this->randomConstructionLots.prev = &this->randomConstructionLots;

    strcpy(this->constructionPlanNameValue, "");
}

// Typed wire locals preserve the original serialized read order and raw bits.
ConstructionAIModule::ConstructionAIModule(int playerID, int infile)
    : AIModule("ConAI", 0x3ea, playerID, 0),
      numberConstructionLotsValue(0),
      constructionLots(),
      numberRandomConstructionLotsValue(0),
      randomConstructionLots(),
      xReferencePointValue(-1.0f),
      yReferencePointValue(-1.0f),
      zReferencePointValue(-1.0f),
      mapXSizeValue(-1),
      mapYSizeValue(-1),
      lastPlacementReturnCodeValue(PlacementOk) {
    char name[257];
    IntFloat x;
    int i;
    ConstructionItem* item;
    ConstructionItem* prev;

    this->constructionLots.next = &this->constructionLots;
    this->constructionLots.prev = &this->constructionLots;
    this->randomConstructionLots.next = &this->randomConstructionLots;
    this->randomConstructionLots.prev = &this->randomConstructionLots;

    rge_read(infile, &this->numberConstructionLotsValue, 4);
    rge_read(infile, &x.i, 4);
    rge_read(infile, this->constructionPlanNameValue, x.i);
    this->constructionPlanNameValue[x.i] = 0;
    rge_read(infile, &this->xReferencePointValue, 4);
    rge_read(infile, &this->yReferencePointValue, 4);
    rge_read(infile, &this->zReferencePointValue, 4);
    rge_read(infile, &this->mapXSizeValue, 4);
    rge_read(infile, &this->mapYSizeValue, 4);

    for (i = 0; i < this->numberConstructionLotsValue; i++) {
        IntFloat y, z, uniqueID, xSize, buildAttempts, ySize, inProgress, zSize;
        IntFloat skip;
        int typeID;
        int built;
        IntFloat gameID, i_value;

        rge_read(infile, &x.i, 4);
        rge_read(infile, name, x.i);
        name[x.i] = 0;
        rge_read(infile, &typeID, 4);
        rge_read(infile, &inProgress.i, 4);
        rge_read(infile, &skip.i, 4);
        rge_read(infile, &y.f, 4);
        rge_read(infile, &zSize.f, 4);
        rge_read(infile, &gameID.i, 4);
        rge_read(infile, &ySize.f, 4);
        rge_read(infile, &i_value.i, 4);
        rge_read(infile, &xSize.f, 4);
        rge_read(infile, &built, 4);
        rge_read(infile, &z.f, 4);
        rge_read(infile, &uniqueID.i, 4);
        rge_read(infile, &buildAttempts.i, 4);
        item = new ConstructionItem(y.f, zSize.f, gameID.f, ySize.f, i_value.f, xSize.f, typeID, name);
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

    rge_read(infile, &this->numberRandomConstructionLotsValue, 4);
    for (i = 0; i < this->numberRandomConstructionLotsValue; i++) {
        IntFloat y, z, uniqueID, xSize, buildAttempts, ySize, inProgress, zSize;
        IntFloat skip;
        int typeID;
        int built;
        IntFloat gameID, i_value;

        rge_read(infile, &x.i, 4);
        rge_read(infile, name, x.i);
        name[x.i] = 0;
        rge_read(infile, &built, 4);
        rge_read(infile, &i_value.i, 4);
        rge_read(infile, &xSize.i, 4);
        rge_read(infile, &y.f, 4);
        rge_read(infile, &z.f, 4);
        rge_read(infile, &uniqueID.i, 4);
        rge_read(infile, &buildAttempts.i, 4);
        rge_read(infile, &inProgress.i, 4);
        rge_read(infile, &skip.i, 4);
        rge_read(infile, &typeID, 4);
        rge_read(infile, &zSize.i, 4);
        rge_read(infile, &gameID.i, 4);
        rge_read(infile, &ySize.i, 4);
        item = new ConstructionItem(y.f, z.f, uniqueID.f, buildAttempts.f, inProgress.f, skip.f, built, name);
        item->setInProgress(zSize.i);
        item->setBuilt(gameID.i);
        item->setBuildAttempts(ySize.i);
        item->setGameID(i_value.i);
        item->setUniqueID(xSize.i);
        item->setSkip(typeID);
        item->next = &this->randomConstructionLots;
        prev = this->randomConstructionLots.prev;
        item->prev = prev;
        prev->next = item;
        this->randomConstructionLots.prev = item;
    }
}

ConstructionAIModule::~ConstructionAIModule() {
    if (this->numberConstructionLotsValue > 0) {
        removeOldLots();
    }
}

// boundaries, memory effects, fault order, and return value are preserved.
int ConstructionAIModule::save(int outfile) {
    char tempString[257];
    int tempInt;
    int tempBOOL;
    float tempFloat;
    ConstructionItem* item;

    rge_write(outfile, (void*)&this->numberConstructionLotsValue, 4);
    strcpy(tempString, this->constructionPlanNameValue);
    tempInt = strlen(tempString);
    rge_write(outfile, &tempInt, 4);
    rge_write(outfile, tempString, strlen(tempString));
    rge_write(outfile, (void*)&this->xReferencePointValue, 4);
    rge_write(outfile, (void*)&this->yReferencePointValue, 4);
    rge_write(outfile, (void*)&this->zReferencePointValue, 4);
    rge_write(outfile, (void*)&this->mapXSizeValue, 4);
    rge_write(outfile, (void*)&this->mapYSizeValue, 4);

    for (item = this->constructionLots.next;
         item != &this->constructionLots && item != 0;
         item = item->next) {
        strcpy(tempString, item->name());
        tempInt = strlen(tempString);
        rge_write(outfile, &tempInt, 4);
        rge_write(outfile, tempString, tempInt);
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
        tempBOOL = item->inProgress();
        rge_write(outfile, &tempBOOL, 4);
        tempBOOL = item->built();
        rge_write(outfile, &tempBOOL, 4);
        tempBOOL = item->buildAttempts();
        rge_write(outfile, &tempBOOL, 4);
    }

    rge_write(outfile, (void*)&this->numberRandomConstructionLotsValue, 4);
    for (item = this->randomConstructionLots.next;
         item != &this->randomConstructionLots && item != 0;
         item = item->next) {
        strcpy(tempString, item->name());
        tempInt = strlen(tempString);
        rge_write(outfile, &tempInt, 4);
        rge_write(outfile, tempString, tempInt);
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
        tempBOOL = item->inProgress();
        rge_write(outfile, &tempBOOL, 4);
        tempBOOL = item->built();
        rge_write(outfile, &tempBOOL, 4);
        tempBOOL = item->buildAttempts();
        rge_write(outfile, &tempBOOL, 4);
    }
    return 1;
}

int ConstructionAIModule::loadConstructionPlan(char* pName, int mXSize, int mYSize, float xRef, float yRef, float zRef) {
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

    this->setReferencePoint(mXSize, mYSize, xRef, yRef, zRef);
    if (this->numberConstructionLotsValue > 0) {
        this->removeOldLots();
    }

    plan = this->constructionPlanNameValue;
    saved_plan = plan;
    strncpy(plan, pName, 63);

    if (strcmp(plan, "NONE") == 0 || plan == 0) {
        if (plan == 0) {
            strcpy(plan, "NULL");
        }
        this->logCommonHistory("There is no construction plan to load.");
        return 1;
    }

    this->logCommonHistory("Loading construction plan in file '%s'.", pName);
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

char* ConstructionAIModule::constructionPlanName() {
    return this->constructionPlanNameValue;
}

// predicates, list edits, calls, cleanup, and 495-byte boundary are preserved.
void ConstructionAIModule::setReferencePoint(int mXSize, int mYSize, float x, float y, float z) {
    this->mapXSizeValue = mXSize;
    this->mapYSizeValue = mYSize;
    this->xReferencePointValue = x;
    this->yReferencePointValue = y;
    this->zReferencePointValue = z;

    if (x <= 0.0 || y <= 0.0 || (float)mXSize <= x || (float)mYSize <= y) {
        this->removeOldLots();
        return;
    }

    ConstructionItem* item = this->constructionLots.next;
    ConstructionItem* end = &this->constructionLots;
    while (item != end && item != 0) {
        item->setX(item->x() + x);
        item->setY(item->y() + y);
        item->setZ(item->z() + z);

        if (item->x() - item->xSize() * 0.5f < 0.0f || item->y() - item->ySize() * 0.5f < 0.0f ||
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

float ConstructionAIModule::xReferencePoint() {
    return this->xReferencePointValue;
}

float ConstructionAIModule::yReferencePoint() {
    return this->yReferencePointValue;
}

// The parameter and result are unused in this shipped base implementation.
ConstructionItem* ConstructionAIModule::placeStructure(BuildItem* bi) {
    return 0;
}

ConstructionAIModule::PlacementResult ConstructionAIModule::lastPlacementReturnCode() {
    return this->lastPlacementReturnCodeValue;
}

void ConstructionAIModule::setBuilt(ConstructionItem* ci, int v) {
    ConstructionItem* current;
    ConstructionItem* end;
    ConstructionItem* target = ci;

    current = this->constructionLots.next;
    end = &this->constructionLots;
    while (current != end) {
        if (current == 0) {
            break;
        }
        if (operator==(*current, *target)) {
            current->setBuilt(v);
            return;
        }
        current = current->next;
    }
}

int ConstructionAIModule::unplaceStructure(ConstructionItem* ci, int decBA) {
    ConstructionItem* current;
    ConstructionItem* end;
    ConstructionItem* target = ci;
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
            if (decBA == 1) {
                current->decrementBuildAttempts();
            }
            return oldID;
        }
        current = current->next;
    }
    return -1;
}

int ConstructionAIModule::unplaceStructure(float x, float y, int decBA) {
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
            if (decBA == 1) {
                item->decrementBuildAttempts();
            }
            return id;
        }
        item = item->next;
    }
    return -1;
}

void ConstructionAIModule::decrementBuildAttempts(float x, float y, int n) {
    ConstructionItem* item = this->lot(x, y);
    if (item != 0 && n > 0) {
        do {
            item->decrementBuildAttempts();
            n = n - 1;
        } while (n != 0);
    }
}

void ConstructionAIModule::incrementBuildAttempts(float x, float y, int n) {
    ConstructionItem* item = this->lot(x, y);
    if (item != 0 && n > 0) {
        do {
            item->incrementBuildAttempts();
            n = n - 1;
        } while (n != 0);
    }
}

ConstructionItem* ConstructionAIModule::lot(float x, float y) {
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

ConstructionItem* ConstructionAIModule::randomLot(float x, float y) {
    ConstructionItem* cur = this->randomConstructionLots.next;
    while (cur != &this->randomConstructionLots && cur != 0) {
        if (cur->x() == x && cur->y() == y) {
            return cur;
        }
        cur = cur->next;
    }
    return 0;
}

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
