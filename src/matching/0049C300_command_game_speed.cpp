// VA: 0049C300 command_game_speed (571B)
// scr_game.cpp: 5114-5173
// EH frame (/GX)
//
// Baseline reconstruction: the handler rate-limits the command, reads the
// world's current speed, selects the next speed from the period ladder, then
// broadcasts/queues/applies that speed.  The world and screen fields below are
// named owners for the offsets proved by the packet; the local `new_speed` is
// intentionally allowed to share the first dword of `msg` after its last use.
//
// Attempt log (sa984486de_r1):
// - baseline scaffold had only the debug-time call and a placeholder field;
//   it emitted 30 bytes and one wrong call.
// - typed world/screen reconstruction recovered the 0x108 frame, all 11 calls,
//   and the speed ladder basin (439 bytes, 383 differing).
// - reversing the parameter arms to put the 1/1.5/developer increase path
//   inline and the 16/8/4/2/1.5 decrease path late recovered exact size/CFG;
//   only the two message-buffer LEA displacements remained.
// - separate/scoped local declaration and lifetime/order probes were codegen
//   duplicates; the original stack map proves new_speed shares msg[0].
// - the explicit Speed_Message union plus four-byte tail models that proven
//   local overlay and reached an exact 571-byte match.  Canonical TPanel /
//   TScreenPanel inheritance was then restored without codegen movement.
// - removed the stale per-function /GX response file; default /O2 /Oy remains
//   exact.  Final source is retained in scratch until post-move validation.

#include <stdio.h>

extern unsigned long debug_timeGetTime(const char* file, int line);

class RGE_Base_Game {
public:
    char gap_00[0x1B0];
    int prog_mode;

    int singlePlayerGame();
    int gameDeveloperMode();
    int multiplayerGame();
    void set_game_speed(float speed);
};

class TRIBE_Command {
public:
    void command_game_speed(float speed);
};

class RGE_Game_World {
public:
    char gap_00[0x18];
    float game_speed;
    char gap_1C[0x3C];
    TRIBE_Command* commands;
};

class TCommunications_Handler {
public:
    void SendChatMsgAll(const char* msg);
};

extern RGE_Base_Game* rge_base_game;
extern TCommunications_Handler* comm;

// The original stack map proves that the speed value occupies msg[0] before
// the message text is written.  Keep that observed lifetime overlay explicit
// rather than adding a fourth independent local slot.
struct Speed_Message {
    union {
        float new_speed;
        char msg[256];
    };
    char pad[4];
};

class TPanel {
public:
    virtual ~TPanel();
    const char* get_string(int id);
};

class TScreenPanel : public TPanel {
public:
    char gap_04[0x474];
};

class TRIBE_Screen_Game : public TScreenPanel {
public:
    char gap_478[0x13C];
    RGE_Game_World* world;
    char gap_5B8[0x204];
    unsigned long last_game_speed_time;

    void command_game_speed(int param_1);
};

void TRIBE_Screen_Game::command_game_speed(int param_1) {
    float cur_speed;
    Speed_Message speed_message;

    unsigned long t = debug_timeGetTime(
        "C:\\msdev\\work\\age1_x1\\scr_game.cpp", 0x13FE);
    if (t - this->last_game_speed_time < 1000) {
        if (rge_base_game->singlePlayerGame() == 0) {
            return;
        }
    }

    this->last_game_speed_time = t;
    if (rge_base_game->prog_mode != 5) {
        cur_speed = 0.0f;
        speed_message.new_speed = this->world->game_speed;

        if (param_1 != 0) {
            if (speed_message.new_speed == 1.0f) {
                cur_speed = 1.5f;
            } else if (speed_message.new_speed == 1.5f) {
                cur_speed = 2.0f;
            } else {
                if (rge_base_game->singlePlayerGame() != 0 &&
                    rge_base_game->gameDeveloperMode() != 0) {
                    if (speed_message.new_speed == 2.0f) {
                        cur_speed = 4.0f;
                    } else if (speed_message.new_speed == 4.0f) {
                        cur_speed = 8.0f;
                    } else if (speed_message.new_speed == 8.0f) {
                        cur_speed = 16.0f;
                    }
                }
            }
        } else {
            if (speed_message.new_speed == 16.0f) {
                cur_speed = 8.0f;
            } else if (speed_message.new_speed == 8.0f) {
                cur_speed = 4.0f;
            } else if (speed_message.new_speed == 4.0f) {
                cur_speed = 2.0f;
            } else if (speed_message.new_speed == 2.0f) {
                cur_speed = 1.5f;
            } else if (speed_message.new_speed == 1.5f) {
                cur_speed = 1.0f;
            }
        }

        if (cur_speed != 0.0f) {
            if (rge_base_game->multiplayerGame() != 0) {
                const char* text = this->get_string(0xBF3);
                sprintf(speed_message.msg + 4, text);
                comm->SendChatMsgAll(speed_message.msg + 4);
            }

            this->world->commands->command_game_speed(cur_speed);
            if (rge_base_game->singlePlayerGame() != 0) {
                rge_base_game->set_game_speed(cur_speed);
            }
        }
    }
}
