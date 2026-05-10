// 004351B0 RGE_Command::duplicate_check_command_stop
// HollowSnowdrop pass: tried low-level pointer-delta scan and natural forms. Best prior while-loop remains exact size 89/89 but wrong prologue/loop-addressing. Low-level version improved initial param load but still pushes before last_order load and hoists pointer increments differently; rolled back to best natural behavior source.
// Remaining: original loads param1 into EAX and last_order into ECX before pushes, then uses EDI/ESI delta addressing (`sub edi,esi; mov esi,[edi+eax]`) in loop. VC5 natural forms prefer loading last_order after pushes or separate advancing pointers.
// LemonLily pass: tried packed RGE_Command_Stop (+2 unaligned int items), raw +1/+2 byte-offset forms, param-first and last-first locals, direct this->last_order uses, pointer-delta loops, nested ifs, for/while/do loops, volatile param read, and temporary flag probes (/O2 no /Oy, /Ot, /Og, /Ox, /O1, /Oa, /Ow). No exact.
// Best kept source uses raw +2 item offsets and pointer-delta scan. It fixes the old struct-alignment issue and gets exact size with a closer loop, but VC5 still pushes/schedules before loading last_order and inserts a duplicated loop guard in some forms. /O1 emits too-short text; other flags do not move the basin.

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
    int n = *(unsigned char*)((char*)param1 + 1);
    char* pitems = (char*)param1 + 2;
    if (n != *(unsigned char*)((char*)this->last_order + 1)) {
        return 0;
    }
    int i = 0;
    char* litems = (char*)this->last_order + 2;
    if (n > 0) {
        pitems = pitems - (int)litems;
        while (i < n) {
            if (*(int*)(pitems + (int)litems) != *(int*)litems) {
                return 0;
            }
            i++;
            litems += 4;
        }
    }
    return 1;
}
