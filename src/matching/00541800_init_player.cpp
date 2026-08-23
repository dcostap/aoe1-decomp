// RGE_Game_World::init_player
// VA: 00541800
// World.cpp:735-751
// 113 bytes, 18 diff bytes (15.93%)
// Loop bottom quirk: original uses `cmp si,[ebx]; jl` (16-bit compare),
// rebuilt uses `movsx edx,[ebx]; cmp esi,edx; jl` (32-bit compare + sign-ext).
// Same behavior, different loop comparison encoding.
// 5+ source forms tried. 6 relocations masked.

#include "../../include/world_scenario_context.h"

unsigned char RGE_Game_World::init_player(int fileHandle) {
    rge_read(fileHandle, &this->master_player_num, 2);

    if (this->master_player_num > 0) {
        this->master_players = (RGE_Master_Player**)calloc(this->master_player_num, 4);
        for (int i = 0; (short)i < this->master_player_num; i++) {
            unsigned char tempByte;
            rge_read(fileHandle, &tempByte, 1);
            this->init_player_type(fileHandle, (short)i, tempByte);
        }
    }
    return 1;
}
