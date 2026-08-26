TRIBE_Action_Hunt::TRIBE_Action_Hunt(RGE_Action_Object* obj, RGE_Task* task,
                                     float x, float y, float z)
    : RGE_Action(obj, 1) {
    this->task = task;
    this->action_type = 0x6E;
    this->target_x = x;
    this->target_y = y;
    this->target_z = z;
    this->targetType = -1;
}
