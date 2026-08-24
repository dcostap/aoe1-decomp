#if !defined(SCR_GAME_TU_CONTEXT)
class TRIBE_Screen_Game {
public:
    void target_func(int p0);
    void set_redraw(int p);
};
#endif

void TRIBE_Screen_Game::set_redraw(int p) { this->target_func(p); }
