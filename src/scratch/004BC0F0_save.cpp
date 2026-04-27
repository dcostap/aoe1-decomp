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

#include "..\..\include\game_globals.h"

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

extern int __cdecl rge_write(int handle, void* buf, int size);

void RGE_Sound::save(int handle)
{
    rge_write(handle, &this->id, 2);
    rge_write(handle, this, 2);
    rge_write(handle, &this->sound_num, 2);
    rge_write(handle, &this->cache_time, 4);

    if (this->sound_num > 0) {
        int offset = 0;
        int count = this->sound_num;
        while (count > 0) {
            rge_write(handle, (char*)this->sounds + offset, 0x0D);
            rge_write(handle, (char*)this->sounds + offset + 0x10, 4);
            rge_write(handle, (char*)this->sounds + offset + 0x14, 2);
            offset += 0x24;
            count--;
        }
    }
}
