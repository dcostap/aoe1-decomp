// VA: 00449260 RGE_Effects::RGE_Effects(char* path)
// effects.cpp lines 68-129
// 478 bytes

// attempt 1: text file fscanf constructor
// ret 4, __thiscall

#include <stdio.h>

void* __cdecl calloc(int count, int size);
int __cdecl fclose(FILE* stream);
void __cdecl convert_us(char* name);

struct RGE_Effect_Command {
    char command;       // +0x00
    char pad;           // +0x01
    short change_num1;  // +0x02
    short change_num2;  // +0x04
    short change_num3;  // +0x06
    float change_amount; // +0x08
};

struct RGE_Effect {
    short id;                   // +0x00
    char name[0x22];            // +0x02
    short effect_list_num;      // +0x24
    short pad2;                 // +0x26
    RGE_Effect_Command* effect_list; // +0x28
};

struct RGE_Effects {
    int* vtable;        // +0x00
    RGE_Effect* effects; // +0x04
    int effect_num;      // +0x08

    RGE_Effects(char* path);
};

extern int DAT_00570430;

RGE_Effects::RGE_Effects(char* path) {
    vtable = &DAT_00570430;
    FILE* f = fopen(path, "r");
    if (f == 0) {
        effect_num = 0;
        effects = 0;
        return;
    }
    int count;
    int num_read = fscanf(f, "%d %d", &effect_num, &count);
    if (num_read == -1) {
        effect_num = 0;
        effects = 0;
    } else {
        effects = (RGE_Effect*)calloc(effect_num, 0x2C);
        int i;
        for (i = 0; i < count; i++) {
            int index;
            fscanf(f, "%d", &index);
            num_read = fscanf(f, "%s %hd", effects[index].name, &effects[index].effect_list_num);
            if (num_read == -1) break;
            effects[index].id = (short)index;
            if (effects[index].effect_list_num > 0) {
                effects[index].effect_list = (RGE_Effect_Command*)calloc(effects[index].effect_list_num, 0x0C);
                RGE_Effect* eff = &effects[index];
                int j;
                for (j = 0; j < eff->effect_list_num; j++) {
                    RGE_Effect_Command* cmd = &eff->effect_list[j];
                    char temp;
                    num_read = fscanf(f, "%hd %hd %hd %hd %f", &temp, &cmd->change_num1, &cmd->change_num2, &cmd->change_num3, &cmd->change_amount);
                    if (num_read == -1) break;
                    cmd->command = temp;
                }
            } else {
                effects[index].effect_list = 0;
            }
            convert_us(effects[index].name);
        }
        fclose(f);
    }
}
