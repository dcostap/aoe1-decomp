// target: VA 00407A20 set_target_obj
// first pass: direct object swap with world lookup and the two virtual notifications
// tried raw vtable casts first; the call sites picked up extra cleanup and the wrong branch offsets
// tried local ownership/object stubs; the object access shape is close, but the two virtual notifications still need a better slot-call basin

class RGE_Game_World;
class RGE_Unit_Object_Owner;
class RGE_Action_Object;
class RGE_Sprite;

class RGE_Static_Object {
public:
    void* vtable_ptr;
    long id;
    char gap_08[4];
    RGE_Unit_Object_Owner* owner;
};

class RGE_Game_World {
public:
    RGE_Static_Object* object(int index);
};

class RGE_Unit_Object_Owner {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
};

class RGE_Action_Object {
public:
    char gap_00[0xC];
    RGE_Unit_Object_Owner* owner;
};

typedef void (__thiscall *RGE_Action_C4)(RGE_Static_Object*, RGE_Action_Object*);
typedef void (__thiscall *RGE_Action_C0)(RGE_Static_Object*, RGE_Action_Object*, short, int);

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int vf04(RGE_Action_Object* param_1);
    virtual int vf08(int param_1, RGE_Action_Object* param_2);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(int param_1);
    virtual short vf18(void);
    virtual void vf1C(unsigned char param_1);
    virtual unsigned char vf20(void);
    virtual unsigned char vf24(void);
    virtual unsigned char vf28(void);
    virtual int vf2C(void);
    virtual int vf30(void*, float, float, float);
    virtual int vf34(void*, float, float, float);
    virtual unsigned char vf38(void*);
    virtual unsigned char vf3C(long, unsigned char);
    virtual void vf40(void*);
    virtual void vf44(void*, void*, void*);
    virtual void vf48(char*);
    virtual void* vf4C(void);
    virtual void* vf50(void);
    virtual void set_target_obj(void*);
    virtual void vf58(void*);
    virtual void set_state(unsigned char);

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
    void* task;
    void* sub_actions;
    RGE_Sprite* sprite;
    unsigned char subActionValue;
    char gap_3D[0x3];

    void set_target_obj(RGE_Static_Object* param_1);
};

void RGE_Action::set_target_obj(RGE_Static_Object* param_1) {
    RGE_Static_Object* previous;
    void** vtable;

    if (this->target_obj != 0 && this->target_obj != param_1) {
        previous = this->obj->owner->world->object(this->targetID);
        if (previous != 0) {
            vtable = *(void***)previous;
            ((RGE_Action_C4)vtable[49])(previous, this->obj);
        }
    }

    if (this->target_obj != param_1) {
        this->target_obj = param_1;
        if (param_1 != 0) {
            this->targetID = param_1->id;
            vtable = *(void***)param_1;
            ((RGE_Action_C0)vtable[48])(param_1, this->obj, this->action_type, 0);
            return;
        }

        this->targetID = -1;
    }
}
