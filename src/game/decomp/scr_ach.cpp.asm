// Auto-generated scaffold unit: scr_ach.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/scr_ach.cpp
#include "../include/common.h"

// Offset: 0x0048D530
undefined TribeAchievementsScreen(TribeAchievementsScreen* this_, char* param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TribeAchievementsScreen::TribeAchievementsScreen(char *,int)                       *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TribeAchievementsScreen(TribeAchievementsScreen
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TribeAchieveme    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0048d561(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0048d57c(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0048e1a9(R)  
    //              char[260]         Stack[-0x114   info_file                 XREF[0,3]:   0048d673(*), 0048d6db(*), 0048d708(*)  
    //              char[100]         Stack[-0x178   str                       XREF[0,3]:   0048d5fb(W), 0048d7a7(*), 0048d7bc(*)  
    //              char[50]          Stack[-0x1ac   temptxt                   XREF[0,4]:   0048d568(W), 0048d572(W), 0048d578(W), 0048d583(W)  
    //              TPanel *[8]       Stack[-0x1cc   tabList                   XREF[1]:     0048d556(W)  
    //              undefined4        Stack[-0x1dc   local_1dc                 XREF[3]:     0048d61c(W), 0048d647(R), 0048d652(W)  
    //              ulong             Stack[-0x1e4   color
    //                               ??0TribeAchievementsScreen@@QAE@PADH@Z                       XREF[3]:     action:0043f9fc(c), 
    //                               TribeAchievementsScreen::TribeAchievementsScreen                          action:00493cea(c), 
    //                                                                                                         stop_video:00523dd4(c)  
    //                              scr_ach.cpp:110 (47)
    //         0048d530     PUSH       -0x1
    //         0048d532     PUSH       FUN_0055e847
    //         0048d537     MOV        EAX,FS:[0x0]
    //         0048d53d     PUSH       EAX
    //         0048d53e     MOV        dword ptr FS:[0x0],ESP
    //         0048d545     SUB        ESP,0x1d4
    //         0048d54b     PUSH       EBX
    //         0048d54c     PUSH       EBP
    //         0048d54d     PUSH       ESI
    //         0048d54e     PUSH       EDI
    //         0048d54f     MOV        EBP,this
    //         0048d551     PUSH       s_Achievements_Screen                            = "Achievements Screen"
    //         0048d556     MOV        dword ptr [ESP + tabList[0]],EBP
    //         0048d55a     CALL       TScreenPanel::TScreenPanel                       undefined TScreenPanel(TScreenPanel * this, c
    //                              scr_ach.cpp:119 (2)
    //         0048d55f     XOR        this,this
    //                              scr_ach.cpp:121 (11)
    //         0048d561     MOV        EDX,dword ptr [ESP + param_2]
    //         0048d568     MOV        dword ptr [ESP + temptxt[35]],this
    //                              scr_ach.cpp:137 (107)
    //         0048d56c     LEA        EBX,[EBP + 0x5ec]
    //         0048d572     MOV        dword ptr [ESP + temptxt[39]],this
    //         0048d576     XOR        EAX,EAX
    //         0048d578     MOV        dword ptr [ESP + temptxt[43]],this
    //         0048d57c     MOV        dword ptr [ESP + local_4],EAX
    //         0048d583     MOV        dword ptr [ESP + temptxt[47]],this
    //         0048d587     MOV        dword ptr [EBP + 0x484],EAX
    //         0048d58d     MOV        dword ptr [EBP + 0x494],EAX
    //         0048d593     MOV        dword ptr [EBP + 0x488],EAX
    //         0048d599     MOV        dword ptr [EBP + 0x490],EAX
    //         0048d59f     MOV        dword ptr [EBP + 0x48c],EAX
    //         0048d5a5     MOV        dword ptr [EBP + 0x5f4],EAX
    //         0048d5ab     MOV        dword ptr [EBP + 0x5d4],EAX
    //         0048d5b1     MOV        dword ptr [EBP + 0x5e0],EAX
    //         0048d5b7     MOV        dword ptr [EBP + 0x5e8],EAX
    //         0048d5bd     MOV        dword ptr [EBP + 0x5e4],EAX
    //         0048d5c3     MOV        dword ptr [EBP + 0x5d8],EAX
    //         0048d5c9     MOV        dword ptr [EBP + 0x5dc],EAX
    //         0048d5cf     MOV        dword ptr [EBP + 0x5f0],EAX
    //         0048d5d5     MOV        dword ptr [EBX],EAX
    //                              scr_ach.cpp:138 (6)
    //         0048d5d7     MOV        dword ptr [EBP + 0x5cc],EAX
    //                              scr_ach.cpp:139 (6)
    //         0048d5dd     MOV        dword ptr [EBP + 0x5d0],EAX
    //                              scr_ach.cpp:140 (34)
    //         0048d5e3     MOV        dword ptr [EBP + 0x5c8],EAX
    //         0048d5e9     MOV        word ptr [ESP + Stack[-0x179]],this
    //         0048d5ee     LEA        EAX,[EBP + 0x4b4]
    //         0048d5f4     MOV        dword ptr [EBP],TribeAchievementsScreen::`vfta   = 0048e1f0
    //         0048d5fb     MOV        byte ptr [ESP + str[1]],this
    //         0048d5ff     MOV        dword ptr [EBP + 0x478],EDX
    //                              scr_ach.cpp:144 (2)
    //         0048d605     MOV        dword ptr [EAX],this
    //                              scr_ach.cpp:354 (161)
    //         0048d607     LEA        EDI,[EBP + 0x498]
    //         0048d60d     LEA        ESI,[EBP + 0x4c8]
    //         0048d613     MOV        dword ptr [EAX + 0x4],this
    //         0048d616     LEA        EDX,[EBP + 0x5a8]
    //         0048d61c     MOV        dword ptr [ESP + local_1dc],0x8
    //         0048d624     MOV        dword ptr [EAX + 0x8],this
    //         0048d627     MOV        dword ptr [EAX + 0xc],this
    //         0048d62a     MOV        dword ptr [EAX + 0x10],this
    //         0048d62d     MOV        this,0x7
    //         0048d632     XOR        EAX,EAX
    //         0048d634     STOSD.REP  ES:EDI
    //                               LAB_0048d636                                                 XREF[1]:     0048d656(j)  
    //         0048d636     MOV        this,0x7
    //         0048d63b     XOR        EAX,EAX
    //         0048d63d     MOV        EDI,ESI
    //         0048d63f     MOV        dword ptr [EDX],0x0
    //         0048d645     STOSD.REP  ES:EDI
    //         0048d647     MOV        EAX,dword ptr [ESP + local_1dc]
    //         0048d64b     ADD        EDX,0x4
    //         0048d64e     ADD        ESI,0x1c
    //         0048d651     DEC        EAX
    //         0048d652     MOV        dword ptr [ESP + local_1dc],EAX
    //         0048d656     JNZ        LAB_0048d636
    //         0048d658     MOV        EAX,dword ptr [EBP + 0x478]
    //         0048d65e     TEST       EAX,EAX
    //         0048d660     JZ         LAB_0048d6d1
    //         0048d662     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0048d668     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0048d66d     MOV        this,byte ptr [EAX + 0x80]
    //         0048d673     LEA        EDX=>info_file[4],[ESP + 0xe0]
    //         0048d67a     CMP        this,0x1
    //         0048d67d     JNZ        LAB_0048d6a8
    //         0048d67f     MOV        EDI,s_scr7                                       = 73h
    //         0048d684     OR         this,0xffffffff
    //         0048d687     XOR        EAX,EAX
    //         0048d689     SCASB.RE   ES:EDI=>s_scr7                                   = 73h
    //                                                                                  = 63h
    //         0048d68b     NOT        this
    //         0048d68d     SUB        EDI,this
    //         0048d68f     MOV        EAX,this
    //         0048d691     MOV        ESI,EDI
    //         0048d693     MOV        EDI,EDX
    //         0048d695     SHR        this,0x2
    //         0048d698     MOVSD.REP  ES:EDI,ESI
    //         0048d69a     MOV        this,EAX
    //         0048d69c     MOV        EAX,0xc389
    //         0048d6a1     AND        this,0x3
    //         0048d6a4     MOVSB.REP  ES:EDI,ESI
    //         0048d6a6     JMP        LAB_0048d6ff
    //                               LAB_0048d6a8                                                 XREF[1]:     0048d67d(j)  
    //                              scr_ach.cpp:169 (29)
    //         0048d6a8     MOV        EDI,s_scr8                                       = 73h
    //         0048d6ad     OR         this,0xffffffff
    //         0048d6b0     XOR        EAX,EAX
    //         0048d6b2     SCASB.RE   ES:EDI=>s_scr8                                   = 73h
    //                                                                                  = 63h
    //         0048d6b4     NOT        this
    //         0048d6b6     SUB        EDI,this
    //         0048d6b8     MOV        EAX,this
    //         0048d6ba     MOV        ESI,EDI
    //         0048d6bc     MOV        EDI,EDX
    //         0048d6be     SHR        this,0x2
    //         0048d6c1     MOVSD.REP  ES:EDI,ESI
    //         0048d6c3     MOV        this,EAX
    //                              scr_ach.cpp:170 (10)
    //         0048d6c5     MOV        EAX,0xc38a
    //         0048d6ca     AND        this,0x3
    //         0048d6cd     MOVSB.REP  ES:EDI,ESI
    //                              scr_ach.cpp:173 (2)
    //         0048d6cf     JMP        LAB_0048d6ff
    //                               LAB_0048d6d1                                                 XREF[1]:     0048d660(j)  
    //                              scr_ach.cpp:175 (36)
    //         0048d6d1     MOV        EDI,s_scr10                                      = "scr10"
    //         0048d6d6     OR         this,0xffffffff
    //         0048d6d9     XOR        EAX,EAX
    //         0048d6db     LEA        EDX=>info_file[4],[ESP + 0xe0]
    //         0048d6e2     SCASB.RE   ES:EDI=>s_scr10                                  = "scr10"
    //                                                                                  = "cr10"
    //         0048d6e4     NOT        this
    //         0048d6e6     SUB        EDI,this
    //         0048d6e8     MOV        EAX,this
    //         0048d6ea     MOV        ESI,EDI
    //         0048d6ec     MOV        EDI,EDX
    //         0048d6ee     SHR        this,0x2
    //         0048d6f1     MOVSD.REP  ES:EDI,ESI=>s_scr10                              = "scr10"
    //         0048d6f3     MOV        this,EAX
    //                              scr_ach.cpp:176 (10)
    //         0048d6f5     MOV        EAX,0xc38d
    //         0048d6fa     AND        this,0x3
    //         0048d6fd     MOVSB.REP  ES:EDI,ESI=>s_scr10                              = "scr10"
    //                               LAB_0048d6ff                                                 XREF[2]:     0048d6a6(j), 0048d6cf(j)  
    //                              scr_ach.cpp:179 (32)
    //         0048d6ff     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
    //         0048d705     PUSH       0x1
    //         0048d707     PUSH       EAX
    //         0048d708     LEA        this=>info_file[4],[ESP + 0xe8]
    //         0048d70f     MOV        EAX,dword ptr [EDX + 0x4c]
    //         0048d712     PUSH       this
    //         0048d713     PUSH       EAX
    //         0048d714     MOV        this,EBP
    //         0048d716     CALL       TScreenPanel::setup                              long setup(TScreenPanel * this, TDrawArea * p
    //         0048d71b     TEST       EAX,EAX
    //         0048d71d     JNZ        LAB_0048d72e
    //                              scr_ach.cpp:181 (10)
    //         0048d71f     MOV        dword ptr [EBP + 0xd8],0x1
    //                              scr_ach.cpp:182 (5)
    //         0048d729     JMP        LAB_0048e1a9
    //                               LAB_0048d72e                                                 XREF[1]:     0048d71d(j)  
    //                              scr_ach.cpp:185 (17)
    //         0048d72e     PUSH       0x1e0
    //         0048d733     PUSH       0x280
    //         0048d738     MOV        this,EBP
    //         0048d73a     CALL       TEasy_Panel::set_ideal_size                      void set_ideal_size(TEasy_Panel * this, long 
    //                              scr_ach.cpp:188 (11)
    //         0048d73f     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0048d745     MOV        EAX,0x10624dd3
    //                              scr_ach.cpp:189 (2)
    //         0048d74a     XOR        ESI,ESI
    //                              scr_ach.cpp:190 (16)
    //         0048d74c     XOR        EDI,EDI
    //         0048d74e     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0048d754     MUL        dword ptr [EDX + 0x4]
    //         0048d757     MOV        this,EDX
    //         0048d759     SHR        this,0x6
    //                              scr_ach.cpp:191 (5)
    //         0048d75c     CMP        this,0x3b
    //         0048d75f     JLE        LAB_0048d7a4
    //                              scr_ach.cpp:193 (21)
    //         0048d761     MOV        EAX,0x88888889
    //         0048d766     IMUL       this
    //         0048d768     ADD        EDX,this
    //         0048d76a     SAR        EDX,0x5
    //         0048d76d     MOV        EAX,EDX
    //         0048d76f     SHR        EAX,0x1f
    //         0048d772     ADD        EDX,EAX
    //         0048d774     MOV        ESI,EDX
    //                              scr_ach.cpp:194 (7)
    //         0048d776     SHL        EDX,0x4
    //         0048d779     SUB        EDX,ESI
    //         0048d77b     NEG        EDX
    //                              scr_ach.cpp:195 (8)
    //         0048d77d     CMP        ESI,0x3b
    //         0048d780     LEA        this,[this->_padding_ + EDX*0x4]
    //         0048d783     JLE        LAB_0048d7a4
    //                              scr_ach.cpp:197 (21)
    //         0048d785     MOV        EAX,0x88888889
    //         0048d78a     IMUL       ESI
    //         0048d78c     ADD        EDX,ESI
    //         0048d78e     SAR        EDX,0x5
    //         0048d791     MOV        EAX,EDX
    //         0048d793     SHR        EAX,0x1f
    //         0048d796     ADD        EDX,EAX
    //         0048d798     MOV        EDI,EDX
    //                              scr_ach.cpp:198 (10)
    //         0048d79a     SHL        EDX,0x4
    //         0048d79d     SUB        EDX,EDI
    //         0048d79f     NEG        EDX
    //         0048d7a1     LEA        ESI,[ESI + EDX*0x4]
    //                               LAB_0048d7a4                                                 XREF[2]:     0048d75f(j), 0048d783(j)  
    //                              scr_ach.cpp:201 (24)
    //         0048d7a4     PUSH       this
    //         0048d7a5     PUSH       ESI
    //         0048d7a6     PUSH       EDI
    //         0048d7a7     LEA        EAX=>str[4],[ESP + 0x88]
    //         0048d7ae     PUSH       s_%02ld:%02ld:%02ld                              = "%02ld:%02ld:%02ld"
    //         0048d7b3     PUSH       EAX
    //         0048d7b4     CALL       sprintf                                          undefined sprintf()
    //         0048d7b9     ADD        ESP,0x14
    //                              scr_ach.cpp:203 (39)
    //         0048d7bc     LEA        this=>str[4],[ESP + 0x7c]
    //         0048d7c0     LEA        ESI,[EBP + 0x494]
    //         0048d7c6     PUSH       0x0
    //         0048d7c8     PUSH       0x0
    //         0048d7ca     PUSH       0x0
    //         0048d7cc     PUSH       0xb
    //         0048d7ce     PUSH       0x14
    //                              language.dll match for 0x6e: "Copperplate Gothic Light"
    //         0048d7d0     PUSH       0x6e
    //         0048d7d2     PUSH       0xa
    //         0048d7d4     PUSH       0x1e0
    //         0048d7d9     PUSH       this
    //         0048d7da     PUSH       ESI
    //         0048d7db     PUSH       EBP
    //         0048d7dc     MOV        this,EBP
    //         0048d7de     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //                              scr_ach.cpp:204 (11)
    //         0048d7e3     MOV        this,dword ptr [ESI]
    //         0048d7e5     PUSH       0x2
    //         0048d7e7     PUSH       0x3
    //         0048d7e9     CALL       TTextPanel::set_alignment                        void set_alignment(TTextPanel * this, Alignme
    //                              scr_ach.cpp:206 (39)
    //         0048d7ee     PUSH       0x0
    //         0048d7f0     PUSH       0x0
    //         0048d7f2     PUSH       0x1
    //         0048d7f4     PUSH       0x1
    //         0048d7f6     PUSH       0x1e
    //         0048d7f8     PUSH       0x280
    //         0048d7fd     PUSH       0x5
    //         0048d7ff     PUSH       0x0
    //         0048d801     LEA        EAX,[EBP + 0x484]
    //                              language.dll match for 0x269e: "Achievements"
    //         0048d807     PUSH       0x269e
    //         0048d80c     PUSH       EAX
    //         0048d80d     PUSH       EBP
    //         0048d80e     MOV        this,EBP
    //         0048d810     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //                              scr_ach.cpp:208 (36)
    //         0048d815     PUSH       0x0
    //         0048d817     PUSH       0x0
    //         0048d819     PUSH       0x1
    //         0048d81b     PUSH       0x1
    //         0048d81d     PUSH       0x1e
    //         0048d81f     PUSH       0x26c
    //         0048d824     PUSH       0x23
    //         0048d826     PUSH       0xa
    //         0048d828     LEA        EAX,[EBP + 0x488]
    //         0048d82e     PUSH       0x0
    //         0048d830     PUSH       EAX
    //         0048d831     PUSH       EBP
    //         0048d832     MOV        this,EBP
    //         0048d834     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //                              scr_ach.cpp:210 (42)
    //         0048d839     PUSH       0x0
    //         0048d83b     PUSH       0x0
    //         0048d83d     PUSH       0x1
    //         0048d83f     PUSH       0xb
    //         0048d841     PUSH       0x14
    //         0048d843     PUSH       0x26c
    //         0048d848     PUSH       0x19a
    //         0048d84d     PUSH       0xa
    //         0048d84f     LEA        EAX,[EBP + 0x48c]
    //                              language.dll match for 0x26db: "Click a column for more detai
    //         0048d855     PUSH       0x26db
    //         0048d85a     PUSH       EAX
    //         0048d85b     PUSH       EBP
    //         0048d85c     MOV        this,EBP
    //         0048d85e     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //                              scr_ach.cpp:212 (14)
    //         0048d863     MOV        EAX,dword ptr [EBP + 0x478]
    //         0048d869     TEST       EAX,EAX
    //         0048d86b     JZ         LAB_0048d951
    //                              scr_ach.cpp:214 (20)
    //         0048d871     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0048d877     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0048d87c     CMP        byte ptr [EAX + 0x80],0x1
    //         0048d883     JNZ        LAB_0048d898
    //                              scr_ach.cpp:215 (17)
    //         0048d885     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
    //         0048d88b     PUSH       0x2
    //         0048d88d     MOV        EAX,dword ptr [EDX + 0x3f4]
    //         0048d893     MOV        this,dword ptr [EAX + 0x5c]
    //                              scr_ach.cpp:216 (2)
    //         0048d896     JMP        LAB_0048d8a9
    //                               LAB_0048d898                                                 XREF[1]:     0048d883(j)  
    //                              scr_ach.cpp:217 (24)
    //         0048d898     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0048d89e     PUSH       0x3
    //         0048d8a0     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0048d8a6     MOV        this,dword ptr [EDX + 0x5c]
    //                               LAB_0048d8a9                                                 XREF[1]:     0048d896(j)  
    //         0048d8a9     CALL       RGE_Scenario::Get_message                        char * Get_message(RGE_Scenario * this, long 
    //         0048d8ae     MOV        EDI,EAX
    //                              scr_ach.cpp:218 (17)
    //         0048d8b0     TEST       EDI,EDI
    //         0048d8b2     JZ         LAB_0048d951
    //         0048d8b8     CMP        byte ptr [EDI],0x0
    //         0048d8bb     JZ         LAB_0048d951
    //                              scr_ach.cpp:220 (42)
    //         0048d8c1     PUSH       0x1
    //         0048d8c3     PUSH       0x0
    //         0048d8c5     PUSH       0x0
    //         0048d8c7     PUSH       0xb
    //         0048d8c9     PUSH       0x14a
    //         0048d8ce     PUSH       0x26c
    //         0048d8d3     PUSH       0x55
    //         0048d8d5     PUSH       0xa
    //         0048d8d7     LEA        ESI,[EBP + 0x490]
    //         0048d8dd     PUSH       s_                                               = ""
    //         0048d8e2     PUSH       ESI
    //         0048d8e3     PUSH       EBP
    //         0048d8e4     MOV        this,EBP
    //         0048d8e6     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //                              scr_ach.cpp:221 (6)
    //         0048d8eb     MOV        EAX,dword ptr [ESI]
    //         0048d8ed     TEST       EAX,EAX
    //         0048d8ef     JZ         LAB_0048d951
    //                              scr_ach.cpp:223 (17)
    //         0048d8f1     PUSH       0x14
    //         0048d8f3     PUSH       EAX
    //         0048d8f4     LEA        EAX,[EBP + 0x5d0]
    //         0048d8fa     MOV        this,EBP
    //         0048d8fc     PUSH       EAX
    //         0048d8fd     CALL       TEasy_Panel::create_auto_scrollbar               int create_auto_scrollbar(TEasy_Panel * this,
    //                              scr_ach.cpp:224 (66)
    //         0048d902     XOR        EDX,EDX
    //         0048d904     MOV        this,dword ptr [ESI]
    //         0048d906     MOV        DL,byte ptr [EBP + 0x325]
    //         0048d90c     PUSH       EDX
    //         0048d90d     XOR        EDX,EDX
    //         0048d90f     MOV        DL,byte ptr [EBP + 0x324]
    //         0048d915     MOV        EAX,dword ptr [this->_padding_]
    //         0048d917     PUSH       EDX
    //         0048d918     XOR        EDX,EDX
    //         0048d91a     MOV        DL,byte ptr [EBP + 0x323]
    //         0048d920     PUSH       EDX
    //         0048d921     XOR        EDX,EDX
    //         0048d923     MOV        DL,byte ptr [EBP + 0x322]
    //         0048d929     PUSH       EDX
    //         0048d92a     XOR        EDX,EDX
    //         0048d92c     MOV        DL,byte ptr [EBP + 0x321]
    //         0048d932     PUSH       EDX
    //         0048d933     XOR        EDX,EDX
    //         0048d935     MOV        DL,byte ptr [EBP + 0x320]
    //         0048d93b     PUSH       EDX
    //         0048d93c     PUSH       0x4
    //         0048d93e     CALL       dword ptr [EAX + 0xec]
    //                              scr_ach.cpp:225 (13)
    //         0048d944     MOV        ESI,dword ptr [ESI]
    //         0048d946     PUSH       EDI
    //         0048d947     MOV        this,ESI
    //         0048d949     MOV        EAX,dword ptr [ESI]
    //         0048d94b     CALL       dword ptr [EAX + 0xe8]
    //                               LAB_0048d951                                                 XREF[4]:     0048d86b(j), 0048d8b2(j), 
    //                                                                                                         0048d8bb(j), 0048d8ef(j)  
    //                              scr_ach.cpp:231 (47)
    //         0048d951     PUSH       0x1e0
    //         0048d956     PUSH       offset DAT_fffffff8
    //         0048d95b     MOV        this,dword ptr [EBP + 0x5f4]
    //         0048d961     PUSH       offset DAT_fffffff4
    //         0048d963     PUSH       offset DAT_fffffff0
    //         0048d965     PUSH       0x14a
    //         0048d96a     PUSH       0x26c
    //         0048d96f     PUSH       0x55
    //         0048d971     LEA        ESI,[EBP + 0x5f4]
    //         0048d977     PUSH       0xa
    //         0048d979     PUSH       ESI
    //         0048d97a     PUSH       EBP
    //         0048d97b     CALL       Time_Line_Panel::create_timeline                 long create_timeline(Time_Line_Panel * this, 
    //                              scr_ach.cpp:232 (63)
    //         0048d980     XOR        this,this
    //         0048d982     XOR        EDX,EDX
    //         0048d984     MOV        this,byte ptr [EBP + 0x325]
    //         0048d98a     MOV        DL,byte ptr [EBP + 0x324]
    //         0048d990     XOR        EAX,EAX
    //         0048d992     PUSH       this
    //         0048d993     MOV        AL,byte ptr [EBP + 0x323]
    //         0048d999     PUSH       EDX=>DAT_fffffff8
    //         0048d99a     XOR        this,this
    //         0048d99c     PUSH       EAX=>DAT_fffffff4
    //         0048d99d     MOV        this,byte ptr [EBP + 0x322]
    //         0048d9a3     XOR        EDX,EDX
    //         0048d9a5     MOV        DL,byte ptr [EBP + 0x321]
    //         0048d9ab     XOR        EAX,EAX
    //         0048d9ad     MOV        AL,byte ptr [EBP + 0x320]
    //         0048d9b3     PUSH       this=>DAT_fffffff0
    //         0048d9b4     MOV        this,dword ptr [ESI]
    //         0048d9b6     PUSH       EDX
    //         0048d9b7     PUSH       EAX
    //         0048d9b8     PUSH       0x3
    //         0048d9ba     CALL       Time_Line_Panel::set_bevel_info                  void set_bevel_info(Time_Line_Panel * this, i
    //                              scr_ach.cpp:233 (12)
    //         0048d9bf     MOV        this,dword ptr [ESI]
    //         0048d9c1     PUSH       s_timeline.slp                                   = "timeline.slp"
    //         0048d9c6     CALL       Time_Line_Panel::set_special_events              int set_special_events(Time_Line_Panel * this
    //                              scr_ach.cpp:236 (38)
    //         0048d9cb     PUSH       0x0
    //         0048d9cd     PUSH       offset DAT_fffffff8
    //         0048d9cf     PUSH       offset DAT_fffffff4
    //         0048d9d1     PUSH       0x0=>DAT_fffffff0
    //         0048d9d3     PUSH       0x0
    //         0048d9d5     PUSH       0x0
    //         0048d9d7     PUSH       0x0
    //         0048d9d9     PUSH       0x0
    //                              language.dll match for 0x3ea: "X"
    //         0048d9db     PUSH       0x3ea
    //         0048d9e0     PUSH       EBX
    //         0048d9e1     PUSH       EBP
    //         0048d9e2     MOV        this,EBP
    //         0048d9e4     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         0048d9e9     TEST       EAX,EAX
    //         0048d9eb     JZ         LAB_0048e1a9
    //                              scr_ach.cpp:237 (9)
    //         0048d9f1     MOV        this,dword ptr [EBX]
    //         0048d9f3     PUSH       0x1
    //         0048d9f5     MOV        EDX,dword ptr [this->_padding_]
    //         0048d9f7     CALL       dword ptr [EDX + 0x14]
    //                              scr_ach.cpp:238 (33)
    //         0048d9fa     MOV        this,dword ptr [EBX]
    //         0048d9fc     PUSH       0x0
    //         0048d9fe     PUSH       0x0=>DAT_fffffff8
    //         0048da00     PUSH       0x0=>DAT_fffffff4
    //         0048da02     MOV        EAX,dword ptr [this->_padding_]
    //         0048da04     PUSH       0x0=>DAT_fffffff0
    //         0048da06     PUSH       0x11
    //         0048da08     PUSH       0x11
    //         0048da0a     PUSH       0x11
    //         0048da0c     PUSH       0x11
    //         0048da0e     PUSH       0x4
    //         0048da10     PUSH       0x4
    //         0048da12     PUSH       0x4
    //         0048da14     PUSH       0x4
    //         0048da16     PUSH       0x9
    //         0048da18     CALL       dword ptr [EAX + 0x18]
    //                              scr_ach.cpp:241 (39)
    //         0048da1b     PUSH       0x0
    //         0048da1d     PUSH       0x0=>DAT_fffffff8
    //         0048da1f     PUSH       0x0=>DAT_fffffff4
    //         0048da21     PUSH       offset DAT_fffffff0
    //         0048da23     PUSH       0x1e
    //         0048da25     PUSH       0xc8
    //         0048da2a     PUSH       0x97
    //         0048da2f     PUSH       0x62
    //         0048da31     LEA        EAX,[EBP + 0x498]
    //         0048da37     PUSH       0x0
    //         0048da39     PUSH       EAX
    //         0048da3a     PUSH       EBP
    //         0048da3b     MOV        this,EBP
    //         0048da3d     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //                              scr_ach.cpp:242 (42)
    //         0048da42     PUSH       0x0
    //         0048da44     PUSH       0x0=>DAT_fffffff8
    //         0048da46     PUSH       0x0=>DAT_fffffff4
    //         0048da48     PUSH       offset DAT_fffffff0
    //         0048da4a     PUSH       0x1e
    //         0048da4c     PUSH       0xc8
    //                              language.dll match for 0x83: "Arial"
    //         0048da51     PUSH       0x83
    //         0048da56     PUSH       0x98
    //         0048da5b     LEA        this,[EBP + 0x49c]
    //         0048da61     PUSH       0x0
    //         0048da63     PUSH       this
    //         0048da64     PUSH       EBP
    //         0048da65     MOV        this,EBP
    //         0048da67     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //                              scr_ach.cpp:243 (39)
    //         0048da6c     PUSH       0x0
    //         0048da6e     PUSH       0x0=>DAT_fffffff8
    //         0048da70     PUSH       0x0=>DAT_fffffff4
    //         0048da72     PUSH       offset DAT_fffffff0
    //         0048da74     PUSH       0x1e
    //         0048da76     PUSH       0x91
    //                              language.dll match for 0x6f: "12"
    //         0048da7b     PUSH       0x6f
    //         0048da7d     PUSH       0xd4
    //         0048da82     LEA        EDX,[EBP + 0x4a0]
    //         0048da88     PUSH       0x0
    //         0048da8a     PUSH       EDX
    //         0048da8b     PUSH       EBP
    //         0048da8c     MOV        this,EBP
    //         0048da8e     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //                              scr_ach.cpp:244 (39)
    //         0048da93     PUSH       0x0
    //         0048da95     PUSH       0x0=>DAT_fffffff8
    //         0048da97     PUSH       offset DAT_fffffff4
    //         0048da99     PUSH       offset DAT_fffffff0
    //         0048da9b     PUSH       0x1e
    //         0048da9d     PUSH       0xc8
    //         0048daa2     PUSH       0x5b
    //         0048daa4     PUSH       0x104
    //         0048daa9     LEA        EAX,[EBP + 0x4a4]
    //         0048daaf     PUSH       0x0
    //         0048dab1     PUSH       EAX
    //         0048dab2     PUSH       EBP
    //         0048dab3     MOV        this,EBP
    //         0048dab5     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //                              scr_ach.cpp:245 (39)
    //         0048daba     PUSH       0x0
    //         0048dabc     PUSH       0x0=>DAT_fffffff8
    //         0048dabe     PUSH       0x0=>DAT_fffffff4
    //         0048dac0     LEA        ESI,[EBP + 0x4a8]
    //         0048dac6     PUSH       offset DAT_fffffff0
    //         0048dac8     PUSH       0x1e
    //         0048daca     PUSH       0x91
    //                              language.dll match for 0x6f: "12"
    //         0048dacf     PUSH       0x6f
    //         0048dad1     PUSH       0x16c
    //         0048dad6     PUSH       0x0
    //         0048dad8     PUSH       ESI
    //         0048dad9     PUSH       EBP
    //         0048dada     MOV        this,EBP
    //         0048dadc     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //                              scr_ach.cpp:246 (42)
    //         0048dae1     PUSH       0x0
    //         0048dae3     PUSH       0x0=>DAT_fffffff8
    //         0048dae5     PUSH       0x0=>DAT_fffffff4
    //         0048dae7     PUSH       offset DAT_fffffff0
    //         0048dae9     PUSH       0x1e
    //         0048daeb     PUSH       0xc8
    //                              language.dll match for 0x83: "Arial"
    //         0048daf0     PUSH       0x83
    //         0048daf5     LEA        EDI,[EBP + 0x4ac]
    //         0048dafb     PUSH       0x172
    //         0048db00     PUSH       0x0
    //         0048db02     PUSH       EDI
    //         0048db03     PUSH       EBP
    //         0048db04     MOV        this,EBP
    //         0048db06     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //                              scr_ach.cpp:247 (42)
    //         0048db0b     PUSH       0x0
    //         0048db0d     PUSH       0x0=>DAT_fffffff8
    //         0048db0f     PUSH       0x0=>DAT_fffffff4
    //         0048db11     PUSH       offset DAT_fffffff0
    //         0048db13     PUSH       0x1e
    //         0048db15     PUSH       0xc8
    //         0048db1a     PUSH       0x97
    //         0048db1f     LEA        EBX,[EBP + 0x4b0]
    //         0048db25     PUSH       0x1a8
    //         0048db2a     PUSH       0x0
    //         0048db2c     PUSH       EBX
    //         0048db2d     PUSH       EBP
    //         0048db2e     MOV        this,EBP
    //         0048db30     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //                              scr_ach.cpp:248 (11)
    //         0048db35     MOV        this,dword ptr [ESI]
    //         0048db37     PUSH       0x2
    //         0048db39     PUSH       offset DAT_fffffff8
    //         0048db3b     CALL       TTextPanel::set_alignment                        void set_alignment(TTextPanel * this, Alignme
    //                              scr_ach.cpp:249 (11)
    //         0048db40     MOV        this,dword ptr [EDI]
    //         0048db42     PUSH       0x2
    //         0048db44     PUSH       offset DAT_fffffff8
    //         0048db46     CALL       TTextPanel::set_alignment                        void set_alignment(TTextPanel * this, Alignme
    //                              scr_ach.cpp:250 (11)
    //         0048db4b     MOV        this,dword ptr [EBX]
    //         0048db4d     PUSH       0x2
    //         0048db4f     PUSH       offset DAT_fffffff8
    //         0048db51     CALL       TTextPanel::set_alignment                        void set_alignment(TTextPanel * this, Alignme
    //                              scr_ach.cpp:252 (42)
    //         0048db56     PUSH       0x0
    //         0048db58     PUSH       0x0=>DAT_fffffff8
    //         0048db5a     PUSH       0x0=>DAT_fffffff4
    //         0048db5c     PUSH       offset DAT_fffffff0
    //         0048db5e     PUSH       0xfa
    //                              language.dll match for 0x82: "B"
    //         0048db63     PUSH       0x82
    //         0048db68     PUSH       0x97
    //         0048db6d     PUSH       0x64
    //         0048db6f     LEA        EAX,[EBP + 0x4b4]
    //         0048db75     PUSH       0x0
    //         0048db77     PUSH       EAX
    //         0048db78     PUSH       EBP
    //         0048db79     MOV        this,EBP
    //         0048db7b     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //                              scr_ach.cpp:253 (45)
    //         0048db80     PUSH       0x0
    //         0048db82     PUSH       0x0=>DAT_fffffff8
    //         0048db84     PUSH       0x0=>DAT_fffffff4
    //         0048db86     PUSH       offset DAT_fffffff0
    //         0048db88     PUSH       0x112
    //         0048db8d     PUSH       0x80
    //                              language.dll match for 0x83: "Arial"
    //         0048db92     PUSH       0x83
    //         0048db97     PUSH       0x9a
    //         0048db9c     LEA        this,[EBP + 0x4b8]
    //         0048dba2     PUSH       0x0
    //         0048dba4     PUSH       this
    //         0048dba5     PUSH       EBP
    //         0048dba6     MOV        this,EBP
    //         0048dba8     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //                              scr_ach.cpp:254 (39)
    //         0048dbad     PUSH       0x0
    //         0048dbaf     PUSH       0x0=>DAT_fffffff8
    //         0048dbb1     PUSH       0x0=>DAT_fffffff4
    //         0048dbb3     PUSH       offset DAT_fffffff0
    //         0048dbb5     PUSH       0x121
    //         0048dbba     PUSH       0x79
    //                              language.dll match for 0x6f: "12"
    //         0048dbbc     PUSH       0x6f
    //         0048dbbe     PUSH       0xd6
    //         0048dbc3     LEA        EDX,[EBP + 0x4bc]
    //         0048dbc9     PUSH       0x0
    //         0048dbcb     PUSH       EDX
    //         0048dbcc     PUSH       EBP
    //         0048dbcd     MOV        this,EBP
    //         0048dbcf     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //                              scr_ach.cpp:255 (42)
    //         0048dbd4     PUSH       0x0
    //         0048dbd6     PUSH       0x0=>DAT_fffffff8
    //         0048dbd8     PUSH       0x0=>DAT_fffffff4
    //         0048dbda     PUSH       offset DAT_fffffff0
    //         0048dbdc     PUSH       0x135
    //         0048dbe1     PUSH       0x9c
    //         0048dbe6     PUSH       0x5b
    //         0048dbe8     PUSH       0x11a
    //         0048dbed     LEA        EAX,[EBP + 0x4c0]
    //         0048dbf3     PUSH       0x0
    //         0048dbf5     PUSH       EAX
    //         0048dbf6     PUSH       EBP
    //         0048dbf7     MOV        this,EBP
    //         0048dbf9     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //                              scr_ach.cpp:256 (76)
    //         0048dbfe     PUSH       0x0
    //         0048dc00     PUSH       0x0=>DAT_fffffff8
    //         0048dc02     PUSH       0x0=>DAT_fffffff4
    //         0048dc04     PUSH       offset DAT_fffffff0
    //         0048dc06     PUSH       0x121
    //         0048dc0b     PUSH       0x79
    //                              language.dll match for 0x6f: "12"
    //         0048dc0d     PUSH       0x6f
    //         0048dc0f     PUSH       0x184
    //         0048dc14     LEA        this,[EBP + 0x4c4]
    //         0048dc1a     PUSH       0x0
    //         0048dc1c     PUSH       this
    //         0048dc1d     PUSH       EBP
    //         0048dc1e     MOV        this,EBP
    //         0048dc20     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         0048dc25     LEA        EAX,[EBP + 0x5a8]
    //         0048dc2b     MOV        dword ptr [ESP + 0x14],0x1
    //         0048dc33     MOV        dword ptr [ESP + 0x20],0x4
    //         0048dc3b     MOV        ESI,0xab
    //         0048dc40     MOV        dword ptr [ESP + 0x1c],EAX
    //         0048dc44     LEA        EDI,[EBP + 0x4d0]
    //                               LAB_0048dc4a                                                 XREF[1]:     0048de66(j)  
    //                              scr_ach.cpp:260 (24)
    //         0048dc4a     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
    //         0048dc50     MOV        EAX,dword ptr [EDX + 0x3f4]
    //         0048dc56     MOV        EDX,dword ptr [ESP + 0x14]
    //         0048dc5a     MOVSX      this,word ptr [EAX + 0x3c]
    //         0048dc5e     CMP        EDX,this
    //         0048dc60     JGE        LAB_0048dc71
    //                              scr_ach.cpp:261 (13)
    //         0048dc62     MOV        EDX,dword ptr [EAX + 0x40]
    //         0048dc65     MOV        EAX,dword ptr [ESP + 0x20]
    //         0048dc69     MOV        this,dword ptr [EDX + EAX*0x1]
    //         0048dc6c     MOV        EAX,dword ptr [ECX + this->_padding_]
    //                              scr_ach.cpp:262 (2)
    //         0048dc6f     JMP        LAB_0048dc73
    //                               LAB_0048dc71                                                 XREF[1]:     0048dc60(j)  
    //                              scr_ach.cpp:263 (2)
    //         0048dc71     XOR        EAX,EAX
    //                               LAB_0048dc73                                                 XREF[1]:     0048dc6f(j)  
    //                              scr_ach.cpp:265 (32)
    //         0048dc73     MOV        EDX,dword ptr [ESP + 0x1c]
    //         0048dc77     PUSH       0x0
    //         0048dc79     PUSH       offset DAT_fffffff8
    //         0048dc7b     PUSH       0x0=>DAT_fffffff4
    //         0048dc7d     PUSH       offset DAT_fffffff0
    //         0048dc7f     PUSH       0x1d
    //         0048dc81     PUSH       0x96
    //         0048dc86     PUSH       ESI
    //         0048dc87     PUSH       0x16
    //         0048dc89     PUSH       EAX
    //         0048dc8a     PUSH       EDX
    //         0048dc8b     PUSH       EBP
    //         0048dc8c     MOV        this,EBP
    //         0048dc8e     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //                              scr_ach.cpp:266 (32)
    //         0048dc93     PUSH       0x0
    //         0048dc95     PUSH       offset DAT_fffffff8
    //         0048dc97     PUSH       offset DAT_fffffff4
    //         0048dc99     PUSH       offset DAT_fffffff0
    //         0048dc9b     PUSH       0x1d
    //         0048dc9d     PUSH       0x33
    //         0048dc9f     PUSH       ESI
    //         0048dca0     LEA        EBX,[EDI + -0x8]
    //         0048dca3     PUSH       0xb2
    //         0048dca8     PUSH       0x0
    //         0048dcaa     PUSH       EBX
    //         0048dcab     PUSH       EBP
    //         0048dcac     MOV        this,EBP
    //         0048dcae     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //                              scr_ach.cpp:267 (32)
    //         0048dcb3     PUSH       0x0
    //         0048dcb5     PUSH       offset DAT_fffffff8
    //         0048dcb7     PUSH       offset DAT_fffffff4
    //         0048dcb9     PUSH       offset DAT_fffffff0
    //         0048dcbb     PUSH       0x1d
    //         0048dcbd     PUSH       0x33
    //         0048dcbf     PUSH       ESI
    //         0048dcc0     PUSH       0xe7
    //         0048dcc5     LEA        EAX,[EDI + -0x4]
    //         0048dcc8     PUSH       0x0
    //         0048dcca     PUSH       EAX
    //         0048dccb     PUSH       EBP
    //         0048dccc     MOV        this,EBP
    //         0048dcce     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //                              scr_ach.cpp:268 (29)
    //         0048dcd3     PUSH       0x0
    //         0048dcd5     PUSH       offset DAT_fffffff8
    //         0048dcd7     PUSH       offset DAT_fffffff4
    //         0048dcd9     PUSH       offset DAT_fffffff0
    //         0048dcdb     PUSH       0x1d
    //         0048dcdd     PUSH       0x33
    //         0048dcdf     PUSH       ESI
    //         0048dce0     PUSH       0x11b
    //         0048dce5     PUSH       0x0
    //         0048dce7     PUSH       EDI
    //         0048dce8     PUSH       EBP
    //         0048dce9     MOV        this,EBP
    //         0048dceb     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //                              scr_ach.cpp:269 (32)
    //         0048dcf0     PUSH       0x0
    //         0048dcf2     PUSH       offset DAT_fffffff8
    //         0048dcf4     PUSH       offset DAT_fffffff4
    //         0048dcf6     PUSH       offset DAT_fffffff0
    //         0048dcf8     PUSH       0x1d
    //         0048dcfa     PUSH       0x33
    //         0048dcfc     PUSH       ESI
    //         0048dcfd     PUSH       0x150
    //         0048dd02     LEA        this,[EDI + 0x4]
    //         0048dd05     PUSH       0x0
    //         0048dd07     PUSH       this
    //         0048dd08     PUSH       EBP
    //         0048dd09     MOV        this,EBP
    //         0048dd0b     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //                              scr_ach.cpp:270 (32)
    //         0048dd10     PUSH       0x0
    //         0048dd12     PUSH       offset DAT_fffffff8
    //         0048dd14     PUSH       offset DAT_fffffff4
    //         0048dd16     PUSH       offset DAT_fffffff0
    //         0048dd18     PUSH       0x1d
    //         0048dd1a     PUSH       0x33
    //         0048dd1c     PUSH       ESI
    //         0048dd1d     PUSH       0x185
    //         0048dd22     LEA        EDX,[EDI + 0x8]
    //         0048dd25     PUSH       0x0
    //         0048dd27     PUSH       EDX
    //         0048dd28     PUSH       EBP
    //         0048dd29     MOV        this,EBP
    //         0048dd2b     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //                              scr_ach.cpp:271 (32)
    //         0048dd30     PUSH       0x0
    //         0048dd32     PUSH       offset DAT_fffffff8
    //         0048dd34     PUSH       offset DAT_fffffff4
    //         0048dd36     PUSH       offset DAT_fffffff0
    //         0048dd38     PUSH       0x1d
    //         0048dd3a     PUSH       0x33
    //         0048dd3c     PUSH       ESI
    //         0048dd3d     PUSH       0x1ba
    //         0048dd42     LEA        EAX,[EDI + 0xc]
    //         0048dd45     PUSH       0x0
    //         0048dd47     PUSH       EAX
    //         0048dd48     PUSH       EBP
    //         0048dd49     MOV        this,EBP
    //         0048dd4b     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //                              scr_ach.cpp:272 (32)
    //         0048dd50     PUSH       0x0
    //         0048dd52     PUSH       offset DAT_fffffff8
    //         0048dd54     PUSH       offset DAT_fffffff4
    //         0048dd56     PUSH       offset DAT_fffffff0
    //         0048dd58     PUSH       0x1d
    //         0048dd5a     PUSH       0x33
    //         0048dd5c     PUSH       ESI
    //         0048dd5d     PUSH       0x1ee
    //         0048dd62     LEA        this,[EDI + 0x10]
    //         0048dd65     PUSH       0x0
    //         0048dd67     PUSH       this
    //         0048dd68     PUSH       EBP
    //         0048dd69     MOV        this,EBP
    //         0048dd6b     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //                              scr_ach.cpp:274 (28)
    //         0048dd70     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
    //         0048dd76     MOV        EAX,dword ptr [EDX + 0x3f4]
    //         0048dd7c     MOV        EDX,dword ptr [ESP + 0x14]
    //         0048dd80     MOVSX      this,word ptr [EAX + 0x3c]
    //         0048dd84     CMP        EDX,this
    //         0048dd86     JGE        LAB_0048de3a
    //                              scr_ach.cpp:277 (32)
    //         0048dd8c     MOV        EDX,dword ptr [EAX + 0x40]
    //         0048dd8f     MOV        EAX,dword ptr [ESP + 0x20]
    //         0048dd93     MOV        this,dword ptr [EDX + EAX*0x1]
    //         0048dd96     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0048dd9c     MOVSX      EAX,word ptr [EDX + 0x26]
    //         0048dda0     CMP        EAX,0x7
    //         0048dda3     JA         switchD_0048dda5::default
    //                               switchD_0048dda5::switchD
    //         0048dda5     JMP        dword ptr [EAX*0x4 + switchD_0048dda5::switchd   = 0048ddac
    //                               switchD_0048dda5::caseD_0                                    XREF[2]:     0048dda5(j), 0048e1c8(*)  
    //                              scr_ach.cpp:279 (10)
    //         0048ddac     MOV        dword ptr [ESP + 0x10],0xc40000
    //         0048ddb4     JMP        LAB_0048de04
    //                               switchD_0048dda5::caseD_1                                    XREF[2]:     0048dda5(j), 0048e1cc(*)  
    //                              scr_ach.cpp:280 (10)
    //         0048ddb6     MOV        dword ptr [ESP + 0x10],0xc8
    //         0048ddbe     JMP        LAB_0048de04
    //                               switchD_0048dda5::caseD_2                                    XREF[2]:     0048dda5(j), 0048e1d0(*)  
    //                              scr_ach.cpp:281 (10)
    //         0048ddc0     MOV        dword ptr [ESP + 0x10],0xeaea
    //         0048ddc8     JMP        LAB_0048de04
    //                               switchD_0048dda5::caseD_3                                    XREF[2]:     0048dda5(j), 0048e1d4(*)  
    //                              scr_ach.cpp:282 (10)
    //         0048ddca     MOV        dword ptr [ESP + 0x10],0x215a8c
    //         0048ddd2     JMP        LAB_0048de04
    //                               switchD_0048dda5::caseD_4                                    XREF[2]:     0048dda5(j), 0048e1d8(*)  
    //                              scr_ach.cpp:283 (10)
    //         0048ddd4     MOV        dword ptr [ESP + 0x10],0x80ff
    //         0048dddc     JMP        LAB_0048de04
    //                               switchD_0048dda5::caseD_5                                    XREF[2]:     0048dda5(j), 0048e1dc(*)  
    //                              scr_ach.cpp:284 (10)
    //         0048ddde     MOV        dword ptr [ESP + 0x10],0x8000
    //         0048dde6     JMP        LAB_0048de04
    //                               switchD_0048dda5::caseD_6                                    XREF[2]:     0048dda5(j), 0048e1e0(*)  
    //                              scr_ach.cpp:285 (10)
    //         0048dde8     MOV        dword ptr [ESP + 0x10],pathSystem.MGP_openPath
    //         0048ddf0     JMP        LAB_0048de04
    //                               switchD_0048dda5::caseD_7                                    XREF[2]:     0048dda5(j), 0048e1e4(*)  
    //                              scr_ach.cpp:286 (10)
    //         0048ddf2     MOV        dword ptr [ESP + 0x10],pathSystem.MGP_openPath
    //         0048ddfa     JMP        LAB_0048de04
    //                               switchD_0048dda5::default                                    XREF[1]:     0048dda3(j)  
    //                              scr_ach.cpp:287 (8)
    //         0048ddfc     MOV        dword ptr [ESP + 0x10],0xffffff
    //                               LAB_0048de04                                                 XREF[8]:     0048ddb4(j), 0048ddbe(j), 
    //                                                                                                         0048ddc8(j), 0048ddd2(j), 
    //                                                                                                         0048dddc(j), 0048dde6(j), 
    //                                                                                                         0048ddf0(j), 0048ddfa(j)  
    //                              scr_ach.cpp:289 (26)
    //         0048de04     MOV        this,dword ptr [ESP + 0x1c]
    //         0048de08     MOV        EAX,dword ptr [ESP + 0x10]
    //         0048de0c     PUSH       0x0
    //         0048de0e     PUSH       EAX=>pathSystem.MGP_openPaths[54973].total
    //         0048de0f     MOV        this,dword ptr [this->_padding_]
    //         0048de11     CALL       TTextPanel::set_text_color                       void set_text_color(TTextPanel * this, ulong 
    //         0048de16     MOV        dword ptr [ESP + 0x18],0x7
    //                               LAB_0048de1e                                                 XREF[1]:     0048de38(j)  
    //                              scr_ach.cpp:291 (28)
    //         0048de1e     MOV        EDX,dword ptr [ESP + 0x10]
    //         0048de22     MOV        this,dword ptr [EBX]
    //         0048de24     PUSH       0x0
    //         0048de26     PUSH       EDX=>pathSystem.MGP_openPaths[54973].total
    //         0048de27     CALL       TTextPanel::set_text_color                       void set_text_color(TTextPanel * this, ulong 
    //         0048de2c     MOV        EAX,dword ptr [ESP + 0x18]
    //         0048de30     ADD        EBX,0x4
    //         0048de33     DEC        EAX
    //         0048de34     MOV        dword ptr [ESP + 0x18],EAX
    //         0048de38     JNZ        LAB_0048de1e
    //                               LAB_0048de3a                                                 XREF[1]:     0048dd86(j)  
    //                              scr_ach.cpp:258 (50)
    //         0048de3a     MOV        EDX,dword ptr [ESP + 0x20]
    //         0048de3e     MOV        this,dword ptr [ESP + 0x1c]
    //         0048de42     MOV        EAX,0x4
    //         0048de47     ADD        ESI,0x1e
    //         0048de4a     ADD        EDX,EAX
    //         0048de4c     ADD        this,EAX
    //         0048de4e     MOV        EAX,dword ptr [ESP + 0x14]
    //         0048de52     ADD        EDI,0x1c
    //         0048de55     INC        EAX
    //         0048de56     MOV        dword ptr [ESP + 0x20],EDX
    //         0048de5a     MOV        dword ptr [ESP + 0x14],EAX
    //         0048de5e     DEC        EAX
    //         0048de5f     CMP        EAX,0x8
    //         0048de62     MOV        dword ptr [ESP + 0x1c],this
    //         0048de66     JL         LAB_0048dc4a
    //                              scr_ach.cpp:296 (33)
    //         0048de6c     MOV        EAX,dword ptr [EBP + 0x478]
    //         0048de72     TEST       EAX,EAX
    //         0048de74     JZ         LAB_0048dfa3
    //         0048de7a     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0048de80     CALL       RGE_Base_Game::singlePlayerGame                  int singlePlayerGame(RGE_Base_Game * this)
    //         0048de85     TEST       EAX,EAX
    //         0048de87     JZ         LAB_0048dfa3
    //                              scr_ach.cpp:298 (6)
    //         0048de8d     MOV        EAX,dword ptr [EBP + 0x490]
    //                              scr_ach.cpp:300 (50)
    //         0048de93     PUSH       0x0
    //         0048de95     PUSH       0x0=>DAT_fffffff8
    //         0048de97     PUSH       0x0=>DAT_fffffff4
    //         0048de99     TEST       EAX,EAX
    //         0048de9b     PUSH       offset DAT_fffffff0
    //         0048de9d     JZ         LAB_0048df3b
    //         0048dea3     PUSH       0x96
    //         0048dea8     PUSH       0x1b9
    //         0048dead     PUSH       0x5
    //         0048deaf     PUSH       0x0
    //         0048deb1     LEA        EAX,[EBP + 0x5e4]
    //                              language.dll match for 0x26b2: "Aftermath"
    //         0048deb7     PUSH       0x26b2
    //         0048debc     PUSH       EAX
    //         0048debd     PUSH       EBP
    //         0048debe     MOV        this,EBP
    //         0048dec0     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //                              scr_ach.cpp:301 (45)
    //         0048dec5     PUSH       0x0
    //         0048dec7     PUSH       0x0=>DAT_fffffff8
    //         0048dec9     PUSH       0x0=>DAT_fffffff4
    //         0048decb     PUSH       offset DAT_fffffff0
    //         0048decd     PUSH       0x96
    //         0048ded2     PUSH       0x1b9
    //         0048ded7     PUSH       0xa5
    //         0048dedc     PUSH       0x0
    //         0048dede     LEA        EAX,[EBP + 0x5e0]
    //                              language.dll match for 0x26d8: "Timeline"
    //         0048dee4     PUSH       0x26d8
    //         0048dee9     PUSH       EAX
    //         0048deea     PUSH       EBP
    //         0048deeb     MOV        this,EBP
    //         0048deed     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //                              scr_ach.cpp:302 (45)
    //         0048def2     PUSH       0x0
    //         0048def4     PUSH       0x0=>DAT_fffffff8
    //         0048def6     PUSH       0x0=>DAT_fffffff4
    //         0048def8     PUSH       offset DAT_fffffff0
    //         0048defa     PUSH       0x96
    //         0048deff     PUSH       0x1b9
    //         0048df04     PUSH       0x145
    //         0048df09     PUSH       0x0
    //         0048df0b     LEA        EAX,[EBP + 0x5e8]
    //                              language.dll match for 0x269f: "Restart"
    //         0048df11     PUSH       0x269f
    //         0048df16     PUSH       EAX
    //         0048df17     PUSH       EBP
    //         0048df18     MOV        this,EBP
    //         0048df1a     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //                              scr_ach.cpp:303 (23)
    //         0048df1f     PUSH       0x0
    //         0048df21     PUSH       0x0=>DAT_fffffff8
    //         0048df23     PUSH       0x0=>DAT_fffffff4
    //         0048df25     PUSH       offset DAT_fffffff0
    //         0048df27     PUSH       0x96
    //         0048df2c     PUSH       0x1b9
    //         0048df31     PUSH       0x1e5
    //                              scr_ach.cpp:305 (5)
    //         0048df36     JMP        LAB_0048dfe4
    //                               LAB_0048df3b                                                 XREF[1]:     0048de9d(j)  
    //                              scr_ach.cpp:307 (34)
    //         0048df3b     PUSH       0xb4
    //         0048df40     PUSH       0x1b9
    //         0048df45     PUSH       0x14
    //         0048df47     PUSH       0x0
    //         0048df49     LEA        EAX,[EBP + 0x5e0]
    //                              language.dll match for 0x26d8: "Timeline"
    //         0048df4f     PUSH       0x26d8
    //         0048df54     PUSH       EAX
    //         0048df55     PUSH       EBP
    //         0048df56     MOV        this,EBP
    //         0048df58     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //                              scr_ach.cpp:308 (45)
    //         0048df5d     PUSH       0x0
    //         0048df5f     PUSH       0x0=>DAT_fffffff8
    //         0048df61     PUSH       0x0=>DAT_fffffff4
    //         0048df63     PUSH       offset DAT_fffffff0
    //         0048df65     PUSH       0xb4
    //         0048df6a     PUSH       0x1b9
    //         0048df6f     PUSH       0xe6
    //         0048df74     PUSH       0x0
    //         0048df76     LEA        EAX,[EBP + 0x5e8]
    //                              language.dll match for 0x269f: "Restart"
    //         0048df7c     PUSH       0x269f
    //         0048df81     PUSH       EAX
    //         0048df82     PUSH       EBP
    //         0048df83     MOV        this,EBP
    //         0048df85     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //                              scr_ach.cpp:309 (23)
    //         0048df8a     PUSH       0x0
    //         0048df8c     PUSH       0x0=>DAT_fffffff8
    //         0048df8e     PUSH       0x0=>DAT_fffffff4
    //         0048df90     PUSH       offset DAT_fffffff0
    //         0048df92     PUSH       0xb4
    //         0048df97     PUSH       0x1b9
    //         0048df9c     PUSH       0x1b8
    //                              scr_ach.cpp:312 (2)
    //         0048dfa1     JMP        LAB_0048dfe4
    //                               LAB_0048dfa3                                                 XREF[2]:     0048de74(j), 0048de87(j)  
    //                              scr_ach.cpp:314 (42)
    //         0048dfa3     PUSH       0x0
    //         0048dfa5     PUSH       0x0=>DAT_fffffff8
    //         0048dfa7     PUSH       0x0=>DAT_fffffff4
    //         0048dfa9     PUSH       offset DAT_fffffff0
    //         0048dfab     PUSH       0xc8
    //         0048dfb0     PUSH       0x1b9
    //         0048dfb5     PUSH       0x64
    //         0048dfb7     PUSH       0x0
    //         0048dfb9     LEA        EAX,[EBP + 0x5e0]
    //                              language.dll match for 0x26d8: "Timeline"
    //         0048dfbf     PUSH       0x26d8
    //         0048dfc4     PUSH       EAX
    //         0048dfc5     PUSH       EBP
    //         0048dfc6     MOV        this,EBP
    //         0048dfc8     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //                              scr_ach.cpp:315 (45)
    //         0048dfcd     PUSH       0x0
    //         0048dfcf     PUSH       0x0=>DAT_fffffff8
    //         0048dfd1     PUSH       0x0=>DAT_fffffff4
    //         0048dfd3     PUSH       offset DAT_fffffff0
    //         0048dfd5     PUSH       0xc8
    //         0048dfda     PUSH       0x1b9
    //         0048dfdf     PUSH       0x154
    //                               LAB_0048dfe4                                                 XREF[2]:     0048df36(j), 0048dfa1(j)  
    //         0048dfe4     PUSH       0x0
    //         0048dfe6     LEA        EAX,[EBP + 0x5d4]
    //                              language.dll match for 0x269c: "Close"
    //         0048dfec     PUSH       0x269c
    //         0048dff1     PUSH       EAX
    //         0048dff2     PUSH       EBP
    //         0048dff3     MOV        this,EBP
    //         0048dff5     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //                              scr_ach.cpp:318 (45)
    //         0048dffa     PUSH       0x0
    //         0048dffc     PUSH       0x0=>DAT_fffffff8
    //         0048dffe     PUSH       0x0=>DAT_fffffff4
    //         0048e000     PUSH       offset DAT_fffffff0
    //         0048e002     PUSH       0xf0
    //         0048e007     PUSH       0x1b9
    //         0048e00c     PUSH       0xc8
    //         0048e011     PUSH       0x0
    //         0048e013     LEA        ESI,[EBP + 0x5d8]
    //                              language.dll match for 0x26da: "Back"
    //         0048e019     PUSH       0x26da
    //         0048e01e     PUSH       ESI
    //         0048e01f     PUSH       EBP
    //         0048e020     MOV        this,EBP
    //         0048e022     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //                              scr_ach.cpp:319 (9)
    //         0048e027     MOV        this,dword ptr [ESI]
    //         0048e029     PUSH       0x0
    //         0048e02b     MOV        EAX,dword ptr [this->_padding_]
    //         0048e02d     CALL       dword ptr [EAX + 0x14]
    //                              scr_ach.cpp:320 (2)
    //         0048e030     MOV        EAX,dword ptr [ESI]
    //                              scr_ach.cpp:322 (66)
    //         0048e032     PUSH       0x0
    //         0048e034     PUSH       0x0=>DAT_fffffff8
    //         0048e036     PUSH       0x0=>DAT_fffffff4
    //         0048e038     PUSH       offset DAT_fffffff0
    //         0048e03a     PUSH       0xf0
    //         0048e03f     PUSH       0x1b9
    //         0048e044     PUSH       0xc8
    //         0048e049     PUSH       0x0
    //         0048e04b     LEA        EDI,[EBP + 0x5dc]
    //                              language.dll match for 0x269c: "Close"
    //         0048e051     PUSH       0x269c
    //         0048e056     MOV        EBX,0x1b
    //         0048e05b     PUSH       EDI
    //         0048e05c     PUSH       EBP
    //         0048e05d     MOV        this,EBP
    //         0048e05f     MOV        dword ptr [EAX + 0x298],EBX
    //         0048e065     MOV        dword ptr [EAX + 0x29c],0x0
    //         0048e06f     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //                              scr_ach.cpp:323 (9)
    //         0048e074     MOV        this,dword ptr [EDI]
    //         0048e076     PUSH       0x0
    //         0048e078     MOV        EDX,dword ptr [this->_padding_]
    //         0048e07a     CALL       dword ptr [EDX + 0x14]
    //                              scr_ach.cpp:324 (16)
    //         0048e07d     MOV        EAX,dword ptr [EDI]
    //         0048e07f     XOR        this,this
    //         0048e081     MOV        dword ptr [EAX + 0x298],EBX
    //         0048e087     MOV        dword ptr [EAX + 0x29c],this
    //                              scr_ach.cpp:326 (18)
    //         0048e08d     MOV        EAX,dword ptr [EBP + 0x5d4]
    //         0048e093     MOV        dword ptr [EAX + 0x298],EBX
    //         0048e099     MOV        dword ptr [EAX + 0x29c],this
    //                              scr_ach.cpp:328 (17)
    //         0048e09f     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0048e0a5     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0048e0aa     MOV        this,byte ptr [EAX + 0x80]
    //                              scr_ach.cpp:329 (41)
    //         0048e0b0     PUSH       0x20
    //         0048e0b2     CMP        this,0x1
    //         0048e0b5     JNZ        LAB_0048e0e2
    //         0048e0b7     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0048e0bc     ADD        ESP,0x4
    //         0048e0bf     MOV        dword ptr [ESP + 0x18],EAX
    //         0048e0c3     TEST       EAX,EAX
    //         0048e0c5     MOV        byte ptr [ESP + 0x1ec],0x1
    //         0048e0cd     JZ         LAB_0048e10d
    //         0048e0cf     PUSH       0xcb21
    //         0048e0d4     PUSH       s_viccheck.slp                                   = "viccheck.slp"
    //                              scr_ach.cpp:331 (54)
    //         0048e0d9     MOV        this,EAX
    //         0048e0db     CALL       TShape::TShape                                   undefined TShape(TShape * this, char * param_
    //         0048e0e0     JMP        LAB_0048e10f
    //                               LAB_0048e0e2                                                 XREF[1]:     0048e0b5(j)  
    //         0048e0e2     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0048e0e7     ADD        ESP,0x4
    //         0048e0ea     MOV        dword ptr [ESP + 0x18],EAX
    //         0048e0ee     TEST       EAX,EAX
    //         0048e0f0     MOV        byte ptr [ESP + 0x1ec],0x2
    //         0048e0f8     JZ         LAB_0048e10d
    //         0048e0fa     PUSH       0xcb22
    //         0048e0ff     PUSH       s_defcheck.slp                                   = "defcheck.slp"
    //         0048e104     MOV        this,EAX
    //         0048e106     CALL       TShape::TShape                                   undefined TShape(TShape * this, char * param_
    //         0048e10b     JMP        LAB_0048e10f
    //                               LAB_0048e10d                                                 XREF[2]:     0048e0cd(j), 0048e0f8(j)  
    //         0048e10d     XOR        EAX,EAX
    //                               LAB_0048e10f                                                 XREF[2]:     0048e0e0(j), 0048e10b(j)  
    //                              scr_ach.cpp:337 (26)
    //         0048e10f     MOV        this,dword ptr [EBP + 0x5e4]
    //         0048e115     MOV        dword ptr [EBP + 0x5f0],EAX
    //         0048e11b     XOR        EAX,EAX
    //         0048e11d     MOV        byte ptr [ESP + 0x1ec],0x0
    //         0048e125     TEST       this,this
    //         0048e127     JZ         LAB_0048e132
    //                              scr_ach.cpp:338 (9)
    //         0048e129     MOV        dword ptr [ESP + 0x28],this
    //         0048e12d     MOV        EAX,0x1
    //                               LAB_0048e132                                                 XREF[1]:     0048e127(j)  
    //                              scr_ach.cpp:339 (10)
    //         0048e132     MOV        this,dword ptr [EBP + 0x5e0]
    //         0048e138     TEST       this,this
    //         0048e13a     JZ         LAB_0048e141
    //                              scr_ach.cpp:340 (5)
    //         0048e13c     MOV        dword ptr [ESP + EAX*0x4 + 0x28],this
    //         0048e140     INC        EAX
    //                               LAB_0048e141                                                 XREF[1]:     0048e13a(j)  
    //                              scr_ach.cpp:341 (10)
    //         0048e141     MOV        this,dword ptr [EBP + 0x5e8]
    //         0048e147     TEST       this,this
    //         0048e149     JZ         LAB_0048e150
    //                              scr_ach.cpp:342 (5)
    //         0048e14b     MOV        dword ptr [ESP + EAX*0x4 + 0x28],this
    //         0048e14f     INC        EAX
    //                               LAB_0048e150                                                 XREF[1]:     0048e149(j)  
    //                              scr_ach.cpp:343 (6)
    //         0048e150     MOV        this,dword ptr [EBP + 0x5d4]
    //                              scr_ach.cpp:344 (18)
    //         0048e156     LEA        EDX,[ESP + 0x28]
    //         0048e15a     MOV        dword ptr [ESP + EAX*0x4 + 0x28],this
    //         0048e15e     INC        EAX
    //         0048e15f     PUSH       EAX
    //         0048e160     PUSH       EDX=>DAT_fffffff8
    //         0048e161     MOV        this,EBP
    //         0048e163     CALL       TPanel::set_tab_order                            void set_tab_order(TPanel * this, TPanel * * 
    //                              scr_ach.cpp:345 (14)
    //         0048e168     MOV        EAX,dword ptr [EBP + 0x5d4]
    //         0048e16e     MOV        this,EBP
    //         0048e170     PUSH       EAX
    //         0048e171     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                              scr_ach.cpp:347 (14)
    //         0048e176     MOV        this,dword ptr [ESI]
    //         0048e178     PUSH       0x0
    //         0048e17a     PUSH       0x0=>DAT_fffffff8
    //         0048e17c     MOV        EDX,dword ptr [this->_padding_]
    //         0048e17e     CALL       dword ptr [EDX + 0xc4]
    //                              scr_ach.cpp:348 (14)
    //         0048e184     MOV        this,dword ptr [EDI]
    //         0048e186     PUSH       0x0
    //         0048e188     PUSH       0x0=>DAT_fffffff8
    //         0048e18a     MOV        EAX,dword ptr [this->_padding_]
    //         0048e18c     CALL       dword ptr [EAX + 0xc4]
    //                              scr_ach.cpp:350 (10)
    //         0048e192     MOV        EAX,dword ptr [EBP + 0x490]
    //         0048e198     TEST       EAX,EAX
    //         0048e19a     JZ         LAB_0048e1a0
    //                              scr_ach.cpp:351 (2)
    //         0048e19c     PUSH       0x5
    //                              scr_ach.cpp:352 (2)
    //         0048e19e     JMP        LAB_0048e1a2
    //                               LAB_0048e1a0                                                 XREF[1]:     0048e19a(j)  
    //                              scr_ach.cpp:353 (9)
    //         0048e1a0     PUSH       0x0
    //                               LAB_0048e1a2                                                 XREF[1]:     0048e19e(j)  
    //         0048e1a2     MOV        this,EBP
    //         0048e1a4     CALL       TribeAchievementsScreen::set_mode                void set_mode(TribeAchievementsScreen * this,
    //                               LAB_0048e1a9                                                 XREF[2]:     0048d729(j), 0048d9eb(j)  
    //                              scr_ach.cpp:354 (63)
    //         0048e1a9     MOV        this,dword ptr [ESP + local_c]
    //         0048e1b0     POP        EDI
    //         0048e1b1     MOV        EAX,EBP
    //         0048e1b3     POP        ESI
    //         0048e1b4     POP        EBP
    //         0048e1b5     MOV        dword ptr FS:[0x0],this
    //         0048e1bc     POP        EBX
    //         0048e1bd     ADD        ESP,0x1e0
    //         0048e1c3     RET        0x8
}

// Offset: 0x0048E1C6
undefined FUN_0048e1c6() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0048e1c6()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0048e1c6
    //         0048e1c6     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_0048dda5::switchdataD_0048e1c8                       XREF[1]:     TribeAchievementsScreen:0048dda5(*
}

// Offset: 0x0048E210
void TribeAchievementsScreen(TribeAchievementsScreen* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall TribeAchievementsScreen::~TribeAchievementsScreen(void)                    *
    //                              *********************************************************************************************************
    //                              void __thiscall ~TribeAchievementsScreen(TribeAchievementsScreen * t
    //              void              <VOID>         <RETURN>
    //              TribeAchieveme    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0048e240(W)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0048e22c(W)  
    //                               ??1TribeAchievementsScreen@@UAE@XZ                           XREF[1]:     `vector_deleting_destructor':0048e
    //                               TribeAchievementsScreen::~TribeAchievementsScreen
    //                              scr_ach.cpp:360 (38)
    //         0048e210     PUSH       -0x1
    //         0048e212     PUSH       FUN_0055e868
    //         0048e217     MOV        EAX,FS:[0x0]
    //         0048e21d     PUSH       EAX
    //         0048e21e     MOV        dword ptr FS:[0x0],ESP
    //         0048e225     PUSH       this
    //         0048e226     PUSH       EBX
    //         0048e227     MOV        EBX,this
    //         0048e229     PUSH       EBP
    //         0048e22a     PUSH       ESI
    //         0048e22b     PUSH       EDI
    //         0048e22c     MOV        dword ptr [ESP + local_10],EBX
    //         0048e230     MOV        dword ptr [EBX],TribeAchievementsScreen::`vfta   = 0048e1f0
    //                              scr_ach.cpp:364 (23)
    //         0048e236     PUSH       s_YesNoDialog                                    = 59h
    //         0048e23b     MOV        this,panel_system
    //         0048e240     MOV        dword ptr [ESP + local_4],0x0
    //         0048e248     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_ach.cpp:367 (10)
    //         0048e24d     MOV        ESI,dword ptr [EBX + 0x5f0]
    //         0048e253     TEST       ESI,ESI
    //         0048e255     JZ         LAB_0048e267
    //                              scr_ach.cpp:368 (16)
    //         0048e257     MOV        this,ESI
    //         0048e259     CALL       TShape::~TShape                                  void ~TShape(TShape * this)
    //         0048e25e     PUSH       ESI
    //         0048e25f     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0048e264     ADD        ESP,0x4
    //                               LAB_0048e267                                                 XREF[1]:     0048e255(j)  
    //                              scr_ach.cpp:370 (10)
    //         0048e267     MOV        this,dword ptr [EBX + 0x484]
    //         0048e26d     TEST       this,this
    //         0048e26f     JZ         LAB_0048e277
    //                              scr_ach.cpp:371 (6)
    //         0048e271     MOV        EAX,dword ptr [this->_padding_]
    //         0048e273     PUSH       0x1
    //         0048e275     CALL       dword ptr [EAX]
    //                               LAB_0048e277                                                 XREF[1]:     0048e26f(j)  
    //                              scr_ach.cpp:373 (10)
    //         0048e277     MOV        this,dword ptr [EBX + 0x488]
    //         0048e27d     TEST       this,this
    //         0048e27f     JZ         LAB_0048e287
    //                              scr_ach.cpp:374 (6)
    //         0048e281     MOV        EDX,dword ptr [this->_padding_]
    //         0048e283     PUSH       0x1
    //         0048e285     CALL       dword ptr [EDX]
    //                               LAB_0048e287                                                 XREF[1]:     0048e27f(j)  
    //                              scr_ach.cpp:376 (10)
    //         0048e287     MOV        this,dword ptr [EBX + 0x494]
    //         0048e28d     TEST       this,this
    //         0048e28f     JZ         LAB_0048e297
    //                              scr_ach.cpp:377 (6)
    //         0048e291     MOV        EAX,dword ptr [this->_padding_]
    //         0048e293     PUSH       0x1
    //         0048e295     CALL       dword ptr [EAX]
    //                               LAB_0048e297                                                 XREF[1]:     0048e28f(j)  
    //                              scr_ach.cpp:379 (10)
    //         0048e297     MOV        this,dword ptr [EBX + 0x490]
    //         0048e29d     TEST       this,this
    //         0048e29f     JZ         LAB_0048e2a7
    //                              scr_ach.cpp:380 (6)
    //         0048e2a1     MOV        EDX,dword ptr [this->_padding_]
    //         0048e2a3     PUSH       0x1
    //         0048e2a5     CALL       dword ptr [EDX]
    //                               LAB_0048e2a7                                                 XREF[1]:     0048e29f(j)  
    //                              scr_ach.cpp:382 (10)
    //         0048e2a7     MOV        this,dword ptr [EBX + 0x48c]
    //         0048e2ad     TEST       this,this
    //         0048e2af     JZ         LAB_0048e2b7
    //                              scr_ach.cpp:383 (6)
    //         0048e2b1     MOV        EAX,dword ptr [this->_padding_]
    //         0048e2b3     PUSH       0x1
    //         0048e2b5     CALL       dword ptr [EAX]
    //                               LAB_0048e2b7                                                 XREF[1]:     0048e2af(j)  
    //                              scr_ach.cpp:385 (10)
    //         0048e2b7     MOV        this,dword ptr [EBX + 0x5e8]
    //         0048e2bd     TEST       this,this
    //         0048e2bf     JZ         LAB_0048e2c7
    //                              scr_ach.cpp:386 (6)
    //         0048e2c1     MOV        EDX,dword ptr [this->_padding_]
    //         0048e2c3     PUSH       0x1
    //         0048e2c5     CALL       dword ptr [EDX]
    //                               LAB_0048e2c7                                                 XREF[1]:     0048e2bf(j)  
    //                              scr_ach.cpp:388 (10)
    //         0048e2c7     MOV        this,dword ptr [EBX + 0x5d4]
    //         0048e2cd     TEST       this,this
    //         0048e2cf     JZ         LAB_0048e2d7
    //                              scr_ach.cpp:389 (6)
    //         0048e2d1     MOV        EAX,dword ptr [this->_padding_]
    //         0048e2d3     PUSH       0x1
    //         0048e2d5     CALL       dword ptr [EAX]
    //                               LAB_0048e2d7                                                 XREF[1]:     0048e2cf(j)  
    //                              scr_ach.cpp:391 (10)
    //         0048e2d7     MOV        this,dword ptr [EBX + 0x5d8]
    //         0048e2dd     TEST       this,this
    //         0048e2df     JZ         LAB_0048e2e7
    //                              scr_ach.cpp:392 (6)
    //         0048e2e1     MOV        EDX,dword ptr [this->_padding_]
    //         0048e2e3     PUSH       0x1
    //         0048e2e5     CALL       dword ptr [EDX]
    //                               LAB_0048e2e7                                                 XREF[1]:     0048e2df(j)  
    //                              scr_ach.cpp:394 (10)
    //         0048e2e7     MOV        this,dword ptr [EBX + 0x5dc]
    //         0048e2ed     TEST       this,this
    //         0048e2ef     JZ         LAB_0048e2f7
    //                              scr_ach.cpp:395 (6)
    //         0048e2f1     MOV        EAX,dword ptr [this->_padding_]
    //         0048e2f3     PUSH       0x1
    //         0048e2f5     CALL       dword ptr [EAX]
    //                               LAB_0048e2f7                                                 XREF[1]:     0048e2ef(j)  
    //                              scr_ach.cpp:397 (10)
    //         0048e2f7     MOV        this,dword ptr [EBX + 0x5e4]
    //         0048e2fd     TEST       this,this
    //         0048e2ff     JZ         LAB_0048e307
    //                              scr_ach.cpp:398 (6)
    //         0048e301     MOV        EDX,dword ptr [this->_padding_]
    //         0048e303     PUSH       0x1
    //         0048e305     CALL       dword ptr [EDX]
    //                               LAB_0048e307                                                 XREF[1]:     0048e2ff(j)  
    //                              scr_ach.cpp:400 (10)
    //         0048e307     MOV        this,dword ptr [EBX + 0x5e0]
    //         0048e30d     TEST       this,this
    //         0048e30f     JZ         LAB_0048e317
    //                              scr_ach.cpp:401 (6)
    //         0048e311     MOV        EAX,dword ptr [this->_padding_]
    //         0048e313     PUSH       0x1
    //         0048e315     CALL       dword ptr [EAX]
    //                               LAB_0048e317                                                 XREF[1]:     0048e30f(j)  
    //                              scr_ach.cpp:403 (10)
    //         0048e317     MOV        this,dword ptr [EBX + 0x5f4]
    //         0048e31d     TEST       this,this
    //         0048e31f     JZ         LAB_0048e327
    //                              scr_ach.cpp:404 (6)
    //         0048e321     MOV        EDX,dword ptr [this->_padding_]
    //         0048e323     PUSH       0x1
    //         0048e325     CALL       dword ptr [EDX]
    //                               LAB_0048e327                                                 XREF[1]:     0048e31f(j)  
    //                              scr_ach.cpp:406 (10)
    //         0048e327     MOV        this,dword ptr [EBX + 0x5d0]
    //         0048e32d     TEST       this,this
    //         0048e32f     JZ         LAB_0048e337
    //                              scr_ach.cpp:407 (6)
    //         0048e331     MOV        EAX,dword ptr [this->_padding_]
    //         0048e333     PUSH       0x1
    //         0048e335     CALL       dword ptr [EAX]
    //                               LAB_0048e337                                                 XREF[1]:     0048e32f(j)  
    //                              scr_ach.cpp:409 (10)
    //         0048e337     MOV        this,dword ptr [EBX + 0x5c8]
    //         0048e33d     TEST       this,this
    //         0048e33f     JZ         LAB_0048e347
    //                              scr_ach.cpp:410 (6)
    //         0048e341     MOV        EDX,dword ptr [this->_padding_]
    //         0048e343     PUSH       0x1
    //         0048e345     CALL       dword ptr [EDX]
    //                               LAB_0048e347                                                 XREF[1]:     0048e33f(j)  
    //                              scr_ach.cpp:412 (10)
    //         0048e347     MOV        this,dword ptr [EBX + 0x5cc]
    //         0048e34d     TEST       this,this
    //         0048e34f     JZ         LAB_0048e357
    //                              scr_ach.cpp:413 (6)
    //         0048e351     MOV        EAX,dword ptr [this->_padding_]
    //         0048e353     PUSH       0x1
    //         0048e355     CALL       dword ptr [EAX]
    //                               LAB_0048e357                                                 XREF[1]:     0048e34f(j)  
    //                              scr_ach.cpp:415 (25)
    //         0048e357     LEA        this,[EBX + 0x5ec]
    //         0048e35d     PUSH       this
    //         0048e35e     MOV        this,EBX
    //         0048e360     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         0048e365     LEA        ESI,[EBX + 0x498]
    //         0048e36b     MOV        EDI,0x7
    //                               LAB_0048e370                                                 XREF[1]:     0048e380(j)  
    //                              scr_ach.cpp:419 (6)
    //         0048e370     MOV        this,dword ptr [ESI]
    //         0048e372     TEST       this,this
    //         0048e374     JZ         LAB_0048e37c
    //                              scr_ach.cpp:420 (12)
    //         0048e376     MOV        EDX,dword ptr [this->_padding_]
    //         0048e378     PUSH       0x1
    //         0048e37a     CALL       dword ptr [EDX]
    //                               LAB_0048e37c                                                 XREF[1]:     0048e374(j)  
    //         0048e37c     ADD        ESI,0x4
    //         0048e37f     DEC        EDI
    //         0048e380     JNZ        LAB_0048e370
    //                              scr_ach.cpp:435 (58)
    //         0048e382     LEA        ESI,[EBX + 0x4b4]
    //         0048e388     MOV        EDI,0x5
    //                               LAB_0048e38d                                                 XREF[1]:     0048e39d(j)  
    //         0048e38d     MOV        this,dword ptr [ESI]
    //         0048e38f     TEST       this,this
    //         0048e391     JZ         LAB_0048e399
    //         0048e393     MOV        EAX,dword ptr [this->_padding_]
    //         0048e395     PUSH       0x1
    //         0048e397     CALL       dword ptr [EAX]
    //                               LAB_0048e399                                                 XREF[1]:     0048e391(j)  
    //         0048e399     ADD        ESI,0x4
    //         0048e39c     DEC        EDI
    //         0048e39d     JNZ        LAB_0048e38d
    //         0048e39f     LEA        ESI,[EBX + 0x4c8]
    //         0048e3a5     ADD        EBX,0x5a8
    //         0048e3ab     MOV        EBP,0x8
    //                               LAB_0048e3b0                                                 XREF[1]:     0048e3d7(j)  
    //         0048e3b0     MOV        this,dword ptr [EBX]
    //         0048e3b2     TEST       this,this
    //         0048e3b4     JZ         LAB_0048e3bc
    //         0048e3b6     MOV        EDX,dword ptr [this->_padding_]
    //         0048e3b8     PUSH       0x1
    //         0048e3ba     CALL       dword ptr [EDX]
    //                               LAB_0048e3bc                                                 XREF[1]:     0048e3b4(j)  
    //                              scr_ach.cpp:431 (5)
    //         0048e3bc     MOV        EDI,0x7
    //                               LAB_0048e3c1                                                 XREF[1]:     0048e3d1(j)  
    //                              scr_ach.cpp:432 (6)
    //         0048e3c1     MOV        this,dword ptr [ESI]
    //         0048e3c3     TEST       this,this
    //         0048e3c5     JZ         LAB_0048e3cd
    //                              scr_ach.cpp:433 (22)
    //         0048e3c7     MOV        EAX,dword ptr [this->_padding_]
    //         0048e3c9     PUSH       0x1
    //         0048e3cb     CALL       dword ptr [EAX]
    //                               LAB_0048e3cd                                                 XREF[1]:     0048e3c5(j)  
    //         0048e3cd     ADD        ESI,0x4
    //         0048e3d0     DEC        EDI
    //         0048e3d1     JNZ        LAB_0048e3c1
    //         0048e3d3     ADD        EBX,0x4
    //         0048e3d6     DEC        EBP
    //         0048e3d7     JNZ        LAB_0048e3b0
    //         0048e3d9     MOV        this,dword ptr [ESP + 0x10]
    //                              scr_ach.cpp:435 (32)
    //         0048e3dd     MOV        dword ptr [ESP + 0x1c],0xffffffff
    //         0048e3e5     CALL       TScreenPanel::~TScreenPanel                      void ~TScreenPanel(TScreenPanel * this)
    //         0048e3ea     MOV        this,dword ptr [ESP + 0x14]
    //         0048e3ee     POP        EDI
    //         0048e3ef     POP        ESI
    //         0048e3f0     POP        EBP
    //         0048e3f1     MOV        dword ptr FS:[0x0],this
    //         0048e3f8     POP        EBX
    //         0048e3f9     ADD        ESP,0x10
    //         0048e3fc     RET
}

// Offset: 0x0048E400
void set_mode(TribeAchievementsScreen* this_, long param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall TribeAchievementsScreen::set_mode(long)                                    *
    //                              *********************************************************************************************************
    //                              void __thiscall set_mode(TribeAchievementsScreen * this, long param_1)
    //              void              <VOID>         <RETURN>
    //              TribeAchieveme    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     0048e456(R)  
    //              undefined1        Stack[-0x3]:1  local_3                   XREF[1]:     0048e435(W)  
    //              undefined2        Stack[-0x5]:2  local_5                   XREF[1]:     0048e430(W)  
    //              char[50]          Stack[-0x38]   temptxt                   XREF[0,4]:   0048e41b(W), 0048e420(W), 0048e428(W), 0048e42c(W)  
    //              undefined4        Stack[-0x3c]:4 local_3c                  XREF[1]:     0048e424(W)  
    //              long              Stack[-0x40]:4 player_num
    //                               ?set_mode@TribeAchievementsScreen@@IAEXJ@Z                   XREF[8]:     TribeAchievementsScreen:0048e1a4(c
    //                               TribeAchievementsScreen::set_mode                                         handle_mouse_down:0048f1de(c), 
    //                                                                                                         handle_mouse_down:0048f204(c), 
    //                                                                                                         handle_mouse_down:0048f22a(c), 
    //                                                                                                         handle_mouse_down:0048f264(c), 
    //                                                                                                         action:0048f333(c), 
    //                                                                                                         action:0048f3ae(c), 
    //                                                                                                         action:0048f431(c)  
    //                              scr_ach.cpp:441 (6)
    //         0048e400     SUB        ESP,0x3c
    //         0048e403     PUSH       EBX
    //         0048e404     MOV        EBX,this
    //                              scr_ach.cpp:444 (8)
    //         0048e406     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0048e40c     PUSH       EBP
    //         0048e40d     PUSH       ESI
    //                              scr_ach.cpp:447 (43)
    //         0048e40e     XOR        EDX,EDX
    //         0048e410     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         0048e416     PUSH       EDI
    //         0048e417     MOVSX      ESI,word ptr [EAX + 0x3c]
    //         0048e41b     MOV        dword ptr [ESP + temptxt[35]],EDX
    //         0048e41f     DEC        ESI
    //         0048e420     MOV        dword ptr [ESP + temptxt[39]],EDX
    //         0048e424     MOV        dword ptr [ESP + local_3c],ESI
    //         0048e428     MOV        dword ptr [ESP + temptxt[43]],EDX
    //         0048e42c     MOV        dword ptr [ESP + temptxt[47]],EDX
    //         0048e430     MOV        word ptr [ESP + local_5],DX
    //         0048e435     MOV        byte ptr [ESP + local_3],DL
    //                              scr_ach.cpp:449 (5)
    //         0048e439     CALL       RGE_Base_Game::disable_input                     void disable_input(RGE_Base_Game * this)
    //                              scr_ach.cpp:451 (12)
    //         0048e43e     MOV        this,dword ptr [EBX + 0x490]
    //         0048e444     XOR        EBP,EBP
    //         0048e446     CMP        this,EBP
    //         0048e448     JZ         LAB_0048e450
    //                              scr_ach.cpp:452 (6)
    //         0048e44a     MOV        EAX,dword ptr [this->_padding_]
    //         0048e44c     PUSH       EBP
    //         0048e44d     CALL       dword ptr [EAX + 0x14]
    //                               LAB_0048e450                                                 XREF[1]:     0048e448(j)  
    //                              scr_ach.cpp:457 (22)
    //         0048e450     MOV        this,dword ptr [EBX + 0x5f4]
    //         0048e456     MOV        EDI,dword ptr [ESP + param_1]
    //         0048e45a     PUSH       EBP
    //         0048e45b     MOV        dword ptr [EBX + 0x47c],EDI
    //         0048e461     MOV        EDX,dword ptr [this->_padding_]
    //         0048e463     CALL       dword ptr [EDX + 0x14]
    //                              scr_ach.cpp:458 (12)
    //         0048e466     MOV        this,dword ptr [EBX + 0x48c]
    //         0048e46c     PUSH       EBP
    //         0048e46d     MOV        EAX,dword ptr [this->_padding_]
    //         0048e46f     CALL       dword ptr [EAX + 0x14]
    //                              scr_ach.cpp:460 (13)
    //         0048e472     MOV        this,dword ptr [EBX + 0x494]
    //         0048e478     PUSH       0x1
    //         0048e47a     MOV        EDX,dword ptr [this->_padding_]
    //         0048e47c     CALL       dword ptr [EDX + 0x14]
    //                              scr_ach.cpp:462 (10)
    //         0048e47f     MOV        this,dword ptr [EBX + 0x5e8]
    //         0048e485     CMP        this,EBP
    //         0048e487     JZ         LAB_0048e48f
    //                              scr_ach.cpp:463 (6)
    //         0048e489     MOV        EAX,dword ptr [this->_padding_]
    //         0048e48b     PUSH       EBP
    //         0048e48c     CALL       dword ptr [EAX + 0x14]
    //                               LAB_0048e48f                                                 XREF[1]:     0048e487(j)  
    //                              scr_ach.cpp:465 (10)
    //         0048e48f     MOV        this,dword ptr [EBX + 0x5d4]
    //         0048e495     CMP        this,EBP
    //         0048e497     JZ         LAB_0048e49f
    //                              scr_ach.cpp:466 (6)
    //         0048e499     MOV        EDX,dword ptr [this->_padding_]
    //         0048e49b     PUSH       EBP
    //         0048e49c     CALL       dword ptr [EDX + 0x14]
    //                               LAB_0048e49f                                                 XREF[1]:     0048e497(j)  
    //                              scr_ach.cpp:468 (10)
    //         0048e49f     MOV        this,dword ptr [EBX + 0x5e4]
    //         0048e4a5     CMP        this,EBP
    //         0048e4a7     JZ         LAB_0048e4af
    //                              scr_ach.cpp:469 (6)
    //         0048e4a9     MOV        EAX,dword ptr [this->_padding_]
    //         0048e4ab     PUSH       EBP
    //         0048e4ac     CALL       dword ptr [EAX + 0x14]
    //                               LAB_0048e4af                                                 XREF[1]:     0048e4a7(j)  
    //                              scr_ach.cpp:471 (10)
    //         0048e4af     MOV        this,dword ptr [EBX + 0x5e0]
    //         0048e4b5     CMP        this,EBP
    //         0048e4b7     JZ         LAB_0048e4bf
    //                              scr_ach.cpp:472 (6)
    //         0048e4b9     MOV        EDX,dword ptr [this->_padding_]
    //         0048e4bb     PUSH       EBP
    //         0048e4bc     CALL       dword ptr [EDX + 0x14]
    //                               LAB_0048e4bf                                                 XREF[1]:     0048e4b7(j)  
    //                              scr_ach.cpp:474 (10)
    //         0048e4bf     MOV        this,dword ptr [EBX + 0x5d8]
    //         0048e4c5     CMP        this,EBP
    //         0048e4c7     JZ         LAB_0048e4d0
    //                              scr_ach.cpp:475 (7)
    //         0048e4c9     MOV        EAX,dword ptr [this->_padding_]
    //         0048e4cb     PUSH       0x1
    //         0048e4cd     CALL       dword ptr [EAX + 0x14]
    //                               LAB_0048e4d0                                                 XREF[1]:     0048e4c7(j)  
    //                              scr_ach.cpp:477 (10)
    //         0048e4d0     MOV        this,dword ptr [EBX + 0x5dc]
    //         0048e4d6     CMP        this,EBP
    //         0048e4d8     JZ         LAB_0048e4e0
    //                              scr_ach.cpp:478 (6)
    //         0048e4da     MOV        EDX,dword ptr [this->_padding_]
    //         0048e4dc     PUSH       EBP
    //         0048e4dd     CALL       dword ptr [EDX + 0x14]
    //                               LAB_0048e4e0                                                 XREF[1]:     0048e4d8(j)  
    //                              scr_ach.cpp:480 (14)
    //         0048e4e0     MOV        EAX,dword ptr [EBX + 0x5d8]
    //         0048e4e6     MOV        this,EBX
    //         0048e4e8     PUSH       EAX
    //         0048e4e9     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                              scr_ach.cpp:483 (21)
    //         0048e4ee     CMP        EDI,0x6
    //         0048e4f1     MOV        EAX,0x7
    //         0048e4f6     JA         switchD_0048e4fc::default
    //                               switchD_0048e4fc::switchD
    //         0048e4fc     JMP        dword ptr [EDI*0x4 + switchD_0048e4fc::switchd   = 0048e503
    //                               switchD_0048e4fc::caseD_0                                    XREF[2]:     0048e4fc(j), 0048f088(*)  
    //                              scr_ach.cpp:488 (20)
    //         0048e503     MOV        this,dword ptr [EBX + 0x5d4]
    //         0048e509     MOV        dword ptr [EBX + 0x480],EAX
    //         0048e50f     PUSH       this
    //         0048e510     MOV        this,EBX
    //         0048e512     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                              scr_ach.cpp:490 (10)
    //         0048e517     MOV        this,dword ptr [EBX + 0x5e8]
    //         0048e51d     CMP        this,EBP
    //         0048e51f     JZ         LAB_0048e528
    //                              scr_ach.cpp:491 (7)
    //         0048e521     MOV        EDX,dword ptr [this->_padding_]
    //         0048e523     PUSH       0x1
    //         0048e525     CALL       dword ptr [EDX + 0x14]
    //                               LAB_0048e528                                                 XREF[1]:     0048e51f(j)  
    //                              scr_ach.cpp:493 (10)
    //         0048e528     MOV        this,dword ptr [EBX + 0x5d4]
    //         0048e52e     CMP        this,EBP
    //         0048e530     JZ         LAB_0048e539
    //                              scr_ach.cpp:494 (7)
    //         0048e532     MOV        EAX,dword ptr [this->_padding_]
    //         0048e534     PUSH       0x1
    //         0048e536     CALL       dword ptr [EAX + 0x14]
    //                               LAB_0048e539                                                 XREF[1]:     0048e530(j)  
    //                              scr_ach.cpp:496 (10)
    //         0048e539     MOV        this,dword ptr [EBX + 0x5e4]
    //         0048e53f     CMP        this,EBP
    //         0048e541     JZ         LAB_0048e54a
    //                              scr_ach.cpp:497 (7)
    //         0048e543     MOV        EDX,dword ptr [this->_padding_]
    //         0048e545     PUSH       0x1
    //         0048e547     CALL       dword ptr [EDX + 0x14]
    //                               LAB_0048e54a                                                 XREF[1]:     0048e541(j)  
    //                              scr_ach.cpp:499 (10)
    //         0048e54a     MOV        this,dword ptr [EBX + 0x5e0]
    //         0048e550     CMP        this,EBP
    //         0048e552     JZ         LAB_0048e55b
    //                              scr_ach.cpp:500 (7)
    //         0048e554     MOV        EAX,dword ptr [this->_padding_]
    //         0048e556     PUSH       0x1
    //         0048e558     CALL       dword ptr [EAX + 0x14]
    //                               LAB_0048e55b                                                 XREF[1]:     0048e552(j)  
    //                              scr_ach.cpp:502 (10)
    //         0048e55b     MOV        this,dword ptr [EBX + 0x5d8]
    //         0048e561     CMP        this,EBP
    //         0048e563     JZ         LAB_0048e56b
    //                              scr_ach.cpp:503 (6)
    //         0048e565     MOV        EDX,dword ptr [this->_padding_]
    //         0048e567     PUSH       EBP
    //         0048e568     CALL       dword ptr [EDX + 0x14]
    //                               LAB_0048e56b                                                 XREF[1]:     0048e563(j)  
    //                              scr_ach.cpp:505 (13)
    //         0048e56b     MOV        this,dword ptr [EBX + 0x48c]
    //         0048e571     PUSH       0x1
    //         0048e573     MOV        EAX,dword ptr [this->_padding_]
    //         0048e575     CALL       dword ptr [EAX + 0x14]
    //                              scr_ach.cpp:506 (19)
    //         0048e578     MOV        this,dword ptr [EBX + 0x488]
    //                              language.dll match for 0x26d9: "Summary"
    //         0048e57e     PUSH       0x26d9
    //         0048e583     MOV        EDX,dword ptr [this->_padding_]
    //         0048e585     CALL       dword ptr [EDX + 0xe4]
    //                              scr_ach.cpp:508 (19)
    //         0048e58b     MOV        this,dword ptr [EBX + 0x498]
    //                              language.dll match for 0x26ac: "Military"
    //         0048e591     PUSH       0x26ac
    //         0048e596     MOV        EAX,dword ptr [this->_padding_]
    //         0048e598     CALL       dword ptr [EAX + 0xe4]
    //                              scr_ach.cpp:509 (19)
    //         0048e59e     MOV        this,dword ptr [EBX + 0x49c]
    //                              language.dll match for 0x26ad: "Economy"
    //         0048e5a4     PUSH       0x26ad
    //         0048e5a9     MOV        EDX,dword ptr [this->_padding_]
    //         0048e5ab     CALL       dword ptr [EDX + 0xe4]
    //                              scr_ach.cpp:510 (19)
    //         0048e5b1     MOV        this,dword ptr [EBX + 0x4a0]
    //                              language.dll match for 0x26ae: "Religion"
    //         0048e5b7     PUSH       0x26ae
    //         0048e5bc     MOV        EAX,dword ptr [this->_padding_]
    //         0048e5be     CALL       dword ptr [EAX + 0xe4]
    //                              scr_ach.cpp:511 (19)
    //         0048e5c4     MOV        this,dword ptr [EBX + 0x4a4]
    //                              language.dll match for 0x26af: "Technology"
    //         0048e5ca     PUSH       0x26af
    //         0048e5cf     MOV        EDX,dword ptr [this->_padding_]
    //         0048e5d1     CALL       dword ptr [EDX + 0xe4]
    //                              scr_ach.cpp:512 (19)
    //         0048e5d7     MOV        this,dword ptr [EBX + 0x4a8]
    //                              language.dll match for 0x26d6: "Survival"
    //         0048e5dd     PUSH       0x26d6
    //         0048e5e2     MOV        EAX,dword ptr [this->_padding_]
    //         0048e5e4     CALL       dword ptr [EAX + 0xe4]
    //                              scr_ach.cpp:513 (19)
    //         0048e5ea     MOV        this,dword ptr [EBX + 0x4ac]
    //                              language.dll match for 0x26d7: "Wonder"
    //         0048e5f0     PUSH       0x26d7
    //         0048e5f5     MOV        EDX,dword ptr [this->_padding_]
    //         0048e5f7     CALL       dword ptr [EDX + 0xe4]
    //                              scr_ach.cpp:514 (19)
    //         0048e5fd     MOV        this,dword ptr [EBX + 0x4b0]
    //                              language.dll match for 0x26b1: "Total Score"
    //         0048e603     PUSH       0x26b1
    //         0048e608     MOV        EAX,dword ptr [this->_padding_]
    //         0048e60a     CALL       dword ptr [EAX + 0xe4]
    //                              scr_ach.cpp:517 (23)
    //         0048e610     CMP        ESI,EBP
    //         0048e612     JLE        switchD_0048e4fc::default
    //         0048e618     MOV        EBP,0x4
    //         0048e61d     LEA        EDI,[EBX + 0x4cc]
    //         0048e623     MOV        dword ptr [ESP + 0x50],ESI
    //                               LAB_0048e627                                                 XREF[1]:     0048e771(j)  
    //                              scr_ach.cpp:519 (6)
    //         0048e627     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //                              scr_ach.cpp:521 (35)
    //         0048e62d     PUSH       0xa
    //         0048e62f     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0048e635     LEA        this,[ESP + 0x1c]
    //         0048e639     PUSH       this=>DAT_fffffff8
    //         0048e63a     PUSH       0x0=>DAT_fffffff4
    //         0048e63c     MOV        EAX,dword ptr [EDX + 0x40]
    //         0048e63f     MOV        ESI,dword ptr [EAX + EBP*0x1]
    //         0048e642     MOV        this,dword ptr [ESI + 0x34]
    //         0048e645     CALL       RGE_Victory_Conditions::get_victory_points_group long get_victory_points_group(RGE_Victory_Con
    //         0048e64a     PUSH       EAX=>DAT_fffffff4
    //         0048e64b     CALL       itoa                                             undefined itoa()
    //                              scr_ach.cpp:522 (19)
    //         0048e650     MOV        this,dword ptr [EDI + -0x4]
    //         0048e653     ADD        ESP,0xc
    //         0048e656     LEA        EAX,[ESP + 0x18]
    //         0048e65a     MOV        EDX,dword ptr [this->_padding_]
    //         0048e65c     PUSH       EAX
    //         0048e65d     CALL       dword ptr [EDX + 0xe8]
    //                              scr_ach.cpp:524 (23)
    //         0048e663     LEA        this,[ESP + 0x18]
    //         0048e667     PUSH       0xa
    //         0048e669     PUSH       this=>DAT_fffffff8
    //         0048e66a     MOV        this,dword ptr [ESI + 0x34]
    //         0048e66d     PUSH       offset DAT_fffffff4
    //         0048e66f     CALL       RGE_Victory_Conditions::get_victory_points_group long get_victory_points_group(RGE_Victory_Con
    //         0048e674     PUSH       EAX=>DAT_fffffff4
    //         0048e675     CALL       itoa                                             undefined itoa()
    //                              scr_ach.cpp:525 (18)
    //         0048e67a     MOV        this,dword ptr [EDI]
    //         0048e67c     ADD        ESP,0xc
    //         0048e67f     LEA        EAX,[ESP + 0x18]
    //         0048e683     MOV        EDX,dword ptr [this->_padding_]
    //         0048e685     PUSH       EAX
    //         0048e686     CALL       dword ptr [EDX + 0xe8]
    //                              scr_ach.cpp:527 (23)
    //         0048e68c     LEA        this,[ESP + 0x18]
    //         0048e690     PUSH       0xa
    //         0048e692     PUSH       this=>DAT_fffffff8
    //         0048e693     MOV        this,dword ptr [ESI + 0x34]
    //         0048e696     PUSH       offset DAT_fffffff4
    //         0048e698     CALL       RGE_Victory_Conditions::get_victory_points_group long get_victory_points_group(RGE_Victory_Con
    //         0048e69d     PUSH       EAX=>DAT_fffffff4
    //         0048e69e     CALL       itoa                                             undefined itoa()
    //                              scr_ach.cpp:528 (19)
    //         0048e6a3     MOV        this,dword ptr [EDI + 0x4]
    //         0048e6a6     ADD        ESP,0xc
    //         0048e6a9     LEA        EAX,[ESP + 0x18]
    //         0048e6ad     MOV        EDX,dword ptr [this->_padding_]
    //         0048e6af     PUSH       EAX
    //         0048e6b0     CALL       dword ptr [EDX + 0xe8]
    //                              scr_ach.cpp:530 (23)
    //         0048e6b6     LEA        this,[ESP + 0x18]
    //         0048e6ba     PUSH       0xa
    //         0048e6bc     PUSH       this=>DAT_fffffff8
    //         0048e6bd     MOV        this,dword ptr [ESI + 0x34]
    //         0048e6c0     PUSH       offset DAT_fffffff4
    //         0048e6c2     CALL       RGE_Victory_Conditions::get_victory_points_group long get_victory_points_group(RGE_Victory_Con
    //         0048e6c7     PUSH       EAX=>DAT_fffffff4
    //         0048e6c8     CALL       itoa                                             undefined itoa()
    //                              scr_ach.cpp:531 (19)
    //         0048e6cd     MOV        this,dword ptr [EDI + 0x8]
    //         0048e6d0     ADD        ESP,0xc
    //         0048e6d3     LEA        EAX,[ESP + 0x18]
    //         0048e6d7     MOV        EDX,dword ptr [this->_padding_]
    //         0048e6d9     PUSH       EAX
    //         0048e6da     CALL       dword ptr [EDX + 0xe8]
    //                              scr_ach.cpp:533 (10)
    //         0048e6e0     MOV        this,dword ptr [ESI + 0x34]
    //         0048e6e3     PUSH       0x16
    //         0048e6e5     CALL       RGE_Victory_Conditions::get_victory_points_id    long get_victory_points_id(RGE_Victory_Condit
    //                              scr_ach.cpp:534 (20)
    //         0048e6ea     MOV        this,dword ptr [EDI + 0xc]
    //         0048e6ed     TEST       EAX,EAX
    //         0048e6ef     JLE        LAB_0048e700
    //         0048e6f1     MOV        EDX,dword ptr [this->_padding_]
    //                              language.dll match for 0xfa3: "Yes"
    //         0048e6f3     PUSH       0xfa3
    //         0048e6f8     CALL       dword ptr [EDX + 0xe4]
    //                              scr_ach.cpp:535 (2)
    //         0048e6fe     JMP        LAB_0048e70d
    //                               LAB_0048e700                                                 XREF[1]:     0048e6ef(j)  
    //                              scr_ach.cpp:536 (13)
    //         0048e700     MOV        EAX,dword ptr [this->_padding_]
    //         0048e702     PUSH       s_                                               = ""
    //         0048e707     CALL       dword ptr [EAX + 0xe8]
    //                               LAB_0048e70d                                                 XREF[1]:     0048e6fe(j)  
    //                              scr_ach.cpp:538 (10)
    //         0048e70d     MOV        this,dword ptr [ESI + 0x34]
    //         0048e710     PUSH       0x17
    //         0048e712     CALL       RGE_Victory_Conditions::get_victory_points_id    long get_victory_points_id(RGE_Victory_Condit
    //                              scr_ach.cpp:539 (20)
    //         0048e717     MOV        this,dword ptr [EDI + 0x10]
    //         0048e71a     TEST       EAX,EAX
    //         0048e71c     JLE        LAB_0048e72d
    //         0048e71e     MOV        EDX,dword ptr [this->_padding_]
    //                              language.dll match for 0xfa3: "Yes"
    //         0048e720     PUSH       0xfa3
    //         0048e725     CALL       dword ptr [EDX + 0xe4]
    //                              scr_ach.cpp:540 (2)
    //         0048e72b     JMP        LAB_0048e73a
    //                               LAB_0048e72d                                                 XREF[1]:     0048e71c(j)  
    //                              scr_ach.cpp:541 (13)
    //         0048e72d     MOV        EAX,dword ptr [this->_padding_]
    //         0048e72f     PUSH       s_                                               = ""
    //         0048e734     CALL       dword ptr [EAX + 0xe8]
    //                               LAB_0048e73a                                                 XREF[1]:     0048e72b(j)  
    //                              scr_ach.cpp:543 (21)
    //         0048e73a     LEA        this,[ESP + 0x18]
    //         0048e73e     PUSH       0xa
    //         0048e740     PUSH       this=>DAT_fffffff8
    //         0048e741     MOV        this,dword ptr [ESI + 0x34]
    //         0048e744     CALL       RGE_Victory_Conditions::get_victory_points       long get_victory_points(RGE_Victory_Condition
    //         0048e749     PUSH       EAX=>DAT_fffffff4
    //         0048e74a     CALL       itoa                                             undefined itoa()
    //                              scr_ach.cpp:544 (40)
    //         0048e74f     MOV        this,dword ptr [EDI + 0x14]
    //         0048e752     ADD        ESP,0xc
    //         0048e755     LEA        EAX,[ESP + 0x18]
    //         0048e759     MOV        EDX,dword ptr [this->_padding_]
    //         0048e75b     PUSH       EAX
    //         0048e75c     CALL       dword ptr [EDX + 0xe8]
    //         0048e762     MOV        EAX,dword ptr [ESP + 0x50]
    //         0048e766     ADD        EBP,0x4
    //         0048e769     ADD        EDI,0x1c
    //         0048e76c     DEC        EAX
    //         0048e76d     MOV        dword ptr [ESP + 0x50],EAX
    //         0048e771     JNZ        LAB_0048e627
    //                              scr_ach.cpp:547 (5)
    //         0048e777     JMP        switchD_0048e4fc::default
    //                               switchD_0048e4fc::caseD_1                                    XREF[2]:     0048e4fc(j), 0048f08c(*)  
    //                              scr_ach.cpp:551 (29)
    //         0048e77c     MOV        this,dword ptr [EBX + 0x488]
    //                              language.dll match for 0x26ac: "Military"
    //         0048e782     PUSH       0x26ac
    //         0048e787     MOV        dword ptr [EBX + 0x480],0x6
    //         0048e791     MOV        EDX,dword ptr [this->_padding_]
    //         0048e793     CALL       dword ptr [EDX + 0xe4]
    //                              scr_ach.cpp:552 (19)
    //         0048e799     MOV        this,dword ptr [EBX + 0x498]
    //                              language.dll match for 0x26b6: "Kills"
    //         0048e79f     PUSH       0x26b6
    //         0048e7a4     MOV        EAX,dword ptr [this->_padding_]
    //         0048e7a6     CALL       dword ptr [EAX + 0xe4]
    //                              scr_ach.cpp:553 (19)
    //         0048e7ac     MOV        this,dword ptr [EBX + 0x49c]
    //                              language.dll match for 0x26b7: "Razings"
    //         0048e7b2     PUSH       0x26b7
    //         0048e7b7     MOV        EDX,dword ptr [this->_padding_]
    //         0048e7b9     CALL       dword ptr [EDX + 0xe4]
    //                              scr_ach.cpp:554 (19)
    //         0048e7bf     MOV        this,dword ptr [EBX + 0x4a0]
    //                              language.dll match for 0x26b9: "Losses"
    //         0048e7c5     PUSH       0x26b9
    //         0048e7ca     MOV        EAX,dword ptr [this->_padding_]
    //         0048e7cc     CALL       dword ptr [EAX + 0xe4]
    //                              scr_ach.cpp:555 (19)
    //         0048e7d2     MOV        this,dword ptr [EBX + 0x4a4]
    //                              language.dll match for 0x26b8: "Kills - Losses"
    //         0048e7d8     PUSH       0x26b8
    //         0048e7dd     MOV        EDX,dword ptr [this->_padding_]
    //         0048e7df     CALL       dword ptr [EDX + 0xe4]
    //                              scr_ach.cpp:556 (19)
    //         0048e7e5     MOV        this,dword ptr [EBX + 0x4a8]
    //                              language.dll match for 0x26ba: "Largest Army"
    //         0048e7eb     PUSH       0x26ba
    //         0048e7f0     MOV        EAX,dword ptr [this->_padding_]
    //         0048e7f2     CALL       dword ptr [EAX + 0xe4]
    //                              scr_ach.cpp:557 (19)
    //         0048e7f8     MOV        this,dword ptr [EBX + 0x4ac]
    //                              language.dll match for 0x26b5: "Total Score"
    //         0048e7fe     PUSH       0x26b5
    //         0048e803     MOV        EDX,dword ptr [this->_padding_]
    //         0048e805     CALL       dword ptr [EDX + 0xe4]
    //                              scr_ach.cpp:559 (8)
    //         0048e80b     CMP        ESI,EBP
    //         0048e80d     JLE        switchD_0048e4fc::default
    //                              scr_ach.cpp:744 (240)
    //         0048e813     MOV        EAX,dword ptr [ESP + 0x10]
    //         0048e817     MOV        EBP,0x4
    //         0048e81c     LEA        EDI,[EBX + 0x4cc]
    //         0048e822     MOV        dword ptr [ESP + 0x50],EAX
    //                               LAB_0048e826                                                 XREF[1]:     0048e949(j)  
    //         0048e826     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0048e82c     PUSH       0xa
    //         0048e82e     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0048e834     LEA        this,[ESP + 0x1c]
    //         0048e838     PUSH       this=>DAT_fffffff8
    //         0048e839     PUSH       0x0=>DAT_fffffff4
    //         0048e83b     MOV        EAX,dword ptr [EDX + 0x40]
    //         0048e83e     MOV        ESI,dword ptr [EAX + EBP*0x1]
    //         0048e841     MOV        this,dword ptr [ESI + 0x34]
    //         0048e844     CALL       RGE_Victory_Conditions::get_attribute_id         long get_attribute_id(RGE_Victory_Conditions 
    //         0048e849     PUSH       EAX=>DAT_fffffff4
    //         0048e84a     CALL       itoa                                             undefined itoa()
    //         0048e84f     MOV        this,dword ptr [EDI + -0x4]
    //         0048e852     ADD        ESP,0xc
    //         0048e855     LEA        EAX,[ESP + 0x18]
    //         0048e859     MOV        EDX,dword ptr [this->_padding_]
    //         0048e85b     PUSH       EAX
    //         0048e85c     CALL       dword ptr [EDX + 0xe8]
    //         0048e862     LEA        this,[ESP + 0x18]
    //         0048e866     PUSH       0xa
    //         0048e868     PUSH       this=>DAT_fffffff8
    //         0048e869     MOV        this,dword ptr [ESI + 0x34]
    //         0048e86c     PUSH       offset DAT_fffffff4
    //         0048e86e     CALL       RGE_Victory_Conditions::get_attribute_id         long get_attribute_id(RGE_Victory_Conditions 
    //         0048e873     PUSH       EAX=>DAT_fffffff4
    //         0048e874     CALL       itoa                                             undefined itoa()
    //         0048e879     MOV        this,dword ptr [EDI]
    //         0048e87b     ADD        ESP,0xc
    //         0048e87e     LEA        EAX,[ESP + 0x18]
    //         0048e882     MOV        EDX,dword ptr [this->_padding_]
    //         0048e884     PUSH       EAX
    //         0048e885     CALL       dword ptr [EDX + 0xe8]
    //         0048e88b     MOV        EAX,dword ptr [ESI + 0x50]
    //         0048e88e     LEA        this,[ESP + 0x18]
    //         0048e892     PUSH       0xa
    //         0048e894     PUSH       this=>DAT_fffffff8
    //         0048e895     FLD        float ptr [EAX + 0x4c]
    //         0048e898     FSUB       float ptr [EAX + 0x2c]
    //         0048e89b     CALL       __ftol                                           undefined __ftol()
    //         0048e8a0     PUSH       EAX=>DAT_fffffff4
    //         0048e8a1     CALL       itoa                                             undefined itoa()
    //         0048e8a6     MOV        this,dword ptr [EDI + 0x4]
    //         0048e8a9     ADD        ESP,0xc
    //         0048e8ac     LEA        EAX,[ESP + 0x18]
    //         0048e8b0     MOV        EDX,dword ptr [this->_padding_]
    //         0048e8b2     PUSH       EAX
    //         0048e8b3     CALL       dword ptr [EDX + 0xe8]
    //         0048e8b9     LEA        this,[ESP + 0x18]
    //         0048e8bd     PUSH       0xa
    //         0048e8bf     PUSH       this=>DAT_fffffff8
    //         0048e8c0     MOV        this,dword ptr [ESI + 0x34]
    //         0048e8c3     PUSH       offset DAT_fffffff4
    //         0048e8c5     CALL       RGE_Victory_Conditions::get_attribute_id         long get_attribute_id(RGE_Victory_Conditions 
    //         0048e8ca     PUSH       EAX=>DAT_fffffff4
    //         0048e8cb     CALL       itoa                                             undefined itoa()
    //         0048e8d0     MOV        this,dword ptr [EDI + 0x8]
    //         0048e8d3     ADD        ESP,0xc
    //         0048e8d6     LEA        EAX,[ESP + 0x18]
    //         0048e8da     MOV        EDX,dword ptr [this->_padding_]
    //         0048e8dc     PUSH       EAX
    //         0048e8dd     CALL       dword ptr [EDX + 0xe8]
    //         0048e8e3     MOV        this,dword ptr [ESI + 0x34]
    //         0048e8e6     PUSH       0x3
    //         0048e8e8     CALL       RGE_Victory_Conditions::get_victory_points_id    long get_victory_points_id(RGE_Victory_Condit
    //         0048e8ed     MOV        this,dword ptr [EDI + 0xc]
    //         0048e8f0     TEST       EAX,EAX
    //         0048e8f2     JLE        LAB_0048e903
    //         0048e8f4     MOV        EDX,dword ptr [this->_padding_]
    //                              language.dll match for 0xfa3: "Yes"
    //         0048e8f6     PUSH       0xfa3
    //         0048e8fb     CALL       dword ptr [EDX + 0xe4]
    //         0048e901     JMP        LAB_0048e910
    //                               LAB_0048e903                                                 XREF[1]:     0048e8f2(j)  
    //                              scr_ach.cpp:579 (13)
    //         0048e903     MOV        EAX,dword ptr [this->_padding_]
    //         0048e905     PUSH       s_                                               = ""
    //         0048e90a     CALL       dword ptr [EAX + 0xe8]
    //                               LAB_0048e910                                                 XREF[1]:     0048e901(j)  
    //                              scr_ach.cpp:581 (23)
    //         0048e910     LEA        this,[ESP + 0x18]
    //         0048e914     PUSH       0xa
    //         0048e916     PUSH       this=>DAT_fffffff8
    //         0048e917     MOV        this,dword ptr [ESI + 0x34]
    //         0048e91a     PUSH       0x0=>DAT_fffffff4
    //         0048e91c     CALL       RGE_Victory_Conditions::get_victory_points_group long get_victory_points_group(RGE_Victory_Con
    //         0048e921     PUSH       EAX=>DAT_fffffff4
    //         0048e922     CALL       itoa                                             undefined itoa()
    //                              scr_ach.cpp:582 (40)
    //         0048e927     MOV        this,dword ptr [EDI + 0x10]
    //         0048e92a     ADD        ESP,0xc
    //         0048e92d     LEA        EAX,[ESP + 0x18]
    //         0048e931     MOV        EDX,dword ptr [this->_padding_]
    //         0048e933     PUSH       EAX
    //         0048e934     CALL       dword ptr [EDX + 0xe8]
    //         0048e93a     MOV        EAX,dword ptr [ESP + 0x50]
    //         0048e93e     ADD        EBP,0x4
    //         0048e941     ADD        EDI,0x1c
    //         0048e944     DEC        EAX
    //         0048e945     MOV        dword ptr [ESP + 0x50],EAX
    //         0048e949     JNZ        LAB_0048e826
    //                              scr_ach.cpp:585 (5)
    //         0048e94f     JMP        switchD_0048e4fc::default
    //                               switchD_0048e4fc::caseD_2                                    XREF[2]:     0048e4fc(j), 0048f090(*)  
    //                              scr_ach.cpp:588 (25)
    //         0048e954     MOV        this,dword ptr [EBX + 0x488]
    //                              language.dll match for 0x26ad: "Economy"
    //         0048e95a     PUSH       0x26ad
    //         0048e95f     MOV        dword ptr [EBX + 0x480],EAX
    //         0048e965     MOV        EDX,dword ptr [this->_padding_]
    //         0048e967     CALL       dword ptr [EDX + 0xe4]
    //                              scr_ach.cpp:589 (19)
    //         0048e96d     MOV        this,dword ptr [EBX + 0x498]
    //                              language.dll match for 0x26be: "Gold Collected"
    //         0048e973     PUSH       0x26be
    //         0048e978     MOV        EAX,dword ptr [this->_padding_]
    //         0048e97a     CALL       dword ptr [EAX + 0xe4]
    //                              scr_ach.cpp:590 (19)
    //         0048e980     MOV        this,dword ptr [EBX + 0x49c]
    //                              language.dll match for 0x26bf: "Villager High"
    //         0048e986     PUSH       0x26bf
    //         0048e98b     MOV        EDX,dword ptr [this->_padding_]
    //         0048e98d     CALL       dword ptr [EDX + 0xe4]
    //                              scr_ach.cpp:591 (19)
    //         0048e993     MOV        this,dword ptr [EBX + 0x4a0]
    //                              language.dll match for 0x26c0: "Villager Bonus"
    //         0048e999     PUSH       0x26c0
    //         0048e99e     MOV        EAX,dword ptr [this->_padding_]
    //         0048e9a0     CALL       dword ptr [EAX + 0xe4]
    //                              scr_ach.cpp:592 (19)
    //         0048e9a6     MOV        this,dword ptr [EBX + 0x4a4]
    //                              language.dll match for 0x26c1: "Exploration"
    //         0048e9ac     PUSH       0x26c1
    //         0048e9b1     MOV        EDX,dword ptr [this->_padding_]
    //         0048e9b3     CALL       dword ptr [EDX + 0xe4]
    //                              scr_ach.cpp:593 (19)
    //         0048e9b9     MOV        this,dword ptr [EBX + 0x4a8]
    //                              language.dll match for 0x26c2: "Most Explored"
    //         0048e9bf     PUSH       0x26c2
    //         0048e9c4     MOV        EAX,dword ptr [this->_padding_]
    //         0048e9c6     CALL       dword ptr [EAX + 0xe4]
    //                              scr_ach.cpp:594 (19)
    //         0048e9cc     MOV        this,dword ptr [EBX + 0x4ac]
    //                              language.dll match for 0x26c3: "Tribute Given"
    //         0048e9d2     PUSH       0x26c3
    //         0048e9d7     MOV        EDX,dword ptr [this->_padding_]
    //         0048e9d9     CALL       dword ptr [EDX + 0xe4]
    //                              scr_ach.cpp:595 (19)
    //         0048e9df     MOV        this,dword ptr [EBX + 0x4b0]
    //                              language.dll match for 0x26b5: "Total Score"
    //         0048e9e5     PUSH       0x26b5
    //         0048e9ea     MOV        EAX,dword ptr [this->_padding_]
    //         0048e9ec     CALL       dword ptr [EAX + 0xe4]
    //                              scr_ach.cpp:597 (8)
    //         0048e9f2     CMP        ESI,EBP
    //         0048e9f4     JLE        switchD_0048e4fc::default
    //                              scr_ach.cpp:744 (152)
    //         0048e9fa     MOV        this,dword ptr [ESP + 0x10]
    //         0048e9fe     MOV        EBP,0x4
    //         0048ea03     LEA        ESI,[EBX + 0x4d0]
    //         0048ea09     MOV        dword ptr [ESP + 0x50],this
    //                               LAB_0048ea0d                                                 XREF[1]:     0048eb5c(j)  
    //         0048ea0d     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
    //         0048ea13     PUSH       0xa
    //         0048ea15     MOV        EAX,dword ptr [EDX + 0x3f4]
    //         0048ea1b     LEA        EDX,[ESP + 0x1c]
    //         0048ea1f     PUSH       EDX=>DAT_fffffff8
    //         0048ea20     PUSH       offset DAT_fffffff4
    //         0048ea22     MOV        this,dword ptr [EAX + 0x40]
    //         0048ea25     MOV        EDI,dword ptr [this->_padding_ + EBP*0x1]
    //         0048ea28     MOV        this,dword ptr [EDI + 0x34]
    //         0048ea2b     CALL       RGE_Victory_Conditions::get_attribute_id         long get_attribute_id(RGE_Victory_Conditions 
    //         0048ea30     PUSH       EAX=>DAT_fffffff4
    //         0048ea31     CALL       itoa                                             undefined itoa()
    //         0048ea36     MOV        this,dword ptr [ESI + -0x8]
    //         0048ea39     ADD        ESP,0xc
    //         0048ea3c     LEA        EDX,[ESP + 0x18]
    //         0048ea40     MOV        EAX,dword ptr [this->_padding_]
    //         0048ea42     PUSH       EDX
    //         0048ea43     CALL       dword ptr [EAX + 0xe8]
    //         0048ea49     MOV        this,dword ptr [EDI + 0x34]
    //         0048ea4c     LEA        EAX,[ESP + 0x18]
    //         0048ea50     PUSH       0xa
    //         0048ea52     PUSH       EAX=>DAT_fffffff8
    //         0048ea53     PUSH       offset DAT_fffffff4
    //         0048ea55     CALL       RGE_Victory_Conditions::get_attribute_id         long get_attribute_id(RGE_Victory_Conditions 
    //         0048ea5a     PUSH       EAX=>DAT_fffffff4
    //         0048ea5b     CALL       itoa                                             undefined itoa()
    //         0048ea60     MOV        this,dword ptr [ESI + -0x4]
    //         0048ea63     ADD        ESP,0xc
    //         0048ea66     LEA        EAX,[ESP + 0x18]
    //         0048ea6a     MOV        EDX,dword ptr [this->_padding_]
    //         0048ea6c     PUSH       EAX
    //         0048ea6d     CALL       dword ptr [EDX + 0xe8]
    //         0048ea73     MOV        this,dword ptr [EDI + 0x34]
    //         0048ea76     PUSH       0x6
    //         0048ea78     CALL       RGE_Victory_Conditions::get_victory_points_id    long get_victory_points_id(RGE_Victory_Condit
    //         0048ea7d     MOV        this,dword ptr [ESI]
    //         0048ea7f     TEST       EAX,EAX
    //         0048ea81     JLE        LAB_0048ea92
    //         0048ea83     MOV        EDX,dword ptr [this->_padding_]
    //                              language.dll match for 0xfa3: "Yes"
    //         0048ea85     PUSH       0xfa3
    //         0048ea8a     CALL       dword ptr [EDX + 0xe4]
    //         0048ea90     JMP        LAB_0048ea9f
    //                               LAB_0048ea92                                                 XREF[1]:     0048ea81(j)  
    //                              scr_ach.cpp:610 (13)
    //         0048ea92     MOV        EAX,dword ptr [this->_padding_]
    //         0048ea94     PUSH       s_                                               = ""
    //         0048ea99     CALL       dword ptr [EAX + 0xe8]
    //                               LAB_0048ea9f                                                 XREF[1]:     0048ea90(j)  
    //                              scr_ach.cpp:612 (26)
    //         0048ea9f     MOV        this,dword ptr [EDI + 0x34]
    //         0048eaa2     PUSH       0x7
    //         0048eaa4     CALL       RGE_Victory_Conditions::get_attribute_id         long get_attribute_id(RGE_Victory_Conditions 
    //         0048eaa9     PUSH       EAX
    //         0048eaaa     LEA        this,[ESP + 0x1c]
    //         0048eaae     PUSH       s_%d%%                                           = "%d%%"
    //         0048eab3     PUSH       this=>DAT_fffffff4
    //         0048eab4     CALL       sprintf                                          undefined sprintf()
    //                              scr_ach.cpp:613 (19)
    //         0048eab9     MOV        this,dword ptr [ESI + 0x4]
    //         0048eabc     ADD        ESP,0xc
    //         0048eabf     LEA        EAX,[ESP + 0x18]
    //         0048eac3     MOV        EDX,dword ptr [this->_padding_]
    //         0048eac5     PUSH       EAX
    //         0048eac6     CALL       dword ptr [EDX + 0xe8]
    //                              scr_ach.cpp:615 (10)
    //         0048eacc     MOV        this,dword ptr [EDI + 0x34]
    //         0048eacf     PUSH       0x8
    //         0048ead1     CALL       RGE_Victory_Conditions::get_victory_points_id    long get_victory_points_id(RGE_Victory_Condit
    //                              scr_ach.cpp:616 (20)
    //         0048ead6     MOV        this,dword ptr [ESI + 0x8]
    //         0048ead9     TEST       EAX,EAX
    //         0048eadb     JLE        LAB_0048eaec
    //         0048eadd     MOV        EDX,dword ptr [this->_padding_]
    //                              language.dll match for 0xfa3: "Yes"
    //         0048eadf     PUSH       0xfa3
    //         0048eae4     CALL       dword ptr [EDX + 0xe4]
    //                              scr_ach.cpp:617 (2)
    //         0048eaea     JMP        LAB_0048eaf9
    //                               LAB_0048eaec                                                 XREF[1]:     0048eadb(j)  
    //                              scr_ach.cpp:618 (13)
    //         0048eaec     MOV        EAX,dword ptr [this->_padding_]
    //         0048eaee     PUSH       s_                                               = ""
    //         0048eaf3     CALL       dword ptr [EAX + 0xe8]
    //                               LAB_0048eaf9                                                 XREF[1]:     0048eaea(j)  
    //                              scr_ach.cpp:620 (23)
    //         0048eaf9     LEA        this,[ESP + 0x18]
    //         0048eafd     PUSH       0xa
    //         0048eaff     PUSH       this=>DAT_fffffff8
    //         0048eb00     MOV        this,dword ptr [EDI + 0x34]
    //         0048eb03     PUSH       offset DAT_fffffff4
    //         0048eb05     CALL       RGE_Victory_Conditions::get_attribute_id         long get_attribute_id(RGE_Victory_Conditions 
    //         0048eb0a     PUSH       EAX=>DAT_fffffff4
    //         0048eb0b     CALL       itoa                                             undefined itoa()
    //                              scr_ach.cpp:621 (19)
    //         0048eb10     MOV        this,dword ptr [ESI + 0xc]
    //         0048eb13     ADD        ESP,0xc
    //         0048eb16     LEA        EAX,[ESP + 0x18]
    //         0048eb1a     MOV        EDX,dword ptr [this->_padding_]
    //         0048eb1c     PUSH       EAX
    //         0048eb1d     CALL       dword ptr [EDX + 0xe8]
    //                              scr_ach.cpp:623 (23)
    //         0048eb23     LEA        this,[ESP + 0x18]
    //         0048eb27     PUSH       0xa
    //         0048eb29     PUSH       this=>DAT_fffffff8
    //         0048eb2a     MOV        this,dword ptr [EDI + 0x34]
    //         0048eb2d     PUSH       offset DAT_fffffff4
    //         0048eb2f     CALL       RGE_Victory_Conditions::get_victory_points_group long get_victory_points_group(RGE_Victory_Con
    //         0048eb34     PUSH       EAX=>DAT_fffffff4
    //         0048eb35     CALL       itoa                                             undefined itoa()
    //                              scr_ach.cpp:624 (40)
    //         0048eb3a     MOV        this,dword ptr [ESI + 0x10]
    //         0048eb3d     ADD        ESP,0xc
    //         0048eb40     LEA        EAX,[ESP + 0x18]
    //         0048eb44     MOV        EDX,dword ptr [this->_padding_]
    //         0048eb46     PUSH       EAX
    //         0048eb47     CALL       dword ptr [EDX + 0xe8]
    //         0048eb4d     MOV        EAX,dword ptr [ESP + 0x50]
    //         0048eb51     ADD        EBP,0x4
    //         0048eb54     ADD        ESI,0x1c
    //         0048eb57     DEC        EAX
    //         0048eb58     MOV        dword ptr [ESP + 0x50],EAX
    //         0048eb5c     JNZ        LAB_0048ea0d
    //                              scr_ach.cpp:627 (5)
    //         0048eb62     JMP        switchD_0048e4fc::default
    //                               switchD_0048e4fc::caseD_3                                    XREF[2]:     0048e4fc(j), 0048f094(*)  
    //                              scr_ach.cpp:630 (25)
    //         0048eb67     MOV        this,dword ptr [EBX + 0x488]
    //                              language.dll match for 0x26ae: "Religion"
    //         0048eb6d     PUSH       0x26ae
    //         0048eb72     MOV        dword ptr [EBX + 0x480],EAX
    //         0048eb78     MOV        EDX,dword ptr [this->_padding_]
    //         0048eb7a     CALL       dword ptr [EDX + 0xe4]
    //                              scr_ach.cpp:631 (19)
    //         0048eb80     MOV        this,dword ptr [EBX + 0x498]
    //                              language.dll match for 0x26c6: "Conversions"
    //         0048eb86     PUSH       0x26c6
    //         0048eb8b     MOV        EAX,dword ptr [this->_padding_]
    //         0048eb8d     CALL       dword ptr [EAX + 0xe4]
    //                              scr_ach.cpp:632 (19)
    //         0048eb93     MOV        this,dword ptr [EBX + 0x49c]
    //                              language.dll match for 0x26c7: "Most Conversions"
    //         0048eb99     PUSH       0x26c7
    //         0048eb9e     MOV        EDX,dword ptr [this->_padding_]
    //         0048eba0     CALL       dword ptr [EDX + 0xe4]
    //                              scr_ach.cpp:633 (19)
    //         0048eba6     MOV        this,dword ptr [EBX + 0x4a0]
    //                              language.dll match for 0x26c8: "Ruins"
    //         0048ebac     PUSH       0x26c8
    //         0048ebb1     MOV        EAX,dword ptr [this->_padding_]
    //         0048ebb3     CALL       dword ptr [EAX + 0xe4]
    //                              scr_ach.cpp:634 (19)
    //         0048ebb9     MOV        this,dword ptr [EBX + 0x4a4]
    //                              language.dll match for 0x26c9: "Artifacts"
    //         0048ebbf     PUSH       0x26c9
    //         0048ebc4     MOV        EDX,dword ptr [this->_padding_]
    //         0048ebc6     CALL       dword ptr [EDX + 0xe4]
    //                              scr_ach.cpp:635 (19)
    //         0048ebcc     MOV        this,dword ptr [EBX + 0x4a8]
    //                              language.dll match for 0x26ca: "Temples"
    //         0048ebd2     PUSH       0x26ca
    //         0048ebd7     MOV        EAX,dword ptr [this->_padding_]
    //         0048ebd9     CALL       dword ptr [EAX + 0xe4]
    //                              scr_ach.cpp:636 (19)
    //         0048ebdf     MOV        this,dword ptr [EBX + 0x4ac]
    //                              language.dll match for 0x26dc: "All Artifacts/Ruins."
    //         0048ebe5     PUSH       0x26dc
    //         0048ebea     MOV        EDX,dword ptr [this->_padding_]
    //         0048ebec     CALL       dword ptr [EDX + 0xe4]
    //                              scr_ach.cpp:637 (19)
    //         0048ebf2     MOV        this,dword ptr [EBX + 0x4b0]
    //                              language.dll match for 0x26b5: "Total Score"
    //         0048ebf8     PUSH       0x26b5
    //         0048ebfd     MOV        EAX,dword ptr [this->_padding_]
    //         0048ebff     CALL       dword ptr [EAX + 0xe4]
    //                              scr_ach.cpp:639 (8)
    //         0048ec05     CMP        ESI,EBP
    //         0048ec07     JLE        switchD_0048e4fc::default
    //                              scr_ach.cpp:744 (126)
    //         0048ec0d     MOV        dword ptr [ESP + 0x50],0x4
    //         0048ec15     LEA        EDI,[EBX + 0x4cc]
    //         0048ec1b     MOV        dword ptr [ESP + 0x14],ESI
    //                               LAB_0048ec1f                                                 XREF[1]:     0048ed8f(j)  
    //         0048ec1f     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0048ec25     PUSH       0x0
    //         0048ec27     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0048ec2d     MOV        this,dword ptr [ESP + 0x54]
    //         0048ec31     MOV        EAX,dword ptr [EDX + 0x40]
    //         0048ec34     MOV        ESI,dword ptr [EAX + this->_padding_*0x1]
    //         0048ec37     MOV        this,dword ptr [EBX + 0x5f4]
    //         0048ec3d     MOV        EDX,dword ptr [this->_padding_]
    //         0048ec3f     CALL       dword ptr [EDX + 0x14]
    //         0048ec42     MOV        this,dword ptr [ESI + 0x34]
    //         0048ec45     LEA        EAX,[ESP + 0x18]
    //         0048ec49     PUSH       0xa
    //         0048ec4b     PUSH       EAX=>DAT_fffffff8
    //         0048ec4c     PUSH       offset DAT_fffffff4
    //         0048ec4e     CALL       RGE_Victory_Conditions::get_attribute_id         long get_attribute_id(RGE_Victory_Conditions 
    //         0048ec53     PUSH       EAX=>DAT_fffffff4
    //         0048ec54     CALL       itoa                                             undefined itoa()
    //         0048ec59     MOV        this,dword ptr [EDI + -0x4]
    //         0048ec5c     ADD        ESP,0xc
    //         0048ec5f     LEA        EAX,[ESP + 0x18]
    //         0048ec63     MOV        EDX,dword ptr [this->_padding_]
    //         0048ec65     PUSH       EAX
    //         0048ec66     CALL       dword ptr [EDX + 0xe8]
    //         0048ec6c     MOV        this,dword ptr [ESI + 0x34]
    //         0048ec6f     PUSH       0xb
    //         0048ec71     CALL       RGE_Victory_Conditions::get_victory_points_id    long get_victory_points_id(RGE_Victory_Condit
    //         0048ec76     MOV        this,dword ptr [EDI]
    //         0048ec78     TEST       EAX,EAX
    //         0048ec7a     JLE        LAB_0048ec8b
    //         0048ec7c     MOV        EDX,dword ptr [this->_padding_]
    //                              language.dll match for 0xfa3: "Yes"
    //         0048ec7e     PUSH       0xfa3
    //         0048ec83     CALL       dword ptr [EDX + 0xe4]
    //         0048ec89     JMP        LAB_0048ec98
    //                               LAB_0048ec8b                                                 XREF[1]:     0048ec7a(j)  
    //                              scr_ach.cpp:651 (13)
    //         0048ec8b     MOV        EAX,dword ptr [this->_padding_]
    //         0048ec8d     PUSH       s_                                               = ""
    //         0048ec92     CALL       dword ptr [EAX + 0xe8]
    //                               LAB_0048ec98                                                 XREF[1]:     0048ec89(j)  
    //                              scr_ach.cpp:653 (23)
    //         0048ec98     LEA        this,[ESP + 0x18]
    //         0048ec9c     PUSH       0xa
    //         0048ec9e     PUSH       this=>DAT_fffffff8
    //         0048ec9f     MOV        this,dword ptr [ESI + 0x34]
    //         0048eca2     PUSH       offset DAT_fffffff4
    //         0048eca4     CALL       RGE_Victory_Conditions::get_attribute_id         long get_attribute_id(RGE_Victory_Conditions 
    //         0048eca9     PUSH       EAX=>DAT_fffffff4
    //         0048ecaa     CALL       itoa                                             undefined itoa()
    //                              scr_ach.cpp:654 (19)
    //         0048ecaf     MOV        this,dword ptr [EDI + 0x4]
    //         0048ecb2     ADD        ESP,0xc
    //         0048ecb5     LEA        EAX,[ESP + 0x18]
    //         0048ecb9     MOV        EDX,dword ptr [this->_padding_]
    //         0048ecbb     PUSH       EAX
    //         0048ecbc     CALL       dword ptr [EDX + 0xe8]
    //                              scr_ach.cpp:656 (23)
    //         0048ecc2     LEA        this,[ESP + 0x18]
    //         0048ecc6     PUSH       0xa
    //         0048ecc8     PUSH       this=>DAT_fffffff8
    //         0048ecc9     MOV        this,dword ptr [ESI + 0x34]
    //         0048eccc     PUSH       offset DAT_fffffff4
    //         0048ecce     CALL       RGE_Victory_Conditions::get_attribute_id         long get_attribute_id(RGE_Victory_Conditions 
    //         0048ecd3     PUSH       EAX=>DAT_fffffff4
    //         0048ecd4     CALL       itoa                                             undefined itoa()
    //                              scr_ach.cpp:657 (19)
    //         0048ecd9     MOV        this,dword ptr [EDI + 0x8]
    //         0048ecdc     ADD        ESP,0xc
    //         0048ecdf     LEA        EAX,[ESP + 0x18]
    //         0048ece3     MOV        EDX,dword ptr [this->_padding_]
    //         0048ece5     PUSH       EAX
    //         0048ece6     CALL       dword ptr [EDX + 0xe8]
    //                              scr_ach.cpp:659 (23)
    //         0048ecec     LEA        this,[ESP + 0x18]
    //         0048ecf0     PUSH       0xa
    //         0048ecf2     PUSH       this=>DAT_fffffff8
    //         0048ecf3     MOV        this,dword ptr [ESI + 0x34]
    //         0048ecf6     PUSH       offset DAT_fffffff4
    //         0048ecf8     CALL       RGE_Victory_Conditions::get_attribute_id         long get_attribute_id(RGE_Victory_Conditions 
    //         0048ecfd     PUSH       EAX=>DAT_fffffff4
    //         0048ecfe     CALL       itoa                                             undefined itoa()
    //                              scr_ach.cpp:660 (19)
    //         0048ed03     MOV        this,dword ptr [EDI + 0xc]
    //         0048ed06     ADD        ESP,0xc
    //         0048ed09     LEA        EAX,[ESP + 0x18]
    //         0048ed0d     MOV        EDX,dword ptr [this->_padding_]
    //         0048ed0f     PUSH       EAX
    //         0048ed10     CALL       dword ptr [EDX + 0xe8]
    //                              scr_ach.cpp:663 (37)
    //         0048ed16     LEA        this,[ESP + 0x18]
    //         0048ed1a     PUSH       0xa
    //         0048ed1c     PUSH       this=>DAT_fffffff8
    //         0048ed1d     MOV        this,dword ptr [ESI + 0x34]
    //         0048ed20     PUSH       offset DAT_fffffff4
    //         0048ed22     CALL       RGE_Victory_Conditions::get_victory_points_id    long get_victory_points_id(RGE_Victory_Condit
    //         0048ed27     MOV        this,dword ptr [ESI + 0x34]
    //         0048ed2a     PUSH       offset DAT_fffffff4
    //         0048ed2c     MOV        EBP,EAX
    //         0048ed2e     CALL       RGE_Victory_Conditions::get_victory_points_id    long get_victory_points_id(RGE_Victory_Condit
    //         0048ed33     ADD        EBP,EAX
    //         0048ed35     PUSH       EBP=>DAT_fffffff4
    //         0048ed36     CALL       itoa                                             undefined itoa()
    //                              scr_ach.cpp:664 (19)
    //         0048ed3b     MOV        this,dword ptr [EDI + 0x10]
    //         0048ed3e     ADD        ESP,0xc
    //         0048ed41     LEA        EAX,[ESP + 0x18]
    //         0048ed45     MOV        EDX,dword ptr [this->_padding_]
    //         0048ed47     PUSH       EAX
    //         0048ed48     CALL       dword ptr [EDX + 0xe8]
    //                              scr_ach.cpp:666 (23)
    //         0048ed4e     LEA        this,[ESP + 0x18]
    //         0048ed52     PUSH       0xa
    //         0048ed54     PUSH       this=>DAT_fffffff8
    //         0048ed55     MOV        this,dword ptr [ESI + 0x34]
    //         0048ed58     PUSH       offset DAT_fffffff4
    //         0048ed5a     CALL       RGE_Victory_Conditions::get_victory_points_group long get_victory_points_group(RGE_Victory_Con
    //         0048ed5f     PUSH       EAX=>DAT_fffffff4
    //         0048ed60     CALL       itoa                                             undefined itoa()
    //                              scr_ach.cpp:667 (38)
    //         0048ed65     MOV        this,dword ptr [EDI + 0x14]
    //         0048ed68     ADD        ESP,0xc
    //         0048ed6b     LEA        EAX,[ESP + 0x18]
    //         0048ed6f     MOV        EDX,dword ptr [this->_padding_]
    //         0048ed71     PUSH       EAX
    //         0048ed72     CALL       dword ptr [EDX + 0xe8]
    //         0048ed78     MOV        EDX,dword ptr [ESP + 0x50]
    //         0048ed7c     MOV        EAX,dword ptr [ESP + 0x14]
    //         0048ed80     ADD        EDX,0x4
    //         0048ed83     ADD        EDI,0x1c
    //         0048ed86     MOV        dword ptr [ESP + 0x50],EDX
    //         0048ed8a     DEC        EAX
    //                              scr_ach.cpp:639 (10)
    //         0048ed8b     MOV        dword ptr [ESP + 0x14],EAX
    //         0048ed8f     JNZ        LAB_0048ec1f
    //                              scr_ach.cpp:669 (5)
    //         0048ed95     JMP        switchD_0048e4fc::default
    //                               switchD_0048e4fc::caseD_4                                    XREF[2]:     0048e4fc(j), 0048f098(*)  
    //                              scr_ach.cpp:672 (29)
    //         0048ed9a     MOV        this,dword ptr [EBX + 0x488]
    //                              language.dll match for 0x26af: "Technology"
    //         0048eda0     PUSH       0x26af
    //         0048eda5     MOV        dword ptr [EBX + 0x480],0x5
    //         0048edaf     MOV        EDX,dword ptr [this->_padding_]
    //         0048edb1     CALL       dword ptr [EDX + 0xe4]
    //                              scr_ach.cpp:673 (19)
    //         0048edb7     MOV        this,dword ptr [EBX + 0x498]
    //                              language.dll match for 0x26ce: "Technologies"
    //         0048edbd     PUSH       0x26ce
    //         0048edc2     MOV        EAX,dword ptr [this->_padding_]
    //         0048edc4     CALL       dword ptr [EAX + 0xe4]
    //                              scr_ach.cpp:674 (19)
    //         0048edca     MOV        this,dword ptr [EBX + 0x49c]
    //                              language.dll match for 0x26d1: "Most Technologies"
    //         0048edd0     PUSH       0x26d1
    //         0048edd5     MOV        EDX,dword ptr [this->_padding_]
    //         0048edd7     CALL       dword ptr [EDX + 0xe4]
    //                              scr_ach.cpp:675 (19)
    //         0048eddd     MOV        this,dword ptr [EBX + 0x4a0]
    //                              language.dll match for 0x26cf: "Bronze Age First"
    //         0048ede3     PUSH       0x26cf
    //         0048ede8     MOV        EAX,dword ptr [this->_padding_]
    //         0048edea     CALL       dword ptr [EAX + 0xe4]
    //                              scr_ach.cpp:676 (19)
    //         0048edf0     MOV        this,dword ptr [EBX + 0x4a4]
    //                              language.dll match for 0x26d0: "Iron Age First"
    //         0048edf6     PUSH       0x26d0
    //         0048edfb     MOV        EDX,dword ptr [this->_padding_]
    //         0048edfd     CALL       dword ptr [EDX + 0xe4]
    //                              scr_ach.cpp:677 (19)
    //         0048ee03     MOV        this,dword ptr [EBX + 0x4a8]
    //                              language.dll match for 0x26b5: "Total Score"
    //         0048ee09     PUSH       0x26b5
    //         0048ee0e     MOV        EAX,dword ptr [this->_padding_]
    //         0048ee10     CALL       dword ptr [EAX + 0xe4]
    //                              scr_ach.cpp:679 (8)
    //         0048ee16     CMP        ESI,EBP
    //         0048ee18     JLE        switchD_0048e4fc::default
    //                              scr_ach.cpp:744 (110)
    //         0048ee1e     MOV        this,dword ptr [ESP + 0x10]
    //         0048ee22     MOV        EBP,0x4
    //         0048ee27     LEA        ESI,[EBX + 0x4cc]
    //         0048ee2d     MOV        dword ptr [ESP + 0x50],this
    //                               LAB_0048ee31                                                 XREF[1]:     0048ef2c(j)  
    //         0048ee31     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
    //         0048ee37     PUSH       0xa
    //         0048ee39     MOV        EAX,dword ptr [EDX + 0x3f4]
    //         0048ee3f     LEA        EDX,[ESP + 0x1c]
    //         0048ee43     PUSH       EDX=>DAT_fffffff8
    //         0048ee44     PUSH       offset DAT_fffffff4
    //         0048ee46     MOV        this,dword ptr [EAX + 0x40]
    //         0048ee49     MOV        EDI,dword ptr [this->_padding_ + EBP*0x1]
    //         0048ee4c     MOV        this,dword ptr [EDI + 0x34]
    //         0048ee4f     CALL       RGE_Victory_Conditions::get_attribute_id         long get_attribute_id(RGE_Victory_Conditions 
    //         0048ee54     PUSH       EAX=>DAT_fffffff4
    //         0048ee55     CALL       itoa                                             undefined itoa()
    //         0048ee5a     MOV        this,dword ptr [ESI + -0x4]
    //         0048ee5d     ADD        ESP,0xc
    //         0048ee60     LEA        EDX,[ESP + 0x18]
    //         0048ee64     MOV        EAX,dword ptr [this->_padding_]
    //         0048ee66     PUSH       EDX
    //         0048ee67     CALL       dword ptr [EAX + 0xe8]
    //         0048ee6d     MOV        this,dword ptr [EDI + 0x34]
    //         0048ee70     PUSH       0x12
    //         0048ee72     CALL       RGE_Victory_Conditions::get_victory_points_id    long get_victory_points_id(RGE_Victory_Condit
    //         0048ee77     MOV        this,dword ptr [ESI]
    //         0048ee79     TEST       EAX,EAX
    //         0048ee7b     JLE        LAB_0048ee8c
    //         0048ee7d     MOV        EAX,dword ptr [this->_padding_]
    //                              language.dll match for 0xfa3: "Yes"
    //         0048ee7f     PUSH       0xfa3
    //         0048ee84     CALL       dword ptr [EAX + 0xe4]
    //         0048ee8a     JMP        LAB_0048ee99
    //                               LAB_0048ee8c                                                 XREF[1]:     0048ee7b(j)  
    //                              scr_ach.cpp:689 (13)
    //         0048ee8c     MOV        EDX,dword ptr [this->_padding_]
    //         0048ee8e     PUSH       s_                                               = ""
    //         0048ee93     CALL       dword ptr [EDX + 0xe8]
    //                               LAB_0048ee99                                                 XREF[1]:     0048ee8a(j)  
    //                              scr_ach.cpp:691 (10)
    //         0048ee99     MOV        this,dword ptr [EDI + 0x34]
    //         0048ee9c     PUSH       0x13
    //         0048ee9e     CALL       RGE_Victory_Conditions::get_victory_points_id    long get_victory_points_id(RGE_Victory_Condit
    //                              scr_ach.cpp:692 (20)
    //         0048eea3     MOV        this,dword ptr [ESI + 0x4]
    //         0048eea6     TEST       EAX,EAX
    //         0048eea8     JLE        LAB_0048eeb9
    //         0048eeaa     MOV        EAX,dword ptr [this->_padding_]
    //                              language.dll match for 0xfa3: "Yes"
    //         0048eeac     PUSH       0xfa3
    //         0048eeb1     CALL       dword ptr [EAX + 0xe4]
    //                              scr_ach.cpp:693 (2)
    //         0048eeb7     JMP        LAB_0048eec6
    //                               LAB_0048eeb9                                                 XREF[1]:     0048eea8(j)  
    //                              scr_ach.cpp:694 (13)
    //         0048eeb9     MOV        EDX,dword ptr [this->_padding_]
    //         0048eebb     PUSH       s_                                               = ""
    //         0048eec0     CALL       dword ptr [EDX + 0xe8]
    //                               LAB_0048eec6                                                 XREF[1]:     0048eeb7(j)  
    //                              scr_ach.cpp:696 (10)
    //         0048eec6     MOV        this,dword ptr [EDI + 0x34]
    //         0048eec9     PUSH       0x14
    //         0048eecb     CALL       RGE_Victory_Conditions::get_victory_points_id    long get_victory_points_id(RGE_Victory_Condit
    //                              scr_ach.cpp:697 (20)
    //         0048eed0     MOV        this,dword ptr [ESI + 0x8]
    //         0048eed3     TEST       EAX,EAX
    //         0048eed5     JLE        LAB_0048eee6
    //         0048eed7     MOV        EAX,dword ptr [this->_padding_]
    //                              language.dll match for 0xfa3: "Yes"
    //         0048eed9     PUSH       0xfa3
    //         0048eede     CALL       dword ptr [EAX + 0xe4]
    //                              scr_ach.cpp:698 (2)
    //         0048eee4     JMP        LAB_0048eef3
    //                               LAB_0048eee6                                                 XREF[1]:     0048eed5(j)  
    //                              scr_ach.cpp:699 (13)
    //         0048eee6     MOV        EDX,dword ptr [this->_padding_]
    //         0048eee8     PUSH       s_                                               = ""
    //         0048eeed     CALL       dword ptr [EDX + 0xe8]
    //                               LAB_0048eef3                                                 XREF[1]:     0048eee4(j)  
    //                              scr_ach.cpp:701 (23)
    //         0048eef3     MOV        this,dword ptr [EDI + 0x34]
    //         0048eef6     LEA        EAX,[ESP + 0x18]
    //         0048eefa     PUSH       0xa
    //         0048eefc     PUSH       EAX=>DAT_fffffff8
    //         0048eefd     PUSH       offset DAT_fffffff4
    //         0048eeff     CALL       RGE_Victory_Conditions::get_victory_points_group long get_victory_points_group(RGE_Victory_Con
    //         0048ef04     PUSH       EAX=>DAT_fffffff4
    //         0048ef05     CALL       itoa                                             undefined itoa()
    //                              scr_ach.cpp:702 (40)
    //         0048ef0a     MOV        this,dword ptr [ESI + 0xc]
    //         0048ef0d     ADD        ESP,0xc
    //         0048ef10     LEA        EAX,[ESP + 0x18]
    //         0048ef14     MOV        EDX,dword ptr [this->_padding_]
    //         0048ef16     PUSH       EAX
    //         0048ef17     CALL       dword ptr [EDX + 0xe8]
    //         0048ef1d     MOV        EAX,dword ptr [ESP + 0x50]
    //         0048ef21     ADD        EBP,0x4
    //         0048ef24     ADD        ESI,0x1c
    //         0048ef27     DEC        EAX
    //         0048ef28     MOV        dword ptr [ESP + 0x50],EAX
    //         0048ef2c     JNZ        LAB_0048ee31
    //                              scr_ach.cpp:704 (5)
    //         0048ef32     JMP        switchD_0048e4fc::default
    //                               switchD_0048e4fc::caseD_6                                    XREF[2]:     0048e4fc(j), 0048f0a0(*)  
    //                              scr_ach.cpp:708 (19)
    //         0048ef37     MOV        this,dword ptr [EBX + 0x5f4]
    //         0048ef3d     PUSH       0x1
    //         0048ef3f     MOV        dword ptr [EBX + 0x480],EBP
    //         0048ef45     MOV        EDX,dword ptr [this->_padding_]
    //         0048ef47     CALL       dword ptr [EDX + 0x14]
    //                              scr_ach.cpp:709 (19)
    //         0048ef4a     MOV        this,dword ptr [EBX + 0x488]
    //                              language.dll match for 0x26d8: "Timeline"
    //         0048ef50     PUSH       0x26d8
    //         0048ef55     MOV        EAX,dword ptr [this->_padding_]
    //         0048ef57     CALL       dword ptr [EAX + 0xe4]
    //                              scr_ach.cpp:710 (13)
    //         0048ef5d     MOV        this,dword ptr [EBX + 0x494]
    //         0048ef63     PUSH       0x1
    //         0048ef65     MOV        EDX,dword ptr [this->_padding_]
    //         0048ef67     CALL       dword ptr [EDX + 0x14]
    //                              scr_ach.cpp:711 (2)
    //         0048ef6a     JMP        switchD_0048e4fc::default
    //                               switchD_0048e4fc::caseD_5                                    XREF[2]:     0048e4fc(j), 0048f09c(*)  
    //                              scr_ach.cpp:715 (25)
    //         0048ef6c     MOV        this,dword ptr [EBX + 0x488]
    //                              language.dll match for 0x26b2: "Aftermath"
    //         0048ef72     PUSH       0x26b2
    //         0048ef77     MOV        dword ptr [EBX + 0x480],EBP
    //         0048ef7d     MOV        EAX,dword ptr [this->_padding_]
    //         0048ef7f     CALL       dword ptr [EAX + 0xe4]
    //                              scr_ach.cpp:716 (10)
    //         0048ef85     MOV        this,dword ptr [EBX + 0x490]
    //         0048ef8b     CMP        this,EBP
    //         0048ef8d     JZ         LAB_0048ef96
    //                              scr_ach.cpp:717 (7)
    //         0048ef8f     MOV        EDX,dword ptr [this->_padding_]
    //         0048ef91     PUSH       0x1
    //         0048ef93     CALL       dword ptr [EDX + 0x14]
    //                               LAB_0048ef96                                                 XREF[1]:     0048ef8d(j)  
    //                              scr_ach.cpp:718 (12)
    //         0048ef96     MOV        this,dword ptr [EBX + 0x494]
    //         0048ef9c     PUSH       EBP
    //         0048ef9d     MOV        EAX,dword ptr [this->_padding_]
    //         0048ef9f     CALL       dword ptr [EAX + 0x14]
    //                              scr_ach.cpp:720 (10)
    //         0048efa2     MOV        this,dword ptr [EBX + 0x5d8]
    //         0048efa8     CMP        this,EBP
    //         0048efaa     JZ         LAB_0048efb2
    //                              scr_ach.cpp:721 (6)
    //         0048efac     MOV        EDX,dword ptr [this->_padding_]
    //         0048efae     PUSH       EBP
    //         0048efaf     CALL       dword ptr [EDX + 0x14]
    //                               LAB_0048efb2                                                 XREF[1]:     0048efaa(j)  
    //                              scr_ach.cpp:723 (10)
    //         0048efb2     MOV        this,dword ptr [EBX + 0x5dc]
    //         0048efb8     CMP        this,EBP
    //         0048efba     JZ         switchD_0048e4fc::default
    //                              scr_ach.cpp:725 (7)
    //         0048efbc     MOV        EAX,dword ptr [this->_padding_]
    //         0048efbe     PUSH       0x1
    //         0048efc0     CALL       dword ptr [EAX + 0x14]
    //                              scr_ach.cpp:726 (14)
    //         0048efc3     MOV        this,dword ptr [EBX + 0x5dc]
    //         0048efc9     PUSH       this
    //         0048efca     MOV        this,EBX
    //         0048efcc     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                               switchD_0048e4fc::default                                    XREF[13]:    0048e4f6(j), 0048e612(j), 
    //                                                                                                         0048e777(j), 0048e80d(j), 
    //                                                                                                         0048e94f(j), 0048e9f4(j), 
    //                                                                                                         0048eb62(j), 0048ec07(j), 
    //                                                                                                         0048ed95(j), 0048ee18(j), 
    //                                                                                                         0048ef32(j), 0048ef6a(j), 
    //                                                                                                         0048efba(j)  
    //                              scr_ach.cpp:731 (10)
    //         0048efd1     MOV        EAX,dword ptr [EBX + 0x480]
    //         0048efd7     TEST       EAX,EAX
    //         0048efd9     JNZ        LAB_0048eff7
    //                              scr_ach.cpp:744 (26)
    //         0048efdb     LEA        ESI,[EBX + 0x5a8]
    //         0048efe1     MOV        EDI,0x8
    //                               LAB_0048efe6                                                 XREF[1]:     0048eff3(j)  
    //         0048efe6     MOV        this,dword ptr [ESI]
    //         0048efe8     PUSH       0x0
    //         0048efea     MOV        EDX,dword ptr [this->_padding_]
    //         0048efec     CALL       dword ptr [EDX + 0x14]
    //         0048efef     ADD        ESI,0x4
    //         0048eff2     DEC        EDI
    //         0048eff3     JNZ        LAB_0048efe6
    //                              scr_ach.cpp:734 (2)
    //         0048eff5     JMP        LAB_0048f01b
    //                               LAB_0048eff7                                                 XREF[1]:     0048efd9(j)  
    //                              scr_ach.cpp:735 (2)
    //         0048eff7     XOR        ESI,ESI
    //                              scr_ach.cpp:744 (34)
    //         0048eff9     LEA        EDI,[EBX + 0x5a8]
    //                               LAB_0048efff                                                 XREF[1]:     0048f019(j)  
    //         0048efff     MOV        EBP,dword ptr [ESP + 0x10]
    //         0048f003     MOV        this,dword ptr [EDI]
    //         0048f005     XOR        EDX,EDX
    //         0048f007     CMP        ESI,EBP
    //         0048f009     MOV        EAX,dword ptr [this->_padding_]
    //         0048f00b     SETL       DL
    //         0048f00e     PUSH       EDX
    //         0048f00f     CALL       dword ptr [EAX + 0x14]
    //         0048f012     INC        ESI
    //         0048f013     ADD        EDI,0x4
    //         0048f016     CMP        ESI,0x8
    //         0048f019     JL         LAB_0048efff
    //                               LAB_0048f01b                                                 XREF[1]:     0048eff5(j)  
    //                              scr_ach.cpp:738 (12)
    //         0048f01b     LEA        EAX,[EBX + 0x498]
    //         0048f021     XOR        EDI,EDI
    //         0048f023     MOV        dword ptr [ESP + 0x50],EAX
    //                               LAB_0048f027                                                 XREF[1]:     0048f079(j)  
    //                              scr_ach.cpp:740 (25)
    //         0048f027     MOV        this,dword ptr [ESP + 0x50]
    //         0048f02b     MOV        EBP,dword ptr [EBX + 0x480]
    //         0048f031     XOR        EAX,EAX
    //         0048f033     CMP        EDI,EBP
    //         0048f035     MOV        this,dword ptr [this->_padding_]
    //         0048f037     SETL       AL
    //         0048f03a     MOV        EDX,dword ptr [this->_padding_]
    //         0048f03c     PUSH       EAX
    //         0048f03d     CALL       dword ptr [EDX + 0x14]
    //                              scr_ach.cpp:741 (17)
    //         0048f040     MOV        EAX,dword ptr [ESP + 0x10]
    //         0048f044     TEST       EAX,EAX
    //         0048f046     JLE        LAB_0048f06a
    //         0048f048     MOV        this,dword ptr [ESP + 0x50]
    //         0048f04c     MOV        EBP,EAX
    //         0048f04e     LEA        ESI,[ECX + this->_padding_]
    //                               LAB_0048f051                                                 XREF[1]:     0048f068(j)  
    //                              scr_ach.cpp:742 (25)
    //         0048f051     MOV        this,dword ptr [ESI]
    //         0048f053     XOR        EAX,EAX
    //         0048f055     CMP        EDI,dword ptr [EBX + 0x480]
    //         0048f05b     MOV        EDX,dword ptr [this->_padding_]
    //         0048f05d     SETL       AL
    //         0048f060     PUSH       EAX
    //         0048f061     CALL       dword ptr [EDX + 0x14]
    //         0048f064     ADD        ESI,0x1c
    //         0048f067     DEC        EBP
    //         0048f068     JNZ        LAB_0048f051
    //                               LAB_0048f06a                                                 XREF[1]:     0048f046(j)  
    //                              scr_ach.cpp:738 (17)
    //         0048f06a     MOV        this,dword ptr [ESP + 0x50]
    //         0048f06e     INC        EDI
    //         0048f06f     ADD        this,0x4
    //         0048f072     CMP        EDI,0x7
    //         0048f075     MOV        dword ptr [ESP + 0x50],this
    //         0048f079     JL         LAB_0048f027
    //                              scr_ach.cpp:744 (41)
    //         0048f07b     POP        EDI
    //         0048f07c     POP        ESI
    //         0048f07d     POP        EBP
    //         0048f07e     POP        EBX
    //         0048f07f     ADD        ESP,0x3c
    //         0048f082     RET        0x4
}

// Offset: 0x0048F085
undefined FUN_0048f085() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0048f085()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0048f085
    //         0048f085     NOP
    //         0048f086     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_0048e4fc::switchdataD_0048f088                       XREF[1]:     set_mode:0048e4fc(*)  
}

// Offset: 0x0048F0B0
void TribeAchievementsScreen::draw() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall TribeAchievementsScreen::draw(void)                                   *
    //                              *********************************************************************************************************
    //                              void __thiscall draw(TribeAchievementsScreen * this)
    //              void              <VOID>         <RETURN>
    //              TribeAchieveme    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0048f0cf(W)  
    //                               ?draw@TribeAchievementsScreen@@UAEXXZ                        XREF[1]:     005721b0(*)  
    //                               TribeAchievementsScreen::draw
    //                              scr_ach.cpp:750 (6)
    //         0048f0b0     SUB        ESP,0x8
    //         0048f0b3     PUSH       EDI
    //         0048f0b4     MOV        EDI,this
    //                              scr_ach.cpp:755 (5)
    //         0048f0b6     CALL       TScreenPanel::draw                               void draw(TScreenPanel * this)
    //                              scr_ach.cpp:757 (14)
    //         0048f0bb     CMP        dword ptr [EDI + 0x47c],0x5
    //         0048f0c2     JGE        LAB_0048f182
    //         0048f0c8     PUSH       ESI
    //                              scr_ach.cpp:759 (13)
    //         0048f0c9     MOV        ESI,dword ptr [EDI]
    //         0048f0cb     PUSH       0x0
    //         0048f0cd     MOV        this,EDI
    //         0048f0cf     MOV        dword ptr [ESP + local_4],ESI
    //         0048f0d3     CALL       dword ptr [ESI + 0x28]
    //                              scr_ach.cpp:761 (14)
    //         0048f0d6     MOV        EAX,dword ptr [EDI + 0x5f0]
    //         0048f0dc     TEST       EAX,EAX
    //         0048f0de     JZ         LAB_0048f17c
    //                              scr_ach.cpp:762 (23)
    //         0048f0e4     MOV        this,dword ptr [EDI + 0x20]
    //         0048f0e7     PUSH       0x1
    //         0048f0e9     PUSH       s_scr_ach::draw                                  = "scr_ach::draw"
    //         0048f0ee     CALL       TDrawArea::Lock                                  uchar * Lock(TDrawArea * this, char * param_1
    //         0048f0f3     TEST       EAX,EAX
    //         0048f0f5     JZ         LAB_0048f17c
    //                              scr_ach.cpp:764 (12)
    //         0048f0fb     MOV        EAX,[rge_base_game]                              = 00000000
    //         0048f100     PUSH       EBX
    //         0048f101     MOV        EBX,dword ptr [EAX + 0x3f4]
    //                              scr_ach.cpp:765 (5)
    //         0048f107     MOVSX      EAX,word ptr [EBX + 0x3c]
    //         0048f10b     DEC        EAX
    //                              scr_ach.cpp:766 (22)
    //         0048f10c     TEST       EAX,EAX
    //         0048f10e     JLE        LAB_0048f16e
    //         0048f110     PUSH       EBP
    //         0048f111     MOV        EBP,0xfffffa5c
    //         0048f116     LEA        ESI,[EDI + 0x5a8]
    //         0048f11c     SUB        EBP,EDI
    //         0048f11e     MOV        dword ptr [ESP + 0x10],EAX
    //                               LAB_0048f122                                                 XREF[1]:     0048f167(j)  
    //                              scr_ach.cpp:768 (17)
    //         0048f122     MOV        this,dword ptr [EBX + 0x40]
    //         0048f125     ADD        this,EBP
    //         0048f127     MOV        EDX,dword ptr [this->_padding_ + ESI*0x1]
    //         0048f12a     CMP        byte ptr [EDX + 0x80],0x1
    //         0048f131     JNZ        LAB_0048f15b
    //                              scr_ach.cpp:769 (59)
    //         0048f133     MOV        this,dword ptr [ESI]
    //         0048f135     PUSH       0x0
    //         0048f137     PUSH       0x0
    //         0048f139     PUSH       0x0
    //         0048f13b     CALL       TPanel::yPosition                                long yPosition(TPanel * this)
    //         0048f140     MOV        this,dword ptr [ESI]
    //         0048f142     PUSH       EAX
    //         0048f143     CALL       TPanel::xPosition                                long xPosition(TPanel * this)
    //         0048f148     MOV        this,dword ptr [EDI + 0x5f0]
    //         0048f14e     SUB        EAX,0x14
    //         0048f151     PUSH       EAX
    //         0048f152     MOV        EAX,dword ptr [EDI + 0x20]
    //         0048f155     PUSH       EAX
    //         0048f156     CALL       TShape::shape_draw                               uchar shape_draw(TShape * this, TDrawArea * p
    //                               LAB_0048f15b                                                 XREF[1]:     0048f131(j)  
    //         0048f15b     MOV        EAX,dword ptr [ESP + 0x10]
    //         0048f15f     ADD        ESI,0x4
    //         0048f162     DEC        EAX
    //         0048f163     MOV        dword ptr [ESP + 0x10],EAX
    //         0048f167     JNZ        LAB_0048f122
    //         0048f169     MOV        ESI,dword ptr [ESP + 0x14]
    //         0048f16d     POP        EBP
    //                               LAB_0048f16e                                                 XREF[1]:     0048f10e(j)  
    //                              scr_ach.cpp:772 (14)
    //         0048f16e     MOV        this,dword ptr [EDI + 0x20]
    //         0048f171     PUSH       s_scr_ach::draw                                  = "scr_ach::draw"
    //         0048f176     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
    //         0048f17b     POP        EBX
    //                               LAB_0048f17c                                                 XREF[2]:     0048f0de(j), 0048f0f5(j)  
    //                              scr_ach.cpp:775 (6)
    //         0048f17c     MOV        this,EDI
    //         0048f17e     CALL       dword ptr [ESI + 0x2c]
    //         0048f181     POP        ESI
    //                               LAB_0048f182                                                 XREF[1]:     0048f0c2(j)  
    //                              scr_ach.cpp:777 (5)
    //         0048f182     POP        EDI
    //         0048f183     ADD        ESP,0x8
    //         0048f186     RET
}

// Offset: 0x0048F190
long TribeAchievementsScreen::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TribeAchievementsScreen::handle_mouse_down(unsigned char,long,long... *
    //                              *********************************************************************************************************
    //                              long __thiscall handle_mouse_down(TribeAchievementsScreen * this, uc
    //              long              EAX:4          <RETURN>
    //              TribeAchieveme    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     0048f199(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     0048f195(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     0048f1a6(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     0048f1a2(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[1]:     0048f190(R)  
    //                               ?handle_mouse_down@TribeAchievementsScreen@@UAEJEJJHH@Z      XREF[1]:     005721f0(*)  
    //                               TribeAchievementsScreen::handle_mouse_down
    //                              scr_ach.cpp:783 (40)
    //         0048f190     MOV        EAX,dword ptr [ESP + param_5]
    //         0048f194     PUSH       EBX
    //         0048f195     MOV        EBX,dword ptr [ESP + param_2]
    //         0048f199     MOV        EDX,dword ptr [ESP + param_1]
    //         0048f19d     PUSH       EBP
    //         0048f19e     PUSH       ESI
    //         0048f19f     MOV        ESI,this
    //         0048f1a1     PUSH       EDI
    //         0048f1a2     MOV        this,dword ptr [ESP + param_4]
    //         0048f1a6     MOV        EDI,dword ptr [ESP + param_3]
    //         0048f1aa     PUSH       EAX
    //         0048f1ab     PUSH       this
    //         0048f1ac     PUSH       EDI
    //         0048f1ad     PUSH       EBX
    //         0048f1ae     PUSH       EDX
    //         0048f1af     MOV        this,ESI
    //         0048f1b1     CALL       TEasy_Panel::handle_mouse_down                   long handle_mouse_down(TEasy_Panel * this, uc
    //         0048f1b6     MOV        EBP,EAX
    //                              scr_ach.cpp:788 (14)
    //         0048f1b8     MOV        EAX,dword ptr [ESI + 0x47c]
    //         0048f1be     TEST       EAX,EAX
    //         0048f1c0     JNZ        LAB_0048f269
    //                              scr_ach.cpp:790 (20)
    //         0048f1c6     MOV        this,dword ptr [ESI + 0x4b4]
    //         0048f1cc     PUSH       EDI
    //         0048f1cd     PUSH       EBX
    //         0048f1ce     MOV        EAX,dword ptr [this->_padding_]
    //         0048f1d0     CALL       dword ptr [EAX + 0xbc]
    //         0048f1d6     TEST       EAX,EAX
    //         0048f1d8     JZ         LAB_0048f1ec
    //                              scr_ach.cpp:791 (2)
    //         0048f1da     PUSH       0x1
    //                              scr_ach.cpp:797 (7)
    //         0048f1dc     MOV        this,ESI
    //         0048f1de     CALL       TribeAchievementsScreen::set_mode                void set_mode(TribeAchievementsScreen * this,
    //                              scr_ach.cpp:800 (2)
    //         0048f1e3     MOV        EAX,EBP
    //                              scr_ach.cpp:801 (7)
    //         0048f1e5     POP        EDI
    //         0048f1e6     POP        ESI
    //         0048f1e7     POP        EBP
    //         0048f1e8     POP        EBX
    //         0048f1e9     RET        0x14
    //                               LAB_0048f1ec                                                 XREF[1]:     0048f1d8(j)  
    //                              scr_ach.cpp:792 (20)
    //         0048f1ec     MOV        this,dword ptr [ESI + 0x4b8]
    //         0048f1f2     PUSH       EDI
    //         0048f1f3     PUSH       EBX=>DAT_fffffff8
    //         0048f1f4     MOV        EDX,dword ptr [this->_padding_]
    //         0048f1f6     CALL       dword ptr [EDX + 0xbc]
    //         0048f1fc     TEST       EAX,EAX
    //         0048f1fe     JZ         LAB_0048f212
    //                              scr_ach.cpp:793 (2)
    //         0048f200     PUSH       0x2
    //                              scr_ach.cpp:797 (7)
    //         0048f202     MOV        this,ESI
    //         0048f204     CALL       TribeAchievementsScreen::set_mode                void set_mode(TribeAchievementsScreen * this,
    //                              scr_ach.cpp:800 (2)
    //         0048f209     MOV        EAX,EBP
    //                              scr_ach.cpp:801 (7)
    //         0048f20b     POP        EDI
    //         0048f20c     POP        ESI
    //         0048f20d     POP        EBP
    //         0048f20e     POP        EBX
    //         0048f20f     RET        0x14
    //                               LAB_0048f212                                                 XREF[1]:     0048f1fe(j)  
    //                              scr_ach.cpp:794 (20)
    //         0048f212     MOV        this,dword ptr [ESI + 0x4bc]
    //         0048f218     PUSH       EDI
    //         0048f219     PUSH       EBX=>DAT_fffffff8
    //         0048f21a     MOV        EAX,dword ptr [this->_padding_]
    //         0048f21c     CALL       dword ptr [EAX + 0xbc]
    //         0048f222     TEST       EAX,EAX
    //         0048f224     JZ         LAB_0048f238
    //                              scr_ach.cpp:795 (2)
    //         0048f226     PUSH       0x3
    //                              scr_ach.cpp:797 (7)
    //         0048f228     MOV        this,ESI
    //         0048f22a     CALL       TribeAchievementsScreen::set_mode                void set_mode(TribeAchievementsScreen * this,
    //                              scr_ach.cpp:800 (2)
    //         0048f22f     MOV        EAX,EBP
    //                              scr_ach.cpp:801 (7)
    //         0048f231     POP        EDI
    //         0048f232     POP        ESI
    //         0048f233     POP        EBP
    //         0048f234     POP        EBX
    //         0048f235     RET        0x14
    //                               LAB_0048f238                                                 XREF[1]:     0048f224(j)  
    //                              scr_ach.cpp:796 (40)
    //         0048f238     MOV        this,dword ptr [ESI + 0x4c0]
    //         0048f23e     PUSH       EDI
    //         0048f23f     PUSH       EBX=>DAT_fffffff8
    //         0048f240     MOV        EDX,dword ptr [this->_padding_]
    //         0048f242     CALL       dword ptr [EDX + 0xbc]
    //         0048f248     TEST       EAX,EAX
    //         0048f24a     JZ         LAB_0048f269
    //         0048f24c     MOV        this,dword ptr [ESI + 0x4c4]
    //         0048f252     PUSH       EDI
    //         0048f253     PUSH       EBX=>DAT_fffffff8
    //         0048f254     MOV        EAX,dword ptr [this->_padding_]
    //         0048f256     CALL       dword ptr [EAX + 0xbc]
    //         0048f25c     TEST       EAX,EAX
    //         0048f25e     JNZ        LAB_0048f269
    //                              scr_ach.cpp:797 (9)
    //         0048f260     PUSH       0x4
    //         0048f262     MOV        this,ESI
    //         0048f264     CALL       TribeAchievementsScreen::set_mode                void set_mode(TribeAchievementsScreen * this,
    //                               LAB_0048f269                                                 XREF[3]:     0048f1c0(j), 0048f24a(j), 
    //                                                                                                         0048f25e(j)  
    //                              scr_ach.cpp:801 (9)
    //         0048f269     POP        EDI
    //         0048f26a     MOV        EAX,EBP
    //         0048f26c     POP        ESI
    //         0048f26d     POP        EBP
    //         0048f26e     POP        EBX
    //         0048f26f     RET        0x14
}

// Offset: 0x0048F280
long TribeAchievementsScreen::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TribeAchievementsScreen::action(class TPanel *,long,unsigned long,... *
    //                              *********************************************************************************************************
    //                              long __thiscall action(TribeAchievementsScreen * this, TPanel * para
    //              long              EAX:4          <RETURN>
    //              TribeAchieveme    ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     0048f282(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     0048f287(R)  
    //              ulong             Stack[0xc]:4   param_3                   XREF[1]:     0048f4e8(R)  
    //              ulong             Stack[0x10]:4  param_4                   XREF[1]:     0048f4e4(R)  
    //                               ?action@TribeAchievementsScreen@@UAEJPAVTPanel@@JKK@Z        XREF[1]:     00572234(*)  
    //                               TribeAchievementsScreen::action
    //                              scr_ach.cpp:808 (2)
    //         0048f280     PUSH       EBX
    //         0048f281     PUSH       EBP
    //                              scr_ach.cpp:812 (25)
    //         0048f282     MOV        EBP,dword ptr [ESP + param_1]
    //         0048f286     PUSH       ESI
    //         0048f287     MOV        EBX,dword ptr [ESP + param_2]
    //         0048f28b     PUSH       EDI
    //         0048f28c     MOV        EDI,this
    //         0048f28e     CMP        EBP,dword ptr [EDI + 0x5d4]
    //         0048f294     JNZ        LAB_0048f301
    //         0048f296     CMP        EBX,0x1
    //         0048f299     JNZ        LAB_0048f301
    //                              scr_ach.cpp:814 (6)
    //         0048f29b     MOV        EAX,dword ptr [EDI + 0x478]
    //                              scr_ach.cpp:816 (15)
    //         0048f2a1     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0048f2a7     TEST       EAX,EAX
    //         0048f2a9     JZ         LAB_0048f2b2
    //         0048f2ab     CALL       TRIBE_Game::quit_game                            void quit_game(TRIBE_Game * this)
    //                              scr_ach.cpp:818 (2)
    //         0048f2b0     JMP        LAB_0048f2e6
    //                               LAB_0048f2b2                                                 XREF[1]:     0048f2a9(j)  
    //                              scr_ach.cpp:820 (26)
    //         0048f2b2     CALL       RGE_Base_Game::singlePlayerGame                  int singlePlayerGame(RGE_Base_Game * this)
    //         0048f2b7     CMP        EAX,0x1
    //         0048f2ba     JNZ        LAB_0048f2d5
    //         0048f2bc     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0048f2c2     MOV        EAX,dword ptr [this->_padding_ + 0xa00]
    //         0048f2c8     TEST       EAX,EAX
    //         0048f2ca     JNZ        LAB_0048f2d5
    //                              scr_ach.cpp:821 (9)
    //         0048f2cc     PUSH       0x0
    //         0048f2ce     PUSH       0x0
    //         0048f2d0     CALL       RGE_Base_Game::set_paused                        void set_paused(RGE_Base_Game * this, int par
    //                               LAB_0048f2d5                                                 XREF[2]:     0048f2ba(j), 0048f2ca(j)  
    //                              scr_ach.cpp:822 (17)
    //         0048f2d5     PUSH       0x0
    //         0048f2d7     PUSH       s_Game_Screen                                    = "Game Screen"
    //         0048f2dc     MOV        this,panel_system
    //         0048f2e1     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                               LAB_0048f2e6                                                 XREF[1]:     0048f2b0(j)  
    //                              scr_ach.cpp:825 (15)
    //         0048f2e6     PUSH       s_Achievements_Screen                            = "Achievements Screen"
    //         0048f2eb     MOV        this,panel_system
    //         0048f2f0     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_ach.cpp:826 (5)
    //         0048f2f5     MOV        EAX,0x1
    //                              scr_ach.cpp:905 (7)
    //         0048f2fa     POP        EDI
    //         0048f2fb     POP        ESI
    //         0048f2fc     POP        EBP
    //         0048f2fd     POP        EBX
    //         0048f2fe     RET        0x10
    //                               LAB_0048f301                                                 XREF[2]:     0048f294(j), 0048f299(j)  
    //                              scr_ach.cpp:829 (13)
    //         0048f301     CMP        EBP,dword ptr [EDI + 0x5e8]
    //         0048f307     JNZ        LAB_0048f322
    //         0048f309     CMP        EBX,0x1
    //         0048f30c     JNZ        LAB_0048f322
    //                              scr_ach.cpp:831 (11)
    //         0048f30e     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0048f314     CALL       TRIBE_Game::restart_game                         void restart_game(TRIBE_Game * this)
    //                              scr_ach.cpp:832 (2)
    //         0048f319     MOV        EAX,EBX
    //                              scr_ach.cpp:905 (7)
    //         0048f31b     POP        EDI
    //         0048f31c     POP        ESI
    //         0048f31d     POP        EBP
    //         0048f31e     POP        EBX
    //         0048f31f     RET        0x10
    //                               LAB_0048f322                                                 XREF[2]:     0048f307(j), 0048f30c(j)  
    //                              scr_ach.cpp:835 (13)
    //         0048f322     CMP        EBP,dword ptr [EDI + 0x5e0]
    //         0048f328     JNZ        LAB_0048f39d
    //         0048f32a     CMP        EBX,0x1
    //         0048f32d     JNZ        LAB_0048f39d
    //                              scr_ach.cpp:837 (9)
    //         0048f32f     PUSH       0x6
    //         0048f331     MOV        this,EDI
    //         0048f333     CALL       TribeAchievementsScreen::set_mode                void set_mode(TribeAchievementsScreen * this,
    //                              scr_ach.cpp:839 (10)
    //         0048f338     MOV        this,dword ptr [EDI + 0x5e8]
    //         0048f33e     TEST       this,this
    //         0048f340     JZ         LAB_0048f349
    //                              scr_ach.cpp:840 (7)
    //         0048f342     MOV        EAX,dword ptr [this->_padding_]
    //         0048f344     PUSH       0x0
    //         0048f346     CALL       dword ptr [EAX + 0x14]
    //                               LAB_0048f349                                                 XREF[1]:     0048f340(j)  
    //                              scr_ach.cpp:842 (10)
    //         0048f349     MOV        this,dword ptr [EDI + 0x5d4]
    //         0048f34f     TEST       this,this
    //         0048f351     JZ         LAB_0048f35a
    //                              scr_ach.cpp:843 (7)
    //         0048f353     MOV        EDX,dword ptr [this->_padding_]
    //         0048f355     PUSH       0x0
    //         0048f357     CALL       dword ptr [EDX + 0x14]
    //                               LAB_0048f35a                                                 XREF[1]:     0048f351(j)  
    //                              scr_ach.cpp:845 (10)
    //         0048f35a     MOV        this,dword ptr [EDI + 0x5e4]
    //         0048f360     TEST       this,this
    //         0048f362     JZ         LAB_0048f36b
    //                              scr_ach.cpp:846 (7)
    //         0048f364     MOV        EAX,dword ptr [this->_padding_]
    //         0048f366     PUSH       0x0
    //         0048f368     CALL       dword ptr [EAX + 0x14]
    //                               LAB_0048f36b                                                 XREF[1]:     0048f362(j)  
    //                              scr_ach.cpp:848 (10)
    //         0048f36b     MOV        this,dword ptr [EDI + 0x5e0]
    //         0048f371     TEST       this,this
    //         0048f373     JZ         LAB_0048f37c
    //                              scr_ach.cpp:849 (7)
    //         0048f375     MOV        EDX,dword ptr [this->_padding_]
    //         0048f377     PUSH       0x0
    //         0048f379     CALL       dword ptr [EDX + 0x14]
    //                               LAB_0048f37c                                                 XREF[1]:     0048f373(j)  
    //                              scr_ach.cpp:851 (14)
    //         0048f37c     MOV        this,dword ptr [EDI + 0x5d8]
    //         0048f382     TEST       this,this
    //         0048f384     JZ         LAB_0048f4d8
    //                              scr_ach.cpp:852 (7)
    //         0048f38a     MOV        EAX,dword ptr [this->_padding_]
    //         0048f38c     PUSH       0x1
    //         0048f38e     CALL       dword ptr [EAX + 0x14]
    //                              scr_ach.cpp:853 (5)
    //         0048f391     MOV        EAX,0x1
    //                              scr_ach.cpp:905 (7)
    //         0048f396     POP        EDI
    //         0048f397     POP        ESI
    //         0048f398     POP        EBP
    //         0048f399     POP        EBX
    //         0048f39a     RET        0x10
    //                               LAB_0048f39d                                                 XREF[2]:     0048f328(j), 0048f32d(j)  
    //                              scr_ach.cpp:856 (13)
    //         0048f39d     CMP        EBP,dword ptr [EDI + 0x5e4]
    //         0048f3a3     JNZ        LAB_0048f418
    //         0048f3a5     CMP        EBX,0x1
    //         0048f3a8     JNZ        LAB_0048f418
    //                              scr_ach.cpp:858 (9)
    //         0048f3aa     PUSH       0x5
    //         0048f3ac     MOV        this,EDI
    //         0048f3ae     CALL       TribeAchievementsScreen::set_mode                void set_mode(TribeAchievementsScreen * this,
    //                              scr_ach.cpp:860 (10)
    //         0048f3b3     MOV        this,dword ptr [EDI + 0x5e8]
    //         0048f3b9     TEST       this,this
    //         0048f3bb     JZ         LAB_0048f3c4
    //                              scr_ach.cpp:861 (7)
    //         0048f3bd     MOV        EDX,dword ptr [this->_padding_]
    //         0048f3bf     PUSH       0x0
    //         0048f3c1     CALL       dword ptr [EDX + 0x14]
    //                               LAB_0048f3c4                                                 XREF[1]:     0048f3bb(j)  
    //                              scr_ach.cpp:863 (10)
    //         0048f3c4     MOV        this,dword ptr [EDI + 0x5d4]
    //         0048f3ca     TEST       this,this
    //         0048f3cc     JZ         LAB_0048f3d5
    //                              scr_ach.cpp:864 (7)
    //         0048f3ce     MOV        EAX,dword ptr [this->_padding_]
    //         0048f3d0     PUSH       0x0
    //         0048f3d2     CALL       dword ptr [EAX + 0x14]
    //                               LAB_0048f3d5                                                 XREF[1]:     0048f3cc(j)  
    //                              scr_ach.cpp:866 (10)
    //         0048f3d5     MOV        this,dword ptr [EDI + 0x5e4]
    //         0048f3db     TEST       this,this
    //         0048f3dd     JZ         LAB_0048f3e6
    //                              scr_ach.cpp:867 (7)
    //         0048f3df     MOV        EDX,dword ptr [this->_padding_]
    //         0048f3e1     PUSH       0x0
    //         0048f3e3     CALL       dword ptr [EDX + 0x14]
    //                               LAB_0048f3e6                                                 XREF[1]:     0048f3dd(j)  
    //                              scr_ach.cpp:869 (10)
    //         0048f3e6     MOV        this,dword ptr [EDI + 0x5e0]
    //         0048f3ec     TEST       this,this
    //         0048f3ee     JZ         LAB_0048f3f7
    //                              scr_ach.cpp:870 (7)
    //         0048f3f0     MOV        EAX,dword ptr [this->_padding_]
    //         0048f3f2     PUSH       0x0
    //         0048f3f4     CALL       dword ptr [EAX + 0x14]
    //                               LAB_0048f3f7                                                 XREF[1]:     0048f3ee(j)  
    //                              scr_ach.cpp:872 (14)
    //         0048f3f7     MOV        this,dword ptr [EDI + 0x5d8]
    //         0048f3fd     TEST       this,this
    //         0048f3ff     JZ         LAB_0048f4d8
    //                              scr_ach.cpp:873 (7)
    //         0048f405     MOV        EDX,dword ptr [this->_padding_]
    //         0048f407     PUSH       0x1
    //         0048f409     CALL       dword ptr [EDX + 0x14]
    //                              scr_ach.cpp:875 (5)
    //         0048f40c     MOV        EAX,0x1
    //                              scr_ach.cpp:905 (7)
    //         0048f411     POP        EDI
    //         0048f412     POP        ESI
    //         0048f413     POP        EBP
    //         0048f414     POP        EBX
    //         0048f415     RET        0x10
    //                               LAB_0048f418                                                 XREF[2]:     0048f3a3(j), 0048f3a8(j)  
    //                              scr_ach.cpp:878 (21)
    //         0048f418     CMP        EBP,dword ptr [EDI + 0x5d8]
    //         0048f41e     JZ         LAB_0048f428
    //         0048f420     CMP        EBP,dword ptr [EDI + 0x5dc]
    //         0048f426     JNZ        LAB_0048f43f
    //                               LAB_0048f428                                                 XREF[1]:     0048f41e(j)  
    //         0048f428     CMP        EBX,0x1
    //         0048f42b     JNZ        LAB_0048f43f
    //                              scr_ach.cpp:880 (9)
    //         0048f42d     PUSH       0x0
    //         0048f42f     MOV        this,EDI
    //         0048f431     CALL       TribeAchievementsScreen::set_mode                void set_mode(TribeAchievementsScreen * this,
    //                              scr_ach.cpp:881 (2)
    //         0048f436     MOV        EAX,EBX
    //                              scr_ach.cpp:905 (7)
    //         0048f438     POP        EDI
    //         0048f439     POP        ESI
    //         0048f43a     POP        EBP
    //         0048f43b     POP        EBX
    //         0048f43c     RET        0x10
    //                               LAB_0048f43f                                                 XREF[2]:     0048f426(j), 0048f42b(j)  
    //                              scr_ach.cpp:885 (13)
    //         0048f43f     CMP        EBP,dword ptr [EDI + 0x5ec]
    //         0048f445     JNZ        LAB_0048f460
    //         0048f447     CMP        EBX,0x1
    //         0048f44a     JNZ        LAB_0048f460
    //                              scr_ach.cpp:889 (11)
    //         0048f44c     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0048f452     CALL       RGE_Base_Game::close                             void close(RGE_Base_Game * this)
    //                              scr_ach.cpp:890 (2)
    //         0048f457     MOV        EAX,EBX
    //                              scr_ach.cpp:905 (7)
    //         0048f459     POP        EDI
    //         0048f45a     POP        ESI
    //         0048f45b     POP        EBP
    //         0048f45c     POP        EBX
    //         0048f45d     RET        0x10
    //                               LAB_0048f460                                                 XREF[2]:     0048f445(j), 0048f44a(j)  
    //                              scr_ach.cpp:894 (68)
    //         0048f460     MOV        this,EBP
    //         0048f462     CALL       TPanel::panelName                                char * panelName(TPanel * this)
    //         0048f467     TEST       EAX,EAX
    //         0048f469     JZ         LAB_0048f4e4
    //         0048f46b     MOV        this,EBP
    //         0048f46d     MOV        ESI,s_YesNoDialog                                = 59h
    //         0048f472     CALL       TPanel::panelName                                char * panelName(TPanel * this)
    //                               LAB_0048f477                                                 XREF[1]:     0048f495(j)  
    //         0048f477     MOV        DL,byte ptr [EAX]
    //         0048f479     MOV        this,DL
    //         0048f47b     CMP        DL,byte ptr [ESI]=>s_YesNoDialog                 = 59h
    //                                                                                  = 73h
    //         0048f47d     JNZ        LAB_0048f49b
    //         0048f47f     TEST       this,this
    //         0048f481     JZ         LAB_0048f497
    //         0048f483     MOV        DL,byte ptr [EAX + 0x1]
    //         0048f486     MOV        this,DL
    //         0048f488     CMP        DL,byte ptr [ESI + 0x1]=>DAT_00584ec1            = 65h
    //                                                                                  = "NoDialog"
    //         0048f48b     JNZ        LAB_0048f49b
    //         0048f48d     ADD        EAX,0x2
    //         0048f490     ADD        ESI,0x2
    //         0048f493     TEST       this,this
    //         0048f495     JNZ        LAB_0048f477
    //                               LAB_0048f497                                                 XREF[1]:     0048f481(j)  
    //         0048f497     XOR        EAX,EAX
    //         0048f499     JMP        LAB_0048f4a0
    //                               LAB_0048f49b                                                 XREF[2]:     0048f47d(j), 0048f48b(j)  
    //         0048f49b     SBB        EAX,EAX
    //         0048f49d     SBB        EAX,-0x1
    //                               LAB_0048f4a0                                                 XREF[1]:     0048f499(j)  
    //         0048f4a0     TEST       EAX,EAX
    //         0048f4a2     JNZ        LAB_0048f4e4
    //                              scr_ach.cpp:896 (15)
    //         0048f4a4     PUSH       s_YesNoDialog                                    = 59h
    //         0048f4a9     MOV        this,panel_system
    //         0048f4ae     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_ach.cpp:897 (4)
    //         0048f4b3     TEST       EBX,EBX
    //         0048f4b5     JNZ        LAB_0048f4ce
    //                              scr_ach.cpp:898 (11)
    //         0048f4b7     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0048f4bd     CALL       RGE_Base_Game::close                             void close(RGE_Base_Game * this)
    //                              scr_ach.cpp:901 (5)
    //         0048f4c2     MOV        EAX,0x1
    //                              scr_ach.cpp:905 (7)
    //         0048f4c7     POP        EDI
    //         0048f4c8     POP        ESI
    //         0048f4c9     POP        EBP
    //         0048f4ca     POP        EBX
    //         0048f4cb     RET        0x10
    //                               LAB_0048f4ce                                                 XREF[1]:     0048f4b5(j)  
    //                              scr_ach.cpp:900 (10)
    //         0048f4ce     MOV        dword ptr [confirmed_close],0x0
    //                               LAB_0048f4d8                                                 XREF[2]:     0048f384(j), 0048f3ff(j)  
    //                              scr_ach.cpp:901 (5)
    //         0048f4d8     MOV        EAX,0x1
    //                              scr_ach.cpp:905 (7)
    //         0048f4dd     POP        EDI
    //         0048f4de     POP        ESI
    //         0048f4df     POP        EBP
    //         0048f4e0     POP        EBX
    //         0048f4e1     RET        0x10
    //                               LAB_0048f4e4                                                 XREF[2]:     0048f469(j), 0048f4a2(j)  
    //                              scr_ach.cpp:904 (19)
    //         0048f4e4     MOV        EAX,dword ptr [ESP + param_4]
    //         0048f4e8     MOV        this,dword ptr [ESP + param_3]
    //         0048f4ec     PUSH       EAX
    //         0048f4ed     PUSH       this
    //         0048f4ee     PUSH       EBX
    //         0048f4ef     PUSH       EBP
    //         0048f4f0     MOV        this,EDI
    //         0048f4f2     CALL       TEasy_Panel::action                              long action(TEasy_Panel * this, TPanel * para
    //                              scr_ach.cpp:905 (7)
    //         0048f4f7     POP        EDI
    //         0048f4f8     POP        ESI
    //         0048f4f9     POP        EBP
    //         0048f4fa     POP        EBX
    //         0048f4fb     RET        0x10
}

// Offset: 0x0048F500
long TribeAchievementsScreen::handle_idle() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TribeAchievementsScreen::handle_idle(void)                            *
    //                              *********************************************************************************************************
    //                              long __thiscall handle_idle(TribeAchievementsScreen * this)
    //              long              EAX:4          <RETURN>
    //              TribeAchieveme    ECX:4 (auto)   this
    //                               ?handle_idle@TribeAchievementsScreen@@UAEJXZ                 XREF[1]:     005721cc(*)  
    //                               TribeAchievementsScreen::handle_idle
    //                              scr_ach.cpp:911 (3)
    //         0048f500     PUSH       ESI
    //         0048f501     MOV        ESI,this
    //                              scr_ach.cpp:912 (16)
    //         0048f503     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0048f509     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         0048f50f     TEST       EAX,EAX
    //         0048f511     JNZ        LAB_0048f518
    //                              scr_ach.cpp:913 (5)
    //         0048f513     CALL       RGE_Base_Game::enable_input                      void enable_input(RGE_Base_Game * this)
    //                               LAB_0048f518                                                 XREF[1]:     0048f511(j)  
    //                              scr_ach.cpp:915 (7)
    //         0048f518     MOV        this,ESI
    //         0048f51a     CALL       TPanel::handle_idle                              long handle_idle(TPanel * this)
    //                              scr_ach.cpp:916 (2)
    //         0048f51f     POP        ESI
    //         0048f520     RET
}

// Offset: 0x0048F530
long TribeAchievementsScreen::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TribeAchievementsScreen::wnd_proc(void *,unsigned int,unsigned int... *
    //                              *********************************************************************************************************
    //                              long __thiscall wnd_proc(TribeAchievementsScreen * this, void * para
    //              long              EAX:4          <RETURN>
    //              TribeAchieveme    ECX:4 (auto)   this
    //              void *            Stack[0x4]:4   param_1                   XREF[1]:     0048f5ae(R)  
    //              uint              Stack[0x8]:4   param_2                   XREF[1]:     0048f532(R)  
    //              uint              Stack[0xc]:4   param_3                   XREF[1]:     0048f5aa(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     0048f5a6(R)  
    //                               ?wnd_proc@TribeAchievementsScreen@@UAEJPAXIIJ@Z              XREF[1]:     005721c8(*)  
    //                               TribeAchievementsScreen::wnd_proc
    //                              scr_ach.cpp:922 (2)
    //         0048f530     PUSH       ESI
    //         0048f531     PUSH       EDI
    //                              scr_ach.cpp:923 (11)
    //         0048f532     MOV        EDI,dword ptr [ESP + param_2]
    //         0048f536     MOV        ESI,this
    //         0048f538     CMP        EDI,0x10
    //         0048f53b     JNZ        LAB_0048f5a6
    //                              scr_ach.cpp:925 (9)
    //         0048f53d     MOV        EAX,[confirmed_close]
    //         0048f542     TEST       EAX,EAX
    //         0048f544     JNZ        LAB_0048f5a6
    //                              scr_ach.cpp:928 (58)
    //         0048f546     MOV        EAX,[rge_base_game]                              = 00000000
    //         0048f54b     MOV        dword ptr [confirmed_close],0x1
    //         0048f555     MOV        EAX,dword ptr [EAX + 0x1b0]
    //         0048f55b     CMP        EAX,0x5
    //         0048f55e     JZ         LAB_0048f56f
    //         0048f560     CMP        EAX,0x4
    //         0048f563     JZ         LAB_0048f56f
    //         0048f565     CMP        EAX,0x6
    //         0048f568     JZ         LAB_0048f56f
    //         0048f56a     CMP        EAX,0x7
    //         0048f56d     JNZ        LAB_0048f5a6
    //                               LAB_0048f56f                                                 XREF[3]:     0048f55e(j), 0048f563(j), 
    //                                                                                                         0048f568(j)  
    //         0048f56f     MOV        this,dword ptr [ESI + 0x20]
    //         0048f572     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0048f575     PUSH       EDX
    //         0048f576     CALL       dword ptr [->USER32.DLL::IsIconic]               = 0048ae70
    //         0048f57c     TEST       EAX,EAX
    //         0048f57e     JNZ        LAB_0048f5a6
    //                              scr_ach.cpp:930 (28)
    //         0048f580     PUSH       0x64
    //         0048f582     PUSH       0x1c2
    //         0048f587     PUSH       EAX
    //                              language.dll match for 0xc1d: "Are you sure you want to quit 
    //         0048f588     PUSH       0xc1d
    //         0048f58d     MOV        this,ESI
    //         0048f58f     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
    //         0048f594     PUSH       EAX
    //         0048f595     MOV        this,ESI
    //         0048f597     CALL       TEasy_Panel::popupYesNoDialog                    void popupYesNoDialog(TEasy_Panel * this, cha
    //                              scr_ach.cpp:931 (5)
    //         0048f59c     MOV        EAX,0x1
    //                              scr_ach.cpp:936 (5)
    //         0048f5a1     POP        EDI
    //         0048f5a2     POP        ESI
    //         0048f5a3     RET        0x10
    //                               LAB_0048f5a6                                                 XREF[4]:     0048f53b(j), 0048f544(j), 
    //                                                                                                         0048f56d(j), 0048f57e(j)  
    //                              scr_ach.cpp:935 (23)
    //         0048f5a6     MOV        EAX,dword ptr [ESP + param_4]
    //         0048f5aa     MOV        this,dword ptr [ESP + param_3]
    //         0048f5ae     MOV        EDX,dword ptr [ESP + param_1]
    //         0048f5b2     PUSH       EAX
    //         0048f5b3     PUSH       this
    //         0048f5b4     PUSH       EDI
    //         0048f5b5     PUSH       EDX
    //         0048f5b6     MOV        this,ESI
    //         0048f5b8     CALL       TPanel::wnd_proc                                 long wnd_proc(TPanel * this, void * param_1, 
    //                              scr_ach.cpp:936 (5)
    //         0048f5bd     POP        EDI
    //         0048f5be     POP        ESI
    //         0048f5bf     RET        0x10
}

