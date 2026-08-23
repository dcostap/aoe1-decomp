#ifndef SOUND_CANONICAL_TU
class RGE_Sound {
public:
    void play(int v);
    void update_play(void);
    short play_at_update_count;
};
#endif

void RGE_Sound::update_play(void) {
    if (this->play_at_update_count > 0) {
        this->play(1);
        this->play_at_update_count = 0;
    }
}
