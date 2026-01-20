// Auto-generated scaffold unit: m_mo_obj.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/m_mo_obj.cpp
#include "../include/common.h"

// Offset: 0x00451A20
undefined RGE_Master_Moving_Object(RGE_Master_Moving_Object* this_, RGE_Master_Moving_Object* param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Master_Moving_Object::RGE_Master_Moving_Object(class RGE_Master_Moving_Obje... *
    //                              *********************************************************************************************************
    //                              undefined __thiscall RGE_Master_Moving_Object(RGE_Master_Moving_Obje
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Master_Mov    ECX:4 (auto)   this
    //              RGE_Master_Mov    Stack[0x4]:4   param_1                   XREF[1]:     00451a38(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     00451a4a(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00451a4e(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00451a68(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00451a41(W)  
    //                               ??0RGE_Master_Moving_Object@@QAE@PAV0@H@Z                    XREF[2]:     RGE_Master_Action_Object:0044f095(
    //                               RGE_Master_Moving_Object::RGE_Master_Moving_Object                        make_new_master:00451efb(c)  
    //                              m_mo_obj.cpp:25 (42)
    //         00451a20     PUSH       -0x1
    //         00451a22     PUSH       FUN_0055d998
    //         00451a27     MOV        EAX,FS:[0x0]
    //         00451a2d     PUSH       EAX
    //         00451a2e     MOV        dword ptr FS:[0x0],ESP
    //         00451a35     PUSH       this
    //         00451a36     PUSH       ESI
    //         00451a37     PUSH       EDI
    //         00451a38     MOV        EDI,dword ptr [ESP + param_1]
    //         00451a3c     MOV        ESI,this
    //         00451a3e     PUSH       0x0
    //         00451a40     PUSH       EDI
    //         00451a41     MOV        dword ptr [ESP + local_10],ESI
    //         00451a45     CALL       RGE_Master_Animated_Object::RGE_Master_Animate   undefined RGE_Master_Animated_Object(RGE_Mast
    //                              m_mo_obj.cpp:26 (22)
    //         00451a4a     MOV        EAX,dword ptr [ESP + param_2]
    //         00451a4e     MOV        dword ptr [ESP + local_4],0x0
    //         00451a56     TEST       EAX,EAX
    //         00451a58     MOV        dword ptr [ESI],RGE_Master_Moving_Object::`vft   = 00451a80
    //         00451a5e     JZ         LAB_00451a68
    //                              m_mo_obj.cpp:27 (8)
    //         00451a60     PUSH       EDI
    //         00451a61     MOV        this,ESI
    //         00451a63     CALL       RGE_Master_Moving_Object::setup                  int setup(RGE_Master_Moving_Object * this, RG
    //                               LAB_00451a68                                                 XREF[1]:     00451a5e(j)  
    //                              m_mo_obj.cpp:28 (21)
    //         00451a68     MOV        this,dword ptr [ESP + local_c]
    //         00451a6c     MOV        EAX,ESI
    //         00451a6e     POP        EDI
    //         00451a6f     MOV        dword ptr FS:[0x0],this
    //         00451a76     POP        ESI
    //         00451a77     ADD        ESP,0x10
    //         00451a7a     RET        0x8
}

// Offset: 0x00451AA0
undefined RGE_Master_Moving_Object(RGE_Master_Moving_Object* this_, int param_2, RGE_Sprite** param_3, RGE_Sound** param_4, int param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Master_Moving_Object::RGE_Master_Moving_Object(int,class RGE_Sprite * *,cla... *
    //                              *********************************************************************************************************
    //                              undefined __thiscall RGE_Master_Moving_Object(RGE_Master_Moving_Obje
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Master_Mov    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00451abc(R)  
    //              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     00451ab7(R)  
    //              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[1]:     00451ac2(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     00451ad6(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00451ada(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00451af6(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00451acd(W)  
    //                               ??0RGE_Master_Moving_Object@@QAE@HPAPAVRGE_Sprite@@PAPAVRGE  XREF[3]:     RGE_Master_Action_Object:0044f121(
    //                               RGE_Master_Moving_Object::RGE_Master_Moving_Object                        load_master_object:00461374(c), 
    //                                                                                                         load_master_object:0046fd44(c)  
    //                              m_mo_obj.cpp:34 (54)
    //         00451aa0     PUSH       -0x1
    //         00451aa2     PUSH       FUN_0055d9b8
    //         00451aa7     MOV        EAX,FS:[0x0]
    //         00451aad     PUSH       EAX
    //         00451aae     MOV        dword ptr FS:[0x0],ESP
    //         00451ab5     PUSH       this
    //         00451ab6     PUSH       EBX
    //         00451ab7     MOV        EBX,dword ptr [ESP + param_2]
    //         00451abb     PUSH       EBP
    //         00451abc     MOV        EBP,dword ptr [ESP + param_1]
    //         00451ac0     PUSH       ESI
    //         00451ac1     PUSH       EDI
    //         00451ac2     MOV        EDI,dword ptr [ESP + param_3]
    //         00451ac6     PUSH       0x0
    //         00451ac8     PUSH       EDI
    //         00451ac9     MOV        ESI,this
    //         00451acb     PUSH       EBX
    //         00451acc     PUSH       EBP
    //         00451acd     MOV        dword ptr [ESP + local_10],ESI
    //         00451ad1     CALL       RGE_Master_Animated_Object::RGE_Master_Animate   undefined RGE_Master_Animated_Object(RGE_Mast
    //                              m_mo_obj.cpp:35 (22)
    //         00451ad6     MOV        EAX,dword ptr [ESP + param_4]
    //         00451ada     MOV        dword ptr [ESP + local_4],0x0
    //         00451ae2     TEST       EAX,EAX
    //         00451ae4     MOV        dword ptr [ESI],RGE_Master_Moving_Object::`vft   = 00451a80
    //         00451aea     JZ         LAB_00451af6
    //                              m_mo_obj.cpp:36 (10)
    //         00451aec     PUSH       EDI
    //         00451aed     PUSH       EBX
    //         00451aee     PUSH       EBP
    //         00451aef     MOV        this,ESI
    //         00451af1     CALL       RGE_Master_Moving_Object::setup                  int setup(RGE_Master_Moving_Object * this, in
    //                               LAB_00451af6                                                 XREF[1]:     00451aea(j)  
    //                              m_mo_obj.cpp:37 (23)
    //         00451af6     MOV        this,dword ptr [ESP + local_c]
    //         00451afa     MOV        EAX,ESI
    //         00451afc     POP        EDI
    //         00451afd     POP        ESI
    //         00451afe     POP        EBP
    //         00451aff     MOV        dword ptr FS:[0x0],this
    //         00451b06     POP        EBX
    //         00451b07     ADD        ESP,0x10
    //         00451b0a     RET        0x10
}

// Offset: 0x00451B10
undefined RGE_Master_Moving_Object(RGE_Master_Moving_Object* this_, FILE* param_2, RGE_Sprite** param_3, RGE_Sound** param_4, short param_5, int param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Master_Moving_Object::RGE_Master_Moving_Object(struct _iobuf *,class RGE_Sp... *
    //                              *********************************************************************************************************
    //                              undefined __thiscall RGE_Master_Moving_Object(RGE_Master_Moving_Obje
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Master_Mov    ECX:4 (auto)   this
    //              _iobuf *          Stack[0x4]:4   param_1                   XREF[2]:     00451b26(R), 00451b61(R)  
    //              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     00451b30(R)  
    //              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[1]:     00451b2b(R)  
    //              short             Stack[0x10]:2  param_4                   XREF[1]:     00451b36(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[1]:     00451b4b(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00451b4f(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00451b70(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00451b42(W)  
    //                               ??0RGE_Master_Moving_Object@@QAE@PAU_iobuf@@PAPAVRGE_Sprite  XREF[2]:     RGE_Master_Action_Object:0044f196(
    //                               RGE_Master_Moving_Object::RGE_Master_Moving_Object                        load_object:00461673(c)  
    //                              m_mo_obj.cpp:43 (59)
    //         00451b10     PUSH       -0x1
    //         00451b12     PUSH       FUN_0055d9d8
    //         00451b17     MOV        EAX,FS:[0x0]
    //         00451b1d     PUSH       EAX
    //         00451b1e     MOV        dword ptr FS:[0x0],ESP
    //         00451b25     PUSH       this
    //         00451b26     MOV        EAX,dword ptr [ESP + param_1]
    //         00451b2a     PUSH       EBX
    //         00451b2b     MOV        EBX,dword ptr [ESP + param_3]
    //         00451b2f     PUSH       EBP
    //         00451b30     MOV        EBP,dword ptr [ESP + param_2]
    //         00451b34     PUSH       ESI
    //         00451b35     PUSH       EDI
    //         00451b36     MOV        EDI,dword ptr [ESP + param_4]
    //         00451b3a     PUSH       0x0
    //         00451b3c     PUSH       EDI
    //         00451b3d     PUSH       EBX
    //         00451b3e     MOV        ESI,this
    //         00451b40     PUSH       EBP
    //         00451b41     PUSH       EAX
    //         00451b42     MOV        dword ptr [ESP + local_10],ESI
    //         00451b46     CALL       RGE_Master_Animated_Object::RGE_Master_Animate   undefined RGE_Master_Animated_Object(RGE_Mast
    //                              m_mo_obj.cpp:44 (22)
    //         00451b4b     MOV        EAX,dword ptr [ESP + param_5]
    //         00451b4f     MOV        dword ptr [ESP + local_4],0x0
    //         00451b57     TEST       EAX,EAX
    //         00451b59     MOV        dword ptr [ESI],RGE_Master_Moving_Object::`vft   = 00451a80
    //         00451b5f     JZ         LAB_00451b70
    //                              m_mo_obj.cpp:45 (15)
    //         00451b61     MOV        this,dword ptr [ESP + param_1]
    //         00451b65     PUSH       EDI
    //         00451b66     PUSH       EBX
    //         00451b67     PUSH       EBP
    //         00451b68     PUSH       this
    //         00451b69     MOV        this,ESI
    //         00451b6b     CALL       RGE_Master_Moving_Object::setup                  int setup(RGE_Master_Moving_Object * this, _i
    //                               LAB_00451b70                                                 XREF[1]:     00451b5f(j)  
    //                              m_mo_obj.cpp:46 (23)
    //         00451b70     MOV        this,dword ptr [ESP + local_c]
    //         00451b74     MOV        EAX,ESI
    //         00451b76     POP        EDI
    //         00451b77     POP        ESI
    //         00451b78     POP        EBP
    //         00451b79     MOV        dword ptr FS:[0x0],this
    //         00451b80     POP        EBX
    //         00451b81     ADD        ESP,0x10
    //         00451b84     RET        0x14
}

// Offset: 0x00451B90
int setup(RGE_Master_Moving_Object* this_, RGE_Master_Moving_Object* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: int __thiscall RGE_Master_Moving_Object::setup(class RGE_Master_Moving_Object *)           *
    //                              *********************************************************************************************************
    //                              int __thiscall setup(RGE_Master_Moving_Object * this, RGE_Master_Mov
    //              int               EAX:4          <RETURN>
    //              RGE_Master_Mov    ECX:4 (auto)   this
    //              RGE_Master_Mov    Stack[0x4]:4   param_1                   XREF[1]:     00451b92(R)  
    //                               ?setup@RGE_Master_Moving_Object@@IAEHPAV1@@Z                 XREF[2]:     setup:0044f1e9(c), 
    //                               RGE_Master_Moving_Object::setup                                           RGE_Master_Moving_Object:00451a63(
    //                              m_mo_obj.cpp:51 (2)
    //         00451b90     PUSH       ESI
    //         00451b91     PUSH       EDI
    //                              m_mo_obj.cpp:52 (12)
    //         00451b92     MOV        EDI,dword ptr [ESP + param_1]
    //         00451b96     MOV        ESI,this
    //         00451b98     PUSH       EDI
    //         00451b99     CALL       RGE_Master_Animated_Object::setup                int setup(RGE_Master_Animated_Object * this, 
    //                              m_mo_obj.cpp:54 (4)
    //         00451b9e     MOV        byte ptr [ESI + 0x4],0x1e
    //                              m_mo_obj.cpp:57 (12)
    //         00451ba2     MOV        EAX,dword ptr [EDI + 0xbc]
    //         00451ba8     MOV        dword ptr [ESI + 0xbc],EAX
    //                              m_mo_obj.cpp:58 (12)
    //         00451bae     MOV        this,dword ptr [EDI + 0xc0]
    //         00451bb4     MOV        dword ptr [ESI + 0xc0],this
    //                              m_mo_obj.cpp:59 (12)
    //         00451bba     MOV        EDX,dword ptr [EDI + 0xc4]
    //         00451bc0     MOV        dword ptr [ESI + 0xc4],EDX
    //                              m_mo_obj.cpp:60 (12)
    //         00451bc6     MOV        AL,byte ptr [EDI + 0xc8]
    //         00451bcc     MOV        byte ptr [ESI + 0xc8],AL
    //                              m_mo_obj.cpp:61 (14)
    //         00451bd2     MOV        this,word ptr [EDI + 0xca]
    //         00451bd9     MOV        word ptr [ESI + 0xca],this
    //                              m_mo_obj.cpp:62 (12)
    //         00451be0     MOV        DL,byte ptr [EDI + 0xcc]
    //         00451be6     MOV        byte ptr [ESI + 0xcc],DL
    //                              m_mo_obj.cpp:63 (12)
    //         00451bec     MOV        EAX,dword ptr [EDI + 0xd0]
    //         00451bf2     MOV        dword ptr [ESI + 0xd0],EAX
    //                              m_mo_obj.cpp:64 (12)
    //         00451bf8     MOV        this,byte ptr [EDI + 0xd4]
    //         00451bfe     MOV        byte ptr [ESI + 0xd4],this
    //                              m_mo_obj.cpp:67 (10)
    //         00451c04     POP        EDI
    //         00451c05     MOV        EAX,0x1
    //         00451c0a     POP        ESI
    //         00451c0b     RET        0x4
}

// Offset: 0x00451C10
int setup(RGE_Master_Moving_Object* this_, int param_2, RGE_Sprite** param_3, RGE_Sound** param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: int __thiscall RGE_Master_Moving_Object::setup(int,class RGE_Sprite * *,class RGE_Sound... *
    //                              *********************************************************************************************************
    //                              int __thiscall setup(RGE_Master_Moving_Object * this, int param_1, R
    //              int               EAX:4          <RETURN>
    //              RGE_Master_Mov    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00451c1b(R)  
    //              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[3]:     00451c15(R), 00451c3d(*), 00451cd3(R)  
    //              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[3]:     00451c10(R), 00451c29(*), 00451cb6(R)  
    //                               ?setup@RGE_Master_Moving_Object@@IAEHHPAPAVRGE_Sprite@@PAPA  XREF[2]:     setup:0044f2a5(c), 
    //                               RGE_Master_Moving_Object::setup                                           RGE_Master_Moving_Object:00451af1(
    //                              m_mo_obj.cpp:72 (25)
    //         00451c10     MOV        EAX,dword ptr [ESP + param_3]
    //         00451c14     PUSH       EBX
    //         00451c15     MOV        EBX,dword ptr [ESP + param_2]
    //         00451c19     PUSH       ESI
    //         00451c1a     PUSH       EDI
    //         00451c1b     MOV        EDI,dword ptr [ESP + param_1]
    //         00451c1f     PUSH       EAX
    //         00451c20     PUSH       EBX
    //         00451c21     MOV        ESI,this
    //         00451c23     PUSH       EDI
    //         00451c24     CALL       RGE_Master_Animated_Object::setup                int setup(RGE_Master_Animated_Object * this, 
    //                              m_mo_obj.cpp:81 (20)
    //         00451c29     LEA        this=>param_3,[ESP + 0x18]
    //         00451c2d     PUSH       0x2
    //         00451c2f     PUSH       this
    //         00451c30     PUSH       EDI
    //         00451c31     MOV        byte ptr [ESI + 0x4],0x1e
    //         00451c35     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00451c3a     ADD        ESP,0xc
    //                              m_mo_obj.cpp:82 (16)
    //         00451c3d     LEA        EDX=>param_2,[ESP + 0x14]
    //         00451c41     PUSH       0x2
    //         00451c43     PUSH       EDX
    //         00451c44     PUSH       EDI
    //         00451c45     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00451c4a     ADD        ESP,0xc
    //                              m_mo_obj.cpp:83 (18)
    //         00451c4d     LEA        EAX,[ESI + 0xc4]
    //         00451c53     PUSH       0x4
    //         00451c55     PUSH       EAX
    //         00451c56     PUSH       EDI
    //         00451c57     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00451c5c     ADD        ESP,0xc
    //                              m_mo_obj.cpp:84 (18)
    //         00451c5f     LEA        this,[ESI + 0xc8]
    //         00451c65     PUSH       0x1
    //         00451c67     PUSH       this
    //         00451c68     PUSH       EDI
    //         00451c69     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00451c6e     ADD        ESP,0xc
    //                              m_mo_obj.cpp:85 (18)
    //         00451c71     LEA        EDX,[ESI + 0xca]
    //         00451c77     PUSH       0x2
    //         00451c79     PUSH       EDX
    //         00451c7a     PUSH       EDI
    //         00451c7b     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00451c80     ADD        ESP,0xc
    //                              m_mo_obj.cpp:86 (18)
    //         00451c83     LEA        EAX,[ESI + 0xcc]
    //         00451c89     PUSH       0x1
    //         00451c8b     PUSH       EAX
    //         00451c8c     PUSH       EDI
    //         00451c8d     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00451c92     ADD        ESP,0xc
    //                              m_mo_obj.cpp:87 (18)
    //         00451c95     LEA        this,[ESI + 0xd0]
    //         00451c9b     PUSH       0x4
    //         00451c9d     PUSH       this
    //         00451c9e     PUSH       EDI
    //         00451c9f     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00451ca4     ADD        ESP,0xc
    //                              m_mo_obj.cpp:88 (15)
    //         00451ca7     LEA        EDX,[ESI + 0xd4]
    //         00451cad     PUSH       0x1
    //         00451caf     PUSH       EDX
    //         00451cb0     PUSH       EDI
    //         00451cb1     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              m_mo_obj.cpp:90 (29)
    //         00451cb6     MOV        AX,word ptr [ESP + param_3]
    //         00451cbb     ADD        ESP,0xc
    //         00451cbe     TEST       AX,AX
    //         00451cc1     JL         LAB_00451ccb
    //         00451cc3     MOVSX      EAX,AX
    //         00451cc6     MOV        EAX,dword ptr [EBX + EAX*0x4]
    //         00451cc9     JMP        LAB_00451ccd
    //                               LAB_00451ccb                                                 XREF[1]:     00451cc1(j)  
    //         00451ccb     XOR        EAX,EAX
    //                               LAB_00451ccd                                                 XREF[1]:     00451cc9(j)  
    //         00451ccd     MOV        dword ptr [ESI + 0xbc],EAX
    //                              m_mo_obj.cpp:91 (13)
    //         00451cd3     MOV        AX,word ptr [ESP + param_2]
    //         00451cd8     TEST       AX,AX
    //         00451cdb     JL         LAB_00451cf4
    //         00451cdd     MOVSX      this,AX
    //                              m_mo_obj.cpp:93 (14)
    //         00451ce0     MOV        EAX,0x1
    //         00451ce5     MOV        EBX,dword ptr [EBX + this->_padding_*0x4]
    //         00451ce8     MOV        dword ptr [ESI + 0xc0],EBX
    //                              m_mo_obj.cpp:94 (6)
    //         00451cee     POP        EDI
    //         00451cef     POP        ESI
    //         00451cf0     POP        EBX
    //         00451cf1     RET        0xc
    //                               LAB_00451cf4                                                 XREF[1]:     00451cdb(j)  
    //                              m_mo_obj.cpp:91 (2)
    //         00451cf4     XOR        EBX,EBX
    //                              m_mo_obj.cpp:94 (17)
    //         00451cf6     POP        EDI
    //         00451cf7     MOV        dword ptr [ESI + 0xc0],EBX
    //         00451cfd     POP        ESI
    //         00451cfe     MOV        EAX,0x1
    //         00451d03     POP        EBX
    //         00451d04     RET        0xc
}

// Offset: 0x00451D10
int setup(RGE_Master_Moving_Object* this_, FILE* param_2, RGE_Sprite** param_3, RGE_Sound** param_4, short param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: int __thiscall RGE_Master_Moving_Object::setup(struct _iobuf *,class RGE_Sprite * *,cla... *
    //                              *********************************************************************************************************
    //                              int __thiscall setup(RGE_Master_Moving_Object * this, _iobuf * param
    //              int               EAX:4          <RETURN>
    //              RGE_Master_Mov    ECX:4 (auto)   this
    //              _iobuf *          Stack[0x4]:4   param_1                   XREF[3]:     00451d22(R), 00451d59(*), 00451d80(R)  
    //              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[3]:     00451d16(R), 00451d3c(*), 00451d6e(R)  
    //              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[3]:     00451d1e(R), 00451d31(*), 00451d76(R)  
    //              short             Stack[0x10]:2  param_4                   XREF[3]:     00451d11(R), 00451d48(*), 00451d72(R)  
    //              undefined2        Stack[-0x2]:2  local_2                   XREF[2]:     00451d54(*), 00451da9(R)  
    //              short             Stack[-0x6]:2  temp_run_sprite
    //                               ?setup@RGE_Master_Moving_Object@@IAEHPAU_iobuf@@PAPAVRGE_Sp  XREF[2]:     setup:0044f3da(c), 
    //                               RGE_Master_Moving_Object::setup                                           RGE_Master_Moving_Object:00451b6b(
    //                              m_mo_obj.cpp:99 (1)
    //         00451d10     PUSH       this
    //                              m_mo_obj.cpp:106 (32)
    //         00451d11     MOV        EAX,dword ptr [ESP + param_4]
    //         00451d15     PUSH       EBX
    //         00451d16     MOV        EBX,dword ptr [ESP + param_2]
    //         00451d1a     PUSH       ESI
    //         00451d1b     MOV        ESI,this
    //         00451d1d     PUSH       EDI
    //         00451d1e     MOV        this,dword ptr [ESP + param_3]
    //         00451d22     MOV        EDI,dword ptr [ESP + param_1]
    //         00451d26     PUSH       EAX
    //         00451d27     PUSH       this
    //         00451d28     PUSH       EBX
    //         00451d29     PUSH       EDI
    //         00451d2a     MOV        this,ESI
    //         00451d2c     CALL       RGE_Master_Animated_Object::setup                int setup(RGE_Master_Animated_Object * this, 
    //                              m_mo_obj.cpp:119 (61)
    //         00451d31     LEA        EDX=>param_3,[ESP + 0x1c]
    //         00451d35     LEA        EAX,[ESI + 0xd0]
    //         00451d3b     PUSH       EDX
    //         00451d3c     LEA        this=>param_2,[ESP + 0x1c]
    //         00451d40     PUSH       EAX
    //         00451d41     LEA        EDX,[ESI + 0xca]
    //         00451d47     PUSH       this
    //         00451d48     LEA        EAX=>param_4,[ESP + 0x2c]
    //         00451d4c     PUSH       EDX
    //         00451d4d     LEA        this,[ESI + 0xc4]
    //         00451d53     PUSH       EAX
    //         00451d54     LEA        EDX=>local_2,[ESP + 0x22]
    //         00451d58     PUSH       this
    //         00451d59     LEA        EAX=>param_1,[ESP + 0x2c]
    //         00451d5d     PUSH       EDX
    //         00451d5e     PUSH       EAX
    //         00451d5f     PUSH       s_%hd_%hd_%f_%hd_%hd_%hd_%f_%hd                  = "%hd %hd %f %hd %hd %hd %f %hd"
    //         00451d64     PUSH       EDI
    //         00451d65     MOV        byte ptr [ESI + 0x4],0x1e
    //         00451d69     CALL       fscanf                                           undefined fscanf()
    //                              m_mo_obj.cpp:125 (18)
    //         00451d6e     MOV        AL,byte ptr [ESP + param_2]
    //         00451d72     MOV        this,byte ptr [ESP + param_4]
    //         00451d76     MOV        DL,byte ptr [ESP + param_3]
    //         00451d7a     MOV        byte ptr [ESI + 0xcc],AL
    //                              m_mo_obj.cpp:126 (41)
    //         00451d80     MOV        AX,word ptr [ESP + param_1]
    //         00451d85     ADD        ESP,0x28
    //         00451d88     TEST       AX,AX
    //         00451d8b     MOV        byte ptr [ESI + 0xc8],this
    //         00451d91     MOV        byte ptr [ESI + 0xd4],DL
    //         00451d97     JL         LAB_00451da1
    //         00451d99     MOVSX      this,AX
    //         00451d9c     MOV        EAX,dword ptr [EBX + this->_padding_*0x4]
    //         00451d9f     JMP        LAB_00451da3
    //                               LAB_00451da1                                                 XREF[1]:     00451d97(j)  
    //         00451da1     XOR        EAX,EAX
    //                               LAB_00451da3                                                 XREF[1]:     00451d9f(j)  
    //         00451da3     MOV        dword ptr [ESI + 0xbc],EAX
    //                              m_mo_obj.cpp:127 (13)
    //         00451da9     MOV        AX,word ptr [ESP + local_2]
    //         00451dae     TEST       AX,AX
    //         00451db1     JL         LAB_00451dcb
    //         00451db3     MOVSX      EDX,AX
    //                              m_mo_obj.cpp:129 (14)
    //         00451db6     MOV        EAX,0x1
    //         00451dbb     MOV        EBX,dword ptr [EBX + EDX*0x4]
    //         00451dbe     MOV        dword ptr [ESI + 0xc0],EBX
    //                              m_mo_obj.cpp:130 (7)
    //         00451dc4     POP        EDI
    //         00451dc5     POP        ESI
    //         00451dc6     POP        EBX
    //         00451dc7     POP        this
    //         00451dc8     RET        0x10
    //                               LAB_00451dcb                                                 XREF[1]:     00451db1(j)  
    //                              m_mo_obj.cpp:127 (2)
    //         00451dcb     XOR        EBX,EBX
    //                              m_mo_obj.cpp:130 (18)
    //         00451dcd     POP        EDI
    //         00451dce     MOV        dword ptr [ESI + 0xc0],EBX
    //         00451dd4     POP        ESI
    //         00451dd5     MOV        EAX,0x1
    //         00451dda     POP        EBX
    //         00451ddb     POP        this
    //         00451ddc     RET        0x10
}

// Offset: 0x00451DE0
void RGE_Master_Moving_Object(RGE_Master_Moving_Object* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall RGE_Master_Moving_Object::~RGE_Master_Moving_Object(void)                  *
    //                              *********************************************************************************************************
    //                              void __thiscall ~RGE_Master_Moving_Object(RGE_Master_Moving_Object *
    //              void              <VOID>         <RETURN>
    //              RGE_Master_Mov    ECX:4 (auto)   this
    //                               ??1RGE_Master_Moving_Object@@UAE@XZ                          XREF[2]:     ~RGE_Master_Action_Object:0044f52a
    //                               RGE_Master_Moving_Object::~RGE_Master_Moving_Object                       `vector_deleting_destructor':00451
    //                              m_mo_obj.cpp:135 (11)
    //         00451de0     MOV        dword ptr [this->_padding_],RGE_Master_Moving_   = 00451a80
    //         00451de6     JMP        RGE_Master_Animated_Object::~RGE_Master_Animat   void ~RGE_Master_Animated_Object(RGE_Master_A
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x00451DF0
RGE_Static_Object* RGE_Master_Moving_Object::make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual class RGE_Static_Object * __thiscall RGE_Master_Moving_Object::make_new_obj(class ... *
    //                              *********************************************************************************************************
    //                              RGE_Static_Object * __thiscall make_new_obj(RGE_Master_Moving_Object
    //              RGE_Static_Obj    EAX:4          <RETURN>
    //              RGE_Master_Mov    ECX:4 (auto)   this
    //              RGE_Player *      Stack[0x4]:4   param_1                   XREF[2]:     00451e07(R), 00451e65(W)  
    //              float             Stack[0x8]:4   param_2                   XREF[2]:     00451e35(R), 00451e80(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[2]:     00451e2e(R), 00451e79(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[2]:     00451e2a(R), 00451e75(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00451e6b(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     00451e8f(R), 00451ea3(R)  
    //                               ?make_new_obj@RGE_Master_Moving_Object@@UAEPAVRGE_Static_Ob  XREF[1]:     005705b8(*)  
    //                               RGE_Master_Moving_Object::make_new_obj
    //                              m_mo_obj.cpp:141 (23)
    //         00451df0     MOV        EAX,FS:[0x0]
    //         00451df6     PUSH       -0x1
    //         00451df8     PUSH       FUN_0055d9fb
    //         00451dfd     PUSH       EAX
    //         00451dfe     MOV        dword ptr FS:[0x0],ESP
    //         00451e05     PUSH       EBX
    //         00451e06     PUSH       ESI
    //                              m_mo_obj.cpp:144 (17)
    //         00451e07     MOV        EBX,dword ptr [ESP + param_1]
    //         00451e0b     PUSH       EDI
    //         00451e0c     MOV        EDI,this
    //         00451e0e     MOV        AL,byte ptr [EDI + 0xa4]
    //         00451e14     TEST       AL,AL
    //         00451e16     JZ         LAB_00451e58
    //                              m_mo_obj.cpp:146 (14)
    //         00451e18     MOV        AL,byte ptr [EDI + 0x4]
    //         00451e1b     MOV        this,dword ptr [EBX + 0x3c]
    //         00451e1e     PUSH       EAX
    //         00451e1f     CALL       RGE_Game_World::recycle_object_in_to_game        RGE_Static_Object * recycle_object_in_to_game
    //         00451e24     MOV        ESI,EAX
    //                              m_mo_obj.cpp:147 (4)
    //         00451e26     TEST       ESI,ESI
    //         00451e28     JZ         LAB_00451e58
    //                              m_mo_obj.cpp:149 (24)
    //         00451e2a     MOV        EAX,dword ptr [ESP + param_4]
    //         00451e2e     MOV        this,dword ptr [ESP + param_3]
    //         00451e32     MOV        EDX,dword ptr [ESI]
    //         00451e34     PUSH       EAX
    //         00451e35     MOV        EAX,dword ptr [ESP + param_2]
    //         00451e39     PUSH       this
    //         00451e3a     PUSH       EAX
    //         00451e3b     PUSH       EBX
    //         00451e3c     PUSH       EDI
    //         00451e3d     MOV        this,ESI
    //         00451e3f     CALL       dword ptr [EDX + 0x4]
    //                              m_mo_obj.cpp:150 (2)
    //         00451e42     MOV        EAX,ESI
    //                              m_mo_obj.cpp:155 (20)
    //         00451e44     MOV        this,dword ptr [ESP + 0xc]
    //         00451e48     MOV        dword ptr FS:[0x0],this
    //         00451e4f     POP        EDI
    //         00451e50     POP        ESI
    //         00451e51     POP        EBX
    //         00451e52     ADD        ESP,0xc
    //         00451e55     RET        0x10
    //                               LAB_00451e58                                                 XREF[2]:     00451e16(j), 00451e28(j)  
    //                              m_mo_obj.cpp:154 (55)
    //         00451e58     PUSH       0x180
    //         00451e5d     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00451e62     ADD        ESP,0x4
    //         00451e65     MOV        dword ptr [ESP + param_1],EAX
    //         00451e69     TEST       EAX,EAX
    //         00451e6b     MOV        dword ptr [ESP + local_4],0x0
    //         00451e73     JZ         LAB_00451ea3
    //         00451e75     MOV        this,dword ptr [ESP + param_4]
    //         00451e79     MOV        EDX,dword ptr [ESP + param_3]
    //         00451e7d     PUSH       0x1
    //         00451e7f     PUSH       this
    //         00451e80     MOV        this,dword ptr [ESP + param_2]
    //         00451e84     PUSH       EDX
    //         00451e85     PUSH       this
    //         00451e86     PUSH       EBX
    //         00451e87     PUSH       EDI
    //         00451e88     MOV        this,EAX
    //         00451e8a     CALL       RGE_Moving_Object::RGE_Moving_Object             undefined RGE_Moving_Object(RGE_Moving_Object
    //                              m_mo_obj.cpp:155 (42)
    //         00451e8f     MOV        this,dword ptr [ESP + local_c]
    //         00451e93     MOV        dword ptr FS:[0x0],this
    //         00451e9a     POP        EDI
    //         00451e9b     POP        ESI
    //         00451e9c     POP        EBX
    //         00451e9d     ADD        ESP,0xc
    //         00451ea0     RET        0x10
    //                               LAB_00451ea3                                                 XREF[1]:     00451e73(j)  
    //         00451ea3     MOV        this,dword ptr [ESP + local_c]
    //         00451ea7     POP        EDI
    //         00451ea8     POP        ESI
    //         00451ea9     XOR        EAX,EAX
    //         00451eab     MOV        dword ptr FS:[0x0],this
    //         00451eb2     POP        EBX
    //         00451eb3     ADD        ESP,0xc
    //         00451eb6     RET        0x10
}

// Offset: 0x00451EC0
RGE_Master_Static_Object* RGE_Master_Moving_Object::make_new_master() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual class RGE_Master_Static_Object * __thiscall RGE_Master_Moving_Object::make_new_mas... *
    //                              *********************************************************************************************************
    //                              RGE_Master_Static_Object * __thiscall make_new_master(RGE_Master_Mov
    //              RGE_Master_Sta    EAX:4          <RETURN>
    //              RGE_Master_Mov    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00451eec(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     00451f00(R), 00451f10(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00451ee6(W)  
    //                               ?make_new_master@RGE_Master_Moving_Object@@UAEPAVRGE_Master  XREF[1]:     005705bc(*)  
    //                               RGE_Master_Moving_Object::make_new_master
    //                              m_mo_obj.cpp:160 (25)
    //         00451ec0     PUSH       -0x1
    //         00451ec2     PUSH       FUN_0055da1b
    //         00451ec7     MOV        EAX,FS:[0x0]
    //         00451ecd     PUSH       EAX
    //         00451ece     MOV        dword ptr FS:[0x0],ESP
    //         00451ed5     PUSH       this
    //         00451ed6     PUSH       ESI
    //         00451ed7     MOV        ESI,this
    //                              m_mo_obj.cpp:161 (39)
    //         00451ed9     PUSH       0xd8
    //         00451ede     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00451ee3     ADD        ESP,0x4
    //         00451ee6     MOV        dword ptr [ESP + local_10],EAX
    //         00451eea     TEST       EAX,EAX
    //         00451eec     MOV        dword ptr [ESP + local_4],0x0
    //         00451ef4     JZ         LAB_00451f10
    //         00451ef6     PUSH       0x1
    //         00451ef8     PUSH       ESI
    //         00451ef9     MOV        this,EAX
    //         00451efb     CALL       RGE_Master_Moving_Object::RGE_Master_Moving_Ob   undefined RGE_Master_Moving_Object(RGE_Master
    //                              m_mo_obj.cpp:162 (34)
    //         00451f00     MOV        this,dword ptr [ESP + local_c]
    //         00451f04     MOV        dword ptr FS:[0x0],this
    //         00451f0b     POP        ESI
    //         00451f0c     ADD        ESP,0x10
    //         00451f0f     RET
    //                               LAB_00451f10                                                 XREF[1]:     00451ef4(j)  
    //         00451f10     MOV        this,dword ptr [ESP + local_c]
    //         00451f14     XOR        EAX,EAX
    //         00451f16     MOV        dword ptr FS:[0x0],this
    //         00451f1d     POP        ESI
    //         00451f1e     ADD        ESP,0x10
    //         00451f21     RET
}

// Offset: 0x00451F30
void RGE_Master_Moving_Object::copy_obj(RGE_Master_Static_Object* param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Master_Moving_Object::copy_obj(class RGE_Master_Static_Object *)  *
    //                              *********************************************************************************************************
    //                              void __thiscall copy_obj(RGE_Master_Moving_Object * this, RGE_Master
    //              void              <VOID>         <RETURN>
    //              RGE_Master_Mov    ECX:4 (auto)   this
    //              RGE_Master_Sta    Stack[0x4]:4   param_1                   XREF[1]:     00451f32(R)  
    //                               ?copy_obj@RGE_Master_Moving_Object@@UAEXPAVRGE_Master_Stati  XREF[2]:     copy_obj:0044f769(c), 005705a4(*)  
    //                               RGE_Master_Moving_Object::copy_obj
    //                              m_mo_obj.cpp:167 (2)
    //         00451f30     PUSH       ESI
    //         00451f31     PUSH       EDI
    //                              m_mo_obj.cpp:170 (12)
    //         00451f32     MOV        EDI,dword ptr [ESP + param_1]
    //         00451f36     MOV        ESI,this
    //         00451f38     PUSH       EDI
    //         00451f39     CALL       RGE_Master_Animated_Object::copy_obj             void copy_obj(RGE_Master_Animated_Object * th
    //                              m_mo_obj.cpp:172 (12)
    //         00451f3e     MOV        EAX,dword ptr [EDI + 0xbc]
    //         00451f44     MOV        dword ptr [ESI + 0xbc],EAX
    //                              m_mo_obj.cpp:173 (12)
    //         00451f4a     MOV        this,dword ptr [EDI + 0xc0]
    //         00451f50     MOV        dword ptr [ESI + 0xc0],this
    //                              m_mo_obj.cpp:174 (12)
    //         00451f56     MOV        EDX,dword ptr [EDI + 0xc4]
    //         00451f5c     MOV        dword ptr [ESI + 0xc4],EDX
    //                              m_mo_obj.cpp:175 (12)
    //         00451f62     MOV        AL,byte ptr [EDI + 0xc8]
    //         00451f68     MOV        byte ptr [ESI + 0xc8],AL
    //                              m_mo_obj.cpp:176 (14)
    //         00451f6e     MOV        this,word ptr [EDI + 0xca]
    //         00451f75     MOV        word ptr [ESI + 0xca],this
    //                              m_mo_obj.cpp:177 (12)
    //         00451f7c     MOV        DL,byte ptr [EDI + 0xcc]
    //         00451f82     MOV        byte ptr [ESI + 0xcc],DL
    //                              m_mo_obj.cpp:178 (12)
    //         00451f88     MOV        EAX,dword ptr [EDI + 0xd0]
    //         00451f8e     MOV        dword ptr [ESI + 0xd0],EAX
    //                              m_mo_obj.cpp:179 (12)
    //         00451f94     MOV        this,byte ptr [EDI + 0xd4]
    //         00451f9a     MOV        byte ptr [ESI + 0xd4],this
    //                              m_mo_obj.cpp:180 (5)
    //         00451fa0     POP        EDI
    //         00451fa1     POP        ESI
    //         00451fa2     RET        0x4
}

// Offset: 0x00451FB0
void RGE_Master_Moving_Object::modify(float param_1, uchar param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Master_Moving_Object::modify(float,unsigned char)                 *
    //                              *********************************************************************************************************
    //                              void __thiscall modify(RGE_Master_Moving_Object * this, float param_
    //              void              <VOID>         <RETURN>
    //              RGE_Master_Mov    ECX:4 (auto)   this
    //              float             Stack[0x4]:4   param_1                   XREF[2]:     00451fb9(R), 00451fc6(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[1]:     00451fb0(R)  
    //                               ?modify@RGE_Master_Moving_Object@@UAEXME@Z                   XREF[2]:     modify:0044f7fe(c), 005705a8(*)  
    //                               RGE_Master_Moving_Object::modify
    //                              m_mo_obj.cpp:184 (8)
    //         00451fb0     MOV        EAX,dword ptr [ESP + param_2]
    //         00451fb4     CMP        AL,0x6
    //         00451fb6     JZ         LAB_00451fc6
    //                              m_mo_obj.cpp:191 (11)
    //         00451fb8     PUSH       EAX
    //         00451fb9     MOV        EAX,dword ptr [ESP + param_1]
    //         00451fbd     PUSH       EAX
    //         00451fbe     CALL       RGE_Master_Animated_Object::modify               void modify(RGE_Master_Animated_Object * this
    //                              m_mo_obj.cpp:194 (3)
    //         00451fc3     RET        0x8
    //                               LAB_00451fc6                                                 XREF[1]:     00451fb6(j)  
    //                              m_mo_obj.cpp:188 (10)
    //         00451fc6     MOV        EDX,dword ptr [ESP + param_1]
    //         00451fca     MOV        dword ptr [ECX + this->turn_speed],EDX
    //                              m_mo_obj.cpp:194 (3)
    //         00451fd0     RET        0x8
}

// Offset: 0x00451FE0
void RGE_Master_Moving_Object::modify_delta(float param_1, uchar param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Master_Moving_Object::modify_delta(float,unsigned char)           *
    //                              *********************************************************************************************************
    //                              void __thiscall modify_delta(RGE_Master_Moving_Object * this, float 
    //              void              <VOID>         <RETURN>
    //              RGE_Master_Mov    ECX:4 (auto)   this
    //              float             Stack[0x4]:4   param_1                   XREF[2]:     00451fe9(R), 00451ff6(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[1]:     00451fe0(R)  
    //                               ?modify_delta@RGE_Master_Moving_Object@@UAEXME@Z             XREF[2]:     modify_delta:0044f82e(c), 
    //                               RGE_Master_Moving_Object::modify_delta                                    005705ac(*)  
    //                              m_mo_obj.cpp:198 (8)
    //         00451fe0     MOV        EAX,dword ptr [ESP + param_2]
    //         00451fe4     CMP        AL,0x6
    //         00451fe6     JZ         LAB_00451ff6
    //                              m_mo_obj.cpp:205 (11)
    //         00451fe8     PUSH       EAX
    //         00451fe9     MOV        EAX,dword ptr [ESP + param_1]
    //         00451fed     PUSH       EAX
    //         00451fee     CALL       RGE_Master_Animated_Object::modify_delta         void modify_delta(RGE_Master_Animated_Object 
    //                              m_mo_obj.cpp:208 (3)
    //         00451ff3     RET        0x8
    //                               LAB_00451ff6                                                 XREF[1]:     00451fe6(j)  
    //                              m_mo_obj.cpp:202 (16)
    //         00451ff6     FLD        float ptr [ESP + param_1]
    //         00451ffa     FADD       float ptr [ECX + this->turn_speed]
    //         00452000     FSTP       float ptr [ECX + this->turn_speed]
    //                              m_mo_obj.cpp:208 (3)
    //         00452006     RET        0x8
}

// Offset: 0x00452010
void RGE_Master_Moving_Object::modify_percent(float param_1, uchar param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Master_Moving_Object::modify_percent(float,unsigned char)         *
    //                              *********************************************************************************************************
    //                              void __thiscall modify_percent(RGE_Master_Moving_Object * this, floa
    //              void              <VOID>         <RETURN>
    //              RGE_Master_Mov    ECX:4 (auto)   this
    //              float             Stack[0x4]:4   param_1                   XREF[2]:     00452019(R), 00452026(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[1]:     00452010(R)  
    //                               ?modify_percent@RGE_Master_Moving_Object@@UAEXME@Z           XREF[2]:     modify_percent:0044f85e(c), 
    //                               RGE_Master_Moving_Object::modify_percent                                  005705b0(*)  
    //                              m_mo_obj.cpp:212 (8)
    //         00452010     MOV        EAX,dword ptr [ESP + param_2]
    //         00452014     CMP        AL,0x6
    //         00452016     JZ         LAB_00452026
    //                              m_mo_obj.cpp:219 (11)
    //         00452018     PUSH       EAX
    //         00452019     MOV        EAX,dword ptr [ESP + param_1]
    //         0045201d     PUSH       EAX
    //         0045201e     CALL       RGE_Master_Animated_Object::modify_percent       void modify_percent(RGE_Master_Animated_Objec
    //                              m_mo_obj.cpp:222 (3)
    //         00452023     RET        0x8
    //                               LAB_00452026                                                 XREF[1]:     00452016(j)  
    //                              m_mo_obj.cpp:216 (16)
    //         00452026     FLD        float ptr [ESP + param_1]
    //         0045202a     FMUL       float ptr [ECX + this->turn_speed]
    //         00452030     FSTP       float ptr [ECX + this->turn_speed]
    //                              m_mo_obj.cpp:222 (3)
    //         00452036     RET        0x8
}

// Offset: 0x00452040
void RGE_Master_Moving_Object::save(int param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Master_Moving_Object::save(int)                                   *
    //                              *********************************************************************************************************
    //                              void __thiscall save(RGE_Master_Moving_Object * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Master_Mov    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00452070(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00452074(W), 00452090(*)  
    //              short             Stack[-0x8]:2  temp_run_sprite           XREF[3]:     00452058(W), 0045205e(W), 00452080(*)  
    //              short             Stack[-0xc]:2  temp_move_sprite
    //                               ?save@RGE_Master_Moving_Object@@UAEXH@Z                      XREF[2]:     save:0044f897(c), 005705b4(*)  
    //                               RGE_Master_Moving_Object::save
    //                              m_mo_obj.cpp:227 (7)
    //         00452040     SUB        ESP,0x8
    //         00452043     PUSH       ESI
    //         00452044     PUSH       EDI
    //         00452045     MOV        EDI,this
    //                              m_mo_obj.cpp:231 (27)
    //         00452047     OR         this,0xffffffff
    //         0045204a     MOV        EAX,dword ptr [EDI + 0xbc]
    //         00452050     TEST       EAX,EAX
    //         00452052     JZ         LAB_0045205e
    //         00452054     MOV        AX,word ptr [EAX + 0x72]
    //         00452058     MOV        dword ptr [ESP + temp_run_sprite],EAX
    //         0045205c     JMP        LAB_00452062
    //                               LAB_0045205e                                                 XREF[1]:     00452052(j)  
    //         0045205e     MOV        dword ptr [ESP + temp_run_sprite],this
    //                               LAB_00452062                                                 XREF[1]:     0045205c(j)  
    //                              m_mo_obj.cpp:232 (14)
    //         00452062     MOV        EAX,dword ptr [EDI + 0xc0]
    //         00452068     TEST       EAX,EAX
    //         0045206a     JZ         LAB_00452070
    //         0045206c     MOV        this,word ptr [EAX + 0x72]
    //                               LAB_00452070                                                 XREF[1]:     0045206a(j)  
    //                              m_mo_obj.cpp:234 (16)
    //         00452070     MOV        ESI,dword ptr [ESP + param_1]
    //         00452074     MOV        dword ptr [ESP + local_4],this
    //         00452078     PUSH       ESI
    //         00452079     MOV        this,EDI
    //         0045207b     CALL       RGE_Master_Animated_Object::save                 void save(RGE_Master_Animated_Object * this, 
    //                              m_mo_obj.cpp:236 (16)
    //         00452080     LEA        EDX=>temp_run_sprite,[ESP + 0x8]
    //         00452084     PUSH       0x2
    //         00452086     PUSH       EDX
    //         00452087     PUSH       ESI
    //         00452088     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0045208d     ADD        ESP,0xc
    //                              m_mo_obj.cpp:237 (16)
    //         00452090     LEA        EAX=>local_4,[ESP + 0xc]
    //         00452094     PUSH       0x2
    //         00452096     PUSH       EAX
    //         00452097     PUSH       ESI
    //         00452098     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0045209d     ADD        ESP,0xc
    //                              m_mo_obj.cpp:238 (18)
    //         004520a0     LEA        this,[EDI + 0xc4]
    //         004520a6     PUSH       0x4
    //         004520a8     PUSH       this
    //         004520a9     PUSH       ESI
    //         004520aa     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004520af     ADD        ESP,0xc
    //                              m_mo_obj.cpp:239 (18)
    //         004520b2     LEA        EDX,[EDI + 0xc8]
    //         004520b8     PUSH       0x1
    //         004520ba     PUSH       EDX
    //         004520bb     PUSH       ESI
    //         004520bc     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004520c1     ADD        ESP,0xc
    //                              m_mo_obj.cpp:240 (18)
    //         004520c4     LEA        EAX,[EDI + 0xca]
    //         004520ca     PUSH       0x2
    //         004520cc     PUSH       EAX
    //         004520cd     PUSH       ESI
    //         004520ce     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004520d3     ADD        ESP,0xc
    //                              m_mo_obj.cpp:241 (18)
    //         004520d6     LEA        this,[EDI + 0xcc]
    //         004520dc     PUSH       0x1
    //         004520de     PUSH       this
    //         004520df     PUSH       ESI
    //         004520e0     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004520e5     ADD        ESP,0xc
    //                              m_mo_obj.cpp:242 (18)
    //         004520e8     LEA        EDX,[EDI + 0xd0]
    //         004520ee     PUSH       0x4
    //         004520f0     PUSH       EDX
    //         004520f1     PUSH       ESI
    //         004520f2     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004520f7     ADD        ESP,0xc
    //                              m_mo_obj.cpp:243 (18)
    //         004520fa     ADD        EDI,0xd4
    //         00452100     PUSH       0x1
    //         00452102     PUSH       EDI
    //         00452103     PUSH       ESI
    //         00452104     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00452109     ADD        ESP,0xc
    //                              m_mo_obj.cpp:244 (8)
    //         0045210c     POP        EDI
    //         0045210d     POP        ESI
    //         0045210e     ADD        ESP,0x8
    //         00452111     RET        0x4
}

