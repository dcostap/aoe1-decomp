// VA: 0049C920 TRIBE_Screen_Game::command_outline (56 B)
// PDB source: scr_game.cpp lines 5333-5355

#if !defined(SCR_GAME_TU_CONTEXT)
class RGE_Base_Game {
public:
    char gap_00[0x50];
    unsigned char outline_type;
};

extern "C" {
extern RGE_Base_Game* rge_base_game;
}

class TRIBE_Screen_Game {
public:
    void command_outline();
};
#endif

void TRIBE_Screen_Game::command_outline() {
    RGE_Base_Game* game;
    unsigned char t;

    game = rge_base_game;
    t = game->outline_type;
    switch (t) {
    case 0:
    case 3:
        t = 2;
        break;
    case 2:
        t = 1;
        break;
    case 1:
        t = 0;
        break;
    }
    game->outline_type = t;
}
