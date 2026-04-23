extern "C" char* strcpy(char* dst, const char* src);

class TRIBE_Game {
public:
    char gap_0[0xE64];
    char save_game_name[260];

    void set_save_game_name(char* text);
};

void TRIBE_Game::set_save_game_name(char* text) {
    if (text != 0) {
        strcpy(this->save_game_name, text);
    } else {
        this->save_game_name[0] = 0;
    }
}
