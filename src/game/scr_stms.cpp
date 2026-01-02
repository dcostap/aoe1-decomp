#include "../common.h"
#include "scr_stms.h"

TRIBE_Screen_Status_Message::TRIBE_Screen_Status_Message(char* param_1, char* param_2, char* param_3, long param_4) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Screen_Status_Message(TRIBE_Screen_Status
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Screen_S    ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     004b734b(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     004b74b6(R)
//              char *            Stack[0xc]:4   param_3                   XREF[1]:     004b7381(R)
//              long              Stack[0x10]:4  param_4                   XREF[1]:     004b7388(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004b7369(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004b74e3(R)
//              char[260]         Stack[-0x114   info_file                 XREF[1,6]:   004b7359(W), 004b73bf(*), 004b73e4(W), 004b73f9(*),
//                                                                                     004b7411(R), 004b7426(*), 004b7485(*)
//                               ??0TRIBE_Screen_Status_Message@@QAE@PADJ0J@Z                 XREF[1]:     setup:00521b8e(c)
//                               TRIBE_Screen_Status_Message::TRIBE_Screen_Status_Message
//                              scr_stms.cpp:88 (52)
//         004b7330     PUSH       -0x1
//         004b7332     PUSH       FUN_0055f79b
//         004b7337     MOV        EAX,FS:[0x0]
//         004b733d     PUSH       EAX
//         004b733e     MOV        dword ptr FS:[0x0],ESP
//         004b7345     SUB        ESP,0x108
//         004b734b     MOV        EAX,dword ptr [ESP + param_1]
//         004b7352     PUSH       EBX
//         004b7353     PUSH       EBP
//         004b7354     PUSH       ESI
//         004b7355     PUSH       EDI
//         004b7356     MOV        EBX,this
//         004b7358     PUSH       EAX
//         004b7359     MOV        dword ptr [ESP + info_file[0]],EBX
//         004b735d     CALL       TScreenPanel::TScreenPanel                       undefined TScreenPanel(TScreenPanel * this, c
//         004b7362     XOR        ESI,ESI
//                              scr_stms.cpp:93 (29)
//         004b7364     MOV        this,panel_system
//         004b7369     MOV        dword ptr [ESP + local_4],ESI
//         004b7370     MOV        dword ptr [EBX],TRIBE_Screen_Status_Message::`   = 004b7310
//         004b7376     MOV        dword ptr [EBX + 0x478],ESI
//         004b737c     CALL       TPanelSystem::currentPanel                       TPanel * currentPanel(TPanelSystem * this)
//                              scr_stms.cpp:98 (25)
//         004b7381     MOV        EDI,dword ptr [ESP + param_3]
//         004b7388     MOV        EDX,dword ptr [ESP + param_4]
//         004b738f     CMP        EDI,ESI
//         004b7391     MOV        EBP,EAX
//         004b7393     JNZ        LAB_004b73ee
//         004b7395     CMP        EDX,-0x1
//         004b7398     JNZ        LAB_004b73ee
//                              scr_stms.cpp:103 (23)
//         004b739a     CMP        EBP,ESI
//         004b739c     JZ         LAB_004b73e4
//         004b739e     PUSH       s_Achievements_Screen                            = "Achievements Screen"
//         004b73a3     MOV        this,panel_system
//         004b73a8     CALL       TPanelSystem::panel                              TPanel * panel(TPanelSystem * this, char * pa
//         004b73ad     CMP        EBP,EAX
//         004b73af     JZ         LAB_004b73e4
//                              scr_stms.cpp:105 (42)
//         004b73b1     MOV        this,EBP
//         004b73b3     CALL       TEasy_Panel::get_info_file                       char * get_info_file(TEasy_Panel * this)
//         004b73b8     MOV        EDI,EAX
//         004b73ba     OR         this,0xffffffff
//         004b73bd     XOR        EAX,EAX
//         004b73bf     LEA        EDX=>info_file[4],[ESP + 0x14]
//         004b73c3     SCASB.RE   ES:EDI
//         004b73c5     NOT        this
//         004b73c7     SUB        EDI,this
//         004b73c9     MOV        EAX,this
//         004b73cb     MOV        ESI,EDI
//         004b73cd     MOV        EDI,EDX
//         004b73cf     SHR        this,0x2
//         004b73d2     MOVSD.REP  ES:EDI,ESI
//         004b73d4     MOV        this,EAX
//         004b73d6     AND        this,0x3
//         004b73d9     MOVSB.REP  ES:EDI,ESI
//                              scr_stms.cpp:106 (7)
//         004b73db     MOV        this,EBP
//         004b73dd     CALL       TEasy_Panel::get_info_id                         long get_info_id(TEasy_Panel * this)
//                              scr_stms.cpp:108 (2)
//         004b73e2     JMP        LAB_004b7411
//                               LAB_004b73e4                                                 XREF[2]:     004b739c(j), 004b73af(j)
//                              scr_stms.cpp:110 (5)
//         004b73e4     MOV        byte ptr [ESP + info_file[4]],0x0
//                              scr_stms.cpp:111 (5)
//         004b73e9     OR         EAX,0xffffffff
//         004b73ec     JMP        LAB_004b7411
//                               LAB_004b73ee                                                 XREF[2]:     004b7393(j), 004b7398(j)
//                              scr_stms.cpp:100 (28)
//         004b73ee     OR         this,0xffffffff
//         004b73f1     XOR        EAX,EAX
//         004b73f3     SCASB.RE   ES:EDI
//         004b73f5     NOT        this
//         004b73f7     SUB        EDI,this
//         004b73f9     LEA        EBP=>info_file[4],[ESP + 0x14]
//         004b73fd     MOV        EAX,this
//         004b73ff     MOV        ESI,EDI
//         004b7401     MOV        EDI,EBP
//         004b7403     SHR        this,0x2
//         004b7406     MOVSD.REP  ES:EDI,ESI
//         004b7408     MOV        this,EAX
//                              scr_stms.cpp:101 (7)
//         004b740a     MOV        EAX,EDX
//         004b740c     AND        this,0x3
//         004b740f     MOVSB.REP  ES:EDI,ESI
//                               LAB_004b7411                                                 XREF[2]:     004b73e2(j), 004b73ec(j)
//                              scr_stms.cpp:114 (8)
//         004b7411     MOV        this,byte ptr [ESP + info_file[4]]
//         004b7415     TEST       this,this
//         004b7417     JNZ        LAB_004b747c
//                              scr_stms.cpp:116 (13)
//         004b7419     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004b741f     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
//         004b7424     TEST       EAX,EAX
//                              scr_stms.cpp:118 (35)
//         004b7426     LEA        EDX=>info_file[4],[ESP + 0x14]
//         004b742a     JZ         LAB_004b7455
//         004b742c     MOV        EDI,s_scr3                                       = 73h
//         004b7431     OR         this,0xffffffff
//         004b7434     XOR        EAX,EAX
//         004b7436     SCASB.RE   ES:EDI=>s_scr3                                   = 73h
//                                                                                  = 63h
//         004b7438     NOT        this
//         004b743a     SUB        EDI,this
//         004b743c     MOV        EAX,this
//         004b743e     MOV        ESI,EDI
//         004b7440     MOV        EDI,EDX
//         004b7442     SHR        this,0x2
//         004b7445     MOVSD.REP  ES:EDI,ESI
//         004b7447     MOV        this,EAX
//                              scr_stms.cpp:119 (10)
//         004b7449     MOV        EAX,0xc385
//         004b744e     AND        this,0x3
//         004b7451     MOVSB.REP  ES:EDI,ESI
//                              scr_stms.cpp:121 (2)
//         004b7453     JMP        LAB_004b747c
//                               LAB_004b7455                                                 XREF[1]:     004b742a(j)
//                              scr_stms.cpp:123 (29)
//         004b7455     MOV        EDI,s_scr2                                       = 73h
//         004b745a     OR         this,0xffffffff
//         004b745d     XOR        EAX,EAX
//         004b745f     SCASB.RE   ES:EDI=>s_scr2                                   = 73h
//                                                                                  = 63h
//         004b7461     NOT        this
//         004b7463     SUB        EDI,this
//         004b7465     MOV        EAX,this
//         004b7467     MOV        ESI,EDI
//         004b7469     MOV        EDI,EDX
//         004b746b     SHR        this,0x2
//         004b746e     MOVSD.REP  ES:EDI,ESI
//         004b7470     MOV        this,EAX
//                              scr_stms.cpp:124 (10)
//         004b7472     MOV        EAX,0xc384
//         004b7477     AND        this,0x3
//         004b747a     MOVSB.REP  ES:EDI,ESI
//                               LAB_004b747c                                                 XREF[2]:     004b7417(j), 004b7453(j)
//                              scr_stms.cpp:128 (29)
//         004b747c     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
//         004b7482     PUSH       0x0
//         004b7484     PUSH       EAX
//         004b7485     LEA        this=>info_file[4],[ESP + 0x1c]
//         004b7489     MOV        EAX,dword ptr [EDX + 0x4c]
//         004b748c     PUSH       this
//         004b748d     PUSH       EAX
//         004b748e     MOV        this,EBX
//         004b7490     CALL       TScreenPanel::setup                              long setup(TScreenPanel * this, TDrawArea * p
//         004b7495     TEST       EAX,EAX
//         004b7497     JNZ        LAB_004b74a5
//                              scr_stms.cpp:130 (10)
//         004b7499     MOV        dword ptr [EBX + 0xd8],0x1
//                              scr_stms.cpp:131 (2)
//         004b74a3     JMP        LAB_004b74e3
//                               LAB_004b74a5                                                 XREF[1]:     004b7497(j)
//                              scr_stms.cpp:134 (17)
//         004b74a5     PUSH       0x1e0
//         004b74aa     PUSH       0x280
//         004b74af     MOV        this,EBX
//         004b74b1     CALL       TEasy_Panel::set_ideal_size                      void set_ideal_size(TEasy_Panel * this, long
//                              scr_stms.cpp:137 (45)
//         004b74b6     MOV        this,dword ptr [ESP + param_2]
//         004b74bd     PUSH       0x1
//         004b74bf     PUSH       0x1
//         004b74c1     PUSH       0x1
//         004b74c3     PUSH       0x4
//         004b74c5     PUSH       0x190
//         004b74ca     PUSH       0x230
//         004b74cf     PUSH       0x28
//         004b74d1     PUSH       0x28
//         004b74d3     LEA        EAX,[EBX + 0x478]
//         004b74d9     PUSH       this
//         004b74da     PUSH       EAX
//         004b74db     PUSH       EBX
//         004b74dc     MOV        this,EBX
//         004b74de     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel *
//                               LAB_004b74e3                                                 XREF[1]:     004b74a3(j)
//                              scr_stms.cpp:138 (29)
//         004b74e3     MOV        this,dword ptr [ESP + local_c]
//         004b74ea     POP        EDI
//         004b74eb     POP        ESI
//         004b74ec     MOV        EAX,EBX
//         004b74ee     POP        EBP
//         004b74ef     MOV        dword ptr FS:[0x0],this
//         004b74f6     POP        EBX
//         004b74f7     ADD        ESP,0x114
//         004b74fd     RET        0x10
}

TRIBE_Screen_Status_Message::TRIBE_Screen_Status_Message(char* param_1, long param_2, char* param_3, long param_4) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Screen_Status_Message(TRIBE_Screen_Status
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Screen_S    ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     004b734b(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     004b74b6(R)
//              char *            Stack[0xc]:4   param_3                   XREF[1]:     004b7381(R)
//              long              Stack[0x10]:4  param_4                   XREF[1]:     004b7388(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004b7369(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004b74e3(R)
//              char[260]         Stack[-0x114   info_file                 XREF[1,6]:   004b7359(W), 004b73bf(*), 004b73e4(W), 004b73f9(*),
//                                                                                     004b7411(R), 004b7426(*), 004b7485(*)
//                               ??0TRIBE_Screen_Status_Message@@QAE@PADJ0J@Z                 XREF[1]:     setup:00521b8e(c)
//                               TRIBE_Screen_Status_Message::TRIBE_Screen_Status_Message
//                              scr_stms.cpp:88 (52)
//         004b7330     PUSH       -0x1
//         004b7332     PUSH       FUN_0055f79b
//         004b7337     MOV        EAX,FS:[0x0]
//         004b733d     PUSH       EAX
//         004b733e     MOV        dword ptr FS:[0x0],ESP
//         004b7345     SUB        ESP,0x108
//         004b734b     MOV        EAX,dword ptr [ESP + param_1]
//         004b7352     PUSH       EBX
//         004b7353     PUSH       EBP
//         004b7354     PUSH       ESI
//         004b7355     PUSH       EDI
//         004b7356     MOV        EBX,this
//         004b7358     PUSH       EAX
//         004b7359     MOV        dword ptr [ESP + info_file[0]],EBX
//         004b735d     CALL       TScreenPanel::TScreenPanel                       undefined TScreenPanel(TScreenPanel * this, c
//         004b7362     XOR        ESI,ESI
//                              scr_stms.cpp:93 (29)
//         004b7364     MOV        this,panel_system
//         004b7369     MOV        dword ptr [ESP + local_4],ESI
//         004b7370     MOV        dword ptr [EBX],TRIBE_Screen_Status_Message::`   = 004b7310
//         004b7376     MOV        dword ptr [EBX + 0x478],ESI
//         004b737c     CALL       TPanelSystem::currentPanel                       TPanel * currentPanel(TPanelSystem * this)
//                              scr_stms.cpp:98 (25)
//         004b7381     MOV        EDI,dword ptr [ESP + param_3]
//         004b7388     MOV        EDX,dword ptr [ESP + param_4]
//         004b738f     CMP        EDI,ESI
//         004b7391     MOV        EBP,EAX
//         004b7393     JNZ        LAB_004b73ee
//         004b7395     CMP        EDX,-0x1
//         004b7398     JNZ        LAB_004b73ee
//                              scr_stms.cpp:103 (23)
//         004b739a     CMP        EBP,ESI
//         004b739c     JZ         LAB_004b73e4
//         004b739e     PUSH       s_Achievements_Screen                            = "Achievements Screen"
//         004b73a3     MOV        this,panel_system
//         004b73a8     CALL       TPanelSystem::panel                              TPanel * panel(TPanelSystem * this, char * pa
//         004b73ad     CMP        EBP,EAX
//         004b73af     JZ         LAB_004b73e4
//                              scr_stms.cpp:105 (42)
//         004b73b1     MOV        this,EBP
//         004b73b3     CALL       TEasy_Panel::get_info_file                       char * get_info_file(TEasy_Panel * this)
//         004b73b8     MOV        EDI,EAX
//         004b73ba     OR         this,0xffffffff
//         004b73bd     XOR        EAX,EAX
//         004b73bf     LEA        EDX=>info_file[4],[ESP + 0x14]
//         004b73c3     SCASB.RE   ES:EDI
//         004b73c5     NOT        this
//         004b73c7     SUB        EDI,this
//         004b73c9     MOV        EAX,this
//         004b73cb     MOV        ESI,EDI
//         004b73cd     MOV        EDI,EDX
//         004b73cf     SHR        this,0x2
//         004b73d2     MOVSD.REP  ES:EDI,ESI
//         004b73d4     MOV        this,EAX
//         004b73d6     AND        this,0x3
//         004b73d9     MOVSB.REP  ES:EDI,ESI
//                              scr_stms.cpp:106 (7)
//         004b73db     MOV        this,EBP
//         004b73dd     CALL       TEasy_Panel::get_info_id                         long get_info_id(TEasy_Panel * this)
//                              scr_stms.cpp:108 (2)
//         004b73e2     JMP        LAB_004b7411
//                               LAB_004b73e4                                                 XREF[2]:     004b739c(j), 004b73af(j)
//                              scr_stms.cpp:110 (5)
//         004b73e4     MOV        byte ptr [ESP + info_file[4]],0x0
//                              scr_stms.cpp:111 (5)
//         004b73e9     OR         EAX,0xffffffff
//         004b73ec     JMP        LAB_004b7411
//                               LAB_004b73ee                                                 XREF[2]:     004b7393(j), 004b7398(j)
//                              scr_stms.cpp:100 (28)
//         004b73ee     OR         this,0xffffffff
//         004b73f1     XOR        EAX,EAX
//         004b73f3     SCASB.RE   ES:EDI
//         004b73f5     NOT        this
//         004b73f7     SUB        EDI,this
//         004b73f9     LEA        EBP=>info_file[4],[ESP + 0x14]
//         004b73fd     MOV        EAX,this
//         004b73ff     MOV        ESI,EDI
//         004b7401     MOV        EDI,EBP
//         004b7403     SHR        this,0x2
//         004b7406     MOVSD.REP  ES:EDI,ESI
//         004b7408     MOV        this,EAX
//                              scr_stms.cpp:101 (7)
//         004b740a     MOV        EAX,EDX
//         004b740c     AND        this,0x3
//         004b740f     MOVSB.REP  ES:EDI,ESI
//                               LAB_004b7411                                                 XREF[2]:     004b73e2(j), 004b73ec(j)
//                              scr_stms.cpp:114 (8)
//         004b7411     MOV        this,byte ptr [ESP + info_file[4]]
//         004b7415     TEST       this,this
//         004b7417     JNZ        LAB_004b747c
//                              scr_stms.cpp:116 (13)
//         004b7419     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004b741f     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
//         004b7424     TEST       EAX,EAX
//                              scr_stms.cpp:118 (35)
//         004b7426     LEA        EDX=>info_file[4],[ESP + 0x14]
//         004b742a     JZ         LAB_004b7455
//         004b742c     MOV        EDI,s_scr3                                       = 73h
//         004b7431     OR         this,0xffffffff
//         004b7434     XOR        EAX,EAX
//         004b7436     SCASB.RE   ES:EDI=>s_scr3                                   = 73h
//                                                                                  = 63h
//         004b7438     NOT        this
//         004b743a     SUB        EDI,this
//         004b743c     MOV        EAX,this
//         004b743e     MOV        ESI,EDI
//         004b7440     MOV        EDI,EDX
//         004b7442     SHR        this,0x2
//         004b7445     MOVSD.REP  ES:EDI,ESI
//         004b7447     MOV        this,EAX
//                              scr_stms.cpp:119 (10)
//         004b7449     MOV        EAX,0xc385
//         004b744e     AND        this,0x3
//         004b7451     MOVSB.REP  ES:EDI,ESI
//                              scr_stms.cpp:121 (2)
//         004b7453     JMP        LAB_004b747c
//                               LAB_004b7455                                                 XREF[1]:     004b742a(j)
//                              scr_stms.cpp:123 (29)
//         004b7455     MOV        EDI,s_scr2                                       = 73h
//         004b745a     OR         this,0xffffffff
//         004b745d     XOR        EAX,EAX
//         004b745f     SCASB.RE   ES:EDI=>s_scr2                                   = 73h
//                                                                                  = 63h
//         004b7461     NOT        this
//         004b7463     SUB        EDI,this
//         004b7465     MOV        EAX,this
//         004b7467     MOV        ESI,EDI
//         004b7469     MOV        EDI,EDX
//         004b746b     SHR        this,0x2
//         004b746e     MOVSD.REP  ES:EDI,ESI
//         004b7470     MOV        this,EAX
//                              scr_stms.cpp:124 (10)
//         004b7472     MOV        EAX,0xc384
//         004b7477     AND        this,0x3
//         004b747a     MOVSB.REP  ES:EDI,ESI
//                               LAB_004b747c                                                 XREF[2]:     004b7417(j), 004b7453(j)
//                              scr_stms.cpp:128 (29)
//         004b747c     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
//         004b7482     PUSH       0x0
//         004b7484     PUSH       EAX
//         004b7485     LEA        this=>info_file[4],[ESP + 0x1c]
//         004b7489     MOV        EAX,dword ptr [EDX + 0x4c]
//         004b748c     PUSH       this
//         004b748d     PUSH       EAX
//         004b748e     MOV        this,EBX
//         004b7490     CALL       TScreenPanel::setup                              long setup(TScreenPanel * this, TDrawArea * p
//         004b7495     TEST       EAX,EAX
//         004b7497     JNZ        LAB_004b74a5
//                              scr_stms.cpp:130 (10)
//         004b7499     MOV        dword ptr [EBX + 0xd8],0x1
//                              scr_stms.cpp:131 (2)
//         004b74a3     JMP        LAB_004b74e3
//                               LAB_004b74a5                                                 XREF[1]:     004b7497(j)
//                              scr_stms.cpp:134 (17)
//         004b74a5     PUSH       0x1e0
//         004b74aa     PUSH       0x280
//         004b74af     MOV        this,EBX
//         004b74b1     CALL       TEasy_Panel::set_ideal_size                      void set_ideal_size(TEasy_Panel * this, long
//                              scr_stms.cpp:137 (45)
//         004b74b6     MOV        this,dword ptr [ESP + param_2]
//         004b74bd     PUSH       0x1
//         004b74bf     PUSH       0x1
//         004b74c1     PUSH       0x1
//         004b74c3     PUSH       0x4
//         004b74c5     PUSH       0x190
//         004b74ca     PUSH       0x230
//         004b74cf     PUSH       0x28
//         004b74d1     PUSH       0x28
//         004b74d3     LEA        EAX,[EBX + 0x478]
//         004b74d9     PUSH       this
//         004b74da     PUSH       EAX
//         004b74db     PUSH       EBX
//         004b74dc     MOV        this,EBX
//         004b74de     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel *
//                               LAB_004b74e3                                                 XREF[1]:     004b74a3(j)
//                              scr_stms.cpp:138 (29)
//         004b74e3     MOV        this,dword ptr [ESP + local_c]
//         004b74ea     POP        EDI
//         004b74eb     POP        ESI
//         004b74ec     MOV        EAX,EBX
//         004b74ee     POP        EBP
//         004b74ef     MOV        dword ptr FS:[0x0],this
//         004b74f6     POP        EBX
//         004b74f7     ADD        ESP,0x114
//         004b74fd     RET        0x10
}

TRIBE_Screen_Status_Message::~TRIBE_Screen_Status_Message() {
    /* TODO: Stub */
//                              void __thiscall ~TRIBE_Screen_Status_Message(TRIBE_Screen_Status_Mes
//              void              <VOID>         <RETURN>
//              TRIBE_Screen_S    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004b7529(W), 004b7539(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004b7546(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004b7519(W)
//                               ??1TRIBE_Screen_Status_Message@@UAE@XZ                       XREF[1]:     `vector_deleting_destructor':004b7
//                               TRIBE_Screen_Status_Message::~TRIBE_Screen_Status_Message
//                              scr_stms.cpp:142 (35)
//         004b7500     PUSH       -0x1
//         004b7502     PUSH       FUN_0055f7b8
//         004b7507     MOV        EAX,FS:[0x0]
//         004b750d     PUSH       EAX
//         004b750e     MOV        dword ptr FS:[0x0],ESP
//         004b7515     PUSH       this
//         004b7516     PUSH       ESI
//         004b7517     MOV        ESI,this
//         004b7519     MOV        dword ptr [ESP + local_10],ESI
//         004b751d     MOV        dword ptr [ESI],TRIBE_Screen_Status_Message::`   = 004b7310
//                              scr_stms.cpp:143 (22)
//         004b7523     LEA        EAX,[ESI + 0x478]
//         004b7529     MOV        dword ptr [ESP + local_4],0x0
//         004b7531     PUSH       EAX
//         004b7532     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//         004b7537     MOV        this,ESI
//                              scr_stms.cpp:144 (29)
//         004b7539     MOV        dword ptr [ESP + local_4],0xffffffff
//         004b7541     CALL       TScreenPanel::~TScreenPanel                      void ~TScreenPanel(TScreenPanel * this)
//         004b7546     MOV        this,dword ptr [ESP + local_c]
//         004b754a     POP        ESI
//         004b754b     MOV        dword ptr FS:[0x0],this
//         004b7552     ADD        ESP,0x10
//         004b7555     RET
//         004b7556     ??         90h
//         004b7557     NOP
//         004b7558     NOP
//         004b7559     NOP
//         004b755a     NOP
//         004b755b     NOP
//         004b755c     NOP
//         004b755d     NOP
//         004b755e     NOP
//         004b755f     NOP
}

void TRIBE_Screen_Status_Message::set_text(char* param_1) {
    /* TODO: Stub */
//                              void __thiscall set_text(TRIBE_Screen_Status_Message * this, long pa
//              void              <VOID>         <RETURN>
//              TRIBE_Screen_S    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     004b7586(R)
//                               ?set_text@TRIBE_Screen_Status_Message@@QAEXJ@Z
//                               TRIBE_Screen_Status_Message::set_text
//                              scr_stms.cpp:158 (19)
//         004b7580     MOV        this,dword ptr [ECX + this->message]
//         004b7586     MOV        EDX,dword ptr [ESP + param_1]
//         004b758a     PUSH       EDX
//         004b758b     MOV        EAX,dword ptr [this->_padding_]
//         004b758d     CALL       dword ptr [EAX + 0xe4]
//                              scr_stms.cpp:160 (3)
//         004b7593     RET        0x4
//         004b7596     ??         90h
//         004b7597     NOP
//         004b7598     NOP
//         004b7599     NOP
//         004b759a     NOP
//         004b759b     NOP
//         004b759c     NOP
//         004b759d     NOP
//         004b759e     NOP
//         004b759f     NOP
    return;
}

void TRIBE_Screen_Status_Message::set_text(long param_1) {
    /* TODO: Stub */
//                              void __thiscall set_text(TRIBE_Screen_Status_Message * this, long pa
//              void              <VOID>         <RETURN>
//              TRIBE_Screen_S    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     004b7586(R)
//                               ?set_text@TRIBE_Screen_Status_Message@@QAEXJ@Z
//                               TRIBE_Screen_Status_Message::set_text
//                              scr_stms.cpp:158 (19)
//         004b7580     MOV        this,dword ptr [ECX + this->message]
//         004b7586     MOV        EDX,dword ptr [ESP + param_1]
//         004b758a     PUSH       EDX
//         004b758b     MOV        EAX,dword ptr [this->_padding_]
//         004b758d     CALL       dword ptr [EAX + 0xe4]
//                              scr_stms.cpp:160 (3)
//         004b7593     RET        0x4
//         004b7596     ??         90h
//         004b7597     NOP
//         004b7598     NOP
//         004b7599     NOP
//         004b759a     NOP
//         004b759b     NOP
//         004b759c     NOP
//         004b759d     NOP
//         004b759e     NOP
//         004b759f     NOP
    return;
}

