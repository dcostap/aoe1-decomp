#pragma once
#include "../common.h"


// ----------------------------------------------------------------
// RGE_Sound_Info
// Size: 0x24
struct RGE_Sound_Info {
    char name[13]; // 0x0
    long resource_id; // 0x10
    short percent; // 0x14
    TDigital * digital_sound; // 0x18
    uchar loaded; // 0x1C
    ulong time; // 0x20
};

// ----------------------------------------------------------------
// RGE_Sound_List
// Size: 0x14
struct RGE_Sound_List {
    RGE_Sound * sound[3]; // 0x0
    short frame[3]; // 0xC
};


class RGE_Sound {
public:
    RGE_Sound_Info* sounds;                  // 0x4
    ulong cache_time;                        // 0x8
    short id;                                // 0xC

    RGE_Sound(_iobuf* param_1, short param_2);
    RGE_Sound(int param_1, TSound_Driver* param_2);
    RGE_Sound();
    virtual ~RGE_Sound();
    virtual void save(int param_1);
    virtual void restart_sound(TSound_Driver* param_1);
    virtual void update(ulong param_1);
    virtual void set_cache_time(ulong param_1);
    virtual void play_at_update();
    virtual void update_play();
    virtual void play(int param_1);
    virtual char* get_file_name();
    virtual void stop();
    virtual int is_playing();
};

static_assert(sizeof(RGE_Sound) == 0x10, "RGE_Sound Size Mismatch");
static_assert(offsetof(RGE_Sound, id) == 0xC, "RGE_Sound Offset Mismatch");

