#include "../common.h"
#include "scr_save.h"

TribeSaveGameScreen::TribeSaveGameScreen(Mode param_1, char* param_2, int param_3) {
    /* TODO: Stub */
//                              undefined __thiscall TribeSaveGameScreen(TribeSaveGameScreen * this,
//              undefined         <UNASSIGNED>   <RETURN>
//              TribeSaveGameS    ECX:4 (auto)   this
//              Mode              Stack[0x4]:4   param_1                   XREF[1]:     004a7226(R)
//              char *            Stack[0x8]:4   param_2                   XREF[3]:     004a7233(R), 004a72ad(W), 004a73b0(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     004a721f(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004a7240(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004a7581(R)
//              char[260]         Stack[-0x114   info_file                 XREF[1,2]:   004a7216(W), 004a72d0(*), 004a7300(*)
//              undefined4        Stack[-0x118   local_118                 XREF[1]:     004a7578(W)
//              TPanel *[5]       Stack[-0x12c   tabList                   XREF[2,5]:   004a72c0(W), 004a72f7(R), 004a755b(W), 004a756b(*),
//                                                                                     004a7565(W), 004a7561(W), 004a756f(W)
//              TEasy_Panel *     Stack[-0x130   from_panel
//                               ??0TribeSaveGameScreen@@QAE@W4Mode@0@PADH@Z                  XREF[6]:     action:0043f77f(c),
//                               TribeSaveGameScreen::TribeSaveGameScreen                                  action:0043f7ee(c),
//                                                                                                         key_down_action:00497d3a(c),
//                                                                                                         command_save_game:0049cbe7(c),
//                                                                                                         command_save_scenario:0049cc77(c),
//                                                                                                         command_save_as:004ada28(c)
//                              scr_save.cpp:57 (47)
//         004a71f0     PUSH       -0x1
//         004a71f2     PUSH       FUN_0055f3bb
//         004a71f7     MOV        EAX,FS:[0x0]
//         004a71fd     PUSH       EAX
//         004a71fe     MOV        dword ptr FS:[0x0],ESP
//         004a7205     SUB        ESP,0x120
//         004a720b     PUSH       EBX
//         004a720c     PUSH       EBP
//         004a720d     PUSH       ESI
//         004a720e     PUSH       EDI
//         004a720f     MOV        EBP,this
//         004a7211     PUSH       s_Save_Game_Screen                               = "Save Game Screen"
//         004a7216     MOV        dword ptr [ESP + info_file[0]],EBP
//         004a721a     CALL       TScreenPanel::TScreenPanel                       undefined TScreenPanel(TScreenPanel * this, c
//                              scr_save.cpp:66 (20)
//         004a721f     MOV        this,dword ptr [ESP + param_3]
//         004a7226     MOV        EAX,dword ptr [ESP + param_1]
//         004a722d     MOV        dword ptr [EBP + 0x6a0],this
//                              scr_save.cpp:69 (111)
//         004a7233     MOV        this,dword ptr [ESP + param_2]
//         004a723a     LEA        EBX,[EBP + 0x478]
//         004a7240     MOV        dword ptr [ESP + local_4],0x0
//         004a724b     TEST       this,this
//         004a724d     MOV        dword ptr [EBP + 0x69c],EAX
//         004a7253     MOV        dword ptr [EBP],TribeSaveGameScreen::`vftable'   = 004a75a0
//         004a725a     MOV        dword ptr [EBX],0x0
//         004a7260     MOV        dword ptr [EBP + 0x47c],0x0
//         004a726a     MOV        dword ptr [EBP + 0x480],0x0
//         004a7274     MOV        dword ptr [EBP + 0x484],0x0
//         004a727e     MOV        dword ptr [EBP + 0x488],0x0
//         004a7288     MOV        dword ptr [EBP + 0x48c],0x0
//         004a7292     MOV        dword ptr [EBP + 0x490],0x0
//         004a729c     JNZ        LAB_004a72b4
//         004a729e     TEST       EAX,EAX
//         004a72a0     JNZ        LAB_004a72b4
//                              scr_save.cpp:70 (18)
//         004a72a2     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a72a8     CALL       TRIBE_Game::get_save_game_name                   char * get_save_game_name(TRIBE_Game * this)
//         004a72ad     MOV        dword ptr [ESP + param_2],EAX
//                               LAB_004a72b4                                                 XREF[2]:     004a729c(j), 004a72a0(j)
//                              scr_save.cpp:73 (10)
//         004a72b4     MOV        this,panel_system
//         004a72b9     CALL       TPanelSystem::currentPanel                       TPanel * currentPanel(TPanelSystem * this)
//                              scr_save.cpp:75 (28)
//         004a72be     MOV        this,EAX
//         004a72c0     MOV        dword ptr [ESP + tabList[0]],EAX
//         004a72c4     CALL       TEasy_Panel::get_popup_info_file                 char * get_popup_info_file(TEasy_Panel * this)
//         004a72c9     MOV        EDI,EAX
//         004a72cb     OR         this,0xffffffff
//         004a72ce     XOR        EAX,EAX
//         004a72d0     LEA        EDX=>info_file[4],[ESP + 0x2c]
//         004a72d4     SCASB.RE   ES:EDI
//         004a72d6     NOT        this
//         004a72d8     SUB        EDI,this
//                              scr_save.cpp:77 (56)
//         004a72da     PUSH       0x1
//         004a72dc     MOV        EAX,this
//         004a72de     MOV        ESI,EDI
//         004a72e0     MOV        EDI,EDX
//         004a72e2     SHR        this,0x2
//         004a72e5     MOVSD.REP  ES:EDI,ESI
//         004a72e7     MOV        this,EAX
//         004a72e9     AND        this,0x3
//         004a72ec     MOVSB.REP  ES:EDI,ESI
//         004a72ee     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a72f4     MOV        ESI,dword ptr [ECX + this->_padding_]
//         004a72f7     MOV        this,dword ptr [ESP + tabList[0]]
//         004a72fb     CALL       TEasy_Panel::get_popup_info_id                   long get_popup_info_id(TEasy_Panel * this)
//         004a7300     LEA        EDX=>info_file[4],[ESP + 0x30]
//         004a7304     PUSH       EAX
//         004a7305     PUSH       EDX
//         004a7306     PUSH       ESI
//         004a7307     MOV        this,EBP
//         004a7309     CALL       TScreenPanel::setup                              long setup(TScreenPanel * this, TDrawArea * p
//         004a730e     TEST       EAX,EAX
//         004a7310     JNZ        LAB_004a7321
//                              scr_save.cpp:78 (10)
//         004a7312     MOV        dword ptr [EBP + 0xd8],0x1
//                              scr_save.cpp:79 (5)
//         004a731c     JMP        LAB_004a7581
//                               LAB_004a7321                                                 XREF[1]:     004a7310(j)
//                              scr_save.cpp:82 (9)
//         004a7321     PUSH       0x0
//         004a7323     MOV        this,EBP
//         004a7325     CALL       TEasy_Panel::setup_shadow_area                   void setup_shadow_area(TEasy_Panel * this, in
//                              scr_save.cpp:83 (17)
//         004a732a     PUSH       0x1e0
//         004a732f     PUSH       0x280
//         004a7334     MOV        this,EBP
//         004a7336     CALL       TEasy_Panel::set_ideal_size                      void set_ideal_size(TEasy_Panel * this, long
//                              scr_save.cpp:88 (55)
//         004a733b     MOV        EDX,dword ptr [EBP + 0x69c]
//         004a7341     PUSH       0x0
//         004a7343     PUSH       0x0
//         004a7345     XOR        EAX,EAX
//         004a7347     PUSH       0x1
//         004a7349     PUSH       0x1
//         004a734b     TEST       EDX,EDX
//         004a734d     PUSH       0x1e
//         004a734f     PUSH       0x258
//         004a7354     SETNZ      AL
//         004a7357     PUSH       0x14
//         004a7359     ADD        EAX,0x24c3
//         004a735e     PUSH       0x14
//         004a7360     PUSH       EAX
//         004a7361     PUSH       EBX
//         004a7362     PUSH       EBP
//         004a7363     MOV        this,EBP
//         004a7365     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel *
//         004a736a     TEST       EAX,EAX
//         004a736c     JZ         LAB_004a7581
//                              scr_save.cpp:96 (113)
//         004a7372     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a7378     XOR        EAX,EAX
//         004a737a     LEA        EDX,[ECX + this->_padding_]
//         004a7380     OR         this,0xffffffff
//         004a7383     MOV        EDI,EDX
//         004a7385     SCASB.RE   ES:EDI
//         004a7387     NOT        this
//         004a7389     DEC        this
//         004a738a     MOV        EAX,0x7a
//         004a738f     SUB        EAX,this
//         004a7391     CMP        EAX,0x50
//         004a7394     JBE        LAB_004a739d
//         004a7396     MOV        EAX,0x50
//         004a739b     JMP        LAB_004a73b0
//                               LAB_004a739d                                                 XREF[1]:     004a7394(j)
//         004a739d     MOV        EDI,EDX
//         004a739f     OR         this,0xffffffff
//         004a73a2     XOR        EAX,EAX
//         004a73a4     SCASB.RE   ES:EDI
//         004a73a6     NOT        this
//         004a73a8     DEC        this
//         004a73a9     MOV        EAX,0x7a
//         004a73ae     SUB        EAX,this
//                               LAB_004a73b0                                                 XREF[1]:     004a739b(j)
//         004a73b0     MOV        this,dword ptr [ESP + param_2]
//         004a73b7     PUSH       0x1
//         004a73b9     PUSH       0x1
//         004a73bb     PUSH       0xb
//         004a73bd     PUSH       0x17
//         004a73bf     PUSH       0x258
//         004a73c4     PUSH       0x46
//         004a73c6     PUSH       0x14
//         004a73c8     PUSH       0x5
//         004a73ca     PUSH       EAX
//         004a73cb     LEA        ESI,[EBP + 0x47c]
//         004a73d1     PUSH       this
//         004a73d2     PUSH       ESI
//         004a73d3     PUSH       EBP
//         004a73d4     MOV        this,EBP
//         004a73d6     CALL       TEasy_Panel::create_edit                         int create_edit(TEasy_Panel * this, TPanel *
//         004a73db     TEST       EAX,EAX
//         004a73dd     JZ         LAB_004a7581
//                              scr_save.cpp:97 (14)
//         004a73e3     MOV        this,dword ptr [ESI]
//         004a73e5     PUSH       -0x1
//                              language.dll match for 0x7670: "Type a name for the game."
//         004a73e7     PUSH       0x7670
//         004a73ec     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_save.cpp:100 (39)
//         004a73f1     PUSH       0xb
//         004a73f3     PUSH       0x12c
//         004a73f8     PUSH       0x258
//                              language.dll match for 0x6e: "Copperplate Gothic Light"
//         004a73fd     PUSH       0x6e
//         004a73ff     LEA        ESI,[EBP + 0x480]
//         004a7405     PUSH       0x14
//         004a7407     PUSH       ESI
//         004a7408     PUSH       EBP
//         004a7409     MOV        this,EBP
//         004a740b     CALL       TEasy_Panel::create_list                         int create_list(TEasy_Panel * this, TPanel *
//         004a7410     TEST       EAX,EAX
//         004a7412     JZ         LAB_004a7581
//                              scr_save.cpp:101 (27)
//         004a7418     MOV        EDX,dword ptr [ESI]
//         004a741a     PUSH       0x14
//         004a741c     LEA        ESI,[EBP + 0x484]
//         004a7422     PUSH       EDX
//         004a7423     PUSH       ESI
//         004a7424     MOV        this,EBP
//         004a7426     CALL       TEasy_Panel::create_auto_scrollbar               int create_auto_scrollbar(TEasy_Panel * this,
//         004a742b     TEST       EAX,EAX
//         004a742d     JZ         LAB_004a7581
//                              scr_save.cpp:102 (14)
//         004a7433     MOV        this,dword ptr [ESI]
//         004a7435     PUSH       -0x1
//                              language.dll match for 0x7671: "Select a saved game."
//         004a7437     PUSH       0x7671
//         004a743c     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_save.cpp:105 (50)
//         004a7441     PUSH       0x0
//         004a7443     PUSH       0x0
//         004a7445     PUSH       0x0
//         004a7447     PUSH       0x1e
//         004a7449     PUSH       0xb4
//         004a744e     PUSH       0x1b8
//         004a7453     PUSH       0x1e
//         004a7455     PUSH       0x0
//         004a7457     LEA        ESI,[EBP + 0x488]
//                              language.dll match for 0xfa1: "OK"
//         004a745d     PUSH       0xfa1
//         004a7462     PUSH       ESI
//         004a7463     PUSH       EBP
//         004a7464     MOV        this,EBP
//         004a7466     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel
//         004a746b     TEST       EAX,EAX
//         004a746d     JZ         LAB_004a7581
//                              scr_save.cpp:106 (53)
//         004a7473     PUSH       0x0
//         004a7475     PUSH       0x0
//         004a7477     PUSH       0x0
//         004a7479     PUSH       0x1e
//         004a747b     PUSH       0xb4
//         004a7480     PUSH       0x1b8
//         004a7485     PUSH       0xe6
//         004a748a     PUSH       0x0
//         004a748c     LEA        EBX,[EBP + 0x490]
//                              language.dll match for 0x24c9: "Delete"
//         004a7492     PUSH       0x24c9
//         004a7497     PUSH       EBX
//         004a7498     PUSH       EBP
//         004a7499     MOV        this,EBP
//         004a749b     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel
//         004a74a0     TEST       EAX,EAX
//         004a74a2     JZ         LAB_004a7581
//                              scr_save.cpp:107 (53)
//         004a74a8     PUSH       0x0
//         004a74aa     PUSH       0x0
//         004a74ac     PUSH       0x0
//         004a74ae     PUSH       0x1e
//         004a74b0     PUSH       0xb4
//         004a74b5     PUSH       0x1b8
//         004a74ba     PUSH       0x1ae
//         004a74bf     PUSH       0x0
//         004a74c1     LEA        EDI,[EBP + 0x48c]
//                              language.dll match for 0xfa2: "Cancel"
//         004a74c7     PUSH       0xfa2
//         004a74cc     PUSH       EDI
//         004a74cd     PUSH       EBP
//         004a74ce     MOV        this,EBP
//         004a74d0     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel
//         004a74d5     TEST       EAX,EAX
//         004a74d7     JZ         LAB_004a7581
//                              scr_save.cpp:108 (14)
//         004a74dd     MOV        this,dword ptr [ESI]
//         004a74df     PUSH       -0x1
//         004a74e1     PUSH       0x7531
//         004a74e6     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_save.cpp:109 (14)
//         004a74eb     MOV        this,dword ptr [EDI]
//         004a74ed     PUSH       -0x1
//         004a74ef     PUSH       0x7532
//         004a74f4     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_save.cpp:111 (20)
//         004a74f9     MOV        EAX,dword ptr [EDI]
//         004a74fb     XOR        this,this
//         004a74fd     MOV        dword ptr [EAX + 0x298],0x1b
//         004a7507     MOV        dword ptr [EAX + 0x29c],this
//                              scr_save.cpp:112 (8)
//         004a750d     MOV        EAX,dword ptr [EBX]
//         004a750f     MOV        dword ptr [EAX + 0x29c],this
//                              scr_save.cpp:115 (17)
//         004a7515     MOV        this,EBP
//         004a7517     MOV        dword ptr [EAX + 0x298],0x2e
//         004a7521     CALL       TribeSaveGameScreen::fillList                    void fillList(TribeSaveGameScreen * this)
//                              scr_save.cpp:117 (16)
//         004a7526     MOV        this,dword ptr [EBP + 0x480]
//         004a752c     CALL       TTextPanel::currentLine                          char * currentLine(TTextPanel * this)
//         004a7531     CMP        byte ptr [EAX],0x0
//         004a7534     JNZ        LAB_004a753f
//                              scr_save.cpp:118 (9)
//         004a7536     MOV        this,dword ptr [EBX]
//         004a7538     PUSH       0x1
//         004a753a     CALL       TButtonPanel::set_disabled                       void set_disabled(TButtonPanel * this, int pa
//                               LAB_004a753f                                                 XREF[1]:     004a7534(j)
//                              scr_save.cpp:121 (14)
//         004a753f     MOV        EAX,dword ptr [EBP + 0x47c]
//         004a7545     MOV        this,EBP
//         004a7547     PUSH       EAX
//         004a7548     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
//                              scr_save.cpp:124 (6)
//         004a754d     MOV        this,dword ptr [EBP + 0x47c]
//                              scr_save.cpp:126 (12)
//         004a7553     MOV        EAX,dword ptr [ESI]
//         004a7555     MOV        EDX,dword ptr [EBP + 0x480]
//         004a755b     MOV        dword ptr [ESP + tabList[1]],this
//                              scr_save.cpp:127 (10)
//         004a755f     MOV        this,dword ptr [EBX]
//         004a7561     MOV        dword ptr [ESP + tabList[3]],EAX
//         004a7565     MOV        dword ptr [ESP + tabList[2]],EDX
//                              scr_save.cpp:128 (2)
//         004a7569     MOV        EDX,dword ptr [EDI]
//                              scr_save.cpp:129 (22)
//         004a756b     LEA        EAX=>tabList[1],[ESP + 0x14]
//         004a756f     MOV        dword ptr [ESP + tabList[4]],this
//         004a7573     PUSH       0x5
//         004a7575     PUSH       EAX
//         004a7576     MOV        this,EBP
//         004a7578     MOV        dword ptr [ESP + local_118],EDX
//         004a757c     CALL       TPanel::set_tab_order                            void set_tab_order(TPanel * this, TPanel * *
//                               LAB_004a7581                                                 XREF[8]:     004a731c(j), 004a736c(j),
//                                                                                                         004a73dd(j), 004a7412(j),
//                                                                                                         004a742d(j), 004a746d(j),
//                                                                                                         004a74a2(j), 004a74d7(j)
//                              scr_save.cpp:130 (29)
//         004a7581     MOV        this,dword ptr [ESP + local_c]
//         004a7588     POP        EDI
//         004a7589     MOV        EAX,EBP
//         004a758b     POP        ESI
//         004a758c     POP        EBP
//         004a758d     MOV        dword ptr FS:[0x0],this
//         004a7594     POP        EBX
//         004a7595     ADD        ESP,0x12c
//         004a759b     RET        0xc
//         004a759e     ??         90h
//         004a759f     NOP
}

TribeSaveGameScreen::~TribeSaveGameScreen() {
    /* TODO: Stub */
//                              void __thiscall ~TribeSaveGameScreen(TribeSaveGameScreen * this)
//              void              <VOID>         <RETURN>
//              TribeSaveGameS    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004a75e9(W), 004a764d(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004a765a(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004a75d9(W)
//                               ??1TribeSaveGameScreen@@UAE@XZ                               XREF[1]:     `vector_deleting_destructor':004a7
//                               TribeSaveGameScreen::~TribeSaveGameScreen
//                              scr_save.cpp:135 (35)
//         004a75c0     PUSH       -0x1
//         004a75c2     PUSH       FUN_0055f3d8
//         004a75c7     MOV        EAX,FS:[0x0]
//         004a75cd     PUSH       EAX
//         004a75ce     MOV        dword ptr FS:[0x0],ESP
//         004a75d5     PUSH       this
//         004a75d6     PUSH       ESI
//         004a75d7     MOV        ESI,this
//         004a75d9     MOV        dword ptr [ESP + local_10],ESI
//         004a75dd     MOV        dword ptr [ESI],TribeSaveGameScreen::`vftable'   = 004a75a0
//                              scr_save.cpp:136 (20)
//         004a75e3     LEA        EAX,[ESI + 0x478]
//         004a75e9     MOV        dword ptr [ESP + local_4],0x0
//         004a75f1     PUSH       EAX
//         004a75f2     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//                              scr_save.cpp:137 (14)
//         004a75f7     LEA        this,[ESI + 0x47c]
//         004a75fd     PUSH       this
//         004a75fe     MOV        this,ESI
//         004a7600     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//                              scr_save.cpp:138 (14)
//         004a7605     LEA        EDX,[ESI + 0x480]
//         004a760b     MOV        this,ESI
//         004a760d     PUSH       EDX
//         004a760e     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//                              scr_save.cpp:139 (14)
//         004a7613     LEA        EAX,[ESI + 0x484]
//         004a7619     MOV        this,ESI
//         004a761b     PUSH       EAX
//         004a761c     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//                              scr_save.cpp:140 (14)
//         004a7621     LEA        this,[ESI + 0x488]
//         004a7627     PUSH       this
//         004a7628     MOV        this,ESI
//         004a762a     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//                              scr_save.cpp:141 (14)
//         004a762f     LEA        EDX,[ESI + 0x48c]
//         004a7635     MOV        this,ESI
//         004a7637     PUSH       EDX
//         004a7638     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//                              scr_save.cpp:142 (16)
//         004a763d     LEA        EAX,[ESI + 0x490]
//         004a7643     MOV        this,ESI
//         004a7645     PUSH       EAX
//         004a7646     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//         004a764b     MOV        this,ESI
//                              scr_save.cpp:143 (29)
//         004a764d     MOV        dword ptr [ESP + local_4],0xffffffff
//         004a7655     CALL       TScreenPanel::~TScreenPanel                      void ~TScreenPanel(TScreenPanel * this)
//         004a765a     MOV        this,dword ptr [ESP + local_c]
//         004a765e     POP        ESI
//         004a765f     MOV        dword ptr FS:[0x0],this
//         004a7666     ADD        ESP,0x10
//         004a7669     RET
//         004a766a     ??         90h
//         004a766b     NOP
//         004a766c     NOP
//         004a766d     NOP
//         004a766e     NOP
//         004a766f     NOP
}

void TribeSaveGameScreen::fillList() {
    /* TODO: Stub */
//                              void __thiscall fillList(TribeSaveGameScreen * this)
//              void              <VOID>         <RETURN>
//              TribeSaveGameS    ECX:4 (auto)   this
//              _finddata_t       Stack[-0x11c   fileInfo                  XREF[0,10]:  004a76c3(*), 004a76f3(*), 004a7752(*), 004a7793(*),
//                                                                                     004a77c3(*), 004a7822(*), 004a770f(*), 004a771b(*),
//                                                                                     004a77df(*), 004a77f6(*)
//              char[260]         Stack[-0x220   file_name                 XREF[0,12]:  004a76a7(*), 004a76ca(*), 004a76d7(*), 004a76fa(*),
//                                                                                     004a7727(*), 004a773b(*), 004a7777(*), 004a779a(*),
//                                                                                     004a77a8(*), 004a77ca(*), 004a77eb(*), 004a7811(*)
//                               ?fillList@TribeSaveGameScreen@@IAEXXZ                        XREF[1]:     TribeSaveGameScreen:004a7521(c)
//                               TribeSaveGameScreen::fillList
//                              scr_save.cpp:148 (12)
//         004a7670     SUB        ESP,0x21c
//         004a7676     PUSH       EBX
//         004a7677     PUSH       EBP
//         004a7678     MOV        EBP,this
//         004a767a     PUSH       ESI
//         004a767b     PUSH       EDI
//                              scr_save.cpp:155 (11)
//         004a767c     MOV        this,dword ptr [EBP + 0x480]
//         004a7682     CALL       TTextPanel::empty_list                           void empty_list(TTextPanel * this)
//                              scr_save.cpp:156 (16)
//         004a7687     MOV        EAX,dword ptr [EBP + 0x480]
//         004a768d     MOV        dword ptr [EAX + 0x15c],0x1
//                              scr_save.cpp:161 (10)
//         004a7697     MOV        EAX,dword ptr [EBP + 0x69c]
//         004a769d     TEST       EAX,EAX
//         004a769f     JNZ        LAB_004a76d2
//                              scr_save.cpp:163 (34)
//         004a76a1     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a76a7     LEA        EAX=>file_name[4],[ESP + 0x10]
//         004a76ab     MOV        EDX,dword ptr [ECX + this->_padding_]
//         004a76ae     ADD        EDX,0xb12
//         004a76b4     PUSH       EDX
//         004a76b5     PUSH       s_%s*.gam                                        = "%s*.gam"
//         004a76ba     PUSH       EAX
//         004a76bb     CALL       sprintf                                          undefined sprintf()
//         004a76c0     ADD        ESP,0xc
//                              scr_save.cpp:164 (13)
//         004a76c3     LEA        this=>fileInfo.time_create,[ESP + 0x114]
//         004a76ca     LEA        EDX=>file_name[4],[ESP + 0x10]
//         004a76ce     PUSH       this
//         004a76cf     PUSH       EDX
//                              scr_save.cpp:166 (2)
//         004a76d0     JMP        LAB_004a7700
//                               LAB_004a76d2                                                 XREF[1]:     004a769f(j)
//                              scr_save.cpp:168 (33)
//         004a76d2     MOV        EAX,[rge_base_game]                              = 00000000
//         004a76d7     LEA        EDX=>file_name[4],[ESP + 0x10]
//         004a76db     MOV        this,dword ptr [EAX + 0xc]
//         004a76de     ADD        this,0xc17
//         004a76e4     PUSH       this
//         004a76e5     PUSH       s_%s*.scn                                        = "%s*.scn"
//         004a76ea     PUSH       EDX
//         004a76eb     CALL       sprintf                                          undefined sprintf()
//         004a76f0     ADD        ESP,0xc
//                              scr_save.cpp:169 (23)
//         004a76f3     LEA        EAX=>fileInfo.time_create,[ESP + 0x114]
//         004a76fa     LEA        this=>file_name[4],[ESP + 0x10]
//         004a76fe     PUSH       EAX
//         004a76ff     PUSH       this
//                               LAB_004a7700                                                 XREF[1]:     004a76d0(j)
//         004a7700     CALL       __findfirst                                      undefined __findfirst()
//         004a7705     MOV        EBX,EAX
//         004a7707     ADD        ESP,0x8
//                              scr_save.cpp:171 (5)
//         004a770a     CMP        EBX,-0x1
//         004a770d     JZ         LAB_004a7768
//                               LAB_004a770f                                                 XREF[1]:     004a7766(j)
//                              scr_save.cpp:172 (12)
//         004a770f     LEA        EDI=>fileInfo+0x18,[ESP + 0x128]
//         004a7716     OR         this,0xffffffff
//         004a7719     XOR        EAX,EAX
//                              scr_save.cpp:173 (32)
//         004a771b     LEA        EDX=>fileInfo+0x18,[ESP + 0x128]
//         004a7722     SCASB.RE   ES:EDI
//         004a7724     NOT        this
//         004a7726     DEC        this
//         004a7727     LEA        EAX=>file_name[4],[ESP + 0x10]
//         004a772b     MOV        ESI,this
//         004a772d     SUB        ESI,0x4
//         004a7730     PUSH       ESI
//         004a7731     PUSH       EDX
//         004a7732     PUSH       EAX
//         004a7733     CALL       strncpy                                          undefined strncpy()
//         004a7738     ADD        ESP,0xc
//                              scr_save.cpp:175 (23)
//         004a773b     LEA        this=>file_name[4],[ESP + 0x10]
//         004a773f     MOV        byte ptr [ESP + ESI*0x1 + 0x10],0x0
//         004a7744     PUSH       0x0
//         004a7746     PUSH       this
//         004a7747     MOV        this,dword ptr [EBP + 0x480]
//         004a774d     CALL       TTextPanel::append_line                          int append_line(TTextPanel * this, char * par
//                              scr_save.cpp:176 (22)
//         004a7752     LEA        EDX=>fileInfo.time_create,[ESP + 0x114]
//         004a7759     PUSH       EDX
//         004a775a     PUSH       EBX
//         004a775b     CALL       __findnext                                       undefined __findnext()
//         004a7760     ADD        ESP,0x8
//         004a7763     CMP        EAX,-0x1
//         004a7766     JNZ        LAB_004a770f
//                               LAB_004a7768                                                 XREF[1]:     004a770d(j)
//                              scr_save.cpp:180 (10)
//         004a7768     MOV        EAX,dword ptr [EBP + 0x69c]
//         004a776e     TEST       EAX,EAX
//         004a7770     JNZ        LAB_004a77a2
//                              scr_save.cpp:182 (33)
//         004a7772     MOV        EAX,[rge_base_game]                              = 00000000
//         004a7777     LEA        EDX=>file_name[4],[ESP + 0x10]
//         004a777b     MOV        this,dword ptr [EAX + 0xc]
//         004a777e     ADD        this,0xb12
//         004a7784     PUSH       this
//         004a7785     PUSH       s_%s*.gmx                                        = "%s*.gmx"
//         004a778a     PUSH       EDX
//         004a778b     CALL       sprintf                                          undefined sprintf()
//         004a7790     ADD        ESP,0xc
//                              scr_save.cpp:183 (13)
//         004a7793     LEA        EAX=>fileInfo.time_create,[ESP + 0x114]
//         004a779a     LEA        this=>file_name[4],[ESP + 0x10]
//         004a779e     PUSH       EAX
//         004a779f     PUSH       this
//                              scr_save.cpp:185 (2)
//         004a77a0     JMP        LAB_004a77d0
//                               LAB_004a77a2                                                 XREF[1]:     004a7770(j)
//                              scr_save.cpp:187 (33)
//         004a77a2     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
//         004a77a8     LEA        this=>file_name[4],[ESP + 0x10]
//         004a77ac     MOV        EAX,dword ptr [EDX + 0xc]
//         004a77af     ADD        EAX,0xc17
//         004a77b4     PUSH       EAX
//         004a77b5     PUSH       s_%s*.scx                                        = "%s*.scx"
//         004a77ba     PUSH       this
//         004a77bb     CALL       sprintf                                          undefined sprintf()
//         004a77c0     ADD        ESP,0xc
//                              scr_save.cpp:188 (23)
//         004a77c3     LEA        EDX=>fileInfo.time_create,[ESP + 0x114]
//         004a77ca     LEA        EAX=>file_name[4],[ESP + 0x10]
//         004a77ce     PUSH       EDX
//         004a77cf     PUSH       EAX
//                               LAB_004a77d0                                                 XREF[1]:     004a77a0(j)
//         004a77d0     CALL       __findfirst                                      undefined __findfirst()
//         004a77d5     MOV        EBX,EAX
//         004a77d7     ADD        ESP,0x8
//                              scr_save.cpp:191 (5)
//         004a77da     CMP        EBX,-0x1
//         004a77dd     JZ         LAB_004a7838
//                               LAB_004a77df                                                 XREF[1]:     004a7836(j)
//                              scr_save.cpp:192 (12)
//         004a77df     LEA        EDI=>fileInfo+0x18,[ESP + 0x128]
//         004a77e6     OR         this,0xffffffff
//         004a77e9     XOR        EAX,EAX
//                              scr_save.cpp:193 (29)
//         004a77eb     LEA        EDX=>file_name[4],[ESP + 0x10]
//         004a77ef     SCASB.RE   ES:EDI
//         004a77f1     NOT        this
//         004a77f3     DEC        this
//         004a77f4     MOV        ESI,this
//         004a77f6     LEA        this=>fileInfo+0x18,[ESP + 0x128]
//         004a77fd     SUB        ESI,0x4
//         004a7800     PUSH       ESI
//         004a7801     PUSH       this
//         004a7802     PUSH       EDX
//         004a7803     CALL       strncpy                                          undefined strncpy()
//                              scr_save.cpp:195 (26)
//         004a7808     MOV        this,dword ptr [EBP + 0x480]
//         004a780e     ADD        ESP,0xc
//         004a7811     LEA        EAX=>file_name[4],[ESP + 0x10]
//         004a7815     MOV        byte ptr [ESP + ESI*0x1 + 0x10],0x0
//         004a781a     PUSH       0x0
//         004a781c     PUSH       EAX
//         004a781d     CALL       TTextPanel::append_line                          int append_line(TTextPanel * this, char * par
//                              scr_save.cpp:196 (22)
//         004a7822     LEA        this=>fileInfo.time_create,[ESP + 0x114]
//         004a7829     PUSH       this
//         004a782a     PUSH       EBX
//         004a782b     CALL       __findnext                                       undefined __findnext()
//         004a7830     ADD        ESP,0x8
//         004a7833     CMP        EAX,-0x1
//         004a7836     JNZ        LAB_004a77df
//                               LAB_004a7838                                                 XREF[1]:     004a77dd(j)
//                              scr_save.cpp:199 (11)
//         004a7838     POP        EDI
//         004a7839     POP        ESI
//         004a783a     POP        EBP
//         004a783b     POP        EBX
//         004a783c     ADD        ESP,0x21c
//         004a7842     RET
//         004a7843     ??         90h
//         004a7844     NOP
//         004a7845     NOP
//         004a7846     NOP
//         004a7847     NOP
//         004a7848     NOP
//         004a7849     NOP
//         004a784a     NOP
//         004a784b     NOP
//         004a784c     NOP
//         004a784d     NOP
//         004a784e     NOP
//         004a784f     NOP
    return;
}

long TribeSaveGameScreen::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    /* TODO: Stub */
//                              long __thiscall action(TribeSaveGameScreen * this, TPanel * param_1,
//              long              EAX:4          <RETURN>
//              TribeSaveGameS    ECX:4 (auto)   this
//              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     004a7861(R)
//              long              Stack[0x8]:4   param_2                   XREF[2]:     004a7857(R), 004a78cd(R)
//              ulong             Stack[0xc]:4   param_3                   XREF[1]:     004a8040(R)
//              ulong             Stack[0x10]:4  param_4                   XREF[1]:     004a8039(R)
//              char[556]         Stack[-0x230   text                      XREF[0,2]:   004a7a4b(*), 004a7a5c(*)
//              char[260]         Stack[-0x334   tempFileName              XREF[0,22]:  004a7b4c(W), 004a7bc2(W), 004a7c28(R), 004a7c4e(W),
//                                                                                     004a7c5b(R), 004a7901(*), 004a7929(*), 004a793b(*),
//                                                                                     004a798d(*), 004a799a(*), 004a7a25(*), 004a7a47(*),
//                                                                                     004a7b99(*), 004a7bab(*), 004a7c19(*), 004a7c37(*),
//                                                                                     004a7eb7(*), 004a7ed3(*), 004a7f47(*), 004a7f62(*)
//              uchar             Stack[-0x335   exist_flag
//                               ?action@TribeSaveGameScreen@@MAEJPAVTPanel@@JKK@Z            XREF[1]:     0057394c(*)
//                               TribeSaveGameScreen::action
//                              scr_save.cpp:204 (7)
//         004a7850     SUB        ESP,0x334
//         004a7856     PUSH       EBX
//                              scr_save.cpp:205 (27)
//         004a7857     MOV        EBX,dword ptr [ESP + param_2]
//         004a785e     PUSH       EBP
//         004a785f     PUSH       ESI
//         004a7860     PUSH       EDI
//         004a7861     MOV        EDI,dword ptr [ESP + param_1]
//         004a7868     TEST       EDI,EDI
//         004a786a     MOV        EBP,this
//         004a786c     JZ         LAB_004a8039
//                              scr_save.cpp:206 (76)
//         004a7872     MOV        this,EDI
//         004a7874     CALL       TPanel::panelName                                char * panelName(TPanel * this)
//         004a7879     TEST       EAX,EAX
//         004a787b     JZ         LAB_004a7a08
//         004a7881     MOV        this,EDI
//         004a7883     MOV        ESI,s_Cancel_Dialog                              = 43h
//         004a7888     CALL       TPanel::panelName                                char * panelName(TPanel * this)
//                               LAB_004a788d                                                 XREF[1]:     004a78ab(j)
//         004a788d     MOV        DL,byte ptr [EAX]
//         004a788f     MOV        this,DL
//         004a7891     CMP        DL,byte ptr [ESI]=>s_Cancel_Dialog               = 43h
//                                                                                  = 6Eh
//         004a7893     JNZ        LAB_004a78b1
//         004a7895     TEST       this,this
//         004a7897     JZ         LAB_004a78ad
//         004a7899     MOV        DL,byte ptr [EAX + 0x1]
//         004a789c     MOV        this,DL
//         004a789e     CMP        DL,byte ptr [ESI + 0x1]=>DAT_005860e5            = 61h
//                                                                                  = "cel Dialog"
//         004a78a1     JNZ        LAB_004a78b1
//         004a78a3     ADD        EAX,0x2
//         004a78a6     ADD        ESI,0x2
//         004a78a9     TEST       this,this
//         004a78ab     JNZ        LAB_004a788d
//                               LAB_004a78ad                                                 XREF[1]:     004a7897(j)
//         004a78ad     XOR        EAX,EAX
//         004a78af     JMP        LAB_004a78b6
//                               LAB_004a78b1                                                 XREF[2]:     004a7893(j), 004a78a1(j)
//         004a78b1     SBB        EAX,EAX
//         004a78b3     SBB        EAX,-0x1
//                               LAB_004a78b6                                                 XREF[1]:     004a78af(j)
//         004a78b6     TEST       EAX,EAX
//         004a78b8     JNZ        LAB_004a7a08
//                              scr_save.cpp:208 (15)
//         004a78be     PUSH       s_Cancel_Dialog                                  = 43h
//         004a78c3     MOV        this,panel_system
//         004a78c8     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char *
//                              scr_save.cpp:210 (15)
//         004a78cd     MOV        EAX,dword ptr [ESP + param_2]
//         004a78d4     TEST       EAX,EAX
//         004a78d6     JNZ        LAB_004a8027
//                              scr_save.cpp:215 (10)
//         004a78dc     MOV        EAX,dword ptr [EBP + 0x69c]
//         004a78e2     TEST       EAX,EAX
//         004a78e4     JNZ        LAB_004a790d
//                              scr_save.cpp:216 (37)
//         004a78e6     MOV        EAX,[rge_base_game]                              = 00000000
//         004a78eb     MOV        this,dword ptr [EBP + 0x480]
//         004a78f1     MOV        ESI,dword ptr [EAX + 0xc]
//         004a78f4     ADD        ESI,0xb12
//         004a78fa     CALL       TTextPanel::currentLine                          char * currentLine(TTextPanel * this)
//         004a78ff     PUSH       EAX
//         004a7900     PUSH       ESI
//         004a7901     LEA        this=>tempFileName[4],[ESP + 0x1c]
//         004a7905     PUSH       s_%s%s.gam                                       = "%s%s.gam"
//         004a790a     PUSH       this
//                              scr_save.cpp:217 (2)
//         004a790b     JMP        LAB_004a7933
//                               LAB_004a790d                                                 XREF[1]:     004a78e4(j)
//                              scr_save.cpp:218 (46)
//         004a790d     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
//         004a7913     MOV        this,dword ptr [EBP + 0x480]
//         004a7919     MOV        ESI,dword ptr [EDX + 0xc]
//         004a791c     ADD        ESI,0xc17
//         004a7922     CALL       TTextPanel::currentLine                          char * currentLine(TTextPanel * this)
//         004a7927     PUSH       EAX
//         004a7928     PUSH       ESI
//         004a7929     LEA        EAX=>tempFileName[4],[ESP + 0x1c]
//         004a792d     PUSH       s_%s%s.scn                                       = "%s%s.scn"
//         004a7932     PUSH       EAX
//                               LAB_004a7933                                                 XREF[1]:     004a790b(j)
//         004a7933     CALL       sprintf                                          undefined sprintf()
//         004a7938     ADD        ESP,0x10
//                              scr_save.cpp:220 (10)
//         004a793b     LEA        this=>tempFileName[4],[ESP + 0x14]
//         004a793f     PUSH       this
//         004a7940     CALL       __unlink                                         undefined __unlink()
//                              scr_save.cpp:221 (6)
//         004a7945     MOV        EAX,dword ptr [EBP + 0x69c]
//                              scr_save.cpp:223 (40)
//         004a794b     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
//         004a7951     ADD        ESP,0x4
//         004a7954     MOV        ESI,dword ptr [EDX + 0xc]
//         004a7957     TEST       EAX,EAX
//         004a7959     JNZ        LAB_004a7975
//         004a795b     MOV        this,dword ptr [EBP + 0x480]
//         004a7961     ADD        ESI,0xb12
//         004a7967     CALL       TTextPanel::currentLine                          char * currentLine(TTextPanel * this)
//         004a796c     PUSH       EAX
//         004a796d     PUSH       ESI
//         004a796e     PUSH       s_%s%s.gmx                                       = "%s%s.gmx"
//                              scr_save.cpp:226 (2)
//         004a7973     JMP        LAB_004a798d
//                               LAB_004a7975                                                 XREF[1]:     004a7959(j)
//                              scr_save.cpp:228 (37)
//         004a7975     MOV        this,dword ptr [EBP + 0x480]
//         004a797b     ADD        ESI,0xc17
//         004a7981     CALL       TTextPanel::currentLine                          char * currentLine(TTextPanel * this)
//         004a7986     PUSH       EAX
//         004a7987     PUSH       ESI
//         004a7988     PUSH       s_%s%s.scx                                       = "%s%s.scx"
//                               LAB_004a798d                                                 XREF[1]:     004a7973(j)
//         004a798d     LEA        EAX=>tempFileName[4],[ESP + 0x20]
//         004a7991     PUSH       EAX
//         004a7992     CALL       sprintf                                          undefined sprintf()
//         004a7997     ADD        ESP,0x10
//                              scr_save.cpp:229 (10)
//         004a799a     LEA        this=>tempFileName[4],[ESP + 0x14]
//         004a799e     PUSH       this
//         004a799f     CALL       __unlink                                         undefined __unlink()
//                              scr_save.cpp:233 (26)
//         004a79a4     MOV        this,dword ptr [EBP + 0x480]
//         004a79aa     ADD        ESP,0x4
//         004a79ad     CALL       TTextPanel::get_line                             long get_line(TTextPanel * this)
//         004a79b2     MOV        this,dword ptr [EBP + 0x480]
//         004a79b8     PUSH       EAX
//         004a79b9     CALL       TTextPanel::delete_line                          int delete_line(TTextPanel * this, long param
//                              scr_save.cpp:234 (23)
//         004a79be     MOV        this,dword ptr [EBP + 0x480]
//         004a79c4     CALL       TTextPanel::currentLine                          char * currentLine(TTextPanel * this)
//         004a79c9     MOV        this,dword ptr [EBP + 0x47c]
//         004a79cf     PUSH       EAX
//         004a79d0     CALL       TEditPanel::set_text                             void set_text(TEditPanel * this, char * param
//                              scr_save.cpp:235 (20)
//         004a79d5     MOV        this,dword ptr [EBP + 0x480]
//         004a79db     CALL       TTextPanel::currentLine                          char * currentLine(TTextPanel * this)
//         004a79e0     CMP        byte ptr [EAX],0x0
//         004a79e3     JNZ        LAB_004a8027
//                              scr_save.cpp:236 (13)
//         004a79e9     MOV        this,dword ptr [EBP + 0x490]
//         004a79ef     PUSH       0x1
//         004a79f1     CALL       TButtonPanel::set_disabled                       void set_disabled(TButtonPanel * this, int pa
//                              scr_save.cpp:240 (5)
//         004a79f6     MOV        EAX,0x1
//                              scr_save.cpp:402 (13)
//         004a79fb     POP        EDI
//         004a79fc     POP        ESI
//         004a79fd     POP        EBP
//         004a79fe     POP        EBX
//         004a79ff     ADD        ESP,0x334
//         004a7a05     RET        0x10
//                               LAB_004a7a08                                                 XREF[2]:     004a787b(j), 004a78b8(j)
//                              scr_save.cpp:242 (13)
//         004a7a08     CMP        EDI,dword ptr [EBP + 0x490]
//         004a7a0e     JNZ        LAB_004a7a77
//         004a7a10     CMP        EBX,0x1
//         004a7a13     JNZ        LAB_004a7a77
//                              scr_save.cpp:246 (16)
//         004a7a15     MOV        this,dword ptr [EBP + 0x480]
//         004a7a1b     CALL       TTextPanel::currentLine                          char * currentLine(TTextPanel * this)
//         004a7a20     CMP        byte ptr [EAX],0x0
//         004a7a23     JZ         LAB_004a7a77
//                              scr_save.cpp:248 (22)
//         004a7a25     LEA        EDX=>tempFileName[4],[ESP + 0x14]
//         004a7a29     PUSH       0x100
//         004a7a2e     PUSH       EDX
//                              language.dll match for 0x24ca: "Are you sure you want to dele
//         004a7a2f     PUSH       0x24ca
//         004a7a34     MOV        this,EBP
//         004a7a36     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
//                              scr_save.cpp:249 (33)
//         004a7a3b     MOV        this,dword ptr [EBP + 0x480]
//         004a7a41     CALL       TTextPanel::currentLine                          char * currentLine(TTextPanel * this)
//         004a7a46     PUSH       EAX
//         004a7a47     LEA        EAX=>tempFileName[4],[ESP + 0x18]
//         004a7a4b     LEA        this=>text[4],[ESP + 0x11c]
//         004a7a52     PUSH       EAX
//         004a7a53     PUSH       this
//         004a7a54     CALL       sprintf                                          undefined sprintf()
//         004a7a59     ADD        ESP,0xc
//                              scr_save.cpp:250 (27)
//         004a7a5c     LEA        EDX=>text[4],[ESP + 0x118]
//         004a7a63     MOV        this,EBP
//         004a7a65     PUSH       0x64
//         004a7a67     PUSH       0x1c2
//         004a7a6c     PUSH       s_Cancel_Dialog                                  = 43h
//         004a7a71     PUSH       EDX
//         004a7a72     CALL       TEasy_Panel::popupYesNoDialog                    void popupYesNoDialog(TEasy_Panel * this, cha
//                               LAB_004a7a77                                                 XREF[3]:     004a7a0e(j), 004a7a13(j),
//                                                                                                         004a7a23(j)
//                              scr_save.cpp:253 (15)
//         004a7a77     MOV        this,dword ptr [EBP + 0x480]
//         004a7a7d     CMP        EDI,this
//         004a7a7f     JNZ        LAB_004a7aa6
//         004a7a81     CMP        EBX,0x1
//         004a7a84     JNZ        LAB_004a7aa6
//                              scr_save.cpp:254 (17)
//         004a7a86     CALL       TTextPanel::currentLine                          char * currentLine(TTextPanel * this)
//         004a7a8b     MOV        this,dword ptr [EBP + 0x47c]
//         004a7a91     PUSH       EAX
//         004a7a92     CALL       TEditPanel::set_text                             void set_text(TEditPanel * this, char * param
//                              scr_save.cpp:255 (2)
//         004a7a97     MOV        EAX,EBX
//                              scr_save.cpp:402 (13)
//         004a7a99     POP        EDI
//         004a7a9a     POP        ESI
//         004a7a9b     POP        EBP
//         004a7a9c     POP        EBX
//         004a7a9d     ADD        ESP,0x334
//         004a7aa3     RET        0x10
//                               LAB_004a7aa6                                                 XREF[2]:     004a7a7f(j), 004a7a84(j)
//                              scr_save.cpp:259 (44)
//         004a7aa6     CMP        EDI,dword ptr [EBP + 0x488]
//         004a7aac     JNZ        LAB_004a7ab3
//         004a7aae     CMP        EBX,0x1
//         004a7ab1     JZ         LAB_004a7ad2
//                               LAB_004a7ab3                                                 XREF[1]:     004a7aac(j)
//         004a7ab3     MOV        EAX,dword ptr [EBP + 0x47c]
//         004a7ab9     CMP        EDI,EAX
//         004a7abb     JNZ        LAB_004a7ac1
//         004a7abd     TEST       EBX,EBX
//         004a7abf     JZ         LAB_004a7ad2
//                               LAB_004a7ac1                                                 XREF[1]:     004a7abb(j)
//         004a7ac1     CMP        EDI,this
//         004a7ac3     JNZ        LAB_004a7d33
//         004a7ac9     CMP        EBX,0x3
//         004a7acc     JNZ        LAB_004a7d33
//                               LAB_004a7ad2                                                 XREF[2]:     004a7ab1(j), 004a7abf(j)
//                              scr_save.cpp:264 (23)
//         004a7ad2     MOV        this,dword ptr [EBP + 0x47c]
//         004a7ad8     LEA        EBX,[EBP + 0x598]
//         004a7ade     PUSH       0x104
//         004a7ae3     PUSH       EBX
//         004a7ae4     CALL       TEditPanel::get_trimmed_str                      char * get_trimmed_str(TEditPanel * this, cha
//                              scr_save.cpp:267 (14)
//         004a7ae9     MOV        EDI,EBX
//         004a7aeb     OR         this,0xffffffff
//         004a7aee     XOR        EAX,EAX
//         004a7af0     SCASB.RE   ES:EDI
//         004a7af2     NOT        this
//         004a7af4     DEC        this
//         004a7af5     JNZ        LAB_004a7b46
//                              scr_save.cpp:268 (6)
//         004a7af7     MOV        EAX,dword ptr [EBP + 0x69c]
//                              scr_save.cpp:269 (18)
//         004a7afd     PUSH       0x64
//         004a7aff     TEST       EAX,EAX
//         004a7b01     PUSH       0x1c2
//         004a7b06     PUSH       0x0
//         004a7b08     JNZ        LAB_004a7b28
//                              language.dll match for 0x24c6: "You must enter a name to save
//         004a7b0a     PUSH       0x24c6
//                              scr_save.cpp:271 (7)
//         004a7b0f     MOV        this,EBP
//         004a7b11     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, long p
//                              scr_save.cpp:272 (5)
//         004a7b16     MOV        EAX,0x1
//                              scr_save.cpp:402 (13)
//         004a7b1b     POP        EDI
//         004a7b1c     POP        ESI
//         004a7b1d     POP        EBP
//         004a7b1e     POP        EBX
//         004a7b1f     ADD        ESP,0x334
//         004a7b25     RET        0x10
//                              language.dll match for 0x24c7: "You must enter a name to save
//                               LAB_004a7b28                                                 XREF[1]:     004a7b08(j)
//                              scr_save.cpp:271 (12)
//         004a7b28     PUSH       0x24c7
//         004a7b2d     MOV        this,EBP
//         004a7b2f     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, long p
//                              scr_save.cpp:272 (5)
//         004a7b34     MOV        EAX,0x1
//                              scr_save.cpp:402 (13)
//         004a7b39     POP        EDI
//         004a7b3a     POP        ESI
//         004a7b3b     POP        EBP
//         004a7b3c     POP        EBX
//         004a7b3d     ADD        ESP,0x334
//         004a7b43     RET        0x10
//                               LAB_004a7b46                                                 XREF[1]:     004a7af5(j)
//                              scr_save.cpp:283 (13)
//         004a7b46     MOV        EAX,dword ptr [EBP + 0x69c]
//         004a7b4c     MOV        byte ptr [ESP + tempFileName[3]],0x0
//         004a7b51     TEST       EAX,EAX
//                              scr_save.cpp:285 (20)
//         004a7b53     LEA        ESI,[EBP + 0x494]
//         004a7b59     PUSH       EBX
//         004a7b5a     JNZ        LAB_004a7b7b
//         004a7b5c     PUSH       s_%s.gam                                         = "%s.gam"
//         004a7b61     PUSH       ESI
//         004a7b62     CALL       sprintf                                          undefined sprintf()
//                              scr_save.cpp:286 (18)
//         004a7b67     MOV        EAX,[rge_base_game]                              = 00000000
//         004a7b6c     ADD        ESP,0xc
//         004a7b6f     MOV        this,dword ptr [EAX + 0xc]
//         004a7b72     PUSH       ESI
//         004a7b73     ADD        this,0xb12
//                              scr_save.cpp:288 (2)
//         004a7b79     JMP        LAB_004a7b98
//                               LAB_004a7b7b                                                 XREF[1]:     004a7b5a(j)
//                              scr_save.cpp:290 (11)
//         004a7b7b     PUSH       s_%s.scn                                         = "%s.scn"
//         004a7b80     PUSH       ESI
//         004a7b81     CALL       sprintf                                          undefined sprintf()
//                              scr_save.cpp:291 (37)
//         004a7b86     MOV        EAX,[rge_base_game]                              = 00000000
//         004a7b8b     ADD        ESP,0xc
//         004a7b8e     MOV        this,dword ptr [EAX + 0xc]
//         004a7b91     PUSH       ESI
//         004a7b92     ADD        this,0xc17
//                               LAB_004a7b98                                                 XREF[1]:     004a7b79(j)
//         004a7b98     PUSH       this
//         004a7b99     LEA        EDX=>tempFileName[4],[ESP + 0x1c]
//         004a7b9d     PUSH       s_%s%s                                           = "%s%s"
//         004a7ba2     PUSH       EDX
//         004a7ba3     CALL       sprintf                                          undefined sprintf()
//         004a7ba8     ADD        ESP,0x10
//                              scr_save.cpp:294 (22)
//         004a7bab     LEA        EAX=>tempFileName[4],[ESP + 0x14]
//         004a7baf     PUSH       s_rb                                             = "rb"
//         004a7bb4     PUSH       EAX
//         004a7bb5     CALL       fopen                                            undefined fopen()
//         004a7bba     ADD        ESP,0x8
//         004a7bbd     TEST       EAX,EAX
//         004a7bbf     JZ         LAB_004a7bcf
//                              scr_save.cpp:297 (14)
//         004a7bc1     PUSH       EAX
//         004a7bc2     MOV        byte ptr [ESP + tempFileName[3]],0x1
//         004a7bc7     CALL       fclose                                           undefined fclose()
//         004a7bcc     ADD        ESP,0x4
//                               LAB_004a7bcf                                                 XREF[1]:     004a7bbf(j)
//                              scr_save.cpp:301 (6)
//         004a7bcf     MOV        EAX,dword ptr [EBP + 0x69c]
//                              scr_save.cpp:303 (16)
//         004a7bd5     PUSH       EBX
//         004a7bd6     TEST       EAX,EAX
//         004a7bd8     JNZ        LAB_004a7bfa
//         004a7bda     PUSH       s_%s.gmx                                         = "%s.gmx"
//         004a7bdf     PUSH       ESI
//         004a7be0     CALL       sprintf                                          undefined sprintf()
//                              scr_save.cpp:304 (19)
//         004a7be5     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a7beb     ADD        ESP,0xc
//         004a7bee     MOV        EDX,dword ptr [ECX + this->_padding_]
//         004a7bf1     PUSH       ESI
//         004a7bf2     ADD        EDX,0xb12
//                              scr_save.cpp:306 (2)
//         004a7bf8     JMP        LAB_004a7c18
//                               LAB_004a7bfa                                                 XREF[1]:     004a7bd8(j)
//                              scr_save.cpp:308 (11)
//         004a7bfa     PUSH       s_%s.scx                                         = "%s.scx"
//         004a7bff     PUSH       ESI
//         004a7c00     CALL       sprintf                                          undefined sprintf()
//                              scr_save.cpp:309 (35)
//         004a7c05     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a7c0b     ADD        ESP,0xc
//         004a7c0e     MOV        EDX,dword ptr [ECX + this->_padding_]
//         004a7c11     PUSH       ESI
//         004a7c12     ADD        EDX,0xc17
//                               LAB_004a7c18                                                 XREF[1]:     004a7bf8(j)
//         004a7c18     PUSH       EDX
//         004a7c19     LEA        EAX=>tempFileName[4],[ESP + 0x1c]
//         004a7c1d     PUSH       s_%s%s                                           = "%s%s"
//         004a7c22     PUSH       EAX
//         004a7c23     CALL       sprintf                                          undefined sprintf()
//                              scr_save.cpp:312 (37)
//         004a7c28     MOV        AL,byte ptr [ESP + tempFileName[3]]
//         004a7c2c     ADD        ESP,0x10
//         004a7c2f     TEST       AL,AL
//         004a7c31     JNZ        LAB_004a7d0c
//         004a7c37     LEA        this=>tempFileName[4],[ESP + 0x14]
//         004a7c3b     PUSH       s_rb                                             = "rb"
//         004a7c40     PUSH       this
//         004a7c41     CALL       fopen                                            undefined fopen()
//         004a7c46     ADD        ESP,0x8
//         004a7c49     TEST       EAX,EAX
//         004a7c4b     JZ         LAB_004a7c5b
//                              scr_save.cpp:315 (14)
//         004a7c4d     PUSH       EAX
//         004a7c4e     MOV        byte ptr [ESP + tempFileName[3]],0x1
//         004a7c53     CALL       fclose                                           undefined fclose()
//         004a7c58     ADD        ESP,0x4
//                               LAB_004a7c5b                                                 XREF[1]:     004a7c4b(j)
//                              scr_save.cpp:318 (12)
//         004a7c5b     MOV        AL,byte ptr [ESP + tempFileName[3]]
//         004a7c5f     TEST       AL,AL
//         004a7c61     JNZ        LAB_004a7d0c
//                              scr_save.cpp:319 (10)
//         004a7c67     MOV        EAX,dword ptr [EBP + 0x69c]
//         004a7c6d     TEST       EAX,EAX
//         004a7c6f     JNZ        LAB_004a7cab
//                              scr_save.cpp:320 (20)
//         004a7c71     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a7c77     PUSH       ESI
//         004a7c78     CALL       TRIBE_Game::save_game                            int save_game(TRIBE_Game * this, char * param
//         004a7c7d     TEST       EAX,EAX
//         004a7c7f     JNZ        LAB_004a8027
//                              scr_save.cpp:321 (20)
//         004a7c85     PUSH       0x64
//         004a7c87     PUSH       0x1c2
//         004a7c8c     PUSH       EAX
//                              language.dll match for 0x962: "The game could not be saved. F
//         004a7c8d     PUSH       0x962
//         004a7c92     MOV        this,EBP
//         004a7c94     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, long p
//                              scr_save.cpp:397 (5)
//         004a7c99     MOV        EAX,0x1
//                              scr_save.cpp:402 (13)
//         004a7c9e     POP        EDI
//         004a7c9f     POP        ESI
//         004a7ca0     POP        EBP
//         004a7ca1     POP        EBX
//         004a7ca2     ADD        ESP,0x334
//         004a7ca8     RET        0x10
//                               LAB_004a7cab                                                 XREF[1]:     004a7c6f(j)
//                              scr_save.cpp:323 (5)
//         004a7cab     CMP        EAX,0x1
//         004a7cae     JNZ        LAB_004a7cea
//                              scr_save.cpp:324 (20)
//         004a7cb0     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a7cb6     PUSH       ESI
//         004a7cb7     CALL       TRIBE_Game::save_scenario                        int save_scenario(TRIBE_Game * this, char * p
//         004a7cbc     TEST       EAX,EAX
//         004a7cbe     JNZ        LAB_004a8027
//                              scr_save.cpp:325 (20)
//         004a7cc4     PUSH       0x64
//         004a7cc6     PUSH       0x1c2
//         004a7ccb     PUSH       EAX
//                              language.dll match for 0x963: "The scenario could not be save
//         004a7ccc     PUSH       0x963
//         004a7cd1     MOV        this,EBP
//         004a7cd3     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, long p
//                              scr_save.cpp:397 (5)
//         004a7cd8     MOV        EAX,0x1
//                              scr_save.cpp:402 (13)
//         004a7cdd     POP        EDI
//         004a7cde     POP        ESI
//         004a7cdf     POP        EBP
//         004a7ce0     POP        EBX
//         004a7ce1     ADD        ESP,0x334
//         004a7ce7     RET        0x10
//                               LAB_004a7cea                                                 XREF[1]:     004a7cae(j)
//                              scr_save.cpp:327 (9)
//         004a7cea     CMP        EAX,0x2
//         004a7ced     JNZ        LAB_004a8027
//                              scr_save.cpp:328 (7)
//         004a7cf3     MOV        this,EBP
//         004a7cf5     CALL       TribeSaveGameScreen::save_for_scenario_editor    void save_for_scenario_editor(TribeSaveGameSc
//                              scr_save.cpp:397 (5)
//         004a7cfa     MOV        EAX,0x1
//                              scr_save.cpp:402 (13)
//         004a7cff     POP        EDI
//         004a7d00     POP        ESI
//         004a7d01     POP        EBP
//         004a7d02     POP        EBX
//         004a7d03     ADD        ESP,0x334
//         004a7d09     RET        0x10
//                               LAB_004a7d0c                                                 XREF[2]:     004a7c31(j), 004a7c61(j)
//                              scr_save.cpp:331 (21)
//         004a7d0c     PUSH       0x64
//         004a7d0e     PUSH       0x1c2
//         004a7d13     PUSH       0x0
//                              language.dll match for 0x24c8: "That file exists. Overwrite i
//         004a7d15     PUSH       0x24c8
//         004a7d1a     MOV        this,EBP
//         004a7d1c     CALL       TEasy_Panel::popupYesNoDialog                    void popupYesNoDialog(TEasy_Panel * this, lon
//                              scr_save.cpp:333 (5)
//         004a7d21     MOV        EAX,0x1
//                              scr_save.cpp:402 (13)
//         004a7d26     POP        EDI
//         004a7d27     POP        ESI
//         004a7d28     POP        EBP
//         004a7d29     POP        EBX
//         004a7d2a     ADD        ESP,0x334
//         004a7d30     RET        0x10
//                               LAB_004a7d33                                                 XREF[2]:     004a7ac3(j), 004a7acc(j)
//                              scr_save.cpp:336 (22)
//         004a7d33     CMP        EDI,dword ptr [EBP + 0x48c]
//         004a7d39     JNZ        LAB_004a7d40
//         004a7d3b     CMP        EBX,0x1
//         004a7d3e     JZ         LAB_004a7d49
//                               LAB_004a7d40                                                 XREF[1]:     004a7d39(j)
//         004a7d40     CMP        EDI,EAX
//         004a7d42     JNZ        LAB_004a7db6
//         004a7d44     CMP        EBX,0x1
//         004a7d47     JNZ        LAB_004a7db6
//                               LAB_004a7d49                                                 XREF[1]:     004a7d3e(j)
//                              scr_save.cpp:339 (32)
//         004a7d49     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a7d4f     CALL       RGE_Base_Game::singlePlayerGame                  int singlePlayerGame(RGE_Base_Game * this)
//         004a7d54     CMP        EAX,0x1
//         004a7d57     JNZ        LAB_004a7d72
//         004a7d59     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a7d5f     MOV        EAX,dword ptr [this->_padding_ + 0xa00]
//         004a7d65     TEST       EAX,EAX
//         004a7d67     JNZ        LAB_004a7d72
//                              scr_save.cpp:340 (9)
//         004a7d69     PUSH       0x0
//         004a7d6b     PUSH       0x0
//         004a7d6d     CALL       RGE_Base_Game::set_paused                        void set_paused(RGE_Base_Game * this, int par
//                               LAB_004a7d72                                                 XREF[2]:     004a7d57(j), 004a7d67(j)
//                              scr_save.cpp:342 (6)
//         004a7d72     MOV        EAX,dword ptr [EBP + 0x69c]
//                              scr_save.cpp:343 (12)
//         004a7d78     PUSH       0x0
//         004a7d7a     CMP        EAX,0x2
//         004a7d7d     JNZ        LAB_004a7d86
//         004a7d7f     PUSH       s_Scenario_Editor_Screen                         = "Scenario Editor Screen"
//                              scr_save.cpp:344 (2)
//         004a7d84     JMP        LAB_004a7d8b
//                               LAB_004a7d86                                                 XREF[1]:     004a7d7d(j)
//                              scr_save.cpp:345 (15)
//         004a7d86     PUSH       s_Game_Screen                                    = "Game Screen"
//                               LAB_004a7d8b                                                 XREF[1]:     004a7d84(j)
//         004a7d8b     MOV        this,panel_system
//         004a7d90     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
//                              scr_save.cpp:346 (15)
//         004a7d95     PUSH       s_Save_Game_Screen                               = "Save Game Screen"
//         004a7d9a     MOV        this,panel_system
//         004a7d9f     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char *
//                              scr_save.cpp:347 (5)
//         004a7da4     MOV        EAX,0x1
//                              scr_save.cpp:402 (13)
//         004a7da9     POP        EDI
//         004a7daa     POP        ESI
//         004a7dab     POP        EBP
//         004a7dac     POP        EBX
//         004a7dad     ADD        ESP,0x334
//         004a7db3     RET        0x10
//                               LAB_004a7db6                                                 XREF[2]:     004a7d42(j), 004a7d47(j)
//                              scr_save.cpp:350 (68)
//         004a7db6     MOV        this,EDI
//         004a7db8     CALL       TPanel::panelName                                char * panelName(TPanel * this)
//         004a7dbd     TEST       EAX,EAX
//         004a7dbf     JZ         LAB_004a7e29
//         004a7dc1     MOV        this,EDI
//         004a7dc3     MOV        ESI,s_OKDialog                                   = 4Fh
//         004a7dc8     CALL       TPanel::panelName                                char * panelName(TPanel * this)
//                               LAB_004a7dcd                                                 XREF[1]:     004a7deb(j)
//         004a7dcd     MOV        DL,byte ptr [EAX]
//         004a7dcf     MOV        this,DL
//         004a7dd1     CMP        DL,byte ptr [ESI]=>s_OKDialog                    = 4Fh
//                                                                                  = 44h
//         004a7dd3     JNZ        LAB_004a7df1
//         004a7dd5     TEST       this,this
//         004a7dd7     JZ         LAB_004a7ded
//         004a7dd9     MOV        DL,byte ptr [EAX + 0x1]
//         004a7ddc     MOV        this,DL
//         004a7dde     CMP        DL,byte ptr [ESI + 0x1]=>DAT_00584eb5            = 4Bh
//                                                                                  = "ialog"
//         004a7de1     JNZ        LAB_004a7df1
//         004a7de3     ADD        EAX,0x2
//         004a7de6     ADD        ESI,0x2
//         004a7de9     TEST       this,this
//         004a7deb     JNZ        LAB_004a7dcd
//                               LAB_004a7ded                                                 XREF[1]:     004a7dd7(j)
//         004a7ded     XOR        EAX,EAX
//         004a7def     JMP        LAB_004a7df6
//                               LAB_004a7df1                                                 XREF[2]:     004a7dd3(j), 004a7de1(j)
//         004a7df1     SBB        EAX,EAX
//         004a7df3     SBB        EAX,-0x1
//                               LAB_004a7df6                                                 XREF[1]:     004a7def(j)
//         004a7df6     TEST       EAX,EAX
//         004a7df8     JNZ        LAB_004a7e29
//                              scr_save.cpp:351 (15)
//         004a7dfa     PUSH       s_OKDialog                                       = 4Fh
//         004a7dff     MOV        this,panel_system
//         004a7e04     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char *
//                              scr_save.cpp:352 (14)
//         004a7e09     MOV        EAX,dword ptr [EBP + 0x47c]
//         004a7e0f     MOV        this,EBP
//         004a7e11     PUSH       EAX
//         004a7e12     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
//                              scr_save.cpp:353 (5)
//         004a7e17     MOV        EAX,0x1
//                              scr_save.cpp:402 (13)
//         004a7e1c     POP        EDI
//         004a7e1d     POP        ESI
//         004a7e1e     POP        EBP
//         004a7e1f     POP        EBX
//         004a7e20     ADD        ESP,0x334
//         004a7e26     RET        0x10
//                               LAB_004a7e29                                                 XREF[2]:     004a7dbf(j), 004a7df8(j)
//                              scr_save.cpp:356 (76)
//         004a7e29     MOV        this,EDI
//         004a7e2b     CALL       TPanel::panelName                                char * panelName(TPanel * this)
//         004a7e30     TEST       EAX,EAX
//         004a7e32     JZ         LAB_004a8039
//         004a7e38     MOV        this,EDI
//         004a7e3a     MOV        ESI,s_YesNoDialog                                = 59h
//         004a7e3f     CALL       TPanel::panelName                                char * panelName(TPanel * this)
//                               LAB_004a7e44                                                 XREF[1]:     004a7e62(j)
//         004a7e44     MOV        DL,byte ptr [EAX]
//         004a7e46     MOV        this,DL
//         004a7e48     CMP        DL,byte ptr [ESI]=>s_YesNoDialog                 = 59h
//                                                                                  = 73h
//         004a7e4a     JNZ        LAB_004a7e68
//         004a7e4c     TEST       this,this
//         004a7e4e     JZ         LAB_004a7e64
//         004a7e50     MOV        DL,byte ptr [EAX + 0x1]
//         004a7e53     MOV        this,DL
//         004a7e55     CMP        DL,byte ptr [ESI + 0x1]=>DAT_00584ec1            = 65h
//                                                                                  = "NoDialog"
//         004a7e58     JNZ        LAB_004a7e68
//         004a7e5a     ADD        EAX,0x2
//         004a7e5d     ADD        ESI,0x2
//         004a7e60     TEST       this,this
//         004a7e62     JNZ        LAB_004a7e44
//                               LAB_004a7e64                                                 XREF[1]:     004a7e4e(j)
//         004a7e64     XOR        EAX,EAX
//         004a7e66     JMP        LAB_004a7e6d
//                               LAB_004a7e68                                                 XREF[2]:     004a7e4a(j), 004a7e58(j)
//         004a7e68     SBB        EAX,EAX
//         004a7e6a     SBB        EAX,-0x1
//                               LAB_004a7e6d                                                 XREF[1]:     004a7e66(j)
//         004a7e6d     TEST       EAX,EAX
//         004a7e6f     JNZ        LAB_004a8039
//                              scr_save.cpp:357 (2)
//         004a7e75     TEST       EBX,EBX
//                              scr_save.cpp:358 (21)
//         004a7e77     PUSH       s_YesNoDialog                                    = 59h
//         004a7e7c     MOV        this,panel_system
//         004a7e81     JNZ        LAB_004a8014
//         004a7e87     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char *
//                              scr_save.cpp:359 (14)
//         004a7e8c     MOV        EAX,dword ptr [EBP + 0x69c]
//         004a7e92     TEST       EAX,EAX
//         004a7e94     JNZ        LAB_004a7f20
//                              scr_save.cpp:363 (23)
//         004a7e9a     MOV        this,dword ptr [EBP + 0x47c]
//         004a7ea0     LEA        ESI,[EBP + 0x598]
//         004a7ea6     PUSH       0x104
//         004a7eab     PUSH       ESI
//         004a7eac     CALL       TEditPanel::get_trimmed_str                      char * get_trimmed_str(TEditPanel * this, cha
//                              scr_save.cpp:364 (34)
//         004a7eb1     MOV        EAX,[rge_base_game]                              = 00000000
//         004a7eb6     PUSH       ESI
//         004a7eb7     LEA        EDX=>tempFileName[4],[ESP + 0x18]
//         004a7ebb     MOV        this,dword ptr [EAX + 0xc]
//         004a7ebe     ADD        this,0xb12
//         004a7ec4     PUSH       this
//         004a7ec5     PUSH       s_%s%s.gam                                       = "%s%s.gam"
//         004a7eca     PUSH       EDX
//         004a7ecb     CALL       sprintf                                          undefined sprintf()
//         004a7ed0     ADD        ESP,0x10
//                              scr_save.cpp:365 (13)
//         004a7ed3     LEA        EAX=>tempFileName[4],[ESP + 0x14]
//         004a7ed7     PUSH       EAX
//         004a7ed8     CALL       __unlink                                         undefined __unlink()
//         004a7edd     ADD        ESP,0x4
//                              scr_save.cpp:367 (26)
//         004a7ee0     LEA        this,[EBP + 0x494]
//         004a7ee6     PUSH       this
//         004a7ee7     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a7eed     CALL       TRIBE_Game::save_game                            int save_game(TRIBE_Game * this, char * param
//         004a7ef2     TEST       EAX,EAX
//         004a7ef4     JNZ        LAB_004a8027
//                              scr_save.cpp:368 (20)
//         004a7efa     PUSH       0x64
//         004a7efc     PUSH       0x1c2
//         004a7f01     PUSH       EAX
//                              language.dll match for 0x962: "The game could not be saved. F
//         004a7f02     PUSH       0x962
//         004a7f07     MOV        this,EBP
//         004a7f09     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, long p
//                              scr_save.cpp:397 (5)
//         004a7f0e     MOV        EAX,0x1
//                              scr_save.cpp:402 (13)
//         004a7f13     POP        EDI
//         004a7f14     POP        ESI
//         004a7f15     POP        EBP
//         004a7f16     POP        EBX
//         004a7f17     ADD        ESP,0x334
//         004a7f1d     RET        0x10
//                               LAB_004a7f20                                                 XREF[1]:     004a7e94(j)
//                              scr_save.cpp:370 (9)
//         004a7f20     CMP        EAX,0x1
//         004a7f23     JNZ        LAB_004a7faf
//                              scr_save.cpp:374 (23)
//         004a7f29     MOV        this,dword ptr [EBP + 0x47c]
//         004a7f2f     LEA        ESI,[EBP + 0x598]
//         004a7f35     PUSH       0x104
//         004a7f3a     PUSH       ESI
//         004a7f3b     CALL       TEditPanel::get_trimmed_str                      char * get_trimmed_str(TEditPanel * this, cha
//                              scr_save.cpp:375 (34)
//         004a7f40     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
//         004a7f46     PUSH       ESI
//         004a7f47     LEA        this=>tempFileName[4],[ESP + 0x18]
//         004a7f4b     MOV        EAX,dword ptr [EDX + 0xc]
//         004a7f4e     ADD        EAX,0xc17
//         004a7f53     PUSH       EAX
//         004a7f54     PUSH       s_%s%s.scn                                       = "%s%s.scn"
//         004a7f59     PUSH       this
//         004a7f5a     CALL       sprintf                                          undefined sprintf()
//         004a7f5f     ADD        ESP,0x10
//                              scr_save.cpp:376 (10)
//         004a7f62     LEA        EDX=>tempFileName[4],[ESP + 0x14]
//         004a7f66     PUSH       EDX
//         004a7f67     CALL       __unlink                                         undefined __unlink()
//                              scr_save.cpp:378 (29)
//         004a7f6c     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a7f72     ADD        ESP,0x4
//         004a7f75     LEA        EAX,[EBP + 0x494]
//         004a7f7b     PUSH       EAX
//         004a7f7c     CALL       TRIBE_Game::save_scenario                        int save_scenario(TRIBE_Game * this, char * p
//         004a7f81     TEST       EAX,EAX
//         004a7f83     JNZ        LAB_004a8027
//                              scr_save.cpp:379 (20)
//         004a7f89     PUSH       0x64
//         004a7f8b     PUSH       0x1c2
//         004a7f90     PUSH       EAX
//                              language.dll match for 0x963: "The scenario could not be save
//         004a7f91     PUSH       0x963
//         004a7f96     MOV        this,EBP
//         004a7f98     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, long p
//                              scr_save.cpp:397 (5)
//         004a7f9d     MOV        EAX,0x1
//                              scr_save.cpp:402 (13)
//         004a7fa2     POP        EDI
//         004a7fa3     POP        ESI
//         004a7fa4     POP        EBP
//         004a7fa5     POP        EBX
//         004a7fa6     ADD        ESP,0x334
//         004a7fac     RET        0x10
//                               LAB_004a7faf                                                 XREF[1]:     004a7f23(j)
//                              scr_save.cpp:381 (5)
//         004a7faf     CMP        EAX,0x2
//         004a7fb2     JNZ        LAB_004a8027
//                              scr_save.cpp:386 (23)
//         004a7fb4     MOV        this,dword ptr [EBP + 0x47c]
//         004a7fba     LEA        ESI,[EBP + 0x598]
//         004a7fc0     PUSH       0x104
//         004a7fc5     PUSH       ESI
//         004a7fc6     CALL       TEditPanel::get_trimmed_str                      char * get_trimmed_str(TEditPanel * this, cha
//                              scr_save.cpp:387 (35)
//         004a7fcb     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a7fd1     PUSH       ESI
//         004a7fd2     LEA        EAX=>tempFileName[4],[ESP + 0x18]
//         004a7fd6     MOV        EDX,dword ptr [ECX + this->_padding_]
//         004a7fd9     ADD        EDX,0xc17
//         004a7fdf     PUSH       EDX
//         004a7fe0     PUSH       s_%s%s.scn                                       = "%s%s.scn"
//         004a7fe5     PUSH       EAX
//         004a7fe6     CALL       sprintf                                          undefined sprintf()
//         004a7feb     ADD        ESP,0x10
//                              scr_save.cpp:388 (13)
//         004a7fee     LEA        this=>tempFileName[4],[ESP + 0x14]
//         004a7ff2     PUSH       this
//         004a7ff3     CALL       __unlink                                         undefined __unlink()
//         004a7ff8     ADD        ESP,0x4
//                              scr_save.cpp:390 (7)
//         004a7ffb     MOV        this,EBP
//         004a7ffd     CALL       TribeSaveGameScreen::save_for_scenario_editor    void save_for_scenario_editor(TribeSaveGameSc
//                              scr_save.cpp:397 (5)
//         004a8002     MOV        EAX,0x1
//                              scr_save.cpp:402 (13)
//         004a8007     POP        EDI
//         004a8008     POP        ESI
//         004a8009     POP        EBP
//         004a800a     POP        EBX
//         004a800b     ADD        ESP,0x334
//         004a8011     RET        0x10
//                               LAB_004a8014                                                 XREF[1]:     004a7e81(j)
//                              scr_save.cpp:394 (5)
//         004a8014     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char *
//                              scr_save.cpp:395 (14)
//         004a8019     MOV        EDX,dword ptr [EBP + 0x47c]
//         004a801f     MOV        this,EBP
//         004a8021     PUSH       EDX
//         004a8022     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
//                               LAB_004a8027                                                 XREF[8]:     004a78d6(j), 004a79e3(j),
//                                                                                                         004a7c7f(j), 004a7cbe(j),
//                                                                                                         004a7ced(j), 004a7ef4(j),
//                                                                                                         004a7f83(j), 004a7fb2(j)
//                              scr_save.cpp:397 (5)
//         004a8027     MOV        EAX,0x1
//                              scr_save.cpp:402 (13)
//         004a802c     POP        EDI
//         004a802d     POP        ESI
//         004a802e     POP        EBP
//         004a802f     POP        EBX
//         004a8030     ADD        ESP,0x334
//         004a8036     RET        0x10
//                               LAB_004a8039                                                 XREF[3]:     004a786c(j), 004a7e32(j),
//                                                                                                         004a7e6f(j)
//                              scr_save.cpp:401 (25)
//         004a8039     MOV        EAX,dword ptr [ESP + param_4]
//         004a8040     MOV        this,dword ptr [ESP + param_3]
//         004a8047     PUSH       EAX
//         004a8048     PUSH       this
//         004a8049     PUSH       EBX
//         004a804a     PUSH       EDI
//         004a804b     MOV        this,EBP
//         004a804d     CALL       TEasy_Panel::action                              long action(TEasy_Panel * this, TPanel * para
//                              scr_save.cpp:402 (13)
//         004a8052     POP        EDI
//         004a8053     POP        ESI
//         004a8054     POP        EBP
//         004a8055     POP        EBX
//         004a8056     ADD        ESP,0x334
//         004a805c     RET        0x10
//         004a805f     ??         90h
    return 0;
}

void TribeSaveGameScreen::save_for_scenario_editor() {
    /* TODO: Stub */
//                              void __thiscall save_for_scenario_editor(TribeSaveGameScreen * this)
//              void              <VOID>         <RETURN>
//              TribeSaveGameS    ECX:4 (auto)   this
//                               ?save_for_scenario_editor@TribeSaveGameScreen@@IAEXXZ        XREF[2]:     action:004a7cf5(c),
//                               TribeSaveGameScreen::save_for_scenario_editor                             action:004a7ffd(c)
//                              scr_save.cpp:408 (26)
//         004a8060     PUSH       -0x1
//         004a8062     PUSH       FUN_0055f3fb
//         004a8067     MOV        EAX,FS:[0x0]
//         004a806d     PUSH       EAX
//         004a806e     MOV        dword ptr FS:[0x0],ESP
//         004a8075     PUSH       this
//         004a8076     PUSH       ESI
//         004a8077     PUSH       EDI
//         004a8078     MOV        EDI,this
//                              scr_save.cpp:410 (20)
//         004a807a     PUSH       -0x1
//         004a807c     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a8082     PUSH       0x0
//                              language.dll match for 0x450: "Saving scenario..."
//         004a8084     PUSH       0x450
//         004a8089     CALL       TRIBE_Game::show_status_message                  void show_status_message(TRIBE_Game * this, i
//                              scr_save.cpp:412 (26)
//         004a808e     MOV        EAX,[rge_base_game]                              = 00000000
//         004a8093     LEA        ESI,[EDI + 0x494]
//         004a8099     PUSH       ESI
//         004a809a     MOV        this,dword ptr [EAX + 0x3f4]
//         004a80a0     MOV        this,dword ptr [ECX + this->_padding_]
//         004a80a3     CALL       RGE_Scenario::Set_scenario_name                  void Set_scenario_name(RGE_Scenario * this, c
//                              scr_save.cpp:413 (25)
//         004a80a8     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
//         004a80ae     PUSH       ESI
//         004a80af     MOV        this,dword ptr [EDX + 0x3f4]
//         004a80b5     MOV        EAX,dword ptr [this->_padding_]
//         004a80b7     CALL       dword ptr [EAX + 0xe4]
//         004a80bd     TEST       AL,AL
//         004a80bf     JNZ        LAB_004a80e7
//                              scr_save.cpp:415 (21)
//         004a80c1     PUSH       0x64
//         004a80c3     PUSH       offset DAT_fffffff8
//         004a80c8     PUSH       0x0=>DAT_fffffff4
//                              language.dll match for 0x963: "The scenario could not be save
//         004a80ca     PUSH       offset DAT_fffffff0
//         004a80cf     MOV        this,EDI
//         004a80d1     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, long p
//                              scr_save.cpp:445 (17)
//         004a80d6     MOV        this,dword ptr [ESP + 0xc]
//         004a80da     MOV        dword ptr FS:[0x0],this
//         004a80e1     POP        EDI
//         004a80e2     POP        ESI
//         004a80e3     ADD        ESP,0x10
//         004a80e6     RET
//                               LAB_004a80e7                                                 XREF[1]:     004a80bf(j)
//                              scr_save.cpp:419 (15)
//         004a80e7     PUSH       s_Scenario_Editor_Screen                         = "Scenario Editor Screen"
//         004a80ec     MOV        this,panel_system
//         004a80f1     CALL       TPanelSystem::panel                              TPanel * panel(TPanelSystem * this, char * pa
//                              scr_save.cpp:420 (4)
//         004a80f6     TEST       EAX,EAX
//         004a80f8     JZ         LAB_004a8101
//                              scr_save.cpp:421 (7)
//         004a80fa     MOV        byte ptr [EAX + 0x4c0],0x0
//                               LAB_004a8101                                                 XREF[1]:     004a80f8(j)
//                              scr_save.cpp:423 (11)
//         004a8101     MOV        EDI,dword ptr [EDI + 0x6a0]
//         004a8107     CMP        EDI,0x1
//         004a810a     JNZ        LAB_004a8148
//                              scr_save.cpp:425 (15)
//         004a810c     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a8112     CALL       TRIBE_Game::start_menu                           int start_menu(TRIBE_Game * this)
//         004a8117     TEST       EAX,EAX
//         004a8119     JNZ        LAB_004a8137
//                              scr_save.cpp:427 (11)
//         004a811b     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a8121     CALL       RGE_Base_Game::close                             void close(RGE_Base_Game * this)
//                              scr_save.cpp:445 (17)
//         004a8126     MOV        this,dword ptr [ESP + 0xc]
//         004a812a     MOV        dword ptr FS:[0x0],this
//         004a8131     POP        EDI
//         004a8132     POP        ESI
//         004a8133     ADD        ESP,0x10
//         004a8136     RET
//                               LAB_004a8137                                                 XREF[1]:     004a8119(j)
//                              scr_save.cpp:431 (15)
//         004a8137     PUSH       s_Scenario_Editor_Screen                         = "Scenario Editor Screen"
//         004a813c     MOV        this,panel_system
//         004a8141     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char *
//                              scr_save.cpp:433 (7)
//         004a8146     JMP        LAB_004a81a7
//                               LAB_004a8148                                                 XREF[1]:     004a810a(j)
//         004a8148     CMP        EDI,0x2
//         004a814b     JNZ        LAB_004a8182
//                              scr_save.cpp:435 (36)
//         004a814d     PUSH       0x490
//         004a8152     CALL       operator_new                                     void * operator_new(uint param_1)
//         004a8157     ADD        ESP,0x4
//         004a815a     MOV        dword ptr [ESP + 0x8],EAX
//         004a815e     TEST       EAX,EAX
//         004a8160     MOV        dword ptr [ESP + 0x14],0x0
//         004a8168     JZ         LAB_004a8171
//         004a816a     MOV        this,EAX
//         004a816c     CALL       TRIBE_Screen_Sed_Open::TRIBE_Screen_Sed_Open     undefined TRIBE_Screen_Sed_Open(TRIBE_Screen_
//                               LAB_004a8171                                                 XREF[1]:     004a8168(j)
//                              scr_save.cpp:436 (15)
//         004a8171     PUSH       0x0
//         004a8173     MOV        dword ptr [ESP + 0x18],0xffffffff
//         004a817b     PUSH       s_Scenario_Editor_Open                           = "Scenario Editor Open"
//                              scr_save.cpp:438 (5)
//         004a8180     JMP        LAB_004a819d
//                               LAB_004a8182                                                 XREF[1]:     004a814b(j)
//         004a8182     CMP        EDI,0x3
//                              scr_save.cpp:439 (17)
//         004a8185     PUSH       0x0
//         004a8187     JNZ        LAB_004a8198
//         004a8189     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a818f     PUSH       0x0=>DAT_fffffff8
//         004a8191     CALL       TRIBE_Game::start_scenario_editor                int start_scenario_editor(TRIBE_Game * this,
//                              scr_save.cpp:440 (2)
//         004a8196     JMP        LAB_004a81a7
//                               LAB_004a8198                                                 XREF[1]:     004a8187(j)
//                              scr_save.cpp:441 (15)
//         004a8198     PUSH       s_Scenario_Editor_Screen                         = "Scenario Editor Screen"
//                               LAB_004a819d                                                 XREF[1]:     004a8180(j)
//         004a819d     MOV        this,panel_system
//         004a81a2     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
//                               LAB_004a81a7                                                 XREF[2]:     004a8146(j), 004a8196(j)
//                              scr_save.cpp:443 (15)
//         004a81a7     PUSH       s_Status_Screen                                  = "Status Screen"
//         004a81ac     MOV        this,panel_system
//         004a81b1     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char *
//                              scr_save.cpp:444 (15)
//         004a81b6     PUSH       s_Save_Game_Screen                               = "Save Game Screen"
//         004a81bb     MOV        this,panel_system
//         004a81c0     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char *
//                              scr_save.cpp:445 (17)
//         004a81c5     MOV        this,dword ptr [ESP + 0xc]
//         004a81c9     POP        EDI
//         004a81ca     MOV        dword ptr FS:[0x0],this
//         004a81d1     POP        ESI
//         004a81d2     ADD        ESP,0x10
//         004a81d5     RET
//         004a81d6     ??         90h
//         004a81d7     NOP
//         004a81d8     NOP
//         004a81d9     NOP
//         004a81da     NOP
//         004a81db     NOP
//         004a81dc     NOP
//         004a81dd     NOP
//         004a81de     NOP
//         004a81df     NOP
    return;
}

