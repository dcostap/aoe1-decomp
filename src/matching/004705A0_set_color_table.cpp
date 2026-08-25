#ifndef PLAYER_GROUPED_TU
class RGE_Color_Table {
public:
    virtual ~RGE_Color_Table();
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x60];
    RGE_Color_Table** color_tables;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;
    char gap_40[0xC8];
    RGE_Color_Table* color_table;

    void set_color_table(unsigned char param);
};

#endif

void RGE_Player::set_color_table(unsigned char param) {
    this->color_table = this->world->color_tables[param];
}
