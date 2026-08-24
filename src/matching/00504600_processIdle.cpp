// TribeLionUnitAIModule::processIdle (00504600)
// taiuaimd.cpp:441-515, 251 bytes
// __thiscall: ecx=this, 1 stack param, ret 4

#ifndef TAIUAIMD_COMPLETE_TU
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

class RGE_Master_Obj {
public:
    char gap_00[0x28];
    float los;
};

class RGE_Static_Object {
public:
    void* vtable;
    int id_num;
    RGE_Master_Obj* master;
    void* owner;
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

    // Dummy virtuals to pad vtable to match offsets
    virtual void pad00() = 0;
    virtual void pad01() = 0;
    virtual void pad02() = 0;
    virtual void pad03() = 0;
    virtual void pad04() = 0;
    virtual void pad05() = 0;
    virtual void pad06() = 0;
    virtual void pad07() = 0;
    virtual void pad08() = 0;
    virtual void pad09() = 0;
    virtual void pad10() = 0;
    virtual void pad11() = 0;
    virtual void pad12() = 0;
    virtual void pad13() = 0;
    virtual void pad14() = 0;
    virtual void pad15() = 0;
    virtual int findEnemy(int, int, int, int, int) = 0;  // vt[16] = +0x40
    virtual void pad17() = 0;
    virtual void pad18() = 0;
    virtual void pad19() = 0;
    virtual void pad20() = 0;
    virtual void pad21() = 0;
    virtual void pad22() = 0;
    virtual void setTarget(int, int) = 0;               // vt[23] = +0x5C
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

    int targetId = findEnemy(-1, -1, -1, -1, 0);
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
        los = factor * obj->master->los;
#endif
        if (los < 1.0f) {
            los = 1.0f;
        }
    } else {
#ifdef TAIUAIMD_COMPLETE_TU
        los = objectValue->master_obj->los * 2.0f;
#else
        los = obj->master->los * 2.0f;
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

    setTarget(targetId, 0);
    return 6;
}
