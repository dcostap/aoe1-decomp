// VA: 00508320 TribeBuildingUnitAIModule::processNotify
// Source: taiuaimd.cpp lines 3027-3115
// Attempt log:
// baseline: rough decompiler-style source had the wrong switch and omitted dynamic-list growth.
// structural reconstruction: copied the exact same-TU UnitAIModule/RGE_Player/RGE_Static_Object
// surfaces from 005068B0 and modeled the three binary dispatch cases (0x1f4, 0x258, 0x2bb).
// probe 2: adding the full list-growth/removal bodies improved structure but left two inline
// growth calls and no real resize call.
// probe 3: modeling +0x60 as ManagedArray_int and using resize for 0x1f4 reduced the body to
// 607 bytes and restored the direct resize relocation.
// probe 4: normalized the switch expression; no lookup table was emitted and it was rolled back.
// probe 5: added the binary-proven type 0x20b/default-return arm; VC5 emitted the expected
// compressed lookup table and all 11 ordered calls, but the local table remained after the
// original boundary until the body is byte-sized.
// probe 6: used a branch-local ManagedArray pointer, preloaded the 0x258 caller, and reread
// 0x2bb maximum size; exact-block coverage reached 85% and the remaining drift localized to
// the second removal search plus the lookup-table boundary.
// probe 7: changed the 0x1f4 pointer to a natural reference and matched its growth compare
// operands; best emitted result was 317 changed bytes / 64.71% shape / all calls aligned.
// probe 8: do/while removal-loop variants moved farther; restored probe 7.
// probe 9/10: fresh post-hit removal locals and a guarded do/while were also farther; restored
// the probe-7 source shape.
// probe 11: give the second removal search an explicit typed maximum local before its list pointer;
// this follows the original max/caller/pointer load order without adding codegen-only scaffolding.
// result: the body shrank from 832 to 828 bytes and positional diff improved 317 to 313, but
// VC5 still reused the prior max register and kept the pointer-first removal CFG.
// fresh worker probe: replaced the 0x2bb pointer-walk search with a natural indexed while and
// a do/while compaction loop; size reached 600 and positional diff improved to 135.
// kept the max/list locals with that do/while shape; event-pointer allocation returned to the
// original prologue family and positional diff improved to 89 with all 11 calls aligned.
// rolled back a direct-value variant; it moved the prologue and worsened the diff to 138.
// left in scratch: all 11 call targets and the main 0x1f4/0x258 bodies align; remaining
// mismatch is the dispatch-table relocation and 0x2bb max/list register order.

// This function uses the period UnitAIModule layout and the same-TU virtual surfaces as
// the exact transport/fishing processNotify donors.  The target class adds no fields.
typedef unsigned long ulong;
typedef unsigned char uchar;

void* operator new(unsigned int size);
void operator delete(void* ptr);

struct NotifyEvent {
    int caller;          // +0x00
    char gap_04[4];      // +0x04
    int mType;           // +0x08
    char gap_0c[4];      // +0x0c
    int p2;              // +0x10
};

class RGE_Player {
public:
    virtual ~RGE_Player(); virtual void p01(); virtual void p02(); virtual void p03();
    virtual void p04(); virtual void p05(); virtual void p06(); virtual void p07();
    virtual void p08(); virtual void p09(); virtual void p10(); virtual void p11();
    virtual void p12(); virtual void p13(); virtual void p14(); virtual void p15();
    virtual void p16(); virtual void p17(); virtual void p18(); virtual void p19();
    virtual void p20(); virtual void p21(); virtual void p22(); virtual void p23();
    virtual void p24(); virtual void p25(); virtual void p26(); virtual void p27();
    virtual void p28(); virtual void p29(); virtual void p30(); virtual void p31();
    virtual void p32(); virtual void p33(); virtual void p34(); virtual void p35();
    virtual void p36(); virtual void p37(); virtual void p38(); virtual void p39();
    virtual void p40(); virtual void p41(); virtual void p42(); virtual void p43();
    virtual void p44(); virtual void p45(); virtual void p46(); virtual void p47();
    virtual void p48(); virtual void p49(); virtual void p50(); virtual void p51();
    virtual void p52(); virtual void p53(); virtual void p54(); virtual void p55();
    virtual void p56(); virtual void p57();
    virtual void notifyCommander(int, int, int, long, long, long); // +0xe8
    int computerPlayer();
};

class RGE_Action {
public:
    char gap_00[0x0c];
    uchar state;
};

class RGE_Action_List {
public:
    uchar have_action();
    RGE_Action* get_action();
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6c();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7c();
    virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8c();
    virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9c();
    virtual void va0(); virtual void va4(); virtual void va8(); virtual void vac();
    virtual void vb0(); virtual void vb4(); virtual void vb8(); virtual void vbc();
    virtual void vc0(); virtual void vc4(); virtual void vc8(); virtual void vcc();
    virtual void vd0(); virtual void vd4(); virtual void vd8(); virtual void vdc();
    virtual void ve0(); virtual void ve4();
    virtual uchar underAttack();                 // +0xe8
    virtual void setUnderAttack(uchar one);      // +0xec

    int id;             // +0x04
    void* master_obj;   // +0x08
    RGE_Player* owner;  // +0x0c
    char gap_10[0x174];
    RGE_Action_List* action_list; // +0x184
};

class ManagedArray_int {
public:
    int* value;             // +0x00
    int numberValue;        // +0x04
    int desiredNumberValue; // +0x08
    int maximumSizeValue;   // +0x0c

    int resize(int new_size);
};

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual void save(int);
    virtual void load(int);
    virtual RGE_Player* owner();
    virtual int order(int, int, int, int, float, float, float, float, int, int, int);
    virtual int notify(int, int, int, long, long, long);
    virtual int notifyCommander(int, int, int, long, long, long);
    virtual int notifyCommander(void*);
    virtual void search();
    virtual int importantWhenDead(int);
    virtual int retryableOrder(int);
    virtual int actionRequiresLiveTarget(int);
    virtual int bestUnitToAttack(int, int, float*);
    virtual int mostDangerousEnemy(float*);
    virtual int weakestEnemy(float*);
    virtual int closestAttacker(float*);
    virtual int closestObject(int, int, int, int, int*);
    virtual int closestResourceObject(int, int*);
    virtual int closestUndiscoveredTile(int*, int*, int);
    virtual void logDebug(char*);
    virtual int canAttackUnit(void*);
    virtual int canAttackUnitAtNeutrality(int);
    virtual int stopObject(int);
    virtual int attackObject(int, int);
    virtual int attackRoundupObject(int);
    virtual int huntObject(int, int);
    virtual int gatherObject(int, int);
    virtual int convertObject(int, int);
    virtual int healObject(int, int);
    virtual int repairObject(int, int);
    virtual int buildObject(int, int);
    virtual int tradeWithObject(int, int);
    virtual int explore(int, int, int);
    virtual int enterObject(int, int);
    virtual int unload(int, float, float);
    virtual int transportObject(float, float, float, int);
    virtual int moveTo(float, float, float, float, int);
    virtual int moveTo(int, float, int);
    virtual int moveTo(int, int);
    virtual int evasiveMoveTo(float, float, float, int);
    virtual int intelligentEvasiveMoveTo(float, float, float, int, int);
    virtual int runAwayFromAttackers(int);
    virtual int followObject(int, float, int);
    virtual int defendObject(int, float, int);
    virtual int defendPosition(float, float, float, int);
    virtual int seekAndDestroy(int, int, int, int);
    virtual int exploreAndDestroy(int, int, int);
    virtual int importantObject(int);
    virtual int convertToLOSResourceType(int);
    virtual int canConvert(int);
    virtual int processOrder(void*, int);
    virtual int processNotify(NotifyEvent*, ulong);
    virtual void processGroupNotify(void*);
    virtual int processIdle(int);
    virtual int processMisc();
    virtual int processRetryableOrder();
    virtual int bestUnitToHeal(int, float*);
    virtual int bestUnitToConvert(float*);

    RGE_Static_Object* obj;       // +0x04
    char gap_08[0x20];            // +0x08
    int currentOrder;             // +0x28
    char gap_2c[0x08];            // +0x2c
    int currentTarget;            // +0x34
    char gap_38[0x28];             // +0x38
    ManagedArray_int attackingUnitsValue; // +0x60

    void purgeNotifyQueue(ulong param_2);
    void askForHelp(int caller);
};

class TribeBuildingUnitAIModule : public UnitAIModule {
public:
    int processNotify(NotifyEvent* event, ulong param_2);
};

int TribeBuildingUnitAIModule::processNotify(NotifyEvent* event, ulong param_2)
{
    switch (event->mType - 0x1f4) {
    case 0:
    {
        if (event->p2 <= 0) {
            RGE_Static_Object* obj = this->obj;
            obj->owner->notifyCommander(obj->id, obj->id, 0x209, event->caller, 0, 0);
            this->purgeNotifyQueue(param_2);
            return 4;
        }

        if (this->attackingUnitsValue.numberValue == 0 ||
            this->obj->owner->computerPlayer() == 1) {
            RGE_Static_Object* obj = this->obj;
            obj->owner->notifyCommander(obj->id, obj->id, 0x201, event->caller, 0, 0);
        }

        int count = this->attackingUnitsValue.numberValue;
        ManagedArray_int& array = this->attackingUnitsValue;
        int i = 0;
        for (; i < count && i < array.maximumSizeValue; ++i) {
            if (array.value[i] == event->caller) goto found_for_help;
        }
        if (this->obj->owner->computerPlayer() == 0 &&
            this->currentTarget != event->caller) {
            this->askForHelp(event->caller);
        }

found_for_help:
        i = 0;
        int caller = event->caller;
        count = array.numberValue;
        for (; i < count && i < array.maximumSizeValue; ++i) {
            if (array.value[i] == caller) goto already_in_list;
        }

        if (array.numberValue > array.maximumSizeValue - 1) {
            array.resize(array.numberValue + 1);
        }
        array.value[array.numberValue] = caller;
        array.numberValue++;

already_in_list:
        this->obj->setUnderAttack(1);
        return 2;
    }

    case 0x17:
        return 2;

    case 0x64:
    {
        int caller = event->caller;
        int count = this->attackingUnitsValue.numberValue;
        int i = 0;
        for (; i < count && i < this->attackingUnitsValue.maximumSizeValue; ++i) {
            if (this->attackingUnitsValue.value[i] == caller) goto changed_258;
        }

        if (this->attackingUnitsValue.numberValue >
            this->attackingUnitsValue.maximumSizeValue - 1) {
            int newMax = this->attackingUnitsValue.numberValue + 1;
            int* newList = (int*)operator new(newMax * 4);
            if (newList != 0) {
                for (i = 0; i < this->attackingUnitsValue.maximumSizeValue && i < newMax; ++i)
                    newList[i] = this->attackingUnitsValue.value[i];
                operator delete(this->attackingUnitsValue.value);
                this->attackingUnitsValue.value = newList;
                this->attackingUnitsValue.maximumSizeValue = newMax;
            }
        }
        this->attackingUnitsValue.value[this->attackingUnitsValue.numberValue] = caller;
        this->attackingUnitsValue.numberValue++;

changed_258:
        this->obj->setUnderAttack(1);
        return 2;
    }

    case 0xc7:
    {
        int count = this->attackingUnitsValue.numberValue;
        int i = 0;
        for (; i < count && i < this->attackingUnitsValue.maximumSizeValue; ++i) {
            if (this->attackingUnitsValue.value[i] == event->caller) goto found_2bb;
        }
        return 2;

found_2bb:
        i = 0;
        int max = this->attackingUnitsValue.maximumSizeValue;
        int* list = this->attackingUnitsValue.value;
        while (i < max && list[i] != event->caller) {
            ++i;
        }
        if (i >= max)
            return 2;
        if (i < max - 1) {
            do {
                ++i;
                list[i - 1] = list[i];
            } while (i < max - 1);
        }
        this->attackingUnitsValue.numberValue--;
        if (this->attackingUnitsValue.numberValue < 0)
            this->attackingUnitsValue.numberValue = 0;
        return 2;
    }

    default:
        return 2;
    }
}
