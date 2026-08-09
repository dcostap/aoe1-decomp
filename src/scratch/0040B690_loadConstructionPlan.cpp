// 0040B690 ConstructionAIModule::loadConstructionPlan
// Attempt log:
// - Natural /GX parser reconstruction reaches the correct 0x168 frame, 17-call set, and 226 instructions.
// - Modeled sscanf's %d field as int xSize; this removes a spurious __ftol and restores call/CFG parity.
// - Bound the proven aiconmod string-table addresses (NONE, formats, NULL, .tmp, and messages) so COFF
//   relocation identities and the inline strcmp/rep-copy paths follow the original symbols.
// - A dead-float comment-byte overlay, 68-byte name buffer, typed union overlay, scoped pointer, and
//   declaration-order probes were diagnostic only; the overlay/size forms worsened codegen and the
//   remaining scopes/order collapsed to the same output.
// - Kept the clean typed source: original uses name+4 at esp+38 and temp+4 at esp+78, while rebuilt
//   uses esp+3c/esp+7c. The two widened temp LEAs account for the remaining +6 bytes and branch drift.
//   A compiler-reused name-prefix/new-result home is suggested by the decompiler but no policy-compliant
//   natural spelling found it; leave this target in scratch rather than retain an opaque overlay.
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
    char itemName[64];
    char temp[256];
    FILE* fp;
    char* plan;

    this->setReferencePoint(p2, p3, p4, p5, p6);
    if (this->numberConstructionLotsValue > 0) {
        this->removeOldLots();
    }

    plan = this->constructionPlanNameValue;
    char* saved_plan = plan;
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
                sscanf(temp + 4, "%f %f %f %f %f %f %d %s ", &z, &x, &zSize, &ySize, &item_arg_5, &item_arg_6, &xSize, itemName + 4);
                z = this->xReferencePointValue + z;
                x = this->yReferencePointValue + x;
                zSize = this->zReferencePointValue + zSize;
                if (this->lot(z, x) == 0) {
                    ConstructionItem* item;
                    ConstructionItem* prev;
                    item = new ConstructionItem(z, x, zSize, ySize, item_arg_5, item_arg_6, xSize, itemName + 4);
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
