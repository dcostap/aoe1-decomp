#ifndef AOE1_AIMDMOD_H
#define AOE1_AIMDMOD_H

#include <new.h>
#include <stdlib.h>
#include "aimodule.h"
#include "m_s_obj.h"
#include "player.h"
#include "stat_obj.h"
#include "utmarray.h"
#include "world.h"

typedef unsigned char uchar;

class RGE_Action_Object;
class RGE_Sprite;
class RGE_Color_Table;
class RGE_Armor_Weapon_Info;
class RGE_Object_List;
class RGE_Active_Sprite_List;
class RGE_Active_Sprite;
class LOSTBL;

extern "C" void __cdecl rge_read(int, void*, int);
void rge_write(int, const void*, int);

class UnitAIModule {
public:
    int currentAction();
    int currentTarget();
    int currentTargetType();
};

class MainDecisionAIModule : public AIModule {
public:
    union {
        RGE_Player* player;
        RGE_Player* game;
    };                                             // +0xF0
    ManagedArray<int> objects;                       // +0xF4

    MainDecisionAIModule(void*, int, RGE_Player*);
    MainDecisionAIModule(int, RGE_Player*, int);
    virtual ~MainDecisionAIModule();
    virtual void setLogHistory(int);
    virtual int save(int);
    virtual int addObject(RGE_Static_Object*);
    virtual int removeObject(int);
    virtual int objectGroupThatCanPerformAction(int);
    virtual int canPerformAction(int, int);

    int numberObjects();
    int numberObjectsWithAction(int);
    int numberObjectsWithGroup(int);
    int numberObjectsWithActionAndTarget(int, int);
    int numberObjectsWithTargetType(int);
    int numberObjectsWithActionAndTargetType(int, int);
    RGE_Static_Object* object(int);
    RGE_Static_Object* object(int, int, int, int, int, int, int, int, int, int);
    RGE_Static_Object* object(int, int, int, int, int, int);
    int numberBusyObjects();
    RGE_Static_Object* mostDamaged(int, int);
};

#endif
