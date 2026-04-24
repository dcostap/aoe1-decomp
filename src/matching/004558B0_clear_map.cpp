class RGE_Player;
class RGE_Game_World;

class RGE_Game_World {
public:
    void reset_object_count();
    void reset_player_visible_maps();
};

class RGE_Map {
public:
    void new_map(long x, long y);
    void set_terrain(RGE_Player* player, RGE_Game_World* world, int a3, int a4, long x, long y, unsigned char a7, unsigned char a8, int a9);
    void clear_map(RGE_Player* param_1, RGE_Game_World* param_2, unsigned char param_3, long param_4, long param_5);
};

void RGE_Map::clear_map(RGE_Player* param_1, RGE_Game_World* param_2, unsigned char param_3, long param_4, long param_5) {
    new_map(param_4, param_5);
    if (param_2 != 0) {
        param_2->reset_object_count();
    }
    set_terrain(param_1, param_2, 0, 0, param_4 - 1, param_5 - 1, param_3, 1, 0);
    if (param_2 != 0) {
        param_2->reset_player_visible_maps();
    }
}
