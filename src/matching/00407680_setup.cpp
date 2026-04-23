class RGE_Action_List;
class RGE_Action_Object;
class RGE_Sprite;
class RGE_Static_Object;
class RGE_Task;

class RGE_Action {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual RGE_Action_List* vf0C(RGE_Action_Object* action_object);

    short action_type;
    char gap_06[0x2];
    RGE_Action_Object* obj;
    unsigned char state;
    char gap_0D[0x3];
    RGE_Static_Object* target_obj;
    RGE_Static_Object* target_obj2;
    int targetID;
    int target2ID;
    float target_x;
    float target_y;
    float target_z;
    float timer;
    RGE_Task* task;
    RGE_Action_List* sub_actions;
    RGE_Sprite* sprite;
    unsigned char subActionValue;

    int setup(RGE_Action_Object* action_object);
};

int RGE_Action::setup(RGE_Action_Object* action_object) {
    this->action_type = 0;
    this->obj = action_object;
    this->state = 0;
    this->target_obj = 0;
    this->target_obj2 = 0;
    this->target_x = 0.0f;
    this->target_y = 0.0f;
    this->target_z = 0.0f;
    this->timer = 0.0f;
    this->task = 0;
    this->sub_actions = this->vf0C(action_object);
    this->sprite = 0;
    this->subActionValue = 0;
    return 1;
}
