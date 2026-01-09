#include "common.h"
#include "scr_cj.h"

TribeJoinScreen::TribeJoinScreen() {
    /* TODO: Stub */
    //                              undefined __thiscall TribeJoinScreen(TribeJoinScreen * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TribeJoinScree    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004916bc(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     00491704(R), 00491958(R)  
    //              TPanel *[5]       Stack[-0x24]   tabList                   XREF[1]:     00491673(W)  
    //                               ??0TribeJoinScreen@@QAE@XZ                                   XREF[3]:     action:0049fc13(c), 
    //                               TribeJoinScreen::TribeJoinScreen                                          cancelScreen:004a2d0f(c), 
    //                                                                                                         quit_game:00524332(c)  
    //                              scr_cj.cpp:62 (52)
    //         00491650     PUSH       -0x1
    //         00491652     PUSH       FUN_0055e9a8
    //         00491657     MOV        EAX,FS:[0x0]
    //         0049165d     PUSH       EAX
    //         0049165e     MOV        dword ptr FS:[0x0],ESP
    //         00491665     SUB        ESP,0x18
    //         00491668     PUSH       EBX
    //         00491669     PUSH       EBP
    //         0049166a     PUSH       ESI
    //         0049166b     PUSH       EDI
    //         0049166c     MOV        ESI,this
    //         0049166e     PUSH       s_Join_Screen                                    = "Join Screen"
    //         00491673     MOV        dword ptr [ESP + tabList[0]],ESI
    //         00491677     CALL       TScreenPanel::TScreenPanel                       undefined TScreenPanel(TScreenPanel * this, c
    //         0049167c     XOR        EBP,EBP
    //         0049167e     MOV        dword ptr [ESI],TribeJoinScreen::`vftable'       = 00491970
    //                              scr_cj.cpp:64 (6)
    //         00491684     MOV        dword ptr [ESI + 0x478],EBP
    //                              scr_cj.cpp:65 (6)
    //         0049168a     MOV        dword ptr [ESI + 0x47c],EBP
    //                              scr_cj.cpp:66 (6)
    //         00491690     MOV        dword ptr [Sess],EBP                             = 00000000
    //                              scr_cj.cpp:74 (47)
    //         00491696     MOV        EBX,0x1
    //         0049169b     MOV        dword ptr [ESI + 0x4a4],EBP
    //         004916a1     MOV        dword ptr [ESI + 0x4a8],EBP
    //         004916a7     MOV        dword ptr [ESI + 0x4ac],EBP
    //         004916ad     MOV        dword ptr [ESI + 0x4a0],EBP
    //         004916b3     MOV        this,dword ptr [comm]                            = 00000000
    //         004916b9     PUSH       0x2
    //         004916bb     PUSH       EBX
    //         004916bc     MOV        dword ptr [ESP + local_4],EBP
    //         004916c0     CALL       TCommunications_Handler::SetPlayerHumanity       void SetPlayerHumanity(TCommunications_Handle
    //                              scr_cj.cpp:75 (5)
    //         004916c5     MOV        EDI,0x2
    //                               LAB_004916ca                                                 XREF[1]:     004916db(j)  
    //                              scr_cj.cpp:76 (19)
    //         004916ca     MOV        this,dword ptr [comm]                            = 00000000
    //         004916d0     PUSH       EBP
    //         004916d1     PUSH       EDI
    //         004916d2     CALL       TCommunications_Handler::SetPlayerHumanity       void SetPlayerHumanity(TCommunications_Handle
    //         004916d7     INC        EDI
    //         004916d8     CMP        EDI,0x9
    //         004916db     JLE        LAB_004916ca
    //                              scr_cj.cpp:79 (31)
    //         004916dd     MOV        EAX,[rge_base_game]                              = 00000000
    //         004916e2     PUSH       EBX
    //         004916e3     PUSH       0xc385
    //         004916e8     PUSH       s_scr3                                           = 73h
    //         004916ed     MOV        this,dword ptr [EAX + 0x4c]
    //         004916f0     PUSH       this
    //         004916f1     MOV        this,ESI
    //         004916f3     CALL       TScreenPanel::setup                              long setup(TScreenPanel * this, TDrawArea * p
    //         004916f8     TEST       EAX,EAX
    //         004916fa     JNZ        LAB_00491717
    //                              scr_cj.cpp:80 (6)
    //         004916fc     MOV        dword ptr [ESI + 0xd8],EBX
    //                              scr_cj.cpp:126 (21)
    //         00491702     MOV        EAX,ESI
    //         00491704     MOV        this,dword ptr [ESP + local_c]
    //         00491708     MOV        dword ptr FS:[0x0],this
    //         0049170f     POP        EDI
    //         00491710     POP        ESI
    //         00491711     POP        EBP
    //         00491712     POP        EBX
    //         00491713     ADD        ESP,0x24
    //         00491716     RET
    //                               LAB_00491717                                                 XREF[1]:     004916fa(j)  
    //                              scr_cj.cpp:84 (8)
    //         00491717     PUSH       EBP
    //         00491718     MOV        this,ESI
    //         0049171a     CALL       TEasy_Panel::setup_shadow_area                   void setup_shadow_area(TEasy_Panel * this, in
    //                              scr_cj.cpp:85 (17)
    //         0049171f     PUSH       0x1e0
    //         00491724     PUSH       0x280
    //         00491729     MOV        this,ESI
    //         0049172b     CALL       TEasy_Panel::set_ideal_size                      void set_ideal_size(TEasy_Panel * this, long 
    //                              scr_cj.cpp:88 (43)
    //         00491730     PUSH       EBP
    //         00491731     PUSH       EBP
    //         00491732     PUSH       EBX
    //         00491733     PUSH       EBX
    //         00491734     PUSH       0x1e
    //         00491736     PUSH       0x258
    //         0049173b     PUSH       0x14
    //         0049173d     PUSH       0x14
    //         0049173f     LEA        EDX,[ESI + 0x480]
    //                              language.dll match for 0x259f: "Multiplayer Games"
    //         00491745     PUSH       0x259f
    //         0049174a     PUSH       EDX
    //         0049174b     PUSH       ESI
    //         0049174c     MOV        this,ESI
    //         0049174e     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         00491753     TEST       EAX,EAX
    //         00491755     JZ         LAB_00491958
    //                              scr_cj.cpp:91 (36)
    //         0049175b     PUSH       EBP
    //         0049175c     PUSH       EBP
    //         0049175d     PUSH       EBP
    //         0049175e     PUSH       0x4
    //         00491760     PUSH       0x14
    //         00491762     PUSH       0x258
    //         00491767     PUSH       0x41
    //         00491769     PUSH       0x14
    //         0049176b     LEA        EAX,[ESI + 0x484]
    //                              language.dll match for 0x25a8: "Select Game to Join"
    //         00491771     PUSH       0x25a8
    //         00491776     PUSH       EAX
    //         00491777     PUSH       ESI
    //         00491778     MOV        this,ESI
    //         0049177a     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //                              scr_cj.cpp:94 (39)
    //         0049177f     PUSH       0xb
    //         00491781     PUSH       0x10e
    //         00491786     PUSH       0x258
    //         0049178b     LEA        EBP,[ESI + 0x488]
    //         00491791     PUSH       0x5a
    //         00491793     PUSH       0x14
    //         00491795     PUSH       EBP
    //         00491796     PUSH       ESI
    //         00491797     MOV        this,ESI
    //         00491799     CALL       TEasy_Panel::create_list                         int create_list(TEasy_Panel * this, TPanel * 
    //         0049179e     TEST       EAX,EAX
    //         004917a0     JZ         LAB_00491958
    //                              scr_cj.cpp:95 (28)
    //         004917a6     MOV        this,dword ptr [EBP]
    //         004917a9     PUSH       0x14
    //         004917ab     LEA        EDX,[ESI + 0x48c]
    //         004917b1     PUSH       this
    //         004917b2     PUSH       EDX
    //         004917b3     MOV        this,ESI
    //         004917b5     CALL       TEasy_Panel::create_auto_scrollbar               int create_auto_scrollbar(TEasy_Panel * this,
    //         004917ba     TEST       EAX,EAX
    //         004917bc     JZ         LAB_00491958
    //                              scr_cj.cpp:98 (22)
    //         004917c2     MOV        this,dword ptr [EBP]
    //                              language.dll match for 0x25ab: "Click Show Games to see a lis
    //         004917c5     PUSH       0x25ab
    //         004917ca     MOV        dword ptr [ESI + 0x47c],EBX
    //         004917d0     MOV        EAX,dword ptr [this->_padding_]
    //         004917d2     CALL       dword ptr [EAX + 0xe4]
    //                              scr_cj.cpp:101 (53)
    //         004917d8     PUSH       0x0
    //         004917da     PUSH       0x0=>DAT_fffffff8
    //         004917dc     PUSH       0x0=>DAT_fffffff4
    //         004917de     PUSH       offset DAT_fffffff0
    //         004917e0     PUSH       0xdc
    //         004917e5     PUSH       0x172
    //         004917ea     PUSH       0xd2
    //         004917ef     LEA        EBX,[ESI + 0x49c]
    //         004917f5     PUSH       0x0
    //                              language.dll match for 0x25a1: "Show Games"
    //         004917f7     PUSH       0x25a1
    //         004917fc     PUSH       EBX
    //         004917fd     PUSH       ESI
    //         004917fe     MOV        this,ESI
    //         00491800     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         00491805     TEST       EAX,EAX
    //         00491807     JZ         LAB_00491958
    //                              scr_cj.cpp:103 (50)
    //         0049180d     PUSH       0x0
    //         0049180f     PUSH       0x0=>DAT_fffffff8
    //         00491811     PUSH       0x0=>DAT_fffffff4
    //         00491813     PUSH       offset DAT_fffffff0
    //         00491815     PUSH       0xc8
    //         0049181a     PUSH       0x1b8
    //         0049181f     PUSH       0xa
    //         00491821     LEA        EAX,[ESI + 0x490]
    //         00491827     PUSH       0x0
    //                              language.dll match for 0x25a0: "Join"
    //         00491829     PUSH       0x25a0
    //         0049182e     PUSH       EAX
    //         0049182f     PUSH       ESI
    //         00491830     MOV        this,ESI
    //         00491832     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         00491837     TEST       EAX,EAX
    //         00491839     JZ         LAB_00491958
    //                              scr_cj.cpp:106 (53)
    //         0049183f     PUSH       0x0
    //         00491841     PUSH       0x0=>DAT_fffffff8
    //         00491843     PUSH       0x0=>DAT_fffffff4
    //         00491845     PUSH       offset DAT_fffffff0
    //         00491847     PUSH       0xc8
    //         0049184c     PUSH       0x1b8
    //         00491851     PUSH       0xdc
    //         00491856     LEA        EAX,[ESI + 0x494]
    //         0049185c     PUSH       0x0
    //                              language.dll match for 0x25a2: "Create"
    //         0049185e     PUSH       0x25a2
    //         00491863     PUSH       EAX
    //         00491864     PUSH       ESI
    //         00491865     MOV        this,ESI
    //         00491867     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         0049186c     TEST       EAX,EAX
    //         0049186e     JZ         LAB_00491958
    //                              scr_cj.cpp:108 (53)
    //         00491874     PUSH       0x0
    //         00491876     PUSH       0x0=>DAT_fffffff8
    //         00491878     PUSH       0x0=>DAT_fffffff4
    //         0049187a     PUSH       offset DAT_fffffff0
    //         0049187c     PUSH       0xc8
    //         00491881     PUSH       0x1b8
    //         00491886     PUSH       0x1ae
    //         0049188b     LEA        EDI,[ESI + 0x498]
    //         00491891     PUSH       0x0
    //                              language.dll match for 0xfa2: "Cancel"
    //         00491893     PUSH       0xfa2
    //         00491898     PUSH       EDI
    //         00491899     PUSH       ESI
    //         0049189a     MOV        this,ESI
    //         0049189c     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         004918a1     TEST       EAX,EAX
    //         004918a3     JZ         LAB_00491958
    //                              scr_cj.cpp:109 (2)
    //         004918a9     MOV        EAX,dword ptr [EDI]
    //                              scr_cj.cpp:112 (60)
    //         004918ab     PUSH       0x0
    //         004918ad     PUSH       offset DAT_fffffff8
    //         004918af     PUSH       offset DAT_fffffff4
    //         004918b1     PUSH       0x0=>DAT_fffffff0
    //         004918b3     PUSH       0x0
    //         004918b5     PUSH       0x0
    //         004918b7     MOV        dword ptr [EAX + 0x298],0x1b
    //         004918c1     MOV        dword ptr [EAX + 0x29c],0x0
    //         004918cb     PUSH       0x0
    //         004918cd     PUSH       0x0
    //         004918cf     LEA        EAX,[ESI + 0x4a0]
    //                              language.dll match for 0x3ea: "X"
    //         004918d5     PUSH       0x3ea
    //         004918da     PUSH       EAX
    //         004918db     PUSH       ESI
    //         004918dc     MOV        this,ESI
    //         004918de     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         004918e3     TEST       EAX,EAX
    //         004918e5     JZ         LAB_00491958
    //                              scr_cj.cpp:113 (13)
    //         004918e7     MOV        this,dword ptr [ESI + 0x4a0]
    //         004918ed     PUSH       0x1
    //         004918ef     MOV        EDX,dword ptr [this->_padding_]
    //         004918f1     CALL       dword ptr [EDX + 0x14]
    //                              scr_cj.cpp:114 (37)
    //         004918f4     MOV        this,dword ptr [ESI + 0x4a0]
    //         004918fa     PUSH       0x0
    //         004918fc     PUSH       0x0=>DAT_fffffff8
    //         004918fe     PUSH       0x0=>DAT_fffffff4
    //         00491900     MOV        EAX,dword ptr [this->_padding_]
    //         00491902     PUSH       0x0=>DAT_fffffff0
    //         00491904     PUSH       0x11
    //         00491906     PUSH       0x11
    //         00491908     PUSH       0x11
    //         0049190a     PUSH       0x11
    //         0049190c     PUSH       0x4
    //         0049190e     PUSH       0x4
    //         00491910     PUSH       0x4
    //         00491912     PUSH       0x4
    //         00491914     PUSH       0x9
    //         00491916     CALL       dword ptr [EAX + 0x18]
    //                              scr_cj.cpp:117 (10)
    //         00491919     MOV        this,dword ptr [EBX]
    //         0049191b     PUSH       this
    //         0049191c     MOV        this,ESI
    //         0049191e     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                              scr_cj.cpp:122 (15)
    //         00491923     MOV        this,dword ptr [ESI + 0x490]
    //         00491929     MOV        EDX,dword ptr [EBP]
    //         0049192c     MOV        EAX,dword ptr [EBX]
    //         0049192e     MOV        dword ptr [ESP + 0x1c],this
    //                              scr_cj.cpp:125 (38)
    //         00491932     LEA        this,[ESP + 0x14]
    //         00491936     MOV        dword ptr [ESP + 0x14],EDX
    //         0049193a     MOV        EDX,dword ptr [ESI + 0x494]
    //         00491940     MOV        dword ptr [ESP + 0x18],EAX
    //         00491944     MOV        EAX,dword ptr [EDI]
    //         00491946     PUSH       0x5
    //         00491948     PUSH       this=>DAT_fffffff8
    //         00491949     MOV        this,ESI
    //         0049194b     MOV        dword ptr [ESP + 0x28],EDX
    //         0049194f     MOV        dword ptr [ESP + 0x2c],EAX
    //         00491953     CALL       TPanel::set_tab_order                            void set_tab_order(TPanel * this, TPanel * * 
    //                               LAB_00491958                                                 XREF[8]:     00491755(j), 004917a0(j), 
    //                                                                                                         004917bc(j), 00491807(j), 
    //                                                                                                         00491839(j), 0049186e(j), 
    //                                                                                                         004918a3(j), 004918e5(j)  
    //                              scr_cj.cpp:126 (21)
    //         00491958     MOV        this,dword ptr [ESP + local_c]
    //         0049195c     MOV        EAX,ESI
    //         0049195e     POP        EDI
    //         0049195f     POP        ESI
    //         00491960     POP        EBP
    //         00491961     MOV        dword ptr FS:[0x0],this
    //         00491968     POP        EBX
    //         00491969     ADD        ESP,0x24
    //         0049196c     RET
    //         0049196d     ??         90h
    //         0049196e     NOP
    //         0049196f     NOP
}

TribeJoinScreen::~TribeJoinScreen() {
    /* TODO: Stub */
    //                              void __thiscall ~TribeJoinScreen(TribeJoinScreen * this)
    //              void              <VOID>         <RETURN>
    //              TribeJoinScree    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004919ba(W), 00491a56(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00491a63(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004919aa(W)  
    //                               ??1TribeJoinScreen@@UAE@XZ                                   XREF[1]:     `scalar_deleting_destructor':00491
    //                               TribeJoinScreen::~TribeJoinScreen
    //                              scr_cj.cpp:131 (36)
    //         00491990     PUSH       -0x1
    //         00491992     PUSH       FUN_0055e9c8
    //         00491997     MOV        EAX,FS:[0x0]
    //         0049199d     PUSH       EAX
    //         0049199e     MOV        dword ptr FS:[0x0],ESP
    //         004919a5     PUSH       this
    //         004919a6     PUSH       ESI
    //         004919a7     MOV        ESI,this
    //         004919a9     PUSH       EDI
    //         004919aa     MOV        dword ptr [ESP + local_10],ESI
    //         004919ae     MOV        dword ptr [ESI],TribeJoinScreen::`vftable'       = 00491970
    //                              scr_cj.cpp:133 (18)
    //         004919b4     MOV        EDI,dword ptr [Sess]                             = 00000000
    //         004919ba     MOV        dword ptr [ESP + local_4],0x0
    //         004919c2     TEST       EDI,EDI
    //         004919c4     JZ         LAB_004919d6
    //                              scr_cj.cpp:134 (16)
    //         004919c6     MOV        this,EDI
    //         004919c8     CALL       TCommunications_Sessions::~TCommunications_Ses   void ~TCommunications_Sessions(TCommunication
    //         004919cd     PUSH       EDI
    //         004919ce     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004919d3     ADD        ESP,0x4
    //                               LAB_004919d6                                                 XREF[1]:     004919c4(j)  
    //                              scr_cj.cpp:136 (14)
    //         004919d6     LEA        EAX,[ESI + 0x480]
    //         004919dc     MOV        this,ESI
    //         004919de     PUSH       EAX
    //         004919df     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_cj.cpp:137 (14)
    //         004919e4     LEA        this,[ESI + 0x484]
    //         004919ea     PUSH       this
    //         004919eb     MOV        this,ESI
    //         004919ed     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_cj.cpp:138 (14)
    //         004919f2     LEA        EDX,[ESI + 0x488]
    //         004919f8     MOV        this,ESI
    //         004919fa     PUSH       EDX
    //         004919fb     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_cj.cpp:139 (14)
    //         00491a00     LEA        EAX,[ESI + 0x48c]
    //         00491a06     MOV        this,ESI
    //         00491a08     PUSH       EAX
    //         00491a09     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_cj.cpp:140 (14)
    //         00491a0e     LEA        this,[ESI + 0x49c]
    //         00491a14     PUSH       this
    //         00491a15     MOV        this,ESI
    //         00491a17     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_cj.cpp:141 (14)
    //         00491a1c     LEA        EDX,[ESI + 0x490]
    //         00491a22     MOV        this,ESI
    //         00491a24     PUSH       EDX
    //         00491a25     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_cj.cpp:142 (14)
    //         00491a2a     LEA        EAX,[ESI + 0x494]
    //         00491a30     MOV        this,ESI
    //         00491a32     PUSH       EAX
    //         00491a33     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_cj.cpp:143 (14)
    //         00491a38     LEA        this,[ESI + 0x498]
    //         00491a3e     PUSH       this
    //         00491a3f     MOV        this,ESI
    //         00491a41     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_cj.cpp:144 (16)
    //         00491a46     LEA        EDX,[ESI + 0x4a0]
    //         00491a4c     MOV        this,ESI
    //         00491a4e     PUSH       EDX
    //         00491a4f     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         00491a54     MOV        this,ESI
    //                              scr_cj.cpp:146 (30)
    //         00491a56     MOV        dword ptr [ESP + local_4],0xffffffff
    //         00491a5e     CALL       TScreenPanel::~TScreenPanel                      void ~TScreenPanel(TScreenPanel * this)
    //         00491a63     MOV        this,dword ptr [ESP + local_c]
    //         00491a67     POP        EDI
    //         00491a68     MOV        dword ptr FS:[0x0],this
    //         00491a6f     POP        ESI
    //         00491a70     ADD        ESP,0x10
    //         00491a73     RET
    //         00491a74     ??         90h
    //         00491a75     NOP
    //         00491a76     NOP
    //         00491a77     NOP
    //         00491a78     NOP
    //         00491a79     NOP
    //         00491a7a     NOP
    //         00491a7b     NOP
    //         00491a7c     NOP
    //         00491a7d     NOP
    //         00491a7e     NOP
    //         00491a7f     NOP
}

long TribeJoinScreen::handle_idle() {
    /* TODO: Stub */
    //                              long __thiscall handle_idle(TribeJoinScreen * this)
    //              long              EAX:4          <RETURN>
    //              TribeJoinScree    ECX:4 (auto)   this
    //                               ?handle_idle@TribeJoinScreen@@UAEJXZ                         XREF[1]:     00572544(*)  
    //                               TribeJoinScreen::handle_idle
    //                              scr_cj.cpp:152 (3)
    //         00491a80     PUSH       ESI
    //         00491a81     MOV        ESI,this
    //                              scr_cj.cpp:164 (36)
    //         00491a83     MOV        EAX,dword ptr [ESI + 0x4a8]
    //         00491a89     TEST       EAX,EAX
    //         00491a8b     JNZ        LAB_00491ab6
    //         00491a8d     MOV        EAX,dword ptr [ESI + 0x47c]
    //         00491a93     TEST       EAX,EAX
    //         00491a95     JZ         LAB_00491aac
    //         00491a97     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00491a9d     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         00491aa3     TEST       EAX,EAX
    //         00491aa5     JNZ        LAB_00491aac
    //                              scr_cj.cpp:165 (5)
    //         00491aa7     CALL       RGE_Base_Game::enable_input                      void enable_input(RGE_Base_Game * this)
    //                               LAB_00491aac                                                 XREF[2]:     00491a95(j), 00491aa5(j)  
    //                              scr_cj.cpp:167 (10)
    //         00491aac     MOV        EAX,dword ptr [ESI + 0x4a8]
    //         00491ab2     TEST       EAX,EAX
    //         00491ab4     JZ         LAB_00491b15
    //                               LAB_00491ab6                                                 XREF[1]:     00491a8b(j)  
    //                              scr_cj.cpp:170 (33)
    //         00491ab6     PUSH       0xaa
    //         00491abb     PUSH       s_C:\msdev\work\age1_x1\scr_cj.cpp               = "C:\\msdev\\work\\age1_x1\\scr_cj.cpp"
    //         00491ac0     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //         00491ac5     MOV        EDX,dword ptr [ESI + 0x4ac]
    //         00491acb     ADD        ESP,0x8
    //         00491ace     SUB        EAX,EDX
    //         00491ad0     CMP        EAX,0x2710
    //         00491ad5     JBE        LAB_00491b15
    //                              scr_cj.cpp:172 (13)
    //         00491ad7     MOV        this,dword ptr [comm]                            = 00000000
    //         00491add     PUSH       0x5
    //         00491adf     CALL       TCommunications_Handler::UnlinkToLevel           COMMSTATUS UnlinkToLevel(TCommunications_Hand
    //                              scr_cj.cpp:173 (10)
    //         00491ae4     MOV        dword ptr [ESI + 0x4a8],0x0
    //                              scr_cj.cpp:174 (11)
    //         00491aee     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00491af4     CALL       RGE_Base_Game::enable_input                      void enable_input(RGE_Base_Game * this)
    //                              scr_cj.cpp:175 (21)
    //         00491af9     PUSH       0x64
    //         00491afb     PUSH       0x1c2
    //         00491b00     PUSH       0x0
    //                              language.dll match for 0x25a3: "Unable to join game."
    //         00491b02     PUSH       0x25a3
    //         00491b07     MOV        this,ESI
    //         00491b09     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, long p
    //                              scr_cj.cpp:176 (5)
    //         00491b0e     MOV        EAX,0x1
    //                              scr_cj.cpp:181 (2)
    //         00491b13     POP        ESI
    //         00491b14     RET
    //                               LAB_00491b15                                                 XREF[2]:     00491ab4(j), 00491ad5(j)  
    //                              scr_cj.cpp:180 (7)
    //         00491b15     MOV        this,ESI
    //         00491b17     CALL       TPanel::handle_idle                              long handle_idle(TPanel * this)
    //                              scr_cj.cpp:181 (2)
    //         00491b1c     POP        ESI
    //         00491b1d     RET
    //         00491b1e     ??         90h
    //         00491b1f     NOP
    return 0;
}

long TribeJoinScreen::handle_user_command(uint param_1, long param_2) {
    /* TODO: Stub */
    //                              long __thiscall handle_user_command(TribeJoinScreen * this, uint par
    //              long              EAX:4          <RETURN>
    //              TribeJoinScree    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[2]:     00491b38(R), 00491b75(W)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     00491c23(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00491b7b(W), 00491b98(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[3]:     00491bb9(R), 00491c11(R), 00491c30(R)  
    //                               ?handle_user_command@TribeJoinScreen@@UAEJIJ@Z               XREF[1]:     0057255c(*)  
    //                               TribeJoinScreen::handle_user_command
    //                              scr_cj.cpp:187 (24)
    //         00491b20     MOV        EAX,FS:[0x0]
    //         00491b26     PUSH       -0x1
    //         00491b28     PUSH       FUN_0055e9eb
    //         00491b2d     PUSH       EAX
    //         00491b2e     MOV        dword ptr FS:[0x0],ESP
    //         00491b35     PUSH       ESI
    //         00491b36     MOV        ESI,this
    //                              scr_cj.cpp:188 (34)
    //         00491b38     MOV        this,dword ptr [ESP + param_1]
    //         00491b3c     LEA        EAX,[this->_padding_ + 0xffffe85c]
    //         00491b42     CMP        EAX,0x14
    //         00491b45     JA         switchD_00491b53::caseD_17a4
    //         00491b4b     XOR        EDX,EDX
    //         00491b4d     MOV        DL,byte ptr [EAX + switchD_00491b53::switchdat
    //                               switchD_00491b53::switchD
    //         00491b53     JMP        dword ptr [EDX*0x4 + switchD_00491b53::switchd   = 00491c23
    //                               switchD_00491b53::caseD_17b8                                 XREF[2]:     00491b53(j), 00491c50(*)  
    //                              scr_cj.cpp:191 (14)
    //         00491b5a     MOV        EAX,dword ptr [ESI + 0x4a8]
    //         00491b60     TEST       EAX,EAX
    //         00491b62     JZ         switchD_00491b53::caseD_17a4
    //                              scr_cj.cpp:193 (36)
    //         00491b68     PUSH       0x890
    //         00491b6d     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00491b72     ADD        ESP,0x4
    //         00491b75     MOV        dword ptr [ESP + param_1],EAX
    //         00491b79     TEST       EAX,EAX
    //         00491b7b     MOV        dword ptr [ESP + local_4],0x0
    //         00491b83     JZ         LAB_00491b8c
    //         00491b85     MOV        this,EAX
    //         00491b87     CALL       TribeMPSetupScreen::TribeMPSetupScreen           undefined TribeMPSetupScreen(TribeMPSetupScre
    //                               LAB_00491b8c                                                 XREF[1]:     00491b83(j)  
    //                              scr_cj.cpp:194 (25)
    //         00491b8c     PUSH       0x0
    //         00491b8e     PUSH       s_MP_Setup_Screen                                = "MP Setup Screen"
    //         00491b93     MOV        this,panel_system
    //         00491b98     MOV        dword ptr [ESP + local_4],0xffffffff
    //         00491ba0     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              scr_cj.cpp:195 (15)
    //         00491ba5     PUSH       s_Join_Screen                                    = "Join Screen"
    //         00491baa     MOV        this,panel_system
    //         00491baf     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_cj.cpp:196 (5)
    //         00491bb4     MOV        EAX,0x1
    //                              scr_cj.cpp:230 (18)
    //         00491bb9     MOV        this,dword ptr [ESP + local_c]
    //         00491bbd     MOV        dword ptr FS:[0x0],this
    //         00491bc4     POP        ESI
    //         00491bc5     ADD        ESP,0xc
    //         00491bc8     RET        0x8
    //                               switchD_00491b53::caseD_17a9                                 XREF[3]:     00491b53(j), 00491c48(*), 
    //                               switchD_00491b53::caseD_17aa                                              00491c4c(*)  
    //                               switchD_00491b53::caseD_17b2
    //                               switchD_00491b53::caseD_17a8
    //                              scr_cj.cpp:212 (10)
    //         00491bcb     MOV        EAX,dword ptr [ESI + 0x4a8]
    //         00491bd1     TEST       EAX,EAX
    //         00491bd3     JZ         switchD_00491b53::caseD_17a4
    //                              scr_cj.cpp:214 (13)
    //         00491bd5     MOV        this,dword ptr [comm]                            = 00000000
    //         00491bdb     PUSH       0x5
    //         00491bdd     CALL       TCommunications_Handler::UnlinkToLevel           COMMSTATUS UnlinkToLevel(TCommunications_Hand
    //                              scr_cj.cpp:215 (10)
    //         00491be2     MOV        dword ptr [ESI + 0x4a8],0x0
    //                              scr_cj.cpp:216 (11)
    //         00491bec     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00491bf2     CALL       RGE_Base_Game::enable_input                      void enable_input(RGE_Base_Game * this)
    //                              scr_cj.cpp:220 (21)
    //         00491bf7     PUSH       0x64
    //         00491bf9     PUSH       0x1c2
    //         00491bfe     PUSH       0x0
    //                              language.dll match for 0x25a3: "Unable to join game."
    //         00491c00     PUSH       0x25a3
    //         00491c05     MOV        this,ESI
    //         00491c07     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, long p
    //                              scr_cj.cpp:221 (5)
    //         00491c0c     MOV        EAX,0x1
    //                              scr_cj.cpp:230 (18)
    //         00491c11     MOV        this,dword ptr [ESP + local_c]
    //         00491c15     MOV        dword ptr FS:[0x0],this
    //         00491c1c     POP        ESI
    //         00491c1d     ADD        ESP,0xc
    //         00491c20     RET        0x8
    //                               switchD_00491b53::caseD_17a5                                 XREF[6]:     00491b45(j), 00491b53(j), 
    //                               switchD_00491b53::caseD_17a6                                              00491b62(j), 00491bd3(j), 
    //                               switchD_00491b53::caseD_17a7                                              00491c44(*), 00491c54(*)  
    //                               switchD_00491b53::caseD_17ab
    //                               switchD_00491b53::caseD_17ac
    //                               switchD_00491b53::caseD_17ad
    //                               switchD_00491b53::caseD_17ae
    //                               switchD_00491b53::caseD_17af
    //                               switchD_00491b53::caseD_17b0
    //                               switchD_00491b53::caseD_17b1
    //                               switchD_00491b53::caseD_17b3
    //                               switchD_00491b53::caseD_17b4
    //                               switchD_00491b53::caseD_17b5
    //                               switchD_00491b53::caseD_17b6
    //                               switchD_00491b53::caseD_17b7
    //                               switchD_00491b53::caseD_17a4
    //                              scr_cj.cpp:229 (13)
    //         00491c23     MOV        EAX,dword ptr [ESP + param_2]
    //         00491c27     PUSH       EAX
    //         00491c28     PUSH       this
    //         00491c29     MOV        this,ESI
    //         00491c2b     CALL       TPanel::handle_user_command                      long handle_user_command(TPanel * this, uint 
    //                              scr_cj.cpp:230 (61)
    //         00491c30     MOV        this,dword ptr [ESP + local_c]
    //         00491c34     POP        ESI
    //         00491c35     MOV        dword ptr FS:[0x0],this
    //         00491c3c     ADD        ESP,0xc
    //         00491c3f     RET        0x8
    //                              *                                               FUNCTION                                                *
    //                              undefined FUN_00491c42()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00491c42
    //         00491c42     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_00491b53::switchdataD_00491c44                       XREF[1]:     handle_user_command:00491b53(*)  
    //         00491c44     addr       switchD_00491b53::caseD_17a4
    //         00491c48     addr       switchD_00491b53::caseD_17a8
    //         00491c4c     addr       switchD_00491b53::caseD_17a8
    //         00491c50     addr       switchD_00491b53::caseD_17b8
    //         00491c54     addr       switchD_00491b53::caseD_17a4
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_00491b53::switchdataD_00491c58                       XREF[1]:     handle_user_command:00491b4d(*)  
    //         00491c58     db         0h
    //         00491c59     db         4h
    //         00491c5a     db         4h
    //         00491c5b     db         4h
    //         00491c5c     db         1h
    //         00491c5d     db         1h
    //         00491c5e     db         1h
    //         00491c5f     db         4h
    //         00491c60     db         4h
    //         00491c61     db         4h
    //         00491c62     db         4h
    //         00491c63     db         4h
    //         00491c64     db         4h
    //         00491c65     db         4h
    //         00491c66     db         2h
    //         00491c67     db         4h
    //         00491c68     db         4h
    //         00491c69     db         4h
    //         00491c6a     db         4h
    //         00491c6b     db         4h
    //         00491c6c     db         3h
    //         00491c6d     ??         90h
    //         00491c6e     ??         90h
    //         00491c6f     ??         90h
    return 0;
}

void TribeJoinScreen::fillList() {
    /* TODO: Stub */
    //                              void __thiscall fillList(TribeJoinScreen * this)
    //              void              <VOID>         <RETURN>
    //              TribeJoinScree    ECX:4 (auto)   this
    //              char[126]         Stack[-0x90]   szTemp
    //                               ?fillList@TribeJoinScreen@@IAEXXZ                            XREF[1]:     action:00492063(c)  
    //                               TribeJoinScreen::fillList
    //                              scr_cj.cpp:235 (31)
    //         00491c70     MOV        EAX,FS:[0x0]
    //         00491c76     PUSH       -0x1
    //         00491c78     PUSH       FUN_0055ea0e
    //         00491c7d     PUSH       EAX
    //         00491c7e     MOV        dword ptr FS:[0x0],ESP
    //         00491c85     SUB        ESP,0x84
    //         00491c8b     PUSH       ESI
    //         00491c8c     PUSH       EDI
    //         00491c8d     MOV        EDI,this
    //                              scr_cj.cpp:237 (11)
    //         00491c8f     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00491c95     CALL       RGE_Base_Game::disable_input                     void disable_input(RGE_Base_Game * this)
    //                              scr_cj.cpp:241 (39)
    //         00491c9a     MOV        this,dword ptr [EDI + 0x488]
    //                              language.dll match for 0x25a9: "Looking for games..."
    //         00491ca0     PUSH       0x25a9
    //         00491ca5     MOV        dword ptr [EDI + 0x47c],0x0
    //         00491caf     MOV        dword ptr [EDI + 0x4a4],0x0
    //         00491cb9     MOV        EAX,dword ptr [this->_padding_]
    //         00491cbb     CALL       dword ptr [EAX + 0xe4]
    //                              scr_cj.cpp:242 (11)
    //         00491cc1     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00491cc7     CALL       RGE_Base_Game::draw_window                       void draw_window(RGE_Base_Game * this)
    //                              scr_cj.cpp:248 (10)
    //         00491ccc     MOV        EAX,dword ptr [EDI + 0x478]
    //         00491cd2     TEST       EAX,EAX
    //         00491cd4     JNZ        LAB_00491d52
    //                              scr_cj.cpp:250 (50)
    //         00491cd6     PUSH       0x457b0
    //         00491cdb     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00491ce0     ADD        ESP,0x4
    //         00491ce3     MOV        dword ptr [ESP + 0x8],EAX
    //         00491ce7     TEST       EAX,EAX
    //         00491ce9     MOV        dword ptr [ESP + 0x94],0x0
    //         00491cf4     JZ         LAB_00491d06
    //         00491cf6     MOV        this,dword ptr [comm]                            = 00000000
    //         00491cfc     PUSH       this
    //         00491cfd     MOV        this,EAX
    //         00491cff     CALL       TCommunications_Sessions::TCommunications_Sess   undefined TCommunications_Sessions(TCommunica
    //         00491d04     JMP        LAB_00491d08
    //                               LAB_00491d06                                                 XREF[1]:     00491cf4(j)  
    //         00491d06     XOR        EAX,EAX
    //                               LAB_00491d08                                                 XREF[1]:     00491d04(j)  
    //                              scr_cj.cpp:251 (20)
    //         00491d08     TEST       EAX,EAX
    //         00491d0a     MOV        dword ptr [ESP + 0x94],0xffffffff
    //         00491d15     MOV        [Sess],EAX                                       = 00000000
    //         00491d1a     JNZ        LAB_00491d46
    //                              scr_cj.cpp:252 (19)
    //         00491d1c     MOV        this,dword ptr [EDI + 0x488]
    //                              language.dll match for 0x25ab: "Click Show Games to see a lis
    //         00491d22     PUSH       0x25ab
    //         00491d27     MOV        EDX,dword ptr [this->_padding_]
    //         00491d29     CALL       dword ptr [EDX + 0xe4]
    //                              scr_cj.cpp:283 (23)
    //         00491d2f     MOV        this,dword ptr [ESP + 0x8c]
    //         00491d36     MOV        dword ptr FS:[0x0],this
    //         00491d3d     POP        EDI
    //         00491d3e     POP        ESI
    //         00491d3f     ADD        ESP,0x90
    //         00491d45     RET
    //                               LAB_00491d46                                                 XREF[1]:     00491d1a(j)  
    //                              scr_cj.cpp:255 (10)
    //         00491d46     MOV        dword ptr [EDI + 0x478],0x1
    //                              scr_cj.cpp:257 (2)
    //         00491d50     JMP        LAB_00491d5d
    //                               LAB_00491d52                                                 XREF[1]:     00491cd4(j)  
    //                              scr_cj.cpp:258 (11)
    //         00491d52     MOV        this,dword ptr [Sess]                            = 00000000
    //         00491d58     CALL       TCommunications_Sessions::Refresh                int Refresh(TCommunications_Sessions * this)
    //                               LAB_00491d5d                                                 XREF[1]:     00491d50(j)  
    //                              scr_cj.cpp:262 (11)
    //         00491d5d     MOV        this,dword ptr [Sess]                            = 00000000
    //         00491d63     CALL       TCommunications_Sessions::GetSessionCount        int GetSessionCount(TCommunications_Sessions 
    //                              scr_cj.cpp:265 (21)
    //         00491d68     MOV        this,dword ptr [EDI + 0x488]
    //         00491d6e     MOV        dword ptr [EDI + 0x4a4],EAX
    //         00491d74     TEST       EAX,EAX
    //         00491d76     JLE        LAB_00491def
    //         00491d78     CALL       TTextPanel::empty_list                           void empty_list(TTextPanel * this)
    //                              scr_cj.cpp:269 (12)
    //         00491d7d     MOV        EAX,dword ptr [EDI + 0x4a4]
    //         00491d83     XOR        ESI,ESI
    //         00491d85     TEST       EAX,EAX
    //         00491d87     JLE        LAB_00491ddf
    //                               LAB_00491d89                                                 XREF[1]:     00491ddd(j)  
    //                              scr_cj.cpp:271 (57)
    //         00491d89     MOV        this,dword ptr [Sess]                            = 00000000
    //         00491d8f     PUSH       ESI
    //         00491d90     CALL       TCommunications_Sessions::GetSessionMaxPlayers   ulong GetSessionMaxPlayers(TCommunications_Se
    //         00491d95     MOV        this,dword ptr [Sess]                            = 00000000
    //         00491d9b     PUSH       EAX
    //         00491d9c     PUSH       ESI
    //         00491d9d     CALL       TCommunications_Sessions::GetSessionCurrentPla   ulong GetSessionCurrentPlayers(TCommunication
    //         00491da2     MOV        this,dword ptr [Sess]                            = 00000000
    //         00491da8     PUSH       EAX
    //         00491da9     PUSH       ESI
    //         00491daa     CALL       TCommunications_Sessions::GetSessionName         char * GetSessionName(TCommunications_Session
    //         00491daf     PUSH       EAX
    //         00491db0     LEA        EAX,[ESP + 0x18]
    //         00491db4     PUSH       s_%s_(_%.1d_/_%.1d_)                             = "%s ( %.1d / %.1d )"
    //         00491db9     PUSH       EAX
    //         00491dba     CALL       sprintf                                          undefined sprintf()
    //         00491dbf     ADD        ESP,0x14
    //                              scr_cj.cpp:272 (29)
    //         00491dc2     LEA        this,[ESP + 0xc]
    //         00491dc6     PUSH       0x0
    //         00491dc8     PUSH       this
    //         00491dc9     MOV        this,dword ptr [EDI + 0x488]
    //         00491dcf     CALL       TTextPanel::append_line                          int append_line(TTextPanel * this, char * par
    //         00491dd4     MOV        EAX,dword ptr [EDI + 0x4a4]
    //         00491dda     INC        ESI
    //         00491ddb     CMP        ESI,EAX
    //         00491ddd     JL         LAB_00491d89
    //                               LAB_00491ddf                                                 XREF[1]:     00491d87(j)  
    //                              scr_cj.cpp:276 (14)
    //         00491ddf     MOV        EDX,dword ptr [EDI + 0x488]
    //         00491de5     MOV        this,EDI
    //         00491de7     PUSH       EDX
    //         00491de8     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                              scr_cj.cpp:278 (2)
    //         00491ded     JMP        LAB_00491dfc
    //                               LAB_00491def                                                 XREF[1]:     00491d76(j)  
    //                              scr_cj.cpp:279 (13)
    //         00491def     MOV        EAX,dword ptr [this->_padding_]
    //                              language.dll match for 0x25ab: "Click Show Games to see a lis
    //         00491df1     PUSH       0x25ab
    //         00491df6     CALL       dword ptr [EAX + 0xe4]
    //                               LAB_00491dfc                                                 XREF[1]:     00491ded(j)  
    //                              scr_cj.cpp:283 (33)
    //         00491dfc     MOV        this,dword ptr [ESP + 0x8c]
    //         00491e03     MOV        dword ptr [EDI + 0x47c],0x1
    //         00491e0d     POP        EDI
    //         00491e0e     MOV        dword ptr FS:[0x0],this
    //         00491e15     POP        ESI
    //         00491e16     ADD        ESP,0x90
    //         00491e1c     RET
    //         00491e1d     ??         90h
    //         00491e1e     NOP
    //         00491e1f     NOP
    //                              * public: virtual long __thiscall TribeJoinScreen::action(class TPanel *,long,unsigned long,unsigned... *
    //                              long __thiscall action(TribeJoinScreen * this, TPanel * param_1, lon
    //              long              EAX:4          <RETURN>
    //              TribeJoinScree    ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     00491e32(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[3]:     00491e2d(R), 00491e9e(R), 00491f96(R)  
    //              ulong             Stack[0xc]:4   param_3                   XREF[1]:     00492096(R)  
    //              ulong             Stack[0x10]:4  param_4                   XREF[1]:     0049208e(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     00491fcf(W), 00491fef(W), 00492038(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004920a7(R)  
    //              char[256]         Stack[-0x110   string                    XREF[0,2]:   00491f01(*), 00491f12(*)  
    //              char[256]         Stack[-0x210   temp                      XREF[2,2]:   00491fc9(W), 00492032(W), 00491edb(*), 00491efd(*)  
    //                               ?action@TribeJoinScreen@@UAEJPAVTPanel@@JKK@Z                XREF[1]:     005725ac(*)  
    //                               TribeJoinScreen::action
    //                              scr_cj.cpp:289 (13)
    //         00491e20     MOV        EAX,FS:[0x0]
    //         00491e26     PUSH       -0x1
    //         00491e28     PUSH       FUN_0055ea3c
    //                              scr_cj.cpp:290 (33)
    //         00491e2d     MOV        EDX,dword ptr [ESP + param_2]
    //         00491e31     PUSH       EAX
    //         00491e32     MOV        EAX,dword ptr [ESP + param_1]
    //         00491e36     MOV        dword ptr FS:[0x0],ESP
    //         00491e3d     SUB        ESP,0x204
    //         00491e43     TEST       EAX,EAX
    //         00491e45     PUSH       ESI
    //         00491e46     MOV        ESI,this
    //         00491e48     JZ         LAB_0049208e
    //                              scr_cj.cpp:291 (10)
    //         00491e4e     MOV        this,dword ptr [ESI + 0x488]
    //         00491e54     CMP        EAX,this
    //         00491e56     JNZ        LAB_00491e92
    //                              scr_cj.cpp:292 (25)
    //         00491e58     MOV        EAX,EDX
    //         00491e5a     CMP        EAX,0x3
    //         00491e5d     JNZ        LAB_00492087
    //         00491e63     MOV        EAX,dword ptr [ESI + 0x4a4]
    //         00491e69     TEST       EAX,EAX
    //         00491e6b     JLE        LAB_00492087
    //                              scr_cj.cpp:293 (23)
    //         00491e71     MOV        this,dword ptr [ESI + 0x490]
    //         00491e77     MOV        EAX,dword ptr [ESI]
    //         00491e79     PUSH       0x0
    //         00491e7b     PUSH       0x0
    //         00491e7d     PUSH       0x1
    //         00491e7f     PUSH       this
    //         00491e80     MOV        this,ESI
    //         00491e82     CALL       dword ptr [EAX + 0xb4]
    //                              scr_cj.cpp:294 (10)
    //         00491e88     MOV        EAX,0x1
    //         00491e8d     JMP        LAB_004920a7
    //                               LAB_00491e92                                                 XREF[1]:     00491e56(j)  
    //                              scr_cj.cpp:296 (12)
    //         00491e92     CMP        EAX,dword ptr [ESI + 0x490]
    //         00491e98     JNZ        LAB_00491f8a
    //                              scr_cj.cpp:297 (14)
    //         00491e9e     CMP        dword ptr [ESP + param_2],0x1
    //         00491ea6     JNZ        LAB_00492087
    //                              scr_cj.cpp:303 (14)
    //         00491eac     MOV        EAX,dword ptr [ESI + 0x4a4]
    //         00491eb2     TEST       EAX,EAX
    //         00491eb4     JLE        LAB_00491f6b
    //                              scr_cj.cpp:305 (33)
    //         00491eba     CALL       TTextPanel::currentLineNumber                    int currentLineNumber(TTextPanel * this)
    //         00491ebf     MOV        this,dword ptr [Sess]                            = 00000000
    //         00491ec5     PUSH       EAX
    //         00491ec6     CALL       TCommunications_Sessions::GetSessionGUID         _GUID * GetSessionGUID(TCommunications_Sessio
    //         00491ecb     MOV        this,dword ptr [comm]                            = 00000000
    //         00491ed1     PUSH       EAX
    //         00491ed2     CALL       TCommunications_Handler::JoinMultiplayerGame     int JoinMultiplayerGame(TCommunications_Handl
    //         00491ed7     TEST       EAX,EAX
    //         00491ed9     JNZ        LAB_00491f34
    //                              scr_cj.cpp:308 (22)
    //         00491edb     LEA        EDX=>temp[4],[ESP + 0x8]
    //         00491edf     PUSH       0x100
    //         00491ee4     PUSH       EDX
    //                              language.dll match for 0x25a3: "Unable to join game."
    //         00491ee5     PUSH       0x25a3
    //         00491eea     MOV        this,ESI
    //         00491eec     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
    //                              scr_cj.cpp:309 (33)
    //         00491ef1     MOV        this,dword ptr [ESI + 0x488]
    //         00491ef7     CALL       TTextPanel::currentLine                          char * currentLine(TTextPanel * this)
    //         00491efc     PUSH       EAX
    //         00491efd     LEA        EAX=>temp[4],[ESP + 0xc]
    //         00491f01     LEA        this=>string[4],[ESP + 0x10c]
    //         00491f08     PUSH       EAX
    //         00491f09     PUSH       this
    //         00491f0a     CALL       sprintf                                          undefined sprintf()
    //         00491f0f     ADD        ESP,0xc
    //                              scr_cj.cpp:310 (24)
    //         00491f12     LEA        EDX=>string[4],[ESP + 0x108]
    //         00491f19     MOV        this,ESI
    //         00491f1b     PUSH       0x64
    //         00491f1d     PUSH       0x1c2
    //         00491f22     PUSH       0x0
    //         00491f24     PUSH       EDX
    //         00491f25     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, char *
    //                              scr_cj.cpp:315 (10)
    //         00491f2a     MOV        EAX,0x1
    //         00491f2f     JMP        LAB_004920a7
    //                               LAB_00491f34                                                 XREF[1]:     00491ed9(j)  
    //                              scr_cj.cpp:318 (11)
    //         00491f34     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00491f3a     CALL       RGE_Base_Game::disable_input                     void disable_input(RGE_Base_Game * this)
    //                              scr_cj.cpp:320 (34)
    //         00491f3f     PUSH       0x140
    //         00491f44     PUSH       s_C:\msdev\work\age1_x1\scr_cj.cpp               = "C:\\msdev\\work\\age1_x1\\scr_cj.cpp"
    //         00491f49     MOV        dword ptr [ESI + 0x4a8],0x1
    //         00491f53     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //         00491f58     MOV        dword ptr [ESI + 0x4ac],EAX
    //         00491f5e     ADD        ESP,0x8
    //                              scr_cj.cpp:326 (10)
    //         00491f61     MOV        EAX,0x1
    //         00491f66     JMP        LAB_004920a7
    //                               LAB_00491f6b                                                 XREF[1]:     00491eb4(j)  
    //                              scr_cj.cpp:330 (21)
    //         00491f6b     PUSH       0x64
    //         00491f6d     PUSH       0x1c2
    //         00491f72     PUSH       0x0
    //                              language.dll match for 0x25a4: "There are no games to join."
    //         00491f74     PUSH       0x25a4
    //         00491f79     MOV        this,ESI
    //         00491f7b     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, long p
    //                              scr_cj.cpp:333 (10)
    //         00491f80     MOV        EAX,0x1
    //         00491f85     JMP        LAB_004920a7
    //                               LAB_00491f8a                                                 XREF[1]:     00491e98(j)  
    //                              scr_cj.cpp:335 (12)
    //         00491f8a     CMP        EAX,dword ptr [ESI + 0x498]
    //         00491f90     JNZ        LAB_00492018
    //                              scr_cj.cpp:336 (14)
    //         00491f96     CMP        dword ptr [ESP + param_2],0x1
    //         00491f9e     JNZ        LAB_00492087
    //                              scr_cj.cpp:337 (11)
    //         00491fa4     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00491faa     CALL       RGE_Base_Game::disable_input                     void disable_input(RGE_Base_Game * this)
    //                              scr_cj.cpp:340 (13)
    //         00491faf     MOV        this,dword ptr [comm]                            = 00000000
    //         00491fb5     PUSH       0x2
    //         00491fb7     CALL       TCommunications_Handler::UnlinkToLevel           COMMSTATUS UnlinkToLevel(TCommunications_Hand
    //                              scr_cj.cpp:341 (39)
    //         00491fbc     PUSH       0x6a0
    //         00491fc1     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00491fc6     ADD        ESP,0x4
    //         00491fc9     MOV        dword ptr [ESP + temp[0]],EAX
    //         00491fcd     TEST       EAX,EAX
    //         00491fcf     MOV        dword ptr [ESP + local_4],0x0
    //         00491fda     JZ         LAB_00491fe3
    //         00491fdc     MOV        this,EAX
    //         00491fde     CALL       TribeMPStartupScreen::TribeMPStartupScreen       undefined TribeMPStartupScreen(TribeMPStartup
    //                               LAB_00491fe3                                                 XREF[1]:     00491fda(j)  
    //                              scr_cj.cpp:342 (28)
    //         00491fe3     PUSH       0x0
    //         00491fe5     PUSH       s_MP_Startup_Screen                              = "MP Startup Screen"
    //         00491fea     MOV        this,panel_system
    //         00491fef     MOV        dword ptr [ESP + local_4],0xffffffff
    //         00491ffa     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              scr_cj.cpp:343 (15)
    //         00491fff     PUSH       s_Join_Screen                                    = "Join Screen"
    //         00492004     MOV        this,panel_system
    //         00492009     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_cj.cpp:345 (10)
    //         0049200e     MOV        EAX,0x1
    //         00492013     JMP        LAB_004920a7
    //                               LAB_00492018                                                 XREF[1]:     00491f90(j)  
    //                              scr_cj.cpp:348 (13)
    //         00492018     CMP        EAX,dword ptr [ESI + 0x494]
    //         0049201e     JNZ        LAB_00492054
    //         00492020     CMP        EDX,0x1
    //         00492023     JNZ        LAB_00492054
    //                              scr_cj.cpp:349 (40)
    //         00492025     PUSH       0x4a4
    //         0049202a     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0049202f     ADD        ESP,0x4
    //         00492032     MOV        dword ptr [ESP + temp[0]],EAX
    //         00492036     TEST       EAX,EAX
    //         00492038     MOV        dword ptr [ESP + local_4],0x1
    //         00492043     JZ         LAB_00492087
    //         00492045     PUSH       ESI
    //         00492046     MOV        this,EAX
    //         00492048     CALL       TribeMPCreateDialog::TribeMPCreateDialog         undefined TribeMPCreateDialog(TribeMPCreateDi
    //                              scr_cj.cpp:350 (7)
    //         0049204d     MOV        EAX,0x1
    //         00492052     JMP        LAB_004920a7
    //                               LAB_00492054                                                 XREF[2]:     0049201e(j), 00492023(j)  
    //                              scr_cj.cpp:352 (8)
    //         00492054     CMP        EAX,dword ptr [ESI + 0x49c]
    //         0049205a     JNZ        LAB_0049206f
    //                              scr_cj.cpp:353 (5)
    //         0049205c     CMP        EDX,0x1
    //         0049205f     JNZ        LAB_00492087
    //                              scr_cj.cpp:354 (7)
    //         00492061     MOV        this,ESI
    //         00492063     CALL       TribeJoinScreen::fillList                        void fillList(TribeJoinScreen * this)
    //                              scr_cj.cpp:356 (7)
    //         00492068     MOV        EAX,0x1
    //         0049206d     JMP        LAB_004920a7
    //                               LAB_0049206f                                                 XREF[1]:     0049205a(j)  
    //                              scr_cj.cpp:359 (13)
    //         0049206f     CMP        EAX,dword ptr [ESI + 0x4a0]
    //         00492075     JNZ        LAB_0049208e
    //         00492077     CMP        EDX,0x1
    //         0049207a     JNZ        LAB_0049208e
    //                              scr_cj.cpp:361 (11)
    //         0049207c     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00492082     CALL       RGE_Base_Game::close                             void close(RGE_Base_Game * this)
    //                               LAB_00492087                                                 XREF[6]:     00491e5d(j), 00491e6b(j), 
    //                                                                                                         00491ea6(j), 00491f9e(j), 
    //                                                                                                         00492043(j), 0049205f(j)  
    //                              scr_cj.cpp:362 (7)
    //         00492087     MOV        EAX,0x1
    //         0049208c     JMP        LAB_004920a7
    //                               LAB_0049208e                                                 XREF[3]:     00491e48(j), 00492075(j), 
    //                                                                                                         0049207a(j)  
    //                              scr_cj.cpp:367 (25)
    //         0049208e     MOV        this,dword ptr [ESP + param_4]
    //         00492095     PUSH       this
    //         00492096     MOV        this,dword ptr [ESP + param_3]
    //         0049209d     PUSH       this
    //         0049209e     PUSH       EDX
    //         0049209f     PUSH       EAX
    //         004920a0     MOV        this,ESI
    //         004920a2     CALL       TEasy_Panel::action                              long action(TEasy_Panel * this, TPanel * para
    //                               LAB_004920a7                                                 XREF[8]:     00491e8d(j), 00491f2f(j), 
    //                                                                                                         00491f66(j), 00491f85(j), 
    //                                                                                                         00492013(j), 00492052(j), 
    //                                                                                                         0049206d(j), 0049208c(j)  
    //                              scr_cj.cpp:368 (24)
    //         004920a7     MOV        this,dword ptr [ESP + local_c]
    //         004920ae     MOV        dword ptr FS:[0x0],this
    //         004920b5     POP        ESI
    //         004920b6     ADD        ESP,0x210
    //         004920bc     RET        0x10
    //         004920bf     ??         90h
    return;
}

TribeMPCreateDialog::TribeMPCreateDialog(TPanel* param_1) {
    /* TODO: Stub */
    //                              undefined __thiscall TribeMPCreateDialog(TribeMPCreateDialog * this,
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TribeMPCreateD    ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     004920ef(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00492106(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004922e6(R)  
    //              char[256]         Stack[-0x110   str                       XREF[1,3]:   004920e6(W), 004921f9(*), 00492217(W), 0049222f(*)  
    //              undefined4        Stack[-0x114   local_114                 XREF[1]:     004922cc(W)  
    //              TPanel *[3]       Stack[-0x120   tab_list                  XREF[0,3]:   004922c4(W), 004922c8(*), 004922d3(W)  
    //                               ??0TribeMPCreateDialog@@QAE@PAVTPanel@@@Z                    XREF[1]:     action:00492048(c)  
    //                               TribeMPCreateDialog::TribeMPCreateDialog
    //                              scr_cj.cpp:375 (47)
    //         004920c0     PUSH       -0x1
    //         004920c2     PUSH       FUN_0055ea5b
    //         004920c7     MOV        EAX,FS:[0x0]
    //         004920cd     PUSH       EAX
    //         004920ce     MOV        dword ptr FS:[0x0],ESP
    //         004920d5     SUB        ESP,0x110
    //         004920db     PUSH       EBX
    //         004920dc     PUSH       EBP
    //         004920dd     PUSH       ESI
    //         004920de     PUSH       EDI
    //         004920df     MOV        EBP,this
    //         004920e1     PUSH       s_Create_Dialog                                  = "Create Dialog"
    //         004920e6     MOV        dword ptr [ESP + str[0]],EBP
    //         004920ea     CALL       TDialogPanel::TDialogPanel                       undefined TDialogPanel(TDialogPanel * this, c
    //                              scr_cj.cpp:382 (131)
    //         004920ef     MOV        ESI,dword ptr [ESP + param_1]
    //         004920f6     LEA        EDI,[EBP + 0x490]
    //         004920fc     LEA        EBX,[EBP + 0x498]
    //         00492102     PUSH       0x1
    //         00492104     MOV        this,ESI
    //         00492106     MOV        dword ptr [ESP + local_4],0x0
    //         00492111     MOV        dword ptr [EBP],TribeMPCreateDialog::`vftable'   = 00492310
    //         00492118     MOV        dword ptr [EDI],0x0
    //         0049211e     MOV        dword ptr [EBP + 0x494],0x0
    //         00492128     MOV        dword ptr [EBX],0x0
    //         0049212e     MOV        dword ptr [EBP + 0x49c],0x0
    //         00492138     MOV        dword ptr [EBP + 0x4a0],0x0
    //         00492142     CALL       TEasy_Panel::get_popup_info_id                   long get_popup_info_id(TEasy_Panel * this)
    //         00492147     PUSH       EAX
    //         00492148     MOV        this,ESI
    //         0049214a     CALL       TEasy_Panel::get_popup_info_file                 char * get_popup_info_file(TEasy_Panel * this)
    //         0049214f     PUSH       EAX
    //         00492150     PUSH       0xe6
    //         00492155     PUSH       0x1f4
    //         0049215a     PUSH       ESI
    //         0049215b     MOV        this,ESI
    //         0049215d     CALL       TPanel::renderArea                               TDrawArea * renderArea(TPanel * this)
    //         00492162     PUSH       EAX
    //         00492163     MOV        this,EBP
    //         00492165     CALL       TDialogPanel::setup                              int setup(TDialogPanel * this, TDrawArea * pa
    //         0049216a     TEST       EAX,EAX
    //         0049216c     JZ         LAB_004922e6
    //                              scr_cj.cpp:387 (41)
    //         00492172     PUSH       0x0
    //         00492174     PUSH       0x1
    //         00492176     PUSH       0x1
    //         00492178     PUSH       0x1
    //         0049217a     PUSH       0x1e
    //         0049217c     PUSH       0x1cc
    //         00492181     PUSH       0x14
    //         00492183     PUSH       0x14
    //                              language.dll match for 0x25a6: "Create Game"
    //         00492185     PUSH       0x25a6
    //         0049218a     PUSH       EDI
    //         0049218b     PUSH       EBP
    //         0049218c     MOV        this,EBP
    //         0049218e     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         00492193     TEST       EAX,EAX
    //         00492195     JZ         LAB_004922e6
    //                              scr_cj.cpp:389 (47)
    //         0049219b     PUSH       0x0
    //         0049219d     PUSH       0x1
    //         0049219f     PUSH       0x0
    //         004921a1     PUSH       0x4
    //         004921a3     PUSH       0x14
    //         004921a5     PUSH       0x1a4
    //         004921aa     PUSH       0x55
    //         004921ac     PUSH       0x28
    //         004921ae     LEA        EAX,[EBP + 0x494]
    //                              language.dll match for 0x25aa: "Game Name"
    //         004921b4     PUSH       0x25aa
    //         004921b9     PUSH       EAX
    //         004921ba     PUSH       EBP
    //         004921bb     MOV        this,EBP
    //         004921bd     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         004921c2     TEST       EAX,EAX
    //         004921c4     JZ         LAB_004922e6
    //                              scr_cj.cpp:392 (22)
    //         004921ca     MOV        this,dword ptr [Regs]                            = 00000000
    //         004921d0     PUSH       s_Default_Age_Of_Empires_MP_Gamena               = "Default Age Of Empires MP Gamename"
    //         004921d5     PUSH       0x1
    //         004921d7     CALL       TRegistry::RegGetAscii                           char * RegGetAscii(TRegistry * this, int para
    //         004921dc     TEST       EAX,EAX
    //         004921de     JZ         LAB_00492217
    //                              scr_cj.cpp:393 (53)
    //         004921e0     MOV        this,dword ptr [Regs]                            = 00000000
    //         004921e6     PUSH       s_Default_Age_Of_Empires_MP_Gamena               = "Default Age Of Empires MP Gamename"
    //         004921eb     PUSH       0x1
    //         004921ed     CALL       TRegistry::RegGetAscii                           char * RegGetAscii(TRegistry * this, int para
    //         004921f2     MOV        EDI,EAX
    //         004921f4     OR         this,0xffffffff
    //         004921f7     XOR        EAX,EAX
    //         004921f9     LEA        EDX=>str[4],[ESP + 0x20]
    //         004921fd     SCASB.RE   ES:EDI
    //         004921ff     NOT        this
    //         00492201     SUB        EDI,this
    //         00492203     MOV        EAX,this
    //         00492205     MOV        ESI,EDI
    //         00492207     MOV        EDI,EDX
    //         00492209     SHR        this,0x2
    //         0049220c     MOVSD.REP  ES:EDI,ESI
    //         0049220e     MOV        this,EAX
    //         00492210     AND        this,0x3
    //         00492213     MOVSB.REP  ES:EDI,ESI
    //                              scr_cj.cpp:394 (2)
    //         00492215     JMP        LAB_0049221c
    //                               LAB_00492217                                                 XREF[1]:     004921de(j)  
    //                              scr_cj.cpp:395 (5)
    //         00492217     MOV        byte ptr [ESP + str[4]],0x0
    //                               LAB_0049221c                                                 XREF[1]:     00492215(j)  
    //                              scr_cj.cpp:397 (43)
    //         0049221c     PUSH       0x0
    //         0049221e     PUSH       0x1
    //         00492220     PUSH       0xb
    //         00492222     PUSH       0x17
    //         00492224     PUSH       0x1a4
    //                              language.dll match for 0x6e: "Copperplate Gothic Light"
    //         00492229     PUSH       0x6e
    //         0049222b     PUSH       0x28
    //         0049222d     PUSH       0x0
    //         0049222f     LEA        this=>str[4],[ESP + 0x40]
    //         00492233     PUSH       0x28
    //         00492235     PUSH       this
    //         00492236     PUSH       EBX
    //         00492237     PUSH       EBP
    //         00492238     MOV        this,EBP
    //         0049223a     CALL       TEasy_Panel::create_edit                         int create_edit(TEasy_Panel * this, TPanel * 
    //         0049223f     TEST       EAX,EAX
    //         00492241     JZ         LAB_004922e6
    //                              scr_cj.cpp:399 (46)
    //         00492247     PUSH       0x0
    //         00492249     PUSH       0x0
    //         0049224b     PUSH       0x0
    //         0049224d     PUSH       0x1e
    //         0049224f     PUSH       0xb4
    //         00492254     PUSH       0xb4
    //         00492259     PUSH       0x3c
    //         0049225b     PUSH       0x0
    //         0049225d     LEA        EDI,[EBP + 0x49c]
    //                              language.dll match for 0xfa1: "OK"
    //         00492263     PUSH       0xfa1
    //         00492268     PUSH       EDI
    //         00492269     PUSH       EBP
    //         0049226a     MOV        this,EBP
    //         0049226c     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         00492271     TEST       EAX,EAX
    //         00492273     JZ         LAB_004922e6
    //                              scr_cj.cpp:400 (49)
    //         00492275     PUSH       0x0
    //         00492277     PUSH       0x0
    //         00492279     PUSH       0x0
    //         0049227b     PUSH       0x1e
    //         0049227d     PUSH       0xb4
    //         00492282     PUSH       0xb4
    //         00492287     PUSH       0x104
    //         0049228c     PUSH       0x0
    //         0049228e     LEA        ESI,[EBP + 0x4a0]
    //                              language.dll match for 0xfa2: "Cancel"
    //         00492294     PUSH       0xfa2
    //         00492299     PUSH       ESI
    //         0049229a     PUSH       EBP
    //         0049229b     MOV        this,EBP
    //         0049229d     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         004922a2     TEST       EAX,EAX
    //         004922a4     JZ         LAB_004922e6
    //                              scr_cj.cpp:401 (2)
    //         004922a6     MOV        EAX,dword ptr [ESI]
    //                              scr_cj.cpp:408 (52)
    //         004922a8     PUSH       0x3
    //         004922aa     MOV        dword ptr [EAX + 0x298],0x1b
    //         004922b4     MOV        dword ptr [EAX + 0x29c],0x0
    //         004922be     MOV        EDX,dword ptr [EBX]
    //         004922c0     MOV        this,dword ptr [ESI]
    //         004922c2     MOV        EAX,dword ptr [EDI]
    //         004922c4     MOV        dword ptr [ESP + tab_list[1]],EDX
    //         004922c8     LEA        EDX=>tab_list[1],[ESP + 0x14]
    //         004922cc     MOV        dword ptr [ESP + local_114],this
    //         004922d0     PUSH       EDX
    //         004922d1     MOV        this,EBP
    //         004922d3     MOV        dword ptr [ESP + tab_list[2]],EAX
    //         004922d7     CALL       TPanel::set_tab_order                            void set_tab_order(TPanel * this, TPanel * * 
    //                              scr_cj.cpp:411 (10)
    //         004922dc     MOV        EAX,dword ptr [EBX]
    //         004922de     MOV        this,EBP
    //         004922e0     PUSH       EAX
    //         004922e1     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                               LAB_004922e6                                                 XREF[6]:     0049216c(j), 00492195(j), 
    //                                                                                                         004921c4(j), 00492241(j), 
    //                                                                                                         00492273(j), 004922a4(j)  
    //                              scr_cj.cpp:412 (29)
    //         004922e6     MOV        this,dword ptr [ESP + local_c]
    //         004922ed     POP        EDI
    //         004922ee     MOV        EAX,EBP
    //         004922f0     POP        ESI
    //         004922f1     POP        EBP
    //         004922f2     MOV        dword ptr FS:[0x0],this
    //         004922f9     POP        EBX
    //         004922fa     ADD        ESP,0x11c
    //         00492300     RET        0x4
    //         00492303     ??         90h
    //         00492304     NOP
    //         00492305     NOP
    //         00492306     NOP
    //         00492307     NOP
    //         00492308     NOP
    //         00492309     NOP
    //         0049230a     NOP
    //         0049230b     NOP
    //         0049230c     NOP
    //         0049230d     NOP
    //         0049230e     NOP
    //         0049230f     NOP
}

TribeMPCreateDialog::~TribeMPCreateDialog() {
    /* TODO: Stub */
    //                              void __thiscall ~TribeMPCreateDialog(TribeMPCreateDialog * this)
    //              void              <VOID>         <RETURN>
    //              TribeMPCreateD    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00492359(W), 004923a1(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004923ae(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00492349(W)  
    //                               ??1TribeMPCreateDialog@@UAE@XZ                               XREF[1]:     `vector_deleting_destructor':00492
    //                               TribeMPCreateDialog::~TribeMPCreateDialog
    //                              scr_cj.cpp:418 (35)
    //         00492330     PUSH       -0x1
    //         00492332     PUSH       FUN_0055ea78
    //         00492337     MOV        EAX,FS:[0x0]
    //         0049233d     PUSH       EAX
    //         0049233e     MOV        dword ptr FS:[0x0],ESP
    //         00492345     PUSH       this
    //         00492346     PUSH       ESI
    //         00492347     MOV        ESI,this
    //         00492349     MOV        dword ptr [ESP + local_10],ESI
    //         0049234d     MOV        dword ptr [ESI],TribeMPCreateDialog::`vftable'   = 00492310
    //                              scr_cj.cpp:419 (20)
    //         00492353     LEA        EAX,[ESI + 0x490]
    //         00492359     MOV        dword ptr [ESP + local_4],0x0
    //         00492361     PUSH       EAX
    //         00492362     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_cj.cpp:420 (14)
    //         00492367     LEA        this,[ESI + 0x494]
    //         0049236d     PUSH       this
    //         0049236e     MOV        this,ESI
    //         00492370     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_cj.cpp:421 (14)
    //         00492375     LEA        EDX,[ESI + 0x498]
    //         0049237b     MOV        this,ESI
    //         0049237d     PUSH       EDX
    //         0049237e     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_cj.cpp:422 (14)
    //         00492383     LEA        EAX,[ESI + 0x49c]
    //         00492389     MOV        this,ESI
    //         0049238b     PUSH       EAX
    //         0049238c     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_cj.cpp:423 (16)
    //         00492391     LEA        this,[ESI + 0x4a0]
    //         00492397     PUSH       this
    //         00492398     MOV        this,ESI
    //         0049239a     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         0049239f     MOV        this,ESI
    //                              scr_cj.cpp:424 (29)
    //         004923a1     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004923a9     CALL       TDialogPanel::~TDialogPanel                      void ~TDialogPanel(TDialogPanel * this)
    //         004923ae     MOV        this,dword ptr [ESP + local_c]
    //         004923b2     POP        ESI
    //         004923b3     MOV        dword ptr FS:[0x0],this
    //         004923ba     ADD        ESP,0x10
    //         004923bd     RET
    //         004923be     ??         90h
    //         004923bf     NOP
    //                              * protected: virtual long __thiscall TribeMPCreateDialog::action(class TPanel *,long,unsigned long,u... *
    //                              long __thiscall action(TribeMPCreateDialog * this, TPanel * param_1,
    //              long              EAX:4          <RETURN>
    //              TribeMPCreateD    ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     004923ce(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     004923e3(R)  
    //              ulong             Stack[0xc]:4   param_3                   XREF[1]:     004926b3(R)  
    //              ulong             Stack[0x10]:4  param_4                   XREF[1]:     004926ae(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004926c1(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004924fa(W)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[1]:     004924f1(W)  
    //              undefined4        Stack[-0x18]:4 local_18                  XREF[1]:     004924ea(W)  
    //              undefined4        Stack[-0x1c]:4 local_1c                  XREF[2]:     004924d3(*), 004924e3(W)  
    //                               ?action@TribeMPCreateDialog@@MAEJPAVTPanel@@JKK@Z            XREF[1]:     005726d4(*)  
    //                               TribeMPCreateDialog::action
    //                              scr_cj.cpp:430 (14)
    //         004923c0     MOV        EAX,FS:[0x0]
    //         004923c6     PUSH       -0x1
    //         004923c8     PUSH       FUN_0055ea9b
    //         004923cd     PUSH       EAX
    //                              scr_cj.cpp:434 (32)
    //         004923ce     MOV        EAX,dword ptr [ESP + param_1]
    //         004923d2     MOV        dword ptr FS:[0x0],ESP
    //         004923d9     SUB        ESP,0x10
    //         004923dc     TEST       EAX,EAX
    //         004923de     PUSH       EBX
    //         004923df     PUSH       EBP
    //         004923e0     MOV        EBX,this
    //         004923e2     PUSH       ESI
    //         004923e3     MOV        this,dword ptr [ESP + param_2]
    //         004923e7     PUSH       EDI
    //         004923e8     JZ         LAB_004926ae
    //                              scr_cj.cpp:438 (35)
    //         004923ee     CMP        EAX,dword ptr [EBX + 0x49c]
    //         004923f4     JNZ        LAB_004923fb
    //         004923f6     CMP        this,0x1
    //         004923f9     JZ         LAB_00492411
    //                               LAB_004923fb                                                 XREF[1]:     004923f4(j)  
    //         004923fb     MOV        EDX,dword ptr [EBX + 0x498]
    //         00492401     CMP        EAX,EDX
    //         00492403     JNZ        LAB_00492671
    //         00492409     TEST       this,this
    //         0049240b     JNZ        LAB_00492671
    //                               LAB_00492411                                                 XREF[1]:     004923f9(j)  
    //                              scr_cj.cpp:441 (15)
    //         00492411     MOV        this,dword ptr [EBX + 0x498]
    //         00492417     CALL       TEditPanel::is_blank                             int is_blank(TEditPanel * this)
    //         0049241c     TEST       EAX,EAX
    //         0049241e     JZ         LAB_00492438
    //                              scr_cj.cpp:442 (14)
    //         00492420     MOV        EAX,dword ptr [EBX + 0x498]
    //         00492426     MOV        this,EBX
    //         00492428     PUSH       EAX
    //         00492429     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                              scr_cj.cpp:444 (10)
    //         0049242e     MOV        EAX,0x1
    //         00492433     JMP        LAB_004926c1
    //                               LAB_00492438                                                 XREF[1]:     0049241e(j)  
    //                              scr_cj.cpp:447 (11)
    //         00492438     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0049243e     CALL       RGE_Base_Game::disable_input                     void disable_input(RGE_Base_Game * this)
    //                              scr_cj.cpp:452 (53)
    //         00492443     MOV        this,dword ptr [EBX + 0x498]
    //         00492449     CALL       TEditPanel::currentLine                          char * currentLine(TEditPanel * this)
    //         0049244e     MOV        EDI,EAX
    //         00492450     OR         this,0xffffffff
    //         00492453     XOR        EAX,EAX
    //         00492455     SCASB.RE   ES:EDI
    //         00492457     NOT        this
    //         00492459     PUSH       this
    //         0049245a     MOV        this,dword ptr [EBX + 0x498]
    //         00492460     CALL       TEditPanel::currentLine                          char * currentLine(TEditPanel * this)
    //         00492465     MOV        this,dword ptr [Regs]                            = 00000000
    //         0049246b     PUSH       EAX
    //         0049246c     PUSH       s_Default_Age_Of_Empires_MP_Gamena               = "Default Age Of Empires MP Gamename"
    //         00492471     PUSH       0x1
    //         00492473     CALL       TRegistry::RegSetAscii                           int RegSetAscii(TRegistry * this, int param_1
    //                              scr_cj.cpp:453 (23)
    //         00492478     MOV        this,dword ptr [EBX + 0x498]
    //         0049247e     CALL       TEditPanel::currentLine                          char * currentLine(TEditPanel * this)
    //         00492483     MOV        this,dword ptr [comm]                            = 00000000
    //         00492489     PUSH       EAX
    //         0049248a     CALL       TCommunications_Handler::SetGameTitle            int SetGameTitle(TCommunications_Handler * th
    //                              scr_cj.cpp:458 (23)
    //         0049248f     MOV        this,dword ptr [L]                               = 00000000
    //         00492495     MOV        EBP,dword ptr [EBX + 0x20]
    //         00492498     PUSH       s_$$$_CALLING_CreateMultiplayerGam               = "$$$ CALLING CreateMultiplayerGame"
    //         0049249d     PUSH       this
    //         0049249e     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         004924a3     ADD        ESP,0x8
    //                              scr_cj.cpp:460 (17)
    //         004924a6     MOV        this,panel_system
    //         004924ab     PUSH       0x0
    //         004924ad     PUSH       s_Join_Screen                                    = "Join Screen"
    //         004924b2     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              scr_cj.cpp:461 (11)
    //         004924b7     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004924bd     CALL       RGE_Base_Game::draw_window                       void draw_window(RGE_Base_Game * this)
    //                              scr_cj.cpp:463 (21)
    //         004924c2     MOV        EDX,dword ptr [comm]                             = 00000000
    //         004924c8     MOV        EDI,_DPSPGUID_TCPIP                              = E0h
    //         004924cd     ADD        EDX,0x12dc
    //         004924d3     LEA        ESI=>local_1c,[ESP + 0x10]
    //                              scr_cj.cpp:464 (53)
    //         004924d7     PUSH       0xc385
    //         004924dc     PUSH       s_scr3                                           = 73h
    //         004924e1     MOV        EAX,dword ptr [EDX]
    //         004924e3     MOV        dword ptr [ESP + local_1c],EAX
    //         004924e7     MOV        this,dword ptr [EDX + 0x4]
    //         004924ea     MOV        dword ptr [ESP + local_18],this
    //         004924ee     MOV        EAX,dword ptr [EDX + 0x8]
    //         004924f1     MOV        dword ptr [ESP + local_14],EAX
    //         004924f5     MOV        this,dword ptr [EDX + 0xc]
    //         004924f8     XOR        EDX,EDX
    //         004924fa     MOV        dword ptr [ESP + local_10],this
    //         004924fe     MOV        this,0x10
    //         00492503     CMPSB.REPE ES:EDI=>_DPSPGUID_TCPIP,ESI                      = E0h
    //                                                                                  = 5Eh
    //         00492505     JNZ        LAB_0049250e
    //         00492507     PUSH       0x4c3
    //                              scr_cj.cpp:465 (2)
    //         0049250c     JMP        LAB_00492513
    //                              language.dll match for 0x4c2: "Creating multiplayer game...\\
    //                               LAB_0049250e                                                 XREF[1]:     00492505(j)  
    //                              scr_cj.cpp:466 (16)
    //         0049250e     PUSH       0x4c2
    //                               LAB_00492513                                                 XREF[1]:     0049250c(j)  
    //         00492513     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00492519     CALL       TRIBE_Game::show_status_message                  void show_status_message(TRIBE_Game * this, i
    //                              scr_cj.cpp:467 (11)
    //         0049251e     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00492524     CALL       RGE_Base_Game::draw_window                       void draw_window(RGE_Base_Game * this)
    //                              scr_cj.cpp:469 (13)
    //         00492529     PUSH       0x0
    //         0049252b     PUSH       s_data\closedpw.exe                              = "data\\closedpw.exe"
    //         00492530     CALL       dword ptr [->KERNEL32.DLL::WinExec]              = 0048ac6e
    //                              scr_cj.cpp:471 (21)
    //         00492536     MOV        EBP,dword ptr [EBP]
    //         00492539     MOV        AL,0x2
    //         0049253b     CMP        byte ptr [EBP + 0x478],AL
    //         00492541     JNZ        LAB_00492555
    //         00492543     CMP        byte ptr [EBP + 0x479],AL
    //         00492549     JNZ        LAB_00492555
    //                              scr_cj.cpp:472 (10)
    //         0049254b     MOV        EBP,dword ptr [EBP + 0x18]
    //         0049254e     PUSH       EBP
    //         0049254f     MOV        EAX,dword ptr [EBP]
    //         00492552     CALL       dword ptr [EAX + 0x28]
    //                               LAB_00492555                                                 XREF[2]:     00492541(j), 00492549(j)  
    //                              scr_cj.cpp:474 (20)
    //         00492555     MOV        EAX,[comm]                                       = 00000000
    //         0049255a     MOV        this,0x9
    //         0049255f     LEA        EDI,[EAX + 0x13c0]
    //         00492565     XOR        EAX,EAX
    //         00492567     STOSD.REP  ES:EDI
    //                              scr_cj.cpp:475 (11)
    //         00492569     MOV        this,dword ptr [comm]                            = 00000000
    //         0049256f     CALL       TCommunications_Handler::CreateMultiplayerGame   int CreateMultiplayerGame(TCommunications_Han
    //                              scr_cj.cpp:476 (22)
    //         00492574     MOV        this,dword ptr [L]                               = 00000000
    //         0049257a     PUSH       s_$$$_RETURNED_FROM_CreateMultipla               = "$$$ RETURNED FROM CreateMultiplayerGame"
    //         0049257f     PUSH       this=>DAT_fffffff8
    //         00492580     MOV        ESI,EAX
    //         00492582     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00492587     ADD        ESP,0x8
    //                              scr_cj.cpp:478 (16)
    //         0049258a     PUSH       s_closedpw                                       = "closedpw"
    //         0049258f     PUSH       s_closedpw                                       = "closedpw"
    //         00492594     CALL       dword ptr [->USER32.DLL::FindWindowA]            = 0048ad18
    //                              scr_cj.cpp:479 (4)
    //         0049259a     TEST       EAX,EAX
    //         0049259c     JZ         LAB_004925ab
    //                              scr_cj.cpp:480 (13)
    //         0049259e     PUSH       0x0
    //         004925a0     PUSH       0x0=>DAT_fffffff8
    //         004925a2     PUSH       offset DAT_fffffff4
    //         004925a4     PUSH       EAX=>DAT_fffffff0
    //         004925a5     CALL       dword ptr [->USER32.DLL::SendMessageA]           = 0048ad08
    //                               LAB_004925ab                                                 XREF[1]:     0049259c(j)  
    //                              scr_cj.cpp:482 (4)
    //         004925ab     TEST       ESI,ESI
    //         004925ad     JZ         LAB_00492623
    //                              scr_cj.cpp:485 (36)
    //         004925af     PUSH       0x890
    //         004925b4     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004925b9     ADD        ESP,0x4
    //         004925bc     MOV        dword ptr [ESP + 0x30],EAX
    //         004925c0     TEST       EAX,EAX
    //         004925c2     MOV        dword ptr [ESP + 0x28],0x0
    //         004925ca     JZ         LAB_004925d3
    //         004925cc     MOV        this,EAX
    //         004925ce     CALL       TribeMPSetupScreen::TribeMPSetupScreen           undefined TribeMPSetupScreen(TribeMPSetupScre
    //                               LAB_004925d3                                                 XREF[1]:     004925ca(j)  
    //                              scr_cj.cpp:486 (25)
    //         004925d3     PUSH       0x0
    //         004925d5     PUSH       s_MP_Setup_Screen                                = "MP Setup Screen"
    //         004925da     MOV        this,panel_system
    //         004925df     MOV        dword ptr [ESP + 0x30],0xffffffff
    //         004925e7     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              scr_cj.cpp:487 (15)
    //         004925ec     PUSH       s_Status_Screen                                  = "Status Screen"
    //         004925f1     MOV        this,panel_system
    //         004925f6     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_cj.cpp:488 (15)
    //         004925fb     PUSH       s_Create_Dialog                                  = "Create Dialog"
    //         00492600     MOV        this,panel_system
    //         00492605     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_cj.cpp:489 (5)
    //         0049260a     PUSH       s_Join_Screen                                    = "Join Screen"
    //                              scr_cj.cpp:507 (10)
    //         0049260f     MOV        this,panel_system
    //         00492614     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_cj.cpp:508 (10)
    //         00492619     MOV        EAX,0x1
    //         0049261e     JMP        LAB_004926c1
    //                               LAB_00492623                                                 XREF[1]:     004925ad(j)  
    //                              scr_cj.cpp:495 (3)
    //         00492623     MOV        EBX,dword ptr [EBX + 0x40]
    //                              scr_cj.cpp:496 (15)
    //         00492626     PUSH       s_Create_Dialog                                  = "Create Dialog"
    //         0049262b     MOV        this,panel_system
    //         00492630     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_cj.cpp:497 (17)
    //         00492635     PUSH       0x0
    //         00492637     PUSH       s_Join_Screen                                    = "Join Screen"
    //         0049263c     MOV        this,panel_system
    //         00492641     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              scr_cj.cpp:498 (15)
    //         00492646     PUSH       s_Status_Screen                                  = "Status Screen"
    //         0049264b     MOV        this,panel_system
    //         00492650     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_cj.cpp:499 (21)
    //         00492655     PUSH       0x64
    //         00492657     PUSH       offset DAT_fffffff8
    //         0049265c     PUSH       0x0=>DAT_fffffff4
    //                              language.dll match for 0x25ad: "Unable to create game. For TC
    //         0049265e     PUSH       offset DAT_fffffff0
    //         00492663     MOV        this,EBX
    //         00492665     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, long p
    //                              scr_cj.cpp:502 (7)
    //         0049266a     MOV        EAX,0x1
    //         0049266f     JMP        LAB_004926c1
    //                               LAB_00492671                                                 XREF[2]:     00492403(j), 0049240b(j)  
    //                              scr_cj.cpp:505 (22)
    //         00492671     CMP        EAX,dword ptr [EBX + 0x4a0]
    //         00492677     JNZ        LAB_0049267e
    //         00492679     CMP        this,0x1
    //         0049267c     JZ         LAB_00492687
    //                               LAB_0049267e                                                 XREF[1]:     00492677(j)  
    //         0049267e     CMP        EAX,EDX
    //         00492680     JNZ        LAB_004926ae
    //         00492682     CMP        this,0x1
    //         00492685     JNZ        LAB_004926ae
    //                               LAB_00492687                                                 XREF[1]:     0049267c(j)  
    //                              scr_cj.cpp:506 (17)
    //         00492687     PUSH       0x0
    //         00492689     PUSH       s_Join_Screen                                    = "Join Screen"
    //         0049268e     MOV        this,panel_system
    //         00492693     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              scr_cj.cpp:507 (15)
    //         00492698     PUSH       s_Create_Dialog                                  = "Create Dialog"
    //         0049269d     MOV        this,panel_system
    //         004926a2     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_cj.cpp:508 (7)
    //         004926a7     MOV        EAX,0x1
    //         004926ac     JMP        LAB_004926c1
    //                               LAB_004926ae                                                 XREF[3]:     004923e8(j), 00492680(j), 
    //                                                                                                         00492685(j)  
    //                              scr_cj.cpp:512 (19)
    //         004926ae     MOV        EDX,dword ptr [ESP + param_4]
    //         004926b2     PUSH       EDX
    //         004926b3     MOV        EDX,dword ptr [ESP + param_3]
    //         004926b7     PUSH       EDX
    //         004926b8     PUSH       this
    //         004926b9     PUSH       EAX
    //         004926ba     MOV        this,EBX
    //         004926bc     CALL       TPanel::action                                   long action(TPanel * this, TPanel * param_1, 
    //                               LAB_004926c1                                                 XREF[4]:     00492433(j), 0049261e(j), 
    //                                                                                                         0049266f(j), 004926ac(j)  
    //                              scr_cj.cpp:513 (21)
    //         004926c1     MOV        this,dword ptr [ESP + local_c]
    //         004926c5     POP        EDI
    //         004926c6     POP        ESI
    //         004926c7     POP        EBP
    //         004926c8     MOV        dword ptr FS:[0x0],this
    //         004926cf     POP        EBX
    //         004926d0     ADD        ESP,0x1c
    //         004926d3     RET        0x10
    //         004926d6     ??         90h
    //         004926d7     NOP
    //         004926d8     NOP
    //         004926d9     NOP
    //         004926da     NOP
    //         004926db     NOP
    //         004926dc     NOP
    //         004926dd     NOP
    //         004926de     NOP
    //         004926df     NOP
}

long TribeJoinScreen::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

long TribeMPCreateDialog::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

