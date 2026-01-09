#include "common.h"
#include "com_q.h"

MsgQueue::MsgQueue() {
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

RGE_Communications_Queue::RGE_Communications_Queue(int param_1) {
    /* TODO: Stub */
    //                              undefined __thiscall RGE_Communications_Queue(RGE_Communications_Que
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00431720(R)  
    //                               ??0RGE_Communications_Queue@@QAE@H@Z                         XREF[1]:     TCommunications_Handler:00425cee(c
    //                               RGE_Communications_Queue::RGE_Communications_Queue
    //                              com_q.cpp:24 (17)
    //         00431720     MOV        EAX,dword ptr [ESP + param_1]
    //         00431724     PUSH       ESI
    //         00431725     CMP        EAX,0x14
    //         00431728     MOV        ESI,this
    //         0043172a     JGE        LAB_00431731
    //         0043172c     MOV        EAX,0x14
    //                               LAB_00431731                                                 XREF[1]:     0043172a(j)  
    //                              com_q.cpp:26 (2)
    //         00431731     XOR        this,this
    //                              com_q.cpp:34 (35)
    //         00431733     PUSH       EAX
    //         00431734     MOV        dword ptr [ESI],this
    //         00431736     MOV        dword ptr [ESI + 0x4],this
    //         00431739     MOV        dword ptr [ESI + 0x10c],this
    //         0043173f     MOV        dword ptr [ESI + 0x114],this
    //         00431745     MOV        this,ESI
    //         00431747     MOV        dword ptr [ESI + 0x8],EAX
    //         0043174a     MOV        byte ptr [ESI + 0x110],0x1
    //         00431751     CALL       RGE_Communications_Queue::AllocateQueue          int AllocateQueue(RGE_Communications_Queue * 
    //                              com_q.cpp:35 (6)
    //         00431756     MOV        EAX,ESI
    //         00431758     POP        ESI
    //         00431759     RET        0x4
    //         0043175c     ??         90h
    //         0043175d     NOP
    //         0043175e     NOP
    //         0043175f     NOP
}

MsgQueue::~MsgQueue() {
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

RGE_Communications_Queue::~RGE_Communications_Queue() {
    /* TODO: Stub */
    //                              void __thiscall ~RGE_Communications_Queue(RGE_Communications_Queue *
    //              void              <VOID>         <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //                               ??1RGE_Communications_Queue@@QAE@XZ                          XREF[1]:     ~TCommunications_Handler:004262d2(
    //                               RGE_Communications_Queue::~RGE_Communications_Queue
    //                              com_q.cpp:38 (41)
    //         00431760     MOV        EAX,dword ptr [ECX + this->Queue]
    //         00431766     TEST       EAX,EAX
    //         00431768     JZ         LAB_00431789
    //         0043176a     MOV        this,dword ptr [EAX + -0x4]
    //         0043176d     PUSH       ESI
    //         0043176e     LEA        ESI,[EAX + -0x4]
    //         00431771     PUSH       MsgQueue::~MsgQueue
    //         00431776     PUSH       this
    //         00431777     PUSH       0x1c
    //         00431779     PUSH       EAX
    //         0043177a     CALL       `eh_vector_destructor_iterator'                  void `eh_vector_destructor_iterator'(void * p
    //         0043177f     PUSH       ESI
    //         00431780     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00431785     ADD        ESP,0x4
    //         00431788     POP        ESI
    //                               LAB_00431789                                                 XREF[1]:     00431768(j)  
    //                              com_q.cpp:40 (1)
    //         00431789     RET
    //         0043178a     ??         90h
    //         0043178b     NOP
    //         0043178c     NOP
    //         0043178d     NOP
    //         0043178e     NOP
    //         0043178f     NOP
}

int RGE_Communications_Queue::AllocateQueue(uint param_1) {
    /* TODO: Stub */
    //                              int __thiscall AllocateQueue(RGE_Communications_Queue * this, uint p
    //              int               EAX:4          <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[2]:     00431829(R), 004319b5(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00431862(W), 0043188e(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004319cb(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[3]:     0043185a(W), 004318bb(W), 00431973(R)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[2]:     00431832(W), 00431946(R)  
    //              undefined4        Stack[-0x18]:4 local_18                  XREF[2]:     00431919(W), 00431930(R)  
    //              undefined4        Stack[-0x1c]:4 local_1c                  XREF[3]:     004318b2(W), 00431977(R), 00431984(W)  
    //              uint              Stack[-0x20]:4 i                         XREF[4]:     00431880(W), 00431886(W), 0043188a(R), 004319b9(R)  
    //                               ?AllocateQueue@RGE_Communications_Queue@@IAEHI@Z             XREF[2]:     RGE_Communications_Queue:00431751(
    //                               RGE_Communications_Queue::AllocateQueue                                   AddItem:00431c2e(c)  
    //                              com_q.cpp:43 (25)
    //         00431810     PUSH       -0x1
    //         00431812     PUSH       FUN_0055cedb
    //         00431817     MOV        EAX,FS:[0x0]
    //         0043181d     PUSH       EAX
    //         0043181e     MOV        dword ptr FS:[0x0],ESP
    //         00431825     SUB        ESP,0x14
    //         00431828     PUSH       EBX
    //                              com_q.cpp:58 (18)
    //         00431829     MOV        EBX,dword ptr [ESP + param_1]
    //         0043182d     PUSH       EBP
    //         0043182e     PUSH       ESI
    //         0043182f     MOV        ESI,this
    //         00431831     PUSH       EDI
    //         00431832     MOV        dword ptr [ESP + local_14],ESI
    //         00431836     CMP        EBX,dword ptr [ESI + 0x8]
    //         00431839     JNC        LAB_00431842
    //                              com_q.cpp:59 (7)
    //         0043183b     XOR        EAX,EAX
    //         0043183d     JMP        LAB_004319cb
    //                               LAB_00431842                                                 XREF[1]:     00431839(j)  
    //                              com_q.cpp:61 (72)
    //         00431842     INC        EBX
    //         00431843     MOV        EAX,EBX
    //         00431845     SHL        EAX,0x3
    //         00431848     SUB        EAX,EBX
    //         0043184a     LEA        this,[EAX*0x4 + 0x4]
    //         00431851     PUSH       this
    //         00431852     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00431857     ADD        ESP,0x4
    //         0043185a     MOV        dword ptr [ESP + local_10],EAX
    //         0043185e     XOR        EDI,EDI
    //         00431860     CMP        EAX,EDI
    //         00431862     MOV        dword ptr [ESP + local_4],EDI
    //         00431866     JZ         LAB_00431886
    //         00431868     PUSH       MsgQueue::~MsgQueue
    //         0043186d     PUSH       MsgQueue::MsgQueue
    //         00431872     LEA        EBP,[EAX + 0x4]
    //         00431875     PUSH       EBX
    //         00431876     PUSH       0x1c
    //         00431878     PUSH       EBP
    //         00431879     MOV        dword ptr [EAX],EBX
    //         0043187b     CALL       `eh_vector_constructor_iterator'                 void `eh_vector_constructor_iterator'(void * 
    //         00431880     MOV        dword ptr [ESP + i],EBP
    //         00431884     JMP        LAB_0043188a
    //                               LAB_00431886                                                 XREF[1]:     00431866(j)  
    //         00431886     MOV        dword ptr [ESP + i],EDI
    //                               LAB_0043188a                                                 XREF[1]:     00431884(j)  
    //                              com_q.cpp:63 (16)
    //         0043188a     MOV        this,dword ptr [ESP + i]
    //         0043188e     MOV        dword ptr [ESP + local_4],0xffffffff
    //         00431896     CMP        this,EDI
    //         00431898     JNZ        LAB_004318a1
    //                              com_q.cpp:64 (7)
    //         0043189a     XOR        EAX,EAX
    //         0043189c     JMP        LAB_004319cb
    //                               LAB_004318a1                                                 XREF[1]:     00431898(j)  
    //                              com_q.cpp:68 (12)
    //         004318a1     CMP        dword ptr [ESI + 0x114],EDI
    //         004318a7     JZ         LAB_004319b5
    //                              com_q.cpp:97 (307)
    //         004318ad     MOV        EAX,0xfffffff8
    //         004318b2     MOV        dword ptr [ESP + local_1c],EDI
    //         004318b6     SUB        EAX,this
    //         004318b8     LEA        EBP,[ECX + this->MaxQSize]
    //         004318bb     MOV        dword ptr [ESP + local_10],EAX
    //                               LAB_004318bf                                                 XREF[1]:     00431988(j)  
    //         004318bf     MOV        EDX,dword ptr [ESI + 0x114]
    //         004318c5     LEA        EBX,[EAX + EBP*0x1]
    //         004318c8     CMP        dword ptr [EBX + EDX*0x1 + 0x14],EDI
    //         004318cc     JZ         LAB_00431977
    //         004318d2     MOV        dword ptr [EBP + -0x8],EDI
    //         004318d5     MOV        dword ptr [EBP + -0x4],EDI
    //         004318d8     MOV        byte ptr [EBP],0x0
    //         004318dc     MOV        dword ptr [EBP + 0x8],EDI
    //         004318df     MOV        dword ptr [EBP + 0xc],EDI
    //         004318e2     MOV        dword ptr [EBP + 0x10],EDI
    //         004318e5     MOV        EAX,dword ptr [ESI + 0x114]
    //         004318eb     MOV        this,dword ptr [EBX + EAX*0x1]
    //         004318ee     MOV        dword ptr [EBP + -0x8],this
    //         004318f1     MOV        EDX,dword ptr [ESI + 0x114]
    //         004318f7     MOV        EAX,dword ptr [EBX + EDX*0x1 + 0x4]
    //         004318fb     MOV        dword ptr [EBP + -0x4],EAX
    //         004318fe     MOV        this,dword ptr [ESI + 0x114]
    //         00431904     MOV        DL,byte ptr [EBX + this->QueueDepth*0x1 + 0x8]
    //         00431908     MOV        byte ptr [EBP],DL
    //         0043190b     MOV        EAX,dword ptr [ESI + 0x114]
    //         00431911     ADD        EAX,EBX
    //         00431913     MOV        EDI,dword ptr [EAX + 0x14]
    //         00431916     MOV        this,dword ptr [EAX + 0xc]
    //         00431919     MOV        dword ptr [ESP + local_18],this
    //         0043191d     LEA        EDX,[EDI + 0x1]
    //         00431920     PUSH       EDX
    //         00431921     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00431926     ADD        ESP,0x4
    //         00431929     MOV        dword ptr [EBP + 0x4],EAX
    //         0043192c     TEST       EAX,EAX
    //         0043192e     JZ         LAB_0043194a
    //         00431930     MOV        ESI,dword ptr [ESP + local_18]
    //         00431934     MOV        this,EDI
    //         00431936     MOV        EDI,EAX
    //         00431938     MOV        EAX,this
    //         0043193a     SHR        this,0x2
    //         0043193d     MOVSD.REP  ES:EDI,ESI
    //         0043193f     MOV        this,EAX
    //         00431941     AND        this,0x3
    //         00431944     MOVSB.REP  ES:EDI,ESI
    //         00431946     MOV        ESI,dword ptr [ESP + local_14]
    //                               LAB_0043194a                                                 XREF[1]:     0043192e(j)  
    //         0043194a     MOV        this,dword ptr [ESI + 0x114]
    //         00431950     XOR        EDI,EDI
    //         00431952     MOV        EDX,dword ptr [EBX + this->QueueDepth*0x1 + 0x
    //         00431956     MOV        dword ptr [EBP + 0x8],EDX
    //         00431959     MOV        EAX,dword ptr [ESI + 0x114]
    //         0043195f     MOV        this,dword ptr [EBX + EAX*0x1 + 0x14]
    //         00431963     MOV        dword ptr [EBP + 0xc],this
    //         00431966     MOV        EDX,dword ptr [ESI + 0x114]
    //         0043196c     MOV        EAX,dword ptr [EBX + EDX*0x1 + 0x18]
    //         00431970     MOV        dword ptr [EBP + 0x10],EAX
    //         00431973     MOV        EAX,dword ptr [ESP + local_10]
    //                               LAB_00431977                                                 XREF[1]:     004318cc(j)  
    //         00431977     MOV        this,dword ptr [ESP + local_1c]
    //         0043197b     MOV        EDX,dword ptr [ESI + 0x8]
    //         0043197e     INC        this
    //         0043197f     ADD        EBP,0x1c
    //         00431982     CMP        this,EDX
    //         00431984     MOV        dword ptr [ESP + local_1c],this
    //         00431988     JBE        LAB_004318bf
    //         0043198e     MOV        EAX,dword ptr [ESI + 0x114]
    //         00431994     CMP        EAX,EDI
    //         00431996     JZ         LAB_004319b5
    //         00431998     MOV        this,dword ptr [EAX + -0x4]
    //         0043199b     LEA        EDI,[EAX + -0x4]
    //         0043199e     PUSH       MsgQueue::~MsgQueue
    //         004319a3     PUSH       this
    //         004319a4     PUSH       0x1c
    //         004319a6     PUSH       EAX
    //         004319a7     CALL       `eh_vector_destructor_iterator'                  void `eh_vector_destructor_iterator'(void * p
    //         004319ac     PUSH       EDI
    //         004319ad     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004319b2     ADD        ESP,0x4
    //                               LAB_004319b5                                                 XREF[2]:     004318a7(j), 00431996(j)  
    //         004319b5     MOV        EAX,dword ptr [ESP + param_1]
    //         004319b9     MOV        EDX,dword ptr [ESP + i]
    //         004319bd     MOV        dword ptr [ESI + 0x8],EAX
    //         004319c0     MOV        dword ptr [ESI + 0x114],EDX
    //         004319c6     MOV        EAX,0x1
    //                               LAB_004319cb                                                 XREF[2]:     0043183d(j), 0043189c(j)  
    //         004319cb     MOV        this,dword ptr [ESP + local_c]
    //         004319cf     POP        EDI
    //         004319d0     POP        ESI
    //         004319d1     POP        EBP
    //         004319d2     MOV        dword ptr FS:[0x0],this
    //         004319d9     POP        EBX
    //         004319da     ADD        ESP,0x20
    //         004319dd     RET        0x4
    //                              * public: unsigned char __thiscall RGE_Communications_Queue::ExpectedNextSequence(unsigned long,unsi... *
    //                              uchar __thiscall ExpectedNextSequence(RGE_Communications_Queue * thi
    //              uchar             AL:1           <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //              ulong             Stack[0x4]:4   param_1                   XREF[1]:     004319ea(R)  
    //              uint              Stack[0x8]:4   param_2                   XREF[1]:     004319e2(R)  
    //                               ?ExpectedNextSequence@RGE_Communications_Queue@@QAEEKI@Z
    //                               RGE_Communications_Queue::ExpectedNextSequence
    //                              com_q.cpp:141 (2)
    //         004319e0     PUSH       EBX
    //         004319e1     PUSH       EBP
    //                              com_q.cpp:147 (12)
    //         004319e2     MOV        EBP,dword ptr [ESP + param_2]
    //         004319e6     PUSH       ESI
    //         004319e7     MOV        BL,0x1
    //         004319e9     PUSH       EDI
    //         004319ea     MOV        EDI,dword ptr [ESP + param_1]
    //                              com_q.cpp:149 (10)
    //         004319ee     XOR        ESI,ESI
    //         004319f0     MOV        byte ptr [DAT_0062cf40],BL
    //         004319f6     XOR        EDX,EDX
    //                               LAB_004319f8                                                 XREF[1]:     00431a21(j)  
    //                              com_q.cpp:152 (24)
    //         004319f8     MOV        EAX,dword ptr [ECX + this->Queue]
    //         004319fe     ADD        EAX,EDX
    //         00431a00     CMP        dword ptr [EAX + 0x4],EDI
    //         00431a03     JNZ        LAB_00431a18
    //         00431a05     CMP        dword ptr [EAX + 0x10],EBP
    //         00431a08     JNZ        LAB_00431a18
    //         00431a0a     CMP        dword ptr [EAX + 0x14],0x0
    //         00431a0e     JZ         LAB_00431a18
    //                              com_q.cpp:153 (19)
    //         00431a10     INC        BL
    //         00431a12     MOV        byte ptr [DAT_0062cf40],BL
    //                               LAB_00431a18                                                 XREF[3]:     00431a03(j), 00431a08(j), 
    //                                                                                                         00431a0e(j)  
    //         00431a18     MOV        EAX,dword ptr [ECX + this->HighQueueDepth]
    //         00431a1b     INC        ESI
    //         00431a1c     ADD        EDX,0x1c
    //         00431a1f     CMP        ESI,EAX
    //         00431a21     JBE        LAB_004319f8
    //                              com_q.cpp:155 (3)
    //         00431a23     OR         this,0xff
    //                              com_q.cpp:165 (21)
    //         00431a26     POP        EDI
    //         00431a27     CMP        this,BL
    //         00431a29     MOV        this,dword ptr [DAT_0062cf40]
    //         00431a2f     SBB        AL,AL
    //         00431a31     POP        ESI
    //         00431a32     NOT        AL
    //         00431a34     POP        EBP
    //         00431a35     AND        EAX,this
    //         00431a37     POP        EBX
    //         00431a38     RET        0x8
    //         00431a3b     ??         90h
    //         00431a3c     NOP
    //         00431a3d     NOP
    //         00431a3e     NOP
    //         00431a3f     NOP
    return 0;
}

uint RGE_Communications_Queue::QueuedForTurn(ulong param_1) {
    /* TODO: Stub */
    //                              uint __thiscall QueuedForTurn(RGE_Communications_Queue * this, ulong
    //              uint              EAX:4          <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //              ulong             Stack[0x4]:4   param_1                   XREF[1]:     00431a4a(R)  
    //                               ?QueuedForTurn@RGE_Communications_Queue@@IAEIK@Z
    //                               RGE_Communications_Queue::QueuedForTurn
    //                              com_q.cpp:168 (20)
    //         00431a40     MOV        EDX,dword ptr [ECX + this->Queue]
    //         00431a46     MOV        this,dword ptr [ECX + this->HighQueueDepth]
    //         00431a49     PUSH       ESI
    //         00431a4a     MOV        ESI,dword ptr [ESP + param_1]
    //         00431a4e     XOR        EAX,EAX
    //         00431a50     ADD        EDX,0x4
    //         00431a53     INC        this
    //                               LAB_00431a54                                                 XREF[1]:     00431a5d(j)  
    //                              com_q.cpp:174 (4)
    //         00431a54     CMP        dword ptr [EDX],ESI
    //         00431a56     JNZ        LAB_00431a59
    //                              com_q.cpp:175 (1)
    //         00431a58     INC        EAX
    //                               LAB_00431a59                                                 XREF[1]:     00431a56(j)  
    //                              com_q.cpp:173 (6)
    //         00431a59     ADD        EDX,0x1c
    //         00431a5c     DEC        this
    //         00431a5d     JNZ        LAB_00431a54
    //                              com_q.cpp:178 (4)
    //         00431a5f     POP        ESI
    //         00431a60     RET        0x4
    //         00431a63     ??         90h
    //         00431a64     NOP
    //         00431a65     NOP
    //         00431a66     NOP
    //         00431a67     NOP
    //         00431a68     NOP
    //         00431a69     NOP
    //         00431a6a     NOP
    //         00431a6b     NOP
    //         00431a6c     NOP
    //         00431a6d     NOP
    //         00431a6e     NOP
    //         00431a6f     NOP
    return 0;
}

void RGE_Communications_Queue::FlushAll() {
    /* TODO: Stub */
    //                              void __thiscall FlushAll(RGE_Communications_Queue * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //                               ?FlushAll@RGE_Communications_Queue@@QAEXXZ                   XREF[12]:    GameOver:00425767(c), 
    //                               RGE_Communications_Queue::FlushAll                                        GameOver:00425776(c), 
    //                                                                                                         TCommunications_Handler:0042608b(c
    //                                                                                                         TCommunications_Handler:0042609a(c
    //                                                                                                         DestroyMultiplayerGame:0042ba8d(c)
    //                                                                                                         DestroyMultiplayerGame:0042ba9c(c)
    //                                                                                                         UnlinkCurrentLevel:0042bd58(c), 
    //                                                                                                         UnlinkCurrentLevel:0042bd67(c), 
    //                                                                                                         UnlinkCurrentLevel:0042bfd2(c), 
    //                                                                                                         UnlinkCurrentLevel:0042bfe1(c), 
    //                                                                                                         UnlinkCurrentLevel:0042c438(c), 
    //                                                                                                         UnlinkCurrentLevel:0042c527(c)  
    //                              com_q.cpp:181 (9)
    //         00431a70     PUSH       0x0
    //         00431a72     PUSH       0x0
    //         00431a74     CALL       RGE_Communications_Queue::FlushTurnRange         uint FlushTurnRange(RGE_Communications_Queue 
    //                              com_q.cpp:184 (1)
    //         00431a79     RET
    //         00431a7a     ??         90h
    //         00431a7b     NOP
    //         00431a7c     NOP
    //         00431a7d     NOP
    //         00431a7e     NOP
    //         00431a7f     NOP
    return;
}

uint RGE_Communications_Queue::FlushTurnRange(ulong param_1, ulong param_2) {
    /* TODO: Stub */
    //                              uint __thiscall FlushTurnRange(RGE_Communications_Queue * this, ulon
    //              uint              EAX:4          <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //              ulong             Stack[0x4]:4   param_1                   XREF[1]:     00431a9b(R)  
    //              ulong             Stack[0x8]:4   param_2                   XREF[2]:     00431aaa(R), 00431ab4(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     00431a8f(W), 00431aee(R), 00431afb(W)  
    //              uint              Stack[-0x8]:4  i                         XREF[4]:     00431a8b(W), 00431aba(R), 00431ac4(W), 00431b01(R)  
    //              uint              Stack[-0xc]:4  Count
    //                               ?FlushTurnRange@RGE_Communications_Queue@@QAEIKK@Z           XREF[3]:     FlushAll:00431a74(c), 
    //                               RGE_Communications_Queue::FlushTurnRange                                  FlushForTurn:00431bd6(c), 
    //                                                                                                         FlushThruTurn:00431be7(c)  
    //                              com_q.cpp:187 (6)
    //         00431a80     SUB        ESP,0x8
    //         00431a83     PUSH       EBX
    //         00431a84     PUSH       EBP
    //         00431a85     PUSH       ESI
    //                              com_q.cpp:190 (9)
    //         00431a86     XOR        EBX,EBX
    //         00431a88     PUSH       EDI
    //         00431a89     MOV        EBP,this
    //         00431a8b     MOV        dword ptr [ESP + i],EBX
    //                              com_q.cpp:193 (6)
    //         00431a8f     MOV        dword ptr [ESP + local_4],EBX
    //         00431a93     XOR        EDI,EDI
    //                               LAB_00431a95                                                 XREF[1]:     00431aff(j)  
    //                              com_q.cpp:196 (37)
    //         00431a95     MOV        EAX,dword ptr [EBP + 0x114]
    //         00431a9b     MOV        this,dword ptr [ESP + param_1]
    //         00431a9f     LEA        ESI,[EAX + EDI*0x1]
    //         00431aa2     MOV        EAX,dword ptr [EAX + EDI*0x1 + 0x4]
    //         00431aa6     CMP        EAX,this
    //         00431aa8     JC         LAB_00431ab0
    //         00431aaa     CMP        EAX,dword ptr [ESP + param_2]
    //         00431aae     JBE        LAB_00431aba
    //                               LAB_00431ab0                                                 XREF[1]:     00431aa8(j)  
    //         00431ab0     CMP        this,EBX
    //         00431ab2     JNZ        LAB_00431aee
    //         00431ab4     CMP        dword ptr [ESP + param_2],EBX
    //         00431ab8     JNZ        LAB_00431aee
    //                               LAB_00431aba                                                 XREF[1]:     00431aae(j)  
    //                              com_q.cpp:199 (4)
    //         00431aba     MOV        this,dword ptr [ESP + i]
    //                              com_q.cpp:200 (12)
    //         00431abe     MOV        EAX,dword ptr [ESI + 0x14]
    //         00431ac1     INC        this
    //         00431ac2     CMP        EAX,EBX
    //         00431ac4     MOV        dword ptr [ESP + i],this
    //         00431ac8     JBE        LAB_00431aee
    //                              com_q.cpp:201 (36)
    //         00431aca     MOV        EAX,dword ptr [ESI + 0xc]
    //         00431acd     MOV        dword ptr [ESI],EBX
    //         00431acf     CMP        EAX,EBX
    //         00431ad1     MOV        dword ptr [ESI + 0x4],EBX
    //         00431ad4     MOV        byte ptr [ESI + 0x8],BL
    //         00431ad7     MOV        dword ptr [ESI + 0x10],EBX
    //         00431ada     MOV        dword ptr [ESI + 0x14],EBX
    //         00431add     MOV        dword ptr [ESI + 0x18],EBX
    //         00431ae0     JZ         LAB_00431aeb
    //         00431ae2     PUSH       EAX
    //         00431ae3     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00431ae8     ADD        ESP,0x4
    //                               LAB_00431aeb                                                 XREF[1]:     00431ae0(j)  
    //         00431aeb     MOV        dword ptr [ESI + 0xc],EBX
    //                               LAB_00431aee                                                 XREF[3]:     00431ab2(j), 00431ab8(j), 
    //                                                                                                         00431ac8(j)  
    //                              com_q.cpp:193 (19)
    //         00431aee     MOV        EAX,dword ptr [ESP + local_4]
    //         00431af2     MOV        this,dword ptr [EBP + 0x4]
    //         00431af5     INC        EAX
    //         00431af6     ADD        EDI,0x1c
    //         00431af9     CMP        EAX,this
    //         00431afb     MOV        dword ptr [ESP + local_4],EAX
    //         00431aff     JBE        LAB_00431a95
    //                              com_q.cpp:204 (4)
    //         00431b01     MOV        EAX,dword ptr [ESP + i]
    //                              com_q.cpp:205 (10)
    //         00431b05     POP        EDI
    //         00431b06     POP        ESI
    //         00431b07     POP        EBP
    //         00431b08     POP        EBX
    //         00431b09     ADD        ESP,0x8
    //         00431b0c     RET        0x8
    //         00431b0f     ??         90h
    return 0;
}

void RGE_Communications_Queue::FlushForPlayer(uint param_1) {
    /* TODO: Stub */
    //                              void __thiscall FlushForPlayer(RGE_Communications_Queue * this, uint
    //              void              <VOID>         <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[2]:     00431b11(R), 00431b45(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     00431b32(W), 00431b64(R), 00431baa(R), 00431bb7(W)  
    //              uint              Stack[-0x8]:4  i
    //                               ?FlushForPlayer@RGE_Communications_Queue@@QAEXI@Z            XREF[1]:     InitPlayerInformation:0042d380(c)  
    //                               RGE_Communications_Queue::FlushForPlayer
    //                              com_q.cpp:208 (1)
    //         00431b10     PUSH       this
    //                              com_q.cpp:209 (28)
    //         00431b11     MOV        EAX,dword ptr [ESP + param_1]
    //         00431b15     PUSH       EBX
    //         00431b16     PUSH       EBP
    //         00431b17     PUSH       ESI
    //         00431b18     MOV        EBP,this
    //         00431b1a     PUSH       EDI
    //         00431b1b     MOV        this,dword ptr [L]                               = 00000000
    //         00431b21     PUSH       EAX
    //         00431b22     PUSH       s_Flushing_queue_for_player_%d                   = "Flushing queue for player %d"
    //         00431b27     PUSH       this
    //         00431b28     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //                              com_q.cpp:210 (11)
    //         00431b2d     XOR        EBX,EBX
    //         00431b2f     ADD        ESP,0xc
    //         00431b32     MOV        dword ptr [ESP + local_4],EBX
    //         00431b36     XOR        EDI,EDI
    //                               LAB_00431b38                                                 XREF[1]:     00431bbb(j)  
    //                              com_q.cpp:212 (19)
    //         00431b38     MOV        EDX,dword ptr [EBP + 0x114]
    //         00431b3e     MOV        this,dword ptr [EDX + EDI*0x1 + 0x10]
    //         00431b42     LEA        EAX,[EDX + EDI*0x1]
    //         00431b45     CMP        this,dword ptr [ESP + param_1]
    //         00431b49     JNZ        LAB_00431baa
    //                              com_q.cpp:215 (7)
    //         00431b4b     MOV        EDX,dword ptr [EAX + 0x14]
    //         00431b4e     CMP        EDX,EBX
    //         00431b50     JBE        LAB_00431baa
    //                              com_q.cpp:224 (41)
    //         00431b52     MOV        ESI,dword ptr [EAX]
    //         00431b54     PUSH       ESI
    //         00431b55     MOV        ESI,dword ptr [EAX + 0x18]
    //         00431b58     PUSH       ESI
    //         00431b59     PUSH       EDX
    //         00431b5a     PUSH       this
    //         00431b5b     MOV        this,dword ptr [EAX + 0x4]
    //         00431b5e     XOR        EDX,EDX
    //         00431b60     PUSH       this
    //         00431b61     MOV        DL,byte ptr [EAX + 0x8]
    //         00431b64     MOV        EAX,dword ptr [ESP + local_4]
    //         00431b68     MOV        this,dword ptr [L]                               = 00000000
    //         00431b6e     PUSH       EDX
    //         00431b6f     PUSH       EAX
    //         00431b70     PUSH       s_Remove_Q_#%d_Seq=%d_ToExecute_%l               = "Remove Q #%d Seq=%d ToExecute %ld From P#%
    //         00431b75     PUSH       this
    //         00431b76     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //                              com_q.cpp:226 (47)
    //         00431b7b     MOV        ESI,dword ptr [EBP + 0x114]
    //         00431b81     ADD        ESP,0x24
    //         00431b84     ADD        ESI,EDI
    //         00431b86     MOV        EAX,dword ptr [ESI + 0xc]
    //         00431b89     MOV        dword ptr [ESI],EBX
    //         00431b8b     CMP        EAX,EBX
    //         00431b8d     MOV        dword ptr [ESI + 0x4],EBX
    //         00431b90     MOV        byte ptr [ESI + 0x8],BL
    //         00431b93     MOV        dword ptr [ESI + 0x10],EBX
    //         00431b96     MOV        dword ptr [ESI + 0x14],EBX
    //         00431b99     MOV        dword ptr [ESI + 0x18],EBX
    //         00431b9c     JZ         LAB_00431ba7
    //         00431b9e     PUSH       EAX
    //         00431b9f     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00431ba4     ADD        ESP,0x4
    //                               LAB_00431ba7                                                 XREF[1]:     00431b9c(j)  
    //         00431ba7     MOV        dword ptr [ESI + 0xc],EBX
    //                               LAB_00431baa                                                 XREF[2]:     00431b49(j), 00431b50(j)  
    //                              com_q.cpp:210 (23)
    //         00431baa     MOV        EAX,dword ptr [ESP + local_4]
    //         00431bae     MOV        this,dword ptr [EBP + 0x4]
    //         00431bb1     INC        EAX
    //         00431bb2     ADD        EDI,0x1c
    //         00431bb5     CMP        EAX,this
    //         00431bb7     MOV        dword ptr [ESP + local_4],EAX
    //         00431bbb     JBE        LAB_00431b38
    //                              com_q.cpp:230 (8)
    //         00431bc1     POP        EDI
    //         00431bc2     POP        ESI
    //         00431bc3     POP        EBP
    //         00431bc4     POP        EBX
    //         00431bc5     POP        this
    //         00431bc6     RET        0x4
    //         00431bc9     ??         90h
    //         00431bca     NOP
    //         00431bcb     NOP
    //         00431bcc     NOP
    //         00431bcd     NOP
    //         00431bce     NOP
    //         00431bcf     NOP
    return;
}

uint RGE_Communications_Queue::FlushForTurn(ulong param_1) {
    /* TODO: Stub */
    //                              uint __thiscall FlushForTurn(RGE_Communications_Queue * this, ulong 
    //              uint              EAX:4          <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //              ulong             Stack[0x4]:4   param_1                   XREF[1]:     00431bd0(R)  
    //                               ?FlushForTurn@RGE_Communications_Queue@@QAEIK@Z
    //                               RGE_Communications_Queue::FlushForTurn
    //                              com_q.cpp:233 (11)
    //         00431bd0     MOV        EAX,dword ptr [ESP + param_1]
    //         00431bd4     PUSH       EAX
    //         00431bd5     PUSH       EAX
    //         00431bd6     CALL       RGE_Communications_Queue::FlushTurnRange         uint FlushTurnRange(RGE_Communications_Queue 
    //                              com_q.cpp:236 (3)
    //         00431bdb     RET        0x4
    //         00431bde     ??         90h
    //         00431bdf     NOP
    return 0;
}

uint RGE_Communications_Queue::FlushThruTurn(ulong param_1) {
    /* TODO: Stub */
    //                              uint __thiscall FlushThruTurn(RGE_Communications_Queue * this, ulong
    //              uint              EAX:4          <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //              ulong             Stack[0x4]:4   param_1                   XREF[1]:     00431be0(R)  
    //                               ?FlushThruTurn@RGE_Communications_Queue@@QAEIK@Z
    //                               RGE_Communications_Queue::FlushThruTurn
    //                              com_q.cpp:239 (12)
    //         00431be0     MOV        EAX,dword ptr [ESP + param_1]
    //         00431be4     PUSH       EAX
    //         00431be5     PUSH       0x0
    //         00431be7     CALL       RGE_Communications_Queue::FlushTurnRange         uint FlushTurnRange(RGE_Communications_Queue 
    //                              com_q.cpp:242 (3)
    //         00431bec     RET        0x4
    //         00431bef     ??         90h
    //                              * public: int __thiscall RGE_Communications_Queue::AddItem(unsigned long,void *,unsigned long,unsign... *
    //                              int __thiscall AddItem(RGE_Communications_Queue * this, ulong param_
    //              int               EAX:4          <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //              ulong             Stack[0x4]:4   param_1                   XREF[1]:     00431cb6(R)  
    //              void *            Stack[0x8]:4   param_2                   XREF[1]:     00431c7b(R)  
    //              ulong             Stack[0xc]:4   param_3                   XREF[3]:     00431c5d(R), 00431c77(R), 00431c99(R)  
    //              uint              Stack[0x10]:4  param_4                   XREF[1]:     00431cc9(R)  
    //              uchar             Stack[0x14]:1  param_5                   XREF[1]:     00431ca8(R)  
    //              int               Stack[0x18]:4  param_6                   XREF[1]:     00431cec(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     00431bff(W), 00431c1d(W), 00431c40(W), 00431c8f(R)  
    //              uint              Stack[-0x8]:4  i
    //                               ?AddItem@RGE_Communications_Queue@@QAEHKPAXKIEH@Z            XREF[1]:     AddCommand:00426494(c)  
    //                               RGE_Communications_Queue::AddItem
    //                              com_q.cpp:246 (6)
    //         00431bf0     PUSH       this
    //         00431bf1     PUSH       EBX
    //         00431bf2     PUSH       EBP
    //         00431bf3     MOV        EBP,this
    //         00431bf5     PUSH       ESI
    //                              com_q.cpp:247 (3)
    //         00431bf6     XOR        ESI,ESI
    //         00431bf8     PUSH       EDI
    //                              com_q.cpp:249 (28)
    //         00431bf9     MOV        EAX,dword ptr [EBP + 0x114]
    //         00431bff     MOV        dword ptr [ESP + local_4],ESI
    //         00431c03     ADD        EAX,0x14
    //         00431c06     CMP        dword ptr [EAX],0x0
    //         00431c09     JZ         LAB_00431c21
    //         00431c0b     MOV        this,dword ptr [EBP + 0x8]
    //                               LAB_00431c0e                                                 XREF[1]:     00431c1b(j)  
    //         00431c0e     CMP        ESI,this
    //         00431c10     JNC        LAB_00431c1d
    //         00431c12     MOV        EDX,dword ptr [EAX + 0x1c]
    //                              com_q.cpp:250 (12)
    //         00431c15     ADD        EAX,0x1c
    //         00431c18     INC        ESI
    //         00431c19     TEST       EDX,EDX
    //         00431c1b     JNZ        LAB_00431c0e
    //                               LAB_00431c1d                                                 XREF[1]:     00431c10(j)  
    //         00431c1d     MOV        dword ptr [ESP + local_4],ESI
    //                               LAB_00431c21                                                 XREF[1]:     00431c09(j)  
    //                              com_q.cpp:252 (7)
    //         00431c21     MOV        EAX,dword ptr [EBP + 0x8]
    //         00431c24     CMP        ESI,EAX
    //         00431c26     JC         LAB_00431c44
    //                              com_q.cpp:254 (15)
    //         00431c28     ADD        EAX,0x14
    //         00431c2b     MOV        this,EBP
    //         00431c2d     PUSH       EAX
    //         00431c2e     CALL       RGE_Communications_Queue::AllocateQueue          int AllocateQueue(RGE_Communications_Queue * 
    //         00431c33     TEST       EAX,EAX
    //         00431c35     JNZ        LAB_00431c3f
    //                              com_q.cpp:277 (8)
    //         00431c37     POP        EDI
    //         00431c38     POP        ESI
    //         00431c39     POP        EBP
    //         00431c3a     POP        EBX
    //         00431c3b     POP        this
    //         00431c3c     RET        0x18
    //                               LAB_00431c3f                                                 XREF[1]:     00431c35(j)  
    //                              com_q.cpp:256 (5)
    //         00431c3f     INC        ESI
    //         00431c40     MOV        dword ptr [ESP + local_4],ESI
    //                               LAB_00431c44                                                 XREF[1]:     00431c26(j)  
    //                              com_q.cpp:259 (9)
    //         00431c44     MOV        EAX,dword ptr [EBP + 0x4]
    //         00431c47     CMP        ESI,EAX
    //         00431c49     JBE        LAB_00431c4d
    //         00431c4b     MOV        EAX,ESI
    //                               LAB_00431c4d                                                 XREF[1]:     00431c49(j)  
    //                              com_q.cpp:262 (70)
    //         00431c4d     MOV        EDI,dword ptr [EBP + 0x114]
    //         00431c53     MOV        EBX,ESI
    //         00431c55     SHL        EBX,0x3
    //         00431c58     SUB        EBX,ESI
    //         00431c5a     MOV        dword ptr [EBP + 0x4],EAX
    //         00431c5d     MOV        EAX,dword ptr [ESP + param_3]
    //         00431c61     SHL        EBX,0x2
    //         00431c64     ADD        EDI,EBX
    //         00431c66     INC        EAX
    //         00431c67     PUSH       EAX
    //         00431c68     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00431c6d     ADD        ESP,0x4
    //         00431c70     MOV        dword ptr [EDI + 0xc],EAX
    //         00431c73     TEST       EAX,EAX
    //         00431c75     JZ         LAB_00431c93
    //         00431c77     MOV        this,dword ptr [ESP + param_3]
    //         00431c7b     MOV        ESI,dword ptr [ESP + param_2]
    //         00431c7f     MOV        EDX,this
    //         00431c81     MOV        EDI,EAX
    //         00431c83     SHR        this,0x2
    //         00431c86     MOVSD.REP  ES:EDI,ESI
    //         00431c88     MOV        this,EDX
    //         00431c8a     AND        this,0x3
    //         00431c8d     MOVSB.REP  ES:EDI,ESI
    //         00431c8f     MOV        ESI,dword ptr [ESP + local_4]
    //                               LAB_00431c93                                                 XREF[1]:     00431c75(j)  
    //                              com_q.cpp:266 (10)
    //         00431c93     MOV        EAX,dword ptr [EBP + 0x114]
    //         00431c99     MOV        this,dword ptr [ESP + param_3]
    //                              com_q.cpp:277 (102)
    //         00431c9d     POP        EDI
    //         00431c9e     MOV        dword ptr [EAX + EBX*0x1 + 0x14],this
    //         00431ca2     MOV        EDX,dword ptr [EBP + 0x114]
    //         00431ca8     MOV        EAX,dword ptr [ESP + param_5]
    //         00431cac     MOV        byte ptr [EDX + EBX*0x1 + 0x8],AL
    //         00431cb0     MOV        this,dword ptr [EBP + 0x114]
    //         00431cb6     MOV        EDX,dword ptr [ESP + param_1]
    //         00431cba     AND        EAX,0xff
    //         00431cbf     MOV        dword ptr [ECX + EBX*0x1 + this->HighQueueDept
    //         00431cc3     MOV        EDX,dword ptr [EBP + 0x114]
    //         00431cc9     MOV        this,dword ptr [ESP + param_4]
    //         00431ccd     MOV        dword ptr [EDX + EBX*0x1 + 0x10],this
    //         00431cd1     LEA        this,[ECX + ECX*0x4]
    //         00431cd4     LEA        this,[ECX + ECX*0x4]
    //         00431cd7     LEA        this,[ECX + ECX*0x4]
    //         00431cda     LEA        EDX,[EAX + this->QueueDepth*0x8]
    //         00431cdd     MOV        EAX,dword ptr [EBP + 0x114]
    //         00431ce3     MOV        dword ptr [EAX + EBX*0x1],EDX
    //         00431ce6     MOV        this,dword ptr [EBP + 0x114]
    //         00431cec     MOV        EDX,dword ptr [ESP + param_6]
    //         00431cf0     MOV        EAX,0x1
    //         00431cf5     MOV        dword ptr [ECX + EBX*0x1 + this+0x18],EDX
    //         00431cf9     MOV        dword ptr [EBP],ESI
    //         00431cfc     POP        ESI
    //         00431cfd     POP        EBP
    //         00431cfe     POP        EBX
    //         00431cff     POP        this
    //         00431d00     RET        0x18
    //         00431d03     ??         90h
    //         00431d04     NOP
    //         00431d05     NOP
    //         00431d06     NOP
    //         00431d07     NOP
    //         00431d08     NOP
    //         00431d09     NOP
    //         00431d0a     NOP
    //         00431d0b     NOP
    //         00431d0c     NOP
    //         00431d0d     NOP
    //         00431d0e     NOP
    //         00431d0f     NOP
    return 0;
}

uint RGE_Communications_Queue::GetQueueDepth() {
    /* TODO: Stub */
    //                              uint __thiscall GetQueueDepth(RGE_Communications_Queue * this)
    //              uint              EAX:4          <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //                               ?GetQueueDepth@RGE_Communications_Queue@@QAEIXZ
    //                               RGE_Communications_Queue::GetQueueDepth
    //                              com_q.cpp:288 (2)
    //         00431d10     MOV        EAX,dword ptr [this->QueueDepth]
    //                              com_q.cpp:290 (1)
    //         00431d12     RET
    //         00431d13     ??         90h
    //         00431d14     NOP
    //         00431d15     NOP
    //         00431d16     NOP
    //         00431d17     NOP
    //         00431d18     NOP
    //         00431d19     NOP
    //         00431d1a     NOP
    //         00431d1b     NOP
    //         00431d1c     NOP
    //         00431d1d     NOP
    //         00431d1e     NOP
    //         00431d1f     NOP
    return 0;
}

uint RGE_Communications_Queue::GetHighQueueDepth() {
    /* TODO: Stub */
    //                              uint __thiscall GetHighQueueDepth(RGE_Communications_Queue * this)
    //              uint              EAX:4          <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //                               ?GetHighQueueDepth@RGE_Communications_Queue@@QAEIXZ
    //                               RGE_Communications_Queue::GetHighQueueDepth
    //                              com_q.cpp:293 (3)
    //         00431d20     MOV        EAX,dword ptr [ECX + this->HighQueueDepth]
    //                              com_q.cpp:295 (1)
    //         00431d23     RET
    //         00431d24     ??         90h
    //         00431d25     NOP
    //         00431d26     NOP
    //         00431d27     NOP
    //         00431d28     NOP
    //         00431d29     NOP
    //         00431d2a     NOP
    //         00431d2b     NOP
    //         00431d2c     NOP
    //         00431d2d     NOP
    //         00431d2e     NOP
    //         00431d2f     NOP
    //                              * public: void * __thiscall RGE_Communications_Queue::GetSpecificItem(unsigned int,unsigned long,uns... *
    //                              void * __thiscall GetSpecificItem(RGE_Communications_Queue * this, u
    //              void *            EAX:4          <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00431d30(R)  
    //              ulong             Stack[0x8]:4   param_2                   XREF[1]:     00431d3d(R)  
    //              uchar             Stack[0xc]:1   param_3                   XREF[1]:     00431d34(R)  
    //              uint *            Stack[0x10]:4  param_4                   XREF[1]:     00431d87(R)  
    //                               ?GetSpecificItem@RGE_Communications_Queue@@QAEPAXIKEPAI@Z
    //                               RGE_Communications_Queue::GetSpecificItem
    //                              com_q.cpp:298 (24)
    //         00431d30     MOV        EAX,dword ptr [ESP + param_1]
    //         00431d34     MOV        EDX,dword ptr [ESP + param_3]
    //         00431d38     PUSH       EBX
    //         00431d39     PUSH       EBP
    //         00431d3a     LEA        EAX,[EAX + EAX*0x4]
    //         00431d3d     MOV        EBP,dword ptr [ESP + param_2]
    //         00431d41     AND        EDX,0xff
    //         00431d47     PUSH       ESI
    //                              com_q.cpp:307 (31)
    //         00431d48     MOV        ESI,dword ptr [ECX + this->Queue]
    //         00431d4e     LEA        EAX,[EAX + EAX*0x4]
    //         00431d51     PUSH       EDI
    //         00431d52     XOR        EBX,EBX
    //         00431d54     LEA        EAX,[EAX + EAX*0x4]
    //         00431d57     LEA        EDI,[EDX + EAX*0x8]
    //         00431d5a     XOR        EDX,EDX
    //         00431d5c     MOV        EAX,ESI
    //                               LAB_00431d5e                                                 XREF[1]:     00431d6e(j)  
    //         00431d5e     CMP        dword ptr [EAX],EDI
    //         00431d60     JNZ        LAB_00431d67
    //         00431d62     CMP        dword ptr [EAX + 0x4],EBP
    //         00431d65     JZ         LAB_00431d79
    //                               LAB_00431d67                                                 XREF[1]:     00431d60(j)  
    //                              com_q.cpp:304 (9)
    //         00431d67     INC        EDX
    //         00431d68     ADD        EAX,0x1c
    //         00431d6b     CMP        EDX,dword ptr [ECX + this->HighQueueDepth]
    //         00431d6e     JBE        LAB_00431d5e
    //                              com_q.cpp:322 (2)
    //         00431d70     XOR        EAX,EAX
    //                              com_q.cpp:323 (7)
    //         00431d72     POP        EDI
    //         00431d73     POP        ESI
    //         00431d74     POP        EBP
    //         00431d75     POP        EBX
    //         00431d76     RET        0x10
    //                               LAB_00431d79                                                 XREF[1]:     00431d65(j)  
    //                              com_q.cpp:312 (20)
    //         00431d79     MOV        EAX,EDX
    //         00431d7b     SHL        EAX,0x3
    //         00431d7e     SUB        EAX,EDX
    //         00431d80     SHL        EAX,0x2
    //         00431d83     MOV        EDX,dword ptr [ESI + EAX*0x1 + 0x14]
    //         00431d87     MOV        ESI,dword ptr [ESP + param_4]
    //         00431d8b     MOV        dword ptr [ESI],EDX
    //                              com_q.cpp:313 (16)
    //         00431d8d     MOV        EDX,dword ptr [ECX + this->Queue]
    //         00431d93     MOV        EDX,dword ptr [EDX + EAX*0x1 + 0xc]
    //         00431d97     MOV        dword ptr [DAT_0062cf3c],EDX
    //                              com_q.cpp:314 (10)
    //         00431d9d     MOV        EDX,dword ptr [ECX + this->Queue]
    //         00431da3     MOV        dword ptr [EDX + EAX*0x1 + 0xc],EBX
    //                              com_q.cpp:315 (25)
    //         00431da7     MOV        this,dword ptr [ECX + this->Queue]
    //         00431dad     ADD        this,EAX
    //         00431daf     MOV        dword ptr [this->QueueDepth],EBX
    //         00431db1     MOV        dword ptr [ECX + this->HighQueueDepth],EBX
    //         00431db4     MOV        byte ptr [ECX + this->MaxQSize],BL
    //         00431db7     MOV        dword ptr [ECX + this+0x10],EBX
    //         00431dba     MOV        dword ptr [ECX + this+0x14],EBX
    //         00431dbd     MOV        dword ptr [ECX + this+0x18],EBX
    //                              com_q.cpp:316 (5)
    //         00431dc0     MOV        EAX,[DAT_0062cf3c]
    //                              com_q.cpp:323 (7)
    //         00431dc5     POP        EDI
    //         00431dc6     POP        ESI
    //         00431dc7     POP        EBP
    //         00431dc8     POP        EBX
    //         00431dc9     RET        0x10
    //         00431dcc     ??         90h
    //         00431dcd     NOP
    //         00431dce     NOP
    //         00431dcf     NOP
    return 0;
}

void* RGE_Communications_Queue::GetNextItemSingle() {
    /* TODO: Stub */
    //                              void * __thiscall GetNextItemSingle(RGE_Communications_Queue * this)
    //              void *            EAX:4          <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //                               ?GetNextItemSingle@RGE_Communications_Queue@@QAEPAXXZ        XREF[2]:     get_command:004264e0(c), 
    //                               RGE_Communications_Queue::GetNextItemSingle                               get_command:004264f4(c)  
    //                              com_q.cpp:327 (2)
    //         00431dd0     PUSH       EBX
    //         00431dd1     PUSH       ESI
    //                              com_q.cpp:336 (14)
    //         00431dd2     MOV        ESI,dword ptr [ECX + this->Queue]
    //         00431dd8     XOR        EBX,EBX
    //         00431dda     PUSH       EDI
    //         00431ddb     XOR        EAX,EAX
    //         00431ddd     LEA        EDX,[ESI + 0x14]
    //                               LAB_00431de0                                                 XREF[1]:     00431ded(j)  
    //                              com_q.cpp:337 (15)
    //         00431de0     CMP        dword ptr [EDX],EBX
    //         00431de2     JA         LAB_00431df5
    //         00431de4     MOV        EDI,dword ptr [ECX + this->HighQueueDepth]
    //         00431de7     INC        EAX
    //         00431de8     ADD        EDX,0x1c
    //         00431deb     CMP        EAX,EDI
    //         00431ded     JBE        LAB_00431de0
    //                              com_q.cpp:345 (2)
    //         00431def     XOR        EAX,EAX
    //                              com_q.cpp:346 (4)
    //         00431df1     POP        EDI
    //         00431df2     POP        ESI
    //         00431df3     POP        EBX
    //         00431df4     RET
    //                               LAB_00431df5                                                 XREF[1]:     00431de2(j)  
    //                              com_q.cpp:339 (19)
    //         00431df5     MOV        EDX,EAX
    //         00431df7     SHL        EDX,0x3
    //         00431dfa     SUB        EDX,EAX
    //         00431dfc     SHL        EDX,0x2
    //         00431dff     MOV        EAX,dword ptr [ESI + EDX*0x1 + 0xc]
    //         00431e03     MOV        [DAT_0062cf34],EAX
    //                              com_q.cpp:340 (25)
    //         00431e08     MOV        EAX,dword ptr [ECX + this->Queue]
    //         00431e0e     ADD        EAX,EDX
    //         00431e10     MOV        dword ptr [EAX],EBX
    //         00431e12     MOV        dword ptr [EAX + 0x4],EBX
    //         00431e15     MOV        byte ptr [EAX + 0x8],BL
    //         00431e18     MOV        dword ptr [EAX + 0x10],EBX
    //         00431e1b     MOV        dword ptr [EAX + 0x14],EBX
    //         00431e1e     MOV        dword ptr [EAX + 0x18],EBX
    //                              com_q.cpp:341 (10)
    //         00431e21     MOV        this,dword ptr [ECX + this->Queue]
    //         00431e27     MOV        dword ptr [ECX + EDX*0x1 + this->TBuff[0]],EBX
    //                              com_q.cpp:342 (5)
    //         00431e2b     MOV        EAX,[DAT_0062cf34]
    //                              com_q.cpp:346 (4)
    //         00431e30     POP        EDI
    //         00431e31     POP        ESI
    //         00431e32     POP        EBX
    //         00431e33     RET
    //         00431e34     ??         90h
    //         00431e35     NOP
    //         00431e36     NOP
    //         00431e37     NOP
    //         00431e38     NOP
    //         00431e39     NOP
    //         00431e3a     NOP
    //         00431e3b     NOP
    //         00431e3c     NOP
    //         00431e3d     NOP
    //         00431e3e     NOP
    //         00431e3f     NOP
    return 0;
}

void* RGE_Communications_Queue::GetNextItemOrdered(ulong param_1) {
    /* TODO: Stub */
    //                              void * __thiscall GetNextItemOrdered(RGE_Communications_Queue * this
    //              void *            EAX:4          <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //              ulong             Stack[0x4]:4   param_1                   XREF[2]:     00431e69(R), 00431e88(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     00431e4c(W), 00431e93(W), 00431ea2(R)  
    //              int               Stack[-0x8]:4  SendMsg
    //                               ?GetNextItemOrdered@RGE_Communications_Queue@@QAEPAXK@Z      XREF[1]:     get_command:00426506(c)  
    //                               RGE_Communications_Queue::GetNextItemOrdered
    //                              com_q.cpp:350 (4)
    //         00431e40     PUSH       this
    //         00431e41     PUSH       EBX
    //         00431e42     PUSH       EBP
    //         00431e43     PUSH       ESI
    //                              com_q.cpp:356 (4)
    //         00431e44     OR         EBX,0xffffffff
    //         00431e47     PUSH       EDI
    //                              com_q.cpp:362 (10)
    //         00431e48     XOR        EBP,EBP
    //         00431e4a     MOV        ESI,this
    //         00431e4c     MOV        dword ptr [ESP + local_4],EBX
    //         00431e50     XOR        EDI,EDI
    //                               LAB_00431e52                                                 XREF[1]:     00431ea0(j)  
    //                              com_q.cpp:365 (20)
    //         00431e52     MOV        EAX,dword ptr [ESI + 0x114]
    //         00431e58     ADD        EAX,EDI
    //         00431e5a     CMP        dword ptr [EAX],0x0
    //         00431e5d     JZ         LAB_00431e97
    //         00431e5f     MOV        this,dword ptr [EAX + 0x14]
    //         00431e62     TEST       this,this
    //         00431e64     JZ         LAB_00431e97
    //                              com_q.cpp:369 (11)
    //         00431e66     MOV        this,dword ptr [EAX + 0x4]
    //         00431e69     MOV        EAX,dword ptr [ESP + param_1]
    //         00431e6d     CMP        this,EAX
    //         00431e6f     JNC        LAB_00431e78
    //                              com_q.cpp:371 (7)
    //         00431e71     MOV        this,ESI
    //         00431e73     CALL       RGE_Communications_Queue::TestShowQueue          void TestShowQueue(RGE_Communications_Queue *
    //                               LAB_00431e78                                                 XREF[1]:     00431e6f(j)  
    //                              com_q.cpp:381 (16)
    //         00431e78     MOV        EDX,dword ptr [ESI + 0x114]
    //         00431e7e     MOV        EAX,dword ptr [EDX + EDI*0x1]
    //         00431e81     LEA        this,[EDX + EDI*0x1]
    //         00431e84     CMP        EAX,EBX
    //         00431e86     JNC        LAB_00431e97
    //                              com_q.cpp:382 (9)
    //         00431e88     MOV        EDX,dword ptr [ESP + param_1]
    //         00431e8c     CMP        dword ptr [ECX + this->HighQueueDepth],EDX
    //         00431e8f     JNZ        LAB_00431e97
    //                              com_q.cpp:384 (2)
    //         00431e91     MOV        EBX,EAX
    //                              com_q.cpp:385 (15)
    //         00431e93     MOV        dword ptr [ESP + local_4],EBP
    //                               LAB_00431e97                                                 XREF[4]:     00431e5d(j), 00431e64(j), 
    //                                                                                                         00431e86(j), 00431e8f(j)  
    //         00431e97     MOV        EAX,dword ptr [ESI + 0x4]
    //         00431e9a     INC        EBP
    //         00431e9b     ADD        EDI,0x1c
    //         00431e9e     CMP        EBP,EAX
    //         00431ea0     JBE        LAB_00431e52
    //                              com_q.cpp:393 (9)
    //         00431ea2     MOV        this,dword ptr [ESP + local_4]
    //         00431ea6     CMP        this,-0x1
    //         00431ea9     JNZ        LAB_00431eb5
    //                              com_q.cpp:394 (2)
    //         00431eab     XOR        EAX,EAX
    //                              com_q.cpp:421 (8)
    //         00431ead     POP        EDI
    //         00431eae     POP        ESI
    //         00431eaf     POP        EBP
    //         00431eb0     POP        EBX
    //         00431eb1     POP        this
    //         00431eb2     RET        0x4
    //                               LAB_00431eb5                                                 XREF[1]:     00431ea9(j)  
    //                              com_q.cpp:417 (2)
    //         00431eb5     MOV        EAX,this
    //                              com_q.cpp:421 (74)
    //         00431eb7     POP        EDI
    //         00431eb8     SHL        EAX,0x3
    //         00431ebb     SUB        EAX,this
    //         00431ebd     MOV        this,dword ptr [ESI + 0x114]
    //         00431ec3     SHL        EAX,0x2
    //         00431ec6     MOV        EDX,dword ptr [ECX + EAX*0x1 + this->TBuff[0]]
    //         00431eca     XOR        this,this
    //         00431ecc     MOV        dword ptr [DAT_0062cf38],EDX
    //         00431ed2     MOV        EDX,dword ptr [ESI + 0x114]
    //         00431ed8     MOV        dword ptr [EDX + EAX*0x1 + 0xc],this
    //         00431edc     MOV        ESI,dword ptr [ESI + 0x114]
    //         00431ee2     ADD        ESI,EAX
    //         00431ee4     MOV        dword ptr [ESI],this
    //         00431ee6     MOV        dword ptr [ESI + 0x4],this
    //         00431ee9     MOV        byte ptr [ESI + 0x8],this
    //         00431eec     MOV        dword ptr [ESI + 0x10],this
    //         00431eef     MOV        dword ptr [ESI + 0x14],this
    //         00431ef2     MOV        dword ptr [ESI + 0x18],this
    //         00431ef5     MOV        EAX,[DAT_0062cf38]
    //         00431efa     POP        ESI
    //         00431efb     POP        EBP
    //         00431efc     POP        EBX
    //         00431efd     POP        this
    //         00431efe     RET        0x4
    //         00431f01     ??         90h
    //         00431f02     NOP
    //         00431f03     NOP
    //         00431f04     NOP
    //         00431f05     NOP
    //         00431f06     NOP
    //         00431f07     NOP
    //         00431f08     NOP
    //         00431f09     NOP
    //         00431f0a     NOP
    //         00431f0b     NOP
    //         00431f0c     NOP
    //         00431f0d     NOP
    //         00431f0e     NOP
    //         00431f0f     NOP
    return 0;
}

uchar RGE_Communications_Queue::GetNextSequence(ulong param_1) {
    /* TODO: Stub */
    //                              uchar __thiscall GetNextSequence(RGE_Communications_Queue * this, ul
    //              uchar             AL:1           <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //              ulong             Stack[0x4]:4   param_1                   XREF[1]:     00431f10(R)  
    //                               ?GetNextSequence@RGE_Communications_Queue@@QAEEK@Z           XREF[1]:     NewCommand:004265aa(c)  
    //                               RGE_Communications_Queue::GetNextSequence
    //                              com_q.cpp:424 (14)
    //         00431f10     MOV        EAX,dword ptr [ESP + param_1]
    //         00431f14     MOV        EDX,dword ptr [ECX + this->LastCurrentTurn]
    //         00431f1a     CMP        EAX,EDX
    //         00431f1c     JZ         LAB_00431f30
    //                              com_q.cpp:437 (13)
    //         00431f1e     MOV        dword ptr [ECX + this->LastCurrentTurn],EAX
    //         00431f24     MOV        byte ptr [ECX + this->Sequence],0x1
    //                              com_q.cpp:438 (2)
    //         00431f2b     MOV        AL,0x1
    //                              com_q.cpp:458 (3)
    //         00431f2d     RET        0x4
    //                               LAB_00431f30                                                 XREF[1]:     00431f1c(j)  
    //                              com_q.cpp:442 (16)
    //         00431f30     MOV        DL,byte ptr [ECX + this->Sequence]
    //         00431f36     INC        DL
    //         00431f38     MOV        byte ptr [ECX + this->Sequence],DL
    //         00431f3e     MOV        this,DL
    //                              com_q.cpp:444 (7)
    //         00431f40     CMP        this,0xff
    //         00431f43     SBB        AL,AL
    //         00431f45     AND        EAX,this
    //                              com_q.cpp:458 (3)
    //         00431f47     RET        0x4
    //         00431f4a     ??         90h
    //         00431f4b     NOP
    //         00431f4c     NOP
    //         00431f4d     NOP
    //         00431f4e     NOP
    //         00431f4f     NOP
    return 0;
}

void RGE_Communications_Queue::TestShowQueue() {
    /* TODO: Stub */
    //                              void __thiscall TestShowQueue(RGE_Communications_Queue * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //                               ?TestShowQueue@RGE_Communications_Queue@@QAEXXZ              XREF[1]:     GetNextItemOrdered:00431e73(c)  
    //                               RGE_Communications_Queue::TestShowQueue
    //                              com_q.cpp:462 (1)
    //         00431f50     RET
    //         00431f51     ??         90h
    //         00431f52     NOP
    //         00431f53     NOP
    //         00431f54     NOP
    //         00431f55     NOP
    //         00431f56     NOP
    //         00431f57     NOP
    //         00431f58     NOP
    //         00431f59     NOP
    //         00431f5a     NOP
    //         00431f5b     NOP
    //         00431f5c     NOP
    //         00431f5d     NOP
    //         00431f5e     NOP
    //         00431f5f     NOP
    return;
}

uchar RGE_Communications_Queue::ExpectedNextSequence(ulong param_1, uint param_2) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

int RGE_Communications_Queue::AddItem(ulong param_1, void* param_2, ulong param_3, uint param_4, uchar param_5, int param_6) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

void* RGE_Communications_Queue::GetSpecificItem(uint param_1, ulong param_2, uchar param_3, uint* param_4) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

