// 004BC470 RGE_Sound::get_file_name
// Source: Sound.cpp lines 278-299
// Size: 121 bytes, non-virtual, no EH
//
// Attempt log:
// Probe 1: natural C++

#include "..\..\include\game_globals.h"

// RGE_Sound class layout
// +0x00: play_at_update_count (short)
// +0x02: sound_num (short)
// +0x04: sounds (RGE_Sound_Info*)
// +0x08: cache_time (int)
// +0x0C: id (short)

class RGE_Sound_Info;

class RGE_Sound {
public:
    short play_at_update_count;  // +0x00
    short sound_num;             // +0x02
    RGE_Sound_Info* sounds;      // +0x04
    int cache_time;              // +0x08
    short id;                    // +0x0C

    char* get_file_name();
};

// TDigital — +0x0A = sound_file (inline char array)
class TDigital {
public:
    char _gap_00[0x0A];
    char sound_file[1];          // +0x0A (inline array, address returned)
};

// RGE_Sound_Info — 0x24 bytes per entry
class RGE_Sound_Info {
public:
    char _gap_00[0x14];
    short percent;               // +0x14
    char _gap_16[2];
    TDigital* digital_sound;     // +0x18
    char _gap_1C[4];
    int time_field;              // +0x20
};

extern int __cdecl debug_rand(const char* file, int line);

char* RGE_Sound::get_file_name()
{
    if (this->sound_num > 0) {
        int rand_val = debug_rand("C:\\msdev\\work\\age1_x1\\Sound.cpp", 0x11C);
        rand_val = (rand_val * 100) / 0x7FFF;
        for (int i = 0; i < this->sound_num; i++) {
            rand_val -= this->sounds[i].percent;
            if (rand_val <= 0) {
                TDigital* dig = this->sounds[i].digital_sound;
                if (dig != 0) {
                    return dig->sound_file;
                }
                break;
            }
        }
    }
    return 0;
}
