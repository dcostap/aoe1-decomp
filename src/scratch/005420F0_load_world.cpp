// VA: 005420F0 RGE_Game_World::load_world
// Attempt log:
// 1: direct offset-based reconstruction from packet/decompiler.
// 2: preserved file handle in f and reused incoming file parameter as 1-byte saved game-state slot; fixes prologue/early read sequence.
// 3: current same-size 614B, exact until after player_num read. Remaining broad mismatch is register allocation/topology: VC5 original keeps player_num in EBX and player_time_delta cursor in EBP, rebuilt chooses the inverse and uses EBX for subsequent player loop indices; later also had unified_vis_map offset fixed to +8DC8.
// 4: tried char* cursor with p += 4, delaying player_num assignment until after direct rge_read, splitting i initialization, and positive `0 < *player_num` spelling; no improvement, first mismatch stayed offset 190.
// left in scratch: same-size broad register-allocation/control-flow topology mismatch from player_num/player_time_delta cursor onward; not accepted_drift-safe.

extern "C" void __cdecl rge_read(int, void*, int);
extern "C" void* __cdecl calloc(unsigned int, unsigned int);

struct RGE_Map { void load_map(int); char gap[0x8dc8]; void* unified_vis_map; };
struct RGE_Unified_Visible_Map { void suppress_updates(int); };
struct RGE_Player { void load_info(int); };
struct RGE_Base_Game { int singlePlayerGame(); float get_game_speed(); };
extern RGE_Base_Game* rge_base_game;
extern float save_game_version;

class RGE_Game_World {
public:
    unsigned char load_world(int file);
    void initializePathingSystem();
    void update_mutual_allies();
};

unsigned char RGE_Game_World::load_world(int file)
{
    char* self = (char*)this;
    int local_4;
    int count;
    unsigned long* p;
    short* player_num;
    int f = file;

    *(unsigned char*)(self + 0x1d) = 2;
    *(unsigned char*)(self + 0x1e) = 0;
    rge_read(f, self + 0x04, 4);
    rge_read(f, self + 0x08, 4);
    rge_read(f, self + 0x0c, 4);
    rge_read(f, self + 0x84, 4);
    rge_read(f, self + 0x10, 4);
    rge_read(f, self + 0x18, 4);
    rge_read(f, self + 0x1c, 1);
    rge_read(f, self + 0x68, 4);
    rge_read(f, self + 0x6c, 4);
    rge_read(f, self + 0x78, 4);
    rge_read(f, self + 0x7c, 2);
    player_num = (short*)(self + 0x3c);
    rge_read(f, player_num, 2);
    rge_read(f, &file, 1);
    rge_read(f, self + 0xa4, 4);
    rge_read(f, self + 0xa8, 4);
    rge_read(f, self + 0xac, 4);
    rge_read(f, self + 0xb0, 4);

    p = (unsigned long*)(self + 0xb4);
    count = 9;
    do {
        rge_read(f, p, 4);
        p++;
        count--;
    } while (count != 0);

    int i = 0;
    *(int*)(self + 0x14) = 0;
    ((RGE_Map*)*(int*)(self + 0x28))->load_map(f);
    this->initializePathingSystem();
    *(int*)(self + 0xfc) = -1;
    if (0 < *player_num) {
        *(void**)(self + 0x40) = calloc(4, *player_num);
        if (0 < *player_num) {
            void (__stdcall *create_player)(int, int, int) = *(void (__stdcall **)(int, int, int))(*(int*)self + 0x34);
            do {
                rge_read(f, &local_4, 1);
                create_player(f, local_4, i);
                i++;
            } while (i < *player_num);
        }
    }

    this->update_mutual_allies();
    ((RGE_Unified_Visible_Map*)((RGE_Map*)*(int*)(self + 0x28))->unified_vis_map)->suppress_updates(1);
    i = 0;
    if (0 < *player_num) {
        do {
            ((RGE_Player**)*(int*)(self + 0x40))[i]->load_info(f);
            i++;
        } while (i < *player_num);
    }
    ((RGE_Unified_Visible_Map*)((RGE_Map*)*(int*)(self + 0x28))->unified_vis_map)->suppress_updates(0);
    (*(void (__stdcall **)(int, RGE_Game_World*))(*(int*)self + 0xf4))(f, this);

    if (save_game_version < *(float*)0x00577A10) {
        *(int*)(self + 0x100) = -1;
    } else {
        rge_read(f, self + 0x100, 4);
    }
    if (rge_base_game->singlePlayerGame()) {
        *(float*)(self + 0x18) = rge_base_game->get_game_speed();
    }
    *(unsigned char*)(self + 0x1d) = (unsigned char)file;
    return 1;
}
