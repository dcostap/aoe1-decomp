class RGE_Master_Action_Object;

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int setup(RGE_Master_Action_Object* param_1);
    virtual int setup(int param_1, RGE_Master_Action_Object* param_2);
    virtual void* create_action_list(RGE_Master_Action_Object* param_1);
    virtual void rehook();
    virtual void save(int param_1);
    virtual short type();
    virtual void first_in_stack(unsigned char param_1);
    virtual unsigned char inside_obj_update();
    virtual unsigned char idle_update();
    virtual unsigned char update();
    virtual int stop();
    virtual int move_to(void* param_1, float param_2, float param_3, float param_4);
    virtual int work(void* param_1, float param_2, float param_3, float param_4);
    virtual unsigned char attack_response(void* param_1);
    virtual unsigned char relation_response(long param_1, unsigned char param_2);
    virtual void copy_obj(RGE_Master_Action_Object* param_1);
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

    void copy_obj(RGE_Master_Action_Object* param_1);
};

void RGE_Action_List::copy_obj(RGE_Master_Action_Object* param_1) {
    RGE_Action_Node* node = this->list;
    while (node != 0) {
        node->action->copy_obj(param_1);
        node = node->next;
    }
}
