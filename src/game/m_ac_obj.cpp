#include "../common.h"
#include "m_ac_obj.h"

RGE_Master_Action_Object::RGE_Master_Action_Object(RGE_Master_Action_Object* param_1, int param_2) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Master_Action_Object(RGE_Master_Action_Obje
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Master_Act    ECX:4 (auto)   this
//              RGE_Master_Act    Stack[0x4]:4   param_1                   XREF[1]:     0044f088(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0044f09a(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0044f09e(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0044f0b8(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0044f091(W)
//                               ??0RGE_Master_Action_Object@@QAE@PAV0@H@Z                    XREF[2]:     make_new_master:0044f6ab(c),
//                               RGE_Master_Action_Object::RGE_Master_Action_Object                        RGE_Master_Combat_Object:0044fe65(
//                              m_ac_obj.cpp:29 (42)
//         0044f070     PUSH       -0x1
//         0044f072     PUSH       FUN_0055d638
//         0044f077     MOV        EAX,FS:[0x0]
//         0044f07d     PUSH       EAX
//         0044f07e     MOV        dword ptr FS:[0x0],ESP
//         0044f085     PUSH       this
//         0044f086     PUSH       ESI
//         0044f087     PUSH       EDI
//         0044f088     MOV        EDI,dword ptr [ESP + param_1]
//         0044f08c     MOV        ESI,this
//         0044f08e     PUSH       0x0
//         0044f090     PUSH       EDI
//         0044f091     MOV        dword ptr [ESP + local_10],ESI
//         0044f095     CALL       RGE_Master_Moving_Object::RGE_Master_Moving_Ob   undefined RGE_Master_Moving_Object(RGE_Master
//                              m_ac_obj.cpp:30 (22)
//         0044f09a     MOV        EAX,dword ptr [ESP + param_2]
//         0044f09e     MOV        dword ptr [ESP + local_4],0x0
//         0044f0a6     TEST       EAX,EAX
//         0044f0a8     MOV        dword ptr [ESI],RGE_Master_Action_Object::`vft   = 0044f0d0
//         0044f0ae     JZ         LAB_0044f0b8
//                              m_ac_obj.cpp:31 (8)
//         0044f0b0     PUSH       EDI
//         0044f0b1     MOV        this,ESI
//         0044f0b3     CALL       RGE_Master_Action_Object::setup                  int setup(RGE_Master_Action_Object * this, RG
//                               LAB_0044f0b8                                                 XREF[1]:     0044f0ae(j)
//                              m_ac_obj.cpp:32 (21)
//         0044f0b8     MOV        this,dword ptr [ESP + local_c]
//         0044f0bc     MOV        EAX,ESI
//         0044f0be     POP        EDI
//         0044f0bf     MOV        dword ptr FS:[0x0],this
//         0044f0c6     POP        ESI
//         0044f0c7     ADD        ESP,0x10
//         0044f0ca     RET        0x8
//         0044f0cd     ??         90h
//         0044f0ce     NOP
//         0044f0cf     NOP
}

RGE_Master_Action_Object::RGE_Master_Action_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Master_Action_Object(RGE_Master_Action_Obje
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Master_Act    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0044f10c(R)
//              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     0044f107(R)
//              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[1]:     0044f112(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     0044f126(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0044f12a(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0044f146(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0044f11d(W)
//                               ??0RGE_Master_Action_Object@@QAE@HPAPAVRGE_Sprite@@PAPAVRGE  XREF[3]:     RGE_Master_Combat_Object:0044fef1(
//                               RGE_Master_Action_Object::RGE_Master_Action_Object                        load_master_object:00461408(c),
//                                                                                                         load_master_object:0046fdd8(c)
//                              m_ac_obj.cpp:38 (54)
//         0044f0f0     PUSH       -0x1
//         0044f0f2     PUSH       FUN_0055d658
//         0044f0f7     MOV        EAX,FS:[0x0]
//         0044f0fd     PUSH       EAX
//         0044f0fe     MOV        dword ptr FS:[0x0],ESP
//         0044f105     PUSH       this
//         0044f106     PUSH       EBX
//         0044f107     MOV        EBX,dword ptr [ESP + param_2]
//         0044f10b     PUSH       EBP
//         0044f10c     MOV        EBP,dword ptr [ESP + param_1]
//         0044f110     PUSH       ESI
//         0044f111     PUSH       EDI
//         0044f112     MOV        EDI,dword ptr [ESP + param_3]
//         0044f116     PUSH       0x0
//         0044f118     PUSH       EDI
//         0044f119     MOV        ESI,this
//         0044f11b     PUSH       EBX
//         0044f11c     PUSH       EBP
//         0044f11d     MOV        dword ptr [ESP + local_10],ESI
//         0044f121     CALL       RGE_Master_Moving_Object::RGE_Master_Moving_Ob   undefined RGE_Master_Moving_Object(RGE_Master
//                              m_ac_obj.cpp:39 (22)
//         0044f126     MOV        EAX,dword ptr [ESP + param_4]
//         0044f12a     MOV        dword ptr [ESP + local_4],0x0
//         0044f132     TEST       EAX,EAX
//         0044f134     MOV        dword ptr [ESI],RGE_Master_Action_Object::`vft   = 0044f0d0
//         0044f13a     JZ         LAB_0044f146
//                              m_ac_obj.cpp:40 (10)
//         0044f13c     PUSH       EDI
//         0044f13d     PUSH       EBX
//         0044f13e     PUSH       EBP
//         0044f13f     MOV        this,ESI
//         0044f141     CALL       RGE_Master_Action_Object::setup                  int setup(RGE_Master_Action_Object * this, in
//                               LAB_0044f146                                                 XREF[1]:     0044f13a(j)
//                              m_ac_obj.cpp:41 (23)
//         0044f146     MOV        this,dword ptr [ESP + local_c]
//         0044f14a     MOV        EAX,ESI
//         0044f14c     POP        EDI
//         0044f14d     POP        ESI
//         0044f14e     POP        EBP
//         0044f14f     MOV        dword ptr FS:[0x0],this
//         0044f156     POP        EBX
//         0044f157     ADD        ESP,0x10
//         0044f15a     RET        0x10
//         0044f15d     ??         90h
//         0044f15e     NOP
//         0044f15f     NOP
}

RGE_Master_Action_Object::RGE_Master_Action_Object(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Master_Action_Object(RGE_Master_Action_Obje
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Master_Act    ECX:4 (auto)   this
//              _iobuf *          Stack[0x4]:4   param_1                   XREF[2]:     0044f176(R), 0044f1b1(R)
//              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     0044f180(R)
//              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[1]:     0044f17b(R)
//              short             Stack[0x10]:2  param_4                   XREF[1]:     0044f186(R)
//              int               Stack[0x14]:4  param_5                   XREF[1]:     0044f19b(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0044f19f(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0044f1c0(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0044f192(W)
//                               ??0RGE_Master_Action_Object@@QAE@PAU_iobuf@@PAPAVRGE_Sprite  XREF[2]:     RGE_Master_Combat_Object:0044ff66(
//                               RGE_Master_Action_Object::RGE_Master_Action_Object                        load_object:00461710(c)
//                              m_ac_obj.cpp:47 (59)
//         0044f160     PUSH       -0x1
//         0044f162     PUSH       FUN_0055d678
//         0044f167     MOV        EAX,FS:[0x0]
//         0044f16d     PUSH       EAX
//         0044f16e     MOV        dword ptr FS:[0x0],ESP
//         0044f175     PUSH       this
//         0044f176     MOV        EAX,dword ptr [ESP + param_1]
//         0044f17a     PUSH       EBX
//         0044f17b     MOV        EBX,dword ptr [ESP + param_3]
//         0044f17f     PUSH       EBP
//         0044f180     MOV        EBP,dword ptr [ESP + param_2]
//         0044f184     PUSH       ESI
//         0044f185     PUSH       EDI
//         0044f186     MOV        EDI,dword ptr [ESP + param_4]
//         0044f18a     PUSH       0x0
//         0044f18c     PUSH       EDI
//         0044f18d     PUSH       EBX
//         0044f18e     MOV        ESI,this
//         0044f190     PUSH       EBP
//         0044f191     PUSH       EAX
//         0044f192     MOV        dword ptr [ESP + local_10],ESI
//         0044f196     CALL       RGE_Master_Moving_Object::RGE_Master_Moving_Ob   undefined RGE_Master_Moving_Object(RGE_Master
//                              m_ac_obj.cpp:48 (22)
//         0044f19b     MOV        EAX,dword ptr [ESP + param_5]
//         0044f19f     MOV        dword ptr [ESP + local_4],0x0
//         0044f1a7     TEST       EAX,EAX
//         0044f1a9     MOV        dword ptr [ESI],RGE_Master_Action_Object::`vft   = 0044f0d0
//         0044f1af     JZ         LAB_0044f1c0
//                              m_ac_obj.cpp:49 (15)
//         0044f1b1     MOV        this,dword ptr [ESP + param_1]
//         0044f1b5     PUSH       EDI
//         0044f1b6     PUSH       EBX
//         0044f1b7     PUSH       EBP
//         0044f1b8     PUSH       this
//         0044f1b9     MOV        this,ESI
//         0044f1bb     CALL       RGE_Master_Action_Object::setup                  int setup(RGE_Master_Action_Object * this, _i
//                               LAB_0044f1c0                                                 XREF[1]:     0044f1af(j)
//                              m_ac_obj.cpp:50 (23)
//         0044f1c0     MOV        this,dword ptr [ESP + local_c]
//         0044f1c4     MOV        EAX,ESI
//         0044f1c6     POP        EDI
//         0044f1c7     POP        ESI
//         0044f1c8     POP        EBP
//         0044f1c9     MOV        dword ptr FS:[0x0],this
//         0044f1d0     POP        EBX
//         0044f1d1     ADD        ESP,0x10
//         0044f1d4     RET        0x14
//         0044f1d7     ??         90h
//         0044f1d8     NOP
//         0044f1d9     NOP
//         0044f1da     NOP
//         0044f1db     NOP
//         0044f1dc     NOP
//         0044f1dd     NOP
//         0044f1de     NOP
//         0044f1df     NOP
}

int RGE_Master_Action_Object::setup(RGE_Master_Action_Object* param_1) {
    /* TODO: Stub */
//                              int __thiscall setup(RGE_Master_Action_Object * this, RGE_Master_Act
//              int               EAX:4          <RETURN>
//              RGE_Master_Act    ECX:4 (auto)   this
//              RGE_Master_Act    Stack[0x4]:4   param_1                   XREF[1]:     0044f1e2(R)
//                               ?setup@RGE_Master_Action_Object@@IAEHPAV1@@Z                 XREF[2]:     RGE_Master_Action_Object:0044f0b3(
//                               RGE_Master_Action_Object::setup                                           setup:0044ffbb(c)
//                              m_ac_obj.cpp:55 (2)
//         0044f1e0     PUSH       ESI
//         0044f1e1     PUSH       EDI
//                              m_ac_obj.cpp:56 (12)
//         0044f1e2     MOV        EDI,dword ptr [ESP + param_1]
//         0044f1e6     MOV        ESI,this
//         0044f1e8     PUSH       EDI
//         0044f1e9     CALL       RGE_Master_Moving_Object::setup                  int setup(RGE_Master_Moving_Object * this, RG
//                              m_ac_obj.cpp:58 (4)
//         0044f1ee     MOV        byte ptr [ESI + 0x4],0x28
//                              m_ac_obj.cpp:61 (14)
//         0044f1f2     MOV        AX,word ptr [EDI + 0xdc]
//         0044f1f9     MOV        word ptr [ESI + 0xdc],AX
//                              m_ac_obj.cpp:62 (12)
//         0044f200     MOV        this,dword ptr [EDI + 0xe0]
//         0044f206     MOV        dword ptr [ESI + 0xe0],this
//                              m_ac_obj.cpp:63 (12)
//         0044f20c     MOV        EDX,dword ptr [EDI + 0xe4]
//         0044f212     MOV        dword ptr [ESI + 0xe4],EDX
//                              m_ac_obj.cpp:64 (14)
//         0044f218     MOV        AX,word ptr [EDI + 0xe8]
//         0044f21f     MOV        word ptr [ESI + 0xe8],AX
//                              m_ac_obj.cpp:65 (14)
//         0044f226     MOV        this,word ptr [EDI + 0xea]
//         0044f22d     MOV        word ptr [ESI + 0xea],this
//                              m_ac_obj.cpp:66 (12)
//         0044f234     MOV        DL,byte ptr [EDI + 0xec]
//         0044f23a     MOV        byte ptr [ESI + 0xec],DL
//                              m_ac_obj.cpp:67 (12)
//         0044f240     MOV        EAX,dword ptr [EDI + 0xf0]
//         0044f246     MOV        dword ptr [ESI + 0xf0],EAX
//                              m_ac_obj.cpp:68 (6)
//         0044f24c     MOV        this,dword ptr [EDI + 0xf4]
//                              m_ac_obj.cpp:72 (31)
//         0044f252     MOV        EAX,dword ptr [ESI]
//         0044f254     MOV        dword ptr [ESI + 0xf4],this
//         0044f25a     MOV        DL,byte ptr [EDI + 0xf8]
//         0044f260     MOV        this,ESI
//         0044f262     MOV        byte ptr [ESI + 0xf8],DL
//         0044f268     CALL       dword ptr [EAX + 0x38]
//         0044f26b     MOV        dword ptr [ESI + 0xd8],EAX
//                              m_ac_obj.cpp:73 (14)
//         0044f271     MOV        this,dword ptr [EDI + 0xd8]
//         0044f277     PUSH       this
//         0044f278     MOV        this,EAX
//         0044f27a     CALL       RGE_Task_List::copy                              void copy(RGE_Task_List * this, RGE_Task_List
//                              m_ac_obj.cpp:76 (10)
//         0044f27f     POP        EDI
//         0044f280     MOV        EAX,0x1
//         0044f285     POP        ESI
//         0044f286     RET        0x4
//         0044f289     ??         90h
//         0044f28a     NOP
//         0044f28b     NOP
//         0044f28c     NOP
//         0044f28d     NOP
//         0044f28e     NOP
//         0044f28f     NOP
    return 0;
}

int RGE_Master_Action_Object::setup(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3) {
    /* TODO: Stub */
//                              int __thiscall setup(RGE_Master_Action_Object * this, int param_1, R
//              int               EAX:4          <RETURN>
//              RGE_Master_Act    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0044f29c(R)
//              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[4]:     0044f296(R), 0044f33d(*), 0044f353(W), 0044f382(R)
//              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[4]:     0044f291(R), 0044f31a(*), 0044f34f(R), 0044f366(R)
//                               ?setup@RGE_Master_Action_Object@@IAEHHPAPAVRGE_Sprite@@PAPA  XREF[2]:     RGE_Master_Action_Object:0044f141(
//                               RGE_Master_Action_Object::setup                                           setup:00450187(c)
//                              m_ac_obj.cpp:81 (1)
//         0044f290     PUSH       EBX
//                              m_ac_obj.cpp:85 (25)
//         0044f291     MOV        EBX,dword ptr [ESP + param_3]
//         0044f295     PUSH       EBP
//         0044f296     MOV        EBP,dword ptr [ESP + param_2]
//         0044f29a     PUSH       ESI
//         0044f29b     PUSH       EDI
//         0044f29c     MOV        EDI,dword ptr [ESP + param_1]
//         0044f2a0     PUSH       EBX
//         0044f2a1     PUSH       EBP
//         0044f2a2     MOV        ESI,this
//         0044f2a4     PUSH       EDI
//         0044f2a5     CALL       RGE_Master_Moving_Object::setup                  int setup(RGE_Master_Moving_Object * this, in
//                              m_ac_obj.cpp:90 (22)
//         0044f2aa     LEA        EAX,[ESI + 0xdc]
//         0044f2b0     PUSH       0x2
//         0044f2b2     PUSH       EAX
//         0044f2b3     PUSH       EDI
//         0044f2b4     MOV        byte ptr [ESI + 0x4],0x28
//         0044f2b8     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0044f2bd     ADD        ESP,0xc
//                              m_ac_obj.cpp:91 (18)
//         0044f2c0     LEA        this,[ESI + 0xe0]
//         0044f2c6     PUSH       0x4
//         0044f2c8     PUSH       this
//         0044f2c9     PUSH       EDI
//         0044f2ca     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0044f2cf     ADD        ESP,0xc
//                              m_ac_obj.cpp:92 (18)
//         0044f2d2     LEA        EDX,[ESI + 0xe4]
//         0044f2d8     PUSH       0x4
//         0044f2da     PUSH       EDX
//         0044f2db     PUSH       EDI
//         0044f2dc     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0044f2e1     ADD        ESP,0xc
//                              m_ac_obj.cpp:93 (18)
//         0044f2e4     LEA        EAX,[ESI + 0xe8]
//         0044f2ea     PUSH       0x2
//         0044f2ec     PUSH       EAX
//         0044f2ed     PUSH       EDI
//         0044f2ee     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0044f2f3     ADD        ESP,0xc
//                              m_ac_obj.cpp:94 (18)
//         0044f2f6     LEA        this,[ESI + 0xea]
//         0044f2fc     PUSH       0x2
//         0044f2fe     PUSH       this
//         0044f2ff     PUSH       EDI
//         0044f300     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0044f305     ADD        ESP,0xc
//                              m_ac_obj.cpp:95 (18)
//         0044f308     LEA        EDX,[ESI + 0xec]
//         0044f30e     PUSH       0x1
//         0044f310     PUSH       EDX
//         0044f311     PUSH       EDI
//         0044f312     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0044f317     ADD        ESP,0xc
//                              m_ac_obj.cpp:96 (13)
//         0044f31a     LEA        EAX=>param_3,[ESP + 0x1c]
//         0044f31e     PUSH       0x2
//         0044f320     PUSH       EAX
//         0044f321     PUSH       EDI
//         0044f322     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              m_ac_obj.cpp:98 (22)
//         0044f327     FLD        float ptr [save_game_version]                    = 7.23
//         0044f32d     FCOMP      float ptr [DAT_00570484]                         = A4h
//         0044f333     ADD        ESP,0xc
//         0044f336     FNSTSW     AX
//         0044f338     TEST       AH,0x1
//         0044f33b     JNZ        LAB_0044f34f
//                              m_ac_obj.cpp:99 (16)
//         0044f33d     LEA        this=>param_2,[ESP + 0x18]
//         0044f341     PUSH       0x2
//         0044f343     PUSH       this
//         0044f344     PUSH       EDI
//         0044f345     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0044f34a     ADD        ESP,0xc
//                              m_ac_obj.cpp:100 (2)
//         0044f34d     JMP        LAB_0044f357
//                               LAB_0044f34f                                                 XREF[1]:     0044f33b(j)
//                              m_ac_obj.cpp:101 (8)
//         0044f34f     MOV        EDX,dword ptr [ESP + param_3]
//         0044f353     MOV        dword ptr [ESP + param_2],EDX
//                               LAB_0044f357                                                 XREF[1]:     0044f34d(j)
//                              m_ac_obj.cpp:103 (15)
//         0044f357     LEA        EAX,[ESI + 0xf8]
//         0044f35d     PUSH       0x1
//         0044f35f     PUSH       EAX
//         0044f360     PUSH       EDI
//         0044f361     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              m_ac_obj.cpp:106 (28)
//         0044f366     MOV        EAX,dword ptr [ESP + param_3]
//         0044f36a     ADD        ESP,0xc
//         0044f36d     TEST       AX,AX
//         0044f370     JL         LAB_0044f37a
//         0044f372     MOVSX      this,AX
//         0044f375     MOV        EAX,dword ptr [EBX + this->_padding_*0x4]
//         0044f378     JMP        LAB_0044f37c
//                               LAB_0044f37a                                                 XREF[1]:     0044f370(j)
//         0044f37a     XOR        EAX,EAX
//                               LAB_0044f37c                                                 XREF[1]:     0044f378(j)
//         0044f37c     MOV        dword ptr [ESI + 0xf0],EAX
//                              m_ac_obj.cpp:107 (25)
//         0044f382     MOV        EAX,dword ptr [ESP + param_2]
//         0044f386     TEST       AX,AX
//         0044f389     JL         LAB_0044f393
//         0044f38b     MOVSX      EDX,AX
//         0044f38e     MOV        EAX,dword ptr [EBX + EDX*0x4]
//         0044f391     JMP        LAB_0044f395
//                               LAB_0044f393                                                 XREF[1]:     0044f389(j)
//         0044f393     XOR        EAX,EAX
//                               LAB_0044f395                                                 XREF[1]:     0044f391(j)
//         0044f395     MOV        dword ptr [ESI + 0xf4],EAX
//                              m_ac_obj.cpp:110 (7)
//         0044f39b     MOV        EAX,dword ptr [ESI]
//         0044f39d     MOV        this,ESI
//         0044f39f     CALL       dword ptr [EAX + 0x38]
//                              m_ac_obj.cpp:111 (16)
//         0044f3a2     PUSH       EBX
//         0044f3a3     PUSH       EBP=>DAT_fffffff8
//         0044f3a4     PUSH       EDI=>DAT_fffffff4
//         0044f3a5     MOV        this,EAX
//         0044f3a7     MOV        dword ptr [ESI + 0xd8],EAX
//         0044f3ad     CALL       RGE_Task_List::load                              void load(RGE_Task_List * this, int param_1,
//                              m_ac_obj.cpp:114 (12)
//         0044f3b2     POP        EDI
//         0044f3b3     POP        ESI
//         0044f3b4     POP        EBP
//         0044f3b5     MOV        EAX,0x1
//         0044f3ba     POP        EBX
//         0044f3bb     RET        0xc
//         0044f3be     ??         90h
//         0044f3bf     NOP
    return 0;
}

int RGE_Master_Action_Object::setup(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4) {
    /* TODO: Stub */
//                              int __thiscall setup(RGE_Master_Action_Object * this, _iobuf * param
//              int               EAX:4          <RETURN>
//              RGE_Master_Act    ECX:4 (auto)   this
//              _iobuf *          Stack[0x4]:4   param_1                   XREF[3]:     0044f3c5(R), 0044f3e3(*), 0044f44f(R)
//              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[3]:     0044f3ca(R), 0044f3e8(*), 0044f42c(R)
//              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[3]:     0044f3d0(R), 0044f3df(*), 0044f422(R)
//              short             Stack[0x10]:2  param_4                   XREF[3]:     0044f3c0(R), 0044f3ed(*), 0044f41e(R)
//                               ?setup@RGE_Master_Action_Object@@IAEHPAU_iobuf@@PAPAVRGE_Sp  XREF[2]:     RGE_Master_Action_Object:0044f1bb(
//                               RGE_Master_Action_Object::setup                                           setup:0045046d(c)
//                              m_ac_obj.cpp:119 (31)
//         0044f3c0     MOV        EAX,dword ptr [ESP + param_4]
//         0044f3c4     PUSH       EBX
//         0044f3c5     MOV        EBX,dword ptr [ESP + param_1]
//         0044f3c9     PUSH       EBP
//         0044f3ca     MOV        EBP,dword ptr [ESP + param_2]
//         0044f3ce     PUSH       ESI
//         0044f3cf     PUSH       EDI
//         0044f3d0     MOV        EDI,dword ptr [ESP + param_3]
//         0044f3d4     PUSH       EAX
//         0044f3d5     PUSH       EDI
//         0044f3d6     PUSH       EBP
//         0044f3d7     MOV        ESI,this
//         0044f3d9     PUSH       EBX
//         0044f3da     CALL       RGE_Master_Moving_Object::setup                  int setup(RGE_Master_Moving_Object * this, _i
//                              m_ac_obj.cpp:139 (63)
//         0044f3df     LEA        this=>param_3,[ESP + 0x1c]
//         0044f3e3     LEA        EDX=>param_1,[ESP + 0x14]
//         0044f3e7     PUSH       this
//         0044f3e8     LEA        EAX=>param_2,[ESP + 0x1c]
//         0044f3ec     PUSH       EDX
//         0044f3ed     LEA        this=>param_4,[ESP + 0x28]
//         0044f3f1     PUSH       EAX
//         0044f3f2     LEA        EDX,[ESI + 0xea]
//         0044f3f8     PUSH       this
//         0044f3f9     LEA        EAX,[ESI + 0xe8]
//         0044f3ff     PUSH       EDX
//         0044f400     LEA        this,[ESI + 0xe4]
//         0044f406     PUSH       EAX
//         0044f407     LEA        EDX,[ESI + 0xe0]
//         0044f40d     PUSH       this
//         0044f40e     PUSH       EDX
//         0044f40f     PUSH       s_%f_%f_%hd_%hd_%hd_%hd_%hd_%hd                  = "%f %f %hd %hd %hd %hd %hd %hd"
//         0044f414     PUSH       EBX
//         0044f415     MOV        byte ptr [ESI + 0x4],0x28
//         0044f419     CALL       fscanf                                           undefined fscanf()
//                              m_ac_obj.cpp:142 (4)
//         0044f41e     MOV        AL,byte ptr [ESP + param_4]
//                              m_ac_obj.cpp:143 (10)
//         0044f422     MOV        this,byte ptr [ESP + param_3]
//         0044f426     MOV        byte ptr [ESI + 0xec],AL
//                              m_ac_obj.cpp:145 (35)
//         0044f42c     MOV        AX,word ptr [ESP + param_2]
//         0044f431     ADD        ESP,0x28
//         0044f434     MOV        byte ptr [ESI + 0xf8],this
//         0044f43a     TEST       AX,AX
//         0044f43d     JL         LAB_0044f447
//         0044f43f     MOVSX      EDX,AX
//         0044f442     MOV        EAX,dword ptr [EDI + EDX*0x4]
//         0044f445     JMP        LAB_0044f449
//                               LAB_0044f447                                                 XREF[1]:     0044f43d(j)
//         0044f447     XOR        EAX,EAX
//                               LAB_0044f449                                                 XREF[1]:     0044f445(j)
//         0044f449     MOV        dword ptr [ESI + 0xf0],EAX
//                              m_ac_obj.cpp:146 (20)
//         0044f44f     MOV        AX,word ptr [ESP + param_1]
//         0044f454     TEST       AX,AX
//         0044f457     JL         LAB_0044f461
//         0044f459     MOVSX      EAX,AX
//         0044f45c     MOV        EAX,dword ptr [EDI + EAX*0x4]
//         0044f45f     JMP        LAB_0044f463
//                               LAB_0044f461                                                 XREF[1]:     0044f457(j)
//         0044f461     XOR        EAX,EAX
//                               LAB_0044f463                                                 XREF[1]:     0044f45f(j)
//                              m_ac_obj.cpp:149 (13)
//         0044f463     MOV        EDX,dword ptr [ESI]
//         0044f465     MOV        this,ESI
//         0044f467     MOV        dword ptr [ESI + 0xf4],EAX
//         0044f46d     CALL       dword ptr [EDX + 0x38]
//                              m_ac_obj.cpp:150 (16)
//         0044f470     PUSH       EDI
//         0044f471     PUSH       EBP=>DAT_fffffff8
//         0044f472     PUSH       EBX=>DAT_fffffff4
//         0044f473     MOV        this,EAX
//         0044f475     MOV        dword ptr [ESI + 0xd8],EAX
//         0044f47b     CALL       RGE_Task_List::load                              void load(RGE_Task_List * this, _iobuf * para
//                              m_ac_obj.cpp:154 (25)
//         0044f480     MOV        EDX,dword ptr [ESI + 0xd8]
//         0044f486     MOV        word ptr [ESI + 0xdc],0xffff
//         0044f48f     XOR        EAX,EAX
//         0044f491     MOVSX      this,word ptr [EDX + 0x8]
//         0044f495     TEST       this,this
//         0044f497     JLE        LAB_0044f4c0
//                              m_ac_obj.cpp:146 (3)
//         0044f499     MOV        EDX,dword ptr [EDX + 0x4]
//                               LAB_0044f49c                                                 XREF[1]:     0044f4ab(j)
//                              m_ac_obj.cpp:156 (17)
//         0044f49c     MOV        EDI,dword ptr [EDX]
//         0044f49e     MOV        BL,byte ptr [EDI + 0x4]
//         0044f4a1     TEST       BL,BL
//         0044f4a3     JNZ        LAB_0044f4b9
//         0044f4a5     INC        EAX
//         0044f4a6     ADD        EDX,0x4
//         0044f4a9     CMP        EAX,this
//         0044f4ab     JL         LAB_0044f49c
//                              m_ac_obj.cpp:163 (5)
//         0044f4ad     MOV        EAX,0x1
//                              m_ac_obj.cpp:164 (7)
//         0044f4b2     POP        EDI
//         0044f4b3     POP        ESI
//         0044f4b4     POP        EBP
//         0044f4b5     POP        EBX
//         0044f4b6     RET        0x10
//                               LAB_0044f4b9                                                 XREF[1]:     0044f4a3(j)
//                              m_ac_obj.cpp:158 (7)
//         0044f4b9     MOV        word ptr [ESI + 0xdc],AX
//                               LAB_0044f4c0                                                 XREF[1]:     0044f497(j)
//                              m_ac_obj.cpp:164 (12)
//         0044f4c0     POP        EDI
//         0044f4c1     POP        ESI
//         0044f4c2     POP        EBP
//         0044f4c3     MOV        EAX,0x1
//         0044f4c8     POP        EBX
//         0044f4c9     RET        0x10
//         0044f4cc     ??         90h
//         0044f4cd     NOP
//         0044f4ce     NOP
//         0044f4cf     NOP
    return 0;
}

RGE_Master_Action_Object::~RGE_Master_Action_Object() {
    /* TODO: Stub */
//                              void __thiscall ~RGE_Master_Action_Object(RGE_Master_Action_Object *
//              void              <VOID>         <RETURN>
//              RGE_Master_Act    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0044f4fa(W), 0044f522(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0044f52f(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0044f4ea(W)
//                               ??1RGE_Master_Action_Object@@UAE@XZ                          XREF[2]:     `vector_deleting_destructor':0044f
//                               RGE_Master_Action_Object::~RGE_Master_Action_Object                       ~RGE_Master_Combat_Object:004506c5
//                              m_ac_obj.cpp:169 (36)
//         0044f4d0     PUSH       -0x1
//         0044f4d2     PUSH       FUN_0055d698
//         0044f4d7     MOV        EAX,FS:[0x0]
//         0044f4dd     PUSH       EAX
//         0044f4de     MOV        dword ptr FS:[0x0],ESP
//         0044f4e5     PUSH       this
//         0044f4e6     PUSH       ESI
//         0044f4e7     MOV        ESI,this
//         0044f4e9     PUSH       EDI
//         0044f4ea     MOV        dword ptr [ESP + local_10],ESI
//         0044f4ee     MOV        dword ptr [ESI],RGE_Master_Action_Object::`vft   = 0044f0d0
//                              m_ac_obj.cpp:170 (18)
//         0044f4f4     MOV        EDI,dword ptr [ESI + 0xd8]
//         0044f4fa     MOV        dword ptr [ESP + local_4],0x0
//         0044f502     TEST       EDI,EDI
//         0044f504     JZ         LAB_0044f520
//                              m_ac_obj.cpp:172 (16)
//         0044f506     MOV        this,EDI
//         0044f508     CALL       RGE_Task_List::~RGE_Task_List                    void ~RGE_Task_List(RGE_Task_List * this)
//         0044f50d     PUSH       EDI
//         0044f50e     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0044f513     ADD        ESP,0x4
//                              m_ac_obj.cpp:173 (12)
//         0044f516     MOV        dword ptr [ESI + 0xd8],0x0
//                               LAB_0044f520                                                 XREF[1]:     0044f504(j)
//         0044f520     MOV        this,ESI
//                              m_ac_obj.cpp:175 (30)
//         0044f522     MOV        dword ptr [ESP + local_4],0xffffffff
//         0044f52a     CALL       RGE_Master_Moving_Object::~RGE_Master_Moving_O   void ~RGE_Master_Moving_Object(RGE_Master_Mov
//         0044f52f     MOV        this,dword ptr [ESP + local_c]
//         0044f533     POP        EDI
//         0044f534     MOV        dword ptr FS:[0x0],this
//         0044f53b     POP        ESI
//         0044f53c     ADD        ESP,0x10
//         0044f53f     RET
}

RGE_Task_List* RGE_Master_Action_Object::create_task_list() {
    /* TODO: Stub */
//                              RGE_Task_List * __thiscall create_task_list(RGE_Master_Action_Object
//              RGE_Task_List *   EAX:4          <RETURN>
//              RGE_Master_Act    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0044f566(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     0044f577(R), 0044f586(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0044f560(*)
//                               ?create_task_list@RGE_Master_Action_Object@@UAEPAVRGE_Task_  XREF[3]:     00570480(*), 005704f8(*),
//                               RGE_Master_Action_Object::create_task_list                                00570598(*)
//                              m_ac_obj.cpp:181 (22)
//         0044f540     PUSH       -0x1
//         0044f542     PUSH       FUN_0055d6bb
//         0044f547     MOV        EAX,FS:[0x0]
//         0044f54d     PUSH       EAX
//         0044f54e     MOV        dword ptr FS:[0x0],ESP
//         0044f555     PUSH       this
//                              m_ac_obj.cpp:182 (33)
//         0044f556     PUSH       0xc
//         0044f558     CALL       operator_new                                     void * operator_new(uint param_1)
//         0044f55d     ADD        ESP,0x4
//         0044f560     MOV        dword ptr [ESP]=>local_10,EAX
//         0044f564     TEST       EAX,EAX
//         0044f566     MOV        dword ptr [ESP + local_4],0x0
//         0044f56e     JZ         LAB_0044f586
//         0044f570     MOV        this,EAX
//         0044f572     CALL       RGE_Task_List::RGE_Task_List                     undefined RGE_Task_List(RGE_Task_List * this)
//                              m_ac_obj.cpp:183 (32)
//         0044f577     MOV        this,dword ptr [ESP + local_c]
//         0044f57b     MOV        dword ptr FS:[0x0],this
//         0044f582     ADD        ESP,0x10
//         0044f585     RET
//                               LAB_0044f586                                                 XREF[1]:     0044f56e(j)
//         0044f586     MOV        this,dword ptr [ESP + local_c]
//         0044f58a     XOR        EAX,EAX
//         0044f58c     MOV        dword ptr FS:[0x0],this
//         0044f593     ADD        ESP,0x10
//         0044f596     RET
//         0044f597     ??         90h
//         0044f598     NOP
//         0044f599     NOP
//         0044f59a     NOP
//         0044f59b     NOP
//         0044f59c     NOP
//         0044f59d     NOP
//         0044f59e     NOP
//         0044f59f     NOP
    return 0;
}

RGE_Static_Object* RGE_Master_Action_Object::make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4) {
    /* TODO: Stub */
//                              RGE_Static_Object * __thiscall make_new_obj(RGE_Master_Action_Object
//              RGE_Static_Obj    EAX:4          <RETURN>
//              RGE_Master_Act    ECX:4 (auto)   this
//              RGE_Player *      Stack[0x4]:4   param_1                   XREF[2]:     0044f5b7(R), 0044f615(W)
//              float             Stack[0x8]:4   param_2                   XREF[2]:     0044f5e5(R), 0044f630(R)
//              float             Stack[0xc]:4   param_3                   XREF[2]:     0044f5de(R), 0044f629(R)
//              float             Stack[0x10]:4  param_4                   XREF[2]:     0044f5da(R), 0044f625(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0044f61b(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     0044f63f(R), 0044f653(R)
//                               ?make_new_obj@RGE_Master_Action_Object@@UAEPAVRGE_Static_Ob  XREF[1]:     00570460(*)
//                               RGE_Master_Action_Object::make_new_obj
//                              m_ac_obj.cpp:188 (23)
//         0044f5a0     MOV        EAX,FS:[0x0]
//         0044f5a6     PUSH       -0x1
//         0044f5a8     PUSH       FUN_0055d6db
//         0044f5ad     PUSH       EAX
//         0044f5ae     MOV        dword ptr FS:[0x0],ESP
//         0044f5b5     PUSH       EBX
//         0044f5b6     PUSH       ESI
//                              m_ac_obj.cpp:191 (17)
//         0044f5b7     MOV        EBX,dword ptr [ESP + param_1]
//         0044f5bb     PUSH       EDI
//         0044f5bc     MOV        EDI,this
//         0044f5be     MOV        AL,byte ptr [EDI + 0xa4]
//         0044f5c4     TEST       AL,AL
//         0044f5c6     JZ         LAB_0044f608
//                              m_ac_obj.cpp:193 (14)
//         0044f5c8     MOV        AL,byte ptr [EDI + 0x4]
//         0044f5cb     MOV        this,dword ptr [EBX + 0x3c]
//         0044f5ce     PUSH       EAX
//         0044f5cf     CALL       RGE_Game_World::recycle_object_in_to_game        RGE_Static_Object * recycle_object_in_to_game
//         0044f5d4     MOV        ESI,EAX
//                              m_ac_obj.cpp:194 (4)
//         0044f5d6     TEST       ESI,ESI
//         0044f5d8     JZ         LAB_0044f608
//                              m_ac_obj.cpp:196 (24)
//         0044f5da     MOV        EAX,dword ptr [ESP + param_4]
//         0044f5de     MOV        this,dword ptr [ESP + param_3]
//         0044f5e2     MOV        EDX,dword ptr [ESI]
//         0044f5e4     PUSH       EAX
//         0044f5e5     MOV        EAX,dword ptr [ESP + param_2]
//         0044f5e9     PUSH       this
//         0044f5ea     PUSH       EAX
//         0044f5eb     PUSH       EBX
//         0044f5ec     PUSH       EDI
//         0044f5ed     MOV        this,ESI
//         0044f5ef     CALL       dword ptr [EDX + 0x4]
//                              m_ac_obj.cpp:197 (2)
//         0044f5f2     MOV        EAX,ESI
//                              m_ac_obj.cpp:202 (20)
//         0044f5f4     MOV        this,dword ptr [ESP + 0xc]
//         0044f5f8     MOV        dword ptr FS:[0x0],this
//         0044f5ff     POP        EDI
//         0044f600     POP        ESI
//         0044f601     POP        EBX
//         0044f602     ADD        ESP,0xc
//         0044f605     RET        0x10
//                               LAB_0044f608                                                 XREF[2]:     0044f5c6(j), 0044f5d8(j)
//                              m_ac_obj.cpp:201 (55)
//         0044f608     PUSH       0x194
//         0044f60d     CALL       operator_new                                     void * operator_new(uint param_1)
//         0044f612     ADD        ESP,0x4
//         0044f615     MOV        dword ptr [ESP + param_1],EAX
//         0044f619     TEST       EAX,EAX
//         0044f61b     MOV        dword ptr [ESP + local_4],0x0
//         0044f623     JZ         LAB_0044f653
//         0044f625     MOV        this,dword ptr [ESP + param_4]
//         0044f629     MOV        EDX,dword ptr [ESP + param_3]
//         0044f62d     PUSH       0x1
//         0044f62f     PUSH       this
//         0044f630     MOV        this,dword ptr [ESP + param_2]
//         0044f634     PUSH       EDX
//         0044f635     PUSH       this
//         0044f636     PUSH       EBX
//         0044f637     PUSH       EDI
//         0044f638     MOV        this,EAX
//         0044f63a     CALL       RGE_Action_Object::RGE_Action_Object             undefined RGE_Action_Object(RGE_Action_Object
//                              m_ac_obj.cpp:202 (42)
//         0044f63f     MOV        this,dword ptr [ESP + local_c]
//         0044f643     MOV        dword ptr FS:[0x0],this
//         0044f64a     POP        EDI
//         0044f64b     POP        ESI
//         0044f64c     POP        EBX
//         0044f64d     ADD        ESP,0xc
//         0044f650     RET        0x10
//                               LAB_0044f653                                                 XREF[1]:     0044f623(j)
//         0044f653     MOV        this,dword ptr [ESP + local_c]
//         0044f657     POP        EDI
//         0044f658     POP        ESI
//         0044f659     XOR        EAX,EAX
//         0044f65b     MOV        dword ptr FS:[0x0],this
//         0044f662     POP        EBX
//         0044f663     ADD        ESP,0xc
//         0044f666     RET        0x10
//         0044f669     ??         90h
//         0044f66a     NOP
//         0044f66b     NOP
//         0044f66c     NOP
//         0044f66d     NOP
//         0044f66e     NOP
//         0044f66f     NOP
    return 0;
}

RGE_Task* RGE_Master_Action_Object::get_task(short param_1) {
    /* TODO: Stub */
//                              RGE_Task * __thiscall get_task(RGE_Master_Action_Object * this, shor
//              RGE_Task *        EAX:4          <RETURN>
//              RGE_Master_Act    ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[1]:     0044f6e0(R)
//                               ?get_task@RGE_Master_Action_Object@@QAEPAVRGE_Task@@F@Z      XREF[1]:     set_task:0040694b(c)
//                               RGE_Master_Action_Object::get_task
//                              m_ac_obj.cpp:213 (23)
//         0044f6e0     MOV        DX,word ptr [ESP + param_1]
//         0044f6e5     CMP        DX,-0x1
//         0044f6e9     JZ         LAB_0044f703
//         0044f6eb     MOV        EAX,dword ptr [ECX + this->tasks]
//         0044f6f1     CMP        DX,word ptr [EAX + 0x8]
//         0044f6f5     JGE        LAB_0044f703
//                              m_ac_obj.cpp:215 (9)
//         0044f6f7     MOVSX      this,DX
//         0044f6fa     MOV        EDX,dword ptr [EAX + 0x4]
//         0044f6fd     MOV        EAX,dword ptr [EDX + this->_padding_*0x4]
//                              m_ac_obj.cpp:218 (3)
//         0044f700     RET        0x4
//                               LAB_0044f703                                                 XREF[2]:     0044f6e9(j), 0044f6f5(j)
//                              m_ac_obj.cpp:217 (2)
//         0044f703     XOR        EAX,EAX
//                              m_ac_obj.cpp:218 (3)
//         0044f705     RET        0x4
//         0044f708     ??         90h
//         0044f709     NOP
//         0044f70a     NOP
//         0044f70b     NOP
//         0044f70c     NOP
//         0044f70d     NOP
//         0044f70e     NOP
//         0044f70f     NOP
    return 0;
}

RGE_Task* RGE_Master_Action_Object::getTaskByTaskID(int param_1) {
    /* TODO: Stub */
//                              RGE_Task * __thiscall getTaskByTaskID(RGE_Master_Action_Object * thi
//              RGE_Task *        EAX:4          <RETURN>
//              RGE_Master_Act    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0044f712(R)
//                               ?getTaskByTaskID@RGE_Master_Action_Object@@QBEPAVRGE_Task@@  XREF[1]:     setTaskByTaskID:0040699b(c)
//                               RGE_Master_Action_Object::getTaskByTaskID
//                              m_ac_obj.cpp:223 (2)
//         0044f710     PUSH       EBX
//         0044f711     PUSH       ESI
//                              m_ac_obj.cpp:227 (8)
//         0044f712     MOV        ESI,dword ptr [ESP + param_1]
//         0044f716     PUSH       EDI
//         0044f717     CMP        ESI,-0x1
//                              m_ac_obj.cpp:228 (2)
//         0044f71a     JZ         LAB_0044f754
//                              m_ac_obj.cpp:230 (16)
//         0044f71c     MOV        this,dword ptr [ECX + this->tasks]
//         0044f722     XOR        EAX,EAX
//         0044f724     MOVSX      EDX,word ptr [ECX + this->_padding_]
//         0044f728     TEST       EDX,EDX
//         0044f72a     JLE        LAB_0044f754
//                              m_ac_obj.cpp:231 (3)
//         0044f72c     MOV        EDI,dword ptr [ECX + this->_padding_]
//                              m_ac_obj.cpp:237 (20)
//         0044f72f     MOV        this,EDI
//                               LAB_0044f731                                                 XREF[1]:     0044f741(j)
//         0044f731     MOV        EBX,dword ptr [this->_padding_]
//         0044f733     MOVSX      EBX,word ptr [EBX + 0x6]
//         0044f737     CMP        ESI,EBX
//         0044f739     JZ         LAB_0044f74b
//         0044f73b     INC        EAX
//         0044f73c     ADD        this,0x4
//         0044f73f     CMP        EAX,EDX
//         0044f741     JL         LAB_0044f731
//                              m_ac_obj.cpp:236 (2)
//         0044f743     XOR        EAX,EAX
//                              m_ac_obj.cpp:237 (6)
//         0044f745     POP        EDI
//         0044f746     POP        ESI
//         0044f747     POP        EBX
//         0044f748     RET        0x4
//                               LAB_0044f74b                                                 XREF[1]:     0044f739(j)
//                              m_ac_obj.cpp:232 (3)
//         0044f74b     MOV        EAX,dword ptr [EDI + EAX*0x4]
//                              m_ac_obj.cpp:237 (14)
//         0044f74e     POP        EDI
//         0044f74f     POP        ESI
//         0044f750     POP        EBX
//         0044f751     RET        0x4
//                               LAB_0044f754                                                 XREF[2]:     0044f71a(j), 0044f72a(j)
//         0044f754     POP        EDI
//         0044f755     POP        ESI
//         0044f756     XOR        EAX,EAX
//         0044f758     POP        EBX
//         0044f759     RET        0x4
//         0044f75c     ??         90h
//         0044f75d     NOP
//         0044f75e     NOP
//         0044f75f     NOP
    return 0;
}

void RGE_Master_Action_Object::copy_obj(RGE_Master_Static_Object* param_1) {
    /* TODO: Stub */
//                              void __thiscall copy_obj(RGE_Master_Action_Object * this, RGE_Master
//              void              <VOID>         <RETURN>
//              RGE_Master_Act    ECX:4 (auto)   this
//              RGE_Master_Sta    Stack[0x4]:4   param_1                   XREF[1]:     0044f762(R)
//                               ?copy_obj@RGE_Master_Action_Object@@UAEXPAVRGE_Master_Stati  XREF[2]:     copy_obj:0045081b(c), 0057044c(*)
//                               RGE_Master_Action_Object::copy_obj
//                              m_ac_obj.cpp:242 (2)
//         0044f760     PUSH       ESI
//         0044f761     PUSH       EDI
//                              m_ac_obj.cpp:245 (12)
//         0044f762     MOV        EDI,dword ptr [ESP + param_1]
//         0044f766     MOV        ESI,this
//         0044f768     PUSH       EDI
//         0044f769     CALL       RGE_Master_Moving_Object::copy_obj               void copy_obj(RGE_Master_Moving_Object * this
//                              m_ac_obj.cpp:248 (14)
//         0044f76e     MOV        AX,word ptr [EDI + 0xdc]
//         0044f775     MOV        word ptr [ESI + 0xdc],AX
//                              m_ac_obj.cpp:249 (12)
//         0044f77c     MOV        this,dword ptr [EDI + 0xe0]
//         0044f782     MOV        dword ptr [ESI + 0xe0],this
//                              m_ac_obj.cpp:250 (12)
//         0044f788     MOV        EDX,dword ptr [EDI + 0xe4]
//         0044f78e     MOV        dword ptr [ESI + 0xe4],EDX
//                              m_ac_obj.cpp:251 (14)
//         0044f794     MOV        AX,word ptr [EDI + 0xe8]
//         0044f79b     MOV        word ptr [ESI + 0xe8],AX
//                              m_ac_obj.cpp:252 (14)
//         0044f7a2     MOV        this,word ptr [EDI + 0xea]
//         0044f7a9     MOV        word ptr [ESI + 0xea],this
//                              m_ac_obj.cpp:253 (12)
//         0044f7b0     MOV        DL,byte ptr [EDI + 0xec]
//         0044f7b6     MOV        byte ptr [ESI + 0xec],DL
//                              m_ac_obj.cpp:254 (12)
//         0044f7bc     MOV        EAX,dword ptr [EDI + 0xf0]
//         0044f7c2     MOV        dword ptr [ESI + 0xf0],EAX
//                              m_ac_obj.cpp:255 (12)
//         0044f7c8     MOV        this,dword ptr [EDI + 0xf4]
//         0044f7ce     MOV        dword ptr [ESI + 0xf4],this
//                              m_ac_obj.cpp:258 (18)
//         0044f7d4     MOV        EDX,dword ptr [EDI + 0xd8]
//         0044f7da     MOV        this,dword ptr [ESI + 0xd8]
//         0044f7e0     PUSH       EDX
//         0044f7e1     CALL       RGE_Task_List::copy                              void copy(RGE_Task_List * this, RGE_Task_List
//                              m_ac_obj.cpp:259 (5)
//         0044f7e6     POP        EDI
//         0044f7e7     POP        ESI
//         0044f7e8     RET        0x4
//         0044f7eb     ??         90h
//         0044f7ec     NOP
//         0044f7ed     NOP
//         0044f7ee     NOP
//         0044f7ef     NOP
    return;
}

void RGE_Master_Action_Object::modify(float param_1, uchar param_2) {
    /* TODO: Stub */
//                              void __thiscall modify(RGE_Master_Action_Object * this, float param_
//              void              <VOID>         <RETURN>
//              RGE_Master_Act    ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1                   XREF[2]:     0044f7f9(R), 0044f806(R)
//              uchar             Stack[0x8]:1   param_2                   XREF[1]:     0044f7f0(R)
//                               ?modify@RGE_Master_Action_Object@@UAEXME@Z                   XREF[2]:     modify:00450b00(c), 00570450(*)
//                               RGE_Master_Action_Object::modify
//                              m_ac_obj.cpp:263 (8)
//         0044f7f0     MOV        EAX,dword ptr [ESP + param_2]
//         0044f7f4     CMP        AL,0xd
//         0044f7f6     JZ         LAB_0044f806
//                              m_ac_obj.cpp:270 (11)
//         0044f7f8     PUSH       EAX
//         0044f7f9     MOV        EAX,dword ptr [ESP + param_1]
//         0044f7fd     PUSH       EAX
//         0044f7fe     CALL       RGE_Master_Moving_Object::modify                 void modify(RGE_Master_Moving_Object * this,
//                              m_ac_obj.cpp:272 (3)
//         0044f803     RET        0x8
//                               LAB_0044f806                                                 XREF[1]:     0044f7f6(j)
//                              m_ac_obj.cpp:267 (10)
//         0044f806     MOV        EDX,dword ptr [ESP + param_1]
//         0044f80a     MOV        dword ptr [ECX + this->work_rate],EDX
//                              m_ac_obj.cpp:272 (3)
//         0044f810     RET        0x8
//         0044f813     ??         90h
//         0044f814     NOP
//         0044f815     NOP
//         0044f816     NOP
//         0044f817     NOP
//         0044f818     NOP
//         0044f819     NOP
//         0044f81a     NOP
//         0044f81b     NOP
//         0044f81c     NOP
//         0044f81d     NOP
//         0044f81e     NOP
//         0044f81f     NOP
    return;
}

void RGE_Master_Action_Object::modify_delta(float param_1, uchar param_2) {
    /* TODO: Stub */
//                              void __thiscall modify_delta(RGE_Master_Action_Object * this, float
//              void              <VOID>         <RETURN>
//              RGE_Master_Act    ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1                   XREF[2]:     0044f829(R), 0044f836(R)
//              uchar             Stack[0x8]:1   param_2                   XREF[1]:     0044f820(R)
//                               ?modify_delta@RGE_Master_Action_Object@@UAEXME@Z             XREF[2]:     modify_delta:00450cbc(c),
//                               RGE_Master_Action_Object::modify_delta                                    00570454(*)
//                              m_ac_obj.cpp:276 (8)
//         0044f820     MOV        EAX,dword ptr [ESP + param_2]
//         0044f824     CMP        AL,0xd
//         0044f826     JZ         LAB_0044f836
//                              m_ac_obj.cpp:283 (11)
//         0044f828     PUSH       EAX
//         0044f829     MOV        EAX,dword ptr [ESP + param_1]
//         0044f82d     PUSH       EAX
//         0044f82e     CALL       RGE_Master_Moving_Object::modify_delta           void modify_delta(RGE_Master_Moving_Object *
//                              m_ac_obj.cpp:285 (3)
//         0044f833     RET        0x8
//                               LAB_0044f836                                                 XREF[1]:     0044f826(j)
//                              m_ac_obj.cpp:280 (16)
//         0044f836     FLD        float ptr [ESP + param_1]
//         0044f83a     FADD       float ptr [ECX + this->work_rate]
//         0044f840     FSTP       float ptr [ECX + this->work_rate]
//                              m_ac_obj.cpp:285 (3)
//         0044f846     RET        0x8
//         0044f849     ??         90h
//         0044f84a     NOP
//         0044f84b     NOP
//         0044f84c     NOP
//         0044f84d     NOP
//         0044f84e     NOP
//         0044f84f     NOP
    return;
}

void RGE_Master_Action_Object::modify_percent(float param_1, uchar param_2) {
    /* TODO: Stub */
//                              void __thiscall modify_percent(RGE_Master_Action_Object * this, floa
//              void              <VOID>         <RETURN>
//              RGE_Master_Act    ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1                   XREF[2]:     0044f859(R), 0044f866(R)
//              uchar             Stack[0x8]:1   param_2                   XREF[1]:     0044f850(R)
//                               ?modify_percent@RGE_Master_Action_Object@@UAEXME@Z           XREF[2]:     modify_percent:00450de1(c),
//                               RGE_Master_Action_Object::modify_percent                                  00570458(*)
//                              m_ac_obj.cpp:289 (8)
//         0044f850     MOV        EAX,dword ptr [ESP + param_2]
//         0044f854     CMP        AL,0xd
//         0044f856     JZ         LAB_0044f866
//                              m_ac_obj.cpp:296 (11)
//         0044f858     PUSH       EAX
//         0044f859     MOV        EAX,dword ptr [ESP + param_1]
//         0044f85d     PUSH       EAX
//         0044f85e     CALL       RGE_Master_Moving_Object::modify_percent         void modify_percent(RGE_Master_Moving_Object
//                              m_ac_obj.cpp:298 (3)
//         0044f863     RET        0x8
//                               LAB_0044f866                                                 XREF[1]:     0044f856(j)
//                              m_ac_obj.cpp:293 (16)
//         0044f866     FLD        float ptr [ESP + param_1]
//         0044f86a     FMUL       float ptr [ECX + this->work_rate]
//         0044f870     FSTP       float ptr [ECX + this->work_rate]
//                              m_ac_obj.cpp:298 (3)
//         0044f876     RET        0x8
//         0044f879     ??         90h
//         0044f87a     NOP
//         0044f87b     NOP
//         0044f87c     NOP
//         0044f87d     NOP
//         0044f87e     NOP
//         0044f87f     NOP
    return;
}

void RGE_Master_Action_Object::save(int param_1) {
    /* TODO: Stub */
//                              void __thiscall save(RGE_Master_Action_Object * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_Master_Act    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0044f885(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0044f893(W), 0044f8bc(W), 0044f93c(*)
//              short             Stack[-0x8]:2  move_sound_num            XREF[3]:     0044f88f(W), 0044f8aa(W), 0044f92c(*)
//              short             Stack[-0xc]:2  command_sound_num
//                               ?save@RGE_Master_Action_Object@@UAEXH@Z                      XREF[2]:     save:00450e2a(c), 0057045c(*)
//                               RGE_Master_Action_Object::save
//                              m_ac_obj.cpp:303 (5)
//         0044f880     SUB        ESP,0x8
//         0044f883     PUSH       ESI
//         0044f884     PUSH       EDI
//                              m_ac_obj.cpp:307 (23)
//         0044f885     MOV        EDI,dword ptr [ESP + param_1]
//         0044f889     OR         EAX,0xffffffff
//         0044f88c     MOV        ESI,this
//         0044f88e     PUSH       EDI
//         0044f88f     MOV        dword ptr [ESP + move_sound_num],EAX
//         0044f893     MOV        dword ptr [ESP + local_4],EAX
//         0044f897     CALL       RGE_Master_Moving_Object::save                   void save(RGE_Master_Moving_Object * this, in
//                              m_ac_obj.cpp:309 (10)
//         0044f89c     MOV        EAX,dword ptr [ESI + 0xf0]
//         0044f8a2     TEST       EAX,EAX
//         0044f8a4     JZ         LAB_0044f8ae
//                              m_ac_obj.cpp:310 (8)
//         0044f8a6     MOV        AX,word ptr [EAX + 0xc]
//         0044f8aa     MOV        dword ptr [ESP + move_sound_num],EAX
//                               LAB_0044f8ae                                                 XREF[1]:     0044f8a4(j)
//                              m_ac_obj.cpp:311 (10)
//         0044f8ae     MOV        EAX,dword ptr [ESI + 0xf4]
//         0044f8b4     TEST       EAX,EAX
//         0044f8b6     JZ         LAB_0044f8c0
//                              m_ac_obj.cpp:312 (8)
//         0044f8b8     MOV        this,word ptr [EAX + 0xc]
//         0044f8bc     MOV        dword ptr [ESP + local_4],this
//                               LAB_0044f8c0                                                 XREF[1]:     0044f8b6(j)
//                              m_ac_obj.cpp:315 (18)
//         0044f8c0     LEA        EDX,[ESI + 0xdc]
//         0044f8c6     PUSH       0x2
//         0044f8c8     PUSH       EDX
//         0044f8c9     PUSH       EDI
//         0044f8ca     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0044f8cf     ADD        ESP,0xc
//                              m_ac_obj.cpp:316 (18)
//         0044f8d2     LEA        EAX,[ESI + 0xe0]
//         0044f8d8     PUSH       0x4
//         0044f8da     PUSH       EAX
//         0044f8db     PUSH       EDI
//         0044f8dc     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0044f8e1     ADD        ESP,0xc
//                              m_ac_obj.cpp:317 (18)
//         0044f8e4     LEA        this,[ESI + 0xe4]
//         0044f8ea     PUSH       0x4
//         0044f8ec     PUSH       this
//         0044f8ed     PUSH       EDI
//         0044f8ee     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0044f8f3     ADD        ESP,0xc
//                              m_ac_obj.cpp:318 (18)
//         0044f8f6     LEA        EDX,[ESI + 0xe8]
//         0044f8fc     PUSH       0x2
//         0044f8fe     PUSH       EDX
//         0044f8ff     PUSH       EDI
//         0044f900     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0044f905     ADD        ESP,0xc
//                              m_ac_obj.cpp:319 (18)
//         0044f908     LEA        EAX,[ESI + 0xea]
//         0044f90e     PUSH       0x2
//         0044f910     PUSH       EAX
//         0044f911     PUSH       EDI
//         0044f912     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0044f917     ADD        ESP,0xc
//                              m_ac_obj.cpp:320 (18)
//         0044f91a     LEA        this,[ESI + 0xec]
//         0044f920     PUSH       0x1
//         0044f922     PUSH       this
//         0044f923     PUSH       EDI
//         0044f924     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0044f929     ADD        ESP,0xc
//                              m_ac_obj.cpp:321 (16)
//         0044f92c     LEA        EDX=>move_sound_num,[ESP + 0x8]
//         0044f930     PUSH       0x2
//         0044f932     PUSH       EDX
//         0044f933     PUSH       EDI
//         0044f934     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0044f939     ADD        ESP,0xc
//                              m_ac_obj.cpp:322 (16)
//         0044f93c     LEA        EAX=>local_4,[ESP + 0xc]
//         0044f940     PUSH       0x2
//         0044f942     PUSH       EAX
//         0044f943     PUSH       EDI
//         0044f944     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0044f949     ADD        ESP,0xc
//                              m_ac_obj.cpp:323 (15)
//         0044f94c     LEA        this,[ESI + 0xf8]
//         0044f952     PUSH       0x1
//         0044f954     PUSH       this
//         0044f955     PUSH       EDI
//         0044f956     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              m_ac_obj.cpp:326 (15)
//         0044f95b     MOV        this,dword ptr [ESI + 0xd8]
//         0044f961     ADD        ESP,0xc
//         0044f964     PUSH       EDI
//         0044f965     CALL       RGE_Task_List::save                              void save(RGE_Task_List * this, int param_1)
//                              m_ac_obj.cpp:327 (8)
//         0044f96a     POP        EDI
//         0044f96b     POP        ESI
//         0044f96c     ADD        ESP,0x8
//         0044f96f     RET        0x4
//         0044f972     ??         90h
//         0044f973     NOP
//         0044f974     NOP
//         0044f975     NOP
//         0044f976     NOP
//         0044f977     NOP
//         0044f978     NOP
//         0044f979     NOP
//         0044f97a     NOP
//         0044f97b     NOP
//         0044f97c     NOP
//         0044f97d     NOP
//         0044f97e     NOP
//         0044f97f     NOP
    return;
}

void RGE_Master_Action_Object::play_command_sound() {
    /* TODO: Stub */
//                              void __thiscall play_command_sound(RGE_Master_Action_Object * this)
//              void              <VOID>         <RETURN>
//              RGE_Master_Act    ECX:4 (auto)   this
//                               ?play_command_sound@RGE_Master_Action_Object@@UAEXXZ         XREF[5]:     00570474(*), 005704ec(*),
//                               RGE_Master_Action_Object::play_command_sound                              0057058c(*), 0057672c(*),
//                                                                                                         0057676c(*)
//                              m_ac_obj.cpp:331 (10)
//         0044f980     MOV        this,dword ptr [ECX + this->command_sound]
//         0044f986     TEST       this,this
//         0044f988     JZ         LAB_0044f991
//                              m_ac_obj.cpp:333 (7)
//         0044f98a     PUSH       0x1
//         0044f98c     CALL       RGE_Sound::play                                  void play(RGE_Sound * this, int param_1)
//                               LAB_0044f991                                                 XREF[1]:     0044f988(j)
//                              m_ac_obj.cpp:334 (1)
//         0044f991     RET
//         0044f992     ??         90h
//         0044f993     NOP
//         0044f994     NOP
//         0044f995     NOP
//         0044f996     NOP
//         0044f997     NOP
//         0044f998     NOP
//         0044f999     NOP
//         0044f99a     NOP
//         0044f99b     NOP
//         0044f99c     NOP
//         0044f99d     NOP
//         0044f99e     NOP
//         0044f99f     NOP
    return;
}

void RGE_Master_Action_Object::play_move_sound() {
    /* TODO: Stub */
//                              void __thiscall play_move_sound(RGE_Master_Action_Object * this)
//              void              <VOID>         <RETURN>
//              RGE_Master_Act    ECX:4 (auto)   this
//                               ?play_move_sound@RGE_Master_Action_Object@@UAEXXZ            XREF[5]:     00570478(*), 005704f0(*),
//                               RGE_Master_Action_Object::play_move_sound                                 00570590(*), 00576730(*),
//                                                                                                         00576770(*)
//                              m_ac_obj.cpp:338 (10)
//         0044f9a0     MOV        this,dword ptr [ECX + this->move_sound]
//         0044f9a6     TEST       this,this
//         0044f9a8     JZ         LAB_0044f9b1
//                              m_ac_obj.cpp:340 (7)
//         0044f9aa     PUSH       0x1
//         0044f9ac     CALL       RGE_Sound::play                                  void play(RGE_Sound * this, int param_1)
//                               LAB_0044f9b1                                                 XREF[1]:     0044f9a8(j)
//                              m_ac_obj.cpp:341 (1)
//         0044f9b1     RET
//         0044f9b2     ??         90h
//         0044f9b3     NOP
//         0044f9b4     NOP
//         0044f9b5     NOP
//         0044f9b6     NOP
//         0044f9b7     NOP
//         0044f9b8     NOP
//         0044f9b9     NOP
//         0044f9ba     NOP
//         0044f9bb     NOP
//         0044f9bc     NOP
//         0044f9bd     NOP
//         0044f9be     NOP
//         0044f9bf     NOP
    return;
}

RGE_Master_Static_Object* RGE_Master_Action_Object::make_new_master() {
    /* TODO: Stub */
// <NO ASSEMBLY FOUND>
    return 0;
}

