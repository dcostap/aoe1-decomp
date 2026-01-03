#include "../common.h"
#include "tact_art.h"

TRIBE_Action_Artifact::TRIBE_Action_Artifact(int param_1, RGE_Action_Object* param_2) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Action_Artifact(TRIBE_Action_Artifact * t
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Action_A    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004ccba9(R)
//              RGE_Action_Obj    Stack[0x8]:4   param_2                   XREF[1]:     004ccba0(R)
//                               ??0TRIBE_Action_Artifact@@QAE@HPAVRGE_Action_Object@@@Z      XREF[1]:     create_action:004d0313(c)
//                               TRIBE_Action_Artifact::TRIBE_Action_Artifact
//                              tact_art.cpp:36 (28)
//         004ccba0     MOV        EAX,dword ptr [ESP + param_2]
//         004ccba4     PUSH       ESI
//         004ccba5     MOV        ESI,this
//         004ccba7     PUSH       0x1
//         004ccba9     MOV        this,dword ptr [ESP + param_1]
//         004ccbad     PUSH       EAX
//         004ccbae     PUSH       this
//         004ccbaf     MOV        this,ESI
//         004ccbb1     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, int p
//         004ccbb6     MOV        dword ptr [ESI],TRIBE_Action_Artifact::`vftable' = 004ccbd0
//                              tact_art.cpp:37 (6)
//         004ccbbc     MOV        word ptr [ESI + 0x4],0x6b
//                              tact_art.cpp:38 (6)
//         004ccbc2     MOV        EAX,ESI
//         004ccbc4     POP        ESI
//         004ccbc5     RET        0x8
//         004ccbc8     ??         90h
//         004ccbc9     NOP
//         004ccbca     NOP
//         004ccbcb     NOP
//         004ccbcc     NOP
//         004ccbcd     NOP
//         004ccbce     NOP
//         004ccbcf     NOP
}

TRIBE_Action_Artifact::TRIBE_Action_Artifact(RGE_Action_Object* param_1, RGE_Task* param_2, RGE_Static_Object* param_3) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Action_Artifact(TRIBE_Action_Artifact * t
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Action_A    ECX:4 (auto)   this
//              RGE_Action_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004ccc00(R)
//              RGE_Task *        Stack[0x8]:4   param_2                   XREF[1]:     004ccc0f(R)
//              RGE_Static_Obj    Stack[0xc]:4   param_3                   XREF[1]:     004ccc13(R)
//                               ??0TRIBE_Action_Artifact@@QAE@PAVRGE_Action_Object@@PAVRGE_  XREF[1]:     create_task_action:004d07f1(c)
//                               TRIBE_Action_Artifact::TRIBE_Action_Artifact
//                              tact_art.cpp:43 (15)
//         004ccc00     MOV        EAX,dword ptr [ESP + param_1]
//         004ccc04     PUSH       ESI
//         004ccc05     PUSH       0x1
//         004ccc07     MOV        ESI,this
//         004ccc09     PUSH       EAX
//         004ccc0a     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, RGE_A
//                              tact_art.cpp:46 (4)
//         004ccc0f     MOV        this,dword ptr [ESP + param_2]
//                              tact_art.cpp:47 (22)
//         004ccc13     MOV        EDX,dword ptr [ESP + param_3]
//         004ccc17     MOV        dword ptr [ESI],TRIBE_Action_Artifact::`vftable' = 004ccbd0
//         004ccc1d     MOV        word ptr [ESI + 0x4],0x6b
//         004ccc23     MOV        dword ptr [ESI + 0x30],this
//         004ccc26     MOV        dword ptr [ESI + 0x10],EDX
//                              tact_art.cpp:48 (6)
//         004ccc29     MOV        EAX,ESI
//         004ccc2b     POP        ESI
//         004ccc2c     RET        0xc
//         004ccc2f     ??         90h
}

TRIBE_Action_Artifact::TRIBE_Action_Artifact(RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Action_Artifact(TRIBE_Action_Artifact * t
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Action_A    ECX:4 (auto)   this
//              RGE_Action_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004ccc30(R)
//              RGE_Task *        Stack[0x8]:4   param_2                   XREF[1]:     004ccc3f(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     004ccc47(R)
//              float             Stack[0x10]:4  param_4                   XREF[1]:     004ccc43(R)
//              float             Stack[0x14]:4  param_5                   XREF[1]:     004ccc4e(R)
//                               ??0TRIBE_Action_Artifact@@QAE@PAVRGE_Action_Object@@PAVRGE_  XREF[1]:     create_task_action:004d083c(c)
//                               TRIBE_Action_Artifact::TRIBE_Action_Artifact
//                              tact_art.cpp:53 (15)
//         004ccc30     MOV        EAX,dword ptr [ESP + param_1]
//         004ccc34     PUSH       ESI
//         004ccc35     PUSH       0x1
//         004ccc37     MOV        ESI,this
//         004ccc39     PUSH       EAX
//         004ccc3a     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, RGE_A
//                              tact_art.cpp:56 (4)
//         004ccc3f     MOV        this,dword ptr [ESP + param_2]
//                              tact_art.cpp:58 (11)
//         004ccc43     MOV        EAX,dword ptr [ESP + param_4]
//         004ccc47     MOV        EDX,dword ptr [ESP + param_3]
//         004ccc4b     MOV        dword ptr [ESI + 0x30],this
//                              tact_art.cpp:59 (25)
//         004ccc4e     MOV        this,dword ptr [ESP + param_5]
//         004ccc52     MOV        dword ptr [ESI + 0x24],EAX
//         004ccc55     MOV        dword ptr [ESI],TRIBE_Action_Artifact::`vftable' = 004ccbd0
//         004ccc5b     MOV        word ptr [ESI + 0x4],0x6b
//         004ccc61     MOV        dword ptr [ESI + 0x20],EDX
//         004ccc64     MOV        dword ptr [ESI + 0x28],this
//                              tact_art.cpp:60 (6)
//         004ccc67     MOV        EAX,ESI
//         004ccc69     POP        ESI
//         004ccc6a     RET        0x14
//         004ccc6d     ??         90h
//         004ccc6e     NOP
//         004ccc6f     NOP
}

void TRIBE_Action_Artifact::first_in_stack(uchar param_1) {
    /* TODO: Stub */
//                              void __thiscall first_in_stack(TRIBE_Action_Artifact * this, uchar p
//              void              <VOID>         <RETURN>
//              TRIBE_Action_A    ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     004ccc70(R)
//                               ?first_in_stack@TRIBE_Action_Artifact@@UAEXE@Z               XREF[1]:     00574ec4(*)
//                               TRIBE_Action_Artifact::first_in_stack
//                              tact_art.cpp:64 (8)
//         004ccc70     MOV        AL,byte ptr [ESP + param_1]
//         004ccc74     TEST       AL,AL
//         004ccc76     JZ         LAB_004cccab
//                              tact_art.cpp:67 (7)
//         004ccc78     MOV        EAX,dword ptr [ECX + this->field16_0x10]
//         004ccc7b     TEST       EAX,EAX
//         004ccc7d     JZ         LAB_004ccc89
//                              tact_art.cpp:68 (4)
//         004ccc7f     MOV        EAX,dword ptr [this->field0_0x0]
//         004ccc81     PUSH       0x5
//                              tact_art.cpp:72 (3)
//         004ccc83     CALL       dword ptr [EAX + 0x5c]
//                              tact_art.cpp:74 (3)
//         004ccc86     RET        0x4
//                               LAB_004ccc89                                                 XREF[1]:     004ccc7d(j)
//                              tact_art.cpp:69 (17)
//         004ccc89     MOV        EDX,dword ptr [ECX + this->field32_0x20]
//         004ccc8c     MOV        EAX,0xbf800000
//         004ccc91     CMP        EDX,EAX
//         004ccc93     JZ         LAB_004ccca4
//         004ccc95     CMP        dword ptr [ECX + this->field36_0x24],EAX
//         004ccc98     JZ         LAB_004ccca4
//                              tact_art.cpp:70 (7)
//         004ccc9a     MOV        EDX,dword ptr [this->field0_0x0]
//         004ccc9c     PUSH       0x4
//         004ccc9e     CALL       dword ptr [EDX + 0x5c]
//                              tact_art.cpp:74 (3)
//         004ccca1     RET        0x4
//                               LAB_004ccca4                                                 XREF[2]:     004ccc93(j), 004ccc98(j)
//                              tact_art.cpp:72 (7)
//         004ccca4     MOV        EAX,dword ptr [this->field0_0x0]
//         004ccca6     PUSH       0x6
//         004ccca8     CALL       dword ptr [EAX + 0x5c]
//                               LAB_004cccab                                                 XREF[1]:     004ccc76(j)
//                              tact_art.cpp:74 (3)
//         004cccab     RET        0x4
//         004cccae     ??         90h
//         004cccaf     NOP
    return;
}

void TRIBE_Action_Artifact::set_state(uchar param_1) {
    /* TODO: Stub */
//                              void __thiscall set_state(TRIBE_Action_Artifact * this, uchar param_1)
//              void              <VOID>         <RETURN>
//              TRIBE_Action_A    ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[3]:     004cccbe(R), 004ccd30(W), 004ccd84(W)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     004ccd36(W), 004ccd66(W), 004ccd8a(W), 004ccdba(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     004cccf0(R), 004ccdd6(R)
//                               ?set_state@TRIBE_Action_Artifact@@MAEXE@Z                    XREF[1]:     00574f04(*)
//                               TRIBE_Action_Artifact::set_state
//                              tact_art.cpp:78 (14)
//         004cccb0     MOV        EAX,FS:[0x0]
//         004cccb6     PUSH       -0x1
//         004cccb8     PUSH       FUN_0055fd76
//         004cccbd     PUSH       EAX
//                              tact_art.cpp:82 (17)
//         004cccbe     MOV        EAX,dword ptr [ESP + param_1]
//         004cccc2     MOV        dword ptr FS:[0x0],ESP
//         004cccc9     PUSH       ESI
//         004cccca     MOV        ESI,this
//         004ccccc     MOV        byte ptr [ESI + 0xc],AL
//                              tact_art.cpp:84 (26)
//         004ccccf     AND        EAX,0xff
//         004cccd4     SUB        EAX,0x4
//         004cccd7     JZ         LAB_004ccd72
//         004cccdd     DEC        EAX
//         004cccde     JZ         LAB_004ccd02
//         004ccce0     SUB        EAX,0x5
//         004ccce3     JNZ        LAB_004ccdd6
//                              tact_art.cpp:87 (7)
//         004ccce9     MOV        dword ptr [ESI + 0x2c],0x40400000
//                              tact_art.cpp:116 (18)
//         004cccf0     MOV        this,dword ptr [ESP + local_c]
//         004cccf4     MOV        dword ptr FS:[0x0],this
//         004cccfb     POP        ESI
//         004cccfc     ADD        ESP,0xc
//         004cccff     RET        0x4
//                               LAB_004ccd02                                                 XREF[1]:     004cccde(j)
//                              tact_art.cpp:102 (8)
//         004ccd02     MOV        this,dword ptr [ESI + 0x34]
//         004ccd05     CALL       RGE_Action_List::delete_list                     void delete_list(RGE_Action_List * this)
//                              tact_art.cpp:105 (3)
//         004ccd0a     MOV        EAX,dword ptr [ESI + 0x10]
//                              tact_art.cpp:109 (87)
//         004ccd0d     PUSH       0x44
//         004ccd0f     MOV        this,dword ptr [EAX + 0x38]
//         004ccd12     MOV        dword ptr [ESI + 0x20],this
//         004ccd15     MOV        EDX,dword ptr [EAX + 0x3c]
//         004ccd18     MOV        dword ptr [ESI + 0x24],EDX
//         004ccd1b     MOV        EAX,dword ptr [EAX + 0x40]
//         004ccd1e     MOV        dword ptr [ESI + 0x28],EAX
//         004ccd21     MOV        dword ptr [ESI + 0x10],0x0
//         004ccd28     CALL       operator_new                                     void * operator_new(uint param_1)
//         004ccd2d     ADD        ESP,0x4
//         004ccd30     MOV        dword ptr [ESP + param_1],EAX
//         004ccd34     TEST       EAX,EAX
//         004ccd36     MOV        dword ptr [ESP + local_4],0x1
//         004ccd3e     JZ         LAB_004ccd62
//         004ccd40     MOV        this,dword ptr [ESI + 0x30]
//         004ccd43     MOV        EDX,dword ptr [ECX + this->field52_0x34]
//         004ccd46     MOV        this,dword ptr [ESI + 0x28]
//         004ccd49     PUSH       EDX
//         004ccd4a     MOV        EDX,dword ptr [ESI + 0x24]
//         004ccd4d     PUSH       0x0
//         004ccd4f     PUSH       this
//         004ccd50     MOV        this,dword ptr [ESI + 0x20]
//         004ccd53     PUSH       EDX
//         004ccd54     MOV        EDX,dword ptr [ESI + 0x8]
//         004ccd57     PUSH       this
//         004ccd58     PUSH       EDX
//         004ccd59     MOV        this,EAX
//         004ccd5b     CALL       RGE_Action_Move_To::RGE_Action_Move_To           undefined RGE_Action_Move_To(RGE_Action_Move_
//         004ccd60     JMP        LAB_004ccd64
//                               LAB_004ccd62                                                 XREF[1]:     004ccd3e(j)
//         004ccd62     XOR        EAX,EAX
//                               LAB_004ccd64                                                 XREF[1]:     004ccd60(j)
//                              tact_art.cpp:110 (12)
//         004ccd64     TEST       EAX,EAX
//         004ccd66     MOV        dword ptr [ESP + local_4],0xffffffff
//         004ccd6e     JZ         LAB_004ccdd6
//                              tact_art.cpp:115 (2)
//         004ccd70     JMP        LAB_004ccdc4
//                               LAB_004ccd72                                                 XREF[1]:     004cccd7(j)
//                              tact_art.cpp:91 (8)
//         004ccd72     MOV        this,dword ptr [ESI + 0x34]
//         004ccd75     CALL       RGE_Action_List::delete_list                     void delete_list(RGE_Action_List * this)
//                              tact_art.cpp:93 (62)
//         004ccd7a     PUSH       0x44
//         004ccd7c     CALL       operator_new                                     void * operator_new(uint param_1)
//         004ccd81     ADD        ESP,0x4
//         004ccd84     MOV        dword ptr [ESP + param_1],EAX
//         004ccd88     TEST       EAX,EAX
//         004ccd8a     MOV        dword ptr [ESP + local_4],0x0
//         004ccd92     JZ         LAB_004ccdb6
//         004ccd94     MOV        this,dword ptr [ESI + 0x30]
//         004ccd97     MOV        EDX,dword ptr [ECX + this->field52_0x34]
//         004ccd9a     MOV        this,dword ptr [ESI + 0x28]
//         004ccd9d     PUSH       EDX
//         004ccd9e     MOV        EDX,dword ptr [ESI + 0x24]
//         004ccda1     PUSH       0x0
//         004ccda3     PUSH       this
//         004ccda4     MOV        this,dword ptr [ESI + 0x20]
//         004ccda7     PUSH       EDX
//         004ccda8     MOV        EDX,dword ptr [ESI + 0x8]
//         004ccdab     PUSH       this
//         004ccdac     PUSH       EDX
//         004ccdad     MOV        this,EAX
//         004ccdaf     CALL       RGE_Action_Move_To::RGE_Action_Move_To           undefined RGE_Action_Move_To(RGE_Action_Move_
//         004ccdb4     JMP        LAB_004ccdb8
//                               LAB_004ccdb6                                                 XREF[1]:     004ccd92(j)
//         004ccdb6     XOR        EAX,EAX
//                               LAB_004ccdb8                                                 XREF[1]:     004ccdb4(j)
//                              tact_art.cpp:94 (12)
//         004ccdb8     TEST       EAX,EAX
//         004ccdba     MOV        dword ptr [ESP + local_4],0xffffffff
//         004ccdc2     JZ         LAB_004ccdd6
//                               LAB_004ccdc4                                                 XREF[1]:     004ccd70(j)
//                              tact_art.cpp:96 (9)
//         004ccdc4     MOV        this,dword ptr [ESI + 0x34]
//         004ccdc7     PUSH       EAX
//         004ccdc8     CALL       RGE_Action_List::add_action                      void add_action(RGE_Action_List * this, RGE_A
//                              tact_art.cpp:97 (9)
//         004ccdcd     MOV        EAX,dword ptr [ESI]
//         004ccdcf     PUSH       0x6
//         004ccdd1     MOV        this,ESI
//         004ccdd3     CALL       dword ptr [EAX + 0x5c]
//                               LAB_004ccdd6                                                 XREF[3]:     004ccce3(j), 004ccd6e(j),
//                                                                                                         004ccdc2(j)
//                              tact_art.cpp:116 (18)
//         004ccdd6     MOV        this,dword ptr [ESP + local_c]
//         004ccdda     POP        ESI
//         004ccddb     MOV        dword ptr FS:[0x0],this
//         004ccde2     ADD        ESP,0xc
//         004ccde5     RET        0x4
//         004ccde8     ??         90h
//         004ccde9     NOP
//         004ccdea     NOP
//         004ccdeb     NOP
//         004ccdec     NOP
//         004ccded     NOP
//         004ccdee     NOP
//         004ccdef     NOP
    return;
}

uchar TRIBE_Action_Artifact::update() {
    /* TODO: Stub */
//                              uchar __thiscall update(TRIBE_Action_Artifact * this)
//              uchar             AL:1           <RETURN>
//              TRIBE_Action_A    ECX:4 (auto)   this
//                               ?update@TRIBE_Action_Artifact@@UAEEXZ                        XREF[1]:     00574ed0(*)
//                               TRIBE_Action_Artifact::update
//                              tact_art.cpp:120 (4)
//         004ccdf0     PUSH       ESI
//         004ccdf1     MOV        ESI,this
//         004ccdf3     PUSH       EDI
//                              tact_art.cpp:123 (16)
//         004ccdf4     MOV        this,dword ptr [ESI + 0x34]
//         004ccdf7     MOV        EAX,dword ptr [this->field0_0x0]
//         004ccdf9     CALL       dword ptr [EAX + 0xc]
//         004ccdfc     TEST       AL,AL
//         004ccdfe     JBE        LAB_004cce0c
//         004cce00     CMP        AL,0x3
//         004cce02     JA         LAB_004cce0c
//                              tact_art.cpp:128 (8)
//         004cce04     MOV        this,dword ptr [ESI + 0x34]
//         004cce07     CALL       RGE_Action_List::delete_list                     void delete_list(RGE_Action_List * this)
//                               LAB_004cce0c                                                 XREF[2]:     004ccdfe(j), 004cce02(j)
//                              tact_art.cpp:132 (30)
//         004cce0c     XOR        EAX,EAX
//         004cce0e     MOV        AL,byte ptr [ESI + 0xc]
//         004cce11     DEC        EAX
//         004cce12     CMP        EAX,0x63
//         004cce15     JA         switchD_004cce23::caseD_2
//         004cce1b     XOR        this,this
//         004cce1d     MOV        this,byte ptr [EAX + 0x4ccecc]=>PTR_caseD_2_00
//                               switchD_004cce23::switchD
//         004cce23     JMP        dword ptr [this->field0_0x0*0x4 + switchD_004c   = 004ccead
//                               switchD_004cce23::caseD_a                                    XREF[2]:     004cce23(j), 004ccec0(*)
//                              tact_art.cpp:135 (18)
//         004cce2a     MOV        EDX,dword ptr [ESI + 0x8]
//         004cce2d     FLD        float ptr [ESI + 0x2c]
//         004cce30     MOV        EAX,dword ptr [EDX + 0xc]
//         004cce33     MOV        this,dword ptr [EAX + 0x3c]
//         004cce36     FSUB       float ptr [this->field0_0x0 + 0x84]
//                              tact_art.cpp:136 (16)
//         004cce3c     FCOM       double ptr [DAT_00574f08]                        = align(10)
//         004cce42     FSTP       float ptr [ESI + 0x2c]
//         004cce45     FNSTSW     AX
//         004cce47     TEST       AH,0x41
//         004cce4a     JZ         switchD_004cce23::caseD_2
//                              tact_art.cpp:137 (9)
//         004cce4c     MOV        EDX,dword ptr [ESI]
//         004cce4e     PUSH       0x6
//         004cce50     MOV        this,ESI
//         004cce52     CALL       dword ptr [EDX + 0x5c]
//                              tact_art.cpp:163 (2)
//         004cce55     XOR        AL,AL
//                              tact_art.cpp:164 (3)
//         004cce57     POP        EDI
//         004cce58     POP        ESI
//         004cce59     RET
//                               switchD_004cce23::caseD_6                                    XREF[2]:     004cce23(j), 004ccebc(*)
//                              tact_art.cpp:141 (9)
//         004cce5a     MOV        this,ESI
//         004cce5c     CALL       TRIBE_Action_Artifact::check_ownership           RGE_Player * check_ownership(TRIBE_Action_Art
//         004cce61     MOV        EDI,EAX
//                              tact_art.cpp:142 (4)
//         004cce63     TEST       EDI,EDI
//         004cce65     JZ         LAB_004cce7d
//                              tact_art.cpp:145 (8)
//         004cce67     MOV        this,dword ptr [ESI + 0x34]
//         004cce6a     CALL       RGE_Action_List::delete_list                     void delete_list(RGE_Action_List * this)
//                              tact_art.cpp:147 (9)
//         004cce6f     MOV        this,dword ptr [ESI + 0x8]
//         004cce72     PUSH       EDI
//         004cce73     MOV        EAX,dword ptr [this->field0_0x0]
//         004cce75     CALL       dword ptr [EAX + 0x44]
//                              tact_art.cpp:163 (2)
//         004cce78     XOR        AL,AL
//                              tact_art.cpp:164 (3)
//         004cce7a     POP        EDI
//         004cce7b     POP        ESI
//         004cce7c     RET
//                               LAB_004cce7d                                                 XREF[1]:     004cce65(j)
//                              tact_art.cpp:151 (9)
//         004cce7d     MOV        EDX,dword ptr [ESI]
//         004cce7f     PUSH       0xa
//         004cce81     MOV        this,ESI
//         004cce83     CALL       dword ptr [EDX + 0x5c]
//                              tact_art.cpp:163 (2)
//         004cce86     XOR        AL,AL
//                              tact_art.cpp:164 (3)
//         004cce88     POP        EDI
//         004cce89     POP        ESI
//         004cce8a     RET
//                               switchD_004cce23::caseD_64                                   XREF[2]:     004cce23(j), 004ccec4(*)
//                              tact_art.cpp:155 (20)
//         004cce8b     MOV        this,dword ptr [ESI + 0x8]
//         004cce8e     MOV        EDX,dword ptr [ECX + this->field12_0xc]
//         004cce91     MOV        EAX,dword ptr [this->field0_0x0]
//         004cce93     MOV        EDX,dword ptr [EDX + 0x3c]
//         004cce96     MOV        EDX,dword ptr [EDX + 0x40]
//         004cce99     MOV        EDX,dword ptr [EDX]
//         004cce9b     PUSH       EDX
//         004cce9c     CALL       dword ptr [EAX + 0x44]
//                              tact_art.cpp:156 (9)
//         004cce9f     MOV        EAX,dword ptr [ESI]
//         004ccea1     PUSH       0x6
//         004ccea3     MOV        this,ESI
//         004ccea5     CALL       dword ptr [EAX + 0x5c]
//                              tact_art.cpp:163 (2)
//         004ccea8     XOR        AL,AL
//                              tact_art.cpp:164 (3)
//         004cceaa     POP        EDI
//         004cceab     POP        ESI
//         004cceac     RET
//                               switchD_004cce23::caseD_1                                    XREF[2]:     004cce23(j), 004cceb8(*)
//                              tact_art.cpp:160 (2)
//         004ccead     MOV        AL,0x1
//                              tact_art.cpp:164 (129)
//         004cceaf     POP        EDI
//         004cceb0     POP        ESI
//         004cceb1     RET
//                               switchD_004cce23::caseD_3                                    XREF[4]:     004cce15(j), 004cce23(j),
//                               switchD_004cce23::caseD_4                                                 004cce4a(j), 004ccec8(*)
//                               switchD_004cce23::caseD_5
//                               switchD_004cce23::caseD_7
//                               switchD_004cce23::caseD_8
//                               switchD_004cce23::caseD_9
//                               switchD_004cce23::caseD_b
//                               switchD_004cce23::caseD_c
//                               switchD_004cce23::caseD_d
//                               switchD_004cce23::caseD_e
//                               switchD_004cce23::caseD_f
//                               switchD_004cce23::caseD_10
//                               switchD_004cce23::caseD_11
//                               switchD_004cce23::caseD_12
//                               switchD_004cce23::caseD_13
//                               switchD_004cce23::caseD_14
//                               switchD_004cce23::caseD_15
//                               switchD_004cce23::caseD_16
//                               switchD_004cce23::caseD_17
//                               switchD_004cce23::caseD_18
//                               switchD_004cce23::caseD_19
//                               switchD_004cce23::caseD_1a
//                               switchD_004cce23::caseD_1b
//                               switchD_004cce23::caseD_1c
//                               switchD_004cce23::caseD_1d
//                               switchD_004cce23::caseD_1e
//                               switchD_004cce23::caseD_1f
//                               switchD_004cce23::caseD_20
//                               switchD_004cce23::caseD_21
//                               switchD_004cce23::caseD_22
//                               switchD_004cce23::caseD_23
//                               switchD_004cce23::caseD_24
//                               switchD_004cce23::caseD_25
//                               switchD_004cce23::caseD_26
//                               switchD_004cce23::caseD_27
//                               switchD_004cce23::caseD_28
//                               switchD_004cce23::caseD_29
//                               switchD_004cce23::caseD_2a
//                               switchD_004cce23::caseD_2b
//                               switchD_004cce23::caseD_2c
//                               switchD_004cce23::caseD_2d
//                               switchD_004cce23::caseD_2e
//                               switchD_004cce23::caseD_2f
//                               switchD_004cce23::caseD_30
//                               switchD_004cce23::caseD_31
//                               switchD_004cce23::caseD_32
//                               switchD_004cce23::caseD_33
//                               switchD_004cce23::caseD_34
//                               switchD_004cce23::caseD_35
//                               switchD_004cce23::caseD_36
//                               switchD_004cce23::caseD_37
//                               switchD_004cce23::caseD_38
//                               switchD_004cce23::caseD_39
//                               switchD_004cce23::caseD_3a
//                               switchD_004cce23::caseD_3b
//                               switchD_004cce23::caseD_3c
//                               switchD_004cce23::caseD_3d
//                               switchD_004cce23::caseD_3e
//                               switchD_004cce23::caseD_3f
//                               switchD_004cce23::caseD_40
//                               switchD_004cce23::caseD_41
//                               switchD_004cce23::caseD_42
//                               switchD_004cce23::caseD_43
//                               switchD_004cce23::caseD_44
//                               switchD_004cce23::caseD_45
//                               switchD_004cce23::caseD_46
//                               switchD_004cce23::caseD_47
//                               switchD_004cce23::caseD_48
//                               switchD_004cce23::caseD_49
//                               switchD_004cce23::caseD_4a
//                               switchD_004cce23::caseD_4b
//                               switchD_004cce23::caseD_4c
//                               switchD_004cce23::caseD_4d
//                               switchD_004cce23::caseD_4e
//                               switchD_004cce23::caseD_4f
//                               switchD_004cce23::caseD_50
//                               switchD_004cce23::caseD_51
//                               switchD_004cce23::caseD_52
//                               switchD_004cce23::caseD_53
//                               switchD_004cce23::caseD_54
//                               switchD_004cce23::caseD_55
//                               switchD_004cce23::caseD_56
//                               switchD_004cce23::caseD_57
//                               switchD_004cce23::caseD_58
//                               switchD_004cce23::caseD_59
//                               switchD_004cce23::caseD_5a
//                               switchD_004cce23::caseD_5b
//                               switchD_004cce23::caseD_5c
//                               switchD_004cce23::caseD_5d
//                               switchD_004cce23::caseD_5e
//                               switchD_004cce23::caseD_5f
//                               switchD_004cce23::caseD_60
//                               switchD_004cce23::caseD_61
//                               switchD_004cce23::caseD_62
//                               switchD_004cce23::caseD_63
//                               switchD_004cce23::caseD_2
//         004cceb2     POP        EDI
//         004cceb3     XOR        AL,AL
//         004cceb5     POP        ESI
//         004cceb6     RET
//         004cceb7     ??         90h
//                              Symbol Ref: No symbol: NONAME
//                               switchD_004cce23::switchdataD_004cceb8                       XREF[1]:     update:004cce23(*)
//         004cceb8     addr       switchD_004cce23::caseD_1
//         004ccebc     addr       switchD_004cce23::caseD_6
//         004ccec0     addr       switchD_004cce23::caseD_a
//         004ccec4     addr       switchD_004cce23::caseD_64
//                               PTR_caseD_2_004ccec8+3                                       XREF[0,1]:   update:004cce1d(*)
//         004ccec8     addr       switchD_004cce23::caseD_2
//                              Symbol Ref: No symbol: NONAME
//                               switchD_004cce23::switchdataD_004ccecc
//         004ccecc     db         0h
//         004ccecd     db         4h
//         004ccece     db         4h
//         004ccecf     db         4h
//         004cced0     db         4h
//         004cced1     db         1h
//         004cced2     db         4h
//         004cced3     db         4h
//         004cced4     db         4h
//         004cced5     db         2h
//         004cced6     db         4h
//         004cced7     db         4h
//         004cced8     db         4h
//         004cced9     db         4h
//         004cceda     db         4h
//         004ccedb     db         4h
//         004ccedc     db         4h
//         004ccedd     db         4h
//         004ccede     db         4h
//         004ccedf     db         4h
//         004ccee0     db         4h
//         004ccee1     db         4h
//         004ccee2     db         4h
//         004ccee3     db         4h
//         004ccee4     db         4h
//         004ccee5     db         4h
//         004ccee6     db         4h
//         004ccee7     db         4h
//         004ccee8     db         4h
//         004ccee9     db         4h
//         004cceea     db         4h
//         004cceeb     db         4h
//         004cceec     db         4h
//         004cceed     db         4h
//         004cceee     db         4h
//         004cceef     db         4h
//         004ccef0     db         4h
//         004ccef1     db         4h
//         004ccef2     db         4h
//         004ccef3     db         4h
//         004ccef4     db         4h
//         004ccef5     db         4h
//         004ccef6     db         4h
//         004ccef7     db         4h
//         004ccef8     db         4h
//         004ccef9     db         4h
//         004ccefa     db         4h
//         004ccefb     db         4h
//         004ccefc     db         4h
//         004ccefd     db         4h
//         004ccefe     db         4h
//         004cceff     db         4h
//         004ccf00     db         4h
//         004ccf01     db         4h
//         004ccf02     db         4h
//         004ccf03     db         4h
//         004ccf04     db         4h
//         004ccf05     db         4h
//         004ccf06     db         4h
//         004ccf07     db         4h
//         004ccf08     db         4h
//         004ccf09     db         4h
//         004ccf0a     db         4h
//         004ccf0b     db         4h
//         004ccf0c     db         4h
//         004ccf0d     db         4h
//         004ccf0e     db         4h
//         004ccf0f     db         4h
//         004ccf10     db         4h
//         004ccf11     db         4h
//         004ccf12     db         4h
//         004ccf13     db         4h
//         004ccf14     db         4h
//         004ccf15     db         4h
//         004ccf16     db         4h
//         004ccf17     db         4h
//         004ccf18     db         4h
//         004ccf19     db         4h
//         004ccf1a     db         4h
//         004ccf1b     db         4h
//         004ccf1c     db         4h
//         004ccf1d     db         4h
//         004ccf1e     db         4h
//         004ccf1f     db         4h
//         004ccf20     db         4h
//         004ccf21     db         4h
//         004ccf22     db         4h
//         004ccf23     db         4h
//         004ccf24     db         4h
//         004ccf25     db         4h
//         004ccf26     db         4h
//         004ccf27     db         4h
//         004ccf28     db         4h
//         004ccf29     db         4h
//         004ccf2a     db         4h
//         004ccf2b     db         4h
//         004ccf2c     db         4h
//         004ccf2d     db         4h
//         004ccf2e     db         4h
//         004ccf2f     db         3h
    return 0;
}

RGE_Player* TRIBE_Action_Artifact::check_ownership() {
    /* TODO: Stub */
//                              RGE_Player * __thiscall check_ownership(TRIBE_Action_Artifact * this)
//              RGE_Player *      EAX:4          <RETURN>
//              TRIBE_Action_A    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004ccf3a(W), 004cd0f1(R)
//              undefined4        Stack[-0x8]:4  local_8                   XREF[3]:     004ccfa8(W), 004ccfb4(R), 004cd0b8(R)
//              short             Stack[-0xc]:2  player_num                XREF[3]:     004ccfbc(W), 004cd089(R), 004cd0b4(R)
//              uchar *           Stack[-0x10]:4 player_list               XREF[6]:     004ccfa4(W), 004ccfd4(R), 004cd02f(W), 004cd052(R),
//                                                                                     004cd0a6(R), 004cd0ae(W)
//              RGE_Map *         Stack[-0x14]:4 map                       XREF[5]:     004ccf5b(W), 004ccfd8(R), 004ccfe0(W), 004cd02b(R),
//                                                                                     004cd0a2(R)
//              short             Stack[-0x18]:2 x0                        XREF[5]:     004ccf80(W), 004ccfef(R), 004ccfff(W), 004cd033(R),
//                                                                                     004cd09e(R)
//              short             Stack[-0x1c]:2 x1
//                               ?check_ownership@TRIBE_Action_Artifact@@IAEPAVRGE_Player@@XZ XREF[1]:     update:004cce5c(c)
//                               TRIBE_Action_Artifact::check_ownership
//                              tact_art.cpp:168 (6)
//         004ccf30     SUB        ESP,0x18
//         004ccf33     PUSH       EBX
//         004ccf34     PUSH       EBP
//         004ccf35     PUSH       ESI
//                              tact_art.cpp:169 (28)
//         004ccf36     MOV        ESI,dword ptr [ECX + this->field8_0x8]
//         004ccf39     PUSH       EDI
//         004ccf3a     MOV        dword ptr [ESP + local_4],this
//         004ccf3e     FLD        float ptr [ESI + 0x38]
//         004ccf41     FSUB       float ptr [null_00574f10]                        = align(2)
//         004ccf47     MOV        EDI,dword ptr [ESI + 0x8]
//         004ccf4a     FSUB       float ptr [EDI + 0x30]
//         004ccf4d     CALL       __ftol                                           undefined __ftol()
//                              tact_art.cpp:170 (21)
//         004ccf52     FLD        float ptr [ESI + 0x3c]
//         004ccf55     FSUB       float ptr [null_00574f10]                        = align(2)
//         004ccf5b     MOV        dword ptr [ESP + map],EAX
//         004ccf5f     FSUB       float ptr [EDI + 0x34]
//         004ccf62     CALL       __ftol                                           undefined __ftol()
//                              tact_art.cpp:171 (19)
//         004ccf67     FLD        float ptr [EDI + 0x30]
//         004ccf6a     FADD       float ptr [ESI + 0x38]
//         004ccf6d     MOV        EBP,EAX
//         004ccf6f     FSUB       float ptr [DAT_00574f14]
//         004ccf75     CALL       __ftol                                           undefined __ftol()
//                              tact_art.cpp:172 (23)
//         004ccf7a     FLD        float ptr [EDI + 0x34]
//         004ccf7d     FADD       float ptr [ESI + 0x3c]
//         004ccf80     MOV        dword ptr [ESP + x0],EAX
//         004ccf84     FSUB       float ptr [DAT_00574f14]
//         004ccf8a     CALL       __ftol                                           undefined __ftol()
//         004ccf8f     MOV        EBX,EAX
//                              tact_art.cpp:181 (3)
//         004ccf91     MOV        EAX,dword ptr [ESI + 0xc]
//                              tact_art.cpp:185 (32)
//         004ccf94     PUSH       0x1
//         004ccf96     MOV        EAX,dword ptr [EAX + 0x3c]
//         004ccf99     MOV        EDI,dword ptr [EAX + 0x28]
//         004ccf9c     MOV        AX,word ptr [EAX + 0x3c]
//         004ccfa0     MOVSX      ESI,AX
//         004ccfa3     PUSH       ESI
//         004ccfa4     MOV        dword ptr [ESP + player_list],EDI
//         004ccfa8     MOV        dword ptr [ESP + local_8],EAX
//         004ccfac     CALL       calloc                                           undefined calloc()
//         004ccfb1     ADD        ESP,0x8
//                              tact_art.cpp:186 (36)
//         004ccfb4     CMP        word ptr [ESP + local_8],0x0
//         004ccfba     MOV        EDX,EAX
//         004ccfbc     MOV        dword ptr [ESP + player_num],EDX
//         004ccfc0     JLE        LAB_004ccfd8
//         004ccfc2     MOV        this,ESI
//         004ccfc4     XOR        EAX,EAX
//         004ccfc6     MOV        EDI,EDX
//         004ccfc8     SHR        this,0x2
//         004ccfcb     STOSD.REP  ES:EDI
//         004ccfcd     MOV        this,ESI
//         004ccfcf     AND        this,0x3
//         004ccfd2     STOSB.REP  ES:EDI
//         004ccfd4     MOV        EDI,dword ptr [ESP + player_list]
//                               LAB_004ccfd8                                                 XREF[1]:     004ccfc0(j)
//                              tact_art.cpp:189 (16)
//         004ccfd8     CMP        word ptr [ESP + map],0x0
//         004ccfde     JGE        LAB_004ccfe8
//         004ccfe0     MOV        dword ptr [ESP + map],0x0
//                               LAB_004ccfe8                                                 XREF[1]:     004ccfde(j)
//                              tact_art.cpp:190 (7)
//         004ccfe8     TEST       BP,BP
//         004ccfeb     JGE        LAB_004ccfef
//         004ccfed     XOR        EBP,EBP
//                               LAB_004ccfef                                                 XREF[1]:     004ccfeb(j)
//                              tact_art.cpp:191 (20)
//         004ccfef     MOVSX      this,word ptr [ESP + x0]
//         004ccff4     CMP        this,dword ptr [EDI + 0x8]
//         004ccff7     JL         LAB_004cd003
//         004ccff9     MOV        AX,word ptr [EDI + 0x8]
//         004ccffd     DEC        AX
//         004ccfff     MOV        dword ptr [ESP + x0],EAX
//                               LAB_004cd003                                                 XREF[1]:     004ccff7(j)
//                              tact_art.cpp:192 (16)
//         004cd003     MOV        this,dword ptr [EDI + 0xc]
//         004cd006     MOVSX      EAX,BX
//         004cd009     CMP        EAX,this
//         004cd00b     JL         LAB_004cd013
//         004cd00d     MOV        BX,word ptr [EDI + 0xc]
//         004cd011     DEC        BX
//                               LAB_004cd013                                                 XREF[1]:     004cd00b(j)
//                              tact_art.cpp:196 (37)
//         004cd013     CMP        BP,BX
//         004cd016     JG         LAB_004cd0b8
//         004cd01c     MOVSX      EAX,BP
//         004cd01f     MOVSX      EBX,BX
//         004cd022     LEA        this,[EAX*0x4 + 0x0]
//         004cd029     SUB        EBX,EAX
//         004cd02b     MOV        EAX,dword ptr [ESP + map]
//         004cd02f     MOV        dword ptr [ESP + player_list],this
//         004cd033     MOV        this,dword ptr [ESP + x0]
//         004cd037     INC        EBX
//                               LAB_004cd038                                                 XREF[1]:     004cd0b2(j)
//                              tact_art.cpp:197 (20)
//         004cd038     CMP        AX,this
//         004cd03b     JG         LAB_004cd0a6
//         004cd03d     MOVSX      EAX,AX
//         004cd040     MOVSX      EBP,this
//         004cd043     LEA        ESI,[EAX + EAX*0x2]
//         004cd046     SUB        EBP,EAX
//         004cd048     SHL        ESI,0x3
//         004cd04b     INC        EBP
//                               LAB_004cd04c                                                 XREF[1]:     004cd09c(j)
//                              tact_art.cpp:198 (21)
//         004cd04c     MOV        EDX,dword ptr [EDI + 0x8d8c]
//         004cd052     MOV        EAX,dword ptr [ESP + player_list]
//         004cd056     MOV        this,dword ptr [EAX + EDX*0x1]
//         004cd059     MOV        EDX,dword ptr [ECX + ESI*0x1 + this->field16_0
//         004cd05d     TEST       EDX,EDX
//         004cd05f     JZ         LAB_004cd098
//                               LAB_004cd061                                                 XREF[1]:     004cd096(j)
//                              tact_art.cpp:202 (33)
//         004cd061     MOV        this,dword ptr [EDX]
//         004cd063     MOV        EAX,dword ptr [ECX + this->field8_0x8]
//         004cd066     MOV        AX,word ptr [EAX + 0x14]
//         004cd06a     CMP        AX,0x1
//         004cd06e     JZ         LAB_004cd091
//         004cd070     CMP        AX,0xb
//         004cd074     JZ         LAB_004cd091
//         004cd076     CMP        AX,0x1e
//         004cd07a     JZ         LAB_004cd091
//         004cd07c     CMP        byte ptr [this->field0_0x0 + 0x48],0x2
//         004cd080     JNZ        LAB_004cd091
//                              tact_art.cpp:203 (22)
//         004cd082     MOV        this,dword ptr [ECX + this->field12_0xc]
//         004cd085     MOVSX      EAX,word ptr [this->field0_0x0 + 0x4a]
//         004cd089     MOV        this,dword ptr [ESP + player_num]
//         004cd08d     ADD        EAX,this
//         004cd08f     INC        byte ptr [EAX]
//                               LAB_004cd091                                                 XREF[4]:     004cd06e(j), 004cd074(j),
//                                                                                                         004cd07a(j), 004cd080(j)
//         004cd091     MOV        EDX,dword ptr [EDX + 0x4]
//         004cd094     TEST       EDX,EDX
//         004cd096     JNZ        LAB_004cd061
//                               LAB_004cd098                                                 XREF[1]:     004cd05f(j)
//                              tact_art.cpp:197 (28)
//         004cd098     ADD        ESI,0x18
//         004cd09b     DEC        EBP
//         004cd09c     JNZ        LAB_004cd04c
//         004cd09e     MOV        this,dword ptr [ESP + x0]
//         004cd0a2     MOV        EAX,dword ptr [ESP + map]
//                               LAB_004cd0a6                                                 XREF[1]:     004cd03b(j)
//         004cd0a6     MOV        ESI,dword ptr [ESP + player_list]
//         004cd0aa     ADD        ESI,0x4
//         004cd0ad     DEC        EBX
//         004cd0ae     MOV        dword ptr [ESP + player_list],ESI
//         004cd0b2     JNZ        LAB_004cd038
//                              tact_art.cpp:196 (4)
//         004cd0b4     MOV        EDX,dword ptr [ESP + player_num]
//                               LAB_004cd0b8                                                 XREF[1]:     004cd016(j)
//                              tact_art.cpp:208 (19)
//         004cd0b8     MOV        EDI,dword ptr [ESP + local_8]
//         004cd0bc     MOV        EAX,0x1
//         004cd0c1     OR         ESI,0xffffffff
//         004cd0c4     XOR        EBX,EBX
//         004cd0c6     CMP        DI,AX
//         004cd0c9     JLE        LAB_004cd0dd
//                              tact_art.cpp:206 (3)
//         004cd0cb     LEA        this,[EDX + 0x1]
//                               LAB_004cd0ce                                                 XREF[1]:     004cd0db(j)
//                              tact_art.cpp:209 (5)
//         004cd0ce     CMP        byte ptr [this->field0_0x0],0x0
//         004cd0d1     JBE        LAB_004cd0d6
//                              tact_art.cpp:211 (1)
//         004cd0d3     INC        EBX
//                              tact_art.cpp:212 (9)
//         004cd0d4     MOV        ESI,EAX
//                               LAB_004cd0d6                                                 XREF[1]:     004cd0d1(j)
//         004cd0d6     INC        EAX
//         004cd0d7     INC        this
//         004cd0d8     CMP        AX,DI
//         004cd0db     JL         LAB_004cd0ce
//                               LAB_004cd0dd                                                 XREF[1]:     004cd0c9(j)
//                              tact_art.cpp:215 (9)
//         004cd0dd     PUSH       EDX
//         004cd0de     CALL       free                                             undefined free()
//         004cd0e3     ADD        ESP,0x4
//                              tact_art.cpp:218 (27)
//         004cd0e6     CMP        BX,0x1
//         004cd0ea     JNZ        LAB_004cd115
//         004cd0ec     TEST       SI,SI
//         004cd0ef     JLE        LAB_004cd115
//         004cd0f1     MOV        EDX,dword ptr [ESP + local_4]
//         004cd0f5     MOV        EAX,dword ptr [EDX + 0x8]
//         004cd0f8     MOV        EAX,dword ptr [EAX + 0xc]
//         004cd0fb     CMP        SI,word ptr [EAX + 0x4a]
//         004cd0ff     JZ         LAB_004cd115
//                              tact_art.cpp:220 (12)
//         004cd101     MOV        this,dword ptr [EAX + 0x3c]
//         004cd104     MOVSX      EDX,SI
//         004cd107     MOV        EAX,dword ptr [ECX + this+0x40]
//         004cd10a     MOV        EAX,dword ptr [EAX + EDX*0x4]
//                              tact_art.cpp:224 (18)
//         004cd10d     POP        EDI
//         004cd10e     POP        ESI
//         004cd10f     POP        EBP
//         004cd110     POP        EBX
//         004cd111     ADD        ESP,0x18
//         004cd114     RET
//                               LAB_004cd115                                                 XREF[3]:     004cd0ea(j), 004cd0ef(j),
//                                                                                                         004cd0ff(j)
//         004cd115     POP        EDI
//         004cd116     POP        ESI
//         004cd117     POP        EBP
//         004cd118     XOR        EAX,EAX
//         004cd11a     POP        EBX
//         004cd11b     ADD        ESP,0x18
//         004cd11e     RET
//         004cd11f     ??         90h
    return 0;
}

int TRIBE_Action_Artifact::stop() {
    /* TODO: Stub */
//                              int __thiscall stop(TRIBE_Action_Artifact * this)
//              int               EAX:4          <RETURN>
//              TRIBE_Action_A    ECX:4 (auto)   this
//                               ?stop@TRIBE_Action_Artifact@@MAEHXZ                          XREF[1]:     00574ed4(*)
//                               TRIBE_Action_Artifact::stop
//                              tact_art.cpp:228 (7)
//         004cd120     MOV        EAX,dword ptr [this->field0_0x0]
//         004cd122     PUSH       0x6
//         004cd124     CALL       dword ptr [EAX + 0x5c]
//                              tact_art.cpp:230 (5)
//         004cd127     MOV        EAX,0x1
//                              tact_art.cpp:231 (1)
//         004cd12c     RET
//         004cd12d     ??         90h
//         004cd12e     NOP
//         004cd12f     NOP
    return 0;
}

int TRIBE_Action_Artifact::move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    /* TODO: Stub */
//                              int __thiscall move_to(TRIBE_Action_Artifact * this, RGE_Static_Obje
//              int               EAX:4          <RETURN>
//              TRIBE_Action_A    ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1
//              float             Stack[0x8]:4   param_2                   XREF[1]:     004cd130(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     004cd134(R)
//              float             Stack[0x10]:4  param_4                   XREF[1]:     004cd13b(R)
//                               ?move_to@TRIBE_Action_Artifact@@MAEHPAVRGE_Static_Object@@M  XREF[1]:     00574ed8(*)
//                               TRIBE_Action_Artifact::move_to
//                              tact_art.cpp:235 (4)
//         004cd130     MOV        EAX,dword ptr [ESP + param_2]
//                              tact_art.cpp:237 (7)
//         004cd134     MOV        EDX,dword ptr [ESP + param_3]
//         004cd138     MOV        dword ptr [ECX + this->field32_0x20],EAX
//                              tact_art.cpp:238 (7)
//         004cd13b     MOV        EAX,dword ptr [ESP + param_4]
//         004cd13f     MOV        dword ptr [ECX + this->field36_0x24],EDX
//                              tact_art.cpp:239 (10)
//         004cd142     MOV        EDX,dword ptr [this->field0_0x0]
//         004cd144     PUSH       0x4
//         004cd146     MOV        dword ptr [ECX + this->field40_0x28],EAX
//         004cd149     CALL       dword ptr [EDX + 0x5c]
//                              tact_art.cpp:240 (5)
//         004cd14c     MOV        EAX,0x1
//                              tact_art.cpp:241 (3)
//         004cd151     RET        0x10
//         004cd154     ??         90h
//         004cd155     NOP
//         004cd156     NOP
//         004cd157     NOP
//         004cd158     NOP
//         004cd159     NOP
//         004cd15a     NOP
//         004cd15b     NOP
//         004cd15c     NOP
//         004cd15d     NOP
//         004cd15e     NOP
//         004cd15f     NOP
    return 0;
}

int TRIBE_Action_Artifact::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    /* TODO: Stub */
//                              int __thiscall work(TRIBE_Action_Artifact * this, RGE_Static_Object
//              int               EAX:4          <RETURN>
//              TRIBE_Action_A    ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004cd160(R)
//              float             Stack[0x8]:4   param_2                   XREF[1]:     004cd17a(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     004cd17e(R)
//              float             Stack[0x10]:4  param_4                   XREF[1]:     004cd185(R)
//                               ?work@TRIBE_Action_Artifact@@MAEHPAVRGE_Static_Object@@MMM@Z XREF[1]:     00574edc(*)
//                               TRIBE_Action_Artifact::work
//                              tact_art.cpp:245 (8)
//         004cd160     MOV        EAX,dword ptr [ESP + param_1]
//         004cd164     TEST       EAX,EAX
//         004cd166     JZ         LAB_004cd17a
//                              tact_art.cpp:248 (3)
//         004cd168     MOV        dword ptr [ECX + this->field16_0x10],EAX
//                              tact_art.cpp:249 (4)
//         004cd16b     MOV        EAX,dword ptr [this->field0_0x0]
//         004cd16d     PUSH       0x5
//                              tact_art.cpp:256 (3)
//         004cd16f     CALL       dword ptr [EAX + 0x5c]
//                              tact_art.cpp:258 (5)
//         004cd172     MOV        EAX,0x1
//                              tact_art.cpp:259 (3)
//         004cd177     RET        0x10
//                               LAB_004cd17a                                                 XREF[1]:     004cd166(j)
//                              tact_art.cpp:253 (4)
//         004cd17a     MOV        EDX,dword ptr [ESP + param_2]
//                              tact_art.cpp:254 (7)
//         004cd17e     MOV        EAX,dword ptr [ESP + param_3]
//         004cd182     MOV        dword ptr [ECX + this->field32_0x20],EDX
//                              tact_art.cpp:255 (7)
//         004cd185     MOV        EDX,dword ptr [ESP + param_4]
//         004cd189     MOV        dword ptr [ECX + this->field36_0x24],EAX
//                              tact_art.cpp:256 (10)
//         004cd18c     MOV        EAX,dword ptr [this->field0_0x0]
//         004cd18e     PUSH       0x4
//         004cd190     MOV        dword ptr [ECX + this->field40_0x28],EDX
//         004cd193     CALL       dword ptr [EAX + 0x5c]
//                              tact_art.cpp:258 (5)
//         004cd196     MOV        EAX,0x1
//                              tact_art.cpp:259 (3)
//         004cd19b     RET        0x10
//         004cd19e     ??         90h
//         004cd19f     NOP
    return 0;
}

void TRIBE_Action_Artifact::reset_owner() {
    /* TODO: Stub */
//                              void __thiscall reset_owner(TRIBE_Action_Artifact * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Action_A    ECX:4 (auto)   this
//                               ?reset_owner@TRIBE_Action_Artifact@@QAEXXZ
//                               TRIBE_Action_Artifact::reset_owner
//                              tact_art.cpp:263 (7)
//         004cd1a0     MOV        EAX,dword ptr [this->field0_0x0]
//         004cd1a2     PUSH       0x64
//         004cd1a4     CALL       dword ptr [EAX + 0x5c]
//                              tact_art.cpp:265 (1)
//         004cd1a7     RET
//         004cd1a8     ??         90h
//         004cd1a9     NOP
//         004cd1aa     NOP
//         004cd1ab     NOP
//         004cd1ac     NOP
//         004cd1ad     NOP
//         004cd1ae     NOP
//         004cd1af     NOP
    return;
}

TRIBE_Action_Artifact::~TRIBE_Action_Artifact() {
    /* TODO: Stub */
//                              void __thiscall ~TRIBE_Action_Artifact(TRIBE_Action_Artifact * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Action_A    ECX:4 (auto)   this
//                               ??1TRIBE_Action_Artifact@@UAE@XZ                             XREF[1]:     `vector_deleting_destructor':004cc
//                               TRIBE_Action_Artifact::~TRIBE_Action_Artifact
//         004ccbf0     JMP        RGE_Action::~RGE_Action
//         004ccbf5     ??         90h
//         004ccbf6     NOP
//         004ccbf7     NOP
//         004ccbf8     NOP
//         004ccbf9     NOP
//         004ccbfa     NOP
//         004ccbfb     NOP
//         004ccbfc     NOP
//         004ccbfd     NOP
//         004ccbfe     NOP
//         004ccbff     NOP
}

