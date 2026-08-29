
#include "../include/effects.h"
#include "../include/player.h"
#include <stdio.h>
#include <stdlib.h>

void __cdecl rge_read(int fd, void* buf, int size);
void __cdecl rge_write(int fd, void* buf, int size);
void convert_us(char* s);

// The original constructor keeps the first record name as the name-read base
// while its count and command fields use the running record offset.
RGE_Effects::RGE_Effects(int fd) {
    int file = fd;
    long* peffect = &this->effect_num;
    int outer_count;
    rge_read(file, peffect, 4);
    if (*peffect > 0) {
        this->effects = (RGE_Effect*)calloc(*peffect, 0x2C);
        outer_count = 0;
        if (outer_count < *peffect) {
            do {
                RGE_Effect* effect;
                RGE_Effect* fields;
                effect = this->effects;
                fields = &this->effects[outer_count];
                rge_read(file, effect->name, 0x1F);
                rge_read(file, &fields->effect_list_num, 2);
                if (fields->effect_list_num > 0) {
                    int inner_count;
                    RGE_Effect_Command*& list = fields->effect_list;
                    RGE_Effect_Command* allocated =
                        (RGE_Effect_Command*)calloc(fields->effect_list_num, 0x0C);
                    inner_count = 0;
                    if (inner_count < fields->effect_list_num) {
                        list = allocated;
                        do {
                            RGE_Effect_Command* command =
                                &list[inner_count];
                            rge_read(file, &command->command, 1);
                            rge_read(file, &command->change_num1, 2);
                            rge_read(file, &command->change_num2, 2);
                            rge_read(file, &command->change_num3, 2);
                            rge_read(file, &command->change_amount, 4);
                            inner_count++;
                        } while (inner_count < fields->effect_list_num);
                    }
                } else {
                    fields->effect_list = 0;
                }
                outer_count++;
            } while (outer_count < this->effect_num);
        }
    } else {
        this->effects = 0;
        this->effect_num = 0;
    }
}

RGE_Effects::RGE_Effects(char* path) {
    int local_4, index, count;

    FILE* fp = fopen(path, "r");
    if (fp != 0) {
        if (fscanf(fp, "%d %d", &effect_num, &local_4) != -1) {
            effects = (RGE_Effect*)calloc(effect_num, 0x2C);
            for (count = 0; count < local_4; count++) {
                short sVar7 = 0;
                fscanf(fp, "%d", &index);
                if (fscanf(fp, "%s %hd", effects[index].name, &effects[index].effect_list_num) == -1) break;
                effects[index].id = (short)index;
                if (effects[index].effect_list_num > 0) {
                    effects[index].effect_list = (RGE_Effect_Command*)calloc(effects[index].effect_list_num, 0x0C);
                    if (effects[index].effect_list_num > 0) {
                        while (effects[index].effect_list_num > sVar7) {
                            RGE_Effect_Command* command = &effects[index].effect_list[sVar7];
                            short command_num;
                            if (fscanf(fp, "%hd %hd %hd %hd %f", &command_num, &command->change_num1, &command->change_num2, &command->change_num3, &command->change_amount) == -1) break;
                            sVar7++;
                            command->command = (unsigned char)command_num;
                        }
                    }
                } else {
                    effects[index].effect_list = 0;
                }
                convert_us(effects[index].name);
            }
            fclose(fp);
        } else {
            effect_num = 0;
            effects = 0;
            fclose(fp);
        }
    } else {
        effect_num = 0;
        effects = 0;
    }
}

RGE_Effects::~RGE_Effects() {
    for (short i = 0; i < effect_num; i++) {
        if (effects[i].effect_list != 0) {
            free(effects[i].effect_list);
        }
        effects[i].effect_list = 0;
    }
    if (effects != 0) {
        free(effects);
        effects = 0;
    }
    effect_num = 0;
}

void RGE_Effects::save(int fd) {
    long* num = &this->effect_num;
    RGE_Effect* record;
    int handle = fd;
    int index;

    rge_write(fd, num, 4);
    index = 0;
    if (*num > 0) {
        fd = 0;
        do {
            record = this->effects + index;
            rge_write(handle, this->effects->name, 0x1F);
            rge_write(handle, &record->effect_list_num, 2);
            int inner = 0;
            if (record->effect_list_num > 0) {
                do {
                    RGE_Effect_Command* command = &record->effect_list[inner];
                    rge_write(handle, &command->command, 1);
                    rge_write(handle, &command->change_num1, 2);
                    rge_write(handle, &command->change_num2, 2);
                    rge_write(handle, &command->change_num3, 2);
                    rge_write(handle, &command->change_amount, 4);
                    inner++;
                } while (inner < record->effect_list_num);
            }
            index++;
            fd += 0x2C;
        } while (index < this->effect_num);
    }
}

void RGE_Effects::do_effect(short effect_id, RGE_Player* player) {
    if (effect_id < effect_num) {
        RGE_Effect* eff = &effects[effect_id];
        if (eff) {
            for (short i = 0; i < eff->effect_list_num; i++) {
                RGE_Effect_Command* cmd = &eff->effect_list[i];
                switch (cmd->command) {
                case 4: {
                    short operation = cmd->change_num3;
                    float amount = cmd->change_amount;
                    player->modify_tobj_delta(cmd->change_num1, cmd->change_num2,
                                              amount,
                                              (unsigned char)operation);
                    break;
                }
                case 5: {
                    short operation = cmd->change_num3;
                    float amount = cmd->change_amount;
                    player->modify_tobj_percent(cmd->change_num1, cmd->change_num2,
                                                amount,
                                                (unsigned char)operation);
                    break;
                }
                case 0: {
                    short operation = cmd->change_num3;
                    float amount = cmd->change_amount;
                    player->modify_tobj(cmd->change_num1, cmd->change_num2,
                                        amount,
                                        (unsigned char)operation);
                    break;
                }
                case 1: {
                    short attribute = cmd->change_num1;
                    short mode = cmd->change_num2;
                    float amount = cmd->change_amount;
                    if (attribute > -1) {
                        if (mode == 0) {
                            player->new_attribute_num(attribute, amount);
                        } else {
                            player->add_attribute_num(attribute, amount, 0);
                        }
                    }
                    break;
                }
                case 2:
                    if (cmd->change_num1 > -1) {
                        player->make_available(cmd->change_num1, (unsigned char)cmd->change_num2);
                    }
                    break;
                case 3:
                    player->copy_obj(cmd->change_num1, cmd->change_num2);
                    break;
                }
            }
        }
    }
}
