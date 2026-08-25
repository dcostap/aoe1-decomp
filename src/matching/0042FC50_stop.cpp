extern "C" void* actionFile;
extern "C" int fprintf(void* stream, const char* format, ...);

#ifndef RGE_COM_OBJ_SHARED_CONTEXT
class RGE_Static_Object;

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual void save(int);
    virtual void load(int);
    virtual void owner();
    virtual void order();
    virtual int notify(int, int, int, long, long, long);
    virtual int notifyCommander(void*);
    virtual int notifyCommander(int, int, int, long, long, long);
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
    virtual int canAttackUnit(RGE_Static_Object*);
    virtual int canAttackUnitAtNeutrality(int);
    virtual int stopObject(int force);
};

class RGE_Action_Object {
public:
    virtual void stop();
};

class RGE_Combat_Object : public RGE_Action_Object {
public:
    int id;
    unsigned char gap_08[0x6C];
    UnitAIModule* unitAIValue;

    virtual void stop();
};
#endif

void RGE_Combat_Object::stop() {
    RGE_Action_Object::stop();
    if (unitAIValue != 0) {
        if (actionFile != 0) {
            fprintf(actionFile, "#%d call stopObject %s %d\n", id, "C:\\msdev\\work\\age1_x1\\com_obj.cpp", 0xAB);
        }
        unitAIValue->stopObject(1);
    }
}
