// 004BBE40 RGE_Sound::RGE_Sound (fscanf-based ctor)
// Source: Sound.cpp lines 35-58
// Size: 230 bytes, no EH
//
// Attempt log:
// Probe 1: natural C++ with strcat → 88% diff (older structure)
// Probe 2: strcpy+strlen split → 88% diff, calls not inline (older structure)
// Probe 3: single-indexed for loop + strcat(name, ".wav") (not strcpy+strlen:
//   original computes strlen(".wav") first, the strcat intrinsic order);
//   counter i reuses the dead sound_id param slot ([esp+18h]); no count/offset
//   locals. diff 39%: only VC5 deferred push edi to the loop top.
// Probe 4: cache_time=300000 written once AFTER the if/else (line 57) instead
//   of in both branches — VC5 then tail-duplicates store+return into both exits
//   AND saves edi in the prologue. MATCH (0.0000%).

#include "..\..\include\game_globals.h"
#include <stdio.h>
#include <string.h>

#ifndef SOUND_CANONICAL_TU
class RGE_Sound_Info;

class RGE_Sound {
public:
    short play_at_update_count;  // +0x00
    short sound_num;             // +0x02
    RGE_Sound_Info* sounds;      // +0x04
    int cache_time;              // +0x08
    short id;                    // +0x0C

    RGE_Sound(FILE* file, short sound_id);
};

class RGE_Sound_Info {
public:
    char name[13];               // +0x00
    char _gap_0D[3];
    long resource_id;            // +0x10
    short percent;               // +0x14
    char _gap_16[2];
    void* digital_sound;         // +0x18
    char loaded;                 // +0x1C
    char _gap_1D[3];
    long time_field;             // +0x20
};
#endif

extern void* __cdecl calloc(int num, int size);

RGE_Sound::RGE_Sound(FILE* file, short sound_id)
{
    this->id = sound_id;
    this->play_at_update_count = 0;
    fscanf(file, "%hd", &this->sound_num);
    if (this->sound_num > 0) {
        this->sounds = (RGE_Sound_Info*)calloc(this->sound_num, 0x24);
        for (int i = 0; i < this->sound_num; i++) {
            fscanf(file, "%d %s %hd",
                &this->sounds[i].resource_id, this->sounds[i].name,
                &this->sounds[i].percent);
            strcat(this->sounds[i].name, ".wav");
            this->sounds[i].digital_sound = 0;
        }
    } else {
        this->sounds = 0;
    }
    this->cache_time = 300000;
}
