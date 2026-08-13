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
// session sa-a3ad6bc7-r1-Defend baseline: typed candidate was 747 bytes, but used the wrong 0x9e/0xa3 coverage and helper-call surface.
// corrected master cases and restored the four-word ManagedArray layout plus contains/add/resize ABI; prologue and call alignment improved.
// inline duplicate-scan append recovered the three resize calls and reduced drift to 597 bytes at the original 747-byte boundary.
// ordered group if/else and scoped result probes still merged the 0x33/0x32 call paths; shared temporary is the clean retained form.
// distinct group temporaries preserved all 13 ordered calls but expanded the emitted switch-table/function boundary by 148 bytes.
// parameter-home pointer reuse expanded the prologue/frame and was rolled back; a distinct-temp group switch kept calls ordered but expanded by 224 bytes; sparse group switches with a shared tmp still merged one contains/resize pair.
// final pause: natural typed candidate remains 747 bytes (597 positional diff, 11/13 calls); guard order 8, 7, 0x20 recovered 13/13 calls only at 903 bytes, so the clean candidate remains best.

typedef unsigned char uchar;

struct RGE_Master_Object { char pad0[0x10]; short id; char pad1[2]; short object_group; };
struct RGE_Player { char pad0[0x4a]; short id; };
struct RGE_Static_Object { char pad0[4]; int id; RGE_Master_Object* master; RGE_Player* owner; };

class TribeTacticalAIModule { public: int strategicNumber(int); };
class TribeMainDecisionAIModule { public: char pad0[0xf0]; RGE_Player* player; char pad1[0x1146c - 0xf4]; TribeTacticalAIModule tacticalAI; };

struct IntArray {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
    int resize(int);
    int contains(const int&) const;
    int add(int);
};

class TribeInformationAIModule {
public:
    char pad0[0x100];
    TribeMainDecisionAIModule* mainDecisionAI;
    char pad1[0x148 - 0x104];
    IntArray importantObjects;
    int checkDefend(RGE_Static_Object*);
};

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
        if (this->importantObjects.numberValue > this->importantObjects.maximumSizeValue - 1)
            this->importantObjects.resize(this->importantObjects.numberValue + 1);
        this->importantObjects.value[this->importantObjects.numberValue] = id;
        this->importantObjects.numberValue++;
        return 1;
    }
    case 45: {
        if (owner != this->mainDecisionAI->player->id) return 0;
        if (this->mainDecisionAI->tacticalAI.strategicNumber(0x46) <= 0) return 0;
        id = obj->id;
        for (int i = 0; i < this->importantObjects.numberValue && i < this->importantObjects.maximumSizeValue; i++) {
            if (this->importantObjects.value[i] == id) return 1;
        }
        if (this->importantObjects.numberValue > this->importantObjects.maximumSizeValue - 1)
            this->importantObjects.resize(this->importantObjects.numberValue + 1);
        this->importantObjects.value[this->importantObjects.numberValue] = id;
        this->importantObjects.numberValue++;
        return 1;
    }
    case 0x9f: {
        if (this->mainDecisionAI->tacticalAI.strategicNumber(0x37) <= 0) return 0;
        id = obj->id;
        for (int i = 0; i < this->importantObjects.numberValue && i < this->importantObjects.maximumSizeValue; i++) {
            if (this->importantObjects.value[i] == id) return 1;
        }
        if (this->importantObjects.numberValue > this->importantObjects.maximumSizeValue - 1)
            this->importantObjects.resize(this->importantObjects.numberValue + 1);
        this->importantObjects.value[this->importantObjects.numberValue] = id;
        this->importantObjects.numberValue++;
        return 1;
    }
    case 0x9e:
    case 0xa3: {
        if (this->mainDecisionAI->tacticalAI.strategicNumber(0x36) <= 0) return 0;
        id = obj->id;
        for (int i = 0; i < this->importantObjects.numberValue && i < this->importantObjects.maximumSizeValue; i++) {
            if (this->importantObjects.value[i] == id) return 1;
        }
        if (this->importantObjects.numberValue > this->importantObjects.maximumSizeValue - 1)
            this->importantObjects.resize(this->importantObjects.numberValue + 1);
        this->importantObjects.value[this->importantObjects.numberValue] = id;
        this->importantObjects.numberValue++;
        return 1;
    }
    default:
        if (group == 7) {
            if (this->mainDecisionAI->tacticalAI.strategicNumber(0x34) <= 0) return 0;
            this->importantObjects.add(obj->id);
            return 1;
        }
        else if (group == 8) {
            int result8 = this->mainDecisionAI->tacticalAI.strategicNumber(0x33);
            if (result8 > 0) {
                tmp = obj->id;
                if (this->importantObjects.contains(tmp) == 1) return 1;
                if (this->importantObjects.numberValue > this->importantObjects.maximumSizeValue - 1)
                    this->importantObjects.resize(this->importantObjects.numberValue + 1);
                this->importantObjects.value[this->importantObjects.numberValue] = tmp;
                this->importantObjects.numberValue++;
                return 1;
            }
        }
        else if (group == 32) {
            int result32 = this->mainDecisionAI->tacticalAI.strategicNumber(0x32);
            if (result32 > 0) {
                tmp = obj->id;
                if (this->importantObjects.contains(tmp) == 1) return 1;
                if (this->importantObjects.numberValue > this->importantObjects.maximumSizeValue - 1)
                    this->importantObjects.resize(this->importantObjects.numberValue + 1);
                this->importantObjects.value[this->importantObjects.numberValue] = tmp;
                this->importantObjects.numberValue++;
                return 1;
            }
        }
        return 0;
    }
}
