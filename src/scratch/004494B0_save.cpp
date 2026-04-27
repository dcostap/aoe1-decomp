// VA: 004494B0 RGE_Effects::save
// effects.cpp lines 154-180
// 265 bytes

// attempt 1: Mirror of ctor file-read logic via rge_write
// ret 4, __thiscall

void __cdecl rge_write(int fd, void* buf, int size);

struct RGE_Effect_Command {
    char command;       // +0x00
    char pad;           // +0x01
    short change_num1;  // +0x02
    short change_num2;  // +0x04
    short change_num3;  // +0x06
    float change_amount;// +0x08
};

struct RGE_Effect {
    short id;                   // +0x00
    char name[0x22];            // +0x02 (padded to 0x24)
    short effect_list_num;      // +0x24
    short pad2;                 // +0x26
    RGE_Effect_Command* effect_list; // +0x28
};

struct RGE_Effects {
    int* vtable;        // +0x00
    RGE_Effect* effects; // +0x04
    int effect_num;      // +0x08
};

void __thiscall RGE_Effects::save(int fd) {
    rge_write(fd, &effect_num, 4);
    int i;
    for (i = 0; i < effect_num; i++) {
        RGE_Effect* eff = &effects[i];
        rge_write(fd, eff->name, 0x1F);
        rge_write(fd, &eff->effect_list_num, 2);
        int j;
        for (j = 0; j < eff->effect_list_num; j++) {
            RGE_Effect_Command* cmd = &eff->effect_list[j];
            rge_write(fd, &cmd->command, 1);
            rge_write(fd, &cmd->change_num1, 2);
            rge_write(fd, &cmd->change_num2, 2);
            rge_write(fd, &cmd->change_num3, 2);
            rge_write(fd, &cmd->change_amount, 4);
        }
    }
}
