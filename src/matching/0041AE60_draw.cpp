class RGE_Color_Table;
class TDrawArea;
class RGE_Sprite;

class RGE_Active_Sprite {
public:
    RGE_Sprite* sprite;
    unsigned char type;
    char gap_09[0x3];
    long offset_x;
    long offset_y;

    virtual void draw(short param_1, long param_2, long param_3, long param_4, long param_5, RGE_Color_Table* param_6, TDrawArea* param_7);
};

class RGE_Sprite {
public:
    unsigned char draw(long param_1, long param_2, long param_3, long param_4, long param_5, long param_6, RGE_Color_Table* param_7, TDrawArea* param_8, unsigned char param_9);
};

void RGE_Active_Sprite::draw(short param_1, long param_2, long param_3, long param_4, long param_5, RGE_Color_Table* param_6, TDrawArea* param_7) {
    this->sprite->draw((long)param_1, 0, param_2 + this->offset_x, param_3 + this->offset_y, param_4 + this->offset_x, param_5 + this->offset_y, param_6, param_7, 0);
}
