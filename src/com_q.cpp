#include "../include/com_q.h"
#include "../include/game_globals.h"
#include "../include/debuglog.h"
#include <string.h>


RGE_Communications_Queue::RGE_Communications_Queue(int MaxSize) {
    if (MaxSize < 0x14) {
        MaxSize = 0x14;
    }
    this->QueueDepth = 0;
    this->HighQueueDepth = 0;
    this->LastCurrentTurn = 0;
    this->Queue = 0;
    this->MaxQSize = MaxSize;
    this->Sequence = 1;
    this->AllocateQueue(MaxSize);
}

RGE_Communications_Queue::~RGE_Communications_Queue() {
    MsgQueue* queue = this->Queue;

    if (queue != 0) {
        delete[] queue;
    }
}

int RGE_Communications_Queue::AllocateQueue(unsigned int NewQSize) {
    int result;
    if (NewQSize < this->MaxQSize) {
        result = 0;
    } else {
        unsigned int count = NewQSize + 1;
        MsgQueue* newQueue = new MsgQueue[count];
        if (newQueue == 0) {
            result = 0;
        } else {
            if (this->Queue != 0) {
                for (unsigned int i = 0; i <= this->MaxQSize; ++i) {
                    if (this->Queue[i].Size != 0) {
                        newQueue[i].Code = 0;
                        newQueue[i].ExecTurn = 0;
                        newQueue[i].SeqNo = 0;
                        newQueue[i].From = 0;
                        newQueue[i].Size = 0;
                        newQueue[i].ControlCommand = 0;

                        newQueue[i].Code = this->Queue[i].Code;
                        newQueue[i].ExecTurn = this->Queue[i].ExecTurn;
                        newQueue[i].SeqNo = this->Queue[i].SeqNo;

                        unsigned int size = this->Queue[i].Size;
                        char* source = this->Queue[i].msgptr;
                        char* data = new char[size + 1];
                        newQueue[i].msgptr = data;
                        if (data != 0) {
                            memcpy(data, source, size);
                        }

                        newQueue[i].From = this->Queue[i].From;
                        newQueue[i].Size = this->Queue[i].Size;
                        newQueue[i].ControlCommand = this->Queue[i].ControlCommand;
                    }
                }

                delete[] this->Queue;
            }

            this->Queue = newQueue;
            this->MaxQSize = NewQSize;
            result = 1;
        }
    }

    return result;
}

unsigned char RGE_Communications_Queue::ExpectedNextSequence(unsigned long TurnID, unsigned int PlayerNo) {
    static unsigned char Count;
    unsigned char seq;
    unsigned int i;

    seq = 1;
    i = 0;
    Count = seq;
    do {
        if (this->Queue[i].ExecTurn == TurnID && this->Queue[i].From == PlayerNo && this->Queue[i].Size != 0) {
            seq++;
            Count = seq;
        }
        i++;
    } while (i <= this->HighQueueDepth);

    {
        unsigned int c = (unsigned int)this;
        c |= 0xff;
        if ((unsigned char)c >= seq) {
            return Count;
        }
        return 0;
    }
}

unsigned int RGE_Communications_Queue::QueuedForTurn(unsigned long TurnID) {
    unsigned int count = 0;
    unsigned int* execTurn = &this->Queue->ExecTurn;
    int remaining = this->HighQueueDepth + 1;

    do {
        if (*execTurn == TurnID) {
            ++count;
        }
        execTurn += sizeof(MsgQueue) / sizeof(*execTurn);
        --remaining;
    } while (remaining != 0);

    return count;
}

void RGE_Communications_Queue::FlushAll() {
    this->FlushTurnRange(0, 0);
}

unsigned int RGE_Communications_Queue::FlushTurnRange(
    unsigned long LowRange, unsigned long HiRange) {
    unsigned int Count = 0;
    unsigned int i = 0;

    do {
        unsigned int execTurn = Queue[i].ExecTurn;
        MsgQueue* entry = &Queue[i];
        if (((execTurn >= LowRange) && (execTurn <= HiRange)) || ((LowRange == 0) && (HiRange == 0))) {
            Count++;
            if (entry->Size > 0) {
                entry->Code = 0;
                entry->ExecTurn = 0;
                entry->SeqNo = 0;
                entry->From = 0;
                entry->Size = 0;
                entry->ControlCommand = 0;
                if (entry->msgptr != 0) {
                    operator delete(entry->msgptr);
                }
                entry->msgptr = 0;
            }
        }
        i++;
    } while (i <= HighQueueDepth);

    return Count;
}

void RGE_Communications_Queue::FlushForPlayer(unsigned int p) {
    L->Log("Flushing queue for player %d", p);

    unsigned int i = 0;
    do {
        unsigned int from = Queue[i].From;
        MsgQueue* entry = &Queue[i];
        if (from == p && entry->Size > 0) {
            L->Log("Remove Q #%d Seq=%d ToExecute %ld From P#%d Size=%d CtrlCmd=%d",
                   i, entry->SeqNo, entry->ExecTurn, from, entry->Size, entry->ControlCommand, entry->Code);

            entry = &Queue[i];
            void* data = entry->msgptr;
            entry->Code = 0;
            entry->ExecTurn = 0;
            entry->SeqNo = 0;
            entry->From = 0;
            entry->Size = 0;
            entry->ControlCommand = 0;
            if (data != 0) {
                operator delete(data);
            }
            entry->msgptr = 0;
        }
        i++;
    } while (i <= HighQueueDepth);
}

unsigned int RGE_Communications_Queue::FlushForTurn(unsigned long TurnID) {
    return this->FlushTurnRange(TurnID, TurnID);
}

unsigned int RGE_Communications_Queue::FlushThruTurn(unsigned long TurnID) {
    return this->FlushTurnRange(0, TurnID);
}

int RGE_Communications_Queue::AddItem(
    unsigned long ExecuteOnTurn, void* command, unsigned long nBytes,
    unsigned int PFrom, unsigned char InSequence, int ControlCommand) {
    unsigned int i = 0;

    while (this->Queue[i].Size != 0) {
        if (i >= this->MaxQSize) {
            break;
        }
        i = i + 1;
    }

    if (i >= this->MaxQSize) {
        if (!this->AllocateQueue(this->MaxQSize + 0x14)) {
            return 0;
        }
        i = i + 1;
    }

    unsigned int high_depth = this->HighQueueDepth;
    if (i > this->HighQueueDepth) {
        high_depth = i;
    }

    MsgQueue* slot = this->Queue + i;
    this->HighQueueDepth = high_depth;

    char* message = static_cast<char*>(operator new(nBytes + 1));
    slot->msgptr = message;

    if (message != 0) {
        memcpy(message, command, nBytes);
    }

    this->Queue[i].Size = nBytes;
    this->Queue[i].SeqNo = InSequence;
    this->Queue[i].ExecTurn = ExecuteOnTurn;
    this->Queue[i].From = PFrom;
    this->Queue[i].Code = (unsigned int)InSequence + PFrom * 1000;
    this->Queue[i].ControlCommand = ControlCommand;
    this->QueueDepth = i;

    return 1;
}

unsigned int RGE_Communications_Queue::GetQueueDepth() {
    return this->QueueDepth;
}

unsigned int RGE_Communications_Queue::GetHighQueueDepth() {
    return this->HighQueueDepth;
}

void* RGE_Communications_Queue::GetSpecificItem(
    unsigned int FromPlayer, unsigned long ExecuteOnTurn, unsigned char Seq,
    unsigned int* Size) {
    static void* retptr;
    unsigned int targetCode = FromPlayer * 1000 + Seq;
    unsigned int idx = 0;
    MsgQueue* entry = this->Queue;

    while (entry->Code != targetCode || entry->ExecTurn != ExecuteOnTurn) {
        idx++;
        entry++;
        if (idx > this->HighQueueDepth) {
            return 0;
        }
    }

    *Size = entry->Size;
    retptr = this->Queue[idx].msgptr;
    this->Queue[idx].msgptr = 0;

    {
        MsgQueue* p = &this->Queue[idx];
        p->Code = 0;
        p->ExecTurn = 0;
        p->SeqNo = 0;
        p->From = 0;
        p->Size = 0;
        p->ControlCommand = 0;
    }

    return retptr;
}

void* RGE_Communications_Queue::GetNextItemSingle() {
    static void* retptr;
    MsgQueue* q = this->Queue;
    for (unsigned int i = 0; i <= this->HighQueueDepth; i++) {
        if (q[i].Size > 0) {
            retptr = q[i].msgptr;
            MsgQueue* entry = this->Queue + i;
            entry->Code = 0;
            entry->ExecTurn = 0;
            entry->SeqNo = 0;
            entry->From = 0;
            entry->Size = 0;
            entry->ControlCommand = 0;
            this->Queue[i].msgptr = 0;
            return retptr;
        }
    }
    return 0;
}

void* RGE_Communications_Queue::GetNextItemOrdered(unsigned long ThisTurn) {
    static void* retptr;
    unsigned int bestControlCommand = 0xFFFFFFFF;
    unsigned int i = 0;
    int SendMsg = -1;

    do {
        if (Queue[i].Code != 0 && Queue[i].Size != 0) {
            if (Queue[i].ExecTurn < ThisTurn) {
                TestShowQueue();
            }

            if (Queue[i].Code < bestControlCommand && Queue[i].ExecTurn == ThisTurn) {
                bestControlCommand = Queue[i].Code;
                SendMsg = i;
            }
        }

        i++;
    } while (i <= HighQueueDepth);

    if (SendMsg == -1) {
        return 0;
    }

    retptr = Queue[SendMsg].msgptr;
    Queue[SendMsg].msgptr = 0;

    MsgQueue* mq = Queue + SendMsg;
    mq->Code = 0;
    mq->ExecTurn = 0;
    mq->SeqNo = 0;
    mq->From = 0;
    mq->Size = 0;
    mq->ControlCommand = 0;

    return retptr;
}

unsigned char RGE_Communications_Queue::GetNextSequence(unsigned long ThisTurn) {
    if (ThisTurn != this->LastCurrentTurn) {
        this->Sequence = 1;
        this->LastCurrentTurn = ThisTurn;
        return 1;
    }
    ++this->Sequence;
    if (this->Sequence < 0xff) {
        return this->Sequence;
    }
    return 0;
}

void RGE_Communications_Queue::TestShowQueue() {
}
