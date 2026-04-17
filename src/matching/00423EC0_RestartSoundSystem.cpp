class TSound_Driver;

class TTaunt {
public:
    int RestartSoundSystem(TSound_Driver* sound_driver);
};

class TChat {
public:
    char gap_00[0xFC];
    TTaunt* taunt;

    int RestartSoundSystem(TSound_Driver* sound_driver);
};

int TChat::RestartSoundSystem(TSound_Driver* sound_driver) {
    if (taunt != 0) {
        return taunt->RestartSoundSystem(sound_driver);
    }
    return 1;
}
