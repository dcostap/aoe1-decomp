// 004CF240 TRIBE_Action_Hunt::first_in_stack(unsigned char) — tact_hnt.cpp:139-171
// PDB source: C:\msdev\work\age1_x1\tact_hnt.cpp

// A global float = 0.0 used for fcomp comparison
// Non-const so VC5 generates an actual memory reference
float _zero_val = 0.0f;

void TRIBE_Action_Hunt::first_in_stack(unsigned char param_1)
{
    RGE_Task* tsk = (RGE_Task*)this->task;

    short attr_val = tsk->attribute_type;
    if (this->obj->attribute_type_held != attr_val) {
        this->obj->set_attribute(attr_val, 0.0f);
    }

    if (param_1) {
        RGE_Static_Object* target = this->target_obj;
        if (target) {
            RGE_Static_Object* unit = this->obj;
            // Compare target->owner with unit->owner (order matters for register choice)
            if (target->owner == unit->owner) {
                RGE_Master_Static_Object* target_master = target->master_obj;
                RGE_Master_Action_Object* unit_master =
                    (RGE_Master_Action_Object*)unit->master_obj;
                short target_id = target_master->id;
                if (target_id == unit_master->drop_site || target_id == unit_master->backup_drop_site) {
                    if (unit->attribute_amount_held > _zero_val) {
                        this->set_target_obj2(target);
                        this->set_target_obj(0);
                        this->target_x = -1.0f;
                        this->target_y = -1.0f;
                        this->target_z = -1.0f;
                        this->set_state(8);
                        return;
                    }
                }
            }
            this->set_state(4);
        } else {
            this->set_state(3);
        }
    } else {
        this->set_state(3);
    }
}
