// 0042B200 TCommunications_Handler::GetNextSequence (Com_hand.cpp:4042-4084, 108B)
// Default flags
//
// === ACCEPTED_DRIFT ===
// Positional drift is a stable 2-byte schedule swap
// in the new-turn path: original does `mov byte [g],1; mov al,1; ret 4`
// (immediate store first, then return-value load), rebuilt does
// `mov al,1; mov [g],al; ret 4` (return-value load first, then store through al).
// This shifts all subsequent labels by 2 bytes, padded with 2 NOPs at the end.
// Same size (108/108), behavior-identical, localized schedule difference.
//
// Attempt log:
// - Attempt 1: return 1 literal — same 59% family
// - Attempt 2: volatile byte store — same 59%
// - Attempt 3: absolute-address macro — 63% (slightly worse)
// - Attempt 4: assignment-expression return — same 59%
// - Attempt 5: removed overlapping dword extern — same 59%
// - Attempt 6: comma-operator store+return — same 59%
// - Attempt 7: separate result local — same 59%
// - Attempt 8: local retval = 1 — same 59%
// - No source variation across 8 attempts changed VC5's preference for
//   `mov al,1; mov [g],al` over `mov byte [g],1; mov al,1`. This is a
//   stable VC5 schedule/register allocation choice at /O2.

extern unsigned long dword_62CF30;
extern unsigned char byte_62CF2C;

class TDebuggingLog;
extern void __cdecl TDebuggingLog_Log(TDebuggingLog* log, const char* msg, unsigned int value);

#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_00[0x1558];
    int pause_state;

    unsigned char GetNextSequence(unsigned long value);
};
#endif // COM_HAND_TU_CONTEXT


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
        TDebuggingLog_Log(*(TDebuggingLog**)0x62C4FC, (const char*)0x582490,
            *(unsigned int*)&byte_62CF2C & 0xFF);
        return 0;
    }

    if (this->pause_state == 4 && seq > 100) {
        byte_62CF2C = 100;
        return 100;
    }

    return seq;
}
