struct InnerObj_draw {
    unsigned char get_lowest_draw_level();
};

class RGE_Sprite {
public:
    char gap_0[4];
    InnerObj_draw *ptr;
    unsigned char get_lowest_draw_level();
};

unsigned char RGE_Sprite::get_lowest_draw_level() {
    if (this->ptr)
        return this->ptr->get_lowest_draw_level();
    return 0x14;
}
