// Auto-generated scaffold unit: tmplayer.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/tmplayer.cpp
#include "../include/common.h"

// Offset: 0x005117C0
undefined TRIBE_Master_Player(TRIBE_Master_Player* this_, FILE* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TRIBE_Master_Player::TRIBE_Master_Player(struct _iobuf *)                          *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TRIBE_Master_Player(TRIBE_Master_Player * this,
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TRIBE_Master_P    ECX:4 (auto)   this
    //              _iobuf *          Stack[0x4]:4   param_1                   XREF[1]:     005117c0(R)  
    //                               ??0TRIBE_Master_Player@@QAE@PAU_iobuf@@@Z                    XREF[1]:     data_load_players_type:0052e287(c)
    //                               TRIBE_Master_Player::TRIBE_Master_Player
    //                              tmplayer.cpp:23 (19)
    //         005117c0     MOV        EAX,dword ptr [ESP + param_1]
    //         005117c4     PUSH       ESI
    //         005117c5     MOV        ESI,this
    //         005117c7     PUSH       EAX
    //         005117c8     CALL       RGE_Master_Player::RGE_Master_Player             undefined RGE_Master_Player(RGE_Master_Player
    //         005117cd     MOV        dword ptr [ESI],TRIBE_Master_Player::`vftable'   = 005117e0
    //                              tmplayer.cpp:24 (4)
    //         005117d3     MOV        byte ptr [ESI + 0x29],0x1
    //                              tmplayer.cpp:25 (6)
    //         005117d7     MOV        EAX,ESI
    //         005117d9     POP        ESI
    //         005117da     RET        0x4
}

// Offset: 0x00511800
undefined TRIBE_Master_Player(TRIBE_Master_Player* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TRIBE_Master_Player::TRIBE_Master_Player(int)                                      *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TRIBE_Master_Player(TRIBE_Master_Player * this,
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TRIBE_Master_P    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00511800(R)  
    //                               ??0TRIBE_Master_Player@@QAE@H@Z                              XREF[1]:     init_player_type:0052e46c(c)  
    //                               TRIBE_Master_Player::TRIBE_Master_Player
    //                              tmplayer.cpp:30 (19)
    //         00511800     MOV        EAX,dword ptr [ESP + param_1]
    //         00511804     PUSH       ESI
    //         00511805     MOV        ESI,this
    //         00511807     PUSH       EAX
    //         00511808     CALL       RGE_Master_Player::RGE_Master_Player             undefined RGE_Master_Player(RGE_Master_Player
    //         0051180d     MOV        dword ptr [ESI],TRIBE_Master_Player::`vftable'   = 005117e0
    //                              tmplayer.cpp:31 (4)
    //         00511813     MOV        byte ptr [ESI + 0x29],0x1
    //                              tmplayer.cpp:32 (6)
    //         00511817     MOV        EAX,ESI
    //         00511819     POP        ESI
    //         0051181a     RET        0x4
}

// Offset: 0x00511820
void TRIBE_Master_Player(TRIBE_Master_Player* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall TRIBE_Master_Player::~TRIBE_Master_Player(void)                            *
    //                              *********************************************************************************************************
    //                              void __thiscall ~TRIBE_Master_Player(TRIBE_Master_Player * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Master_P    ECX:4 (auto)   this
    //                               ??1TRIBE_Master_Player@@UAE@XZ                               XREF[1]:     `scalar_deleting_destructor':00511
    //                               TRIBE_Master_Player::~TRIBE_Master_Player
    //                              tmplayer.cpp:36 (11)
    //         00511820     MOV        dword ptr [this->field0_0x0],TRIBE_Master_Play   = 005117e0
    //         00511826     JMP        RGE_Master_Player::~RGE_Master_Player            void ~RGE_Master_Player(RGE_Master_Player * t
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x00511830
void TRIBE_Master_Player::load_master_object(int param_1, uchar param_2, RGE_Sprite** param_3, RGE_Sound** param_4, short param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall TRIBE_Master_Player::load_master_object(int,unsigned char,class RG... *
    //                              *********************************************************************************************************
    //                              void __thiscall load_master_object(TRIBE_Master_Player * this, int p
    //              void              <VOID>         <RETURN>
    //              TRIBE_Master_P    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[4]:     0051186a(R), 005118b6(R), 005118f0(R), 00511961(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[4]:     0051183e(R), 00511897(W), 005118d5(W), 00511946(W)  
    //              RGE_Sprite * *    Stack[0xc]:4   param_3                   XREF[4]:     00511865(R), 005118af(R), 005118e9(R), 0051195a(R)  
    //              RGE_Sound * *     Stack[0x10]:4  param_4                   XREF[4]:     00511860(R), 005118ab(R), 005118e5(R), 00511956(R)  
    //              short             Stack[0x14]:2  param_5                   XREF[4]:     0051185c(R), 005118fd(R), 0051191a(R), 00511972(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0051189d(W), 005118db(W), 0051194c(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[4]:     00511878(R), 00511908(R), 00511927(R), 0051197e(*)  
    //                               ?load_master_object@TRIBE_Master_Player@@UAEXHEPAPAVRGE_Spr  XREF[1]:     00576808(*)  
    //                               TRIBE_Master_Player::load_master_object
    //                              tmplayer.cpp:41 (14)
    //         00511830     MOV        EAX,FS:[0x0]
    //         00511836     PUSH       -0x1
    //         00511838     PUSH       FUN_005610c1
    //         0051183d     PUSH       EAX
    //                              tmplayer.cpp:42 (30)
    //         0051183e     MOV        EAX,dword ptr [ESP + param_2]
    //         00511842     MOV        dword ptr FS:[0x0],ESP
    //         00511849     PUSH       ESI
    //         0051184a     CMP        AL,0x46
    //         0051184c     MOV        ESI,this
    //         0051184e     JZ         LAB_00511939
    //         00511854     CMP        AL,0x50
    //         00511856     JZ         LAB_005118c8
    //         00511858     CMP        AL,0x5a
    //         0051185a     JZ         LAB_0051188a
    //                              tmplayer.cpp:54 (28)
    //         0051185c     MOV        this,dword ptr [ESP + param_5]
    //         00511860     MOV        EDX,dword ptr [ESP + param_4]
    //         00511864     PUSH       this
    //         00511865     MOV        this,dword ptr [ESP + param_3]
    //         00511869     PUSH       EDX
    //         0051186a     MOV        EDX,dword ptr [ESP + param_1]
    //         0051186e     PUSH       this
    //         0051186f     PUSH       EAX
    //         00511870     PUSH       EDX
    //         00511871     MOV        this,ESI
    //         00511873     CALL       RGE_Master_Player::load_master_object            void load_master_object(RGE_Master_Player * t
    //                              tmplayer.cpp:57 (18)
    //         00511878     MOV        this,dword ptr [ESP + local_c]
    //         0051187c     MOV        dword ptr FS:[0x0],this
    //         00511883     POP        ESI
    //         00511884     ADD        ESP,0xc
    //         00511887     RET        0x14
    //                               LAB_0051188a                                                 XREF[1]:     0051185a(j)  
    //                              tmplayer.cpp:51 (57)
    //         0051188a     PUSH       0xb8
    //         0051188f     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00511894     ADD        ESP,0x4
    //         00511897     MOV        dword ptr [ESP + param_2],EAX
    //         0051189b     TEST       EAX,EAX
    //         0051189d     MOV        dword ptr [ESP + local_4],0x2
    //         005118a5     JZ         LAB_00511970
    //         005118ab     MOV        this,dword ptr [ESP + param_4]
    //         005118af     MOV        EDX,dword ptr [ESP + param_3]
    //         005118b3     PUSH       0x1
    //         005118b5     PUSH       this
    //         005118b6     MOV        this,dword ptr [ESP + param_1]
    //         005118ba     PUSH       EDX
    //         005118bb     PUSH       this
    //         005118bc     MOV        this,EAX
    //         005118be     CALL       TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Ob   undefined TRIBE_Master_Tree_Object(TRIBE_Mast
    //                              tmplayer.cpp:52 (5)
    //         005118c3     JMP        LAB_00511972
    //                               LAB_005118c8                                                 XREF[1]:     00511856(j)  
    //                              tmplayer.cpp:48 (64)
    //         005118c8     PUSH       0x17c
    //         005118cd     CALL       operator_new                                     void * operator_new(uint param_1)
    //         005118d2     ADD        ESP,0x4
    //         005118d5     MOV        dword ptr [ESP + param_2],EAX
    //         005118d9     TEST       EAX,EAX
    //         005118db     MOV        dword ptr [ESP + local_4],0x1
    //         005118e3     JZ         LAB_0051191a
    //         005118e5     MOV        EDX,dword ptr [ESP + param_4]
    //         005118e9     MOV        this,dword ptr [ESP + param_3]
    //         005118ed     PUSH       0x1
    //         005118ef     PUSH       EDX
    //         005118f0     MOV        EDX,dword ptr [ESP + param_1]
    //         005118f4     PUSH       this
    //         005118f5     PUSH       EDX
    //         005118f6     MOV        this,EAX
    //         005118f8     CALL       TRIBE_Master_Building_Object::TRIBE_Master_Bui   undefined TRIBE_Master_Building_Object(TRIBE_
    //         005118fd     MOVSX      this,word ptr [ESP + param_5]
    //         00511902     MOV        EDX,dword ptr [ESI + 0x1c]
    //         00511905     MOV        dword ptr [EDX + this->field0_0x0*0x4],EAX
    //                              tmplayer.cpp:57 (18)
    //         00511908     MOV        this,dword ptr [ESP + local_c]
    //         0051190c     MOV        dword ptr FS:[0x0],this
    //         00511913     POP        ESI
    //         00511914     ADD        ESP,0xc
    //         00511917     RET        0x14
    //                               LAB_0051191a                                                 XREF[1]:     005118e3(j)  
    //                              tmplayer.cpp:48 (13)
    //         0051191a     MOVSX      this,word ptr [ESP + param_5]
    //         0051191f     MOV        EDX,dword ptr [ESI + 0x1c]
    //         00511922     XOR        EAX,EAX
    //         00511924     MOV        dword ptr [EDX + this->field0_0x0*0x4],EAX
    //                              tmplayer.cpp:57 (18)
    //         00511927     MOV        this,dword ptr [ESP + local_c]
    //         0051192b     MOV        dword ptr FS:[0x0],this
    //         00511932     POP        ESI
    //         00511933     ADD        ESP,0xc
    //         00511936     RET        0x14
    //                               LAB_00511939                                                 XREF[1]:     0051184e(j)  
    //                              tmplayer.cpp:45 (65)
    //         00511939     PUSH       0x164
    //         0051193e     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00511943     ADD        ESP,0x4
    //         00511946     MOV        dword ptr [ESP + param_2],EAX
    //         0051194a     TEST       EAX,EAX
    //         0051194c     MOV        dword ptr [ESP + local_4],0x0
    //         00511954     JZ         LAB_00511970
    //         00511956     MOV        this,dword ptr [ESP + param_4]
    //         0051195a     MOV        EDX,dword ptr [ESP + param_3]
    //         0051195e     PUSH       0x1
    //         00511960     PUSH       this
    //         00511961     MOV        this,dword ptr [ESP + param_1]
    //         00511965     PUSH       EDX
    //         00511966     PUSH       this
    //         00511967     MOV        this,EAX
    //         00511969     CALL       TRIBE_Master_Combat_Object::TRIBE_Master_Comba   undefined TRIBE_Master_Combat_Object(TRIBE_Ma
    //         0051196e     JMP        LAB_00511972
    //                               LAB_00511970                                                 XREF[2]:     005118a5(j), 00511954(j)  
    //         00511970     XOR        EAX,EAX
    //                               LAB_00511972                                                 XREF[2]:     005118c3(j), 0051196e(j)  
    //         00511972     MOVSX      EDX,word ptr [ESP + param_5]
    //         00511977     MOV        this,dword ptr [ESI + 0x1c]
    //                              tmplayer.cpp:57 (21)
    //         0051197a     POP        ESI
    //         0051197b     MOV        dword ptr [this->field0_0x0 + EDX*0x4],EAX
    //         0051197e     MOV        this,dword ptr [ESP]=>local_c
    //         00511982     MOV        dword ptr FS:[0x0],this
    //         00511989     ADD        ESP,0xc
    //         0051198c     RET        0x14
}

// Offset: 0x00511990
void TRIBE_Master_Player::load_object(FILE* param_1, uchar param_2, RGE_Sprite** param_3, RGE_Sound** param_4, short param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall TRIBE_Master_Player::load_object(struct _iobuf *,unsigned char,cla... *
    //                              *********************************************************************************************************
    //                              void __thiscall load_object(TRIBE_Master_Player * this, _iobuf * par
    //              void              <VOID>         <RETURN>
    //              TRIBE_Master_P    ECX:4 (auto)   this
    //              _iobuf *          Stack[0x4]:4   param_1                   XREF[4]:     005119cb(R), 00511a1d(R), 00511a5c(R), 00511ad0(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[4]:     0051199e(R), 005119f9(W), 00511a3c(W), 00511ab0(W)  
    //              RGE_Sprite * *    Stack[0xc]:4   param_3                   XREF[4]:     005119c6(R), 00511a15(R), 00511a54(R), 00511ac8(R)  
    //              RGE_Sound * *     Stack[0x10]:4  param_4                   XREF[4]:     005119c1(R), 00511a11(R), 00511a50(R), 00511ac4(R)  
    //              short             Stack[0x14]:2  param_5                   XREF[4]:     005119bd(R), 005119fd(R), 00511a40(R), 00511ab4(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     00511a01(W), 00511a44(W), 00511ab8(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[4]:     005119d9(R), 00511a72(R), 00511a90(R), 00511aec(*)  
    //                               ?load_object@TRIBE_Master_Player@@UAEXPAU_iobuf@@EPAPAVRGE_  XREF[1]:     00576810(*)  
    //                               TRIBE_Master_Player::load_object
    //                              tmplayer.cpp:61 (14)
    //         00511990     MOV        EAX,FS:[0x0]
    //         00511996     PUSH       -0x1
    //         00511998     PUSH       FUN_005610f1
    //         0051199d     PUSH       EAX
    //                              tmplayer.cpp:66 (31)
    //         0051199e     MOV        EAX,dword ptr [ESP + param_2]
    //         005119a2     MOV        dword ptr FS:[0x0],ESP
    //         005119a9     PUSH       ESI
    //         005119aa     PUSH       EDI
    //         005119ab     CMP        AL,0x46
    //         005119ad     MOV        EDI,this
    //         005119af     JZ         LAB_00511aa3
    //         005119b5     CMP        AL,0x50
    //         005119b7     JZ         LAB_00511a2f
    //         005119b9     CMP        AL,0x5a
    //         005119bb     JZ         LAB_005119ec
    //                              tmplayer.cpp:78 (28)
    //         005119bd     MOV        this,dword ptr [ESP + param_5]
    //         005119c1     MOV        EDX,dword ptr [ESP + param_4]
    //         005119c5     PUSH       this
    //         005119c6     MOV        this,dword ptr [ESP + param_3]
    //         005119ca     PUSH       EDX
    //         005119cb     MOV        EDX,dword ptr [ESP + param_1]
    //         005119cf     PUSH       this
    //         005119d0     PUSH       EAX
    //         005119d1     PUSH       EDX
    //         005119d2     MOV        this,EDI
    //         005119d4     CALL       RGE_Master_Player::load_object                   void load_object(RGE_Master_Player * this, _i
    //                              tmplayer.cpp:81 (19)
    //         005119d9     MOV        this,dword ptr [ESP + local_c]
    //         005119dd     MOV        dword ptr FS:[0x0],this
    //         005119e4     POP        EDI
    //         005119e5     POP        ESI
    //         005119e6     ADD        ESP,0xc
    //         005119e9     RET        0x14
    //                               LAB_005119ec                                                 XREF[1]:     005119bb(j)  
    //                              tmplayer.cpp:75 (62)
    //         005119ec     PUSH       0xb8
    //         005119f1     CALL       operator_new                                     void * operator_new(uint param_1)
    //         005119f6     ADD        ESP,0x4
    //         005119f9     MOV        dword ptr [ESP + param_2],EAX
    //         005119fd     MOV        ESI,dword ptr [ESP + param_5]
    //         00511a01     MOV        dword ptr [ESP + local_4],0x2
    //         00511a09     TEST       EAX,EAX
    //         00511a0b     JZ         LAB_00511adf
    //         00511a11     MOV        this,dword ptr [ESP + param_4]
    //         00511a15     MOV        EDX,dword ptr [ESP + param_3]
    //         00511a19     PUSH       0x1
    //         00511a1b     PUSH       ESI
    //         00511a1c     PUSH       this
    //         00511a1d     MOV        this,dword ptr [ESP + param_1]
    //         00511a21     PUSH       EDX
    //         00511a22     PUSH       this
    //         00511a23     MOV        this,EAX
    //         00511a25     CALL       TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Ob   undefined TRIBE_Master_Tree_Object(TRIBE_Mast
    //                              tmplayer.cpp:76 (5)
    //         00511a2a     JMP        LAB_00511ae1
    //                               LAB_00511a2f                                                 XREF[1]:     005119b7(j)  
    //                              tmplayer.cpp:72 (67)
    //         00511a2f     PUSH       0x17c
    //         00511a34     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00511a39     ADD        ESP,0x4
    //         00511a3c     MOV        dword ptr [ESP + param_2],EAX
    //         00511a40     MOV        ESI,dword ptr [ESP + param_5]
    //         00511a44     MOV        dword ptr [ESP + local_4],0x1
    //         00511a4c     TEST       EAX,EAX
    //         00511a4e     JZ         LAB_00511a85
    //         00511a50     MOV        EDX,dword ptr [ESP + param_4]
    //         00511a54     MOV        this,dword ptr [ESP + param_3]
    //         00511a58     PUSH       0x1
    //         00511a5a     PUSH       ESI
    //         00511a5b     PUSH       EDX
    //         00511a5c     MOV        EDX,dword ptr [ESP + param_1]
    //         00511a60     PUSH       this
    //         00511a61     PUSH       EDX
    //         00511a62     MOV        this,EAX
    //         00511a64     CALL       TRIBE_Master_Building_Object::TRIBE_Master_Bui   undefined TRIBE_Master_Building_Object(TRIBE_
    //         00511a69     MOV        EDX,dword ptr [EDI + 0x1c]
    //         00511a6c     MOVSX      this,SI
    //         00511a6f     MOV        dword ptr [EDX + this->field0_0x0*0x4],EAX
    //                              tmplayer.cpp:81 (19)
    //         00511a72     MOV        this,dword ptr [ESP + local_c]
    //         00511a76     MOV        dword ptr FS:[0x0],this
    //         00511a7d     POP        EDI
    //         00511a7e     POP        ESI
    //         00511a7f     ADD        ESP,0xc
    //         00511a82     RET        0x14
    //                               LAB_00511a85                                                 XREF[1]:     00511a4e(j)  
    //                              tmplayer.cpp:72 (11)
    //         00511a85     MOV        EDX,dword ptr [EDI + 0x1c]
    //         00511a88     XOR        EAX,EAX
    //         00511a8a     MOVSX      this,SI
    //         00511a8d     MOV        dword ptr [EDX + this->field0_0x0*0x4],EAX
    //                              tmplayer.cpp:81 (19)
    //         00511a90     MOV        this,dword ptr [ESP + local_c]
    //         00511a94     MOV        dword ptr FS:[0x0],this
    //         00511a9b     POP        EDI
    //         00511a9c     POP        ESI
    //         00511a9d     ADD        ESP,0xc
    //         00511aa0     RET        0x14
    //                               LAB_00511aa3                                                 XREF[1]:     005119af(j)  
    //                              tmplayer.cpp:69 (65)
    //         00511aa3     PUSH       0x164
    //         00511aa8     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00511aad     ADD        ESP,0x4
    //         00511ab0     MOV        dword ptr [ESP + param_2],EAX
    //         00511ab4     MOV        ESI,dword ptr [ESP + param_5]
    //         00511ab8     MOV        dword ptr [ESP + local_4],0x0
    //         00511ac0     TEST       EAX,EAX
    //         00511ac2     JZ         LAB_00511adf
    //         00511ac4     MOV        this,dword ptr [ESP + param_4]
    //         00511ac8     MOV        EDX,dword ptr [ESP + param_3]
    //         00511acc     PUSH       0x1
    //         00511ace     PUSH       ESI
    //         00511acf     PUSH       this
    //         00511ad0     MOV        this,dword ptr [ESP + param_1]
    //         00511ad4     PUSH       EDX
    //         00511ad5     PUSH       this
    //         00511ad6     MOV        this,EAX
    //         00511ad8     CALL       TRIBE_Master_Combat_Object::TRIBE_Master_Comba   undefined TRIBE_Master_Combat_Object(TRIBE_Ma
    //         00511add     JMP        LAB_00511ae1
    //                               LAB_00511adf                                                 XREF[2]:     00511a0b(j), 00511ac2(j)  
    //         00511adf     XOR        EAX,EAX
    //                               LAB_00511ae1                                                 XREF[2]:     00511a2a(j), 00511add(j)  
    //         00511ae1     MOV        this,dword ptr [EDI + 0x1c]
    //                              tmplayer.cpp:81 (25)
    //         00511ae4     POP        EDI
    //         00511ae5     MOVSX      EDX,SI
    //         00511ae8     POP        ESI
    //         00511ae9     MOV        dword ptr [this->field0_0x0 + EDX*0x4],EAX
    //         00511aec     MOV        this,dword ptr [ESP]=>local_c
    //         00511af0     MOV        dword ptr FS:[0x0],this
    //         00511af7     ADD        ESP,0xc
    //         00511afa     RET        0x14
}

