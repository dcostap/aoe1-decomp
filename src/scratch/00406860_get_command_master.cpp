// VA: 00406860 RGE_Action_Object::get_command_master
// PDB source: act_obj.cpp lines 484-519
// The natural typed reconstruction retains the ordered command-task calls and
// the proven owner/master array walk.  Register allocation remains unresolved.
// BINARY NOTE: The rebuilt body remains 217 bytes with 143 differing bytes.
// The original keeps target in EBX, z in EBP, and i in the target home.  The
// clean source keeps target in EBP, reloads z, and keeps i in EBX.

#include "../../include/act_obj_context.h"

RGE_Master_Static_Object* RGE_Action_Object::get_command_master(RGE_Static_Object* target,
                                                                float x, float y, float z)
{
    if (target == this || ((RGE_Master_Action_Object*)this->master_obj)->task_by_group == 0) {
        return this->master_obj;
    }
    if (((RGE_Master_Command*)((RGE_Master_Action_Object*)this->master_obj)->tasks)->getTask(
            this, target, x, y, z) != 0) {
        return this->master_obj;
    }
    if (((RGE_Master_Action_Object*)this->master_obj)->task_by_group != 0) {
        RGE_Master_Static_Object* obj;
        for (int i = 0; i < this->owner->master_object_num; i++) {
            obj = this->owner->master_objects[i];
            if (obj != 0 &&
                obj->object_group == this->master_obj->object_group &&
                obj->master_type == this->master_obj->master_type &&
                ((RGE_Master_Action_Object*)obj)->task_by_group ==
                    ((RGE_Master_Action_Object*)this->master_obj)->task_by_group) {
                if (((RGE_Master_Command*)((RGE_Master_Action_Object*)obj)->tasks)->getTask(
                        this, target, x, y, z) != 0) {
                    return obj;
                }
            }
        }
    }
    return this->master_obj;
}
