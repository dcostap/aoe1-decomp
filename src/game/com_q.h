#pragma once
#include "../common.h"

class MsgQueue {
public:
    ulong ExecTurn;                          // 0x4
    uchar SeqNo;                             // 0x8
    char* msgptr;                            // 0xC
    uint From;                               // 0x10
    uint Size;                               // 0x14
    int ControlCommand;                      // 0x18

    MsgQueue();
    virtual ~MsgQueue();
};

static_assert(sizeof(MsgQueue) == 0x1C, "MsgQueue Size Mismatch");
static_assert(offsetof(MsgQueue, ControlCommand) == 0x18, "MsgQueue Offset Mismatch");

class RGE_Communications_Queue {
public:
    uint HighQueueDepth;                     // 0x4
    uint MaxQSize;                           // 0x8
    char TBuff[255];                         // 0xC
    ulong LastCurrentTurn;                   // 0x10C
    uchar Sequence;                          // 0x110
    MsgQueue* Queue;                         // 0x114

    RGE_Communications_Queue(int param_1);
    virtual ~RGE_Communications_Queue();
    virtual int AllocateQueue(uint param_1);
    virtual uchar ExpectedNextSequence(ulong param_1, uint param_2);
    virtual uint QueuedForTurn(ulong param_1);
    virtual void FlushAll();
    virtual uint FlushTurnRange(ulong param_1, ulong param_2);
    virtual void FlushForPlayer(uint param_1);
    virtual uint FlushForTurn(ulong param_1);
    virtual uint FlushThruTurn(ulong param_1);
    virtual int AddItem(ulong param_1, void* param_2, ulong param_3, uint param_4, uchar param_5, int param_6);
    virtual uint GetQueueDepth();
    virtual uint GetHighQueueDepth();
    virtual void* GetSpecificItem(uint param_1, ulong param_2, uchar param_3, uint* param_4);
    virtual void* GetNextItemSingle();
    virtual void* GetNextItemOrdered(ulong param_1);
    virtual uchar GetNextSequence(ulong param_1);
    virtual void TestShowQueue();
};

static_assert(sizeof(RGE_Communications_Queue) == 0x118, "RGE_Communications_Queue Size Mismatch");
static_assert(offsetof(RGE_Communications_Queue, Queue) == 0x114, "RGE_Communications_Queue Offset Mismatch");

inline MsgQueue::MsgQueue() {
    /* TODO: Stub */
//                              undefined __thiscall MsgQueue(MsgQueue * this)
//              undefined         <UNASSIGNED>   <RETURN>
//              MsgQueue *        ECX:4 (auto)   this
//                               ??0MsgQueue@@QAE@XZ                                          XREF[1]:     AllocateQueue:0043186d(*)
//                               MsgQueue::MsgQueue
//                              com_q.h:18 (2)
//         00431f60     MOV        EAX,this
//                              com_q.h:23 (22)
//         00431f62     XOR        this,this
//         00431f64     MOV        dword ptr [EAX],this
//         00431f66     MOV        dword ptr [EAX + 0x4],this
//         00431f69     MOV        byte ptr [EAX + 0x8],this
//         00431f6c     MOV        dword ptr [EAX + 0x10],this
//         00431f6f     MOV        dword ptr [EAX + 0x14],this
//         00431f72     MOV        dword ptr [EAX + 0x18],this
//         00431f75     MOV        dword ptr [EAX + 0xc],this
//                              com_q.h:24 (1)
//         00431f78     RET
//         00431f79     ??         90h
//         00431f7a     NOP
//         00431f7b     NOP
//         00431f7c     NOP
//         00431f7d     NOP
//         00431f7e     NOP
//         00431f7f     NOP
}

inline MsgQueue::~MsgQueue() {
    /* TODO: Stub */
//                              void __thiscall ~MsgQueue(MsgQueue * this)
//              void              <VOID>         <RETURN>
//              MsgQueue *        ECX:4 (auto)   this
//                               ??1MsgQueue@@QAE@XZ                                          XREF[4]:     ~RGE_Communications_Queue:00431771
//                               MsgQueue::~MsgQueue                                                       `vector_deleting_destructor':00431
//                                                                                                         AllocateQueue:00431868(*),
//                                                                                                         AllocateQueue:0043199e(*)
//                              com_q.h:27 (4)
//         00431f80     PUSH       EBX
//         00431f81     PUSH       ESI
//         00431f82     MOV        ESI,this
//                              com_q.h:28 (38)
//         00431f84     XOR        EBX,EBX
//         00431f86     MOV        EAX,dword ptr [ESI + 0xc]
//         00431f89     MOV        dword ptr [ESI],EBX
//         00431f8b     CMP        EAX,EBX
//         00431f8d     MOV        dword ptr [ESI + 0x4],EBX
//         00431f90     MOV        byte ptr [ESI + 0x8],BL
//         00431f93     MOV        dword ptr [ESI + 0x10],EBX
//         00431f96     MOV        dword ptr [ESI + 0x14],EBX
//         00431f99     MOV        dword ptr [ESI + 0x18],EBX
//         00431f9c     JZ         LAB_00431fa7
//         00431f9e     PUSH       EAX
//         00431f9f     CALL       operator_delete                                  void operator_delete(void * param_1)
//         00431fa4     ADD        ESP,0x4
//                               LAB_00431fa7                                                 XREF[1]:     00431f9c(j)
//         00431fa7     MOV        dword ptr [ESI + 0xc],EBX
//                              com_q.h:29 (3)
//         00431faa     POP        ESI
//         00431fab     POP        EBX
//         00431fac     RET
//         00431fad     ??         90h
//         00431fae     NOP
//         00431faf     NOP
}

