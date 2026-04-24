// attempt 1: for-loop too compact (80 vs 89 bytes)
// attempt 2: while-loop+base ptr matches 89 bytes but prologue wrong (VC5 pushes ebx first vs original loads param1 first)
// attempt 3: direct this->last_order access still wrong prologue
// attempt 4: local 'unsigned char n = param1->unit_num' makes function too small (80 vs 89)
// Left in scratch after 4 attempts
// Remaining: prologue register allocation differs (original loads param1 into eax before any pushes,
// overwrites ecx with last_order, then pushes ebx/esi/edi with xor edx between).
// Loop uses delta-based addressing (sub edi,esi; mov esi,[edi+eax]) that VC5 doesn't generate from natural source.
// Behavioral logic fully correct.

class RGE_Command_Stop {
public:
    char pad_00[1];
    unsigned char unit_num;
    int items[1];
};

class RGE_Command {
public:
    char gap_00[8];
    RGE_Command_Stop* last_order;

    unsigned char duplicate_check_command_stop(RGE_Command_Stop* param1);
};

unsigned char RGE_Command::duplicate_check_command_stop(RGE_Command_Stop* param1) {
    RGE_Command_Stop* last = this->last_order;

    if (param1->unit_num != last->unit_num) {
        return 0;
    }
    int i = 0;
    int* base = last->items;
    if (param1->unit_num > 0) {
        while (i < param1->unit_num) {
            if (base[i] != param1->items[i]) {
                return 0;
            }
            i++;
        }
    }
    return 1;
}
