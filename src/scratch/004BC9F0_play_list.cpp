class TDigital_pl {
public:
    void play(void);
};

class TSound_Driver_pl {
public:
    void play_list(void);
    char gap_00[0x298];
    TDigital_pl* sound_play_list[256];
    int play_list_count;
};

void TSound_Driver_pl::play_list(void) {
    int count = this->play_list_count;
    if (count <= 0) {
        return;
    }

    TDigital_pl** pp = this->sound_play_list;
    int i = 0;
    do {
        (*pp)->play();
        ++i;
        ++pp;
    } while (i < count);
}
