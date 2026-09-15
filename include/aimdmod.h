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

    MainDecisionAIModule(void* pW, int playerID, RGE_Player* plyr);
    MainDecisionAIModule(int playerID, RGE_Player* plyr, int infile);
    virtual ~MainDecisionAIModule();
    virtual void setLogHistory(int v);
    virtual int save(int outfile);
    virtual int addObject(RGE_Static_Object* obj);
    virtual int removeObject(int id);
    virtual int objectGroupThatCanPerformAction(int a);
    virtual int canPerformAction(int id, int t);

    int numberObjects();
    int numberObjectsWithAction(int aid);
    int numberObjectsWithGroup(int gid);
    int numberObjectsWithActionAndTarget(int action, int target);
    int numberObjectsWithTargetType(int tt);
    int numberObjectsWithActionAndTargetType(int action, int tt);
    RGE_Static_Object* object(int id);
    RGE_Static_Object* object(int gameID, int typeID, int groupID, int currentAction, int canPerformActionID,
                              int targetID, int targetType, int secondaryTargetType, int objectState,
                              int maxAttributeAmount);
    RGE_Static_Object* object(int gameID, int typeID, int groupID, int action1, int action2, int objectState);
    int numberBusyObjects();
    RGE_Static_Object* mostDamaged(int oGroup, int oType);
};

typedef char aimdmod_main_decision_size[
    (sizeof(MainDecisionAIModule) == 0x104) ? 1 : -1];

#endif
