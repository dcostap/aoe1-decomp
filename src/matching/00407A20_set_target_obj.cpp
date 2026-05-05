// target: VA 00407A20 set_target_obj
// first pass had raw __thiscall typedefs, which VC5 rejects in this context.
// current: typed virtual surface for slots +0xC0/+0xC4.

class RGE_Game_World;
class RGE_Unit_Object_Owner;
class RGE_Action_Object;
class RGE_Sprite;
class RGE_Static_Object;

class RGE_Static_Object_Virtuals {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
    virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C();
    virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3C();
    virtual void vf40(); virtual void vf44(); virtual void vf48(); virtual void vf4C();
    virtual void vf50(); virtual void vf54(); virtual void vf58(); virtual void vf5C();
    virtual void vf60(); virtual void vf64(); virtual void vf68(); virtual void vf6C();
    virtual void vf70(); virtual void vf74(); virtual void vf78(); virtual void vf7C();
    virtual void vf80(); virtual void vf84(); virtual void vf88(); virtual void vf8C();
    virtual void vf90(); virtual void vf94(); virtual void vf98(); virtual void vf9C();
    virtual void vfA0(); virtual void vfA4(); virtual void vfA8(); virtual void vfAC();
    virtual void vfB0(); virtual void vfB4(); virtual void vfB8(); virtual void vfBC();
    virtual void notify_target_set(RGE_Action_Object*, short, int); // +0xC0
    virtual void notify_target_clear(RGE_Action_Object*);           // +0xC4
};

class RGE_Static_Object : public RGE_Static_Object_Virtuals {
public:
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
    virtual void set_target_obj(RGE_Static_Object*);
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
};

void RGE_Action::set_target_obj(RGE_Static_Object* param_1) {
    if (this->target_obj != 0 && this->target_obj != param_1) {
        RGE_Static_Object* previous = this->obj->owner->world->object(this->targetID);
        if (previous != 0) {
            previous->notify_target_clear(this->obj);
        }
    }

    if (this->target_obj != param_1) {
        this->target_obj = param_1;
        if (param_1 != 0) {
            this->targetID = param_1->id;
            param_1->notify_target_set(this->obj, this->action_type, 0);
            return;
        }
        this->targetID = -1;
    }
}
