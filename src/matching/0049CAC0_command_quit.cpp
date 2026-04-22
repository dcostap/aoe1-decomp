class TCommunications_Handler {
public:
    void SendIResignMsg();
    void GameOver();
};

class TRIBE_Game {
public:
    void do_game_over();
};

extern TCommunications_Handler* comm;
extern TRIBE_Game* rge_base_game;

class TRIBE_Screen_Game {
public:
    void command_quit();
};

void TRIBE_Screen_Game::command_quit() {
    comm->SendIResignMsg();
    comm->GameOver();
    rge_base_game->do_game_over();
}
