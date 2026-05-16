// 0040B690 ConstructionAIModule::loadConstructionPlan
// scratch give-up: natural /GX reconstruction reaches exact size 731 and matches through setup/strncpy/strcmp
// but remains 54.86% positional / 27.36% edit mismatch. First real drift is branch-distance after
// strcmp because later local layout/code size differs; persistent issues include temp buffer at esp+7c
// vs original esp+78, FILE* allocated in EDI vs original ESI, and constructor/new argument scheduling.
// Kept /GX because original has EH frame and default flags do not reproduce prologue.

#include <stdio.h>
#include <string.h>

class BaseItem { public: virtual ~BaseItem(); char gap[0x68]; };
class ConstructionItem : public BaseItem {
public:
    ConstructionItem* next;
    ConstructionItem* prev;
    int field_74;
    int field_78;
    int field_7c;
    ConstructionItem(float, float, float, float, float, float, int, const char*);
};

class ConstructionAIModule {
public:
    char gap000[0xF0];
    int numberConstructionLotsValue;
    ConstructionItem constructionLots;
    char pad174[4];
    ConstructionItem randomConstructionLots;
    char constructionPlanNameValue[0x40];
    char gap238[0xC4];
    float xReferencePointValue;
    float yReferencePointValue;
    float zReferencePointValue;

    int loadConstructionPlan(char* name, int p2, int p3, float p4, float p5, float p6);
    void setReferencePoint(int, int, float, float, float);
    void removeOldLots();
    ConstructionItem* lot(float, float);
    void logCommonHistory(char*, ...);
};

extern "C" int __cdecl _unlink(const char*);

int ConstructionAIModule::loadConstructionPlan(char* name, int p2, int p3, float p4, float p5, float p6)
{
    char commentTemp1;
    char commentTemp2;
    float y;
    float x;
    float z;
    float zSize;
    float xSize;
    float ySize;
    float local_154;
    float local_164;
    int id;
    char itemName[64];
    char temp[256];
    FILE* fp;
    ConstructionItem* item;
    ConstructionItem* prev;
    char* plan;

    this->setReferencePoint(p2, p3, p4, p5, p6);
    if (this->numberConstructionLotsValue > 0) {
        this->removeOldLots();
    }

    plan = this->constructionPlanNameValue;
    id = (int)plan;
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
                sscanf(temp + 4, "%f %f %f %f %f %f %d %s ", &z, &x, &zSize, &ySize, &local_154, &local_164, &xSize, itemName + 4);
                z = this->xReferencePointValue + z;
                x = this->yReferencePointValue + x;
                zSize = this->zReferencePointValue + zSize;
                if (this->lot(z, x) == 0) {
                    item = new ConstructionItem(z, x, zSize, ySize, local_154, local_164, (int)xSize, itemName + 4);
                    item->next = &this->constructionLots;
                    prev = this->constructionLots.prev;
                    item->prev = prev;
                    prev->next = item;
                    this->constructionLots.prev = item;
                    this->numberConstructionLotsValue++;
                }
            }
        } while (fgets(temp + 4, 0x100, fp) != 0);
        plan = (char*)id;
    }

    fclose(fp);
    if (strstr(plan, ".tmp") != 0) {
        _unlink(plan);
    }
    return 1;
}
