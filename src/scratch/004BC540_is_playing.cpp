// tried direct loop forms with offset/index locals; logic matched, but VC5 kept choosing edi for this and the prolog stayed push ebx;push esi;push edi;mov edi,ecx
// tried caching sound_num as short/int and swapping declaration order; mismatch stayed at offset 2 in prolog/register basin
// attempt 3: size matches (76), VC5 uses edi for this, esi for byte offset (vs original esi/edi); also missing double-check
// attempt 4: same as attempt 3; VC5 consistently uses edi for this
// Left in scratch: benign register-allocation drift at prolog (offset 2), behavior correct

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
    int ebx;

    if (sound_num > 0) {
        ebx = 0;
        if (sound_num > 0) {
            int edi = 0;
            do {
                TDigital* digital = ((RGE_Sound_Info*)((char*)sounds + edi))->digital_sound;
                if (digital != 0) {
                    if (digital->is_playing() != 0) {
                        return 1;
                    }
                }
                ebx = ebx + 1;
                edi = edi + 0x24;
            } while (ebx < sound_num);
        }
    }
    return 0;
}
