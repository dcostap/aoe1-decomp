#include "../common.h"
#include "tact_cnv.h"

TRIBE_Action_Convert::TRIBE_Action_Convert(int param_1, RGE_Action_Object* param_2) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Action_Convert(TRIBE_Action_Convert * thi
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Action_C    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004cd9fd(R)
//              RGE_Action_Obj    Stack[0x8]:4   param_2                   XREF[1]:     004cd9f6(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004cda1a(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004cda45(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004cda07(W)
//                               ??0TRIBE_Action_Convert@@QAE@HPAVRGE_Action_Object@@@Z       XREF[1]:     create_action:004d0293(c)
//                               TRIBE_Action_Convert::TRIBE_Action_Convert
//                              tact_cnv.cpp:48 (48)
//         004cd9e0     PUSH       -0x1
//         004cd9e2     PUSH       FUN_0055fdc8
//         004cd9e7     MOV        EAX,FS:[0x0]
//         004cd9ed     PUSH       EAX
//         004cd9ee     MOV        dword ptr FS:[0x0],ESP
//         004cd9f5     PUSH       this
//         004cd9f6     MOV        EAX,dword ptr [ESP + param_2]
//         004cd9fa     PUSH       EBX
//         004cd9fb     PUSH       ESI
//         004cd9fc     PUSH       EDI
//         004cd9fd     MOV        EDI,dword ptr [ESP + param_1]
//         004cda01     PUSH       0x1
//         004cda03     MOV        ESI,this
//         004cda05     PUSH       EAX
//         004cda06     PUSH       EDI
//         004cda07     MOV        dword ptr [ESP + local_10],ESI
//         004cda0b     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, int p
//                              tact_cnv.cpp:50 (44)
//         004cda10     LEA        this,[ESI + 0x40]
//         004cda13     LEA        EBX,[ESI + 0x44]
//         004cda16     PUSH       0x1
//         004cda18     PUSH       this
//         004cda19     PUSH       EDI
//         004cda1a     MOV        dword ptr [ESP + local_4],0x0
//         004cda22     MOV        dword ptr [EBX],0x3f800000
//         004cda28     MOV        dword ptr [ESI],TRIBE_Action_Convert::`vftable'  = 004cda60
//                              language.dll match for 0x68: "Arial"
//         004cda2e     MOV        word ptr [ESI + 0x4],0x68
//         004cda34     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         004cda39     ADD        ESP,0xc
//                              tact_cnv.cpp:51 (9)
//         004cda3c     PUSH       0x4
//         004cda3e     PUSH       EBX
//         004cda3f     PUSH       EDI
//         004cda40     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              tact_cnv.cpp:52 (25)
//         004cda45     MOV        this,dword ptr [ESP + local_c]
//         004cda49     ADD        ESP,0xc
//         004cda4c     MOV        EAX,ESI
//         004cda4e     MOV        dword ptr FS:[0x0],this
//         004cda55     POP        EDI
//         004cda56     POP        ESI
//         004cda57     POP        EBX
//         004cda58     ADD        ESP,0x10
//         004cda5b     RET        0x8
//         004cda5e     ??         90h
//         004cda5f     NOP
}

TRIBE_Action_Convert::TRIBE_Action_Convert(RGE_Action_Object* param_1, RGE_Task* param_2, RGE_Static_Object* param_3) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Action_Convert(TRIBE_Action_Convert * thi
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Action_C    ECX:4 (auto)   this
//              RGE_Action_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004cdaa6(R)
//              RGE_Task *        Stack[0x8]:4   param_2                   XREF[1]:     004cdaba(R)
//              RGE_Static_Obj    Stack[0xc]:4   param_3                   XREF[1]:     004cdabe(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004cdac8(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004cdafe(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004cdab1(W)
//                               ??0TRIBE_Action_Convert@@QAE@PAVRGE_Action_Object@@PAVRGE_T  XREF[2]:     convert:004cb2b2(c),
//                               TRIBE_Action_Convert::TRIBE_Action_Convert                                create_task_action:004d06cd(c)
//                              tact_cnv.cpp:61 (42)
//         004cda90     PUSH       -0x1
//         004cda92     PUSH       FUN_0055fde8
//         004cda97     MOV        EAX,FS:[0x0]
//         004cda9d     PUSH       EAX
//         004cda9e     MOV        dword ptr FS:[0x0],ESP
//         004cdaa5     PUSH       this
//         004cdaa6     MOV        EAX,dword ptr [ESP + param_1]
//         004cdaaa     PUSH       ESI
//         004cdaab     PUSH       EDI
//         004cdaac     MOV        ESI,this
//         004cdaae     PUSH       0x1
//         004cdab0     PUSH       EAX
//         004cdab1     MOV        dword ptr [ESP + local_10],ESI
//         004cdab5     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, RGE_A
//                              tact_cnv.cpp:63 (4)
//         004cdaba     MOV        this,dword ptr [ESP + param_2]
//                              tact_cnv.cpp:64 (42)
//         004cdabe     MOV        EDI,dword ptr [ESP + param_3]
//         004cdac2     MOV        dword ptr [ESI + 0x30],this
//         004cdac5     PUSH       EDI
//         004cdac6     MOV        this,ESI
//         004cdac8     MOV        dword ptr [ESP + local_4],0x0
//         004cdad0     MOV        dword ptr [ESI + 0x44],0x3f800000
//         004cdad7     MOV        dword ptr [ESI],TRIBE_Action_Convert::`vftable'  = 004cda60
//                              language.dll match for 0x68: "Arial"
//         004cdadd     MOV        word ptr [ESI + 0x4],0x68
//         004cdae3     CALL       RGE_Action::set_target_obj                       void set_target_obj(RGE_Action * this, RGE_St
//                              tact_cnv.cpp:65 (4)
//         004cdae8     TEST       EDI,EDI
//         004cdaea     JZ         LAB_004cdafe
//                              tact_cnv.cpp:67 (6)
//         004cdaec     MOV        EDX,dword ptr [EDI + 0x38]
//         004cdaef     MOV        dword ptr [ESI + 0x20],EDX
//                              tact_cnv.cpp:68 (6)
//         004cdaf2     MOV        EAX,dword ptr [EDI + 0x3c]
//         004cdaf5     MOV        dword ptr [ESI + 0x24],EAX
//                              tact_cnv.cpp:69 (6)
//         004cdaf8     MOV        this,dword ptr [EDI + 0x40]
//         004cdafb     MOV        dword ptr [ESI + 0x28],this
//                               LAB_004cdafe                                                 XREF[1]:     004cdaea(j)
//                              tact_cnv.cpp:81 (25)
//         004cdafe     MOV        this,dword ptr [ESP + local_c]
//         004cdb02     MOV        byte ptr [ESI + 0x40],0x0
//         004cdb06     MOV        EAX,ESI
//         004cdb08     POP        EDI
//         004cdb09     MOV        dword ptr FS:[0x0],this
//         004cdb10     POP        ESI
//         004cdb11     ADD        ESP,0x10
//         004cdb14     RET        0xc
//         004cdb17     ??         90h
//         004cdb18     NOP
//         004cdb19     NOP
//         004cdb1a     NOP
//         004cdb1b     NOP
//         004cdb1c     NOP
//         004cdb1d     NOP
//         004cdb1e     NOP
//         004cdb1f     NOP
}

TRIBE_Action_Convert::TRIBE_Action_Convert(RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Action_Convert(TRIBE_Action_Convert * thi
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Action_C    ECX:4 (auto)   this
//              RGE_Action_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004cdb20(R)
//              RGE_Task *        Stack[0x8]:4   param_2                   XREF[1]:     004cdb2f(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     004cdb37(R)
//              float             Stack[0x10]:4  param_4                   XREF[1]:     004cdb33(R)
//              float             Stack[0x14]:4  param_5                   XREF[1]:     004cdb3e(R)
//                               ??0TRIBE_Action_Convert@@QAE@PAVRGE_Action_Object@@PAVRGE_T  XREF[1]:     create_task_action:004d0718(c)
//                               TRIBE_Action_Convert::TRIBE_Action_Convert
//                              tact_cnv.cpp:90 (15)
//         004cdb20     MOV        EAX,dword ptr [ESP + param_1]
//         004cdb24     PUSH       ESI
//         004cdb25     PUSH       0x1
//         004cdb27     MOV        ESI,this
//         004cdb29     PUSH       EAX
//         004cdb2a     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, RGE_A
//                              tact_cnv.cpp:92 (4)
//         004cdb2f     MOV        this,dword ptr [ESP + param_2]
//                              tact_cnv.cpp:94 (11)
//         004cdb33     MOV        EAX,dword ptr [ESP + param_4]
//         004cdb37     MOV        EDX,dword ptr [ESP + param_3]
//         004cdb3b     MOV        dword ptr [ESI + 0x30],this
//                              tact_cnv.cpp:95 (32)
//         004cdb3e     MOV        this,dword ptr [ESP + param_5]
//         004cdb42     MOV        dword ptr [ESI + 0x24],EAX
//         004cdb45     MOV        dword ptr [ESI + 0x44],0x3f800000
//         004cdb4c     MOV        dword ptr [ESI],TRIBE_Action_Convert::`vftable'  = 004cda60
//         004cdb52     MOV        word ptr [ESI + 0x4],0x68
//         004cdb58     MOV        dword ptr [ESI + 0x20],EDX
//         004cdb5b     MOV        dword ptr [ESI + 0x28],this
//                              tact_cnv.cpp:96 (4)
//         004cdb5e     MOV        byte ptr [ESI + 0x40],0x0
//                              tact_cnv.cpp:102 (6)
//         004cdb62     MOV        EAX,ESI
//         004cdb64     POP        ESI
//         004cdb65     RET        0x14
//         004cdb68     ??         90h
//         004cdb69     NOP
//         004cdb6a     NOP
//         004cdb6b     NOP
//         004cdb6c     NOP
//         004cdb6d     NOP
//         004cdb6e     NOP
//         004cdb6f     NOP
}

void TRIBE_Action_Convert::save(int param_1) {
    /* TODO: Stub */
//                              void __thiscall save(TRIBE_Action_Convert * this, int param_1)
//              void              <VOID>         <RETURN>
//              TRIBE_Action_C    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004cdb72(R)
//                               ?save@TRIBE_Action_Convert@@UAEXH@Z                          XREF[1]:     00574fa4(*)
//                               TRIBE_Action_Convert::save
//                              tact_cnv.cpp:108 (2)
//         004cdb70     PUSH       ESI
//         004cdb71     PUSH       EDI
//                              tact_cnv.cpp:109 (12)
//         004cdb72     MOV        EDI,dword ptr [ESP + param_1]
//         004cdb76     MOV        ESI,this
//         004cdb78     PUSH       EDI
//         004cdb79     CALL       RGE_Action::save                                 void save(RGE_Action * this, int param_1)
//                              tact_cnv.cpp:110 (15)
//         004cdb7e     LEA        EAX,[ESI + 0x40]
//         004cdb81     PUSH       0x1
//         004cdb83     PUSH       EAX
//         004cdb84     PUSH       EDI
//         004cdb85     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004cdb8a     ADD        ESP,0xc
//                              tact_cnv.cpp:111 (15)
//         004cdb8d     ADD        ESI,0x44
//         004cdb90     PUSH       0x4
//         004cdb92     PUSH       ESI
//         004cdb93     PUSH       EDI
//         004cdb94     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004cdb99     ADD        ESP,0xc
//                              tact_cnv.cpp:112 (5)
//         004cdb9c     POP        EDI
//         004cdb9d     POP        ESI
//         004cdb9e     RET        0x4
//         004cdba1     ??         90h
//         004cdba2     NOP
//         004cdba3     NOP
//         004cdba4     NOP
//         004cdba5     NOP
//         004cdba6     NOP
//         004cdba7     NOP
//         004cdba8     NOP
//         004cdba9     NOP
//         004cdbaa     NOP
//         004cdbab     NOP
//         004cdbac     NOP
//         004cdbad     NOP
//         004cdbae     NOP
//         004cdbaf     NOP
    return;
}

void TRIBE_Action_Convert::first_in_stack(uchar param_1) {
    /* TODO: Stub */
//                              void __thiscall first_in_stack(TRIBE_Action_Convert * this, uchar pa
//              void              <VOID>         <RETURN>
//              TRIBE_Action_C    ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     004cddca(R)
//                               ?first_in_stack@TRIBE_Action_Convert@@UAEXE@Z                XREF[1]:     00574fac(*)
//                               TRIBE_Action_Convert::first_in_stack
//                              tact_cnv.cpp:118 (5)
//         004cdbb0     PUSH       EBX
//         004cdbb1     PUSH       ESI
//         004cdbb2     MOV        ESI,this
//         004cdbb4     PUSH       EDI
//                              tact_cnv.cpp:120 (11)
//         004cdbb5     MOV        EDX,dword ptr [ESI + 0x10]
//         004cdbb8     TEST       EDX,EDX
//         004cdbba     JZ         LAB_004cddca
//                              tact_cnv.cpp:122 (3)
//         004cdbc0     MOV        EAX,dword ptr [EDX + 0x8]
//                              tact_cnv.cpp:125 (15)
//         004cdbc3     MOV        EDI,dword ptr [ESI + 0x8]
//         004cdbc6     MOV        this,dword ptr [EDX + 0xc]
//         004cdbc9     MOVSX      EBX,word ptr [EAX + 0x14]
//         004cdbcd     CMP        this,dword ptr [EDI + 0xc]
//         004cdbd0     JNZ        LAB_004cdbd8
//                              tact_cnv.cpp:126 (4)
//         004cdbd2     MOV        byte ptr [ESI + 0x40],0x1
//                              tact_cnv.cpp:127 (2)
//         004cdbd6     JMP        LAB_004cdbdc
//                               LAB_004cdbd8                                                 XREF[1]:     004cdbd0(j)
//                              tact_cnv.cpp:128 (4)
//         004cdbd8     MOV        byte ptr [ESI + 0x40],0x0
//                               LAB_004cdbdc                                                 XREF[1]:     004cdbd6(j)
//                              tact_cnv.cpp:140 (66)
//         004cdbdc     MOV        EAX,dword ptr [EDX + 0x8]
//         004cdbdf     MOV        AX,word ptr [EAX + 0x10]
//         004cdbe3     CMP        AX,0x6d
//         004cdbe7     JZ         LAB_004cdd4b
//         004cdbed     CMP        EBX,0x1b
//         004cdbf0     JZ         LAB_004cdd4b
//         004cdbf6     CMP        AX,0x9f
//         004cdbfa     JZ         LAB_004cdd4b
//         004cdc00     CMP        AX,0x9e
//         004cdc04     JZ         LAB_004cdd4b
//         004cdc0a     CMP        AX,0xa3
//         004cdc0e     JZ         LAB_004cdd4b
//         004cdc14     CMP        AX,0x114
//         004cdc18     JZ         LAB_004cdd4b
//                              tact_cnv.cpp:156 (16)
//         004cdc1e     FLD        float ptr [EDI + 0x44]
//         004cdc21     FCOMP      double ptr [DAT_00574ff0]                        = align(6)
//         004cdc27     FNSTSW     AX
//         004cdc29     TEST       AH,0x1
//         004cdc2c     JZ         LAB_004cdc5b
//                              tact_cnv.cpp:158 (9)
//         004cdc2e     MOV        EDX,dword ptr [ESI]
//         004cdc30     PUSH       0xd
//         004cdc32     MOV        this,ESI
//         004cdc34     CALL       dword ptr [EDX + 0x5c]
//                              tact_cnv.cpp:159 (30)
//         004cdc37     MOV        EDX,dword ptr [ESI + 0x8]
//         004cdc3a     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004cdc40     PUSH       0x0
//         004cdc42     PUSH       0x0=>DAT_fffffff8
//         004cdc44     MOV        EDX,dword ptr [EDX + 0xc]
//         004cdc47     MOV        EAX,dword ptr [this->_padding_]
//         004cdc49     PUSH       0x0=>DAT_fffffff4
//         004cdc4b     MOVSX      EDX,word ptr [EDX + 0x4a]
//         004cdc4f     PUSH       EDX=>DAT_fffffff0
//                              language.dll match for 0x76: "B"
//         004cdc50     PUSH       0x76
//         004cdc52     CALL       dword ptr [EAX + 0x40]
//                              tact_cnv.cpp:216 (6)
//         004cdc55     POP        EDI
//         004cdc56     POP        ESI
//         004cdc57     POP        EBX
//         004cdc58     RET        0x4
//                               LAB_004cdc5b                                                 XREF[1]:     004cdc2c(j)
//                              tact_cnv.cpp:165 (5)
//         004cdc5b     CMP        EBX,0x3
//         004cdc5e     JNZ        LAB_004cdc69
//                              tact_cnv.cpp:166 (7)
//         004cdc60     MOV        dword ptr [ESI + 0x44],0x3f800000
//                              tact_cnv.cpp:167 (2)
//         004cdc67     JMP        LAB_004cdc75
//                               LAB_004cdc69                                                 XREF[1]:     004cdc5e(j)
//                              tact_cnv.cpp:168 (12)
//         004cdc69     MOV        EAX,dword ptr [EDI + 0x8]
//         004cdc6c     MOV        this,dword ptr [EAX + 0x114]
//         004cdc72     MOV        dword ptr [ESI + 0x44],this
//                               LAB_004cdc75                                                 XREF[1]:     004cdc67(j)
//                              tact_cnv.cpp:170 (5)
//         004cdc75     CMP        EBX,0x1e
//         004cdc78     JNZ        LAB_004cdc89
//                              tact_cnv.cpp:172 (9)
//         004cdc7a     MOV        EDX,dword ptr [ESI]
//         004cdc7c     PUSH       0xd
//         004cdc7e     MOV        this,ESI
//         004cdc80     CALL       dword ptr [EDX + 0x5c]
//                              tact_cnv.cpp:216 (6)
//         004cdc83     POP        EDI
//         004cdc84     POP        ESI
//         004cdc85     POP        EBX
//         004cdc86     RET        0x4
//                               LAB_004cdc89                                                 XREF[1]:     004cdc78(j)
//                              tact_cnv.cpp:179 (27)
//         004cdc89     CMP        EBX,0x12
//         004cdc8c     JNZ        LAB_004cdce6
//         004cdc8e     MOV        this,dword ptr [EDI + 0xc]
//         004cdc91     MOV        EAX,dword ptr [this->_padding_ + 0x50]
//         004cdc94     FLD        float ptr [EAX + 0x6c]
//         004cdc97     FCOMP      float ptr [DAT_00574ff8]
//         004cdc9d     FNSTSW     AX
//         004cdc9f     TEST       AH,0x41
//         004cdca2     JZ         LAB_004cdce6
//                              tact_cnv.cpp:182 (10)
//         004cdca4     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
//         004cdca9     CMP        EAX,0x1
//         004cdcac     JNZ        LAB_004cdcb9
//                              tact_cnv.cpp:183 (9)
//         004cdcae     MOV        EDX,dword ptr [ESI]
//         004cdcb0     PUSH       0xb
//         004cdcb2     MOV        this,ESI
//         004cdcb4     CALL       dword ptr [EDX + 0x5c]
//                              tact_cnv.cpp:184 (2)
//         004cdcb7     JMP        LAB_004cdcc2
//                               LAB_004cdcb9                                                 XREF[1]:     004cdcac(j)
//                              tact_cnv.cpp:185 (9)
//         004cdcb9     MOV        EAX,dword ptr [ESI]
//         004cdcbb     PUSH       0xd
//         004cdcbd     MOV        this,ESI
//         004cdcbf     CALL       dword ptr [EAX + 0x5c]
//                               LAB_004cdcc2                                                 XREF[1]:     004cdcb7(j)
//                              tact_cnv.cpp:187 (30)
//         004cdcc2     MOV        EAX,dword ptr [ESI + 0x8]
//         004cdcc5     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004cdccb     PUSH       0x0
//         004cdccd     PUSH       0x0=>DAT_fffffff8
//         004cdccf     MOV        EAX,dword ptr [EAX + 0xc]
//         004cdcd2     MOV        EDX,dword ptr [this->_padding_]
//         004cdcd4     PUSH       0x0=>DAT_fffffff4
//         004cdcd6     MOVSX      EAX,word ptr [EAX + 0x4a]
//         004cdcda     PUSH       EAX=>DAT_fffffff0
//                              language.dll match for 0x77: "Arial"
//         004cdcdb     PUSH       0x77
//         004cdcdd     CALL       dword ptr [EDX + 0x40]
//                              tact_cnv.cpp:216 (6)
//         004cdce0     POP        EDI
//         004cdce1     POP        ESI
//         004cdce2     POP        EBX
//         004cdce3     RET        0x4
//                               LAB_004cdce6                                                 XREF[2]:     004cdc8c(j), 004cdca2(j)
//                              tact_cnv.cpp:194 (35)
//         004cdce6     CMP        EBX,0x3
//         004cdce9     JNZ        LAB_004cddca
//         004cdcef     MOV        this,dword ptr [EDI + 0xc]
//         004cdcf2     MOV        EAX,dword ptr [this->_padding_ + 0x50]
//         004cdcf5     FLD        float ptr [EAX + 0x70]
//         004cdcf8     FCOMP      float ptr [DAT_00574ff8]
//         004cdcfe     FNSTSW     AX
//         004cdd00     TEST       AH,0x41
//         004cdd03     JZ         LAB_004cddca
//                              tact_cnv.cpp:197 (10)
//         004cdd09     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
//         004cdd0e     CMP        EAX,0x1
//         004cdd11     JNZ        LAB_004cdd1e
//                              tact_cnv.cpp:198 (9)
//         004cdd13     MOV        EDX,dword ptr [ESI]
//         004cdd15     PUSH       0xb
//         004cdd17     MOV        this,ESI
//         004cdd19     CALL       dword ptr [EDX + 0x5c]
//                              tact_cnv.cpp:199 (2)
//         004cdd1c     JMP        LAB_004cdd27
//                               LAB_004cdd1e                                                 XREF[1]:     004cdd11(j)
//                              tact_cnv.cpp:200 (9)
//         004cdd1e     MOV        EAX,dword ptr [ESI]
//         004cdd20     PUSH       0xd
//         004cdd22     MOV        this,ESI
//         004cdd24     CALL       dword ptr [EAX + 0x5c]
//                               LAB_004cdd27                                                 XREF[1]:     004cdd1c(j)
//                              tact_cnv.cpp:202 (30)
//         004cdd27     MOV        EAX,dword ptr [ESI + 0x8]
//         004cdd2a     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004cdd30     PUSH       0x0
//         004cdd32     PUSH       0x0=>DAT_fffffff8
//         004cdd34     MOV        EAX,dword ptr [EAX + 0xc]
//         004cdd37     MOV        EDX,dword ptr [this->_padding_]
//         004cdd39     PUSH       0x0=>DAT_fffffff4
//         004cdd3b     MOVSX      EAX,word ptr [EAX + 0x4a]
//         004cdd3f     PUSH       EAX=>DAT_fffffff0
//                              language.dll match for 0x78: "10"
//         004cdd40     PUSH       0x78
//         004cdd42     CALL       dword ptr [EDX + 0x40]
//                              tact_cnv.cpp:216 (6)
//         004cdd45     POP        EDI
//         004cdd46     POP        ESI
//         004cdd47     POP        EBX
//         004cdd48     RET        0x4
//                               LAB_004cdd4b                                                 XREF[6]:     004cdbe7(j), 004cdbf0(j),
//                                                                                                         004cdbfa(j), 004cdc04(j),
//                                                                                                         004cdc0e(j), 004cdc18(j)
//                              tact_cnv.cpp:143 (13)
//         004cdd4b     MOV        this,dword ptr [EDI + 0xc]
//         004cdd4e     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
//         004cdd53     CMP        EAX,0x1
//         004cdd56     JNZ        LAB_004cdd63
//                              tact_cnv.cpp:144 (9)
//         004cdd58     MOV        EDX,dword ptr [ESI]
//         004cdd5a     PUSH       0xb
//         004cdd5c     MOV        this,ESI
//         004cdd5e     CALL       dword ptr [EDX + 0x5c]
//                              tact_cnv.cpp:145 (2)
//         004cdd61     JMP        LAB_004cdd6c
//                               LAB_004cdd63                                                 XREF[1]:     004cdd56(j)
//                              tact_cnv.cpp:146 (9)
//         004cdd63     MOV        EAX,dword ptr [ESI]
//         004cdd65     PUSH       0xd
//         004cdd67     MOV        this,ESI
//         004cdd69     CALL       dword ptr [EAX + 0x5c]
//                               LAB_004cdd6c                                                 XREF[1]:     004cdd61(j)
//                              tact_cnv.cpp:148 (16)
//         004cdd6c     MOV        this,dword ptr [ESI + 0x10]
//         004cdd6f     MOV        EDX,dword ptr [ECX + this->_padding_]
//         004cdd72     MOV        AX,word ptr [EDX + 0x10]
//         004cdd76     CMP        AX,0x6d
//         004cdd7a     JNZ        LAB_004cdda0
//                              tact_cnv.cpp:149 (30)
//         004cdd7c     MOV        EDX,dword ptr [ESI + 0x8]
//         004cdd7f     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004cdd85     PUSH       0x0
//         004cdd87     PUSH       0x0=>DAT_fffffff8
//         004cdd89     MOV        EDX,dword ptr [EDX + 0xc]
//         004cdd8c     MOV        EAX,dword ptr [this->_padding_]
//         004cdd8e     PUSH       0x0=>DAT_fffffff4
//         004cdd90     MOVSX      EDX,word ptr [EDX + 0x4a]
//         004cdd94     PUSH       EDX=>DAT_fffffff0
//                              language.dll match for 0x79: "N"
//         004cdd95     PUSH       0x79
//         004cdd97     CALL       dword ptr [EAX + 0x40]
//                              tact_cnv.cpp:216 (6)
//         004cdd9a     POP        EDI
//         004cdd9b     POP        ESI
//         004cdd9c     POP        EBX
//         004cdd9d     RET        0x4
//                               LAB_004cdda0                                                 XREF[1]:     004cdd7a(j)
//                              tact_cnv.cpp:150 (6)
//         004cdda0     CMP        AX,0x114
//         004cdda4     JNZ        LAB_004cddfd
//                              tact_cnv.cpp:151 (30)
//         004cdda6     MOV        EDX,dword ptr [ESI + 0x8]
//         004cdda9     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004cddaf     PUSH       0x0
//         004cddb1     PUSH       0x0=>DAT_fffffff8
//         004cddb3     MOV        EDX,dword ptr [EDX + 0xc]
//         004cddb6     MOV        EAX,dword ptr [this->_padding_]
//         004cddb8     PUSH       0x0=>DAT_fffffff4
//         004cddba     MOVSX      EDX,word ptr [EDX + 0x4a]
//         004cddbe     PUSH       EDX=>DAT_fffffff0
//                              language.dll match for 0x7a: "Arial"
//         004cddbf     PUSH       0x7a
//         004cddc1     CALL       dword ptr [EAX + 0x40]
//                              tact_cnv.cpp:216 (6)
//         004cddc4     POP        EDI
//         004cddc5     POP        ESI
//         004cddc6     POP        EBX
//         004cddc7     RET        0x4
//                               LAB_004cddca                                                 XREF[3]:     004cdbba(j), 004cdce9(j),
//                                                                                                         004cdd03(j)
//                              tact_cnv.cpp:207 (8)
//         004cddca     MOV        AL,byte ptr [ESP + param_1]
//         004cddce     TEST       AL,AL
//         004cddd0     JZ         LAB_004cddf4
//                              tact_cnv.cpp:209 (4)
//         004cddd2     TEST       EDX,EDX
//         004cddd4     JZ         LAB_004cdde5
//                              tact_cnv.cpp:210 (4)
//         004cddd6     MOV        EAX,dword ptr [ESI]
//         004cddd8     PUSH       0x4
//                              tact_cnv.cpp:215 (5)
//         004cddda     MOV        this,ESI
//         004cdddc     CALL       dword ptr [EAX + 0x5c]
//                              tact_cnv.cpp:216 (6)
//         004cdddf     POP        EDI
//         004cdde0     POP        ESI
//         004cdde1     POP        EBX
//         004cdde2     RET        0x4
//                               LAB_004cdde5                                                 XREF[1]:     004cddd4(j)
//                              tact_cnv.cpp:212 (9)
//         004cdde5     MOV        EDX,dword ptr [ESI]
//         004cdde7     PUSH       0x3
//         004cdde9     MOV        this,ESI
//         004cddeb     CALL       dword ptr [EDX + 0x5c]
//                              tact_cnv.cpp:216 (6)
//         004cddee     POP        EDI
//         004cddef     POP        ESI
//         004cddf0     POP        EBX
//         004cddf1     RET        0x4
//                               LAB_004cddf4                                                 XREF[1]:     004cddd0(j)
//                              tact_cnv.cpp:215 (9)
//         004cddf4     MOV        EAX,dword ptr [ESI]
//         004cddf6     PUSH       0x3
//         004cddf8     MOV        this,ESI
//         004cddfa     CALL       dword ptr [EAX + 0x5c]
//                               LAB_004cddfd                                                 XREF[1]:     004cdda4(j)
//                              tact_cnv.cpp:216 (6)
//         004cddfd     POP        EDI
//         004cddfe     POP        ESI
//         004cddff     POP        EBX
//         004cde00     RET        0x4
//         004cde03     ??         90h
//         004cde04     NOP
//         004cde05     NOP
//         004cde06     NOP
//         004cde07     NOP
//         004cde08     NOP
//         004cde09     NOP
//         004cde0a     NOP
//         004cde0b     NOP
//         004cde0c     NOP
//         004cde0d     NOP
//         004cde0e     NOP
//         004cde0f     NOP
    return;
}

void TRIBE_Action_Convert::set_state(uchar param_1) {
    /* TODO: Stub */
//                              void __thiscall set_state(TRIBE_Action_Convert * this, uchar param_1)
//              void              <VOID>         <RETURN>
//              TRIBE_Action_C    ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[3]:     004cde31(R), 004cde94(W), 004cdf38(W)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     004cde9a(W), 004cdece(W), 004cdf3e(W), 004cdf6a(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[3]:     004cde77(R), 004cdf06(R), 004cdfa2(R)
//                               ?set_state@TRIBE_Action_Convert@@MAEXE@Z                     XREF[1]:     00574fec(*)
//                               TRIBE_Action_Convert::set_state
//                              tact_cnv.cpp:222 (25)
//         004cde10     MOV        EAX,FS:[0x0]
//         004cde16     PUSH       -0x1
//         004cde18     PUSH       FUN_0055fe16
//         004cde1d     PUSH       EAX
//         004cde1e     MOV        dword ptr FS:[0x0],ESP
//         004cde25     PUSH       ESI
//         004cde26     MOV        ESI,this
//         004cde28     PUSH       EDI
//                              tact_cnv.cpp:230 (8)
//         004cde29     MOV        this,dword ptr [ESI + 0x34]
//         004cde2c     CALL       RGE_Action_List::delete_list                     void delete_list(RGE_Action_List * this)
//                              tact_cnv.cpp:233 (7)
//         004cde31     MOV        EAX,dword ptr [ESP + param_1]
//         004cde35     MOV        byte ptr [ESI + 0xc],AL
//                              tact_cnv.cpp:235 (18)
//         004cde38     AND        EAX,0xff
//         004cde3d     DEC        EAX
//         004cde3e     CMP        EAX,0xd
//         004cde41     JA         switchD_004cde43::caseD_5
//                               switchD_004cde43::switchD
//         004cde43     JMP        dword ptr [EAX*0x4 + switchD_004cde43::switchd   = 004cde68
//                               switchD_004cde43::caseD_3                                    XREF[2]:     004cde43(j), 004ce038(*)
//                              tact_cnv.cpp:238 (30)
//         004cde4a     MOV        this,dword ptr [ESI + 0x8]
//         004cde4d     PUSH       0x0
//         004cde4f     PUSH       0x0
//         004cde51     PUSH       0x25c
//         004cde56     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004cde59     MOV        EDX,dword ptr [this->_padding_]
//         004cde5b     PUSH       0x202
//         004cde60     PUSH       EAX
//         004cde61     PUSH       EAX
//         004cde62     CALL       dword ptr [EDX + 0x148]
//                               switchD_004cde43::caseD_2                                    XREF[5]:     004cde43(j), 004ce030(*),
//                               switchD_004cde43::caseD_d                                                 004ce034(*), 004ce060(*),
//                               switchD_004cde43::caseD_e                                                 004ce064(*)
//                               switchD_004cde43::caseD_1
//                              tact_cnv.cpp:302 (15)
//         004cde68     MOV        this,dword ptr [ESI + 0x8]
//         004cde6b     MOV        EDX,dword ptr [ECX + this->_padding_]
//         004cde6e     MOV        EAX,dword ptr [this->_padding_]
//         004cde70     MOV        EDX,dword ptr [EDX + 0x18]
//                               LAB_004cde73                                                 XREF[1]:     004cdfc0(j)
//         004cde73     PUSH       EDX
//         004cde74     CALL       dword ptr [EAX + 0x38]
//                               switchD_004cde43::caseD_8                                    XREF[7]:     004cde41(j), 004cde43(j),
//                               switchD_004cde43::caseD_9                                                 004ce040(*), 004ce04c(*),
//                               switchD_004cde43::caseD_a                                                 004ce050(*), 004ce054(*),
//                               switchD_004cde43::caseD_c                                                 004ce05c(*)
//                               switchD_004cde43::caseD_5
//                              tact_cnv.cpp:305 (19)
//         004cde77     MOV        this,dword ptr [ESP + local_c]
//         004cde7b     MOV        dword ptr FS:[0x0],this
//         004cde82     POP        EDI
//         004cde83     POP        ESI
//         004cde84     ADD        ESP,0xc
//         004cde87     RET        0x4
//                               switchD_004cde43::caseD_b                                    XREF[2]:     004cde43(j), 004ce058(*)
//                              tact_cnv.cpp:249 (66)
//         004cde8a     PUSH       0x44
//         004cde8c     CALL       operator_new                                     void * operator_new(uint param_1)
//         004cde91     ADD        ESP,0x4
//         004cde94     MOV        dword ptr [ESP + param_1],EAX
//         004cde98     TEST       EAX,EAX
//         004cde9a     MOV        dword ptr [ESP + local_4],0x0
//         004cdea2     JZ         LAB_004cdeca
//         004cdea4     MOV        this,dword ptr [ESI + 0x30]
//         004cdea7     MOV        EDX,dword ptr [ECX + this->_padding_]
//         004cdeaa     MOV        this,dword ptr [ESI + 0x44]
//         004cdead     PUSH       EDX
//         004cdeae     MOV        EDX,dword ptr [ESI + 0x28]
//         004cdeb1     PUSH       this
//         004cdeb2     MOV        this,dword ptr [ESI + 0x24]
//         004cdeb5     PUSH       EDX
//         004cdeb6     MOV        EDX,dword ptr [ESI + 0x20]
//         004cdeb9     PUSH       this
//         004cdeba     MOV        this,dword ptr [ESI + 0x8]
//         004cdebd     PUSH       EDX
//         004cdebe     PUSH       this
//         004cdebf     MOV        this,EAX
//         004cdec1     CALL       RGE_Action_Move_To::RGE_Action_Move_To           undefined RGE_Action_Move_To(RGE_Action_Move_
//         004cdec6     MOV        EDI,EAX
//         004cdec8     JMP        LAB_004cdecc
//                               LAB_004cdeca                                                 XREF[1]:     004cdea2(j)
//         004cdeca     XOR        EDI,EDI
//                               LAB_004cdecc                                                 XREF[1]:     004cdec8(j)
//                              tact_cnv.cpp:250 (12)
//         004cdecc     TEST       EDI,EDI
//         004cdece     MOV        dword ptr [ESP + local_4],0xffffffff
//         004cded6     JNZ        LAB_004cdef4
//                              tact_cnv.cpp:252 (9)
//         004cded8     MOV        EDX,dword ptr [ESI]
//         004cdeda     PUSH       0xd
//         004cdedc     MOV        this,ESI
//         004cdede     CALL       dword ptr [EDX + 0x5c]
//                              tact_cnv.cpp:305 (19)
//         004cdee1     MOV        this,dword ptr [ESP + 0x8]
//         004cdee5     MOV        dword ptr FS:[0x0],this
//         004cdeec     POP        EDI
//         004cdeed     POP        ESI
//         004cdeee     ADD        ESP,0xc
//         004cdef1     RET        0x4
//                               LAB_004cdef4                                                 XREF[1]:     004cded6(j)
//                              tact_cnv.cpp:255 (9)
//         004cdef4     PUSH       0x1
//         004cdef6     MOV        this,EDI
//         004cdef8     CALL       RGE_Action::setSubAction                         void setSubAction(RGE_Action * this, uchar pa
//                              tact_cnv.cpp:256 (9)
//         004cdefd     MOV        this,dword ptr [ESI + 0x34]
//         004cdf00     PUSH       EDI
//         004cdf01     CALL       RGE_Action_List::add_action                      void add_action(RGE_Action_List * this, RGE_A
//                              tact_cnv.cpp:305 (19)
//         004cdf06     MOV        this,dword ptr [ESP + local_c]
//         004cdf0a     MOV        dword ptr FS:[0x0],this
//         004cdf11     POP        EDI
//         004cdf12     POP        ESI
//         004cdf13     ADD        ESP,0xc
//         004cdf16     RET        0x4
//                               switchD_004cde43::caseD_4                                    XREF[2]:     004cde43(j), 004ce03c(*)
//                              tact_cnv.cpp:261 (3)
//         004cdf19     MOV        EAX,dword ptr [ESI + 0x10]
//                              tact_cnv.cpp:265 (76)
//         004cdf1c     PUSH       0x44
//         004cdf1e     MOV        this,dword ptr [EAX + 0x38]
//         004cdf21     MOV        dword ptr [ESI + 0x20],this
//         004cdf24     MOV        EDX,dword ptr [EAX + 0x3c]
//         004cdf27     MOV        dword ptr [ESI + 0x24],EDX
//         004cdf2a     MOV        EAX,dword ptr [EAX + 0x40]
//         004cdf2d     MOV        dword ptr [ESI + 0x28],EAX
//         004cdf30     CALL       operator_new                                     void * operator_new(uint param_1)
//         004cdf35     ADD        ESP,0x4
//         004cdf38     MOV        dword ptr [ESP + param_1],EAX
//         004cdf3c     TEST       EAX,EAX
//         004cdf3e     MOV        dword ptr [ESP + local_4],0x1
//         004cdf46     JZ         LAB_004cdf66
//         004cdf48     MOV        this,dword ptr [ESI + 0x30]
//         004cdf4b     MOV        EDX,dword ptr [ECX + this->_padding_]
//         004cdf4e     MOV        this,dword ptr [ESI + 0x44]
//         004cdf51     PUSH       EDX
//         004cdf52     MOV        EDX,dword ptr [ESI + 0x10]
//         004cdf55     PUSH       this
//         004cdf56     MOV        this,dword ptr [ESI + 0x8]
//         004cdf59     PUSH       EDX
//         004cdf5a     PUSH       this
//         004cdf5b     MOV        this,EAX
//         004cdf5d     CALL       RGE_Action_Move_To::RGE_Action_Move_To           undefined RGE_Action_Move_To(RGE_Action_Move_
//         004cdf62     MOV        EDI,EAX
//         004cdf64     JMP        LAB_004cdf68
//                               LAB_004cdf66                                                 XREF[1]:     004cdf46(j)
//         004cdf66     XOR        EDI,EDI
//                               LAB_004cdf68                                                 XREF[1]:     004cdf64(j)
//                              tact_cnv.cpp:266 (12)
//         004cdf68     TEST       EDI,EDI
//         004cdf6a     MOV        dword ptr [ESP + local_4],0xffffffff
//         004cdf72     JNZ        LAB_004cdf90
//                              tact_cnv.cpp:268 (9)
//         004cdf74     MOV        EDX,dword ptr [ESI]
//         004cdf76     PUSH       0xd
//         004cdf78     MOV        this,ESI
//         004cdf7a     CALL       dword ptr [EDX + 0x5c]
//                              tact_cnv.cpp:305 (19)
//         004cdf7d     MOV        this,dword ptr [ESP + 0x8]
//         004cdf81     MOV        dword ptr FS:[0x0],this
//         004cdf88     POP        EDI
//         004cdf89     POP        ESI
//         004cdf8a     ADD        ESP,0xc
//         004cdf8d     RET        0x4
//                               LAB_004cdf90                                                 XREF[1]:     004cdf72(j)
//                              tact_cnv.cpp:271 (9)
//         004cdf90     MOV        this,dword ptr [ESI + 0x34]
//         004cdf93     PUSH       EDI
//         004cdf94     CALL       RGE_Action_List::add_action                      void add_action(RGE_Action_List * this, RGE_A
//                              tact_cnv.cpp:272 (9)
//         004cdf99     PUSH       0x1
//         004cdf9b     MOV        this,EDI
//         004cdf9d     CALL       RGE_Action::setSubAction                         void setSubAction(RGE_Action * this, uchar pa
//                              tact_cnv.cpp:305 (19)
//         004cdfa2     MOV        this,dword ptr [ESP + local_c]
//         004cdfa6     MOV        dword ptr FS:[0x0],this
//         004cdfad     POP        EDI
//         004cdfae     POP        ESI
//         004cdfaf     ADD        ESP,0xc
//         004cdfb2     RET        0x4
//                               switchD_004cde43::caseD_6                                    XREF[2]:     004cde43(j), 004ce044(*)
//                              tact_cnv.cpp:277 (11)
//         004cdfb5     MOV        this,dword ptr [ESI + 0x8]
//         004cdfb8     MOV        EDX,dword ptr [ESI + 0x30]
//         004cdfbb     MOV        EAX,dword ptr [this->_padding_]
//         004cdfbd     MOV        EDX,dword ptr [EDX + 0x34]
//                              tact_cnv.cpp:278 (5)
//         004cdfc0     JMP        LAB_004cde73
//                               switchD_004cde43::caseD_7                                    XREF[2]:     004cde43(j), 004ce048(*)
//                              tact_cnv.cpp:282 (15)
//         004cdfc5     MOV        EDX,dword ptr [ESI + 0x30]
//         004cdfc8     MOV        this,dword ptr [ESI + 0x8]
//         004cdfcb     MOV        EDX,dword ptr [EDX + 0x38]
//         004cdfce     MOV        EAX,dword ptr [this->_padding_]
//         004cdfd0     PUSH       EDX
//         004cdfd1     CALL       dword ptr [EAX + 0x38]
//                              tact_cnv.cpp:285 (10)
//         004cdfd4     MOV        EAX,dword ptr [ESI + 0x30]
//         004cdfd7     MOV        this,dword ptr [EAX + 0x44]
//         004cdfda     TEST       this,this
//         004cdfdc     JZ         LAB_004cdfe5
//                              tact_cnv.cpp:286 (7)
//         004cdfde     PUSH       0x1
//         004cdfe0     CALL       RGE_Sound::play                                  void play(RGE_Sound * this, int param_1)
//                               LAB_004cdfe5                                                 XREF[1]:     004cdfdc(j)
//                              tact_cnv.cpp:290 (17)
//         004cdfe5     MOV        EAX,dword ptr [ESI + 0x10]
//         004cdfe8     TEST       EAX,EAX
//         004cdfea     JZ         LAB_004ce011
//         004cdfec     MOV        this,dword ptr [EAX + 0xc]
//         004cdfef     CMP        word ptr [this->_padding_ + 0x4a],0x0
//         004cdff4     JLE        LAB_004ce011
//                              tact_cnv.cpp:291 (27)
//         004cdff6     MOV        EAX,dword ptr [ESI + 0x8]
//         004cdff9     MOV        EDX,dword ptr [this->_padding_]
//         004cdffb     PUSH       0x0
//         004cdffd     MOV        EDI,dword ptr [EAX + 0x40]
//         004ce000     PUSH       EDI=>DAT_fffffff8
//         004ce001     MOV        EDI,dword ptr [EAX + 0x3c]
//         004ce004     MOV        EAX,dword ptr [EAX + 0x38]
//         004ce007     PUSH       EDI=>DAT_fffffff4
//         004ce008     PUSH       EAX=>DAT_fffffff0
//                              language.dll match for 0x70: "B"
//         004ce009     PUSH       0x70
//         004ce00b     CALL       dword ptr [EDX + 0x94]
//                               LAB_004ce011                                                 XREF[2]:     004cdfea(j), 004cdff4(j)
//                              tact_cnv.cpp:293 (3)
//         004ce011     MOV        this,dword ptr [ESI + 0x30]
//                              tact_cnv.cpp:305 (84)
//         004ce014     POP        EDI
//         004ce015     MOV        EDX,dword ptr [ECX + this->_padding_]
//         004ce018     MOV        this,dword ptr [ESP + 0x4]
//         004ce01c     MOV        dword ptr [ESI + 0x2c],EDX
//         004ce01f     MOV        dword ptr FS:[0x0],this
//         004ce026     POP        ESI
//         004ce027     ADD        ESP,0xc
//         004ce02a     RET        0x4
    return;
}

uchar TRIBE_Action_Convert::update() {
    /* TODO: Stub */
//                              uchar __thiscall update(TRIBE_Action_Convert * this)
//              uchar             AL:1           <RETURN>
//              TRIBE_Action_C    ECX:4 (auto)   this
//                               ?update@TRIBE_Action_Convert@@UAEEXZ                         XREF[1]:     00574fb8(*)
//                               TRIBE_Action_Convert::update
//                              tact_cnv.cpp:311 (7)
//         004ce070     PUSH       this
//         004ce071     PUSH       EBX
//         004ce072     PUSH       EBP
//         004ce073     PUSH       ESI
//         004ce074     MOV        ESI,this
//         004ce076     PUSH       EDI
//                              tact_cnv.cpp:331 (25)
//         004ce077     MOV        EAX,dword ptr [ESI + 0x18]
//         004ce07a     CMP        EAX,-0x1
//         004ce07d     JZ         LAB_004ce092
//         004ce07f     PUSH       EAX
//         004ce080     MOV        EAX,dword ptr [ESI + 0x8]
//         004ce083     MOV        this,dword ptr [EAX + 0xc]
//         004ce086     MOV        this,dword ptr [ECX + this->_padding_]
//         004ce089     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
//         004ce08e     TEST       EAX,EAX
//                              tact_cnv.cpp:335 (2)
//         004ce090     JZ         LAB_004ce0c6
//                               LAB_004ce092                                                 XREF[1]:     004ce07d(j)
//                              tact_cnv.cpp:337 (27)
//         004ce092     MOV        EAX,dword ptr [ESI + 0x1c]
//         004ce095     CMP        EAX,-0x1
//         004ce098     JZ         LAB_004ce0b5
//         004ce09a     MOV        EDX,dword ptr [ESI + 0x8]
//         004ce09d     PUSH       EAX
//         004ce09e     MOV        EAX,dword ptr [EDX + 0xc]
//         004ce0a1     MOV        this,dword ptr [EAX + 0x3c]
//         004ce0a4     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
//         004ce0a9     TEST       EAX,EAX
//         004ce0ab     JNZ        LAB_004ce0b5
//                              tact_cnv.cpp:338 (8)
//         004ce0ad     MOV        EDX,dword ptr [ESI]
//         004ce0af     PUSH       EAX
//         004ce0b0     MOV        this,ESI
//         004ce0b2     CALL       dword ptr [EDX + 0x58]
//                               LAB_004ce0b5                                                 XREF[2]:     004ce098(j), 004ce0ab(j)
//                              tact_cnv.cpp:341 (17)
//         004ce0b5     MOV        EAX,dword ptr [ESI + 0x10]
//         004ce0b8     TEST       EAX,EAX
//         004ce0ba     JZ         LAB_004ce147
//         004ce0c0     CMP        byte ptr [EAX + 0x48],0x2
//         004ce0c4     JZ         LAB_004ce0de
//                               LAB_004ce0c6                                                 XREF[1]:     004ce090(j)
//                              tact_cnv.cpp:343 (9)
//         004ce0c6     MOV        EDI,dword ptr [ESI]
//         004ce0c8     PUSH       0x0
//         004ce0ca     MOV        this,ESI
//         004ce0cc     CALL       dword ptr [EDI + 0x54]
//                              tact_cnv.cpp:344 (7)
//         004ce0cf     PUSH       0x3
//         004ce0d1     MOV        this,ESI
//         004ce0d3     CALL       dword ptr [EDI + 0x5c]
//                              tact_cnv.cpp:521 (2)
//         004ce0d6     XOR        AL,AL
//                              tact_cnv.cpp:522 (6)
//         004ce0d8     POP        EDI
//         004ce0d9     POP        ESI
//         004ce0da     POP        EBP
//         004ce0db     POP        EBX
//         004ce0dc     POP        this
//         004ce0dd     RET
//                               LAB_004ce0de                                                 XREF[1]:     004ce0c4(j)
//                              tact_cnv.cpp:349 (28)
//         004ce0de     TEST       EAX,EAX
//         004ce0e0     JZ         LAB_004ce147
//         004ce0e2     MOV        this,dword ptr [ESI + 0x8]
//         004ce0e5     MOV        EAX,dword ptr [EAX + 0xc]
//         004ce0e8     MOV        this,dword ptr [ECX + this->_padding_]
//         004ce0eb     MOVSX      EAX,word ptr [EAX + 0x4a]
//         004ce0ef     MOV        EDX,dword ptr [this->_padding_]
//         004ce0f1     PUSH       EAX
//         004ce0f2     CALL       dword ptr [EDX + 0x1c]
//         004ce0f5     CMP        EAX,0x1
//         004ce0f8     JNZ        LAB_004ce147
//                              tact_cnv.cpp:353 (15)
//         004ce0fa     MOV        AL,byte ptr [ESI + 0xc]
//         004ce0fd     CMP        AL,0x7
//         004ce0ff     JZ         LAB_004ce109
//         004ce101     CMP        AL,0x6
//         004ce103     JZ         LAB_004ce109
//         004ce105     CMP        AL,0x4
//         004ce107     JNZ        LAB_004ce118
//                               LAB_004ce109                                                 XREF[2]:     004ce0ff(j), 004ce103(j)
//                              tact_cnv.cpp:356 (15)
//         004ce109     MOV        this,dword ptr [ESI + 0x8]
//         004ce10c     PUSH       0x0
//         004ce10e     PUSH       0x22
//         004ce110     MOV        EDX,dword ptr [this->_padding_]
//         004ce112     CALL       dword ptr [EDX + 0x80]
//                               LAB_004ce118                                                 XREF[1]:     004ce107(j)
//                              tact_cnv.cpp:359 (9)
//         004ce118     MOV        EAX,dword ptr [ESI]
//         004ce11a     PUSH       0x1
//         004ce11c     MOV        this,ESI
//         004ce11e     CALL       dword ptr [EAX + 0x5c]
//                              tact_cnv.cpp:360 (30)
//         004ce121     MOV        this,dword ptr [ESI + 0x8]
//         004ce124     PUSH       0x0
//         004ce126     PUSH       0x0
//         004ce128     PUSH       0x25c
//         004ce12d     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004ce130     MOV        EDX,dword ptr [this->_padding_]
//         004ce132     PUSH       0x1fb
//         004ce137     PUSH       EAX
//         004ce138     PUSH       EAX
//         004ce139     CALL       dword ptr [EDX + 0x148]
//                              tact_cnv.cpp:362 (2)
//         004ce13f     MOV        AL,0x4
//                              tact_cnv.cpp:522 (6)
//         004ce141     POP        EDI
//         004ce142     POP        ESI
//         004ce143     POP        EBP
//         004ce144     POP        EBX
//         004ce145     POP        this
//         004ce146     RET
//                               LAB_004ce147                                                 XREF[3]:     004ce0ba(j), 004ce0e0(j),
//                                                                                                         004ce0f8(j)
//                              tact_cnv.cpp:365 (30)
//         004ce147     XOR        EAX,EAX
//         004ce149     MOV        AL,byte ptr [ESI + 0xc]
//         004ce14c     DEC        EAX
//         004ce14d     CMP        EAX,0xc
//         004ce150     JA         switchD_004ce15e::caseD_2
//         004ce156     XOR        this,this
//         004ce158     MOV        this,byte ptr [EAX + 0x4ce418]=>PTR_caseD_2_00
//                               switchD_004ce15e::switchD
//         004ce15e     JMP        dword ptr [this->_padding_*0x4 + switchD_004ce   = 004ce3bb
//                               switchD_004ce15e::caseD_b                                    XREF[2]:     004ce15e(j), 004ce40c(*)
//                              tact_cnv.cpp:369 (30)
//         004ce165     MOV        this,dword ptr [ESI + 0x34]
//         004ce168     MOV        EDX,dword ptr [this->_padding_]
//         004ce16a     CALL       dword ptr [EDX + 0xc]
//         004ce16d     AND        EAX,0xff
//         004ce172     DEC        EAX
//         004ce173     CMP        EAX,0x4
//         004ce176     JA         switchD_004ce15e::caseD_2
//                               switchD_004ce17c::switchD
//         004ce17c     JMP        dword ptr [EAX*0x4 + switchD_004ce17c::switchd   = 004ce234
//                               switchD_004ce17c::caseD_2                                    XREF[2]:     004ce17c(j), 004ce430(*)
//                              tact_cnv.cpp:386 (9)
//         004ce183     MOV        EAX,dword ptr [ESI]
//         004ce185     PUSH       0xd
//         004ce187     MOV        this,ESI
//         004ce189     CALL       dword ptr [EAX + 0x5c]
//                              tact_cnv.cpp:521 (2)
//         004ce18c     XOR        AL,AL
//                              tact_cnv.cpp:522 (6)
//         004ce18e     POP        EDI
//         004ce18f     POP        ESI
//         004ce190     POP        EBP
//         004ce191     POP        EBX
//         004ce192     POP        this
//         004ce193     RET
//                               switchD_004ce15e::caseD_4                                    XREF[2]:     004ce15e(j), 004ce400(*)
//                              tact_cnv.cpp:401 (30)
//         004ce194     MOV        this,dword ptr [ESI + 0x34]
//         004ce197     MOV        EAX,dword ptr [this->_padding_]
//         004ce199     CALL       dword ptr [EAX + 0xc]
//         004ce19c     AND        EAX,0xff
//         004ce1a1     DEC        EAX
//         004ce1a2     CMP        EAX,0x4
//         004ce1a5     JA         switchD_004ce15e::caseD_2
//                               switchD_004ce1ab::switchD
//         004ce1ab     JMP        dword ptr [EAX*0x4 + switchD_004ce1ab::switchd   = 004ce1db
//                               switchD_004ce1ab::caseD_3                                    XREF[5]:     004ce17c(j), 004ce1ab(j),
//                               switchD_004ce1ab::caseD_4                                                 004ce434(*), 004ce448(*),
//                               switchD_004ce17c::caseD_3                                                 004ce44c(*)
//                              tact_cnv.cpp:410 (9)
//         004ce1b2     MOV        EDI,dword ptr [ESI]
//         004ce1b4     PUSH       0x0
//         004ce1b6     MOV        this,ESI
//         004ce1b8     CALL       dword ptr [EDI + 0x54]
//                              tact_cnv.cpp:411 (7)
//         004ce1bb     PUSH       0xb
//         004ce1bd     MOV        this,ESI
//         004ce1bf     CALL       dword ptr [EDI + 0x5c]
//                              tact_cnv.cpp:521 (2)
//         004ce1c2     XOR        AL,AL
//                              tact_cnv.cpp:522 (6)
//         004ce1c4     POP        EDI
//         004ce1c5     POP        ESI
//         004ce1c6     POP        EBP
//         004ce1c7     POP        EBX
//         004ce1c8     POP        this
//         004ce1c9     RET
//                               switchD_004ce1ab::caseD_2                                    XREF[2]:     004ce1ab(j), 004ce444(*)
//                              tact_cnv.cpp:419 (9)
//         004ce1ca     MOV        EDX,dword ptr [ESI]
//         004ce1cc     PUSH       0xd
//         004ce1ce     MOV        this,ESI
//         004ce1d0     CALL       dword ptr [EDX + 0x5c]
//                              tact_cnv.cpp:521 (2)
//         004ce1d3     XOR        AL,AL
//                              tact_cnv.cpp:522 (6)
//         004ce1d5     POP        EDI
//         004ce1d6     POP        ESI
//         004ce1d7     POP        EBP
//         004ce1d8     POP        EBX
//         004ce1d9     POP        this
//         004ce1da     RET
//                               switchD_004ce1ab::caseD_1                                    XREF[3]:     004ce1ab(j), 004ce43c(*),
//                               switchD_004ce1ab::caseD_0                                                 004ce440(*)
//                              tact_cnv.cpp:425 (9)
//         004ce1db     MOV        EAX,dword ptr [ESI]
//         004ce1dd     PUSH       0x6
//         004ce1df     MOV        this,ESI
//         004ce1e1     CALL       dword ptr [EAX + 0x5c]
//                              tact_cnv.cpp:521 (2)
//         004ce1e4     XOR        AL,AL
//                              tact_cnv.cpp:522 (6)
//         004ce1e6     POP        EDI
//         004ce1e7     POP        ESI
//         004ce1e8     POP        EBP
//         004ce1e9     POP        EBX
//         004ce1ea     POP        this
//         004ce1eb     RET
//                               switchD_004ce15e::caseD_6                                    XREF[2]:     004ce15e(j), 004ce404(*)
//                              tact_cnv.cpp:433 (7)
//         004ce1ec     MOV        EAX,dword ptr [ESI + 0x10]
//         004ce1ef     TEST       EAX,EAX
//         004ce1f1     JNZ        LAB_004ce204
//                              tact_cnv.cpp:435 (9)
//         004ce1f3     MOV        EDX,dword ptr [ESI]
//         004ce1f5     PUSH       0x3
//         004ce1f7     MOV        this,ESI
//         004ce1f9     CALL       dword ptr [EDX + 0x5c]
//                              tact_cnv.cpp:521 (2)
//         004ce1fc     XOR        AL,AL
//                              tact_cnv.cpp:522 (6)
//         004ce1fe     POP        EDI
//         004ce1ff     POP        ESI
//         004ce200     POP        EBP
//         004ce201     POP        EBX
//         004ce202     POP        this
//         004ce203     RET
//                               LAB_004ce204                                                 XREF[1]:     004ce1f1(j)
//                              tact_cnv.cpp:440 (24)
//         004ce204     MOV        this,dword ptr [ESI + 0x8]
//         004ce207     PUSH       0x0
//         004ce209     PUSH       0x0
//         004ce20b     PUSH       EAX
//         004ce20c     MOV        EDX,dword ptr [this->_padding_]
//         004ce20e     CALL       dword ptr [EDX + 0x1f0]
//         004ce214     TEST       AL,AL
//         004ce216     JZ         switchD_004ce15e::caseD_2
//                              tact_cnv.cpp:442 (9)
//         004ce21c     MOV        EAX,dword ptr [ESI]
//         004ce21e     PUSH       0x7
//         004ce220     MOV        this,ESI
//         004ce222     CALL       dword ptr [EAX + 0x5c]
//                              tact_cnv.cpp:521 (2)
//         004ce225     XOR        AL,AL
//                              tact_cnv.cpp:522 (6)
//         004ce227     POP        EDI
//         004ce228     POP        ESI
//         004ce229     POP        EBP
//         004ce22a     POP        EBX
//         004ce22b     POP        this
//         004ce22c     RET
//                               switchD_004ce15e::caseD_7                                    XREF[2]:     004ce15e(j), 004ce408(*)
//                              tact_cnv.cpp:451 (7)
//         004ce22d     MOV        EDI,dword ptr [ESI + 0x10]
//         004ce230     TEST       EDI,EDI
//         004ce232     JNZ        LAB_004ce245
//                               switchD_004ce17c::caseD_1                                    XREF[4]:     004ce17c(j), 004ce428(*),
//                               switchD_004ce17c::caseD_4                                                 004ce42c(*), 004ce438(*)
//                               switchD_004ce17c::caseD_0
//                              tact_cnv.cpp:453 (9)
//         004ce234     MOV        EDX,dword ptr [ESI]
//         004ce236     PUSH       0x3
//         004ce238     MOV        this,ESI
//         004ce23a     CALL       dword ptr [EDX + 0x5c]
//                              tact_cnv.cpp:521 (2)
//         004ce23d     XOR        AL,AL
//                              tact_cnv.cpp:522 (6)
//         004ce23f     POP        EDI
//         004ce240     POP        ESI
//         004ce241     POP        EBP
//         004ce242     POP        EBX
//         004ce243     POP        this
//         004ce244     RET
//                               LAB_004ce245                                                 XREF[1]:     004ce232(j)
//                              tact_cnv.cpp:460 (44)
//         004ce245     MOV        this,dword ptr [EDI + 0x8]
//         004ce248     MOV        EAX,dword ptr [ESI + 0x8]
//         004ce24b     FLD        float ptr [EDI + 0x30]
//         004ce24e     MOVSX      EDX,word ptr [ECX + this+0x26]
//         004ce252     MOV        EBX,dword ptr [EAX + 0x4]
//         004ce255     MOV        EBP,dword ptr [EDI]
//         004ce257     PUSH       EDX
//         004ce258     CALL       __ftol                                           undefined __ftol()
//         004ce25d     PUSH       EAX
//         004ce25e     MOV        EAX,dword ptr [EDI + 0x4]
//         004ce261     PUSH       EBX
//         004ce262     PUSH       0x1f4
//         004ce267     PUSH       EAX
//         004ce268     PUSH       EBX
//         004ce269     MOV        this,EDI
//         004ce26b     CALL       dword ptr [EBP + 0x148]
//                              tact_cnv.cpp:463 (21)
//         004ce271     MOV        EDX,dword ptr [ESI + 0x8]
//         004ce274     FLD        float ptr [ESI + 0x2c]
//         004ce277     MOV        this,dword ptr [EDX + 0xc]
//         004ce27a     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004ce27d     FSUB       float ptr [EAX + 0x84]
//         004ce283     FST        float ptr [ESI + 0x2c]
//                              tact_cnv.cpp:464 (17)
//         004ce286     FCOMP      float ptr [DAT_00574ff8]
//         004ce28c     FNSTSW     AX
//         004ce28e     TEST       AH,0x41
//         004ce291     JZ         switchD_004ce15e::caseD_2
//                              tact_cnv.cpp:468 (17)
//         004ce297     MOV        EAX,dword ptr [ESI + 0x10]
//         004ce29a     TEST       EAX,EAX
//         004ce29c     JZ         LAB_004ce2c0
//         004ce29e     MOV        this,dword ptr [EAX + 0xc]
//         004ce2a1     CMP        word ptr [this->_padding_ + 0x4a],0x0
//         004ce2a6     JLE        LAB_004ce2c0
//                              tact_cnv.cpp:469 (24)
//         004ce2a8     MOV        EDI,dword ptr [EDX + 0x40]
//         004ce2ab     MOV        EAX,dword ptr [this->_padding_]
//         004ce2ad     PUSH       0x0
//         004ce2af     PUSH       EDI
//         004ce2b0     MOV        EDI,dword ptr [EDX + 0x3c]
//         004ce2b3     MOV        EDX,dword ptr [EDX + 0x38]
//         004ce2b6     PUSH       EDI
//         004ce2b7     PUSH       EDX
//                              language.dll match for 0x70: "B"
//         004ce2b8     PUSH       0x70
//         004ce2ba     CALL       dword ptr [EAX + 0x94]
//                               LAB_004ce2c0                                                 XREF[2]:     004ce29c(j), 004ce2a6(j)
//                              tact_cnv.cpp:471 (19)
//         004ce2c0     PUSH       0x1d7
//         004ce2c5     PUSH       s_C:\msdev\work\age1_x1\tact_cnv.c               = "C:\\msdev\\work\\age1_x1\\tact_cnv.cpp"
//         004ce2ca     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         004ce2cf     MOV        dword ptr [ESP + 0x18],EAX
//                              tact_cnv.cpp:474 (30)
//         004ce2d3     MOV        EAX,dword ptr [ESI + 0x10]
//         004ce2d6     FILD       dword ptr [ESP + 0x18]
//         004ce2da     MOV        EDI,dword ptr [EAX + 0xc]
//         004ce2dd     ADD        ESP,0x8
//         004ce2e0     MOV        this,byte ptr [EDI + 0x105]
//         004ce2e6     FMUL       float ptr [DAT_00574ffc]
//         004ce2ec     CMP        this,0x10
//         004ce2ef     JNZ        LAB_004ce2f9
//                              tact_cnv.cpp:475 (6)
//         004ce2f1     FMUL       float ptr [DAT_00575000]
//                              tact_cnv.cpp:477 (2)
//         004ce2f7     JMP        LAB_004ce334
//                               LAB_004ce2f9                                                 XREF[1]:     004ce2ef(j)
//                              tact_cnv.cpp:481 (37)
//         004ce2f9     MOV        EAX,dword ptr [EAX + 0x8]
//         004ce2fc     MOV        AX,word ptr [EAX + 0x14]
//         004ce300     CMP        AX,0x15
//         004ce304     JZ         LAB_004ce332
//         004ce306     CMP        AX,0x2
//         004ce30a     JZ         LAB_004ce332
//         004ce30c     CMP        AX,0x14
//         004ce310     JZ         LAB_004ce332
//         004ce312     CMP        AX,0x16
//         004ce316     JZ         LAB_004ce332
//         004ce318     CMP        AX,0x12
//         004ce31c     JZ         LAB_004ce332
//                              tact_cnv.cpp:485 (12)
//         004ce31e     CMP        AX,0x23
//         004ce322     JZ         LAB_004ce32a
//         004ce324     CMP        AX,0x17
//         004ce328     JNZ        LAB_004ce334
//                               LAB_004ce32a                                                 XREF[1]:     004ce322(j)
//                              tact_cnv.cpp:486 (8)
//         004ce32a     FMUL       float ptr [DAT_00575004]
//         004ce330     JMP        LAB_004ce334
//                               LAB_004ce332                                                 XREF[5]:     004ce304(j), 004ce30a(j),
//                                                                                                         004ce310(j), 004ce316(j),
//                                                                                                         004ce31c(j)
//                              tact_cnv.cpp:482 (2)
//         004ce332     FADD       ST0,ST0
//                               LAB_004ce334                                                 XREF[3]:     004ce2f7(j), 004ce328(j),
//                                                                                                         004ce330(j)
//                              tact_cnv.cpp:488 (29)
//         004ce334     MOV        EDX,dword ptr [ESI + 0x8]
//         004ce337     MOV        this,dword ptr [ESI + 0x30]
//         004ce33a     MOV        EAX,dword ptr [EDX + 0x8]
//         004ce33d     FLD        float ptr [ECX + this->_padding_]
//         004ce340     FMUL       float ptr [EAX + 0xe4]
//         004ce346     FXCH
//         004ce348     FCOMPP
//         004ce34a     FNSTSW     AX
//         004ce34c     TEST       AH,0x41
//         004ce34f     JZ         LAB_004ce3aa
//                              tact_cnv.cpp:490 (30)
//         004ce351     MOV        EDX,dword ptr [EDX + 0xc]
//         004ce354     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004ce35a     MOVSX      EDI,word ptr [EDI + 0x4a]
//         004ce35e     MOVSX      EDX,word ptr [EDX + 0x4a]
//         004ce362     MOV        EAX,dword ptr [this->_padding_]
//         004ce364     PUSH       0x0
//         004ce366     PUSH       0x0
//         004ce368     PUSH       EDI
//         004ce369     PUSH       EDX
//                              language.dll match for 0x7b: "9"
//         004ce36a     PUSH       0x7b
//         004ce36c     CALL       dword ptr [EAX + 0x40]
//                              tact_cnv.cpp:492 (15)
//         004ce36f     MOV        EDX,dword ptr [ESI + 0x8]
//         004ce372     MOV        this,dword ptr [ESI + 0x10]
//         004ce375     MOV        EDX,dword ptr [EDX + 0xc]
//         004ce378     MOV        EAX,dword ptr [this->_padding_]
//         004ce37a     PUSH       EDX
//         004ce37b     CALL       dword ptr [EAX + 0x44]
//                              tact_cnv.cpp:494 (20)
//         004ce37e     MOV        EAX,dword ptr [ESI + 0x8]
//         004ce381     PUSH       0x0
//         004ce383     PUSH       0x3f800000
//         004ce388     PUSH       0x29
//         004ce38a     MOV        this,dword ptr [EAX + 0xc]
//         004ce38d     MOV        EDX,dword ptr [this->_padding_]
//         004ce38f     CALL       dword ptr [EDX + 0x78]
//                              tact_cnv.cpp:497 (15)
//         004ce392     MOV        this,dword ptr [ESI + 0x8]
//         004ce395     PUSH       0x0
//         004ce397     PUSH       0x22
//         004ce399     MOV        EAX,dword ptr [this->_padding_]
//         004ce39b     CALL       dword ptr [EAX + 0x80]
//                              tact_cnv.cpp:499 (9)
//         004ce3a1     MOV        EDX,dword ptr [ESI]
//         004ce3a3     PUSH       0x3
//         004ce3a5     MOV        this,ESI
//         004ce3a7     CALL       dword ptr [EDX + 0x5c]
//                               LAB_004ce3aa                                                 XREF[1]:     004ce34f(j)
//                              tact_cnv.cpp:502 (9)
//         004ce3aa     MOV        EAX,dword ptr [ESI]
//         004ce3ac     PUSH       0x4
//         004ce3ae     MOV        this,ESI
//         004ce3b0     CALL       dword ptr [EAX + 0x5c]
//                              tact_cnv.cpp:521 (2)
//         004ce3b3     XOR        AL,AL
//                              tact_cnv.cpp:522 (6)
//         004ce3b5     POP        EDI
//         004ce3b6     POP        ESI
//         004ce3b7     POP        EBP
//         004ce3b8     POP        EBX
//         004ce3b9     POP        this
//         004ce3ba     RET
//                               switchD_004ce15e::caseD_1                                    XREF[2]:     004ce15e(j), 004ce3fc(*)
//                              tact_cnv.cpp:512 (2)
//         004ce3bb     MOV        AL,0x1
//                              tact_cnv.cpp:522 (6)
//         004ce3bd     POP        EDI
//         004ce3be     POP        ESI
//         004ce3bf     POP        EBP
//         004ce3c0     POP        EBX
//         004ce3c1     POP        this
//         004ce3c2     RET
//                               switchD_004ce15e::caseD_d                                    XREF[2]:     004ce15e(j), 004ce410(*)
//                              tact_cnv.cpp:516 (30)
//         004ce3c3     MOV        this,dword ptr [ESI + 0x8]
//         004ce3c6     PUSH       0x0
//         004ce3c8     PUSH       0x0
//         004ce3ca     PUSH       0x25c
//         004ce3cf     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004ce3d2     MOV        EDX,dword ptr [this->_padding_]
//         004ce3d4     PUSH       0x1f9
//         004ce3d9     PUSH       EAX
//         004ce3da     PUSH       EAX
//         004ce3db     CALL       dword ptr [EDX + 0x148]
//                              tact_cnv.cpp:517 (9)
//         004ce3e1     MOV        EAX,dword ptr [ESI]
//         004ce3e3     PUSH       0x2
//         004ce3e5     MOV        this,ESI
//         004ce3e7     CALL       dword ptr [EAX + 0x5c]
//                              tact_cnv.cpp:518 (2)
//         004ce3ea     MOV        AL,0x3
//                              tact_cnv.cpp:522 (100)
//         004ce3ec     POP        EDI
//         004ce3ed     POP        ESI
//         004ce3ee     POP        EBP
//         004ce3ef     POP        EBX
//         004ce3f0     POP        this
//         004ce3f1     RET
//                               switchD_004ce15e::caseD_3                                    XREF[7]:     004ce150(j), 004ce15e(j),
//                               switchD_004ce15e::caseD_5                                                 004ce176(j), 004ce1a5(j),
//                               switchD_004ce15e::caseD_8                                                 004ce216(j), 004ce291(j),
//                               switchD_004ce15e::caseD_9                                                 004ce414(*)
//                               switchD_004ce15e::caseD_a
//                               switchD_004ce15e::caseD_c
//                               switchD_004ce17c::default
//                               switchD_004ce1ab::default
//                               switchD_004ce15e::caseD_2
//         004ce3f2     POP        EDI
//         004ce3f3     POP        ESI
//         004ce3f4     POP        EBP
//         004ce3f5     XOR        AL,AL
//         004ce3f7     POP        EBX
//         004ce3f8     POP        this
//         004ce3f9     RET
    return 0;
}

int TRIBE_Action_Convert::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    /* TODO: Stub */
//                              int __thiscall work(TRIBE_Action_Convert * this, RGE_Static_Object *
//              int               EAX:4          <RETURN>
//              TRIBE_Action_C    ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004ce453(R)
//              float             Stack[0x8]:4   param_2
//              float             Stack[0xc]:4   param_3
//              float             Stack[0x10]:4  param_4
//                               ?work@TRIBE_Action_Convert@@UAEHPAVRGE_Static_Object@@MMM@Z  XREF[1]:     00574fc4(*)
//                               TRIBE_Action_Convert::work
//                              tact_cnv.cpp:529 (3)
//         004ce450     PUSH       EBX
//         004ce451     PUSH       ESI
//         004ce452     PUSH       EDI
//                              tact_cnv.cpp:530 (10)
//         004ce453     MOV        EDI,dword ptr [ESP + param_1]
//         004ce457     TEST       EDI,EDI
//         004ce459     MOV        ESI,this
//         004ce45b     JZ         LAB_004ce4a8
//                              tact_cnv.cpp:534 (20)
//         004ce45d     CMP        EDI,dword ptr [ESI + 0x10]
//         004ce460     JNZ        LAB_004ce47c
//         004ce462     MOV        AL,byte ptr [ESI + 0xc]
//         004ce465     CMP        AL,0x4
//         004ce467     JZ         LAB_004ce49d
//         004ce469     CMP        AL,0x6
//         004ce46b     JZ         LAB_004ce49d
//         004ce46d     CMP        AL,0x7
//         004ce46f     JNZ        LAB_004ce47c
//                              tact_cnv.cpp:535 (5)
//         004ce471     MOV        EAX,0x1
//                              tact_cnv.cpp:547 (6)
//         004ce476     POP        EDI
//         004ce477     POP        ESI
//         004ce478     POP        EBX
//         004ce479     RET        0x10
//                               LAB_004ce47c                                                 XREF[2]:     004ce460(j), 004ce46f(j)
//                              tact_cnv.cpp:537 (8)
//         004ce47c     MOV        EBX,dword ptr [ESI]
//         004ce47e     PUSH       EDI
//         004ce47f     MOV        this,ESI
//         004ce481     CALL       dword ptr [EBX + 0x54]
//                              tact_cnv.cpp:538 (3)
//         004ce484     MOV        EAX,dword ptr [EDI + 0x38]
//                              tact_cnv.cpp:542 (22)
//         004ce487     PUSH       0x1
//         004ce489     MOV        dword ptr [ESI + 0x20],EAX
//         004ce48c     MOV        this,dword ptr [EDI + 0x3c]
//         004ce48f     MOV        dword ptr [ESI + 0x24],this
//         004ce492     MOV        EDX,dword ptr [EDI + 0x40]
//         004ce495     MOV        this,ESI
//         004ce497     MOV        dword ptr [ESI + 0x28],EDX
//         004ce49a     CALL       dword ptr [EBX + 0x1c]
//                               LAB_004ce49d                                                 XREF[2]:     004ce467(j), 004ce46b(j)
//                              tact_cnv.cpp:543 (5)
//         004ce49d     MOV        EAX,0x1
//                              tact_cnv.cpp:547 (14)
//         004ce4a2     POP        EDI
//         004ce4a3     POP        ESI
//         004ce4a4     POP        EBX
//         004ce4a5     RET        0x10
//                               LAB_004ce4a8                                                 XREF[1]:     004ce45b(j)
//         004ce4a8     POP        EDI
//         004ce4a9     POP        ESI
//         004ce4aa     XOR        EAX,EAX
//         004ce4ac     POP        EBX
//         004ce4ad     RET        0x10
    return 0;
}

void TRIBE_Action_Convert::martyrdom() {
    /* TODO: Stub */
//                              void __thiscall martyrdom(TRIBE_Action_Convert * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Action_C    ECX:4 (auto)   this
//                               ?martyrdom@TRIBE_Action_Convert@@QAEXXZ                      XREF[1]:     die_die_die:004ca7d3(c)
//                               TRIBE_Action_Convert::martyrdom
//                              tact_cnv.cpp:553 (3)
//         004ce4b0     PUSH       ESI
//         004ce4b1     MOV        ESI,this
//                              tact_cnv.cpp:554 (23)
//         004ce4b3     CMP        byte ptr [ESI + 0xc],0x7
//         004ce4b7     JNZ        LAB_004ce529
//         004ce4b9     MOV        EAX,dword ptr [ESI + 0x10]
//         004ce4bc     TEST       EAX,EAX
//         004ce4be     JZ         LAB_004ce529
//         004ce4c0     MOV        this,dword ptr [EAX + 0x8]
//         004ce4c3     CMP        word ptr [ECX + this->_padding_],0x12
//         004ce4c8     JZ         LAB_004ce529
//                              tact_cnv.cpp:556 (36)
//         004ce4ca     MOV        EAX,dword ptr [EAX + 0xc]
//         004ce4cd     PUSH       0x0
//         004ce4cf     PUSH       0x0
//         004ce4d1     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004ce4d7     MOVSX      EAX,word ptr [EAX + 0x4a]
//         004ce4db     PUSH       EAX
//         004ce4dc     MOV        EAX,dword ptr [ESI + 0x8]
//         004ce4df     MOV        EDX,dword ptr [this->_padding_]
//         004ce4e1     MOV        EAX,dword ptr [EAX + 0xc]
//         004ce4e4     MOVSX      EAX,word ptr [EAX + 0x4a]
//         004ce4e8     PUSH       EAX
//                              language.dll match for 0x7b: "9"
//         004ce4e9     PUSH       0x7b
//         004ce4eb     CALL       dword ptr [EDX + 0x40]
//                              tact_cnv.cpp:558 (15)
//         004ce4ee     MOV        EAX,dword ptr [ESI + 0x8]
//         004ce4f1     MOV        this,dword ptr [ESI + 0x10]
//         004ce4f4     MOV        EAX,dword ptr [EAX + 0xc]
//         004ce4f7     MOV        EDX,dword ptr [this->_padding_]
//         004ce4f9     PUSH       EAX
//         004ce4fa     CALL       dword ptr [EDX + 0x44]
//                              tact_cnv.cpp:560 (20)
//         004ce4fd     MOV        this,dword ptr [ESI + 0x8]
//         004ce500     PUSH       0x0
//         004ce502     PUSH       0x3f800000
//         004ce507     PUSH       0x29
//         004ce509     MOV        this,dword ptr [ECX + this->_padding_]
//         004ce50c     MOV        EDX,dword ptr [this->_padding_]
//         004ce50e     CALL       dword ptr [EDX + 0x78]
//                              tact_cnv.cpp:563 (15)
//         004ce511     MOV        this,dword ptr [ESI + 0x8]
//         004ce514     PUSH       0x0
//         004ce516     PUSH       0x22
//         004ce518     MOV        EAX,dword ptr [this->_padding_]
//         004ce51a     CALL       dword ptr [EAX + 0x80]
//                              tact_cnv.cpp:565 (9)
//         004ce520     MOV        EDX,dword ptr [ESI]
//         004ce522     PUSH       0x3
//         004ce524     MOV        this,ESI
//         004ce526     CALL       dword ptr [EDX + 0x5c]
//                               LAB_004ce529                                                 XREF[3]:     004ce4b7(j), 004ce4be(j),
//                                                                                                         004ce4c8(j)
//                              tact_cnv.cpp:567 (2)
//         004ce529     POP        ESI
//         004ce52a     RET
//         004ce52b     ??         90h
//         004ce52c     NOP
//         004ce52d     NOP
//         004ce52e     NOP
//         004ce52f     NOP
    return;
}

TRIBE_Action_Convert::~TRIBE_Action_Convert() {
    /* TODO: Stub */
//                              void __thiscall ~TRIBE_Action_Convert(TRIBE_Action_Convert * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Action_C    ECX:4 (auto)   this
//                               ??1TRIBE_Action_Convert@@UAE@XZ                              XREF[1]:     `vector_deleting_destructor':004cd
//                               TRIBE_Action_Convert::~TRIBE_Action_Convert
//         004cda80     JMP        RGE_Action::~RGE_Action
//         004cda85     ??         90h
//         004cda86     NOP
//         004cda87     NOP
//         004cda88     NOP
//         004cda89     NOP
//         004cda8a     NOP
//         004cda8b     NOP
//         004cda8c     NOP
//         004cda8d     NOP
//         004cda8e     NOP
//         004cda8f     NOP
}

