#ifndef AOE1_SOUND_CONTEXT_H
#define AOE1_SOUND_CONTEXT_H

#include <stdio.h>
#include "sounddrv.h"

class RGE_Sound_Info {
public:
    char name[13];
    long resource_id;
    short percent;
    TDigital* digital_sound;
    unsigned char loaded;
    unsigned long time;
};

class RGE_Sound {
public:
    short play_at_update_count;   // +0x00
    short sound_num;              // +0x02
    RGE_Sound_Info* sounds;       // +0x04
    unsigned long cache_time;     // +0x08
    short id;                     // +0x0C

    RGE_Sound(FILE* file, short sound_id);
    RGE_Sound(int handle, TSound_Driver* driver);
    RGE_Sound();
    ~RGE_Sound();

    void save(int handle);
    void restart_sound(TSound_Driver* driver);
    void update(unsigned long now);
    void set_cache_time(unsigned long time);
    void play_at_update();
    void update_play();
    void play(int add_to_list);
    char* get_file_name();
    void stop();
    int is_playing();
};

// These are the direct Sound.cpp helper ABIs.  Keep the C++ linkage on the
// stream helpers used by the exact Sound.cpp save and load donors.
extern "C" int __cdecl debug_rand(char* file, int line);
extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);
extern "C" unsigned long __cdecl debug_timeGetTime(char* file, int line);
extern void __cdecl write_draw_log(char* message);
extern void __cdecl write_draw_log2(char* message);
extern void __cdecl rge_read(int handle, void* buffer, int size);
extern int __cdecl rge_write(int handle, void* buffer, int size);
extern void* __cdecl calloc(int count, int size);
extern "C" void __cdecl free(void* block);
extern void __cdecl operator_delete(void* block);

extern int do_draw_log;
extern int safe_draw_log;
extern int debug_timeGetTime_on;

typedef char sound_rge_sound_size_check[
    (sizeof(RGE_Sound) == 0x10) ? 1 : -1];
typedef char sound_rge_sound_info_size_check[
    (sizeof(RGE_Sound_Info) == 0x24) ? 1 : -1];
typedef char sound_rge_sound_info_resource_id_offset_check[
    (offsetof(RGE_Sound_Info, resource_id) == 0x10) ? 1 : -1];

#endif
