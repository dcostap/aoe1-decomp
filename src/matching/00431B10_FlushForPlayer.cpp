// 00431B10 FlushForPlayer
// 185 bytes, __thiscall, RGE_Communications_Queue method
// attempt log:
// - baseline typed MsgQueue for-loop was 176 bytes: kept param in EBP and entry pointer in ESI, too short.
// - current mirrors decompiler topology with stack i and byte offset; local this alias intended to keep this in EBP.

class TDebuggingLog {
public:
    void Log(const char* format, ...);
};

#define L (*(TDebuggingLog**)0x62C4FC)
void __cdecl operator delete(void* ptr);

struct MsgQueue {
    unsigned int ControlCommand; // +00
    unsigned int ExecTurn;       // +04
    unsigned char Code;          // +08
    char gap_09[3];              // +09
    void* Data;                  // +0C
    unsigned int From;           // +10
    unsigned int field_14;       // +14
    unsigned int field_18;       // +18
};

class RGE_Communications_Queue {
public:
    unsigned int QueueDepth;
    unsigned int HighQueueDepth;
    unsigned int MaxQSize;
    char TBuff[255];
    unsigned char _pad_0[1];
    unsigned long LastCurrentTurn;
    unsigned char Sequence;
    unsigned char _pad_1[3];
    MsgQueue* Queue;

    void FlushForPlayer(unsigned int param_1);
};

void RGE_Communications_Queue::FlushForPlayer(unsigned int param_1) {
    RGE_Communications_Queue* th = this;
    L->Log("Flushing queue for player %d", param_1);

    unsigned int i = 0;
    int off = 0;
    do {
        unsigned int from = *(unsigned int*)((char*)th->Queue + off + 0x10);
        MsgQueue* q = (MsgQueue*)((char*)th->Queue + off);
        if (from == param_1 && q->field_14 > 0) {
            L->Log("Remove Q #%d Seq=%d ToExecute %ld From P#%d Size=%d CtrlCmd=%d",
                i, q->Code, q->ExecTurn, from, q->field_14, q->field_18, q->ControlCommand);

            q = (MsgQueue*)((char*)th->Queue + off);
            void* data = q->Data;
            q->ControlCommand = 0;
            q->ExecTurn = 0;
            q->Code = 0;
            q->From = 0;
            q->field_14 = 0;
            q->field_18 = 0;
            if (data != 0) {
                operator delete(data);
            }
            q->Data = 0;
        }
        i++;
        off += 0x1c;
    } while (i <= th->HighQueueDepth);
}
