// VA: 004490E0 RGE_Effects::RGE_Effects(int fd)
// effects.cpp lines 21-63
// 352 bytes

// attempt 1: binary file read constructor
// ret 4, __thiscall

void __cdecl rge_read(int fd, void* buf, int size);
void* __cdecl calloc(int count, int size);
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

    RGE_Effects(int fd);
};

extern int DAT_00570430;

RGE_Effects::RGE_Effects(int fd) {
    vtable = &DAT_00570430;
    rge_read(fd, &effect_num, 4);
    if (effect_num > 0) {
        effects = (RGE_Effect*)calloc(effect_num, 0x2C);
        for (int i = 0; i < effect_num; i++) {
            RGE_Effect* eff = &effects[i];
            rge_read(fd, eff->name, 0x1F);
            rge_read(fd, &eff->effect_list_num, 2);
            if (eff->effect_list_num > 0) {
                eff->effect_list = (RGE_Effect_Command*)calloc(eff->effect_list_num, 0x0C);
                for (int j = 0; j < eff->effect_list_num; j++) {
                    RGE_Effect_Command* cmd = &eff->effect_list[j];
                    rge_read(fd, &cmd->command, 1);
                    rge_read(fd, &cmd->change_num1, 2);
                    rge_read(fd, &cmd->change_num2, 2);
                    rge_read(fd, &cmd->change_num3, 2);
                    rge_read(fd,