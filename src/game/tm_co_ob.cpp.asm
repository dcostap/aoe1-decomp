#include "common.h"
#include "tm_co_ob.h"

int TRIBE_Master_Combat_Object::setup(TRIBE_Master_Combat_Object* param_1) {
    /* TODO: Stub */
    //                              int __thiscall setup(TRIBE_Master_Combat_Object * this, TRIBE_Master
    //              int               EAX:4          <RETURN>
    //              TRIBE_Master_C    ECX:4 (auto)   this
    //              TRIBE_Master_C    Stack[0x4]:4   param_1                   XREF[2]:     0050eae4(R), 0050eb1a(R)  
    //                               ?setup@TRIBE_Master_Combat_Object@@IAEHPAV1@@Z               XREF[2]:     setup:0050e1b9(c), 
    //                               TRIBE_Master_Combat_Object::setup                                         TRIBE_Master_Combat_Object:0050e9b
    //                              tm_co_ob.cpp:51 (4)
    //         0050eae0     PUSH       EBX
    //         0050eae1     PUSH       EBP
    //         0050eae2     PUSH       ESI
    //         0050eae3     PUSH       EDI
    //                              tm_co_ob.cpp:54 (12)
    //         0050eae4     MOV        EDI,dword ptr [ESP + param_1]
    //         0050eae8     MOV        ESI,this
    //         0050eaea     PUSH       EDI
    //         0050eaeb     CALL       RGE_Master_Combat_Object::setup                  int setup(RGE_Master_Combat_Object * this, RG
    //                              tm_co_ob.cpp:58 (22)
    //         0050eaf0     MOV        this,EDI
    //         0050eaf2     MOV        byte ptr [ESI + 0x4],0x46
    //         0050eaf6     LEA        EAX,[ESI + 0x148]
    //         0050eafc     SUB        this,ESI
    //         0050eafe     MOV        EDX,0x3
    //                               LAB_0050eb03                                                 XREF[1]:     0050eb18(j)  
    //         0050eb03     LEA        EDI,[this->_padding_ + EAX*0x1]
    //                              tm_co_ob.cpp:59 (20)
    //         0050eb06     MOV        EBX,EAX
    //         0050eb08     ADD        EAX,0x6
    //         0050eb0b     DEC        EDX
    //         0050eb0c     MOV        EBP,dword ptr [EDI]
    //         0050eb0e     MOV        dword ptr [EBX],EBP
    //         0050eb10     MOV        DI,word ptr [EDI + 0x4]
    //         0050eb14     MOV        word ptr [EBX + 0x4],DI
    //         0050eb18     JNZ        LAB_0050eb03
    //                              tm_co_ob.cpp:60 (4)
    //         0050eb1a     MOV        EAX,dword ptr [ESP + param_1]
    //                              tm_co_ob.cpp:69 (66)
    //         0050eb1e     POP        EDI
    //         0050eb1f     MOV        this,word ptr [EAX + 0x15a]
    //         0050eb26     MOV        word ptr [ESI + 0x15a],this
    //         0050eb2d     MOV        DX,word ptr [EAX + 0x15c]
    //         0050eb34     MOV        word ptr [ESI + 0x15c],DX
    //         0050eb3b     MOV        this,byte ptr [EAX + 0x15e]
    //         0050eb41     MOV        byte ptr [ESI + 0x15e],this
    //         0050eb47     MOV        DX,word ptr [EAX + 0x160]
    //         0050eb4e     MOV        word ptr [ESI + 0x160],DX
    //         0050eb55     POP        ESI
    //         0050eb56     POP        EBP
    //         0050eb57     MOV        EAX,0x1
    //         0050eb5c     POP        EBX
    //         0050eb5d     RET        0x4
    //                              * protected: int __thiscall TRIBE_Master_Combat_Object::setup(int,class RGE_Sprite * *,class RGE_Sou... *
    //                              int __thiscall setup(TRIBE_Master_Combat_Object * this, int param_1,
    //              int               EAX:4          <RETURN>
    //              TRIBE_Master_C    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0050eb65(R)  
    //              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     0050eb6d(R)  
    //              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[1]:     0050eb60(R)  
    //                               ?setup@TRIBE_Master_Combat_Object@@IAEHHPAPAVRGE_Sprite@@PA  XREF[2]:     setup:0050e265(c), 
    //                               TRIBE_Master_Combat_Object::setup                                         TRIBE_Master_Combat_Object:0050ea4
    //                              tm_co_ob.cpp:73 (28)
    //         0050eb60     MOV        EAX,dword ptr [ESP + param_3]
    //         0050eb64     PUSH       EBX
    //         0050eb65     MOV        EBX,dword ptr [ESP + param_1]
    //         0050eb69     PUSH       EBP
    //         0050eb6a     PUSH       ESI
    //         0050eb6b     MOV        ESI,this
    //         0050eb6d     MOV        this,dword ptr [ESP + param_2]
    //         0050eb71     PUSH       EDI
    //         0050eb72     PUSH       EAX
    //         0050eb73     PUSH       this
    //         0050eb74     PUSH       EBX
    //         0050eb75     MOV        this,ESI
    //         0050eb77     CALL       RGE_Master_Combat_Object::setup                  int setup(RGE_Master_Combat_Object * this, in
    //                              tm_co_ob.cpp:79 (15)
    //         0050eb7c     MOV        byte ptr [ESI + 0x4],0x46
    //         0050eb80     LEA        EDI,[ESI + 0x148]
    //         0050eb86     MOV        EBP,0x3
    //                               LAB_0050eb8b                                                 XREF[1]:     0050eb9b(j)  
    //                              tm_co_ob.cpp:82 (18)
    //         0050eb8b     PUSH       0x6
    //         0050eb8d     PUSH       EDI
    //         0050eb8e     PUSH       EBX
    //         0050eb8f     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050eb94     ADD        ESP,0xc
    //         0050eb97     ADD        EDI,0x6
    //         0050eb9a     DEC        EBP
    //         0050eb9b     JNZ        LAB_0050eb8b
    //                              tm_co_ob.cpp:83 (18)
    //         0050eb9d     LEA        EDX,[ESI + 0x15a]
    //         0050eba3     PUSH       0x2
    //         0050eba5     PUSH       EDX
    //         0050eba6     PUSH       EBX
    //         0050eba7     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050ebac     ADD        ESP,0xc
    //                              tm_co_ob.cpp:84 (18)
    //         0050ebaf     LEA        EAX,[ESI + 0x15c]
    //         0050ebb5     PUSH       0x2
    //         0050ebb7     PUSH       EAX
    //         0050ebb8     PUSH       EBX
    //         0050ebb9     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050ebbe     ADD        ESP,0xc
    //                              tm_co_ob.cpp:85 (15)
    //         0050ebc1     LEA        this,[ESI + 0x15e]
    //         0050ebc7     PUSH       0x1
    //         0050ebc9     PUSH       this
    //         0050ebca     PUSH       EBX
    //         0050ebcb     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              tm_co_ob.cpp:87 (22)
    //         0050ebd0     FLD        float ptr [save_game_version]                    = 7.23
    //         0050ebd6     FCOMP      float ptr [DAT_0057677c]                         = ECh
    //         0050ebdc     ADD        ESP,0xc
    //         0050ebdf     FNSTSW     AX
    //         0050ebe1     TEST       AH,0x1
    //         0050ebe4     JNZ        LAB_0050ec04
    //                              tm_co_ob.cpp:88 (18)
    //         0050ebe6     ADD        ESI,0x160
    //         0050ebec     PUSH       0x2
    //         0050ebee     PUSH       ESI
    //         0050ebef     PUSH       EBX
    //         0050ebf0     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050ebf5     ADD        ESP,0xc
    //                              tm_co_ob.cpp:106 (5)
    //         0050ebf8     MOV        EAX,0x1
    //                              tm_co_ob.cpp:107 (7)
    //         0050ebfd     POP        EDI
    //         0050ebfe     POP        ESI
    //         0050ebff     POP        EBP
    //         0050ec00     POP        EBX
    //         0050ec01     RET        0xc
    //                               LAB_0050ec04                                                 XREF[1]:     0050ebe4(j)  
    //                              tm_co_ob.cpp:92 (20)
    //         0050ec04     MOVSX      EDX,word ptr [ESI + 0x102]
    //         0050ec0b     TEST       EDX,EDX
    //         0050ec0d     MOV        word ptr [ESI + 0x160],0x0
    //         0050ec16     JLE        LAB_0050ec40
    //                              tm_co_ob.cpp:107 (8)
    //         0050ec18     MOV        EAX,dword ptr [ESI + 0x104]
    //         0050ec1e     MOV        EDI,EDX
    //                               LAB_0050ec20                                                 XREF[1]:     0050ec3e(j)  
    //                              tm_co_ob.cpp:94 (19)
    //         0050ec20     CMP        word ptr [EAX],0x3
    //         0050ec24     JNZ        LAB_0050ec3a
    //         0050ec26     MOV        this,word ptr [EAX + 0x2]
    //         0050ec2a     CMP        this,word ptr [ESI + 0x160]
    //         0050ec31     JLE        LAB_0050ec3a
    //                              tm_co_ob.cpp:95 (7)
    //         0050ec33     MOV        word ptr [ESI + 0x160],this
    //                               LAB_0050ec3a                                                 XREF[2]:     0050ec24(j), 0050ec31(j)  
    //                              tm_co_ob.cpp:92 (6)
    //         0050ec3a     ADD        EAX,0x4
    //         0050ec3d     DEC        EDI
    //         0050ec3e     JNZ        LAB_0050ec20
    //                               LAB_0050ec40                                                 XREF[1]:     0050ec16(j)  
    //                              tm_co_ob.cpp:98 (8)
    //         0050ec40     MOVZX      AX,byte ptr [ESI + 0x100]
    //                              tm_co_ob.cpp:99 (11)
    //         0050ec48     TEST       EDX,EDX
    //         0050ec4a     MOV        word ptr [ESI + 0x13c],AX
    //         0050ec51     JLE        LAB_0050ec79
    //                              tm_co_ob.cpp:98 (6)
    //         0050ec53     MOV        EAX,dword ptr [ESI + 0x104]
    //                               LAB_0050ec59                                                 XREF[1]:     0050ec77(j)  
    //                              tm_co_ob.cpp:101 (19)
    //         0050ec59     CMP        word ptr [EAX],0x3
    //         0050ec5d     JZ         LAB_0050ec73
    //         0050ec5f     MOV        this,word ptr [EAX + 0x2]
    //         0050ec63     CMP        this,word ptr [ESI + 0x13c]
    //         0050ec6a     JLE        LAB_0050ec73
    //                              tm_co_ob.cpp:102 (7)
    //         0050ec6c     MOV        word ptr [ESI + 0x13c],this
    //                               LAB_0050ec73                                                 XREF[2]:     0050ec5d(j), 0050ec6a(j)  
    //                              tm_co_ob.cpp:99 (6)
    //         0050ec73     ADD        EAX,0x4
    //         0050ec76     DEC        EDX
    //         0050ec77     JNZ        LAB_0050ec59
    //                               LAB_0050ec79                                                 XREF[1]:     0050ec51(j)  
    //                              tm_co_ob.cpp:107 (12)
    //         0050ec79     POP        EDI
    //         0050ec7a     POP        ESI
    //         0050ec7b     POP        EBP
    //         0050ec7c     MOV        EAX,0x1
    //         0050ec81     POP        EBX
    //         0050ec82     RET        0xc
    //         0050ec85     ??         90h
    //         0050ec86     NOP
    //         0050ec87     NOP
    //         0050ec88     NOP
    //         0050ec89     NOP
    //         0050ec8a     NOP
    //         0050ec8b     NOP
    //         0050ec8c     NOP
    //         0050ec8d     NOP
    //         0050ec8e     NOP
    //         0050ec8f     NOP
    //                              * protected: int __thiscall TRIBE_Master_Combat_Object::setup(struct _iobuf *,class RGE_Sprite * *,c... *
    //                              int __thiscall setup(TRIBE_Master_Combat_Object * this, _iobuf * par
    //              int               EAX:4          <RETURN>
    //              TRIBE_Master_C    ECX:4 (auto)   this
    //              _iobuf *          Stack[0x4]:4   param_1                   XREF[1]:     0050ec99(R)  
    //              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     0050ec94(R)  
    //              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[3]:     0050eca2(R), 0050ece5(*), 0050ed0a(R)  
    //              short             Stack[0x10]:2  param_4                   XREF[3]:     0050ec90(R), 0050ecc0(*), 0050ecd5(R)  
    //                               ?setup@TRIBE_Master_Combat_Object@@IAEHPAU_iobuf@@PAPAVRGE_  XREF[2]:     setup:0050e37a(c), 
    //                               TRIBE_Master_Combat_Object::setup                                         TRIBE_Master_Combat_Object:0050eab
    //                              tm_co_ob.cpp:111 (33)
    //         0050ec90     MOV        EAX,dword ptr [ESP + param_4]
    //         0050ec94     MOV        EDX,dword ptr [ESP + param_2]
    //         0050ec98     PUSH       EBX
    //         0050ec99     MOV        EBX,dword ptr [ESP + param_1]
    //         0050ec9d     PUSH       EBP
    //         0050ec9e     PUSH       ESI
    //         0050ec9f     PUSH       EDI
    //         0050eca0     MOV        EDI,this
    //         0050eca2     MOV        this,dword ptr [ESP + param_3]
    //         0050eca6     PUSH       EAX
    //         0050eca7     PUSH       this
    //         0050eca8     PUSH       EDX
    //         0050eca9     PUSH       EBX
    //         0050ecaa     MOV        this,EDI
    //         0050ecac     CALL       RGE_Master_Combat_Object::setup                  int setup(RGE_Master_Combat_Object * this, _i
    //                              tm_co_ob.cpp:119 (15)
    //         0050ecb1     MOV        byte ptr [EDI + 0x4],0x46
    //         0050ecb5     LEA        ESI,[EDI + 0x148]
    //         0050ecbb     MOV        EBP,0x3
    //                               LAB_0050ecc0                                                 XREF[1]:     0050ece3(j)  
    //                              tm_co_ob.cpp:126 (21)
    //         0050ecc0     LEA        EAX=>param_4,[ESP + 0x20]
    //         0050ecc4     LEA        this,[ESI + 0x2]
    //         0050ecc7     PUSH       EAX
    //         0050ecc8     PUSH       this
    //         0050ecc9     PUSH       ESI
    //         0050ecca     PUSH       s_%hd_%hd_%hd                                    = "%hd %hd %hd"
    //         0050eccf     PUSH       EBX
    //         0050ecd0     CALL       fscanf                                           undefined fscanf()
    //                              tm_co_ob.cpp:127 (16)
    //         0050ecd5     MOV        DL,byte ptr [ESP + param_4]
    //         0050ecd9     ADD        ESP,0x14
    //         0050ecdc     MOV        byte ptr [ESI + 0x4],DL
    //         0050ecdf     ADD        ESI,0x6
    //         0050ece2     DEC        EBP
    //         0050ece3     JNZ        LAB_0050ecc0
    //                              tm_co_ob.cpp:129 (30)
    //         0050ece5     LEA        EAX=>param_3,[ESP + 0x1c]
    //         0050ece9     LEA        this,[EDI + 0x15c]
    //         0050ecef     PUSH       EAX
    //         0050ecf0     LEA        EDX,[EDI + 0x15a]
    //         0050ecf6     PUSH       this
    //         0050ecf7     PUSH       EDX
    //         0050ecf8     PUSH       s_%hd_%hd_%hd                                    = "%hd %hd %hd"
    //         0050ecfd     PUSH       EBX
    //         0050ecfe     CALL       fscanf                                           undefined fscanf()
    //                              tm_co_ob.cpp:134 (33)
    //         0050ed03     MOVSX      EDX,word ptr [EDI + 0x102]
    //         0050ed0a     MOV        AL,byte ptr [ESP + param_3]
    //         0050ed0e     ADD        ESP,0x14
    //         0050ed11     TEST       EDX,EDX
    //         0050ed13     MOV        byte ptr [EDI + 0x15e],AL
    //         0050ed19     MOV        word ptr [EDI + 0x160],0x0
    //         0050ed22     JLE        LAB_0050ed4c
    //                              tm_co_ob.cpp:148 (8)
    //         0050ed24     MOV        EAX,dword ptr [EDI + 0x104]
    //         0050ed2a     MOV        ESI,EDX
    //                               LAB_0050ed2c                                                 XREF[1]:     0050ed4a(j)  
    //                              tm_co_ob.cpp:136 (19)
    //         0050ed2c     CMP        word ptr [EAX],0x3
    //         0050ed30     JNZ        LAB_0050ed46
    //         0050ed32     MOV        this,word ptr [EAX + 0x2]
    //         0050ed36     CMP        this,word ptr [EDI + 0x160]
    //         0050ed3d     JLE        LAB_0050ed46
    //                              tm_co_ob.cpp:137 (7)
    //         0050ed3f     MOV        word ptr [EDI + 0x160],this
    //                               LAB_0050ed46                                                 XREF[2]:     0050ed30(j), 0050ed3d(j)  
    //                              tm_co_ob.cpp:134 (6)
    //         0050ed46     ADD        EAX,0x4
    //         0050ed49     DEC        ESI
    //         0050ed4a     JNZ        LAB_0050ed2c
    //                               LAB_0050ed4c                                                 XREF[1]:     0050ed22(j)  
    //                              tm_co_ob.cpp:140 (8)
    //         0050ed4c     MOVZX      this,byte ptr [EDI + 0x100]
    //                              tm_co_ob.cpp:141 (11)
    //         0050ed54     TEST       EDX,EDX
    //         0050ed56     MOV        word ptr [EDI + 0x13c],this
    //         0050ed5d     JLE        LAB_0050ed85
    //                              tm_co_ob.cpp:140 (6)
    //         0050ed5f     MOV        EAX,dword ptr [EDI + 0x104]
    //                               LAB_0050ed65                                                 XREF[1]:     0050ed83(j)  
    //                              tm_co_ob.cpp:143 (19)
    //         0050ed65     CMP        word ptr [EAX],0x3
    //         0050ed69     JZ         LAB_0050ed7f
    //         0050ed6b     MOV        this,word ptr [EAX + 0x2]
    //         0050ed6f     CMP        this,word ptr [EDI + 0x13c]
    //         0050ed76     JLE        LAB_0050ed7f
    //                              tm_co_ob.cpp:144 (7)
    //         0050ed78     MOV        word ptr [EDI + 0x13c],this
    //                               LAB_0050ed7f                                                 XREF[2]:     0050ed69(j), 0050ed76(j)  
    //                              tm_co_ob.cpp:141 (6)
    //         0050ed7f     ADD        EAX,0x4
    //         0050ed82     DEC        EDX
    //         0050ed83     JNZ        LAB_0050ed65
    //                               LAB_0050ed85                                                 XREF[1]:     0050ed5d(j)  
    //                              tm_co_ob.cpp:148 (12)
    //         0050ed85     POP        EDI
    //         0050ed86     POP        ESI
    //         0050ed87     POP        EBP
    //         0050ed88     MOV        EAX,0x1
    //         0050ed8d     POP        EBX
    //         0050ed8e     RET        0x10
    //         0050ed91     ??         90h
    //         0050ed92     NOP
    //         0050ed93     NOP
    //         0050ed94     NOP
    //         0050ed95     NOP
    //         0050ed96     NOP
    //         0050ed97     NOP
    //         0050ed98     NOP
    //         0050ed99     NOP
    //         0050ed9a     NOP
    //         0050ed9b     NOP
    //         0050ed9c     NOP
    //         0050ed9d     NOP
    //         0050ed9e     NOP
    //         0050ed9f     NOP
    return 0;
}

int TRIBE_Master_Combat_Object::setup(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3) {
    /* TODO: Stub */
    //                              int __thiscall setup(TRIBE_Master_Combat_Object * this, TRIBE_Master
    //              int               EAX:4          <RETURN>
    //              TRIBE_Master_C    ECX:4 (auto)   this
    //              TRIBE_Master_C    Stack[0x4]:4   param_1                   XREF[2]:     0050eae4(R), 0050eb1a(R)  
    //                               ?setup@TRIBE_Master_Combat_Object@@IAEHPAV1@@Z               XREF[2]:     setup:0050e1b9(c), 
    //                               TRIBE_Master_Combat_Object::setup                                         TRIBE_Master_Combat_Object:0050e9b
    //                              tm_co_ob.cpp:51 (4)
    //         0050eae0     PUSH       EBX
    //         0050eae1     PUSH       EBP
    //         0050eae2     PUSH       ESI
    //         0050eae3     PUSH       EDI
    //                              tm_co_ob.cpp:54 (12)
    //         0050eae4     MOV        EDI,dword ptr [ESP + param_1]
    //         0050eae8     MOV        ESI,this
    //         0050eaea     PUSH       EDI
    //         0050eaeb     CALL       RGE_Master_Combat_Object::setup                  int setup(RGE_Master_Combat_Object * this, RG
    //                              tm_co_ob.cpp:58 (22)
    //         0050eaf0     MOV        this,EDI
    //         0050eaf2     MOV        byte ptr [ESI + 0x4],0x46
    //         0050eaf6     LEA        EAX,[ESI + 0x148]
    //         0050eafc     SUB        this,ESI
    //         0050eafe     MOV        EDX,0x3
    //                               LAB_0050eb03                                                 XREF[1]:     0050eb18(j)  
    //         0050eb03     LEA        EDI,[this->_padding_ + EAX*0x1]
    //                              tm_co_ob.cpp:59 (20)
    //         0050eb06     MOV        EBX,EAX
    //         0050eb08     ADD        EAX,0x6
    //         0050eb0b     DEC        EDX
    //         0050eb0c     MOV        EBP,dword ptr [EDI]
    //         0050eb0e     MOV        dword ptr [EBX],EBP
    //         0050eb10     MOV        DI,word ptr [EDI + 0x4]
    //         0050eb14     MOV        word ptr [EBX + 0x4],DI
    //         0050eb18     JNZ        LAB_0050eb03
    //                              tm_co_ob.cpp:60 (4)
    //         0050eb1a     MOV        EAX,dword ptr [ESP + param_1]
    //                              tm_co_ob.cpp:69 (66)
    //         0050eb1e     POP        EDI
    //         0050eb1f     MOV        this,word ptr [EAX + 0x15a]
    //         0050eb26     MOV        word ptr [ESI + 0x15a],this
    //         0050eb2d     MOV        DX,word ptr [EAX + 0x15c]
    //         0050eb34     MOV        word ptr [ESI + 0x15c],DX
    //         0050eb3b     MOV        this,byte ptr [EAX + 0x15e]
    //         0050eb41     MOV        byte ptr [ESI + 0x15e],this
    //         0050eb47     MOV        DX,word ptr [EAX + 0x160]
    //         0050eb4e     MOV        word ptr [ESI + 0x160],DX
    //         0050eb55     POP        ESI
    //         0050eb56     POP        EBP
    //         0050eb57     MOV        EAX,0x1
    //         0050eb5c     POP        EBX
    //         0050eb5d     RET        0x4
    //                              * protected: int __thiscall TRIBE_Master_Combat_Object::setup(int,class RGE_Sprite * *,class RGE_Sou... *
    //                              int __thiscall setup(TRIBE_Master_Combat_Object * this, int param_1,
    //              int               EAX:4          <RETURN>
    //              TRIBE_Master_C    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0050eb65(R)  
    //              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     0050eb6d(R)  
    //              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[1]:     0050eb60(R)  
    //                               ?setup@TRIBE_Master_Combat_Object@@IAEHHPAPAVRGE_Sprite@@PA  XREF[2]:     setup:0050e265(c), 
    //                               TRIBE_Master_Combat_Object::setup                                         TRIBE_Master_Combat_Object:0050ea4
    //                              tm_co_ob.cpp:73 (28)
    //         0050eb60     MOV        EAX,dword ptr [ESP + param_3]
    //         0050eb64     PUSH       EBX
    //         0050eb65     MOV        EBX,dword ptr [ESP + param_1]
    //         0050eb69     PUSH       EBP
    //         0050eb6a     PUSH       ESI
    //         0050eb6b     MOV        ESI,this
    //         0050eb6d     MOV        this,dword ptr [ESP + param_2]
    //         0050eb71     PUSH       EDI
    //         0050eb72     PUSH       EAX
    //         0050eb73     PUSH       this
    //         0050eb74     PUSH       EBX
    //         0050eb75     MOV        this,ESI
    //         0050eb77     CALL       RGE_Master_Combat_Object::setup                  int setup(RGE_Master_Combat_Object * this, in
    //                              tm_co_ob.cpp:79 (15)
    //         0050eb7c     MOV        byte ptr [ESI + 0x4],0x46
    //         0050eb80     LEA        EDI,[ESI + 0x148]
    //         0050eb86     MOV        EBP,0x3
    //                               LAB_0050eb8b                                                 XREF[1]:     0050eb9b(j)  
    //                              tm_co_ob.cpp:82 (18)
    //         0050eb8b     PUSH       0x6
    //         0050eb8d     PUSH       EDI
    //         0050eb8e     PUSH       EBX
    //         0050eb8f     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050eb94     ADD        ESP,0xc
    //         0050eb97     ADD        EDI,0x6
    //         0050eb9a     DEC        EBP
    //         0050eb9b     JNZ        LAB_0050eb8b
    //                              tm_co_ob.cpp:83 (18)
    //         0050eb9d     LEA        EDX,[ESI + 0x15a]
    //         0050eba3     PUSH       0x2
    //         0050eba5     PUSH       EDX
    //         0050eba6     PUSH       EBX
    //         0050eba7     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050ebac     ADD        ESP,0xc
    //                              tm_co_ob.cpp:84 (18)
    //         0050ebaf     LEA        EAX,[ESI + 0x15c]
    //         0050ebb5     PUSH       0x2
    //         0050ebb7     PUSH       EAX
    //         0050ebb8     PUSH       EBX
    //         0050ebb9     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050ebbe     ADD        ESP,0xc
    //                              tm_co_ob.cpp:85 (15)
    //         0050ebc1     LEA        this,[ESI + 0x15e]
    //         0050ebc7     PUSH       0x1
    //         0050ebc9     PUSH       this
    //         0050ebca     PUSH       EBX
    //         0050ebcb     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              tm_co_ob.cpp:87 (22)
    //         0050ebd0     FLD        float ptr [save_game_version]                    = 7.23
    //         0050ebd6     FCOMP      float ptr [DAT_0057677c]                         = ECh
    //         0050ebdc     ADD        ESP,0xc
    //         0050ebdf     FNSTSW     AX
    //         0050ebe1     TEST       AH,0x1
    //         0050ebe4     JNZ        LAB_0050ec04
    //                              tm_co_ob.cpp:88 (18)
    //         0050ebe6     ADD        ESI,0x160
    //         0050ebec     PUSH       0x2
    //         0050ebee     PUSH       ESI
    //         0050ebef     PUSH       EBX
    //         0050ebf0     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050ebf5     ADD        ESP,0xc
    //                              tm_co_ob.cpp:106 (5)
    //         0050ebf8     MOV        EAX,0x1
    //                              tm_co_ob.cpp:107 (7)
    //         0050ebfd     POP        EDI
    //         0050ebfe     POP        ESI
    //         0050ebff     POP        EBP
    //         0050ec00     POP        EBX
    //         0050ec01     RET        0xc
    //                               LAB_0050ec04                                                 XREF[1]:     0050ebe4(j)  
    //                              tm_co_ob.cpp:92 (20)
    //         0050ec04     MOVSX      EDX,word ptr [ESI + 0x102]
    //         0050ec0b     TEST       EDX,EDX
    //         0050ec0d     MOV        word ptr [ESI + 0x160],0x0
    //         0050ec16     JLE        LAB_0050ec40
    //                              tm_co_ob.cpp:107 (8)
    //         0050ec18     MOV        EAX,dword ptr [ESI + 0x104]
    //         0050ec1e     MOV        EDI,EDX
    //                               LAB_0050ec20                                                 XREF[1]:     0050ec3e(j)  
    //                              tm_co_ob.cpp:94 (19)
    //         0050ec20     CMP        word ptr [EAX],0x3
    //         0050ec24     JNZ        LAB_0050ec3a
    //         0050ec26     MOV        this,word ptr [EAX + 0x2]
    //         0050ec2a     CMP        this,word ptr [ESI + 0x160]
    //         0050ec31     JLE        LAB_0050ec3a
    //                              tm_co_ob.cpp:95 (7)
    //         0050ec33     MOV        word ptr [ESI + 0x160],this
    //                               LAB_0050ec3a                                                 XREF[2]:     0050ec24(j), 0050ec31(j)  
    //                              tm_co_ob.cpp:92 (6)
    //         0050ec3a     ADD        EAX,0x4
    //         0050ec3d     DEC        EDI
    //         0050ec3e     JNZ        LAB_0050ec20
    //                               LAB_0050ec40                                                 XREF[1]:     0050ec16(j)  
    //                              tm_co_ob.cpp:98 (8)
    //         0050ec40     MOVZX      AX,byte ptr [ESI + 0x100]
    //                              tm_co_ob.cpp:99 (11)
    //         0050ec48     TEST       EDX,EDX
    //         0050ec4a     MOV        word ptr [ESI + 0x13c],AX
    //         0050ec51     JLE        LAB_0050ec79
    //                              tm_co_ob.cpp:98 (6)
    //         0050ec53     MOV        EAX,dword ptr [ESI + 0x104]
    //                               LAB_0050ec59                                                 XREF[1]:     0050ec77(j)  
    //                              tm_co_ob.cpp:101 (19)
    //         0050ec59     CMP        word ptr [EAX],0x3
    //         0050ec5d     JZ         LAB_0050ec73
    //         0050ec5f     MOV        this,word ptr [EAX + 0x2]
    //         0050ec63     CMP        this,word ptr [ESI + 0x13c]
    //         0050ec6a     JLE        LAB_0050ec73
    //                              tm_co_ob.cpp:102 (7)
    //         0050ec6c     MOV        word ptr [ESI + 0x13c],this
    //                               LAB_0050ec73                                                 XREF[2]:     0050ec5d(j), 0050ec6a(j)  
    //                              tm_co_ob.cpp:99 (6)
    //         0050ec73     ADD        EAX,0x4
    //         0050ec76     DEC        EDX
    //         0050ec77     JNZ        LAB_0050ec59
    //                               LAB_0050ec79                                                 XREF[1]:     0050ec51(j)  
    //                              tm_co_ob.cpp:107 (12)
    //         0050ec79     POP        EDI
    //         0050ec7a     POP        ESI
    //         0050ec7b     POP        EBP
    //         0050ec7c     MOV        EAX,0x1
    //         0050ec81     POP        EBX
    //         0050ec82     RET        0xc
    //         0050ec85     ??         90h
    //         0050ec86     NOP
    //         0050ec87     NOP
    //         0050ec88     NOP
    //         0050ec89     NOP
    //         0050ec8a     NOP
    //         0050ec8b     NOP
    //         0050ec8c     NOP
    //         0050ec8d     NOP
    //         0050ec8e     NOP
    //         0050ec8f     NOP
    //                              * protected: int __thiscall TRIBE_Master_Combat_Object::setup(struct _iobuf *,class RGE_Sprite * *,c... *
    //                              int __thiscall setup(TRIBE_Master_Combat_Object * this, _iobuf * par
    //              int               EAX:4          <RETURN>
    //              TRIBE_Master_C    ECX:4 (auto)   this
    //              _iobuf *          Stack[0x4]:4   param_1                   XREF[1]:     0050ec99(R)  
    //              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     0050ec94(R)  
    //              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[3]:     0050eca2(R), 0050ece5(*), 0050ed0a(R)  
    //              short             Stack[0x10]:2  param_4                   XREF[3]:     0050ec90(R), 0050ecc0(*), 0050ecd5(R)  
    //                               ?setup@TRIBE_Master_Combat_Object@@IAEHPAU_iobuf@@PAPAVRGE_  XREF[2]:     setup:0050e37a(c), 
    //                               TRIBE_Master_Combat_Object::setup                                         TRIBE_Master_Combat_Object:0050eab
    //                              tm_co_ob.cpp:111 (33)
    //         0050ec90     MOV        EAX,dword ptr [ESP + param_4]
    //         0050ec94     MOV        EDX,dword ptr [ESP + param_2]
    //         0050ec98     PUSH       EBX
    //         0050ec99     MOV        EBX,dword ptr [ESP + param_1]
    //         0050ec9d     PUSH       EBP
    //         0050ec9e     PUSH       ESI
    //         0050ec9f     PUSH       EDI
    //         0050eca0     MOV        EDI,this
    //         0050eca2     MOV        this,dword ptr [ESP + param_3]
    //         0050eca6     PUSH       EAX
    //         0050eca7     PUSH       this
    //         0050eca8     PUSH       EDX
    //         0050eca9     PUSH       EBX
    //         0050ecaa     MOV        this,EDI
    //         0050ecac     CALL       RGE_Master_Combat_Object::setup                  int setup(RGE_Master_Combat_Object * this, _i
    //                              tm_co_ob.cpp:119 (15)
    //         0050ecb1     MOV        byte ptr [EDI + 0x4],0x46
    //         0050ecb5     LEA        ESI,[EDI + 0x148]
    //         0050ecbb     MOV        EBP,0x3
    //                               LAB_0050ecc0                                                 XREF[1]:     0050ece3(j)  
    //                              tm_co_ob.cpp:126 (21)
    //         0050ecc0     LEA        EAX=>param_4,[ESP + 0x20]
    //         0050ecc4     LEA        this,[ESI + 0x2]
    //         0050ecc7     PUSH       EAX
    //         0050ecc8     PUSH       this
    //         0050ecc9     PUSH       ESI
    //         0050ecca     PUSH       s_%hd_%hd_%hd                                    = "%hd %hd %hd"
    //         0050eccf     PUSH       EBX
    //         0050ecd0     CALL       fscanf                                           undefined fscanf()
    //                              tm_co_ob.cpp:127 (16)
    //         0050ecd5     MOV        DL,byte ptr [ESP + param_4]
    //         0050ecd9     ADD        ESP,0x14
    //         0050ecdc     MOV        byte ptr [ESI + 0x4],DL
    //         0050ecdf     ADD        ESI,0x6
    //         0050ece2     DEC        EBP
    //         0050ece3     JNZ        LAB_0050ecc0
    //                              tm_co_ob.cpp:129 (30)
    //         0050ece5     LEA        EAX=>param_3,[ESP + 0x1c]
    //         0050ece9     LEA        this,[EDI + 0x15c]
    //         0050ecef     PUSH       EAX
    //         0050ecf0     LEA        EDX,[EDI + 0x15a]
    //         0050ecf6     PUSH       this
    //         0050ecf7     PUSH       EDX
    //         0050ecf8     PUSH       s_%hd_%hd_%hd                                    = "%hd %hd %hd"
    //         0050ecfd     PUSH       EBX
    //         0050ecfe     CALL       fscanf                                           undefined fscanf()
    //                              tm_co_ob.cpp:134 (33)
    //         0050ed03     MOVSX      EDX,word ptr [EDI + 0x102]
    //         0050ed0a     MOV        AL,byte ptr [ESP + param_3]
    //         0050ed0e     ADD        ESP,0x14
    //         0050ed11     TEST       EDX,EDX
    //         0050ed13     MOV        byte ptr [EDI + 0x15e],AL
    //         0050ed19     MOV        word ptr [EDI + 0x160],0x0
    //         0050ed22     JLE        LAB_0050ed4c
    //                              tm_co_ob.cpp:148 (8)
    //         0050ed24     MOV        EAX,dword ptr [EDI + 0x104]
    //         0050ed2a     MOV        ESI,EDX
    //                               LAB_0050ed2c                                                 XREF[1]:     0050ed4a(j)  
    //                              tm_co_ob.cpp:136 (19)
    //         0050ed2c     CMP        word ptr [EAX],0x3
    //         0050ed30     JNZ        LAB_0050ed46
    //         0050ed32     MOV        this,word ptr [EAX + 0x2]
    //         0050ed36     CMP        this,word ptr [EDI + 0x160]
    //         0050ed3d     JLE        LAB_0050ed46
    //                              tm_co_ob.cpp:137 (7)
    //         0050ed3f     MOV        word ptr [EDI + 0x160],this
    //                               LAB_0050ed46                                                 XREF[2]:     0050ed30(j), 0050ed3d(j)  
    //                              tm_co_ob.cpp:134 (6)
    //         0050ed46     ADD        EAX,0x4
    //         0050ed49     DEC        ESI
    //         0050ed4a     JNZ        LAB_0050ed2c
    //                               LAB_0050ed4c                                                 XREF[1]:     0050ed22(j)  
    //                              tm_co_ob.cpp:140 (8)
    //         0050ed4c     MOVZX      this,byte ptr [EDI + 0x100]
    //                              tm_co_ob.cpp:141 (11)
    //         0050ed54     TEST       EDX,EDX
    //         0050ed56     MOV        word ptr [EDI + 0x13c],this
    //         0050ed5d     JLE        LAB_0050ed85
    //                              tm_co_ob.cpp:140 (6)
    //         0050ed5f     MOV        EAX,dword ptr [EDI + 0x104]
    //                               LAB_0050ed65                                                 XREF[1]:     0050ed83(j)  
    //                              tm_co_ob.cpp:143 (19)
    //         0050ed65     CMP        word ptr [EAX],0x3
    //         0050ed69     JZ         LAB_0050ed7f
    //         0050ed6b     MOV        this,word ptr [EAX + 0x2]
    //         0050ed6f     CMP        this,word ptr [EDI + 0x13c]
    //         0050ed76     JLE        LAB_0050ed7f
    //                              tm_co_ob.cpp:144 (7)
    //         0050ed78     MOV        word ptr [EDI + 0x13c],this
    //                               LAB_0050ed7f                                                 XREF[2]:     0050ed69(j), 0050ed76(j)  
    //                              tm_co_ob.cpp:141 (6)
    //         0050ed7f     ADD        EAX,0x4
    //         0050ed82     DEC        EDX
    //         0050ed83     JNZ        LAB_0050ed65
    //                               LAB_0050ed85                                                 XREF[1]:     0050ed5d(j)  
    //                              tm_co_ob.cpp:148 (12)
    //         0050ed85     POP        EDI
    //         0050ed86     POP        ESI
    //         0050ed87     POP        EBP
    //         0050ed88     MOV        EAX,0x1
    //         0050ed8d     POP        EBX
    //         0050ed8e     RET        0x10
    //         0050ed91     ??         90h
    //         0050ed92     NOP
    //         0050ed93     NOP
    //         0050ed94     NOP
    //         0050ed95     NOP
    //         0050ed96     NOP
    //         0050ed97     NOP
    //         0050ed98     NOP
    //         0050ed99     NOP
    //         0050ed9a     NOP
    //         0050ed9b     NOP
    //         0050ed9c     NOP
    //         0050ed9d     NOP
    //         0050ed9e     NOP
    //         0050ed9f     NOP
    return 0;
}

int TRIBE_Master_Combat_Object::setup(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4) {
    /* TODO: Stub */
    //                              int __thiscall setup(TRIBE_Master_Combat_Object * this, TRIBE_Master
    //              int               EAX:4          <RETURN>
    //              TRIBE_Master_C    ECX:4 (auto)   this
    //              TRIBE_Master_C    Stack[0x4]:4   param_1                   XREF[2]:     0050eae4(R), 0050eb1a(R)  
    //                               ?setup@TRIBE_Master_Combat_Object@@IAEHPAV1@@Z               XREF[2]:     setup:0050e1b9(c), 
    //                               TRIBE_Master_Combat_Object::setup                                         TRIBE_Master_Combat_Object:0050e9b
    //                              tm_co_ob.cpp:51 (4)
    //         0050eae0     PUSH       EBX
    //         0050eae1     PUSH       EBP
    //         0050eae2     PUSH       ESI
    //         0050eae3     PUSH       EDI
    //                              tm_co_ob.cpp:54 (12)
    //         0050eae4     MOV        EDI,dword ptr [ESP + param_1]
    //         0050eae8     MOV        ESI,this
    //         0050eaea     PUSH       EDI
    //         0050eaeb     CALL       RGE_Master_Combat_Object::setup                  int setup(RGE_Master_Combat_Object * this, RG
    //                              tm_co_ob.cpp:58 (22)
    //         0050eaf0     MOV        this,EDI
    //         0050eaf2     MOV        byte ptr [ESI + 0x4],0x46
    //         0050eaf6     LEA        EAX,[ESI + 0x148]
    //         0050eafc     SUB        this,ESI
    //         0050eafe     MOV        EDX,0x3
    //                               LAB_0050eb03                                                 XREF[1]:     0050eb18(j)  
    //         0050eb03     LEA        EDI,[this->_padding_ + EAX*0x1]
    //                              tm_co_ob.cpp:59 (20)
    //         0050eb06     MOV        EBX,EAX
    //         0050eb08     ADD        EAX,0x6
    //         0050eb0b     DEC        EDX
    //         0050eb0c     MOV        EBP,dword ptr [EDI]
    //         0050eb0e     MOV        dword ptr [EBX],EBP
    //         0050eb10     MOV        DI,word ptr [EDI + 0x4]
    //         0050eb14     MOV        word ptr [EBX + 0x4],DI
    //         0050eb18     JNZ        LAB_0050eb03
    //                              tm_co_ob.cpp:60 (4)
    //         0050eb1a     MOV        EAX,dword ptr [ESP + param_1]
    //                              tm_co_ob.cpp:69 (66)
    //         0050eb1e     POP        EDI
    //         0050eb1f     MOV        this,word ptr [EAX + 0x15a]
    //         0050eb26     MOV        word ptr [ESI + 0x15a],this
    //         0050eb2d     MOV        DX,word ptr [EAX + 0x15c]
    //         0050eb34     MOV        word ptr [ESI + 0x15c],DX
    //         0050eb3b     MOV        this,byte ptr [EAX + 0x15e]
    //         0050eb41     MOV        byte ptr [ESI + 0x15e],this
    //         0050eb47     MOV        DX,word ptr [EAX + 0x160]
    //         0050eb4e     MOV        word ptr [ESI + 0x160],DX
    //         0050eb55     POP        ESI
    //         0050eb56     POP        EBP
    //         0050eb57     MOV        EAX,0x1
    //         0050eb5c     POP        EBX
    //         0050eb5d     RET        0x4
    //                              * protected: int __thiscall TRIBE_Master_Combat_Object::setup(int,class RGE_Sprite * *,class RGE_Sou... *
    //                              int __thiscall setup(TRIBE_Master_Combat_Object * this, int param_1,
    //              int               EAX:4          <RETURN>
    //              TRIBE_Master_C    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0050eb65(R)  
    //              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     0050eb6d(R)  
    //              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[1]:     0050eb60(R)  
    //                               ?setup@TRIBE_Master_Combat_Object@@IAEHHPAPAVRGE_Sprite@@PA  XREF[2]:     setup:0050e265(c), 
    //                               TRIBE_Master_Combat_Object::setup                                         TRIBE_Master_Combat_Object:0050ea4
    //                              tm_co_ob.cpp:73 (28)
    //         0050eb60     MOV        EAX,dword ptr [ESP + param_3]
    //         0050eb64     PUSH       EBX
    //         0050eb65     MOV        EBX,dword ptr [ESP + param_1]
    //         0050eb69     PUSH       EBP
    //         0050eb6a     PUSH       ESI
    //         0050eb6b     MOV        ESI,this
    //         0050eb6d     MOV        this,dword ptr [ESP + param_2]
    //         0050eb71     PUSH       EDI
    //         0050eb72     PUSH       EAX
    //         0050eb73     PUSH       this
    //         0050eb74     PUSH       EBX
    //         0050eb75     MOV        this,ESI
    //         0050eb77     CALL       RGE_Master_Combat_Object::setup                  int setup(RGE_Master_Combat_Object * this, in
    //                              tm_co_ob.cpp:79 (15)
    //         0050eb7c     MOV        byte ptr [ESI + 0x4],0x46
    //         0050eb80     LEA        EDI,[ESI + 0x148]
    //         0050eb86     MOV        EBP,0x3
    //                               LAB_0050eb8b                                                 XREF[1]:     0050eb9b(j)  
    //                              tm_co_ob.cpp:82 (18)
    //         0050eb8b     PUSH       0x6
    //         0050eb8d     PUSH       EDI
    //         0050eb8e     PUSH       EBX
    //         0050eb8f     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050eb94     ADD        ESP,0xc
    //         0050eb97     ADD        EDI,0x6
    //         0050eb9a     DEC        EBP
    //         0050eb9b     JNZ        LAB_0050eb8b
    //                              tm_co_ob.cpp:83 (18)
    //         0050eb9d     LEA        EDX,[ESI + 0x15a]
    //         0050eba3     PUSH       0x2
    //         0050eba5     PUSH       EDX
    //         0050eba6     PUSH       EBX
    //         0050eba7     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050ebac     ADD        ESP,0xc
    //                              tm_co_ob.cpp:84 (18)
    //         0050ebaf     LEA        EAX,[ESI + 0x15c]
    //         0050ebb5     PUSH       0x2
    //         0050ebb7     PUSH       EAX
    //         0050ebb8     PUSH       EBX
    //         0050ebb9     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050ebbe     ADD        ESP,0xc
    //                              tm_co_ob.cpp:85 (15)
    //         0050ebc1     LEA        this,[ESI + 0x15e]
    //         0050ebc7     PUSH       0x1
    //         0050ebc9     PUSH       this
    //         0050ebca     PUSH       EBX
    //         0050ebcb     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              tm_co_ob.cpp:87 (22)
    //         0050ebd0     FLD        float ptr [save_game_version]                    = 7.23
    //         0050ebd6     FCOMP      float ptr [DAT_0057677c]                         = ECh
    //         0050ebdc     ADD        ESP,0xc
    //         0050ebdf     FNSTSW     AX
    //         0050ebe1     TEST       AH,0x1
    //         0050ebe4     JNZ        LAB_0050ec04
    //                              tm_co_ob.cpp:88 (18)
    //         0050ebe6     ADD        ESI,0x160
    //         0050ebec     PUSH       0x2
    //         0050ebee     PUSH       ESI
    //         0050ebef     PUSH       EBX
    //         0050ebf0     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050ebf5     ADD        ESP,0xc
    //                              tm_co_ob.cpp:106 (5)
    //         0050ebf8     MOV        EAX,0x1
    //                              tm_co_ob.cpp:107 (7)
    //         0050ebfd     POP        EDI
    //         0050ebfe     POP        ESI
    //         0050ebff     POP        EBP
    //         0050ec00     POP        EBX
    //         0050ec01     RET        0xc
    //                               LAB_0050ec04                                                 XREF[1]:     0050ebe4(j)  
    //                              tm_co_ob.cpp:92 (20)
    //         0050ec04     MOVSX      EDX,word ptr [ESI + 0x102]
    //         0050ec0b     TEST       EDX,EDX
    //         0050ec0d     MOV        word ptr [ESI + 0x160],0x0
    //         0050ec16     JLE        LAB_0050ec40
    //                              tm_co_ob.cpp:107 (8)
    //         0050ec18     MOV        EAX,dword ptr [ESI + 0x104]
    //         0050ec1e     MOV        EDI,EDX
    //                               LAB_0050ec20                                                 XREF[1]:     0050ec3e(j)  
    //                              tm_co_ob.cpp:94 (19)
    //         0050ec20     CMP        word ptr [EAX],0x3
    //         0050ec24     JNZ        LAB_0050ec3a
    //         0050ec26     MOV        this,word ptr [EAX + 0x2]
    //         0050ec2a     CMP        this,word ptr [ESI + 0x160]
    //         0050ec31     JLE        LAB_0050ec3a
    //                              tm_co_ob.cpp:95 (7)
    //         0050ec33     MOV        word ptr [ESI + 0x160],this
    //                               LAB_0050ec3a                                                 XREF[2]:     0050ec24(j), 0050ec31(j)  
    //                              tm_co_ob.cpp:92 (6)
    //         0050ec3a     ADD        EAX,0x4
    //         0050ec3d     DEC        EDI
    //         0050ec3e     JNZ        LAB_0050ec20
    //                               LAB_0050ec40                                                 XREF[1]:     0050ec16(j)  
    //                              tm_co_ob.cpp:98 (8)
    //         0050ec40     MOVZX      AX,byte ptr [ESI + 0x100]
    //                              tm_co_ob.cpp:99 (11)
    //         0050ec48     TEST       EDX,EDX
    //         0050ec4a     MOV        word ptr [ESI + 0x13c],AX
    //         0050ec51     JLE        LAB_0050ec79
    //                              tm_co_ob.cpp:98 (6)
    //         0050ec53     MOV        EAX,dword ptr [ESI + 0x104]
    //                               LAB_0050ec59                                                 XREF[1]:     0050ec77(j)  
    //                              tm_co_ob.cpp:101 (19)
    //         0050ec59     CMP        word ptr [EAX],0x3
    //         0050ec5d     JZ         LAB_0050ec73
    //         0050ec5f     MOV        this,word ptr [EAX + 0x2]
    //         0050ec63     CMP        this,word ptr [ESI + 0x13c]
    //         0050ec6a     JLE        LAB_0050ec73
    //                              tm_co_ob.cpp:102 (7)
    //         0050ec6c     MOV        word ptr [ESI + 0x13c],this
    //                               LAB_0050ec73                                                 XREF[2]:     0050ec5d(j), 0050ec6a(j)  
    //                              tm_co_ob.cpp:99 (6)
    //         0050ec73     ADD        EAX,0x4
    //         0050ec76     DEC        EDX
    //         0050ec77     JNZ        LAB_0050ec59
    //                               LAB_0050ec79                                                 XREF[1]:     0050ec51(j)  
    //                              tm_co_ob.cpp:107 (12)
    //         0050ec79     POP        EDI
    //         0050ec7a     POP        ESI
    //         0050ec7b     POP        EBP
    //         0050ec7c     MOV        EAX,0x1
    //         0050ec81     POP        EBX
    //         0050ec82     RET        0xc
    //         0050ec85     ??         90h
    //         0050ec86     NOP
    //         0050ec87     NOP
    //         0050ec88     NOP
    //         0050ec89     NOP
    //         0050ec8a     NOP
    //         0050ec8b     NOP
    //         0050ec8c     NOP
    //         0050ec8d     NOP
    //         0050ec8e     NOP
    //         0050ec8f     NOP
    //                              * protected: int __thiscall TRIBE_Master_Combat_Object::setup(struct _iobuf *,class RGE_Sprite * *,c... *
    //                              int __thiscall setup(TRIBE_Master_Combat_Object * this, _iobuf * par
    //              int               EAX:4          <RETURN>
    //              TRIBE_Master_C    ECX:4 (auto)   this
    //              _iobuf *          Stack[0x4]:4   param_1                   XREF[1]:     0050ec99(R)  
    //              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     0050ec94(R)  
    //              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[3]:     0050eca2(R), 0050ece5(*), 0050ed0a(R)  
    //              short             Stack[0x10]:2  param_4                   XREF[3]:     0050ec90(R), 0050ecc0(*), 0050ecd5(R)  
    //                               ?setup@TRIBE_Master_Combat_Object@@IAEHPAU_iobuf@@PAPAVRGE_  XREF[2]:     setup:0050e37a(c), 
    //                               TRIBE_Master_Combat_Object::setup                                         TRIBE_Master_Combat_Object:0050eab
    //                              tm_co_ob.cpp:111 (33)
    //         0050ec90     MOV        EAX,dword ptr [ESP + param_4]
    //         0050ec94     MOV        EDX,dword ptr [ESP + param_2]
    //         0050ec98     PUSH       EBX
    //         0050ec99     MOV        EBX,dword ptr [ESP + param_1]
    //         0050ec9d     PUSH       EBP
    //         0050ec9e     PUSH       ESI
    //         0050ec9f     PUSH       EDI
    //         0050eca0     MOV        EDI,this
    //         0050eca2     MOV        this,dword ptr [ESP + param_3]
    //         0050eca6     PUSH       EAX
    //         0050eca7     PUSH       this
    //         0050eca8     PUSH       EDX
    //         0050eca9     PUSH       EBX
    //         0050ecaa     MOV        this,EDI
    //         0050ecac     CALL       RGE_Master_Combat_Object::setup                  int setup(RGE_Master_Combat_Object * this, _i
    //                              tm_co_ob.cpp:119 (15)
    //         0050ecb1     MOV        byte ptr [EDI + 0x4],0x46
    //         0050ecb5     LEA        ESI,[EDI + 0x148]
    //         0050ecbb     MOV        EBP,0x3
    //                               LAB_0050ecc0                                                 XREF[1]:     0050ece3(j)  
    //                              tm_co_ob.cpp:126 (21)
    //         0050ecc0     LEA        EAX=>param_4,[ESP + 0x20]
    //         0050ecc4     LEA        this,[ESI + 0x2]
    //         0050ecc7     PUSH       EAX
    //         0050ecc8     PUSH       this
    //         0050ecc9     PUSH       ESI
    //         0050ecca     PUSH       s_%hd_%hd_%hd                                    = "%hd %hd %hd"
    //         0050eccf     PUSH       EBX
    //         0050ecd0     CALL       fscanf                                           undefined fscanf()
    //                              tm_co_ob.cpp:127 (16)
    //         0050ecd5     MOV        DL,byte ptr [ESP + param_4]
    //         0050ecd9     ADD        ESP,0x14
    //         0050ecdc     MOV        byte ptr [ESI + 0x4],DL
    //         0050ecdf     ADD        ESI,0x6
    //         0050ece2     DEC        EBP
    //         0050ece3     JNZ        LAB_0050ecc0
    //                              tm_co_ob.cpp:129 (30)
    //         0050ece5     LEA        EAX=>param_3,[ESP + 0x1c]
    //         0050ece9     LEA        this,[EDI + 0x15c]
    //         0050ecef     PUSH       EAX
    //         0050ecf0     LEA        EDX,[EDI + 0x15a]
    //         0050ecf6     PUSH       this
    //         0050ecf7     PUSH       EDX
    //         0050ecf8     PUSH       s_%hd_%hd_%hd                                    = "%hd %hd %hd"
    //         0050ecfd     PUSH       EBX
    //         0050ecfe     CALL       fscanf                                           undefined fscanf()
    //                              tm_co_ob.cpp:134 (33)
    //         0050ed03     MOVSX      EDX,word ptr [EDI + 0x102]
    //         0050ed0a     MOV        AL,byte ptr [ESP + param_3]
    //         0050ed0e     ADD        ESP,0x14
    //         0050ed11     TEST       EDX,EDX
    //         0050ed13     MOV        byte ptr [EDI + 0x15e],AL
    //         0050ed19     MOV        word ptr [EDI + 0x160],0x0
    //         0050ed22     JLE        LAB_0050ed4c
    //                              tm_co_ob.cpp:148 (8)
    //         0050ed24     MOV        EAX,dword ptr [EDI + 0x104]
    //         0050ed2a     MOV        ESI,EDX
    //                               LAB_0050ed2c                                                 XREF[1]:     0050ed4a(j)  
    //                              tm_co_ob.cpp:136 (19)
    //         0050ed2c     CMP        word ptr [EAX],0x3
    //         0050ed30     JNZ        LAB_0050ed46
    //         0050ed32     MOV        this,word ptr [EAX + 0x2]
    //         0050ed36     CMP        this,word ptr [EDI + 0x160]
    //         0050ed3d     JLE        LAB_0050ed46
    //                              tm_co_ob.cpp:137 (7)
    //         0050ed3f     MOV        word ptr [EDI + 0x160],this
    //                               LAB_0050ed46                                                 XREF[2]:     0050ed30(j), 0050ed3d(j)  
    //                              tm_co_ob.cpp:134 (6)
    //         0050ed46     ADD        EAX,0x4
    //         0050ed49     DEC        ESI
    //         0050ed4a     JNZ        LAB_0050ed2c
    //                               LAB_0050ed4c                                                 XREF[1]:     0050ed22(j)  
    //                              tm_co_ob.cpp:140 (8)
    //         0050ed4c     MOVZX      this,byte ptr [EDI + 0x100]
    //                              tm_co_ob.cpp:141 (11)
    //         0050ed54     TEST       EDX,EDX
    //         0050ed56     MOV        word ptr [EDI + 0x13c],this
    //         0050ed5d     JLE        LAB_0050ed85
    //                              tm_co_ob.cpp:140 (6)
    //         0050ed5f     MOV        EAX,dword ptr [EDI + 0x104]
    //                               LAB_0050ed65                                                 XREF[1]:     0050ed83(j)  
    //                              tm_co_ob.cpp:143 (19)
    //         0050ed65     CMP        word ptr [EAX],0x3
    //         0050ed69     JZ         LAB_0050ed7f
    //         0050ed6b     MOV        this,word ptr [EAX + 0x2]
    //         0050ed6f     CMP        this,word ptr [EDI + 0x13c]
    //         0050ed76     JLE        LAB_0050ed7f
    //                              tm_co_ob.cpp:144 (7)
    //         0050ed78     MOV        word ptr [EDI + 0x13c],this
    //                               LAB_0050ed7f                                                 XREF[2]:     0050ed69(j), 0050ed76(j)  
    //                              tm_co_ob.cpp:141 (6)
    //         0050ed7f     ADD        EAX,0x4
    //         0050ed82     DEC        EDX
    //         0050ed83     JNZ        LAB_0050ed65
    //                               LAB_0050ed85                                                 XREF[1]:     0050ed5d(j)  
    //                              tm_co_ob.cpp:148 (12)
    //         0050ed85     POP        EDI
    //         0050ed86     POP        ESI
    //         0050ed87     POP        EBP
    //         0050ed88     MOV        EAX,0x1
    //         0050ed8d     POP        EBX
    //         0050ed8e     RET        0x10
    //         0050ed91     ??         90h
    //         0050ed92     NOP
    //         0050ed93     NOP
    //         0050ed94     NOP
    //         0050ed95     NOP
    //         0050ed96     NOP
    //         0050ed97     NOP
    //         0050ed98     NOP
    //         0050ed99     NOP
    //         0050ed9a     NOP
    //         0050ed9b     NOP
    //         0050ed9c     NOP
    //         0050ed9d     NOP
    //         0050ed9e     NOP
    //         0050ed9f     NOP
    return 0;
}

TRIBE_Master_Combat_Object::~TRIBE_Master_Combat_Object() {
    /* TODO: Stub */
    //                              void __thiscall ~TRIBE_Master_Combat_Object(TRIBE_Master_Combat_Obje
    //              void              <VOID>         <RETURN>
    //              TRIBE_Master_C    ECX:4 (auto)   this
    //                               ??1TRIBE_Master_Combat_Object@@UAE@XZ                        XREF[2]:     ~TRIBE_Master_Building_Object:0050
    //                               TRIBE_Master_Combat_Object::~TRIBE_Master_Combat_Object                   `vector_deleting_destructor':0050e
    //                              tm_co_ob.cpp:152 (11)
    //         0050eda0     MOV        dword ptr [this->_padding_],TRIBE_Master_Comba   = 0050e9d0
    //         0050eda6     JMP        RGE_Master_Combat_Object::~RGE_Master_Combat_O   void ~RGE_Master_Combat_Object(RGE_Master_Com
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
    //         0050edab     ??         90h
    //         0050edac     NOP
    //         0050edad     NOP
    //         0050edae     NOP
    //         0050edaf     NOP
}

RGE_Task_List* TRIBE_Master_Combat_Object::create_task_list() {
    /* TODO: Stub */
    //                              RGE_Task_List * __thiscall create_task_list(TRIBE_Master_Combat_Obje
    //              RGE_Task_List *   EAX:4          <RETURN>
    //              TRIBE_Master_C    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0050eddb(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0050edf0(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0050edd3(W)  
    //                               ?create_task_list@TRIBE_Master_Combat_Object@@UAEPAVRGE_Tas  XREF[2]:     00576738(*), 00576778(*)  
    //                               TRIBE_Master_Combat_Object::create_task_list
    //                              tm_co_ob.cpp:157 (23)
    //         0050edb0     PUSH       -0x1
    //         0050edb2     PUSH       FUN_00560f4b
    //         0050edb7     MOV        EAX,FS:[0x0]
    //         0050edbd     PUSH       EAX
    //         0050edbe     MOV        dword ptr FS:[0x0],ESP
    //         0050edc5     PUSH       this
    //         0050edc6     PUSH       ESI
    //                              tm_co_ob.cpp:158 (41)
    //         0050edc7     PUSH       0xc
    //         0050edc9     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0050edce     MOV        ESI,EAX
    //         0050edd0     ADD        ESP,0x4
    //         0050edd3     MOV        dword ptr [ESP + local_10],ESI
    //         0050edd7     XOR        EAX,EAX
    //         0050edd9     CMP        ESI,EAX
    //         0050eddb     MOV        dword ptr [ESP + local_4],EAX
    //         0050eddf     JZ         LAB_0050edf0
    //         0050ede1     MOV        this,ESI
    //         0050ede3     CALL       RGE_Task_List::RGE_Task_List                     undefined RGE_Task_List(RGE_Task_List * this)
    //         0050ede8     MOV        dword ptr [ESI],TRIBE_Task_List::`vftable'       = 005090b0
    //         0050edee     MOV        EAX,ESI
    //                               LAB_0050edf0                                                 XREF[1]:     0050eddf(j)  
    //                              tm_co_ob.cpp:159 (16)
    //         0050edf0     MOV        this,dword ptr [ESP + local_c]
    //         0050edf4     POP        ESI
    //         0050edf5     MOV        dword ptr FS:[0x0],this
    //         0050edfc     ADD        ESP,0x10
    //         0050edff     RET
    //                              * public: virtual void __thiscall TRIBE_Master_Combat_Object::copy_obj(class RGE_Master_Static_Objec... *
    //                              void __thiscall copy_obj(TRIBE_Master_Combat_Object * this, RGE_Mast
    //              void              <VOID>         <RETURN>
    //              TRIBE_Master_C    ECX:4 (auto)   this
    //              RGE_Master_Sta    Stack[0x4]:4   param_1                   XREF[2]:     0050ee04(R), 0050ee36(R)  
    //                               ?copy_obj@TRIBE_Master_Combat_Object@@UAEXPAVRGE_Master_Sta  XREF[2]:     copy_obj:0050e449(c), 00576744(*)  
    //                               TRIBE_Master_Combat_Object::copy_obj
    //                              tm_co_ob.cpp:163 (4)
    //         0050ee00     PUSH       EBX
    //         0050ee01     PUSH       EBP
    //         0050ee02     PUSH       ESI
    //         0050ee03     PUSH       EDI
    //                              tm_co_ob.cpp:167 (12)
    //         0050ee04     MOV        EDI,dword ptr [ESP + param_1]
    //         0050ee08     MOV        ESI,this
    //         0050ee0a     PUSH       EDI
    //         0050ee0b     CALL       RGE_Master_Combat_Object::copy_obj               void copy_obj(RGE_Master_Combat_Object * this
    //                              tm_co_ob.cpp:169 (18)
    //         0050ee10     MOV        this,EDI
    //         0050ee12     LEA        EAX,[ESI + 0x148]
    //         0050ee18     SUB        this,ESI
    //         0050ee1a     MOV        EDX,0x3
    //                               LAB_0050ee1f                                                 XREF[1]:     0050ee34(j)  
    //         0050ee1f     LEA        EDI,[this->_padding_ + EAX*0x1]
    //                              tm_co_ob.cpp:170 (20)
    //         0050ee22     MOV        EBX,EAX
    //         0050ee24     ADD        EAX,0x6
    //         0050ee27     DEC        EDX
    //         0050ee28     MOV        EBP,dword ptr [EDI]
    //         0050ee2a     MOV        dword ptr [EBX],EBP
    //         0050ee2c     MOV        DI,word ptr [EDI + 0x4]
    //         0050ee30     MOV        word ptr [EBX + 0x4],DI
    //         0050ee34     JNZ        LAB_0050ee1f
    //                              tm_co_ob.cpp:171 (4)
    //         0050ee36     MOV        EAX,dword ptr [ESP + param_1]
    //                              tm_co_ob.cpp:176 (61)
    //         0050ee3a     POP        EDI
    //         0050ee3b     MOV        this,word ptr [EAX + 0x15a]
    //         0050ee42     MOV        word ptr [ESI + 0x15a],this
    //         0050ee49     MOV        DX,word ptr [EAX + 0x15c]
    //         0050ee50     MOV        word ptr [ESI + 0x15c],DX
    //         0050ee57     MOV        this,byte ptr [EAX + 0x15e]
    //         0050ee5d     MOV        byte ptr [ESI + 0x15e],this
    //         0050ee63     MOV        DX,word ptr [EAX + 0x160]
    //         0050ee6a     MOV        word ptr [ESI + 0x160],DX
    //         0050ee71     POP        ESI
    //         0050ee72     POP        EBP
    //         0050ee73     POP        EBX
    //         0050ee74     RET        0x4
    //         0050ee77     ??         90h
    //         0050ee78     NOP
    //         0050ee79     NOP
    //         0050ee7a     NOP
    //         0050ee7b     NOP
    //         0050ee7c     NOP
    //         0050ee7d     NOP
    //         0050ee7e     NOP
    //         0050ee7f     NOP
    return 0;
}

void TRIBE_Master_Combat_Object::modify(float param_1, uchar param_2) {
    /* TODO: Stub */
    //                              void __thiscall modify(TRIBE_Master_Combat_Object * this, float para
    //              void              <VOID>         <RETURN>
    //              TRIBE_Master_C    ECX:4 (auto)   this
    //              float             Stack[0x4]:4   param_1                   XREF[6]:     0050ee9c(R), 0050eec1(R), 0050eeea(R), 0050ef08(R), 
    //                                                                                     0050ef28(R), 0050ef51(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[1]:     0050ee85(R)  
    //                               ?modify@TRIBE_Master_Combat_Object@@UAEXME@Z                 XREF[2]:     modify:0050e4e1(c), 00576748(*)  
    //                               TRIBE_Master_Combat_Object::modify
    //                              tm_co_ob.cpp:180 (5)
    //         0050ee80     PUSH       EBX
    //         0050ee81     PUSH       ESI
    //         0050ee82     PUSH       EDI
    //         0050ee83     MOV        EDI,this
    //                              tm_co_ob.cpp:183 (23)
    //         0050ee85     MOV        this,dword ptr [ESP + param_2]
    //         0050ee89     MOV        EAX,this
    //         0050ee8b     AND        EAX,0xff
    //         0050ee90     SUB        EAX,0x64
    //         0050ee93     JZ         LAB_0050ef3f
    //         0050ee99     DEC        EAX
    //         0050ee9a     JZ         LAB_0050eeaf
    //                              tm_co_ob.cpp:208 (13)
    //         0050ee9c     MOV        EAX,dword ptr [ESP + param_1]
    //         0050eea0     PUSH       this
    //         0050eea1     PUSH       EAX
    //         0050eea2     MOV        this,EDI
    //         0050eea4     CALL       RGE_Master_Combat_Object::modify                 void modify(RGE_Master_Combat_Object * this, 
    //                              tm_co_ob.cpp:211 (59)
    //         0050eea9     POP        EDI
    //         0050eeaa     POP        ESI
    //         0050eeab     POP        EBX
    //         0050eeac     RET        0x8
    //                               LAB_0050eeaf                                                 XREF[1]:     0050ee9a(j)  
    //         0050eeaf     LEA        ESI,[EDI + 0x14a]
    //         0050eeb5     MOV        EBX,0x3
    //                               LAB_0050eeba                                                 XREF[1]:     0050eed3(j)  
    //         0050eeba     MOV        AL,byte ptr [ESI + 0x2]
    //         0050eebd     TEST       AL,AL
    //         0050eebf     JNZ        LAB_0050eecf
    //         0050eec1     FLD        float ptr [ESP + param_1]
    //         0050eec5     FCHS
    //         0050eec7     CALL       __ftol                                           undefined __ftol()
    //         0050eecc     MOV        word ptr [ESI],AX
    //                               LAB_0050eecf                                                 XREF[1]:     0050eebf(j)  
    //         0050eecf     ADD        ESI,0x6
    //         0050eed2     DEC        EBX
    //         0050eed3     JNZ        LAB_0050eeba
    //         0050eed5     LEA        ESI,[EDI + 0x70]
    //         0050eed8     ADD        EDI,0x6a
    //         0050eedb     MOV        this,ESI
    //         0050eedd     MOV        EAX,EDI
    //         0050eedf     MOV        EDX,0x3
    //                               LAB_0050eee4                                                 XREF[1]:     0050eef7(j)  
    //                              tm_co_ob.cpp:196 (6)
    //         0050eee4     CMP        word ptr [EAX],0x4
    //         0050eee8     JNZ        LAB_0050eef0
    //                              tm_co_ob.cpp:197 (15)
    //         0050eeea     MOV        EBX,dword ptr [ESP + param_1]
    //         0050eeee     MOV        dword ptr [this->_padding_],EBX
    //                               LAB_0050eef0                                                 XREF[1]:     0050eee8(j)  
    //         0050eef0     ADD        EAX,0x2
    //         0050eef3     ADD        this,0x4
    //         0050eef6     DEC        EDX
    //         0050eef7     JNZ        LAB_0050eee4
    //                              tm_co_ob.cpp:211 (9)
    //         0050eef9     MOV        this,ESI
    //         0050eefb     MOV        EAX,EDI
    //         0050eefd     MOV        EDX,0x3
    //                               LAB_0050ef02                                                 XREF[1]:     0050ef17(j)  
    //                              tm_co_ob.cpp:200 (6)
    //         0050ef02     CMP        word ptr [EAX],0xb
    //         0050ef06     JNZ        LAB_0050ef10
    //                              tm_co_ob.cpp:201 (17)
    //         0050ef08     FLD        float ptr [ESP + param_1]
    //         0050ef0c     FCHS
    //         0050ef0e     FSTP       float ptr [this->_padding_]
    //                               LAB_0050ef10                                                 XREF[1]:     0050ef06(j)  
    //         0050ef10     ADD        EAX,0x2
    //         0050ef13     ADD        this,0x4
    //         0050ef16     DEC        EDX
    //         0050ef17     JNZ        LAB_0050ef02
    //                              tm_co_ob.cpp:211 (9)
    //         0050ef19     MOV        this,ESI
    //         0050ef1b     MOV        EAX,EDI
    //         0050ef1d     MOV        EDX,0x3
    //                               LAB_0050ef22                                                 XREF[1]:     0050ef37(j)  
    //                              tm_co_ob.cpp:204 (6)
    //         0050ef22     CMP        word ptr [EAX],0x13
    //         0050ef26     JNZ        LAB_0050ef30
    //                              tm_co_ob.cpp:205 (17)
    //         0050ef28     FLD        float ptr [ESP + param_1]
    //         0050ef2c     FCHS
    //         0050ef2e     FSTP       float ptr [this->_padding_]
    //                               LAB_0050ef30                                                 XREF[1]:     0050ef26(j)  
    //         0050ef30     ADD        EAX,0x2
    //         0050ef33     ADD        this,0x4
    //         0050ef36     DEC        EDX
    //         0050ef37     JNZ        LAB_0050ef22
    //                              tm_co_ob.cpp:211 (48)
    //         0050ef39     POP        EDI
    //         0050ef3a     POP        ESI
    //         0050ef3b     POP        EBX
    //         0050ef3c     RET        0x8
    //                               LAB_0050ef3f                                                 XREF[1]:     0050ee93(j)  
    //         0050ef3f     LEA        ESI,[EDI + 0x14a]
    //         0050ef45     MOV        EDI,0x3
    //                               LAB_0050ef4a                                                 XREF[1]:     0050ef61(j)  
    //         0050ef4a     MOV        AL,byte ptr [ESI + 0x2]
    //         0050ef4d     TEST       AL,AL
    //         0050ef4f     JZ         LAB_0050ef5d
    //         0050ef51     FLD        float ptr [ESP + param_1]
    //         0050ef55     CALL       __ftol                                           undefined __ftol()
    //         0050ef5a     MOV        word ptr [ESI],AX
    //                               LAB_0050ef5d                                                 XREF[1]:     0050ef4f(j)  
    //         0050ef5d     ADD        ESI,0x6
    //         0050ef60     DEC        EDI
    //         0050ef61     JNZ        LAB_0050ef4a
    //         0050ef63     POP        EDI
    //         0050ef64     POP        ESI
    //         0050ef65     POP        EBX
    //         0050ef66     RET        0x8
    //         0050ef69     ??         90h
    //         0050ef6a     NOP
    //         0050ef6b     NOP
    //         0050ef6c     NOP
    //         0050ef6d     NOP
    //         0050ef6e     NOP
    //         0050ef6f     NOP
    return;
}

void TRIBE_Master_Combat_Object::modify_delta(float param_1, uchar param_2) {
    /* TODO: Stub */
    //                              void __thiscall modify_delta(TRIBE_Master_Combat_Object * this, floa
    //              void              <VOID>         <RETURN>
    //              TRIBE_Master_C    ECX:4 (auto)   this
    //              float             Stack[0x4]:4   param_1                   XREF[2]:     0050ef79(R), 0050ef9a(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[1]:     0050ef70(R)  
    //                               ?modify_delta@TRIBE_Master_Combat_Object@@UAEXME@Z           XREF[2]:     modify_delta:0050e511(c), 
    //                               TRIBE_Master_Combat_Object::modify_delta                                  0057674c(*)  
    //                              tm_co_ob.cpp:215 (8)
    //         0050ef70     MOV        EAX,dword ptr [ESP + param_2]
    //         0050ef74     CMP        AL,0x64
    //         0050ef76     JZ         LAB_0050ef86
    //                              tm_co_ob.cpp:226 (11)
    //         0050ef78     PUSH       EAX
    //         0050ef79     MOV        EAX,dword ptr [ESP + param_1]
    //         0050ef7d     PUSH       EAX
    //         0050ef7e     CALL       RGE_Master_Combat_Object::modify_delta           void modify_delta(RGE_Master_Combat_Object * 
    //                              tm_co_ob.cpp:229 (3)
    //         0050ef83     RET        0x8
    //                               LAB_0050ef86                                                 XREF[1]:     0050ef76(j)  
    //                              tm_co_ob.cpp:215 (2)
    //         0050ef86     PUSH       EDI
    //         0050ef87     PUSH       ESI
    //                              tm_co_ob.cpp:229 (41)
    //         0050ef88     LEA        ESI,[ECX + this+0x14a]
    //         0050ef8e     MOV        EDI,0x3
    //                               LAB_0050ef93                                                 XREF[1]:     0050efaa(j)  
    //         0050ef93     MOV        AL,byte ptr [ESI + 0x2]
    //         0050ef96     TEST       AL,AL
    //         0050ef98     JZ         LAB_0050efa6
    //         0050ef9a     FLD        float ptr [ESP + param_1]
    //         0050ef9e     CALL       __ftol                                           undefined __ftol()
    //         0050efa3     ADD        word ptr [ESI],AX
    //                               LAB_0050efa6                                                 XREF[1]:     0050ef98(j)  
    //         0050efa6     ADD        ESI,0x6
    //         0050efa9     DEC        EDI
    //         0050efaa     JNZ        LAB_0050ef93
    //         0050efac     POP        ESI
    //         0050efad     POP        EDI
    //         0050efae     RET        0x8
    //         0050efb1     ??         90h
    //         0050efb2     NOP
    //         0050efb3     NOP
    //         0050efb4     NOP
    //         0050efb5     NOP
    //         0050efb6     NOP
    //         0050efb7     NOP
    //         0050efb8     NOP
    //         0050efb9     NOP
    //         0050efba     NOP
    //         0050efbb     NOP
    //         0050efbc     NOP
    //         0050efbd     NOP
    //         0050efbe     NOP
    //         0050efbf     NOP
    return;
}

void TRIBE_Master_Combat_Object::modify_percent(float param_1, uchar param_2) {
    /* TODO: Stub */
    //                              void __thiscall modify_percent(TRIBE_Master_Combat_Object * this, fl
    //              void              <VOID>         <RETURN>
    //              TRIBE_Master_C    ECX:4 (auto)   this
    //              float             Stack[0x4]:4   param_1                   XREF[2]:     0050efc9(R), 0050eff5(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[3]:     0050efc0(R), 0050efed(W), 0050eff1(R)  
    //                               ?modify_percent@TRIBE_Master_Combat_Object@@UAEXME@Z         XREF[2]:     modify_percent:0050e53a(c), 
    //                               TRIBE_Master_Combat_Object::modify_percent                                00576750(*)  
    //                              tm_co_ob.cpp:233 (8)
    //         0050efc0     MOV        EAX,dword ptr [ESP + param_2]
    //         0050efc4     CMP        AL,0x64
    //         0050efc6     JZ         LAB_0050efd6
    //                              tm_co_ob.cpp:244 (11)
    //         0050efc8     PUSH       EAX
    //         0050efc9     MOV        EAX,dword ptr [ESP + param_1]
    //         0050efcd     PUSH       EAX
    //         0050efce     CALL       RGE_Master_Combat_Object::modify_percent         void modify_percent(RGE_Master_Combat_Object 
    //                              tm_co_ob.cpp:247 (3)
    //         0050efd3     RET        0x8
    //                               LAB_0050efd6                                                 XREF[1]:     0050efc6(j)  
    //                              tm_co_ob.cpp:233 (2)
    //         0050efd6     PUSH       EDI
    //         0050efd7     PUSH       ESI
    //                              tm_co_ob.cpp:247 (52)
    //         0050efd8     LEA        ESI,[ECX + this+0x14a]
    //         0050efde     MOV        EDI,0x3
    //                               LAB_0050efe3                                                 XREF[1]:     0050f005(j)  
    //         0050efe3     MOV        AL,byte ptr [ESI + 0x2]
    //         0050efe6     TEST       AL,AL
    //         0050efe8     JZ         LAB_0050f001
    //         0050efea     MOVSX      this,word ptr [ESI]
    //         0050efed     MOV        dword ptr [ESP + param_2],this
    //         0050eff1     FILD       dword ptr [ESP + param_2]
    //         0050eff5     FMUL       float ptr [ESP + param_1]
    //         0050eff9     CALL       __ftol                                           undefined __ftol()
    //         0050effe     MOV        word ptr [ESI],AX
    //                               LAB_0050f001                                                 XREF[1]:     0050efe8(j)  
    //         0050f001     ADD        ESI,0x6
    //         0050f004     DEC        EDI
    //         0050f005     JNZ        LAB_0050efe3
    //         0050f007     POP        ESI
    //         0050f008     POP        EDI
    //         0050f009     RET        0x8
    //         0050f00c     ??         90h
    //         0050f00d     NOP
    //         0050f00e     NOP
    //         0050f00f     NOP
    return;
}

void TRIBE_Master_Combat_Object::save(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall save(TRIBE_Master_Combat_Object * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Master_C    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0050f014(R)  
    //                               ?save@TRIBE_Master_Combat_Object@@UAEXH@Z                    XREF[2]:     save:0050e55a(c), 00576754(*)  
    //                               TRIBE_Master_Combat_Object::save
    //                              tm_co_ob.cpp:251 (4)
    //         0050f010     PUSH       EBX
    //         0050f011     PUSH       EBP
    //         0050f012     PUSH       ESI
    //         0050f013     PUSH       EDI
    //                              tm_co_ob.cpp:254 (23)
    //         0050f014     MOV        EDI,dword ptr [ESP + param_1]
    //         0050f018     MOV        EBP,this
    //         0050f01a     PUSH       EDI
    //         0050f01b     CALL       RGE_Master_Combat_Object::save                   void save(RGE_Master_Combat_Object * this, in
    //         0050f020     LEA        ESI,[EBP + 0x148]
    //         0050f026     MOV        EBX,0x3
    //                               LAB_0050f02b                                                 XREF[1]:     0050f03b(j)  
    //                              tm_co_ob.cpp:257 (18)
    //         0050f02b     PUSH       0x6
    //         0050f02d     PUSH       ESI
    //         0050f02e     PUSH       EDI
    //         0050f02f     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050f034     ADD        ESP,0xc
    //         0050f037     ADD        ESI,0x6
    //         0050f03a     DEC        EBX
    //         0050f03b     JNZ        LAB_0050f02b
    //                              tm_co_ob.cpp:258 (18)
    //         0050f03d     LEA        EAX,[EBP + 0x15a]
    //         0050f043     PUSH       0x2
    //         0050f045     PUSH       EAX
    //         0050f046     PUSH       EDI
    //         0050f047     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050f04c     ADD        ESP,0xc
    //                              tm_co_ob.cpp:259 (18)
    //         0050f04f     LEA        this,[EBP + 0x15c]
    //         0050f055     PUSH       0x2
    //         0050f057     PUSH       this
    //         0050f058     PUSH       EDI
    //         0050f059     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050f05e     ADD        ESP,0xc
    //                              tm_co_ob.cpp:260 (18)
    //         0050f061     LEA        EDX,[EBP + 0x15e]
    //         0050f067     PUSH       0x1
    //         0050f069     PUSH       EDX
    //         0050f06a     PUSH       EDI
    //         0050f06b     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050f070     ADD        ESP,0xc
    //                              tm_co_ob.cpp:261 (18)
    //         0050f073     ADD        EBP,0x160
    //         0050f079     PUSH       0x2
    //         0050f07b     PUSH       EBP
    //         0050f07c     PUSH       EDI
    //         0050f07d     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050f082     ADD        ESP,0xc
    //                              tm_co_ob.cpp:262 (7)
    //         0050f085     POP        EDI
    //         0050f086     POP        ESI
    //         0050f087     POP        EBP
    //         0050f088     POP        EBX
    //         0050f089     RET        0x4
    //         0050f08c     ??         90h
    //         0050f08d     NOP
    //         0050f08e     NOP
    //         0050f08f     NOP
    //                              * public: virtual class RGE_Static_Object * __thiscall TRIBE_Master_Combat_Object::make_new_obj(clas... *
    //                              RGE_Static_Object * __thiscall make_new_obj(TRIBE_Master_Combat_Obje
    //              RGE_Static_Obj    EAX:4          <RETURN>
    //              TRIBE_Master_C    ECX:4 (auto)   this
    //              RGE_Player *      Stack[0x4]:4   param_1                   XREF[1]:     0050f0d6(R)  
    //              float             Stack[0x8]:4   param_2                   XREF[1]:     0050f0d1(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[1]:     0050f0ca(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[1]:     0050f0c6(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0050f0bc(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     0050f0e4(R), 0050f0f6(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0050f0b6(W)  
    //                               ?make_new_obj@TRIBE_Master_Combat_Object@@UAEPAVRGE_Static_  XREF[1]:     00576758(*)  
    //                               TRIBE_Master_Combat_Object::make_new_obj
    //                              tm_co_ob.cpp:266 (25)
    //         0050f090     PUSH       -0x1
    //         0050f092     PUSH       FUN_00560f6b
    //         0050f097     MOV        EAX,FS:[0x0]
    //         0050f09d     PUSH       EAX
    //         0050f09e     MOV        dword ptr FS:[0x0],ESP
    //         0050f0a5     PUSH       this
    //         0050f0a6     PUSH       ESI
    //         0050f0a7     MOV        ESI,this
    //                              tm_co_ob.cpp:267 (59)
    //         0050f0a9     PUSH       0x1c8
    //         0050f0ae     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0050f0b3     ADD        ESP,0x4
    //         0050f0b6     MOV        dword ptr [ESP + local_10],EAX
    //         0050f0ba     TEST       EAX,EAX
    //         0050f0bc     MOV        dword ptr [ESP + local_4],0x0
    //         0050f0c4     JZ         LAB_0050f0f6
    //         0050f0c6     MOV        this,dword ptr [ESP + param_4]
    //         0050f0ca     MOV        EDX,dword ptr [ESP + param_3]
    //         0050f0ce     PUSH       0x1
    //         0050f0d0     PUSH       this
    //         0050f0d1     MOV        this,dword ptr [ESP + param_2]
    //         0050f0d5     PUSH       EDX
    //         0050f0d6     MOV        EDX,dword ptr [ESP + param_1]
    //         0050f0da     PUSH       this
    //         0050f0db     PUSH       EDX
    //         0050f0dc     PUSH       ESI
    //         0050f0dd     MOV        this,EAX
    //         0050f0df     CALL       TRIBE_Combat_Object::TRIBE_Combat_Object         undefined TRIBE_Combat_Object(TRIBE_Combat_Ob
    //                              tm_co_ob.cpp:268 (38)
    //         0050f0e4     MOV        this,dword ptr [ESP + local_c]
    //         0050f0e8     MOV        dword ptr FS:[0x0],this
    //         0050f0ef     POP        ESI
    //         0050f0f0     ADD        ESP,0x10
    //         0050f0f3     RET        0x10
    //                               LAB_0050f0f6                                                 XREF[1]:     0050f0c4(j)  
    //         0050f0f6     MOV        this,dword ptr [ESP + local_c]
    //         0050f0fa     XOR        EAX,EAX
    //         0050f0fc     MOV        dword ptr FS:[0x0],this
    //         0050f103     POP        ESI
    //         0050f104     ADD        ESP,0x10
    //         0050f107     RET        0x10
    //         0050f10a     ??         90h
    //         0050f10b     NOP
    //         0050f10c     NOP
    //         0050f10d     NOP
    //         0050f10e     NOP
    //         0050f10f     NOP
    //                              * public: virtual class RGE_Master_Static_Object * __thiscall TRIBE_Master_Combat_Object::make_new_m... *
    //                              RGE_Master_Static_Object * __thiscall make_new_master(TRIBE_Master_C
    //              RGE_Master_Sta    EAX:4          <RETURN>
    //              TRIBE_Master_C    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0050f13c(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     0050f150(R), 0050f160(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0050f136(W)  
    //                               ?make_new_master@TRIBE_Master_Combat_Object@@UAEPAVRGE_Mast  XREF[1]:     0057675c(*)  
    //                               TRIBE_Master_Combat_Object::make_new_master
    //                              tm_co_ob.cpp:272 (25)
    //         0050f110     PUSH       -0x1
    //         0050f112     PUSH       FUN_00560f8b
    //         0050f117     MOV        EAX,FS:[0x0]
    //         0050f11d     PUSH       EAX
    //         0050f11e     MOV        dword ptr FS:[0x0],ESP
    //         0050f125     PUSH       this
    //         0050f126     PUSH       ESI
    //         0050f127     MOV        ESI,this
    //                              tm_co_ob.cpp:273 (39)
    //         0050f129     PUSH       0x164
    //         0050f12e     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0050f133     ADD        ESP,0x4
    //         0050f136     MOV        dword ptr [ESP + local_10],EAX
    //         0050f13a     TEST       EAX,EAX
    //         0050f13c     MOV        dword ptr [ESP + local_4],0x0
    //         0050f144     JZ         LAB_0050f160
    //         0050f146     PUSH       0x1
    //         0050f148     PUSH       ESI
    //         0050f149     MOV        this,EAX
    //         0050f14b     CALL       TRIBE_Master_Combat_Object::TRIBE_Master_Comba   undefined TRIBE_Master_Combat_Object(TRIBE_Ma
    //                              tm_co_ob.cpp:274 (34)
    //         0050f150     MOV        this,dword ptr [ESP + local_c]
    //         0050f154     MOV        dword ptr FS:[0x0],this
    //         0050f15b     POP        ESI
    //         0050f15c     ADD        ESP,0x10
    //         0050f15f     RET
    //                               LAB_0050f160                                                 XREF[1]:     0050f144(j)  
    //         0050f160     MOV        this,dword ptr [ESP + local_c]
    //         0050f164     XOR        EAX,EAX
    //         0050f166     MOV        dword ptr FS:[0x0],this
    //         0050f16d     POP        ESI
    //         0050f16e     ADD        ESP,0x10
    //         0050f171     RET
    //         0050f172     ??         90h
    //         0050f173     NOP
    //         0050f174     NOP
    //         0050f175     NOP
    //         0050f176     NOP
    //         0050f177     NOP
    //         0050f178     NOP
    //         0050f179     NOP
    //         0050f17a     NOP
    //         0050f17b     NOP
    //         0050f17c     NOP
    //         0050f17d     NOP
    //         0050f17e     NOP
    //         0050f17f     NOP
    //                              * public: __thiscall TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object(class TRIBE_Master_Tree_Obje... *
    //                              undefined __thiscall TRIBE_Master_Tree_Object(TRIBE_Master_Tree_Obje
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TRIBE_Master_T    ECX:4 (auto)   this
    //              TRIBE_Master_T    Stack[0x4]:4   param_1                   XREF[1]:     0050f198(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0050f1aa(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0050f1ae(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0050f1cc(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0050f1a1(W)  
    //                               ??0TRIBE_Master_Tree_Object@@QAE@PAV0@H@Z                    XREF[1]:     make_new_master:0050f3db(c)  
    //                               TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object
    //                              tm_tre_o.cpp:21 (42)
    //         0050f180     PUSH       -0x1
    //         0050f182     PUSH       FUN_00560fa8
    //         0050f187     MOV        EAX,FS:[0x0]
    //         0050f18d     PUSH       EAX
    //         0050f18e     MOV        dword ptr FS:[0x0],ESP
    //         0050f195     PUSH       this
    //         0050f196     PUSH       ESI
    //         0050f197     PUSH       EDI
    //         0050f198     MOV        EDI,dword ptr [ESP + param_1]
    //         0050f19c     MOV        ESI,this
    //         0050f19e     PUSH       0x0
    //         0050f1a0     PUSH       EDI
    //         0050f1a1     MOV        dword ptr [ESP + local_10],ESI
    //         0050f1a5     CALL       RGE_Master_Static_Object::RGE_Master_Static_Ob   undefined RGE_Master_Static_Object(RGE_Master
    //                              tm_tre_o.cpp:22 (22)
    //         0050f1aa     MOV        EAX,dword ptr [ESP + param_2]
    //         0050f1ae     MOV        dword ptr [ESP + local_4],0x0
    //         0050f1b6     TEST       EAX,EAX
    //         0050f1b8     MOV        dword ptr [ESI],TRIBE_Master_Tree_Object::`vft   = 0050f1f0
    //         0050f1be     JZ         LAB_0050f1cc
    //                              tm_tre_o.cpp:24 (8)
    //         0050f1c0     PUSH       EDI
    //         0050f1c1     MOV        this,ESI
    //         0050f1c3     CALL       RGE_Master_Static_Object::setup                  int setup(RGE_Master_Static_Object * this, RG
    //                              tm_tre_o.cpp:25 (4)
    //         0050f1c8     MOV        byte ptr [ESI + 0x4],0x5a
    //                               LAB_0050f1cc                                                 XREF[1]:     0050f1be(j)  
    //                              tm_tre_o.cpp:27 (21)
    //         0050f1cc     MOV        this,dword ptr [ESP + local_c]
    //         0050f1d0     MOV        EAX,ESI
    //         0050f1d2     POP        EDI
    //         0050f1d3     MOV        dword ptr FS:[0x0],this
    //         0050f1da     POP        ESI
    //         0050f1db     ADD        ESP,0x10
    //         0050f1de     RET        0x8
    //         0050f1e1     ??         90h
    //         0050f1e2     NOP
    //         0050f1e3     NOP
    //         0050f1e4     NOP
    //         0050f1e5     NOP
    //         0050f1e6     NOP
    //         0050f1e7     NOP
    //         0050f1e8     NOP
    //         0050f1e9     NOP
    //         0050f1ea     NOP
    //         0050f1eb     NOP
    //         0050f1ec     NOP
    //         0050f1ed     NOP
    //         0050f1ee     NOP
    //         0050f1ef     NOP
    //                              * public: virtual void * __thiscall TRIBE_Master_Tree_Object::`scalar deleting destructor'(unsigned ... *
    //                              void * __thiscall `scalar_deleting_destructor'(TRIBE_Master_Tree_Obj
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Master_T    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0050f1f8(R)  
    //                               ??_ETRIBE_Master_Tree_Object@@UAEPAXI@Z                      XREF[1]:     00576790(*)  
    //                               ??_GTRIBE_Master_Tree_Object@@UAEPAXI@Z
    //                               TRIBE_Master_Tree_Object::`scalar_deleting_destructor'
    //         0050f1f0     PUSH       ESI
    //         0050f1f1     MOV        ESI,this
    //         0050f1f3     CALL       TRIBE_Master_Tree_Object::~TRIBE_Master_Tree_O   void ~TRIBE_Master_Tree_Object(TRIBE_Master_T
    //         0050f1f8     TEST       byte ptr [ESP + param_1],0x1
    //         0050f1fd     JZ         LAB_0050f208
    //         0050f1ff     PUSH       ESI
    //         0050f200     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0050f205     ADD        ESP,0x4
    //                               LAB_0050f208                                                 XREF[1]:     0050f1fd(j)  
    //         0050f208     MOV        EAX,ESI
    //         0050f20a     POP        ESI
    //         0050f20b     RET        0x4
    //                              *                                            THUNK FUNCTION                                             *
    //                              thunk void __thiscall ~RGE_Master_Static_Object(RGE_Master_Static_Ob
    //                                Thunked-Function: RGE_Master_Static_Objec
    //              void              <VOID>         <RETURN>
    //              RGE_Master_Sta    ECX:4 (auto)   this
    //                               RGE_Master_Static_Object::~RGE_Master_Static_Object
    //         0050f20e     NOP
    //         0050f20f     NOP
    return;
}

TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object(TRIBE_Master_Combat_Object* param_1, int param_2) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
}

TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
}

TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
}

void TRIBE_Master_Combat_Object::copy_obj(RGE_Master_Static_Object* param_1) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return;
}

RGE_Static_Object* TRIBE_Master_Combat_Object::make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

RGE_Master_Static_Object* TRIBE_Master_Combat_Object::make_new_master() {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

