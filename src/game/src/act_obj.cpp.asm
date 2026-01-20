// Auto-generated scaffold unit: act_obj.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/act_obj.cpp
#include "../include/common.h"

// Offset: 0x00405C60
undefined RGE_Action_Object(RGE_Action_Object* this_, RGE_Master_Action_Object* param_2, RGE_Player* param_3, float param_4, float param_5, float param_6, int param_7) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Action_Object::RGE_Action_Object(class RGE_Master_Action_Object *,class RGE... *
    //                              *********************************************************************************************************
    //                              undefined __thiscall RGE_Action_Object(RGE_Action_Object * this, RGE
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Action_Obj    ECX:4 (auto)   this
    //              RGE_Master_Act    Stack[0x4]:4   param_1                   XREF[2]:     00405c8e(R), 00405ccb(R)  
    //              RGE_Player *      Stack[0x8]:4   param_2                   XREF[2]:     00405c76(R), 00405cc7(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[1]:     00405c80(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[1]:     00405c7b(R)  
    //              float             Stack[0x14]:4  param_5                   XREF[1]:     00405c86(R)  
    //              int               Stack[0x18]:4  param_6                   XREF[1]:     00405cb9(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00405ca5(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00405cdb(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00405c99(W)  
    //                               ??0RGE_Action_Object@@QAE@PAVRGE_Master_Action_Object@@PAVR  XREF[2]:     RGE_Combat_Object:0042f96d(c), 
    //                               RGE_Action_Object::RGE_Action_Object                                      make_new_obj:0044f63a(c)  
    //                              act_obj.cpp:47 (66)
    //         00405c60     PUSH       -0x1
    //         00405c62     PUSH       FUN_0055c368
    //         00405c67     MOV        EAX,FS:[0x0]
    //         00405c6d     PUSH       EAX
    //         00405c6e     MOV        dword ptr FS:[0x0],ESP
    //         00405c75     PUSH       this
    //         00405c76     MOV        EAX,dword ptr [ESP + param_2]
    //         00405c7a     PUSH       EBX
    //         00405c7b     MOV        EBX,dword ptr [ESP + param_4]
    //         00405c7f     PUSH       EBP
    //         00405c80     MOV        EBP,dword ptr [ESP + param_3]
    //         00405c84     PUSH       ESI
    //         00405c85     PUSH       EDI
    //         00405c86     MOV        EDI,dword ptr [ESP + param_5]
    //         00405c8a     PUSH       0x0
    //         00405c8c     MOV        ESI,this
    //         00405c8e     MOV        this,dword ptr [ESP + param_1]
    //         00405c92     PUSH       EDI
    //         00405c93     PUSH       EBX
    //         00405c94     PUSH       EBP
    //         00405c95     PUSH       EAX
    //         00405c96     PUSH       this
    //         00405c97     MOV        this,ESI
    //         00405c99     MOV        dword ptr [ESP + local_10],ESI
    //         00405c9d     CALL       RGE_Moving_Object::RGE_Moving_Object             undefined RGE_Moving_Object(RGE_Moving_Object
    //                              act_obj.cpp:50 (17)
    //         00405ca2     OR         EAX,0xffffffff
    //         00405ca5     MOV        dword ptr [ESP + local_4],0x0
    //         00405cad     MOV        dword ptr [ESI + 0x18c],EAX
    //                              act_obj.cpp:51 (6)
    //         00405cb3     MOV        dword ptr [ESI + 0x190],EAX
    //                              act_obj.cpp:54 (14)
    //         00405cb9     MOV        EAX,dword ptr [ESP + param_6]
    //         00405cbd     MOV        dword ptr [ESI],RGE_Action_Object::`vftable'     = 00405f70
    //         00405cc3     TEST       EAX,EAX
    //         00405cc5     JZ         LAB_00405cdb
    //                              act_obj.cpp:55 (20)
    //         00405cc7     MOV        EDX,dword ptr [ESP + param_2]
    //         00405ccb     MOV        EAX,dword ptr [ESP + param_1]
    //         00405ccf     PUSH       EDI
    //         00405cd0     PUSH       EBX
    //         00405cd1     PUSH       EBP
    //         00405cd2     PUSH       EDX
    //         00405cd3     PUSH       EAX
    //         00405cd4     MOV        this,ESI
    //         00405cd6     CALL       RGE_Action_Object::setup                         int setup(RGE_Action_Object * this, RGE_Maste
    //                               LAB_00405cdb                                                 XREF[1]:     00405cc5(j)  
    //                              act_obj.cpp:56 (23)
    //         00405cdb     MOV        this,dword ptr [ESP + local_c]
    //         00405cdf     MOV        EAX,ESI
    //         00405ce1     POP        EDI
    //         00405ce2     POP        ESI
    //         00405ce3     POP        EBP
    //         00405ce4     MOV        dword ptr FS:[0x0],this
    //         00405ceb     POP        EBX
    //         00405cec     ADD        ESP,0x10
    //         00405cef     RET        0x18
}

// Offset: 0x00405F90
undefined RGE_Action_Object(RGE_Action_Object* this_, int param_2, RGE_Game_World* param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Action_Object::RGE_Action_Object(int,class RGE_Game_World *,int)               *
    //                              *********************************************************************************************************
    //                              undefined __thiscall RGE_Action_Object(RGE_Action_Object * this, int
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Action_Obj    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00405fa7(R)  
    //              RGE_Game_World    Stack[0x8]:4   param_2                   XREF[1]:     00405fad(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     00405fd7(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00405fc3(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00405fee(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00405fb7(W)  
    //                               ??0RGE_Action_Object@@QAE@HPAVRGE_Game_World@@H@Z            XREF[2]:     RGE_Combat_Object:0042fa0b(c), 
    //                               RGE_Action_Object::RGE_Action_Object                                      load:00463aed(c)  
    //                              act_obj.cpp:62 (48)
    //         00405f90     PUSH       -0x1
    //         00405f92     PUSH       FUN_0055c388
    //         00405f97     MOV        EAX,FS:[0x0]
    //         00405f9d     PUSH       EAX
    //         00405f9e     MOV        dword ptr FS:[0x0],ESP
    //         00405fa5     PUSH       this
    //         00405fa6     PUSH       EBX
    //         00405fa7     MOV        EBX,dword ptr [ESP + param_1]
    //         00405fab     PUSH       ESI
    //         00405fac     PUSH       EDI
    //         00405fad     MOV        EDI,dword ptr [ESP + param_2]
    //         00405fb1     PUSH       0x0
    //         00405fb3     MOV        ESI,this
    //         00405fb5     PUSH       EDI
    //         00405fb6     PUSH       EBX
    //         00405fb7     MOV        dword ptr [ESP + local_10],ESI
    //         00405fbb     CALL       RGE_Moving_Object::RGE_Moving_Object             undefined RGE_Moving_Object(RGE_Moving_Object
    //                              act_obj.cpp:65 (17)
    //         00405fc0     OR         EAX,0xffffffff
    //         00405fc3     MOV        dword ptr [ESP + local_4],0x0
    //         00405fcb     MOV        dword ptr [ESI + 0x18c],EAX
    //                              act_obj.cpp:66 (6)
    //         00405fd1     MOV        dword ptr [ESI + 0x190],EAX
    //                              act_obj.cpp:69 (14)
    //         00405fd7     MOV        EAX,dword ptr [ESP + param_3]
    //         00405fdb     MOV        dword ptr [ESI],RGE_Action_Object::`vftable'     = 00405f70
    //         00405fe1     TEST       EAX,EAX
    //         00405fe3     JZ         LAB_00405fee
    //                              act_obj.cpp:70 (9)
    //         00405fe5     PUSH       EDI
    //         00405fe6     PUSH       EBX
    //         00405fe7     MOV        this,ESI
    //         00405fe9     CALL       RGE_Action_Object::setup                         int setup(RGE_Action_Object * this, int param
    //                               LAB_00405fee                                                 XREF[1]:     00405fe3(j)  
    //                              act_obj.cpp:71 (22)
    //         00405fee     MOV        this,dword ptr [ESP + local_c]
    //         00405ff2     MOV        EAX,ESI
    //         00405ff4     POP        EDI
    //         00405ff5     POP        ESI
    //         00405ff6     MOV        dword ptr FS:[0x0],this
    //         00405ffd     POP        EBX
    //         00405ffe     ADD        ESP,0x10
    //         00406001     RET        0xc
}

// Offset: 0x00406010
void RGE_Action_Object(RGE_Action_Object* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall RGE_Action_Object::~RGE_Action_Object(void)                                *
    //                              *********************************************************************************************************
    //                              void __thiscall ~RGE_Action_Object(RGE_Action_Object * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Obj    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0040603a(W), 00406062(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0040606f(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0040602a(W)  
    //                               ??1RGE_Action_Object@@UAE@XZ                                 XREF[2]:     `vector_deleting_destructor':00405
    //                               RGE_Action_Object::~RGE_Action_Object                                     ~RGE_Combat_Object:0042facb(c)  
    //                              act_obj.cpp:76 (36)
    //         00406010     PUSH       -0x1
    //         00406012     PUSH       FUN_0055c3a8
    //         00406017     MOV        EAX,FS:[0x0]
    //         0040601d     PUSH       EAX
    //         0040601e     MOV        dword ptr FS:[0x0],ESP
    //         00406025     PUSH       this
    //         00406026     PUSH       ESI
    //         00406027     MOV        ESI,this
    //         00406029     PUSH       EDI
    //         0040602a     MOV        dword ptr [ESP + local_10],ESI
    //         0040602e     MOV        dword ptr [ESI],RGE_Action_Object::`vftable'     = 00405f70
    //                              act_obj.cpp:77 (18)
    //         00406034     MOV        EDI,dword ptr [ESI + 0x184]
    //         0040603a     MOV        dword ptr [ESP + local_4],0x0
    //         00406042     TEST       EDI,EDI
    //         00406044     JZ         LAB_00406060
    //                              act_obj.cpp:79 (16)
    //         00406046     MOV        this,EDI
    //         00406048     CALL       RGE_Action_List::~RGE_Action_List                void ~RGE_Action_List(RGE_Action_List * this)
    //         0040604d     PUSH       EDI
    //         0040604e     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00406053     ADD        ESP,0x4
    //                              act_obj.cpp:80 (12)
    //         00406056     MOV        dword ptr [ESI + 0x184],0x0
    //                               LAB_00406060                                                 XREF[1]:     00406044(j)  
    //         00406060     MOV        this,ESI
    //                              act_obj.cpp:82 (30)
    //         00406062     MOV        dword ptr [ESP + local_4],0xffffffff
    //         0040606a     CALL       RGE_Moving_Object::~RGE_Moving_Object            void ~RGE_Moving_Object(RGE_Moving_Object * t
    //         0040606f     MOV        this,dword ptr [ESP + local_c]
    //         00406073     POP        EDI
    //         00406074     MOV        dword ptr FS:[0x0],this
    //         0040607b     POP        ESI
    //         0040607c     ADD        ESP,0x10
    //         0040607f     RET
}

// Offset: 0x00406080
void RGE_Combat_Object::recycle_out_of_game() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Action_Object::recycle_out_of_game(void)                          *
    //                              *********************************************************************************************************
    //                              void __thiscall recycle_out_of_game(RGE_Action_Object * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Obj    ECX:4 (auto)   this
    //                               ?recycle_out_of_game@RGE_Action_Object@@UAEXXZ               XREF[5]:     recycle_out_of_game:004c83ca(c), 
    //                               RGE_Action_Object::recycle_out_of_game                                    0056e428(*), 0056f260(*), 
    //                                                                                                         005706f8(*), 00574a28(*)  
    //                              act_obj.cpp:86 (3)
    //         00406080     PUSH       ESI
    //         00406081     MOV        ESI,this
    //                              act_obj.cpp:87 (10)
    //         00406083     MOV        this,dword ptr [ESI + 0x184]
    //         00406089     TEST       this,this
    //         0040608b     JZ         LAB_00406092
    //                              act_obj.cpp:88 (5)
    //         0040608d     CALL       RGE_Action_List::delete_list                     void delete_list(RGE_Action_List * this)
    //                               LAB_00406092                                                 XREF[1]:     0040608b(j)  
    //                              act_obj.cpp:90 (7)
    //         00406092     MOV        this,ESI
    //         00406094     CALL       RGE_Static_Object::recycle_out_of_game           void recycle_out_of_game(RGE_Static_Object * 
    //                              act_obj.cpp:91 (2)
    //         00406099     POP        ESI
    //         0040609a     RET
}

// Offset: 0x004060A0
void RGE_Action_Object::recycle_in_to_game(RGE_Master_Static_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Action_Object::recycle_in_to_game(class RGE_Master_Static_Obje... *
    //                              *********************************************************************************************************
    //                              void __thiscall recycle_in_to_game(RGE_Action_Object * this, RGE_Mas
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Obj    ECX:4 (auto)   this
    //              RGE_Master_Sta    Stack[0x4]:4   param_1                   XREF[1]:     004060b5(R)  
    //              RGE_Player *      Stack[0x8]:4   param_2                   XREF[1]:     004060b0(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[1]:     004060a4(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[1]:     004060ab(R)  
    //              float             Stack[0x14]:4  param_5                   XREF[1]:     004060a0(R)  
    //                               ?recycle_in_to_game@RGE_Action_Object@@UAEXPAVRGE_Master_St  XREF[2]:     recycle_in_to_game:0042fb24(c), 
    //                               RGE_Action_Object::recycle_in_to_game                                     0056e424(*)  
    //                              act_obj.cpp:96 (35)
    //         004060a0     MOV        EAX,dword ptr [ESP + param_5]
    //         004060a4     MOV        EDX,dword ptr [ESP + param_3]
    //         004060a8     PUSH       ESI
    //         004060a9     MOV        ESI,this
    //         004060ab     MOV        this,dword ptr [ESP + param_4]
    //         004060af     PUSH       EAX
    //         004060b0     MOV        EAX,dword ptr [ESP + param_2]
    //         004060b4     PUSH       this
    //         004060b5     MOV        this,dword ptr [ESP + param_1]
    //         004060b9     PUSH       EDX
    //         004060ba     PUSH       EAX
    //         004060bb     PUSH       this
    //         004060bc     MOV        this,ESI
    //         004060be     CALL       RGE_Moving_Object::recycle_in_to_game            void recycle_in_to_game(RGE_Moving_Object * t
    //                              act_obj.cpp:99 (7)
    //         004060c3     MOV        byte ptr [ESI + 0x180],0x0
    //                              act_obj.cpp:100 (4)
    //         004060ca     POP        ESI
    //         004060cb     RET        0x14
}

// Offset: 0x004060D0
int setup(RGE_Action_Object* this_, RGE_Master_Action_Object* param_2, RGE_Player* param_3, float param_4, float param_5, float param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: virtual int __thiscall RGE_Action_Object::setup(class RGE_Master_Action_Object *,class ... *
    //                              *********************************************************************************************************
    //                              int __thiscall setup(RGE_Action_Object * this, RGE_Master_Action_Obj
    //              int               EAX:4          <RETURN>
    //              RGE_Action_Obj    ECX:4 (auto)   this
    //              RGE_Master_Act    Stack[0x4]:4   param_1                   XREF[1]:     004060e5(R)  
    //              RGE_Player *      Stack[0x8]:4   param_2                   XREF[1]:     004060e0(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[1]:     004060d4(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[1]:     004060db(R)  
    //              float             Stack[0x14]:4  param_5                   XREF[1]:     004060d0(R)  
    //                               ?setup@RGE_Action_Object@@MAEHPAVRGE_Master_Action_Object@@  XREF[7]:     RGE_Action_Object:00405cd6(c), 
    //                               RGE_Action_Object::setup                                                  setup:0042fb74(c), 0056e634(*), 
    //                                                                                                         0056f46c(*), 00570904(*), 
    //                                                                                                         0057498c(*), 00574c34(*)  
    //                              act_obj.cpp:105 (35)
    //         004060d0     MOV        EAX,dword ptr [ESP + param_5]
    //         004060d4     MOV        EDX,dword ptr [ESP + param_3]
    //         004060d8     PUSH       ESI
    //         004060d9     MOV        ESI,this
    //         004060db     MOV        this,dword ptr [ESP + param_4]
    //         004060df     PUSH       EAX
    //         004060e0     MOV        EAX,dword ptr [ESP + param_2]
    //         004060e4     PUSH       this
    //         004060e5     MOV        this,dword ptr [ESP + param_1]
    //         004060e9     PUSH       EDX
    //         004060ea     PUSH       EAX
    //         004060eb     PUSH       this
    //         004060ec     MOV        this,ESI
    //         004060ee     CALL       RGE_Moving_Object::setup                         int setup(RGE_Moving_Object * this, RGE_Maste
    //                              act_obj.cpp:110 (27)
    //         004060f3     MOV        EDX,dword ptr [ESI]
    //         004060f5     MOV        this,ESI
    //         004060f7     MOV        byte ptr [ESI + 0x4e],0x28
    //         004060fb     MOV        byte ptr [ESI + 0x180],0x0
    //         00406102     CALL       dword ptr [EDX + 0x218]
    //         00406108     MOV        dword ptr [ESI + 0x184],EAX
    //                              act_obj.cpp:115 (7)
    //         0040610e     MOV        byte ptr [ESI + 0x188],0x0
    //                              act_obj.cpp:123 (5)
    //         00406115     MOV        EAX,0x1
    //                              act_obj.cpp:124 (4)
    //         0040611a     POP        ESI
    //         0040611b     RET        0x14
}

// Offset: 0x00406120
int RGE_Action_Object::setup(int param_1, RGE_Game_World* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: virtual int __thiscall RGE_Action_Object::setup(int,class RGE_Game_World *)                *
    //                              *********************************************************************************************************
    //                              int __thiscall setup(RGE_Action_Object * this, int param_1, RGE_Game
    //              int               EAX:4          <RETURN>
    //              RGE_Action_Obj    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00406126(R)  
    //              RGE_Game_World    Stack[0x8]:4   param_2                   XREF[1]:     00406120(R)  
    //                               ?setup@RGE_Action_Object@@MAEHHPAVRGE_Game_World@@@Z         XREF[3]:     RGE_Action_Object:00405fe9(c), 
    //                               RGE_Action_Object::setup                                                  setup:0042fbc5(c), 0056e5f8(*)  
    //                              act_obj.cpp:129 (19)
    //         00406120     MOV        EAX,dword ptr [ESP + param_2]
    //         00406124     PUSH       ESI
    //         00406125     PUSH       EDI
    //         00406126     MOV        EDI,dword ptr [ESP + param_1]
    //         0040612a     PUSH       EAX
    //         0040612b     MOV        ESI,this
    //         0040612d     PUSH       EDI
    //         0040612e     CALL       RGE_Moving_Object::setup                         int setup(RGE_Moving_Object * this, int param
    //                              act_obj.cpp:134 (19)
    //         00406133     LEA        this,[ESI + 0x180]
    //         00406139     PUSH       0x1
    //         0040613b     PUSH       this
    //         0040613c     PUSH       EDI
    //         0040613d     MOV        byte ptr [ESI + 0x4e],0x28
    //         00406141     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              act_obj.cpp:136 (22)
    //         00406146     FLD        float ptr [save_game_version]                    = 7.23
    //         0040614c     FCOMP      float ptr [DAT_0056e648]
    //         00406152     ADD        ESP,0xc
    //         00406155     FNSTSW     AX
    //         00406157     TEST       AH,0x1
    //         0040615a     JNZ        LAB_00406170
    //                              act_obj.cpp:137 (18)
    //         0040615c     LEA        EDX,[ESI + 0x188]
    //         00406162     PUSH       0x1
    //         00406164     PUSH       EDX
    //         00406165     PUSH       EDI
    //         00406166     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0040616b     ADD        ESP,0xc
    //                              act_obj.cpp:138 (2)
    //         0040616e     JMP        LAB_00406177
    //                               LAB_00406170                                                 XREF[1]:     0040615a(j)  
    //                              act_obj.cpp:139 (7)
    //         00406170     MOV        byte ptr [ESI + 0x188],0x0
    //                               LAB_00406177                                                 XREF[1]:     0040616e(j)  
    //                              act_obj.cpp:141 (10)
    //         00406177     MOV        EAX,dword ptr [ESI]
    //         00406179     MOV        this,ESI
    //         0040617b     CALL       dword ptr [EAX + 0x218]
    //                              act_obj.cpp:142 (14)
    //         00406181     PUSH       EDI
    //         00406182     MOV        this,EAX
    //         00406184     MOV        dword ptr [ESI + 0x184],EAX
    //         0040618a     CALL       RGE_Action_List::load                            void load(RGE_Action_List * this, int param_1)
    //                              act_obj.cpp:145 (10)
    //         0040618f     POP        EDI
    //         00406190     MOV        EAX,0x1
    //         00406195     POP        ESI
    //         00406196     RET        0x8
}

// Offset: 0x004061A0
RGE_Action_List* create_action_list(RGE_Action_Object* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: virtual class RGE_Action_List * __thiscall RGE_Action_Object::create_action_list(void)     *
    //                              *********************************************************************************************************
    //                              RGE_Action_List * __thiscall create_action_list(RGE_Action_Object * 
    //              RGE_Action_Lis    EAX:4          <RETURN>
    //              RGE_Action_Obj    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004061c9(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     004061db(R), 004061eb(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004061c3(W)  
    //                               ?create_action_list@RGE_Action_Object@@MAEPAVRGE_Action_Lis  XREF[3]:     0056e638(*), 0056f470(*), 
    //                               RGE_Action_Object::create_action_list                                     00570908(*)  
    //                              act_obj.cpp:149 (25)
    //         004061a0     PUSH       -0x1
    //         004061a2     PUSH       FUN_0055c3cb
    //         004061a7     MOV        EAX,FS:[0x0]
    //         004061ad     PUSH       EAX
    //         004061ae     MOV        dword ptr FS:[0x0],ESP
    //         004061b5     PUSH       this
    //         004061b6     PUSH       ESI
    //         004061b7     MOV        ESI,this
    //                              act_obj.cpp:150 (34)
    //         004061b9     PUSH       0xc
    //         004061bb     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004061c0     ADD        ESP,0x4
    //         004061c3     MOV        dword ptr [ESP + local_10],EAX
    //         004061c7     TEST       EAX,EAX
    //         004061c9     MOV        dword ptr [ESP + local_4],0x0
    //         004061d1     JZ         LAB_004061eb
    //         004061d3     PUSH       ESI
    //         004061d4     MOV        this,EAX
    //         004061d6     CALL       RGE_Action_List::RGE_Action_List                 undefined RGE_Action_List(RGE_Action_List * t
    //                              act_obj.cpp:151 (34)
    //         004061db     MOV        this,dword ptr [ESP + local_c]
    //         004061df     MOV        dword ptr FS:[0x0],this
    //         004061e6     POP        ESI
    //         004061e7     ADD        ESP,0x10
    //         004061ea     RET
    //                               LAB_004061eb                                                 XREF[1]:     004061d1(j)  
    //         004061eb     MOV        this,dword ptr [ESP + local_c]
    //         004061ef     XOR        EAX,EAX
    //         004061f1     MOV        dword ptr FS:[0x0],this
    //         004061f8     POP        ESI
    //         004061f9     ADD        ESP,0x10
    //         004061fc     RET
}

// Offset: 0x00406200
void RGE_Combat_Object::rehook() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Action_Object::rehook(void)                                       *
    //                              *********************************************************************************************************
    //                              void __thiscall rehook(RGE_Action_Object * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Obj    ECX:4 (auto)   this
    //                               ?rehook@RGE_Action_Object@@UAEXXZ                            XREF[5]:     rehook:0045a8ff(T), 
    //                               RGE_Action_Object::rehook                                                 rehook:0045a900(j), 
    //                                                                                                         rehook:004c8a63(c), 0056e44c(*), 
    //                                                                                                         0056f284(*), 00574a4c(*)  
    //                              act_obj.cpp:160 (3)
    //         00406200     PUSH       ESI
    //         00406201     MOV        ESI,this
    //                              act_obj.cpp:161 (5)
    //         00406203     CALL       RGE_Static_Object::rehook                        void rehook(RGE_Static_Object * this)
    //                              act_obj.cpp:162 (11)
    //         00406208     MOV        this,dword ptr [ESI + 0x184]
    //         0040620e     CALL       RGE_Action_List::rehook                          void rehook(RGE_Action_List * this)
    //                              act_obj.cpp:163 (2)
    //         00406213     POP        ESI
    //         00406214     RET
}

// Offset: 0x00406220
void RGE_Action_Object::save(int param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Action_Object::save(int)                                          *
    //                              *********************************************************************************************************
    //                              void __thiscall save(RGE_Action_Object * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Obj    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00406222(R)  
    //                               ?save@RGE_Action_Object@@UAEXH@Z                             XREF[2]:     save:0042fc19(c), 0056e450(*)  
    //                               RGE_Action_Object::save
    //                              act_obj.cpp:167 (2)
    //         00406220     PUSH       ESI
    //         00406221     PUSH       EDI
    //                              act_obj.cpp:168 (12)
    //         00406222     MOV        EDI,dword ptr [ESP + param_1]
    //         00406226     MOV        ESI,this
    //         00406228     PUSH       EDI
    //         00406229     CALL       RGE_Moving_Object::save                          void save(RGE_Moving_Object * this, int param
    //                              act_obj.cpp:170 (18)
    //         0040622e     LEA        EAX,[ESI + 0x180]
    //         00406234     PUSH       0x1
    //         00406236     PUSH       EAX
    //         00406237     PUSH       EDI
    //         00406238     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0040623d     ADD        ESP,0xc
    //                              act_obj.cpp:171 (15)
    //         00406240     LEA        this,[ESI + 0x188]
    //         00406246     PUSH       0x1
    //         00406248     PUSH       this
    //         00406249     PUSH       EDI
    //         0040624a     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              act_obj.cpp:173 (15)
    //         0040624f     MOV        this,dword ptr [ESI + 0x184]
    //         00406255     ADD        ESP,0xc
    //         00406258     PUSH       EDI
    //         00406259     CALL       RGE_Action_List::save                            void save(RGE_Action_List * this, int param_1)
    //                              act_obj.cpp:174 (5)
    //         0040625e     POP        EDI
    //         0040625f     POP        ESI
    //         00406260     RET        0x4
}

// Offset: 0x00406270
void RGE_Combat_Object::transform(RGE_Master_Static_Object* param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Action_Object::transform(class RGE_Master_Static_Object *)        *
    //                              *********************************************************************************************************
    //                              void __thiscall transform(RGE_Action_Object * this, RGE_Master_Stati
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Obj    ECX:4 (auto)   this
    //              RGE_Master_Sta    Stack[0x4]:4   param_1                   XREF[1]:     00406270(R)  
    //                               ?transform@RGE_Action_Object@@UAEXPAVRGE_Master_Static_Obje  XREF[4]:     transform:004ca70c(c), 
    //                               RGE_Action_Object::transform                                              0056e474(*), 0056f2ac(*), 
    //                                                                                                         00570744(*)  
    //                              act_obj.cpp:178 (13)
    //         00406270     MOV        EAX,dword ptr [ESP + param_1]
    //         00406274     PUSH       ESI
    //         00406275     MOV        ESI,this
    //         00406277     PUSH       EAX
    //         00406278     CALL       RGE_Moving_Object::transform                     void transform(RGE_Moving_Object * this, RGE_
    //                              act_obj.cpp:180 (11)
    //         0040627d     MOV        this,dword ptr [ESI + 0x184]
    //         00406283     CALL       RGE_Action_List::delete_list                     void delete_list(RGE_Action_List * this)
    //                              act_obj.cpp:181 (4)
    //         00406288     POP        ESI
    //         00406289     RET        0x4
}

// Offset: 0x00406290
void RGE_Combat_Object::destroy_obj() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Action_Object::destroy_obj(void)                                  *
    //                              *********************************************************************************************************
    //                              void __thiscall destroy_obj(RGE_Action_Object * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Obj    ECX:4 (auto)   this
    //                               ?destroy_obj@RGE_Action_Object@@UAEXXZ                       XREF[5]:     destroy_obj:004c869d(c), 
    //                               RGE_Action_Object::destroy_obj                                            0056e488(*), 0056f2c0(*), 
    //                                                                                                         00570758(*), 00574a88(*)  
    //                              act_obj.cpp:185 (3)
    //         00406290     PUSH       ESI
    //         00406291     MOV        ESI,this
    //                              act_obj.cpp:191 (11)
    //         00406293     MOV        this,dword ptr [ESI + 0x184]
    //         00406299     CALL       RGE_Action_List::delete_list                     void delete_list(RGE_Action_List * this)
    //                              act_obj.cpp:192 (7)
    //         0040629e     MOV        this,ESI
    //         004062a0     CALL       RGE_Static_Object::destroy_obj                   void destroy_obj(RGE_Static_Object * this)
    //                              act_obj.cpp:198 (2)
    //         004062a5     POP        ESI
    //         004062a6     RET
}

// Offset: 0x004062B0
void TRIBE_Building_Object::notify_of_relation(long param_1, uchar param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Action_Object::notify_of_relation(long,unsigned char)             *
    //                              *********************************************************************************************************
    //                              void __thiscall notify_of_relation(RGE_Action_Object * this, long pa
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Obj    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1
    //              uchar             Stack[0x8]:1   param_2
    //                               ?notify_of_relation@RGE_Action_Object@@UAEXJE@Z              XREF[5]:     0056e4b4(*), 0056f2ec(*), 
    //                               RGE_Action_Object::notify_of_relation                                     00570784(*), 0057480c(*), 
    //                                                                                                         00574ab4(*)  
    //                              act_obj.cpp:202 (3)
    //         004062b0     RET        0x8
}

// Offset: 0x004062C0
void TRIBE_Building_Object::do_command(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Action_Object::do_command(class RGE_Static_Object *,float,floa... *
    //                              *********************************************************************************************************
    //                              void __thiscall do_command(RGE_Action_Object * this, RGE_Static_Obje
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Obj    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004062c0(R)  
    //              float             Stack[0x8]:4   param_2                   XREF[1]:     004062d9(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[1]:     004062d4(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[1]:     004062cb(R)  
    //                               ?do_command@RGE_Action_Object@@UAEXPAVRGE_Static_Object@@MM  XREF[5]:     0056e4b8(*), 0056f2f0(*), 
    //                               RGE_Action_Object::do_command                                             00570788(*), 00574810(*), 
    //                                                                                                         00574ab8(*)  
    //                              act_obj.cpp:208 (11)
    //         004062c0     MOV        EAX,dword ptr [ESP + param_1]
    //         004062c4     PUSH       ESI
    //         004062c5     MOV        ESI,this
    //         004062c7     CMP        EAX,ESI
    //         004062c9     JZ         LAB_004062ed
    //                              act_obj.cpp:212 (28)
    //         004062cb     MOV        this,dword ptr [ESP + param_4]
    //         004062cf     MOV        EDX,dword ptr [ESI]
    //         004062d1     PUSH       0x0
    //         004062d3     PUSH       this
    //         004062d4     MOV        this,dword ptr [ESP + param_3]
    //         004062d8     PUSH       this
    //         004062d9     MOV        this,dword ptr [ESP + param_2]
    //         004062dd     PUSH       this
    //         004062de     PUSH       EAX
    //         004062df     MOV        this,ESI
    //         004062e1     CALL       dword ptr [EDX + 0x1f8]
    //                              act_obj.cpp:213 (6)
    //         004062e7     INC        byte ptr [ESI + 0x188]
    //                               LAB_004062ed                                                 XREF[1]:     004062c9(j)  
    //                              act_obj.cpp:214 (4)
    //         004062ed     POP        ESI
    //         004062ee     RET        0x10
}

// Offset: 0x00406300
void TRIBE_Building_Object::move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Action_Object::move_to(class RGE_Static_Object *,float,float,f... *
    //                              *********************************************************************************************************
    //                              void __thiscall move_to(RGE_Action_Object * this, RGE_Static_Object 
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Obj    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[5]:     00406319(R), 00406358(W), 00406382(W), 004063b9(W), 
    //                                                                                     00406400(R)  
    //              float             Stack[0x8]:4   param_2                   XREF[4]:     0040632f(R), 00406392(R), 004063df(R), 004063ef(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[1]:     0040632b(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[1]:     00406327(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0040635e(W), 00406388(W), 004063af(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00406419(R)  
    //                               ?move_to@RGE_Action_Object@@UAEXPAVRGE_Static_Object@@MMM@Z  XREF[5]:     0056e4bc(*), 0056f2f4(*), 
    //                               RGE_Action_Object::move_to                                                0057078c(*), 00574814(*), 
    //                                                                                                         00574abc(*)  
    //                              act_obj.cpp:218 (25)
    //         00406300     MOV        EAX,FS:[0x0]
    //         00406306     PUSH       -0x1
    //         00406308     PUSH       FUN_0055c3f6
    //         0040630d     PUSH       EAX
    //         0040630e     MOV        dword ptr FS:[0x0],ESP
    //         00406315     PUSH       EBX
    //         00406316     PUSH       EBP
    //         00406317     PUSH       ESI
    //         00406318     PUSH       EDI
    //                              act_obj.cpp:220 (14)
    //         00406319     MOV        EDI,dword ptr [ESP + param_1]
    //         0040631d     MOV        ESI,this
    //         0040631f     CMP        EDI,ESI
    //         00406321     JZ         LAB_00406419
    //                              act_obj.cpp:224 (35)
    //         00406327     MOV        EBX,dword ptr [ESP + param_4]
    //         0040632b     MOV        EBP,dword ptr [ESP + param_3]
    //         0040632f     MOV        EAX,dword ptr [ESP + param_2]
    //         00406333     MOV        this,dword ptr [ESI + 0x184]
    //         00406339     PUSH       EBX
    //         0040633a     PUSH       EBP
    //         0040633b     PUSH       EAX
    //         0040633c     PUSH       EDI
    //         0040633d     CALL       RGE_Action_List::action_move_to                  int action_move_to(RGE_Action_List * this, RG
    //         00406342     TEST       EAX,EAX
    //         00406344     JNZ        LAB_00406419
    //                              act_obj.cpp:229 (2)
    //         0040634a     TEST       EDI,EDI
    //                              act_obj.cpp:230 (44)
    //         0040634c     PUSH       0x44
    //         0040634e     JZ         LAB_0040637a
    //         00406350     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00406355     ADD        ESP,0x4
    //         00406358     MOV        dword ptr [ESP + param_1],EAX
    //         0040635c     TEST       EAX,EAX
    //         0040635e     MOV        dword ptr [ESP + local_4],0x0
    //         00406366     JZ         LAB_004063aa
    //         00406368     PUSH       0x0
    //         0040636a     PUSH       0x3ecccccd
    //         0040636f     PUSH       EDI
    //         00406370     PUSH       ESI
    //         00406371     MOV        this,EAX
    //         00406373     CALL       RGE_Action_Move_To::RGE_Action_Move_To           undefined RGE_Action_Move_To(RGE_Action_Move_
    //                              act_obj.cpp:231 (2)
    //         00406378     JMP        LAB_004063ac
    //                               LAB_0040637a                                                 XREF[1]:     0040634e(j)  
    //                              act_obj.cpp:232 (50)
    //         0040637a     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0040637f     ADD        ESP,0x4
    //         00406382     MOV        dword ptr [ESP + param_1],EAX
    //         00406386     TEST       EAX,EAX
    //         00406388     MOV        dword ptr [ESP + local_4],0x1
    //         00406390     JZ         LAB_004063aa
    //         00406392     MOV        this,dword ptr [ESP + param_2]
    //         00406396     PUSH       0x0
    //         00406398     PUSH       0x3ecccccd
    //         0040639d     PUSH       EBX
    //         0040639e     PUSH       EBP
    //         0040639f     PUSH       this
    //         004063a0     PUSH       ESI
    //         004063a1     MOV        this,EAX
    //         004063a3     CALL       RGE_Action_Move_To::RGE_Action_Move_To           undefined RGE_Action_Move_To(RGE_Action_Move_
    //         004063a8     JMP        LAB_004063ac
    //                               LAB_004063aa                                                 XREF[2]:     00406366(j), 00406390(j)  
    //         004063aa     XOR        EAX,EAX
    //                               LAB_004063ac                                                 XREF[2]:     00406378(j), 004063a8(j)  
    //                              act_obj.cpp:234 (19)
    //         004063ac     MOV        this,dword ptr [ESI + 0x74]
    //         004063af     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004063b7     TEST       this,this
    //         004063b9     MOV        dword ptr [ESP + param_1],EAX
    //         004063bd     JZ         LAB_00406400
    //                              act_obj.cpp:235 (10)
    //         004063bf     PUSH       0x2c6
    //         004063c4     CALL       UnitAIModule::setCurrentOrder                    void setCurrentOrder(UnitAIModule * this, int
    //                              act_obj.cpp:236 (13)
    //         004063c9     MOV        this,dword ptr [ESI + 0x74]
    //         004063cc     PUSH       0x262
    //         004063d1     CALL       UnitAIModule::setCurrentAction                   void setCurrentAction(UnitAIModule * this, in
    //                              act_obj.cpp:237 (2)
    //         004063d6     TEST       EDI,EDI
    //                              act_obj.cpp:239 (21)
    //         004063d8     PUSH       EBX
    //         004063d9     PUSH       EBP
    //         004063da     JZ         LAB_004063ef
    //         004063dc     MOV        EAX,dword ptr [EDI + 0x8]
    //         004063df     MOV        EDX,dword ptr [ESP + param_2]
    //         004063e3     PUSH       EDX
    //         004063e4     MOV        EDX,dword ptr [EDI + 0x4]
    //         004063e7     MOVSX      this,word ptr [EAX + 0x14]
    //         004063eb     PUSH       this
    //         004063ec     PUSH       EDX
    //                              act_obj.cpp:240 (2)
    //         004063ed     JMP        LAB_004063f8
    //                               LAB_004063ef                                                 XREF[1]:     004063da(j)  
    //                              act_obj.cpp:241 (17)
    //         004063ef     MOV        EAX,dword ptr [ESP + param_2]
    //         004063f3     PUSH       EAX
    //         004063f4     PUSH       -0x1
    //         004063f6     PUSH       -0x1
    //                               LAB_004063f8                                                 XREF[1]:     004063ed(j)  
    //         004063f8     MOV        this,dword ptr [ESI + 0x74]
    //         004063fb     CALL       UnitAIModule::setCurrentTarget                   void setCurrentTarget(UnitAIModule * this, in
    //                               LAB_00406400                                                 XREF[1]:     004063bd(j)  
    //                              act_obj.cpp:244 (8)
    //         00406400     MOV        EAX,dword ptr [ESP + param_1]
    //         00406404     TEST       EAX,EAX
    //         00406406     JZ         LAB_00406413
    //                              act_obj.cpp:245 (11)
    //         00406408     MOV        EDX,dword ptr [ESI]
    //         0040640a     PUSH       EAX
    //         0040640b     MOV        this,ESI
    //         0040640d     CALL       dword ptr [EDX + 0x208]
    //                               LAB_00406413                                                 XREF[1]:     00406406(j)  
    //                              act_obj.cpp:246 (6)
    //         00406413     INC        byte ptr [ESI + 0x188]
    //                               LAB_00406419                                                 XREF[2]:     00406321(j), 00406344(j)  
    //                              act_obj.cpp:247 (21)
    //         00406419     MOV        this,dword ptr [ESP + local_c]
    //         0040641d     POP        EDI
    //         0040641e     POP        ESI
    //         0040641f     POP        EBP
    //         00406420     MOV        dword ptr FS:[0x0],this
    //         00406427     POP        EBX
    //         00406428     ADD        ESP,0xc
    //         0040642b     RET        0x10
}

// Offset: 0x00406430
void TRIBE_Building_Object::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Action_Object::work(class RGE_Static_Object *,float,float,float)  *
    //                              *********************************************************************************************************
    //                              void __thiscall work(RGE_Action_Object * this, RGE_Static_Object * p
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Obj    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00406430(R)  
    //              float             Stack[0x8]:4   param_2                   XREF[1]:     00406449(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[1]:     00406444(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[1]:     0040643b(R)  
    //                               ?work@RGE_Action_Object@@UAEXPAVRGE_Static_Object@@MMM@Z     XREF[5]:     0056e4c0(*), 0056f2f8(*), 
    //                               RGE_Action_Object::work                                                   00570790(*), 00574818(*), 
    //                                                                                                         00574ac0(*)  
    //                              act_obj.cpp:251 (11)
    //         00406430     MOV        EAX,dword ptr [ESP + param_1]
    //         00406434     PUSH       ESI
    //         00406435     MOV        ESI,this
    //         00406437     CMP        EAX,ESI
    //         00406439     JZ         LAB_0040645d
    //                              act_obj.cpp:255 (28)
    //         0040643b     MOV        this,dword ptr [ESP + param_4]
    //         0040643f     MOV        EDX,dword ptr [ESI]
    //         00406441     PUSH       0x1
    //         00406443     PUSH       this
    //         00406444     MOV        this,dword ptr [ESP + param_3]
    //         00406448     PUSH       this
    //         00406449     MOV        this,dword ptr [ESP + param_2]
    //         0040644d     PUSH       this
    //         0040644e     PUSH       EAX
    //         0040644f     MOV        this,ESI
    //         00406451     CALL       dword ptr [EDX + 0x1f8]
    //                              act_obj.cpp:256 (6)
    //         00406457     INC        byte ptr [ESI + 0x188]
    //                               LAB_0040645d                                                 XREF[1]:     00406439(j)  
    //                              act_obj.cpp:257 (4)
    //         0040645d     POP        ESI
    //         0040645e     RET        0x10
}

// Offset: 0x00406470
void TRIBE_Building_Object::work2(RGE_Static_Object* param_1, float param_2, float param_3, float param_4, uchar param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Action_Object::work2(class RGE_Static_Object *,float,float,flo... *
    //                              *********************************************************************************************************
    //                              void __thiscall work2(RGE_Action_Object * this, RGE_Static_Object * 
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Obj    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00406473(R)  
    //              float             Stack[0x8]:4   param_2                   XREF[1]:     00406496(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[1]:     00406491(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[1]:     00406486(R)  
    //              uchar             Stack[0x14]:1  param_5
    //              int               Stack[-0x8]:4  skip
    //                               ?work2@RGE_Action_Object@@UAEXPAVRGE_Static_Object@@MMME@Z   XREF[5]:     0056e618(*), 0056f450(*), 
    //                               RGE_Action_Object::work2                                                  005708e8(*), 00574970(*), 
    //                                                                                                         00574c18(*)  
    //                              act_obj.cpp:266 (3)
    //         00406470     PUSH       this
    //         00406471     PUSH       EBX
    //         00406472     PUSH       EBP
    //                              act_obj.cpp:282 (16)
    //         00406473     MOV        EBP,dword ptr [ESP + param_1]
    //         00406477     PUSH       ESI
    //         00406478     MOV        ESI,this
    //         0040647a     PUSH       EDI
    //         0040647b     CMP        EBP,ESI
    //         0040647d     JZ         LAB_0040677d
    //                              act_obj.cpp:286 (33)
    //         00406483     MOV        EAX,dword ptr [ESI + 0x8]
    //         00406486     MOV        EDI,dword ptr [ESP + param_4]
    //         0040648a     PUSH       EDI
    //         0040648b     MOV        this,dword ptr [EAX + 0xd8]
    //         00406491     MOV        EAX,dword ptr [ESP + param_3]
    //         00406495     PUSH       EAX
    //         00406496     MOV        EAX,dword ptr [ESP + param_2]
    //         0040649a     MOV        EDX,dword ptr [this->_padding_]
    //         0040649c     PUSH       EAX
    //         0040649d     PUSH       EBP
    //         0040649e     PUSH       ESI
    //         0040649f     CALL       dword ptr [EDX + 0x4]
    //         004064a2     MOV        EBX,EAX
    //                              act_obj.cpp:287 (8)
    //         004064a4     TEST       EBX,EBX
    //         004064a6     JNZ        LAB_0040653d
    //                              act_obj.cpp:292 (17)
    //         004064ac     MOV        this,dword ptr [ESI + 0x8]
    //         004064af     MOV        AL,byte ptr [ECX + this->_padding_]
    //         004064b5     TEST       AL,AL
    //         004064b7     JZ         LAB_0040653d
    //                              act_obj.cpp:294 (15)
    //         004064bd     MOV        EAX,dword ptr [ESI + 0xc]
    //         004064c0     XOR        this,this
    //         004064c2     MOV        dword ptr [ESP + 0x18],this
    //         004064c6     CMP        word ptr [EAX + 0x22],this
    //         004064ca     JLE        LAB_0040653d
    //                               LAB_004064cc                                                 XREF[1]:     0040652d(j)  
    //                              act_obj.cpp:296 (6)
    //         004064cc     MOV        EDX,dword ptr [EAX + 0x24]
    //         004064cf     MOV        EDI,dword ptr [EDX + this->_padding_*0x4]
    //                              act_obj.cpp:300 (39)
    //         004064d2     TEST       EDI,EDI
    //         004064d4     JZ         LAB_0040651f
    //         004064d6     MOV        EAX,dword ptr [ESI + 0x8]
    //         004064d9     MOV        DX,word ptr [EDI + 0x14]
    //         004064dd     CMP        DX,word ptr [EAX + 0x14]
    //         004064e1     JNZ        LAB_0040651f
    //         004064e3     MOV        DL,byte ptr [EDI + 0x4]
    //         004064e6     CMP        DL,byte ptr [EAX + 0x4]
    //         004064e9     JNZ        LAB_0040651f
    //         004064eb     MOV        DL,byte ptr [EDI + 0xec]
    //         004064f1     CMP        DL,byte ptr [EAX + 0xec]
    //         004064f7     JNZ        LAB_0040651f
    //                              act_obj.cpp:303 (30)
    //         004064f9     MOV        EDX,dword ptr [ESP + 0x24]
    //         004064fd     MOV        this,dword ptr [EDI + 0xd8]
    //         00406503     PUSH       EDX
    //         00406504     MOV        EDX,dword ptr [ESP + 0x24]
    //         00406508     MOV        EAX,dword ptr [this->_padding_]
    //         0040650a     PUSH       EDX=>DAT_fffffff8
    //         0040650b     MOV        EDX,dword ptr [ESP + 0x24]
    //         0040650f     PUSH       EDX=>DAT_fffffff4
    //         00406510     PUSH       EBP=>DAT_fffffff0
    //         00406511     PUSH       ESI
    //         00406512     CALL       dword ptr [EAX + 0x4]
    //         00406515     MOV        EBX,EAX
    //                              act_obj.cpp:304 (8)
    //         00406517     TEST       EBX,EBX
    //         00406519     JNZ        LAB_00406531
    //         0040651b     MOV        this,dword ptr [ESP + 0x18]
    //                               LAB_0040651f                                                 XREF[4]:     004064d4(j), 004064e1(j), 
    //                                                                                                         004064e9(j), 004064f7(j)  
    //                              act_obj.cpp:294 (18)
    //         0040651f     MOV        EAX,dword ptr [ESI + 0xc]
    //         00406522     INC        this
    //         00406523     MOV        dword ptr [ESP + 0x18],this
    //         00406527     MOVSX      EDX,word ptr [EAX + 0x22]
    //         0040652b     CMP        this,EDX
    //         0040652d     JL         LAB_004064cc
    //         0040652f     JMP        LAB_00406539
    //                               LAB_00406531                                                 XREF[1]:     00406519(j)  
    //                              act_obj.cpp:307 (12)
    //         00406531     MOV        EAX,dword ptr [ESI]
    //         00406533     PUSH       EDI
    //         00406534     MOV        this,ESI
    //         00406536     CALL       dword ptr [EAX + 0x54]
    //                               LAB_00406539                                                 XREF[1]:     0040652f(j)  
    //         00406539     MOV        EDI,dword ptr [ESP + 0x24]
    //                               LAB_0040653d                                                 XREF[3]:     004064a6(j), 004064b7(j), 
    //                                                                                                         004064ca(j)  
    //                              act_obj.cpp:318 (11)
    //         0040653d     MOV        this,dword ptr [ESI + 0x184]
    //         00406543     CALL       RGE_Action_List::get_task                        RGE_Task * get_task(RGE_Action_List * this)
    //                              act_obj.cpp:321 (20)
    //         00406548     TEST       EAX,EAX
    //         0040654a     MOV        dword ptr [ESP + 0x10],0x0
    //         00406552     MOV        dword ptr [ESP + 0x18],0xffffffff
    //         0040655a     JZ         LAB_00406599
    //                              act_obj.cpp:323 (4)
    //         0040655c     CMP        EBX,EAX
    //         0040655e     JNZ        LAB_00406599
    //                              act_obj.cpp:325 (27)
    //         00406560     MOV        this,dword ptr [ESP + 0x20]
    //         00406564     MOV        EDX,dword ptr [ESP + 0x1c]
    //         00406568     PUSH       EDI
    //         00406569     PUSH       this=>DAT_fffffff8
    //         0040656a     MOV        this,dword ptr [ESI + 0x184]
    //         00406570     PUSH       EDX=>DAT_fffffff4
    //         00406571     PUSH       EBP=>DAT_fffffff0
    //         00406572     CALL       RGE_Action_List::action_work                     int action_work(RGE_Action_List * this, RGE_S
    //         00406577     TEST       EAX,EAX
    //         00406579     JZ         LAB_00406599
    //                              act_obj.cpp:327 (22)
    //         0040657b     MOV        this,dword ptr [ESI + 0x184]
    //         00406581     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
    //         00406586     MOV        EDX,dword ptr [EAX]
    //         00406588     MOV        this,EAX
    //         0040658a     CALL       dword ptr [EDX + 0x18]
    //         0040658d     MOV        dword ptr [ESP + 0x18],EAX
    //                              act_obj.cpp:328 (8)
    //         00406591     MOV        dword ptr [ESP + 0x10],0x1
    //                               LAB_00406599                                                 XREF[3]:     0040655a(j), 0040655e(j), 
    //                                                                                                         00406579(j)  
    //                              act_obj.cpp:361 (61)
    //         00406599     MOV        this,dword ptr [ESI + 0x184]
    //         0040659f     CALL       RGE_Action_List::have_action                     uchar have_action(RGE_Action_List * this)
    //         004065a4     CMP        AL,0x1
    //         004065a6     JNZ        LAB_00406615
    //         004065a8     MOV        this,dword ptr [ESI + 0x184]
    //         004065ae     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
    //         004065b3     MOV        EDX,dword ptr [EAX]
    //         004065b5     MOV        this,EAX
    //         004065b7     CALL       dword ptr [EDX + 0x4c]
    //         004065ba     CMP        EAX,EBP
    //         004065bc     JNZ        LAB_00406615
    //         004065be     MOV        this,dword ptr [ESI + 0x184]
    //         004065c4     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
    //         004065c9     MOV        EDX,dword ptr [EAX]
    //         004065cb     MOV        this,EAX
    //         004065cd     CALL       dword ptr [EDX + 0x18]
    //         004065d0     CMP        AX,0x9
    //         004065d4     JNZ        LAB_00406615
    //                              act_obj.cpp:363 (34)
    //         004065d6     MOV        this,dword ptr [ESI + 0x184]
    //         004065dc     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
    //         004065e1     MOV        this,dword ptr [ESP + 0x20]
    //         004065e5     MOV        EDX,dword ptr [EAX]
    //         004065e7     PUSH       EDI
    //         004065e8     PUSH       this=>DAT_fffffff8
    //         004065e9     MOV        this,dword ptr [ESP + 0x24]
    //         004065ed     PUSH       this=>DAT_fffffff4
    //         004065ee     PUSH       EBP=>DAT_fffffff0
    //         004065ef     MOV        this,EAX
    //         004065f1     CALL       dword ptr [EDX + 0x34]
    //         004065f4     TEST       EAX,EAX
    //         004065f6     JZ         LAB_00406615
    //                              act_obj.cpp:365 (22)
    //         004065f8     MOV        this,dword ptr [ESI + 0x184]
    //         004065fe     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
    //         00406603     MOV        EDX,dword ptr [EAX]
    //         00406605     MOV        this,EAX
    //         00406607     CALL       dword ptr [EDX + 0x18]
    //         0040660a     MOV        dword ptr [ESP + 0x18],EAX
    //                              act_obj.cpp:366 (11)
    //         0040660e     MOV        EAX,0x1
    //         00406613     JMP        LAB_00406619
    //                               LAB_00406615                                                 XREF[4]:     004065a6(j), 004065bc(j), 
    //                                                                                                         004065d4(j), 004065f6(j)  
    //         00406615     MOV        EAX,dword ptr [ESP + 0x10]
    //                               LAB_00406619                                                 XREF[1]:     00406613(j)  
    //                              act_obj.cpp:370 (4)
    //         00406619     TEST       EAX,EAX
    //         0040661b     JNZ        LAB_00406679
    //                              act_obj.cpp:373 (4)
    //         0040661d     TEST       EBX,EBX
    //         0040661f     JZ         LAB_0040663d
    //                              act_obj.cpp:374 (26)
    //         00406621     MOV        EDX,dword ptr [ESP + 0x20]
    //         00406625     MOV        this,dword ptr [ESI + 0x184]
    //         0040662b     PUSH       EDI
    //         0040662c     PUSH       EDX=>DAT_fffffff8
    //         0040662d     MOV        EDX,dword ptr [ESP + 0x24]
    //         00406631     MOV        EAX,dword ptr [this->_padding_]
    //         00406633     PUSH       EDX=>DAT_fffffff4
    //         00406634     PUSH       EBP=>DAT_fffffff0
    //         00406635     PUSH       EBX
    //         00406636     CALL       dword ptr [EAX + 0x4]
    //         00406639     MOV        EBX,EAX
    //                              act_obj.cpp:375 (2)
    //         0040663b     JMP        LAB_0040663f
    //                               LAB_0040663d                                                 XREF[1]:     0040661f(j)  
    //                              act_obj.cpp:376 (2)
    //         0040663d     XOR        EBX,EBX
    //                               LAB_0040663f                                                 XREF[1]:     0040663b(j)  
    //                              act_obj.cpp:380 (4)
    //         0040663f     TEST       EBX,EBX
    //         00406641     JZ         LAB_0040665b
    //                              act_obj.cpp:382 (7)
    //         00406643     MOV        EAX,dword ptr [EBX]
    //         00406645     MOV        this,EBX
    //         00406647     CALL       dword ptr [EAX + 0x18]
    //                              act_obj.cpp:383 (15)
    //         0040664a     MOV        EDX,dword ptr [ESI]
    //         0040664c     PUSH       EBX
    //         0040664d     MOV        this,ESI
    //         0040664f     MOV        dword ptr [ESP + 0x1c],EAX
    //         00406653     CALL       dword ptr [EDX + 0x208]
    //                              act_obj.cpp:385 (2)
    //         00406659     JMP        LAB_00406679
    //                               LAB_0040665b                                                 XREF[1]:     00406641(j)  
    //                              act_obj.cpp:388 (30)
    //         0040665b     MOV        this,dword ptr [ESP + 0x20]
    //         0040665f     MOV        EDX,dword ptr [ESP + 0x1c]
    //         00406663     MOV        EAX,dword ptr [ESI]
    //         00406665     PUSH       EDI
    //         00406666     PUSH       this=>DAT_fffffff8
    //         00406667     PUSH       EDX=>DAT_fffffff4
    //         00406668     PUSH       EBP=>DAT_fffffff0
    //         00406669     MOV        this,ESI
    //         0040666b     MOV        dword ptr [ESP + 0x28],0x1
    //         00406673     CALL       dword ptr [EAX + 0x9c]
    //                               LAB_00406679                                                 XREF[2]:     0040661b(j), 00406659(j)  
    //                              act_obj.cpp:393 (11)
    //         00406679     MOV        this,dword ptr [ESI + 0x74]
    //         0040667c     TEST       this,this
    //         0040667e     JZ         LAB_0040677d
    //                              act_obj.cpp:397 (36)
    //         00406684     MOVSX      EDX,word ptr [ESP + 0x18]
    //         00406689     OR         EAX,0xffffffff
    //         0040668c     OR         EDI,0xffffffff
    //         0040668f     DEC        EDX
    //         00406690     CMP        EDX,0x6e
    //         00406693     JA         switchD_004066a1::caseD_2
    //         00406699     XOR        EBX,EBX
    //         0040669b     MOV        BL,byte ptr [EDX + 0x4067bc]=>PTR_caseD_2_0040
    //                               switchD_004066a1::switchD
    //         004066a1     JMP        dword ptr [EBX*0x4 + switchD_004066a1::switchd   = 004066e7
    //                               switchD_004066a1::caseD_9                                    XREF[2]:     004066a1(j), 00406798(*)  
    //                              act_obj.cpp:400 (5)
    //         004066a8     MOV        EDI,0x258
    //                              act_obj.cpp:401 (5)
    //         004066ad     MOV        EAX,0x2bc
    //                              act_obj.cpp:402 (5)
    //         004066b2     JMP        switchD_004066a1::caseD_2
    //                               switchD_004066a1::caseD_65                                   XREF[2]:     004066a1(j), 004067a0(*)  
    //                              act_obj.cpp:404 (5)
    //         004066b7     MOV        EDI,0x25a
    //                              act_obj.cpp:405 (5)
    //         004066bc     MOV        EAX,0x2be
    //                              act_obj.cpp:406 (2)
    //         004066c1     JMP        switchD_004066a1::caseD_2
    //                               switchD_004066a1::caseD_3                                    XREF[2]:     004066a1(j), 0040678c(*)  
    //                              act_obj.cpp:408 (5)
    //         004066c3     MOV        EDI,0x269
    //                              act_obj.cpp:409 (5)
    //         004066c8     MOV        EAX,0x2cd
    //                              act_obj.cpp:410 (2)
    //         004066cd     JMP        switchD_004066a1::caseD_2
    //                               switchD_004066a1::caseD_4                                    XREF[2]:     004066a1(j), 00406790(*)  
    //                              act_obj.cpp:412 (5)
    //         004066cf     MOV        EDI,0x25d
    //                              act_obj.cpp:413 (5)
    //         004066d4     MOV        EAX,0x2c1
    //                              act_obj.cpp:414 (2)
    //         004066d9     JMP        switchD_004066a1::caseD_2
    //                               switchD_004066a1::caseD_5                                    XREF[2]:     004066a1(j), 00406794(*)  
    //                              act_obj.cpp:416 (5)
    //         004066db     MOV        EDI,0x261
    //                              act_obj.cpp:417 (5)
    //         004066e0     MOV        EAX,0x2c5
    //                              act_obj.cpp:418 (2)
    //         004066e5     JMP        switchD_004066a1::caseD_2
    //                               switchD_004066a1::caseD_1                                    XREF[2]:     004066a1(j), 00406788(*)  
    //                              act_obj.cpp:420 (5)
    //         004066e7     MOV        EDI,0x262
    //                              act_obj.cpp:421 (5)
    //         004066ec     MOV        EAX,0x2c6
    //                              act_obj.cpp:422 (2)
    //         004066f1     JMP        switchD_004066a1::caseD_2
    //                               switchD_004066a1::caseD_6e                                   XREF[2]:     004066a1(j), 004067b0(*)  
    //                              act_obj.cpp:424 (5)
    //         004066f3     MOV        EDI,0x265
    //                              act_obj.cpp:425 (5)
    //         004066f8     MOV        EAX,0x2c9
    //                              act_obj.cpp:426 (2)
    //         004066fd     JMP        switchD_004066a1::caseD_2
    //                               switchD_004066a1::caseD_c                                    XREF[2]:     004066a1(j), 0040679c(*)  
    //                              act_obj.cpp:428 (5)
    //         004066ff     MOV        EDI,0x266
    //                              act_obj.cpp:429 (5)
    //         00406704     MOV        EAX,0x2ca
    //                              act_obj.cpp:430 (2)
    //         00406709     JMP        switchD_004066a1::caseD_2
    //                               switchD_004066a1::caseD_6f                                   XREF[2]:     004066a1(j), 004067b4(*)  
    //                              act_obj.cpp:432 (5)
    //         0040670b     MOV        EDI,0x267
    //                              act_obj.cpp:433 (5)
    //         00406710     MOV        EAX,0x2cb
    //                              act_obj.cpp:434 (2)
    //         00406715     JMP        switchD_004066a1::caseD_2
    //                               switchD_004066a1::caseD_68                                   XREF[2]:     004066a1(j), 004067a4(*)  
    //                              act_obj.cpp:436 (5)
    //         00406717     MOV        EDI,0x25c
    //                              act_obj.cpp:437 (5)
    //         0040671c     MOV        EAX,0x2c0
    //                              act_obj.cpp:438 (2)
    //         00406721     JMP        switchD_004066a1::caseD_2
    //                               switchD_004066a1::caseD_69                                   XREF[2]:     004066a1(j), 004067a8(*)  
    //                              act_obj.cpp:440 (5)
    //         00406723     MOV        EDI,0x25b
    //                              act_obj.cpp:441 (5)
    //         00406728     MOV        EAX,0x2bf
    //                              act_obj.cpp:442 (2)
    //         0040672d     JMP        switchD_004066a1::caseD_2
    //                               switchD_004066a1::caseD_6a                                   XREF[2]:     004066a1(j), 004067ac(*)  
    //                              act_obj.cpp:444 (5)
    //         0040672f     MOV        EDI,0x26a
    //                              act_obj.cpp:445 (5)
    //         00406734     MOV        EAX,0x2ce
    //                               switchD_004066a1::caseD_6                                    XREF[14]:    00406693(j), 004066a1(j), 
    //                               switchD_004066a1::caseD_7                                                 004066b2(j), 004066c1(j), 
    //                               switchD_004066a1::caseD_8                                                 004066cd(j), 004066d9(j), 
    //                               switchD_004066a1::caseD_a                                                 004066e5(j), 004066f1(j), 
    //                               switchD_004066a1::caseD_b                                                 004066fd(j), 00406709(j), 
    //                               switchD_004066a1::caseD_d                                                 00406715(j), 00406721(j), 
    //                               switchD_004066a1::caseD_e                                                 0040672d(j), 004067b8(*)  
    //                               switchD_004066a1::caseD_f
    //                               switchD_004066a1::caseD_10
    //                               switchD_004066a1::caseD_11
    //                               switchD_004066a1::caseD_12
    //                               switchD_004066a1::caseD_13
    //                               switchD_004066a1::caseD_14
    //                               switchD_004066a1::caseD_15
    //                               switchD_004066a1::caseD_16
    //                               switchD_004066a1::caseD_17
    //                               switchD_004066a1::caseD_18
    //                               switchD_004066a1::caseD_19
    //                               switchD_004066a1::caseD_1a
    //                               switchD_004066a1::caseD_1b
    //                               switchD_004066a1::caseD_1c
    //                               switchD_004066a1::caseD_1d
    //                               switchD_004066a1::caseD_1e
    //                               switchD_004066a1::caseD_1f
    //                               switchD_004066a1::caseD_20
    //                               switchD_004066a1::caseD_21
    //                               switchD_004066a1::caseD_22
    //                               switchD_004066a1::caseD_23
    //                               switchD_004066a1::caseD_24
    //                               switchD_004066a1::caseD_25
    //                               switchD_004066a1::caseD_26
    //                               switchD_004066a1::caseD_27
    //                               switchD_004066a1::caseD_28
    //                               switchD_004066a1::caseD_29
    //                               switchD_004066a1::caseD_2a
    //                               switchD_004066a1::caseD_2b
    //                               switchD_004066a1::caseD_2c
    //                               switchD_004066a1::caseD_2d
    //                               switchD_004066a1::caseD_2e
    //                               switchD_004066a1::caseD_2f
    //                               switchD_004066a1::caseD_30
    //                               switchD_004066a1::caseD_31
    //                               switchD_004066a1::caseD_32
    //                               switchD_004066a1::caseD_33
    //                               switchD_004066a1::caseD_34
    //                               switchD_004066a1::caseD_35
    //                               switchD_004066a1::caseD_36
    //                               switchD_004066a1::caseD_37
    //                               switchD_004066a1::caseD_38
    //                               switchD_004066a1::caseD_39
    //                               switchD_004066a1::caseD_3a
    //                               switchD_004066a1::caseD_3b
    //                               switchD_004066a1::caseD_3c
    //                               switchD_004066a1::caseD_3d
    //                               switchD_004066a1::caseD_3e
    //                               switchD_004066a1::caseD_3f
    //                               switchD_004066a1::caseD_40
    //                               switchD_004066a1::caseD_41
    //                               switchD_004066a1::caseD_42
    //                               switchD_004066a1::caseD_43
    //                               switchD_004066a1::caseD_44
    //                               switchD_004066a1::caseD_45
    //                               switchD_004066a1::caseD_46
    //                               switchD_004066a1::caseD_47
    //                               switchD_004066a1::caseD_48
    //                               switchD_004066a1::caseD_49
    //                               switchD_004066a1::caseD_4a
    //                               switchD_004066a1::caseD_4b
    //                               switchD_004066a1::caseD_4c
    //                               switchD_004066a1::caseD_4d
    //                               switchD_004066a1::caseD_4e
    //                               switchD_004066a1::caseD_4f
    //                               switchD_004066a1::caseD_50
    //                               switchD_004066a1::caseD_51
    //                               switchD_004066a1::caseD_52
    //                               switchD_004066a1::caseD_53
    //                               switchD_004066a1::caseD_54
    //                               switchD_004066a1::caseD_55
    //                               switchD_004066a1::caseD_56
    //                               switchD_004066a1::caseD_57
    //                               switchD_004066a1::caseD_58
    //                               switchD_004066a1::caseD_59
    //                               switchD_004066a1::caseD_5a
    //                               switchD_004066a1::caseD_5b
    //                               switchD_004066a1::caseD_5c
    //                               switchD_004066a1::caseD_5d
    //                               switchD_004066a1::caseD_5e
    //                               switchD_004066a1::caseD_5f
    //                               switchD_004066a1::caseD_60
    //                               switchD_004066a1::caseD_61
    //                               switchD_004066a1::caseD_62
    //                               switchD_004066a1::caseD_63
    //                               switchD_004066a1::caseD_64
    //                               switchD_004066a1::caseD_66
    //                               switchD_004066a1::caseD_67
    //                               switchD_004066a1::caseD_6b
    //                               switchD_004066a1::caseD_6c
    //                               switchD_004066a1::caseD_6d
    //                               switchD_004066a1::caseD_2
    //                              act_obj.cpp:448 (6)
    //         00406739     PUSH       EAX
    //         0040673a     CALL       UnitAIModule::setCurrentOrder                    void setCurrentOrder(UnitAIModule * this, int
    //                              act_obj.cpp:449 (9)
    //         0040673f     MOV        this,dword ptr [ESI + 0x74]
    //         00406742     PUSH       EDI
    //         00406743     CALL       UnitAIModule::setCurrentAction                   void setCurrentAction(UnitAIModule * this, in
    //                              act_obj.cpp:452 (31)
    //         00406748     MOV        EAX,dword ptr [ESP + 0x24]
    //         0040674c     MOV        this,dword ptr [ESP + 0x20]
    //         00406750     MOV        EDX,dword ptr [ESP + 0x1c]
    //         00406754     PUSH       EAX
    //         00406755     TEST       EBP,EBP
    //         00406757     PUSH       this=>DAT_fffffff8
    //         00406758     PUSH       EDX=>DAT_fffffff4
    //         00406759     JZ         LAB_00406769
    //         0040675b     MOV        EAX,dword ptr [EBP + 0x8]
    //         0040675e     MOV        EDX,dword ptr [EBP + 0x4]
    //         00406761     MOVSX      this,word ptr [EAX + 0x14]
    //         00406765     PUSH       this=>DAT_fffffff0
    //         00406766     PUSH       EDX
    //                              act_obj.cpp:453 (2)
    //         00406767     JMP        LAB_0040676d
    //                               LAB_00406769                                                 XREF[1]:     00406759(j)  
    //                              act_obj.cpp:454 (12)
    //         00406769     PUSH       offset DAT_fffffff0
    //         0040676b     PUSH       -0x1
    //                               LAB_0040676d                                                 XREF[1]:     00406767(j)  
    //         0040676d     MOV        this,dword ptr [ESI + 0x74]
    //         00406770     CALL       UnitAIModule::setCurrentTarget                   void setCurrentTarget(UnitAIModule * this, in
    //                              act_obj.cpp:460 (8)
    //         00406775     MOV        this,dword ptr [ESI + 0x74]
    //         00406778     CALL       UnitAIModule::setTaskedByPlayer                  void setTaskedByPlayer(UnitAIModule * this)
    //                               LAB_0040677d                                                 XREF[2]:     0040647d(j), 0040667e(j)  
    //                              act_obj.cpp:462 (174)
    //         0040677d     POP        EDI
    //         0040677e     POP        ESI
    //         0040677f     POP        EBP
    //         00406780     POP        EBX
    //         00406781     POP        this
    //         00406782     RET        0x14
}

// Offset: 0x00406785
undefined FUN_00406785() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_00406785()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00406785
    //         00406785     NOP
    //         00406786     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_004066a1::switchdataD_00406788                       XREF[1]:     work2:004066a1(*)  
}

// Offset: 0x00406830
void TRIBE_Building_Object::set_attack(RGE_Static_Object* param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Action_Object::set_attack(class RGE_Static_Object *)              *
    //                              *********************************************************************************************************
    //                              void __thiscall set_attack(RGE_Action_Object * this, RGE_Static_Obje
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Obj    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1
    //                               ?set_attack@RGE_Action_Object@@UAEXPAVRGE_Static_Object@@@Z  XREF[5]:     0056e4c8(*), 0056f300(*), 
    //                               RGE_Action_Object::set_attack                                             00570798(*), 00574820(*), 
    //                                                                                                         00574ac8(*)  
    //                              act_obj.cpp:466 (3)
    //         00406830     RET        0x4
}

// Offset: 0x00406840
void TRIBE_Building_Object::play_command_sound() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Action_Object::play_command_sound(void)                           *
    //                              *********************************************************************************************************
    //                              void __thiscall play_command_sound(RGE_Action_Object * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Obj    ECX:4 (auto)   this
    //                               ?play_command_sound@RGE_Action_Object@@UAEXXZ                XREF[5]:     0056e4cc(*), 0056f304(*), 
    //                               RGE_Action_Object::play_command_sound                                     0057079c(*), 00574824(*), 
    //                                                                                                         00574acc(*)  
    //                              act_obj.cpp:472 (8)
    //         00406840     MOV        this,dword ptr [ECX + this->_padding_]
    //         00406843     MOV        EAX,dword ptr [this->_padding_]
    //         00406845     JMP        dword ptr [EAX + 0x2c]
}

// Offset: 0x00406850
void TRIBE_Building_Object::play_move_sound() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Action_Object::play_move_sound(void)                              *
    //                              *********************************************************************************************************
    //                              void __thiscall play_move_sound(RGE_Action_Object * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Obj    ECX:4 (auto)   this
    //                               ?play_move_sound@RGE_Action_Object@@UAEXXZ                   XREF[5]:     0056e4d0(*), 0056f308(*), 
    //                               RGE_Action_Object::play_move_sound                                        005707a0(*), 00574828(*), 
    //                                                                                                         00574ad0(*)  
    //                              act_obj.cpp:478 (8)
    //         00406850     MOV        this,dword ptr [ECX + this->_padding_]
    //         00406853     MOV        EAX,dword ptr [this->_padding_]
    //         00406855     JMP        dword ptr [EAX + 0x30]
}

// Offset: 0x00406860
RGE_Master_Static_Object* TRIBE_Building_Object::get_command_master(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual class RGE_Master_Static_Object * __thiscall RGE_Action_Object::get_command_master(... *
    //                              *********************************************************************************************************
    //                              RGE_Master_Static_Object * __thiscall get_command_master(RGE_Action_
    //              RGE_Master_Sta    EAX:4          <RETURN>
    //              RGE_Action_Obj    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00406861(R)  
    //              float             Stack[0x8]:4   param_2                   XREF[1]:     00406893(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[1]:     00406887(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[1]:     00406883(R)  
    //                               ?get_command_master@RGE_Action_Object@@UAEPAVRGE_Master_Sta  XREF[5]:     0056e4dc(*), 0056f314(*), 
    //                               RGE_Action_Object::get_command_master                                     005707ac(*), 00574834(*), 
    //                                                                                                         00574adc(*)  
    //                              act_obj.cpp:484 (1)
    //         00406860     PUSH       EBX
    //                              act_obj.cpp:490 (34)
    //         00406861     MOV        EBX,dword ptr [ESP + param_1]
    //         00406865     PUSH       EBP
    //         00406866     PUSH       ESI
    //         00406867     PUSH       EDI
    //         00406868     MOV        EDI,this
    //         0040686a     CMP        EBX,EDI
    //         0040686c     JZ         LAB_00406933
    //         00406872     MOV        EAX,dword ptr [EDI + 0x8]
    //         00406875     MOV        this,byte ptr [EAX + 0xec]
    //         0040687b     TEST       this,this
    //         0040687d     JZ         LAB_00406933
    //                              act_obj.cpp:494 (28)
    //         00406883     MOV        EBP,dword ptr [ESP + param_4]
    //         00406887     MOV        EDX,dword ptr [ESP + param_3]
    //         0040688b     MOV        this,dword ptr [EAX + 0xd8]
    //         00406891     PUSH       EBP
    //         00406892     PUSH       EDX
    //         00406893     MOV        EDX,dword ptr [ESP + param_2]
    //         00406897     MOV        EAX,dword ptr [this->_padding_]
    //         00406899     PUSH       EDX
    //         0040689a     PUSH       EBX
    //         0040689b     PUSH       EDI
    //         0040689c     CALL       dword ptr [EAX + 0x4]
    //                              act_obj.cpp:495 (2)
    //         0040689f     TEST       EAX,EAX
    //                              act_obj.cpp:496 (9)
    //         004068a1     MOV        EAX,dword ptr [EDI + 0x8]
    //         004068a4     JNZ        LAB_00406936
    //                              act_obj.cpp:501 (10)
    //         004068aa     MOV        this,byte ptr [EAX + 0xec]
    //         004068b0     TEST       this,this
    //         004068b2     JZ         LAB_00406933
    //                              act_obj.cpp:503 (15)
    //         004068b4     MOV        EAX,dword ptr [EDI + 0xc]
    //         004068b7     XOR        this,this
    //         004068b9     MOV        dword ptr [ESP + 0x14],this
    //         004068bd     CMP        word ptr [EAX + 0x22],this
    //         004068c1     JLE        LAB_00406933
    //                               LAB_004068c3                                                 XREF[1]:     0040691e(j)  
    //                              act_obj.cpp:505 (6)
    //         004068c3     MOV        EDX,dword ptr [EAX + 0x24]
    //         004068c6     MOV        ESI,dword ptr [EDX + this->_padding_*0x4]
    //                              act_obj.cpp:509 (39)
    //         004068c9     TEST       ESI,ESI
    //         004068cb     JZ         LAB_00406910
    //         004068cd     MOV        EAX,dword ptr [EDI + 0x8]
    //         004068d0     MOV        DX,word ptr [ESI + 0x14]
    //         004068d4     CMP        DX,word ptr [EAX + 0x14]
    //         004068d8     JNZ        LAB_00406910
    //         004068da     MOV        DL,byte ptr [ESI + 0x4]
    //         004068dd     CMP        DL,byte ptr [EAX + 0x4]
    //         004068e0     JNZ        LAB_00406910
    //         004068e2     MOV        DL,byte ptr [ESI + 0xec]
    //         004068e8     CMP        DL,byte ptr [EAX + 0xec]
    //         004068ee     JNZ        LAB_00406910
    //                              act_obj.cpp:511 (24)
    //         004068f0     MOV        EDX,dword ptr [ESP + 0x1c]
    //         004068f4     MOV        this,dword ptr [ESI + 0xd8]
    //         004068fa     PUSH       EBP
    //         004068fb     PUSH       EDX=>DAT_fffffff8
    //         004068fc     MOV        EDX,dword ptr [ESP + 0x20]
    //         00406900     MOV        EAX,dword ptr [this->_padding_]
    //         00406902     PUSH       EDX=>DAT_fffffff4
    //         00406903     PUSH       EBX=>DAT_fffffff0
    //         00406904     PUSH       EDI
    //         00406905     CALL       dword ptr [EAX + 0x4]
    //                              act_obj.cpp:512 (8)
    //         00406908     TEST       EAX,EAX
    //         0040690a     JNZ        LAB_0040692a
    //         0040690c     MOV        this,dword ptr [ESP + 0x14]
    //                               LAB_00406910                                                 XREF[4]:     004068cb(j), 004068d8(j), 
    //                                                                                                         004068e0(j), 004068ee(j)  
    //                              act_obj.cpp:503 (16)
    //         00406910     MOV        EAX,dword ptr [EDI + 0xc]
    //         00406913     INC        this
    //         00406914     MOV        dword ptr [ESP + 0x14],this
    //         00406918     MOVSX      EDX,word ptr [EAX + 0x22]
    //         0040691c     CMP        this,EDX
    //         0040691e     JL         LAB_004068c3
    //                              act_obj.cpp:491 (3)
    //         00406920     MOV        EAX,dword ptr [EDI + 0x8]
    //                              act_obj.cpp:519 (7)
    //         00406923     POP        EDI
    //         00406924     POP        ESI
    //         00406925     POP        EBP
    //         00406926     POP        EBX
    //         00406927     RET        0x10
    //                               LAB_0040692a                                                 XREF[1]:     0040690a(j)  
    //                              act_obj.cpp:513 (2)
    //         0040692a     MOV        EAX,ESI
    //                              act_obj.cpp:519 (7)
    //         0040692c     POP        EDI
    //         0040692d     POP        ESI
    //         0040692e     POP        EBP
    //         0040692f     POP        EBX
    //         00406930     RET        0x10
    //                               LAB_00406933                                                 XREF[4]:     0040686c(j), 0040687d(j), 
    //                                                                                                         004068b2(j), 004068c1(j)  
    //                              act_obj.cpp:491 (3)
    //         00406933     MOV        EAX,dword ptr [EDI + 0x8]
    //                               LAB_00406936                                                 XREF[1]:     004068a4(j)  
    //                              act_obj.cpp:519 (7)
    //         00406936     POP        EDI
    //         00406937     POP        ESI
    //         00406938     POP        EBP
    //         00406939     POP        EBX
    //         0040693a     RET        0x10
}

// Offset: 0x00406940
void TRIBE_Building_Object::set_task(short param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Action_Object::set_task(short)                                    *
    //                              *********************************************************************************************************
    //                              void __thiscall set_task(RGE_Action_Object * this, short param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Obj    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[1]:     00406940(R)  
    //                               ?set_task@RGE_Action_Object@@UAEXF@Z                         XREF[6]:     TRIBE_Building_Object:004c8018(c), 
    //                               RGE_Action_Object::set_task                                               0056e61c(*), 0056f454(*), 
    //                                                                                                         005708ec(*), 00574974(*), 
    //                                                                                                         00574c1c(*)  
    //                              act_obj.cpp:525 (16)
    //         00406940     MOV        EAX,dword ptr [ESP + param_1]
    //         00406944     PUSH       ESI
    //         00406945     MOV        ESI,this
    //         00406947     PUSH       EAX
    //         00406948     MOV        this,dword ptr [ESI + 0x8]
    //         0040694b     CALL       RGE_Master_Action_Object::get_task               RGE_Task * get_task(RGE_Master_Action_Object 
    //                              act_obj.cpp:531 (4)
    //         00406950     TEST       EAX,EAX
    //         00406952     JZ         LAB_00406980
    //                              act_obj.cpp:533 (29)
    //         00406954     MOV        this,dword ptr [ESI + 0x184]
    //         0040695a     PUSH       0xbf800000
    //         0040695f     PUSH       0xbf800000
    //         00406964     PUSH       0xbf800000
    //         00406969     MOV        EDX,dword ptr [this->_padding_]
    //         0040696b     PUSH       0x0
    //         0040696d     PUSH       EAX
    //         0040696e     CALL       dword ptr [EDX + 0x4]
    //                              act_obj.cpp:534 (4)
    //         00406971     TEST       EAX,EAX
    //         00406973     JZ         LAB_00406980
    //                              act_obj.cpp:535 (11)
    //         00406975     MOV        EDX,dword ptr [ESI]
    //         00406977     PUSH       EAX
    //         00406978     MOV        this,ESI
    //         0040697a     CALL       dword ptr [EDX + 0x208]
    //                               LAB_00406980                                                 XREF[2]:     00406952(j), 00406973(j)  
    //                              act_obj.cpp:537 (4)
    //         00406980     POP        ESI
    //         00406981     RET        0x4
}

// Offset: 0x00406990
void setTaskByTaskID(RGE_Action_Object* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Action_Object::setTaskByTaskID(int)                               *
    //                              *********************************************************************************************************
    //                              void __thiscall setTaskByTaskID(RGE_Action_Object * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Obj    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00406990(R)  
    //                               ?setTaskByTaskID@RGE_Action_Object@@UAEXH@Z                  XREF[5]:     0056e620(*), 0056f458(*), 
    //                               RGE_Action_Object::setTaskByTaskID                                        005708f0(*), 00574978(*), 
    //                                                                                                         00574c20(*)  
    //                              act_obj.cpp:542 (16)
    //         00406990     MOV        EAX,dword ptr [ESP + param_1]
    //         00406994     PUSH       ESI
    //         00406995     MOV        ESI,this
    //         00406997     PUSH       EAX
    //         00406998     MOV        this,dword ptr [ESI + 0x8]
    //         0040699b     CALL       RGE_Master_Action_Object::getTaskByTaskID        RGE_Task * getTaskByTaskID(RGE_Master_Action_
    //                              act_obj.cpp:546 (4)
    //         004069a0     TEST       EAX,EAX
    //         004069a2     JZ         LAB_004069d0
    //                              act_obj.cpp:548 (29)
    //         004069a4     MOV        this,dword ptr [ESI + 0x184]
    //         004069aa     PUSH       0xbf800000
    //         004069af     PUSH       0xbf800000
    //         004069b4     PUSH       0xbf800000
    //         004069b9     MOV        EDX,dword ptr [this->_padding_]
    //         004069bb     PUSH       0x0
    //         004069bd     PUSH       EAX
    //         004069be     CALL       dword ptr [EDX + 0x4]
    //                              act_obj.cpp:549 (4)
    //         004069c1     TEST       EAX,EAX
    //         004069c3     JZ         LAB_004069d0
    //                              act_obj.cpp:550 (11)
    //         004069c5     MOV        EDX,dword ptr [ESI]
    //         004069c7     PUSH       EAX
    //         004069c8     MOV        this,ESI
    //         004069ca     CALL       dword ptr [EDX + 0x208]
    //                               LAB_004069d0                                                 XREF[2]:     004069a2(j), 004069c3(j)  
    //                              act_obj.cpp:552 (4)
    //         004069d0     POP        ESI
    //         004069d1     RET        0x4
}

// Offset: 0x004069E0
void set_action(RGE_Action_Object* this_, RGE_Action* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Action_Object::set_action(class RGE_Action *)                     *
    //                              *********************************************************************************************************
    //                              void __thiscall set_action(RGE_Action_Object * this, RGE_Action * pa
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Obj    ECX:4 (auto)   this
    //              RGE_Action *      Stack[0x4]:4   param_1                   XREF[1]:     004069e0(R)  
    //                               ?set_action@RGE_Action_Object@@UAEXPAVRGE_Action@@@Z         XREF[5]:     0056e624(*), 0056f45c(*), 
    //                               RGE_Action_Object::set_action                                             005708f4(*), 0057497c(*), 
    //                                                                                                         00574c24(*)  
    //                              act_obj.cpp:557 (8)
    //         004069e0     MOV        EAX,dword ptr [ESP + param_1]
    //         004069e4     TEST       EAX,EAX
    //         004069e6     JZ         LAB_004069f4
    //                              act_obj.cpp:559 (12)
    //         004069e8     MOV        this,dword ptr [ECX + this->actions]
    //         004069ee     PUSH       EAX
    //         004069ef     CALL       RGE_Action_List::add_action                      void add_action(RGE_Action_List * this, RGE_A
    //                               LAB_004069f4                                                 XREF[1]:     004069e6(j)  
    //                              act_obj.cpp:560 (3)
    //         004069f4     RET        0x4
}

// Offset: 0x00406A00
void set_only_action(RGE_Action_Object* this_, RGE_Action* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Action_Object::set_only_action(class RGE_Action *)                *
    //                              *********************************************************************************************************
    //                              void __thiscall set_only_action(RGE_Action_Object * this, RGE_Action
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Obj    ECX:4 (auto)   this
    //              RGE_Action *      Stack[0x4]:4   param_1                   XREF[1]:     00406a0e(R)  
    //                               ?set_only_action@RGE_Action_Object@@UAEXPAVRGE_Action@@@Z    XREF[5]:     0056e628(*), 0056f460(*), 
    //                               RGE_Action_Object::set_only_action                                        005708f8(*), 00574980(*), 
    //                                                                                                         00574c28(*)  
    //                              act_obj.cpp:565 (3)
    //         00406a00     PUSH       ESI
    //         00406a01     MOV        ESI,this
    //                              act_obj.cpp:571 (11)
    //         00406a03     MOV        this,dword ptr [ESI + 0x184]
    //         00406a09     CALL       RGE_Action_List::delete_list                     void delete_list(RGE_Action_List * this)
    //                              act_obj.cpp:572 (8)
    //         00406a0e     MOV        EAX,dword ptr [ESP + param_1]
    //         00406a12     TEST       EAX,EAX
    //         00406a14     JZ         LAB_00406a22
    //                              act_obj.cpp:573 (12)
    //         00406a16     MOV        this,dword ptr [ESI + 0x184]
    //         00406a1c     PUSH       EAX
    //         00406a1d     CALL       RGE_Action_List::add_action                      void add_action(RGE_Action_List * this, RGE_A
    //                               LAB_00406a22                                                 XREF[1]:     00406a14(j)  
    //                              act_obj.cpp:579 (4)
    //         00406a22     POP        ESI
    //         00406a23     RET        0x4
}

// Offset: 0x00406A30
void set_end_action(RGE_Action_Object* this_, RGE_Action* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Action_Object::set_end_action(class RGE_Action *)                 *
    //                              *********************************************************************************************************
    //                              void __thiscall set_end_action(RGE_Action_Object * this, RGE_Action 
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Obj    ECX:4 (auto)   this
    //              RGE_Action *      Stack[0x4]:4   param_1                   XREF[1]:     00406a30(R)  
    //                               ?set_end_action@RGE_Action_Object@@UAEXPAVRGE_Action@@@Z     XREF[5]:     0056e62c(*), 0056f464(*), 
    //                               RGE_Action_Object::set_end_action                                         005708fc(*), 00574984(*), 
    //                                                                                                         00574c2c(*)  
    //                              act_obj.cpp:584 (8)
    //         00406a30     MOV        EAX,dword ptr [ESP + param_1]
    //         00406a34     TEST       EAX,EAX
    //         00406a36     JZ         LAB_00406a44
    //                              act_obj.cpp:586 (12)
    //         00406a38     MOV        this,dword ptr [ECX + this->actions]
    //         00406a3e     PUSH       EAX
    //         00406a3f     CALL       RGE_Action_List::add_action_at_end               void add_action_at_end(RGE_Action_List * this
    //                               LAB_00406a44                                                 XREF[1]:     00406a36(j)  
    //                              act_obj.cpp:587 (3)
    //         00406a44     RET        0x4
}

// Offset: 0x00406A50
void RGE_Action_Object::stop() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Action_Object::stop(void)                                         *
    //                              *********************************************************************************************************
    //                              void __thiscall stop(RGE_Action_Object * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Obj    ECX:4 (auto)   this
    //                               ?stop@RGE_Action_Object@@UAEXXZ                              XREF[2]:     stop:0042fc53(c), 0056e4c4(*)  
    //                               RGE_Action_Object::stop
    //                              act_obj.cpp:592 (3)
    //         00406a50     PUSH       ESI
    //         00406a51     MOV        ESI,this
    //                              act_obj.cpp:598 (15)
    //         00406a53     MOV        this,dword ptr [ESI + 0x184]
    //         00406a59     CALL       RGE_Action_List::action_stop                     int action_stop(RGE_Action_List * this)
    //         00406a5e     TEST       EAX,EAX
    //         00406a60     JNZ        LAB_00406a6d
    //                              act_obj.cpp:599 (11)
    //         00406a62     MOV        this,dword ptr [ESI + 0x184]
    //         00406a68     CALL       RGE_Action_List::delete_list                     void delete_list(RGE_Action_List * this)
    //                               LAB_00406a6d                                                 XREF[1]:     00406a60(j)  
    //                              act_obj.cpp:605 (2)
    //         00406a6d     POP        ESI
    //         00406a6e     RET
}

// Offset: 0x00406A70
uchar RGE_Action_Object::update() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual unsigned char __thiscall RGE_Action_Object::update(void)                              *
    //                              *********************************************************************************************************
    //                              uchar __thiscall update(RGE_Action_Object * this)
    //              uchar             AL:1           <RETURN>
    //              RGE_Action_Obj    ECX:4 (auto)   this
    //                               ?update@RGE_Action_Object@@UAEEXZ                            XREF[2]:     update:004306d5(c), 0056e444(*)  
    //                               RGE_Action_Object::update
    //                              act_obj.cpp:609 (18)
    //         00406a70     MOV        EAX,[actionFile]                                 = 00000000
    //         00406a75     PUSH       EBX
    //         00406a76     PUSH       ESI
    //         00406a77     PUSH       EDI
    //         00406a78     TEST       EAX,EAX
    //         00406a7a     MOV        ESI,this
    //         00406a7c     JZ         LAB_00406b07
    //                              act_obj.cpp:621 (15)
    //         00406a82     MOV        this,dword ptr [ESI + 0x184]
    //         00406a88     CALL       RGE_Action_List::have_action                     uchar have_action(RGE_Action_List * this)
    //         00406a8d     TEST       AL,AL
    //         00406a8f     JZ         LAB_00406ab8
    //                              act_obj.cpp:623 (18)
    //         00406a91     MOV        this,dword ptr [ESI + 0x184]
    //         00406a97     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
    //         00406a9c     MOV        EDX,dword ptr [EAX]
    //         00406a9e     MOV        this,EAX
    //         00406aa0     CALL       dword ptr [EDX + 0x18]
    //                              act_obj.cpp:624 (19)
    //         00406aa3     MOV        this,dword ptr [ESI + 0x184]
    //         00406aa9     MOVSX      EDI,AX
    //         00406aac     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
    //         00406ab1     XOR        EBX,EBX
    //         00406ab3     MOV        BL,byte ptr [EAX + 0xc]
    //                              act_obj.cpp:626 (2)
    //         00406ab6     JMP        LAB_00406abe
    //                               LAB_00406ab8                                                 XREF[1]:     00406a8f(j)  
    //                              act_obj.cpp:628 (3)
    //         00406ab8     OR         EDI,0xffffffff
    //                              act_obj.cpp:629 (3)
    //         00406abb     OR         EBX,0xffffffff
    //                               LAB_00406abe                                                 XREF[1]:     00406ab6(j)  
    //                              act_obj.cpp:631 (18)
    //         00406abe     MOV        EAX,dword ptr [ESI + 0x18c]
    //         00406ac4     CMP        EAX,EDI
    //         00406ac6     JNZ        LAB_00406ad0
    //         00406ac8     CMP        dword ptr [ESI + 0x190],EBX
    //         00406ace     JZ         LAB_00406b07
    //                               LAB_00406ad0                                                 XREF[1]:     00406ac6(j)  
    //                              act_obj.cpp:634 (43)
    //         00406ad0     MOV        this,dword ptr [ESI + 0x190]
    //         00406ad6     MOV        EDX,dword ptr [ESI + 0x4]
    //         00406ad9     PUSH       EBX
    //         00406ada     PUSH       EDI=>DAT_fffffff8
    //         00406adb     PUSH       this=>DAT_fffffff4
    //         00406adc     PUSH       EAX=>DAT_fffffff0
    //         00406add     MOV        EAX,dword ptr [ESI + 0xc]
    //         00406ae0     PUSH       EDX
    //         00406ae1     MOV        this,dword ptr [EAX + 0x3c]
    //         00406ae4     MOV        EAX,[actionFile]                                 = 00000000
    //         00406ae9     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         00406aec     PUSH       EDX
    //         00406aed     PUSH       s_t%d,_%d,%d,%d,%d,%d_                           = "t%d, %d,%d,%d,%d,%d\n"
    //         00406af2     PUSH       EAX
    //         00406af3     CALL       fprintf                                          undefined fprintf()
    //         00406af8     ADD        ESP,0x20
    //                              act_obj.cpp:635 (6)
    //         00406afb     MOV        dword ptr [ESI + 0x18c],EDI
    //                              act_obj.cpp:636 (6)
    //         00406b01     MOV        dword ptr [ESI + 0x190],EBX
    //                               LAB_00406b07                                                 XREF[2]:     00406a7c(j), 00406ace(j)  
    //                              act_obj.cpp:644 (7)
    //         00406b07     MOV        this,ESI
    //         00406b09     CALL       RGE_Animated_Object::update                      uchar update(RGE_Animated_Object * this)
    //                              act_obj.cpp:651 (22)
    //         00406b0e     MOV        this,dword ptr [ESI + 0x184]
    //         00406b14     MOV        BL,AL
    //         00406b16     MOV        AL,byte ptr [ESI + 0x48]
    //         00406b19     CMP        AL,0x2
    //         00406b1b     JBE        LAB_00406b2f
    //         00406b1d     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         00406b20     TEST       EAX,EAX
    //         00406b22     JZ         LAB_00406b85
    //                              act_obj.cpp:656 (5)
    //         00406b24     CALL       RGE_Action_List::delete_list                     void delete_list(RGE_Action_List * this)
    //                              act_obj.cpp:716 (2)
    //         00406b29     MOV        AL,BL
    //                              act_obj.cpp:717 (4)
    //         00406b2b     POP        EDI
    //         00406b2c     POP        ESI
    //         00406b2d     POP        EBX
    //         00406b2e     RET
    //                               LAB_00406b2f                                                 XREF[1]:     00406b1b(j)  
    //                              act_obj.cpp:661 (7)
    //         00406b2f     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         00406b32     TEST       EDX,EDX
    //         00406b34     JNZ        LAB_00406b5b
    //                              act_obj.cpp:668 (4)
    //         00406b36     CMP        AL,0x2
    //         00406b38     JNZ        LAB_00406b85
    //                              act_obj.cpp:673 (10)
    //         00406b3a     MOV        this,dword ptr [ESI + 0x8]
    //         00406b3d     MOV        AX,word ptr [ECX + this->_padding_]
    //                              act_obj.cpp:674 (6)
    //         00406b44     CMP        AX,0xffff
    //         00406b48     JZ         LAB_00406b85
    //                              act_obj.cpp:679 (11)
    //         00406b4a     MOV        EDX,dword ptr [ESI]
    //         00406b4c     PUSH       EAX
    //         00406b4d     MOV        this,ESI
    //         00406b4f     CALL       dword ptr [EDX + 0x1fc]
    //                              act_obj.cpp:716 (2)
    //         00406b55     MOV        AL,BL
    //                              act_obj.cpp:717 (4)
    //         00406b57     POP        EDI
    //         00406b58     POP        ESI
    //         00406b59     POP        EBX
    //         00406b5a     RET
    //                               LAB_00406b5b                                                 XREF[1]:     00406b34(j)  
    //                              act_obj.cpp:688 (7)
    //         00406b5b     MOV        EAX,dword ptr [ESI + 0x20]
    //         00406b5e     TEST       EAX,EAX
    //         00406b60     JZ         LAB_00406b6d
    //                              act_obj.cpp:693 (5)
    //         00406b62     MOV        EAX,dword ptr [this->_padding_]
    //         00406b64     CALL       dword ptr [EAX + 0x8]
    //                              act_obj.cpp:716 (2)
    //         00406b67     MOV        AL,BL
    //                              act_obj.cpp:717 (4)
    //         00406b69     POP        EDI
    //         00406b6a     POP        ESI
    //         00406b6b     POP        EBX
    //         00406b6c     RET
    //                               LAB_00406b6d                                                 XREF[1]:     00406b60(j)  
    //                              act_obj.cpp:700 (5)
    //         00406b6d     MOV        EDX,dword ptr [this->_padding_]
    //         00406b6f     CALL       dword ptr [EDX + 0xc]
    //                              act_obj.cpp:705 (8)
    //         00406b72     CMP        AL,0x3
    //         00406b74     JZ         LAB_00406b7a
    //         00406b76     CMP        AL,0x1
    //         00406b78     JNZ        LAB_00406b85
    //                               LAB_00406b7a                                                 XREF[1]:     00406b74(j)  
    //                              act_obj.cpp:710 (11)
    //         00406b7a     MOV        this,dword ptr [ESI + 0x184]
    //         00406b80     CALL       RGE_Action_List::remove_action                   void remove_action(RGE_Action_List * this)
    //                               LAB_00406b85                                                 XREF[4]:     00406b22(j), 00406b38(j), 
    //                                                                                                         00406b48(j), 00406b78(j)  
    //                              act_obj.cpp:717 (6)
    //         00406b85     POP        EDI
    //         00406b86     MOV        AL,BL
    //         00406b88     POP        ESI
    //         00406b89     POP        EBX
    //         00406b8a     RET
}

// Offset: 0x00406B90
void RGE_Combat_Object::change_ownership(RGE_Player* param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Action_Object::change_ownership(class RGE_Player *)               *
    //                              *********************************************************************************************************
    //                              void __thiscall change_ownership(RGE_Action_Object * this, RGE_Playe
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Obj    ECX:4 (auto)   this
    //              RGE_Player *      Stack[0x4]:4   param_1
    //                               ?change_ownership@RGE_Action_Object@@UAEXPAVRGE_Player@@@Z   XREF[4]:     change_ownership:004ca8fa(c), 
    //                               RGE_Action_Object::change_ownership                                       0056e464(*), 0056f29c(*), 
    //                                                                                                         00570734(*)  
    //                              act_obj.cpp:721 (4)
    //         00406b90     PUSH       ESI
    //         00406b91     MOV        ESI,this
    //         00406b93     PUSH       EDI
    //                              act_obj.cpp:722 (8)
    //         00406b94     MOV        EDI,dword ptr [ESI]
    //         00406b96     CALL       dword ptr [EDI + 0xa4]
    //                              act_obj.cpp:724 (12)
    //         00406b9c     MOV        EAX,dword ptr [ESP + 0xc]
    //         00406ba0     MOV        this,ESI
    //         00406ba2     PUSH       EAX
    //         00406ba3     CALL       RGE_Static_Object::change_ownership              void change_ownership(RGE_Static_Object * thi
    //                              act_obj.cpp:726 (10)
    //         00406ba8     PUSH       0x0
    //         00406baa     MOV        this,ESI
    //         00406bac     CALL       dword ptr [EDI + 0x208]
    //                              act_obj.cpp:727 (5)
    //         00406bb2     POP        EDI
    //         00406bb3     POP        ESI
    //         00406bb4     RET        0x4
}

// Offset: 0x00406BC0
void RGE_Action_Object::copy_obj(RGE_Master_Static_Object* param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Action_Object::copy_obj(class RGE_Master_Static_Object *)         *
    //                              *********************************************************************************************************
    //                              void __thiscall copy_obj(RGE_Action_Object * this, RGE_Master_Static
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Obj    ECX:4 (auto)   this
    //              RGE_Master_Sta    Stack[0x4]:4   param_1                   XREF[1]:     00406bc4(R)  
    //                               ?copy_obj@RGE_Action_Object@@UAEXPAVRGE_Master_Static_Objec  XREF[2]:     copy_obj:0043083f(c), 0056e478(*)  
    //                               RGE_Action_Object::copy_obj
    //                              act_obj.cpp:731 (4)
    //         00406bc0     PUSH       ESI
    //         00406bc1     MOV        ESI,this
    //         00406bc3     PUSH       EDI
    //                              act_obj.cpp:732 (16)
    //         00406bc4     MOV        EDI,dword ptr [ESP + param_1]
    //         00406bc8     MOV        this,dword ptr [ESI + 0x184]
    //         00406bce     PUSH       EDI
    //         00406bcf     MOV        EAX,dword ptr [this->_padding_]
    //         00406bd1     CALL       dword ptr [EAX + 0x14]
    //                              act_obj.cpp:734 (8)
    //         00406bd4     PUSH       EDI
    //         00406bd5     MOV        this,ESI
    //         00406bd7     CALL       RGE_Moving_Object::copy_obj                      void copy_obj(RGE_Moving_Object * this, RGE_M
    //                              act_obj.cpp:735 (5)
    //         00406bdc     POP        EDI
    //         00406bdd     POP        ESI
    //         00406bde     RET        0x4
}

// Offset: 0x00406BF0
uchar have_action(RGE_Action_Object* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall RGE_Action_Object::have_action(void)                                 *
    //                              *********************************************************************************************************
    //                              uchar __thiscall have_action(RGE_Action_Object * this)
    //              uchar             AL:1           <RETURN>
    //              RGE_Action_Obj    ECX:4 (auto)   this
    //                               ?have_action@RGE_Action_Object@@QAEEXZ                       XREF[5]:     setup_buttons:0049a60e(c), 
    //                               RGE_Action_Object::have_action                                            any_selected_have_action:0049d47a(
    //                                                                                                         taskBoats:004f567f(c), 
    //                                                                                                         handle_idle:0051c641(c), 
    //                                                                                                         save_object_info:0051caf1(c)  
    //                              act_obj.cpp:739 (16)
    //         00406bf0     MOV        this,dword ptr [ECX + this->actions]
    //         00406bf6     CALL       RGE_Action_List::have_action                     uchar have_action(RGE_Action_List * this)
    //         00406bfb     TEST       AL,AL
    //         00406bfd     SETNZ      AL
    //                              act_obj.cpp:744 (1)
    //         00406c00     RET
}

// Offset: 0x00406C10
RGE_Static_Object* TRIBE_Building_Object::get_target_obj() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual class RGE_Static_Object * __thiscall RGE_Action_Object::get_target_obj(void)          *
    //                              *********************************************************************************************************
    //                              RGE_Static_Object * __thiscall get_target_obj(RGE_Action_Object * th
    //              RGE_Static_Obj    EAX:4          <RETURN>
    //              RGE_Action_Obj    ECX:4 (auto)   this
    //                               ?get_target_obj@RGE_Action_Object@@UAEPAVRGE_Static_Object@  XREF[5]:     0056e4ec(*), 0056f324(*), 
    //                               RGE_Action_Object::get_target_obj                                         005707bc(*), 00574844(*), 
    //                                                                                                         00574aec(*)  
    //                              act_obj.cpp:748 (11)
    //         00406c10     MOV        this,dword ptr [ECX + this->actions]
    //         00406c16     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
    //                              act_obj.cpp:752 (4)
    //         00406c1b     TEST       EAX,EAX
    //         00406c1d     JZ         LAB_00406c26
    //                              act_obj.cpp:753 (7)
    //         00406c1f     MOV        EDX,dword ptr [EAX]
    //         00406c21     MOV        this,EAX
    //         00406c23     JMP        dword ptr [EDX + 0x4c]
    //                               LAB_00406c26                                                 XREF[1]:     00406c1d(j)  
    //                              act_obj.cpp:755 (2)
    //         00406c26     XOR        EAX,EAX
    //                              act_obj.cpp:756 (1)
    //         00406c28     RET
}

// Offset: 0x00406C30
RGE_Task* getTask(RGE_Action_Object* this_, RGE_Static_Object* param_2, float param_3, float param_4, float param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual class RGE_Task * __thiscall RGE_Action_Object::getTask(class RGE_Static_Object *,f... *
    //                              *********************************************************************************************************
    //                              RGE_Task * __thiscall getTask(RGE_Action_Object * this, RGE_Static_O
    //              RGE_Task *        EAX:4          <RETURN>
    //              RGE_Action_Obj    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00406c50(R)  
    //              float             Stack[0x8]:4   param_2                   XREF[1]:     00406c49(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[1]:     00406c44(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[1]:     00406c33(R)  
    //                               ?getTask@RGE_Action_Object@@UAEPAVRGE_Task@@PAVRGE_Static_O  XREF[5]:     0056e630(*), 0056f468(*), 
    //                               RGE_Action_Object::getTask                                                00570900(*), 00574988(*), 
    //                                                                                                         00574c30(*)  
    //                              act_obj.cpp:764 (3)
    //         00406c30     PUSH       EBX
    //         00406c31     PUSH       EBP
    //         00406c32     PUSH       ESI
    //                              act_obj.cpp:767 (40)
    //         00406c33     MOV        EBP,dword ptr [ESP + param_4]
    //         00406c37     PUSH       EDI
    //         00406c38     MOV        EDI,this
    //         00406c3a     PUSH       EBP
    //         00406c3b     MOV        EAX,dword ptr [EDI + 0x8]
    //         00406c3e     MOV        this,dword ptr [EAX + 0xd8]
    //         00406c44     MOV        EAX,dword ptr [ESP + param_3]
    //         00406c48     PUSH       EAX
    //         00406c49     MOV        EAX,dword ptr [ESP + param_2]
    //         00406c4d     MOV        EDX,dword ptr [this->_padding_]
    //         00406c4f     PUSH       EAX
    //         00406c50     MOV        EAX,dword ptr [ESP + param_1]
    //         00406c54     PUSH       EAX
    //         00406c55     PUSH       EDI
    //         00406c56     CALL       dword ptr [EDX + 0x4]
    //         00406c59     MOV        EBX,EAX
    //                              act_obj.cpp:769 (8)
    //         00406c5b     TEST       EBX,EBX
    //         00406c5d     JNZ        LAB_00406cf7
    //                              act_obj.cpp:774 (17)
    //         00406c63     MOV        this,dword ptr [EDI + 0x8]
    //         00406c66     MOV        AL,byte ptr [ECX + this->_padding_]
    //         00406c6c     TEST       AL,AL
    //         00406c6e     JZ         LAB_00406cf7
    //                              act_obj.cpp:776 (15)
    //         00406c74     MOV        EAX,dword ptr [EDI + 0xc]
    //         00406c77     XOR        this,this
    //         00406c79     MOV        dword ptr [ESP + 0x20],this
    //         00406c7d     CMP        word ptr [EAX + 0x22],this
    //         00406c81     JLE        LAB_00406cf7
    //                               LAB_00406c83                                                 XREF[1]:     00406ce4(j)  
    //                              act_obj.cpp:778 (6)
    //         00406c83     MOV        EDX,dword ptr [EAX + 0x24]
    //         00406c86     MOV        ESI,dword ptr [EDX + this->_padding_*0x4]
    //                              act_obj.cpp:782 (39)
    //         00406c89     TEST       ESI,ESI
    //         00406c8b     JZ         LAB_00406cd6
    //         00406c8d     MOV        EAX,dword ptr [EDI + 0x8]
    //         00406c90     MOV        DX,word ptr [ESI + 0x14]
    //         00406c94     CMP        DX,word ptr [EAX + 0x14]
    //         00406c98     JNZ        LAB_00406cd6
    //         00406c9a     MOV        DL,byte ptr [ESI + 0x4]
    //         00406c9d     CMP        DL,byte ptr [EAX + 0x4]
    //         00406ca0     JNZ        LAB_00406cd6
    //         00406ca2     MOV        DL,byte ptr [ESI + 0xec]
    //         00406ca8     CMP        DL,byte ptr [EAX + 0xec]
    //         00406cae     JNZ        LAB_00406cd6
    //                              act_obj.cpp:785 (30)
    //         00406cb0     MOV        EDX,dword ptr [ESP + 0x1c]
    //         00406cb4     MOV        this,dword ptr [ESI + 0xd8]
    //         00406cba     PUSH       EBP
    //         00406cbb     PUSH       EDX=>DAT_fffffff8
    //         00406cbc     MOV        EDX,dword ptr [ESP + 0x20]
    //         00406cc0     MOV        EAX,dword ptr [this->_padding_]
    //         00406cc2     PUSH       EDX=>DAT_fffffff4
    //         00406cc3     MOV        EDX,dword ptr [ESP + 0x20]
    //         00406cc7     PUSH       EDX=>DAT_fffffff0
    //         00406cc8     PUSH       EDI
    //         00406cc9     CALL       dword ptr [EAX + 0x4]
    //         00406ccc     MOV        EBX,EAX
    //                              act_obj.cpp:786 (8)
    //         00406cce     TEST       EBX,EBX
    //         00406cd0     JNZ        LAB_00406cef
    //         00406cd2     MOV        this,dword ptr [ESP + 0x20]
    //                               LAB_00406cd6                                                 XREF[4]:     00406c8b(j), 00406c98(j), 
    //                                                                                                         00406ca0(j), 00406cae(j)  
    //                              act_obj.cpp:776 (16)
    //         00406cd6     MOV        EAX,dword ptr [EDI + 0xc]
    //         00406cd9     INC        this
    //         00406cda     MOV        dword ptr [ESP + 0x20],this
    //         00406cde     MOVSX      EDX,word ptr [EAX + 0x22]
    //         00406ce2     CMP        this,EDX
    //         00406ce4     JL         LAB_00406c83
    //                              act_obj.cpp:796 (2)
    //         00406ce6     MOV        EAX,EBX
    //                              act_obj.cpp:797 (7)
    //         00406ce8     POP        EDI
    //         00406ce9     POP        ESI
    //         00406cea     POP        EBP
    //         00406ceb     POP        EBX
    //         00406cec     RET        0x10
    //                               LAB_00406cef                                                 XREF[1]:     00406cd0(j)  
    //                              act_obj.cpp:789 (8)
    //         00406cef     MOV        EAX,dword ptr [EDI]
    //         00406cf1     PUSH       ESI
    //         00406cf2     MOV        this,EDI
    //         00406cf4     CALL       dword ptr [EAX + 0x54]
    //                               LAB_00406cf7                                                 XREF[3]:     00406c5d(j), 00406c6e(j), 
    //                                                                                                         00406c81(j)  
    //                              act_obj.cpp:797 (9)
    //         00406cf7     POP        EDI
    //         00406cf8     POP        ESI
    //         00406cf9     MOV        EAX,EBX
    //         00406cfb     POP        EBP
    //         00406cfc     POP        EBX
    //         00406cfd     RET        0x10
}

// Offset: 0x00406D00
uchar TRIBE_Building_Object::actionState() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual unsigned char __thiscall RGE_Action_Object::actionState(void)const                    *
    //                              *********************************************************************************************************
    //                              uchar __thiscall actionState(RGE_Action_Object * this)
    //              uchar             AL:1           <RETURN>
    //              RGE_Action_Obj    ECX:4 (auto)   this
    //                               ?actionState@RGE_Action_Object@@UBEEXZ                       XREF[5]:     0056e554(*), 0056f38c(*), 
    //                               RGE_Action_Object::actionState                                            00570824(*), 005748ac(*), 
    //                                                                                                         00574b54(*)  
    //                              act_obj.cpp:803 (3)
    //         00406d00     PUSH       ESI
    //         00406d01     MOV        ESI,this
    //                              act_obj.cpp:804 (15)
    //         00406d03     MOV        this,dword ptr [ESI + 0x184]
    //         00406d09     CALL       RGE_Action_List::have_action                     uchar have_action(RGE_Action_List * this)
    //         00406d0e     CMP        AL,0x1
    //         00406d10     JNZ        LAB_00406d22
    //                              act_obj.cpp:805 (14)
    //         00406d12     MOV        this,dword ptr [ESI + 0x184]
    //         00406d18     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
    //         00406d1d     MOV        AL,byte ptr [EAX + 0xc]
    //                              act_obj.cpp:807 (2)
    //         00406d20     POP        ESI
    //         00406d21     RET
    //                               LAB_00406d22                                                 XREF[1]:     00406d10(j)  
    //                              act_obj.cpp:806 (2)
    //         00406d22     XOR        AL,AL
    //                              act_obj.cpp:807 (2)
    //         00406d24     POP        ESI
    //         00406d25     RET
}

// Offset: 0x00406D30
long TRIBE_Building_Object::get_action_checksum() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall RGE_Action_Object::get_action_checksum(void)                          *
    //                              *********************************************************************************************************
    //                              long __thiscall get_action_checksum(RGE_Action_Object * this)
    //              long              EAX:4          <RETURN>
    //              RGE_Action_Obj    ECX:4 (auto)   this
    //                               ?get_action_checksum@RGE_Action_Object@@UAEJXZ               XREF[5]:     0056e5f0(*), 0056f428(*), 
    //                               RGE_Action_Object::get_action_checksum                                    005708c0(*), 00574948(*), 
    //                                                                                                         00574bf0(*)  
    //                              act_obj.cpp:813 (13)
    //         00406d30     MOV        this,dword ptr [ECX + this->actions]
    //         00406d36     PUSH       ESI
    //         00406d37     XOR        ESI,ESI
    //         00406d39     TEST       this,this
    //         00406d3b     JZ         LAB_00406d51
    //                              act_obj.cpp:819 (5)
    //         00406d3d     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
    //                              act_obj.cpp:820 (4)
    //         00406d42     TEST       EAX,EAX
    //         00406d44     JZ         LAB_00406d51
    //                              act_obj.cpp:823 (11)
    //         00406d46     MOVSX      ESI,word ptr [EAX + 0x4]
    //         00406d4a     XOR        this,this
    //         00406d4c     MOV        this,byte ptr [EAX + 0xc]
    //         00406d4f     ADD        ESI,this
    //                               LAB_00406d51                                                 XREF[2]:     00406d3b(j), 00406d44(j)  
    //                              act_obj.cpp:827 (2)
    //         00406d51     MOV        EAX,ESI
    //                              act_obj.cpp:828 (2)
    //         00406d53     POP        ESI
    //         00406d54     RET
}

