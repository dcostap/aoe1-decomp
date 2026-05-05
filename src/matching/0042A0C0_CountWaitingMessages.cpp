// VA: 0042A0C0 | TCommunications_Handler::CountWaitingMessages() | Com_hand.cpp:3187-3214 | 111 bytes
// No custom flags needed.
//
// Scans Resend entries (0x38 bytes each, up to 0x6D98 offset), counting those with
// non-null message field. For each non-null, calls debug log with entry fields.

class RESENDER;

class TCommunications_Handler {
public:
    char gap_00[0x1520];
    RESENDER* Resend;              // +0x1520

    int CountWaitingMessages();
};

class TDebuggingLog;

extern TDebuggingLog* g_rge_debug_log;  // 0x62C4FC
extern void __cdecl debug_log(TDebuggingLog* log, const char* fmt, ...);  // 0x436610

// A Resend entry: 0x38 bytes
// +0x00: ???
// +0x04: void* msg (non-null => active)
// +0x08: char* byte_src (dereferenced for a byte)
// +0x0C: int field
// +0x14..+0x30: more int fields

int TCommunications_Handler::CountWaitingMessages() {
    int count = 0;
    int slot = 0;
    unsigned int offset = 0;

    do {
        char* entry = (char*)this->Resend + offset;
        void* msg = *(void**)(entry + 4);
        if (msg != 0) {
            debug_log(g_rge_debug_log,
                "GTD: Ser #%d Slot=%d Cmd='%c' Len=%d not a",  // 0x581E74
                msg,
                slot,
                *(signed char*)(*(char**)(entry + 8)),
                *(int*)(entry + 0x0C),
                *(int*)(entry + 0x14),
                *(int*)(entry + 0x18),
                *(int*)(entry + 0x1C),
                *(int*)(entry + 0x20),
                *(int*)(entry + 0x24),
                *(int*)(entry + 0x28),
                *(int*)(entry + 0x2C),
                *(int*)(entry + 0x30));
            count++;
        }
        offset += 0x38;
        slot++;
    } while (offset <= 0x6D98);

    return count;
}
