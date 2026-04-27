// Sound.cpp:103-123, 111 bytes
// attempt 1: 48 bytes, too small, wrong layout
// attempt 2: 71.2%, loop stride wrong (0x28 vs 0x24)
// attempt 3: 16 bytes, sounds=0 at top killed it
// attempt 4: 68.5%, int counter, stride fixed
// attempt 5: 68.5%, same
// BEST: 68.5%. BLOCKER: extra xor eax/mov ax in loop, base pointer
//   reloaded each iteration. No EH frame needed. Core logic
//   (play_at_update_count=0, loop with dtor+delete, free+null) correct.
class TDigital {
public:
    ~TDigital();
};

extern void __cdecl free(void*);
extern void __cdecl operator_delete(void*);

struct Sound_Entry {
    char gap_00[0x18];
    TDigital* digital;  // +0x18
    char gap_1C[0x08];
};

class RGE_Sound {
public:
    unsigned short play_at_update_count;  // +0x00
    unsigned short sound_num;             // +0x02
    Sound_Entry* sounds;                  // +0x04

    ~RGE_Sound();
};

RGE_Sound::~RGE_Sound() {
    play_at_update_count = 0;
    if (sounds != 0) {
        for (int i = 0; i < sound_num; i++) {
            if (sounds[i].digital != 0) {
                sounds[i].digital->~TDigital();
                operator_delete(sounds[i].digital);
            }
        }
        free(sounds);
        sounds = 0;
        sound_num = 0;
    }
}
