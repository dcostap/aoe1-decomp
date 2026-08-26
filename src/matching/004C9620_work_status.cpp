// VA: 004C9620 TRIBE_Building_Object::work_status(short&, short&, short&, char*, short)
// PDB source: t_b_obj.cpp lines 872-898 (150 B, 48 asm)
// Attempt log:

#include "../../include/t_b_obj_context.h"

int TRIBE_Building_Object::work_status(short& p1, short& p2, short& p3, char* p4, short p5)
{
    RGE_Action* action = this->actions->get_action();
    
    if (action != 0) {
        p1 = action->action_type;
    } else {
        p1 = 0;
    }
    
    switch (p1) {
    case 0x66:
        ((TRIBE_Action_Make_Obj*)action)->get_info(&p2, &p3, p4, p5);
        return 1;
    case 0x67:
        ((TRIBE_Action_Make_Tech*)action)->get_info(&p2, &p3, p4, p5);
        return 1;
    default:
        p2 = -1;
        p3 = 0;
        if (p4 != 0) *p4 = 0;
        return 0;
    }
}
