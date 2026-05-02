// VA: 004494B0 RGE_Effects::save(int fd)
// effects.cpp lines 140-183
// 265 bytes
// BLOCKER: first 20 bytes match perfectly (prologue/frame/es=this),
// but stack layout differs from offset 20 (this saved at different slot).
// The remaining diff is all shifted stack offsets from this one difference.
//
// Attempt log:
// - with RGE_Effect* eff local: first 20 bytes match (best result: 74% diff)
// - without eff local: prologue breaks (83% diff)
// - int* num = &effect_num: same 83% diff
// - natural nested for loops: 74% first 20 bytes match
// FLAGS: none
// NOTE: very close - the stack layout diff at byte 20 suggests one extra
// local variable in our version vs the original.

void __cdecl rge_write(int fd, void* buf, int size);

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
    void save(int fd);
};

void RGE_Effects::save(int fd) {
    rge_write(fd, &effect_num, 4);
    if (effect_num > 0) {
        for (int i = 0; i < effect_num; i++) {
            RGE_Effect* eff = &effects[i];
            rge_write(fd, eff->name, 0x1F);
            rge_write(fd, &eff->effect_list_num, 2);
            if (eff->effect_list_num > 0) {
                for (int j = 0; j < eff->effect_list_num; j++) {
                    RGE_Effect_Command* cmd = &eff->effect_list[j];
                    rge_write(fd, &cmd->command, 1);
                    rge_write(fd, &cmd->change_num1, 2);
                    rge_write(fd, &cmd->change_num2, 2);
                    rge_write(fd, &cmd->change_num3, 2);
                    rge_write(fd, &cmd->change_amount, 4);
                }
            }
        }
    }
}
