// TRIBE_Player::removeObject
// VA: 005150E0
// tplayer.cpp:2003-2013
// MATCH: 0.0000% diff, 0 relocations masked
// STATUS: scratch. Standalone bytes match; the canonical full tplayer wrapper does not.

#ifndef AOE1_TPLAYER_TU_SHARED_CONTEXT
struct RGE_Object_Node;
class RGE_Static_Object {
public:
    char gap_00[4];
    int id;                // +0x04
    void* master_obj;      // +0x08
};

class RGE_Player {
public:
    virtual void removeObject(RGE_Static_Object* obj, int param_2, int param_3, RGE_Object_Node* param_4);
};

class AIModuleMessage;
class AIModule {
public:
    virtual ~AIModule();
    virtual int loggingHistory();
    virtual void setLogHistory(int);
    virtual void toggleLogHistory();
    virtual void setHistoryFilename(char*);
    virtual int loggingCommonHistory();
    virtual void setLogCommonHistory(int);
    virtual void toggleLogCommonHistory();
    virtual int loadState(char*);
    virtual int saveState(char*);
    virtual int gleanState(int);
    virtual int processMessage(AIModuleMessage*);
    virtual int update(int);
    virtual void setCallbackMessage(AIModuleMessage*);
    virtual int filterOutMessage(AIModuleMessage*);
};

class MainDecisionAIModule : public AIModule {
public:
    virtual ~MainDecisionAIModule();
    virtual void setLogHistory(int);
    virtual int save(int);
    virtual int addObject(RGE_Static_Object*);
    virtual int removeObject(int);
    virtual int objectGroupThatCanPerformAction(int);
    virtual int canPerformAction(int, int);
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    virtual ~TribeMainDecisionAIModule();
    virtual void setLogHistory(int);
    virtual int update(int);
    virtual int save(int);
    virtual int addObject(RGE_Static_Object*);
    virtual int removeObject(int);
};

class TRIBE_Player : public RGE_Player {
public:
    char gap_00[0x234];
    TribeMainDecisionAIModule* playerAI;    // +0x238

    virtual void removeObject(RGE_Static_Object* obj, int param_2, int param_3, RGE_Object_Node* param_4);
};
#endif

void TRIBE_Player::removeObject(RGE_Static_Object* obj, int param_2, int param_3, RGE_Object_Node* param_4) {
    RGE_Player::removeObject(obj, param_2, param_3, param_4);

    if (this->playerAI) {
        short grp = *(short*)((char*)obj->master_obj + 0x14);
        if (grp != 0x0B && obj->id >= 0) {
            this->playerAI->removeObject(obj->id);
        }
    }
}
