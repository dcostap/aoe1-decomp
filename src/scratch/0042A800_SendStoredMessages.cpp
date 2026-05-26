// VA: 0042A800 TCommunications_Handler::SendStoredMessages
// PDB source: Com_hand.cpp
// Attempt log:
// - reconstructed high-level flow from packet: send gating, timing throttle, queued-message scan, per-player send/log/update loop.
// - default /O2 broad reconstruction compiles but .text is 1216 vs target 1285, too short for extraction; missing exact source/helper surfaces around DirectPlay send/log and retry/failure handling.
// - tried /Od diagnostically: extraction compares but 90.66% positional diff from offset 0 due EBP frame, confirming original is optimized /O2.
// - restored default flags; give-up. No accepted_drift because current source has broad behavioral uncertainty and no localized diff.

extern unsigned long debug_timeGetTime(char* file, int line);
extern void logmsg(void* out, char* fmt, ...);
extern void sprintf(char* dst, char* fmt, ...);

#define COM_FILE ((char*)0x580BF4)
#define sent_flag (*(unsigned char*)0x62C5E4)
#define last_send_time (*(unsigned long*)0x62C5A8)
#define queued_bytes (*(unsigned long*)0x62CF28)
#define log_stream (*(void**)0x62C4FC)
#define dword_62CF04 (*(void**)0x62CF04)
#define dword_62CF08 (*(unsigned long*)0x62CF08)
#define dword_62CF0C (*(unsigned long*)0x62CF0C)
#define lobby_obj (*(LobbyObj**)0x62C5EC)

class LobbyObj { public: virtual void v0(); char gap[0x68-4]; virtual int send(void*, void*, int, void*, int, int); };
struct StoredMsg { unsigned long time; int player; int bytes; int data; int delay; char pad[0x38-0x14]; };
class TCommunications_Handler_42A800 {
public:
    char gap0[0x1c]; int flag1c; char gap20[0xfc5-0x20]; char tmp[0x100]; char gap10c5[0x10c8-0x10c5]; int state10c8; char gap10cc[0x10e0-0x10cc]; int selfPlayer; char gap10e4[0x12a8-0x10e4]; int mode12a8; char gap12ac[0x12c0-0x12ac]; int sentBytes; char gap12c4[0x12d8-0x12c4]; unsigned short maxPlayers; char gap12da[0x132c-0x12da]; int sentCount; char gap1330[0x14d4-0x1330]; void* dpDesc; char gap14d8[0x14e0-0x14d8]; void* logObj; char gap14e4[0x1514-0x14e4]; unsigned char canSend; char gap1515[0x1520-0x1515]; StoredMsg* msgs; char gap1524[0x1568-0x1524]; int perPlayer[256];
    void resetStored(); int canSendTo(int player); int nameFor(int player); int SendStoredMessages(); int Send(int a, int b, int c, char* d, int e);
};

int TCommunications_Handler_42A800::SendStoredMessages()
{
    unsigned long now;
    unsigned long maxElapsed = 0;
    unsigned int oldestSlot = 0;
    unsigned long items = 0;
    int any = 0;
    int maxFree = 0;
    int player;

    if (!this->canSend) { logmsg(log_stream, (char*)0x582264); return 0; }
    if ((sent_flag & 1) == 0) { sent_flag |= 1; last_send_time = debug_timeGetTime(COM_FILE, 0xe00); }
    now = debug_timeGetTime(COM_FILE, 0xe02);
    if ((float)((double)queued_bytes / (double)(now - last_send_time)) <= *(float*)0x56F210) return 0;
    last_send_time = now;
    queued_bytes = 0;
    this->resetStored();

    StoredMsg* m = this->msgs;
    for (int slot = 0; slot <= 0x1f4; ++slot, ++m) {
        if (m->delay != 0) {
            ++items;
            unsigned long elapsed = now - m->time;
            if (elapsed > maxElapsed) { maxElapsed = elapsed; oldestSlot = slot; }
            if (this->maxPlayers >= 1) {
                for (int p = 1; p <= this->maxPlayers; ++p) {
                    int free = 0xf0 - m->player;
                    if (free > maxFree) maxFree = free;
                }
            }
        }
    }
    if (items == 0) return 0;
    if (this->state10c8 <= 6) { if (maxElapsed < 2000) return 0; }
    else if (this->mode12a8) { if (maxElapsed < 250) return 0; }
    else {
        unsigned long lim = dword_62CF0C + (unsigned long)this->dpDesc;
        if (lim < dword_62CF08 + 500) lim = dword_62CF08 + 500;
        if (maxElapsed < lim) return 0;
    }

    int byteOffset = oldestSlot * 0x38;
    this->msgs[oldestSlot].time = debug_timeGetTime(COM_FILE, 0xe55);
    for (player = 1; player <= this->maxPlayers; ++player) {
        StoredMsg* sm = (StoredMsg*)((char*)this->msgs + byteOffset);
        if (sm->delay > 0 && this->canSendTo(player) && this->perPlayer[player-1] != 0 && player != this->selfPlayer) {
            if (sm->delay) --sm->delay;
            logmsg(log_stream, (char*)0x582210, player, sm->player, oldestSlot, sm->data, debug_timeGetTime(COM_FILE, 0xe69), sm->delay);
            if (dword_62CF04 == 0) { logmsg(log_stream, (char*)0x5810B0); return 0; }
            unsigned long t = debug_timeGetTime(COM_FILE, 0xe76);
            logmsg(log_stream, (char*)0x5821F8, player, oldestSlot, sm->data);
            int first = this->perPlayer[0];
            int hr = lobby_obj->send(lobby_obj, dword_62CF04, first, 0, sm->bytes, sm->data);
            if (debug_timeGetTime(COM_FILE, 0xe86) - t > 50) logmsg(log_stream, (char*)0x5821D0, debug_timeGetTime(COM_FILE, 0xe86) - t);
            if (hr == 0) { this->sentCount++; this->sentBytes += sm->data; queued_bytes += sm->data; logmsg(log_stream, (char*)0x5821A8, sm->player, player, sm->data); }
            else logmsg(this->logObj, (char*)0x582198, hr);
            if (sm->delay == 0 && this->canSendTo(player) && this->perPlayer[player-1] != 0 && player != this->selfPlayer) {
                player = this->nameFor(player);
                sprintf(this->tmp, (char*)0x582178, player);
                logmsg(log_stream, this->tmp);
                if (this->flag1c) { logmsg(log_stream, (char*)0x582158, player); this->msgs[oldestSlot].pad[0] = 1; this->Send(player,0,0,0,0); }
                else { logmsg(log_stream, (char*)0x582130, this->perPlayer[player-1]); char q[8]; q[0]='?'; logmsg(log_stream, (char*)0x582120, 8); this->Send(0,0,8,q,0); }
            }
        }
    }
    return this->sentCount;
}
