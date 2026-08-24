#ifndef AOE1_CHAT_CONTEXT_H
class MemberType {
public:
    void StopSoundSystem();
};
#endif

#ifndef AOE1_CHAT_CONTEXT_H
class TChat {
public:
    char gap_0[0xFC];
    MemberType* member_FC;

    void StopSoundSystem();
};
#endif

void TChat::StopSoundSystem() {
    if (this->taunt) {
        this->taunt->StopSoundSystem();
    }
}
