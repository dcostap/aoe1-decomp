// 004351B0 RGE_Command::duplicate_check_command_stop
// HollowSnowdrop pass: tried low-level pointer-delta scan and natural forms. Best prior while-loop remains exact size 89/89 but wrong prologue/loop-addressing. Low-level version improved initial param load but still pushes before last_order load and hoists pointer increments differently; rolled back to best natural behavior source.
// Remaining: original loads param1 into EAX and last_order into ECX before pushes, then uses EDI/ESI delta addressing (`sub edi,esi; mov esi,[edi+eax]`) in loop. VC5 natural forms prefer loading last_order after pushes or separate advancing pointers.

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
