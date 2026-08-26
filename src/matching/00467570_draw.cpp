void TEasy_Panel::draw() {
    if (this->need_restore != 0) {
        if (this->shadow_area != 0) {
            this->setup_shadow_area(1);
        }
        this->need_restore = 0;
    }
    if (this->draw_rect2_flag != 0) {
        this->draw_background(1);
    } else {
        this->draw_background(0);
    }
}
