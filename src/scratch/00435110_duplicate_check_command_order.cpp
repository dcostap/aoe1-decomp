// RGE_Command::duplicate_check_command_order
// VA: 00435110
// Command.cpp:1070-1092
// 153 bytes
//
// Attempt log:
// 1-3: Basic C++ version. 144B prologue (no push ecx/push ebp), inline failures.
// 4: goto fail for shared epilogue — same result (goto-skip-init errors resolved).
// 5: Declared all locals at top, goto fail — same 144B.
// 6: Added long* p1_units, p2_units locals — same 144B.
// 7: Inline ftol comparisons without short locals — same 144B.
// 8: Compound && condition — same 144B.
// 9: volatile int dummy — same 144B.
// 10: long* p1/p2 declared early — 153B but prologue still wrong (3 pushes, no ecx/ebp).
// 11: Explicit n1/n2 for count, p1/p2 for arrays — same 153B.
// 12: Manual delta pointer sub — no improvement.
//
// Persistent differences from original:
// 1. Prologue: 3 pushes (ebx,esi,edi) vs 5 pushes (ecx,ebx,ebp,esi,edi)
//    — missing push ecx (4B local slot) and push ebp (ebp register)
// 2. Register allocation: edi=param_1 vs ebx=param_1; count on [esp+10h] vs edi
// 3. ftol temp: bx vs bp (ebp not saved)
// 4. Error handling: inline je+8; xor al,al; pop; ret per check (8B each ×4)
//    vs shared jne+0x65 to single xor al,al; pop; ret at end
// 5. Zero extension: and edx,0xFF (6B) vs xor/mov byte (4B)
// 6. Unit array: add esi,14h modifies last_order ptr vs separate lea+stores
//
// Root cause: VC5 register allocator chooses different strategy.
// Cannot control register assignment (ebx vs edi for param_1, ebp usage)
// from C++ source in this toolchain.
//
// Left in scratch. Not proposing accepted_drift (pervasive reg alloc diff).

class RGE_Command_Order {
public:
    long unknown_00;    // +0x00
    long target_id;     // +0x04
    unsigned char unit_num; // +0x08
    char pad_09[3];     // +0x09 to +0x0B
    float pos_x;        // +0x0C
    float pos_y;        // +0x10
    long units[1];      // +0x14 (variable length)
};

class RGE_Command {
public:
    char gap_00[8];
    RGE_Command_Order* last_order; // +0x08

    unsigned char duplicate_check_command_order(RGE_Command_Order* param_1);
};

unsigned char RGE_Command::duplicate_check_command_order(RGE_Command_Order* param_1)
{
    RGE_Command_Order* last_order = this->last_order;
    unsigned char n = param_1->unit_num;

    if (n != last_order->unit_num)
        return 0;

    if ((short)(int)param_1->pos_x != (short)(int)last_order->pos_x)
        return 0;

    if ((short)(int)param_1->pos_y != (short)(int)last_order->pos_y)
        return 0;

    if (last_order->target_id != param_1->target_id)
        return 0;

    for (int i = 0; i < n; i++) {
        if (param_1->units[i] != last_order->units[i])
            return 0;
    }

    return 1;
}
