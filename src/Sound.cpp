#include "../include/sound.h"
#include "../include/rge_fio.h"
#include <stdio.h>
#include "../include/sounddrv.h"

// Sound.cpp-only runtime, helper, and global declarations.
extern "C" int __cdecl debug_rand(char* file, int line);
extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);
extern "C" unsigned long __cdecl debug_timeGetTime(char* file, int line);
extern void __cdecl write_draw_log(char* message);
extern void __cdecl write_draw_log2(char* message);
extern void* __cdecl calloc(int count, int size);
extern "C" void __cdecl free(void* block);

extern int do_draw_log;
extern int safe_draw_log;
extern int debug_timeGetTime_on;

#include "../include/game_globals.h"
#include <string.h>

RGE_Sound::RGE_Sound(_iobuf* file, short sound_id)
{
    this->id = sound_id;
    this->play_at_update_count = 0;
    fscanf(file, "%hd", &this->sound_num);
    if (this->sound_num > 0) {
        this->sounds = (RGE_Sound_Info*)calloc(this->sound_num, 0x24);
        for (int i = 0; i < this->sound_num; i++) {
            fscanf(file, "%d %s %hd",
                   &this->sounds[i].resource_id,
                   this->sounds[i].name,
                   &this->sounds[i].percent);
            strcat(this->sounds[i].name, ".wav");
            this->sounds[i].digital_sound = 0;
        }
    } else {
        this->sounds = 0;
    }
    this->cache_time = 300000;
}

RGE_Sound::RGE_Sound(int handle, TSound_Driver* driver)
{
    rge_read(handle, &this->id, 2);
    rge_read(handle, this, 2);
    rge_read(handle, &this->sound_num, 2);
    rge_read(handle, &this->cache_time, 4);

    if (this->sound_num > 0) {
        this->sounds = (RGE_Sound_Info*)calloc(this->sound_num, 0x24);
        if (this->sound_num > 0) {
            for (int i = 0; i < this->sound_num; i++) {
                rge_read(handle, this->sounds[i].name, 0x0D);
                rge_read(handle, &this->sounds[i].resource_id, 4);
                rge_read(handle, &this->sounds[i].percent, 2);
                this->sounds[i].digital_sound = new TDigital(
                    driver, this->sounds[i].name,
                    this->sounds[i].resource_id);
                this->sounds[i].loaded = 2;
            }
        }
    } else {
        this->sounds = 0;
    }
}

RGE_Sound::RGE_Sound()
{
    this->play_at_update_count = 0;
    this->sound_num = 0;
    this->sounds = 0;
}

RGE_Sound::~RGE_Sound()
{
    this->play_at_update_count = 0;
    if (this->sounds != 0) {
        int i = 0;
        if (this->sound_num > 0) {
            do {
                this->sounds[i].name[0] = 0;
                TDigital* digital = this->sounds[i].digital_sound;
                if (digital != 0) {
                    delete digital;
                    this->sounds[i].digital_sound = 0;
                }
                i++;
            } while (i < this->sound_num);
        }
        free(this->sounds);
        this->sounds = 0;
        this->sound_num = 0;
    }
}

void RGE_Sound::save(int handle)
{
    rge_write(handle, &this->id, 2);
    rge_write(handle, this, 2);
    rge_write(handle, &this->sound_num, 2);
    rge_write(handle, &this->cache_time, 4);

    short count = this->sound_num;
    if (count > 0) {
        for (int i = 0; i < this->sound_num; i++) {
            rge_write(handle, this->sounds[i].name, 0x0D);
            rge_write(handle, &this->sounds[i].resource_id, 4);
            rge_write(handle, &this->sounds[i].percent, 2);
        }
    }
}

void RGE_Sound::restart_sound(TSound_Driver* driver)
{
    int i = 0;
    if (this->sound_num > 0) {
        do {
            TDigital* digital = this->sounds[i].digital_sound;
            if (digital != 0) {
                delete digital;
            }
            if (driver != 0) {
                digital = new TDigital(driver,
                                       this->sounds[i].name,
                                       this->sounds[i].resource_id);
                this->sounds[i].digital_sound = digital;
            } else {
                this->sounds[i].digital_sound = 0;
            }
            this->sounds[i].loaded = 2;
            ++i;
        } while (i < this->sound_num);
    }
}

void RGE_Sound::update(unsigned long now)
{
    if ((this->sound_num > 0) && (this->cache_time != 0)) {
        int i = 0;
        if (this->sound_num > 0) {
            do {
                if ((this->sounds[i].loaded == 1) &&
                    (this->cache_time <
                     now - this->sounds[i].time)) {
                    this->sounds[i].digital_sound->unload();
                    this->sounds[i].loaded = 2;
                }
                i++;
            } while (i < this->sound_num);
        }
    }
}

void RGE_Sound::set_cache_time(unsigned long time)
{
    this->cache_time = time;
}

void RGE_Sound::play_at_update()
{
    this->play_at_update_count++;
}

void RGE_Sound::update_play()
{
    if (this->play_at_update_count > 0) {
        this->play(1);
        this->play_at_update_count = 0;
    }
}

void RGE_Sound::play(int play_list_param)
{
    char s[256];
    int sound_count;
    int idx;

    if (this->sound_num > 0) {
        int rand_val = debug_rand("C:\\msdev\\work\\age1_x1\\Sound.cpp", 0xDD);
        rand_val = (rand_val * 100) / 0x7FFF;

        sound_count = this->sound_num;
        idx = 0;
        if (sound_count > 0) {
            for (; idx < sound_count; ++idx) {
                short percent = this->sounds[idx].percent;
                rand_val -= percent;
                if (rand_val <= 0) {
                    if (this->sounds[idx].digital_sound != 0) {
                        if (do_draw_log) {
                            sprintf(s, "{%s", this->sounds[idx].name);
                            if (safe_draw_log)
                                write_draw_log2(s);
                            else
                                write_draw_log(s);
                        }

                        if (play_list_param)
                            this->sounds[idx].digital_sound->add_to_play_list();
                        else
                            this->sounds[idx].digital_sound->play();

                        if (do_draw_log) {
                            if (safe_draw_log)
                                write_draw_log2("}");
                            else
                                write_draw_log("}");
                        }

                        this->sounds[idx].loaded = 1;
                        int saved_time_get = debug_timeGetTime_on;
                        debug_timeGetTime_on = 0;
                        unsigned long time_val = debug_timeGetTime(
                            "C:\\msdev\\work\\age1_x1\\Sound.cpp", 0x108);
                        this->sounds[idx].time = time_val;
                        debug_timeGetTime_on = saved_time_get;
                    }
                    return;
                }
            }
        }
    }
}

char* RGE_Sound::get_file_name()
{
    if (this->sound_num > 0) {
        int rand_val = debug_rand("C:\\msdev\\work\\age1_x1\\Sound.cpp", 0x11C);
        rand_val = (rand_val * 100) / 0x7FFF;
        for (int i = 0; i < this->sound_num; i++) {
            rand_val -= this->sounds[i].percent;
            if (rand_val <= 0) {
                TDigital* digital = this->sounds[i].digital_sound;
                if (digital != 0) {
                    return digital->sound_file;
                }
                break;
            }
        }
    }
    return 0;
}

void RGE_Sound::stop()
{
    int i;

    if (this->sound_num > 0) {
        for (i = 0; i < this->sound_num; i++) {
            if ((this->sounds[i].digital_sound != 0) &&
                (this->sounds[i].digital_sound->is_playing() != 0)) {
                this->sounds[i].digital_sound->stop();
            }
        }
    }
}

int RGE_Sound::is_playing()
{
    if (this->sound_num > 0) {
        for (int i = 0; i < this->sound_num; i++) {
            TDigital* digital = this->sounds[i].digital_sound;
            if (digital != 0) {
                if (digital->is_playing() != 0) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
