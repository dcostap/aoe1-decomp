// RGE_Game_World::setup_players
// VA: 005424F0, World.cpp:1163-1169
// Status: active scratch
// FLAGS: config/flags/005424F0_setup_players.rsp

extern "C" void* __cdecl operator_new(unsigned long size);

struct RGE_Player_Info {
    char name[9][65];      // +0x00 (0x249 bytes)
    char type[9];          // +0x249
    char tribe[9];         // +0x252
    char gap_25B;
    short color[9];        // +0x25C
    char gap_26E[2];
    long player_id_hash[9]; // +0x270
    short player_num;      // +0x294
    char gap_296[2];
    char* scenario;        // +0x298
    void* map_info;        // +0x29C
    short map_type;        // +0x2A0
    short map_width;       // +0x2A2
    short map_height;      // +0x2A4
    short ai_info;         // +0x2A6
    unsigned char campaign; // +0x2A8
    char gap_2A9[3];
};

struct RGE_Game_World;

struct RGE_Player {
    virtual ~RGE_Player();
    RGE_Player(RGE_Game_World* world, RGE_Player* master, short idx, const char* name, unsigned char tribe, int flag);
    char gap_04[0x21C];
};

struct RGE_Game_World {
    char gap_00[0x3C];
    short player_num;          // +0x3C
    char gap_3E[0x02];
    void* players;             // +0x40
    char gap_44[0x04];
    void* master_players;      // +0x48

    void setup_players(RGE_Player_Info& info);
};

void RGE_Game_World::setup_players(RGE_Player_Info& info) {
    short index = 1;

    if (player_num > 1) {
        do {
            if (info.type[index - 1] != -1) {
                RGE_Player* player = new RGE_Player(this,
                    ((RGE_Player**)master_players)[info.tribe[index - 1]],
                    index, info.name[index - 1],
                    info.tribe[index - 1], 1);
                ((RGE_Player**)players)[index] = player;
            }
            index++;
        } while (index < player_num);
    }
}
