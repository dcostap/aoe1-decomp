#if !defined(SCR_GAME_TU_CONTEXT)
class TPanel {
public:
    virtual int restart_sound_system();
};

class TRIBE_Screen_Game : public TPanel {
protected:
    virtual int restart_sound_system();
};
#endif

int TRIBE_Screen_Game::restart_sound_system() { return TPanel::restart_sound_system(); }
