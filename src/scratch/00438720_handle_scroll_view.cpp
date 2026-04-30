// 00438720 RGE_Diamond_Map::handle_scroll_view (diam_map.cpp:1402-1423)

class RGE_Player {
public:
    void set_view_loc(float x, float y);
};

class VBase {
public:
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void update_view(int);
};

class RGE_Diamond_Map : public VBase {
public:
    void handle_scroll_view(long param_1, long param_2);
    int pick_tile(long param_1, long param_2, short* out1, short* out2, void** out_tile);

    char gap_04[0xF0];
    void* world;                 // +0xF4
    RGE_Player* player;          // +0xF8
    char gap_FC[0x0C];
    long mouse_last_x;           // +0x108
    long mouse_last_y;           // +0x10C
    char gap_110[0x40];
    VBase* main_view;            // +0x150
    char gap_154[0x18];
};

void RGE_Diamond_Map::handle_scroll_view(long param_1, long param_2)
{
    void* tile;
    long orig_1 = param_1;
    long orig_2 = param_2;
    if (this->pick_tile(param_1, param_2, (short*)&param_1, (short*)&param_2, &tile) == 0)
        return;

    this->player->set_view_loc((float)(short)param_2 - 0.5f, (float)(short)param_1 - 0.5f);

    this->update_view(1);

    if (this->main_view != 0) {
        this->main_view->update_view(1);
    }

    this->mouse_last_x = orig_1;
    this->mouse_last_y = orig_2;
}
