// VA: 004CA030 TRIBE_Building_Object::production_queue_status (115 B)
// PDB source: t_b_obj.cpp

#include "../../include/t_b_obj_context.h"

int TRIBE_Building_Object::production_queue_status(short* type_out, short* count_out)
{
    *type_out = -1;
    *count_out = 0;
    
    TRIBE_Action_Make_Obj* act = (TRIBE_Action_Make_Obj*)((RGE_Action_List*)production_queue_actions)->get_action();
    if (act && act->action_type == 0x66) {
        act->get_info(type_out, count_out, 0, 0);
        return 1;
    }
    
    if (production_queue_count > 0) {
        *type_out = *production_queue;
        *count_out = 0;
        return 1;
    }
    
    return 0;
}
