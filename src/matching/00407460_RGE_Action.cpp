class RGE_Action_Object;

class RGE_Action {
public:
    virtual void vf00(void);
    char gap_04[0x14];
    int targetID;
    int target2ID;

    RGE_Action(int mode, RGE_Action_Object* object, int doSetup);
    int setup(int mode, RGE_Action_Object* object);
};

RGE_Action::RGE_Action(int mode, RGE_Action_Object* object, int doSetup) {
    this->targetID = -1;
    this->target2ID = -1;
    if (doSetup != 0) {
        this->setup(mode, object);
    }
}
