// VA: 0049C540 TRIBE_Screen_Game::command_group (36 B)
// PDB source: scr_game.cpp lines 5179-5183
// Exact match. Key: declare get_player() with no params, group_objects(int) with its
// real parameter. Chained call get_player()->group_objects(-1) prevents VC5 tail-call
// optimization (E8 call vs E9 jmp) compared to get_player(-1)->group_objects().

#if !defined(SCR_GAME_TU_CONTEXT)
class RGE_Base_Game {
public:
    int get_paused(void);
    class RGE_Player* get_player(void);
};

class RGE_Player {
public:
    int group_objects(int group);
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Screen_Game {
public:
    void command_group(void);
};
#endif

void TRIBE_Screen_Game::command_group(void) {
    if (rge_base_game->get_paused() == 0) {
        rge_base_game->get_player()->group_objects(-1);
    }
}
