#include "../common.h"
#include "dlg_menu.h"

TribeMenuDialog::TribeMenuDialog(TScreenPanel* param_1) {
    /* TODO: Stub */
//                              undefined __thiscall TribeMenuDialog(TribeMenuDialog * this, TScreen
//              undefined         <UNASSIGNED>   <RETURN>
//              TribeMenuDialo    ECX:4 (auto)   this
//              TScreenPanel *    Stack[0x4]:4   param_1                   XREF[1]:     0043f3c3(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0043f387(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0043f66f(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0043f361(W)
//                               ??0TribeMenuDialog@@QAE@PAVTScreenPanel@@@Z                  XREF[1]:     command_menu:0049c7e2(c)
//                               TribeMenuDialog::TribeMenuDialog
//                              dlg_menu.cpp:74 (48)
//         0043f340     PUSH       -0x1
//         0043f342     PUSH       FUN_0055d108
//         0043f347     MOV        EAX,FS:[0x0]
//         0043f34d     PUSH       EAX
//         0043f34e     MOV        dword ptr FS:[0x0],ESP
//         0043f355     PUSH       this
//         0043f356     PUSH       EBX
//         0043f357     PUSH       EBP
//         0043f358     PUSH       ESI
//         0043f359     PUSH       EDI
//         0043f35a     MOV        ESI,this
//         0043f35c     PUSH       s_Menu_Dialog                                    = "Menu Dialog"
//         0043f361     MOV        dword ptr [ESP + local_10],ESI
//         0043f365     CALL       TDialogPanel::TDialogPanel                       undefined TDialogPanel(TDialogPanel * this, c
//         0043f36a     LEA        EDI,[ESI + 0x490]
//                              dlg_menu.cpp:81 (15)
//         0043f370     MOV        this,0xb
//         0043f375     XOR        EAX,EAX
//         0043f377     MOV        dword ptr [ESI],TribeMenuDialog::`vftable'       = 0043f690
//         0043f37d     STOSD.REP  ES:EDI
//                              dlg_menu.cpp:86 (45)
//         0043f37f     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0043f385     XOR        EBX,EBX
//         0043f387     MOV        dword ptr [ESP + local_4],EBX
//         0043f38b     MOV        EBP,0x12c
//         0043f390     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
//         0043f395     TEST       EAX,EAX
//         0043f397     JZ         LAB_0043f3b1
//         0043f399     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0043f39f     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
//         0043f3a4     CMP        byte ptr [EAX + 0x80],BL
//         0043f3aa     JNZ        LAB_0043f3b1
//                              dlg_menu.cpp:87 (5)
//         0043f3ac     MOV        EBP,0x14f
//                               LAB_0043f3b1                                                 XREF[2]:     0043f397(j), 0043f3aa(j)
//                              dlg_menu.cpp:89 (15)
//         0043f3b1     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0043f3b7     CALL       RGE_Base_Game::singlePlayerGame                  int singlePlayerGame(RGE_Base_Game * this)
//         0043f3bc     TEST       EAX,EAX
//         0043f3be     JZ         LAB_0043f3c3
//                              dlg_menu.cpp:90 (3)
//         0043f3c0     ADD        EBP,0x69
//                               LAB_0043f3c3                                                 XREF[1]:     0043f3be(j)
//                              dlg_menu.cpp:92 (52)
//         0043f3c3     MOV        EDI,dword ptr [ESP + param_1]
//         0043f3c7     PUSH       0x1
//         0043f3c9     MOV        this,EDI
//         0043f3cb     CALL       TEasy_Panel::get_popup_info_id                   long get_popup_info_id(TEasy_Panel * this)
//         0043f3d0     PUSH       EAX
//         0043f3d1     MOV        this,EDI
//         0043f3d3     CALL       TEasy_Panel::get_popup_info_file                 char * get_popup_info_file(TEasy_Panel * this)
//         0043f3d8     PUSH       EAX
//         0043f3d9     PUSH       EBP
//         0043f3da     PUSH       0x190
//         0043f3df     PUSH       EDI
//         0043f3e0     MOV        this,EDI
//         0043f3e2     CALL       TPanel::renderArea                               TDrawArea * renderArea(TPanel * this)
//         0043f3e7     PUSH       EAX
//         0043f3e8     MOV        this,ESI
//         0043f3ea     CALL       TDialogPanel::setup                              int setup(TDialogPanel * this, TDrawArea * pa
//         0043f3ef     TEST       EAX,EAX
//         0043f3f1     JZ         LAB_0043f66f
//                              dlg_menu.cpp:98 (49)
//         0043f3f7     PUSH       0x4
//         0043f3f9     PUSH       EBX
//         0043f3fa     PUSH       EBX
//         0043f3fb     PUSH       0x1e
//         0043f3fd     PUSH       0x168
//         0043f402     PUSH       0xf
//         0043f404     PUSH       0x14
//         0043f406     PUSH       EBX
//         0043f407     LEA        EAX,[ESI + 0x490]
//                              language.dll match for 0x2439: "Quit Game"
//         0043f40d     PUSH       0x2439
//         0043f412     PUSH       EAX
//         0043f413     PUSH       ESI
//         0043f414     MOV        this,ESI
//         0043f416     MOV        EDI,0x1
//         0043f41b     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel
//         0043f420     TEST       EAX,EAX
//         0043f422     JZ         LAB_0043f66f
//                              dlg_menu.cpp:101 (39)
//         0043f428     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0043f42e     MOV        EBP,0x41
//         0043f433     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
//         0043f438     TEST       EAX,EAX
//         0043f43a     JZ         LAB_0043f484
//         0043f43c     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0043f442     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
//         0043f447     CMP        byte ptr [EAX + 0x80],BL
//         0043f44d     JNZ        LAB_0043f484
//                              dlg_menu.cpp:103 (48)
//         0043f44f     PUSH       0xc
//         0043f451     PUSH       EBX
//         0043f452     PUSH       EBX
//         0043f453     PUSH       0x1e
//         0043f455     PUSH       0x168
//         0043f45a     PUSH       EBP
//         0043f45b     PUSH       0x14
//         0043f45d     LEA        EAX,[ESI + 0x494]
//         0043f463     PUSH       EBX
//                              language.dll match for 0x2440: "Resign"
//         0043f464     PUSH       0x2440
//         0043f469     PUSH       EAX
//         0043f46a     PUSH       ESI
//         0043f46b     MOV        this,ESI
//         0043f46d     MOV        EDI,0x2
//         0043f472     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel
//         0043f477     TEST       EAX,EAX
//         0043f479     JZ         LAB_0043f66f
//                              dlg_menu.cpp:104 (5)
//         0043f47f     MOV        EBP,0x64
//                               LAB_0043f484                                                 XREF[2]:     0043f43a(j), 0043f44d(j)
//                              dlg_menu.cpp:107 (45)
//         0043f484     PUSH       0x7
//         0043f486     PUSH       EBX
//         0043f487     PUSH       EBX
//         0043f488     PUSH       0x1e
//         0043f48a     PUSH       0x168
//         0043f48f     PUSH       EBP
//         0043f490     PUSH       0x14
//         0043f492     LEA        EAX,[ESI + EDI*0x4 + 0x490]
//         0043f499     PUSH       EBX
//                              language.dll match for 0x2437: "Achievements"
//         0043f49a     PUSH       0x2437
//         0043f49f     PUSH       EAX
//         0043f4a0     PUSH       ESI
//         0043f4a1     MOV        this,ESI
//         0043f4a3     INC        EDI
//         0043f4a4     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel
//         0043f4a9     TEST       EAX,EAX
//         0043f4ab     JZ         LAB_0043f66f
//                              dlg_menu.cpp:110 (48)
//         0043f4b1     PUSH       0x9
//         0043f4b3     PUSH       EBX
//         0043f4b4     PUSH       EBX
//         0043f4b5     ADD        EBP,0x23
//         0043f4b8     PUSH       0x1e
//         0043f4ba     PUSH       0x168
//         0043f4bf     PUSH       EBP
//         0043f4c0     PUSH       0x14
//         0043f4c2     LEA        EAX,[ESI + EDI*0x4 + 0x490]
//         0043f4c9     PUSH       EBX
//                              language.dll match for 0x243e: "Scenario Instructions"
//         0043f4ca     PUSH       0x243e
//         0043f4cf     PUSH       EAX
//         0043f4d0     PUSH       ESI
//         0043f4d1     MOV        this,ESI
//         0043f4d3     INC        EDI
//         0043f4d4     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel
//         0043f4d9     TEST       EAX,EAX
//         0043f4db     JZ         LAB_0043f66f
//                              dlg_menu.cpp:113 (22)
//         0043f4e1     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0043f4e7     ADD        EBP,0x23
//         0043f4ea     CALL       RGE_Base_Game::singlePlayerGame                  int singlePlayerGame(RGE_Base_Game * this)
//         0043f4ef     TEST       EAX,EAX
//         0043f4f1     JZ         LAB_0043f587
//                              dlg_menu.cpp:115 (45)
//         0043f4f7     PUSH       0x1
//         0043f4f9     PUSH       EBX
//         0043f4fa     PUSH       EBX
//         0043f4fb     PUSH       0x1e
//         0043f4fd     PUSH       0x168
//         0043f502     PUSH       EBP
//         0043f503     PUSH       0x14
//         0043f505     LEA        EAX,[ESI + EDI*0x4 + 0x490]
//         0043f50c     PUSH       EBX
//                              language.dll match for 0x2438: "Save"
//         0043f50d     PUSH       0x2438
//         0043f512     PUSH       EAX
//         0043f513     PUSH       ESI
//         0043f514     MOV        this,ESI
//         0043f516     INC        EDI
//         0043f517     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel
//         0043f51c     TEST       EAX,EAX
//         0043f51e     JZ         LAB_0043f66f
//                              dlg_menu.cpp:118 (48)
//         0043f524     PUSH       0x3
//         0043f526     PUSH       EBX
//         0043f527     PUSH       EBX
//         0043f528     ADD        EBP,0x23
//         0043f52b     PUSH       0x1e
//         0043f52d     PUSH       0x168
//         0043f532     PUSH       EBP
//         0043f533     PUSH       0x14
//         0043f535     LEA        EAX,[ESI + EDI*0x4 + 0x490]
//         0043f53c     PUSH       EBX
//                              language.dll match for 0x243c: "Load"
//         0043f53d     PUSH       0x243c
//         0043f542     PUSH       EAX
//         0043f543     PUSH       ESI
//         0043f544     MOV        this,ESI
//         0043f546     INC        EDI
//         0043f547     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel
//         0043f54c     TEST       EAX,EAX
//         0043f54e     JZ         LAB_0043f66f
//                              dlg_menu.cpp:121 (48)
//         0043f554     PUSH       0xb
//         0043f556     PUSH       EBX
//         0043f557     PUSH       EBX
//         0043f558     ADD        EBP,0x23
//         0043f55b     PUSH       0x1e
//         0043f55d     PUSH       0x168
//         0043f562     PUSH       EBP
//         0043f563     PUSH       0x14
//         0043f565     LEA        EAX,[ESI + EDI*0x4 + 0x490]
//         0043f56c     PUSH       EBX
//                              language.dll match for 0x243f: "Restart"
//         0043f56d     PUSH       0x243f
//         0043f572     PUSH       EAX
//         0043f573     PUSH       ESI
//         0043f574     MOV        this,ESI
//         0043f576     INC        EDI
//         0043f577     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel
//         0043f57c     TEST       EAX,EAX
//         0043f57e     JZ         LAB_0043f66f
//                              dlg_menu.cpp:122 (3)
//         0043f584     ADD        EBP,0x23
//                               LAB_0043f587                                                 XREF[1]:     0043f4f1(j)
//                              dlg_menu.cpp:125 (45)
//         0043f587     PUSH       0x5
//         0043f589     PUSH       EBX
//         0043f58a     PUSH       EBX
//         0043f58b     PUSH       0x1e
//         0043f58d     PUSH       0x168
//         0043f592     PUSH       EBP
//         0043f593     PUSH       0x14
//         0043f595     LEA        EAX,[ESI + EDI*0x4 + 0x490]
//         0043f59c     PUSH       EBX
//                              language.dll match for 0x243a: "Game Settings"
//         0043f59d     PUSH       0x243a
//         0043f5a2     PUSH       EAX
//         0043f5a3     PUSH       ESI
//         0043f5a4     MOV        this,ESI
//         0043f5a6     INC        EDI
//         0043f5a7     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel
//         0043f5ac     TEST       EAX,EAX
//         0043f5ae     JZ         LAB_0043f66f
//                              dlg_menu.cpp:128 (48)
//         0043f5b4     PUSH       0x8
//         0043f5b6     PUSH       EBX
//         0043f5b7     PUSH       EBX
//         0043f5b8     ADD        EBP,0x23
//         0043f5bb     PUSH       0x1e
//         0043f5bd     PUSH       0x168
//         0043f5c2     PUSH       EBP
//         0043f5c3     PUSH       0x14
//         0043f5c5     LEA        EAX,[ESI + EDI*0x4 + 0x490]
//         0043f5cc     PUSH       EBX
//                              language.dll match for 0x23f5: "Help"
//         0043f5cd     PUSH       0x23f5
//         0043f5d2     PUSH       EAX
//         0043f5d3     PUSH       ESI
//         0043f5d4     MOV        this,ESI
//         0043f5d6     INC        EDI
//         0043f5d7     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel
//         0043f5dc     TEST       EAX,EAX
//         0043f5de     JZ         LAB_0043f66f
//                              dlg_menu.cpp:131 (44)
//         0043f5e4     PUSH       0xa
//         0043f5e6     PUSH       EBX
//         0043f5e7     PUSH       EBX
//         0043f5e8     ADD        EBP,0x23
//         0043f5eb     PUSH       0x1e
//         0043f5ed     PUSH       0x168
//         0043f5f2     PUSH       EBP
//         0043f5f3     PUSH       0x14
//         0043f5f5     LEA        EAX,[ESI + EDI*0x4 + 0x490]
//         0043f5fc     PUSH       EBX
//                              language.dll match for 0x23f9: "About"
//         0043f5fd     PUSH       0x23f9
//         0043f602     PUSH       EAX
//         0043f603     PUSH       ESI
//         0043f604     MOV        this,ESI
//         0043f606     INC        EDI
//         0043f607     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel
//         0043f60c     TEST       EAX,EAX
//         0043f60e     JZ         LAB_0043f66f
//                              dlg_menu.cpp:136 (47)
//         0043f610     PUSH       0x6
//         0043f612     ADD        EBP,0x23
//         0043f615     PUSH       EBX
//         0043f616     PUSH       EBX
//         0043f617     PUSH       0x1e
//         0043f619     ADD        EBP,0xf
//         0043f61c     PUSH       0x168
//         0043f621     PUSH       EBP
//         0043f622     PUSH       0x14
//         0043f624     LEA        EAX,[ESI + EDI*0x4 + 0x490]
//         0043f62b     PUSH       EBX
//                              language.dll match for 0x243b: "Cancel"
//         0043f62c     PUSH       0x243b
//         0043f631     PUSH       EAX
//         0043f632     PUSH       ESI
//         0043f633     MOV        this,ESI
//         0043f635     INC        EDI
//         0043f636     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel
//         0043f63b     TEST       EAX,EAX
//         0043f63d     JZ         LAB_0043f66f
//                              dlg_menu.cpp:137 (7)
//         0043f63f     MOV        EAX,dword ptr [ESI + EDI*0x4 + 0x48c]
//                              dlg_menu.cpp:139 (32)
//         0043f646     MOV        this,ESI
//         0043f648     MOV        dword ptr [EAX + 0x29c],EBX
//         0043f64e     LEA        EBX,[ESI + 0x490]
//         0043f654     MOV        dword ptr [EAX + 0x298],0x1b
//         0043f65e     MOV        EAX,dword ptr [EBX]
//         0043f660     PUSH       EAX
//         0043f661     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
//                              dlg_menu.cpp:141 (9)
//         0043f666     PUSH       EDI
//         0043f667     PUSH       EBX
//         0043f668     MOV        this,ESI
//         0043f66a     CALL       TPanel::set_tab_order                            void set_tab_order(TPanel * this, TPanel * *
//                               LAB_0043f66f                                                 XREF[12]:    0043f3f1(j), 0043f422(j),
//                                                                                                         0043f479(j), 0043f4ab(j),
//                                                                                                         0043f4db(j), 0043f51e(j),
//                                                                                                         0043f54e(j), 0043f57e(j),
//                                                                                                         0043f5ae(j), 0043f5de(j),
//                                                                                                         0043f60e(j), 0043f63d(j)
//                              dlg_menu.cpp:142 (23)
//         0043f66f     MOV        this,dword ptr [ESP + local_c]
//         0043f673     MOV        EAX,ESI
//         0043f675     POP        EDI
//         0043f676     POP        ESI
//         0043f677     POP        EBP
//         0043f678     MOV        dword ptr FS:[0x0],this
//         0043f67f     POP        EBX
//         0043f680     ADD        ESP,0x10
//         0043f683     RET        0x4
//         0043f686     ??         90h
//         0043f687     NOP
//         0043f688     NOP
//         0043f689     NOP
//         0043f68a     NOP
//         0043f68b     NOP
//         0043f68c     NOP
//         0043f68d     NOP
//         0043f68e     NOP
//         0043f68f     NOP
}

TribeMenuDialog::~TribeMenuDialog() {
    /* TODO: Stub */
//                              void __thiscall ~TribeMenuDialog(TribeMenuDialog * this)
//              void              <VOID>         <RETURN>
//              TribeMenuDialo    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0043f6d5(W), 0043f6f8(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0043f705(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0043f6cb(W)
//                               ??1TribeMenuDialog@@UAE@XZ                                   XREF[1]:     `scalar_deleting_destructor':0043f
//                               TribeMenuDialog::~TribeMenuDialog
//                              dlg_menu.cpp:148 (56)
//         0043f6b0     PUSH       -0x1
//         0043f6b2     PUSH       FUN_0055d128
//         0043f6b7     MOV        EAX,FS:[0x0]
//         0043f6bd     PUSH       EAX
//         0043f6be     MOV        dword ptr FS:[0x0],ESP
//         0043f6c5     PUSH       this
//         0043f6c6     PUSH       EBX
//         0043f6c7     PUSH       ESI
//         0043f6c8     PUSH       EDI
//         0043f6c9     MOV        EDI,this
//         0043f6cb     MOV        dword ptr [ESP + local_10],EDI
//         0043f6cf     MOV        dword ptr [EDI],TribeMenuDialog::`vftable'       = 0043f690
//         0043f6d5     MOV        dword ptr [ESP + local_4],0x0
//         0043f6dd     LEA        ESI,[EDI + 0x490]
//         0043f6e3     MOV        EBX,0xb
//                               LAB_0043f6e8                                                 XREF[1]:     0043f6f4(j)
//                              dlg_menu.cpp:152 (16)
//         0043f6e8     PUSH       ESI
//         0043f6e9     MOV        this,EDI
//         0043f6eb     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//         0043f6f0     ADD        ESI,0x4
//         0043f6f3     DEC        EBX
//         0043f6f4     JNZ        LAB_0043f6e8
//         0043f6f6     MOV        this,EDI
//                              dlg_menu.cpp:153 (31)
//         0043f6f8     MOV        dword ptr [ESP + local_4],0xffffffff
//         0043f700     CALL       TDialogPanel::~TDialogPanel                      void ~TDialogPanel(TDialogPanel * this)
//         0043f705     MOV        this,dword ptr [ESP + local_c]
//         0043f709     POP        EDI
//         0043f70a     POP        ESI
//         0043f70b     MOV        dword ptr FS:[0x0],this
//         0043f712     POP        EBX
//         0043f713     ADD        ESP,0x10
//         0043f716     RET
//         0043f717     ??         90h
//         0043f718     NOP
//         0043f719     NOP
//         0043f71a     NOP
//         0043f71b     NOP
//         0043f71c     NOP
//         0043f71d     NOP
//         0043f71e     NOP
//         0043f71f     NOP
}

long TribeMenuDialog::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    /* TODO: Stub */
//                              long __thiscall action(TribeMenuDialog * this, TPanel * param_1, lon
//              long              EAX:4          <RETURN>
//              TribeMenuDialo    ECX:4 (auto)   this
//              TPanel *          Stack[0x4]:4   param_1                   XREF[7]:     0043f741(R), 0043f767(W), 0043f7d6(W), 0043f991(W),
//                                                                                     0043f9db(W), 0043fa76(W), 0043fb14(W)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     0043f732(R)
//              ulong             Stack[0xc]:4   param_3                   XREF[1]:     0043f72e(R)
//              ulong             Stack[0x10]:4  param_4                   XREF[1]:     0043fc43(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[10]:    0043f76d(W), 0043f790(W), 0043f7dc(W), 0043f7ff(W),
//                                                                                     0043f997(W), 0043f9e1(W), 0043fa0d(W), 0043fa7c(W),
//                                                                                     0043fb1a(W), 0043fb51(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[12]:    0043f7b1(R), 0043f811(R), 0043f869(R), 0043f949(R),
//                                                                                     0043f9b4(R), 0043fa2e(R), 0043fa97(R), 0043faef(R),
//                                                                                     0043fb72(R), 0043fbd8(R), 0043fc30(R), 0043fc52(R)
//                               ?action@TribeMenuDialog@@MAEJPAVTPanel@@JKK@Z                XREF[1]:     0056fce4(*)
//                               TribeMenuDialog::action
//                              dlg_menu.cpp:159 (14)
//         0043f720     MOV        EAX,FS:[0x0]
//         0043f726     PUSH       -0x1
//         0043f728     PUSH       FUN_0055d182
//         0043f72d     PUSH       EAX
//                              dlg_menu.cpp:160 (31)
//         0043f72e     MOV        EAX,dword ptr [ESP + param_3]
//         0043f732     MOV        EDX,dword ptr [ESP + param_2]
//         0043f736     MOV        dword ptr FS:[0x0],ESP
//         0043f73d     PUSH       ESI
//         0043f73e     MOV        ESI,this
//         0043f740     PUSH       EDI
//         0043f741     MOV        this,dword ptr [ESP + param_1]
//         0043f745     TEST       this,this
//         0043f747     JZ         LAB_0043fc43
//                              dlg_menu.cpp:161 (9)
//         0043f74d     CMP        EDX,0x1
//         0043f750     JNZ        LAB_0043fc43
//                              dlg_menu.cpp:162 (4)
//         0043f756     CMP        EAX,EDX
//         0043f758     JNZ        LAB_0043f7c4
//                              dlg_menu.cpp:164 (42)
//         0043f75a     PUSH       0x6a4
//         0043f75f     CALL       operator_new                                     void * operator_new(uint param_1)
//         0043f764     ADD        ESP,0x4
//         0043f767     MOV        dword ptr [ESP + param_1],EAX
//         0043f76b     TEST       EAX,EAX
//         0043f76d     MOV        dword ptr [ESP + local_4],0x0
//         0043f775     JZ         LAB_0043f784
//         0043f777     PUSH       0x0
//         0043f779     PUSH       0x0
//         0043f77b     PUSH       0x0
//         0043f77d     MOV        this,EAX
//         0043f77f     CALL       TribeSaveGameScreen::TribeSaveGameScreen         undefined TribeSaveGameScreen(TribeSaveGameSc
//                               LAB_0043f784                                                 XREF[1]:     0043f775(j)
//                              dlg_menu.cpp:165 (25)
//         0043f784     PUSH       0x0
//         0043f786     PUSH       s_Save_Game_Screen                               = "Save Game Screen"
//         0043f78b     MOV        this,panel_system
//         0043f790     MOV        dword ptr [ESP + local_4],0xffffffff
//         0043f798     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
//                              dlg_menu.cpp:166 (15)
//         0043f79d     PUSH       s_Menu_Dialog                                    = "Menu Dialog"
//         0043f7a2     MOV        this,panel_system
//         0043f7a7     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char *
//                              dlg_menu.cpp:167 (5)
//         0043f7ac     MOV        EAX,0x1
//                              dlg_menu.cpp:326 (19)
//         0043f7b1     MOV        this,dword ptr [ESP + local_c]
//         0043f7b5     MOV        dword ptr FS:[0x0],this
//         0043f7bc     POP        EDI
//         0043f7bd     POP        ESI
//         0043f7be     ADD        ESP,0xc
//         0043f7c1     RET        0x10
//                               LAB_0043f7c4                                                 XREF[1]:     0043f758(j)
//                              dlg_menu.cpp:169 (5)
//         0043f7c4     CMP        EAX,0x2
//         0043f7c7     JNZ        LAB_0043f824
//                              dlg_menu.cpp:171 (42)
//         0043f7c9     PUSH       0x6a4
//         0043f7ce     CALL       operator_new                                     void * operator_new(uint param_1)
//         0043f7d3     ADD        ESP,0x4
//         0043f7d6     MOV        dword ptr [ESP + param_1],EAX
//         0043f7da     TEST       EAX,EAX
//         0043f7dc     MOV        dword ptr [ESP + local_4],0x1
//         0043f7e4     JZ         LAB_0043f7f3
//         0043f7e6     PUSH       0x0
//         0043f7e8     PUSH       0x0
//         0043f7ea     PUSH       0x1
//         0043f7ec     MOV        this,EAX
//         0043f7ee     CALL       TribeSaveGameScreen::TribeSaveGameScreen         undefined TribeSaveGameScreen(TribeSaveGameSc
//                               LAB_0043f7f3                                                 XREF[1]:     0043f7e4(j)
//                              dlg_menu.cpp:172 (25)
//         0043f7f3     PUSH       0x0
//         0043f7f5     PUSH       s_Save_Game_Screen                               = "Save Game Screen"
//         0043f7fa     MOV        this,panel_system
//         0043f7ff     MOV        dword ptr [ESP + local_4],0xffffffff
//         0043f807     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
//                              dlg_menu.cpp:173 (5)
//         0043f80c     MOV        EAX,0x1
//                              dlg_menu.cpp:326 (19)
//         0043f811     MOV        this,dword ptr [ESP + local_c]
//         0043f815     MOV        dword ptr FS:[0x0],this
//         0043f81c     POP        EDI
//         0043f81d     POP        ESI
//         0043f81e     ADD        ESP,0xc
//         0043f821     RET        0x10
//                               LAB_0043f824                                                 XREF[1]:     0043f7c7(j)
//                              dlg_menu.cpp:175 (5)
//         0043f824     CMP        EAX,0x3
//         0043f827     JNZ        LAB_0043f87c
//                              dlg_menu.cpp:176 (3)
//         0043f829     MOV        ESI,dword ptr [ESI + 0x40]
//                              dlg_menu.cpp:177 (15)
//         0043f82c     PUSH       s_Menu_Dialog                                    = "Menu Dialog"
//         0043f831     MOV        this,panel_system
//         0043f836     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char *
//                              dlg_menu.cpp:178 (17)
//         0043f83b     PUSH       0x0
//         0043f83d     PUSH       s_Game_Screen                                    = "Game Screen"
//         0043f842     MOV        this,panel_system
//         0043f847     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
//                              dlg_menu.cpp:181 (24)
//         0043f84c     PUSH       0x64
//         0043f84e     PUSH       0x1c2
//         0043f853     PUSH       s_QuitAndLoadDialog                              = 51h
//                              language.dll match for 0xc1c: "Are you sure you want to quit
//         0043f858     PUSH       0xc1c
//         0043f85d     MOV        this,ESI
//         0043f85f     CALL       TEasy_Panel::popupYesNoDialog                    void popupYesNoDialog(TEasy_Panel * this, lon
//                              dlg_menu.cpp:187 (5)
//         0043f864     MOV        EAX,0x1
//                              dlg_menu.cpp:326 (19)
//         0043f869     MOV        this,dword ptr [ESP + local_c]
//         0043f86d     MOV        dword ptr FS:[0x0],this
//         0043f874     POP        EDI
//         0043f875     POP        ESI
//         0043f876     ADD        ESP,0xc
//         0043f879     RET        0x10
//                               LAB_0043f87c                                                 XREF[1]:     0043f827(j)
//                              dlg_menu.cpp:189 (5)
//         0043f87c     CMP        EAX,0x8
//         0043f87f     JNZ        LAB_0043f8fa
//                              dlg_menu.cpp:190 (32)
//         0043f881     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0043f887     CALL       RGE_Base_Game::singlePlayerGame                  int singlePlayerGame(RGE_Base_Game * this)
//         0043f88c     CMP        EAX,0x1
//         0043f88f     JNZ        LAB_0043f8aa
//         0043f891     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0043f897     MOV        EAX,dword ptr [this->_padding_ + 0xa00]
//         0043f89d     TEST       EAX,EAX
//         0043f89f     JNZ        LAB_0043f8aa
//                              dlg_menu.cpp:191 (9)
//         0043f8a1     PUSH       0x0
//         0043f8a3     PUSH       0x0
//         0043f8a5     CALL       RGE_Base_Game::set_paused                        void set_paused(RGE_Base_Game * this, int par
//                               LAB_0043f8aa                                                 XREF[2]:     0043f88f(j), 0043f89f(j)
//                              dlg_menu.cpp:192 (15)
//         0043f8aa     PUSH       s_Menu_Dialog                                    = "Menu Dialog"
//         0043f8af     MOV        this,panel_system
//         0043f8b4     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char *
//                              dlg_menu.cpp:193 (17)
//         0043f8b9     PUSH       0x0
//         0043f8bb     PUSH       s_Game_Screen                                    = "Game Screen"
//         0043f8c0     MOV        this,panel_system
//         0043f8c5     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
//                              dlg_menu.cpp:194 (24)
//         0043f8ca     MOV        EAX,[rge_base_game]                              = 00000000
//         0043f8cf     PUSH       0x0
//         0043f8d1     PUSH       0x3
//         0043f8d3     PUSH       s_empires.hlp                                    = "empires.hlp"
//         0043f8d8     MOV        this,dword ptr [EAX + 0x10]
//         0043f8db     PUSH       this
//         0043f8dc     CALL       dword ptr [->USER32.DLL::WinHelpA]               = 0048aff6
//                              dlg_menu.cpp:195 (5)
//         0043f8e2     MOV        EAX,0x1
//                              dlg_menu.cpp:326 (19)
//         0043f8e7     MOV        this,dword ptr [ESP + 0x8]
//         0043f8eb     MOV        dword ptr FS:[0x0],this
//         0043f8f2     POP        EDI
//         0043f8f3     POP        ESI
//         0043f8f4     ADD        ESP,0xc
//         0043f8f7     RET        0x10
//                               LAB_0043f8fa                                                 XREF[1]:     0043f87f(j)
//                              dlg_menu.cpp:197 (5)
//         0043f8fa     CMP        EAX,0x4
//         0043f8fd     JNZ        LAB_0043f95c
//                              dlg_menu.cpp:212 (10)
//         0043f8ff     MOV        dword ptr [confirmed_close],0x1
//                              dlg_menu.cpp:213 (3)
//         0043f909     MOV        ESI,dword ptr [ESI + 0x40]
//                              dlg_menu.cpp:214 (15)
//         0043f90c     PUSH       s_Menu_Dialog                                    = "Menu Dialog"
//         0043f911     MOV        this,panel_system
//         0043f916     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char *
//                              dlg_menu.cpp:215 (17)
//         0043f91b     PUSH       0x0
//         0043f91d     PUSH       s_Game_Screen                                    = "Game Screen"
//         0043f922     MOV        this,panel_system
//         0043f927     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
//                              dlg_menu.cpp:218 (24)
//         0043f92c     PUSH       0x64
//         0043f92e     PUSH       0x1c2
//         0043f933     PUSH       s_QuitGameDialog                                 = 51h
//                              language.dll match for 0xc1d: "Are you sure you want to quit
//         0043f938     PUSH       0xc1d
//         0043f93d     MOV        this,ESI
//         0043f93f     CALL       TEasy_Panel::popupYesNoDialog                    void popupYesNoDialog(TEasy_Panel * this, lon
//                              dlg_menu.cpp:220 (5)
//         0043f944     MOV        EAX,0x1
//                              dlg_menu.cpp:326 (19)
//         0043f949     MOV        this,dword ptr [ESP + local_c]
//         0043f94d     MOV        dword ptr FS:[0x0],this
//         0043f954     POP        EDI
//         0043f955     POP        ESI
//         0043f956     ADD        ESP,0xc
//         0043f959     RET        0x10
//                               LAB_0043f95c                                                 XREF[1]:     0043f8fd(j)
//                              dlg_menu.cpp:222 (5)
//         0043f95c     CMP        EAX,0x5
//         0043f95f     JNZ        LAB_0043f9c7
//                              dlg_menu.cpp:223 (3)
//         0043f961     MOV        ESI,dword ptr [ESI + 0x40]
//                              dlg_menu.cpp:224 (15)
//         0043f964     PUSH       s_Menu_Dialog                                    = "Menu Dialog"
//         0043f969     MOV        this,panel_system
//         0043f96e     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char *
//                              dlg_menu.cpp:225 (17)
//         0043f973     PUSH       0x0
//         0043f975     PUSH       s_Game_Screen                                    = "Game Screen"
//         0043f97a     MOV        this,panel_system
//         0043f97f     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
//                              dlg_menu.cpp:226 (43)
//         0043f984     PUSH       0x564
//         0043f989     CALL       operator_new                                     void * operator_new(uint param_1)
//         0043f98e     ADD        ESP,0x4
//         0043f991     MOV        dword ptr [ESP + param_1],EAX
//         0043f995     TEST       EAX,EAX
//         0043f997     MOV        dword ptr [ESP + local_4],0x2
//         0043f99f     JZ         LAB_0043fc2b
//         0043f9a5     PUSH       ESI
//         0043f9a6     PUSH       0x0
//         0043f9a8     MOV        this,EAX
//         0043f9aa     CALL       TribeConfigDialog::TribeConfigDialog             undefined TribeConfigDialog(TribeConfigDialog
//                              dlg_menu.cpp:227 (5)
//         0043f9af     MOV        EAX,0x1
//                              dlg_menu.cpp:326 (19)
//         0043f9b4     MOV        this,dword ptr [ESP + local_c]
//         0043f9b8     MOV        dword ptr FS:[0x0],this
//         0043f9bf     POP        EDI
//         0043f9c0     POP        ESI
//         0043f9c1     ADD        ESP,0xc
//         0043f9c4     RET        0x10
//                               LAB_0043f9c7                                                 XREF[1]:     0043f95f(j)
//                              dlg_menu.cpp:229 (5)
//         0043f9c7     CMP        EAX,0x7
//         0043f9ca     JNZ        LAB_0043fa41
//                              dlg_menu.cpp:230 (53)
//         0043f9cc     PUSH       0x5f8
//         0043f9d1     CALL       operator_new                                     void * operator_new(uint param_1)
//         0043f9d6     MOV        EDI,EAX
//         0043f9d8     ADD        ESP,0x4
//         0043f9db     MOV        dword ptr [ESP + param_1],EDI
//         0043f9df     TEST       EDI,EDI
//         0043f9e1     MOV        dword ptr [ESP + local_4],0x3
//         0043f9e9     JZ         LAB_0043fa01
//         0043f9eb     PUSH       0x0
//                              language.dll match for 0x269e: "Achievements"
//         0043f9ed     PUSH       0x269e
//         0043f9f2     MOV        this,ESI
//         0043f9f4     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         0043f9f9     PUSH       EAX
//         0043f9fa     MOV        this,EDI
//         0043f9fc     CALL       TribeAchievementsScreen::TribeAchievementsScreen undefined TribeAchievementsScreen(TribeAchiev
//                               LAB_0043fa01                                                 XREF[1]:     0043f9e9(j)
//                              dlg_menu.cpp:231 (25)
//         0043fa01     PUSH       0x0
//         0043fa03     PUSH       s_Achievements_Screen                            = "Achievements Screen"
//         0043fa08     MOV        this,panel_system
//         0043fa0d     MOV        dword ptr [ESP + local_4],0xffffffff
//         0043fa15     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
//                              dlg_menu.cpp:232 (15)
//         0043fa1a     PUSH       s_Menu_Dialog                                    = "Menu Dialog"
//         0043fa1f     MOV        this,panel_system
//         0043fa24     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char *
//                              dlg_menu.cpp:233 (5)
//         0043fa29     MOV        EAX,0x1
//                              dlg_menu.cpp:326 (19)
//         0043fa2e     MOV        this,dword ptr [ESP + local_c]
//         0043fa32     MOV        dword ptr FS:[0x0],this
//         0043fa39     POP        EDI
//         0043fa3a     POP        ESI
//         0043fa3b     ADD        ESP,0xc
//         0043fa3e     RET        0x10
//                               LAB_0043fa41                                                 XREF[1]:     0043f9ca(j)
//                              dlg_menu.cpp:235 (5)
//         0043fa41     CMP        EAX,0xa
//         0043fa44     JNZ        LAB_0043faaa
//                              dlg_menu.cpp:236 (3)
//         0043fa46     MOV        ESI,dword ptr [ESI + 0x40]
//                              dlg_menu.cpp:237 (15)
//         0043fa49     PUSH       s_Menu_Dialog                                    = "Menu Dialog"
//         0043fa4e     MOV        this,panel_system
//         0043fa53     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char *
//                              dlg_menu.cpp:238 (17)
//         0043fa58     PUSH       0x0
//         0043fa5a     PUSH       s_Game_Screen                                    = "Game Screen"
//         0043fa5f     MOV        this,panel_system
//         0043fa64     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
//                              dlg_menu.cpp:241 (41)
//         0043fa69     PUSH       0x4c4
//         0043fa6e     CALL       operator_new                                     void * operator_new(uint param_1)
//         0043fa73     ADD        ESP,0x4
//         0043fa76     MOV        dword ptr [ESP + param_1],EAX
//         0043fa7a     TEST       EAX,EAX
//         0043fa7c     MOV        dword ptr [ESP + local_4],0x4
//         0043fa84     JZ         LAB_0043fc2b
//         0043fa8a     PUSH       ESI
//         0043fa8b     MOV        this,EAX
//         0043fa8d     CALL       TribeAboutDialog::TribeAboutDialog               undefined TribeAboutDialog(TribeAboutDialog *
//                              dlg_menu.cpp:242 (5)
//         0043fa92     MOV        EAX,0x1
//                              dlg_menu.cpp:326 (19)
//         0043fa97     MOV        this,dword ptr [ESP + local_c]
//         0043fa9b     MOV        dword ptr FS:[0x0],this
//         0043faa2     POP        EDI
//         0043faa3     POP        ESI
//         0043faa4     ADD        ESP,0xc
//         0043faa7     RET        0x10
//                               LAB_0043faaa                                                 XREF[1]:     0043fa44(j)
//                              dlg_menu.cpp:244 (5)
//         0043faaa     CMP        EAX,0xb
//         0043faad     JNZ        LAB_0043fb02
//                              dlg_menu.cpp:245 (3)
//         0043faaf     MOV        ESI,dword ptr [ESI + 0x40]
//                              dlg_menu.cpp:246 (15)
//         0043fab2     PUSH       s_Menu_Dialog                                    = "Menu Dialog"
//         0043fab7     MOV        this,panel_system
//         0043fabc     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char *
//                              dlg_menu.cpp:247 (17)
//         0043fac1     PUSH       0x0
//         0043fac3     PUSH       s_Game_Screen                                    = "Game Screen"
//         0043fac8     MOV        this,panel_system
//         0043facd     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
//                              dlg_menu.cpp:250 (24)
//         0043fad2     PUSH       0x64
//         0043fad4     PUSH       0x1c2
//         0043fad9     PUSH       s_RestartDialog                                  = 52h
//                              language.dll match for 0xc1e: "Are you sure you want to resta
//         0043fade     PUSH       0xc1e
//         0043fae3     MOV        this,ESI
//         0043fae5     CALL       TEasy_Panel::popupYesNoDialog                    void popupYesNoDialog(TEasy_Panel * this, lon
//                              dlg_menu.cpp:252 (5)
//         0043faea     MOV        EAX,0x1
//                              dlg_menu.cpp:326 (19)
//         0043faef     MOV        this,dword ptr [ESP + local_c]
//         0043faf3     MOV        dword ptr FS:[0x0],this
//         0043fafa     POP        EDI
//         0043fafb     POP        ESI
//         0043fafc     ADD        ESP,0xc
//         0043faff     RET        0x10
//                               LAB_0043fb02                                                 XREF[1]:     0043faad(j)
//                              dlg_menu.cpp:254 (5)
//         0043fb02     CMP        EAX,0x9
//         0043fb05     JNZ        LAB_0043fb85
//                              dlg_menu.cpp:293 (62)
//         0043fb07     PUSH       0x49c
//         0043fb0c     CALL       operator_new                                     void * operator_new(uint param_1)
//         0043fb11     ADD        ESP,0x4
//         0043fb14     MOV        dword ptr [ESP + param_1],EAX
//         0043fb18     TEST       EAX,EAX
//         0043fb1a     MOV        dword ptr [ESP + local_4],0x5
//         0043fb22     JZ         LAB_0043fb45
//         0043fb24     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
//         0043fb2a     MOV        this,dword ptr [EDX + 0x3f4]
//         0043fb30     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0043fb33     MOV        this,dword ptr [EDX + 0x198c]
//         0043fb39     PUSH       this
//         0043fb3a     PUSH       0x1
//         0043fb3c     PUSH       0x0
//         0043fb3e     MOV        this,EAX
//         0043fb40     CALL       TRIBE_Mission_Screen::TRIBE_Mission_Screen       undefined TRIBE_Mission_Screen(TRIBE_Mission_
//                               LAB_0043fb45                                                 XREF[1]:     0043fb22(j)
//                              dlg_menu.cpp:295 (25)
//         0043fb45     PUSH       0x0
//         0043fb47     PUSH       s_Mission_Dialog                                 = "Mission Dialog"
//         0043fb4c     MOV        this,panel_system
//         0043fb51     MOV        dword ptr [ESP + local_4],0xffffffff
//         0043fb59     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
//                              dlg_menu.cpp:296 (15)
//         0043fb5e     PUSH       s_Menu_Dialog                                    = "Menu Dialog"
//         0043fb63     MOV        this,panel_system
//         0043fb68     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char *
//                              dlg_menu.cpp:297 (5)
//         0043fb6d     MOV        EAX,0x1
//                              dlg_menu.cpp:326 (19)
//         0043fb72     MOV        this,dword ptr [ESP + local_c]
//         0043fb76     MOV        dword ptr FS:[0x0],this
//         0043fb7d     POP        EDI
//         0043fb7e     POP        ESI
//         0043fb7f     ADD        ESP,0xc
//         0043fb82     RET        0x10
//                               LAB_0043fb85                                                 XREF[1]:     0043fb05(j)
//                              dlg_menu.cpp:299 (5)
//         0043fb85     CMP        EAX,0x6
//         0043fb88     JNZ        LAB_0043fbeb
//                              dlg_menu.cpp:300 (32)
//         0043fb8a     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0043fb90     CALL       RGE_Base_Game::singlePlayerGame                  int singlePlayerGame(RGE_Base_Game * this)
//         0043fb95     CMP        EAX,0x1
//         0043fb98     JNZ        LAB_0043fbb3
//         0043fb9a     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0043fba0     MOV        EAX,dword ptr [this->_padding_ + 0xa00]
//         0043fba6     TEST       EAX,EAX
//         0043fba8     JNZ        LAB_0043fbb3
//                              dlg_menu.cpp:301 (9)
//         0043fbaa     PUSH       0x0
//         0043fbac     PUSH       0x0
//         0043fbae     CALL       RGE_Base_Game::set_paused                        void set_paused(RGE_Base_Game * this, int par
//                               LAB_0043fbb3                                                 XREF[2]:     0043fb98(j), 0043fba8(j)
//                              dlg_menu.cpp:302 (17)
//         0043fbb3     PUSH       0x0
//         0043fbb5     PUSH       s_Game_Screen                                    = "Game Screen"
//         0043fbba     MOV        this,panel_system
//         0043fbbf     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
//                              dlg_menu.cpp:303 (15)
//         0043fbc4     PUSH       s_Menu_Dialog                                    = "Menu Dialog"
//         0043fbc9     MOV        this,panel_system
//         0043fbce     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char *
//                              dlg_menu.cpp:304 (5)
//         0043fbd3     MOV        EAX,0x1
//                              dlg_menu.cpp:326 (19)
//         0043fbd8     MOV        this,dword ptr [ESP + local_c]
//         0043fbdc     MOV        dword ptr FS:[0x0],this
//         0043fbe3     POP        EDI
//         0043fbe4     POP        ESI
//         0043fbe5     ADD        ESP,0xc
//         0043fbe8     RET        0x10
//                               LAB_0043fbeb                                                 XREF[1]:     0043fb88(j)
//                              dlg_menu.cpp:306 (5)
//         0043fbeb     CMP        EAX,0xc
//         0043fbee     JNZ        LAB_0043fc43
//                              dlg_menu.cpp:307 (3)
//         0043fbf0     MOV        ESI,dword ptr [ESI + 0x40]
//                              dlg_menu.cpp:308 (15)
//         0043fbf3     PUSH       s_Menu_Dialog                                    = "Menu Dialog"
//         0043fbf8     MOV        this,panel_system
//         0043fbfd     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char *
//                              dlg_menu.cpp:309 (17)
//         0043fc02     PUSH       0x0
//         0043fc04     PUSH       s_Game_Screen                                    = "Game Screen"
//         0043fc09     MOV        this,panel_system
//         0043fc0e     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
//                              dlg_menu.cpp:312 (24)
//         0043fc13     PUSH       0x64
//         0043fc15     PUSH       0x1c2
//         0043fc1a     PUSH       s_ResignDialog                                   = 52h
//                              language.dll match for 0xc1f: "Are you sure you want to resig
//         0043fc1f     PUSH       0xc1f
//         0043fc24     MOV        this,ESI
//         0043fc26     CALL       TEasy_Panel::popupYesNoDialog                    void popupYesNoDialog(TEasy_Panel * this, lon
//                               LAB_0043fc2b                                                 XREF[2]:     0043f99f(j), 0043fa84(j)
//                              dlg_menu.cpp:320 (5)
//         0043fc2b     MOV        EAX,0x1
//                              dlg_menu.cpp:326 (19)
//         0043fc30     MOV        this,dword ptr [ESP + local_c]
//         0043fc34     MOV        dword ptr FS:[0x0],this
//         0043fc3b     POP        EDI
//         0043fc3c     POP        ESI
//         0043fc3d     ADD        ESP,0xc
//         0043fc40     RET        0x10
//                               LAB_0043fc43                                                 XREF[3]:     0043f747(j), 0043f750(j),
//                                                                                                         0043fbee(j)
//                              dlg_menu.cpp:325 (15)
//         0043fc43     MOV        EDI,dword ptr [ESP + param_4]
//         0043fc47     PUSH       EDI
//         0043fc48     PUSH       EAX
//         0043fc49     PUSH       EDX
//         0043fc4a     PUSH       this
//         0043fc4b     MOV        this,ESI
//         0043fc4d     CALL       TEasy_Panel::action                              long action(TEasy_Panel * this, TPanel * para
//                              dlg_menu.cpp:326 (19)
//         0043fc52     MOV        this,dword ptr [ESP + local_c]
//         0043fc56     POP        EDI
//         0043fc57     MOV        dword ptr FS:[0x0],this
//         0043fc5e     POP        ESI
//         0043fc5f     ADD        ESP,0xc
//         0043fc62     RET        0x10
//         0043fc65     ??         90h
//         0043fc66     NOP
//         0043fc67     NOP
//         0043fc68     NOP
//         0043fc69     NOP
//         0043fc6a     NOP
//         0043fc6b     NOP
//         0043fc6c     NOP
//         0043fc6d     NOP
//         0043fc6e     NOP
//         0043fc6f     NOP
    return 0;
}

