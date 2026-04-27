// 0049C970 command_pause
// 152 bytes, __thiscall, TRIBE_Screen_Game method
// probe 2: check time guard, send chat, request_pause

#include <stdio.h>

class RGE_Base_Game;

extern RGE_Base_Game* rge_base_game;
extern void* comm;
extern const char* s_C__msdev_work_age1_x1_scr_game_c;
unsigned long debug_timeGetTime(const char* file, int line);
int RGE_Base_Game_singlePlayerGame(RGE_Base_Game* game);
int RGE_Base_Game_multiplayerGame(RGE_Base_Game* game);
void RGE_Base_Game_request_pause(RGE_Base_Game* game);
const char* TPanel_get_string(void* self, int id);
void TCommunications_Handler_SendChatMsgAll(void* handler, const char* msg);

class RGE_Base_Game {
public:
    char gap_00[0x1B0];
    unsigned int prog_mode;
};

class TRIBE_Screen_Game {
public:
    char gap_00[0x7C0];
    unsigned long field_7C0;

    void command_pause();
};

void TRIBE_Screen_Game::command_pause() {
    unsigned long t = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_game_c, 0x14F2);
    if (t - field_7C0 < 1000) {
        int single = RGE_Base_Game_singlePlayerGame(rge_base_game);
        if (single == 0) {
            return;
        }
    }
    field_7C0 = t;
    if (rge_base_game->prog_mode != 5) {
        int mp = RGE_Base_Game_multiplayerGame(rge_base_game);
        if (mp != 0) {
            char msg[256];
            const char* s = TPanel_get_string(this, 0xBF4);
            sprintf(msg + 4, s);
            TCommunications_Handler_SendChatMsgAll(comm, msg + 4);
        }
        RGE_Base_Game_request_pause(rge_base_game);
    }
}
