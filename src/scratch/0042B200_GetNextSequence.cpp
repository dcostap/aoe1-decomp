// 0042B200 TCommunications_Handler::GetNextSequence (Com_hand.cpp:4042-4084, 108B)
// ~64% matching. VC5-version codegen differences:
//
// 1. NEW-VALUE PATH (2-byte shift): original uses `mov byte [addr], 1` (c605, 7B)
//    for `byte_62CF2C = 1` then `mov al, 1` (2B) for return. Our VC5 instead does
//    `mov al, 1; mov [addr], al` (2+5=7B), combining the store source and return
//    value register. Same total bytes but shifted instruction order, changing the
//    je offset at offset 0Dh (11 vs 0F) and all subsequent addresses.
//
// 2. INCREMENT PATH SPILL (4 bytes): our VC5 always allocates a stack slot for
//    local `seq` and spills `mov [esp+4], al` after `cmp`, before the global store.
//    The 1998 build avoids the spill entirely (no stack frame for this trivial function).
//    The spill shifts the log and clamp code.
//
// 3. LOG CALL REGISTERS: original loads byte value into eax, logptr into ecx.
//    Our VC5 loads logptr into eax (overwriting byte value in al), then reloads
//    byte value from stack spill into ecx. Different register choices but same
//    push order and stack layout.
//
// 4. CLAMP PATH JUMP OFFSETS: shifted by 8-10 bytes due to above differences.
//    Clamp logic, store pattern (`mov byte [addr], 100`), and return are correct.
//
// All control flow, memory effects, field offsets, and global addresses match
// the original. The differences are pure VC5-version scheduling/register allocation.

extern unsigned char byte_62CF2C;
extern unsigned long dword_62CF30;

class TDebuggingLog;
extern void __cdecl TDebuggingLog_Log(unsigned char value, const char* msg, TDebuggingLog* log);

class TCommunications_Handler {
public:
    char gap_00[0x1558];
    int pause_state; // +0x1558

    unsigned char GetNextSequence(unsigned long value);
};

unsigned char TCommunications_Handler::GetNextSequence(unsigned long value) {
    if (value != dword_62CF30) {
        dword_62CF30 = value;
        byte_62CF2C = 1;
        return 1;
    }

    unsigned char seq = byte_62CF2C;
    ++seq;
    byte_62CF2C = seq;
    if (seq >= 0xFF) {
        TDebuggingLog_Log(seq, (const char*)0x582490, *(TDebuggingLog**)0x62C4FC);
        return 0;
    }
    if (this->pause_state == 4 && seq > 100) {
        byte_62CF2C = 100;
        return 100;
    }
    return seq;
}
