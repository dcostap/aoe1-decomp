void RGE_Static_Object::release_being_worked_on(RGE_Static_Object* unused) {
    if (this->worker_num > 0) {
        this->worker_num--;
    }
    if (this->worker_num == 0) {
        unsigned char state = this->object_state;
        if (state == 2) {
            if (!(this->hp < DAT_00574720)) {
                goto sleep_it;
            }
        }
        if (state != 6) {
            return;
        }
    sleep_it:
        set_sleep_flag(1);
    }
}
