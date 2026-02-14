// Auto-generated scaffold unit: tm_b_obj.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/tm_b_obj.cpp
#include "../include/common.h"

// Offset: 0x0050E040
undefined TRIBE_Master_Building_Object(TRIBE_Master_Building_Object* this_, TRIBE_Master_Building_Object* param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TRIBE_Master_Building_Object::TRIBE_Master_Building_Object(class TRIBE_Master_B... *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TRIBE_Master_Building_Object(TRIBE_Master_Build
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TRIBE_Master_B    ECX:4 (auto)   this
    //              TRIBE_Master_B    Stack[0x4]:4   param_1                   XREF[1]:     0050e058(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0050e06a(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0050e06e(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0050e088(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0050e061(W)  
    //                               ??0TRIBE_Master_Building_Object@@QAE@PAV0@H@Z                XREF[1]:     make_new_master:0050e76b(c)  
    //                               TRIBE_Master_Building_Object::TRIBE_Master_Building_Object
    //                              tm_b_obj.cpp:30 (42)
    //         0050e040     PUSH       -0x1
    //         0050e042     PUSH       FUN_00560e28
    //         0050e047     MOV        EAX,FS:[0x0]
    //         0050e04d     PUSH       EAX
    //         0050e04e     MOV        dword ptr FS:[0x0],ESP
    //         0050e055     PUSH       this
    //         0050e056     PUSH       ESI
    //         0050e057     PUSH       EDI
    //         0050e058     MOV        EDI,dword ptr [ESP + param_1]
    //         0050e05c     MOV        ESI,this
    //         0050e05e     PUSH       0x0
    //         0050e060     PUSH       EDI
    //         0050e061     MOV        dword ptr [ESP + local_10],ESI
    //         0050e065     CALL       TRIBE_Master_Combat_Object::TRIBE_Master_Comba   undefined TRIBE_Master_Combat_Object(TRIBE_Ma
    //                              tm_b_obj.cpp:31 (22)
    //         0050e06a     MOV        EAX,dword ptr [ESP + param_2]
    //         0050e06e     MOV        dword ptr [ESP + local_4],0x0
    //         0050e076     TEST       EAX,EAX
    //         0050e078     MOV        dword ptr [ESI],TRIBE_Master_Building_Object::   = 0050e0a0
    //         0050e07e     JZ         LAB_0050e088
    //                              tm_b_obj.cpp:32 (8)
    //         0050e080     PUSH       EDI
    //         0050e081     MOV        this,ESI
    //         0050e083     CALL       TRIBE_Master_Building_Object::setup              int setup(TRIBE_Master_Building_Object * this
    //                               LAB_0050e088                                                 XREF[1]:     0050e07e(j)  
    //                              tm_b_obj.cpp:33 (21)
    //         0050e088     MOV        this,dword ptr [ESP + local_c]
    //         0050e08c     MOV        EAX,ESI
    //         0050e08e     POP        EDI
    //         0050e08f     MOV        dword ptr FS:[0x0],this
    //         0050e096     POP        ESI
    //         0050e097     ADD        ESP,0x10
    //         0050e09a     RET        0x8
}

// Offset: 0x0050E0C0
undefined TRIBE_Master_Building_Object(TRIBE_Master_Building_Object* this_, int param_2, RGE_Sprite** param_3, RGE_Sound** param_4, int param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TRIBE_Master_Building_Object::TRIBE_Master_Building_Object(int,class RGE_Sprite... *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TRIBE_Master_Building_Object(TRIBE_Master_Build
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TRIBE_Master_B    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0050e0dc(R)  
    //              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     0050e0d7(R)  
    //              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[1]:     0050e0e2(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     0050e0f6(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0050e0fa(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0050e116(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0050e0ed(W)  
    //                               ??0TRIBE_Master_Building_Object@@QAE@HPAPAVRGE_Sprite@@PAPA  XREF[3]:     setup:004ca4ad(c), 
    //                               TRIBE_Master_Building_Object::TRIBE_Master_Building_Object                load_master_object:005118f8(c), 
    //                                                                                                         load_master_object:00512b58(c)  
    //                              tm_b_obj.cpp:38 (54)
    //         0050e0c0     PUSH       -0x1
    //         0050e0c2     PUSH       FUN_00560e48
    //         0050e0c7     MOV        EAX,FS:[0x0]
    //         0050e0cd     PUSH       EAX
    //         0050e0ce     MOV        dword ptr FS:[0x0],ESP
    //         0050e0d5     PUSH       this
    //         0050e0d6     PUSH       EBX
    //         0050e0d7     MOV        EBX,dword ptr [ESP + param_2]
    //         0050e0db     PUSH       EBP
    //         0050e0dc     MOV        EBP,dword ptr [ESP + param_1]
    //         0050e0e0     PUSH       ESI
    //         0050e0e1     PUSH       EDI
    //         0050e0e2     MOV        EDI,dword ptr [ESP + param_3]
    //         0050e0e6     PUSH       0x0
    //         0050e0e8     PUSH       EDI
    //         0050e0e9     MOV        ESI,this
    //         0050e0eb     PUSH       EBX
    //         0050e0ec     PUSH       EBP
    //         0050e0ed     MOV        dword ptr [ESP + local_10],ESI
    //         0050e0f1     CALL       TRIBE_Master_Combat_Object::TRIBE_Master_Comba   undefined TRIBE_Master_Combat_Object(TRIBE_Ma
    //                              tm_b_obj.cpp:39 (22)
    //         0050e0f6     MOV        EAX,dword ptr [ESP + param_4]
    //         0050e0fa     MOV        dword ptr [ESP + local_4],0x0
    //         0050e102     TEST       EAX,EAX
    //         0050e104     MOV        dword ptr [ESI],TRIBE_Master_Building_Object::   = 0050e0a0
    //         0050e10a     JZ         LAB_0050e116
    //                              tm_b_obj.cpp:40 (10)
    //         0050e10c     PUSH       EDI
    //         0050e10d     PUSH       EBX
    //         0050e10e     PUSH       EBP
    //         0050e10f     MOV        this,ESI
    //         0050e111     CALL       TRIBE_Master_Building_Object::setup              int setup(TRIBE_Master_Building_Object * this
    //                               LAB_0050e116                                                 XREF[1]:     0050e10a(j)  
    //                              tm_b_obj.cpp:41 (23)
    //         0050e116     MOV        this,dword ptr [ESP + local_c]
    //         0050e11a     MOV        EAX,ESI
    //         0050e11c     POP        EDI
    //         0050e11d     POP        ESI
    //         0050e11e     POP        EBP
    //         0050e11f     MOV        dword ptr FS:[0x0],this
    //         0050e126     POP        EBX
    //         0050e127     ADD        ESP,0x10
    //         0050e12a     RET        0x10
}

// Offset: 0x0050E130
undefined TRIBE_Master_Building_Object(TRIBE_Master_Building_Object* this_, FILE* param_2, RGE_Sprite** param_3, RGE_Sound** param_4, short param_5, int param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TRIBE_Master_Building_Object::TRIBE_Master_Building_Object(struct _iobuf *,clas... *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TRIBE_Master_Building_Object(TRIBE_Master_Build
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TRIBE_Master_B    ECX:4 (auto)   this
    //              _iobuf *          Stack[0x4]:4   param_1                   XREF[2]:     0050e146(R), 0050e181(R)  
    //              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     0050e150(R)  
    //              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[1]:     0050e14b(R)  
    //              short             Stack[0x10]:2  param_4                   XREF[1]:     0050e156(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[1]:     0050e16b(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0050e16f(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0050e190(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0050e162(W)  
    //                               ??0TRIBE_Master_Building_Object@@QAE@PAU_iobuf@@PAPAVRGE_Sp  XREF[1]:     load_object:00511a64(c)  
    //                               TRIBE_Master_Building_Object::TRIBE_Master_Building_Object
    //                              tm_b_obj.cpp:46 (59)
    //         0050e130     PUSH       -0x1
    //         0050e132     PUSH       FUN_00560e68
    //         0050e137     MOV        EAX,FS:[0x0]
    //         0050e13d     PUSH       EAX
    //         0050e13e     MOV        dword ptr FS:[0x0],ESP
    //         0050e145     PUSH       this
    //         0050e146     MOV        EAX,dword ptr [ESP + param_1]
    //         0050e14a     PUSH       EBX
    //         0050e14b     MOV        EBX,dword ptr [ESP + param_3]
    //         0050e14f     PUSH       EBP
    //         0050e150     MOV        EBP,dword ptr [ESP + param_2]
    //         0050e154     PUSH       ESI
    //         0050e155     PUSH       EDI
    //         0050e156     MOV        EDI,dword ptr [ESP + param_4]
    //         0050e15a     PUSH       0x0
    //         0050e15c     PUSH       EDI
    //         0050e15d     PUSH       EBX
    //         0050e15e     MOV        ESI,this
    //         0050e160     PUSH       EBP
    //         0050e161     PUSH       EAX
    //         0050e162     MOV        dword ptr [ESP + local_10],ESI
    //         0050e166     CALL       TRIBE_Master_Combat_Object::TRIBE_Master_Comba   undefined TRIBE_Master_Combat_Object(TRIBE_Ma
    //                              tm_b_obj.cpp:47 (22)
    //         0050e16b     MOV        EAX,dword ptr [ESP + param_5]
    //         0050e16f     MOV        dword ptr [ESP + local_4],0x0
    //         0050e177     TEST       EAX,EAX
    //         0050e179     MOV        dword ptr [ESI],TRIBE_Master_Building_Object::   = 0050e0a0
    //         0050e17f     JZ         LAB_0050e190
    //                              tm_b_obj.cpp:48 (15)
    //         0050e181     MOV        this,dword ptr [ESP + param_1]
    //         0050e185     PUSH       EDI
    //         0050e186     PUSH       EBX
    //         0050e187     PUSH       EBP
    //         0050e188     PUSH       this
    //         0050e189     MOV        this,ESI
    //         0050e18b     CALL       TRIBE_Master_Building_Object::setup              int setup(TRIBE_Master_Building_Object * this
    //                               LAB_0050e190                                                 XREF[1]:     0050e17f(j)  
    //                              tm_b_obj.cpp:49 (23)
    //         0050e190     MOV        this,dword ptr [ESP + local_c]
    //         0050e194     MOV        EAX,ESI
    //         0050e196     POP        EDI
    //         0050e197     POP        ESI
    //         0050e198     POP        EBP
    //         0050e199     MOV        dword ptr FS:[0x0],this
    //         0050e1a0     POP        EBX
    //         0050e1a1     ADD        ESP,0x10
    //         0050e1a4     RET        0x14
}

// Offset: 0x0050E1B0
int setup(TRIBE_Master_Building_Object* this_, TRIBE_Master_Building_Object* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: int __thiscall TRIBE_Master_Building_Object::setup(class TRIBE_Master_Building_Object *)   *
    //                              *********************************************************************************************************
    //                              int __thiscall setup(TRIBE_Master_Building_Object * this, TRIBE_Mast
    //              int               EAX:4          <RETURN>
    //              TRIBE_Master_B    ECX:4 (auto)   this
    //              TRIBE_Master_B    Stack[0x4]:4   param_1                   XREF[1]:     0050e1b2(R)  
    //                               ?setup@TRIBE_Master_Building_Object@@IAEHPAV1@@Z             XREF[1]:     TRIBE_Master_Building_Object:0050e
    //                               TRIBE_Master_Building_Object::setup
    //                              tm_b_obj.cpp:53 (2)
    //         0050e1b0     PUSH       ESI
    //         0050e1b1     PUSH       EDI
    //                              tm_b_obj.cpp:54 (12)
    //         0050e1b2     MOV        EDI,dword ptr [ESP + param_1]
    //         0050e1b6     MOV        ESI,this
    //         0050e1b8     PUSH       EDI
    //         0050e1b9     CALL       TRIBE_Master_Combat_Object::setup                int setup(TRIBE_Master_Combat_Object * this, 
    //                              tm_b_obj.cpp:56 (4)
    //         0050e1be     MOV        byte ptr [ESI + 0x4],0x50
    //                              tm_b_obj.cpp:58 (12)
    //         0050e1c2     MOV        EAX,dword ptr [EDI + 0x168]
    //         0050e1c8     MOV        dword ptr [ESI + 0x168],EAX
    //                              tm_b_obj.cpp:59 (12)
    //         0050e1ce     MOV        this,byte ptr [EDI + 0x16c]
    //         0050e1d4     MOV        byte ptr [ESI + 0x16c],this
    //                              tm_b_obj.cpp:60 (14)
    //         0050e1da     MOV        DX,word ptr [EDI + 0x16e]
    //         0050e1e1     MOV        word ptr [ESI + 0x16e],DX
    //                              tm_b_obj.cpp:61 (12)
    //         0050e1e8     MOV        AL,byte ptr [EDI + 0x170]
    //         0050e1ee     MOV        byte ptr [ESI + 0x170],AL
    //                              tm_b_obj.cpp:62 (14)
    //         0050e1f4     MOV        this,word ptr [EDI + 0x172]
    //         0050e1fb     MOV        word ptr [ESI + 0x172],this
    //                              tm_b_obj.cpp:63 (14)
    //         0050e202     MOV        DX,word ptr [EDI + 0x174]
    //         0050e209     MOV        word ptr [ESI + 0x174],DX
    //                              tm_b_obj.cpp:64 (14)
    //         0050e210     MOV        AX,word ptr [EDI + 0x176]
    //         0050e217     MOV        word ptr [ESI + 0x176],AX
    //                              tm_b_obj.cpp:65 (14)
    //         0050e21e     MOV        this,word ptr [EDI + 0x178]
    //         0050e225     MOV        word ptr [ESI + 0x178],this
    //                              tm_b_obj.cpp:66 (12)
    //         0050e22c     MOV        EDX,dword ptr [EDI + 0x164]
    //         0050e232     MOV        dword ptr [ESI + 0x164],EDX
    //                              tm_b_obj.cpp:69 (10)
    //         0050e238     POP        EDI
    //         0050e239     MOV        EAX,0x1
    //         0050e23e     POP        ESI
    //         0050e23f     RET        0x4
}

// Offset: 0x0050E250
int setup(TRIBE_Master_Building_Object* this_, int param_2, RGE_Sprite** param_3, RGE_Sound** param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: int __thiscall TRIBE_Master_Building_Object::setup(int,class RGE_Sprite * *,class RGE_S... *
    //                              *********************************************************************************************************
    //                              int __thiscall setup(TRIBE_Master_Building_Object * this, int param_
    //              int               EAX:4          <RETURN>
    //              TRIBE_Master_B    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0050e25c(R)  
    //              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[3]:     0050e251(R), 0050e2fc(*), 0050e321(R)  
    //              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[3]:     0050e256(R), 0050e26a(*), 0050e309(R)  
    //                               ?setup@TRIBE_Master_Building_Object@@IAEHHPAPAVRGE_Sprite@@  XREF[1]:     TRIBE_Master_Building_Object:0050e
    //                               TRIBE_Master_Building_Object::setup
    //                              tm_b_obj.cpp:73 (1)
    //         0050e250     PUSH       EBX
    //                              tm_b_obj.cpp:77 (25)
    //         0050e251     MOV        EBX,dword ptr [ESP + param_2]
    //         0050e255     PUSH       EBP
    //         0050e256     MOV        EBP,dword ptr [ESP + param_3]
    //         0050e25a     PUSH       ESI
    //         0050e25b     PUSH       EDI
    //         0050e25c     MOV        EDI,dword ptr [ESP + param_1]
    //         0050e260     PUSH       EBP
    //         0050e261     PUSH       EBX
    //         0050e262     MOV        ESI,this
    //         0050e264     PUSH       EDI
    //         0050e265     CALL       TRIBE_Master_Combat_Object::setup                int setup(TRIBE_Master_Combat_Object * this, 
    //                              tm_b_obj.cpp:81 (20)
    //         0050e26a     LEA        EAX=>param_3,[ESP + 0x1c]
    //         0050e26e     PUSH       0x2
    //         0050e270     PUSH       EAX
    //         0050e271     PUSH       EDI
    //         0050e272     MOV        byte ptr [ESI + 0x4],0x50
    //         0050e276     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050e27b     ADD        ESP,0xc
    //                              tm_b_obj.cpp:82 (18)
    //         0050e27e     LEA        this,[ESI + 0x16c]
    //         0050e284     PUSH       0x1
    //         0050e286     PUSH       this
    //         0050e287     PUSH       EDI
    //         0050e288     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050e28d     ADD        ESP,0xc
    //                              tm_b_obj.cpp:83 (18)
    //         0050e290     LEA        EDX,[ESI + 0x16e]
    //         0050e296     PUSH       0x2
    //         0050e298     PUSH       EDX
    //         0050e299     PUSH       EDI
    //         0050e29a     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050e29f     ADD        ESP,0xc
    //                              tm_b_obj.cpp:84 (18)
    //         0050e2a2     LEA        EAX,[ESI + 0x170]
    //         0050e2a8     PUSH       0x1
    //         0050e2aa     PUSH       EAX
    //         0050e2ab     PUSH       EDI
    //         0050e2ac     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050e2b1     ADD        ESP,0xc
    //                              tm_b_obj.cpp:85 (18)
    //         0050e2b4     LEA        this,[ESI + 0x172]
    //         0050e2ba     PUSH       0x2
    //         0050e2bc     PUSH       this
    //         0050e2bd     PUSH       EDI
    //         0050e2be     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050e2c3     ADD        ESP,0xc
    //                              tm_b_obj.cpp:86 (18)
    //         0050e2c6     LEA        EDX,[ESI + 0x174]
    //         0050e2cc     PUSH       0x2
    //         0050e2ce     PUSH       EDX
    //         0050e2cf     PUSH       EDI
    //         0050e2d0     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050e2d5     ADD        ESP,0xc
    //                              tm_b_obj.cpp:87 (18)
    //         0050e2d8     LEA        EAX,[ESI + 0x176]
    //         0050e2de     PUSH       0x2
    //         0050e2e0     PUSH       EAX
    //         0050e2e1     PUSH       EDI
    //         0050e2e2     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050e2e7     ADD        ESP,0xc
    //                              tm_b_obj.cpp:88 (18)
    //         0050e2ea     LEA        this,[ESI + 0x178]
    //         0050e2f0     PUSH       0x2
    //         0050e2f2     PUSH       this
    //         0050e2f3     PUSH       EDI
    //         0050e2f4     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0050e2f9     ADD        ESP,0xc
    //                              tm_b_obj.cpp:89 (13)
    //         0050e2fc     LEA        EDX=>param_2,[ESP + 0x18]
    //         0050e300     PUSH       0x2
    //         0050e302     PUSH       EDX
    //         0050e303     PUSH       EDI
    //         0050e304     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              tm_b_obj.cpp:91 (24)
    //         0050e309     MOV        AX,word ptr [ESP + param_3]
    //         0050e30e     ADD        ESP,0xc
    //         0050e311     CMP        AX,0xffff
    //         0050e315     JLE        LAB_0050e31f
    //         0050e317     MOVSX      EAX,AX
    //         0050e31a     MOV        EBX,dword ptr [EBX + EAX*0x4]
    //         0050e31d     JMP        LAB_0050e321
    //                               LAB_0050e31f                                                 XREF[1]:     0050e315(j)  
    //         0050e31f     XOR        EBX,EBX
    //                               LAB_0050e321                                                 XREF[1]:     0050e31d(j)  
    //                              tm_b_obj.cpp:92 (30)
    //         0050e321     MOV        AX,word ptr [ESP + param_2]
    //         0050e326     MOV        dword ptr [ESI + 0x168],EBX
    //         0050e32c     CMP        AX,0xffff
    //         0050e330     JLE        LAB_0050e34b
    //         0050e332     MOVSX      this,AX
    //         0050e335     MOV        EAX,dword ptr [EBP + this->_padding_*0x4]
    //         0050e339     MOV        dword ptr [ESI + 0x164],EAX
    //                              tm_b_obj.cpp:94 (5)
    //         0050e33f     MOV        EAX,0x1
    //                              tm_b_obj.cpp:95 (7)
    //         0050e344     POP        EDI
    //         0050e345     POP        ESI
    //         0050e346     POP        EBP
    //         0050e347     POP        EBX
    //         0050e348     RET        0xc
    //                               LAB_0050e34b                                                 XREF[1]:     0050e330(j)  
    //                              tm_b_obj.cpp:92 (2)
    //         0050e34b     XOR        EAX,EAX
    //                              tm_b_obj.cpp:95 (18)
    //         0050e34d     POP        EDI
    //         0050e34e     MOV        dword ptr [ESI + 0x164],EAX
    //         0050e354     POP        ESI
    //         0050e355     POP        EBP
    //         0050e356     MOV        EAX,0x1
    //         0050e35b     POP        EBX
    //         0050e35c     RET        0xc
}

// Offset: 0x0050E360
int setup(TRIBE_Master_Building_Object* this_, FILE* param_2, RGE_Sprite** param_3, RGE_Sound** param_4, short param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: int __thiscall TRIBE_Master_Building_Object::setup(struct _iobuf *,class RGE_Sprite * *... *
    //                              *********************************************************************************************************
    //                              int __thiscall setup(TRIBE_Master_Building_Object * this, _iobuf * p
    //              int               EAX:4          <RETURN>
    //              TRIBE_Master_B    ECX:4 (auto)   this
    //              _iobuf *          Stack[0x4]:4   param_1                   XREF[3]:     0050e370(R), 0050e37f(*), 0050e3f1(R)  
    //              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[3]:     0050e365(R), 0050e3b0(*), 0050e3c5(R)  
    //              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[3]:     0050e36a(R), 0050e39f(*), 0050e3ce(R)  
    //              short             Stack[0x10]:2  param_4                   XREF[3]:     0050e360(R), 0050e3ab(*), 0050e3ca(R)  
    //                               ?setup@TRIBE_Master_Building_Object@@IAEHPAU_iobuf@@PAPAVRG  XREF[1]:     TRIBE_Master_Building_Object:0050e
    //                               TRIBE_Master_Building_Object::setup
    //                              tm_b_obj.cpp:99 (31)
    //         0050e360     MOV        EAX,dword ptr [ESP + param_4]
    //         0050e364     PUSH       EBX
    //         0050e365     MOV        EBX,dword ptr [ESP + param_2]
    //         0050e369     PUSH       EBP
    //         0050e36a     MOV        EBP,dword ptr [ESP + param_3]
    //         0050e36e     PUSH       ESI
    //         0050e36f     PUSH       EDI
    //         0050e370     MOV        EDI,dword ptr [ESP + param_1]
    //         0050e374     PUSH       EAX
    //         0050e375     PUSH       EBP
    //         0050e376     PUSH       EBX
    //         0050e377     MOV        ESI,this
    //         0050e379     PUSH       EDI
    //         0050e37a     CALL       TRIBE_Master_Combat_Object::setup                int setup(TRIBE_Master_Combat_Object * this, 
    //                              tm_b_obj.cpp:118 (70)
    //         0050e37f     LEA        this=>param_1,[ESP + 0x14]
    //         0050e383     LEA        EDX,[ESI + 0x178]
    //         0050e389     PUSH       this
    //         0050e38a     LEA        EAX,[ESI + 0x176]
    //         0050e390     PUSH       EDX
    //         0050e391     LEA        this,[ESI + 0x174]
    //         0050e397     PUSH       EAX
    //         0050e398     LEA        EDX,[ESI + 0x172]
    //         0050e39e     PUSH       this
    //         0050e39f     LEA        EAX=>param_3,[ESP + 0x2c]
    //         0050e3a3     PUSH       EDX
    //         0050e3a4     LEA        this,[ESI + 0x16e]
    //         0050e3aa     PUSH       EAX
    //         0050e3ab     LEA        EDX=>param_4,[ESP + 0x38]
    //         0050e3af     PUSH       this
    //         0050e3b0     LEA        EAX=>param_2,[ESP + 0x34]
    //         0050e3b4     PUSH       EDX
    //         0050e3b5     PUSH       EAX
    //         0050e3b6     PUSH       s_%hd_%hd_%hd_%hd_%hd_%hd_%hd_%hd_               = "%hd %hd %hd %hd %hd %hd %hd %hd %hd"
    //         0050e3bb     PUSH       EDI
    //         0050e3bc     MOV        byte ptr [ESI + 0x4],0x50
    //         0050e3c0     CALL       fscanf                                           undefined fscanf()
    //                              tm_b_obj.cpp:123 (44)
    //         0050e3c5     MOV        AX,word ptr [ESP + param_2]
    //         0050e3ca     MOV        this,byte ptr [ESP + param_4]
    //         0050e3ce     MOV        DL,byte ptr [ESP + param_3]
    //         0050e3d2     ADD        ESP,0x2c
    //         0050e3d5     CMP        AX,0xffff
    //         0050e3d9     MOV        byte ptr [ESI + 0x16c],this
    //         0050e3df     MOV        byte ptr [ESI + 0x170],DL
    //         0050e3e5     JLE        LAB_0050e3ef
    //         0050e3e7     MOVSX      EAX,AX
    //         0050e3ea     MOV        EBX,dword ptr [EBX + EAX*0x4]
    //         0050e3ed     JMP        LAB_0050e3f1
    //                               LAB_0050e3ef                                                 XREF[1]:     0050e3e5(j)  
    //         0050e3ef     XOR        EBX,EBX
    //                               LAB_0050e3f1                                                 XREF[1]:     0050e3ed(j)  
    //                              tm_b_obj.cpp:124 (30)
    //         0050e3f1     MOV        AX,word ptr [ESP + param_1]
    //         0050e3f6     MOV        dword ptr [ESI + 0x168],EBX
    //         0050e3fc     CMP        AX,0xffff
    //         0050e400     JLE        LAB_0050e41b
    //         0050e402     MOVSX      this,AX
    //         0050e405     MOV        EAX,dword ptr [EBP + this->_padding_*0x4]
    //         0050e409     MOV        dword ptr [ESI + 0x164],EAX
    //                              tm_b_obj.cpp:126 (5)
    //         0050e40f     MOV        EAX,0x1
    //                              tm_b_obj.cpp:127 (7)
    //         0050e414     POP        EDI
    //         0050e415     POP        ESI
    //         0050e416     POP        EBP
    //         0050e417     POP        EBX
    //         0050e418     RET        0x10
    //                               LAB_0050e41b                                                 XREF[1]:     0050e400(j)  
    //                              tm_b_obj.cpp:124 (2)
    //         0050e41b     XOR        EAX,EAX
    //                              tm_b_obj.cpp:127 (18)
    //         0050e41d     POP        EDI
    //         0050e41e     MOV        dword ptr [ESI + 0x164],EAX
    //         0050e424     POP        ESI
    //         0050e425     POP        EBP
    //         0050e426     MOV        EAX,0x1
    //         0050e42b     POP        EBX
    //         0050e42c     RET        0x10
}

// Offset: 0x0050E430
void TRIBE_Master_Building_Object(TRIBE_Master_Building_Object* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall TRIBE_Master_Building_Object::~TRIBE_Master_Building_Object(void)          *
    //                              *********************************************************************************************************
    //                              void __thiscall ~TRIBE_Master_Building_Object(TRIBE_Master_Building_
    //              void              <VOID>         <RETURN>
    //              TRIBE_Master_B    ECX:4 (auto)   this
    //                               ??1TRIBE_Master_Building_Object@@UAE@XZ                      XREF[1]:     `vector_deleting_destructor':0050e
    //                               TRIBE_Master_Building_Object::~TRIBE_Master_Building_Object
    //                              tm_b_obj.cpp:132 (11)
    //         0050e430     MOV        dword ptr [this->_padding_],TRIBE_Master_Build   = 0050e0a0
    //         0050e436     JMP        TRIBE_Master_Combat_Object::~TRIBE_Master_Comb   void ~TRIBE_Master_Combat_Object(TRIBE_Master
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0050E440
void TRIBE_Master_Building_Object::copy_obj(RGE_Master_Static_Object* param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall TRIBE_Master_Building_Object::copy_obj(class RGE_Master_Static_Obj... *
    //                              *********************************************************************************************************
    //                              void __thiscall copy_obj(TRIBE_Master_Building_Object * this, RGE_Ma
    //              void              <VOID>         <RETURN>
    //              TRIBE_Master_B    ECX:4 (auto)   this
    //              RGE_Master_Sta    Stack[0x4]:4   param_1                   XREF[1]:     0050e442(R)  
    //                               ?copy_obj@TRIBE_Master_Building_Object@@UAEXPAVRGE_Master_S  XREF[1]:     00576704(*)  
    //                               TRIBE_Master_Building_Object::copy_obj
    //                              tm_b_obj.cpp:137 (2)
    //         0050e440     PUSH       ESI
    //         0050e441     PUSH       EDI
    //                              tm_b_obj.cpp:140 (12)
    //         0050e442     MOV        EDI,dword ptr [ESP + param_1]
    //         0050e446     MOV        ESI,this
    //         0050e448     PUSH       EDI
    //         0050e449     CALL       TRIBE_Master_Combat_Object::copy_obj             void copy_obj(TRIBE_Master_Combat_Object * th
    //                              tm_b_obj.cpp:142 (12)
    //         0050e44e     MOV        EAX,dword ptr [EDI + 0x168]
    //         0050e454     MOV        dword ptr [ESI + 0x168],EAX
    //                              tm_b_obj.cpp:143 (12)
    //         0050e45a     MOV        this,dword ptr [EDI + 0x164]
    //         0050e460     MOV        dword ptr [ESI + 0x164],this
    //                              tm_b_obj.cpp:144 (12)
    //         0050e466     MOV        DL,byte ptr [EDI + 0x16c]
    //         0050e46c     MOV        byte ptr [ESI + 0x16c],DL
    //                              tm_b_obj.cpp:145 (14)
    //         0050e472     MOV        AX,word ptr [EDI + 0x16e]
    //         0050e479     MOV        word ptr [ESI + 0x16e],AX
    //                              tm_b_obj.cpp:146 (12)
    //         0050e480     MOV        this,byte ptr [EDI + 0x170]
    //         0050e486     MOV        byte ptr [ESI + 0x170],this
    //                              tm_b_obj.cpp:147 (14)
    //         0050e48c     MOV        DX,word ptr [EDI + 0x172]
    //         0050e493     MOV        word ptr [ESI + 0x172],DX
    //                              tm_b_obj.cpp:148 (14)
    //         0050e49a     MOV        AX,word ptr [EDI + 0x174]
    //         0050e4a1     MOV        word ptr [ESI + 0x174],AX
    //                              tm_b_obj.cpp:149 (14)
    //         0050e4a8     MOV        this,word ptr [EDI + 0x176]
    //         0050e4af     MOV        word ptr [ESI + 0x176],this
    //                              tm_b_obj.cpp:150 (14)
    //         0050e4b6     MOV        DX,word ptr [EDI + 0x178]
    //         0050e4bd     MOV        word ptr [ESI + 0x178],DX
    //                              tm_b_obj.cpp:151 (5)
    //         0050e4c4     POP        EDI
    //         0050e4c5     POP        ESI
    //         0050e4c6     RET        0x4
}

// Offset: 0x0050E4D0
void TRIBE_Master_Building_Object::modify(float param_1, uchar param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall TRIBE_Master_Building_Object::modify(float,unsigned char)             *
    //                              *********************************************************************************************************
    //                              void __thiscall modify(TRIBE_Master_Building_Object * this, float pa
    //              void              <VOID>         <RETURN>
    //              TRIBE_Master_B    ECX:4 (auto)   this
    //              float             Stack[0x4]:4   param_1                   XREF[2]:     0050e4dc(R), 0050e4ea(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[1]:     0050e4d0(R)  
    //                               ?modify@TRIBE_Master_Building_Object@@UAEXME@Z               XREF[1]:     00576708(*)  
    //                               TRIBE_Master_Building_Object::modify
    //                              tm_b_obj.cpp:155 (11)
    //         0050e4d0     MOV        EAX,dword ptr [ESP + param_2]
    //         0050e4d4     PUSH       ESI
    //         0050e4d5     CMP        AL,0x11
    //         0050e4d7     MOV        ESI,this
    //         0050e4d9     JZ         LAB_0050e4ea
    //                              tm_b_obj.cpp:162 (11)
    //         0050e4db     PUSH       EAX
    //         0050e4dc     MOV        EAX,dword ptr [ESP + param_1]
    //         0050e4e0     PUSH       EAX
    //         0050e4e1     CALL       TRIBE_Master_Combat_Object::modify               void modify(TRIBE_Master_Combat_Object * this
    //                              tm_b_obj.cpp:165 (4)
    //         0050e4e6     POP        ESI
    //         0050e4e7     RET        0x8
    //                               LAB_0050e4ea                                                 XREF[1]:     0050e4d9(j)  
    //                              tm_b_obj.cpp:159 (16)
    //         0050e4ea     FLD        float ptr [ESP + param_1]
    //         0050e4ee     CALL       __ftol                                           undefined __ftol()
    //         0050e4f3     MOV        word ptr [ESI + 0x16e],AX
    //                              tm_b_obj.cpp:165 (4)
    //         0050e4fa     POP        ESI
    //         0050e4fb     RET        0x8
}

// Offset: 0x0050E500
void TRIBE_Master_Building_Object::modify_delta(float param_1, uchar param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall TRIBE_Master_Building_Object::modify_delta(float,unsigned char)       *
    //                              *********************************************************************************************************
    //                              void __thiscall modify_delta(TRIBE_Master_Building_Object * this, fl
    //              void              <VOID>         <RETURN>
    //              TRIBE_Master_B    ECX:4 (auto)   this
    //              float             Stack[0x4]:4   param_1                   XREF[2]:     0050e50c(R), 0050e51a(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[1]:     0050e500(R)  
    //                               ?modify_delta@TRIBE_Master_Building_Object@@UAEXME@Z         XREF[1]:     0057670c(*)  
    //                               TRIBE_Master_Building_Object::modify_delta
    //                              tm_b_obj.cpp:169 (11)
    //         0050e500     MOV        EAX,dword ptr [ESP + param_2]
    //         0050e504     PUSH       ESI
    //         0050e505     CMP        AL,0x11
    //         0050e507     MOV        ESI,this
    //         0050e509     JZ         LAB_0050e51a
    //                              tm_b_obj.cpp:176 (11)
    //         0050e50b     PUSH       EAX
    //         0050e50c     MOV        EAX,dword ptr [ESP + param_1]
    //         0050e510     PUSH       EAX
    //         0050e511     CALL       TRIBE_Master_Combat_Object::modify_delta         void modify_delta(TRIBE_Master_Combat_Object 
    //                              tm_b_obj.cpp:179 (4)
    //         0050e516     POP        ESI
    //         0050e517     RET        0x8
    //                               LAB_0050e51a                                                 XREF[1]:     0050e509(j)  
    //                              tm_b_obj.cpp:173 (16)
    //         0050e51a     FLD        float ptr [ESP + param_1]
    //         0050e51e     CALL       __ftol                                           undefined __ftol()
    //         0050e523     ADD        word ptr [ESI + 0x16e],AX
    //                              tm_b_obj.cpp:179 (4)
    //         0050e52a     POP        ESI
    //         0050e52b     RET        0x8
}

// Offset: 0x0050E530
void TRIBE_Master_Building_Object::modify_percent(float param_1, uchar param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall TRIBE_Master_Building_Object::modify_percent(float,unsigned char)     *
    //                              *********************************************************************************************************
    //                              void __thiscall modify_percent(TRIBE_Master_Building_Object * this, 
    //              void              <VOID>         <RETURN>
    //              TRIBE_Master_B    ECX:4 (auto)   this
    //              float             Stack[0x4]:4   param_1                   XREF[1]:     0050e534(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[1]:     0050e530(R)  
    //                               ?modify_percent@TRIBE_Master_Building_Object@@UAEXME@Z       XREF[1]:     00576710(*)  
    //                               TRIBE_Master_Building_Object::modify_percent
    //                              tm_b_obj.cpp:183 (15)
    //         0050e530     MOV        EAX,dword ptr [ESP + param_2]
    //         0050e534     MOV        EDX,dword ptr [ESP + param_1]
    //         0050e538     PUSH       EAX
    //         0050e539     PUSH       EDX
    //         0050e53a     CALL       TRIBE_Master_Combat_Object::modify_percent       void modify_percent(TRIBE_Master_Combat_Objec
    //                              tm_b_obj.cpp:185 (3)
    //         0050e53f     RET        0x8
}

// Offset: 0x0050E550
void TRIBE_Master_Building_Object::save(int param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall TRIBE_Master_Building_Object::save(int)                               *
    //                              *********************************************************************************************************
    //                              void __thiscall save(TRIBE_Master_Building_Object * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Master_B    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[4]:     0050e553(R), 0050e570(W), 0050e576(W), 0050e588(*)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0050e590(W), 0050e61a(*)  
    //              short             Stack[-0x8]:2  sound_num
    //                               ?save@TRIBE_Master_Building_Object@@UAEXH@Z                  XREF[1]:     00576714(*)  
    //                               TRIBE_Master_Building_Object::save
    //                              tm_b_obj.cpp:189 (3)
    //         0050e550     PUSH       this
    //         0050e551     PUSH       ESI
    //         0050e552     PUSH       EDI
    //                              tm_b_obj.cpp:193 (12)
    //         0050e553     MOV        EDI,dword ptr [ESP + param_1]
    //         0050e557     MOV        ESI,this
    //         0050e559     PUSH       EDI
    //         0050e55a     CALL       TRIBE_Master_Combat_Object::save                 void save(TRIBE_Master_Combat_Object * this, 
    //                              tm_b_obj.cpp:195 (27)
    //         0050e55f     MOV        EAX,dword ptr [ESI + 0x168]
    //         0050e565     OR         this,0xffffffff
    //         0050e568     TEST       EAX,EAX
    //         0050e56a     JZ         LAB_0050e576
    //         0050e56c     MOV        AX,word ptr [EAX + 0x72]
    //         0050e570     MOV        dword ptr [ESP + param_1],EAX
    //         0050e574     JMP        LAB_0050e57a
    //                               LAB_0050e576                                                 XREF[1]:     0050e56a(j)  
    //         0050e576     MOV        dword ptr [ESP + param_1],this
    //                               LAB_0050e57a                                                 XREF[1]:     0050e574(j)  
    //                              tm_b_obj.cpp:196 (14)
    //         0050e57a     MOV        EAX,dword ptr [ESI + 0x164]
    //         0050e580     TEST       EAX,EAX
    //         0050e582     JZ         LAB_0050e588
    //         0050e584     MOV        this,word ptr [EAX + 0xc]
    //                               LAB_0050e588                                                 XREF[1]:     0050e582(j)  
    //                              tm_b_obj.cpp:198 (20)
    //         0050e588     LEA        EDX=>param_1,[ESP + 0x10]
    //         0050e58c     PUSH       0x2
    //         0050e58e     PUSH       EDX
    //         0050e58f     PUSH       EDI
    //         0050e590     MOV        dword ptr [ESP + local_4],this
    //         0050e594     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050e599     ADD        ESP,0xc
    //                              tm_b_obj.cpp:199 (18)
    //         0050e59c     LEA        EAX,[ESI + 0x16c]
    //         0050e5a2     PUSH       0x1
    //         0050e5a4     PUSH       EAX
    //         0050e5a5     PUSH       EDI
    //         0050e5a6     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050e5ab     ADD        ESP,0xc
    //                              tm_b_obj.cpp:200 (18)
    //         0050e5ae     LEA        this,[ESI + 0x16e]
    //         0050e5b4     PUSH       0x2
    //         0050e5b6     PUSH       this
    //         0050e5b7     PUSH       EDI
    //         0050e5b8     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050e5bd     ADD        ESP,0xc
    //                              tm_b_obj.cpp:201 (18)
    //         0050e5c0     LEA        EDX,[ESI + 0x170]
    //         0050e5c6     PUSH       0x1
    //         0050e5c8     PUSH       EDX
    //         0050e5c9     PUSH       EDI
    //         0050e5ca     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050e5cf     ADD        ESP,0xc
    //                              tm_b_obj.cpp:202 (18)
    //         0050e5d2     LEA        EAX,[ESI + 0x172]
    //         0050e5d8     PUSH       0x2
    //         0050e5da     PUSH       EAX
    //         0050e5db     PUSH       EDI
    //         0050e5dc     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050e5e1     ADD        ESP,0xc
    //                              tm_b_obj.cpp:203 (18)
    //         0050e5e4     LEA        this,[ESI + 0x174]
    //         0050e5ea     PUSH       0x2
    //         0050e5ec     PUSH       this
    //         0050e5ed     PUSH       EDI
    //         0050e5ee     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050e5f3     ADD        ESP,0xc
    //                              tm_b_obj.cpp:204 (18)
    //         0050e5f6     LEA        EDX,[ESI + 0x176]
    //         0050e5fc     PUSH       0x2
    //         0050e5fe     PUSH       EDX
    //         0050e5ff     PUSH       EDI
    //         0050e600     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050e605     ADD        ESP,0xc
    //                              tm_b_obj.cpp:205 (18)
    //         0050e608     ADD        ESI,0x178
    //         0050e60e     PUSH       0x2
    //         0050e610     PUSH       ESI
    //         0050e611     PUSH       EDI
    //         0050e612     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050e617     ADD        ESP,0xc
    //                              tm_b_obj.cpp:206 (16)
    //         0050e61a     LEA        EAX=>local_4,[ESP + 0x8]
    //         0050e61e     PUSH       0x2
    //         0050e620     PUSH       EAX
    //         0050e621     PUSH       EDI
    //         0050e622     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0050e627     ADD        ESP,0xc
    //                              tm_b_obj.cpp:207 (6)
    //         0050e62a     POP        EDI
    //         0050e62b     POP        ESI
    //         0050e62c     POP        this
    //         0050e62d     RET        0x4
}

// Offset: 0x0050E630
RGE_Static_Object* TRIBE_Master_Building_Object::make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4, int param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual class RGE_Static_Object * __thiscall TRIBE_Master_Building_Object::make_new_obj(cl... *
    //                              *********************************************************************************************************
    //                              RGE_Static_Object * __thiscall make_new_obj(TRIBE_Master_Building_Ob
    //              RGE_Static_Obj    EAX:4          <RETURN>
    //              TRIBE_Master_B    ECX:4 (auto)   this
    //              RGE_Player *      Stack[0x4]:4   param_1                   XREF[1]:     0050e67b(R)  
    //              float             Stack[0x8]:4   param_2                   XREF[1]:     0050e676(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[1]:     0050e671(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[1]:     0050e66a(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[1]:     0050e666(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0050e65c(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     0050e689(R), 0050e69b(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0050e656(W)  
    //                               ?make_new_obj@TRIBE_Master_Building_Object@@UAEPAVRGE_Stati  XREF[1]:     0057673c(*)  
    //                               TRIBE_Master_Building_Object::make_new_obj
    //                              tm_b_obj.cpp:211 (25)
    //         0050e630     PUSH       -0x1
    //         0050e632     PUSH       FUN_00560e8b
    //         0050e637     MOV        EAX,FS:[0x0]
    //         0050e63d     PUSH       EAX
    //         0050e63e     MOV        dword ptr FS:[0x0],ESP
    //         0050e645     PUSH       this
    //         0050e646     PUSH       ESI
    //         0050e647     MOV        ESI,this
    //                              tm_b_obj.cpp:212 (64)
    //         0050e649     PUSH       0x204
    //         0050e64e     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0050e653     ADD        ESP,0x4
    //         0050e656     MOV        dword ptr [ESP + local_10],EAX
    //         0050e65a     TEST       EAX,EAX
    //         0050e65c     MOV        dword ptr [ESP + local_4],0x0
    //         0050e664     JZ         LAB_0050e69b
    //         0050e666     MOV        this,dword ptr [ESP + param_5]
    //         0050e66a     MOV        EDX,dword ptr [ESP + param_4]
    //         0050e66e     PUSH       0x1
    //         0050e670     PUSH       this
    //         0050e671     MOV        this,dword ptr [ESP + param_3]
    //         0050e675     PUSH       EDX
    //         0050e676     MOV        EDX,dword ptr [ESP + param_2]
    //         0050e67a     PUSH       this
    //         0050e67b     MOV        this,dword ptr [ESP + param_1]
    //         0050e67f     PUSH       EDX
    //         0050e680     PUSH       this
    //         0050e681     PUSH       ESI
    //         0050e682     MOV        this,EAX
    //         0050e684     CALL       TRIBE_Building_Object::TRIBE_Building_Object     undefined TRIBE_Building_Object(TRIBE_Buildin
    //                              tm_b_obj.cpp:213 (38)
    //         0050e689     MOV        this,dword ptr [ESP + local_c]
    //         0050e68d     MOV        dword ptr FS:[0x0],this
    //         0050e694     POP        ESI
    //         0050e695     ADD        ESP,0x10
    //         0050e698     RET        0x14
    //                               LAB_0050e69b                                                 XREF[1]:     0050e664(j)  
    //         0050e69b     MOV        this,dword ptr [ESP + local_c]
    //         0050e69f     XOR        EAX,EAX
    //         0050e6a1     MOV        dword ptr FS:[0x0],this
    //         0050e6a8     POP        ESI
    //         0050e6a9     ADD        ESP,0x10
    //         0050e6ac     RET        0x14
}

// Offset: 0x0050E6B0
RGE_Static_Object* TRIBE_Master_Building_Object::make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual class RGE_Static_Object * __thiscall TRIBE_Master_Building_Object::make_new_obj(cl... *
    //                              *********************************************************************************************************
    //                              RGE_Static_Object * __thiscall make_new_obj(TRIBE_Master_Building_Ob
    //              RGE_Static_Obj    EAX:4          <RETURN>
    //              TRIBE_Master_B    ECX:4 (auto)   this
    //              RGE_Player *      Stack[0x4]:4   param_1                   XREF[1]:     0050e6f6(R)  
    //              float             Stack[0x8]:4   param_2                   XREF[1]:     0050e6f1(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[1]:     0050e6ea(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[1]:     0050e6e6(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0050e6dc(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     0050e704(R), 0050e716(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0050e6d6(W)  
    //                               ?make_new_obj@TRIBE_Master_Building_Object@@UAEPAVRGE_Stati  XREF[1]:     00576718(*)  
    //                               TRIBE_Master_Building_Object::make_new_obj
    //                              tm_b_obj.cpp:217 (25)
    //         0050e6b0     PUSH       -0x1
    //         0050e6b2     PUSH       FUN_00560eab
    //         0050e6b7     MOV        EAX,FS:[0x0]
    //         0050e6bd     PUSH       EAX
    //         0050e6be     MOV        dword ptr FS:[0x0],ESP
    //         0050e6c5     PUSH       this
    //         0050e6c6     PUSH       ESI
    //         0050e6c7     MOV        ESI,this
    //                              tm_b_obj.cpp:218 (59)
    //         0050e6c9     PUSH       0x204
    //         0050e6ce     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0050e6d3     ADD        ESP,0x4
    //         0050e6d6     MOV        dword ptr [ESP + local_10],EAX
    //         0050e6da     TEST       EAX,EAX
    //         0050e6dc     MOV        dword ptr [ESP + local_4],0x0
    //         0050e6e4     JZ         LAB_0050e716
    //         0050e6e6     MOV        this,dword ptr [ESP + param_4]
    //         0050e6ea     MOV        EDX,dword ptr [ESP + param_3]
    //         0050e6ee     PUSH       0x1
    //         0050e6f0     PUSH       this
    //         0050e6f1     MOV        this,dword ptr [ESP + param_2]
    //         0050e6f5     PUSH       EDX
    //         0050e6f6     MOV        EDX,dword ptr [ESP + param_1]
    //         0050e6fa     PUSH       this
    //         0050e6fb     PUSH       EDX
    //         0050e6fc     PUSH       ESI
    //         0050e6fd     MOV        this,EAX
    //         0050e6ff     CALL       TRIBE_Building_Object::TRIBE_Building_Object     undefined TRIBE_Building_Object(TRIBE_Buildin
    //                              tm_b_obj.cpp:219 (38)
    //         0050e704     MOV        this,dword ptr [ESP + local_c]
    //         0050e708     MOV        dword ptr FS:[0x0],this
    //         0050e70f     POP        ESI
    //         0050e710     ADD        ESP,0x10
    //         0050e713     RET        0x10
    //                               LAB_0050e716                                                 XREF[1]:     0050e6e4(j)  
    //         0050e716     MOV        this,dword ptr [ESP + local_c]
    //         0050e71a     XOR        EAX,EAX
    //         0050e71c     MOV        dword ptr FS:[0x0],this
    //         0050e723     POP        ESI
    //         0050e724     ADD        ESP,0x10
    //         0050e727     RET        0x10
}

// Offset: 0x0050E730
RGE_Master_Static_Object* TRIBE_Master_Building_Object::make_new_master() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual class RGE_Master_Static_Object * __thiscall TRIBE_Master_Building_Object::make_new... *
    //                              *********************************************************************************************************
    //                              RGE_Master_Static_Object * __thiscall make_new_master(TRIBE_Master_B
    //              RGE_Master_Sta    EAX:4          <RETURN>
    //              TRIBE_Master_B    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0050e75c(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     0050e770(R), 0050e780(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0050e756(W)  
    //                               ?make_new_master@TRIBE_Master_Building_Object@@UAEPAVRGE_Ma  XREF[1]:     0057671c(*)  
    //                               TRIBE_Master_Building_Object::make_new_master
    //                              tm_b_obj.cpp:223 (25)
    //         0050e730     PUSH       -0x1
    //         0050e732     PUSH       FUN_00560ecb
    //         0050e737     MOV        EAX,FS:[0x0]
    //         0050e73d     PUSH       EAX
    //         0050e73e     MOV        dword ptr FS:[0x0],ESP
    //         0050e745     PUSH       this
    //         0050e746     PUSH       ESI
    //         0050e747     MOV        ESI,this
    //                              tm_b_obj.cpp:224 (39)
    //         0050e749     PUSH       0x17c
    //         0050e74e     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0050e753     ADD        ESP,0x4
    //         0050e756     MOV        dword ptr [ESP + local_10],EAX
    //         0050e75a     TEST       EAX,EAX
    //         0050e75c     MOV        dword ptr [ESP + local_4],0x0
    //         0050e764     JZ         LAB_0050e780
    //         0050e766     PUSH       0x1
    //         0050e768     PUSH       ESI
    //         0050e769     MOV        this,EAX
    //         0050e76b     CALL       TRIBE_Master_Building_Object::TRIBE_Master_Bui   undefined TRIBE_Master_Building_Object(TRIBE_
    //                              tm_b_obj.cpp:225 (34)
    //         0050e770     MOV        this,dword ptr [ESP + local_c]
    //         0050e774     MOV        dword ptr FS:[0x0],this
    //         0050e77b     POP        ESI
    //         0050e77c     ADD        ESP,0x10
    //         0050e77f     RET
    //                               LAB_0050e780                                                 XREF[1]:     0050e764(j)  
    //         0050e780     MOV        this,dword ptr [ESP + local_c]
    //         0050e784     XOR        EAX,EAX
    //         0050e786     MOV        dword ptr FS:[0x0],this
    //         0050e78d     POP        ESI
    //         0050e78e     ADD        ESP,0x10
    //         0050e791     RET
}

// Offset: 0x0050E7A0
void TRIBE_Master_Building_Object::draw(TDrawArea* param_1, short param_2, short param_3, RGE_Color_Table* param_4, long param_5, long param_6, int param_7, uchar param_8) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall TRIBE_Master_Building_Object::draw(class TDrawArea *,short,short,c... *
    //                              *********************************************************************************************************
    //                              void __thiscall draw(TRIBE_Master_Building_Object * this, TDrawArea 
    //              void              <VOID>         <RETURN>
    //              TRIBE_Master_B    ECX:4 (auto)   this
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[5]:     0050e7da(R), 0050e7ee(R), 0050e806(R), 0050e8b7(*), 
    //                                                                                     0050e906(R)  
    //              short             Stack[0x8]:2   param_2                   XREF[4]:     0050e7ca(R), 0050e80a(R), 0050e8db(*), 0050e8fe(R)  
    //              short             Stack[0xc]:2   param_3                   XREF[4]:     0050e7c6(R), 0050e802(R), 0050e8d6(*), 0050e8f2(R)  
    //              RGE_Color_Tabl    Stack[0x10]:4  param_4                   XREF[5]:     0050e7df(R), 0050e7f4(R), 0050e814(R), 0050e8bc(*), 
    //                                                                                     0050e90d(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[3]:     0050e7c2(R), 0050e88e(*), 0050e912(R)  
    //              long              Stack[0x18]:4  param_6
    //              int               Stack[0x1c]:4  param_7                   XREF[3]:     0050e82f(R), 0050e893(*), 0050e91a(R)  
    //              uchar             Stack[0x20]:1  param_8                   XREF[1]:     0050e8ee(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[5]:     0050e7ae(W), 0050e841(R), 0050e86a(W), 0050e86e(R), 
    //                                                                                     0050e8c9(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[4]:     0050e85c(W), 0050e864(R), 0050e881(R), 0050e8a4(R)  
    //              float             Stack[-0xc]:4  ry1                       XREF[6]:     0050e852(W), 0050e885(R), 0050e8a0(R), 0050e8ab(W), 
    //                                                                                     0050e8af(R), 0050e8cd(R)  
    //              float             Stack[-0x10]:4 rx1                       XREF[2,2]:   0050e860(*), 0050e91f(R), 0050e874(*), 0050e924(R)  
    //              short             Stack[-0x12]:2 x1
    //              short             Stack[-0x14]:2 y1
    //                               ?draw@TRIBE_Master_Building_Object@@UAEXPAVTDrawArea@@FFPAV  XREF[1]:     00576734(*)  
    //                               TRIBE_Master_Building_Object::draw
    //                              tm_b_obj.cpp:228 (8)
    //         0050e7a0     SUB        ESP,0x10
    //         0050e7a3     MOV        EDX,this
    //         0050e7a5     PUSH       EBX
    //         0050e7a6     PUSH       EBP
    //         0050e7a7     PUSH       ESI
    //                              tm_b_obj.cpp:229 (16)
    //         0050e7a8     MOV        this,dword ptr [EDX + 0x18]
    //         0050e7ab     PUSH       EDI
    //         0050e7ac     TEST       this,this
    //         0050e7ae     MOV        dword ptr [ESP + local_4],EDX
    //         0050e7b2     JZ         LAB_0050e93a
    //                              tm_b_obj.cpp:232 (10)
    //         0050e7b8     MOV        AL,byte ptr [EDX + 0x16c]
    //         0050e7be     TEST       AL,AL
    //         0050e7c0     JZ         LAB_0050e802
    //                              tm_b_obj.cpp:236 (4)
    //         0050e7c2     MOV        EDX,dword ptr [ESP + param_5]
    //                              tm_b_obj.cpp:237 (38)
    //         0050e7c6     MOV        EDI,dword ptr [ESP + param_3]
    //         0050e7ca     MOV        EBX,dword ptr [ESP + param_2]
    //         0050e7ce     PUSH       0x0
    //         0050e7d0     TEST       EDX,EDX
    //         0050e7d2     MOVSX      ESI,DI
    //         0050e7d5     MOVSX      EAX,BX
    //         0050e7d8     JNZ        LAB_0050e7ee
    //         0050e7da     MOV        EDX,dword ptr [ESP + param_1]
    //         0050e7de     PUSH       EDX
    //         0050e7df     MOV        EDX,dword ptr [ESP + param_4]
    //         0050e7e3     PUSH       EDX
    //         0050e7e4     PUSH       ESI
    //         0050e7e5     PUSH       EAX
    //         0050e7e6     PUSH       ESI
    //         0050e7e7     PUSH       EAX
    //         0050e7e8     PUSH       0x0
    //         0050e7ea     PUSH       0x2
    //                              tm_b_obj.cpp:238 (2)
    //         0050e7ec     JMP        LAB_0050e82a
    //                               LAB_0050e7ee                                                 XREF[1]:     0050e7d8(j)  
    //                              tm_b_obj.cpp:239 (18)
    //         0050e7ee     MOV        EBP,dword ptr [ESP + param_1]
    //         0050e7f2     DEC        EDX
    //         0050e7f3     PUSH       EBP
    //         0050e7f4     MOV        EBP,dword ptr [ESP + param_4]
    //         0050e7f8     PUSH       EBP
    //         0050e7f9     PUSH       ESI
    //         0050e7fa     PUSH       EAX
    //         0050e7fb     PUSH       ESI
    //         0050e7fc     PUSH       EAX
    //         0050e7fd     PUSH       0x0
    //         0050e7ff     PUSH       EDX
    //                              tm_b_obj.cpp:241 (2)
    //         0050e800     JMP        LAB_0050e82a
    //                               LAB_0050e802                                                 XREF[1]:     0050e7c0(j)  
    //                              tm_b_obj.cpp:242 (45)
    //         0050e802     MOV        EDI,dword ptr [ESP + param_3]
    //         0050e806     MOV        EBP,dword ptr [ESP + param_1]
    //         0050e80a     MOV        EBX,dword ptr [ESP + param_2]
    //         0050e80e     PUSH       0x0
    //         0050e810     MOVSX      ESI,DI
    //         0050e813     PUSH       EBP
    //         0050e814     MOV        EBP,dword ptr [ESP + param_4]
    //         0050e818     MOVSX      EAX,BX
    //         0050e81b     PUSH       EBP
    //         0050e81c     PUSH       ESI
    //         0050e81d     PUSH       EAX
    //         0050e81e     PUSH       ESI
    //         0050e81f     PUSH       EAX
    //         0050e820     PUSH       0x0
    //         0050e822     MOVSX      EAX,word ptr [EDX + 0x16e]
    //         0050e829     PUSH       EAX
    //                               LAB_0050e82a                                                 XREF[2]:     0050e7ec(j), 0050e800(j)  
    //         0050e82a     CALL       RGE_Sprite::draw                                 uchar draw(RGE_Sprite * this, long param_1, l
    //                              tm_b_obj.cpp:245 (12)
    //         0050e82f     MOV        EAX,dword ptr [ESP + param_7]
    //         0050e833     TEST       EAX,EAX
    //         0050e835     JZ         LAB_0050e93a
    //                              tm_b_obj.cpp:247 (6)
    //         0050e83b     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //                              tm_b_obj.cpp:248 (4)
    //         0050e841     MOV        EAX,dword ptr [ESP + local_4]
    //                              tm_b_obj.cpp:253 (60)
    //         0050e845     PUSH       EDI
    //         0050e846     PUSH       EBX
    //         0050e847     MOV        EDX,dword ptr [this->_padding_ + 0x3f4]
    //         0050e84d     MOV        this,dword ptr [EAX + 0x30]
    //         0050e850     PUSH       0x0
    //         0050e852     MOV        dword ptr [ESP + ry1],this
    //         0050e856     MOV        EBP,dword ptr [EDX + 0x28]
    //         0050e859     MOV        EDX,dword ptr [EAX + 0x34]
    //         0050e85c     MOV        dword ptr [ESP + local_8],EDX
    //         0050e860     LEA        EDX=>rx1,[ESP + 0x1c]
    //         0050e864     FLD        float ptr [ESP + local_8]
    //         0050e868     FCHS
    //         0050e86a     FSTP       float ptr [ESP + local_4]
    //         0050e86e     MOV        EAX,dword ptr [ESP + local_4]
    //         0050e872     PUSH       EAX
    //         0050e873     PUSH       this
    //         0050e874     LEA        EAX=>rx1+0x2,[ESP + 0x26]
    //         0050e878     PUSH       EDX
    //         0050e879     PUSH       EAX
    //         0050e87a     MOV        this,EBP
    //         0050e87c     CALL       RGE_Map::get_point                               void get_point(RGE_Map * this, short * param_
    //                              tm_b_obj.cpp:254 (31)
    //         0050e881     MOV        this,dword ptr [ESP + local_8]
    //         0050e885     MOV        EDX,dword ptr [ESP + ry1]
    //         0050e889     PUSH       EDI
    //         0050e88a     PUSH       EBX
    //         0050e88b     PUSH       0x0
    //         0050e88d     PUSH       this
    //         0050e88e     LEA        EAX=>param_5,[ESP + 0x44]
    //         0050e892     PUSH       EDX
    //         0050e893     LEA        this=>param_7,[ESP + 0x50]
    //         0050e897     PUSH       EAX
    //         0050e898     PUSH       this
    //         0050e899     MOV        this,EBP
    //         0050e89b     CALL       RGE_Map::get_point                               void get_point(RGE_Map * this, short * param_
    //                              tm_b_obj.cpp:255 (41)
    //         0050e8a0     FLD        float ptr [ESP + ry1]
    //         0050e8a4     MOV        EDX,dword ptr [ESP + local_8]
    //         0050e8a8     PUSH       EDI
    //         0050e8a9     FCHS
    //         0050e8ab     FSTP       float ptr [ESP + ry1]
    //         0050e8af     MOV        EAX,dword ptr [ESP + ry1]
    //         0050e8b3     PUSH       EBX
    //         0050e8b4     PUSH       0x0
    //         0050e8b6     PUSH       EDX
    //         0050e8b7     LEA        this=>param_1,[ESP + 0x34]
    //         0050e8bb     PUSH       EAX
    //         0050e8bc     LEA        EDX=>param_4,[ESP + 0x44]
    //         0050e8c0     PUSH       this
    //         0050e8c1     PUSH       EDX
    //         0050e8c2     MOV        this,EBP
    //         0050e8c4     CALL       RGE_Map::get_point                               void get_point(RGE_Map * this, short * param_
    //                              tm_b_obj.cpp:256 (31)
    //         0050e8c9     MOV        EAX,dword ptr [ESP + local_4]
    //         0050e8cd     MOV        this,dword ptr [ESP + ry1]
    //         0050e8d1     PUSH       EDI
    //         0050e8d2     PUSH       EBX
    //         0050e8d3     PUSH       0x0
    //         0050e8d5     PUSH       EAX
    //         0050e8d6     LEA        EDX=>param_3,[ESP + 0x3c]
    //         0050e8da     PUSH       this
    //         0050e8db     LEA        EAX=>param_2,[ESP + 0x3c]
    //         0050e8df     PUSH       EDX
    //         0050e8e0     PUSH       EAX
    //         0050e8e1     MOV        this,EBP
    //         0050e8e3     CALL       RGE_Map::get_point                               void get_point(RGE_Map * this, short * param_
    //                              tm_b_obj.cpp:257 (82)
    //         0050e8e8     MOV        this,dword ptr [SDI_Object_ID]
    //         0050e8ee     MOV        EDX,dword ptr [ESP + param_8]
    //         0050e8f2     MOVSX      EAX,word ptr [ESP + param_3]
    //         0050e8f7     PUSH       this
    //         0050e8f8     AND        EDX,0xff
    //         0050e8fe     MOVSX      this,word ptr [ESP + param_2]
    //         0050e903     PUSH       EDX
    //         0050e904     PUSH       0xa
    //         0050e906     MOVSX      EDX,word ptr [ESP + param_1]
    //         0050e90b     PUSH       EAX
    //         0050e90c     PUSH       this
    //         0050e90d     MOVSX      EAX,word ptr [ESP + param_4]
    //         0050e912     MOVSX      this,word ptr [ESP + param_5]
    //         0050e917     PUSH       EDX
    //         0050e918     PUSH       EAX
    //         0050e919     PUSH       this
    //         0050e91a     MOVSX      EDX,word ptr [ESP + param_7]
    //         0050e91f     MOVSX      EAX,word ptr [ESP + rx1]
    //         0050e924     MOVSX      this,word ptr [ESP + rx1+0x2]
    //         0050e929     PUSH       EDX
    //         0050e92a     PUSH       EAX
    //         0050e92b     PUSH       this
    //         0050e92c     MOV        this,dword ptr [SDI_List]                        = 00000000
    //         0050e932     PUSH       ESI
    //         0050e933     PUSH       0x1
    //         0050e935     CALL       DClipInfo_List::AddGDINode                       DClipInfo_Node * AddGDINode(DClipInfo_List * 
    //                               LAB_0050e93a                                                 XREF[2]:     0050e7b2(j), 0050e835(j)  
    //                              tm_b_obj.cpp:260 (10)
    //         0050e93a     POP        EDI
    //         0050e93b     POP        ESI
    //         0050e93c     POP        EBP
    //         0050e93d     POP        EBX
    //         0050e93e     ADD        ESP,0x10
    //         0050e941     RET        0x20
}

// Offset: 0x0050E950
uchar TRIBE_Master_Building_Object::alignment(float* param_1, float* param_2, RGE_Game_World* param_3, uchar param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual unsigned char __thiscall TRIBE_Master_Building_Object::alignment(float &,float &,c... *
    //                              *********************************************************************************************************
    //                              uchar __thiscall alignment(TRIBE_Master_Building_Object * this, floa
    //              uchar             AL:1           <RETURN>
    //              TRIBE_Master_B    ECX:4 (auto)   this
    //              float *           Stack[0x4]:4   param_1                   XREF[1]:     0050e95b(R)  
    //              float *           Stack[0x8]:4   param_2                   XREF[1]:     0050e954(R)  
    //              RGE_Game_World    Stack[0xc]:4   param_3                   XREF[1]:     0050e950(R)  
    //              uchar             Stack[0x10]:1  param_4
    //                               ?alignment@TRIBE_Master_Building_Object@@UAEEAAM0PAVRGE_Gam  XREF[1]:     00576724(*)  
    //                               TRIBE_Master_Building_Object::alignment
    //                              tm_b_obj.cpp:264 (22)
    //         0050e950     MOV        EAX,dword ptr [ESP + param_3]
    //         0050e954     MOV        EDX,dword ptr [ESP + param_2]
    //         0050e958     PUSH       0x1
    //         0050e95a     PUSH       EAX
    //         0050e95b     MOV        EAX,dword ptr [ESP + param_1]
    //         0050e95f     PUSH       EDX
    //         0050e960     PUSH       EAX
    //         0050e961     CALL       RGE_Master_Static_Object::alignment              uchar alignment(RGE_Master_Static_Object * th
    //                              tm_b_obj.cpp:266 (3)
    //         0050e966     RET        0x10
}

