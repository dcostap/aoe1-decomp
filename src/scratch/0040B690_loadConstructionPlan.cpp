// 0040B690 ConstructionAIModule::loadConstructionPlan
// Attempt log:
// - Natural /GX parser reconstruction reaches the correct 0x168 frame, 17-call set, and 226 instructions.
// - Modeled sscanf's %d field as int xSize; this removes a spurious __ftol and restores call/CFG parity.
// - Bound the proven aiconmod string-table addresses (NONE, formats, NULL, .tmp, and messages) so COFF
//   relocation identities and the inline strcmp/rep-copy paths follow the original symbols.
// - A dead-float comment-byte overlay, 68-byte name buffer, typed union/record overlays, scoped pointer,
//   and declaration-order probes were diagnostic only; they either worsened codegen or duplicated the
//   64-byte result.
// - A natural 60-byte item-name payload (the binary writes/reads only name+4's 60 usable bytes) moves
//   itemName/temp to the original short-LEA offsets and removes all six widened LEA bytes. It leaves a
//   4-byte frame-size difference (0x164 vs 0x168); adding the decompiler's int id home was a duplicate,
//   so the 60-byte candidate is retained as the cleanest policy-compliant reconstruction.
// FLAGS: config/flags/0040B690_loadConstructionPlan.rsp (/GX for EH frame)

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
    virtual ~ConstructionItem();
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
    float item_arg_6;
    int xSize;
    float ySize;
    float item_arg_5;
    char itemName[60];
    char temp[256];
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
