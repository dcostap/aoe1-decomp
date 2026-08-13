// VA: 0049B910 handle_terrain_sound (468B)
// scr_game.cpp:4621-4711
//
// Natural reconstruction of the terrain-sound throttle, terrain priority
// scan, and DirectSound stream restart.  The map and terrain-set declarations
// retain the proven 0x198 terrain stride and field ownership.
//
// Attempt log:
// - baseline natural typed terrain-set scan: 233 differing bytes, rebuilt
//   size 462 versus the 468-byte oracle; all 12 calls were ordered correctly.
// - moved the world load ahead of the last-time store and corrected the
//   terrain-playing 1000ms path to the oracle's direct epilogue return;
//   size became exact and CFG coverage improved.
// - A field-centered cursor diagnostic reached 202 differing bytes, but its
//   negative-offset field accesses were not retained. Restoring direct typed
//   terrain_types[index] ownership unexpectedly improved the canonical source
//   to exact size/CFG/calls and only eight register-encoding bytes of drift.
// - byte priority, register hints, direct loop-bound, and for-loop spelling
//   probes were regressive or emitted duplicates. The remaining gap is the
//   best-index/count register coloring in the typed scan.
// - swapped priority/index declarations and routed the interval throttle to
//   the shared no-log return; diff improved from 8 to 7 bytes.
// - moved the named map/count loads before the result locals; output was
//   unchanged. Remaining drift is seven register-encoding bytes in the scan.
// - declaring best_index before terrain_count was a natural ownership-order
//   probe; output was unchanged, so the clean declaration order remains.
// - named the typed terrain sound before get_file_name() as a natural dispatch
//   probe; output was unchanged, so the seven scan register bytes remain.

extern "C" void __cdecl color_log(unsigned char a, unsigned char b, int c);
extern unsigned long debug_timeGetTime(const char* file, int line);

extern int disable_terrain_sounds;
extern int _bPlaying;

class TSound_Driver {
public:
    int stop_stream();
    int stream_file(char* file_name, int a, long b);
};

class RGE_Sound {
public:
    char* get_file_name();
};

class RGE_Tile_Set {
public:
    unsigned char loaded;               // +0x00
    char gap_001[0x23];
    RGE_Sound* sound;                   // +0x24
    char gap_028[0x1D];
    unsigned char drawn;                // +0x45
    char gap_046[0x152];
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    char gap_004[0x88];
    RGE_Tile_Set terrain_types[32];     // +0x8C
    char gap_338C[0x5A00];
    void* map_row_offset;               // +0x8D8C
    short num_terrain;                  // +0x8D90
};

class RGE_Game_World {
public:
    virtual unsigned char data_load_world(void* file);
    char gap_004[0x24];
    RGE_Map* map;                       // +0x28
};

class TRIBE_World : public RGE_Game_World {
};

class RGE_Prog_Info {
public:
    char gap_000[0x8A8];
    int use_sound;                      // +0x8A8
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_004[8];
    RGE_Prog_Info* prog_info;           // +0x0C
    char gap_010[0x50];
    TSound_Driver* sound_system;        // +0x60
};

extern RGE_Base_Game* rge_base_game;

class TScreenPanel {
public:
    virtual ~TScreenPanel();
    char gap_004[0x474];
};

class TRIBE_Screen_Game : public TScreenPanel {
public:
    char gap_478[0x13C];
    TRIBE_World* world;                 // +0x5B4
    char gap_5B8[0xC0];
    unsigned long terrain_sound_interval;       // +0x678
    unsigned long last_terrain_sound_time;      // +0x67C
    RGE_Sound* terrain_sound;                    // +0x680
    int terrain_playing;                         // +0x684
    unsigned long terrain_sound_start_time;     // +0x688

    void handle_terrain_sound();
};

static const char s_scr_game_cpp[] =
    "C:\\msdev\\work\\age1_x1\\scr_game.cpp";

void TRIBE_Screen_Game::handle_terrain_sound() {
    color_log(0x54, 0x16, 4);

    if (rge_base_game->prog_info->use_sound != 0 &&
        rge_base_game->sound_system != 0 &&
        disable_terrain_sounds == 0) {
        unsigned long now =
            debug_timeGetTime(s_scr_game_cpp, 0x121D);

        if (this->terrain_playing != 0) {
            if (now - this->last_terrain_sound_time < 1000) {
                goto early_return;
            }
            this->last_terrain_sound_time = now;

            if (_bPlaying != 0) {
                if (now - this->terrain_sound_start_time < 6000) {
                    goto done;
                }
                rge_base_game->sound_system->stop_stream();
            }

            this->terrain_playing = 0;
            color_log(0x54, 0x5F, 4);
            goto done_return;
        }

        if (now - this->last_terrain_sound_time <
            this->terrain_sound_interval) {
            goto early_return;
        }
        TRIBE_World* world = this->world;
        this->last_terrain_sound_time = now;

        RGE_Map* map = world->map;
        short terrain_count = map->num_terrain;
        short best_index = -1;
        short best_drawn = 0;
        short index = 0;
        for (; index < terrain_count; ++index) {
            RGE_Tile_Set* terrain = &map->terrain_types[index];
            if (terrain->loaded != 0 &&
                terrain->drawn > best_drawn &&
                terrain->sound != 0) {
                best_index = index;
                best_drawn = terrain->drawn;
            }
        }

        if (best_index == -1) {
            goto done;
        }

        char* file_name = map->terrain_types[best_index].sound->get_file_name();
        if (file_name == 0) {
            goto done;
        }

        color_log(0x54, 0x4C, 4);
        debug_timeGetTime(s_scr_game_cpp, 0x125B);
        rge_base_game->sound_system->stop_stream();
        rge_base_game->sound_system->stream_file(file_name, 0, 0);
        color_log(0x54, 0x32, 4);
        this->terrain_playing = 1;
        this->terrain_sound_start_time =
            debug_timeGetTime(s_scr_game_cpp, 0x1262);
    }

done:
    color_log(0x54, 0x5F, 4);

early_return:
done_return:
    return;
}
