// VA: 00406010 RGE_Action_Object::~RGE_Action_Object (112 B)
// PDB source: act_obj.cpp lines 76-82
// Flags: config/flags/act_obj.rsp (default + /GX)

#include "../../include/act_obj_context.h"

RGE_Action_Object::~RGE_Action_Object()
{
    RGE_Action_List* p = this->actions;
    if (p != 0) {
        p->RGE_Action_List::~RGE_Action_List();
        operator_delete(p);
        this->actions = 0;
    }
    // No explicit ~RGE_Moving_Object() call — VC5 auto-generates it.
}
