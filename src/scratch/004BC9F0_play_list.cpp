class TDigital_pl {
public:
    void play(void);
};

class TSound_Driver_pl {
public:
    void play_list(void);
    char gap_00[0x298];
    TDigital_pl* sounds[256];
    char gap_698[0x00];
    int num_sounds;
};

void TSound_Driver_pl::play_list(void) {
    int count = this->num_sounds;
    if (count <= 0) return;
    for (int i = 0; i < count; i++) {
        this->sounds[i]->play();
    }
}
