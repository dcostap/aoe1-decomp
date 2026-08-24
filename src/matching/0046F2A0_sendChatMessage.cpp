// VA: 0046F2A0 RGE_Player::sendChatMessage (251B)
// PDB source: player.cpp, lines 706-729
// Baseline reconstruction: format the cdecl member's varargs message, then
// send it to the requested player and optionally to the local player's id.
// Attempt log:
// - Corrected the ABI to a cdecl member with stack-passed this and varargs.
// - Recovered the 1025-byte formatting buffer and named playerID results.
// - The named result locals reproduce the original saved-register coloring;
//   direct member ownership and the typed world/command/communications chain
//   remain period-plausible.
// Main-agent audit replaced raw vptr storage with canonical player/world/
// command/base-game virtual surfaces; emitted code remains exact.

#include <string.h>

extern "C" int __cdecl vsprintf(char* buffer, const char* format, void* argptr);

#ifndef PLAYER_GROUPED_TU
class TCommunications_Handler {
public:
    void SendChatMsg(unsigned int player, unsigned int to, char* text);
};

class RGE_Command {
public:
    virtual ~RGE_Command();
    char gap_04[0x10];
    TCommunications_Handler* com_hand;
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x54];
    RGE_Command* command;
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    int numberPlayers();
    int playerID(int player);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    int computerPlayerValue;
    int pathingAttemptCapValue;
    int pathingDelayCapValue;
    int currentUpdatePathingAttemptsValue;
    long checksum;
    long position_checksum;
    long action_checksum;
    unsigned char checksum_created_this_update;
    unsigned char pad_21;
    short master_object_num;
    void* master_objects;
    void* objects;
    void* sleeping_objects;
    void* doppleganger_objects;
    void* victory_conditions;
    void* visible;
    RGE_Game_World* world;
    void* doppleganger_creator;
    char* name;
    unsigned char type;
    unsigned char pad_49;
    short id;

    void __cdecl sendChatMessage(int player, int mode, char* message, ...);
};
#endif

#define rge_base_game (*(RGE_Base_Game**)0x62C574)

void __cdecl RGE_Player::sendChatMessage(int player, int mode, char* message, ...)
{
    char textOut[1025];

    vsprintf(textOut, message, (&message) + 1);

    int i;

    if (strlen(textOut) != 0) {
        for (i = 1; i <= rge_base_game->numberPlayers(); ++i) {
            int playerID = rge_base_game->playerID(i);
            if (playerID == player) {
                this->world->command->com_hand->SendChatMsg(
                    this->id, i, textOut);
            }
        }

        if (mode == 1 && player != this->id) {
            for (i = 1; i <= rge_base_game->numberPlayers(); ++i) {
                int playerID = rge_base_game->playerID(i);
                if (playerID == this->id) {
                    this->world->command->com_hand->SendChatMsg(
                        this->id, i, textOut);
                }
            }
        }
    }
}
