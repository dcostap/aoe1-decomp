// 00471C00 RGE_Player::remake_visible_map
// Working pass: natural delete/new visible map with /GX EH context.

#ifndef PLAYER_GROUPED_TU
class RGE_Player;

class RGE_World {
public:
    char gap_00[0x28];
    void* objects;
};

class RGE_Visible_Map {
public:
    char gap_00[0x38];

    RGE_Visible_Map(void* objects, RGE_Player* player);
    ~RGE_Visible_Map();
};

class RGE_Player {
public:
    char gap_00[0x38];
    RGE_Visible_Map* visible;
    RGE_World* world;

    void remake_visible_map();
};
#endif

void RGE_Player::remake_visible_map() {
    if (this->visible != 0) {
        delete this->visible;
    }
    this->visible = new RGE_Visible_Map(this->world->map, this);
}
