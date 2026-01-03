#include "../common.h"
#include "tact_hea.h"

TRIBE_Action_Heal::TRIBE_Action_Heal(int param_1, RGE_Action_Object* param_2) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Action_Heal(TRIBE_Action_Heal * this, int
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Action_H    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004ce939(R)
//              RGE_Action_Obj    Stack[0x8]:4   param_2                   XREF[1]:     004ce930(R)
//                               ??0TRIBE_Action_Heal@@QAE@HPAVRGE_Action_Object@@@Z          XREF[1]:     create_action:004d02d3(c)
//                               TRIBE_Action_Heal::TRIBE_Action_Heal
//                              tact_hea.cpp:41 (28)
//         004ce930     MOV        EAX,dword ptr [ESP + param_2]
//         004ce934     PUSH       ESI
//         004ce935     MOV        ESI,this
//         004ce937     PUSH       0x1
//         004ce939     MOV        this,dword ptr [ESP + param_1]
//         004ce93d     PUSH       EAX
//         004ce93e     PUSH       this
//         004ce93f     MOV        this,ESI
//         004ce941     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, int p
//         004ce946     MOV        dword ptr [ESI],TRIBE_Action_Heal::`vftable'     = 004ce960
//                              tact_hea.cpp:42 (6)
//         004ce94c     MOV        word ptr [ESI + 0x4],0x69
//                              tact_hea.cpp:43 (6)
//         004ce952     MOV        EAX,ESI
//         004ce954     POP        ESI
//         004ce955     RET        0x8
//         004ce958     ??         90h
//         004ce959     NOP
//         004ce95a     NOP
//         004ce95b     NOP
//         004ce95c     NOP
//         004ce95d     NOP
//         004ce95e     NOP
//         004ce95f     NOP
}

TRIBE_Action_Heal::TRIBE_Action_Heal(RGE_Action_Object* param_1, RGE_Task* param_2, RGE_Static_Object* param_3) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Action_Heal(TRIBE_Action_Heal * this, RGE
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Action_H    ECX:4 (auto)   this
//              RGE_Action_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004ce9a6(R)
//              RGE_Task *        Stack[0x8]:4   param_2                   XREF[1]:     004ce9ba(R)
//              RGE_Static_Obj    Stack[0xc]:4   param_3                   XREF[1]:     004ce9be(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004ce9c8(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004ce9f3(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004ce9b1(W)
//                               ??0TRIBE_Action_Heal@@QAE@PAVRGE_Action_Object@@PAVRGE_Task  XREF[2]:     heal:004cb402(c),
//                               TRIBE_Action_Heal::TRIBE_Action_Heal                                      create_task_action:004d075f(c)
//                              tact_hea.cpp:51 (42)
//         004ce990     PUSH       -0x1
//         004ce992     PUSH       FUN_0055fe68
//         004ce997     MOV        EAX,FS:[0x0]
//         004ce99d     PUSH       EAX
//         004ce99e     MOV        dword ptr FS:[0x0],ESP
//         004ce9a5     PUSH       this
//         004ce9a6     MOV        EAX,dword ptr [ESP + param_1]
//         004ce9aa     PUSH       ESI
//         004ce9ab     PUSH       EDI
//         004ce9ac     MOV        ESI,this
//         004ce9ae     PUSH       0x1
//         004ce9b0     PUSH       EAX
//         004ce9b1     MOV        dword ptr [ESP + local_10],ESI
//         004ce9b5     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, RGE_A
//                              tact_hea.cpp:54 (4)
//         004ce9ba     MOV        this,dword ptr [ESP + param_2]
//                              tact_hea.cpp:55 (35)
//         004ce9be     MOV        EDI,dword ptr [ESP + param_3]
//         004ce9c2     MOV        dword ptr [ESI + 0x30],this
//         004ce9c5     PUSH       EDI
//         004ce9c6     MOV        this,ESI
//         004ce9c8     MOV        dword ptr [ESP + local_4],0x0
//         004ce9d0     MOV        dword ptr [ESI],TRIBE_Action_Heal::`vftable'     = 004ce960
//         004ce9d6     MOV        word ptr [ESI + 0x4],0x69
//         004ce9dc     CALL       RGE_Action::set_target_obj                       void set_target_obj(RGE_Action * this, RGE_St
//                              tact_hea.cpp:56 (6)
//         004ce9e1     MOV        EDX,dword ptr [EDI + 0x38]
//         004ce9e4     MOV        dword ptr [ESI + 0x20],EDX
//                              tact_hea.cpp:57 (6)
//         004ce9e7     MOV        EAX,dword ptr [EDI + 0x3c]
//         004ce9ea     MOV        dword ptr [ESI + 0x24],EAX
//                              tact_hea.cpp:58 (6)
//         004ce9ed     MOV        this,dword ptr [EDI + 0x40]
//         004ce9f0     MOV        dword ptr [ESI + 0x28],this
//                              tact_hea.cpp:59 (21)
//         004ce9f3     MOV        this,dword ptr [ESP + local_c]
//         004ce9f7     MOV        EAX,ESI
//         004ce9f9     POP        EDI
//         004ce9fa     MOV        dword ptr FS:[0x0],this
//         004cea01     POP        ESI
//         004cea02     ADD        ESP,0x10
//         004cea05     RET        0xc
//         004cea08     ??         90h
//         004cea09     NOP
//         004cea0a     NOP
//         004cea0b     NOP
//         004cea0c     NOP
//         004cea0d     NOP
//         004cea0e     NOP
//         004cea0f     NOP
}

TRIBE_Action_Heal::TRIBE_Action_Heal(RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Action_Heal(TRIBE_Action_Heal * this, RGE
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Action_H    ECX:4 (auto)   this
//              RGE_Action_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004cea10(R)
//              RGE_Task *        Stack[0x8]:4   param_2                   XREF[1]:     004cea1f(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     004cea27(R)
//              float             Stack[0x10]:4  param_4                   XREF[1]:     004cea23(R)
//              float             Stack[0x14]:4  param_5                   XREF[1]:     004cea2e(R)
//                               ??0TRIBE_Action_Heal@@QAE@PAVRGE_Action_Object@@PAVRGE_Task  XREF[1]:     create_task_action:004d07aa(c)
//                               TRIBE_Action_Heal::TRIBE_Action_Heal
//                              tact_hea.cpp:67 (15)
//         004cea10     MOV        EAX,dword ptr [ESP + param_1]
//         004cea14     PUSH       ESI
//         004cea15     PUSH       0x1
//         004cea17     MOV        ESI,this
//         004cea19     PUSH       EAX
//         004cea1a     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, RGE_A
//                              tact_hea.cpp:70 (4)
//         004cea1f     MOV        this,dword ptr [ESP + param_2]
//                              tact_hea.cpp:72 (11)
//         004cea23     MOV        EAX,dword ptr [ESP + param_4]
//         004cea27     MOV        EDX,dword ptr [ESP + param_3]
//         004cea2b     MOV        dword ptr [ESI + 0x30],this
//                              tact_hea.cpp:73 (25)
//         004cea2e     MOV        this,dword ptr [ESP + param_5]
//         004cea32     MOV        dword ptr [ESI + 0x24],EAX
//         004cea35     MOV        dword ptr [ESI],TRIBE_Action_Heal::`vftable'     = 004ce960
//         004cea3b     MOV        word ptr [ESI + 0x4],0x69
//         004cea41     MOV        dword ptr [ESI + 0x20],EDX
//         004cea44     MOV        dword ptr [ESI + 0x28],this
//                              tact_hea.cpp:74 (6)
//         004cea47     MOV        EAX,ESI
//         004cea49     POP        ESI
//         004cea4a     RET        0x14
//         004cea4d     ??         90h
//         004cea4e     NOP
//         004cea4f     NOP
}

void TRIBE_Action_Heal::first_in_stack(uchar param_1) {
    /* TODO: Stub */
//                              void __thiscall first_in_stack(TRIBE_Action_Heal * this, uchar param
//              void              <VOID>         <RETURN>
//              TRIBE_Action_H    ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1
//                               ?first_in_stack@TRIBE_Action_Heal@@UAEXE@Z                   XREF[1]:     0057509c(*)
//                               TRIBE_Action_Heal::first_in_stack
//                              tact_hea.cpp:80 (7)
//         004cea50     MOV        EAX,dword ptr [ECX + this->field16_0x10]
//         004cea53     TEST       EAX,EAX
//         004cea55     JZ         LAB_004cea80
//                              tact_hea.cpp:86 (31)
//         004cea57     MOV        EAX,dword ptr [EAX + 0x8]
//         004cea5a     MOV        AX,word ptr [EAX + 0x14]
//         004cea5e     CMP        AX,0x15
//         004cea62     JZ         LAB_004cea87
//         004cea64     CMP        AX,0x2
//         004cea68     JZ         LAB_004cea87
//         004cea6a     CMP        AX,0x14
//         004cea6e     JZ         LAB_004cea87
//         004cea70     CMP        AX,0x16
//         004cea74     JZ         LAB_004cea87
//                              tact_hea.cpp:88 (7)
//         004cea76     MOV        EDX,dword ptr [this->field0_0x0]
//         004cea78     PUSH       0x4
//         004cea7a     CALL       dword ptr [EDX + 0x5c]
//                              tact_hea.cpp:92 (3)
//         004cea7d     RET        0x4
//                               LAB_004cea80                                                 XREF[1]:     004cea55(j)
//                              tact_hea.cpp:91 (7)
//         004cea80     MOV        EAX,dword ptr [this->field0_0x0]
//         004cea82     PUSH       0x3
//         004cea84     CALL       dword ptr [EAX + 0x5c]
//                               LAB_004cea87                                                 XREF[4]:     004cea62(j), 004cea68(j),
//                                                                                                         004cea6e(j), 004cea74(j)
//                              tact_hea.cpp:92 (3)
//         004cea87     RET        0x4
//         004cea8a     ??         90h
//         004cea8b     NOP
//         004cea8c     NOP
//         004cea8d     NOP
//         004cea8e     NOP
//         004cea8f     NOP
    return;
}

void TRIBE_Action_Heal::set_state(uchar param_1) {
    /* TODO: Stub */
//                              void __thiscall set_state(TRIBE_Action_Heal * this, uchar param_1)
//              void              <VOID>         <RETURN>
//              TRIBE_Action_H    ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[3]:     004ceab1(R), 004ceb3c(W), 004cebde(W)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     004ceb42(W), 004ceb74(W), 004cebe4(W), 004cec11(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[3]:     004cebac(R), 004cec49(R), 004cecb3(R)
//                               ?set_state@TRIBE_Action_Heal@@MAEXE@Z                        XREF[1]:     005750dc(*)
//                               TRIBE_Action_Heal::set_state
//                              tact_hea.cpp:98 (25)
//         004cea90     MOV        EAX,FS:[0x0]
//         004cea96     PUSH       -0x1
//         004cea98     PUSH       FUN_0055fe96
//         004cea9d     PUSH       EAX
//         004cea9e     MOV        dword ptr FS:[0x0],ESP
//         004ceaa5     PUSH       ESI
//         004ceaa6     MOV        ESI,this
//         004ceaa8     PUSH       EDI
//                              tact_hea.cpp:107 (8)
//         004ceaa9     MOV        this,dword ptr [ESI + 0x34]
//         004ceaac     CALL       RGE_Action_List::delete_list                     void delete_list(RGE_Action_List * this)
//                              tact_hea.cpp:110 (7)
//         004ceab1     MOV        EAX,dword ptr [ESP + param_1]
//         004ceab5     MOV        byte ptr [ESI + 0xc],AL
//                              tact_hea.cpp:112 (24)
//         004ceab8     AND        EAX,0xff
//         004ceabd     ADD        EAX,-0x2
//         004ceac0     CMP        EAX,0x9
//         004ceac3     JA         switchD_004ceac9::caseD_5
//                               switchD_004ceac9::switchD
//         004ceac9     JMP        dword ptr [EAX*0x4 + switchD_004ceac9::switchd   = 004ceb10
//                               switchD_004ceac9::caseD_3                                    XREF[2]:     004ceac9(j), 004ceccc(*)
//                              tact_hea.cpp:115 (30)
//         004cead0     MOV        this,dword ptr [ESI + 0x8]
//         004cead3     PUSH       0x0
//         004cead5     PUSH       0x0
//         004cead7     PUSH       0x25b
//         004ceadc     MOV        EAX,dword ptr [ECX + this->field4_0x4]
//         004ceadf     MOV        EDX,dword ptr [this->field0_0x0]
//         004ceae1     PUSH       0x202
//         004ceae6     PUSH       EAX
//         004ceae7     PUSH       EAX
//         004ceae8     CALL       dword ptr [EDX + 0x148]
//                              tact_hea.cpp:116 (15)
//         004ceaee     MOV        this,dword ptr [ESI + 0x8]
//         004ceaf1     MOV        EDX,dword ptr [ECX + this->field8_0x8]
//         004ceaf4     MOV        EAX,dword ptr [this->field0_0x0]
//         004ceaf6     MOV        EDX,dword ptr [EDX + 0x18]
//         004ceaf9     PUSH       EDX
//         004ceafa     CALL       dword ptr [EAX + 0x38]
//                              tact_hea.cpp:169 (19)
//         004ceafd     MOV        this,dword ptr [ESP + 0x8]
//         004ceb01     MOV        dword ptr FS:[0x0],this
//         004ceb08     POP        EDI
//         004ceb09     POP        ESI
//         004ceb0a     ADD        ESP,0xc
//         004ceb0d     RET        0x4
//                               switchD_004ceac9::caseD_2                                    XREF[2]:     004ceac9(j), 004cecc8(*)
//                              tact_hea.cpp:120 (15)
//         004ceb10     MOV        this,dword ptr [ESI + 0x8]
//         004ceb13     MOV        EDX,dword ptr [ECX + this->field8_0x8]
//         004ceb16     MOV        EAX,dword ptr [this->field0_0x0]
//         004ceb18     MOV        EDX,dword ptr [EDX + 0x18]
//         004ceb1b     PUSH       EDX
//         004ceb1c     CALL       dword ptr [EAX + 0x38]
//                              tact_hea.cpp:169 (19)
//         004ceb1f     MOV        this,dword ptr [ESP + 0x8]
//         004ceb23     MOV        dword ptr FS:[0x0],this
//         004ceb2a     POP        EDI
//         004ceb2b     POP        ESI
//         004ceb2c     ADD        ESP,0xc
//         004ceb2f     RET        0x4
//                               switchD_004ceac9::caseD_b                                    XREF[2]:     004ceac9(j), 004cecec(*)
//                              tact_hea.cpp:126 (64)
//         004ceb32     PUSH       0x44
//         004ceb34     CALL       operator_new                                     void * operator_new(uint param_1)
//         004ceb39     ADD        ESP,0x4
//         004ceb3c     MOV        dword ptr [ESP + param_1],EAX
//         004ceb40     TEST       EAX,EAX
//         004ceb42     MOV        dword ptr [ESP + local_4],0x0
//         004ceb4a     JZ         LAB_004ceb70
//         004ceb4c     MOV        this,dword ptr [ESI + 0x30]
//         004ceb4f     MOV        EDX,dword ptr [ECX + this->field52_0x34]
//         004ceb52     MOV        this,dword ptr [ESI + 0x28]
//         004ceb55     PUSH       EDX
//         004ceb56     MOV        EDX,dword ptr [ESI + 0x24]
//         004ceb59     PUSH       0x0
//         004ceb5b     PUSH       this
//         004ceb5c     MOV        this,dword ptr [ESI + 0x20]
//         004ceb5f     PUSH       EDX
//         004ceb60     MOV        EDX,dword ptr [ESI + 0x8]
//         004ceb63     PUSH       this
//         004ceb64     PUSH       EDX
//         004ceb65     MOV        this,EAX
//         004ceb67     CALL       RGE_Action_Move_To::RGE_Action_Move_To           undefined RGE_Action_Move_To(RGE_Action_Move_
//         004ceb6c     MOV        EDI,EAX
//         004ceb6e     JMP        LAB_004ceb72
//                               LAB_004ceb70                                                 XREF[1]:     004ceb4a(j)
//         004ceb70     XOR        EDI,EDI
//                               LAB_004ceb72                                                 XREF[1]:     004ceb6e(j)
//                              tact_hea.cpp:127 (12)
//         004ceb72     TEST       EDI,EDI
//         004ceb74     MOV        dword ptr [ESP + local_4],0xffffffff
//         004ceb7c     JNZ        LAB_004ceb9a
//                              tact_hea.cpp:129 (9)
//         004ceb7e     MOV        EAX,dword ptr [ESI]
//         004ceb80     PUSH       0xd
//         004ceb82     MOV        this,ESI
//         004ceb84     CALL       dword ptr [EAX + 0x5c]
//                              tact_hea.cpp:169 (19)
//         004ceb87     MOV        this,dword ptr [ESP + 0x8]
//         004ceb8b     MOV        dword ptr FS:[0x0],this
//         004ceb92     POP        EDI
//         004ceb93     POP        ESI
//         004ceb94     ADD        ESP,0xc
//         004ceb97     RET        0x4
//                               LAB_004ceb9a                                                 XREF[1]:     004ceb7c(j)
//                              tact_hea.cpp:132 (9)
//         004ceb9a     PUSH       0x1
//         004ceb9c     MOV        this,EDI
//         004ceb9e     CALL       RGE_Action::setSubAction                         void setSubAction(RGE_Action * this, uchar pa
//                              tact_hea.cpp:133 (9)
//         004ceba3     MOV        this,dword ptr [ESI + 0x34]
//         004ceba6     PUSH       EDI
//         004ceba7     CALL       RGE_Action_List::add_action                      void add_action(RGE_Action_List * this, RGE_A
//                              tact_hea.cpp:169 (19)
//         004cebac     MOV        this,dword ptr [ESP + local_c]
//         004cebb0     MOV        dword ptr FS:[0x0],this
//         004cebb7     POP        EDI
//         004cebb8     POP        ESI
//         004cebb9     ADD        ESP,0xc
//         004cebbc     RET        0x4
//                               switchD_004ceac9::caseD_4                                    XREF[2]:     004ceac9(j), 004cecd0(*)
//                              tact_hea.cpp:138 (3)
//         004cebbf     MOV        EAX,dword ptr [ESI + 0x10]
//                              tact_hea.cpp:142 (77)
//         004cebc2     PUSH       0x44
//         004cebc4     MOV        this,dword ptr [EAX + 0x38]
//         004cebc7     MOV        dword ptr [ESI + 0x20],this
//         004cebca     MOV        EDX,dword ptr [EAX + 0x3c]
//         004cebcd     MOV        dword ptr [ESI + 0x24],EDX
//         004cebd0     MOV        EAX,dword ptr [EAX + 0x40]
//         004cebd3     MOV        dword ptr [ESI + 0x28],EAX
//         004cebd6     CALL       operator_new                                     void * operator_new(uint param_1)
//         004cebdb     ADD        ESP,0x4
//         004cebde     MOV        dword ptr [ESP + param_1],EAX
//         004cebe2     TEST       EAX,EAX
//         004cebe4     MOV        dword ptr [ESP + local_4],0x1
//         004cebec     JZ         LAB_004cec0d
//         004cebee     MOV        this,dword ptr [ESI + 0x30]
//         004cebf1     MOV        EDX,dword ptr [ECX + this->field52_0x34]
//         004cebf4     MOV        this,dword ptr [ESI + 0x10]
//         004cebf7     PUSH       EDX
//         004cebf8     MOV        EDX,dword ptr [ESI + 0x8]
//         004cebfb     PUSH       0x3ecccccd
//         004cec00     PUSH       this
//         004cec01     PUSH       EDX
//         004cec02     MOV        this,EAX
//         004cec04     CALL       RGE_Action_Move_To::RGE_Action_Move_To           undefined RGE_Action_Move_To(RGE_Action_Move_
//         004cec09     MOV        EDI,EAX
//         004cec0b     JMP        LAB_004cec0f
//                               LAB_004cec0d                                                 XREF[1]:     004cebec(j)
//         004cec0d     XOR        EDI,EDI
//                               LAB_004cec0f                                                 XREF[1]:     004cec0b(j)
//                              tact_hea.cpp:144 (12)
//         004cec0f     TEST       EDI,EDI
//         004cec11     MOV        dword ptr [ESP + local_4],0xffffffff
//         004cec19     JNZ        LAB_004cec37
//                              tact_hea.cpp:146 (9)
//         004cec1b     MOV        EAX,dword ptr [ESI]
//         004cec1d     PUSH       0xd
//         004cec1f     MOV        this,ESI
//         004cec21     CALL       dword ptr [EAX + 0x5c]
//                              tact_hea.cpp:169 (19)
//         004cec24     MOV        this,dword ptr [ESP + 0x8]
//         004cec28     MOV        dword ptr FS:[0x0],this
//         004cec2f     POP        EDI
//         004cec30     POP        ESI
//         004cec31     ADD        ESP,0xc
//         004cec34     RET        0x4
//                               LAB_004cec37                                                 XREF[1]:     004cec19(j)
//                              tact_hea.cpp:149 (9)
//         004cec37     MOV        this,dword ptr [ESI + 0x34]
//         004cec3a     PUSH       EDI
//         004cec3b     CALL       RGE_Action_List::add_action                      void add_action(RGE_Action_List * this, RGE_A
//                              tact_hea.cpp:150 (9)
//         004cec40     PUSH       0x1
//         004cec42     MOV        this,EDI
//         004cec44     CALL       RGE_Action::setSubAction                         void setSubAction(RGE_Action * this, uchar pa
//                              tact_hea.cpp:169 (19)
//         004cec49     MOV        this,dword ptr [ESP + local_c]
//         004cec4d     MOV        dword ptr FS:[0x0],this
//         004cec54     POP        EDI
//         004cec55     POP        ESI
//         004cec56     ADD        ESP,0xc
//         004cec59     RET        0x4
//                               switchD_004ceac9::caseD_6                                    XREF[2]:     004ceac9(j), 004cecd8(*)
//                              tact_hea.cpp:155 (9)
//         004cec5c     MOV        EAX,dword ptr [ESI + 0x10]
//         004cec5f     MOV        this,dword ptr [EAX + 0x38]
//         004cec62     MOV        dword ptr [ESI + 0x20],this
//                              tact_hea.cpp:156 (3)
//         004cec65     MOV        EDX,dword ptr [EAX + 0x3c]
//                              tact_hea.cpp:158 (24)
//         004cec68     MOV        this,dword ptr [ESI + 0x8]
//         004cec6b     MOV        dword ptr [ESI + 0x24],EDX
//         004cec6e     MOV        EAX,dword ptr [EAX + 0x40]
//         004cec71     MOV        EDX,dword ptr [this->field0_0x0]
//         004cec73     MOV        dword ptr [ESI + 0x28],EAX
//         004cec76     MOV        EAX,dword ptr [ESI + 0x30]
//         004cec79     MOV        EAX,dword ptr [EAX + 0x34]
//         004cec7c     PUSH       EAX
//         004cec7d     CALL       dword ptr [EDX + 0x38]
//                              tact_hea.cpp:169 (19)
//         004cec80     MOV        this,dword ptr [ESP + 0x8]
//         004cec84     MOV        dword ptr FS:[0x0],this
//         004cec8b     POP        EDI
//         004cec8c     POP        ESI
//         004cec8d     ADD        ESP,0xc
//         004cec90     RET        0x4
//                               switchD_004ceac9::caseD_7                                    XREF[2]:     004ceac9(j), 004cecdc(*)
//                              tact_hea.cpp:163 (15)
//         004cec93     MOV        EAX,dword ptr [ESI + 0x30]
//         004cec96     MOV        this,dword ptr [ESI + 0x8]
//         004cec99     MOV        EAX,dword ptr [EAX + 0x38]
//         004cec9c     MOV        EDX,dword ptr [this->field0_0x0]
//         004cec9e     PUSH       EAX
//         004cec9f     CALL       dword ptr [EDX + 0x38]
//                              tact_hea.cpp:165 (10)
//         004ceca2     MOV        this,dword ptr [ESI + 0x30]
//         004ceca5     MOV        this,dword ptr [this->field0_0x0 + 0x44]
//         004ceca8     TEST       this,this
//         004cecaa     JZ         switchD_004ceac9::caseD_5
//                              tact_hea.cpp:166 (7)
//         004cecac     PUSH       0x1
//         004cecae     CALL       RGE_Sound::play                                  void play(RGE_Sound * this, int param_1)
//                               switchD_004ceac9::caseD_8                                    XREF[7]:     004ceac3(j), 004ceac9(j),
//                               switchD_004ceac9::caseD_9                                                 004cecaa(j), 004cecd4(*),
//                               switchD_004ceac9::caseD_a                                                 004cece0(*), 004cece4(*),
//                               switchD_004ceac9::caseD_5                                                 004cece8(*)
//                              tact_hea.cpp:169 (61)
//         004cecb3     MOV        this,dword ptr [ESP + local_c]
//         004cecb7     POP        EDI
//         004cecb8     MOV        dword ptr FS:[0x0],this
//         004cecbf     POP        ESI
//         004cecc0     ADD        ESP,0xc
//         004cecc3     RET        0x4
    return;
}

uchar TRIBE_Action_Heal::update() {
    /* TODO: Stub */
//                              uchar __thiscall update(TRIBE_Action_Heal * this)
//              uchar             AL:1           <RETURN>
//              TRIBE_Action_H    ECX:4 (auto)   this
//              float             Stack[-0x8]:4  work
//                               ?update@TRIBE_Action_Heal@@UAEEXZ                            XREF[1]:     005750a8(*)
//                               TRIBE_Action_Heal::update
//                              tact_hea.cpp:175 (5)
//         004cecf0     PUSH       this
//         004cecf1     PUSH       ESI
//         004cecf2     MOV        ESI,this
//         004cecf4     PUSH       EDI
//                              tact_hea.cpp:195 (25)
//         004cecf5     MOV        EAX,dword ptr [ESI + 0x18]
//         004cecf8     CMP        EAX,-0x1
//         004cecfb     JZ         LAB_004ced10
//         004cecfd     PUSH       EAX
//         004cecfe     MOV        EAX,dword ptr [ESI + 0x8]
//         004ced01     MOV        this,dword ptr [EAX + 0xc]
//         004ced04     MOV        this,dword ptr [ECX + this->field60_0x3c]
//         004ced07     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
//         004ced0c     TEST       EAX,EAX
//                              tact_hea.cpp:199 (2)
//         004ced0e     JZ         LAB_004ced40
//                               LAB_004ced10                                                 XREF[1]:     004cecfb(j)
//                              tact_hea.cpp:201 (27)
//         004ced10     MOV        EAX,dword ptr [ESI + 0x1c]
//         004ced13     CMP        EAX,-0x1
//         004ced16     JZ         LAB_004ced33
//         004ced18     MOV        EDX,dword ptr [ESI + 0x8]
//         004ced1b     PUSH       EAX
//         004ced1c     MOV        EAX,dword ptr [EDX + 0xc]
//         004ced1f     MOV        this,dword ptr [EAX + 0x3c]
//         004ced22     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
//         004ced27     TEST       EAX,EAX
//         004ced29     JNZ        LAB_004ced33
//                              tact_hea.cpp:202 (8)
//         004ced2b     MOV        EDX,dword ptr [ESI]
//         004ced2d     PUSH       EAX
//         004ced2e     MOV        this,ESI
//         004ced30     CALL       dword ptr [EDX + 0x58]
//                               LAB_004ced33                                                 XREF[2]:     004ced16(j), 004ced29(j)
//                              tact_hea.cpp:205 (13)
//         004ced33     MOV        EAX,dword ptr [ESI + 0x10]
//         004ced36     TEST       EAX,EAX
//         004ced38     JZ         LAB_004ced9e
//         004ced3a     CMP        byte ptr [EAX + 0x48],0x2
//         004ced3e     JZ         LAB_004ced56
//                               LAB_004ced40                                                 XREF[1]:     004ced0e(j)
//                              tact_hea.cpp:207 (9)
//         004ced40     MOV        EDI,dword ptr [ESI]
//         004ced42     PUSH       0x0
//         004ced44     MOV        this,ESI
//         004ced46     CALL       dword ptr [EDI + 0x54]
//                              tact_hea.cpp:208 (7)
//         004ced49     PUSH       0x3
//         004ced4b     MOV        this,ESI
//         004ced4d     CALL       dword ptr [EDI + 0x5c]
//                              tact_hea.cpp:364 (2)
//         004ced50     XOR        AL,AL
//                              tact_hea.cpp:365 (4)
//         004ced52     POP        EDI
//         004ced53     POP        ESI
//         004ced54     POP        this
//         004ced55     RET
//                               LAB_004ced56                                                 XREF[1]:     004ced3e(j)
//                              tact_hea.cpp:214 (27)
//         004ced56     TEST       EAX,EAX
//         004ced58     JZ         LAB_004ced9e
//         004ced5a     MOV        this,dword ptr [ESI + 0x8]
//         004ced5d     MOV        EAX,dword ptr [EAX + 0xc]
//         004ced60     MOV        this,dword ptr [ECX + this->field12_0xc]
//         004ced63     MOVSX      EAX,word ptr [EAX + 0x4a]
//         004ced67     MOV        EDX,dword ptr [this->field0_0x0]
//         004ced69     PUSH       EAX
//         004ced6a     CALL       dword ptr [EDX + 0x1c]
//         004ced6d     TEST       EAX,EAX
//         004ced6f     JNZ        LAB_004ced9e
//                              tact_hea.cpp:216 (9)
//         004ced71     MOV        EDX,dword ptr [ESI]
//         004ced73     PUSH       0x1
//         004ced75     MOV        this,ESI
//         004ced77     CALL       dword ptr [EDX + 0x5c]
//                              tact_hea.cpp:217 (30)
//         004ced7a     MOV        this,dword ptr [ESI + 0x8]
//         004ced7d     PUSH       0x0
//         004ced7f     PUSH       0x0
//         004ced81     PUSH       0x25b
//         004ced86     MOV        EAX,dword ptr [ECX + this->field4_0x4]
//         004ced89     MOV        EDX,dword ptr [this->field0_0x0]
//         004ced8b     PUSH       0x1fb
//         004ced90     PUSH       EAX
//         004ced91     PUSH       EAX
//         004ced92     CALL       dword ptr [EDX + 0x148]
//                              tact_hea.cpp:218 (2)
//         004ced98     MOV        AL,0x4
//                              tact_hea.cpp:365 (4)
//         004ced9a     POP        EDI
//         004ced9b     POP        ESI
//         004ced9c     POP        this
//         004ced9d     RET
//                               LAB_004ced9e                                                 XREF[3]:     004ced38(j), 004ced58(j),
//                                                                                                         004ced6f(j)
//                              tact_hea.cpp:221 (30)
//         004ced9e     XOR        EAX,EAX
//         004ceda0     MOV        AL,byte ptr [ESI + 0xc]
//         004ceda3     DEC        EAX
//         004ceda4     CMP        EAX,0xc
//         004ceda7     JA         switchD_004cedb5::caseD_2
//         004cedad     XOR        this,this
//         004cedaf     MOV        this,byte ptr [EAX + 0x4ceff0]=>PTR_caseD_2_00
//                               switchD_004cedb5::switchD
//         004cedb5     JMP        dword ptr [this->field0_0x0*0x4 + switchD_004c   = 004cef9a
//                               switchD_004cedb5::caseD_b                                    XREF[2]:     004cedb5(j), 004cefe4(*)
//                              tact_hea.cpp:225 (30)
//         004cedbc     MOV        this,dword ptr [ESI + 0x34]
//         004cedbf     MOV        EDX,dword ptr [this->field0_0x0]
//         004cedc1     CALL       dword ptr [EDX + 0xc]
//         004cedc4     AND        EAX,0xff
//         004cedc9     DEC        EAX
//         004cedca     CMP        EAX,0x4
//         004cedcd     JA         switchD_004cedb5::caseD_2
//                               switchD_004cedd3::switchD
//         004cedd3     JMP        dword ptr [EAX*0x4 + switchD_004cedd3::switchd   = 004cedda
//                               switchD_004cedd3::caseD_1                                    XREF[4]:     004cedd3(j), 004cf000(*),
//                               switchD_004cedd3::caseD_4                                                 004cf004(*), 004cf010(*)
//                               switchD_004cedd3::caseD_0
//                              tact_hea.cpp:242 (9)
//         004cedda     MOV        EAX,dword ptr [ESI]
//         004ceddc     PUSH       0x3
//         004cedde     MOV        this,ESI
//         004cede0     CALL       dword ptr [EAX + 0x5c]
//                              tact_hea.cpp:364 (2)
//         004cede3     XOR        AL,AL
//                              tact_hea.cpp:365 (4)
//         004cede5     POP        EDI
//         004cede6     POP        ESI
//         004cede7     POP        this
//         004cede8     RET
//                               switchD_004cedb5::caseD_4                                    XREF[2]:     004cedb5(j), 004cefd8(*)
//                              tact_hea.cpp:257 (30)
//         004cede9     MOV        this,dword ptr [ESI + 0x34]
//         004cedec     MOV        EAX,dword ptr [this->field0_0x0]
//         004cedee     CALL       dword ptr [EAX + 0xc]
//         004cedf1     AND        EAX,0xff
//         004cedf6     DEC        EAX
//         004cedf7     CMP        EAX,0x4
//         004cedfa     JA         switchD_004cedb5::caseD_2
//                               switchD_004cee00::switchD
//         004cee00     JMP        dword ptr [EAX*0x4 + switchD_004cee00::switchd   = 004cee2c
//                               switchD_004cee00::caseD_3                                    XREF[5]:     004cedd3(j), 004cee00(j),
//                               switchD_004cee00::caseD_4                                                 004cf00c(*), 004cf020(*),
//                               switchD_004cedd3::caseD_3                                                 004cf024(*)
//                              tact_hea.cpp:266 (9)
//         004cee07     MOV        EDI,dword ptr [ESI]
//         004cee09     PUSH       0x0
//         004cee0b     MOV        this,ESI
//         004cee0d     CALL       dword ptr [EDI + 0x54]
//                              tact_hea.cpp:267 (7)
//         004cee10     PUSH       0xb
//         004cee12     MOV        this,ESI
//         004cee14     CALL       dword ptr [EDI + 0x5c]
//                              tact_hea.cpp:364 (2)
//         004cee17     XOR        AL,AL
//                              tact_hea.cpp:365 (4)
//         004cee19     POP        EDI
//         004cee1a     POP        ESI
//         004cee1b     POP        this
//         004cee1c     RET
//                               switchD_004cee00::caseD_2                                    XREF[4]:     004cedd3(j), 004cee00(j),
//                               switchD_004cedd3::caseD_2                                                 004cf008(*), 004cf01c(*)
//                              tact_hea.cpp:275 (9)
//         004cee1d     MOV        EDX,dword ptr [ESI]
//         004cee1f     PUSH       0xd
//         004cee21     MOV        this,ESI
//         004cee23     CALL       dword ptr [EDX + 0x5c]
//                              tact_hea.cpp:364 (2)
//         004cee26     XOR        AL,AL
//                              tact_hea.cpp:365 (4)
//         004cee28     POP        EDI
//         004cee29     POP        ESI
//         004cee2a     POP        this
//         004cee2b     RET
//                               switchD_004cee00::caseD_1                                    XREF[3]:     004cee00(j), 004cf014(*),
//                               switchD_004cee00::caseD_0                                                 004cf018(*)
//                              tact_hea.cpp:281 (9)
//         004cee2c     MOV        EAX,dword ptr [ESI]
//         004cee2e     PUSH       0x6
//         004cee30     MOV        this,ESI
//         004cee32     CALL       dword ptr [EAX + 0x5c]
//                              tact_hea.cpp:364 (2)
//         004cee35     XOR        AL,AL
//                              tact_hea.cpp:365 (4)
//         004cee37     POP        EDI
//         004cee38     POP        ESI
//         004cee39     POP        this
//         004cee3a     RET
//                               switchD_004cedb5::caseD_6                                    XREF[2]:     004cedb5(j), 004cefdc(*)
//                              tact_hea.cpp:289 (7)
//         004cee3b     MOV        EAX,dword ptr [ESI + 0x10]
//         004cee3e     TEST       EAX,EAX
//         004cee40     JNZ        LAB_004cee51
//                              tact_hea.cpp:291 (9)
//         004cee42     MOV        EDX,dword ptr [ESI]
//         004cee44     PUSH       0x3
//         004cee46     MOV        this,ESI
//         004cee48     CALL       dword ptr [EDX + 0x5c]
//                              tact_hea.cpp:364 (2)
//         004cee4b     XOR        AL,AL
//                              tact_hea.cpp:365 (4)
//         004cee4d     POP        EDI
//         004cee4e     POP        ESI
//         004cee4f     POP        this
//         004cee50     RET
//                               LAB_004cee51                                                 XREF[1]:     004cee40(j)
//                              tact_hea.cpp:296 (24)
//         004cee51     MOV        this,dword ptr [ESI + 0x8]
//         004cee54     PUSH       0x0
//         004cee56     PUSH       0x0
//         004cee58     PUSH       EAX
//         004cee59     MOV        EDX,dword ptr [this->field0_0x0]
//         004cee5b     CALL       dword ptr [EDX + 0x1f0]
//         004cee61     TEST       AL,AL
//         004cee63     JZ         switchD_004cedb5::caseD_2
//                              tact_hea.cpp:298 (9)
//         004cee69     MOV        EAX,dword ptr [ESI]
//         004cee6b     PUSH       0x7
//         004cee6d     MOV        this,ESI
//         004cee6f     CALL       dword ptr [EAX + 0x5c]
//                              tact_hea.cpp:364 (2)
//         004cee72     XOR        AL,AL
//                              tact_hea.cpp:365 (4)
//         004cee74     POP        EDI
//         004cee75     POP        ESI
//         004cee76     POP        this
//         004cee77     RET
//                               switchD_004cedb5::caseD_7                                    XREF[2]:     004cedb5(j), 004cefe0(*)
//                              tact_hea.cpp:307 (7)
//         004cee78     MOV        this,dword ptr [ESI + 0x10]
//         004cee7b     TEST       this,this
//         004cee7d     JNZ        LAB_004cee8e
//                              tact_hea.cpp:309 (9)
//         004cee7f     MOV        EDX,dword ptr [ESI]
//         004cee81     PUSH       0x3
//         004cee83     MOV        this,ESI
//         004cee85     CALL       dword ptr [EDX + 0x5c]
//                              tact_hea.cpp:364 (2)
//         004cee88     XOR        AL,AL
//                              tact_hea.cpp:365 (4)
//         004cee8a     POP        EDI
//         004cee8b     POP        ESI
//         004cee8c     POP        this
//         004cee8d     RET
//                               LAB_004cee8e                                                 XREF[1]:     004cee7d(j)
//                              tact_hea.cpp:315 (34)
//         004cee8e     FLD        float ptr [ECX + this->field56_0x38]
//         004cee91     FCOMP      float ptr [ESI + 0x20]
//         004cee94     FNSTSW     AX
//         004cee96     TEST       AH,0x40
//         004cee99     JZ         LAB_004cef4b
//         004cee9f     FLD        float ptr [ESI + 0x24]
//         004ceea2     FCOMP      float ptr [ECX + this->field60_0x3c]
//         004ceea5     FNSTSW     AX
//         004ceea7     TEST       AH,0x40
//         004ceeaa     JZ         LAB_004cef4b
//                              tact_hea.cpp:333 (24)
//         004ceeb0     MOV        EAX,dword ptr [ESI + 0x8]
//         004ceeb3     MOV        EDI,dword ptr [ESI + 0x30]
//         004ceeb6     MOV        EDX,dword ptr [EAX + 0xc]
//         004ceeb9     MOV        EAX,dword ptr [EAX + 0x8]
//         004ceebc     FLD        float ptr [EDI + 0x1c]
//         004ceebf     FMUL       float ptr [EAX + 0xe4]
//         004ceec5     MOV        EAX,dword ptr [EDX + 0x3c]
//                              tact_hea.cpp:336 (32)
//         004ceec8     MOV        EDX,dword ptr [EDX + 0x50]
//         004ceecb     FMUL       float ptr [EAX + 0x84]
//         004ceed1     FSTP       float ptr [ESP + 0x8]
//         004ceed5     FLD        float ptr [EDX + 0xe0]
//         004ceedb     FCOMP      float ptr [DAT_005750e0]                         = CDh
//         004ceee1     FNSTSW     AX
//         004ceee3     TEST       AH,0x41
//         004ceee6     JNZ        LAB_004ceef6
//                              tact_hea.cpp:337 (14)
//         004ceee8     FLD        float ptr [ESP + 0x8]
//         004ceeec     FMUL       float ptr [EDX + 0xe0]
//         004ceef2     FSTP       float ptr [ESP + 0x8]
//                               LAB_004ceef6                                                 XREF[1]:     004ceee6(j)
//                              tact_hea.cpp:339 (13)
//         004ceef6     MOV        EAX,dword ptr [ESP + 0x8]
//         004ceefa     MOV        EDX,dword ptr [this->field0_0x0]
//         004ceefc     PUSH       EAX
//         004ceefd     CALL       dword ptr [EDX + 0x8c]
//                              tact_hea.cpp:340 (4)
//         004cef03     CMP        AL,0x1
//         004cef05     JNZ        LAB_004cef16
//                              tact_hea.cpp:341 (9)
//         004cef07     MOV        EDX,dword ptr [ESI]
//         004cef09     PUSH       0x3
//         004cef0b     MOV        this,ESI
//         004cef0d     CALL       dword ptr [EDX + 0x5c]
//                              tact_hea.cpp:364 (2)
//         004cef10     XOR        AL,AL
//                              tact_hea.cpp:365 (4)
//         004cef12     POP        EDI
//         004cef13     POP        ESI
//         004cef14     POP        this
//         004cef15     RET
//                               LAB_004cef16                                                 XREF[1]:     004cef05(j)
//                              tact_hea.cpp:342 (8)
//         004cef16     CMP        AL,0x2
//         004cef18     JNZ        switchD_004cedb5::caseD_2
//                              tact_hea.cpp:344 (30)
//         004cef1e     MOV        this,dword ptr [ESI + 0x8]
//         004cef21     PUSH       0x0
//         004cef23     PUSH       0x0
//         004cef25     PUSH       0x25b
//         004cef2a     MOV        EAX,dword ptr [ECX + this->field4_0x4]
//         004cef2d     MOV        EDX,dword ptr [this->field0_0x0]
//         004cef2f     PUSH       0x1fb
//         004cef34     PUSH       EAX
//         004cef35     PUSH       EAX
//         004cef36     CALL       dword ptr [EDX + 0x148]
//                              tact_hea.cpp:345 (9)
//         004cef3c     MOV        EAX,dword ptr [ESI]
//         004cef3e     PUSH       0x2
//         004cef40     MOV        this,ESI
//         004cef42     CALL       dword ptr [EAX + 0x5c]
//                              tact_hea.cpp:364 (2)
//         004cef45     XOR        AL,AL
//                              tact_hea.cpp:365 (4)
//         004cef47     POP        EDI
//         004cef48     POP        ESI
//         004cef49     POP        this
//         004cef4a     RET
//                               LAB_004cef4b                                                 XREF[2]:     004cee99(j), 004ceeaa(j)
//                              tact_hea.cpp:319 (9)
//         004cef4b     PUSH       this
//         004cef4c     MOV        this,dword ptr [ESI + 0x8]
//         004cef4f     CALL       RGE_Static_Object::distance_to_object            float distance_to_object(RGE_Static_Object *
//                              tact_hea.cpp:320 (26)
//         004cef54     MOV        this,dword ptr [ESI + 0x30]
//         004cef57     FCOM       float ptr [ECX + this->field36_0x24]
//         004cef5a     FNSTSW     AX
//         004cef5c     TEST       AH,0x41
//         004cef5f     JNZ        LAB_004cef7d
//         004cef61     FCOMP      double ptr [DAT_005750e8]
//         004cef67     FNSTSW     AX
//         004cef69     TEST       AH,0x41
//         004cef6c     JNZ        LAB_004cef7f
//                              tact_hea.cpp:321 (9)
//         004cef6e     MOV        EDX,dword ptr [ESI]
//         004cef70     PUSH       0x3
//         004cef72     MOV        this,ESI
//         004cef74     CALL       dword ptr [EDX + 0x5c]
//                              tact_hea.cpp:364 (2)
//         004cef77     XOR        AL,AL
//                              tact_hea.cpp:365 (4)
//         004cef79     POP        EDI
//         004cef7a     POP        ESI
//         004cef7b     POP        this
//         004cef7c     RET
//                               LAB_004cef7d                                                 XREF[1]:     004cef5f(j)
//                              tact_hea.cpp:320 (2)
//         004cef7d     FSTP       ST0
//                               LAB_004cef7f                                                 XREF[1]:     004cef6c(j)
//                              tact_hea.cpp:324 (9)
//         004cef7f     MOV        EAX,dword ptr [ESI + 0x10]
//         004cef82     MOV        this,dword ptr [EAX + 0x38]
//         004cef85     MOV        dword ptr [ESI + 0x20],this
//                              tact_hea.cpp:325 (6)
//         004cef88     MOV        EDX,dword ptr [EAX + 0x3c]
//         004cef8b     MOV        dword ptr [ESI + 0x24],EDX
//                              tact_hea.cpp:326 (6)
//         004cef8e     MOV        EAX,dword ptr [EAX + 0x40]
//         004cef91     MOV        dword ptr [ESI + 0x28],EAX
//                              tact_hea.cpp:364 (2)
//         004cef94     XOR        AL,AL
//                              tact_hea.cpp:365 (4)
//         004cef96     POP        EDI
//         004cef97     POP        ESI
//         004cef98     POP        this
//         004cef99     RET
//                               switchD_004cedb5::caseD_1                                    XREF[2]:     004cedb5(j), 004cefd4(*)
//                              tact_hea.cpp:355 (2)
//         004cef9a     MOV        AL,0x1
//                              tact_hea.cpp:365 (4)
//         004cef9c     POP        EDI
//         004cef9d     POP        ESI
//         004cef9e     POP        this
//         004cef9f     RET
//                               switchD_004cedb5::caseD_d                                    XREF[2]:     004cedb5(j), 004cefe8(*)
//                              tact_hea.cpp:359 (30)
//         004cefa0     MOV        this,dword ptr [ESI + 0x8]
//         004cefa3     PUSH       0x0
//         004cefa5     PUSH       0x0
//         004cefa7     PUSH       0x25b
//         004cefac     MOV        EAX,dword ptr [ECX + this->field4_0x4]
//         004cefaf     MOV        EDX,dword ptr [this->field0_0x0]
//         004cefb1     PUSH       0x1f9
//         004cefb6     PUSH       EAX
//         004cefb7     PUSH       EAX
//         004cefb8     CALL       dword ptr [EDX + 0x148]
//                              tact_hea.cpp:360 (9)
//         004cefbe     MOV        EAX,dword ptr [ESI]
//         004cefc0     PUSH       0x2
//         004cefc2     MOV        this,ESI
//         004cefc4     CALL       dword ptr [EAX + 0x5c]
//                              tact_hea.cpp:361 (2)
//         004cefc7     MOV        AL,0x3
//                              tact_hea.cpp:365 (95)
//         004cefc9     POP        EDI
//         004cefca     POP        ESI
//         004cefcb     POP        this
//         004cefcc     RET
//                               switchD_004cedb5::caseD_3                                    XREF[7]:     004ceda7(j), 004cedb5(j),
//                               switchD_004cedb5::caseD_5                                                 004cedcd(j), 004cedfa(j),
//                               switchD_004cedb5::caseD_8                                                 004cee63(j), 004cef18(j),
//                               switchD_004cedb5::caseD_9                                                 004cefec(*)
//                               switchD_004cedb5::caseD_a
//                               switchD_004cedb5::caseD_c
//                               switchD_004cedd3::default
//                               switchD_004cee00::default
//                               switchD_004cedb5::caseD_2
//         004cefcd     POP        EDI
//         004cefce     XOR        AL,AL
//         004cefd0     POP        ESI
//         004cefd1     POP        this
//         004cefd2     RET
//         004cefd3     ??         90h
//                              Symbol Ref: No symbol: NONAME
//                               switchD_004cedb5::switchdataD_004cefd4                       XREF[1]:     update:004cedb5(*)
//         004cefd4     addr       switchD_004cedb5::caseD_1
//         004cefd8     addr       switchD_004cedb5::caseD_4
//         004cefdc     addr       switchD_004cedb5::caseD_6
//         004cefe0     addr       switchD_004cedb5::caseD_7
//         004cefe4     addr       switchD_004cedb5::caseD_b
//         004cefe8     addr       switchD_004cedb5::caseD_d
//                               PTR_caseD_2_004cefec+3                                       XREF[0,1]:   update:004cedaf(*)
//         004cefec     addr       switchD_004cedb5::caseD_2
//                              Symbol Ref: No symbol: NONAME
//                               switchD_004cedb5::switchdataD_004ceff0
//         004ceff0     db         0h
//         004ceff1     db         6h
//         004ceff2     db         6h
//         004ceff3     db         1h
//         004ceff4     db         6h
//         004ceff5     db         2h
//         004ceff6     db         3h
//         004ceff7     db         6h
//         004ceff8     db         6h
//         004ceff9     db         6h
//         004ceffa     db         4h
//         004ceffb     db         6h
//         004ceffc     db         5h
//         004ceffd     ??         90h
//         004ceffe     ??         8Bh
//         004cefff     ??         FFh
//                              Symbol Ref: No symbol: NONAME
//                               switchD_004cedd3::switchdataD_004cf000                       XREF[1]:     update:004cedd3(*)
//         004cf000     addr       switchD_004cedd3::caseD_0
//         004cf004     addr       switchD_004cedd3::caseD_0
//         004cf008     addr       switchD_004cedd3::caseD_2
//         004cf00c     addr       switchD_004cedd3::caseD_3
//         004cf010     addr       switchD_004cedd3::caseD_0
//                              Symbol Ref: No symbol: NONAME
//                               switchD_004cee00::switchdataD_004cf014                       XREF[1]:     update:004cee00(*)
//         004cf014     addr       switchD_004cee00::caseD_0
//         004cf018     addr       switchD_004cee00::caseD_0
//         004cf01c     addr       switchD_004cedd3::caseD_2
//         004cf020     addr       switchD_004cedd3::caseD_3
//         004cf024     addr       switchD_004cedd3::caseD_3
//         004cf028     ??         90h
//         004cf029     ??         90h
//         004cf02a     ??         90h
//         004cf02b     ??         90h
//         004cf02c     ??         90h
//         004cf02d     ??         90h
//         004cf02e     ??         90h
//         004cf02f     ??         90h
    return 0;
}

int TRIBE_Action_Heal::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    /* TODO: Stub */
//                              int __thiscall work(TRIBE_Action_Heal * this, RGE_Static_Object * pa
//              int               EAX:4          <RETURN>
//              TRIBE_Action_H    ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004cf033(R)
//              float             Stack[0x8]:4   param_2
//              float             Stack[0xc]:4   param_3
//              float             Stack[0x10]:4  param_4
//                               ?work@TRIBE_Action_Heal@@UAEHPAVRGE_Static_Object@@MMM@Z     XREF[1]:     005750b4(*)
//                               TRIBE_Action_Heal::work
//                              tact_hea.cpp:371 (3)
//         004cf030     PUSH       EBX
//         004cf031     PUSH       ESI
//         004cf032     PUSH       EDI
//                              tact_hea.cpp:372 (10)
//         004cf033     MOV        EDI,dword ptr [ESP + param_1]
//         004cf037     TEST       EDI,EDI
//         004cf039     MOV        ESI,this
//         004cf03b     JZ         LAB_004cf088
//                              tact_hea.cpp:377 (20)
//         004cf03d     CMP        EDI,dword ptr [ESI + 0x10]
//         004cf040     JNZ        LAB_004cf05c
//         004cf042     MOV        AL,byte ptr [ESI + 0xc]
//         004cf045     CMP        AL,0x4
//         004cf047     JZ         LAB_004cf07d
//         004cf049     CMP        AL,0x6
//         004cf04b     JZ         LAB_004cf07d
//         004cf04d     CMP        AL,0x7
//         004cf04f     JNZ        LAB_004cf05c
//                              tact_hea.cpp:378 (5)
//         004cf051     MOV        EAX,0x1
//                              tact_hea.cpp:390 (6)
//         004cf056     POP        EDI
//         004cf057     POP        ESI
//         004cf058     POP        EBX
//         004cf059     RET        0x10
//                               LAB_004cf05c                                                 XREF[2]:     004cf040(j), 004cf04f(j)
//                              tact_hea.cpp:380 (8)
//         004cf05c     MOV        EBX,dword ptr [ESI]
//         004cf05e     PUSH       EDI
//         004cf05f     MOV        this,ESI
//         004cf061     CALL       dword ptr [EBX + 0x54]
//                              tact_hea.cpp:381 (3)
//         004cf064     MOV        EAX,dword ptr [EDI + 0x38]
//                              tact_hea.cpp:385 (22)
//         004cf067     PUSH       0x1
//         004cf069     MOV        dword ptr [ESI + 0x20],EAX
//         004cf06c     MOV        this,dword ptr [EDI + 0x3c]
//         004cf06f     MOV        dword ptr [ESI + 0x24],this
//         004cf072     MOV        EDX,dword ptr [EDI + 0x40]
//         004cf075     MOV        this,ESI
//         004cf077     MOV        dword ptr [ESI + 0x28],EDX
//         004cf07a     CALL       dword ptr [EBX + 0x1c]
//                               LAB_004cf07d                                                 XREF[2]:     004cf047(j), 004cf04b(j)
//                              tact_hea.cpp:386 (5)
//         004cf07d     MOV        EAX,0x1
//                              tact_hea.cpp:390 (14)
//         004cf082     POP        EDI
//         004cf083     POP        ESI
//         004cf084     POP        EBX
//         004cf085     RET        0x10
//                               LAB_004cf088                                                 XREF[1]:     004cf03b(j)
//         004cf088     POP        EDI
//         004cf089     POP        ESI
//         004cf08a     XOR        EAX,EAX
//         004cf08c     POP        EBX
//         004cf08d     RET        0x10
    return 0;
}

TRIBE_Action_Heal::~TRIBE_Action_Heal() {
    /* TODO: Stub */
//                              void __thiscall ~TRIBE_Action_Heal(TRIBE_Action_Heal * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Action_H    ECX:4 (auto)   this
//                               ??1TRIBE_Action_Heal@@UAE@XZ                                 XREF[1]:     `scalar_deleting_destructor':004ce
//                               TRIBE_Action_Heal::~TRIBE_Action_Heal
//         004ce980     JMP        RGE_Action::~RGE_Action
//         004ce985     ??         90h
//         004ce986     NOP
//         004ce987     NOP
//         004ce988     NOP
//         004ce989     NOP
//         004ce98a     NOP
//         004ce98b     NOP
//         004ce98c     NOP
//         004ce98d     NOP
//         004ce98e     NOP
//         004ce98f     NOP
}

