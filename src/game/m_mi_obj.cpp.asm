#include "common.h"
#include "m_mi_obj.h"

int RGE_Master_Missile_Object::setup(RGE_Master_Missile_Object* param_1) {
    /* TODO: Stub */
    //                              int __thiscall setup(RGE_Master_Missile_Object * this, RGE_Master_Mi
    //              int               EAX:4          <RETURN>
    //              RGE_Master_Mis    ECX:4 (auto)   this
    //              RGE_Master_Mis    Stack[0x4]:4   param_1                   XREF[1]:     004515b2(R)  
    //                               ?setup@RGE_Master_Missile_Object@@IAEHPAV1@@Z                XREF[1]:     RGE_Master_Missile_Object:00451483
    //                               RGE_Master_Missile_Object::setup
    //                              m_mi_obj.cpp:50 (2)
    //         004515b0     PUSH       ESI
    //         004515b1     PUSH       EDI
    //                              m_mi_obj.cpp:51 (12)
    //         004515b2     MOV        EDI,dword ptr [ESP + param_1]
    //         004515b6     MOV        ESI,this
    //         004515b8     PUSH       EDI
    //         004515b9     CALL       RGE_Master_Combat_Object::setup                  int setup(RGE_Master_Combat_Object * this, RG
    //                              m_mi_obj.cpp:53 (4)
    //         004515be     MOV        byte ptr [ESI + 0x4],0x3c
    //                              m_mi_obj.cpp:56 (12)
    //         004515c2     MOV        AL,byte ptr [EDI + 0x148]
    //         004515c8     MOV        byte ptr [ESI + 0x148],AL
    //                              m_mi_obj.cpp:57 (12)
    //         004515ce     MOV        this,byte ptr [EDI + 0x149]
    //         004515d4     MOV        byte ptr [ESI + 0x149],this
    //                              m_mi_obj.cpp:58 (12)
    //         004515da     MOV        DL,byte ptr [EDI + 0x14a]
    //         004515e0     MOV        byte ptr [ESI + 0x14a],DL
    //                              m_mi_obj.cpp:59 (12)
    //         004515e6     MOV        AL,byte ptr [EDI + 0x14b]
    //         004515ec     MOV        byte ptr [ESI + 0x14b],AL
    //                              m_mi_obj.cpp:60 (12)
    //         004515f2     MOV        this,byte ptr [EDI + 0x14c]
    //         004515f8     MOV        byte ptr [ESI + 0x14c],this
    //                              m_mi_obj.cpp:61 (12)
    //         004515fe     MOV        EDX,dword ptr [EDI + 0x150]
    //         00451604     MOV        dword ptr [ESI + 0x150],EDX
    //                              m_mi_obj.cpp:64 (10)
    //         0045160a     POP        EDI
    //         0045160b     MOV        EAX,0x1
    //         00451610     POP        ESI
    //         00451611     RET        0x4
    //         00451614     ??         90h
    //         00451615     NOP
    //         00451616     NOP
    //         00451617     NOP
    //         00451618     NOP
    //         00451619     NOP
    //         0045161a     NOP
    //         0045161b     NOP
    //         0045161c     NOP
    //         0045161d     NOP
    //         0045161e     NOP
    //         0045161f     NOP
    //                              * protected: int __thiscall RGE_Master_Missile_Object::setup(int,class RGE_Sprite * *,class RGE_Soun... *
    //                              int __thiscall setup(RGE_Master_Missile_Object * this, int param_1, 
    //              int               EAX:4          <RETURN>
    //              RGE_Master_Mis    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0045162c(R)  
    //              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     00451628(R)  
    //              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[1]:     00451620(R)  
    //                               ?setup@RGE_Master_Missile_Object@@IAEHHPAPAVRGE_Sprite@@PAP  XREF[1]:     RGE_Master_Missile_Object:00451511
    //                               RGE_Master_Missile_Object::setup
    //                              m_mi_obj.cpp:69 (26)
    //         00451620     MOV        EAX,dword ptr [ESP + param_3]
    //         00451624     PUSH       ESI
    //         00451625     MOV        ESI,this
    //         00451627     PUSH       EDI
    //         00451628     MOV        this,dword ptr [ESP + param_2]
    //         0045162c     MOV        EDI,dword ptr [ESP + param_1]
    //         00451630     PUSH       EAX
    //         00451631     PUSH       this
    //         00451632     PUSH       EDI
    //         00451633     MOV        this,ESI
    //         00451635     CALL       RGE_Master_Combat_Object::setup                  int setup(RGE_Master_Combat_Object * this, in
    //                              m_mi_obj.cpp:75 (22)
    //         0045163a     LEA        EDX,[ESI + 0x148]
    //         00451640     PUSH       0x1
    //         00451642     PUSH       EDX
    //         00451643     PUSH       EDI
    //         00451644     MOV        byte ptr [ESI + 0x4],0x3c
    //         00451648     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0045164d     ADD        ESP,0xc
    //                              m_mi_obj.cpp:76 (18)
    //         00451650     LEA        EAX,[ESI + 0x149]
    //         00451656     PUSH       0x1
    //         00451658     PUSH       EAX
    //         00451659     PUSH       EDI
    //         0045165a     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0045165f     ADD        ESP,0xc
    //                              m_mi_obj.cpp:77 (18)
    //         00451662     LEA        this,[ESI + 0x14a]
    //         00451668     PUSH       0x1
    //         0045166a     PUSH       this
    //         0045166b     PUSH       EDI
    //         0045166c     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00451671     ADD        ESP,0xc
    //                              m_mi_obj.cpp:78 (18)
    //         00451674     LEA        EDX,[ESI + 0x14b]
    //         0045167a     PUSH       0x1
    //         0045167c     PUSH       EDX
    //         0045167d     PUSH       EDI
    //         0045167e     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00451683     ADD        ESP,0xc
    //                              m_mi_obj.cpp:79 (18)
    //         00451686     LEA        EAX,[ESI + 0x14c]
    //         0045168c     PUSH       0x1
    //         0045168e     PUSH       EAX
    //         0045168f     PUSH       EDI
    //         00451690     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00451695     ADD        ESP,0xc
    //                              m_mi_obj.cpp:80 (18)
    //         00451698     ADD        ESI,0x150
    //         0045169e     PUSH       0x4
    //         004516a0     PUSH       ESI
    //         004516a1     PUSH       EDI
    //         004516a2     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004516a7     ADD        ESP,0xc
    //                              m_mi_obj.cpp:82 (5)
    //         004516aa     MOV        EAX,0x1
    //                              m_mi_obj.cpp:83 (5)
    //         004516af     POP        EDI
    //         004516b0     POP        ESI
    //         004516b1     RET        0xc
    //         004516b4     ??         90h
    //         004516b5     NOP
    //         004516b6     NOP
    //         004516b7     NOP
    //         004516b8     NOP
    //         004516b9     NOP
    //         004516ba     NOP
    //         004516bb     NOP
    //         004516bc     NOP
    //         004516bd     NOP
    //         004516be     NOP
    //         004516bf     NOP
    //                              * protected: int __thiscall RGE_Master_Missile_Object::setup(struct _iobuf *,class RGE_Sprite * *,cl... *
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
    //                              int __thiscall setup(RGE_Master_Missile_Object * this, RGE_Master_Mi
    //              int               EAX:4          <RETURN>
    //              RGE_Master_Mis    ECX:4 (auto)   this
    //              RGE_Master_Mis    Stack[0x4]:4   param_1                   XREF[1]:     004515b2(R)  
    //                               ?setup@RGE_Master_Missile_Object@@IAEHPAV1@@Z                XREF[1]:     RGE_Master_Missile_Object:00451483
    //                               RGE_Master_Missile_Object::setup
    //                              m_mi_obj.cpp:50 (2)
    //         004515b0     PUSH       ESI
    //         004515b1     PUSH       EDI
    //                              m_mi_obj.cpp:51 (12)
    //         004515b2     MOV        EDI,dword ptr [ESP + param_1]
    //         004515b6     MOV        ESI,this
    //         004515b8     PUSH       EDI
    //         004515b9     CALL       RGE_Master_Combat_Object::setup                  int setup(RGE_Master_Combat_Object * this, RG
    //                              m_mi_obj.cpp:53 (4)
    //         004515be     MOV        byte ptr [ESI + 0x4],0x3c
    //                              m_mi_obj.cpp:56 (12)
    //         004515c2     MOV        AL,byte ptr [EDI + 0x148]
    //         004515c8     MOV        byte ptr [ESI + 0x148],AL
    //                              m_mi_obj.cpp:57 (12)
    //         004515ce     MOV        this,byte ptr [EDI + 0x149]
    //         004515d4     MOV        byte ptr [ESI + 0x149],this
    //                              m_mi_obj.cpp:58 (12)
    //         004515da     MOV        DL,byte ptr [EDI + 0x14a]
    //         004515e0     MOV        byte ptr [ESI + 0x14a],DL
    //                              m_mi_obj.cpp:59 (12)
    //         004515e6     MOV        AL,byte ptr [EDI + 0x14b]
    //         004515ec     MOV        byte ptr [ESI + 0x14b],AL
    //                              m_mi_obj.cpp:60 (12)
    //         004515f2     MOV        this,byte ptr [EDI + 0x14c]
    //         004515f8     MOV        byte ptr [ESI + 0x14c],this
    //                              m_mi_obj.cpp:61 (12)
    //         004515fe     MOV        EDX,dword ptr [EDI + 0x150]
    //         00451604     MOV        dword ptr [ESI + 0x150],EDX
    //                              m_mi_obj.cpp:64 (10)
    //         0045160a     POP        EDI
    //         0045160b     MOV        EAX,0x1
    //         00451610     POP        ESI
    //         00451611     RET        0x4
    //         00451614     ??         90h
    //         00451615     NOP
    //         00451616     NOP
    //         00451617     NOP
    //         00451618     NOP
    //         00451619     NOP
    //         0045161a     NOP
    //         0045161b     NOP
    //         0045161c     NOP
    //         0045161d     NOP
    //         0045161e     NOP
    //         0045161f     NOP
    //                              * protected: int __thiscall RGE_Master_Missile_Object::setup(int,class RGE_Sprite * *,class RGE_Soun... *
    //                              int __thiscall setup(RGE_Master_Missile_Object * this, int param_1, 
    //              int               EAX:4          <RETURN>
    //              RGE_Master_Mis    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0045162c(R)  
    //              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     00451628(R)  
    //              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[1]:     00451620(R)  
    //                               ?setup@RGE_Master_Missile_Object@@IAEHHPAPAVRGE_Sprite@@PAP  XREF[1]:     RGE_Master_Missile_Object:00451511
    //                               RGE_Master_Missile_Object::setup
    //                              m_mi_obj.cpp:69 (26)
    //         00451620     MOV        EAX,dword ptr [ESP + param_3]
    //         00451624     PUSH       ESI
    //         00451625     MOV        ESI,this
    //         00451627     PUSH       EDI
    //         00451628     MOV        this,dword ptr [ESP + param_2]
    //         0045162c     MOV        EDI,dword ptr [ESP + param_1]
    //         00451630     PUSH       EAX
    //         00451631     PUSH       this
    //         00451632     PUSH       EDI
    //         00451633     MOV        this,ESI
    //         00451635     CALL       RGE_Master_Combat_Object::setup                  int setup(RGE_Master_Combat_Object * this, in
    //                              m_mi_obj.cpp:75 (22)
    //         0045163a     LEA        EDX,[ESI + 0x148]
    //         00451640     PUSH       0x1
    //         00451642     PUSH       EDX
    //         00451643     PUSH       EDI
    //         00451644     MOV        byte ptr [ESI + 0x4],0x3c
    //         00451648     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0045164d     ADD        ESP,0xc
    //                              m_mi_obj.cpp:76 (18)
    //         00451650     LEA        EAX,[ESI + 0x149]
    //         00451656     PUSH       0x1
    //         00451658     PUSH       EAX
    //         00451659     PUSH       EDI
    //         0045165a     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0045165f     ADD        ESP,0xc
    //                              m_mi_obj.cpp:77 (18)
    //         00451662     LEA        this,[ESI + 0x14a]
    //         00451668     PUSH       0x1
    //         0045166a     PUSH       this
    //         0045166b     PUSH       EDI
    //         0045166c     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00451671     ADD        ESP,0xc
    //                              m_mi_obj.cpp:78 (18)
    //         00451674     LEA        EDX,[ESI + 0x14b]
    //         0045167a     PUSH       0x1
    //         0045167c     PUSH       EDX
    //         0045167d     PUSH       EDI
    //         0045167e     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00451683     ADD        ESP,0xc
    //                              m_mi_obj.cpp:79 (18)
    //         00451686     LEA        EAX,[ESI + 0x14c]
    //         0045168c     PUSH       0x1
    //         0045168e     PUSH       EAX
    //         0045168f     PUSH       EDI
    //         00451690     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00451695     ADD        ESP,0xc
    //                              m_mi_obj.cpp:80 (18)
    //         00451698     ADD        ESI,0x150
    //         0045169e     PUSH       0x4
    //         004516a0     PUSH       ESI
    //         004516a1     PUSH       EDI
    //         004516a2     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004516a7     ADD        ESP,0xc
    //                              m_mi_obj.cpp:82 (5)
    //         004516aa     MOV        EAX,0x1
    //                              m_mi_obj.cpp:83 (5)
    //         004516af     POP        EDI
    //         004516b0     POP        ESI
    //         004516b1     RET        0xc
    //         004516b4     ??         90h
    //         004516b5     NOP
    //         004516b6     NOP
    //         004516b7     NOP
    //         004516b8     NOP
    //         004516b9     NOP
    //         004516ba     NOP
    //         004516bb     NOP
    //         004516bc     NOP
    //         004516bd     NOP
    //         004516be     NOP
    //         004516bf     NOP
    //                              * protected: int __thiscall RGE_Master_Missile_Object::setup(struct _iobuf *,class RGE_Sprite * *,cl... *
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
    //                              int __thiscall setup(RGE_Master_Missile_Object * this, RGE_Master_Mi
    //              int               EAX:4          <RETURN>
    //              RGE_Master_Mis    ECX:4 (auto)   this
    //              RGE_Master_Mis    Stack[0x4]:4   param_1                   XREF[1]:     004515b2(R)  
    //                               ?setup@RGE_Master_Missile_Object@@IAEHPAV1@@Z                XREF[1]:     RGE_Master_Missile_Object:00451483
    //                               RGE_Master_Missile_Object::setup
    //                              m_mi_obj.cpp:50 (2)
    //         004515b0     PUSH       ESI
    //         004515b1     PUSH       EDI
    //                              m_mi_obj.cpp:51 (12)
    //         004515b2     MOV        EDI,dword ptr [ESP + param_1]
    //         004515b6     MOV        ESI,this
    //         004515b8     PUSH       EDI
    //         004515b9     CALL       RGE_Master_Combat_Object::setup                  int setup(RGE_Master_Combat_Object * this, RG
    //                              m_mi_obj.cpp:53 (4)
    //         004515be     MOV        byte ptr [ESI + 0x4],0x3c
    //                              m_mi_obj.cpp:56 (12)
    //         004515c2     MOV        AL,byte ptr [EDI + 0x148]
    //         004515c8     MOV        byte ptr [ESI + 0x148],AL
    //                              m_mi_obj.cpp:57 (12)
    //         004515ce     MOV        this,byte ptr [EDI + 0x149]
    //         004515d4     MOV        byte ptr [ESI + 0x149],this
    //                              m_mi_obj.cpp:58 (12)
    //         004515da     MOV        DL,byte ptr [EDI + 0x14a]
    //         004515e0     MOV        byte ptr [ESI + 0x14a],DL
    //                              m_mi_obj.cpp:59 (12)
    //         004515e6     MOV        AL,byte ptr [EDI + 0x14b]
    //         004515ec     MOV        byte ptr [ESI + 0x14b],AL
    //                              m_mi_obj.cpp:60 (12)
    //         004515f2     MOV        this,byte ptr [EDI + 0x14c]
    //         004515f8     MOV        byte ptr [ESI + 0x14c],this
    //                              m_mi_obj.cpp:61 (12)
    //         004515fe     MOV        EDX,dword ptr [EDI + 0x150]
    //         00451604     MOV        dword ptr [ESI + 0x150],EDX
    //                              m_mi_obj.cpp:64 (10)
    //         0045160a     POP        EDI
    //         0045160b     MOV        EAX,0x1
    //         00451610     POP        ESI
    //         00451611     RET        0x4
    //         00451614     ??         90h
    //         00451615     NOP
    //         00451616     NOP
    //         00451617     NOP
    //         00451618     NOP
    //         00451619     NOP
    //         0045161a     NOP
    //         0045161b     NOP
    //         0045161c     NOP
    //         0045161d     NOP
    //         0045161e     NOP
    //         0045161f     NOP
    //                              * protected: int __thiscall RGE_Master_Missile_Object::setup(int,class RGE_Sprite * *,class RGE_Soun... *
    //                              int __thiscall setup(RGE_Master_Missile_Object * this, int param_1, 
    //              int               EAX:4          <RETURN>
    //              RGE_Master_Mis    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0045162c(R)  
    //              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     00451628(R)  
    //              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[1]:     00451620(R)  
    //                               ?setup@RGE_Master_Missile_Object@@IAEHHPAPAVRGE_Sprite@@PAP  XREF[1]:     RGE_Master_Missile_Object:00451511
    //                               RGE_Master_Missile_Object::setup
    //                              m_mi_obj.cpp:69 (26)
    //         00451620     MOV        EAX,dword ptr [ESP + param_3]
    //         00451624     PUSH       ESI
    //         00451625     MOV        ESI,this
    //         00451627     PUSH       EDI
    //         00451628     MOV        this,dword ptr [ESP + param_2]
    //         0045162c     MOV        EDI,dword ptr [ESP + param_1]
    //         00451630     PUSH       EAX
    //         00451631     PUSH       this
    //         00451632     PUSH       EDI
    //         00451633     MOV        this,ESI
    //         00451635     CALL       RGE_Master_Combat_Object::setup                  int setup(RGE_Master_Combat_Object * this, in
    //                              m_mi_obj.cpp:75 (22)
    //         0045163a     LEA        EDX,[ESI + 0x148]
    //         00451640     PUSH       0x1
    //         00451642     PUSH       EDX
    //         00451643     PUSH       EDI
    //         00451644     MOV        byte ptr [ESI + 0x4],0x3c
    //         00451648     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0045164d     ADD        ESP,0xc
    //                              m_mi_obj.cpp:76 (18)
    //         00451650     LEA        EAX,[ESI + 0x149]
    //         00451656     PUSH       0x1
    //         00451658     PUSH       EAX
    //         00451659     PUSH       EDI
    //         0045165a     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0045165f     ADD        ESP,0xc
    //                              m_mi_obj.cpp:77 (18)
    //         00451662     LEA        this,[ESI + 0x14a]
    //         00451668     PUSH       0x1
    //         0045166a     PUSH       this
    //         0045166b     PUSH       EDI
    //         0045166c     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00451671     ADD        ESP,0xc
    //                              m_mi_obj.cpp:78 (18)
    //         00451674     LEA        EDX,[ESI + 0x14b]
    //         0045167a     PUSH       0x1
    //         0045167c     PUSH       EDX
    //         0045167d     PUSH       EDI
    //         0045167e     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00451683     ADD        ESP,0xc
    //                              m_mi_obj.cpp:79 (18)
    //         00451686     LEA        EAX,[ESI + 0x14c]
    //         0045168c     PUSH       0x1
    //         0045168e     PUSH       EAX
    //         0045168f     PUSH       EDI
    //         00451690     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00451695     ADD        ESP,0xc
    //                              m_mi_obj.cpp:80 (18)
    //         00451698     ADD        ESI,0x150
    //         0045169e     PUSH       0x4
    //         004516a0     PUSH       ESI
    //         004516a1     PUSH       EDI
    //         004516a2     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004516a7     ADD        ESP,0xc
    //                              m_mi_obj.cpp:82 (5)
    //         004516aa     MOV        EAX,0x1
    //                              m_mi_obj.cpp:83 (5)
    //         004516af     POP        EDI
    //         004516b0     POP        ESI
    //         004516b1     RET        0xc
    //         004516b4     ??         90h
    //         004516b5     NOP
    //         004516b6     NOP
    //         004516b7     NOP
    //         004516b8     NOP
    //         004516b9     NOP
    //         004516ba     NOP
    //         004516bb     NOP
    //         004516bc     NOP
    //         004516bd     NOP
    //         004516be     NOP
    //         004516bf     NOP
    //                              * protected: int __thiscall RGE_Master_Missile_Object::setup(struct _iobuf *,class RGE_Sprite * *,cl... *
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
    //                              * public: virtual class RGE_Static_Object * __thiscall RGE_Master_Missile_Object::make_new_obj(class... *
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
    //                              * public: virtual class RGE_Master_Static_Object * __thiscall RGE_Master_Missile_Object::make_new_ma... *
    //                              RGE_Master_Static_Object * __thiscall make_new_master(RGE_Master_Mis
    //              RGE_Master_Sta    EAX:4          <RETURN>
    //              RGE_Master_Mis    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0045186c(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     00451880(R), 00451890(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00451866(W)  
    //                               ?make_new_master@RGE_Master_Missile_Object@@UAEPAVRGE_Maste  XREF[1]:     0057057c(*)  
    //                               RGE_Master_Missile_Object::make_new_master
    //                              m_mi_obj.cpp:148 (25)
    //         00451840     PUSH       -0x1
    //         00451842     PUSH       FUN_0055d97b
    //         00451847     MOV        EAX,FS:[0x0]
    //         0045184d     PUSH       EAX
    //         0045184e     MOV        dword ptr FS:[0x0],ESP
    //         00451855     PUSH       this
    //         00451856     PUSH       ESI
    //         00451857     MOV        ESI,this
    //                              m_mi_obj.cpp:149 (39)
    //         00451859     PUSH       0x154
    //         0045185e     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00451863     ADD        ESP,0x4
    //         00451866     MOV        dword ptr [ESP + local_10],EAX
    //         0045186a     TEST       EAX,EAX
    //         0045186c     MOV        dword ptr [ESP + local_4],0x0
    //         00451874     JZ         LAB_00451890
    //         00451876     PUSH       0x1
    //         00451878     PUSH       ESI
    //         00451879     MOV        this,EAX
    //         0045187b     CALL       RGE_Master_Missile_Object::RGE_Master_Missile_   undefined RGE_Master_Missile_Object(RGE_Maste
    //                              m_mi_obj.cpp:150 (34)
    //         00451880     MOV        this,dword ptr [ESP + local_c]
    //         00451884     MOV        dword ptr FS:[0x0],this
    //         0045188b     POP        ESI
    //         0045188c     ADD        ESP,0x10
    //         0045188f     RET
    //                               LAB_00451890                                                 XREF[1]:     00451874(j)  
    //         00451890     MOV        this,dword ptr [ESP + local_c]
    //         00451894     XOR        EAX,EAX
    //         00451896     MOV        dword ptr FS:[0x0],this
    //         0045189d     POP        ESI
    //         0045189e     ADD        ESP,0x10
    //         004518a1     RET
    //         004518a2     ??         90h
    //         004518a3     NOP
    //         004518a4     NOP
    //         004518a5     NOP
    //         004518a6     NOP
    //         004518a7     NOP
    //         004518a8     NOP
    //         004518a9     NOP
    //         004518aa     NOP
    //         004518ab     NOP
    //         004518ac     NOP
    //         004518ad     NOP
    //         004518ae     NOP
    //         004518af     NOP
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
    //                              * public: __thiscall RGE_Master_Moving_Object::RGE_Master_Moving_Object(class RGE_Master_Moving_Obje... *
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
    //         00451a7d     ??         90h
    //         00451a7e     NOP
    //         00451a7f     NOP
    //                              * public: virtual void * __thiscall RGE_Master_Moving_Object::`vector deleting destructor'(unsigned ... *
    //                              void * __thiscall `vector_deleting_destructor'(RGE_Master_Moving_Obj
    //              void *            EAX:4          <RETURN>
    //              RGE_Master_Mov    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00451a88(R)  
    //                               ??_GRGE_Master_Moving_Object@@UAEPAXI@Z                      XREF[1]:     005705a0(*)  
    //                               ??_ERGE_Master_Moving_Object@@UAEPAXI@Z
    //                               RGE_Master_Moving_Object::`vector_deleting_destructor'
    //         00451a80     PUSH       ESI
    //         00451a81     MOV        ESI,this
    //         00451a83     CALL       RGE_Master_Moving_Object::~RGE_Master_Moving_O   void ~RGE_Master_Moving_Object(RGE_Master_Mov
    //         00451a88     TEST       byte ptr [ESP + param_1],0x1
    //         00451a8d     JZ         LAB_00451a98
    //         00451a8f     PUSH       ESI
    //         00451a90     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00451a95     ADD        ESP,0x4
    //                               LAB_00451a98                                                 XREF[1]:     00451a8d(j)  
    //         00451a98     MOV        EAX,ESI
    //         00451a9a     POP        ESI
    //         00451a9b     RET        0x4
    //         00451a9e     ??         90h
    //         00451a9f     NOP
    //                              * public: __thiscall RGE_Master_Moving_Object::RGE_Master_Moving_Object(int,class RGE_Sprite * *,cla... *
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
    //         00451b0d     ??         90h
    //         00451b0e     NOP
    //         00451b0f     NOP
    //                              * public: __thiscall RGE_Master_Moving_Object::RGE_Master_Moving_Object(struct _iobuf *,class RGE_Sp... *
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
    //         00451b87     ??         90h
    //         00451b88     NOP
    //         00451b89     NOP
    //         00451b8a     NOP
    //         00451b8b     NOP
    //         00451b8c     NOP
    //         00451b8d     NOP
    //         00451b8e     NOP
    //         00451b8f     NOP
    return;
}

RGE_Master_Missile_Object::RGE_Master_Missile_Object(RGE_Master_Missile_Object* param_1, int param_2) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
}

RGE_Master_Missile_Object::RGE_Master_Missile_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
}

RGE_Master_Missile_Object::RGE_Master_Missile_Object(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
}

RGE_Static_Object* RGE_Master_Missile_Object::make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

RGE_Master_Static_Object* RGE_Master_Missile_Object::make_new_master() {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

