#include "common.h"
#include "Chat.h"

TChat::TChat(void* param_1) {
    /* TODO: Stub */
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
    //         00423ccb     ??         90h
    //         00423ccc     NOP
    //         00423ccd     NOP
    //         00423cce     NOP
    //         00423ccf     NOP
}

TChat::~TChat() {
    /* TODO: Stub */
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
    //         00423cf4     ??         90h
    //         00423cf5     NOP
    //         00423cf6     NOP
    //         00423cf7     NOP
    //         00423cf8     NOP
    //         00423cf9     NOP
    //         00423cfa     NOP
    //         00423cfb     NOP
    //         00423cfc     NOP
    //         00423cfd     NOP
    //         00423cfe     NOP
    //         00423cff     NOP
}

int TChat::AddChatMsg(char* param_1, char* param_2, uchar param_3) {
    /* TODO: Stub */
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
    //         00423dee     ??         90h
    //         00423def     NOP
    return 0;
}

char* TChat::GetChatMsg(int param_1) {
    /* TODO: Stub */
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
    //         00423e09     ??         90h
    //         00423e0a     NOP
    //         00423e0b     NOP
    //         00423e0c     NOP
    //         00423e0d     NOP
    //         00423e0e     NOP
    //         00423e0f     NOP
    return 0;
}

void TChat::ClearChat() {
    /* TODO: Stub */
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
    //         00423e46     ??         90h
    //         00423e47     NOP
    //         00423e48     NOP
    //         00423e49     NOP
    //         00423e4a     NOP
    //         00423e4b     NOP
    //         00423e4c     NOP
    //         00423e4d     NOP
    //         00423e4e     NOP
    //         00423e4f     NOP
    return;
}

int TChat::MaxArraySize() {
    /* TODO: Stub */
    //                              int __thiscall MaxArraySize(TChat * this)
    //              int               EAX:4          <RETURN>
    //              TChat *           ECX:4 (auto)   this
    //                               ?MaxArraySize@TChat@@QAEHXZ
    //                               TChat::MaxArraySize
    //                              Chat.cpp:185 (5)
    //         00423e50     MOV        EAX,0x32
    //                              Chat.cpp:189 (1)
    //         00423e55     RET
    //         00423e56     ??         90h
    //         00423e57     NOP
    //         00423e58     NOP
    //         00423e59     NOP
    //         00423e5a     NOP
    //         00423e5b     NOP
    //         00423e5c     NOP
    //         00423e5d     NOP
    //         00423e5e     NOP
    //         00423e5f     NOP
    return 0;
}

void TChat::setWindowHandle(void* param_1) {
    /* TODO: Stub */
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
    //         00423e69     ??         90h
    //         00423e6a     NOP
    //         00423e6b     NOP
    //         00423e6c     NOP
    //         00423e6d     NOP
    //         00423e6e     NOP
    //         00423e6f     NOP
    return;
}

void TChat::setInChatGroup(int param_1, int param_2) {
    /* TODO: Stub */
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
    //         00423e88     ??         90h
    //         00423e89     NOP
    //         00423e8a     NOP
    //         00423e8b     NOP
    //         00423e8c     NOP
    //         00423e8d     NOP
    //         00423e8e     NOP
    //         00423e8f     NOP
    return;
}

int TChat::inChatGroup(int param_1) {
    /* TODO: Stub */
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
    //         00423ea9     ??         90h
    //         00423eaa     NOP
    //         00423eab     NOP
    //         00423eac     NOP
    //         00423ead     NOP
    //         00423eae     NOP
    //         00423eaf     NOP
    return 0;
}

void TChat::StopSoundSystem() {
    /* TODO: Stub */
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
    return;
}

int TChat::RestartSoundSystem(TSound_Driver* param_1) {
    /* TODO: Stub */
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
    //         00423edf     ??         90h
    //                              * void __cdecl RGE_translate_palette(struct tagPALETTEENTRY *,struct tagPALETTEENTRY *,struct tagPAL... *
    //                              void __cdecl RGE_translate_palette(tagPALETTEENTRY * param_1, tagPAL
    //              void              <VOID>         <RETURN>
    //              tagPALETTEENTR    Stack[0x4]:4   param_1                   XREF[4]:     00423ee7(R), 00423efd(W), 00424019(R), 0042405f(R)  
    //              tagPALETTEENTR    Stack[0x8]:4   param_2                   XREF[4]:     00423ee3(R), 00423f33(W), 00423f58(R), 00423f5d(W)  
    //              tagPALETTEENTRY   Stack[0xc]:4   param_3                   XREF[1,2]:   00423f90(R), 00423fa1(R), 00423fe8(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[3]:     00423fc2(R), 00424005(R), 00424046(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[1]:     00423f01(R)  
    //              int               Stack[0x18]:4  param_6                   XREF[1]:     00423f0b(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00423f2f(W), 00423f67(R)  
    //              long[3]           Stack[-0x10]   intense                   XREF[3,9]:   00423ef6(W), 00424063(R), 0042408f(W), 00423f24(W), 
    //                                                                                     00423f44(R), 00423f4d(W), 00423f6b(R), 00423f2b(W), 
    //                                                                                     00423f3b(*), 00423f47(*), 00423f50(*), 00423f63(R)  
    //              long              Stack[-0x14]:4 index1
    //                               ?RGE_translate_palette@@YAXPAUtagPALETTEENTRY@@0U1@JHH@Z     XREF[4]:     RGE_fade_palette:0042424e(c), 
    //                               RGE_translate_palette                                                     RGE_fade_palette:0042431b(c), 
    //                                                                                                         RGE_Color_Table:004246d0(c), 
    //                                                                                                         RGE_fade_palette_step:004936a6(c)  
    //                              color.cpp:23 (3)
    //         00423ee0     SUB        ESP,0x10
    //                              color.cpp:32 (30)
    //         00423ee3     MOV        ECX,dword ptr [ESP + param_2]
    //         00423ee7     MOV        EDX,dword ptr [ESP + param_1]
    //         00423eeb     PUSH       EBX
    //         00423eec     PUSH       EBP
    //         00423eed     XOR        EAX,EAX
    //         00423eef     LEA        EBP,[ECX + 0x3]
    //         00423ef2     PUSH       ESI
    //         00423ef3     SUB        ECX,EDX
    //         00423ef5     PUSH       EDI
    //         00423ef6     MOV        dword ptr [ESP + intense[0]],EAX
    //         00423efa     LEA        EDI,[EDX + 0x1]
    //         00423efd     MOV        dword ptr [ESP + param_1],ECX
    //                               LAB_00423f01                                                 XREF[1]:     00424093(j)  
    //                              color.cpp:34 (20)
    //         00423f01     CMP        EAX,dword ptr [ESP + param_5]
    //         00423f05     JZ         LAB_0042406c
    //         00423f0b     CMP        EAX,dword ptr [ESP + param_6]
    //         00423f0f     JZ         LAB_0042406c
    //                              color.cpp:43 (3)
    //         00423f15     MOV        EBX,dword ptr [EDI + -0x1]
    //                              color.cpp:44 (10)
    //         00423f18     XOR        EAX,EAX
    //         00423f1a     MOV        AL,byte ptr [EDI]
    //         00423f1c     AND        EBX,0xff
    //                              color.cpp:45 (17)
    //         00423f22     XOR        ECX,ECX
    //         00423f24     MOV        dword ptr [ESP + intense[1]],EBX
    //         00423f28     MOV        CL,byte ptr [EDI + 0x1]
    //         00423f2b     MOV        dword ptr [ESP + intense[2]],EAX
    //         00423f2f     MOV        dword ptr [ESP + local_4],ECX
    //                              color.cpp:67 (313)
    //         00423f33     MOV        dword ptr [ESP + param_2],0x2
    //                               LAB_00423f3b                                                 XREF[1]:     00423f61(j)  
    //         00423f3b     LEA        EAX=>intense[2],[ESP + 0x18]
    //         00423f3f     MOV        ESI,0x2
    //                               LAB_00423f44                                                 XREF[1]:     00423f56(j)  
    //         00423f44     MOV        ECX,dword ptr [EAX + intense[1]]
    //         00423f47     MOV        EDX,dword ptr [EAX]=>intense[2]
    //         00423f49     CMP        ECX,EDX
    //         00423f4b     JGE        LAB_00423f52
    //         00423f4d     MOV        dword ptr [EAX + intense[1]],EDX
    //         00423f50     MOV        dword ptr [EAX]=>intense[2],ECX
    //                               LAB_00423f52                                                 XREF[1]:     00423f4b(j)  
    //         00423f52     ADD        EAX,0x4
    //         00423f55     DEC        ESI
    //         00423f56     JNZ        LAB_00423f44
    //         00423f58     MOV        EAX,dword ptr [ESP + param_2]
    //         00423f5c     DEC        EAX
    //         00423f5d     MOV        dword ptr [ESP + param_2],EAX
    //         00423f61     JNZ        LAB_00423f3b
    //         00423f63     MOV        EDX,dword ptr [ESP + intense[2]]
    //         00423f67     MOV        EAX,dword ptr [ESP + local_4]
    //         00423f6b     MOV        ESI,dword ptr [ESP + intense[1]]
    //         00423f6f     MOV        ECX,0xff
    //         00423f74     ADD        EAX,EDX
    //         00423f76     SUB        ECX,ESI
    //         00423f78     IMUL       EAX,ECX
    //         00423f7b     CDQ
    //         00423f7c     AND        EDX,0x1ff
    //         00423f82     ADD        EAX,EDX
    //         00423f84     MOV        ECX,EAX
    //         00423f86     MOV        EAX,0x80808081
    //         00423f8b     SAR        ECX,0x9
    //         00423f8e     ADD        ECX,ESI
    //         00423f90     MOV        ESI,dword ptr [ESP + param_3.peRed]
    //         00423f94     AND        ESI,0xff
    //         00423f9a     IMUL       ESI,ECX
    //         00423f9d     IMUL       ESI
    //         00423f9f     ADD        EDX,ESI
    //         00423fa1     MOV        ESI,dword ptr [ESP + param_3.peGreen]
    //         00423fa5     SAR        EDX,0x7
    //         00423fa8     MOV        EAX,EDX
    //         00423faa     AND        ESI,0xff
    //         00423fb0     SHR        EAX,0x1f
    //         00423fb3     IMUL       ESI,ECX
    //         00423fb6     ADD        EDX,EAX
    //         00423fb8     MOV        EAX,0x51eb851f
    //         00423fbd     SUB        EDX,EBX
    //         00423fbf     MOV        BL,byte ptr [EDI + -0x1]
    //         00423fc2     IMUL       EDX,dword ptr [ESP + param_4]
    //         00423fc7     IMUL       EDX
    //         00423fc9     SAR        EDX,0x5
    //         00423fcc     MOV        EAX,EDX
    //         00423fce     SHR        EAX,0x1f
    //         00423fd1     ADD        EDX,EAX
    //         00423fd3     MOV        EAX,0x80808081
    //         00423fd8     ADD        DL,BL
    //         00423fda     MOV        byte ptr [EBP + -0x3],DL
    //         00423fdd     IMUL       ESI
    //         00423fdf     MOV        BL,byte ptr [EDI]
    //         00423fe1     ADD        EDX,ESI
    //         00423fe3     SAR        EDX,0x7
    //         00423fe6     MOV        EAX,EDX
    //         00423fe8     MOV        ESI,dword ptr [ESP + param_3.peBlue]
    //         00423fec     SHR        EAX,0x1f
    //         00423fef     ADD        EDX,EAX
    //         00423ff1     MOV        EAX,EBX
    //         00423ff3     AND        EAX,0xff
    //         00423ff8     AND        ESI,0xff
    //         00423ffe     SUB        EDX,EAX
    //         00424000     MOV        EAX,0x51eb851f
    //         00424005     IMUL       EDX,dword ptr [ESP + param_4]
    //         0042400a     IMUL       ESI,ECX
    //         0042400d     IMUL       EDX
    //         0042400f     SAR        EDX,0x5
    //         00424012     MOV        EAX,EDX
    //         00424014     SHR        EAX,0x1f
    //         00424017     ADD        EDX,EAX
    //         00424019     MOV        EAX,dword ptr [ESP + param_1]
    //         0042401d     ADD        DL,BL
    //         0042401f     MOV        byte ptr [EAX + EDI*0x1],DL
    //         00424022     MOV        EAX,0x80808081
    //         00424027     IMUL       ESI
    //         00424029     MOV        BL,byte ptr [EDI + 0x1]
    //         0042402c     ADD        EDX,ESI
    //         0042402e     SAR        EDX,0x7
    //         00424031     MOV        ECX,EDX
    //         00424033     MOV        EAX,EBX
    //         00424035     SHR        ECX,0x1f
    //         00424038     ADD        EDX,ECX
    //         0042403a     AND        EAX,0xff
    //         0042403f     SUB        EDX,EAX
    //         00424041     MOV        EAX,0x51eb851f
    //         00424046     IMUL       EDX,dword ptr [ESP + param_4]
    //         0042404b     IMUL       EDX
    //         0042404d     SAR        EDX,0x5
    //         00424050     MOV        ECX,EDX
    //         00424052     SHR        ECX,0x1f
    //         00424055     ADD        EDX,ECX
    //         00424057     ADD        DL,BL
    //         00424059     MOV        byte ptr [EBP + -0x1],DL
    //         0042405c     MOV        DL,byte ptr [EDI + 0x2]
    //         0042405f     MOV        ECX,dword ptr [ESP + param_1]
    //         00424063     MOV        EAX,dword ptr [ESP + intense[0]]
    //         00424067     MOV        byte ptr [EBP],DL
    //         0042406a     JMP        LAB_00424083
    //                               LAB_0042406c                                                 XREF[2]:     00423f05(j), 00423f0f(j)  
    //                              color.cpp:36 (6)
    //         0042406c     MOV        DL,byte ptr [EDI + -0x1]
    //         0042406f     MOV        byte ptr [EBP + -0x3],DL
    //                              color.cpp:37 (5)
    //         00424072     MOV        DL,byte ptr [EDI]
    //         00424074     MOV        byte ptr [ECX + EDI*0x1],DL
    //                              color.cpp:38 (6)
    //         00424077     MOV        DL,byte ptr [EDI + 0x1]
    //         0042407a     MOV        byte ptr [EBP + -0x1],DL
    //                              color.cpp:39 (28)
    //         0042407d     MOV        DL,byte ptr [EDI + 0x2]
    //         00424080     MOV        byte ptr [EBP],DL
    //                               LAB_00424083                                                 XREF[1]:     0042406a(j)  
    //         00424083     INC        EAX
    //         00424084     ADD        EDI,0x4
    //         00424087     ADD        EBP,0x4
    //         0042408a     CMP        EAX,0x100
    //         0042408f     MOV        dword ptr [ESP + intense[0]],EAX
    //         00424093     JL         LAB_00423f01
    //                              color.cpp:67 (8)
    //         00424099     POP        EDI
    //         0042409a     POP        ESI
    //         0042409b     POP        EBP
    //         0042409c     POP        EBX
    //         0042409d     ADD        ESP,0x10
    //         004240a0     RET
    //         004240a1     ??         90h
    //         004240a2     NOP
    //         004240a3     NOP
    //         004240a4     NOP
    //         004240a5     NOP
    //         004240a6     NOP
    //         004240a7     NOP
    //         004240a8     NOP
    //         004240a9     NOP
    //         004240aa     NOP
    //         004240ab     NOP
    //         004240ac     NOP
    //         004240ad     NOP
    //         004240ae     NOP
    //         004240af     NOP
    //                              * void __cdecl RGE_fade_palette(class TDrawArea *,struct tagPALETTEENTRY,float,unsigned char,struct ... *
    //                              void __cdecl RGE_fade_palette(TDrawArea * param_1, tagPALETTEENTRY p
    //              void              <VOID>         <RETURN>
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[2]:     00424107(R), 00424165(R)  
    //              tagPALETTEENTRY   Stack[0x8]:4   param_2                   XREF[2]:     00424236(R), 00424303(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[7]:     00424178(R), 0042417f(R), 004241d5(R), 004241ed(R), 
    //                                                                                     0042429e(R), 004242a9(R), 004242c1(R)  
    //              uchar             Stack[0x10]:1  param_4                   XREF[1]:     00424198(R)  
    //              tagPALETTEENTR    Stack[0x14]:4  param_5                   XREF[1]:     00424100(R)  
    //              int               Stack[0x18]:4  param_6                   XREF[1]:     0042418d(R)  
    //              int               Stack[0x1c]:4  param_7                   XREF[1]:     00424186(R)  
    //              tagPALETTEENTR    Stack[-0x404   palette2                  XREF[0,4]:   00424240(*), 00424256(*), 0042430d(*), 00424323(*)  
    //              tagPALETTEENTR    Stack[-0x804   palette1                  XREF[3,8]:   004241a4(W), 00424214(R), 004242e8(R), 00424112(*), 
    //                                                                                     00424124(*), 00424135(*), 00424144(*), 00424248(*), 
    //                                                                                     00424315(*), 00424120(*), 00424128(*)  
    //              float             Stack[-0x808   fade_time2                XREF[3]:     00424194(W), 004241ba(R), 00424287(R)  
    //              long              Stack[-0x80c   old_time                  XREF[0,2]:   004240bc(W), 00424161(R)  
    //              uchar             Stack[-0x80d   done
    //              float             Stack[-0x814   delta_time
    //                               ?RGE_fade_palette@@YAXPAVTDrawArea@@UtagPALETTEENTRY@@MEPAU  XREF[4]:     set_focus:0047bc0c(c), 
    //                               RGE_fade_palette                                                          set_focus:0047bc70(c), 
    //                                                                                                         set_focus:0047bc8e(c), 
    //                                                                                                         set_focus:0047bcb7(c)  
    //                              color.cpp:71 (8)
    //         004240b0     SUB        ESP,0x810
    //         004240b6     PUSH       EBX
    //         004240b7     PUSH       EBP
    //                              color.cpp:72 (8)
    //         004240b8     XOR        BL,BL
    //         004240ba     PUSH       ESI
    //         004240bb     PUSH       EDI
    //         004240bc     MOV        byte ptr [ESP + old_time+0x3],BL
    //                              color.cpp:84 (7)
    //         004240c0     XOR        EAX,EAX
    //                               LAB_004240c2                                                 XREF[1]:     004240fe(j)  
    //         004240c2     MOV        byte ptr [ESP + EAX*0x1 + 0x20],0x0
    //                              color.cpp:88 (13)
    //         004240c7     MOV        byte ptr [ESP + EAX*0x1 + 0x420],0x0
    //         004240cf     MOV        byte ptr [ESP + EAX*0x1 + 0x22],0x0
    //                              color.cpp:89 (13)
    //         004240d4     MOV        byte ptr [ESP + EAX*0x1 + 0x422],0x0
    //         004240dc     MOV        byte ptr [ESP + EAX*0x1 + 0x21],0x0
    //                              color.cpp:90 (13)
    //         004240e1     MOV        byte ptr [ESP + EAX*0x1 + 0x421],0x0
    //         004240e9     MOV        byte ptr [ESP + EAX*0x1 + 0x23],0x0
    //                              color.cpp:91 (18)
    //         004240ee     MOV        byte ptr [ESP + EAX*0x1 + 0x423],0x0
    //         004240f6     ADD        EAX,0x4
    //         004240f9     CMP        EAX,0x400
    //         004240fe     JL         LAB_004240c2
    //                              color.cpp:94 (18)
    //         00424100     MOV        EDX,dword ptr [ESP + param_5]
    //         00424107     MOV        ESI,dword ptr [ESP + param_1]
    //         0042410e     TEST       EDX,EDX
    //         00424110     JNZ        LAB_00424120
    //                              color.cpp:95 (12)
    //         00424112     LEA        EAX=>palette1[1],[ESP + 0x20]
    //         00424116     MOV        ECX,ESI
    //         00424118     PUSH       EAX
    //         00424119     CALL       TDrawArea::GetPalette                            void GetPalette(TDrawArea * this, tagPALETTEE
    //                              color.cpp:96 (2)
    //         0042411e     JMP        LAB_0042416c
    //                               LAB_00424120                                                 XREF[1]:     00424110(j)  
    //                              color.cpp:99 (16)
    //         00424120     LEA        ESI=>palette1[1].peGreen,[ESP + 0x21]
    //         00424124     LEA        EDI=>palette1[1],[ESP + 0x20]
    //         00424128     LEA        EBP=>palette1[1].peBlue,[ESP + 0x22]
    //         0042412c     SUB        ESI,EDX
    //         0042412e     SUB        EDI,EDX
    //                              color.cpp:157 (126)
    //         00424130     LEA        EAX,[EDX + 0x1]
    //         00424133     SUB        EBP,EDX
    //         00424135     LEA        ECX=>palette1[1],[ESP + 0x20]
    //         00424139     MOV        EDX,0x100
    //                               LAB_0042413e                                                 XREF[1]:     0042415f(j)  
    //         0042413e     MOV        BL,byte ptr [EAX + -0x1]
    //         00424141     ADD        EAX,0x4
    //         00424144     MOV        byte ptr [ECX]=>palette1[1],BL
    //         00424146     MOV        BL,byte ptr [EAX + -0x3]
    //         00424149     MOV        byte ptr [ESI + EAX*0x1 + -0x4],BL
    //         0042414d     MOV        BL,byte ptr [EAX + -0x4]
    //         00424150     MOV        byte ptr [EDI + EAX*0x1 + -0x4],BL
    //         00424154     MOV        BL,byte ptr [EAX + -0x2]
    //         00424157     MOV        byte ptr [EBP + EAX*0x1 + -0x4],BL
    //         0042415b     ADD        ECX,0x4
    //         0042415e     DEC        EDX
    //         0042415f     JNZ        LAB_0042413e
    //         00424161     MOV        BL,byte ptr [ESP + old_time+0x3]
    //         00424165     MOV        ESI,dword ptr [ESP + param_1]
    //                               LAB_0042416c                                                 XREF[1]:     0042411e(j)  
    //         0042416c     PUSH       0x69
    //         0042416e     PUSH       s_C:\msdev\work\age1_x1\color.cpp                = "C:\\msdev\\work\\age1_x1\\color.cpp"
    //         00424173     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //         00424178     FLD        float ptr [ESP + param_3]
    //         0042417f     FMUL       float ptr [ESP + param_3]
    //         00424186     MOV        EDI,dword ptr [ESP + param_7]
    //         0042418d     MOV        EBP,dword ptr [ESP + param_6]
    //         00424194     MOV        dword ptr [ESP + fade_time2],EAX
    //         00424198     MOV        AL,byte ptr [ESP + param_4]
    //         0042419f     ADD        ESP,0x8
    //         004241a2     CMP        AL,0x1
    //         004241a4     FSTP       float ptr [ESP + palette1[0].peRed]
    //         004241a8     JNZ        LAB_00424278
    //                              language.dll match for 0x70: "B"
    //                               LAB_004241ae                                                 XREF[1]:     00424267(j)  
    //                              color.cpp:112 (12)
    //         004241ae     PUSH       0x70
    //         004241b0     PUSH       s_C:\msdev\work\age1_x1\color.cpp                = "C:\\msdev\\work\\age1_x1\\color.cpp"
    //         004241b5     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //                              color.cpp:113 (27)
    //         004241ba     MOV        ECX,dword ptr [ESP + fade_time2]
    //         004241be     ADD        ESP,0x8
    //         004241c1     SUB        EAX,ECX
    //         004241c3     MOV        dword ptr [ESP + Stack[-0x810]],EAX
    //         004241c7     FILD       dword ptr [ESP + Stack[-0x810]]
    //         004241cb     FMUL       float ptr [DAT_0056f020]                         = 6Fh    o
    //         004241d1     FSTP       float ptr [ESP + Stack[-0x810]]
    //                              color.cpp:114 (55)
    //         004241d5     FLD        float ptr [ESP + param_3]
    //         004241dc     FCOMP      double ptr [DAT_0056f028]
    //         004241e2     FNSTSW     AX
    //         004241e4     TEST       AH,0x41
    //         004241e7     JNZ        LAB_00424225
    //         004241e9     FLD        float ptr [ESP + Stack[-0x810]]
    //         004241ed     FCOMP      float ptr [ESP + param_3]
    //         004241f4     FNSTSW     AX
    //         004241f6     TEST       AH,0x41
    //         004241f9     JZ         LAB_00424225
    //         004241fb     FLD        float ptr [ESP + Stack[-0x810]]
    //         004241ff     FCOMP      float ptr [DAT_0056f030]
    //         00424205     FNSTSW     AX
    //         00424207     TEST       AH,0x1
    //         0042420a     JNZ        LAB_00424225
    //                              color.cpp:119 (25)
    //         0042420c     FLD        float ptr [ESP + Stack[-0x810]]
    //         00424210     FMUL       float ptr [ESP + Stack[-0x810]]
    //         00424214     FDIV       float ptr [ESP + palette1[0].peRed]
    //         00424218     FMUL       float ptr [DAT_0056f034]
    //         0042421e     CALL       __ftol                                           undefined __ftol()
    //         00424223     JMP        LAB_0042422a
    //                               LAB_00424225                                                 XREF[3]:     004241e7(j), 004241f9(j), 
    //                                                                                                         0042420a(j)  
    //                              color.cpp:115 (5)
    //         00424225     MOV        EAX,0x64
    //                               LAB_0042422a                                                 XREF[1]:     00424223(j)  
    //                              color.cpp:122 (5)
    //         0042422a     CMP        EAX,0x64
    //         0042422d     JL         LAB_00424236
    //                              color.cpp:124 (5)
    //         0042422f     MOV        EAX,0x64
    //                              color.cpp:125 (2)
    //         00424234     MOV        BL,0x1
    //                               LAB_00424236                                                 XREF[1]:     0042422d(j)  
    //                              color.cpp:127 (32)
    //         00424236     MOV        ECX,dword ptr [ESP + param_2.peRed]
    //         0042423d     PUSH       EDI
    //         0042423e     PUSH       EBP
    //         0042423f     PUSH       EAX
    //         00424240     LEA        EDX=>palette2[1],[ESP + 0x42c]
    //         00424247     PUSH       ECX
    //         00424248     LEA        EAX=>palette1[1],[ESP + 0x30]
    //         0042424c     PUSH       EDX
    //         0042424d     PUSH       EAX
    //         0042424e     CALL       RGE_translate_palette                            void RGE_translate_palette(tagPALETTEENTRY * 
    //         00424253     ADD        ESP,0x18
    //                              color.cpp:128 (23)
    //         00424256     LEA        ECX=>palette2[1],[ESP + 0x420]
    //         0042425d     PUSH       ECX
    //         0042425e     MOV        ECX,ESI
    //         00424260     CALL       TDrawArea::SetPalette                            void SetPalette(TDrawArea * this, tagPALETTEE
    //         00424265     TEST       BL,BL
    //         00424267     JZ         LAB_004241ae
    //                              color.cpp:157 (11)
    //         0042426d     POP        EDI
    //         0042426e     POP        ESI
    //         0042426f     POP        EBP
    //         00424270     POP        EBX
    //         00424271     ADD        ESP,0x810
    //         00424277     RET
    //                               LAB_00424278                                                 XREF[2]:     004241a8(j), 00424334(j)  
    //                              color.cpp:136 (15)
    //         00424278     PUSH       0x88
    //         0042427d     PUSH       s_C:\msdev\work\age1_x1\color.cpp                = "C:\\msdev\\work\\age1_x1\\color.cpp"
    //         00424282     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //                              color.cpp:138 (34)
    //         00424287     MOV        ECX,dword ptr [ESP + fade_time2]
    //         0042428b     ADD        ESP,0x8
    //         0042428e     SUB        EAX,ECX
    //         00424290     MOV        dword ptr [ESP + Stack[-0x810]],EAX
    //         00424294     FILD       dword ptr [ESP + Stack[-0x810]]
    //         00424298     FMUL       float ptr [DAT_0056f020]                         = 6Fh    o
    //         0042429e     FSUBR      float ptr [ESP + param_3]
    //         004242a5     FSTP       float ptr [ESP + Stack[-0x810]]
    //                              color.cpp:139 (55)
    //         004242a9     FLD        float ptr [ESP + param_3]
    //         004242b0     FCOMP      double ptr [DAT_0056f028]
    //         004242b6     FNSTSW     AX
    //         004242b8     TEST       AH,0x41
    //         004242bb     JNZ        LAB_004242f9
    //         004242bd     FLD        float ptr [ESP + Stack[-0x810]]
    //         004242c1     FCOMP      float ptr [ESP + param_3]
    //         004242c8     FNSTSW     AX
    //         004242ca     TEST       AH,0x41
    //         004242cd     JZ         LAB_004242f9
    //         004242cf     FLD        float ptr [ESP + Stack[-0x810]]
    //         004242d3     FCOMP      float ptr [DAT_0056f030]
    //         004242d9     FNSTSW     AX
    //         004242db     TEST       AH,0x1
    //         004242de     JNZ        LAB_004242f9
    //                              color.cpp:144 (25)
    //         004242e0     FLD        float ptr [ESP + Stack[-0x810]]
    //         004242e4     FMUL       float ptr [ESP + Stack[-0x810]]
    //         004242e8     FDIV       float ptr [ESP + palette1[0].peRed]
    //         004242ec     FMUL       float ptr [DAT_0056f034]
    //         004242f2     CALL       __ftol                                           undefined __ftol()
    //         004242f7     JMP        LAB_004242fb
    //                               LAB_004242f9                                                 XREF[3]:     004242bb(j), 004242cd(j), 
    //                                                                                                         004242de(j)  
    //                              color.cpp:140 (2)
    //         004242f9     XOR        EAX,EAX
    //                               LAB_004242fb                                                 XREF[1]:     004242f7(j)  
    //                              color.cpp:147 (4)
    //         004242fb     TEST       EAX,EAX
    //         004242fd     JG         LAB_00424303
    //                              color.cpp:149 (2)
    //         004242ff     XOR        EAX,EAX
    //                              color.cpp:150 (2)
    //         00424301     MOV        BL,0x1
    //                               LAB_00424303                                                 XREF[1]:     004242fd(j)  
    //                              color.cpp:152 (32)
    //         00424303     MOV        EDX,dword ptr [ESP + param_2.peRed]
    //         0042430a     PUSH       EDI
    //         0042430b     PUSH       EBP
    //         0042430c     PUSH       EAX
    //         0042430d     LEA        EAX=>palette2[1],[ESP + 0x42c]
    //         00424314     PUSH       EDX
    //         00424315     LEA        ECX=>palette1[1],[ESP + 0x30]
    //         00424319     PUSH       EAX
    //         0042431a     PUSH       ECX
    //         0042431b     CALL       RGE_translate_palette                            void RGE_translate_palette(tagPALETTEENTRY * 
    //         00424320     ADD        ESP,0x18
    //                              color.cpp:153 (23)
    //         00424323     LEA        EDX=>palette2[1],[ESP + 0x420]
    //         0042432a     MOV        ECX,ESI
    //         0042432c     PUSH       EDX
    //         0042432d     CALL       TDrawArea::SetPalette                            void SetPalette(TDrawArea * this, tagPALETTEE
    //         00424332     TEST       BL,BL
    //         00424334     JZ         LAB_00424278
    //                              color.cpp:157 (11)
    //         0042433a     POP        EDI
    //         0042433b     POP        ESI
    //         0042433c     POP        EBP
    //         0042433d     POP        EBX
    //         0042433e     ADD        ESP,0x810
    //         00424344     RET
    //         00424345     ??         90h
    //         00424346     NOP
    //         00424347     NOP
    //         00424348     NOP
    //         00424349     NOP
    //         0042434a     NOP
    //         0042434b     NOP
    //         0042434c     NOP
    //         0042434d     NOP
    //         0042434e     NOP
    //         0042434f     NOP
    return 0;
}

