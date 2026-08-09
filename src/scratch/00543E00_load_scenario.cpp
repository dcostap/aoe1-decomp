// VA: 00543E00 RGE_Game_World::load_scenario
// Attempt log:
// initial natural version-chain reconstruction from packet.
// tried direct 4-byte version comparisons against packet globals and immediate return tails after each virtual load/post_load pair.
// modeled 1.03 extra header-size read/malloc/read/free path and failure close path.
// used local stack buffer shaped as scenario_name[300] plus int locals; the
// first draft merged the identical post-load tails and emitted only 544 bytes.
// tried vtable padding so load variants land at +0x7c..+0x98 and post_load at +0xa8.
// - The typed scenario-directory surface, 0x134 frame, positive outer guards,
//   shared v1.02/v1.03 label, and repeated per-version post-load returns now
//   recover all 24 calls and the nine original returns.  The best source is
//   634 bytes versus 642 (145 strict bytes, 88.84% shape); its remaining
//   structural drift is the late-version compare/block layout and the initial
//   parameter-versus-this register coloring.
// - Distinct view-type aliases for the A8 call and a return-width ABI probe
//   did not inhibit VC5 tail merging and were removed.  The literal Ghidra
//   nested source shape was retained only where it explains the observed
//   repeated tails; compiler steering is not retained beyond that.

extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" int __cdecl rge_open(char*, int);
extern "C" void __cdecl rge_read_uncompressed(int, void*, int);
extern "C" void* __cdecl malloc(unsigned int);
extern "C" void __cdecl free(void*);
extern "C" void __cdecl rge_close(int);

struct RGE_Prog_Info {
    char gap[0xc17];
    char scenario_dir[261];
};

struct RGE_Base_Game {
    char gap[0xc];
    RGE_Prog_Info* prog_info;
};
extern RGE_Base_Game* rge_base_game;
extern int world_update_counter;
extern int version_101;
extern int version_102;
extern int version_103;
extern int version_104;
extern int version_105;
extern int version_106;
extern int version_107;
extern int version_108;
extern int version_109;
extern int version_110;
extern int version_111;

struct RGE_Player_Info {};

class RGE_Game_World {
public:
    virtual unsigned char data_load_world(void*);
    virtual unsigned char data_load_terrain_tables(char*);
    virtual unsigned char data_load_players(char*);
    virtual unsigned char data_load_objects(char*);
    virtual unsigned char data_load_sounds(char*);
    virtual unsigned char data_load_color_tables(char*);
    virtual unsigned char data_load_sprites(char*);
    virtual void data_load_players_type(short, short, void*);
    virtual void data_load_effects(char*);
    virtual void data_load_map();
    virtual void data_load_random_map();
    virtual unsigned char init_player_type(int, short, unsigned char);
    virtual unsigned char init_player(int);
    virtual void load_player(int, unsigned char, short);
    virtual void color_table_init(int);
    virtual void terrain_tables_init(int);
    virtual void init_sounds(int, void*);
    virtual void init_sprites(int);
    virtual void map_init(int, void*);
    virtual void effects_init(int);
    virtual void master_player_init(int);
    virtual void command_init(int, void*);
    virtual void world_init(int, void*, void*);
    virtual void setup_gaia();
    virtual void setup_players(RGE_Player_Info*);
    virtual unsigned char new_random_game(RGE_Player_Info*);
    virtual void save(int);
    virtual void scenario_make_player(short, unsigned char, unsigned char,
                                      unsigned char, char*);
    virtual void scenario_make_map(int);
    virtual unsigned char load_scenario(char*, RGE_Player_Info*);
    virtual unsigned char load_scenario(RGE_Player_Info*);
    virtual void load_101(int, RGE_Player_Info&);
    virtual void load_102(int, RGE_Player_Info&);
    virtual void load_104(int, RGE_Player_Info&);
    virtual void load_105(int, RGE_Player_Info&);
    virtual void load_106(int, RGE_Player_Info&);
    virtual void load_107(int, RGE_Player_Info&);
    virtual void load_108(int, RGE_Player_Info&);
    virtual void load_110(int, RGE_Player_Info&);
    virtual void logStatus(void*, int);
    virtual ~RGE_Game_World();
    virtual void setup_player_colors(RGE_Player_Info&);
    virtual void setup_player_colors();
    unsigned char load_scenario(char*, RGE_Player_Info&);
};

unsigned char RGE_Game_World::load_scenario(char* name, RGE_Player_Info& info)
{
    char scenario_name[304];
    int version;
    int header_size;
    int file;
    void* buf;
    world_update_counter = 0;
    sprintf(scenario_name + 4, "%s%s", rge_base_game->prog_info->scenario_dir, name);
    if (name != 0) {
        file = rge_open(scenario_name + 4, 0x8000);
        if (file != -1) {
            rge_read_uncompressed(file, scenario_name, 4);
            if (*(int*)scenario_name == version_101) {
                this->load_101(file, info);
                this->setup_player_colors(info);
                return 1;
            }
            if (*(int*)scenario_name == version_102) {
                goto version2;
            }
            if (*(int*)scenario_name == version_103) {
                rge_read_uncompressed(file, &version, 4);
                if (version <= 0) {
                    goto version2;
                }
                buf = malloc(version);
                if (buf != 0) {
                    rge_read_uncompressed(file, buf, version);
                    free(buf);
                    goto version2;
                }
            } else {
                if (*(int*)scenario_name == version_104) {
                    this->load_104(file, info);
                    this->setup_player_colors(info);
                    return 1;
                }
                if (*(int*)scenario_name == version_105) {
                    this->load_105(file, info);
                    this->setup_player_colors(info);
                    return 1;
                }
                if (*(int*)scenario_name == version_106) {
                    this->load_106(file, info);
                    this->setup_player_colors(info);
                    return 1;
                }
                if (*(int*)scenario_name == version_107) {
                    this->load_107(file, info);
                    this->setup_player_colors(info);
                    return 1;
                }
                if (*(int*)scenario_name == version_108) {
                    this->load_108(file, info);
                    this->setup_player_colors(info);
                    return 1;
                }
                if (*(int*)scenario_name == version_109) {
                    goto version110;
                }
                if (*(int*)scenario_name == version_111) {
                    goto version110;
                }
                if (*(int*)scenario_name != version_110) {
                    goto close_failed;
                }
            }
close_failed:
            rge_close(file);
        }
    }
    return 0;

version2:
    this->load_102(file, info);
    this->setup_player_colors(info);
    return 1;

version110:
    this->load_110(file, info);
    this->setup_player_colors(info);
    return 1;
}
