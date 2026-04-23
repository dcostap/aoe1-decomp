class TDrawArea;
class TPanel;
class RGE_Game_World;

class TPanel {
public:
    long setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, unsigned char param_7);
};

class RGE_Diamond_Map : public TPanel {
public:
    char gap_00[0x164];
    int own_save_area;
    TDrawArea* save_area;

    long setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, unsigned char param_7, int param_8, TDrawArea* param_9);
};

long RGE_Diamond_Map::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, unsigned char param_7, int param_8, TDrawArea* param_9) {
    this->save_area = param_9;
    this->own_save_area = 0;
    TPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
    return 1;
}
