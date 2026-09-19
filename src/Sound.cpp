#include "../include/sound.h"
#include "../include/sprite.h"
#include "../include/rge_fio.h"
#include <stdio.h>
#include <stdlib.h>
#include "../include/sounddrv.h"

// Sound.cpp-only runtime, helper, and global declarations.
extern int __cdecl debug_rand(char* file, int line);
extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);
extern unsigned long __cdecl debug_timeGetTime(char* file, int line);
extern void __cdecl write_draw_log(char* message);
extern void __cdecl write_draw_log2(char* message);

#include "../include/game_globals.h"
#include <string.h>

RGE_Sound::RGE_Sound(_iobuf* infile, short in_id) {
    this->id = in_id;
    this->play_at_update_count = 0;
    fscanf(infile, "%hd", &this->sound_num);
    if (this->sound_num > 0) {
        this->sounds = (RGE_Sound_Info*)calloc(this->sound_num, 36);
        for (int index = 0; index < this->sound_num; index++) {
            fscanf(infile, "%d %s %hd", &this->sounds[index].resource_id, this->sounds[index].name,
                   &this->sounds[index].percent);
            strcat(this->sounds[index].name, ".wav");
            this->sounds[index].digital_sound = 0;
        }
    } else {
        this->sounds = 0;
    }
    this->cache_time = 300000;
}

RGE_Sound::RGE_Sound(int infile, TSound_Driver* sound) {
    rge_read(infile, &this->id, 2);
    rge_read(infile, this, 2);
    rge_read(infile, &this->sound_num, 2);
    rge_read(infile, &this->cache_time, 4);

    if (this->sound_num > 0) {
        this->sounds = (RGE_Sound_Info*)calloc(this->sound_num, 36);
        for (int i = 0; i < this->sound_num; i++) {
            rge_read(infile, this->sounds[i].name, 13);
            rge_read(infile, &this->sounds[i].resource_id, 4);
            rge_read(infile, &this->sounds[i].percent, 2);
            this->sounds[i].digital_sound =
                new TDigital(sound, this->sounds[i].name, this->sounds[i].resource_id);
            this->sounds[i].loaded = 2;
        }
    } else {
        this->sounds = 0;
    }
}

RGE_Sound::RGE_Sound() {
    this->play_at_update_count = 0;
    this->sound_num = 0;
    this->sounds = 0;
}

RGE_Sound::~RGE_Sound() {
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

void RGE_Sound::save(int outfile) {
    rge_write(outfile, &this->id, 2);
    rge_write(outfile, this, 2);
    rge_write(outfile, &this->sound_num, 2);
    rge_write(outfile, &this->cache_time, 4);

    short count = this->sound_num;
    if (count > 0) {
        for (int i = 0; i < this->sound_num; i++) {
            rge_write(outfile, this->sounds[i].name, 13);
            rge_write(outfile, &this->sounds[i].resource_id, 4);
            rge_write(outfile, &this->sounds[i].percent, 2);
        }
    }
}

void RGE_Sound::restart_sound(TSound_Driver* sound) {
    int i = 0;
    if (this->sound_num > 0) {
        do {
            TDigital* digital = this->sounds[i].digital_sound;
            if (digital != 0) {
                delete digital;
            }
            if (sound != 0) {
                digital = new TDigital(sound, this->sounds[i].name, this->sounds[i].resource_id);
                this->sounds[i].digital_sound = digital;
            } else {
                this->sounds[i].digital_sound = 0;
            }
            this->sounds[i].loaded = 2;
            ++i;
        } while (i < this->sound_num);
    }
}

void RGE_Sound::update(unsigned long curr_time) {
    if ((this->sound_num > 0) && (this->cache_time != 0)) {
        int i = 0;
        if (this->sound_num > 0) {
            do {
                if ((this->sounds[i].loaded == 1) && (this->cache_time < curr_time - this->sounds[i].time)) {
                    this->sounds[i].digital_sound->unload();
                    this->sounds[i].loaded = 2;
                }
                i++;
            } while (i < this->sound_num);
        }
    }
}

void RGE_Sound::set_cache_time(unsigned long new_cache_time) {
    this->cache_time = new_cache_time;
}

void RGE_Sound::play_at_update() {
    this->play_at_update_count++;
}

void RGE_Sound::update_play() {
    if (this->play_at_update_count > 0) {
        this->play(1);
        this->play_at_update_count = 0;
    }
}

void RGE_Sound::play(int add_to_play_list) {
    char s[256];

    if (this->sound_num > 0) {
        int rand_val = debug_rand("C:\\msdev\\work\\age1_x1\\Sound.cpp", 221);
        rand_val = (rand_val * 100) / 0x7FFF;

        for (int i = 0; i < this->sound_num; i++) {
            rand_val -= this->sounds[i].percent;
            if (rand_val <= 0) {
                if (this->sounds[i].digital_sound != 0) {
                    if (do_draw_log != 0) {
                        sprintf(s, "{%s", this->sounds[i].name);
                        if (safe_draw_log != 0) {
                            write_draw_log2(s);
                        } else {
                            write_draw_log(s);
                        }
                    }

                    if (add_to_play_list != 0) {
                        this->sounds[i].digital_sound->add_to_play_list();
                    } else {
                        this->sounds[i].digital_sound->play();
                    }

                    if (do_draw_log != 0) {
                        if (safe_draw_log != 0) {
                            write_draw_log2("}");
                        } else {
                            write_draw_log("}");
                        }
                    }

                    this->sounds[i].loaded = 1;
                    int saved_time_get = debug_timeGetTime_on;
                    debug_timeGetTime_on = 0;
                    this->sounds[i].time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Sound.cpp", 264);
                    debug_timeGetTime_on = saved_time_get;
                }
                break;
            }
        }
    }
}

char* RGE_Sound::get_file_name() {
    if (this->sound_num > 0) {
        int rand_val = debug_rand("C:\\msdev\\work\\age1_x1\\Sound.cpp", 284);
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

void RGE_Sound::stop() {
    int i;

    if (this->sound_num > 0) {
        for (i = 0; i < this->sound_num; i++) {
            if ((this->sounds[i].digital_sound != 0) && (this->sounds[i].digital_sound->is_playing() != 0)) {
                this->sounds[i].digital_sound->stop();
            }
        }
    }
}

int RGE_Sound::is_playing() {
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
