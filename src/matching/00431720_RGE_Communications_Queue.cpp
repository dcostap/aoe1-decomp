class MsgQueue;

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

    RGE_Communications_Queue(int param_1);
    int AllocateQueue(int param_1);
};

RGE_Communications_Queue::RGE_Communications_Queue(int param_1) {
    if (param_1 < 0x14) {
        param_1 = 0x14;
    }
    this->QueueDepth = 0;
    this->HighQueueDepth = 0;
    this->LastCurrentTurn = 0;
    this->Queue = 0;
    this->MaxQSize = param_1;
    this->Sequence = 1;
    this->AllocateQueue(param_1);
}
