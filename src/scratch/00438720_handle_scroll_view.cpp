// 00438720 RGE_Diamond_Map::handle_scroll_view
// Source: diam_map.cpp lines 1402-1423. 148 bytes. __thiscall, ret 8.

class RGE_Player {
public:
    char gap_00[0x21C];
    void set_view_loc(float x, float y);
};

// Vtable helper: 8 dummies + update_view at vtable[0x20/4] = entry 8
class VTableHelper {
public:
    virtual void d00(); virtual void d01(); virtual void d02();
    virtual void d03(); virtual void d04(); virtual void d05();
    virtual void d06(); virtual void d07();
    virtual void update_view(int param);
};

// Same helper for RGE_View
class ViewHelper {
public:
    virtual void d00(); virtual void d01(); virtual void d02();
    virtual void d03(); virtual void d04(); virtual void d05();
    virtual void d06(); virtual void d07();
    virtual void update_view(int param);
};

class RGE_Diamond_Map {
public:
    char gap_00[0xF4];
    void* world;                 // +0xF4
    RGE_Player* player;          // +0xF8
    char gap_FC[0x108 - 0xFC];
    long mouse_last_x;           // +0x108
    long mouse_last_y;           // +0x10C
    char gap_110[0x150 - 0x110];
    void* main_view;             // +0x150
    char gap_154[0x16C - 0x154];

    void handle_scroll_view(long param_1, long param_2);
    // pick_tile as a member function (__thiscall)
    int pick_tile(long param_1, long param_2, short* out1, short* out2, void** out_tile);
};

void RGE_Diamond_Map::handle_scroll_view(long param_1, long param_2) {
    void* tile = 0;
    if (this->pick_tile(param_1, param_2, (short*)&param_1, (short*)&param_2, &tile) == 0)
        return;

    this->player->set_view_loc((float)(short)param_1 - 0.5f, (float)(short)param_2 - 0.5f);
    ((VTableHelper*)this)->update_view(1);
    if (this->main_view != 0) {
        ((ViewHelper*)this->main_view)->update_view(1);
    }
    this->mouse_last_x = param_1;
    this->mouse_last_y = param_2;
}
