#ifndef ASPRITE_FULL_TU
class RGE_Sprite;

class RGE_Active_Sprite {
public:
    RGE_Sprite* sprite;

    virtual unsigned char get_frame(short& param_1, short& param_2, short& param_3, short& param_4, long param_5);
};

class RGE_Sprite {
public:
    int get_frame(short& param_1, short& param_2, short& param_3, short& param_4, long param_5, long param_6);
};
#endif

unsigned char RGE_Active_Sprite::get_frame(short& param_1, short& param_2, short& param_3, short& param_4, long param_5) {
    int iVar1;

    iVar1 = this->sprite->get_frame(param_1, param_2, param_3, param_4, param_5, 0);
    return (unsigned char)iVar1;
}
