#include "../common.h"
#include "com_obj.h"

RGE_Combat_Object::RGE_Combat_Object(RGE_Master_Combat_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Combat_Object(RGE_Combat_Object * this, RGE
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              RGE_Master_Com    Stack[0x4]:4   param_1                   XREF[2]:     0042f95e(R), 0042f98c(R)
//              RGE_Player *      Stack[0x8]:4   param_2                   XREF[2]:     0042f946(R), 0042f988(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     0042f950(R)
//              float             Stack[0x10]:4  param_4                   XREF[1]:     0042f94b(R)
//              float             Stack[0x14]:4  param_5                   XREF[1]:     0042f956(R)
//              int               Stack[0x18]:4  param_6                   XREF[1]:     0042f972(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0042f976(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0042f99c(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0042f969(W)
//                               ??0RGE_Combat_Object@@QAE@PAVRGE_Master_Combat_Object@@PAVR  XREF[3]:     make_new_obj:0045076a(c),
//                               RGE_Combat_Object::RGE_Combat_Object                                      RGE_Missile_Object:0045a77d(c),
//                                                                                                         TRIBE_Combat_Object:004ca12d(c)
//                              com_obj.cpp:72 (66)
//         0042f930     PUSH       -0x1
//         0042f932     PUSH       FUN_0055cd58
//         0042f937     MOV        EAX,FS:[0x0]
//         0042f93d     PUSH       EAX
//         0042f93e     MOV        dword ptr FS:[0x0],ESP
//         0042f945     PUSH       this
//         0042f946     MOV        EAX,dword ptr [ESP + param_2]
//         0042f94a     PUSH       EBX
//         0042f94b     MOV        EBX,dword ptr [ESP + param_4]
//         0042f94f     PUSH       EBP
//         0042f950     MOV        EBP,dword ptr [ESP + param_3]
//         0042f954     PUSH       ESI
//         0042f955     PUSH       EDI
//         0042f956     MOV        EDI,dword ptr [ESP + param_5]
//         0042f95a     PUSH       0x0
//         0042f95c     MOV        ESI,this
//         0042f95e     MOV        this,dword ptr [ESP + param_1]
//         0042f962     PUSH       EDI
//         0042f963     PUSH       EBX
//         0042f964     PUSH       EBP
//         0042f965     PUSH       EAX
//         0042f966     PUSH       this
//         0042f967     MOV        this,ESI
//         0042f969     MOV        dword ptr [ESP + local_10],ESI
//         0042f96d     CALL       RGE_Action_Object::RGE_Action_Object             undefined RGE_Action_Object(RGE_Action_Object
//                              com_obj.cpp:73 (22)
//         0042f972     MOV        EAX,dword ptr [ESP + param_6]
//         0042f976     MOV        dword ptr [ESP + local_4],0x0
//         0042f97e     TEST       EAX,EAX
//         0042f980     MOV        dword ptr [ESI],RGE_Combat_Object::`vftable'     = 0042f9c0
//         0042f986     JZ         LAB_0042f99c
//                              com_obj.cpp:74 (20)
//         0042f988     MOV        EDX,dword ptr [ESP + param_2]
//         0042f98c     MOV        EAX,dword ptr [ESP + param_1]
//         0042f990     PUSH       EDI
//         0042f991     PUSH       EBX
//         0042f992     PUSH       EBP
//         0042f993     PUSH       EDX
//         0042f994     PUSH       EAX
//         0042f995     MOV        this,ESI
//         0042f997     CALL       RGE_Combat_Object::setup                         int setup(RGE_Combat_Object * this, RGE_Maste
//                               LAB_0042f99c                                                 XREF[1]:     0042f986(j)
//                              com_obj.cpp:75 (23)
//         0042f99c     MOV        this,dword ptr [ESP + local_c]
//         0042f9a0     MOV        EAX,ESI
//         0042f9a2     POP        EDI
//         0042f9a3     POP        ESI
//         0042f9a4     POP        EBP
//         0042f9a5     MOV        dword ptr FS:[0x0],this
//         0042f9ac     POP        EBX
//         0042f9ad     ADD        ESP,0x10
//         0042f9b0     RET        0x18
//         0042f9b3     ??         90h
//         0042f9b4     NOP
//         0042f9b5     NOP
//         0042f9b6     NOP
//         0042f9b7     NOP
//         0042f9b8     NOP
//         0042f9b9     NOP
//         0042f9ba     NOP
//         0042f9bb     NOP
//         0042f9bc     NOP
//         0042f9bd     NOP
//         0042f9be     NOP
//         0042f9bf     NOP
}

RGE_Combat_Object::RGE_Combat_Object(int param_1, RGE_Game_World* param_2, int param_3) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Combat_Object(RGE_Combat_Object * this, int
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0042f9f7(R)
//              RGE_Game_World    Stack[0x8]:4   param_2                   XREF[1]:     0042f9fd(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     0042fa10(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0042fa14(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0042fa2f(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0042fa07(W)
//                               ??0RGE_Combat_Object@@QAE@HPAVRGE_Game_World@@H@Z            XREF[3]:     RGE_Missile_Object:0045a82b(c),
//                               RGE_Combat_Object::RGE_Combat_Object                                      load:00463b2e(c),
//                                                                                                         TRIBE_Combat_Object:004ca1cb(c)
//                              com_obj.cpp:82 (48)
//         0042f9e0     PUSH       -0x1
//         0042f9e2     PUSH       FUN_0055cd78
//         0042f9e7     MOV        EAX,FS:[0x0]
//         0042f9ed     PUSH       EAX
//         0042f9ee     MOV        dword ptr FS:[0x0],ESP
//         0042f9f5     PUSH       this
//         0042f9f6     PUSH       EBX
//         0042f9f7     MOV        EBX,dword ptr [ESP + param_1]
//         0042f9fb     PUSH       ESI
//         0042f9fc     PUSH       EDI
//         0042f9fd     MOV        EDI,dword ptr [ESP + param_2]
//         0042fa01     PUSH       0x0
//         0042fa03     MOV        ESI,this
//         0042fa05     PUSH       EDI
//         0042fa06     PUSH       EBX
//         0042fa07     MOV        dword ptr [ESP + local_10],ESI
//         0042fa0b     CALL       RGE_Action_Object::RGE_Action_Object             undefined RGE_Action_Object(RGE_Action_Object
//                              com_obj.cpp:83 (22)
//         0042fa10     MOV        EAX,dword ptr [ESP + param_3]
//         0042fa14     MOV        dword ptr [ESP + local_4],0x0
//         0042fa1c     TEST       EAX,EAX
//         0042fa1e     MOV        dword ptr [ESI],RGE_Combat_Object::`vftable'     = 0042f9c0
//         0042fa24     JZ         LAB_0042fa2f
//                              com_obj.cpp:84 (9)
//         0042fa26     PUSH       EDI
//         0042fa27     PUSH       EBX
//         0042fa28     MOV        this,ESI
//         0042fa2a     CALL       RGE_Combat_Object::setup                         int setup(RGE_Combat_Object * this, int param
//                               LAB_0042fa2f                                                 XREF[1]:     0042fa24(j)
//                              com_obj.cpp:85 (22)
//         0042fa2f     MOV        this,dword ptr [ESP + local_c]
//         0042fa33     MOV        EAX,ESI
//         0042fa35     POP        EDI
//         0042fa36     POP        ESI
//         0042fa37     MOV        dword ptr FS:[0x0],this
//         0042fa3e     POP        EBX
//         0042fa3f     ADD        ESP,0x10
//         0042fa42     RET        0xc
//         0042fa45     ??         90h
//         0042fa46     NOP
//         0042fa47     NOP
//         0042fa48     NOP
//         0042fa49     NOP
//         0042fa4a     NOP
//         0042fa4b     NOP
//         0042fa4c     NOP
//         0042fa4d     NOP
//         0042fa4e     NOP
//         0042fa4f     NOP
}

RGE_Combat_Object::~RGE_Combat_Object() {
    /* TODO: Stub */
//                              void __thiscall ~RGE_Combat_Object(RGE_Combat_Object * this)
//              void              <VOID>         <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0042fa77(W), 0042fac3(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0042fad0(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0042fa6a(W)
//                               ??1RGE_Combat_Object@@UAE@XZ                                 XREF[3]:     `vector_deleting_destructor':0042f
//                               RGE_Combat_Object::~RGE_Combat_Object                                     ~RGE_Combat_Object:0045a7ee(T),
//                                                                                                         ~RGE_Missile_Object:0045a7f0(j),
//                                                                                                         ~TRIBE_Combat_Object:004ca2db(c)
//                              com_obj.cpp:91 (36)
//         0042fa50     PUSH       -0x1
//         0042fa52     PUSH       FUN_0055cd98
//         0042fa57     MOV        EAX,FS:[0x0]
//         0042fa5d     PUSH       EAX
//         0042fa5e     MOV        dword ptr FS:[0x0],ESP
//         0042fa65     PUSH       this
//         0042fa66     PUSH       ESI
//         0042fa67     MOV        ESI,this
//         0042fa69     PUSH       EDI
//         0042fa6a     MOV        dword ptr [ESP + local_10],ESI
//         0042fa6e     MOV        dword ptr [ESI],RGE_Combat_Object::`vftable'     = 0042f9c0
//                              com_obj.cpp:93 (15)
//         0042fa74     MOV        EDI,dword ptr [ESI + 0x4]
//         0042fa77     MOV        dword ptr [ESP + local_4],0x0
//         0042fa7f     TEST       EDI,EDI
//         0042fa81     JL         LAB_0042fac1
//                              com_obj.cpp:96 (64)
//         0042fa83     MOV        EDX,dword ptr [ESI + 0x8]
//         0042fa86     MOV        this,dword ptr [ESI + 0x1b8]
//         0042fa8c     FLD        float ptr [ESI + 0x3c]
//         0042fa8f     LEA        EAX,[ESI + 0x194]
//         0042fa95     PUSH       EAX
//         0042fa96     PUSH       0x0
//         0042fa98     MOVSX      EAX,word ptr [EDX + 0x14]
//         0042fa9c     PUSH       this
//         0042fa9d     PUSH       EAX
//         0042fa9e     CALL       __ftol                                           undefined __ftol()
//         0042faa3     FLD        float ptr [ESI + 0x38]
//         0042faa6     PUSH       EAX
//         0042faa7     CALL       __ftol                                           undefined __ftol()
//         0042faac     MOV        this,dword ptr [ESI + 0xc]
//         0042faaf     PUSH       EAX
//         0042fab0     MOVSX      EDX,word ptr [ECX + this+0x4a]
//         0042fab4     MOV        this,dword ptr [VisibleUnitManager]              = 00000000
//         0042faba     PUSH       EDX
//         0042fabb     PUSH       EDI
//         0042fabc     CALL       Visible_Unit_Manager::Update_Unit_Info           void Update_Unit_Info(Visible_Unit_Manager *
//                               LAB_0042fac1                                                 XREF[1]:     0042fa81(j)
//         0042fac1     MOV        this,ESI
//                              com_obj.cpp:100 (30)
//         0042fac3     MOV        dword ptr [ESP + local_4],0xffffffff
//         0042facb     CALL       RGE_Action_Object::~RGE_Action_Object            void ~RGE_Action_Object(RGE_Action_Object * t
//         0042fad0     MOV        this,dword ptr [ESP + local_c]
//         0042fad4     POP        EDI
//         0042fad5     MOV        dword ptr FS:[0x0],this
//         0042fadc     POP        ESI
//         0042fadd     ADD        ESP,0x10
//         0042fae0     RET
//         0042fae1     ??         90h
//         0042fae2     NOP
//         0042fae3     NOP
//         0042fae4     NOP
//         0042fae5     NOP
//         0042fae6     NOP
//         0042fae7     NOP
//         0042fae8     NOP
//         0042fae9     NOP
//         0042faea     NOP
//         0042faeb     NOP
//         0042faec     NOP
//         0042faed     NOP
//         0042faee     NOP
//         0042faef     NOP
}

void RGE_Combat_Object::recycle_in_to_game(RGE_Master_Static_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5) {
    /* TODO: Stub */
//                              void __thiscall recycle_in_to_game(RGE_Combat_Object * this, RGE_Mas
//              void              <VOID>         <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              RGE_Master_Sta    Stack[0x4]:4   param_1                   XREF[1]:     0042fb1b(R)
//              RGE_Player *      Stack[0x8]:4   param_2                   XREF[1]:     0042fb16(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     0042faf3(R)
//              float             Stack[0x10]:4  param_4                   XREF[1]:     0042fb07(R)
//              float             Stack[0x14]:4  param_5                   XREF[1]:     0042fb11(R)
//                               ?recycle_in_to_game@RGE_Combat_Object@@UAEXPAVRGE_Master_St  XREF[4]:     0056f25c(*), 005706f4(*),
//                               RGE_Combat_Object::recycle_in_to_game                                     0057477c(*), 00574a24(*)
//                              com_obj.cpp:105 (3)
//         0042faf0     PUSH       ESI
//         0042faf1     MOV        ESI,this
//                              com_obj.cpp:109 (54)
//         0042faf3     MOV        EDX,dword ptr [ESP + param_3]
//         0042faf7     PUSH       EDI
//         0042faf8     LEA        EDI,[ESI + 0x194]
//         0042fafe     MOV        this,0x9
//         0042fb03     XOR        EAX,EAX
//         0042fb05     STOSD.REP  ES:EDI
//         0042fb07     MOV        this,dword ptr [ESP + param_4]
//         0042fb0b     MOV        dword ptr [ESI + 0x1b8],EAX
//         0042fb11     MOV        EAX,dword ptr [ESP + param_5]
//         0042fb15     PUSH       EAX
//         0042fb16     MOV        EAX,dword ptr [ESP + param_2]
//         0042fb1a     PUSH       this
//         0042fb1b     MOV        this,dword ptr [ESP + param_1]
//         0042fb1f     PUSH       EDX
//         0042fb20     PUSH       EAX
//         0042fb21     PUSH       this
//         0042fb22     MOV        this,ESI
//         0042fb24     CALL       RGE_Action_Object::recycle_in_to_game            void recycle_in_to_game(RGE_Action_Object * t
//                              com_obj.cpp:111 (3)
//         0042fb29     MOV        EDX,dword ptr [ESI + 0x8]
//                              com_obj.cpp:112 (17)
//         0042fb2c     POP        EDI
//         0042fb2d     FLD        float ptr [EDX + 0x120]
//         0042fb33     FSTP       float ptr [ESI + 0x1bc]
//         0042fb39     POP        ESI
//         0042fb3a     RET        0x14
//         0042fb3d     ??         90h
//         0042fb3e     NOP
//         0042fb3f     NOP
    return;
}

int RGE_Combat_Object::setup(RGE_Master_Combat_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5) {
    /* TODO: Stub */
//                              int __thiscall setup(RGE_Combat_Object * this, RGE_Master_Combat_Obj
//              int               EAX:4          <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              RGE_Master_Com    Stack[0x4]:4   param_1                   XREF[1]:     0042fb6b(R)
//              RGE_Player *      Stack[0x8]:4   param_2                   XREF[1]:     0042fb66(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     0042fb43(R)
//              float             Stack[0x10]:4  param_4                   XREF[1]:     0042fb57(R)
//              float             Stack[0x14]:4  param_5                   XREF[1]:     0042fb61(R)
//                               ?setup@RGE_Combat_Object@@MAEHPAVRGE_Master_Combat_Object@@  XREF[6]:     RGE_Combat_Object:0042f997(c),
//                               RGE_Combat_Object::setup                                                  setup:0045a88e(c),
//                                                                                                         setup:004ca31e(c), 0056f494(*),
//                                                                                                         005749b4(*), 00574c5c(*)
//                              com_obj.cpp:119 (3)
//         0042fb40     PUSH       ESI
//         0042fb41     MOV        ESI,this
//                              com_obj.cpp:124 (54)
//         0042fb43     MOV        EDX,dword ptr [ESP + param_3]
//         0042fb47     PUSH       EDI
//         0042fb48     LEA        EDI,[ESI + 0x194]
//         0042fb4e     MOV        this,0x9
//         0042fb53     XOR        EAX,EAX
//         0042fb55     STOSD.REP  ES:EDI
//         0042fb57     MOV        this,dword ptr [ESP + param_4]
//         0042fb5b     MOV        dword ptr [ESI + 0x1b8],EAX
//         0042fb61     MOV        EAX,dword ptr [ESP + param_5]
//         0042fb65     PUSH       EAX
//         0042fb66     MOV        EAX,dword ptr [ESP + param_2]
//         0042fb6a     PUSH       this
//         0042fb6b     MOV        this,dword ptr [ESP + param_1]
//         0042fb6f     PUSH       EDX
//         0042fb70     PUSH       EAX
//         0042fb71     PUSH       this
//         0042fb72     MOV        this,ESI
//         0042fb74     CALL       RGE_Action_Object::setup                         int setup(RGE_Action_Object * this, RGE_Maste
//                              com_obj.cpp:127 (7)
//         0042fb79     MOV        EDX,dword ptr [ESI + 0x8]
//         0042fb7c     MOV        byte ptr [ESI + 0x4e],0x32
//                              com_obj.cpp:130 (29)
//         0042fb80     POP        EDI
//         0042fb81     MOV        EAX,0x1
//         0042fb86     FLD        float ptr [EDX + 0x120]
//         0042fb8c     FSTP       float ptr [ESI + 0x1bc]
//         0042fb92     MOV        byte ptr [ESI + 0x1c0],0x0
//         0042fb99     POP        ESI
//         0042fb9a     RET        0x14
//         0042fb9d     ??         90h
//         0042fb9e     NOP
//         0042fb9f     NOP
    return 0;
}

int RGE_Combat_Object::setup(int param_1, RGE_Game_World* param_2) {
    /* TODO: Stub */
//                              int __thiscall setup(RGE_Combat_Object * this, int param_1, RGE_Game
//              int               EAX:4          <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0042fbb3(R)
//              RGE_Game_World    Stack[0x8]:4   param_2                   XREF[1]:     0042fbbd(R)
//                               ?setup@RGE_Combat_Object@@MAEHHPAVRGE_Game_World@@@Z         XREF[4]:     RGE_Combat_Object:0042fa2a(c),
//                               RGE_Combat_Object::setup                                                  setup:0045a8ae(c),
//                                                                                                         setup:004ca405(c), 0056f430(*)
//                              com_obj.cpp:136 (4)
//         0042fba0     PUSH       ESI
//         0042fba1     MOV        ESI,this
//         0042fba3     PUSH       EDI
//                              com_obj.cpp:137 (15)
//         0042fba4     MOV        this,0x9
//         0042fba9     LEA        EDI,[ESI + 0x194]
//         0042fbaf     XOR        EAX,EAX
//         0042fbb1     STOSD.REP  ES:EDI
//                              com_obj.cpp:140 (23)
//         0042fbb3     MOV        EDI,dword ptr [ESP + param_1]
//         0042fbb7     MOV        dword ptr [ESI + 0x1b8],EAX
//         0042fbbd     MOV        EAX,dword ptr [ESP + param_2]
//         0042fbc1     MOV        this,ESI
//         0042fbc3     PUSH       EAX
//         0042fbc4     PUSH       EDI
//         0042fbc5     CALL       RGE_Action_Object::setup                         int setup(RGE_Action_Object * this, int param
//                              com_obj.cpp:143 (19)
//         0042fbca     LEA        this,[ESI + 0x1bc]
//         0042fbd0     PUSH       0x4
//         0042fbd2     PUSH       this
//         0042fbd3     PUSH       EDI
//         0042fbd4     MOV        byte ptr [ESI + 0x4e],0x32
//         0042fbd8     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              com_obj.cpp:145 (22)
//         0042fbdd     FLD        float ptr [save_game_version]                    = 7.23
//         0042fbe3     FCOMP      float ptr [DAT_0056f498]                         = D7h
//         0042fbe9     ADD        ESP,0xc
//         0042fbec     FNSTSW     AX
//         0042fbee     TEST       AH,0x1
//         0042fbf1     JNZ        LAB_0042fc05
//                              com_obj.cpp:146 (18)
//         0042fbf3     ADD        ESI,0x1c0
//         0042fbf9     PUSH       0x1
//         0042fbfb     PUSH       ESI
//         0042fbfc     PUSH       EDI
//         0042fbfd     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0042fc02     ADD        ESP,0xc
//                               LAB_0042fc05                                                 XREF[1]:     0042fbf1(j)
//                              com_obj.cpp:149 (10)
//         0042fc05     POP        EDI
//         0042fc06     MOV        EAX,0x1
//         0042fc0b     POP        ESI
//         0042fc0c     RET        0x8
//         0042fc0f     ??         90h
    return 0;
}

void RGE_Combat_Object::save(int param_1) {
    /* TODO: Stub */
//                              void __thiscall save(RGE_Combat_Object * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0042fc12(R)
//                               ?save@RGE_Combat_Object@@UAEXH@Z                             XREF[3]:     save:0045a919(c),
//                               RGE_Combat_Object::save                                                   save:004ca57a(c), 0056f288(*)
//                              com_obj.cpp:155 (2)
//         0042fc10     PUSH       ESI
//         0042fc11     PUSH       EDI
//                              com_obj.cpp:156 (12)
//         0042fc12     MOV        EDI,dword ptr [ESP + param_1]
//         0042fc16     MOV        ESI,this
//         0042fc18     PUSH       EDI
//         0042fc19     CALL       RGE_Action_Object::save                          void save(RGE_Action_Object * this, int param
//                              com_obj.cpp:157 (18)
//         0042fc1e     LEA        EAX,[ESI + 0x1bc]
//         0042fc24     PUSH       0x4
//         0042fc26     PUSH       EAX
//         0042fc27     PUSH       EDI
//         0042fc28     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0042fc2d     ADD        ESP,0xc
//                              com_obj.cpp:158 (18)
//         0042fc30     ADD        ESI,0x1c0
//         0042fc36     PUSH       0x1
//         0042fc38     PUSH       ESI
//         0042fc39     PUSH       EDI
//         0042fc3a     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0042fc3f     ADD        ESP,0xc
//                              com_obj.cpp:159 (5)
//         0042fc42     POP        EDI
//         0042fc43     POP        ESI
//         0042fc44     RET        0x4
//         0042fc47     ??         90h
//         0042fc48     NOP
//         0042fc49     NOP
//         0042fc4a     NOP
//         0042fc4b     NOP
//         0042fc4c     NOP
//         0042fc4d     NOP
//         0042fc4e     NOP
//         0042fc4f     NOP
    return;
}

void RGE_Combat_Object::stop() {
    /* TODO: Stub */
//                              void __thiscall stop(RGE_Combat_Object * this)
//              void              <VOID>         <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//                               ?stop@RGE_Combat_Object@@UAEXXZ                              XREF[4]:     stop:004ca0b3(c), 0056f2fc(*),
//                               RGE_Combat_Object::stop                                                   00570794(*), 00574ac4(*)
//                              com_obj.cpp:164 (3)
//         0042fc50     PUSH       ESI
//         0042fc51     MOV        ESI,this
//                              com_obj.cpp:166 (5)
//         0042fc53     CALL       RGE_Action_Object::stop                          void stop(RGE_Action_Object * this)
//                              com_obj.cpp:168 (7)
//         0042fc58     MOV        EAX,dword ptr [ESI + 0x74]
//         0042fc5b     TEST       EAX,EAX
//         0042fc5d     JZ         LAB_0042fc8e
//                              com_obj.cpp:171 (37)
//         0042fc5f     MOV        EAX,[actionFile]                                 = 00000000
//         0042fc64     TEST       EAX,EAX
//         0042fc66     JZ         LAB_0042fc84
//         0042fc68     MOV        this,dword ptr [ESI + 0x4]
//         0042fc6b     PUSH       0xab
//         0042fc70     PUSH       s_C:\msdev\work\age1_x1\com_obj.cp               = "C:\\msdev\\work\\age1_x1\\com_obj.cpp"
//         0042fc75     PUSH       this
//         0042fc76     PUSH       s_#%d_call_stopObject_%s_%d_                     = "#%d call stopObject %s %d\n"
//         0042fc7b     PUSH       EAX
//         0042fc7c     CALL       fprintf                                          undefined fprintf()
//         0042fc81     ADD        ESP,0x14
//                               LAB_0042fc84                                                 XREF[1]:     0042fc66(j)
//                              com_obj.cpp:173 (10)
//         0042fc84     MOV        this,dword ptr [ESI + 0x74]
//         0042fc87     PUSH       0x1
//         0042fc89     MOV        EDX,dword ptr [this->_padding_]
//         0042fc8b     CALL       dword ptr [EDX + 0x58]
//                               LAB_0042fc8e                                                 XREF[1]:     0042fc5d(j)
//                              com_obj.cpp:175 (2)
//         0042fc8e     POP        ESI
//         0042fc8f     RET
    return;
}

float RGE_Combat_Object::calc_attack_modifier(RGE_Static_Object* param_1) {
    /* TODO: Stub */
//                              float __thiscall calc_attack_modifier(RGE_Combat_Object * this, RGE_
//              float             ST0:10         <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1
//                               ?calc_attack_modifier@RGE_Combat_Object@@UAEMPAVRGE_Static_  XREF[2]:     0056f348(*), 005707e0(*)
//                               RGE_Combat_Object::calc_attack_modifier
//                              com_obj.cpp:179 (6)
//         0042fc90     FLD        float ptr [DAT_0056f49c]
//                              com_obj.cpp:183 (3)
//         0042fc96     RET        0x4
//         0042fc99     ??         90h
//         0042fc9a     NOP
//         0042fc9b     NOP
//         0042fc9c     NOP
//         0042fc9d     NOP
//         0042fc9e     NOP
//         0042fc9f     NOP
    return 0;
}

uchar RGE_Combat_Object::area_attack(float param_1, float param_2, float param_3, RGE_Combat_Object* param_4, RGE_Static_Object* param_5) {
    /* TODO: Stub */
//                              uchar __thiscall area_attack(RGE_Combat_Object * this, float param_1
//              uchar             AL:1           <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1                   XREF[3]:     0042fcec(R), 0042fcfa(R), 0042fdf4(R)
//              float             Stack[0x8]:4   param_2                   XREF[3]:     0042fd0a(R), 0042fd1c(R), 0042fdfb(R)
//              float             Stack[0xc]:4   param_3
//              RGE_Combat_Obj    Stack[0x10]:4  param_4
//              RGE_Static_Obj    Stack[0x14]:4  param_5                   XREF[1]:     0042fde7(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0042fcca(W), 0042fe7f(R)
//              float             Stack[-0x8]:4  r2                        XREF[2]:     0042fcbe(W), 0042fda8(R)
//              RGE_Map *         Stack[-0xc]:4  map                       XREF[3]:     0042fd81(W), 0042ff29(R), 0042ff35(W)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[3]:     0042fda4(W), 0042ff13(R), 0042ff1b(W)
//              undefined4        Stack[-0x14]:4 local_14                  XREF[3]:     0042fe39(W), 0042fe5c(R), 0042fe6b(R)
//              float             Stack[-0x18]:4 ry                        XREF[4]:     0042fd7d(W), 0042fdac(R), 0042ff25(R), 0042ff31(W)
//              undefined4        Stack[-0x1c]:4 local_1c                  XREF[4]:     0042fd13(W), 0042fd3e(R), 0042fd4c(W), 0042fd89(R)
//              short             Stack[-0x20]:2 x1                        XREF[4]:     0042fd01(W), 0042fd2e(R), 0042fd36(W), 0042fd85(R)
//              short             Stack[-0x24]:2 x0                        XREF[6]:     0042fe07(W), 0042fe14(R), 0042fe25(R), 0042fe2b(W),
//                                                                                     0042fe58(R), 0042fe67(R)
//              float             Stack[-0x28]:4 attack_modifier
//                               ?area_attack@RGE_Combat_Object@@UAEEMMMPAV1@PAVRGE_Static_O  XREF[2]:     0056f474(*), 0057090c(*)
//                               RGE_Combat_Object::area_attack
//                              com_obj.cpp:191 (8)
//         0042fca0     SUB        ESP,0x24
//         0042fca3     PUSH       EBX
//         0042fca4     PUSH       EBP
//         0042fca5     PUSH       ESI
//         0042fca6     MOV        ESI,this
//                              com_obj.cpp:202 (15)
//         0042fca8     MOV        EDX,dword ptr [ESI + 0x8]
//         0042fcab     MOV        EAX,dword ptr [ESI + 0xc]
//         0042fcae     FLD        float ptr [EDX + 0x118]
//         0042fcb4     MOV        this,dword ptr [EAX + 0x3c]
//                              com_obj.cpp:208 (27)
//         0042fcb7     FLD        ST0
//         0042fcb9     FMUL       ST1
//         0042fcbb     MOV        EAX,dword ptr [ECX + this->_padding_]
//         0042fcbe     MOV        dword ptr [ESP + r2],EAX
//         0042fcc2     MOV        BX,word ptr [EAX + 0x8]
//         0042fcc6     MOV        BP,word ptr [EAX + 0xc]
//         0042fcca     FSTP       float ptr [ESP + local_4]
//         0042fcce     DEC        BX
//         0042fcd0     DEC        BP
//                              com_obj.cpp:214 (15)
//         0042fcd2     FCOM       double ptr [DAT_0056f4a0]
//         0042fcd8     FNSTSW     AX
//         0042fcda     TEST       AH,0x41
//         0042fcdd     JZ         LAB_0042fcec
//         0042fcdf     FSTP       ST0
//                              com_obj.cpp:215 (2)
//         0042fce1     XOR        AL,AL
//                              com_obj.cpp:262 (9)
//         0042fce3     POP        ESI
//         0042fce4     POP        EBP
//         0042fce5     POP        EBX
//         0042fce6     ADD        ESP,0x24
//         0042fce9     RET        0x14
//                               LAB_0042fcec                                                 XREF[1]:     0042fcdd(j)
//                              com_obj.cpp:217 (12)
//         0042fcec     FLD        float ptr [ESP + param_1]
//         0042fcf0     FSUB       ST0,ST1
//         0042fcf2     PUSH       EDI
//         0042fcf3     CALL       __ftol                                           undefined __ftol()
//                              com_obj.cpp:218 (18)
//         0042fcf8     FLD        ST0
//         0042fcfa     FADD       float ptr [ESP + param_1]
//         0042fcfe     SUB        EAX,0x2
//         0042fd01     MOV        dword ptr [ESP + x1],EAX
//         0042fd05     CALL       __ftol                                           undefined __ftol()
//                              com_obj.cpp:219 (18)
//         0042fd0a     FLD        float ptr [ESP + param_2]
//         0042fd0e     FSUB       ST0,ST1
//         0042fd10     ADD        EAX,0x2
//         0042fd13     MOV        dword ptr [ESP + local_1c],EAX
//         0042fd17     CALL       __ftol                                           undefined __ftol()
//                              com_obj.cpp:220 (18)
//         0042fd1c     FADD       float ptr [ESP + param_2]
//         0042fd20     MOV        DI,AX
//         0042fd23     SUB        EDI,0x2
//         0042fd26     CALL       __ftol                                           undefined __ftol()
//         0042fd2b     ADD        EAX,0x2
//                              com_obj.cpp:222 (16)
//         0042fd2e     CMP        word ptr [ESP + x1],0x0
//         0042fd34     JGE        LAB_0042fd3e
//         0042fd36     MOV        dword ptr [ESP + x1],0x0
//                               LAB_0042fd3e                                                 XREF[1]:     0042fd34(j)
//                              com_obj.cpp:223 (18)
//         0042fd3e     MOVSX      EDX,word ptr [ESP + local_1c]
//         0042fd43     MOVSX      this,BX
//         0042fd46     INC        this
//         0042fd47     CMP        EDX,this
//         0042fd49     JLE        LAB_0042fd50
//         0042fd4b     INC        EBX
//         0042fd4c     MOV        dword ptr [ESP + local_1c],EBX
//                               LAB_0042fd50                                                 XREF[1]:     0042fd49(j)
//                              com_obj.cpp:224 (7)
//         0042fd50     TEST       DI,DI
//         0042fd53     JGE        LAB_0042fd57
//         0042fd55     XOR        EDI,EDI
//                               LAB_0042fd57                                                 XREF[1]:     0042fd53(j)
//                              com_obj.cpp:225 (14)
//         0042fd57     MOVSX      this,BP
//         0042fd5a     MOVSX      EDX,AX
//         0042fd5d     INC        this
//         0042fd5e     CMP        EDX,this
//         0042fd60     JLE        LAB_0042fd65
//         0042fd62     LEA        EAX,[EBP + 0x1]
//                               LAB_0042fd65                                                 XREF[1]:     0042fd60(j)
//                              com_obj.cpp:227 (32)
//         0042fd65     CMP        DI,AX
//         0042fd68     JGE        LAB_0042ff3f
//         0042fd6e     MOVSX      this,DI
//         0042fd71     MOVSX      EAX,AX
//         0042fd74     LEA        EDX,[this->_padding_*0x4 + 0x0]
//         0042fd7b     SUB        EAX,this
//         0042fd7d     MOV        dword ptr [ESP + ry],EDX
//         0042fd81     MOV        dword ptr [ESP + map],EAX
//                               LAB_0042fd85                                                 XREF[1]:     0042ff39(j)
//                              com_obj.cpp:228 (35)
//         0042fd85     MOV        EAX,dword ptr [ESP + x1]
//         0042fd89     MOV        this,dword ptr [ESP + local_1c]
//         0042fd8d     CMP        AX,this
//         0042fd90     JGE        LAB_0042ff25
//         0042fd96     MOVSX      EAX,AX
//         0042fd99     MOVSX      this,this
//         0042fd9c     LEA        EBP,[EAX + EAX*0x2]
//         0042fd9f     SHL        EBP,0x3
//         0042fda2     SUB        this,EAX
//         0042fda4     MOV        dword ptr [ESP + local_10],this
//                               LAB_0042fda8                                                 XREF[1]:     0042ff1f(j)
//                              com_obj.cpp:229 (29)
//         0042fda8     MOV        EAX,dword ptr [ESP + r2]
//         0042fdac     MOV        EDX,dword ptr [ESP + ry]
//         0042fdb0     MOV        this,dword ptr [EAX + 0x8d8c]
//         0042fdb6     MOV        EAX,dword ptr [EDX + this->_padding_*0x1]
//         0042fdb9     MOV        EBX,dword ptr [EAX + EBP*0x1 + 0x10]
//         0042fdbd     TEST       EBX,EBX
//         0042fdbf     JZ         LAB_0042ff13
//                               LAB_0042fdc5                                                 XREF[1]:     0042ff0d(j)
//                              com_obj.cpp:232 (2)
//         0042fdc5     MOV        EDI,dword ptr [EBX]
//                              com_obj.cpp:233 (32)
//         0042fdc7     CMP        EDI,ESI
//         0042fdc9     JZ         LAB_0042ff08
//         0042fdcf     MOV        this,dword ptr [EDI + 0x8]
//         0042fdd2     MOV        EDX,dword ptr [ESI + 0x8]
//         0042fdd5     MOV        AL,byte ptr [ECX + this+0x8b]
//         0042fddb     CMP        AL,byte ptr [EDX + 0x11c]
//         0042fde1     JC         LAB_0042ff08
//                              com_obj.cpp:235 (10)
//         0042fde7     CMP        EDI,dword ptr [ESP + param_5]
//         0042fdeb     JZ         LAB_0042ff08
//                              com_obj.cpp:238 (7)
//         0042fdf1     FLD        float ptr [EDI + 0x38]
//         0042fdf4     FSUB       float ptr [ESP + param_1]
//                              com_obj.cpp:239 (7)
//         0042fdf8     FLD        float ptr [EDI + 0x3c]
//         0042fdfb     FSUB       float ptr [ESP + param_2]
//                              com_obj.cpp:241 (21)
//         0042fdff     FLD        ST1
//         0042fe01     FCOMP      float ptr [DAT_0056f4a8]
//         0042fe07     FSTP       float ptr [ESP + x0]
//         0042fe0b     FNSTSW     AX
//         0042fe0d     TEST       AH,0x1
//         0042fe10     JZ         LAB_0042fe14
//         0042fe12     FCHS
//                               LAB_0042fe14                                                 XREF[1]:     0042fe10(j)
//                              com_obj.cpp:242 (27)
//         0042fe14     FLD        float ptr [ESP + x0]
//         0042fe18     FCOMP      float ptr [DAT_0056f4a8]
//         0042fe1e     FNSTSW     AX
//         0042fe20     TEST       AH,0x1
//         0042fe23     JZ         LAB_0042fe2f
//         0042fe25     FLD        float ptr [ESP + x0]
//         0042fe29     FCHS
//         0042fe2b     FSTP       float ptr [ESP + x0]
//                               LAB_0042fe2f                                                 XREF[1]:     0042fe23(j)
//                              com_obj.cpp:243 (3)
//         0042fe2f     FLD        float ptr [ECX + this->_padding_]
//                              com_obj.cpp:245 (38)
//         0042fe32     FLD        ST1
//         0042fe34     MOV        this,dword ptr [ECX + this->_padding_]
//         0042fe37     FCOMP
//         0042fe39     MOV        dword ptr [ESP + local_14],this
//         0042fe3d     FNSTSW     AX
//         0042fe3f     TEST       AH,0x41
//         0042fe42     JNZ        LAB_0042fe4e
//         0042fe44     FXCH
//         0042fe46     FSUB       ST0,ST1
//         0042fe48     FXCH
//         0042fe4a     FSTP       ST0
//         0042fe4c     JMP        LAB_0042fe58
//                               LAB_0042fe4e                                                 XREF[1]:     0042fe42(j)
//         0042fe4e     FSTP       ST0
//         0042fe50     FSTP       ST0
//         0042fe52     FLD        float ptr [DAT_0056f4a8]
//                               LAB_0042fe58                                                 XREF[1]:     0042fe4c(j)
//                              com_obj.cpp:246 (31)
//         0042fe58     FLD        float ptr [ESP + x0]
//         0042fe5c     FCOMP      float ptr [ESP + local_14]
//         0042fe60     FNSTSW     AX
//         0042fe62     TEST       AH,0x41
//         0042fe65     JNZ        LAB_0042fe71
//         0042fe67     FLD        float ptr [ESP + x0]
//         0042fe6b     FSUB       float ptr [ESP + local_14]
//         0042fe6f     JMP        LAB_0042fe77
//                               LAB_0042fe71                                                 XREF[1]:     0042fe65(j)
//         0042fe71     FLD        float ptr [DAT_0056f4a8]
//                               LAB_0042fe77                                                 XREF[1]:     0042fe6f(j)
//                              com_obj.cpp:248 (33)
//         0042fe77     FLD        ST1
//         0042fe79     FLD        ST1
//         0042fe7b     FXCH
//         0042fe7d     FMUL       ST3
//         0042fe7f     FLD        float ptr [ESP + local_4]
//         0042fe83     FXCH       ST2
//         0042fe85     FMUL       ST3
//         0042fe87     FADDP
//         0042fe89     FXCH
//         0042fe8b     FCOMPP
//         0042fe8d     FNSTSW     AX
//         0042fe8f     FSTP       ST0
//         0042fe91     TEST       AH,0x41
//         0042fe94     FSTP       ST0
//         0042fe96     JNZ        LAB_0042ff08
//                              com_obj.cpp:250 (36)
//         0042fe98     PUSH       0xfa
//         0042fe9d     PUSH       s_C:\msdev\work\age1_x1\com_obj.cp               = "C:\\msdev\\work\\age1_x1\\com_obj.cpp"
//         0042fea2     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         0042fea7     LEA        EAX,[EAX + EAX*0x4]
//         0042feaa     ADD        ESP,0x8
//         0042fead     LEA        this,[EAX + EAX*0x4]
//         0042feb0     MOV        EAX,0x80010003
//         0042feb5     SHL        this,0x2
//         0042feb8     IMUL       this
//         0042feba     ADD        EDX,this
//                              com_obj.cpp:251 (22)
//         0042febc     MOV        this,dword ptr [ESI + 0x8]
//         0042febf     SAR        EDX,0xe
//         0042fec2     MOV        EAX,EDX
//         0042fec4     SHR        EAX,0x1f
//         0042fec7     ADD        EDX,EAX
//         0042fec9     CMP        DX,word ptr [ECX + this+0x126]
//         0042fed0     JG         LAB_0042ff08
//                              com_obj.cpp:253 (11)
//         0042fed2     MOV        EDX,dword ptr [ESI]
//         0042fed4     PUSH       EDI
//         0042fed5     MOV        this,ESI
//         0042fed7     CALL       dword ptr [EDX + 0xf0]
//                              com_obj.cpp:255 (54)
//         0042fedd     MOV        this,dword ptr [ESP + 0x44]
//         0042fee1     MOV        EAX,dword ptr [ESI + 0x8]
//         0042fee4     FSTP       float ptr [ESP + 0x10]
//         0042fee8     PUSH       this
//         0042fee9     MOV        this,dword ptr [ESI + 0xc]
//         0042feec     MOV        EDX,dword ptr [EDI]
//         0042feee     PUSH       this=>DAT_fffffff8
//         0042feef     MOV        this,dword ptr [ESP + 0x18]
//         0042fef3     PUSH       this=>DAT_fffffff4
//         0042fef4     MOV        this,dword ptr [EAX + 0x10c]
//         0042fefa     MOVSX      EAX,word ptr [EAX + 0x108]
//         0042ff01     PUSH       this=>DAT_fffffff0
//         0042ff02     PUSH       EAX
//         0042ff03     MOV        this,EDI
//         0042ff05     CALL       dword ptr [EDX + 0x70]
//                               LAB_0042ff08                                                 XREF[5]:     0042fdc9(j), 0042fde1(j),
//                                                                                                         0042fdeb(j), 0042fe96(j),
//                                                                                                         0042fed0(j)
//         0042ff08     MOV        EBX,dword ptr [EBX + 0x4]
//         0042ff0b     TEST       EBX,EBX
//         0042ff0d     JNZ        LAB_0042fdc5
//                               LAB_0042ff13                                                 XREF[1]:     0042fdbf(j)
//                              com_obj.cpp:228 (18)
//         0042ff13     MOV        EAX,dword ptr [ESP + local_10]
//         0042ff17     ADD        EBP,0x18
//         0042ff1a     DEC        EAX
//         0042ff1b     MOV        dword ptr [ESP + local_10],EAX
//         0042ff1f     JNZ        LAB_0042fda8
//                               LAB_0042ff25                                                 XREF[1]:     0042fd90(j)
//                              com_obj.cpp:227 (26)
//         0042ff25     MOV        this,dword ptr [ESP + ry]
//         0042ff29     MOV        EAX,dword ptr [ESP + map]
//         0042ff2d     ADD        this,0x4
//         0042ff30     DEC        EAX
//         0042ff31     MOV        dword ptr [ESP + ry],this
//         0042ff35     MOV        dword ptr [ESP + map],EAX
//         0042ff39     JNZ        LAB_0042fd85
//                               LAB_0042ff3f                                                 XREF[1]:     0042fd68(j)
//                              com_obj.cpp:191 (1)
//         0042ff3f     POP        EDI
//                              com_obj.cpp:262 (11)
//         0042ff40     POP        ESI
//         0042ff41     POP        EBP
//         0042ff42     MOV        AL,0x1
//         0042ff44     POP        EBX
//         0042ff45     ADD        ESP,0x24
//         0042ff48     RET        0x14
//         0042ff4b     ??         90h
//         0042ff4c     NOP
//         0042ff4d     NOP
//         0042ff4e     NOP
//         0042ff4f     NOP
    return 0;
}

uchar RGE_Combat_Object::do_attack(RGE_Static_Object* param_1, RGE_Combat_Object* param_2, float param_3, float param_4, float param_5) {
    /* TODO: Stub */
//                              uchar __thiscall do_attack(RGE_Combat_Object * this, RGE_Static_Obje
//              uchar             AL:1           <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00430233(R)
//              RGE_Combat_Obj    Stack[0x8]:4   param_2                   XREF[1]:     0043025b(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     0043026d(R)
//              float             Stack[0x10]:4  param_4                   XREF[1]:     00430268(R)
//              float             Stack[0x14]:4  param_5                   XREF[1]:     0043025f(R)
//                               ?do_attack@RGE_Combat_Object@@UAEEPAVRGE_Static_Object@@PAV  XREF[3]:     do_attack:004cac01(c),
//                               RGE_Combat_Object::do_attack                                              0056f480(*), 00570918(*)
//                              com_obj.cpp:361 (3)
//         00430230     PUSH       EBX
//         00430231     PUSH       ESI
//         00430232     PUSH       EDI
//                              com_obj.cpp:366 (10)
//         00430233     MOV        EDI,dword ptr [ESP + param_1]
//         00430237     TEST       EDI,EDI
//         00430239     MOV        ESI,this
//         0043023b     JNZ        LAB_00430245
//                              com_obj.cpp:367 (2)
//         0043023d     XOR        AL,AL
//                              com_obj.cpp:390 (6)
//         0043023f     POP        EDI
//         00430240     POP        ESI
//         00430241     POP        EBX
//         00430242     RET        0x14
//                               LAB_00430245                                                 XREF[1]:     0043023b(j)
//                              com_obj.cpp:369 (22)
//         00430245     MOV        EAX,dword ptr [ESI + 0x8]
//         00430248     FLD        float ptr [EAX + 0x118]
//         0043024e     FCOMP      float ptr [DAT_0056f4a8]
//         00430254     FNSTSW     AX
//         00430256     TEST       AH,0x41
//         00430259     JNZ        LAB_00430283
//                              com_obj.cpp:371 (32)
//         0043025b     MOV        EAX,dword ptr [ESP + param_2]
//         0043025f     MOV        this,dword ptr [ESP + param_5]
//         00430263     MOV        EDX,dword ptr [ESI]
//         00430265     PUSH       0x0
//         00430267     PUSH       EAX
//         00430268     MOV        EAX,dword ptr [ESP + param_4]
//         0043026c     PUSH       this
//         0043026d     MOV        this,dword ptr [ESP + param_3]
//         00430271     PUSH       EAX
//         00430272     PUSH       this
//         00430273     MOV        this,ESI
//         00430275     CALL       dword ptr [EDX + 0x21c]
//                              com_obj.cpp:389 (2)
//         0043027b     MOV        AL,0x1
//                              com_obj.cpp:390 (6)
//         0043027d     POP        EDI
//         0043027e     POP        ESI
//         0043027f     POP        EBX
//         00430280     RET        0x14
//                               LAB_00430283                                                 XREF[1]:     00430259(j)
//                              com_obj.cpp:376 (31)
//         00430283     MOV        EDX,dword ptr [EDI + 0x4]
//         00430286     MOV        EAX,dword ptr [ESI + 0x4]
//         00430289     MOV        EBX,dword ptr [ESI]
//         0043028b     PUSH       0x0
//         0043028d     PUSH       EDX
//         0043028e     PUSH       0x258
//         00430293     PUSH       0x200
//         00430298     PUSH       EAX
//         00430299     PUSH       EAX
//         0043029a     MOV        this,ESI
//         0043029c     CALL       dword ptr [EBX + 0x148]
//                              com_obj.cpp:379 (36)
//         004302a2     PUSH       0x17b
//         004302a7     PUSH       s_C:\msdev\work\age1_x1\com_obj.cp               = "C:\\msdev\\work\\age1_x1\\com_obj.cpp"
//         004302ac     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         004302b1     LEA        EAX,[EAX + EAX*0x4]
//         004302b4     ADD        ESP,0x8
//         004302b7     LEA        this,[EAX + EAX*0x4]
//         004302ba     MOV        EAX,0x80010003
//         004302bf     SHL        this,0x2
//         004302c2     IMUL       this
//         004302c4     ADD        EDX,this
//                              com_obj.cpp:380 (24)
//         004302c6     MOV        this,dword ptr [ESI + 0x8]
//         004302c9     SAR        EDX,0xe
//         004302cc     MOV        EAX,EDX
//         004302ce     SHR        EAX,0x1f
//         004302d1     ADD        EDX,EAX
//         004302d3     MOVSX      EAX,word ptr [ECX + this+0x126]
//         004302da     CMP        EDX,EAX
//         004302dc     JG         LAB_00430312
//                              com_obj.cpp:382 (9)
//         004302de     PUSH       EDI
//         004302df     MOV        this,ESI
//         004302e1     CALL       dword ptr [EBX + 0xf0]
//                              com_obj.cpp:386 (43)
//         004302e7     MOV        this,dword ptr [ESP + 0x14]
//         004302eb     MOV        EAX,dword ptr [ESI + 0x8]
//         004302ee     FSTP       float ptr [ESP + 0x10]
//         004302f2     PUSH       this
//         004302f3     MOV        this,dword ptr [ESI + 0xc]
//         004302f6     MOV        EDX,dword ptr [EDI]
//         004302f8     PUSH       this=>DAT_fffffff8
//         004302f9     MOV        this,dword ptr [ESP + 0x18]
//         004302fd     PUSH       this=>DAT_fffffff4
//         004302fe     MOV        this,dword ptr [EAX + 0x10c]
//         00430304     MOVSX      EAX,word ptr [EAX + 0x108]
//         0043030b     PUSH       this=>DAT_fffffff0
//         0043030c     PUSH       EAX
//         0043030d     MOV        this,EDI
//         0043030f     CALL       dword ptr [EDX + 0x70]
//                               LAB_00430312                                                 XREF[1]:     004302dc(j)
//                              com_obj.cpp:390 (8)
//         00430312     POP        EDI
//         00430313     POP        ESI
//         00430314     MOV        AL,0x1
//         00430316     POP        EBX
//         00430317     RET        0x14
//         0043031a     ??         90h
//         0043031b     NOP
//         0043031c     NOP
//         0043031d     NOP
//         0043031e     NOP
//         0043031f     NOP
    return 0;
}

void RGE_Combat_Object::damage(int param_1, RGE_Armor_Weapon_Info* param_2, float param_3, RGE_Player* param_4, RGE_Static_Object* param_5) {
    /* TODO: Stub */
//                              void __thiscall damage(RGE_Combat_Object * this, int param_1, RGE_Ar
//              void              <VOID>         <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00430337(R)
//              RGE_Armor_Weap    Stack[0x8]:4   param_2                   XREF[1]:     00430324(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     00430332(R)
//              RGE_Player *      Stack[0x10]:4  param_4                   XREF[1]:     00430320(R)
//              RGE_Static_Obj    Stack[0x14]:4  param_5                   XREF[1]:     0043032b(R)
//                               ?damage@RGE_Combat_Object@@UAEXHPAURGE_Armor_Weapon_Info@@M  XREF[4]:     damage:004c97ac(c),
//                               RGE_Combat_Object::damage                                                 damage:004ca82d(c), 0056f2c8(*),
//                                                                                                         00570760(*)
//                              com_obj.cpp:398 (40)
//         00430320     MOV        EAX,dword ptr [ESP + param_4]
//         00430324     MOV        EDX,dword ptr [ESP + param_2]
//         00430328     PUSH       EBX
//         00430329     PUSH       ESI
//         0043032a     PUSH       EDI
//         0043032b     MOV        EDI,dword ptr [ESP + param_5]
//         0043032f     MOV        ESI,this
//         00430331     PUSH       EDI
//         00430332     MOV        this,dword ptr [ESP + param_3]
//         00430336     PUSH       EAX
//         00430337     MOV        EAX,dword ptr [ESP + param_1]
//         0043033b     MOV        EBX,dword ptr [ESI]
//         0043033d     PUSH       this
//         0043033e     PUSH       EDX
//         0043033f     PUSH       EAX
//         00430340     MOV        this,ESI
//         00430342     CALL       dword ptr [EBX + 0x74]
//         00430345     FSUBR      float ptr [ESI + 0x30]
//                              com_obj.cpp:407 (7)
//         00430348     TEST       EDI,EDI
//         0043034a     FST        float ptr [ESI + 0x30]
//         0043034d     JZ         LAB_00430375
//                              com_obj.cpp:414 (38)
//         0043034f     MOV        this,dword ptr [ESI + 0x8]
//         00430352     MOV        EDI,dword ptr [EDI + 0x4]
//         00430355     MOVSX      EDX,word ptr [ECX + this+0x26]
//         00430359     PUSH       EDX
//         0043035a     CALL       __ftol                                           undefined __ftol()
//         0043035f     PUSH       EAX=>DAT_fffffff8
//         00430360     MOV        EAX,dword ptr [ESI + 0x4]
//         00430363     PUSH       EDI=>DAT_fffffff4
//         00430364     PUSH       offset DAT_fffffff0
//         00430369     PUSH       EAX
//         0043036a     PUSH       EDI
//         0043036b     MOV        this,ESI
//         0043036d     CALL       dword ptr [EBX + 0x148]
//         00430373     JMP        LAB_00430377
//                               LAB_00430375                                                 XREF[1]:     0043034d(j)
//                              com_obj.cpp:404 (2)
//         00430375     FSTP       ST0
//                               LAB_00430377                                                 XREF[1]:     00430373(j)
//                              com_obj.cpp:419 (16)
//         00430377     FLD        float ptr [ESI + 0x30]
//         0043037a     FCOMP      double ptr [DAT_0056f4b0]
//         00430380     FNSTSW     AX
//         00430382     TEST       AH,0x1
//         00430385     JZ         LAB_0043038e
//                              com_obj.cpp:420 (7)
//         00430387     MOV        dword ptr [ESI + 0x30],0x0
//                               LAB_0043038e                                                 XREF[1]:     00430385(j)
//                              com_obj.cpp:425 (6)
//         0043038e     POP        EDI
//         0043038f     POP        ESI
//         00430390     POP        EBX
//         00430391     RET        0x14
//         00430394     ??         90h
//         00430395     NOP
//         00430396     NOP
//         00430397     NOP
//         00430398     NOP
//         00430399     NOP
//         0043039a     NOP
//         0043039b     NOP
//         0043039c     NOP
//         0043039d     NOP
//         0043039e     NOP
//         0043039f     NOP
    return;
}

float RGE_Combat_Object::calculateDamage(int param_1, RGE_Armor_Weapon_Info* param_2, float param_3, RGE_Player* param_4, RGE_Static_Object* param_5) {
    /* TODO: Stub */
//                              float __thiscall calculateDamage(RGE_Combat_Object * this, int param
//              float             ST0:10         <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[6]:     004303e8(R), 00430410(W), 00430426(W), 00430434(R),
//                                                                                     00430438(W), 0043043c(R)
//              RGE_Armor_Weap    Stack[0x8]:4   param_2                   XREF[4]:     004303f6(R), 00430402(W), 0043045d(R), 00430465(W)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     00430446(R)
//              RGE_Player *      Stack[0x10]:4  param_4
//              RGE_Static_Obj    Stack[0x14]:4  param_5
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00430406(W), 0043040a(R)
//                               ?calculateDamage@RGE_Combat_Object@@UAEMHPAURGE_Armor_Weapo  XREF[4]:     0056f2cc(*), 00570764(*),
//                               RGE_Combat_Object::calculateDamage                                        005747ec(*), 00574a94(*)
//                              com_obj.cpp:433 (1)
//         004303a0     PUSH       this
//                              com_obj.cpp:435 (4)
//         004303a1     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004303a4     PUSH       EBX
//                              com_obj.cpp:439 (6)
//         004303a5     FLD        float ptr [DAT_0056f49c]
//                              com_obj.cpp:441 (35)
//         004303ab     MOV        DX,word ptr [EAX + 0x110]
//         004303b2     PUSH       EBP
//         004303b3     MOV        EBP,dword ptr [EAX + 0x104]
//         004303b9     PUSH       ESI
//         004303ba     PUSH       EDI
//         004303bb     MOVSX      EDI,word ptr [EAX + 0x102]
//         004303c2     TEST       DX,DX
//         004303c5     JL         LAB_004303e8
//         004303c7     MOV        ESI,dword ptr [ECX + this->_padding_]
//         004303ca     TEST       ESI,ESI
//         004303cc     JZ         LAB_004303e8
//                              com_obj.cpp:442 (26)
//         004303ce     MOV        this,dword ptr [ECX + this->_padding_]
//         004303d1     MOV        BL,byte ptr [ESI + 0x5]
//         004303d4     MOVSX      EDX,DX
//         004303d7     FSTP       ST0
//         004303d9     MOV        this,dword ptr [ECX + this->_padding_]
//         004303dc     AND        EBX,0x1f
//         004303df     MOV        this,dword ptr [ECX + this->_padding_]
//         004303e2     MOV        EDX,dword ptr [this->_padding_ + EDX*0x4]
//         004303e5     FLD        float ptr [EDX + EBX*0x4]
//                               LAB_004303e8                                                 XREF[2]:     004303c5(j), 004303cc(j)
//                              com_obj.cpp:445 (18)
//         004303e8     MOV        this,dword ptr [ESP + param_1]
//         004303ec     FLD        float ptr [DAT_0056f4a8]
//         004303f2     TEST       this,this
//         004303f4     JLE        LAB_0043046b
//         004303f6     MOV        ESI,dword ptr [ESP + param_2]
//                              com_obj.cpp:448 (20)
//         004303fa     XOR        EDX,EDX
//         004303fc     MOV        DL,byte ptr [EAX + 0x100]
//         00430402     MOV        dword ptr [ESP + param_2],this
//         00430406     MOV        dword ptr [ESP + local_4],EDX
//                               LAB_0043040a                                                 XREF[1]:     00430469(j)
//         0043040a     MOV        EAX,dword ptr [ESP + local_4]
//                              com_obj.cpp:449 (8)
//         0043040e     TEST       EDI,EDI
//         00430410     MOV        dword ptr [ESP + param_1],EAX
//         00430414     JLE        LAB_00430430
//                              com_obj.cpp:450 (12)
//         00430416     MOV        DX,word ptr [ESI]
//         00430419     MOV        EAX,EBP
//         0043041b     MOV        this,EDI
//                               LAB_0043041d                                                 XREF[1]:     0043042e(j)
//         0043041d     CMP        word ptr [EAX],DX
//         00430420     JNZ        LAB_0043042a
//                              com_obj.cpp:451 (14)
//         00430422     MOVSX      EBX,word ptr [EAX + 0x2]
//         00430426     MOV        dword ptr [ESP + param_1],EBX
//                               LAB_0043042a                                                 XREF[1]:     00430420(j)
//         0043042a     ADD        EAX,0x4
//         0043042d     DEC        this
//         0043042e     JNZ        LAB_0043041d
//                               LAB_00430430                                                 XREF[1]:     00430414(j)
//                              com_obj.cpp:461 (26)
//         00430430     MOVSX      this,word ptr [ESI + 0x2]
//         00430434     FILD       dword ptr [ESP + param_1]
//         00430438     MOV        dword ptr [ESP + param_1],this
//         0043043c     FILD       dword ptr [ESP + param_1]
//         00430440     FXCH
//         00430442     FSUBP
//         00430444     FMUL       ST2
//         00430446     FMUL       float ptr [ESP + param_3]
//                              com_obj.cpp:462 (13)
//         0043044a     FCOM       double ptr [DAT_0056f4a0]
//         00430450     FNSTSW     AX
//         00430452     TEST       AH,0x41
//         00430455     JNZ        LAB_0043045b
//                              com_obj.cpp:463 (2)
//         00430457     FADDP
//                              com_obj.cpp:462 (4)
//         00430459     JMP        LAB_0043045d
//                               LAB_0043045b                                                 XREF[1]:     00430455(j)
//         0043045b     FSTP       ST0
//                               LAB_0043045d                                                 XREF[1]:     00430459(j)
//                              com_obj.cpp:463 (14)
//         0043045d     MOV        EAX,dword ptr [ESP + param_2]
//         00430461     ADD        ESI,0x4
//         00430464     DEC        EAX
//         00430465     MOV        dword ptr [ESP + param_2],EAX
//         00430469     JNZ        LAB_0043040a
//                               LAB_0043046b                                                 XREF[1]:     004303f4(j)
//                              com_obj.cpp:466 (10)
//         0043046b     POP        EDI
//         0043046c     POP        ESI
//         0043046d     POP        EBP
//         0043046e     POP        EBX
//         0043046f     FSTP       ST1
//         00430471     POP        this
//         00430472     RET        0x14
//         00430475     ??         90h
//         00430476     NOP
//         00430477     NOP
//         00430478     NOP
//         00430479     NOP
//         0043047a     NOP
//         0043047b     NOP
//         0043047c     NOP
//         0043047d     NOP
//         0043047e     NOP
//         0043047f     NOP
    return 0;
}

uchar RGE_Combat_Object::can_attack() {
    /* TODO: Stub */
//                              uchar __thiscall can_attack(RGE_Combat_Object * this)
//              uchar             AL:1           <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//                               ?can_attack@RGE_Combat_Object@@UAEEXZ                        XREF[4]:     0056f2d4(*), 0057076c(*),
//                               RGE_Combat_Object::can_attack                                             005747f4(*), 00574a9c(*)
//                              com_obj.cpp:472 (19)
//         00430480     FLD        float ptr [ECX + this->attack_timer]
//         00430486     FCOMP      float ptr [DAT_0056f4a8]
//         0043048c     FNSTSW     AX
//         0043048e     TEST       AH,0x41
//         00430491     JNZ        LAB_00430496
//                              com_obj.cpp:474 (2)
//         00430493     XOR        AL,AL
//                              com_obj.cpp:477 (1)
//         00430495     RET
//                               LAB_00430496                                                 XREF[1]:     00430491(j)
//                              com_obj.cpp:476 (2)
//         00430496     MOV        AL,0x1
//                              com_obj.cpp:477 (1)
//         00430498     RET
//         00430499     ??         90h
//         0043049a     NOP
//         0043049b     NOP
//         0043049c     NOP
//         0043049d     NOP
//         0043049e     NOP
//         0043049f     NOP
    return 0;
}

void RGE_Combat_Object::reset_attack_timer() {
    /* TODO: Stub */
//                              void __thiscall reset_attack_timer(RGE_Combat_Object * this)
//              void              <VOID>         <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//                               ?reset_attack_timer@RGE_Combat_Object@@QAEXXZ                XREF[3]:     set_state:004016d3(c),
//                               RGE_Combat_Object::reset_attack_timer                                     update:00401916(c),
//                                                                                                         update:00401961(c)
//                              com_obj.cpp:483 (15)
//         004304a0     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004304a3     FLD        float ptr [EAX + 0x120]
//         004304a9     FSTP       float ptr [ECX + this->attack_timer]
//                              com_obj.cpp:492 (1)
//         004304af     RET
    return;
}

void RGE_Combat_Object::get_armor(short* param_1, short* param_2) {
    /* TODO: Stub */
//                              void __thiscall get_armor(RGE_Combat_Object * this, short * param_1,
//              void              <VOID>         <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              short *           Stack[0x4]:4   param_1                   XREF[1]:     004304b4(R)
//              short *           Stack[0x8]:4   param_2                   XREF[1]:     004304f8(R)
//                               ?get_armor@RGE_Combat_Object@@UAEXAAF0@Z                     XREF[2]:     0056f484(*), 0057091c(*)
//                               RGE_Combat_Object::get_armor
//                              com_obj.cpp:498 (19)
//         004304b0     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004304b3     PUSH       ESI
//         004304b4     MOV        ESI,dword ptr [ESP + param_1]
//         004304b8     MOVZX      DX,byte ptr [EAX + 0x100]
//         004304c0     MOV        word ptr [ESI],DX
//                              com_obj.cpp:502 (14)
//         004304c3     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004304c6     XOR        EDX,EDX
//         004304c8     CMP        word ptr [EAX + 0x102],DX
//         004304cf     JLE        LAB_004304f5
//                              com_obj.cpp:498 (1)
//         004304d1     PUSH       EDI
//                               LAB_004304d2                                                 XREF[1]:     004304f2(j)
//                              com_obj.cpp:504 (16)
//         004304d2     MOV        EAX,dword ptr [EAX + 0x104]
//         004304d8     MOV        AX,word ptr [EAX + EDX*0x4 + 0x2]
//         004304dd     CMP        AX,word ptr [ESI]
//         004304e0     JLE        LAB_004304e5
//                              com_obj.cpp:505 (3)
//         004304e2     MOV        word ptr [ESI],AX
//                               LAB_004304e5                                                 XREF[1]:     004304e0(j)
//                              com_obj.cpp:502 (15)
//         004304e5     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004304e8     INC        EDX
//         004304e9     MOVSX      EDI,word ptr [EAX + 0x102]
//         004304f0     CMP        EDX,EDI
//         004304f2     JL         LAB_004304d2
//                              com_obj.cpp:498 (1)
//         004304f4     POP        EDI
//                               LAB_004304f5                                                 XREF[1]:     004304cf(j)
//                              com_obj.cpp:508 (7)
//         004304f5     MOV        this,dword ptr [ECX + this->_padding_]
//         004304f8     MOV        EAX,dword ptr [ESP + param_2]
//                              com_obj.cpp:509 (14)
//         004304fc     POP        ESI
//         004304fd     MOV        DX,word ptr [ECX + this->_padding_]
//         00430504     MOV        word ptr [EAX],DX
//         00430507     RET        0x8
//         0043050a     ??         90h
//         0043050b     NOP
//         0043050c     NOP
//         0043050d     NOP
//         0043050e     NOP
//         0043050f     NOP
    return;
}

void RGE_Combat_Object::get_weapon(short* param_1, short* param_2) {
    /* TODO: Stub */
//                              void __thiscall get_weapon(RGE_Combat_Object * this, short * param_1
//              void              <VOID>         <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              short *           Stack[0x4]:4   param_1                   XREF[1]:     00430511(R)
//              short *           Stack[0x8]:4   param_2                   XREF[1]:     0043054f(R)
//                               ?get_weapon@RGE_Combat_Object@@UAEXAAF0@Z                    XREF[4]:     0056f488(*), 00570920(*),
//                               RGE_Combat_Object::get_weapon                                             005749a8(*), 00574c50(*)
//                              com_obj.cpp:515 (1)
//         00430510     PUSH       ESI
//                              com_obj.cpp:518 (4)
//         00430511     MOV        ESI,dword ptr [ESP + param_1]
//                              com_obj.cpp:519 (19)
//         00430515     XOR        EDX,EDX
//         00430517     MOV        word ptr [ESI],0x0
//         0043051c     MOV        EAX,dword ptr [ECX + this->_padding_]
//         0043051f     CMP        word ptr [EAX + 0x108],DX
//         00430526     JLE        LAB_0043054c
//                              com_obj.cpp:515 (1)
//         00430528     PUSH       EDI
//                               LAB_00430529                                                 XREF[1]:     00430549(j)
//                              com_obj.cpp:521 (16)
//         00430529     MOV        EAX,dword ptr [EAX + 0x10c]
//         0043052f     MOV        AX,word ptr [EAX + EDX*0x4 + 0x2]
//         00430534     CMP        AX,word ptr [ESI]
//         00430537     JLE        LAB_0043053c
//                              com_obj.cpp:522 (3)
//         00430539     MOV        word ptr [ESI],AX
//                               LAB_0043053c                                                 XREF[1]:     00430537(j)
//                              com_obj.cpp:519 (15)
//         0043053c     MOV        EAX,dword ptr [ECX + this->_padding_]
//         0043053f     INC        EDX
//         00430540     MOVSX      EDI,word ptr [EAX + 0x108]
//         00430547     CMP        EDX,EDI
//         00430549     JL         LAB_00430529
//                              com_obj.cpp:515 (1)
//         0043054b     POP        EDI
//                               LAB_0043054c                                                 XREF[1]:     00430526(j)
//                              com_obj.cpp:525 (7)
//         0043054c     MOV        this,dword ptr [ECX + this->_padding_]
//         0043054f     MOV        EAX,dword ptr [ESP + param_2]
//                              com_obj.cpp:526 (14)
//         00430553     POP        ESI
//         00430554     MOV        DX,word ptr [ECX + this+0x13e]
//         0043055b     MOV        word ptr [EAX],DX
//         0043055e     RET        0x8
//         00430561     ??         90h
//         00430562     NOP
//         00430563     NOP
//         00430564     NOP
//         00430565     NOP
//         00430566     NOP
//         00430567     NOP
//         00430568     NOP
//         00430569     NOP
//         0043056a     NOP
//         0043056b     NOP
//         0043056c     NOP
//         0043056d     NOP
//         0043056e     NOP
//         0043056f     NOP
    return;
}

void RGE_Combat_Object::get_weapon_range(float* param_1, float* param_2) {
    /* TODO: Stub */
//                              void __thiscall get_weapon_range(RGE_Combat_Object * this, float * p
//              void              <VOID>         <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              float *           Stack[0x4]:4   param_1                   XREF[1]:     00430579(R)
//              float *           Stack[0x8]:4   param_2                   XREF[1]:     00430582(R)
//                               ?get_weapon_range@RGE_Combat_Object@@UAEXAAM0@Z              XREF[4]:     0056f48c(*), 00570924(*),
//                               RGE_Combat_Object::get_weapon_range                                       005749ac(*), 00574c54(*)
//                              com_obj.cpp:532 (15)
//         00430570     MOV        EAX,dword ptr [ECX + this->_padding_]
//         00430573     MOV        EDX,dword ptr [EAX + 0x114]
//         00430579     MOV        EAX,dword ptr [ESP + param_1]
//         0043057d     MOV        dword ptr [EAX],EDX
//                              com_obj.cpp:534 (15)
//         0043057f     MOV        this,dword ptr [ECX + this->_padding_]
//         00430582     MOV        EAX,dword ptr [ESP + param_2]
//         00430586     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0043058c     MOV        dword ptr [EAX],EDX
//                              com_obj.cpp:535 (3)
//         0043058e     RET        0x8
//         00430591     ??         90h
//         00430592     NOP
//         00430593     NOP
//         00430594     NOP
//         00430595     NOP
//         00430596     NOP
//         00430597     NOP
//         00430598     NOP
//         00430599     NOP
//         0043059a     NOP
//         0043059b     NOP
//         0043059c     NOP
//         0043059d     NOP
//         0043059e     NOP
//         0043059f     NOP
    return;
}

void RGE_Combat_Object::get_speed_of_attack(float* param_1, float* param_2) {
    /* TODO: Stub */
//                              void __thiscall get_speed_of_attack(RGE_Combat_Object * this, float
//              void              <VOID>         <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              float *           Stack[0x4]:4   param_1                   XREF[1]:     004305a9(R)
//              float *           Stack[0x8]:4   param_2                   XREF[1]:     004305b2(R)
//                               ?get_speed_of_attack@RGE_Combat_Object@@UAEXAAM0@Z           XREF[4]:     0056f490(*), 00570928(*),
//                               RGE_Combat_Object::get_speed_of_attack                                    005749b0(*), 00574c58(*)
//                              com_obj.cpp:541 (15)
//         004305a0     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004305a3     MOV        EDX,dword ptr [EAX + 0x120]
//         004305a9     MOV        EAX,dword ptr [ESP + param_1]
//         004305ad     MOV        dword ptr [EAX],EDX
//                              com_obj.cpp:543 (15)
//         004305af     MOV        this,dword ptr [ECX + this->_padding_]
//         004305b2     MOV        EAX,dword ptr [ESP + param_2]
//         004305b6     MOV        EDX,dword ptr [ECX + this->_padding_]
//         004305bc     MOV        dword ptr [EAX],EDX
//                              com_obj.cpp:544 (3)
//         004305be     RET        0x8
//         004305c1     ??         90h
//         004305c2     NOP
//         004305c3     NOP
//         004305c4     NOP
//         004305c5     NOP
//         004305c6     NOP
//         004305c7     NOP
//         004305c8     NOP
//         004305c9     NOP
//         004305ca     NOP
//         004305cb     NOP
//         004305cc     NOP
//         004305cd     NOP
//         004305ce     NOP
//         004305cf     NOP
    return;
}

void RGE_Combat_Object::release_being_worked_on(RGE_Static_Object* param_1) {
    /* TODO: Stub */
//                              void __thiscall release_being_worked_on(RGE_Combat_Object * this, RG
//              void              <VOID>         <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004305d2(R)
//                               ?release_being_worked_on@RGE_Combat_Object@@UAEXPAVRGE_Stat  XREF[4]:     0056f31c(*), 005707b4(*),
//                               RGE_Combat_Object::release_being_worked_on                                0057483c(*), 00574ae4(*)
//                              com_obj.cpp:550 (2)
//         004305d0     PUSH       ESI
//         004305d1     PUSH       EDI
//                              com_obj.cpp:551 (12)
//         004305d2     MOV        EDI,dword ptr [ESP + param_1]
//         004305d6     MOV        ESI,this
//         004305d8     PUSH       EDI
//         004305d9     CALL       RGE_Animated_Object::release_being_worked_on     void release_being_worked_on(RGE_Animated_Obj
//                              com_obj.cpp:553 (7)
//         004305de     MOV        EAX,dword ptr [EDI + 0x4]
//         004305e1     TEST       EAX,EAX
//         004305e3     JL         LAB_00430605
//                              com_obj.cpp:560 (32)
//         004305e5     MOV        this,dword ptr [EDI + 0x8]
//         004305e8     MOV        EDX,dword ptr [ESI]
//         004305ea     PUSH       0x0
//         004305ec     PUSH       0x0
//         004305ee     MOVSX      this,word ptr [ECX + this->_padding_]
//         004305f2     PUSH       this
//         004305f3     MOV        this,dword ptr [ESI + 0x4]
//         004305f6     PUSH       0x2bb
//         004305fb     PUSH       this
//         004305fc     PUSH       EAX
//         004305fd     MOV        this,ESI
//         004305ff     CALL       dword ptr [EDX + 0x148]
//                               LAB_00430605                                                 XREF[1]:     004305e3(j)
//                              com_obj.cpp:562 (5)
//         00430605     POP        EDI
//         00430606     POP        ESI
//         00430607     RET        0x4
//         0043060a     ??         90h
//         0043060b     NOP
//         0043060c     NOP
//         0043060d     NOP
//         0043060e     NOP
//         0043060f     NOP
    return;
}

void RGE_Combat_Object::enter_obj(RGE_Static_Object* param_1) {
    /* TODO: Stub */
//                              void __thiscall enter_obj(RGE_Combat_Object * this, RGE_Static_Objec
//              void              <VOID>         <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00430610(R)
//                               ?enter_obj@RGE_Combat_Object@@UAEXPAVRGE_Static_Object@@@Z   XREF[4]:     0056f328(*), 005707c0(*),
//                               RGE_Combat_Object::enter_obj                                              00574848(*), 00574af0(*)
//                              com_obj.cpp:569 (14)
//         00430610     MOV        EAX,dword ptr [ESP + param_1]
//         00430614     PUSH       ESI
//         00430615     PUSH       EDI
//         00430616     MOV        ESI,this
//         00430618     PUSH       EAX
//         00430619     CALL       RGE_Static_Object::enter_obj                     void enter_obj(RGE_Static_Object * this, RGE_
//                              com_obj.cpp:572 (7)
//         0043061e     MOV        EAX,dword ptr [ESI + 0x20]
//         00430621     TEST       EAX,EAX
//         00430623     JZ         LAB_00430674
//                              com_obj.cpp:574 (7)
//         00430625     MOV        EDI,dword ptr [ESI + 0x4]
//         00430628     TEST       EDI,EDI
//         0043062a     JL         LAB_00430674
//                              com_obj.cpp:577 (62)
//         0043062c     MOV        EAX,dword ptr [ESI + 0x8]
//         0043062f     MOV        EDX,dword ptr [ESI + 0x1b8]
//         00430635     FLD        float ptr [ESI + 0x3c]
//         00430638     LEA        this,[ESI + 0x194]
//         0043063e     PUSH       this
//         0043063f     PUSH       0x0
//         00430641     MOVSX      this,word ptr [EAX + 0x14]
//         00430645     PUSH       EDX
//         00430646     PUSH       this
//         00430647     CALL       __ftol                                           undefined __ftol()
//         0043064c     FLD        float ptr [ESI + 0x38]
//         0043064f     PUSH       EAX
//         00430650     CALL       __ftol                                           undefined __ftol()
//         00430655     MOV        EDX,dword ptr [ESI + 0xc]
//         00430658     MOV        this,dword ptr [VisibleUnitManager]              = 00000000
//         0043065e     PUSH       EAX
//         0043065f     MOVSX      EAX,word ptr [EDX + 0x4a]
//         00430663     PUSH       EAX
//         00430664     PUSH       EDI
//         00430665     CALL       Visible_Unit_Manager::Update_Unit_Info           void Update_Unit_Info(Visible_Unit_Manager *
//                              com_obj.cpp:578 (10)
//         0043066a     MOV        dword ptr [ESI + 0x1b8],0x0
//                               LAB_00430674                                                 XREF[2]:     00430623(j), 0043062a(j)
//                              com_obj.cpp:582 (5)
//         00430674     POP        EDI
//         00430675     POP        ESI
//         00430676     RET        0x4
//         00430679     ??         90h
//         0043067a     NOP
//         0043067b     NOP
//         0043067c     NOP
//         0043067d     NOP
//         0043067e     NOP
//         0043067f     NOP
    return;
}

uchar RGE_Combat_Object::update() {
    /* TODO: Stub */
//                              uchar __thiscall update(RGE_Combat_Object * this)
//              uchar             AL:1           <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00430689(W), 00430780(R)
//              long              Stack[-0x8]:4  sighted_by_player         XREF[0,2]:   004306dd(W), 004307f6(R)
//              uchar             Stack[-0x9]:1  returnResult
//                               ?update@RGE_Combat_Object@@UAEEXZ                            XREF[3]:     update:0045a940(j),
//                               RGE_Combat_Object::update                                                 update:004ca635(c), 0056f27c(*)
//                              com_obj.cpp:589 (9)
//         00430680     SUB        ESP,0x8
//         00430683     PUSH       EBX
//         00430684     PUSH       EBP
//         00430685     PUSH       ESI
//         00430686     MOV        ESI,this
//         00430688     PUSH       EDI
//                              com_obj.cpp:595 (8)
//         00430689     MOV        dword ptr [ESP + local_4],0xffffffff
//                              com_obj.cpp:610 (19)
//         00430691     FLD        float ptr [ESI + 0x1bc]
//         00430697     FCOMP      float ptr [DAT_0056f4a8]
//         0043069d     FNSTSW     AX
//         0043069f     TEST       AH,0x41
//         004306a2     JNZ        LAB_004306d3
//                              com_obj.cpp:612 (18)
//         004306a4     MOV        EAX,dword ptr [ESI + 0xc]
//         004306a7     FLD        float ptr [ESI + 0x1bc]
//         004306ad     MOV        this,dword ptr [EAX + 0x3c]
//         004306b0     FSUB       float ptr [ECX + this->_padding_]
//                              com_obj.cpp:613 (19)
//         004306b6     FCOM       float ptr [DAT_0056f4a8]
//         004306bc     FSTP       float ptr [ESI + 0x1bc]
//         004306c2     FNSTSW     AX
//         004306c4     TEST       AH,0x1
//         004306c7     JZ         LAB_004306d3
//                              com_obj.cpp:614 (10)
//         004306c9     MOV        dword ptr [ESI + 0x1bc],0x0
//                               LAB_004306d3                                                 XREF[2]:     004306a2(j), 004306c7(j)
//                              com_obj.cpp:618 (7)
//         004306d3     MOV        this,ESI
//         004306d5     CALL       RGE_Action_Object::update                        uchar update(RGE_Action_Object * this)
//                              com_obj.cpp:632 (26)
//         004306da     MOV        EBX,dword ptr [ESI + 0x4]
//         004306dd     MOV        byte ptr [ESP + sighted_by_player+0x3],AL
//         004306e1     TEST       EBX,EBX
//         004306e3     JL         LAB_004307c2
//         004306e9     MOV        EAX,dword ptr [ESI + 0x20]
//         004306ec     TEST       EAX,EAX
//         004306ee     JNZ        LAB_004307c2
//                              com_obj.cpp:634 (8)
//         004306f4     FLD        float ptr [ESI + 0x38]
//         004306f7     CALL       __ftol                                           undefined __ftol()
//                              com_obj.cpp:635 (10)
//         004306fc     FLD        float ptr [ESI + 0x3c]
//         004306ff     MOV        EBP,EAX
//         00430701     CALL       __ftol                                           undefined __ftol()
//                              com_obj.cpp:637 (16)
//         00430706     MOV        EDX,dword ptr [EAX*0x4 + unified_map_offsets]    = 00000000
//         0043070d     MOV        this,dword ptr [ESI + 0x1b8]
//         00430713     MOV        EDI,dword ptr [EDX + EBP*0x4]
//                              com_obj.cpp:641 (14)
//         00430716     CMP        EDI,this
//         00430718     MOV        dword ptr [ESI + 0x1b8],EDI
//         0043071e     JZ         LAB_004307c2
//                              com_obj.cpp:644 (39)
//         00430724     LEA        EDX,[ESI + 0x194]
//         0043072a     PUSH       EDX
//         0043072b     PUSH       EDI
//         0043072c     PUSH       this
//         0043072d     MOV        this,dword ptr [ESI + 0x8]
//         00430730     MOVSX      EDX,word ptr [ECX + this->_padding_]
//         00430734     PUSH       EDX
//         00430735     PUSH       EAX
//         00430736     MOV        EAX,dword ptr [ESI + 0xc]
//         00430739     PUSH       EBP
//         0043073a     MOVSX      this,word ptr [EAX + 0x4a]
//         0043073e     PUSH       this
//         0043073f     MOV        this,dword ptr [VisibleUnitManager]              = 00000000
//         00430745     PUSH       EBX
//         00430746     CALL       Visible_Unit_Manager::Update_Unit_Info           void Update_Unit_Info(Visible_Unit_Manager *
//                              com_obj.cpp:646 (10)
//         0043074b     MOV        AL,byte ptr [ESI + 0x1c0]
//         00430751     TEST       AL,AL
//         00430753     JZ         LAB_004307c2
//                              com_obj.cpp:648 (19)
//         00430755     MOV        EAX,dword ptr [ESI + 0xc]
//         00430758     MOV        this,0x1
//         0043075d     MOV        EBX,dword ptr [EAX + 0x3c]
//         00430760     MOVSX      EDX,word ptr [EBX + 0x3c]
//         00430764     CMP        EDX,this
//         00430766     JLE        LAB_00430780
//                              com_obj.cpp:649 (19)
//         00430768     MOVSX      EAX,word ptr [EAX + 0x4a]
//                               LAB_0043076c                                                 XREF[1]:     0043077e(j)
//         0043076c     CMP        this,EAX
//         0043076e     JZ         LAB_0043077b
//         00430770     MOV        EBP,0x1
//         00430775     SHL        EBP,this
//         00430777     TEST       EDI,EBP
//         00430779     JA         LAB_00430784
//                               LAB_0043077b                                                 XREF[1]:     0043076e(j)
//                              com_obj.cpp:648 (5)
//         0043077b     INC        this
//         0043077c     CMP        this,EDX
//         0043077e     JL         LAB_0043076c
//                               LAB_00430780                                                 XREF[1]:     00430766(j)
//                              com_obj.cpp:651 (4)
//         00430780     MOV        this,dword ptr [ESP + local_4]
//                               LAB_00430784                                                 XREF[1]:     00430779(j)
//                              com_obj.cpp:658 (26)
//         00430784     TEST       this,this
//         00430786     JL         LAB_004307c2
//         00430788     MOV        EDX,dword ptr [EBX + 0x40]
//         0043078b     LEA        EDI,[this->_padding_*0x4 + 0x0]
//         00430792     MOV        this,dword ptr [EDX + this->_padding_*0x4]
//         00430795     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
//         0043079a     TEST       EAX,EAX
//         0043079c     JNZ        LAB_004307c2
//                              com_obj.cpp:660 (20)
//         0043079e     MOV        this,dword ptr [ESI + 0xc]
//         004307a1     MOV        EAX,dword ptr [ESI]
//         004307a3     MOV        EDX,dword ptr [ECX + this->_padding_]
//         004307a6     MOV        this,dword ptr [EDX + 0x40]
//         004307a9     MOV        EDX,dword ptr [this->_padding_ + EDI*0x1]
//         004307ac     MOV        this,ESI
//         004307ae     PUSH       EDX
//         004307af     CALL       dword ptr [EAX + 0x44]
//                              com_obj.cpp:661 (9)
//         004307b2     CMP        byte ptr [ESI + 0x1c0],0x1
//         004307b9     JNZ        LAB_004307c2
//                              com_obj.cpp:662 (7)
//         004307bb     MOV        byte ptr [ESI + 0x1c0],0x0
//                               LAB_004307c2                                                 XREF[7]:     004306e3(j), 004306ee(j),
//                                                                                                         0043071e(j), 00430753(j),
//                                                                                                         00430786(j), 0043079c(j),
//                                                                                                         004307b9(j)
//                              com_obj.cpp:673 (27)
//         004307c2     MOV        EAX,dword ptr [ESI + 0x74]
//         004307c5     TEST       EAX,EAX
//         004307c7     JZ         LAB_004307f6
//         004307c9     MOV        EAX,dword ptr [ESI + 0xc]
//         004307cc     MOVSX      this,word ptr [EAX + 0x4a]
//         004307d0     PUSH       this
//         004307d1     MOV        this,dword ptr [EAX + 0x3c]
//         004307d4     CALL       RGE_Game_World::is_player_turn                   int is_player_turn(RGE_Game_World * this, int
//         004307d9     TEST       EAX,EAX
//         004307db     JZ         LAB_004307f6
//                              com_obj.cpp:675 (25)
//         004307dd     MOV        EAX,dword ptr [ESI + 0xc]
//         004307e0     MOVSX      EDX,word ptr [EAX + 0x4a]
//         004307e4     MOV        this,dword ptr [EAX + 0x3c]
//         004307e7     PUSH       EDX
//         004307e8     CALL       RGE_Game_World::get_accum_time_delta             ulong get_accum_time_delta(RGE_Game_World * t
//         004307ed     MOV        this,dword ptr [ESI + 0x74]
//         004307f0     PUSH       EAX
//         004307f1     CALL       UnitAIModule::update                             int update(UnitAIModule * this, ulong param_1)
//                               LAB_004307f6                                                 XREF[2]:     004307c7(j), 004307db(j)
//                              com_obj.cpp:710 (4)
//         004307f6     MOV        AL,byte ptr [ESP + sighted_by_player+0x3]
//                              com_obj.cpp:711 (8)
//         004307fa     POP        EDI
//         004307fb     POP        ESI
//         004307fc     POP        EBP
//         004307fd     POP        EBX
//         004307fe     ADD        ESP,0x8
//         00430801     RET
//         00430802     ??         90h
//         00430803     NOP
//         00430804     NOP
//         00430805     NOP
//         00430806     NOP
//         00430807     NOP
//         00430808     NOP
//         00430809     NOP
//         0043080a     NOP
//         0043080b     NOP
//         0043080c     NOP
//         0043080d     NOP
//         0043080e     NOP
//         0043080f     NOP
    return 0;
}

void RGE_Combat_Object::copy_obj(RGE_Master_Static_Object* param_1) {
    /* TODO: Stub */
//                              void __thiscall copy_obj(RGE_Combat_Object * this, RGE_Master_Static
//              void              <VOID>         <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              RGE_Master_Sta    Stack[0x4]:4   param_1                   XREF[1]:     00430824(R)
//                               ?copy_obj@RGE_Combat_Object@@UAEXPAVRGE_Master_Static_Objec  XREF[4]:     copy_obj:004c9737(c), 0056f2b0(*),
//                               RGE_Combat_Object::copy_obj                                               00570748(*), 00574a78(*)
//                              com_obj.cpp:717 (4)
//         00430810     PUSH       ESI
//         00430811     MOV        ESI,this
//         00430813     PUSH       EDI
//                              com_obj.cpp:719 (2)
//         00430814     XOR        EAX,EAX
//                              com_obj.cpp:721 (26)
//         00430816     MOV        this,dword ptr [ESI + 0x8]
//         00430819     MOV        EDX,dword ptr [ESI + 0x10]
//         0043081c     MOV        EDI,dword ptr [ECX + this->_padding_]
//         00430822     CMP        EDX,EDI
//         00430824     MOV        EDI,dword ptr [ESP + param_1]
//         00430828     JNZ        LAB_00430830
//         0043082a     MOV        EAX,dword ptr [EDI + 0xfc]
//                               LAB_00430830                                                 XREF[1]:     00430828(j)
//                              com_obj.cpp:723 (4)
//         00430830     TEST       EAX,EAX
//         00430832     JZ         LAB_0043083c
//                              com_obj.cpp:724 (8)
//         00430834     MOV        EDX,dword ptr [ESI]
//         00430836     PUSH       EAX
//         00430837     MOV        this,ESI
//         00430839     CALL       dword ptr [EDX + 0x38]
//                               LAB_0043083c                                                 XREF[1]:     00430832(j)
//                              com_obj.cpp:726 (8)
//         0043083c     PUSH       EDI
//         0043083d     MOV        this,ESI
//         0043083f     CALL       RGE_Action_Object::copy_obj                      void copy_obj(RGE_Action_Object * this, RGE_M
//                              com_obj.cpp:727 (5)
//         00430844     POP        EDI
//         00430845     POP        ESI
//         00430846     RET        0x4
//         00430849     ??         90h
//         0043084a     NOP
//         0043084b     NOP
//         0043084c     NOP
//         0043084d     NOP
//         0043084e     NOP
//         0043084f     NOP
    return;
}

void RGE_Combat_Object::notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6) {
    /* TODO: Stub */
//                              void __thiscall notify(RGE_Combat_Object * this, int param_1, int pa
//              void              <VOID>         <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[2]:     00430885(R), 004308ab(R)
//              int               Stack[0x8]:4   param_2                   XREF[2]:     0043087a(R), 0043089d(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     00430872(R)
//              long              Stack[0x10]:4  param_4                   XREF[1]:     0043086e(R)
//              long              Stack[0x14]:4  param_5                   XREF[1]:     0043086a(R)
//              long              Stack[0x18]:4  param_6                   XREF[1]:     00430866(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0043085d(W)
//                               ?notify@RGE_Combat_Object@@UAEXHHHJJJ@Z                      XREF[4]:     0056f3a0(*), 00570838(*),
//                               RGE_Combat_Object::notify                                                 005748c0(*), 00574b68(*)
//                              com_obj.cpp:734 (6)
//         00430850     PUSH       this
//         00430851     MOV        EAX,this
//         00430853     PUSH       EBX
//         00430854     PUSH       EBP
//         00430855     PUSH       ESI
//                              com_obj.cpp:739 (13)
//         00430856     MOV        this,byte ptr [EAX + 0x48]
//         00430859     PUSH       EDI
//         0043085a     CMP        this,0x2
//         0043085d     MOV        dword ptr [ESP + local_4],EAX
//         00430861     JNZ        LAB_004308b6
//                              com_obj.cpp:751 (58)
//         00430863     MOV        this,dword ptr [EAX + 0x74]
//         00430866     MOV        EDI,dword ptr [ESP + param_6]
//         0043086a     MOV        EBX,dword ptr [ESP + param_5]
//         0043086e     MOV        EBP,dword ptr [ESP + param_4]
//         00430872     MOV        ESI,dword ptr [ESP + param_3]
//         00430876     TEST       this,this
//         00430878     JZ         LAB_00430895
//         0043087a     MOV        EDX,dword ptr [ESP + param_2]
//         0043087e     MOV        EAX,dword ptr [this->_padding_]
//         00430880     PUSH       EDI
//         00430881     PUSH       EBX
//         00430882     PUSH       EBP
//         00430883     PUSH       ESI
//         00430884     PUSH       EDX
//         00430885     MOV        EDX,dword ptr [ESP + param_1]
//         00430889     PUSH       EDX
//         0043088a     CALL       dword ptr [EAX + 0x14]
//         0043088d     TEST       EAX,EAX
//         0043088f     JNZ        LAB_004308b6
//         00430891     MOV        EAX,dword ptr [ESP + 0x10]
//                               LAB_00430895                                                 XREF[1]:     00430878(j)
//         00430895     CMP        ESI,0x2bb
//         0043089b     JZ         LAB_004308b6
//                              com_obj.cpp:752 (25)
//         0043089d     MOV        EDX,dword ptr [ESP + param_2]
//         004308a1     MOV        this,dword ptr [EAX + 0xc]
//         004308a4     PUSH       EDI
//         004308a5     PUSH       EBX=>DAT_fffffff8
//         004308a6     MOV        EAX,dword ptr [this->_padding_]
//         004308a8     PUSH       EBP=>DAT_fffffff4
//         004308a9     PUSH       ESI=>DAT_fffffff0
//         004308aa     PUSH       EDX
//         004308ab     MOV        EDX,dword ptr [ESP + param_1]
//         004308af     PUSH       EDX
//         004308b0     CALL       dword ptr [EAX + 0xe8]
//                               LAB_004308b6                                                 XREF[3]:     00430861(j), 0043088f(j),
//                                                                                                         0043089b(j)
//                              com_obj.cpp:753 (8)
//         004308b6     POP        EDI
//         004308b7     POP        ESI
//         004308b8     POP        EBP
//         004308b9     POP        EBX
//         004308ba     POP        this
//         004308bb     RET        0x18
//         004308be     ??         90h
//         004308bf     NOP
    return;
}

uchar RGE_Combat_Object::attack(RGE_Static_Object* param_1, RGE_Combat_Object* param_2) {
    /* TODO: Stub */
//                              uchar __thiscall attack(RGE_Combat_Object * this, RGE_Static_Object
//              uchar             AL:1           <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[8]:     0042ff53(R), 0042ff8c(W), 0042ff93(R), 0042ff9b(R),
//                                                                                     0042ffc4(W), 0042ffc8(R), 00430003(W), 00430033(W)
//              RGE_Combat_Obj    Stack[0x8]:4   param_2                   XREF[1]:     004300cf(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0042ffba(W), 0042ffd4(R)
//              float             Stack[-0x8]:4  c
//              undefined4        Stack[-0x14]:4 local_14                  XREF[1]:     00430018(*)
//              undefined4        Stack[-0x18]:4 local_18                  XREF[1]:     00430029(*)
//              undefined4        Stack[-0x1c]:4 local_1c                  XREF[1]:     0043002f(*)
//                               ?attack@RGE_Combat_Object@@UAEEPAVRGE_Static_Object@@PAV1@@Z XREF[3]:     attack:004caa93(c), 0056f47c(*),
//                               RGE_Combat_Object::attack                                                 00570914(*)
//                              com_obj.cpp:269 (3)
//         0042ff50     PUSH       this
//         0042ff51     PUSH       ESI
//         0042ff52     PUSH       EDI
//                              com_obj.cpp:272 (10)
//         0042ff53     MOV        EDI,dword ptr [ESP + param_1]
//         0042ff57     MOV        ESI,this
//         0042ff59     TEST       EDI,EDI
//         0042ff5b     JNZ        LAB_0042ff65
//                              com_obj.cpp:273 (2)
//         0042ff5d     XOR        AL,AL
//                              com_obj.cpp:315 (6)
//         0042ff5f     POP        EDI
//         0042ff60     POP        ESI
//         0042ff61     POP        this
//         0042ff62     RET        0x8
//                               LAB_0042ff65                                                 XREF[1]:     0042ff5b(j)
//                              com_obj.cpp:276 (20)
//         0042ff65     MOV        EAX,dword ptr [ESI + 0x8]
//         0042ff68     PUSH       EBX
//         0042ff69     MOV        this,word ptr [EAX + 0x124]
//         0042ff70     TEST       this,this
//         0042ff73     JL         LAB_004300c2
//                              com_obj.cpp:291 (3)
//         0042ff79     FLD        float ptr [EAX + 0x34]
//                              com_obj.cpp:294 (29)
//         0042ff7c     MOV        EDX,dword ptr [EAX + 0x30]
//         0042ff7f     PUSH       this
//         0042ff80     FLD        float ptr [ESI + 0x9c]
//         0042ff86     FLD        float ptr [ESI + 0x9c]
//         0042ff8c     MOV        dword ptr [ESP + param_1],EDX
//         0042ff90     MOV        EDX,dword ptr [ESI + 0xc]
//         0042ff93     FLD        float ptr [ESP + param_1]
//         0042ff97     FLD        ST3
//                              com_obj.cpp:314 (291)
//         0042ff99     FXCH
//         0042ff9b     FMUL       float ptr [ESP + param_1]
//         0042ff9f     FXCH       ST3
//         0042ffa1     FCOS
//         0042ffa3     MOV        EBX,dword ptr [EDX + 0x24]
//         0042ffa6     MOVSX      this,this
//         0042ffa9     MOV        this,dword ptr [EBX + this->_padding_*0x4]
//         0042ffac     MOV        EBX,dword ptr [this->_padding_]
//         0042ffae     FXCH
//         0042ffb0     FMUL       ST4
//         0042ffb2     FXCH       ST2
//         0042ffb4     FSIN
//         0042ffb6     FXCH       ST2
//         0042ffb8     FADDP      ST3,ST0
//         0042ffba     FST        float ptr [ESP + local_4]
//         0042ffbe     FXCH       ST2
//         0042ffc0     FSQRT
//         0042ffc2     FXCH
//         0042ffc4     FST        float ptr [ESP + param_1]
//         0042ffc8     FLD        float ptr [ESP + param_1]
//         0042ffcc     FXCH
//         0042ffce     FMUL       float ptr [EAX + 0x130]
//         0042ffd4     FLD        float ptr [ESP + local_4]
//         0042ffd8     FXCH       ST4
//         0042ffda     FMUL       float ptr [EAX + 0x12c]
//         0042ffe0     FLD        float ptr [ESI + 0x40]
//         0042ffe3     FXCH       ST5
//         0042ffe5     FMUL       float ptr [EAX + 0x130]
//         0042ffeb     FXCH       ST5
//         0042ffed     FADD       float ptr [EAX + 0x134]
//         0042fff3     FXCH       ST3
//         0042fff5     FCHS
//         0042fff7     FMUL       float ptr [EAX + 0x12c]
//         0042fffd     FXCH
//         0042ffff     FADDP      ST2,ST0
//         00430001     FXCH       ST3
//         00430003     FST        float ptr [ESP + param_1]
//         00430007     FADD       float ptr [EAX + 0x114]
//         0043000d     FXCH
//         0043000f     FADD       float ptr [ESI + 0x3c]
//         00430012     FXCH       ST4
//         00430014     FADDP      ST3,ST0
//         00430016     FXCH
//         00430018     FSTP       float ptr [ESP]=>local_14
//         0043001b     PUSH       this
//         0043001c     FSUB       float ptr [DAT_0056f4ac]
//         00430022     FXCH
//         00430024     FADD       float ptr [ESI + 0x38]
//         00430027     FXCH       ST2
//         00430029     FSTP       float ptr [ESP]=>local_18
//         0043002c     FXCH
//         0043002e     PUSH       this
//         0043002f     FSTP       float ptr [ESP]=>local_1c
//         00430032     PUSH       EDX
//         00430033     FSTP       float ptr [ESP + param_1]
//         00430037     FSTP       ST0
//         00430039     CALL       dword ptr [EBX + 0x18]
//         0043003c     MOV        EDX,dword ptr [ESP + 0x14]
//         00430040     MOV        this,dword ptr [ESP + 0x18]
//         00430044     PUSH       EDX
//         00430045     PUSH       EDI=>DAT_fffffff8
//         00430046     PUSH       this=>DAT_fffffff4
//         00430047     MOV        this,EAX
//         00430049     CALL       RGE_Missile_Object::init_missile                 void init_missile(RGE_Missile_Object * this,
//         0043004e     MOV        EDX,dword ptr [EDI + 0x4]
//         00430051     MOV        EAX,dword ptr [ESI + 0x4]
//         00430054     MOV        EBX,dword ptr [ESI]
//         00430056     PUSH       0x0
//         00430058     PUSH       EDX=>DAT_fffffff8
//         00430059     PUSH       offset DAT_fffffff4
//         0043005e     PUSH       offset DAT_fffffff0
//         00430063     PUSH       EAX
//         00430064     PUSH       EAX
//         00430065     MOV        this,ESI
//         00430067     CALL       dword ptr [EBX + 0x148]
//         0043006d     MOV        EAX,dword ptr [ESI + 0x8]
//         00430070     FLD        float ptr [EAX + 0x114]
//         00430076     FCOMP      float ptr [DAT_0056f49c]
//         0043007c     FNSTSW     AX
//         0043007e     TEST       AH,0x41
//         00430081     JNZ        LAB_004300de
//         00430083     MOV        this,dword ptr [EDI + 0xc]
//         00430086     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
//         0043008b     CMP        EAX,0x1
//         0043008e     JNZ        LAB_004300de
//         00430090     MOV        this,dword ptr [EDI + 0x8]
//         00430093     MOV        ESI,dword ptr [ESI + 0x4]
//         00430096     FLD        float ptr [EDI + 0x30]
//         00430099     MOVSX      EDX,word ptr [ECX + this+0x26]
//         0043009d     MOV        EBX,dword ptr [EDI]
//         0043009f     PUSH       EDX
//         004300a0     CALL       __ftol                                           undefined __ftol()
//         004300a5     PUSH       EAX=>DAT_fffffff8
//         004300a6     MOV        EAX,dword ptr [EDI + 0x4]
//         004300a9     PUSH       ESI=>DAT_fffffff4
//         004300aa     PUSH       offset DAT_fffffff0
//         004300af     PUSH       EAX
//         004300b0     PUSH       ESI
//         004300b1     MOV        this,EDI
//         004300b3     CALL       dword ptr [EBX + 0x148]
//         004300b9     MOV        AL,0x1
//         004300bb     POP        EBX
//                              com_obj.cpp:315 (6)
//         004300bc     POP        EDI
//         004300bd     POP        ESI
//         004300be     POP        this
//         004300bf     RET        0x8
//                               LAB_004300c2                                                 XREF[1]:     0042ff73(j)
//                              com_obj.cpp:312 (29)
//         004300c2     MOV        EAX,dword ptr [ESI + 0x40]
//         004300c5     MOV        this,dword ptr [ESI + 0x3c]
//         004300c8     MOV        EDX,dword ptr [ESI]
//         004300ca     PUSH       EAX
//         004300cb     MOV        EAX,dword ptr [ESI + 0x38]
//         004300ce     PUSH       this
//         004300cf     MOV        this,dword ptr [ESP + param_2]
//         004300d3     PUSH       EAX
//         004300d4     PUSH       this
//         004300d5     PUSH       EDI
//         004300d6     MOV        this,ESI
//         004300d8     CALL       dword ptr [EDX + 0x228]
//                               LAB_004300de                                                 XREF[2]:     00430081(j), 0043008e(j)
//         004300de     POP        EBX
//                              com_obj.cpp:315 (8)
//         004300df     POP        EDI
//         004300e0     MOV        AL,0x1
//         004300e2     POP        ESI
//         004300e3     POP        this
//         004300e4     RET        0x8
//         004300e7     ??         90h
//         004300e8     NOP
//         004300e9     NOP
//         004300ea     NOP
//         004300eb     NOP
//         004300ec     NOP
//         004300ed     NOP
//         004300ee     NOP
//         004300ef     NOP
    return 0;
}

uchar RGE_Combat_Object::attack(float param_1, float param_2, float param_3, RGE_Combat_Object* param_4) {
    /* TODO: Stub */
//                              uchar __thiscall attack(RGE_Combat_Object * this, float param_1, flo
//              uchar             AL:1           <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1
//              float             Stack[0x8]:4   param_2
//              float             Stack[0xc]:4   param_3
//              RGE_Combat_Obj    Stack[0x10]:4  param_4
//              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     0043014c(W), 00430166(R), 00430195(W), 004301c7(W)
//              float             Stack[-0x8]:4  c                         XREF[5]:     0043011c(W), 00430123(R), 0043012b(R), 00430156(W),
//                                                                                     0043015a(R)
//              float             Stack[-0xc]:4  s
//              undefined4        Stack[-0x18]:4 local_18                  XREF[1]:     004301aa(*)
//              undefined4        Stack[-0x1c]:4 local_1c                  XREF[1]:     004301bd(*)
//              undefined4        Stack[-0x20]:4 local_20                  XREF[1]:     004301c3(*)
//                               ?attack@RGE_Combat_Object@@UAEEMMMPAV1@@Z                    XREF[4]:     0056f478(*), 00570910(*),
//                               RGE_Combat_Object::attack                                                 00574998(*), 00574c40(*)
//                              com_obj.cpp:322 (6)
//         004300f0     SUB        ESP,0x8
//         004300f3     PUSH       ESI
//         004300f4     MOV        ESI,this
//                              com_obj.cpp:324 (19)
//         004300f6     MOV        EAX,dword ptr [ESI + 0x8]
//         004300f9     MOV        this,word ptr [EAX + 0x124]
//         00430100     TEST       this,this
//         00430103     JL         LAB_00430218
//                              com_obj.cpp:339 (3)
//         00430109     FLD        float ptr [EAX + 0x34]
//                              com_obj.cpp:342 (29)
//         0043010c     MOV        EDX,dword ptr [EAX + 0x30]
//         0043010f     PUSH       EDI
//         00430110     FLD        float ptr [ESI + 0x9c]
//         00430116     FLD        float ptr [ESI + 0x9c]
//         0043011c     MOV        dword ptr [ESP + c],EDX
//         00430120     MOV        EDX,dword ptr [ESI + 0xc]
//         00430123     FLD        float ptr [ESP + c]
//         00430127     FLD        ST3
//                              com_obj.cpp:353 (232)
//         00430129     FXCH
//         0043012b     FMUL       float ptr [ESP + c]
//         0043012f     FXCH       ST3
//         00430131     FCOS
//         00430133     MOV        EDI,dword ptr [EDX + 0x24]
//         00430136     PUSH       EBX
//         00430137     PUSH       this
//         00430138     MOVSX      this,this
//         0043013b     MOV        this,dword ptr [EDI + this->_padding_*0x4]
//         0043013e     MOV        EDI,dword ptr [this->_padding_]
//         00430140     FXCH
//         00430142     FMUL       ST4
//         00430144     FXCH       ST2
//         00430146     FSIN
//         00430148     FXCH       ST2
//         0043014a     FADDP      ST3,ST0
//         0043014c     FST        float ptr [ESP + local_4]
//         00430150     FXCH       ST2
//         00430152     FSQRT
//         00430154     FXCH
//         00430156     FST        float ptr [ESP + c]
//         0043015a     FLD        float ptr [ESP + c]
//         0043015e     FXCH       ST3
//         00430160     FMUL       float ptr [EAX + 0x12c]
//         00430166     FLD        float ptr [ESP + local_4]
//         0043016a     FXCH       ST2
//         0043016c     FMUL       float ptr [EAX + 0x130]
//         00430172     FLD        float ptr [ESI + 0x40]
//         00430175     FXCH       ST3
//         00430177     FMUL       float ptr [EAX + 0x130]
//         0043017d     FXCH       ST3
//         0043017f     FADD       float ptr [EAX + 0x134]
//         00430185     FXCH       ST5
//         00430187     FCHS
//         00430189     FMUL       float ptr [EAX + 0x12c]
//         0043018f     FXCH
//         00430191     FADDP      ST2,ST0
//         00430193     FXCH       ST3
//         00430195     FST        float ptr [ESP + local_4]
//         00430199     FADD       float ptr [EAX + 0x114]
//         0043019f     FXCH
//         004301a1     FADD       float ptr [ESI + 0x3c]
//         004301a4     FXCH       ST2
//         004301a6     FADDP      ST3,ST0
//         004301a8     FXCH       ST3
//         004301aa     FSTP       float ptr [ESP]=>local_18
//         004301ad     FXCH       ST2
//         004301af     FSUB       float ptr [DAT_0056f4ac]
//         004301b5     FXCH
//         004301b7     FADD       float ptr [ESI + 0x38]
//         004301ba     FXCH       ST2
//         004301bc     PUSH       this
//         004301bd     FSTP       float ptr [ESP]=>local_1c
//         004301c0     FXCH
//         004301c2     PUSH       this
//         004301c3     FSTP       float ptr [ESP]=>local_20
//         004301c6     PUSH       EDX
//         004301c7     FSTP       float ptr [ESP + local_4]
//         004301cb     FSTP       ST0
//         004301cd     CALL       dword ptr [EDI + 0x18]
//         004301d0     MOV        EDX,dword ptr [ESP + 0x10]
//         004301d4     MOV        this,dword ptr [ESP + 0x20]
//         004301d8     MOV        EDI,dword ptr [ESP + 0x1c]
//         004301dc     MOV        EBX,dword ptr [ESP + 0x18]
//         004301e0     PUSH       EDX
//         004301e1     MOV        EDX,dword ptr [ESP + 0x28]
//         004301e5     PUSH       this=>DAT_fffffff8
//         004301e6     PUSH       EDI=>DAT_fffffff4
//         004301e7     PUSH       EBX=>DAT_fffffff0
//         004301e8     PUSH       EDX
//         004301e9     MOV        this,EAX
//         004301eb     CALL       RGE_Missile_Object::init_missile                 void init_missile(RGE_Missile_Object * this,
//         004301f0     MOV        EAX,dword ptr [ESI + 0x4]
//         004301f3     MOV        EDX,dword ptr [ESI]
//         004301f5     PUSH       0x0
//         004301f7     PUSH       offset DAT_fffffff8
//         004301f9     PUSH       offset DAT_fffffff4
//         004301fe     PUSH       offset DAT_fffffff0
//         00430203     PUSH       EAX
//         00430204     PUSH       EAX
//         00430205     MOV        this,ESI
//         00430207     CALL       dword ptr [EDX + 0x148]
//         0043020d     POP        EBX
//         0043020e     MOV        AL,0x1
//         00430210     POP        EDI
//                              com_obj.cpp:354 (7)
//         00430211     POP        ESI
//         00430212     ADD        ESP,0x8
//         00430215     RET        0x10
//                               LAB_00430218                                                 XREF[1]:     00430103(j)
//                              com_obj.cpp:353 (2)
//         00430218     XOR        AL,AL
//                              com_obj.cpp:354 (7)
//         0043021a     POP        ESI
//         0043021b     ADD        ESP,0x8
//         0043021e     RET        0x10
//         00430221     ??         90h
//         00430222     NOP
//         00430223     NOP
//         00430224     NOP
//         00430225     NOP
//         00430226     NOP
//         00430227     NOP
//         00430228     NOP
//         00430229     NOP
//         0043022a     NOP
//         0043022b     NOP
//         0043022c     NOP
//         0043022d     NOP
//         0043022e     NOP
//         0043022f     NOP
    return 0;
}

uchar RGE_Combat_Object::do_attack(RGE_Static_Object* param_1, RGE_Combat_Object* param_2, float param_3, float param_4, float param_5) {
    /* TODO: Stub */
//                              uchar __thiscall do_attack(RGE_Combat_Object * this, RGE_Static_Obje
//              uchar             AL:1           <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00430233(R)
//              RGE_Combat_Obj    Stack[0x8]:4   param_2                   XREF[1]:     0043025b(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     0043026d(R)
//              float             Stack[0x10]:4  param_4                   XREF[1]:     00430268(R)
//              float             Stack[0x14]:4  param_5                   XREF[1]:     0043025f(R)
//                               ?do_attack@RGE_Combat_Object@@UAEEPAVRGE_Static_Object@@PAV  XREF[3]:     do_attack:004cac01(c),
//                               RGE_Combat_Object::do_attack                                              0056f480(*), 00570918(*)
//                              com_obj.cpp:361 (3)
//         00430230     PUSH       EBX
//         00430231     PUSH       ESI
//         00430232     PUSH       EDI
//                              com_obj.cpp:366 (10)
//         00430233     MOV        EDI,dword ptr [ESP + param_1]
//         00430237     TEST       EDI,EDI
//         00430239     MOV        ESI,this
//         0043023b     JNZ        LAB_00430245
//                              com_obj.cpp:367 (2)
//         0043023d     XOR        AL,AL
//                              com_obj.cpp:390 (6)
//         0043023f     POP        EDI
//         00430240     POP        ESI
//         00430241     POP        EBX
//         00430242     RET        0x14
//                               LAB_00430245                                                 XREF[1]:     0043023b(j)
//                              com_obj.cpp:369 (22)
//         00430245     MOV        EAX,dword ptr [ESI + 0x8]
//         00430248     FLD        float ptr [EAX + 0x118]
//         0043024e     FCOMP      float ptr [DAT_0056f4a8]
//         00430254     FNSTSW     AX
//         00430256     TEST       AH,0x41
//         00430259     JNZ        LAB_00430283
//                              com_obj.cpp:371 (32)
//         0043025b     MOV        EAX,dword ptr [ESP + param_2]
//         0043025f     MOV        this,dword ptr [ESP + param_5]
//         00430263     MOV        EDX,dword ptr [ESI]
//         00430265     PUSH       0x0
//         00430267     PUSH       EAX
//         00430268     MOV        EAX,dword ptr [ESP + param_4]
//         0043026c     PUSH       this
//         0043026d     MOV        this,dword ptr [ESP + param_3]
//         00430271     PUSH       EAX
//         00430272     PUSH       this
//         00430273     MOV        this,ESI
//         00430275     CALL       dword ptr [EDX + 0x21c]
//                              com_obj.cpp:389 (2)
//         0043027b     MOV        AL,0x1
//                              com_obj.cpp:390 (6)
//         0043027d     POP        EDI
//         0043027e     POP        ESI
//         0043027f     POP        EBX
//         00430280     RET        0x14
//                               LAB_00430283                                                 XREF[1]:     00430259(j)
//                              com_obj.cpp:376 (31)
//         00430283     MOV        EDX,dword ptr [EDI + 0x4]
//         00430286     MOV        EAX,dword ptr [ESI + 0x4]
//         00430289     MOV        EBX,dword ptr [ESI]
//         0043028b     PUSH       0x0
//         0043028d     PUSH       EDX
//         0043028e     PUSH       0x258
//         00430293     PUSH       0x200
//         00430298     PUSH       EAX
//         00430299     PUSH       EAX
//         0043029a     MOV        this,ESI
//         0043029c     CALL       dword ptr [EBX + 0x148]
//                              com_obj.cpp:379 (36)
//         004302a2     PUSH       0x17b
//         004302a7     PUSH       s_C:\msdev\work\age1_x1\com_obj.cp               = "C:\\msdev\\work\\age1_x1\\com_obj.cpp"
//         004302ac     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         004302b1     LEA        EAX,[EAX + EAX*0x4]
//         004302b4     ADD        ESP,0x8
//         004302b7     LEA        this,[EAX + EAX*0x4]
//         004302ba     MOV        EAX,0x80010003
//         004302bf     SHL        this,0x2
//         004302c2     IMUL       this
//         004302c4     ADD        EDX,this
//                              com_obj.cpp:380 (24)
//         004302c6     MOV        this,dword ptr [ESI + 0x8]
//         004302c9     SAR        EDX,0xe
//         004302cc     MOV        EAX,EDX
//         004302ce     SHR        EAX,0x1f
//         004302d1     ADD        EDX,EAX
//         004302d3     MOVSX      EAX,word ptr [ECX + this+0x126]
//         004302da     CMP        EDX,EAX
//         004302dc     JG         LAB_00430312
//                              com_obj.cpp:382 (9)
//         004302de     PUSH       EDI
//         004302df     MOV        this,ESI
//         004302e1     CALL       dword ptr [EBX + 0xf0]
//                              com_obj.cpp:386 (43)
//         004302e7     MOV        this,dword ptr [ESP + 0x14]
//         004302eb     MOV        EAX,dword ptr [ESI + 0x8]
//         004302ee     FSTP       float ptr [ESP + 0x10]
//         004302f2     PUSH       this
//         004302f3     MOV        this,dword ptr [ESI + 0xc]
//         004302f6     MOV        EDX,dword ptr [EDI]
//         004302f8     PUSH       this=>DAT_fffffff8
//         004302f9     MOV        this,dword ptr [ESP + 0x18]
//         004302fd     PUSH       this=>DAT_fffffff4
//         004302fe     MOV        this,dword ptr [EAX + 0x10c]
//         00430304     MOVSX      EAX,word ptr [EAX + 0x108]
//         0043030b     PUSH       this=>DAT_fffffff0
//         0043030c     PUSH       EAX
//         0043030d     MOV        this,EDI
//         0043030f     CALL       dword ptr [EDX + 0x70]
//                               LAB_00430312                                                 XREF[1]:     004302dc(j)
//                              com_obj.cpp:390 (8)
//         00430312     POP        EDI
//         00430313     POP        ESI
//         00430314     MOV        AL,0x1
//         00430316     POP        EBX
//         00430317     RET        0x14
//         0043031a     ??         90h
//         0043031b     NOP
//         0043031c     NOP
//         0043031d     NOP
//         0043031e     NOP
//         0043031f     NOP
    return 0;
}

void RGE_Combat_Object::damage(int param_1, RGE_Armor_Weapon_Info* param_2, float param_3, RGE_Player* param_4, RGE_Static_Object* param_5) {
    /* TODO: Stub */
//                              void __thiscall damage(RGE_Combat_Object * this, int param_1, RGE_Ar
//              void              <VOID>         <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00430337(R)
//              RGE_Armor_Weap    Stack[0x8]:4   param_2                   XREF[1]:     00430324(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     00430332(R)
//              RGE_Player *      Stack[0x10]:4  param_4                   XREF[1]:     00430320(R)
//              RGE_Static_Obj    Stack[0x14]:4  param_5                   XREF[1]:     0043032b(R)
//                               ?damage@RGE_Combat_Object@@UAEXHPAURGE_Armor_Weapon_Info@@M  XREF[4]:     damage:004c97ac(c),
//                               RGE_Combat_Object::damage                                                 damage:004ca82d(c), 0056f2c8(*),
//                                                                                                         00570760(*)
//                              com_obj.cpp:398 (40)
//         00430320     MOV        EAX,dword ptr [ESP + param_4]
//         00430324     MOV        EDX,dword ptr [ESP + param_2]
//         00430328     PUSH       EBX
//         00430329     PUSH       ESI
//         0043032a     PUSH       EDI
//         0043032b     MOV        EDI,dword ptr [ESP + param_5]
//         0043032f     MOV        ESI,this
//         00430331     PUSH       EDI
//         00430332     MOV        this,dword ptr [ESP + param_3]
//         00430336     PUSH       EAX
//         00430337     MOV        EAX,dword ptr [ESP + param_1]
//         0043033b     MOV        EBX,dword ptr [ESI]
//         0043033d     PUSH       this
//         0043033e     PUSH       EDX
//         0043033f     PUSH       EAX
//         00430340     MOV        this,ESI
//         00430342     CALL       dword ptr [EBX + 0x74]
//         00430345     FSUBR      float ptr [ESI + 0x30]
//                              com_obj.cpp:407 (7)
//         00430348     TEST       EDI,EDI
//         0043034a     FST        float ptr [ESI + 0x30]
//         0043034d     JZ         LAB_00430375
//                              com_obj.cpp:414 (38)
//         0043034f     MOV        this,dword ptr [ESI + 0x8]
//         00430352     MOV        EDI,dword ptr [EDI + 0x4]
//         00430355     MOVSX      EDX,word ptr [ECX + this+0x26]
//         00430359     PUSH       EDX
//         0043035a     CALL       __ftol                                           undefined __ftol()
//         0043035f     PUSH       EAX=>DAT_fffffff8
//         00430360     MOV        EAX,dword ptr [ESI + 0x4]
//         00430363     PUSH       EDI=>DAT_fffffff4
//         00430364     PUSH       offset DAT_fffffff0
//         00430369     PUSH       EAX
//         0043036a     PUSH       EDI
//         0043036b     MOV        this,ESI
//         0043036d     CALL       dword ptr [EBX + 0x148]
//         00430373     JMP        LAB_00430377
//                               LAB_00430375                                                 XREF[1]:     0043034d(j)
//                              com_obj.cpp:404 (2)
//         00430375     FSTP       ST0
//                               LAB_00430377                                                 XREF[1]:     00430373(j)
//                              com_obj.cpp:419 (16)
//         00430377     FLD        float ptr [ESI + 0x30]
//         0043037a     FCOMP      double ptr [DAT_0056f4b0]
//         00430380     FNSTSW     AX
//         00430382     TEST       AH,0x1
//         00430385     JZ         LAB_0043038e
//                              com_obj.cpp:420 (7)
//         00430387     MOV        dword ptr [ESI + 0x30],0x0
//                               LAB_0043038e                                                 XREF[1]:     00430385(j)
//                              com_obj.cpp:425 (6)
//         0043038e     POP        EDI
//         0043038f     POP        ESI
//         00430390     POP        EBX
//         00430391     RET        0x14
//         00430394     ??         90h
//         00430395     NOP
//         00430396     NOP
//         00430397     NOP
//         00430398     NOP
//         00430399     NOP
//         0043039a     NOP
//         0043039b     NOP
//         0043039c     NOP
//         0043039d     NOP
//         0043039e     NOP
//         0043039f     NOP
    return;
}

float RGE_Combat_Object::calculateDamage(int param_1, RGE_Armor_Weapon_Info* param_2, float param_3, RGE_Player* param_4, RGE_Static_Object* param_5) {
    /* TODO: Stub */
//                              float __thiscall calculateDamage(RGE_Combat_Object * this, int param
//              float             ST0:10         <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[6]:     004303e8(R), 00430410(W), 00430426(W), 00430434(R),
//                                                                                     00430438(W), 0043043c(R)
//              RGE_Armor_Weap    Stack[0x8]:4   param_2                   XREF[4]:     004303f6(R), 00430402(W), 0043045d(R), 00430465(W)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     00430446(R)
//              RGE_Player *      Stack[0x10]:4  param_4
//              RGE_Static_Obj    Stack[0x14]:4  param_5
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00430406(W), 0043040a(R)
//                               ?calculateDamage@RGE_Combat_Object@@UAEMHPAURGE_Armor_Weapo  XREF[4]:     0056f2cc(*), 00570764(*),
//                               RGE_Combat_Object::calculateDamage                                        005747ec(*), 00574a94(*)
//                              com_obj.cpp:433 (1)
//         004303a0     PUSH       this
//                              com_obj.cpp:435 (4)
//         004303a1     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004303a4     PUSH       EBX
//                              com_obj.cpp:439 (6)
//         004303a5     FLD        float ptr [DAT_0056f49c]
//                              com_obj.cpp:441 (35)
//         004303ab     MOV        DX,word ptr [EAX + 0x110]
//         004303b2     PUSH       EBP
//         004303b3     MOV        EBP,dword ptr [EAX + 0x104]
//         004303b9     PUSH       ESI
//         004303ba     PUSH       EDI
//         004303bb     MOVSX      EDI,word ptr [EAX + 0x102]
//         004303c2     TEST       DX,DX
//         004303c5     JL         LAB_004303e8
//         004303c7     MOV        ESI,dword ptr [ECX + this->_padding_]
//         004303ca     TEST       ESI,ESI
//         004303cc     JZ         LAB_004303e8
//                              com_obj.cpp:442 (26)
//         004303ce     MOV        this,dword ptr [ECX + this->_padding_]
//         004303d1     MOV        BL,byte ptr [ESI + 0x5]
//         004303d4     MOVSX      EDX,DX
//         004303d7     FSTP       ST0
//         004303d9     MOV        this,dword ptr [ECX + this->_padding_]
//         004303dc     AND        EBX,0x1f
//         004303df     MOV        this,dword ptr [ECX + this->_padding_]
//         004303e2     MOV        EDX,dword ptr [this->_padding_ + EDX*0x4]
//         004303e5     FLD        float ptr [EDX + EBX*0x4]
//                               LAB_004303e8                                                 XREF[2]:     004303c5(j), 004303cc(j)
//                              com_obj.cpp:445 (18)
//         004303e8     MOV        this,dword ptr [ESP + param_1]
//         004303ec     FLD        float ptr [DAT_0056f4a8]
//         004303f2     TEST       this,this
//         004303f4     JLE        LAB_0043046b
//         004303f6     MOV        ESI,dword ptr [ESP + param_2]
//                              com_obj.cpp:448 (20)
//         004303fa     XOR        EDX,EDX
//         004303fc     MOV        DL,byte ptr [EAX + 0x100]
//         00430402     MOV        dword ptr [ESP + param_2],this
//         00430406     MOV        dword ptr [ESP + local_4],EDX
//                               LAB_0043040a                                                 XREF[1]:     00430469(j)
//         0043040a     MOV        EAX,dword ptr [ESP + local_4]
//                              com_obj.cpp:449 (8)
//         0043040e     TEST       EDI,EDI
//         00430410     MOV        dword ptr [ESP + param_1],EAX
//         00430414     JLE        LAB_00430430
//                              com_obj.cpp:450 (12)
//         00430416     MOV        DX,word ptr [ESI]
//         00430419     MOV        EAX,EBP
//         0043041b     MOV        this,EDI
//                               LAB_0043041d                                                 XREF[1]:     0043042e(j)
//         0043041d     CMP        word ptr [EAX],DX
//         00430420     JNZ        LAB_0043042a
//                              com_obj.cpp:451 (14)
//         00430422     MOVSX      EBX,word ptr [EAX + 0x2]
//         00430426     MOV        dword ptr [ESP + param_1],EBX
//                               LAB_0043042a                                                 XREF[1]:     00430420(j)
//         0043042a     ADD        EAX,0x4
//         0043042d     DEC        this
//         0043042e     JNZ        LAB_0043041d
//                               LAB_00430430                                                 XREF[1]:     00430414(j)
//                              com_obj.cpp:461 (26)
//         00430430     MOVSX      this,word ptr [ESI + 0x2]
//         00430434     FILD       dword ptr [ESP + param_1]
//         00430438     MOV        dword ptr [ESP + param_1],this
//         0043043c     FILD       dword ptr [ESP + param_1]
//         00430440     FXCH
//         00430442     FSUBP
//         00430444     FMUL       ST2
//         00430446     FMUL       float ptr [ESP + param_3]
//                              com_obj.cpp:462 (13)
//         0043044a     FCOM       double ptr [DAT_0056f4a0]
//         00430450     FNSTSW     AX
//         00430452     TEST       AH,0x41
//         00430455     JNZ        LAB_0043045b
//                              com_obj.cpp:463 (2)
//         00430457     FADDP
//                              com_obj.cpp:462 (4)
//         00430459     JMP        LAB_0043045d
//                               LAB_0043045b                                                 XREF[1]:     00430455(j)
//         0043045b     FSTP       ST0
//                               LAB_0043045d                                                 XREF[1]:     00430459(j)
//                              com_obj.cpp:463 (14)
//         0043045d     MOV        EAX,dword ptr [ESP + param_2]
//         00430461     ADD        ESI,0x4
//         00430464     DEC        EAX
//         00430465     MOV        dword ptr [ESP + param_2],EAX
//         00430469     JNZ        LAB_0043040a
//                               LAB_0043046b                                                 XREF[1]:     004303f4(j)
//                              com_obj.cpp:466 (10)
//         0043046b     POP        EDI
//         0043046c     POP        ESI
//         0043046d     POP        EBP
//         0043046e     POP        EBX
//         0043046f     FSTP       ST1
//         00430471     POP        this
//         00430472     RET        0x14
//         00430475     ??         90h
//         00430476     NOP
//         00430477     NOP
//         00430478     NOP
//         00430479     NOP
//         0043047a     NOP
//         0043047b     NOP
//         0043047c     NOP
//         0043047d     NOP
//         0043047e     NOP
//         0043047f     NOP
    return 0;
}

uchar RGE_Combat_Object::can_attack() {
    /* TODO: Stub */
//                              uchar __thiscall can_attack(RGE_Combat_Object * this)
//              uchar             AL:1           <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//                               ?can_attack@RGE_Combat_Object@@UAEEXZ                        XREF[4]:     0056f2d4(*), 0057076c(*),
//                               RGE_Combat_Object::can_attack                                             005747f4(*), 00574a9c(*)
//                              com_obj.cpp:472 (19)
//         00430480     FLD        float ptr [ECX + this->attack_timer]
//         00430486     FCOMP      float ptr [DAT_0056f4a8]
//         0043048c     FNSTSW     AX
//         0043048e     TEST       AH,0x41
//         00430491     JNZ        LAB_00430496
//                              com_obj.cpp:474 (2)
//         00430493     XOR        AL,AL
//                              com_obj.cpp:477 (1)
//         00430495     RET
//                               LAB_00430496                                                 XREF[1]:     00430491(j)
//                              com_obj.cpp:476 (2)
//         00430496     MOV        AL,0x1
//                              com_obj.cpp:477 (1)
//         00430498     RET
//         00430499     ??         90h
//         0043049a     NOP
//         0043049b     NOP
//         0043049c     NOP
//         0043049d     NOP
//         0043049e     NOP
//         0043049f     NOP
    return 0;
}

void RGE_Combat_Object::reset_attack_timer() {
    /* TODO: Stub */
//                              void __thiscall reset_attack_timer(RGE_Combat_Object * this)
//              void              <VOID>         <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//                               ?reset_attack_timer@RGE_Combat_Object@@QAEXXZ                XREF[3]:     set_state:004016d3(c),
//                               RGE_Combat_Object::reset_attack_timer                                     update:00401916(c),
//                                                                                                         update:00401961(c)
//                              com_obj.cpp:483 (15)
//         004304a0     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004304a3     FLD        float ptr [EAX + 0x120]
//         004304a9     FSTP       float ptr [ECX + this->attack_timer]
//                              com_obj.cpp:492 (1)
//         004304af     RET
    return;
}

void RGE_Combat_Object::get_armor(short* param_1, short* param_2) {
    /* TODO: Stub */
//                              void __thiscall get_armor(RGE_Combat_Object * this, short * param_1,
//              void              <VOID>         <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              short *           Stack[0x4]:4   param_1                   XREF[1]:     004304b4(R)
//              short *           Stack[0x8]:4   param_2                   XREF[1]:     004304f8(R)
//                               ?get_armor@RGE_Combat_Object@@UAEXAAF0@Z                     XREF[2]:     0056f484(*), 0057091c(*)
//                               RGE_Combat_Object::get_armor
//                              com_obj.cpp:498 (19)
//         004304b0     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004304b3     PUSH       ESI
//         004304b4     MOV        ESI,dword ptr [ESP + param_1]
//         004304b8     MOVZX      DX,byte ptr [EAX + 0x100]
//         004304c0     MOV        word ptr [ESI],DX
//                              com_obj.cpp:502 (14)
//         004304c3     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004304c6     XOR        EDX,EDX
//         004304c8     CMP        word ptr [EAX + 0x102],DX
//         004304cf     JLE        LAB_004304f5
//                              com_obj.cpp:498 (1)
//         004304d1     PUSH       EDI
//                               LAB_004304d2                                                 XREF[1]:     004304f2(j)
//                              com_obj.cpp:504 (16)
//         004304d2     MOV        EAX,dword ptr [EAX + 0x104]
//         004304d8     MOV        AX,word ptr [EAX + EDX*0x4 + 0x2]
//         004304dd     CMP        AX,word ptr [ESI]
//         004304e0     JLE        LAB_004304e5
//                              com_obj.cpp:505 (3)
//         004304e2     MOV        word ptr [ESI],AX
//                               LAB_004304e5                                                 XREF[1]:     004304e0(j)
//                              com_obj.cpp:502 (15)
//         004304e5     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004304e8     INC        EDX
//         004304e9     MOVSX      EDI,word ptr [EAX + 0x102]
//         004304f0     CMP        EDX,EDI
//         004304f2     JL         LAB_004304d2
//                              com_obj.cpp:498 (1)
//         004304f4     POP        EDI
//                               LAB_004304f5                                                 XREF[1]:     004304cf(j)
//                              com_obj.cpp:508 (7)
//         004304f5     MOV        this,dword ptr [ECX + this->_padding_]
//         004304f8     MOV        EAX,dword ptr [ESP + param_2]
//                              com_obj.cpp:509 (14)
//         004304fc     POP        ESI
//         004304fd     MOV        DX,word ptr [ECX + this->_padding_]
//         00430504     MOV        word ptr [EAX],DX
//         00430507     RET        0x8
//         0043050a     ??         90h
//         0043050b     NOP
//         0043050c     NOP
//         0043050d     NOP
//         0043050e     NOP
//         0043050f     NOP
    return;
}

void RGE_Combat_Object::get_weapon(short* param_1, short* param_2) {
    /* TODO: Stub */
//                              void __thiscall get_weapon(RGE_Combat_Object * this, short * param_1
//              void              <VOID>         <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              short *           Stack[0x4]:4   param_1                   XREF[1]:     00430511(R)
//              short *           Stack[0x8]:4   param_2                   XREF[1]:     0043054f(R)
//                               ?get_weapon@RGE_Combat_Object@@UAEXAAF0@Z                    XREF[4]:     0056f488(*), 00570920(*),
//                               RGE_Combat_Object::get_weapon                                             005749a8(*), 00574c50(*)
//                              com_obj.cpp:515 (1)
//         00430510     PUSH       ESI
//                              com_obj.cpp:518 (4)
//         00430511     MOV        ESI,dword ptr [ESP + param_1]
//                              com_obj.cpp:519 (19)
//         00430515     XOR        EDX,EDX
//         00430517     MOV        word ptr [ESI],0x0
//         0043051c     MOV        EAX,dword ptr [ECX + this->_padding_]
//         0043051f     CMP        word ptr [EAX + 0x108],DX
//         00430526     JLE        LAB_0043054c
//                              com_obj.cpp:515 (1)
//         00430528     PUSH       EDI
//                               LAB_00430529                                                 XREF[1]:     00430549(j)
//                              com_obj.cpp:521 (16)
//         00430529     MOV        EAX,dword ptr [EAX + 0x10c]
//         0043052f     MOV        AX,word ptr [EAX + EDX*0x4 + 0x2]
//         00430534     CMP        AX,word ptr [ESI]
//         00430537     JLE        LAB_0043053c
//                              com_obj.cpp:522 (3)
//         00430539     MOV        word ptr [ESI],AX
//                               LAB_0043053c                                                 XREF[1]:     00430537(j)
//                              com_obj.cpp:519 (15)
//         0043053c     MOV        EAX,dword ptr [ECX + this->_padding_]
//         0043053f     INC        EDX
//         00430540     MOVSX      EDI,word ptr [EAX + 0x108]
//         00430547     CMP        EDX,EDI
//         00430549     JL         LAB_00430529
//                              com_obj.cpp:515 (1)
//         0043054b     POP        EDI
//                               LAB_0043054c                                                 XREF[1]:     00430526(j)
//                              com_obj.cpp:525 (7)
//         0043054c     MOV        this,dword ptr [ECX + this->_padding_]
//         0043054f     MOV        EAX,dword ptr [ESP + param_2]
//                              com_obj.cpp:526 (14)
//         00430553     POP        ESI
//         00430554     MOV        DX,word ptr [ECX + this+0x13e]
//         0043055b     MOV        word ptr [EAX],DX
//         0043055e     RET        0x8
//         00430561     ??         90h
//         00430562     NOP
//         00430563     NOP
//         00430564     NOP
//         00430565     NOP
//         00430566     NOP
//         00430567     NOP
//         00430568     NOP
//         00430569     NOP
//         0043056a     NOP
//         0043056b     NOP
//         0043056c     NOP
//         0043056d     NOP
//         0043056e     NOP
//         0043056f     NOP
    return;
}

void RGE_Combat_Object::get_weapon_range(float* param_1, float* param_2) {
    /* TODO: Stub */
//                              void __thiscall get_weapon_range(RGE_Combat_Object * this, float * p
//              void              <VOID>         <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              float *           Stack[0x4]:4   param_1                   XREF[1]:     00430579(R)
//              float *           Stack[0x8]:4   param_2                   XREF[1]:     00430582(R)
//                               ?get_weapon_range@RGE_Combat_Object@@UAEXAAM0@Z              XREF[4]:     0056f48c(*), 00570924(*),
//                               RGE_Combat_Object::get_weapon_range                                       005749ac(*), 00574c54(*)
//                              com_obj.cpp:532 (15)
//         00430570     MOV        EAX,dword ptr [ECX + this->_padding_]
//         00430573     MOV        EDX,dword ptr [EAX + 0x114]
//         00430579     MOV        EAX,dword ptr [ESP + param_1]
//         0043057d     MOV        dword ptr [EAX],EDX
//                              com_obj.cpp:534 (15)
//         0043057f     MOV        this,dword ptr [ECX + this->_padding_]
//         00430582     MOV        EAX,dword ptr [ESP + param_2]
//         00430586     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0043058c     MOV        dword ptr [EAX],EDX
//                              com_obj.cpp:535 (3)
//         0043058e     RET        0x8
//         00430591     ??         90h
//         00430592     NOP
//         00430593     NOP
//         00430594     NOP
//         00430595     NOP
//         00430596     NOP
//         00430597     NOP
//         00430598     NOP
//         00430599     NOP
//         0043059a     NOP
//         0043059b     NOP
//         0043059c     NOP
//         0043059d     NOP
//         0043059e     NOP
//         0043059f     NOP
    return;
}

void RGE_Combat_Object::get_speed_of_attack(float* param_1, float* param_2) {
    /* TODO: Stub */
//                              void __thiscall get_speed_of_attack(RGE_Combat_Object * this, float
//              void              <VOID>         <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              float *           Stack[0x4]:4   param_1                   XREF[1]:     004305a9(R)
//              float *           Stack[0x8]:4   param_2                   XREF[1]:     004305b2(R)
//                               ?get_speed_of_attack@RGE_Combat_Object@@UAEXAAM0@Z           XREF[4]:     0056f490(*), 00570928(*),
//                               RGE_Combat_Object::get_speed_of_attack                                    005749b0(*), 00574c58(*)
//                              com_obj.cpp:541 (15)
//         004305a0     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004305a3     MOV        EDX,dword ptr [EAX + 0x120]
//         004305a9     MOV        EAX,dword ptr [ESP + param_1]
//         004305ad     MOV        dword ptr [EAX],EDX
//                              com_obj.cpp:543 (15)
//         004305af     MOV        this,dword ptr [ECX + this->_padding_]
//         004305b2     MOV        EAX,dword ptr [ESP + param_2]
//         004305b6     MOV        EDX,dword ptr [ECX + this->_padding_]
//         004305bc     MOV        dword ptr [EAX],EDX
//                              com_obj.cpp:544 (3)
//         004305be     RET        0x8
//         004305c1     ??         90h
//         004305c2     NOP
//         004305c3     NOP
//         004305c4     NOP
//         004305c5     NOP
//         004305c6     NOP
//         004305c7     NOP
//         004305c8     NOP
//         004305c9     NOP
//         004305ca     NOP
//         004305cb     NOP
//         004305cc     NOP
//         004305cd     NOP
//         004305ce     NOP
//         004305cf     NOP
    return;
}

void RGE_Combat_Object::release_being_worked_on(RGE_Static_Object* param_1) {
    /* TODO: Stub */
//                              void __thiscall release_being_worked_on(RGE_Combat_Object * this, RG
//              void              <VOID>         <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004305d2(R)
//                               ?release_being_worked_on@RGE_Combat_Object@@UAEXPAVRGE_Stat  XREF[4]:     0056f31c(*), 005707b4(*),
//                               RGE_Combat_Object::release_being_worked_on                                0057483c(*), 00574ae4(*)
//                              com_obj.cpp:550 (2)
//         004305d0     PUSH       ESI
//         004305d1     PUSH       EDI
//                              com_obj.cpp:551 (12)
//         004305d2     MOV        EDI,dword ptr [ESP + param_1]
//         004305d6     MOV        ESI,this
//         004305d8     PUSH       EDI
//         004305d9     CALL       RGE_Animated_Object::release_being_worked_on     void release_being_worked_on(RGE_Animated_Obj
//                              com_obj.cpp:553 (7)
//         004305de     MOV        EAX,dword ptr [EDI + 0x4]
//         004305e1     TEST       EAX,EAX
//         004305e3     JL         LAB_00430605
//                              com_obj.cpp:560 (32)
//         004305e5     MOV        this,dword ptr [EDI + 0x8]
//         004305e8     MOV        EDX,dword ptr [ESI]
//         004305ea     PUSH       0x0
//         004305ec     PUSH       0x0
//         004305ee     MOVSX      this,word ptr [ECX + this->_padding_]
//         004305f2     PUSH       this
//         004305f3     MOV        this,dword ptr [ESI + 0x4]
//         004305f6     PUSH       0x2bb
//         004305fb     PUSH       this
//         004305fc     PUSH       EAX
//         004305fd     MOV        this,ESI
//         004305ff     CALL       dword ptr [EDX + 0x148]
//                               LAB_00430605                                                 XREF[1]:     004305e3(j)
//                              com_obj.cpp:562 (5)
//         00430605     POP        EDI
//         00430606     POP        ESI
//         00430607     RET        0x4
//         0043060a     ??         90h
//         0043060b     NOP
//         0043060c     NOP
//         0043060d     NOP
//         0043060e     NOP
//         0043060f     NOP
    return;
}

void RGE_Combat_Object::enter_obj(RGE_Static_Object* param_1) {
    /* TODO: Stub */
//                              void __thiscall enter_obj(RGE_Combat_Object * this, RGE_Static_Objec
//              void              <VOID>         <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00430610(R)
//                               ?enter_obj@RGE_Combat_Object@@UAEXPAVRGE_Static_Object@@@Z   XREF[4]:     0056f328(*), 005707c0(*),
//                               RGE_Combat_Object::enter_obj                                              00574848(*), 00574af0(*)
//                              com_obj.cpp:569 (14)
//         00430610     MOV        EAX,dword ptr [ESP + param_1]
//         00430614     PUSH       ESI
//         00430615     PUSH       EDI
//         00430616     MOV        ESI,this
//         00430618     PUSH       EAX
//         00430619     CALL       RGE_Static_Object::enter_obj                     void enter_obj(RGE_Static_Object * this, RGE_
//                              com_obj.cpp:572 (7)
//         0043061e     MOV        EAX,dword ptr [ESI + 0x20]
//         00430621     TEST       EAX,EAX
//         00430623     JZ         LAB_00430674
//                              com_obj.cpp:574 (7)
//         00430625     MOV        EDI,dword ptr [ESI + 0x4]
//         00430628     TEST       EDI,EDI
//         0043062a     JL         LAB_00430674
//                              com_obj.cpp:577 (62)
//         0043062c     MOV        EAX,dword ptr [ESI + 0x8]
//         0043062f     MOV        EDX,dword ptr [ESI + 0x1b8]
//         00430635     FLD        float ptr [ESI + 0x3c]
//         00430638     LEA        this,[ESI + 0x194]
//         0043063e     PUSH       this
//         0043063f     PUSH       0x0
//         00430641     MOVSX      this,word ptr [EAX + 0x14]
//         00430645     PUSH       EDX
//         00430646     PUSH       this
//         00430647     CALL       __ftol                                           undefined __ftol()
//         0043064c     FLD        float ptr [ESI + 0x38]
//         0043064f     PUSH       EAX
//         00430650     CALL       __ftol                                           undefined __ftol()
//         00430655     MOV        EDX,dword ptr [ESI + 0xc]
//         00430658     MOV        this,dword ptr [VisibleUnitManager]              = 00000000
//         0043065e     PUSH       EAX
//         0043065f     MOVSX      EAX,word ptr [EDX + 0x4a]
//         00430663     PUSH       EAX
//         00430664     PUSH       EDI
//         00430665     CALL       Visible_Unit_Manager::Update_Unit_Info           void Update_Unit_Info(Visible_Unit_Manager *
//                              com_obj.cpp:578 (10)
//         0043066a     MOV        dword ptr [ESI + 0x1b8],0x0
//                               LAB_00430674                                                 XREF[2]:     00430623(j), 0043062a(j)
//                              com_obj.cpp:582 (5)
//         00430674     POP        EDI
//         00430675     POP        ESI
//         00430676     RET        0x4
//         00430679     ??         90h
//         0043067a     NOP
//         0043067b     NOP
//         0043067c     NOP
//         0043067d     NOP
//         0043067e     NOP
//         0043067f     NOP
    return;
}

uchar RGE_Combat_Object::update() {
    /* TODO: Stub */
//                              uchar __thiscall update(RGE_Combat_Object * this)
//              uchar             AL:1           <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00430689(W), 00430780(R)
//              long              Stack[-0x8]:4  sighted_by_player         XREF[0,2]:   004306dd(W), 004307f6(R)
//              uchar             Stack[-0x9]:1  returnResult
//                               ?update@RGE_Combat_Object@@UAEEXZ                            XREF[3]:     update:0045a940(j),
//                               RGE_Combat_Object::update                                                 update:004ca635(c), 0056f27c(*)
//                              com_obj.cpp:589 (9)
//         00430680     SUB        ESP,0x8
//         00430683     PUSH       EBX
//         00430684     PUSH       EBP
//         00430685     PUSH       ESI
//         00430686     MOV        ESI,this
//         00430688     PUSH       EDI
//                              com_obj.cpp:595 (8)
//         00430689     MOV        dword ptr [ESP + local_4],0xffffffff
//                              com_obj.cpp:610 (19)
//         00430691     FLD        float ptr [ESI + 0x1bc]
//         00430697     FCOMP      float ptr [DAT_0056f4a8]
//         0043069d     FNSTSW     AX
//         0043069f     TEST       AH,0x41
//         004306a2     JNZ        LAB_004306d3
//                              com_obj.cpp:612 (18)
//         004306a4     MOV        EAX,dword ptr [ESI + 0xc]
//         004306a7     FLD        float ptr [ESI + 0x1bc]
//         004306ad     MOV        this,dword ptr [EAX + 0x3c]
//         004306b0     FSUB       float ptr [ECX + this->_padding_]
//                              com_obj.cpp:613 (19)
//         004306b6     FCOM       float ptr [DAT_0056f4a8]
//         004306bc     FSTP       float ptr [ESI + 0x1bc]
//         004306c2     FNSTSW     AX
//         004306c4     TEST       AH,0x1
//         004306c7     JZ         LAB_004306d3
//                              com_obj.cpp:614 (10)
//         004306c9     MOV        dword ptr [ESI + 0x1bc],0x0
//                               LAB_004306d3                                                 XREF[2]:     004306a2(j), 004306c7(j)
//                              com_obj.cpp:618 (7)
//         004306d3     MOV        this,ESI
//         004306d5     CALL       RGE_Action_Object::update                        uchar update(RGE_Action_Object * this)
//                              com_obj.cpp:632 (26)
//         004306da     MOV        EBX,dword ptr [ESI + 0x4]
//         004306dd     MOV        byte ptr [ESP + sighted_by_player+0x3],AL
//         004306e1     TEST       EBX,EBX
//         004306e3     JL         LAB_004307c2
//         004306e9     MOV        EAX,dword ptr [ESI + 0x20]
//         004306ec     TEST       EAX,EAX
//         004306ee     JNZ        LAB_004307c2
//                              com_obj.cpp:634 (8)
//         004306f4     FLD        float ptr [ESI + 0x38]
//         004306f7     CALL       __ftol                                           undefined __ftol()
//                              com_obj.cpp:635 (10)
//         004306fc     FLD        float ptr [ESI + 0x3c]
//         004306ff     MOV        EBP,EAX
//         00430701     CALL       __ftol                                           undefined __ftol()
//                              com_obj.cpp:637 (16)
//         00430706     MOV        EDX,dword ptr [EAX*0x4 + unified_map_offsets]    = 00000000
//         0043070d     MOV        this,dword ptr [ESI + 0x1b8]
//         00430713     MOV        EDI,dword ptr [EDX + EBP*0x4]
//                              com_obj.cpp:641 (14)
//         00430716     CMP        EDI,this
//         00430718     MOV        dword ptr [ESI + 0x1b8],EDI
//         0043071e     JZ         LAB_004307c2
//                              com_obj.cpp:644 (39)
//         00430724     LEA        EDX,[ESI + 0x194]
//         0043072a     PUSH       EDX
//         0043072b     PUSH       EDI
//         0043072c     PUSH       this
//         0043072d     MOV        this,dword ptr [ESI + 0x8]
//         00430730     MOVSX      EDX,word ptr [ECX + this->_padding_]
//         00430734     PUSH       EDX
//         00430735     PUSH       EAX
//         00430736     MOV        EAX,dword ptr [ESI + 0xc]
//         00430739     PUSH       EBP
//         0043073a     MOVSX      this,word ptr [EAX + 0x4a]
//         0043073e     PUSH       this
//         0043073f     MOV        this,dword ptr [VisibleUnitManager]              = 00000000
//         00430745     PUSH       EBX
//         00430746     CALL       Visible_Unit_Manager::Update_Unit_Info           void Update_Unit_Info(Visible_Unit_Manager *
//                              com_obj.cpp:646 (10)
//         0043074b     MOV        AL,byte ptr [ESI + 0x1c0]
//         00430751     TEST       AL,AL
//         00430753     JZ         LAB_004307c2
//                              com_obj.cpp:648 (19)
//         00430755     MOV        EAX,dword ptr [ESI + 0xc]
//         00430758     MOV        this,0x1
//         0043075d     MOV        EBX,dword ptr [EAX + 0x3c]
//         00430760     MOVSX      EDX,word ptr [EBX + 0x3c]
//         00430764     CMP        EDX,this
//         00430766     JLE        LAB_00430780
//                              com_obj.cpp:649 (19)
//         00430768     MOVSX      EAX,word ptr [EAX + 0x4a]
//                               LAB_0043076c                                                 XREF[1]:     0043077e(j)
//         0043076c     CMP        this,EAX
//         0043076e     JZ         LAB_0043077b
//         00430770     MOV        EBP,0x1
//         00430775     SHL        EBP,this
//         00430777     TEST       EDI,EBP
//         00430779     JA         LAB_00430784
//                               LAB_0043077b                                                 XREF[1]:     0043076e(j)
//                              com_obj.cpp:648 (5)
//         0043077b     INC        this
//         0043077c     CMP        this,EDX
//         0043077e     JL         LAB_0043076c
//                               LAB_00430780                                                 XREF[1]:     00430766(j)
//                              com_obj.cpp:651 (4)
//         00430780     MOV        this,dword ptr [ESP + local_4]
//                               LAB_00430784                                                 XREF[1]:     00430779(j)
//                              com_obj.cpp:658 (26)
//         00430784     TEST       this,this
//         00430786     JL         LAB_004307c2
//         00430788     MOV        EDX,dword ptr [EBX + 0x40]
//         0043078b     LEA        EDI,[this->_padding_*0x4 + 0x0]
//         00430792     MOV        this,dword ptr [EDX + this->_padding_*0x4]
//         00430795     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
//         0043079a     TEST       EAX,EAX
//         0043079c     JNZ        LAB_004307c2
//                              com_obj.cpp:660 (20)
//         0043079e     MOV        this,dword ptr [ESI + 0xc]
//         004307a1     MOV        EAX,dword ptr [ESI]
//         004307a3     MOV        EDX,dword ptr [ECX + this->_padding_]
//         004307a6     MOV        this,dword ptr [EDX + 0x40]
//         004307a9     MOV        EDX,dword ptr [this->_padding_ + EDI*0x1]
//         004307ac     MOV        this,ESI
//         004307ae     PUSH       EDX
//         004307af     CALL       dword ptr [EAX + 0x44]
//                              com_obj.cpp:661 (9)
//         004307b2     CMP        byte ptr [ESI + 0x1c0],0x1
//         004307b9     JNZ        LAB_004307c2
//                              com_obj.cpp:662 (7)
//         004307bb     MOV        byte ptr [ESI + 0x1c0],0x0
//                               LAB_004307c2                                                 XREF[7]:     004306e3(j), 004306ee(j),
//                                                                                                         0043071e(j), 00430753(j),
//                                                                                                         00430786(j), 0043079c(j),
//                                                                                                         004307b9(j)
//                              com_obj.cpp:673 (27)
//         004307c2     MOV        EAX,dword ptr [ESI + 0x74]
//         004307c5     TEST       EAX,EAX
//         004307c7     JZ         LAB_004307f6
//         004307c9     MOV        EAX,dword ptr [ESI + 0xc]
//         004307cc     MOVSX      this,word ptr [EAX + 0x4a]
//         004307d0     PUSH       this
//         004307d1     MOV        this,dword ptr [EAX + 0x3c]
//         004307d4     CALL       RGE_Game_World::is_player_turn                   int is_player_turn(RGE_Game_World * this, int
//         004307d9     TEST       EAX,EAX
//         004307db     JZ         LAB_004307f6
//                              com_obj.cpp:675 (25)
//         004307dd     MOV        EAX,dword ptr [ESI + 0xc]
//         004307e0     MOVSX      EDX,word ptr [EAX + 0x4a]
//         004307e4     MOV        this,dword ptr [EAX + 0x3c]
//         004307e7     PUSH       EDX
//         004307e8     CALL       RGE_Game_World::get_accum_time_delta             ulong get_accum_time_delta(RGE_Game_World * t
//         004307ed     MOV        this,dword ptr [ESI + 0x74]
//         004307f0     PUSH       EAX
//         004307f1     CALL       UnitAIModule::update                             int update(UnitAIModule * this, ulong param_1)
//                               LAB_004307f6                                                 XREF[2]:     004307c7(j), 004307db(j)
//                              com_obj.cpp:710 (4)
//         004307f6     MOV        AL,byte ptr [ESP + sighted_by_player+0x3]
//                              com_obj.cpp:711 (8)
//         004307fa     POP        EDI
//         004307fb     POP        ESI
//         004307fc     POP        EBP
//         004307fd     POP        EBX
//         004307fe     ADD        ESP,0x8
//         00430801     RET
//         00430802     ??         90h
//         00430803     NOP
//         00430804     NOP
//         00430805     NOP
//         00430806     NOP
//         00430807     NOP
//         00430808     NOP
//         00430809     NOP
//         0043080a     NOP
//         0043080b     NOP
//         0043080c     NOP
//         0043080d     NOP
//         0043080e     NOP
//         0043080f     NOP
    return 0;
}

void RGE_Combat_Object::copy_obj(RGE_Master_Static_Object* param_1) {
    /* TODO: Stub */
//                              void __thiscall copy_obj(RGE_Combat_Object * this, RGE_Master_Static
//              void              <VOID>         <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              RGE_Master_Sta    Stack[0x4]:4   param_1                   XREF[1]:     00430824(R)
//                               ?copy_obj@RGE_Combat_Object@@UAEXPAVRGE_Master_Static_Objec  XREF[4]:     copy_obj:004c9737(c), 0056f2b0(*),
//                               RGE_Combat_Object::copy_obj                                               00570748(*), 00574a78(*)
//                              com_obj.cpp:717 (4)
//         00430810     PUSH       ESI
//         00430811     MOV        ESI,this
//         00430813     PUSH       EDI
//                              com_obj.cpp:719 (2)
//         00430814     XOR        EAX,EAX
//                              com_obj.cpp:721 (26)
//         00430816     MOV        this,dword ptr [ESI + 0x8]
//         00430819     MOV        EDX,dword ptr [ESI + 0x10]
//         0043081c     MOV        EDI,dword ptr [ECX + this->_padding_]
//         00430822     CMP        EDX,EDI
//         00430824     MOV        EDI,dword ptr [ESP + param_1]
//         00430828     JNZ        LAB_00430830
//         0043082a     MOV        EAX,dword ptr [EDI + 0xfc]
//                               LAB_00430830                                                 XREF[1]:     00430828(j)
//                              com_obj.cpp:723 (4)
//         00430830     TEST       EAX,EAX
//         00430832     JZ         LAB_0043083c
//                              com_obj.cpp:724 (8)
//         00430834     MOV        EDX,dword ptr [ESI]
//         00430836     PUSH       EAX
//         00430837     MOV        this,ESI
//         00430839     CALL       dword ptr [EDX + 0x38]
//                               LAB_0043083c                                                 XREF[1]:     00430832(j)
//                              com_obj.cpp:726 (8)
//         0043083c     PUSH       EDI
//         0043083d     MOV        this,ESI
//         0043083f     CALL       RGE_Action_Object::copy_obj                      void copy_obj(RGE_Action_Object * this, RGE_M
//                              com_obj.cpp:727 (5)
//         00430844     POP        EDI
//         00430845     POP        ESI
//         00430846     RET        0x4
//         00430849     ??         90h
//         0043084a     NOP
//         0043084b     NOP
//         0043084c     NOP
//         0043084d     NOP
//         0043084e     NOP
//         0043084f     NOP
    return;
}

void RGE_Combat_Object::notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6) {
    /* TODO: Stub */
//                              void __thiscall notify(RGE_Combat_Object * this, int param_1, int pa
//              void              <VOID>         <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[2]:     00430885(R), 004308ab(R)
//              int               Stack[0x8]:4   param_2                   XREF[2]:     0043087a(R), 0043089d(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     00430872(R)
//              long              Stack[0x10]:4  param_4                   XREF[1]:     0043086e(R)
//              long              Stack[0x14]:4  param_5                   XREF[1]:     0043086a(R)
//              long              Stack[0x18]:4  param_6                   XREF[1]:     00430866(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0043085d(W)
//                               ?notify@RGE_Combat_Object@@UAEXHHHJJJ@Z                      XREF[4]:     0056f3a0(*), 00570838(*),
//                               RGE_Combat_Object::notify                                                 005748c0(*), 00574b68(*)
//                              com_obj.cpp:734 (6)
//         00430850     PUSH       this
//         00430851     MOV        EAX,this
//         00430853     PUSH       EBX
//         00430854     PUSH       EBP
//         00430855     PUSH       ESI
//                              com_obj.cpp:739 (13)
//         00430856     MOV        this,byte ptr [EAX + 0x48]
//         00430859     PUSH       EDI
//         0043085a     CMP        this,0x2
//         0043085d     MOV        dword ptr [ESP + local_4],EAX
//         00430861     JNZ        LAB_004308b6
//                              com_obj.cpp:751 (58)
//         00430863     MOV        this,dword ptr [EAX + 0x74]
//         00430866     MOV        EDI,dword ptr [ESP + param_6]
//         0043086a     MOV        EBX,dword ptr [ESP + param_5]
//         0043086e     MOV        EBP,dword ptr [ESP + param_4]
//         00430872     MOV        ESI,dword ptr [ESP + param_3]
//         00430876     TEST       this,this
//         00430878     JZ         LAB_00430895
//         0043087a     MOV        EDX,dword ptr [ESP + param_2]
//         0043087e     MOV        EAX,dword ptr [this->_padding_]
//         00430880     PUSH       EDI
//         00430881     PUSH       EBX
//         00430882     PUSH       EBP
//         00430883     PUSH       ESI
//         00430884     PUSH       EDX
//         00430885     MOV        EDX,dword ptr [ESP + param_1]
//         00430889     PUSH       EDX
//         0043088a     CALL       dword ptr [EAX + 0x14]
//         0043088d     TEST       EAX,EAX
//         0043088f     JNZ        LAB_004308b6
//         00430891     MOV        EAX,dword ptr [ESP + 0x10]
//                               LAB_00430895                                                 XREF[1]:     00430878(j)
//         00430895     CMP        ESI,0x2bb
//         0043089b     JZ         LAB_004308b6
//                              com_obj.cpp:752 (25)
//         0043089d     MOV        EDX,dword ptr [ESP + param_2]
//         004308a1     MOV        this,dword ptr [EAX + 0xc]
//         004308a4     PUSH       EDI
//         004308a5     PUSH       EBX=>DAT_fffffff8
//         004308a6     MOV        EAX,dword ptr [this->_padding_]
//         004308a8     PUSH       EBP=>DAT_fffffff4
//         004308a9     PUSH       ESI=>DAT_fffffff0
//         004308aa     PUSH       EDX
//         004308ab     MOV        EDX,dword ptr [ESP + param_1]
//         004308af     PUSH       EDX
//         004308b0     CALL       dword ptr [EAX + 0xe8]
//                               LAB_004308b6                                                 XREF[3]:     00430861(j), 0043088f(j),
//                                                                                                         0043089b(j)
//                              com_obj.cpp:753 (8)
//         004308b6     POP        EDI
//         004308b7     POP        ESI
//         004308b8     POP        EBP
//         004308b9     POP        EBX
//         004308ba     POP        this
//         004308bb     RET        0x18
//         004308be     ??         90h
//         004308bf     NOP
    return;
}

int RGE_Combat_Object::attack(int param_1, int param_2) {
    /* TODO: Stub */
//                              int __thiscall attack(RGE_Combat_Object * this, int param_1, int par
//              int               EAX:4          <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004308ce(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     00430902(R)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004308ef(R)
//                               ?attack@RGE_Combat_Object@@UAEHHH@Z                          XREF[4]:     0056f3a8(*), 00570840(*),
//                               RGE_Combat_Object::attack                                                 005748c8(*), 00574b70(*)
//                              com_obj.cpp:759 (14)
//         004308c0     MOV        EAX,FS:[0x0]
//         004308c6     PUSH       -0x1
//         004308c8     PUSH       FUN_0055cdbb
//         004308cd     PUSH       EAX
//                              com_obj.cpp:765 (29)
//         004308ce     MOV        EAX,dword ptr [ESP + param_1]
//         004308d2     MOV        dword ptr FS:[0x0],ESP
//         004308d9     PUSH       ESI
//         004308da     MOV        ESI,this
//         004308dc     PUSH       EDI
//         004308dd     PUSH       EAX
//         004308de     MOV        this,dword ptr [ESI + 0xc]
//         004308e1     MOV        this,dword ptr [ECX + this->_padding_]
//         004308e4     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
//         004308e9     MOV        EDI,EAX
//                              com_obj.cpp:766 (4)
//         004308eb     TEST       EDI,EDI
//         004308ed     JNZ        LAB_00430902
//                              com_obj.cpp:821 (19)
//         004308ef     MOV        this,dword ptr [ESP + local_c]
//         004308f3     MOV        dword ptr FS:[0x0],this
//         004308fa     POP        EDI
//         004308fb     POP        ESI
//         004308fc     ADD        ESP,0xc
//         004308ff     RET        0x8
//                               LAB_00430902                                                 XREF[1]:     004308ed(j)
//                              com_obj.cpp:779 (95)
//         00430902     MOV        EAX,dword ptr [ESP + param_2]
//         00430906     TEST       EAX,EAX
//         00430908     JNZ        LAB_00430967
//         0043090a     MOV        this,dword ptr [ESI + 0x184]
//         00430910     CALL       RGE_Action_List::have_action                     uchar have_action(RGE_Action_List * this)
//         00430915     CMP        AL,0x1
//         00430917     JNZ        LAB_00430967
//         00430919     MOV        this,dword ptr [ESI + 0x184]
//         0043091f     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         00430924     MOV        EDX,dword ptr [EAX]
//         00430926     MOV        this,EAX
//         00430928     CALL       dword ptr [EDX + 0x4c]
//         0043092b     CMP        EAX,EDI
//         0043092d     JNZ        LAB_00430967
//         0043092f     MOV        this,dword ptr [ESI + 0x184]
//         00430935     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         0043093a     MOV        EDX,dword ptr [EAX]
//         0043093c     MOV        this,EAX
//         0043093e     CALL       dword ptr [EDX + 0x18]
//         00430941     CMP        AX,0x9
//         00430945     JZ         LAB_00430a71
//         0043094b     MOV        this,dword ptr [ESI + 0x184]
//         00430951     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         00430956     MOV        EDX,dword ptr [EAX]
//         00430958     MOV        this,EAX
//         0043095a     CALL       dword ptr [EDX + 0x18]
//         0043095d     CMP        AX,0x7
//                              com_obj.cpp:784 (6)
//         00430961     JZ         LAB_00430a71
//                               LAB_00430967                                                 XREF[3]:     00430908(j), 00430917(j),
//                                                                                                         0043092d(j)
//                              com_obj.cpp:790 (61)
//         00430967     MOV        this,dword ptr [ESI + 0x184]
//         0043096d     CALL       RGE_Action_List::have_action                     uchar have_action(RGE_Action_List * this)
//         00430972     CMP        AL,0x1
//         00430974     JNZ        LAB_004309c8
//         00430976     MOV        this,dword ptr [ESI + 0x184]
//         0043097c     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         00430981     MOV        EDX,dword ptr [EAX]
//         00430983     MOV        this,EAX
//         00430985     CALL       dword ptr [EDX + 0x4c]
//         00430988     CMP        EAX,EDI
//         0043098a     JNZ        LAB_004309c8
//         0043098c     MOV        this,dword ptr [ESI + 0x184]
//         00430992     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         00430997     MOV        EDX,dword ptr [EAX]
//         00430999     MOV        this,EAX
//         0043099b     CALL       dword ptr [EDX + 0x18]
//         0043099e     CMP        AX,0x9
//         004309a2     JNZ        LAB_004309c8
//                              com_obj.cpp:793 (31)
//         004309a4     MOV        this,dword ptr [ESI + 0x184]
//         004309aa     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         004309af     MOV        this,dword ptr [EDI + 0x40]
//         004309b2     MOV        EDX,dword ptr [EAX]
//         004309b4     PUSH       this
//         004309b5     MOV        this,dword ptr [EDI + 0x3c]
//         004309b8     PUSH       this=>DAT_fffffff8
//         004309b9     MOV        this,dword ptr [EDI + 0x38]
//         004309bc     PUSH       this=>DAT_fffffff4
//         004309bd     PUSH       EDI=>DAT_fffffff0
//         004309be     MOV        this,EAX
//         004309c0     CALL       dword ptr [EDX + 0x34]
//                              com_obj.cpp:794 (5)
//         004309c3     JMP        LAB_00430a71
//                               LAB_004309c8                                                 XREF[3]:     00430974(j), 0043098a(j),
//                                                                                                         004309a2(j)
//                              com_obj.cpp:799 (26)
//         004309c8     MOV        EDX,dword ptr [ESI + 0x8]
//         004309cb     CMP        word ptr [EDX + 0x14],0x4
//         004309d0     JNZ        LAB_004309ea
//         004309d2     MOV        EAX,dword ptr [ESI + 0xc]
//         004309d5     MOV        this,dword ptr [EAX + 0x24]
//         004309d8     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004309de     TEST       EAX,EAX
//         004309e0     JZ         LAB_004309ea
//                              com_obj.cpp:800 (8)
//         004309e2     MOV        EDX,dword ptr [ESI]
//         004309e4     PUSH       EAX
//         004309e5     MOV        this,ESI
//         004309e7     CALL       dword ptr [EDX + 0x54]
//                               LAB_004309ea                                                 XREF[2]:     004309d0(j), 004309e0(j)
//                              com_obj.cpp:806 (80)
//         004309ea     PUSH       0x5c
//         004309ec     CALL       operator_new                                     void * operator_new(uint param_1)
//         004309f1     ADD        ESP,0x4
//         004309f4     MOV        dword ptr [ESP + 0x18],EAX
//         004309f8     TEST       EAX,EAX
//         004309fa     MOV        dword ptr [ESP + 0x10],0x0
//         00430a02     JZ         LAB_00430a38
//         00430a04     MOV        EDX,dword ptr [ESI + 0x8]
//         00430a07     MOV        this,word ptr [EDX + 0x12a]
//         00430a0e     PUSH       this
//         00430a0f     MOV        this,word ptr [EDX + 0x124]
//         00430a16     PUSH       this=>DAT_fffffff8
//         00430a17     MOV        this,dword ptr [EDX + 0x138]
//         00430a1d     MOV        EDX,dword ptr [EDX + 0x114]
//         00430a23     PUSH       this=>DAT_fffffff4
//         00430a24     PUSH       EDX=>DAT_fffffff0
//         00430a25     PUSH       0x0
//         00430a27     PUSH       0x0
//         00430a29     PUSH       0x0
//         00430a2b     PUSH       EDI
//         00430a2c     PUSH       ESI
//         00430a2d     MOV        this,EAX
//         00430a2f     CALL       RGE_Action_Attack::RGE_Action_Attack             undefined RGE_Action_Attack(RGE_Action_Attack
//         00430a34     MOV        EDI,EAX
//         00430a36     JMP        LAB_00430a3a
//                               LAB_00430a38                                                 XREF[1]:     00430a02(j)
//         00430a38     XOR        EDI,EDI
//                               LAB_00430a3a                                                 XREF[1]:     00430a36(j)
//                              com_obj.cpp:807 (12)
//         00430a3a     TEST       EDI,EDI
//         00430a3c     MOV        dword ptr [ESP + 0x10],0xffffffff
//         00430a44     JNZ        LAB_00430a5b
//                              com_obj.cpp:811 (2)
//         00430a46     XOR        EAX,EAX
//                              com_obj.cpp:821 (19)
//         00430a48     MOV        this,dword ptr [ESP + 0x8]
//         00430a4c     MOV        dword ptr FS:[0x0],this
//         00430a53     POP        EDI
//         00430a54     POP        ESI
//         00430a55     ADD        ESP,0xc
//         00430a58     RET        0x8
//                               LAB_00430a5b                                                 XREF[1]:     00430a44(j)
//                              com_obj.cpp:813 (11)
//         00430a5b     MOV        this,dword ptr [ESI + 0x184]
//         00430a61     CALL       RGE_Action_List::delete_list                     void delete_list(RGE_Action_List * this)
//                              com_obj.cpp:814 (11)
//         00430a66     MOV        EAX,dword ptr [ESI]
//         00430a68     PUSH       EDI
//         00430a69     MOV        this,ESI
//         00430a6b     CALL       dword ptr [EAX + 0x208]
//                               LAB_00430a71                                                 XREF[3]:     00430945(j), 00430961(j),
//                                                                                                         004309c3(j)
//                              com_obj.cpp:821 (24)
//         00430a71     MOV        this,dword ptr [ESP + 0x8]
//         00430a75     POP        EDI
//         00430a76     MOV        EAX,0x1
//         00430a7b     MOV        dword ptr FS:[0x0],this
//         00430a82     POP        ESI
//         00430a83     ADD        ESP,0xc
//         00430a86     RET        0x8
//         00430a89     ??         90h
//         00430a8a     NOP
//         00430a8b     NOP
//         00430a8c     NOP
//         00430a8d     NOP
//         00430a8e     NOP
//         00430a8f     NOP
    return 0;
}

int RGE_Combat_Object::attack(float param_1, float param_2, float param_3, int param_4) {
    /* TODO: Stub */
//                              int __thiscall attack(RGE_Combat_Object * this, float param_1, float
//              int               EAX:4          <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1                   XREF[1]:     00430ada(R)
//              float             Stack[0x8]:4   param_2                   XREF[1]:     00430af7(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     00430b14(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     00430a9e(R)
//                               ?attack@RGE_Combat_Object@@UAEHMMMH@Z                        XREF[4]:     0056f3a4(*), 0057083c(*),
//                               RGE_Combat_Object::attack                                                 005748c4(*), 00574b6c(*)
//                              com_obj.cpp:827 (14)
//         00430a90     MOV        EAX,FS:[0x0]
//         00430a96     PUSH       -0x1
//         00430a98     PUSH       FUN_0055cddb
//         00430a9d     PUSH       EAX
//                              com_obj.cpp:842 (179)
//         00430a9e     MOV        EAX,dword ptr [ESP + param_4]
//         00430aa2     MOV        dword ptr FS:[0x0],ESP
//         00430aa9     PUSH       ESI
//         00430aaa     PUSH       EDI
//         00430aab     TEST       EAX,EAX
//         00430aad     MOV        ESI,this
//         00430aaf     JNZ        LAB_00430b57
//         00430ab5     MOV        this,dword ptr [ESI + 0x184]
//         00430abb     CALL       RGE_Action_List::have_action                     uchar have_action(RGE_Action_List * this)
//         00430ac0     CMP        AL,0x1
//         00430ac2     JNZ        LAB_00430b57
//         00430ac8     MOV        this,dword ptr [ESI + 0x184]
//         00430ace     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         00430ad3     MOV        this,EAX
//         00430ad5     CALL       RGE_Action::targetX                              float targetX(RGE_Action * this)
//         00430ada     FCOMP      float ptr [ESP + param_1]
//         00430ade     FNSTSW     AX
//         00430ae0     TEST       AH,0x40
//         00430ae3     JZ         LAB_00430b57
//         00430ae5     MOV        this,dword ptr [ESI + 0x184]
//         00430aeb     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         00430af0     MOV        this,EAX
//         00430af2     CALL       RGE_Action::targetX                              float targetX(RGE_Action * this)
//         00430af7     FCOMP      float ptr [ESP + param_2]
//         00430afb     FNSTSW     AX
//         00430afd     TEST       AH,0x40
//         00430b00     JZ         LAB_00430b57
//         00430b02     MOV        this,dword ptr [ESI + 0x184]
//         00430b08     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         00430b0d     MOV        this,EAX
//         00430b0f     CALL       RGE_Action::targetX                              float targetX(RGE_Action * this)
//         00430b14     FCOMP      float ptr [ESP + param_3]
//         00430b18     FNSTSW     AX
//         00430b1a     TEST       AH,0x40
//         00430b1d     JZ         LAB_00430b57
//         00430b1f     MOV        this,dword ptr [ESI + 0x184]
//         00430b25     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         00430b2a     MOV        EDX,dword ptr [EAX]
//         00430b2c     MOV        this,EAX
//         00430b2e     CALL       dword ptr [EDX + 0x18]
//         00430b31     CMP        AX,0x9
//         00430b35     JZ         LAB_00430bec
//         00430b3b     MOV        this,dword ptr [ESI + 0x184]
//         00430b41     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         00430b46     MOV        EDX,dword ptr [EAX]
//         00430b48     MOV        this,EAX
//         00430b4a     CALL       dword ptr [EDX + 0x18]
//         00430b4d     CMP        AX,0x7
//                              com_obj.cpp:847 (6)
//         00430b51     JZ         LAB_00430bec
//                               LAB_00430b57                                                 XREF[5]:     00430aaf(j), 00430ac2(j),
//                                                                                                         00430ae3(j), 00430b00(j),
//                                                                                                         00430b1d(j)
//                              com_obj.cpp:854 (94)
//         00430b57     PUSH       0x5c
//         00430b59     CALL       operator_new                                     void * operator_new(uint param_1)
//         00430b5e     ADD        ESP,0x4
//         00430b61     MOV        dword ptr [ESP + 0x24],EAX
//         00430b65     TEST       EAX,EAX
//         00430b67     MOV        dword ptr [ESP + 0x10],0x0
//         00430b6f     JZ         LAB_00430bb3
//         00430b71     MOV        EDX,dword ptr [ESI + 0x8]
//         00430b74     MOV        this,word ptr [EDX + 0x12a]
//         00430b7b     PUSH       this
//         00430b7c     MOV        this,word ptr [EDX + 0x124]
//         00430b83     PUSH       this=>DAT_fffffff8
//         00430b84     MOV        this,dword ptr [EDX + 0x138]
//         00430b8a     MOV        EDX,dword ptr [EDX + 0x114]
//         00430b90     PUSH       this=>DAT_fffffff4
//         00430b91     MOV        this,dword ptr [ESP + 0x2c]
//         00430b95     PUSH       EDX=>DAT_fffffff0
//         00430b96     MOV        EDX,dword ptr [ESP + 0x2c]
//         00430b9a     PUSH       0x0
//         00430b9c     PUSH       0x0
//         00430b9e     PUSH       0x0
//         00430ba0     PUSH       this
//         00430ba1     MOV        this,dword ptr [ESP + 0x38]
//         00430ba5     PUSH       EDX
//         00430ba6     PUSH       this
//         00430ba7     PUSH       ESI
//         00430ba8     MOV        this,EAX
//         00430baa     CALL       RGE_Action_Attack::RGE_Action_Attack             undefined RGE_Action_Attack(RGE_Action_Attack
//         00430baf     MOV        EDI,EAX
//         00430bb1     JMP        LAB_00430bb5
//                               LAB_00430bb3                                                 XREF[1]:     00430b6f(j)
//         00430bb3     XOR        EDI,EDI
//                               LAB_00430bb5                                                 XREF[1]:     00430bb1(j)
//                              com_obj.cpp:855 (12)
//         00430bb5     TEST       EDI,EDI
//         00430bb7     MOV        dword ptr [ESP + 0x10],0xffffffff
//         00430bbf     JNZ        LAB_00430bd6
//                              com_obj.cpp:859 (2)
//         00430bc1     XOR        EAX,EAX
//                              com_obj.cpp:869 (19)
//         00430bc3     MOV        this,dword ptr [ESP + 0x8]
//         00430bc7     MOV        dword ptr FS:[0x0],this
//         00430bce     POP        EDI
//         00430bcf     POP        ESI
//         00430bd0     ADD        ESP,0xc
//         00430bd3     RET        0x10
//                               LAB_00430bd6                                                 XREF[1]:     00430bbf(j)
//                              com_obj.cpp:861 (11)
//         00430bd6     MOV        this,dword ptr [ESI + 0x184]
//         00430bdc     CALL       RGE_Action_List::delete_list                     void delete_list(RGE_Action_List * this)
//                              com_obj.cpp:862 (11)
//         00430be1     MOV        EDX,dword ptr [ESI]
//         00430be3     PUSH       EDI
//         00430be4     MOV        this,ESI
//         00430be6     CALL       dword ptr [EDX + 0x208]
//                               LAB_00430bec                                                 XREF[2]:     00430b35(j), 00430b51(j)
//                              com_obj.cpp:869 (24)
//         00430bec     MOV        this,dword ptr [ESP + 0x8]
//         00430bf0     POP        EDI
//         00430bf1     MOV        EAX,0x1
//         00430bf6     MOV        dword ptr FS:[0x0],this
//         00430bfd     POP        ESI
//         00430bfe     ADD        ESP,0xc
//         00430c01     RET        0x10
//         00430c04     ??         90h
//         00430c05     NOP
//         00430c06     NOP
//         00430c07     NOP
//         00430c08     NOP
//         00430c09     NOP
//         00430c0a     NOP
//         00430c0b     NOP
//         00430c0c     NOP
//         00430c0d     NOP
//         00430c0e     NOP
//         00430c0f     NOP
    return 0;
}

int RGE_Combat_Object::moveTo(int param_1, int param_2) {
    /* TODO: Stub */
//                              int __thiscall moveTo(RGE_Combat_Object * this, int param_1, int par
//              int               EAX:4          <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00430c17(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     00430c10(R)
//                               ?moveTo@RGE_Combat_Object@@UAEHHH@Z                          XREF[4]:     0056f3b4(*), 0057084c(*),
//                               RGE_Combat_Object::moveTo                                                 005748d4(*), 00574b7c(*)
//                              com_obj.cpp:875 (23)
//         00430c10     MOV        EDX,dword ptr [ESP + param_2]
//         00430c14     MOV        EAX,dword ptr [this->_padding_]
//         00430c16     PUSH       EDX
//         00430c17     MOV        EDX,dword ptr [ESP + param_1]
//         00430c1b     PUSH       0x3f800000
//         00430c20     PUSH       EDX
//         00430c21     CALL       dword ptr [EAX + 0x158]
//                              com_obj.cpp:877 (3)
//         00430c27     RET        0x8
//         00430c2a     ??         90h
//         00430c2b     NOP
//         00430c2c     NOP
//         00430c2d     NOP
//         00430c2e     NOP
//         00430c2f     NOP
    return 0;
}

int RGE_Combat_Object::moveTo(int param_1, float param_2, int param_3) {
    /* TODO: Stub */
//                              int __thiscall moveTo(RGE_Combat_Object * this, int param_1, float p
//              int               EAX:4          <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00430c3e(R)
//              float             Stack[0x8]:4   param_2
//              int               Stack[0xc]:4   param_3                   XREF[1]:     00430c74(R)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00430c60(R)
//                               ?moveTo@RGE_Combat_Object@@UAEHHMH@Z                         XREF[4]:     0056f3b0(*), 00570848(*),
//                               RGE_Combat_Object::moveTo                                                 005748d0(*), 00574b78(*)
//                              com_obj.cpp:884 (14)
//         00430c30     MOV        EAX,FS:[0x0]
//         00430c36     PUSH       -0x1
//         00430c38     PUSH       FUN_0055cdfb
//         00430c3d     PUSH       EAX
//                              com_obj.cpp:885 (30)
//         00430c3e     MOV        EAX,dword ptr [ESP + param_1]
//         00430c42     MOV        dword ptr FS:[0x0],ESP
//         00430c49     PUSH       EBX
//         00430c4a     PUSH       ESI
//         00430c4b     MOV        ESI,this
//         00430c4d     PUSH       EDI
//         00430c4e     PUSH       EAX
//         00430c4f     MOV        this,dword ptr [ESI + 0xc]
//         00430c52     MOV        this,dword ptr [ECX + this->_padding_]
//         00430c55     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
//         00430c5a     MOV        EBX,EAX
//                              com_obj.cpp:886 (4)
//         00430c5c     TEST       EBX,EBX
//         00430c5e     JNZ        LAB_00430c74
//                              com_obj.cpp:923 (20)
//         00430c60     MOV        this,dword ptr [ESP + local_c]
//         00430c64     MOV        dword ptr FS:[0x0],this
//         00430c6b     POP        EDI
//         00430c6c     POP        ESI
//         00430c6d     POP        EBX
//         00430c6e     ADD        ESP,0xc
//         00430c71     RET        0xc
//                               LAB_00430c74                                                 XREF[1]:     00430c5e(j)
//                              com_obj.cpp:898 (67)
//         00430c74     MOV        EAX,dword ptr [ESP + param_3]
//         00430c78     TEST       EAX,EAX
//         00430c7a     JNZ        LAB_00430cb9
//         00430c7c     MOV        this,dword ptr [ESI + 0x184]
//         00430c82     CALL       RGE_Action_List::have_action                     uchar have_action(RGE_Action_List * this)
//         00430c87     CMP        AL,0x1
//         00430c89     JNZ        LAB_00430cb9
//         00430c8b     MOV        this,dword ptr [ESI + 0x184]
//         00430c91     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         00430c96     MOV        EDX,dword ptr [EAX]
//         00430c98     MOV        this,EAX
//         00430c9a     CALL       dword ptr [EDX + 0x4c]
//         00430c9d     CMP        EAX,EBX
//         00430c9f     JNZ        LAB_00430cb9
//         00430ca1     MOV        this,dword ptr [ESI + 0x184]
//         00430ca7     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         00430cac     MOV        EDX,dword ptr [EAX]
//         00430cae     MOV        this,EAX
//         00430cb0     CALL       dword ptr [EDX + 0x18]
//         00430cb3     CMP        AX,0x1
//                              com_obj.cpp:903 (2)
//         00430cb7     JZ         LAB_00430d35
//                               LAB_00430cb9                                                 XREF[3]:     00430c7a(j), 00430c89(j),
//                                                                                                         00430c9f(j)
//                              com_obj.cpp:907 (11)
//         00430cb9     MOV        EAX,dword ptr [ESI + 0x8]
//         00430cbc     MOV        this,dword ptr [EAX + 0xc0]
//         00430cc2     TEST       this,this
//                              com_obj.cpp:908 (4)
//         00430cc4     MOV        EDI,this
//         00430cc6     JNZ        LAB_00430cce
//                              com_obj.cpp:910 (6)
//         00430cc8     MOV        EDI,dword ptr [EAX + 0xbc]
//                               LAB_00430cce                                                 XREF[1]:     00430cc6(j)
//                              com_obj.cpp:913 (47)
//         00430cce     PUSH       0x44
//         00430cd0     CALL       operator_new                                     void * operator_new(uint param_1)
//         00430cd5     ADD        ESP,0x4
//         00430cd8     MOV        dword ptr [ESP + 0x1c],EAX
//         00430cdc     TEST       EAX,EAX
//         00430cde     MOV        dword ptr [ESP + 0x14],0x0
//         00430ce6     JZ         LAB_00430cfb
//         00430ce8     MOV        this,dword ptr [ESP + 0x20]
//         00430cec     PUSH       EDI
//         00430ced     PUSH       this=>DAT_fffffff8
//         00430cee     PUSH       EBX=>DAT_fffffff4
//         00430cef     PUSH       ESI=>DAT_fffffff0
//         00430cf0     MOV        this,EAX
//         00430cf2     CALL       RGE_Action_Move_To::RGE_Action_Move_To           undefined RGE_Action_Move_To(RGE_Action_Move_
//         00430cf7     MOV        EDI,EAX
//         00430cf9     JMP        LAB_00430cfd
//                               LAB_00430cfb                                                 XREF[1]:     00430ce6(j)
//         00430cfb     XOR        EDI,EDI
//                               LAB_00430cfd                                                 XREF[1]:     00430cf9(j)
//                              com_obj.cpp:914 (12)
//         00430cfd     TEST       EDI,EDI
//         00430cff     MOV        dword ptr [ESP + 0x14],0xffffffff
//         00430d07     JNZ        LAB_00430d1f
//                              com_obj.cpp:918 (2)
//         00430d09     XOR        EAX,EAX
//                              com_obj.cpp:923 (20)
//         00430d0b     MOV        this,dword ptr [ESP + 0xc]
//         00430d0f     MOV        dword ptr FS:[0x0],this
//         00430d16     POP        EDI
//         00430d17     POP        ESI
//         00430d18     POP        EBX
//         00430d19     ADD        ESP,0xc
//         00430d1c     RET        0xc
//                               LAB_00430d1f                                                 XREF[1]:     00430d07(j)
//                              com_obj.cpp:920 (11)
//         00430d1f     MOV        this,dword ptr [ESI + 0x184]
//         00430d25     CALL       RGE_Action_List::delete_list                     void delete_list(RGE_Action_List * this)
//                              com_obj.cpp:921 (11)
//         00430d2a     MOV        EDX,dword ptr [ESI]
//         00430d2c     PUSH       EDI
//         00430d2d     MOV        this,ESI
//         00430d2f     CALL       dword ptr [EDX + 0x208]
//                               LAB_00430d35                                                 XREF[1]:     00430cb7(j)
//                              com_obj.cpp:923 (25)
//         00430d35     MOV        this,dword ptr [ESP + 0xc]
//         00430d39     POP        EDI
//         00430d3a     POP        ESI
//         00430d3b     MOV        EAX,0x1
//         00430d40     MOV        dword ptr FS:[0x0],this
//         00430d47     POP        EBX
//         00430d48     ADD        ESP,0xc
//         00430d4b     RET        0xc
//         00430d4e     ??         90h
//         00430d4f     NOP
    return 0;
}

int RGE_Combat_Object::moveTo(float param_1, float param_2, float param_3, float param_4, int param_5) {
    /* TODO: Stub */
//                              int __thiscall moveTo(RGE_Combat_Object * this, float param_1, float
//              int               EAX:4          <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1                   XREF[1]:     00430d98(R)
//              float             Stack[0x8]:4   param_2                   XREF[1]:     00430db5(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     00430dd2(R)
//              float             Stack[0x10]:4  param_4
//              int               Stack[0x14]:4  param_5                   XREF[1]:     00430d5e(R)
//                               ?moveTo@RGE_Combat_Object@@UAEHMMMMH@Z                       XREF[4]:     0056f3ac(*), 00570844(*),
//                               RGE_Combat_Object::moveTo                                                 005748cc(*), 00574b74(*)
//                              com_obj.cpp:930 (14)
//         00430d50     MOV        EAX,FS:[0x0]
//         00430d56     PUSH       -0x1
//         00430d58     PUSH       FUN_0055ce1b
//         00430d5d     PUSH       EAX
//                              com_obj.cpp:938 (149)
//         00430d5e     MOV        EAX,dword ptr [ESP + param_5]
//         00430d62     MOV        dword ptr FS:[0x0],ESP
//         00430d69     PUSH       EBX
//         00430d6a     PUSH       EBP
//         00430d6b     PUSH       ESI
//         00430d6c     PUSH       EDI
//         00430d6d     TEST       EAX,EAX
//         00430d6f     MOV        ESI,this
//         00430d71     JNZ        LAB_00430df9
//         00430d77     MOV        this,dword ptr [ESI + 0x184]
//         00430d7d     CALL       RGE_Action_List::have_action                     uchar have_action(RGE_Action_List * this)
//         00430d82     CMP        AL,0x1
//         00430d84     JNZ        LAB_00430df9
//         00430d86     MOV        this,dword ptr [ESI + 0x184]
//         00430d8c     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         00430d91     MOV        this,EAX
//         00430d93     CALL       RGE_Action::targetX                              float targetX(RGE_Action * this)
//         00430d98     FCOMP      float ptr [ESP + param_1]
//         00430d9c     FNSTSW     AX
//         00430d9e     TEST       AH,0x40
//         00430da1     JZ         LAB_00430df9
//         00430da3     MOV        this,dword ptr [ESI + 0x184]
//         00430da9     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         00430dae     MOV        this,EAX
//         00430db0     CALL       RGE_Action::targetY                              float targetY(RGE_Action * this)
//         00430db5     FCOMP      float ptr [ESP + param_2]
//         00430db9     FNSTSW     AX
//         00430dbb     TEST       AH,0x40
//         00430dbe     JZ         LAB_00430df9
//         00430dc0     MOV        this,dword ptr [ESI + 0x184]
//         00430dc6     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         00430dcb     MOV        this,EAX
//         00430dcd     CALL       RGE_Action::targetZ                              float targetZ(RGE_Action * this)
//         00430dd2     FCOMP      float ptr [ESP + param_3]
//         00430dd6     FNSTSW     AX
//         00430dd8     TEST       AH,0x40
//         00430ddb     JZ         LAB_00430df9
//         00430ddd     MOV        this,dword ptr [ESI + 0x184]
//         00430de3     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         00430de8     MOV        EDX,dword ptr [EAX]
//         00430dea     MOV        this,EAX
//         00430dec     CALL       dword ptr [EDX + 0x18]
//         00430def     CMP        AX,0x1
//                              com_obj.cpp:944 (6)
//         00430df3     JZ         LAB_00430e9d
//                               LAB_00430df9                                                 XREF[5]:     00430d71(j), 00430d84(j),
//                                                                                                         00430da1(j), 00430dbe(j),
//                                                                                                         00430ddb(j)
//                              com_obj.cpp:949 (52)
//         00430df9     MOV        this,dword ptr [ESI + 0x184]
//         00430dff     CALL       RGE_Action_List::have_action                     uchar have_action(RGE_Action_List * this)
//         00430e04     MOV        EBX,dword ptr [ESP + 0x28]
//         00430e08     MOV        EBP,dword ptr [ESP + 0x24]
//         00430e0c     CMP        AL,0x1
//         00430e0e     JNZ        LAB_00430e2f
//         00430e10     MOV        this,dword ptr [ESI + 0x184]
//         00430e16     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         00430e1b     MOV        this,dword ptr [ESP + 0x20]
//         00430e1f     MOV        EDX,dword ptr [EAX]
//         00430e21     PUSH       EBX
//         00430e22     PUSH       EBP=>DAT_fffffff8
//         00430e23     PUSH       this=>DAT_fffffff4
//         00430e24     PUSH       ESI=>DAT_fffffff0
//         00430e25     MOV        this,EAX
//         00430e27     CALL       dword ptr [EDX + 0x30]
//         00430e2a     CMP        EAX,0x1
//                              com_obj.cpp:954 (2)
//         00430e2d     JZ         LAB_00430e9d
//                               LAB_00430e2f                                                 XREF[1]:     00430e0e(j)
//                              com_obj.cpp:958 (11)
//         00430e2f     MOV        EAX,dword ptr [ESI + 0x8]
//         00430e32     MOV        EDI,dword ptr [EAX + 0xc0]
//         00430e38     TEST       EDI,EDI
//                              com_obj.cpp:960 (2)
//         00430e3a     JNZ        LAB_00430e42
//                              com_obj.cpp:961 (6)
//         00430e3c     MOV        EDI,dword ptr [EAX + 0xbc]
//                               LAB_00430e42                                                 XREF[1]:     00430e3a(j)
//                              com_obj.cpp:964 (53)
//         00430e42     PUSH       0x44
//         00430e44     CALL       operator_new                                     void * operator_new(uint param_1)
//         00430e49     ADD        ESP,0x4
//         00430e4c     MOV        dword ptr [ESP + 0x28],EAX
//         00430e50     TEST       EAX,EAX
//         00430e52     MOV        dword ptr [ESP + 0x18],0x0
//         00430e5a     JZ         LAB_00430e75
//         00430e5c     MOV        EDX,dword ptr [ESP + 0x2c]
//         00430e60     MOV        this,dword ptr [ESP + 0x20]
//         00430e64     PUSH       EDI
//         00430e65     PUSH       EDX=>DAT_fffffff8
//         00430e66     PUSH       EBX=>DAT_fffffff4
//         00430e67     PUSH       EBP=>DAT_fffffff0
//         00430e68     PUSH       this
//         00430e69     PUSH       ESI
//         00430e6a     MOV        this,EAX
//         00430e6c     CALL       RGE_Action_Move_To::RGE_Action_Move_To           undefined RGE_Action_Move_To(RGE_Action_Move_
//         00430e71     MOV        EDI,EAX
//         00430e73     JMP        LAB_00430e77
//                               LAB_00430e75                                                 XREF[1]:     00430e5a(j)
//         00430e75     XOR        EDI,EDI
//                               LAB_00430e77                                                 XREF[1]:     00430e73(j)
//                              com_obj.cpp:965 (12)
//         00430e77     TEST       EDI,EDI
//         00430e79     MOV        dword ptr [ESP + 0x18],0xffffffff
//         00430e81     JNZ        LAB_00430e87
//                              com_obj.cpp:969 (4)
//         00430e83     XOR        EAX,EAX
//         00430e85     JMP        LAB_00430ea2
//                               LAB_00430e87                                                 XREF[1]:     00430e81(j)
//                              com_obj.cpp:971 (11)
//         00430e87     MOV        this,dword ptr [ESI + 0x184]
//         00430e8d     CALL       RGE_Action_List::delete_list                     void delete_list(RGE_Action_List * this)
//                              com_obj.cpp:972 (11)
//         00430e92     MOV        EDX,dword ptr [ESI]
//         00430e94     PUSH       EDI
//         00430e95     MOV        this,ESI
//         00430e97     CALL       dword ptr [EDX + 0x208]
//                               LAB_00430e9d                                                 XREF[2]:     00430df3(j), 00430e2d(j)
//                              com_obj.cpp:973 (5)
//         00430e9d     MOV        EAX,0x1
//                               LAB_00430ea2                                                 XREF[1]:     00430e85(j)
//                              com_obj.cpp:974 (21)
//         00430ea2     MOV        this,dword ptr [ESP + 0x10]
//         00430ea6     POP        EDI
//         00430ea7     POP        ESI
//         00430ea8     POP        EBP
//         00430ea9     MOV        dword ptr FS:[0x0],this
//         00430eb0     POP        EBX
//         00430eb1     ADD        ESP,0xc
//         00430eb4     RET        0x14
//         00430eb7     ??         90h
//         00430eb8     NOP
//         00430eb9     NOP
//         00430eba     NOP
//         00430ebb     NOP
//         00430ebc     NOP
//         00430ebd     NOP
//         00430ebe     NOP
//         00430ebf     NOP
    return 0;
}

int RGE_Combat_Object::moveAwayFrom(int param_1, int param_2) {
    /* TODO: Stub */
//                              int __thiscall moveAwayFrom(RGE_Combat_Object * this, int param_1, i
//              int               EAX:4          <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//              int               Stack[0x8]:4   param_2
//                               ?moveAwayFrom@RGE_Combat_Object@@UAEHHH@Z                    XREF[4]:     0056f3b8(*), 00570850(*),
//                               RGE_Combat_Object::moveAwayFrom                                           005748d8(*), 00574b80(*)
//                              com_obj.cpp:980 (2)
//         00430ec0     XOR        EAX,EAX
//                              com_obj.cpp:982 (3)
//         00430ec2     RET        0x8
//         00430ec5     ??         90h
//         00430ec6     NOP
//         00430ec7     NOP
//         00430ec8     NOP
//         00430ec9     NOP
//         00430eca     NOP
//         00430ecb     NOP
//         00430ecc     NOP
//         00430ecd     NOP
//         00430ece     NOP
//         00430ecf     NOP
    return 0;
}

int RGE_Combat_Object::gather(int param_1, int param_2) {
    /* TODO: Stub */
//                              int __thiscall gather(RGE_Combat_Object * this, int param_1, int par
//              int               EAX:4          <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00430ee6(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     00430f05(R)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00431006(R)
//                               ?gather@RGE_Combat_Object@@UAEHHH@Z                          XREF[4]:     0056f3c0(*), 00570858(*),
//                               RGE_Combat_Object::gather                                                 005748e0(*), 00574b88(*)
//                              com_obj.cpp:988 (22)
//         00430ed0     MOV        EAX,FS:[0x0]
//         00430ed6     PUSH       -0x1
//         00430ed8     PUSH       FUN_0055ce3b
//         00430edd     PUSH       EAX
//         00430ede     MOV        dword ptr FS:[0x0],ESP
//         00430ee5     PUSH       EBX
//                              com_obj.cpp:989 (23)
//         00430ee6     MOV        EAX,dword ptr [ESP + param_1]
//         00430eea     PUSH       EBP
//         00430eeb     PUSH       ESI
//         00430eec     PUSH       EDI
//         00430eed     MOV        EDI,this
//         00430eef     PUSH       EAX
//         00430ef0     MOV        this,dword ptr [EDI + 0xc]
//         00430ef3     MOV        this,dword ptr [ECX + this->_padding_]
//         00430ef6     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
//         00430efb     MOV        ESI,EAX
//                              com_obj.cpp:990 (8)
//         00430efd     TEST       ESI,ESI
//         00430eff     JZ         LAB_00431006
//                              com_obj.cpp:1002 (67)
//         00430f05     MOV        EAX,dword ptr [ESP + param_2]
//         00430f09     TEST       EAX,EAX
//         00430f0b     JNZ        LAB_00430f4e
//         00430f0d     MOV        this,dword ptr [EDI + 0x184]
//         00430f13     CALL       RGE_Action_List::have_action                     uchar have_action(RGE_Action_List * this)
//         00430f18     CMP        AL,0x1
//         00430f1a     JNZ        LAB_00430f4e
//         00430f1c     MOV        this,dword ptr [EDI + 0x184]
//         00430f22     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         00430f27     MOV        EDX,dword ptr [EAX]
//         00430f29     MOV        this,EAX
//         00430f2b     CALL       dword ptr [EDX + 0x4c]
//         00430f2e     CMP        EAX,ESI
//         00430f30     JNZ        LAB_00430f4e
//         00430f32     MOV        this,dword ptr [EDI + 0x184]
//         00430f38     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         00430f3d     MOV        EDX,dword ptr [EAX]
//         00430f3f     MOV        this,EAX
//         00430f41     CALL       dword ptr [EDX + 0x18]
//         00430f44     CMP        AX,0x5
//                              com_obj.cpp:1007 (6)
//         00430f48     JZ         LAB_00431001
//                               LAB_00430f4e                                                 XREF[3]:     00430f0b(j), 00430f1a(j),
//                                                                                                         00430f30(j)
//                              com_obj.cpp:1013 (39)
//         00430f4e     MOV        this,dword ptr [EDI + 0x184]
//         00430f54     CALL       RGE_Action_List::have_action                     uchar have_action(RGE_Action_List * this)
//         00430f59     CMP        AL,0x1
//         00430f5b     JNZ        LAB_00430f96
//         00430f5d     MOV        this,dword ptr [EDI + 0x184]
//         00430f63     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         00430f68     MOV        EDX,dword ptr [EAX]
//         00430f6a     MOV        this,EAX
//         00430f6c     CALL       dword ptr [EDX + 0x18]
//         00430f6f     CMP        AX,0x5
//         00430f73     JNZ        LAB_00430f96
//                              com_obj.cpp:1016 (31)
//         00430f75     MOV        this,dword ptr [EDI + 0x184]
//         00430f7b     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         00430f80     MOV        this,dword ptr [ESI + 0x40]
//         00430f83     MOV        EDX,dword ptr [EAX]
//         00430f85     PUSH       this
//         00430f86     MOV        this,dword ptr [ESI + 0x3c]
//         00430f89     PUSH       this=>DAT_fffffff8
//         00430f8a     MOV        this,dword ptr [ESI + 0x38]
//         00430f8d     PUSH       this=>DAT_fffffff4
//         00430f8e     PUSH       ESI=>DAT_fffffff0
//         00430f8f     MOV        this,EAX
//         00430f91     CALL       dword ptr [EDX + 0x34]
//                              com_obj.cpp:1017 (2)
//         00430f94     JMP        LAB_00431001
//                               LAB_00430f96                                                 XREF[2]:     00430f5b(j), 00430f73(j)
//                              com_obj.cpp:1022 (25)
//         00430f96     MOV        EDX,dword ptr [ESI + 0x40]
//         00430f99     MOV        EAX,dword ptr [ESI + 0x3c]
//         00430f9c     MOV        this,dword ptr [ESI + 0x38]
//         00430f9f     MOV        EBP,dword ptr [EDI]
//         00430fa1     PUSH       EDX
//         00430fa2     PUSH       EAX=>DAT_fffffff8
//         00430fa3     PUSH       this=>DAT_fffffff4
//         00430fa4     PUSH       ESI=>DAT_fffffff0
//         00430fa5     MOV        this,EDI
//         00430fa7     CALL       dword ptr [EBP + 0x210]
//         00430fad     MOV        EBX,EAX
//                              com_obj.cpp:1023 (4)
//         00430faf     TEST       EBX,EBX
//         00430fb1     JZ         LAB_00431006
//                              com_obj.cpp:1030 (42)
//         00430fb3     PUSH       0x44
//         00430fb5     CALL       operator_new                                     void * operator_new(uint param_1)
//         00430fba     ADD        ESP,0x4
//         00430fbd     MOV        dword ptr [ESP + 0x20],EAX
//         00430fc1     TEST       EAX,EAX
//         00430fc3     MOV        dword ptr [ESP + 0x18],0x0
//         00430fcb     JZ         LAB_00430fdb
//         00430fcd     PUSH       ESI
//         00430fce     PUSH       EBX=>DAT_fffffff8
//         00430fcf     PUSH       EDI=>DAT_fffffff4
//         00430fd0     MOV        this,EAX
//         00430fd2     CALL       RGE_Action_Gather::RGE_Action_Gather             undefined RGE_Action_Gather(RGE_Action_Gather
//         00430fd7     MOV        ESI,EAX
//         00430fd9     JMP        LAB_00430fdd
//                               LAB_00430fdb                                                 XREF[1]:     00430fcb(j)
//         00430fdb     XOR        ESI,ESI
//                               LAB_00430fdd                                                 XREF[1]:     00430fd9(j)
//                              com_obj.cpp:1031 (12)
//         00430fdd     TEST       ESI,ESI
//         00430fdf     MOV        dword ptr [ESP + 0x18],0xffffffff
//         00430fe7     JNZ        LAB_00430fed
//                              com_obj.cpp:1035 (4)
//         00430fe9     XOR        EAX,EAX
//         00430feb     JMP        LAB_00431006
//                               LAB_00430fed                                                 XREF[1]:     00430fe7(j)
//                              com_obj.cpp:1037 (11)
//         00430fed     MOV        this,dword ptr [EDI + 0x184]
//         00430ff3     CALL       RGE_Action_List::delete_list                     void delete_list(RGE_Action_List * this)
//                              com_obj.cpp:1038 (9)
//         00430ff8     PUSH       ESI
//         00430ff9     MOV        this,EDI
//         00430ffb     CALL       dword ptr [EBP + 0x208]
//                               LAB_00431001                                                 XREF[2]:     00430f48(j), 00430f94(j)
//                              com_obj.cpp:1039 (5)
//         00431001     MOV        EAX,0x1
//                               LAB_00431006                                                 XREF[3]:     00430eff(j), 00430fb1(j),
//                                                                                                         00430feb(j)
//                              com_obj.cpp:1040 (21)
//         00431006     MOV        this,dword ptr [ESP + local_c]
//         0043100a     POP        EDI
//         0043100b     POP        ESI
//         0043100c     POP        EBP
//         0043100d     MOV        dword ptr FS:[0x0],this
//         00431014     POP        EBX
//         00431015     ADD        ESP,0xc
//         00431018     RET        0x8
//         0043101b     ??         90h
//         0043101c     NOP
//         0043101d     NOP
//         0043101e     NOP
//         0043101f     NOP
    return 0;
}

int RGE_Combat_Object::explore(int param_1, int param_2, int param_3) {
    /* TODO: Stub */
//                              int __thiscall explore(RGE_Combat_Object * this, int param_1, int pa
//              int               EAX:4          <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//              int               Stack[0x8]:4   param_2
//              int               Stack[0xc]:4   param_3                   XREF[1]:     0043102e(R)
//                               ?explore@RGE_Combat_Object@@UAEHHHH@Z                        XREF[4]:     0056f3d4(*), 0057086c(*),
//                               RGE_Combat_Object::explore                                                005748f4(*), 00574b9c(*)
//                              com_obj.cpp:1046 (14)
//         00431020     MOV        EAX,FS:[0x0]
//         00431026     PUSH       -0x1
//         00431028     PUSH       FUN_0055ce5b
//         0043102d     PUSH       EAX
//                              com_obj.cpp:1055 (56)
//         0043102e     MOV        EAX,dword ptr [ESP + param_3]
//         00431032     MOV        dword ptr FS:[0x0],ESP
//         00431039     PUSH       ESI
//         0043103a     PUSH       EDI
//         0043103b     TEST       EAX,EAX
//         0043103d     MOV        ESI,this
//         0043103f     JNZ        LAB_0043106c
//         00431041     MOV        this,dword ptr [ESI + 0x184]
//         00431047     CALL       RGE_Action_List::have_action                     uchar have_action(RGE_Action_List * this)
//         0043104c     CMP        AL,0x1
//         0043104e     JNZ        LAB_0043106c
//         00431050     MOV        this,dword ptr [ESI + 0x184]
//         00431056     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         0043105b     MOV        EDX,dword ptr [EAX]
//         0043105d     MOV        this,EAX
//         0043105f     CALL       dword ptr [EDX + 0x18]
//         00431062     CMP        AX,0x4
//                              com_obj.cpp:1060 (6)
//         00431066     JZ         LAB_00431132
//                               LAB_0043106c                                                 XREF[2]:     0043103f(j), 0043104e(j)
//                              com_obj.cpp:1066 (39)
//         0043106c     MOV        this,dword ptr [ESI + 0x184]
//         00431072     CALL       RGE_Action_List::have_action                     uchar have_action(RGE_Action_List * this)
//         00431077     CMP        AL,0x1
//         00431079     JNZ        LAB_004310bd
//         0043107b     MOV        this,dword ptr [ESI + 0x184]
//         00431081     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         00431086     MOV        EDX,dword ptr [EAX]
//         00431088     MOV        this,EAX
//         0043108a     CALL       dword ptr [EDX + 0x18]
//         0043108d     CMP        AX,0x4
//         00431091     JNZ        LAB_004310bd
//                              com_obj.cpp:1068 (40)
//         00431093     MOV        this,dword ptr [ESI + 0x184]
//         00431099     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         0043109e     MOV        this,dword ptr [ESI + 0x40]
//         004310a1     MOV        EDX,dword ptr [EAX]
//         004310a3     FILD       dword ptr [ESP + 0x1c]
//         004310a7     PUSH       this
//         004310a8     PUSH       this=>DAT_fffffff8
//         004310a9     FSTP       float ptr [ESP]=>DAT_fffffff8
//         004310ac     FILD       dword ptr [ESP + 0x20]
//         004310b0     PUSH       this=>DAT_fffffff4
//         004310b1     MOV        this,EAX
//         004310b3     FSTP       float ptr [ESP]=>DAT_fffffff4
//         004310b6     PUSH       0x0=>DAT_fffffff0
//         004310b8     CALL       dword ptr [EDX + 0x34]
//                              com_obj.cpp:1069 (2)
//         004310bb     JMP        LAB_00431132
//                               LAB_004310bd                                                 XREF[2]:     00431079(j), 00431091(j)
//                              com_obj.cpp:1074 (62)
//         004310bd     PUSH       0x40
//         004310bf     CALL       operator_new                                     void * operator_new(uint param_1)
//         004310c4     ADD        ESP,0x4
//         004310c7     MOV        dword ptr [ESP + 0x20],EAX
//         004310cb     TEST       EAX,EAX
//         004310cd     MOV        dword ptr [ESP + 0x10],0x0
//         004310d5     JZ         LAB_004310f9
//         004310d7     MOV        EDX,dword ptr [ESI + 0x40]
//         004310da     FILD       dword ptr [ESP + 0x1c]
//         004310de     PUSH       EDX
//         004310df     PUSH       this=>DAT_fffffff8
//         004310e0     FSTP       float ptr [ESP]=>DAT_fffffff8
//         004310e3     FILD       dword ptr [ESP + 0x20]
//         004310e7     PUSH       this=>DAT_fffffff4
//         004310e8     MOV        this,EAX
//         004310ea     FSTP       float ptr [ESP]=>DAT_fffffff4
//         004310ed     PUSH       0x0=>DAT_fffffff0
//         004310ef     PUSH       ESI
//         004310f0     CALL       RGE_Action_Explore::RGE_Action_Explore           undefined RGE_Action_Explore(RGE_Action_Explo
//         004310f5     MOV        EDI,EAX
//         004310f7     JMP        LAB_004310fb
//                               LAB_004310f9                                                 XREF[1]:     004310d5(j)
//         004310f9     XOR        EDI,EDI
//                               LAB_004310fb                                                 XREF[1]:     004310f7(j)
//                              com_obj.cpp:1075 (12)
//         004310fb     TEST       EDI,EDI
//         004310fd     MOV        dword ptr [ESP + 0x10],0xffffffff
//         00431105     JNZ        LAB_0043111c
//                              com_obj.cpp:1079 (2)
//         00431107     XOR        EAX,EAX
//                              com_obj.cpp:1091 (19)
//         00431109     MOV        this,dword ptr [ESP + 0x8]
//         0043110d     MOV        dword ptr FS:[0x0],this
//         00431114     POP        EDI
//         00431115     POP        ESI
//         00431116     ADD        ESP,0xc
//         00431119     RET        0xc
//                               LAB_0043111c                                                 XREF[1]:     00431105(j)
//                              com_obj.cpp:1081 (11)
//         0043111c     MOV        this,dword ptr [ESI + 0x184]
//         00431122     CALL       RGE_Action_List::delete_list                     void delete_list(RGE_Action_List * this)
//                              com_obj.cpp:1082 (11)
//         00431127     MOV        EAX,dword ptr [ESI]
//         00431129     PUSH       EDI
//         0043112a     MOV        this,ESI
//         0043112c     CALL       dword ptr [EAX + 0x208]
//                               LAB_00431132                                                 XREF[2]:     00431066(j), 004310bb(j)
//                              com_obj.cpp:1091 (24)
//         00431132     MOV        this,dword ptr [ESP + 0x8]
//         00431136     POP        EDI
//         00431137     MOV        EAX,0x1
//         0043113c     MOV        dword ptr FS:[0x0],this
//         00431143     POP        ESI
//         00431144     ADD        ESP,0xc
//         00431147     RET        0xc
//         0043114a     ??         90h
//         0043114b     NOP
//         0043114c     NOP
//         0043114d     NOP
//         0043114e     NOP
//         0043114f     NOP
    return 0;
}

int RGE_Combat_Object::enter(int param_1, int param_2) {
    /* TODO: Stub */
//                              int __thiscall enter(RGE_Combat_Object * this, int param_1, int para
//              int               EAX:4          <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00431165(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     00431185(R)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0043123a(R)
//                               ?enter@RGE_Combat_Object@@UAEHHH@Z                           XREF[4]:     0056f3d8(*), 00570870(*),
//                               RGE_Combat_Object::enter                                                  005748f8(*), 00574ba0(*)
//                              com_obj.cpp:1097 (21)
//         00431150     MOV        EAX,FS:[0x0]
//         00431156     PUSH       -0x1
//         00431158     PUSH       FUN_0055ce7b
//         0043115d     PUSH       EAX
//         0043115e     MOV        dword ptr FS:[0x0],ESP
//                              com_obj.cpp:1098 (24)
//         00431165     MOV        EAX,dword ptr [ESP + param_1]
//         00431169     PUSH       EBX
//         0043116a     PUSH       EBP
//         0043116b     PUSH       ESI
//         0043116c     MOV        ESI,this
//         0043116e     PUSH       EDI
//         0043116f     PUSH       EAX
//         00431170     MOV        this,dword ptr [ESI + 0xc]
//         00431173     MOV        this,dword ptr [ECX + this->_padding_]
//         00431176     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
//         0043117b     MOV        EDI,EAX
//                              com_obj.cpp:1099 (8)
//         0043117d     TEST       EDI,EDI
//         0043117f     JZ         LAB_0043123a
//                              com_obj.cpp:1111 (67)
//         00431185     MOV        EAX,dword ptr [ESP + param_2]
//         00431189     TEST       EAX,EAX
//         0043118b     JNZ        LAB_004311ca
//         0043118d     MOV        this,dword ptr [ESI + 0x184]
//         00431193     CALL       RGE_Action_List::have_action                     uchar have_action(RGE_Action_List * this)
//         00431198     CMP        AL,0x1
//         0043119a     JNZ        LAB_004311ca
//         0043119c     MOV        this,dword ptr [ESI + 0x184]
//         004311a2     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         004311a7     MOV        EDX,dword ptr [EAX]
//         004311a9     MOV        this,EAX
//         004311ab     CALL       dword ptr [EDX + 0x4c]
//         004311ae     CMP        EAX,EDI
//         004311b0     JNZ        LAB_004311ca
//         004311b2     MOV        this,dword ptr [ESI + 0x184]
//         004311b8     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         004311bd     MOV        EDX,dword ptr [EAX]
//         004311bf     MOV        this,EAX
//         004311c1     CALL       dword ptr [EDX + 0x18]
//         004311c4     CMP        AX,0x3
//                              com_obj.cpp:1116 (2)
//         004311c8     JZ         LAB_00431235
//                               LAB_004311ca                                                 XREF[3]:     0043118b(j), 0043119a(j),
//                                                                                                         004311b0(j)
//                              com_obj.cpp:1121 (25)
//         004311ca     MOV        EAX,dword ptr [EDI + 0x40]
//         004311cd     MOV        this,dword ptr [EDI + 0x3c]
//         004311d0     MOV        EDX,dword ptr [EDI + 0x38]
//         004311d3     MOV        EBP,dword ptr [ESI]
//         004311d5     PUSH       EAX
//         004311d6     PUSH       this=>DAT_fffffff8
//         004311d7     PUSH       EDX=>DAT_fffffff4
//         004311d8     PUSH       EDI=>DAT_fffffff0
//         004311d9     MOV        this,ESI
//         004311db     CALL       dword ptr [EBP + 0x210]
//         004311e1     MOV        EBX,EAX
//                              com_obj.cpp:1122 (4)
//         004311e3     TEST       EBX,EBX
//         004311e5     JZ         LAB_0043123a
//                              com_obj.cpp:1129 (42)
//         004311e7     PUSH       0x40
//         004311e9     CALL       operator_new                                     void * operator_new(uint param_1)
//         004311ee     ADD        ESP,0x4
//         004311f1     MOV        dword ptr [ESP + 0x20],EAX
//         004311f5     TEST       EAX,EAX
//         004311f7     MOV        dword ptr [ESP + 0x18],0x0
//         004311ff     JZ         LAB_0043120f
//         00431201     PUSH       EDI
//         00431202     PUSH       EBX=>DAT_fffffff8
//         00431203     PUSH       ESI=>DAT_fffffff4
//         00431204     MOV        this,EAX
//         00431206     CALL       RGE_Action_Enter::RGE_Action_Enter               undefined RGE_Action_Enter(RGE_Action_Enter *
//         0043120b     MOV        EDI,EAX
//         0043120d     JMP        LAB_00431211
//                               LAB_0043120f                                                 XREF[1]:     004311ff(j)
//         0043120f     XOR        EDI,EDI
//                               LAB_00431211                                                 XREF[1]:     0043120d(j)
//                              com_obj.cpp:1130 (12)
//         00431211     TEST       EDI,EDI
//         00431213     MOV        dword ptr [ESP + 0x18],0xffffffff
//         0043121b     JNZ        LAB_00431221
//                              com_obj.cpp:1134 (4)
//         0043121d     XOR        EAX,EAX
//         0043121f     JMP        LAB_0043123a
//                               LAB_00431221                                                 XREF[1]:     0043121b(j)
//                              com_obj.cpp:1136 (11)
//         00431221     MOV        this,dword ptr [ESI + 0x184]
//         00431227     CALL       RGE_Action_List::delete_list                     void delete_list(RGE_Action_List * this)
//                              com_obj.cpp:1137 (9)
//         0043122c     PUSH       EDI
//         0043122d     MOV        this,ESI
//         0043122f     CALL       dword ptr [EBP + 0x208]
//                               LAB_00431235                                                 XREF[1]:     004311c8(j)
//                              com_obj.cpp:1138 (5)
//         00431235     MOV        EAX,0x1
//                               LAB_0043123a                                                 XREF[3]:     0043117f(j), 004311e5(j),
//                                                                                                         0043121f(j)
//                              com_obj.cpp:1139 (21)
//         0043123a     MOV        this,dword ptr [ESP + local_c]
//         0043123e     POP        EDI
//         0043123f     POP        ESI
//         00431240     POP        EBP
//         00431241     MOV        dword ptr FS:[0x0],this
//         00431248     POP        EBX
//         00431249     ADD        ESP,0xc
//         0043124c     RET        0x8
//         0043124f     ??         90h
    return 0;
}

int RGE_Combat_Object::transport(float param_1, float param_2, float param_3, int param_4) {
    /* TODO: Stub */
//                              int __thiscall transport(RGE_Combat_Object * this, float param_1, fl
//              int               EAX:4          <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1
//              float             Stack[0x8]:4   param_2
//              float             Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//                               ?transport@RGE_Combat_Object@@UAEHMMMH@Z                     XREF[4]:     0056f3e0(*), 00570878(*),
//                               RGE_Combat_Object::transport                                              00574900(*), 00574ba8(*)
//                              com_obj.cpp:1146 (28)
//         00431250     PUSH       -0x1
//         00431252     PUSH       FUN_0055ce9b
//         00431257     MOV        EAX,FS:[0x0]
//         0043125d     PUSH       EAX
//         0043125e     MOV        dword ptr FS:[0x0],ESP
//         00431265     PUSH       this
//         00431266     PUSH       EBX
//         00431267     PUSH       EBP
//         00431268     PUSH       ESI
//         00431269     MOV        ESI,this
//         0043126b     PUSH       EDI
//                              com_obj.cpp:1154 (39)
//         0043126c     MOV        this,dword ptr [ESI + 0x184]
//         00431272     CALL       RGE_Action_List::have_action                     uchar have_action(RGE_Action_List * this)
//         00431277     CMP        AL,0x1
//         00431279     JNZ        LAB_004312b5
//         0043127b     MOV        this,dword ptr [ESI + 0x184]
//         00431281     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         00431286     MOV        EDX,dword ptr [EAX]
//         00431288     MOV        this,EAX
//         0043128a     CALL       dword ptr [EDX + 0x18]
//         0043128d     CMP        AX,0xc
//         00431291     JNZ        LAB_004312b5
//                              com_obj.cpp:1156 (32)
//         00431293     MOV        this,dword ptr [ESI + 0x184]
//         00431299     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         0043129e     MOV        this,dword ptr [ESP + 0x2c]
//         004312a2     MOV        EDX,dword ptr [EAX]
//         004312a4     PUSH       this
//         004312a5     MOV        this,dword ptr [ESP + 0x2c]
//         004312a9     PUSH       this=>DAT_fffffff8
//         004312aa     MOV        this,dword ptr [ESP + 0x2c]
//         004312ae     PUSH       this=>DAT_fffffff4
//         004312af     PUSH       0x0=>DAT_fffffff0
//         004312b1     MOV        this,EAX
//                              com_obj.cpp:1157 (2)
//         004312b3     JMP        LAB_00431319
//                               LAB_004312b5                                                 XREF[2]:     00431279(j), 00431291(j)
//                              com_obj.cpp:1161 (50)
//         004312b5     PUSH       0x40
//         004312b7     CALL       operator_new                                     void * operator_new(uint param_1)
//         004312bc     ADD        ESP,0x4
//         004312bf     MOV        dword ptr [ESP + 0x10],EAX
//         004312c3     MOV        EBX,dword ptr [ESP + 0x2c]
//         004312c7     MOV        EBP,dword ptr [ESP + 0x28]
//         004312cb     XOR        EDI,EDI
//         004312cd     CMP        EAX,EDI
//         004312cf     MOV        dword ptr [ESP + 0x1c],EDI
//         004312d3     JZ         LAB_004312e7
//         004312d5     MOV        EDX,dword ptr [ESP + 0x24]
//         004312d9     PUSH       EBX
//         004312da     PUSH       EBP=>DAT_fffffff8
//         004312db     PUSH       EDX=>DAT_fffffff4
//         004312dc     PUSH       EDI=>DAT_fffffff0
//         004312dd     PUSH       ESI
//         004312de     MOV        this,EAX
//         004312e0     CALL       RGE_Action_Transport::RGE_Action_Transport       undefined RGE_Action_Transport(RGE_Action_Tra
//         004312e5     MOV        EDI,EAX
//                               LAB_004312e7                                                 XREF[1]:     004312d3(j)
//                              com_obj.cpp:1162 (12)
//         004312e7     TEST       EDI,EDI
//         004312e9     MOV        dword ptr [ESP + 0x1c],0xffffffff
//         004312f1     JNZ        LAB_004312f7
//                              com_obj.cpp:1166 (4)
//         004312f3     XOR        EAX,EAX
//         004312f5     JMP        LAB_00431321
//                               LAB_004312f7                                                 XREF[1]:     004312f1(j)
//                              com_obj.cpp:1168 (11)
//         004312f7     MOV        this,dword ptr [ESI + 0x184]
//         004312fd     CALL       RGE_Action_List::delete_list                     void delete_list(RGE_Action_List * this)
//                              com_obj.cpp:1169 (11)
//         00431302     MOV        EAX,dword ptr [ESI]
//         00431304     PUSH       EDI
//         00431305     MOV        this,ESI
//         00431307     CALL       dword ptr [EAX + 0x208]
//                              com_obj.cpp:1170 (15)
//         0043130d     MOV        EAX,dword ptr [ESP + 0x24]
//         00431311     MOV        EDX,dword ptr [EDI]
//         00431313     PUSH       EBX
//         00431314     PUSH       EBP=>DAT_fffffff8
//         00431315     PUSH       EAX=>DAT_fffffff4
//         00431316     PUSH       ESI=>DAT_fffffff0
//         00431317     MOV        this,EDI
//                               LAB_00431319                                                 XREF[1]:     004312b3(j)
//         00431319     CALL       dword ptr [EDX + 0x34]
//                              com_obj.cpp:1171 (5)
//         0043131c     MOV        EAX,0x1
//                               LAB_00431321                                                 XREF[1]:     004312f5(j)
//                              com_obj.cpp:1172 (21)
//         00431321     MOV        this,dword ptr [ESP + 0x14]
//         00431325     POP        EDI
//         00431326     POP        ESI
//         00431327     POP        EBP
//         00431328     MOV        dword ptr FS:[0x0],this
//         0043132f     POP        EBX
//         00431330     ADD        ESP,0x10
//         00431333     RET        0x10
//         00431336     ??         90h
//         00431337     NOP
//         00431338     NOP
//         00431339     NOP
//         0043133a     NOP
//         0043133b     NOP
//         0043133c     NOP
//         0043133d     NOP
//         0043133e     NOP
//         0043133f     NOP
    return 0;
}

int RGE_Combat_Object::unload(int param_1, float param_2, float param_3, float param_4) {
    /* TODO: Stub */
//                              int __thiscall unload(RGE_Combat_Object * this, int param_1, float p
//              int               EAX:4          <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//              float             Stack[0x8]:4   param_2
//              float             Stack[0xc]:4   param_3
//              float             Stack[0x10]:4  param_4
//                               ?unload@RGE_Combat_Object@@UAEHHMMM@Z                        XREF[4]:     0056f3dc(*), 00570874(*),
//                               RGE_Combat_Object::unload                                                 005748fc(*), 00574ba4(*)
//                              com_obj.cpp:1178 (26)
//         00431340     PUSH       -0x1
//         00431342     PUSH       FUN_0055cebb
//         00431347     MOV        EAX,FS:[0x0]
//         0043134d     PUSH       EAX
//         0043134e     MOV        dword ptr FS:[0x0],ESP
//         00431355     PUSH       this
//         00431356     PUSH       ESI
//         00431357     MOV        ESI,this
//         00431359     PUSH       EDI
//                              com_obj.cpp:1191 (39)
//         0043135a     MOV        this,dword ptr [ESI + 0x184]
//         00431360     CALL       RGE_Action_List::have_action                     uchar have_action(RGE_Action_List * this)
//         00431365     CMP        AL,0x1
//         00431367     JNZ        LAB_004313a2
//         00431369     MOV        this,dword ptr [ESI + 0x184]
//         0043136f     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         00431374     MOV        EDX,dword ptr [EAX]
//         00431376     MOV        this,EAX
//         00431378     CALL       dword ptr [EDX + 0x18]
//         0043137b     CMP        AX,0xc
//         0043137f     JNZ        LAB_004313a2
//                              com_obj.cpp:1196 (28)
//         00431381     MOV        this,dword ptr [ESI + 0x184]
//         00431387     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         0043138c     MOV        this,dword ptr [ESI + 0x40]
//         0043138f     MOV        EDX,dword ptr [EAX]
//         00431391     PUSH       this
//         00431392     MOV        this,dword ptr [ESI + 0x3c]
//         00431395     PUSH       this=>DAT_fffffff8
//         00431396     MOV        this,dword ptr [ESI + 0x38]
//         00431399     PUSH       this=>DAT_fffffff4
//         0043139a     PUSH       ESI=>DAT_fffffff0
//         0043139b     MOV        this,EAX
//                              com_obj.cpp:1197 (5)
//         0043139d     JMP        LAB_00431423
//                               LAB_004313a2                                                 XREF[2]:     00431367(j), 0043137f(j)
//                              com_obj.cpp:1201 (54)
//         004313a2     PUSH       0x40
//         004313a4     CALL       operator_new                                     void * operator_new(uint param_1)
//         004313a9     ADD        ESP,0x4
//         004313ac     MOV        dword ptr [ESP + 0x8],EAX
//         004313b0     TEST       EAX,EAX
//         004313b2     MOV        dword ptr [ESP + 0x14],0x0
//         004313ba     JZ         LAB_004313d6
//         004313bc     MOV        EDX,dword ptr [ESI + 0x40]
//         004313bf     MOV        this,dword ptr [ESI + 0x3c]
//         004313c2     PUSH       EDX
//         004313c3     MOV        EDX,dword ptr [ESI + 0x38]
//         004313c6     PUSH       this=>DAT_fffffff8
//         004313c7     PUSH       EDX=>DAT_fffffff4
//         004313c8     PUSH       0x0=>DAT_fffffff0
//         004313ca     PUSH       ESI
//         004313cb     MOV        this,EAX
//         004313cd     CALL       RGE_Action_Transport::RGE_Action_Transport       undefined RGE_Action_Transport(RGE_Action_Tra
//         004313d2     MOV        EDI,EAX
//         004313d4     JMP        LAB_004313d8
//                               LAB_004313d6                                                 XREF[1]:     004313ba(j)
//         004313d6     XOR        EDI,EDI
//                               LAB_004313d8                                                 XREF[1]:     004313d4(j)
//                              com_obj.cpp:1205 (12)
//         004313d8     TEST       EDI,EDI
//         004313da     MOV        dword ptr [ESP + 0x14],0xffffffff
//         004313e2     JNZ        LAB_004313f9
//                              com_obj.cpp:1209 (2)
//         004313e4     XOR        EAX,EAX
//                              com_obj.cpp:1215 (19)
//         004313e6     MOV        this,dword ptr [ESP + 0xc]
//         004313ea     MOV        dword ptr FS:[0x0],this
//         004313f1     POP        EDI
//         004313f2     POP        ESI
//         004313f3     ADD        ESP,0x10
//         004313f6     RET        0x10
//                               LAB_004313f9                                                 XREF[1]:     004313e2(j)
//                              com_obj.cpp:1211 (11)
//         004313f9     MOV        this,dword ptr [ESI + 0x184]
//         004313ff     CALL       RGE_Action_List::delete_list                     void delete_list(RGE_Action_List * this)
//                              com_obj.cpp:1212 (11)
//         00431404     MOV        EAX,dword ptr [ESI]
//         00431406     PUSH       EDI
//         00431407     MOV        this,ESI
//         00431409     CALL       dword ptr [EAX + 0x208]
//                              com_obj.cpp:1213 (23)
//         0043140f     MOV        EAX,dword ptr [ESP + 0x28]
//         00431413     MOV        this,dword ptr [ESP + 0x24]
//         00431417     MOV        EDX,dword ptr [EDI]
//         00431419     PUSH       EAX
//         0043141a     MOV        EAX,dword ptr [ESP + 0x24]
//         0043141e     PUSH       this=>DAT_fffffff8
//         0043141f     PUSH       EAX=>DAT_fffffff4
//         00431420     PUSH       ESI=>DAT_fffffff0
//         00431421     MOV        this,EDI
//                               LAB_00431423                                                 XREF[1]:     0043139d(j)
//         00431423     CALL       dword ptr [EDX + 0x34]
//                              com_obj.cpp:1215 (24)
//         00431426     MOV        this,dword ptr [ESP + 0xc]
//         0043142a     POP        EDI
//         0043142b     MOV        EAX,0x1
//         00431430     MOV        dword ptr FS:[0x0],this
//         00431437     POP        ESI
//         00431438     ADD        ESP,0x10
//         0043143b     RET        0x10
//         0043143e     ??         90h
//         0043143f     NOP
    return 0;
}

int RGE_Combat_Object::stopAction() {
    /* TODO: Stub */
//                              int __thiscall stopAction(RGE_Combat_Object * this)
//              int               EAX:4          <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//                               ?stopAction@RGE_Combat_Object@@UAEHXZ                        XREF[4]:     0056f3e4(*), 0057087c(*),
//                               RGE_Combat_Object::stopAction                                             00574904(*), 00574bac(*)
//                              com_obj.cpp:1221 (3)
//         00431440     PUSH       ESI
//         00431441     MOV        ESI,this
//                              com_obj.cpp:1226 (11)
//         00431443     MOV        this,dword ptr [ESI + 0x184]
//         00431449     CALL       RGE_Action_List::delete_list                     void delete_list(RGE_Action_List * this)
//                              com_obj.cpp:1227 (14)
//         0043144e     MOV        this,dword ptr [ESI + 0x8]
//         00431451     MOV        EAX,dword ptr [ESI]
//         00431453     MOV        EDX,dword ptr [ECX + this->_padding_]
//         00431456     MOV        this,ESI
//         00431458     PUSH       EDX
//         00431459     CALL       dword ptr [EAX + 0x38]
//                              com_obj.cpp:1232 (5)
//         0043145c     MOV        EAX,0x1
//                              com_obj.cpp:1233 (2)
//         00431461     POP        ESI
//         00431462     RET
//         00431463     ??         90h
//         00431464     NOP
//         00431465     NOP
//         00431466     NOP
//         00431467     NOP
//         00431468     NOP
//         00431469     NOP
//         0043146a     NOP
//         0043146b     NOP
//         0043146c     NOP
//         0043146d     NOP
//         0043146e     NOP
//         0043146f     NOP
    return 0;
}

int RGE_Combat_Object::pause() {
    /* TODO: Stub */
//                              int __thiscall pause(RGE_Combat_Object * this)
//              int               EAX:4          <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//                               ?pause@RGE_Combat_Object@@UAEHXZ                             XREF[4]:     0056f3e8(*), 00570880(*),
//                               RGE_Combat_Object::pause                                                  00574908(*), 00574bb0(*)
//                              com_obj.cpp:1239 (12)
//         00431470     MOV        EDX,dword ptr [ECX + this->_padding_]
//         00431473     MOV        EAX,dword ptr [this->_padding_]
//         00431475     MOV        EDX,dword ptr [EDX + 0x18]
//         00431478     PUSH       EDX
//         00431479     CALL       dword ptr [EAX + 0x38]
//                              com_obj.cpp:1245 (5)
//         0043147c     MOV        EAX,0x1
//                              com_obj.cpp:1246 (1)
//         00431481     RET
//         00431482     ??         90h
//         00431483     NOP
//         00431484     NOP
//         00431485     NOP
//         00431486     NOP
//         00431487     NOP
//         00431488     NOP
//         00431489     NOP
//         0043148a     NOP
//         0043148b     NOP
//         0043148c     NOP
//         0043148d     NOP
//         0043148e     NOP
//         0043148f     NOP
    return 0;
}

float RGE_Combat_Object::rateOfFire() {
    /* TODO: Stub */
//                              float __thiscall rateOfFire(RGE_Combat_Object * this)
//              float             ST0:10         <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//                               ?rateOfFire@RGE_Combat_Object@@UAEMXZ                        XREF[4]:     0056f358(*), 005707f0(*),
//                               RGE_Combat_Object::rateOfFire                                             00574878(*), 00574b20(*)
//                              com_obj.cpp:1252 (9)
//         00431490     MOV        EAX,dword ptr [ECX + this->_padding_]
//         00431493     FLD        float ptr [EAX + 0x120]
//                              com_obj.cpp:1254 (1)
//         00431499     RET
//         0043149a     ??         90h
//         0043149b     NOP
//         0043149c     NOP
//         0043149d     NOP
//         0043149e     NOP
//         0043149f     NOP
    return 0;
}

float RGE_Combat_Object::damageCapability() {
    /* TODO: Stub */
//                              float __thiscall damageCapability(RGE_Combat_Object * this)
//              float             ST0:10         <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004314c1(*), 004314c5(*)
//                               ?damageCapability@RGE_Combat_Object@@UAEMXZ                  XREF[4]:     0056f360(*), 005707f8(*),
//                               RGE_Combat_Object::damageCapability                                       00574880(*), 00574b28(*)
//                              com_obj.cpp:1260 (1)
//         004314a0     PUSH       this
//                              com_obj.cpp:1264 (29)
//         004314a1     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004314a4     FLD        float ptr [DAT_0056f4a8]
//         004314aa     MOVSX      EDX,word ptr [EAX + 0x108]
//         004314b1     TEST       EDX,EDX
//         004314b3     JLE        LAB_004314e4
//         004314b5     MOV        this,dword ptr [EAX + 0x10c]
//         004314bb     ADD        this,0x2
//                               LAB_004314be                                                 XREF[1]:     004314e2(j)
//                              com_obj.cpp:1265 (24)
//         004314be     MOVSX      EAX,word ptr [this->_padding_]
//         004314c1     MOV        dword ptr [ESP]=>local_4,EAX
//         004314c5     FILD       dword ptr [ESP]=>local_4
//         004314c9     FCOM       float ptr [DAT_0056f4a8]
//         004314cf     FNSTSW     AX
//         004314d1     TEST       AH,0x41
//         004314d4     JNZ        LAB_004314dc
//                              com_obj.cpp:1266 (14)
//         004314d6     FXCH
//         004314d8     FADD       ST0,ST1
//         004314da     FXCH
//                               LAB_004314dc                                                 XREF[1]:     004314d4(j)
//         004314dc     ADD        this,0x4
//         004314df     DEC        EDX
//         004314e0     FSTP       ST0
//         004314e2     JNZ        LAB_004314be
//                               LAB_004314e4                                                 XREF[1]:     004314b3(j)
//                              com_obj.cpp:1268 (2)
//         004314e4     POP        this
//         004314e5     RET
//         004314e6     ??         90h
//         004314e7     NOP
//         004314e8     NOP
//         004314e9     NOP
//         004314ea     NOP
//         004314eb     NOP
//         004314ec     NOP
//         004314ed     NOP
//         004314ee     NOP
//         004314ef     NOP
    return 0;
}

float RGE_Combat_Object::damageCapability(RGE_Static_Object* param_1) {
    /* TODO: Stub */
//                              float __thiscall damageCapability(RGE_Combat_Object * this, RGE_Stat
//              float             ST0:10         <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004314f1(R)
//                               ?damageCapability@RGE_Combat_Object@@UAEMPAVRGE_Static_Obje  XREF[4]:     0056f35c(*), 005707f4(*),
//                               RGE_Combat_Object::damageCapability                                       0057487c(*), 00574b24(*)
//                              com_obj.cpp:1273 (1)
//         004314f0     PUSH       ESI
//                              com_obj.cpp:1275 (18)
//         004314f1     MOV        ESI,dword ptr [ESP + param_1]
//         004314f5     PUSH       EDI
//         004314f6     MOV        EDI,this
//         004314f8     MOV        EAX,dword ptr [ESI]
//         004314fa     PUSH       EDI
//         004314fb     MOV        this,ESI
//         004314fd     CALL       dword ptr [EAX + 0xf0]
//                              com_obj.cpp:1280 (39)
//         00431503     MOV        this,dword ptr [ESI + 0xc]
//         00431506     MOV        EAX,dword ptr [ESI + 0x8]
//         00431509     FSTP       float ptr [ESP + 0xc]
//         0043150d     PUSH       ESI
//         0043150e     MOV        EDX,dword ptr [EDI]
//         00431510     PUSH       this=>DAT_fffffff8
//         00431511     MOV        this,dword ptr [ESP + 0x14]
//         00431515     PUSH       this=>DAT_fffffff4
//         00431516     MOV        this,dword ptr [EAX + 0x10c]
//         0043151c     MOVSX      EAX,word ptr [EAX + 0x108]
//         00431523     PUSH       this=>DAT_fffffff0
//         00431524     PUSH       EAX
//         00431525     MOV        this,EDI
//         00431527     CALL       dword ptr [EDX + 0x74]
//                              com_obj.cpp:1282 (5)
//         0043152a     POP        EDI
//         0043152b     POP        ESI
//         0043152c     RET        0x4
//         0043152f     ??         90h
    return 0;
}

int RGE_Combat_Object::inAttackRange(RGE_Static_Object* param_1) {
    /* TODO: Stub */
//                              int __thiscall inAttackRange(RGE_Combat_Object * this, RGE_Static_Ob
//              int               EAX:4          <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1
//              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     0043153f(W), 00431545(R), 0043154d(R), 00431559(W)
//              float             Stack[-0x8]:4  radiusDistance
//                               ?inAttackRange@RGE_Combat_Object@@UAEHPAVRGE_Static_Object@  XREF[4]:     0056f33c(*), 005707d4(*),
//                               RGE_Combat_Object::inAttackRange                                          0057485c(*), 00574b04(*)
//                              com_obj.cpp:1287 (4)
//         00431530     PUSH       this
//         00431531     PUSH       ESI
//         00431532     MOV        ESI,this
//                              com_obj.cpp:1289 (3)
//         00431534     MOV        EAX,dword ptr [ESI + 0x8]
//                              com_obj.cpp:1290 (50)
//         00431537     MOV        EDX,dword ptr [ESI]
//         00431539     MOV        this,dword ptr [EAX + 0x30]
//         0043153c     FLD        float ptr [EAX + 0x34]
//         0043153f     MOV        dword ptr [ESP + local_4],this
//         00431543     MOV        this,ESI
//         00431545     FLD        float ptr [ESP + local_4]
//         00431549     FLD        ST1
//         0043154b     FXCH
//         0043154d     FMUL       float ptr [ESP + local_4]
//         00431551     FXCH
//         00431553     FMUL       ST2
//         00431555     FADDP
//         00431557     FSQRT
//         00431559     FSTP       float ptr [ESP + local_4]
//         0043155d     FSTP       ST0
//         0043155f     CALL       dword ptr [EDX + 0x10c]
//         00431565     FADD       float ptr [ESP + 0x4]
//                              com_obj.cpp:1291 (22)
//         00431569     MOV        EDX,dword ptr [ESP + 0xc]
//         0043156d     MOV        this,ESI
//         0043156f     PUSH       EDX
//         00431570     FSUB       float ptr [DAT_0056f4b8]                         = 9Ah
//         00431576     FSTP       float ptr [ESP + 0x10]
//         0043157a     CALL       RGE_Static_Object::distance_to_object            float distance_to_object(RGE_Static_Object *
//                              com_obj.cpp:1292 (11)
//         0043157f     FCOMP      float ptr [ESP + 0xc]
//         00431583     FNSTSW     AX
//         00431585     TEST       AH,0x41
//         00431588     JZ         LAB_00431594
//                              com_obj.cpp:1293 (5)
//         0043158a     MOV        EAX,0x1
//                              com_obj.cpp:1295 (5)
//         0043158f     POP        ESI
//         00431590     POP        this
//         00431591     RET        0x4
//                               LAB_00431594                                                 XREF[1]:     00431588(j)
//                              com_obj.cpp:1294 (2)
//         00431594     XOR        EAX,EAX
//                              com_obj.cpp:1295 (5)
//         00431596     POP        ESI
//         00431597     POP        this
//         00431598     RET        0x4
//         0043159b     ??         90h
//         0043159c     NOP
//         0043159d     NOP
//         0043159e     NOP
//         0043159f     NOP
    return 0;
}

float RGE_Combat_Object::weaponRange() {
    /* TODO: Stub */
//                              float __thiscall weaponRange(RGE_Combat_Object * this)
//              float             ST0:10         <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//                               ?weaponRange@RGE_Combat_Object@@UAEMXZ                       XREF[4]:     0056f364(*), 005707fc(*),
//                               RGE_Combat_Object::weaponRange                                            00574884(*), 00574b2c(*)
//                              com_obj.cpp:1301 (9)
//         004315a0     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004315a3     FLD        float ptr [EAX + 0x114]
//                              com_obj.cpp:1303 (1)
//         004315a9     RET
//         004315aa     ??         90h
//         004315ab     NOP
//         004315ac     NOP
//         004315ad     NOP
//         004315ae     NOP
//         004315af     NOP
    return 0;
}

float RGE_Combat_Object::minimumWeaponRange() {
    /* TODO: Stub */
//                              float __thiscall minimumWeaponRange(RGE_Combat_Object * this)
//              float             ST0:10         <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//                               ?minimumWeaponRange@RGE_Combat_Object@@UAEMXZ                XREF[4]:     0056f368(*), 00570800(*),
//                               RGE_Combat_Object::minimumWeaponRange                                     00574888(*), 00574b30(*)
//                              com_obj.cpp:1309 (9)
//         004315b0     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004315b3     FLD        float ptr [EAX + 0x138]
//                              com_obj.cpp:1311 (1)
//         004315b9     RET
//         004315ba     ??         90h
//         004315bb     NOP
//         004315bc     NOP
//         004315bd     NOP
//         004315be     NOP
//         004315bf     NOP
    return 0;
}

int RGE_Combat_Object::currentTargetID() {
    /* TODO: Stub */
//                              int __thiscall currentTargetID(RGE_Combat_Object * this)
//              int               EAX:4          <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//                               ?currentTargetID@RGE_Combat_Object@@UBEHXZ                   XREF[4]:     0056f374(*), 0057080c(*),
//                               RGE_Combat_Object::currentTargetID                                        00574894(*), 00574b3c(*)
//                              com_obj.cpp:1316 (3)
//         004315c0     PUSH       ESI
//         004315c1     MOV        ESI,this
//                              com_obj.cpp:1318 (37)
//         004315c3     MOV        this,dword ptr [ESI + 0x184]
//         004315c9     CALL       RGE_Action_List::have_action                     uchar have_action(RGE_Action_List * this)
//         004315ce     CMP        AL,0x1
//         004315d0     JNZ        LAB_004315ff
//         004315d2     MOV        this,dword ptr [ESI + 0x184]
//         004315d8     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         004315dd     MOV        EDX,dword ptr [EAX]
//         004315df     MOV        this,EAX
//         004315e1     CALL       dword ptr [EDX + 0x4c]
//         004315e4     TEST       EAX,EAX
//         004315e6     JZ         LAB_004315ff
//                              com_obj.cpp:1319 (21)
//         004315e8     MOV        this,dword ptr [ESI + 0x184]
//         004315ee     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         004315f3     MOV        EDX,dword ptr [EAX]
//         004315f5     MOV        this,EAX
//         004315f7     CALL       dword ptr [EDX + 0x4c]
//         004315fa     MOV        EAX,dword ptr [EAX + 0x4]
//                              com_obj.cpp:1321 (2)
//         004315fd     POP        ESI
//         004315fe     RET
//                               LAB_004315ff                                                 XREF[2]:     004315d0(j), 004315e6(j)
//                              com_obj.cpp:1320 (3)
//         004315ff     OR         EAX,0xffffffff
//                              com_obj.cpp:1321 (2)
//         00431602     POP        ESI
//         00431603     RET
//         00431604     ??         90h
//         00431605     NOP
//         00431606     NOP
//         00431607     NOP
//         00431608     NOP
//         00431609     NOP
//         0043160a     NOP
//         0043160b     NOP
//         0043160c     NOP
//         0043160d     NOP
//         0043160e     NOP
//         0043160f     NOP
    return 0;
}

float RGE_Combat_Object::currentTargetX() {
    /* TODO: Stub */
//                              float __thiscall currentTargetX(RGE_Combat_Object * this)
//              float             ST0:10         <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//                               ?currentTargetX@RGE_Combat_Object@@UBEMXZ                    XREF[4]:     0056f378(*), 00570810(*),
//                               RGE_Combat_Object::currentTargetX                                         00574898(*), 00574b40(*)
//                              com_obj.cpp:1326 (3)
//         00431610     PUSH       ESI
//         00431611     MOV        ESI,this
//                              com_obj.cpp:1327 (15)
//         00431613     MOV        this,dword ptr [ESI + 0x184]
//         00431619     CALL       RGE_Action_List::have_action                     uchar have_action(RGE_Action_List * this)
//         0043161e     CMP        AL,0x1
//         00431620     JNZ        LAB_00431636
//                              com_obj.cpp:1328 (18)
//         00431622     MOV        this,dword ptr [ESI + 0x184]
//         00431628     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         0043162d     MOV        this,EAX
//         0043162f     CALL       RGE_Action::targetX                              float targetX(RGE_Action * this)
//                              com_obj.cpp:1330 (2)
//         00431634     POP        ESI
//         00431635     RET
//                               LAB_00431636                                                 XREF[1]:     00431620(j)
//                              com_obj.cpp:1329 (6)
//         00431636     FLD        float ptr [DAT_0056f4bc]
//                              com_obj.cpp:1330 (2)
//         0043163c     POP        ESI
//         0043163d     RET
//         0043163e     ??         90h
//         0043163f     NOP
    return 0;
}

float RGE_Combat_Object::currentTargetY() {
    /* TODO: Stub */
//                              float __thiscall currentTargetY(RGE_Combat_Object * this)
//              float             ST0:10         <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//                               ?currentTargetY@RGE_Combat_Object@@UBEMXZ                    XREF[4]:     0056f37c(*), 00570814(*),
//                               RGE_Combat_Object::currentTargetY                                         0057489c(*), 00574b44(*)
//                              com_obj.cpp:1335 (3)
//         00431640     PUSH       ESI
//         00431641     MOV        ESI,this
//                              com_obj.cpp:1336 (15)
//         00431643     MOV        this,dword ptr [ESI + 0x184]
//         00431649     CALL       RGE_Action_List::have_action                     uchar have_action(RGE_Action_List * this)
//         0043164e     CMP        AL,0x1
//         00431650     JNZ        LAB_00431666
//                              com_obj.cpp:1337 (18)
//         00431652     MOV        this,dword ptr [ESI + 0x184]
//         00431658     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         0043165d     MOV        this,EAX
//         0043165f     CALL       RGE_Action::targetY                              float targetY(RGE_Action * this)
//                              com_obj.cpp:1339 (2)
//         00431664     POP        ESI
//         00431665     RET
//                               LAB_00431666                                                 XREF[1]:     00431650(j)
//                              com_obj.cpp:1338 (6)
//         00431666     FLD        float ptr [DAT_0056f4bc]
//                              com_obj.cpp:1339 (2)
//         0043166c     POP        ESI
//         0043166d     RET
//         0043166e     ??         90h
//         0043166f     NOP
    return 0;
}

float RGE_Combat_Object::currentTargetZ() {
    /* TODO: Stub */
//                              float __thiscall currentTargetZ(RGE_Combat_Object * this)
//              float             ST0:10         <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//                               ?currentTargetZ@RGE_Combat_Object@@UBEMXZ                    XREF[4]:     0056f380(*), 00570818(*),
//                               RGE_Combat_Object::currentTargetZ                                         005748a0(*), 00574b48(*)
//                              com_obj.cpp:1344 (3)
//         00431670     PUSH       ESI
//         00431671     MOV        ESI,this
//                              com_obj.cpp:1345 (15)
//         00431673     MOV        this,dword ptr [ESI + 0x184]
//         00431679     CALL       RGE_Action_List::have_action                     uchar have_action(RGE_Action_List * this)
//         0043167e     CMP        AL,0x1
//         00431680     JNZ        LAB_00431696
//                              com_obj.cpp:1346 (18)
//         00431682     MOV        this,dword ptr [ESI + 0x184]
//         00431688     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         0043168d     MOV        this,EAX
//         0043168f     CALL       RGE_Action::targetZ                              float targetZ(RGE_Action * this)
//                              com_obj.cpp:1348 (2)
//         00431694     POP        ESI
//         00431695     RET
//                               LAB_00431696                                                 XREF[1]:     00431680(j)
//                              com_obj.cpp:1347 (6)
//         00431696     FLD        float ptr [DAT_0056f4bc]
//                              com_obj.cpp:1348 (2)
//         0043169c     POP        ESI
//         0043169d     RET
//         0043169e     ??         90h
//         0043169f     NOP
    return 0;
}

float RGE_Combat_Object::teleport(float param_1, float param_2, float param_3) {
    /* TODO: Stub */
//                              float __thiscall teleport(RGE_Combat_Object * this, float param_1, f
//              float             ST0:10         <RETURN>
//              RGE_Combat_Obj    ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1                   XREF[1]:     004316bc(R)
//              float             Stack[0x8]:4   param_2                   XREF[1]:     004316b8(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     004316c2(R)
//                               ?teleport@RGE_Combat_Object@@UAEMMMM@Z                       XREF[4]:     0056f28c(*), 00570724(*),
//                               RGE_Combat_Object::teleport                                               005747ac(*), 00574a54(*)
//                              com_obj.cpp:1356 (6)
//         004316a0     PUSH       EBX
//         004316a1     PUSH       EBP
//         004316a2     PUSH       ESI
//         004316a3     MOV        ESI,this
//         004316a5     PUSH       EDI
//                              com_obj.cpp:1361 (8)
//         004316a6     FLD        float ptr [ESI + 0x38]
//         004316a9     CALL       __ftol                                           undefined __ftol()
//                              com_obj.cpp:1362 (10)
//         004316ae     FLD        float ptr [ESI + 0x3c]
//         004316b1     MOV        EDI,EAX
//         004316b3     CALL       __ftol                                           undefined __ftol()
//                              com_obj.cpp:1364 (24)
//         004316b8     MOV        this,dword ptr [ESP + param_2]
//         004316bc     MOV        EDX,dword ptr [ESP + param_1]
//         004316c0     MOV        EBP,EAX
//         004316c2     MOV        EAX,dword ptr [ESP + param_3]
//         004316c6     PUSH       EAX
//         004316c7     PUSH       this
//         004316c8     PUSH       EDX
//         004316c9     MOV        this,ESI
//         004316cb     CALL       RGE_Moving_Object::teleport                      float teleport(RGE_Moving_Object * this, floa
//                              com_obj.cpp:1366 (7)
//         004316d0     MOV        EAX,dword ptr [ESI + 0x4]
//         004316d3     TEST       EAX,EAX
//         004316d5     JL         LAB_0043170e
//                              com_obj.cpp:1368 (8)
//         004316d7     FLD        float ptr [ESI + 0x38]
//         004316da     CALL       __ftol                                           undefined __ftol()
//                              com_obj.cpp:1369 (10)
//         004316df     FLD        float ptr [ESI + 0x3c]
//         004316e2     MOV        EBX,EAX
//         004316e4     CALL       __ftol                                           undefined __ftol()
//                              com_obj.cpp:1371 (8)
//         004316e9     CMP        EBX,EDI
//         004316eb     JNZ        LAB_004316f1
//         004316ed     CMP        EAX,EBP
//         004316ef     JZ         LAB_0043170e
//                               LAB_004316f1                                                 XREF[1]:     004316eb(j)
//                              com_obj.cpp:1377 (11)
//         004316f1     LEA        EDX,[ESI + 0x194]
//         004316f7     MOV        ESI,0x9
//                               LAB_004316fc                                                 XREF[1]:     0043170c(j)
//                              com_obj.cpp:1379 (2)
//         004316fc     MOV        this,dword ptr [EDX]
//                              com_obj.cpp:1380 (4)
//         004316fe     TEST       this,this
//         00431700     JZ         LAB_00431708
//                              com_obj.cpp:1382 (3)
//         00431702     MOV        byte ptr [ECX + this+0x6],BL
//                              com_obj.cpp:1383 (9)
//         00431705     MOV        byte ptr [ECX + this+0x7],AL
//                               LAB_00431708                                                 XREF[1]:     00431700(j)
//         00431708     ADD        EDX,0x4
//         0043170b     DEC        ESI
//         0043170c     JNZ        LAB_004316fc
//                               LAB_0043170e                                                 XREF[2]:     004316d5(j), 004316ef(j)
//                              com_obj.cpp:1391 (7)
//         0043170e     POP        EDI
//         0043170f     POP        ESI
//         00431710     POP        EBP
//         00431711     POP        EBX
//         00431712     RET        0xc
//         00431715     ??         90h
//         00431716     NOP
//         00431717     NOP
//         00431718     NOP
//         00431719     NOP
//         0043171a     NOP
//         0043171b     NOP
//         0043171c     NOP
//         0043171d     NOP
//         0043171e     NOP
//         0043171f     NOP
    return 0;
}

