#ifndef AOE1_TAIMDMD_CONTEXT_H
class RGE_Static_Object;
class MainDecisionAIModule {
public:
    virtual ~MainDecisionAIModule();
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
    virtual int processMessage(void*);
    virtual int update(int);
    virtual void setCallbackMessage(void*);
    virtual int filterOutMessage(void*);
    virtual int save(int);
    virtual int addObject(RGE_Static_Object*);
    virtual int removeObject(int);
    virtual int objectGroupThatCanPerformAction(int);
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    RGE_Static_Object* object(int);
    virtual int canPerformAction(int param_1, int param_2);
};

class RGE_Master_Static_Object {
public:
    char gap_00[0x14];
    short object_group;
};

class RGE_Static_Object {
public:
    char gap_00[0x8];
    RGE_Master_Static_Object* master_obj;
};
#endif

int TribeMainDecisionAIModule::canPerformAction(int param_1, int param_2) {
    RGE_Static_Object* object = this->object(param_1);
    if (object != 0) {
        if (object->master_obj->object_group == this->objectGroupThatCanPerformAction(param_2)) {
            return 1;
        }
    }
    return 0;
}
