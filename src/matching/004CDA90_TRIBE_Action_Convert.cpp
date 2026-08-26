// VA: 004CDA90 TRIBE_Action_Convert::TRIBE_Action_Convert
// tact_cnv.cpp lines 61-81
// FLAGS: config/flags/004CDA90_TRIBE_Action_Convert.rsp (/GX)
//
// Attempt log:
// 1: Policy recovery kept the typed base and removed the former raw vtable store.
// 2: Canonical derived ownership plus a required_range initializer recovered the vptr order.
//    The authentic TU now matches without inline assembly or a raw vtable view.

#ifndef TACT_CNV_SHARED_CONTEXT
class RGE_Action_Object;
class RGE_Task;

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
};

class TRIBE_Action_Convert : public RGE_Action {
public:
    char was_same_owner;
    char gap_41[3];
    float required_range;

    TRIBE_Action_Convert(RGE_Action_Object* obj, RGE_Task* task, RGE_Static_Object* static_obj);
};

#endif

TRIBE_Action_Convert::TRIBE_Action_Convert(RGE_Action_Object* obj, RGE_Task* task, RGE_Static_Object* static_obj)
    : RGE_Action(obj, 1), required_range(1.0f) {
    this->task_ptr = task;
    this->field_04 = 0x68;
    RGE_Action::set_target_obj(static_obj);
    if (static_obj != 0) {
        this->target_x = static_obj->world_x;
        this->target_y = static_obj->world_y;
        this->target_z = static_obj->world_z;
    }
    this->was_same_owner = 0;
}
