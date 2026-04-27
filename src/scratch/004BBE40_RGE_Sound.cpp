// 004BBE40 RGE_Sound::RGE_Sound (fscanf-based ctor)
// Source: Sound.cpp lines 35-58
// Size: 230 bytes, no EH
//
// Attempt log:
// Probe 1: natural C++ with strcat → 88% diff
// Probe 2: 230/230, 88% diff — strcpy/strlen still generate calls, not inline rep
// Left in scratch: codegen basin (CRT calls vs inline; sub esp,8 vs no stack locals)

#include "..\..\include\game_globals.h"
#include <stdio.h>
#include <string.h>

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
    char name[16];               // +0x00
    int field_10;                // +0x10
    short percent;               // +0x14
    char _gap_16[2];
    void* digital_sound;         // +0x18
    char loaded;                 // +0x1C
    char _gap_1D[3];
    int time_field;              // +0x20
};

extern void* __cdecl calloc(int num, int size);

RGE_Sound::RGE_Sound(FILE* file, short sound_id)
{
    this->id = sound_id;
    this->play_at_update_count = 0;
    fscanf(file, "%hd", &this->sound_num);
    if (this->sound_num > 0) {
        this->sounds = (RGE_Sound_Info*)calloc(this->sound_num, 0x24);
        int count = 0;
        int offset = 0;
        while (count < this->sound_num) {
            RGE_Sound_Info* info = (RGE_Sound_Info*)((char*)this->sounds + offset);
            fscanf(file, "%d %s %hd", &info->field_10, info->name, &info->percent);
            strcpy(info->name + strlen(info->name), ".wav");
            info->digital_sound = 0;
            count++;
            offset += 0x24;
        }
        this->cache_time = 300000;
    } else {
        this->sounds = 0;
        this->cache_time = 300000;
    }
}
