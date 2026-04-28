// VA: 004D8270 TribeInformationAIModule::initialize()
// Source: taiinfmd.cpp lines 569-581
// Size: 143 bytes, __thiscall, ret
// Returns 1 (always)
// MATCH (0% diff, 6 relocations masked)
// Key: extern RGE_Base_Game* rge_base_game for A1 encoding;
//      (char*)this + 0xFF90 for buffer (no huge struct gap);
//      inlined get_current_player_name() in sprintf arg for 2nd call

#include <stdio.h>
#include <string.h>

struct RGE_Game_Info {
    char* get_current_player_name();
};

struct RGE_Base_Game {
    char _pad[4];
    RGE_Game_Info* player_game_info;  // +4
};

extern RGE_Base_Game* rge_base_game;  // 0x62C574

struct TribeInformationAIModule {
    char _gap[0x100];
    void* md;       // +0x100
    int map_w;      // +0x104
    int map_h;      // +0x108

    int initialize();
};

int TribeInformationAIModule::initialize() {
    // Pointer chain: md->field_F0->field_3C->field_28 = terrain
    void* terrain = *(void**)(*(char**)(*(char**)((char*)this->md + 0xF0) + 0x3C) + 0x28);
    this->map_w = *(int*)((char*)terrain + 8);
    this->map_h = *(int*)((char*)terrain + 0x0C);

    // Get player game info from global
    RGE_Game_Info* game_info = rge_base_game->player_game_info;

    // Check if player name exists
    if (game_info->get_current_player_name()) {
        // Inline call in sprintf argument forces VC5 to call get_current_player_name again
        sprintf((char*)this + 0xFF90, "learn\\%s.uh", game_info->get_current_player_name());
    } else {
        strcpy((char*)this + 0xFF90, "learn\\Default.uh");
    }

    return 1;
}
