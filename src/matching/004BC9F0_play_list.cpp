#ifndef SOUNDDRV_CANONICAL_TU
class TDigital {
public:
    void play(void);
};

class TSound_Driver {
public:
    void play_list(void);
    char gap_00[0x298];
    TDigital* sound_play_list[256];
    int play_list_count;
};
#endif

void TSound_Driver::play_list(void) {
    int i;
    TDigital** sound;

    i = 0;
    if (0 < this->play_list_count) {
        sound = this->sound_play_list;
        do {
            (*sound)->play();
            i = i + 1;
            sound = sound + 1;
        } while (i < this->play_list_count);
    }
}
