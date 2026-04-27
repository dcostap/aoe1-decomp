// 004BC310 RGE_Sound::play
// Source: Sound.cpp lines 215-273
// Size: 346 bytes, large stack (0x100)
//
// Attempt log:
// Probe 1: 336/346 bytes — structural probe passes
//   sub esp, 0x100 for char[256], percent-selection loop, TDigital dispatch,
//   draw_log instrumentation, debug_timeGetTime. 10 bytes short (likely
//   format string and register allocation differences).

#include "..\..\include\game_globals.h"

class RGE_Sound_Info;

class RGE_Sound {
public:
    short play_at_update_count;  // +0x00
    short sound_num;             // +0x02
    RGE_Sound_Info* sounds;      // +0x04
    int cache_time;              // +0x08
    short id;                    // +0x0C

    void play(int param);
};

class TDigital {
public:
    char _gap_00[0x3C];
    int play();
    int add_to_play_list();
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

extern int __cdecl debug_rand(const char* file, int line);
extern int __cdecl sprintf(char* buf, const char* fmt, ...);
extern int __cdecl debug_timeGetTime(const char* file, int line);

extern void __cdecl write_draw_log(const char* msg);
extern void __cdecl write_draw_log2(const char* msg);

// Globals (extern)
extern int do_draw_log;       // 0x62C498
extern int safe_draw_log;     // 0x592A5C
extern int debug_timeGetTime_on;  // 0x62C4E8

void RGE_Sound::play(int play_list_param)
{
    if (this->sound_num <= 0)
        return;

    int rand_val = debug_rand("C:\\msdev\\work\\age1_x1\\Sound.cpp", 0xDD);
    rand_val = (rand_val * 100) / 0x7FFF;

    int idx;
    for (idx = 0; idx < this->sound_num; idx++) {
        rand_val -= this->sounds[idx].percent;
        if (rand_val <= 0)
            break;
    }
    if (idx >= this->sound_num)
        return;

    RGE_Sound_Info* info = &this->sounds[idx];
    TDigital* dig = info->digital_sound;
    if (!dig)
        return;

    char s[256];
    if (do_draw_log) {
        sprintf(s + 4, "{%s", (char*)(this->sounds + idx));
        if (safe_draw_log)
            write_draw_log2(s + 4);
        else
            write_draw_log(s + 4);
    }

    if (play_list_param)
        dig->add_to_play_list();
    else
        dig->play();

    if (do_draw_log) {
        if (safe_draw_log)
            write_draw_log2("}");
        else
            write_draw_log("}");
    }

    this->sounds[idx].loaded = 1;
    int saved_time_get = debug_timeGetTime_on;
    debug_timeGetTime_on = 0;
    unsigned long time_val = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Sound.cpp", 0x108);
    this->sounds[idx].time_field = time_val;
    debug_timeGetTime_on = saved_time_get;
}
