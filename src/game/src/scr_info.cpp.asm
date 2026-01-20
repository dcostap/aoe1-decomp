// Auto-generated scaffold unit: scr_info.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/scr_info.cpp
#include "../include/common.h"

// Offset: 0x0049D550
undefined TRIBE_Screen_Info(TRIBE_Screen_Info* this_, char* param_2, char* param_3, long param_4, ulong param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TRIBE_Screen_Info::TRIBE_Screen_Info(char *,char *,long,unsigned long)             *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TRIBE_Screen_Info(TRIBE_Screen_Info * this, cha
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TRIBE_Screen_I    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     0049d566(R)  
    //              char *            Stack[0x8]:4   param_2                   XREF[1]:     0049d587(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     0049d5ab(R)  
    //              ulong             Stack[0x10]:4  param_4                   XREF[1]:     0049d577(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0049d58d(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0049d5ca(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0049d56e(W)  
    //                               ??0TRIBE_Screen_Info@@QAE@PAD0JK@Z                           XREF[6]:     close_screen:0049d8a4(c), 
    //                               TRIBE_Screen_Info::TRIBE_Screen_Info                                      close_screen:0049d9a7(c), 
    //                                                                                                         close_screen:0049da55(c), 
    //                                                                                                         close_screen:0049db03(c), 
    //                                                                                                         close_screen:0049dc4e(c), 
    //                                                                                                         close_screen:0049dd00(c)  
    //                              scr_info.cpp:32 (39)
    //         0049d550     PUSH       -0x1
    //         0049d552     PUSH       FUN_0055ef28
    //         0049d557     MOV        EAX,FS:[0x0]
    //         0049d55d     PUSH       EAX
    //         0049d55e     MOV        dword ptr FS:[0x0],ESP
    //         0049d565     PUSH       this
    //         0049d566     MOV        EAX,dword ptr [ESP + param_1]
    //         0049d56a     PUSH       ESI
    //         0049d56b     MOV        ESI,this
    //         0049d56d     PUSH       EAX
    //         0049d56e     MOV        dword ptr [ESP + local_10],ESI
    //         0049d572     CALL       TScreenPanel::TScreenPanel                       undefined TScreenPanel(TScreenPanel * this, c
    //                              scr_info.cpp:33 (4)
    //         0049d577     MOV        EAX,dword ptr [ESP + param_4]
    //                              scr_info.cpp:34 (12)
    //         0049d57b     XOR        EDX,EDX
    //         0049d57d     XOR        this,this
    //         0049d57f     CMP        EDX,EAX
    //         0049d581     MOV        dword ptr [ESI + 0x47c],EAX
    //                              scr_info.cpp:47 (57)
    //         0049d587     MOV        EDX,dword ptr [ESP + param_2]
    //         0049d58b     SBB        EAX,EAX
    //         0049d58d     MOV        dword ptr [ESP + local_4],this
    //         0049d591     NEG        EAX
    //         0049d593     MOV        dword ptr [ESI],TRIBE_Screen_Info::`vftable'     = 0049d5e0
    //         0049d599     MOV        dword ptr [ESI + 0x478],EAX
    //         0049d59f     MOV        dword ptr [ESI + 0x480],this
    //         0049d5a5     MOV        EAX,[rge_base_game]                              = 00000000
    //         0049d5aa     PUSH       this
    //         0049d5ab     MOV        this,dword ptr [ESP + param_3]
    //         0049d5af     PUSH       this
    //         0049d5b0     MOV        this,dword ptr [EAX + 0x4c]
    //         0049d5b3     PUSH       EDX
    //         0049d5b4     PUSH       this
    //         0049d5b5     MOV        this,ESI
    //         0049d5b7     CALL       TScreenPanel::setup                              long setup(TScreenPanel * this, TDrawArea * p
    //         0049d5bc     TEST       EAX,EAX
    //         0049d5be     JNZ        LAB_0049d5ca
    //                              scr_info.cpp:49 (10)
    //         0049d5c0     MOV        dword ptr [ESI + 0xd8],0x1
    //                               LAB_0049d5ca                                                 XREF[1]:     0049d5be(j)  
    //                              scr_info.cpp:52 (20)
    //         0049d5ca     MOV        this,dword ptr [ESP + local_c]
    //         0049d5ce     MOV        EAX,ESI
    //         0049d5d0     MOV        dword ptr FS:[0x0],this
    //         0049d5d7     POP        ESI
    //         0049d5d8     ADD        ESP,0x10
    //         0049d5db     RET        0x10
}

// Offset: 0x0049D600
void TRIBE_Screen_Info(TRIBE_Screen_Info* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall TRIBE_Screen_Info::~TRIBE_Screen_Info(void)                                *
    //                              *********************************************************************************************************
    //                              void __thiscall ~TRIBE_Screen_Info(TRIBE_Screen_Info * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Screen_I    ECX:4 (auto)   this
    //                               ??1TRIBE_Screen_Info@@UAE@XZ                                 XREF[1]:     `scalar_deleting_destructor':0049d
    //                               TRIBE_Screen_Info::~TRIBE_Screen_Info
    //                              scr_info.cpp:58 (11)
    //         0049d600     MOV        dword ptr [this->_padding_],TRIBE_Screen_Info:   = 0049d5e0
    //         0049d606     JMP        TScreenPanel::~TScreenPanel                      void ~TScreenPanel(TScreenPanel * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0049D610
long TRIBE_Screen_Info::handle_idle() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TRIBE_Screen_Info::handle_idle(void)                                  *
    //                              *********************************************************************************************************
    //                              long __thiscall handle_idle(TRIBE_Screen_Info * this)
    //              long              EAX:4          <RETURN>
    //              TRIBE_Screen_I    ECX:4 (auto)   this
    //                               ?handle_idle@TRIBE_Screen_Info@@UAEJXZ                       XREF[1]:     00572d4c(*)  
    //                               TRIBE_Screen_Info::handle_idle
    //                              scr_info.cpp:65 (3)
    //         0049d610     PUSH       ESI
    //         0049d611     MOV        ESI,this
    //                              scr_info.cpp:66 (16)
    //         0049d613     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0049d619     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         0049d61f     TEST       EAX,EAX
    //         0049d621     JNZ        LAB_0049d628
    //                              scr_info.cpp:67 (5)
    //         0049d623     CALL       RGE_Base_Game::enable_input                      void enable_input(RGE_Base_Game * this)
    //                               LAB_0049d628                                                 XREF[1]:     0049d621(j)  
    //                              scr_info.cpp:69 (10)
    //         0049d628     MOV        EAX,dword ptr [ESI + 0x478]
    //         0049d62e     TEST       EAX,EAX
    //         0049d630     JZ         LAB_0049d686
    //                              scr_info.cpp:71 (10)
    //         0049d632     MOV        EAX,dword ptr [ESI + 0x480]
    //         0049d638     TEST       EAX,EAX
    //         0049d63a     JNZ        LAB_0049d65a
    //                              scr_info.cpp:72 (15)
    //         0049d63c     PUSH       0x48
    //         0049d63e     PUSH       s_C:\msdev\work\age1_x1\scr_info.c               = "C:\\msdev\\work\\age1_x1\\scr_info.cpp"
    //         0049d643     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //         0049d648     ADD        ESP,0x8
    //                              scr_info.cpp:84 (13)
    //         0049d64b     MOV        this,ESI
    //         0049d64d     MOV        dword ptr [ESI + 0x480],EAX
    //         0049d653     CALL       TPanel::handle_idle                              long handle_idle(TPanel * this)
    //                              scr_info.cpp:85 (2)
    //         0049d658     POP        ESI
    //         0049d659     RET
    //                               LAB_0049d65a                                                 XREF[1]:     0049d63a(j)  
    //                              scr_info.cpp:75 (12)
    //         0049d65a     PUSH       0x4b
    //         0049d65c     PUSH       s_C:\msdev\work\age1_x1\scr_info.c               = "C:\\msdev\\work\\age1_x1\\scr_info.cpp"
    //         0049d661     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //                              scr_info.cpp:76 (21)
    //         0049d666     MOV        EDX,dword ptr [ESI + 0x480]
    //         0049d66c     MOV        this,dword ptr [ESI + 0x47c]
    //         0049d672     SUB        EAX,EDX
    //         0049d674     ADD        ESP,0x8
    //         0049d677     CMP        EAX,this
    //         0049d679     JBE        LAB_0049d686
    //                              scr_info.cpp:78 (7)
    //         0049d67b     MOV        this,ESI
    //         0049d67d     CALL       TRIBE_Screen_Info::close_screen                  void close_screen(TRIBE_Screen_Info * this)
    //                              scr_info.cpp:79 (2)
    //         0049d682     XOR        EAX,EAX
    //                              scr_info.cpp:85 (2)
    //         0049d684     POP        ESI
    //         0049d685     RET
    //                               LAB_0049d686                                                 XREF[2]:     0049d630(j), 0049d679(j)  
    //                              scr_info.cpp:84 (7)
    //         0049d686     MOV        this,ESI
    //         0049d688     CALL       TPanel::handle_idle                              long handle_idle(TPanel * this)
    //                              scr_info.cpp:85 (2)
    //         0049d68d     POP        ESI
    //         0049d68e     RET
}

// Offset: 0x0049D690
long TRIBE_Screen_Info::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TRIBE_Screen_Info::key_down_action(long,short,int,int,int)            *
    //                              *********************************************************************************************************
    //                              long __thiscall key_down_action(TRIBE_Screen_Info * this, long param
    //              long              EAX:4          <RETURN>
    //              TRIBE_Screen_I    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     0049d690(R)  
    //              short             Stack[0x8]:2   param_2
    //              int               Stack[0xc]:4   param_3
    //              int               Stack[0x10]:4  param_4
    //              int               Stack[0x14]:4  param_5
    //                               ?key_down_action@TRIBE_Screen_Info@@UAEJJFHHH@Z              XREF[1]:     00572dac(*)  
    //                               TRIBE_Screen_Info::key_down_action
    //                              scr_info.cpp:91 (19)
    //         0049d690     MOV        EAX,dword ptr [ESP + param_1]
    //         0049d694     CMP        EAX,0x12
    //         0049d697     JZ         LAB_0049d6a8
    //         0049d699     CMP        EAX,0x11
    //         0049d69c     JZ         LAB_0049d6a8
    //         0049d69e     CMP        EAX,0x10
    //         0049d6a1     JZ         LAB_0049d6a8
    //                              scr_info.cpp:93 (5)
    //         0049d6a3     CALL       TRIBE_Screen_Info::close_screen                  void close_screen(TRIBE_Screen_Info * this)
    //                               LAB_0049d6a8                                                 XREF[3]:     0049d697(j), 0049d69c(j), 
    //                                                                                                         0049d6a1(j)  
    //                              scr_info.cpp:94 (2)
    //         0049d6a8     XOR        EAX,EAX
    //                              scr_info.cpp:95 (3)
    //         0049d6aa     RET        0x14
}

// Offset: 0x0049D6B0
long TRIBE_Screen_Info::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TRIBE_Screen_Info::mouse_left_down_action(long,long,int,int)          *
    //                              *********************************************************************************************************
    //                              long __thiscall mouse_left_down_action(TRIBE_Screen_Info * this, lon
    //              long              EAX:4          <RETURN>
    //              TRIBE_Screen_I    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1
    //              long              Stack[0x8]:4   param_2
    //              int               Stack[0xc]:4   param_3
    //              int               Stack[0x10]:4  param_4
    //                               ?mouse_left_down_action@TRIBE_Screen_Info@@UAEJJJHH@Z        XREF[1]:     00572d84(*)  
    //                               TRIBE_Screen_Info::mouse_left_down_action
    //                              scr_info.cpp:101 (5)
    //         0049d6b0     CALL       TRIBE_Screen_Info::close_screen                  void close_screen(TRIBE_Screen_Info * this)
    //                              scr_info.cpp:103 (2)
    //         0049d6b5     XOR        EAX,EAX
    //                              scr_info.cpp:104 (3)
    //         0049d6b7     RET        0x10
}

// Offset: 0x0049D6C0
long TRIBE_Screen_Info::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TRIBE_Screen_Info::action(class TPanel *,long,unsigned long,unsign... *
    //                              *********************************************************************************************************
    //                              long __thiscall action(TRIBE_Screen_Info * this, TPanel * param_1, l
    //              long              EAX:4          <RETURN>
    //              TRIBE_Screen_I    ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     0049d6ce(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     0049d6c9(R)  
    //              ulong             Stack[0xc]:4   param_3                   XREF[1]:     0049d6c4(R)  
    //              ulong             Stack[0x10]:4  param_4                   XREF[1]:     0049d6c0(R)  
    //                               ?action@TRIBE_Screen_Info@@UAEJPAVTPanel@@JKK@Z              XREF[1]:     00572db4(*)  
    //                               TRIBE_Screen_Info::action
    //                              scr_info.cpp:110 (25)
    //         0049d6c0     MOV        EAX,dword ptr [ESP + param_4]
    //         0049d6c4     MOV        EDX,dword ptr [ESP + param_3]
    //         0049d6c8     PUSH       EAX
    //         0049d6c9     MOV        EAX,dword ptr [ESP + param_2]
    //         0049d6cd     PUSH       EDX
    //         0049d6ce     MOV        EDX,dword ptr [ESP + param_1]
    //         0049d6d2     PUSH       EAX
    //         0049d6d3     PUSH       EDX
    //         0049d6d4     CALL       TEasy_Panel::action                              long action(TEasy_Panel * this, TPanel * para
    //                              scr_info.cpp:112 (3)
    //         0049d6d9     RET        0x10
}

// Offset: 0x0049D6E0
void close_screen(TRIBE_Screen_Info* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TRIBE_Screen_Info::close_screen(void)                                         *
    //                              *********************************************************************************************************
    //                              void __thiscall close_screen(TRIBE_Screen_Info * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Screen_I    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[18]:    0049d755(W), 0049d772(W), 0049d7f2(W), 0049d80f(W), 
    //                                                                                     0049d884(W), 0049d8b5(W), 0049d98a(W), 0049d9b8(W), 
    //                                                                                     0049da38(W), 0049da66(W), 0049dae6(W), 0049db14(W), 
    //                                                                                     0049db94(W), 0049dbb1(W), 0049dc31(W), 0049dc5f(W), 
    //                                                                                     0049dce3(W), 0049dd11(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[10]:    0049d78a(R), 0049d827(R), 0049d8be(R), 0049d922(R), 
    //                                                                                     0049d9d0(R), 0049da7e(R), 0049db2c(R), 0049dbc9(R), 
    //                                                                                     0049dc77(R), 0049dd29(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[9]:     0049d74f(W), 0049d7ec(W), 0049d87e(W), 0049d984(W), 
    //                                                                                     0049da32(W), 0049dae0(W), 0049db8e(W), 0049dc2b(W), 
    //                                                                                     0049dcdd(W)  
    //                               ?close_screen@TRIBE_Screen_Info@@QAEXXZ                      XREF[3]:     handle_idle:0049d67d(c), 
    //                               TRIBE_Screen_Info::close_screen                                           key_down_action:0049d6a3(c), 
    //                                                                                                         mouse_left_down_action:0049d6b0(c)
    //                              scr_info.cpp:118 (26)
    //         0049d6e0     PUSH       -0x1
    //         0049d6e2     PUSH       FUN_0055efa3
    //         0049d6e7     MOV        EAX,FS:[0x0]
    //         0049d6ed     PUSH       EAX
    //         0049d6ee     MOV        dword ptr FS:[0x0],ESP
    //         0049d6f5     PUSH       this
    //         0049d6f6     PUSH       EBX
    //         0049d6f7     PUSH       EBP
    //         0049d6f8     PUSH       ESI
    //         0049d6f9     PUSH       EDI
    //                              scr_info.cpp:119 (61)
    //         0049d6fa     MOV        EDI,dword ptr [ECX + this->_padding_]
    //         0049d6fd     MOV        ESI,s_RandomMap                                  = 52h
    //         0049d702     MOV        EAX,EDI
    //                               LAB_0049d704                                                 XREF[1]:     0049d729(j)  
    //         0049d704     MOV        DL,byte ptr [EAX]
    //         0049d706     MOV        BL,byte ptr [ESI]=>s_RandomMap                   = 52h
    //                                                                                  = 6Eh
    //         0049d708     MOV        this,DL
    //         0049d70a     OR         EBP,0xffffffff
    //         0049d70d     CMP        DL,BL
    //         0049d70f     JNZ        LAB_0049d72f
    //         0049d711     TEST       this,this
    //         0049d713     JZ         LAB_0049d72b
    //         0049d715     MOV        DL,byte ptr [EAX + 0x1]
    //         0049d718     MOV        BL,byte ptr [ESI + 0x1]=>DAT_0058664d            = 61h
    //                                                                                  = "domMap"
    //         0049d71b     MOV        this,DL
    //         0049d71d     CMP        DL,BL
    //         0049d71f     JNZ        LAB_0049d72f
    //         0049d721     ADD        EAX,0x2
    //         0049d724     ADD        ESI,0x2
    //         0049d727     TEST       this,this
    //         0049d729     JNZ        LAB_0049d704
    //                               LAB_0049d72b                                                 XREF[1]:     0049d713(j)  
    //         0049d72b     XOR        EAX,EAX
    //         0049d72d     JMP        LAB_0049d733
    //                               LAB_0049d72f                                                 XREF[2]:     0049d70f(j), 0049d71f(j)  
    //         0049d72f     SBB        EAX,EAX
    //         0049d731     SBB        EAX,EBP
    //                               LAB_0049d733                                                 XREF[1]:     0049d72d(j)  
    //         0049d733     TEST       EAX,EAX
    //         0049d735     JNZ        LAB_0049d79d
    //                              scr_info.cpp:121 (11)
    //         0049d737     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0049d73d     CALL       RGE_Base_Game::disable_input                     void disable_input(RGE_Base_Game * this)
    //                              scr_info.cpp:122 (36)
    //         0049d742     PUSH       0x49c
    //         0049d747     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0049d74c     ADD        ESP,0x4
    //         0049d74f     MOV        dword ptr [ESP + local_10],EAX
    //         0049d753     TEST       EAX,EAX
    //         0049d755     MOV        dword ptr [ESP + local_4],0x0
    //         0049d75d     JZ         LAB_0049d766
    //         0049d75f     MOV        this,EAX
    //         0049d761     CALL       TribeSPMenuScreen::TribeSPMenuScreen             undefined TribeSPMenuScreen(TribeSPMenuScreen
    //                               LAB_0049d766                                                 XREF[1]:     0049d75d(j)  
    //                              scr_info.cpp:123 (21)
    //         0049d766     PUSH       0x0
    //         0049d768     PUSH       s_Single_Player_Menu                             = "Single Player Menu"
    //         0049d76d     MOV        this,panel_system
    //         0049d772     MOV        dword ptr [ESP + local_4],EBP
    //         0049d776     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              scr_info.cpp:124 (15)
    //         0049d77b     PUSH       s_RandomMap                                      = 52h
    //         0049d780     MOV        this,panel_system
    //         0049d785     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_info.cpp:189 (19)
    //         0049d78a     MOV        this,dword ptr [ESP + local_c]
    //         0049d78e     MOV        dword ptr FS:[0x0],this
    //         0049d795     POP        EDI
    //         0049d796     POP        ESI
    //         0049d797     POP        EBP
    //         0049d798     POP        EBX
    //         0049d799     ADD        ESP,0x10
    //         0049d79c     RET
    //                               LAB_0049d79d                                                 XREF[1]:     0049d735(j)  
    //                              scr_info.cpp:126 (55)
    //         0049d79d     MOV        ESI,s_DeathMatch                                 = 44h
    //         0049d7a2     MOV        EAX,EDI
    //                               LAB_0049d7a4                                                 XREF[1]:     0049d7c6(j)  
    //         0049d7a4     MOV        DL,byte ptr [EAX]
    //         0049d7a6     MOV        BL,byte ptr [ESI]=>s_DeathMatch                  = 44h
    //                                                                                  = 61h
    //         0049d7a8     MOV        this,DL
    //         0049d7aa     CMP        DL,BL
    //         0049d7ac     JNZ        LAB_0049d7cc
    //         0049d7ae     TEST       this,this
    //         0049d7b0     JZ         LAB_0049d7c8
    //         0049d7b2     MOV        DL,byte ptr [EAX + 0x1]
    //         0049d7b5     MOV        BL,byte ptr [ESI + 0x1]=>DAT_0058662d            = 65h
    //                                                                                  = "thMatch"
    //         0049d7b8     MOV        this,DL
    //         0049d7ba     CMP        DL,BL
    //         0049d7bc     JNZ        LAB_0049d7cc
    //         0049d7be     ADD        EAX,0x2
    //         0049d7c1     ADD        ESI,0x2
    //         0049d7c4     TEST       this,this
    //         0049d7c6     JNZ        LAB_0049d7a4
    //                               LAB_0049d7c8                                                 XREF[1]:     0049d7b0(j)  
    //         0049d7c8     XOR        EAX,EAX
    //         0049d7ca     JMP        LAB_0049d7d0
    //                               LAB_0049d7cc                                                 XREF[2]:     0049d7ac(j), 0049d7bc(j)  
    //         0049d7cc     SBB        EAX,EAX
    //         0049d7ce     SBB        EAX,EBP
    //                               LAB_0049d7d0                                                 XREF[1]:     0049d7ca(j)  
    //         0049d7d0     TEST       EAX,EAX
    //         0049d7d2     JNZ        LAB_0049d83a
    //                              scr_info.cpp:128 (11)
    //         0049d7d4     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0049d7da     CALL       RGE_Base_Game::disable_input                     void disable_input(RGE_Base_Game * this)
    //                              scr_info.cpp:129 (36)
    //         0049d7df     PUSH       0x49c
    //         0049d7e4     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0049d7e9     ADD        ESP,0x4
    //         0049d7ec     MOV        dword ptr [ESP + local_10],EAX
    //         0049d7f0     TEST       EAX,EAX
    //         0049d7f2     MOV        dword ptr [ESP + local_4],0x1
    //         0049d7fa     JZ         LAB_0049d803
    //         0049d7fc     MOV        this,EAX
    //         0049d7fe     CALL       TribeSPMenuScreen::TribeSPMenuScreen             undefined TribeSPMenuScreen(TribeSPMenuScreen
    //                               LAB_0049d803                                                 XREF[1]:     0049d7fa(j)  
    //                              scr_info.cpp:130 (21)
    //         0049d803     PUSH       0x0
    //         0049d805     PUSH       s_Single_Player_Menu                             = "Single Player Menu"
    //         0049d80a     MOV        this,panel_system
    //         0049d80f     MOV        dword ptr [ESP + local_4],EBP
    //         0049d813     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              scr_info.cpp:131 (15)
    //         0049d818     PUSH       s_DeathMatch                                     = 44h
    //         0049d81d     MOV        this,panel_system
    //         0049d822     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_info.cpp:189 (19)
    //         0049d827     MOV        this,dword ptr [ESP + local_c]
    //         0049d82b     MOV        dword ptr FS:[0x0],this
    //         0049d832     POP        EDI
    //         0049d833     POP        ESI
    //         0049d834     POP        EBP
    //         0049d835     POP        EBX
    //         0049d836     ADD        ESP,0x10
    //         0049d839     RET
    //                               LAB_0049d83a                                                 XREF[1]:     0049d7d2(j)  
    //                              scr_info.cpp:133 (55)
    //         0049d83a     MOV        ESI,s_Logo1Screen                                = 4Ch
    //         0049d83f     MOV        EAX,EDI
    //                               LAB_0049d841                                                 XREF[1]:     0049d863(j)  
    //         0049d841     MOV        DL,byte ptr [EAX]
    //         0049d843     MOV        BL,byte ptr [ESI]=>s_Logo1Screen                 = 4Ch
    //                                                                                  = 67h
    //         0049d845     MOV        this,DL
    //         0049d847     CMP        DL,BL
    //         0049d849     JNZ        LAB_0049d869
    //         0049d84b     TEST       this,this
    //         0049d84d     JZ         LAB_0049d865
    //         0049d84f     MOV        DL,byte ptr [EAX + 0x1]
    //         0049d852     MOV        BL,byte ptr [ESI + 0x1]=>DAT_00586621            = 6Fh
    //                                                                                  = "o1Screen"
    //         0049d855     MOV        this,DL
    //         0049d857     CMP        DL,BL
    //         0049d859     JNZ        LAB_0049d869
    //         0049d85b     ADD        EAX,0x2
    //         0049d85e     ADD        ESI,0x2
    //         0049d861     TEST       this,this
    //         0049d863     JNZ        LAB_0049d841
    //                               LAB_0049d865                                                 XREF[1]:     0049d84d(j)  
    //         0049d865     XOR        EAX,EAX
    //         0049d867     JMP        LAB_0049d86d
    //                               LAB_0049d869                                                 XREF[2]:     0049d849(j), 0049d859(j)  
    //         0049d869     SBB        EAX,EAX
    //         0049d86b     SBB        EAX,EBP
    //                               LAB_0049d86d                                                 XREF[1]:     0049d867(j)  
    //         0049d86d     TEST       EAX,EAX
    //         0049d86f     JNZ        LAB_0049d8d1
    //                              scr_info.cpp:136 (56)
    //         0049d871     PUSH       0x484
    //         0049d876     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0049d87b     ADD        ESP,0x4
    //         0049d87e     MOV        dword ptr [ESP + local_10],EAX
    //         0049d882     TEST       EAX,EAX
    //         0049d884     MOV        dword ptr [ESP + local_4],0x2
    //         0049d88c     JZ         LAB_0049d8a9
    //                              language.dll match for 0x7d0: "place holder"
    //         0049d88e     PUSH       0x7d0
    //         0049d893     PUSH       0xc392
    //         0049d898     PUSH       s_scrlogo2                                       = "scrlogo2"
    //         0049d89d     PUSH       s_Logo2Screen                                    = 4Ch
    //         0049d8a2     MOV        this,EAX
    //         0049d8a4     CALL       TRIBE_Screen_Info::TRIBE_Screen_Info             undefined TRIBE_Screen_Info(TRIBE_Screen_Info
    //                               LAB_0049d8a9                                                 XREF[1]:     0049d88c(j)  
    //                              scr_info.cpp:137 (21)
    //         0049d8a9     PUSH       0x0
    //         0049d8ab     PUSH       s_Logo2Screen                                    = 4Ch
    //         0049d8b0     MOV        this,panel_system
    //         0049d8b5     MOV        dword ptr [ESP + local_4],EBP
    //         0049d8b9     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              scr_info.cpp:189 (19)
    //         0049d8be     MOV        this,dword ptr [ESP + local_c]
    //         0049d8c2     MOV        dword ptr FS:[0x0],this
    //         0049d8c9     POP        EDI
    //         0049d8ca     POP        ESI
    //         0049d8cb     POP        EBP
    //         0049d8cc     POP        EBX
    //         0049d8cd     ADD        ESP,0x10
    //         0049d8d0     RET
    //                               LAB_0049d8d1                                                 XREF[1]:     0049d86f(j)  
    //                              scr_info.cpp:139 (55)
    //         0049d8d1     MOV        ESI,s_Logo2Screen                                = 4Ch
    //         0049d8d6     MOV        EAX,EDI
    //                               LAB_0049d8d8                                                 XREF[1]:     0049d8fa(j)  
    //         0049d8d8     MOV        DL,byte ptr [EAX]
    //         0049d8da     MOV        BL,byte ptr [ESI]=>s_Logo2Screen                 = 4Ch
    //                                                                                  = 67h
    //         0049d8dc     MOV        this,DL
    //         0049d8de     CMP        DL,BL
    //         0049d8e0     JNZ        LAB_0049d900
    //         0049d8e2     TEST       this,this
    //         0049d8e4     JZ         LAB_0049d8fc
    //         0049d8e6     MOV        DL,byte ptr [EAX + 0x1]
    //         0049d8e9     MOV        BL,byte ptr [ESI + 0x1]=>DAT_00586609            = 6Fh
    //                                                                                  = "o2Screen"
    //         0049d8ec     MOV        this,DL
    //         0049d8ee     CMP        DL,BL
    //         0049d8f0     JNZ        LAB_0049d900
    //         0049d8f2     ADD        EAX,0x2
    //         0049d8f5     ADD        ESI,0x2
    //         0049d8f8     TEST       this,this
    //         0049d8fa     JNZ        LAB_0049d8d8
    //                               LAB_0049d8fc                                                 XREF[1]:     0049d8e4(j)  
    //         0049d8fc     XOR        EAX,EAX
    //         0049d8fe     JMP        LAB_0049d904
    //                               LAB_0049d900                                                 XREF[2]:     0049d8e0(j), 0049d8f0(j)  
    //         0049d900     SBB        EAX,EAX
    //         0049d902     SBB        EAX,EBP
    //                               LAB_0049d904                                                 XREF[1]:     0049d8fe(j)  
    //         0049d904     TEST       EAX,EAX
    //         0049d906     JNZ        LAB_0049d935
    //                              scr_info.cpp:142 (15)
    //         0049d908     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0049d90e     CALL       TRIBE_Game::start_menu                           int start_menu(TRIBE_Game * this)
    //         0049d913     TEST       EAX,EAX
    //         0049d915     JNZ        LAB_0049d922
    //                               LAB_0049d917                                                 XREF[1]:     0049dcbf(j)  
    //                              scr_info.cpp:188 (11)
    //         0049d917     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0049d91d     CALL       RGE_Base_Game::close                             void close(RGE_Base_Game * this)
    //                               LAB_0049d922                                                 XREF[1]:     0049d915(j)  
    //                              scr_info.cpp:189 (19)
    //         0049d922     MOV        this,dword ptr [ESP + local_c]
    //         0049d926     MOV        dword ptr FS:[0x0],this
    //         0049d92d     POP        EDI
    //         0049d92e     POP        ESI
    //         0049d92f     POP        EBP
    //         0049d930     POP        EBX
    //         0049d931     ADD        ESP,0x10
    //         0049d934     RET
    //                               LAB_0049d935                                                 XREF[1]:     0049d906(j)  
    //                              scr_info.cpp:145 (55)
    //         0049d935     MOV        ESI,s_ScenarioEditorInfo                         = 53h
    //         0049d93a     MOV        EAX,EDI
    //                               LAB_0049d93c                                                 XREF[1]:     0049d95e(j)  
    //         0049d93c     MOV        DL,byte ptr [EAX]
    //         0049d93e     MOV        BL,byte ptr [ESI]=>s_ScenarioEditorInfo          = 53h
    //                                                                                  = 65h
    //         0049d940     MOV        this,DL
    //         0049d942     CMP        DL,BL
    //         0049d944     JNZ        LAB_0049d964
    //         0049d946     TEST       this,this
    //         0049d948     JZ         LAB_0049d960
    //         0049d94a     MOV        DL,byte ptr [EAX + 0x1]
    //         0049d94d     MOV        BL,byte ptr [ESI + 0x1]=>DAT_005865f5            = 63h
    //                                                                                  = "narioEditorInfo"
    //         0049d950     MOV        this,DL
    //         0049d952     CMP        DL,BL
    //         0049d954     JNZ        LAB_0049d964
    //         0049d956     ADD        EAX,0x2
    //         0049d959     ADD        ESI,0x2
    //         0049d95c     TEST       this,this
    //         0049d95e     JNZ        LAB_0049d93c
    //                               LAB_0049d960                                                 XREF[1]:     0049d948(j)  
    //         0049d960     XOR        EAX,EAX
    //         0049d962     JMP        LAB_0049d968
    //                               LAB_0049d964                                                 XREF[2]:     0049d944(j), 0049d954(j)  
    //         0049d964     SBB        EAX,EAX
    //         0049d966     SBB        EAX,EBP
    //                               LAB_0049d968                                                 XREF[1]:     0049d962(j)  
    //         0049d968     TEST       EAX,EAX
    //         0049d96a     JNZ        LAB_0049d9e3
    //                              scr_info.cpp:147 (11)
    //         0049d96c     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0049d972     CALL       RGE_Base_Game::disable_input                     void disable_input(RGE_Base_Game * this)
    //                              scr_info.cpp:148 (53)
    //         0049d977     PUSH       0x484
    //         0049d97c     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0049d981     ADD        ESP,0x4
    //         0049d984     MOV        dword ptr [ESP + local_10],EAX
    //         0049d988     TEST       EAX,EAX
    //         0049d98a     MOV        dword ptr [ESP + local_4],0x3
    //         0049d992     JZ         LAB_0049d9ac
    //         0049d994     PUSH       0x0
    //         0049d996     PUSH       0xc394
    //         0049d99b     PUSH       s_scrunit1                                       = "scrunit1"
    //         0049d9a0     PUSH       s_UnitInfo1                                      = 55h
    //         0049d9a5     MOV        this,EAX
    //         0049d9a7     CALL       TRIBE_Screen_Info::TRIBE_Screen_Info             undefined TRIBE_Screen_Info(TRIBE_Screen_Info
    //                               LAB_0049d9ac                                                 XREF[1]:     0049d992(j)  
    //                              scr_info.cpp:149 (21)
    //         0049d9ac     PUSH       0x0
    //         0049d9ae     PUSH       s_UnitInfo1                                      = 55h
    //         0049d9b3     MOV        this,panel_system
    //         0049d9b8     MOV        dword ptr [ESP + local_4],EBP
    //         0049d9bc     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              scr_info.cpp:150 (15)
    //         0049d9c1     PUSH       s_ScenarioEditorInfo                             = 53h
    //         0049d9c6     MOV        this,panel_system
    //         0049d9cb     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_info.cpp:189 (19)
    //         0049d9d0     MOV        this,dword ptr [ESP + local_c]
    //         0049d9d4     MOV        dword ptr FS:[0x0],this
    //         0049d9db     POP        EDI
    //         0049d9dc     POP        ESI
    //         0049d9dd     POP        EBP
    //         0049d9de     POP        EBX
    //         0049d9df     ADD        ESP,0x10
    //         0049d9e2     RET
    //                               LAB_0049d9e3                                                 XREF[1]:     0049d96a(j)  
    //                              scr_info.cpp:152 (55)
    //         0049d9e3     MOV        ESI,s_UnitInfo1                                  = 55h
    //         0049d9e8     MOV        EAX,EDI
    //                               LAB_0049d9ea                                                 XREF[1]:     0049da0c(j)  
    //         0049d9ea     MOV        DL,byte ptr [EAX]
    //         0049d9ec     MOV        BL,byte ptr [ESI]=>s_UnitInfo1                   = 55h
    //                                                                                  = 69h
    //         0049d9ee     MOV        this,DL
    //         0049d9f0     CMP        DL,BL
    //         0049d9f2     JNZ        LAB_0049da12
    //         0049d9f4     TEST       this,this
    //         0049d9f6     JZ         LAB_0049da0e
    //         0049d9f8     MOV        DL,byte ptr [EAX + 0x1]
    //         0049d9fb     MOV        BL,byte ptr [ESI + 0x1]=>DAT_005865dd            = 6Eh
    //                                                                                  = "tInfo1"
    //         0049d9fe     MOV        this,DL
    //         0049da00     CMP        DL,BL
    //         0049da02     JNZ        LAB_0049da12
    //         0049da04     ADD        EAX,0x2
    //         0049da07     ADD        ESI,0x2
    //         0049da0a     TEST       this,this
    //         0049da0c     JNZ        LAB_0049d9ea
    //                               LAB_0049da0e                                                 XREF[1]:     0049d9f6(j)  
    //         0049da0e     XOR        EAX,EAX
    //         0049da10     JMP        LAB_0049da16
    //                               LAB_0049da12                                                 XREF[2]:     0049d9f2(j), 0049da02(j)  
    //         0049da12     SBB        EAX,EAX
    //         0049da14     SBB        EAX,EBP
    //                               LAB_0049da16                                                 XREF[1]:     0049da10(j)  
    //         0049da16     TEST       EAX,EAX
    //         0049da18     JNZ        LAB_0049da91
    //                              scr_info.cpp:154 (11)
    //         0049da1a     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0049da20     CALL       RGE_Base_Game::disable_input                     void disable_input(RGE_Base_Game * this)
    //                              scr_info.cpp:155 (53)
    //         0049da25     PUSH       0x484
    //         0049da2a     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0049da2f     ADD        ESP,0x4
    //         0049da32     MOV        dword ptr [ESP + local_10],EAX
    //         0049da36     TEST       EAX,EAX
    //         0049da38     MOV        dword ptr [ESP + local_4],0x4
    //         0049da40     JZ         LAB_0049da5a
    //         0049da42     PUSH       0x0
    //         0049da44     PUSH       0xc395
    //         0049da49     PUSH       s_scrunit2                                       = "scrunit2"
    //         0049da4e     PUSH       s_UnitInfo2                                      = 55h
    //         0049da53     MOV        this,EAX
    //         0049da55     CALL       TRIBE_Screen_Info::TRIBE_Screen_Info             undefined TRIBE_Screen_Info(TRIBE_Screen_Info
    //                               LAB_0049da5a                                                 XREF[1]:     0049da40(j)  
    //                              scr_info.cpp:156 (21)
    //         0049da5a     PUSH       0x0
    //         0049da5c     PUSH       s_UnitInfo2                                      = 55h
    //         0049da61     MOV        this,panel_system
    //         0049da66     MOV        dword ptr [ESP + local_4],EBP
    //         0049da6a     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              scr_info.cpp:157 (15)
    //         0049da6f     PUSH       s_UnitInfo1                                      = 55h
    //         0049da74     MOV        this,panel_system
    //         0049da79     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_info.cpp:189 (19)
    //         0049da7e     MOV        this,dword ptr [ESP + local_c]
    //         0049da82     MOV        dword ptr FS:[0x0],this
    //         0049da89     POP        EDI
    //         0049da8a     POP        ESI
    //         0049da8b     POP        EBP
    //         0049da8c     POP        EBX
    //         0049da8d     ADD        ESP,0x10
    //         0049da90     RET
    //                               LAB_0049da91                                                 XREF[1]:     0049da18(j)  
    //                              scr_info.cpp:159 (55)
    //         0049da91     MOV        ESI,s_UnitInfo2                                  = 55h
    //         0049da96     MOV        EAX,EDI
    //                               LAB_0049da98                                                 XREF[1]:     0049daba(j)  
    //         0049da98     MOV        DL,byte ptr [EAX]
    //         0049da9a     MOV        BL,byte ptr [ESI]=>s_UnitInfo2                   = 55h
    //                                                                                  = 69h
    //         0049da9c     MOV        this,DL
    //         0049da9e     CMP        DL,BL
    //         0049daa0     JNZ        LAB_0049dac0
    //         0049daa2     TEST       this,this
    //         0049daa4     JZ         LAB_0049dabc
    //         0049daa6     MOV        DL,byte ptr [EAX + 0x1]
    //         0049daa9     MOV        BL,byte ptr [ESI + 0x1]=>DAT_005865c5            = 6Eh
    //                                                                                  = "tInfo2"
    //         0049daac     MOV        this,DL
    //         0049daae     CMP        DL,BL
    //         0049dab0     JNZ        LAB_0049dac0
    //         0049dab2     ADD        EAX,0x2
    //         0049dab5     ADD        ESI,0x2
    //         0049dab8     TEST       this,this
    //         0049daba     JNZ        LAB_0049da98
    //                               LAB_0049dabc                                                 XREF[1]:     0049daa4(j)  
    //         0049dabc     XOR        EAX,EAX
    //         0049dabe     JMP        LAB_0049dac4
    //                               LAB_0049dac0                                                 XREF[2]:     0049daa0(j), 0049dab0(j)  
    //         0049dac0     SBB        EAX,EAX
    //         0049dac2     SBB        EAX,EBP
    //                               LAB_0049dac4                                                 XREF[1]:     0049dabe(j)  
    //         0049dac4     TEST       EAX,EAX
    //         0049dac6     JNZ        LAB_0049db3f
    //                              scr_info.cpp:161 (11)
    //         0049dac8     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0049dace     CALL       RGE_Base_Game::disable_input                     void disable_input(RGE_Base_Game * this)
    //                              scr_info.cpp:162 (53)
    //         0049dad3     PUSH       0x484
    //         0049dad8     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0049dadd     ADD        ESP,0x4
    //         0049dae0     MOV        dword ptr [ESP + local_10],EAX
    //         0049dae4     TEST       EAX,EAX
    //         0049dae6     MOV        dword ptr [ESP + local_4],0x5
    //         0049daee     JZ         LAB_0049db08
    //         0049daf0     PUSH       0x0
    //         0049daf2     PUSH       0xc396
    //         0049daf7     PUSH       s_scrunit3                                       = "scrunit3"
    //         0049dafc     PUSH       s_UnitInfo3                                      = 55h
    //         0049db01     MOV        this,EAX
    //         0049db03     CALL       TRIBE_Screen_Info::TRIBE_Screen_Info             undefined TRIBE_Screen_Info(TRIBE_Screen_Info
    //                               LAB_0049db08                                                 XREF[1]:     0049daee(j)  
    //                              scr_info.cpp:163 (21)
    //         0049db08     PUSH       0x0
    //         0049db0a     PUSH       s_UnitInfo3                                      = 55h
    //         0049db0f     MOV        this,panel_system
    //         0049db14     MOV        dword ptr [ESP + local_4],EBP
    //         0049db18     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              scr_info.cpp:164 (15)
    //         0049db1d     PUSH       s_UnitInfo2                                      = 55h
    //         0049db22     MOV        this,panel_system
    //         0049db27     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_info.cpp:189 (19)
    //         0049db2c     MOV        this,dword ptr [ESP + local_c]
    //         0049db30     MOV        dword ptr FS:[0x0],this
    //         0049db37     POP        EDI
    //         0049db38     POP        ESI
    //         0049db39     POP        EBP
    //         0049db3a     POP        EBX
    //         0049db3b     ADD        ESP,0x10
    //         0049db3e     RET
    //                               LAB_0049db3f                                                 XREF[1]:     0049dac6(j)  
    //                              scr_info.cpp:166 (55)
    //         0049db3f     MOV        ESI,s_UnitInfo3                                  = 55h
    //         0049db44     MOV        EAX,EDI
    //                               LAB_0049db46                                                 XREF[1]:     0049db68(j)  
    //         0049db46     MOV        DL,byte ptr [EAX]
    //         0049db48     MOV        BL,byte ptr [ESI]=>s_UnitInfo3                   = 55h
    //                                                                                  = 69h
    //         0049db4a     MOV        this,DL
    //         0049db4c     CMP        DL,BL
    //         0049db4e     JNZ        LAB_0049db6e
    //         0049db50     TEST       this,this
    //         0049db52     JZ         LAB_0049db6a
    //         0049db54     MOV        DL,byte ptr [EAX + 0x1]
    //         0049db57     MOV        BL,byte ptr [ESI + 0x1]=>DAT_005865ad            = 6Eh
    //                                                                                  = "tInfo3"
    //         0049db5a     MOV        this,DL
    //         0049db5c     CMP        DL,BL
    //         0049db5e     JNZ        LAB_0049db6e
    //         0049db60     ADD        EAX,0x2
    //         0049db63     ADD        ESI,0x2
    //         0049db66     TEST       this,this
    //         0049db68     JNZ        LAB_0049db46
    //                               LAB_0049db6a                                                 XREF[1]:     0049db52(j)  
    //         0049db6a     XOR        EAX,EAX
    //         0049db6c     JMP        LAB_0049db72
    //                               LAB_0049db6e                                                 XREF[2]:     0049db4e(j), 0049db5e(j)  
    //         0049db6e     SBB        EAX,EAX
    //         0049db70     SBB        EAX,EBP
    //                               LAB_0049db72                                                 XREF[1]:     0049db6c(j)  
    //         0049db72     TEST       EAX,EAX
    //         0049db74     JNZ        LAB_0049dbdc
    //                              scr_info.cpp:168 (11)
    //         0049db76     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0049db7c     CALL       RGE_Base_Game::disable_input                     void disable_input(RGE_Base_Game * this)
    //                              language.dll match for 0x4b0: "Ready"
    //                              scr_info.cpp:169 (36)
    //         0049db81     PUSH       0x4b0
    //         0049db86     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0049db8b     ADD        ESP,0x4
    //         0049db8e     MOV        dword ptr [ESP + local_10],EAX
    //         0049db92     TEST       EAX,EAX
    //         0049db94     MOV        dword ptr [ESP + local_4],0x6
    //         0049db9c     JZ         LAB_0049dba5
    //         0049db9e     MOV        this,EAX
    //         0049dba0     CALL       TRIBE_Screen_Main_Menu::TRIBE_Screen_Main_Menu   undefined TRIBE_Screen_Main_Menu(TRIBE_Screen
    //                               LAB_0049dba5                                                 XREF[1]:     0049db9c(j)  
    //                              scr_info.cpp:170 (21)
    //         0049dba5     PUSH       0x0
    //         0049dba7     PUSH       s_Main_Menu                                      = "Main Menu"
    //         0049dbac     MOV        this,panel_system
    //         0049dbb1     MOV        dword ptr [ESP + local_4],EBP
    //         0049dbb5     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              scr_info.cpp:171 (15)
    //         0049dbba     PUSH       s_UnitInfo3                                      = 55h
    //         0049dbbf     MOV        this,panel_system
    //         0049dbc4     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_info.cpp:189 (19)
    //         0049dbc9     MOV        this,dword ptr [ESP + local_c]
    //         0049dbcd     MOV        dword ptr FS:[0x0],this
    //         0049dbd4     POP        EDI
    //         0049dbd5     POP        ESI
    //         0049dbd6     POP        EBP
    //         0049dbd7     POP        EBX
    //         0049dbd8     ADD        ESP,0x10
    //         0049dbdb     RET
    //                               LAB_0049dbdc                                                 XREF[1]:     0049db74(j)  
    //                              scr_info.cpp:173 (55)
    //         0049dbdc     MOV        ESI,s_FeaturesInfo                               = 46h
    //         0049dbe1     MOV        EAX,EDI
    //                               LAB_0049dbe3                                                 XREF[1]:     0049dc05(j)  
    //         0049dbe3     MOV        DL,byte ptr [EAX]
    //         0049dbe5     MOV        BL,byte ptr [ESI]=>s_FeaturesInfo                = 46h
    //                                                                                  = 61h
    //         0049dbe7     MOV        this,DL
    //         0049dbe9     CMP        DL,BL
    //         0049dbeb     JNZ        LAB_0049dc0b
    //         0049dbed     TEST       this,this
    //         0049dbef     JZ         LAB_0049dc07
    //         0049dbf1     MOV        DL,byte ptr [EAX + 0x1]
    //         0049dbf4     MOV        BL,byte ptr [ESI + 0x1]=>DAT_0058659d            = 65h
    //                                                                                  = "turesInfo"
    //         0049dbf7     MOV        this,DL
    //         0049dbf9     CMP        DL,BL
    //         0049dbfb     JNZ        LAB_0049dc0b
    //         0049dbfd     ADD        EAX,0x2
    //         0049dc00     ADD        ESI,0x2
    //         0049dc03     TEST       this,this
    //         0049dc05     JNZ        LAB_0049dbe3
    //                               LAB_0049dc07                                                 XREF[1]:     0049dbef(j)  
    //         0049dc07     XOR        EAX,EAX
    //         0049dc09     JMP        LAB_0049dc0f
    //                               LAB_0049dc0b                                                 XREF[2]:     0049dbeb(j), 0049dbfb(j)  
    //         0049dc0b     SBB        EAX,EAX
    //         0049dc0d     SBB        EAX,EBP
    //                               LAB_0049dc0f                                                 XREF[1]:     0049dc09(j)  
    //         0049dc0f     TEST       EAX,EAX
    //         0049dc11     JNZ        LAB_0049dc8a
    //                              scr_info.cpp:175 (11)
    //         0049dc13     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0049dc19     CALL       RGE_Base_Game::disable_input                     void disable_input(RGE_Base_Game * this)
    //                              scr_info.cpp:176 (53)
    //         0049dc1e     PUSH       0x484
    //         0049dc23     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0049dc28     ADD        ESP,0x4
    //         0049dc2b     MOV        dword ptr [ESP + local_10],EAX
    //         0049dc2f     TEST       EAX,EAX
    //         0049dc31     MOV        dword ptr [ESP + local_4],0x7
    //         0049dc39     JZ         LAB_0049dc53
    //         0049dc3b     PUSH       0x0
    //         0049dc3d     PUSH       0xc393
    //         0049dc42     PUSH       s_scrtech                                        = "scrtech"
    //         0049dc47     PUSH       s_TechInfo                                       = 54h
    //         0049dc4c     MOV        this,EAX
    //         0049dc4e     CALL       TRIBE_Screen_Info::TRIBE_Screen_Info             undefined TRIBE_Screen_Info(TRIBE_Screen_Info
    //                               LAB_0049dc53                                                 XREF[1]:     0049dc39(j)  
    //                              scr_info.cpp:177 (21)
    //         0049dc53     PUSH       0x0
    //         0049dc55     PUSH       s_TechInfo                                       = 54h
    //         0049dc5a     MOV        this,panel_system
    //         0049dc5f     MOV        dword ptr [ESP + local_4],EBP
    //         0049dc63     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              scr_info.cpp:178 (15)
    //         0049dc68     PUSH       s_FeaturesInfo                                   = 46h
    //         0049dc6d     MOV        this,panel_system
    //         0049dc72     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_info.cpp:189 (19)
    //         0049dc77     MOV        this,dword ptr [ESP + local_c]
    //         0049dc7b     MOV        dword ptr FS:[0x0],this
    //         0049dc82     POP        EDI
    //         0049dc83     POP        ESI
    //         0049dc84     POP        EBP
    //         0049dc85     POP        EBX
    //         0049dc86     ADD        ESP,0x10
    //         0049dc89     RET
    //                               LAB_0049dc8a                                                 XREF[1]:     0049dc11(j)  
    //                              scr_info.cpp:180 (59)
    //         0049dc8a     MOV        ESI,s_TechInfo                                   = 54h
    //         0049dc8f     MOV        EAX,EDI
    //                               LAB_0049dc91                                                 XREF[1]:     0049dcb3(j)  
    //         0049dc91     MOV        DL,byte ptr [EAX]
    //         0049dc93     MOV        BL,byte ptr [ESI]=>s_TechInfo                    = 54h
    //                                                                                  = 63h
    //         0049dc95     MOV        this,DL
    //         0049dc97     CMP        DL,BL
    //         0049dc99     JNZ        LAB_0049dcb9
    //         0049dc9b     TEST       this,this
    //         0049dc9d     JZ         LAB_0049dcb5
    //         0049dc9f     MOV        DL,byte ptr [EAX + 0x1]
    //         0049dca2     MOV        BL,byte ptr [ESI + 0x1]=>DAT_00586589            = 65h
    //                                                                                  = "hInfo"
    //         0049dca5     MOV        this,DL
    //         0049dca7     CMP        DL,BL
    //         0049dca9     JNZ        LAB_0049dcb9
    //         0049dcab     ADD        EAX,0x2
    //         0049dcae     ADD        ESI,0x2
    //         0049dcb1     TEST       this,this
    //         0049dcb3     JNZ        LAB_0049dc91
    //                               LAB_0049dcb5                                                 XREF[1]:     0049dc9d(j)  
    //         0049dcb5     XOR        EAX,EAX
    //         0049dcb7     JMP        LAB_0049dcbd
    //                               LAB_0049dcb9                                                 XREF[2]:     0049dc99(j), 0049dca9(j)  
    //         0049dcb9     SBB        EAX,EAX
    //         0049dcbb     SBB        EAX,EBP
    //                               LAB_0049dcbd                                                 XREF[1]:     0049dcb7(j)  
    //         0049dcbd     TEST       EAX,EAX
    //         0049dcbf     JNZ        LAB_0049d917
    //                              scr_info.cpp:182 (11)
    //         0049dcc5     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0049dccb     CALL       RGE_Base_Game::disable_input                     void disable_input(RGE_Base_Game * this)
    //                              scr_info.cpp:183 (53)
    //         0049dcd0     PUSH       0x484
    //         0049dcd5     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0049dcda     ADD        ESP,0x4
    //         0049dcdd     MOV        dword ptr [ESP + local_10],EAX
    //         0049dce1     TEST       EAX,EAX
    //         0049dce3     MOV        dword ptr [ESP + local_4],0x8
    //         0049dceb     JZ         LAB_0049dd05
    //         0049dced     PUSH       0x0
    //         0049dcef     PUSH       0xc38f
    //         0049dcf4     PUSH       s_scrinfqu                                       = "scrinfqu"
    //         0049dcf9     PUSH       s_QuotesInfo                                     = "QuotesInfo"
    //         0049dcfe     MOV        this,EAX
    //         0049dd00     CALL       TRIBE_Screen_Info::TRIBE_Screen_Info             undefined TRIBE_Screen_Info(TRIBE_Screen_Info
    //                               LAB_0049dd05                                                 XREF[1]:     0049dceb(j)  
    //                              scr_info.cpp:184 (21)
    //         0049dd05     PUSH       0x0
    //         0049dd07     PUSH       s_QuotesInfo                                     = "QuotesInfo"
    //         0049dd0c     MOV        this,panel_system
    //         0049dd11     MOV        dword ptr [ESP + local_4],EBP
    //         0049dd15     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              scr_info.cpp:185 (15)
    //         0049dd1a     PUSH       s_TechInfo                                       = 54h
    //         0049dd1f     MOV        this,panel_system
    //         0049dd24     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_info.cpp:189 (19)
    //         0049dd29     MOV        this,dword ptr [ESP + local_c]
    //         0049dd2d     POP        EDI
    //         0049dd2e     POP        ESI
    //         0049dd2f     POP        EBP
    //         0049dd30     MOV        dword ptr FS:[0x0],this
    //         0049dd37     POP        EBX
    //         0049dd38     ADD        ESP,0x10
    //         0049dd3b     RET
}

