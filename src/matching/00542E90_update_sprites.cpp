class RGE_Sprite {
public:
    void update(unsigned long param);
};

class RGE_Game_World {
public:
    char gap_00[0x24];
    int sprite_update_index;
    char gap_28[0x0C];
    short sprite_num;
    char gap_36[0x02];
    RGE_Sprite** sprites;

    void update_sprites(unsigned long param);
};

void RGE_Game_World::update_sprites(unsigned long param) {
    if (this->sprite_update_index >= this->sprite_num) {
        this->sprite_update_index = 0;
    }
    if (this->sprites[this->sprite_update_index] != 0) {
        this->sprites[this->sprite_update_index]->update(param);
    }
    this->sprite_update_index++;
}
