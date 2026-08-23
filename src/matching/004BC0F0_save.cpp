// 004BC0F0 RGE_Sound::save
// Source: Sound.cpp lines 129-146
// Size: 158 bytes
//
// Attempt log:
// Probe 1: 158/158, 44% diff — register allocation basin
// Probe 2: while-loop form — same basin
// Left in scratch: same register allocation basin as task_lst.cpp
//   Issues: original reuses esi register for sound_num→offset conversion
//   ebp vs ebx for loop counter choice differs
// Fresh pass 2026-05-19:
// try 3: explicit short num local + do/while with i/offset: worsened badly; VC5 delayed push ebp into loop block.
// try 4: top-declared i then explicit short num: same delayed-ebp basin; rolled back.
// try 5: initialized i=0 at top: restored push ebp but moved this to ESI and offset to EDI; worsened broad prologue/body.
// try 6: restored countdown while baseline: exact-size 158B, 70/158 positional, 44 edit bytes.
// try 7: count-up while (`i < this->sound_num`) with offset: same positional 70/158 but better edit diff 34 bytes.
// Retry 2026-05-20 assigned pass:
// try 8: short count + do/while with explicit offset and duplicate count guard; worsened (123 positional).
// try 9: short count + while with explicit offset; near baseline (69 positional / 32 edit) but still AX/SI drift.
// try 10: pointer-to-sound_num count local; same bad 123-positional basin.
// try 11: register short count; same bad 123-positional basin.
// try 12: offset declared before i; worsened (124 positional).
// try 13: do-loop without inner duplicate guard; worsened (123 positional / 65 edit).
// try 14: for-loop with carried offset; near baseline (70 positional / 36 edit).
// try 15: direct `int offset = i * 0x24` inside the for body; MATCH. VC5 strength-reduces it to the original ESI byte-offset induction while keeping the short count in SI for the pre-loop tests.

#include "..\..\include\game_globals.h"

#ifndef SOUND_CANONICAL_TU
class RGE_Sound_Info;

class RGE_Sound {
public:
    short play_at_update_count;  // +0x00
    short sound_num;             // +0x02
    RGE_Sound_Info* sounds;      // +0x04
    int cache_time;              // +0x08
    short id;                    // +0x0C

    void save(int handle);
};

class RGE_Sound_Info {
public:
    char _gap_00[0x14];
    short percent;               // +0x14
    char _gap_16[2];
    void* digital_sound;         // +0x18
    char loaded;                 // +0x1C
    char _gap_1D[3];
    int time_field;              // +0x20
};
#endif

extern int __cdecl rge_write(int handle, void* buf, int size);

void RGE_Sound::save(int handle)
{
    rge_write(handle, &this->id, 2);
    rge_write(handle, this, 2);
    rge_write(handle, &this->sound_num, 2);
    rge_write(handle, &this->cache_time, 4);

    short count = this->sound_num;
    if (count > 0) {
        for (int i = 0; i < this->sound_num; i++) {
            int offset = i * 0x24;
            rge_write(handle, (char*)this->sounds + offset, 0x0D);
            rge_write(handle, (char*)this->sounds + offset + 0x10, 4);
            rge_write(handle, (char*)this->sounds + offset + 0x14, 2);
        }
    }
}
