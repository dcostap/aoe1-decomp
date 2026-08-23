#ifndef SOUND_CANONICAL_TU
class RGE_Sound {
public:
    short play_at_update_count;
    void play_at_update();
};
#endif

void RGE_Sound::play_at_update() { this->play_at_update_count++; }
