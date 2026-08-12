// VA: 00414D40 UnitAIModule::order(int,int,int,int,float,float,float,float,int,int,int)
// aiuaimod.cpp
// Attempt log:
// - Baseline: typed direct-call reconstruction; exact size/call set, but VC5 saves
//   EDI at entry while the original delays it until the nonzero-p9 path.
// - Tried p2 directly, a block-local orderType, early-return versus explicit-else
//   layout, positive state guard, <3 versus <=2, corrected virtual return types,
//   and stdio context. These emitted the same best nonexact code (except <3,
//   which changed the compare immediate); no source-shape lead remains in this
//   isolated TU.
// - Follow-up session probes: a branch-local p2 copy, an address-taken p2 alias,
//   register/const p2 qualifiers, and /GX all emitted the same code. A natural
//   switch(p9) worsened size/call alignment and was rolled back. The remaining
//   structural gap is the original's delayed push edi after the p9 test versus
//   VC5's entry push edi; no ABI/layout or ordered-call discrepancy was found.
// - Fresh normal-414D40-r1 pass: baseline reconfirmed the 306-byte, 8-call
//   canonical source. Separate branch-local copies, a top-level guard-bound
//   copy, a single-iteration loop, a common done label, and positive-guard
//   if/else layout were all codegen duplicates. The delayed EDI save remains
//   the only actionable gap; the clean direct-parameter source is restored.
// - Best canonical source retained: positive state guard, direct p2 use, typed
//   object/member ownership, real virtual calls, and standard FILE/fprintf ABI.

#include <stdio.h>

class RGE_Static_Object;
struct OrderEvent;

extern FILE* actionFile;
extern const char str_fmt_stopObject[];
extern const char str_aiuaimod_path[];

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int id;                         // +0x04
    char gap_08[0x48 - 0x08];
    unsigned char object_state;     // +0x48
};

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual void save(int); virtual void load(int); virtual void* owner() const;
    virtual int order(int, int, int, int, float, float, float, float, int, int, int);
    virtual int notify(int, int, int, long, long, long);
    virtual int notifyCommander(int, int, int, long, long, long);
    virtual int notifyCommander(void*); virtual void search();
    virtual int importantWhenDead(int); virtual int retryableOrder(int);
    virtual int actionRequiresLiveTarget(int); virtual int bestUnitToAttack(int, int, float*);
    virtual int mostDangerousEnemy(float*); virtual int weakestEnemy(float*);
    virtual int closestAttacker(float*); virtual int closestObject(int, int, int, int, int*);
    virtual int closestResourceObject(int, int*); virtual int closestUndiscoveredTile(int*, int*, int);
    virtual void logDebug(char*); virtual int canAttackUnit(RGE_Static_Object*);
    virtual int canAttackUnitAtNeutrality(int);
    virtual int stopObject(int flag); // +0x58
    virtual int attackObject(int, int); virtual int attackRoundupObject(int);
    virtual int huntObject(int, int); virtual int gatherObject(int, int);
    virtual int convertObject(int, int); virtual int healObject(int, int);
    virtual int repairObject(int, int); virtual int buildObject(int, int);
    virtual int tradeWithObject(int, int); virtual int explore(int, int, int);
    virtual int enterObject(int, int); virtual int unload(int, float, float);
    virtual int transportObject(float, float, float, int);
    virtual int moveTo(float, float, float, float, int);
    virtual int moveTo(int, float, int); virtual int moveTo(int, int);
    virtual int evasiveMoveTo(float, float, float, int);
    virtual int runAwayFromAttackers(int);
    virtual int intelligentEvasiveMoveTo(float, float, float, int, int);
    virtual int followObject(int, float);
    virtual int defendObject(int, float, int); virtual int defendPosition(float, float, float, int);
    virtual int seekAndDestroy(int, int, int, int); virtual int exploreAndDestroy(int, int, int);
    virtual int importantObject(int); virtual int convertToLOSResourceType(int);
    virtual int canConvert(int);
    virtual int processOrder(OrderEvent* queue, int flag); // +0xC8

    RGE_Static_Object* objectValue;  // +0x04
    char gap_08[0x18 - 0x08];
    OrderEvent* orderQueueValue;     // +0x18
    char gap_1C[0x28 - 0x1C];
    int currentOrderValue;           // +0x28
    int currentOrderPriorityValue;   // +0x2C
    char gap_30[0x34 - 0x30];
    int currentTargetValue;          // +0x34
    char gap_38[0x3C - 0x38];
    float currentTargetXValue;       // +0x3C
    float currentTargetYValue;       // +0x40
    float currentTargetZValue;       // +0x44
    float desiredTargetDistanceValue;// +0x48

    int addToOrderQueue(int p1, int p2, int p3, int p4, float p5, float p6, float p7, float p8, int p9, int p10);
    void removeCurrentTarget();
    void purgeNotifyQueue(unsigned long flags);
};

int UnitAIModule::order(int p1, int p2, int p3, int p4, float p5, float p6, float p7, float p8, int p9, int p10, int p11)
{
    if (this->objectValue->object_state <= 2) {
        if (p9 == 0) {
            this->addToOrderQueue(p1, p2, p3, p4, p5, p6, p7, p8, p10, p11);
            return 1;
        }

        if (p10 == 1) {
            this->addToOrderQueue(this->objectValue->id,
                                  this->currentOrderValue,
                                  this->currentTargetValue,
                                  -1,
                                  this->currentTargetXValue,
                                  this->currentTargetYValue,
                                  this->currentTargetZValue,
                                  this->desiredTargetDistanceValue,
                                  1,
                                  this->currentOrderPriorityValue);
        }

        this->addToOrderQueue(p1, p2, p3, p4, p5, p6, p7, p8, 1, p11);

        if (p2 != 0x2D9) {
            this->removeCurrentTarget();
            if (actionFile != 0) {
                int id;
                if (this->objectValue != 0)
                    id = this->objectValue->id;
                else
                    id = -1;
                fprintf(actionFile, str_fmt_stopObject, id, str_aiuaimod_path, 0x6F3);
            }
            this->stopObject(1);
        }

        this->purgeNotifyQueue(0);
        this->processOrder(this->orderQueueValue, 0);
    }
    return 1;
}
