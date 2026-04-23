// tried the straight constructor body with base init-list; first mismatch moved to the early prolog / constructor-call basin
// tried adding a virtual destructor to force a vtable store; that changed the layout too much and the mismatch moved deeper into the prolog
// leaving in scratch because the remaining gap is constructor-codegen shape, not a behavior mismatch
class RGE_Action_Object;
class RGE_Task;

class RGE_Action {
public:
    void* vtable_ptr;
    short action_type;
    char gap_06[0x2];
    RGE_Action_Object* obj;
    unsigned char state;
    char gap_0D[0x3];
    void* target_obj;
    void* target_obj2;
    int targetID;
    int target2ID;
    float target_x;
    float target_y;
    float target_z;
    float timer;
    RGE_Task* task;
    void* sub_actions;
    void* sprite;
    unsigned char subActionValue;

    RGE_Action(RGE_Action_Object* object, int do_setup);
};

class TRIBE_Action_Convert : public RGE_Action {
public:
    unsigned char was_same_owner;
    char gap_41[0x3];
    float requiredRange;

    virtual ~TRIBE_Action_Convert();
    TRIBE_Action_Convert(RGE_Action_Object* object, RGE_Task* task, float x, float y, float z);
};

TRIBE_Action_Convert::TRIBE_Action_Convert(RGE_Action_Object* object, RGE_Task* task, float x, float y, float z)
    : RGE_Action(object, 1) {
    this->task = task;
    this->target_y = y;
    this->requiredRange = 1.0f;
    this->action_type = 0x68;
    this->target_x = x;
    this->target_z = z;
    this->was_same_owner = 0;
}
