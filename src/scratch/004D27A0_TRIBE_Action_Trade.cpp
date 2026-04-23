// tried the base RGE_Action ctor plus direct member writes; mismatch stayed in the first post-call store block
// tried raw int bit-casts and a 0x2C gap to force the task pointer at +30; offsets matched, but VC5 still reordered 20/30 vs 40/44
// remaining gap is statement/order codegen drift around the trade-specific field stores, not the ctor call itself

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
    int x_bits = *(int*)&x;
    int y_bits = *(int*)&y;
    int z_bits = *(int*)&z;

    *(int*)&this->field_24 = y_bits;
    this->task = task;
    this->vftable = (void*)0x005752E8;
    *(int*)&this->pick_up_x = 0xBF800000;
    *(int*)&this->pick_up_y = 0xBF800000;
    this->action_type = 0x6F;
    *(int*)&this->field_20 = x_bits;
    *(int*)&this->field_28 = z_bits;
}
