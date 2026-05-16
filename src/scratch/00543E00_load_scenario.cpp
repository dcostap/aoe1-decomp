// VA: 00543E00 RGE_Game_World::load_scenario
// Attempt log:
// initial natural version-chain reconstruction from packet.
// tried direct 4-byte version comparisons against packet globals and immediate return tails after each virtual load/post_load pair.
// modeled 1.03 extra header-size read/malloc/read/free path and failure close path.
// used local stack buffer shaped as scenario_name[300] plus int locals; check still emits only 544-byte .text vs original 642, so no positional diff.
// tried vtable padding so load variants land at +0x7c..+0x98 and post_load at +0xa8.
// left in scratch: behavior/control flow broadly understood, but rebuilt is 98 bytes short; not accepted_drift-safe.

extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" int __cdecl rge_open(char*, int);
extern "C" void __cdecl rge_read_uncompressed(int, void*, int);
extern "C" void* __cdecl malloc(unsigned int);
extern "C" void __cdecl free(void*);
extern "C" void __cdecl rge_close(int);

struct RGE_Base_Game { char gap[0xc]; char* path; };
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

struct RGE_Player_Info {};
class RGE_Game_World {
public:
#define VPAD(n) virtual void v##n();
    VPAD(0) VPAD(1) VPAD(2) VPAD(3) VPAD(4) VPAD(5) VPAD(6) VPAD(7)
    VPAD(8) VPAD(9) VPAD(10) VPAD(11) VPAD(12) VPAD(13) VPAD(14) VPAD(15)
    VPAD(16) VPAD(17) VPAD(18) VPAD(19) VPAD(20) VPAD(21) VPAD(22) VPAD(23)
    VPAD(24) VPAD(25) VPAD(26) VPAD(27) VPAD(28) VPAD(29) VPAD(30)
#undef VPAD
    virtual void load_101(int, RGE_Player_Info&);
    virtual void load_102(int, RGE_Player_Info&);
    virtual void load_104(int, RGE_Player_Info&);
    virtual void load_105(int, RGE_Player_Info&);
    virtual void load_106(int, RGE_Player_Info&);
    virtual void load_107(int, RGE_Player_Info&);
    virtual void load_108(int, RGE_Player_Info&);
    virtual void load_110(int, RGE_Player_Info&);
#define VPAD2(n) virtual void w##n();
    VPAD2(39) VPAD2(40) VPAD2(41)
#undef VPAD2
    virtual void post_load(RGE_Player_Info&);
    unsigned char load_scenario(char*, RGE_Player_Info&);
};

unsigned char RGE_Game_World::load_scenario(char* name, RGE_Player_Info& info)
{
    char scenario_name[300];
    int version;
    int header_size;
    int file;
    void* buf;
    world_update_counter = 0;
    sprintf(scenario_name + 4, "%s%s", rge_base_game->path + 0xc17, name);
    if (name == 0) return 0;
    file = rge_open(scenario_name + 4, 0x8000);
    if (file == -1) return 0;
    rge_read_uncompressed(file, scenario_name, 4);
    if (*(int*)scenario_name == version_101) {
        this->load_101(file, info); this->post_load(info); return 1;
    }
    if (*(int*)scenario_name != version_102) {
        if (*(int*)scenario_name == version_103) {
            rge_read_uncompressed(file, &version, 4);
            if (version > 0) {
                buf = malloc(version);
                if (buf == 0) { rge_close(file); return 0; }
                rge_read_uncompressed(file, buf, version);
                free(buf);
            }
        } else if (*(int*)scenario_name == version_104) {
            this->load_104(file, info); this->post_load(info); return 1;
        } else if (*(int*)scenario_name == version_105) {
            this->load_105(file, info); this->post_load(info); return 1;
        } else if (*(int*)scenario_name == version_106) {
            this->load_106(file, info); this->post_load(info); return 1;
        } else if (*(int*)scenario_name == version_107) {
            this->load_107(file, info); this->post_load(info); return 1;
        } else if (*(int*)scenario_name == version_108) {
            this->load_108(file, info); this->post_load(info); return 1;
        } else if (*(int*)scenario_name == version_109 || *(int*)scenario_name == version_110 || *(int*)scenario_name == header_size) {
            this->load_110(file, info); this->post_load(info); return 1;
        } else { rge_close(file); return 0; }
    }
    this->load_102(file, info); this->post_load(info); return 1;
}
