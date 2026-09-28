
#include "../include/effects.h"
#include "../include/player.h"
#include <stdio.h>
#include <stdlib.h>

void __cdecl rge_read(int fd, void* buf, int size);
void __cdecl rge_write(int fd, void* buf, int size);
void convert_us(char* s);

// The original constructor keeps the first record name as the name-read base
// while its count and command fields use the running record offset.
RGE_Effects::RGE_Effects(int infile) {
    int input_file = infile;
    long* effect_num_ptr = &this->effect_num;
    int index;
    rge_read(input_file, effect_num_ptr, 4);
    if (*effect_num_ptr > 0) {
        this->effects = (RGE_Effect*)calloc(*effect_num_ptr, 44);
        index = 0;
        if (index < *effect_num_ptr) {
            do {
                RGE_Effect* base_effect;
                RGE_Effect* effect_record;
                base_effect = this->effects;
                effect_record = &this->effects[index];
                rge_read(input_file, base_effect->name, 31);
                rge_read(input_file, &effect_record->effect_list_num, 2);
                if (effect_record->effect_list_num > 0) {
                    int command_index;
                    RGE_Effect_Command*& effect_list = effect_record->effect_list;
                    RGE_Effect_Command* allocated =
                        (RGE_Effect_Command*)calloc(effect_record->effect_list_num, 12);
                    command_index = 0;
                    effect_list = allocated;
                    if (command_index < effect_record->effect_list_num) {
                        do {
                            RGE_Effect_Command* command =
                                &effect_list[command_index];
                            rge_read(input_file, &command->command, 1);
                            rge_read(input_file, &command->change_num1, 2);
                            rge_read(input_file, &command->change_num2, 2);
                            rge_read(input_file, &command->change_num3, 2);
                            rge_read(input_file, &command->change_amount, 4);
                            command_index++;
                        } while (command_index < effect_record->effect_list_num);
                    }
                } else {
                    effect_record->effect_list = 0;
                }
                index++;
            } while (index < this->effect_num);
        }
    } else {
        this->effects = 0;
        this->effect_num = 0;
    }
}

RGE_Effects::RGE_Effects(char* effect_file) {
    FILE* fp;
    long count;
    long index;
    long this_effect_num;
    short effect_command;

    fp = fopen(effect_file, "r");
    if (fp != 0) {
        if (fscanf(fp, "%d %d", &effect_num, &count) != -1) {
            effects = (RGE_Effect*)calloc(effect_num, 44);
            for (index = 0; index < count; index++) {
                short command_index = 0;
                fscanf(fp, "%d", &this_effect_num);
                if (fscanf(fp, "%s %hd", effects[this_effect_num].name, &effects[this_effect_num].effect_list_num) == -1) break;
                effects[this_effect_num].id = (short)this_effect_num;
                if (effects[this_effect_num].effect_list_num > 0) {
                    effects[this_effect_num].effect_list = (RGE_Effect_Command*)calloc(effects[this_effect_num].effect_list_num, 12);
                    if (effects[this_effect_num].effect_list_num > 0) {
                        while (effects[this_effect_num].effect_list_num > command_index) {
                            RGE_Effect_Command* command = &effects[this_effect_num].effect_list[command_index];
                            if (fscanf(fp, "%hd %hd %hd %hd %f", &effect_command, &command->change_num1, &command->change_num2, &command->change_num3, &command->change_amount) == -1) break;
                            command_index++;
                            command->command = (unsigned char)effect_command;
                        }
                    }
                } else {
                    effects[this_effect_num].effect_list = 0;
                }
                convert_us(effects[this_effect_num].name);
            }
        } else {
            effect_num = 0;
            effects = 0;
        }
        fclose(fp);
    } else {
        effect_num = 0;
        effects = 0;
    }
}

RGE_Effects::~RGE_Effects() {
    for (short effect_index = 0; effect_index < effect_num; effect_index++) {
        if (effects[effect_index].effect_list != 0) {
            free(effects[effect_index].effect_list);
        }
        effects[effect_index].effect_list = 0;
    }
    if (effects != 0) {
        free(effects);
        effects = 0;
    }
    effect_num = 0;
}

void RGE_Effects::save(int outfile) {
    long* effect_num_ptr = &this->effect_num;
    RGE_Effect* record;
    int output_file = outfile;
    int index;

    rge_write(outfile, effect_num_ptr, 4);
    index = 0;
    if (*effect_num_ptr > 0) {
        outfile = 0;
        do {
            record = this->effects + index;
            rge_write(output_file, this->effects->name, 31);
            rge_write(output_file, &record->effect_list_num, 2);
            int command_index = 0;
            if (record->effect_list_num > 0) {
                do {
                    RGE_Effect_Command* command = &record->effect_list[command_index];
                    rge_write(output_file, &command->command, 1);
                    rge_write(output_file, &command->change_num1, 2);
                    rge_write(output_file, &command->change_num2, 2);
                    rge_write(output_file, &command->change_num3, 2);
                    rge_write(output_file, &command->change_amount, 4);
                    command_index++;
                } while (command_index < record->effect_list_num);
            }
            index++;
            outfile += 0x2C;
        } while (index < this->effect_num);
    }
}

void RGE_Effects::do_effect(short current_effect, RGE_Player* player) {
    if (current_effect < effect_num) {
        RGE_Effect* effect = &effects[current_effect];
        if (effect) {
            for (short command_index = 0; command_index < effect->effect_list_num; command_index++) {
                RGE_Effect_Command* command = &effect->effect_list[command_index];
                //! Cases 0-5 only. No case 6, so Resource Modifier (Multiply) is dropped.
                //! The row loads from the data file, then does nothing when the tech runs.
                //! No default case exists, so the drop is silent.
                switch (command->command) {
                case 4: {
                    short operation = command->change_num3;
                    float amount = command->change_amount;
                    player->modify_tobj_delta(command->change_num1, command->change_num2, amount, (unsigned char)operation);
                    break;
                }
                case 5: {
                    short operation = command->change_num3;
                    float amount = command->change_amount;
                    player->modify_tobj_percent(command->change_num1, command->change_num2, amount,
                                                (unsigned char)operation);
                    break;
                }
                case 0: {
                    short operation = command->change_num3;
                    float amount = command->change_amount;
                    player->modify_tobj(command->change_num1, command->change_num2, amount, (unsigned char)operation);
                    break;
                }
                case 1: {
                    short attribute = command->change_num1;
                    short mode = command->change_num2;
                    float amount = command->change_amount;
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
                    if (command->change_num1 > -1) {
                        player->make_available(command->change_num1, (unsigned char)command->change_num2);
                    }
                    break;
                case 3:
                    player->copy_obj(command->change_num1, command->change_num2);
                    break;
                }
            }
        }
    }
}
