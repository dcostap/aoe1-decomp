#include "../common.h"
#include "m_an_obj.h"

RGE_Master_Animated_Object::RGE_Master_Animated_Object(RGE_Master_Animated_Object* param_1, int param_2) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Master_Animated_Object(RGE_Master_Animated_
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Master_Ani    ECX:4 (auto)   this
//              _iobuf *          Stack[0x4]:4   param_1                   XREF[2]:     0044fac6(R), 0044fb01(R)
//              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     0044fad0(R)
//              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[1]:     0044facb(R)
//              short             Stack[0x10]:2  param_4                   XREF[1]:     0044fad6(R)
//              int               Stack[0x14]:4  param_5                   XREF[1]:     0044faeb(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0044faef(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0044fb10(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0044fae2(W)
//                               ??0RGE_Master_Animated_Object@@QAE@PAU_iobuf@@PAPAVRGE_Spri  XREF[3]:     RGE_Master_Doppleganger_Object:004
//                               RGE_Master_Animated_Object::RGE_Master_Animated_Object                    RGE_Master_Moving_Object:00451b46(
//                                                                                                         load_object:00461619(c)
//                              m_an_obj.cpp:42 (59)
//         0044fab0     PUSH       -0x1
//         0044fab2     PUSH       FUN_0055d758
//         0044fab7     MOV        EAX,FS:[0x0]
//         0044fabd     PUSH       EAX
//         0044fabe     MOV        dword ptr FS:[0x0],ESP
//         0044fac5     PUSH       this
//         0044fac6     MOV        EAX,dword ptr [ESP + param_1]
//         0044faca     PUSH       EBX
//         0044facb     MOV        EBX,dword ptr [ESP + param_3]
//         0044facf     PUSH       EBP
//         0044fad0     MOV        EBP,dword ptr [ESP + param_2]
//         0044fad4     PUSH       ESI
//         0044fad5     PUSH       EDI
//         0044fad6     MOV        EDI,dword ptr [ESP + param_4]
//         0044fada     PUSH       0x0
//         0044fadc     PUSH       EDI
//         0044fadd     PUSH       EBX
//         0044fade     MOV        ESI,this
//         0044fae0     PUSH       EBP
//         0044fae1     PUSH       EAX
//         0044fae2     MOV        dword ptr [ESP + local_10],ESI
//         0044fae6     CALL       RGE_Master_Static_Object::RGE_Master_Static_Ob   undefined RGE_Master_Static_Object(RGE_Master
//                              m_an_obj.cpp:43 (22)
//         0044faeb     MOV        EAX,dword ptr [ESP + param_5]
//         0044faef     MOV        dword ptr [ESP + local_4],0x0
//         0044faf7     TEST       EAX,EAX
//         0044faf9     MOV        dword ptr [ESI],RGE_Master_Animated_Object::`v   = 0044fa20
//         0044faff     JZ         LAB_0044fb10
//                              m_an_obj.cpp:44 (15)
//         0044fb01     MOV        this,dword ptr [ESP + param_1]
//         0044fb05     PUSH       EDI
//         0044fb06     PUSH       EBX
//         0044fb07     PUSH       EBP
//         0044fb08     PUSH       this
//         0044fb09     MOV        this,ESI
//         0044fb0b     CALL       RGE_Master_Animated_Object::setup                int setup(RGE_Master_Animated_Object * this,
//                               LAB_0044fb10                                                 XREF[1]:     0044faff(j)
//                              m_an_obj.cpp:45 (23)
//         0044fb10     MOV        this,dword ptr [ESP + local_c]
//         0044fb14     MOV        EAX,ESI
//         0044fb16     POP        EDI
//         0044fb17     POP        ESI
//         0044fb18     POP        EBP
//         0044fb19     MOV        dword ptr FS:[0x0],this
//         0044fb20     POP        EBX
//         0044fb21     ADD        ESP,0x10
//         0044fb24     RET        0x14
//         0044fb27     ??         90h
//         0044fb28     NOP
//         0044fb29     NOP
//         0044fb2a     NOP
//         0044fb2b     NOP
//         0044fb2c     NOP
//         0044fb2d     NOP
//         0044fb2e     NOP
//         0044fb2f     NOP
}

RGE_Master_Animated_Object::RGE_Master_Animated_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Master_Animated_Object(RGE_Master_Animated_
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Master_Ani    ECX:4 (auto)   this
//              _iobuf *          Stack[0x4]:4   param_1                   XREF[2]:     0044fac6(R), 0044fb01(R)
//              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     0044fad0(R)
//              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[1]:     0044facb(R)
//              short             Stack[0x10]:2  param_4                   XREF[1]:     0044fad6(R)
//              int               Stack[0x14]:4  param_5                   XREF[1]:     0044faeb(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0044faef(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0044fb10(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0044fae2(W)
//                               ??0RGE_Master_Animated_Object@@QAE@PAU_iobuf@@PAPAVRGE_Spri  XREF[3]:     RGE_Master_Doppleganger_Object:004
//                               RGE_Master_Animated_Object::RGE_Master_Animated_Object                    RGE_Master_Moving_Object:00451b46(
//                                                                                                         load_object:00461619(c)
//                              m_an_obj.cpp:42 (59)
//         0044fab0     PUSH       -0x1
//         0044fab2     PUSH       FUN_0055d758
//         0044fab7     MOV        EAX,FS:[0x0]
//         0044fabd     PUSH       EAX
//         0044fabe     MOV        dword ptr FS:[0x0],ESP
//         0044fac5     PUSH       this
//         0044fac6     MOV        EAX,dword ptr [ESP + param_1]
//         0044faca     PUSH       EBX
//         0044facb     MOV        EBX,dword ptr [ESP + param_3]
//         0044facf     PUSH       EBP
//         0044fad0     MOV        EBP,dword ptr [ESP + param_2]
//         0044fad4     PUSH       ESI
//         0044fad5     PUSH       EDI
//         0044fad6     MOV        EDI,dword ptr [ESP + param_4]
//         0044fada     PUSH       0x0
//         0044fadc     PUSH       EDI
//         0044fadd     PUSH       EBX
//         0044fade     MOV        ESI,this
//         0044fae0     PUSH       EBP
//         0044fae1     PUSH       EAX
//         0044fae2     MOV        dword ptr [ESP + local_10],ESI
//         0044fae6     CALL       RGE_Master_Static_Object::RGE_Master_Static_Ob   undefined RGE_Master_Static_Object(RGE_Master
//                              m_an_obj.cpp:43 (22)
//         0044faeb     MOV        EAX,dword ptr [ESP + param_5]
//         0044faef     MOV        dword ptr [ESP + local_4],0x0
//         0044faf7     TEST       EAX,EAX
//         0044faf9     MOV        dword ptr [ESI],RGE_Master_Animated_Object::`v   = 0044fa20
//         0044faff     JZ         LAB_0044fb10
//                              m_an_obj.cpp:44 (15)
//         0044fb01     MOV        this,dword ptr [ESP + param_1]
//         0044fb05     PUSH       EDI
//         0044fb06     PUSH       EBX
//         0044fb07     PUSH       EBP
//         0044fb08     PUSH       this
//         0044fb09     MOV        this,ESI
//         0044fb0b     CALL       RGE_Master_Animated_Object::setup                int setup(RGE_Master_Animated_Object * this,
//                               LAB_0044fb10                                                 XREF[1]:     0044faff(j)
//                              m_an_obj.cpp:45 (23)
//         0044fb10     MOV        this,dword ptr [ESP + local_c]
//         0044fb14     MOV        EAX,ESI
//         0044fb16     POP        EDI
//         0044fb17     POP        ESI
//         0044fb18     POP        EBP
//         0044fb19     MOV        dword ptr FS:[0x0],this
//         0044fb20     POP        EBX
//         0044fb21     ADD        ESP,0x10
//         0044fb24     RET        0x14
//         0044fb27     ??         90h
//         0044fb28     NOP
//         0044fb29     NOP
//         0044fb2a     NOP
//         0044fb2b     NOP
//         0044fb2c     NOP
//         0044fb2d     NOP
//         0044fb2e     NOP
//         0044fb2f     NOP
}

RGE_Master_Animated_Object::RGE_Master_Animated_Object(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Master_Animated_Object(RGE_Master_Animated_
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Master_Ani    ECX:4 (auto)   this
//              _iobuf *          Stack[0x4]:4   param_1                   XREF[2]:     0044fac6(R), 0044fb01(R)
//              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     0044fad0(R)
//              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[1]:     0044facb(R)
//              short             Stack[0x10]:2  param_4                   XREF[1]:     0044fad6(R)
//              int               Stack[0x14]:4  param_5                   XREF[1]:     0044faeb(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0044faef(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0044fb10(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0044fae2(W)
//                               ??0RGE_Master_Animated_Object@@QAE@PAU_iobuf@@PAPAVRGE_Spri  XREF[3]:     RGE_Master_Doppleganger_Object:004
//                               RGE_Master_Animated_Object::RGE_Master_Animated_Object                    RGE_Master_Moving_Object:00451b46(
//                                                                                                         load_object:00461619(c)
//                              m_an_obj.cpp:42 (59)
//         0044fab0     PUSH       -0x1
//         0044fab2     PUSH       FUN_0055d758
//         0044fab7     MOV        EAX,FS:[0x0]
//         0044fabd     PUSH       EAX
//         0044fabe     MOV        dword ptr FS:[0x0],ESP
//         0044fac5     PUSH       this
//         0044fac6     MOV        EAX,dword ptr [ESP + param_1]
//         0044faca     PUSH       EBX
//         0044facb     MOV        EBX,dword ptr [ESP + param_3]
//         0044facf     PUSH       EBP
//         0044fad0     MOV        EBP,dword ptr [ESP + param_2]
//         0044fad4     PUSH       ESI
//         0044fad5     PUSH       EDI
//         0044fad6     MOV        EDI,dword ptr [ESP + param_4]
//         0044fada     PUSH       0x0
//         0044fadc     PUSH       EDI
//         0044fadd     PUSH       EBX
//         0044fade     MOV        ESI,this
//         0044fae0     PUSH       EBP
//         0044fae1     PUSH       EAX
//         0044fae2     MOV        dword ptr [ESP + local_10],ESI
//         0044fae6     CALL       RGE_Master_Static_Object::RGE_Master_Static_Ob   undefined RGE_Master_Static_Object(RGE_Master
//                              m_an_obj.cpp:43 (22)
//         0044faeb     MOV        EAX,dword ptr [ESP + param_5]
//         0044faef     MOV        dword ptr [ESP + local_4],0x0
//         0044faf7     TEST       EAX,EAX
//         0044faf9     MOV        dword ptr [ESI],RGE_Master_Animated_Object::`v   = 0044fa20
//         0044faff     JZ         LAB_0044fb10
//                              m_an_obj.cpp:44 (15)
//         0044fb01     MOV        this,dword ptr [ESP + param_1]
//         0044fb05     PUSH       EDI
//         0044fb06     PUSH       EBX
//         0044fb07     PUSH       EBP
//         0044fb08     PUSH       this
//         0044fb09     MOV        this,ESI
//         0044fb0b     CALL       RGE_Master_Animated_Object::setup                int setup(RGE_Master_Animated_Object * this,
//                               LAB_0044fb10                                                 XREF[1]:     0044faff(j)
//                              m_an_obj.cpp:45 (23)
//         0044fb10     MOV        this,dword ptr [ESP + local_c]
//         0044fb14     MOV        EAX,ESI
//         0044fb16     POP        EDI
//         0044fb17     POP        ESI
//         0044fb18     POP        EBP
//         0044fb19     MOV        dword ptr FS:[0x0],this
//         0044fb20     POP        EBX
//         0044fb21     ADD        ESP,0x10
//         0044fb24     RET        0x14
//         0044fb27     ??         90h
//         0044fb28     NOP
//         0044fb29     NOP
//         0044fb2a     NOP
//         0044fb2b     NOP
//         0044fb2c     NOP
//         0044fb2d     NOP
//         0044fb2e     NOP
//         0044fb2f     NOP
}

int RGE_Master_Animated_Object::setup(RGE_Master_Animated_Object* param_1) {
    /* TODO: Stub */
//                              int __thiscall setup(RGE_Master_Animated_Object * this, _iobuf * par
//              int               EAX:4          <RETURN>
//              RGE_Master_Ani    ECX:4 (auto)   this
//              _iobuf *          Stack[0x4]:4   param_1                   XREF[1]:     0044fbb0(R)
//              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     0044fba4(R)
//              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[1]:     0044fbab(R)
//              short             Stack[0x10]:2  param_4                   XREF[1]:     0044fba0(R)
//                               ?setup@RGE_Master_Animated_Object@@IAEHPAU_iobuf@@PAPAVRGE_  XREF[3]:     RGE_Master_Animated_Object:0044fb0
//                               RGE_Master_Animated_Object::setup                                         setup:00451299(c),
//                                                                                                         setup:00451d2c(c)
//                              m_an_obj.cpp:79 (31)
//         0044fba0     MOV        EAX,dword ptr [ESP + param_4]
//         0044fba4     MOV        EDX,dword ptr [ESP + param_2]
//         0044fba8     PUSH       ESI
//         0044fba9     MOV        ESI,this
//         0044fbab     MOV        this,dword ptr [ESP + param_3]
//         0044fbaf     PUSH       EDI
//         0044fbb0     MOV        EDI,dword ptr [ESP + param_1]
//         0044fbb4     PUSH       EAX
//         0044fbb5     PUSH       this
//         0044fbb6     PUSH       EDX
//         0044fbb7     PUSH       EDI
//         0044fbb8     MOV        this,ESI
//         0044fbba     CALL       RGE_Master_Static_Object::setup                  int setup(RGE_Master_Static_Object * this, _i
//                              m_an_obj.cpp:82 (4)
//         0044fbbf     MOV        byte ptr [ESI + 0x4],0x14
//                              m_an_obj.cpp:85 (21)
//         0044fbc3     ADD        ESI,0xb8
//         0044fbc9     PUSH       ESI
//         0044fbca     PUSH       s_%f                                             = "%f"
//         0044fbcf     PUSH       EDI
//         0044fbd0     CALL       fscanf                                           undefined fscanf()
//         0044fbd5     ADD        ESP,0xc
//                              m_an_obj.cpp:88 (5)
//         0044fbd8     MOV        EAX,0x1
//                              m_an_obj.cpp:89 (5)
//         0044fbdd     POP        EDI
//         0044fbde     POP        ESI
//         0044fbdf     RET        0x10
//         0044fbe2     ??         90h
//         0044fbe3     NOP
//         0044fbe4     NOP
//         0044fbe5     NOP
//         0044fbe6     NOP
//         0044fbe7     NOP
//         0044fbe8     NOP
//         0044fbe9     NOP
//         0044fbea     NOP
//         0044fbeb     NOP
//         0044fbec     NOP
//         0044fbed     NOP
//         0044fbee     NOP
//         0044fbef     NOP
    return 0;
}

int RGE_Master_Animated_Object::setup(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3) {
    /* TODO: Stub */
//                              int __thiscall setup(RGE_Master_Animated_Object * this, _iobuf * par
//              int               EAX:4          <RETURN>
//              RGE_Master_Ani    ECX:4 (auto)   this
//              _iobuf *          Stack[0x4]:4   param_1                   XREF[1]:     0044fbb0(R)
//              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     0044fba4(R)
//              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[1]:     0044fbab(R)
//              short             Stack[0x10]:2  param_4                   XREF[1]:     0044fba0(R)
//                               ?setup@RGE_Master_Animated_Object@@IAEHPAU_iobuf@@PAPAVRGE_  XREF[3]:     RGE_Master_Animated_Object:0044fb0
//                               RGE_Master_Animated_Object::setup                                         setup:00451299(c),
//                                                                                                         setup:00451d2c(c)
//                              m_an_obj.cpp:79 (31)
//         0044fba0     MOV        EAX,dword ptr [ESP + param_4]
//         0044fba4     MOV        EDX,dword ptr [ESP + param_2]
//         0044fba8     PUSH       ESI
//         0044fba9     MOV        ESI,this
//         0044fbab     MOV        this,dword ptr [ESP + param_3]
//         0044fbaf     PUSH       EDI
//         0044fbb0     MOV        EDI,dword ptr [ESP + param_1]
//         0044fbb4     PUSH       EAX
//         0044fbb5     PUSH       this
//         0044fbb6     PUSH       EDX
//         0044fbb7     PUSH       EDI
//         0044fbb8     MOV        this,ESI
//         0044fbba     CALL       RGE_Master_Static_Object::setup                  int setup(RGE_Master_Static_Object * this, _i
//                              m_an_obj.cpp:82 (4)
//         0044fbbf     MOV        byte ptr [ESI + 0x4],0x14
//                              m_an_obj.cpp:85 (21)
//         0044fbc3     ADD        ESI,0xb8
//         0044fbc9     PUSH       ESI
//         0044fbca     PUSH       s_%f                                             = "%f"
//         0044fbcf     PUSH       EDI
//         0044fbd0     CALL       fscanf                                           undefined fscanf()
//         0044fbd5     ADD        ESP,0xc
//                              m_an_obj.cpp:88 (5)
//         0044fbd8     MOV        EAX,0x1
//                              m_an_obj.cpp:89 (5)
//         0044fbdd     POP        EDI
//         0044fbde     POP        ESI
//         0044fbdf     RET        0x10
//         0044fbe2     ??         90h
//         0044fbe3     NOP
//         0044fbe4     NOP
//         0044fbe5     NOP
//         0044fbe6     NOP
//         0044fbe7     NOP
//         0044fbe8     NOP
//         0044fbe9     NOP
//         0044fbea     NOP
//         0044fbeb     NOP
//         0044fbec     NOP
//         0044fbed     NOP
//         0044fbee     NOP
//         0044fbef     NOP
    return 0;
}

int RGE_Master_Animated_Object::setup(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4) {
    /* TODO: Stub */
//                              int __thiscall setup(RGE_Master_Animated_Object * this, _iobuf * par
//              int               EAX:4          <RETURN>
//              RGE_Master_Ani    ECX:4 (auto)   this
//              _iobuf *          Stack[0x4]:4   param_1                   XREF[1]:     0044fbb0(R)
//              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     0044fba4(R)
//              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[1]:     0044fbab(R)
//              short             Stack[0x10]:2  param_4                   XREF[1]:     0044fba0(R)
//                               ?setup@RGE_Master_Animated_Object@@IAEHPAU_iobuf@@PAPAVRGE_  XREF[3]:     RGE_Master_Animated_Object:0044fb0
//                               RGE_Master_Animated_Object::setup                                         setup:00451299(c),
//                                                                                                         setup:00451d2c(c)
//                              m_an_obj.cpp:79 (31)
//         0044fba0     MOV        EAX,dword ptr [ESP + param_4]
//         0044fba4     MOV        EDX,dword ptr [ESP + param_2]
//         0044fba8     PUSH       ESI
//         0044fba9     MOV        ESI,this
//         0044fbab     MOV        this,dword ptr [ESP + param_3]
//         0044fbaf     PUSH       EDI
//         0044fbb0     MOV        EDI,dword ptr [ESP + param_1]
//         0044fbb4     PUSH       EAX
//         0044fbb5     PUSH       this
//         0044fbb6     PUSH       EDX
//         0044fbb7     PUSH       EDI
//         0044fbb8     MOV        this,ESI
//         0044fbba     CALL       RGE_Master_Static_Object::setup                  int setup(RGE_Master_Static_Object * this, _i
//                              m_an_obj.cpp:82 (4)
//         0044fbbf     MOV        byte ptr [ESI + 0x4],0x14
//                              m_an_obj.cpp:85 (21)
//         0044fbc3     ADD        ESI,0xb8
//         0044fbc9     PUSH       ESI
//         0044fbca     PUSH       s_%f                                             = "%f"
//         0044fbcf     PUSH       EDI
//         0044fbd0     CALL       fscanf                                           undefined fscanf()
//         0044fbd5     ADD        ESP,0xc
//                              m_an_obj.cpp:88 (5)
//         0044fbd8     MOV        EAX,0x1
//                              m_an_obj.cpp:89 (5)
//         0044fbdd     POP        EDI
//         0044fbde     POP        ESI
//         0044fbdf     RET        0x10
//         0044fbe2     ??         90h
//         0044fbe3     NOP
//         0044fbe4     NOP
//         0044fbe5     NOP
//         0044fbe6     NOP
//         0044fbe7     NOP
//         0044fbe8     NOP
//         0044fbe9     NOP
//         0044fbea     NOP
//         0044fbeb     NOP
//         0044fbec     NOP
//         0044fbed     NOP
//         0044fbee     NOP
//         0044fbef     NOP
    return 0;
}

RGE_Master_Animated_Object::~RGE_Master_Animated_Object() {
    /* TODO: Stub */
//                              void __thiscall ~RGE_Master_Animated_Object(RGE_Master_Animated_Obje
//              void              <VOID>         <RETURN>
//              RGE_Master_Ani    ECX:4 (auto)   this
//                               ??1RGE_Master_Animated_Object@@UAE@XZ                        XREF[3]:     `vector_deleting_destructor':0044f
//                               RGE_Master_Animated_Object::~RGE_Master_Animated_Object                   ~RGE_Master_Doppleganger_Object:00
//                                                                                                         ~RGE_Master_Moving_Object:00451de6
//                              m_an_obj.cpp:94 (11)
//         0044fbf0     MOV        dword ptr [this->_padding_],RGE_Master_Animate   = 0044fa20
//         0044fbf6     JMP        RGE_Master_Static_Object::~RGE_Master_Static_O   void ~RGE_Master_Static_Object(RGE_Master_Sta
//                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
//         0044fbfb     ??         90h
//         0044fbfc     NOP
//         0044fbfd     NOP
//         0044fbfe     NOP
//         0044fbff     NOP
}

RGE_Static_Object* RGE_Master_Animated_Object::make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4) {
    /* TODO: Stub */
//                              RGE_Static_Object * __thiscall make_new_obj(RGE_Master_Animated_Obje
//              RGE_Static_Obj    EAX:4          <RETURN>
//              RGE_Master_Ani    ECX:4 (auto)   this
//              RGE_Player *      Stack[0x4]:4   param_1                   XREF[2]:     0044fc17(R), 0044fc75(W)
//              float             Stack[0x8]:4   param_2                   XREF[2]:     0044fc45(R), 0044fc90(R)
//              float             Stack[0xc]:4   param_3                   XREF[2]:     0044fc3e(R), 0044fc89(R)
//              float             Stack[0x10]:4  param_4                   XREF[2]:     0044fc3a(R), 0044fc85(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0044fc7b(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     0044fc9f(R), 0044fcb3(R)
//                               ?make_new_obj@RGE_Master_Animated_Object@@UAEPAVRGE_Static_  XREF[2]:     005704a0(*), 00570538(*)
//                               RGE_Master_Animated_Object::make_new_obj
//                              m_an_obj.cpp:100 (23)
//         0044fc00     MOV        EAX,FS:[0x0]
//         0044fc06     PUSH       -0x1
//         0044fc08     PUSH       FUN_0055d77b
//         0044fc0d     PUSH       EAX
//         0044fc0e     MOV        dword ptr FS:[0x0],ESP
//         0044fc15     PUSH       EBX
//         0044fc16     PUSH       ESI
//                              m_an_obj.cpp:103 (17)
//         0044fc17     MOV        EBX,dword ptr [ESP + param_1]
//         0044fc1b     PUSH       EDI
//         0044fc1c     MOV        EDI,this
//         0044fc1e     MOV        AL,byte ptr [EDI + 0xa4]
//         0044fc24     TEST       AL,AL
//         0044fc26     JZ         LAB_0044fc68
//                              m_an_obj.cpp:105 (14)
//         0044fc28     MOV        AL,byte ptr [EDI + 0x4]
//         0044fc2b     MOV        this,dword ptr [EBX + 0x3c]
//         0044fc2e     PUSH       EAX
//         0044fc2f     CALL       RGE_Game_World::recycle_object_in_to_game        RGE_Static_Object * recycle_object_in_to_game
//         0044fc34     MOV        ESI,EAX
//                              m_an_obj.cpp:106 (4)
//         0044fc36     TEST       ESI,ESI
//         0044fc38     JZ         LAB_0044fc68
//                              m_an_obj.cpp:108 (24)
//         0044fc3a     MOV        EAX,dword ptr [ESP + param_4]
//         0044fc3e     MOV        this,dword ptr [ESP + param_3]
//         0044fc42     MOV        EDX,dword ptr [ESI]
//         0044fc44     PUSH       EAX
//         0044fc45     MOV        EAX,dword ptr [ESP + param_2]
//         0044fc49     PUSH       this
//         0044fc4a     PUSH       EAX
//         0044fc4b     PUSH       EBX
//         0044fc4c     PUSH       EDI
//         0044fc4d     MOV        this,ESI
//         0044fc4f     CALL       dword ptr [EDX + 0x4]
//                              m_an_obj.cpp:109 (2)
//         0044fc52     MOV        EAX,ESI
//                              m_an_obj.cpp:114 (20)
//         0044fc54     MOV        this,dword ptr [ESP + 0xc]
//         0044fc58     MOV        dword ptr FS:[0x0],this
//         0044fc5f     POP        EDI
//         0044fc60     POP        ESI
//         0044fc61     POP        EBX
//         0044fc62     ADD        ESP,0xc
//         0044fc65     RET        0x10
//                               LAB_0044fc68                                                 XREF[2]:     0044fc26(j), 0044fc38(j)
//                              m_an_obj.cpp:113 (55)
//         0044fc68     PUSH       0x8c
//         0044fc6d     CALL       operator_new                                     void * operator_new(uint param_1)
//         0044fc72     ADD        ESP,0x4
//         0044fc75     MOV        dword ptr [ESP + param_1],EAX
//         0044fc79     TEST       EAX,EAX
//         0044fc7b     MOV        dword ptr [ESP + local_4],0x0
//         0044fc83     JZ         LAB_0044fcb3
//         0044fc85     MOV        this,dword ptr [ESP + param_4]
//         0044fc89     MOV        EDX,dword ptr [ESP + param_3]
//         0044fc8d     PUSH       0x1
//         0044fc8f     PUSH       this
//         0044fc90     MOV        this,dword ptr [ESP + param_2]
//         0044fc94     PUSH       EDX
//         0044fc95     PUSH       this
//         0044fc96     PUSH       EBX
//         0044fc97     PUSH       EDI
//         0044fc98     MOV        this,EAX
//         0044fc9a     CALL       RGE_Animated_Object::RGE_Animated_Object         undefined RGE_Animated_Object(RGE_Animated_Ob
//                              m_an_obj.cpp:114 (42)
//         0044fc9f     MOV        this,dword ptr [ESP + local_c]
//         0044fca3     MOV        dword ptr FS:[0x0],this
//         0044fcaa     POP        EDI
//         0044fcab     POP        ESI
//         0044fcac     POP        EBX
//         0044fcad     ADD        ESP,0xc
//         0044fcb0     RET        0x10
//                               LAB_0044fcb3                                                 XREF[1]:     0044fc83(j)
//         0044fcb3     MOV        this,dword ptr [ESP + local_c]
//         0044fcb7     POP        EDI
//         0044fcb8     POP        ESI
//         0044fcb9     XOR        EAX,EAX
//         0044fcbb     MOV        dword ptr FS:[0x0],this
//         0044fcc2     POP        EBX
//         0044fcc3     ADD        ESP,0xc
//         0044fcc6     RET        0x10
//         0044fcc9     ??         90h
//         0044fcca     NOP
//         0044fccb     NOP
//         0044fccc     NOP
//         0044fccd     NOP
//         0044fcce     NOP
//         0044fccf     NOP
    return 0;
}

void RGE_Master_Animated_Object::copy_obj(RGE_Master_Static_Object* param_1) {
    /* TODO: Stub */
//                              void __thiscall copy_obj(RGE_Master_Animated_Object * this, RGE_Mast
//              void              <VOID>         <RETURN>
//              RGE_Master_Ani    ECX:4 (auto)   this
//              RGE_Master_Sta    Stack[0x4]:4   param_1                   XREF[1]:     0044fd42(R)
//                               ?copy_obj@RGE_Master_Animated_Object@@UAEXPAVRGE_Master_Sta  XREF[3]:     copy_obj:00451425(c),
//                               RGE_Master_Animated_Object::copy_obj                                      copy_obj:00451f39(c), 0057048c(*)
//                              m_an_obj.cpp:126 (2)
//         0044fd40     PUSH       ESI
//         0044fd41     PUSH       EDI
//                              m_an_obj.cpp:129 (12)
//         0044fd42     MOV        EDI,dword ptr [ESP + param_1]
//         0044fd46     MOV        ESI,this
//         0044fd48     PUSH       EDI
//         0044fd49     CALL       RGE_Master_Static_Object::copy_obj               void copy_obj(RGE_Master_Static_Object * this
//                              m_an_obj.cpp:131 (6)
//         0044fd4e     MOV        EAX,dword ptr [EDI + 0xb8]
//                              m_an_obj.cpp:132 (11)
//         0044fd54     POP        EDI
//         0044fd55     MOV        dword ptr [ESI + 0xb8],EAX
//         0044fd5b     POP        ESI
//         0044fd5c     RET        0x4
//         0044fd5f     ??         90h
    return;
}

void RGE_Master_Animated_Object::modify(float param_1, uchar param_2) {
    /* TODO: Stub */
//                              void __thiscall modify(RGE_Master_Animated_Object * this, float para
//              void              <VOID>         <RETURN>
//              RGE_Master_Ani    ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1                   XREF[2]:     0044fd69(R), 0044fd76(R)
//              uchar             Stack[0x8]:1   param_2                   XREF[1]:     0044fd60(R)
//                               ?modify@RGE_Master_Animated_Object@@UAEXME@Z                 XREF[3]:     modify:00451fbe(c), 00570490(*),
//                               RGE_Master_Animated_Object::modify                                        00570528(*)
//                              m_an_obj.cpp:136 (8)
//         0044fd60     MOV        EAX,dword ptr [ESP + param_2]
//         0044fd64     CMP        AL,0x5
//         0044fd66     JZ         LAB_0044fd76
//                              m_an_obj.cpp:143 (11)
//         0044fd68     PUSH       EAX
//         0044fd69     MOV        EAX,dword ptr [ESP + param_1]
//         0044fd6d     PUSH       EAX
//         0044fd6e     CALL       RGE_Master_Static_Object::modify                 void modify(RGE_Master_Static_Object * this,
//                              m_an_obj.cpp:170 (3)
//         0044fd73     RET        0x8
//                               LAB_0044fd76                                                 XREF[1]:     0044fd66(j)
//                              m_an_obj.cpp:140 (10)
//         0044fd76     MOV        EDX,dword ptr [ESP + param_1]
//         0044fd7a     MOV        dword ptr [ECX + this->speed],EDX
//                              m_an_obj.cpp:170 (3)
//         0044fd80     RET        0x8
//         0044fd83     ??         90h
//         0044fd84     NOP
//         0044fd85     NOP
//         0044fd86     NOP
//         0044fd87     NOP
//         0044fd88     NOP
//         0044fd89     NOP
//         0044fd8a     NOP
//         0044fd8b     NOP
//         0044fd8c     NOP
//         0044fd8d     NOP
//         0044fd8e     NOP
//         0044fd8f     NOP
    return;
}

void RGE_Master_Animated_Object::modify_delta(float param_1, uchar param_2) {
    /* TODO: Stub */
//                              void __thiscall modify_delta(RGE_Master_Animated_Object * this, floa
//              void              <VOID>         <RETURN>
//              RGE_Master_Ani    ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1                   XREF[2]:     0044fd99(R), 0044fda6(R)
//              uchar             Stack[0x8]:1   param_2                   XREF[1]:     0044fd90(R)
//                               ?modify_delta@RGE_Master_Animated_Object@@UAEXME@Z           XREF[3]:     modify_delta:00451fee(c),
//                               RGE_Master_Animated_Object::modify_delta                                  00570494(*), 0057052c(*)
//                              m_an_obj.cpp:174 (8)
//         0044fd90     MOV        EAX,dword ptr [ESP + param_2]
//         0044fd94     CMP        AL,0x5
//         0044fd96     JZ         LAB_0044fda6
//                              m_an_obj.cpp:181 (11)
//         0044fd98     PUSH       EAX
//         0044fd99     MOV        EAX,dword ptr [ESP + param_1]
//         0044fd9d     PUSH       EAX
//         0044fd9e     CALL       RGE_Master_Static_Object::modify_delta           void modify_delta(RGE_Master_Static_Object *
//                              m_an_obj.cpp:208 (3)
//         0044fda3     RET        0x8
//                               LAB_0044fda6                                                 XREF[1]:     0044fd96(j)
//                              m_an_obj.cpp:178 (16)
//         0044fda6     FLD        float ptr [ESP + param_1]
//         0044fdaa     FADD       float ptr [ECX + this->speed]
//         0044fdb0     FSTP       float ptr [ECX + this->speed]
//                              m_an_obj.cpp:208 (3)
//         0044fdb6     RET        0x8
//         0044fdb9     ??         90h
//         0044fdba     NOP
//         0044fdbb     NOP
//         0044fdbc     NOP
//         0044fdbd     NOP
//         0044fdbe     NOP
//         0044fdbf     NOP
    return;
}

void RGE_Master_Animated_Object::modify_percent(float param_1, uchar param_2) {
    /* TODO: Stub */
//                              void __thiscall modify_percent(RGE_Master_Animated_Object * this, fl
//              void              <VOID>         <RETURN>
//              RGE_Master_Ani    ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1                   XREF[2]:     0044fdc9(R), 0044fdd6(R)
//              uchar             Stack[0x8]:1   param_2                   XREF[1]:     0044fdc0(R)
//                               ?modify_percent@RGE_Master_Animated_Object@@UAEXME@Z         XREF[3]:     modify_percent:0045201e(c),
//                               RGE_Master_Animated_Object::modify_percent                                00570498(*), 00570530(*)
//                              m_an_obj.cpp:212 (8)
//         0044fdc0     MOV        EAX,dword ptr [ESP + param_2]
//         0044fdc4     CMP        AL,0x5
//         0044fdc6     JZ         LAB_0044fdd6
//                              m_an_obj.cpp:219 (11)
//         0044fdc8     PUSH       EAX
//         0044fdc9     MOV        EAX,dword ptr [ESP + param_1]
//         0044fdcd     PUSH       EAX
//         0044fdce     CALL       RGE_Master_Static_Object::modify_percent         void modify_percent(RGE_Master_Static_Object
//                              m_an_obj.cpp:246 (3)
//         0044fdd3     RET        0x8
//                               LAB_0044fdd6                                                 XREF[1]:     0044fdc6(j)
//                              m_an_obj.cpp:216 (16)
//         0044fdd6     FLD        float ptr [ESP + param_1]
//         0044fdda     FMUL       float ptr [ECX + this->speed]
//         0044fde0     FSTP       float ptr [ECX + this->speed]
//                              m_an_obj.cpp:246 (3)
//         0044fde6     RET        0x8
//         0044fde9     ??         90h
//         0044fdea     NOP
//         0044fdeb     NOP
//         0044fdec     NOP
//         0044fded     NOP
//         0044fdee     NOP
//         0044fdef     NOP
    return;
}

void RGE_Master_Animated_Object::save(int param_1) {
    /* TODO: Stub */
//                              void __thiscall save(RGE_Master_Animated_Object * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_Master_Ani    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0044fdf2(R)
//                               ?save@RGE_Master_Animated_Object@@UAEXH@Z                    XREF[3]:     save:00451435(c),
//                               RGE_Master_Animated_Object::save                                          save:0045207b(c), 0057049c(*)
//                              m_an_obj.cpp:251 (2)
//         0044fdf0     PUSH       ESI
//         0044fdf1     PUSH       EDI
//                              m_an_obj.cpp:252 (12)
//         0044fdf2     MOV        EDI,dword ptr [ESP + param_1]
//         0044fdf6     MOV        ESI,this
//         0044fdf8     PUSH       EDI
//         0044fdf9     CALL       RGE_Master_Static_Object::save                   void save(RGE_Master_Static_Object * this, in
//                              m_an_obj.cpp:254 (18)
//         0044fdfe     ADD        ESI,0xb8
//         0044fe04     PUSH       0x4
//         0044fe06     PUSH       ESI
//         0044fe07     PUSH       EDI
//         0044fe08     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0044fe0d     ADD        ESP,0xc
//                              m_an_obj.cpp:255 (5)
//         0044fe10     POP        EDI
//         0044fe11     POP        ESI
//         0044fe12     RET        0x4
//         0044fe15     ??         90h
//         0044fe16     NOP
//         0044fe17     NOP
//         0044fe18     NOP
//         0044fe19     NOP
//         0044fe1a     NOP
//         0044fe1b     NOP
//         0044fe1c     NOP
//         0044fe1d     NOP
//         0044fe1e     NOP
//         0044fe1f     NOP
    return;
}

RGE_Master_Static_Object* RGE_Master_Animated_Object::make_new_master() {
    /* TODO: Stub */
// <NO ASSEMBLY FOUND>
    return 0;
}

