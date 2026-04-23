class RGE_Action_Object;

class RGE_Action {
public:
    virtual ~RGE_Action();
    char gap_04[0x14];
    int targetID;
    int target2ID;

    RGE_Action(RGE_Action_Object* object, int do_setup);
    int setup(RGE_Action_Object* object);
};

RGE_Action::RGE_Action(RGE_Action_Object* object, int do_setup) {
    this->targetID = -1;
    this->target2ID = -1;
    if (do_setup) {
        setup(object);
    }
}
