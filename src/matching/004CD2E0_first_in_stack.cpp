void TRIBE_Action_Build::first_in_stack(unsigned char value) {
    if (value != 0) {
        if (this->target_obj != 0) {
            this->set_state(4);
            return;
        }
        this->set_state(3);
        return;
    }
    this->set_state(3);
}
