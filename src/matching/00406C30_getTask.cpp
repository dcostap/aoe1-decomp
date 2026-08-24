#include "../../include/act_obj_context.h"

RGE_Task* RGE_Action_Object::getTask(RGE_Static_Object* target, float x, float y, float z)
{
    RGE_Task* task = ((RGE_Master_Command*)
        ((RGE_Master_Action_Object*)this->master_obj)->tasks)->getTask(
            this, target, x, y, z);
    if (task == 0 && ((RGE_Master_Action_Object*)this->master_obj)->task_by_group != 0) {
        int i = 0;
        if (this->owner->master_object_num > 0) {
            RGE_Master_Static_Object* obj;
            while (1) {
                obj = this->owner->master_objects[i];
                if (obj != 0 &&
                    obj->object_group == this->master_obj->object_group &&
                    obj->master_type == this->master_obj->master_type &&
                    ((RGE_Master_Action_Object*)obj)->task_by_group ==
                        ((RGE_Master_Action_Object*)this->master_obj)->task_by_group) {
                    task = ((RGE_Master_Command*)
                        ((RGE_Master_Action_Object*)obj)->tasks)->getTask(
                            this, target, x, y, z);
                    if (task != 0) {
                        goto found;
                    }
                }
                i++;
                if (i < this->owner->master_object_num) continue;
                return task;
            }
found:
            this->transform(obj);
        }
    }
    return task;
}
