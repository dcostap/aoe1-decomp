class TDigital_pl {
public:
    void play(void);
};

class TSound_Driver_pl {
public:
    void play_list(void);
    char gap_00[0x298];
    TDigital_pl* sounds[256];
    int num_sounds;
};

void TSound_Driver_pl::play_list(void) {
    int i;
    TDigital_pl** sound;

    i = 0;
    if (0 < this->num_sounds) {
        sound = this->sounds;
        do {
            (*sound)->play();
            i = i + 1;
            sound = sound + 1;
        } while (i < this->num_sounds);
    }
}
