// VA: 0049CAC0 TRIBE_Screen_Game::command_quit (33B)
// PDB source: scr_game.cpp lines 5411-5416
// Sends resign message, ends game, triggers game over
#include "..\..\include\game_globals.h"

struct TCommunications_Handler {
    void SendIResignMsg();
    void GameOver();
};

struct TRIBE_Game {
    void do_game_over();
};

extern TCommunications_Handler* comm;

struct TRIBE_Screen_Game {
    void command_quit();
};

void TRIBE_Screen_Game::command_quit() {
    comm->SendIResignMsg();
    comm->GameOver();
    ((TRIBE_Game*)rge_base_game)->do_game_over();
}
