#if !defined(SCR_GAME_TU_CONTEXT)
class TPanel {
public:
    enum RedrawMode { RedrawNormal = 0 };
};

class TRIBE_Screen_Game {
public:
    void target_func(int p0);
    virtual void set_redraw(TPanel::RedrawMode p);
};
#endif

void TRIBE_Screen_Game::set_redraw(TPanel::RedrawMode p) { this->target_func(p); }
