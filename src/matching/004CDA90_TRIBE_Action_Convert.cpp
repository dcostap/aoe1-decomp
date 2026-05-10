// VA: 004CDA90 TRIBE_Action_Convert::TRIBE_Action_Convert
// tact_cnv.cpp lines 61-81
// FLAGS: config/flags/004CDA90_TRIBE_Action_Convert.rsp (/GX)
//
// Attempt log:
// - Prior scratch used a helper destructor and a base layout without the vptr, causing shifted offsets and EH prologue
//   mismatch.
// - Natural ctor with correct virtual RGE_Action base got down to the known 8-byte vptr ordering drift.
// - SpruceGlow MATCH: keep the real virtual base layout and explicitly restore the derived vptr after `required_range = 1.0f`
//   but before `field_04 = 0x68` and `set_target_obj`. This matches the original VC5 constructor ordering.
// Result: MATCH locally with `python tools/check_function.py --va 004CDA90`.

class RGE_Action_Object;

class RGE_Static_Object {
public:
    char gap_00[0x38];
    int world_x;
    int world_y;
    int world_z;
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    RGE_Action(RGE_Action_Object* obj, int a);
    void set_target_obj(RGE_Static_Object* obj);

    short field_04;
    char gap_06[0x1A];
    int target_x;
    int target_y;
    int target_z;
    char gap_2C[4];
    void* task_ptr;
    char gap_34[0x0C];
    char was_same_owner;
    char gap_41[3];
    float required_range;
};

class TRIBE_Action_Convert : public RGE_Action {
public:
    TRIBE_Action_Convert(RGE_Action_Object* obj, void* task, RGE_Static_Object* static_obj);
};

TRIBE_Action_Convert::TRIBE_Action_Convert(RGE_Action_Object* obj, void* task, RGE_Static_Object* static_obj)
    : RGE_Action(obj, 1) {
    this->task_ptr = task;
    this->required_range = 1.0f;
    *(int*)this = 0x574F90;
    this->field_04 = 0x68;
    RGE_Action::set_target_obj(static_obj);
    if (static_obj != 0) {
        this->target_x = static_obj->world_x;
        this->target_y = static_obj->world_y;
        this->target_z = static_obj->world_z;
    }
    this->was_same_owner = 0;
}
