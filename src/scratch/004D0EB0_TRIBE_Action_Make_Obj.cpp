class RGE_Action_Object;

class RGE_Action {
public:
    char _gap[0x40];
    RGE_Action(RGE_Action_Object* obj, int type);
};

class TRIBE_Action_Make_Obj : public RGE_Action {
public:
    short obj_id;
    float work_done;
    int unique_id;
    unsigned char pre_paid;

    TRIBE_Action_Make_Obj(RGE_Action_Object* obj, short obj_id, int unique_id, unsigned char pre_paid);
};

TRIBE_Action_Make_Obj::TRIBE_Action_Make_Obj(RGE_Action_Object* obj, short obj_id, int unique_id, unsigned char pre_paid)
    : RGE_Action(obj, 1)
{
    this->unique_id = unique_id;
    *(unsigned char*)((char*)this + 0x4C) = pre_paid;
    { short* poid = &this->obj_id; *poid = obj_id; }
    *(int*)this = 0x5751A8;
    *(short*)((char*)this + 4) = 0x66;
    this->work_done = 0.0f;
}
