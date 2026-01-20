// Auto-generated scaffold unit: misl_obj.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/misl_obj.cpp
#include "../include/common.h"

// Offset: 0x0045A740
undefined RGE_Missile_Object(RGE_Missile_Object* this_, RGE_Master_Combat_Object* param_2, RGE_Player* param_3, float param_4, float param_5, float param_6, int param_7) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Missile_Object::RGE_Missile_Object(class RGE_Master_Combat_Object *,class R... *
    //                              *********************************************************************************************************
    //                              undefined __thiscall RGE_Missile_Object(RGE_Missile_Object * this, R
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Missile_Ob    ECX:4 (auto)   this
    //              RGE_Master_Com    Stack[0x4]:4   param_1                   XREF[2]:     0045a76e(R), 0045a79c(R)  
    //              RGE_Player *      Stack[0x8]:4   param_2                   XREF[2]:     0045a756(R), 0045a798(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[1]:     0045a760(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[1]:     0045a75b(R)  
    //              float             Stack[0x14]:4  param_5                   XREF[1]:     0045a766(R)  
    //              int               Stack[0x18]:4  param_6                   XREF[1]:     0045a782(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0045a786(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0045a7ac(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0045a779(W)  
    //                               ??0RGE_Missile_Object@@QAE@PAVRGE_Master_Combat_Object@@PAV  XREF[1]:     make_new_obj:0045180a(c)  
    //                               RGE_Missile_Object::RGE_Missile_Object
    //                              misl_obj.cpp:31 (66)
    //         0045a740     PUSH       -0x1
    //         0045a742     PUSH       FUN_0055db68
    //         0045a747     MOV        EAX,FS:[0x0]
    //         0045a74d     PUSH       EAX
    //         0045a74e     MOV        dword ptr FS:[0x0],ESP
    //         0045a755     PUSH       this
    //         0045a756     MOV        EAX,dword ptr [ESP + param_2]
    //         0045a75a     PUSH       EBX
    //         0045a75b     MOV        EBX,dword ptr [ESP + param_4]
    //         0045a75f     PUSH       EBP
    //         0045a760     MOV        EBP,dword ptr [ESP + param_3]
    //         0045a764     PUSH       ESI
    //         0045a765     PUSH       EDI
    //         0045a766     MOV        EDI,dword ptr [ESP + param_5]
    //         0045a76a     PUSH       0x0
    //         0045a76c     MOV        ESI,this
    //         0045a76e     MOV        this,dword ptr [ESP + param_1]
    //         0045a772     PUSH       EDI
    //         0045a773     PUSH       EBX
    //         0045a774     PUSH       EBP
    //         0045a775     PUSH       EAX
    //         0045a776     PUSH       this
    //         0045a777     MOV        this,ESI
    //         0045a779     MOV        dword ptr [ESP + local_10],ESI
    //         0045a77d     CALL       RGE_Combat_Object::RGE_Combat_Object             undefined RGE_Combat_Object(RGE_Combat_Object
    //                              misl_obj.cpp:32 (22)
    //         0045a782     MOV        EAX,dword ptr [ESP + param_6]
    //         0045a786     MOV        dword ptr [ESP + local_4],0x0
    //         0045a78e     TEST       EAX,EAX
    //         0045a790     MOV        dword ptr [ESI],RGE_Missile_Object::`vftable'    = 0045a7d0
    //         0045a796     JZ         LAB_0045a7ac
    //                              misl_obj.cpp:33 (20)
    //         0045a798     MOV        EDX,dword ptr [ESP + param_2]
    //         0045a79c     MOV        EAX,dword ptr [ESP + param_1]
    //         0045a7a0     PUSH       EDI
    //         0045a7a1     PUSH       EBX
    //         0045a7a2     PUSH       EBP
    //         0045a7a3     PUSH       EDX
    //         0045a7a4     PUSH       EAX
    //         0045a7a5     MOV        this,ESI
    //         0045a7a7     CALL       RGE_Missile_Object::setup                        int setup(RGE_Missile_Object * this, RGE_Mast
    //                               LAB_0045a7ac                                                 XREF[1]:     0045a796(j)  
    //                              misl_obj.cpp:35 (27)
    //         0045a7ac     MOV        this,dword ptr [ESP + local_c]
    //         0045a7b0     MOV        byte ptr [ESI + 0x4e],0x3c
    //         0045a7b4     MOV        EAX,ESI
    //         0045a7b6     POP        EDI
    //         0045a7b7     POP        ESI
    //         0045a7b8     POP        EBP
    //         0045a7b9     MOV        dword ptr FS:[0x0],this
    //         0045a7c0     POP        EBX
    //         0045a7c1     ADD        ESP,0x10
    //         0045a7c4     RET        0x18
}

// Offset: 0x0045A800
undefined RGE_Missile_Object(RGE_Missile_Object* this_, int param_2, RGE_Game_World* param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Missile_Object::RGE_Missile_Object(int,class RGE_Game_World *,int)             *
    //                              *********************************************************************************************************
    //                              undefined __thiscall RGE_Missile_Object(RGE_Missile_Object * this, i
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Missile_Ob    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0045a817(R)  
    //              RGE_Game_World    Stack[0x8]:4   param_2                   XREF[1]:     0045a81d(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0045a830(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0045a834(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0045a84f(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0045a827(W)  
    //                               ??0RGE_Missile_Object@@QAE@HPAVRGE_Game_World@@H@Z           XREF[1]:     load:00463aac(c)  
    //                               RGE_Missile_Object::RGE_Missile_Object
    //                              misl_obj.cpp:41 (48)
    //         0045a800     PUSH       -0x1
    //         0045a802     PUSH       FUN_0055db88
    //         0045a807     MOV        EAX,FS:[0x0]
    //         0045a80d     PUSH       EAX
    //         0045a80e     MOV        dword ptr FS:[0x0],ESP
    //         0045a815     PUSH       this
    //         0045a816     PUSH       EBX
    //         0045a817     MOV        EBX,dword ptr [ESP + param_1]
    //         0045a81b     PUSH       ESI
    //         0045a81c     PUSH       EDI
    //         0045a81d     MOV        EDI,dword ptr [ESP + param_2]
    //         0045a821     PUSH       0x0
    //         0045a823     MOV        ESI,this
    //         0045a825     PUSH       EDI
    //         0045a826     PUSH       EBX
    //         0045a827     MOV        dword ptr [ESP + local_10],ESI
    //         0045a82b     CALL       RGE_Combat_Object::RGE_Combat_Object             undefined RGE_Combat_Object(RGE_Combat_Object
    //                              misl_obj.cpp:42 (22)
    //         0045a830     MOV        EAX,dword ptr [ESP + param_3]
    //         0045a834     MOV        dword ptr [ESP + local_4],0x0
    //         0045a83c     TEST       EAX,EAX
    //         0045a83e     MOV        dword ptr [ESI],RGE_Missile_Object::`vftable'    = 0045a7d0
    //         0045a844     JZ         LAB_0045a84f
    //                              misl_obj.cpp:43 (9)
    //         0045a846     PUSH       EDI
    //         0045a847     PUSH       EBX
    //         0045a848     MOV        this,ESI
    //         0045a84a     CALL       RGE_Missile_Object::setup                        int setup(RGE_Missile_Object * this, int para
    //                               LAB_0045a84f                                                 XREF[1]:     0045a844(j)  
    //                              misl_obj.cpp:45 (26)
    //         0045a84f     MOV        this,dword ptr [ESP + local_c]
    //         0045a853     MOV        byte ptr [ESI + 0x4e],0x3c
    //         0045a857     MOV        EAX,ESI
    //         0045a859     POP        EDI
    //         0045a85a     POP        ESI
    //         0045a85b     MOV        dword ptr FS:[0x0],this
    //         0045a862     POP        EBX
    //         0045a863     ADD        ESP,0x10
    //         0045a866     RET        0xc
}

// Offset: 0x0045A870
int setup(RGE_Missile_Object* this_, RGE_Master_Combat_Object* param_2, RGE_Player* param_3, float param_4, float param_5, float param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: virtual int __thiscall RGE_Missile_Object::setup(class RGE_Master_Combat_Object *,class... *
    //                              *********************************************************************************************************
    //                              int __thiscall setup(RGE_Missile_Object * this, RGE_Master_Combat_Ob
    //              int               EAX:4          <RETURN>
    //              RGE_Missile_Ob    ECX:4 (auto)   this
    //              RGE_Master_Com    Stack[0x4]:4   param_1                   XREF[1]:     0045a885(R)  
    //              RGE_Player *      Stack[0x8]:4   param_2                   XREF[1]:     0045a880(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[1]:     0045a874(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[1]:     0045a87b(R)  
    //              float             Stack[0x14]:4  param_5                   XREF[1]:     0045a870(R)  
    //                               ?setup@RGE_Missile_Object@@MAEHPAVRGE_Master_Combat_Object@  XREF[2]:     RGE_Missile_Object:0045a7a7(c), 
    //                               RGE_Missile_Object::setup                                                 0057092c(*)  
    //                              misl_obj.cpp:49 (35)
    //         0045a870     MOV        EAX,dword ptr [ESP + param_5]
    //         0045a874     MOV        EDX,dword ptr [ESP + param_3]
    //         0045a878     PUSH       ESI
    //         0045a879     MOV        ESI,this
    //         0045a87b     MOV        this,dword ptr [ESP + param_4]
    //         0045a87f     PUSH       EAX
    //         0045a880     MOV        EAX,dword ptr [ESP + param_2]
    //         0045a884     PUSH       this
    //         0045a885     MOV        this,dword ptr [ESP + param_1]
    //         0045a889     PUSH       EDX
    //         0045a88a     PUSH       EAX
    //         0045a88b     PUSH       this
    //         0045a88c     MOV        this,ESI
    //         0045a88e     CALL       RGE_Combat_Object::setup                         int setup(RGE_Combat_Object * this, RGE_Maste
    //                              misl_obj.cpp:52 (4)
    //         0045a893     MOV        byte ptr [ESI + 0x4e],0x3c
    //                              misl_obj.cpp:54 (5)
    //         0045a897     MOV        EAX,0x1
    //                              misl_obj.cpp:55 (4)
    //         0045a89c     POP        ESI
    //         0045a89d     RET        0x14
}

// Offset: 0x0045A8A0
int RGE_Missile_Object::setup(int param_1, RGE_Game_World* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: virtual int __thiscall RGE_Missile_Object::setup(int,class RGE_Game_World *)               *
    //                              *********************************************************************************************************
    //                              int __thiscall setup(RGE_Missile_Object * this, int param_1, RGE_Gam
    //              int               EAX:4          <RETURN>
    //              RGE_Missile_Ob    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0045a8a6(R)  
    //              RGE_Game_World    Stack[0x8]:4   param_2                   XREF[1]:     0045a8a0(R)  
    //                               ?setup@RGE_Missile_Object@@MAEHHPAVRGE_Game_World@@@Z        XREF[2]:     RGE_Missile_Object:0045a84a(c), 
    //                               RGE_Missile_Object::setup                                                 005708c8(*)  
    //                              misl_obj.cpp:59 (19)
    //         0045a8a0     MOV        EAX,dword ptr [ESP + param_2]
    //         0045a8a4     PUSH       ESI
    //         0045a8a5     PUSH       EDI
    //         0045a8a6     MOV        EDI,dword ptr [ESP + param_1]
    //         0045a8aa     PUSH       EAX
    //         0045a8ab     MOV        ESI,this
    //         0045a8ad     PUSH       EDI
    //         0045a8ae     CALL       RGE_Combat_Object::setup                         int setup(RGE_Combat_Object * this, int param
    //                              misl_obj.cpp:62 (4)
    //         0045a8b3     MOV        byte ptr [ESI + 0x4e],0x3c
    //                              misl_obj.cpp:64 (19)
    //         0045a8b7     FLD        float ptr [save_game_version]                    = 7.23
    //         0045a8bd     FCOMP      float ptr [DAT_00570930]                         = 48h    H
    //         0045a8c3     FNSTSW     AX
    //         0045a8c5     TEST       AH,0x41
    //         0045a8c8     JNZ        LAB_0045a8e6
    //                              misl_obj.cpp:65 (18)
    //         0045a8ca     ADD        ESI,0x1c4
    //         0045a8d0     PUSH       0x4
    //         0045a8d2     PUSH       ESI
    //         0045a8d3     PUSH       EDI
    //         0045a8d4     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0045a8d9     ADD        ESP,0xc
    //                              misl_obj.cpp:69 (5)
    //         0045a8dc     MOV        EAX,0x1
    //                              misl_obj.cpp:70 (5)
    //         0045a8e1     POP        EDI
    //         0045a8e2     POP        ESI
    //         0045a8e3     RET        0x8
    //                               LAB_0045a8e6                                                 XREF[1]:     0045a8c8(j)  
    //                              misl_obj.cpp:67 (3)
    //         0045a8e6     MOV        this,dword ptr [ESI + 0x8]
    //                              misl_obj.cpp:70 (22)
    //         0045a8e9     POP        EDI
    //         0045a8ea     MOV        EAX,0x1
    //         0045a8ef     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0045a8f5     MOV        dword ptr [ESI + 0x1c4],EDX
    //         0045a8fb     POP        ESI
    //         0045a8fc     RET        0x8
}

// Offset: 0x0045A900
void RGE_Missile_Object::rehook() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Missile_Object::rehook(void)                                      *
    //                              *********************************************************************************************************
    //                              void __thiscall rehook(RGE_Missile_Object * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Missile_Ob    ECX:4 (auto)   this
    //                               ?rehook@RGE_Missile_Object@@UAEXXZ                           XREF[1]:     0057071c(*)  
    //                               RGE_Missile_Object::rehook
    //                              misl_obj.cpp:75 (5)
    //         0045a900     JMP        RGE_Action_Object::rehook
}

// Offset: 0x0045A910
void RGE_Missile_Object::save(int param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Missile_Object::save(int)                                         *
    //                              *********************************************************************************************************
    //                              void __thiscall save(RGE_Missile_Object * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Missile_Ob    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0045a912(R)  
    //                               ?save@RGE_Missile_Object@@UAEXH@Z                            XREF[1]:     00570720(*)  
    //                               RGE_Missile_Object::save
    //                              misl_obj.cpp:82 (2)
    //         0045a910     PUSH       ESI
    //         0045a911     PUSH       EDI
    //                              misl_obj.cpp:83 (12)
    //         0045a912     MOV        EDI,dword ptr [ESP + param_1]
    //         0045a916     MOV        ESI,this
    //         0045a918     PUSH       EDI
    //         0045a919     CALL       RGE_Combat_Object::save                          void save(RGE_Combat_Object * this, int param
    //                              misl_obj.cpp:84 (18)
    //         0045a91e     ADD        ESI,0x1c4
    //         0045a924     PUSH       0x4
    //         0045a926     PUSH       ESI
    //         0045a927     PUSH       EDI
    //         0045a928     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0045a92d     ADD        ESP,0xc
    //                              misl_obj.cpp:85 (5)
    //         0045a930     POP        EDI
    //         0045a931     POP        ESI
    //         0045a932     RET        0x4
}

// Offset: 0x0045A940
uchar RGE_Missile_Object::update() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual unsigned char __thiscall RGE_Missile_Object::update(void)                             *
    //                              *********************************************************************************************************
    //                              uchar __thiscall update(RGE_Missile_Object * this)
    //              uchar             AL:1           <RETURN>
    //              RGE_Missile_Ob    ECX:4 (auto)   this
    //                               ?update@RGE_Missile_Object@@UAEEXZ                           XREF[1]:     00570714(*)  
    //                               RGE_Missile_Object::update
    //                              misl_obj.cpp:89 (5)
    //         0045a940     JMP        RGE_Combat_Object::update
}

// Offset: 0x0045A950
void init_missile(RGE_Missile_Object* this_, RGE_Combat_Object* param_2, RGE_Static_Object* param_3, float param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Missile_Object::init_missile(class RGE_Combat_Object *,class RGE_Stati... *
    //                              *********************************************************************************************************
    //                              void __thiscall init_missile(RGE_Missile_Object * this, RGE_Combat_O
    //              void              <VOID>         <RETURN>
    //              RGE_Missile_Ob    ECX:4 (auto)   this
    //              RGE_Combat_Obj    Stack[0x4]:4   param_1                   XREF[1]:     0045a994(R)  
    //              RGE_Static_Obj    Stack[0x8]:4   param_2                   XREF[1]:     0045a983(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[1]:     0045a9bd(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0045a979(W), 0045a9a7(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0045a9c1(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0045a973(W)  
    //                               ?init_missile@RGE_Missile_Object@@QAEXPAVRGE_Combat_Object@  XREF[1]:     attack:00430049(c)  
    //                               RGE_Missile_Object::init_missile
    //                              misl_obj.cpp:100 (25)
    //         0045a950     PUSH       -0x1
    //         0045a952     PUSH       FUN_0055dbab
    //         0045a957     MOV        EAX,FS:[0x0]
    //         0045a95d     PUSH       EAX
    //         0045a95e     MOV        dword ptr FS:[0x0],ESP
    //         0045a965     PUSH       this
    //         0045a966     PUSH       ESI
    //         0045a967     MOV        ESI,this
    //                              misl_obj.cpp:104 (60)
    //         0045a969     PUSH       0x54
    //         0045a96b     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0045a970     ADD        ESP,0x4
    //         0045a973     MOV        dword ptr [ESP + local_10],EAX
    //         0045a977     TEST       EAX,EAX
    //         0045a979     MOV        dword ptr [ESP + local_4],0x0
    //         0045a981     JZ         LAB_0045a9a3
    //         0045a983     MOV        EDX,dword ptr [ESP + param_2]
    //         0045a987     MOV        this,dword ptr [EDX + 0x40]
    //         0045a98a     PUSH       this
    //         0045a98b     MOV        this,dword ptr [EDX + 0x3c]
    //         0045a98e     PUSH       this
    //         0045a98f     MOV        this,dword ptr [EDX + 0x38]
    //         0045a992     PUSH       this
    //         0045a993     PUSH       EDX
    //         0045a994     MOV        EDX,dword ptr [ESP + param_1]
    //         0045a998     MOV        this,EAX
    //         0045a99a     PUSH       EDX
    //         0045a99b     PUSH       ESI
    //         0045a99c     CALL       RGE_Action_Missile::RGE_Action_Missile           undefined RGE_Action_Missile(RGE_Action_Missi
    //         0045a9a1     JMP        LAB_0045a9a5
    //                               LAB_0045a9a3                                                 XREF[1]:     0045a981(j)  
    //         0045a9a3     XOR        EAX,EAX
    //                               LAB_0045a9a5                                                 XREF[1]:     0045a9a1(j)  
    //                              misl_obj.cpp:105 (12)
    //         0045a9a5     TEST       EAX,EAX
    //         0045a9a7     MOV        dword ptr [ESP + local_4],0xffffffff
    //         0045a9af     JZ         LAB_0045a9bd
    //                              misl_obj.cpp:106 (12)
    //         0045a9b1     MOV        this,dword ptr [ESI + 0x184]
    //         0045a9b7     PUSH       EAX
    //         0045a9b8     CALL       RGE_Action_List::add_action                      void add_action(RGE_Action_List * this, RGE_A
    //                               LAB_0045a9bd                                                 XREF[1]:     0045a9af(j)  
    //                              misl_obj.cpp:108 (4)
    //         0045a9bd     MOV        EAX,dword ptr [ESP + param_3]
    //                              misl_obj.cpp:109 (24)
    //         0045a9c1     MOV        this,dword ptr [ESP + local_c]
    //         0045a9c5     MOV        dword ptr [ESI + 0x1c4],EAX
    //         0045a9cb     MOV        dword ptr FS:[0x0],this
    //         0045a9d2     POP        ESI
    //         0045a9d3     ADD        ESP,0x10
    //         0045a9d6     RET        0xc
}

// Offset: 0x0045A9E0
void init_missile(RGE_Missile_Object* this_, RGE_Combat_Object* param_2, float param_3, float param_4, float param_5, float param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Missile_Object::init_missile(class RGE_Combat_Object *,float,float,flo... *
    //                              *********************************************************************************************************
    //                              void __thiscall init_missile(RGE_Missile_Object * this, RGE_Combat_O
    //              void              <VOID>         <RETURN>
    //              RGE_Missile_Ob    ECX:4 (auto)   this
    //              RGE_Combat_Obj    Stack[0x4]:4   param_1                   XREF[1]:     0045aa21(R)  
    //              float             Stack[0x8]:4   param_2                   XREF[1]:     0045aa1c(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[1]:     0045aa17(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[1]:     0045aa13(R)  
    //              float             Stack[0x14]:4  param_5                   XREF[1]:     0045aa4d(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0045aa09(W), 0045aa37(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0045aa51(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0045aa03(W)  
    //                               ?init_missile@RGE_Missile_Object@@QAEXPAVRGE_Combat_Object@  XREF[1]:     attack:004301eb(c)  
    //                               RGE_Missile_Object::init_missile
    //                              misl_obj.cpp:114 (25)
    //         0045a9e0     PUSH       -0x1
    //         0045a9e2     PUSH       FUN_0055dbcb
    //         0045a9e7     MOV        EAX,FS:[0x0]
    //         0045a9ed     PUSH       EAX
    //         0045a9ee     MOV        dword ptr FS:[0x0],ESP
    //         0045a9f5     PUSH       this
    //         0045a9f6     PUSH       ESI
    //         0045a9f7     MOV        ESI,this
    //                              misl_obj.cpp:117 (60)
    //         0045a9f9     PUSH       0x54
    //         0045a9fb     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0045aa00     ADD        ESP,0x4
    //         0045aa03     MOV        dword ptr [ESP + local_10],EAX
    //         0045aa07     TEST       EAX,EAX
    //         0045aa09     MOV        dword ptr [ESP + local_4],0x0
    //         0045aa11     JZ         LAB_0045aa33
    //         0045aa13     MOV        this,dword ptr [ESP + param_4]
    //         0045aa17     MOV        EDX,dword ptr [ESP + param_3]
    //         0045aa1b     PUSH       this
    //         0045aa1c     MOV        this,dword ptr [ESP + param_2]
    //         0045aa20     PUSH       EDX
    //         0045aa21     MOV        EDX,dword ptr [ESP + param_1]
    //         0045aa25     PUSH       this
    //         0045aa26     PUSH       0x0
    //         0045aa28     PUSH       EDX
    //         0045aa29     PUSH       ESI
    //         0045aa2a     MOV        this,EAX
    //         0045aa2c     CALL       RGE_Action_Missile::RGE_Action_Missile           undefined RGE_Action_Missile(RGE_Action_Missi
    //         0045aa31     JMP        LAB_0045aa35
    //                               LAB_0045aa33                                                 XREF[1]:     0045aa11(j)  
    //         0045aa33     XOR        EAX,EAX
    //                               LAB_0045aa35                                                 XREF[1]:     0045aa31(j)  
    //                              misl_obj.cpp:118 (12)
    //         0045aa35     TEST       EAX,EAX
    //         0045aa37     MOV        dword ptr [ESP + local_4],0xffffffff
    //         0045aa3f     JZ         LAB_0045aa4d
    //                              misl_obj.cpp:119 (12)
    //         0045aa41     MOV        this,dword ptr [ESI + 0x184]
    //         0045aa47     PUSH       EAX
    //         0045aa48     CALL       RGE_Action_List::add_action                      void add_action(RGE_Action_List * this, RGE_A
    //                               LAB_0045aa4d                                                 XREF[1]:     0045aa3f(j)  
    //                              misl_obj.cpp:121 (4)
    //         0045aa4d     MOV        EAX,dword ptr [ESP + param_5]
    //                              misl_obj.cpp:122 (24)
    //         0045aa51     MOV        this,dword ptr [ESP + local_c]
    //         0045aa55     MOV        dword ptr [ESI + 0x1c4],EAX
    //         0045aa5b     MOV        dword ptr FS:[0x0],this
    //         0045aa62     POP        ESI
    //         0045aa63     ADD        ESP,0x10
    //         0045aa66     RET        0x14
}

// Offset: 0x0045AA70
uchar missile_move(RGE_Missile_Object* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall RGE_Missile_Object::missile_move(void)                               *
    //                              *********************************************************************************************************
    //                              uchar __thiscall missile_move(RGE_Missile_Object * this)
    //              uchar             AL:1           <RETURN>
    //              RGE_Missile_Ob    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0045aaa5(W), 0045aaeb(R)  
    //              float             Stack[-0x8]:4  new_z                     XREF[3]:     0045aa90(W), 0045aaba(R), 0045aaf6(R)  
    //              float             Stack[-0xc]:4  new_x                     XREF[4]:     0045aa9f(W), 0045aac5(R), 0045aad9(R), 0045aaef(R)  
    //              float             Stack[-0x10]:4 new_y
    //                               ?missile_move@RGE_Missile_Object@@QAEEXZ                     XREF[1]:     update:0040528e(c)  
    //                               RGE_Missile_Object::missile_move
    //                              misl_obj.cpp:126 (6)
    //         0045aa70     SUB        ESP,0xc
    //         0045aa73     PUSH       ESI
    //         0045aa74     MOV        ESI,this
    //                              misl_obj.cpp:129 (9)
    //         0045aa76     FLD        float ptr [ESI + 0x38]
    //         0045aa79     FADD       float ptr [ESI + 0x90]
    //                              misl_obj.cpp:131 (21)
    //         0045aa7f     FLD        float ptr [ESI + 0x98]
    //         0045aa85     FLD        float ptr [ESI + 0x3c]
    //         0045aa88     FADD       float ptr [ESI + 0x94]
    //         0045aa8e     FXCH       ST2
    //         0045aa90     FST        float ptr [ESP + new_z]
    //                              misl_obj.cpp:134 (80)
    //         0045aa94     FCOMP      float ptr [DAT_00570934]
    //         0045aa9a     FADD       float ptr [ESI + 0x40]
    //         0045aa9d     FXCH
    //         0045aa9f     FSTP       float ptr [ESP + new_x]
    //         0045aaa3     FNSTSW     AX
    //         0045aaa5     FSTP       float ptr [ESP + local_4]
    //         0045aaa9     TEST       AH,0x1
    //         0045aaac     JNZ        LAB_0045aae4
    //         0045aaae     MOV        EAX,dword ptr [ESI + 0xc]
    //         0045aab1     MOV        this,dword ptr [EAX + 0x3c]
    //         0045aab4     MOV        this,dword ptr [ECX + this->_padding_]
    //         0045aab7     FILD       dword ptr [ECX + this->_padding_]
    //         0045aaba     FCOMP      float ptr [ESP + new_z]
    //         0045aabe     FNSTSW     AX
    //         0045aac0     TEST       AH,0x41
    //         0045aac3     JNZ        LAB_0045aae4
    //         0045aac5     FLD        float ptr [ESP + new_x]
    //         0045aac9     FCOMP      float ptr [DAT_00570934]
    //         0045aacf     FNSTSW     AX
    //         0045aad1     TEST       AH,0x1
    //         0045aad4     JNZ        LAB_0045aae4
    //         0045aad6     FILD       dword ptr [ECX + this->_padding_]
    //         0045aad9     FCOMP      float ptr [ESP + new_x]
    //         0045aadd     FNSTSW     AX
    //         0045aadf     TEST       AH,0x41
    //         0045aae2     JZ         LAB_0045aaeb
    //                               LAB_0045aae4                                                 XREF[3]:     0045aaac(j), 0045aac3(j), 
    //                                                                                                         0045aad4(j)  
    //                              misl_obj.cpp:135 (7)
    //         0045aae4     MOV        EDX,dword ptr [ESI]
    //         0045aae6     MOV        this,ESI
    //         0045aae8     CALL       dword ptr [EDX + 0x6c]
    //                               LAB_0045aaeb                                                 XREF[1]:     0045aae2(j)  
    //                              misl_obj.cpp:138 (22)
    //         0045aaeb     MOV        this,dword ptr [ESP + local_4]
    //         0045aaef     MOV        EDX,dword ptr [ESP + new_x]
    //         0045aaf3     MOV        EAX,dword ptr [ESI]
    //         0045aaf5     PUSH       this
    //         0045aaf6     MOV        this,dword ptr [ESP + new_z]
    //         0045aafa     PUSH       EDX=>DAT_fffffff8
    //         0045aafb     PUSH       this=>DAT_fffffff4
    //         0045aafc     MOV        this,ESI
    //         0045aafe     CALL       dword ptr [EAX + 0x34]
    //                              misl_obj.cpp:141 (15)
    //         0045ab01     FCOMP      float ptr [ESI + 0x40]
    //         0045ab04     FNSTSW     AX
    //         0045ab06     TEST       AH,0x40
    //         0045ab09     JZ         LAB_0045ab15
    //         0045ab0b     MOV        EAX,0x1
    //                              misl_obj.cpp:142 (5)
    //         0045ab10     POP        ESI
    //         0045ab11     ADD        ESP,0xc
    //         0045ab14     RET
    //                               LAB_0045ab15                                                 XREF[1]:     0045ab09(j)  
    //                              misl_obj.cpp:141 (2)
    //         0045ab15     XOR        EAX,EAX
    //                              misl_obj.cpp:142 (5)
    //         0045ab17     POP        ESI
    //         0045ab18     ADD        ESP,0xc
    //         0045ab1b     RET
}

// Offset: 0x0045AB20
RGE_Check_List* make_object_collision_list(RGE_Missile_Object* this_, float param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: class RGE_Check_List * __thiscall RGE_Missile_Object::make_object_collision_list(float)       *
    //                              *********************************************************************************************************
    //                              RGE_Check_List * __thiscall make_object_collision_list(RGE_Missile_O
    //              RGE_Check_List    EAX:4          <RETURN>
    //              RGE_Missile_Ob    ECX:4 (auto)   this
    //              float             Stack[0x4]:4   param_1                   XREF[2]:     0045ad67(R), 0045ad6d(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0045abda(W), 0045abfa(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0045ae2d(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[3]:     0045abd2(W), 0045ac61(W), 0045adde(R)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[2]:     0045ad79(W), 0045adab(R)  
    //              float             Stack[-0x18]:4 dx                        XREF[2]:     0045ab47(W), 0045ad59(R)  
    //              float             Stack[-0x1c]:4 rx                        XREF[2]:     0045ac4d(W), 0045ac8c(R)  
    //              undefined4        Stack[-0x20]:4 local_20                  XREF[3]:     0045ac02(W), 0045ae1d(W), 0045ae25(R)  
    //              RGE_Check_List    Stack[-0x24]:4 check_list                XREF[3]:     0045ac69(W), 0045ade6(R), 0045adf2(W)  
    //              undefined4        Stack[-0x28]:4 local_28                  XREF[3]:     0045abc6(W), 0045ac13(R), 0045adda(R)  
    //              RGE_Map *         Stack[-0x2c]:4 map                       XREF[3]:     0045ad89(W), 0045ad96(R), 0045ada7(R)  
    //              float             Stack[-0x30]:4 dy                        XREF[3]:     0045ab51(W), 0045ab60(R), 0045ad61(R)  
    //              float             Stack[-0x34]:4 ry                        XREF[3]:     0045acb1(W), 0045acb8(R), 0045ad5d(R)  
    //              float             Stack[-0x38]:4 ry2                       XREF[3]:     0045acc2(W), 0045acd1(R), 0045ad55(R)  
    //              float             Stack[-0x3c]:4 rx2                       XREF[4]:     0045ac65(W), 0045ac73(R), 0045ade2(R), 0045adee(W)  
    //              undefined4        Stack[-0x40]:4 local_40                  XREF[3]:     0045ab8e(W), 0045ac08(W), 0045add6(R)  
    //              short             Stack[-0x44]:2 x1                        XREF[5]:     0045abb0(W), 0045ac0e(R), 0045ac22(W), 0045ac7c(R), 
    //                                                                                     0045ac87(R)  
    //              short             Stack[-0x48]:2 x2                        XREF[6]:     0045abe7(W), 0045abef(W), 0045abf3(R), 0045adb4(R), 
    //                                                                                     0045adfc(R), 0045ae10(R)  
    //                               ?make_object_collision_list@RGE_Missile_Object@@QAEPAVRGE_C  XREF[1]:     update:0040530b(c)  
    //                               RGE_Missile_Object::make_object_collision_list
    //                              misl_obj.cpp:148 (30)
    //         0045ab20     PUSH       -0x1
    //         0045ab22     PUSH       FUN_0055dbeb
    //         0045ab27     MOV        EAX,FS:[0x0]
    //         0045ab2d     PUSH       EAX
    //         0045ab2e     MOV        dword ptr FS:[0x0],ESP
    //         0045ab35     SUB        ESP,0x3c
    //         0045ab38     PUSH       EBX
    //         0045ab39     PUSH       EBP
    //         0045ab3a     PUSH       ESI
    //         0045ab3b     PUSH       EDI
    //         0045ab3c     MOV        EDI,this
    //                              misl_obj.cpp:158 (6)
    //         0045ab3e     MOV        EAX,dword ptr [EDI + 0x8]
    //         0045ab41     FLD        float ptr [EAX + 0x30]
    //                              misl_obj.cpp:159 (7)
    //         0045ab44     MOV        EAX,dword ptr [EAX + 0x34]
    //         0045ab47     FST        float ptr [ESP + dx]
    //                              misl_obj.cpp:169 (42)
    //         0045ab4b     FCOMP      float ptr [DAT_00570934]
    //         0045ab51     MOV        dword ptr [ESP + dy],EAX
    //         0045ab55     FNSTSW     AX
    //         0045ab57     TEST       AH,0x41
    //         0045ab5a     JNZ        LAB_0045ae2b
    //         0045ab60     FLD        float ptr [ESP + dy]
    //         0045ab64     FCOMP      float ptr [DAT_00570934]
    //         0045ab6a     FNSTSW     AX
    //         0045ab6c     TEST       AH,0x41
    //         0045ab6f     JNZ        LAB_0045ae2b
    //                              misl_obj.cpp:173 (14)
    //         0045ab75     FLD        float ptr [EDI + 0x38]
    //         0045ab78     FSUB       float ptr [DAT_00570938]
    //         0045ab7e     CALL       __ftol                                           undefined __ftol()
    //                              misl_obj.cpp:174 (20)
    //         0045ab83     FLD        float ptr [EDI + 0x3c]
    //         0045ab86     FSUB       float ptr [DAT_00570938]
    //         0045ab8c     MOV        EBP,EAX
    //         0045ab8e     MOV        dword ptr [ESP + local_40],EBP
    //         0045ab92     CALL       __ftol                                           undefined __ftol()
    //                              misl_obj.cpp:175 (16)
    //         0045ab97     FLD        float ptr [EDI + 0x38]
    //         0045ab9a     FSUB       float ptr [DAT_0057093c]
    //         0045aba0     MOV        EBX,EAX
    //         0045aba2     CALL       __ftol                                           undefined __ftol()
    //                              misl_obj.cpp:176 (18)
    //         0045aba7     FLD        float ptr [EDI + 0x3c]
    //         0045abaa     FSUB       float ptr [DAT_0057093c]
    //         0045abb0     MOV        dword ptr [ESP + x1],EAX
    //         0045abb4     CALL       __ftol                                           undefined __ftol()
    //                              misl_obj.cpp:177 (5)
    //         0045abb9     MOV        this,dword ptr [EDI + 0xc]
    //         0045abbc     MOV        ESI,EAX
    //                              misl_obj.cpp:178 (57)
    //         0045abbe     PUSH       0x4
    //         0045abc0     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0045abc3     MOV        EAX,dword ptr [EDX + 0x28]
    //         0045abc6     MOV        dword ptr [ESP + local_28],EAX
    //         0045abca     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0045abcf     ADD        ESP,0x4
    //         0045abd2     MOV        dword ptr [ESP + local_10],EAX
    //         0045abd6     XOR        this,this
    //         0045abd8     CMP        EAX,this
    //         0045abda     MOV        dword ptr [ESP + local_4],this
    //         0045abde     JZ         LAB_0045abef
    //         0045abe0     MOV        this,EAX
    //         0045abe2     CALL       RGE_Check_List::RGE_Check_List                   undefined RGE_Check_List(RGE_Check_List * this)
    //         0045abe7     MOV        dword ptr [ESP + x2],EAX
    //         0045abeb     XOR        this,this
    //         0045abed     JMP        LAB_0045abf3
    //                               LAB_0045abef                                                 XREF[1]:     0045abde(j)  
    //         0045abef     MOV        dword ptr [ESP + x2],this
    //                               LAB_0045abf3                                                 XREF[1]:     0045abed(j)  
    //         0045abf3     MOV        EDX,dword ptr [ESP + x2]
    //                              misl_obj.cpp:181 (23)
    //         0045abf7     CMP        BP,this
    //         0045abfa     MOV        dword ptr [ESP + local_4],0xffffffff
    //         0045ac02     MOV        dword ptr [ESP + local_20],EDX
    //         0045ac06     JGE        LAB_0045ac0e
    //         0045ac08     MOV        dword ptr [ESP + local_40],this
    //         0045ac0c     MOV        EBP,this
    //                               LAB_0045ac0e                                                 XREF[1]:     0045ac06(j)  
    //                              misl_obj.cpp:182 (24)
    //         0045ac0e     MOVSX      EAX,word ptr [ESP + x1]
    //         0045ac13     MOV        this,dword ptr [ESP + local_28]
    //         0045ac17     CMP        EAX,dword ptr [ECX + this->_padding_]
    //         0045ac1a     JL         LAB_0045ac26
    //         0045ac1c     MOV        AX,word ptr [ECX + this->_padding_]
    //         0045ac20     DEC        AX
    //         0045ac22     MOV        dword ptr [ESP + x1],EAX
    //                               LAB_0045ac26                                                 XREF[1]:     0045ac1a(j)  
    //                              misl_obj.cpp:183 (7)
    //         0045ac26     TEST       BX,BX
    //         0045ac29     JGE        LAB_0045ac2d
    //         0045ac2b     XOR        EBX,EBX
    //                               LAB_0045ac2d                                                 XREF[1]:     0045ac29(j)  
    //                              misl_obj.cpp:184 (14)
    //         0045ac2d     MOVSX      EAX,SI
    //         0045ac30     CMP        EAX,dword ptr [ECX + this->_padding_]
    //         0045ac33     JL         LAB_0045ac3b
    //         0045ac35     MOV        SI,word ptr [ECX + this->_padding_]
    //         0045ac39     DEC        SI
    //                               LAB_0045ac3b                                                 XREF[1]:     0045ac33(j)  
    //                              misl_obj.cpp:187 (9)
    //         0045ac3b     CMP        BX,SI
    //         0045ac3e     JG         LAB_0045ae00
    //                              misl_obj.cpp:189 (56)
    //         0045ac44     MOVSX      EDX,BP
    //         0045ac47     MOVSX      EAX,BX
    //         0045ac4a     MOVSX      ESI,SI
    //         0045ac4d     MOV        dword ptr [ESP + rx],EDX
    //         0045ac51     LEA        EDX,[EDX + EDX*0x2]
    //         0045ac54     SUB        ESI,EAX
    //         0045ac56     LEA        EBX,[EAX*0x4 + 0x0]
    //         0045ac5d     SHL        EDX,0x3
    //         0045ac60     INC        ESI
    //         0045ac61     MOV        dword ptr [ESP + local_10],EDX
    //         0045ac65     MOV        dword ptr [ESP + rx2],EBX
    //         0045ac69     MOV        dword ptr [ESP + check_list],ESI
    //                               LAB_0045ac6d                                                 XREF[1]:     0045adf6(j)  
    //         0045ac6d     MOV        EAX,dword ptr [this->_padding_ + 0x8d8c]
    //         0045ac73     MOV        ESI,dword ptr [ESP + rx2]
    //         0045ac77     MOV        EAX,dword ptr [ESI + EAX*0x1]
    //         0045ac7a     ADD        EAX,EDX
    //                              misl_obj.cpp:190 (26)
    //         0045ac7c     CMP        BP,word ptr [ESP + x1]
    //         0045ac81     JG         LAB_0045ade2
    //         0045ac87     MOVSX      EBX,word ptr [ESP + x1]
    //         0045ac8c     MOV        this,dword ptr [ESP + rx]
    //         0045ac90     LEA        EBP,[EAX + 0x10]
    //         0045ac93     SUB        EBX,this
    //         0045ac95     INC        EBX
    //                               LAB_0045ac96                                                 XREF[1]:     0045add0(j)  
    //                              misl_obj.cpp:191 (11)
    //         0045ac96     MOV        ESI,dword ptr [EBP]
    //         0045ac99     TEST       ESI,ESI
    //         0045ac9b     JZ         LAB_0045adcc
    //                               LAB_0045aca1                                                 XREF[1]:     0045adc6(j)  
    //                              misl_obj.cpp:193 (2)
    //         0045aca1     MOV        this,dword ptr [ESI]
    //                              misl_obj.cpp:195 (8)
    //         0045aca3     CMP        this,EDI
    //         0045aca5     JZ         LAB_0045adc1
    //                              misl_obj.cpp:197 (3)
    //         0045acab     MOV        EDX,dword ptr [ECX + this->_padding_]
    //                              misl_obj.cpp:198 (7)
    //         0045acae     MOV        EAX,dword ptr [EDX + 0x34]
    //         0045acb1     MOV        dword ptr [ESP + ry],EAX
    //                              misl_obj.cpp:201 (49)
    //         0045acb5     MOV        EAX,dword ptr [EDX + 0x30]
    //         0045acb8     FLD        float ptr [ESP + ry]
    //         0045acbc     FCOMP      float ptr [DAT_00570934]
    //         0045acc2     MOV        dword ptr [ESP + ry2],EAX
    //         0045acc6     FNSTSW     AX
    //         0045acc8     TEST       AH,0x41
    //         0045accb     JNZ        LAB_0045adc1
    //         0045acd1     FLD        float ptr [ESP + ry2]
    //         0045acd5     FCOMP      float ptr [DAT_00570934]
    //         0045acdb     FNSTSW     AX
    //         0045acdd     TEST       AH,0x41
    //         0045ace0     JNZ        LAB_0045adc1
    //                              misl_obj.cpp:203 (6)
    //         0045ace6     FLD        float ptr [ECX + this->_padding_]
    //         0045ace9     FSUB       float ptr [EDI + 0x40]
    //                              misl_obj.cpp:206 (57)
    //         0045acec     FLD        float ptr [EDX + 0x38]
    //         0045acef     FSUB       float ptr [DAT_00570940]                         = CDh
    //         0045acf5     FLD        ST1
    //         0045acf7     FXCH
    //         0045acf9     FCHS
    //         0045acfb     FXCH
    //         0045acfd     FCOMPP
    //         0045acff     FNSTSW     AX
    //         0045ad01     TEST       AH,0x1
    //         0045ad04     JNZ        LAB_0045adbf
    //         0045ad0a     MOV        EDX,dword ptr [EDI + 0x8]
    //         0045ad0d     FLD        float ptr [EDX + 0x38]
    //         0045ad10     FSUB       float ptr [DAT_00570940]                         = CDh
    //         0045ad16     FXCH
    //         0045ad18     FCOMPP
    //         0045ad1a     FNSTSW     AX
    //         0045ad1c     TEST       AH,0x41
    //         0045ad1f     JZ         LAB_0045adc1
    //                              misl_obj.cpp:208 (6)
    //         0045ad25     FLD        float ptr [ECX + this->_padding_]
    //         0045ad28     FSUB       float ptr [EDI + 0x38]
    //                              misl_obj.cpp:209 (6)
    //         0045ad2b     FLD        float ptr [ECX + this->_padding_]
    //         0045ad2e     FSUB       float ptr [EDI + 0x3c]
    //                              misl_obj.cpp:211 (21)
    //         0045ad31     FLD        ST1
    //         0045ad33     FCOMP      float ptr [DAT_00570934]
    //         0045ad39     FNSTSW     AX
    //         0045ad3b     TEST       AH,0x1
    //         0045ad3e     JZ         LAB_0045ad46
    //         0045ad40     FXCH
    //         0045ad42     FCHS
    //         0045ad44     FXCH
    //                               LAB_0045ad46                                                 XREF[1]:     0045ad3e(j)  
    //                              misl_obj.cpp:212 (15)
    //         0045ad46     FCOM       float ptr [DAT_00570934]
    //         0045ad4c     FNSTSW     AX
    //         0045ad4e     TEST       AH,0x1
    //         0045ad51     JZ         LAB_0045ad55
    //         0045ad53     FCHS
    //                               LAB_0045ad55                                                 XREF[1]:     0045ad51(j)  
    //                              misl_obj.cpp:216 (8)
    //         0045ad55     FLD        float ptr [ESP + ry2]
    //         0045ad59     FADD       float ptr [ESP + dx]
    //                              misl_obj.cpp:217 (34)
    //         0045ad5d     FLD        float ptr [ESP + ry]
    //         0045ad61     FADD       float ptr [ESP + dy]
    //         0045ad65     FXCH
    //         0045ad67     FADD       float ptr [ESP + param_1]
    //         0045ad6b     FXCH
    //         0045ad6d     FADD       float ptr [ESP + param_1]
    //         0045ad71     FXCH
    //         0045ad73     FSUBP      ST3,ST0
    //         0045ad75     FSUBR      ST0,ST1
    //         0045ad77     FXCH       ST2
    //         0045ad79     FST        float ptr [ESP + local_14]
    //         0045ad7d     FXCH       ST2
    //                              misl_obj.cpp:221 (40)
    //         0045ad7f     FXCH       ST2
    //         0045ad81     FCOMP      float ptr [DAT_00570934]
    //         0045ad87     FXCH
    //         0045ad89     FSTP       float ptr [ESP + map]
    //         0045ad8d     FSTP       ST0
    //         0045ad8f     FNSTSW     AX
    //         0045ad91     TEST       AH,0x41
    //         0045ad94     JZ         LAB_0045adc1
    //         0045ad96     FLD        float ptr [ESP + map]
    //         0045ad9a     FCOMP      float ptr [DAT_00570934]
    //         0045ada0     FNSTSW     AX
    //         0045ada2     TEST       AH,0x41
    //         0045ada5     JZ         LAB_0045adc1
    //                              misl_obj.cpp:222 (24)
    //         0045ada7     MOV        EAX,dword ptr [ESP + map]
    //         0045adab     MOV        EDX,dword ptr [ESP + local_14]
    //         0045adaf     PUSH       0x0
    //         0045adb1     PUSH       EAX
    //         0045adb2     PUSH       EDX
    //         0045adb3     PUSH       this
    //         0045adb4     MOV        this,dword ptr [ESP + x2]
    //         0045adb8     CALL       RGE_Check_List::add_node                         void add_node(RGE_Check_List * this, RGE_Stat
    //         0045adbd     JMP        LAB_0045adc1
    //                               LAB_0045adbf                                                 XREF[1]:     0045ad04(j)  
    //                              misl_obj.cpp:206 (2)
    //         0045adbf     FSTP       ST0
    //                               LAB_0045adc1                                                 XREF[7]:     0045aca5(j), 0045accb(j), 
    //                                                                                                         0045ace0(j), 0045ad1f(j), 
    //                                                                                                         0045ad94(j), 0045ada5(j), 
    //                                                                                                         0045adbd(j)  
    //                              misl_obj.cpp:191 (11)
    //         0045adc1     MOV        ESI,dword ptr [ESI + 0x4]
    //         0045adc4     TEST       ESI,ESI
    //         0045adc6     JNZ        LAB_0045aca1
    //                               LAB_0045adcc                                                 XREF[1]:     0045ac9b(j)  
    //                              misl_obj.cpp:190 (48)
    //         0045adcc     ADD        EBP,0x18
    //         0045adcf     DEC        EBX
    //         0045add0     JNZ        LAB_0045ac96
    //         0045add6     MOV        EBP,dword ptr [ESP + local_40]
    //         0045adda     MOV        this,dword ptr [ESP + local_28]
    //         0045adde     MOV        EDX,dword ptr [ESP + local_10]
    //                               LAB_0045ade2                                                 XREF[1]:     0045ac81(j)  
    //         0045ade2     MOV        ESI,dword ptr [ESP + rx2]
    //         0045ade6     MOV        EAX,dword ptr [ESP + check_list]
    //         0045adea     ADD        ESI,0x4
    //         0045aded     DEC        EAX
    //         0045adee     MOV        dword ptr [ESP + rx2],ESI
    //         0045adf2     MOV        dword ptr [ESP + check_list],EAX
    //         0045adf6     JNZ        LAB_0045ac6d
    //                              misl_obj.cpp:187 (4)
    //         0045adfc     MOV        EDX,dword ptr [ESP + x2]
    //                               LAB_0045ae00                                                 XREF[1]:     0045ac3e(j)  
    //                              misl_obj.cpp:229 (5)
    //         0045ae00     CMP        dword ptr [EDX],0x0
    //         0045ae03     JNZ        LAB_0045ae25
    //                              misl_obj.cpp:231 (24)
    //         0045ae05     TEST       EDX,EDX
    //         0045ae07     JZ         LAB_0045ae1d
    //         0045ae09     MOV        this,EDX
    //         0045ae0b     CALL       RGE_Check_List::~RGE_Check_List                  void ~RGE_Check_List(RGE_Check_List * this)
    //         0045ae10     MOV        EAX,dword ptr [ESP + x2]
    //         0045ae14     PUSH       EAX
    //         0045ae15     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0045ae1a     ADD        ESP,0x4
    //                               LAB_0045ae1d                                                 XREF[1]:     0045ae07(j)  
    //                              misl_obj.cpp:232 (8)
    //         0045ae1d     MOV        dword ptr [ESP + local_20],0x0
    //                               LAB_0045ae25                                                 XREF[1]:     0045ae03(j)  
    //                              misl_obj.cpp:235 (6)
    //         0045ae25     MOV        EAX,dword ptr [ESP + local_20]
    //         0045ae29     JMP        LAB_0045ae2d
    //                               LAB_0045ae2b                                                 XREF[2]:     0045ab5a(j), 0045ab6f(j)  
    //                              misl_obj.cpp:170 (2)
    //         0045ae2b     XOR        EAX,EAX
    //                               LAB_0045ae2d                                                 XREF[1]:     0045ae29(j)  
    //                              misl_obj.cpp:236 (21)
    //         0045ae2d     MOV        this,dword ptr [ESP + local_c]
    //         0045ae31     POP        EDI
    //         0045ae32     POP        ESI
    //         0045ae33     POP        EBP
    //         0045ae34     MOV        dword ptr FS:[0x0],this
    //         0045ae3b     POP        EBX
    //         0045ae3c     ADD        ESP,0x48
    //         0045ae3f     RET        0x4
}

