#include "../common.h"
#include "tm_tre_o.h"

TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object(TRIBE_Master_Tree_Object* param_1, int param_2) {
    /* TODO: Stub */
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
//         0050f31b     ??         90h
//         0050f31c     NOP
//         0050f31d     NOP
//         0050f31e     NOP
//         0050f31f     NOP
}

TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4) {
    /* TODO: Stub */
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
//         0050f31b     ??         90h
//         0050f31c     NOP
//         0050f31d     NOP
//         0050f31e     NOP
//         0050f31f     NOP
}

TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5) {
    /* TODO: Stub */
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
//         0050f31b     ??         90h
//         0050f31c     NOP
//         0050f31d     NOP
//         0050f31e     NOP
//         0050f31f     NOP
}

RGE_Static_Object* TRIBE_Master_Tree_Object::make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4) {
    /* TODO: Stub */
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
//         0050f39a     ??         90h
//         0050f39b     NOP
//         0050f39c     NOP
//         0050f39d     NOP
//         0050f39e     NOP
//         0050f39f     NOP
    return 0;
}

TRIBE_Master_Tree_Object::~TRIBE_Master_Tree_Object() {
    /* TODO: Stub */
//                              void __thiscall ~TRIBE_Master_Tree_Object(TRIBE_Master_Tree_Object *
//              void              <VOID>         <RETURN>
//              TRIBE_Master_T    ECX:4 (auto)   this
//                               ??1TRIBE_Master_Tree_Object@@UAE@XZ                          XREF[1]:     `scalar_deleting_destructor':0050f
//                               TRIBE_Master_Tree_Object::~TRIBE_Master_Tree_Object
//         0050f210     JMP        RGE_Master_Static_Object::~RGE_Master_Static_O
//         0050f215     ??         90h
//         0050f216     NOP
//         0050f217     NOP
//         0050f218     NOP
//         0050f219     NOP
//         0050f21a     NOP
//         0050f21b     NOP
//         0050f21c     NOP
//         0050f21d     NOP
//         0050f21e     NOP
//         0050f21f     NOP
}

RGE_Master_Static_Object* TRIBE_Master_Tree_Object::make_new_master() {
    /* TODO: Stub */
// <NO ASSEMBLY FOUND>
    return 0;
}

