// 0042B200 TCommunications_Handler::GetNextSequence (Com_hand.cpp:4042-4084, 108B)
//
// Attempt log:
// - Original scratch used `unsigned char byte_62CF2C` and fake log signature
//   `(value,msg,log)`. It matched control flow but spilled the incremented byte to
//   `[esp+4]`, used wrong log-call register order, and kept the new-turn path as
//   `mov al,1; mov [global],al` instead of original immediate byte store.
// - Try 1: corrected log declaration to `(log,msg,value)`. This fixed the push order
//   and log registers but still spilled the byte local.
// - Try 2: reused the incoming parameter slot, used unsigned/int seq locals, no seq
//   local, volatile byte reads/stores: all kept the stack byte spill family.
// - Try 3: modelled the sequence global as a dword at 0x62CF2C and accessed its low
//   byte explicitly. This removed the stack spill and recovered the original overflow
//   logging shape: byte load/inc/cmp/store, dword reload, log pointer in ECX, AND EAX,
//   push value/msg/log.
// - Try 4: tried to force the new-turn path's `mov byte [global],1; mov al,1` with
//   value-value expressions, volatile stores, volatile/global return reads, and return
//   from the global. VC5 either kept `mov al,1; mov [global],al` or added a reload.
// - Try 5: flag probes /Ob0, /Og, /Ot no effect; /Os and /O1 were 103-byte wrong-size
//   bodies. No per-function flag kept.
// Left in scratch: best source below is behavior-equivalent and same-size. Remaining
// drift is localized to the new-turn store/return scheduling (`mov al,1; mov [g],al`
// vs original `mov byte [g],1; mov al,1`), shifting later blocks/tail 2 bytes earlier
// with trailing NOP padding. Accepted_drift candidate if reviewed; no inline asm/hacks.

extern unsigned int dword_62CF2C;
extern unsigned long dword_62CF30;

class TDebuggingLog;
extern void __cdecl TDebuggingLog_Log(TDebuggingLog* log, const char* msg, unsigned int value);

class TCommunications_Handler {
public:
    char gap_00[0x1558];
    int pause_state; // +0x1558

    unsigned char GetNextSequence(unsigned long value);
};

unsigned char TCommunications_Handler::GetNextSequence(unsigned long value) {
    if (value != dword_62CF30) {
        dword_62CF30 = value;
        *(unsigned char*)&dword_62CF2C = 1;
        return 1;
    }

    unsigned char seq = *(unsigned char*)&dword_62CF2C;
    ++seq;
    *(unsigned char*)&dword_62CF2C = seq;
    if (seq >= 0xFF) {
        TDebuggingLog_Log(*(TDebuggingLog**)0x62C4FC, (const char*)0x582490, dword_62CF2C & 0xFF);
        return 0;
    }
    if (this->pause_state == 4 && seq > 100) {
        *(unsigned char*)&dword_62CF2C = 100;
        return 100;
    }
    return seq;
}
