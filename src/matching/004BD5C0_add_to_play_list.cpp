class TDigital;

class TSound_Driver {
public:
    char gap_00[0x01];
    unsigned char mute;

    int add_to_play_list(TDigital* digital);
};

class TDigital {
public:
    TSound_Driver* sound_system;

    int add_to_play_list();
};

int TDigital::add_to_play_list() {
    TSound_Driver* sound_system;

    sound_system = this->sound_system;
    if (sound_system != 0) {
        if (sound_system->mute == 0) {
            return sound_system->add_to_play_list(this);
        }
    }
    return 0;
}
