// Decompiled: Sound.cpp
// SourceMap: C:/msdev/work/age1_x1/Sound.cpp

#include "../include/RGE_Sound.h"
#include "../include/TDigital.h"
#include "../include/TSound_Driver.h"
#include "../include/globals.h"
#include "../include/custom_debug.h"
#include "../include/debug_helpers.h"
#include <string.h>
#include <stdlib.h>

// Offset: 0x004BBE40
RGE_Sound::RGE_Sound(FILE* infile, short param_id) {
    this->id = param_id;
    this->play_at_update_count = 0;
    fscanf(infile, " %hd", &this->sound_num);
    if (this->sound_num < 1) {
        this->sounds = nullptr;
    } else {
        this->sounds = (RGE_Sound_Info*)calloc((int)this->sound_num, sizeof(RGE_Sound_Info));
        for (short i = 0; i < this->sound_num; i++) {
            fscanf(infile, " %ld %s %hd",
                &this->sounds[i].resource_id,
                this->sounds[i].name,
                &this->sounds[i].percent);
            // Append .wav extension
            strcat(this->sounds[i].name, ".wav");
            this->sounds[i].digital_sound = nullptr;
        }
    }
    this->cache_time = 300000;
}

// Offset: 0x004BBF30
RGE_Sound::RGE_Sound(int handle, TSound_Driver* driver) {
    rge_read(handle, &this->id, 2);
    rge_read(handle, &this->play_at_update_count, 2); // reads into offset 0x0
    rge_read(handle, &this->sound_num, 2);
    rge_read(handle, &this->cache_time, 4);

    if (this->sound_num < 1) {
        this->sounds = nullptr;
    } else {
        this->sounds = (RGE_Sound_Info*)calloc((int)this->sound_num, sizeof(RGE_Sound_Info));
        for (int i = 0; i < this->sound_num; i++) {
            rge_read(handle, this->sounds[i].name, 0x0D);
            rge_read(handle, &this->sounds[i].resource_id, 4);
            rge_read(handle, &this->sounds[i].percent, 2);

            TDigital* dig = new TDigital(driver, this->sounds[i].name, this->sounds[i].resource_id);
            this->sounds[i].digital_sound = dig;
            this->sounds[i].loaded = 2;
        }
    }
}

// Offset: 0x004BC070
RGE_Sound::RGE_Sound() {
    this->play_at_update_count = 0;
    this->sound_num = 0;
    this->sounds = nullptr;
}

// Offset: 0x004BC080
RGE_Sound::~RGE_Sound() {
    this->play_at_update_count = 0;
    if (this->sounds != nullptr) {
        for (int i = 0; i < this->sound_num; i++) {
            this->sounds[i].name[0] = '\0';
            if (this->sounds[i].digital_sound != nullptr) {
                delete this->sounds[i].digital_sound;
                this->sounds[i].digital_sound = nullptr;
            }
        }
        free(this->sounds);
        this->sounds = nullptr;
        this->sound_num = 0;
    }
}

// Offset: 0x004BC0F0
void RGE_Sound::save(int handle) {
    rge_write(handle, &this->id, 2);
    rge_write(handle, &this->play_at_update_count, 2);
    rge_write(handle, &this->sound_num, 2);
    rge_write(handle, &this->cache_time, 4);

    if (this->sound_num > 0) {
        for (int i = 0; i < this->sound_num; i++) {
            rge_write(handle, this->sounds[i].name, 0x0D);
            rge_write(handle, &this->sounds[i].resource_id, 4);
            rge_write(handle, &this->sounds[i].percent, 2);
        }
    }
}

// Offset: 0x004BC190
void RGE_Sound::restart_sound(TSound_Driver* driver) {
    for (int i = 0; i < this->sound_num; i++) {
        if (this->sounds[i].digital_sound != nullptr) {
            delete this->sounds[i].digital_sound;
        }
        if (driver == nullptr) {
            this->sounds[i].digital_sound = nullptr;
        } else {
            TDigital* dig = new TDigital(driver, this->sounds[i].name, this->sounds[i].resource_id);
            this->sounds[i].digital_sound = dig;
        }
        this->sounds[i].loaded = 2;
    }
}

// Offset: 0x004BC270
void RGE_Sound::update(ulong time) {
    if (this->sound_num <= 0 || this->cache_time == 0) return;

    for (int i = 0; i < this->sound_num; i++) {
        if (this->sounds[i].loaded == 1 &&
            this->cache_time < (time - this->sounds[i].time)) {
            this->sounds[i].digital_sound->unload();
            this->sounds[i].loaded = 2;
        }
    }
}

// Offset: 0x004BC2D0
void RGE_Sound::set_cache_time(ulong time) {
    this->cache_time = time;
}

// Offset: 0x004BC2E0
void RGE_Sound::play_at_update() {
    this->play_at_update_count++;
}

// Offset: 0x004BC2F0
void RGE_Sound::update_play() {
    if (this->play_at_update_count > 0) {
        this->play(1);
        this->play_at_update_count = 0;
    }
}

// Offset: 0x004BC310
void RGE_Sound::play(int add_to_list) {
    if (this->sound_num <= 0) return;

    int r = debug_rand("C:\\msdev\\work\\age1_x1\\Sound.cpp", 0xDD);
    int pct = (r * 100) / 0x7FFF;

    int idx = 0;
    for (idx = 0; idx < this->sound_num; idx++) {
        pct -= this->sounds[idx].percent;
        if (pct <= 0) break;
    }
    if (idx >= this->sound_num) return;

    if (this->sounds[idx].digital_sound != nullptr) {
        CUSTOM_DEBUG_BEGIN
        CUSTOM_DEBUG_LOG_FMT(
            "RGE_Sound::play id=%d sound_num=%d idx=%d add_to_list=%d name='%s' resid=%ld pct=%hd dig=%p",
            (int)this->id,
            (int)this->sound_num,
            (int)idx,
            (int)add_to_list,
            this->sounds[idx].name,
            this->sounds[idx].resource_id,
            (short)this->sounds[idx].percent,
            this->sounds[idx].digital_sound);
        CUSTOM_DEBUG_END

        if (do_draw_log != 0) {
            char s[256];
            sprintf(s, " %s", this->sounds[idx].name);
            if (safe_draw_log == 0) {
                write_draw_log(s);
            } else {
                write_draw_log2(s);
            }
        }

        if (add_to_list == 0) {
            this->sounds[idx].digital_sound->play();
        } else {
            this->sounds[idx].digital_sound->add_to_play_list();
        }

        if (do_draw_log != 0) {
            char empty[] = "";
            if (safe_draw_log == 0) {
                write_draw_log(empty);
            } else {
                write_draw_log2(empty);
            }
        }

        this->sounds[idx].loaded = 1;
        int saved = debug_timeGetTime_on;
        debug_timeGetTime_on = 0;
        this->sounds[idx].time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Sound.cpp", 0x108);
        debug_timeGetTime_on = saved;
    }
}

// Offset: 0x004BC470
char* RGE_Sound::get_file_name() {
    if (this->sound_num <= 0) return nullptr;

    int r = debug_rand("C:\\msdev\\work\\age1_x1\\Sound.cpp", 0x11C);
    int pct = (r * 100) / 0x7FFF;

    for (int idx = 0; idx < this->sound_num; idx++) {
        pct -= this->sounds[idx].percent;
        if (pct <= 0) {
            if (this->sounds[idx].digital_sound != nullptr) {
                return this->sounds[idx].digital_sound->sound_file;
            }
            return nullptr;
        }
    }
    return nullptr;
}

// Offset: 0x004BC4F0
void RGE_Sound::stop() {
    if (this->sound_num <= 0) return;
    for (int i = 0; i < this->sound_num; i++) {
        if (this->sounds[i].digital_sound != nullptr &&
            this->sounds[i].digital_sound->is_playing()) {
            this->sounds[i].digital_sound->stop();
        }
    }
}

// Offset: 0x004BC540
int RGE_Sound::is_playing() {
    if (this->sound_num <= 0) return 0;
    for (int i = 0; i < this->sound_num; i++) {
        if (this->sounds[i].digital_sound != nullptr) {
            if (this->sounds[i].digital_sound->is_playing()) {
                return 1;
            }
        }
    }
    return 0;
}
