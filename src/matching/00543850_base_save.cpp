// VA: 00543850 RGE_Game_World::base_save(int)
// PDB source: World.cpp lines 2108-2152
// attempt 1: natural decompiler-shaped save with exact field offsets and direct/member virtual save surfaces.

void __cdecl rge_write(int file, void* data, int size);

class RGE_Color_Table { public: void save(int file); };
class RGE_Sound { public: void save(int file); };
class RGE_Sprite { public: void save(int file); };

class RGE_Map {
public:
    virtual void v0(); virtual void v4(); virtual void v8(); virtual void vC();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28();
    virtual void save(int file); // +0x2C
};

class RGE_Effects {
public:
    virtual void v0();
    virtual void save(int file); // +0x04
};

class RGE_Master_Player {
public:
    virtual void v0(); virtual void v4(); virtual void v8(); virtual void vC(); virtual void v10();
    virtual void save(int file); // +0x14
};

class RGE_Game_World {
public:
    char gap_04[0x24];
    RGE_Map* map;                 // +0x28
    short sound_num;              // +0x2C
    char gap_2E[2];
    RGE_Sound** sounds;           // +0x30
    short sprite_num;             // +0x34
    char gap_36[2];
    RGE_Sprite** sprites;         // +0x38
    char gap_3C[8];
    short master_player_num;      // +0x44
    char gap_46[2];
    RGE_Master_Player** master_players; // +0x48
    RGE_Effects* effects;         // +0x4C
    short terrain_num;            // +0x50
    short terrain_size;           // +0x52
    void** terrains;              // +0x54
    char gap_58[8];
    short color_table_num;        // +0x60
    char gap_62[2];
    RGE_Color_Table** color_tables; // +0x64

    virtual void base_save(int file);
};

void RGE_Game_World::base_save(int file) {
    int i;

    rge_write(file, (void*)0x58EC20, 8);
    rge_write(file, &this->terrain_num, 2);
    rge_write(file, &this->terrain_size, 2);

    if (this->terrain_num > 0 && this->terrain_size > 0) {
        rge_write(file, this->terrains, (int)this->terrain_num << 2);
        for (i = 0; i < this->terrain_num; i++) {
            if (this->terrains[i] != 0) {
                rge_write(file, this->terrains[i], (int)this->terrain_size << 2);
            }
        }
    }

    rge_write(file, &this->color_table_num, 2);
    for (i = 0; i < this->color_table_num; i++) {
        this->color_tables[i]->save(file);
    }

    rge_write(file, &this->sound_num, 2);
    for (i = 0; i < this->sound_num; i++) {
        this->sounds[i]->save(file);
    }

    rge_write(file, &this->sprite_num, 2);
    rge_write(file, this->sprites, (int)this->sprite_num << 2);
    for (i = 0; i < this->sprite_num; i++) {
        if (this->sprites[i] != 0) {
            this->sprites[i]->save(file);
        }
    }

    this->map->save(file);
    this->effects->save(file);

    rge_write(file, &this->master_player_num, 2);
    for (i = 0; i < this->master_player_num; i++) {
        this->master_players[i]->save(file);
    }
}
