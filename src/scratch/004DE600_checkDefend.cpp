// 004DE600 TribeInformationAIModule::checkDefend
// Attempt log:
// try 1: reconstructed switch by unit master id and importantObjects list insertion/check helpers.
// try 2: added IntArray methods at 004147A0/004DE980/004DE9D0 surface; compiles exact byte size but broad drift.
// try 3: used C switch on master id to get jump table; first compare differs due range 0x73 vs original 0x76.
// try 4: reordered case 109 before case 45 to mirror original block order; no improvement to range/jump table family.
// try 5: preserved separate group fallback switch for object_group 7/8/32; tail blocks recognizable but branch layout differs.
// try 6: modeled owner id load at +0x4a and master id/group at +0x10/+0x14; prologue through initial loads matches.
// try 7: modeled importantObjects at +0x148 and mainDecisionAI at +0x100; helper calls use expected this offsets.
// try 8: inlined list duplicate scan for special master-id cases; generated same-size source but early-return layout differs.
// try 9: used IntArray::checkObjectInList for group 8/32 and addImportantObject for group 7; call set matches fallback.
// try 10: kept natural add_to_important helper body to share insertion tail; compiler duplicates/places exits differently.
// left in scratch: exact size but not safe drift; initial switch range/table and early-return/code layout need source-shape recovery.

typedef unsigned char uchar;

struct RGE_Master_Object { char pad0[0x10]; short id; char pad1[2]; short object_group; };
struct RGE_Player { char pad0[0x4a]; short id; };
struct RGE_Static_Object { char pad0[4]; int id; RGE_Master_Object* master; RGE_Player* owner; };

class TribeTacticalAIModule { public: int strategicNumber(int); };
class TribeMainDecisionAIModule { public: char pad0[0xf0]; RGE_Player* player; char pad1[0x1146c - 0xf4]; TribeTacticalAIModule tacticalAI; };

struct IntArray {
    int* value;
    int numberValue;
    int maximumSizeValue;
    void setSize(int);
    int checkObjectInList(int, int*);
    void addImportantObject(int);
};

class TribeInformationAIModule {
public:
    char pad0[0x100];
    TribeMainDecisionAIModule* mainDecisionAI;
    char pad1[0x148 - 0x104];
    IntArray importantObjects;
    int checkDefend(RGE_Static_Object*);
};

static int add_to_important(IntArray* list, int id)
{
    int n = list->numberValue;
    if (n > list->maximumSizeValue - 1) {
        list->setSize(n + 1);
    }
    list->value[list->numberValue] = id;
    list->numberValue++;
    return 1;
}

int TribeInformationAIModule::checkDefend(RGE_Static_Object* obj)
{
    int group = obj->master->object_group;
    int owner = obj->owner->id;
    int id;
    int tmp;

    switch (obj->master->id) {
    case 109: {
        if (owner != this->mainDecisionAI->player->id) return 0;
        if (this->mainDecisionAI->tacticalAI.strategicNumber(0x38) <= 0) return 0;
        id = obj->id;
        for (int i = 0; i < this->importantObjects.numberValue && i < this->importantObjects.maximumSizeValue; i++) {
            if (this->importantObjects.value[i] == id) return 1;
        }
        return add_to_important(&this->importantObjects, id);
    }
    case 45: {
        if (owner != this->mainDecisionAI->player->id) return 0;
        if (this->mainDecisionAI->tacticalAI.strategicNumber(0x46) <= 0) return 0;
        id = obj->id;
        for (int i = 0; i < this->importantObjects.numberValue && i < this->importantObjects.maximumSizeValue; i++) {
            if (this->importantObjects.value[i] == id) return 1;
        }
        return add_to_important(&this->importantObjects, id);
    }
    case 159: {
        if (this->mainDecisionAI->tacticalAI.strategicNumber(0x37) <= 0) return 0;
        id = obj->id;
        for (int i = 0; i < this->importantObjects.numberValue && i < this->importantObjects.maximumSizeValue; i++) {
            if (this->importantObjects.value[i] == id) return 1;
        }
        return add_to_important(&this->importantObjects, id);
    }
    case 160: {
        if (this->mainDecisionAI->tacticalAI.strategicNumber(0x36) <= 0) return 0;
        id = obj->id;
        for (int i = 0; i < this->importantObjects.numberValue && i < this->importantObjects.maximumSizeValue; i++) {
            if (this->importantObjects.value[i] == id) return 1;
        }
        return add_to_important(&this->importantObjects, id);
    }
    default:
        switch (group) {
        case 7:
            if (this->mainDecisionAI->tacticalAI.strategicNumber(0x34) <= 0) return 0;
            this->importantObjects.addImportantObject(obj->id);
            return 1;
        case 8:
            if (this->mainDecisionAI->tacticalAI.strategicNumber(0x33) <= 0) return 0;
            tmp = obj->id;
            if (this->importantObjects.checkObjectInList(1, &tmp) == 1) return 1;
            return add_to_important(&this->importantObjects, tmp);
        case 32:
            if (this->mainDecisionAI->tacticalAI.strategicNumber(0x32) <= 0) return 0;
            tmp = obj->id;
            if (this->importantObjects.checkObjectInList(1, &tmp) == 1) return 1;
            return add_to_important(&this->importantObjects, tmp);
        default:
            return 0;
        }
    }
}
