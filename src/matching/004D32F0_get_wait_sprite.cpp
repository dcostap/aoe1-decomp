#ifndef TACT_TRD_SHARED_CONTEXT
struct RGE_Sprite;
struct SomeObj {
    char pad[0x08]; int* field_08;
    char pad2[0x38]; float field_44;
    char pad3[0x04]; short field_4C;
};
struct SubObj {
    char pad[0x14]; short field_14;
    char pad2[0x28]; RGE_Sprite* field_40;
};
class TRIBE_Action_Trade {
public:
    RGE_Sprite* get_wait_sprite(void);
    char pad_00[0x08]; SomeObj* field_08;
    char pad_0C[0x24]; SubObj* field_30;
};
#endif
RGE_Sprite* TRIBE_Action_Trade::get_wait_sprite(void) {
#ifdef TACT_TRD_SHARED_CONTEXT
    RGE_Task* task = this->task;
    short task_facet = task->attribute_type;
    if (task_facet != (short)0xFFFF && task_facet == this->obj->facet
        && this->obj->attribute_amount_held > 0 && task->carry_sprite != 0) {
        return task->carry_sprite;
    }
    return task->work_sprite;
#else
    SubObj* obj = this->field_30;
    short val = obj->field_14;
    if (val != (short)0xFFFF && val == this->field_08->field_4C 
        && (int)this->field_08->field_44 > 0 && obj->field_40 != 0) {
        return obj->field_40;
    }
    return (RGE_Sprite*)*(int*)((char*)this->field_08->field_08 + 0x18);
#endif
}
