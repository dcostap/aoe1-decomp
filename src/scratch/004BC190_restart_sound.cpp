// 004BC190 RGE_Sound::restart_sound
// Source: Sound.cpp lines 151-165
// Size: 215 bytes, EH-framed
//
// Attempt log:
// Probe 1: 176/215 bytes — new expression generates inline default ctor
//   Original uses manual operator_new(0x3C) + TDigital::TDigital(driver, name, field_10)
//   Need full TDigital class with param ctor to match

#include "..\..\include\game_globals.h"

class RGE_Sound_Info;

class RGE_Sound {
public:
    short play_at_update_count;  // +0x00
    short sound_num;             // +0x02
    RGE_Sound_Info* sounds;      // +0x04
    int cache_time;              // +0x08
    short id;                    // +0x0C

    void restart_sound(void* driver);
};

// TDigital stub — sizeof = 0x3C, virtual destructor for EH prolog
class TDigital {
public:
    virtual void d0() {}
    virtual ~TDigital() {}
    char _gap_04[0x38];  // padding to 0x3C
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

extern void* __cdecl operator_new(unsigned int size);
extern void __cdecl operator_delete(void* ptr);

void RGE_Sound::restart_sound(void* driver)
{
    if (this->sound_num > 0) {
        int offset = 0;
        for (int i = 0; i < this->sound_num; i++) {
            RGE_Sound_Info* info = (RGE_Sound_Info*)((char*)this->sounds + offset);
            if (info->digital_sound) {
                delete info->digital_sound;
            }
            if (driver) {
                info->digital_sound = new TDigital();
            } else {
                info->digital_sound = 0;
            }
            info->loaded = 2;
            offset += 0x24;
        }
    }
}
