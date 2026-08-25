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

#ifndef TAIINFMD_PREFIX_CONTEXT
#define TAIINFMD_INFO_CONTEXT "../../include/information_dropsites_context.h"
#include TAIINFMD_INFO_CONTEXT
#undef TAIINFMD_INFO_CONTEXT
#endif

// File I/O helper functions
extern "C" void rge_read(int fd, void* buf, int size);
extern "C" int rge_close(int fd);

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
