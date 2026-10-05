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

    RGE_Communications_Queue(int MaxSize);
    ~RGE_Communications_Queue();

  protected:
    int AllocateQueue(unsigned int NewQSize);
    unsigned int QueuedForTurn(unsigned long TurnID);

  public:
    unsigned char ExpectedNextSequence(unsigned long TurnID, unsigned int PlayerNo);
    void FlushAll();
    unsigned int FlushTurnRange(unsigned long LowRange, unsigned long HiRange);
    void FlushForPlayer(unsigned int p);
    unsigned int FlushForTurn(unsigned long TurnID);
    unsigned int FlushThruTurn(unsigned long TurnID);
    int AddItem(
        unsigned long ExecuteOnTurn, void* command, unsigned long nBytes, unsigned int PFrom, unsigned char InSequence,
        int ControlCommand
    );
    unsigned int GetQueueDepth();
    unsigned int GetHighQueueDepth();
    void* GetSpecificItem(unsigned int FromPlayer, unsigned long ExecuteOnTurn, unsigned char Seq, unsigned int* Size);
    void* GetNextItemSingle();
    void* GetNextItemOrdered(unsigned long ThisTurn);
    unsigned char GetNextSequence(unsigned long ThisTurn);
    void TestShowQueue();
};

typedef char com_q_msg_queue_size_check[(sizeof(MsgQueue) == 0x1C) ? 1 : -1];
typedef char com_q_size_check[(sizeof(RGE_Communications_Queue) == 0x118) ? 1 : -1];

#endif
