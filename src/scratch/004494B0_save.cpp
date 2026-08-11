// VA: 004494B0 RGE_Effects::save(int fd)
// effects.cpp lines 140-183
// 265 bytes
// BLOCKER: the natural candidate has the complete rge_write call set and
// canonical record widths, but VC5 chooses a different frame/register basin
// from the original at the prologue and inner-loop stack homes.
//
// Attempt log:
// - with RGE_Effect* eff local: first 20 bytes match (best result: 74% diff)
// - without eff local: prologue breaks (83% diff)
// - int* num = &effect_num: same 83% diff
// - natural nested for loops: 74% first 20 bytes match
// - outer do/while with typed effect[i] ownership: removed duplicate guards,
//   but introduced early EBP save and a different loop basin
// - serialized byte-cursor form: preserves the binary-observed base-name
//   access and offset-based count/list fields; frame remains 0x10 vs 0x14
// - function-scope pointer/counter declarations and virtual save ABI: no
//   emitted-code improvement; register-qualified counters were unchanged
// FLAGS: none
// NOTE: exact calls/targets and record layout are established. Remaining
// mismatch is structural VC5 register/local-home allocation, not a call or
// field-width uncertainty.

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
    virtual void save(int fd);
};

void RGE_Effects::save(int fd) {
    long* num = &effect_num;
    char* count_ptr;
    RGE_Effect* effect;
    int handle = fd;
    int inner;
    int command_offset;
    RGE_Effect_Command* command;
    int index;

    rge_write(fd, num, 4);
    index = 0;
    if (*num > 0) {
        fd = 0;
        do {
            effect = effects;
            rge_write(handle, effect->name, 0x1F);
            count_ptr = effect->name + fd + 0x22;
            rge_write(handle, count_ptr, 2);
            inner = 0;
            if (*(short*)count_ptr > 0) {
                command_offset = 0;
                do {
                    command = (RGE_Effect_Command*)
                        ((char*)*(RGE_Effect_Command**)(count_ptr + 4) + command_offset);
                    rge_write(handle, &command->command, 1);
                    rge_write(handle, &command->change_num1, 2);
                    rge_write(handle, &command->change_num2, 2);
                    rge_write(handle, &command->change_num3, 2);
                    rge_write(handle, &command->change_amount, 4);
                    inner++;
                    command_offset += 0x0C;
                } while (inner < *(short*)count_ptr);
            }
            index++;
            fd += 0x2C;
        } while (index < effect_num);
    }
}
