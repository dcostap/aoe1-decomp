// Auto-generated scaffold unit: Chat.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/Chat.cpp
#include "../include/common.h"

// Offset: 0x00423C30
undefined TChat(TChat* this_, void* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TChat::TChat(void *)                                                               *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TChat(TChat * this, void * param_1)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TChat *           ECX:4 (auto)   this
    //              void *            Stack[0x4]:4   param_1                   XREF[1]:     00423c83(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00423c5e(W), 00423c95(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00423cb5(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00423c58(W)  
    //                               ??0TChat@@QAE@PAX@Z                                          XREF[1]:     setup_chat:0041ed3c(c)  
    //                               TChat::TChat
    //                              Chat.cpp:20 (27)
    //         00423c30     PUSH       -0x1
    //         00423c32     PUSH       FUN_0055cc3b
    //         00423c37     MOV        EAX,FS:[0x0]
    //         00423c3d     PUSH       EAX
    //         00423c3e     MOV        dword ptr FS:[0x0],ESP
    //         00423c45     PUSH       this
    //         00423c46     PUSH       EBX
    //         00423c47     PUSH       ESI
    //         00423c48     PUSH       EDI
    //         00423c49     MOV        EBX,this
    //                              Chat.cpp:23 (56)
    //         00423c4b     PUSH       0x198
    //         00423c50     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00423c55     ADD        ESP,0x4
    //         00423c58     MOV        dword ptr [ESP + local_10],EAX
    //         00423c5c     TEST       EAX,EAX
    //         00423c5e     MOV        dword ptr [ESP + local_4],0x0
    //         00423c66     JZ         LAB_00423c7b
    //         00423c68     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00423c6e     MOV        EDX,dword ptr [ECX + this+0x60]
    //         00423c71     MOV        this,EAX
    //         00423c73     PUSH       EDX
    //         00423c74     CALL       TTaunt::TTaunt                                   undefined TTaunt(TTaunt * this, TSound_Driver
    //         00423c79     JMP        LAB_00423c7d
    //                               LAB_00423c7b                                                 XREF[1]:     00423c66(j)  
    //         00423c7b     XOR        EAX,EAX
    //                               LAB_00423c7d                                                 XREF[1]:     00423c79(j)  
    //         00423c7d     MOV        dword ptr [EBX + 0xfc],EAX
    //                              Chat.cpp:25 (9)
    //         00423c83     MOV        EAX,dword ptr [ESP + param_1]
    //         00423c87     MOV        dword ptr [EBX],EAX
    //         00423c89     LEA        EDI,[EBX + 0x2c]
    //                              Chat.cpp:29 (17)
    //         00423c8c     MOV        this,0x33
    //         00423c91     XOR        EAX,EAX
    //         00423c93     STOSD.REP  ES:EDI
    //         00423c95     MOV        dword ptr [ESP + local_4],0xffffffff
    //                              Chat.cpp:30 (6)
    //         00423c9d     MOV        dword ptr [EBX + 0xf8],EAX
    //                              Chat.cpp:33 (2)
    //         00423ca3     XOR        ESI,ESI
    //                               LAB_00423ca5                                                 XREF[1]:     00423cb3(j)  
    //                              Chat.cpp:34 (16)
    //         00423ca5     PUSH       0x0
    //         00423ca7     PUSH       ESI
    //         00423ca8     MOV        this,EBX
    //         00423caa     CALL       TChat::setInChatGroup                            void setInChatGroup(TChat * this, int param_1
    //         00423caf     INC        ESI
    //         00423cb0     CMP        ESI,0x9
    //         00423cb3     JLE        LAB_00423ca5
    //                              Chat.cpp:35 (22)
    //         00423cb5     MOV        this,dword ptr [ESP + local_c]
    //         00423cb9     POP        EDI
    //         00423cba     MOV        EAX,EBX
    //         00423cbc     POP        ESI
    //         00423cbd     MOV        dword ptr FS:[0x0],this
    //         00423cc4     POP        EBX
    //         00423cc5     ADD        ESP,0x10
    //         00423cc8     RET        0x4
}

// Offset: 0x00423CD0
void TChat(TChat* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TChat::~TChat(void)                                                                *
    //                              *********************************************************************************************************
    //                              void __thiscall ~TChat(TChat * this)
    //              void              <VOID>         <RETURN>
    //              TChat *           ECX:4 (auto)   this
    //                               ??1TChat@@QAE@XZ                                             XREF[1]:     ~RGE_Base_Game:0041c505(c)  
    //                               TChat::~TChat
    //                              Chat.cpp:38 (3)
    //         00423cd0     PUSH       ESI
    //         00423cd1     MOV        ESI,this
    //                              Chat.cpp:39 (5)
    //         00423cd3     CALL       TChat::ClearChat                                 void ClearChat(TChat * this)
    //                              Chat.cpp:40 (26)
    //         00423cd8     MOV        ESI,dword ptr [ESI + 0xfc]
    //         00423cde     TEST       ESI,ESI
    //         00423ce0     JZ         LAB_00423cf2
    //         00423ce2     MOV        this,ESI
    //         00423ce4     CALL       TTaunt::~TTaunt                                  void ~TTaunt(TTaunt * this)
    //         00423ce9     PUSH       ESI
    //         00423cea     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00423cef     ADD        ESP,0x4
    //                               LAB_00423cf2                                                 XREF[1]:     00423ce0(j)  
    //                              Chat.cpp:42 (2)
    //         00423cf2     POP        ESI
    //         00423cf3     RET
}

// Offset: 0x00423D00
int AddChatMsg(TChat* this_, char* param_2, char* param_3, uchar param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TChat::AddChatMsg(char *,char *,unsigned char)                                 *
    //                              *********************************************************************************************************
    //                              int __thiscall AddChatMsg(TChat * this, char * param_1, char * param
    //              int               EAX:4          <RETURN>
    //              TChat *           ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     00423d02(R)  
    //              char *            Stack[0x8]:4   param_2                   XREF[1]:     00423d17(R)  
    //              uchar             Stack[0xc]:1   param_3
    //                               ?AddChatMsg@TChat@@QAEHPAD0E@Z                               XREF[5]:     PreprocessMessages:00427c6e(c), 
    //                               TChat::AddChatMsg                                                         PreprocessMessages:00427ee7(c), 
    //                                                                                                         EvaluatePlayerMessage:0042849f(c), 
    //                                                                                                         TXChat:004298a6(c), 
    //                                                                                                         TXChat:0042995d(c)  
    //                              Chat.cpp:45 (2)
    //         00423d00     PUSH       EBX
    //         00423d01     PUSH       EBP
    //                              Chat.cpp:52 (12)
    //         00423d02     MOV        EBP,dword ptr [ESP + param_1]
    //         00423d06     PUSH       ESI
    //         00423d07     TEST       EBP,EBP
    //         00423d09     PUSH       EDI
    //         00423d0a     MOV        ESI,this
    //         00423d0c     JNZ        LAB_00423d17
    //                              Chat.cpp:53 (2)
    //         00423d0e     XOR        EAX,EAX
    //                              Chat.cpp:87 (7)
    //         00423d10     POP        EDI
    //         00423d11     POP        ESI
    //         00423d12     POP        EBP
    //         00423d13     POP        EBX
    //         00423d14     RET        0xc
    //                               LAB_00423d17                                                 XREF[1]:     00423d0c(j)  
    //                              Chat.cpp:55 (8)
    //         00423d17     MOV        EBX,dword ptr [ESP + param_2]
    //         00423d1b     TEST       EBX,EBX
    //         00423d1d     JNZ        LAB_00423d28
    //                              Chat.cpp:56 (2)
    //         00423d1f     XOR        EAX,EAX
    //                              Chat.cpp:87 (7)
    //         00423d21     POP        EDI
    //         00423d22     POP        ESI
    //         00423d23     POP        EBP
    //         00423d24     POP        EBX
    //         00423d25     RET        0xc
    //                               LAB_00423d28                                                 XREF[1]:     00423d1d(j)  
    //                              Chat.cpp:59 (7)
    //         00423d28     MOV        this,dword ptr [ESI + 0xf8]
    //         00423d2e     INC        this
    //                              Chat.cpp:61 (13)
    //         00423d2f     MOV        EAX,this
    //         00423d31     MOV        dword ptr [ESI + 0xf8],this
    //         00423d37     CMP        EAX,0x32
    //         00423d3a     JLE        LAB_00423d46
    //                              Chat.cpp:62 (10)
    //         00423d3c     MOV        dword ptr [ESI + 0xf8],0x0
    //                               LAB_00423d46                                                 XREF[1]:     00423d3a(j)  
    //                              Chat.cpp:65 (14)
    //         00423d46     MOV        EAX,dword ptr [ESI + 0xf8]
    //         00423d4c     MOV        EAX,dword ptr [ESI + EAX*0x4 + 0x2c]
    //         00423d50     TEST       EAX,EAX
    //         00423d52     JZ         LAB_00423d5d
    //                              Chat.cpp:66 (9)
    //         00423d54     PUSH       EAX
    //         00423d55     CALL       free                                             undefined free()
    //         00423d5a     ADD        ESP,0x4
    //                               LAB_00423d5d                                                 XREF[1]:     00423d52(j)  
    //                              Chat.cpp:69 (7)
    //         00423d5d     MOV        EDI,EBP
    //         00423d5f     OR         this,0xffffffff
    //         00423d62     XOR        EAX,EAX
    //                              Chat.cpp:71 (42)
    //         00423d64     PUSH       0x1
    //         00423d66     SCASB.RE   ES:EDI
    //         00423d68     NOT        this
    //         00423d6a     DEC        this
    //         00423d6b     MOV        EDI,EBX
    //         00423d6d     MOV        EDX,this
    //         00423d6f     OR         this,0xffffffff
    //         00423d72     SCASB.RE   ES:EDI
    //         00423d74     NOT        this
    //         00423d76     DEC        this
    //         00423d77     LEA        EAX,[EDX + this->HostWnd*0x1 + 0x3]
    //         00423d7b     PUSH       EAX
    //         00423d7c     CALL       calloc                                           undefined calloc()
    //         00423d81     MOV        this,dword ptr [ESI + 0xf8]
    //         00423d87     ADD        ESP,0x8
    //         00423d8a     MOV        dword ptr [ESI + this->HostWnd*0x4 + 0x2c],EAX
    //                              Chat.cpp:73 (14)
    //         00423d8e     MOV        EDX,dword ptr [ESI + 0xf8]
    //         00423d94     MOV        EAX,dword ptr [ESI + EDX*0x4 + 0x2c]
    //         00423d98     TEST       EAX,EAX
    //         00423d9a     JNZ        LAB_00423da3
    //                              Chat.cpp:87 (7)
    //         00423d9c     POP        EDI
    //         00423d9d     POP        ESI
    //         00423d9e     POP        EBP
    //         00423d9f     POP        EBX
    //         00423da0     RET        0xc
    //                               LAB_00423da3                                                 XREF[1]:     00423d9a(j)  
    //                              Chat.cpp:77 (13)
    //         00423da3     PUSH       EBX
    //         00423da4     PUSH       EBP
    //         00423da5     PUSH       s_%s:_%s                                         = "%s: %s"
    //         00423daa     PUSH       EAX
    //         00423dab     CALL       sprintf                                          undefined sprintf()
    //                              Chat.cpp:81 (29)
    //         00423db0     MOV        EAX,dword ptr [ESI + 0xf8]
    //         00423db6     MOV        this,dword ptr [ESI]
    //         00423db8     ADD        ESP,0x10
    //         00423dbb     PUSH       EAX
    //         00423dbc     PUSH       0x17d5
    //         00423dc1     PUSH       0x400
    //         00423dc6     PUSH       this
    //         00423dc7     CALL       dword ptr [->USER32.DLL::PostMessageA]           = 0048afc2
    //                              Chat.cpp:83 (10)
    //         00423dcd     MOV        this,dword ptr [ESI + 0xfc]
    //         00423dd3     TEST       this,this
    //         00423dd5     JZ         LAB_00423de2
    //                              Chat.cpp:84 (11)
    //         00423dd7     MOV        EDX,dword ptr [ESP + 0x1c]
    //         00423ddb     PUSH       EDX
    //         00423ddc     PUSH       EBX
    //         00423ddd     CALL       TTaunt::PlayTauntStr                             int PlayTauntStr(TTaunt * this, char * param_
    //                               LAB_00423de2                                                 XREF[1]:     00423dd5(j)  
    //                              Chat.cpp:87 (12)
    //         00423de2     POP        EDI
    //         00423de3     POP        ESI
    //         00423de4     POP        EBP
    //         00423de5     MOV        EAX,0x1
    //         00423dea     POP        EBX
    //         00423deb     RET        0xc
}

// Offset: 0x00423DF0
char* GetChatMsg(TChat* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: char * __thiscall TChat::GetChatMsg(int)                                                      *
    //                              *********************************************************************************************************
    //                              char * __thiscall GetChatMsg(TChat * this, int param_1)
    //              char *            EAX:4          <RETURN>
    //              TChat *           ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00423df0(R)  
    //                               ?GetChatMsg@TChat@@QAEPADH@Z                                 XREF[2]:     handleChatReceived:00497346(c), 
    //                               TChat::GetChatMsg                                                         fillChat:004a415c(c)  
    //                              Chat.cpp:147 (13)
    //         00423df0     MOV        EAX,dword ptr [ESP + param_1]
    //         00423df4     TEST       EAX,EAX
    //         00423df6     JL         LAB_00423e04
    //         00423df8     CMP        EAX,0x32
    //         00423dfb     JG         LAB_00423e04
    //                              Chat.cpp:157 (4)
    //         00423dfd     MOV        EAX,dword ptr [ECX + EAX*0x4 + this->Chat[0]]
    //                              Chat.cpp:158 (3)
    //         00423e01     RET        0x4
    //                               LAB_00423e04                                                 XREF[2]:     00423df6(j), 00423dfb(j)  
    //                              Chat.cpp:155 (2)
    //         00423e04     XOR        EAX,EAX
    //                              Chat.cpp:158 (3)
    //         00423e06     RET        0x4
}

// Offset: 0x00423E10
void ClearChat(TChat* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TChat::ClearChat(void)                                                        *
    //                              *********************************************************************************************************
    //                              void __thiscall ClearChat(TChat * this)
    //              void              <VOID>         <RETURN>
    //              TChat *           ECX:4 (auto)   this
    //                               ?ClearChat@TChat@@QAEXXZ                                     XREF[9]:     ~TChat:00423cd3(c), 
    //                               TChat::ClearChat                                                          UnlinkCurrentLevel:0042c0e0(c), 
    //                                                                                                         UnlinkCurrentLevel:0042c115(c), 
    //                                                                                                         UnlinkCurrentLevel:0042c331(c), 
    //                                                                                                         UnlinkCurrentLevel:0042c500(c), 
    //                                                                                                         CreateMultiplayerGame:0042d5c5(c), 
    //                                                                                                         InitJoinGame:0042da56(c), 
    //                                                                                                         TribeMPSetupScreen:004a0110(c), 
    //                                                                                                         let_game_begin:00528d0e(c)  
    //                              Chat.cpp:161 (5)
    //         00423e10     PUSH       EBX
    //         00423e11     MOV        EBX,this
    //         00423e13     PUSH       ESI
    //         00423e14     PUSH       EDI
    //                              Chat.cpp:165 (8)
    //         00423e15     LEA        ESI,[EBX + 0x2c]
    //         00423e18     MOV        EDI,0x33
    //                               LAB_00423e1d                                                 XREF[1]:     00423e36(j)  
    //                              Chat.cpp:168 (6)
    //         00423e1d     MOV        EAX,dword ptr [ESI]
    //         00423e1f     TEST       EAX,EAX
    //         00423e21     JZ         LAB_00423e2c
    //                              Chat.cpp:169 (9)
    //         00423e23     PUSH       EAX
    //         00423e24     CALL       free                                             undefined free()
    //         00423e29     ADD        ESP,0x4
    //                               LAB_00423e2c                                                 XREF[1]:     00423e21(j)  
    //                              Chat.cpp:170 (12)
    //         00423e2c     MOV        dword ptr [ESI],0x0
    //         00423e32     ADD        ESI,0x4
    //         00423e35     DEC        EDI
    //         00423e36     JNZ        LAB_00423e1d
    //                              Chat.cpp:174 (14)
    //         00423e38     POP        EDI
    //         00423e39     MOV        dword ptr [EBX + 0xf8],0x0
    //         00423e43     POP        ESI
    //         00423e44     POP        EBX
    //         00423e45     RET
}

// Offset: 0x00423E50
int MaxArraySize(TChat* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TChat::MaxArraySize(void)                                                      *
    //                              *********************************************************************************************************
    //                              int __thiscall MaxArraySize(TChat * this)
    //              int               EAX:4          <RETURN>
    //              TChat *           ECX:4 (auto)   this
    //                               ?MaxArraySize@TChat@@QAEHXZ
    //                               TChat::MaxArraySize
    //                              Chat.cpp:185 (5)
    //         00423e50     MOV        EAX,0x32
    //                              Chat.cpp:189 (1)
    //         00423e55     RET
}

// Offset: 0x00423E60
void setWindowHandle(TChat* this_, void* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TChat::setWindowHandle(void *)                                                *
    //                              *********************************************************************************************************
    //                              void __thiscall setWindowHandle(TChat * this, void * param_1)
    //              void              <VOID>         <RETURN>
    //              TChat *           ECX:4 (auto)   this
    //              void *            Stack[0x4]:4   param_1                   XREF[1]:     00423e60(R)  
    //                               ?setWindowHandle@TChat@@QAEXPAX@Z                            XREF[2]:     startGame:004a26ec(c), 
    //                               TChat::setWindowHandle                                                    handle_user_command:004a3486(c)  
    //                              Chat.cpp:192 (6)
    //         00423e60     MOV        EAX,dword ptr [ESP + param_1]
    //         00423e64     MOV        dword ptr [this->HostWnd],EAX
    //                              Chat.cpp:198 (3)
    //         00423e66     RET        0x4
}

// Offset: 0x00423E70
void setInChatGroup(TChat* this_, int param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TChat::setInChatGroup(int,int)                                                *
    //                              *********************************************************************************************************
    //                              void __thiscall setInChatGroup(TChat * this, int param_1, int param_2)
    //              void              <VOID>         <RETURN>
    //              TChat *           ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00423e70(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     00423e7d(R)  
    //                               ?setInChatGroup@TChat@@QAEXHH@Z                              XREF[5]:     TChat:00423caa(c), 
    //                               TChat::setInChatGroup                                                     checkButtons:00441443(c), 
    //                                                                                                         TribeMPSetupScreen:004a0123(c), 
    //                                                                                                         random_start:005144e5(c), 
    //                                                                                                         let_game_begin:00528d26(c)  
    //                              Chat.cpp:202 (13)
    //         00423e70     MOV        EAX,dword ptr [ESP + param_1]
    //         00423e74     TEST       EAX,EAX
    //         00423e76     JLE        LAB_00423e85
    //         00423e78     CMP        EAX,0x9
    //         00423e7b     JG         LAB_00423e85
    //                              Chat.cpp:206 (8)
    //         00423e7d     MOV        EDX,dword ptr [ESP + param_2]
    //         00423e81     MOV        dword ptr [ECX + EAX*this->chatGroupPlayers[0]
    //                               LAB_00423e85                                                 XREF[2]:     00423e76(j), 00423e7b(j)  
    //                              Chat.cpp:208 (3)
    //         00423e85     RET        0x8
}

// Offset: 0x00423E90
int inChatGroup(TChat* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TChat::inChatGroup(int)                                                        *
    //                              *********************************************************************************************************
    //                              int __thiscall inChatGroup(TChat * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              TChat *           ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00423e90(R)  
    //                               ?inChatGroup@TChat@@QAEHH@Z                                  XREF[2]:     SendGroupChatMsg:0042978e(c), 
    //                               TChat::inChatGroup                                                        TribeSendMessageDialog:00440abf(c)
    //                              Chat.cpp:211 (13)
    //         00423e90     MOV        EAX,dword ptr [ESP + param_1]
    //         00423e94     TEST       EAX,EAX
    //         00423e96     JL         LAB_00423ea4
    //         00423e98     CMP        EAX,0x9
    //         00423e9b     JG         LAB_00423ea4
    //                              Chat.cpp:216 (4)
    //         00423e9d     MOV        EAX,dword ptr [ECX + EAX*this->chatGroupPlayer
    //                              Chat.cpp:217 (3)
    //         00423ea1     RET        0x4
    //                               LAB_00423ea4                                                 XREF[2]:     00423e96(j), 00423e9b(j)  
    //                              Chat.cpp:214 (2)
    //         00423ea4     XOR        EAX,EAX
    //                              Chat.cpp:217 (3)
    //         00423ea6     RET        0x4
}

// Offset: 0x00423EB0
void StopSoundSystem(TChat* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TChat::StopSoundSystem(void)                                                  *
    //                              *********************************************************************************************************
    //                              void __thiscall StopSoundSystem(TChat * this)
    //              void              <VOID>         <RETURN>
    //              TChat *           ECX:4 (auto)   this
    //                               ?StopSoundSystem@TChat@@QAEXXZ                               XREF[1]:     stop_sound_system:0041f83f(c)  
    //                               TChat::StopSoundSystem
    //                              Chat.cpp:220 (10)
    //         00423eb0     MOV        this,dword ptr [ECX + this->taunt]
    //         00423eb6     TEST       this,this
    //         00423eb8     JZ         LAB_00423ebf
    //                              Chat.cpp:222 (5)
    //         00423eba     JMP        TTaunt::StopSoundSystem                          void StopSoundSystem(TTaunt * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
    //                               LAB_00423ebf                                                 XREF[1]:     00423eb8(j)  
    //                              Chat.cpp:223 (1)
    //         00423ebf     RET
}

// Offset: 0x00423EC0
int RestartSoundSystem(TChat* this_, TSound_Driver* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TChat::RestartSoundSystem(class TSound_Driver *)                               *
    //                              *********************************************************************************************************
    //                              int __thiscall RestartSoundSystem(TChat * this, TSound_Driver * para
    //              int               EAX:4          <RETURN>
    //              TChat *           ECX:4 (auto)   this
    //              TSound_Driver *   Stack[0x4]:4   param_1                   XREF[1]:     00423eca(R)  
    //                               ?RestartSoundSystem@TChat@@QAEHPAVTSound_Driver@@@Z          XREF[1]:     restart_sound_system:0041f994(c)  
    //                               TChat::RestartSoundSystem
    //                              Chat.cpp:226 (10)
    //         00423ec0     MOV        this,dword ptr [ECX + this->taunt]
    //         00423ec6     TEST       this,this
    //         00423ec8     JZ         LAB_00423ed7
    //                              Chat.cpp:228 (10)
    //         00423eca     MOV        EAX,dword ptr [ESP + param_1]
    //         00423ece     PUSH       EAX
    //         00423ecf     CALL       TTaunt::RestartSoundSystem                       int RestartSoundSystem(TTaunt * this, TSound_
    //                              Chat.cpp:231 (3)
    //         00423ed4     RET        0x4
    //                               LAB_00423ed7                                                 XREF[1]:     00423ec8(j)  
    //                              Chat.cpp:230 (5)
    //         00423ed7     MOV        EAX,0x1
    //                              Chat.cpp:231 (3)
    //         00423edc     RET        0x4
}

