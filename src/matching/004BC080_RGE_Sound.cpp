// Sound.cpp:103-123, 111 bytes
// RGE_Sound::~RGE_Sound()
//
// Attempt log:
// [1-5] Previous attempts: various struct layouts, 68.5% best.
// [6] Match original register usage: esi=this, ebx=counter i, edi=byte offset, ebp=digital.
//     Sound_Entry stride = 0x24. In the canonical Sound.cpp TU, typed indexed
//     entry access preserves the original base/index SIB order for all three
//     record accesses. The standalone raw-offset form is equivalent but is not
//     used when SOUND_CANONICAL_TU supplies the reviewed record type.
// [7] Replaced the standalone void* fallback with the same reviewed typed
//     RGE_Sound_Info layout. Fresh standalone and full-TU checks both match.

#ifndef SOUND_CANONICAL_TU
class TDigital {
public:
    ~TDigital();
};

class RGE_Sound_Info {
public:
    char name[13];
    char _gap_0D[3];
    long resource_id;
    short percent;
    char _gap_16[2];
    TDigital* digital_sound;
    char _gap_1C[8];
};

#ifndef SOUND_CANONICAL_TU
extern void __cdecl free(void*);
#endif
extern void __cdecl operator_delete(void*);

class RGE_Sound {
public:
    unsigned short play_at_update_count;  // +0x00
    short sound_num;                      // +0x02
    RGE_Sound_Info* sounds;               // +0x04

    ~RGE_Sound();
};
#endif

RGE_Sound::~RGE_Sound() {
    this->play_at_update_count = 0;
    if (this->sounds != 0) {
        int i = 0;
        if (this->sound_num > 0) {
            do {
                this->sounds[i].name[0] = 0;
                TDigital* d = this->sounds[i].digital_sound;
                if (d != 0) {
                    d->~TDigital();
                    operator_delete(d);
                    this->sounds[i].digital_sound = 0;
                }
                i++;
            } while (i < this->sound_num);
        }
        free(this->sounds);
        this->sounds = 0;
        this->sound_num = 0;
    }
}
