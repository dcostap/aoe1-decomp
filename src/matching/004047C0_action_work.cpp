class RGE_Static_Object;
class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int setup(RGE_Static_Object* param_1);
    virtual int setup(int param_1, RGE_Static_Object* param_2);
    virtual void* create_action_list(RGE_Static_Object* param_1);
    virtual void rehook();
    virtual void save(int param_1);
    virtual short type();
    virtual void first_in_stack(unsigned char param_1);
    virtual unsigned char inside_obj_update();
    virtual unsigned char idle_update();
    virtual unsigned char update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual int work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
};

class RGE_Action_Node {
public:
    RGE_Action* action;
    RGE_Action_Node* next;
};

class RGE_Action_List {
public:
    char gap_00[0x8];
    RGE_Action_Node* list;

    int action_work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
};

int RGE_Action_List::action_work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    if (this->list != 0) {
        return this->list->action->work(param_1, param_2, param_3, param_4);
    }
    return 0;
}
