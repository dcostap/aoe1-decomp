#pragma once
#include "common.h"

class MainDecisionAIModule : public AIModule {
public:
    RGE_Player* player;                      // 0xF0
    ManagedArray<int> objects;               // 0xF4

    virtual void setLogHistory(int param_1);                // vt0[2]+0x8=0x40D090
    virtual int save(int param_1);                          // vt0[15]+0x3C=0x40D0A0
    virtual int addObject(RGE_Static_Object* param_1);      // vt0[16]+0x40=0x40D180
    virtual int removeObject(int param_1);                  // vt0[17]+0x44=0x40D250
    virtual int objectGroupThatCanPerformAction(int param_1); // vt0[18]+0x48=0x40DB20
    virtual int canPerformAction(int param_1, int param_2); // vt0[19]+0x4C=0x40DB40
    MainDecisionAIModule(void* param_1, int param_2, RGE_Player* param_3);
    MainDecisionAIModule(int param_1, RGE_Player* param_2, int param_3);
    ~MainDecisionAIModule();
    int numberObjects();
    int numberObjectsWithAction(int param_1);
    int numberObjectsWithGroup(int param_1);
    int numberObjectsWithActionAndTarget(int param_1, int param_2);
    int numberObjectsWithTargetType(int param_1);
    int numberObjectsWithActionAndTargetType(int param_1, int param_2);
    RGE_Static_Object* object(int param_1);
    RGE_Static_Object* object(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7, int param_8, int param_9, int param_10);
    RGE_Static_Object* object(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6);
    int numberBusyObjects();
    RGE_Static_Object* mostDamaged(int param_1, int param_2);
};

static_assert(sizeof(MainDecisionAIModule) == 0x104, "MainDecisionAIModule Size Mismatch");

