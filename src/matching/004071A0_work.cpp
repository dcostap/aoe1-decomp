// RGE_Action_Transport::work
// VA: 004071A0
// PDB: act_tran.cpp:346-386
//
// Baseline reconstruction: the action owns an RGE_Action_Object at +08 and
// inherits the transport fields from RGE_Action.  The object calls below are
// the period member-function surface; the executable's byte return/mask and
// x87 comparison behavior are retained rather than expressed as raw helpers.
// Attempt log:
// - Baseline typed reconstruction: exact size/frame/call set, 4 bytes differed
//   in the successful target-write block.
// - Swapped source assignment order to target_x, target_y, target_z; VC5 then
//   emitted the original y/x store order and the function matched exactly.

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_04[0x3C];
    float world_z;

    unsigned char lookupZone(int x, int y);
    float distance_to_position(float x, float y, float z);
    int withinRangeOfZone(unsigned char zone, float range);
};

class RGE_Action_Object : public RGE_Static_Object {
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int setup(RGE_Action_Object* object);
    virtual int setup(int value, RGE_Action_Object* object);
    virtual void* create_action_list(RGE_Action_Object* object);
    virtual void rehook();
    virtual void save(int file);
    virtual short type();
    virtual void first_in_stack(unsigned char value);
    virtual unsigned char inside_obj_update();
    virtual unsigned char idle_update();
    virtual unsigned char update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object* object, float x, float y, float z);
    virtual int work(RGE_Static_Object* object, float x, float y, float z);
    virtual unsigned char attack_response(RGE_Static_Object* object);
    virtual unsigned char relation_response(long value, unsigned char relation);
    virtual void copy_obj(void* object);
    virtual void copy_obj_sprites(void* object, void* task, void* other_task);
    virtual void get_state_name(char* name);
    virtual RGE_Static_Object* get_target_obj();
    virtual RGE_Static_Object* get_target_obj2();
    virtual void set_target_obj(RGE_Static_Object* object);
    virtual void set_target_obj2(RGE_Static_Object* object);
    virtual void set_state(unsigned char state);

    short action_type;
    unsigned char gap_06[2];
    RGE_Action_Object* obj;
    unsigned char state;
    unsigned char gap_0D[3];
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
    void* sprite;
    unsigned char subActionValue;
    unsigned char gap_3D[3];
};

class RGE_Action_Transport : public RGE_Action {
public:
    int work(RGE_Static_Object* object, float x, float y, float z);
};

int RGE_Action_Transport::work(RGE_Static_Object* object, float x, float y, float z)
{
    this->target2ID = 1;

    int zone = (int)this->obj->lookupZone((int)x, (int)y);
    float distance = this->obj->distance_to_position(x, y, this->obj->world_z);

    if (zone != -1) {
        if (this->obj->withinRangeOfZone((unsigned char)zone, 2.0f) == 1 &&
            distance <= 2.0f) {
            this->target_x = x;
            this->target_y = y;
            this->target_z = z;
            this->set_state(6);
            return 1;
        }
    }

    if (x >= 0.0 && y >= 0.0) {
        this->target_x = x;
        this->target_y = y;
        this->target_z = z;
        if (object != this->obj) {
            this->set_state(0x0B);
            return 1;
        }
        this->set_state(4);
    }
    return 1;
}
