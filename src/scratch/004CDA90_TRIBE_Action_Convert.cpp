// 004CDA90 TRIBE_Action_Convert::TRIBE_Action_Convert
// Size: 135 bytes (8 bytes diff remaining)
// FLAGS: /GX (EH frame)
//
// tried: member initializer (8B diff), body-style base ctor (wrong codegen),
// guard struct with dtor (no EH frame), volatile, reordered body statements
// Remaining: VC5 places vtable write before first body statement with member
// initializer, original places it after required_range=1.0f. 8 bytes benign
// ordering diff within vtable relocation area.

class RGE_Action_Object;
class RGE_Static_Object;

struct EH_Helper {
    ~EH_Helper() {}
};

class RGE_Action {
public:
    RGE_Action(RGE_Action_Object* obj, int a);
    void set_target_obj(RGE_Static_Object* obj);
    short field_04;           // +0x04 (word)
    char gap_06[0x1A];
    int target_x;             // +0x20
    int target_y;             // +0x24
    int target_z;             // +0x28
    char gap_2C[4];
    void* task_ptr;           // +0x30
    char gap_34[0x0C];
    char was_same_owner;      // +0x40
    char gap_41[3];
    float required_range;     // +0x44
};

class TRIBE_Action_Convert : public RGE_Action {
public:
    TRIBE_Action_Convert(RGE_Action_Object* obj, void* task, RGE_Static_Object* static_obj);
};

TRIBE_Action_Convert::TRIBE_Action_Convert(RGE_Action_Object* obj, void* task, RGE_Static_Object* static_obj) : RGE_Action(obj, 1) {
    EH_Helper helper;
    this->task_ptr = task;
    this->required_range = 1.0f;
    this->field_04 = 0x68;
    RGE_Action::set_target_obj(static_obj);
    if (static_obj != 0) {
        this->target_x = *(int*)((char*)static_obj + 0x38);
        this->target_y = *(int*)((char*)static_obj + 0x3C);
        this->target_z = *(int*)((char*)static_obj + 0x40);
    }
    this->was_same_owner = 0;
}
