// Auto-generated scaffold unit: tm_tre_o.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/tm_tre_o.cpp
#include "../include/common.h"

// Offset: 0x0050F180
undefined TRIBE_Master_Tree_Object(TRIBE_Master_Tree_Object* this_, TRIBE_Master_Tree_Object* param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object(class TRIBE_Master_Tree_Obje... *
    //                              *********************************************************************************************************
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
}

// Offset: 0x0050F220
undefined TRIBE_Master_Tree_Object(TRIBE_Master_Tree_Object* this_, int param_2, RGE_Sprite** param_3, RGE_Sound** param_4, int param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object(int,class RGE_Sprite * *,cla... *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TRIBE_Master_Tree_Object(TRIBE_Master_Tree_Obje
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TRIBE_Master_T    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0050f23c(R)  
    //              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     0050f237(R)  
    //              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[1]:     0050f242(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     0050f256(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0050f25a(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0050f27a(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0050f24d(W)  
    //                               ??0TRIBE_Master_Tree_Object@@QAE@HPAPAVRGE_Sprite@@PAPAVRGE  XREF[2]:     load_master_object:005118be(c), 
    //                               TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object                        load_master_object:00512b1e(c)  
    //                              tm_tre_o.cpp:32 (54)
    //         0050f220     PUSH       -0x1
    //         0050f222     PUSH       FUN_00560fc8
    //         0050f227     MOV        EAX,FS:[0x0]
    //         0050f22d     PUSH       EAX
    //         0050f22e     MOV        dword ptr FS:[0x0],ESP
    //         0050f235     PUSH       this
    //         0050f236     PUSH       EBX
    //         0050f237     MOV        EBX,dword ptr [ESP + param_2]
    //         0050f23b     PUSH       EBP
    //         0050f23c     MOV        EBP,dword ptr [ESP + param_1]
    //         0050f240     PUSH       ESI
    //         0050f241     PUSH       EDI
    //         0050f242     MOV        EDI,dword ptr [ESP + param_3]
    //         0050f246     PUSH       0x0
    //         0050f248     PUSH       EDI
    //         0050f249     MOV        ESI,this
    //         0050f24b     PUSH       EBX
    //         0050f24c     PUSH       EBP
    //         0050f24d     MOV        dword ptr [ESP + local_10],ESI
    //         0050f251     CALL       RGE_Master_Static_Object::RGE_Master_Static_Ob   undefined RGE_Master_Static_Object(RGE_Master
    //                              tm_tre_o.cpp:33 (22)
    //         0050f256     MOV        EAX,dword ptr [ESP + param_4]
    //         0050f25a     MOV        dword ptr [ESP + local_4],0x0
    //         0050f262     TEST       EAX,EAX
    //         0050f264     MOV        dword ptr [ESI],TRIBE_Master_Tree_Object::`vft   = 0050f1f0
    //         0050f26a     JZ         LAB_0050f27a
    //                              tm_tre_o.cpp:35 (10)
    //         0050f26c     PUSH       EDI
    //         0050f26d     PUSH       EBX
    //         0050f26e     PUSH       EBP
    //         0050f26f     MOV        this,ESI
    //         0050f271     CALL       RGE_Master_Static_Object::setup                  int setup(RGE_Master_Static_Object * this, in
    //                              tm_tre_o.cpp:36 (4)
    //         0050f276     MOV        byte ptr [ESI + 0x4],0x5a
    //                               LAB_0050f27a                                                 XREF[1]:     0050f26a(j)  
    //                              tm_tre_o.cpp:38 (23)
    //         0050f27a     MOV        this,dword ptr [ESP + local_c]
    //         0050f27e     MOV        EAX,ESI
    //         0050f280     POP        EDI
    //         0050f281     POP        ESI
    //         0050f282     POP        EBP
    //         0050f283     MOV        dword ptr FS:[0x0],this
    //         0050f28a     POP        EBX
    //         0050f28b     ADD        ESP,0x10
    //         0050f28e     RET        0x10
}

// Offset: 0x0050F2A0
undefined TRIBE_Master_Tree_Object(TRIBE_Master_Tree_Object* this_, FILE* param_2, RGE_Sprite** param_3, RGE_Sound** param_4, short param_5, int param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object(struct _iobuf *,class RGE_Sp... *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TRIBE_Master_Tree_Object(TRIBE_Master_Tree_Obje
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TRIBE_Master_T    ECX:4 (auto)   this
    //              _iobuf *          Stack[0x4]:4   param_1                   XREF[2]:     0050f2b6(R), 0050f2f1(R)  
    //              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     0050f2c0(R)  
    //              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[1]:     0050f2bb(R)  
    //              short             Stack[0x10]:2  param_4                   XREF[1]:     0050f2c6(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[1]:     0050f2db(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0050f2df(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0050f304(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0050f2d2(W)  
    //                               ??0TRIBE_Master_Tree_Object@@QAE@PAU_iobuf@@PAPAVRGE_Sprite  XREF[1]:     load_object:00511a25(c)  
    //                               TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object
    //                              tm_tre_o.cpp:43 (59)
    //         0050f2a0     PUSH       -0x1
    //         0050f2a2     PUSH       FUN_00560fe8
    //         0050f2a7     MOV        EAX,FS:[0x0]
    //         0050f2ad     PUSH       EAX
    //         0050f2ae     MOV        dword ptr FS:[0x0],ESP
    //         0050f2b5     PUSH       this
    //         0050f2b6     MOV        EAX,dword ptr [ESP + param_1]
    //         0050f2ba     PUSH       EBX
    //         0050f2bb     MOV        EBX,dword ptr [ESP + param_3]
    //         0050f2bf     PUSH       EBP
    //         0050f2c0     MOV        EBP,dword ptr [ESP + param_2]
    //         0050f2c4     PUSH       ESI
    //         0050f2c5     PUSH       EDI
    //         0050f2c6     MOV        EDI,dword ptr [ESP + param_4]
    //         0050f2ca     PUSH       0x0
    //         0050f2cc     PUSH       EDI
    //         0050f2cd     PUSH       EBX
    //         0050f2ce     MOV        ESI,this
    //         0050f2d0     PUSH       EBP
    //         0050f2d1     PUSH       EAX
    //         0050f2d2     MOV        dword ptr [ESP + local_10],ESI
    //         0050f2d6     CALL       RGE_Master_Static_Object::RGE_Master_Static_Ob   undefined RGE_Master_Static_Object(RGE_Master
    //                              tm_tre_o.cpp:44 (22)
    //         0050f2db     MOV        EAX,dword ptr [ESP + param_5]
    //         0050f2df     MOV        dword ptr [ESP + local_4],0x0
    //         0050f2e7     TEST       EAX,EAX
    //         0050f2e9     MOV        dword ptr [ESI],TRIBE_Master_Tree_Object::`vft   = 0050f1f0
    //         0050f2ef     JZ         LAB_0050f304
    //                              tm_tre_o.cpp:46 (15)
    //         0050f2f1     MOV        this,dword ptr [ESP + param_1]
    //         0050f2f5     PUSH       EDI
    //         0050f2f6     PUSH       EBX
    //         0050f2f7     PUSH       EBP
    //         0050f2f8     PUSH       this
    //         0050f2f9     MOV        this,ESI
    //         0050f2fb     CALL       RGE_Master_Static_Object::setup                  int setup(RGE_Master_Static_Object * this, _i
    //                              tm_tre_o.cpp:47 (4)
    //         0050f300     MOV        byte ptr [ESI + 0x4],0x5a
    //                               LAB_0050f304                                                 XREF[1]:     0050f2ef(j)  
    //                              tm_tre_o.cpp:49 (23)
    //         0050f304     MOV        this,dword ptr [ESP + local_c]
    //         0050f308     MOV        EAX,ESI
    //         0050f30a     POP        EDI
    //         0050f30b     POP        ESI
    //         0050f30c     POP        EBP
    //         0050f30d     MOV        dword ptr FS:[0x0],this
    //         0050f314     POP        EBX
    //         0050f315     ADD        ESP,0x10
    //         0050f318     RET        0x14
}

// Offset: 0x0050F320
RGE_Static_Object* TRIBE_Master_Tree_Object::make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual class RGE_Static_Object * __thiscall TRIBE_Master_Tree_Object::make_new_obj(class ... *
    //                              *********************************************************************************************************
    //                              RGE_Static_Object * __thiscall make_new_obj(TRIBE_Master_Tree_Object
    //              RGE_Static_Obj    EAX:4          <RETURN>
    //              TRIBE_Master_T    ECX:4 (auto)   this
    //              RGE_Player *      Stack[0x4]:4   param_1                   XREF[1]:     0050f366(R)  
    //              float             Stack[0x8]:4   param_2                   XREF[1]:     0050f361(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[1]:     0050f35a(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[1]:     0050f356(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0050f34c(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     0050f374(R), 0050f386(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0050f346(W)  
    //                               ?make_new_obj@TRIBE_Master_Tree_Object@@UAEPAVRGE_Static_Ob  XREF[1]:     005767a8(*)  
    //                               TRIBE_Master_Tree_Object::make_new_obj
    //                              tm_tre_o.cpp:53 (25)
    //         0050f320     PUSH       -0x1
    //         0050f322     PUSH       FUN_0056100b
    //         0050f327     MOV        EAX,FS:[0x0]
    //         0050f32d     PUSH       EAX
    //         0050f32e     MOV        dword ptr FS:[0x0],ESP
    //         0050f335     PUSH       this
    //         0050f336     PUSH       ESI
    //         0050f337     MOV        ESI,this
    //                              tm_tre_o.cpp:54 (59)
    //         0050f339     PUSH       0x88
    //         0050f33e     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0050f343     ADD        ESP,0x4
    //         0050f346     MOV        dword ptr [ESP + local_10],EAX
    //         0050f34a     TEST       EAX,EAX
    //         0050f34c     MOV        dword ptr [ESP + local_4],0x0
    //         0050f354     JZ         LAB_0050f386
    //         0050f356     MOV        this,dword ptr [ESP + param_4]
    //         0050f35a     MOV        EDX,dword ptr [ESP + param_3]
    //         0050f35e     PUSH       0x1
    //         0050f360     PUSH       this
    //         0050f361     MOV        this,dword ptr [ESP + param_2]
    //         0050f365     PUSH       EDX
    //         0050f366     MOV        EDX,dword ptr [ESP + param_1]
    //         0050f36a     PUSH       this
    //         0050f36b     PUSH       EDX
    //         0050f36c     PUSH       ESI
    //         0050f36d     MOV        this,EAX
    //         0050f36f     CALL       TRIBE_Tree_Object::TRIBE_Tree_Object             undefined TRIBE_Tree_Object(TRIBE_Tree_Object
    //                              tm_tre_o.cpp:55 (38)
    //         0050f374     MOV        this,dword ptr [ESP + local_c]
    //         0050f378     MOV        dword ptr FS:[0x0],this
    //         0050f37f     POP        ESI
    //         0050f380     ADD        ESP,0x10
    //         0050f383     RET        0x10
    //                               LAB_0050f386                                                 XREF[1]:     0050f354(j)  
    //         0050f386     MOV        this,dword ptr [ESP + local_c]
    //         0050f38a     XOR        EAX,EAX
    //         0050f38c     MOV        dword ptr FS:[0x0],this
    //         0050f393     POP        ESI
    //         0050f394     ADD        ESP,0x10
    //         0050f397     RET        0x10
}

// Offset: 0x0050F3A0
RGE_Master_Static_Object* TRIBE_Master_Tree_Object::make_new_master() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual class RGE_Master_Static_Object * __thiscall TRIBE_Master_Tree_Object::make_new_mas... *
    //                              *********************************************************************************************************
    //                              RGE_Master_Static_Object * __thiscall make_new_master(TRIBE_Master_T
    //              RGE_Master_Sta    EAX:4          <RETURN>
    //              TRIBE_Master_T    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0050f3cc(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     0050f3e0(R), 0050f3f0(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0050f3c6(W)  
    //                               ?make_new_master@TRIBE_Master_Tree_Object@@UAEPAVRGE_Master  XREF[1]:     005767ac(*)  
    //                               TRIBE_Master_Tree_Object::make_new_master
    //                              tm_tre_o.cpp:59 (25)
    //         0050f3a0     PUSH       -0x1
    //         0050f3a2     PUSH       FUN_0056102b
    //         0050f3a7     MOV        EAX,FS:[0x0]
    //         0050f3ad     PUSH       EAX
    //         0050f3ae     MOV        dword ptr FS:[0x0],ESP
    //         0050f3b5     PUSH       this
    //         0050f3b6     PUSH       ESI
    //         0050f3b7     MOV        ESI,this
    //                              tm_tre_o.cpp:60 (39)
    //         0050f3b9     PUSH       0xb8
    //         0050f3be     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0050f3c3     ADD        ESP,0x4
    //         0050f3c6     MOV        dword ptr [ESP + local_10],EAX
    //         0050f3ca     TEST       EAX,EAX
    //         0050f3cc     MOV        dword ptr [ESP + local_4],0x0
    //         0050f3d4     JZ         LAB_0050f3f0
    //         0050f3d6     PUSH       0x1
    //         0050f3d8     PUSH       ESI
    //         0050f3d9     MOV        this,EAX
    //         0050f3db     CALL       TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Ob   undefined TRIBE_Master_Tree_Object(TRIBE_Mast
    //                              tm_tre_o.cpp:61 (34)
    //         0050f3e0     MOV        this,dword ptr [ESP + local_c]
    //         0050f3e4     MOV        dword ptr FS:[0x0],this
    //         0050f3eb     POP        ESI
    //         0050f3ec     ADD        ESP,0x10
    //         0050f3ef     RET
    //                               LAB_0050f3f0                                                 XREF[1]:     0050f3d4(j)  
    //         0050f3f0     MOV        this,dword ptr [ESP + local_c]
    //         0050f3f4     XOR        EAX,EAX
    //         0050f3f6     MOV        dword ptr FS:[0x0],this
    //         0050f3fd     POP        ESI
    //         0050f3fe     ADD        ESP,0x10
    //         0050f401     RET
}

