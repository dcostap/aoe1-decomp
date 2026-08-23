#include "../../include/tribegam_context.h"

#if 0
class TRIBE_Screen_Game {
public:
    void game_mode_changed(int a, int b);
};

class RGE_Base_Game {
public:
    char gap_00[0x1B4];
    int field_1B4;
    int field_1B8;
    void set_game_mode(int a, int b);
};

class TRIBE_Game {
public:
    char gap_00[0x1B4];
    int field_1B4;
    int field_1B8;
    char gap_1BC[0xA68];
    TRIBE_Screen_Game* game_screen;

    void set_game_mode(int a, int b);
};
#endif

void TRIBE_Game::set_game_mode(int a, int b) {
    int old_mode = this->field_1B4;
    this->RGE_Base_Game::set_game_mode(a, b);
    if (this->game_screen != 0) {
        this->game_screen->game_mode_changed(old_mode, this->field_1B4);
    }
}
