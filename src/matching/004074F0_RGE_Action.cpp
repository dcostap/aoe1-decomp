class RGE_Action_List;
class RGE_Static_Object;

class RGE_Action {
public:
    void* vtable_ptr;
    short action_type;
    char gap_06[2];
    void* obj;
    unsigned char state;
    char gap_0D[3];
    RGE_Static_Object* target_obj;
    RGE_Static_Object* target_obj2;
    int targetID;
    int target2ID;
    float target_x;
    float target_y;
    float target_z;
    float timer;
    void* task;
    RGE_Action_List* sub_actions;
    void* sprite;
    unsigned char subActionValue;
    char gap_3D[3];

    void set_target_obj(RGE_Static_Object* target);
    void set_target_obj2(RGE_Static_Object* target);
    ~RGE_Action();
};

class RGE_Action_List {
public:
    ~RGE_Action_List();
};

RGE_Action::~RGE_Action() {
    RGE_Action_List* this_00;

    this->vtable_ptr = (void*)0x56E6D0;
    this->set_target_obj((RGE_Static_Object*)0);
    this->set_target_obj2((RGE_Static_Object*)0);
    this_00 = this->sub_actions;
    if (this_00 != 0) {
        delete this_00;
        this->sub_actions = 0;
    }
}
