// TRIBE_Action_Hunt::work (004D0080)
// PDB source: tact_hnt.cpp:890-948
// Size: 207 bytes
// Calling convention: __thiscall

int TRIBE_Action_Hunt::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4)
{
    if (param_1 != 0) {
        if (param_1->owner == this->obj->owner) {
            RGE_Master_Action_Object* master =
                static_cast<RGE_Master_Action_Object*>(this->obj->master_obj);
            short obj_id = param_1->master_obj->id;
            if ((obj_id == master->drop_site || obj_id == master->backup_drop_site) &&
                this->obj->attribute_amount_held > DAT_00575150) {
                this->set_target_obj(0);
                this->timer = 0.0f;
                this->target_x = -1.0f;
                this->target_y = -1.0f;
                this->target_z = -1.0f;
                this->set_target_obj2(param_1);
                this->set_state(8);
                return 1;
            }
        }
        this->set_target_obj(param_1);
        this->set_target_obj2(0);
        this->set_state(4);
        return 1;
    }
    this->target_x = param_2;
    this->target_y = param_3;
    this->target_z = param_4;
    this->set_target_obj(0);
    this->set_state(0x0F);
    return 1;
}
