// VA: 00449260 RGE_Effects::RGE_Effects(char* path)
// effects.cpp lines 68-129
// 478 bytes

// attempt 6: vtable after fopen, register short sVar7

#include <stdio.h>
#include <stdlib.h>

void convert_us(char* s);

struct RGE_Effect_Command {
    unsigned char command; unsigned char _pad_0;
    short change_num1; short change_num2; short change_num3; float change_amount;
};

struct RGE_Effect {
    short id; char name[31]; unsigned char _pad_0;
    short string_table_id; short effect_list_num;
    unsigned char _pad_1[2]; RGE_Effect_Command* effect_list;
};

struct RGE_Effects {
    void* vtable_ptr; RGE_Effect* effects; long effect_num;
    RGE_Effects(char* path);
};

RGE_Effects::RGE_Effects(char* path) {
    vtable_ptr = (void*)0x570430;
    int local_4, index, count;

    FILE* fp = fopen(path, "r");
    if (fp == 0) {
        effect_num = 0;
        effects = 0;
    } else {
        if (fscanf(fp, "%d %d", &effect_num, &local_4) == -1) {
            effect_num = 0;
            effects = 0;
        } else {
            effects = (RGE_Effect*)calloc(effect_num, 0x2C);
            for (count = 0; count < local_4; count++) {
                register short sVar7 = 0;
                fscanf(fp, "%d", &index);
                if (fscanf(fp, "%s %hd", effects[index].name, &effects[index].effect_list_num) == -1) break;
                effects[index].id = (short)index;
                if (effects[index].effect_list_num < 1) {
                    effects[index].effect_list = 0;
                } else {
                    effects[index].effect_list = (RGE_Effect_Command*)calloc(effects[index].effect_list_num, 0x0C);
                    if (effects[index].effect_list_num > 0) {
                        do {
                            if (fscanf(fp, "%hd %hd %hd %hd %f", &sVar7, &effects[index].effect_list[sVar7].change_num1, &effects[index].effect_list[sVar7].change_num2, &effects[index].effect_list[sVar7].change_num3, &effects[index].effect_list[sVar7].change_amount) == -1) break;
                            effects[index].effect_list[sVar7].command = (unsigned char)sVar7;
                            sVar7++;
                        } while (sVar7 < effects[index].effect_list_num);
                    }
                }
                convert_us(effects[index].name);
            }
            fclose(fp);
        }
    }
}
