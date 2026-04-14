class MemberType {
public:
    void StopSoundSystem();
};

class TChat {
public:
    char gap_0[0xFC];
    MemberType* member_FC;

    void StopSoundSystem();
};

void TChat::StopSoundSystem() {
    if (this->member_FC) {
        this->member_FC->StopSoundSystem();
    }
}
