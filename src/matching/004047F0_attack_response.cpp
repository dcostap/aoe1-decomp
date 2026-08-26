#ifndef ACT_LIST_SHARED_CONTEXT
class RGE_Action_Object;
class RGE_Action_List;
class RGE_Static_Object;

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int setup(RGE_Action_Object* object);
    virtual int setup(int value, RGE_Action_Object* object);
    virtual RGE_Action_List* create_action_list(RGE_Action_Object* object);
    virtual void rehook(void);
    virtual void save(int file);
    virtual short type(void);
    virtual void first_in_stack(unsigned char value);
    virtual unsigned char inside_obj_update(void);
    virtual unsigned char idle_update(void);
    virtual unsigned char update(void);
    virtual int stop(void);
    virtual int move_to(RGE_Static_Object*, float, float, float);
    virtual int work(RGE_Static_Object*, float, float, float);
    virtual unsigned char attack_response(RGE_Static_Object*);
};

class RGE_Action_Node {
public:
    RGE_Action* action;
};

class RGE_Action_List {
public:
    char gap_00[8];
    RGE_Action_Node* list;

    int attack_response(RGE_Static_Object* obj);
};
#endif

int RGE_Action_List::attack_response(RGE_Static_Object* obj) {
    if (this->list != 0) {
        return this->list->action->attack_response(obj) & 0xff;
    }
    return 0;
}
