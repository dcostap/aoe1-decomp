extern "C" void __cdecl rge_read(int handle, void* buffer, int size);

#ifndef ASPRITE_FULL_TU
class RGE_Sprite;

class RGE_Active_Sprite {
public:
    virtual ~RGE_Active_Sprite();
    RGE_Sprite* sprite;
    unsigned char type;
    char gap_09[0x3];
    long offset_x;
    long offset_y;

    RGE_Active_Sprite(int param_1, RGE_Sprite** param_2);
};
#endif

RGE_Active_Sprite::RGE_Active_Sprite(int param_1, RGE_Sprite** param_2) {
    short index;

    this->type = 1;
    rge_read(param_1, &index, 2);
    if (index >= 0) {
        this->sprite = param_2[index];
    } else {
        this->sprite = 0;
    }
    rge_read(param_1, &this->offset_x, 4);
    rge_read(param_1, &this->offset_y, 4);
}
