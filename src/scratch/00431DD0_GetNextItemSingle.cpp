// attempt 1: decompiler-shaped scan using a size-field pointer and a separate queue pointer
// attempt 2: tried a few direct-member rewrites; VC5 drifted into a much different register/layout basin
// leaving this paused in scratch because the remaining gap is a stable codegen-family issue, not a logic bug

class MsgQueue {
public:
    unsigned long Code;
    unsigned long ExecTurn;
    unsigned char SeqNo;
    char* msgptr;
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

void* RGE_Communications_Queue::GetNextItemSingle() {
    unsigned int index = 0;
    MsgQueue* entry = this->Queue;
    unsigned int* size_ptr = &this->Queue->Size;

    do {
        if (*size_ptr != 0) {
            DAT_0062cf34 = entry->msgptr;
            entry->Code = 0;
            entry->ExecTurn = 0;
            entry->SeqNo = 0;
            entry->From = 0;
            entry->Size = 0;
            entry->ControlCommand = 0;
            return DAT_0062cf34;
        }

        index = index + 1;
        entry = (MsgQueue*)((char*)entry + 0x1C);
        size_ptr = size_ptr + 7;
    } while (index <= this->HighQueueDepth);

    return 0;
}
