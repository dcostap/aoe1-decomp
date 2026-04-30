// VA: 004494B0 RGE_Effects::save(int fd)
// effects.cpp lines 140-183
// 265 bytes
// BLOCKER: same register allocation issue as the int ctor.
// The original uses esi=this but with a different register order.
// Rebuilt patterns all produce different prologue/frame code.
//
// Attempt log:
// - natural pattern mirroring ctor: diverse register allocation
// - int* num = &effect_num: same
// - for loops with offsets: different prologue
// FLAGS: none

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
    int* num = &effect_num;
    rge_write(fd, num, 4);
    if (*num > 0) {
        for (int i = 0; i < *num; i++) {
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
