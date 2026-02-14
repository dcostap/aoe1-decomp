// Auto-generated scaffold unit: dlg_smsg.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/dlg_smsg.cpp
#include "../include/common.h"

// Offset: 0x004407A0
undefined TribeSendMessageDialog(TribeSendMessageDialog* this_, TScreenPanel* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TribeSendMessageDialog::TribeSendMessageDialog(class TScreenPanel *)               *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TribeSendMessageDialog(TribeSendMessageDialog *
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TribeSendMessa    ECX:4 (auto)   this
    //              TScreenPanel *    Stack[0x4]:4   param_1                   XREF[1]:     00440882(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     004407d7(W), 00440846(W), 0044086e(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00440dda(R)  
    //              char[100]         Stack[-0x74]   temp_str                  XREF[1,1]:   004407c6(W), 00440a04(*)  
    //              undefined4        Stack[-0x78]:4 local_78                  XREF[3]:     00440840(W), 00440933(W), 00440a00(R)  
    //              undefined4        Stack[-0x7c]:4 local_7c                  XREF[2]:     0044091d(W), 00440976(R)  
    //              int               Stack[-0x80]:4 id                        XREF[3]:     00440907(W), 00440927(R), 00440a0b(R)  
    //              RGE_Game_World    Stack[-0x84]:4 world                     XREF[3]:     00440958(W), 00440992(W), 004409a6(R)  
    //              int               Stack[-0x88]:4 humanity                  XREF[3]:     004408f8(W), 004409bf(R), 00440afd(W)  
    //              int               Stack[-0x8c]:4 i                         XREF[2]:     0044090b(W), 004409bb(R)  
    //                               ??0TribeSendMessageDialog@@QAE@PAVTScreenPanel@@@Z           XREF[1]:     command_chat:0049bffb(c)  
    //                               TribeSendMessageDialog::TribeSendMessageDialog
    //                              dlg_smsg.cpp:66 (47)
    //         004407a0     PUSH       -0x1
    //         004407a2     PUSH       FUN_0055d223
    //         004407a7     MOV        EAX,FS:[0x0]
    //         004407ad     PUSH       EAX
    //         004407ae     MOV        dword ptr FS:[0x0],ESP
    //         004407b5     SUB        ESP,0x80
    //         004407bb     PUSH       EBX
    //         004407bc     PUSH       EBP
    //         004407bd     PUSH       ESI
    //         004407be     PUSH       EDI
    //         004407bf     MOV        ESI,this
    //         004407c1     PUSH       s_Send_Message_Dialog                            = "Send Message Dialog"
    //         004407c6     MOV        dword ptr [ESP + temp_str[0]],ESI
    //         004407ca     CALL       TDialogPanel::TDialogPanel                       undefined TDialogPanel(TDialogPanel * this, c
    //                              dlg_smsg.cpp:72 (34)
    //         004407cf     LEA        EBX,[ESI + 0x490]
    //         004407d5     XOR        EBP,EBP
    //         004407d7     MOV        dword ptr [ESP + local_4],EBP
    //         004407de     MOV        dword ptr [ESI],TribeSendMessageDialog::`vftab   = 00440e00
    //         004407e4     MOV        dword ptr [EBX],EBP
    //         004407e6     LEA        EAX,[ESI + 0x4b4]
    //         004407ec     MOV        this,0x8
    //                               LAB_004407f1                                                 XREF[1]:     00440800(j)  
    //                              dlg_smsg.cpp:74 (3)
    //         004407f1     MOV        dword ptr [EAX + -0x20],EBP
    //                              dlg_smsg.cpp:75 (2)
    //         004407f4     MOV        dword ptr [EAX],EBP
    //                              dlg_smsg.cpp:76 (3)
    //         004407f6     MOV        dword ptr [EAX + 0x20],EBP
    //                              dlg_smsg.cpp:77 (9)
    //         004407f9     MOV        dword ptr [EAX + 0x78],EBP
    //         004407fc     ADD        EAX,0x4
    //         004407ff     DEC        this
    //         00440800     JNZ        LAB_004407f1
    //                              dlg_smsg.cpp:244 (97)
    //         00440802     LEA        EAX,[ESI + 0x504]
    //         00440808     MOV        this,0x3
    //                               LAB_0044080d                                                 XREF[1]:     00440816(j)  
    //         0044080d     MOV        dword ptr [EAX + -0x10],EBP
    //         00440810     MOV        dword ptr [EAX],EBP
    //         00440812     ADD        EAX,0x4
    //         00440815     DEC        this
    //         00440816     JNZ        LAB_0044080d
    //         00440818     PUSH       0x20
    //         0044081a     MOV        dword ptr [ESI + 0x518],EBP
    //         00440820     MOV        dword ptr [ESI + 0x51c],EBP
    //         00440826     MOV        dword ptr [ESI + 0x520],EBP
    //         0044082c     MOV        dword ptr [ESI + 0x524],EBP
    //         00440832     MOV        dword ptr [ESI + 0x528],EBP
    //         00440838     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0044083d     ADD        ESP,0x4
    //         00440840     MOV        dword ptr [ESP + local_78],EAX
    //         00440844     CMP        EAX,EBP
    //         00440846     MOV        byte ptr [ESP + local_4],0x1
    //         0044084e     JZ         LAB_00440863
    //         00440850     PUSH       0xc63a
    //         00440855     PUSH       s_dlg_plbn.shp                                   = "dlg_plbn.shp"
    //         0044085a     MOV        this,EAX
    //         0044085c     CALL       TShape::TShape                                   undefined TShape(TShape * this, char * param_
    //         00440861     JMP        LAB_00440865
    //                               LAB_00440863                                                 XREF[1]:     0044084e(j)  
    //                              dlg_smsg.cpp:90 (31)
    //         00440863     XOR        EAX,EAX
    //                               LAB_00440865                                                 XREF[1]:     00440861(j)  
    //         00440865     XOR        this,this
    //         00440867     CMP        EAX,EBP
    //         00440869     SETZ       this
    //         0044086c     TEST       this,this
    //         0044086e     MOV        byte ptr [ESP + local_4],0x0
    //         00440876     MOV        dword ptr [ESI + 0x528],EAX
    //         0044087c     JNZ        LAB_00440dda
    //                              dlg_smsg.cpp:94 (59)
    //         00440882     MOV        EDI,dword ptr [ESP + param_1]
    //         00440889     PUSH       0x1
    //         0044088b     MOV        this,EDI
    //         0044088d     CALL       TEasy_Panel::get_popup_info_id                   long get_popup_info_id(TEasy_Panel * this)
    //         00440892     PUSH       EAX
    //         00440893     MOV        this,EDI
    //         00440895     CALL       TEasy_Panel::get_popup_info_file                 char * get_popup_info_file(TEasy_Panel * this)
    //         0044089a     PUSH       EAX
    //         0044089b     PUSH       0x1d1
    //         004408a0     PUSH       0x208
    //         004408a5     PUSH       EDI
    //         004408a6     MOV        this,EDI
    //         004408a8     CALL       TPanel::renderArea                               TDrawArea * renderArea(TPanel * this)
    //         004408ad     PUSH       EAX
    //         004408ae     MOV        this,ESI
    //         004408b0     CALL       TDialogPanel::setup                              int setup(TDialogPanel * this, TDrawArea * pa
    //         004408b5     TEST       EAX,EAX
    //         004408b7     JZ         LAB_00440dda
    //                              dlg_smsg.cpp:100 (42)
    //         004408bd     MOV        EAX,dword ptr [ESI + 0x14]
    //         004408c0     PUSH       EBP
    //         004408c1     PUSH       0x1
    //         004408c3     PUSH       0x1
    //         004408c5     PUSH       0x1
    //         004408c7     SUB        EAX,0x28
    //         004408ca     PUSH       0x1e
    //         004408cc     PUSH       EAX
    //         004408cd     PUSH       0xa
    //         004408cf     PUSH       0x5
    //                              language.dll match for 0x2667: "Send Messages to"
    //         004408d1     PUSH       0x2667
    //         004408d6     PUSH       EBX
    //         004408d7     PUSH       ESI
    //         004408d8     MOV        this,ESI
    //         004408da     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         004408df     TEST       EAX,EAX
    //         004408e1     JZ         LAB_00440dda
    //                              dlg_smsg.cpp:103 (6)
    //         004408e7     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //                              dlg_smsg.cpp:142 (34)
    //         004408ed     MOV        EDI,0x1
    //         004408f2     LEA        EAX,[ESI + 0x4d4]
    //         004408f8     MOV        dword ptr [ESP + humanity],EDI
    //         004408fc     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         00440902     MOV        EBX,0x28
    //         00440907     MOV        dword ptr [ESP + id],EDX
    //         0044090b     MOV        dword ptr [ESP + i],EAX
    //                               LAB_0044090f                                                 XREF[1]:     00440b01(j)  
    //                              dlg_smsg.cpp:144 (12)
    //         0044090f     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00440915     PUSH       EDI
    //         00440916     CALL       RGE_Base_Game::playerID                          int playerID(RGE_Base_Game * this, int param_1)
    //                              dlg_smsg.cpp:145 (12)
    //         0044091b     CMP        EAX,EBP
    //         0044091d     MOV        dword ptr [ESP + local_7c],EAX
    //         00440921     JZ         LAB_00440af9
    //                              dlg_smsg.cpp:151 (26)
    //         00440927     MOV        this,dword ptr [ESP + id]
    //         0044092b     XOR        EDI,EDI
    //         0044092d     SHL        EAX,0x2
    //         00440930     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         00440933     MOV        dword ptr [ESP + local_78],EAX
    //         00440937     MOV        EAX,dword ptr [EDX + EAX*0x1]
    //         0044093a     CMP        byte ptr [EAX + 0x80],0x2
    //                              dlg_smsg.cpp:153 (2)
    //         00440941     JZ         LAB_004409b4
    //                              dlg_smsg.cpp:156 (15)
    //         00440943     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00440949     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
    //         0044094e     TEST       EAX,EAX
    //         00440950     JZ         LAB_004409b9
    //                              dlg_smsg.cpp:159 (24)
    //         00440952     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00440958     MOV        dword ptr [ESP + world],EBP
    //         0044095c     MOV        EBP,0x1
    //         00440961     CALL       RGE_Base_Game::numberPlayers                     int numberPlayers(RGE_Base_Game * this)
    //         00440966     CMP        EAX,EBP
    //         00440968     JL         LAB_004409a6
    //                               LAB_0044096a                                                 XREF[1]:     004409a4(j)  
    //                              dlg_smsg.cpp:161 (18)
    //         0044096a     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00440970     PUSH       EBP
    //         00440971     CALL       RGE_Base_Game::playerID                          int playerID(RGE_Base_Game * this, int param_1)
    //         00440976     CMP        EAX,dword ptr [ESP + local_7c]
    //         0044097a     JNZ        LAB_00440996
    //                              dlg_smsg.cpp:163 (12)
    //         0044097c     MOV        this,dword ptr [comm]                            = 00000000
    //         00440982     PUSH       EBP
    //         00440983     CALL       TCommunications_Handler::GetPlayerHumanity       int GetPlayerHumanity(TCommunications_Handler
    //                              dlg_smsg.cpp:164 (10)
    //         00440988     CMP        EAX,0x2
    //         0044098b     JZ         LAB_00440992
    //         0044098d     CMP        EAX,0x4
    //         00440990     JNZ        LAB_00440996
    //                               LAB_00440992                                                 XREF[1]:     0044098b(j)  
    //                              dlg_smsg.cpp:165 (4)
    //         00440992     MOV        dword ptr [ESP + world],EAX
    //                               LAB_00440996                                                 XREF[2]:     0044097a(j), 00440990(j)  
    //                              dlg_smsg.cpp:159 (16)
    //         00440996     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0044099c     INC        EBP
    //         0044099d     CALL       RGE_Base_Game::numberPlayers                     int numberPlayers(RGE_Base_Game * this)
    //         004409a2     CMP        EBP,EAX
    //         004409a4     JLE        LAB_0044096a
    //                               LAB_004409a6                                                 XREF[1]:     00440968(j)  
    //                              dlg_smsg.cpp:168 (14)
    //         004409a6     MOV        EAX,dword ptr [ESP + world]
    //         004409aa     CMP        EAX,0x2
    //         004409ad     JZ         LAB_004409b9
    //         004409af     CMP        EAX,0x4
    //         004409b2     JZ         LAB_004409b9
    //                               LAB_004409b4                                                 XREF[1]:     00440941(j)  
    //                              dlg_smsg.cpp:169 (5)
    //         004409b4     MOV        EDI,0x1
    //                               LAB_004409b9                                                 XREF[3]:     00440950(j), 004409ad(j), 
    //                                                                                                         004409b2(j)  
    //                              dlg_smsg.cpp:172 (6)
    //         004409b9     NEG        EDI
    //         004409bb     MOV        this,dword ptr [ESP + i]
    //                              dlg_smsg.cpp:176 (65)
    //         004409bf     MOV        EDX,dword ptr [ESP + humanity]
    //         004409c3     SBB        EDI,EDI
    //         004409c5     PUSH       0x0
    //         004409c7     AND        EDI,0xfffffffd
    //         004409ca     PUSH       0x1
    //         004409cc     ADD        EDI,0xb
    //         004409cf     PUSH       0x0
    //         004409d1     PUSH       EDI
    //         004409d2     PUSH       0x1e
    //         004409d4     PUSH       0xbe
    //         004409d9     PUSH       EBX
    //         004409da     LEA        EBP,[this->_padding_ + -0x20]
    //         004409dd     MOV        this,dword ptr [comm]                            = 00000000
    //         004409e3     PUSH       0x32
    //         004409e5     PUSH       EDX
    //         004409e6     CALL       TCommunications_Handler::GetPlayerName           char * GetPlayerName(TCommunications_Handler 
    //         004409eb     PUSH       EAX
    //         004409ec     LEA        EAX,[EBP + -0x20]
    //         004409ef     PUSH       EAX
    //         004409f0     PUSH       ESI
    //         004409f1     MOV        this,ESI
    //         004409f3     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         004409f8     TEST       EAX,EAX
    //         004409fa     JZ         LAB_00440dda
    //                              dlg_smsg.cpp:179 (45)
    //         00440a00     MOV        EDI,dword ptr [ESP + local_78]
    //         00440a04     LEA        EAX=>temp_str[4],[ESP + 0x2c]
    //         00440a08     PUSH       0x64
    //         00440a0a     PUSH       EAX
    //         00440a0b     MOV        EAX,dword ptr [ESP + id]
    //         00440a0f     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00440a15     PUSH       0x0
    //         00440a17     MOV        EAX,dword ptr [EAX + 0x40]
    //         00440a1a     MOV        EDX,dword ptr [this->_padding_]
    //         00440a1c     MOV        EDI,dword ptr [EAX + EDI*0x1]
    //         00440a1f     XOR        EAX,EAX
    //         00440a21     MOV        AL,byte ptr [EDI + 0x105]
    //         00440a27     PUSH       EAX
    //         00440a28     PUSH       0x69
    //         00440a2a     CALL       dword ptr [EDX + 0x28]
    //                              dlg_smsg.cpp:180 (40)
    //         00440a2d     PUSH       0x0
    //         00440a2f     PUSH       offset DAT_fffffff8
    //         00440a31     PUSH       0x0=>DAT_fffffff4
    //         00440a33     PUSH       offset DAT_fffffff0
    //         00440a35     PUSH       0x1e
    //                              language.dll match for 0x78: "10"
    //         00440a37     PUSH       0x78
    //         00440a39     PUSH       EBX
    //         00440a3a     LEA        this,[ESP + 0x48]
    //         00440a3e     PUSH       0x104
    //         00440a43     PUSH       this
    //         00440a44     PUSH       EBP
    //         00440a45     PUSH       ESI
    //         00440a46     MOV        this,ESI
    //         00440a48     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         00440a4d     TEST       EAX,EAX
    //         00440a4f     JZ         LAB_00440dda
    //                              dlg_smsg.cpp:182 (53)
    //         00440a55     MOV        this,dword ptr [comm]                            = 00000000
    //         00440a5b     CALL       TCommunications_Handler::WhoAmI                  int WhoAmI(TCommunications_Handler * this)
    //         00440a60     MOV        EBP,dword ptr [ESP + 0x14]
    //         00440a64     CMP        EBP,EAX
    //         00440a66     JZ         LAB_00440ae2
    //         00440a68     MOV        this,dword ptr [comm]                            = 00000000
    //         00440a6e     PUSH       EBP
    //         00440a6f     CALL       TCommunications_Handler::GetPlayerHumanity       int GetPlayerHumanity(TCommunications_Handler
    //         00440a74     CMP        EAX,0x2
    //         00440a77     JZ         LAB_00440a8a
    //         00440a79     MOV        this,dword ptr [comm]                            = 00000000
    //         00440a7f     PUSH       EBP
    //         00440a80     CALL       TCommunications_Handler::GetPlayerHumanity       int GetPlayerHumanity(TCommunications_Handler
    //         00440a85     CMP        EAX,0x4
    //         00440a88     JNZ        LAB_00440ae2
    //                               LAB_00440a8a                                                 XREF[1]:     00440a77(j)  
    //                              dlg_smsg.cpp:187 (32)
    //         00440a8a     MOV        EDI,dword ptr [ESP + 0x10]
    //         00440a8e     PUSH       0x0
    //         00440a90     PUSH       0x0=>DAT_fffffff8
    //         00440a92     PUSH       offset DAT_fffffff4
    //         00440a94     PUSH       offset DAT_fffffff0
    //         00440a96     PUSH       EBX
    //         00440a97     PUSH       0xa
    //         00440a99     PUSH       EDI
    //         00440a9a     PUSH       ESI
    //         00440a9b     MOV        this,ESI
    //         00440a9d     CALL       TEasy_Panel::create_check_box                    int create_check_box(TEasy_Panel * this, TPan
    //         00440aa2     TEST       EAX,EAX
    //         00440aa4     JZ         LAB_00440dda
    //                              dlg_smsg.cpp:188 (14)
    //         00440aaa     MOV        this,dword ptr [EDI]
    //         00440aac     PUSH       -0x1
    //                              language.dll match for 0x767f: "Click to send a message to th
    //         00440aae     PUSH       offset DAT_fffffff8
    //         00440ab3     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              dlg_smsg.cpp:192 (12)
    //         00440ab8     MOV        this,dword ptr [chat]                            = 00000000
    //         00440abe     PUSH       EBP
    //         00440abf     CALL       TChat::inChatGroup                               int inChatGroup(TChat * this, int param_1)
    //                              dlg_smsg.cpp:193 (16)
    //         00440ac4     MOV        this,dword ptr [EDI]
    //         00440ac6     TEST       EAX,EAX
    //         00440ac8     JZ         LAB_00440ad6
    //         00440aca     MOV        EDX,dword ptr [this->_padding_]
    //         00440acc     PUSH       0x1
    //         00440ace     CALL       dword ptr [EDX + 0xe0]
    //                              dlg_smsg.cpp:194 (2)
    //         00440ad4     JMP        LAB_00440ae6
    //                               LAB_00440ad6                                                 XREF[1]:     00440ac8(j)  
    //                              dlg_smsg.cpp:195 (16)
    //         00440ad6     MOV        EAX,dword ptr [this->_padding_]
    //         00440ad8     PUSH       0x0
    //         00440ada     CALL       dword ptr [EAX + 0xe0]
    //         00440ae0     JMP        LAB_00440ae6
    //                               LAB_00440ae2                                                 XREF[2]:     00440a66(j), 00440a88(j)  
    //         00440ae2     MOV        EDI,dword ptr [ESP + 0x10]
    //                               LAB_00440ae6                                                 XREF[2]:     00440ad4(j), 00440ae0(j)  
    //                              dlg_smsg.cpp:198 (3)
    //         00440ae6     MOV        dword ptr [EDI + 0x58],EBP
    //                              dlg_smsg.cpp:200 (30)
    //         00440ae9     ADD        EDI,0x4
    //         00440aec     MOV        dword ptr [ESP + 0x10],EDI
    //         00440af0     MOV        EDI,dword ptr [ESP + 0x14]
    //         00440af4     ADD        EBX,0x1e
    //         00440af7     XOR        EBP,EBP
    //                               LAB_00440af9                                                 XREF[1]:     00440921(j)  
    //         00440af9     INC        EDI
    //         00440afa     CMP        EDI,0x9
    //         00440afd     MOV        dword ptr [ESP + humanity],EDI
    //         00440b01     JL         LAB_0044090f
    //                              dlg_smsg.cpp:204 (46)
    //         00440b07     PUSH       EBP
    //         00440b08     PUSH       offset DAT_fffffff8
    //         00440b0a     PUSH       offset DAT_fffffff4
    //         00440b0c     PUSH       offset DAT_fffffff0
    //         00440b0e     PUSH       0x1e
    //         00440b10     PUSH       0x78
    //         00440b12     PUSH       0x13b
    //         00440b17     PUSH       0xa
    //         00440b19     LEA        EAX,[ESI + 0x51c]
    //                              language.dll match for 0x2668: "Chat"
    //         00440b1f     PUSH       0x2668
    //         00440b24     PUSH       EAX
    //         00440b25     PUSH       ESI
    //         00440b26     MOV        this,ESI
    //         00440b28     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         00440b2d     TEST       EAX,EAX
    //         00440b2f     JZ         LAB_00440dda
    //                              dlg_smsg.cpp:206 (53)
    //         00440b35     PUSH       EBP
    //         00440b36     PUSH       offset DAT_fffffff8
    //         00440b38     PUSH       offset DAT_fffffff4
    //         00440b3a     PUSH       offset DAT_fffffff0
    //         00440b3c     PUSH       0x17c
    //         00440b41     PUSH       0x13b
    //                              language.dll match for 0x82: "B"
    //         00440b46     PUSH       0x82
    //         00440b4b     PUSH       EBP
    //         00440b4c     PUSH       0x41
    //         00440b4e     LEA        EDI,[ESI + 0x518]
    //         00440b54     PUSH       s_                                               = ""
    //         00440b59     PUSH       EDI
    //         00440b5a     PUSH       ESI
    //         00440b5b     MOV        this,ESI
    //         00440b5d     CALL       TEasy_Panel::create_edit                         int create_edit(TEasy_Panel * this, TPanel * 
    //         00440b62     TEST       EAX,EAX
    //         00440b64     JZ         LAB_00440dda
    //                              dlg_smsg.cpp:207 (14)
    //         00440b6a     MOV        this,dword ptr [EDI]
    //         00440b6c     PUSH       -0x1
    //                              language.dll match for 0x767a: "Type a message. Press ENTER t
    //         00440b6e     PUSH       offset DAT_fffffff8
    //         00440b73     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              dlg_smsg.cpp:209 (36)
    //         00440b78     PUSH       EBP
    //         00440b79     PUSH       EBP=>DAT_fffffff8
    //         00440b7a     PUSH       offset DAT_fffffff4
    //         00440b7c     PUSH       offset DAT_fffffff0
    //         00440b7e     PUSH       0x15e
    //         00440b83     LEA        EBP,[ESI + 0x504]
    //         00440b89     PUSH       0x2d
    //         00440b8b     PUSH       EBP
    //         00440b8c     PUSH       ESI
    //         00440b8d     MOV        this,ESI
    //         00440b8f     CALL       TEasy_Panel::create_radio_button                 int create_radio_button(TEasy_Panel * this, T
    //         00440b94     TEST       EAX,EAX
    //         00440b96     JZ         LAB_00440dda
    //                              dlg_smsg.cpp:210 (41)
    //         00440b9c     PUSH       0x0
    //         00440b9e     PUSH       0x0=>DAT_fffffff8
    //         00440ba0     PUSH       offset DAT_fffffff4
    //         00440ba2     PUSH       offset DAT_fffffff0
    //         00440ba4     LEA        EAX,[ESI + 0x508]
    //         00440baa     PUSH       0x15e
    //         00440baf     PUSH       0x113
    //         00440bb4     PUSH       EAX
    //         00440bb5     PUSH       ESI
    //         00440bb6     MOV        this,ESI
    //         00440bb8     CALL       TEasy_Panel::create_radio_button                 int create_radio_button(TEasy_Panel * this, T
    //         00440bbd     TEST       EAX,EAX
    //         00440bbf     JZ         LAB_00440dda
    //                              dlg_smsg.cpp:211 (38)
    //         00440bc5     PUSH       0x0
    //         00440bc7     PUSH       0x0=>DAT_fffffff8
    //         00440bc9     PUSH       offset DAT_fffffff4
    //         00440bcb     PUSH       offset DAT_fffffff0
    //         00440bcd     LEA        EAX,[ESI + 0x50c]
    //         00440bd3     PUSH       0x181
    //         00440bd8     PUSH       0x2d
    //         00440bda     PUSH       EAX
    //         00440bdb     PUSH       ESI
    //         00440bdc     MOV        this,ESI
    //         00440bde     CALL       TEasy_Panel::create_radio_button                 int create_radio_button(TEasy_Panel * this, T
    //         00440be3     TEST       EAX,EAX
    //         00440be5     JZ         LAB_00440dda
    //                              dlg_smsg.cpp:212 (41)
    //         00440beb     PUSH       0x0
    //         00440bed     PUSH       0x0=>DAT_fffffff8
    //         00440bef     PUSH       offset DAT_fffffff4
    //         00440bf1     PUSH       offset DAT_fffffff0
    //         00440bf3     LEA        EAX,[ESI + 0x510]
    //         00440bf9     PUSH       0x181
    //         00440bfe     PUSH       0x113
    //         00440c03     PUSH       EAX
    //         00440c04     PUSH       ESI
    //         00440c05     MOV        this,ESI
    //         00440c07     CALL       TEasy_Panel::create_radio_button                 int create_radio_button(TEasy_Panel * this, T
    //         00440c0c     TEST       EAX,EAX
    //         00440c0e     JZ         LAB_00440dda
    //                              dlg_smsg.cpp:215 (50)
    //         00440c14     PUSH       0x0
    //         00440c16     PUSH       offset DAT_fffffff8
    //         00440c18     PUSH       0x0=>DAT_fffffff4
    //         00440c1a     PUSH       offset DAT_fffffff0
    //         00440c1c     PUSH       0x1e
    //         00440c1e     PUSH       0xc8
    //         00440c23     PUSH       0x15e
    //         00440c28     LEA        EDI,[ESI + 0x4f4]
    //         00440c2e     PUSH       0x4b
    //                              language.dll match for 0x2669: "Allies"
    //         00440c30     PUSH       0x2669
    //         00440c35     PUSH       EDI
    //         00440c36     PUSH       ESI
    //         00440c37     MOV        this,ESI
    //         00440c39     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         00440c3e     TEST       EAX,EAX
    //         00440c40     JZ         LAB_00440dda
    //                              dlg_smsg.cpp:216 (11)
    //         00440c46     MOV        this,dword ptr [EDI]
    //         00440c48     PUSH       -0x1
    //         00440c4a     PUSH       offset DAT_fffffff8
    //         00440c4c     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              dlg_smsg.cpp:217 (53)
    //         00440c51     PUSH       0x0
    //         00440c53     PUSH       offset DAT_fffffff8
    //         00440c55     PUSH       0x0=>DAT_fffffff4
    //         00440c57     PUSH       offset DAT_fffffff0
    //         00440c59     PUSH       0x1e
    //         00440c5b     PUSH       0xc8
    //         00440c60     PUSH       0x15e
    //         00440c65     LEA        EDI,[ESI + 0x4f8]
    //         00440c6b     PUSH       0x131
    //                              language.dll match for 0x266a: "Enemies"
    //         00440c70     PUSH       0x266a
    //         00440c75     PUSH       EDI
    //         00440c76     PUSH       ESI
    //         00440c77     MOV        this,ESI
    //         00440c79     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         00440c7e     TEST       EAX,EAX
    //         00440c80     JZ         LAB_00440dda
    //                              dlg_smsg.cpp:218 (11)
    //         00440c86     MOV        this,dword ptr [EDI]
    //         00440c88     PUSH       -0x1
    //         00440c8a     PUSH       offset DAT_fffffff8
    //         00440c8c     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              dlg_smsg.cpp:220 (50)
    //         00440c91     PUSH       0x0
    //         00440c93     PUSH       offset DAT_fffffff8
    //         00440c95     PUSH       0x0=>DAT_fffffff4
    //         00440c97     PUSH       offset DAT_fffffff0
    //         00440c99     PUSH       0x1e
    //         00440c9b     PUSH       0xc8
    //         00440ca0     PUSH       0x181
    //         00440ca5     LEA        EDI,[ESI + 0x4fc]
    //         00440cab     PUSH       0x4b
    //                              language.dll match for 0x266b: "Everyone"
    //         00440cad     PUSH       0x266b
    //         00440cb2     PUSH       EDI
    //         00440cb3     PUSH       ESI
    //         00440cb4     MOV        this,ESI
    //         00440cb6     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         00440cbb     TEST       EAX,EAX
    //         00440cbd     JZ         LAB_00440dda
    //                              dlg_smsg.cpp:221 (11)
    //         00440cc3     MOV        this,dword ptr [EDI]
    //         00440cc5     PUSH       -0x1
    //         00440cc7     PUSH       offset DAT_fffffff8
    //         00440cc9     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              dlg_smsg.cpp:222 (53)
    //         00440cce     PUSH       0x0
    //         00440cd0     PUSH       offset DAT_fffffff8
    //         00440cd2     PUSH       0x0=>DAT_fffffff4
    //         00440cd4     PUSH       offset DAT_fffffff0
    //         00440cd6     PUSH       0x1e
    //         00440cd8     PUSH       0xc8
    //         00440cdd     PUSH       0x181
    //         00440ce2     LEA        EDI,[ESI + 0x500]
    //         00440ce8     PUSH       0x131
    //                              language.dll match for 0x266e: "Select Player"
    //         00440ced     PUSH       0x266e
    //         00440cf2     PUSH       EDI
    //         00440cf3     PUSH       ESI
    //         00440cf4     MOV        this,ESI
    //         00440cf6     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         00440cfb     TEST       EAX,EAX
    //         00440cfd     JZ         LAB_00440dda
    //                              dlg_smsg.cpp:223 (18)
    //         00440d03     MOV        this,dword ptr [EDI]
    //         00440d05     PUSH       -0x1
    //         00440d07     PUSH       offset DAT_fffffff8
    //         00440d09     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //         00440d0e     MOV        EDI,EBP
    //         00440d10     MOV        EBX,0x4
    //                               LAB_00440d15                                                 XREF[1]:     00440d23(j)  
    //                              dlg_smsg.cpp:226 (16)
    //         00440d15     MOV        this,dword ptr [EDI]
    //         00440d17     PUSH       0x4
    //         00440d19     PUSH       EBP=>DAT_fffffff8
    //         00440d1a     CALL       TButtonPanel::set_radio_info                     void set_radio_info(TButtonPanel * this, TBut
    //         00440d1f     ADD        EDI,0x4
    //         00440d22     DEC        EBX
    //         00440d23     JNZ        LAB_00440d15
    //                              dlg_smsg.cpp:227 (16)
    //         00440d25     MOV        this,dword ptr [ESI + 0x510]
    //         00440d2b     PUSH       0x1
    //         00440d2d     MOV        EDX,dword ptr [this->_padding_]
    //         00440d2f     CALL       dword ptr [EDX + 0xe0]
    //                              dlg_smsg.cpp:229 (15)
    //         00440d35     MOV        this,dword ptr [EBP]
    //         00440d38     PUSH       -0x1
    //                              language.dll match for 0x767b: "Click to send a message to al
    //         00440d3a     PUSH       offset DAT_fffffff8
    //         00440d3f     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              dlg_smsg.cpp:230 (18)
    //         00440d44     MOV        this,dword ptr [ESI + 0x508]
    //         00440d4a     PUSH       -0x1
    //                              language.dll match for 0x767c: "Click to send a message to al
    //         00440d4c     PUSH       offset DAT_fffffff8
    //         00440d51     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              dlg_smsg.cpp:231 (18)
    //         00440d56     MOV        this,dword ptr [ESI + 0x50c]
    //         00440d5c     PUSH       -0x1
    //                              language.dll match for 0x767d: "Click to send a message to al
    //         00440d5e     PUSH       offset DAT_fffffff8
    //         00440d63     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              dlg_smsg.cpp:232 (18)
    //         00440d68     MOV        this,dword ptr [ESI + 0x510]
    //         00440d6e     PUSH       -0x1
    //                              language.dll match for 0x767e: "Select which players receive 
    //         00440d70     PUSH       offset DAT_fffffff8
    //         00440d75     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              dlg_smsg.cpp:235 (46)
    //         00440d7a     PUSH       0x0
    //         00440d7c     PUSH       0x0=>DAT_fffffff8
    //         00440d7e     PUSH       0x0=>DAT_fffffff4
    //         00440d80     PUSH       offset DAT_fffffff0
    //         00440d82     PUSH       0x12c
    //         00440d87     PUSH       0x1a9
    //         00440d8c     PUSH       0x64
    //         00440d8e     PUSH       0x0
    //         00440d90     LEA        EDI,[ESI + 0x520]
    //                              language.dll match for 0x266c: "Return to Game"
    //         00440d96     PUSH       0x266c
    //         00440d9b     PUSH       EDI
    //         00440d9c     PUSH       ESI
    //         00440d9d     MOV        this,ESI
    //         00440d9f     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         00440da4     TEST       EAX,EAX
    //         00440da6     JZ         LAB_00440dda
    //                              dlg_smsg.cpp:236 (14)
    //         00440da8     MOV        this,dword ptr [EDI]
    //         00440daa     PUSH       -0x1
    //         00440dac     PUSH       offset DAT_fffffff8
    //         00440db1     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              dlg_smsg.cpp:237 (2)
    //         00440db6     MOV        EDI,dword ptr [EDI]
    //                              dlg_smsg.cpp:243 (34)
    //         00440db8     MOV        this,ESI
    //         00440dba     MOV        dword ptr [EDI + 0x298],0x1b
    //         00440dc4     MOV        dword ptr [EDI + 0x29c],0x0
    //         00440dce     MOV        EAX,dword ptr [ESI + 0x518]
    //         00440dd4     PUSH       EAX
    //         00440dd5     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                               LAB_00440dda                                                 XREF[17]:    0044087c(j), 004408b7(j), 
    //                                                                                                         004408e1(j), 004409fa(j), 
    //                                                                                                         00440a4f(j), 00440aa4(j), 
    //                                                                                                         00440b2f(j), 00440b64(j), 
    //                                                                                                         00440b96(j), 00440bbf(j), 
    //                                                                                                         00440be5(j), 00440c0e(j), 
    //                                                                                                         00440c40(j), 00440c80(j), 
    //                                                                                                         00440cbd(j), 00440cfd(j), 
    //                                                                                                         00440da6(j)  
    //                              dlg_smsg.cpp:244 (29)
    //         00440dda     MOV        this,dword ptr [ESP + local_c]
    //         00440de1     MOV        EAX,ESI
    //         00440de3     POP        EDI
    //         00440de4     POP        ESI
    //         00440de5     POP        EBP
    //         00440de6     MOV        dword ptr FS:[0x0],this
    //         00440ded     POP        EBX
    //         00440dee     ADD        ESP,0x8c
    //         00440df4     RET        0x4
}

// Offset: 0x00440E20
void TribeSendMessageDialog(TribeSendMessageDialog* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall TribeSendMessageDialog::~TribeSendMessageDialog(void)                      *
    //                              *********************************************************************************************************
    //                              void __thiscall ~TribeSendMessageDialog(TribeSendMessageDialog * this)
    //              void              <VOID>         <RETURN>
    //              TribeSendMessa    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00440e4b(W), 00440f00(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00440f0d(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00440e3b(W)  
    //                               ??1TribeSendMessageDialog@@UAE@XZ                            XREF[1]:     `scalar_deleting_destructor':00440
    //                               TribeSendMessageDialog::~TribeSendMessageDialog
    //                              dlg_smsg.cpp:249 (37)
    //         00440e20     PUSH       -0x1
    //         00440e22     PUSH       FUN_0055d238
    //         00440e27     MOV        EAX,FS:[0x0]
    //         00440e2d     PUSH       EAX
    //         00440e2e     MOV        dword ptr FS:[0x0],ESP
    //         00440e35     PUSH       this
    //         00440e36     PUSH       EBX
    //         00440e37     PUSH       ESI
    //         00440e38     MOV        ESI,this
    //         00440e3a     PUSH       EDI
    //         00440e3b     MOV        dword ptr [ESP + local_10],ESI
    //         00440e3f     MOV        dword ptr [ESI],TribeSendMessageDialog::`vftab   = 00440e00
    //                              dlg_smsg.cpp:250 (31)
    //         00440e45     LEA        EAX,[ESI + 0x490]
    //         00440e4b     MOV        dword ptr [ESP + local_4],0x0
    //         00440e53     PUSH       EAX
    //         00440e54     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         00440e59     LEA        EDI,[ESI + 0x4b4]
    //         00440e5f     MOV        EBX,0x8
    //                               LAB_00440e64                                                 XREF[1]:     00440e86(j)  
    //                              dlg_smsg.cpp:251 (3)
    //         00440e64     LEA        this,[EDI + -0x20]
    //                              dlg_smsg.cpp:252 (8)
    //         00440e67     PUSH       this
    //         00440e68     MOV        this,ESI
    //         00440e6a     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              dlg_smsg.cpp:253 (11)
    //         00440e6f     PUSH       EDI
    //         00440e70     MOV        this,ESI
    //         00440e72     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         00440e77     LEA        EDX,[EDI + 0x20]
    //                              dlg_smsg.cpp:254 (14)
    //         00440e7a     MOV        this,ESI
    //         00440e7c     PUSH       EDX
    //         00440e7d     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         00440e82     ADD        EDI,0x4
    //         00440e85     DEC        EBX
    //         00440e86     JNZ        LAB_00440e64
    //                              dlg_smsg.cpp:267 (151)
    //         00440e88     LEA        EDI,[ESI + 0x504]
    //         00440e8e     MOV        EBX,0x4
    //                               LAB_00440e93                                                 XREF[1]:     00440eaa(j)  
    //         00440e93     LEA        EAX,[EDI + -0x10]
    //         00440e96     MOV        this,ESI
    //         00440e98     PUSH       EAX
    //         00440e99     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         00440e9e     PUSH       EDI
    //         00440e9f     MOV        this,ESI
    //         00440ea1     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         00440ea6     ADD        EDI,0x4
    //         00440ea9     DEC        EBX
    //         00440eaa     JNZ        LAB_00440e93
    //         00440eac     LEA        this,[ESI + 0x518]
    //         00440eb2     PUSH       this
    //         00440eb3     MOV        this,ESI
    //         00440eb5     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         00440eba     LEA        EDX,[ESI + 0x51c]
    //         00440ec0     MOV        this,ESI
    //         00440ec2     PUSH       EDX
    //         00440ec3     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         00440ec8     LEA        EAX,[ESI + 0x520]
    //         00440ece     MOV        this,ESI
    //         00440ed0     PUSH       EAX
    //         00440ed1     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         00440ed6     LEA        this,[ESI + 0x524]
    //         00440edc     PUSH       this
    //         00440edd     MOV        this,ESI
    //         00440edf     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         00440ee4     MOV        EDI,dword ptr [ESI + 0x528]
    //         00440eea     TEST       EDI,EDI
    //         00440eec     JZ         LAB_00440efe
    //         00440eee     MOV        this,EDI
    //         00440ef0     CALL       TShape::~TShape                                  void ~TShape(TShape * this)
    //         00440ef5     PUSH       EDI
    //         00440ef6     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00440efb     ADD        ESP,0x4
    //                               LAB_00440efe                                                 XREF[1]:     00440eec(j)  
    //         00440efe     MOV        this,ESI
    //         00440f00     MOV        dword ptr [ESP + local_4],0xffffffff
    //         00440f08     CALL       TDialogPanel::~TDialogPanel                      void ~TDialogPanel(TDialogPanel * this)
    //         00440f0d     MOV        this,dword ptr [ESP + local_c]
    //         00440f11     POP        EDI
    //         00440f12     POP        ESI
    //         00440f13     MOV        dword ptr FS:[0x0],this
    //         00440f1a     POP        EBX
    //         00440f1b     ADD        ESP,0x10
    //         00440f1e     RET
}

// Offset: 0x00440F20
long TribeSendMessageDialog::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: virtual long __thiscall TribeSendMessageDialog::action(class TPanel *,long,unsigned lon... *
    //                              *********************************************************************************************************
    //                              long __thiscall action(TribeSendMessageDialog * this, TPanel * param
    //              long              EAX:4          <RETURN>
    //              TribeSendMessa    ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     00440f20(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[4]:     00440f43(R), 00441068(R), 00441340(R), 004413f6(R)  
    //              ulong             Stack[0xc]:4   param_3                   XREF[1]:     004413f2(R)  
    //              ulong             Stack[0x10]:4  param_4                   XREF[1]:     004413ee(R)  
    //              char[66]          Stack[-0x48]   save_msg                  XREF[0,8]:   00440f7d(*), 00440f9b(W), 00440fa0(R), 00440fb2(*), 
    //                                                                                     004410ae(*), 004410cc(W), 004410f1(R), 00441103(*)  
    //                               ?action@TribeSendMessageDialog@@MAEJPAVTPanel@@JKK@Z         XREF[1]:     00570074(*)  
    //                               TribeSendMessageDialog::action
    //                              dlg_smsg.cpp:273 (21)
    //         00440f20     MOV        EAX,dword ptr [ESP + param_1]
    //         00440f24     SUB        ESP,0x44
    //         00440f27     TEST       EAX,EAX
    //         00440f29     PUSH       EBX
    //         00440f2a     PUSH       EBP
    //         00440f2b     PUSH       ESI
    //         00440f2c     PUSH       EDI
    //         00440f2d     MOV        EBP,this
    //         00440f2f     JZ         LAB_004413ee
    //                              dlg_smsg.cpp:277 (14)
    //         00440f35     MOV        this,dword ptr [EBP + 0x518]
    //         00440f3b     CMP        EAX,this
    //         00440f3d     JNZ        LAB_0044105c
    //                              dlg_smsg.cpp:278 (12)
    //         00440f43     MOV        EAX,dword ptr [ESP + param_2]
    //         00440f47     TEST       EAX,EAX
    //         00440f49     JNZ        LAB_004413df
    //                              dlg_smsg.cpp:280 (3)
    //         00440f4f     MOV        EBX,dword ptr [EBP + 0x40]
    //                              dlg_smsg.cpp:283 (25)
    //         00440f52     CALL       TEditPanel::currentLine                          char * currentLine(TEditPanel * this)
    //         00440f57     TEST       EAX,EAX
    //         00440f59     JZ         LAB_00440f9b
    //         00440f5b     MOV        this,dword ptr [EBP + 0x518]
    //         00440f61     CALL       TEditPanel::currentLine                          char * currentLine(TEditPanel * this)
    //         00440f66     CMP        byte ptr [EAX],0x0
    //         00440f69     JZ         LAB_00440f9b
    //                              dlg_smsg.cpp:284 (46)
    //         00440f6b     MOV        this,dword ptr [EBP + 0x518]
    //         00440f71     CALL       TEditPanel::currentLine                          char * currentLine(TEditPanel * this)
    //         00440f76     MOV        EDI,EAX
    //         00440f78     OR         this,0xffffffff
    //         00440f7b     XOR        EAX,EAX
    //         00440f7d     LEA        EDX=>save_msg[4],[ESP + 0x10]
    //         00440f81     SCASB.RE   ES:EDI
    //         00440f83     NOT        this
    //         00440f85     SUB        EDI,this
    //         00440f87     MOV        EAX,this
    //         00440f89     MOV        ESI,EDI
    //         00440f8b     MOV        EDI,EDX
    //         00440f8d     SHR        this,0x2
    //         00440f90     MOVSD.REP  ES:EDI,ESI
    //         00440f92     MOV        this,EAX
    //         00440f94     AND        this,0x3
    //         00440f97     MOVSB.REP  ES:EDI,ESI
    //                              dlg_smsg.cpp:285 (2)
    //         00440f99     JMP        LAB_00440fa0
    //                               LAB_00440f9b                                                 XREF[2]:     00440f59(j), 00440f69(j)  
    //                              dlg_smsg.cpp:286 (5)
    //         00440f9b     MOV        byte ptr [ESP + save_msg[4]],0x0
    //                               LAB_00440fa0                                                 XREF[1]:     00440f99(j)  
    //                              dlg_smsg.cpp:288 (12)
    //         00440fa0     MOV        AL,byte ptr [ESP + save_msg[4]]
    //         00440fa4     TEST       AL,AL
    //         00440fa6     JZ         LAB_004413df
    //                              dlg_smsg.cpp:290 (31)
    //         00440fac     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00440fb2     LEA        EAX=>save_msg[4],[ESP + 0x10]
    //         00440fb6     PUSH       EAX
    //         00440fb7     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         00440fbd     MOV        EDX,dword ptr [this->_padding_]
    //         00440fbf     MOVSX      EAX,word ptr [EAX + 0x7c]
    //         00440fc3     PUSH       EAX
    //         00440fc4     CALL       dword ptr [EDX + 0x54]
    //         00440fc7     TEST       EAX,EAX
    //         00440fc9     JNZ        LAB_0044103d
    //                              dlg_smsg.cpp:292 (15)
    //         00440fcb     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00440fd1     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
    //         00440fd6     TEST       EAX,EAX
    //         00440fd8     JZ         LAB_00441024
    //                              dlg_smsg.cpp:294 (15)
    //         00440fda     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00440fe0     CMP        dword ptr [ECX + this->_padding_],0x5
    //         00440fe7     JZ         LAB_0044103d
    //                              dlg_smsg.cpp:296 (16)
    //         00440fe9     MOV        this,dword ptr [comm]                            = 00000000
    //         00440fef     LEA        EDX,[ESP + 0x10]
    //         00440ff3     PUSH       EDX
    //         00440ff4     CALL       TCommunications_Handler::SendGroupChatMsg        void SendGroupChatMsg(TCommunications_Handler
    //                              dlg_smsg.cpp:298 (41)
    //         00440ff9     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00440fff     LEA        EAX,[ESP + 0x10]
    //         00441003     PUSH       EAX
    //         00441004     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0044100a     MOV        this,dword ptr [L]                               = 00000000
    //         00441010     MOV        EAX,dword ptr [EDX + 0x4]
    //         00441013     PUSH       EAX=>DAT_fffffff8
    //         00441014     PUSH       s_$$$_SEND_CHAT_@%u:_%s                          = "$$$ SEND CHAT @%u: %s"
    //         00441019     PUSH       this=>DAT_fffffff0
    //         0044101a     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         0044101f     ADD        ESP,0x10
    //                              dlg_smsg.cpp:302 (2)
    //         00441022     JMP        LAB_0044103d
    //                               LAB_00441024                                                 XREF[1]:     00440fd8(j)  
    //                              dlg_smsg.cpp:304 (13)
    //         00441024     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0044102a     PUSH       0x2
    //         0044102c     CALL       RGE_Base_Game::play_sound                        int play_sound(RGE_Base_Game * this, int para
    //                              dlg_smsg.cpp:305 (12)
    //         00441031     LEA        EDX,[ESP + 0x10]
    //         00441035     MOV        this,EBX
    //         00441037     PUSH       EDX
    //         00441038     CALL       TRIBE_Screen_Game::display_system_message        void display_system_message(TRIBE_Screen_Game
    //                               LAB_0044103d                                                 XREF[3]:     00440fc9(j), 00440fe7(j), 
    //                                                                                                         00441022(j)  
    //                              dlg_smsg.cpp:308 (16)
    //         0044103d     MOV        this,dword ptr [EBP + 0x518]
    //         00441043     PUSH       s_                                               = ""
    //         00441048     CALL       TEditPanel::set_text                             void set_text(TEditPanel * this, char * param
    //                              dlg_smsg.cpp:311 (5)
    //         0044104d     MOV        EAX,0x1
    //                              dlg_smsg.cpp:436 (10)
    //         00441052     POP        EDI
    //         00441053     POP        ESI
    //         00441054     POP        EBP
    //         00441055     POP        EBX
    //         00441056     ADD        ESP,0x44
    //         00441059     RET        0x10
    //                               LAB_0044105c                                                 XREF[1]:     00440f3d(j)  
    //                              dlg_smsg.cpp:313 (12)
    //         0044105c     CMP        EAX,dword ptr [EBP + 0x520]
    //         00441062     JNZ        LAB_004411b2
    //                              dlg_smsg.cpp:314 (11)
    //         00441068     CMP        dword ptr [ESP + param_2],0x1
    //         0044106d     JNZ        LAB_004413d8
    //                              dlg_smsg.cpp:315 (7)
    //         00441073     MOV        this,EBP
    //         00441075     CALL       TribeSendMessageDialog::checkButtons             void checkButtons(TribeSendMessageDialog * th
    //                              dlg_smsg.cpp:320 (34)
    //         0044107a     MOV        this,dword ptr [EBP + 0x518]
    //         00441080     MOV        EBX,dword ptr [EBP + 0x40]
    //         00441083     CALL       TEditPanel::currentLine                          char * currentLine(TEditPanel * this)
    //         00441088     TEST       EAX,EAX
    //         0044108a     JZ         LAB_004410cc
    //         0044108c     MOV        this,dword ptr [EBP + 0x518]
    //         00441092     CALL       TEditPanel::currentLine                          char * currentLine(TEditPanel * this)
    //         00441097     CMP        byte ptr [EAX],0x0
    //         0044109a     JZ         LAB_004410cc
    //                              dlg_smsg.cpp:321 (46)
    //         0044109c     MOV        this,dword ptr [EBP + 0x518]
    //         004410a2     CALL       TEditPanel::currentLine                          char * currentLine(TEditPanel * this)
    //         004410a7     MOV        EDI,EAX
    //         004410a9     OR         this,0xffffffff
    //         004410ac     XOR        EAX,EAX
    //         004410ae     LEA        EDX=>save_msg[4],[ESP + 0x10]
    //         004410b2     SCASB.RE   ES:EDI
    //         004410b4     NOT        this
    //         004410b6     SUB        EDI,this
    //         004410b8     MOV        EAX,this
    //         004410ba     MOV        ESI,EDI
    //         004410bc     MOV        EDI,EDX
    //         004410be     SHR        this,0x2
    //         004410c1     MOVSD.REP  ES:EDI,ESI
    //         004410c3     MOV        this,EAX
    //         004410c5     AND        this,0x3
    //         004410c8     MOVSB.REP  ES:EDI,ESI
    //                              dlg_smsg.cpp:322 (2)
    //         004410ca     JMP        LAB_004410d1
    //                               LAB_004410cc                                                 XREF[2]:     0044108a(j), 0044109a(j)  
    //                              dlg_smsg.cpp:323 (5)
    //         004410cc     MOV        byte ptr [ESP + save_msg[4]],0x0
    //                               LAB_004410d1                                                 XREF[1]:     004410ca(j)  
    //                              dlg_smsg.cpp:325 (17)
    //         004410d1     PUSH       0x0
    //         004410d3     PUSH       s_Game_Screen                                    = "Game Screen"
    //         004410d8     MOV        this,panel_system
    //         004410dd     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              dlg_smsg.cpp:326 (15)
    //         004410e2     PUSH       s_Send_Message_Dialog                            = "Send Message Dialog"
    //         004410e7     MOV        this,panel_system
    //         004410ec     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              dlg_smsg.cpp:328 (12)
    //         004410f1     MOV        AL,byte ptr [ESP + save_msg[4]]
    //         004410f5     TEST       AL,AL
    //         004410f7     JZ         LAB_004413df
    //                              dlg_smsg.cpp:330 (35)
    //         004410fd     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00441103     LEA        EAX=>save_msg[4],[ESP + 0x10]
    //         00441107     PUSH       EAX
    //         00441108     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         0044110e     MOV        EDX,dword ptr [this->_padding_]
    //         00441110     MOVSX      EAX,word ptr [EAX + 0x7c]
    //         00441114     PUSH       EAX
    //         00441115     CALL       dword ptr [EDX + 0x54]
    //         00441118     TEST       EAX,EAX
    //         0044111a     JNZ        LAB_004413df
    //                              dlg_smsg.cpp:332 (15)
    //         00441120     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00441126     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
    //         0044112b     TEST       EAX,EAX
    //         0044112d     JZ         LAB_0044118a
    //                              dlg_smsg.cpp:334 (19)
    //         0044112f     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00441135     CMP        dword ptr [ECX + this->_padding_],0x5
    //         0044113c     JZ         LAB_004413df
    //                              dlg_smsg.cpp:336 (16)
    //         00441142     MOV        this,dword ptr [comm]                            = 00000000
    //         00441148     LEA        EDX,[ESP + 0x10]
    //         0044114c     PUSH       EDX
    //         0044114d     CALL       TCommunications_Handler::SendGroupChatMsg        void SendGroupChatMsg(TCommunications_Handler
    //                              dlg_smsg.cpp:338 (41)
    //         00441152     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00441158     LEA        EAX,[ESP + 0x10]
    //         0044115c     PUSH       EAX
    //         0044115d     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         00441163     MOV        this,dword ptr [L]                               = 00000000
    //         00441169     MOV        EAX,dword ptr [EDX + 0x4]
    //         0044116c     PUSH       EAX=>DAT_fffffff8
    //         0044116d     PUSH       s_$$$_SEND_CHAT_@%u:_%s                          = "$$$ SEND CHAT @%u: %s"
    //         00441172     PUSH       this=>DAT_fffffff0
    //         00441173     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00441178     ADD        ESP,0x10
    //                              dlg_smsg.cpp:432 (5)
    //         0044117b     MOV        EAX,0x1
    //                              dlg_smsg.cpp:436 (10)
    //         00441180     POP        EDI
    //         00441181     POP        ESI
    //         00441182     POP        EBP
    //         00441183     POP        EBX
    //         00441184     ADD        ESP,0x44
    //         00441187     RET        0x10
    //                               LAB_0044118a                                                 XREF[1]:     0044112d(j)  
    //                              dlg_smsg.cpp:344 (13)
    //         0044118a     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00441190     PUSH       0x2
    //         00441192     CALL       RGE_Base_Game::play_sound                        int play_sound(RGE_Base_Game * this, int para
    //                              dlg_smsg.cpp:345 (12)
    //         00441197     LEA        EDX,[ESP + 0x10]
    //         0044119b     MOV        this,EBX
    //         0044119d     PUSH       EDX
    //         0044119e     CALL       TRIBE_Screen_Game::display_system_message        void display_system_message(TRIBE_Screen_Game
    //                              dlg_smsg.cpp:349 (5)
    //         004411a3     MOV        EAX,0x1
    //                              dlg_smsg.cpp:436 (10)
    //         004411a8     POP        EDI
    //         004411a9     POP        ESI
    //         004411aa     POP        EBP
    //         004411ab     POP        EBX
    //         004411ac     ADD        ESP,0x44
    //         004411af     RET        0x10
    //                               LAB_004411b2                                                 XREF[1]:     00441062(j)  
    //                              dlg_smsg.cpp:354 (8)
    //         004411b2     CMP        EAX,dword ptr [EBP + 0x524]
    //         004411b8     JNZ        LAB_004411d0
    //                              dlg_smsg.cpp:355 (7)
    //         004411ba     MOV        this,EBP
    //         004411bc     CALL       TEasy_Panel::setup_popup_help                    void setup_popup_help(TEasy_Panel * this)
    //                              dlg_smsg.cpp:356 (5)
    //         004411c1     MOV        EAX,0x1
    //                              dlg_smsg.cpp:436 (10)
    //         004411c6     POP        EDI
    //         004411c7     POP        ESI
    //         004411c8     POP        EBP
    //         004411c9     POP        EBX
    //         004411ca     ADD        ESP,0x44
    //         004411cd     RET        0x10
    //                               LAB_004411d0                                                 XREF[1]:     004411b8(j)  
    //                              dlg_smsg.cpp:366 (104)
    //         004411d0     MOV        this,dword ptr [EBP + 0x4d4]
    //         004411d6     LEA        ESI,[EBP + 0x4d4]
    //         004411dc     CMP        EAX,this
    //         004411de     JZ         LAB_00441398
    //         004411e4     CMP        EAX,dword ptr [EBP + 0x4d8]
    //         004411ea     JZ         LAB_00441398
    //         004411f0     CMP        EAX,dword ptr [EBP + 0x4dc]
    //         004411f6     JZ         LAB_00441398
    //         004411fc     CMP        EAX,dword ptr [EBP + 0x4e0]
    //         00441202     JZ         LAB_00441398
    //         00441208     CMP        EAX,dword ptr [EBP + 0x4e4]
    //         0044120e     JZ         LAB_00441398
    //         00441214     CMP        EAX,dword ptr [EBP + 0x4e8]
    //         0044121a     JZ         LAB_00441398
    //         00441220     CMP        EAX,dword ptr [EBP + 0x4ec]
    //         00441226     JZ         LAB_00441398
    //         0044122c     CMP        EAX,dword ptr [EBP + 0x4f0]
    //         00441232     JZ         LAB_00441398
    //                              dlg_smsg.cpp:374 (8)
    //         00441238     CMP        EAX,dword ptr [EBP + 0x504]
    //         0044123e     JNZ        LAB_004412b8
    //                              dlg_smsg.cpp:376 (5)
    //         00441240     MOV        EAX,[rge_base_game]                              = 00000000
    //                              dlg_smsg.cpp:436 (75)
    //         00441245     MOV        EBX,0x8
    //         0044124a     MOV        EAX,dword ptr [EAX + 0x3f4]
    //         00441250     MOVSX      this,word ptr [EAX + 0x7c]
    //         00441254     MOV        EDX,dword ptr [EAX + 0x40]
    //         00441257     MOV        EDI,dword ptr [EDX + this->_padding_*0x4]
    //                               LAB_0044125a                                                 XREF[1]:     004412a0(j)  
    //         0044125a     CMP        dword ptr [ESI],0x0
    //         0044125d     JZ         LAB_0044129c
    //         0044125f     MOV        EAX,dword ptr [ESI + 0x58]
    //         00441262     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00441268     PUSH       EAX
    //         00441269     CALL       RGE_Base_Game::playerID                          int playerID(RGE_Base_Game * this, int param_1)
    //         0044126e     MOVSX      this,word ptr [EDI + 0x4a]
    //         00441272     CMP        EAX,this
    //         00441274     JZ         LAB_00441290
    //         00441276     MOV        EDX,dword ptr [EDI]
    //         00441278     PUSH       EAX
    //         00441279     MOV        this,EDI
    //         0044127b     CALL       dword ptr [EDX + 0x1c]
    //         0044127e     TEST       EAX,EAX
    //         00441280     JNZ        LAB_00441290
    //         00441282     MOV        this,dword ptr [ESI]
    //         00441284     PUSH       0x0
    //         00441286     MOV        EAX,dword ptr [this->_padding_]
    //         00441288     CALL       dword ptr [EAX + 0xe0]
    //         0044128e     JMP        LAB_0044129c
    //                               LAB_00441290                                                 XREF[2]:     00441274(j), 00441280(j)  
    //                              dlg_smsg.cpp:388 (18)
    //         00441290     MOV        this,dword ptr [ESI]
    //         00441292     PUSH       0x1
    //         00441294     MOV        EDX,dword ptr [this->_padding_]
    //         00441296     CALL       dword ptr [EDX + 0xe0]
    //                               LAB_0044129c                                                 XREF[2]:     0044125d(j), 0044128e(j)  
    //         0044129c     ADD        ESI,0x4
    //         0044129f     DEC        EBX
    //         004412a0     JNZ        LAB_0044125a
    //                              dlg_smsg.cpp:431 (7)
    //         004412a2     MOV        this,EBP
    //         004412a4     CALL       TribeSendMessageDialog::checkButtons             void checkButtons(TribeSendMessageDialog * th
    //                              dlg_smsg.cpp:432 (5)
    //         004412a9     MOV        EAX,0x1
    //                              dlg_smsg.cpp:436 (10)
    //         004412ae     POP        EDI
    //         004412af     POP        ESI
    //         004412b0     POP        EBP
    //         004412b1     POP        EBX
    //         004412b2     ADD        ESP,0x44
    //         004412b5     RET        0x10
    //                               LAB_004412b8                                                 XREF[1]:     0044123e(j)  
    //                              dlg_smsg.cpp:394 (8)
    //         004412b8     CMP        EAX,dword ptr [EBP + 0x508]
    //         004412be     JNZ        LAB_00441338
    //                              dlg_smsg.cpp:396 (5)
    //         004412c0     MOV        EAX,[rge_base_game]                              = 00000000
    //                              dlg_smsg.cpp:436 (75)
    //         004412c5     MOV        EBX,0x8
    //         004412ca     MOV        EAX,dword ptr [EAX + 0x3f4]
    //         004412d0     MOVSX      this,word ptr [EAX + 0x7c]
    //         004412d4     MOV        EDX,dword ptr [EAX + 0x40]
    //         004412d7     MOV        EDI,dword ptr [EDX + this->_padding_*0x4]
    //                               LAB_004412da                                                 XREF[1]:     00441320(j)  
    //         004412da     CMP        dword ptr [ESI],0x0
    //         004412dd     JZ         LAB_0044131c
    //         004412df     MOV        EAX,dword ptr [ESI + 0x58]
    //         004412e2     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004412e8     PUSH       EAX
    //         004412e9     CALL       RGE_Base_Game::playerID                          int playerID(RGE_Base_Game * this, int param_1)
    //         004412ee     MOVSX      this,word ptr [EDI + 0x4a]
    //         004412f2     CMP        EAX,this
    //         004412f4     JZ         LAB_00441310
    //         004412f6     MOV        EDX,dword ptr [EDI]
    //         004412f8     PUSH       EAX
    //         004412f9     MOV        this,EDI
    //         004412fb     CALL       dword ptr [EDX + 0x18]
    //         004412fe     TEST       EAX,EAX
    //         00441300     JZ         LAB_00441310
    //         00441302     MOV        this,dword ptr [ESI]
    //         00441304     PUSH       0x1
    //         00441306     MOV        EAX,dword ptr [this->_padding_]
    //         00441308     CALL       dword ptr [EAX + 0xe0]
    //         0044130e     JMP        LAB_0044131c
    //                               LAB_00441310                                                 XREF[2]:     004412f4(j), 00441300(j)  
    //                              dlg_smsg.cpp:410 (18)
    //         00441310     MOV        this,dword ptr [ESI]
    //         00441312     PUSH       0x0
    //         00441314     MOV        EDX,dword ptr [this->_padding_]
    //         00441316     CALL       dword ptr [EDX + 0xe0]
    //                               LAB_0044131c                                                 XREF[2]:     004412dd(j), 0044130e(j)  
    //         0044131c     ADD        ESI,0x4
    //         0044131f     DEC        EBX
    //         00441320     JNZ        LAB_004412da
    //                              dlg_smsg.cpp:431 (7)
    //         00441322     MOV        this,EBP
    //         00441324     CALL       TribeSendMessageDialog::checkButtons             void checkButtons(TribeSendMessageDialog * th
    //                              dlg_smsg.cpp:432 (5)
    //         00441329     MOV        EAX,0x1
    //                              dlg_smsg.cpp:436 (10)
    //         0044132e     POP        EDI
    //         0044132f     POP        ESI
    //         00441330     POP        EBP
    //         00441331     POP        EBX
    //         00441332     ADD        ESP,0x44
    //         00441335     RET        0x10
    //                               LAB_00441338                                                 XREF[1]:     004412be(j)  
    //                              dlg_smsg.cpp:414 (8)
    //         00441338     CMP        EAX,dword ptr [EBP + 0x50c]
    //         0044133e     JNZ        LAB_0044137c
    //                              dlg_smsg.cpp:415 (11)
    //         00441340     CMP        dword ptr [ESP + param_2],0x1
    //         00441345     JNZ        LAB_004413d8
    //                              dlg_smsg.cpp:436 (5)
    //         0044134b     MOV        EDI,0x8
    //                               LAB_00441350                                                 XREF[1]:     00441364(j)  
    //                              dlg_smsg.cpp:423 (6)
    //         00441350     MOV        this,dword ptr [ESI]
    //         00441352     TEST       this,this
    //         00441354     JZ         LAB_00441360
    //                              dlg_smsg.cpp:424 (16)
    //         00441356     MOV        EAX,dword ptr [this->_padding_]
    //         00441358     PUSH       0x1
    //         0044135a     CALL       dword ptr [EAX + 0xe0]
    //                               LAB_00441360                                                 XREF[1]:     00441354(j)  
    //         00441360     ADD        ESI,0x4
    //         00441363     DEC        EDI
    //         00441364     JNZ        LAB_00441350
    //                              dlg_smsg.cpp:431 (7)
    //         00441366     MOV        this,EBP
    //         00441368     CALL       TribeSendMessageDialog::checkButtons             void checkButtons(TribeSendMessageDialog * th
    //                              dlg_smsg.cpp:432 (5)
    //         0044136d     MOV        EAX,0x1
    //                              dlg_smsg.cpp:436 (10)
    //         00441372     POP        EDI
    //         00441373     POP        ESI
    //         00441374     POP        EBP
    //         00441375     POP        EBX
    //         00441376     ADD        ESP,0x44
    //         00441379     RET        0x10
    //                               LAB_0044137c                                                 XREF[1]:     0044133e(j)  
    //                              dlg_smsg.cpp:428 (6)
    //         0044137c     MOV        this,dword ptr [EBP + 0x510]
    //                              dlg_smsg.cpp:431 (7)
    //         00441382     MOV        this,EBP
    //         00441384     CALL       TribeSendMessageDialog::checkButtons             void checkButtons(TribeSendMessageDialog * th
    //                              dlg_smsg.cpp:432 (5)
    //         00441389     MOV        EAX,0x1
    //                              dlg_smsg.cpp:436 (10)
    //         0044138e     POP        EDI
    //         0044138f     POP        ESI
    //         00441390     POP        EBP
    //         00441391     POP        EBX
    //         00441392     ADD        ESP,0x44
    //         00441395     RET        0x10
    //                               LAB_00441398                                                 XREF[8]:     004411de(j), 004411ea(j), 
    //                                                                                                         004411f6(j), 00441202(j), 
    //                                                                                                         0044120e(j), 0044121a(j), 
    //                                                                                                         00441226(j), 00441232(j)  
    //                              dlg_smsg.cpp:368 (16)
    //         00441398     MOV        this,dword ptr [EBP + 0x504]
    //         0044139e     PUSH       0x0
    //         004413a0     MOV        EDX,dword ptr [this->_padding_]
    //         004413a2     CALL       dword ptr [EDX + 0xe0]
    //                              dlg_smsg.cpp:369 (16)
    //         004413a8     MOV        this,dword ptr [EBP + 0x508]
    //         004413ae     PUSH       0x0
    //         004413b0     MOV        EAX,dword ptr [this->_padding_]
    //         004413b2     CALL       dword ptr [EAX + 0xe0]
    //                              dlg_smsg.cpp:370 (16)
    //         004413b8     MOV        this,dword ptr [EBP + 0x50c]
    //         004413be     PUSH       0x0
    //         004413c0     MOV        EDX,dword ptr [this->_padding_]
    //         004413c2     CALL       dword ptr [EDX + 0xe0]
    //                              dlg_smsg.cpp:371 (16)
    //         004413c8     MOV        this,dword ptr [EBP + 0x510]
    //         004413ce     PUSH       0x1
    //         004413d0     MOV        EAX,dword ptr [this->_padding_]
    //         004413d2     CALL       dword ptr [EAX + 0xe0]
    //                               LAB_004413d8                                                 XREF[2]:     0044106d(j), 00441345(j)  
    //                              dlg_smsg.cpp:431 (7)
    //         004413d8     MOV        this,EBP
    //         004413da     CALL       TribeSendMessageDialog::checkButtons             void checkButtons(TribeSendMessageDialog * th
    //                               LAB_004413df                                                 XREF[5]:     00440f49(j), 00440fa6(j), 
    //                                                                                                         004410f7(j), 0044111a(j), 
    //                                                                                                         0044113c(j)  
    //                              dlg_smsg.cpp:432 (5)
    //         004413df     MOV        EAX,0x1
    //                              dlg_smsg.cpp:436 (10)
    //         004413e4     POP        EDI
    //         004413e5     POP        ESI
    //         004413e6     POP        EBP
    //         004413e7     POP        EBX
    //         004413e8     ADD        ESP,0x44
    //         004413eb     RET        0x10
    //                               LAB_004413ee                                                 XREF[1]:     00440f2f(j)  
    //                              dlg_smsg.cpp:435 (24)
    //         004413ee     MOV        this,dword ptr [ESP + param_4]
    //         004413f2     MOV        EDX,dword ptr [ESP + param_3]
    //         004413f6     MOV        EAX,dword ptr [ESP + param_2]
    //         004413fa     PUSH       this
    //         004413fb     PUSH       EDX
    //         004413fc     PUSH       EAX
    //         004413fd     PUSH       0x0
    //         004413ff     MOV        this,EBP
    //         00441401     CALL       TPanel::action                                   long action(TPanel * this, TPanel * param_1, 
    //                              dlg_smsg.cpp:436 (10)
    //         00441406     POP        EDI
    //         00441407     POP        ESI
    //         00441408     POP        EBP
    //         00441409     POP        EBX
    //         0044140a     ADD        ESP,0x44
    //         0044140d     RET        0x10
}

// Offset: 0x00441410
void checkButtons(TribeSendMessageDialog* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall TribeSendMessageDialog::checkButtons(void)                                 *
    //                              *********************************************************************************************************
    //                              void __thiscall checkButtons(TribeSendMessageDialog * this)
    //              void              <VOID>         <RETURN>
    //              TribeSendMessa    ECX:4 (auto)   this
    //                               ?checkButtons@TribeSendMessageDialog@@IAEXXZ                 XREF[6]:     action:00441075(c), 
    //                               TribeSendMessageDialog::checkButtons                                      action:004412a4(c), 
    //                                                                                                         action:00441324(c), 
    //                                                                                                         action:00441368(c), 
    //                                                                                                         action:00441384(c), 
    //                                                                                                         action:004413da(c)  
    //                              dlg_smsg.cpp:441 (2)
    //         00441410     PUSH       ESI
    //         00441411     PUSH       EDI
    //                              dlg_smsg.cpp:455 (11)
    //         00441412     LEA        ESI,[ECX + this->commPlayers[0]]
    //         00441418     MOV        EDI,0x8
    //                               LAB_0044141d                                                 XREF[1]:     0044144c(j)  
    //                              dlg_smsg.cpp:456 (12)
    //         0044141d     CMP        dword ptr [ESI],0x0
    //         00441420     JZ         LAB_00441448
    //         00441422     MOV        this,dword ptr [ESI + -0x58]
    //         00441425     TEST       this,this
    //         00441427     JZ         LAB_00441448
    //                              dlg_smsg.cpp:457 (9)
    //         00441429     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
    //         0044142e     TEST       EAX,EAX
    //         00441430     JNZ        LAB_00441438
    //                              dlg_smsg.cpp:458 (4)
    //         00441432     PUSH       EAX
    //         00441433     MOV        EAX,dword ptr [ESI]
    //         00441435     PUSH       EAX
    //                              dlg_smsg.cpp:459 (2)
    //         00441436     JMP        LAB_0044143d
    //                               LAB_00441438                                                 XREF[1]:     00441430(j)  
    //                              dlg_smsg.cpp:460 (22)
    //         00441438     MOV        this,dword ptr [ESI]
    //         0044143a     PUSH       0x1
    //         0044143c     PUSH       this
    //                               LAB_0044143d                                                 XREF[1]:     00441436(j)  
    //         0044143d     MOV        this,dword ptr [chat]                            = 00000000
    //         00441443     CALL       TChat::setInChatGroup                            void setInChatGroup(TChat * this, int param_1
    //                               LAB_00441448                                                 XREF[2]:     00441420(j), 00441427(j)  
    //         00441448     ADD        ESI,0x4
    //         0044144b     DEC        EDI
    //         0044144c     JNZ        LAB_0044141d
    //                              dlg_smsg.cpp:464 (3)
    //         0044144e     POP        EDI
    //         0044144f     POP        ESI
    //         00441450     RET
}

// Offset: 0x00441460
void TribeSendMessageDialog::draw() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: virtual void __thiscall TribeSendMessageDialog::draw(void)                                 *
    //                              *********************************************************************************************************
    //                              void __thiscall draw(TribeSendMessageDialog * this)
    //              void              <VOID>         <RETURN>
    //              TribeSendMessa    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0044148d(W)  
    //              int               Stack[-0xc]:4  i
    //                               ?draw@TribeSendMessageDialog@@MAEXXZ                         XREF[1]:     0056fff0(*)  
    //                               TribeSendMessageDialog::draw
    //                              dlg_smsg.cpp:470 (6)
    //         00441460     SUB        ESP,0x8
    //         00441463     PUSH       ESI
    //         00441464     MOV        ESI,this
    //                              dlg_smsg.cpp:474 (5)
    //         00441466     CALL       TEasy_Panel::draw                                void draw(TEasy_Panel * this)
    //                              dlg_smsg.cpp:476 (14)
    //         0044146b     MOV        EAX,dword ptr [ESI + 0x528]
    //         00441471     TEST       EAX,EAX
    //         00441473     JZ         LAB_00441526
    //                              dlg_smsg.cpp:478 (14)
    //         00441479     MOV        EAX,[rge_base_game]                              = 00000000
    //         0044147e     PUSH       EDI
    //         0044147f     PUSH       EBP
    //         00441480     PUSH       EBX
    //         00441481     MOV        EBX,dword ptr [EAX + 0x3f4]
    //                              dlg_smsg.cpp:480 (13)
    //         00441487     MOV        EAX,dword ptr [ESI]
    //         00441489     PUSH       0x0
    //         0044148b     MOV        this,ESI
    //         0044148d     MOV        dword ptr [ESP + local_4],EAX
    //         00441491     CALL       dword ptr [EAX + 0x28]
    //                              dlg_smsg.cpp:482 (5)
    //         00441494     MOV        EDI,0x1
    //                              dlg_smsg.cpp:499 (146)
    //         00441499     XOR        EBP,EBP
    //         0044149b     MOV        dword ptr [ESP + 0x10],EDI
    //                               LAB_0044149f                                                 XREF[1]:     00441518(j)  
    //         0044149f     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004414a5     PUSH       EDI
    //         004414a6     CALL       RGE_Base_Game::playerID                          int playerID(RGE_Base_Game * this, int param_1)
    //         004414ab     TEST       EAX,EAX
    //         004414ad     JZ         LAB_00441510
    //         004414af     MOV        this,dword ptr [EBX + 0x40]
    //         004414b2     LEA        EDI,[EAX*0x4 + 0x0]
    //         004414b9     MOV        EDX,dword ptr [this->_padding_ + EDI*0x1]
    //         004414bc     MOV        EAX,dword ptr [EDX + 0x108]
    //         004414c2     TEST       EAX,EAX
    //         004414c4     JZ         LAB_00441509
    //         004414c6     MOVSX      EAX,word ptr [EAX + 0x26]
    //         004414ca     INC        EAX
    //         004414cb     SHL        EAX,0x4
    //         004414ce     PUSH       EAX
    //         004414cf     CALL       _ASMSet_Color_Xform                              undefined _ASMSet_Color_Xform()
    //         004414d4     MOV        this,dword ptr [EBX + 0x40]
    //         004414d7     ADD        ESP,0x4
    //         004414da     MOV        EDX,dword ptr [this->_padding_ + EDI*0x1]
    //         004414dd     MOV        this,dword ptr [ESI + 0x10]
    //         004414e0     MOV        EAX,dword ptr [EDX + 0x108]
    //         004414e6     LEA        EDX,[ECX + EBP*0x1 + this->_padding_]
    //         004414ea     MOV        this,dword ptr [ESI + 0x20]
    //         004414ed     ADD        EAX,0x28
    //         004414f0     PUSH       EAX
    //         004414f1     MOV        EAX,dword ptr [ESI + 0xc]
    //         004414f4     PUSH       offset DAT_fffffff8
    //         004414f6     PUSH       0x0=>DAT_fffffff4
    //         004414f8     ADD        EAX,0x32
    //         004414fb     PUSH       EDX=>DAT_fffffff0
    //         004414fc     PUSH       EAX
    //         004414fd     PUSH       this
    //         004414fe     MOV        this,dword ptr [ESI + 0x528]
    //         00441504     CALL       TShape::shape_draw                               uchar shape_draw(TShape * this, TDrawArea * p
    //                               LAB_00441509                                                 XREF[1]:     004414c4(j)  
    //         00441509     MOV        EDI,dword ptr [ESP + 0x10]
    //         0044150d     ADD        EBP,0x1e
    //                               LAB_00441510                                                 XREF[1]:     004414ad(j)  
    //         00441510     INC        EDI
    //         00441511     CMP        EDI,0x9
    //         00441514     MOV        dword ptr [ESP + 0x10],EDI
    //         00441518     JL         LAB_0044149f
    //         0044151a     MOV        EDX,dword ptr [ESP + 0x14]
    //         0044151e     MOV        this,ESI
    //         00441520     CALL       dword ptr [EDX + 0x2c]
    //         00441523     POP        EBX
    //         00441524     POP        EBP
    //         00441525     POP        EDI
    //                               LAB_00441526                                                 XREF[1]:     00441473(j)  
    //         00441526     POP        ESI
    //         00441527     ADD        ESP,0x8
    //         0044152a     RET
}

// Offset: 0x00441530
undefined TribeSendQuickMessageDialog(TribeSendQuickMessageDialog* this_, TScreenPanel* param_2, Mode param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TribeSendQuickMessageDialog::TribeSendQuickMessageDialog(class TScreenPanel *,e... *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TribeSendQuickMessageDialog(TribeSendQuickMessa
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TribeSendQuick    ECX:4 (auto)   this
    //              TScreenPanel *    Stack[0x4]:4   param_1                   XREF[1]:     00441558(R)  
    //              Mode              Stack[0x8]:4   param_2                   XREF[1]:     0044155c(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00441564(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00441611(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0044154f(W)  
    //                               ??0TribeSendQuickMessageDialog@@QAE@PAVTScreenPanel@@W4Mode  XREF[1]:     command_quick_chat:0049c097(c)  
    //                               TribeSendQuickMessageDialog::TribeSendQuickMessageDialog
    //                              dlg_smsg.cpp:507 (40)
    //         00441530     PUSH       -0x1
    //         00441532     PUSH       FUN_0055d258
    //         00441537     MOV        EAX,FS:[0x0]
    //         0044153d     PUSH       EAX
    //         0044153e     MOV        dword ptr FS:[0x0],ESP
    //         00441545     PUSH       this
    //         00441546     PUSH       ESI
    //         00441547     PUSH       EDI
    //         00441548     MOV        ESI,this
    //         0044154a     PUSH       s_Send_Quick_Message_Dialog                      = "Send Quick Message Dialog"
    //         0044154f     MOV        dword ptr [ESP + local_10],ESI
    //         00441553     CALL       TDialogPanel::TDialogPanel                       undefined TDialogPanel(TDialogPanel * this, c
    //                              dlg_smsg.cpp:512 (73)
    //         00441558     MOV        EDI,dword ptr [ESP + param_1]
    //         0044155c     MOV        EAX,dword ptr [ESP + param_2]
    //         00441560     PUSH       0x1
    //         00441562     MOV        this,EDI
    //         00441564     MOV        dword ptr [ESP + local_4],0x0
    //         0044156c     MOV        dword ptr [ESI + 0x498],EAX
    //         00441572     MOV        dword ptr [ESI],TribeSendQuickMessageDialog::`   = 00441630
    //         00441578     CALL       TEasy_Panel::get_popup_info_id                   long get_popup_info_id(TEasy_Panel * this)
    //         0044157d     PUSH       EAX
    //         0044157e     MOV        this,EDI
    //         00441580     CALL       TEasy_Panel::get_popup_info_file                 char * get_popup_info_file(TEasy_Panel * this)
    //         00441585     PUSH       EAX
    //         00441586     PUSH       0x23
    //         00441588     PUSH       0x21c
    //         0044158d     PUSH       EDI
    //         0044158e     MOV        this,EDI
    //         00441590     CALL       TPanel::renderArea                               TDrawArea * renderArea(TPanel * this)
    //         00441595     PUSH       EAX
    //         00441596     MOV        this,ESI
    //         00441598     CALL       TDialogPanel::setup                              int setup(TDialogPanel * this, TDrawArea * pa
    //         0044159d     TEST       EAX,EAX
    //         0044159f     JZ         LAB_00441611
    //                              dlg_smsg.cpp:516 (6)
    //         004415a1     MOV        EAX,dword ptr [ESI + 0x498]
    //                              dlg_smsg.cpp:521 (48)
    //         004415a7     PUSH       0x0
    //         004415a9     NEG        EAX
    //         004415ab     PUSH       0x1
    //         004415ad     PUSH       0x1
    //         004415af     SBB        EAX,EAX
    //         004415b1     PUSH       0x4
    //         004415b3     AND        EAX,0x5
    //         004415b6     PUSH       0x19
    //                              language.dll match for 0x78: "10"
    //         004415b8     PUSH       0x78
    //         004415ba     ADD        EAX,0x2668
    //         004415bf     PUSH       0x5
    //         004415c1     PUSH       0x5
    //         004415c3     LEA        this,[ESI + 0x494]
    //         004415c9     PUSH       EAX
    //         004415ca     PUSH       this
    //         004415cb     PUSH       ESI
    //         004415cc     MOV        this,ESI
    //         004415ce     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         004415d3     TEST       EAX,EAX
    //         004415d5     JZ         LAB_00441611
    //                              dlg_smsg.cpp:524 (48)
    //         004415d7     PUSH       0x0
    //         004415d9     PUSH       0x1
    //         004415db     PUSH       0xb
    //         004415dd     PUSH       0x19
    //         004415df     PUSH       0x195
    //         004415e4     PUSH       0x5
    //                              language.dll match for 0x82: "B"
    //         004415e6     PUSH       0x82
    //         004415eb     PUSH       0x0
    //         004415ed     LEA        EDI,[ESI + 0x490]
    //         004415f3     PUSH       0x41
    //         004415f5     PUSH       s_                                               = ""
    //         004415fa     PUSH       EDI
    //         004415fb     PUSH       ESI
    //         004415fc     MOV        this,ESI
    //         004415fe     CALL       TEasy_Panel::create_edit                         int create_edit(TEasy_Panel * this, TPanel * 
    //         00441603     TEST       EAX,EAX
    //         00441605     JZ         LAB_00441611
    //                              dlg_smsg.cpp:526 (10)
    //         00441607     MOV        EDX,dword ptr [EDI]
    //         00441609     MOV        this,ESI
    //         0044160b     PUSH       EDX
    //         0044160c     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                               LAB_00441611                                                 XREF[3]:     0044159f(j), 004415d5(j), 
    //                                                                                                         00441605(j)  
    //                              dlg_smsg.cpp:527 (21)
    //         00441611     MOV        this,dword ptr [ESP + local_c]
    //         00441615     MOV        EAX,ESI
    //         00441617     POP        EDI
    //         00441618     MOV        dword ptr FS:[0x0],this
    //         0044161f     POP        ESI
    //         00441620     ADD        ESP,0x10
    //         00441623     RET        0x8
}

// Offset: 0x00441650
void TribeSendQuickMessageDialog(TribeSendQuickMessageDialog* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall TribeSendQuickMessageDialog::~TribeSendQuickMessageDialog(void)            *
    //                              *********************************************************************************************************
    //                              void __thiscall ~TribeSendQuickMessageDialog(TribeSendQuickMessageDi
    //              void              <VOID>         <RETURN>
    //              TribeSendQuick    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00441679(W)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00441669(W)  
    //                               ??1TribeSendQuickMessageDialog@@UAE@XZ                       XREF[1]:     `vector_deleting_destructor':00441
    //                               TribeSendQuickMessageDialog::~TribeSendQuickMessageDialog
    //                              dlg_smsg.cpp:532 (35)
    //         00441650     PUSH       -0x1
    //         00441652     PUSH       FUN_0055d278
    //         00441657     MOV        EAX,FS:[0x0]
    //         0044165d     PUSH       EAX
    //         0044165e     MOV        dword ptr FS:[0x0],ESP
    //         00441665     PUSH       this
    //         00441666     PUSH       ESI
    //         00441667     MOV        ESI,this
    //         00441669     MOV        dword ptr [ESP + local_10],ESI
    //         0044166d     MOV        dword ptr [ESI],TribeSendQuickMessageDialog::`   = 00441630
    //                              dlg_smsg.cpp:533 (24)
    //         00441673     MOV        this,dword ptr [ESI + 0x490]
    //         00441679     MOV        dword ptr [ESP + local_4],0x0
    //         00441681     TEST       this,this
    //         00441683     JZ         LAB_0044168b
    //         00441685     MOV        EAX,dword ptr [this->_padding_]
    //         00441687     PUSH       0x1
    //         00441689     CALL       dword ptr [EAX]
    //                               LAB_0044168b                                                 XREF[1]:     00441683(j)  
    //                              dlg_smsg.cpp:534 (18)
    //         0044168b     MOV        this,dword ptr [ESI + 0x494]
    //         00441691     TEST       this,this
    //         00441693     JZ         LAB_0044169b
    //         00441695     MOV        EDX,dword ptr [this->_padding_]
    //         00441697     PUSH       0x1
    //         00441699     CALL       dword ptr [EDX]
    //                               LAB_0044169b                                                 XREF[1]:     00441693(j)  
    //         0044169b     MOV        this,ESI
    //                              dlg_smsg.cpp:535 (29)
    //         0044169d     MOV        dword ptr [ESP + 0x10],0xffffffff
    //         004416a5     CALL       TDialogPanel::~TDialogPanel                      void ~TDialogPanel(TDialogPanel * this)
    //         004416aa     MOV        this,dword ptr [ESP + 0x8]
    //         004416ae     POP        ESI
    //         004416af     MOV        dword ptr FS:[0x0],this
    //         004416b6     ADD        ESP,0x10
    //         004416b9     RET
}

// Offset: 0x004416C0
long TribeSendQuickMessageDialog::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TribeSendQuickMessageDialog::action(class TPanel *,long,unsigned l... *
    //                              *********************************************************************************************************
    //                              long __thiscall action(TribeSendQuickMessageDialog * this, TPanel * 
    //              long              EAX:4          <RETURN>
    //              TribeSendQuick    ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     004416c0(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     004416c4(R)  
    //              ulong             Stack[0xc]:4   param_3                   XREF[1]:     0044181e(R)  
    //              ulong             Stack[0x10]:4  param_4                   XREF[1]:     00441819(R)  
    //              char[66]          Stack[-0x48]   save_msg                  XREF[0,2]:   00441724(*), 00441766(*)  
    //                               ?action@TribeSendQuickMessageDialog@@UAEJPAVTPanel@@JKK@Z    XREF[1]:     005701a4(*)  
    //                               TribeSendQuickMessageDialog::action
    //                              dlg_smsg.cpp:542 (24)
    //         004416c0     MOV        EAX,dword ptr [ESP + param_1]
    //         004416c4     MOV        EDX,dword ptr [ESP + param_2]
    //         004416c8     SUB        ESP,0x44
    //         004416cb     TEST       EAX,EAX
    //         004416cd     PUSH       EBX
    //         004416ce     PUSH       ESI
    //         004416cf     PUSH       EDI
    //         004416d0     MOV        ESI,this
    //         004416d2     JZ         LAB_00441819
    //                              dlg_smsg.cpp:545 (14)
    //         004416d8     MOV        this,dword ptr [ESI + 0x490]
    //         004416de     CMP        EAX,this
    //         004416e0     JNZ        LAB_00441819
    //                              dlg_smsg.cpp:547 (8)
    //         004416e6     TEST       EDX,EDX
    //         004416e8     JNZ        LAB_004417e6
    //                              dlg_smsg.cpp:549 (33)
    //         004416ee     CALL       TEditPanel::currentLine                          char * currentLine(TEditPanel * this)
    //         004416f3     TEST       EAX,EAX
    //         004416f5     JZ         LAB_004417eb
    //         004416fb     MOV        this,dword ptr [ESI + 0x490]
    //         00441701     CALL       TEditPanel::currentLine                          char * currentLine(TEditPanel * this)
    //         00441706     CMP        byte ptr [EAX],0x0
    //         00441709     JZ         LAB_004417eb
    //                              dlg_smsg.cpp:554 (31)
    //         0044170f     MOV        this,dword ptr [ESI + 0x490]
    //         00441715     MOV        EBX,dword ptr [ESI + 0x40]
    //         00441718     CALL       TEditPanel::currentLine                          char * currentLine(TEditPanel * this)
    //         0044171d     MOV        EDI,EAX
    //         0044171f     OR         this,0xffffffff
    //         00441722     XOR        EAX,EAX
    //         00441724     LEA        EDX=>save_msg[4],[ESP + 0xc]
    //         00441728     SCASB.RE   ES:EDI
    //         0044172a     NOT        this
    //         0044172c     SUB        EDI,this
    //                              dlg_smsg.cpp:556 (35)
    //         0044172e     PUSH       0x0
    //         00441730     MOV        EAX,this
    //         00441732     MOV        ESI,EDI
    //         00441734     MOV        EDI,EDX
    //         00441736     PUSH       s_Game_Screen                                    = "Game Screen"
    //         0044173b     SHR        this,0x2
    //         0044173e     MOVSD.REP  ES:EDI,ESI
    //         00441740     MOV        this,EAX
    //         00441742     AND        this,0x3
    //         00441745     MOVSB.REP  ES:EDI,ESI
    //         00441747     MOV        this,panel_system
    //         0044174c     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              dlg_smsg.cpp:557 (15)
    //         00441751     PUSH       s_Send_Quick_Message_Dialog                      = "Send Quick Message Dialog"
    //         00441756     MOV        this,panel_system
    //         0044175b     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              dlg_smsg.cpp:559 (35)
    //         00441760     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00441766     LEA        EAX=>save_msg[4],[ESP + 0xc]
    //         0044176a     PUSH       EAX
    //         0044176b     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         00441771     MOV        EDX,dword ptr [this->_padding_]
    //         00441773     MOVSX      EAX,word ptr [EAX + 0x7c]
    //         00441777     PUSH       EAX
    //         00441778     CALL       dword ptr [EDX + 0x54]
    //         0044177b     TEST       EAX,EAX
    //         0044177d     JNZ        LAB_0044180b
    //                              dlg_smsg.cpp:561 (15)
    //         00441783     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00441789     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
    //         0044178e     TEST       EAX,EAX
    //         00441790     JZ         LAB_004417bf
    //                              dlg_smsg.cpp:563 (15)
    //         00441792     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00441798     CMP        dword ptr [ECX + this->_padding_],0x5
    //         0044179f     JZ         LAB_0044180b
    //                              dlg_smsg.cpp:564 (16)
    //         004417a1     MOV        this,dword ptr [comm]                            = 00000000
    //         004417a7     LEA        EDX,[ESP + 0xc]
    //         004417ab     PUSH       EDX
    //         004417ac     CALL       TCommunications_Handler::SendGroupChatMsg        void SendGroupChatMsg(TCommunications_Handler
    //                              dlg_smsg.cpp:585 (5)
    //         004417b1     MOV        EAX,0x1
    //                              dlg_smsg.cpp:590 (9)
    //         004417b6     POP        EDI
    //         004417b7     POP        ESI
    //         004417b8     POP        EBX
    //         004417b9     ADD        ESP,0x44
    //         004417bc     RET        0x10
    //                               LAB_004417bf                                                 XREF[1]:     00441790(j)  
    //                              dlg_smsg.cpp:568 (13)
    //         004417bf     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004417c5     PUSH       0x2
    //         004417c7     CALL       RGE_Base_Game::play_sound                        int play_sound(RGE_Base_Game * this, int para
    //                              dlg_smsg.cpp:569 (12)
    //         004417cc     LEA        EAX,[ESP + 0xc]
    //         004417d0     MOV        this,EBX
    //         004417d2     PUSH       EAX
    //         004417d3     CALL       TRIBE_Screen_Game::display_system_message        void display_system_message(TRIBE_Screen_Game
    //                              dlg_smsg.cpp:572 (5)
    //         004417d8     MOV        EAX,0x1
    //                              dlg_smsg.cpp:590 (9)
    //         004417dd     POP        EDI
    //         004417de     POP        ESI
    //         004417df     POP        EBX
    //         004417e0     ADD        ESP,0x44
    //         004417e3     RET        0x10
    //                               LAB_004417e6                                                 XREF[1]:     004416e8(j)  
    //                              dlg_smsg.cpp:581 (5)
    //         004417e6     CMP        EDX,0x1
    //         004417e9     JNZ        LAB_00441819
    //                               LAB_004417eb                                                 XREF[2]:     004416f5(j), 00441709(j)  
    //                              dlg_smsg.cpp:583 (17)
    //         004417eb     PUSH       0x0
    //         004417ed     PUSH       s_Game_Screen                                    = "Game Screen"
    //         004417f2     MOV        this,panel_system
    //         004417f7     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              dlg_smsg.cpp:584 (15)
    //         004417fc     PUSH       s_Send_Quick_Message_Dialog                      = "Send Quick Message Dialog"
    //         00441801     MOV        this,panel_system
    //         00441806     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                               LAB_0044180b                                                 XREF[2]:     0044177d(j), 0044179f(j)  
    //                              dlg_smsg.cpp:585 (5)
    //         0044180b     MOV        EAX,0x1
    //                              dlg_smsg.cpp:590 (9)
    //         00441810     POP        EDI
    //         00441811     POP        ESI
    //         00441812     POP        EBX
    //         00441813     ADD        ESP,0x44
    //         00441816     RET        0x10
    //                               LAB_00441819                                                 XREF[3]:     004416d2(j), 004416e0(j), 
    //                                                                                                         004417e9(j)  
    //                              dlg_smsg.cpp:589 (19)
    //         00441819     MOV        this,dword ptr [ESP + param_4]
    //         0044181d     PUSH       this
    //         0044181e     MOV        this,dword ptr [ESP + param_3]
    //         00441822     PUSH       this
    //         00441823     PUSH       EDX
    //         00441824     PUSH       EAX
    //         00441825     MOV        this,ESI
    //         00441827     CALL       TEasy_Panel::action                              long action(TEasy_Panel * this, TPanel * para
    //                              dlg_smsg.cpp:590 (9)
    //         0044182c     POP        EDI
    //         0044182d     POP        ESI
    //         0044182e     POP        EBX
    //         0044182f     ADD        ESP,0x44
    //         00441832     RET        0x10
}

// Offset: 0x00441840
long TribeSendQuickMessageDialog::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TribeSendQuickMessageDialog::handle_mouse_down(unsigned char,long,... *
    //                              *********************************************************************************************************
    //                              long __thiscall handle_mouse_down(TribeSendQuickMessageDialog * this
    //              long              EAX:4          <RETURN>
    //              TribeSendQuick    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     00441846(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     00441841(R)  
    //              int               Stack[0x10]:4  param_4
    //              int               Stack[0x14]:4  param_5
    //                               ?handle_mouse_down@TribeSendQuickMessageDialog@@UAEJEJJHH@Z  XREF[1]:     00570160(*)  
    //                               TribeSendQuickMessageDialog::handle_mouse_down
    //                              dlg_smsg.cpp:596 (1)
    //         00441840     PUSH       EBX
    //                              dlg_smsg.cpp:597 (27)
    //         00441841     MOV        EBX,dword ptr [ESP + param_3]
    //         00441845     PUSH       EBP
    //         00441846     MOV        EBP,dword ptr [ESP + param_2]
    //         0044184a     PUSH       ESI
    //         0044184b     MOV        ESI,this
    //         0044184d     PUSH       EDI
    //         0044184e     PUSH       EBX
    //         0044184f     MOV        EDI,dword ptr [ESI]
    //         00441851     PUSH       EBP
    //         00441852     CALL       dword ptr [EDI + 0xbc]
    //         00441858     TEST       EAX,EAX
    //         0044185a     JNZ        LAB_0044187b
    //                              dlg_smsg.cpp:599 (19)
    //         0044185c     PUSH       EAX
    //         0044185d     PUSH       EAX=>DAT_fffffff8
    //         0044185e     MOV        EAX,dword ptr [ESI + 0x490]
    //         00441864     PUSH       offset DAT_fffffff4
    //         00441866     PUSH       EAX=>DAT_fffffff0
    //         00441867     MOV        this,ESI
    //         00441869     CALL       dword ptr [EDI + 0xb4]
    //                              dlg_smsg.cpp:600 (5)
    //         0044186f     MOV        EAX,0x1
    //                              dlg_smsg.cpp:604 (7)
    //         00441874     POP        EDI
    //         00441875     POP        ESI
    //         00441876     POP        EBP
    //         00441877     POP        EBX
    //         00441878     RET        0x14
    //                               LAB_0044187b                                                 XREF[1]:     0044185a(j)  
    //                              dlg_smsg.cpp:603 (24)
    //         0044187b     MOV        this,dword ptr [ESP + 0x24]
    //         0044187f     MOV        EDX,dword ptr [ESP + 0x20]
    //         00441883     MOV        EAX,dword ptr [ESP + 0x14]
    //         00441887     PUSH       this
    //         00441888     PUSH       EDX=>DAT_fffffff8
    //         00441889     PUSH       EBX=>DAT_fffffff4
    //         0044188a     PUSH       EBP=>DAT_fffffff0
    //         0044188b     PUSH       EAX
    //         0044188c     MOV        this,ESI
    //         0044188e     CALL       TEasy_Panel::handle_mouse_down                   long handle_mouse_down(TEasy_Panel * this, uc
    //                              dlg_smsg.cpp:604 (7)
    //         00441893     POP        EDI
    //         00441894     POP        ESI
    //         00441895     POP        EBP
    //         00441896     POP        EBX
    //         00441897     RET        0x14
}

