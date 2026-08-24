#ifndef AOE1_CHAT_CONTEXT_H
class TSound_Driver;

class TTaunt {
public:
    int RestartSoundSystem(TSound_Driver* sound_driver);
};
#endif

#ifndef AOE1_CHAT_CONTEXT_H
class TChat {
public:
    char gap_00[0xFC];
    TTaunt* taunt;

    int RestartSoundSystem(TSound_Driver* sound_driver);
};
#endif

int TChat::RestartSoundSystem(TSound_Driver* sound_driver) {
    if (taunt != 0) {
        return taunt->RestartSoundSystem(sound_driver);
    }
    return 1;
}
