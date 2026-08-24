#ifndef ASPRITE_FULL_TU
class RGE_Sprite;

class RGE_Active_Sprite {
public:
    RGE_Sprite* sprite;
    int check_for_shadows();
};

class RGE_Sprite {
public:
    int check_for_shadows();
};
#endif

int RGE_Active_Sprite::check_for_shadows() {
    if (this->sprite != 0) {
        return this->sprite->check_for_shadows();
    }
    return 0;
}
