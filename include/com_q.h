#ifndef AOE1_COM_Q_H
#define AOE1_COM_Q_H


#include <new.h>

class MsgQueue {
public:
    unsigned int Code;
    unsigned int ExecTurn;
    unsigned char SeqNo;
    char* msgptr;
    unsigned int From;
    unsigned int Size;
    int ControlCommand;

    MsgQueue() {
        this->Code = 0;
        this->ExecTurn = 0;
        this->SeqNo = 0;
        this->From = 0;
        this->Size = 0;
        this->ControlCommand = 0;
        this->msgptr = 0;
    }

    ~MsgQueue() {
        this->Code = 0;
        this->ExecTurn = 0;
        this->SeqNo = 0;
        this->From = 0;
        this->Size = 0;
        this->ControlCommand = 0;
        if (this->msgptr != 0) {
            operator delete(this->msgptr);
        }
        this->msgptr = 0;
    }
};

typedef MsgQueue MsgQueueEntry;

class RGE_Communications_Queue {
public:
    unsigned int QueueDepth;
    unsigned int HighQueueDepth;
    unsigned int MaxQSize;
    char TBuff[255];
    unsigned long LastCurrentTurn;
    unsigned char Sequence;
    MsgQueue* Queue;

    RGE_Communications_Queue(int param_1);
    ~RGE_Communications_Queue();

protected:
    int AllocateQueue(unsigned int param_1);
    unsigned int QueuedForTurn(unsigned long turn);

public:
    unsigned char ExpectedNextSequence(unsigned long turn, unsigned int from);
    void FlushAll();
    unsigned int FlushTurnRange(unsigned long first, unsigned long last);
    void FlushForPlayer(unsigned int player);
    unsigned int FlushForTurn(unsigned long turn);
    unsigned int FlushThruTurn(unsigned long turn);
    int AddItem(unsigned long turn, void* data, unsigned long size,
                unsigned int from, unsigned char sequence, int control);
    unsigned int GetQueueDepth();
    unsigned int GetHighQueueDepth();
    void* GetSpecificItem(unsigned int player, unsigned long turn,
                          unsigned char sequence, unsigned int* size);
    void* GetNextItemSingle();
    void* GetNextItemOrdered(unsigned long turn);
    unsigned char GetNextSequence(unsigned long turn);
    void TestShowQueue();
};

typedef char com_q_msg_queue_size_check[
    (sizeof(MsgQueue) == 0x1C) ? 1 : -1];
typedef char com_q_size_check[
    (sizeof(RGE_Communications_Queue) == 0x118) ? 1 : -1];

#endif
