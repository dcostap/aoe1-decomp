#include "../include/com_q.h"
#include "../include/debuglog.h"
#include <string.h>

extern void* DAT_0062cf34;
extern void* DAT_0062cf38;
extern void* DAT_0062cf3c;
extern unsigned int DAT_0062cf40;
extern TDebuggingLog* L;

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

RGE_Communications_Queue::~RGE_Communications_Queue() {
    MsgQueue* queue = this->Queue;

    if (queue != 0) {
        delete[] queue;
    }
}

int RGE_Communications_Queue::AllocateQueue(unsigned int param_1) {
    int result;
    if (param_1 < this->MaxQSize) {
        result = 0;
    }
    else {
        unsigned int count = param_1 + 1;
        MsgQueue* newQueue = new MsgQueue[count];
        if (newQueue == 0) {
            result = 0;
        }
        else {
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
            this->MaxQSize = param_1;
            result = 1;
        }
    }

    return result;
}

unsigned char RGE_Communications_Queue::ExpectedNextSequence(
    unsigned long turn, unsigned int from) {
    unsigned char seq;
    unsigned int i;

    seq = 1;
    i = 0;
    *(unsigned char*)&DAT_0062cf40 = seq;
    do {
        if (this->Queue[i].ExecTurn == turn &&
            this->Queue[i].From == from &&
            this->Queue[i].Size != 0) {
            seq++;
            *(unsigned char*)&DAT_0062cf40 = seq;
        }
        i++;
    } while (i <= this->HighQueueDepth);

    {
        unsigned int c = (unsigned int)this;
        c |= 0xff;
        if ((unsigned char)c >= seq) {
            return (unsigned char)DAT_0062cf40;
        }
        return 0;
    }
}

unsigned int RGE_Communications_Queue::QueuedForTurn(unsigned long turn) {
    unsigned int count = 0;
    unsigned int* execTurn = &this->Queue->ExecTurn;
    int remaining = this->HighQueueDepth + 1;

    do {
        if (*execTurn == turn) {
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
    unsigned long param_1, unsigned long param_2) {
    unsigned int i = 0;
    unsigned int index = 0;

    while (index <= HighQueueDepth) {
        MsgQueue* mq = &Queue[index];
        unsigned int execTurn = mq->ExecTurn;
        ++index;

        if (((execTurn < param_1) || (execTurn > param_2)) &&
            !((param_1 == 0) && (param_2 == 0))) {
            continue;
        }

        i++;
        if (mq->Size <= 0) {
            continue;
        }

        mq->Code = 0;
        mq->ExecTurn = 0;
        mq->SeqNo = 0;
        mq->From = 0;
        mq->Size = 0;
        mq->ControlCommand = 0;

        if (mq->msgptr != 0) {
            operator delete(mq->msgptr);
        }
        mq->msgptr = 0;
    }

    return i;
}

void RGE_Communications_Queue::FlushForPlayer(unsigned int param_1) {
    RGE_Communications_Queue* th = this;
    L->Log("Flushing queue for player %d", param_1);

    unsigned int i = 0;
    do {
        MsgQueue* q = &th->Queue[i];
        unsigned int from = q->From;
        if (from == param_1 && q->Size > 0) {
            L->Log("Remove Q #%d Seq=%d ToExecute %ld From P#%d Size=%d CtrlCmd=%d",
                i, q->SeqNo, q->ExecTurn, from, q->Size,
                q->ControlCommand, q->Code);

            void* data = q->msgptr;
            q->Code = 0;
            q->ExecTurn = 0;
            q->SeqNo = 0;
            q->From = 0;
            q->Size = 0;
            q->ControlCommand = 0;
            if (data != 0) {
                operator delete(data);
            }
            q->msgptr = 0;
        }
        i++;
    } while (i <= th->HighQueueDepth);
}

unsigned int RGE_Communications_Queue::FlushForTurn(unsigned long turn) {
    return this->FlushTurnRange(turn, turn);
}

unsigned int RGE_Communications_Queue::FlushThruTurn(unsigned long turn) {
    return this->FlushTurnRange(0, turn);
}

int RGE_Communications_Queue::AddItem(
    unsigned long turn, void* data, unsigned long size,
    unsigned int from, unsigned char sequence, int control) {
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

    char* message = static_cast<char*>(operator new(size + 1));
    slot->msgptr = message;

    if (message != 0) {
        memcpy(message, data, size);
    }

    this->Queue[i].Size = size;
    this->Queue[i].SeqNo = sequence;
    this->Queue[i].ExecTurn = turn;
    this->Queue[i].From = from;
    this->Queue[i].Code = (unsigned int)sequence + from * 1000;
    this->Queue[i].ControlCommand = control;
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
    unsigned int player, unsigned long turn, unsigned char sequence,
    unsigned int* size) {
    unsigned int targetCode = player * 1000 + sequence;
    unsigned int idx = 0;
    MsgQueue* entry = this->Queue;

    while (1) {
        if (entry->Code == targetCode && entry->ExecTurn == turn) {
            goto found;
        }
        idx++;
        entry++;
        if (idx > this->HighQueueDepth) {
            return 0;
        }
    }

found:
    *size = this->Queue[idx].Size;
    DAT_0062cf3c = this->Queue[idx].msgptr;
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

    return DAT_0062cf3c;
}

void* RGE_Communications_Queue::GetNextItemSingle() {
    MsgQueue* q = this->Queue;
    for (unsigned int i = 0; i <= this->HighQueueDepth; i++) {
        if (q[i].Size > 0) {
            DAT_0062cf34 = q[i].msgptr;
            MsgQueue* entry = this->Queue + i;
            entry->Code = 0;
            entry->ExecTurn = 0;
            entry->SeqNo = 0;
            entry->From = 0;
            entry->Size = 0;
            entry->ControlCommand = 0;
            this->Queue[i].msgptr = 0;
            return DAT_0062cf34;
        }
    }
    return 0;
}

void* RGE_Communications_Queue::GetNextItemOrdered(unsigned long turn) {
    unsigned int bestControlCommand = 0xFFFFFFFF;
    unsigned int i = 0;
    int bestIndex = -1;

    do {
        if (Queue[i].Code != 0 && Queue[i].Size != 0) {
            if (Queue[i].ExecTurn < turn) {
                TestShowQueue();
            }

            if (Queue[i].Code < bestControlCommand &&
                Queue[i].ExecTurn == turn) {
                bestControlCommand = Queue[i].Code;
                bestIndex = i;
            }
        }

        i++;
    } while (i <= HighQueueDepth);

    if (bestIndex == -1) {
        return 0;
    }

    DAT_0062cf38 = Queue[bestIndex].msgptr;
    Queue[bestIndex].msgptr = 0;

    MsgQueue* mq = Queue + bestIndex;
    mq->Code = 0;
    mq->ExecTurn = 0;
    mq->SeqNo = 0;
    mq->From = 0;
    mq->Size = 0;
    mq->ControlCommand = 0;

    return DAT_0062cf38;
}

unsigned char RGE_Communications_Queue::GetNextSequence(unsigned long turn) {
    if (turn != this->LastCurrentTurn) {
        this->Sequence = 1;
        this->LastCurrentTurn = turn;
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
