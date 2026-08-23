#include "../../include/tribegam_context.h"

#if 0
class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[3680];
    char get_save_game_name_[1];

    char * get_save_game_name();
};
#endif
char * TRIBE_Game::get_save_game_name() { return this->save_game_name; }
