// VA: 004D0EB0 TRIBE_Action_Make_Obj::TRIBE_Action_Make_Obj()
// Source: tact_mob.cpp lines 48-54
// tried direct stores, explicit temps, and the minimal RGE_Action base with correct +0x40/+0x44/+0x48/+0x4C layout
// best result matches the base-call prologue and all final stores/offsets, but VC5 still insists on loading/storing obj_id first (ax/[+40]) before pre_paid and unique_id, instead of the original al/ecx/dx load order and pre_paid/unique_id-first schedule

class RGE_Action_Object;

class RGE_Action {
public:
    char _gap[0x40];
    RGE_Action(RGE_Action_Object* obj, int type);
};

class TRIBE_Action_Make_Obj : public RGE_Action {
public:
    short obj_id;      // +0x40
    int work_done;     // +0x44
    int unique_id;     // +0x48
    unsigned char pre_paid; // +0x4C

    TRIBE_Action_Make_Obj(RGE_Action_Object* obj, short obj_id, int unique_id, unsigned char pre_paid);
};

TRIBE_Action_Make_Obj::TRIBE_Action_Make_Obj(RGE_Action_Object* obj, short obj_id, int unique_id, unsigned char pre_paid)
    : RGE_Action(obj, 1)
{
    unsigned char paid;
    int uid;
    short oid;

    paid = pre_paid;
    uid = unique_id;
    oid = obj_id;
    this->pre_paid = paid;
    this->unique_id = uid;
    *(int*)this = 0x5751A8;
    *(short*)((int)this + 4) = 0x66;
    this->obj_id = oid;
    this->work_done = 0;
}
