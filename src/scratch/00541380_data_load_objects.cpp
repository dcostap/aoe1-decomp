// 00541380 RGE_Game_World::data_load_objects (World.cpp:568-601, 279B)
// Loads object data from file for all master players.
// FLAGS: /nologo /c /O2 /Oy
//
// Attempt notes:
// - Logic, calls, field offsets, virtual dispatch (slots 3/4) all match correctly
// - Remaining ~28% edit diff is purely register save scheduling:
//   * Original saves esi/edi in prologue, ebp at 005413A7 (after fopen), ebx at 005413CD (inside outer loop)
//   * Rebuilt saves ebx/ebp/esi/edi all at function entry
//   * All stack offsets shifted by 4-8 bytes as a result
// - Reuses filename param slot for player_index (short), object_id locals slot for count
// - Virtual calls via RGE_Master_Player struct with padding (slots 0-2) and add_object/slot3 + add_object_data/slot4
// - Second virtual call arg order: add_object_data(fp, v2, sprites, sounds, v1)
//   (original pushes: v1, sounds[+0x30], sprites[+0x38], v2, fp → thiscall: fp/arg1, v2/arg2, sprites/arg3, sounds/arg4, v1/arg5)
// - Strong candidate for variant_lab to find right register save scheduling

extern "C" void* __cdecl fopen(const char*, const char*);
extern "C" int __cdecl fscanf(void*, const char*, ...);
extern "C" int __cdecl fclose(void*);

struct RGE_Sprite;
struct RGE_Sound;

struct RGE_Master_Player {
    virtual void d0() {}
    virtual void d1() {}
    virtual void d2() {}
    virtual void add_object(short id) {}
    virtual void add_object_data(void* fp, short v2, RGE_Sprite** sprites, RGE_Sound** sounds, short v1) {}
};

struct RGE_Game_World {
    void* vtable;
    char gap_04[0x2C];
    RGE_Sound** sounds;  // +0x30
    char gap_34[4];
    RGE_Sprite** sprites;  // +0x38
    char gap_3C[0x0C];
    RGE_Master_Player** master_players;  // +0x48

    unsigned char data_load_objects(char* filename);
};

unsigned char RGE_Game_World::data_load_objects(char* filename) {
    void* fp = fopen(filename, "r");
    if (fp == 0) {
        return 1;
    }

    short player_count;
    if (fscanf(fp, "%hd", &player_count) == -1) {
        fclose(fp);
        return 1;
    }

    short object_id;  // reused as count for inner loop

    for (short player_idx = 0; player_idx < player_count; player_idx++) {
        if (fscanf(fp, "%hd", (short*)&filename) == -1) {
            continue;
        }

        fscanf(fp, "%hd", &object_id);
        master_players[*(short*)&filename]->add_object(object_id);

        if (fscanf(fp, "%hd", &object_id) == -1) {
            continue;
        }
        if (object_id <= 0) {
            continue;
        }

        short v1, v2;
        for (short j = 0; j < object_id; j++) {
            if (fscanf(fp, "%hd %hd", &v1, &v2) == -1) {
                continue;
            }

            master_players[*(short*)&filename]->add_object_data(fp, v2, sprites, sounds, v1);
        }
    }

    fclose(fp);
    return 1;
}
