#ifndef ASPRITE_FULL_TU
class RGE_Color_Table;
class TDrawArea;
class RGE_Sprite {
public:
    unsigned char normal_draw(long param_1, long param_2, long param_3, long param_4, RGE_Color_Table* param_5, TDrawArea* param_6);
    void play_sound(short param_1, short param_2, short param_3);
};

class RGE_Active_Animated_Sprite {
public:
    char gap_00[4];
    RGE_Sprite* sprite;
    char gap_08[0xC];
    short frame;
    char gap_16[0xA];
    short last_frame;
    unsigned char frame_changed;

    void normal_draw(short param_1, long param_2, long param_3, RGE_Color_Table* param_4, TDrawArea* param_5);
};
#endif

void RGE_Active_Animated_Sprite::normal_draw(short param_1, long param_2, long param_3, RGE_Color_Table* param_4, TDrawArea* param_5) {
    this->sprite->normal_draw((long)param_1, (long)this->frame, param_2, param_3, param_4, param_5);
    if (this->frame_changed != 0) {
        this->sprite->play_sound(this->last_frame, this->frame, param_1);
        this->frame_changed = 0;
    }
}
