#include "../common.h"
#include "m_mi_obj.h"

RGE_Master_Missile_Object::RGE_Master_Missile_Object(RGE_Master_Missile_Object* param_1, int param_2) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Master_Missile_Object(RGE_Master_Missile_Ob
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Master_Mis    ECX:4 (auto)   this
//              _iobuf *          Stack[0x4]:4   param_1                   XREF[2]:     00451546(R), 00451581(R)
//              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     00451550(R)
//              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[1]:     0045154b(R)
//              short             Stack[0x10]:2  param_4                   XREF[1]:     00451556(R)
//              int               Stack[0x14]:4  param_5                   XREF[1]:     0045156b(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0045156f(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00451590(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00451562(W)
//                               ??0RGE_Master_Missile_Object@@QAE@PAU_iobuf@@PAPAVRGE_Sprit  XREF[1]:     load_object:004616b6(c)
//                               RGE_Master_Missile_Object::RGE_Master_Missile_Object
//                              m_mi_obj.cpp:42 (59)
//         00451530     PUSH       -0x1
//         00451532     PUSH       FUN_0055d938
//         00451537     MOV        EAX,FS:[0x0]
//         0045153d     PUSH       EAX
//         0045153e     MOV        dword ptr FS:[0x0],ESP
//         00451545     PUSH       this
//         00451546     MOV        EAX,dword ptr [ESP + param_1]
//         0045154a     PUSH       EBX
//         0045154b     MOV        EBX,dword ptr [ESP + param_3]
//         0045154f     PUSH       EBP
//         00451550     MOV        EBP,dword ptr [ESP + param_2]
//         00451554     PUSH       ESI
//         00451555     PUSH       EDI
//         00451556     MOV        EDI,dword ptr [ESP + param_4]
//         0045155a     PUSH       0x0
//         0045155c     PUSH       EDI
//         0045155d     PUSH       EBX
//         0045155e     MOV        ESI,this
//         00451560     PUSH       EBP
//         00451561     PUSH       EAX
//         00451562     MOV        dword ptr [ESP + local_10],ESI
//         00451566     CALL       RGE_Master_Combat_Object::RGE_Master_Combat_Ob   undefined RGE_Master_Combat_Object(RGE_Master
//                              m_mi_obj.cpp:43 (22)
//         0045156b     MOV        EAX,dword ptr [ESP + param_5]
//         0045156f     MOV        dword ptr [ESP + local_4],0x0
//         00451577     TEST       EAX,EAX
//         00451579     MOV        dword ptr [ESI],RGE_Master_Missile_Object::`vf   = 004514a0
//         0045157f     JZ         LAB_00451590
//                              m_mi_obj.cpp:44 (15)
//         00451581     MOV        this,dword ptr [ESP + param_1]
//         00451585     PUSH       EDI
//         00451586     PUSH       EBX
//         00451587     PUSH       EBP
//         00451588     PUSH       this
//         00451589     MOV        this,ESI
//         0045158b     CALL       RGE_Master_Missile_Object::setup                 int setup(RGE_Master_Missile_Object * this, _
//                               LAB_00451590                                                 XREF[1]:     0045157f(j)
//                              m_mi_obj.cpp:45 (23)
//         00451590     MOV        this,dword ptr [ESP + local_c]
//         00451594     MOV        EAX,ESI
//         00451596     POP        EDI
//         00451597     POP        ESI
//         00451598     POP        EBP
//         00451599     MOV        dword ptr FS:[0x0],this
//         004515a0     POP        EBX
//         004515a1     ADD        ESP,0x10
//         004515a4     RET        0x14
//         004515a7     ??         90h
//         004515a8     NOP
//         004515a9     NOP
//         004515aa     NOP
//         004515ab     NOP
//         004515ac     NOP
//         004515ad     NOP
//         004515ae     NOP
//         004515af     NOP
}

RGE_Master_Missile_Object::RGE_Master_Missile_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Master_Missile_Object(RGE_Master_Missile_Ob
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Master_Mis    ECX:4 (auto)   this
//              _iobuf *          Stack[0x4]:4   param_1                   XREF[2]:     00451546(R), 00451581(R)
//              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     00451550(R)
//              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[1]:     0045154b(R)
//              short             Stack[0x10]:2  param_4                   XREF[1]:     00451556(R)
//              int               Stack[0x14]:4  param_5                   XREF[1]:     0045156b(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0045156f(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00451590(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00451562(W)
//                               ??0RGE_Master_Missile_Object@@QAE@PAU_iobuf@@PAPAVRGE_Sprit  XREF[1]:     load_object:004616b6(c)
//                               RGE_Master_Missile_Object::RGE_Master_Missile_Object
//                              m_mi_obj.cpp:42 (59)
//         00451530     PUSH       -0x1
//         00451532     PUSH       FUN_0055d938
//         00451537     MOV        EAX,FS:[0x0]
//         0045153d     PUSH       EAX
//         0045153e     MOV        dword ptr FS:[0x0],ESP
//         00451545     PUSH       this
//         00451546     MOV        EAX,dword ptr [ESP + param_1]
//         0045154a     PUSH       EBX
//         0045154b     MOV        EBX,dword ptr [ESP + param_3]
//         0045154f     PUSH       EBP
//         00451550     MOV        EBP,dword ptr [ESP + param_2]
//         00451554     PUSH       ESI
//         00451555     PUSH       EDI
//         00451556     MOV        EDI,dword ptr [ESP + param_4]
//         0045155a     PUSH       0x0
//         0045155c     PUSH       EDI
//         0045155d     PUSH       EBX
//         0045155e     MOV        ESI,this
//         00451560     PUSH       EBP
//         00451561     PUSH       EAX
//         00451562     MOV        dword ptr [ESP + local_10],ESI
//         00451566     CALL       RGE_Master_Combat_Object::RGE_Master_Combat_Ob   undefined RGE_Master_Combat_Object(RGE_Master
//                              m_mi_obj.cpp:43 (22)
//         0045156b     MOV        EAX,dword ptr [ESP + param_5]
//         0045156f     MOV        dword ptr [ESP + local_4],0x0
//         00451577     TEST       EAX,EAX
//         00451579     MOV        dword ptr [ESI],RGE_Master_Missile_Object::`vf   = 004514a0
//         0045157f     JZ         LAB_00451590
//                              m_mi_obj.cpp:44 (15)
//         00451581     MOV        this,dword ptr [ESP + param_1]
//         00451585     PUSH       EDI
//         00451586     PUSH       EBX
//         00451587     PUSH       EBP
//         00451588     PUSH       this
//         00451589     MOV        this,ESI
//         0045158b     CALL       RGE_Master_Missile_Object::setup                 int setup(RGE_Master_Missile_Object * this, _
//                               LAB_00451590                                                 XREF[1]:     0045157f(j)
//                              m_mi_obj.cpp:45 (23)
//         00451590     MOV        this,dword ptr [ESP + local_c]
//         00451594     MOV        EAX,ESI
//         00451596     POP        EDI
//         00451597     POP        ESI
//         00451598     POP        EBP
//         00451599     MOV        dword ptr FS:[0x0],this
//         004515a0     POP        EBX
//         004515a1     ADD        ESP,0x10
//         004515a4     RET        0x14
//         004515a7     ??         90h
//         004515a8     NOP
//         004515a9     NOP
//         004515aa     NOP
//         004515ab     NOP
//         004515ac     NOP
//         004515ad     NOP
//         004515ae     NOP
//         004515af     NOP
}

RGE_Master_Missile_Object::RGE_Master_Missile_Object(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Master_Missile_Object(RGE_Master_Missile_Ob
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Master_Mis    ECX:4 (auto)   this
//              _iobuf *          Stack[0x4]:4   param_1                   XREF[2]:     00451546(R), 00451581(R)
//              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     00451550(R)
//              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[1]:     0045154b(R)
//              short             Stack[0x10]:2  param_4                   XREF[1]:     00451556(R)
//              int               Stack[0x14]:4  param_5                   XREF[1]:     0045156b(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0045156f(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00451590(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00451562(W)
//                               ??0RGE_Master_Missile_Object@@QAE@PAU_iobuf@@PAPAVRGE_Sprit  XREF[1]:     load_object:004616b6(c)
//                               RGE_Master_Missile_Object::RGE_Master_Missile_Object
//                              m_mi_obj.cpp:42 (59)
//         00451530     PUSH       -0x1
//         00451532     PUSH       FUN_0055d938
//         00451537     MOV        EAX,FS:[0x0]
//         0045153d     PUSH       EAX
//         0045153e     MOV        dword ptr FS:[0x0],ESP
//         00451545     PUSH       this
//         00451546     MOV        EAX,dword ptr [ESP + param_1]
//         0045154a     PUSH       EBX
//         0045154b     MOV        EBX,dword ptr [ESP + param_3]
//         0045154f     PUSH       EBP
//         00451550     MOV        EBP,dword ptr [ESP + param_2]
//         00451554     PUSH       ESI
//         00451555     PUSH       EDI
//         00451556     MOV        EDI,dword ptr [ESP + param_4]
//         0045155a     PUSH       0x0
//         0045155c     PUSH       EDI
//         0045155d     PUSH       EBX
//         0045155e     MOV        ESI,this
//         00451560     PUSH       EBP
//         00451561     PUSH       EAX
//         00451562     MOV        dword ptr [ESP + local_10],ESI
//         00451566     CALL       RGE_Master_Combat_Object::RGE_Master_Combat_Ob   undefined RGE_Master_Combat_Object(RGE_Master
//                              m_mi_obj.cpp:43 (22)
//         0045156b     MOV        EAX,dword ptr [ESP + param_5]
//         0045156f     MOV        dword ptr [ESP + local_4],0x0
//         00451577     TEST       EAX,EAX
//         00451579     MOV        dword ptr [ESI],RGE_Master_Missile_Object::`vf   = 004514a0
//         0045157f     JZ         LAB_00451590
//                              m_mi_obj.cpp:44 (15)
//         00451581     MOV        this,dword ptr [ESP + param_1]
//         00451585     PUSH       EDI
//         00451586     PUSH       EBX
//         00451587     PUSH       EBP
//         00451588     PUSH       this
//         00451589     MOV        this,ESI
//         0045158b     CALL       RGE_Master_Missile_Object::setup                 int setup(RGE_Master_Missile_Object * this, _
//                               LAB_00451590                                                 XREF[1]:     0045157f(j)
//                              m_mi_obj.cpp:45 (23)
//         00451590     MOV        this,dword ptr [ESP + local_c]
//         00451594     MOV        EAX,ESI
//         00451596     POP        EDI
//         00451597     POP        ESI
//         00451598     POP        EBP
//         00451599     MOV        dword ptr FS:[0x0],this
//         004515a0     POP        EBX
//         004515a1     ADD        ESP,0x10
//         004515a4     RET        0x14
//         004515a7     ??         90h
//         004515a8     NOP
//         004515a9     NOP
//         004515aa     NOP
//         004515ab     NOP
//         004515ac     NOP
//         004515ad     NOP
//         004515ae     NOP
//         004515af     NOP
}

int RGE_Master_Missile_Object::setup(RGE_Master_Missile_Object* param_1) {
    /* TODO: Stub */
//                              int __thiscall setup(RGE_Master_Missile_Object * this, _iobuf * para
//              int               EAX:4          <RETURN>
//              RGE_Master_Mis    ECX:4 (auto)   this
//              _iobuf *          Stack[0x4]:4   param_1                   XREF[3]:     004516d1(R), 004516e6(*), 0045172b(R)
//              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[3]:     004516c5(R), 004516eb(*), 0045171e(R)
//              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[3]:     004516cc(R), 004516f0(*), 0045171a(R)
//              short             Stack[0x10]:2  param_4                   XREF[3]:     004516c1(R), 004516f5(*), 00451716(R)
//              undefined         Stack[-0x2]:1  local_2                   XREF[2]:     004516fa(*), 00451735(R)
//              short             Stack[-0x6]:2  temp_missile_type
//                               ?setup@RGE_Master_Missile_Object@@IAEHPAU_iobuf@@PAPAVRGE_S  XREF[1]:     RGE_Master_Missile_Object:0045158b
//                               RGE_Master_Missile_Object::setup
//                              m_mi_obj.cpp:88 (1)
//         004516c0     PUSH       this
//                              m_mi_obj.cpp:95 (31)
//         004516c1     MOV        EAX,dword ptr [ESP + param_4]
//         004516c5     MOV        EDX,dword ptr [ESP + param_2]
//         004516c9     PUSH       ESI
//         004516ca     MOV        ESI,this
//         004516cc     MOV        this,dword ptr [ESP + param_3]
//         004516d0     PUSH       EDI
//         004516d1     MOV        EDI,dword ptr [ESP + param_1]
//         004516d5     PUSH       EAX
//         004516d6     PUSH       this
//         004516d7     PUSH       EDX
//         004516d8     PUSH       EDI
//         004516d9     MOV        this,ESI
//         004516db     CALL       RGE_Master_Combat_Object::setup                  int setup(RGE_Master_Combat_Object * this, _i
//                              m_mi_obj.cpp:108 (54)
//         004516e0     LEA        EAX,[ESI + 0x150]
//         004516e6     LEA        this=>param_1,[ESP + 0x10]
//         004516ea     PUSH       EAX
//         004516eb     LEA        EDX=>param_2,[ESP + 0x18]
//         004516ef     PUSH       this
//         004516f0     LEA        EAX=>param_3,[ESP + 0x20]
//         004516f4     PUSH       EDX
//         004516f5     LEA        this=>param_4,[ESP + 0x28]
//         004516f9     PUSH       EAX
//         004516fa     LEA        EDX=>local_2,[ESP + 0x1a]
//         004516fe     PUSH       this
//         004516ff     PUSH       EDX
//         00451700     PUSH       s_%hd_%hd_%hd_%hd_%hd_%f                         = "%hd %hd %hd %hd %hd %f"
//         00451705     PUSH       EDI
//         00451706     MOV        byte ptr [ESI + 0xa4],0x1
//         0045170d     MOV        byte ptr [ESI + 0x4],0x3c
//         00451711     CALL       fscanf                                           undefined fscanf()
//                              m_mi_obj.cpp:111 (4)
//         00451716     MOV        AL,byte ptr [ESP + param_4]
//                              m_mi_obj.cpp:112 (4)
//         0045171a     MOV        this,byte ptr [ESP + param_3]
//                              m_mi_obj.cpp:113 (13)
//         0045171e     MOV        DL,byte ptr [ESP + param_2]
//         00451722     ADD        ESP,0x20
//         00451725     MOV        byte ptr [ESI + 0x149],AL
//                              m_mi_obj.cpp:114 (10)
//         0045172b     MOV        AL,byte ptr [ESP + param_1]
//         0045172f     MOV        byte ptr [ESI + 0x14a],this
//                              m_mi_obj.cpp:115 (22)
//         00451735     MOV        this,byte ptr [ESP + local_2]
//         00451739     MOV        byte ptr [ESI + 0x14b],DL
//         0045173f     MOV        byte ptr [ESI + 0x14c],AL
//         00451745     MOV        byte ptr [ESI + 0x148],this
//                              m_mi_obj.cpp:118 (11)
//         0045174b     POP        EDI
//         0045174c     MOV        EAX,0x1
//         00451751     POP        ESI
//         00451752     POP        this
//         00451753     RET        0x10
//         00451756     ??         90h
//         00451757     NOP
//         00451758     NOP
//         00451759     NOP
//         0045175a     NOP
//         0045175b     NOP
//         0045175c     NOP
//         0045175d     NOP
//         0045175e     NOP
//         0045175f     NOP
    return 0;
}

int RGE_Master_Missile_Object::setup(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3) {
    /* TODO: Stub */
//                              int __thiscall setup(RGE_Master_Missile_Object * this, _iobuf * para
//              int               EAX:4          <RETURN>
//              RGE_Master_Mis    ECX:4 (auto)   this
//              _iobuf *          Stack[0x4]:4   param_1                   XREF[3]:     004516d1(R), 004516e6(*), 0045172b(R)
//              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[3]:     004516c5(R), 004516eb(*), 0045171e(R)
//              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[3]:     004516cc(R), 004516f0(*), 0045171a(R)
//              short             Stack[0x10]:2  param_4                   XREF[3]:     004516c1(R), 004516f5(*), 00451716(R)
//              undefined         Stack[-0x2]:1  local_2                   XREF[2]:     004516fa(*), 00451735(R)
//              short             Stack[-0x6]:2  temp_missile_type
//                               ?setup@RGE_Master_Missile_Object@@IAEHPAU_iobuf@@PAPAVRGE_S  XREF[1]:     RGE_Master_Missile_Object:0045158b
//                               RGE_Master_Missile_Object::setup
//                              m_mi_obj.cpp:88 (1)
//         004516c0     PUSH       this
//                              m_mi_obj.cpp:95 (31)
//         004516c1     MOV        EAX,dword ptr [ESP + param_4]
//         004516c5     MOV        EDX,dword ptr [ESP + param_2]
//         004516c9     PUSH       ESI
//         004516ca     MOV        ESI,this
//         004516cc     MOV        this,dword ptr [ESP + param_3]
//         004516d0     PUSH       EDI
//         004516d1     MOV        EDI,dword ptr [ESP + param_1]
//         004516d5     PUSH       EAX
//         004516d6     PUSH       this
//         004516d7     PUSH       EDX
//         004516d8     PUSH       EDI
//         004516d9     MOV        this,ESI
//         004516db     CALL       RGE_Master_Combat_Object::setup                  int setup(RGE_Master_Combat_Object * this, _i
//                              m_mi_obj.cpp:108 (54)
//         004516e0     LEA        EAX,[ESI + 0x150]
//         004516e6     LEA        this=>param_1,[ESP + 0x10]
//         004516ea     PUSH       EAX
//         004516eb     LEA        EDX=>param_2,[ESP + 0x18]
//         004516ef     PUSH       this
//         004516f0     LEA        EAX=>param_3,[ESP + 0x20]
//         004516f4     PUSH       EDX
//         004516f5     LEA        this=>param_4,[ESP + 0x28]
//         004516f9     PUSH       EAX
//         004516fa     LEA        EDX=>local_2,[ESP + 0x1a]
//         004516fe     PUSH       this
//         004516ff     PUSH       EDX
//         00451700     PUSH       s_%hd_%hd_%hd_%hd_%hd_%f                         = "%hd %hd %hd %hd %hd %f"
//         00451705     PUSH       EDI
//         00451706     MOV        byte ptr [ESI + 0xa4],0x1
//         0045170d     MOV        byte ptr [ESI + 0x4],0x3c
//         00451711     CALL       fscanf                                           undefined fscanf()
//                              m_mi_obj.cpp:111 (4)
//         00451716     MOV        AL,byte ptr [ESP + param_4]
//                              m_mi_obj.cpp:112 (4)
//         0045171a     MOV        this,byte ptr [ESP + param_3]
//                              m_mi_obj.cpp:113 (13)
//         0045171e     MOV        DL,byte ptr [ESP + param_2]
//         00451722     ADD        ESP,0x20
//         00451725     MOV        byte ptr [ESI + 0x149],AL
//                              m_mi_obj.cpp:114 (10)
//         0045172b     MOV        AL,byte ptr [ESP + param_1]
//         0045172f     MOV        byte ptr [ESI + 0x14a],this
//                              m_mi_obj.cpp:115 (22)
//         00451735     MOV        this,byte ptr [ESP + local_2]
//         00451739     MOV        byte ptr [ESI + 0x14b],DL
//         0045173f     MOV        byte ptr [ESI + 0x14c],AL
//         00451745     MOV        byte ptr [ESI + 0x148],this
//                              m_mi_obj.cpp:118 (11)
//         0045174b     POP        EDI
//         0045174c     MOV        EAX,0x1
//         00451751     POP        ESI
//         00451752     POP        this
//         00451753     RET        0x10
//         00451756     ??         90h
//         00451757     NOP
//         00451758     NOP
//         00451759     NOP
//         0045175a     NOP
//         0045175b     NOP
//         0045175c     NOP
//         0045175d     NOP
//         0045175e     NOP
//         0045175f     NOP
    return 0;
}

int RGE_Master_Missile_Object::setup(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4) {
    /* TODO: Stub */
//                              int __thiscall setup(RGE_Master_Missile_Object * this, _iobuf * para
//              int               EAX:4          <RETURN>
//              RGE_Master_Mis    ECX:4 (auto)   this
//              _iobuf *          Stack[0x4]:4   param_1                   XREF[3]:     004516d1(R), 004516e6(*), 0045172b(R)
//              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[3]:     004516c5(R), 004516eb(*), 0045171e(R)
//              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[3]:     004516cc(R), 004516f0(*), 0045171a(R)
//              short             Stack[0x10]:2  param_4                   XREF[3]:     004516c1(R), 004516f5(*), 00451716(R)
//              undefined         Stack[-0x2]:1  local_2                   XREF[2]:     004516fa(*), 00451735(R)
//              short             Stack[-0x6]:2  temp_missile_type
//                               ?setup@RGE_Master_Missile_Object@@IAEHPAU_iobuf@@PAPAVRGE_S  XREF[1]:     RGE_Master_Missile_Object:0045158b
//                               RGE_Master_Missile_Object::setup
//                              m_mi_obj.cpp:88 (1)
//         004516c0     PUSH       this
//                              m_mi_obj.cpp:95 (31)
//         004516c1     MOV        EAX,dword ptr [ESP + param_4]
//         004516c5     MOV        EDX,dword ptr [ESP + param_2]
//         004516c9     PUSH       ESI
//         004516ca     MOV        ESI,this
//         004516cc     MOV        this,dword ptr [ESP + param_3]
//         004516d0     PUSH       EDI
//         004516d1     MOV        EDI,dword ptr [ESP + param_1]
//         004516d5     PUSH       EAX
//         004516d6     PUSH       this
//         004516d7     PUSH       EDX
//         004516d8     PUSH       EDI
//         004516d9     MOV        this,ESI
//         004516db     CALL       RGE_Master_Combat_Object::setup                  int setup(RGE_Master_Combat_Object * this, _i
//                              m_mi_obj.cpp:108 (54)
//         004516e0     LEA        EAX,[ESI + 0x150]
//         004516e6     LEA        this=>param_1,[ESP + 0x10]
//         004516ea     PUSH       EAX
//         004516eb     LEA        EDX=>param_2,[ESP + 0x18]
//         004516ef     PUSH       this
//         004516f0     LEA        EAX=>param_3,[ESP + 0x20]
//         004516f4     PUSH       EDX
//         004516f5     LEA        this=>param_4,[ESP + 0x28]
//         004516f9     PUSH       EAX
//         004516fa     LEA        EDX=>local_2,[ESP + 0x1a]
//         004516fe     PUSH       this
//         004516ff     PUSH       EDX
//         00451700     PUSH       s_%hd_%hd_%hd_%hd_%hd_%f                         = "%hd %hd %hd %hd %hd %f"
//         00451705     PUSH       EDI
//         00451706     MOV        byte ptr [ESI + 0xa4],0x1
//         0045170d     MOV        byte ptr [ESI + 0x4],0x3c
//         00451711     CALL       fscanf                                           undefined fscanf()
//                              m_mi_obj.cpp:111 (4)
//         00451716     MOV        AL,byte ptr [ESP + param_4]
//                              m_mi_obj.cpp:112 (4)
//         0045171a     MOV        this,byte ptr [ESP + param_3]
//                              m_mi_obj.cpp:113 (13)
//         0045171e     MOV        DL,byte ptr [ESP + param_2]
//         00451722     ADD        ESP,0x20
//         00451725     MOV        byte ptr [ESI + 0x149],AL
//                              m_mi_obj.cpp:114 (10)
//         0045172b     MOV        AL,byte ptr [ESP + param_1]
//         0045172f     MOV        byte ptr [ESI + 0x14a],this
//                              m_mi_obj.cpp:115 (22)
//         00451735     MOV        this,byte ptr [ESP + local_2]
//         00451739     MOV        byte ptr [ESI + 0x14b],DL
//         0045173f     MOV        byte ptr [ESI + 0x14c],AL
//         00451745     MOV        byte ptr [ESI + 0x148],this
//                              m_mi_obj.cpp:118 (11)
//         0045174b     POP        EDI
//         0045174c     MOV        EAX,0x1
//         00451751     POP        ESI
//         00451752     POP        this
//         00451753     RET        0x10
//         00451756     ??         90h
//         00451757     NOP
//         00451758     NOP
//         00451759     NOP
//         0045175a     NOP
//         0045175b     NOP
//         0045175c     NOP
//         0045175d     NOP
//         0045175e     NOP
//         0045175f     NOP
    return 0;
}

RGE_Master_Missile_Object::~RGE_Master_Missile_Object() {
    /* TODO: Stub */
//                              void __thiscall ~RGE_Master_Missile_Object(RGE_Master_Missile_Object
//              void              <VOID>         <RETURN>
//              RGE_Master_Mis    ECX:4 (auto)   this
//                               ??1RGE_Master_Missile_Object@@UAE@XZ                         XREF[1]:     `vector_deleting_destructor':00451
//                               RGE_Master_Missile_Object::~RGE_Master_Missile_Object
//                              m_mi_obj.cpp:123 (11)
//         00451760     MOV        dword ptr [this->_padding_],RGE_Master_Missile   = 004514a0
//         00451766     JMP        RGE_Master_Combat_Object::~RGE_Master_Combat_O   void ~RGE_Master_Combat_Object(RGE_Master_Com
//                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
//         0045176b     ??         90h
//         0045176c     NOP
//         0045176d     NOP
//         0045176e     NOP
//         0045176f     NOP
}

RGE_Static_Object* RGE_Master_Missile_Object::make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4) {
    /* TODO: Stub */
//                              RGE_Static_Object * __thiscall make_new_obj(RGE_Master_Missile_Objec
//              RGE_Static_Obj    EAX:4          <RETURN>
//              RGE_Master_Mis    ECX:4 (auto)   this
//              RGE_Player *      Stack[0x4]:4   param_1                   XREF[2]:     00451787(R), 004517e5(W)
//              float             Stack[0x8]:4   param_2                   XREF[2]:     004517b5(R), 00451800(R)
//              float             Stack[0xc]:4   param_3                   XREF[2]:     004517ae(R), 004517f9(R)
//              float             Stack[0x10]:4  param_4                   XREF[2]:     004517aa(R), 004517f5(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004517eb(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     0045180f(R), 00451823(R)
//                               ?make_new_obj@RGE_Master_Missile_Object@@UAEPAVRGE_Static_O  XREF[1]:     00570578(*)
//                               RGE_Master_Missile_Object::make_new_obj
//                              m_mi_obj.cpp:129 (23)
//         00451770     MOV        EAX,FS:[0x0]
//         00451776     PUSH       -0x1
//         00451778     PUSH       FUN_0055d95b
//         0045177d     PUSH       EAX
//         0045177e     MOV        dword ptr FS:[0x0],ESP
//         00451785     PUSH       EBX
//         00451786     PUSH       ESI
//                              m_mi_obj.cpp:132 (17)
//         00451787     MOV        EBX,dword ptr [ESP + param_1]
//         0045178b     PUSH       EDI
//         0045178c     MOV        EDI,this
//         0045178e     MOV        AL,byte ptr [EDI + 0xa4]
//         00451794     TEST       AL,AL
//         00451796     JZ         LAB_004517d8
//                              m_mi_obj.cpp:134 (14)
//         00451798     MOV        AL,byte ptr [EDI + 0x4]
//         0045179b     MOV        this,dword ptr [EBX + 0x3c]
//         0045179e     PUSH       EAX
//         0045179f     CALL       RGE_Game_World::recycle_object_in_to_game        RGE_Static_Object * recycle_object_in_to_game
//         004517a4     MOV        ESI,EAX
//                              m_mi_obj.cpp:135 (4)
//         004517a6     TEST       ESI,ESI
//         004517a8     JZ         LAB_004517d8
//                              m_mi_obj.cpp:137 (24)
//         004517aa     MOV        EAX,dword ptr [ESP + param_4]
//         004517ae     MOV        this,dword ptr [ESP + param_3]
//         004517b2     MOV        EDX,dword ptr [ESI]
//         004517b4     PUSH       EAX
//         004517b5     MOV        EAX,dword ptr [ESP + param_2]
//         004517b9     PUSH       this
//         004517ba     PUSH       EAX
//         004517bb     PUSH       EBX
//         004517bc     PUSH       EDI
//         004517bd     MOV        this,ESI
//         004517bf     CALL       dword ptr [EDX + 0x4]
//                              m_mi_obj.cpp:138 (2)
//         004517c2     MOV        EAX,ESI
//                              m_mi_obj.cpp:143 (20)
//         004517c4     MOV        this,dword ptr [ESP + 0xc]
//         004517c8     MOV        dword ptr FS:[0x0],this
//         004517cf     POP        EDI
//         004517d0     POP        ESI
//         004517d1     POP        EBX
//         004517d2     ADD        ESP,0xc
//         004517d5     RET        0x10
//                               LAB_004517d8                                                 XREF[2]:     00451796(j), 004517a8(j)
//                              m_mi_obj.cpp:142 (55)
//         004517d8     PUSH       0x1c8
//         004517dd     CALL       operator_new                                     void * operator_new(uint param_1)
//         004517e2     ADD        ESP,0x4
//         004517e5     MOV        dword ptr [ESP + param_1],EAX
//         004517e9     TEST       EAX,EAX
//         004517eb     MOV        dword ptr [ESP + local_4],0x0
//         004517f3     JZ         LAB_00451823
//         004517f5     MOV        this,dword ptr [ESP + param_4]
//         004517f9     MOV        EDX,dword ptr [ESP + param_3]
//         004517fd     PUSH       0x1
//         004517ff     PUSH       this
//         00451800     MOV        this,dword ptr [ESP + param_2]
//         00451804     PUSH       EDX
//         00451805     PUSH       this
//         00451806     PUSH       EBX
//         00451807     PUSH       EDI
//         00451808     MOV        this,EAX
//         0045180a     CALL       RGE_Missile_Object::RGE_Missile_Object           undefined RGE_Missile_Object(RGE_Missile_Obje
//                              m_mi_obj.cpp:143 (42)
//         0045180f     MOV        this,dword ptr [ESP + local_c]
//         00451813     MOV        dword ptr FS:[0x0],this
//         0045181a     POP        EDI
//         0045181b     POP        ESI
//         0045181c     POP        EBX
//         0045181d     ADD        ESP,0xc
//         00451820     RET        0x10
//                               LAB_00451823                                                 XREF[1]:     004517f3(j)
//         00451823     MOV        this,dword ptr [ESP + local_c]
//         00451827     POP        EDI
//         00451828     POP        ESI
//         00451829     XOR        EAX,EAX
//         0045182b     MOV        dword ptr FS:[0x0],this
//         00451832     POP        EBX
//         00451833     ADD        ESP,0xc
//         00451836     RET        0x10
//         00451839     ??         90h
//         0045183a     NOP
//         0045183b     NOP
//         0045183c     NOP
//         0045183d     NOP
//         0045183e     NOP
//         0045183f     NOP
    return 0;
}

void RGE_Master_Missile_Object::copy_obj(RGE_Master_Static_Object* param_1) {
    /* TODO: Stub */
//                              void __thiscall copy_obj(RGE_Master_Missile_Object * this, RGE_Maste
//              void              <VOID>         <RETURN>
//              RGE_Master_Mis    ECX:4 (auto)   this
//              RGE_Master_Sta    Stack[0x4]:4   param_1                   XREF[1]:     004518b2(R)
//                               ?copy_obj@RGE_Master_Missile_Object@@UAEXPAVRGE_Master_Stat  XREF[1]:     00570564(*)
//                               RGE_Master_Missile_Object::copy_obj
//                              m_mi_obj.cpp:155 (2)
//         004518b0     PUSH       ESI
//         004518b1     PUSH       EDI
//                              m_mi_obj.cpp:158 (12)
//         004518b2     MOV        EDI,dword ptr [ESP + param_1]
//         004518b6     MOV        ESI,this
//         004518b8     PUSH       EDI
//         004518b9     CALL       RGE_Master_Combat_Object::copy_obj               void copy_obj(RGE_Master_Combat_Object * this
//                              m_mi_obj.cpp:160 (12)
//         004518be     MOV        AL,byte ptr [EDI + 0x148]
//         004518c4     MOV        byte ptr [ESI + 0x148],AL
//                              m_mi_obj.cpp:161 (12)
//         004518ca     MOV        this,byte ptr [EDI + 0x149]
//         004518d0     MOV        byte ptr [ESI + 0x149],this
//                              m_mi_obj.cpp:162 (12)
//         004518d6     MOV        DL,byte ptr [EDI + 0x14a]
//         004518dc     MOV        byte ptr [ESI + 0x14a],DL
//                              m_mi_obj.cpp:163 (12)
//         004518e2     MOV        AL,byte ptr [EDI + 0x14b]
//         004518e8     MOV        byte ptr [ESI + 0x14b],AL
//                              m_mi_obj.cpp:164 (12)
//         004518ee     MOV        this,byte ptr [EDI + 0x14c]
//         004518f4     MOV        byte ptr [ESI + 0x14c],this
//                              m_mi_obj.cpp:165 (12)
//         004518fa     MOV        EDX,dword ptr [EDI + 0x150]
//         00451900     MOV        dword ptr [ESI + 0x150],EDX
//                              m_mi_obj.cpp:166 (5)
//         00451906     POP        EDI
//         00451907     POP        ESI
//         00451908     RET        0x4
//         0045190b     ??         90h
//         0045190c     NOP
//         0045190d     NOP
//         0045190e     NOP
//         0045190f     NOP
    return;
}

void RGE_Master_Missile_Object::modify(float param_1, uchar param_2) {
    /* TODO: Stub */
//                              void __thiscall modify(RGE_Master_Missile_Object * this, float param
//              void              <VOID>         <RETURN>
//              RGE_Master_Mis    ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1                   XREF[2]:     0045191d(R), 0045192c(R)
//              uchar             Stack[0x8]:1   param_2                   XREF[1]:     00451911(R)
//                               ?modify@RGE_Master_Missile_Object@@UAEXME@Z                  XREF[1]:     00570568(*)
//                               RGE_Master_Missile_Object::modify
//                              m_mi_obj.cpp:170 (1)
//         00451910     PUSH       EBX
//                              m_mi_obj.cpp:171 (12)
//         00451911     MOV        EBX,dword ptr [ESP + param_2]
//         00451915     PUSH       ESI
//         00451916     CMP        BL,0x13
//         00451919     MOV        ESI,this
//         0045191b     JNZ        LAB_0045192c
//                              m_mi_obj.cpp:174 (15)
//         0045191d     FLD        float ptr [ESP + param_1]
//         00451921     CALL       __ftol                                           undefined __ftol()
//         00451926     MOV        byte ptr [ESI + 0x149],AL
//                               LAB_0045192c                                                 XREF[1]:     0045191b(j)
//                              m_mi_obj.cpp:178 (13)
//         0045192c     MOV        EAX,dword ptr [ESP + param_1]
//         00451930     PUSH       EBX
//         00451931     PUSH       EAX
//         00451932     MOV        this,ESI
//         00451934     CALL       RGE_Master_Combat_Object::modify                 void modify(RGE_Master_Combat_Object * this,
//                              m_mi_obj.cpp:179 (5)
//         00451939     POP        ESI
//         0045193a     POP        EBX
//         0045193b     RET        0x8
//         0045193e     ??         90h
//         0045193f     NOP
    return;
}

void RGE_Master_Missile_Object::modify_delta(float param_1, uchar param_2) {
    /* TODO: Stub */
//                              void __thiscall modify_delta(RGE_Master_Missile_Object * this, float
//              void              <VOID>         <RETURN>
//              RGE_Master_Mis    ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1                   XREF[2]:     0045194d(R), 0045195c(R)
//              uchar             Stack[0x8]:1   param_2                   XREF[1]:     00451941(R)
//                               ?modify_delta@RGE_Master_Missile_Object@@UAEXME@Z            XREF[1]:     0057056c(*)
//                               RGE_Master_Missile_Object::modify_delta
//                              m_mi_obj.cpp:183 (1)
//         00451940     PUSH       EBX
//                              m_mi_obj.cpp:184 (12)
//         00451941     MOV        EBX,dword ptr [ESP + param_2]
//         00451945     PUSH       ESI
//         00451946     CMP        BL,0x13
//         00451949     MOV        ESI,this
//         0045194b     JNZ        LAB_0045195c
//                              m_mi_obj.cpp:187 (15)
//         0045194d     FLD        float ptr [ESP + param_1]
//         00451951     CALL       __ftol                                           undefined __ftol()
//         00451956     MOV        byte ptr [ESI + 0x149],AL
//                               LAB_0045195c                                                 XREF[1]:     0045194b(j)
//                              m_mi_obj.cpp:191 (13)
//         0045195c     MOV        EAX,dword ptr [ESP + param_1]
//         00451960     PUSH       EBX
//         00451961     PUSH       EAX
//         00451962     MOV        this,ESI
//         00451964     CALL       RGE_Master_Combat_Object::modify_delta           void modify_delta(RGE_Master_Combat_Object *
//                              m_mi_obj.cpp:192 (5)
//         00451969     POP        ESI
//         0045196a     POP        EBX
//         0045196b     RET        0x8
//         0045196e     ??         90h
//         0045196f     NOP
    return;
}

void RGE_Master_Missile_Object::modify_percent(float param_1, uchar param_2) {
    /* TODO: Stub */
//                              void __thiscall modify_percent(RGE_Master_Missile_Object * this, flo
//              void              <VOID>         <RETURN>
//              RGE_Master_Mis    ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1                   XREF[2]:     0045197d(R), 0045198c(R)
//              uchar             Stack[0x8]:1   param_2                   XREF[1]:     00451971(R)
//                               ?modify_percent@RGE_Master_Missile_Object@@UAEXME@Z          XREF[1]:     00570570(*)
//                               RGE_Master_Missile_Object::modify_percent
//                              m_mi_obj.cpp:196 (1)
//         00451970     PUSH       EBX
//                              m_mi_obj.cpp:197 (12)
//         00451971     MOV        EBX,dword ptr [ESP + param_2]
//         00451975     PUSH       ESI
//         00451976     CMP        BL,0x13
//         00451979     MOV        ESI,this
//         0045197b     JNZ        LAB_0045198c
//                              m_mi_obj.cpp:200 (15)
//         0045197d     FLD        float ptr [ESP + param_1]
//         00451981     CALL       __ftol                                           undefined __ftol()
//         00451986     MOV        byte ptr [ESI + 0x149],AL
//                               LAB_0045198c                                                 XREF[1]:     0045197b(j)
//                              m_mi_obj.cpp:204 (13)
//         0045198c     MOV        EAX,dword ptr [ESP + param_1]
//         00451990     PUSH       EBX
//         00451991     PUSH       EAX
//         00451992     MOV        this,ESI
//         00451994     CALL       RGE_Master_Combat_Object::modify_percent         void modify_percent(RGE_Master_Combat_Object
//                              m_mi_obj.cpp:205 (5)
//         00451999     POP        ESI
//         0045199a     POP        EBX
//         0045199b     RET        0x8
//         0045199e     ??         90h
//         0045199f     NOP
    return;
}

void RGE_Master_Missile_Object::save(int param_1) {
    /* TODO: Stub */
//                              void __thiscall save(RGE_Master_Missile_Object * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_Master_Mis    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004519a2(R)
//                               ?save@RGE_Master_Missile_Object@@UAEXH@Z                     XREF[1]:     00570574(*)
//                               RGE_Master_Missile_Object::save
//                              m_mi_obj.cpp:210 (2)
//         004519a0     PUSH       ESI
//         004519a1     PUSH       EDI
//                              m_mi_obj.cpp:211 (12)
//         004519a2     MOV        EDI,dword ptr [ESP + param_1]
//         004519a6     MOV        ESI,this
//         004519a8     PUSH       EDI
//         004519a9     CALL       RGE_Master_Combat_Object::save                   void save(RGE_Master_Combat_Object * this, in
//                              m_mi_obj.cpp:213 (18)
//         004519ae     LEA        EAX,[ESI + 0x148]
//         004519b4     PUSH       0x1
//         004519b6     PUSH       EAX
//         004519b7     PUSH       EDI
//         004519b8     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004519bd     ADD        ESP,0xc
//                              m_mi_obj.cpp:214 (18)
//         004519c0     LEA        this,[ESI + 0x149]
//         004519c6     PUSH       0x1
//         004519c8     PUSH       this
//         004519c9     PUSH       EDI
//         004519ca     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004519cf     ADD        ESP,0xc
//                              m_mi_obj.cpp:215 (18)
//         004519d2     LEA        EDX,[ESI + 0x14a]
//         004519d8     PUSH       0x1
//         004519da     PUSH       EDX
//         004519db     PUSH       EDI
//         004519dc     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004519e1     ADD        ESP,0xc
//                              m_mi_obj.cpp:216 (18)
//         004519e4     LEA        EAX,[ESI + 0x14b]
//         004519ea     PUSH       0x1
//         004519ec     PUSH       EAX
//         004519ed     PUSH       EDI
//         004519ee     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004519f3     ADD        ESP,0xc
//                              m_mi_obj.cpp:217 (18)
//         004519f6     LEA        this,[ESI + 0x14c]
//         004519fc     PUSH       0x1
//         004519fe     PUSH       this
//         004519ff     PUSH       EDI
//         00451a00     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00451a05     ADD        ESP,0xc
//                              m_mi_obj.cpp:218 (18)
//         00451a08     ADD        ESI,0x150
//         00451a0e     PUSH       0x4
//         00451a10     PUSH       ESI
//         00451a11     PUSH       EDI
//         00451a12     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00451a17     ADD        ESP,0xc
//                              m_mi_obj.cpp:219 (5)
//         00451a1a     POP        EDI
//         00451a1b     POP        ESI
//         00451a1c     RET        0x4
//         00451a1f     ??         90h
    return;
}

RGE_Master_Static_Object* RGE_Master_Missile_Object::make_new_master() {
    /* TODO: Stub */
// <NO ASSEMBLY FOUND>
    return 0;
}

