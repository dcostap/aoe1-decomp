#ifndef SOUND_CANONICAL_TU
class RGE_Sound_Info;
class RGE_Sound {
public:
    short play_at_update_count;
    short sound_num;
    RGE_Sound_Info* sounds;
    RGE_Sound();
};
#endif

RGE_Sound::RGE_Sound() {
    this->play_at_update_count = 0;
    this->sound_num = 0;
    this->sounds = 0;
}
