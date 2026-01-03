#include "../common.h"
#include "TACTION.h"

TRIBE_Action::TRIBE_Action(int param_1, RGE_Action_Object* param_2, int param_3) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Action(TRIBE_Action * this, int param_1,
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Action *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004d38f7(R)
//              RGE_Action_Obj    Stack[0x8]:4   param_2                   XREF[1]:     004d38fd(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     004d3910(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004d3914(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004d392f(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004d3907(W)
//                               ??0TRIBE_Action@@QAE@HPAVRGE_Action_Object@@H@Z
//                               TRIBE_Action::TRIBE_Action
//                              TACTION.cpp:23 (48)
//         004d38e0     PUSH       -0x1
//         004d38e2     PUSH       FUN_00560218
//         004d38e7     MOV        EAX,FS:[0x0]
//         004d38ed     PUSH       EAX
//         004d38ee     MOV        dword ptr FS:[0x0],ESP
//         004d38f5     PUSH       this
//         004d38f6     PUSH       EBX
//         004d38f7     MOV        EBX,dword ptr [ESP + param_1]
//         004d38fb     PUSH       ESI
//         004d38fc     PUSH       EDI
//         004d38fd     MOV        EDI,dword ptr [ESP + param_2]
//         004d3901     PUSH       0x0
//         004d3903     MOV        ESI,this
//         004d3905     PUSH       EDI
//         004d3906     PUSH       EBX
//         004d3907     MOV        dword ptr [ESP + local_10],ESI
//         004d390b     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, int p
//                              TACTION.cpp:24 (22)
//         004d3910     MOV        EAX,dword ptr [ESP + param_3]
//         004d3914     MOV        dword ptr [ESP + local_4],0x0
//         004d391c     TEST       EAX,EAX
//         004d391e     MOV        dword ptr [ESI],TRIBE_Action::`vftable'          = 004d3950
//         004d3924     JZ         LAB_004d392f
//                              TACTION.cpp:25 (9)
//         004d3926     PUSH       EDI
//         004d3927     PUSH       EBX
//         004d3928     MOV        this,ESI
//         004d392a     CALL       TRIBE_Action::setup                              int setup(TRIBE_Action * this, int param_1, R
//                               LAB_004d392f                                                 XREF[1]:     004d3924(j)
//                              TACTION.cpp:26 (22)
//         004d392f     MOV        this,dword ptr [ESP + local_c]
//         004d3933     MOV        EAX,ESI
//         004d3935     POP        EDI
//         004d3936     POP        ESI
//         004d3937     MOV        dword ptr FS:[0x0],this
//         004d393e     POP        EBX
//         004d393f     ADD        ESP,0x10
//         004d3942     RET        0xc
//         004d3945     ??         90h
//         004d3946     NOP
//         004d3947     NOP
//         004d3948     NOP
//         004d3949     NOP
//         004d394a     NOP
//         004d394b     NOP
//         004d394c     NOP
//         004d394d     NOP
//         004d394e     NOP
//         004d394f     NOP
}

TRIBE_Action::TRIBE_Action(RGE_Action_Object* param_1, int param_2) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Action(TRIBE_Action * this, RGE_Action_Ob
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Action *    ECX:4 (auto)   this
//              RGE_Action_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004d3998(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     004d39aa(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004d39ae(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004d39c8(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004d39a1(W)
//                               ??0TRIBE_Action@@QAE@PAVRGE_Action_Object@@H@Z
//                               TRIBE_Action::TRIBE_Action
//                              TACTION.cpp:31 (42)
//         004d3980     PUSH       -0x1
//         004d3982     PUSH       FUN_00560238
//         004d3987     MOV        EAX,FS:[0x0]
//         004d398d     PUSH       EAX
//         004d398e     MOV        dword ptr FS:[0x0],ESP
//         004d3995     PUSH       this
//         004d3996     PUSH       ESI
//         004d3997     PUSH       EDI
//         004d3998     MOV        EDI,dword ptr [ESP + param_1]
//         004d399c     MOV        ESI,this
//         004d399e     PUSH       0x0
//         004d39a0     PUSH       EDI
//         004d39a1     MOV        dword ptr [ESP + local_10],ESI
//         004d39a5     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, RGE_A
//                              TACTION.cpp:32 (22)
//         004d39aa     MOV        EAX,dword ptr [ESP + param_2]
//         004d39ae     MOV        dword ptr [ESP + local_4],0x0
//         004d39b6     TEST       EAX,EAX
//         004d39b8     MOV        dword ptr [ESI],TRIBE_Action::`vftable'          = 004d3950
//         004d39be     JZ         LAB_004d39c8
//                              TACTION.cpp:33 (8)
//         004d39c0     PUSH       EDI
//         004d39c1     MOV        this,ESI
//         004d39c3     CALL       TRIBE_Action::setup                              int setup(TRIBE_Action * this, RGE_Action_Obj
//                               LAB_004d39c8                                                 XREF[1]:     004d39be(j)
//                              TACTION.cpp:34 (21)
//         004d39c8     MOV        this,dword ptr [ESP + local_c]
//         004d39cc     MOV        EAX,ESI
//         004d39ce     POP        EDI
//         004d39cf     MOV        dword ptr FS:[0x0],this
//         004d39d6     POP        ESI
//         004d39d7     ADD        ESP,0x10
//         004d39da     RET        0x8
//         004d39dd     ??         90h
//         004d39de     NOP
//         004d39df     NOP
}

int TRIBE_Action::setup(int param_1, RGE_Action_Object* param_2) {
    /* TODO: Stub */
//                              int __thiscall setup(TRIBE_Action * this, int param_1, RGE_Action_Ob
//              int               EAX:4          <RETURN>
//              TRIBE_Action *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004d39e4(R)
//              RGE_Action_Obj    Stack[0x8]:4   param_2                   XREF[1]:     004d39e0(R)
//                               ?setup@TRIBE_Action@@UAEHHPAVRGE_Action_Object@@@Z           XREF[2]:     TRIBE_Action:004d392a(c),
//                               TRIBE_Action::setup                                                       005753e8(*)
//                              TACTION.cpp:38 (15)
//         004d39e0     MOV        EAX,dword ptr [ESP + param_2]
//         004d39e4     MOV        EDX,dword ptr [ESP + param_1]
//         004d39e8     PUSH       EAX
//         004d39e9     PUSH       EDX
//         004d39ea     CALL       RGE_Action::setup                                int setup(RGE_Action * this, int param_1, RGE
//                              TACTION.cpp:40 (3)
//         004d39ef     RET        0x8
//         004d39f2     ??         90h
//         004d39f3     NOP
//         004d39f4     NOP
//         004d39f5     NOP
//         004d39f6     NOP
//         004d39f7     NOP
//         004d39f8     NOP
//         004d39f9     NOP
//         004d39fa     NOP
//         004d39fb     NOP
//         004d39fc     NOP
//         004d39fd     NOP
//         004d39fe     NOP
//         004d39ff     NOP
    return 0;
}

int TRIBE_Action::setup(RGE_Action_Object* param_1) {
    /* TODO: Stub */
//                              int __thiscall setup(TRIBE_Action * this, RGE_Action_Object * param_1)
//              int               EAX:4          <RETURN>
//              TRIBE_Action *    ECX:4 (auto)   this
//              RGE_Action_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004d3a00(R)
//                               ?setup@TRIBE_Action@@UAEHPAVRGE_Action_Object@@@Z            XREF[2]:     TRIBE_Action:004d39c3(c),
//                               TRIBE_Action::setup                                                       005753e4(*)
//                              TACTION.cpp:44 (10)
//         004d3a00     MOV        EAX,dword ptr [ESP + param_1]
//         004d3a04     PUSH       EAX
//         004d3a05     CALL       RGE_Action::setup                                int setup(RGE_Action * this, RGE_Action_Objec
//                              TACTION.cpp:46 (3)
//         004d3a0a     RET        0x4
//         004d3a0d     ??         90h
//         004d3a0e     NOP
//         004d3a0f     NOP
    return 0;
}

RGE_Action_List* TRIBE_Action::create_action_list(RGE_Action_Object* param_1) {
    /* TODO: Stub */
//                              RGE_Action_List * __thiscall create_action_list(TRIBE_Action * this,
//              RGE_Action_Lis    EAX:4          <RETURN>
//              TRIBE_Action *    ECX:4 (auto)   this
//              RGE_Action_Obj    Stack[0x4]:4   param_1
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004d3a39(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     004d3a4e(R), 004d3a60(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004d3a33(W)
//                               ?create_action_list@TRIBE_Action@@UAEPAVRGE_Action_List@@PA  XREF[1]:     005753ec(*)
//                               TRIBE_Action::create_action_list
//                              TACTION.cpp:50 (25)
//         004d3a10     PUSH       -0x1
//         004d3a12     PUSH       FUN_0056025b
//         004d3a17     MOV        EAX,FS:[0x0]
//         004d3a1d     PUSH       EAX
//         004d3a1e     MOV        dword ptr FS:[0x0],ESP
//         004d3a25     PUSH       this
//         004d3a26     PUSH       ESI
//         004d3a27     MOV        ESI,this
//                              TACTION.cpp:51 (37)
//         004d3a29     PUSH       0xc
//         004d3a2b     CALL       operator_new                                     void * operator_new(uint param_1)
//         004d3a30     ADD        ESP,0x4
//         004d3a33     MOV        dword ptr [ESP + local_10],EAX
//         004d3a37     TEST       EAX,EAX
//         004d3a39     MOV        dword ptr [ESP + local_4],0x0
//         004d3a41     JZ         LAB_004d3a60
//         004d3a43     MOV        this,dword ptr [ESI + 0x8]
//         004d3a46     PUSH       this
//         004d3a47     MOV        this,EAX
//         004d3a49     CALL       TRIBE_Action_List::TRIBE_Action_List             undefined TRIBE_Action_List(TRIBE_Action_List
//                              TACTION.cpp:52 (38)
//         004d3a4e     MOV        this,dword ptr [ESP + local_c]
//         004d3a52     MOV        dword ptr FS:[0x0],this
//         004d3a59     POP        ESI
//         004d3a5a     ADD        ESP,0x10
//         004d3a5d     RET        0x4
//                               LAB_004d3a60                                                 XREF[1]:     004d3a41(j)
//         004d3a60     MOV        this,dword ptr [ESP + local_c]
//         004d3a64     XOR        EAX,EAX
//         004d3a66     MOV        dword ptr FS:[0x0],this
//         004d3a6d     POP        ESI
//         004d3a6e     ADD        ESP,0x10
//         004d3a71     RET        0x4
//         004d3a74     ??         90h
//         004d3a75     NOP
//         004d3a76     NOP
//         004d3a77     NOP
//         004d3a78     NOP
//         004d3a79     NOP
//         004d3a7a     NOP
//         004d3a7b     NOP
//         004d3a7c     NOP
//         004d3a7d     NOP
//         004d3a7e     NOP
//         004d3a7f     NOP
    return 0;
}

TRIBE_Action::~TRIBE_Action() {
    /* TODO: Stub */
//                              void __thiscall ~TRIBE_Action(TRIBE_Action * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Action *    ECX:4 (auto)   this
//                               ??1TRIBE_Action@@UAE@XZ                                      XREF[1]:     `vector_deleting_destructor':004d3
//                               TRIBE_Action::~TRIBE_Action
//         004d3970     JMP        RGE_Action::~RGE_Action
//         004d3975     ??         90h
//         004d3976     NOP
//         004d3977     NOP
//         004d3978     NOP
//         004d3979     NOP
//         004d397a     NOP
//         004d397b     NOP
//         004d397c     NOP
//         004d397d     NOP
//         004d397e     NOP
//         004d397f     NOP
}

