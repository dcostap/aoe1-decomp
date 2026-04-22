struct SpriteState {
    char gap_00[0x70];
    unsigned char flags;
};

class RGE_Active_Animated_Sprite {
public:
    SpriteState* state;
    char gap_08[0x1C];
    unsigned char animate_flag;

    virtual int is_animating();
};

int RGE_Active_Animated_Sprite::is_animating() {
    if (this->animate_flag == 0 || (this->state->flags & 1) == 0) {
        return 0;
    }
    return 1;
}
