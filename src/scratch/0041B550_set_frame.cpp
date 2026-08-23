class RGE_Sprite {
public:
    char gap_0[0x14];
    short frame;
    void set_frame(short v);
};

void RGE_Sprite::set_frame(short v) {
    this->frame = v;
}
