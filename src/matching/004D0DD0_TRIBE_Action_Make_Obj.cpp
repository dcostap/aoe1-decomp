// 004D0DD0 TRIBE_Action_Make_Obj::TRIBE_Action_Make_Obj(int, RGE_Action_Object*)
// Size: 192 bytes
// FLAGS: config/flags/004D0DD0_TRIBE_Action_Make_Obj.rsp uses /GX for the original EH frame

#include "../../include/game_globals.h"

class RGE_Action_Object;

void rge_read(int handle, void* buffer, int size);
extern float save_game_version;

class RGE_Action {
public:
    virtual ~RGE_Action();
    short action_type;
    char gap_06[0x3A];

    RGE_Action(int param_1, RGE_Action_Object* param_2, int param_3);
};

class TRIBE_Action_Make_Obj : public RGE_Action {
public:
    unsigned short field_40;
    int work_done;
    int unique_id;
    unsigned char pre_paid;

    TRIBE_Action_Make_Obj(int param_1, RGE_Action_Object* param_2);
};

TRIBE_Action_Make_Obj::TRIBE_Action_Make_Obj(int param_1, RGE_Action_Object* param_2)
    : RGE_Action(param_1, param_2, 1)
{
    this->action_type = 0x66;
    rge_read(param_1, &this->field_40, 2);
    rge_read(param_1, &this->work_done, 4);
    rge_read(param_1, &this->unique_id, 4);

    if (save_game_version >= 7.23f) {
        rge_read(param_1, &this->pre_paid, 1);
    } else {
        this->pre_paid = 0;
    }
}
