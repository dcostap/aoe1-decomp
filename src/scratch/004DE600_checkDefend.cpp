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
// shardB6 probe: combined group-32 strategic predicate was codegen-neutral; rolled back.
// shardB6 probe: explicit ManagedArray aliases improved block shape but stayed at 11 calls and diff 599; rolled back.
// shardB6 probe: taiinfmd parameter-home overwrite split group calls but grew to 975 bytes and duplicated special growth; rolled back.
// shardB6 probe: group-8 contains != 0 reached diff 587 and two contains calls, but a distinct resize spelling grew to 935 bytes; rolled back.
// Revisit sa-3023930d-r1:
// - Baseline was 747 bytes, 597 positional diff, and 11/13 ordered calls.
// - A separate count plus do/while scan was worse.  It hoisted the array base
//   and changed the proven indexed loop.  The original combined bounds form
//   remains the natural loop input.
// - Branch-local ManagedArray aliases for all four master-id append paths
//   recovered the original +0x148 receiver update and reduced the diff to 289.
//   Those four paths then matched through their complete append block.
// - A sparse group switch with one shared failure label improved the best
//   source to 263 positional diff and 76.92% shape similarity.  VC5 still
//   merged the group-8 and group-32 strategic/append path, leaving 10/13
//   calls.  The original has separate 0x32 and 0x33 strategic calls, two
//   contains calls, and three resize calls in this tail.
// - Distinct group temporaries restored all 13 calls only at 899 bytes
//   (+152).  Parameter-home id reuse restored the observed stack writes but
//   grew to 959 bytes (+212).  A sparse switch with distinct temporaries was
//   also 899 bytes.  These are metric-only shapes and were rejected.
// - Canonical inherited vptr surfaces, the corrected +0x100 md gap, the
//   ManagedArray<int> template spelling, stdlib context, receiver aliases,
//   predicate spellings, and source case order were neutral or worse.
// - Final validation: 747-byte boundary, 226/234 instructions, 10/13 calls,
//   263 positional diff (35.2075%), first mismatch +0x4B.  Retain the typed
//   sparse-switch/common-failure reconstruction for the next evidence pass.

typedef unsigned char uchar;

struct RGE_Master_Object {
    virtual void v00();
    char pad0[0x0c];
    short id;
    char pad1[2];
    short object_group;
};
struct RGE_Player {
    virtual void v00();
    char pad0[0x46];
    short id;
};
struct RGE_Static_Object {
    virtual void v00();
    int id;
    RGE_Master_Object* master;
    RGE_Player* owner;
};

class TribeTacticalAIModule { public: int strategicNumber(int); };
class MainDecisionAIModule {
public:
    virtual void v00();
    char pad0[0xec];
    RGE_Player* player;
};
class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    char pad1[0x1146c - 0xf4];
    TribeTacticalAIModule tacticalAI;
};

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
    int resize(int);
    int contains(const T&) const;
    int add(T);
};

class InformationAIModule {
public:
    virtual void v00();
    char pad0[0xec];
};
class TribeInformationAIModule : public InformationAIModule {
public:
    char pad0[0x10];
    TribeMainDecisionAIModule* mainDecisionAI;
    char pad1[0x148 - 0x104];
    ManagedArray<int> itemsToDefend;
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
        if (owner != this->mainDecisionAI->player->id) goto checkDefend_fail;
        if (this->mainDecisionAI->tacticalAI.strategicNumber(0x38) <= 0) goto checkDefend_fail;
        id = obj->id;
        {
            ManagedArray<int>* list = &this->itemsToDefend;
            int numValues = list->numberValue;
            for (int i = 0; i < numValues && i < list->maximumSizeValue; i++) {
                if (list->value[i] == id) return 1;
            }
            if (list->numberValue > list->maximumSizeValue - 1)
                list->resize(list->numberValue + 1);
            list->value[list->numberValue] = id;
            list->numberValue++;
        }
        return 1;
    }
    case 45: {
        if (owner != this->mainDecisionAI->player->id) goto checkDefend_fail;
        if (this->mainDecisionAI->tacticalAI.strategicNumber(0x46) <= 0) goto checkDefend_fail;
        id = obj->id;
        {
            ManagedArray<int>* list = &this->itemsToDefend;
            int numValues = list->numberValue;
            for (int i = 0; i < numValues && i < list->maximumSizeValue; i++) {
                if (list->value[i] == id) return 1;
            }
            if (list->numberValue > list->maximumSizeValue - 1)
                list->resize(list->numberValue + 1);
            list->value[list->numberValue] = id;
            list->numberValue++;
        }
        return 1;
    }
    case 0x9f: {
        if (this->mainDecisionAI->tacticalAI.strategicNumber(0x37) <= 0) goto checkDefend_fail;
        id = obj->id;
        {
            ManagedArray<int>* list = &this->itemsToDefend;
            int numValues = list->numberValue;
            for (int i = 0; i < numValues && i < list->maximumSizeValue; i++) {
                if (list->value[i] == id) return 1;
            }
            if (list->numberValue > list->maximumSizeValue - 1)
                list->resize(list->numberValue + 1);
            list->value[list->numberValue] = id;
            list->numberValue++;
        }
        return 1;
    }
    case 0x9e:
    case 0xa3: {
        if (this->mainDecisionAI->tacticalAI.strategicNumber(0x36) <= 0) goto checkDefend_fail;
        id = obj->id;
        {
            ManagedArray<int>* list = &this->itemsToDefend;
            int numValues = list->numberValue;
            for (int i = 0; i < numValues && i < list->maximumSizeValue; i++) {
                if (list->value[i] == id) return 1;
            }
            if (list->numberValue > list->maximumSizeValue - 1)
                list->resize(list->numberValue + 1);
            list->value[list->numberValue] = id;
            list->numberValue++;
        }
        return 1;
    }
    default:
        switch (group) {
        case 7:
            if (this->mainDecisionAI->tacticalAI.strategicNumber(0x34) <= 0)
                goto checkDefend_fail;
            this->itemsToDefend.add(obj->id);
            return 1;
        case 8: {
            int result8 = this->mainDecisionAI->tacticalAI.strategicNumber(0x33);
            if (result8 <= 0) goto checkDefend_fail;
            tmp = obj->id;
            if (this->itemsToDefend.contains(tmp) == 1) return 1;
            int numValues = this->itemsToDefend.numberValue;
            if (this->itemsToDefend.maximumSizeValue - 1 < numValues)
                this->itemsToDefend.resize(numValues + 1);
            this->itemsToDefend.value[this->itemsToDefend.numberValue] = tmp;
            this->itemsToDefend.numberValue++;
            return 1;
        }
        case 32: {
            int result32 = this->mainDecisionAI->tacticalAI.strategicNumber(0x32);
            if (result32 <= 0) goto checkDefend_fail;
            tmp = obj->id;
            if (this->itemsToDefend.contains(tmp) == 1) return 1;
            int numValues = this->itemsToDefend.numberValue;
            if (this->itemsToDefend.maximumSizeValue - 1 < numValues)
                this->itemsToDefend.resize(numValues + 1);
            this->itemsToDefend.value[this->itemsToDefend.numberValue] = tmp;
            this->itemsToDefend.numberValue++;
            return 1;
        }
        default:
            goto checkDefend_fail;
        }
    }

checkDefend_fail:
    return 0;
}
