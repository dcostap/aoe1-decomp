class RGE_Color_Table;
class TDrawArea;

class RGE_Sprite {
public:
    void shadow_draw(int x, int frame, long a3, long a4, RGE_Color_Table* colors, TDrawArea* area, unsigned char mode);
};

class RGE_Active_Animated_Sprite {
public:
    RGE_Sprite* sprite;
    char gap_08[0x0C];
    short frame;

    virtual void shadow_draw(short x, long a3, long a4, RGE_Color_Table* colors, TDrawArea* area, unsigned char mode);
};

void RGE_Active_Animated_Sprite::shadow_draw(short x, long a3, long a4, RGE_Color_Table* colors, TDrawArea* area, unsigned char mode) {
    this->sprite->shadow_draw((int)x, (int)this->frame, a3, a4, colors, area, mode);
}
