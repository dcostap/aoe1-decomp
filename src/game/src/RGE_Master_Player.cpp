#include "../include/RGE_Master_Player.h"
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

void RGE_Master_Player::finish_init(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3) {}
void RGE_Master_Player::load_master_object(int param_1, uchar param_2, RGE_Sprite** param_3, RGE_Sound** param_4, short param_5) {}
void RGE_Master_Player::create_master_object_space(short param_1) {
    this->master_object_num = param_1;
    if (param_1 > 0) {
        this->master_objects = (RGE_Master_Static_Object**)calloc(param_1, sizeof(RGE_Master_Static_Object*));
    }
}
void RGE_Master_Player::load_object(FILE* param_1, uchar param_2, RGE_Sprite** param_3, RGE_Sound** param_4, short param_5) {}
void RGE_Master_Player::save(int param_1) {}
