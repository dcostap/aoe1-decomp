// VA: 005415B0 RGE_Game_World::data_load_world(FILE*)
// PDB source: World.cpp lines 624-695
// attempt 1: natural named 24-byte filename buffers; frame was 0x188 and local order differed.
// attempt 2: one exact 0x18C stack window with binary-observed offsets for the 16 filename records and scalar outputs; fscanf setup matched through add esp.
// attempt 3: use binary-observed post-fscanf argument offsets rather than nominal filename bases; matched through data_load_effects.
// attempt 4: model three data_load_sprites parameters as by-value dwords reloaded from stack slots, not addresses; only three LEA displacements remain.
// attempt 5: tune the remaining data_load_sprites pointer offsets for VC5's right-to-left argument scheduling.

extern "C" int __cdecl fscanf(void* stream, const char* fmt, ...);

class RGE_Game_World {
public:
    char gap_04[0x2C];
    void* sounds; // +0x30

    virtual void vf00();
    virtual void load_terrain_tables(char* terrain_table_file);   // +0x04
    virtual void data_load_objects(char* obj_file);               // +0x08
    virtual void data_load_overlay(char* overlay_file);           // +0x0C
    virtual void data_load_rmm_terrain(char* rmm_terrain_file);   // +0x10
    virtual void data_load_colors(char* color_file);              // +0x14
    virtual void data_load_terrain(char* terrain_file);           // +0x18
    virtual void vf1C();
    virtual void data_load_effects(void* tile_height);            // +0x20
    virtual void data_load_sprites(char* a, char* b, char* c, char* d, int e, int f, int g, void* sounds, char* border_file); // +0x24
    virtual void data_load_random_map(char* sound_file, char* player_file, char* terr_obj_file, char* obj_file); // +0x28

    unsigned char data_load_world(void* file);
};

unsigned char RGE_Game_World::data_load_world(void* file) {
    char local[0x18C];

    fscanf(file, (const char*)0x58EBE4,
        local + 0x15C,  // terrain_table_file + 4
        local + 0x3C,   // color_file + 4
        local + 0x12C,  // sound_file + 4
        local + 0xB4,   // border_file + 4
        local + 0x84,   // overlay_file + 4
        local + 0x54,   // terrain_file + 4
        local + 0x24,   // map_file + 4
        local + 0x6C,   // sprite_file + 4
        local + 0xFC,   // player_file + 4
        local + 0x9C,   // obj_file + 4
        local + 0x0C,   // effects_file + 4
        local + 0xCC,   // terr_obj_file + 4
        local + 0x174,  // rmm_map_file + 4
        local + 0x144,  // rmm_land_file + 4
        local + 0x114,  // rmm_terr_file + 4
        local + 0xE4,   // rmm_obj_file + 4
        local + 0x08,   // effects_file
        local + 0x00,   // elev_height
        local + 0x04);  // tile_width

    this->load_terrain_tables(local + 0x15C);
    this->data_load_colors(local + 0x3C);
    this->data_load_rmm_terrain(local + 0x12C);
    this->data_load_terrain(local + 0x6C);
    this->data_load_objects(local + 0xFC);
    this->data_load_overlay(local + 0x9C);
    this->data_load_effects(local + 0x0C);
    this->data_load_sprites(local + 0xB4, local + 0x84, local + 0x54, local + 0x24, *(int*)(local + 0x08), *(int*)(local + 0x00), *(int*)(local + 0x04), this->sounds, local + 0xCC);
    this->data_load_random_map(local + 0x174, local + 0x144, local + 0x114, local + 0xE4);
    return 1;
}
