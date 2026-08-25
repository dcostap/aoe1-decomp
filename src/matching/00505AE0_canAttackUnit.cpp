#ifndef TAIUAIMD_COMPLETE_TU
class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int id;
};

class TribePriestUnitAIModule {
public:
    virtual ~TribePriestUnitAIModule();
    virtual void save(int); virtual void load(int); virtual RGE_Player* owner();
    virtual int order(int, int, int, int, float, float, float, float, int, int, int);
    virtual int notify(int, int, int, long, long, long);
    virtual int notifyCommander(int, int, int, long, long, long);
    virtual int notifyCommander(void*); virtual void search();
    virtual int importantWhenDead(int); virtual int retryableOrder(int);
    virtual int actionRequiresLiveTarget(int);
    virtual int bestUnitToAttack(int, int, float*);
    virtual int mostDangerousEnemy(float*); virtual int weakestEnemy(float*);
    virtual int closestAttacker(float*);
    virtual int closestObject(int, int, int, int, int*);
    virtual int closestResourceObject(int, int*);
    virtual int closestUndiscoveredTile(int*, int*, int);
    virtual void logDebug(char*); virtual int canAttackUnit(RGE_Static_Object*);
    virtual int canAttackUnitAtNeutrality(int); virtual int stopObject(int);
    virtual int attackObject(int, int); virtual int attackRoundupObject(int);
    virtual int huntObject(int, int); virtual int gatherObject(int, int);
    virtual int convertObject(int, int);
    virtual int healObject(int, int); virtual int repairObject(int, int);
    virtual int buildObject(int, int); virtual int tradeWithObject(int, int);
    virtual int explore(int, int, int); virtual int enterObject(int, int);
    virtual int unload(int, float, float);
    virtual int transportObject(float, float, float, int);
    virtual int moveTo(float, float, float, float, int);
    virtual int moveTo(int, float, int); virtual int moveTo(int, int);
    virtual int evasiveMoveTo(float, float, float, int);
    virtual int intelligentEvasiveMoveTo(float, float, float, int, int);
    virtual int runAwayFromAttackers(int); virtual int followObject(int, float, int);
    virtual int defendObject(int, float, int);
    virtual int defendPosition(float, float, float, int);
    virtual int seekAndDestroy(int, int, int, int);
    virtual int exploreAndDestroy(int, int, int);
    virtual int importantObject(int); virtual int convertToLOSResourceType(int);
    virtual int canConvert(int id);
};
#endif

int TribePriestUnitAIModule::canAttackUnit(RGE_Static_Object* obj) {
    if (obj != 0) {
        return canConvert(obj->id);
    }
    return 0;
}
