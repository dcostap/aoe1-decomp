// Auto-generated scaffold unit: scr_mp.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/scr_mp.cpp
#include "../include/common.h"

// Offset: 0x0049F370
undefined TribeMPStartupScreen(TribeMPStartupScreen* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TribeMPStartupScreen::TribeMPStartupScreen(void)                                   *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TribeMPStartupScreen(TribeMPStartupScreen * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TribeMPStartup    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0049f3c9(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0049f853(R)  
    //              char[256]         Stack[-0x110   str                       XREF[0,3]:   0049f4a5(*), 0049f4c6(W), 0049f4e1(*)  
    //              char[255]         Stack[-0x210   temp_str
    //              char[255]         Stack[-0x310   Data                      XREF[1]:     0049f396(W)  
    //              ulong             Stack[-0x318   gdwDisp
    //              TPanel *[5]       Stack[-0x32c   tabList
    //              ulong             Stack[-0x330   dwType
    //              ulong             Stack[-0x334   dwSize
    //              void *            Stack[-0x338   ghUserKey
    //                               ??0TribeMPStartupScreen@@QAE@XZ                              XREF[2]:     action:00491fde(c), 
    //                               TribeMPStartupScreen::TribeMPStartupScreen                                action:0049ef89(c)  
    //                              scr_mp.cpp:68 (47)
    //         0049f370     PUSH       -0x1
    //         0049f372     PUSH       FUN_0055f0fb
    //         0049f377     MOV        EAX,FS:[0x0]
    //         0049f37d     PUSH       EAX
    //         0049f37e     MOV        dword ptr FS:[0x0],ESP
    //         0049f385     SUB        ESP,0x328
    //         0049f38b     PUSH       EBX
    //         0049f38c     PUSH       EBP
    //         0049f38d     PUSH       ESI
    //         0049f38e     PUSH       EDI
    //         0049f38f     MOV        EBP,this
    //         0049f391     PUSH       s_MP_Startup_Screen                              = "MP Startup Screen"
    //         0049f396     MOV        dword ptr [ESP + Data[0]],EBP
    //         0049f39a     CALL       TScreenPanel::TScreenPanel                       undefined TScreenPanel(TScreenPanel * this, c
    //                              scr_mp.cpp:76 (29)
    //         0049f39f     LEA        EBX,[EBP + 0x48c]
    //         0049f3a5     XOR        ESI,ESI
    //         0049f3a7     MOV        dword ptr [EBP],TribeMPStartupScreen::`vftable'  = 0049f870
    //         0049f3ae     MOV        dword ptr [EBP + 0x490],ESI
    //         0049f3b4     MOV        dword ptr [EBP + 0x488],ESI
    //         0049f3ba     MOV        dword ptr [EBX],ESI
    //                              scr_mp.cpp:77 (6)
    //         0049f3bc     MOV        dword ptr [EBP + 0x494],ESI
    //                              scr_mp.cpp:84 (19)
    //         0049f3c2     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0049f3c8     PUSH       ESI
    //         0049f3c9     MOV        dword ptr [ESP + local_4],ESI
    //         0049f3d0     CALL       RGE_Base_Game::setMultiplayerGame                void setMultiplayerGame(RGE_Base_Game * this,
    //                              scr_mp.cpp:87 (32)
    //         0049f3d5     MOV        EAX,[rge_base_game]                              = 00000000
    //         0049f3da     PUSH       0x1
    //         0049f3dc     PUSH       0xc385
    //         0049f3e1     PUSH       s_scr3                                           = 73h
    //         0049f3e6     MOV        this,dword ptr [EAX + 0x4c]
    //         0049f3e9     PUSH       this
    //         0049f3ea     MOV        this,EBP
    //         0049f3ec     CALL       TScreenPanel::setup                              long setup(TScreenPanel * this, TDrawArea * p
    //         0049f3f1     TEST       EAX,EAX
    //         0049f3f3     JNZ        LAB_0049f404
    //                              scr_mp.cpp:88 (10)
    //         0049f3f5     MOV        dword ptr [EBP + 0xd8],0x1
    //                              scr_mp.cpp:89 (5)
    //         0049f3ff     JMP        LAB_0049f853
    //                               LAB_0049f404                                                 XREF[1]:     0049f3f3(j)  
    //                              scr_mp.cpp:92 (8)
    //         0049f404     PUSH       ESI
    //         0049f405     MOV        this,EBP
    //         0049f407     CALL       TEasy_Panel::setup_shadow_area                   void setup_shadow_area(TEasy_Panel * this, in
    //                              scr_mp.cpp:93 (17)
    //         0049f40c     PUSH       0x1e0
    //         0049f411     PUSH       0x280
    //         0049f416     MOV        this,EBP
    //         0049f418     CALL       TEasy_Panel::set_ideal_size                      void set_ideal_size(TEasy_Panel * this, long 
    //                              scr_mp.cpp:98 (45)
    //         0049f41d     PUSH       ESI
    //         0049f41e     PUSH       ESI
    //         0049f41f     PUSH       0x1
    //         0049f421     PUSH       0x1
    //         0049f423     PUSH       0x1e
    //         0049f425     PUSH       0x258
    //         0049f42a     PUSH       0x14
    //         0049f42c     PUSH       0x14
    //         0049f42e     LEA        EDX,[EBP + 0x478]
    //                              language.dll match for 0x258b: "Multiplayer Connection"
    //         0049f434     PUSH       0x258b
    //         0049f439     PUSH       EDX
    //         0049f43a     PUSH       EBP
    //         0049f43b     MOV        this,EBP
    //         0049f43d     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         0049f442     TEST       EAX,EAX
    //         0049f444     JZ         LAB_0049f853
    //                              scr_mp.cpp:101 (44)
    //         0049f44a     PUSH       ESI
    //         0049f44b     PUSH       ESI
    //         0049f44c     PUSH       ESI
    //         0049f44d     PUSH       0x4
    //         0049f44f     PUSH       0x14
    //         0049f451     PUSH       0x1f4
    //         0049f456     PUSH       0x4b
    //         0049f458     PUSH       0x14
    //         0049f45a     LEA        EAX,[EBP + 0x47c]
    //                              language.dll match for 0x258c: "Name"
    //         0049f460     PUSH       0x258c
    //         0049f465     PUSH       EAX
    //         0049f466     PUSH       EBP
    //         0049f467     MOV        this,EBP
    //         0049f469     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         0049f46e     TEST       EAX,EAX
    //         0049f470     JZ         LAB_0049f853
    //                              scr_mp.cpp:105 (22)
    //         0049f476     MOV        this,dword ptr [Regs]                            = 00000000
    //         0049f47c     PUSH       s_Default_Age_Of_Empires_Player_Na               = "Default Age Of Empires Player Name"
    //         0049f481     PUSH       0x1
    //         0049f483     CALL       TRegistry::RegGetAscii                           char * RegGetAscii(TRegistry * this, int para
    //         0049f488     TEST       EAX,EAX
    //         0049f48a     JZ         LAB_0049f4c6
    //                              scr_mp.cpp:106 (56)
    //         0049f48c     MOV        this,dword ptr [Regs]                            = 00000000
    //         0049f492     PUSH       s_Default_Age_Of_Empires_Player_Na               = "Default Age Of Empires Player Name"
    //         0049f497     PUSH       0x1
    //         0049f499     CALL       TRegistry::RegGetAscii                           char * RegGetAscii(TRegistry * this, int para
    //         0049f49e     MOV        EDI,EAX
    //         0049f4a0     OR         this,0xffffffff
    //         0049f4a3     XOR        EAX,EAX
    //         0049f4a5     LEA        EDX=>str[4],[ESP + 0x238]
    //         0049f4ac     SCASB.RE   ES:EDI
    //         0049f4ae     NOT        this
    //         0049f4b0     SUB        EDI,this
    //         0049f4b2     MOV        EAX,this
    //         0049f4b4     MOV        ESI,EDI
    //         0049f4b6     MOV        EDI,EDX
    //         0049f4b8     SHR        this,0x2
    //         0049f4bb     MOVSD.REP  ES:EDI,ESI
    //         0049f4bd     MOV        this,EAX
    //         0049f4bf     AND        this,0x3
    //         0049f4c2     MOVSB.REP  ES:EDI,ESI
    //                              scr_mp.cpp:107 (2)
    //         0049f4c4     JMP        LAB_0049f4ce
    //                               LAB_0049f4c6                                                 XREF[1]:     0049f48a(j)  
    //                              scr_mp.cpp:108 (8)
    //         0049f4c6     MOV        byte ptr [ESP + str[4]],0x0
    //                               LAB_0049f4ce                                                 XREF[1]:     0049f4c4(j)  
    //                              scr_mp.cpp:110 (52)
    //         0049f4ce     PUSH       0x0
    //         0049f4d0     PUSH       0x1
    //         0049f4d2     PUSH       0xb
    //         0049f4d4     PUSH       0x17
    //         0049f4d6     PUSH       0x258
    //         0049f4db     PUSH       0x64
    //         0049f4dd     PUSH       0x14
    //         0049f4df     PUSH       0x0
    //         0049f4e1     LEA        this=>str[4],[ESP + 0x258]
    //         0049f4e8     LEA        ESI,[EBP + 0x480]
    //         0049f4ee     PUSH       0xf
    //         0049f4f0     PUSH       this
    //         0049f4f1     PUSH       ESI
    //         0049f4f2     PUSH       EBP
    //         0049f4f3     MOV        this,EBP
    //         0049f4f5     CALL       TEasy_Panel::create_edit                         int create_edit(TEasy_Panel * this, TPanel * 
    //         0049f4fa     TEST       EAX,EAX
    //         0049f4fc     JZ         LAB_0049f853
    //                              scr_mp.cpp:111 (14)
    //         0049f502     MOV        this,dword ptr [ESI]
    //         0049f504     PUSH       -0x1
    //                              language.dll match for 0x7595: "Type your player name."
    //         0049f506     PUSH       0x7595
    //         0049f50b     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              scr_mp.cpp:114 (50)
    //         0049f510     PUSH       0x0
    //         0049f512     PUSH       0x0
    //         0049f514     PUSH       0x0
    //         0049f516     PUSH       0x4
    //         0049f518     PUSH       0x14
    //         0049f51a     PUSH       0x258
    //         0049f51f     PUSH       0xa5
    //         0049f524     PUSH       0x14
    //         0049f526     LEA        EDX,[EBP + 0x484]
    //                              language.dll match for 0x258d: "Connection Type"
    //         0049f52c     PUSH       0x258d
    //         0049f531     PUSH       EDX
    //         0049f532     PUSH       EBP
    //         0049f533     MOV        this,EBP
    //         0049f535     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         0049f53a     TEST       EAX,EAX
    //         0049f53c     JZ         LAB_0049f853
    //                              scr_mp.cpp:117 (42)
    //         0049f542     PUSH       0xb
    //         0049f544     PUSH       0xd2
    //         0049f549     PUSH       0x258
    //         0049f54e     LEA        ESI,[EBP + 0x498]
    //         0049f554     PUSH       0xbe
    //         0049f559     PUSH       0x14
    //         0049f55b     PUSH       ESI
    //         0049f55c     PUSH       EBP
    //         0049f55d     MOV        this,EBP
    //         0049f55f     CALL       TEasy_Panel::create_list                         int create_list(TEasy_Panel * this, TPanel * 
    //         0049f564     TEST       EAX,EAX
    //         0049f566     JZ         LAB_0049f853
    //                              scr_mp.cpp:118 (27)
    //         0049f56c     MOV        EAX,dword ptr [ESI]
    //         0049f56e     PUSH       0x14
    //         0049f570     LEA        this,[EBP + 0x49c]
    //         0049f576     PUSH       EAX
    //         0049f577     PUSH       this
    //         0049f578     MOV        this,EBP
    //         0049f57a     CALL       TEasy_Panel::create_auto_scrollbar               int create_auto_scrollbar(TEasy_Panel * this,
    //         0049f57f     TEST       EAX,EAX
    //         0049f581     JZ         LAB_0049f853
    //                              scr_mp.cpp:119 (17)
    //         0049f587     MOV        this,dword ptr [ESI]
    //         0049f589     PUSH       0x25f08
    //                              language.dll match for 0x7596: "Select the type of connection
    //         0049f58e     PUSH       0x7596
    //         0049f593     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              scr_mp.cpp:124 (50)
    //         0049f598     PUSH       0x0
    //         0049f59a     PUSH       0x0
    //         0049f59c     PUSH       0x0
    //         0049f59e     PUSH       0x1e
    //         0049f5a0     PUSH       0xf0
    //         0049f5a5     PUSH       0x1b8
    //         0049f5aa     PUSH       0x46
    //         0049f5ac     PUSH       0x0
    //         0049f5ae     LEA        ESI,[EBP + 0x488]
    //                              language.dll match for 0xfa1: "OK"
    //         0049f5b4     PUSH       0xfa1
    //         0049f5b9     PUSH       ESI
    //         0049f5ba     PUSH       EBP
    //         0049f5bb     MOV        this,EBP
    //         0049f5bd     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         0049f5c2     TEST       EAX,EAX
    //         0049f5c4     JZ         LAB_0049f853
    //                              scr_mp.cpp:125 (14)
    //         0049f5ca     MOV        this,dword ptr [ESI]
    //         0049f5cc     PUSH       -0x1
    //         0049f5ce     PUSH       0x7531
    //         0049f5d3     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              scr_mp.cpp:126 (47)
    //         0049f5d8     PUSH       0x0
    //         0049f5da     PUSH       0x0
    //         0049f5dc     PUSH       0x0
    //         0049f5de     PUSH       0x1e
    //         0049f5e0     PUSH       0xf0
    //         0049f5e5     PUSH       0x1b8
    //         0049f5ea     PUSH       0x14a
    //         0049f5ef     PUSH       0x0
    //                              language.dll match for 0xfa2: "Cancel"
    //         0049f5f1     PUSH       0xfa2
    //         0049f5f6     PUSH       EBX
    //         0049f5f7     PUSH       EBP
    //         0049f5f8     MOV        this,EBP
    //         0049f5fa     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         0049f5ff     TEST       EAX,EAX
    //         0049f601     JZ         LAB_0049f853
    //                              scr_mp.cpp:127 (14)
    //         0049f607     MOV        this,dword ptr [EBX]
    //         0049f609     PUSH       -0x1
    //         0049f60b     PUSH       0x7532
    //         0049f610     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              scr_mp.cpp:128 (2)
    //         0049f615     MOV        EAX,dword ptr [EBX]
    //                              scr_mp.cpp:129 (70)
    //         0049f617     PUSH       0x0
    //         0049f619     PUSH       0x0
    //         0049f61b     PUSH       0x0
    //         0049f61d     PUSH       0x1e
    //         0049f61f     PUSH       0x1e
    //         0049f621     PUSH       0x1b8
    //         0049f626     MOV        dword ptr [EAX + 0x298],0x1b
    //         0049f630     MOV        dword ptr [EAX + 0x29c],0x0
    //         0049f63a     PUSH       0x244
    //         0049f63f     PUSH       0x0
    //         0049f641     LEA        EAX,[EBP + 0x490]
    //                              language.dll match for 0xfa9: "?"
    //         0049f647     PUSH       0xfa9
    //         0049f64c     PUSH       EAX
    //         0049f64d     PUSH       EBP
    //         0049f64e     MOV        this,EBP
    //         0049f650     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         0049f655     TEST       EAX,EAX
    //         0049f657     JZ         LAB_0049f853
    //                              scr_mp.cpp:132 (44)
    //         0049f65d     PUSH       0x0
    //         0049f65f     PUSH       -0x1
    //         0049f661     PUSH       -0x1
    //         0049f663     PUSH       0x0
    //         0049f665     PUSH       0x0
    //         0049f667     PUSH       0x0
    //         0049f669     PUSH       0x0
    //         0049f66b     PUSH       0x0
    //         0049f66d     LEA        ESI,[EBP + 0x494]
    //                              language.dll match for 0x3ea: "X"
    //         0049f673     PUSH       0x3ea
    //         0049f678     PUSH       ESI
    //         0049f679     PUSH       EBP
    //         0049f67a     MOV        this,EBP
    //         0049f67c     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         0049f681     TEST       EAX,EAX
    //         0049f683     JZ         LAB_0049f853
    //                              scr_mp.cpp:133 (9)
    //         0049f689     MOV        this,dword ptr [ESI]
    //         0049f68b     PUSH       0x1
    //         0049f68d     MOV        EDX,dword ptr [this->_padding_]
    //         0049f68f     CALL       dword ptr [EDX + 0x14]
    //                              scr_mp.cpp:134 (33)
    //         0049f692     MOV        this,dword ptr [ESI]
    //         0049f694     PUSH       0x0
    //         0049f696     PUSH       0x0=>DAT_fffffff8
    //         0049f698     PUSH       0x0=>DAT_fffffff4
    //         0049f69a     MOV        EAX,dword ptr [this->_padding_]
    //         0049f69c     PUSH       0x0=>DAT_fffffff0
    //         0049f69e     PUSH       0x11
    //         0049f6a0     PUSH       0x11
    //         0049f6a2     PUSH       0x11
    //         0049f6a4     PUSH       0x11
    //         0049f6a6     PUSH       0x4
    //         0049f6a8     PUSH       0x4
    //         0049f6aa     PUSH       0x4
    //         0049f6ac     PUSH       0x4
    //         0049f6ae     PUSH       0x9
    //         0049f6b0     CALL       dword ptr [EAX + 0x18]
    //                              scr_mp.cpp:160 (57)
    //         0049f6b3     LEA        this,[ESP + 0x30]
    //         0049f6b7     LEA        EDX,[ESP + 0x10]
    //         0049f6bb     PUSH       this
    //         0049f6bc     PUSH       EDX=>DAT_fffffff8
    //         0049f6bd     PUSH       0x0=>DAT_fffffff4
    //         0049f6bf     PUSH       offset DAT_fffffff0
    //         0049f6c4     PUSH       0x0
    //         0049f6c6     PUSH       0x0
    //         0049f6c8     LEA        EBX,[EBP + 0x4a0]
    //         0049f6ce     LEA        ESI,[EBP + 0x59f]
    //         0049f6d4     PUSH       0x0
    //         0049f6d6     PUSH       s_http\shell\open\command                        = "http\\shell\\open\\command"
    //         0049f6db     PUSH       0x80000000
    //         0049f6e0     MOV        byte ptr [EBX],0x0
    //         0049f6e3     MOV        byte ptr [ESI],0x0
    //         0049f6e6     CALL       dword ptr [->ADVAPI32.DLL::RegCreateKeyExA]      = 0048b386
    //                              scr_mp.cpp:171 (48)
    //         0049f6ec     LEA        EAX,[ESP + 0x14]
    //         0049f6f0     LEA        this,[ESP + 0x38]
    //         0049f6f4     PUSH       EAX
    //         0049f6f5     MOV        EAX,dword ptr [ESP + 0x14]
    //         0049f6f9     LEA        EDX,[ESP + 0x1c]
    //         0049f6fd     PUSH       this=>DAT_fffffff8
    //         0049f6fe     PUSH       EDX=>DAT_fffffff4
    //         0049f6ff     PUSH       0x0=>DAT_fffffff0
    //         0049f701     PUSH       0x0
    //         0049f703     PUSH       EAX
    //         0049f704     MOV        dword ptr [ESP + 0x30],0x1
    //         0049f70c     MOV        dword ptr [ESP + 0x2c],0xff
    //         0049f714     CALL       dword ptr [->ADVAPI32.DLL::RegQueryValueExA]     = 0048b3b8
    //         0049f71a     MOV        EDI,EAX
    //                              scr_mp.cpp:173 (8)
    //         0049f71c     MOV        EAX,dword ptr [ESP + 0x10]
    //         0049f720     TEST       EAX,EAX
    //         0049f722     JZ         LAB_0049f733
    //                              scr_mp.cpp:174 (7)
    //         0049f724     PUSH       EAX
    //         0049f725     CALL       dword ptr [->ADVAPI32.DLL::RegCloseKey]          = 0048b398
    //                              scr_mp.cpp:175 (8)
    //         0049f72b     MOV        dword ptr [ESP + 0x10],0x0
    //                               LAB_0049f733                                                 XREF[1]:     0049f722(j)  
    //                              scr_mp.cpp:180 (8)
    //         0049f733     TEST       EDI,EDI
    //         0049f735     JNZ        LAB_0049f7fe
    //                              scr_mp.cpp:188 (36)
    //         0049f73b     LEA        EDI,[ESP + 0x38]
    //         0049f73f     OR         this,0xffffffff
    //         0049f742     XOR        EAX,EAX
    //         0049f744     LEA        EDX,[ESP + 0x138]
    //         0049f74b     SCASB.RE   ES:EDI
    //         0049f74d     NOT        this
    //         0049f74f     DEC        this
    //         0049f750     PUSH       this
    //         0049f751     LEA        this,[ESP + 0x3d]
    //         0049f755     PUSH       this=>DAT_fffffff8
    //         0049f756     PUSH       EDX=>DAT_fffffff4
    //         0049f757     CALL       strncpy                                          undefined strncpy()
    //         0049f75c     ADD        ESP,0xc
    //                              scr_mp.cpp:190 (18)
    //         0049f75f     LEA        EAX,[ESP + 0x138]
    //         0049f766     PUSH       0x22
    //         0049f768     PUSH       EAX=>DAT_fffffff8
    //         0049f769     CALL       strchr                                           undefined strchr()
    //         0049f76e     ADD        ESP,0x8
    //                              scr_mp.cpp:191 (4)
    //         0049f771     TEST       EAX,EAX
    //         0049f773     JZ         LAB_0049f79e
    //                              scr_mp.cpp:193 (12)
    //         0049f775     LEA        this,[ESP + 0x138]
    //         0049f77c     SUB        EAX,this
    //         0049f77e     INC        EAX
    //         0049f77f     MOV        EDI,EAX
    //                              scr_mp.cpp:194 (21)
    //         0049f781     LEA        EAX,[ESP + 0x138]
    //         0049f788     LEA        EDX,[EDI + -0x1]
    //         0049f78b     PUSH       EDX
    //         0049f78c     PUSH       EAX=>DAT_fffffff8
    //         0049f78d     PUSH       ESI=>DAT_fffffff4
    //         0049f78e     CALL       strncpy                                          undefined strncpy()
    //         0049f793     ADD        ESP,0xc
    //                              scr_mp.cpp:195 (8)
    //         0049f796     MOV        byte ptr [EDI + EBP*0x1 + 0x59e],0x0
    //                               LAB_0049f79e                                                 XREF[1]:     0049f773(j)  
    //                              scr_mp.cpp:198 (18)
    //         0049f79e     MOV        this,dword ptr [Regs]                            = 00000000
    //         0049f7a4     PUSH       s_Zone                                           = "Zone"
    //         0049f7a9     PUSH       0x0=>DAT_fffffff8
    //         0049f7ab     CALL       TRegistry::RegGetAscii                           char * RegGetAscii(TRegistry * this, int para
    //                              scr_mp.cpp:199 (4)
    //         0049f7b0     TEST       EAX,EAX
    //         0049f7b2     JZ         LAB_0049f7fe
    //                              scr_mp.cpp:200 (43)
    //         0049f7b4     MOV        EDI,EAX
    //         0049f7b6     OR         this,0xffffffff
    //         0049f7b9     XOR        EAX,EAX
    //         0049f7bb     LEA        EDX,[ESP + 0x38]
    //         0049f7bf     SCASB.RE   ES:EDI
    //         0049f7c1     NOT        this
    //         0049f7c3     SUB        EDI,this
    //         0049f7c5     MOV        ESI,EDI
    //         0049f7c7     MOV        EDI,EDX
    //         0049f7c9     MOV        EDX,this
    //         0049f7cb     OR         this,0xffffffff
    //         0049f7ce     SCASB.RE   ES:EDI
    //         0049f7d0     MOV        this,EDX
    //         0049f7d2     DEC        EDI
    //         0049f7d3     SHR        this,0x2
    //         0049f7d6     MOVSD.REP  ES:EDI,ESI
    //         0049f7d8     MOV        this,EDX
    //         0049f7da     AND        this,0x3
    //         0049f7dd     MOVSB.REP  ES:EDI,ESI
    //                              scr_mp.cpp:201 (31)
    //         0049f7df     LEA        EDI,[ESP + 0x38]
    //         0049f7e3     OR         this,0xffffffff
    //         0049f7e6     SCASB.RE   ES:EDI
    //         0049f7e8     NOT        this
    //         0049f7ea     SUB        EDI,this
    //         0049f7ec     MOV        EAX,this
    //         0049f7ee     MOV        ESI,EDI
    //         0049f7f0     MOV        EDI,EBX
    //         0049f7f2     SHR        this,0x2
    //         0049f7f5     MOVSD.REP  ES:EDI,ESI
    //         0049f7f7     MOV        this,EAX
    //         0049f7f9     AND        this,0x3
    //         0049f7fc     MOVSB.REP  ES:EDI,ESI
    //                               LAB_0049f7fe                                                 XREF[2]:     0049f735(j), 0049f7b2(j)  
    //                              scr_mp.cpp:206 (7)
    //         0049f7fe     MOV        this,EBP
    //         0049f800     CALL       TribeMPStartupScreen::fillList                   void fillList(TribeMPStartupScreen * this)
    //                              scr_mp.cpp:209 (14)
    //         0049f805     MOV        this,dword ptr [EBP + 0x480]
    //         0049f80b     PUSH       this
    //         0049f80c     MOV        this,EBP
    //         0049f80e     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                              scr_mp.cpp:216 (22)
    //         0049f813     MOV        this,dword ptr [EBP + 0x488]
    //         0049f819     MOV        EDX,dword ptr [EBP + 0x480]
    //         0049f81f     MOV        EAX,dword ptr [EBP + 0x498]
    //         0049f825     MOV        dword ptr [ESP + 0x24],this
    //                              scr_mp.cpp:219 (42)
    //         0049f829     LEA        this,[ESP + 0x1c]
    //         0049f82d     MOV        dword ptr [ESP + 0x1c],EDX
    //         0049f831     MOV        EDX,dword ptr [EBP + 0x48c]
    //         0049f837     MOV        dword ptr [ESP + 0x20],EAX
    //         0049f83b     MOV        EAX,dword ptr [EBP + 0x490]
    //         0049f841     PUSH       0x5
    //         0049f843     PUSH       this=>DAT_fffffff8
    //         0049f844     MOV        this,EBP
    //         0049f846     MOV        dword ptr [ESP + 0x30],EDX
    //         0049f84a     MOV        dword ptr [ESP + 0x34],EAX
    //         0049f84e     CALL       TPanel::set_tab_order                            void set_tab_order(TPanel * this, TPanel * * 
    //                               LAB_0049f853                                                 XREF[11]:    0049f3ff(j), 0049f444(j), 
    //                                                                                                         0049f470(j), 0049f4fc(j), 
    //                                                                                                         0049f53c(j), 0049f566(j), 
    //                                                                                                         0049f581(j), 0049f5c4(j), 
    //                                                                                                         0049f601(j), 0049f657(j), 
    //                                                                                                         0049f683(j)  
    //                              scr_mp.cpp:220 (27)
    //         0049f853     MOV        this,dword ptr [ESP + local_c]
    //         0049f85a     POP        EDI
    //         0049f85b     MOV        EAX,EBP
    //         0049f85d     POP        ESI
    //         0049f85e     POP        EBP
    //         0049f85f     MOV        dword ptr FS:[0x0],this
    //         0049f866     POP        EBX
    //         0049f867     ADD        ESP,0x334
    //         0049f86d     RET
}

// Offset: 0x0049F890
void TribeMPStartupScreen(TribeMPStartupScreen* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall TribeMPStartupScreen::~TribeMPStartupScreen(void)                          *
    //                              *********************************************************************************************************
    //                              void __thiscall ~TribeMPStartupScreen(TribeMPStartupScreen * this)
    //              void              <VOID>         <RETURN>
    //              TribeMPStartup    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0049f8b9(W), 0049f974(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0049f981(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0049f8a9(W)  
    //                               ??1TribeMPStartupScreen@@UAE@XZ                              XREF[1]:     `vector_deleting_destructor':0049f
    //                               TribeMPStartupScreen::~TribeMPStartupScreen
    //                              scr_mp.cpp:225 (35)
    //         0049f890     PUSH       -0x1
    //         0049f892     PUSH       FUN_0055f118
    //         0049f897     MOV        EAX,FS:[0x0]
    //         0049f89d     PUSH       EAX
    //         0049f89e     MOV        dword ptr FS:[0x0],ESP
    //         0049f8a5     PUSH       this
    //         0049f8a6     PUSH       ESI
    //         0049f8a7     MOV        ESI,this
    //         0049f8a9     MOV        dword ptr [ESP + local_10],ESI
    //         0049f8ad     MOV        dword ptr [ESI],TribeMPStartupScreen::`vftable'  = 0049f870
    //                              scr_mp.cpp:226 (20)
    //         0049f8b3     LEA        EAX,[ESI + 0x478]
    //         0049f8b9     MOV        dword ptr [ESP + local_4],0x0
    //         0049f8c1     PUSH       EAX
    //         0049f8c2     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_mp.cpp:227 (14)
    //         0049f8c7     LEA        this,[ESI + 0x47c]
    //         0049f8cd     PUSH       this
    //         0049f8ce     MOV        this,ESI
    //         0049f8d0     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_mp.cpp:228 (14)
    //         0049f8d5     LEA        EDX,[ESI + 0x480]
    //         0049f8db     MOV        this,ESI
    //         0049f8dd     PUSH       EDX
    //         0049f8de     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_mp.cpp:229 (14)
    //         0049f8e3     LEA        EAX,[ESI + 0x484]
    //         0049f8e9     MOV        this,ESI
    //         0049f8eb     PUSH       EAX
    //         0049f8ec     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_mp.cpp:230 (14)
    //         0049f8f1     LEA        this,[ESI + 0x498]
    //         0049f8f7     PUSH       this
    //         0049f8f8     MOV        this,ESI
    //         0049f8fa     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_mp.cpp:231 (14)
    //         0049f8ff     LEA        EDX,[ESI + 0x49c]
    //         0049f905     MOV        this,ESI
    //         0049f907     PUSH       EDX
    //         0049f908     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_mp.cpp:233 (14)
    //         0049f90d     LEA        EAX,[ESI + 0x488]
    //         0049f913     MOV        this,ESI
    //         0049f915     PUSH       EAX
    //         0049f916     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_mp.cpp:234 (14)
    //         0049f91b     LEA        this,[ESI + 0x48c]
    //         0049f921     PUSH       this
    //         0049f922     MOV        this,ESI
    //         0049f924     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_mp.cpp:235 (14)
    //         0049f929     LEA        EDX,[ESI + 0x490]
    //         0049f92f     MOV        this,ESI
    //         0049f931     PUSH       EDX
    //         0049f932     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_mp.cpp:236 (14)
    //         0049f937     LEA        EAX,[ESI + 0x494]
    //         0049f93d     MOV        this,ESI
    //         0049f93f     PUSH       EAX
    //         0049f940     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_mp.cpp:238 (15)
    //         0049f945     PUSH       s_Create_Dialog                                  = "Create Dialog"
    //         0049f94a     MOV        this,panel_system
    //         0049f94f     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_mp.cpp:239 (15)
    //         0049f954     PUSH       s_OKDialog                                       = 4Fh
    //         0049f959     MOV        this,panel_system
    //         0049f95e     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_mp.cpp:240 (17)
    //         0049f963     PUSH       s_YesNoDialog                                    = 59h
    //         0049f968     MOV        this,panel_system
    //         0049f96d     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //         0049f972     MOV        this,ESI
    //                              scr_mp.cpp:241 (29)
    //         0049f974     MOV        dword ptr [ESP + local_4],0xffffffff
    //         0049f97c     CALL       TScreenPanel::~TScreenPanel                      void ~TScreenPanel(TScreenPanel * this)
    //         0049f981     MOV        this,dword ptr [ESP + local_c]
    //         0049f985     POP        ESI
    //         0049f986     MOV        dword ptr FS:[0x0],this
    //         0049f98d     ADD        ESP,0x10
    //         0049f990     RET
}

// Offset: 0x0049F9A0
long TribeMPStartupScreen::handle_idle() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TribeMPStartupScreen::handle_idle(void)                               *
    //                              *********************************************************************************************************
    //                              long __thiscall handle_idle(TribeMPStartupScreen * this)
    //              long              EAX:4          <RETURN>
    //              TribeMPStartup    ECX:4 (auto)   this
    //                               ?handle_idle@TribeMPStartupScreen@@UAEJXZ                    XREF[1]:     005731ec(*)  
    //                               TribeMPStartupScreen::handle_idle
    //                              scr_mp.cpp:247 (3)
    //         0049f9a0     PUSH       ESI
    //         0049f9a1     MOV        ESI,this
    //                              scr_mp.cpp:248 (16)
    //         0049f9a3     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0049f9a9     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         0049f9af     TEST       EAX,EAX
    //         0049f9b1     JNZ        LAB_0049f9b8
    //                              scr_mp.cpp:249 (5)
    //         0049f9b3     CALL       RGE_Base_Game::enable_input                      void enable_input(RGE_Base_Game * this)
    //                               LAB_0049f9b8                                                 XREF[1]:     0049f9b1(j)  
    //                              scr_mp.cpp:251 (7)
    //         0049f9b8     MOV        this,ESI
    //         0049f9ba     CALL       TPanel::handle_idle                              long handle_idle(TPanel * this)
    //                              scr_mp.cpp:252 (2)
    //         0049f9bf     POP        ESI
    //         0049f9c0     RET
}

// Offset: 0x0049F9D0
long TribeMPStartupScreen::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TribeMPStartupScreen::action(class TPanel *,long,unsigned long,uns... *
    //                              *********************************************************************************************************
    //                              long __thiscall action(TribeMPStartupScreen * this, TPanel * param_1
    //              long              EAX:4          <RETURN>
    //              TribeMPStartup    ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     0049f9f2(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[5]:     0049fa09(R), 0049fd72(R), 0049fde4(R), 0049fe50(R), 
    //                                                                                     0049fe87(R)  
    //              ulong             Stack[0xc]:4   param_3                   XREF[1]:     0049fe95(R)  
    //              ulong             Stack[0x10]:4  param_4                   XREF[1]:     0049fe8e(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[6]:     0049fba4(W), 0049fc07(W), 0049fc24(W), 0049fc44(W), 
    //                                                                                     0049fca3(W), 0049fcc3(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0049fea7(R)  
    //              TCommunication    Stack[-0x259   Serv                      XREF[0,3]:   0049fb95(*), 0049fbba(*), 0049fc40(*)  
    //              undefined         Stack[-0x25a   local_25a0                XREF[1]:     0049fbb4(*)  
    //              undefined4        Stack[-0x25a   local_25a4                XREF[2]:     0049fc01(W), 0049fc9d(W)  
    //              undefined4        Stack[-0x25b   local_25b4                XREF[1]:     0049fbdb(W)  
    //              undefined4        Stack[-0x25b   local_25b8                XREF[1]:     0049fbd8(W)  
    //              undefined4        Stack[-0x25b   local_25bc                XREF[1]:     0049fbcf(W)  
    //              undefined4        Stack[-0x25c   local_25c0                XREF[1]:     0049fbca(*)  
    //                               ?action@TribeMPStartupScreen@@UAEJPAVTPanel@@JKK@Z           XREF[1]:     00573254(*)  
    //                               TribeMPStartupScreen::action
    //                              scr_mp.cpp:258 (34)
    //         0049f9d0     MOV        EAX,FS:[0x0]
    //         0049f9d6     PUSH       -0x1
    //         0049f9d8     PUSH       FUN_0055f157
    //         0049f9dd     PUSH       EAX
    //         0049f9de     MOV        EAX,0x2598
    //         0049f9e3     MOV        dword ptr FS:[0x0],ESP
    //         0049f9ea     CALL       __alloca_probe                                   undefined __alloca_probe()
    //         0049f9ef     PUSH       EBP
    //         0049f9f0     PUSH       ESI
    //         0049f9f1     PUSH       EDI
    //                              scr_mp.cpp:259 (17)
    //         0049f9f2     MOV        EDI,dword ptr [ESP + param_1]
    //         0049f9f9     TEST       EDI,EDI
    //         0049f9fb     MOV        EBP,this
    //         0049f9fd     JZ         LAB_0049fe87
    //                              scr_mp.cpp:260 (22)
    //         0049fa03     MOV        EAX,dword ptr [EBP + 0x498]
    //         0049fa09     MOV        ESI,dword ptr [ESP + param_2]
    //         0049fa10     CMP        EDI,EAX
    //         0049fa12     JNZ        LAB_0049fa3b
    //         0049fa14     CMP        ESI,0x3
    //         0049fa17     JNZ        LAB_0049fa3b
    //                              scr_mp.cpp:261 (24)
    //         0049fa19     MOV        this,dword ptr [EBP + 0x488]
    //         0049fa1f     MOV        EAX,dword ptr [EBP]
    //         0049fa22     PUSH       0x0
    //         0049fa24     PUSH       0x0
    //         0049fa26     PUSH       0x1
    //         0049fa28     PUSH       this
    //         0049fa29     MOV        this,EBP
    //         0049fa2b     CALL       dword ptr [EAX + 0xb4]
    //                              scr_mp.cpp:262 (10)
    //         0049fa31     MOV        EAX,0x1
    //         0049fa36     JMP        LAB_0049fea7
    //                               LAB_0049fa3b                                                 XREF[2]:     0049fa12(j), 0049fa17(j)  
    //                              scr_mp.cpp:266 (11)
    //         0049fa3b     CMP        EDI,dword ptr [EBP + 0x494]
    //         0049fa41     JNZ        LAB_0049fa4c
    //         0049fa43     CMP        ESI,0x1
    //                              scr_mp.cpp:269 (6)
    //         0049fa46     JZ         LAB_0049fe75
    //                               LAB_0049fa4c                                                 XREF[1]:     0049fa41(j)  
    //                              scr_mp.cpp:273 (21)
    //         0049fa4c     CMP        EDI,dword ptr [EBP + 0x488]
    //         0049fa52     JNZ        LAB_0049fc5e
    //         0049fa58     CMP        ESI,0x1
    //         0049fa5b     JNZ        LAB_0049fc5e
    //                              scr_mp.cpp:276 (12)
    //         0049fa61     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0049fa67     PUSH       ESI
    //         0049fa68     CALL       RGE_Base_Game::setMultiplayerGame                void setMultiplayerGame(RGE_Base_Game * this,
    //                              scr_mp.cpp:278 (16)
    //         0049fa6d     MOV        this,dword ptr [EBP + 0x480]
    //         0049fa73     CALL       TEditPanel::get_text                             char * get_text(TEditPanel * this)
    //         0049fa78     CMP        byte ptr [EAX],0x0
    //         0049fa7b     JNZ        LAB_0049fa9c
    //                              scr_mp.cpp:279 (24)
    //         0049fa7d     PUSH       0x64
    //         0049fa7f     PUSH       0x1c2
    //         0049fa84     PUSH       s_Name_Error                                     = 4Eh
    //                              language.dll match for 0x258f: "You must enter a valid player
    //         0049fa89     PUSH       0x258f
    //         0049fa8e     MOV        this,EBP
    //         0049fa90     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, long p
    //                              scr_mp.cpp:359 (7)
    //         0049fa95     MOV        EAX,ESI
    //         0049fa97     JMP        LAB_0049fea7
    //                               LAB_0049fa9c                                                 XREF[1]:     0049fa7b(j)  
    //                              scr_mp.cpp:281 (15)
    //         0049fa9c     MOV        this,dword ptr [EBP + 0x498]
    //         0049faa2     CALL       TTextPanel::numberLines                          int numberLines(TTextPanel * this)
    //         0049faa7     TEST       EAX,EAX
    //         0049faa9     JNZ        LAB_0049facd
    //                              scr_mp.cpp:282 (24)
    //         0049faab     PUSH       0x64
    //         0049faad     PUSH       0x1c2
    //         0049fab2     PUSH       s_List_Error                                     = 4Ch
    //                              language.dll match for 0x2592: "No multiplayer connections ar
    //         0049fab7     PUSH       0x2592
    //         0049fabc     MOV        this,EBP
    //         0049fabe     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, long p
    //                              scr_mp.cpp:359 (10)
    //         0049fac3     MOV        EAX,0x1
    //         0049fac8     JMP        LAB_0049fea7
    //                               LAB_0049facd                                                 XREF[1]:     0049faa9(j)  
    //                              scr_mp.cpp:284 (26)
    //         0049facd     MOV        AL,byte ptr [EBP + 0x4a0]
    //         0049fad3     TEST       AL,AL
    //         0049fad5     JZ         LAB_0049fb09
    //         0049fad7     MOV        this,dword ptr [EBP + 0x498]
    //         0049fadd     CALL       TTextPanel::get_id                               long get_id(TTextPanel * this)
    //         0049fae2     CMP        EAX,-0x1
    //         0049fae5     JNZ        LAB_0049fb09
    //                              scr_mp.cpp:285 (24)
    //         0049fae7     PUSH       0x64
    //         0049fae9     PUSH       0x1c2
    //         0049faee     PUSH       s_Start_Zone                                     = 53h
    //                              language.dll match for 0x2593: "Start your Web browser and go
    //         0049faf3     PUSH       0x2593
    //         0049faf8     MOV        this,EBP
    //         0049fafa     CALL       TEasy_Panel::popupYesNoDialog                    void popupYesNoDialog(TEasy_Panel * this, lon
    //                              scr_mp.cpp:359 (10)
    //         0049faff     MOV        EAX,0x1
    //         0049fb04     JMP        LAB_0049fea7
    //                               LAB_0049fb09                                                 XREF[2]:     0049fad5(j), 0049fae5(j)  
    //                              scr_mp.cpp:289 (11)
    //         0049fb09     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0049fb0f     CALL       RGE_Base_Game::disable_input                     void disable_input(RGE_Base_Game * this)
    //                              scr_mp.cpp:293 (53)
    //         0049fb14     MOV        this,dword ptr [EBP + 0x480]
    //         0049fb1a     CALL       TEditPanel::currentLine                          char * currentLine(TEditPanel * this)
    //         0049fb1f     MOV        EDI,EAX
    //         0049fb21     OR         this,0xffffffff
    //         0049fb24     XOR        EAX,EAX
    //         0049fb26     SCASB.RE   ES:EDI
    //         0049fb28     NOT        this
    //         0049fb2a     PUSH       this
    //         0049fb2b     MOV        this,dword ptr [EBP + 0x480]
    //         0049fb31     CALL       TEditPanel::currentLine                          char * currentLine(TEditPanel * this)
    //         0049fb36     MOV        this,dword ptr [Regs]                            = 00000000
    //         0049fb3c     PUSH       EAX
    //         0049fb3d     PUSH       s_Default_Age_Of_Empires_Player_Na               = "Default Age Of Empires Player Name"
    //         0049fb42     PUSH       0x1
    //         0049fb44     CALL       TRegistry::RegSetAscii                           int RegSetAscii(TRegistry * this, int param_1
    //                              scr_mp.cpp:295 (53)
    //         0049fb49     MOV        this,dword ptr [EBP + 0x498]
    //         0049fb4f     CALL       TTextPanel::get_text                             char * get_text(TTextPanel * this)
    //         0049fb54     MOV        EDI,EAX
    //         0049fb56     OR         this,0xffffffff
    //         0049fb59     XOR        EAX,EAX
    //         0049fb5b     SCASB.RE   ES:EDI
    //         0049fb5d     NOT        this
    //         0049fb5f     PUSH       this
    //         0049fb60     MOV        this,dword ptr [EBP + 0x498]
    //         0049fb66     CALL       TTextPanel::get_text                             char * get_text(TTextPanel * this)
    //         0049fb6b     MOV        this,dword ptr [Regs]                            = 00000000
    //         0049fb71     PUSH       EAX
    //         0049fb72     PUSH       s_Default_Age_Of_Empires_Multiplay               = "Default Age Of Empires Multiplayer Service"
    //         0049fb77     PUSH       0x1
    //         0049fb79     CALL       TRegistry::RegSetAscii                           int RegSetAscii(TRegistry * this, int param_1
    //                              scr_mp.cpp:296 (23)
    //         0049fb7e     MOV        this,dword ptr [EBP + 0x480]
    //         0049fb84     CALL       TEditPanel::currentLine                          char * currentLine(TEditPanel * this)
    //         0049fb89     MOV        this,dword ptr [comm]                            = 00000000
    //         0049fb8f     PUSH       EAX
    //         0049fb90     CALL       TCommunications_Handler::SetMyPlayerName         void SetMyPlayerName(TCommunications_Handler 
    //                              scr_mp.cpp:299 (9)
    //         0049fb95     LEA        this=>Serv+0x4,[ESP + 0x20]
    //         0049fb99     CALL       TCommunications_Services::TCommunications_Serv   undefined TCommunications_Services(TCommunica
    //                              scr_mp.cpp:300 (75)
    //         0049fb9e     MOV        this,dword ptr [EBP + 0x498]
    //         0049fba4     MOV        dword ptr [ESP + local_4],0x0
    //         0049fbaf     CALL       TTextPanel::get_id                               long get_id(TTextPanel * this)
    //         0049fbb4     LEA        EDX=>local_25a0,[ESP + 0x10]
    //         0049fbb8     PUSH       EAX
    //         0049fbb9     PUSH       EDX
    //         0049fbba     LEA        this=>Serv+0x4,[ESP + 0x28]
    //         0049fbbe     CALL       TCommunications_Services::GetServiceGUID         _GUID * GetServiceGUID(TCommunications_Servic
    //         0049fbc3     MOV        EDX,dword ptr [EAX]
    //         0049fbc5     SUB        ESP,0x10
    //         0049fbc8     MOV        this,ESP
    //         0049fbca     MOV        dword ptr [this->_padding_]=>local_25c0,EDX
    //         0049fbcc     MOV        EDX,dword ptr [EAX + 0x4]
    //         0049fbcf     MOV        dword ptr [ECX + local_25bc],EDX
    //         0049fbd2     MOV        EDX,dword ptr [EAX + 0x8]
    //         0049fbd5     MOV        EAX,dword ptr [EAX + 0xc]
    //         0049fbd8     MOV        dword ptr [ECX + local_25b8],EDX
    //         0049fbdb     MOV        dword ptr [ECX + local_25b4],EAX
    //         0049fbde     MOV        this,dword ptr [comm]                            = 00000000
    //         0049fbe4     CALL       TCommunications_Handler::SetServiceGUID          void SetServiceGUID(TCommunications_Handler *
    //                              scr_mp.cpp:301 (11)
    //         0049fbe9     MOV        this,dword ptr [comm]                            = 00000000
    //         0049fbef     CALL       TCommunications_Handler::InitJoinGame            long InitJoinGame(TCommunications_Handler * t
    //                              language.dll match for 0x4b0: "Ready"
    //                              scr_mp.cpp:305 (36)
    //         0049fbf4     PUSH       0x4b0
    //         0049fbf9     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0049fbfe     ADD        ESP,0x4
    //         0049fc01     MOV        dword ptr [ESP + local_25a4],EAX
    //         0049fc05     TEST       EAX,EAX
    //         0049fc07     MOV        byte ptr [ESP + local_4],0x1
    //         0049fc0f     JZ         LAB_0049fc18
    //         0049fc11     MOV        this,EAX
    //         0049fc13     CALL       TribeJoinScreen::TribeJoinScreen                 undefined TribeJoinScreen(TribeJoinScreen * t
    //                               LAB_0049fc18                                                 XREF[1]:     0049fc0f(j)  
    //                              scr_mp.cpp:306 (25)
    //         0049fc18     PUSH       0x0
    //         0049fc1a     PUSH       s_Join_Screen                                    = "Join Screen"
    //         0049fc1f     MOV        this,panel_system
    //         0049fc24     MOV        byte ptr [ESP + local_4],0x0
    //         0049fc2c     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              scr_mp.cpp:307 (19)
    //         0049fc31     PUSH       s_MP_Startup_Screen                              = "MP Startup Screen"
    //         0049fc36     MOV        this,panel_system
    //         0049fc3b     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //         0049fc40     LEA        this=>Serv+0x4,[ESP + 0x20]
    //                              scr_mp.cpp:308 (16)
    //         0049fc44     MOV        dword ptr [ESP + local_4],0xffffffff
    //         0049fc4f     CALL       TCommunications_Services::~TCommunications_Ser   void ~TCommunications_Services(TCommunication
    //                              scr_mp.cpp:310 (10)
    //         0049fc54     MOV        EAX,0x1
    //         0049fc59     JMP        LAB_0049fea7
    //                               LAB_0049fc5e                                                 XREF[2]:     0049fa52(j), 0049fa5b(j)  
    //                              scr_mp.cpp:314 (26)
    //         0049fc5e     CMP        EDI,dword ptr [EBP + 0x48c]
    //         0049fc64     JNZ        LAB_0049fc6b
    //         0049fc66     CMP        ESI,0x1
    //         0049fc69     JZ         LAB_0049fc78
    //                               LAB_0049fc6b                                                 XREF[1]:     0049fc64(j)  
    //         0049fc6b     CMP        EDI,dword ptr [EBP + 0x480]
    //         0049fc71     JNZ        LAB_0049fcec
    //         0049fc73     CMP        ESI,0x1
    //         0049fc76     JNZ        LAB_0049fcec
    //                               LAB_0049fc78                                                 XREF[1]:     0049fc69(j)  
    //                              scr_mp.cpp:315 (11)
    //         0049fc78     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0049fc7e     CALL       RGE_Base_Game::disable_input                     void disable_input(RGE_Base_Game * this)
    //                              scr_mp.cpp:317 (13)
    //         0049fc83     MOV        this,dword ptr [comm]                            = 00000000
    //         0049fc89     PUSH       0x2
    //         0049fc8b     CALL       TCommunications_Handler::UnlinkToLevel           COMMSTATUS UnlinkToLevel(TCommunications_Hand
    //                              language.dll match for 0x4b0: "Ready"
    //                              scr_mp.cpp:318 (39)
    //         0049fc90     PUSH       0x4b0
    //         0049fc95     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0049fc9a     ADD        ESP,0x4
    //         0049fc9d     MOV        dword ptr [ESP + local_25a4],EAX
    //         0049fca1     TEST       EAX,EAX
    //         0049fca3     MOV        dword ptr [ESP + local_4],0x2
    //         0049fcae     JZ         LAB_0049fcb7
    //         0049fcb0     MOV        this,EAX
    //         0049fcb2     CALL       TRIBE_Screen_Main_Menu::TRIBE_Screen_Main_Menu   undefined TRIBE_Screen_Main_Menu(TRIBE_Screen
    //                               LAB_0049fcb7                                                 XREF[1]:     0049fcae(j)  
    //                              scr_mp.cpp:319 (28)
    //         0049fcb7     PUSH       0x0
    //         0049fcb9     PUSH       s_Main_Menu                                      = "Main Menu"
    //         0049fcbe     MOV        this,panel_system
    //         0049fcc3     MOV        dword ptr [ESP + local_4],0xffffffff
    //         0049fcce     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              scr_mp.cpp:320 (15)
    //         0049fcd3     PUSH       s_MP_Startup_Screen                              = "MP Startup Screen"
    //         0049fcd8     MOV        this,panel_system
    //         0049fcdd     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_mp.cpp:321 (10)
    //         0049fce2     MOV        EAX,0x1
    //         0049fce7     JMP        LAB_0049fea7
    //                               LAB_0049fcec                                                 XREF[2]:     0049fc71(j), 0049fc76(j)  
    //                              scr_mp.cpp:326 (13)
    //         0049fcec     CMP        EDI,dword ptr [EBP + 0x490]
    //         0049fcf2     JNZ        LAB_0049fd07
    //         0049fcf4     CMP        ESI,0x1
    //         0049fcf7     JNZ        LAB_0049fd07
    //                              scr_mp.cpp:327 (7)
    //         0049fcf9     MOV        this,EBP
    //         0049fcfb     CALL       TEasy_Panel::setup_popup_help                    void setup_popup_help(TEasy_Panel * this)
    //                              scr_mp.cpp:328 (7)
    //         0049fd00     MOV        EAX,ESI
    //         0049fd02     JMP        LAB_0049fea7
    //                               LAB_0049fd07                                                 XREF[2]:     0049fcf2(j), 0049fcf7(j)  
    //                              scr_mp.cpp:332 (68)
    //         0049fd07     MOV        this,EDI
    //         0049fd09     CALL       TPanel::panelName                                char * panelName(TPanel * this)
    //         0049fd0e     TEST       EAX,EAX
    //         0049fd10     JZ         LAB_0049fd79
    //         0049fd12     MOV        this,EDI
    //         0049fd14     MOV        ESI,s_List_Error                                 = 4Ch
    //         0049fd19     CALL       TPanel::panelName                                char * panelName(TPanel * this)
    //                               LAB_0049fd1e                                                 XREF[1]:     0049fd3c(j)  
    //         0049fd1e     MOV        DL,byte ptr [EAX]
    //         0049fd20     MOV        this,DL
    //         0049fd22     CMP        DL,byte ptr [ESI]=>s_List_Error                  = 4Ch
    //                                                                                  = 73h
    //         0049fd24     JNZ        LAB_0049fd42
    //         0049fd26     TEST       this,this
    //         0049fd28     JZ         LAB_0049fd3e
    //         0049fd2a     MOV        DL,byte ptr [EAX + 0x1]
    //         0049fd2d     MOV        this,DL
    //         0049fd2f     CMP        DL,byte ptr [ESI + 0x1]=>DAT_00586745            = 69h
    //                                                                                  = "t Error"
    //         0049fd32     JNZ        LAB_0049fd42
    //         0049fd34     ADD        EAX,0x2
    //         0049fd37     ADD        ESI,0x2
    //         0049fd3a     TEST       this,this
    //         0049fd3c     JNZ        LAB_0049fd1e
    //                               LAB_0049fd3e                                                 XREF[1]:     0049fd28(j)  
    //         0049fd3e     XOR        EAX,EAX
    //         0049fd40     JMP        LAB_0049fd47
    //                               LAB_0049fd42                                                 XREF[2]:     0049fd24(j), 0049fd32(j)  
    //         0049fd42     SBB        EAX,EAX
    //         0049fd44     SBB        EAX,-0x1
    //                               LAB_0049fd47                                                 XREF[1]:     0049fd40(j)  
    //         0049fd47     TEST       EAX,EAX
    //         0049fd49     JNZ        LAB_0049fd72
    //                              scr_mp.cpp:333 (15)
    //         0049fd4b     PUSH       s_List_Error                                     = 4Ch
    //         0049fd50     MOV        this,panel_system
    //         0049fd55     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_mp.cpp:334 (14)
    //         0049fd5a     MOV        EAX,dword ptr [EBP + 0x498]
    //         0049fd60     MOV        this,EBP
    //         0049fd62     PUSH       EAX
    //         0049fd63     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                              scr_mp.cpp:335 (17)
    //         0049fd68     MOV        EAX,0x1
    //         0049fd6d     JMP        LAB_0049fea7
    //                               LAB_0049fd72                                                 XREF[1]:     0049fd49(j)  
    //         0049fd72     MOV        ESI,dword ptr [ESP + param_2]
    //                               LAB_0049fd79                                                 XREF[1]:     0049fd10(j)  
    //                              scr_mp.cpp:339 (68)
    //         0049fd79     MOV        this,EDI
    //         0049fd7b     CALL       TPanel::panelName                                char * panelName(TPanel * this)
    //         0049fd80     TEST       EAX,EAX
    //         0049fd82     JZ         LAB_0049fdeb
    //         0049fd84     MOV        this,EDI
    //         0049fd86     MOV        ESI,s_Name_Error                                 = 4Eh
    //         0049fd8b     CALL       TPanel::panelName                                char * panelName(TPanel * this)
    //                               LAB_0049fd90                                                 XREF[1]:     0049fdae(j)  
    //         0049fd90     MOV        DL,byte ptr [EAX]
    //         0049fd92     MOV        this,DL
    //         0049fd94     CMP        DL,byte ptr [ESI]=>s_Name_Error                  = 4Eh
    //                                                                                  = 6Dh
    //         0049fd96     JNZ        LAB_0049fdb4
    //         0049fd98     TEST       this,this
    //         0049fd9a     JZ         LAB_0049fdb0
    //         0049fd9c     MOV        DL,byte ptr [EAX + 0x1]
    //         0049fd9f     MOV        this,DL
    //         0049fda1     CMP        DL,byte ptr [ESI + 0x1]=>DAT_00586751            = 61h
    //                                                                                  = "e Error"
    //         0049fda4     JNZ        LAB_0049fdb4
    //         0049fda6     ADD        EAX,0x2
    //         0049fda9     ADD        ESI,0x2
    //         0049fdac     TEST       this,this
    //         0049fdae     JNZ        LAB_0049fd90
    //                               LAB_0049fdb0                                                 XREF[1]:     0049fd9a(j)  
    //         0049fdb0     XOR        EAX,EAX
    //         0049fdb2     JMP        LAB_0049fdb9
    //                               LAB_0049fdb4                                                 XREF[2]:     0049fd96(j), 0049fda4(j)  
    //         0049fdb4     SBB        EAX,EAX
    //         0049fdb6     SBB        EAX,-0x1
    //                               LAB_0049fdb9                                                 XREF[1]:     0049fdb2(j)  
    //         0049fdb9     TEST       EAX,EAX
    //         0049fdbb     JNZ        LAB_0049fde4
    //                              scr_mp.cpp:340 (15)
    //         0049fdbd     PUSH       s_Name_Error                                     = 4Eh
    //         0049fdc2     MOV        this,panel_system
    //         0049fdc7     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_mp.cpp:341 (14)
    //         0049fdcc     MOV        EAX,dword ptr [EBP + 0x480]
    //         0049fdd2     MOV        this,EBP
    //         0049fdd4     PUSH       EAX
    //         0049fdd5     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                              scr_mp.cpp:342 (17)
    //         0049fdda     MOV        EAX,0x1
    //         0049fddf     JMP        LAB_0049fea7
    //                               LAB_0049fde4                                                 XREF[1]:     0049fdbb(j)  
    //         0049fde4     MOV        ESI,dword ptr [ESP + param_2]
    //                               LAB_0049fdeb                                                 XREF[1]:     0049fd82(j)  
    //                              scr_mp.cpp:346 (72)
    //         0049fdeb     MOV        this,EDI
    //         0049fded     CALL       TPanel::panelName                                char * panelName(TPanel * this)
    //         0049fdf2     TEST       EAX,EAX
    //         0049fdf4     JZ         LAB_0049fe8e
    //         0049fdfa     MOV        this,EDI
    //         0049fdfc     MOV        ESI,s_Start_Zone                                 = 53h
    //         0049fe01     CALL       TPanel::panelName                                char * panelName(TPanel * this)
    //                               LAB_0049fe06                                                 XREF[1]:     0049fe24(j)  
    //         0049fe06     MOV        DL,byte ptr [EAX]
    //         0049fe08     MOV        this,DL
    //         0049fe0a     CMP        DL,byte ptr [ESI]=>s_Start_Zone                  = 53h
    //                                                                                  = 61h
    //         0049fe0c     JNZ        LAB_0049fe2a
    //         0049fe0e     TEST       this,this
    //         0049fe10     JZ         LAB_0049fe26
    //         0049fe12     MOV        DL,byte ptr [EAX + 0x1]
    //         0049fe15     MOV        this,DL
    //         0049fe17     CMP        DL,byte ptr [ESI + 0x1]=>DAT_00586739            = 74h
    //                                                                                  = "rt Zone"
    //         0049fe1a     JNZ        LAB_0049fe2a
    //         0049fe1c     ADD        EAX,0x2
    //         0049fe1f     ADD        ESI,0x2
    //         0049fe22     TEST       this,this
    //         0049fe24     JNZ        LAB_0049fe06
    //                               LAB_0049fe26                                                 XREF[1]:     0049fe10(j)  
    //         0049fe26     XOR        EAX,EAX
    //         0049fe28     JMP        LAB_0049fe2f
    //                               LAB_0049fe2a                                                 XREF[2]:     0049fe0c(j), 0049fe1a(j)  
    //         0049fe2a     SBB        EAX,EAX
    //         0049fe2c     SBB        EAX,-0x1
    //                               LAB_0049fe2f                                                 XREF[1]:     0049fe28(j)  
    //         0049fe2f     TEST       EAX,EAX
    //         0049fe31     JNZ        LAB_0049fe87
    //                              scr_mp.cpp:347 (15)
    //         0049fe33     PUSH       s_Start_Zone                                     = 53h
    //         0049fe38     MOV        this,panel_system
    //         0049fe3d     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_mp.cpp:348 (14)
    //         0049fe42     MOV        EAX,dword ptr [EBP + 0x498]
    //         0049fe48     MOV        this,EBP
    //         0049fe4a     PUSH       EAX
    //         0049fe4b     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                              scr_mp.cpp:350 (11)
    //         0049fe50     MOV        EAX,dword ptr [ESP + param_2]
    //         0049fe57     TEST       EAX,EAX
    //         0049fe59     JNZ        LAB_0049fe80
    //                              scr_mp.cpp:351 (11)
    //         0049fe5b     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0049fe61     CALL       RGE_Base_Game::disable_input                     void disable_input(RGE_Base_Game * this)
    //                              scr_mp.cpp:352 (15)
    //         0049fe66     ADD        EBP,0x4a0
    //         0049fe6c     PUSH       0x3
    //         0049fe6e     PUSH       EBP
    //         0049fe6f     CALL       dword ptr [->KERNEL32.DLL::WinExec]              = 0048ac6e
    //                               LAB_0049fe75                                                 XREF[1]:     0049fa46(j)  
    //                              scr_mp.cpp:356 (11)
    //         0049fe75     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0049fe7b     CALL       RGE_Base_Game::close                             void close(RGE_Base_Game * this)
    //                               LAB_0049fe80                                                 XREF[1]:     0049fe59(j)  
    //                              scr_mp.cpp:359 (14)
    //         0049fe80     MOV        EAX,0x1
    //         0049fe85     JMP        LAB_0049fea7
    //                               LAB_0049fe87                                                 XREF[2]:     0049f9fd(j), 0049fe31(j)  
    //         0049fe87     MOV        ESI,dword ptr [ESP + param_2]
    //                               LAB_0049fe8e                                                 XREF[1]:     0049fdf4(j)  
    //                              scr_mp.cpp:364 (25)
    //         0049fe8e     MOV        this,dword ptr [ESP + param_4]
    //         0049fe95     MOV        EDX,dword ptr [ESP + param_3]
    //         0049fe9c     PUSH       this
    //         0049fe9d     PUSH       EDX
    //         0049fe9e     PUSH       ESI
    //         0049fe9f     PUSH       EDI
    //         0049fea0     MOV        this,EBP
    //         0049fea2     CALL       TEasy_Panel::action                              long action(TEasy_Panel * this, TPanel * para
    //                               LAB_0049fea7                                                 XREF[10]:    0049fa36(j), 0049fa97(j), 
    //                                                                                                         0049fac8(j), 0049fb04(j), 
    //                                                                                                         0049fc59(j), 0049fce7(j), 
    //                                                                                                         0049fd02(j), 0049fd6d(j), 
    //                                                                                                         0049fddf(j), 0049fe85(j)  
    //                              scr_mp.cpp:365 (26)
    //         0049fea7     MOV        this,dword ptr [ESP + local_c]
    //         0049feae     POP        EDI
    //         0049feaf     POP        ESI
    //         0049feb0     MOV        dword ptr FS:[0x0],this
    //         0049feb7     POP        EBP
    //         0049feb8     ADD        ESP,0x25a4
    //         0049febe     RET        0x10
}

// Offset: 0x0049FED0
void fillList(TribeMPStartupScreen* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall TribeMPStartupScreen::fillList(void)                                       *
    //                              *********************************************************************************************************
    //                              void __thiscall fillList(TribeMPStartupScreen * this)
    //              void              <VOID>         <RETURN>
    //              TribeMPStartup    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0049ff13(W), 004a0074(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004a0084(R)  
    //              TCommunication    Stack[-0x259   Serv                      XREF[0,7]:   0049ff00(*), 0049ff0c(*), 0049ff8e(*), 0049ff9f(*), 
    //                                                                                     0049ffb1(*), 0049ffca(*), 004a006d(*)  
    //              _finddata_t       Stack[-0x26a   file_info                 XREF[0,1]:   004a0014(*)  
    //              char[256]         Stack[-0x27a   lastServiceName           XREF[3,5]:   0049ff32(W), 004a0007(W), 004a004c(R), 0049ff55(*), 
    //                                                                                     0049ff5d(*), 0049ffd1(*), 0049ffde(*), 0049ffeb(R)  
    //              int               Stack[-0x27b   lastServiceNumber
    //                               ?fillList@TribeMPStartupScreen@@IAEXXZ                       XREF[1]:     TribeMPStartupScreen:0049f800(c)  
    //                               TribeMPStartupScreen::fillList
    //                              scr_mp.cpp:370 (37)
    //         0049fed0     PUSH       -0x1
    //         0049fed2     MOV        EAX,FS:[0x0]
    //         0049fed8     PUSH       FUN_0055f17b
    //         0049fedd     PUSH       EAX
    //         0049fede     MOV        EAX,0x27a0
    //         0049fee3     MOV        dword ptr FS:[0x0],ESP
    //         0049feea     CALL       __alloca_probe                                   undefined __alloca_probe()
    //         0049feef     PUSH       EBX
    //         0049fef0     PUSH       EBP
    //         0049fef1     MOV        EBP,this
    //         0049fef3     PUSH       ESI
    //         0049fef4     PUSH       EDI
    //                              scr_mp.cpp:376 (11)
    //         0049fef5     MOV        this,dword ptr [EBP + 0x498]
    //         0049fefb     CALL       TTextPanel::empty_list                           void empty_list(TTextPanel * this)
    //                              scr_mp.cpp:379 (12)
    //         0049ff00     LEA        this=>Serv+0x4,[ESP + 0x22c]
    //         0049ff07     CALL       TCommunications_Services::TCommunications_Serv   undefined TCommunications_Services(TCommunica
    //                              scr_mp.cpp:380 (23)
    //         0049ff0c     LEA        this=>Serv+0x4,[ESP + 0x22c]
    //         0049ff13     MOV        dword ptr [ESP + local_4],0x0
    //         0049ff1e     CALL       TCommunications_Services::GetServiceCount        int GetServiceCount(TCommunications_Services 
    //                              scr_mp.cpp:385 (32)
    //         0049ff23     MOV        this,dword ptr [Regs]                            = 00000000
    //         0049ff29     PUSH       s_Default_Age_Of_Empires_Multiplay               = "Default Age Of Empires Multiplayer Service"
    //         0049ff2e     PUSH       0x1
    //         0049ff30     MOV        EBX,EAX
    //         0049ff32     MOV        dword ptr [ESP + lastServiceName[0]],0xffffffff
    //         0049ff3a     CALL       TRegistry::RegGetAscii                           char * RegGetAscii(TRegistry * this, int para
    //         0049ff3f     TEST       EAX,EAX
    //         0049ff41     JZ         LAB_0049ff5d
    //                              scr_mp.cpp:386 (24)
    //         0049ff43     MOV        this,dword ptr [Regs]                            = 00000000
    //         0049ff49     PUSH       s_Default_Age_Of_Empires_Multiplay               = "Default Age Of Empires Multiplayer Service"
    //         0049ff4e     PUSH       0x1
    //         0049ff50     CALL       TRegistry::RegGetAscii                           char * RegGetAscii(TRegistry * this, int para
    //         0049ff55     LEA        EDX=>lastServiceName[4],[ESP + 0x14]
    //         0049ff59     MOV        EDI,EAX
    //                              scr_mp.cpp:387 (2)
    //         0049ff5b     JMP        LAB_0049ff66
    //                               LAB_0049ff5d                                                 XREF[1]:     0049ff41(j)  
    //                              scr_mp.cpp:388 (38)
    //         0049ff5d     LEA        EDX=>lastServiceName[4],[ESP + 0x14]
    //         0049ff61     MOV        EDI,s_                                           = ""
    //                               LAB_0049ff66                                                 XREF[1]:     0049ff5b(j)  
    //         0049ff66     OR         this,0xffffffff
    //         0049ff69     XOR        EAX,EAX
    //         0049ff6b     SCASB.RE   ES:EDI=>s_                                       = ""
    //         0049ff6d     NOT        this
    //         0049ff6f     SUB        EDI,this
    //         0049ff71     MOV        EAX,this
    //         0049ff73     MOV        ESI,EDI
    //         0049ff75     MOV        EDI,EDX
    //         0049ff77     SHR        this,0x2
    //         0049ff7a     MOVSD.REP  ES:EDI,ESI
    //         0049ff7c     MOV        this,EAX
    //         0049ff7e     AND        this,0x3
    //         0049ff81     MOVSB.REP  ES:EDI,ESI
    //                              scr_mp.cpp:391 (10)
    //         0049ff83     XOR        EDI,EDI
    //         0049ff85     TEST       EBX,EBX
    //         0049ff87     JLE        LAB_004a0014
    //                               LAB_0049ff8d                                                 XREF[1]:     004a000e(j)  
    //                              scr_mp.cpp:393 (34)
    //         0049ff8d     PUSH       EDI
    //         0049ff8e     LEA        this=>Serv+0x4,[ESP + 0x230]
    //         0049ff95     CALL       TCommunications_Services::GetServiceActive       int GetServiceActive(TCommunications_Services
    //         0049ff9a     TEST       EAX,EAX
    //         0049ff9c     JZ         LAB_004a000b
    //         0049ff9e     PUSH       EDI
    //         0049ff9f     LEA        this=>Serv+0x4,[ESP + 0x230]
    //         0049ffa6     CALL       TCommunications_Services::GetServiceName         char * GetServiceName(TCommunications_Service
    //         0049ffab     TEST       EAX,EAX
    //         0049ffad     JZ         LAB_004a000b
    //                              scr_mp.cpp:394 (26)
    //         0049ffaf     PUSH       EDI
    //         0049ffb0     PUSH       EDI
    //         0049ffb1     LEA        this=>Serv+0x4,[ESP + 0x234]
    //         0049ffb8     CALL       TCommunications_Services::GetServiceName         char * GetServiceName(TCommunications_Service
    //         0049ffbd     MOV        this,dword ptr [EBP + 0x498]
    //         0049ffc3     PUSH       EAX
    //         0049ffc4     CALL       TTextPanel::append_line                          int append_line(TTextPanel * this, char * par
    //                              scr_mp.cpp:396 (62)
    //         0049ffc9     PUSH       EDI
    //         0049ffca     LEA        this=>Serv+0x4,[ESP + 0x230]
    //         0049ffd1     LEA        ESI=>lastServiceName[4],[ESP + 0x18]
    //         0049ffd5     CALL       TCommunications_Services::GetServiceName         char * GetServiceName(TCommunications_Service
    //                               LAB_0049ffda                                                 XREF[1]:     0049fff8(j)  
    //         0049ffda     MOV        DL,byte ptr [EAX]
    //         0049ffdc     MOV        this,DL
    //         0049ffde     CMP        DL,byte ptr [ESI]=>lastServiceName[4]
    //         0049ffe0     JNZ        LAB_0049fffe
    //         0049ffe2     TEST       this,this
    //         0049ffe4     JZ         LAB_0049fffa
    //         0049ffe6     MOV        DL,byte ptr [EAX + 0x1]
    //         0049ffe9     MOV        this,DL
    //         0049ffeb     CMP        DL,byte ptr [ESI + lastServiceName[5]]
    //         0049ffee     JNZ        LAB_0049fffe
    //         0049fff0     ADD        EAX,0x2
    //         0049fff3     ADD        ESI,0x2
    //         0049fff6     TEST       this,this
    //         0049fff8     JNZ        LAB_0049ffda
    //                               LAB_0049fffa                                                 XREF[1]:     0049ffe4(j)  
    //         0049fffa     XOR        EAX,EAX
    //         0049fffc     JMP        LAB_004a0003
    //                               LAB_0049fffe                                                 XREF[2]:     0049ffe0(j), 0049ffee(j)  
    //         0049fffe     SBB        EAX,EAX
    //         004a0000     SBB        EAX,-0x1
    //                               LAB_004a0003                                                 XREF[1]:     0049fffc(j)  
    //         004a0003     TEST       EAX,EAX
    //         004a0005     JNZ        LAB_004a000b
    //                              scr_mp.cpp:397 (4)
    //         004a0007     MOV        dword ptr [ESP + lastServiceName[0]],EDI
    //                               LAB_004a000b                                                 XREF[3]:     0049ff9c(j), 0049ffad(j), 
    //                                                                                                         004a0005(j)  
    //                              scr_mp.cpp:391 (9)
    //         004a000b     INC        EDI
    //         004a000c     CMP        EDI,EBX
    //         004a000e     JL         LAB_0049ff8d
    //                               LAB_004a0014                                                 XREF[1]:     0049ff87(j)  
    //                              scr_mp.cpp:402 (23)
    //         004a0014     LEA        EAX=>file_info.time_create,[ESP + 0x114]
    //         004a001b     LEA        this,[EBP + 0x59f]
    //         004a0021     PUSH       EAX
    //         004a0022     PUSH       this
    //         004a0023     CALL       __findfirst                                      undefined __findfirst()
    //         004a0028     ADD        ESP,0x8
    //                              scr_mp.cpp:404 (15)
    //         004a002b     CMP        EAX,-0x1
    //         004a002e     JZ         LAB_004a004c
    //         004a0030     MOV        AL,byte ptr [EBP + 0x4a0]
    //         004a0036     TEST       AL,AL
    //         004a0038     JZ         LAB_004a004c
    //                              scr_mp.cpp:405 (18)
    //         004a003a     MOV        this,dword ptr [EBP + 0x498]
    //         004a0040     PUSH       -0x1
    //                              language.dll match for 0x258e: "Microsoft Internet Gaming Zon
    //         004a0042     PUSH       0x258e
    //         004a0047     CALL       TTextPanel::append_line                          int append_line(TTextPanel * this, long param
    //                               LAB_004a004c                                                 XREF[2]:     004a002e(j), 004a0038(j)  
    //                              scr_mp.cpp:408 (9)
    //         004a004c     MOV        EAX,dword ptr [ESP + lastServiceName[0]]
    //         004a0050     CMP        EAX,-0x1
    //         004a0053     JZ         LAB_004a006d
    //                              scr_mp.cpp:409 (31)
    //         004a0055     MOV        this,dword ptr [EBP + 0x498]
    //         004a005b     PUSH       EAX
    //         004a005c     CALL       TTextPanel::get_line                             long get_line(TTextPanel * this, long param_1)
    //         004a0061     MOV        this,dword ptr [EBP + 0x498]
    //         004a0067     PUSH       EAX
    //         004a0068     CALL       TTextPanel::set_line                             void set_line(TTextPanel * this, long param_1)
    //                               LAB_004a006d                                                 XREF[1]:     004a0053(j)  
    //         004a006d     LEA        this=>Serv+0x4,[ESP + 0x22c]
    //                              scr_mp.cpp:410 (41)
    //         004a0074     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004a007f     CALL       TCommunications_Services::~TCommunications_Ser   void ~TCommunications_Services(TCommunication
    //         004a0084     MOV        this,dword ptr [ESP + local_c]
    //         004a008b     POP        EDI
    //         004a008c     POP        ESI
    //         004a008d     POP        EBP
    //         004a008e     MOV        dword ptr FS:[0x0],this
    //         004a0095     POP        EBX
    //         004a0096     ADD        ESP,0x27ac
    //         004a009c     RET
}

// Offset: 0x004A00A0
long TribeMPStartupScreen::handle_user_command(uint param_1, long param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TribeMPStartupScreen::handle_user_command(unsigned int,long)          *
    //                              *********************************************************************************************************
    //                              long __thiscall handle_user_command(TribeMPStartupScreen * this, uin
    //              long              EAX:4          <RETURN>
    //              TribeMPStartup    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1
    //              long              Stack[0x8]:4   param_2
    //                               ?handle_user_command@TribeMPStartupScreen@@UAEJIJ@Z          XREF[1]:     00573204(*)  
    //                               TribeMPStartupScreen::handle_user_command
    //                              scr_mp.cpp:415 (5)
    //         004a00a0     MOV        EAX,0x1
    //                              scr_mp.cpp:424 (3)
    //         004a00a5     RET        0x8
}

