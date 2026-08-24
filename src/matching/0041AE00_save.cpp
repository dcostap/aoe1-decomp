extern "C" void __cdecl rge_write(int param_1, void* param_2, int param_3);

#ifndef ASPRITE_FULL_TU
class RGE_Sprite {
public:
    char gap_00[0x72];
    short id;
};

class RGE_Active_Sprite {
public:
    RGE_Sprite* sprite;
    unsigned char type;
    char gap_09[0x3];
    long offset_x;
    long offset_y;

    virtual void save(int param_1);
};
#endif

void RGE_Active_Sprite::save(int param_1) {
    rge_write(param_1, &this->type, 1);
    rge_write(param_1, &this->sprite->id, 2);
    rge_write(param_1, &this->offset_x, 4);
    rge_write(param_1, &this->offset_y, 4);
}
