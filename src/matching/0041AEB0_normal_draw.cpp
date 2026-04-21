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

    virtual void normal_draw(short param_1, long param_2, long param_3, RGE_Color_Table* param_4, TDrawArea* param_5);
};

class RGE_Sprite {
public:
    unsigned char normal_draw(long param_1, long param_2, long param_3, long param_4, RGE_Color_Table* param_5, TDrawArea* param_6);
};

void RGE_Active_Sprite::normal_draw(short param_1, long param_2, long param_3, RGE_Color_Table* param_4, TDrawArea* param_5) {
    this->sprite->normal_draw((long)param_1, 0, this->offset_x + param_2, this->offset_y + param_3, param_4, param_5);
}
