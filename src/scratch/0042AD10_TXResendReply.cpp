// VA: 0042AD10 TCommunications_Handler::TXResendReply
// Com_hand.cpp
// Attempt log:
// try 1: natural reconstruction from packet and sibling TXResendRequest/TXAcknowledgeMessage: GTD guard, per-player throttle, scan TX table, send resend reply, stats/logging.
// try 2: modeled key fields from packet/siblings: TXPacketLength +0x12C0, resend_serial +0x1434, resend_time +0x145C, Err +0x14E0, guaranteed +0x1514, tx_data +0x1520, state +0x1558, dcoID +0x1564.
// try 3: modeled initial guards exactly: guaranteed byte, dcoID[player] null log, global dco id null return.
// try 4: modeled resend throttle using debug_timeGetTime(file,0xEE7), serial compare, time delta <500 log/return.
// try 5: modeled per-player serial/time update and scan offset `player*4+0x10` with stride 0x38 to mirror original loop.
// try 6: modeled matched slot path: log via stack buffer, allocate slot length, decrement slot count, second dco guard, debug timing, send through sender vtable +0x68, slow-send log.
// try 7: modeled good/bad counters and TXPacketLength update vs Err->ShowReturn path.
// try 8: modeled post-loop no-good/no-bad state==3 fallback with 8-byte 'Y' message, TXAcknowledgeMessage, ClearTXForPlayer, and summary log otherwise.
// try 9: fixed class layout compile issue from zero-size gap; current source compiles but .text is 816B vs original 901B.
// try 10: compared packet around send: original uses table slot data pointer/length directly for vtable send and has very specific stack-buffer/log/allocation side effects; current behavioral reconstruction is too compact and likely still has wrong slot struct semantics.
// left in scratch: broad behavior/call surface is reconstructed, but code is far too small and not diffable. Main blockers are exact TX slot layout/semantics, stack temp use, and original logging/allocation side-effect ordering. No accepted_drift: broad missing code/size gap.

typedef unsigned int uint;

extern unsigned long debug_timeGetTime(const char* file, int line);
extern void* operator new(unsigned int size);
extern void operator delete(void* ptr);
extern const char s_Com_hand_cpp[];
extern unsigned int DAT_0062cf04;
extern void* DAT_0062c5ec;
extern int DAT_0062c4fc;

class TDebuggingLog { public: static void Log(void* log, const char* fmt, ...); };
class RGE_Comm_Error { public: void ShowReturn(long result, const char* name); };

struct SendVTable { char gap[0x68]; int (__stdcall *send)(void*, unsigned int, unsigned int, int, void*, int); };
struct Sender { SendVTable* vt; };
extern Sender* sender;

class TCommunications_Handler {
public:
    char gap_0000[0x12C0];
    int TXPacketLength;
    char gap_12C4[0x1434-0x12C4];
    unsigned int resend_serial[10];     // +1434
    unsigned int resend_time[10];       // +145C
    char gap_1484[0x14E0-0x1484];
    RGE_Comm_Error* Err;
    unsigned int count_limit;           // +14E4
    char gap_14E8[0x1514-0x14E8];
    unsigned char guaranteed;
    char gap_1515[0x1520-0x1515];
    int* tx_data;                       // +1520
    char gap_1524[0x1558-0x1524];
    int state;                          // +1558
    char gap_155C[0x1564-0x155C];
    unsigned int dcoID[10];             // +1564

    int TXResendReply(uint serial, uint player);
    void TXAcknowledgeMessage(uint serial, uint player);
    void ClearTXForPlayer(uint player);
    void flush();
};

int TCommunications_Handler::TXResendReply(uint serial, uint player) {
    if (!this->guaranteed) return 0;
    if (this->dcoID[player] == 0) {
        TDebuggingLog::Log((void*)DAT_0062c4fc, "Invalid player req.");
        return 0;
    }
    if (DAT_0062cf04 == 0) return 0;

    unsigned long now = debug_timeGetTime(s_Com_hand_cpp, 0xEE7);
    if (serial == this->resend_serial[player]) {
        unsigned long diff = now - this->resend_time[player];
        if (diff < 500) {
            TDebuggingLog::Log((void*)DAT_0062c4fc, "Res reply too soon #%u %u", serial, diff);
            return 0;
        }
    }
    this->resend_serial[player] = serial;
    this->resend_time[player] = now;

    int good = 0;
    int bad = 0;
    int hr = 0;
    int offset = player * 4 + 0x10;
    for (int i = 0; i <= 0x1F6; i++, offset += 0x38) {
        int* slot = (int*)((char*)this->tx_data + offset);
        if (slot[1] == (int)serial) {
            char buf[64];
            TDebuggingLog::Log((void*)buf, "Res reply #%d ser %d", player, serial);
            TDebuggingLog::Log((void*)DAT_0062c4fc, buf);
            char* msg = (char*)operator new(slot[3]);
            --slot[0];
            if (DAT_0062cf04 == 0) {
                TDebuggingLog::Log((void*)DAT_0062c4fc, "+++BAD DCOID=0 NO TX");
                return 0;
            }
            unsigned long start = debug_timeGetTime(s_Com_hand_cpp, 0xF19);
            TDebuggingLog::Log((void*)DAT_0062c4fc, "  >TX RES REPLY #%d %d (%d)", player, serial, slot[3]);
            Sender* s = sender;
            hr = s->vt->send(s, DAT_0062cf04, this->dcoID[player], 0, msg, slot[3]);
            unsigned long elapsed = debug_timeGetTime(s_Com_hand_cpp, 0xF28) - start;
            if (elapsed > 50) TDebuggingLog::Log((void*)DAT_0062c4fc, "  TX RES REPLY took %d", elapsed);
            if (hr == 0) {
                good++;
                this->TXPacketLength += slot[3];
            } else {
                this->Err->ShowReturn(hr, "GTD RESEND REPLY");
                bad++;
            }
            TDebuggingLog::Log((void*)DAT_0062c4fc, "  RES REPLY %d %d %d %d %d %d %d", player, slot[1], slot[3], slot[0], *(char*)slot[2], i, debug_timeGetTime(s_Com_hand_cpp, 0xF42));
            operator delete(msg);
        }
    }
    if (good == 0 && bad == 0) {
        if (this->state == 3) {
            TDebuggingLog::Log((void*)DAT_0062c4fc, "Res reply none #%d %d", player, serial);
            char no[8];
            no[0] = 'Y';
            *(uint*)(no+4) = this->count_limit - 1;
            TDebuggingLog::Log((void*)DAT_0062c4fc, "res none send %d %d", player, serial, 8);
            this->TXAcknowledgeMessage(serial, player);
            TDebuggingLog::Log((void*)DAT_0062c4fc, "clearing tx %d", serial);
            this->ClearTXForPlayer(player);
        }
    } else {
        TDebuggingLog::Log((void*)DAT_0062c4fc, "RES REPLY summary p%d good %d bad %d total %d", player, good, bad, good + bad);
    }
    this->flush();
    return 1;
}
