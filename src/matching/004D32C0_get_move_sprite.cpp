#ifndef TACT_TRD_SHARED_CONTEXT
class RGE_Sprite;

struct TradeUnit {
    char gap_00[0x44];
    float field_44;
    char gap_48[0x04];
    short field_4C;
};

struct RGE_Task {
    char gap_00[0x14];
    short field_14;
    char gap_16[0x1E];
    RGE_Sprite* field_34;
    char gap_38[0x08];
    RGE_Sprite* field_40;
};

class TRIBE_Action_Trade {
public:
    virtual void vf00(void);
    char gap_04[0x04];
    TradeUnit* unit;
    char gap_0C[0x24];
    RGE_Task* task;

    RGE_Sprite* get_move_sprite(void);
};
#endif

RGE_Sprite* TRIBE_Action_Trade::get_move_sprite(void) {
#ifdef TACT_TRD_SHARED_CONTEXT
    RGE_Task* task = this->task;
    short task_facet = task->attribute_type;

    if (task_facet != -1) {
        if (this->obj->facet == task_facet) {
            if (this->obj->attribute_amount_held > 0) {
                if (task->carry_sprite != 0) {
                    return task->carry_sprite;
                }
            }
        }
    }
    return task->work_sprite;
#else
    RGE_Task* task = this->task;
    short task_facet = task->field_14;

    if (task_facet != -1) {
        if (this->unit->field_4C == task_facet) {
            if ((int)this->unit->field_44 > 0) {
                if (task->field_40 != 0) {
                    return task->field_40;
                }
            }
        }
    }
    return task->field_34;
#endif
}
