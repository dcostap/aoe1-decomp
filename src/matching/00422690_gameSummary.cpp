static char game_summary_buf;

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();

    char* gameSummary();
};

char* RGE_Base_Game::gameSummary() {
    game_summary_buf = 0;
    return &game_summary_buf;
}
