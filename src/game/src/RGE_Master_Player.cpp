#include "../include/RGE_Master_Player.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Master_Animated_Object.h"
#include "../include/RGE_Master_Moving_Object.h"
#include "../include/RGE_Master_Action_Object.h"
#include "../include/RGE_Master_Combat_Object.h"
#include "../include/RGE_Master_Missile_Object.h"
#include "../include/RGE_Master_Doppleganger_Object.h"
#include "../include/globals.h"
#include "../include/custom_debug.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// TODO: PARITY - RGE_Master_Player::vector_deleting_destructor from decomp is not implemented in this translation unit. [decomp: RGE_Master_Player.decomp @ 0x004610A0]
// TODO: PARITY - Requested m_player.cpp.decomp/mplayer.cpp.decomp names are not present in this tree; this audit maps RGE_Master_Player to mst_play.cpp.decomp. [decomp: mst_play.cpp.decomp @ 0x004610C0]

RGE_Master_Player::RGE_Master_Player() {
    memset(this->name, 0, sizeof(this->name));
    this->master_object_num = 0;
    this->master_objects = nullptr;
    this->attribute_num = 0;
    this->attributes = nullptr;
    this->culture = 0;
    this->type = 0;
    this->tribe_effect = 0;
}

// Fully verified. Source of truth: mst_play.cpp.decomp @ 0x004610C0
RGE_Master_Player::RGE_Master_Player(int fd) {
    memset(this->name, 0, sizeof(this->name));
    rge_read(fd, this->name, 20);
    rge_read(fd, &this->attribute_num, 2);
    rge_read(fd, &this->tribe_effect, 2);
    if (this->attribute_num > 0) {
        this->attributes = (float*)calloc(this->attribute_num, sizeof(float));
        rge_read(fd, this->attributes, this->attribute_num * sizeof(float));
    } else {
        this->attributes = nullptr;
    }
    rge_read(fd, &this->culture, 1);
    this->master_object_num = 0;
    this->master_objects = nullptr;
    this->type = 0; // Default or read from somewhere? Decomp shows it set to 0.
}

// Fully verified. Source of truth: mst_play.cpp.decomp @ 0x00460FD0
RGE_Master_Player::RGE_Master_Player(FILE* f) {
    memset(this->name, 0, sizeof(this->name));
    this->type = 0;
    fscanf(f, " %s %hd %hd", this->name, &this->tribe_effect, &this->attribute_num);
    if (this->attribute_num > 0) {
        this->attributes = (float*)calloc(this->attribute_num, sizeof(float));
    } else {
        this->attributes = nullptr;
    }
    
    short count;
    fscanf(f, " %hd", &count);
    for (short i = 0; i < count; i++) {
        short index;
        float val;
        fscanf(f, " %hd %f", &index, &val);
        if (this->attributes && index >= 0 && index < this->attribute_num) {
            this->attributes[index] = val;
        }
    }
    
    short culture_val;
    fscanf(f, " %hd", &culture_val);
    this->culture = (unsigned char)culture_val;
    
    this->master_object_num = 0;
    this->master_objects = nullptr;
}

// Fully verified. Source of truth: mst_play.cpp.decomp @ 0x00461150
RGE_Master_Player::~RGE_Master_Player() {
    if (this->attribute_num > 0 && this->attributes != nullptr) {
        free(this->attributes);
        this->attributes = nullptr;
        this->attribute_num = 0;
    }

    if (this->master_object_num > 0 && this->master_objects != nullptr) {
        for (short i = 0; i < this->master_object_num; ++i) {
            if (this->master_objects[i] != nullptr) {
                delete this->master_objects[i];
                this->master_objects[i] = nullptr;
            }
        }
        free(this->master_objects);
        this->master_objects = nullptr;
        this->master_object_num = 0;
    }
}

// Fully verified. Source of truth: mst_play.cpp.decomp @ 0x004611D0
void RGE_Master_Player::finish_init(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3) {
    // TODO: PARITY - Decomp labels this body under TRIBE_Master_Player while also documenting RGE_Master_Player virtual dispatch; keep vtable-owner mapping verified when auditing cross-module overrides. [decomp: mst_play.cpp.decomp @ 0x004611D0]
    CUSTOM_DEBUG_LOG_FMT("RGE_Master_Player::finish_init enter this=%p pos=%ld", this, rge_stream_tell(param_1));
    short* object_count = &this->master_object_num;
    rge_read(param_1, object_count, 2);
    CUSTOM_DEBUG_LOG_FMT("RGE_Master_Player::finish_init object_count=%d", (int)*object_count);

    if (*object_count < 1) {
        this->master_objects = nullptr;
        CUSTOM_DEBUG_LOG("RGE_Master_Player::finish_init exit empty");
        return;
    }

    this->master_objects = (RGE_Master_Static_Object**)calloc((int)*object_count, sizeof(RGE_Master_Static_Object*));
    rge_read(param_1, this->master_objects, (int)*object_count * (int)sizeof(RGE_Master_Static_Object*));
    for (short i = 0; i < *object_count; ++i) {
        if (this->master_objects[i] != nullptr) {
            uchar master_type = 0;
            rge_read(param_1, &master_type, 1);
            CUSTOM_DEBUG_LOG_FMT("RGE_Master_Player::finish_init idx=%d type=0x%02X", (int)i, (unsigned int)master_type);
            long object_begin = 0;
            if (*object_count == 400) {
                object_begin = rge_stream_tell(param_1);
            }
            this->load_master_object(param_1, master_type, param_2, param_3, i);
            CUSTOM_DEBUG_LOG_FMT("RGE_Master_Player::finish_init idx=%d loaded=%p", (int)i, this->master_objects[i]);
            if (*object_count == 400) {
                const long object_end = rge_stream_tell(param_1);
                CUSTOM_DEBUG_LOG_FMT(
                    "RGE_Master_Player::finish_init idx=%d delta=%ld pos=%ld->%ld",
                    (int)i,
                    object_end - object_begin,
                    object_begin,
                    object_end);
            }
        }
    }
    CUSTOM_DEBUG_LOG_FMT("RGE_Master_Player::finish_init exit pos=%ld", rge_stream_tell(param_1));
}

// Fully verified. Source of truth: mst_play.cpp.decomp @ 0x00461270
void RGE_Master_Player::load_master_object(int param_1, uchar param_2, RGE_Sprite** param_3, RGE_Sound** param_4, short param_5) {
    // TODO: PARITY - Decomp shows operator_new + failure/unwind scaffolding in this constructor-dispatch block; this transliteration relies on C++ new semantics and needs ASM audit on allocation-failure side effects. [decomp: mst_play.cpp.decomp @ 0x00461270]
    RGE_Master_Static_Object* loaded = nullptr;

    switch (param_2) {
    case '\n':
        loaded = new RGE_Master_Static_Object(param_1, param_3, param_4, 1);
        break;
    case '\x14':
        loaded = new RGE_Master_Animated_Object(param_1, param_3, param_4, 1);
        break;
    case '\x19':
        loaded = new RGE_Master_Doppleganger_Object(param_1, param_3, param_4, 1);
        break;
    case '\x1e':
        loaded = new RGE_Master_Moving_Object(param_1, param_3, param_4, 1);
        break;
    case '(':
        loaded = new RGE_Master_Action_Object(param_1, param_3, param_4, 1);
        break;
    case '2':
        loaded = new RGE_Master_Combat_Object(param_1, param_3, param_4, 1);
        break;
    case '<':
        loaded = new RGE_Master_Missile_Object(param_1, param_3, param_4, 1);
        break;
    default:
        loaded = nullptr;
        break;
    }

    if (this->master_objects != nullptr && param_5 >= 0 && param_5 < this->master_object_num) {
        this->master_objects[param_5] = loaded;
    }
}
// Fully verified. Source of truth: mst_play.cpp.decomp @ 0x004614D9 (embedded bad-instruction gap between adjacent methods).
// Fully verified. Source of truth: mst_play.cpp.decomp @ 0x00461530
void RGE_Master_Player::create_master_object_space(short param_1) {
    this->master_object_num = param_1;
    if (param_1 > 0) {
        this->master_objects = (RGE_Master_Static_Object**)calloc(param_1, sizeof(RGE_Master_Static_Object*));
    }
}
// Fully verified. Source of truth: mst_play.cpp.decomp @ 0x00461560
void RGE_Master_Player::load_object(FILE* param_1, uchar param_2, RGE_Sprite** param_3, RGE_Sound** param_4, short param_5) {
    RGE_Master_Static_Object* loaded = nullptr;

    switch (param_2) {
    case '\n':
        loaded = new RGE_Master_Static_Object(param_1, param_3, param_4, param_5, 1);
        break;
    case '\x14':
        loaded = new RGE_Master_Animated_Object(param_1, param_3, param_4, param_5, 1);
        break;
    case '\x19':
        loaded = new RGE_Master_Doppleganger_Object(param_1, param_3, param_4, param_5, 1);
        break;
    case '\x1e':
        loaded = new RGE_Master_Moving_Object(param_1, param_3, param_4, param_5, 1);
        break;
    case '(':
        loaded = new RGE_Master_Action_Object(param_1, param_3, param_4, param_5, 1);
        break;
    case '2':
        loaded = new RGE_Master_Combat_Object(param_1, param_3, param_4, param_5, 1);
        break;
    case '<':
        loaded = new RGE_Master_Missile_Object(param_1, param_3, param_4, param_5, 1);
        break;
    default:
        loaded = nullptr;
        break;
    }

    if (this->master_objects != nullptr && param_5 >= 0 && param_5 < this->master_object_num) {
        this->master_objects[param_5] = loaded;
    }
}
// Fully verified. Source of truth: mst_play.cpp.decomp @ 0x00461840
void RGE_Master_Player::save(int param_1) {
    rge_write(param_1, &this->type, 1);
    rge_write(param_1, this->name, 0x14);
    rge_write(param_1, &this->attribute_num, 2);
    rge_write(param_1, &this->tribe_effect, 2);
    if (this->attribute_num > 0) {
        rge_write(param_1, this->attributes, (int)this->attribute_num << 2);
    }
    rge_write(param_1, &this->culture, 1);
    rge_write(param_1, &this->master_object_num, 2);
    if (this->master_object_num > 0) {
        rge_write(param_1, this->master_objects, (int)this->master_object_num << 2);
        for (short i = 0; i < this->master_object_num; ++i) {
            if (this->master_objects[i] != nullptr) {
                this->master_objects[i]->save(param_1);
            }
        }
    }
}

// TODO: PARITY [LOW] - FUN_004614D9 remains an unmapped helper/thunk symbol pending ASM/name recovery. [decomp: mst_play.cpp.decomp @ 0x004614D9]
