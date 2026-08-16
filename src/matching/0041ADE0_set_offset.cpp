class RGE_Active_Sprite {
public:
    void* sprite;
    unsigned char type;
    char gap_09[0x3];
    long offset_x;
    long offset_y;

    virtual void set_offset(long param_1, long param_2);
};

void RGE_Active_Sprite::set_offset(long param_1, long param_2) {
    this->offset_x = param_1;
    this->offset_y = param_2;
}
