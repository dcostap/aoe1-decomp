// VC5 emitted the same inline strcpy/strlen-style expansion here as the sibling scenario string setters.
// Keep the null path explicit so the short-circuit and copy expansion stay aligned with the original bytes.

#include <string.h>

class TRIBE_Game {
public:
    char gap_000[0xF68];
    char load_game_name[260];

    void set_load_game_name(char* param_1);
};

void TRIBE_Game::set_load_game_name(char* param_1) {
    if (param_1 != 0) {
        strcpy(this->load_game_name, param_1);
        return;
    }

    this->load_game_name[0] = 0;
}
