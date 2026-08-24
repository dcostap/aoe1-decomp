#ifndef SOUNDDRV_CANONICAL_TU
class TDigital;

class TSound_Driver {
public:
    char gap_00[0x1];
    unsigned char mute;
    char gap_02[0x296];
    TDigital* sound_play_list[0x100];
    int play_list_count;

    int add_to_play_list(TDigital* param_1);
};
#endif

int TSound_Driver::add_to_play_list(TDigital* param_1) {
    if ((this->play_list_count != 0xFF) && (this->mute == 0)) {
        this->sound_play_list[this->play_list_count] = param_1;
        ++this->play_list_count;
        return 1;
    }
    return 0;
}
