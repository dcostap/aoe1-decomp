#ifndef AOE1_SOUND_CONTEXT_H
#define AOE1_SOUND_CONTEXT_H

#include <stdio.h>

// Sound.cpp uses the period RGE_Sound object.  The class has no virtual table.
// These offsets are taken from the shipped Sound.cpp accesses.
class TSound_Driver;

class TDigital {
public:
    TSound_Driver* sound_system; // +0x00
    TDigital* owner;              // +0x04
    unsigned char loaded;         // +0x08
    unsigned char failed;         // +0x09
    char sound_file[13];          // +0x0A
    unsigned char gap_17;         // +0x17
    long resource_id;             // +0x18
    long volume;                  // +0x1C
    unsigned long pitch;          // +0x20
    long pan;                     // +0x24
    int loop;                     // +0x28
    unsigned char* wave_data;     // +0x2C
    void* wave_info;              // +0x30
    void* sound_buffer;           // +0x34
    unsigned long data_size;      // +0x38

    TDigital(TSound_Driver* driver, char* file, long resource_id);
    ~TDigital();
    int play();
    int add_to_play_list();
    int is_playing();
    void stop();
    void unload();
};

class RGE_Sound_Info {
public:
    char name[13];                // +0x00
    unsigned char gap_0D[3];      // +0x0D
    long resource_id;             // +0x10
    short percent;                // +0x14
    unsigned char gap_16[2];      // +0x16
    TDigital* digital_sound;      // +0x18
    unsigned char loaded;         // +0x1C
    unsigned char gap_1D[3];      // +0x1D
    unsigned long time;           // +0x20
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

typedef char sound_context_rge_sound_size_check[
    (sizeof(RGE_Sound) == 0x10) ? 1 : -1];
typedef char sound_context_sound_info_size_check[
    (sizeof(RGE_Sound_Info) == 0x24) ? 1 : -1];
typedef char sound_context_tdigital_size_check[
    (sizeof(TDigital) == 0x3C) ? 1 : -1];

#endif
