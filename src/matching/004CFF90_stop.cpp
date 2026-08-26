int TRIBE_Action_Hunt::stop(void) {
    if (this->obj->owner->computerPlayer() == 0) {
        this->set_state(2);
        return 1;
    }
    this->set_state(1);
    return 1;
}
