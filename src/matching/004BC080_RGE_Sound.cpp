// Sound.cpp:103-123, 111 bytes
// RGE_Sound::~RGE_Sound()
//
// Attempt log:
// [1-5] Previous attempts: various struct layouts, 68.5% best.
// [6] Match original register usage: esi=this, ebx=counter i, edi=byte offset, ebp=digital.
//     Sound_Entry stride = 0x24. Explicit byte-zero at first byte of each entry.

class TDigital {
public:
    ~TDigital();
};

extern void __cdecl free(void*);
extern void __cdecl operator_delete(void*);

class RGE_Sound {
public:
    unsigned short play_at_update_count;  // +0x00
    short sound_num;                      // +0x02
    void* sounds;                         // +0x04

    ~RGE_Sound();
};

RGE_Sound::~RGE_Sound() {
    this->play_at_update_count = 0;
    if (this->sounds != 0) {
        int i = 0;
        if (this->sound_num > 0) {
            int offset = 0;
            do {
                ((char*)this->sounds)[offset] = 0;
                TDigital* d = *(TDigital**)((char*)this->sounds + offset + 0x18);
                if (d != 0) {
                    d->~TDigital();
                    operator_delete(d);
                    *(int*)((char*)this->sounds + offset + 0x18) = 0;
                }
                i++;
                offset += 0x24;
            } while (i < this->sound_num);
        }
        free(this->sounds);
        this->sounds = 0;
        this->sound_num = 0;
    }
}
