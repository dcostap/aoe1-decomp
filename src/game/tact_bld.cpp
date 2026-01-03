#include "../common.h"
#include "tact_bld.h"

TRIBE_Action_Build::TRIBE_Action_Build(int param_1, RGE_Action_Object* param_2) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Action_Build(TRIBE_Action_Build * this, i
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Action_B    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004cd1b9(R)
//              RGE_Action_Obj    Stack[0x8]:4   param_2                   XREF[1]:     004cd1b0(R)
//                               ??0TRIBE_Action_Build@@QAE@HPAVRGE_Action_Object@@@Z         XREF[1]:     create_action:004d01d3(c)
//                               TRIBE_Action_Build::TRIBE_Action_Build
//                              tact_bld.cpp:45 (28)
//         004cd1b0     MOV        EAX,dword ptr [ESP + param_2]
//         004cd1b4     PUSH       ESI
//         004cd1b5     MOV        ESI,this
//         004cd1b7     PUSH       0x1
//         004cd1b9     MOV        this,dword ptr [ESP + param_1]
//         004cd1bd     PUSH       EAX
//         004cd1be     PUSH       this
//         004cd1bf     MOV        this,ESI
//         004cd1c1     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, int p
//         004cd1c6     MOV        dword ptr [ESI],TRIBE_Action_Build::`vftable'    = 004cd1e0
//                              language.dll match for 0x65: "1"
//                              tact_bld.cpp:46 (6)
//         004cd1cc     MOV        word ptr [ESI + 0x4],0x65
//                              tact_bld.cpp:47 (6)
//         004cd1d2     MOV        EAX,ESI
//         004cd1d4     POP        ESI
//         004cd1d5     RET        0x8
//         004cd1d8     ??         90h
//         004cd1d9     NOP
//         004cd1da     NOP
//         004cd1db     NOP
//         004cd1dc     NOP
//         004cd1dd     NOP
//         004cd1de     NOP
//         004cd1df     NOP
}

TRIBE_Action_Build::TRIBE_Action_Build(RGE_Action_Object* param_1, RGE_Task* param_2, RGE_Static_Object* param_3) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Action_Build(TRIBE_Action_Build * this, R
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Action_B    ECX:4 (auto)   this
//              RGE_Action_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004cd227(R)
//              RGE_Task *        Stack[0x8]:4   param_2                   XREF[1]:     004cd23f(R)
//              RGE_Static_Obj    Stack[0xc]:4   param_3                   XREF[1]:     004cd23b(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004cd245(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004cd288(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004cd232(W)
//                               ??0TRIBE_Action_Build@@QAE@PAVRGE_Action_Object@@PAVRGE_Tas  XREF[2]:     build:004cb6c2(c),
//                               TRIBE_Action_Build::TRIBE_Action_Build                                    create_task_action:004d063b(c)
//                              tact_bld.cpp:55 (43)
//         004cd210     PUSH       -0x1
//         004cd212     PUSH       FUN_0055fd88
//         004cd217     MOV        EAX,FS:[0x0]
//         004cd21d     PUSH       EAX
//         004cd21e     MOV        dword ptr FS:[0x0],ESP
//         004cd225     PUSH       this
//         004cd226     PUSH       EBX
//         004cd227     MOV        EBX,dword ptr [ESP + param_1]
//         004cd22b     PUSH       ESI
//         004cd22c     PUSH       EDI
//         004cd22d     MOV        ESI,this
//         004cd22f     PUSH       0x1
//         004cd231     PUSH       EBX
//         004cd232     MOV        dword ptr [ESP + local_10],ESI
//         004cd236     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, RGE_A
//                              tact_bld.cpp:58 (51)
//         004cd23b     MOV        EDI,dword ptr [ESP + param_3]
//         004cd23f     MOV        EAX,dword ptr [ESP + param_2]
//         004cd243     TEST       EDI,EDI
//         004cd245     MOV        dword ptr [ESP + local_4],0x0
//         004cd24d     MOV        dword ptr [ESI],TRIBE_Action_Build::`vftable'    = 004cd1e0
//                              language.dll match for 0x65: "1"
//         004cd253     MOV        word ptr [ESI + 0x4],0x65
//         004cd259     MOV        dword ptr [ESI + 0x30],EAX
//         004cd25c     JZ         LAB_004cd26e
//         004cd25e     MOV        this,dword ptr [EBX + 0xc]
//         004cd261     MOV        EDX,dword ptr [EDI + 0xc]
//         004cd264     MOV        AX,word ptr [this->field0_0x0 + 0x4a]
//         004cd268     CMP        AX,word ptr [EDX + 0x4a]
//         004cd26c     JNZ        LAB_004cd288
//                               LAB_004cd26e                                                 XREF[1]:     004cd25c(j)
//                              tact_bld.cpp:60 (8)
//         004cd26e     PUSH       EDI
//         004cd26f     MOV        this,ESI
//         004cd271     CALL       RGE_Action::set_target_obj                       void set_target_obj(RGE_Action * this, RGE_St
//                              tact_bld.cpp:61 (6)
//         004cd276     MOV        this,dword ptr [EDI + 0x38]
//         004cd279     MOV        dword ptr [ESI + 0x20],this
//                              tact_bld.cpp:62 (6)
//         004cd27c     MOV        EDX,dword ptr [EDI + 0x3c]
//         004cd27f     MOV        dword ptr [ESI + 0x24],EDX
//                              tact_bld.cpp:63 (6)
//         004cd282     MOV        EAX,dword ptr [EDI + 0x40]
//         004cd285     MOV        dword ptr [ESI + 0x28],EAX
//                               LAB_004cd288                                                 XREF[1]:     004cd26c(j)
//                              tact_bld.cpp:69 (22)
//         004cd288     MOV        this,dword ptr [ESP + local_c]
//         004cd28c     MOV        EAX,ESI
//         004cd28e     POP        EDI
//         004cd28f     POP        ESI
//         004cd290     MOV        dword ptr FS:[0x0],this
//         004cd297     POP        EBX
//         004cd298     ADD        ESP,0x10
//         004cd29b     RET        0xc
//         004cd29e     ??         90h
//         004cd29f     NOP
}

TRIBE_Action_Build::TRIBE_Action_Build(RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Action_Build(TRIBE_Action_Build * this, R
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Action_B    ECX:4 (auto)   this
//              RGE_Action_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004cd2a0(R)
//              RGE_Task *        Stack[0x8]:4   param_2                   XREF[1]:     004cd2af(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     004cd2b7(R)
//              float             Stack[0x10]:4  param_4                   XREF[1]:     004cd2b3(R)
//              float             Stack[0x14]:4  param_5                   XREF[1]:     004cd2be(R)
//                               ??0TRIBE_Action_Build@@QAE@PAVRGE_Action_Object@@PAVRGE_Tas  XREF[1]:     create_task_action:004d0686(c)
//                               TRIBE_Action_Build::TRIBE_Action_Build
//                              tact_bld.cpp:77 (15)
//         004cd2a0     MOV        EAX,dword ptr [ESP + param_1]
//         004cd2a4     PUSH       ESI
//         004cd2a5     PUSH       0x1
//         004cd2a7     MOV        ESI,this
//         004cd2a9     PUSH       EAX
//         004cd2aa     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, RGE_A
//                              tact_bld.cpp:79 (4)
//         004cd2af     MOV        this,dword ptr [ESP + param_2]
//                              tact_bld.cpp:81 (11)
//         004cd2b3     MOV        EAX,dword ptr [ESP + param_4]
//         004cd2b7     MOV        EDX,dword ptr [ESP + param_3]
//         004cd2bb     MOV        dword ptr [ESI + 0x30],this
//                              tact_bld.cpp:82 (25)
//         004cd2be     MOV        this,dword ptr [ESP + param_5]
//         004cd2c2     MOV        dword ptr [ESI + 0x24],EAX
//         004cd2c5     MOV        dword ptr [ESI],TRIBE_Action_Build::`vftable'    = 004cd1e0
//         004cd2cb     MOV        word ptr [ESI + 0x4],0x65
//         004cd2d1     MOV        dword ptr [ESI + 0x20],EDX
//         004cd2d4     MOV        dword ptr [ESI + 0x28],this
//                              tact_bld.cpp:87 (6)
//         004cd2d7     MOV        EAX,ESI
//         004cd2d9     POP        ESI
//         004cd2da     RET        0x14
//         004cd2dd     ??         90h
//         004cd2de     NOP
//         004cd2df     NOP
}

void TRIBE_Action_Build::first_in_stack(uchar param_1) {
    /* TODO: Stub */
//                              void __thiscall first_in_stack(TRIBE_Action_Build * this, uchar para
//              void              <VOID>         <RETURN>
//              TRIBE_Action_B    ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     004cd2e0(R)
//                               ?first_in_stack@TRIBE_Action_Build@@UAEXE@Z                  XREF[1]:     00574f34(*)
//                               TRIBE_Action_Build::first_in_stack
//                              tact_bld.cpp:93 (8)
//         004cd2e0     MOV        AL,byte ptr [ESP + param_1]
//         004cd2e4     TEST       AL,AL
//         004cd2e6     JZ         LAB_004cd303
//                              tact_bld.cpp:96 (7)
//         004cd2e8     MOV        EAX,dword ptr [ECX + this->field16_0x10]
//         004cd2eb     TEST       EAX,EAX
//         004cd2ed     JZ         LAB_004cd2f9
//                              tact_bld.cpp:97 (4)
//         004cd2ef     MOV        EAX,dword ptr [this->field0_0x0]
//         004cd2f1     PUSH       0x4
//                              tact_bld.cpp:102 (3)
//         004cd2f3     CALL       dword ptr [EAX + 0x5c]
//                              tact_bld.cpp:103 (3)
//         004cd2f6     RET        0x4
//                               LAB_004cd2f9                                                 XREF[1]:     004cd2ed(j)
//                              tact_bld.cpp:99 (7)
//         004cd2f9     MOV        EDX,dword ptr [this->field0_0x0]
//         004cd2fb     PUSH       0x3
//         004cd2fd     CALL       dword ptr [EDX + 0x5c]
//                              tact_bld.cpp:103 (3)
//         004cd300     RET        0x4
//                               LAB_004cd303                                                 XREF[1]:     004cd2e6(j)
//                              tact_bld.cpp:102 (7)
//         004cd303     MOV        EAX,dword ptr [this->field0_0x0]
//         004cd305     PUSH       0x3
//         004cd307     CALL       dword ptr [EAX + 0x5c]
//                              tact_bld.cpp:103 (3)
//         004cd30a     RET        0x4
//         004cd30d     ??         90h
//         004cd30e     NOP
//         004cd30f     NOP
    return;
}

void TRIBE_Action_Build::set_state(uchar param_1) {
    /* TODO: Stub */
//                              void __thiscall set_state(TRIBE_Action_Build * this, uchar param_1)
//              void              <VOID>         <RETURN>
//              TRIBE_Action_B    ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[3]:     004cd331(R), 004cd420(W), 004cd4c6(W)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     004cd426(W), 004cd458(W), 004cd4cc(W), 004cd4f8(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[3]:     004cd490(R), 004cd530(R), 004cd592(R)
//                               ?set_state@TRIBE_Action_Build@@MAEXE@Z                       XREF[1]:     00574f74(*)
//                               TRIBE_Action_Build::set_state
//                              tact_bld.cpp:109 (25)
//         004cd310     MOV        EAX,FS:[0x0]
//         004cd316     PUSH       -0x1
//         004cd318     PUSH       FUN_0055fdb6
//         004cd31d     PUSH       EAX
//         004cd31e     MOV        dword ptr FS:[0x0],ESP
//         004cd325     PUSH       ESI
//         004cd326     MOV        ESI,this
//         004cd328     PUSH       EDI
//                              tact_bld.cpp:118 (8)
//         004cd329     MOV        this,dword ptr [ESI + 0x34]
//         004cd32c     CALL       RGE_Action_List::delete_list                     void delete_list(RGE_Action_List * this)
//                              tact_bld.cpp:120 (7)
//         004cd331     MOV        EAX,dword ptr [ESP + param_1]
//         004cd335     MOV        byte ptr [ESI + 0xc],AL
//                              tact_bld.cpp:122 (22)
//         004cd338     AND        EAX,0xff
//         004cd33d     DEC        EAX
//         004cd33e     CMP        EAX,0xc
//         004cd341     JA         switchD_004cd347::caseD_5
//                               switchD_004cd347::switchD
//         004cd347     JMP        dword ptr [EAX*0x4 + switchD_004cd347::switchd   = 004cd583
//                               switchD_004cd347::caseD_3                                    XREF[2]:     004cd347(j), 004cd5b0(*)
//                              tact_bld.cpp:127 (11)
//         004cd34e     MOV        EAX,dword ptr [ESI + 0x8]
//         004cd351     MOV        this,dword ptr [EAX + 0xc]
//         004cd354     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
//                              tact_bld.cpp:129 (35)
//         004cd359     MOV        this,dword ptr [ESI + 0x8]
//         004cd35c     PUSH       0x0
//         004cd35e     CMP        EAX,0x1
//         004cd361     PUSH       0x0
//         004cd363     MOV        EAX,dword ptr [ECX + this->field4_0x4]
//         004cd366     MOV        EDX,dword ptr [this->field0_0x0]
//         004cd368     PUSH       0x25a
//         004cd36d     JNZ        LAB_004cd3a7
//         004cd36f     PUSH       0x1fa
//         004cd374     PUSH       EAX
//         004cd375     PUSH       EAX
//         004cd376     CALL       dword ptr [EDX + 0x148]
//                              tact_bld.cpp:130 (9)
//         004cd37c     MOV        EAX,dword ptr [ESI]
//         004cd37e     PUSH       0x1
//         004cd380     MOV        this,ESI
//         004cd382     CALL       dword ptr [EAX + 0x5c]
//                              tact_bld.cpp:134 (15)
//         004cd385     MOV        this,dword ptr [ESI + 0x8]
//         004cd388     MOV        EDX,dword ptr [ECX + this->field8_0x8]
//         004cd38b     MOV        EAX,dword ptr [this->field0_0x0]
//         004cd38d     MOV        EDX,dword ptr [EDX + 0x18]
//         004cd390     PUSH       EDX
//         004cd391     CALL       dword ptr [EAX + 0x38]
//                              tact_bld.cpp:198 (19)
//         004cd394     MOV        this,dword ptr [ESP + 0x8]
//         004cd398     MOV        dword ptr FS:[0x0],this
//         004cd39f     POP        EDI
//         004cd3a0     POP        ESI
//         004cd3a1     ADD        ESP,0xc
//         004cd3a4     RET        0x4
//                               LAB_004cd3a7                                                 XREF[1]:     004cd36d(j)
//                              tact_bld.cpp:133 (13)
//         004cd3a7     PUSH       0x202
//         004cd3ac     PUSH       EAX
//         004cd3ad     PUSH       EAX
//         004cd3ae     CALL       dword ptr [EDX + 0x148]
//                              tact_bld.cpp:134 (15)
//         004cd3b4     MOV        this,dword ptr [ESI + 0x8]
//         004cd3b7     MOV        EDX,dword ptr [ECX + this->field8_0x8]
//         004cd3ba     MOV        EAX,dword ptr [this->field0_0x0]
//         004cd3bc     MOV        EDX,dword ptr [EDX + 0x18]
//         004cd3bf     PUSH       EDX
//         004cd3c0     CALL       dword ptr [EAX + 0x38]
//                              tact_bld.cpp:198 (19)
//         004cd3c3     MOV        this,dword ptr [ESP + 0x8]
//         004cd3c7     MOV        dword ptr FS:[0x0],this
//         004cd3ce     POP        EDI
//         004cd3cf     POP        ESI
//         004cd3d0     ADD        ESP,0xc
//         004cd3d3     RET        0x4
//                               switchD_004cd347::caseD_2                                    XREF[2]:     004cd347(j), 004cd5ac(*)
//                              tact_bld.cpp:138 (15)
//         004cd3d6     MOV        this,dword ptr [ESI + 0x8]
//         004cd3d9     MOV        EDX,dword ptr [ECX + this->field8_0x8]
//         004cd3dc     MOV        EAX,dword ptr [this->field0_0x0]
//         004cd3de     MOV        EDX,dword ptr [EDX + 0x18]
//         004cd3e1     PUSH       EDX
//         004cd3e2     CALL       dword ptr [EAX + 0x38]
//                              tact_bld.cpp:139 (9)
//         004cd3e5     MOV        EDI,dword ptr [ESI]
//         004cd3e7     PUSH       0x0
//         004cd3e9     MOV        this,ESI
//         004cd3eb     CALL       dword ptr [EDI + 0x54]
//                              tact_bld.cpp:140 (7)
//         004cd3ee     PUSH       0x0
//         004cd3f0     MOV        this,ESI
//         004cd3f2     CALL       dword ptr [EDI + 0x58]
//                              tact_bld.cpp:141 (8)
//         004cd3f5     MOV        EAX,0xbf800000
//         004cd3fa     MOV        dword ptr [ESI + 0x20],EAX
//                              tact_bld.cpp:142 (3)
//         004cd3fd     MOV        dword ptr [ESI + 0x24],EAX
//                              tact_bld.cpp:143 (3)
//         004cd400     MOV        dword ptr [ESI + 0x28],EAX
//                              tact_bld.cpp:198 (19)
//         004cd403     MOV        this,dword ptr [ESP + 0x8]
//         004cd407     MOV        dword ptr FS:[0x0],this
//         004cd40e     POP        EDI
//         004cd40f     POP        ESI
//         004cd410     ADD        ESP,0xc
//         004cd413     RET        0x4
//                               switchD_004cd347::caseD_b                                    XREF[2]:     004cd347(j), 004cd5d0(*)
//                              tact_bld.cpp:149 (64)
//         004cd416     PUSH       0x44
//         004cd418     CALL       operator_new                                     void * operator_new(uint param_1)
//         004cd41d     ADD        ESP,0x4
//         004cd420     MOV        dword ptr [ESP + param_1],EAX
//         004cd424     TEST       EAX,EAX
//         004cd426     MOV        dword ptr [ESP + local_4],0x0
//         004cd42e     JZ         LAB_004cd454
//         004cd430     MOV        this,dword ptr [ESI + 0x30]
//         004cd433     MOV        EDX,dword ptr [ECX + this->field52_0x34]
//         004cd436     MOV        this,dword ptr [ESI + 0x28]
//         004cd439     PUSH       EDX
//         004cd43a     MOV        EDX,dword ptr [ESI + 0x24]
//         004cd43d     PUSH       0x0
//         004cd43f     PUSH       this
//         004cd440     MOV        this,dword ptr [ESI + 0x20]
//         004cd443     PUSH       EDX
//         004cd444     MOV        EDX,dword ptr [ESI + 0x8]
//         004cd447     PUSH       this
//         004cd448     PUSH       EDX
//         004cd449     MOV        this,EAX
//         004cd44b     CALL       RGE_Action_Move_To::RGE_Action_Move_To           undefined RGE_Action_Move_To(RGE_Action_Move_
//         004cd450     MOV        EDI,EAX
//         004cd452     JMP        LAB_004cd456
//                               LAB_004cd454                                                 XREF[1]:     004cd42e(j)
//         004cd454     XOR        EDI,EDI
//                               LAB_004cd456                                                 XREF[1]:     004cd452(j)
//                              tact_bld.cpp:150 (12)
//         004cd456     TEST       EDI,EDI
//         004cd458     MOV        dword ptr [ESP + local_4],0xffffffff
//         004cd460     JNZ        LAB_004cd47e
//                              tact_bld.cpp:152 (9)
//         004cd462     MOV        EAX,dword ptr [ESI]
//         004cd464     PUSH       0xd
//         004cd466     MOV        this,ESI
//         004cd468     CALL       dword ptr [EAX + 0x5c]
//                              tact_bld.cpp:198 (19)
//         004cd46b     MOV        this,dword ptr [ESP + 0x8]
//         004cd46f     MOV        dword ptr FS:[0x0],this
//         004cd476     POP        EDI
//         004cd477     POP        ESI
//         004cd478     ADD        ESP,0xc
//         004cd47b     RET        0x4
//                               LAB_004cd47e                                                 XREF[1]:     004cd460(j)
//                              tact_bld.cpp:155 (9)
//         004cd47e     PUSH       0x1
//         004cd480     MOV        this,EDI
//         004cd482     CALL       RGE_Action::setSubAction                         void setSubAction(RGE_Action * this, uchar pa
//                              tact_bld.cpp:156 (9)
//         004cd487     MOV        this,dword ptr [ESI + 0x34]
//         004cd48a     PUSH       EDI
//         004cd48b     CALL       RGE_Action_List::add_action                      void add_action(RGE_Action_List * this, RGE_A
//                              tact_bld.cpp:198 (19)
//         004cd490     MOV        this,dword ptr [ESP + local_c]
//         004cd494     MOV        dword ptr FS:[0x0],this
//         004cd49b     POP        EDI
//         004cd49c     POP        ESI
//         004cd49d     ADD        ESP,0xc
//         004cd4a0     RET        0x4
//                               switchD_004cd347::caseD_4                                    XREF[2]:     004cd347(j), 004cd5b4(*)
//                              tact_bld.cpp:161 (7)
//         004cd4a3     MOV        EAX,dword ptr [ESI + 0x10]
//         004cd4a6     TEST       EAX,EAX
//         004cd4a8     JZ         LAB_004cd4bc
//                              tact_bld.cpp:163 (6)
//         004cd4aa     MOV        this,dword ptr [EAX + 0x38]
//         004cd4ad     MOV        dword ptr [ESI + 0x20],this
//                              tact_bld.cpp:164 (6)
//         004cd4b0     MOV        EDX,dword ptr [EAX + 0x3c]
//         004cd4b3     MOV        dword ptr [ESI + 0x24],EDX
//                              tact_bld.cpp:165 (6)
//         004cd4b6     MOV        EAX,dword ptr [EAX + 0x40]
//         004cd4b9     MOV        dword ptr [ESI + 0x28],EAX
//                               LAB_004cd4bc                                                 XREF[1]:     004cd4a8(j)
//                              tact_bld.cpp:169 (58)
//         004cd4bc     PUSH       0x44
//         004cd4be     CALL       operator_new                                     void * operator_new(uint param_1)
//         004cd4c3     ADD        ESP,0x4
//         004cd4c6     MOV        dword ptr [ESP + param_1],EAX
//         004cd4ca     TEST       EAX,EAX
//         004cd4cc     MOV        dword ptr [ESP + local_4],0x1
//         004cd4d4     JZ         LAB_004cd4f4
//         004cd4d6     MOV        EDX,dword ptr [ESI + 0x30]
//         004cd4d9     MOV        this,dword ptr [EDX + 0x34]
//         004cd4dc     MOV        EDX,dword ptr [EDX + 0x24]
//         004cd4df     PUSH       this
//         004cd4e0     MOV        this,dword ptr [ESI + 0x10]
//         004cd4e3     PUSH       EDX
//         004cd4e4     MOV        EDX,dword ptr [ESI + 0x8]
//         004cd4e7     PUSH       this
//         004cd4e8     PUSH       EDX
//         004cd4e9     MOV        this,EAX
//         004cd4eb     CALL       RGE_Action_Move_To::RGE_Action_Move_To           undefined RGE_Action_Move_To(RGE_Action_Move_
//         004cd4f0     MOV        EDI,EAX
//         004cd4f2     JMP        LAB_004cd4f6
//                               LAB_004cd4f4                                                 XREF[1]:     004cd4d4(j)
//         004cd4f4     XOR        EDI,EDI
//                               LAB_004cd4f6                                                 XREF[1]:     004cd4f2(j)
//                              tact_bld.cpp:170 (12)
//         004cd4f6     TEST       EDI,EDI
//         004cd4f8     MOV        dword ptr [ESP + local_4],0xffffffff
//         004cd500     JNZ        LAB_004cd51e
//                              tact_bld.cpp:172 (9)
//         004cd502     MOV        EAX,dword ptr [ESI]
//         004cd504     PUSH       0xd
//         004cd506     MOV        this,ESI
//         004cd508     CALL       dword ptr [EAX + 0x5c]
//                              tact_bld.cpp:198 (19)
//         004cd50b     MOV        this,dword ptr [ESP + 0x8]
//         004cd50f     MOV        dword ptr FS:[0x0],this
//         004cd516     POP        EDI
//         004cd517     POP        ESI
//         004cd518     ADD        ESP,0xc
//         004cd51b     RET        0x4
//                               LAB_004cd51e                                                 XREF[1]:     004cd500(j)
//                              tact_bld.cpp:175 (9)
//         004cd51e     MOV        this,dword ptr [ESI + 0x34]
//         004cd521     PUSH       EDI
//         004cd522     CALL       RGE_Action_List::add_action                      void add_action(RGE_Action_List * this, RGE_A
//                              tact_bld.cpp:176 (9)
//         004cd527     PUSH       0x1
//         004cd529     MOV        this,EDI
//         004cd52b     CALL       RGE_Action::setSubAction                         void setSubAction(RGE_Action * this, uchar pa
//                              tact_bld.cpp:198 (19)
//         004cd530     MOV        this,dword ptr [ESP + local_c]
//         004cd534     MOV        dword ptr FS:[0x0],this
//         004cd53b     POP        EDI
//         004cd53c     POP        ESI
//         004cd53d     ADD        ESP,0xc
//         004cd540     RET        0x4
//                               switchD_004cd347::caseD_6                                    XREF[2]:     004cd347(j), 004cd5bc(*)
//                              tact_bld.cpp:182 (11)
//         004cd543     MOV        this,dword ptr [ESI + 0x8]
//         004cd546     MOV        EAX,dword ptr [ESI + 0x30]
//         004cd549     MOV        EDX,dword ptr [this->field0_0x0]
//         004cd54b     MOV        EAX,dword ptr [EAX + 0x34]
//                              tact_bld.cpp:183 (2)
//         004cd54e     JMP        LAB_004cd58e
//                               switchD_004cd347::caseD_7                                    XREF[2]:     004cd347(j), 004cd5c0(*)
//                              tact_bld.cpp:187 (15)
//         004cd550     MOV        EAX,dword ptr [ESI + 0x30]
//         004cd553     MOV        this,dword ptr [ESI + 0x8]
//         004cd556     MOV        EAX,dword ptr [EAX + 0x38]
//         004cd559     MOV        EDX,dword ptr [this->field0_0x0]
//         004cd55b     PUSH       EAX
//         004cd55c     CALL       dword ptr [EDX + 0x38]
//                              tact_bld.cpp:190 (10)
//         004cd55f     MOV        this,dword ptr [ESI + 0x30]
//         004cd562     MOV        this,dword ptr [this->field0_0x0 + 0x44]
//         004cd565     TEST       this,this
//         004cd567     JZ         switchD_004cd347::caseD_5
//                              tact_bld.cpp:191 (7)
//         004cd569     PUSH       0x1
//         004cd56b     CALL       RGE_Sound::play                                  void play(RGE_Sound * this, int param_1)
//                              tact_bld.cpp:198 (19)
//         004cd570     MOV        this,dword ptr [ESP + 0x8]
//         004cd574     MOV        dword ptr FS:[0x0],this
//         004cd57b     POP        EDI
//         004cd57c     POP        ESI
//         004cd57d     ADD        ESP,0xc
//         004cd580     RET        0x4
//                               switchD_004cd347::caseD_d                                    XREF[3]:     004cd347(j), 004cd5a8(*),
//                               switchD_004cd347::caseD_1                                                 004cd5d8(*)
//                              tact_bld.cpp:196 (15)
//         004cd583     MOV        this,dword ptr [ESI + 0x8]
//         004cd586     MOV        EAX,dword ptr [ECX + this->field8_0x8]
//         004cd589     MOV        EDX,dword ptr [this->field0_0x0]
//         004cd58b     MOV        EAX,dword ptr [EAX + 0x18]
//                               LAB_004cd58e                                                 XREF[1]:     004cd54e(j)
//         004cd58e     PUSH       EAX
//         004cd58f     CALL       dword ptr [EDX + 0x38]
//                               switchD_004cd347::caseD_8                                    XREF[8]:     004cd341(j), 004cd347(j),
//                               switchD_004cd347::caseD_9                                                 004cd567(j), 004cd5b8(*),
//                               switchD_004cd347::caseD_a                                                 004cd5c4(*), 004cd5c8(*),
//                               switchD_004cd347::caseD_c                                                 004cd5cc(*), 004cd5d4(*)
//                               switchD_004cd347::caseD_5
//                              tact_bld.cpp:198 (74)
//         004cd592     MOV        this,dword ptr [ESP + local_c]
//         004cd596     POP        EDI
//         004cd597     MOV        dword ptr FS:[0x0],this
//         004cd59e     POP        ESI
//         004cd59f     ADD        ESP,0xc
//         004cd5a2     RET        0x4
    return;
}

uchar TRIBE_Action_Build::update() {
    /* TODO: Stub */
//                              uchar __thiscall update(TRIBE_Action_Build * this)
//              uchar             AL:1           <RETURN>
//              TRIBE_Action_B    ECX:4 (auto)   this
//              float             Stack[-0x8]:4  work
//                               ?update@TRIBE_Action_Build@@UAEEXZ                           XREF[1]:     00574f40(*)
//                               TRIBE_Action_Build::update
//                              tact_bld.cpp:204 (5)
//         004cd5e0     PUSH       this
//         004cd5e1     PUSH       ESI
//         004cd5e2     MOV        ESI,this
//         004cd5e4     PUSH       EDI
//                              tact_bld.cpp:228 (27)
//         004cd5e5     MOV        EAX,dword ptr [ESI + 0x18]
//         004cd5e8     CMP        EAX,-0x1
//         004cd5eb     JZ         LAB_004cd61b
//         004cd5ed     PUSH       EAX
//         004cd5ee     MOV        EAX,dword ptr [ESI + 0x8]
//         004cd5f1     MOV        this,dword ptr [EAX + 0xc]
//         004cd5f4     MOV        this,dword ptr [ECX + this->field60_0x3c]
//         004cd5f7     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
//         004cd5fc     TEST       EAX,EAX
//         004cd5fe     JNZ        LAB_004cd61b
//                              tact_bld.cpp:229 (8)
//         004cd600     MOV        EDI,dword ptr [ESI]
//         004cd602     PUSH       EAX
//         004cd603     MOV        this,ESI
//         004cd605     CALL       dword ptr [EDI + 0x54]
//                              tact_bld.cpp:230 (6)
//         004cd608     CMP        byte ptr [ESI + 0xc],0x2
//         004cd60c     JZ         LAB_004cd61b
//                              tact_bld.cpp:232 (7)
//         004cd60e     PUSH       0x3
//         004cd610     MOV        this,ESI
//         004cd612     CALL       dword ptr [EDI + 0x5c]
//                              tact_bld.cpp:423 (2)
//         004cd615     XOR        AL,AL
//                              tact_bld.cpp:424 (4)
//         004cd617     POP        EDI
//         004cd618     POP        ESI
//         004cd619     POP        this
//         004cd61a     RET
//                               LAB_004cd61b                                                 XREF[3]:     004cd5eb(j), 004cd5fe(j),
//                                                                                                         004cd60c(j)
//                              tact_bld.cpp:236 (27)
//         004cd61b     MOV        EAX,dword ptr [ESI + 0x1c]
//         004cd61e     CMP        EAX,-0x1
//         004cd621     JZ         LAB_004cd63e
//         004cd623     MOV        EDX,dword ptr [ESI + 0x8]
//         004cd626     PUSH       EAX
//         004cd627     MOV        EAX,dword ptr [EDX + 0xc]
//         004cd62a     MOV        this,dword ptr [EAX + 0x3c]
//         004cd62d     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
//         004cd632     TEST       EAX,EAX
//         004cd634     JNZ        LAB_004cd63e
//                              tact_bld.cpp:237 (8)
//         004cd636     MOV        EDX,dword ptr [ESI]
//         004cd638     PUSH       EAX
//         004cd639     MOV        this,ESI
//         004cd63b     CALL       dword ptr [EDX + 0x58]
//                               LAB_004cd63e                                                 XREF[2]:     004cd621(j), 004cd634(j)
//                              tact_bld.cpp:242 (42)
//         004cd63e     MOV        this,dword ptr [ESI + 0x10]
//         004cd641     TEST       this,this
//         004cd643     JZ         LAB_004cd6ea
//         004cd649     MOV        AL,byte ptr [this->field0_0x0 + 0x48]
//         004cd64c     TEST       AL,AL
//         004cd64e     JZ         LAB_004cd6ea
//         004cd654     FLD        float ptr [ESI + 0x2c]
//         004cd657     FCOMP      float ptr [DAT_00574f78]                         = align(18)
//         004cd65d     FNSTSW     AX
//         004cd65f     TEST       AH,0x40
//         004cd662     JZ         LAB_004cd6ea
//                              tact_bld.cpp:249 (25)
//         004cd668     MOV        EAX,dword ptr [ECX + this->field8_0x8]
//         004cd66b     MOVSX      EDX,word ptr [EAX + 0x26]
//         004cd66f     MOV        dword ptr [ESP + 0x8],EDX
//         004cd673     FILD       dword ptr [ESP + 0x8]
//         004cd677     FCOMP      float ptr [ECX + this->field48_0x30]
//         004cd67a     FNSTSW     AX
//         004cd67c     TEST       AH,0x41
//         004cd67f     JNZ        LAB_004cd6ce
//                              tact_bld.cpp:260 (8)
//         004cd681     MOV        this,dword ptr [ESI + 0x8]
//         004cd684     CALL       RGE_Static_Object::removeAllFromPathingGroup     void removeAllFromPathingGroup(RGE_Static_Obj
//                              tact_bld.cpp:268 (63)
//         004cd689     MOV        EAX,dword ptr [ESI + 0x8]
//         004cd68c     MOV        ESI,dword ptr [ESI + 0x10]
//         004cd68f     PUSH       0x64
//         004cd691     PUSH       0x0
//         004cd693     MOV        EDI,dword ptr [ESI + 0x40]
//         004cd696     PUSH       0x1
//         004cd698     PUSH       0x3f800000
//         004cd69d     PUSH       EDI
//         004cd69e     MOV        EDI,dword ptr [ESI + 0x3c]
//         004cd6a1     MOV        this,dword ptr [EAX + 0xc]
//         004cd6a4     PUSH       EDI
//         004cd6a5     MOV        EDI,dword ptr [ESI + 0x38]
//         004cd6a8     PUSH       EDI
//         004cd6a9     MOV        EDI,dword ptr [ESI + 0xc]
//         004cd6ac     MOV        ESI,dword ptr [ESI + 0x4]
//         004cd6af     MOV        EAX,dword ptr [EAX + 0x4]
//         004cd6b2     MOVSX      EDI,word ptr [EDI + 0x4a]
//         004cd6b6     MOV        EDX,dword ptr [this->field0_0x0]
//         004cd6b8     PUSH       EDI
//         004cd6b9     PUSH       ESI
//         004cd6ba     PUSH       0x2ce
//         004cd6bf     PUSH       EAX
//         004cd6c0     MOVSX      EAX,word ptr [this->field0_0x0 + 0x4a]
//         004cd6c4     PUSH       EAX
//         004cd6c5     CALL       dword ptr [EDX + 0x34]
//                              tact_bld.cpp:423 (2)
//         004cd6c8     XOR        AL,AL
//                              tact_bld.cpp:424 (4)
//         004cd6ca     POP        EDI
//         004cd6cb     POP        ESI
//         004cd6cc     POP        this
//         004cd6cd     RET
//                               LAB_004cd6ce                                                 XREF[1]:     004cd67f(j)
//                              tact_bld.cpp:275 (9)
//         004cd6ce     MOV        EDI,dword ptr [ESI]
//         004cd6d0     PUSH       0x0
//         004cd6d2     MOV        this,ESI
//         004cd6d4     CALL       dword ptr [EDI + 0x54]
//                              tact_bld.cpp:276 (6)
//         004cd6d7     CMP        byte ptr [ESI + 0xc],0x2
//         004cd6db     JZ         LAB_004cd6ea
//                              tact_bld.cpp:278 (7)
//         004cd6dd     PUSH       0x3
//         004cd6df     MOV        this,ESI
//         004cd6e1     CALL       dword ptr [EDI + 0x5c]
//                              tact_bld.cpp:423 (2)
//         004cd6e4     XOR        AL,AL
//                              tact_bld.cpp:424 (4)
//         004cd6e6     POP        EDI
//         004cd6e7     POP        ESI
//         004cd6e8     POP        this
//         004cd6e9     RET
//                               LAB_004cd6ea                                                 XREF[4]:     004cd643(j), 004cd64e(j),
//                                                                                                         004cd662(j), 004cd6db(j)
//                              tact_bld.cpp:283 (30)
//         004cd6ea     XOR        EAX,EAX
//         004cd6ec     MOV        AL,byte ptr [ESI + 0xc]
//         004cd6ef     DEC        EAX
//         004cd6f0     CMP        EAX,0xc
//         004cd6f3     JA         switchD_004cd701::caseD_2
//         004cd6f9     XOR        this,this
//         004cd6fb     MOV        this,byte ptr [EAX + 0x4cd8d0]=>PTR_caseD_2_00
//                               switchD_004cd701::switchD
//         004cd701     JMP        dword ptr [this->field0_0x0*0x4 + switchD_004c   = 004cd87b
//                               switchD_004cd701::caseD_b                                    XREF[2]:     004cd701(j), 004cd8c4(*)
//                              tact_bld.cpp:287 (30)
//         004cd708     MOV        this,dword ptr [ESI + 0x34]
//         004cd70b     MOV        EDX,dword ptr [this->field0_0x0]
//         004cd70d     CALL       dword ptr [EDX + 0xc]
//         004cd710     AND        EAX,0xff
//         004cd715     DEC        EAX
//         004cd716     CMP        EAX,0x4
//         004cd719     JA         switchD_004cd701::caseD_2
//                               switchD_004cd71f::switchD
//         004cd71f     JMP        dword ptr [EAX*0x4 + switchD_004cd71f::switchd   = 004cd726
//                               switchD_004cd71f::caseD_1                                    XREF[4]:     004cd71f(j), 004cd8e0(*),
//                               switchD_004cd71f::caseD_4                                                 004cd8e4(*), 004cd8f0(*)
//                               switchD_004cd71f::caseD_0
//                              tact_bld.cpp:304 (9)
//         004cd726     MOV        EAX,dword ptr [ESI]
//         004cd728     PUSH       0x3
//         004cd72a     MOV        this,ESI
//         004cd72c     CALL       dword ptr [EAX + 0x5c]
//                              tact_bld.cpp:423 (2)
//         004cd72f     XOR        AL,AL
//                              tact_bld.cpp:424 (4)
//         004cd731     POP        EDI
//         004cd732     POP        ESI
//         004cd733     POP        this
//         004cd734     RET
//                               switchD_004cd701::caseD_4                                    XREF[2]:     004cd701(j), 004cd8b8(*)
//                              tact_bld.cpp:327 (30)
//         004cd735     MOV        this,dword ptr [ESI + 0x34]
//         004cd738     MOV        EAX,dword ptr [this->field0_0x0]
//         004cd73a     CALL       dword ptr [EAX + 0xc]
//         004cd73d     AND        EAX,0xff
//         004cd742     DEC        EAX
//         004cd743     CMP        EAX,0x4
//         004cd746     JA         switchD_004cd701::caseD_2
//                               switchD_004cd74c::switchD
//         004cd74c     JMP        dword ptr [EAX*0x4 + switchD_004cd74c::switchd   = 004cd769
//                               switchD_004cd74c::caseD_3                                    XREF[5]:     004cd71f(j), 004cd74c(j),
//                               switchD_004cd74c::caseD_4                                                 004cd8ec(*), 004cd900(*),
//                               switchD_004cd71f::caseD_3                                                 004cd904(*)
//                              tact_bld.cpp:336 (9)
//         004cd753     MOV        EDI,dword ptr [ESI]
//         004cd755     PUSH       0x0
//         004cd757     MOV        this,ESI
//         004cd759     CALL       dword ptr [EDI + 0x54]
//                              tact_bld.cpp:337 (7)
//         004cd75c     PUSH       0xb
//         004cd75e     MOV        this,ESI
//         004cd760     CALL       dword ptr [EDI + 0x5c]
//                              tact_bld.cpp:423 (2)
//         004cd763     XOR        AL,AL
//                              tact_bld.cpp:424 (4)
//         004cd765     POP        EDI
//         004cd766     POP        ESI
//         004cd767     POP        this
//         004cd768     RET
//                               switchD_004cd74c::caseD_1                                    XREF[3]:     004cd74c(j), 004cd8f4(*),
//                               switchD_004cd74c::caseD_0                                                 004cd8f8(*)
//                              tact_bld.cpp:359 (9)
//         004cd769     MOV        EAX,dword ptr [ESI]
//         004cd76b     PUSH       0x6
//         004cd76d     MOV        this,ESI
//         004cd76f     CALL       dword ptr [EAX + 0x5c]
//                              tact_bld.cpp:423 (2)
//         004cd772     XOR        AL,AL
//                              tact_bld.cpp:424 (4)
//         004cd774     POP        EDI
//         004cd775     POP        ESI
//         004cd776     POP        this
//         004cd777     RET
//                               switchD_004cd701::caseD_6                                    XREF[2]:     004cd701(j), 004cd8bc(*)
//                              tact_bld.cpp:367 (27)
//         004cd778     MOV        this,dword ptr [ESI + 0x8]
//         004cd77b     MOV        EAX,dword ptr [ESI + 0x10]
//         004cd77e     PUSH       0x0
//         004cd780     PUSH       0x0
//         004cd782     MOV        EDX,dword ptr [this->field0_0x0]
//         004cd784     PUSH       EAX
//         004cd785     CALL       dword ptr [EDX + 0x1f0]
//         004cd78b     TEST       AL,AL
//         004cd78d     JZ         switchD_004cd701::caseD_2
//                              tact_bld.cpp:368 (9)
//         004cd793     MOV        EDX,dword ptr [ESI]
//         004cd795     PUSH       0x7
//         004cd797     MOV        this,ESI
//         004cd799     CALL       dword ptr [EDX + 0x5c]
//                              tact_bld.cpp:423 (2)
//         004cd79c     XOR        AL,AL
//                              tact_bld.cpp:424 (4)
//         004cd79e     POP        EDI
//         004cd79f     POP        ESI
//         004cd7a0     POP        this
//         004cd7a1     RET
//                               switchD_004cd701::caseD_7                                    XREF[2]:     004cd701(j), 004cd8c0(*)
//                              tact_bld.cpp:377 (39)
//         004cd7a2     FLD        float ptr [ESI + 0x2c]
//         004cd7a5     FCOMP      double ptr [null_00574f80]                       = align(10)
//         004cd7ab     FNSTSW     AX
//         004cd7ad     TEST       AH,0x1
//         004cd7b0     JZ         LAB_004cd7fd
//         004cd7b2     MOV        EAX,dword ptr [ESI + 0x10]
//         004cd7b5     TEST       EAX,EAX
//         004cd7b7     JZ         LAB_004cd7fd
//         004cd7b9     FLD        float ptr [EAX + 0x44]
//         004cd7bc     FCOMP      float ptr [DAT_00574f78]                         = align(18)
//         004cd7c2     FNSTSW     AX
//         004cd7c4     TEST       AH,0x41
//         004cd7c7     JNZ        LAB_004cd7fd
//                              tact_bld.cpp:381 (8)
//         004cd7c9     MOV        this,dword ptr [ESI + 0x8]
//         004cd7cc     CALL       RGE_Static_Object::removeAllFromPathingGroup     void removeAllFromPathingGroup(RGE_Static_Obj
//                              tact_bld.cpp:382 (13)
//         004cd7d1     MOV        this,dword ptr [ESI + 0x8]
//         004cd7d4     PUSH       0x1
//         004cd7d6     MOV        EAX,dword ptr [this->field0_0x0]
//         004cd7d8     CALL       dword ptr [EAX + 0x12c]
//                              tact_bld.cpp:383 (25)
//         004cd7de     MOV        this,dword ptr [ESI + 0x8]
//         004cd7e1     MOV        ESI,dword ptr [ESI + 0x10]
//         004cd7e4     PUSH       0x0
//         004cd7e6     MOV        EAX,dword ptr [ESI + 0x3c]
//         004cd7e9     MOV        EDX,dword ptr [this->field0_0x0]
//         004cd7eb     PUSH       EAX
//         004cd7ec     MOV        EAX,dword ptr [ESI + 0x38]
//         004cd7ef     PUSH       EAX
//         004cd7f0     PUSH       ESI
//         004cd7f1     CALL       dword ptr [EDX + 0x98]
//                              tact_bld.cpp:423 (2)
//         004cd7f7     XOR        AL,AL
//                              tact_bld.cpp:424 (4)
//         004cd7f9     POP        EDI
//         004cd7fa     POP        ESI
//         004cd7fb     POP        this
//         004cd7fc     RET
//                               LAB_004cd7fd                                                 XREF[3]:     004cd7b0(j), 004cd7b7(j),
//                                                                                                         004cd7c7(j)
//                              tact_bld.cpp:388 (16)
//         004cd7fd     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004cd803     MOV        EAX,dword ptr [this->field0_0x0 + 0x9a8]
//         004cd809     TEST       EAX,EAX
//         004cd80b     JZ         LAB_004cd817
//                              tact_bld.cpp:389 (8)
//         004cd80d     MOV        dword ptr [ESP + 0x8],0x447a0000
//                              tact_bld.cpp:390 (2)
//         004cd815     JMP        LAB_004cd839
//                               LAB_004cd817                                                 XREF[1]:     004cd80b(j)
//                              tact_bld.cpp:392 (34)
//         004cd817     MOV        EAX,dword ptr [ESI + 0x8]
//         004cd81a     MOV        EDX,dword ptr [ESI + 0x30]
//         004cd81d     MOV        this,dword ptr [EAX + 0x8]
//         004cd820     FLD        float ptr [EDX + 0x1c]
//         004cd823     MOV        EDX,dword ptr [EAX + 0xc]
//         004cd826     FMUL       float ptr [this->field0_0x0 + 0xe4]
//         004cd82c     MOV        EAX,dword ptr [EDX + 0x3c]
//         004cd82f     FMUL       float ptr [EAX + 0x84]
//         004cd835     FSTP       float ptr [ESP + 0x8]
//                               LAB_004cd839                                                 XREF[1]:     004cd815(j)
//                              tact_bld.cpp:394 (21)
//         004cd839     MOV        this,dword ptr [ESI + 0x10]
//         004cd83c     TEST       this,this
//         004cd83e     JZ         LAB_004cd84e
//         004cd840     MOV        EDX,dword ptr [ESP + 0x8]
//         004cd844     PUSH       EDX
//         004cd845     CALL       TRIBE_Building_Object::build                     uchar build(TRIBE_Building_Object * this, flo
//         004cd84a     TEST       AL,AL
//         004cd84c     JZ         switchD_004cd701::caseD_2
//                               LAB_004cd84e                                                 XREF[1]:     004cd83e(j)
//                              tact_bld.cpp:398 (17)
//         004cd84e     MOV        EAX,dword ptr [ESI + 0x10]
//         004cd851     TEST       EAX,EAX
//         004cd853     JZ         switchD_004cd71f::caseD_2
//         004cd855     MOV        EAX,dword ptr [EAX + 0x8]
//         004cd858     CMP        word ptr [EAX + 0x10],0x32
//         004cd85d     JNZ        switchD_004cd71f::caseD_2
//                              tact_bld.cpp:400 (7)
//         004cd85f     MOV        dword ptr [ESI + 0x2c],0xbf800000
//                              tact_bld.cpp:423 (2)
//         004cd866     XOR        AL,AL
//                              tact_bld.cpp:424 (4)
//         004cd868     POP        EDI
//         004cd869     POP        ESI
//         004cd86a     POP        this
//         004cd86b     RET
//                               switchD_004cd74c::caseD_2                                    XREF[6]:     004cd71f(j), 004cd74c(j),
//                               switchD_004cd71f::caseD_2                                                 004cd853(j), 004cd85d(j),
//                                                                                                         004cd8e8(*), 004cd8fc(*)
//                              tact_bld.cpp:403 (9)
//         004cd86c     MOV        EDX,dword ptr [ESI]
//         004cd86e     PUSH       0x3
//         004cd870     MOV        this,ESI
//         004cd872     CALL       dword ptr [EDX + 0x5c]
//                              tact_bld.cpp:423 (2)
//         004cd875     XOR        AL,AL
//                              tact_bld.cpp:424 (4)
//         004cd877     POP        EDI
//         004cd878     POP        ESI
//         004cd879     POP        this
//         004cd87a     RET
//                               switchD_004cd701::caseD_1                                    XREF[2]:     004cd701(j), 004cd8b4(*)
//                              tact_bld.cpp:413 (2)
//         004cd87b     MOV        AL,0x1
//                              tact_bld.cpp:424 (4)
//         004cd87d     POP        EDI
//         004cd87e     POP        ESI
//         004cd87f     POP        this
//         004cd880     RET
//                               switchD_004cd701::caseD_d                                    XREF[2]:     004cd701(j), 004cd8c8(*)
//                              tact_bld.cpp:418 (30)
//         004cd881     MOV        this,dword ptr [ESI + 0x8]
//         004cd884     PUSH       0x0
//         004cd886     PUSH       0x0
//         004cd888     PUSH       0x25a
//         004cd88d     MOV        EAX,dword ptr [ECX + this->field4_0x4]
//         004cd890     MOV        EDX,dword ptr [this->field0_0x0]
//         004cd892     PUSH       0x1f9
//         004cd897     PUSH       EAX
//         004cd898     PUSH       EAX
//         004cd899     CALL       dword ptr [EDX + 0x148]
//                              tact_bld.cpp:419 (9)
//         004cd89f     MOV        EAX,dword ptr [ESI]
//         004cd8a1     PUSH       0x2
//         004cd8a3     MOV        this,ESI
//         004cd8a5     CALL       dword ptr [EAX + 0x5c]
//                              tact_bld.cpp:420 (2)
//         004cd8a8     MOV        AL,0x3
//                              tact_bld.cpp:424 (94)
//         004cd8aa     POP        EDI
//         004cd8ab     POP        ESI
//         004cd8ac     POP        this
//         004cd8ad     RET
//                               switchD_004cd701::caseD_3                                    XREF[7]:     004cd6f3(j), 004cd701(j),
//                               switchD_004cd701::caseD_5                                                 004cd719(j), 004cd746(j),
//                               switchD_004cd701::caseD_8                                                 004cd78d(j), 004cd84c(j),
//                               switchD_004cd701::caseD_9                                                 004cd8cc(*)
//                               switchD_004cd701::caseD_a
//                               switchD_004cd701::caseD_c
//                               switchD_004cd71f::default
//                               switchD_004cd74c::default
//                               switchD_004cd701::caseD_2
//         004cd8ae     POP        EDI
//         004cd8af     XOR        AL,AL
//         004cd8b1     POP        ESI
//         004cd8b2     POP        this
//         004cd8b3     RET
//                              Symbol Ref: No symbol: NONAME
//                               switchD_004cd701::switchdataD_004cd8b4                       XREF[1]:     update:004cd701(*)
//         004cd8b4     addr       switchD_004cd701::caseD_1
//         004cd8b8     addr       switchD_004cd701::caseD_4
//         004cd8bc     addr       switchD_004cd701::caseD_6
//         004cd8c0     addr       switchD_004cd701::caseD_7
//         004cd8c4     addr       switchD_004cd701::caseD_b
//         004cd8c8     addr       switchD_004cd701::caseD_d
//                               PTR_caseD_2_004cd8cc+3                                       XREF[0,1]:   update:004cd6fb(*)
//         004cd8cc     addr       switchD_004cd701::caseD_2
//                              Symbol Ref: No symbol: NONAME
//                               switchD_004cd701::switchdataD_004cd8d0
//         004cd8d0     db         0h
//         004cd8d1     db         6h
//         004cd8d2     db         6h
//         004cd8d3     db         1h
//         004cd8d4     db         6h
//         004cd8d5     db         2h
//         004cd8d6     db         3h
//         004cd8d7     db         6h
//         004cd8d8     db         6h
//         004cd8d9     db         6h
//         004cd8da     db         4h
//         004cd8db     db         6h
//         004cd8dc     db         5h
//         004cd8dd     ??         90h
//         004cd8de     ??         8Bh
//         004cd8df     ??         FFh
//                              Symbol Ref: No symbol: NONAME
//                               switchD_004cd71f::switchdataD_004cd8e0                       XREF[1]:     update:004cd71f(*)
//         004cd8e0     addr       switchD_004cd71f::caseD_0
//         004cd8e4     addr       switchD_004cd71f::caseD_0
//         004cd8e8     addr       switchD_004cd71f::caseD_2
//         004cd8ec     addr       switchD_004cd71f::caseD_3
//         004cd8f0     addr       switchD_004cd71f::caseD_0
//                              Symbol Ref: No symbol: NONAME
//                               switchD_004cd74c::switchdataD_004cd8f4                       XREF[1]:     update:004cd74c(*)
//         004cd8f4     addr       switchD_004cd74c::caseD_0
//         004cd8f8     addr       switchD_004cd74c::caseD_0
//         004cd8fc     addr       switchD_004cd71f::caseD_2
//         004cd900     addr       switchD_004cd71f::caseD_3
//         004cd904     addr       switchD_004cd71f::caseD_3
//         004cd908     ??         90h
//         004cd909     ??         90h
//         004cd90a     ??         90h
//         004cd90b     ??         90h
//         004cd90c     ??         90h
//         004cd90d     ??         90h
//         004cd90e     ??         90h
//         004cd90f     ??         90h
    return 0;
}

int TRIBE_Action_Build::stop() {
    /* TODO: Stub */
//                              int __thiscall stop(TRIBE_Action_Build * this)
//              int               EAX:4          <RETURN>
//              TRIBE_Action_B    ECX:4 (auto)   this
//                               ?stop@TRIBE_Action_Build@@UAEHXZ                             XREF[1]:     00574f44(*)
//                               TRIBE_Action_Build::stop
//                              tact_bld.cpp:430 (7)
//         004cd910     MOV        EAX,dword ptr [this->field0_0x0]
//         004cd912     PUSH       0x2
//         004cd914     CALL       dword ptr [EAX + 0x5c]
//                              tact_bld.cpp:432 (5)
//         004cd917     MOV        EAX,0x1
//                              tact_bld.cpp:433 (1)
//         004cd91c     RET
//         004cd91d     ??         90h
//         004cd91e     NOP
//         004cd91f     NOP
    return 0;
}

int TRIBE_Action_Build::move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    /* TODO: Stub */
//                              int __thiscall move_to(TRIBE_Action_Build * this, RGE_Static_Object
//              int               EAX:4          <RETURN>
//              TRIBE_Action_B    ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1
//              float             Stack[0x8]:4   param_2                   XREF[1]:     004cd920(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     004cd92b(R)
//              float             Stack[0x10]:4  param_4                   XREF[1]:     004cd924(R)
//                               ?move_to@TRIBE_Action_Build@@UAEHPAVRGE_Static_Object@@MMM@Z XREF[1]:     00574f48(*)
//                               TRIBE_Action_Build::move_to
//                              tact_bld.cpp:440 (4)
//         004cd920     MOV        EAX,dword ptr [ESP + param_2]
//                              tact_bld.cpp:443 (12)
//         004cd924     MOV        EDX,dword ptr [ESP + param_4]
//         004cd928     PUSH       ESI
//         004cd929     MOV        ESI,this
//         004cd92b     MOV        this,dword ptr [ESP + param_3]
//         004cd92f     PUSH       EDI
//                              tact_bld.cpp:444 (18)
//         004cd930     MOV        EDI,dword ptr [ESI]
//         004cd932     MOV        dword ptr [ESI + 0x24],this
//         004cd935     PUSH       0x0
//         004cd937     MOV        this,ESI
//         004cd939     MOV        dword ptr [ESI + 0x20],EAX
//         004cd93c     MOV        dword ptr [ESI + 0x28],EDX
//         004cd93f     CALL       dword ptr [EDI + 0x54]
//                              tact_bld.cpp:445 (7)
//         004cd942     PUSH       0xb
//         004cd944     MOV        this,ESI
//         004cd946     CALL       dword ptr [EDI + 0x5c]
//                              tact_bld.cpp:447 (10)
//         004cd949     POP        EDI
//         004cd94a     MOV        EAX,0x1
//         004cd94f     POP        ESI
//         004cd950     RET        0x10
//         004cd953     ??         90h
//         004cd954     NOP
//         004cd955     NOP
//         004cd956     NOP
//         004cd957     NOP
//         004cd958     NOP
//         004cd959     NOP
//         004cd95a     NOP
//         004cd95b     NOP
//         004cd95c     NOP
//         004cd95d     NOP
//         004cd95e     NOP
//         004cd95f     NOP
    return 0;
}

int TRIBE_Action_Build::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    /* TODO: Stub */
//                              int __thiscall work(TRIBE_Action_Build * this, RGE_Static_Object * p
//              int               EAX:4          <RETURN>
//              TRIBE_Action_B    ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004cd960(R)
//              float             Stack[0x8]:4   param_2                   XREF[1]:     004cd9ae(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     004cd9b2(R)
//              float             Stack[0x10]:4  param_4                   XREF[1]:     004cd9aa(R)
//                               ?work@TRIBE_Action_Build@@UAEHPAVRGE_Static_Object@@MMM@Z    XREF[1]:     00574f4c(*)
//                               TRIBE_Action_Build::work
//                              tact_bld.cpp:454 (31)
//         004cd960     MOV        EAX,dword ptr [ESP + param_1]
//         004cd964     PUSH       ESI
//         004cd965     TEST       EAX,EAX
//         004cd967     PUSH       EDI
//         004cd968     MOV        ESI,this
//         004cd96a     JZ         LAB_004cd9aa
//         004cd96c     MOV        EDX,dword ptr [ESI + 0x8]
//         004cd96f     MOV        this,dword ptr [EAX + 0xc]
//         004cd972     MOV        EDX,dword ptr [EDX + 0xc]
//         004cd975     MOV        this,word ptr [this->field0_0x0 + 0x4a]
//         004cd979     CMP        this,word ptr [EDX + 0x4a]
//         004cd97d     JNZ        LAB_004cd9aa
//                              tact_bld.cpp:468 (16)
//         004cd97f     CMP        EAX,dword ptr [ESI + 0x10]
//         004cd982     JNZ        LAB_004cd991
//         004cd984     MOV        this,byte ptr [ESI + 0xc]
//         004cd987     CMP        this,0x4
//         004cd98a     JZ         LAB_004cd9cf
//         004cd98c     CMP        this,0x6
//                              tact_bld.cpp:469 (2)
//         004cd98f     JZ         LAB_004cd9cf
//                               LAB_004cd991                                                 XREF[1]:     004cd982(j)
//                              tact_bld.cpp:471 (8)
//         004cd991     MOV        EDI,dword ptr [ESI]
//         004cd993     PUSH       EAX
//         004cd994     MOV        this,ESI
//         004cd996     CALL       dword ptr [EDI + 0x54]
//                              tact_bld.cpp:472 (2)
//         004cd999     PUSH       0x4
//                              tact_bld.cpp:480 (5)
//         004cd99b     MOV        this,ESI
//         004cd99d     CALL       dword ptr [EDI + 0x5c]
//                              tact_bld.cpp:482 (5)
//         004cd9a0     MOV        EAX,0x1
//                              tact_bld.cpp:483 (5)
//         004cd9a5     POP        EDI
//         004cd9a6     POP        ESI
//         004cd9a7     RET        0x10
//                               LAB_004cd9aa                                                 XREF[2]:     004cd96a(j), 004cd97d(j)
//                              tact_bld.cpp:478 (12)
//         004cd9aa     MOV        this,dword ptr [ESP + param_4]
//         004cd9ae     MOV        EDX,dword ptr [ESP + param_2]
//         004cd9b2     MOV        EAX,dword ptr [ESP + param_3]
//                              tact_bld.cpp:479 (18)
//         004cd9b6     MOV        EDI,dword ptr [ESI]
//         004cd9b8     MOV        dword ptr [ESI + 0x28],this
//         004cd9bb     PUSH       0x0
//         004cd9bd     MOV        this,ESI
//         004cd9bf     MOV        dword ptr [ESI + 0x20],EDX
//         004cd9c2     MOV        dword ptr [ESI + 0x24],EAX
//         004cd9c5     CALL       dword ptr [EDI + 0x54]
//                              tact_bld.cpp:480 (7)
//         004cd9c8     PUSH       0xb
//         004cd9ca     MOV        this,ESI
//         004cd9cc     CALL       dword ptr [EDI + 0x5c]
//                               LAB_004cd9cf                                                 XREF[2]:     004cd98a(j), 004cd98f(j)
//                              tact_bld.cpp:483 (10)
//         004cd9cf     POP        EDI
//         004cd9d0     MOV        EAX,0x1
//         004cd9d5     POP        ESI
//         004cd9d6     RET        0x10
//         004cd9d9     ??         90h
//         004cd9da     NOP
//         004cd9db     NOP
//         004cd9dc     NOP
//         004cd9dd     NOP
//         004cd9de     NOP
//         004cd9df     NOP
    return 0;
}

TRIBE_Action_Build::~TRIBE_Action_Build() {
    /* TODO: Stub */
//                              void __thiscall ~TRIBE_Action_Build(TRIBE_Action_Build * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Action_B    ECX:4 (auto)   this
//                               ??1TRIBE_Action_Build@@UAE@XZ                                XREF[1]:     `vector_deleting_destructor':004cd
//                               TRIBE_Action_Build::~TRIBE_Action_Build
//         004cd200     JMP        RGE_Action::~RGE_Action
//         004cd205     ??         90h
//         004cd206     NOP
//         004cd207     NOP
//         004cd208     NOP
//         004cd209     NOP
//         004cd20a     NOP
//         004cd20b     NOP
//         004cd20c     NOP
//         004cd20d     NOP
//         004cd20e     NOP
//         004cd20f     NOP
}

