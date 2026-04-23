class TSound_Driver;

class TTaunt {
public:
    char gap_00[0x113];
    char TauntDir_0;
    char gap_114[0x80];
    int Mute;

    TTaunt(TSound_Driver* sound_driver);
    int RestartSoundSystem(TSound_Driver* sound_driver);
};

TTaunt::TTaunt(TSound_Driver* sound_driver) {
    this->TauntDir_0 = 0;
    RestartSoundSystem(sound_driver);
    this->Mute = 0;
}
