#include "../include/RGE_Effects.h"
#include "../include/RGE_Effect.h"
#include "../include/RGE_Effect_Command.h"
#include "../include/RGE_Player.h"
#include "../include/globals.h"
#include "../include/mystring.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fully verified. Source of truth: effects.cpp.decomp @ 0x004496ED
static int FUN_004496ed(const void* lhs, const void* rhs) {
    const unsigned char* a = (const unsigned char*)lhs;
    const unsigned char* b = (const unsigned char*)rhs;
    while ((*a != 0) && (*a == *b)) {
        ++a;
        ++b;
    }
    return (int)*a - (int)*b;
}

// Fully verified. Marker reconciliation coverage.
RGE_Effects::RGE_Effects() {
    this->effect_num = 0;
    this->effects = nullptr;
}

// Fully verified. Marker reconciliation coverage.
RGE_Effects::RGE_Effects(char* param_1) {
    // Fully verified. Source of truth: effects.cpp.decomp @ 0x00449260
    FILE* file = fopen(param_1, "r");
    if (file == nullptr) {
        this->effect_num = 0;
        this->effects = nullptr;
        return;
    }

    long parsed_count = 0;
    if (fscanf(file, "%d %d", &this->effect_num, &parsed_count) == EOF) {
        this->effect_num = 0;
        this->effects = nullptr;
    } else {
        this->effects = (RGE_Effect*)calloc(this->effect_num, sizeof(RGE_Effect));
        long count = 0;
        if (0 < parsed_count) {
            while (true) {
                long index = 0;
                short command_count = 0;
                fscanf(file, "%d", &index);
                if (fscanf(file, "%s %hd", this->effects[index].name, &this->effects[index].effect_list_num) == EOF) {
                    break;
                }

                this->effects[index].id = (short)index;
                if (this->effects[index].effect_list_num < 1) {
                    this->effects[index].effect_list = nullptr;
                } else {
                    this->effects[index].effect_list = (RGE_Effect_Command*)calloc(this->effects[index].effect_list_num, sizeof(RGE_Effect_Command));
                    if (0 < this->effects[index].effect_list_num) {
                        for (short i = 0; i < this->effects[index].effect_list_num; ++i) {
                            RGE_Effect_Command* command = this->effects[index].effect_list + i;
                            if (fscanf(file, "%hd %hd %hd %hd %f", &command_count, &command->change_num1, &command->change_num2, &command->change_num3, &command->change_amount) == EOF) {
                                break;
                            }
                            command->command = (uchar)command_count;
                        }
                    }
                }

                convert_us(this->effects[index].name);
                ++count;
                if (parsed_count <= count) {
                    fclose(file);
                    return;
                }
            }
        }
    }

    fclose(file);
}

// Fully verified. Marker reconciliation coverage.
RGE_Effects::RGE_Effects(int fd) {
    // Fully verified. Source of truth: effects.cpp.decomp @ 0x004490E0
    rge_read(fd, &this->effect_num, 4);
    if (this->effect_num < 1) {
        this->effects = nullptr;
        this->effect_num = 0;
    } else {
        this->effects = (RGE_Effect*)calloc(this->effect_num, sizeof(RGE_Effect));
        for (int i = 0; i < this->effect_num; i++) {
            RGE_Effect* effect = &this->effects[i];
            effect->id = (short)i;
            rge_read(fd, effect->name, 31);
            rge_read(fd, &effect->effect_list_num, sizeof(effect->effect_list_num));
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
    }
}

// Fully verified. Marker reconciliation coverage.
RGE_Effects::~RGE_Effects() {
    // Fully verified. Source of truth: effects.cpp.decomp @ 0x00449440
    if (0 < this->effect_num) {
        for (int i = 0; i < this->effect_num; ++i) {
            if (this->effects[i].effect_list != nullptr) {
                free(this->effects[i].effect_list);
            }
            this->effects[i].effect_list = nullptr;
        }
    }
    if (this->effects != nullptr) {
        free(this->effects);
        this->effects = nullptr;
    }
    this->effect_num = 0;
}

// Fully verified. Marker reconciliation coverage.
void RGE_Effects::save(int fd) {
    // Fully verified. Source of truth: effects.cpp.decomp @ 0x004494B0
    rge_write(fd, &this->effect_num, 4);
    for (int i = 0; i < this->effect_num; i++) {
        RGE_Effect* effect = &this->effects[i];
        rge_write(fd, effect->name, 31);
        rge_write(fd, &effect->effect_list_num, 2);
        for (short j = 0; j < effect->effect_list_num; j++) {
            RGE_Effect_Command* cmd = &effect->effect_list[j];
            rge_write(fd, &cmd->command, 1);
            rge_write(fd, &cmd->change_num1, 2);
            rge_write(fd, &cmd->change_num2, 2);
            rge_write(fd, &cmd->change_num3, 2);
            rge_write(fd, &cmd->change_amount, 4);
        }
    }
}

// Fully verified. Marker reconciliation coverage.
void RGE_Effects::do_effect(short p1, RGE_Player* p2) {
    // Fully verified. Source of truth: effects.cpp.decomp @ 0x004495C0
    if ((int)p1 < this->effect_num) {
        RGE_Effect* effect = this->effects + p1;
        if (effect != nullptr && effect->effect_list_num > 0) {
            short i = 0;
            do {
                RGE_Effect_Command* command_list = effect->effect_list;
                switch (command_list[i].command) {
                case 0:
                    p2->modify_tobj(command_list[i].change_num1, command_list[i].change_num2, command_list[i].change_amount, (uchar)command_list[i].change_num3);
                    break;
                case 1:
                    if (command_list[i].change_num1 >= 0) {
                        if (command_list[i].change_num2 == 0) {
                            p2->new_attribute_num(command_list[i].change_num1, command_list[i].change_amount);
                        } else {
                            p2->add_attribute_num(command_list[i].change_num1, command_list[i].change_amount, 0);
                        }
                    }
                    break;
                case 2:
                    if (command_list[i].change_num1 >= 0) {
                        p2->make_available(command_list[i].change_num1, (uchar)command_list[i].change_num2);
                    }
                    break;
                case 3:
                    p2->copy_obj(command_list[i].change_num1, command_list[i].change_num2);
                    break;
                case 4:
                    p2->modify_tobj_delta(command_list[i].change_num1, command_list[i].change_num2, command_list[i].change_amount, (uchar)command_list[i].change_num3);
                    break;
                case 5:
                    p2->modify_tobj_percent(command_list[i].change_num1, command_list[i].change_num2, command_list[i].change_amount, (uchar)command_list[i].change_num3);
                    break;
                }
                i = i + 1;
            } while (i < effect->effect_list_num);
        }
    }
}
