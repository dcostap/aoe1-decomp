void __cdecl operator delete(void* ptr);

#if !defined(SCR_GAME_TU_CONTEXT)
class TDigital {
public:
    ~TDigital();
};

class TPanel {
public:
    void stop_sound_system(void);
};

class TRIBE_Screen_Game : public TPanel {
public:
    char gap_04[0x7B8];
    TDigital* sound_system;

    void stop_sound_system(void);
};
#endif

void TRIBE_Screen_Game::stop_sound_system(void) {
    TDigital* sound_system = this->sound_system;

    if (sound_system != 0) {
        sound_system->~TDigital();
        operator delete(sound_system);
        this->sound_system = 0;
    }
    TPanel::stop_sound_system();
}
