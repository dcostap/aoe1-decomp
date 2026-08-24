// VA: 0049C970 command_pause (152B)
// scr_game.cpp: 5361-5378
// void __thiscall TRIBE_Screen_Game::command_pause(void)

#include <stdio.h>

#if !defined(SCR_GAME_TU_CONTEXT)
extern unsigned long debug_timeGetTime(const char* file, int line);

class RGE_Base_Game {
public:
    char pad_00[0x1B0];
    unsigned int prog_mode;             // +0x1B0

    int singlePlayerGame();
    int multiplayerGame();
    void request_pause();
};

class TCommunications_Handler {
public:
    void SendChatMsgAll(const char* msg);
};

extern RGE_Base_Game* rge_base_game;
extern TCommunications_Handler* comm;

class TRIBE_Screen_Game {
public:
    char pad_00[0x7C0];
    unsigned long last_pause_time;      // +0x7C0

    void command_pause();
    const char* get_string(int id);
};
#endif

void TRIBE_Screen_Game::command_pause() {
    char msg[256];
    unsigned long t = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\scr_game.cpp", 0x14F2);

    if (t - last_pause_time < 1000) {
        if (rge_base_game->singlePlayerGame() == 0) {
            return;
        }
    }

    last_pause_time = t;

    if (rge_base_game->prog_mode != 5) {
        if (rge_base_game->multiplayerGame() != 0) {
            const char* s = get_string(0xBF4);
            sprintf(msg, s);
            comm->SendChatMsgAll(msg);
        }
        rge_base_game->request_pause();
    }
}
