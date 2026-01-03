#include "../common.h"
#include "move_obj.h"

RGE_Moving_Object::RGE_Moving_Object(RGE_Master_Moving_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Moving_Object(RGE_Moving_Object * this, RGE
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//              RGE_Master_Mov    Stack[0x4]:4   param_1                   XREF[2]:     0045c46b(R), 0045c576(R)
//              RGE_Player *      Stack[0x8]:4   param_2                   XREF[2]:     0045c47e(R), 0045c572(R)
//              float             Stack[0xc]:4   param_3                   XREF[2]:     0045c466(R), 0045c56e(R)
//              float             Stack[0x10]:4  param_4                   XREF[1]:     0045c470(R)
//              float             Stack[0x14]:4  param_5                   XREF[1]:     0045c476(R)
//              int               Stack[0x18]:4  param_6                   XREF[1]:     0045c534(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0045c49b(W), 0045c4ac(W), 0045c4bc(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0045c586(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0045c48a(W)
//                               ??0RGE_Moving_Object@@QAE@PAVRGE_Master_Moving_Object@@PAVR  XREF[2]:     RGE_Action_Object:00405c9d(c),
//                               RGE_Moving_Object::RGE_Moving_Object                                      make_new_obj:00451e8a(c)
//                              move_obj.cpp:96 (107)
//         0045c450     PUSH       -0x1
//         0045c452     PUSH       FUN_0055dc84
//         0045c457     MOV        EAX,FS:[0x0]
//         0045c45d     PUSH       EAX
//         0045c45e     MOV        dword ptr FS:[0x0],ESP
//         0045c465     PUSH       this
//         0045c466     MOV        EAX,dword ptr [ESP + param_3]
//         0045c46a     PUSH       EBX
//         0045c46b     MOV        EDX,dword ptr [ESP + param_1]
//         0045c46f     PUSH       EBP
//         0045c470     MOV        EBP,dword ptr [ESP + param_4]
//         0045c474     PUSH       ESI
//         0045c475     PUSH       EDI
//         0045c476     MOV        EDI,dword ptr [ESP + param_5]
//         0045c47a     XOR        EBX,EBX
//         0045c47c     MOV        ESI,this
//         0045c47e     MOV        this,dword ptr [ESP + param_2]
//         0045c482     PUSH       EBX
//         0045c483     PUSH       EDI
//         0045c484     PUSH       EBP
//         0045c485     PUSH       EAX
//         0045c486     PUSH       this
//         0045c487     PUSH       EDX
//         0045c488     MOV        this,ESI
//         0045c48a     MOV        dword ptr [ESP + local_10],ESI
//         0045c48e     CALL       RGE_Animated_Object::RGE_Animated_Object         undefined RGE_Animated_Object(RGE_Animated_Ob
//         0045c493     PUSH       0xa
//         0045c495     LEA        this,[ESI + 0xa4]
//         0045c49b     MOV        dword ptr [ESP + local_4],EBX
//         0045c49f     CALL       Path::Path                                       undefined Path(Path * this, int param_1)
//         0045c4a4     PUSH       0xa
//         0045c4a6     LEA        this,[ESI + 0xd8]
//         0045c4ac     MOV        byte ptr [ESP + local_4],0x1
//         0045c4b1     CALL       Path::Path                                       undefined Path(Path * this, int param_1)
//         0045c4b6     MOV        EAX,0x2
//                              move_obj.cpp:99 (101)
//         0045c4bb     PUSH       EBX
//         0045c4bc     MOV        byte ptr [ESP + local_4],AL
//         0045c4c0     MOV        dword ptr [ESI + 0x148],EAX
//         0045c4c6     OR         EAX,0xffffffff
//         0045c4c9     PUSH       EBX
//         0045c4ca     PUSH       EBX
//         0045c4cb     MOV        this,ESI
//         0045c4cd     MOV        dword ptr [ESI + 0x14c],EAX
//         0045c4d3     MOV        dword ptr [ESI + 0x150],EAX
//         0045c4d9     MOV        byte ptr [ESI + 0x154],BL
//         0045c4df     MOV        byte ptr [ESI + 0x155],BL
//         0045c4e5     MOV        byte ptr [ESI + 0x156],BL
//         0045c4eb     MOV        dword ptr [ESI + 0x168],EBX
//         0045c4f1     MOV        dword ptr [ESI + 0x16c],EBX
//         0045c4f7     MOV        dword ptr [ESI + 0x170],EBX
//         0045c4fd     MOV        byte ptr [ESI + 0x174],BL
//         0045c503     MOV        dword ptr [ESI],RGE_Moving_Object::`vftable'     = 0045c5a0
//         0045c509     MOV        dword ptr [ESI + 0x10c],EBX
//         0045c50f     MOV        dword ptr [ESI + 0x110],EBX
//         0045c515     MOV        dword ptr [ESI + 0x114],EBX
//         0045c51b     CALL       RGE_Moving_Object::setGoal                       void setGoal(RGE_Moving_Object * this, float
//                              move_obj.cpp:108 (14)
//         0045c520     MOV        AL,0xff
//         0045c522     MOV        dword ptr [ESI + 0x12c],EBX
//         0045c528     MOV        byte ptr [ESI + 0x17c],AL
//                              move_obj.cpp:109 (6)
//         0045c52e     MOV        byte ptr [ESI + 0x17d],AL
//                              move_obj.cpp:110 (58)
//         0045c534     MOV        EAX,dword ptr [ESP + param_6]
//         0045c538     MOV        dword ptr [ESI + 0x130],EBX
//         0045c53e     CMP        EAX,EBX
//         0045c540     MOV        dword ptr [ESI + 0x134],EBX
//         0045c546     MOV        dword ptr [ESI + 0x138],0xffffffff
//         0045c550     MOV        dword ptr [ESI + 0x13c],EBX
//         0045c556     MOV        dword ptr [ESI + 0x140],EBX
//         0045c55c     MOV        dword ptr [ESI + 0x144],EBX
//         0045c562     MOV        dword ptr [ESI + 0x178],0x47c35000
//         0045c56c     JZ         LAB_0045c586
//                              move_obj.cpp:111 (24)
//         0045c56e     MOV        EAX,dword ptr [ESP + param_3]
//         0045c572     MOV        this,dword ptr [ESP + param_2]
//         0045c576     MOV        EDX,dword ptr [ESP + param_1]
//         0045c57a     PUSH       EDI
//         0045c57b     PUSH       EBP
//         0045c57c     PUSH       EAX
//         0045c57d     PUSH       this
//         0045c57e     PUSH       EDX
//         0045c57f     MOV        this,ESI
//         0045c581     CALL       RGE_Moving_Object::setup                         int setup(RGE_Moving_Object * this, RGE_Maste
//                               LAB_0045c586                                                 XREF[1]:     0045c56c(j)
//                              move_obj.cpp:112 (23)
//         0045c586     MOV        this,dword ptr [ESP + local_c]
//         0045c58a     MOV        EAX,ESI
//         0045c58c     POP        EDI
//         0045c58d     POP        ESI
//         0045c58e     POP        EBP
//         0045c58f     MOV        dword ptr FS:[0x0],this
//         0045c596     POP        EBX
//         0045c597     ADD        ESP,0x10
//         0045c59a     RET        0x18
//         0045c59d     ??         90h
//         0045c59e     NOP
//         0045c59f     NOP
}

RGE_Moving_Object::RGE_Moving_Object(int param_1, RGE_Game_World* param_2, int param_3) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Moving_Object(RGE_Moving_Object * this, int
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[2]:     0045c5d6(R), 0045c6d1(R)
//              RGE_Game_World    Stack[0x8]:4   param_2                   XREF[1]:     0045c5dc(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     0045c697(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0045c5f9(W), 0045c60a(W), 0045c61e(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0045c6de(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0045c5e8(W)
//                               ??0RGE_Moving_Object@@QAE@HPAVRGE_Game_World@@H@Z            XREF[2]:     RGE_Action_Object:00405fbb(c),
//                               RGE_Moving_Object::RGE_Moving_Object                                      load:00463a67(c)
//                              move_obj.cpp:130 (84)
//         0045c5c0     PUSH       -0x1
//         0045c5c2     PUSH       FUN_0055dcb4
//         0045c5c7     MOV        EAX,FS:[0x0]
//         0045c5cd     PUSH       EAX
//         0045c5ce     MOV        dword ptr FS:[0x0],ESP
//         0045c5d5     PUSH       this
//         0045c5d6     MOV        EAX,dword ptr [ESP + param_1]
//         0045c5da     PUSH       EBX
//         0045c5db     PUSH       EBP
//         0045c5dc     MOV        EBP,dword ptr [ESP + param_2]
//         0045c5e0     XOR        EBX,EBX
//         0045c5e2     PUSH       ESI
//         0045c5e3     PUSH       EBX
//         0045c5e4     MOV        ESI,this
//         0045c5e6     PUSH       EBP
//         0045c5e7     PUSH       EAX
//         0045c5e8     MOV        dword ptr [ESP + local_10],ESI
//         0045c5ec     CALL       RGE_Animated_Object::RGE_Animated_Object         undefined RGE_Animated_Object(RGE_Animated_Ob
//         0045c5f1     PUSH       0xa
//         0045c5f3     LEA        this,[ESI + 0xa4]
//         0045c5f9     MOV        dword ptr [ESP + local_4],EBX
//         0045c5fd     CALL       Path::Path                                       undefined Path(Path * this, int param_1)
//         0045c602     PUSH       0xa
//         0045c604     LEA        this,[ESI + 0xd8]
//         0045c60a     MOV        byte ptr [ESP + local_4],0x1
//         0045c60f     CALL       Path::Path                                       undefined Path(Path * this, int param_1)
//                              move_obj.cpp:133 (111)
//         0045c614     PUSH       EBX
//         0045c615     MOV        EAX,0x2
//         0045c61a     PUSH       EBX
//         0045c61b     PUSH       EBX
//         0045c61c     MOV        this,ESI
//         0045c61e     MOV        byte ptr [ESP + local_4],AL
//         0045c622     MOV        dword ptr [ESI + 0x148],EAX
//         0045c628     MOV        dword ptr [ESI + 0x14c],0xffffffff
//         0045c632     MOV        dword ptr [ESI + 0x150],0xffffffff
//         0045c63c     MOV        byte ptr [ESI + 0x154],BL
//         0045c642     MOV        byte ptr [ESI + 0x155],BL
//         0045c648     MOV        byte ptr [ESI + 0x156],BL
//         0045c64e     MOV        dword ptr [ESI + 0x168],EBX
//         0045c654     MOV        dword ptr [ESI + 0x16c],EBX
//         0045c65a     MOV        dword ptr [ESI + 0x170],EBX
//         0045c660     MOV        byte ptr [ESI + 0x174],BL
//         0045c666     MOV        dword ptr [ESI],RGE_Moving_Object::`vftable'     = 0045c5a0
//         0045c66c     MOV        dword ptr [ESI + 0x10c],EBX
//         0045c672     MOV        dword ptr [ESI + 0x110],EBX
//         0045c678     MOV        dword ptr [ESI + 0x114],EBX
//         0045c67e     CALL       RGE_Moving_Object::setGoal                       void setGoal(RGE_Moving_Object * this, float
//                              move_obj.cpp:142 (14)
//         0045c683     MOV        AL,0xff
//         0045c685     MOV        dword ptr [ESI + 0x12c],EBX
//         0045c68b     MOV        byte ptr [ESI + 0x17c],AL
//                              move_obj.cpp:143 (6)
//         0045c691     MOV        byte ptr [ESI + 0x17d],AL
//                              move_obj.cpp:144 (58)
//         0045c697     MOV        EAX,dword ptr [ESP + param_3]
//         0045c69b     MOV        dword ptr [ESI + 0x130],EBX
//         0045c6a1     CMP        EAX,EBX
//         0045c6a3     MOV        dword ptr [ESI + 0x134],EBX
//         0045c6a9     MOV        dword ptr [ESI + 0x138],0xffffffff
//         0045c6b3     MOV        dword ptr [ESI + 0x13c],EBX
//         0045c6b9     MOV        dword ptr [ESI + 0x140],EBX
//         0045c6bf     MOV        dword ptr [ESI + 0x144],EBX
//         0045c6c5     MOV        dword ptr [ESI + 0x178],0x47c35000
//         0045c6cf     JZ         LAB_0045c6de
//                              move_obj.cpp:145 (13)
//         0045c6d1     MOV        this,dword ptr [ESP + param_1]
//         0045c6d5     PUSH       EBP
//         0045c6d6     PUSH       this
//         0045c6d7     MOV        this,ESI
//         0045c6d9     CALL       RGE_Moving_Object::setup                         int setup(RGE_Moving_Object * this, int param
//                               LAB_0045c6de                                                 XREF[1]:     0045c6cf(j)
//                              move_obj.cpp:146 (22)
//         0045c6de     MOV        this,dword ptr [ESP + local_c]
//         0045c6e2     MOV        EAX,ESI
//         0045c6e4     POP        ESI
//         0045c6e5     POP        EBP
//         0045c6e6     MOV        dword ptr FS:[0x0],this
//         0045c6ed     POP        EBX
//         0045c6ee     ADD        ESP,0x10
//         0045c6f1     RET        0xc
//         0045c6f4     ??         90h
//         0045c6f5     NOP
//         0045c6f6     NOP
//         0045c6f7     NOP
//         0045c6f8     NOP
//         0045c6f9     NOP
//         0045c6fa     NOP
//         0045c6fb     NOP
//         0045c6fc     NOP
//         0045c6fd     NOP
//         0045c6fe     NOP
//         0045c6ff     NOP
}

RGE_Moving_Object::~RGE_Moving_Object() {
    /* TODO: Stub */
//                              void __thiscall ~RGE_Moving_Object(RGE_Moving_Object * this)
//              void              <VOID>         <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     0045c729(W), 0045c74e(W), 0045c75e(W), 0045c76a(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0045c777(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0045c719(W)
//                               ??1RGE_Moving_Object@@UAE@XZ                                 XREF[2]:     ~RGE_Action_Object:0040606a(c),
//                               RGE_Moving_Object::~RGE_Moving_Object                                     `scalar_deleting_destructor':0045c
//                              move_obj.cpp:152 (35)
//         0045c700     PUSH       -0x1
//         0045c702     PUSH       FUN_0055dce4
//         0045c707     MOV        EAX,FS:[0x0]
//         0045c70d     PUSH       EAX
//         0045c70e     MOV        dword ptr FS:[0x0],ESP
//         0045c715     PUSH       this
//         0045c716     PUSH       ESI
//         0045c717     MOV        ESI,this
//         0045c719     MOV        dword ptr [ESP + local_10],ESI
//         0045c71d     MOV        dword ptr [ESI],RGE_Moving_Object::`vftable'     = 0045c5a0
//                              move_obj.cpp:153 (18)
//         0045c723     MOV        EAX,dword ptr [ESI + 0x168]
//         0045c729     MOV        dword ptr [ESP + local_4],0x2
//         0045c731     TEST       EAX,EAX
//         0045c733     JZ         LAB_0045c748
//                              move_obj.cpp:155 (9)
//         0045c735     PUSH       EAX
//         0045c736     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0045c73b     ADD        ESP,0x4
//                              move_obj.cpp:156 (16)
//         0045c73e     MOV        dword ptr [ESI + 0x168],0x0
//                               LAB_0045c748                                                 XREF[1]:     0045c733(j)
//         0045c748     LEA        this,[ESI + 0xd8]
//                              move_obj.cpp:158 (57)
//         0045c74e     MOV        byte ptr [ESP + local_4],0x1
//         0045c753     CALL       Path::~Path                                      void ~Path(Path * this)
//         0045c758     LEA        this,[ESI + 0xa4]
//         0045c75e     MOV        byte ptr [ESP + local_4],0x0
//         0045c763     CALL       Path::~Path                                      void ~Path(Path * this)
//         0045c768     MOV        this,ESI
//         0045c76a     MOV        dword ptr [ESP + local_4],0xffffffff
//         0045c772     CALL       RGE_Static_Object::~RGE_Static_Object            void ~RGE_Static_Object(RGE_Static_Object * t
//         0045c777     MOV        this,dword ptr [ESP + local_c]
//         0045c77b     POP        ESI
//         0045c77c     MOV        dword ptr FS:[0x0],this
//         0045c783     ADD        ESP,0x10
//         0045c786     RET
//         0045c787     ??         90h
//         0045c788     NOP
//         0045c789     NOP
//         0045c78a     NOP
//         0045c78b     NOP
//         0045c78c     NOP
//         0045c78d     NOP
//         0045c78e     NOP
//         0045c78f     NOP
}

void RGE_Moving_Object::recycle_in_to_game(RGE_Master_Static_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5) {
    /* TODO: Stub */
//                              void __thiscall recycle_in_to_game(RGE_Moving_Object * this, RGE_Mas
//              void              <VOID>         <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//              RGE_Master_Sta    Stack[0x4]:4   param_1                   XREF[1]:     0045c842(R)
//              RGE_Player *      Stack[0x8]:4   param_2                   XREF[1]:     0045c82d(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     0045c83d(R)
//              float             Stack[0x10]:4  param_4                   XREF[3]:     0045c826(R), 0045c8d6(W), 0045c902(R)
//              float             Stack[0x14]:4  param_5                   XREF[3]:     0045c822(R), 0045c8fa(W), 0045c8fe(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0045c7c5(W), 0045c7d5(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0045c953(R)
//              undefined         Stack[-0x40]:1 local_40                  XREF[3]:     0045c7af(*), 0045c7b8(*), 0045c7d1(*)
//                               ?recycle_in_to_game@RGE_Moving_Object@@UAEXPAVRGE_Master_St  XREF[2]:     recycle_in_to_game:004060be(c),
//                               RGE_Moving_Object::recycle_in_to_game                                     0057094c(*)
//                              move_obj.cpp:164 (29)
//         0045c790     PUSH       -0x1
//         0045c792     PUSH       FUN_0055dcf8
//         0045c797     MOV        EAX,FS:[0x0]
//         0045c79d     PUSH       EAX
//         0045c79e     MOV        dword ptr FS:[0x0],ESP
//         0045c7a5     SUB        ESP,0x34
//         0045c7a8     PUSH       EBX
//         0045c7a9     PUSH       ESI
//         0045c7aa     MOV        ESI,this
//         0045c7ac     PUSH       EDI
//                              move_obj.cpp:165 (49)
//         0045c7ad     PUSH       0xa
//         0045c7af     LEA        this=>local_40,[ESP + 0x10]
//         0045c7b3     CALL       Path::Path                                       undefined Path(Path * this, int param_1)
//         0045c7b8     LEA        EAX=>local_40,[ESP + 0xc]
//         0045c7bc     XOR        EBX,EBX
//         0045c7be     PUSH       EAX
//         0045c7bf     LEA        this,[ESI + 0xa4]
//         0045c7c5     MOV        dword ptr [ESP + local_4],EBX
//         0045c7c9     CALL       Path::operator=                                  Path * operator=(Path * this, Path * param_1)
//         0045c7ce     OR         EDI,0xffffffff
//         0045c7d1     LEA        this=>local_40,[ESP + 0xc]
//         0045c7d5     MOV        dword ptr [ESP + local_4],EDI
//         0045c7d9     CALL       Path::~Path                                      void ~Path(Path * this)
//                              move_obj.cpp:173 (68)
//         0045c7de     PUSH       EBX
//         0045c7df     PUSH       EBX
//         0045c7e0     PUSH       EBX
//         0045c7e1     MOV        this,ESI
//         0045c7e3     MOV        dword ptr [ESI + 0x148],0x2
//         0045c7ed     MOV        dword ptr [ESI + 0x14c],EDI
//         0045c7f3     MOV        dword ptr [ESI + 0x150],EDI
//         0045c7f9     MOV        byte ptr [ESI + 0x154],BL
//         0045c7ff     MOV        byte ptr [ESI + 0x155],BL
//         0045c805     MOV        byte ptr [ESI + 0x156],BL
//         0045c80b     MOV        dword ptr [ESI + 0x10c],EBX
//         0045c811     MOV        dword ptr [ESI + 0x110],EBX
//         0045c817     MOV        dword ptr [ESI + 0x114],EBX
//         0045c81d     CALL       RGE_Moving_Object::setGoal                       void setGoal(RGE_Moving_Object * this, float
//                              move_obj.cpp:185 (98)
//         0045c822     MOV        this,dword ptr [ESP + param_5]
//         0045c826     MOV        EDX,dword ptr [ESP + param_4]
//         0045c82a     MOV        AL,0xff
//         0045c82c     PUSH       this
//         0045c82d     MOV        this,dword ptr [ESP + param_2]
//         0045c831     MOV        byte ptr [ESI + 0x17c],AL
//         0045c837     MOV        byte ptr [ESI + 0x17d],AL
//         0045c83d     MOV        EAX,dword ptr [ESP + param_3]
//         0045c841     PUSH       EDX
//         0045c842     MOV        EDX,dword ptr [ESP + param_1]
//         0045c846     PUSH       EAX
//         0045c847     PUSH       this
//         0045c848     PUSH       EDX
//         0045c849     MOV        this,ESI
//         0045c84b     MOV        dword ptr [ESI + 0x12c],EBX
//         0045c851     MOV        dword ptr [ESI + 0x130],EBX
//         0045c857     MOV        dword ptr [ESI + 0x134],EBX
//         0045c85d     MOV        dword ptr [ESI + 0x138],EDI
//         0045c863     MOV        dword ptr [ESI + 0x13c],EBX
//         0045c869     MOV        dword ptr [ESI + 0x140],EBX
//         0045c86f     MOV        dword ptr [ESI + 0x144],EBX
//         0045c875     MOV        dword ptr [ESI + 0x178],0x47c35000
//         0045c87f     CALL       RGE_Animated_Object::recycle_in_to_game          void recycle_in_to_game(RGE_Animated_Object *
//                              move_obj.cpp:195 (68)
//         0045c884     MOV        EAX,dword ptr [ESI + 0x10]
//         0045c887     MOV        dword ptr [ESI + 0x90],EBX
//         0045c88d     CMP        EAX,EBX
//         0045c88f     MOV        dword ptr [ESI + 0x94],EBX
//         0045c895     MOV        dword ptr [ESI + 0x98],EBX
//         0045c89b     MOV        dword ptr [ESI + 0x9c],EBX
//         0045c8a1     MOV        dword ptr [ESI + 0xa0],EBX
//         0045c8a7     MOV        dword ptr [ESI + 0x8c],EBX
//         0045c8ad     JZ         LAB_0045c94c
//         0045c8b3     TEST       byte ptr [EAX + 0x70],0x2
//         0045c8b7     JZ         LAB_0045c94c
//         0045c8bd     CMP        word ptr [EAX + 0x60],0x1
//         0045c8c2     JLE        LAB_0045c94c
//                              move_obj.cpp:197 (76)
//         0045c8c8     MOVSX      EDI,word ptr [EAX + 0x60]
//         0045c8cc     PUSH       0xc5
//         0045c8d1     PUSH       s_C:\msdev\work\age1_x1\move_obj.c               = "C:\\msdev\\work\\age1_x1\\move_obj.cpp"
//         0045c8d6     MOV        dword ptr [ESP + param_4],EDI
//         0045c8da     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         0045c8df     MOV        this,EAX
//         0045c8e1     MOV        EAX,0x80010003
//         0045c8e6     IMUL       this,EDI
//         0045c8e9     IMUL       this
//         0045c8eb     ADD        EDX,this
//         0045c8ed     ADD        ESP,0x8
//         0045c8f0     SAR        EDX,0xe
//         0045c8f3     MOV        this,EDX
//         0045c8f5     SHR        this,0x1f
//         0045c8f8     ADD        EDX,this
//         0045c8fa     MOV        dword ptr [ESP + param_5],EDX
//         0045c8fe     FILD       dword ptr [ESP + param_5]
//         0045c902     FILD       dword ptr [ESP + param_4]
//         0045c906     FDIVR      double ptr [DAT_00570b40]                        = F1h
//         0045c90c     FMULP
//         0045c90e     FST        float ptr [ESI + 0x9c]
//                              move_obj.cpp:198 (56)
//         0045c914     FCOM       float ptr [DAT_00570b48]
//         0045c91a     FNSTSW     AX
//         0045c91c     TEST       AH,0x1
//         0045c91f     JZ         LAB_0045c92f
//         0045c921     FSUB       float ptr [DAT_00570b4c]                         = DBh
//         0045c927     FSTP       float ptr [ESI + 0x9c]
//         0045c92d     JMP        LAB_0045c94c
//                               LAB_0045c92f                                                 XREF[1]:     0045c91f(j)
//         0045c92f     FCOM       float ptr [DAT_00570b50]                         = DBh
//         0045c935     FNSTSW     AX
//         0045c937     TEST       AH,0x41
//         0045c93a     JNZ        LAB_0045c94a
//         0045c93c     FSUB       float ptr [DAT_00570b50]                         = DBh
//         0045c942     FSTP       float ptr [ESI + 0x9c]
//         0045c948     JMP        LAB_0045c94c
//                               LAB_0045c94a                                                 XREF[1]:     0045c93a(j)
//         0045c94a     FSTP       ST0
//                               LAB_0045c94c                                                 XREF[5]:     0045c8ad(j), 0045c8b7(j),
//                                                                                                         0045c8c2(j), 0045c92d(j),
//                                                                                                         0045c948(j)
//                              move_obj.cpp:201 (7)
//         0045c94c     MOV        this,ESI
//         0045c94e     CALL       RGE_Moving_Object::set_angle                     void set_angle(RGE_Moving_Object * this)
//                              move_obj.cpp:202 (20)
//         0045c953     MOV        this,dword ptr [ESP + local_c]
//         0045c957     POP        EDI
//         0045c958     POP        ESI
//         0045c959     MOV        dword ptr FS:[0x0],this
//         0045c960     POP        EBX
//         0045c961     ADD        ESP,0x40
//         0045c964     RET        0x14
//         0045c967     ??         90h
//         0045c968     NOP
//         0045c969     NOP
//         0045c96a     NOP
//         0045c96b     NOP
//         0045c96c     NOP
//         0045c96d     NOP
//         0045c96e     NOP
//         0045c96f     NOP
    return;
}

int RGE_Moving_Object::setup(RGE_Master_Moving_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5) {
    /* TODO: Stub */
//                              int __thiscall setup(RGE_Moving_Object * this, RGE_Master_Moving_Obj
//              int               EAX:4          <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//              RGE_Master_Mov    Stack[0x4]:4   param_1                   XREF[1]:     0045c986(R)
//              RGE_Player *      Stack[0x8]:4   param_2                   XREF[1]:     0045c981(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     0045c974(R)
//              float             Stack[0x10]:4  param_4                   XREF[3]:     0045c97b(R), 0045c9ee(W), 0045ca1a(R)
//              float             Stack[0x14]:4  param_5                   XREF[3]:     0045c970(R), 0045ca12(W), 0045ca16(R)
//                               ?setup@RGE_Moving_Object@@MAEHPAVRGE_Master_Moving_Object@@  XREF[8]:     setup:004060ee(c),
//                               RGE_Moving_Object::setup                                                  RGE_Moving_Object:0045c581(c),
//                                                                                                         0056e614(*), 0056f44c(*),
//                                                                                                         005708e4(*), 00570b3c(*),
//                                                                                                         0057496c(*), 00574c14(*)
//                              move_obj.cpp:208 (36)
//         0045c970     MOV        EAX,dword ptr [ESP + param_5]
//         0045c974     MOV        EDX,dword ptr [ESP + param_3]
//         0045c978     PUSH       ESI
//         0045c979     MOV        ESI,this
//         0045c97b     MOV        this,dword ptr [ESP + param_4]
//         0045c97f     PUSH       EDI
//         0045c980     PUSH       EAX
//         0045c981     MOV        EAX,dword ptr [ESP + param_2]
//         0045c985     PUSH       this
//         0045c986     MOV        this,dword ptr [ESP + param_1]
//         0045c98a     PUSH       EDX
//         0045c98b     PUSH       EAX
//         0045c98c     PUSH       this
//         0045c98d     MOV        this,ESI
//         0045c98f     CALL       RGE_Animated_Object::setup                       int setup(RGE_Animated_Object * this, RGE_Mas
//                              move_obj.cpp:220 (74)
//         0045c994     MOV        this,dword ptr [ESI + 0x10]
//         0045c997     XOR        EAX,EAX
//         0045c999     CMP        this,EAX
//         0045c99b     MOV        byte ptr [ESI + 0x4e],0x1e
//         0045c99f     MOV        dword ptr [ESI + 0x90],EAX
//         0045c9a5     MOV        dword ptr [ESI + 0x94],EAX
//         0045c9ab     MOV        dword ptr [ESI + 0x98],EAX
//         0045c9b1     MOV        dword ptr [ESI + 0x9c],EAX
//         0045c9b7     MOV        dword ptr [ESI + 0xa0],EAX
//         0045c9bd     MOV        dword ptr [ESI + 0x8c],EAX
//         0045c9c3     JZ         LAB_0045ca82
//         0045c9c9     TEST       byte ptr [ECX + this->_padding_],0x2
//         0045c9cd     JZ         LAB_0045ca82
//         0045c9d3     CMP        word ptr [ECX + this->_padding_],0x1
//         0045c9d8     JLE        LAB_0045ca82
//                              move_obj.cpp:222 (78)
//         0045c9de     MOV        EDX,this
//         0045c9e0     PUSH       0xde
//         0045c9e5     PUSH       s_C:\msdev\work\age1_x1\move_obj.c               = "C:\\msdev\\work\\age1_x1\\move_obj.cpp"
//         0045c9ea     MOVSX      EDI,word ptr [EDX + 0x60]
//         0045c9ee     MOV        dword ptr [ESP + param_4],EDI
//         0045c9f2     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         0045c9f7     MOV        this,EAX
//         0045c9f9     MOV        EAX,0x80010003
//         0045c9fe     IMUL       this,EDI
//         0045ca01     IMUL       this
//         0045ca03     ADD        EDX,this
//         0045ca05     ADD        ESP,0x8
//         0045ca08     SAR        EDX,0xe
//         0045ca0b     MOV        EAX,EDX
//         0045ca0d     SHR        EAX,0x1f
//         0045ca10     ADD        EDX,EAX
//         0045ca12     MOV        dword ptr [ESP + param_5],EDX
//         0045ca16     FILD       dword ptr [ESP + param_5]
//         0045ca1a     FILD       dword ptr [ESP + param_4]
//         0045ca1e     FDIVR      double ptr [DAT_00570b40]                        = F1h
//         0045ca24     FMULP
//         0045ca26     FST        float ptr [ESI + 0x9c]
//                              move_obj.cpp:223 (19)
//         0045ca2c     FCOM       float ptr [DAT_00570b48]
//         0045ca32     FNSTSW     AX
//         0045ca34     TEST       AH,0x1
//         0045ca37     JZ         LAB_0045ca56
//         0045ca39     FSUB       float ptr [DAT_00570b4c]                         = DBh
//                              move_obj.cpp:226 (13)
//         0045ca3f     MOV        this,ESI
//         0045ca41     FSTP       float ptr [ESI + 0x9c]
//         0045ca47     CALL       RGE_Moving_Object::set_angle                     void set_angle(RGE_Moving_Object * this)
//                              move_obj.cpp:228 (5)
//         0045ca4c     MOV        EAX,0x1
//                              move_obj.cpp:229 (5)
//         0045ca51     POP        EDI
//         0045ca52     POP        ESI
//         0045ca53     RET        0x14
//                               LAB_0045ca56                                                 XREF[1]:     0045ca37(j)
//                              move_obj.cpp:223 (19)
//         0045ca56     FCOM       float ptr [DAT_00570b50]                         = DBh
//         0045ca5c     FNSTSW     AX
//         0045ca5e     TEST       AH,0x41
//         0045ca61     JNZ        LAB_0045ca80
//         0045ca63     FSUB       float ptr [DAT_00570b50]                         = DBh
//                              move_obj.cpp:226 (13)
//         0045ca69     MOV        this,ESI
//         0045ca6b     FSTP       float ptr [ESI + 0x9c]
//         0045ca71     CALL       RGE_Moving_Object::set_angle                     void set_angle(RGE_Moving_Object * this)
//                              move_obj.cpp:228 (5)
//         0045ca76     MOV        EAX,0x1
//                              move_obj.cpp:229 (5)
//         0045ca7b     POP        EDI
//         0045ca7c     POP        ESI
//         0045ca7d     RET        0x14
//                               LAB_0045ca80                                                 XREF[1]:     0045ca61(j)
//                              move_obj.cpp:223 (2)
//         0045ca80     FSTP       ST0
//                               LAB_0045ca82                                                 XREF[3]:     0045c9c3(j), 0045c9cd(j),
//                                                                                                         0045c9d8(j)
//                              move_obj.cpp:226 (7)
//         0045ca82     MOV        this,ESI
//         0045ca84     CALL       RGE_Moving_Object::set_angle                     void set_angle(RGE_Moving_Object * this)
//                              move_obj.cpp:229 (10)
//         0045ca89     POP        EDI
//         0045ca8a     MOV        EAX,0x1
//         0045ca8f     POP        ESI
//         0045ca90     RET        0x14
//         0045ca93     ??         90h
//         0045ca94     NOP
//         0045ca95     NOP
//         0045ca96     NOP
//         0045ca97     NOP
//         0045ca98     NOP
//         0045ca99     NOP
//         0045ca9a     NOP
//         0045ca9b     NOP
//         0045ca9c     NOP
//         0045ca9d     NOP
//         0045ca9e     NOP
//         0045ca9f     NOP
    return 0;
}

int RGE_Moving_Object::setup(int param_1, RGE_Game_World* param_2) {
    /* TODO: Stub */
//                              int __thiscall setup(RGE_Moving_Object * this, int param_1, RGE_Game
//              int               EAX:4          <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[4]:     0045caab(R), 0045cb28(*), 0045cb35(R), 0045cb7c(R)
//              RGE_Game_World    Stack[0x8]:4   param_2                   XREF[5]:     0045caa0(R), 0045ccd5(W), 0045ccd9(R), 0045ccee(R),
//                                                                                     0045ccfe(W)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0045cb6b(R)
//              Waypoint          Stack[-0x14]   temp                      XREF[3,4]:   0045cb85(*), 0045cba4(R), 0045cbb3(R), 0045cb48(*),
//                                                                                     0045cb55(R), 0045cb59(R), 0045cb64(R)
//              int               Stack[-0x18]:4 currentWaypoint
//              undefined4        Stack[-0x28]:4 local_28                  XREF[1]:     0045cb74(W)
//              undefined4        Stack[-0x2c]:4 local_2c                  XREF[1]:     0045cb6f(W)
//              undefined4        Stack[-0x30]:4 local_30                  XREF[1]:     0045cb68(W)
//              undefined4        Stack[-0x34]:4 local_34                  XREF[1]:     0045cb62(*)
//                               ?setup@RGE_Moving_Object@@MAEHHPAVRGE_Game_World@@@Z         XREF[3]:     setup:0040612e(c),
//                               RGE_Moving_Object::setup                                                  RGE_Moving_Object:0045c6d9(c),
//                                                                                                         00570b20(*)
//                              move_obj.cpp:232 (24)
//         0045caa0     MOV        EAX,dword ptr [ESP + param_2]
//         0045caa4     SUB        ESP,0x14
//         0045caa7     PUSH       EBX
//         0045caa8     PUSH       EBP
//         0045caa9     PUSH       ESI
//         0045caaa     PUSH       EDI
//         0045caab     MOV        EDI,dword ptr [ESP + param_1]
//         0045caaf     PUSH       EAX
//         0045cab0     MOV        ESI,this
//         0045cab2     PUSH       EDI
//         0045cab3     CALL       RGE_Animated_Object::setup                       int setup(RGE_Animated_Object * this, int par
//                              move_obj.cpp:237 (22)
//         0045cab8     LEA        this,[ESI + 0x8c]
//         0045cabe     PUSH       0x4
//         0045cac0     PUSH       this
//         0045cac1     PUSH       EDI
//         0045cac2     MOV        byte ptr [ESI + 0x4e],0x1e
//         0045cac6     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0045cacb     ADD        ESP,0xc
//                              move_obj.cpp:238 (18)
//         0045cace     LEA        EDX,[ESI + 0x90]
//         0045cad4     PUSH       0x4
//         0045cad6     PUSH       EDX
//         0045cad7     PUSH       EDI
//         0045cad8     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0045cadd     ADD        ESP,0xc
//                              move_obj.cpp:239 (18)
//         0045cae0     LEA        EAX,[ESI + 0x94]
//         0045cae6     PUSH       0x4
//         0045cae8     PUSH       EAX
//         0045cae9     PUSH       EDI
//         0045caea     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0045caef     ADD        ESP,0xc
//                              move_obj.cpp:240 (18)
//         0045caf2     LEA        this,[ESI + 0x98]
//         0045caf8     PUSH       0x4
//         0045cafa     PUSH       this
//         0045cafb     PUSH       EDI
//         0045cafc     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0045cb01     ADD        ESP,0xc
//                              move_obj.cpp:241 (18)
//         0045cb04     LEA        EDX,[ESI + 0x9c]
//         0045cb0a     PUSH       0x4
//         0045cb0c     PUSH       EDX
//         0045cb0d     PUSH       EDI
//         0045cb0e     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0045cb13     ADD        ESP,0xc
//                              move_obj.cpp:242 (18)
//         0045cb16     LEA        EAX,[ESI + 0xa0]
//         0045cb1c     PUSH       0x4
//         0045cb1e     PUSH       EAX
//         0045cb1f     PUSH       EDI
//         0045cb20     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0045cb25     ADD        ESP,0xc
//                              move_obj.cpp:246 (13)
//         0045cb28     LEA        this=>param_1,[ESP + 0x28]
//         0045cb2c     PUSH       0x4
//         0045cb2e     PUSH       this
//         0045cb2f     PUSH       EDI
//         0045cb30     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              move_obj.cpp:248 (13)
//         0045cb35     MOV        EAX,dword ptr [ESP + param_1]
//         0045cb39     ADD        ESP,0xc
//         0045cb3c     XOR        EBX,EBX
//         0045cb3e     TEST       EAX,EAX
//         0045cb40     JLE        LAB_0045cb85
//                              move_obj.cpp:250 (6)
//         0045cb42     LEA        EBP,[ESI + 0xa4]
//                               LAB_0045cb48                                                 XREF[1]:     0045cb83(j)
//                              move_obj.cpp:249 (13)
//         0045cb48     LEA        EDX=>temp.y,[ESP + 0x14]
//         0045cb4c     PUSH       0x10
//         0045cb4e     PUSH       EDX
//         0045cb4f     PUSH       EDI
//         0045cb50     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              move_obj.cpp:250 (48)
//         0045cb55     MOV        this,dword ptr [ESP + temp.y]
//         0045cb59     MOV        EDX,dword ptr [ESP + temp.z]
//         0045cb5d     ADD        ESP,-0x4
//         0045cb60     MOV        EAX,ESP
//         0045cb62     MOV        dword ptr [EAX]=>local_34,this
//         0045cb64     MOV        this,dword ptr [ESP + temp.facetToNextWaypoint]
//         0045cb68     MOV        dword ptr [EAX + local_30],EDX
//         0045cb6b     MOV        EDX,dword ptr [ESP + local_4]
//         0045cb6f     MOV        dword ptr [EAX + local_2c],this
//         0045cb72     MOV        this,EBP
//         0045cb74     MOV        dword ptr [EAX + local_28],EDX
//         0045cb77     CALL       Path::insertAtEnd                                int insertAtEnd(Path * this, Waypoint param_1)
//         0045cb7c     MOV        EAX,dword ptr [ESP + param_1]
//         0045cb80     INC        EBX
//         0045cb81     CMP        EBX,EAX
//         0045cb83     JL         LAB_0045cb48
//                               LAB_0045cb85                                                 XREF[1]:     0045cb40(j)
//                              move_obj.cpp:253 (13)
//         0045cb85     LEA        EAX=>temp,[ESP + 0x10]
//         0045cb89     PUSH       0x4
//         0045cb8b     PUSH       EAX
//         0045cb8c     PUSH       EDI
//         0045cb8d     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              move_obj.cpp:254 (26)
//         0045cb92     LEA        EBP,[ESI + 0xa4]
//         0045cb98     ADD        ESP,0xc
//         0045cb9b     MOV        this,EBP
//         0045cb9d     XOR        EBX,EBX
//         0045cb9f     CALL       Path::initToStart                                void initToStart(Path * this)
//         0045cba4     MOV        EAX,dword ptr [ESP + temp.x]
//         0045cba8     TEST       EAX,EAX
//         0045cbaa     JLE        LAB_0045cbbc
//                               LAB_0045cbac                                                 XREF[1]:     0045cbba(j)
//                              move_obj.cpp:255 (16)
//         0045cbac     MOV        this,EBP
//         0045cbae     CALL       Path::moveToNextWaypoint                         int moveToNextWaypoint(Path * this)
//         0045cbb3     MOV        EAX,dword ptr [ESP + temp.x]
//         0045cbb7     INC        EBX
//         0045cbb8     CMP        EBX,EAX
//         0045cbba     JL         LAB_0045cbac
//                               LAB_0045cbbc                                                 XREF[1]:     0045cbaa(j)
//                              move_obj.cpp:256 (18)
//         0045cbbc     LEA        this,[ESI + 0x10c]
//         0045cbc2     PUSH       0x10
//         0045cbc4     PUSH       this
//         0045cbc5     PUSH       EDI
//         0045cbc6     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0045cbcb     ADD        ESP,0xc
//                              move_obj.cpp:257 (18)
//         0045cbce     LEA        EDX,[ESI + 0x11c]
//         0045cbd4     PUSH       0x10
//         0045cbd6     PUSH       EDX
//         0045cbd7     PUSH       EDI
//         0045cbd8     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0045cbdd     ADD        ESP,0xc
//                              move_obj.cpp:258 (18)
//         0045cbe0     LEA        EAX,[ESI + 0x12c]
//         0045cbe6     PUSH       0x4
//         0045cbe8     PUSH       EAX
//         0045cbe9     PUSH       EDI
//         0045cbea     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0045cbef     ADD        ESP,0xc
//                              move_obj.cpp:259 (18)
//         0045cbf2     LEA        this,[ESI + 0x130]
//         0045cbf8     PUSH       0x4
//         0045cbfa     PUSH       this
//         0045cbfb     PUSH       EDI
//         0045cbfc     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0045cc01     ADD        ESP,0xc
//                              move_obj.cpp:260 (18)
//         0045cc04     LEA        EDX,[ESI + 0x134]
//         0045cc0a     PUSH       0x4
//         0045cc0c     PUSH       EDX
//         0045cc0d     PUSH       EDI
//         0045cc0e     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0045cc13     ADD        ESP,0xc
//                              move_obj.cpp:261 (18)
//         0045cc16     LEA        EAX,[ESI + 0x138]
//         0045cc1c     PUSH       0x4
//         0045cc1e     PUSH       EAX
//         0045cc1f     PUSH       EDI
//         0045cc20     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0045cc25     ADD        ESP,0xc
//                              move_obj.cpp:262 (18)
//         0045cc28     LEA        this,[ESI + 0x13c]
//         0045cc2e     PUSH       0x4
//         0045cc30     PUSH       this
//         0045cc31     PUSH       EDI
//         0045cc32     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0045cc37     ADD        ESP,0xc
//                              move_obj.cpp:263 (18)
//         0045cc3a     LEA        EDX,[ESI + 0x140]
//         0045cc40     PUSH       0x4
//         0045cc42     PUSH       EDX
//         0045cc43     PUSH       EDI
//         0045cc44     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0045cc49     ADD        ESP,0xc
//                              move_obj.cpp:264 (18)
//         0045cc4c     LEA        EAX,[ESI + 0x144]
//         0045cc52     PUSH       0x4
//         0045cc54     PUSH       EAX
//         0045cc55     PUSH       EDI
//         0045cc56     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0045cc5b     ADD        ESP,0xc
//                              move_obj.cpp:265 (18)
//         0045cc5e     LEA        this,[ESI + 0x148]
//         0045cc64     PUSH       0x4
//         0045cc66     PUSH       this
//         0045cc67     PUSH       EDI
//         0045cc68     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0045cc6d     ADD        ESP,0xc
//                              move_obj.cpp:266 (18)
//         0045cc70     LEA        EDX,[ESI + 0x155]
//         0045cc76     PUSH       0x1
//         0045cc78     PUSH       EDX
//         0045cc79     PUSH       EDI
//         0045cc7a     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0045cc7f     ADD        ESP,0xc
//                              move_obj.cpp:267 (18)
//         0045cc82     LEA        EAX,[ESI + 0x156]
//         0045cc88     PUSH       0x1
//         0045cc8a     PUSH       EAX
//         0045cc8b     PUSH       EDI
//         0045cc8c     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0045cc91     ADD        ESP,0xc
//                              move_obj.cpp:270 (18)
//         0045cc94     LEA        EBP,[ESI + 0x16c]
//         0045cc9a     PUSH       0x4
//         0045cc9c     PUSH       EBP
//         0045cc9d     PUSH       EDI
//         0045cc9e     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0045cca3     ADD        ESP,0xc
//                              move_obj.cpp:271 (15)
//         0045cca6     LEA        EBX,[ESI + 0x170]
//         0045ccac     PUSH       0x4
//         0045ccae     PUSH       EBX
//         0045ccaf     PUSH       EDI
//         0045ccb0     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              move_obj.cpp:272 (20)
//         0045ccb5     MOV        EBX,dword ptr [EBX]
//         0045ccb7     ADD        ESP,0xc
//         0045ccba     LEA        this,[EBX + EBX*0x2]
//         0045ccbd     PUSH       this
//         0045ccbe     CALL       operator_new                                     void * operator_new(uint param_1)
//         0045ccc3     MOV        dword ptr [ESI + 0x168],EAX
//                              move_obj.cpp:273 (12)
//         0045ccc9     MOV        EAX,dword ptr [EBP]
//         0045cccc     XOR        EBX,EBX
//         0045ccce     ADD        ESP,0x4
//         0045ccd1     CMP        EAX,EBX
//         0045ccd3     JLE        LAB_0045cd04
//                              move_obj.cpp:256 (4)
//         0045ccd5     MOV        dword ptr [ESP + param_2],EBX
//                               LAB_0045ccd9                                                 XREF[1]:     0045cd02(j)
//                              move_obj.cpp:274 (43)
//         0045ccd9     MOV        EDX,dword ptr [ESP + param_2]
//         0045ccdd     MOV        this,dword ptr [ESI + 0x168]
//         0045cce3     ADD        EDX,this
//         0045cce5     PUSH       0x3
//         0045cce7     PUSH       EDX
//         0045cce8     PUSH       EDI
//         0045cce9     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0045ccee     MOV        this,dword ptr [ESP + param_2]
//         0045ccf2     MOV        EAX,dword ptr [EBP]
//         0045ccf5     ADD        ESP,0xc
//         0045ccf8     INC        EBX
//         0045ccf9     ADD        this,0x3
//         0045ccfc     CMP        EBX,EAX
//         0045ccfe     MOV        dword ptr [ESP + param_2],this
//         0045cd02     JL         LAB_0045ccd9
//                               LAB_0045cd04                                                 XREF[1]:     0045ccd3(j)
//                              move_obj.cpp:275 (15)
//         0045cd04     LEA        EAX,[ESI + 0x174]
//         0045cd0a     PUSH       0x1
//         0045cd0c     PUSH       EAX
//         0045cd0d     PUSH       EDI
//         0045cd0e     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              move_obj.cpp:277 (22)
//         0045cd13     FLD        float ptr [save_game_version]                    = 7.23
//         0045cd19     FCOMP      float ptr [DAT_00570b54]                         = 66h    f
//         0045cd1f     ADD        ESP,0xc
//         0045cd22     FNSTSW     AX
//         0045cd24     TEST       AH,0x1
//         0045cd27     JNZ        LAB_0045cd4f
//                              move_obj.cpp:278 (18)
//         0045cd29     LEA        this,[ESI + 0x158]
//         0045cd2f     PUSH       0x8
//         0045cd31     PUSH       this
//         0045cd32     PUSH       EDI
//         0045cd33     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0045cd38     ADD        ESP,0xc
//                              move_obj.cpp:279 (18)
//         0045cd3b     LEA        EDX,[ESI + 0x160]
//         0045cd41     PUSH       0x8
//         0045cd43     PUSH       EDX
//         0045cd44     PUSH       EDI
//         0045cd45     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0045cd4a     ADD        ESP,0xc
//                              move_obj.cpp:281 (2)
//         0045cd4d     JMP        LAB_0045cd6a
//                               LAB_0045cd4f                                                 XREF[1]:     0045cd27(j)
//                              move_obj.cpp:282 (9)
//         0045cd4f     OR         EAX,0xffffffff
//         0045cd52     MOV        dword ptr [ESI + 0x158],EAX
//                              move_obj.cpp:283 (6)
//         0045cd58     MOV        dword ptr [ESI + 0x15c],EAX
//                              move_obj.cpp:284 (6)
//         0045cd5e     MOV        dword ptr [ESI + 0x160],EAX
//                              move_obj.cpp:285 (6)
//         0045cd64     MOV        dword ptr [ESI + 0x164],EAX
//                               LAB_0045cd6a                                                 XREF[1]:     0045cd4d(j)
//                              move_obj.cpp:288 (21)
//         0045cd6a     FLD        float ptr [save_game_version]                    = 7.23
//         0045cd70     FCOMP      float ptr [DAT_00570b58]                         = 3Dh    =
//         0045cd76     MOV        BL,0xff
//         0045cd78     FNSTSW     AX
//         0045cd7a     TEST       AH,0x1
//         0045cd7d     JNZ        LAB_0045cda5
//                              move_obj.cpp:290 (18)
//         0045cd7f     LEA        EAX,[ESI + 0x178]
//         0045cd85     PUSH       0x4
//         0045cd87     PUSH       EAX
//         0045cd88     PUSH       EDI
//         0045cd89     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0045cd8e     ADD        ESP,0xc
//                              move_obj.cpp:291 (18)
//         0045cd91     LEA        this,[ESI + 0x17c]
//         0045cd97     PUSH       0x1
//         0045cd99     PUSH       this
//         0045cd9a     PUSH       EDI
//         0045cd9b     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0045cda0     ADD        ESP,0xc
//                              move_obj.cpp:293 (2)
//         0045cda3     JMP        LAB_0045cdb5
//                               LAB_0045cda5                                                 XREF[1]:     0045cd7d(j)
//                              move_obj.cpp:295 (10)
//         0045cda5     MOV        dword ptr [ESI + 0x178],0x47c35000
//                              move_obj.cpp:296 (6)
//         0045cdaf     MOV        byte ptr [ESI + 0x17c],BL
//                               LAB_0045cdb5                                                 XREF[1]:     0045cda3(j)
//                              move_obj.cpp:298 (19)
//         0045cdb5     FLD        float ptr [save_game_version]                    = 7.23
//         0045cdbb     FCOMP      float ptr [DAT_00570b5c]                         = 29h    )
//         0045cdc1     FNSTSW     AX
//         0045cdc3     TEST       AH,0x1
//         0045cdc6     JNZ        LAB_0045cde9
//                              move_obj.cpp:299 (18)
//         0045cdc8     ADD        ESI,0x17d
//         0045cdce     PUSH       0x1
//         0045cdd0     PUSH       ESI
//         0045cdd1     PUSH       EDI
//         0045cdd2     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0045cdd7     ADD        ESP,0xc
//                              move_obj.cpp:303 (5)
//         0045cdda     MOV        EAX,0x1
//                              move_obj.cpp:304 (10)
//         0045cddf     POP        EDI
//         0045cde0     POP        ESI
//         0045cde1     POP        EBP
//         0045cde2     POP        EBX
//         0045cde3     ADD        ESP,0x14
//         0045cde6     RET        0x8
//                               LAB_0045cde9                                                 XREF[1]:     0045cdc6(j)
//                              move_obj.cpp:301 (6)
//         0045cde9     MOV        byte ptr [ESI + 0x17d],BL
//                              move_obj.cpp:304 (15)
//         0045cdef     POP        EDI
//         0045cdf0     POP        ESI
//         0045cdf1     POP        EBP
//         0045cdf2     MOV        EAX,0x1
//         0045cdf7     POP        EBX
//         0045cdf8     ADD        ESP,0x14
//         0045cdfb     RET        0x8
//         0045cdfe     ??         90h
//         0045cdff     NOP
    return 0;
}

void RGE_Moving_Object::save(int param_1) {
    /* TODO: Stub */
//                              void __thiscall save(RGE_Moving_Object * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[5]:     0045ce04(R), 0045ce8a(W), 0045ce8e(*), 0045ce9b(R),
//                                                                                     0045ceb9(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0045cecc(*), 0045ced4(W)
//              int               Stack[-0x8]:4  currentWaypoint
//                               ?save@RGE_Moving_Object@@UAEXH@Z                             XREF[2]:     save:00406229(c), 00570978(*)
//                               RGE_Moving_Object::save
//                              move_obj.cpp:307 (4)
//         0045ce00     PUSH       this
//         0045ce01     PUSH       EBX
//         0045ce02     PUSH       EBP
//         0045ce03     PUSH       ESI
//                              move_obj.cpp:308 (13)
//         0045ce04     MOV        ESI,dword ptr [ESP + param_1]
//         0045ce08     PUSH       EDI
//         0045ce09     MOV        EDI,this
//         0045ce0b     PUSH       ESI
//         0045ce0c     CALL       RGE_Animated_Object::save                        void save(RGE_Animated_Object * this, int par
//                              move_obj.cpp:310 (18)
//         0045ce11     LEA        EAX,[EDI + 0x8c]
//         0045ce17     PUSH       0x4
//         0045ce19     PUSH       EAX
//         0045ce1a     PUSH       ESI
//         0045ce1b     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0045ce20     ADD        ESP,0xc
//                              move_obj.cpp:311 (18)
//         0045ce23     LEA        this,[EDI + 0x90]
//         0045ce29     PUSH       0x4
//         0045ce2b     PUSH       this
//         0045ce2c     PUSH       ESI
//         0045ce2d     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0045ce32     ADD        ESP,0xc
//                              move_obj.cpp:312 (18)
//         0045ce35     LEA        EDX,[EDI + 0x94]
//         0045ce3b     PUSH       0x4
//         0045ce3d     PUSH       EDX
//         0045ce3e     PUSH       ESI
//         0045ce3f     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0045ce44     ADD        ESP,0xc
//                              move_obj.cpp:313 (18)
//         0045ce47     LEA        EAX,[EDI + 0x98]
//         0045ce4d     PUSH       0x4
//         0045ce4f     PUSH       EAX
//         0045ce50     PUSH       ESI
//         0045ce51     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0045ce56     ADD        ESP,0xc
//                              move_obj.cpp:314 (18)
//         0045ce59     LEA        this,[EDI + 0x9c]
//         0045ce5f     PUSH       0x4
//         0045ce61     PUSH       this
//         0045ce62     PUSH       ESI
//         0045ce63     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0045ce68     ADD        ESP,0xc
//                              move_obj.cpp:315 (15)
//         0045ce6b     LEA        EDX,[EDI + 0xa0]
//         0045ce71     PUSH       0x4
//         0045ce73     PUSH       EDX
//         0045ce74     PUSH       ESI
//         0045ce75     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              move_obj.cpp:318 (20)
//         0045ce7a     LEA        EBP,[EDI + 0xa4]
//         0045ce80     ADD        ESP,0xc
//         0045ce83     MOV        this,EBP
//         0045ce85     CALL       Path::numberOfWaypoints                          int numberOfWaypoints(Path * this)
//         0045ce8a     MOV        dword ptr [ESP + param_1],EAX
//                              move_obj.cpp:319 (13)
//         0045ce8e     LEA        EAX=>param_1,[ESP + 0x18]
//         0045ce92     PUSH       0x4
//         0045ce94     PUSH       EAX
//         0045ce95     PUSH       ESI
//         0045ce96     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              move_obj.cpp:320 (13)
//         0045ce9b     MOV        EAX,dword ptr [ESP + param_1]
//         0045ce9f     ADD        ESP,0xc
//         0045cea2     XOR        EBX,EBX
//         0045cea4     TEST       EAX,EAX
//         0045cea6     JLE        LAB_0045cec5
//                               LAB_0045cea8                                                 XREF[1]:     0045cec3(j)
//                              move_obj.cpp:321 (29)
//         0045cea8     PUSH       0x10
//         0045ceaa     PUSH       EBX
//         0045ceab     MOV        this,EBP
//         0045cead     CALL       Path::waypoint                                   Waypoint * waypoint(Path * this, int param_1)
//         0045ceb2     PUSH       EAX
//         0045ceb3     PUSH       ESI
//         0045ceb4     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0045ceb9     MOV        EAX,dword ptr [ESP + param_1]
//         0045cebd     ADD        ESP,0xc
//         0045cec0     INC        EBX
//         0045cec1     CMP        EBX,EAX
//         0045cec3     JL         LAB_0045cea8
//                               LAB_0045cec5                                                 XREF[1]:     0045cea6(j)
//                              move_obj.cpp:322 (7)
//         0045cec5     MOV        this,EBP
//         0045cec7     CALL       Path::currentWaypointNumber                      int currentWaypointNumber(Path * this)
//                              move_obj.cpp:323 (20)
//         0045cecc     LEA        this=>local_4,[ESP + 0x10]
//         0045ced0     PUSH       0x4
//         0045ced2     PUSH       this
//         0045ced3     PUSH       ESI
//         0045ced4     MOV        dword ptr [ESP + local_4],EAX
//         0045ced8     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0045cedd     ADD        ESP,0xc
//                              move_obj.cpp:324 (18)
//         0045cee0     LEA        EDX,[EDI + 0x10c]
//         0045cee6     PUSH       0x10
//         0045cee8     PUSH       EDX
//         0045cee9     PUSH       ESI
//         0045ceea     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0045ceef     ADD        ESP,0xc
//                              move_obj.cpp:325 (18)
//         0045cef2     LEA        EAX,[EDI + 0x11c]
//         0045cef8     PUSH       0x10
//         0045cefa     PUSH       EAX
//         0045cefb     PUSH       ESI
//         0045cefc     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0045cf01     ADD        ESP,0xc
//                              move_obj.cpp:326 (18)
//         0045cf04     LEA        this,[EDI + 0x12c]
//         0045cf0a     PUSH       0x4
//         0045cf0c     PUSH       this
//         0045cf0d     PUSH       ESI
//         0045cf0e     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0045cf13     ADD        ESP,0xc
//                              move_obj.cpp:327 (18)
//         0045cf16     LEA        EDX,[EDI + 0x130]
//         0045cf1c     PUSH       0x4
//         0045cf1e     PUSH       EDX
//         0045cf1f     PUSH       ESI
//         0045cf20     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0045cf25     ADD        ESP,0xc
//                              move_obj.cpp:328 (18)
//         0045cf28     LEA        EAX,[EDI + 0x134]
//         0045cf2e     PUSH       0x4
//         0045cf30     PUSH       EAX
//         0045cf31     PUSH       ESI
//         0045cf32     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0045cf37     ADD        ESP,0xc
//                              move_obj.cpp:329 (18)
//         0045cf3a     LEA        this,[EDI + 0x138]
//         0045cf40     PUSH       0x4
//         0045cf42     PUSH       this
//         0045cf43     PUSH       ESI
//         0045cf44     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0045cf49     ADD        ESP,0xc
//                              move_obj.cpp:330 (18)
//         0045cf4c     LEA        EDX,[EDI + 0x13c]
//         0045cf52     PUSH       0x4
//         0045cf54     PUSH       EDX
//         0045cf55     PUSH       ESI
//         0045cf56     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0045cf5b     ADD        ESP,0xc
//                              move_obj.cpp:331 (18)
//         0045cf5e     LEA        EAX,[EDI + 0x140]
//         0045cf64     PUSH       0x4
//         0045cf66     PUSH       EAX
//         0045cf67     PUSH       ESI
//         0045cf68     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0045cf6d     ADD        ESP,0xc
//                              move_obj.cpp:332 (18)
//         0045cf70     LEA        this,[EDI + 0x144]
//         0045cf76     PUSH       0x4
//         0045cf78     PUSH       this
//         0045cf79     PUSH       ESI
//         0045cf7a     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0045cf7f     ADD        ESP,0xc
//                              move_obj.cpp:333 (18)
//         0045cf82     LEA        EDX,[EDI + 0x148]
//         0045cf88     PUSH       0x4
//         0045cf8a     PUSH       EDX
//         0045cf8b     PUSH       ESI
//         0045cf8c     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0045cf91     ADD        ESP,0xc
//                              move_obj.cpp:334 (18)
//         0045cf94     LEA        EAX,[EDI + 0x155]
//         0045cf9a     PUSH       0x1
//         0045cf9c     PUSH       EAX
//         0045cf9d     PUSH       ESI
//         0045cf9e     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0045cfa3     ADD        ESP,0xc
//                              move_obj.cpp:335 (18)
//         0045cfa6     LEA        this,[EDI + 0x156]
//         0045cfac     PUSH       0x1
//         0045cfae     PUSH       this
//         0045cfaf     PUSH       ESI
//         0045cfb0     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0045cfb5     ADD        ESP,0xc
//                              move_obj.cpp:338 (18)
//         0045cfb8     LEA        EBP,[EDI + 0x16c]
//         0045cfbe     PUSH       0x4
//         0045cfc0     PUSH       EBP
//         0045cfc1     PUSH       ESI
//         0045cfc2     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0045cfc7     ADD        ESP,0xc
//                              move_obj.cpp:339 (15)
//         0045cfca     LEA        EDX,[EDI + 0x170]
//         0045cfd0     PUSH       0x4
//         0045cfd2     PUSH       EDX
//         0045cfd3     PUSH       ESI
//         0045cfd4     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//                              move_obj.cpp:340 (12)
//         0045cfd9     MOV        EAX,dword ptr [EBP]
//         0045cfdc     ADD        ESP,0xc
//         0045cfdf     XOR        EBX,EBX
//         0045cfe1     TEST       EAX,EAX
//         0045cfe3     JLE        LAB_0045d00b
//                              move_obj.cpp:322 (2)
//         0045cfe5     XOR        EBP,EBP
//                               LAB_0045cfe7                                                 XREF[1]:     0045d009(j)
//                              move_obj.cpp:341 (36)
//         0045cfe7     MOV        this,dword ptr [EDI + 0x168]
//         0045cfed     MOV        EAX,EBP
//         0045cfef     ADD        EAX,this
//         0045cff1     PUSH       0x3
//         0045cff3     PUSH       EAX
//         0045cff4     PUSH       ESI
//         0045cff5     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0045cffa     MOV        EAX,dword ptr [EDI + 0x16c]
//         0045d000     ADD        ESP,0xc
//         0045d003     INC        EBX
//         0045d004     ADD        EBP,0x3
//         0045d007     CMP        EBX,EAX
//         0045d009     JL         LAB_0045cfe7
//                               LAB_0045d00b                                                 XREF[1]:     0045cfe3(j)
//                              move_obj.cpp:342 (18)
//         0045d00b     LEA        this,[EDI + 0x174]
//         0045d011     PUSH       0x1
//         0045d013     PUSH       this
//         0045d014     PUSH       ESI
//         0045d015     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0045d01a     ADD        ESP,0xc
//                              move_obj.cpp:343 (18)
//         0045d01d     LEA        EDX,[EDI + 0x158]
//         0045d023     PUSH       0x8
//         0045d025     PUSH       EDX
//         0045d026     PUSH       ESI
//         0045d027     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0045d02c     ADD        ESP,0xc
//                              move_obj.cpp:344 (18)
//         0045d02f     LEA        EAX,[EDI + 0x160]
//         0045d035     PUSH       0x8
//         0045d037     PUSH       EAX
//         0045d038     PUSH       ESI
//         0045d039     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0045d03e     ADD        ESP,0xc
//                              move_obj.cpp:346 (18)
//         0045d041     LEA        this,[EDI + 0x178]
//         0045d047     PUSH       0x4
//         0045d049     PUSH       this
//         0045d04a     PUSH       ESI
//         0045d04b     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0045d050     ADD        ESP,0xc
//                              move_obj.cpp:347 (18)
//         0045d053     LEA        EDX,[EDI + 0x17c]
//         0045d059     PUSH       0x1
//         0045d05b     PUSH       EDX
//         0045d05c     PUSH       ESI
//         0045d05d     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0045d062     ADD        ESP,0xc
//                              move_obj.cpp:348 (18)
//         0045d065     ADD        EDI,0x17d
//         0045d06b     PUSH       0x1
//         0045d06d     PUSH       EDI
//         0045d06e     PUSH       ESI
//         0045d06f     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0045d074     ADD        ESP,0xc
//                              move_obj.cpp:349 (8)
//         0045d077     POP        EDI
//         0045d078     POP        ESI
//         0045d079     POP        EBP
//         0045d07a     POP        EBX
//         0045d07b     POP        this
//         0045d07c     RET        0x4
//         0045d07f     ??         90h
    return;
}

void RGE_Moving_Object::new_sprite(RGE_Sprite* param_1) {
    /* TODO: Stub */
//                              void __thiscall new_sprite(RGE_Moving_Object * this, RGE_Sprite * pa
//              void              <VOID>         <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//              RGE_Sprite *      Stack[0x4]:4   param_1                   XREF[1]:     0045d080(R)
//                               ?new_sprite@RGE_Moving_Object@@UAEXPAVRGE_Sprite@@@Z         XREF[6]:     0056e458(*), 0056f290(*),
//                               RGE_Moving_Object::new_sprite                                             00570728(*), 00570980(*),
//                                                                                                         005747b0(*), 00574a58(*)
//                              move_obj.cpp:353 (11)
//         0045d080     MOV        EAX,dword ptr [ESP + param_1]
//         0045d084     PUSH       ESI
//         0045d085     TEST       EAX,EAX
//         0045d087     MOV        ESI,this
//         0045d089     JNZ        LAB_0045d091
//                              move_obj.cpp:365 (6)
//         0045d08b     MOV        EAX,dword ptr [ESI + 0x8]
//         0045d08e     MOV        EAX,dword ptr [EAX + 0x18]
//                               LAB_0045d091                                                 XREF[1]:     0045d089(j)
//                              move_obj.cpp:371 (7)
//         0045d091     MOV        this,dword ptr [ESI + 0x10]
//         0045d094     CMP        this,EAX
//         0045d096     JZ         LAB_0045d0aa
//                              move_obj.cpp:382 (3)
//         0045d098     MOV        dword ptr [ESI + 0x14],this
//                              move_obj.cpp:384 (8)
//         0045d09b     PUSH       EAX
//         0045d09c     MOV        this,ESI
//         0045d09e     CALL       RGE_Static_Object::new_sprite                    void new_sprite(RGE_Static_Object * this, RGE
//                              move_obj.cpp:385 (7)
//         0045d0a3     MOV        this,ESI
//         0045d0a5     CALL       RGE_Moving_Object::set_angle                     void set_angle(RGE_Moving_Object * this)
//                               LAB_0045d0aa                                                 XREF[1]:     0045d096(j)
//                              move_obj.cpp:386 (4)
//         0045d0aa     POP        ESI
//         0045d0ab     RET        0x4
//         0045d0ae     ??         90h
//         0045d0af     NOP
    return;
}

RGE_Static_Object* RGE_Moving_Object::spawn_death_obj() {
    /* TODO: Stub */
//                              RGE_Static_Object * __thiscall spawn_death_obj(RGE_Moving_Object * t
//              RGE_Static_Obj    EAX:4          <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//                               ?spawn_death_obj@RGE_Moving_Object@@UAEPAVRGE_Static_Object  XREF[6]:     0056e4d8(*), 0056f310(*),
//                               RGE_Moving_Object::spawn_death_obj                                        005707a8(*), 00570a00(*),
//                                                                                                         00574830(*), 00574ad8(*)
//                              move_obj.cpp:390 (4)
//         0045d0b0     PUSH       ESI
//         0045d0b1     PUSH       EDI
//         0045d0b2     MOV        EDI,this
//                              move_obj.cpp:393 (7)
//         0045d0b4     CALL       RGE_Static_Object::spawn_death_obj               RGE_Static_Object * spawn_death_obj(RGE_Stati
//         0045d0b9     MOV        ESI,EAX
//                              move_obj.cpp:395 (4)
//         0045d0bb     TEST       ESI,ESI
//         0045d0bd     JZ         LAB_0045d0d9
//                              move_obj.cpp:397 (9)
//         0045d0bf     MOV        EAX,dword ptr [ESI + 0x8]
//         0045d0c2     CMP        byte ptr [EAX + 0x4],0x1e
//         0045d0c6     JC         LAB_0045d0d9
//                              move_obj.cpp:398 (17)
//         0045d0c8     MOV        EAX,dword ptr [EDI + 0x9c]
//         0045d0ce     MOV        EDX,dword ptr [ESI]
//         0045d0d0     PUSH       EAX
//         0045d0d1     MOV        this,ESI
//         0045d0d3     CALL       dword ptr [EDX + 0xb4]
//                               LAB_0045d0d9                                                 XREF[2]:     0045d0bd(j), 0045d0c6(j)
//                              move_obj.cpp:400 (2)
//         0045d0d9     MOV        EAX,ESI
//                              move_obj.cpp:401 (3)
//         0045d0db     POP        EDI
//         0045d0dc     POP        ESI
//         0045d0dd     RET
//         0045d0de     ??         90h
//         0045d0df     NOP
    return 0;
}

void RGE_Moving_Object::transform(RGE_Master_Static_Object* param_1) {
    /* TODO: Stub */
//                              void __thiscall transform(RGE_Moving_Object * this, RGE_Master_Stati
//              void              <VOID>         <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//              RGE_Master_Sta    Stack[0x4]:4   param_1                   XREF[1]:     0045d0e0(R)
//                               ?transform@RGE_Moving_Object@@UAEXPAVRGE_Master_Static_Obje  XREF[2]:     transform:00406278(c),
//                               RGE_Moving_Object::transform                                              0057099c(*)
//                              move_obj.cpp:405 (13)
//         0045d0e0     MOV        EAX,dword ptr [ESP + param_1]
//         0045d0e4     PUSH       ESI
//         0045d0e5     MOV        ESI,this
//         0045d0e7     PUSH       EAX
//         0045d0e8     CALL       RGE_Animated_Object::transform                   void transform(RGE_Animated_Object * this, RG
//                              move_obj.cpp:408 (2)
//         0045d0ed     XOR        EAX,EAX
//                              move_obj.cpp:418 (43)
//         0045d0ef     MOV        this,ESI
//         0045d0f1     MOV        dword ptr [ESI + 0x90],EAX
//         0045d0f7     MOV        dword ptr [ESI + 0x94],EAX
//         0045d0fd     MOV        dword ptr [ESI + 0x98],EAX
//         0045d103     MOV        dword ptr [ESI + 0x130],EAX
//         0045d109     MOV        dword ptr [ESI + 0x12c],EAX
//         0045d10f     MOV        dword ptr [ESI + 0xa0],EAX
//         0045d115     CALL       RGE_Moving_Object::set_angle                     void set_angle(RGE_Moving_Object * this)
//                              move_obj.cpp:419 (4)
//         0045d11a     POP        ESI
//         0045d11b     RET        0x4
//         0045d11e     ??         90h
//         0045d11f     NOP
    return;
}

uchar RGE_Moving_Object::is_moving() {
    /* TODO: Stub */
//                              uchar __thiscall is_moving(RGE_Moving_Object * this)
//              uchar             AL:1           <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//                               ?is_moving@RGE_Moving_Object@@UAEEXZ                         XREF[6]:     0056e4e8(*), 0056f320(*),
//                               RGE_Moving_Object::is_moving                                              005707b8(*), 00570a10(*),
//                                                                                                         00574840(*), 00574ae8(*)
//                              move_obj.cpp:422 (19)
//         0045d120     FLD        float ptr [ECX + this->_padding_]
//         0045d126     FCOMP      float ptr [DAT_00570b48]
//         0045d12c     FNSTSW     AX
//         0045d12e     TEST       AH,0x41
//         0045d131     JNZ        LAB_0045d136
//                              move_obj.cpp:424 (2)
//         0045d133     MOV        AL,0x1
//                              move_obj.cpp:427 (1)
//         0045d135     RET
//                               LAB_0045d136                                                 XREF[1]:     0045d131(j)
//                              move_obj.cpp:426 (2)
//         0045d136     XOR        AL,AL
//                              move_obj.cpp:427 (1)
//         0045d138     RET
//         0045d139     ??         90h
//         0045d13a     NOP
//         0045d13b     NOP
//         0045d13c     NOP
//         0045d13d     NOP
//         0045d13e     NOP
//         0045d13f     NOP
    return 0;
}

void RGE_Moving_Object::stop_moving() {
    /* TODO: Stub */
//                              void __thiscall stop_moving(RGE_Moving_Object * this)
//              void              <VOID>         <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//                               ?stop_moving@RGE_Moving_Object@@UAEXXZ                       XREF[6]:     0056e60c(*), 0056f444(*),
//                               RGE_Moving_Object::stop_moving                                            005708dc(*), 00570b34(*),
//                                                                                                         00574964(*), 00574c0c(*)
//                              move_obj.cpp:430 (10)
//         0045d140     MOV        dword ptr [ECX + this->_padding_],0x0
//                              move_obj.cpp:432 (1)
//         0045d14a     RET
//         0045d14b     ??         90h
//         0045d14c     NOP
//         0045d14d     NOP
//         0045d14e     NOP
//         0045d14f     NOP
    return;
}

float RGE_Moving_Object::angle_to_object(RGE_Static_Object* param_1, float param_2, float param_3) {
    /* TODO: Stub */
//                              float __thiscall angle_to_object(RGE_Moving_Object * this, RGE_Stati
//              float             ST0:10         <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[3]:     0045d16e(R), 0045d1d4(W), 0045d1d8(R)
//              float             Stack[0x8]:4   param_2                   XREF[1]:     0045d182(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     0045d17e(R)
//                               ?angle_to_object@RGE_Moving_Object@@QAEMPAVRGE_Static_Objec  XREF[2]:     turn_towards:0045d208(c),
//                               RGE_Moving_Object::angle_to_object                                        turn_towards:0045d31d(c)
//                              move_obj.cpp:436 (30)
//         0045d150     MOV        EAX,dword ptr [ECX + this->_padding_]
//         0045d153     TEST       EAX,EAX
//         0045d155     JZ         LAB_0045d1e7
//         0045d15b     TEST       byte ptr [EAX + 0x70],0x2
//         0045d15f     JZ         LAB_0045d1e7
//         0045d165     MOV        DX,word ptr [EAX + 0x60]
//         0045d169     TEST       DX,DX
//         0045d16c     JLE        LAB_0045d1e7
//                              move_obj.cpp:446 (8)
//         0045d16e     MOV        EAX,dword ptr [ESP + param_1]
//         0045d172     TEST       EAX,EAX
//         0045d174     JZ         LAB_0045d17e
//                              move_obj.cpp:449 (6)
//         0045d176     FLD        float ptr [EAX + 0x3c]
//         0045d179     FLD        float ptr [EAX + 0x38]
//                              move_obj.cpp:451 (2)
//         0045d17c     JMP        LAB_0045d186
//                               LAB_0045d17e                                                 XREF[1]:     0045d174(j)
//                              move_obj.cpp:454 (16)
//         0045d17e     FLD        float ptr [ESP + param_3]
//         0045d182     FLD        float ptr [ESP + param_2]
//                               LAB_0045d186                                                 XREF[1]:     0045d17c(j)
//         0045d186     FSUB       float ptr [ECX + this->_padding_]
//         0045d189     FXCH
//         0045d18b     FSUB       float ptr [ECX + this->_padding_]
//                              move_obj.cpp:457 (4)
//         0045d18e     FXCH
//         0045d190     FPATAN
//                              move_obj.cpp:458 (13)
//         0045d192     FCOM       float ptr [DAT_00570b48]
//         0045d198     FNSTSW     AX
//         0045d19a     TEST       AH,0x1
//         0045d19d     JZ         LAB_0045d1a5
//                              move_obj.cpp:459 (6)
//         0045d19f     FSUB       float ptr [DAT_00570b4c]                         = DBh
//                               LAB_0045d1a5                                                 XREF[1]:     0045d19d(j)
//                              move_obj.cpp:461 (6)
//         0045d1a5     FSUB       float ptr [ECX + this->angle]
//                              move_obj.cpp:462 (19)
//         0045d1ab     FCOM       double ptr [DAT_00570b68]                        = F1h
//         0045d1b1     FNSTSW     AX
//         0045d1b3     TEST       AH,0x41
//         0045d1b6     JNZ        LAB_0045d1be
//         0045d1b8     FSUB       float ptr [DAT_00570b50]                         = DBh
//                               LAB_0045d1be                                                 XREF[1]:     0045d1b6(j)
//                              move_obj.cpp:463 (19)
//         0045d1be     FCOM       double ptr [DAT_00570b70]                        = F1h
//         0045d1c4     FNSTSW     AX
//         0045d1c6     TEST       AH,0x1
//         0045d1c9     JZ         LAB_0045d1d1
//         0045d1cb     FSUB       float ptr [DAT_00570b4c]                         = DBh
//                               LAB_0045d1d1                                                 XREF[1]:     0045d1c9(j)
//                              move_obj.cpp:467 (19)
//         0045d1d1     MOVSX      EAX,DX
//         0045d1d4     MOV        dword ptr [ESP + param_1],EAX
//         0045d1d8     FILD       dword ptr [ESP + param_1]
//         0045d1dc     FMUL       float ptr [DAT_00570b78]                         = 83h
//         0045d1e2     FMULP
//                              move_obj.cpp:470 (3)
//         0045d1e4     RET        0xc
//                               LAB_0045d1e7                                                 XREF[3]:     0045d155(j), 0045d15f(j),
//                                                                                                         0045d16c(j)
//                              move_obj.cpp:469 (6)
//         0045d1e7     FLD        float ptr [DAT_00570b48]
//                              move_obj.cpp:470 (3)
//         0045d1ed     RET        0xc
    return 0;
}

uchar RGE_Moving_Object::turn_towards(RGE_Static_Object* param_1, float param_2, float param_3) {
    /* TODO: Stub */
//                              uchar __thiscall turn_towards(RGE_Moving_Object * this, RGE_Static_O
//              uchar             AL:1           <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     0045d1f9(R)
//              float             Stack[0x8]:4   param_2                   XREF[3]:     0045d1f4(R), 0045d25d(W), 0045d30e(R)
//              float             Stack[0xc]:4   param_3                   XREF[8]:     0045d1ff(R), 0045d20d(W), 0045d21e(R), 0045d278(R),
//                                                                                     0045d290(W), 0045d294(R), 0045d2ad(W), 0045d2b1(R)
//              undefined8        Stack[-0x8]:8  local_8                   XREF[2,1]:   0045d24f(W), 0045d253(R), 0045d23e(W)
//                               ?turn_towards@RGE_Moving_Object@@UAEEPAVRGE_Static_Object@@  XREF[6]:     0056e610(*), 0056f448(*),
//                               RGE_Moving_Object::turn_towards                                           005708e0(*), 00570b38(*),
//                                                                                                         00574968(*), 00574c10(*)
//                              move_obj.cpp:475 (4)
//         0045d1f0     SUB        ESP,0x8
//         0045d1f3     PUSH       EBX
//                              move_obj.cpp:480 (29)
//         0045d1f4     MOV        EBX,dword ptr [ESP + param_2]
//         0045d1f8     PUSH       EBP
//         0045d1f9     MOV        EBP,dword ptr [ESP + param_1]
//         0045d1fd     PUSH       ESI
//         0045d1fe     PUSH       EDI
//         0045d1ff     MOV        EDI,dword ptr [ESP + param_3]
//         0045d203     MOV        ESI,this
//         0045d205     PUSH       EDI
//         0045d206     PUSH       EBX
//         0045d207     PUSH       EBP
//         0045d208     CALL       RGE_Moving_Object::angle_to_object               float angle_to_object(RGE_Moving_Object * thi
//         0045d20d     FST        float ptr [ESP + param_3]
//                              move_obj.cpp:481 (30)
//         0045d211     FCOMP      float ptr [DAT_00570b7c]
//         0045d217     FNSTSW     AX
//         0045d219     TEST       AH,0x41
//         0045d21c     JZ         LAB_0045d23b
//         0045d21e     FLD        float ptr [ESP + param_3]
//         0045d222     FCOMP      float ptr [DAT_00570b80]
//         0045d228     FNSTSW     AX
//         0045d22a     TEST       AH,0x1
//         0045d22d     JNZ        LAB_0045d23b
//                              move_obj.cpp:482 (2)
//         0045d22f     MOV        AL,0x1
//                              move_obj.cpp:505 (10)
//         0045d231     POP        EDI
//         0045d232     POP        ESI
//         0045d233     POP        EBP
//         0045d234     POP        EBX
//         0045d235     ADD        ESP,0x8
//         0045d238     RET        0xc
//                               LAB_0045d23b                                                 XREF[2]:     0045d21c(j), 0045d22d(j)
//                              move_obj.cpp:484 (14)
//         0045d23b     MOV        EAX,dword ptr [ESI + 0xc]
//         0045d23e     MOV        dword ptr [ESP + local_8+0x4],0x0
//         0045d246     MOV        this,dword ptr [EAX + 0x3c]
//                              move_obj.cpp:487 (41)
//         0045d249     MOV        EAX,dword ptr [ESI + 0x8]
//         0045d24c     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0045d24f     MOV        dword ptr [ESP + local_8],EDX
//         0045d253     FILD       qword ptr [ESP + local_8]
//         0045d257     FMUL       float ptr [DAT_00570b84]                         = 6Fh    o
//         0045d25d     FST        float ptr [ESP + param_2]
//         0045d261     FSUB       float ptr [ESI + 0xa0]
//         0045d267     FCOMP      float ptr [EAX + 0xc4]
//         0045d26d     FNSTSW     AX
//         0045d26f     TEST       AH,0x1
//                              move_obj.cpp:488 (6)
//         0045d272     JNZ        LAB_0045d34a
//                              move_obj.cpp:490 (17)
//         0045d278     FLD        float ptr [ESP + param_3]
//         0045d27c     FCOMP      float ptr [DAT_00570b48]
//         0045d282     FNSTSW     AX
//         0045d284     TEST       AH,0x1
//         0045d287     JZ         LAB_0045d2a6
//                              move_obj.cpp:491 (27)
//         0045d289     MOV        this,dword ptr [ESI + 0x10]
//         0045d28c     MOVSX      EDX,word ptr [ECX + this->_padding_]
//         0045d290     MOV        dword ptr [ESP + param_3],EDX
//         0045d294     FILD       dword ptr [ESP + param_3]
//         0045d298     FDIVR      double ptr [DAT_00570b40]                        = F1h
//         0045d29e     FSUBR      float ptr [ESI + 0x9c]
//                              move_obj.cpp:492 (2)
//         0045d2a4     JMP        LAB_0045d2c1
//                               LAB_0045d2a6                                                 XREF[1]:     0045d287(j)
//                              move_obj.cpp:493 (33)
//         0045d2a6     MOV        EAX,dword ptr [ESI + 0x10]
//         0045d2a9     MOVSX      this,word ptr [EAX + 0x60]
//         0045d2ad     MOV        dword ptr [ESP + param_3],this
//         0045d2b1     FILD       dword ptr [ESP + param_3]
//         0045d2b5     FDIVR      double ptr [DAT_00570b40]                        = F1h
//         0045d2bb     FADD       float ptr [ESI + 0x9c]
//                               LAB_0045d2c1                                                 XREF[1]:     0045d2a4(j)
//         0045d2c1     FSTP       float ptr [ESI + 0x9c]
//                              move_obj.cpp:494 (64)
//         0045d2c7     FLD        float ptr [ESI + 0x9c]
//         0045d2cd     FCOMP      float ptr [DAT_00570b48]
//         0045d2d3     FLD        float ptr [ESI + 0x9c]
//         0045d2d9     FNSTSW     AX
//         0045d2db     TEST       AH,0x1
//         0045d2de     JZ         LAB_0045d2e8
//         0045d2e0     FSUB       float ptr [DAT_00570b4c]                         = DBh
//         0045d2e6     JMP        LAB_0045d301
//                               LAB_0045d2e8                                                 XREF[1]:     0045d2de(j)
//         0045d2e8     FCOMP      float ptr [DAT_00570b50]                         = DBh
//         0045d2ee     FNSTSW     AX
//         0045d2f0     TEST       AH,0x41
//         0045d2f3     JNZ        LAB_0045d307
//         0045d2f5     FLD        float ptr [ESI + 0x9c]
//         0045d2fb     FSUB       float ptr [DAT_00570b50]                         = DBh
//                               LAB_0045d301                                                 XREF[1]:     0045d2e6(j)
//         0045d301     FSTP       float ptr [ESI + 0x9c]
//                               LAB_0045d307                                                 XREF[1]:     0045d2f3(j)
//                              move_obj.cpp:495 (7)
//         0045d307     MOV        this,ESI
//         0045d309     CALL       RGE_Moving_Object::set_angle                     void set_angle(RGE_Moving_Object * this)
//                              move_obj.cpp:497 (4)
//         0045d30e     MOV        EDX,dword ptr [ESP + param_2]
//                              move_obj.cpp:500 (16)
//         0045d312     PUSH       EDI
//         0045d313     PUSH       EBX
//         0045d314     PUSH       EBP
//         0045d315     MOV        this,ESI
//         0045d317     MOV        dword ptr [ESI + 0xa0],EDX
//         0045d31d     CALL       RGE_Moving_Object::angle_to_object               float angle_to_object(RGE_Moving_Object * thi
//                              move_obj.cpp:501 (26)
//         0045d322     FCOM       float ptr [DAT_00570b7c]
//         0045d328     FNSTSW     AX
//         0045d32a     TEST       AH,0x41
//         0045d32d     JZ         LAB_0045d348
//         0045d32f     FCOMP      float ptr [DAT_00570b80]
//         0045d335     FNSTSW     AX
//         0045d337     TEST       AH,0x1
//         0045d33a     JNZ        LAB_0045d34a
//                              move_obj.cpp:502 (2)
//         0045d33c     MOV        AL,0x1
//                              move_obj.cpp:505 (10)
//         0045d33e     POP        EDI
//         0045d33f     POP        ESI
//         0045d340     POP        EBP
//         0045d341     POP        EBX
//         0045d342     ADD        ESP,0x8
//         0045d345     RET        0xc
//                               LAB_0045d348                                                 XREF[1]:     0045d32d(j)
//                              move_obj.cpp:501 (2)
//         0045d348     FSTP       ST0
//                               LAB_0045d34a                                                 XREF[2]:     0045d272(j), 0045d33a(j)
//                              move_obj.cpp:505 (12)
//         0045d34a     POP        EDI
//         0045d34b     POP        ESI
//         0045d34c     POP        EBP
//         0045d34d     XOR        AL,AL
//         0045d34f     POP        EBX
//         0045d350     ADD        ESP,0x8
//         0045d353     RET        0xc
//         0045d356     ??         90h
//         0045d357     NOP
//         0045d358     NOP
//         0045d359     NOP
//         0045d35a     NOP
//         0045d35b     NOP
//         0045d35c     NOP
//         0045d35d     NOP
//         0045d35e     NOP
//         0045d35f     NOP
    return 0;
}

void RGE_Moving_Object::set_angle() {
    /* TODO: Stub */
//                              void __thiscall set_angle(RGE_Moving_Object * this)
//              void              <VOID>         <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[5]:     0045d389(W), 0045d38d(R), 0045d391(W), 0045d395(R),
//                                                                                     0045d3b2(R)
//                               ?set_angle@RGE_Moving_Object@@QAEXXZ                         XREF[11]:    recycle_in_to_game:0045c94e(c),
//                               RGE_Moving_Object::set_angle                                              setup:0045ca47(c),
//                                                                                                         setup:0045ca71(c),
//                                                                                                         setup:0045ca84(c),
//                                                                                                         new_sprite:0045d0a5(c),
//                                                                                                         transform:0045d115(c),
//                                                                                                         turn_towards:0045d309(c),
//                                                                                                         new_angle:0045d5fa(c),
//                                                                                                         doTrivialMove:0045ec2a(c),
//                                                                                                         doTrivialMove:0045f421(c),
//                                                                                                         connect:004c90cd(c)
//                              move_obj.cpp:510 (4)
//         0045d360     PUSH       this
//         0045d361     PUSH       ESI
//         0045d362     MOV        ESI,this
//                              move_obj.cpp:513 (22)
//         0045d364     MOV        EAX,dword ptr [ESI + 0x10]
//         0045d367     TEST       EAX,EAX
//         0045d369     JZ         LAB_0045d3c1
//         0045d36b     TEST       byte ptr [EAX + 0x70],0x2
//         0045d36f     JZ         LAB_0045d3c1
//         0045d371     MOV        AX,word ptr [EAX + 0x60]
//         0045d375     TEST       AX,AX
//         0045d378     JLE        LAB_0045d3c1
//                              move_obj.cpp:516 (43)
//         0045d37a     FLD        float ptr [ESI + 0x9c]
//         0045d380     FSUB       float ptr [DAT_00570b88]                         = DBh
//         0045d386     MOVSX      EAX,AX
//         0045d389     MOV        dword ptr [ESP + local_4],EAX
//         0045d38d     FILD       dword ptr [ESP + local_4]
//         0045d391     FSTP       float ptr [ESP + local_4]
//         0045d395     FMUL       float ptr [ESP + local_4]
//         0045d399     FMUL       float ptr [DAT_00570b78]                         = 83h
//         0045d39f     FSUB       float ptr [DAT_00570b80]
//                              move_obj.cpp:517 (13)
//         0045d3a5     FCOM       float ptr [DAT_00570b48]
//         0045d3ab     FNSTSW     AX
//         0045d3ad     TEST       AH,0x1
//         0045d3b0     JZ         LAB_0045d3b6
//                              move_obj.cpp:518 (4)
//         0045d3b2     FADD       float ptr [ESP + local_4]
//                               LAB_0045d3b6                                                 XREF[1]:     0045d3b0(j)
//                              move_obj.cpp:519 (8)
//         0045d3b6     CALL       __ftol                                           undefined __ftol()
//         0045d3bb     MOV        byte ptr [ESI + 0x35],AL
//                              move_obj.cpp:523 (3)
//         0045d3be     POP        ESI
//         0045d3bf     POP        this
//         0045d3c0     RET
//                               LAB_0045d3c1                                                 XREF[3]:     0045d369(j), 0045d36f(j),
//                                                                                                         0045d378(j)
//                              move_obj.cpp:522 (4)
//         0045d3c1     MOV        byte ptr [ESI + 0x35],0x0
//                              move_obj.cpp:523 (3)
//         0045d3c5     POP        ESI
//         0045d3c6     POP        this
//         0045d3c7     RET
//         0045d3c8     ??         90h
//         0045d3c9     NOP
//         0045d3ca     NOP
//         0045d3cb     NOP
//         0045d3cc     NOP
//         0045d3cd     NOP
//         0045d3ce     NOP
//         0045d3cf     NOP
    return;
}

float RGE_Moving_Object::teleport(float param_1, float param_2, float param_3) {
    /* TODO: Stub */
//                              float __thiscall teleport(RGE_Moving_Object * this, float param_1, f
//              float             ST0:10         <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1                   XREF[2]:     0045d425(R), 0045d5a3(R)
//              float             Stack[0x8]:4   param_2                   XREF[2]:     0045d421(R), 0045d59f(R)
//              float             Stack[0xc]:4   param_3                   XREF[2]:     0045d431(R), 0045d59b(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0045d4bb(W)
//              float             Stack[-0x8]:4  dy                        XREF[1]:     0045d4b5(W)
//              float             Stack[-0xc]:4  dx                        XREF[3]:     0045d47d(W), 0045d484(R), 0045d4c7(W)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[3]:     0045d45e(W), 0045d54a(R), 0045d55a(R)
//              float             Stack[-0x14]:4 d                         XREF[2]:     0045d4a5(W), 0045d4d3(R)
//              float             Stack[-0x18]:4 tz                        XREF[2]:     0045d48e(W), 0045d4d7(R)
//              float             Stack[-0x1c]:4 ty                        XREF[2]:     0045d49e(W), 0045d4db(R)
//              float             Stack[-0x20]:4 tx                        XREF[5]:     0045d492(W), 0045d498(R), 0045d4a9(R), 0045d4af(R),
//                                                                                     0045d546(R)
//              undefined4        Stack[-0x24]:4 local_24                  XREF[5]:     0045d442(W), 0045d448(R), 0045d44c(R), 0045d476(R),
//                                                                                     0045d4bf(W)
//              float             Stack[-0x28]:4 dz
//                               ?teleport@RGE_Moving_Object@@UAEMMMM@Z                       XREF[3]:     teleport:004316cb(c), 0056e454(*),
//                               RGE_Moving_Object::teleport                                               0057097c(*)
//                              move_obj.cpp:527 (9)
//         0045d3d0     SUB        ESP,0x24
//         0045d3d3     PUSH       EBX
//         0045d3d4     PUSH       EBP
//         0045d3d5     PUSH       ESI
//         0045d3d6     MOV        ESI,this
//         0045d3d8     PUSH       EDI
//                              move_obj.cpp:541 (28)
//         0045d3d9     MOV        EAX,dword ptr [ESI + 0x8]
//         0045d3dc     MOV        DL,byte ptr [EAX + 0xcc]
//         0045d3e2     TEST       DL,DL
//         0045d3e4     JZ         LAB_0045d59b
//         0045d3ea     MOV        this,dword ptr [ESI + 0x1c]
//         0045d3ed     TEST       this,this
//         0045d3ef     JZ         LAB_0045d59b
//                              move_obj.cpp:543 (16)
//         0045d3f5     MOV        this,dword ptr [ESI + 0xc]
//         0045d3f8     MOVSX      EDI,word ptr [EAX + 0xca]
//         0045d3ff     MOV        EBX,dword ptr [ECX + this->_padding_]
//         0045d402     MOV        EDI,dword ptr [EBX + EDI*0x4]
//                              move_obj.cpp:544 (8)
//         0045d405     TEST       EDI,EDI
//         0045d407     JZ         LAB_0045d59b
//                              move_obj.cpp:545 (20)
//         0045d40d     AND        EDX,0xff
//         0045d413     DEC        EDX
//         0045d414     JZ         LAB_0045d56c
//         0045d41a     DEC        EDX
//         0045d41b     JNZ        LAB_0045d59b
//                              move_obj.cpp:556 (11)
//         0045d421     FLD        float ptr [ESP + param_2]
//         0045d425     FLD        float ptr [ESP + param_1]
//         0045d429     FSUB       float ptr [ESI + 0x38]
//                              move_obj.cpp:586 (155)
//         0045d42c     FXCH
//         0045d42e     FSUB       float ptr [ESI + 0x3c]
//         0045d431     FLD        float ptr [ESP + param_3]
//         0045d435     FSUB       float ptr [ESI + 0x40]
//         0045d438     FLD        ST2
//         0045d43a     FLD        ST2
//         0045d43c     FXCH
//         0045d43e     FMUL       ST4
//         0045d440     FXCH       ST2
//         0045d442     FSTP       float ptr [ESP + local_24]
//         0045d446     FMUL       ST2
//         0045d448     FLD        float ptr [ESP + local_24]
//         0045d44c     FMUL       float ptr [ESP + local_24]
//         0045d450     FXCH
//         0045d452     FADDP      ST2,ST0
//         0045d454     FADDP
//         0045d456     FSQRT
//         0045d458     FADD       float ptr [ESI + 0x8c]
//         0045d45e     FST        float ptr [ESP + local_10]
//         0045d462     FDIV       float ptr [EAX + 0xd0]
//         0045d468     CALL       __ftol                                           undefined __ftol()
//         0045d46d     TEST       AX,AX
//         0045d470     JLE        LAB_0045d556
//         0045d476     FLD        float ptr [ESP + local_24]
//         0045d47a     MOVSX      this,AX
//         0045d47d     MOV        dword ptr [ESP + dx],this
//         0045d481     MOV        EDX,dword ptr [ESI + 0x3c]
//         0045d484     FILD       dword ptr [ESP + dx]
//         0045d488     TEST       AX,AX
//         0045d48b     MOV        EAX,dword ptr [ESI + 0x38]
//         0045d48e     MOV        dword ptr [ESP + tz],EDX
//         0045d492     FSTP       float ptr [ESP + tx]
//         0045d496     FXCH       ST2
//         0045d498     FDIV       float ptr [ESP + tx]
//         0045d49c     FXCH
//         0045d49e     MOV        dword ptr [ESP + ty],EAX
//         0045d4a2     MOV        EAX,dword ptr [ESI + 0x40]
//         0045d4a5     MOV        dword ptr [ESP + d],EAX
//         0045d4a9     FDIV       float ptr [ESP + tx]
//         0045d4ad     FXCH       ST2
//         0045d4af     FDIV       float ptr [ESP + tx]
//         0045d4b3     FXCH
//         0045d4b5     FSTP       float ptr [ESP + dy]
//         0045d4b9     FXCH
//         0045d4bb     FSTP       float ptr [ESP + local_4]
//         0045d4bf     FSTP       float ptr [ESP + local_24]
//         0045d4c3     JLE        LAB_0045d53d
//         0045d4c5     MOV        EDX,dword ptr [EDI]
//                              move_obj.cpp:587 (118)
//         0045d4c7     MOV        dword ptr [ESP + dx],this
//         0045d4cb     MOV        EBP,0x1e
//         0045d4d0     MOV        EBX,dword ptr [EDX + 0x18]
//                               LAB_0045d4d3                                                 XREF[1]:     0045d53b(j)
//         0045d4d3     MOV        EAX,dword ptr [ESP + d]
//         0045d4d7     MOV        this,dword ptr [ESP + tz]
//         0045d4db     MOV        EDX,dword ptr [ESP + ty]
//         0045d4df     PUSH       EAX
//         0045d4e0     MOV        EAX,dword ptr [ESI + 0xc]
//         0045d4e3     PUSH       this=>DAT_fffffff8
//         0045d4e4     PUSH       EDX=>DAT_fffffff4
//         0045d4e5     PUSH       EAX=>DAT_fffffff0
//         0045d4e6     MOV        this,EDI
//         0045d4e8     CALL       EBX
//         0045d4ea     MOV        this,dword ptr [EAX + 0x8]
//         0045d4ed     CMP        word ptr [ECX + this->_padding_],BP
//         0045d4f1     JLE        LAB_0045d504
//         0045d4f3     MOV        this,dword ptr [ESI + 0x9c]
//         0045d4f9     MOV        EDX,dword ptr [EAX]
//         0045d4fb     PUSH       this
//         0045d4fc     MOV        this,EAX
//         0045d4fe     CALL       dword ptr [EDX + 0xb4]
//                               LAB_0045d504                                                 XREF[1]:     0045d4f1(j)
//         0045d504     FLD        float ptr [ESP + 0x18]
//         0045d508     FLD        float ptr [ESP + 0x1c]
//         0045d50c     FLD        float ptr [ESP + 0x20]
//         0045d510     FXCH       ST2
//         0045d512     FADD       float ptr [ESP + 0x2c]
//         0045d516     FXCH
//         0045d518     FADD       float ptr [ESP + 0x30]
//         0045d51c     FXCH       ST2
//         0045d51e     FADD       float ptr [ESP + 0x10]
//         0045d522     FXCH
//         0045d524     FSTP       float ptr [ESP + 0x18]
//         0045d528     MOV        EAX,dword ptr [ESP + 0x28]
//         0045d52c     FXCH
//         0045d52e     FSTP       float ptr [ESP + 0x1c]
//         0045d532     DEC        EAX
//         0045d533     FSTP       float ptr [ESP + 0x20]
//         0045d537     MOV        dword ptr [ESP + 0x28],EAX
//         0045d53b     JNZ        LAB_0045d4d3
//                               LAB_0045d53d                                                 XREF[1]:     0045d4c3(j)
//                              move_obj.cpp:577 (23)
//         0045d53d     MOV        EDX,dword ptr [ESI + 0x8]
//         0045d540     FLD        float ptr [EDX + 0xd0]
//         0045d546     FMUL       float ptr [ESP + tx]
//         0045d54a     FSUBR      float ptr [ESP + local_10]
//         0045d54e     FSTP       float ptr [ESI + 0x8c]
//                              move_obj.cpp:579 (2)
//         0045d554     JMP        LAB_0045d59b
//                               LAB_0045d556                                                 XREF[1]:     0045d470(j)
//                              move_obj.cpp:559 (4)
//         0045d556     FSTP       ST0
//         0045d558     FSTP       ST0
//                              move_obj.cpp:580 (16)
//         0045d55a     FLD        float ptr [ESP + local_10]
//         0045d55e     FADD       float ptr [ESI + 0x8c]
//         0045d564     FSTP       float ptr [ESI + 0x8c]
//                              move_obj.cpp:581 (2)
//         0045d56a     JMP        LAB_0045d59b
//                               LAB_0045d56c                                                 XREF[1]:     0045d414(j)
//                              move_obj.cpp:549 (20)
//         0045d56c     MOV        EDX,dword ptr [ESI + 0x40]
//         0045d56f     MOV        EAX,dword ptr [EDI]
//         0045d571     PUSH       EDX
//         0045d572     MOV        EDX,dword ptr [ESI + 0x3c]
//         0045d575     PUSH       EDX
//         0045d576     MOV        EDX,dword ptr [ESI + 0x38]
//         0045d579     PUSH       EDX
//         0045d57a     PUSH       this
//         0045d57b     MOV        this,EDI
//         0045d57d     CALL       dword ptr [EAX + 0x18]
//                              move_obj.cpp:550 (10)
//         0045d580     MOV        this,dword ptr [EAX + 0x8]
//         0045d583     CMP        word ptr [ECX + this->_padding_],0x1e
//         0045d588     JLE        LAB_0045d59b
//                              move_obj.cpp:551 (17)
//         0045d58a     MOV        this,dword ptr [ESI + 0x9c]
//         0045d590     MOV        EDX,dword ptr [EAX]
//         0045d592     PUSH       this
//         0045d593     MOV        this,EAX
//         0045d595     CALL       dword ptr [EDX + 0xb4]
//                               LAB_0045d59b                                                 XREF[7]:     0045d3e4(j), 0045d3ef(j),
//                                                                                                         0045d407(j), 0045d41b(j),
//                                                                                                         0045d554(j), 0045d56a(j),
//                                                                                                         0045d588(j)
//                              move_obj.cpp:586 (22)
//         0045d59b     MOV        EDX,dword ptr [ESP + param_3]
//         0045d59f     MOV        EAX,dword ptr [ESP + param_2]
//         0045d5a3     MOV        this,dword ptr [ESP + param_1]
//         0045d5a7     PUSH       EDX
//         0045d5a8     PUSH       EAX=>DAT_fffffff8
//         0045d5a9     PUSH       this=>DAT_fffffff4
//         0045d5aa     MOV        this,ESI
//         0045d5ac     CALL       RGE_Static_Object::teleport                      float teleport(RGE_Static_Object * this, floa
//                              move_obj.cpp:587 (10)
//         0045d5b1     POP        EDI
//         0045d5b2     POP        ESI
//         0045d5b3     POP        EBP
//         0045d5b4     POP        EBX
//         0045d5b5     ADD        ESP,0x24
//         0045d5b8     RET        0xc
//         0045d5bb     ??         90h
//         0045d5bc     NOP
//         0045d5bd     NOP
//         0045d5be     NOP
//         0045d5bf     NOP
    return 0;
}

void RGE_Moving_Object::set_velocity(float param_1, float param_2, float param_3) {
    /* TODO: Stub */
//                              void __thiscall set_velocity(RGE_Moving_Object * this, float param_1
//              void              <VOID>         <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1                   XREF[1]:     0045d5c0(R)
//              float             Stack[0x8]:4   param_2                   XREF[1]:     0045d5c4(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     0045d5ce(R)
//                               ?set_velocity@RGE_Moving_Object@@QAEXMMM@Z                   XREF[1]:     update:00405286(c)
//                               RGE_Moving_Object::set_velocity
//                              move_obj.cpp:591 (4)
//         0045d5c0     MOV        EAX,dword ptr [ESP + param_1]
//                              move_obj.cpp:593 (10)
//         0045d5c4     MOV        EDX,dword ptr [ESP + param_2]
//         0045d5c8     MOV        dword ptr [ECX + this->velocity_x],EAX
//                              move_obj.cpp:594 (16)
//         0045d5ce     MOV        EAX,dword ptr [ESP + param_3]
//         0045d5d2     MOV        dword ptr [ECX + this->velocity_y],EDX
//         0045d5d8     MOV        dword ptr [ECX + this->velocity_z],EAX
//                              move_obj.cpp:595 (3)
//         0045d5de     RET        0xc
//         0045d5e1     ??         90h
//         0045d5e2     NOP
//         0045d5e3     NOP
//         0045d5e4     NOP
//         0045d5e5     NOP
//         0045d5e6     NOP
//         0045d5e7     NOP
//         0045d5e8     NOP
//         0045d5e9     NOP
//         0045d5ea     NOP
//         0045d5eb     NOP
//         0045d5ec     NOP
//         0045d5ed     NOP
//         0045d5ee     NOP
//         0045d5ef     NOP
    return;
}

void RGE_Moving_Object::new_angle(float param_1) {
    /* TODO: Stub */
//                              void __thiscall new_angle(RGE_Moving_Object * this, float param_1)
//              void              <VOID>         <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1                   XREF[1]:     0045d5f0(R)
//                               ?new_angle@RGE_Moving_Object@@UAEXM@Z                        XREF[6]:     0056e4d4(*), 0056f30c(*),
//                               RGE_Moving_Object::new_angle                                              005707a4(*), 005709fc(*),
//                                                                                                         0057482c(*), 00574ad4(*)
//                              move_obj.cpp:599 (10)
//         0045d5f0     MOV        EAX,dword ptr [ESP + param_1]
//         0045d5f4     MOV        dword ptr [ECX + this->angle],EAX
//                              move_obj.cpp:601 (5)
//         0045d5fa     CALL       RGE_Moving_Object::set_angle                     void set_angle(RGE_Moving_Object * this)
//                              move_obj.cpp:602 (3)
//         0045d5ff     RET        0x4
//         0045d602     ??         90h
//         0045d603     NOP
//         0045d604     NOP
//         0045d605     NOP
//         0045d606     NOP
//         0045d607     NOP
//         0045d608     NOP
//         0045d609     NOP
//         0045d60a     NOP
//         0045d60b     NOP
//         0045d60c     NOP
//         0045d60d     NOP
//         0045d60e     NOP
//         0045d60f     NOP
    return;
}

Path* RGE_Moving_Object::getPath() {
    /* TODO: Stub */
//                              Path * __thiscall getPath(RGE_Moving_Object * this)
//              Path *            EAX:4          <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//                               ?getPath@RGE_Moving_Object@@QBEABVPath@@XZ
//                               RGE_Moving_Object::getPath
//                              move_obj.cpp:607 (6)
//         0045d610     LEA        EAX,[ECX + this->pathValue.timeStampValue]
//                              move_obj.cpp:609 (1)
//         0045d616     RET
//         0045d617     ??         90h
//         0045d618     NOP
//         0045d619     NOP
//         0045d61a     NOP
//         0045d61b     NOP
//         0045d61c     NOP
//         0045d61d     NOP
//         0045d61e     NOP
//         0045d61f     NOP
    return 0;
}

uchar RGE_Moving_Object::facetToNextWaypoint() {
    /* TODO: Stub */
//                              uchar __thiscall facetToNextWaypoint(RGE_Moving_Object * this)
//              uchar             AL:1           <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//                               ?facetToNextWaypoint@RGE_Moving_Object@@UBEEXZ               XREF[6]:     0056e538(*), 0056f370(*),
//                               RGE_Moving_Object::facetToNextWaypoint                                    00570808(*), 00570a60(*),
//                                                                                                         00574890(*), 00574b38(*)
//                              move_obj.cpp:614 (1)
//         0045d620     PUSH       ESI
//                              move_obj.cpp:615 (17)
//         0045d621     LEA        ESI,[ECX + this->pathValue.timeStampValue]
//         0045d627     MOV        this,ESI
//         0045d629     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         0045d62e     TEST       EAX,EAX
//         0045d630     JZ         LAB_0045d63e
//                              move_obj.cpp:616 (10)
//         0045d632     MOV        this,ESI
//         0045d634     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         0045d639     MOV        AL,byte ptr [EAX + 0xc]
//                              move_obj.cpp:618 (2)
//         0045d63c     POP        ESI
//         0045d63d     RET
//                               LAB_0045d63e                                                 XREF[1]:     0045d630(j)
//                              move_obj.cpp:617 (2)
//         0045d63e     OR         AL,0xff
//                              move_obj.cpp:618 (2)
//         0045d640     POP        ESI
//         0045d641     RET
//         0045d642     ??         90h
//         0045d643     NOP
//         0045d644     NOP
//         0045d645     NOP
//         0045d646     NOP
//         0045d647     NOP
//         0045d648     NOP
//         0045d649     NOP
//         0045d64a     NOP
//         0045d64b     NOP
//         0045d64c     NOP
//         0045d64d     NOP
//         0045d64e     NOP
//         0045d64f     NOP
    return 0;
}

void RGE_Moving_Object::setGoal(float param_1, float param_2, float param_3) {
    /* TODO: Stub */
//                              void __thiscall setGoal(RGE_Moving_Object * this, float param_1, flo
//              void              <VOID>         <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1                   XREF[1]:     0045d650(R)
//              float             Stack[0x8]:4   param_2                   XREF[1]:     0045d654(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     0045d65e(R)
//                               ?setGoal@RGE_Moving_Object@@QAEXMMM@Z                        XREF[4]:     update:00405994(c),
//                               RGE_Moving_Object::setGoal                                                RGE_Moving_Object:0045c51b(c),
//                                                                                                         RGE_Moving_Object:0045c67e(c),
//                                                                                                         recycle_in_to_game:0045c81d(c)
//                              move_obj.cpp:632 (4)
//         0045d650     MOV        EAX,dword ptr [ESP + param_1]
//                              move_obj.cpp:634 (10)
//         0045d654     MOV        EDX,dword ptr [ESP + param_2]
//         0045d658     MOV        dword ptr [ECX + this->goalValue.x],EAX
//                              move_obj.cpp:635 (16)
//         0045d65e     MOV        EAX,dword ptr [ESP + param_3]
//         0045d662     MOV        dword ptr [ECX + this+0x120],EDX
//         0045d668     MOV        dword ptr [ECX + this+0x124],EAX
//                              move_obj.cpp:636 (3)
//         0045d66e     RET        0xc
//         0045d671     ??         90h
//         0045d672     NOP
//         0045d673     NOP
//         0045d674     NOP
//         0045d675     NOP
//         0045d676     NOP
//         0045d677     NOP
//         0045d678     NOP
//         0045d679     NOP
//         0045d67a     NOP
//         0045d67b     NOP
//         0045d67c     NOP
//         0045d67d     NOP
//         0045d67e     NOP
//         0045d67f     NOP
    return;
}

void RGE_Moving_Object::setActionRange(float param_1) {
    /* TODO: Stub */
//                              void __thiscall setActionRange(RGE_Moving_Object * this, float param
//              void              <VOID>         <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1                   XREF[1]:     0045d680(R)
//                               ?setActionRange@RGE_Moving_Object@@QAEXM@Z                   XREF[1]:     update:004059e8(c)
//                               RGE_Moving_Object::setActionRange
//                              move_obj.cpp:641 (10)
//         0045d680     MOV        EAX,dword ptr [ESP + param_1]
//         0045d684     MOV        dword ptr [ECX + this->actionRange],EAX
//                              move_obj.cpp:643 (3)
//         0045d68a     RET        0x4
//         0045d68d     ??         90h
//         0045d68e     NOP
//         0045d68f     NOP
    return;
}

void RGE_Moving_Object::setTargetID(int param_1) {
    /* TODO: Stub */
//                              void __thiscall setTargetID(RGE_Moving_Object * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0045d690(R)
//                               ?setTargetID@RGE_Moving_Object@@QAEXH@Z                      XREF[2]:     update:004059fb(c),
//                               RGE_Moving_Object::setTargetID                                            update:00405a15(c)
//                              move_obj.cpp:648 (10)
//         0045d690     MOV        EAX,dword ptr [ESP + param_1]
//         0045d694     MOV        dword ptr [ECX + this->targetIDValue],EAX
//                              move_obj.cpp:650 (3)
//         0045d69a     RET        0x4
//         0045d69d     ??         90h
//         0045d69e     NOP
//         0045d69f     NOP
    return;
}

void RGE_Moving_Object::setTargetRadius(float param_1, float param_2) {
    /* TODO: Stub */
//                              void __thiscall setTargetRadius(RGE_Moving_Object * this, float para
//              void              <VOID>         <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1                   XREF[1]:     0045d6a0(R)
//              float             Stack[0x8]:4   param_2                   XREF[1]:     0045d6a4(R)
//                               ?setTargetRadius@RGE_Moving_Object@@QAEXMM@Z                 XREF[1]:     update:00405a21(c)
//                               RGE_Moving_Object::setTargetRadius
//                              move_obj.cpp:655 (4)
//         0045d6a0     MOV        EAX,dword ptr [ESP + param_1]
//                              move_obj.cpp:657 (16)
//         0045d6a4     MOV        EDX,dword ptr [ESP + param_2]
//         0045d6a8     MOV        dword ptr [ECX + this->targetRadiusX],EAX
//         0045d6ae     MOV        dword ptr [ECX + this->targetRadiusY],EDX
//                              move_obj.cpp:658 (3)
//         0045d6b4     RET        0x8
//         0045d6b7     ??         90h
//         0045d6b8     NOP
//         0045d6b9     NOP
//         0045d6ba     NOP
//         0045d6bb     NOP
//         0045d6bc     NOP
//         0045d6bd     NOP
//         0045d6be     NOP
//         0045d6bf     NOP
    return;
}

PathResult RGE_Moving_Object::findPath() {
    /* TODO: Stub */
//                              PathResult __thiscall findPath(RGE_Moving_Object * this)
//              PathResult        EAX:4          <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//              undefined4        Stack[-0x18]:4 local_18                  XREF[1]:     0045d7d4(W)
//                               ?findPath@RGE_Moving_Object@@QAE?AW4PathResult@1@XZ          XREF[1]:     update:00405a29(c)
//                               RGE_Moving_Object::findPath
//                              move_obj.cpp:663 (15)
//         0045d6c0     PUSH       EBP
//         0045d6c1     MOV        EBP,ESP
//         0045d6c3     AND        ESP,0xfffffff8
//         0045d6c6     SUB        ESP,0x10
//         0045d6c9     PUSH       EBX
//         0045d6ca     PUSH       EBP
//         0045d6cb     PUSH       ESI
//         0045d6cc     MOV        ESI,this
//         0045d6ce     PUSH       EDI
//                              move_obj.cpp:674 (23)
//         0045d6cf     MOV        EAX,dword ptr [ESI + 0x8]
//         0045d6d2     FLD        float ptr [EAX + 0x38]
//         0045d6d5     FCOMP      float ptr [DAT_00570b48]
//         0045d6db     FNSTSW     AX
//         0045d6dd     TEST       AH,0x41
//         0045d6e0     JZ         LAB_0045d76b
//                              move_obj.cpp:678 (10)
//         0045d6e6     MOV        EDX,dword ptr [ESI]
//         0045d6e8     PUSH       0x0
//         0045d6ea     CALL       dword ptr [EDX + 0x12c]
//                              move_obj.cpp:679 (9)
//         0045d6f0     FLD        float ptr [ESI + 0x38]
//         0045d6f3     LEA        EBP,[ESI + 0x10c]
//                              move_obj.cpp:681 (51)
//         0045d6f9     LEA        EDI,[ESI + 0xa4]
//         0045d6ff     FSTP       float ptr [EBP]
//         0045d702     FLD        float ptr [ESI + 0x3c]
//         0045d705     FSTP       float ptr [ESI + 0x110]
//         0045d70b     FLD        float ptr [ESI + 0x40]
//         0045d70e     FSTP       float ptr [ESI + 0x114]
//         0045d714     MOV        dword ptr [ESI + 0x58],0x0
//         0045d71b     MOV        EAX,dword ptr [ESI + 0xc]
//         0045d71e     MOV        this,dword ptr [EAX + 0x3c]
//         0045d721     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0045d724     MOV        this,EDI
//         0045d726     PUSH       EDX
//         0045d727     CALL       Path::setTimeStamp                               void setTimeStamp(Path * this, ulong param_1)
//                              move_obj.cpp:683 (7)
//         0045d72c     MOV        this,EDI
//         0045d72e     CALL       Path::killPath                                   void killPath(Path * this)
//                              move_obj.cpp:684 (14)
//         0045d733     LEA        EAX,[ESI + 0x11c]
//         0045d739     MOV        this,EDI
//         0045d73b     PUSH       EAX
//         0045d73c     CALL       Path::insertAtCurrent                            int insertAtCurrent(Path * this, Waypoint * p
//                              move_obj.cpp:685 (8)
//         0045d741     PUSH       EBP
//         0045d742     MOV        this,EDI
//         0045d744     CALL       Path::insertAtCurrent                            int insertAtCurrent(Path * this, Waypoint * p
//                              move_obj.cpp:686 (7)
//         0045d749     MOV        this,EDI
//         0045d74b     CALL       Path::initToStart                                void initToStart(Path * this)
//                              move_obj.cpp:687 (7)
//         0045d750     MOV        this,EDI
//         0045d752     CALL       Path::moveToNextWaypoint                         int moveToNextWaypoint(Path * this)
//                              move_obj.cpp:688 (10)
//         0045d757     MOV        dword ptr [ESI + 0x178],0x47c35000
//                              move_obj.cpp:814 (2)
//         0045d761     XOR        EAX,EAX
//                              move_obj.cpp:815 (8)
//         0045d763     POP        EDI
//         0045d764     POP        ESI
//         0045d765     POP        EBP
//         0045d766     POP        EBX
//         0045d767     MOV        ESP,EBP
//         0045d769     POP        EBP
//         0045d76a     RET
//                               LAB_0045d76b                                                 XREF[1]:     0045d6e0(j)
//                              move_obj.cpp:693 (9)
//         0045d76b     MOV        this,`vcall'{456,{flat}}'_}'
//         0045d770     TEST       this,this
//         0045d772     JNZ        LAB_0045d78f
//                              move_obj.cpp:698 (14)
//         0045d774     MOV        EDX,dword ptr [ESI]
//         0045d776     MOV        dword ptr [ESI + 0x58],this=>`vcall'{456,{flat
//         0045d779     PUSH       this=>`vcall'{456,{flat}}'_}'
//         0045d77a     MOV        this,ESI
//         0045d77c     CALL       dword ptr [EDX + 0x12c]
//                              move_obj.cpp:699 (5)
//         0045d782     MOV        EAX,0x1
//                              move_obj.cpp:815 (8)
//         0045d787     POP        EDI
//         0045d788     POP        ESI
//         0045d789     POP        EBP
//         0045d78a     POP        EBX
//         0045d78b     MOV        ESP,EBP
//         0045d78d     POP        EBP
//         0045d78e     RET
//                               LAB_0045d78f                                                 XREF[1]:     0045d772(j)
//                              move_obj.cpp:703 (21)
//         0045d78f     MOV        this,dword ptr [ESI + 0xc]
//         0045d792     XOR        EAX,EAX
//         0045d794     MOV        AL,byte ptr [ESI + 0x156]
//         0045d79a     PUSH       EAX
//         0045d79b     CALL       RGE_Player::availablePathingAttempts             int availablePathingAttempts(RGE_Player * thi
//         0045d7a0     TEST       EAX,EAX
//         0045d7a2     JNZ        LAB_0045d7bf
//                              move_obj.cpp:707 (14)
//         0045d7a4     MOV        AL,byte ptr [ESI + 0x156]
//         0045d7aa     INC        AL
//         0045d7ac     MOV        byte ptr [ESI + 0x156],AL
//                              move_obj.cpp:708 (5)
//         0045d7b2     MOV        EAX,0x2
//                              move_obj.cpp:815 (8)
//         0045d7b7     POP        EDI
//         0045d7b8     POP        ESI
//         0045d7b9     POP        EBP
//         0045d7ba     POP        EBX
//         0045d7bb     MOV        ESP,EBP
//         0045d7bd     POP        EBP
//         0045d7be     RET
//                               LAB_0045d7bf                                                 XREF[1]:     0045d7a2(j)
//                              move_obj.cpp:714 (8)
//         0045d7bf     MOV        this,dword ptr [ESI + 0xc]
//         0045d7c2     CALL       RGE_Player::incrementPathingAttempts             void incrementPathingAttempts(RGE_Player * th
//                              move_obj.cpp:717 (23)
//         0045d7c7     MOV        EDI,dword ptr [ESI]
//         0045d7c9     PUSH       0x0
//         0045d7cb     MOV        this,ESI
//         0045d7cd     MOV        byte ptr [ESI + 0x156],0x0
//         0045d7d4     MOV        dword ptr [ESP + local_18],EDI
//         0045d7d8     CALL       dword ptr [EDI + 0x12c]
//                              move_obj.cpp:720 (12)
//         0045d7de     MOV        this,dword ptr [ESI + 0xc]
//         0045d7e1     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
//         0045d7e6     TEST       EAX,EAX
//         0045d7e8     JNZ        LAB_0045d7fb
//                              move_obj.cpp:721 (15)
//         0045d7ea     MOV        this,dword ptr [ESI + 0x16c]
//         0045d7f0     ADD        this,0x19
//         0045d7f3     MOV        dword ptr [ESI + 0x144],this
//                              move_obj.cpp:722 (2)
//         0045d7f9     JMP        LAB_0045d80a
//                               LAB_0045d7fb                                                 XREF[1]:     0045d7e8(j)
//                              move_obj.cpp:723 (15)
//         0045d7fb     MOV        EDX,dword ptr [ESI + 0x16c]
//         0045d801     ADD        EDX,0xf
//         0045d804     MOV        dword ptr [ESI + 0x144],EDX
//                               LAB_0045d80a                                                 XREF[1]:     0045d7f9(j)
//                              move_obj.cpp:726 (27)
//         0045d80a     FLD        float ptr [ESI + 0x38]
//         0045d80d     FSTP       float ptr [ESI + 0x10c]
//         0045d813     FLD        float ptr [ESI + 0x3c]
//         0045d816     FSTP       float ptr [ESI + 0x110]
//         0045d81c     FLD        float ptr [ESI + 0x40]
//         0045d81f     FSTP       float ptr [ESI + 0x114]
//                              move_obj.cpp:739 (20)
//         0045d825     MOV        this,pathSystem
//         0045d82a     MOV        dword ptr [ESI + 0x178],0x47c35000
//         0045d834     CALL       PathingSystem::incrementInitialPaths             void incrementInitialPaths(PathingSystem * th
//                              move_obj.cpp:741 (10)
//         0045d839     MOV        EAX,dword ptr [ESI + 0x16c]
//         0045d83f     TEST       EAX,EAX
//         0045d841     JLE        LAB_0045d875
//                              move_obj.cpp:745 (48)
//         0045d843     MOV        this,dword ptr [ESI + 0x138]
//         0045d849     MOV        EDX,dword ptr [ESI + 0x134]
//         0045d84f     MOV        EAX,dword ptr [ESI + 0x168]
//         0045d855     PUSH       -0x1
//         0045d857     PUSH       offset DAT_fffffff8
//         0045d859     PUSH       offset DAT_fffffff4
//         0045d85b     PUSH       offset DAT_fffffff0
//         0045d85d     PUSH       0x1
//         0045d85f     PUSH       0x1
//         0045d861     PUSH       0x0
//         0045d863     PUSH       0x1
//         0045d865     PUSH       this
//         0045d866     PUSH       EDX
//         0045d867     XOR        this,this
//         0045d869     MOV        this,byte ptr [EAX + 0x1]
//         0045d86c     XOR        EDX,EDX
//         0045d86e     MOV        DL,byte ptr [EAX]
//         0045d870     PUSH       ESI
//         0045d871     PUSH       this
//         0045d872     PUSH       EDX
//                              move_obj.cpp:746 (2)
//         0045d873     JMP        LAB_0045d8ac
//                               LAB_0045d875                                                 XREF[1]:     0045d841(j)
//                              move_obj.cpp:750 (91)
//         0045d875     MOV        EAX,dword ptr [ESI + 0x138]
//         0045d87b     MOV        this,dword ptr [ESI + 0x134]
//         0045d881     PUSH       -0x1
//         0045d883     PUSH       offset DAT_fffffff8
//         0045d885     FLD        float ptr [ESI + 0x120]
//         0045d88b     PUSH       offset DAT_fffffff4
//         0045d88d     PUSH       offset DAT_fffffff0
//         0045d88f     PUSH       0x1
//         0045d891     PUSH       0x1
//         0045d893     PUSH       0x0
//         0045d895     PUSH       0x1
//         0045d897     PUSH       EAX
//         0045d898     PUSH       this
//         0045d899     PUSH       ESI
//         0045d89a     CALL       __ftol                                           undefined __ftol()
//         0045d89f     FLD        float ptr [ESI + 0x11c]
//         0045d8a5     PUSH       EAX
//         0045d8a6     CALL       __ftol                                           undefined __ftol()
//         0045d8ab     PUSH       EAX
//                               LAB_0045d8ac                                                 XREF[1]:     0045d873(j)
//         0045d8ac     FLD        float ptr [ESI + 0x110]
//         0045d8b2     CALL       __ftol                                           undefined __ftol()
//         0045d8b7     FLD        float ptr [ESI + 0x10c]
//         0045d8bd     PUSH       EAX
//         0045d8be     CALL       __ftol                                           undefined __ftol()
//         0045d8c3     PUSH       EAX
//         0045d8c4     MOV        this,pathSystem
//         0045d8c9     CALL       PathingSystem::findTilePath                      int findTilePath(PathingSystem * this, int pa
//         0045d8ce     MOV        EBX,EAX
//                              move_obj.cpp:753 (13)
//         0045d8d0     MOV        EAX,[actionFile]                                 = 00000000
//         0045d8d5     TEST       EAX,EAX
//         0045d8d7     JZ         LAB_0045d9af
//                              move_obj.cpp:755 (73)
//         0045d8dd     FLD        float ptr [ESI + 0x120]
//         0045d8e3     SUB        ESP,0x8
//         0045d8e6     MOV        EDX,dword ptr [ESI + 0x4]
//         0045d8e9     MOV        this,dword ptr [ESI + 0xc]
//         0045d8ec     FSTP       double ptr [ESP]=>DAT_fffffff8
//         0045d8ef     FLD        float ptr [ESI + 0x11c]
//         0045d8f5     SUB        ESP,0x8
//         0045d8f8     FSTP       double ptr [ESP]=>DAT_fffffff0
//         0045d8fb     FLD        float ptr [ESI + 0x110]
//         0045d901     SUB        ESP,0x8
//         0045d904     FSTP       double ptr [ESP]
//         0045d907     FLD        float ptr [ESI + 0x10c]
//         0045d90d     SUB        ESP,0x8
//         0045d910     FSTP       double ptr [ESP]
//         0045d913     PUSH       EDX
//         0045d914     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0045d917     MOV        this,dword ptr [EDX + 0x4]
//         0045d91a     PUSH       this
//         0045d91b     PUSH       s_t%ld_uID=%d,_fP1_s=(%6.2f,%6.2f)               = "t%ld uID=%d, fP1 s=(%6.2f,%6.2f), g=(%6.2f
//         0045d920     PUSH       EAX
//         0045d921     CALL       fprintf                                          undefined fprintf()
//                              move_obj.cpp:756 (16)
//         0045d926     LEA        EDI,[ESI + 0xa4]
//         0045d92c     ADD        ESP,0x30
//         0045d92f     MOV        this,EDI
//         0045d931     CALL       Path::initToStart                                void initToStart(Path * this)
//                              move_obj.cpp:757 (13)
//         0045d936     MOV        this,EDI
//         0045d938     XOR        EBP,EBP
//         0045d93a     CALL       Path::numberOfWaypoints                          int numberOfWaypoints(Path * this)
//         0045d93f     TEST       EAX,EAX
//         0045d941     JLE        LAB_0045d98a
//                               LAB_0045d943                                                 XREF[1]:     0045d988(j)
//                              move_obj.cpp:758 (71)
//         0045d943     MOV        this,EDI
//         0045d945     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         0045d94a     FLD        float ptr [EAX + 0x4]
//         0045d94d     SUB        ESP,0x8
//         0045d950     MOV        this,EDI
//         0045d952     FSTP       double ptr [ESP]=>DAT_fffffff8
//         0045d955     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         0045d95a     FLD        float ptr [EAX]
//         0045d95c     MOV        EDX,dword ptr [actionFile]                       = 00000000
//         0045d962     SUB        ESP,0x8
//         0045d965     FSTP       double ptr [ESP]=>DAT_fffffff0
//         0045d968     PUSH       EBP
//         0045d969     PUSH       s_,_WP#%d(%6.2f,_%6.2f)                          = ", WP#%d(%6.2f, %6.2f)"
//         0045d96e     PUSH       EDX
//         0045d96f     CALL       fprintf                                          undefined fprintf()
//         0045d974     ADD        ESP,0x1c
//         0045d977     MOV        this,EDI
//         0045d979     INC        EBP
//         0045d97a     CALL       Path::moveToNextWaypoint                         int moveToNextWaypoint(Path * this)
//         0045d97f     MOV        this,EDI
//         0045d981     CALL       Path::numberOfWaypoints                          int numberOfWaypoints(Path * this)
//         0045d986     CMP        EBP,EAX
//         0045d988     JL         LAB_0045d943
//                               LAB_0045d98a                                                 XREF[1]:     0045d941(j)
//                              move_obj.cpp:759 (19)
//         0045d98a     MOV        EAX,[actionFile]                                 = 00000000
//         0045d98f     PUSH       s_._                                             = ".\n"
//         0045d994     PUSH       EAX=>DAT_fffffff8
//         0045d995     CALL       fprintf                                          undefined fprintf()
//         0045d99a     ADD        ESP,0x8
//                              move_obj.cpp:760 (7)
//         0045d99d     MOV        this,EDI
//         0045d99f     CALL       Path::initToStart                                void initToStart(Path * this)
//                              move_obj.cpp:761 (11)
//         0045d9a4     MOV        this,EDI
//         0045d9a6     CALL       Path::moveToNextWaypoint                         int moveToNextWaypoint(Path * this)
//         0045d9ab     MOV        EDI,dword ptr [ESP + 0x10]
//                               LAB_0045d9af                                                 XREF[1]:     0045d8d7(j)
//                              move_obj.cpp:786 (28)
//         0045d9af     TEST       EBX,EBX
//         0045d9b1     JNZ        LAB_0045dab9
//         0045d9b7     LEA        this,[ESI + 0xa4]
//         0045d9bd     CALL       Path::numberOfWaypoints                          int numberOfWaypoints(Path * this)
//         0045d9c2     CMP        EAX,0x1
//         0045d9c5     JNZ        LAB_0045dab9
//                              move_obj.cpp:791 (75)
//         0045d9cb     FLD        float ptr [ESI + 0x3c]
//         0045d9ce     PUSH       EAX
//         0045d9cf     SUB        ESP,0x8
//         0045d9d2     FSTP       double ptr [ESP]=>DAT_fffffff4
//         0045d9d5     CALL       floor                                            undefined floor()
//         0045d9da     FSUB       float ptr [DAT_00570b80]
//         0045d9e0     FLD        float ptr [ESI + 0x38]
//         0045d9e3     FXCH
//         0045d9e5     ADD        ESP,0x4
//         0045d9e8     FSTP       float ptr [ESP]=>DAT_fffffff8
//         0045d9eb     SUB        ESP,0x8
//         0045d9ee     FSTP       double ptr [ESP]=>DAT_fffffff0
//         0045d9f1     CALL       floor                                            undefined floor()
//         0045d9f6     FSUB       float ptr [DAT_00570b80]
//         0045d9fc     ADD        ESP,0x8
//         0045d9ff     MOV        this,pathSystem
//         0045da04     PUSH       this=>pathSystem
//         0045da05     FSTP       float ptr [ESP]=>DAT_fffffff4
//         0045da08     PUSH       ESI=>DAT_fffffff0
//         0045da09     CALL       PathingSystem::passable                          int passable(PathingSystem * this, RGE_Moving
//         0045da0e     TEST       EAX,EAX
//         0045da10     JZ         LAB_0045dab9
//                              move_obj.cpp:799 (84)
//         0045da16     FLD        float ptr [ESI + 0x38]
//         0045da19     FSTP       double ptr [ESP + 0x18]
//         0045da1d     MOV        this,dword ptr [ESP + 0x1c]
//         0045da21     MOV        EDX,dword ptr [ESP + 0x18]
//         0045da25     PUSH       this
//         0045da26     PUSH       EDX=>DAT_fffffff8
//         0045da27     CALL       floor                                            undefined floor()
//         0045da2c     FSUBR      double ptr [ESP + 0x20]
//         0045da30     ADD        ESP,0x8
//         0045da33     FCOMP      double ptr [DAT_00570b90]
//         0045da39     FNSTSW     AX
//         0045da3b     TEST       AH,0x40
//         0045da3e     JZ         LAB_0045da6a
//         0045da40     FLD        float ptr [ESI + 0x3c]
//         0045da43     FSTP       double ptr [ESP + 0x18]
//         0045da47     MOV        EAX,dword ptr [ESP + 0x1c]
//         0045da4b     MOV        this,dword ptr [ESP + 0x18]
//         0045da4f     PUSH       EAX
//         0045da50     PUSH       this=>DAT_fffffff8
//         0045da51     CALL       floor                                            undefined floor()
//         0045da56     FSUBR      double ptr [ESP + 0x20]
//         0045da5a     ADD        ESP,0x8
//         0045da5d     FCOMP      double ptr [DAT_00570b90]
//         0045da63     FNSTSW     AX
//         0045da65     TEST       AH,0x40
//         0045da68     JNZ        LAB_0045dab9
//                               LAB_0045da6a                                                 XREF[1]:     0045da3e(j)
//                              move_obj.cpp:801 (66)
//         0045da6a     MOV        EDX,dword ptr [ESI + 0x40]
//         0045da6d     FLD        float ptr [ESI + 0x3c]
//         0045da70     PUSH       EDX
//         0045da71     SUB        ESP,0x8
//         0045da74     FSTP       double ptr [ESP]=>DAT_fffffff4
//         0045da77     CALL       floor                                            undefined floor()
//         0045da7c     FSUB       float ptr [DAT_00570b80]
//         0045da82     FLD        float ptr [ESI + 0x38]
//         0045da85     FXCH
//         0045da87     ADD        ESP,0x4
//         0045da8a     FSTP       float ptr [ESP]=>DAT_fffffff8
//         0045da8d     SUB        ESP,0x8
//         0045da90     FSTP       double ptr [ESP]=>DAT_fffffff0
//         0045da93     CALL       floor                                            undefined floor()
//         0045da98     FSUB       float ptr [DAT_00570b80]
//         0045da9e     ADD        ESP,0x8
//         0045daa1     MOV        this,ESI
//         0045daa3     PUSH       this=>DAT_fffffff4
//         0045daa4     FSTP       float ptr [ESP]=>DAT_fffffff4
//         0045daa7     CALL       dword ptr [EDI + 0x34]
//         0045daaa     FSTP       ST0
//                              move_obj.cpp:802 (5)
//         0045daac     MOV        EAX,0x2
//                              move_obj.cpp:815 (8)
//         0045dab1     POP        EDI
//         0045dab2     POP        ESI
//         0045dab3     POP        EBP
//         0045dab4     POP        EBX
//         0045dab5     MOV        ESP,EBP
//         0045dab7     POP        EBP
//         0045dab8     RET
//                               LAB_0045dab9                                                 XREF[4]:     0045d9b1(j), 0045d9c5(j),
//                                                                                                         0045da10(j), 0045da68(j)
//                              move_obj.cpp:807 (23)
//         0045dab9     MOV        EAX,dword ptr [ESI + 0xc]
//         0045dabc     LEA        EDI,[ESI + 0xa4]
//         0045dac2     MOV        this,dword ptr [EAX + 0x3c]
//         0045dac5     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0045dac8     MOV        this,EDI
//         0045daca     PUSH       EDX
//         0045dacb     CALL       Path::setTimeStamp                               void setTimeStamp(Path * this, ulong param_1)
//                              move_obj.cpp:808 (168)
//         0045dad0     MOV        EAX,[displayPathingFlags]
//         0045dad5     MOV        EBX,dword ptr [displayPathObjectID]              = 53h
//         0045dadb     TEST       EAX,EAX
//         0045dadd     JZ         LAB_0045db78
//         0045dae3     TEST       byte ptr [ESI + 0x36],0x1
//         0045dae7     JZ         LAB_0045db78
//         0045daed     MOV        this,EDI
//         0045daef     CALL       Path::initToStart                                void initToStart(Path * this)
//         0045daf4     MOV        this,EDI
//         0045daf6     MOV        dword ptr [ESP + 0x10],0x0
//         0045dafe     CALL       Path::numberOfWaypoints                          int numberOfWaypoints(Path * this)
//         0045db03     TEST       EAX,EAX
//         0045db05     JLE        LAB_0045db6a
//         0045db07     LEA        EBP,[EBX*0x4 + 0x0]
//         0045db0e     MOV        dword ptr [ESP + 0x14],EBP
//                               LAB_0045db12                                                 XREF[1]:     0045db68(j)
//         0045db12     MOV        EBX,dword ptr [ESI + 0xc]
//         0045db15     PUSH       0x3f800000
//         0045db1a     MOV        EAX,EBX
//         0045db1c     MOV        this,dword ptr [EAX + 0x24]
//         0045db1f     MOV        EDX,dword ptr [this->_padding_ + EBP*0x1]
//         0045db22     MOV        this,EDI
//         0045db24     MOV        EBP,dword ptr [EDX]
//         0045db26     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         0045db2b     MOV        EAX,dword ptr [EAX + 0x4]
//         0045db2e     MOV        this,EDI
//         0045db30     PUSH       EAX=>DAT_fffffff8
//         0045db31     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         0045db36     MOV        this,dword ptr [EAX]
//         0045db38     MOV        EDX,dword ptr [EBX + 0x24]
//         0045db3b     MOV        dword ptr [ESP + 0x20],EBP
//         0045db3f     MOV        EBP,dword ptr [ESP + 0x1c]
//         0045db43     MOV        EAX,dword ptr [ESP + 0x20]
//         0045db47     PUSH       this=>DAT_fffffff4
//         0045db48     MOV        this,dword ptr [EDX + EBP*0x1]
//         0045db4b     PUSH       EBX=>DAT_fffffff0
//         0045db4c     CALL       dword ptr [EAX + 0x18]
//         0045db4f     MOV        EBX,dword ptr [ESP + 0x10]
//         0045db53     MOV        this,EDI
//         0045db55     INC        EBX
//         0045db56     MOV        dword ptr [ESP + 0x10],EBX
//         0045db5a     CALL       Path::moveToNextWaypoint                         int moveToNextWaypoint(Path * this)
//         0045db5f     MOV        this,EDI
//         0045db61     CALL       Path::numberOfWaypoints                          int numberOfWaypoints(Path * this)
//         0045db66     CMP        EBX,EAX
//         0045db68     JL         LAB_0045db12
//                               LAB_0045db6a                                                 XREF[1]:     0045db05(j)
//         0045db6a     MOV        this,EDI
//         0045db6c     CALL       Path::initToStart                                void initToStart(Path * this)
//         0045db71     MOV        this,EDI
//         0045db73     CALL       Path::moveToNextWaypoint                         int moveToNextWaypoint(Path * this)
//                               LAB_0045db78                                                 XREF[2]:     0045dadd(j), 0045dae7(j)
//                              move_obj.cpp:812 (7)
//         0045db78     MOV        this,EDI
//         0045db7a     CALL       Path::initToStart                                void initToStart(Path * this)
//                              move_obj.cpp:813 (7)
//         0045db7f     MOV        this,EDI
//         0045db81     CALL       Path::moveToNextWaypoint                         int moveToNextWaypoint(Path * this)
//                              move_obj.cpp:815 (10)
//         0045db86     POP        EDI
//         0045db87     POP        ESI
//         0045db88     POP        EBP
//         0045db89     POP        EBX
//         0045db8a     MOV        ESP,EBP
//         0045db8c     XOR        EAX,EAX
//         0045db8e     POP        EBP
//         0045db8f     RET
    return {};
}

int RGE_Moving_Object::doMove() {
    /* TODO: Stub */
//                              int __thiscall doMove(RGE_Moving_Object * this)
//              int               EAX:4          <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//              float             Stack[-0x10]:4 newDY
//              float             Stack[-0x14]:4 dY
//              float             Stack[-0x18]:4 distanceToGoal
//              undefined4        Stack[-0x20]:4 local_20                  XREF[1]:     0045dba4(W)
//                               ?doMove@RGE_Moving_Object@@QAEHXZ                            XREF[1]:     update:00405aac(c)
//                               RGE_Moving_Object::doMove
//                              move_obj.cpp:841 (14)
//         0045db90     PUSH       EBP
//         0045db91     MOV        EBP,ESP
//         0045db93     AND        ESP,0xfffffff8
//         0045db96     SUB        ESP,0x18
//         0045db99     PUSH       EBX
//         0045db9a     PUSH       EBP
//         0045db9b     PUSH       ESI
//         0045db9c     MOV        ESI,this
//                              move_obj.cpp:870 (16)
//         0045db9e     XOR        EBP,EBP
//         0045dba0     PUSH       EDI
//         0045dba1     MOV        EBX,dword ptr [ESI]
//         0045dba3     PUSH       EBP
//         0045dba4     MOV        dword ptr [ESP + local_20],EBX
//         0045dba8     CALL       dword ptr [EBX + 0x12c]
//                              move_obj.cpp:883 (9)
//         0045dbae     FLD        float ptr [ESI + 0x11c]
//         0045dbb4     FSUB       float ptr [ESI + 0x38]
//                              move_obj.cpp:884 (9)
//         0045dbb7     FLD        float ptr [ESI + 0x120]
//         0045dbbd     FSUB       float ptr [ESI + 0x3c]
//                              move_obj.cpp:888 (15)
//         0045dbc0     FLD        ST1
//         0045dbc2     FCOMP      float ptr [DAT_00570b48]
//         0045dbc8     FNSTSW     AX
//         0045dbca     TEST       AH,0x1
//         0045dbcd     JZ         LAB_0045dbd5
//                              move_obj.cpp:889 (6)
//         0045dbcf     FXCH
//         0045dbd1     FCHS
//         0045dbd3     FXCH
//                               LAB_0045dbd5                                                 XREF[1]:     0045dbcd(j)
//                              move_obj.cpp:890 (13)
//         0045dbd5     FCOM       float ptr [DAT_00570b48]
//         0045dbdb     FNSTSW     AX
//         0045dbdd     TEST       AH,0x1
//         0045dbe0     JZ         LAB_0045dbe4
//                              move_obj.cpp:891 (2)
//         0045dbe2     FCHS
//                               LAB_0045dbe4                                                 XREF[1]:     0045dbe0(j)
//                              move_obj.cpp:895 (12)
//         0045dbe4     MOV        EAX,dword ptr [ESI + 0x8]
//         0045dbe7     FLD        float ptr [ESI + 0x13c]
//         0045dbed     FADD       float ptr [EAX + 0x30]
//                              move_obj.cpp:896 (23)
//         0045dbf0     FLD        float ptr [ESI + 0x140]
//         0045dbf6     FADD       float ptr [EAX + 0x34]
//         0045dbf9     FXCH
//         0045dbfb     FSUBP      ST3,ST0
//         0045dbfd     FSUBR      ST0,ST1
//         0045dbff     FXCH       ST2
//         0045dc01     FST        float ptr [ESP + 0x14]
//         0045dc05     FXCH       ST2
//                              move_obj.cpp:900 (17)
//         0045dc07     FXCH       ST2
//         0045dc09     FCOMP      float ptr [DAT_00570b48]
//         0045dc0f     FNSTSW     AX
//         0045dc11     TEST       AH,0x1
//         0045dc14     FSTP       ST0
//         0045dc16     JZ         LAB_0045dc20
//                              move_obj.cpp:901 (8)
//         0045dc18     MOV        dword ptr [ESP + 0x14],0x0
//                               LAB_0045dc20                                                 XREF[1]:     0045dc16(j)
//                              move_obj.cpp:902 (15)
//         0045dc20     FCOM       float ptr [DAT_00570b48]
//         0045dc26     FNSTSW     AX
//         0045dc28     TEST       AH,0x1
//         0045dc2b     JZ         LAB_0045dc35
//         0045dc2d     FSTP       ST0
//                              move_obj.cpp:903 (6)
//         0045dc2f     FLD        float ptr [DAT_00570b48]
//                               LAB_0045dc35                                                 XREF[1]:     0045dc2b(j)
//                              move_obj.cpp:908 (14)
//         0045dc35     FLD        float ptr [ESP + 0x14]
//         0045dc39     FLD        ST1
//         0045dc3b     FXCH
//         0045dc3d     FMUL       float ptr [ESP + 0x14]
//         0045dc41     FXCH
//                              move_obj.cpp:913 (48)
//         0045dc43     FMUL       ST2
//         0045dc45     FLD        float ptr [ESI + 0x134]
//         0045dc4b     FCOMP      double ptr [DAT_00570b98]
//         0045dc51     FADDP
//         0045dc53     FNSTSW     AX
//         0045dc55     FSQRT
//         0045dc57     TEST       AH,0x41
//         0045dc5a     FSTP       float ptr [ESP + 0x14]
//         0045dc5e     FSTP       ST0
//         0045dc60     JNZ        LAB_0045dc7e
//         0045dc62     FLD        float ptr [ESP + 0x14]
//         0045dc66     FCOMP      float ptr [ESI + 0x134]
//         0045dc6c     FNSTSW     AX
//         0045dc6e     TEST       AH,0x41
//         0045dc71     JZ         LAB_0045dc7e
//                              move_obj.cpp:917 (6)
//         0045dc73     MOV        dword ptr [ESI + 0x88],EBP
//                              move_obj.cpp:921 (5)
//         0045dc79     JMP        LAB_0045e3e3
//                               LAB_0045dc7e                                                 XREF[2]:     0045dc60(j), 0045dc71(j)
//                              move_obj.cpp:923 (21)
//         0045dc7e     FLD        float ptr [ESP + 0x14]
//         0045dc82     FCOMP      double ptr [DAT_00570b90]
//         0045dc88     FNSTSW     AX
//         0045dc8a     TEST       AH,0x1
//         0045dc8d     JZ         LAB_0045dd5d
//                              move_obj.cpp:925 (17)
//         0045dc93     LEA        EDI,[ESI + 0xa4]
//         0045dc99     MOV        this,EDI
//         0045dc9b     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         0045dca0     TEST       EAX,EAX
//         0045dca2     JZ         LAB_0045dcd7
//                              move_obj.cpp:927 (7)
//         0045dca4     MOV        this,EDI
//         0045dca6     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//                              move_obj.cpp:928 (16)
//         0045dcab     FLD        float ptr [EAX]
//         0045dcad     FSUB       float ptr [ESI + 0x38]
//         0045dcb0     MOV        this,EDI
//         0045dcb2     FSTP       float ptr [ESP + 0x1c]
//         0045dcb6     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//                              move_obj.cpp:930 (26)
//         0045dcbb     FLD        float ptr [ESP + 0x1c]
//         0045dcbf     FLD        float ptr [EAX + 0x4]
//         0045dcc2     FSUB       float ptr [ESI + 0x3c]
//         0045dcc5     FLD        ST1
//         0045dcc7     FMULP      ST2
//         0045dcc9     FST        float ptr [ESP + 0x18]
//         0045dccd     FMUL       float ptr [ESP + 0x18]
//         0045dcd1     FADDP
//         0045dcd3     FSQRT
//                              move_obj.cpp:932 (2)
//         0045dcd5     JMP        LAB_0045dcdb
//                               LAB_0045dcd7                                                 XREF[1]:     0045dca2(j)
//                              move_obj.cpp:933 (4)
//         0045dcd7     FLD        float ptr [ESP + 0x14]
//                               LAB_0045dcdb                                                 XREF[1]:     0045dcd5(j)
//                              move_obj.cpp:941 (13)
//         0045dcdb     FCOMP      float ptr [DAT_00570b48]
//         0045dce1     FNSTSW     AX
//         0045dce3     TEST       AH,0x40
//         0045dce6     JZ         LAB_0045dcf8
//                              move_obj.cpp:946 (3)
//         0045dce8     MOV        dword ptr [ESI + 0x58],EBP
//                              move_obj.cpp:947 (5)
//         0045dceb     MOV        EAX,0x2
//                              move_obj.cpp:1504 (8)
//         0045dcf0     POP        EDI
//         0045dcf1     POP        ESI
//         0045dcf2     POP        EBP
//         0045dcf3     POP        EBX
//         0045dcf4     MOV        ESP,EBP
//         0045dcf6     POP        EBP
//         0045dcf7     RET
//                               LAB_0045dcf8                                                 XREF[1]:     0045dce6(j)
//                              move_obj.cpp:950 (21)
//         0045dcf8     MOV        EAX,dword ptr [ESI + 0x120]
//         0045dcfe     MOV        this,dword ptr [ESI + 0x11c]
//         0045dd04     PUSH       EAX
//         0045dd05     PUSH       this
//         0045dd06     MOV        this,ESI
//         0045dd08     CALL       RGE_Moving_Object::doTrivialMove                 int doTrivialMove(RGE_Moving_Object * this, f
//                              move_obj.cpp:954 (3)
//         0045dd0d     CMP        EAX,0x5
//                              move_obj.cpp:958 (6)
//         0045dd10     JZ         LAB_0045e3e3
//                              move_obj.cpp:960 (4)
//         0045dd16     CMP        EAX,EBP
//         0045dd18     JNZ        LAB_0045dd31
//                              move_obj.cpp:961 (10)
//         0045dd1a     MOV        dword ptr [ESI + 0x148],0x2
//                              move_obj.cpp:962 (5)
//         0045dd24     MOV        EAX,0x1
//                              move_obj.cpp:1504 (8)
//         0045dd29     POP        EDI
//         0045dd2a     POP        ESI
//         0045dd2b     POP        EBP
//         0045dd2c     POP        EBX
//         0045dd2d     MOV        ESP,EBP
//         0045dd2f     POP        EBP
//         0045dd30     RET
//                               LAB_0045dd31                                                 XREF[1]:     0045dd18(j)
//                              move_obj.cpp:965 (18)
//         0045dd31     CMP        EAX,0x1
//         0045dd34     JZ         LAB_0045e426
//         0045dd3a     CMP        EAX,0x6
//         0045dd3d     JZ         LAB_0045e426
//                              move_obj.cpp:972 (15)
//         0045dd43     CMP        EAX,0x2
//         0045dd46     JZ         LAB_0045dd52
//         0045dd48     CMP        EAX,0x3
//         0045dd4b     JZ         LAB_0045dd52
//         0045dd4d     CMP        EAX,0x4
//         0045dd50     JNZ        LAB_0045dd5d
//                               LAB_0045dd52                                                 XREF[2]:     0045dd46(j), 0045dd4b(j)
//                              move_obj.cpp:975 (6)
//         0045dd52     MOV        dword ptr [ESI + 0x88],EBP
//                              move_obj.cpp:979 (5)
//         0045dd58     JMP        LAB_0045e3e3
//                               LAB_0045dd5d                                                 XREF[2]:     0045dc8d(j), 0045dd50(j)
//                              move_obj.cpp:986 (3)
//         0045dd5d     MOV        EAX,dword ptr [ESI + 0x8]
//                              move_obj.cpp:998 (62)
//         0045dd60     LEA        EDI,[ESI + 0xa4]
//         0045dd66     MOV        this,EDI
//         0045dd68     MOV        EBP,0x1
//         0045dd6d     MOV        EDX,dword ptr [EAX + 0x30]
//         0045dd70     FLD        float ptr [EAX + 0x34]
//         0045dd73     MOV        dword ptr [ESP + 0x18],EDX
//         0045dd77     FLD        float ptr [ESP + 0x18]
//         0045dd7b     FLD        ST1
//         0045dd7d     FXCH
//         0045dd7f     FMUL       float ptr [ESP + 0x18]
//         0045dd83     FXCH
//         0045dd85     FMUL       ST2
//         0045dd87     FADDP
//         0045dd89     FSQRT
//         0045dd8b     FSTP       float ptr [ESP + 0x18]
//         0045dd8f     FSTP       ST0
//         0045dd91     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         0045dd96     TEST       EAX,EAX
//         0045dd98     JZ         LAB_0045de3d
//                              move_obj.cpp:999 (7)
//         0045dd9e     MOV        this,EDI
//         0045dda0     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//                              move_obj.cpp:1000 (16)
//         0045dda5     FLD        float ptr [EAX]
//         0045dda7     FSUB       float ptr [ESI + 0x38]
//         0045ddaa     MOV        this,EDI
//         0045ddac     FSTP       float ptr [ESP + 0x1c]
//         0045ddb0     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//                              move_obj.cpp:1014 (39)
//         0045ddb5     FLD        float ptr [ESP + 0x1c]
//         0045ddb9     FLD        float ptr [EAX + 0x4]
//         0045ddbc     FSUB       float ptr [ESI + 0x3c]
//         0045ddbf     FLD        ST1
//         0045ddc1     FMULP      ST2
//         0045ddc3     FST        float ptr [ESP + 0x1c]
//         0045ddc7     FMUL       float ptr [ESP + 0x1c]
//         0045ddcb     FADDP
//         0045ddcd     FSQRT
//         0045ddcf     FCOMP      float ptr [DAT_00570b48]
//         0045ddd5     FNSTSW     AX
//         0045ddd7     TEST       AH,0x40
//         0045ddda     JZ         LAB_0045de3f
//                              move_obj.cpp:1017 (37)
//         0045dddc     PUSH       EBP
//         0045dddd     MOV        this,EDI
//         0045dddf     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         0045dde4     MOV        EAX,dword ptr [EAX + 0x4]
//         0045dde7     MOV        this,EDI
//         0045dde9     PUSH       EAX
//         0045ddea     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         0045ddef     MOV        this,dword ptr [EAX]
//         0045ddf1     PUSH       this
//         0045ddf2     PUSH       ESI
//         0045ddf3     MOV        this,pathSystem
//         0045ddf8     CALL       PathingSystem::passable                          int passable(PathingSystem * this, RGE_Moving
//         0045ddfd     TEST       EAX,EAX
//         0045ddff     JZ         LAB_0045de28
//                              move_obj.cpp:1019 (39)
//         0045de01     MOV        this,EDI
//         0045de03     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         0045de08     MOV        EDX,dword ptr [EAX + 0x8]
//         0045de0b     MOV        this,EDI
//         0045de0d     PUSH       EDX
//         0045de0e     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         0045de13     MOV        EAX,dword ptr [EAX + 0x4]
//         0045de16     MOV        this,EDI
//         0045de18     PUSH       EAX
//         0045de19     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         0045de1e     MOV        this,dword ptr [EAX]
//         0045de20     PUSH       this
//         0045de21     MOV        this,ESI
//         0045de23     CALL       dword ptr [EBX + 0x34]
//         0045de26     FSTP       ST0
//                               LAB_0045de28                                                 XREF[1]:     0045ddff(j)
//                              move_obj.cpp:1029 (9)
//         0045de28     MOV        this,EDI
//         0045de2a     CALL       Path::moveToNextWaypoint                         int moveToNextWaypoint(Path * this)
//         0045de2f     MOV        EBP,EAX
//                              move_obj.cpp:1039 (10)
//         0045de31     MOV        dword ptr [ESI + 0x178],0x47c35000
//                              move_obj.cpp:1045 (2)
//         0045de3b     JMP        LAB_0045de3f
//                               LAB_0045de3d                                                 XREF[1]:     0045dd98(j)
//                              move_obj.cpp:1046 (2)
//         0045de3d     XOR        EBP,EBP
//                               LAB_0045de3f                                                 XREF[2]:     0045ddda(j), 0045de3b(j)
//                              move_obj.cpp:1066 (36)
//         0045de3f     MOV        EAX,dword ptr [ESI + 0x16c]
//         0045de45     MOV        dword ptr [ESP + 0x1c],0x0
//         0045de4d     CMP        EAX,0x1
//         0045de50     JLE        LAB_0045dea6
//         0045de52     FLD        float ptr [ESP + 0x14]
//         0045de56     FCOMP      float ptr [DAT_00570ba0]
//         0045de5c     FNSTSW     AX
//         0045de5e     TEST       AH,0x41
//         0045de61     JNZ        LAB_0045dea6
//                              move_obj.cpp:1069 (26)
//         0045de63     MOV        EAX,dword ptr [ESI + 0x168]
//         0045de69     XOR        EDX,EDX
//         0045de6b     XOR        this,this
//         0045de6d     MOV        DL,byte ptr [EAX + 0x1]
//         0045de70     MOV        this,byte ptr [EAX]
//         0045de72     PUSH       EDX
//         0045de73     PUSH       this
//         0045de74     MOV        this,ESI
//         0045de76     CALL       RGE_Static_Object::lookupZone                    uchar lookupZone(RGE_Static_Object * this, in
//         0045de7b     MOV        BL,AL
//                              move_obj.cpp:1070 (25)
//         0045de7d     MOV        EAX,dword ptr [ESI + 0x168]
//         0045de83     XOR        EDX,EDX
//         0045de85     XOR        this,this
//         0045de87     MOV        DL,byte ptr [EAX + 0x4]
//         0045de8a     MOV        this,byte ptr [EAX + 0x3]
//         0045de8d     PUSH       EDX
//         0045de8e     PUSH       this
//         0045de8f     MOV        this,ESI
//         0045de91     CALL       RGE_Static_Object::lookupZone                    uchar lookupZone(RGE_Static_Object * this, in
//                              move_obj.cpp:1072 (4)
//         0045de96     CMP        BL,AL
//         0045de98     JNZ        LAB_0045dea2
//                              move_obj.cpp:1073 (12)
//         0045de9a     MOV        dword ptr [ESP + 0x1c],0x40400000
//                               LAB_0045dea2                                                 XREF[1]:     0045de98(j)
//         0045dea2     MOV        EBX,dword ptr [ESP + 0x10]
//                               LAB_0045dea6                                                 XREF[2]:     0045de50(j), 0045de61(j)
//                              move_obj.cpp:1077 (39)
//         0045dea6     TEST       EBP,EBP
//         0045dea8     JNZ        LAB_0045e3b1
//         0045deae     FLD        float ptr [ESP + 0x1c]
//         0045deb2     FADD       float ptr [ESP + 0x18]
//         0045deb6     FLD        float ptr [ESP + 0x14]
//         0045deba     FXCH
//         0045debc     FADD       float ptr [ESI + 0x134]
//         0045dec2     FXCH
//         0045dec4     FCOMPP
//         0045dec6     FNSTSW     AX
//         0045dec8     TEST       AH,0x41
//         0045decb     JZ         LAB_0045def8
//                              move_obj.cpp:1078 (2)
//         0045decd     XOR        EDI,EDI
//                              move_obj.cpp:1084 (25)
//         0045decf     MOV        this,ESI
//         0045ded1     PUSH       EDI
//         0045ded2     MOV        dword ptr [ESI + 0x88],EDI
//         0045ded8     MOV        dword ptr [ESI + 0x148],0x1
//         0045dee2     CALL       dword ptr [EBX + 0x1c0]
//                              move_obj.cpp:1085 (3)
//         0045dee8     MOV        dword ptr [ESI + 0x58],EDI
//                              move_obj.cpp:1086 (5)
//         0045deeb     MOV        EAX,0x2
//                              move_obj.cpp:1504 (8)
//         0045def0     POP        EDI
//         0045def1     POP        ESI
//         0045def2     POP        EBP
//         0045def3     POP        EBX
//         0045def4     MOV        ESP,EBP
//         0045def6     POP        EBP
//         0045def7     RET
//                               LAB_0045def8                                                 XREF[1]:     0045decb(j)
//                              move_obj.cpp:1091 (8)
//         0045def8     TEST       EBP,EBP
//         0045defa     JNZ        LAB_0045e3b1
//                              move_obj.cpp:1100 (16)
//         0045df00     MOV        EDX,dword ptr [ESP + 0x10]
//         0045df04     MOV        EBX,dword ptr [EDX + 0x1c4]
//                               LAB_0045df0a                                                 XREF[1]:     0045df8b(j)
//         0045df0a     PUSH       0x0
//         0045df0c     MOV        this,ESI
//         0045df0e     CALL       EBX
//                              move_obj.cpp:1102 (14)
//         0045df10     MOV        EAX,dword ptr [ESI + 0x16c]
//         0045df16     TEST       EAX,EAX
//         0045df18     JLE        LAB_0045e92a
//                              move_obj.cpp:1109 (8)
//         0045df1e     MOV        EAX,dword ptr [ESI + 0x168]
//         0045df24     XOR        this,this
//                              move_obj.cpp:1110 (22)
//         0045df26     XOR        EDX,EDX
//         0045df28     MOV        this,byte ptr [EAX]
//         0045df2a     MOV        DL,byte ptr [EAX + 0x1]
//         0045df2d     MOV        dword ptr [ESP + 0x1c],this
//         0045df31     FILD       dword ptr [ESP + 0x1c]
//         0045df35     MOV        dword ptr [ESP + 0x1c],EDX
//         0045df39     FSUB       float ptr [ESI + 0x38]
//                              move_obj.cpp:1112 (72)
//         0045df3c     FLD        float ptr [ESP + 0x18]
//         0045df40     FILD       dword ptr [ESP + 0x1c]
//         0045df44     FSUB       float ptr [ESI + 0x3c]
//         0045df47     FXCH
//         0045df49     FADD       float ptr [ESI + 0x134]
//         0045df4f     FXCH       ST2
//         0045df51     FST        double ptr [ESP + 0x20]
//         0045df55     FXCH
//         0045df57     FST        float ptr [ESP + 0x1c]
//         0045df5b     FXCH
//         0045df5d     FMUL       double ptr [ESP + 0x20]
//         0045df61     FXCH       ST2
//         0045df63     FSUB       float ptr [DAT_00570ba8]                         = 9Ah
//         0045df69     FXCH
//         0045df6b     FMUL       float ptr [ESP + 0x1c]
//         0045df6f     FADDP      ST2,ST0
//         0045df71     FXCH
//         0045df73     FSQRT
//         0045df75     FST        float ptr [ESP + 0x1c]
//         0045df79     FXCH
//         0045df7b     FCOMPP
//         0045df7d     FNSTSW     AX
//         0045df7f     TEST       AH,0x1
//         0045df82     JZ         LAB_0045df89
//                              move_obj.cpp:1116 (5)
//         0045df84     MOV        EBP,0x1
//                               LAB_0045df89                                                 XREF[1]:     0045df82(j)
//                              move_obj.cpp:1095 (8)
//         0045df89     TEST       EBP,EBP
//         0045df8b     JZ         LAB_0045df0a
//                              move_obj.cpp:1124 (15)
//         0045df91     MOV        EDX,dword ptr [ESI + 0x144]
//         0045df97     DEC        EDX
//         0045df98     MOV        EAX,EDX
//         0045df9a     MOV        dword ptr [ESI + 0x144],EDX
//                              move_obj.cpp:1125 (4)
//         0045dfa0     TEST       EAX,EAX
//         0045dfa2     JG         LAB_0045dfdd
//                              move_obj.cpp:1131 (35)
//         0045dfa4     MOV        this,dword ptr [ESI + 0x16c]
//         0045dfaa     MOV        dword ptr [ESI + 0x88],0x0
//         0045dfb4     CMP        this,0x1
//         0045dfb7     MOV        dword ptr [ESI + 0x148],0x2
//         0045dfc1     JLE        LAB_0045e92a
//                              move_obj.cpp:1133 (9)
//         0045dfc7     ADD        EAX,0x5
//         0045dfca     MOV        dword ptr [ESI + 0x144],EAX
//                              move_obj.cpp:1137 (5)
//         0045dfd0     MOV        EAX,0x1
//                              move_obj.cpp:1504 (8)
//         0045dfd5     POP        EDI
//         0045dfd6     POP        ESI
//         0045dfd7     POP        EBP
//         0045dfd8     POP        EBX
//         0045dfd9     MOV        ESP,EBP
//         0045dfdb     POP        EBP
//         0045dfdc     RET
//                               LAB_0045dfdd                                                 XREF[1]:     0045dfa2(j)
//                              move_obj.cpp:1146 (21)
//         0045dfdd     MOV        this,dword ptr [ESI + 0xc]
//         0045dfe0     XOR        EAX,EAX
//         0045dfe2     MOV        AL,byte ptr [ESI + 0x156]
//         0045dfe8     PUSH       EAX
//         0045dfe9     CALL       RGE_Player::availablePathingAttempts             int availablePathingAttempts(RGE_Player * thi
//         0045dfee     TEST       EAX,EAX
//         0045dff0     JNZ        LAB_0045e013
//                              move_obj.cpp:1150 (6)
//         0045dff2     MOV        dword ptr [ESI + 0x88],EAX
//                              move_obj.cpp:1151 (14)
//         0045dff8     MOV        AL,byte ptr [ESI + 0x156]
//         0045dffe     INC        AL
//         0045e000     MOV        byte ptr [ESI + 0x156],AL
//                              move_obj.cpp:1152 (5)
//         0045e006     MOV        EAX,0x1
//                              move_obj.cpp:1504 (8)
//         0045e00b     POP        EDI
//         0045e00c     POP        ESI
//         0045e00d     POP        EBP
//         0045e00e     POP        EBX
//         0045e00f     MOV        ESP,EBP
//         0045e011     POP        EBP
//         0045e012     RET
//                               LAB_0045e013                                                 XREF[1]:     0045dff0(j)
//                              move_obj.cpp:1158 (8)
//         0045e013     MOV        this,dword ptr [ESI + 0xc]
//         0045e016     CALL       RGE_Player::incrementPathingAttempts             void incrementPathingAttempts(RGE_Player * th
//                              move_obj.cpp:1162 (27)
//         0045e01b     FLD        float ptr [ESI + 0x38]
//         0045e01e     FSTP       float ptr [ESI + 0x10c]
//         0045e024     FLD        float ptr [ESI + 0x3c]
//         0045e027     FSTP       float ptr [ESI + 0x110]
//         0045e02d     FLD        float ptr [ESI + 0x40]
//         0045e030     FSTP       float ptr [ESI + 0x114]
//                              move_obj.cpp:1175 (17)
//         0045e036     MOV        this,pathSystem
//         0045e03b     MOV        byte ptr [ESI + 0x156],0x0
//         0045e042     CALL       PathingSystem::incrementContinuePaths            void incrementContinuePaths(PathingSystem * t
//                              move_obj.cpp:1177 (12)
//         0045e047     MOV        EAX,dword ptr [ESI + 0x16c]
//         0045e04d     XOR        EBP,EBP
//         0045e04f     CMP        EAX,EBP
//         0045e051     JLE        LAB_0045e084
//                              move_obj.cpp:1181 (47)
//         0045e053     MOV        this,dword ptr [ESI + 0x138]
//         0045e059     MOV        EDX,dword ptr [ESI + 0x134]
//         0045e05f     MOV        EAX,dword ptr [ESI + 0x168]
//         0045e065     PUSH       -0x1
//         0045e067     PUSH       -0x1
//         0045e069     PUSH       0x1
//         0045e06b     PUSH       0x1
//         0045e06d     PUSH       0x1
//         0045e06f     PUSH       0x1
//         0045e071     PUSH       EBP
//         0045e072     PUSH       0x1
//         0045e074     PUSH       this
//         0045e075     PUSH       EDX
//         0045e076     XOR        this,this
//         0045e078     MOV        this,byte ptr [EAX + 0x1]
//         0045e07b     XOR        EDX,EDX
//         0045e07d     MOV        DL,byte ptr [EAX]
//         0045e07f     PUSH       ESI
//         0045e080     PUSH       this
//         0045e081     PUSH       EDX
//                              move_obj.cpp:1182 (2)
//         0045e082     JMP        LAB_0045e0ba
//                               LAB_0045e084                                                 XREF[1]:     0045e051(j)
//                              move_obj.cpp:1186 (90)
//         0045e084     MOV        EAX,dword ptr [ESI + 0x138]
//         0045e08a     MOV        this,dword ptr [ESI + 0x134]
//         0045e090     PUSH       -0x1
//         0045e092     PUSH       -0x1
//         0045e094     FLD        float ptr [ESI + 0x120]
//         0045e09a     PUSH       0x1
//         0045e09c     PUSH       0x1
//         0045e09e     PUSH       0x1
//         0045e0a0     PUSH       0x1
//         0045e0a2     PUSH       EBP
//         0045e0a3     PUSH       0x1
//         0045e0a5     PUSH       EAX
//         0045e0a6     PUSH       this
//         0045e0a7     PUSH       ESI
//         0045e0a8     CALL       __ftol                                           undefined __ftol()
//         0045e0ad     FLD        float ptr [ESI + 0x11c]
//         0045e0b3     PUSH       EAX
//         0045e0b4     CALL       __ftol                                           undefined __ftol()
//         0045e0b9     PUSH       EAX
//                               LAB_0045e0ba                                                 XREF[1]:     0045e082(j)
//         0045e0ba     FLD        float ptr [ESI + 0x110]
//         0045e0c0     CALL       __ftol                                           undefined __ftol()
//         0045e0c5     FLD        float ptr [ESI + 0x10c]
//         0045e0cb     PUSH       EAX
//         0045e0cc     CALL       __ftol                                           undefined __ftol()
//         0045e0d1     PUSH       EAX
//         0045e0d2     MOV        this,pathSystem
//         0045e0d7     CALL       PathingSystem::findTilePath                      int findTilePath(PathingSystem * this, int pa
//         0045e0dc     MOV        EBX,EAX
//                              move_obj.cpp:1190 (3)
//         0045e0de     MOV        dword ptr [ESI + 0x58],EBP
//                              move_obj.cpp:1193 (13)
//         0045e0e1     MOV        EAX,[actionFile]                                 = 00000000
//         0045e0e6     CMP        EAX,EBP
//         0045e0e8     JZ         LAB_0045e1b8
//                              move_obj.cpp:1195 (76)
//         0045e0ee     FLD        float ptr [ESI + 0x120]
//         0045e0f4     SUB        ESP,0x8
//         0045e0f7     MOV        EDX,dword ptr [ESI + 0x4]
//         0045e0fa     MOV        this,dword ptr [ESI + 0xc]
//         0045e0fd     FSTP       double ptr [ESP]
//         0045e100     FLD        float ptr [ESI + 0x11c]
//         0045e106     SUB        ESP,0x8
//         0045e109     FSTP       double ptr [ESP]
//         0045e10c     FLD        float ptr [ESI + 0x110]
//         0045e112     SUB        ESP,0x8
//         0045e115     FSTP       double ptr [ESP]
//         0045e118     FLD        float ptr [ESI + 0x10c]
//         0045e11e     SUB        ESP,0x8
//         0045e121     FSTP       double ptr [ESP]
//         0045e124     PUSH       EDX
//         0045e125     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0045e128     MOV        this,dword ptr [EDX + 0x4]
//         0045e12b     PUSH       this
//         0045e12c     PUSH       s_t%ld_uID=%d,_fP1_s=(%6.2f,%6.2f)               = "t%ld uID=%d, fP1 s=(%6.2f,%6.2f), g=(%6.2f
//         0045e131     PUSH       EAX
//         0045e132     CALL       fprintf                                          undefined fprintf()
//         0045e137     ADD        ESP,0x30
//                              move_obj.cpp:1196 (7)
//         0045e13a     MOV        this,EDI
//         0045e13c     CALL       Path::initToStart                                void initToStart(Path * this)
//                              move_obj.cpp:1197 (13)
//         0045e141     MOV        this,EDI
//         0045e143     XOR        EBP,EBP
//         0045e145     CALL       Path::numberOfWaypoints                          int numberOfWaypoints(Path * this)
//         0045e14a     TEST       EAX,EAX
//         0045e14c     JLE        LAB_0045e195
//                               LAB_0045e14e                                                 XREF[1]:     0045e193(j)
//                              move_obj.cpp:1198 (71)
//         0045e14e     MOV        this,EDI
//         0045e150     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         0045e155     FLD        float ptr [EAX + 0x4]
//         0045e158     SUB        ESP,0x8
//         0045e15b     MOV        this,EDI
//         0045e15d     FSTP       double ptr [ESP]
//         0045e160     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         0045e165     FLD        float ptr [EAX]
//         0045e167     MOV        EDX,dword ptr [actionFile]                       = 00000000
//         0045e16d     SUB        ESP,0x8
//         0045e170     FSTP       double ptr [ESP]
//         0045e173     PUSH       EBP
//         0045e174     PUSH       s_,_WP#%d(%6.2f,_%6.2f)                          = ", WP#%d(%6.2f, %6.2f)"
//         0045e179     PUSH       EDX
//         0045e17a     CALL       fprintf                                          undefined fprintf()
//         0045e17f     ADD        ESP,0x1c
//         0045e182     MOV        this,EDI
//         0045e184     INC        EBP
//         0045e185     CALL       Path::moveToNextWaypoint                         int moveToNextWaypoint(Path * this)
//         0045e18a     MOV        this,EDI
//         0045e18c     CALL       Path::numberOfWaypoints                          int numberOfWaypoints(Path * this)
//         0045e191     CMP        EBP,EAX
//         0045e193     JL         LAB_0045e14e
//                               LAB_0045e195                                                 XREF[1]:     0045e14c(j)
//                              move_obj.cpp:1199 (19)
//         0045e195     MOV        EAX,[actionFile]                                 = 00000000
//         0045e19a     PUSH       s_._                                             = ".\n"
//         0045e19f     PUSH       EAX
//         0045e1a0     CALL       fprintf                                          undefined fprintf()
//         0045e1a5     ADD        ESP,0x8
//                              move_obj.cpp:1200 (7)
//         0045e1a8     MOV        this,EDI
//         0045e1aa     CALL       Path::initToStart                                void initToStart(Path * this)
//                              move_obj.cpp:1201 (9)
//         0045e1af     MOV        this,EDI
//         0045e1b1     CALL       Path::moveToNextWaypoint                         int moveToNextWaypoint(Path * this)
//         0045e1b6     XOR        EBP,EBP
//                               LAB_0045e1b8                                                 XREF[1]:     0045e0e8(j)
//                              move_obj.cpp:1220 (28)
//         0045e1b8     CMP        EBX,EBP
//         0045e1ba     JNZ        LAB_0045e2bd
//         0045e1c0     MOV        this,EDI
//         0045e1c2     CALL       Path::numberOfWaypoints                          int numberOfWaypoints(Path * this)
//         0045e1c7     MOV        EBX,0x1
//         0045e1cc     CMP        EAX,EBX
//         0045e1ce     JNZ        LAB_0045e2bd
//                              move_obj.cpp:1225 (75)
//         0045e1d4     FLD        float ptr [ESI + 0x3c]
//         0045e1d7     PUSH       EBX
//         0045e1d8     SUB        ESP,0x8
//         0045e1db     FSTP       double ptr [ESP]
//         0045e1de     CALL       floor                                            undefined floor()
//         0045e1e3     FSUB       float ptr [DAT_00570b80]
//         0045e1e9     FLD        float ptr [ESI + 0x38]
//         0045e1ec     FXCH
//         0045e1ee     ADD        ESP,0x4
//         0045e1f1     FSTP       float ptr [ESP]
//         0045e1f4     SUB        ESP,0x8
//         0045e1f7     FSTP       double ptr [ESP]
//         0045e1fa     CALL       floor                                            undefined floor()
//         0045e1ff     FSUB       float ptr [DAT_00570b80]
//         0045e205     ADD        ESP,0x8
//         0045e208     MOV        this,pathSystem
//         0045e20d     PUSH       this=>pathSystem
//         0045e20e     FSTP       float ptr [ESP]
//         0045e211     PUSH       ESI
//         0045e212     CALL       PathingSystem::passable                          int passable(PathingSystem * this, RGE_Moving
//         0045e217     TEST       EAX,EAX
//         0045e219     JZ         LAB_0045e934
//                              move_obj.cpp:1232 (82)
//         0045e21f     FLD        float ptr [ESI + 0x38]
//         0045e222     FSTP       double ptr [ESP + 0x20]
//         0045e226     MOV        this,dword ptr [ESP + 0x24]
//         0045e22a     MOV        EDX,dword ptr [ESP + 0x20]
//         0045e22e     PUSH       this
//         0045e22f     PUSH       EDX
//         0045e230     CALL       floor                                            undefined floor()
//         0045e235     FSUBR      double ptr [ESP + 0x28]
//         0045e239     ADD        ESP,0x8
//         0045e23c     FCOMP      double ptr [DAT_00570b90]
//         0045e242     FNSTSW     AX
//         0045e244     TEST       AH,0x40
//         0045e247     JZ         LAB_0045e277
//         0045e249     FLD        float ptr [ESI + 0x3c]
//         0045e24c     FSTP       double ptr [ESP + 0x20]
//         0045e250     MOV        EAX,dword ptr [ESP + 0x24]
//         0045e254     MOV        this,dword ptr [ESP + 0x20]
//         0045e258     PUSH       EAX
//         0045e259     PUSH       this
//         0045e25a     CALL       floor                                            undefined floor()
//         0045e25f     FSUBR      double ptr [ESP + 0x28]
//         0045e263     ADD        ESP,0x8
//         0045e266     FCOMP      double ptr [DAT_00570b90]
//         0045e26c     FNSTSW     AX
//         0045e26e     TEST       AH,0x40
//                              move_obj.cpp:1251 (6)
//         0045e271     JNZ        LAB_0045e934
//                               LAB_0045e277                                                 XREF[1]:     0045e247(j)
//                              move_obj.cpp:1233 (70)
//         0045e277     MOV        EDX,dword ptr [ESI + 0x40]
//         0045e27a     FLD        float ptr [ESI + 0x3c]
//         0045e27d     PUSH       EDX
//         0045e27e     SUB        ESP,0x8
//         0045e281     FSTP       double ptr [ESP]
//         0045e284     CALL       floor                                            undefined floor()
//         0045e289     FSUB       float ptr [DAT_00570b80]
//         0045e28f     FLD        float ptr [ESI + 0x38]
//         0045e292     FXCH
//         0045e294     ADD        ESP,0x4
//         0045e297     FSTP       float ptr [ESP]
//         0045e29a     SUB        ESP,0x8
//         0045e29d     FSTP       double ptr [ESP]
//         0045e2a0     CALL       floor                                            undefined floor()
//         0045e2a5     FSUB       float ptr [DAT_00570b80]
//         0045e2ab     MOV        EAX,dword ptr [ESP + 0x20]
//         0045e2af     ADD        ESP,0x8
//         0045e2b2     MOV        this,ESI
//         0045e2b4     PUSH       this
//         0045e2b5     FSTP       float ptr [ESP]
//         0045e2b8     CALL       dword ptr [EAX + 0x34]
//         0045e2bb     FSTP       ST0
//                               LAB_0045e2bd                                                 XREF[2]:     0045e1ba(j), 0045e1ce(j)
//                              move_obj.cpp:1274 (162)
//         0045e2bd     MOV        EAX,[displayPathingFlags]
//         0045e2c2     MOV        EBX,dword ptr [displayPathObjectID]              = 53h
//         0045e2c8     CMP        EAX,EBP
//         0045e2ca     JZ         LAB_0045e35f
//         0045e2d0     TEST       byte ptr [ESI + 0x36],0x1
//         0045e2d4     JZ         LAB_0045e35f
//         0045e2da     MOV        this,EDI
//         0045e2dc     CALL       Path::initToStart                                void initToStart(Path * this)
//         0045e2e1     MOV        this,EDI
//         0045e2e3     MOV        dword ptr [ESP + 0x1c],EBP
//         0045e2e7     CALL       Path::numberOfWaypoints                          int numberOfWaypoints(Path * this)
//         0045e2ec     TEST       EAX,EAX
//         0045e2ee     JLE        LAB_0045e34f
//         0045e2f0     SHL        EBX,0x2
//         0045e2f3     MOV        dword ptr [ESP + 0x14],EBX
//                               LAB_0045e2f7                                                 XREF[1]:     0045e34d(j)
//         0045e2f7     MOV        EBP,dword ptr [ESI + 0xc]
//         0045e2fa     PUSH       0x3f800000
//         0045e2ff     MOV        this,EBP
//         0045e301     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0045e304     MOV        this,EDI
//         0045e306     MOV        EAX,dword ptr [EDX + EBX*0x1]
//         0045e309     MOV        EBX,dword ptr [EAX]
//         0045e30b     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         0045e310     MOV        this,dword ptr [EAX + 0x4]
//         0045e313     PUSH       this
//         0045e314     MOV        this,EDI
//         0045e316     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         0045e31b     MOV        EDX,dword ptr [EAX]
//         0045e31d     MOV        EAX,dword ptr [EBP + 0x24]
//         0045e320     MOV        dword ptr [ESP + 0x28],EBX
//         0045e324     MOV        EBX,dword ptr [ESP + 0x1c]
//         0045e328     PUSH       EDX
//         0045e329     MOV        EDX,dword ptr [ESP + 0x2c]
//         0045e32d     MOV        this,dword ptr [EAX + EBX*0x1]
//         0045e330     PUSH       EBP
//         0045e331     CALL       dword ptr [EDX + 0x18]
//         0045e334     MOV        EBP,dword ptr [ESP + 0x1c]
//         0045e338     MOV        this,EDI
//         0045e33a     INC        EBP
//         0045e33b     MOV        dword ptr [ESP + 0x1c],EBP
//         0045e33f     CALL       Path::moveToNextWaypoint                         int moveToNextWaypoint(Path * this)
//         0045e344     MOV        this,EDI
//         0045e346     CALL       Path::numberOfWaypoints                          int numberOfWaypoints(Path * this)
//         0045e34b     CMP        EBP,EAX
//         0045e34d     JL         LAB_0045e2f7
//                               LAB_0045e34f                                                 XREF[1]:     0045e2ee(j)
//         0045e34f     MOV        this,EDI
//         0045e351     CALL       Path::initToStart                                void initToStart(Path * this)
//         0045e356     MOV        this,EDI
//         0045e358     CALL       Path::moveToNextWaypoint                         int moveToNextWaypoint(Path * this)
//         0045e35d     XOR        EBP,EBP
//                               LAB_0045e35f                                                 XREF[2]:     0045e2ca(j), 0045e2d4(j)
//                              move_obj.cpp:1278 (7)
//         0045e35f     MOV        this,EDI
//         0045e361     CALL       Path::initToStart                                void initToStart(Path * this)
//                              move_obj.cpp:1279 (11)
//         0045e366     MOV        this,EDI
//         0045e368     CALL       Path::moveToNextWaypoint                         int moveToNextWaypoint(Path * this)
//         0045e36d     TEST       EAX,EAX
//         0045e36f     JNZ        LAB_0045e3a3
//                              move_obj.cpp:1284 (35)
//         0045e371     MOV        this,dword ptr [ESI + 0x16c]
//         0045e377     MOV        EAX,0x1
//         0045e37c     CMP        this,EAX
//         0045e37e     MOV        dword ptr [ESI + 0x88],EBP
//         0045e384     MOV        dword ptr [ESI + 0x148],0x2
//         0045e38e     JLE        LAB_0045e92a
//                              move_obj.cpp:1494 (7)
//         0045e394     ADD        dword ptr [ESI + 0x144],0x5
//                              move_obj.cpp:1504 (8)
//         0045e39b     POP        EDI
//         0045e39c     POP        ESI
//         0045e39d     POP        EBP
//         0045e39e     POP        EBX
//         0045e39f     MOV        ESP,EBP
//         0045e3a1     POP        EBP
//         0045e3a2     RET
//                               LAB_0045e3a3                                                 XREF[1]:     0045e36f(j)
//                              move_obj.cpp:1297 (14)
//         0045e3a3     MOV        EBX,dword ptr [ESP + 0x10]
//         0045e3a7     MOV        dword ptr [ESI + 0x178],0x47c35000
//                               LAB_0045e3b1                                                 XREF[2]:     0045dea8(j), 0045defa(j)
//                              move_obj.cpp:1304 (17)
//         0045e3b1     MOV        this,EDI
//         0045e3b3     XOR        EBP,EBP
//         0045e3b5     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         0045e3ba     TEST       EAX,EAX
//         0045e3bc     JZ         LAB_0045e8fc
//                              move_obj.cpp:1309 (28)
//         0045e3c2     MOV        this,EDI
//         0045e3c4     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         0045e3c9     MOV        EAX,dword ptr [EAX + 0x4]
//         0045e3cc     MOV        this,EDI
//         0045e3ce     PUSH       EAX
//         0045e3cf     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         0045e3d4     MOV        this,dword ptr [EAX]
//         0045e3d6     PUSH       this
//         0045e3d7     MOV        this,ESI
//         0045e3d9     CALL       RGE_Moving_Object::doTrivialMove                 int doTrivialMove(RGE_Moving_Object * this, f
//                              move_obj.cpp:1313 (5)
//         0045e3de     CMP        EAX,0x5
//         0045e3e1     JNZ        LAB_0045e406
//                               LAB_0045e3e3                                                 XREF[3]:     0045dc79(j), 0045dd10(j),
//                                                                                                         0045dd58(j)
//                              move_obj.cpp:1315 (19)
//         0045e3e3     PUSH       EBP
//         0045e3e4     MOV        this,ESI
//         0045e3e6     MOV        dword ptr [ESI + 0x148],0x1
//         0045e3f0     CALL       dword ptr [EBX + 0x1c0]
//                              move_obj.cpp:1316 (3)
//         0045e3f6     MOV        dword ptr [ESI + 0x58],EBP
//                              move_obj.cpp:1317 (5)
//         0045e3f9     MOV        EAX,0x2
//                              move_obj.cpp:1504 (8)
//         0045e3fe     POP        EDI
//         0045e3ff     POP        ESI
//         0045e400     POP        EBP
//         0045e401     POP        EBX
//         0045e402     MOV        ESP,EBP
//         0045e404     POP        EBP
//         0045e405     RET
//                               LAB_0045e406                                                 XREF[1]:     0045e3e1(j)
//                              move_obj.cpp:1319 (4)
//         0045e406     CMP        EAX,EBP
//         0045e408     JNZ        LAB_0045e421
//                              move_obj.cpp:1320 (10)
//         0045e40a     MOV        dword ptr [ESI + 0x148],0x2
//                              move_obj.cpp:1321 (5)
//         0045e414     MOV        EAX,0x1
//                              move_obj.cpp:1504 (8)
//         0045e419     POP        EDI
//         0045e41a     POP        ESI
//         0045e41b     POP        EBP
//         0045e41c     POP        EBX
//         0045e41d     MOV        ESP,EBP
//         0045e41f     POP        EBP
//         0045e420     RET
//                               LAB_0045e421                                                 XREF[1]:     0045e408(j)
//                              move_obj.cpp:1323 (5)
//         0045e421     CMP        EAX,0x1
//         0045e424     JNZ        LAB_0045e443
//                               LAB_0045e426                                                 XREF[2]:     0045dd34(j), 0045dd3d(j)
//                              move_obj.cpp:1324 (6)
//         0045e426     MOV        dword ptr [ESI + 0x88],EBP
//                              move_obj.cpp:1325 (10)
//         0045e42c     MOV        dword ptr [ESI + 0x148],0x2
//                              move_obj.cpp:1326 (5)
//         0045e436     MOV        EAX,0x1
//                              move_obj.cpp:1504 (8)
//         0045e43b     POP        EDI
//         0045e43c     POP        ESI
//         0045e43d     POP        EBP
//         0045e43e     POP        EBX
//         0045e43f     MOV        ESP,EBP
//         0045e441     POP        EBP
//         0045e442     RET
//                               LAB_0045e443                                                 XREF[1]:     0045e424(j)
//                              move_obj.cpp:1328 (9)
//         0045e443     CMP        EAX,0x2
//         0045e446     JNZ        LAB_0045e8fc
//                              move_obj.cpp:1329 (15)
//         0045e44c     MOV        this,EDI
//         0045e44e     CALL       Path::moveToNextWaypoint                         int moveToNextWaypoint(Path * this)
//         0045e453     TEST       EAX,EAX
//         0045e455     JNZ        LAB_0045e8e5
//                              move_obj.cpp:1338 (18)
//         0045e45b     MOV        EDX,dword ptr [ESP + 0x10]
//         0045e45f     XOR        EBP,EBP
//         0045e461     MOV        EBX,dword ptr [EDX + 0x1c4]
//                               LAB_0045e467                                                 XREF[1]:     0045e4e8(j)
//         0045e467     PUSH       0x0
//         0045e469     MOV        this,ESI
//         0045e46b     CALL       EBX
//                              move_obj.cpp:1340 (14)
//         0045e46d     MOV        EAX,dword ptr [ESI + 0x16c]
//         0045e473     TEST       EAX,EAX
//         0045e475     JLE        LAB_0045e92a
//                              move_obj.cpp:1347 (8)
//         0045e47b     MOV        EAX,dword ptr [ESI + 0x168]
//         0045e481     XOR        this,this
//                              move_obj.cpp:1348 (22)
//         0045e483     XOR        EDX,EDX
//         0045e485     MOV        this,byte ptr [EAX]
//         0045e487     MOV        DL,byte ptr [EAX + 0x1]
//         0045e48a     MOV        dword ptr [ESP + 0x20],this
//         0045e48e     FILD       dword ptr [ESP + 0x20]
//         0045e492     MOV        dword ptr [ESP + 0x20],EDX
//         0045e496     FSUB       float ptr [ESI + 0x38]
//                              move_obj.cpp:1350 (72)
//         0045e499     FLD        float ptr [ESP + 0x18]
//         0045e49d     FILD       dword ptr [ESP + 0x20]
//         0045e4a1     FSUB       float ptr [ESI + 0x3c]
//         0045e4a4     FXCH
//         0045e4a6     FADD       float ptr [ESI + 0x134]
//         0045e4ac     FXCH       ST2
//         0045e4ae     FST        double ptr [ESP + 0x20]
//         0045e4b2     FXCH
//         0045e4b4     FST        float ptr [ESP + 0x1c]
//         0045e4b8     FXCH
//         0045e4ba     FMUL       double ptr [ESP + 0x20]
//         0045e4be     FXCH       ST2
//         0045e4c0     FSUB       float ptr [DAT_00570ba8]                         = 9Ah
//         0045e4c6     FXCH
//         0045e4c8     FMUL       float ptr [ESP + 0x1c]
//         0045e4cc     FADDP      ST2,ST0
//         0045e4ce     FXCH
//         0045e4d0     FSQRT
//         0045e4d2     FST        float ptr [ESP + 0x20]
//         0045e4d6     FXCH
//         0045e4d8     FCOMPP
//         0045e4da     FNSTSW     AX
//         0045e4dc     TEST       AH,0x1
//         0045e4df     JZ         LAB_0045e4e6
//                              move_obj.cpp:1354 (5)
//         0045e4e1     MOV        EBP,0x1
//                               LAB_0045e4e6                                                 XREF[1]:     0045e4df(j)
//                              move_obj.cpp:1333 (8)
//         0045e4e6     TEST       EBP,EBP
//         0045e4e8     JZ         LAB_0045e467
//                              move_obj.cpp:1362 (21)
//         0045e4ee     MOV        this,dword ptr [ESI + 0xc]
//         0045e4f1     XOR        EAX,EAX
//         0045e4f3     MOV        AL,byte ptr [ESI + 0x156]
//         0045e4f9     PUSH       EAX
//         0045e4fa     CALL       RGE_Player::availablePathingAttempts             int availablePathingAttempts(RGE_Player * thi
//         0045e4ff     TEST       EAX,EAX
//         0045e501     JNZ        LAB_0045e528
//                              move_obj.cpp:1366 (6)
//         0045e503     MOV        AL,byte ptr [ESI + 0x156]
//                              move_obj.cpp:1367 (18)
//         0045e509     MOV        dword ptr [ESI + 0x88],0x0
//         0045e513     INC        AL
//         0045e515     MOV        byte ptr [ESI + 0x156],AL
//                              move_obj.cpp:1368 (5)
//         0045e51b     MOV        EAX,0x1
//                              move_obj.cpp:1504 (8)
//         0045e520     POP        EDI
//         0045e521     POP        ESI
//         0045e522     POP        EBP
//         0045e523     POP        EBX
//         0045e524     MOV        ESP,EBP
//         0045e526     POP        EBP
//         0045e527     RET
//                               LAB_0045e528                                                 XREF[1]:     0045e501(j)
//                              move_obj.cpp:1374 (8)
//         0045e528     MOV        this,dword ptr [ESI + 0xc]
//         0045e52b     CALL       RGE_Player::incrementPathingAttempts             void incrementPathingAttempts(RGE_Player * th
//                              move_obj.cpp:1378 (27)
//         0045e530     FLD        float ptr [ESI + 0x38]
//         0045e533     FSTP       float ptr [ESI + 0x10c]
//         0045e539     FLD        float ptr [ESI + 0x3c]
//         0045e53c     FSTP       float ptr [ESI + 0x110]
//         0045e542     FLD        float ptr [ESI + 0x40]
//         0045e545     FSTP       float ptr [ESI + 0x114]
//                              move_obj.cpp:1382 (17)
//         0045e54b     MOV        this,pathSystem
//         0045e550     MOV        byte ptr [ESI + 0x156],0x0
//         0045e557     CALL       PathingSystem::incrementContinuePaths            void incrementContinuePaths(PathingSystem * t
//                              move_obj.cpp:1384 (12)
//         0045e55c     MOV        EAX,dword ptr [ESI + 0x16c]
//         0045e562     XOR        EBP,EBP
//         0045e564     CMP        EAX,EBP
//         0045e566     JLE        LAB_0045e599
//                              move_obj.cpp:1388 (47)
//         0045e568     MOV        this,dword ptr [ESI + 0x138]
//         0045e56e     MOV        EDX,dword ptr [ESI + 0x134]
//         0045e574     MOV        EAX,dword ptr [ESI + 0x168]
//         0045e57a     PUSH       -0x1
//         0045e57c     PUSH       -0x1
//         0045e57e     PUSH       0x1
//         0045e580     PUSH       0x1
//         0045e582     PUSH       0x1
//         0045e584     PUSH       0x1
//         0045e586     PUSH       EBP
//         0045e587     PUSH       0x1
//         0045e589     PUSH       this
//         0045e58a     PUSH       EDX
//         0045e58b     XOR        this,this
//         0045e58d     MOV        this,byte ptr [EAX + 0x1]
//         0045e590     XOR        EDX,EDX
//         0045e592     MOV        DL,byte ptr [EAX]
//         0045e594     PUSH       ESI
//         0045e595     PUSH       this
//         0045e596     PUSH       EDX
//                              move_obj.cpp:1389 (2)
//         0045e597     JMP        LAB_0045e5cf
//                               LAB_0045e599                                                 XREF[1]:     0045e566(j)
//                              move_obj.cpp:1393 (90)
//         0045e599     MOV        EAX,dword ptr [ESI + 0x138]
//         0045e59f     MOV        this,dword ptr [ESI + 0x134]
//         0045e5a5     PUSH       -0x1
//         0045e5a7     PUSH       -0x1
//         0045e5a9     FLD        float ptr [ESI + 0x120]
//         0045e5af     PUSH       0x1
//         0045e5b1     PUSH       0x1
//         0045e5b3     PUSH       0x1
//         0045e5b5     PUSH       0x1
//         0045e5b7     PUSH       EBP
//         0045e5b8     PUSH       0x1
//         0045e5ba     PUSH       EAX
//         0045e5bb     PUSH       this
//         0045e5bc     PUSH       ESI
//         0045e5bd     CALL       __ftol                                           undefined __ftol()
//         0045e5c2     FLD        float ptr [ESI + 0x11c]
//         0045e5c8     PUSH       EAX
//         0045e5c9     CALL       __ftol                                           undefined __ftol()
//         0045e5ce     PUSH       EAX
//                               LAB_0045e5cf                                                 XREF[1]:     0045e597(j)
//         0045e5cf     FLD        float ptr [ESI + 0x110]
//         0045e5d5     CALL       __ftol                                           undefined __ftol()
//         0045e5da     FLD        float ptr [ESI + 0x10c]
//         0045e5e0     PUSH       EAX
//         0045e5e1     CALL       __ftol                                           undefined __ftol()
//         0045e5e6     PUSH       EAX
//         0045e5e7     MOV        this,pathSystem
//         0045e5ec     CALL       PathingSystem::findTilePath                      int findTilePath(PathingSystem * this, int pa
//         0045e5f1     MOV        EBX,EAX
//                              move_obj.cpp:1397 (3)
//         0045e5f3     MOV        dword ptr [ESI + 0x58],EBP
//                              move_obj.cpp:1399 (13)
//         0045e5f6     MOV        EAX,[actionFile]                                 = 00000000
//         0045e5fb     CMP        EAX,EBP
//         0045e5fd     JZ         LAB_0045e6cd
//                              move_obj.cpp:1401 (76)
//         0045e603     FLD        float ptr [ESI + 0x120]
//         0045e609     SUB        ESP,0x8
//         0045e60c     MOV        EDX,dword ptr [ESI + 0x4]
//         0045e60f     MOV        this,dword ptr [ESI + 0xc]
//         0045e612     FSTP       double ptr [ESP]
//         0045e615     FLD        float ptr [ESI + 0x11c]
//         0045e61b     SUB        ESP,0x8
//         0045e61e     FSTP       double ptr [ESP]
//         0045e621     FLD        float ptr [ESI + 0x110]
//         0045e627     SUB        ESP,0x8
//         0045e62a     FSTP       double ptr [ESP]
//         0045e62d     FLD        float ptr [ESI + 0x10c]
//         0045e633     SUB        ESP,0x8
//         0045e636     FSTP       double ptr [ESP]
//         0045e639     PUSH       EDX
//         0045e63a     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0045e63d     MOV        this,dword ptr [EDX + 0x4]
//         0045e640     PUSH       this
//         0045e641     PUSH       s_t%ld_uID=%d,_fP1_s=(%6.2f,%6.2f)               = "t%ld uID=%d, fP1 s=(%6.2f,%6.2f), g=(%6.2f
//         0045e646     PUSH       EAX
//         0045e647     CALL       fprintf                                          undefined fprintf()
//         0045e64c     ADD        ESP,0x30
//                              move_obj.cpp:1402 (7)
//         0045e64f     MOV        this,EDI
//         0045e651     CALL       Path::initToStart                                void initToStart(Path * this)
//                              move_obj.cpp:1403 (13)
//         0045e656     MOV        this,EDI
//         0045e658     XOR        EBP,EBP
//         0045e65a     CALL       Path::numberOfWaypoints                          int numberOfWaypoints(Path * this)
//         0045e65f     TEST       EAX,EAX
//         0045e661     JLE        LAB_0045e6aa
//                               LAB_0045e663                                                 XREF[1]:     0045e6a8(j)
//                              move_obj.cpp:1404 (71)
//         0045e663     MOV        this,EDI
//         0045e665     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         0045e66a     FLD        float ptr [EAX + 0x4]
//         0045e66d     SUB        ESP,0x8
//         0045e670     MOV        this,EDI
//         0045e672     FSTP       double ptr [ESP]
//         0045e675     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         0045e67a     FLD        float ptr [EAX]
//         0045e67c     MOV        EDX,dword ptr [actionFile]                       = 00000000
//         0045e682     SUB        ESP,0x8
//         0045e685     FSTP       double ptr [ESP]
//         0045e688     PUSH       EBP
//         0045e689     PUSH       s_,_WP#%d(%6.2f,_%6.2f)                          = ", WP#%d(%6.2f, %6.2f)"
//         0045e68e     PUSH       EDX
//         0045e68f     CALL       fprintf                                          undefined fprintf()
//         0045e694     ADD        ESP,0x1c
//         0045e697     MOV        this,EDI
//         0045e699     INC        EBP
//         0045e69a     CALL       Path::moveToNextWaypoint                         int moveToNextWaypoint(Path * this)
//         0045e69f     MOV        this,EDI
//         0045e6a1     CALL       Path::numberOfWaypoints                          int numberOfWaypoints(Path * this)
//         0045e6a6     CMP        EBP,EAX
//         0045e6a8     JL         LAB_0045e663
//                               LAB_0045e6aa                                                 XREF[1]:     0045e661(j)
//                              move_obj.cpp:1405 (19)
//         0045e6aa     MOV        EAX,[actionFile]                                 = 00000000
//         0045e6af     PUSH       s_._                                             = ".\n"
//         0045e6b4     PUSH       EAX
//         0045e6b5     CALL       fprintf                                          undefined fprintf()
//         0045e6ba     ADD        ESP,0x8
//                              move_obj.cpp:1406 (7)
//         0045e6bd     MOV        this,EDI
//         0045e6bf     CALL       Path::initToStart                                void initToStart(Path * this)
//                              move_obj.cpp:1407 (9)
//         0045e6c4     MOV        this,EDI
//         0045e6c6     CALL       Path::moveToNextWaypoint                         int moveToNextWaypoint(Path * this)
//         0045e6cb     XOR        EBP,EBP
//                               LAB_0045e6cd                                                 XREF[1]:     0045e5fd(j)
//                              move_obj.cpp:1425 (99)
//         0045e6cd     CMP        EBX,EBP
//         0045e6cf     JNZ        LAB_0045e805
//         0045e6d5     MOV        this,EDI
//         0045e6d7     CALL       Path::numberOfWaypoints                          int numberOfWaypoints(Path * this)
//         0045e6dc     CMP        EAX,0x1
//         0045e6df     JNZ        LAB_0045e805
//         0045e6e5     FLD        float ptr [ESI + 0x3c]
//         0045e6e8     PUSH       EAX
//         0045e6e9     SUB        ESP,0x8
//         0045e6ec     FSTP       double ptr [ESP]
//         0045e6ef     CALL       floor                                            undefined floor()
//         0045e6f4     FSUB       float ptr [DAT_00570b80]
//         0045e6fa     FLD        float ptr [ESI + 0x38]
//         0045e6fd     FXCH
//         0045e6ff     ADD        ESP,0x4
//         0045e702     FSTP       float ptr [ESP]
//         0045e705     SUB        ESP,0x8
//         0045e708     FSTP       double ptr [ESP]
//         0045e70b     CALL       floor                                            undefined floor()
//         0045e710     FSUB       float ptr [DAT_00570b80]
//         0045e716     ADD        ESP,0x8
//         0045e719     MOV        this,pathSystem
//         0045e71e     PUSH       this=>pathSystem
//         0045e71f     FSTP       float ptr [ESP]
//         0045e722     PUSH       ESI
//         0045e723     CALL       PathingSystem::passable                          int passable(PathingSystem * this, RGE_Moving
//         0045e728     TEST       EAX,EAX
//         0045e72a     JZ         LAB_0045e805
//                              move_obj.cpp:1430 (84)
//         0045e730     FLD        float ptr [ESI + 0x38]
//         0045e733     FSTP       double ptr [ESP + 0x20]
//         0045e737     MOV        this,dword ptr [ESP + 0x24]
//         0045e73b     MOV        EDX,dword ptr [ESP + 0x20]
//         0045e73f     PUSH       this
//         0045e740     PUSH       EDX
//         0045e741     CALL       floor                                            undefined floor()
//         0045e746     FSUBR      double ptr [ESP + 0x28]
//         0045e74a     ADD        ESP,0x8
//         0045e74d     FCOMP      double ptr [DAT_00570b90]
//         0045e753     FNSTSW     AX
//         0045e755     TEST       AH,0x40
//         0045e758     JZ         LAB_0045e7bf
//         0045e75a     FLD        float ptr [ESI + 0x3c]
//         0045e75d     FSTP       double ptr [ESP + 0x20]
//         0045e761     MOV        EAX,dword ptr [ESP + 0x24]
//         0045e765     MOV        this,dword ptr [ESP + 0x20]
//         0045e769     PUSH       EAX
//         0045e76a     PUSH       this
//         0045e76b     CALL       floor                                            undefined floor()
//         0045e770     FSUBR      double ptr [ESP + 0x28]
//         0045e774     ADD        ESP,0x8
//         0045e777     FCOMP      double ptr [DAT_00570b90]
//         0045e77d     FNSTSW     AX
//         0045e77f     TEST       AH,0x40
//         0045e782     JZ         LAB_0045e7bf
//                              move_obj.cpp:1438 (31)
//         0045e784     MOV        EAX,dword ptr [ESI + 0x16c]
//         0045e78a     MOV        dword ptr [ESI + 0x88],EBP
//         0045e790     CMP        EAX,0x1
//         0045e793     MOV        dword ptr [ESI + 0x148],0x2
//         0045e79d     JLE        LAB_0045e92a
//                              move_obj.cpp:1440 (15)
//         0045e7a3     MOV        EAX,dword ptr [ESI + 0x144]
//         0045e7a9     ADD        EAX,0x5
//         0045e7ac     MOV        dword ptr [ESI + 0x144],EAX
//                              move_obj.cpp:1444 (5)
//         0045e7b2     MOV        EAX,0x1
//                              move_obj.cpp:1504 (8)
//         0045e7b7     POP        EDI
//         0045e7b8     POP        ESI
//         0045e7b9     POP        EBP
//         0045e7ba     POP        EBX
//         0045e7bb     MOV        ESP,EBP
//         0045e7bd     POP        EBP
//         0045e7be     RET
//                               LAB_0045e7bf                                                 XREF[2]:     0045e758(j), 0045e782(j)
//                              move_obj.cpp:1431 (70)
//         0045e7bf     MOV        EDX,dword ptr [ESI + 0x40]
//         0045e7c2     FLD        float ptr [ESI + 0x3c]
//         0045e7c5     PUSH       EDX
//         0045e7c6     SUB        ESP,0x8
//         0045e7c9     FSTP       double ptr [ESP]
//         0045e7cc     CALL       floor                                            undefined floor()
//         0045e7d1     FSUB       float ptr [DAT_00570b80]
//         0045e7d7     FLD        float ptr [ESI + 0x38]
//         0045e7da     FXCH
//         0045e7dc     ADD        ESP,0x4
//         0045e7df     FSTP       float ptr [ESP]
//         0045e7e2     SUB        ESP,0x8
//         0045e7e5     FSTP       double ptr [ESP]
//         0045e7e8     CALL       floor                                            undefined floor()
//         0045e7ed     FSUB       float ptr [DAT_00570b80]
//         0045e7f3     MOV        EAX,dword ptr [ESP + 0x20]
//         0045e7f7     ADD        ESP,0x8
//         0045e7fa     MOV        this,ESI
//         0045e7fc     PUSH       this
//         0045e7fd     FSTP       float ptr [ESP]
//         0045e800     CALL       dword ptr [EAX + 0x34]
//         0045e803     FSTP       ST0
//                               LAB_0045e805                                                 XREF[3]:     0045e6cf(j), 0045e6df(j),
//                                                                                                         0045e72a(j)
//                              move_obj.cpp:1452 (160)
//         0045e805     MOV        EAX,[displayPathingFlags]
//         0045e80a     MOV        EBX,dword ptr [displayPathObjectID]              = 53h
//         0045e810     CMP        EAX,EBP
//         0045e812     JZ         LAB_0045e8a5
//         0045e818     TEST       byte ptr [ESI + 0x36],0x1
//         0045e81c     JZ         LAB_0045e8a5
//         0045e822     MOV        this,EDI
//         0045e824     CALL       Path::initToStart                                void initToStart(Path * this)
//         0045e829     MOV        this,EDI
//         0045e82b     MOV        dword ptr [ESP + 0x1c],EBP
//         0045e82f     CALL       Path::numberOfWaypoints                          int numberOfWaypoints(Path * this)
//         0045e834     TEST       EAX,EAX
//         0045e836     JLE        LAB_0045e897
//         0045e838     SHL        EBX,0x2
//         0045e83b     MOV        dword ptr [ESP + 0x20],EBX
//                               LAB_0045e83f                                                 XREF[1]:     0045e895(j)
//         0045e83f     MOV        EBP,dword ptr [ESI + 0xc]
//         0045e842     PUSH       0x3f800000
//         0045e847     MOV        this,EBP
//         0045e849     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0045e84c     MOV        this,EDI
//         0045e84e     MOV        EAX,dword ptr [EDX + EBX*0x1]
//         0045e851     MOV        EBX,dword ptr [EAX]
//         0045e853     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         0045e858     MOV        this,dword ptr [EAX + 0x4]
//         0045e85b     PUSH       this
//         0045e85c     MOV        this,EDI
//         0045e85e     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         0045e863     MOV        EDX,dword ptr [EAX]
//         0045e865     MOV        EAX,dword ptr [EBP + 0x24]
//         0045e868     MOV        dword ptr [ESP + 0x20],EBX
//         0045e86c     MOV        EBX,dword ptr [ESP + 0x28]
//         0045e870     PUSH       EDX
//         0045e871     MOV        EDX,dword ptr [ESP + 0x24]
//         0045e875     MOV        this,dword ptr [EAX + EBX*0x1]
//         0045e878     PUSH       EBP
//         0045e879     CALL       dword ptr [EDX + 0x18]
//         0045e87c     MOV        EBP,dword ptr [ESP + 0x1c]
//         0045e880     MOV        this,EDI
//         0045e882     INC        EBP
//         0045e883     MOV        dword ptr [ESP + 0x1c],EBP
//         0045e887     CALL       Path::moveToNextWaypoint                         int moveToNextWaypoint(Path * this)
//         0045e88c     MOV        this,EDI
//         0045e88e     CALL       Path::numberOfWaypoints                          int numberOfWaypoints(Path * this)
//         0045e893     CMP        EBP,EAX
//         0045e895     JL         LAB_0045e83f
//                               LAB_0045e897                                                 XREF[1]:     0045e836(j)
//         0045e897     MOV        this,EDI
//         0045e899     CALL       Path::initToStart                                void initToStart(Path * this)
//         0045e89e     MOV        this,EDI
//         0045e8a0     CALL       Path::moveToNextWaypoint                         int moveToNextWaypoint(Path * this)
//                               LAB_0045e8a5                                                 XREF[2]:     0045e812(j), 0045e81c(j)
//                              move_obj.cpp:1456 (7)
//         0045e8a5     MOV        this,EDI
//         0045e8a7     CALL       Path::initToStart                                void initToStart(Path * this)
//                              move_obj.cpp:1458 (11)
//         0045e8ac     MOV        this,EDI
//         0045e8ae     CALL       Path::moveToNextWaypoint                         int moveToNextWaypoint(Path * this)
//         0045e8b3     TEST       EAX,EAX
//         0045e8b5     JNZ        LAB_0045e8e5
//                              move_obj.cpp:1463 (31)
//         0045e8b7     MOV        this,dword ptr [ESI + 0x16c]
//         0045e8bd     MOV        dword ptr [ESI + 0x88],EAX
//         0045e8c3     MOV        EAX,0x1
//         0045e8c8     MOV        dword ptr [ESI + 0x148],0x2
//         0045e8d2     CMP        this,EAX
//         0045e8d4     JLE        LAB_0045e92a
//                              move_obj.cpp:1494 (7)
//         0045e8d6     ADD        dword ptr [ESI + 0x144],0x5
//                              move_obj.cpp:1504 (8)
//         0045e8dd     POP        EDI
//         0045e8de     POP        ESI
//         0045e8df     POP        EBP
//         0045e8e0     POP        EBX
//         0045e8e1     MOV        ESP,EBP
//         0045e8e3     POP        EBP
//         0045e8e4     RET
//                               LAB_0045e8e5                                                 XREF[2]:     0045e455(j), 0045e8b5(j)
//                              move_obj.cpp:1481 (10)
//         0045e8e5     MOV        dword ptr [ESI + 0x148],0x2
//                              move_obj.cpp:1482 (5)
//         0045e8ef     MOV        EAX,0x1
//                              move_obj.cpp:1504 (8)
//         0045e8f4     POP        EDI
//         0045e8f5     POP        ESI
//         0045e8f6     POP        EBP
//         0045e8f7     POP        EBX
//         0045e8f8     MOV        ESP,EBP
//         0045e8fa     POP        EBP
//         0045e8fb     RET
//                               LAB_0045e8fc                                                 XREF[2]:     0045e3bc(j), 0045e446(j)
//                              move_obj.cpp:1492 (31)
//         0045e8fc     MOV        this,dword ptr [ESI + 0x16c]
//         0045e902     MOV        EAX,0x1
//         0045e907     CMP        this,EAX
//         0045e909     MOV        dword ptr [ESI + 0x88],EBP
//         0045e90f     MOV        dword ptr [ESI + 0x148],0x2
//         0045e919     JLE        LAB_0045e92a
//                              move_obj.cpp:1494 (7)
//         0045e91b     ADD        dword ptr [ESI + 0x144],0x5
//                              move_obj.cpp:1504 (8)
//         0045e922     POP        EDI
//         0045e923     POP        ESI
//         0045e924     POP        EBP
//         0045e925     POP        EBX
//         0045e926     MOV        ESP,EBP
//         0045e928     POP        EBP
//         0045e929     RET
//                               LAB_0045e92a                                                 XREF[8]:     0045df18(j), 0045dfc1(j),
//                                                                                                         0045e38e(j), 0045e475(j),
//                                                                                                         0045e79d(j), 0045e8d4(j),
//                                                                                                         0045e919(j), 0045e94c(j)
//                              move_obj.cpp:1503 (2)
//         0045e92a     XOR        EAX,EAX
//                              move_obj.cpp:1504 (8)
//         0045e92c     POP        EDI
//         0045e92d     POP        ESI
//         0045e92e     POP        EBP
//         0045e92f     POP        EBX
//         0045e930     MOV        ESP,EBP
//         0045e932     POP        EBP
//         0045e933     RET
//                               LAB_0045e934                                                 XREF[2]:     0045e219(j), 0045e271(j)
//                              move_obj.cpp:1260 (26)
//         0045e934     MOV        EAX,dword ptr [ESI + 0x16c]
//         0045e93a     MOV        dword ptr [ESI + 0x88],EBP
//         0045e940     CMP        EAX,EBX
//         0045e942     MOV        dword ptr [ESI + 0x148],0x2
//         0045e94c     JLE        LAB_0045e92a
//                              move_obj.cpp:1262 (6)
//         0045e94e     MOV        EAX,dword ptr [ESI + 0x144]
//                              move_obj.cpp:1504 (19)
//         0045e954     POP        EDI
//         0045e955     ADD        EAX,0x5
//         0045e958     MOV        dword ptr [ESI + 0x144],EAX
//         0045e95e     POP        ESI
//         0045e95f     MOV        EAX,EBX
//         0045e961     POP        EBP
//         0045e962     POP        EBX
//         0045e963     MOV        ESP,EBP
//         0045e965     POP        EBP
//         0045e966     RET
//         0045e967     ??         90h
//         0045e968     NOP
//         0045e969     NOP
//         0045e96a     NOP
//         0045e96b     NOP
//         0045e96c     NOP
//         0045e96d     NOP
//         0045e96e     NOP
//         0045e96f     NOP
    return 0;
}

int RGE_Moving_Object::doTrivialMove(float param_1, float param_2) {
    /* TODO: Stub */
//                              int __thiscall doTrivialMove(RGE_Moving_Object * this, float param_1
//              int               EAX:4          <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1                   XREF[4]:     0045eaa1(R), 0045eacd(R), 0045eeb5(R), 0045f6ba(R)
//              float             Stack[0x8]:4   param_2                   XREF[4]:     0045ea9e(R), 0045eaeb(R), 0045eeb2(R), 0045f6c1(R)
//              float             Stack[-0x10]:4 dY
//              int               Stack[-0x14]:4 alreadyMoving             XREF[6]:     0045eb6a(W), 0045eb6e(R), 0045ecff(W), 0045ed03(R),
//                                                                                     0045ed52(W), 0045ed56(R)
//              float             Stack[-0x18]:4 curDistance               XREF[3]:     0045e991(W), 0045e9a3(W), 0045f567(W)
//              float             Stack[-0x1c]:4 newY                      XREF[5]:     0045eb78(W), 0045eb98(R), 0045ec41(W), 0045ec88(W),
//                                                                                     0045ec8c(R)
//              float             Stack[-0x20]:4 dX                        XREF[2]:     0045ec90(W), 0045ec9b(R)
//              float             Stack[-0x24]:4 distanceToCover           XREF[2]:     0045ec5f(W), 0045ec82(R)
//              float             Stack[-0x28]:4 newAngle                  XREF[4]:     0045e9ee(W), 0045ea0b(R), 0045ec47(R), 0045ec50(R)
//              float             Stack[-0x2c]:4 targetDY                  XREF[3]:     0045eaf4(*), 0045eafd(W), 0045eb06(R)
//              int               Stack[-0x30]:4 numberFacets              XREF[9]:     0045eaae(W), 0045ead6(W), 0045eaee(R), 0045eb16(W),
//                                                                                     0045eb34(W), 0045eb58(W), 0045ebb6(R), 0045ec59(W),
//                                                                                     0045ec7c(R)
//              undefined4        Stack[-0x34]:4 local_34                  XREF[4]:     0045ea98(W), 0045eb5c(R), 0045ebd7(R), 0045ec1b(R)
//              undefined8        Stack[-0x48]:8 local_48                  XREF[4]:     0045eaba(*), 0045eada(*), 0045ed99(*), 0045ede5(*)
//              undefined8        Stack[-0x50]:8 local_50                  XREF[2,4]:   0045ed9f(*), 0045edeb(*), 0045ed83(*), 0045edb6(*),
//                                                                                     0045edcf(*), 0045edff(*)
//                               ?doTrivialMove@RGE_Moving_Object@@QAEHMM@Z                   XREF[2]:     doMove:0045dd08(c),
//                               RGE_Moving_Object::doTrivialMove                                          doMove:0045e3d9(c)
//                              move_obj.cpp:1509 (14)
//         0045e970     PUSH       EBP
//         0045e971     MOV        EBP,ESP
//         0045e973     AND        ESP,0xfffffff8
//         0045e976     SUB        ESP,0x2c
//         0045e979     PUSH       EBX
//         0045e97a     PUSH       ESI
//         0045e97b     MOV        ESI,this
//         0045e97d     PUSH       EDI
//                              move_obj.cpp:1520 (5)
//         0045e97e     MOV        EDX,0x1
//                              move_obj.cpp:1521 (25)
//         0045e983     XOR        EDI,EDI
//         0045e985     FLD        float ptr [ESI + 0x88]
//         0045e98b     FCOMP      double ptr [DAT_00570b98]
//         0045e991     MOV        dword ptr [ESP + curDistance],EDX
//         0045e995     FNSTSW     AX
//         0045e997     TEST       AH,0x40
//         0045e99a     JZ         LAB_0045e9dc
//                              move_obj.cpp:1523 (29)
//         0045e99c     MOV        this,dword ptr [ESI + 0x10]
//         0045e99f     XOR        EDX,EDX
//         0045e9a1     CMP        this,EDI
//         0045e9a3     MOV        dword ptr [ESP + curDistance],EDX
//         0045e9a7     JZ         LAB_0045e9cd
//         0045e9a9     FLD        float ptr [ECX + this->_padding_]
//         0045e9ac     FCOMP      double ptr [DAT_00570b98]
//         0045e9b2     FNSTSW     AX
//         0045e9b4     TEST       AH,0x41
//         0045e9b7     JNZ        LAB_0045e9cd
//                              move_obj.cpp:1524 (18)
//         0045e9b9     MOV        EAX,dword ptr [ESI + 0x8]
//         0045e9bc     FLD        float ptr [EAX + 0xb8]
//         0045e9c2     FMUL       float ptr [ECX + this->_padding_]
//         0045e9c5     FSTP       float ptr [ESI + 0x88]
//                              move_obj.cpp:1525 (2)
//         0045e9cb     JMP        LAB_0045e9dc
//                               LAB_0045e9cd                                                 XREF[2]:     0045e9a7(j), 0045e9b7(j)
//                              move_obj.cpp:1526 (15)
//         0045e9cd     MOV        this,dword ptr [ESI + 0x8]
//         0045e9d0     MOV        EAX,dword ptr [ECX + this+0xb8]
//         0045e9d6     MOV        dword ptr [ESI + 0x88],EAX
//                               LAB_0045e9dc                                                 XREF[2]:     0045e99a(j), 0045e9cb(j)
//                              move_obj.cpp:1529 (22)
//         0045e9dc     MOV        this,dword ptr [ESI + 0xc]
//         0045e9df     MOV        EAX,dword ptr [ECX + this->_padding_]
//         0045e9e2     FLD        float ptr [EAX + 0x84]
//         0045e9e8     FMUL       float ptr [ESI + 0x88]
//         0045e9ee     FSTP       float ptr [ESP + newAngle]
//                              move_obj.cpp:1536 (19)
//         0045e9f2     FLD        float ptr [ESI + 0x130]
//         0045e9f8     FCOMP      double ptr [DAT_00570b98]
//         0045e9fe     FNSTSW     AX
//         0045ea00     TEST       AH,0x41
//         0045ea03     JNZ        LAB_0045ea3d
//                              move_obj.cpp:1537 (10)
//         0045ea05     FLD        float ptr [ESI + 0x130]
//         0045ea0b     FSUB       float ptr [ESP + newAngle]
//                              move_obj.cpp:1542 (19)
//         0045ea0f     FCOM       double ptr [DAT_00570b98]
//         0045ea15     FSTP       float ptr [ESI + 0x130]
//         0045ea1b     FNSTSW     AX
//         0045ea1d     TEST       AH,0x41
//         0045ea20     JNZ        LAB_0045ea33
//                              move_obj.cpp:1547 (6)
//         0045ea22     MOV        dword ptr [ESI + 0x88],EDI
//                              move_obj.cpp:2184 (2)
//         0045ea28     XOR        EAX,EAX
//                              move_obj.cpp:2185 (9)
//         0045ea2a     POP        EDI
//         0045ea2b     POP        ESI
//         0045ea2c     POP        EBX
//         0045ea2d     MOV        ESP,EBP
//         0045ea2f     POP        EBP
//         0045ea30     RET        0x8
//                               LAB_0045ea33                                                 XREF[1]:     0045ea20(j)
//                              move_obj.cpp:1553 (10)
//         0045ea33     MOV        dword ptr [ESI + 0x130],0xbf800000
//                               LAB_0045ea3d                                                 XREF[1]:     0045ea03(j)
//                              move_obj.cpp:1561 (22)
//         0045ea3d     MOV        EAX,dword ptr [ESI + 0x8]
//         0045ea40     FLD        float ptr [EAX + 0xc4]
//         0045ea46     FCOMP      double ptr [DAT_00570b98]
//         0045ea4c     FNSTSW     AX
//         0045ea4e     TEST       AH,0x41
//         0045ea51     JNZ        LAB_0045ea83
//                              move_obj.cpp:1562 (19)
//         0045ea53     FLD        float ptr [ESI + 0x12c]
//         0045ea59     FCOMP      double ptr [DAT_00570b98]
//         0045ea5f     FNSTSW     AX
//         0045ea61     TEST       AH,0x1
//         0045ea64     JZ         LAB_0045ea6e
//                              move_obj.cpp:1563 (6)
//         0045ea66     MOV        dword ptr [ESI + 0x12c],EDI
//                              move_obj.cpp:1564 (2)
//         0045ea6c     JMP        LAB_0045ea83
//                               LAB_0045ea6e                                                 XREF[1]:     0045ea64(j)
//                              move_obj.cpp:1565 (21)
//         0045ea6e     MOV        this,dword ptr [ECX + this->_padding_]
//         0045ea71     FLD        float ptr [ESI + 0x12c]
//         0045ea77     FSUB       float ptr [ECX + this->_padding_]
//         0045ea7d     FSTP       float ptr [ESI + 0x12c]
//                               LAB_0045ea83                                                 XREF[2]:     0045ea51(j), 0045ea6c(j)
//                              move_obj.cpp:1571 (7)
//         0045ea83     MOV        EAX,dword ptr [ESI + 0x10]
//         0045ea86     CMP        EAX,EDI
//         0045ea88     JZ         LAB_0045ea90
//                              move_obj.cpp:1572 (4)
//         0045ea8a     MOVSX      EDI,word ptr [EAX + 0x60]
//                              move_obj.cpp:1573 (2)
//         0045ea8e     JMP        LAB_0045ea95
//                               LAB_0045ea90                                                 XREF[1]:     0045ea88(j)
//                              move_obj.cpp:1574 (5)
//         0045ea90     MOV        EDI,0x8
//                               LAB_0045ea95                                                 XREF[1]:     0045ea8e(j)
//                              move_obj.cpp:1585 (9)
//         0045ea95     CMP        EDX,0x1
//         0045ea98     MOV        dword ptr [ESP + local_34],EDI
//         0045ea9c     JNZ        LAB_0045eab4
//                              move_obj.cpp:1588 (20)
//         0045ea9e     FLD        float ptr [EBP + param_2]
//         0045eaa1     FLD        float ptr [EBP + param_1]
//         0045eaa4     FSUB       float ptr [ESI + 0x38]
//         0045eaa7     FXCH
//         0045eaa9     FSUB       float ptr [ESI + 0x3c]
//         0045eaac     FXCH
//         0045eaae     FSTP       float ptr [ESP + numberFacets]
//                              move_obj.cpp:1590 (2)
//         0045eab2     JMP        LAB_0045eaee
//                               LAB_0045eab4                                                 XREF[1]:     0045ea9c(j)
//                              move_obj.cpp:1592 (20)
//         0045eab4     FLD        float ptr [ESI + 0x38]
//         0045eab7     SUB        ESP,0x8
//         0045eaba     FSTP       double ptr [ESP]=>local_48
//         0045eabd     CALL       floor                                            undefined floor()
//         0045eac2     FSUB       float ptr [DAT_00570b80]
//                              move_obj.cpp:1593 (38)
//         0045eac8     FLD        float ptr [ESI + 0x3c]
//         0045eacb     FXCH
//         0045eacd     FSUBR      float ptr [EBP + param_1]
//         0045ead0     ADD        ESP,0x8
//         0045ead3     SUB        ESP,0x8
//         0045ead6     FSTP       float ptr [ESP + numberFacets]
//         0045eada     FSTP       double ptr [ESP]=>local_48
//         0045eadd     CALL       floor                                            undefined floor()
//         0045eae2     FSUB       float ptr [DAT_00570b80]
//         0045eae8     ADD        ESP,0x8
//         0045eaeb     FSUBR      float ptr [EBP + param_2]
//                               LAB_0045eaee                                                 XREF[1]:     0045eab2(j)
//                              move_obj.cpp:1596 (6)
//         0045eaee     FLD        float ptr [ESP + numberFacets]
//         0045eaf2     FPATAN
//                              move_obj.cpp:1600 (18)
//         0045eaf4     LEA        EDX=>targetDY,[ESP + 0x14]
//         0045eaf8     PUSH       -0x1
//         0045eafa     PUSH       EDX
//         0045eafb     MOV        this,ESI
//         0045eafd     FSTP       float ptr [ESP + targetDY]
//         0045eb01     CALL       RGE_Moving_Object::boundAngle                    void boundAngle(RGE_Moving_Object * this, flo
//                              move_obj.cpp:1605 (10)
//         0045eb06     FLD        float ptr [ESP + targetDY]
//         0045eb0a     FSUB       float ptr [ESI + 0x9c]
//                              move_obj.cpp:1609 (17)
//         0045eb10     FCOM       double ptr [DAT_00570b70]                        = F1h
//         0045eb16     FST        float ptr [ESP + numberFacets]
//         0045eb1a     FNSTSW     AX
//         0045eb1c     TEST       AH,0x1
//         0045eb1f     JZ         LAB_0045eb38
//                               LAB_0045eb21                                                 XREF[1]:     0045eb32(j)
//                              move_obj.cpp:1610 (23)
//         0045eb21     FSUB       float ptr [DAT_00570b4c]                         = DBh
//         0045eb27     FCOM       double ptr [DAT_00570b70]                        = F1h
//         0045eb2d     FNSTSW     AX
//         0045eb2f     TEST       AH,0x1
//         0045eb32     JNZ        LAB_0045eb21
//         0045eb34     FST        float ptr [ESP + numberFacets]
//                               LAB_0045eb38                                                 XREF[1]:     0045eb1f(j)
//                              move_obj.cpp:1611 (13)
//         0045eb38     FCOM       double ptr [DAT_00570b68]                        = F1h
//         0045eb3e     FNSTSW     AX
//         0045eb40     TEST       AH,0x41
//         0045eb43     JNZ        LAB_0045eb5c
//                               LAB_0045eb45                                                 XREF[1]:     0045eb56(j)
//                              move_obj.cpp:1612 (23)
//         0045eb45     FSUB       float ptr [DAT_00570b50]                         = DBh
//         0045eb4b     FCOM       double ptr [DAT_00570b68]                        = F1h
//         0045eb51     FNSTSW     AX
//         0045eb53     TEST       AH,0x41
//         0045eb56     JZ         LAB_0045eb45
//         0045eb58     FST        float ptr [ESP + numberFacets]
//                               LAB_0045eb5c                                                 XREF[1]:     0045eb43(j)
//                              move_obj.cpp:1617 (4)
//         0045eb5c     FILD       dword ptr [ESP + local_34]
//                              move_obj.cpp:1623 (33)
//         0045eb60     PUSH       EDI
//         0045eb61     LEA        EDI,[ESI + 0x9c]
//         0045eb67     PUSH       EDI
//         0045eb68     MOV        this,ESI
//         0045eb6a     FSTP       float ptr [ESP + alreadyMoving]
//         0045eb6e     FMUL       float ptr [ESP + alreadyMoving]
//         0045eb72     FMUL       float ptr [DAT_00570b78]                         = 83h
//         0045eb78     FSTP       float ptr [ESP + newY]
//         0045eb7c     CALL       RGE_Moving_Object::boundAngle                    void boundAngle(RGE_Moving_Object * this, flo
//                              move_obj.cpp:1644 (53)
//         0045eb81     FLD        float ptr [ESI + 0x12c]
//         0045eb87     FCOMP      float ptr [DAT_00570b48]
//         0045eb8d     FNSTSW     AX
//         0045eb8f     TEST       AH,0x41
//         0045eb92     JZ         LAB_0045ec1b
//         0045eb98     FLD        float ptr [ESP + newY]
//                               LAB_0045eb9c                                                 XREF[1]:     0045ec17(j)
//         0045eb9c     FCOM       double ptr [DAT_00570bb0]                        = 9Ah
//         0045eba2     FNSTSW     AX
//         0045eba4     TEST       AH,0x41
//         0045eba7     JZ         LAB_0045ebb6
//         0045eba9     FCOM       double ptr [DAT_00570bb8]                        = 9Ah
//         0045ebaf     FNSTSW     AX
//         0045ebb1     TEST       AH,0x1
//         0045ebb4     JZ         LAB_0045ec19
//                               LAB_0045ebb6                                                 XREF[1]:     0045eba7(j)
//                              move_obj.cpp:1650 (33)
//         0045ebb6     FLD        float ptr [ESP + numberFacets]
//         0045ebba     MOV        EAX,dword ptr [ESI + 0x8]
//         0045ebbd     FCOMP      float ptr [DAT_00570b48]
//         0045ebc3     FLD        float ptr [EAX + 0xc4]
//         0045ebc9     FADD       float ptr [ESI + 0x12c]
//         0045ebcf     FNSTSW     AX
//         0045ebd1     FSTP       float ptr [ESI + 0x12c]
//                              move_obj.cpp:1655 (7)
//         0045ebd7     FILD       dword ptr [ESP + local_34]
//         0045ebdb     TEST       AH,0x1
//                              move_obj.cpp:1656 (20)
//         0045ebde     FXCH
//         0045ebe0     JZ         LAB_0045ebf4
//         0045ebe2     FSUB       float ptr [DAT_00570b64]
//         0045ebe8     FXCH
//         0045ebea     FDIVR      double ptr [DAT_00570b40]                        = F1h
//         0045ebf0     FSUBR      float ptr [EDI]
//                              move_obj.cpp:1658 (2)
//         0045ebf2     JMP        LAB_0045ec04
//                               LAB_0045ebf4                                                 XREF[1]:     0045ebe0(j)
//                              move_obj.cpp:1664 (37)
//         0045ebf4     FSUB       float ptr [DAT_00570b60]
//         0045ebfa     FXCH
//         0045ebfc     FDIVR      double ptr [DAT_00570b40]                        = F1h
//         0045ec02     FADD       float ptr [EDI]
//                               LAB_0045ec04                                                 XREF[1]:     0045ebf2(j)
//         0045ec04     FSTP       float ptr [EDI]
//         0045ec06     FLD        float ptr [ESI + 0x12c]
//         0045ec0c     FCOMP      float ptr [DAT_00570b48]
//         0045ec12     FNSTSW     AX
//         0045ec14     TEST       AH,0x41
//         0045ec17     JNZ        LAB_0045eb9c
//                               LAB_0045ec19                                                 XREF[1]:     0045ebb4(j)
//                              move_obj.cpp:1644 (2)
//         0045ec19     FSTP       ST0
//                               LAB_0045ec1b                                                 XREF[1]:     0045eb92(j)
//                              move_obj.cpp:1684 (13)
//         0045ec1b     MOV        this,dword ptr [ESP + local_34]
//         0045ec1f     PUSH       this
//         0045ec20     PUSH       EDI
//         0045ec21     MOV        this,ESI
//         0045ec23     CALL       RGE_Moving_Object::boundAngle                    void boundAngle(RGE_Moving_Object * this, flo
//                              move_obj.cpp:1695 (7)
//         0045ec28     MOV        this,ESI
//         0045ec2a     CALL       RGE_Moving_Object::set_angle                     void set_angle(RGE_Moving_Object * this)
//                              move_obj.cpp:1708 (6)
//         0045ec2f     FLD        float ptr [EDI]
//         0045ec31     FLD        float ptr [EDI]
//         0045ec33     FCOS
//                              move_obj.cpp:1726 (102)
//         0045ec35     MOV        EDX,dword ptr [ESI + 0x8]
//         0045ec38     MOV        this,0x1
//         0045ec3d     FXCH
//         0045ec3f     FSIN
//         0045ec41     FST        float ptr [ESP + newY]
//         0045ec45     FXCH
//         0045ec47     FMUL       float ptr [ESP + newAngle]
//         0045ec4b     FLD        float ptr [ESI + 0x38]
//         0045ec4e     FXCH       ST2
//         0045ec50     FMUL       float ptr [ESP + newAngle]
//         0045ec54     FLD        float ptr [ESI + 0x3c]
//         0045ec57     FXCH       ST2
//         0045ec59     FST        float ptr [ESP + numberFacets]
//         0045ec5d     FXCH
//         0045ec5f     FST        float ptr [ESP + distanceToCover]
//         0045ec63     FXCH
//         0045ec65     FSTP       float ptr [ESI + 0x90]
//         0045ec6b     FSTP       float ptr [ESI + 0x94]
//         0045ec71     FLD        float ptr [EDX + 0x38]
//         0045ec74     FCOMP      float ptr [DAT_00570b48]
//         0045ec7a     FXCH
//         0045ec7c     FADD       float ptr [ESP + numberFacets]
//         0045ec80     FXCH
//         0045ec82     FADD       float ptr [ESP + distanceToCover]
//         0045ec86     FXCH
//         0045ec88     FSTP       float ptr [ESP + newY]
//         0045ec8c     MOV        EBX,dword ptr [ESP + newY]
//         0045ec90     FSTP       float ptr [ESP + dX]
//         0045ec94     FNSTSW     AX
//         0045ec96     TEST       AH,0x41
//         0045ec99     JNZ        LAB_0045ecaf
//                              move_obj.cpp:1730 (20)
//         0045ec9b     MOV        EAX,dword ptr [ESP + dX]
//         0045ec9f     PUSH       this
//         0045eca0     PUSH       EAX
//         0045eca1     PUSH       EBX
//         0045eca2     PUSH       ESI
//         0045eca3     MOV        this,pathSystem
//         0045eca8     CALL       PathingSystem::passable                          int passable(PathingSystem * this, RGE_Moving
//         0045ecad     MOV        this,EAX
//                               LAB_0045ecaf                                                 XREF[1]:     0045ec99(j)
//                              move_obj.cpp:1734 (10)
//         0045ecaf     XOR        EDI,EDI
//         0045ecb1     CMP        this,EDI
//         0045ecb3     JNZ        LAB_0045f55c
//                              move_obj.cpp:1739 (23)
//         0045ecb9     FLD        float ptr [ESI + 0x130]
//         0045ecbf     FCOMP      float ptr [DAT_00570b48]
//         0045ecc5     FNSTSW     AX
//         0045ecc7     TEST       AH,0x40
//         0045ecca     JZ         LAB_0045ed75
//                              move_obj.cpp:1742 (19)
//         0045ecd0     FLD        float ptr [ESI + 0x88]
//         0045ecd6     FCOMP      float ptr [DAT_00570b48]
//         0045ecdc     FNSTSW     AX
//         0045ecde     TEST       AH,0x41
//         0045ece1     JNZ        LAB_0045ed30
//                              move_obj.cpp:1743 (26)
//         0045ece3     PUSH       0x6cf
//         0045ece8     PUSH       s_C:\msdev\work\age1_x1\move_obj.c               = "C:\\msdev\\work\\age1_x1\\move_obj.cpp"
//         0045eced     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         0045ecf2     CDQ
//         0045ecf3     MOV        this,0x6
//         0045ecf8     ADD        ESP,0x8
//         0045ecfb     IDIV       this
//                              move_obj.cpp:2184 (42)
//         0045ecfd     XOR        EAX,EAX
//         0045ecff     MOV        dword ptr [ESP + alreadyMoving],EDX
//         0045ed03     FILD       dword ptr [ESP + alreadyMoving]
//         0045ed07     FMUL       float ptr [DAT_00570bc0]                         = CDh
//         0045ed0d     FLD        float ptr [DAT_00570b80]
//         0045ed13     FDIV       float ptr [ESI + 0x88]
//         0045ed19     MOV        dword ptr [ESI + 0x88],EDI
//         0045ed1f     FSUBP
//         0045ed21     FSTP       float ptr [ESI + 0x130]
//                              move_obj.cpp:2185 (9)
//         0045ed27     POP        EDI
//         0045ed28     POP        ESI
//         0045ed29     POP        EBX
//         0045ed2a     MOV        ESP,EBP
//         0045ed2c     POP        EBP
//         0045ed2d     RET        0x8
//                               LAB_0045ed30                                                 XREF[1]:     0045ece1(j)
//                              move_obj.cpp:1745 (26)
//         0045ed30     PUSH       0x6d1
//         0045ed35     PUSH       s_C:\msdev\work\age1_x1\move_obj.c               = "C:\\msdev\\work\\age1_x1\\move_obj.cpp"
//         0045ed3a     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         0045ed3f     CDQ
//         0045ed40     MOV        this,0x6
//         0045ed45     ADD        ESP,0x8
//         0045ed48     IDIV       this
//                              move_obj.cpp:1747 (6)
//         0045ed4a     MOV        dword ptr [ESI + 0x88],EDI
//                              move_obj.cpp:2184 (28)
//         0045ed50     XOR        EAX,EAX
//         0045ed52     MOV        dword ptr [ESP + alreadyMoving],EDX
//         0045ed56     FILD       dword ptr [ESP + alreadyMoving]
//         0045ed5a     FMUL       float ptr [DAT_00570bc0]                         = CDh
//         0045ed60     FSUB       float ptr [DAT_00570b80]
//         0045ed66     FSTP       float ptr [ESI + 0x130]
//                              move_obj.cpp:2185 (9)
//         0045ed6c     POP        EDI
//         0045ed6d     POP        ESI
//         0045ed6e     POP        EBX
//         0045ed6f     MOV        ESP,EBP
//         0045ed71     POP        EBP
//         0045ed72     RET        0x8
//                               LAB_0045ed75                                                 XREF[1]:     0045ecca(j)
//                              move_obj.cpp:1758 (78)
//         0045ed75     FLD        float ptr [ESI + 0x3c]
//         0045ed78     PUSH       0x1
//         0045ed7a     MOV        dword ptr [ESI + 0x130],EDI
//         0045ed80     SUB        ESP,0x8
//         0045ed83     FSTP       double ptr [ESP]=>local_50+0x4
//         0045ed86     CALL       floor                                            undefined floor()
//         0045ed8b     FSUB       float ptr [DAT_00570b80]
//         0045ed91     FLD        float ptr [ESI + 0x38]
//         0045ed94     FXCH
//         0045ed96     ADD        ESP,0x4
//         0045ed99     FSTP       float ptr [ESP]=>local_48
//         0045ed9c     SUB        ESP,0x8
//         0045ed9f     FSTP       double ptr [ESP]=>local_50
//         0045eda2     CALL       floor                                            undefined floor()
//         0045eda7     FSUB       float ptr [DAT_00570b80]
//         0045edad     ADD        ESP,0x8
//         0045edb0     MOV        this,pathSystem
//         0045edb5     PUSH       this=>pathSystem
//         0045edb6     FSTP       float ptr [ESP]=>local_50+0x4
//         0045edb9     PUSH       ESI
//         0045edba     CALL       PathingSystem::passable                          int passable(PathingSystem * this, RGE_Moving
//         0045edbf     TEST       EAX,EAX
//         0045edc1     JZ         LAB_0045ee07
//                              move_obj.cpp:1759 (68)
//         0045edc3     MOV        EDX,dword ptr [ESI + 0x40]
//         0045edc6     MOV        EBX,dword ptr [ESI]
//         0045edc8     FLD        float ptr [ESI + 0x3c]
//         0045edcb     PUSH       EDX
//         0045edcc     SUB        ESP,0x8
//         0045edcf     FSTP       double ptr [ESP]=>local_50+0x4
//         0045edd2     CALL       floor                                            undefined floor()
//         0045edd7     FSUB       float ptr [DAT_00570b80]
//         0045eddd     FLD        float ptr [ESI + 0x38]
//         0045ede0     FXCH
//         0045ede2     ADD        ESP,0x4
//         0045ede5     FSTP       float ptr [ESP]=>local_48
//         0045ede8     SUB        ESP,0x8
//         0045edeb     FSTP       double ptr [ESP]=>local_50
//         0045edee     CALL       floor                                            undefined floor()
//         0045edf3     FSUB       float ptr [DAT_00570b80]
//         0045edf9     ADD        ESP,0x8
//         0045edfc     MOV        this,ESI
//         0045edfe     PUSH       this
//         0045edff     FSTP       float ptr [ESP]=>local_50+0x4
//         0045ee02     CALL       dword ptr [EBX + 0x34]
//         0045ee05     FSTP       ST0
//                               LAB_0045ee07                                                 XREF[1]:     0045edc1(j)
//                              move_obj.cpp:1771 (15)
//         0045ee07     MOV        EAX,dword ptr [ESI + 0x138]
//         0045ee0d     CMP        EAX,-0x1
//         0045ee10     JZ         LAB_0045eeb2
//                              move_obj.cpp:1772 (12)
//         0045ee16     PUSH       EAX
//         0045ee17     MOV        EAX,dword ptr [ESI + 0xc]
//         0045ee1a     MOV        this,dword ptr [EAX + 0x3c]
//         0045ee1d     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
//                              move_obj.cpp:1773 (8)
//         0045ee22     CMP        EAX,EDI
//         0045ee24     JZ         LAB_0045eeb2
//                              move_obj.cpp:1784 (25)
//         0045ee2a     MOV        this,dword ptr [ESI + 0x8]
//         0045ee2d     FLD        float ptr [ECX + this->_padding_]
//         0045ee30     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0045ee33     FLD        float ptr [EAX + 0x38]
//         0045ee36     FLD        float ptr [EAX + 0x3c]
//         0045ee39     MOV        dword ptr [ESP + 0x1c],EDX
//         0045ee3d     FLD        float ptr [ESP + 0x1c]
//         0045ee41     FLD        ST3
//                              move_obj.cpp:2184 (97)
//         0045ee43     FXCH       ST3
//         0045ee45     FSUB       float ptr [ESI + 0x38]
//         0045ee48     FXCH       ST2
//         0045ee4a     FSUB       float ptr [ESI + 0x3c]
//         0045ee4d     FXCH
//         0045ee4f     FMUL       float ptr [ESP + 0x1c]
//         0045ee53     FXCH       ST3
//         0045ee55     FMUL       ST4
//         0045ee57     FXCH       ST2
//         0045ee59     FST        float ptr [ESP + 0x1c]
//         0045ee5d     FXCH
//         0045ee5f     FST        float ptr [ESP + 0x10]
//         0045ee63     FXCH
//         0045ee65     FMUL       float ptr [ESP + 0x1c]
//         0045ee69     FXCH       ST2
//         0045ee6b     FADDP      ST3,ST0
//         0045ee6d     FMUL       float ptr [ESP + 0x10]
//         0045ee71     FXCH       ST2
//         0045ee73     FSQRT
//         0045ee75     FXCH       ST2
//         0045ee77     FADDP
//         0045ee79     FXCH
//         0045ee7b     FST        float ptr [ESP + 0x1c]
//         0045ee7f     FXCH
//         0045ee81     FSQRT
//         0045ee83     FXCH
//         0045ee85     FADD       float ptr [ESI + 0x134]
//         0045ee8b     FXCH
//         0045ee8d     FST        float ptr [ESP + 0x1c]
//         0045ee91     FXCH
//         0045ee93     FSUB       float ptr [DAT_00570ba8]                         = 9Ah
//         0045ee99     FCOMPP
//         0045ee9b     FNSTSW     AX
//         0045ee9d     TEST       AH,0x41
//         0045eea0     FSTP       ST0
//         0045eea2     JNZ        LAB_0045eeb2
//                              move_obj.cpp:1788 (5)
//         0045eea4     MOV        EAX,0x5
//                              move_obj.cpp:2185 (9)
//         0045eea9     POP        EDI
//         0045eeaa     POP        ESI
//         0045eeab     POP        EBX
//         0045eeac     MOV        ESP,EBP
//         0045eeae     POP        EBP
//         0045eeaf     RET        0x8
//                               LAB_0045eeb2                                                 XREF[3]:     0045ee10(j), 0045ee24(j),
//                                                                                                         0045eea2(j)
//                              move_obj.cpp:1798 (25)
//         0045eeb2     MOV        EAX,dword ptr [EBP + param_2]
//         0045eeb5     MOV        this,dword ptr [EBP + param_1]
//         0045eeb8     PUSH       0x1
//         0045eeba     PUSH       EAX=>DAT_fffffff8
//         0045eebb     PUSH       this=>DAT_fffffff4
//         0045eebc     PUSH       ESI=>DAT_fffffff0
//         0045eebd     MOV        this,pathSystem
//         0045eec2     CALL       PathingSystem::passable                          int passable(PathingSystem * this, RGE_Moving
//         0045eec7     TEST       EAX,EAX
//         0045eec9     JNZ        LAB_0045eed9
//                              move_obj.cpp:1802 (5)
//         0045eecb     MOV        EAX,0x2
//                              move_obj.cpp:2185 (9)
//         0045eed0     POP        EDI
//         0045eed1     POP        ESI
//         0045eed2     POP        EBX
//         0045eed3     MOV        ESP,EBP
//         0045eed5     POP        EBP
//         0045eed6     RET        0x8
//                               LAB_0045eed9                                                 XREF[1]:     0045eec9(j)
//                              move_obj.cpp:1807 (7)
//         0045eed9     MOV        this,dword ptr [ESI + 0x144]
//         0045eedf     DEC        this
//                              move_obj.cpp:1808 (12)
//         0045eee0     MOV        EAX,this
//         0045eee2     MOV        dword ptr [ESI + 0x144],this
//         0045eee8     CMP        EAX,EDI
//         0045eeea     JG         LAB_0045eefa
//                              move_obj.cpp:1813 (5)
//         0045eeec     MOV        EAX,0x4
//                              move_obj.cpp:2185 (9)
//         0045eef1     POP        EDI
//         0045eef2     POP        ESI
//         0045eef3     POP        EBX
//         0045eef4     MOV        ESP,EBP
//         0045eef6     POP        EBP
//         0045eef7     RET        0x8
//                               LAB_0045eefa                                                 XREF[1]:     0045eeea(j)
//                              move_obj.cpp:1818 (21)
//         0045eefa     MOV        this,dword ptr [ESI + 0xc]
//         0045eefd     XOR        EDX,EDX
//         0045eeff     MOV        DL,byte ptr [ESI + 0x156]
//         0045ef05     PUSH       EDX
//         0045ef06     CALL       RGE_Player::availablePathingAttempts             int availablePathingAttempts(RGE_Player * thi
//         0045ef0b     TEST       EAX,EAX
//         0045ef0d     JNZ        LAB_0045ef2b
//                              move_obj.cpp:1822 (14)
//         0045ef0f     MOV        AL,byte ptr [ESI + 0x156]
//         0045ef15     INC        AL
//         0045ef17     MOV        byte ptr [ESI + 0x156],AL
//                              move_obj.cpp:1823 (5)
//         0045ef1d     MOV        EAX,0x1
//                              move_obj.cpp:2185 (9)
//         0045ef22     POP        EDI
//         0045ef23     POP        ESI
//         0045ef24     POP        EBX
//         0045ef25     MOV        ESP,EBP
//         0045ef27     POP        EBP
//         0045ef28     RET        0x8
//                               LAB_0045ef2b                                                 XREF[1]:     0045ef0d(j)
//                              move_obj.cpp:1825 (8)
//         0045ef2b     MOV        this,dword ptr [ESI + 0xc]
//         0045ef2e     CALL       RGE_Player::incrementPathingAttempts             void incrementPathingAttempts(RGE_Player * th
//                              move_obj.cpp:1845 (27)
//         0045ef33     FLD        float ptr [ESI + 0x38]
//         0045ef36     FSTP       float ptr [ESI + 0x10c]
//         0045ef3c     FLD        float ptr [ESI + 0x3c]
//         0045ef3f     FSTP       float ptr [ESI + 0x110]
//         0045ef45     FLD        float ptr [ESI + 0x40]
//         0045ef48     FSTP       float ptr [ESI + 0x114]
//                              move_obj.cpp:1846 (17)
//         0045ef4e     MOV        this,pathSystem
//         0045ef53     MOV        byte ptr [ESI + 0x156],0x0
//         0045ef5a     CALL       PathingSystem::incrementContinuePaths            void incrementContinuePaths(PathingSystem * t
//                              move_obj.cpp:1848 (8)
//         0045ef5f     CMP        dword ptr [ESI + 0x16c],EDI
//         0045ef65     JLE        LAB_0045ef98
//                              move_obj.cpp:1852 (47)
//         0045ef67     MOV        this,dword ptr [ESI + 0x138]
//         0045ef6d     MOV        EDX,dword ptr [ESI + 0x134]
//         0045ef73     MOV        EAX,dword ptr [ESI + 0x168]
//         0045ef79     PUSH       -0x1
//         0045ef7b     PUSH       offset DAT_fffffff8
//         0045ef7d     PUSH       offset DAT_fffffff4
//         0045ef7f     PUSH       offset DAT_fffffff0
//         0045ef81     PUSH       0x1
//         0045ef83     PUSH       0x1
//         0045ef85     PUSH       EDI
//         0045ef86     PUSH       0x1
//         0045ef88     PUSH       this
//         0045ef89     PUSH       EDX
//         0045ef8a     XOR        this,this
//         0045ef8c     MOV        this,byte ptr [EAX + 0x1]
//         0045ef8f     XOR        EDX,EDX
//         0045ef91     MOV        DL,byte ptr [EAX]
//         0045ef93     PUSH       ESI
//         0045ef94     PUSH       this
//         0045ef95     PUSH       EDX
//                              move_obj.cpp:1853 (2)
//         0045ef96     JMP        LAB_0045efce
//                               LAB_0045ef98                                                 XREF[1]:     0045ef65(j)
//                              move_obj.cpp:1857 (92)
//         0045ef98     MOV        EAX,dword ptr [ESI + 0x138]
//         0045ef9e     MOV        this,dword ptr [ESI + 0x134]
//         0045efa4     PUSH       -0x1
//         0045efa6     PUSH       offset DAT_fffffff8
//         0045efa8     FLD        float ptr [ESI + 0x120]
//         0045efae     PUSH       offset DAT_fffffff4
//         0045efb0     PUSH       offset DAT_fffffff0
//         0045efb2     PUSH       0x1
//         0045efb4     PUSH       0x1
//         0045efb6     PUSH       EDI
//         0045efb7     PUSH       0x1
//         0045efb9     PUSH       EAX
//         0045efba     PUSH       this
//         0045efbb     PUSH       ESI
//         0045efbc     CALL       __ftol                                           undefined __ftol()
//         0045efc1     FLD        float ptr [ESI + 0x11c]
//         0045efc7     PUSH       EAX
//         0045efc8     CALL       __ftol                                           undefined __ftol()
//         0045efcd     PUSH       EAX
//                               LAB_0045efce                                                 XREF[1]:     0045ef96(j)
//         0045efce     FLD        float ptr [ESI + 0x110]
//         0045efd4     CALL       __ftol                                           undefined __ftol()
//         0045efd9     FLD        float ptr [ESI + 0x10c]
//         0045efdf     PUSH       EAX
//         0045efe0     CALL       __ftol                                           undefined __ftol()
//         0045efe5     PUSH       EAX
//         0045efe6     MOV        this,pathSystem
//         0045efeb     CALL       PathingSystem::findTilePath                      int findTilePath(PathingSystem * this, int pa
//         0045eff0     MOV        dword ptr [ESP + 0x1c],EAX
//                              move_obj.cpp:1862 (13)
//         0045eff4     MOV        EAX,[actionFile]                                 = 00000000
//         0045eff9     CMP        EAX,EDI
//         0045effb     JZ         LAB_0045f0cf
//                              move_obj.cpp:1864 (73)
//         0045f001     FLD        float ptr [ESI + 0x120]
//         0045f007     SUB        ESP,0x8
//         0045f00a     MOV        EDX,dword ptr [ESI + 0x4]
//         0045f00d     MOV        this,dword ptr [ESI + 0xc]
//         0045f010     FSTP       double ptr [ESP]=>DAT_fffffff8
//         0045f013     FLD        float ptr [ESI + 0x11c]
//         0045f019     SUB        ESP,0x8
//         0045f01c     FSTP       double ptr [ESP]=>DAT_fffffff0
//         0045f01f     FLD        float ptr [ESI + 0x110]
//         0045f025     SUB        ESP,0x8
//         0045f028     FSTP       double ptr [ESP]
//         0045f02b     FLD        float ptr [ESI + 0x10c]
//         0045f031     SUB        ESP,0x8
//         0045f034     FSTP       double ptr [ESP]
//         0045f037     PUSH       EDX
//         0045f038     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0045f03b     MOV        this,dword ptr [EDX + 0x4]
//         0045f03e     PUSH       this
//         0045f03f     PUSH       s_t%ld_uID=%d,_fP1_s=(%6.2f,%6.2f)               = "t%ld uID=%d, fP1 s=(%6.2f,%6.2f), g=(%6.2f
//         0045f044     PUSH       EAX
//         0045f045     CALL       fprintf                                          undefined fprintf()
//                              move_obj.cpp:1865 (16)
//         0045f04a     LEA        EDI,[ESI + 0xa4]
//         0045f050     ADD        ESP,0x30
//         0045f053     MOV        this,EDI
//         0045f055     CALL       Path::initToStart                                void initToStart(Path * this)
//                              move_obj.cpp:1866 (13)
//         0045f05a     MOV        this,EDI
//         0045f05c     XOR        EBX,EBX
//         0045f05e     CALL       Path::numberOfWaypoints                          int numberOfWaypoints(Path * this)
//         0045f063     TEST       EAX,EAX
//         0045f065     JLE        LAB_0045f0ae
//                               LAB_0045f067                                                 XREF[1]:     0045f0ac(j)
//                              move_obj.cpp:1867 (71)
//         0045f067     MOV        this,EDI
//         0045f069     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         0045f06e     FLD        float ptr [EAX + 0x4]
//         0045f071     SUB        ESP,0x8
//         0045f074     MOV        this,EDI
//         0045f076     FSTP       double ptr [ESP]=>DAT_fffffff8
//         0045f079     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         0045f07e     FLD        float ptr [EAX]
//         0045f080     MOV        EDX,dword ptr [actionFile]                       = 00000000
//         0045f086     SUB        ESP,0x8
//         0045f089     FSTP       double ptr [ESP]=>DAT_fffffff0
//         0045f08c     PUSH       EBX
//         0045f08d     PUSH       s_,_WP#%d(%6.2f,_%6.2f)                          = ", WP#%d(%6.2f, %6.2f)"
//         0045f092     PUSH       EDX
//         0045f093     CALL       fprintf                                          undefined fprintf()
//         0045f098     ADD        ESP,0x1c
//         0045f09b     MOV        this,EDI
//         0045f09d     INC        EBX
//         0045f09e     CALL       Path::moveToNextWaypoint                         int moveToNextWaypoint(Path * this)
//         0045f0a3     MOV        this,EDI
//         0045f0a5     CALL       Path::numberOfWaypoints                          int numberOfWaypoints(Path * this)
//         0045f0aa     CMP        EBX,EAX
//         0045f0ac     JL         LAB_0045f067
//                               LAB_0045f0ae                                                 XREF[1]:     0045f065(j)
//                              move_obj.cpp:1868 (19)
//         0045f0ae     MOV        EAX,[actionFile]                                 = 00000000
//         0045f0b3     PUSH       s_._                                             = ".\n"
//         0045f0b8     PUSH       EAX=>DAT_fffffff8
//         0045f0b9     CALL       fprintf                                          undefined fprintf()
//         0045f0be     ADD        ESP,0x8
//                              move_obj.cpp:1869 (7)
//         0045f0c1     MOV        this,EDI
//         0045f0c3     CALL       Path::initToStart                                void initToStart(Path * this)
//                              move_obj.cpp:1870 (7)
//         0045f0c8     MOV        this,EDI
//         0045f0ca     CALL       Path::moveToNextWaypoint                         int moveToNextWaypoint(Path * this)
//                               LAB_0045f0cf                                                 XREF[1]:     0045effb(j)
//                              move_obj.cpp:1891 (107)
//         0045f0cf     MOV        EAX,dword ptr [ESP + 0x1c]
//         0045f0d3     TEST       EAX,EAX
//         0045f0d5     JNZ        LAB_0045f1e0
//         0045f0db     LEA        this,[ESI + 0xa4]
//         0045f0e1     CALL       Path::numberOfWaypoints                          int numberOfWaypoints(Path * this)
//         0045f0e6     CMP        EAX,0x1
//         0045f0e9     JNZ        LAB_0045f1e0
//         0045f0ef     FLD        float ptr [ESI + 0x3c]
//         0045f0f2     PUSH       EAX
//         0045f0f3     SUB        ESP,0x8
//         0045f0f6     FSTP       double ptr [ESP]=>DAT_fffffff4
//         0045f0f9     CALL       floor                                            undefined floor()
//         0045f0fe     FSUB       float ptr [DAT_00570b80]
//         0045f104     FLD        float ptr [ESI + 0x38]
//         0045f107     FXCH
//         0045f109     ADD        ESP,0x4
//         0045f10c     FSTP       float ptr [ESP]=>DAT_fffffff8
//         0045f10f     SUB        ESP,0x8
//         0045f112     FSTP       double ptr [ESP]=>DAT_fffffff0
//         0045f115     CALL       floor                                            undefined floor()
//         0045f11a     FSUB       float ptr [DAT_00570b80]
//         0045f120     ADD        ESP,0x8
//         0045f123     MOV        this,pathSystem
//         0045f128     PUSH       this=>pathSystem
//         0045f129     FSTP       float ptr [ESP]=>DAT_fffffff4
//         0045f12c     PUSH       ESI=>DAT_fffffff0
//         0045f12d     CALL       PathingSystem::passable                          int passable(PathingSystem * this, RGE_Moving
//         0045f132     TEST       EAX,EAX
//         0045f134     JZ         LAB_0045f1e0
//                              move_obj.cpp:1899 (84)
//         0045f13a     FLD        float ptr [ESI + 0x38]
//         0045f13d     FSTP       double ptr [ESP + 0x30]
//         0045f141     MOV        this,dword ptr [ESP + 0x34]
//         0045f145     MOV        EDX,dword ptr [ESP + 0x30]
//         0045f149     PUSH       this
//         0045f14a     PUSH       EDX=>DAT_fffffff8
//         0045f14b     CALL       floor                                            undefined floor()
//         0045f150     FSUBR      double ptr [ESP + 0x38]
//         0045f154     ADD        ESP,0x8
//         0045f157     FCOMP      double ptr [DAT_00570b90]
//         0045f15d     FNSTSW     AX
//         0045f15f     TEST       AH,0x40
//         0045f162     JZ         LAB_0045f19c
//         0045f164     FLD        float ptr [ESI + 0x3c]
//         0045f167     FSTP       double ptr [ESP + 0x30]
//         0045f16b     MOV        EAX,dword ptr [ESP + 0x34]
//         0045f16f     MOV        this,dword ptr [ESP + 0x30]
//         0045f173     PUSH       EAX
//         0045f174     PUSH       this=>DAT_fffffff8
//         0045f175     CALL       floor                                            undefined floor()
//         0045f17a     FSUBR      double ptr [ESP + 0x38]
//         0045f17e     ADD        ESP,0x8
//         0045f181     FCOMP      double ptr [DAT_00570b90]
//         0045f187     FNSTSW     AX
//         0045f189     TEST       AH,0x40
//         0045f18c     JZ         LAB_0045f19c
//                              move_obj.cpp:1906 (5)
//         0045f18e     MOV        EAX,0x4
//                              move_obj.cpp:2185 (9)
//         0045f193     POP        EDI
//         0045f194     POP        ESI
//         0045f195     POP        EBX
//         0045f196     MOV        ESP,EBP
//         0045f198     POP        EBP
//         0045f199     RET        0x8
//                               LAB_0045f19c                                                 XREF[2]:     0045f162(j), 0045f18c(j)
//                              move_obj.cpp:1900 (68)
//         0045f19c     MOV        EDX,dword ptr [ESI + 0x40]
//         0045f19f     MOV        EDI,dword ptr [ESI]
//         0045f1a1     FLD        float ptr [ESI + 0x3c]
//         0045f1a4     PUSH       EDX
//         0045f1a5     SUB        ESP,0x8
//         0045f1a8     FSTP       double ptr [ESP]=>DAT_fffffff4
//         0045f1ab     CALL       floor                                            undefined floor()
//         0045f1b0     FSUB       float ptr [DAT_00570b80]
//         0045f1b6     FLD        float ptr [ESI + 0x38]
//         0045f1b9     FXCH
//         0045f1bb     ADD        ESP,0x4
//         0045f1be     FSTP       float ptr [ESP]=>DAT_fffffff8
//         0045f1c1     SUB        ESP,0x8
//         0045f1c4     FSTP       double ptr [ESP]=>DAT_fffffff0
//         0045f1c7     CALL       floor                                            undefined floor()
//         0045f1cc     FSUB       float ptr [DAT_00570b80]
//         0045f1d2     ADD        ESP,0x8
//         0045f1d5     MOV        this,ESI
//         0045f1d7     PUSH       this=>DAT_fffffff4
//         0045f1d8     FSTP       float ptr [ESP]=>DAT_fffffff4
//         0045f1db     CALL       dword ptr [EDI + 0x34]
//         0045f1de     FSTP       ST0
//                               LAB_0045f1e0                                                 XREF[3]:     0045f0d5(j), 0045f0e9(j),
//                                                                                                         0045f134(j)
//                              move_obj.cpp:1909 (180)
//         0045f1e0     MOV        EAX,[displayPathingFlags]
//         0045f1e5     MOV        EBX,dword ptr [displayPathObjectID]              = 53h
//         0045f1eb     TEST       EAX,EAX
//         0045f1ed     JZ         LAB_0045f294
//         0045f1f3     TEST       byte ptr [ESI + 0x36],0x1
//         0045f1f7     JZ         LAB_0045f294
//         0045f1fd     LEA        EDI,[ESI + 0xa4]
//         0045f203     MOV        this,EDI
//         0045f205     CALL       Path::initToStart                                void initToStart(Path * this)
//         0045f20a     MOV        this,EDI
//         0045f20c     MOV        dword ptr [ESP + 0x1c],0x0
//         0045f214     CALL       Path::numberOfWaypoints                          int numberOfWaypoints(Path * this)
//         0045f219     TEST       EAX,EAX
//         0045f21b     JLE        LAB_0045f286
//         0045f21d     SHL        EBX,0x2
//         0045f220     MOV        dword ptr [ESP + 0x30],EBX
//                               LAB_0045f224                                                 XREF[1]:     0045f284(j)
//         0045f224     MOV        EAX,dword ptr [ESI + 0xc]
//         0045f227     PUSH       0x3f800000
//         0045f22c     MOV        this,EAX
//         0045f22e     MOV        dword ptr [ESP + 0x14],EAX
//         0045f232     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0045f235     MOV        this,EDI
//         0045f237     MOV        EAX,dword ptr [EDX + EBX*0x1]
//         0045f23a     MOV        EBX,dword ptr [EAX]
//         0045f23c     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         0045f241     MOV        this,dword ptr [EAX + 0x4]
//         0045f244     PUSH       this=>DAT_fffffff8
//         0045f245     MOV        this,EDI
//         0045f247     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         0045f24c     MOV        EDX,dword ptr [EAX]
//         0045f24e     MOV        EAX,dword ptr [ESP + 0x18]
//         0045f252     PUSH       EDX=>DAT_fffffff4
//         0045f253     PUSH       EAX=>DAT_fffffff0
//         0045f254     MOV        EAX,dword ptr [EAX + 0x24]
//         0045f257     MOV        dword ptr [ESP + 0x20],EBX
//         0045f25b     MOV        EBX,dword ptr [ESP + 0x40]
//         0045f25f     MOV        EDX,dword ptr [ESP + 0x20]
//         0045f263     MOV        this,dword ptr [EAX + EBX*0x1]
//         0045f266     CALL       dword ptr [EDX + 0x18]
//         0045f269     MOV        EDX,dword ptr [ESP + 0x1c]
//         0045f26d     MOV        this,EDI
//         0045f26f     INC        EDX
//         0045f270     MOV        dword ptr [ESP + 0x1c],EDX
//         0045f274     CALL       Path::moveToNextWaypoint                         int moveToNextWaypoint(Path * this)
//         0045f279     MOV        this,EDI
//         0045f27b     CALL       Path::numberOfWaypoints                          int numberOfWaypoints(Path * this)
//         0045f280     CMP        dword ptr [ESP + 0x1c],EAX
//         0045f284     JL         LAB_0045f224
//                               LAB_0045f286                                                 XREF[1]:     0045f21b(j)
//         0045f286     MOV        this,EDI
//         0045f288     CALL       Path::initToStart                                void initToStart(Path * this)
//         0045f28d     MOV        this,EDI
//         0045f28f     CALL       Path::moveToNextWaypoint                         int moveToNextWaypoint(Path * this)
//                               LAB_0045f294                                                 XREF[2]:     0045f1ed(j), 0045f1f7(j)
//                              move_obj.cpp:1913 (13)
//         0045f294     LEA        EDI,[ESI + 0xa4]
//         0045f29a     MOV        this,EDI
//         0045f29c     CALL       Path::initToStart                                void initToStart(Path * this)
//                              move_obj.cpp:1914 (11)
//         0045f2a1     MOV        this,EDI
//         0045f2a3     CALL       Path::moveToNextWaypoint                         int moveToNextWaypoint(Path * this)
//         0045f2a8     TEST       EAX,EAX
//         0045f2aa     JNZ        LAB_0045f2ba
//                              move_obj.cpp:1918 (5)
//         0045f2ac     MOV        EAX,0x4
//                              move_obj.cpp:2185 (9)
//         0045f2b1     POP        EDI
//         0045f2b2     POP        ESI
//         0045f2b3     POP        EBX
//         0045f2b4     MOV        ESP,EBP
//         0045f2b6     POP        EBP
//         0045f2b7     RET        0x8
//                               LAB_0045f2ba                                                 XREF[1]:     0045f2aa(j)
//                              move_obj.cpp:1927 (17)
//         0045f2ba     MOV        EAX,dword ptr [ESP + 0x28]
//         0045f2be     MOV        dword ptr [ESI + 0x178],0x47c35000
//         0045f2c8     CMP        EAX,0x1
//                              move_obj.cpp:1929 (14)
//         0045f2cb     MOV        this,EDI
//         0045f2cd     JNZ        LAB_0045f2ec
//         0045f2cf     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         0045f2d4     FLD        float ptr [EAX]
//         0045f2d6     FSUB       float ptr [ESI + 0x38]
//                              move_obj.cpp:1930 (17)
//         0045f2d9     MOV        this,EDI
//         0045f2db     FSTP       float ptr [ESP + 0x10]
//         0045f2df     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         0045f2e4     FLD        float ptr [EAX + 0x4]
//         0045f2e7     FSUB       float ptr [ESI + 0x3c]
//                              move_obj.cpp:1932 (2)
//         0045f2ea     JMP        LAB_0045f333
//                               LAB_0045f2ec                                                 XREF[1]:     0045f2cd(j)
//                              move_obj.cpp:1934 (30)
//         0045f2ec     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         0045f2f1     FLD        float ptr [ESI + 0x38]
//         0045f2f4     SUB        ESP,0x8
//         0045f2f7     MOV        EBX,EAX
//         0045f2f9     FSTP       double ptr [ESP]=>DAT_fffffff8
//         0045f2fc     CALL       floor                                            undefined floor()
//         0045f301     FSUB       float ptr [DAT_00570b80]
//         0045f307     ADD        ESP,0x8
//                              move_obj.cpp:1935 (41)
//         0045f30a     MOV        this,EDI
//         0045f30c     FSUBR      float ptr [EBX]
//         0045f30e     FSTP       float ptr [ESP + 0x10]
//         0045f312     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         0045f317     FLD        float ptr [ESI + 0x3c]
//         0045f31a     SUB        ESP,0x8
//         0045f31d     MOV        EDI,EAX
//         0045f31f     FSTP       double ptr [ESP]=>DAT_fffffff8
//         0045f322     CALL       floor                                            undefined floor()
//         0045f327     FSUB       float ptr [DAT_00570b80]
//         0045f32d     ADD        ESP,0x8
//         0045f330     FSUBR      float ptr [EDI + 0x4]
//                               LAB_0045f333                                                 XREF[1]:     0045f2ea(j)
//                              move_obj.cpp:1938 (6)
//         0045f333     FLD        float ptr [ESP + 0x10]
//         0045f337     FPATAN
//                              move_obj.cpp:1939 (18)
//         0045f339     LEA        EAX,[ESP + 0x14]
//         0045f33d     PUSH       -0x1
//         0045f33f     PUSH       EAX=>DAT_fffffff8
//         0045f340     MOV        this,ESI
//         0045f342     FSTP       float ptr [ESP + 0x1c]
//         0045f346     CALL       RGE_Moving_Object::boundAngle                    void boundAngle(RGE_Moving_Object * this, flo
//                              move_obj.cpp:1940 (10)
//         0045f34b     FLD        float ptr [ESP + 0x14]
//         0045f34f     FSUB       float ptr [ESI + 0x9c]
//                              move_obj.cpp:1943 (41)
//         0045f355     FLD        float ptr [ESI + 0x12c]
//         0045f35b     FCOMP      float ptr [DAT_00570b48]
//         0045f361     LEA        EDI,[ESI + 0x9c]
//         0045f367     FST        float ptr [ESP + 0x10]
//         0045f36b     FMUL       float ptr [ESP + 0x2c]
//         0045f36f     FNSTSW     AX
//         0045f371     FMUL       float ptr [DAT_00570b78]                         = 83h
//         0045f377     TEST       AH,0x41
//         0045f37a     JNZ        LAB_0045f393
//         0045f37c     FSTP       ST0
//                              move_obj.cpp:1947 (10)
//         0045f37e     MOV        dword ptr [ESI + 0x88],0x0
//                              move_obj.cpp:2184 (2)
//         0045f388     XOR        EAX,EAX
//                              move_obj.cpp:2185 (9)
//         0045f38a     POP        EDI
//         0045f38b     POP        ESI
//         0045f38c     POP        EBX
//         0045f38d     MOV        ESP,EBP
//         0045f38f     POP        EBP
//         0045f390     RET        0x8
//                               LAB_0045f393                                                 XREF[2]:     0045f37a(j), 0045f40e(j)
//                              move_obj.cpp:1950 (26)
//         0045f393     FCOM       double ptr [DAT_00570bc8]                        = CDh
//         0045f399     FNSTSW     AX
//         0045f39b     TEST       AH,0x41
//         0045f39e     JZ         LAB_0045f3ad
//         0045f3a0     FCOM       double ptr [DAT_00570bd0]                        = CDh
//         0045f3a6     FNSTSW     AX
//         0045f3a8     TEST       AH,0x1
//         0045f3ab     JZ         LAB_0045f410
//                               LAB_0045f3ad                                                 XREF[1]:     0045f39e(j)
//                              move_obj.cpp:1955 (33)
//         0045f3ad     FLD        float ptr [ESP + 0x10]
//         0045f3b1     MOV        this,dword ptr [ESI + 0x8]
//         0045f3b4     FCOMP      float ptr [DAT_00570b48]
//         0045f3ba     FLD        float ptr [ECX + this+0xc4]
//         0045f3c0     FADD       float ptr [ESI + 0x12c]
//         0045f3c6     FNSTSW     AX
//         0045f3c8     FSTP       float ptr [ESI + 0x12c]
//                              move_obj.cpp:1956 (7)
//         0045f3ce     FILD       dword ptr [ESP + 0xc]
//         0045f3d2     TEST       AH,0x1
//                              move_obj.cpp:1957 (20)
//         0045f3d5     FXCH
//         0045f3d7     JZ         LAB_0045f3eb
//         0045f3d9     FSUB       float ptr [DAT_00570b64]
//         0045f3df     FXCH
//         0045f3e1     FDIVR      double ptr [DAT_00570b40]                        = F1h
//         0045f3e7     FSUBR      float ptr [EDI]
//                              move_obj.cpp:1960 (2)
//         0045f3e9     JMP        LAB_0045f3fb
//                               LAB_0045f3eb                                                 XREF[1]:     0045f3d7(j)
//                              move_obj.cpp:1962 (37)
//         0045f3eb     FSUB       float ptr [DAT_00570b60]
//         0045f3f1     FXCH
//         0045f3f3     FDIVR      double ptr [DAT_00570b40]                        = F1h
//         0045f3f9     FADD       float ptr [EDI]
//                               LAB_0045f3fb                                                 XREF[1]:     0045f3e9(j)
//         0045f3fb     FSTP       float ptr [EDI]
//         0045f3fd     FLD        float ptr [ESI + 0x12c]
//         0045f403     FCOMP      float ptr [DAT_00570b48]
//         0045f409     FNSTSW     AX
//         0045f40b     TEST       AH,0x41
//         0045f40e     JNZ        LAB_0045f393
//                               LAB_0045f410                                                 XREF[1]:     0045f3ab(j)
//                              move_obj.cpp:1967 (15)
//         0045f410     MOV        EDX,dword ptr [ESP + 0xc]
//         0045f414     MOV        this,ESI
//         0045f416     PUSH       EDX
//         0045f417     PUSH       EDI=>DAT_fffffff8
//         0045f418     FSTP       ST0
//         0045f41a     CALL       RGE_Moving_Object::boundAngle                    void boundAngle(RGE_Moving_Object * this, flo
//                              move_obj.cpp:1969 (7)
//         0045f41f     MOV        this,ESI
//         0045f421     CALL       RGE_Moving_Object::set_angle                     void set_angle(RGE_Moving_Object * this)
//                              move_obj.cpp:1977 (6)
//         0045f426     FLD        float ptr [EDI]
//         0045f428     FLD        float ptr [EDI]
//         0045f42a     FSIN
//                              move_obj.cpp:1991 (125)
//         0045f42c     PUSH       0x1
//         0045f42e     MOV        this,pathSystem
//         0045f433     FXCH
//         0045f435     FCOS
//         0045f437     FXCH
//         0045f439     FMUL       float ptr [ESP + 0x1c]
//         0045f43d     FXCH
//         0045f43f     FST        float ptr [ESP + 0x34]
//         0045f443     FMUL       float ptr [ESP + 0x1c]
//         0045f447     FLD        float ptr [ESI + 0x3c]
//         0045f44a     FLD        float ptr [ESI + 0x38]
//         0045f44d     FXCH       ST3
//         0045f44f     FSTP       float ptr [ESP + 0x20]
//         0045f453     FADD       float ptr [ESP + 0x20]
//         0045f457     FXCH
//         0045f459     FSTP       float ptr [ESP + 0x14]
//         0045f45d     FXCH
//         0045f45f     FADD       float ptr [ESP + 0x14]
//         0045f463     FLD        float ptr [ESP + 0x14]
//         0045f467     FXCH       ST2
//         0045f469     FSTP       float ptr [ESP + 0x30]
//         0045f46d     MOV        EAX,dword ptr [ESP + 0x30]
//         0045f471     FLD        float ptr [ESP + 0x20]
//         0045f475     FXCH
//         0045f477     FSTP       float ptr [ESP + 0x30]
//         0045f47b     MOV        EDX,EAX
//         0045f47d     PUSH       EAX=>DAT_fffffff8
//         0045f47e     MOV        dword ptr [ESP + 0x28],EDX
//         0045f482     MOV        EDX,dword ptr [ESP + 0x34]
//         0045f486     FXCH
//         0045f488     FSTP       float ptr [ESI + 0x90]
//         0045f48e     MOV        EAX,EDX
//         0045f490     PUSH       EDX=>DAT_fffffff4
//         0045f491     FSTP       float ptr [ESI + 0x94]
//         0045f497     PUSH       ESI=>DAT_fffffff0
//         0045f498     MOV        dword ptr [ESP + 0x34],EAX
//         0045f49c     CALL       PathingSystem::passable                          int passable(PathingSystem * this, RGE_Moving
//         0045f4a1     TEST       EAX,EAX
//         0045f4a3     JNZ        LAB_0045f558
//                              move_obj.cpp:1993 (13)
//         0045f4a9     MOV        this,dword ptr [ESI + 0xc]
//         0045f4ac     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
//         0045f4b1     CMP        EAX,0x1
//         0045f4b4     JNZ        LAB_0045f4c4
//                              move_obj.cpp:1998 (5)
//         0045f4b6     MOV        EAX,0x4
//                              move_obj.cpp:2185 (9)
//         0045f4bb     POP        EDI
//         0045f4bc     POP        ESI
//         0045f4bd     POP        EBX
//         0045f4be     MOV        ESP,EBP
//         0045f4c0     POP        EBP
//         0045f4c1     RET        0x8
//                               LAB_0045f4c4                                                 XREF[1]:     0045f4b4(j)
//                              move_obj.cpp:2002 (19)
//         0045f4c4     FLD        float ptr [ESI + 0x88]
//         0045f4ca     FCOMP      float ptr [DAT_00570b48]
//         0045f4d0     FNSTSW     AX
//         0045f4d2     TEST       AH,0x41
//         0045f4d5     JNZ        LAB_0045f50f
//                              language.dll match for 0x7d3: "Could not initialize graphics
//                              move_obj.cpp:2003 (54)
//         0045f4d7     PUSH       0x7d3
//         0045f4dc     PUSH       s_C:\msdev\work\age1_x1\move_obj.c               = "C:\\msdev\\work\\age1_x1\\move_obj.cpp"
//         0045f4e1     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         0045f4e6     CDQ
//         0045f4e7     MOV        this,0x6
//         0045f4ec     ADD        ESP,0x8
//         0045f4ef     IDIV       this
//         0045f4f1     MOV        dword ptr [ESP + 0x30],EDX
//         0045f4f5     FILD       dword ptr [ESP + 0x30]
//         0045f4f9     FMUL       float ptr [DAT_00570bc0]                         = CDh
//         0045f4ff     FLD        float ptr [DAT_00570b80]
//         0045f505     FDIV       float ptr [ESI + 0x88]
//         0045f50b     FSUBP
//                              move_obj.cpp:2004 (2)
//         0045f50d     JMP        LAB_0045f53d
//                              language.dll match for 0x7d5: "Could not initialize communica
//                               LAB_0045f50f                                                 XREF[1]:     0045f4d5(j)
//                              move_obj.cpp:2005 (52)
//         0045f50f     PUSH       0x7d5
//         0045f514     PUSH       s_C:\msdev\work\age1_x1\move_obj.c               = "C:\\msdev\\work\\age1_x1\\move_obj.cpp"
//         0045f519     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         0045f51e     CDQ
//         0045f51f     MOV        this,0x6
//         0045f524     ADD        ESP,0x8
//         0045f527     IDIV       this
//         0045f529     MOV        dword ptr [ESP + 0x30],EDX
//         0045f52d     FILD       dword ptr [ESP + 0x30]
//         0045f531     FMUL       float ptr [DAT_00570bc0]                         = CDh
//         0045f537     FSUB       float ptr [DAT_00570b80]
//                               LAB_0045f53d                                                 XREF[1]:     0045f50d(j)
//         0045f53d     FSTP       float ptr [ESI + 0x130]
//                              move_obj.cpp:2007 (10)
//         0045f543     MOV        dword ptr [ESI + 0x88],0x0
//                              move_obj.cpp:2184 (2)
//         0045f54d     XOR        EAX,EAX
//                              move_obj.cpp:2185 (9)
//         0045f54f     POP        EDI
//         0045f550     POP        ESI
//         0045f551     POP        EBX
//         0045f552     MOV        ESP,EBP
//         0045f554     POP        EBP
//         0045f555     RET        0x8
//                               LAB_0045f558                                                 XREF[1]:     0045f4a3(j)
//                              move_obj.cpp:2011 (4)
//         0045f558     MOV        EBX,dword ptr [ESP + 0x24]
//                               LAB_0045f55c                                                 XREF[1]:     0045ecb3(j)
//                              move_obj.cpp:2049 (3)
//         0045f55c     MOV        EDX,dword ptr [ESI + 0x40]
//                              move_obj.cpp:2064 (25)
//         0045f55f     LEA        EDI,[ESI + 0xa4]
//         0045f565     MOV        this,EDI
//         0045f567     MOV        dword ptr [ESP + curDistance],EDX
//         0045f56b     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         0045f570     TEST       EAX,EAX
//         0045f572     JZ         LAB_0045f6ba
//                              move_obj.cpp:2066 (7)
//         0045f578     MOV        this,EDI
//         0045f57a     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//                              move_obj.cpp:2067 (16)
//         0045f57f     FLD        float ptr [EAX]
//         0045f581     FSUB       float ptr [ESI + 0x38]
//         0045f584     MOV        this,EDI
//         0045f586     FSTP       float ptr [ESP + 0x1c]
//         0045f58a     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//                              move_obj.cpp:2069 (34)
//         0045f58f     FLD        float ptr [ESP + 0x1c]
//         0045f593     FLD        float ptr [EAX + 0x4]
//         0045f596     FSUB       float ptr [ESI + 0x3c]
//         0045f599     FLD        ST1
//         0045f59b     FMUL       ST2
//         0045f59d     FXCH
//         0045f59f     FST        float ptr [ESP + 0x2c]
//         0045f5a3     FMUL       float ptr [ESP + 0x2c]
//         0045f5a7     MOV        this,EDI
//         0045f5a9     FADDP
//         0045f5ab     FSQRT
//         0045f5ad     FSTP       float ptr [ESP + 0x24]
//                              move_obj.cpp:2134 (109)
//         0045f5b1     FSTP       ST0
//         0045f5b3     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         0045f5b8     FLD        float ptr [ESI + 0x38]
//         0045f5bb     FADD       float ptr [ESI + 0x90]
//         0045f5c1     MOV        this,EDI
//         0045f5c3     FSUBR      float ptr [EAX]
//         0045f5c5     FSTP       float ptr [ESP + 0x1c]
//         0045f5c9     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         0045f5ce     FLD        float ptr [ESI + 0x3c]
//         0045f5d1     FADD       float ptr [ESI + 0x94]
//         0045f5d7     FLD        float ptr [ESP + 0x1c]
//         0045f5db     FXCH
//         0045f5dd     FSUBR      float ptr [EAX + 0x4]
//         0045f5e0     FXCH
//         0045f5e2     FST        double ptr [ESP + 0x30]
//         0045f5e6     FLD        ST1
//         0045f5e8     FXCH
//         0045f5ea     FMUL       double ptr [ESP + 0x30]
//         0045f5ee     FLD        float ptr [ESI + 0x178]
//         0045f5f4     FXCH       ST2
//         0045f5f6     FMUL       ST3
//         0045f5f8     FADDP
//         0045f5fa     FSQRT
//         0045f5fc     FST        float ptr [ESP + 0x30]
//         0045f600     FXCH
//         0045f602     FCOMPP
//         0045f604     FNSTSW     AX
//         0045f606     TEST       AH,0x1
//         0045f609     FSTP       ST0
//         0045f60b     JZ         LAB_0045f61e
//         0045f60d     FLD        float ptr [ESP + 0x24]
//         0045f611     FCOMP      float ptr [DAT_00570bd8]
//         0045f617     FNSTSW     AX
//         0045f619     TEST       AH,0x1
//         0045f61c     JNZ        LAB_0045f644
//                               LAB_0045f61e                                                 XREF[1]:     0045f60b(j)
//                              move_obj.cpp:2086 (38)
//         0045f61e     MOV        AL,byte ptr [ESI + 0x17d]
//         0045f624     MOV        this,byte ptr [ESI + 0x35]
//         0045f627     CMP        AL,this
//         0045f629     JNZ        LAB_0045f6a1
//         0045f62b     CMP        AL,byte ptr [ESI + 0x17c]
//         0045f631     JZ         LAB_0045f6a1
//         0045f633     FLD        float ptr [ESP + 0x24]
//         0045f637     FCOMP      float ptr [DAT_00570b7c]
//         0045f63d     FNSTSW     AX
//         0045f63f     TEST       AH,0x1
//         0045f642     JZ         LAB_0045f6a1
//                               LAB_0045f644                                                 XREF[1]:     0045f61c(j)
//                              move_obj.cpp:2092 (38)
//         0045f644     PUSH       0x1
//         0045f646     MOV        this,EDI
//         0045f648     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         0045f64d     MOV        EAX,dword ptr [EAX + 0x4]
//         0045f650     MOV        this,EDI
//         0045f652     PUSH       EAX=>DAT_fffffff8
//         0045f653     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         0045f658     MOV        this,dword ptr [EAX]
//         0045f65a     PUSH       this=>DAT_fffffff4
//         0045f65b     PUSH       ESI=>DAT_fffffff0
//         0045f65c     MOV        this,pathSystem
//         0045f661     CALL       PathingSystem::passable                          int passable(PathingSystem * this, RGE_Moving
//         0045f666     TEST       EAX,EAX
//         0045f668     JZ         LAB_0045f693
//                              move_obj.cpp:2097 (39)
//         0045f66a     MOV        EBX,dword ptr [ESI]
//         0045f66c     MOV        this,EDI
//         0045f66e     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         0045f673     MOV        EDX,dword ptr [EAX + 0x8]
//         0045f676     MOV        this,EDI
//         0045f678     PUSH       EDX
//         0045f679     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         0045f67e     MOV        EAX,dword ptr [EAX + 0x4]
//         0045f681     MOV        this,EDI
//         0045f683     PUSH       EAX=>DAT_fffffff8
//         0045f684     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         0045f689     MOV        this,dword ptr [EAX]
//         0045f68b     PUSH       this=>DAT_fffffff4
//         0045f68c     MOV        this,ESI
//         0045f68e     CALL       dword ptr [EBX + 0x34]
//                              move_obj.cpp:2107 (2)
//         0045f691     JMP        LAB_0045f704
//                               LAB_0045f693                                                 XREF[1]:     0045f668(j)
//                              move_obj.cpp:2104 (5)
//         0045f693     MOV        EAX,0x2
//                              move_obj.cpp:2185 (9)
//         0045f698     POP        EDI
//         0045f699     POP        ESI
//         0045f69a     POP        EBX
//         0045f69b     MOV        ESP,EBP
//         0045f69d     POP        EBP
//         0045f69e     RET        0x8
//                               LAB_0045f6a1                                                 XREF[3]:     0045f629(j), 0045f631(j),
//                                                                                                         0045f642(j)
//                              move_obj.cpp:2112 (23)
//         0045f6a1     FLD        float ptr [ESI + 0x98]
//         0045f6a7     FADD       float ptr [ESI + 0x40]
//         0045f6aa     MOV        EDX,dword ptr [ESI]
//         0045f6ac     MOV        EAX,dword ptr [ESP + 0x20]
//         0045f6b0     PUSH       this
//         0045f6b1     MOV        this,ESI
//         0045f6b3     FSTP       float ptr [ESP]
//         0045f6b6     PUSH       EAX=>DAT_fffffff8
//         0045f6b7     PUSH       EBX=>DAT_fffffff4
//                              move_obj.cpp:2116 (2)
//         0045f6b8     JMP        LAB_0045f701
//                               LAB_0045f6ba                                                 XREF[1]:     0045f572(j)
//                              move_obj.cpp:2118 (7)
//         0045f6ba     FLD        float ptr [EBP + param_1]
//         0045f6bd     FSUB       float ptr [ESP + 0x24]
//                              move_obj.cpp:2119 (7)
//         0045f6c1     FLD        float ptr [EBP + param_2]
//         0045f6c4     FSUB       float ptr [ESP + 0x20]
//                              move_obj.cpp:2120 (14)
//         0045f6c8     FST        float ptr [ESP + 0x2c]
//         0045f6cc     FXCH
//         0045f6ce     FST        double ptr [ESP + 0x30]
//         0045f6d2     FMUL       double ptr [ESP + 0x30]
//                              move_obj.cpp:2134 (48)
//         0045f6d6     FLD        float ptr [ESI + 0x98]
//         0045f6dc     FXCH       ST2
//         0045f6de     FMUL       float ptr [ESP + 0x2c]
//         0045f6e2     FXCH       ST2
//         0045f6e4     FADD       float ptr [ESI + 0x40]
//         0045f6e7     FXCH       ST2
//         0045f6e9     FADDP
//         0045f6eb     MOV        EDX,dword ptr [ESI]
//         0045f6ed     MOV        EAX,dword ptr [ESP + 0x20]
//         0045f6f1     PUSH       this
//         0045f6f2     MOV        this,ESI
//         0045f6f4     FSQRT
//         0045f6f6     FXCH
//         0045f6f8     FSTP       float ptr [ESP]
//         0045f6fb     PUSH       EAX=>DAT_fffffff8
//         0045f6fc     PUSH       EBX=>DAT_fffffff4
//         0045f6fd     FSTP       float ptr [ESP + 0x30]
//                               LAB_0045f701                                                 XREF[1]:     0045f6b8(j)
//         0045f701     CALL       dword ptr [EDX + 0x34]
//                               LAB_0045f704                                                 XREF[1]:     0045f691(j)
//         0045f704     FSTP       ST0
//                              move_obj.cpp:2151 (11)
//         0045f706     FLD        float ptr [ESP + 0x28]
//         0045f70a     FSUB       float ptr [ESI + 0x40]
//         0045f70d     FLD        float ptr [ESP + 0x24]
//                              move_obj.cpp:2157 (3)
//         0045f711     MOV        this,byte ptr [ESI + 0x35]
//                              move_obj.cpp:2160 (49)
//         0045f714     MOV        DL,byte ptr [ESI + 0x17c]
//         0045f71a     FLD        ST1
//         0045f71c     FCOMP      double ptr [DAT_00570be0]                        = 7Bh    {
//         0045f722     MOV        dword ptr [ESP + 0x10],0x3f800000
//         0045f72a     MOV        byte ptr [ESI + 0x17c],this
//         0045f730     MOV        byte ptr [ESI + 0x17d],DL
//         0045f736     FSTP       float ptr [ESI + 0x178]
//         0045f73c     FNSTSW     AX
//         0045f73e     TEST       AH,0x1
//         0045f741     JZ         LAB_0045f74f
//         0045f743     FSTP       ST0
//                              move_obj.cpp:2161 (8)
//         0045f745     MOV        dword ptr [ESP + 0x10],0x3f666666
//                              move_obj.cpp:2163 (15)
//         0045f74d     JMP        LAB_0045f7a0
//                               LAB_0045f74f                                                 XREF[1]:     0045f741(j)
//         0045f74f     FCOMP      double ptr [DAT_00570bf0]                        = 7Bh    {
//         0045f755     FNSTSW     AX
//         0045f757     TEST       AH,0x41
//         0045f75a     JNZ        LAB_0045f766
//                              move_obj.cpp:2164 (8)
//         0045f75c     MOV        dword ptr [ESP + 0x10],0x3f83d70a
//                              move_obj.cpp:2166 (2)
//         0045f764     JMP        LAB_0045f7a0
//                               LAB_0045f766                                                 XREF[1]:     0045f75a(j)
//                              move_obj.cpp:2167 (23)
//         0045f766     MOV        this,dword ptr [ESI + 0x10]
//         0045f769     TEST       this,this
//         0045f76b     JZ         LAB_0045f791
//         0045f76d     FLD        float ptr [ECX + this->_padding_]
//         0045f770     FCOMP      double ptr [DAT_00570b98]
//         0045f776     FNSTSW     AX
//         0045f778     TEST       AH,0x41
//         0045f77b     JNZ        LAB_0045f791
//                              move_obj.cpp:2168 (18)
//         0045f77d     MOV        EAX,dword ptr [ESI + 0x8]
//         0045f780     FLD        float ptr [EAX + 0xb8]
//         0045f786     FMUL       float ptr [ECX + this->_padding_]
//         0045f789     FSTP       float ptr [ESI + 0x88]
//                              move_obj.cpp:2169 (2)
//         0045f78f     JMP        LAB_0045f7a0
//                               LAB_0045f791                                                 XREF[2]:     0045f76b(j), 0045f77b(j)
//                              move_obj.cpp:2170 (15)
//         0045f791     MOV        this,dword ptr [ESI + 0x8]
//         0045f794     MOV        EDX,dword ptr [ECX + this+0xb8]
//         0045f79a     MOV        dword ptr [ESI + 0x88],EDX
//                               LAB_0045f7a0                                                 XREF[3]:     0045f74d(j), 0045f764(j),
//                                                                                                         0045f78f(j)
//                              move_obj.cpp:2175 (7)
//         0045f7a0     MOV        EAX,dword ptr [ESI + 0x1c]
//         0045f7a3     TEST       EAX,EAX
//         0045f7a5     JZ         LAB_0045f7bc
//                              move_obj.cpp:2176 (21)
//         0045f7a7     MOV        AL,byte ptr [EAX + 0x5]
//         0045f7aa     MOV        this,ESI
//         0045f7ac     AND        AL,0x1f
//         0045f7ae     PUSH       EAX
//         0045f7af     CALL       RGE_Static_Object::get_terrain_speed             float get_terrain_speed(RGE_Static_Object * t
//         0045f7b4     FMUL       float ptr [ESP + 0x10]
//         0045f7b8     FSTP       float ptr [ESP + 0x10]
//                               LAB_0045f7bc                                                 XREF[1]:     0045f7a5(j)
//                              move_obj.cpp:2180 (17)
//         0045f7bc     FLD        float ptr [ESP + 0x10]
//         0045f7c0     FCOMP      float ptr [DAT_00570b48]
//         0045f7c6     FNSTSW     AX
//         0045f7c8     TEST       AH,0x41
//         0045f7cb     JNZ        LAB_0045f7dd
//                              move_obj.cpp:2181 (16)
//         0045f7cd     FLD        float ptr [ESP + 0x10]
//         0045f7d1     FMUL       float ptr [ESI + 0x88]
//         0045f7d7     FSTP       float ptr [ESI + 0x88]
//                               LAB_0045f7dd                                                 XREF[1]:     0045f7cb(j)
//                              move_obj.cpp:2185 (11)
//         0045f7dd     POP        EDI
//         0045f7de     POP        ESI
//         0045f7df     XOR        EAX,EAX
//         0045f7e1     POP        EBX
//         0045f7e2     MOV        ESP,EBP
//         0045f7e4     POP        EBP
//         0045f7e5     RET        0x8
//         0045f7e8     ??         90h
//         0045f7e9     NOP
//         0045f7ea     NOP
//         0045f7eb     NOP
//         0045f7ec     NOP
//         0045f7ed     NOP
//         0045f7ee     NOP
//         0045f7ef     NOP
    return 0;
}

int RGE_Moving_Object::passableTile(float param_1, float param_2, int param_3) {
    /* TODO: Stub */
//                              int __thiscall passableTile(RGE_Moving_Object * this, float param_1,
//              int               EAX:4          <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//              float             Stack[0x4]:4   param_1                   XREF[1]:     0045f7f4(R)
//              float             Stack[0x8]:4   param_2                   XREF[1]:     0045f7fa(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     0045f7f0(R)
//                               ?passableTile@RGE_Moving_Object@@UAEHMMH@Z                   XREF[6]:     0056e534(*), 0056f36c(*),
//                               RGE_Moving_Object::passableTile                                           00570804(*), 00570a5c(*),
//                                                                                                         0057488c(*), 00574b34(*)
//                              move_obj.cpp:2197 (4)
//         0045f7f0     MOV        EAX,dword ptr [ESP + param_3]
//                              move_obj.cpp:2199 (22)
//         0045f7f4     MOV        EDX,dword ptr [ESP + param_1]
//         0045f7f8     TEST       EAX,EAX
//         0045f7fa     MOV        EAX,dword ptr [ESP + param_2]
//         0045f7fe     PUSH       0x1
//         0045f800     PUSH       EAX
//         0045f801     PUSH       EDX
//         0045f802     PUSH       this
//         0045f803     MOV        this,aiPathSystem
//         0045f808     JNZ        LAB_0045f80f
//                              move_obj.cpp:2200 (10)
//         0045f80a     MOV        this,pathSystem
//                               LAB_0045f80f                                                 XREF[1]:     0045f808(j)
//         0045f80f     CALL       PathingSystem::passable                          int passable(PathingSystem * this, RGE_Moving
//                              move_obj.cpp:2201 (3)
//         0045f814     RET        0xc
//         0045f817     ??         90h
//         0045f818     NOP
//         0045f819     NOP
//         0045f81a     NOP
//         0045f81b     NOP
//         0045f81c     NOP
//         0045f81d     NOP
//         0045f81e     NOP
//         0045f81f     NOP
    return 0;
}

int RGE_Moving_Object::canPath(XYZPoint param_1, float param_2, int param_3, float* param_4, int param_5, int param_6, int param_7) {
    /* TODO: Stub */
//                              int __thiscall canPath(RGE_Moving_Object * this, XYZPoint param_1, f
//              int               EAX:4          <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//              XYZPoint          Stack[0x4]:12  param_1                   XREF[5,1]:   0045f821(R), 0045f8c6(W), 0045f8cf(R), 0045f8e7(W),
//                                                                                     0045f8f4(R), 0045f832(R)
//              float             Stack[0x10]:4  param_2                   XREF[3]:     0045f8f0(R), 0045f930(R), 0045f983(R)
//              int               Stack[0x14]:4  param_3                   XREF[2]:     0045f92b(R), 0045f97e(R)
//              float *           Stack[0x18]:4  param_4                   XREF[2]:     0045f926(R), 0045f979(R)
//              int               Stack[0x1c]:4  param_5                   XREF[1]:     0045f90c(R)
//              int               Stack[0x20]:4  param_6                   XREF[2]:     0045f922(R), 0045f975(R)
//              int               Stack[0x24]:4  param_7                   XREF[2]:     0045f91e(R), 0045f971(R)
//                               ?canPath@RGE_Moving_Object@@UAEHUXYZPoint@@MHPAMHHH@Z        XREF[6]:     0056e5b8(*), 0056f3f0(*),
//                               RGE_Moving_Object::canPath                                                00570888(*), 00570ae0(*),
//                                                                                                         00574910(*), 00574bb8(*)
//                              move_obj.cpp:2208 (1)
//         0045f820     PUSH       EBX
//                              move_obj.cpp:2215 (56)
//         0045f821     MOV        EBX,dword ptr [ESP + param_1.x]
//         0045f825     PUSH       EBP
//         0045f826     PUSH       ESI
//         0045f827     TEST       EBX,EBX
//         0045f829     PUSH       EDI
//         0045f82a     MOV        ESI,this
//         0045f82c     JL         LAB_0045f9ba
//         0045f832     MOV        EBP,dword ptr [ESP + param_1.y]
//         0045f836     TEST       EBP,EBP
//         0045f838     JL         LAB_0045f9ba
//         0045f83e     MOV        EAX,dword ptr [ESI + 0xc]
//         0045f841     MOV        EAX,dword ptr [EAX + 0x3c]
//         0045f844     MOV        this,dword ptr [EAX + 0x28]
//         0045f847     CMP        EBX,dword ptr [ECX + this->_padding_]
//         0045f84a     JGE        LAB_0045f9ba
//         0045f850     CMP        EBP,dword ptr [ECX + this->_padding_]
//         0045f853     JGE        LAB_0045f9ba
//                              move_obj.cpp:2220 (11)
//         0045f859     MOV        EDX,dword ptr [ESI + 0x7c]
//         0045f85c     LEA        EDI,[ESI + 0x7c]
//         0045f85f     CMP        EDX,-0x1
//         0045f862     JNZ        LAB_0045f883
//                              move_obj.cpp:2223 (31)
//         0045f864     MOVSX      EDX,word ptr [EAX + 0x52]
//         0045f868     MOV        EAX,dword ptr [EAX + 0x54]
//         0045f86b     PUSH       EDI
//         0045f86c     PUSH       EDX
//         0045f86d     MOV        EDX,dword ptr [ESI + 0x8]
//         0045f870     MOV        this,dword ptr [this->_padding_ + 0x8dc4]
//         0045f876     MOVSX      EDX,word ptr [EDX + 0x66]
//         0045f87a     MOV        EDX,dword ptr [EAX + EDX*0x4]
//         0045f87d     PUSH       EDX
//         0045f87e     CALL       RGE_Zone_Map_List::get_zone_map                  RGE_Zone_Map * get_zone_map(RGE_Zone_Map_List
//                               LAB_0045f883                                                 XREF[1]:     0045f862(j)
//                              move_obj.cpp:2225 (25)
//         0045f883     MOV        this,dword ptr [ESI + 0xc]
//         0045f886     MOV        EAX,dword ptr [EDI]
//         0045f888     PUSH       EAX
//         0045f889     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0045f88c     MOV        EAX,dword ptr [EDX + 0x28]
//         0045f88f     MOV        this,dword ptr [EAX + 0x8dc4]
//         0045f895     CALL       RGE_Zone_Map_List::get_zone_map                  RGE_Zone_Map * get_zone_map(RGE_Zone_Map_List
//         0045f89a     MOV        EDI,EAX
//                              move_obj.cpp:2226 (2)
//         0045f89c     TEST       EDI,EDI
//                              move_obj.cpp:2227 (6)
//         0045f89e     JZ         LAB_0045f9ba
//                              move_obj.cpp:2228 (30)
//         0045f8a4     FLD        float ptr [ESI + 0x3c]
//         0045f8a7     CALL       __ftol                                           undefined __ftol()
//         0045f8ac     FLD        float ptr [ESI + 0x38]
//         0045f8af     PUSH       EAX
//         0045f8b0     CALL       __ftol                                           undefined __ftol()
//         0045f8b5     PUSH       EAX
//         0045f8b6     MOV        this,EDI
//         0045f8b8     CALL       RGE_Zone_Map::get_zone_info                      uchar get_zone_info(RGE_Zone_Map * this, long
//         0045f8bd     AND        EAX,0xff
//                              move_obj.cpp:2232 (13)
//         0045f8c2     PUSH       EBP
//         0045f8c3     PUSH       EBX
//         0045f8c4     MOV        this,EDI
//         0045f8c6     MOV        dword ptr [ESP + param_1.x],EAX
//         0045f8ca     CALL       RGE_Zone_Map::get_zone_info                      uchar get_zone_info(RGE_Zone_Map * this, long
//                              move_obj.cpp:2233 (13)
//         0045f8cf     MOV        this,dword ptr [ESP + param_1.x]
//         0045f8d3     AND        EAX,0xff
//         0045f8d8     CMP        EAX,this
//         0045f8da     JZ         LAB_0045f90c
//                              move_obj.cpp:2235 (8)
//         0045f8dc     FLD        float ptr [ESI + 0x38]
//         0045f8df     CALL       __ftol                                           undefined __ftol()
//                              move_obj.cpp:2236 (12)
//         0045f8e4     FLD        float ptr [ESI + 0x3c]
//         0045f8e7     MOV        dword ptr [ESP + param_1.x],EAX
//         0045f8eb     CALL       __ftol                                           undefined __ftol()
//                              move_obj.cpp:2240 (22)
//         0045f8f0     MOV        this,dword ptr [ESP + param_2]
//         0045f8f4     MOV        EDX,dword ptr [ESP + param_1.x]
//         0045f8f8     PUSH       this
//         0045f8f9     PUSH       EBP
//         0045f8fa     PUSH       EBX
//         0045f8fb     PUSH       EAX
//         0045f8fc     PUSH       EDX
//         0045f8fd     MOV        this,EDI
//         0045f8ff     CALL       RGE_Zone_Map::withinRange                        int withinRange(RGE_Zone_Map * this, XYPoint
//         0045f904     TEST       EAX,EAX
//                              move_obj.cpp:2241 (6)
//         0045f906     JZ         LAB_0045f9ba
//                               LAB_0045f90c                                                 XREF[1]:     0045f8da(j)
//                              move_obj.cpp:2244 (8)
//         0045f90c     MOV        EAX,dword ptr [ESP + param_5]
//         0045f910     TEST       EAX,EAX
//         0045f912     JZ         LAB_0045f967
//                              move_obj.cpp:2245 (10)
//         0045f914     MOV        this,aiPathSystem
//         0045f919     CALL       PathingSystem::incrementCanPaths                 void incrementCanPaths(PathingSystem * this)
//                              move_obj.cpp:2248 (66)
//         0045f91e     MOV        EAX,dword ptr [ESP + param_7]
//         0045f922     MOV        this,dword ptr [ESP + param_6]
//         0045f926     MOV        EDX,dword ptr [ESP + param_4]
//         0045f92a     PUSH       EAX
//         0045f92b     MOV        EAX,dword ptr [ESP + param_3]
//         0045f92f     PUSH       this
//         0045f930     MOV        this,dword ptr [ESP + param_2]
//         0045f934     PUSH       0x1
//         0045f936     PUSH       0x1
//         0045f938     PUSH       0x1
//         0045f93a     FLD        float ptr [ESI + 0x3c]
//         0045f93d     PUSH       0x1
//         0045f93f     PUSH       EDX
//         0045f940     PUSH       0x0
//         0045f942     PUSH       EAX
//         0045f943     PUSH       this
//         0045f944     PUSH       ESI
//         0045f945     PUSH       EBP
//         0045f946     PUSH       EBX
//         0045f947     CALL       __ftol                                           undefined __ftol()
//         0045f94c     FLD        float ptr [ESI + 0x38]
//         0045f94f     PUSH       EAX
//         0045f950     CALL       __ftol                                           undefined __ftol()
//         0045f955     PUSH       EAX
//         0045f956     MOV        this,aiPathSystem
//         0045f95b     CALL       PathingSystem::findTilePath                      int findTilePath(PathingSystem * this, int pa
//                              move_obj.cpp:2256 (7)
//         0045f960     POP        EDI
//         0045f961     POP        ESI
//         0045f962     POP        EBP
//         0045f963     POP        EBX
//         0045f964     RET        0x24
//                               LAB_0045f967                                                 XREF[1]:     0045f912(j)
//                              move_obj.cpp:2251 (10)
//         0045f967     MOV        this,pathSystem
//         0045f96c     CALL       PathingSystem::incrementCanPaths                 void incrementCanPaths(PathingSystem * this)
//                              move_obj.cpp:2254 (66)
//         0045f971     MOV        EDX,dword ptr [ESP + param_7]
//         0045f975     MOV        EAX,dword ptr [ESP + param_6]
//         0045f979     MOV        this,dword ptr [ESP + param_4]
//         0045f97d     PUSH       EDX
//         0045f97e     MOV        EDX,dword ptr [ESP + param_3]
//         0045f982     PUSH       EAX
//         0045f983     MOV        EAX,dword ptr [ESP + param_2]
//         0045f987     PUSH       0x1
//         0045f989     PUSH       0x1
//         0045f98b     PUSH       0x1
//         0045f98d     FLD        float ptr [ESI + 0x3c]
//         0045f990     PUSH       0x1
//         0045f992     PUSH       this
//         0045f993     PUSH       0x0
//         0045f995     PUSH       EDX
//         0045f996     PUSH       EAX
//         0045f997     PUSH       ESI
//         0045f998     PUSH       EBP
//         0045f999     PUSH       EBX
//         0045f99a     CALL       __ftol                                           undefined __ftol()
//         0045f99f     FLD        float ptr [ESI + 0x38]
//         0045f9a2     PUSH       EAX
//         0045f9a3     CALL       __ftol                                           undefined __ftol()
//         0045f9a8     PUSH       EAX
//         0045f9a9     MOV        this,pathSystem
//         0045f9ae     CALL       PathingSystem::findTilePath                      int findTilePath(PathingSystem * this, int pa
//                              move_obj.cpp:2256 (16)
//         0045f9b3     POP        EDI
//         0045f9b4     POP        ESI
//         0045f9b5     POP        EBP
//         0045f9b6     POP        EBX
//         0045f9b7     RET        0x24
//                               LAB_0045f9ba                                                 XREF[6]:     0045f82c(j), 0045f838(j),
//                                                                                                         0045f84a(j), 0045f853(j),
//                                                                                                         0045f89e(j), 0045f906(j)
//         0045f9ba     POP        EDI
//         0045f9bb     POP        ESI
//         0045f9bc     POP        EBP
//         0045f9bd     XOR        EAX,EAX
//         0045f9bf     POP        EBX
//         0045f9c0     RET        0x24
//         0045f9c3     ??         90h
//         0045f9c4     NOP
//         0045f9c5     NOP
//         0045f9c6     NOP
//         0045f9c7     NOP
//         0045f9c8     NOP
//         0045f9c9     NOP
//         0045f9ca     NOP
//         0045f9cb     NOP
//         0045f9cc     NOP
//         0045f9cd     NOP
//         0045f9ce     NOP
//         0045f9cf     NOP
    return 0;
}

int RGE_Moving_Object::canPath(int param_1, float param_2, float* param_3, int param_4, int param_5, int param_6) {
    /* TODO: Stub */
//                              int __thiscall canPath(RGE_Moving_Object * this, int param_1, float
//              int               EAX:4          <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[3]:     0045f9d3(R), 0045fb0a(R), 0045fb6c(R)
//              float             Stack[0x8]:4   param_2                   XREF[1]:     0045fa93(R)
//              float *           Stack[0xc]:4   param_3                   XREF[2]:     0045fb05(R), 0045fb67(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     0045faeb(R)
//              int               Stack[0x14]:4  param_5                   XREF[2]:     0045fb01(R), 0045fb63(R)
//              int               Stack[0x18]:4  param_6                   XREF[2]:     0045fafd(R), 0045fb5f(R)
//              XYPoint           Stack[-0xc]:8  goal                      XREF[2,2]:   0045fab0(W), 0045fac9(R), 0045fabc(W), 0045fac5(R)
//              XYPoint           Stack[-0x14]:8 start                     XREF[0,2]:   0045faa4(W), 0045facf(R)
//                               ?canPath@RGE_Moving_Object@@UAEHHMPAMHHH@Z                   XREF[6]:     0056e5b4(*), 0056f3ec(*),
//                               RGE_Moving_Object::canPath                                                00570884(*), 00570adc(*),
//                                                                                                         0057490c(*), 00574bb4(*)
//                              move_obj.cpp:2263 (3)
//         0045f9d0     SUB        ESP,0x10
//                              move_obj.cpp:2267 (24)
//         0045f9d3     MOV        EAX,dword ptr [ESP + param_1]
//         0045f9d7     PUSH       EBX
//         0045f9d8     PUSH       EBP
//         0045f9d9     PUSH       ESI
//         0045f9da     MOV        ESI,this
//         0045f9dc     PUSH       EDI
//         0045f9dd     PUSH       EAX
//         0045f9de     MOV        this,dword ptr [ESI + 0xc]
//         0045f9e1     MOV        this,dword ptr [ECX + this->_padding_]
//         0045f9e4     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
//         0045f9e9     MOV        EDI,EAX
//                              move_obj.cpp:2268 (4)
//         0045f9eb     TEST       EDI,EDI
//         0045f9ed     JNZ        LAB_0045f9f9
//                              move_obj.cpp:2312 (10)
//         0045f9ef     POP        EDI
//         0045f9f0     POP        ESI
//         0045f9f1     POP        EBP
//         0045f9f2     POP        EBX
//         0045f9f3     ADD        ESP,0x10
//         0045f9f6     RET        0x18
//                               LAB_0045f9f9                                                 XREF[1]:     0045f9ed(j)
//                              move_obj.cpp:2273 (11)
//         0045f9f9     MOV        EAX,dword ptr [ESI + 0x7c]
//         0045f9fc     LEA        EBX,[ESI + 0x7c]
//         0045f9ff     CMP        EAX,-0x1
//         0045fa02     JNZ        LAB_0045fa2c
//                              move_obj.cpp:2276 (40)
//         0045fa04     MOV        EDX,dword ptr [ESI + 0xc]
//         0045fa07     PUSH       EBX
//         0045fa08     MOV        EAX,dword ptr [EDX + 0x3c]
//         0045fa0b     MOV        EDX,dword ptr [ESI + 0x8]
//         0045fa0e     MOVSX      this,word ptr [EAX + 0x52]
//         0045fa12     PUSH       this
//         0045fa13     MOVSX      this,word ptr [EDX + 0x66]
//         0045fa17     MOV        EDX,dword ptr [EAX + 0x54]
//         0045fa1a     MOV        this,dword ptr [EDX + this->_padding_*0x4]
//         0045fa1d     MOV        EDX,dword ptr [EAX + 0x28]
//         0045fa20     PUSH       this
//         0045fa21     MOV        this,dword ptr [EDX + 0x8dc4]
//         0045fa27     CALL       RGE_Zone_Map_List::get_zone_map                  RGE_Zone_Map * get_zone_map(RGE_Zone_Map_List
//                               LAB_0045fa2c                                                 XREF[1]:     0045fa02(j)
//                              move_obj.cpp:2278 (25)
//         0045fa2c     MOV        this,dword ptr [ESI + 0xc]
//         0045fa2f     MOV        EAX,dword ptr [EBX]
//         0045fa31     PUSH       EAX
//         0045fa32     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0045fa35     MOV        EAX,dword ptr [EDX + 0x28]
//         0045fa38     MOV        this,dword ptr [EAX + 0x8dc4]
//         0045fa3e     CALL       RGE_Zone_Map_List::get_zone_map                  RGE_Zone_Map * get_zone_map(RGE_Zone_Map_List
//         0045fa43     MOV        EBX,EAX
//                              move_obj.cpp:2279 (4)
//         0045fa45     TEST       EBX,EBX
//         0045fa47     JNZ        LAB_0045fa53
//                              move_obj.cpp:2312 (10)
//         0045fa49     POP        EDI
//         0045fa4a     POP        ESI
//         0045fa4b     POP        EBP
//         0045fa4c     POP        EBX
//         0045fa4d     ADD        ESP,0x10
//         0045fa50     RET        0x18
//                               LAB_0045fa53                                                 XREF[1]:     0045fa47(j)
//                              move_obj.cpp:2281 (25)
//         0045fa53     FLD        float ptr [ESI + 0x3c]
//         0045fa56     CALL       __ftol                                           undefined __ftol()
//         0045fa5b     FLD        float ptr [ESI + 0x38]
//         0045fa5e     PUSH       EAX
//         0045fa5f     CALL       __ftol                                           undefined __ftol()
//         0045fa64     PUSH       EAX
//         0045fa65     MOV        this,EBX
//         0045fa67     CALL       RGE_Zone_Map::get_zone_info                      uchar get_zone_info(RGE_Zone_Map * this, long
//                              move_obj.cpp:2286 (37)
//         0045fa6c     FLD        float ptr [EDI + 0x3c]
//         0045fa6f     AND        EAX,0xff
//         0045fa74     MOV        EBP,EAX
//         0045fa76     CALL       __ftol                                           undefined __ftol()
//         0045fa7b     FLD        float ptr [EDI + 0x38]
//         0045fa7e     PUSH       EAX
//         0045fa7f     CALL       __ftol                                           undefined __ftol()
//         0045fa84     PUSH       EAX
//         0045fa85     MOV        this,EBX
//         0045fa87     CALL       RGE_Zone_Map::get_zone_info                      uchar get_zone_info(RGE_Zone_Map * this, long
//         0045fa8c     AND        EAX,0xff
//                              move_obj.cpp:2287 (8)
//         0045fa91     CMP        EAX,EBP
//         0045fa93     MOV        EBP,dword ptr [ESP + param_2]
//         0045fa97     JZ         LAB_0045faeb
//                              move_obj.cpp:2289 (8)
//         0045fa99     FLD        float ptr [ESI + 0x38]
//         0045fa9c     CALL       __ftol                                           undefined __ftol()
//                              move_obj.cpp:2290 (12)
//         0045faa1     FLD        float ptr [ESI + 0x3c]
//         0045faa4     MOV        dword ptr [ESP + start.y],EAX
//         0045faa8     CALL       __ftol                                           undefined __ftol()
//                              move_obj.cpp:2292 (12)
//         0045faad     FLD        float ptr [EDI + 0x38]
//         0045fab0     MOV        dword ptr [ESP + goal.x],EAX
//         0045fab4     CALL       __ftol                                           undefined __ftol()
//                              move_obj.cpp:2293 (12)
//         0045fab9     FLD        float ptr [EDI + 0x3c]
//         0045fabc     MOV        dword ptr [ESP + goal.y],EAX
//         0045fac0     CALL       __ftol                                           undefined __ftol()
//                              move_obj.cpp:2294 (28)
//         0045fac5     MOV        this,dword ptr [ESP + goal.y]
//         0045fac9     MOV        EDX,dword ptr [ESP + goal.x]
//         0045facd     PUSH       EBP
//         0045face     PUSH       EAX
//         0045facf     MOV        EAX,dword ptr [ESP + start.y]
//         0045fad3     PUSH       this
//         0045fad4     PUSH       EDX
//         0045fad5     PUSH       EAX
//         0045fad6     MOV        this,EBX
//         0045fad8     CALL       RGE_Zone_Map::withinRange                        int withinRange(RGE_Zone_Map * this, XYPoint
//         0045fadd     TEST       EAX,EAX
//         0045fadf     JNZ        LAB_0045faeb
//                              move_obj.cpp:2312 (10)
//         0045fae1     POP        EDI
//         0045fae2     POP        ESI
//         0045fae3     POP        EBP
//         0045fae4     POP        EBX
//         0045fae5     ADD        ESP,0x10
//         0045fae8     RET        0x18
//                               LAB_0045faeb                                                 XREF[2]:     0045fa97(j), 0045fadf(j)
//                              move_obj.cpp:2298 (8)
//         0045faeb     MOV        EAX,dword ptr [ESP + param_4]
//         0045faef     TEST       EAX,EAX
//         0045faf1     JZ         LAB_0045fb55
//                              move_obj.cpp:2299 (10)
//         0045faf3     MOV        this,aiPathSystem
//         0045faf8     CALL       PathingSystem::incrementCanPaths                 void incrementCanPaths(PathingSystem * this)
//                              move_obj.cpp:2303 (73)
//         0045fafd     MOV        this,dword ptr [ESP + param_6]
//         0045fb01     MOV        EDX,dword ptr [ESP + param_5]
//         0045fb05     MOV        EAX,dword ptr [ESP + param_3]
//         0045fb09     PUSH       this
//         0045fb0a     MOV        this,dword ptr [ESP + param_1]
//         0045fb0e     PUSH       EDX
//         0045fb0f     FLD        float ptr [EDI + 0x3c]
//         0045fb12     PUSH       0x1
//         0045fb14     PUSH       0x1
//         0045fb16     PUSH       0x1
//         0045fb18     PUSH       0x1
//         0045fb1a     PUSH       EAX
//         0045fb1b     PUSH       0x0
//         0045fb1d     PUSH       this
//         0045fb1e     PUSH       EBP
//         0045fb1f     PUSH       ESI
//         0045fb20     CALL       __ftol                                           undefined __ftol()
//         0045fb25     FLD        float ptr [EDI + 0x38]
//         0045fb28     PUSH       EAX
//         0045fb29     CALL       __ftol                                           undefined __ftol()
//         0045fb2e     FLD        float ptr [ESI + 0x3c]
//         0045fb31     PUSH       EAX
//         0045fb32     CALL       __ftol                                           undefined __ftol()
//         0045fb37     FLD        float ptr [ESI + 0x38]
//         0045fb3a     PUSH       EAX
//         0045fb3b     CALL       __ftol                                           undefined __ftol()
//         0045fb40     PUSH       EAX
//         0045fb41     MOV        this,aiPathSystem
//                              move_obj.cpp:2310 (5)
//         0045fb46     CALL       PathingSystem::findTilePath                      int findTilePath(PathingSystem * this, int pa
//                              move_obj.cpp:2312 (10)
//         0045fb4b     POP        EDI
//         0045fb4c     POP        ESI
//         0045fb4d     POP        EBP
//         0045fb4e     POP        EBX
//         0045fb4f     ADD        ESP,0x10
//         0045fb52     RET        0x18
//                               LAB_0045fb55                                                 XREF[1]:     0045faf1(j)
//                              move_obj.cpp:2306 (10)
//         0045fb55     MOV        this,pathSystem
//         0045fb5a     CALL       PathingSystem::incrementCanPaths                 void incrementCanPaths(PathingSystem * this)
//                              move_obj.cpp:2310 (78)
//         0045fb5f     MOV        EDX,dword ptr [ESP + param_6]
//         0045fb63     MOV        EAX,dword ptr [ESP + param_5]
//         0045fb67     MOV        this,dword ptr [ESP + param_3]
//         0045fb6b     PUSH       EDX
//         0045fb6c     MOV        EDX,dword ptr [ESP + param_1]
//         0045fb70     PUSH       EAX
//         0045fb71     FLD        float ptr [EDI + 0x3c]
//         0045fb74     PUSH       0x1
//         0045fb76     PUSH       0x1
//         0045fb78     PUSH       0x1
//         0045fb7a     PUSH       0x1
//         0045fb7c     PUSH       this
//         0045fb7d     PUSH       0x0
//         0045fb7f     PUSH       EDX
//         0045fb80     PUSH       EBP
//         0045fb81     PUSH       ESI
//         0045fb82     CALL       __ftol                                           undefined __ftol()
//         0045fb87     FLD        float ptr [EDI + 0x38]
//         0045fb8a     PUSH       EAX
//         0045fb8b     CALL       __ftol                                           undefined __ftol()
//         0045fb90     FLD        float ptr [ESI + 0x3c]
//         0045fb93     PUSH       EAX
//         0045fb94     CALL       __ftol                                           undefined __ftol()
//         0045fb99     FLD        float ptr [ESI + 0x38]
//         0045fb9c     PUSH       EAX
//         0045fb9d     CALL       __ftol                                           undefined __ftol()
//         0045fba2     PUSH       EAX
//         0045fba3     MOV        this,pathSystem
//         0045fba8     CALL       PathingSystem::findTilePath                      int findTilePath(PathingSystem * this, int pa
//                              move_obj.cpp:2312 (10)
//         0045fbad     POP        EDI
//         0045fbae     POP        ESI
//         0045fbaf     POP        EBP
//         0045fbb0     POP        EBX
//         0045fbb1     ADD        ESP,0x10
//         0045fbb4     RET        0x18
//         0045fbb7     ??         90h
//         0045fbb8     NOP
//         0045fbb9     NOP
//         0045fbba     NOP
//         0045fbbb     NOP
//         0045fbbc     NOP
//         0045fbbd     NOP
//         0045fbbe     NOP
//         0045fbbf     NOP
    return 0;
}

int RGE_Moving_Object::canBidirectionPath(int param_1, int param_2, float param_3, float* param_4, int param_5, int param_6, int param_7) {
    /* TODO: Stub */
//                              int __thiscall canBidirectionPath(RGE_Moving_Object * this, int para
//              int               EAX:4          <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[3]:     0045fbc3(R), 0045fd1a(R), 0045fdf8(R)
//              int               Stack[0x8]:4   param_2                   XREF[3]:     0045fbd9(R), 0045fd7c(R), 0045fe5a(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     0045fc95(R)
//              float *           Stack[0x10]:4  param_4                   XREF[4]:     0045fd15(R), 0045fd77(R), 0045fdf3(R), 0045fe55(R)
//              int               Stack[0x14]:4  param_5                   XREF[1]:     0045fcf0(R)
//              int               Stack[0x18]:4  param_6                   XREF[4]:     0045fd11(R), 0045fd73(R), 0045fdef(R), 0045fe51(R)
//              int               Stack[0x1c]:4  param_7                   XREF[4]:     0045fd0d(R), 0045fd6f(R), 0045fdeb(R), 0045fe4d(R)
//              XYPoint           Stack[-0xc]:8  goal                      XREF[2,2]:   0045fc4c(W), 0045fcdf(R), 0045fcc5(W), 0045fcce(R)
//              RGE_Zone_Map *    Stack[-0x10]:4 zoneMap                   XREF[2]:     0045fcb9(W), 0045fcd8(R)
//              XYPoint           Stack[-0x18]:8 start                     XREF[0,4]:   0045fc77(W), 0045fc91(R), 0045fcad(W), 0045fcd2(R)
//                               ?canBidirectionPath@RGE_Moving_Object@@UAEHHHMPAMHHH@Z       XREF[6]:     0056e5bc(*), 0056f3f4(*),
//                               RGE_Moving_Object::canBidirectionPath                                     0057088c(*), 00570ae4(*),
//                                                                                                         00574914(*), 00574bbc(*)
//                              move_obj.cpp:2319 (3)
//         0045fbc0     SUB        ESP,0x14
//                              move_obj.cpp:2324 (22)
//         0045fbc3     MOV        EAX,dword ptr [ESP + param_1]
//         0045fbc7     PUSH       EBX
//         0045fbc8     PUSH       EBP
//         0045fbc9     PUSH       ESI
//         0045fbca     MOV        ESI,this
//         0045fbcc     PUSH       EDI
//         0045fbcd     PUSH       EAX
//         0045fbce     MOV        this,dword ptr [ESI + 0xc]
//         0045fbd1     MOV        this,dword ptr [ECX + this->_padding_]
//         0045fbd4     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
//                              move_obj.cpp:2325 (18)
//         0045fbd9     MOV        EDX,dword ptr [ESP + param_2]
//         0045fbdd     MOV        EDI,EAX
//         0045fbdf     MOV        EAX,dword ptr [ESI + 0xc]
//         0045fbe2     PUSH       EDX
//         0045fbe3     MOV        this,dword ptr [EAX + 0x3c]
//         0045fbe6     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
//                              move_obj.cpp:2326 (18)
//         0045fbeb     TEST       EDI,EDI
//         0045fbed     MOV        EBX,EAX
//         0045fbef     JZ         LAB_0045febf
//         0045fbf5     TEST       EBX,EBX
//         0045fbf7     JZ         LAB_0045febf
//                              move_obj.cpp:2335 (11)
//         0045fbfd     MOV        EAX,dword ptr [ESI + 0x7c]
//         0045fc00     LEA        EBP,[ESI + 0x7c]
//         0045fc03     CMP        EAX,-0x1
//         0045fc06     JNZ        LAB_0045fc30
//                              move_obj.cpp:2338 (40)
//         0045fc08     MOV        this,dword ptr [ESI + 0xc]
//         0045fc0b     PUSH       EBP
//         0045fc0c     MOV        EAX,dword ptr [ECX + this->_padding_]
//         0045fc0f     MOV        this,dword ptr [ESI + 0x8]
//         0045fc12     MOVSX      EDX,word ptr [EAX + 0x52]
//         0045fc16     PUSH       EDX
//         0045fc17     MOVSX      EDX,word ptr [ECX + this+0x66]
//         0045fc1b     MOV        this,dword ptr [EAX + 0x54]
//         0045fc1e     MOV        EAX,dword ptr [EAX + 0x28]
//         0045fc21     MOV        EDX,dword ptr [this->_padding_ + EDX*0x4]
//         0045fc24     MOV        this,dword ptr [EAX + 0x8dc4]
//         0045fc2a     PUSH       EDX
//         0045fc2b     CALL       RGE_Zone_Map_List::get_zone_map                  RGE_Zone_Map * get_zone_map(RGE_Zone_Map_List
//                               LAB_0045fc30                                                 XREF[1]:     0045fc06(j)
//                              move_obj.cpp:2340 (26)
//         0045fc30     MOV        EDX,dword ptr [ESI + 0xc]
//         0045fc33     MOV        this,dword ptr [EBP]
//         0045fc36     PUSH       this
//         0045fc37     MOV        EAX,dword ptr [EDX + 0x3c]
//         0045fc3a     MOV        this,dword ptr [EAX + 0x28]
//         0045fc3d     MOV        this,dword ptr [this->_padding_ + 0x8dc4]
//         0045fc43     CALL       RGE_Zone_Map_List::get_zone_map                  RGE_Zone_Map * get_zone_map(RGE_Zone_Map_List
//         0045fc48     MOV        EBP,EAX
//                              move_obj.cpp:2341 (6)
//         0045fc4a     TEST       EBP,EBP
//         0045fc4c     MOV        dword ptr [ESP + goal.x],EBP
//                              move_obj.cpp:2345 (6)
//         0045fc50     JZ         LAB_0045febf
//                              move_obj.cpp:2347 (25)
//         0045fc56     FLD        float ptr [ESI + 0x3c]
//         0045fc59     CALL       __ftol                                           undefined __ftol()
//         0045fc5e     FLD        float ptr [ESI + 0x38]
//         0045fc61     PUSH       EAX
//         0045fc62     CALL       __ftol                                           undefined __ftol()
//         0045fc67     PUSH       EAX
//         0045fc68     MOV        this,EBP
//         0045fc6a     CALL       RGE_Zone_Map::get_zone_info                      uchar get_zone_info(RGE_Zone_Map * this, long
//                              move_obj.cpp:2352 (34)
//         0045fc6f     FLD        float ptr [EDI + 0x3c]
//         0045fc72     AND        EAX,0xff
//         0045fc77     MOV        dword ptr [ESP + start.y],EAX
//         0045fc7b     CALL       __ftol                                           undefined __ftol()
//         0045fc80     FLD        float ptr [EDI + 0x38]
//         0045fc83     PUSH       EAX
//         0045fc84     CALL       __ftol                                           undefined __ftol()
//         0045fc89     PUSH       EAX
//         0045fc8a     MOV        this,EBP
//         0045fc8c     CALL       RGE_Zone_Map::get_zone_info                      uchar get_zone_info(RGE_Zone_Map * this, long
//                              move_obj.cpp:2353 (17)
//         0045fc91     MOV        this,dword ptr [ESP + start.y]
//         0045fc95     MOV        EBP,dword ptr [ESP + param_3]
//         0045fc99     AND        EAX,0xff
//         0045fc9e     CMP        EAX,this
//         0045fca0     JZ         LAB_0045fcf0
//                              move_obj.cpp:2355 (8)
//         0045fca2     FLD        float ptr [ESI + 0x38]
//         0045fca5     CALL       __ftol                                           undefined __ftol()
//                              move_obj.cpp:2356 (12)
//         0045fcaa     FLD        float ptr [ESI + 0x3c]
//         0045fcad     MOV        dword ptr [ESP + start.y],EAX
//         0045fcb1     CALL       __ftol                                           undefined __ftol()
//                              move_obj.cpp:2358 (12)
//         0045fcb6     FLD        float ptr [EDI + 0x38]
//         0045fcb9     MOV        dword ptr [ESP + zoneMap],EAX
//         0045fcbd     CALL       __ftol                                           undefined __ftol()
//                              move_obj.cpp:2359 (12)
//         0045fcc2     FLD        float ptr [EDI + 0x3c]
//         0045fcc5     MOV        dword ptr [ESP + goal.y],EAX
//         0045fcc9     CALL       __ftol                                           undefined __ftol()
//                              move_obj.cpp:2360 (28)
//         0045fcce     MOV        EDX,dword ptr [ESP + goal.y]
//         0045fcd2     MOV        this,dword ptr [ESP + start.y]
//         0045fcd6     PUSH       EBP
//         0045fcd7     PUSH       EAX
//         0045fcd8     MOV        EAX,dword ptr [ESP + zoneMap]
//         0045fcdc     PUSH       EDX
//         0045fcdd     PUSH       EAX
//         0045fcde     PUSH       this
//         0045fcdf     MOV        this,dword ptr [ESP + goal.x]
//         0045fce3     CALL       RGE_Zone_Map::withinRange                        int withinRange(RGE_Zone_Map * this, XYPoint
//         0045fce8     TEST       EAX,EAX
//                              move_obj.cpp:2364 (6)
//         0045fcea     JZ         LAB_0045febf
//                               LAB_0045fcf0                                                 XREF[1]:     0045fca0(j)
//                              move_obj.cpp:2372 (19)
//         0045fcf0     MOV        EAX,dword ptr [ESP + param_5]
//         0045fcf4     MOV        byte ptr [ESI + 0x154],0x1
//         0045fcfb     TEST       EAX,EAX
//         0045fcfd     JZ         LAB_0045fde1
//                              move_obj.cpp:2374 (10)
//         0045fd03     MOV        this,aiPathSystem
//         0045fd08     CALL       PathingSystem::incrementCanPaths                 void incrementCanPaths(PathingSystem * this)
//                              move_obj.cpp:2378 (78)
//         0045fd0d     MOV        EDX,dword ptr [ESP + param_7]
//         0045fd11     MOV        EAX,dword ptr [ESP + param_6]
//         0045fd15     MOV        this,dword ptr [ESP + param_4]
//         0045fd19     PUSH       EDX
//         0045fd1a     MOV        EDX,dword ptr [ESP + param_1]
//         0045fd1e     PUSH       EAX
//         0045fd1f     FLD        float ptr [EDI + 0x3c]
//         0045fd22     PUSH       0x1
//         0045fd24     PUSH       0x1
//         0045fd26     PUSH       0x1
//         0045fd28     PUSH       0x1
//         0045fd2a     PUSH       this
//         0045fd2b     PUSH       0x1
//         0045fd2d     PUSH       EDX
//         0045fd2e     PUSH       EBP
//         0045fd2f     PUSH       ESI
//         0045fd30     CALL       __ftol                                           undefined __ftol()
//         0045fd35     FLD        float ptr [EDI + 0x38]
//         0045fd38     PUSH       EAX
//         0045fd39     CALL       __ftol                                           undefined __ftol()
//         0045fd3e     FLD        float ptr [ESI + 0x3c]
//         0045fd41     PUSH       EAX
//         0045fd42     CALL       __ftol                                           undefined __ftol()
//         0045fd47     FLD        float ptr [ESI + 0x38]
//         0045fd4a     PUSH       EAX
//         0045fd4b     CALL       __ftol                                           undefined __ftol()
//         0045fd50     PUSH       EAX
//         0045fd51     MOV        this,aiPathSystem
//         0045fd56     CALL       PathingSystem::findTilePath                      int findTilePath(PathingSystem * this, int pa
//                              move_obj.cpp:2379 (4)
//         0045fd5b     TEST       EAX,EAX
//         0045fd5d     JNZ        LAB_0045fd6f
//                              move_obj.cpp:2380 (6)
//         0045fd5f     MOV        byte ptr [ESI + 0x154],AL
//                              move_obj.cpp:2432 (10)
//         0045fd65     POP        EDI
//         0045fd66     POP        ESI
//         0045fd67     POP        EBP
//         0045fd68     POP        EBX
//         0045fd69     ADD        ESP,0x14
//         0045fd6c     RET        0x1c
//                               LAB_0045fd6f                                                 XREF[1]:     0045fd5d(j)
//                              move_obj.cpp:2398 (97)
//         0045fd6f     MOV        EAX,dword ptr [ESP + param_7]
//         0045fd73     MOV        this,dword ptr [ESP + param_6]
//         0045fd77     MOV        EDX,dword ptr [ESP + param_4]
//         0045fd7b     PUSH       EAX
//         0045fd7c     MOV        EAX,dword ptr [ESP + param_2]
//         0045fd80     PUSH       this
//         0045fd81     FLD        float ptr [EBX + 0x3c]
//         0045fd84     PUSH       0x1
//         0045fd86     PUSH       0x1
//         0045fd88     PUSH       0x1
//         0045fd8a     PUSH       0x1
//         0045fd8c     PUSH       EDX
//         0045fd8d     PUSH       0x0
//         0045fd8f     PUSH       EAX
//         0045fd90     PUSH       EBP
//         0045fd91     LEA        EDI,[ESI + 0xd8]
//         0045fd97     PUSH       ESI
//         0045fd98     CALL       __ftol                                           undefined __ftol()
//         0045fd9d     FLD        float ptr [EBX + 0x38]
//         0045fda0     PUSH       EAX
//         0045fda1     CALL       __ftol                                           undefined __ftol()
//         0045fda6     PUSH       EAX
//         0045fda7     MOV        this,EDI
//         0045fda9     CALL       Path::lastWaypoint                               Waypoint * lastWaypoint(Path * this)
//         0045fdae     FLD        float ptr [EAX + 0x4]
//         0045fdb1     CALL       __ftol                                           undefined __ftol()
//         0045fdb6     PUSH       EAX
//         0045fdb7     MOV        this,EDI
//         0045fdb9     CALL       Path::lastWaypoint                               Waypoint * lastWaypoint(Path * this)
//         0045fdbe     FLD        float ptr [EAX]
//         0045fdc0     CALL       __ftol                                           undefined __ftol()
//         0045fdc5     PUSH       EAX
//         0045fdc6     MOV        this,aiPathSystem
//         0045fdcb     CALL       PathingSystem::findTilePath                      int findTilePath(PathingSystem * this, int pa
//                              move_obj.cpp:2402 (7)
//         0045fdd0     MOV        byte ptr [ESI + 0x154],0x0
//                              move_obj.cpp:2432 (10)
//         0045fdd7     POP        EDI
//         0045fdd8     POP        ESI
//         0045fdd9     POP        EBP
//         0045fdda     POP        EBX
//         0045fddb     ADD        ESP,0x14
//         0045fdde     RET        0x1c
//                               LAB_0045fde1                                                 XREF[1]:     0045fcfd(j)
//                              move_obj.cpp:2410 (10)
//         0045fde1     MOV        this,pathSystem
//         0045fde6     CALL       PathingSystem::incrementCanPaths                 void incrementCanPaths(PathingSystem * this)
//                              move_obj.cpp:2414 (78)
//         0045fdeb     MOV        this,dword ptr [ESP + param_7]
//         0045fdef     MOV        EDX,dword ptr [ESP + param_6]
//         0045fdf3     MOV        EAX,dword ptr [ESP + param_4]
//         0045fdf7     PUSH       this
//         0045fdf8     MOV        this,dword ptr [ESP + param_1]
//         0045fdfc     PUSH       EDX
//         0045fdfd     FLD        float ptr [EDI + 0x3c]
//         0045fe00     PUSH       0x1
//         0045fe02     PUSH       0x1
//         0045fe04     PUSH       0x1
//         0045fe06     PUSH       0x1
//         0045fe08     PUSH       EAX
//         0045fe09     PUSH       0x1
//         0045fe0b     PUSH       this
//         0045fe0c     PUSH       EBP
//         0045fe0d     PUSH       ESI
//         0045fe0e     CALL       __ftol                                           undefined __ftol()
//         0045fe13     FLD        float ptr [EDI + 0x38]
//         0045fe16     PUSH       EAX
//         0045fe17     CALL       __ftol                                           undefined __ftol()
//         0045fe1c     FLD        float ptr [ESI + 0x3c]
//         0045fe1f     PUSH       EAX
//         0045fe20     CALL       __ftol                                           undefined __ftol()
//         0045fe25     FLD        float ptr [ESI + 0x38]
//         0045fe28     PUSH       EAX
//         0045fe29     CALL       __ftol                                           undefined __ftol()
//         0045fe2e     PUSH       EAX
//         0045fe2f     MOV        this,pathSystem
//         0045fe34     CALL       PathingSystem::findTilePath                      int findTilePath(PathingSystem * this, int pa
//                              move_obj.cpp:2415 (4)
//         0045fe39     TEST       EAX,EAX
//         0045fe3b     JNZ        LAB_0045fe4d
//                              move_obj.cpp:2416 (6)
//         0045fe3d     MOV        byte ptr [ESI + 0x154],AL
//                              move_obj.cpp:2432 (10)
//         0045fe43     POP        EDI
//         0045fe44     POP        ESI
//         0045fe45     POP        EBP
//         0045fe46     POP        EBX
//         0045fe47     ADD        ESP,0x14
//         0045fe4a     RET        0x1c
//                               LAB_0045fe4d                                                 XREF[1]:     0045fe3b(j)
//                              move_obj.cpp:2426 (97)
//         0045fe4d     MOV        EDX,dword ptr [ESP + param_7]
//         0045fe51     MOV        EAX,dword ptr [ESP + param_6]
//         0045fe55     MOV        this,dword ptr [ESP + param_4]
//         0045fe59     PUSH       EDX
//         0045fe5a     MOV        EDX,dword ptr [ESP + param_2]
//         0045fe5e     PUSH       EAX
//         0045fe5f     FLD        float ptr [EBX + 0x3c]
//         0045fe62     PUSH       0x1
//         0045fe64     PUSH       0x1
//         0045fe66     PUSH       0x1
//         0045fe68     PUSH       0x1
//         0045fe6a     PUSH       this
//         0045fe6b     PUSH       0x0
//         0045fe6d     PUSH       EDX
//         0045fe6e     PUSH       EBP
//         0045fe6f     LEA        EDI,[ESI + 0xd8]
//         0045fe75     PUSH       ESI
//         0045fe76     CALL       __ftol                                           undefined __ftol()
//         0045fe7b     FLD        float ptr [EBX + 0x38]
//         0045fe7e     PUSH       EAX
//         0045fe7f     CALL       __ftol                                           undefined __ftol()
//         0045fe84     PUSH       EAX
//         0045fe85     MOV        this,EDI
//         0045fe87     CALL       Path::lastWaypoint                               Waypoint * lastWaypoint(Path * this)
//         0045fe8c     FLD        float ptr [EAX + 0x4]
//         0045fe8f     CALL       __ftol                                           undefined __ftol()
//         0045fe94     PUSH       EAX
//         0045fe95     MOV        this,EDI
//         0045fe97     CALL       Path::lastWaypoint                               Waypoint * lastWaypoint(Path * this)
//         0045fe9c     FLD        float ptr [EAX]
//         0045fe9e     CALL       __ftol                                           undefined __ftol()
//         0045fea3     PUSH       EAX
//         0045fea4     MOV        this,pathSystem
//         0045fea9     CALL       PathingSystem::findTilePath                      int findTilePath(PathingSystem * this, int pa
//                              move_obj.cpp:2427 (7)
//         0045feae     MOV        byte ptr [ESI + 0x154],0x0
//                              move_obj.cpp:2432 (22)
//         0045feb5     POP        EDI
//         0045feb6     POP        ESI
//         0045feb7     POP        EBP
//         0045feb8     POP        EBX
//         0045feb9     ADD        ESP,0x14
//         0045febc     RET        0x1c
//                               LAB_0045febf                                                 XREF[4]:     0045fbef(j), 0045fbf7(j),
//                                                                                                         0045fc50(j), 0045fcea(j)
//         0045febf     POP        EDI
//         0045fec0     POP        ESI
//         0045fec1     POP        EBP
//         0045fec2     XOR        EAX,EAX
//         0045fec4     POP        EBX
//         0045fec5     ADD        ESP,0x14
//         0045fec8     RET        0x1c
//         0045fecb     ??         90h
//         0045fecc     NOP
//         0045fecd     NOP
//         0045fece     NOP
//         0045fecf     NOP
    return 0;
}

int RGE_Moving_Object::canPathWithObstructions(int param_1, float param_2, float* param_3, int param_4, int param_5, int param_6, ManagedArray_int* param_7) {
    /* TODO: Stub */
//                              int __thiscall canPathWithObstructions(RGE_Moving_Object * this, int
//              int               EAX:4          <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[3]:     0045fed3(R), 00460010(R), 0046007b(R)
//              float             Stack[0x8]:4   param_2                   XREF[1]:     0045ff93(R)
//              float *           Stack[0xc]:4   param_3                   XREF[2]:     0046000c(R), 00460077(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     0045ffeb(R)
//              int               Stack[0x14]:4  param_5                   XREF[2]:     00460008(R), 00460073(R)
//              int               Stack[0x18]:4  param_6                   XREF[2]:     00460004(R), 0046006f(R)
//              ManagedArray<i    Stack[0x1c]:4  param_7                   XREF[2]:     00460059(R), 004600c4(R)
//              XYPoint           Stack[-0xc]:8  goal                      XREF[2,2]:   0045ffb0(W), 0045ffc9(R), 0045ffbc(W), 0045ffc5(R)
//              XYPoint           Stack[-0x14]:8 start                     XREF[0,2]:   0045ffa4(W), 0045ffcf(R)
//                               ?canPathWithObstructions@RGE_Moving_Object@@UAEHHMPAMHHHAAV  XREF[6]:     0056e5c0(*), 0056f3f8(*),
//                               RGE_Moving_Object::canPathWithObstructions                                00570890(*), 00570ae8(*),
//                                                                                                         00574918(*), 00574bc0(*)
//                              move_obj.cpp:2439 (3)
//         0045fed0     SUB        ESP,0x10
//                              move_obj.cpp:2444 (24)
//         0045fed3     MOV        EAX,dword ptr [ESP + param_1]
//         0045fed7     PUSH       EBX
//         0045fed8     PUSH       EBP
//         0045fed9     PUSH       ESI
//         0045feda     MOV        ESI,this
//         0045fedc     PUSH       EDI
//         0045fedd     PUSH       EAX
//         0045fede     MOV        this,dword ptr [ESI + 0xc]
//         0045fee1     MOV        this,dword ptr [ECX + this->_padding_]
//         0045fee4     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
//         0045fee9     MOV        EDI,EAX
//                              move_obj.cpp:2445 (4)
//         0045feeb     TEST       EDI,EDI
//         0045feed     JNZ        LAB_0045fef9
//                              move_obj.cpp:2501 (10)
//         0045feef     POP        EDI
//         0045fef0     POP        ESI
//         0045fef1     POP        EBP
//         0045fef2     POP        EBX
//         0045fef3     ADD        ESP,0x10
//         0045fef6     RET        0x1c
//                               LAB_0045fef9                                                 XREF[1]:     0045feed(j)
//                              move_obj.cpp:2450 (11)
//         0045fef9     MOV        EAX,dword ptr [ESI + 0x7c]
//         0045fefc     LEA        EBX,[ESI + 0x7c]
//         0045feff     CMP        EAX,-0x1
//         0045ff02     JNZ        LAB_0045ff2c
//                              move_obj.cpp:2453 (40)
//         0045ff04     MOV        EDX,dword ptr [ESI + 0xc]
//         0045ff07     PUSH       EBX
//         0045ff08     MOV        EAX,dword ptr [EDX + 0x3c]
//         0045ff0b     MOV        EDX,dword ptr [ESI + 0x8]
//         0045ff0e     MOVSX      this,word ptr [EAX + 0x52]
//         0045ff12     PUSH       this
//         0045ff13     MOVSX      this,word ptr [EDX + 0x66]
//         0045ff17     MOV        EDX,dword ptr [EAX + 0x54]
//         0045ff1a     MOV        this,dword ptr [EDX + this->_padding_*0x4]
//         0045ff1d     MOV        EDX,dword ptr [EAX + 0x28]
//         0045ff20     PUSH       this
//         0045ff21     MOV        this,dword ptr [EDX + 0x8dc4]
//         0045ff27     CALL       RGE_Zone_Map_List::get_zone_map                  RGE_Zone_Map * get_zone_map(RGE_Zone_Map_List
//                               LAB_0045ff2c                                                 XREF[1]:     0045ff02(j)
//                              move_obj.cpp:2455 (25)
//         0045ff2c     MOV        this,dword ptr [ESI + 0xc]
//         0045ff2f     MOV        EAX,dword ptr [EBX]
//         0045ff31     PUSH       EAX
//         0045ff32     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0045ff35     MOV        EAX,dword ptr [EDX + 0x28]
//         0045ff38     MOV        this,dword ptr [EAX + 0x8dc4]
//         0045ff3e     CALL       RGE_Zone_Map_List::get_zone_map                  RGE_Zone_Map * get_zone_map(RGE_Zone_Map_List
//         0045ff43     MOV        EBP,EAX
//                              move_obj.cpp:2456 (4)
//         0045ff45     TEST       EBP,EBP
//         0045ff47     JNZ        LAB_0045ff53
//                              move_obj.cpp:2501 (10)
//         0045ff49     POP        EDI
//         0045ff4a     POP        ESI
//         0045ff4b     POP        EBP
//         0045ff4c     POP        EBX
//         0045ff4d     ADD        ESP,0x10
//         0045ff50     RET        0x1c
//                               LAB_0045ff53                                                 XREF[1]:     0045ff47(j)
//                              move_obj.cpp:2458 (25)
//         0045ff53     FLD        float ptr [ESI + 0x3c]
//         0045ff56     CALL       __ftol                                           undefined __ftol()
//         0045ff5b     FLD        float ptr [ESI + 0x38]
//         0045ff5e     PUSH       EAX
//         0045ff5f     CALL       __ftol                                           undefined __ftol()
//         0045ff64     PUSH       EAX
//         0045ff65     MOV        this,EBP
//         0045ff67     CALL       RGE_Zone_Map::get_zone_info                      uchar get_zone_info(RGE_Zone_Map * this, long
//                              move_obj.cpp:2463 (37)
//         0045ff6c     FLD        float ptr [EDI + 0x3c]
//         0045ff6f     AND        EAX,0xff
//         0045ff74     MOV        EBX,EAX
//         0045ff76     CALL       __ftol                                           undefined __ftol()
//         0045ff7b     FLD        float ptr [EDI + 0x38]
//         0045ff7e     PUSH       EAX
//         0045ff7f     CALL       __ftol                                           undefined __ftol()
//         0045ff84     PUSH       EAX
//         0045ff85     MOV        this,EBP
//         0045ff87     CALL       RGE_Zone_Map::get_zone_info                      uchar get_zone_info(RGE_Zone_Map * this, long
//         0045ff8c     AND        EAX,0xff
//                              move_obj.cpp:2464 (8)
//         0045ff91     CMP        EAX,EBX
//         0045ff93     MOV        EBX,dword ptr [ESP + param_2]
//         0045ff97     JZ         LAB_0045ffeb
//                              move_obj.cpp:2466 (8)
//         0045ff99     FLD        float ptr [ESI + 0x38]
//         0045ff9c     CALL       __ftol                                           undefined __ftol()
//                              move_obj.cpp:2467 (12)
//         0045ffa1     FLD        float ptr [ESI + 0x3c]
//         0045ffa4     MOV        dword ptr [ESP + start.y],EAX
//         0045ffa8     CALL       __ftol                                           undefined __ftol()
//                              move_obj.cpp:2469 (12)
//         0045ffad     FLD        float ptr [EDI + 0x38]
//         0045ffb0     MOV        dword ptr [ESP + goal.x],EAX
//         0045ffb4     CALL       __ftol                                           undefined __ftol()
//                              move_obj.cpp:2470 (12)
//         0045ffb9     FLD        float ptr [EDI + 0x3c]
//         0045ffbc     MOV        dword ptr [ESP + goal.y],EAX
//         0045ffc0     CALL       __ftol                                           undefined __ftol()
//                              move_obj.cpp:2471 (28)
//         0045ffc5     MOV        this,dword ptr [ESP + goal.y]
//         0045ffc9     MOV        EDX,dword ptr [ESP + goal.x]
//         0045ffcd     PUSH       EBX
//         0045ffce     PUSH       EAX
//         0045ffcf     MOV        EAX,dword ptr [ESP + start.y]
//         0045ffd3     PUSH       this
//         0045ffd4     PUSH       EDX
//         0045ffd5     PUSH       EAX
//         0045ffd6     MOV        this,EBP
//         0045ffd8     CALL       RGE_Zone_Map::withinRange                        int withinRange(RGE_Zone_Map * this, XYPoint
//         0045ffdd     TEST       EAX,EAX
//         0045ffdf     JNZ        LAB_0045ffeb
//                              move_obj.cpp:2501 (10)
//         0045ffe1     POP        EDI
//         0045ffe2     POP        ESI
//         0045ffe3     POP        EBP
//         0045ffe4     POP        EBX
//         0045ffe5     ADD        ESP,0x10
//         0045ffe8     RET        0x1c
//                               LAB_0045ffeb                                                 XREF[2]:     0045ff97(j), 0045ffdf(j)
//                              move_obj.cpp:2476 (15)
//         0045ffeb     MOV        EAX,dword ptr [ESP + param_4]
//         0045ffef     MOV        byte ptr [ESI + 0x154],0x1
//         0045fff6     TEST       EAX,EAX
//         0045fff8     JZ         LAB_00460065
//                              move_obj.cpp:2477 (10)
//         0045fffa     MOV        this,aiPathSystem
//         0045ffff     CALL       PathingSystem::incrementCanPaths                 void incrementCanPaths(PathingSystem * this)
//                              move_obj.cpp:2481 (78)
//         00460004     MOV        EBP,dword ptr [ESP + param_6]
//         00460008     MOV        this,dword ptr [ESP + param_5]
//         0046000c     MOV        EDX,dword ptr [ESP + param_3]
//         00460010     MOV        EAX,dword ptr [ESP + param_1]
//         00460014     PUSH       EBP
//         00460015     PUSH       this
//         00460016     FLD        float ptr [EDI + 0x3c]
//         00460019     PUSH       0x1
//         0046001b     PUSH       0x1
//         0046001d     PUSH       0x1
//         0046001f     PUSH       0x1
//         00460021     PUSH       EDX
//         00460022     PUSH       0x1
//         00460024     PUSH       EAX
//         00460025     PUSH       EBX
//         00460026     PUSH       ESI
//         00460027     CALL       __ftol                                           undefined __ftol()
//         0046002c     FLD        float ptr [EDI + 0x38]
//         0046002f     PUSH       EAX
//         00460030     CALL       __ftol                                           undefined __ftol()
//         00460035     FLD        float ptr [ESI + 0x3c]
//         00460038     PUSH       EAX
//         00460039     CALL       __ftol                                           undefined __ftol()
//         0046003e     FLD        float ptr [ESI + 0x38]
//         00460041     PUSH       EAX
//         00460042     CALL       __ftol                                           undefined __ftol()
//         00460047     PUSH       EAX
//         00460048     MOV        this,aiPathSystem
//         0046004d     CALL       PathingSystem::findTilePath                      int findTilePath(PathingSystem * this, int pa
//                              move_obj.cpp:2485 (7)
//         00460052     CMP        EBP,-0x1
//         00460055     MOV        EDI,EAX
//         00460057     JZ         LAB_004600d3
//                              move_obj.cpp:2486 (10)
//         00460059     MOV        this,dword ptr [ESP + param_7]
//         0046005d     PUSH       this
//         0046005e     MOV        this,aiPathSystem
//                              move_obj.cpp:2488 (2)
//         00460063     JMP        LAB_004600ce
//                               LAB_00460065                                                 XREF[1]:     0045fff8(j)
//                              move_obj.cpp:2490 (10)
//         00460065     MOV        this,pathSystem
//         0046006a     CALL       PathingSystem::incrementCanPaths                 void incrementCanPaths(PathingSystem * this)
//                              move_obj.cpp:2494 (78)
//         0046006f     MOV        EBP,dword ptr [ESP + param_6]
//         00460073     MOV        EDX,dword ptr [ESP + param_5]
//         00460077     MOV        EAX,dword ptr [ESP + param_3]
//         0046007b     MOV        this,dword ptr [ESP + param_1]
//         0046007f     PUSH       EBP
//         00460080     PUSH       EDX
//         00460081     FLD        float ptr [EDI + 0x3c]
//         00460084     PUSH       0x1
//         00460086     PUSH       0x1
//         00460088     PUSH       0x1
//         0046008a     PUSH       0x1
//         0046008c     PUSH       EAX
//         0046008d     PUSH       0x1
//         0046008f     PUSH       this
//         00460090     PUSH       EBX
//         00460091     PUSH       ESI
//         00460092     CALL       __ftol                                           undefined __ftol()
//         00460097     FLD        float ptr [EDI + 0x38]
//         0046009a     PUSH       EAX
//         0046009b     CALL       __ftol                                           undefined __ftol()
//         004600a0     FLD        float ptr [ESI + 0x3c]
//         004600a3     PUSH       EAX
//         004600a4     CALL       __ftol                                           undefined __ftol()
//         004600a9     FLD        float ptr [ESI + 0x38]
//         004600ac     PUSH       EAX
//         004600ad     CALL       __ftol                                           undefined __ftol()
//         004600b2     PUSH       EAX
//         004600b3     MOV        this,pathSystem
//         004600b8     CALL       PathingSystem::findTilePath                      int findTilePath(PathingSystem * this, int pa
//                              move_obj.cpp:2497 (7)
//         004600bd     CMP        EBP,-0x1
//         004600c0     MOV        EDI,EAX
//         004600c2     JZ         LAB_004600d3
//                              move_obj.cpp:2498 (15)
//         004600c4     MOV        EDX,dword ptr [ESP + param_7]
//         004600c8     MOV        this,pathSystem
//         004600cd     PUSH       EDX
//                               LAB_004600ce                                                 XREF[1]:     00460063(j)
//         004600ce     CALL       PathingSystem::copyUnobstructibles               void copyUnobstructibles(PathingSystem * this
//                               LAB_004600d3                                                 XREF[2]:     00460057(j), 004600c2(j)
//                              move_obj.cpp:2500 (9)
//         004600d3     MOV        EAX,EDI
//         004600d5     MOV        byte ptr [ESI + 0x154],0x0
//                              move_obj.cpp:2501 (10)
//         004600dc     POP        EDI
//         004600dd     POP        ESI
//         004600de     POP        EBP
//         004600df     POP        EBX
//         004600e0     ADD        ESP,0x10
//         004600e3     RET        0x1c
//         004600e6     ??         90h
//         004600e7     NOP
//         004600e8     NOP
//         004600e9     NOP
//         004600ea     NOP
//         004600eb     NOP
//         004600ec     NOP
//         004600ed     NOP
//         004600ee     NOP
//         004600ef     NOP
    return 0;
}

int RGE_Moving_Object::canPathWithAdditionalPassability(XYZPoint param_1, float param_2, int param_3, float* param_4, int param_5, int param_6, int param_7, int param_8, int param_9) {
    /* TODO: Stub */
//                              int __thiscall canPathWithAdditionalPassability(RGE_Moving_Object *
//              int               EAX:4          <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//              XYZPoint          Stack[0x4]:12  param_1                   XREF[1,1]:   004600f3(R), 00460101(R)
//              float             Stack[0x10]:4  param_2                   XREF[2]:     00460167(R), 004601b0(R)
//              int               Stack[0x14]:4  param_3                   XREF[2]:     00460162(R), 004601ab(R)
//              float *           Stack[0x18]:4  param_4                   XREF[2]:     0046015d(R), 004601a6(R)
//              int               Stack[0x1c]:4  param_5                   XREF[1]:     0046012c(R)
//              int               Stack[0x20]:4  param_6                   XREF[1]:     00460128(R)
//              int               Stack[0x24]:4  param_7                   XREF[1]:     00460136(R)
//              int               Stack[0x28]:4  param_8                   XREF[2]:     00460159(R), 004601a2(R)
//              int               Stack[0x2c]:4  param_9                   XREF[2]:     00460155(R), 0046019e(R)
//                               ?canPathWithAdditionalPassability@RGE_Moving_Object@@UAEHUX  XREF[6]:     0056e5c4(*), 0056f3fc(*),
//                               RGE_Moving_Object::canPathWithAdditionalPassability                       00570894(*), 00570aec(*),
//                                                                                                         0057491c(*), 00574bc4(*)
//                              move_obj.cpp:2509 (3)
//         004600f0     PUSH       EBX
//         004600f1     PUSH       ESI
//         004600f2     PUSH       EDI
//                              move_obj.cpp:2516 (53)
//         004600f3     MOV        EDI,dword ptr [ESP + param_1.x]
//         004600f7     TEST       EDI,EDI
//         004600f9     MOV        ESI,this
//         004600fb     JL         LAB_004601fc
//         00460101     MOV        EBX,dword ptr [ESP + param_1.y]
//         00460105     TEST       EBX,EBX
//         00460107     JL         LAB_004601fc
//         0046010d     MOV        EAX,dword ptr [ESI + 0xc]
//         00460110     MOV        this,dword ptr [EAX + 0x3c]
//         00460113     MOV        EAX,dword ptr [ECX + this->_padding_]
//         00460116     CMP        EDI,dword ptr [EAX + 0x8]
//         00460119     JGE        LAB_004601fc
//         0046011f     CMP        EBX,dword ptr [EAX + 0xc]
//         00460122     JGE        LAB_004601fc
//                              move_obj.cpp:2522 (14)
//         00460128     MOV        EAX,dword ptr [ESP + param_6]
//         0046012c     MOV        EDX,dword ptr [ESP + param_5]
//         00460130     MOV        dword ptr [ESI + 0x150],EAX
//                              move_obj.cpp:2525 (21)
//         00460136     MOV        EAX,dword ptr [ESP + param_7]
//         0046013a     TEST       EAX,EAX
//         0046013c     MOV        dword ptr [ESI + 0x14c],EDX
//         00460142     MOV        byte ptr [ESI + 0x154],0x1
//         00460149     JZ         LAB_00460194
//                              move_obj.cpp:2526 (10)
//         0046014b     MOV        this,aiPathSystem
//         00460150     CALL       PathingSystem::incrementCanPaths                 void incrementCanPaths(PathingSystem * this)
//                              move_obj.cpp:2530 (61)
//         00460155     MOV        this,dword ptr [ESP + param_9]
//         00460159     MOV        EDX,dword ptr [ESP + param_8]
//         0046015d     MOV        EAX,dword ptr [ESP + param_4]
//         00460161     PUSH       this
//         00460162     MOV        this,dword ptr [ESP + param_3]
//         00460166     PUSH       EDX
//         00460167     MOV        EDX,dword ptr [ESP + param_2]
//         0046016b     PUSH       0x1
//         0046016d     PUSH       0x1
//         0046016f     PUSH       0x1
//         00460171     FLD        float ptr [ESI + 0x3c]
//         00460174     PUSH       0x1
//         00460176     PUSH       EAX
//         00460177     PUSH       0x1
//         00460179     PUSH       this
//         0046017a     PUSH       EDX
//         0046017b     PUSH       ESI
//         0046017c     PUSH       EBX
//         0046017d     PUSH       EDI
//         0046017e     CALL       __ftol                                           undefined __ftol()
//         00460183     FLD        float ptr [ESI + 0x38]
//         00460186     PUSH       EAX
//         00460187     CALL       __ftol                                           undefined __ftol()
//         0046018c     PUSH       EAX
//         0046018d     MOV        this,aiPathSystem
//                              move_obj.cpp:2532 (2)
//         00460192     JMP        LAB_004601db
//                               LAB_00460194                                                 XREF[1]:     00460149(j)
//                              move_obj.cpp:2533 (10)
//         00460194     MOV        this,pathSystem
//         00460199     CALL       PathingSystem::incrementCanPaths                 void incrementCanPaths(PathingSystem * this)
//                              move_obj.cpp:2537 (66)
//         0046019e     MOV        EAX,dword ptr [ESP + param_9]
//         004601a2     MOV        this,dword ptr [ESP + param_8]
//         004601a6     MOV        EDX,dword ptr [ESP + param_4]
//         004601aa     PUSH       EAX
//         004601ab     MOV        EAX,dword ptr [ESP + param_3]
//         004601af     PUSH       this
//         004601b0     MOV        this,dword ptr [ESP + param_2]
//         004601b4     PUSH       0x1
//         004601b6     PUSH       0x1
//         004601b8     PUSH       0x1
//         004601ba     FLD        float ptr [ESI + 0x3c]
//         004601bd     PUSH       0x1
//         004601bf     PUSH       EDX
//         004601c0     PUSH       0x1
//         004601c2     PUSH       EAX
//         004601c3     PUSH       this
//         004601c4     PUSH       ESI
//         004601c5     PUSH       EBX
//         004601c6     PUSH       EDI
//         004601c7     CALL       __ftol                                           undefined __ftol()
//         004601cc     FLD        float ptr [ESI + 0x38]
//         004601cf     PUSH       EAX
//         004601d0     CALL       __ftol                                           undefined __ftol()
//         004601d5     PUSH       EAX
//         004601d6     MOV        this,pathSystem
//                               LAB_004601db                                                 XREF[1]:     00460192(j)
//         004601db     CALL       PathingSystem::findTilePath                      int findTilePath(PathingSystem * this, int pa
//                              move_obj.cpp:2541 (3)
//         004601e0     OR         this,0xffffffff
//                              move_obj.cpp:2543 (19)
//         004601e3     MOV        byte ptr [ESI + 0x154],0x0
//         004601ea     MOV        dword ptr [ESI + 0x14c],this
//         004601f0     MOV        dword ptr [ESI + 0x150],this
//                              move_obj.cpp:2545 (14)
//         004601f6     POP        EDI
//         004601f7     POP        ESI
//         004601f8     POP        EBX
//         004601f9     RET        0x2c
//                               LAB_004601fc                                                 XREF[4]:     004600fb(j), 00460107(j),
//                                                                                                         00460119(j), 00460122(j)
//         004601fc     POP        EDI
//         004601fd     POP        ESI
//         004601fe     XOR        EAX,EAX
//         00460200     POP        EBX
//         00460201     RET        0x2c
//         00460204     ??         90h
//         00460205     NOP
//         00460206     NOP
//         00460207     NOP
//         00460208     NOP
//         00460209     NOP
//         0046020a     NOP
//         0046020b     NOP
//         0046020c     NOP
//         0046020d     NOP
//         0046020e     NOP
//         0046020f     NOP
    return 0;
}

int RGE_Moving_Object::findFirstTerrainAlongExceptionPath(int param_1, float* param_2, float* param_3) {
    /* TODO: Stub */
//                              int __thiscall findFirstTerrainAlongExceptionPath(RGE_Moving_Object
//              int               EAX:4          <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004602bf(R)
//              float *           Stack[0x8]:4   param_2                   XREF[1]:     0046035f(R)
//              float *           Stack[0xc]:4   param_3                   XREF[1]:     00460363(R)
//              XYPoint           Stack[-0xc]:8  rVal                      XREF[1,1]:   004602a3(W), 004602cc(*)
//              XYPoint           Stack[-0x14]:8 p2                        XREF[1,2]:   00460268(W), 00460290(W), 004602d1(*)
//              XYPoint           Stack[-0x1c]:8 p1                        XREF[1,2]:   004602a7(W), 00460255(W), 004602d6(*)
//              int               Stack[-0x20]:4 i
//                               ?findFirstTerrainAlongExceptionPath@RGE_Moving_Object@@UAEH  XREF[6]:     0056e5c8(*), 0056f400(*),
//                               RGE_Moving_Object::findFirstTerrainAlongExceptionPath                     00570898(*), 00570af0(*),
//                                                                                                         00574920(*), 00574bc8(*)
//                              move_obj.cpp:2551 (8)
//         00460210     SUB        ESP,0x1c
//         00460213     PUSH       EBX
//         00460214     MOV        EBX,this
//         00460216     PUSH       EBP
//         00460217     PUSH       ESI
//                              move_obj.cpp:2552 (17)
//         00460218     LEA        ESI,[EBX + 0xd8]
//         0046021e     PUSH       EDI
//         0046021f     MOV        this,ESI
//         00460221     CALL       Path::numberOfWaypoints                          int numberOfWaypoints(Path * this)
//         00460226     CMP        EAX,0x2
//                              move_obj.cpp:2553 (6)
//         00460229     JL         LAB_00460373
//                              move_obj.cpp:2556 (7)
//         0046022f     MOV        this,ESI
//         00460231     CALL       Path::initToStart                                void initToStart(Path * this)
//                              move_obj.cpp:2557 (9)
//         00460236     MOV        this,ESI
//         00460238     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         0046023d     TEST       EAX,EAX
//                              move_obj.cpp:2558 (6)
//         0046023f     JZ         LAB_00460373
//                              move_obj.cpp:2560 (14)
//         00460245     MOV        this,ESI
//         00460247     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         0046024c     FLD        float ptr [EAX]
//         0046024e     CALL       __ftol                                           undefined __ftol()
//                              move_obj.cpp:2561 (19)
//         00460253     MOV        this,ESI
//         00460255     MOV        dword ptr [ESP + p1.y],EAX
//         00460259     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         0046025e     FLD        float ptr [EAX + 0x4]
//         00460261     CALL       __ftol                                           undefined __ftol()
//                              move_obj.cpp:2562 (11)
//         00460266     MOV        this,ESI
//         00460268     MOV        dword ptr [ESP + p2.x],EAX
//         0046026c     CALL       Path::moveToNextWaypoint                         int moveToNextWaypoint(Path * this)
//                              move_obj.cpp:2563 (9)
//         00460271     MOV        this,ESI
//         00460273     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         00460278     TEST       EAX,EAX
//                              move_obj.cpp:2564 (6)
//         0046027a     JZ         LAB_00460373
//                              move_obj.cpp:2566 (14)
//         00460280     MOV        this,ESI
//         00460282     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         00460287     FLD        float ptr [EAX]
//         00460289     CALL       __ftol                                           undefined __ftol()
//                              move_obj.cpp:2567 (19)
//         0046028e     MOV        this,ESI
//         00460290     MOV        dword ptr [ESP + p2.y],EAX
//         00460294     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         00460299     FLD        float ptr [EAX + 0x4]
//         0046029c     CALL       __ftol                                           undefined __ftol()
//                              move_obj.cpp:2569 (28)
//         004602a1     MOV        this,ESI
//         004602a3     MOV        dword ptr [ESP + rVal.x],EAX
//         004602a7     MOV        dword ptr [ESP + p1.x],0x1
//         004602af     CALL       Path::numberOfWaypoints                          int numberOfWaypoints(Path * this)
//         004602b4     CMP        EAX,0x1
//         004602b7     JLE        LAB_0046035f
//                              move_obj.cpp:2573 (44)
//         004602bd     MOV        EAX,dword ptr [EBX]
//         004602bf     MOV        EDI,dword ptr [ESP + param_1]
//         004602c3     MOV        EBP,dword ptr [EAX + 0x1b4]
//                               LAB_004602c9                                                 XREF[1]:     00460359(j)
//         004602c9     PUSH       0x1
//         004602cb     PUSH       EDI=>DAT_fffffff8
//         004602cc     LEA        this=>rVal.y,[ESP + 0x2c]
//         004602d0     PUSH       EDI=>DAT_fffffff4
//         004602d1     LEA        EDX=>p2.y,[ESP + 0x28]
//         004602d5     PUSH       this=>DAT_fffffff0
//         004602d6     LEA        EAX=>p1.y,[ESP + 0x24]
//         004602da     PUSH       EDX
//         004602db     PUSH       EAX
//         004602dc     MOV        this,EBX
//         004602de     CALL       EBP
//         004602e0     CMP        EAX,0x1
//         004602e3     JZ         LAB_0046037f
//                              move_obj.cpp:2580 (14)
//         004602e9     MOV        this,ESI
//         004602eb     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         004602f0     FLD        float ptr [EAX]
//         004602f2     CALL       __ftol                                           undefined __ftol()
//                              move_obj.cpp:2581 (19)
//         004602f7     MOV        this,ESI
//         004602f9     MOV        dword ptr [ESP + 0x14],EAX
//         004602fd     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         00460302     FLD        float ptr [EAX + 0x4]
//         00460305     CALL       __ftol                                           undefined __ftol()
//                              move_obj.cpp:2582 (11)
//         0046030a     MOV        this,ESI
//         0046030c     MOV        dword ptr [ESP + 0x18],EAX
//         00460310     CALL       Path::moveToNextWaypoint                         int moveToNextWaypoint(Path * this)
//                              move_obj.cpp:2583 (11)
//         00460315     MOV        this,ESI
//         00460317     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         0046031c     TEST       EAX,EAX
//         0046031e     JZ         LAB_00460373
//                              move_obj.cpp:2585 (14)
//         00460320     MOV        this,ESI
//         00460322     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         00460327     FLD        float ptr [EAX]
//         00460329     CALL       __ftol                                           undefined __ftol()
//                              move_obj.cpp:2586 (49)
//         0046032e     MOV        this,ESI
//         00460330     MOV        dword ptr [ESP + 0x1c],EAX
//         00460334     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         00460339     FLD        float ptr [EAX + 0x4]
//         0046033c     CALL       __ftol                                           undefined __ftol()
//         00460341     MOV        EDX,dword ptr [ESP + 0x10]
//         00460345     MOV        this,ESI
//         00460347     INC        EDX
//         00460348     MOV        dword ptr [ESP + 0x20],EAX
//         0046034c     MOV        dword ptr [ESP + 0x10],EDX
//         00460350     CALL       Path::numberOfWaypoints                          int numberOfWaypoints(Path * this)
//         00460355     CMP        dword ptr [ESP + 0x10],EAX
//         00460359     JL         LAB_004602c9
//                               LAB_0046035f                                                 XREF[1]:     004602b7(j)
//                              move_obj.cpp:2590 (4)
//         0046035f     MOV        EAX,dword ptr [ESP + param_2]
//                              move_obj.cpp:2591 (16)
//         00460363     MOV        this,dword ptr [ESP + param_3]
//         00460367     MOV        dword ptr [EAX],0xbf800000
//         0046036d     MOV        dword ptr [this->_padding_],0xbf800000
//                               LAB_00460373                                                 XREF[4]:     00460229(j), 0046023f(j),
//                                                                                                         0046027a(j), 0046031e(j)
//                              move_obj.cpp:2592 (2)
//         00460373     XOR        EAX,EAX
//                              move_obj.cpp:2593 (10)
//         00460375     POP        EDI
//         00460376     POP        ESI
//         00460377     POP        EBP
//         00460378     POP        EBX
//         00460379     ADD        ESP,0x1c
//         0046037c     RET        0xc
//                               LAB_0046037f                                                 XREF[1]:     004602e3(j)
//                              move_obj.cpp:2574 (4)
//         0046037f     FILD       dword ptr [ESP + 0x24]
//                              move_obj.cpp:2576 (8)
//         00460383     MOV        this,dword ptr [ESP + 0x34]
//         00460387     MOV        EDX,dword ptr [ESP + 0x38]
//                              move_obj.cpp:2593 (27)
//         0046038b     POP        EDI
//         0046038c     POP        ESI
//         0046038d     FSUB       float ptr [DAT_00570b80]
//         00460393     POP        EBP
//         00460394     MOV        EAX,0x1
//         00460399     POP        EBX
//         0046039a     FLD        ST0
//         0046039c     FSTP       float ptr [this->_padding_]
//         0046039e     FSTP       float ptr [EDX]
//         004603a0     ADD        ESP,0x1c
//         004603a3     RET        0xc
//         004603a6     ??         90h
//         004603a7     NOP
//         004603a8     NOP
//         004603a9     NOP
//         004603aa     NOP
//         004603ab     NOP
//         004603ac     NOP
//         004603ad     NOP
//         004603ae     NOP
//         004603af     NOP
    return 0;
}

int RGE_Moving_Object::canLinePath(XYPoint* param_1, XYPoint* param_2, float param_3, XYPoint* param_4, int param_5) {
    /* TODO: Stub */
//                              int __thiscall canLinePath(RGE_Moving_Object * this, XYPoint * param
//              int               EAX:4          <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//              XYPoint *         Stack[0x4]:4   param_1                   XREF[9]:     004603b3(R), 004603d0(W), 004603d6(R), 004603da(W),
//                                                                                     004603e2(R), 00460481(W), 00460491(R), 004604a3(W),
//                                                                                     004604d4(R)
//              XYPoint *         Stack[0x8]:4   param_2                   XREF[1]:     004603b7(R)
//              float             Stack[0xc]:4   param_3
//              XYPoint *         Stack[0x10]:4  param_4
//              int               Stack[0x14]:4  param_5                   XREF[1]:     004604c9(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0046047d(W), 0046049d(R)
//              float             Stack[-0x8]:4  yStep                     XREF[2]:     00460477(W), 00460495(R)
//              float             Stack[-0xc]:4  xStep                     XREF[3]:     0046045d(W), 00460522(R), 0046052d(W)
//              int               Stack[-0x10]:4 i                         XREF[2]:     004603c7(W), 0046046d(R)
//              undefined4        Stack[-0x14]:4 local_14                  XREF[3]:     00460467(W), 004604c3(R), 004604de(W)
//              int               Stack[-0x18]:4 priorY                    XREF[4]:     00460436(W), 0046044a(W), 0046044e(R), 00460526(R)
//              int               Stack[-0x1c]:4 numSteps                  XREF[7]:     004603de(W), 00460471(R), 00460485(W), 00460499(R),
//                                                                                     004604a9(W), 004604b2(R), 004604cd(R)
//              float             Stack[-0x20]:4 yTile
//                               ?canLinePath@RGE_Moving_Object@@UAEHABUXYPoint@@0MAAU2@H@Z   XREF[6]:     0056e5d0(*), 0056f408(*),
//                               RGE_Moving_Object::canLinePath                                            005708a0(*), 00570af8(*),
//                                                                                                         00574928(*), 00574bd0(*)
//                              move_obj.cpp:2600 (3)
//         004603b0     SUB        ESP,0x1c
//                              move_obj.cpp:2602 (17)
//         004603b3     MOV        EAX,dword ptr [ESP + param_1]
//         004603b7     MOV        EDX,dword ptr [ESP + param_2]
//         004603bb     PUSH       EBX
//         004603bc     PUSH       EBP
//         004603bd     MOV        EBX,this
//         004603bf     PUSH       ESI
//         004603c0     MOV        this,dword ptr [EAX]
//         004603c2     MOV        ESI,dword ptr [EDX]
//                              move_obj.cpp:2603 (34)
//         004603c4     MOV        EAX,dword ptr [EAX + 0x4]
//         004603c7     MOV        dword ptr [ESP + i],this
//         004603cb     SUB        ESI,this
//         004603cd     MOV        this,dword ptr [EDX + 0x4]
//         004603d0     MOV        dword ptr [ESP + param_1],ESI
//         004603d4     SUB        this,EAX
//         004603d6     FILD       dword ptr [ESP + param_1]
//         004603da     MOV        dword ptr [ESP + param_1],this
//         004603de     MOV        dword ptr [ESP + numSteps],EAX
//         004603e2     FILD       dword ptr [ESP + param_1]
//                              move_obj.cpp:2604 (33)
//         004603e6     FLD        ST1
//         004603e8     FCOMP      float ptr [DAT_00570b48]
//         004603ee     PUSH       EDI
//         004603ef     FNSTSW     AX
//         004603f1     TEST       AH,0x40
//         004603f4     JZ         LAB_00460413
//         004603f6     FCOM       float ptr [DAT_00570b48]
//         004603fc     FNSTSW     AX
//         004603fe     TEST       AH,0x40
//         00460401     JZ         LAB_00460413
//         00460403     FSTP       ST0
//         00460405     FSTP       ST0
//                              move_obj.cpp:2605 (2)
//         00460407     XOR        EAX,EAX
//                              move_obj.cpp:2655 (10)
//         00460409     POP        EDI
//         0046040a     POP        ESI
//         0046040b     POP        EBP
//         0046040c     POP        EBX
//         0046040d     ADD        ESP,0x1c
//         00460410     RET        0x14
//                               LAB_00460413                                                 XREF[2]:     004603f4(j), 00460401(j)
//                              move_obj.cpp:2609 (21)
//         00460413     FLD        ST0
//         00460415     FLD        ST2
//         00460417     FXCH
//         00460419     FABS
//         0046041b     FXCH
//         0046041d     FABS
//         0046041f     FCOMPP
//         00460421     FNSTSW     AX
//         00460423     TEST       AH,0x1
//         00460426     JZ         LAB_0046043c
//                              move_obj.cpp:2610 (18)
//         00460428     FLD        ST0
//         0046042a     CALL       __ftol                                           undefined __ftol()
//         0046042f     CDQ
//         00460430     XOR        EAX,EDX
//         00460432     SUB        EAX,EDX
//         00460434     SHL        EAX,0x1
//         00460436     MOV        dword ptr [ESP + priorY],EAX
//                              move_obj.cpp:2611 (2)
//         0046043a     JMP        LAB_0046044e
//                               LAB_0046043c                                                 XREF[1]:     00460426(j)
//                              move_obj.cpp:2612 (18)
//         0046043c     FLD        ST1
//         0046043e     CALL       __ftol                                           undefined __ftol()
//         00460443     CDQ
//         00460444     XOR        EAX,EDX
//         00460446     SUB        EAX,EDX
//         00460448     SHL        EAX,0x1
//         0046044a     MOV        dword ptr [ESP + priorY],EAX
//                               LAB_0046044e                                                 XREF[1]:     0046043a(j)
//                              move_obj.cpp:2614 (4)
//         0046044e     FILD       dword ptr [ESP + priorY]
//                              move_obj.cpp:2615 (6)
//         00460452     FXCH       ST2
//         00460454     FDIV       ST0,ST2
//         00460456     FXCH
//                              move_obj.cpp:2622 (57)
//         00460458     MOV        EBP,0xfffffc19
//         0046045d     MOV        dword ptr [ESP + xStep],0x0
//         00460465     TEST       EAX,EAX
//         00460467     MOV        dword ptr [ESP + local_14],EBP
//         0046046b     FDIV       ST0,ST2
//         0046046d     FILD       dword ptr [ESP + i]
//         00460471     FILD       dword ptr [ESP + numSteps]
//         00460475     FXCH       ST3
//         00460477     FSTP       float ptr [ESP + yStep]
//         0046047b     FXCH
//         0046047d     FSTP       float ptr [ESP + local_4]
//         00460481     FSTP       float ptr [ESP + param_1]
//         00460485     FSTP       float ptr [ESP + numSteps]
//         00460489     FSTP       ST0
//         0046048b     JLE        LAB_0046055b
//                               LAB_00460491                                                 XREF[1]:     00460531(j)
//                              move_obj.cpp:2625 (8)
//         00460491     FLD        float ptr [ESP + param_1]
//         00460495     FADD       float ptr [ESP + yStep]
//                              move_obj.cpp:2626 (16)
//         00460499     FLD        float ptr [ESP + numSteps]
//         0046049d     FADD       float ptr [ESP + local_4]
//         004604a1     FXCH
//         004604a3     FST        float ptr [ESP + param_1]
//         004604a7     FXCH
//                              move_obj.cpp:2630 (9)
//         004604a9     FSTP       float ptr [ESP + numSteps]
//         004604ad     CALL       __ftol                                           undefined __ftol()
//                              move_obj.cpp:2631 (11)
//         004604b2     FLD        float ptr [ESP + numSteps]
//         004604b6     MOV        ESI,EAX
//         004604b8     CALL       __ftol                                           undefined __ftol()
//                              move_obj.cpp:2632 (12)
//         004604bd     CMP        ESI,EBP
//         004604bf     MOV        EDI,EAX
//         004604c1     JNZ        LAB_004604c9
//         004604c3     CMP        EDI,dword ptr [ESP + local_14]
//         004604c7     JZ         LAB_00460522
//                               LAB_004604c9                                                 XREF[1]:     004604c1(j)
//                              move_obj.cpp:2640 (35)
//         004604c9     MOV        EAX,dword ptr [ESP + param_5]
//         004604cd     MOV        this,dword ptr [ESP + numSteps]
//         004604d1     MOV        EDX,dword ptr [EBX]
//         004604d3     PUSH       EAX
//         004604d4     MOV        EAX,dword ptr [ESP + param_1]
//         004604d8     PUSH       this
//         004604d9     PUSH       EAX
//         004604da     MOV        this,EBX
//         004604dc     MOV        EBP,ESI
//         004604de     MOV        dword ptr [ESP + local_14],EDI
//         004604e2     CALL       dword ptr [EDX + 0x114]
//         004604e8     TEST       EAX,EAX
//         004604ea     JZ         LAB_00460546
//                              move_obj.cpp:2651 (54)
//         004604ec     MOV        EAX,dword ptr [ESP + 0x34]
//         004604f0     FILD       dword ptr [EAX + 0x4]
//         004604f3     FILD       dword ptr [EAX]
//         004604f5     FSUB       float ptr [ESP + 0x30]
//         004604f9     FXCH
//         004604fb     FSUB       float ptr [ESP + 0x10]
//         004604ff     FXCH
//         00460501     FST        float ptr [ESP + 0x1c]
//         00460505     FLD        ST1
//         00460507     FXCH
//         00460509     FMUL       float ptr [ESP + 0x1c]
//         0046050d     FXCH
//         0046050f     FMUL       ST2
//         00460511     FADDP
//         00460513     FSQRT
//         00460515     FSTP       ST1
//         00460517     FCOMP      float ptr [ESP + 0x38]
//         0046051b     FNSTSW     AX
//         0046051d     TEST       AH,0x41
//         00460520     JNZ        LAB_0046055b
//                               LAB_00460522                                                 XREF[1]:     004604c7(j)
//                              move_obj.cpp:2622 (21)
//         00460522     MOV        EAX,dword ptr [ESP + xStep]
//         00460526     MOV        this,dword ptr [ESP + priorY]
//         0046052a     INC        EAX
//         0046052b     CMP        EAX,this
//         0046052d     MOV        dword ptr [ESP + xStep],EAX
//         00460531     JL         LAB_00460491
//                              move_obj.cpp:2654 (5)
//         00460537     MOV        EAX,0x1
//                              move_obj.cpp:2655 (10)
//         0046053c     POP        EDI
//         0046053d     POP        ESI
//         0046053e     POP        EBP
//         0046053f     POP        EBX
//         00460540     ADD        ESP,0x1c
//         00460543     RET        0x14
//                               LAB_00460546                                                 XREF[1]:     004604ea(j)
//                              move_obj.cpp:2642 (6)
//         00460546     MOV        EAX,dword ptr [ESP + 0x3c]
//         0046054a     MOV        dword ptr [EAX],ESI
//                              move_obj.cpp:2643 (3)
//         0046054c     MOV        dword ptr [EAX + 0x4],EDI
//                              move_obj.cpp:2644 (2)
//         0046054f     XOR        EAX,EAX
//                              move_obj.cpp:2655 (25)
//         00460551     POP        EDI
//         00460552     POP        ESI
//         00460553     POP        EBP
//         00460554     POP        EBX
//         00460555     ADD        ESP,0x1c
//         00460558     RET        0x14
//                               LAB_0046055b                                                 XREF[2]:     0046048b(j), 00460520(j)
//         0046055b     POP        EDI
//         0046055c     POP        ESI
//         0046055d     POP        EBP
//         0046055e     MOV        EAX,0x1
//         00460563     POP        EBX
//         00460564     ADD        ESP,0x1c
//         00460567     RET        0x14
//         0046056a     ??         90h
//         0046056b     NOP
//         0046056c     NOP
//         0046056d     NOP
//         0046056e     NOP
//         0046056f     NOP
    return 0;
}

int RGE_Moving_Object::canLinePath(int param_1, int param_2, int param_3, int param_4, float param_5, int param_6) {
    /* TODO: Stub */
//                              int __thiscall canLinePath(RGE_Moving_Object * this, int param_1, in
//              int               EAX:4          <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[6]:     0046057b(R), 00460621(R), 00460635(W), 00460645(R),
//                                                                                     00460657(W), 00460686(R)
//              int               Stack[0x8]:4   param_2                   XREF[7]:     0046058a(R), 00460625(R), 00460639(W), 0046064d(R),
//                                                                                     0046065d(W), 00460666(R), 00460679(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     00460573(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     00460582(R)
//              float             Stack[0x14]:4  param_5
//              int               Stack[0x18]:4  param_6                   XREF[1]:     00460681(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00460631(W), 00460651(R)
//              float             Stack[-0x8]:4  yStep                     XREF[2]:     0046062b(W), 00460649(R)
//              float             Stack[-0xc]:4  xStep                     XREF[7]:     00460586(W), 0046058e(R), 00460595(W), 00460599(R),
//                                                                                     00460613(W), 004606cf(R), 004606da(W)
//              int               Stack[-0x10]:4 i
//              undefined4        Stack[-0x14]:4 local_14                  XREF[4]:     004605ec(W), 00460600(W), 00460604(R), 004606d3(R)
//              int               Stack[-0x18]:4 numSteps
//                               ?canLinePath@RGE_Moving_Object@@UAEHHHHHMH@Z                 XREF[6]:     0056e5cc(*), 0056f404(*),
//                               RGE_Moving_Object::canLinePath                                            0057089c(*), 00570af4(*),
//                                                                                                         00574924(*), 00574bcc(*)
//                              move_obj.cpp:2662 (3)
//         00460570     SUB        ESP,0x14
//                              move_obj.cpp:2664 (15)
//         00460573     MOV        EAX,dword ptr [ESP + param_3]
//         00460577     PUSH       EBX
//         00460578     MOV        EBX,this
//         0046057a     PUSH       EBP
//         0046057b     MOV        this,dword ptr [ESP + param_1]
//         0046057f     PUSH       ESI
//         00460580     SUB        EAX,this
//                              move_obj.cpp:2665 (27)
//         00460582     MOV        this,dword ptr [ESP + param_4]
//         00460586     MOV        dword ptr [ESP + xStep],EAX
//         0046058a     MOV        EAX,dword ptr [ESP + param_2]
//         0046058e     FILD       dword ptr [ESP + xStep]
//         00460592     SUB        this,EAX
//         00460594     PUSH       EDI
//         00460595     MOV        dword ptr [ESP + xStep],this
//         00460599     FILD       dword ptr [ESP + xStep]
//                              move_obj.cpp:2666 (32)
//         0046059d     FLD        ST1
//         0046059f     FCOMP      float ptr [DAT_00570b48]
//         004605a5     FNSTSW     AX
//         004605a7     TEST       AH,0x40
//         004605aa     JZ         LAB_004605c9
//         004605ac     FCOM       float ptr [DAT_00570b48]
//         004605b2     FNSTSW     AX
//         004605b4     TEST       AH,0x40
//         004605b7     JZ         LAB_004605c9
//         004605b9     FSTP       ST0
//         004605bb     FSTP       ST0
//                              move_obj.cpp:2667 (2)
//         004605bd     XOR        EAX,EAX
//                              move_obj.cpp:2713 (10)
//         004605bf     POP        EDI
//         004605c0     POP        ESI
//         004605c1     POP        EBP
//         004605c2     POP        EBX
//         004605c3     ADD        ESP,0x14
//         004605c6     RET        0x18
//                               LAB_004605c9                                                 XREF[2]:     004605aa(j), 004605b7(j)
//                              move_obj.cpp:2671 (21)
//         004605c9     FLD        ST0
//         004605cb     FLD        ST2
//         004605cd     FXCH
//         004605cf     FABS
//         004605d1     FXCH
//         004605d3     FABS
//         004605d5     FCOMPP
//         004605d7     FNSTSW     AX
//         004605d9     TEST       AH,0x1
//         004605dc     JZ         LAB_004605f2
//                              move_obj.cpp:2672 (18)
//         004605de     FLD        ST0
//         004605e0     CALL       __ftol                                           undefined __ftol()
//         004605e5     CDQ
//         004605e6     XOR        EAX,EDX
//         004605e8     SUB        EAX,EDX
//         004605ea     SHL        EAX,0x1
//         004605ec     MOV        dword ptr [ESP + local_14],EAX
//                              move_obj.cpp:2673 (2)
//         004605f0     JMP        LAB_00460604
//                               LAB_004605f2                                                 XREF[1]:     004605dc(j)
//                              move_obj.cpp:2674 (18)
//         004605f2     FLD        ST1
//         004605f4     CALL       __ftol                                           undefined __ftol()
//         004605f9     CDQ
//         004605fa     XOR        EAX,EDX
//         004605fc     SUB        EAX,EDX
//         004605fe     SHL        EAX,0x1
//         00460600     MOV        dword ptr [ESP + local_14],EAX
//                               LAB_00460604                                                 XREF[1]:     004605f0(j)
//                              move_obj.cpp:2676 (4)
//         00460604     FILD       dword ptr [ESP + local_14]
//                              move_obj.cpp:2677 (6)
//         00460608     FXCH       ST2
//         0046060a     FDIV       ST0,ST2
//         0046060c     FXCH
//                              move_obj.cpp:2684 (55)
//         0046060e     MOV        EDI,0xfffffc19
//         00460613     MOV        dword ptr [ESP + xStep],0x0
//         0046061b     TEST       EAX,EAX
//         0046061d     MOV        EBP,EDI
//         0046061f     FDIV       ST0,ST2
//         00460621     FILD       dword ptr [ESP + param_1]
//         00460625     FILD       dword ptr [ESP + param_2]
//         00460629     FXCH       ST3
//         0046062b     FSTP       float ptr [ESP + yStep]
//         0046062f     FXCH
//         00460631     FSTP       float ptr [ESP + local_4]
//         00460635     FSTP       float ptr [ESP + param_1]
//         00460639     FSTP       float ptr [ESP + param_2]
//         0046063d     FSTP       ST0
//         0046063f     JLE        LAB_004606ff
//                               LAB_00460645                                                 XREF[1]:     004606de(j)
//                              move_obj.cpp:2687 (8)
//         00460645     FLD        float ptr [ESP + param_1]
//         00460649     FADD       float ptr [ESP + yStep]
//                              move_obj.cpp:2688 (16)
//         0046064d     FLD        float ptr [ESP + param_2]
//         00460651     FADD       float ptr [ESP + local_4]
//         00460655     FXCH
//         00460657     FST        float ptr [ESP + param_1]
//         0046065b     FXCH
//                              move_obj.cpp:2692 (9)
//         0046065d     FSTP       float ptr [ESP + param_2]
//         00460661     CALL       __ftol                                           undefined __ftol()
//                              move_obj.cpp:2693 (11)
//         00460666     FLD        float ptr [ESP + param_2]
//         0046066a     MOV        ESI,EAX
//         0046066c     CALL       __ftol                                           undefined __ftol()
//                              move_obj.cpp:2694 (8)
//         00460671     CMP        ESI,EDI
//         00460673     JNZ        LAB_00460679
//         00460675     CMP        EAX,EBP
//         00460677     JZ         LAB_004606cf
//                               LAB_00460679                                                 XREF[1]:     00460673(j)
//                              move_obj.cpp:2702 (33)
//         00460679     MOV        this,dword ptr [ESP + param_2]
//         0046067d     MOV        EDX,dword ptr [EBX]
//         0046067f     MOV        EBP,EAX
//         00460681     MOV        EAX,dword ptr [ESP + param_6]
//         00460685     PUSH       EAX
//         00460686     MOV        EAX,dword ptr [ESP + param_1]
//         0046068a     PUSH       this
//         0046068b     PUSH       EAX
//         0046068c     MOV        this,EBX
//         0046068e     MOV        EDI,ESI
//         00460690     CALL       dword ptr [EDX + 0x114]
//         00460696     TEST       EAX,EAX
//         00460698     JZ         LAB_004606f3
//                              move_obj.cpp:2709 (53)
//         0046069a     FILD       dword ptr [ESP + 0x34]
//         0046069e     FILD       dword ptr [ESP + 0x30]
//         004606a2     FSUB       float ptr [ESP + 0x28]
//         004606a6     FXCH
//         004606a8     FSUB       float ptr [ESP + 0x2c]
//         004606ac     FXCH
//         004606ae     FST        float ptr [ESP + 0x14]
//         004606b2     FLD        ST1
//         004606b4     FXCH
//         004606b6     FMUL       float ptr [ESP + 0x14]
//         004606ba     FXCH
//         004606bc     FMUL       ST2
//         004606be     FADDP
//         004606c0     FSQRT
//         004606c2     FSTP       ST1
//         004606c4     FCOMP      float ptr [ESP + 0x38]
//         004606c8     FNSTSW     AX
//         004606ca     TEST       AH,0x41
//         004606cd     JNZ        LAB_004606ff
//                               LAB_004606cf                                                 XREF[1]:     00460677(j)
//                              move_obj.cpp:2684 (21)
//         004606cf     MOV        EAX,dword ptr [ESP + xStep]
//         004606d3     MOV        this,dword ptr [ESP + local_14]
//         004606d7     INC        EAX
//         004606d8     CMP        EAX,this
//         004606da     MOV        dword ptr [ESP + xStep],EAX
//         004606de     JL         LAB_00460645
//                              move_obj.cpp:2712 (5)
//         004606e4     MOV        EAX,0x1
//                              move_obj.cpp:2713 (10)
//         004606e9     POP        EDI
//         004606ea     POP        ESI
//         004606eb     POP        EBP
//         004606ec     POP        EBX
//         004606ed     ADD        ESP,0x14
//         004606f0     RET        0x18
//                               LAB_004606f3                                                 XREF[1]:     00460698(j)
//                              move_obj.cpp:2703 (2)
//         004606f3     XOR        EAX,EAX
//                              move_obj.cpp:2713 (25)
//         004606f5     POP        EDI
//         004606f6     POP        ESI
//         004606f7     POP        EBP
//         004606f8     POP        EBX
//         004606f9     ADD        ESP,0x14
//         004606fc     RET        0x18
//                               LAB_004606ff                                                 XREF[2]:     0046063f(j), 004606cd(j)
//         004606ff     POP        EDI
//         00460700     POP        ESI
//         00460701     POP        EBP
//         00460702     MOV        EAX,0x1
//         00460707     POP        EBX
//         00460708     ADD        ESP,0x14
//         0046070b     RET        0x18
//         0046070e     ??         90h
//         0046070f     NOP
    return 0;
}

int RGE_Moving_Object::firstTileAlongLine(XYPoint* param_1, XYPoint* param_2, XYPoint* param_3, int param_4, int param_5, int param_6) {
    /* TODO: Stub */
//                              int __thiscall firstTileAlongLine(RGE_Moving_Object * this, XYPoint
//              int               EAX:4          <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//              XYPoint *         Stack[0x4]:4   param_1                   XREF[10]:    00460713(R), 00460731(W), 00460735(R), 0046073f(W),
//                                                                                     00460747(R), 004607f4(W), 00460808(R), 00460818(W),
//                                                                                     00460821(R), 00460867(R)
//              XYPoint *         Stack[0x8]:4   param_2                   XREF[7]:     00460717(R), 0046073b(W), 004607e0(R), 004607f0(W),
//                                                                                     00460800(R), 00460812(W), 00460872(R)
//              XYPoint *         Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4                   XREF[1]:     00460845(R)
//              int               Stack[0x14]:4  param_5                   XREF[1]:     0046085a(R)
//              int               Stack[0x18]:4  param_6                   XREF[1]:     00460860(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00460743(W), 0046086b(R)
//              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     00460849(W), 0046084d(R)
//              uchar             Stack[-0xc]:1  tileType                  XREF[2]:     004607d6(W), 00460836(R)
//              RGE_Map *         Stack[-0x10]:4 map                       XREF[2]:     004607ec(W), 0046080c(R)
//              float             Stack[-0x14]:4 yStep                     XREF[4]:     00460728(W), 004607dc(R), 004607e6(W), 00460804(R)
//              float             Stack[-0x18]:4 xStep                     XREF[3]:     004607cb(W), 00460884(R), 0046088f(W)
//              int               Stack[-0x1c]:4 i                         XREF[4]:     0046079a(W), 004607ae(W), 004607b2(R), 00460888(R)
//              int               Stack[-0x20]:4 numSteps
//                               ?firstTileAlongLine@RGE_Moving_Object@@UAEHABUXYPoint@@0AAU  XREF[6]:     0056e5d4(*), 0056f40c(*),
//                               RGE_Moving_Object::firstTileAlongLine                                     005708a4(*), 00570afc(*),
//                                                                                                         0057492c(*), 00574bd4(*)
//                              move_obj.cpp:2719 (3)
//         00460710     SUB        ESP,0x1c
//                              move_obj.cpp:2721 (15)
//         00460713     MOV        EAX,dword ptr [ESP + param_1]
//         00460717     MOV        EDX,dword ptr [ESP + param_2]
//         0046071b     PUSH       EBX
//         0046071c     PUSH       EBP
//         0046071d     PUSH       ESI
//         0046071e     MOV        ESI,this
//         00460720     MOV        this,dword ptr [EAX]
//                              move_obj.cpp:2722 (41)
//         00460722     MOV        EAX,dword ptr [EAX + 0x4]
//         00460725     PUSH       EDI
//         00460726     MOV        EDI,dword ptr [EDX]
//         00460728     MOV        dword ptr [ESP + yStep],this
//         0046072c     SUB        EDI,this
//         0046072e     MOV        this,dword ptr [EDX + 0x4]
//         00460731     MOV        dword ptr [ESP + param_1],EDI
//         00460735     FILD       dword ptr [ESP + param_1]
//         00460739     SUB        this,EAX
//         0046073b     MOV        dword ptr [ESP + param_2],EAX
//         0046073f     MOV        dword ptr [ESP + param_1],this
//         00460743     MOV        dword ptr [ESP + local_4],ESI
//         00460747     FILD       dword ptr [ESP + param_1]
//                              move_obj.cpp:2723 (32)
//         0046074b     FLD        ST1
//         0046074d     FCOMP      float ptr [DAT_00570b48]
//         00460753     FNSTSW     AX
//         00460755     TEST       AH,0x40
//         00460758     JZ         LAB_00460777
//         0046075a     FCOM       float ptr [DAT_00570b48]
//         00460760     FNSTSW     AX
//         00460762     TEST       AH,0x40
//         00460765     JZ         LAB_00460777
//         00460767     FSTP       ST0
//         00460769     FSTP       ST0
//                              move_obj.cpp:2770 (2)
//         0046076b     XOR        EAX,EAX
//                              move_obj.cpp:2771 (10)
//         0046076d     POP        EDI
//         0046076e     POP        ESI
//         0046076f     POP        EBP
//         00460770     POP        EBX
//         00460771     ADD        ESP,0x1c
//         00460774     RET        0x18
//                               LAB_00460777                                                 XREF[2]:     00460758(j), 00460765(j)
//                              move_obj.cpp:2728 (21)
//         00460777     FLD        ST0
//         00460779     FLD        ST2
//         0046077b     FXCH
//         0046077d     FABS
//         0046077f     FXCH
//         00460781     FABS
//         00460783     FCOMPP
//         00460785     FNSTSW     AX
//         00460787     TEST       AH,0x1
//         0046078a     JZ         LAB_004607a0
//                              move_obj.cpp:2729 (18)
//         0046078c     FLD        ST0
//         0046078e     CALL       __ftol                                           undefined __ftol()
//         00460793     CDQ
//         00460794     XOR        EAX,EDX
//         00460796     SUB        EAX,EDX
//         00460798     SHL        EAX,0x1
//         0046079a     MOV        dword ptr [ESP + i],EAX
//                              move_obj.cpp:2730 (2)
//         0046079e     JMP        LAB_004607b2
//                               LAB_004607a0                                                 XREF[1]:     0046078a(j)
//                              move_obj.cpp:2731 (18)
//         004607a0     FLD        ST1
//         004607a2     CALL       __ftol                                           undefined __ftol()
//         004607a7     CDQ
//         004607a8     XOR        EAX,EDX
//         004607aa     SUB        EAX,EDX
//         004607ac     SHL        EAX,0x1
//         004607ae     MOV        dword ptr [ESP + i],EAX
//                               LAB_004607b2                                                 XREF[1]:     0046079e(j)
//                              move_obj.cpp:2733 (4)
//         004607b2     FILD       dword ptr [ESP + i]
//                              move_obj.cpp:2734 (6)
//         004607b6     FXCH       ST2
//         004607b8     FDIV       ST0,ST2
//         004607ba     FXCH
//                              move_obj.cpp:2741 (3)
//         004607bc     MOV        EDX,dword ptr [ESI + 0xc]
//                              move_obj.cpp:2742 (65)
//         004607bf     MOV        EBX,0xfffffc19
//         004607c4     TEST       EAX,EAX
//         004607c6     MOV        EAX,dword ptr [EDX + 0x3c]
//         004607c9     MOV        EBP,EBX
//         004607cb     MOV        dword ptr [ESP + xStep],0x0
//         004607d3     MOV        this,dword ptr [EAX + 0x28]
//         004607d6     MOV        dword ptr [ESP + tileType],this
//         004607da     FDIV       ST0,ST2
//         004607dc     FILD       dword ptr [ESP + yStep]
//         004607e0     FILD       dword ptr [ESP + param_2]
//         004607e4     FXCH       ST3
//         004607e6     FSTP       float ptr [ESP + yStep]
//         004607ea     FXCH
//         004607ec     FSTP       float ptr [ESP + map]
//         004607f0     FSTP       float ptr [ESP + param_2]
//         004607f4     FSTP       float ptr [ESP + param_1]
//         004607f8     FSTP       ST0
//         004607fa     JLE        LAB_004608bd
//                               LAB_00460800                                                 XREF[1]:     00460893(j)
//                              move_obj.cpp:2745 (8)
//         00460800     FLD        float ptr [ESP + param_2]
//         00460804     FADD       float ptr [ESP + yStep]
//                              move_obj.cpp:2746 (16)
//         00460808     FLD        float ptr [ESP + param_1]
//         0046080c     FADD       float ptr [ESP + map]
//         00460810     FXCH
//         00460812     FST        float ptr [ESP + param_2]
//         00460816     FXCH
//                              move_obj.cpp:2750 (9)
//         00460818     FSTP       float ptr [ESP + param_1]
//         0046081c     CALL       __ftol                                           undefined __ftol()
//                              move_obj.cpp:2751 (11)
//         00460821     FLD        float ptr [ESP + param_1]
//         00460825     MOV        ESI,EAX
//         00460827     CALL       __ftol                                           undefined __ftol()
//                              move_obj.cpp:2752 (10)
//         0046082c     CMP        ESI,EBX
//         0046082e     MOV        EDI,EAX
//         00460830     JNZ        LAB_00460836
//         00460832     CMP        EDI,EBP
//         00460834     JZ         LAB_00460884
//                               LAB_00460836                                                 XREF[1]:     00460830(j)
//                              move_obj.cpp:2759 (15)
//         00460836     MOV        this,dword ptr [ESP + tileType]
//         0046083a     PUSH       EDI
//         0046083b     PUSH       ESI
//         0046083c     MOV        EBX,ESI
//         0046083e     MOV        EBP,EDI
//         00460840     CALL       RGE_Map::get_terrain                             uchar get_terrain(RGE_Map * this, short param
//                              move_obj.cpp:2760 (27)
//         00460845     MOV        this,dword ptr [ESP + param_4]
//         00460849     MOV        byte ptr [ESP + local_8],AL
//         0046084d     MOV        EAX,dword ptr [ESP + local_8]
//         00460851     AND        EAX,0xff
//         00460856     CMP        EAX,this
//         00460858     JZ         LAB_00460860
//         0046085a     CMP        EAX,dword ptr [ESP + param_5]
//         0046085e     JNZ        LAB_00460884
//                               LAB_00460860                                                 XREF[1]:     00460858(j)
//                              move_obj.cpp:2764 (36)
//         00460860     CMP        dword ptr [ESP + param_6],0x1
//         00460865     JNZ        LAB_00460884
//         00460867     MOV        EAX,dword ptr [ESP + param_1]
//         0046086b     MOV        this,dword ptr [ESP + local_4]
//         0046086f     PUSH       0x0
//         00460871     PUSH       EAX
//         00460872     MOV        EAX,dword ptr [ESP + param_2]
//         00460876     MOV        EDX,dword ptr [this->_padding_]
//         00460878     PUSH       EAX
//         00460879     CALL       dword ptr [EDX + 0x114]
//         0046087f     CMP        EAX,0x1
//         00460882     JZ         LAB_004608a5
//                               LAB_00460884                                                 XREF[3]:     00460834(j), 0046085e(j),
//                                                                                                         00460865(j)
//                              move_obj.cpp:2742 (21)
//         00460884     MOV        EAX,dword ptr [ESP + xStep]
//         00460888     MOV        this,dword ptr [ESP + i]
//         0046088c     INC        EAX
//         0046088d     CMP        EAX,this
//         0046088f     MOV        dword ptr [ESP + xStep],EAX
//         00460893     JL         LAB_00460800
//                              move_obj.cpp:2770 (2)
//         00460899     XOR        EAX,EAX
//                              move_obj.cpp:2771 (10)
//         0046089b     POP        EDI
//         0046089c     POP        ESI
//         0046089d     POP        EBP
//         0046089e     POP        EBX
//         0046089f     ADD        ESP,0x1c
//         004608a2     RET        0x18
//                               LAB_004608a5                                                 XREF[1]:     00460882(j)
//                              move_obj.cpp:2765 (6)
//         004608a5     MOV        EAX,dword ptr [ESP + 0x38]
//         004608a9     MOV        dword ptr [EAX],ESI
//                              move_obj.cpp:2766 (3)
//         004608ab     MOV        dword ptr [EAX + 0x4],EDI
//                              move_obj.cpp:2767 (5)
//         004608ae     MOV        EAX,0x1
//                              move_obj.cpp:2771 (22)
//         004608b3     POP        EDI
//         004608b4     POP        ESI
//         004608b5     POP        EBP
//         004608b6     POP        EBX
//         004608b7     ADD        ESP,0x1c
//         004608ba     RET        0x18
//                               LAB_004608bd                                                 XREF[1]:     004607fa(j)
//         004608bd     POP        EDI
//         004608be     POP        ESI
//         004608bf     POP        EBP
//         004608c0     XOR        EAX,EAX
//         004608c2     POP        EBX
//         004608c3     ADD        ESP,0x1c
//         004608c6     RET        0x18
//         004608c9     ??         90h
//         004608ca     NOP
//         004608cb     NOP
//         004608cc     NOP
//         004608cd     NOP
//         004608ce     NOP
//         004608cf     NOP
    return 0;
}

float RGE_Moving_Object::maximumSpeed() {
    /* TODO: Stub */
//                              float __thiscall maximumSpeed(RGE_Moving_Object * this)
//              float             ST0:10         <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//                               ?maximumSpeed@RGE_Moving_Object@@UAEMXZ                      XREF[6]:     0056e51c(*), 0056f354(*),
//                               RGE_Moving_Object::maximumSpeed                                           005707ec(*), 00570a44(*),
//                                                                                                         00574874(*), 00574b1c(*)
//                              move_obj.cpp:2777 (23)
//         004608d0     MOV        EDX,dword ptr [ECX + this->_padding_]
//         004608d3     TEST       EDX,EDX
//         004608d5     JZ         LAB_004608f4
//         004608d7     FLD        float ptr [EDX + 0x64]
//         004608da     FCOMP      double ptr [DAT_00570b98]
//         004608e0     FNSTSW     AX
//         004608e2     TEST       AH,0x41
//         004608e5     JNZ        LAB_004608f4
//                              move_obj.cpp:2779 (12)
//         004608e7     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004608ea     FLD        float ptr [EAX + 0xb8]
//         004608f0     FMUL       float ptr [EDX + 0x64]
//                              move_obj.cpp:2780 (0)
//                              move_obj.cpp:2781 (1)
//         004608f3     RET
//                               LAB_004608f4                                                 XREF[2]:     004608d5(j), 004608e5(j)
//                              move_obj.cpp:2780 (9)
//         004608f4     MOV        this,dword ptr [ECX + this->_padding_]
//         004608f7     FLD        float ptr [ECX + this+0xb8]
//                              move_obj.cpp:2781 (1)
//         004608fd     RET
//         004608fe     ??         90h
//         004608ff     NOP
    return 0;
}

uchar RGE_Moving_Object::waitingToMove() {
    /* TODO: Stub */
//                              uchar __thiscall waitingToMove(RGE_Moving_Object * this)
//              uchar             AL:1           <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//                               ?waitingToMove@RGE_Moving_Object@@UBEEXZ                     XREF[6]:     0056e550(*), 0056f388(*),
//                               RGE_Moving_Object::waitingToMove                                          00570820(*), 00570a78(*),
//                                                                                                         005748a8(*), 00574b50(*)
//                              move_obj.cpp:2787 (3)
//         00460900     PUSH       ESI
//         00460901     MOV        ESI,this
//                              move_obj.cpp:2792 (13)
//         00460903     MOV        EAX,dword ptr [ESI]
//         00460905     CALL       dword ptr [EAX + 0x134]
//         0046090b     AND        EAX,0xff
//                              move_obj.cpp:2793 (10)
//         00460910     CMP        EAX,0x6
//         00460913     JZ         LAB_00460922
//         00460915     CMP        EAX,0x7
//         00460918     JZ         LAB_00460922
//                              move_obj.cpp:2795 (6)
//         0046091a     MOV        AL,byte ptr [ESI + 0x155]
//                              move_obj.cpp:2796 (2)
//         00460920     POP        ESI
//         00460921     RET
//                               LAB_00460922                                                 XREF[2]:     00460913(j), 00460918(j)
//                              move_obj.cpp:2794 (2)
//         00460922     XOR        AL,AL
//                              move_obj.cpp:2796 (2)
//         00460924     POP        ESI
//         00460925     RET
//         00460926     ??         90h
//         00460927     NOP
//         00460928     NOP
//         00460929     NOP
//         0046092a     NOP
//         0046092b     NOP
//         0046092c     NOP
//         0046092d     NOP
//         0046092e     NOP
//         0046092f     NOP
    return 0;
}

void RGE_Moving_Object::setWaitingToMove(uchar param_1) {
    /* TODO: Stub */
//                              void __thiscall setWaitingToMove(RGE_Moving_Object * this, uchar par
//              void              <VOID>         <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00460930(R)
//                               ?setWaitingToMove@RGE_Moving_Object@@UAEXE@Z                 XREF[6]:     0056e54c(*), 0056f384(*),
//                               RGE_Moving_Object::setWaitingToMove                                       0057081c(*), 00570a74(*),
//                                                                                                         005748a4(*), 00574b4c(*)
//                              move_obj.cpp:2801 (10)
//         00460930     MOV        AL,byte ptr [ESP + param_1]
//         00460934     MOV        byte ptr [ECX + this->waitingToMoveValue],AL
//                              move_obj.cpp:2803 (3)
//         0046093a     RET        0x4
//         0046093d     ??         90h
//         0046093e     NOP
//         0046093f     NOP
    return;
}

XYZBYTEPoint* RGE_Moving_Object::userDefinedWaypoint(int param_1) {
    /* TODO: Stub */
//                              XYZBYTEPoint * __thiscall userDefinedWaypoint(RGE_Moving_Object * th
//              XYZBYTEPoint *    EAX:4          <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00460940(R)
//                               ?userDefinedWaypoint@RGE_Moving_Object@@UAEPAUXYZBYTEPoint@  XREF[6]:     0056e5d8(*), 0056f410(*),
//                               RGE_Moving_Object::userDefinedWaypoint                                    005708a8(*), 00570b00(*),
//                                                                                                         00574930(*), 00574bd8(*)
//                              move_obj.cpp:2808 (16)
//         00460940     MOV        EAX,dword ptr [ESP + param_1]
//         00460944     TEST       EAX,EAX
//         00460946     JL         LAB_0046095e
//         00460948     CMP        EAX,dword ptr [ECX + this->numberUserDefinedWa
//         0046094e     JGE        LAB_0046095e
//                              move_obj.cpp:2810 (11)
//         00460950     LEA        EDX,[EAX + EAX*0x2]
//         00460953     MOV        EAX,dword ptr [ECX + this->userDefinedWaypoints]
//         00460959     ADD        EAX,EDX
//                              move_obj.cpp:2812 (3)
//         0046095b     RET        0x4
//                               LAB_0046095e                                                 XREF[2]:     00460946(j), 0046094e(j)
//                              move_obj.cpp:2811 (2)
//         0046095e     XOR        EAX,EAX
//                              move_obj.cpp:2812 (3)
//         00460960     RET        0x4
//         00460963     ??         90h
//         00460964     NOP
//         00460965     NOP
//         00460966     NOP
//         00460967     NOP
//         00460968     NOP
//         00460969     NOP
//         0046096a     NOP
//         0046096b     NOP
//         0046096c     NOP
//         0046096d     NOP
//         0046096e     NOP
//         0046096f     NOP
    return 0;
}

int RGE_Moving_Object::addUserDefinedWaypoint(XYZBYTEPoint* param_1, int param_2) {
    /* TODO: Stub */
//                              int __thiscall addUserDefinedWaypoint(RGE_Moving_Object * this, XYZB
//              int               EAX:4          <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//              XYZBYTEPoint *    Stack[0x4]:4   param_1                   XREF[1]:     004609af(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     00460981(R)
//                               ?addUserDefinedWaypoint@RGE_Moving_Object@@UAEHPAUXYZBYTEPo  XREF[6]:     0056e5dc(*), 0056f414(*),
//                               RGE_Moving_Object::addUserDefinedWaypoint                                 005708ac(*), 00570b04(*),
//                                                                                                         00574934(*), 00574bdc(*)
//                              move_obj.cpp:2817 (5)
//         00460970     PUSH       EBX
//         00460971     PUSH       EBP
//         00460972     PUSH       ESI
//         00460973     MOV        ESI,this
//                              move_obj.cpp:2828 (12)
//         00460975     XOR        EBX,EBX
//         00460977     PUSH       EDI
//         00460978     CMP        byte ptr [ESI + 0x174],0x1
//         0046097f     JNZ        LAB_00460996
//                              move_obj.cpp:2832 (15)
//         00460981     MOV        this,dword ptr [ESP + param_2]
//         00460985     MOV        EAX,dword ptr [ESI]
//         00460987     PUSH       this
//         00460988     MOV        this,ESI
//         0046098a     CALL       dword ptr [EAX + 0x1c0]
//                              move_obj.cpp:2833 (6)
//         00460990     MOV        byte ptr [ESI + 0x174],BL
//                               LAB_00460996                                                 XREF[1]:     0046097f(j)
//                              move_obj.cpp:2837 (16)
//         00460996     MOV        this,dword ptr [ESI + 0x170]
//         0046099c     MOV        EAX,dword ptr [ESI + 0x16c]
//         004609a2     CMP        this,EAX
//         004609a4     JLE        LAB_004609e9
//                              move_obj.cpp:2838 (18)
//         004609a6     MOV        this,dword ptr [ESI + 0x168]
//         004609ac     LEA        EDX,[EAX + EAX*0x2]
//         004609af     MOV        EAX,dword ptr [ESP + param_1]
//         004609b3     MOV        BL,byte ptr [EAX]
//         004609b5     MOV        byte ptr [EDX + this->_padding_*0x1],BL
//                              move_obj.cpp:2839 (22)
//         004609b8     MOV        this,dword ptr [ESI + 0x16c]
//         004609be     MOV        BL,byte ptr [EAX + 0x1]
//         004609c1     LEA        EDX,[ECX + ECX*0x2]
//         004609c4     MOV        this,dword ptr [ESI + 0x168]
//         004609ca     MOV        byte ptr [EDX + this->_padding_*0x1 + 0x1],BL
//                              move_obj.cpp:2840 (22)
//         004609ce     MOV        this,dword ptr [ESI + 0x16c]
//         004609d4     MOV        AL,byte ptr [EAX + 0x2]
//         004609d7     LEA        EDX,[ECX + ECX*0x2]
//         004609da     MOV        this,dword ptr [ESI + 0x168]
//         004609e0     MOV        byte ptr [EDX + this->_padding_*0x1 + 0x2],AL
//                              move_obj.cpp:2849 (5)
//         004609e4     JMP        LAB_00460b00
//                               LAB_004609e9                                                 XREF[1]:     004609a4(j)
//                              move_obj.cpp:2853 (4)
//         004609e9     CMP        this,EBX
//         004609eb     JNZ        LAB_00460a12
//                              move_obj.cpp:2854 (16)
//         004609ed     PUSH       0xf
//         004609ef     CALL       operator_new                                     void * operator_new(uint param_1)
//         004609f4     ADD        ESP,0x4
//         004609f7     MOV        dword ptr [ESI + 0x168],EAX
//                              move_obj.cpp:2855 (10)
//         004609fd     MOV        dword ptr [ESI + 0x170],0x5
//                              move_obj.cpp:2856 (6)
//         00460a07     MOV        dword ptr [ESI + 0x16c],EBX
//                              move_obj.cpp:2859 (5)
//         00460a0d     JMP        LAB_00460abc
//                               LAB_00460a12                                                 XREF[1]:     004609eb(j)
//                              move_obj.cpp:2860 (16)
//         00460a12     LEA        this,[ECX + ECX*0x2]
//         00460a15     SHL        this,0x1
//         00460a17     PUSH       this
//         00460a18     CALL       operator_new                                     void * operator_new(uint param_1)
//         00460a1d     MOV        EBP,EAX
//         00460a1f     ADD        ESP,0x4
//                              move_obj.cpp:2861 (4)
//         00460a22     CMP        EBP,EBX
//         00460a24     JNZ        LAB_00460a2f
//                              move_obj.cpp:2862 (2)
//         00460a26     XOR        EAX,EAX
//                              move_obj.cpp:2890 (7)
//         00460a28     POP        EDI
//         00460a29     POP        ESI
//         00460a2a     POP        EBP
//         00460a2b     POP        EBX
//         00460a2c     RET        0x8
//                               LAB_00460a2f                                                 XREF[1]:     00460a24(j)
//                              move_obj.cpp:2863 (12)
//         00460a2f     MOV        this,dword ptr [ESI + 0x16c]
//         00460a35     XOR        EAX,EAX
//         00460a37     CMP        this,EBX
//         00460a39     JLE        LAB_00460a77
//                              move_obj.cpp:2890 (60)
//         00460a3b     XOR        this,this
//         00460a3d     LEA        EDI,[EBP + 0x2]
//                               LAB_00460a40                                                 XREF[1]:     00460a75(j)
//         00460a40     MOV        EDX,dword ptr [ESI + 0x168]
//         00460a46     INC        EAX
//         00460a47     ADD        EDI,0x3
//         00460a4a     MOV        DL,byte ptr [this->_padding_ + EDX*0x1]
//         00460a4d     ADD        this,0x3
//         00460a50     MOV        byte ptr [EDI + -0x5],DL
//         00460a53     MOV        EDX,dword ptr [ESI + 0x168]
//         00460a59     MOV        DL,byte ptr [this->_padding_ + EDX*0x1 + -0x2]
//         00460a5d     MOV        byte ptr [EDI + -0x4],DL
//         00460a60     MOV        EDX,dword ptr [ESI + 0x168]
//         00460a66     MOV        DL,byte ptr [this->_padding_ + EDX*0x1 + -0x1]
//         00460a6a     MOV        byte ptr [EDI + -0x3],DL
//         00460a6d     MOV        EDX,dword ptr [ESI + 0x16c]
//         00460a73     CMP        EAX,EDX
//         00460a75     JL         LAB_00460a40
//                               LAB_00460a77                                                 XREF[1]:     00460a39(j)
//                              move_obj.cpp:2868 (8)
//         00460a77     MOV        this,dword ptr [ESI + 0x170]
//         00460a7d     SHL        this,0x1
//                              move_obj.cpp:2869 (18)
//         00460a7f     CMP        EAX,this
//         00460a81     MOV        dword ptr [ESI + 0x170],this
//         00460a87     JGE        LAB_00460aa7
//         00460a89     LEA        this,[EBP + EAX*0x2]
//         00460a8d     LEA        this,[EAX + this->_padding_*0x1 + 0x2]
//                               LAB_00460a91                                                 XREF[1]:     00460aa5(j)
//                              move_obj.cpp:2870 (3)
//         00460a91     MOV        byte ptr [this->_padding_ + -0x2],BL
//                              move_obj.cpp:2871 (3)
//         00460a94     MOV        byte ptr [this->_padding_ + -0x1],BL
//                              move_obj.cpp:2872 (16)
//         00460a97     MOV        byte ptr [this->_padding_],BL
//         00460a99     MOV        EDX,dword ptr [ESI + 0x170]
//         00460a9f     INC        EAX
//         00460aa0     ADD        this,0x3
//         00460aa3     CMP        EAX,EDX
//         00460aa5     JL         LAB_00460a91
//                               LAB_00460aa7                                                 XREF[1]:     00460a87(j)
//                              move_obj.cpp:2874 (15)
//         00460aa7     MOV        EDX,dword ptr [ESI + 0x168]
//         00460aad     PUSH       EDX
//         00460aae     CALL       operator_delete                                  void operator_delete(void * param_1)
//         00460ab3     ADD        ESP,0x4
//                              move_obj.cpp:2875 (6)
//         00460ab6     MOV        dword ptr [ESI + 0x168],EBP
//                               LAB_00460abc                                                 XREF[1]:     00460a0d(j)
//                              move_obj.cpp:2878 (24)
//         00460abc     MOV        EAX,dword ptr [ESI + 0x16c]
//         00460ac2     MOV        EDX,dword ptr [ESI + 0x168]
//         00460ac8     LEA        this,[EAX + EAX*0x2]
//         00460acb     MOV        EAX,dword ptr [ESP + 0x14]
//         00460acf     MOV        BL,byte ptr [EAX]
//         00460ad1     MOV        byte ptr [this->_padding_ + EDX*0x1],BL
//                              move_obj.cpp:2879 (22)
//         00460ad4     MOV        this,dword ptr [ESI + 0x16c]
//         00460ada     MOV        EDX,dword ptr [ESI + 0x168]
//         00460ae0     MOV        BL,byte ptr [EAX + 0x1]
//         00460ae3     LEA        this,[ECX + ECX*0x2]
//         00460ae6     MOV        byte ptr [ECX + EDX*this+0x1 + 0x1],BL
//                              move_obj.cpp:2880 (22)
//         00460aea     MOV        this,dword ptr [ESI + 0x16c]
//         00460af0     MOV        EDX,dword ptr [ESI + 0x168]
//         00460af6     MOV        AL,byte ptr [EAX + 0x2]
//         00460af9     LEA        this,[ECX + ECX*0x2]
//         00460afc     MOV        byte ptr [ECX + EDX*0x1 + this+0x2],AL
//                               LAB_00460b00                                                 XREF[1]:     004609e4(j)
//                              move_obj.cpp:2881 (6)
//         00460b00     MOV        EAX,dword ptr [ESI + 0x16c]
//                              move_obj.cpp:2890 (19)
//         00460b06     POP        EDI
//         00460b07     INC        EAX
//         00460b08     MOV        dword ptr [ESI + 0x16c],EAX
//         00460b0e     POP        ESI
//         00460b0f     POP        EBP
//         00460b10     MOV        EAX,0x1
//         00460b15     POP        EBX
//         00460b16     RET        0x8
//         00460b19     ??         90h
//         00460b1a     NOP
//         00460b1b     NOP
//         00460b1c     NOP
//         00460b1d     NOP
//         00460b1e     NOP
//         00460b1f     NOP
    return 0;
}

void RGE_Moving_Object::removeAllUserDefinedWaypoints(int param_1) {
    /* TODO: Stub */
//                              void __thiscall removeAllUserDefinedWaypoints(RGE_Moving_Object * th
//              void              <VOID>         <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00460b20(R)
//                               ?removeAllUserDefinedWaypoints@RGE_Moving_Object@@UAEXH@Z    XREF[6]:     0056e5e0(*), 0056f418(*),
//                               RGE_Moving_Object::removeAllUserDefinedWaypoints                          005708b0(*), 00570b08(*),
//                                                                                                         00574938(*), 00574be0(*)
//                              move_obj.cpp:2895 (29)
//         00460b20     MOV        EAX,dword ptr [ESP + param_1]
//         00460b24     PUSH       ESI
//         00460b25     MOV        ESI,this
//         00460b27     CMP        EAX,0x1
//         00460b2a     MOV        dword ptr [ESI + 0x16c],0x0
//         00460b34     JNZ        LAB_00460b6c
//         00460b36     MOV        EAX,dword ptr [ESI + 0x74]
//         00460b39     TEST       EAX,EAX
//         00460b3b     JZ         LAB_00460b6c
//                              move_obj.cpp:2905 (37)
//         00460b3d     MOV        EAX,[actionFile]                                 = 00000000
//         00460b42     TEST       EAX,EAX
//         00460b44     JZ         LAB_00460b62
//         00460b46     MOV        this,dword ptr [ESI + 0x4]
//         00460b49     PUSH       0xb59
//         00460b4e     PUSH       s_C:\msdev\work\age1_x1\move_obj.c               = "C:\\msdev\\work\\age1_x1\\move_obj.cpp"
//         00460b53     PUSH       this
//         00460b54     PUSH       s_#%d_call_stopObject_%s_%d_                     = "#%d call stopObject %s %d\n"
//         00460b59     PUSH       EAX
//         00460b5a     CALL       fprintf                                          undefined fprintf()
//         00460b5f     ADD        ESP,0x14
//                               LAB_00460b62                                                 XREF[1]:     00460b44(j)
//                              move_obj.cpp:2907 (10)
//         00460b62     MOV        this,dword ptr [ESI + 0x74]
//         00460b65     PUSH       0x0
//         00460b67     MOV        EDX,dword ptr [this->_padding_]
//         00460b69     CALL       dword ptr [EDX + 0x58]
//                               LAB_00460b6c                                                 XREF[2]:     00460b34(j), 00460b3b(j)
//                              move_obj.cpp:2909 (4)
//         00460b6c     POP        ESI
//         00460b6d     RET        0x4
    return;
}

void RGE_Moving_Object::removeUserDefinedWaypoint(int param_1) {
    /* TODO: Stub */
//                              void __thiscall removeUserDefinedWaypoint(RGE_Moving_Object * this,
//              void              <VOID>         <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00460b70(R)
//                               ?removeUserDefinedWaypoint@RGE_Moving_Object@@UAEXH@Z        XREF[6]:     0056e5e4(*), 0056f41c(*),
//                               RGE_Moving_Object::removeUserDefinedWaypoint                              005708b4(*), 00570b0c(*),
//                                                                                                         0057493c(*), 00574be4(*)
//                              move_obj.cpp:2914 (19)
//         00460b70     MOV        EDX,dword ptr [ESP + param_1]
//         00460b74     TEST       EDX,EDX
//         00460b76     JL         LAB_00460bea
//         00460b78     MOV        EAX,dword ptr [ECX + this->numberUserDefinedWa
//         00460b7e     CMP        EDX,EAX
//         00460b80     JGE        LAB_00460bea
//         00460b82     PUSH       EDI
//                              move_obj.cpp:2923 (16)
//         00460b83     XOR        EDI,EDI
//         00460b85     TEST       EAX,EAX
//         00460b87     PUSH       ESI
//         00460b88     JLE        LAB_00460b93
//                               LAB_00460b8a                                                 XREF[1]:     00460b91(j)
//         00460b8a     CMP        EDI,EDX
//         00460b8c     JGE        LAB_00460b93
//         00460b8e     INC        EDI
//         00460b8f     CMP        EDI,EAX
//         00460b91     JL         LAB_00460b8a
//                               LAB_00460b93                                                 XREF[2]:     00460b88(j), 00460b8c(j)
//                              move_obj.cpp:2926 (7)
//         00460b93     CMP        EDI,EAX
//         00460b95     JGE        LAB_00460bdb
//         00460b97     LEA        EAX,[EDI + EDI*0x2]
//                               LAB_00460b9a                                                 XREF[1]:     00460bd9(j)
//                              move_obj.cpp:2927 (4)
//         00460b9a     TEST       EAX,EAX
//         00460b9c     JZ         LAB_00460bcd
//                              move_obj.cpp:2929 (15)
//         00460b9e     MOV        EDX,dword ptr [ECX + this->userDefinedWaypoints]
//         00460ba4     LEA        ESI,[EDX + EAX*0x1]
//         00460ba7     MOV        DL,byte ptr [EDX + EAX*0x1]
//         00460baa     MOV        byte ptr [ESI + -0x3],DL
//                              move_obj.cpp:2930 (16)
//         00460bad     MOV        EDX,dword ptr [ECX + this->userDefinedWaypoints]
//         00460bb3     LEA        ESI,[EDX + EAX*0x1]
//         00460bb6     MOV        DL,byte ptr [EDX + EAX*0x1 + 0x1]
//         00460bba     MOV        byte ptr [ESI + -0x2],DL
//                              move_obj.cpp:2931 (30)
//         00460bbd     MOV        EDX,dword ptr [ECX + this->userDefinedWaypoints]
//         00460bc3     LEA        ESI,[EDX + EAX*0x1]
//         00460bc6     MOV        DL,byte ptr [EDX + EAX*0x1 + 0x2]
//         00460bca     MOV        byte ptr [ESI + -0x1],DL
//                               LAB_00460bcd                                                 XREF[1]:     00460b9c(j)
//         00460bcd     MOV        EDX,dword ptr [ECX + this->numberUserDefinedWa
//         00460bd3     INC        EDI
//         00460bd4     ADD        EAX,0x3
//         00460bd7     CMP        EDI,EDX
//         00460bd9     JL         LAB_00460b9a
//                               LAB_00460bdb                                                 XREF[1]:     00460b95(j)
//                              move_obj.cpp:2934 (15)
//         00460bdb     MOV        EAX,dword ptr [ECX + this->numberUserDefinedWa
//         00460be1     POP        ESI
//         00460be2     DEC        EAX
//         00460be3     POP        EDI
//         00460be4     MOV        dword ptr [ECX + this->numberUserDefinedWaypoi
//                               LAB_00460bea                                                 XREF[2]:     00460b76(j), 00460b80(j)
//                              move_obj.cpp:2935 (3)
//         00460bea     RET        0x4
//         00460bed     ??         90h
//         00460bee     NOP
//         00460bef     NOP
    return;
}

void RGE_Moving_Object::setFinalUserDefinedWaypoint() {
    /* TODO: Stub */
//                              void __thiscall setFinalUserDefinedWaypoint(RGE_Moving_Object * this)
//              void              <VOID>         <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//                               ?setFinalUserDefinedWaypoint@RGE_Moving_Object@@QAEXXZ       XREF[1]:     update:004059dc(c)
//                               RGE_Moving_Object::setFinalUserDefinedWaypoint
//                              move_obj.cpp:2940 (7)
//         00460bf0     MOV        byte ptr [ECX + this->finalUserDefinedWaypoint
//                              move_obj.cpp:2942 (1)
//         00460bf7     RET
//         00460bf8     ??         90h
//         00460bf9     NOP
//         00460bfa     NOP
//         00460bfb     NOP
//         00460bfc     NOP
//         00460bfd     NOP
//         00460bfe     NOP
//         00460bff     NOP
    return;
}

Path* RGE_Moving_Object::findAvoidancePath(XYZPoint* param_1, float param_2, int param_3) {
    /* TODO: Stub */
//                              Path * __thiscall findAvoidancePath(RGE_Moving_Object * this, XYZPoi
//              Path *            EAX:4          <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//              XYZPoint *        Stack[0x4]:4   param_1                   XREF[1]:     00460c6b(R)
//              float             Stack[0x8]:4   param_2                   XREF[2]:     00460c9f(R), 00460cc3(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     00460cbf(R)
//                               ?findAvoidancePath@RGE_Moving_Object@@UAEPAVPath@@AAUXYZPoi  XREF[6]:     0056e5ec(*), 0056f424(*),
//                               RGE_Moving_Object::findAvoidancePath                                      005708bc(*), 00570b14(*),
//                                                                                                         00574944(*), 00574bec(*)
//                              move_obj.cpp:2949 (6)
//         00460c00     PUSH       EBX
//         00460c01     PUSH       EBP
//         00460c02     PUSH       ESI
//         00460c03     MOV        ESI,this
//         00460c05     PUSH       EDI
//                              move_obj.cpp:2961 (11)
//         00460c06     MOV        EAX,dword ptr [ESI + 0x7c]
//         00460c09     LEA        EDI,[ESI + 0x7c]
//         00460c0c     CMP        EAX,-0x1
//         00460c0f     JNZ        LAB_00460c39
//                              move_obj.cpp:2964 (40)
//         00460c11     MOV        EAX,dword ptr [ESI + 0xc]
//         00460c14     MOV        EDX,dword ptr [ESI + 0x8]
//         00460c17     PUSH       EDI
//         00460c18     MOV        EAX,dword ptr [EAX + 0x3c]
//         00460c1b     MOVSX      this,word ptr [EAX + 0x52]
//         00460c1f     PUSH       this
//         00460c20     MOVSX      this,word ptr [EDX + 0x66]
//         00460c24     MOV        EDX,dword ptr [EAX + 0x54]
//         00460c27     MOV        this,dword ptr [EDX + this->_padding_*0x4]
//         00460c2a     MOV        EDX,dword ptr [EAX + 0x28]
//         00460c2d     PUSH       this
//         00460c2e     MOV        this,dword ptr [EDX + 0x8dc4]
//         00460c34     CALL       RGE_Zone_Map_List::get_zone_map                  RGE_Zone_Map * get_zone_map(RGE_Zone_Map_List
//                               LAB_00460c39                                                 XREF[1]:     00460c0f(j)
//                              move_obj.cpp:2966 (23)
//         00460c39     MOV        this,dword ptr [ESI + 0xc]
//         00460c3c     MOV        EAX,dword ptr [EDI]
//         00460c3e     PUSH       EAX
//         00460c3f     MOV        EDX,dword ptr [ECX + this->_padding_]
//         00460c42     MOV        EAX,dword ptr [EDX + 0x28]
//         00460c45     MOV        this,dword ptr [EAX + 0x8dc4]
//         00460c4b     CALL       RGE_Zone_Map_List::get_zone_map                  RGE_Zone_Map * get_zone_map(RGE_Zone_Map_List
//                              move_obj.cpp:2967 (27)
//         00460c50     FLD        float ptr [ESI + 0x3c]
//         00460c53     MOV        EBX,EAX
//         00460c55     CALL       __ftol                                           undefined __ftol()
//         00460c5a     FLD        float ptr [ESI + 0x38]
//         00460c5d     PUSH       EAX
//         00460c5e     CALL       __ftol                                           undefined __ftol()
//         00460c63     PUSH       EAX
//         00460c64     MOV        this,EBX
//         00460c66     CALL       RGE_Zone_Map::get_zone_info                      uchar get_zone_info(RGE_Zone_Map * this, long
//                              move_obj.cpp:2974 (30)
//         00460c6b     MOV        EDI,dword ptr [ESP + param_1]
//         00460c6f     AND        EAX,0xff
//         00460c74     MOV        EBP,EAX
//         00460c76     MOV        this,dword ptr [EDI + 0x4]
//         00460c79     MOV        EDX,dword ptr [EDI]
//         00460c7b     PUSH       this
//         00460c7c     PUSH       EDX
//         00460c7d     MOV        this,EBX
//         00460c7f     CALL       RGE_Zone_Map::get_zone_info                      uchar get_zone_info(RGE_Zone_Map * this, long
//         00460c84     AND        EAX,0xff
//                              move_obj.cpp:2975 (4)
//         00460c89     CMP        EAX,EBP
//         00460c8b     JZ         LAB_00460cbf
//                              move_obj.cpp:2977 (8)
//         00460c8d     FLD        float ptr [ESI + 0x38]
//         00460c90     CALL       __ftol                                           undefined __ftol()
//                              move_obj.cpp:2978 (10)
//         00460c95     FLD        float ptr [ESI + 0x3c]
//         00460c98     MOV        EBP,EAX
//         00460c9a     CALL       __ftol                                           undefined __ftol()
//                              move_obj.cpp:2982 (25)
//         00460c9f     MOV        EDX,dword ptr [ESP + param_2]
//         00460ca3     MOV        this,dword ptr [EDI]
//         00460ca5     PUSH       EDX
//         00460ca6     MOV        EDX,dword ptr [EDI + 0x4]
//         00460ca9     PUSH       EDX
//         00460caa     PUSH       this
//         00460cab     PUSH       EAX
//         00460cac     PUSH       EBP
//         00460cad     MOV        this,EBX
//         00460caf     CALL       RGE_Zone_Map::withinRange                        int withinRange(RGE_Zone_Map * this, XYPoint
//         00460cb4     TEST       EAX,EAX
//         00460cb6     JNZ        LAB_00460cbf
//                              move_obj.cpp:3035 (7)
//         00460cb8     POP        EDI
//         00460cb9     POP        ESI
//         00460cba     POP        EBP
//         00460cbb     POP        EBX
//         00460cbc     RET        0xc
//                               LAB_00460cbf                                                 XREF[2]:     00460c8b(j), 00460cb6(j)
//                              move_obj.cpp:3000 (69)
//         00460cbf     MOV        EAX,dword ptr [ESP + param_3]
//         00460cc3     MOV        this,dword ptr [ESP + param_2]
//         00460cc7     PUSH       -0x1
//         00460cc9     PUSH       -0x1
//         00460ccb     PUSH       0x1
//         00460ccd     PUSH       0x1
//         00460ccf     FLD        float ptr [ESI + 0x3c]
//         00460cd2     PUSH       0x1
//         00460cd4     PUSH       0x0
//         00460cd6     PUSH       0x0
//         00460cd8     PUSH       0x1
//         00460cda     MOV        byte ptr [ESI + 0x154],0x1
//         00460ce1     MOV        EDX,dword ptr [EDI + 0x4]
//         00460ce4     PUSH       EAX
//         00460ce5     MOV        EAX,dword ptr [EDI]
//         00460ce7     PUSH       this
//         00460ce8     PUSH       ESI
//         00460ce9     PUSH       EDX
//         00460cea     PUSH       EAX
//         00460ceb     CALL       __ftol                                           undefined __ftol()
//         00460cf0     FLD        float ptr [ESI + 0x38]
//         00460cf3     PUSH       EAX
//         00460cf4     CALL       __ftol                                           undefined __ftol()
//         00460cf9     PUSH       EAX
//         00460cfa     MOV        this,aiPathSystem
//         00460cff     CALL       PathingSystem::findTilePath                      int findTilePath(PathingSystem * this, int pa
//                              move_obj.cpp:3022 (19)
//         00460d04     PUSH       0x0
//         00460d06     MOV        this,aiPathSystem
//         00460d0b     MOV        byte ptr [ESI + 0x154],0x0
//         00460d12     CALL       PathingSystem::initMisc                          void initMisc(PathingSystem * this, uchar par
//                              move_obj.cpp:3034 (6)
//         00460d17     LEA        EAX,[ESI + 0xd8]
//                              move_obj.cpp:3035 (7)
//         00460d1d     POP        EDI
//         00460d1e     POP        ESI
//         00460d1f     POP        EBP
//         00460d20     POP        EBX
//         00460d21     RET        0xc
//         00460d24     ??         90h
//         00460d25     NOP
//         00460d26     NOP
//         00460d27     NOP
//         00460d28     NOP
//         00460d29     NOP
//         00460d2a     NOP
//         00460d2b     NOP
//         00460d2c     NOP
//         00460d2d     NOP
//         00460d2e     NOP
//         00460d2f     NOP
    return 0;
}

void RGE_Moving_Object::setInitialPoints(XYPoint* param_1, XYPoint* param_2) {
    /* TODO: Stub */
//                              void __thiscall setInitialPoints(RGE_Moving_Object * this, XYPoint *
//              void              <VOID>         <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//              XYPoint *         Stack[0x4]:4   param_1                   XREF[1]:     00460d30(R)
//              XYPoint *         Stack[0x8]:4   param_2                   XREF[1]:     00460d45(R)
//                               ?setInitialPoints@RGE_Moving_Object@@QAEXAAUXYPoint@@0@Z     XREF[1]:     findTilePath:0046bc41(c)
//                               RGE_Moving_Object::setInitialPoints
//                              move_obj.cpp:3040 (12)
//         00460d30     MOV        EAX,dword ptr [ESP + param_1]
//         00460d34     MOV        EDX,dword ptr [EAX]
//         00460d36     MOV        dword ptr [ECX + this->minInitialPointValue.x]
//                              move_obj.cpp:3042 (9)
//         00460d3c     MOV        EAX,dword ptr [EAX + 0x4]
//         00460d3f     MOV        dword ptr [ECX + this+0x15c],EAX
//                              move_obj.cpp:3043 (12)
//         00460d45     MOV        EAX,dword ptr [ESP + param_2]
//         00460d49     MOV        EDX,dword ptr [EAX]
//         00460d4b     MOV        dword ptr [ECX + this->maxInitialPointValue.x]
//                              move_obj.cpp:3044 (9)
//         00460d51     MOV        EAX,dword ptr [EAX + 0x4]
//         00460d54     MOV        dword ptr [ECX + this+0x164],EAX
//                              move_obj.cpp:3045 (3)
//         00460d5a     RET        0x8
//         00460d5d     ??         90h
//         00460d5e     NOP
//         00460d5f     NOP
    return;
}

void RGE_Moving_Object::copy_obj(RGE_Master_Static_Object* param_1) {
    /* TODO: Stub */
//                              void __thiscall copy_obj(RGE_Moving_Object * this, RGE_Master_Static
//              void              <VOID>         <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//              RGE_Master_Sta    Stack[0x4]:4   param_1                   XREF[1]:     00460d74(R)
//                               ?copy_obj@RGE_Moving_Object@@UAEXPAVRGE_Master_Static_Objec  XREF[2]:     copy_obj:00406bd7(c), 005709a0(*)
//                               RGE_Moving_Object::copy_obj
//                              move_obj.cpp:3049 (4)
//         00460d60     PUSH       ESI
//         00460d61     MOV        ESI,this
//         00460d63     PUSH       EDI
//                              move_obj.cpp:3051 (2)
//         00460d64     XOR        EDX,EDX
//                              move_obj.cpp:3053 (26)
//         00460d66     MOV        EAX,dword ptr [ESI + 0x8]
//         00460d69     MOV        this,dword ptr [ESI + 0x10]
//         00460d6c     MOV        EDI,dword ptr [EAX + 0xbc]
//         00460d72     CMP        this,EDI
//         00460d74     MOV        EDI,dword ptr [ESP + param_1]
//         00460d78     JNZ        LAB_00460d82
//         00460d7a     MOV        EDX,dword ptr [EDI + 0xbc]
//                              move_obj.cpp:3054 (16)
//         00460d80     JMP        LAB_00460d90
//                               LAB_00460d82                                                 XREF[1]:     00460d78(j)
//         00460d82     CMP        this,dword ptr [EAX + 0xc0]
//         00460d88     JNZ        LAB_00460d90
//         00460d8a     MOV        EDX,dword ptr [EDI + 0xc0]
//                               LAB_00460d90                                                 XREF[2]:     00460d80(j), 00460d88(j)
//                              move_obj.cpp:3056 (4)
//         00460d90     TEST       EDX,EDX
//         00460d92     JZ         LAB_00460d9c
//                              move_obj.cpp:3057 (8)
//         00460d94     MOV        EAX,dword ptr [ESI]
//         00460d96     PUSH       EDX
//         00460d97     MOV        this,ESI
//         00460d99     CALL       dword ptr [EAX + 0x38]
//                               LAB_00460d9c                                                 XREF[1]:     00460d92(j)
//                              move_obj.cpp:3059 (8)
//         00460d9c     PUSH       EDI
//         00460d9d     MOV        this,ESI
//         00460d9f     CALL       RGE_Static_Object::copy_obj                      void copy_obj(RGE_Static_Object * this, RGE_M
//                              move_obj.cpp:3060 (5)
//         00460da4     POP        EDI
//         00460da5     POP        ESI
//         00460da6     RET        0x4
//         00460da9     ??         90h
//         00460daa     NOP
//         00460dab     NOP
//         00460dac     NOP
//         00460dad     NOP
//         00460dae     NOP
//         00460daf     NOP
    return;
}

void RGE_Moving_Object::boundAngle(float* param_1, int param_2) {
    /* TODO: Stub */
//                              void __thiscall boundAngle(RGE_Moving_Object * this, float * param_1
//              void              <VOID>         <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//              float *           Stack[0x4]:4   param_1                   XREF[7]:     00460db2(R), 00460e12(W), 00460e1c(W), 00460e3a(R),
//                                                                                     00460e4f(R), 00460e5a(W), 00460e66(R)
//              int               Stack[0x8]:4   param_2                   XREF[4]:     00460e02(R), 00460e26(W), 00460e5e(W), 00460e80(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     00460e30(W), 00460e36(R), 00460e7a(W)
//              int               Stack[-0x8]:4  i
//                               ?boundAngle@RGE_Moving_Object@@QAEXPAMH@Z                    XREF[5]:     doTrivialMove:0045eb01(c),
//                               RGE_Moving_Object::boundAngle                                             doTrivialMove:0045eb7c(c),
//                                                                                                         doTrivialMove:0045ec23(c),
//                                                                                                         doTrivialMove:0045f346(c),
//                                                                                                         doTrivialMove:0045f41a(c)
//                              move_obj.cpp:3065 (2)
//         00460db0     PUSH       this
//         00460db1     PUSH       ESI
//                              move_obj.cpp:3070 (21)
//         00460db2     MOV        ESI,dword ptr [ESP + param_1]
//         00460db6     FLD        float ptr [ESI]
//         00460db8     FCOMP      float ptr [DAT_00570b48]
//         00460dbe     FLD        float ptr [ESI]
//         00460dc0     FNSTSW     AX
//         00460dc2     TEST       AH,0x1
//         00460dc5     JZ         LAB_00460dde
//                               LAB_00460dc7                                                 XREF[1]:     00460dd8(j)
//                              move_obj.cpp:3072 (21)
//         00460dc7     FSUB       float ptr [DAT_00570b4c]                         = DBh
//         00460dcd     FCOM       float ptr [DAT_00570b48]
//         00460dd3     FNSTSW     AX
//         00460dd5     TEST       AH,0x1
//         00460dd8     JNZ        LAB_00460dc7
//         00460dda     FSTP       float ptr [ESI]
//                              move_obj.cpp:3073 (15)
//         00460ddc     JMP        LAB_00460e02
//                               LAB_00460dde                                                 XREF[1]:     00460dc5(j)
//         00460dde     FCOMP      float ptr [DAT_00570b50]                         = DBh
//         00460de4     FNSTSW     AX
//         00460de6     TEST       AH,0x41
//         00460de9     JNZ        LAB_00460e02
//                               LAB_00460deb                                                 XREF[1]:     00460e00(j)
//                              move_obj.cpp:3075 (23)
//         00460deb     FLD        float ptr [ESI]
//         00460ded     FSUB       float ptr [DAT_00570b50]                         = DBh
//         00460df3     FCOM       float ptr [DAT_00570b50]                         = DBh
//         00460df9     FSTP       float ptr [ESI]
//         00460dfb     FNSTSW     AX
//         00460dfd     TEST       AH,0x41
//         00460e00     JZ         LAB_00460deb
//                               LAB_00460e02                                                 XREF[2]:     00460ddc(j), 00460de9(j)
//                              move_obj.cpp:3085 (13)
//         00460e02     MOV        EDX,dword ptr [ESP + param_2]
//         00460e06     CMP        EDX,-0x1
//         00460e09     JZ         LAB_00460e9e
//                              move_obj.cpp:3088 (3)
//         00460e0f     CMP        EDX,0x8
//                              move_obj.cpp:3089 (10)
//         00460e12     MOV        dword ptr [ESP + param_1],0x3f490fdb
//         00460e1a     JZ         LAB_00460e24
//                              move_obj.cpp:3091 (8)
//         00460e1c     MOV        dword ptr [ESP + param_1],0x3ec90fdb
//                               LAB_00460e24                                                 XREF[1]:     00460e1a(j)
//                              move_obj.cpp:3097 (18)
//         00460e24     XOR        this,this
//         00460e26     MOV        dword ptr [ESP + param_2],0xffffffff
//         00460e2e     TEST       EDX,EDX
//         00460e30     MOV        dword ptr [ESP + local_4],this
//         00460e34     JL         LAB_00460e80
//                               LAB_00460e36                                                 XREF[1]:     00460e7e(j)
//                              move_obj.cpp:3099 (10)
//         00460e36     FILD       dword ptr [ESP + local_4]
//         00460e3a     FMUL       float ptr [ESP + param_1]
//         00460e3e     FSUBR      float ptr [ESI]
//                              move_obj.cpp:3100 (13)
//         00460e40     FCOM       double ptr [DAT_00570b98]
//         00460e46     FNSTSW     AX
//         00460e48     TEST       AH,0x1
//         00460e4b     JZ         LAB_00460e4f
//                              move_obj.cpp:3101 (2)
//         00460e4d     FCHS
//                               LAB_00460e4f                                                 XREF[1]:     00460e4b(j)
//                              move_obj.cpp:3107 (11)
//         00460e4f     FCOM       float ptr [ESP + param_1]
//         00460e53     FNSTSW     AX
//         00460e55     TEST       AH,0x1
//         00460e58     JZ         LAB_00460e64
//                              move_obj.cpp:3112 (4)
//         00460e5a     FSTP       float ptr [ESP + param_1]
//                              move_obj.cpp:3113 (6)
//         00460e5e     MOV        dword ptr [ESP + param_2],this
//         00460e62     JMP        LAB_00460e66
//                               LAB_00460e64                                                 XREF[1]:     00460e58(j)
//                              move_obj.cpp:3107 (2)
//         00460e64     FSTP       ST0
//                               LAB_00460e66                                                 XREF[1]:     00460e62(j)
//                              move_obj.cpp:3117 (26)
//         00460e66     FLD        float ptr [ESP + param_1]
//         00460e6a     FCOMP      double ptr [DAT_00570c00]                        = 9Ah
//         00460e70     FNSTSW     AX
//         00460e72     TEST       AH,0x1
//         00460e75     JNZ        LAB_00460e80
//         00460e77     INC        this
//         00460e78     CMP        this,EDX
//         00460e7a     MOV        dword ptr [ESP + local_4],this
//         00460e7e     JLE        LAB_00460e36
//                               LAB_00460e80                                                 XREF[2]:     00460e34(j), 00460e75(j)
//                              move_obj.cpp:3136 (15)
//         00460e80     FILD       dword ptr [ESP + param_2]
//         00460e84     CMP        EDX,0x8
//         00460e87     JNZ        LAB_00460e96
//         00460e89     FMUL       float ptr [DAT_00570b88]                         = DBh
//                              move_obj.cpp:3142 (2)
//         00460e8f     FSTP       float ptr [ESI]
//                              move_obj.cpp:3151 (5)
//         00460e91     POP        ESI
//         00460e92     POP        this
//         00460e93     RET        0x8
//                               LAB_00460e96                                                 XREF[1]:     00460e87(j)
//                              move_obj.cpp:3142 (8)
//         00460e96     FMUL       float ptr [DAT_00570bfc]                         = DBh
//         00460e9c     FSTP       float ptr [ESI]
//                               LAB_00460e9e                                                 XREF[1]:     00460e09(j)
//                              move_obj.cpp:3151 (5)
//         00460e9e     POP        ESI
//         00460e9f     POP        this
//         00460ea0     RET        0x8
//         00460ea3     ??         90h
//         00460ea4     NOP
//         00460ea5     NOP
//         00460ea6     NOP
//         00460ea7     NOP
//         00460ea8     NOP
//         00460ea9     NOP
//         00460eaa     NOP
//         00460eab     NOP
//         00460eac     NOP
//         00460ead     NOP
//         00460eae     NOP
//         00460eaf     NOP
    return;
}

void RGE_Moving_Object::rotate(long param_1) {
    /* TODO: Stub */
//                              void __thiscall rotate(RGE_Moving_Object * this, long param_1)
//              void              <VOID>         <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[8]:     00460eb3(R), 00460ec1(W), 00460ec5(R), 00460ed7(W),
//                                                                                     00460ef5(W), 00460f19(W), 00460f1d(R), 00460f2d(R)
//                               ?rotate@RGE_Moving_Object@@UAEXJ@Z                           XREF[9]:     connect:004c912f(c),
//                               RGE_Moving_Object::rotate                                                 connect2:004c91d0(c),
//                                                                                                         connect2:004c91f3(c),
//                                                                                                         connect2:004c920d(c), 0056e498(*),
//                                                                                                         0056f2d0(*), 00570768(*),
//                                                                                                         005709c0(*), 00574a98(*)
//                              move_obj.cpp:3157 (33)
//         00460eb0     MOV        EAX,dword ptr [ECX + this->_padding_]
//         00460eb3     FILD       dword ptr [ESP + param_1]
//         00460eb7     MOVSX      EDX,word ptr [EAX + 0x60]
//         00460ebb     FMUL       double ptr [DAT_00570b40]                        = F1h
//         00460ec1     MOV        dword ptr [ESP + param_1],EDX
//         00460ec5     FILD       dword ptr [ESP + param_1]
//         00460ec9     FDIVP
//         00460ecb     FADD       float ptr [ECX + this->angle]
//                              move_obj.cpp:3161 (17)
//         00460ed1     FCOM       float ptr [DAT_00570b48]
//         00460ed7     FST        float ptr [ESP + param_1]
//         00460edb     FNSTSW     AX
//         00460edd     TEST       AH,0x1
//         00460ee0     JZ         LAB_00460ef9
//                               LAB_00460ee2                                                 XREF[1]:     00460ef3(j)
//                              move_obj.cpp:3162 (23)
//         00460ee2     FSUB       float ptr [DAT_00570b4c]                         = DBh
//         00460ee8     FCOM       float ptr [DAT_00570b48]
//         00460eee     FNSTSW     AX
//         00460ef0     TEST       AH,0x1
//         00460ef3     JNZ        LAB_00460ee2
//         00460ef5     FST        float ptr [ESP + param_1]
//                               LAB_00460ef9                                                 XREF[1]:     00460ee0(j)
//                              move_obj.cpp:3163 (13)
//         00460ef9     FCOM       double ptr [DAT_00570b40]                        = F1h
//         00460eff     FNSTSW     AX
//         00460f01     TEST       AH,0x1
//         00460f04     JNZ        LAB_00460f2d
//                               LAB_00460f06                                                 XREF[1]:     00460f17(j)
//                              move_obj.cpp:3164 (23)
//         00460f06     FSUB       float ptr [DAT_00570b50]                         = DBh
//         00460f0c     FCOM       double ptr [DAT_00570b40]                        = F1h
//         00460f12     FNSTSW     AX
//         00460f14     TEST       AH,0x1
//         00460f17     JZ         LAB_00460f06
//         00460f19     FSTP       float ptr [ESP + param_1]
//                              move_obj.cpp:3166 (13)
//         00460f1d     MOV        EDX,dword ptr [ESP + param_1]
//         00460f21     MOV        EAX,dword ptr [this->_padding_]
//         00460f23     PUSH       EDX
//         00460f24     CALL       dword ptr [EAX + 0xb4]
//                              move_obj.cpp:3167 (3)
//         00460f2a     RET        0x4
//                               LAB_00460f2d                                                 XREF[1]:     00460f04(j)
//                              move_obj.cpp:3166 (15)
//         00460f2d     MOV        EDX,dword ptr [ESP + param_1]
//         00460f31     MOV        EAX,dword ptr [this->_padding_]
//         00460f33     PUSH       EDX
//         00460f34     FSTP       ST0
//         00460f36     CALL       dword ptr [EAX + 0xb4]
//                              move_obj.cpp:3167 (3)
//         00460f3c     RET        0x4
//         00460f3f     ??         90h
    return;
}

long RGE_Moving_Object::get_waypoint_checksum() {
    /* TODO: Stub */
//                              long __thiscall get_waypoint_checksum(RGE_Moving_Object * this)
//              long              EAX:4          <RETURN>
//              RGE_Moving_Obj    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     00460f4c(W), 00460f88(R), 00460f8c(W), 00460fa9(R)
//              float             Stack[-0x8]:4  temp
//                               ?get_waypoint_checksum@RGE_Moving_Object@@UAEJXZ             XREF[6]:     0056e5f4(*), 0056f42c(*),
//                               RGE_Moving_Object::get_waypoint_checksum                                  005708c4(*), 00570b1c(*),
//                                                                                                         0057494c(*), 00574bf4(*)
//                              move_obj.cpp:3173 (3)
//         00460f40     PUSH       this
//         00460f41     PUSH       EBX
//         00460f42     PUSH       ESI
//                              move_obj.cpp:3176 (22)
//         00460f43     LEA        ESI,[ECX + this->pathValue.timeStampValue]
//         00460f49     PUSH       EDI
//         00460f4a     MOV        this,ESI
//         00460f4c     MOV        dword ptr [ESP + local_4],0x0
//         00460f54     CALL       Path::currentWaypointNumber                      int currentWaypointNumber(Path * this)
//                              move_obj.cpp:3177 (9)
//         00460f59     MOV        this,ESI
//         00460f5b     MOV        EBX,EAX
//         00460f5d     CALL       Path::initToStart                                void initToStart(Path * this)
//                              move_obj.cpp:3178 (13)
//         00460f62     MOV        this,ESI
//         00460f64     XOR        EDI,EDI
//         00460f66     CALL       Path::numberOfWaypoints                          int numberOfWaypoints(Path * this)
//         00460f6b     TEST       EAX,EAX
//         00460f6d     JLE        LAB_00460fa1
//                              move_obj.cpp:3173 (1)
//         00460f6f     PUSH       EBP
//                               LAB_00460f70                                                 XREF[1]:     00460f9e(j)
//                              move_obj.cpp:3179 (48)
//         00460f70     MOV        this,ESI
//         00460f72     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         00460f77     MOV        this,ESI
//         00460f79     MOV        EBP,EAX
//         00460f7b     CALL       Path::currentWaypoint                            Waypoint * currentWaypoint(Path * this)
//         00460f80     FLD        float ptr [EBP + 0x4]
//         00460f83     FADD       float ptr [EAX]
//         00460f85     MOV        this,ESI
//         00460f87     INC        EDI
//         00460f88     FADD       float ptr [ESP + local_4]
//         00460f8c     FSTP       float ptr [ESP + local_4]
//         00460f90     CALL       Path::moveToNextWaypoint                         int moveToNextWaypoint(Path * this)
//         00460f95     MOV        this,ESI
//         00460f97     CALL       Path::numberOfWaypoints                          int numberOfWaypoints(Path * this)
//         00460f9c     CMP        EDI,EAX
//         00460f9e     JL         LAB_00460f70
//                              move_obj.cpp:3173 (1)
//         00460fa0     POP        EBP
//                               LAB_00460fa1                                                 XREF[1]:     00460f6d(j)
//                              move_obj.cpp:3181 (8)
//         00460fa1     PUSH       EBX
//         00460fa2     MOV        this,ESI
//         00460fa4     CALL       Path::setCurrentWaypointNumber                   void setCurrentWaypointNumber(Path * this, in
//                              move_obj.cpp:3182 (9)
//         00460fa9     FLD        float ptr [ESP + local_4]
//         00460fad     CALL       __ftol                                           undefined __ftol()
//                              move_obj.cpp:3183 (5)
//         00460fb2     POP        EDI
//         00460fb3     POP        ESI
//         00460fb4     POP        EBX
//         00460fb5     POP        this
//         00460fb6     RET
//         00460fb7     ??         90h
//         00460fb8     NOP
//         00460fb9     NOP
//         00460fba     NOP
//         00460fbb     NOP
//         00460fbc     NOP
//         00460fbd     NOP
//         00460fbe     NOP
//         00460fbf     NOP
    return 0;
}

