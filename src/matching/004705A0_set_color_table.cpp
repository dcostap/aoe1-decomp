class RGE_Color_Table {};

class RGE_Game_World {
public:
    void* vtable_ptr;
    char gap_04[0x60];
    RGE_Color_Table** color_tables;
};

class RGE_Player {
public:
    void* vtable_ptr;
    char gap_04[0x38];
    RGE_Game_World* world;
    char gap_40[0xC8];
    RGE_Color_Table* color_table;

    void set_color_table(unsigned char param);
};

struct PlayerColorIndex {
    unsigned char value;
};

void RGE_Player::set_color_table(unsigned char param) {
    PlayerColorIndex index;
    index.value = param;
    this->color_table = this->world->color_tables[index.value];
}
