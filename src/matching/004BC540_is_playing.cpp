// From basegame.cpp
// matched via variant lab: for-loop with raw pointer stride 0x24

class TDigital {
public:
    int is_playing();
};

class RGE_Sound_Info {
public:
    char gap_00[0x18];
    TDigital* digital_sound;
};

class RGE_Sound {
public:
    short play_at_update_count;
    short sound_num;
    RGE_Sound_Info* sounds;
    unsigned long cache_time;
    short id;

    int is_playing();
};

int RGE_Sound::is_playing() {
    if (sound_num > 0) {
        for (int ebx = 0; ebx < sound_num; ebx++) {
            TDigital* digital = ((RGE_Sound_Info*)((char*)sounds + ebx * 0x24))->digital_sound;
            if (digital != 0) {
                if (digital->is_playing() != 0) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
