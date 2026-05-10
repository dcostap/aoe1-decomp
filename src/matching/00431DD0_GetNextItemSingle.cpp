// 00431DD0 RGE_Communications_Queue::GetNextItemSingle
//
// Attempt log:
// - Prior passes were stuck in pointer/size-pointer scan shapes: VC5 saved EDI early and kept Queue in EDI, while
//   the original delays `push edi`, keeps Queue in ESI for the scan, and uses EDI only for HighQueueDepth.
// - SpruceGlow try 1: direct decompiler size-pointer do/while reproduced the prior early-EDI basin (edit diff 27).
// - SpruceGlow try 2 MATCH: use the plain array-indexed `for (i <= this->HighQueueDepth)` scan with `q[i].Size > 0`,
//   while keeping tail clearing through a fresh `this->Queue + i` entry. This lets VC5 choose the original delayed-EDI
//   scan and exact clear/reload sequence.
// Result: MATCH locally with `python tools/check_function.py --va 00431DD0`.

class MsgQueue {
public:
    unsigned long Code;
    unsigned long ExecTurn;
    unsigned char SeqNo;
    char pad_09[3];
    void* msgptr;
    unsigned int From;
    unsigned int Size;
    int ControlCommand;
};

class RGE_Communications_Queue {
public:
    unsigned int QueueDepth;
    unsigned int HighQueueDepth;
    unsigned int MaxQSize;
    char TBuff[0xFF];
    unsigned char _pad_0[1];
    unsigned long LastCurrentTurn;
    unsigned char Sequence;
    unsigned char _pad_1[3];
    MsgQueue* Queue;

    void* GetNextItemSingle();
};

extern void* DAT_0062cf34;

void* RGE_Communications_Queue::GetNextItemSingle(){ MsgQueue* q=this->Queue; for(unsigned int i=0;i<=this->HighQueueDepth;i++){ if(q[i].Size>0){ DAT_0062cf34=q[i].msgptr; MsgQueue* e=this->Queue+i; e->Code=0; e->ExecTurn=0; e->SeqNo=0; e->From=0; e->Size=0; e->ControlCommand=0; this->Queue[i].msgptr=0; return DAT_0062cf34; }} return 0;}
