// 004BBF30 RGE_Sound::RGE_Sound (rge_read-based ctor, EH-framed)
// Source: Sound.cpp lines 64-89
// Size: 306 bytes, EH-framed
//
// Attempt log:
// Probe 1: 288/306 bytes — new expression generates inline default ctor
//   Same pattern as restart_sound: original uses manual operator_new(0x3C) +
//   TDigital::TDigital(driver, name, field_10) with 3 params and EH tracking.

#include "..\..\include\game_globals.h"

class RGE_Sound_Info;

class RGE_Sound {
public:
    short play_at_update_count;  // +0x00
    short sound_num;             // +0x02
    RGE_Sound_Info* sounds;      // +0x04
    int cache_time;              // +0x08
    short id;                    // +0x0C

    RGE_Sound(int handle, void* driver);
};

class TDigital {
public:
    virtual void d0() {}
    virtual ~TDigital() {}
    char _gap_04[0x38];
};

class RGE_Sound_Info {
public:
    char name[16];               // +0x00
    int field_10;                // +0x10
    short percent;               // +0x14
    char _gap_16[2];
    TDigital* digital_sound;     // +0x18
    char loaded;                 // +0x1C
    char _gap_1D[3];
    int time_field;              // +0x20
};

extern int __cdecl rge_read(int handle, void* buf, int size);
extern void* __cdecl calloc(int num, int size);
extern void* __cdecl operator_new(unsigned int size);

RGE_Sound::RGE_Sound(int handle, void* driver)
{
    rge_read(handle, &this->id, 2);
    rge_read(handle, this, 2);
    rge_read(handle, &this->sound_num, 2);
    rge_read(handle, &this->cache_time, 4);

    if (this->sound_num > 0) {
        this->sounds = (RGE_Sound_Info*)calloc(this->sound_num, 0x24);
        int offset = 0;
        for (int i = 0; i < this->sound_num; i++) {
            RGE_Sound_Info* info = (RGE_Sound_Info*)((char*)this->sounds + offset);
            rge_read(handle, info, 0x0D);
            rge_read(handle, &info->field_10, 4);
            rge_read(handle, &info->percent, 2);
            info->digital_sound = new TDigital();
            info->loaded = 2;
            offset += 0x24;
        }
    } else {
        this->sounds = 0;
    }
}
