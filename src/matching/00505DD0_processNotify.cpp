// 00505DD0 TribePriestUnitAIModule::processNotify
// Attempt log:
// 1: Direct reconstruction from packet: switch on event->mType, stop/log tails, special 0x25c/0x25b virtual flows, target-visible branch.
// 2: Inlined repeated logging instead of helper; got to 1-byte diff. Fixed RGE_Player::visible_map offset from +34 to +38.

#ifdef TAIUAIMD_COMPLETE_TU
extern FILE* actionFile;
#else
extern void* actionFile;
#endif
extern int fprintf(void*, const char*, ...);
extern const char str_taiuaimd_path[];
extern const char str_fmt_stopObject[];

#ifndef TAIUAIMD_COMPLETE_TU
class RGE_Visible_Map;
class RGE_Player { public: int computerPlayer(); char gap_00[0x38]; RGE_Visible_Map* visible_map; };
class RGE_Static_Object { public: virtual ~RGE_Static_Object(); int id; char gap_08[4]; RGE_Player* owner; char gap_10[0x28]; float x; float y; };
class UnitAIModule;

class NotifyEvent { public: char gap_00[8]; int mType; };

class UnitAIModule {
public:
    virtual ~UnitAIModule(); virtual void save(int); virtual void load(int);
    virtual RGE_Player* owner();
    virtual int order(int, int, int, int, float, float, float, float, int, int, int);
    virtual int notify(int, int, int, long, long, long);
    virtual int notifyCommander(int, int, int, long, long, long);
    virtual int notifyCommander(NotifyEvent*);
    virtual void search(); virtual int importantWhenDead(int);
    virtual int retryableOrder(int); virtual int actionRequiresLiveTarget(int);
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
    virtual int convertObject(int, int); virtual int healObject(int, int);
    virtual int repairObject(int, int); virtual int buildObject(int, int);
    virtual int tradeWithObject(int, int); virtual int explore(int, int, int);
    virtual int enterObject(int, int); virtual int unload(int, float, float);
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
    virtual int canConvert(int); virtual int processOrder(void*, int);
    virtual void processGroupNotify(void*); virtual int processIdle(int);
    virtual int processMisc(); virtual int processRetryableOrder();
    virtual int bestUnitToHeal(int, float*); virtual int bestUnitToConvert(float*);

    RGE_Static_Object* objectValue; // +4

    void removeCurrentTarget();
    RGE_Static_Object* lookupObject(int objectId);
    unsigned char visibleStatus(RGE_Visible_Map* map, int x, int y);
    int processNotify(NotifyEvent* event, unsigned long param_2);
};

class TribePriestUnitAIModule : public UnitAIModule {
public:
    char gap_08[0x28];
    int field_30;
    int field_34;

    int processNotify(NotifyEvent* event, unsigned long param_2);
};
#endif

int TribePriestUnitAIModule::processNotify(NotifyEvent* event, unsigned long param_2)
{
    switch (event->mType) {
    case 0x1f9:
    case 0x1fb:
    case 0x202:
        if (this->objectValue->owner->computerPlayer() == 0 && this->field_30 == 0x25c) {
            this->removeCurrentTarget();
            if (actionFile != 0) {
                int objId;
                if (this->objectValue != 0) {
                    objId = this->objectValue->id;
                } else {
                    objId = -1;
                }
                fprintf(actionFile, str_fmt_stopObject, objId, str_taiuaimd_path, 0x63b);
            }
            this->stopObject(1);
            this->notifyCommander(event);
            return 2;
        }
        if (this->field_30 == 0x25c) {
            int id = this->bestUnitToConvert(0);
            if (id != -1 && this->convertObject(id, 1) == 1) {
                return 3;
            }
        } else if (this->field_30 == 0x25b) {
            int id = this->bestUnitToHeal(0, 0);
            if (id != -1 && this->healObject(id, 1) == 1) {
                return 3;
            }
        }
        this->removeCurrentTarget();
        if (actionFile != 0) {
                int objId;
                if (this->objectValue != 0) {
                    objId = this->objectValue->id;
                } else {
                    objId = -1;
                }
                fprintf(actionFile, str_fmt_stopObject, objId, str_taiuaimd_path, 0x675);
            }
        this->stopObject(0);
        this->notifyCommander(event);
        return 2;

    case 0x1fc:
    {
        RGE_Static_Object* obj = this->lookupObject(this->field_34);
        if (obj != 0) {
#ifdef TAIUAIMD_COMPLETE_TU
            if (this->visibleStatus(taiuaimd_player_visible_map(this->objectValue->owner),
                                    (int)obj->world_x, (int)obj->world_y) == 0x0f) {
#else
            if (this->visibleStatus(this->objectValue->owner->visible_map, (int)obj->x, (int)obj->y) == 0x0f) {
#endif
                return 2;
            }
        }
        this->removeCurrentTarget();
        if (actionFile != 0) {
                int objId;
                if (this->objectValue != 0) {
                    objId = this->objectValue->id;
                } else {
                    objId = -1;
                }
                fprintf(actionFile, str_fmt_stopObject, objId, str_taiuaimd_path, 0x68f);
            }
        this->stopObject(1);
        this->notifyCommander(event);
        break;
    }
    }

    return UnitAIModule::processNotify(event, param_2);
}
