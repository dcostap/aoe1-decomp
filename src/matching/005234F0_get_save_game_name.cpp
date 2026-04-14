class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[3680];
    char get_save_game_name_[1];

    char * get_save_game_name();
};
char * TRIBE_Game::get_save_game_name() { return this->get_save_game_name_; }
