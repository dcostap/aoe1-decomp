#if !defined(SCR_GAME_TU_CONTEXT)
class TPanel {
public:
    enum RedrawMode { RedrawNormal = 0 };
    virtual void set_redraw(RedrawMode p);
};

class TRIBE_Screen_Game : public TPanel {
public:
    void target_func(int p0);
    virtual void set_redraw(TPanel::RedrawMode p);
};
#endif

// The override delegates to TPanel's redraw slot.
void TRIBE_Screen_Game::set_redraw(TPanel::RedrawMode p) {
    this->TPanel::set_redraw(p);
}
