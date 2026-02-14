#include "../include/RGE_Effects.h"
#include "../include/RGE_Effect.h"
#include "../include/RGE_Effect_Command.h"
#include "../include/globals.h"
#include <stdlib.h>
#include <string.h>

RGE_Effects::RGE_Effects() {
    this->effect_num = 0;
    this->effects = nullptr;
}

RGE_Effects::RGE_Effects(char* param_1) {
    this->effect_num = 0;
    this->effects = nullptr;
}

// Source of truth: effects.cpp.decomp
RGE_Effects::RGE_Effects(int fd) {
    rge_read(fd, &this->effect_num, 4);
    if (this->effect_num > 0) {
        this->effects = (RGE_Effect*)calloc(this->effect_num, sizeof(RGE_Effect));
        for (int i = 0; i < this->effect_num; i++) {
            RGE_Effect* effect = &this->effects[i];
            effect->id = (short)i;
            rge_read(fd, effect->name, 31);
            rge_read(fd, &effect->effect_list_num, 2);
            if (effect->effect_list_num > 0) {
                effect->effect_list = (RGE_Effect_Command*)calloc(effect->effect_list_num, sizeof(RGE_Effect_Command));
                for (int j = 0; j < effect->effect_list_num; j++) {
                    RGE_Effect_Command* cmd = &effect->effect_list[j];
                    rge_read(fd, &cmd->command, 1);
                    rge_read(fd, &cmd->change_num1, 2);
                    rge_read(fd, &cmd->change_num2, 2);
                    rge_read(fd, &cmd->change_num3, 2);
                    rge_read(fd, &cmd->change_amount, 4);
                }
            } else {
                effect->effect_list = nullptr;
            }
        }
    } else {
        this->effect_num = 0;
        this->effects = nullptr;
    }
}

RGE_Effects::~RGE_Effects() {
    if (this->effects) {
        for (int i = 0; i < this->effect_num; i++) {
            if (this->effects[i].effect_list) {
                free(this->effects[i].effect_list);
            }
        }
        free(this->effects);
    }
}

void RGE_Effects::save(int fd) {
    rge_write(fd, &this->effect_num, 4);
    for (int i = 0; i < this->effect_num; i++) {
        rge_write(fd, this->effects[i].name, 31);
        rge_write(fd, &this->effects[i].effect_list_num, 2);
        for (short j = 0; j < this->effects[i].effect_list_num; j++) {
            RGE_Effect_Command* cmd = &this->effects[i].effect_list[j];
            rge_write(fd, &cmd->command, 1);
            rge_write(fd, &cmd->change_num1, 2);
            rge_write(fd, &cmd->change_num2, 2);
            rge_write(fd, &cmd->change_num3, 2);
            rge_write(fd, &cmd->change_amount, 4);
        }
    }
}

void RGE_Effects::do_effect(short p1, RGE_Player* p2) {}
