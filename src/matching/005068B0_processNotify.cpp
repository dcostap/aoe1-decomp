// VA: 005068B0, processNotify, 444 bytes
// Source: taiuaimd.cpp lines 2051-2117
// Status: EXACT — validated VC5 codegen match
// Attempt log:
// - v1: natural decompiler-shaped implementation with local structs/vtable pads.
// - v2: fixed notify caller offset to +0, p2 to +0x10 and base call signature with ulong.
// - v3/v4: changed mType dispatch to subtract chain; v4 uses `t != 0 && t != 0x1b`.
// - v5: cached helpMax in scan loops to avoid extra max>0 pretest/pointer-walk family.
// - v6: modeled RGE_Static_Object::action_list as pointer at +0x184, fixing final have_action/get_action surface.
// - v7: switch for mType dispatch emits original sub/sub chain exactly.
// - v8: introduced count locals for scan loops to try to get count in ecx and max in edx like original.
// - v9: swapped count/i declaration order; no register change.
// - v10: left in scratch. Best check: 444/444 bytes, positional diff 55.8559%, edit diff 31.3063%, first mismatch at +0xA0.
//   Blocker: scan-loop register/topology mismatch. Original uses indexed loop with ecx=count, edx=max,
//   ebx=list, ebp/edi=caller; rebuilt uses edx=count, ebp=max and pointer-walk/add forms, cascading into
//   allocation-copy registers (newMax/newList/caller) despite matching call set, stack cleanup, and final action-list surface.
// - v11: restored the exact same-TU UnitAIModule, RGE_Player, RGE_Static_Object,
//   and action-list virtual/direct surfaces; indexed scan and copy topology were
//   structurally aligned, but redundant bound guards remained.
// - v12: tested do/while scans and the donor bounded-copy form; do/while caused
//   pointer-walk register coloring, so the indexed for family was retained.
// - v13: removed the outer positive count wrappers; size reached 444 and the
//   remaining drift localized to bound scheduling and relocation identity.
// - v14: expressed both scans as natural combined `i < count && i < helpMax`
//   bounds. Exact 444-byte match with all 13 calls and 9/9 relocations aligned.

#ifndef TAIUAIMD_COMPLETE_TU
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
    virtual void notifyCommander(int, int, int, long, long, long); // +0xE8
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
    void* master_obj;    // +0x08
    RGE_Player* owner;   // +0x0c
    char gap_10[0x174];
    RGE_Action_List* action_list; // +0x184
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
    int* helpList;                // +0x60
    int helpCount;                // +0x64
    char gap_68[4];               // +0x68
    int helpMax;                  // +0x6c

    void purgeNotifyQueue(ulong param_2);
    void askForHelp(int caller);
};

class TribeTransportShipUnitAIModule : public UnitAIModule {
public:
    int processNotify(NotifyEvent* event, ulong param_2);
};
#endif

int TribeTransportShipUnitAIModule::processNotify(NotifyEvent* event, ulong param_2)
{
    switch (event->mType) {
    case 0x1f4:
    case 0x20f:
        break;
    default:
        return UnitAIModule::processNotify(event, param_2);
    }

    if (event->p2 <= 0) {
        RGE_Static_Object* o = this->obj;
#ifdef TAIUAIMD_COMPLETE_TU
        taiuaimd_player_notify(o->owner, o->id, o->id, 0x209, event->caller, 0, 0);
#else
        o->owner->notifyCommander(o->id, o->id, 0x209, event->caller, 0, 0);
#endif
        this->purgeNotifyQueue(param_2);
        return 4;
    }

    if (this->helpCount == 0 || ((RGE_Player*)this->obj->owner)->computerPlayer() == 1) {
        RGE_Static_Object* o = this->obj;
#ifdef TAIUAIMD_COMPLETE_TU
        taiuaimd_player_notify(o->owner, o->id, o->id, 0x201, event->caller, 0, 0);
#else
        o->owner->notifyCommander(o->id, o->id, 0x201, event->caller, 0, 0);
#endif
    }

    int count = this->helpCount;
    int i = 0;
    for (; i < count && i < this->helpMax; ++i) {
        if (this->helpList[i] == event->caller) goto found_for_help;
    }
    if (((RGE_Player*)this->obj->owner)->computerPlayer() == 0 && this->currentTarget != event->caller) {
        this->askForHelp(event->caller);
    }

found_for_help:
    i = 0;
    int caller = event->caller;
    count = this->helpCount;
    for (; i < count && i < this->helpMax; ++i) {
        if (this->helpList[i] == caller) goto already_in_list;
    }

    if (this->helpCount > this->helpMax - 1) {
        int newMax = this->helpCount + 1;
        int* newList = (int*)operator new(newMax * 4);
        if (newList != 0) {
            for (i = 0; i < this->helpMax && i < newMax; ++i)
                newList[i] = this->helpList[i];
            operator delete(this->helpList);
            this->helpList = newList;
            this->helpMax = newMax;
        }
    }
    this->helpList[this->helpCount] = caller;
    this->helpCount++;

already_in_list:
    this->obj->setUnderAttack(1);
    if (this->currentOrder != -1) {
        return 2;
    }

#ifdef TAIUAIMD_COMPLETE_TU
    RGE_Action_Object* obj2 = (RGE_Action_Object*)this->obj;
#else
    RGE_Static_Object* obj2 = this->obj;
#endif
    if (!obj2->action_list->have_action() || obj2->action_list->get_action()->state == 2) {
        this->runAwayFromAttackers(1);
    }
    return 3;
}
