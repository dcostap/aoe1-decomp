// RGE_Active_Animated_Sprite::draw (0041B430, 101 bytes, asprite.cpp)
// Attempt 3 - draw() takes int for first 2 params

#ifndef ASPRITE_FULL_TU
class RGE_Color_Table;
class TDrawArea;
class RGE_Sprite {
public:
    void draw(int param_1, int param_2, long param_3, long param_4, long param_5, long param_6, RGE_Color_Table* param_7, TDrawArea* param_8, char param_9);
    void play_sound(short param_1, short param_2, short param_3);
};

extern RGE_Sprite* fog_next_shape;
#endif

#ifndef ASPRITE_FULL_TU
class RGE_Active_Animated_Sprite {
public:
    char gap_00[4];
    RGE_Sprite* sprite;
    char gap_08[0xC];
    short frame;
    char gap_16[0xA];
    short last_frame;
    unsigned char frame_changed;

    void draw(short param_1, long param_2, long param_3, long param_4, long param_5, RGE_Color_Table* param_6, TDrawArea* param_7);
};
#endif

void RGE_Active_Animated_Sprite::draw(short param_1, long param_2, long param_3, long param_4, long param_5, RGE_Color_Table* param_6, TDrawArea* param_7) {
    this->sprite->draw((int)param_1, (int)this->frame, param_2, param_3, param_4, param_5, param_6, param_7, '\0');
    if (this->frame_changed != 0) {
        if (fog_next_shape == 0) {
            this->sprite->play_sound(this->last_frame, this->frame, param_1);
        }
        this->frame_changed = 0;
    }
}
