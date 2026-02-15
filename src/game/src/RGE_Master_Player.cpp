#include "../include/RGE_Master_Player.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Master_Animated_Object.h"
#include "../include/RGE_Master_Moving_Object.h"
#include "../include/RGE_Master_Action_Object.h"
#include "../include/RGE_Master_Combat_Object.h"
#include "../include/RGE_Master_Missile_Object.h"
#include "../include/RGE_Master_Doppleganger_Object.h"
#include "../include/custom_debug.h"
#include "../include/globals.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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

// Source of truth: mst_play.cpp.decomp / mst_play.cpp.asm
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

RGE_Master_Player::~RGE_Master_Player() {
    if (this->attributes) {
        free(this->attributes);
    }
    if (this->master_objects) {
        free(this->master_objects);
    }
}

void RGE_Master_Player::finish_init(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3) {
    const long begin_pos = rge_stream_tell(param_1);
    short* object_count = &this->master_object_num;
    rge_read(param_1, object_count, 2);
    CUSTOM_DEBUG_LOG_FMT(
        "RGE_Master_Player::finish_init begin stream_pos=%ld master_object_num=%d",
        begin_pos,
        (int)this->master_object_num);

    if (*object_count < 1) {
        this->master_objects = nullptr;
        CUSTOM_DEBUG_LOG_FMT("RGE_Master_Player::finish_init no objects stream_pos=%ld", rge_stream_tell(param_1));
        return;
    }

    this->master_objects = (RGE_Master_Static_Object**)calloc((int)*object_count, sizeof(RGE_Master_Static_Object*));
    if (this->master_objects == nullptr) {
        this->master_object_num = 0;
        CUSTOM_DEBUG_LOG_FMT("RGE_Master_Player::finish_init alloc failed stream_pos=%ld", rge_stream_tell(param_1));
        return;
    }

    rge_read(param_1, this->master_objects, (int)*object_count * (int)sizeof(RGE_Master_Static_Object*));
    int marker_non_null = 0;
    for (short i = 0; i < *object_count; ++i) {
        if (this->master_objects[i] != nullptr) {
            marker_non_null++;
        }
    }
    CUSTOM_DEBUG_LOG_FMT(
        "RGE_Master_Player::finish_init marker_table_done stream_pos=%ld non_null=%d/%d",
        rge_stream_tell(param_1),
        marker_non_null,
        (int)*object_count);

    for (short i = 0; i < *object_count; ++i) {
        if (this->master_objects[i] != nullptr) {
            uchar master_type = 0;
            const long type_pos = rge_stream_tell(param_1);
            rge_read(param_1, &master_type, 1);
            if (i < 24 || i + 1 == *object_count) {
                CUSTOM_DEBUG_LOG_FMT(
                    "RGE_Master_Player::finish_init object idx=%d type=0x%02X type_pos=%ld after_type_pos=%ld",
                    (int)i,
                    (unsigned int)master_type,
                    type_pos,
                    rge_stream_tell(param_1));
            }
            this->load_master_object(param_1, master_type, param_2, param_3, i);
        }
    }

    CUSTOM_DEBUG_LOG_FMT(
        "RGE_Master_Player::finish_init end stream_pos=%ld consumed=%ld",
        rge_stream_tell(param_1),
        rge_stream_tell(param_1) - begin_pos);
}

void RGE_Master_Player::load_master_object(int param_1, uchar param_2, RGE_Sprite** param_3, RGE_Sound** param_4, short param_5) {
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
void RGE_Master_Player::create_master_object_space(short param_1) {
    this->master_object_num = param_1;
    if (param_1 > 0) {
        this->master_objects = (RGE_Master_Static_Object**)calloc(param_1, sizeof(RGE_Master_Static_Object*));
    }
}
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
void RGE_Master_Player::save(int param_1) {}
