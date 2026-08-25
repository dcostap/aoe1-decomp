// TribeLionUnitAIModule::processIdle (00504600)
// taiuaimd.cpp:441-515, 251 bytes
// __thiscall: ecx=this, 1 stack param, ret 4

#ifndef TAIUAIMD_COMPLETE_TU
class NotifyEvent;
class RGE_Player;
class RGE_Static_Object;
class RGE_Game_World;

class RGE_Base_Game {
public:
    char gap_00[0x3F4];
    RGE_Game_World* world;
    int scenarioGame();
    int singlePlayerGame();
};

extern RGE_Base_Game* rge_base_game;  // 0x62C574

class RGE_Master_Static_Object {
public:
    char gap_00[0x28];
    float los;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    float distance_to_object(RGE_Static_Object* target);
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
};

class RGE_Game_World {
public:
    char gap_00[0x88];
    void** objectsValue;
    int numberObjectsValue;
    int maxNumberObjectsValue;
    void** negativeObjectsValue;
    int numberNegativeObjectsValue;
    int maxNumberNegativeObjectsValue;
    int difficultyLevel();
};

// Float constants: 0x3F400000 = 0.75, 0x3F000000 = 0.5, 0x3F800000 = 1.0

class UnitAIModule {
public:
    RGE_Static_Object* obj;  // +0x04
    char gap_08[0xF8];
    int idleTimeout;         // +0x100

    void setAdjustedIdleTimeout();
    RGE_Static_Object* lookupObject(int id);

    virtual ~UnitAIModule();
    virtual void save(int); virtual void load(int); virtual RGE_Player* owner();
    virtual int order(int, int, int, int, float, float, float, float, int, int, int);
    virtual int notify(int, int, int, long, long, long);
    virtual int notifyCommander(int, int, int, long, long, long);
    virtual int notifyCommander(NotifyEvent*);
    virtual void search(); virtual int importantWhenDead(int);
    virtual int retryableOrder(int); virtual int actionRequiresLiveTarget(int);
    virtual int bestUnitToAttack(int, int, float*);
    virtual int mostDangerousEnemy(float*); virtual int weakestEnemy(float*);
    virtual int closestAttacker(float*);
    virtual int closestObject(int, int, int, int, int*); // vt[16] = +0x40
    virtual int closestResourceObject(int, int*);
    virtual int closestUndiscoveredTile(int*, int*, int);
    virtual void logDebug(char*); virtual int canAttackUnit(RGE_Static_Object*);
    virtual int canAttackUnitAtNeutrality(int); virtual int stopObject(int);
    virtual int attackObject(int, int); // vt[23] = +0x5C
};

class TribeLionUnitAIModule : public UnitAIModule {
public:
    int processIdle(int param_1);
};
#endif

int TribeLionUnitAIModule::processIdle(int param_1)
{
#ifdef TAIUAIMD_COMPLETE_TU
    idleTimeoutValue = 6000;
#else
    idleTimeout = 6000;
#endif
    setAdjustedIdleTimeout();

    int targetId = closestObject(-1, -1, -1, -1, 0);
    RGE_Static_Object* newTarget = lookupObject(targetId);

    if (targetId == -1 || newTarget == 0) {
        return 5;
    }

#ifdef TAIUAIMD_COMPLETE_TU
    int difficulty = taiuaimd_world_difficulty(objectValue->owner->world);
#else
    int difficulty = ((RGE_Player*)obj->owner)->world->difficultyLevel();
#endif

    float los;
    if (rge_base_game->scenarioGame() == 1 && rge_base_game->singlePlayerGame() == 1 && difficulty >= 3) {
        float factor = (difficulty == 3) ? 0.75f : 0.5f;
#ifdef TAIUAIMD_COMPLETE_TU
        los = factor * objectValue->master_obj->los;
#else
        los = factor * obj->master_obj->los;
#endif
        if (los < 1.0f) {
            los = 1.0f;
        }
    } else {
#ifdef TAIUAIMD_COMPLETE_TU
        los = objectValue->master_obj->los * 2.0f;
#else
        los = obj->master_obj->los * 2.0f;
#endif
    }

#ifdef TAIUAIMD_COMPLETE_TU
    float dist = objectValue->distance_to_object(newTarget);
#else
    float dist = obj->distance_to_object(newTarget);
#endif
    if (dist > los) {
        return 5;
    }

    attackObject(targetId, 0);
    return 6;
}
