void TEasy_Panel::draw() {
    if (*(unsigned char*)((char*)this + 0xF3) != 0) {
        if (*(TDrawArea**)((char*)this + 0x46c) != 0) {
            this->setup_shadow_area(1);
        }
        *(unsigned char*)((char*)this + 0xF3) = 0;
    }
    if (*(unsigned char*)((char*)this + 0xF2) != 0) {
        this->draw_background(1);
    } else {
        this->draw_background(0);
    }
}
