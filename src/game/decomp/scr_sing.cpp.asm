// Auto-generated scaffold unit: scr_sing.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/Scr_sing.cpp
#include "../include/common.h"

// Offset: 0x004B69A0
undefined TribeSPMenuScreen(TribeSPMenuScreen* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TribeSPMenuScreen::TribeSPMenuScreen(void)                                         *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TribeSPMenuScreen(TribeSPMenuScreen * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TribeSPMenuScr    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004b69da(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     004b6a23(R), 004b6bc8(R)  
    //              TPanel *[6]       Stack[-0x28]   tabList                   XREF[1]:     004b69c3(W)  
    //                               ??0TribeSPMenuScreen@@QAE@XZ                                 XREF[8]:     close_screen:0049d761(c), 
    //                               TribeSPMenuScreen::TribeSPMenuScreen                                      close_screen:0049d7fe(c), 
    //                                                                                                         action:0049e662(c), 
    //                                                                                                         action:0049ef27(c), 
    //                                                                                                         cancelScreen:004a2c39(c), 
    //                                                                                                         action:004a6acd(c), 
    //                                                                                                         action:004a715a(c), 
    //                                                                                                         action:004b43f9(c)  
    //                              Scr_sing.cpp:55 (50)
    //         004b69a0     PUSH       -0x1
    //         004b69a2     PUSH       FUN_0055f6d8
    //         004b69a7     MOV        EAX,FS:[0x0]
    //         004b69ad     PUSH       EAX
    //         004b69ae     MOV        dword ptr FS:[0x0],ESP
    //         004b69b5     SUB        ESP,0x1c
    //         004b69b8     PUSH       EBX
    //         004b69b9     PUSH       EBP
    //         004b69ba     PUSH       ESI
    //         004b69bb     PUSH       EDI
    //         004b69bc     MOV        EBX,this
    //         004b69be     PUSH       s_Single_Player_Menu                             = "Single Player Menu"
    //         004b69c3     MOV        dword ptr [ESP + tabList[0]],EBX
    //         004b69c7     CALL       TScreenPanel::TScreenPanel                       undefined TScreenPanel(TScreenPanel * this, c
    //         004b69cc     MOV        dword ptr [EBX],TribeSPMenuScreen::`vftable'     = 004b6be0
    //                              Scr_sing.cpp:60 (21)
    //         004b69d2     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b69d8     PUSH       0x1
    //         004b69da     MOV        dword ptr [ESP + local_4],0x0
    //         004b69e2     CALL       RGE_Base_Game::setSinglePlayerGame               void setSinglePlayerGame(RGE_Base_Game * this
    //                              Scr_sing.cpp:61 (16)
    //         004b69e7     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b69ed     PUSH       s_                                               = ""
    //         004b69f2     CALL       RGE_Base_Game::setScenarioName                   void setScenarioName(RGE_Base_Game * this, ch
    //                              Scr_sing.cpp:64 (32)
    //         004b69f7     MOV        EAX,[rge_base_game]                              = 00000000
    //         004b69fc     PUSH       0x1
    //         004b69fe     PUSH       0xc384
    //         004b6a03     PUSH       s_scr2                                           = 73h
    //         004b6a08     MOV        this,dword ptr [EAX + 0x4c]
    //         004b6a0b     PUSH       this
    //         004b6a0c     MOV        this,EBX
    //         004b6a0e     CALL       TScreenPanel::setup                              long setup(TScreenPanel * this, TDrawArea * p
    //         004b6a13     TEST       EAX,EAX
    //         004b6a15     JNZ        LAB_004b6a36
    //                              Scr_sing.cpp:66 (10)
    //         004b6a17     MOV        dword ptr [EBX + 0xd8],0x1
    //                              Scr_sing.cpp:106 (21)
    //         004b6a21     MOV        EAX,EBX
    //         004b6a23     MOV        this,dword ptr [ESP + local_c]
    //         004b6a27     MOV        dword ptr FS:[0x0],this
    //         004b6a2e     POP        EDI
    //         004b6a2f     POP        ESI
    //         004b6a30     POP        EBP
    //         004b6a31     POP        EBX
    //         004b6a32     ADD        ESP,0x28
    //         004b6a35     RET
    //                               LAB_004b6a36                                                 XREF[1]:     004b6a15(j)  
    //                              Scr_sing.cpp:70 (6)
    //         004b6a36     LEA        ESI,[EBX + 0x47c]
    //                              Scr_sing.cpp:71 (11)
    //         004b6a3c     MOV        this,0x7
    //         004b6a41     XOR        EAX,EAX
    //         004b6a43     MOV        EDI,ESI
    //         004b6a45     STOSD.REP  ES:EDI
    //                              Scr_sing.cpp:74 (23)
    //         004b6a47     PUSH       0x1e0
    //         004b6a4c     PUSH       0x280
    //         004b6a51     MOV        this,EBX
    //         004b6a53     MOV        dword ptr [EBX + 0x498],EAX
    //         004b6a59     CALL       TEasy_Panel::set_ideal_size                      void set_ideal_size(TEasy_Panel * this, long 
    //                              Scr_sing.cpp:77 (47)
    //         004b6a5e     PUSH       0x0
    //         004b6a60     PUSH       0x0
    //         004b6a62     PUSH       0x1
    //         004b6a64     PUSH       0x1
    //         004b6a66     PUSH       0x1e
    //         004b6a68     PUSH       0x258
    //         004b6a6d     PUSH       0x14
    //         004b6a6f     PUSH       0x14
    //         004b6a71     LEA        EDX,[EBX + 0x478]
    //                              language.dll match for 0x2404: "Single Player Menu"
    //         004b6a77     PUSH       0x2404
    //         004b6a7c     PUSH       EDX
    //         004b6a7d     PUSH       EBX
    //         004b6a7e     MOV        this,EBX
    //         004b6a80     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         004b6a85     TEST       EAX,EAX
    //         004b6a87     JZ         LAB_004b6bc8
    //                              language.dll match for 0x76: "B"
    //                              Scr_sing.cpp:80 (7)
    //         004b6a8d     MOV        EDI,0x76
    //         004b6a92     MOV        EBP,ESI
    //                               LAB_004b6a94                                                 XREF[1]:     004b6acb(j)  
    //                              Scr_sing.cpp:81 (57)
    //         004b6a94     PUSH       0x0
    //         004b6a96     PUSH       0x0
    //         004b6a98     PUSH       0x0
    //         004b6a9a     PUSH       0x28
    //         004b6a9c     PUSH       0x12c
    //         004b6aa1     PUSH       EDI
    //         004b6aa2     PUSH       0xaa
    //         004b6aa7     PUSH       0x0
    //         004b6aa9     PUSH       s_                                               = ""
    //         004b6aae     PUSH       EBP
    //         004b6aaf     PUSH       EBX
    //         004b6ab0     MOV        this,EBX
    //         004b6ab2     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         004b6ab7     TEST       EAX,EAX
    //         004b6ab9     JZ         LAB_004b6bc8
    //         004b6abf     ADD        EDI,0x32
    //         004b6ac2     ADD        EBP,0x4
    //         004b6ac5     CMP        EDI,0x1a2
    //         004b6acb     JL         LAB_004b6a94
    //                              Scr_sing.cpp:85 (44)
    //         004b6acd     PUSH       0x0
    //         004b6acf     PUSH       -0x1
    //         004b6ad1     PUSH       -0x1
    //         004b6ad3     PUSH       0x0
    //         004b6ad5     PUSH       0x0
    //         004b6ad7     PUSH       0x0
    //         004b6ad9     PUSH       0x0
    //         004b6adb     PUSH       0x0
    //         004b6add     LEA        EDI,[EBX + 0x498]
    //                              language.dll match for 0x3ea: "X"
    //         004b6ae3     PUSH       0x3ea
    //         004b6ae8     PUSH       EDI
    //         004b6ae9     PUSH       EBX
    //         004b6aea     MOV        this,EBX
    //         004b6aec     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         004b6af1     TEST       EAX,EAX
    //         004b6af3     JZ         LAB_004b6bc8
    //                              Scr_sing.cpp:86 (9)
    //         004b6af9     MOV        this,dword ptr [EDI]
    //         004b6afb     PUSH       0x1
    //         004b6afd     MOV        EAX,dword ptr [this->_padding_]
    //         004b6aff     CALL       dword ptr [EAX + 0x14]
    //                              Scr_sing.cpp:87 (33)
    //         004b6b02     MOV        this,dword ptr [EDI]
    //         004b6b04     PUSH       0x0
    //         004b6b06     PUSH       0x0=>DAT_fffffff8
    //         004b6b08     PUSH       0x0=>DAT_fffffff4
    //         004b6b0a     MOV        EDX,dword ptr [this->_padding_]
    //         004b6b0c     PUSH       0x0=>DAT_fffffff0
    //         004b6b0e     PUSH       0x11
    //         004b6b10     PUSH       0x11
    //         004b6b12     PUSH       0x11
    //         004b6b14     PUSH       0x11
    //         004b6b16     PUSH       0x4
    //         004b6b18     PUSH       0x4
    //         004b6b1a     PUSH       0x4
    //         004b6b1c     PUSH       0x4
    //         004b6b1e     PUSH       0x9
    //         004b6b20     CALL       dword ptr [EDX + 0x18]
    //                              Scr_sing.cpp:89 (14)
    //         004b6b23     MOV        this,dword ptr [ESI]
    //                              language.dll match for 0x240a: "Random Map"
    //         004b6b25     PUSH       0x240a
    //         004b6b2a     PUSH       0x0=>DAT_fffffff8
    //         004b6b2c     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
    //                              Scr_sing.cpp:90 (18)
    //         004b6b31     MOV        this,dword ptr [EBX + 0x480]
    //                              language.dll match for 0x2408: "Campaign"
    //         004b6b37     PUSH       0x2408
    //         004b6b3c     PUSH       0x0=>DAT_fffffff8
    //         004b6b3e     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
    //                              Scr_sing.cpp:91 (18)
    //         004b6b43     MOV        this,dword ptr [EBX + 0x484]
    //                              language.dll match for 0x240b: "Death Match"
    //         004b6b49     PUSH       0x240b
    //         004b6b4e     PUSH       0x0=>DAT_fffffff8
    //         004b6b50     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
    //                              Scr_sing.cpp:92 (18)
    //         004b6b55     MOV        this,dword ptr [EBX + 0x488]
    //                              language.dll match for 0x2405: "Scenario"
    //         004b6b5b     PUSH       0x2405
    //         004b6b60     PUSH       0x0=>DAT_fffffff8
    //         004b6b62     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
    //                              Scr_sing.cpp:94 (18)
    //         004b6b67     MOV        this,dword ptr [EBX + 0x48c]
    //                              language.dll match for 0x2407: "Saved Game"
    //         004b6b6d     PUSH       0x2407
    //         004b6b72     PUSH       0x0=>DAT_fffffff8
    //         004b6b74     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
    //                              Scr_sing.cpp:95 (18)
    //         004b6b79     MOV        this,dword ptr [EBX + 0x490]
    //                              language.dll match for 0x2409: "Cancel"
    //         004b6b7f     PUSH       0x2409
    //         004b6b84     PUSH       0x0=>DAT_fffffff8
    //         004b6b86     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
    //                              Scr_sing.cpp:97 (6)
    //         004b6b8b     MOV        EAX,dword ptr [EBX + 0x490]
    //                              Scr_sing.cpp:100 (30)
    //         004b6b91     MOV        this,EBX
    //         004b6b93     MOV        dword ptr [EAX + 0x298],0x1b
    //         004b6b9d     MOV        dword ptr [EAX + 0x29c],0x0
    //         004b6ba7     MOV        EAX,dword ptr [ESI]
    //         004b6ba9     PUSH       EAX
    //         004b6baa     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                              Scr_sing.cpp:104 (11)
    //         004b6baf     MOV        this,0x6
    //         004b6bb4     LEA        EDI,[ESP + 0x14]
    //         004b6bb8     MOVSD.REP  ES:EDI,ESI
    //                              Scr_sing.cpp:105 (14)
    //         004b6bba     LEA        this,[ESP + 0x14]
    //         004b6bbe     PUSH       0x6
    //         004b6bc0     PUSH       this=>DAT_fffffff8
    //         004b6bc1     MOV        this,EBX
    //         004b6bc3     CALL       TPanel::set_tab_order                            void set_tab_order(TPanel * this, TPanel * * 
    //                               LAB_004b6bc8                                                 XREF[3]:     004b6a87(j), 004b6ab9(j), 
    //                                                                                                         004b6af3(j)  
    //                              Scr_sing.cpp:106 (21)
    //         004b6bc8     MOV        this,dword ptr [ESP + local_c]
    //         004b6bcc     POP        EDI
    //         004b6bcd     POP        ESI
    //         004b6bce     MOV        EAX,EBX
    //         004b6bd0     POP        EBP
    //         004b6bd1     MOV        dword ptr FS:[0x0],this
    //         004b6bd8     POP        EBX
    //         004b6bd9     ADD        ESP,0x28
    //         004b6bdc     RET
}

// Offset: 0x004B6C00
void TribeSPMenuScreen(TribeSPMenuScreen* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall TribeSPMenuScreen::~TribeSPMenuScreen(void)                                *
    //                              *********************************************************************************************************
    //                              void __thiscall ~TribeSPMenuScreen(TribeSPMenuScreen * this)
    //              void              <VOID>         <RETURN>
    //              TribeSPMenuScr    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004b6c2b(W), 004b6c62(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004b6c6f(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004b6c1b(W)  
    //                               ??1TribeSPMenuScreen@@UAE@XZ                                 XREF[1]:     `vector_deleting_destructor':004b6
    //                               TribeSPMenuScreen::~TribeSPMenuScreen
    //                              Scr_sing.cpp:111 (37)
    //         004b6c00     PUSH       -0x1
    //         004b6c02     PUSH       FUN_0055f6f8
    //         004b6c07     MOV        EAX,FS:[0x0]
    //         004b6c0d     PUSH       EAX
    //         004b6c0e     MOV        dword ptr FS:[0x0],ESP
    //         004b6c15     PUSH       this
    //         004b6c16     PUSH       EBX
    //         004b6c17     PUSH       ESI
    //         004b6c18     PUSH       EDI
    //         004b6c19     MOV        EDI,this
    //         004b6c1b     MOV        dword ptr [ESP + local_10],EDI
    //         004b6c1f     MOV        dword ptr [EDI],TribeSPMenuScreen::`vftable'     = 004b6be0
    //                              Scr_sing.cpp:112 (31)
    //         004b6c25     LEA        EAX,[EDI + 0x478]
    //         004b6c2b     MOV        dword ptr [ESP + local_4],0x0
    //         004b6c33     PUSH       EAX
    //         004b6c34     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004b6c39     LEA        ESI,[EDI + 0x47c]
    //         004b6c3f     MOV        EBX,0x7
    //                               LAB_004b6c44                                                 XREF[1]:     004b6c50(j)  
    //                              Scr_sing.cpp:114 (14)
    //         004b6c44     PUSH       ESI
    //         004b6c45     MOV        this,EDI
    //         004b6c47     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004b6c4c     ADD        ESI,0x4
    //         004b6c4f     DEC        EBX
    //         004b6c50     JNZ        LAB_004b6c44
    //                              Scr_sing.cpp:116 (16)
    //         004b6c52     LEA        this,[EDI + 0x498]
    //         004b6c58     PUSH       this
    //         004b6c59     MOV        this,EDI
    //         004b6c5b     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004b6c60     MOV        this,EDI
    //                              Scr_sing.cpp:117 (31)
    //         004b6c62     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004b6c6a     CALL       TScreenPanel::~TScreenPanel                      void ~TScreenPanel(TScreenPanel * this)
    //         004b6c6f     MOV        this,dword ptr [ESP + local_c]
    //         004b6c73     POP        EDI
    //         004b6c74     POP        ESI
    //         004b6c75     MOV        dword ptr FS:[0x0],this
    //         004b6c7c     POP        EBX
    //         004b6c7d     ADD        ESP,0x10
    //         004b6c80     RET
}

// Offset: 0x004B6C90
long TribeSPMenuScreen::handle_idle() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TribeSPMenuScreen::handle_idle(void)                                  *
    //                              *********************************************************************************************************
    //                              long __thiscall handle_idle(TribeSPMenuScreen * this)
    //              long              EAX:4          <RETURN>
    //              TribeSPMenuScr    ECX:4 (auto)   this
    //                               ?handle_idle@TribeSPMenuScreen@@UAEJXZ                       XREF[1]:     00573fec(*)  
    //                               TribeSPMenuScreen::handle_idle
    //                              Scr_sing.cpp:123 (3)
    //         004b6c90     PUSH       ESI
    //         004b6c91     MOV        ESI,this
    //                              Scr_sing.cpp:124 (16)
    //         004b6c93     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b6c99     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004b6c9f     TEST       EAX,EAX
    //         004b6ca1     JNZ        LAB_004b6ca8
    //                              Scr_sing.cpp:125 (5)
    //         004b6ca3     CALL       RGE_Base_Game::enable_input                      void enable_input(RGE_Base_Game * this)
    //                               LAB_004b6ca8                                                 XREF[1]:     004b6ca1(j)  
    //                              Scr_sing.cpp:127 (7)
    //         004b6ca8     MOV        this,ESI
    //         004b6caa     CALL       TPanel::handle_idle                              long handle_idle(TPanel * this)
    //                              Scr_sing.cpp:128 (2)
    //         004b6caf     POP        ESI
    //         004b6cb0     RET
}

// Offset: 0x004B6CC0
long TribeSPMenuScreen::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TribeSPMenuScreen::action(class TPanel *,long,unsigned long,unsign... *
    //                              *********************************************************************************************************
    //                              long __thiscall action(TribeSPMenuScreen * this, TPanel * param_1, l
    //              long              EAX:4          <RETURN>
    //              TribeSPMenuScr    ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[10]:    004b6cce(R), 004b6d54(W), 004b6dc7(W), 004b6e84(W), 
    //                                                                                     004b6efc(W), 004b6f78(*), 004b6f7d(W), 004b6f9a(R), 
    //                                                                                     004b6faf(R), 004b7087(W)  
    //              long              Stack[0x8]:4   param_2                   XREF[2]:     004b6cdc(R), 004b6f70(*)  
    //              ulong             Stack[0xc]:4   param_3                   XREF[1]:     004b7110(R)  
    //              ulong             Stack[0x10]:4  param_4                   XREF[3]:     004b6fcd(W), 004b7032(W), 004b710b(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[12]:    004b6d58(W), 004b6dcb(W), 004b6dea(W), 004b6e8a(W), 
    //                                                                                     004b6ea7(W), 004b6f02(W), 004b6f1f(W), 004b6fd3(W), 
    //                                                                                     004b6ff0(W), 004b7038(W), 004b708d(W), 004b70aa(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[8]:     004b6e0b(R), 004b6ec8(R), 004b6f40(R), 004b7011(R), 
    //                                                                                     004b7053(R), 004b70cb(R), 004b70f7(R), 004b711e(R)  
    //                               ?action@TribeSPMenuScreen@@UAEJPAVTPanel@@JKK@Z              XREF[1]:     00574054(*)  
    //                               TribeSPMenuScreen::action
    //                              Scr_sing.cpp:134 (14)
    //         004b6cc0     MOV        EAX,FS:[0x0]
    //         004b6cc6     PUSH       -0x1
    //         004b6cc8     PUSH       FUN_0055f75d
    //         004b6ccd     PUSH       EAX
    //                              Scr_sing.cpp:138 (28)
    //         004b6cce     MOV        EAX,dword ptr [ESP + param_1]
    //         004b6cd2     MOV        dword ptr FS:[0x0],ESP
    //         004b6cd9     PUSH       EBX
    //         004b6cda     MOV        EBX,this
    //         004b6cdc     MOV        this,dword ptr [ESP + param_2]
    //         004b6ce0     PUSH       ESI
    //         004b6ce1     TEST       EAX,EAX
    //         004b6ce3     PUSH       EDI
    //         004b6ce4     JZ         LAB_004b710b
    //                              Scr_sing.cpp:139 (9)
    //         004b6cea     CMP        this,0x1
    //         004b6ced     JNZ        LAB_004b710b
    //                              Scr_sing.cpp:141 (8)
    //         004b6cf3     CMP        EAX,dword ptr [EBX + 0x47c]
    //         004b6cf9     JNZ        LAB_004b6d62
    //                              Scr_sing.cpp:149 (13)
    //         004b6cfb     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b6d01     PUSH       0x0
    //         004b6d03     CALL       RGE_Base_Game::setCampaignGame                   void setCampaignGame(RGE_Base_Game * this, in
    //                              Scr_sing.cpp:150 (13)
    //         004b6d08     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b6d0e     PUSH       0x0
    //         004b6d10     CALL       RGE_Base_Game::setSavedGame                      void setSavedGame(RGE_Base_Game * this, int p
    //                              Scr_sing.cpp:151 (13)
    //         004b6d15     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b6d1b     PUSH       0x0
    //         004b6d1d     CALL       RGE_Base_Game::setScenarioGame                   void setScenarioGame(RGE_Base_Game * this, in
    //                              Scr_sing.cpp:152 (13)
    //         004b6d22     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b6d28     PUSH       0x0
    //         004b6d2a     CALL       TRIBE_Game::setDeathMatch                        void setDeathMatch(TRIBE_Game * this, uchar p
    //                              Scr_sing.cpp:153 (13)
    //         004b6d2f     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b6d35     PUSH       0x0
    //         004b6d37     CALL       TRIBE_Game::setQuickStartGame                    void setQuickStartGame(TRIBE_Game * this, uch
    //                              Scr_sing.cpp:155 (11)
    //         004b6d3c     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b6d42     CALL       RGE_Base_Game::disable_input                     void disable_input(RGE_Base_Game * this)
    //                              Scr_sing.cpp:156 (25)
    //         004b6d47     PUSH       0x890
    //         004b6d4c     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004b6d51     ADD        ESP,0x4
    //         004b6d54     MOV        dword ptr [ESP + param_1],EAX
    //         004b6d58     MOV        dword ptr [ESP + local_4],0x0
    //                              Scr_sing.cpp:160 (2)
    //         004b6d60     JMP        LAB_004b6dd3
    //                               LAB_004b6d62                                                 XREF[1]:     004b6cf9(j)  
    //                              Scr_sing.cpp:163 (12)
    //         004b6d62     CMP        EAX,dword ptr [EBX + 0x484]
    //         004b6d68     JNZ        LAB_004b6e1f
    //                              Scr_sing.cpp:171 (13)
    //         004b6d6e     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b6d74     PUSH       0x0
    //         004b6d76     CALL       RGE_Base_Game::setCampaignGame                   void setCampaignGame(RGE_Base_Game * this, in
    //                              Scr_sing.cpp:172 (13)
    //         004b6d7b     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b6d81     PUSH       0x0
    //         004b6d83     CALL       RGE_Base_Game::setSavedGame                      void setSavedGame(RGE_Base_Game * this, int p
    //                              Scr_sing.cpp:173 (13)
    //         004b6d88     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b6d8e     PUSH       0x0
    //         004b6d90     CALL       RGE_Base_Game::setScenarioGame                   void setScenarioGame(RGE_Base_Game * this, in
    //                              Scr_sing.cpp:174 (13)
    //         004b6d95     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b6d9b     PUSH       0x1
    //         004b6d9d     CALL       TRIBE_Game::setDeathMatch                        void setDeathMatch(TRIBE_Game * this, uchar p
    //                              Scr_sing.cpp:175 (13)
    //         004b6da2     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b6da8     PUSH       0x0
    //         004b6daa     CALL       TRIBE_Game::setQuickStartGame                    void setQuickStartGame(TRIBE_Game * this, uch
    //                              Scr_sing.cpp:177 (11)
    //         004b6daf     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b6db5     CALL       RGE_Base_Game::disable_input                     void disable_input(RGE_Base_Game * this)
    //                              Scr_sing.cpp:178 (36)
    //         004b6dba     PUSH       0x890
    //         004b6dbf     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004b6dc4     ADD        ESP,0x4
    //         004b6dc7     MOV        dword ptr [ESP + param_1],EAX
    //         004b6dcb     MOV        dword ptr [ESP + local_4],0x1
    //                               LAB_004b6dd3                                                 XREF[1]:     004b6d60(j)  
    //         004b6dd3     TEST       EAX,EAX
    //         004b6dd5     JZ         LAB_004b6dde
    //         004b6dd7     MOV        this,EAX
    //         004b6dd9     CALL       TribeMPSetupScreen::TribeMPSetupScreen           undefined TribeMPSetupScreen(TribeMPSetupScre
    //                               LAB_004b6dde                                                 XREF[1]:     004b6dd5(j)  
    //                              Scr_sing.cpp:179 (25)
    //         004b6dde     PUSH       0x0
    //         004b6de0     PUSH       s_MP_Setup_Screen                                = "MP Setup Screen"
    //         004b6de5     MOV        this,panel_system
    //         004b6dea     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004b6df2     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              Scr_sing.cpp:180 (15)
    //         004b6df7     PUSH       s_Single_Player_Menu                             = "Single Player Menu"
    //         004b6dfc     MOV        this,panel_system
    //         004b6e01     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              Scr_sing.cpp:182 (5)
    //         004b6e06     MOV        EAX,0x1
    //                              Scr_sing.cpp:318 (20)
    //         004b6e0b     MOV        this,dword ptr [ESP + local_c]
    //         004b6e0f     MOV        dword ptr FS:[0x0],this
    //         004b6e16     POP        EDI
    //         004b6e17     POP        ESI
    //         004b6e18     POP        EBX
    //         004b6e19     ADD        ESP,0xc
    //         004b6e1c     RET        0x10
    //                               LAB_004b6e1f                                                 XREF[1]:     004b6d68(j)  
    //                              Scr_sing.cpp:185 (12)
    //         004b6e1f     CMP        EAX,dword ptr [EBX + 0x488]
    //         004b6e25     JNZ        LAB_004b6edc
    //                              Scr_sing.cpp:189 (13)
    //         004b6e2b     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b6e31     PUSH       0x0
    //         004b6e33     CALL       RGE_Base_Game::setCampaignGame                   void setCampaignGame(RGE_Base_Game * this, in
    //                              Scr_sing.cpp:190 (13)
    //         004b6e38     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b6e3e     PUSH       0x0
    //         004b6e40     CALL       RGE_Base_Game::setSavedGame                      void setSavedGame(RGE_Base_Game * this, int p
    //                              Scr_sing.cpp:191 (13)
    //         004b6e45     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b6e4b     PUSH       0x1
    //         004b6e4d     CALL       RGE_Base_Game::setScenarioGame                   void setScenarioGame(RGE_Base_Game * this, in
    //                              Scr_sing.cpp:192 (13)
    //         004b6e52     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b6e58     PUSH       0x0
    //         004b6e5a     CALL       TRIBE_Game::setDeathMatch                        void setDeathMatch(TRIBE_Game * this, uchar p
    //                              Scr_sing.cpp:193 (13)
    //         004b6e5f     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b6e65     PUSH       0x0
    //         004b6e67     CALL       TRIBE_Game::setQuickStartGame                    void setQuickStartGame(TRIBE_Game * this, uch
    //                              Scr_sing.cpp:195 (11)
    //         004b6e6c     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b6e72     CALL       RGE_Base_Game::disable_input                     void disable_input(RGE_Base_Game * this)
    //                              Scr_sing.cpp:196 (36)
    //         004b6e77     PUSH       0x4d8
    //         004b6e7c     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004b6e81     ADD        ESP,0x4
    //         004b6e84     MOV        dword ptr [ESP + param_1],EAX
    //         004b6e88     TEST       EAX,EAX
    //         004b6e8a     MOV        dword ptr [ESP + local_4],0x2
    //         004b6e92     JZ         LAB_004b6e9b
    //         004b6e94     MOV        this,EAX
    //         004b6e96     CALL       TribeSelectScenarioScreen::TribeSelectScenario   undefined TribeSelectScenarioScreen(TribeSele
    //                               LAB_004b6e9b                                                 XREF[1]:     004b6e92(j)  
    //                              Scr_sing.cpp:197 (25)
    //         004b6e9b     PUSH       0x0
    //         004b6e9d     PUSH       s_Select_Scenario_Screen                         = "Select Scenario Screen"
    //         004b6ea2     MOV        this,panel_system
    //         004b6ea7     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004b6eaf     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              Scr_sing.cpp:198 (15)
    //         004b6eb4     PUSH       s_Single_Player_Menu                             = "Single Player Menu"
    //         004b6eb9     MOV        this,panel_system
    //         004b6ebe     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              Scr_sing.cpp:200 (5)
    //         004b6ec3     MOV        EAX,0x1
    //                              Scr_sing.cpp:318 (20)
    //         004b6ec8     MOV        this,dword ptr [ESP + local_c]
    //         004b6ecc     MOV        dword ptr FS:[0x0],this
    //         004b6ed3     POP        EDI
    //         004b6ed4     POP        ESI
    //         004b6ed5     POP        EBX
    //         004b6ed6     ADD        ESP,0xc
    //         004b6ed9     RET        0x10
    //                               LAB_004b6edc                                                 XREF[1]:     004b6e25(j)  
    //                              Scr_sing.cpp:252 (8)
    //         004b6edc     CMP        EAX,dword ptr [EBX + 0x48c]
    //         004b6ee2     JNZ        LAB_004b6f54
    //                              Scr_sing.cpp:253 (11)
    //         004b6ee4     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b6eea     CALL       RGE_Base_Game::disable_input                     void disable_input(RGE_Base_Game * this)
    //                              Scr_sing.cpp:254 (36)
    //         004b6eef     PUSH       0x494
    //         004b6ef4     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004b6ef9     ADD        ESP,0x4
    //         004b6efc     MOV        dword ptr [ESP + param_1],EAX
    //         004b6f00     TEST       EAX,EAX
    //         004b6f02     MOV        dword ptr [ESP + local_4],0x3
    //         004b6f0a     JZ         LAB_004b6f13
    //         004b6f0c     MOV        this,EAX
    //         004b6f0e     CALL       TribeLoadSavedGameScreen::TribeLoadSavedGameSc   undefined TribeLoadSavedGameScreen(TribeLoadS
    //                               LAB_004b6f13                                                 XREF[1]:     004b6f0a(j)  
    //                              Scr_sing.cpp:255 (25)
    //         004b6f13     PUSH       0x0
    //         004b6f15     PUSH       s_Load_Saved_Game_Screen                         = "Load Saved Game Screen"
    //         004b6f1a     MOV        this,panel_system
    //         004b6f1f     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004b6f27     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              Scr_sing.cpp:256 (15)
    //         004b6f2c     PUSH       s_Single_Player_Menu                             = "Single Player Menu"
    //         004b6f31     MOV        this,panel_system
    //         004b6f36     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              Scr_sing.cpp:257 (5)
    //         004b6f3b     MOV        EAX,0x1
    //                              Scr_sing.cpp:318 (20)
    //         004b6f40     MOV        this,dword ptr [ESP + local_c]
    //         004b6f44     MOV        dword ptr FS:[0x0],this
    //         004b6f4b     POP        EDI
    //         004b6f4c     POP        ESI
    //         004b6f4d     POP        EBX
    //         004b6f4e     ADD        ESP,0xc
    //         004b6f51     RET        0x10
    //                               LAB_004b6f54                                                 XREF[1]:     004b6ee2(j)  
    //                              Scr_sing.cpp:260 (12)
    //         004b6f54     CMP        EAX,dword ptr [EBX + 0x480]
    //         004b6f5a     JNZ        LAB_004b7067
    //                              Scr_sing.cpp:261 (11)
    //         004b6f60     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b6f66     CALL       RGE_Base_Game::disable_input                     void disable_input(RGE_Base_Game * this)
    //                              Scr_sing.cpp:269 (5)
    //         004b6f6b     MOV        EAX,[rge_base_game]                              = 00000000
    //                              Scr_sing.cpp:273 (28)
    //         004b6f70     LEA        EDX=>param_2,[ESP + 0x20]
    //         004b6f74     PUSH       EDX
    //         004b6f75     MOV        this,dword ptr [EAX + 0x4]
    //         004b6f78     LEA        EAX=>param_1,[ESP + 0x20]
    //         004b6f7c     PUSH       EAX
    //         004b6f7d     MOV        dword ptr [ESP + param_1],0x0
    //         004b6f85     CALL       RGE_Game_Info::get_people_list                   long get_people_list(RGE_Game_Info * this, ch
    //         004b6f8a     MOV        EDI,EAX
    //                              Scr_sing.cpp:274 (8)
    //         004b6f8c     TEST       EDI,EDI
    //         004b6f8e     JLE        LAB_004b7025
    //                              Scr_sing.cpp:276 (6)
    //         004b6f94     XOR        ESI,ESI
    //         004b6f96     TEST       EDI,EDI
    //         004b6f98     JLE        LAB_004b6faf
    //                               LAB_004b6f9a                                                 XREF[1]:     004b6fad(j)  
    //                              Scr_sing.cpp:277 (21)
    //         004b6f9a     MOV        this,dword ptr [ESP + param_1]
    //         004b6f9e     MOV        EDX,dword ptr [this->_padding_ + ESI*0x4]
    //         004b6fa1     PUSH       EDX
    //         004b6fa2     CALL       free                                             undefined free()
    //         004b6fa7     ADD        ESP,0x4
    //         004b6faa     INC        ESI
    //         004b6fab     CMP        ESI,EDI
    //         004b6fad     JL         LAB_004b6f9a
    //                               LAB_004b6faf                                                 XREF[1]:     004b6f98(j)  
    //                              Scr_sing.cpp:278 (13)
    //         004b6faf     MOV        EAX,dword ptr [ESP + param_1]
    //         004b6fb3     PUSH       EAX
    //         004b6fb4     CALL       free                                             undefined free()
    //         004b6fb9     ADD        ESP,0x4
    //                              Scr_sing.cpp:284 (4)
    //         004b6fbc     TEST       EDI,EDI
    //         004b6fbe     JLE        LAB_004b7025
    //                              Scr_sing.cpp:286 (36)
    //         004b6fc0     PUSH       0x4a0
    //         004b6fc5     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004b6fca     ADD        ESP,0x4
    //         004b6fcd     MOV        dword ptr [ESP + param_4],EAX
    //         004b6fd1     TEST       EAX,EAX
    //         004b6fd3     MOV        dword ptr [ESP + local_4],0x4
    //         004b6fdb     JZ         LAB_004b6fe4
    //         004b6fdd     MOV        this,EAX
    //         004b6fdf     CALL       TRIBE_Screen_Name::TRIBE_Screen_Name             undefined TRIBE_Screen_Name(TRIBE_Screen_Name
    //                               LAB_004b6fe4                                                 XREF[1]:     004b6fdb(j)  
    //                              Scr_sing.cpp:287 (25)
    //         004b6fe4     PUSH       0x0
    //         004b6fe6     PUSH       s_Name_Selection_Screen                          = "Name Selection Screen"
    //         004b6feb     MOV        this,panel_system
    //         004b6ff0     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004b6ff8     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              Scr_sing.cpp:288 (15)
    //         004b6ffd     PUSH       s_Single_Player_Menu                             = "Single Player Menu"
    //         004b7002     MOV        this,panel_system
    //         004b7007     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              Scr_sing.cpp:297 (5)
    //         004b700c     MOV        EAX,0x1
    //                              Scr_sing.cpp:318 (20)
    //         004b7011     MOV        this,dword ptr [ESP + local_c]
    //         004b7015     MOV        dword ptr FS:[0x0],this
    //         004b701c     POP        EDI
    //         004b701d     POP        ESI
    //         004b701e     POP        EBX
    //         004b701f     ADD        ESP,0xc
    //         004b7022     RET        0x10
    //                               LAB_004b7025                                                 XREF[2]:     004b6f8e(j), 004b6fbe(j)  
    //                              Scr_sing.cpp:292 (41)
    //         004b7025     PUSH       0x4a4
    //         004b702a     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004b702f     ADD        ESP,0x4
    //         004b7032     MOV        dword ptr [ESP + param_4],EAX
    //         004b7036     TEST       EAX,EAX
    //         004b7038     MOV        dword ptr [ESP + local_4],0x5
    //         004b7040     JZ         LAB_004b70f2
    //         004b7046     PUSH       EBX
    //         004b7047     MOV        this,EAX
    //         004b7049     CALL       TRIBE_Dialog_Name::TRIBE_Dialog_Name             undefined TRIBE_Dialog_Name(TRIBE_Dialog_Name
    //                              Scr_sing.cpp:294 (5)
    //         004b704e     MOV        EAX,0x1
    //                              Scr_sing.cpp:318 (20)
    //         004b7053     MOV        this,dword ptr [ESP + local_c]
    //         004b7057     MOV        dword ptr FS:[0x0],this
    //         004b705e     POP        EDI
    //         004b705f     POP        ESI
    //         004b7060     POP        EBX
    //         004b7061     ADD        ESP,0xc
    //         004b7064     RET        0x10
    //                               LAB_004b7067                                                 XREF[1]:     004b6f5a(j)  
    //                              Scr_sing.cpp:300 (8)
    //         004b7067     CMP        EAX,dword ptr [EBX + 0x490]
    //         004b706d     JNZ        LAB_004b70df
    //                              Scr_sing.cpp:301 (11)
    //         004b706f     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b7075     CALL       RGE_Base_Game::disable_input                     void disable_input(RGE_Base_Game * this)
    //                              language.dll match for 0x4b0: "Ready"
    //                              Scr_sing.cpp:302 (36)
    //         004b707a     PUSH       0x4b0
    //         004b707f     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004b7084     ADD        ESP,0x4
    //         004b7087     MOV        dword ptr [ESP + param_1],EAX
    //         004b708b     TEST       EAX,EAX
    //         004b708d     MOV        dword ptr [ESP + local_4],0x6
    //         004b7095     JZ         LAB_004b709e
    //         004b7097     MOV        this,EAX
    //         004b7099     CALL       TRIBE_Screen_Main_Menu::TRIBE_Screen_Main_Menu   undefined TRIBE_Screen_Main_Menu(TRIBE_Screen
    //                               LAB_004b709e                                                 XREF[1]:     004b7095(j)  
    //                              Scr_sing.cpp:303 (25)
    //         004b709e     PUSH       0x0
    //         004b70a0     PUSH       s_Main_Menu                                      = "Main Menu"
    //         004b70a5     MOV        this,panel_system
    //         004b70aa     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004b70b2     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              Scr_sing.cpp:304 (15)
    //         004b70b7     PUSH       s_Single_Player_Menu                             = "Single Player Menu"
    //         004b70bc     MOV        this,panel_system
    //         004b70c1     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              Scr_sing.cpp:305 (5)
    //         004b70c6     MOV        EAX,0x1
    //                              Scr_sing.cpp:318 (20)
    //         004b70cb     MOV        this,dword ptr [ESP + local_c]
    //         004b70cf     MOV        dword ptr FS:[0x0],this
    //         004b70d6     POP        EDI
    //         004b70d7     POP        ESI
    //         004b70d8     POP        EBX
    //         004b70d9     ADD        ESP,0xc
    //         004b70dc     RET        0x10
    //                               LAB_004b70df                                                 XREF[1]:     004b706d(j)  
    //                              Scr_sing.cpp:308 (8)
    //         004b70df     CMP        EAX,dword ptr [EBX + 0x498]
    //         004b70e5     JNZ        LAB_004b710b
    //                              Scr_sing.cpp:310 (11)
    //         004b70e7     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b70ed     CALL       RGE_Base_Game::close                             void close(RGE_Base_Game * this)
    //                               LAB_004b70f2                                                 XREF[1]:     004b7040(j)  
    //                              Scr_sing.cpp:311 (5)
    //         004b70f2     MOV        EAX,0x1
    //                              Scr_sing.cpp:318 (20)
    //         004b70f7     MOV        this,dword ptr [ESP + local_c]
    //         004b70fb     MOV        dword ptr FS:[0x0],this
    //         004b7102     POP        EDI
    //         004b7103     POP        ESI
    //         004b7104     POP        EBX
    //         004b7105     ADD        ESP,0xc
    //         004b7108     RET        0x10
    //                               LAB_004b710b                                                 XREF[3]:     004b6ce4(j), 004b6ced(j), 
    //                                                                                                         004b70e5(j)  
    //                              Scr_sing.cpp:317 (19)
    //         004b710b     MOV        EDX,dword ptr [ESP + param_4]
    //         004b710f     PUSH       EDX
    //         004b7110     MOV        EDX,dword ptr [ESP + param_3]
    //         004b7114     PUSH       EDX
    //         004b7115     PUSH       this
    //         004b7116     PUSH       EAX
    //         004b7117     MOV        this,EBX
    //         004b7119     CALL       TEasy_Panel::action                              long action(TEasy_Panel * this, TPanel * para
    //                              Scr_sing.cpp:318 (20)
    //         004b711e     MOV        this,dword ptr [ESP + local_c]
    //         004b7122     POP        EDI
    //         004b7123     POP        ESI
    //         004b7124     MOV        dword ptr FS:[0x0],this
    //         004b712b     POP        EBX
    //         004b712c     ADD        ESP,0xc
    //         004b712f     RET        0x10
}

