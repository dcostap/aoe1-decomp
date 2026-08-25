// VA: 00430A90 RGE_Combat_Object::attack(float,float,float,int)
// PDB source: com_obj.cpp lines 827-869
// attempt 1: natural new RGE_Action_Attack with repeated current-action checks and EH new frame.
// attempt 2: action type virtual lives at +0x18 and attack ctor wants master short +0x12A, not +0x13E.
// attempt 3: object add_action virtual is at vtable +0x208, not +0x204.

#ifndef RGE_COM_OBJ_SHARED_CONTEXT
class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int setup(void*);
    virtual int setup(int, void*);
    virtual void* create_action_list(void*);
    virtual void rehook();
    virtual void save(int);
    virtual short type();
    float targetX();
};

class RGE_Action_List {
public:
    unsigned char have_action();
    RGE_Action* get_action();
    void delete_list();
};

class RGE_Master_Combat_Object {
public:
    char gap_000[0x114];
    float field_114;
    char gap_118[0x0C];
    short field_124;
    char gap_126[4];
    short field_12A;
    char gap_12C[0x0C];
    float field_138;
};

class RGE_Action_Attack {
public:
    char gap_00[0x5C];
    RGE_Action_Attack(void* obj, float x, float y, float z, void* a, void* b, void* c, float f1, float f2, short s1, short s2);
};

class RGE_Combat_Object {
public:
    virtual ~RGE_Combat_Object();
    void add_action(RGE_Action_Attack* action);

    char gap_004[4];
    RGE_Master_Combat_Object* master; // +0x08
    char gap_00C[0x178];
    RGE_Action_List* action_list;     // +0x184

    virtual int attack(float x, float y, float z, int force);
};
#endif

int RGE_Combat_Object::attack(float x, float y, float z, int force)
{
    if (force == 0) {
        if (this->action_list->have_action() == 1) {
            if (this->action_list->get_action()->targetX() == x) {
                if (this->action_list->get_action()->targetX() == y) {
                    if (this->action_list->get_action()->targetX() == z) {
                        if (this->action_list->get_action()->type() == 9) {
                            return 1;
                        }
                        if (this->action_list->get_action()->type() == 7) {
                            return 1;
                        }
                    }
                }
            }
        }
    }

    RGE_Action_Attack* action = new RGE_Action_Attack(this, x, y, z, 0, 0, 0,
        this->master->field_114, this->master->field_138, this->master->field_124, this->master->field_12A);
    if (action == 0) {
        return 0;
    }
    this->action_list->delete_list();
    this->add_action(action);
    return 1;
}
