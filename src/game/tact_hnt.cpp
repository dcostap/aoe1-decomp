#include "../common.h"
#include "tact_hnt.h"

TRIBE_Action_Hunt::TRIBE_Action_Hunt(int param_1, RGE_Action_Object* param_2) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Action_Hunt(TRIBE_Action_Hunt * this, int
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Action_H    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004cf0ac(R)
//              RGE_Action_Obj    Stack[0x8]:4   param_2                   XREF[1]:     004cf0a6(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004cf0c6(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004cf0df(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004cf0b6(W)
//                               ??0TRIBE_Action_Hunt@@QAE@HPAVRGE_Action_Object@@@Z          XREF[1]:     create_action:004d03d3(c)
//                               TRIBE_Action_Hunt::TRIBE_Action_Hunt
//                              tact_hnt.cpp:70 (47)
//         004cf090     PUSH       -0x1
//         004cf092     PUSH       FUN_0055fea8
//         004cf097     MOV        EAX,FS:[0x0]
//         004cf09d     PUSH       EAX
//         004cf09e     MOV        dword ptr FS:[0x0],ESP
//         004cf0a5     PUSH       this
//         004cf0a6     MOV        EAX,dword ptr [ESP + param_2]
//         004cf0aa     PUSH       ESI
//         004cf0ab     PUSH       EDI
//         004cf0ac     MOV        EDI,dword ptr [ESP + param_1]
//         004cf0b0     PUSH       0x1
//         004cf0b2     MOV        ESI,this
//         004cf0b4     PUSH       EAX
//         004cf0b5     PUSH       EDI
//         004cf0b6     MOV        dword ptr [ESP + local_10],ESI
//         004cf0ba     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, int p
//                              tact_hnt.cpp:72 (32)
//         004cf0bf     LEA        this,[ESI + 0x40]
//         004cf0c2     PUSH       0x4
//         004cf0c4     PUSH       this
//         004cf0c5     PUSH       EDI
//         004cf0c6     MOV        dword ptr [ESP + local_4],0x0
//         004cf0ce     MOV        dword ptr [ESI],TRIBE_Action_Hunt::`vftable'     = 004cf100
//                              language.dll match for 0x6e: "Copperplate Gothic Light"
//         004cf0d4     MOV        word ptr [ESI + 0x4],0x6e
//         004cf0da     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              tact_hnt.cpp:73 (24)
//         004cf0df     MOV        this,dword ptr [ESP + local_c]
//         004cf0e3     ADD        ESP,0xc
//         004cf0e6     MOV        EAX,ESI
//         004cf0e8     MOV        dword ptr FS:[0x0],this
//         004cf0ef     POP        EDI
//         004cf0f0     POP        ESI
//         004cf0f1     ADD        ESP,0x10
//         004cf0f4     RET        0x8
//         004cf0f7     ??         90h
//         004cf0f8     NOP
//         004cf0f9     NOP
//         004cf0fa     NOP
//         004cf0fb     NOP
//         004cf0fc     NOP
//         004cf0fd     NOP
//         004cf0fe     NOP
//         004cf0ff     NOP
}

TRIBE_Action_Hunt::TRIBE_Action_Hunt(RGE_Action_Object* param_1, RGE_Task* param_2, RGE_Static_Object* param_3) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Action_Hunt(TRIBE_Action_Hunt * this, RGE
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Action_H    ECX:4 (auto)   this
//              RGE_Action_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004cf146(R)
//              RGE_Task *        Stack[0x8]:4   param_2                   XREF[1]:     004cf15a(R)
//              RGE_Static_Obj    Stack[0xc]:4   param_3                   XREF[1]:     004cf15e(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004cf168(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004cf1a7(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004cf151(W)
//                               ??0TRIBE_Action_Hunt@@QAE@PAVRGE_Action_Object@@PAVRGE_Task  XREF[2]:     hunt:004cb162(c),
//                               TRIBE_Action_Hunt::TRIBE_Action_Hunt                                      create_task_action:004d0952(c)
//                              tact_hnt.cpp:81 (42)
//         004cf130     PUSH       -0x1
//         004cf132     PUSH       FUN_0055fec8
//         004cf137     MOV        EAX,FS:[0x0]
//         004cf13d     PUSH       EAX
//         004cf13e     MOV        dword ptr FS:[0x0],ESP
//         004cf145     PUSH       this
//         004cf146     MOV        EAX,dword ptr [ESP + param_1]
//         004cf14a     PUSH       ESI
//         004cf14b     PUSH       EDI
//         004cf14c     MOV        ESI,this
//         004cf14e     PUSH       0x1
//         004cf150     PUSH       EAX
//         004cf151     MOV        dword ptr [ESP + local_10],ESI
//         004cf155     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, RGE_A
//                              tact_hnt.cpp:83 (4)
//         004cf15a     MOV        this,dword ptr [ESP + param_2]
//                              tact_hnt.cpp:85 (35)
//         004cf15e     MOV        EDI,dword ptr [ESP + param_3]
//         004cf162     MOV        dword ptr [ESI + 0x30],this
//         004cf165     PUSH       EDI
//         004cf166     MOV        this,ESI
//         004cf168     MOV        dword ptr [ESP + local_4],0x0
//         004cf170     MOV        dword ptr [ESI],TRIBE_Action_Hunt::`vftable'     = 004cf100
//                              language.dll match for 0x6e: "Copperplate Gothic Light"
//         004cf176     MOV        word ptr [ESI + 0x4],0x6e
//         004cf17c     CALL       RGE_Action::set_target_obj                       void set_target_obj(RGE_Action * this, RGE_St
//                              tact_hnt.cpp:87 (10)
//         004cf181     TEST       EDI,EDI
//         004cf183     JZ         LAB_004cf1a7
//         004cf185     CMP        byte ptr [EDI + 0x48],0x7
//         004cf189     JNC        LAB_004cf1a7
//                              tact_hnt.cpp:89 (6)
//         004cf18b     MOV        EDX,dword ptr [EDI + 0x38]
//         004cf18e     MOV        dword ptr [ESI + 0x20],EDX
//                              tact_hnt.cpp:90 (6)
//         004cf191     MOV        EAX,dword ptr [EDI + 0x3c]
//         004cf194     MOV        dword ptr [ESI + 0x24],EAX
//                              tact_hnt.cpp:91 (6)
//         004cf197     MOV        this,dword ptr [EDI + 0x40]
//         004cf19a     MOV        dword ptr [ESI + 0x28],this
//                              tact_hnt.cpp:92 (10)
//         004cf19d     MOV        EDX,dword ptr [EDI + 0x8]
//         004cf1a0     MOVSX      EAX,word ptr [EDX + 0x10]
//         004cf1a4     MOV        dword ptr [ESI + 0x40],EAX
//                               LAB_004cf1a7                                                 XREF[2]:     004cf183(j), 004cf189(j)
//                              tact_hnt.cpp:105 (21)
//         004cf1a7     MOV        this,dword ptr [ESP + local_c]
//         004cf1ab     MOV        EAX,ESI
//         004cf1ad     POP        EDI
//         004cf1ae     MOV        dword ptr FS:[0x0],this
//         004cf1b5     POP        ESI
//         004cf1b6     ADD        ESP,0x10
//         004cf1b9     RET        0xc
//         004cf1bc     ??         90h
//         004cf1bd     NOP
//         004cf1be     NOP
//         004cf1bf     NOP
}

TRIBE_Action_Hunt::TRIBE_Action_Hunt(RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Action_Hunt(TRIBE_Action_Hunt * this, RGE
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Action_H    ECX:4 (auto)   this
//              RGE_Action_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004cf1c0(R)
//              RGE_Task *        Stack[0x8]:4   param_2                   XREF[1]:     004cf1cf(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     004cf1d7(R)
//              float             Stack[0x10]:4  param_4                   XREF[1]:     004cf1d3(R)
//              float             Stack[0x14]:4  param_5                   XREF[1]:     004cf1de(R)
//                               ??0TRIBE_Action_Hunt@@QAE@PAVRGE_Action_Object@@PAVRGE_Task  XREF[1]:     create_task_action:004d099d(c)
//                               TRIBE_Action_Hunt::TRIBE_Action_Hunt
//                              tact_hnt.cpp:113 (15)
//         004cf1c0     MOV        EAX,dword ptr [ESP + param_1]
//         004cf1c4     PUSH       ESI
//         004cf1c5     PUSH       0x1
//         004cf1c7     MOV        ESI,this
//         004cf1c9     PUSH       EAX
//         004cf1ca     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, RGE_A
//                              tact_hnt.cpp:115 (4)
//         004cf1cf     MOV        this,dword ptr [ESP + param_2]
//                              tact_hnt.cpp:117 (11)
//         004cf1d3     MOV        EAX,dword ptr [ESP + param_4]
//         004cf1d7     MOV        EDX,dword ptr [ESP + param_3]
//         004cf1db     MOV        dword ptr [ESI + 0x30],this
//                              tact_hnt.cpp:118 (25)
//         004cf1de     MOV        this,dword ptr [ESP + param_5]
//         004cf1e2     MOV        dword ptr [ESI + 0x24],EAX
//         004cf1e5     MOV        dword ptr [ESI],TRIBE_Action_Hunt::`vftable'     = 004cf100
//         004cf1eb     MOV        word ptr [ESI + 0x4],0x6e
//         004cf1f1     MOV        dword ptr [ESI + 0x20],EDX
//         004cf1f4     MOV        dword ptr [ESI + 0x28],this
//                              tact_hnt.cpp:119 (7)
//         004cf1f7     MOV        dword ptr [ESI + 0x40],0xffffffff
//                              tact_hnt.cpp:124 (6)
//         004cf1fe     MOV        EAX,ESI
//         004cf200     POP        ESI
//         004cf201     RET        0x14
//         004cf204     ??         90h
//         004cf205     NOP
//         004cf206     NOP
//         004cf207     NOP
//         004cf208     NOP
//         004cf209     NOP
//         004cf20a     NOP
//         004cf20b     NOP
//         004cf20c     NOP
//         004cf20d     NOP
//         004cf20e     NOP
//         004cf20f     NOP
}

void TRIBE_Action_Hunt::save(int param_1) {
    /* TODO: Stub */
//                              void __thiscall save(TRIBE_Action_Hunt * this, int param_1)
//              void              <VOID>         <RETURN>
//              TRIBE_Action_H    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004cf212(R)
//                               ?save@TRIBE_Action_Hunt@@UAEXH@Z                             XREF[1]:     00575104(*)
//                               TRIBE_Action_Hunt::save
//                              tact_hnt.cpp:130 (2)
//         004cf210     PUSH       ESI
//         004cf211     PUSH       EDI
//                              tact_hnt.cpp:131 (12)
//         004cf212     MOV        EDI,dword ptr [ESP + param_1]
//         004cf216     MOV        ESI,this
//         004cf218     PUSH       EDI
//         004cf219     CALL       RGE_Action::save                                 void save(RGE_Action * this, int param_1)
//                              tact_hnt.cpp:132 (15)
//         004cf21e     ADD        ESI,0x40
//         004cf221     PUSH       0x4
//         004cf223     PUSH       ESI
//         004cf224     PUSH       EDI
//         004cf225     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004cf22a     ADD        ESP,0xc
//                              tact_hnt.cpp:133 (5)
//         004cf22d     POP        EDI
//         004cf22e     POP        ESI
//         004cf22f     RET        0x4
//         004cf232     ??         90h
//         004cf233     NOP
//         004cf234     NOP
//         004cf235     NOP
//         004cf236     NOP
//         004cf237     NOP
//         004cf238     NOP
//         004cf239     NOP
//         004cf23a     NOP
//         004cf23b     NOP
//         004cf23c     NOP
//         004cf23d     NOP
//         004cf23e     NOP
//         004cf23f     NOP
    return;
}

void TRIBE_Action_Hunt::first_in_stack(uchar param_1) {
    /* TODO: Stub */
//                              void __thiscall first_in_stack(TRIBE_Action_Hunt * this, uchar param
//              void              <VOID>         <RETURN>
//              TRIBE_Action_H    ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     004cf25f(R)
//                               ?first_in_stack@TRIBE_Action_Hunt@@UAEXE@Z                   XREF[1]:     0057510c(*)
//                               TRIBE_Action_Hunt::first_in_stack
//                              tact_hnt.cpp:139 (4)
//         004cf240     PUSH       ESI
//         004cf241     MOV        ESI,this
//         004cf243     PUSH       EDI
//                              tact_hnt.cpp:142 (16)
//         004cf244     MOV        EAX,dword ptr [ESI + 0x30]
//         004cf247     MOV        this,dword ptr [ESI + 0x8]
//         004cf24a     MOV        AX,word ptr [EAX + 0x14]
//         004cf24e     CMP        word ptr [this->_padding_ + 0x4c],AX
//         004cf252     JZ         LAB_004cf25f
//                              tact_hnt.cpp:143 (11)
//         004cf254     MOV        EDX,dword ptr [this->_padding_]
//         004cf256     PUSH       0x0
//         004cf258     PUSH       EAX
//         004cf259     CALL       dword ptr [EDX + 0x80]
//                               LAB_004cf25f                                                 XREF[1]:     004cf252(j)
//                              tact_hnt.cpp:145 (12)
//         004cf25f     MOV        AL,byte ptr [ESP + param_1]
//         004cf263     TEST       AL,AL
//         004cf265     JZ         LAB_004cf2ee
//                              tact_hnt.cpp:147 (7)
//         004cf26b     MOV        this,dword ptr [ESI + 0x10]
//         004cf26e     TEST       this,this
//         004cf270     JZ         LAB_004cf2e0
//                              tact_hnt.cpp:154 (55)
//         004cf272     MOV        EDI,dword ptr [ESI + 0x8]
//         004cf275     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004cf278     CMP        EAX,dword ptr [EDI + 0xc]
//         004cf27b     JNZ        LAB_004cf2d2
//         004cf27d     MOV        EDX,dword ptr [ECX + this->_padding_]
//         004cf280     MOV        EAX,dword ptr [EDI + 0x8]
//         004cf283     MOV        DX,word ptr [EDX + 0x10]
//         004cf287     CMP        DX,word ptr [EAX + 0xe8]
//         004cf28e     JZ         LAB_004cf299
//         004cf290     CMP        DX,word ptr [EAX + 0xea]
//         004cf297     JNZ        LAB_004cf2d2
//                               LAB_004cf299                                                 XREF[1]:     004cf28e(j)
//         004cf299     FLD        float ptr [EDI + 0x44]
//         004cf29c     FCOMP      float ptr [DAT_00575150]                         = align(18)
//         004cf2a2     FNSTSW     AX
//         004cf2a4     TEST       AH,0x41
//         004cf2a7     JNZ        LAB_004cf2d2
//                              tact_hnt.cpp:156 (8)
//         004cf2a9     MOV        EDI,dword ptr [ESI]
//         004cf2ab     PUSH       this
//         004cf2ac     MOV        this,ESI
//         004cf2ae     CALL       dword ptr [EDI + 0x58]
//                              tact_hnt.cpp:157 (7)
//         004cf2b1     PUSH       0x0
//         004cf2b3     MOV        this,ESI
//         004cf2b5     CALL       dword ptr [EDI + 0x54]
//                              tact_hnt.cpp:158 (5)
//         004cf2b8     MOV        EAX,0xbf800000
//                              tact_hnt.cpp:161 (16)
//         004cf2bd     PUSH       0x8
//         004cf2bf     MOV        this,ESI
//         004cf2c1     MOV        dword ptr [ESI + 0x20],EAX
//         004cf2c4     MOV        dword ptr [ESI + 0x24],EAX
//         004cf2c7     MOV        dword ptr [ESI + 0x28],EAX
//         004cf2ca     CALL       dword ptr [EDI + 0x5c]
//                              tact_hnt.cpp:171 (5)
//         004cf2cd     POP        EDI
//         004cf2ce     POP        ESI
//         004cf2cf     RET        0x4
//                               LAB_004cf2d2                                                 XREF[3]:     004cf27b(j), 004cf297(j),
//                                                                                                         004cf2a7(j)
//                              tact_hnt.cpp:164 (4)
//         004cf2d2     MOV        EAX,dword ptr [ESI]
//         004cf2d4     PUSH       0x4
//                              tact_hnt.cpp:170 (5)
//         004cf2d6     MOV        this,ESI
//         004cf2d8     CALL       dword ptr [EAX + 0x5c]
//                              tact_hnt.cpp:171 (5)
//         004cf2db     POP        EDI
//         004cf2dc     POP        ESI
//         004cf2dd     RET        0x4
//                               LAB_004cf2e0                                                 XREF[1]:     004cf270(j)
//                              tact_hnt.cpp:167 (9)
//         004cf2e0     MOV        EDX,dword ptr [ESI]
//         004cf2e2     PUSH       0x3
//         004cf2e4     MOV        this,ESI
//         004cf2e6     CALL       dword ptr [EDX + 0x5c]
//                              tact_hnt.cpp:171 (5)
//         004cf2e9     POP        EDI
//         004cf2ea     POP        ESI
//         004cf2eb     RET        0x4
//                               LAB_004cf2ee                                                 XREF[1]:     004cf265(j)
//                              tact_hnt.cpp:170 (9)
//         004cf2ee     MOV        EAX,dword ptr [ESI]
//         004cf2f0     PUSH       0x3
//         004cf2f2     MOV        this,ESI
//         004cf2f4     CALL       dword ptr [EAX + 0x5c]
//                              tact_hnt.cpp:171 (5)
//         004cf2f7     POP        EDI
//         004cf2f8     POP        ESI
//         004cf2f9     RET        0x4
//         004cf2fc     ??         90h
//         004cf2fd     NOP
//         004cf2fe     NOP
//         004cf2ff     NOP
    return;
}

void TRIBE_Action_Hunt::set_state(uchar param_1) {
    /* TODO: Stub */
//                              void __thiscall set_state(TRIBE_Action_Hunt * this, uchar param_1)
//              void              <VOID>         <RETURN>
//              TRIBE_Action_H    ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[4]:     004cf322(R), 004cf3ec(W), 004cf4e5(W), 004cf559(W)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[6]:     004cf3f2(W), 004cf42a(W), 004cf4eb(W), 004cf51b(W),
//                                                                                     004cf55f(W), 004cf5b2(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[3]:     004cf463(R), 004cf73a(R), 004cf80c(R)
//                               ?set_state@TRIBE_Action_Hunt@@MAEXE@Z                        XREF[1]:     0057514c(*)
//                               TRIBE_Action_Hunt::set_state
//                              tact_hnt.cpp:177 (26)
//         004cf300     MOV        EAX,FS:[0x0]
//         004cf306     PUSH       -0x1
//         004cf308     PUSH       FUN_0055ff0c
//         004cf30d     PUSH       EAX
//         004cf30e     MOV        dword ptr FS:[0x0],ESP
//         004cf315     PUSH       EBX
//         004cf316     PUSH       ESI
//         004cf317     MOV        ESI,this
//         004cf319     PUSH       EDI
//                              tact_hnt.cpp:187 (8)
//         004cf31a     MOV        this,dword ptr [ESI + 0x34]
//         004cf31d     CALL       RGE_Action_List::delete_list                     void delete_list(RGE_Action_List * this)
//                              tact_hnt.cpp:189 (7)
//         004cf322     MOV        EAX,dword ptr [ESP + param_1]
//         004cf326     MOV        byte ptr [ESI + 0xc],AL
//                              tact_hnt.cpp:191 (22)
//         004cf329     AND        EAX,0xff
//         004cf32e     DEC        EAX
//         004cf32f     CMP        EAX,0xe
//         004cf332     JA         switchD_004cf338::caseD_4
//                               switchD_004cf338::switchD
//         004cf338     JMP        dword ptr [EAX*0x4 + switchD_004cf338::switchd   = 004cf7f2
//                               switchD_004cf338::caseD_2                                    XREF[2]:     004cf338(j), 004cf828(*)
//                              tact_hnt.cpp:195 (32)
//         004cf33f     MOV        this,dword ptr [ESI + 0x8]
//         004cf342     MOV        EDI,dword ptr [ESI + 0x40]
//         004cf345     PUSH       0x0
//         004cf347     PUSH       EDI
//         004cf348     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004cf34b     MOV        EDX,dword ptr [this->_padding_]
//         004cf34d     PUSH       0x265
//         004cf352     PUSH       0x202
//         004cf357     PUSH       EAX
//         004cf358     PUSH       EAX
//         004cf359     CALL       dword ptr [EDX + 0x148]
//                              tact_hnt.cpp:199 (19)
//         004cf35f     MOV        EAX,dword ptr [ESI + 0x8]
//         004cf362     MOV        this,ESI
//         004cf364     MOV        EDI,dword ptr [EAX]
//         004cf366     CALL       TRIBE_Action_Hunt::get_wait_sprite               RGE_Sprite * get_wait_sprite(TRIBE_Action_Hun
//         004cf36b     MOV        this,dword ptr [ESI + 0x8]
//         004cf36e     PUSH       EAX
//         004cf36f     CALL       dword ptr [EDI + 0x38]
//                              tact_hnt.cpp:201 (7)
//         004cf372     MOV        dword ptr [ESI + 0x2c],0xc1200000
//                              tact_hnt.cpp:378 (20)
//         004cf379     MOV        this,dword ptr [ESP + 0xc]
//         004cf37d     MOV        dword ptr FS:[0x0],this
//         004cf384     POP        EDI
//         004cf385     POP        ESI
//         004cf386     POP        EBX
//         004cf387     ADD        ESP,0xc
//         004cf38a     RET        0x4
//                               switchD_004cf338::caseD_1                                    XREF[2]:     004cf338(j), 004cf824(*)
//                              tact_hnt.cpp:208 (19)
//         004cf38d     MOV        this,dword ptr [ESI + 0x8]
//         004cf390     MOV        EDI,dword ptr [this->_padding_]
//         004cf392     MOV        this,ESI
//         004cf394     CALL       TRIBE_Action_Hunt::get_wait_sprite               RGE_Sprite * get_wait_sprite(TRIBE_Action_Hun
//         004cf399     MOV        this,dword ptr [ESI + 0x8]
//         004cf39c     PUSH       EAX
//         004cf39d     CALL       dword ptr [EDI + 0x38]
//                              tact_hnt.cpp:209 (9)
//         004cf3a0     MOV        EDI,dword ptr [ESI]
//         004cf3a2     PUSH       0x0
//         004cf3a4     MOV        this,ESI
//         004cf3a6     CALL       dword ptr [EDI + 0x54]
//                              tact_hnt.cpp:210 (7)
//         004cf3a9     PUSH       0x0
//         004cf3ab     MOV        this,ESI
//         004cf3ad     CALL       dword ptr [EDI + 0x58]
//                              tact_hnt.cpp:211 (5)
//         004cf3b0     MOV        EAX,0xbf800000
//                              tact_hnt.cpp:214 (16)
//         004cf3b5     MOV        dword ptr [ESI + 0x2c],0x0
//         004cf3bc     MOV        dword ptr [ESI + 0x20],EAX
//         004cf3bf     MOV        dword ptr [ESI + 0x24],EAX
//         004cf3c2     MOV        dword ptr [ESI + 0x28],EAX
//                              tact_hnt.cpp:378 (20)
//         004cf3c5     MOV        this,dword ptr [ESP + 0xc]
//         004cf3c9     MOV        dword ptr FS:[0x0],this
//         004cf3d0     POP        EDI
//         004cf3d1     POP        ESI
//         004cf3d2     POP        EBX
//         004cf3d3     ADD        ESP,0xc
//         004cf3d6     RET        0x4
//                               switchD_004cf338::caseD_e                                    XREF[3]:     004cf338(j), 004cf848(*),
//                               switchD_004cf338::caseD_a                                                 004cf858(*)
//                              tact_hnt.cpp:223 (79)
//         004cf3d9     PUSH       0x44
//         004cf3db     MOV        dword ptr [ESI + 0x2c],0x0
//         004cf3e2     CALL       operator_new                                     void * operator_new(uint param_1)
//         004cf3e7     MOV        EDI,EAX
//         004cf3e9     ADD        ESP,0x4
//         004cf3ec     MOV        dword ptr [ESP + param_1],EDI
//         004cf3f0     TEST       EDI,EDI
//         004cf3f2     MOV        dword ptr [ESP + local_4],0x0
//         004cf3fa     JZ         LAB_004cf426
//         004cf3fc     MOV        this,ESI
//         004cf3fe     CALL       TRIBE_Action_Hunt::get_move_sprite               RGE_Sprite * get_move_sprite(TRIBE_Action_Hun
//         004cf403     MOV        EDX,dword ptr [ESI + 0x30]
//         004cf406     MOV        this,dword ptr [ESI + 0x28]
//         004cf409     PUSH       EAX
//         004cf40a     MOV        EAX,dword ptr [EDX + 0x24]
//         004cf40d     MOV        EDX,dword ptr [ESI + 0x24]
//         004cf410     PUSH       EAX
//         004cf411     MOV        EAX,dword ptr [ESI + 0x20]
//         004cf414     PUSH       this
//         004cf415     MOV        this,dword ptr [ESI + 0x8]
//         004cf418     PUSH       EDX
//         004cf419     PUSH       EAX
//         004cf41a     PUSH       this
//         004cf41b     MOV        this,EDI
//         004cf41d     CALL       RGE_Action_Move_To::RGE_Action_Move_To           undefined RGE_Action_Move_To(RGE_Action_Move_
//         004cf422     MOV        EDI,EAX
//         004cf424     JMP        LAB_004cf428
//                               LAB_004cf426                                                 XREF[1]:     004cf3fa(j)
//         004cf426     XOR        EDI,EDI
//                               LAB_004cf428                                                 XREF[1]:     004cf424(j)
//                              tact_hnt.cpp:224 (12)
//         004cf428     TEST       EDI,EDI
//         004cf42a     MOV        dword ptr [ESP + local_4],0xffffffff
//         004cf432     JNZ        LAB_004cf451
//                              tact_hnt.cpp:226 (9)
//         004cf434     MOV        EDX,dword ptr [ESI]
//         004cf436     PUSH       0xd
//         004cf438     MOV        this,ESI
//         004cf43a     CALL       dword ptr [EDX + 0x5c]
//                              tact_hnt.cpp:378 (20)
//         004cf43d     MOV        this,dword ptr [ESP + 0xc]
//         004cf441     MOV        dword ptr FS:[0x0],this
//         004cf448     POP        EDI
//         004cf449     POP        ESI
//         004cf44a     POP        EBX
//         004cf44b     ADD        ESP,0xc
//         004cf44e     RET        0x4
//                               LAB_004cf451                                                 XREF[1]:     004cf432(j)
//                              tact_hnt.cpp:229 (9)
//         004cf451     PUSH       0x1
//         004cf453     MOV        this,EDI
//         004cf455     CALL       RGE_Action::setSubAction                         void setSubAction(RGE_Action * this, uchar pa
//                              tact_hnt.cpp:230 (9)
//         004cf45a     MOV        this,dword ptr [ESI + 0x34]
//         004cf45d     PUSH       EDI
//         004cf45e     CALL       RGE_Action_List::add_action                      void add_action(RGE_Action_List * this, RGE_A
//                              tact_hnt.cpp:378 (20)
//         004cf463     MOV        this,dword ptr [ESP + local_c]
//         004cf467     MOV        dword ptr FS:[0x0],this
//         004cf46e     POP        EDI
//         004cf46f     POP        ESI
//         004cf470     POP        EBX
//         004cf471     ADD        ESP,0xc
//         004cf474     RET        0x4
//                               switchD_004cf338::caseD_3                                    XREF[2]:     004cf338(j), 004cf82c(*)
//                              tact_hnt.cpp:238 (14)
//         004cf477     MOV        EAX,dword ptr [ESI + 0x10]
//         004cf47a     MOV        dword ptr [ESI + 0x2c],0x0
//         004cf481     TEST       EAX,EAX
//         004cf483     JNZ        LAB_004cf4a2
//                              tact_hnt.cpp:240 (9)
//         004cf485     MOV        EAX,dword ptr [ESI]
//         004cf487     PUSH       0xd
//         004cf489     MOV        this,ESI
//         004cf48b     CALL       dword ptr [EAX + 0x5c]
//                              tact_hnt.cpp:378 (20)
//         004cf48e     MOV        this,dword ptr [ESP + 0xc]
//         004cf492     MOV        dword ptr FS:[0x0],this
//         004cf499     POP        EDI
//         004cf49a     POP        ESI
//         004cf49b     POP        EBX
//         004cf49c     ADD        ESP,0xc
//         004cf49f     RET        0x4
//                               LAB_004cf4a2                                                 XREF[1]:     004cf483(j)
//                              tact_hnt.cpp:244 (6)
//         004cf4a2     MOV        this,dword ptr [EAX + 0x38]
//         004cf4a5     MOV        dword ptr [ESI + 0x20],this
//                              tact_hnt.cpp:245 (6)
//         004cf4a8     MOV        EDX,dword ptr [EAX + 0x3c]
//         004cf4ab     MOV        dword ptr [ESI + 0x24],EDX
//                              tact_hnt.cpp:246 (6)
//         004cf4ae     MOV        this,dword ptr [EAX + 0x40]
//         004cf4b1     MOV        dword ptr [ESI + 0x28],this
//                              tact_hnt.cpp:249 (8)
//         004cf4b4     MOV        this,byte ptr [EAX + 0x48]
//         004cf4b7     CMP        this,0x2
//         004cf4ba     JA         LAB_004cf4d9
//                              tact_hnt.cpp:251 (9)
//         004cf4bc     MOV        EDX,dword ptr [ESI]
//         004cf4be     PUSH       0xc
//         004cf4c0     MOV        this,ESI
//         004cf4c2     CALL       dword ptr [EDX + 0x5c]
//                              tact_hnt.cpp:378 (20)
//         004cf4c5     MOV        this,dword ptr [ESP + 0xc]
//         004cf4c9     MOV        dword ptr FS:[0x0],this
//         004cf4d0     POP        EDI
//         004cf4d1     POP        ESI
//         004cf4d2     POP        EBX
//         004cf4d3     ADD        ESP,0xc
//         004cf4d6     RET        0x4
//                               LAB_004cf4d9                                                 XREF[1]:     004cf4ba(j)
//                              tact_hnt.cpp:256 (64)
//         004cf4d9     PUSH       0x44
//         004cf4db     CALL       operator_new                                     void * operator_new(uint param_1)
//         004cf4e0     MOV        EDI,EAX
//         004cf4e2     ADD        ESP,0x4
//         004cf4e5     MOV        dword ptr [ESP + param_1],EDI
//         004cf4e9     TEST       EDI,EDI
//         004cf4eb     MOV        dword ptr [ESP + local_4],0x1
//         004cf4f3     JZ         LAB_004cf517
//         004cf4f5     MOV        this,ESI
//         004cf4f7     CALL       TRIBE_Action_Hunt::get_move_sprite               RGE_Sprite * get_move_sprite(TRIBE_Action_Hun
//         004cf4fc     MOV        EDX,dword ptr [ESI + 0x10]
//         004cf4ff     PUSH       EAX
//         004cf500     MOV        EAX,dword ptr [ESI + 0x30]
//         004cf503     MOV        this,dword ptr [EAX + 0x24]
//         004cf506     MOV        EAX,dword ptr [ESI + 0x8]
//         004cf509     PUSH       this
//         004cf50a     PUSH       EDX
//         004cf50b     PUSH       EAX
//         004cf50c     MOV        this,EDI
//         004cf50e     CALL       RGE_Action_Move_To::RGE_Action_Move_To           undefined RGE_Action_Move_To(RGE_Action_Move_
//         004cf513     MOV        EDI,EAX
//         004cf515     JMP        LAB_004cf519
//                               LAB_004cf517                                                 XREF[1]:     004cf4f3(j)
//         004cf517     XOR        EDI,EDI
//                               LAB_004cf519                                                 XREF[1]:     004cf515(j)
//                              tact_hnt.cpp:257 (16)
//         004cf519     TEST       EDI,EDI
//         004cf51b     MOV        dword ptr [ESP + local_4],0xffffffff
//         004cf523     JNZ        LAB_004cf728
//                              tact_hnt.cpp:338 (9)
//         004cf529     MOV        EDX,dword ptr [ESI]
//         004cf52b     PUSH       0xd
//         004cf52d     MOV        this,ESI
//         004cf52f     CALL       dword ptr [EDX + 0x5c]
//                              tact_hnt.cpp:378 (20)
//         004cf532     MOV        this,dword ptr [ESP + 0xc]
//         004cf536     MOV        dword ptr FS:[0x0],this
//         004cf53d     POP        EDI
//         004cf53e     POP        ESI
//         004cf53f     POP        EBX
//         004cf540     ADD        ESP,0xc
//         004cf543     RET        0x4
//                               switchD_004cf338::caseD_b                                    XREF[2]:     004cf338(j), 004cf84c(*)
//                              tact_hnt.cpp:273 (106)
//         004cf546     PUSH       0x5c
//         004cf548     MOV        dword ptr [ESI + 0x2c],0x0
//         004cf54f     CALL       operator_new                                     void * operator_new(uint param_1)
//         004cf554     MOV        EDI,EAX
//         004cf556     ADD        ESP,0x4
//         004cf559     MOV        dword ptr [ESP + param_1],EDI
//         004cf55d     TEST       EDI,EDI
//         004cf55f     MOV        dword ptr [ESP + local_4],0x2
//         004cf567     JZ         LAB_004cf5ae
//         004cf569     MOV        EAX,dword ptr [ESI + 0x8]
//         004cf56c     MOV        this,dword ptr [ESI + 0x30]
//         004cf56f     MOV        EAX,dword ptr [EAX + 0x8]
//         004cf572     MOV        DX,word ptr [EAX + 0x12a]
//         004cf579     PUSH       EDX
//         004cf57a     MOV        DX,word ptr [EAX + 0x124]
//         004cf581     MOV        EAX,dword ptr [EAX + 0x138]
//         004cf587     PUSH       EDX
//         004cf588     MOV        EDX,dword ptr [ECX + this->_padding_]
//         004cf58b     PUSH       EAX
//         004cf58c     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004cf58f     PUSH       EDX
//         004cf590     PUSH       0x0
//         004cf592     PUSH       EAX
//         004cf593     MOV        this,ESI
//         004cf595     CALL       TRIBE_Action_Hunt::get_move_sprite               RGE_Sprite * get_move_sprite(TRIBE_Action_Hun
//         004cf59a     MOV        this,dword ptr [ESI + 0x10]
//         004cf59d     MOV        EDX,dword ptr [ESI + 0x8]
//         004cf5a0     PUSH       EAX
//         004cf5a1     PUSH       this
//         004cf5a2     PUSH       EDX
//         004cf5a3     MOV        this,EDI
//         004cf5a5     CALL       RGE_Action_Attack::RGE_Action_Attack             undefined RGE_Action_Attack(RGE_Action_Attack
//         004cf5aa     MOV        EDI,EAX
//         004cf5ac     JMP        LAB_004cf5b0
//                               LAB_004cf5ae                                                 XREF[1]:     004cf567(j)
//         004cf5ae     XOR        EDI,EDI
//                               LAB_004cf5b0                                                 XREF[1]:     004cf5ac(j)
//                              tact_hnt.cpp:274 (16)
//         004cf5b0     TEST       EDI,EDI
//         004cf5b2     MOV        dword ptr [ESP + local_4],0xffffffff
//         004cf5ba     JNZ        LAB_004cf728
//                              tact_hnt.cpp:276 (4)
//         004cf5c0     MOV        EAX,dword ptr [ESI]
//         004cf5c2     PUSH       0xd
//                              tact_hnt.cpp:363 (5)
//         004cf5c4     MOV        this,ESI
//         004cf5c6     CALL       dword ptr [EAX + 0x5c]
//                              tact_hnt.cpp:378 (20)
//         004cf5c9     MOV        this,dword ptr [ESP + 0xc]
//         004cf5cd     MOV        dword ptr FS:[0x0],this
//         004cf5d4     POP        EDI
//         004cf5d5     POP        ESI
//         004cf5d6     POP        EBX
//         004cf5d7     ADD        ESP,0xc
//         004cf5da     RET        0x4
//                               switchD_004cf338::caseD_5                                    XREF[2]:     004cf338(j), 004cf834(*)
//                              tact_hnt.cpp:290 (19)
//         004cf5dd     MOV        this,dword ptr [ESI + 0x8]
//         004cf5e0     MOV        dword ptr [ESI + 0x2c],0x0
//         004cf5e7     MOV        EDI,dword ptr [this->_padding_]
//         004cf5e9     MOV        this,ESI
//         004cf5eb     CALL       TRIBE_Action_Hunt::get_move_sprite               RGE_Sprite * get_move_sprite(TRIBE_Action_Hun
//                              tact_hnt.cpp:291 (5)
//         004cf5f0     JMP        LAB_004cf805
//                               switchD_004cf338::caseD_6                                    XREF[2]:     004cf338(j), 004cf838(*)
//                              tact_hnt.cpp:298 (3)
//         004cf5f5     MOV        EDX,dword ptr [ESI + 0x30]
//                              tact_hnt.cpp:299 (20)
//         004cf5f8     MOV        this,dword ptr [ESI + 0x8]
//         004cf5fb     MOV        dword ptr [ESI + 0x2c],0x0
//         004cf602     MOV        AX,word ptr [EDX + 0x14]
//         004cf606     CMP        word ptr [this->_padding_ + 0x4c],AX
//         004cf60a     JZ         LAB_004cf617
//                              tact_hnt.cpp:300 (11)
//         004cf60c     MOV        EDX,dword ptr [this->_padding_]
//         004cf60e     PUSH       0x0
//         004cf610     PUSH       EAX
//         004cf611     CALL       dword ptr [EDX + 0x80]
//                               LAB_004cf617                                                 XREF[1]:     004cf60a(j)
//                              tact_hnt.cpp:306 (15)
//         004cf617     MOV        EDX,dword ptr [ESI + 0x30]
//         004cf61a     MOV        this,dword ptr [ESI + 0x8]
//         004cf61d     MOV        EDX,dword ptr [EDX + 0x3c]
//         004cf620     MOV        EAX,dword ptr [this->_padding_]
//         004cf622     PUSH       EDX
//         004cf623     CALL       dword ptr [EAX + 0x38]
//                              tact_hnt.cpp:309 (14)
//         004cf626     MOV        EAX,dword ptr [ESI + 0x30]
//         004cf629     MOV        this,dword ptr [EAX + 0x44]
//         004cf62c     TEST       this,this
//         004cf62e     JZ         switchD_004cf338::caseD_4
//                              tact_hnt.cpp:310 (7)
//         004cf634     PUSH       0x1
//         004cf636     CALL       RGE_Sound::play                                  void play(RGE_Sound * this, int param_1)
//                              tact_hnt.cpp:378 (20)
//         004cf63b     MOV        this,dword ptr [ESP + 0xc]
//         004cf63f     MOV        dword ptr FS:[0x0],this
//         004cf646     POP        EDI
//         004cf647     POP        ESI
//         004cf648     POP        EBX
//         004cf649     ADD        ESP,0xc
//         004cf64c     RET        0x4
//                               switchD_004cf338::caseD_7                                    XREF[2]:     004cf338(j), 004cf83c(*)
//                              tact_hnt.cpp:315 (23)
//         004cf64f     MOV        this,dword ptr [ESI + 0x8]
//         004cf652     FLD        float ptr [ECX + this+0x44]
//         004cf655     FCOMP      float ptr [DAT_00575150]                         = align(18)
//         004cf65b     FNSTSW     AX
//         004cf65d     TEST       AH,0x41
//         004cf660     JNZ        LAB_004cf7b5
//                              tact_hnt.cpp:318 (7)
//         004cf666     MOV        EAX,dword ptr [ESI + 0x14]
//         004cf669     TEST       EAX,EAX
//         004cf66b     JNZ        LAB_004cf6bf
//                              tact_hnt.cpp:320 (16)
//         004cf66d     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004cf670     MOV        DX,word ptr [EAX + 0xe8]
//         004cf677     CMP        DX,-0x1
//         004cf67b     JZ         LAB_004cf6ab
//                              tact_hnt.cpp:323 (44)
//         004cf67d     MOV        EBX,dword ptr [ECX + this->_padding_]
//         004cf680     PUSH       this
//         004cf681     MOVSX      EAX,word ptr [EAX + 0xea]
//         004cf688     PUSH       0x2
//         004cf68a     PUSH       0x1
//         004cf68c     PUSH       EBX
//         004cf68d     MOV        EBX,dword ptr [ECX + this->_padding_]
//         004cf690     MOV        EDI,dword ptr [ESI]
//         004cf692     PUSH       EBX
//         004cf693     PUSH       EAX
//         004cf694     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004cf697     MOVSX      EDX,DX
//         004cf69a     MOV        this,dword ptr [EAX + 0x28]
//         004cf69d     PUSH       EDX
//         004cf69e     CALL       RGE_Object_List::find_by_master_ids              RGE_Static_Object * find_by_master_ids(RGE_Ob
//         004cf6a3     PUSH       EAX
//         004cf6a4     MOV        this,ESI
//         004cf6a6     CALL       dword ptr [EDI + 0x58]
//                              tact_hnt.cpp:324 (2)
//         004cf6a9     JMP        LAB_004cf6b4
//                               LAB_004cf6ab                                                 XREF[1]:     004cf67b(j)
//                              tact_hnt.cpp:325 (9)
//         004cf6ab     MOV        EDX,dword ptr [ESI]
//         004cf6ad     PUSH       0x0
//         004cf6af     MOV        this,ESI
//         004cf6b1     CALL       dword ptr [EDX + 0x58]
//                               LAB_004cf6b4                                                 XREF[1]:     004cf6a9(j)
//                              tact_hnt.cpp:328 (11)
//         004cf6b4     MOV        EAX,dword ptr [ESI + 0x14]
//         004cf6b7     TEST       EAX,EAX
//         004cf6b9     JZ         LAB_004cf74e
//                               LAB_004cf6bf                                                 XREF[1]:     004cf66b(j)
//                              tact_hnt.cpp:332 (64)
//         004cf6bf     PUSH       0x44
//         004cf6c1     CALL       operator_new                                     void * operator_new(uint param_1)
//         004cf6c6     MOV        EDI,EAX
//         004cf6c8     ADD        ESP,0x4
//         004cf6cb     MOV        dword ptr [ESP + 0x1c],EDI
//         004cf6cf     TEST       EDI,EDI
//         004cf6d1     MOV        dword ptr [ESP + 0x14],0x3
//         004cf6d9     JZ         LAB_004cf6fd
//         004cf6db     MOV        this,ESI
//         004cf6dd     CALL       TRIBE_Action_Hunt::get_move_sprite               RGE_Sprite * get_move_sprite(TRIBE_Action_Hun
//         004cf6e2     MOV        EDX,dword ptr [ESI + 0x14]
//         004cf6e5     PUSH       EAX
//         004cf6e6     MOV        EAX,dword ptr [ESI + 0x30]
//         004cf6e9     MOV        this,dword ptr [EAX + 0x24]
//         004cf6ec     MOV        EAX,dword ptr [ESI + 0x8]
//         004cf6ef     PUSH       this=>DAT_fffffff8
//         004cf6f0     PUSH       EDX=>DAT_fffffff4
//         004cf6f1     PUSH       EAX=>DAT_fffffff0
//         004cf6f2     MOV        this,EDI
//         004cf6f4     CALL       RGE_Action_Move_To::RGE_Action_Move_To           undefined RGE_Action_Move_To(RGE_Action_Move_
//         004cf6f9     MOV        EDI,EAX
//         004cf6fb     JMP        LAB_004cf6ff
//                               LAB_004cf6fd                                                 XREF[1]:     004cf6d9(j)
//         004cf6fd     XOR        EDI,EDI
//                               LAB_004cf6ff                                                 XREF[1]:     004cf6fb(j)
//                              tact_hnt.cpp:333 (12)
//         004cf6ff     TEST       EDI,EDI
//         004cf701     MOV        dword ptr [ESP + 0x14],0xffffffff
//         004cf709     JNZ        LAB_004cf728
//                              tact_hnt.cpp:338 (9)
//         004cf70b     MOV        EDX,dword ptr [ESI]
//         004cf70d     PUSH       0xd
//         004cf70f     MOV        this,ESI
//         004cf711     CALL       dword ptr [EDX + 0x5c]
//                              tact_hnt.cpp:378 (20)
//         004cf714     MOV        this,dword ptr [ESP + 0xc]
//         004cf718     MOV        dword ptr FS:[0x0],this
//         004cf71f     POP        EDI
//         004cf720     POP        ESI
//         004cf721     POP        EBX
//         004cf722     ADD        ESP,0xc
//         004cf725     RET        0x4
//                               LAB_004cf728                                                 XREF[3]:     004cf523(j), 004cf5ba(j),
//                                                                                                         004cf709(j)
//                              tact_hnt.cpp:341 (9)
//         004cf728     MOV        this,dword ptr [ESI + 0x34]
//         004cf72b     PUSH       EDI
//         004cf72c     CALL       RGE_Action_List::add_action                      void add_action(RGE_Action_List * this, RGE_A
//                              tact_hnt.cpp:342 (9)
//         004cf731     PUSH       0x1
//         004cf733     MOV        this,EDI
//         004cf735     CALL       RGE_Action::setSubAction                         void setSubAction(RGE_Action * this, uchar pa
//                              tact_hnt.cpp:378 (20)
//         004cf73a     MOV        this,dword ptr [ESP + local_c]
//         004cf73e     MOV        dword ptr FS:[0x0],this
//         004cf745     POP        EDI
//         004cf746     POP        ESI
//         004cf747     POP        EBX
//         004cf748     ADD        ESP,0xc
//         004cf74b     RET        0x4
//                               LAB_004cf74e                                                 XREF[1]:     004cf6b9(j)
//                              tact_hnt.cpp:347 (30)
//         004cf74e     MOV        this,dword ptr [ESI + 0x8]
//         004cf751     PUSH       0x0
//         004cf753     PUSH       0x0=>DAT_fffffff8
//         004cf755     PUSH       offset DAT_fffffff4
//         004cf75a     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004cf75d     MOV        EDX,dword ptr [this->_padding_]
//         004cf75f     PUSH       offset DAT_fffffff0
//         004cf764     PUSH       EAX
//         004cf765     PUSH       EAX
//         004cf766     CALL       dword ptr [EDX + 0x148]
//                              tact_hnt.cpp:351 (15)
//         004cf76c     MOV        EAX,dword ptr [ESI + 0x8]
//         004cf76f     MOV        this,dword ptr [EAX + 0xc]
//         004cf772     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
//         004cf777     TEST       EAX,EAX
//         004cf779     JNZ        LAB_004cf798
//                              tact_hnt.cpp:352 (9)
//         004cf77b     MOV        EDX,dword ptr [ESI]
//         004cf77d     PUSH       0x2
//         004cf77f     MOV        this,ESI
//         004cf781     CALL       dword ptr [EDX + 0x5c]
//                              tact_hnt.cpp:378 (20)
//         004cf784     MOV        this,dword ptr [ESP + 0xc]
//         004cf788     MOV        dword ptr FS:[0x0],this
//         004cf78f     POP        EDI
//         004cf790     POP        ESI
//         004cf791     POP        EBX
//         004cf792     ADD        ESP,0xc
//         004cf795     RET        0x4
//                               LAB_004cf798                                                 XREF[1]:     004cf779(j)
//                              tact_hnt.cpp:354 (9)
//         004cf798     MOV        EAX,dword ptr [ESI]
//         004cf79a     PUSH       0x1
//         004cf79c     MOV        this,ESI
//         004cf79e     CALL       dword ptr [EAX + 0x5c]
//                              tact_hnt.cpp:378 (20)
//         004cf7a1     MOV        this,dword ptr [ESP + 0xc]
//         004cf7a5     MOV        dword ptr FS:[0x0],this
//         004cf7ac     POP        EDI
//         004cf7ad     POP        ESI
//         004cf7ae     POP        EBX
//         004cf7af     ADD        ESP,0xc
//         004cf7b2     RET        0x4
//                               LAB_004cf7b5                                                 XREF[1]:     004cf660(j)
//                              tact_hnt.cpp:361 (23)
//         004cf7b5     MOV        EAX,dword ptr [ESI + 0x10]
//         004cf7b8     TEST       EAX,EAX
//         004cf7ba     JZ         LAB_004cf7d5
//         004cf7bc     FLD        float ptr [EAX + 0x44]
//         004cf7bf     FCOMP      float ptr [DAT_00575150]                         = align(18)
//         004cf7c5     FNSTSW     AX
//         004cf7c7     TEST       AH,0x41
//         004cf7ca     JZ         LAB_004cf7d5
//                              tact_hnt.cpp:362 (9)
//         004cf7cc     MOV        EDX,dword ptr [ESI]
//         004cf7ce     PUSH       0x0
//         004cf7d0     MOV        this,ESI
//         004cf7d2     CALL       dword ptr [EDX + 0x54]
//                               LAB_004cf7d5                                                 XREF[2]:     004cf7ba(j), 004cf7ca(j)
//                              tact_hnt.cpp:363 (9)
//         004cf7d5     MOV        EAX,dword ptr [ESI]
//         004cf7d7     PUSH       0x3
//         004cf7d9     MOV        this,ESI
//         004cf7db     CALL       dword ptr [EAX + 0x5c]
//                              tact_hnt.cpp:378 (20)
//         004cf7de     MOV        this,dword ptr [ESP + 0xc]
//         004cf7e2     MOV        dword ptr FS:[0x0],this
//         004cf7e9     POP        EDI
//         004cf7ea     POP        ESI
//         004cf7eb     POP        EBX
//         004cf7ec     ADD        ESP,0xc
//         004cf7ef     RET        0x4
//                               switchD_004cf338::caseD_c                                    XREF[4]:     004cf338(j), 004cf820(*),
//                               switchD_004cf338::caseD_d                                                 004cf850(*), 004cf854(*)
//                               switchD_004cf338::caseD_0
//                              tact_hnt.cpp:375 (26)
//         004cf7f2     MOV        this,dword ptr [ESI + 0x8]
//         004cf7f5     MOV        dword ptr [ESI + 0x2c],0x0
//         004cf7fc     MOV        EDI,dword ptr [this->_padding_]
//         004cf7fe     MOV        this,ESI
//         004cf800     CALL       TRIBE_Action_Hunt::get_wait_sprite               RGE_Sprite * get_wait_sprite(TRIBE_Action_Hun
//                               LAB_004cf805                                                 XREF[1]:     004cf5f0(j)
//         004cf805     MOV        this,dword ptr [ESI + 0x8]
//         004cf808     PUSH       EAX
//         004cf809     CALL       dword ptr [EDI + 0x38]
//                               switchD_004cf338::caseD_8                                    XREF[6]:     004cf332(j), 004cf338(j),
//                               switchD_004cf338::caseD_9                                                 004cf62e(j), 004cf830(*),
//                               switchD_004cf338::caseD_4                                                 004cf840(*), 004cf844(*)
//                              tact_hnt.cpp:378 (80)
//         004cf80c     MOV        this,dword ptr [ESP + local_c]
//         004cf810     POP        EDI
//         004cf811     POP        ESI
//         004cf812     MOV        dword ptr FS:[0x0],this
//         004cf819     POP        EBX
//         004cf81a     ADD        ESP,0xc
//         004cf81d     RET        0x4
//                              Symbol Ref: No symbol: NONAME
//                               switchD_004cf338::switchdataD_004cf820                       XREF[1]:     set_state:004cf338(*)
//         004cf820     addr       switchD_004cf338::caseD_0
//         004cf824     addr       switchD_004cf338::caseD_1
//         004cf828     addr       switchD_004cf338::caseD_2
//         004cf82c     addr       switchD_004cf338::caseD_3
//         004cf830     addr       switchD_004cf338::caseD_4
//         004cf834     addr       switchD_004cf338::caseD_5
//         004cf838     addr       switchD_004cf338::caseD_6
//         004cf83c     addr       switchD_004cf338::caseD_7
//         004cf840     addr       switchD_004cf338::caseD_4
//         004cf844     addr       switchD_004cf338::caseD_4
//         004cf848     addr       switchD_004cf338::caseD_a
//         004cf84c     addr       switchD_004cf338::caseD_b
//         004cf850     addr       switchD_004cf338::caseD_0
//         004cf854     addr       switchD_004cf338::caseD_0
//         004cf858     addr       switchD_004cf338::caseD_a
//         004cf85c     ??         90h
//         004cf85d     ??         90h
//         004cf85e     ??         90h
//         004cf85f     ??         90h
    return;
}

uchar TRIBE_Action_Hunt::update() {
    /* TODO: Stub */
//                              uchar __thiscall update(TRIBE_Action_Hunt * this)
//              uchar             AL:1           <RETURN>
//              TRIBE_Action_H    ECX:4 (auto)   this
//              float             Stack[-0x8]:2  max_hold
//              float             Stack[-0xc]:4  modifier
//              float             Stack[-0x10]:4 give_amount
//                               ?update@TRIBE_Action_Hunt@@UAEEXZ                            XREF[1]:     00575118(*)
//                               TRIBE_Action_Hunt::update
//                              tact_hnt.cpp:384 (9)
//         004cf860     SUB        ESP,0xc
//         004cf863     PUSH       EBX
//         004cf864     PUSH       EBP
//         004cf865     PUSH       ESI
//         004cf866     MOV        ESI,this
//         004cf868     PUSH       EDI
//                              tact_hnt.cpp:412 (27)
//         004cf869     MOV        EAX,dword ptr [ESI + 0x18]
//         004cf86c     CMP        EAX,-0x1
//         004cf86f     JZ         LAB_004cf88c
//         004cf871     PUSH       EAX
//         004cf872     MOV        EAX,dword ptr [ESI + 0x8]
//         004cf875     MOV        this,dword ptr [EAX + 0xc]
//         004cf878     MOV        this,dword ptr [ECX + this->_padding_]
//         004cf87b     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
//         004cf880     TEST       EAX,EAX
//         004cf882     JNZ        LAB_004cf88c
//                              tact_hnt.cpp:417 (8)
//         004cf884     MOV        EDX,dword ptr [ESI]
//         004cf886     PUSH       EAX
//         004cf887     MOV        this,ESI
//         004cf889     CALL       dword ptr [EDX + 0x54]
//                               LAB_004cf88c                                                 XREF[2]:     004cf86f(j), 004cf882(j)
//                              tact_hnt.cpp:419 (27)
//         004cf88c     MOV        EAX,dword ptr [ESI + 0x1c]
//         004cf88f     CMP        EAX,-0x1
//         004cf892     JZ         LAB_004cf8af
//         004cf894     PUSH       EAX
//         004cf895     MOV        EAX,dword ptr [ESI + 0x8]
//         004cf898     MOV        this,dword ptr [EAX + 0xc]
//         004cf89b     MOV        this,dword ptr [ECX + this->_padding_]
//         004cf89e     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
//         004cf8a3     TEST       EAX,EAX
//         004cf8a5     JNZ        LAB_004cf8af
//                              tact_hnt.cpp:424 (8)
//         004cf8a7     MOV        EDX,dword ptr [ESI]
//         004cf8a9     PUSH       EAX
//         004cf8aa     MOV        this,ESI
//         004cf8ac     CALL       dword ptr [EDX + 0x58]
//                               LAB_004cf8af                                                 XREF[2]:     004cf892(j), 004cf8a5(j)
//                              tact_hnt.cpp:427 (17)
//         004cf8af     MOV        EAX,dword ptr [ESI + 0x10]
//         004cf8b2     MOV        EBX,0x7
//         004cf8b7     TEST       EAX,EAX
//         004cf8b9     JZ         LAB_004cf8c9
//         004cf8bb     CMP        byte ptr [EAX + 0x48],BL
//         004cf8be     JC         LAB_004cf8c9
//                              tact_hnt.cpp:432 (9)
//         004cf8c0     MOV        EAX,dword ptr [ESI]
//         004cf8c2     PUSH       0x0
//         004cf8c4     MOV        this,ESI
//         004cf8c6     CALL       dword ptr [EAX + 0x54]
//                               LAB_004cf8c9                                                 XREF[2]:     004cf8b9(j), 004cf8be(j)
//                              tact_hnt.cpp:434 (12)
//         004cf8c9     MOV        EAX,dword ptr [ESI + 0x14]
//         004cf8cc     TEST       EAX,EAX
//         004cf8ce     JZ         LAB_004cf8de
//         004cf8d0     CMP        byte ptr [EAX + 0x48],BL
//         004cf8d3     JC         LAB_004cf8de
//                              tact_hnt.cpp:439 (9)
//         004cf8d5     MOV        EDX,dword ptr [ESI]
//         004cf8d7     PUSH       0x0
//         004cf8d9     MOV        this,ESI
//         004cf8db     CALL       dword ptr [EDX + 0x58]
//                               LAB_004cf8de                                                 XREF[2]:     004cf8ce(j), 004cf8d3(j)
//                              tact_hnt.cpp:442 (22)
//         004cf8de     XOR        EAX,EAX
//         004cf8e0     MOV        AL,byte ptr [ESI + 0xc]
//         004cf8e3     DEC        EAX
//         004cf8e4     CMP        EAX,0xe
//         004cf8e7     JA         switchD_004cf8ed::caseD_1
//                               switchD_004cf8ed::switchD
//         004cf8ed     JMP        dword ptr [EAX*0x4 + switchD_004cf8ed::switchd   = 004cfe3d
//                               switchD_004cf8ed::caseD_2                                    XREF[2]:     004cf8ed(j), 004cfe9c(*)
//                              tact_hnt.cpp:448 (20)
//         004cf8f4     FLD        float ptr [ESI + 0x2c]
//         004cf8f7     FCOMP      double ptr [null_00575158]                       = align(10)
//         004cf8fd     FNSTSW     AX
//         004cf8ff     TEST       AH,0x1
//         004cf902     JZ         switchD_004cf8ed::caseD_1
//                              tact_hnt.cpp:450 (18)
//         004cf908     MOV        this,dword ptr [ESI + 0x8]
//         004cf90b     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004cf90e     MOV        EDX,dword ptr [EAX + 0x3c]
//         004cf911     FLD        float ptr [EDX + 0x84]
//         004cf917     FADD       float ptr [ESI + 0x2c]
//                              tact_hnt.cpp:451 (20)
//         004cf91a     FCOM       double ptr [null_00575158]                       = align(10)
//         004cf920     FSTP       float ptr [ESI + 0x2c]
//         004cf923     FNSTSW     AX
//         004cf925     TEST       AH,0x41
//         004cf928     JNZ        switchD_004cf8ed::caseD_1
//                              tact_hnt.cpp:454 (36)
//         004cf92e     MOV        EDX,dword ptr [this->_padding_]
//         004cf930     MOV        dword ptr [ESI + 0x2c],0xc1200000
//         004cf937     MOV        ESI,dword ptr [ESI + 0x40]
//         004cf93a     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004cf93d     PUSH       0x0
//         004cf93f     PUSH       ESI
//         004cf940     PUSH       0x265
//         004cf945     PUSH       0x202
//         004cf94a     PUSH       EAX
//         004cf94b     PUSH       EAX
//         004cf94c     CALL       dword ptr [EDX + 0x148]
//                              tact_hnt.cpp:793 (2)
//         004cf952     XOR        AL,AL
//                              tact_hnt.cpp:794 (8)
//         004cf954     POP        EDI
//         004cf955     POP        ESI
//         004cf956     POP        EBP
//         004cf957     POP        EBX
//         004cf958     ADD        ESP,0xc
//         004cf95b     RET
//                               switchD_004cf8ed::caseD_e                                    XREF[3]:     004cf8ed(j), 004cfebc(*),
//                               switchD_004cf8ed::caseD_a                                                 004cfecc(*)
//                              tact_hnt.cpp:465 (30)
//         004cf95c     MOV        this,dword ptr [ESI + 0x34]
//         004cf95f     MOV        EAX,dword ptr [this->_padding_]
//         004cf961     CALL       dword ptr [EAX + 0xc]
//         004cf964     AND        EAX,0xff
//         004cf969     DEC        EAX
//         004cf96a     CMP        EAX,0x4
//         004cf96d     JA         switchD_004cf8ed::caseD_1
//                               switchD_004cf973::switchD
//         004cf973     JMP        dword ptr [EAX*0x4 + switchD_004cf973::switchd   = 004cf9ab
//                               switchD_004cf973::caseD_3                                    XREF[2]:     004cf973(j), 004cfedc(*)
//                              tact_hnt.cpp:473 (9)
//         004cf97a     MOV        EDI,dword ptr [ESI]
//         004cf97c     PUSH       0x0
//         004cf97e     MOV        this,ESI
//         004cf980     CALL       dword ptr [EDI + 0x54]
//                              tact_hnt.cpp:474 (6)
//         004cf983     CMP        byte ptr [ESI + 0xc],0xb
//         004cf987     JNZ        LAB_004cf99a
//                              tact_hnt.cpp:475 (7)
//         004cf989     PUSH       0xb
//         004cf98b     MOV        this,ESI
//         004cf98d     CALL       dword ptr [EDI + 0x5c]
//                              tact_hnt.cpp:793 (2)
//         004cf990     XOR        AL,AL
//                              tact_hnt.cpp:794 (8)
//         004cf992     POP        EDI
//         004cf993     POP        ESI
//         004cf994     POP        EBP
//         004cf995     POP        EBX
//         004cf996     ADD        ESP,0xc
//         004cf999     RET
//                               LAB_004cf99a                                                 XREF[1]:     004cf987(j)
//                              tact_hnt.cpp:477 (7)
//         004cf99a     PUSH       0xf
//         004cf99c     MOV        this,ESI
//         004cf99e     CALL       dword ptr [EDI + 0x5c]
//                              tact_hnt.cpp:793 (2)
//         004cf9a1     XOR        AL,AL
//                              tact_hnt.cpp:794 (8)
//         004cf9a3     POP        EDI
//         004cf9a4     POP        ESI
//         004cf9a5     POP        EBP
//         004cf9a6     POP        EBX
//         004cf9a7     ADD        ESP,0xc
//         004cf9aa     RET
//                               switchD_004cf973::caseD_1                                    XREF[4]:     004cf973(j), 004cfed0(*),
//                               switchD_004cf973::caseD_4                                                 004cfed4(*), 004cfee0(*)
//                               switchD_004cf973::caseD_0
//                              tact_hnt.cpp:486 (10)
//         004cf9ab     CMP        byte ptr [ESI + 0xc],0xb
//         004cf9af     JNZ        LAB_004cfdf5
//                              tact_hnt.cpp:487 (4)
//         004cf9b5     MOV        EDX,dword ptr [ESI]
//         004cf9b7     PUSH       0x3
//                              tact_hnt.cpp:761 (5)
//         004cf9b9     MOV        this,ESI
//         004cf9bb     CALL       dword ptr [EDX + 0x5c]
//                              tact_hnt.cpp:793 (2)
//         004cf9be     XOR        AL,AL
//                              tact_hnt.cpp:794 (8)
//         004cf9c0     POP        EDI
//         004cf9c1     POP        ESI
//         004cf9c2     POP        EBP
//         004cf9c3     POP        EBX
//         004cf9c4     ADD        ESP,0xc
//         004cf9c7     RET
//                               switchD_004cf973::caseD_2                                    XREF[2]:     004cf973(j), 004cfed8(*)
//                              tact_hnt.cpp:500 (20)
//         004cf9c8     MOV        this,dword ptr [ESI + 0x8]
//         004cf9cb     MOV        this,dword ptr [ECX + this->_padding_]
//         004cf9ce     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
//         004cf9d3     CMP        EAX,0x1
//         004cf9d6     JNZ        LAB_004cfb46
//                              tact_hnt.cpp:501 (4)
//         004cf9dc     MOV        EDX,dword ptr [ESI]
//         004cf9de     PUSH       0xd
//                              tact_hnt.cpp:761 (5)
//         004cf9e0     MOV        this,ESI
//         004cf9e2     CALL       dword ptr [EDX + 0x5c]
//                              tact_hnt.cpp:793 (2)
//         004cf9e5     XOR        AL,AL
//                              tact_hnt.cpp:794 (8)
//         004cf9e7     POP        EDI
//         004cf9e8     POP        ESI
//         004cf9e9     POP        EBP
//         004cf9ea     POP        EBX
//         004cf9eb     ADD        ESP,0xc
//         004cf9ee     RET
//                               switchD_004cf8ed::caseD_3                                    XREF[2]:     004cf8ed(j), 004cfea0(*)
//                              tact_hnt.cpp:510 (30)
//         004cf9ef     MOV        this,dword ptr [ESI + 0x34]
//         004cf9f2     MOV        EDX,dword ptr [this->_padding_]
//         004cf9f4     CALL       dword ptr [EDX + 0xc]
//         004cf9f7     AND        EAX,0xff
//         004cf9fc     DEC        EAX
//         004cf9fd     CMP        EAX,0x4
//         004cfa00     JA         switchD_004cf8ed::caseD_1
//                               switchD_004cfa06::switchD
//         004cfa06     JMP        dword ptr [EAX*0x4 + switchD_004cfa06::switchd   = 004cfa34
//                               switchD_004cfa06::caseD_2                                    XREF[2]:     004cfa06(j), 004cfeec(*)
//                              tact_hnt.cpp:528 (20)
//         004cfa0d     MOV        EAX,dword ptr [ESI + 0x8]
//         004cfa10     MOV        this,dword ptr [EAX + 0xc]
//         004cfa13     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
//         004cfa18     CMP        EAX,0x1
//         004cfa1b     JNZ        LAB_004cfb46
//                              tact_hnt.cpp:529 (4)
//         004cfa21     MOV        EDX,dword ptr [ESI]
//         004cfa23     PUSH       0xd
//                              tact_hnt.cpp:761 (5)
//         004cfa25     MOV        this,ESI
//         004cfa27     CALL       dword ptr [EDX + 0x5c]
//                              tact_hnt.cpp:793 (2)
//         004cfa2a     XOR        AL,AL
//                              tact_hnt.cpp:794 (8)
//         004cfa2c     POP        EDI
//         004cfa2d     POP        ESI
//         004cfa2e     POP        EBP
//         004cfa2f     POP        EBX
//         004cfa30     ADD        ESP,0xc
//         004cfa33     RET
//                               switchD_004cfa06::caseD_1                                    XREF[3]:     004cfa06(j), 004cfee4(*),
//                               switchD_004cfa06::caseD_0                                                 004cfee8(*)
//                              tact_hnt.cpp:537 (9)
//         004cfa34     MOV        EDX,dword ptr [ESI]
//         004cfa36     PUSH       0x6
//         004cfa38     MOV        this,ESI
//         004cfa3a     CALL       dword ptr [EDX + 0x5c]
//                              tact_hnt.cpp:793 (2)
//         004cfa3d     XOR        AL,AL
//                              tact_hnt.cpp:794 (8)
//         004cfa3f     POP        EDI
//         004cfa40     POP        ESI
//         004cfa41     POP        EBP
//         004cfa42     POP        EBX
//         004cfa43     ADD        ESP,0xc
//         004cfa46     RET
//                               switchD_004cf8ed::caseD_b                                    XREF[2]:     004cf8ed(j), 004cfec0(*)
//                              tact_hnt.cpp:544 (30)
//         004cfa47     MOV        this,dword ptr [ESI + 0x34]
//         004cfa4a     MOV        EAX,dword ptr [this->_padding_]
//         004cfa4c     CALL       dword ptr [EAX + 0xc]
//         004cfa4f     AND        EAX,0xff
//         004cfa54     DEC        EAX
//         004cfa55     CMP        EAX,0x4
//         004cfa58     JA         switchD_004cf8ed::caseD_1
//                               switchD_004cfa5e::switchD
//         004cfa5e     JMP        dword ptr [EAX*0x4 + switchD_004cfa5e::switchd   = 004cfa7f
//                               switchD_004cfa06::caseD_3                                    XREF[5]:     004cfa06(j), 004cfa5e(j),
//                               switchD_004cfa06::caseD_4                                                 004cfef0(*), 004cfef4(*),
//                               switchD_004cfa5e::caseD_3                                                 004cff04(*)
//                              tact_hnt.cpp:556 (9)
//         004cfa65     MOV        EDI,dword ptr [ESI]
//         004cfa67     PUSH       0x0
//         004cfa69     MOV        this,ESI
//         004cfa6b     CALL       dword ptr [EDI + 0x54]
//                              tact_hnt.cpp:557 (7)
//         004cfa6e     PUSH       0xb
//         004cfa70     MOV        this,ESI
//         004cfa72     CALL       dword ptr [EDI + 0x5c]
//                              tact_hnt.cpp:793 (2)
//         004cfa75     XOR        AL,AL
//                              tact_hnt.cpp:794 (8)
//         004cfa77     POP        EDI
//         004cfa78     POP        ESI
//         004cfa79     POP        EBP
//         004cfa7a     POP        EBX
//         004cfa7b     ADD        ESP,0xc
//         004cfa7e     RET
//                               switchD_004cfa5e::caseD_1                                    XREF[4]:     004cfa5e(j), 004cfef8(*),
//                               switchD_004cfa5e::caseD_4                                                 004cfefc(*), 004cff08(*)
//                               switchD_004cfa5e::caseD_0
//                              tact_hnt.cpp:566 (7)
//         004cfa7f     MOV        EAX,dword ptr [ESI + 0x10]
//         004cfa82     TEST       EAX,EAX
//         004cfa84     JZ         switchD_004cfa5e::caseD_2
//                              tact_hnt.cpp:567 (9)
//         004cfa86     MOV        EAX,dword ptr [ESI]
//         004cfa88     PUSH       0x4
//         004cfa8a     MOV        this,ESI
//         004cfa8c     CALL       dword ptr [EAX + 0x5c]
//                              tact_hnt.cpp:793 (2)
//         004cfa8f     XOR        AL,AL
//                              tact_hnt.cpp:794 (8)
//         004cfa91     POP        EDI
//         004cfa92     POP        ESI
//         004cfa93     POP        EBP
//         004cfa94     POP        EBX
//         004cfa95     ADD        ESP,0xc
//         004cfa98     RET
//                               switchD_004cfa5e::caseD_2                                    XREF[3]:     004cfa5e(j), 004cfa84(j),
//                                                                                                         004cff00(*)
//                              tact_hnt.cpp:569 (9)
//         004cfa99     MOV        EDX,dword ptr [ESI]
//         004cfa9b     PUSH       0x3
//         004cfa9d     MOV        this,ESI
//         004cfa9f     CALL       dword ptr [EDX + 0x5c]
//                              tact_hnt.cpp:793 (2)
//         004cfaa2     XOR        AL,AL
//                              tact_hnt.cpp:794 (8)
//         004cfaa4     POP        EDI
//         004cfaa5     POP        ESI
//         004cfaa6     POP        EBP
//         004cfaa7     POP        EBX
//         004cfaa8     ADD        ESP,0xc
//         004cfaab     RET
//                               switchD_004cf8ed::caseD_5                                    XREF[2]:     004cf8ed(j), 004cfea8(*)
//                              tact_hnt.cpp:577 (7)
//         004cfaac     MOV        EAX,dword ptr [ESI + 0x10]
//         004cfaaf     TEST       EAX,EAX
//         004cfab1     JNZ        LAB_004cfac6
//                              tact_hnt.cpp:582 (9)
//         004cfab3     MOV        EAX,dword ptr [ESI]
//         004cfab5     PUSH       0x3
//         004cfab7     MOV        this,ESI
//         004cfab9     CALL       dword ptr [EAX + 0x5c]
//                              tact_hnt.cpp:793 (2)
//         004cfabc     XOR        AL,AL
//                              tact_hnt.cpp:794 (8)
//         004cfabe     POP        EDI
//         004cfabf     POP        ESI
//         004cfac0     POP        EBP
//         004cfac1     POP        EBX
//         004cfac2     ADD        ESP,0xc
//         004cfac5     RET
//                               LAB_004cfac6                                                 XREF[1]:     004cfab1(j)
//                              tact_hnt.cpp:587 (20)
//         004cfac6     MOV        this,dword ptr [ESI + 0x8]
//         004cfac9     PUSH       0x0
//         004cfacb     PUSH       0x0
//         004cfacd     PUSH       EAX
//         004cface     MOV        EDX,dword ptr [this->_padding_]
//         004cfad0     CALL       dword ptr [EDX + 0x1f0]
//         004cfad6     TEST       AL,AL
//         004cfad8     JZ         LAB_004cfb46
//                              tact_hnt.cpp:591 (19)
//         004cfada     MOV        EAX,dword ptr [ESI + 0x10]
//         004cfadd     FLD        float ptr [EAX + 0x44]
//         004cfae0     FCOMP      float ptr [DAT_00575150]                         = align(18)
//         004cfae6     FNSTSW     AX
//         004cfae8     TEST       AH,0x41
//         004cfaeb     JZ         LAB_004cfb07
//                              tact_hnt.cpp:593 (9)
//         004cfaed     MOV        EDI,dword ptr [ESI]
//         004cfaef     PUSH       0x0
//         004cfaf1     MOV        this,ESI
//         004cfaf3     CALL       dword ptr [EDI + 0x54]
//                              tact_hnt.cpp:597 (7)
//         004cfaf6     PUSH       0x3
//         004cfaf8     MOV        this,ESI
//         004cfafa     CALL       dword ptr [EDI + 0x5c]
//                              tact_hnt.cpp:793 (2)
//         004cfafd     XOR        AL,AL
//                              tact_hnt.cpp:794 (8)
//         004cfaff     POP        EDI
//         004cfb00     POP        ESI
//         004cfb01     POP        EBP
//         004cfb02     POP        EBX
//         004cfb03     ADD        ESP,0xc
//         004cfb06     RET
//                               LAB_004cfb07                                                 XREF[1]:     004cfaeb(j)
//                              tact_hnt.cpp:600 (3)
//         004cfb07     MOV        EDX,dword ptr [ESI]
//         004cfb09     PUSH       EBX
//                              tact_hnt.cpp:761 (5)
//         004cfb0a     MOV        this,ESI
//         004cfb0c     CALL       dword ptr [EDX + 0x5c]
//                              tact_hnt.cpp:793 (2)
//         004cfb0f     XOR        AL,AL
//                              tact_hnt.cpp:794 (8)
//         004cfb11     POP        EDI
//         004cfb12     POP        ESI
//         004cfb13     POP        EBP
//         004cfb14     POP        EBX
//         004cfb15     ADD        ESP,0xc
//         004cfb18     RET
//                               switchD_004cf8ed::caseD_6                                    XREF[2]:     004cf8ed(j), 004cfeac(*)
//                              tact_hnt.cpp:615 (7)
//         004cfb19     MOV        this,dword ptr [ESI + 0x10]
//         004cfb1c     TEST       this,this
//         004cfb1e     JNZ        LAB_004cfb59
//                              tact_hnt.cpp:617 (19)
//         004cfb20     MOV        this,dword ptr [ESI + 0x8]
//         004cfb23     FLD        float ptr [ECX + this+0x44]
//         004cfb26     FCOMP      float ptr [DAT_00575150]                         = align(18)
//         004cfb2c     FNSTSW     AX
//         004cfb2e     TEST       AH,0x41
//         004cfb31     JNZ        LAB_004cfb46
//                              tact_hnt.cpp:618 (9)
//         004cfb33     MOV        EDX,dword ptr [ESI]
//         004cfb35     PUSH       0x8
//         004cfb37     MOV        this,ESI
//         004cfb39     CALL       dword ptr [EDX + 0x5c]
//                              tact_hnt.cpp:793 (2)
//         004cfb3c     XOR        AL,AL
//                              tact_hnt.cpp:794 (8)
//         004cfb3e     POP        EDI
//         004cfb3f     POP        ESI
//         004cfb40     POP        EBP
//         004cfb41     POP        EBX
//         004cfb42     ADD        ESP,0xc
//         004cfb45     RET
//                               LAB_004cfb46                                                 XREF[4]:     004cf9d6(j), 004cfa1b(j),
//                                                                                                         004cfad8(j), 004cfb31(j)
//                              tact_hnt.cpp:620 (9)
//         004cfb46     MOV        EAX,dword ptr [ESI]
//         004cfb48     PUSH       0x3
//         004cfb4a     MOV        this,ESI
//         004cfb4c     CALL       dword ptr [EAX + 0x5c]
//                              tact_hnt.cpp:793 (2)
//         004cfb4f     XOR        AL,AL
//                              tact_hnt.cpp:794 (8)
//         004cfb51     POP        EDI
//         004cfb52     POP        ESI
//         004cfb53     POP        EBP
//         004cfb54     POP        EBX
//         004cfb55     ADD        ESP,0xc
//         004cfb58     RET
//                               LAB_004cfb59                                                 XREF[1]:     004cfb1e(j)
//                              tact_hnt.cpp:629 (16)
//         004cfb59     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
//         004cfb5f     MOV        EAX,dword ptr [EDX + 0x9a8]
//         004cfb65     TEST       EAX,EAX
//         004cfb67     JZ         LAB_004cfb6e
//                              tact_hnt.cpp:630 (3)
//         004cfb69     FLD        float ptr [ECX + this+0x44]
//                              tact_hnt.cpp:631 (2)
//         004cfb6c     JMP        LAB_004cfb8c
//                               LAB_004cfb6e                                                 XREF[1]:     004cfb67(j)
//                              tact_hnt.cpp:633 (30)
//         004cfb6e     MOV        EAX,dword ptr [ESI + 0x8]
//         004cfb71     MOV        EDX,dword ptr [ESI + 0x30]
//         004cfb74     MOV        EDI,dword ptr [EAX + 0x8]
//         004cfb77     MOV        EAX,dword ptr [EAX + 0xc]
//         004cfb7a     FLD        float ptr [EDX + 0x1c]
//         004cfb7d     FMUL       float ptr [EDI + 0xe4]
//         004cfb83     MOV        EDX,dword ptr [EAX + 0x3c]
//         004cfb86     FMUL       float ptr [EDX + 0x84]
//                               LAB_004cfb8c                                                 XREF[1]:     004cfb6c(j)
//                              tact_hnt.cpp:635 (12)
//         004cfb8c     FCOM       float ptr [ECX + this+0x44]
//         004cfb8f     FNSTSW     AX
//         004cfb91     TEST       AH,0x41
//         004cfb94     JNZ        LAB_004cfb9b
//         004cfb96     FSTP       ST0
//                              tact_hnt.cpp:636 (3)
//         004cfb98     FLD        float ptr [ECX + this+0x44]
//                               LAB_004cfb9b                                                 XREF[1]:     004cfb94(j)
//                              tact_hnt.cpp:638 (13)
//         004cfb9b     MOV        EAX,dword ptr [ESI + 0x30]
//         004cfb9e     MOV        AX,word ptr [EAX + 0x16]
//         004cfba2     CMP        AX,0xffff
//         004cfba6     JZ         LAB_004cfbbd
//                              tact_hnt.cpp:639 (19)
//         004cfba8     MOV        EDX,dword ptr [ESI + 0x8]
//         004cfbab     MOVSX      EAX,AX
//         004cfbae     MOV        EDX,dword ptr [EDX + 0xc]
//         004cfbb1     MOV        EDX,dword ptr [EDX + 0x50]
//         004cfbb4     FLD        float ptr [EDX + EAX*0x4]
//         004cfbb7     FSTP       float ptr [ESP + 0x14]
//                              tact_hnt.cpp:640 (2)
//         004cfbbb     JMP        LAB_004cfbc5
//                               LAB_004cfbbd                                                 XREF[1]:     004cfba6(j)
//                              tact_hnt.cpp:641 (8)
//         004cfbbd     MOV        dword ptr [ESP + 0x14],0x3f800000
//                               LAB_004cfbc5                                                 XREF[1]:     004cfbbb(j)
//                              tact_hnt.cpp:643 (3)
//         004cfbc5     MOV        EAX,dword ptr [ESI + 0x8]
//                              tact_hnt.cpp:644 (29)
//         004cfbc8     FLD        float ptr [ESP + 0x14]
//         004cfbcc     MOV        EDX,dword ptr [EAX + 0x8]
//         004cfbcf     FMUL       ST1
//         004cfbd1     MOVSX      EDX,word ptr [EDX + 0x7c]
//         004cfbd5     MOV        dword ptr [ESP + 0x18],EDX
//         004cfbd9     FILD       dword ptr [ESP + 0x18]
//         004cfbdd     FXCH
//         004cfbdf     FST        float ptr [ESP + 0x10]
//         004cfbe3     FXCH
//                              tact_hnt.cpp:645 (22)
//         004cfbe5     FMUL       float ptr [ESP + 0x14]
//         004cfbe9     FST        float ptr [ESP + 0x18]
//         004cfbed     FSUB       float ptr [EAX + 0x44]
//         004cfbf0     FXCH
//         004cfbf2     FCOMP
//         004cfbf4     FNSTSW     AX
//         004cfbf6     TEST       AH,0x41
//         004cfbf9     JNZ        LAB_004cfc15
//                              tact_hnt.cpp:647 (4)
//         004cfbfb     FSUBR      float ptr [ESP + 0x10]
//                              tact_hnt.cpp:648 (4)
//         004cfbff     FLD        float ptr [ESP + 0x10]
//                              tact_hnt.cpp:649 (18)
//         004cfc03     FLD        ST1
//         004cfc05     FDIV       float ptr [ESP + 0x14]
//         004cfc09     FXCH
//         004cfc0b     FSUB       ST0,ST2
//         004cfc0d     FXCH
//         004cfc0f     FSUBP      ST3,ST0
//         004cfc11     FSTP       float ptr [ESP + 0x10]
//                               LAB_004cfc15                                                 XREF[1]:     004cfbf9(j)
//                              tact_hnt.cpp:652 (20)
//         004cfc15     MOV        EAX,dword ptr [this->_padding_]
//         004cfc17     PUSH       0x1
//         004cfc19     FSTP       ST0
//         004cfc1b     PUSH       0x1
//         004cfc1d     PUSH       this
//         004cfc1e     FCHS
//         004cfc20     FSTP       float ptr [ESP]
//         004cfc23     CALL       dword ptr [EAX + 0x84]
//                              tact_hnt.cpp:653 (20)
//         004cfc29     MOV        this,dword ptr [ESI + 0x8]
//         004cfc2c     MOV        EAX,dword ptr [ESP + 0x10]
//         004cfc30     PUSH       0x0
//         004cfc32     PUSH       0x1
//         004cfc34     MOV        EDX,dword ptr [this->_padding_]
//         004cfc36     PUSH       EAX
//         004cfc37     CALL       dword ptr [EDX + 0x84]
//                              tact_hnt.cpp:657 (40)
//         004cfc3d     MOV        this,dword ptr [ESI + 0x8]
//         004cfc40     FLD        float ptr [ECX + this+0x44]
//         004cfc43     FCOMP      float ptr [ESP + 0x18]
//         004cfc47     FNSTSW     AX
//         004cfc49     TEST       AH,0x1
//         004cfc4c     JZ         LAB_004cfc65
//         004cfc4e     MOV        EDX,dword ptr [ESI + 0x10]
//         004cfc51     FLD        float ptr [EDX + 0x44]
//         004cfc54     FCOMP      float ptr [DAT_00575150]                         = align(18)
//         004cfc5a     FNSTSW     AX
//         004cfc5c     TEST       AH,0x41
//         004cfc5f     JZ         switchD_004cf8ed::caseD_1
//                               LAB_004cfc65                                                 XREF[1]:     004cfc4c(j)
//                              tact_hnt.cpp:659 (9)
//         004cfc65     MOV        EAX,dword ptr [ESI]
//         004cfc67     PUSH       0x8
//         004cfc69     MOV        this,ESI
//         004cfc6b     CALL       dword ptr [EAX + 0x5c]
//                              tact_hnt.cpp:793 (2)
//         004cfc6e     XOR        AL,AL
//                              tact_hnt.cpp:794 (8)
//         004cfc70     POP        EDI
//         004cfc71     POP        ESI
//         004cfc72     POP        EBP
//         004cfc73     POP        EBX
//         004cfc74     ADD        ESP,0xc
//         004cfc77     RET
//                               switchD_004cf8ed::caseD_7                                    XREF[2]:     004cf8ed(j), 004cfeb0(*)
//                              tact_hnt.cpp:667 (16)
//         004cfc78     FLD        float ptr [ESI + 0x2c]
//         004cfc7b     FCOMP      double ptr [null_00575158]                       = align(10)
//         004cfc81     FNSTSW     AX
//         004cfc83     TEST       AH,0x1
//         004cfc86     JZ         LAB_004cfccf
//                              tact_hnt.cpp:669 (18)
//         004cfc88     MOV        this,dword ptr [ESI + 0x8]
//         004cfc8b     MOV        EDX,dword ptr [ECX + this->_padding_]
//         004cfc8e     MOV        EAX,dword ptr [EDX + 0x3c]
//         004cfc91     FLD        float ptr [EAX + 0x84]
//         004cfc97     FADD       float ptr [ESI + 0x2c]
//                              tact_hnt.cpp:670 (20)
//         004cfc9a     FCOM       double ptr [null_00575158]                       = align(10)
//         004cfca0     FSTP       float ptr [ESI + 0x2c]
//         004cfca3     FNSTSW     AX
//         004cfca5     TEST       AH,0x41
//         004cfca8     JNZ        switchD_004cf8ed::caseD_1
//                              tact_hnt.cpp:673 (16)
//         004cfcae     MOV        EDI,dword ptr [ESI]
//         004cfcb0     PUSH       0x0
//         004cfcb2     MOV        this,ESI
//         004cfcb4     MOV        dword ptr [ESI + 0x2c],0x0
//         004cfcbb     CALL       dword ptr [EDI + 0x58]
//                              tact_hnt.cpp:674 (7)
//         004cfcbe     PUSH       0x8
//         004cfcc0     MOV        this,ESI
//         004cfcc2     CALL       dword ptr [EDI + 0x5c]
//                              tact_hnt.cpp:793 (2)
//         004cfcc5     XOR        AL,AL
//                              tact_hnt.cpp:794 (8)
//         004cfcc7     POP        EDI
//         004cfcc8     POP        ESI
//         004cfcc9     POP        EBP
//         004cfcca     POP        EBX
//         004cfccb     ADD        ESP,0xc
//         004cfcce     RET
//                               LAB_004cfccf                                                 XREF[1]:     004cfc86(j)
//                              tact_hnt.cpp:680 (30)
//         004cfccf     MOV        this,dword ptr [ESI + 0x34]
//         004cfcd2     MOV        EDX,dword ptr [this->_padding_]
//         004cfcd4     CALL       dword ptr [EDX + 0xc]
//         004cfcd7     AND        EAX,0xff
//         004cfcdc     DEC        EAX
//         004cfcdd     CMP        EAX,0x4
//         004cfce0     JA         switchD_004cf8ed::caseD_1
//                               switchD_004cfce6::switchD
//         004cfce6     JMP        dword ptr [EAX*0x4 + switchD_004cfce6::switchd   = 004cfd09
//                               switchD_004cfce6::caseD_3                                    XREF[4]:     004cfce6(j), 004cff14(*),
//                               switchD_004cfce6::caseD_4                                                 004cff18(*), 004cff1c(*)
//                               switchD_004cfce6::caseD_2
//                              tact_hnt.cpp:690 (18)
//         004cfced     MOV        this,dword ptr [ESI + 0x8]
//         004cfcf0     MOV        dword ptr [ESI + 0x2c],0xc0400000
//         004cfcf7     MOV        EAX,dword ptr [this->_padding_]
//         004cfcf9     CALL       dword ptr [EAX + 0x1ec]
//                              tact_hnt.cpp:793 (2)
//         004cfcff     XOR        AL,AL
//                              tact_hnt.cpp:794 (8)
//         004cfd01     POP        EDI
//         004cfd02     POP        ESI
//         004cfd03     POP        EBP
//         004cfd04     POP        EBX
//         004cfd05     ADD        ESP,0xc
//         004cfd08     RET
//                               switchD_004cfce6::caseD_1                                    XREF[3]:     004cfce6(j), 004cff0c(*),
//                               switchD_004cfce6::caseD_0                                                 004cff10(*)
//                              tact_hnt.cpp:697 (11)
//         004cfd09     MOV        EAX,dword ptr [ESI + 0x14]
//         004cfd0c     TEST       EAX,EAX
//         004cfd0e     JZ         LAB_004cfe2a
//                              tact_hnt.cpp:699 (9)
//         004cfd14     MOV        this,dword ptr [ESI + 0x8]
//         004cfd17     PUSH       EAX
//         004cfd18     CALL       RGE_Static_Object::distance_to_object            float distance_to_object(RGE_Static_Object *
//                              tact_hnt.cpp:702 (13)
//         004cfd1d     FCOMP      double ptr [DAT_00575168]
//         004cfd23     FNSTSW     AX
//         004cfd25     TEST       AH,0x41
//         004cfd28     JNZ        LAB_004cfd46
//                              tact_hnt.cpp:705 (18)
//         004cfd2a     MOV        this,dword ptr [ESI + 0x8]
//         004cfd2d     MOV        dword ptr [ESI + 0x2c],0xc0400000
//         004cfd34     MOV        EDX,dword ptr [this->_padding_]
//         004cfd36     CALL       dword ptr [EDX + 0x1ec]
//                              tact_hnt.cpp:793 (2)
//         004cfd3c     XOR        AL,AL
//                              tact_hnt.cpp:794 (8)
//         004cfd3e     POP        EDI
//         004cfd3f     POP        ESI
//         004cfd40     POP        EBP
//         004cfd41     POP        EBX
//         004cfd42     ADD        ESP,0xc
//         004cfd45     RET
//                               LAB_004cfd46                                                 XREF[1]:     004cfd28(j)
//                              tact_hnt.cpp:712 (10)
//         004cfd46     MOV        EAX,dword ptr [ESI + 0x30]
//         004cfd49     MOV        this,dword ptr [EAX + 0x48]
//         004cfd4c     TEST       this,this
//         004cfd4e     JZ         LAB_004cfd57
//                              tact_hnt.cpp:713 (7)
//         004cfd50     PUSH       0x1
//         004cfd52     CALL       RGE_Sound::play                                  void play(RGE_Sound * this, int param_1)
//                               LAB_004cfd57                                                 XREF[1]:     004cfd4e(j)
//                              tact_hnt.cpp:715 (11)
//         004cfd57     MOV        this,dword ptr [ESI + 0x30]
//         004cfd5a     MOV        DX,word ptr [ECX + this->_padding_]
//         004cfd5e     CMP        DX,-0x1
//                              tact_hnt.cpp:717 (2)
//         004cfd62     JNZ        LAB_004cfd6b
//                              tact_hnt.cpp:718 (7)
//         004cfd64     MOV        EDX,dword ptr [ESI + 0x8]
//         004cfd67     MOV        DX,word ptr [EDX + 0x4c]
//                               LAB_004cfd6b                                                 XREF[1]:     004cfd62(j)
//                              tact_hnt.cpp:724 (22)
//         004cfd6b     MOV        EAX,dword ptr [ESI + 0x8]
//         004cfd6e     PUSH       0x0
//         004cfd70     MOV        dword ptr [ESP + 0x1c],EDX
//         004cfd74     MOV        this,dword ptr [EAX + 0xc]
//         004cfd77     MOV        EAX,dword ptr [EAX + 0x44]
//         004cfd7a     PUSH       EAX
//         004cfd7b     PUSH       EDX
//         004cfd7c     MOV        EDI,dword ptr [this->_padding_]
//         004cfd7e     CALL       dword ptr [EDI + 0x78]
//                              tact_hnt.cpp:725 (32)
//         004cfd81     MOV        EDI,dword ptr [ESI + 0x8]
//         004cfd84     MOV        EBX,dword ptr [EDI + 0xc]
//         004cfd87     FLD        float ptr [EDI + 0x44]
//         004cfd8a     MOV        EBP,dword ptr [EBX]
//         004cfd8c     CALL       __ftol                                           undefined __ftol()
//         004cfd91     MOVSX      this,word ptr [ESP + 0x18]
//         004cfd96     MOV        EDX,dword ptr [EDI + 0x4]
//         004cfd99     PUSH       EAX
//         004cfd9a     PUSH       this
//         004cfd9b     PUSH       EDX
//         004cfd9c     MOV        this,EBX
//         004cfd9e     CALL       dword ptr [EBP + 0x5c]
//                              tact_hnt.cpp:726 (15)
//         004cfda1     MOV        this,dword ptr [ESI + 0x8]
//         004cfda4     PUSH       0x0
//         004cfda6     PUSH       -0x1
//         004cfda8     MOV        EAX,dword ptr [this->_padding_]
//         004cfdaa     CALL       dword ptr [EAX + 0x80]
//                              tact_hnt.cpp:731 (7)
//         004cfdb0     MOV        EAX,dword ptr [ESI + 0x10]
//         004cfdb3     TEST       EAX,EAX
//         004cfdb5     JZ         LAB_004cfdd1
//                              tact_hnt.cpp:739 (9)
//         004cfdb7     MOV        EDI,dword ptr [ESI]
//         004cfdb9     PUSH       0x0
//         004cfdbb     MOV        this,ESI
//         004cfdbd     CALL       dword ptr [EDI + 0x58]
//                              tact_hnt.cpp:740 (7)
//         004cfdc0     PUSH       0x4
//         004cfdc2     MOV        this,ESI
//         004cfdc4     CALL       dword ptr [EDI + 0x5c]
//                              tact_hnt.cpp:793 (2)
//         004cfdc7     XOR        AL,AL
//                              tact_hnt.cpp:794 (8)
//         004cfdc9     POP        EDI
//         004cfdca     POP        ESI
//         004cfdcb     POP        EBP
//         004cfdcc     POP        EBX
//         004cfdcd     ADD        ESP,0xc
//         004cfdd0     RET
//                               LAB_004cfdd1                                                 XREF[1]:     004cfdb5(j)
//                              tact_hnt.cpp:742 (17)
//         004cfdd1     MOV        this,dword ptr [ESI + 0x20]
//         004cfdd4     MOV        EAX,0xbf800000
//         004cfdd9     CMP        this,EAX
//         004cfddb     JZ         LAB_004cfdf5
//         004cfddd     CMP        dword ptr [ESI + 0x24],EAX
//         004cfde0     JZ         LAB_004cfdf5
//                              tact_hnt.cpp:748 (9)
//         004cfde2     MOV        EDX,dword ptr [ESI]
//         004cfde4     PUSH       0xb
//         004cfde6     MOV        this,ESI
//         004cfde8     CALL       dword ptr [EDX + 0x5c]
//                              tact_hnt.cpp:793 (2)
//         004cfdeb     XOR        AL,AL
//                              tact_hnt.cpp:794 (8)
//         004cfded     POP        EDI
//         004cfdee     POP        ESI
//         004cfdef     POP        EBP
//         004cfdf0     POP        EBX
//         004cfdf1     ADD        ESP,0xc
//         004cfdf4     RET
//                               LAB_004cfdf5                                                 XREF[3]:     004cf9af(j), 004cfddb(j),
//                                                                                                         004cfde0(j)
//                              tact_hnt.cpp:754 (15)
//         004cfdf5     MOV        EAX,dword ptr [ESI + 0x8]
//         004cfdf8     MOV        this,dword ptr [EAX + 0xc]
//         004cfdfb     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
//         004cfe00     TEST       EAX,EAX
//         004cfe02     JNZ        LAB_004cfe17
//                              tact_hnt.cpp:755 (9)
//         004cfe04     MOV        EDX,dword ptr [ESI]
//         004cfe06     PUSH       0x2
//         004cfe08     MOV        this,ESI
//         004cfe0a     CALL       dword ptr [EDX + 0x5c]
//                              tact_hnt.cpp:793 (2)
//         004cfe0d     XOR        AL,AL
//                              tact_hnt.cpp:794 (8)
//         004cfe0f     POP        EDI
//         004cfe10     POP        ESI
//         004cfe11     POP        EBP
//         004cfe12     POP        EBX
//         004cfe13     ADD        ESP,0xc
//         004cfe16     RET
//                               LAB_004cfe17                                                 XREF[1]:     004cfe02(j)
//                              tact_hnt.cpp:757 (9)
//         004cfe17     MOV        EAX,dword ptr [ESI]
//         004cfe19     PUSH       0x1
//         004cfe1b     MOV        this,ESI
//         004cfe1d     CALL       dword ptr [EAX + 0x5c]
//                              tact_hnt.cpp:793 (2)
//         004cfe20     XOR        AL,AL
//                              tact_hnt.cpp:794 (8)
//         004cfe22     POP        EDI
//         004cfe23     POP        ESI
//         004cfe24     POP        EBP
//         004cfe25     POP        EBX
//         004cfe26     ADD        ESP,0xc
//         004cfe29     RET
//                               LAB_004cfe2a                                                 XREF[1]:     004cfd0e(j)
//                              tact_hnt.cpp:761 (9)
//         004cfe2a     MOV        EDX,dword ptr [ESI]
//         004cfe2c     PUSH       0x8
//         004cfe2e     MOV        this,ESI
//         004cfe30     CALL       dword ptr [EDX + 0x5c]
//                              tact_hnt.cpp:793 (2)
//         004cfe33     XOR        AL,AL
//                              tact_hnt.cpp:794 (8)
//         004cfe35     POP        EDI
//         004cfe36     POP        ESI
//         004cfe37     POP        EBP
//         004cfe38     POP        EBX
//         004cfe39     ADD        ESP,0xc
//         004cfe3c     RET
//                               switchD_004cf8ed::caseD_0                                    XREF[2]:     004cf8ed(j), 004cfe94(*)
//                              tact_hnt.cpp:775 (15)
//         004cfe3d     MOV        EAX,dword ptr [ESI + 0x8]
//         004cfe40     MOV        this,dword ptr [EAX + 0xc]
//         004cfe43     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
//         004cfe48     TEST       EAX,EAX
//         004cfe4a     JNZ        LAB_004cfe55
//                              tact_hnt.cpp:776 (9)
//         004cfe4c     MOV        EDX,dword ptr [ESI]
//         004cfe4e     PUSH       0x2
//         004cfe50     MOV        this,ESI
//         004cfe52     CALL       dword ptr [EDX + 0x5c]
//                               LAB_004cfe55                                                 XREF[1]:     004cfe4a(j)
//                              tact_hnt.cpp:777 (2)
//         004cfe55     MOV        AL,0x1
//                              tact_hnt.cpp:794 (8)
//         004cfe57     POP        EDI
//         004cfe58     POP        ESI
//         004cfe59     POP        EBP
//         004cfe5a     POP        EBX
//         004cfe5b     ADD        ESP,0xc
//         004cfe5e     RET
//                               switchD_004cf8ed::caseD_c                                    XREF[2]:     004cf8ed(j), 004cfec4(*)
//                              tact_hnt.cpp:781 (32)
//         004cfe5f     MOV        ESI,dword ptr [ESI + 0x8]
//         004cfe62     PUSH       0x0
//         004cfe64     PUSH       0x0
//         004cfe66     PUSH       0x265
//         004cfe6b     MOV        EAX,dword ptr [ESI + 0x4]
//         004cfe6e     MOV        EDX,dword ptr [ESI]
//         004cfe70     PUSH       0x1f9
//         004cfe75     PUSH       EAX
//         004cfe76     PUSH       EAX
//         004cfe77     MOV        this,ESI
//         004cfe79     CALL       dword ptr [EDX + 0x148]
//                              tact_hnt.cpp:785 (2)
//         004cfe7f     MOV        AL,0x3
//                              tact_hnt.cpp:794 (159)
//         004cfe81     POP        EDI
//         004cfe82     POP        ESI
//         004cfe83     POP        EBP
//         004cfe84     POP        EBX
//         004cfe85     ADD        ESP,0xc
//         004cfe88     RET
//                               switchD_004cf8ed::caseD_4                                    XREF[15]:    004cf8e7(j), 004cf8ed(j),
//                               switchD_004cf8ed::caseD_8                                                 004cf902(j), 004cf928(j),
//                               switchD_004cf8ed::caseD_9                                                 004cf96d(j), 004cfa00(j),
//                               switchD_004cf8ed::caseD_d                                                 004cfa58(j), 004cfc5f(j),
//                               switchD_004cf973::default                                                 004cfca8(j), 004cfce0(j),
//                               switchD_004cfa5e::default                                                 004cfe98(*), 004cfea4(*),
//                               switchD_004cfce6::default                                                 004cfeb4(*), 004cfeb8(*),
//                               switchD_004cfa06::default                                                 004cfec8(*)
//                               switchD_004cf8ed::caseD_1
//         004cfe89     POP        EDI
//         004cfe8a     POP        ESI
//         004cfe8b     POP        EBP
//         004cfe8c     XOR        AL,AL
//         004cfe8e     POP        EBX
//         004cfe8f     ADD        ESP,0xc
//         004cfe92     RET
//         004cfe93     ??         90h
//                              Symbol Ref: No symbol: NONAME
//                               switchD_004cf8ed::switchdataD_004cfe94                       XREF[1]:     update:004cf8ed(*)
//         004cfe94     addr       switchD_004cf8ed::caseD_0
//         004cfe98     addr       switchD_004cf8ed::caseD_1
//         004cfe9c     addr       switchD_004cf8ed::caseD_2
//         004cfea0     addr       switchD_004cf8ed::caseD_3
//         004cfea4     addr       switchD_004cf8ed::caseD_1
//         004cfea8     addr       switchD_004cf8ed::caseD_5
//         004cfeac     addr       switchD_004cf8ed::caseD_6
//         004cfeb0     addr       switchD_004cf8ed::caseD_7
//         004cfeb4     addr       switchD_004cf8ed::caseD_1
//         004cfeb8     addr       switchD_004cf8ed::caseD_1
//         004cfebc     addr       switchD_004cf8ed::caseD_a
//         004cfec0     addr       switchD_004cf8ed::caseD_b
//         004cfec4     addr       switchD_004cf8ed::caseD_c
//         004cfec8     addr       switchD_004cf8ed::caseD_1
//         004cfecc     addr       switchD_004cf8ed::caseD_a
//                              Symbol Ref: No symbol: NONAME
//                               switchD_004cf973::switchdataD_004cfed0                       XREF[1]:     update:004cf973(*)
//         004cfed0     addr       switchD_004cf973::caseD_0
//         004cfed4     addr       switchD_004cf973::caseD_0
//         004cfed8     addr       switchD_004cf973::caseD_2
//         004cfedc     addr       switchD_004cf973::caseD_3
//         004cfee0     addr       switchD_004cf973::caseD_0
//                              Symbol Ref: No symbol: NONAME
//                               switchD_004cfa06::switchdataD_004cfee4                       XREF[1]:     update:004cfa06(*)
//         004cfee4     addr       switchD_004cfa06::caseD_0
//         004cfee8     addr       switchD_004cfa06::caseD_0
//         004cfeec     addr       switchD_004cfa06::caseD_2
//         004cfef0     addr       switchD_004cfa5e::caseD_3
//         004cfef4     addr       switchD_004cfa5e::caseD_3
//                              Symbol Ref: No symbol: NONAME
//                               switchD_004cfa5e::switchdataD_004cfef8                       XREF[1]:     update:004cfa5e(*)
//         004cfef8     addr       switchD_004cfa5e::caseD_0
//         004cfefc     addr       switchD_004cfa5e::caseD_0
//         004cff00     addr       switchD_004cfa5e::caseD_2
//         004cff04     addr       switchD_004cfa5e::caseD_3
//         004cff08     addr       switchD_004cfa5e::caseD_0
//                              Symbol Ref: No symbol: NONAME
//                               switchD_004cfce6::switchdataD_004cff0c                       XREF[1]:     update:004cfce6(*)
//         004cff0c     addr       switchD_004cfce6::caseD_0
//         004cff10     addr       switchD_004cfce6::caseD_0
//         004cff14     addr       switchD_004cfce6::caseD_2
//         004cff18     addr       switchD_004cfce6::caseD_2
//         004cff1c     addr       switchD_004cfce6::caseD_2
    return 0;
}

RGE_Sprite* TRIBE_Action_Hunt::get_move_sprite() {
    /* TODO: Stub */
//                              RGE_Sprite * __thiscall get_move_sprite(TRIBE_Action_Hunt * this)
//              RGE_Sprite *      EAX:4          <RETURN>
//              TRIBE_Action_H    ECX:4 (auto)   this
//                               ?get_move_sprite@TRIBE_Action_Hunt@@IAEPAVRGE_Sprite@@XZ     XREF[5]:     set_state:004cf3fe(c),
//                               TRIBE_Action_Hunt::get_move_sprite                                        set_state:004cf4f7(c),
//                                                                                                         set_state:004cf595(c),
//                                                                                                         set_state:004cf5eb(c),
//                                                                                                         set_state:004cf6dd(c)
//                              tact_hnt.cpp:800 (1)
//         004cff20     PUSH       ESI
//                              tact_hnt.cpp:803 (39)
//         004cff21     MOV        ESI,dword ptr [ECX + this->_padding_]
//         004cff24     MOV        AX,word ptr [ESI + 0x14]
//         004cff28     CMP        AX,0xffff
//         004cff2c     JZ         LAB_004cff4a
//         004cff2e     MOV        this,dword ptr [ECX + this->_padding_]
//         004cff31     CMP        AX,word ptr [this->_padding_ + 0x4c]
//         004cff35     JNZ        LAB_004cff4a
//         004cff37     FLD        float ptr [ECX + this+0x44]
//         004cff3a     CALL       __ftol                                           undefined __ftol()
//         004cff3f     TEST       EAX,EAX
//         004cff41     JLE        LAB_004cff4a
//         004cff43     MOV        EAX,dword ptr [ESI + 0x40]
//         004cff46     TEST       EAX,EAX
//                              tact_hnt.cpp:804 (2)
//         004cff48     JNZ        LAB_004cff4d
//                               LAB_004cff4a                                                 XREF[3]:     004cff2c(j), 004cff35(j),
//                                                                                                         004cff41(j)
//                              tact_hnt.cpp:806 (3)
//         004cff4a     MOV        EAX,dword ptr [ESI + 0x34]
//                               LAB_004cff4d                                                 XREF[1]:     004cff48(j)
//                              tact_hnt.cpp:807 (2)
//         004cff4d     POP        ESI
//         004cff4e     RET
//         004cff4f     ??         90h
    return 0;
}

RGE_Sprite* TRIBE_Action_Hunt::get_wait_sprite() {
    /* TODO: Stub */
//                              RGE_Sprite * __thiscall get_wait_sprite(TRIBE_Action_Hunt * this)
//              RGE_Sprite *      EAX:4          <RETURN>
//              TRIBE_Action_H    ECX:4 (auto)   this
//                               ?get_wait_sprite@TRIBE_Action_Hunt@@IAEPAVRGE_Sprite@@XZ     XREF[3]:     set_state:004cf366(c),
//                               TRIBE_Action_Hunt::get_wait_sprite                                        set_state:004cf394(c),
//                                                                                                         set_state:004cf800(c)
//                              tact_hnt.cpp:813 (4)
//         004cff50     PUSH       ESI
//         004cff51     MOV        ESI,this
//         004cff53     PUSH       EDI
//                              tact_hnt.cpp:816 (39)
//         004cff54     MOV        EDI,dword ptr [ESI + 0x30]
//         004cff57     MOV        AX,word ptr [EDI + 0x14]
//         004cff5b     CMP        AX,0xffff
//         004cff5f     JZ         LAB_004cff7d
//         004cff61     MOV        this,dword ptr [ESI + 0x8]
//         004cff64     CMP        AX,word ptr [this->_padding_ + 0x4c]
//         004cff68     JNZ        LAB_004cff7d
//         004cff6a     FLD        float ptr [ECX + this+0x44]
//         004cff6d     CALL       __ftol                                           undefined __ftol()
//         004cff72     TEST       EAX,EAX
//         004cff74     JLE        LAB_004cff7d
//         004cff76     MOV        EAX,dword ptr [EDI + 0x40]
//         004cff79     TEST       EAX,EAX
//                              tact_hnt.cpp:817 (2)
//         004cff7b     JNZ        LAB_004cff86
//                               LAB_004cff7d                                                 XREF[3]:     004cff5f(j), 004cff68(j),
//                                                                                                         004cff74(j)
//                              tact_hnt.cpp:819 (9)
//         004cff7d     MOV        EAX,dword ptr [ESI + 0x8]
//         004cff80     MOV        this,dword ptr [EAX + 0x8]
//         004cff83     MOV        EAX,dword ptr [ECX + this->_padding_]
//                               LAB_004cff86                                                 XREF[1]:     004cff7b(j)
//                              tact_hnt.cpp:820 (3)
//         004cff86     POP        EDI
//         004cff87     POP        ESI
//         004cff88     RET
//         004cff89     ??         90h
//         004cff8a     NOP
//         004cff8b     NOP
//         004cff8c     NOP
//         004cff8d     NOP
//         004cff8e     NOP
//         004cff8f     NOP
    return 0;
}

int TRIBE_Action_Hunt::stop() {
    /* TODO: Stub */
//                              int __thiscall stop(TRIBE_Action_Hunt * this)
//              int               EAX:4          <RETURN>
//              TRIBE_Action_H    ECX:4 (auto)   this
//                               ?stop@TRIBE_Action_Hunt@@UAEHXZ                              XREF[1]:     0057511c(*)
//                               TRIBE_Action_Hunt::stop
//                              tact_hnt.cpp:826 (3)
//         004cff90     PUSH       ESI
//         004cff91     MOV        ESI,this
//                              tact_hnt.cpp:828 (15)
//         004cff93     MOV        EAX,dword ptr [ESI + 0x8]
//         004cff96     MOV        this,dword ptr [EAX + 0xc]
//         004cff99     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
//         004cff9e     TEST       EAX,EAX
//         004cffa0     JNZ        LAB_004cffb2
//                              tact_hnt.cpp:829 (9)
//         004cffa2     MOV        EDX,dword ptr [ESI]
//         004cffa4     PUSH       0x2
//         004cffa6     MOV        this,ESI
//         004cffa8     CALL       dword ptr [EDX + 0x5c]
//                              tact_hnt.cpp:832 (5)
//         004cffab     MOV        EAX,0x1
//                              tact_hnt.cpp:833 (2)
//         004cffb0     POP        ESI
//         004cffb1     RET
//                               LAB_004cffb2                                                 XREF[1]:     004cffa0(j)
//                              tact_hnt.cpp:831 (9)
//         004cffb2     MOV        EAX,dword ptr [ESI]
//         004cffb4     PUSH       0x1
//         004cffb6     MOV        this,ESI
//         004cffb8     CALL       dword ptr [EAX + 0x5c]
//                              tact_hnt.cpp:832 (5)
//         004cffbb     MOV        EAX,0x1
//                              tact_hnt.cpp:833 (2)
//         004cffc0     POP        ESI
//         004cffc1     RET
//         004cffc2     ??         90h
//         004cffc3     NOP
//         004cffc4     NOP
//         004cffc5     NOP
//         004cffc6     NOP
//         004cffc7     NOP
//         004cffc8     NOP
//         004cffc9     NOP
//         004cffca     NOP
//         004cffcb     NOP
//         004cffcc     NOP
//         004cffcd     NOP
//         004cffce     NOP
//         004cffcf     NOP
    return 0;
}

int TRIBE_Action_Hunt::move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    /* TODO: Stub */
//                              int __thiscall move_to(TRIBE_Action_Hunt * this, RGE_Static_Object *
//              int               EAX:4          <RETURN>
//              TRIBE_Action_H    ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004cffd1(R)
//              float             Stack[0x8]:4   param_2                   XREF[1]:     004d0052(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     004d0056(R)
//              float             Stack[0x10]:4  param_4                   XREF[1]:     004d004e(R)
//                               ?move_to@TRIBE_Action_Hunt@@UAEHPAVRGE_Static_Object@@MMM@Z  XREF[1]:     00575120(*)
//                               TRIBE_Action_Hunt::move_to
//                              tact_hnt.cpp:840 (1)
//         004cffd0     PUSH       EBX
//                              tact_hnt.cpp:858 (67)
//         004cffd1     MOV        EBX,dword ptr [ESP + param_1]
//         004cffd5     PUSH       ESI
//         004cffd6     PUSH       EDI
//         004cffd7     TEST       EBX,EBX
//         004cffd9     MOV        ESI,this
//         004cffdb     JZ         LAB_004d004e
//         004cffdd     MOV        EDX,dword ptr [ESI + 0x8]
//         004cffe0     MOV        EAX,dword ptr [EBX + 0xc]
//         004cffe3     CMP        EAX,dword ptr [EDX + 0xc]
//         004cffe6     JNZ        LAB_004d004e
//         004cffe8     MOV        this,dword ptr [EBX + 0x8]
//         004cffeb     MOV        EAX,dword ptr [EDX + 0x8]
//         004cffee     MOV        this,word ptr [ECX + this->_padding_]
//         004cfff2     CMP        this,word ptr [EAX + 0xe8]
//         004cfff9     JZ         LAB_004d0004
//         004cfffb     CMP        this,word ptr [EAX + 0xea]
//         004d0002     JNZ        LAB_004d004e
//                               LAB_004d0004                                                 XREF[1]:     004cfff9(j)
//         004d0004     FLD        float ptr [EDX + 0x44]
//         004d0007     FCOMP      float ptr [DAT_00575150]                         = align(18)
//         004d000d     FNSTSW     AX
//         004d000f     TEST       AH,0x41
//         004d0012     JNZ        LAB_004d004e
//                              tact_hnt.cpp:862 (9)
//         004d0014     CMP        EBX,dword ptr [ESI + 0x14]
//         004d0017     JNZ        LAB_004d001f
//         004d0019     CMP        byte ptr [ESI + 0xc],0x8
//                              tact_hnt.cpp:863 (2)
//         004d001d     JZ         LAB_004d0073
//                               LAB_004d001f                                                 XREF[1]:     004d0017(j)
//                              tact_hnt.cpp:866 (9)
//         004d001f     MOV        EDI,dword ptr [ESI]
//         004d0021     PUSH       0x0
//         004d0023     MOV        this,ESI
//         004d0025     CALL       dword ptr [EDI + 0x54]
//                              tact_hnt.cpp:867 (5)
//         004d0028     MOV        EAX,0xbf800000
//                              tact_hnt.cpp:871 (15)
//         004d002d     PUSH       EBX
//         004d002e     MOV        this,ESI
//         004d0030     MOV        dword ptr [ESI + 0x20],EAX
//         004d0033     MOV        dword ptr [ESI + 0x24],EAX
//         004d0036     MOV        dword ptr [ESI + 0x28],EAX
//         004d0039     CALL       dword ptr [EDI + 0x58]
//                              tact_hnt.cpp:872 (2)
//         004d003c     PUSH       0x8
//                              tact_hnt.cpp:880 (5)
//         004d003e     MOV        this,ESI
//         004d0040     CALL       dword ptr [EDI + 0x5c]
//                              tact_hnt.cpp:882 (5)
//         004d0043     MOV        EAX,0x1
//                              tact_hnt.cpp:883 (6)
//         004d0048     POP        EDI
//         004d0049     POP        ESI
//         004d004a     POP        EBX
//         004d004b     RET        0x10
//                               LAB_004d004e                                                 XREF[4]:     004cffdb(j), 004cffe6(j),
//                                                                                                         004d0002(j), 004d0012(j)
//                              tact_hnt.cpp:878 (12)
//         004d004e     MOV        this,dword ptr [ESP + param_4]
//         004d0052     MOV        EDX,dword ptr [ESP + param_2]
//         004d0056     MOV        EAX,dword ptr [ESP + param_3]
//                              tact_hnt.cpp:879 (18)
//         004d005a     MOV        EDI,dword ptr [ESI]
//         004d005c     MOV        dword ptr [ESI + 0x28],this
//         004d005f     PUSH       0x0
//         004d0061     MOV        this,ESI
//         004d0063     MOV        dword ptr [ESI + 0x20],EDX
//         004d0066     MOV        dword ptr [ESI + 0x24],EAX
//         004d0069     CALL       dword ptr [EDI + 0x54]
//                              tact_hnt.cpp:880 (7)
//         004d006c     PUSH       0xf
//         004d006e     MOV        this,ESI
//         004d0070     CALL       dword ptr [EDI + 0x5c]
//                               LAB_004d0073                                                 XREF[1]:     004d001d(j)
//                              tact_hnt.cpp:883 (11)
//         004d0073     POP        EDI
//         004d0074     POP        ESI
//         004d0075     MOV        EAX,0x1
//         004d007a     POP        EBX
//         004d007b     RET        0x10
//         004d007e     ??         90h
//         004d007f     NOP
    return 0;
}

int TRIBE_Action_Hunt::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    /* TODO: Stub */
//                              int __thiscall work(TRIBE_Action_Hunt * this, RGE_Static_Object * pa
//              int               EAX:4          <RETURN>
//              TRIBE_Action_H    ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004d0081(R)
//              float             Stack[0x8]:4   param_2                   XREF[1]:     004d0123(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     004d0127(R)
//              float             Stack[0x10]:4  param_4                   XREF[1]:     004d011f(R)
//                               ?work@TRIBE_Action_Hunt@@UAEHPAVRGE_Static_Object@@MMM@Z     XREF[1]:     00575124(*)
//                               TRIBE_Action_Hunt::work
//                              tact_hnt.cpp:890 (1)
//         004d0080     PUSH       EBX
//                              tact_hnt.cpp:907 (16)
//         004d0081     MOV        EBX,dword ptr [ESP + param_1]
//         004d0085     PUSH       ESI
//         004d0086     PUSH       EDI
//         004d0087     TEST       EBX,EBX
//         004d0089     MOV        ESI,this
//         004d008b     JZ         LAB_004d011f
//                              tact_hnt.cpp:912 (55)
//         004d0091     MOV        EDX,dword ptr [ESI + 0x8]
//         004d0094     MOV        EAX,dword ptr [EBX + 0xc]
//         004d0097     CMP        EAX,dword ptr [EDX + 0xc]
//         004d009a     JNZ        LAB_004d00fe
//         004d009c     MOV        this,dword ptr [EBX + 0x8]
//         004d009f     MOV        EAX,dword ptr [EDX + 0x8]
//         004d00a2     MOV        this,word ptr [ECX + this->_padding_]
//         004d00a6     CMP        this,word ptr [EAX + 0xe8]
//         004d00ad     JZ         LAB_004d00b8
//         004d00af     CMP        this,word ptr [EAX + 0xea]
//         004d00b6     JNZ        LAB_004d00fe
//                               LAB_004d00b8                                                 XREF[1]:     004d00ad(j)
//         004d00b8     FLD        float ptr [EDX + 0x44]
//         004d00bb     FCOMP      float ptr [DAT_00575150]                         = align(18)
//         004d00c1     FNSTSW     AX
//         004d00c3     TEST       AH,0x41
//         004d00c6     JNZ        LAB_004d00fe
//                              tact_hnt.cpp:918 (9)
//         004d00c8     MOV        EDI,dword ptr [ESI]
//         004d00ca     PUSH       0x0
//         004d00cc     MOV        this,ESI
//         004d00ce     CALL       dword ptr [EDI + 0x54]
//                              tact_hnt.cpp:920 (5)
//         004d00d1     MOV        EAX,0xbf800000
//                              tact_hnt.cpp:923 (22)
//         004d00d6     PUSH       EBX
//         004d00d7     MOV        this,ESI
//         004d00d9     MOV        dword ptr [ESI + 0x2c],0x0
//         004d00e0     MOV        dword ptr [ESI + 0x20],EAX
//         004d00e3     MOV        dword ptr [ESI + 0x24],EAX
//         004d00e6     MOV        dword ptr [ESI + 0x28],EAX
//         004d00e9     CALL       dword ptr [EDI + 0x58]
//                              tact_hnt.cpp:924 (2)
//         004d00ec     PUSH       0x8
//                              tact_hnt.cpp:945 (5)
//         004d00ee     MOV        this,ESI
//         004d00f0     CALL       dword ptr [EDI + 0x5c]
//                              tact_hnt.cpp:947 (5)
//         004d00f3     MOV        EAX,0x1
//                              tact_hnt.cpp:948 (6)
//         004d00f8     POP        EDI
//         004d00f9     POP        ESI
//         004d00fa     POP        EBX
//         004d00fb     RET        0x10
//                               LAB_004d00fe                                                 XREF[3]:     004d009a(j), 004d00b6(j),
//                                                                                                         004d00c6(j)
//                              tact_hnt.cpp:931 (8)
//         004d00fe     MOV        EDI,dword ptr [ESI]
//         004d0100     PUSH       EBX
//         004d0101     MOV        this,ESI
//         004d0103     CALL       dword ptr [EDI + 0x54]
//                              tact_hnt.cpp:933 (7)
//         004d0106     PUSH       0x0
//         004d0108     MOV        this,ESI
//         004d010a     CALL       dword ptr [EDI + 0x58]
//                              tact_hnt.cpp:934 (2)
//         004d010d     PUSH       0x4
//                              tact_hnt.cpp:945 (5)
//         004d010f     MOV        this,ESI
//         004d0111     CALL       dword ptr [EDI + 0x5c]
//                              tact_hnt.cpp:947 (5)
//         004d0114     MOV        EAX,0x1
//                              tact_hnt.cpp:948 (6)
//         004d0119     POP        EDI
//         004d011a     POP        ESI
//         004d011b     POP        EBX
//         004d011c     RET        0x10
//                               LAB_004d011f                                                 XREF[1]:     004d008b(j)
//                              tact_hnt.cpp:943 (12)
//         004d011f     MOV        this,dword ptr [ESP + param_4]
//         004d0123     MOV        EDX,dword ptr [ESP + param_2]
//         004d0127     MOV        EAX,dword ptr [ESP + param_3]
//                              tact_hnt.cpp:944 (18)
//         004d012b     MOV        EDI,dword ptr [ESI]
//         004d012d     MOV        dword ptr [ESI + 0x28],this
//         004d0130     PUSH       0x0
//         004d0132     MOV        this,ESI
//         004d0134     MOV        dword ptr [ESI + 0x20],EDX
//         004d0137     MOV        dword ptr [ESI + 0x24],EAX
//         004d013a     CALL       dword ptr [EDI + 0x54]
//                              tact_hnt.cpp:945 (7)
//         004d013d     PUSH       0xf
//         004d013f     MOV        this,ESI
//         004d0141     CALL       dword ptr [EDI + 0x5c]
//                              tact_hnt.cpp:948 (11)
//         004d0144     POP        EDI
//         004d0145     POP        ESI
//         004d0146     MOV        EAX,0x1
//         004d014b     POP        EBX
//         004d014c     RET        0x10
//         004d014f     ??         90h
    return 0;
}

TRIBE_Action_Hunt::~TRIBE_Action_Hunt() {
    /* TODO: Stub */
//                              void __thiscall ~TRIBE_Action_Hunt(TRIBE_Action_Hunt * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Action_H    ECX:4 (auto)   this
//                               ??1TRIBE_Action_Hunt@@UAE@XZ                                 XREF[1]:     `scalar_deleting_destructor':004cf
//                               TRIBE_Action_Hunt::~TRIBE_Action_Hunt
//         004cf120     JMP        RGE_Action::~RGE_Action
//         004cf125     ??         90h
//         004cf126     NOP
//         004cf127     NOP
//         004cf128     NOP
//         004cf129     NOP
//         004cf12a     NOP
//         004cf12b     NOP
//         004cf12c     NOP
//         004cf12d     NOP
//         004cf12e     NOP
//         004cf12f     NOP
}

