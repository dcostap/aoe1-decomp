RGE_Sprite* TRIBE_Action_Hunt::get_move_sprite(void) {
    RGE_Task* task = this->task;
    short task_facet = task->attribute_type;
    if (task_facet != -1 && task_facet == this->obj->attribute_type_held &&
        (int)this->obj->attribute_amount_held > 0 && task->carry_sprite != 0) {
        return task->carry_sprite;
    }
    return task->move_sprite;
}
