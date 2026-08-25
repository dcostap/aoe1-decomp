// VA: 0046F7A0 RGE_Player::scenario_postload(int, long*, float)
// PDB source: player.cpp, lines 879-1016
//
// Canonical Player and World ownership comes from player_context.h.
// The executable reads the allied-victory field through one byte local.
// This byte type preserves the exact output address and malformed-load faults.
// Natural version literals preserve the original rdata ownership and x87 order.
// The Player surface keeps scenario_postsave virtual. This puts load_victory
// at the executable's +0xF0 slot.
//
// Exact finish:
// - An unsigned-byte player_count removed the old short-byte overlay.
// - The 1.06 literal moved the LOS reset after FCOMP, as in the executable.
// - The other version literals stayed exact and removed unused DAT aliases.
// - /GX and function-scope loop-index tests were codegen-neutral and removed.
// - The reviewed context header stayed exact after its virtual-slot correction.

#include <stdlib.h>
#include "../player_tu_context.h"

extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);
extern "C" void __cdecl free(void* block);

void rge_read(int file, void* buffer, int size);

#ifndef PLAYER_GROUPED_TU
class RGE_Base_Game {
public:
    char gap_000[0x1B0];
    int prog_mode;

    int playerID(int player);
    int playerTeam(int player);
};

class TCommunications_Handler {
public:
    int GetPlayerHumanity(int player);
};

extern RGE_Base_Game* rge_base_game;
extern TCommunications_Handler* comm;
#endif

void RGE_Player::scenario_postload(int file, long* data, float version)
{
    int file_handle = file;
    short has_team;
    short count;
    unsigned char player_count;
    int has_human_team;
    unsigned char temp_byte;

    rge_read(file_handle, &has_team, 2);
    if (has_team > 0) {
        char* name = (char*)calloc((int)has_team, 1);
        rge_read(file_handle, name, (int)has_team);
        if (this->name == 0) {
            this->name = name;
        }
        else {
            free(name);
        }
    }

    rge_read(file_handle, &this->view_x, 4);
    rge_read(file_handle, &this->view_y, 4);
    rge_read(file_handle, &this->map_x, 2);
    rge_read(file_handle, &this->map_y, 2);

    has_human_team = 0;
    if (rge_base_game->prog_mode != 7) {
        for (int player = 1; player < 9; ++player) {
            if (rge_base_game->playerID(player) == this->id &&
                (comm->GetPlayerHumanity(player) == 2 ||
                 comm->GetPlayerHumanity(player) == 4)) {
                if (rge_base_game->playerTeam(player - 1) > 1) {
                    has_human_team = 1;
                }
                break;
            }
        }
    }

    if (version > 1.0) {
        rge_read(file_handle, &player_count, 1);
        if (has_human_team == 0) {
            this->allied_victory = player_count;
        }
    }

    this->allied_LOS_Enable = 0;
    if (version <= 1.06 && this->attribute_num > 0) {
        rge_read(file_handle, this->attributes, 0x74);
    }

    rge_read(file_handle, &count, 2);
    short i = 0;
    if (count > 0) {
        do {
            rge_read(file_handle, &temp_byte, 1);
            if (has_human_team == 0) {
                short player_id;
                if (data != 0) {
                    player_id = (short)data[i];
                }
                else {
                    player_id = i;
                }
                if (player_id < this->world->player_num && player_id >= 0) {
                    this->relations[player_id] = temp_byte;
                    if (player_id == 0) {
                        this->unitDiplomacy[0] = 0;
                    }
                    else if (player_id == this->id) {
                        this->unitDiplomacy[player_id] = 1;
                    }
                    else if (temp_byte == 0) {
                        this->unitDiplomacy[player_id] = 2;
                    }
                    else if (temp_byte == 1) {
                        this->unitDiplomacy[player_id] = 3;
                    }
                    else {
                        this->unitDiplomacy[player_id] = 4;
                    }
                }
            }
            ++i;
        } while (i < count);
    }

    if (version >= 1.08) {
        rge_read(file_handle, this->unitDiplomacy, 0x24);
    }

    RGE_Victory_Conditions* victory = this->victory_conditions;
    if (victory != 0) {
        delete victory;
    }

    if (version >= 1.09) {
        this->load_victory(file_handle, data, 1);
    }
    else {
        this->load_victory(file_handle, data, 0);
    }
}
