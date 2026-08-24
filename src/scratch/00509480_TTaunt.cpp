#ifndef AOE1_TAUNT_CONTEXT_H
class TTaunt {
public:
    ~TTaunt();
    void StopSoundSystem();
};
#endif

TTaunt::~TTaunt()
{
    StopSoundSystem();
}
