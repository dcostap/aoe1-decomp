// do_command_resign — accepted_drift candidate (181B)
// VA: 00434EB0
// Reconstructed full behavior: if multiplayer, mark command player resigned, count all slots
// whose playerID matches the resigned player, and call player->vfunc+8 only once all matching
// slots are resigned; otherwise call directly. Best source is exact-size 181B with only a
// localized 12-byte positional / 10-byte edit drift: VC5 schedules `xor ecx; mov cl,[cmd+2]`
// after zeroing EDI/EBP and setting ESI=1, while original performs that independent comm-player
// load before zeroing EBP/setting ESI. From the store onward bytes are identical. Tried 10+
// variants around game local vs direct rge_base_game, int/uchar/volatile comm locals, comm zero
// before/after total initialization, split assignments, and raw byte-cast access; none improved
// beyond this localized scheduling difference. Proposed accepted_drift: behavior/calls/stack/
// memory effects are identical; only independent register setup order before first resigned[]
// store differs. ACCEPTED_DRIFT 2026-05-21 (Boss approved).
#include "../../include/game_globals.h"

#ifndef COMMAND_TU_CONTEXT
struct RGE_Command_Resign {
    unsigned char command;
    unsigned char player_id;
    unsigned char comm_player_id;
    unsigned char dropped;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char);
    virtual void do_resign(int dropped);
};

class RGE_Game_World {
public:
    char gap_00[0x40];
    RGE_Player** players;
};

class RGE_Command {
public:
    virtual ~RGE_Command() {}
    RGE_Game_World* world;
    void do_command_resign(RGE_Command_Resign* cmd);
};

class RGE_Base_Game {
public:
    char gap_00[0xA15];
    unsigned char resigned[16];
    int multiplayerGame();
    int playerID(int index);
};

extern RGE_Base_Game* rge_base_game;
#endif

void RGE_Command::do_command_resign(RGE_Command_Resign* cmd)
{
    if (rge_base_game->multiplayerGame()) {
        RGE_Base_Game* game = rge_base_game;
        int comm = cmd->comm_player_id;
        int total = 0; int resigned_count = 0; int i = 1;
        game->resigned[comm] = 1;
        do { if (rge_base_game->playerID(i) == cmd->player_id) { total++; if (rge_base_game->resigned[i]) resigned_count++; } i++; } while (i < 9);
        if (total != resigned_count) return;
        this->world->players[cmd->player_id]->do_resign(cmd->dropped);
        return;
    }
    this->world->players[cmd->player_id]->do_resign(cmd->dropped);
}
