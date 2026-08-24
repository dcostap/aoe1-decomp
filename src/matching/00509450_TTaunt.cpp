class TSound_Driver;

#ifndef AOE1_TAUNT_CONTEXT_H
class TTaunt {
public:
    char gap_00[0x113];
    char TauntDir_0;
    char gap_114[0x80];
    int Mute;

    TTaunt(TSound_Driver* sound_driver);
    int RestartSoundSystem(TSound_Driver* sound_driver);
};
#endif

TTaunt::TTaunt(TSound_Driver* sound_driver) {
    this->TauntDir_0 = 0;
    RestartSoundSystem(sound_driver);
    this->Mute = 0;
}
