class RGE_Sprite;

class RGE_Active_Sprite {
public:
    void* vtable_ptr;
    RGE_Sprite* sprite;
    unsigned char type;
    char gap_09[0x3];
    long offset_x;
    long offset_y;

    RGE_Active_Sprite(RGE_Sprite* sprite);
};

RGE_Active_Sprite::RGE_Active_Sprite(RGE_Sprite* sprite) {
    this->sprite = sprite;
    this->vtable_ptr = (void*)0x56EE38;
    this->type = 1;
    this->offset_x = 0;
    this->offset_y = 0;
}
