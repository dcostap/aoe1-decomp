class TPanel {
public:
    virtual void restart_sound_system();
};

class TRIBE_Screen_Game : public TPanel {
public:
    void restart_sound_system();
};

void TRIBE_Screen_Game::restart_sound_system() { TPanel::restart_sound_system(); }
