// 004706B0 RGE_Player::check_ally_group
// player.cpp lines 1468-1492
// Retry 2026-05-19/20 assigned pass:
// - Replaced stub with natural RGE_Player/RGE_Game_World model and relation/allied-victory loop.
// - Initial implementation reached 148/148 with 35.8108% positional; source used an ok flag/test block after relation/allied checks.
// - Rewrote failed relation/allied-victory path with `goto failed`, matching all calls/registers/stores and reducing diff to only 3 bytes (2.0270%).
// - /Ob0 flag probe: no change; removed.
// ACCEPTED_DRIFT 2026-05-19: approved localized behavior-equivalent loop back-edge drift.
// Original emits `cmp edi,ecx; jl loop; jmp done; xor bl,bl`; rebuilt emits
// `cmp edi,ecx; jge done; jmp loop; xor bl,bl`. Same compare operands, targets,
// BL state, count store, failure/final paths, calls, stack cleanup, and memory effects;
// only branch polarity/layout encoding differs.
#include "..\..\include\game_globals.h"

class RGE_Player;
class RGE_Game_World {
public:
    char gap_00[0x3C];
    short player_num;
    char gap_3E[2];
    RGE_Player** players;
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
    char gap_40[0x4A - 0x40];
    short id;
    char gap_4C[0x80 - 0x4C];
    unsigned char game_status;
    char gap_81[3];
    unsigned char* relations;
    char gap_88[0x104 - 0x88];
    unsigned char allied_victory;

    unsigned char relation(long playerId);
    unsigned char check_ally_group(long& count);
};

unsigned char RGE_Player::check_ally_group(long& count)
{
    long old = count;
    unsigned char ok = 1;

    if (this->game_status != 2) {
        count = 0;
        RGE_Game_World* world = this->world;
        int i = 1;
        if (world->player_num > 1) {
            do {
                if (this->relations[i] == 0) {
                    if (world->players[i]->relation(this->id) != 0)
                        goto failed;
                    if (this->world->players[i]->allied_victory == 0)
                        goto failed;
                }
                count++;
                i++;
                world = this->world;
            } while (i < world->player_num);
        }
    }

    goto done;

failed:
    ok = 0;

done:
    if (old >= 0 && count != old)
        ok = 0;

    return ok;
}
