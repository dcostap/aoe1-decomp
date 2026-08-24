// VA: 00506CC0 TribeFishingShipUnitAIModule::processNotify
// Source: taiuaimd.cpp lines 2197-2276
// Attempt log:
// 1: natural reconstruction from packet with direct fields, virtual calls, dynamic int-list growth: broad mismatch; compiler cached NotifyEvent in EBP not original EDI.
// 2: add register event alias and use it throughout to try EDI allocation; no register change.
// 3: tried notification type gate as switch; no prologue/register improvement and slightly worse diff, rolled back.
// 4: tried narrow /O1 as possible register/prologue probe; object shrank to 521 and failed configured size, flag removed.
// 5: tried /O2 /Oy /Ob0 flag probe; same as default, flag removed.
// 6: remove event alias and use parameter directly to test whether alias caused EBP cache; no change.
// 7: corrected RGE_Player virtual padding so sendCommand is at vtable +0xE8 instead of +0x20; behavior surface improved but diff worsened due existing early register barrier.
// 8: reviewed late stopObject/vf58/vfA4 surface: current manual vtbl field is behaviorally suspect for ECX=this scheduling, but changing to full virtual class would require reworking all field offsets.
// 9: compared default vs flag/no-alias/switch variants; best byte metrics remain the natural default family before vtable padding, but kept vtable padding because it matches binary-observed +0xE8 call target.
// 10: left in scratch: main blocker is first prologue/register allocation (original EDI=NotifyEvent, ESI=this; rebuilt EBP=NotifyEvent), cascading through all event/list logic plus unresolved true class/vtable surface for late stop calls.
// 11: restored the same-TU UnitAIModule/RGE_Static_Object/RGE_Player surfaces as the exact transport-ship donor; the target's +0x10 call is the real order slot, followed by stopObject and runAwayFromAttackers.

#include <stdio.h>

#ifndef TAIUAIMD_COMPLETE_TU
typedef unsigned long ulong;

extern void* operator new(unsigned int size);
extern void operator delete(void* ptr);
extern FILE* actionFile;

struct NotifyEvent {
    int caller;
    char gap_04[4];
    int mType;
    char gap_0C[4];
    int p2;
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
    virtual unsigned char underAttack(); // +0xE8
    virtual void setUnderAttack(unsigned char one); // +0xEC

    int id;                         // +0x04
    void* master_obj;               // +0x08
    RGE_Player* owner;              // +0x0C
    char gap_10[0x174];
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
    virtual int stopObject(int); // +0x58
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
    virtual int runAwayFromAttackers(int); // +0xA4
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

    RGE_Static_Object* objectValue;       // +0x04
    int moodValue;                        // +0x08
    int objectCategoryValue;              // +0x0C
    int orderQueueSizeValue;              // +0x10
    int orderQueueMaxSizeValue;           // +0x14
    void* orderQueueValue;                // +0x18
    int notifyQueueSizeValue;             // +0x1C
    int notifyQueueMaxSizeValue;          // +0x20
    void* notifyQueueValue;               // +0x24
    int currentOrderValue;                // +0x28
    int currentOrderPriorityValue;        // +0x2C
    int currentActionValue;               // +0x30
    int currentTargetValue;               // +0x34
    int currentTargetTypeValue;           // +0x38
    float currentTargetXValue;            // +0x3C
    float currentTargetYValue;            // +0x40
    float currentTargetZValue;            // +0x44
    float desiredTargetDistanceValue;     // +0x48
    int defendTargetValue;                // +0x4C
    int lastOrderValue;                   // +0x50
    int lastActionValue;                  // +0x54
    int lastTargetValue;                  // +0x58
    int lastTargetTypeValue;              // +0x5C
    int* helpList;                        // +0x60
    int helpCount;                        // +0x64
    int helpDesired;                      // +0x68
    int helpMax;                          // +0x6C

    void purgeNotifyQueue(ulong param_2);
    void askForHelp(int caller);
};

class TribeFishingShipUnitAIModule : public UnitAIModule {
public:
    int processNotify(NotifyEvent* ev, ulong flags);
};
#endif

int TribeFishingShipUnitAIModule::processNotify(NotifyEvent* ev, ulong flags)
{
    switch (ev->mType) {
    case 0x1f4:
    case 0x20f:
        break;
    default:
        return UnitAIModule::processNotify(ev, flags);
    }

    if (ev->p2 <= 0) {
        RGE_Static_Object* obj = this->objectValue;
#ifdef TAIUAIMD_COMPLETE_TU
        taiuaimd_player_notify(obj->owner, obj->id, obj->id, 0x209, ev->caller, 0, 0);
#else
        obj->owner->notifyCommander(obj->id, obj->id, 0x209, ev->caller, 0, 0);
#endif
        this->purgeNotifyQueue(flags);
        return 4;
    }

    if (this->helpCount == 0 || this->objectValue->owner->computerPlayer() == 1) {
        RGE_Static_Object* obj = this->objectValue;
#ifdef TAIUAIMD_COMPLETE_TU
        taiuaimd_player_notify(obj->owner, obj->id, obj->id, 0x201, ev->caller, 0, 0);
#else
        obj->owner->notifyCommander(obj->id, obj->id, 0x201, ev->caller, 0, 0);
#endif
    }

    int count = this->helpCount;
    int i = 0;
    for (; i < count && i < this->helpMax; ++i) {
        if (this->helpList[i] == ev->caller) goto skip_help;
    }
    if (this->objectValue->owner->computerPlayer() == 0 &&
        this->currentTargetValue != ev->caller) {
        this->askForHelp(ev->caller);
    }

skip_help:
    i = 0;
    int caller = ev->caller;
    count = this->helpCount;
    for (; i < count && i < this->helpMax; ++i) {
        if (this->helpList[i] == caller) goto after_add;
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

after_add:
    this->objectValue->setUnderAttack(1);
    if (this->objectValue->owner->computerPlayer() == 0 &&
        this->currentOrderValue != -1) {
        return 2;
    }
    if (this->currentActionValue != 0x262) {
        this->order(this->objectValue->id, this->currentOrderValue,
                    this->currentTargetValue, -1,
                    this->currentTargetXValue, this->currentTargetYValue,
                    this->currentTargetZValue, this->desiredTargetDistanceValue,
                    0, 0, this->currentOrderPriorityValue);
        if (actionFile != 0) {
            int id;
            if (this->objectValue != 0)
                id = this->objectValue->id;
            else
                id = -1;
            fprintf(actionFile, "#%d call stopObject %s %d\n", id,
                    "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x8d4);
        }
        this->stopObject(1);
    }
    this->runAwayFromAttackers(1);
    return 3;
}
