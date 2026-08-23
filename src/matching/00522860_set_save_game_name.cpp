extern "C" char* strcpy(char* dst, const char* src);

#include "../../include/tribegam_context.h"

#if 0
class TRIBE_Game {
public:
    char gap_0[0xE64];
    char save_game_name[260];

    void set_save_game_name(char* text);
};
#endif

void TRIBE_Game::set_save_game_name(char* text) {
    if (text != 0) {
        strcpy(this->save_game_name, text);
    } else {
        this->save_game_name[0] = 0;
    }
}
