#ifndef COM_Q_CONTEXT
// BINARY NOTE: The PDB owner is protected, and the queue record starts with
// Code before ExecTurn at offset 4.
class MsgQueue {
public:
    unsigned int Code;
    unsigned long ExecTurn;
    char gap_08[0x14];
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

protected:
    unsigned int QueuedForTurn(unsigned long turn);
};
#endif

unsigned int RGE_Communications_Queue::QueuedForTurn(unsigned long turn) {
    unsigned int count = 0;
    // BINARY NOTE: The shipped loop walks ExecTurn pointers by seven words.
    unsigned int* execTurn = &this->Queue->ExecTurn;
    int i = this->HighQueueDepth + 1;

    do {
        if (*execTurn == turn) {
            ++count;
        }
        execTurn += 7;
        --i;
    } while (i != 0);

    return count;
}
