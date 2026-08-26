TRIBE_Action_Build::TRIBE_Action_Build(RGE_Action_Object* file, RGE_Task* task, float x, float y, float z)
    : RGE_Action(file, 1) {
    this->task = task;
    this->action_type = 0x65;
    this->target_x = x;
    this->target_y = y;
    this->target_z = z;
}
