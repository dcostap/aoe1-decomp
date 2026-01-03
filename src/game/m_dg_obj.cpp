#include "../common.h"
#include "m_dg_obj.h"

RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Object(RGE_Master_Doppleganger_Object* param_1, int param_2) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Master_Doppleganger_Object(RGE_Master_Doppl
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Master_Dop    ECX:4 (auto)   this
//              RGE_Master_Dop    Stack[0x4]:4   param_1                   XREF[1]:     004510d8(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     004510ea(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004510ee(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00451108(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004510e1(W)
//                               ??0RGE_Master_Doppleganger_Object@@QAE@PAV0@H@Z              XREF[1]:     make_new_master:004513eb(c)
//                               RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Obj
//                              m_dg_obj.cpp:24 (42)
//         004510c0     PUSH       -0x1
//         004510c2     PUSH       FUN_0055d858
//         004510c7     MOV        EAX,FS:[0x0]
//         004510cd     PUSH       EAX
//         004510ce     MOV        dword ptr FS:[0x0],ESP
//         004510d5     PUSH       this
//         004510d6     PUSH       ESI
//         004510d7     PUSH       EDI
//         004510d8     MOV        EDI,dword ptr [ESP + param_1]
//         004510dc     MOV        ESI,this
//         004510de     PUSH       0x0
//         004510e0     PUSH       EDI
//         004510e1     MOV        dword ptr [ESP + local_10],ESI
//         004510e5     CALL       RGE_Master_Animated_Object::RGE_Master_Animate   undefined RGE_Master_Animated_Object(RGE_Mast
//                              m_dg_obj.cpp:25 (22)
//         004510ea     MOV        EAX,dword ptr [ESP + param_2]
//         004510ee     MOV        dword ptr [ESP + local_4],0x0
//         004510f6     TEST       EAX,EAX
//         004510f8     MOV        dword ptr [ESI],RGE_Master_Doppleganger_Object   = 00451120
//         004510fe     JZ         LAB_00451108
//                              m_dg_obj.cpp:26 (8)
//         00451100     PUSH       EDI
//         00451101     MOV        this,ESI
//         00451103     CALL       RGE_Master_Doppleganger_Object::setup            int setup(RGE_Master_Doppleganger_Object * th
//                               LAB_00451108                                                 XREF[1]:     004510fe(j)
//                              m_dg_obj.cpp:27 (21)
//         00451108     MOV        this,dword ptr [ESP + local_c]
//         0045110c     MOV        EAX,ESI
//         0045110e     POP        EDI
//         0045110f     MOV        dword ptr FS:[0x0],this
//         00451116     POP        ESI
//         00451117     ADD        ESP,0x10
//         0045111a     RET        0x8
//         0045111d     ??         90h
//         0045111e     NOP
//         0045111f     NOP
}

RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Master_Doppleganger_Object(RGE_Master_Doppl
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Master_Dop    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0045115c(R)
//              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     00451157(R)
//              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[1]:     00451162(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     00451176(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0045117a(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00451196(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0045116d(W)
//                               ??0RGE_Master_Doppleganger_Object@@QAE@HPAPAVRGE_Sprite@@PA  XREF[2]:     load_master_object:004614b3(c),
//                               RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Obj               load_master_object:0046fe83(c)
//                              m_dg_obj.cpp:33 (54)
//         00451140     PUSH       -0x1
//         00451142     PUSH       FUN_0055d878
//         00451147     MOV        EAX,FS:[0x0]
//         0045114d     PUSH       EAX
//         0045114e     MOV        dword ptr FS:[0x0],ESP
//         00451155     PUSH       this
//         00451156     PUSH       EBX
//         00451157     MOV        EBX,dword ptr [ESP + param_2]
//         0045115b     PUSH       EBP
//         0045115c     MOV        EBP,dword ptr [ESP + param_1]
//         00451160     PUSH       ESI
//         00451161     PUSH       EDI
//         00451162     MOV        EDI,dword ptr [ESP + param_3]
//         00451166     PUSH       0x0
//         00451168     PUSH       EDI
//         00451169     MOV        ESI,this
//         0045116b     PUSH       EBX
//         0045116c     PUSH       EBP
//         0045116d     MOV        dword ptr [ESP + local_10],ESI
//         00451171     CALL       RGE_Master_Animated_Object::RGE_Master_Animate   undefined RGE_Master_Animated_Object(RGE_Mast
//                              m_dg_obj.cpp:34 (22)
//         00451176     MOV        EAX,dword ptr [ESP + param_4]
//         0045117a     MOV        dword ptr [ESP + local_4],0x0
//         00451182     TEST       EAX,EAX
//         00451184     MOV        dword ptr [ESI],RGE_Master_Doppleganger_Object   = 00451120
//         0045118a     JZ         LAB_00451196
//                              m_dg_obj.cpp:35 (10)
//         0045118c     PUSH       EDI
//         0045118d     PUSH       EBX
//         0045118e     PUSH       EBP
//         0045118f     MOV        this,ESI
//         00451191     CALL       RGE_Master_Doppleganger_Object::setup            int setup(RGE_Master_Doppleganger_Object * th
//                               LAB_00451196                                                 XREF[1]:     0045118a(j)
//                              m_dg_obj.cpp:36 (23)
//         00451196     MOV        this,dword ptr [ESP + local_c]
//         0045119a     MOV        EAX,ESI
//         0045119c     POP        EDI
//         0045119d     POP        ESI
//         0045119e     POP        EBP
//         0045119f     MOV        dword ptr FS:[0x0],this
//         004511a6     POP        EBX
//         004511a7     ADD        ESP,0x10
//         004511aa     RET        0x10
//         004511ad     ??         90h
//         004511ae     NOP
//         004511af     NOP
}

RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Object(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Master_Doppleganger_Object(RGE_Master_Doppl
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Master_Dop    ECX:4 (auto)   this
//              _iobuf *          Stack[0x4]:4   param_1                   XREF[2]:     004511c6(R), 00451201(R)
//              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     004511d0(R)
//              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[1]:     004511cb(R)
//              short             Stack[0x10]:2  param_4                   XREF[1]:     004511d6(R)
//              int               Stack[0x14]:4  param_5                   XREF[1]:     004511eb(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004511ef(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00451210(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004511e2(W)
//                               ??0RGE_Master_Doppleganger_Object@@QAE@PAU_iobuf@@PAPAVRGE_  XREF[1]:     load_object:004617c3(c)
//                               RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Obj
//                              m_dg_obj.cpp:42 (59)
//         004511b0     PUSH       -0x1
//         004511b2     PUSH       FUN_0055d898
//         004511b7     MOV        EAX,FS:[0x0]
//         004511bd     PUSH       EAX
//         004511be     MOV        dword ptr FS:[0x0],ESP
//         004511c5     PUSH       this
//         004511c6     MOV        EAX,dword ptr [ESP + param_1]
//         004511ca     PUSH       EBX
//         004511cb     MOV        EBX,dword ptr [ESP + param_3]
//         004511cf     PUSH       EBP
//         004511d0     MOV        EBP,dword ptr [ESP + param_2]
//         004511d4     PUSH       ESI
//         004511d5     PUSH       EDI
//         004511d6     MOV        EDI,dword ptr [ESP + param_4]
//         004511da     PUSH       0x0
//         004511dc     PUSH       EDI
//         004511dd     PUSH       EBX
//         004511de     MOV        ESI,this
//         004511e0     PUSH       EBP
//         004511e1     PUSH       EAX
//         004511e2     MOV        dword ptr [ESP + local_10],ESI
//         004511e6     CALL       RGE_Master_Animated_Object::RGE_Master_Animate   undefined RGE_Master_Animated_Object(RGE_Mast
//                              m_dg_obj.cpp:43 (22)
//         004511eb     MOV        EAX,dword ptr [ESP + param_5]
//         004511ef     MOV        dword ptr [ESP + local_4],0x0
//         004511f7     TEST       EAX,EAX
//         004511f9     MOV        dword ptr [ESI],RGE_Master_Doppleganger_Object   = 00451120
//         004511ff     JZ         LAB_00451210
//                              m_dg_obj.cpp:44 (15)
//         00451201     MOV        this,dword ptr [ESP + param_1]
//         00451205     PUSH       EDI
//         00451206     PUSH       EBX
//         00451207     PUSH       EBP
//         00451208     PUSH       this
//         00451209     MOV        this,ESI
//         0045120b     CALL       RGE_Master_Doppleganger_Object::setup            int setup(RGE_Master_Doppleganger_Object * th
//                               LAB_00451210                                                 XREF[1]:     004511ff(j)
//                              m_dg_obj.cpp:45 (23)
//         00451210     MOV        this,dword ptr [ESP + local_c]
//         00451214     MOV        EAX,ESI
//         00451216     POP        EDI
//         00451217     POP        ESI
//         00451218     POP        EBP
//         00451219     MOV        dword ptr FS:[0x0],this
//         00451220     POP        EBX
//         00451221     ADD        ESP,0x10
//         00451224     RET        0x14
//         00451227     ??         90h
//         00451228     NOP
//         00451229     NOP
//         0045122a     NOP
//         0045122b     NOP
//         0045122c     NOP
//         0045122d     NOP
//         0045122e     NOP
//         0045122f     NOP
}

int RGE_Master_Doppleganger_Object::setup(RGE_Master_Doppleganger_Object* param_1) {
    /* TODO: Stub */
//                              int __thiscall setup(RGE_Master_Doppleganger_Object * this, RGE_Mast
//              int               EAX:4          <RETURN>
//              RGE_Master_Dop    ECX:4 (auto)   this
//              RGE_Master_Dop    Stack[0x4]:4   param_1                   XREF[1]:     00451230(R)
//                               ?setup@RGE_Master_Doppleganger_Object@@IAEHPAV1@@Z           XREF[1]:     RGE_Master_Doppleganger_Object:004
//                               RGE_Master_Doppleganger_Object::setup
//                              m_dg_obj.cpp:51 (13)
//         00451230     MOV        EAX,dword ptr [ESP + param_1]
//         00451234     PUSH       ESI
//         00451235     MOV        ESI,this
//         00451237     PUSH       EAX
//         00451238     CALL       RGE_Master_Animated_Object::setup                int setup(RGE_Master_Animated_Object * this,
//                              m_dg_obj.cpp:54 (4)
//         0045123d     MOV        byte ptr [ESI + 0x4],0x19
//                              m_dg_obj.cpp:56 (4)
//         00451241     MOV        byte ptr [ESI + 0x65],0x3
//                              m_dg_obj.cpp:58 (5)
//         00451245     MOV        EAX,0x1
//                              m_dg_obj.cpp:59 (4)
//         0045124a     POP        ESI
//         0045124b     RET        0x4
//         0045124e     ??         90h
//         0045124f     NOP
    return 0;
}

int RGE_Master_Doppleganger_Object::setup(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3) {
    /* TODO: Stub */
//                              int __thiscall setup(RGE_Master_Doppleganger_Object * this, int para
//              int               EAX:4          <RETURN>
//              RGE_Master_Dop    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00451254(R)
//              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     0045125b(R)
//              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[1]:     00451250(R)
//                               ?setup@RGE_Master_Doppleganger_Object@@IAEHHPAPAVRGE_Sprite  XREF[1]:     RGE_Master_Doppleganger_Object:004
//                               RGE_Master_Doppleganger_Object::setup
//                              m_dg_obj.cpp:64 (25)
//         00451250     MOV        EAX,dword ptr [ESP + param_3]
//         00451254     MOV        EDX,dword ptr [ESP + param_1]
//         00451258     PUSH       ESI
//         00451259     MOV        ESI,this
//         0045125b     MOV        this,dword ptr [ESP + param_2]
//         0045125f     PUSH       EAX
//         00451260     PUSH       this
//         00451261     PUSH       EDX
//         00451262     MOV        this,ESI
//         00451264     CALL       RGE_Master_Animated_Object::setup                int setup(RGE_Master_Animated_Object * this,
//                              m_dg_obj.cpp:67 (4)
//         00451269     MOV        byte ptr [ESI + 0x4],0x19
//                              m_dg_obj.cpp:69 (5)
//         0045126d     MOV        EAX,0x1
//                              m_dg_obj.cpp:70 (4)
//         00451272     POP        ESI
//         00451273     RET        0xc
//         00451276     ??         90h
//         00451277     NOP
//         00451278     NOP
//         00451279     NOP
//         0045127a     NOP
//         0045127b     NOP
//         0045127c     NOP
//         0045127d     NOP
//         0045127e     NOP
//         0045127f     NOP
    return 0;
}

int RGE_Master_Doppleganger_Object::setup(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4) {
    /* TODO: Stub */
//                              int __thiscall setup(RGE_Master_Doppleganger_Object * this, _iobuf *
//              int               EAX:4          <RETURN>
//              RGE_Master_Dop    ECX:4 (auto)   this
//              _iobuf *          Stack[0x4]:4   param_1                   XREF[1]:     00451290(R)
//              RGE_Sprite * *    Stack[0x8]:4   param_2                   XREF[1]:     00451284(R)
//              RGE_Sound * *     Stack[0xc]:4   param_3                   XREF[1]:     0045128b(R)
//              short             Stack[0x10]:2  param_4                   XREF[1]:     00451280(R)
//                               ?setup@RGE_Master_Doppleganger_Object@@IAEHPAU_iobuf@@PAPAV  XREF[1]:     RGE_Master_Doppleganger_Object:004
//                               RGE_Master_Doppleganger_Object::setup
//                              m_dg_obj.cpp:75 (30)
//         00451280     MOV        EAX,dword ptr [ESP + param_4]
//         00451284     MOV        EDX,dword ptr [ESP + param_2]
//         00451288     PUSH       ESI
//         00451289     MOV        ESI,this
//         0045128b     MOV        this,dword ptr [ESP + param_3]
//         0045128f     PUSH       EAX
//         00451290     MOV        EAX,dword ptr [ESP + param_1]
//         00451294     PUSH       this
//         00451295     PUSH       EDX
//         00451296     PUSH       EAX
//         00451297     MOV        this,ESI
//         00451299     CALL       RGE_Master_Animated_Object::setup                int setup(RGE_Master_Animated_Object * this,
//                              m_dg_obj.cpp:80 (15)
//         0045129e     MOV        EAX,0x1
//         004512a3     MOV        byte ptr [ESI + 0x4],0x19
//         004512a7     MOV        byte ptr [ESI + 0xa4],AL
//                              m_dg_obj.cpp:83 (4)
//         004512ad     POP        ESI
//         004512ae     RET        0x10
//         004512b1     ??         90h
//         004512b2     NOP
//         004512b3     NOP
//         004512b4     NOP
//         004512b5     NOP
//         004512b6     NOP
//         004512b7     NOP
//         004512b8     NOP
//         004512b9     NOP
//         004512ba     NOP
//         004512bb     NOP
//         004512bc     NOP
//         004512bd     NOP
//         004512be     NOP
//         004512bf     NOP
    return 0;
}

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
}

RGE_Static_Object* RGE_Master_Doppleganger_Object::make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4, RGE_Static_Object* param_5) {
    /* TODO: Stub */
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
    return 0;
}

void RGE_Master_Doppleganger_Object::copy_obj(RGE_Master_Static_Object* param_1) {
    /* TODO: Stub */
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
    return;
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
    return;
}

RGE_Master_Static_Object* RGE_Master_Doppleganger_Object::make_new_master() {
    /* TODO: Stub */
// <NO ASSEMBLY FOUND>
    return 0;
}

