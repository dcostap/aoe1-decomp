class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[3940];
    char get_load_game_name_[1];

    char * get_load_game_name();
};
char * TRIBE_Game::get_load_game_name() { return this->get_load_game_name_; }
