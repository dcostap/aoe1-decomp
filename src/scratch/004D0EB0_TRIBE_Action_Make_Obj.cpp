class RGE_Action_Object;

// tried the direct constructor shape with explicit field writes; mismatch stayed in the parameter reload/order basin
// tried local temps for the three constructor args; VC5 kept the same load order around the post-call writes

class RGE_Action {
public:
    void* vtable_ptr;
    char gap_04[0x3C];

    RGE_Action(RGE_Action_Object* object, int do_setup);
};

class TRIBE_Action_Make_Obj : public RGE_Action {
public:
    short obj_id;
    float work_done;
    int unique_id;
    unsigned char pre_paid;
    char gap_4D[0x3];

    TRIBE_Action_Make_Obj(RGE_Action_Object* object, short obj_id, int unique_id, unsigned char pre_paid);
};

TRIBE_Action_Make_Obj::TRIBE_Action_Make_Obj(RGE_Action_Object* object, short obj_id, int unique_id, unsigned char pre_paid)
    : RGE_Action(object, 1) {
    unsigned char pre_paid_value = pre_paid;
    int unique_id_value = unique_id;
    short obj_id_value = obj_id;

    this->pre_paid = pre_paid_value;
    this->unique_id = unique_id_value;
    this->vtable_ptr = (void*)0x005751A8;
    *(short*)((char*)this + 4) = 0x66;
    this->obj_id = obj_id_value;
    this->work_done = 0.0f;
}
