class RGE_Static_Object;

int TRIBE_Action_Build::move_to(RGE_Static_Object* obj, float x, float y, float z) {
    this->target_x = x;
    this->target_y = y;
    this->target_z = z;
    this->set_target_obj(0);
    this->set_state(0x0B);
    return 1;
}
