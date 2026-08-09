// 00431810 AllocateQueue
// 464 bytes, __thiscall, RGE_Communications_Queue method
// Attempt log:
// - The inherited scratch draft used raw vector helpers/absolute ctor-dtor
//   addresses and an incorrect 0x24-byte MsgQueue layout; it is not retained.
// - Baseline reconstruction uses the period C++ surfaces: real MsgQueue
//   constructor/destructor declarations, new MsgQueue[count], delete[], a
//   natural counted migration loop, and a typed data copy.
// - Corrected the queue record to Code/ExecTurn/SeqNo/msgptr/From/Size/
//   ControlCommand at the proven 0x1C stride; direct indexed migration plus
//   explicit binary-observed destination zeroing restored size/frame parity.
// - A named Size/source pair before data allocation restored the old-data
//   liveness and copy schedule.  Positive result handling restored one shared
//   return and the 0x14 EH frame, but the remaining EH prologue/block layout
//   and relocation identity are unresolved after the 10-probe budget.

#include <string.h>

void __cdecl operator delete(void* ptr);

class MsgQueue {
public:
    unsigned int Code;
    unsigned int ExecTurn;
    unsigned char SeqNo;
    char gap_09[3];
    char* msgptr;
    unsigned int From;
    unsigned int Size;
    int ControlCommand;

    MsgQueue();
    ~MsgQueue();
};

MsgQueue::MsgQueue() {
    this->Code = 0;
    this->ExecTurn = 0;
    this->SeqNo = 0;
    this->From = 0;
    this->Size = 0;
    this->ControlCommand = 0;
    this->msgptr = 0;
}

MsgQueue::~MsgQueue() {
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

    int AllocateQueue(unsigned int param_1);
};

int RGE_Communications_Queue::AllocateQueue(unsigned int param_1) {
    int result;
    result = 0;
    if (param_1 >= this->MaxQSize) {
        unsigned int count = param_1 + 1;
        MsgQueue* newQueue = new MsgQueue[count];
        if (newQueue != 0) {
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

            this->MaxQSize = param_1;
            this->Queue = newQueue;
            result = 1;
        }
    }

    return result;
}
