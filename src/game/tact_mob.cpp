#include "../common.h"
#include "tact_mob.h"

TRIBE_Action_Make_Obj::TRIBE_Action_Make_Obj(int param_1, RGE_Action_Object* param_2) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Action_Make_Obj(TRIBE_Action_Make_Obj * t
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Action_M    ECX:4 (auto)   this
//              RGE_Action_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004d0eb0(R)
//              short             Stack[0x8]:2   param_2                   XREF[1]:     004d0ec7(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     004d0ec3(R)
//              uchar             Stack[0x10]:1  param_4                   XREF[1]:     004d0ebf(R)
//                               ??0TRIBE_Action_Make_Obj@@QAE@PAVRGE_Action_Object@@FHE@Z    XREF[2]:     update_production_queue:004c9f35(c
//                               TRIBE_Action_Make_Obj::TRIBE_Action_Make_Obj                              do_command_make:00509a21(c)
//                              tact_mob.cpp:48 (15)
//         004d0eb0     MOV        EAX,dword ptr [ESP + param_1]
//         004d0eb4     PUSH       ESI
//         004d0eb5     PUSH       0x1
//         004d0eb7     MOV        ESI,this
//         004d0eb9     PUSH       EAX
//         004d0eba     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, RGE_A
//                              tact_mob.cpp:53 (42)
//         004d0ebf     MOV        AL,byte ptr [ESP + param_4]
//         004d0ec3     MOV        this,dword ptr [ESP + param_3]
//         004d0ec7     MOV        DX,word ptr [ESP + param_2]
//         004d0ecc     MOV        byte ptr [ESI + 0x4c],AL
//         004d0ecf     MOV        dword ptr [ESI + 0x48],this
//         004d0ed2     MOV        dword ptr [ESI],TRIBE_Action_Make_Obj::`vftable' = 004d0e90
//         004d0ed8     MOV        word ptr [ESI + 0x4],0x66
//         004d0ede     MOV        word ptr [ESI + 0x40],DX
//         004d0ee2     MOV        dword ptr [ESI + 0x44],0x0
//                              tact_mob.cpp:54 (6)
//         004d0ee9     MOV        EAX,ESI
//         004d0eeb     POP        ESI
//         004d0eec     RET        0x10
//         004d0eef     ??         90h
}

TRIBE_Action_Make_Obj::TRIBE_Action_Make_Obj(RGE_Action_Object* param_1, short param_2, int param_3, uchar param_4) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Action_Make_Obj(TRIBE_Action_Make_Obj * t
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Action_M    ECX:4 (auto)   this
//              RGE_Action_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004d0eb0(R)
//              short             Stack[0x8]:2   param_2                   XREF[1]:     004d0ec7(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     004d0ec3(R)
//              uchar             Stack[0x10]:1  param_4                   XREF[1]:     004d0ebf(R)
//                               ??0TRIBE_Action_Make_Obj@@QAE@PAVRGE_Action_Object@@FHE@Z    XREF[2]:     update_production_queue:004c9f35(c
//                               TRIBE_Action_Make_Obj::TRIBE_Action_Make_Obj                              do_command_make:00509a21(c)
//                              tact_mob.cpp:48 (15)
//         004d0eb0     MOV        EAX,dword ptr [ESP + param_1]
//         004d0eb4     PUSH       ESI
//         004d0eb5     PUSH       0x1
//         004d0eb7     MOV        ESI,this
//         004d0eb9     PUSH       EAX
//         004d0eba     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, RGE_A
//                              tact_mob.cpp:53 (42)
//         004d0ebf     MOV        AL,byte ptr [ESP + param_4]
//         004d0ec3     MOV        this,dword ptr [ESP + param_3]
//         004d0ec7     MOV        DX,word ptr [ESP + param_2]
//         004d0ecc     MOV        byte ptr [ESI + 0x4c],AL
//         004d0ecf     MOV        dword ptr [ESI + 0x48],this
//         004d0ed2     MOV        dword ptr [ESI],TRIBE_Action_Make_Obj::`vftable' = 004d0e90
//         004d0ed8     MOV        word ptr [ESI + 0x4],0x66
//         004d0ede     MOV        word ptr [ESI + 0x40],DX
//         004d0ee2     MOV        dword ptr [ESI + 0x44],0x0
//                              tact_mob.cpp:54 (6)
//         004d0ee9     MOV        EAX,ESI
//         004d0eeb     POP        ESI
//         004d0eec     RET        0x10
//         004d0eef     ??         90h
}

TRIBE_Action_Make_Obj::~TRIBE_Action_Make_Obj() {
    /* TODO: Stub */
//                              void __thiscall ~TRIBE_Action_Make_Obj(TRIBE_Action_Make_Obj * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Action_M    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004d0f1b(W)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004d0f0a(W)
//                               ??1TRIBE_Action_Make_Obj@@UAE@XZ                             XREF[1]:     `vector_deleting_destructor':004d0
//                               TRIBE_Action_Make_Obj::~TRIBE_Action_Make_Obj
//                              tact_mob.cpp:60 (36)
//         004d0ef0     PUSH       -0x1
//         004d0ef2     PUSH       FUN_005600c8
//         004d0ef7     MOV        EAX,FS:[0x0]
//         004d0efd     PUSH       EAX
//         004d0efe     MOV        dword ptr FS:[0x0],ESP
//         004d0f05     PUSH       this
//         004d0f06     PUSH       ESI
//         004d0f07     MOV        ESI,this
//         004d0f09     PUSH       EDI
//         004d0f0a     MOV        dword ptr [ESP + local_10],ESI
//         004d0f0e     MOV        dword ptr [ESI],TRIBE_Action_Make_Obj::`vftable' = 004d0e90
//                              tact_mob.cpp:63 (53)
//         004d0f14     MOV        this,dword ptr [ESI + 0x8]
//         004d0f17     MOV        EDI,dword ptr [ESI + 0x48]
//         004d0f1a     PUSH       EDI
//         004d0f1b     MOV        dword ptr [ESP + local_4],0x0
//         004d0f23     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004d0f26     MOV        this,dword ptr [ECX + this->_padding_]
//         004d0f29     PUSH       this
//         004d0f2a     MOVSX      this,word ptr [ESI + 0x40]
//         004d0f2e     MOV        EDX,dword ptr [EAX]
//         004d0f30     PUSH       this
//         004d0f31     MOV        this,dword ptr [EAX + 0x3c]
//         004d0f34     MOV        this,dword ptr [ECX + this->_padding_]
//         004d0f37     PUSH       this
//         004d0f38     PUSH       s_WT=%ld,_MkObjDestructor:_obj_id=               = "WT=%ld, MkObjDestructor: obj_id=%d, obj->i
//         004d0f3d     PUSH       EAX
//         004d0f3e     CALL       dword ptr [EDX + 0xe4]
//         004d0f44     ADD        ESP,0x18
//         004d0f47     MOV        this,ESI
//                              tact_mob.cpp:65 (30)
//         004d0f49     MOV        dword ptr [ESP + 0x14],0xffffffff
//         004d0f51     CALL       RGE_Action::~RGE_Action                          void ~RGE_Action(RGE_Action * this)
//         004d0f56     MOV        this,dword ptr [ESP + 0xc]
//         004d0f5a     POP        EDI
//         004d0f5b     MOV        dword ptr FS:[0x0],this
//         004d0f62     POP        ESI
//         004d0f63     ADD        ESP,0x10
//         004d0f66     RET
//         004d0f67     ??         90h
//         004d0f68     NOP
//         004d0f69     NOP
//         004d0f6a     NOP
//         004d0f6b     NOP
//         004d0f6c     NOP
//         004d0f6d     NOP
//         004d0f6e     NOP
//         004d0f6f     NOP
}

void TRIBE_Action_Make_Obj::save(int param_1) {
    /* TODO: Stub */
//                              void __thiscall save(TRIBE_Action_Make_Obj * this, int param_1)
//              void              <VOID>         <RETURN>
//              TRIBE_Action_M    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004d0f72(R)
//                               ?save@TRIBE_Action_Make_Obj@@UAEXH@Z                         XREF[1]:     005751bc(*)
//                               TRIBE_Action_Make_Obj::save
//                              tact_mob.cpp:69 (2)
//         004d0f70     PUSH       ESI
//         004d0f71     PUSH       EDI
//                              tact_mob.cpp:70 (12)
//         004d0f72     MOV        EDI,dword ptr [ESP + param_1]
//         004d0f76     MOV        ESI,this
//         004d0f78     PUSH       EDI
//         004d0f79     CALL       RGE_Action::save                                 void save(RGE_Action * this, int param_1)
//                              tact_mob.cpp:72 (15)
//         004d0f7e     LEA        EAX,[ESI + 0x40]
//         004d0f81     PUSH       0x2
//         004d0f83     PUSH       EAX
//         004d0f84     PUSH       EDI
//         004d0f85     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004d0f8a     ADD        ESP,0xc
//                              tact_mob.cpp:73 (15)
//         004d0f8d     LEA        this,[ESI + 0x44]
//         004d0f90     PUSH       0x4
//         004d0f92     PUSH       this
//         004d0f93     PUSH       EDI
//         004d0f94     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004d0f99     ADD        ESP,0xc
//                              tact_mob.cpp:74 (15)
//         004d0f9c     LEA        EDX,[ESI + 0x48]
//         004d0f9f     PUSH       0x4
//         004d0fa1     PUSH       EDX
//         004d0fa2     PUSH       EDI
//         004d0fa3     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004d0fa8     ADD        ESP,0xc
//                              tact_mob.cpp:75 (15)
//         004d0fab     ADD        ESI,0x4c
//         004d0fae     PUSH       0x1
//         004d0fb0     PUSH       ESI
//         004d0fb1     PUSH       EDI
//         004d0fb2     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004d0fb7     ADD        ESP,0xc
//                              tact_mob.cpp:76 (5)
//         004d0fba     POP        EDI
//         004d0fbb     POP        ESI
//         004d0fbc     RET        0x4
//         004d0fbf     ??         90h
    return;
}

void TRIBE_Action_Make_Obj::first_in_stack(uchar param_1) {
    /* TODO: Stub */
//                              void __thiscall first_in_stack(TRIBE_Action_Make_Obj * this, uchar p
//              void              <VOID>         <RETURN>
//              TRIBE_Action_M    ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     004d0fc0(R)
//                               ?first_in_stack@TRIBE_Action_Make_Obj@@UAEXE@Z               XREF[1]:     005751c4(*)
//                               TRIBE_Action_Make_Obj::first_in_stack
//                              tact_mob.cpp:79 (17)
//         004d0fc0     MOV        AL,byte ptr [ESP + param_1]
//         004d0fc4     PUSH       EBX
//         004d0fc5     PUSH       ESI
//         004d0fc6     TEST       AL,AL
//         004d0fc8     PUSH       EDI
//         004d0fc9     MOV        ESI,this
//         004d0fcb     JZ         LAB_004d10da
//                              tact_mob.cpp:82 (9)
//         004d0fd1     MOV        DX,word ptr [ESI + 0x40]
//         004d0fd5     TEST       DX,DX
//         004d0fd8     JGE        LAB_004d0ffc
//                              tact_mob.cpp:86 (32)
//         004d0fda     MOV        EAX,dword ptr [ESI + 0x8]
//         004d0fdd     MOV        EBX,dword ptr [ESI + 0x48]
//         004d0fe0     MOVSX      EDX,DX
//         004d0fe3     MOV        this,dword ptr [EAX + 0xc]
//         004d0fe6     MOV        EAX,dword ptr [EAX + 0x4]
//         004d0fe9     PUSH       EBX
//         004d0fea     PUSH       EAX
//         004d0feb     MOV        EDI,dword ptr [this->_padding_]
//         004d0fed     PUSH       EDX
//         004d0fee     PUSH       s_Canceling_Train_#1a:__obj_id=%d,               = "Canceling Train #1a:  obj_id=%d, obj->id=%
//         004d0ff3     PUSH       this
//         004d0ff4     CALL       dword ptr [EDI + 0xe4]
//                              tact_mob.cpp:89 (2)
//         004d0ffa     JMP        LAB_004d1025
//                               LAB_004d0ffc                                                 XREF[1]:     004d0fd8(j)
//                              tact_mob.cpp:93 (18)
//         004d0ffc     MOV        EDI,dword ptr [ESI + 0x8]
//         004d0fff     MOVSX      EAX,DX
//         004d1002     MOV        this,dword ptr [EDI + 0xc]
//         004d1005     MOV        EBX,dword ptr [ECX + this->_padding_]
//         004d1008     CMP        dword ptr [EBX + EAX*0x4],0x0
//         004d100c     JNZ        LAB_004d104b
//                              tact_mob.cpp:97 (23)
//         004d100e     MOV        EBX,dword ptr [ESI + 0x48]
//         004d1011     MOV        EDI,dword ptr [EDI + 0x4]
//         004d1014     MOV        EDX,dword ptr [this->_padding_]
//         004d1016     PUSH       EBX
//         004d1017     PUSH       EDI
//         004d1018     PUSH       EAX
//         004d1019     PUSH       s_Canceling_Train_#1b:__obj_id=%d,               = "Canceling Train #1b:  obj_id=%d, obj->id=%
//         004d101e     PUSH       this
//         004d101f     CALL       dword ptr [EDX + 0xe4]
//                               LAB_004d1025                                                 XREF[1]:     004d0ffa(j)
//                              tact_mob.cpp:99 (32)
//         004d1025     MOV        EAX,dword ptr [ESI + 0x8]
//         004d1028     MOV        EDI,dword ptr [ESI + 0x48]
//         004d102b     ADD        ESP,0x14
//         004d102e     MOV        this,dword ptr [EAX + 0xc]
//         004d1031     MOV        EAX,dword ptr [EAX + 0x4]
//         004d1034     PUSH       EDI
//         004d1035     PUSH       EAX
//         004d1036     MOVSX      EAX,word ptr [ESI + 0x40]
//         004d103a     MOV        EDX,dword ptr [this->_padding_]
//         004d103c     PUSH       EAX
//         004d103d     PUSH       0x0
//         004d103f     CALL       dword ptr [EDX + 0x10c]
//                              tact_mob.cpp:116 (6)
//         004d1045     POP        EDI
//         004d1046     POP        ESI
//         004d1047     POP        EBX
//         004d1048     RET        0x4
//                               LAB_004d104b                                                 XREF[1]:     004d100c(j)
//                              tact_mob.cpp:103 (24)
//         004d104b     MOV        AL,byte ptr [ESI + 0x4c]
//         004d104e     TEST       AL,AL
//         004d1050     JNZ        LAB_004d10d1
//         004d1052     PUSH       0x0
//         004d1054     PUSH       0x3f800000
//         004d1059     PUSH       EDX
//         004d105a     CALL       TRIBE_Player::pay_obj_cost                       uchar pay_obj_cost(TRIBE_Player * this, short
//         004d105f     TEST       AL,AL
//         004d1061     JNZ        LAB_004d10d1
//                              tact_mob.cpp:109 (33)
//         004d1063     MOV        EAX,dword ptr [ESI + 0x8]
//         004d1066     MOV        EDI,dword ptr [ESI + 0x48]
//         004d1069     PUSH       EDI
//         004d106a     MOV        this,dword ptr [EAX + 0xc]
//         004d106d     MOV        EAX,dword ptr [EAX + 0x4]
//         004d1070     PUSH       EAX
//         004d1071     MOVSX      EAX,word ptr [ESI + 0x40]
//         004d1075     MOV        EDX,dword ptr [this->_padding_]
//         004d1077     PUSH       EAX
//         004d1078     PUSH       s_Canceling_Train_#1c:__obj_id=%d,               = "Canceling Train #1c:  obj_id=%d, obj->id=%
//         004d107d     PUSH       this
//         004d107e     CALL       dword ptr [EDX + 0xe4]
//                              tact_mob.cpp:111 (32)
//         004d1084     MOV        EAX,dword ptr [ESI + 0x8]
//         004d1087     MOV        EDI,dword ptr [ESI + 0x48]
//         004d108a     ADD        ESP,0x14
//         004d108d     MOV        this,dword ptr [EAX + 0xc]
//         004d1090     MOV        EAX,dword ptr [EAX + 0x4]
//         004d1093     PUSH       EDI
//         004d1094     PUSH       EAX
//         004d1095     MOVSX      EAX,word ptr [ESI + 0x40]
//         004d1099     MOV        EDX,dword ptr [this->_padding_]
//         004d109b     PUSH       EAX
//         004d109c     PUSH       0x0
//         004d109e     CALL       dword ptr [EDX + 0x10c]
//                              tact_mob.cpp:112 (30)
//         004d10a4     MOV        this,dword ptr [ESI + 0x8]
//         004d10a7     PUSH       0x0
//         004d10a9     PUSH       0x0=>DAT_fffffff8
//         004d10ab     PUSH       offset DAT_fffffff4
//         004d10b0     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004d10b3     MOV        EDX,dword ptr [this->_padding_]
//         004d10b5     PUSH       offset DAT_fffffff0
//         004d10ba     PUSH       EAX
//         004d10bb     PUSH       EAX
//         004d10bc     CALL       dword ptr [EDX + 0x148]
//                              tact_mob.cpp:113 (9)
//         004d10c2     MOV        EAX,dword ptr [ESI]
//         004d10c4     PUSH       0x1
//         004d10c6     MOV        this,ESI
//         004d10c8     CALL       dword ptr [EAX + 0x5c]
//                              tact_mob.cpp:116 (6)
//         004d10cb     POP        EDI
//         004d10cc     POP        ESI
//         004d10cd     POP        EBX
//         004d10ce     RET        0x4
//                               LAB_004d10d1                                                 XREF[2]:     004d1050(j), 004d1061(j)
//                              tact_mob.cpp:104 (9)
//         004d10d1     MOV        EDX,dword ptr [ESI]
//         004d10d3     PUSH       0x6
//         004d10d5     MOV        this,ESI
//         004d10d7     CALL       dword ptr [EDX + 0x5c]
//                               LAB_004d10da                                                 XREF[1]:     004d0fcb(j)
//                              tact_mob.cpp:116 (6)
//         004d10da     POP        EDI
//         004d10db     POP        ESI
//         004d10dc     POP        EBX
//         004d10dd     RET        0x4
    return;
}

void TRIBE_Action_Make_Obj::set_state(uchar param_1) {
    /* TODO: Stub */
//                              void __thiscall set_state(TRIBE_Action_Make_Obj * this, uchar param_1)
//              void              <VOID>         <RETURN>
//              TRIBE_Action_M    ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     004d10e0(R)
//                               ?set_state@TRIBE_Action_Make_Obj@@MAEXE@Z                    XREF[1]:     00575204(*)
//                               TRIBE_Action_Make_Obj::set_state
//                              tact_mob.cpp:120 (7)
//         004d10e0     MOV        AL,byte ptr [ESP + param_1]
//         004d10e4     MOV        byte ptr [ECX + this->_padding_],AL
//                              tact_mob.cpp:123 (3)
//         004d10e7     RET        0x4
//         004d10ea     ??         90h
//         004d10eb     NOP
//         004d10ec     NOP
//         004d10ed     NOP
//         004d10ee     NOP
//         004d10ef     NOP
    return;
}

uchar TRIBE_Action_Make_Obj::update() {
    /* TODO: Stub */
//                              uchar __thiscall update(TRIBE_Action_Make_Obj * this)
//              uchar             AL:1           <RETURN>
//              TRIBE_Action_M    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004d1159(W), 004d115d(R)
//              RGE_Static_Obj    Stack[-0x8]:4  newObject
//                               ?update@TRIBE_Action_Make_Obj@@UAEEXZ                        XREF[1]:     005751d0(*)
//                               TRIBE_Action_Make_Obj::update
//                              tact_mob.cpp:126 (6)
//         004d10f0     PUSH       this
//         004d10f1     PUSH       EBX
//         004d10f2     PUSH       EBP
//         004d10f3     PUSH       ESI
//         004d10f4     MOV        ESI,this
//                              tact_mob.cpp:127 (22)
//         004d10f6     XOR        EAX,EAX
//         004d10f8     PUSH       EDI
//         004d10f9     MOV        AL,byte ptr [ESI + 0xc]
//         004d10fc     DEC        EAX
//         004d10fd     JZ         LAB_004d12a6
//         004d1103     SUB        EAX,0x5
//         004d1106     JNZ        LAB_004d129e
//                              tact_mob.cpp:129 (15)
//         004d110c     MOV        EAX,[rge_base_game]                              = 00000000
//         004d1111     MOV        this,dword ptr [EAX + 0x9a8]
//         004d1117     TEST       this,this
//         004d1119     JZ         LAB_004d1124
//                              tact_mob.cpp:130 (7)
//         004d111b     MOV        dword ptr [ESI + 0x44],0x447a0000
//                              tact_mob.cpp:131 (2)
//         004d1122     JMP        LAB_004d1142
//                               LAB_004d1124                                                 XREF[1]:     004d1119(j)
//                              tact_mob.cpp:132 (30)
//         004d1124     MOV        EAX,dword ptr [ESI + 0x8]
//         004d1127     MOV        EDX,dword ptr [EAX + 0xc]
//         004d112a     MOV        this,dword ptr [EAX + 0x8]
//         004d112d     MOV        EAX,dword ptr [EDX + 0x3c]
//         004d1130     FLD        float ptr [this->_padding_ + 0xe4]
//         004d1136     FMUL       float ptr [EAX + 0x84]
//         004d113c     FADD       float ptr [ESI + 0x44]
//         004d113f     FSTP       float ptr [ESI + 0x44]
//                               LAB_004d1142                                                 XREF[1]:     004d1122(j)
//                              tact_mob.cpp:133 (45)
//         004d1142     MOV        EDX,dword ptr [ESI + 0x8]
//         004d1145     MOVSX      this,word ptr [ESI + 0x40]
//         004d1149     MOV        EAX,dword ptr [EDX + 0xc]
//         004d114c     MOV        EDX,dword ptr [EAX + 0x24]
//         004d114f     MOV        EAX,dword ptr [EDX + this->_padding_*0x4]
//         004d1152     MOVSX      this,word ptr [EAX + 0x15a]
//         004d1159     MOV        dword ptr [ESP + local_4],this
//         004d115d     FILD       dword ptr [ESP + local_4]
//         004d1161     FCOMP      float ptr [ESI + 0x44]
//         004d1164     FNSTSW     AX
//         004d1166     TEST       AH,0x41
//         004d1169     JZ         LAB_004d129e
//                              tact_mob.cpp:136 (9)
//         004d116f     MOV        EDX,dword ptr [ESI]
//         004d1171     PUSH       0x1
//         004d1173     MOV        this,ESI
//         004d1175     CALL       dword ptr [EDX + 0x5c]
//                              tact_mob.cpp:140 (20)
//         004d1178     LEA        EAX,[ESP + 0x10]
//         004d117c     MOV        this,ESI
//         004d117e     PUSH       EAX
//         004d117f     CALL       TRIBE_Action_Make_Obj::place_obj                 uchar place_obj(TRIBE_Action_Make_Obj * this,
//         004d1184     TEST       AL,AL
//         004d1186     JNZ        LAB_004d1224
//                              tact_mob.cpp:143 (16)
//         004d118c     MOV        this,word ptr [ESI + 0x40]
//         004d1190     MOV        EDX,dword ptr [ESI + 0x8]
//         004d1193     PUSH       this
//         004d1194     MOV        this,dword ptr [EDX + 0xc]
//         004d1197     CALL       TRIBE_Player::reimburse_obj_cost                 void reimburse_obj_cost(TRIBE_Player * this,
//                              tact_mob.cpp:144 (33)
//         004d119c     MOVSX      EDX,word ptr [ESI + 0x40]
//         004d11a0     PUSH       0x0
//         004d11a2     PUSH       0x0=>DAT_fffffff8
//         004d11a4     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004d11aa     PUSH       EDX=>DAT_fffffff4
//         004d11ab     MOV        EDX,dword ptr [ESI + 0x8]
//         004d11ae     MOV        EAX,dword ptr [this->_padding_]
//         004d11b0     MOV        EDX,dword ptr [EDX + 0xc]
//         004d11b3     MOVSX      EDX,word ptr [EDX + 0x4a]
//         004d11b7     PUSH       EDX=>DAT_fffffff0
//                              language.dll match for 0x68: "Arial"
//         004d11b8     PUSH       0x68
//         004d11ba     CALL       dword ptr [EAX + 0x40]
//                              tact_mob.cpp:146 (33)
//         004d11bd     MOV        EAX,dword ptr [ESI + 0x8]
//         004d11c0     MOV        EDI,dword ptr [ESI + 0x48]
//         004d11c3     PUSH       EDI
//         004d11c4     MOV        this,dword ptr [EAX + 0xc]
//         004d11c7     MOV        EAX,dword ptr [EAX + 0x4]
//         004d11ca     PUSH       EAX=>DAT_fffffff8
//         004d11cb     MOVSX      EAX,word ptr [ESI + 0x40]
//         004d11cf     MOV        EDX,dword ptr [this->_padding_]
//         004d11d1     PUSH       EAX=>DAT_fffffff4
//         004d11d2     PUSH       s_Canceling_Train_#2:__obj_id=%d,_               = "Canceling Train #2:  obj_id=%d, obj->id=%d
//         004d11d7     PUSH       this
//         004d11d8     CALL       dword ptr [EDX + 0xe4]
//                              tact_mob.cpp:148 (32)
//         004d11de     MOV        EAX,dword ptr [ESI + 0x8]
//         004d11e1     MOV        EDI,dword ptr [ESI + 0x48]
//         004d11e4     ADD        ESP,0x14
//         004d11e7     MOV        this,dword ptr [EAX + 0xc]
//         004d11ea     MOV        EAX,dword ptr [EAX + 0x4]
//         004d11ed     PUSH       EDI
//         004d11ee     PUSH       EAX
//         004d11ef     MOVSX      EAX,word ptr [ESI + 0x40]
//         004d11f3     MOV        EDX,dword ptr [this->_padding_]
//         004d11f5     PUSH       EAX
//         004d11f6     PUSH       0x0
//         004d11f8     CALL       dword ptr [EDX + 0x10c]
//                              tact_mob.cpp:149 (22)
//         004d11fe     MOV        this,dword ptr [ESI + 0x8]
//         004d1201     PUSH       0x0
//         004d1203     PUSH       0x0=>DAT_fffffff8
//         004d1205     PUSH       offset DAT_fffffff4
//         004d120a     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004d120d     MOV        EDX,dword ptr [this->_padding_]
//         004d120f     PUSH       offset DAT_fffffff0
//                              tact_mob.cpp:155 (8)
//         004d1214     PUSH       EAX
//         004d1215     PUSH       EAX
//         004d1216     CALL       dword ptr [EDX + 0x148]
//                              tact_mob.cpp:163 (2)
//         004d121c     MOV        AL,0x1
//                              tact_mob.cpp:167 (6)
//         004d121e     POP        EDI
//         004d121f     POP        ESI
//         004d1220     POP        EBP
//         004d1221     POP        EBX
//         004d1222     POP        this
//         004d1223     RET
//                               LAB_004d1224                                                 XREF[1]:     004d1186(j)
//                              tact_mob.cpp:152 (49)
//         004d1224     MOV        EDI,dword ptr [ESI + 0x8]
//         004d1227     MOV        EBX,dword ptr [rge_base_game]                    = 00000000
//         004d122d     FLD        float ptr [EDI + 0x3c]
//         004d1230     MOV        EBP,dword ptr [EBX]
//         004d1232     CALL       __ftol                                           undefined __ftol()
//         004d1237     FLD        float ptr [EDI + 0x38]
//         004d123a     PUSH       EAX
//         004d123b     CALL       __ftol                                           undefined __ftol()
//         004d1240     MOV        this,dword ptr [EDI + 0xc]
//         004d1243     PUSH       EAX=>DAT_fffffff8
//         004d1244     MOVSX      EAX,word ptr [ESI + 0x40]
//         004d1248     MOVSX      EDX,word ptr [ECX + this+0x4a]
//         004d124c     PUSH       EAX=>DAT_fffffff4
//         004d124d     PUSH       EDX=>DAT_fffffff0
//                              language.dll match for 0x66: "Copperplate Gothic Light"
//         004d124e     PUSH       0x66
//         004d1250     MOV        this,EBX
//         004d1252     CALL       dword ptr [EBP + 0x40]
//                              tact_mob.cpp:154 (35)
//         004d1255     MOV        EDI,dword ptr [ESP + 0x10]
//         004d1259     MOV        EAX,dword ptr [ESI + 0x8]
//         004d125c     MOV        EDI,dword ptr [EDI + 0x4]
//         004d125f     MOV        this,dword ptr [EAX + 0xc]
//         004d1262     MOV        EAX,dword ptr [EAX + 0x4]
//         004d1265     PUSH       EDI
//         004d1266     MOV        EDI,dword ptr [ESI + 0x48]
//         004d1269     MOV        EDX,dword ptr [this->_padding_]
//         004d126b     PUSH       EDI=>DAT_fffffff8
//         004d126c     PUSH       EAX=>DAT_fffffff4
//         004d126d     MOVSX      EAX,word ptr [ESI + 0x40]
//         004d1271     PUSH       EAX=>DAT_fffffff0
//         004d1272     CALL       dword ptr [EDX + 0x110]
//                              tact_mob.cpp:155 (30)
//         004d1278     MOV        this,dword ptr [ESI + 0x8]
//         004d127b     PUSH       0x0
//         004d127d     PUSH       0x0=>DAT_fffffff8
//         004d127f     PUSH       offset DAT_fffffff4
//         004d1284     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004d1287     MOV        EDX,dword ptr [this->_padding_]
//         004d1289     PUSH       offset DAT_fffffff0
//         004d128e     PUSH       EAX
//         004d128f     PUSH       EAX
//         004d1290     CALL       dword ptr [EDX + 0x148]
//                              tact_mob.cpp:163 (2)
//         004d1296     MOV        AL,0x1
//                              tact_mob.cpp:167 (6)
//         004d1298     POP        EDI
//         004d1299     POP        ESI
//         004d129a     POP        EBP
//         004d129b     POP        EBX
//         004d129c     POP        this
//         004d129d     RET
//                               LAB_004d129e                                                 XREF[2]:     004d1106(j), 004d1169(j)
//                              tact_mob.cpp:166 (2)
//         004d129e     XOR        AL,AL
//                              tact_mob.cpp:167 (14)
//         004d12a0     POP        EDI
//         004d12a1     POP        ESI
//         004d12a2     POP        EBP
//         004d12a3     POP        EBX
//         004d12a4     POP        this
//         004d12a5     RET
//                               LAB_004d12a6                                                 XREF[1]:     004d10fd(j)
//         004d12a6     POP        EDI
//         004d12a7     POP        ESI
//         004d12a8     POP        EBP
//         004d12a9     MOV        AL,0x1
//         004d12ab     POP        EBX
//         004d12ac     POP        this
//         004d12ad     RET
//         004d12ae     ??         90h
//         004d12af     NOP
    return 0;
}

uchar TRIBE_Action_Make_Obj::place_obj(RGE_Static_Object** param_1) {
    /* TODO: Stub */
//                              uchar __thiscall place_obj(TRIBE_Action_Make_Obj * this, RGE_Static_
//              uchar             AL:1           <RETURN>
//              TRIBE_Action_M    ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004d143e(W), 004d1445(R)
//              undefined4        Stack[-0x8]:4  local_8                   XREF[1]:     004d12b9(W)
//              short             Stack[-0xc]:2  index                     XREF[1]:     004d1301(W)
//              float             Stack[-0x10]:4 radius_2y                 XREF[2]:     004d12eb(W), 004d1449(R)
//              float             Stack[-0x14]:4 radius_2x                 XREF[2]:     004d12fb(W), 004d1432(R)
//              float             Stack[-0x18]:4 radius_y                  XREF[2]:     004d12e5(W), 004d1456(R)
//              float             Stack[-0x1c]:4 radius_x
//                               ?place_obj@TRIBE_Action_Make_Obj@@IAEEPAPAVRGE_Static_Objec  XREF[1]:     update:004d117f(c)
//                               TRIBE_Action_Make_Obj::place_obj
//                              tact_mob.cpp:171 (9)
//         004d12b0     SUB        ESP,0x18
//         004d12b3     PUSH       EBX
//         004d12b4     PUSH       EBP
//         004d12b5     PUSH       ESI
//         004d12b6     MOV        ESI,this
//         004d12b8     PUSH       EDI
//                              tact_mob.cpp:187 (33)
//         004d12b9     MOV        dword ptr [ESP + local_8],0x0
//         004d12c1     MOV        EAX,dword ptr [ESI + 0x8]
//         004d12c4     MOVSX      EDX,word ptr [ESI + 0x40]
//         004d12c8     MOV        this,dword ptr [EAX + 0xc]
//         004d12cb     MOV        EAX,dword ptr [EAX + 0x8]
//         004d12ce     MOV        this,dword ptr [ECX + this->_padding_]
//         004d12d1     FLD        float ptr [EAX + 0x30]
//         004d12d4     MOV        EDI,dword ptr [this->_padding_ + EDX*0x4]
//         004d12d7     FADD       float ptr [EDI + 0x30]
//                              tact_mob.cpp:220 (43)
//         004d12da     MOV        EDX,dword ptr [EDI]
//         004d12dc     FSUB       float ptr [DAT_00575190]                         = 0Ah
//         004d12e2     MOV        EBP,dword ptr [EDX + 0x20]
//         004d12e5     FST        float ptr [ESP + radius_y]
//         004d12e9     FADD       ST0,ST0
//         004d12eb     FSTP       float ptr [ESP + radius_2y]
//         004d12ef     FLD        float ptr [EAX + 0x34]
//         004d12f2     FADD       float ptr [EDI + 0x34]
//         004d12f5     FSUB       float ptr [DAT_00575190]                         = 0Ah
//         004d12fb     FST        float ptr [ESP + radius_2x]
//         004d12ff     FADD       ST0,ST0
//         004d1301     FSTP       float ptr [ESP + index]
//                               LAB_004d1305                                                 XREF[1]:     004d14ed(j)
//                              tact_mob.cpp:189 (2)
//         004d1305     XOR        EBX,EBX
//                               LAB_004d1307                                                 XREF[1]:     004d148a(j)
//                              tact_mob.cpp:191 (6)
//         004d1307     CMP        BX,0x28
//         004d130b     JGE        LAB_004d1338
//                              tact_mob.cpp:192 (41)
//         004d130d     PUSH       0xc0
//         004d1312     PUSH       s_C:\msdev\work\age1_x1\tact_mob.c               = "C:\\msdev\\work\\age1_x1\\tact_mob.cpp"
//         004d1317     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         004d131c     MOV        this,EAX
//         004d131e     MOV        EAX,0x80010003
//         004d1323     SHL        this,0x1
//         004d1325     IMUL       this
//         004d1327     ADD        EDX,this
//         004d1329     ADD        ESP,0x8
//         004d132c     SAR        EDX,0xe
//         004d132f     MOV        EAX,EDX
//         004d1331     SHR        EAX,0x1f
//         004d1334     ADD        EDX,EAX
//                              tact_mob.cpp:193 (2)
//         004d1336     JMP        LAB_004d1363
//                               LAB_004d1338                                                 XREF[1]:     004d130b(j)
//                              tact_mob.cpp:194 (43)
//         004d1338     PUSH       0xc2
//         004d133d     PUSH       s_C:\msdev\work\age1_x1\tact_mob.c               = "C:\\msdev\\work\\age1_x1\\tact_mob.cpp"
//         004d1342     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         004d1347     MOV        this,EAX
//         004d1349     MOV        EAX,0x80010003
//         004d134e     SHL        this,0x1
//         004d1350     IMUL       this
//         004d1352     ADD        EDX,this
//         004d1354     ADD        ESP,0x8
//         004d1357     SAR        EDX,0xe
//         004d135a     MOV        this,EDX
//         004d135c     SHR        this,0x1f
//         004d135f     LEA        EDX,[EDX + this->_padding_*0x1 + 0x2]
//                               LAB_004d1363                                                 XREF[1]:     004d1336(j)
//                              tact_mob.cpp:195 (19)
//         004d1363     MOVSX      EAX,DX
//         004d1366     CMP        EAX,0x3
//         004d1369     JA         switchD_004d136f::default
//                               switchD_004d136f::switchD
//         004d136f     JMP        dword ptr [EAX*0x4 + switchD_004d136f::switchd   = 004d1376
//                               switchD_004d136f::caseD_0                                    XREF[2]:     004d136f(j), 004d1534(*)
//                              tact_mob.cpp:198 (3)
//         004d1376     MOV        EDX,dword ptr [ESI + 0x8]
//                              tact_mob.cpp:199 (36)
//         004d1379     PUSH       0xc7
//         004d137e     PUSH       s_C:\msdev\work\age1_x1\tact_mob.c               = "C:\\msdev\\work\\age1_x1\\tact_mob.cpp"
//         004d1383     FLD        float ptr [EDX + 0x3c]
//         004d1386     FADD       float ptr [ESP + 0x1c]
//         004d138a     FSTP       float ptr [ESI + 0x24]
//         004d138d     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         004d1392     MOV        dword ptr [ESP + 0x2c],EAX
//         004d1396     MOV        EAX,dword ptr [ESI + 0x8]
//         004d1399     FILD       dword ptr [ESP + 0x2c]
//                              tact_mob.cpp:200 (5)
//         004d139d     JMP        LAB_004d1449
//                               switchD_004d136f::caseD_1                                    XREF[2]:     004d136f(j), 004d1538(*)
//                              tact_mob.cpp:202 (3)
//         004d13a2     MOV        this,dword ptr [ESI + 0x8]
//                              tact_mob.cpp:203 (59)
//         004d13a5     PUSH       0xcb
//         004d13aa     PUSH       s_C:\msdev\work\age1_x1\tact_mob.c               = "C:\\msdev\\work\\age1_x1\\tact_mob.cpp"
//         004d13af     FLD        float ptr [ECX + this->_padding_]
//         004d13b2     FSUB       float ptr [ESP + 0x18]
//         004d13b6     FSTP       float ptr [ESI + 0x20]
//         004d13b9     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         004d13be     MOV        dword ptr [ESP + 0x2c],EAX
//         004d13c2     MOV        EDX,dword ptr [ESI + 0x8]
//         004d13c5     FILD       dword ptr [ESP + 0x2c]
//         004d13c9     ADD        ESP,0x8
//         004d13cc     FMUL       float ptr [ESP + 0x1c]
//         004d13d0     FMUL       float ptr [DAT_00575198]
//         004d13d6     FSUB       float ptr [ESP + 0x14]
//         004d13da     FADD       float ptr [EDX + 0x3c]
//         004d13dd     FSTP       float ptr [ESI + 0x24]
//                              tact_mob.cpp:204 (2)
//         004d13e0     JMP        switchD_004d136f::default
//                               switchD_004d136f::caseD_2                                    XREF[2]:     004d136f(j), 004d153c(*)
//                              tact_mob.cpp:206 (3)
//         004d13e2     MOV        EAX,dword ptr [ESI + 0x8]
//                              tact_mob.cpp:207 (59)
//         004d13e5     PUSH       0xcf
//         004d13ea     PUSH       s_C:\msdev\work\age1_x1\tact_mob.c               = "C:\\msdev\\work\\age1_x1\\tact_mob.cpp"
//         004d13ef     FLD        float ptr [EAX + 0x38]
//         004d13f2     FADD       float ptr [ESP + 0x18]
//         004d13f6     FSTP       float ptr [ESI + 0x20]
//         004d13f9     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         004d13fe     MOV        dword ptr [ESP + 0x2c],EAX
//         004d1402     MOV        this,dword ptr [ESI + 0x8]
//         004d1405     FILD       dword ptr [ESP + 0x2c]
//         004d1409     ADD        ESP,0x8
//         004d140c     FMUL       float ptr [ESP + 0x1c]
//         004d1410     FMUL       float ptr [DAT_00575198]
//         004d1416     FSUB       float ptr [ESP + 0x14]
//         004d141a     FADD       float ptr [ECX + this->_padding_]
//         004d141d     FSTP       float ptr [ESI + 0x24]
//                              tact_mob.cpp:208 (2)
//         004d1420     JMP        switchD_004d136f::default
//                               switchD_004d136f::caseD_3                                    XREF[2]:     004d136f(j), 004d1540(*)
//                              tact_mob.cpp:210 (3)
//         004d1422     MOV        EDX,dword ptr [ESI + 0x8]
//                              tact_mob.cpp:211 (59)
//         004d1425     PUSH       0xd3
//         004d142a     PUSH       s_C:\msdev\work\age1_x1\tact_mob.c               = "C:\\msdev\\work\\age1_x1\\tact_mob.cpp"
//         004d142f     FLD        float ptr [EDX + 0x3c]
//         004d1432     FSUB       float ptr [ESP + radius_2x]
//         004d1436     FSTP       float ptr [ESI + 0x24]
//         004d1439     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         004d143e     MOV        dword ptr [ESP + local_4],EAX
//         004d1442     MOV        EAX,dword ptr [ESI + 0x8]
//         004d1445     FILD       dword ptr [ESP + local_4]
//                               LAB_004d1449                                                 XREF[1]:     004d139d(j)
//         004d1449     FMUL       float ptr [ESP + radius_2y]
//         004d144d     ADD        ESP,0x8
//         004d1450     FMUL       float ptr [DAT_00575198]
//         004d1456     FSUB       float ptr [ESP + radius_y]
//         004d145a     FADD       float ptr [EAX + 0x38]
//         004d145d     FSTP       float ptr [ESI + 0x20]
//                               switchD_004d136f::default                                    XREF[3]:     004d1369(j), 004d13e0(j),
//                                                                                                         004d1420(j)
//                              tact_mob.cpp:220 (48)
//         004d1460     MOV        this,dword ptr [ESI + 0x24]
//         004d1463     MOV        EAX,dword ptr [ESI + 0x8]
//         004d1466     MOV        EDX,dword ptr [ESI + 0x20]
//         004d1469     PUSH       0x1
//         004d146b     PUSH       0x0=>DAT_fffffff8
//         004d146d     PUSH       0x0=>DAT_fffffff4
//         004d146f     PUSH       offset DAT_fffffff0
//         004d1471     PUSH       0x1
//         004d1473     PUSH       0x1
//         004d1475     PUSH       0x0
//         004d1477     PUSH       this
//         004d1478     MOV        this,dword ptr [EAX + 0xc]
//         004d147b     PUSH       EDX
//         004d147c     PUSH       this
//         004d147d     MOV        this,EDI
//         004d147f     CALL       EBP
//         004d1481     TEST       AL,AL
//         004d1483     JZ         LAB_004d14ff
//         004d1485     INC        EBX
//         004d1486     CMP        BX,0x3c
//         004d148a     JL         LAB_004d1307
//                              tact_mob.cpp:226 (3)
//         004d1490     FLD        float ptr [EDI + 0x30]
//                              tact_mob.cpp:227 (3)
//         004d1493     FLD        float ptr [EDI + 0x34]
//                              tact_mob.cpp:228 (3)
//         004d1496     FLD        float ptr [EDI + 0x30]
//                              tact_mob.cpp:229 (90)
//         004d1499     FLD        float ptr [EDI + 0x34]
//         004d149c     FXCH       ST3
//         004d149e     FADD       ST0,ST0
//         004d14a0     FXCH       ST2
//         004d14a2     FADD       ST0,ST0
//         004d14a4     FXCH
//         004d14a6     FMUL       float ptr [DAT_0057519c]
//         004d14ac     FXCH       ST2
//         004d14ae     FADD       float ptr [ESP + 0x10]
//         004d14b2     FXCH       ST3
//         004d14b4     FMUL       float ptr [DAT_0057519c]
//         004d14ba     FXCH
//         004d14bc     FADD       float ptr [ESP + 0x14]
//         004d14c0     FXCH       ST2
//         004d14c2     FADD       float ptr [ESP + 0x18]
//         004d14c6     FXCH
//         004d14c8     FADD       float ptr [ESP + 0x1c]
//         004d14cc     FXCH       ST3
//         004d14ce     FSTP       float ptr [ESP + 0x10]
//         004d14d2     MOV        EAX,dword ptr [ESP + 0x20]
//         004d14d6     FXCH
//         004d14d8     FSTP       float ptr [ESP + 0x14]
//         004d14dc     INC        EAX
//         004d14dd     FSTP       float ptr [ESP + 0x18]
//         004d14e1     CMP        AX,0x3
//         004d14e5     MOV        dword ptr [ESP + 0x20],EAX
//         004d14e9     FSTP       float ptr [ESP + 0x1c]
//         004d14ed     JL         LAB_004d1305
//                              tact_mob.cpp:232 (2)
//         004d14f3     XOR        AL,AL
//                              tact_mob.cpp:233 (10)
//         004d14f5     POP        EDI
//         004d14f6     POP        ESI
//         004d14f7     POP        EBP
//         004d14f8     POP        EBX
//         004d14f9     ADD        ESP,0x18
//         004d14fc     RET        0x4
//                               LAB_004d14ff                                                 XREF[1]:     004d1483(j)
//                              tact_mob.cpp:222 (40)
//         004d14ff     MOV        EAX,dword ptr [ESI + 0x8]
//         004d1502     MOVSX      this,word ptr [ESI + 0x40]
//         004d1506     MOV        EDX,dword ptr [EAX + 0xc]
//         004d1509     MOV        EAX,dword ptr [EAX + 0x40]
//         004d150c     PUSH       EAX
//         004d150d     MOV        EAX,dword ptr [ESI + 0x24]
//         004d1510     MOV        EDI,dword ptr [EDX + 0x24]
//         004d1513     PUSH       EAX=>DAT_fffffff8
//         004d1514     MOV        EAX,dword ptr [ESI + 0x20]
//         004d1517     MOV        this,dword ptr [EDI + this->_padding_*0x4]
//         004d151a     PUSH       EAX=>DAT_fffffff4
//         004d151b     PUSH       EDX=>DAT_fffffff0
//         004d151c     MOV        EDI,dword ptr [this->_padding_]
//         004d151e     CALL       dword ptr [EDI + 0x18]
//         004d1521     MOV        this,dword ptr [ESP + 0x2c]
//         004d1525     MOV        dword ptr [this->_padding_],EAX
//                              tact_mob.cpp:223 (2)
//         004d1527     MOV        AL,0x1
//                              tact_mob.cpp:233 (27)
//         004d1529     POP        EDI
//         004d152a     POP        ESI
//         004d152b     POP        EBP
//         004d152c     POP        EBX
//         004d152d     ADD        ESP,0x18
//         004d1530     RET        0x4
//         004d1533     ??         90h
//                              Symbol Ref: No symbol: NONAME
//                               switchD_004d136f::switchdataD_004d1534                       XREF[1]:     place_obj:004d136f(*)
//         004d1534     addr       switchD_004d136f::caseD_0
//         004d1538     addr       switchD_004d136f::caseD_1
//         004d153c     addr       switchD_004d136f::caseD_2
//         004d1540     addr       switchD_004d136f::caseD_3
//         004d1544     ??         90h
//         004d1545     ??         90h
//         004d1546     ??         90h
//         004d1547     ??         90h
//         004d1548     ??         90h
//         004d1549     ??         90h
//         004d154a     ??         90h
//         004d154b     ??         90h
//         004d154c     ??         90h
//         004d154d     ??         90h
//         004d154e     ??         90h
//         004d154f     ??         90h
    return 0;
}

int TRIBE_Action_Make_Obj::stop() {
    /* TODO: Stub */
//                              int __thiscall stop(TRIBE_Action_Make_Obj * this)
//              int               EAX:4          <RETURN>
//              TRIBE_Action_M    ECX:4 (auto)   this
//                               ?stop@TRIBE_Action_Make_Obj@@UAEHXZ                          XREF[1]:     005751d4(*)
//                               TRIBE_Action_Make_Obj::stop
//                              tact_mob.cpp:237 (4)
//         004d1550     PUSH       ESI
//         004d1551     MOV        ESI,this
//         004d1553     PUSH       EDI
//                              tact_mob.cpp:239 (33)
//         004d1554     MOV        EAX,dword ptr [ESI + 0x8]
//         004d1557     MOV        EDI,dword ptr [ESI + 0x48]
//         004d155a     PUSH       EDI
//         004d155b     MOV        this,dword ptr [EAX + 0xc]
//         004d155e     MOV        EAX,dword ptr [EAX + 0x4]
//         004d1561     PUSH       EAX
//         004d1562     MOVSX      EAX,word ptr [ESI + 0x40]
//         004d1566     MOV        EDX,dword ptr [this->_padding_]
//         004d1568     PUSH       EAX
//         004d1569     PUSH       s_Stopping_Train_#8:__obj_id=%d,_o               = "Stopping Train #8:  obj_id=%d, obj->id=%d,
//         004d156e     PUSH       this
//         004d156f     CALL       dword ptr [EDX + 0xe4]
//                              tact_mob.cpp:242 (10)
//         004d1575     MOV        AL,byte ptr [ESI + 0xc]
//         004d1578     ADD        ESP,0x14
//         004d157b     CMP        AL,0x1
//         004d157d     JZ         LAB_004d159f
//                              tact_mob.cpp:244 (9)
//         004d157f     MOV        EDX,dword ptr [ESI]
//         004d1581     PUSH       0x1
//         004d1583     MOV        this,ESI
//         004d1585     CALL       dword ptr [EDX + 0x5c]
//                              tact_mob.cpp:245 (7)
//         004d1588     MOV        AL,byte ptr [ESI + 0x4c]
//         004d158b     TEST       AL,AL
//         004d158d     JNZ        LAB_004d159f
//                              tact_mob.cpp:246 (16)
//         004d158f     MOV        this,dword ptr [ESI + 0x8]
//         004d1592     MOV        AX,word ptr [ESI + 0x40]
//         004d1596     PUSH       EAX
//         004d1597     MOV        this,dword ptr [ECX + this->_padding_]
//         004d159a     CALL       TRIBE_Player::reimburse_obj_cost                 void reimburse_obj_cost(TRIBE_Player * this,
//                               LAB_004d159f                                                 XREF[2]:     004d157d(j), 004d158d(j)
//                              tact_mob.cpp:248 (33)
//         004d159f     MOVSX      EAX,word ptr [ESI + 0x40]
//         004d15a3     PUSH       0x0
//         004d15a5     PUSH       0x0
//         004d15a7     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004d15ad     PUSH       EAX
//         004d15ae     MOV        EAX,dword ptr [ESI + 0x8]
//         004d15b1     MOV        EDX,dword ptr [this->_padding_]
//         004d15b3     MOV        EAX,dword ptr [EAX + 0xc]
//         004d15b6     MOVSX      EAX,word ptr [EAX + 0x4a]
//         004d15ba     PUSH       EAX
//                              language.dll match for 0x67: "Comic Sans MS"
//         004d15bb     PUSH       0x67
//         004d15bd     CALL       dword ptr [EDX + 0x40]
//                              tact_mob.cpp:249 (30)
//         004d15c0     MOV        this,dword ptr [ESI + 0x8]
//         004d15c3     PUSH       0x0
//         004d15c5     PUSH       0x0
//         004d15c7     PUSH       0x26b
//         004d15cc     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004d15cf     MOV        EDX,dword ptr [this->_padding_]
//         004d15d1     PUSH       0x1f9
//         004d15d6     PUSH       EAX
//         004d15d7     PUSH       EAX
//         004d15d8     CALL       dword ptr [EDX + 0x148]
//                              tact_mob.cpp:251 (8)
//         004d15de     POP        EDI
//         004d15df     MOV        EAX,0x1
//         004d15e4     POP        ESI
//         004d15e5     RET
//         004d15e6     ??         90h
//         004d15e7     NOP
//         004d15e8     NOP
//         004d15e9     NOP
//         004d15ea     NOP
//         004d15eb     NOP
//         004d15ec     NOP
//         004d15ed     NOP
//         004d15ee     NOP
//         004d15ef     NOP
    return 0;
}

void TRIBE_Action_Make_Obj::get_info(short* param_1, short* param_2, char* param_3, short param_4) {
    /* TODO: Stub */
//                              void __thiscall get_info(TRIBE_Action_Make_Obj * this, short * param
//              void              <VOID>         <RETURN>
//              TRIBE_Action_M    ECX:4 (auto)   this
//              short *           Stack[0x4]:4   param_1                   XREF[3]:     004d15f5(R), 004d1632(W), 004d1636(R)
//              short *           Stack[0x8]:4   param_2                   XREF[2]:     004d1607(R), 004d163f(R)
//              char *            Stack[0xc]:4   param_3                   XREF[1]:     004d1646(R)
//              short             Stack[0x10]:2  param_4                   XREF[1]:     004d1658(R)
//                               ?get_info@TRIBE_Action_Make_Obj@@QAEXAAF0PADF@Z              XREF[2]:     work_status:004c96a9(c),
//                               TRIBE_Action_Make_Obj::get_info                                           production_queue_status:004ca065(c
//                              tact_mob.cpp:255 (5)
//         004d15f0     PUSH       EBX
//         004d15f1     PUSH       ESI
//         004d15f2     MOV        ESI,this
//         004d15f4     PUSH       EDI
//                              tact_mob.cpp:256 (11)
//         004d15f5     MOV        this,dword ptr [ESP + param_1]
//         004d15f9     MOV        AX,word ptr [ESI + 0x40]
//         004d15fd     MOV        word ptr [this->_padding_],AX
//                              tact_mob.cpp:258 (7)
//         004d1600     MOV        AL,byte ptr [ESI + 0xc]
//         004d1603     CMP        AL,0x1
//         004d1605     JNZ        LAB_004d1612
//                              tact_mob.cpp:259 (9)
//         004d1607     MOV        EDX,dword ptr [ESP + param_2]
//         004d160b     MOV        word ptr [EDX],0x64
//                              tact_mob.cpp:260 (2)
//         004d1610     JMP        LAB_004d1646
//                               LAB_004d1612                                                 XREF[1]:     004d1605(j)
//                              tact_mob.cpp:261 (52)
//         004d1612     MOV        EAX,dword ptr [ESI + 0x8]
//         004d1615     MOVSX      EDX,word ptr [ESI + 0x40]
//         004d1619     FLD        float ptr [ESI + 0x44]
//         004d161c     FMUL       float ptr [DAT_005751a0]
//         004d1622     MOV        this,dword ptr [EAX + 0xc]
//         004d1625     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004d1628     MOV        this,dword ptr [EAX + EDX*0x4]
//         004d162b     MOVSX      EDX,word ptr [this->_padding_ + 0x15a]
//         004d1632     MOV        dword ptr [ESP + param_1],EDX
//         004d1636     FIDIV      dword ptr [ESP + param_1]
//         004d163a     CALL       __ftol                                           undefined __ftol()
//         004d163f     MOV        this,dword ptr [ESP + param_2]
//         004d1643     MOV        word ptr [this->_padding_],AX
//                               LAB_004d1646                                                 XREF[1]:     004d1610(j)
//                              tact_mob.cpp:263 (8)
//         004d1646     MOV        EBX,dword ptr [ESP + param_3]
//         004d164a     TEST       EBX,EBX
//         004d164c     JZ         LAB_004d1676
//                              tact_mob.cpp:265 (35)
//         004d164e     MOV        EDX,dword ptr [ESI + 0x8]
//         004d1651     MOVSX      this,word ptr [ESI + 0x40]
//         004d1655     MOV        EAX,dword ptr [EDX + 0xc]
//         004d1658     MOVSX      EDI,word ptr [ESP + param_4]
//         004d165d     MOV        EDX,dword ptr [EAX + 0x24]
//         004d1660     PUSH       EDI
//         004d1661     MOV        EAX,dword ptr [EDX + this->_padding_*0x4]
//         004d1664     MOV        this,dword ptr [EAX + 0x8]
//         004d1667     PUSH       this
//         004d1668     PUSH       EBX
//         004d1669     CALL       strncpy                                          undefined strncpy()
//         004d166e     ADD        ESP,0xc
//                              tact_mob.cpp:266 (5)
//         004d1671     MOV        byte ptr [EBX + EDI*0x1 + -0x1],0x0
//                               LAB_004d1676                                                 XREF[1]:     004d164c(j)
//                              tact_mob.cpp:268 (6)
//         004d1676     POP        EDI
//         004d1677     POP        ESI
//         004d1678     POP        EBX
//         004d1679     RET        0x10
//         004d167c     ??         90h
//         004d167d     NOP
//         004d167e     NOP
//         004d167f     NOP
    return;
}

