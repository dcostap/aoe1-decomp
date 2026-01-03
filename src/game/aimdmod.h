#pragma once
#include "../common.h"
#include "aimodule.h"
#include "player.h"
#include "utmarray.h"

class MainDecisionAIModule : public AIModule {
public:
    RGE_Player* player;                      // 0xF0
    ManagedArray_int objects;               // 0xF4

    MainDecisionAIModule(void* param_1, int param_2, RGE_Player* param_3);
    MainDecisionAIModule(int param_1, RGE_Player* param_2, int param_3);
    virtual ~MainDecisionAIModule();
    virtual void setLogHistory(int param_1);
    virtual int save(int param_1);
    virtual int addObject(RGE_Static_Object* param_1);
    virtual int removeObject(int param_1);
    virtual int numberObjects();
    virtual int numberObjectsWithAction(int param_1);
    virtual int numberObjectsWithGroup(int param_1);
    virtual int numberObjectsWithActionAndTarget(int param_1, int param_2);
    virtual int numberObjectsWithTargetType(int param_1);
    virtual int numberObjectsWithActionAndTargetType(int param_1, int param_2);
    virtual RGE_Static_Object* object(int param_1);
    virtual RGE_Static_Object* object(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7, int param_8, int param_9, int param_10);
    virtual RGE_Static_Object* object(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6);
    virtual int objectGroupThatCanPerformAction(int param_1);
    virtual int canPerformAction(int param_1, int param_2);
    virtual int numberBusyObjects();
    virtual RGE_Static_Object* mostDamaged(int param_1, int param_2);
};

static_assert(sizeof(MainDecisionAIModule) == 0x104, "MainDecisionAIModule Size Mismatch");
static_assert(offsetof(MainDecisionAIModule, objects) == 0xF4, "MainDecisionAIModule Offset Mismatch");

