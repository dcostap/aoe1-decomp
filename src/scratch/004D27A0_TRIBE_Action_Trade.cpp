// VA: 004D27A0 TRIBE_Action_Trade::TRIBE_Action_Trade (72B)
// PDB source: tact_trd.cpp lines 77-91
// tried the base ctor plus direct member writes, raw int bit-casts, and offset-faithful fields/gaps
// best result keeps the ctor call and most final stores right, but VC5 still chooses a different post-call load/store order: it loads x/y/task from different stack slots and emits the 20/24/30/28 field stores in offset-grouped order instead of the original `24, 30, load z, const, vftable, 40, 44, type, 20, 28` sequence

class RGE_Action_Object;
class RGE_Task;

class RGE_Action {
public:
    void* vftable;
    unsigned short action_type;
    char gap_06[0x1A];

    RGE_Action(RGE_Action_Object* obj, int value);
};

class TRIBE_Action_Trade : public RGE_Action {
public:
    float field_20;
    float field_24;
    float field_28;
    char gap_2C[0x04];
    RGE_Task* task;
    char gap_34[0x0C];
    float pick_up_x;
    float pick_up_y;

    TRIBE_Action_Trade(RGE_Action_Object* obj, RGE_Task* task, float x, float y, float z);
};

TRIBE_Action_Trade::TRIBE_Action_Trade(RGE_Action_Object* obj, RGE_Task* task, float x, float y, float z)
    : RGE_Action(obj, 1) {
    *(int*)&this->field_24 = *(int*)&y;
    this->task = task;
    *(int*)&this->field_20 = *(int*)&x;
    *(int*)&this->field_28 = *(int*)&z;
    this->vftable = (void*)0x005752E8;
    this->pick_up_x = -1.0f;
    this->pick_up_y = -1.0f;
    this->action_type = 0x6F;
}
