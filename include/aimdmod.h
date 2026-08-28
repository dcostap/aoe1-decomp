#ifndef AOE1_AIMDMOD_H
#define AOE1_AIMDMOD_H

#include "aimodule.h"
#include "utmarray.h"

class RGE_Player;
class RGE_Static_Object;

class MainDecisionAIModule : public AIModule {
public:
    RGE_Player* player;
    ManagedArray<int> objects;

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
    RGE_Static_Object* object(int, int, int, int, int, int, int, int, int,
                              int);
    RGE_Static_Object* object(int, int, int, int, int, int);
    int numberBusyObjects();
    RGE_Static_Object* mostDamaged(int, int);
};

typedef char aimdmod_main_decision_size[
    (sizeof(MainDecisionAIModule) == 0x104) ? 1 : -1];

#endif
