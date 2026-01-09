#include "common.h"
#include "m_dg_obj.h"

RGE_Master_Doppleganger_Object::~RGE_Master_Doppleganger_Object() {
    /* TODO: Stub */
    //                              void __thiscall ~RGE_Master_Doppleganger_Object(RGE_Master_Dopplegan
    //              void              <VOID>         <RETURN>
    //              RGE_Master_Dop    ECX:4 (auto)   this
    //                               ??1RGE_Master_Doppleganger_Object@@UAE@XZ                    XREF[1]:     `scalar_deleting_destructor':00451
    //                               RGE_Master_Doppleganger_Object::~RGE_Master_Doppleganger_Ob
    //                              m_dg_obj.cpp:88 (11)
    //         004512c0     MOV        dword ptr [this->field0_0x0],RGE_Master_Dopple   = 00451120
    //         004512c6     JMP        RGE_Master_Animated_Object::~RGE_Master_Animat   void ~RGE_Master_Animated_Object(RGE_Master_A
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
    //         004512cb     ??         90h
    //         004512cc     NOP
    //         004512cd     NOP
    //         004512ce     NOP
    //         004512cf     NOP
    //                              * public: virtual class RGE_Static_Object * __thiscall RGE_Master_Doppleganger_Object::make_new_obj(... *
    //                              RGE_Static_Object * __thiscall make_new_obj(RGE_Master_Doppleganger_
    //              RGE_Static_Obj    EAX:4          <RETURN>
    //              RGE_Master_Dop    ECX:4 (auto)   this
    //              RGE_Player *      Stack[0x4]:4   param_1                   XREF[2]:     004512e7(R), 0045134d(W)  
    //              float             Stack[0x8]:4   param_2                   XREF[2]:     0045131a(R), 0045136d(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[2]:     00451315(R), 00451366(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[2]:     0045130e(R), 00451361(R)  
    //              RGE_Static_Obj    Stack[0x14]:4  param_5                   XREF[2]:     0045130a(R), 0045135d(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00451353(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     0045137c(R), 00451390(R)  
    //                               ?make_new_obj@RGE_Master_Doppleganger_Object@@UAEPAVRGE_Sta  XREF[1]:     00570558(*)  
    //                               RGE_Master_Doppleganger_Object::make_new_obj
    //                              m_dg_obj.cpp:94 (23)
    //         004512d0     MOV        EAX,FS:[0x0]
    //         004512d6     PUSH       -0x1
    //         004512d8     PUSH       FUN_0055d8bb
    //         004512dd     PUSH       EAX
    //         004512de     MOV        dword ptr FS:[0x0],ESP
    //         004512e5     PUSH       EBX
    //         004512e6     PUSH       ESI
    //                              m_dg_obj.cpp:97 (17)
    //         004512e7     MOV        EBX,dword ptr [ESP + param_1]
    //         004512eb     PUSH       EDI
    //         004512ec     MOV        EDI,this
    //         004512ee     MOV        AL,byte ptr [EDI + 0xa4]
    //         004512f4     TEST       AL,AL
    //         004512f6     JZ         LAB_00451340
    //                              m_dg_obj.cpp:99 (14)
    //         004512f8     MOV        AL,byte ptr [EDI + 0x4]
    //         004512fb     MOV        this,dword ptr [EBX + 0x3c]
    //         004512fe     PUSH       EAX
    //         004512ff     CALL       RGE_Game_World::recycle_object_in_to_game        RGE_Static_Object * recycle_object_in_to_game
    //         00451304     MOV        ESI,EAX
    //                              m_dg_obj.cpp:100 (4)
    //         00451306     TEST       ESI,ESI
    //         00451308     JZ         LAB_00451340
    //                              m_dg_obj.cpp:102 (32)
    //         0045130a     MOV        EAX,dword ptr [ESP + param_5]
    //         0045130e     MOV        this,dword ptr [ESP + param_4]
    //         00451312     MOV        EDX,dword ptr [ESI]
    //         00451314     PUSH       EAX
    //         00451315     MOV        EAX,dword ptr [ESP + param_3]
    //         00451319     PUSH       this
    //         0045131a     MOV        this,dword ptr [ESP + param_2]
    //         0045131e     PUSH       EAX
    //         0045131f     PUSH       this
    //         00451320     PUSH       EBX
    //         00451321     PUSH       EDI
    //         00451322     MOV        this,ESI
    //         00451324     CALL       dword ptr [EDX + 0x1ec]
    //                              m_dg_obj.cpp:103 (2)
    //         0045132a     MOV        EAX,ESI
    //                              m_dg_obj.cpp:108 (20)
    //         0045132c     MOV        this,dword ptr [ESP + 0xc]
    //         00451330     MOV        dword ptr FS:[0x0],this
    //         00451337     POP        EDI
    //         00451338     POP        ESI
    //         00451339     POP        EBX
    //         0045133a     ADD        ESP,0xc
    //         0045133d     RET        0x14
    //                               LAB_00451340                                                 XREF[2]:     004512f6(j), 00451308(j)  
    //                              m_dg_obj.cpp:107 (60)
    //         00451340     PUSH       0xb0
    //         00451345     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0045134a     ADD        ESP,0x4
    //         0045134d     MOV        dword ptr [ESP + param_1],EAX
    //         00451351     TEST       EAX,EAX
    //         00451353     MOV        dword ptr [ESP + local_4],0x0
    //         0045135b     JZ         LAB_00451390
    //         0045135d     MOV        EDX,dword ptr [ESP + param_5]
    //         00451361     MOV        this,dword ptr [ESP + param_4]
    //         00451365     PUSH       EDX
    //         00451366     MOV        EDX,dword ptr [ESP + param_3]
    //         0045136a     PUSH       0x1
    //         0045136c     PUSH       this
    //         0045136d     MOV        this,dword ptr [ESP + param_2]
    //         00451371     PUSH       EDX
    //         00451372     PUSH       this
    //         00451373     PUSH       EBX
    //         00451374     PUSH       EDI
    //         00451375     MOV        this,EAX
    //         00451377     CALL       RGE_Doppleganger_Object::RGE_Doppleganger_Object undefined RGE_Doppleganger_Object(RGE_Doppleg
    //                              m_dg_obj.cpp:108 (42)
    //         0045137c     MOV        this,dword ptr [ESP + local_c]
    //         00451380     MOV        dword ptr FS:[0x0],this
    //         00451387     POP        EDI
    //         00451388     POP        ESI
    //         00451389     POP        EBX
    //         0045138a     ADD        ESP,0xc
    //         0045138d     RET        0x14
    //                               LAB_00451390                                                 XREF[1]:     0045135b(j)  
    //         00451390     MOV        this,dword ptr [ESP + local_c]
    //         00451394     POP        EDI
    //         00451395     POP        ESI
    //         00451396     XOR        EAX,EAX
    //         00451398     MOV        dword ptr FS:[0x0],this
    //         0045139f     POP        EBX
    //         004513a0     ADD        ESP,0xc
    //         004513a3     RET        0x14
    //         004513a6     ??         90h
    //         004513a7     NOP
    //         004513a8     NOP
    //         004513a9     NOP
    //         004513aa     NOP
    //         004513ab     NOP
    //         004513ac     NOP
    //         004513ad     NOP
    //         004513ae     NOP
    //         004513af     NOP
    //                              * public: virtual class RGE_Master_Static_Object * __thiscall RGE_Master_Doppleganger_Object::make_n... *
    //                              RGE_Master_Static_Object * __thiscall make_new_master(RGE_Master_Dop
    //              RGE_Master_Sta    EAX:4          <RETURN>
    //              RGE_Master_Dop    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004513dc(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     004513f0(R), 00451400(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004513d6(W)  
    //                               ?make_new_master@RGE_Master_Doppleganger_Object@@UAEPAVRGE_  XREF[1]:     0057053c(*)  
    //                               RGE_Master_Doppleganger_Object::make_new_master
    //                              m_dg_obj.cpp:113 (25)
    //         004513b0     PUSH       -0x1
    //         004513b2     PUSH       FUN_0055d8db
    //         004513b7     MOV        EAX,FS:[0x0]
    //         004513bd     PUSH       EAX
    //         004513be     MOV        dword ptr FS:[0x0],ESP
    //         004513c5     PUSH       this
    //         004513c6     PUSH       ESI
    //         004513c7     MOV        ESI,this
    //                              m_dg_obj.cpp:114 (39)
    //         004513c9     PUSH       0xbc
    //         004513ce     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004513d3     ADD        ESP,0x4
    //         004513d6     MOV        dword ptr [ESP + local_10],EAX
    //         004513da     TEST       EAX,EAX
    //         004513dc     MOV        dword ptr [ESP + local_4],0x0
    //         004513e4     JZ         LAB_00451400
    //         004513e6     PUSH       0x1
    //         004513e8     PUSH       ESI
    //         004513e9     MOV        this,EAX
    //         004513eb     CALL       RGE_Master_Doppleganger_Object::RGE_Master_Dop   undefined RGE_Master_Doppleganger_Object(RGE_
    //                              m_dg_obj.cpp:115 (34)
    //         004513f0     MOV        this,dword ptr [ESP + local_c]
    //         004513f4     MOV        dword ptr FS:[0x0],this
    //         004513fb     POP        ESI
    //         004513fc     ADD        ESP,0x10
    //         004513ff     RET
    //                               LAB_00451400                                                 XREF[1]:     004513e4(j)  
    //         00451400     MOV        this,dword ptr [ESP + local_c]
    //         00451404     XOR        EAX,EAX
    //         00451406     MOV        dword ptr FS:[0x0],this
    //         0045140d     POP        ESI
    //         0045140e     ADD        ESP,0x10
    //         00451411     RET
    //         00451412     ??         90h
    //         00451413     NOP
    //         00451414     NOP
    //         00451415     NOP
    //         00451416     NOP
    //         00451417     NOP
    //         00451418     NOP
    //         00451419     NOP
    //         0045141a     NOP
    //         0045141b     NOP
    //         0045141c     NOP
    //         0045141d     NOP
    //         0045141e     NOP
    //         0045141f     NOP
    //                              * public: virtual void __thiscall RGE_Master_Doppleganger_Object::copy_obj(class RGE_Master_Static_O... *
    //                              void __thiscall copy_obj(RGE_Master_Doppleganger_Object * this, RGE_
    //              void              <VOID>         <RETURN>
    //              RGE_Master_Dop    ECX:4 (auto)   this
    //              RGE_Master_Sta    Stack[0x4]:4   param_1                   XREF[1]:     00451420(R)  
    //                               ?copy_obj@RGE_Master_Doppleganger_Object@@UAEXPAVRGE_Master  XREF[1]:     00570524(*)  
    //                               RGE_Master_Doppleganger_Object::copy_obj
    //                              m_dg_obj.cpp:120 (10)
    //         00451420     MOV        EAX,dword ptr [ESP + param_1]
    //         00451424     PUSH       EAX
    //         00451425     CALL       RGE_Master_Animated_Object::copy_obj             void copy_obj(RGE_Master_Animated_Object * th
    //                              m_dg_obj.cpp:124 (3)
    //         0045142a     RET        0x4
    //         0045142d     ??         90h
    //         0045142e     NOP
    //         0045142f     NOP
}

void RGE_Master_Doppleganger_Object::save(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall save(RGE_Master_Doppleganger_Object * this, int para
    //              void              <VOID>         <RETURN>
    //              RGE_Master_Dop    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00451430(R)  
    //                               ?save@RGE_Master_Doppleganger_Object@@UAEXH@Z                XREF[1]:     00570534(*)  
    //                               RGE_Master_Doppleganger_Object::save
    //                              m_dg_obj.cpp:129 (10)
    //         00451430     MOV        EAX,dword ptr [ESP + param_1]
    //         00451434     PUSH       EAX
    //         00451435     CALL       RGE_Master_Animated_Object::save                 void save(RGE_Master_Animated_Object * this, 
    //                              m_dg_obj.cpp:131 (3)
    //         0045143a     RET        0x4
    //         0045143d     ??         90h
    //         0045143e     NOP
    //         0045143f     NOP
    //                              * public: __thiscall RGE_Master_Missile_Object::RGE_Master_Missile_Object(class RGE_Master_Missile_O... *
    //                              undefined __thiscall RGE_Master_Missile_Object(RGE_Master_Missile_Ob
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Master_Mis    ECX:4 (auto)   this
    //              RGE_Master_Mis    Stack[0x4]:4   param_1                   XREF[1]:     00451458(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0045146a(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0045146e(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00451488(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00451461(W)  
    //                               ??0RGE_Master_Missile_Object@@QAE@PAV0@H@Z                   XREF[1]:     make_new_master:0045187b(c)  
    //                               RGE_Master_Missile_Object::RGE_Master_Missile_Object
    //                              m_mi_obj.cpp:24 (42)
    //         00451440     PUSH       -0x1
    //         00451442     PUSH       FUN_0055d8f8
    //         00451447     MOV        EAX,FS:[0x0]
    //         0045144d     PUSH       EAX
    //         0045144e     MOV        dword ptr FS:[0x0],ESP
    //         00451455     PUSH       this
    //         00451456     PUSH       ESI
    //         00451457     PUSH       EDI
    //         00451458     MOV        EDI,dword ptr [ESP + param_1]
    //         0045145c     MOV        ESI,this
    //         0045145e     PUSH       0x0
    //         00451460     PUSH       EDI
    //         00451461     MOV        dword ptr [ESP + local_10],ESI
    //         00451465     CALL       RGE_Master_Combat_Object::RGE_Master_Combat_Ob   undefined RGE_Master_Combat_Object(RGE_Master
    //                              m_mi_obj.cpp:25 (22)
    //         0045146a     MOV        EAX,dword ptr [ESP + param_2]
    //         0045146e     MOV        dword ptr [ESP + local_4],0x0
    //         00451476     TEST       EAX,EAX
    //         00451478     MOV        dword ptr [ESI],RGE_Master_Missile_Object::`vf   = 004514a0
    //         0045147e     JZ         LAB_00451488
    //                              m_mi_obj.cpp:26 (8)
    //         00451480     PUSH       EDI
    //         00451481     MOV        this,ESI
    //         00451483     CALL       RGE_Master_Missile_Object::setup                 int setup(RGE_Master_Missile_Object * this, R
    //                               LAB_00451488                                                 XREF[1]:     0045147e(j)  
    //                              m_mi_obj.cpp:27 (21)
    //         00451488     MOV        this,dword ptr [ESP + local_c]
    //         0045148c     MOV        EAX,ESI
    //         0045148e     POP        EDI
    //         0045148f     MOV        dword ptr FS:[0x0],this
    //         00451496     POP        ESI
    //         00451497     ADD        ESP,0x10
    //         0045149a     RET        0x8
    //         0045149d     ??         90h
    //         0045149e     NOP
    //         0045149f     NOP
    //                              * public: virtual void * __thiscall RGE_Master_Missile_Object::`vector deleting destructor'(unsigned... *
    //                              void * __thiscall `vector_deleting_destructor'(RGE_Master_Missile_Ob
    //              void *            EAX:4          <RETURN>
    //              RGE_Master_Mis    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004514a8(R)  
    //                               ??_GRGE_Master_Missile_Object@@UAEPAXI@Z                     XREF[1]:     00570560(*)  
    //                               ??_ERGE_Master_Missile_Object@@UAEPAXI@Z
    //                               RGE_Master_Missile_Object::`vector_deleting_destructor'
    //         004514a0     PUSH       ESI
    //         004514a1     MOV        ESI,this
    //         004514a3     CALL       RGE_Master_Missile_Object::~RGE_Master_Missile   void ~RGE_Master_Missile_Object(RGE_Master_Mi
    //         004514a8     TEST       byte ptr [ESP + param_1],0x1
    //         004514ad     JZ         LAB_004514b8
    //         004514af     PUSH       ESI
    //         004514b0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004514b5     ADD        ESP,0x4
    //                               LAB_004514b8                                                 XREF[1]:     004514ad(j)  
    //         004514b8     MOV        EAX,ESI
    //         004514ba     POP        ESI
    //         004514bb     RET        0x4
    //         004514be     ??         90h
    //         004514bf     NOP
    //                              * public: __thiscall RGE_Master_Missile_Object::RGE_Master_Missile_Object(int,class RGE_Sprite * *,c... *
    //                              undefined __thiscall RGE_Master_Missile_Object(RGE_Master_Missile_Ob
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Master_Mis    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004514dc(R)  
    //              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     004514d7(R)  
    //              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[1]:     004514e2(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     004514f6(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004514fa(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00451516(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004514ed(W)  
    //                               ??0RGE_Master_Missile_Object@@QAE@HPAPAVRGE_Sprite@@PAPAVRG  XREF[2]:     load_master_object:004613b2(c), 
    //                               RGE_Master_Missile_Object::RGE_Master_Missile_Object                      load_master_object:0046fd82(c)  
    //                              m_mi_obj.cpp:33 (54)
    //         004514c0     PUSH       -0x1
    //         004514c2     PUSH       FUN_0055d918
    //         004514c7     MOV        EAX,FS:[0x0]
    //         004514cd     PUSH       EAX
    //         004514ce     MOV        dword ptr FS:[0x0],ESP
    //         004514d5     PUSH       this
    //         004514d6     PUSH       EBX
    //         004514d7     MOV        EBX,dword ptr [ESP + param_2]
    //         004514db     PUSH       EBP
    //         004514dc     MOV        EBP,dword ptr [ESP + param_1]
    //         004514e0     PUSH       ESI
    //         004514e1     PUSH       EDI
    //         004514e2     MOV        EDI,dword ptr [ESP + param_3]
    //         004514e6     PUSH       0x0
    //         004514e8     PUSH       EDI
    //         004514e9     MOV        ESI,this
    //         004514eb     PUSH       EBX
    //         004514ec     PUSH       EBP
    //         004514ed     MOV        dword ptr [ESP + local_10],ESI
    //         004514f1     CALL       RGE_Master_Combat_Object::RGE_Master_Combat_Ob   undefined RGE_Master_Combat_Object(RGE_Master
    //                              m_mi_obj.cpp:34 (22)
    //         004514f6     MOV        EAX,dword ptr [ESP + param_4]
    //         004514fa     MOV        dword ptr [ESP + local_4],0x0
    //         00451502     TEST       EAX,EAX
    //         00451504     MOV        dword ptr [ESI],RGE_Master_Missile_Object::`vf   = 004514a0
    //         0045150a     JZ         LAB_00451516
    //                              m_mi_obj.cpp:35 (10)
    //         0045150c     PUSH       EDI
    //         0045150d     PUSH       EBX
    //         0045150e     PUSH       EBP
    //         0045150f     MOV        this,ESI
    //         00451511     CALL       RGE_Master_Missile_Object::setup                 int setup(RGE_Master_Missile_Object * this, i
    //                               LAB_00451516                                                 XREF[1]:     0045150a(j)  
    //                              m_mi_obj.cpp:36 (23)
    //         00451516     MOV        this,dword ptr [ESP + local_c]
    //         0045151a     MOV        EAX,ESI
    //         0045151c     POP        EDI
    //         0045151d     POP        ESI
    //         0045151e     POP        EBP
    //         0045151f     MOV        dword ptr FS:[0x0],this
    //         00451526     POP        EBX
    //         00451527     ADD        ESP,0x10
    //         0045152a     RET        0x10
    //         0045152d     ??         90h
    //         0045152e     NOP
    //         0045152f     NOP
    //                              * public: __thiscall RGE_Master_Missile_Object::RGE_Master_Missile_Object(struct _iobuf *,class RGE_... *
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
    return;
}

RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Object(RGE_Master_Doppleganger_Object* param_1, int param_2) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
}

RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
}

RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Object(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
}

int RGE_Master_Doppleganger_Object::setup(RGE_Master_Doppleganger_Object* param_1) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

int RGE_Master_Doppleganger_Object::setup(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

int RGE_Master_Doppleganger_Object::setup(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

RGE_Static_Object* RGE_Master_Doppleganger_Object::make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4, RGE_Static_Object* param_5) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

RGE_Master_Static_Object* RGE_Master_Doppleganger_Object::make_new_master() {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

void RGE_Master_Doppleganger_Object::copy_obj(RGE_Master_Static_Object* param_1) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return;
}

