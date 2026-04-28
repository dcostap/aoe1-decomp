// VA: 004E4500 TribeInformationAIModule::loadUnitHistory()
// Source: taiinfmd.cpp lines 8454-8470
// Size: 149 bytes, __thiscall, ret
// Returns void
// MATCH (0% diff, 8 relocations masked)
//
// Loads unit history from "learn\\{player_name}.uh" or "learn\\Default.uh"
// Key: char[256] local buffer (not 260) for exact stack frame size

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

// File I/O helper functions
extern "C" int rge_open(const char* filename, int flags);
extern "C" void rge_read(int fd, void* buf, int size);
extern "C" int rge_close(int fd);

struct TribeInformationAIModule {
    char _gap[0x100];
    void* md;       // +0x100
    int map_w;      // +0x104
    int map_h;      // +0x108

    void loadUnitHistory();
};

void TribeInformationAIModule::loadUnitHistory() {
    char historyFileName[256];

    RGE_Game_Info* game_info = rge_base_game->player_game_info;

    if (game_info) {
        sprintf(historyFileName, "learn\\%s.uh", game_info->get_current_player_name());
    } else {
        strcpy(historyFileName, "learn\\Default.uh");
    }

    int fd = rge_open(historyFileName, 0x8000);
    if (fd != -1) {
        rge_read(fd, (char*)this + 0xFF64, 0x2C);
        rge_close(fd);
    }
}
