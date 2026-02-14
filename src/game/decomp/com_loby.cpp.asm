// Auto-generated scaffold unit: com_loby.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/com_loby.cpp
#include "../include/common.h"

// Offset: 0x0042F290
undefined RGE_Lobby(RGE_Lobby* this_, void* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Lobby::RGE_Lobby(void *)                                                       *
    //                              *********************************************************************************************************
    //                              undefined __thiscall RGE_Lobby(RGE_Lobby * this, void * param_1)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Lobby *       ECX:4 (auto)   this
    //              void *            Stack[0x4]:4   param_1                   XREF[2]:     0042f2a8(R), 0042f2ba(W)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0042f2c2(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0042f2d4(R)  
    //                               ??0RGE_Lobby@@QAE@PAX@Z                                      XREF[1]:     TCommunications_Handler:00425df3(c
    //                               RGE_Lobby::RGE_Lobby
    //                              com_loby.cpp:26 (24)
    //         0042f290     MOV        EAX,FS:[0x0]
    //         0042f296     PUSH       -0x1
    //         0042f298     PUSH       FUN_0055cd3b
    //         0042f29d     PUSH       EAX
    //         0042f29e     MOV        dword ptr FS:[0x0],ESP
    //         0042f2a5     PUSH       EBX
    //         0042f2a6     PUSH       ESI
    //         0042f2a7     PUSH       EDI
    //                              com_loby.cpp:28 (6)
    //         0042f2a8     MOV        EDI,dword ptr [ESP + param_1]
    //         0042f2ac     MOV        ESI,this
    //                              com_loby.cpp:31 (38)
    //         0042f2ae     PUSH       0x8
    //         0042f2b0     MOV        dword ptr [ESI],EDI
    //         0042f2b2     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0042f2b7     ADD        ESP,0x4
    //         0042f2ba     MOV        dword ptr [ESP + param_1],EAX
    //         0042f2be     XOR        EBX,EBX
    //         0042f2c0     CMP        EAX,EBX
    //         0042f2c2     MOV        dword ptr [ESP + local_4],EBX
    //         0042f2c6     JZ         LAB_0042f2d2
    //         0042f2c8     PUSH       EDI
    //         0042f2c9     MOV        this,EAX
    //         0042f2cb     CALL       RGE_Comm_Error::RGE_Comm_Error                   undefined RGE_Comm_Error(RGE_Comm_Error * thi
    //         0042f2d0     JMP        LAB_0042f2d4
    //                               LAB_0042f2d2                                                 XREF[1]:     0042f2c6(j)  
    //         0042f2d2     XOR        EAX,EAX
    //                               LAB_0042f2d4                                                 XREF[1]:     0042f2d0(j)  
    //                              com_loby.cpp:39 (40)
    //         0042f2d4     MOV        this,dword ptr [ESP + local_c]
    //         0042f2d8     MOV        dword ptr [ESI + 0x18],EAX
    //         0042f2db     MOV        dword ptr [ESI + 0xc],EBX
    //         0042f2de     MOV        dword ptr [ESI + 0x10],EBX
    //         0042f2e1     MOV        dword ptr [ESI + 0x4],EBX
    //         0042f2e4     MOV        dword ptr [ESI + 0x8],EBX
    //         0042f2e7     MOV        byte ptr [ESI + 0x14],BL
    //         0042f2ea     MOV        EAX,ESI
    //         0042f2ec     POP        EDI
    //         0042f2ed     POP        ESI
    //         0042f2ee     MOV        dword ptr FS:[0x0],this
    //         0042f2f5     POP        EBX
    //         0042f2f6     ADD        ESP,0xc
    //         0042f2f9     RET        0x4
}

// Offset: 0x0042F300
void RGE_Lobby(RGE_Lobby* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Lobby::~RGE_Lobby(void)                                                        *
    //                              *********************************************************************************************************
    //                              void __thiscall ~RGE_Lobby(RGE_Lobby * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Lobby *       ECX:4 (auto)   this
    //                               ??1RGE_Lobby@@QAE@XZ                                         XREF[1]:     ~TCommunications_Handler:004262ec(
    //                               RGE_Lobby::~RGE_Lobby
    //                              com_loby.cpp:44 (4)
    //         0042f300     PUSH       ESI
    //         0042f301     PUSH       EDI
    //         0042f302     MOV        EDI,this
    //                              com_loby.cpp:45 (7)
    //         0042f304     MOV        ESI,dword ptr [EDI + 0x18]
    //         0042f307     TEST       ESI,ESI
    //         0042f309     JZ         LAB_0042f31b
    //                              com_loby.cpp:46 (16)
    //         0042f30b     MOV        this,ESI
    //         0042f30d     CALL       RGE_Comm_Error::~RGE_Comm_Error                  void ~RGE_Comm_Error(RGE_Comm_Error * this)
    //         0042f312     PUSH       ESI
    //         0042f313     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0042f318     ADD        ESP,0x4
    //                               LAB_0042f31b                                                 XREF[1]:     0042f309(j)  
    //                              com_loby.cpp:48 (7)
    //         0042f31b     MOV        this,EDI
    //         0042f31d     CALL       RGE_Lobby::ClearLobbyInfo                        void ClearLobbyInfo(RGE_Lobby * this)
    //                              com_loby.cpp:49 (3)
    //         0042f322     POP        EDI
    //         0042f323     POP        ESI
    //         0042f324     RET
}

// Offset: 0x0042F330
void ClearLobbyInfo(RGE_Lobby* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Lobby::ClearLobbyInfo(void)                                               *
    //                              *********************************************************************************************************
    //                              void __thiscall ClearLobbyInfo(RGE_Lobby * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Lobby *       ECX:4 (auto)   this
    //                               ?ClearLobbyInfo@RGE_Lobby@@QAEXXZ                            XREF[2]:     ~RGE_Lobby:0042f31d(c), 
    //                               RGE_Lobby::ClearLobbyInfo                                                 CheckForLobbyLaunch:0042f44a(c)  
    //                              com_loby.cpp:53 (4)
    //         0042f330     PUSH       EBX
    //         0042f331     PUSH       ESI
    //         0042f332     MOV        ESI,this
    //                              com_loby.cpp:57 (9)
    //         0042f334     XOR        EBX,EBX
    //         0042f336     MOV        EAX,dword ptr [ESI + 0x10]
    //         0042f339     CMP        EAX,EBX
    //         0042f33b     JZ         LAB_0042f349
    //                              com_loby.cpp:59 (9)
    //         0042f33d     PUSH       EAX
    //         0042f33e     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0042f343     ADD        ESP,0x4
    //                              com_loby.cpp:61 (3)
    //         0042f346     MOV        dword ptr [ESI + 0x10],EBX
    //                               LAB_0042f349                                                 XREF[1]:     0042f33b(j)  
    //                              com_loby.cpp:65 (7)
    //         0042f349     MOV        EAX,dword ptr [ESI + 0x8]
    //         0042f34c     CMP        EAX,EBX
    //         0042f34e     JZ         LAB_0042f367
    //                              com_loby.cpp:67 (6)
    //         0042f350     MOV        this,dword ptr [EAX]
    //         0042f352     PUSH       EAX
    //         0042f353     CALL       dword ptr [ECX + this->glpDPL2]
    //                              com_loby.cpp:68 (14)
    //         0042f356     MOV        this,dword ptr [ESI + 0x18]
    //         0042f359     PUSH       s_Release                                        = "Release"
    //         0042f35e     PUSH       EAX=>DAT_fffffff8
    //         0042f35f     CALL       RGE_Comm_Error::ShowReturn                       void ShowReturn(RGE_Comm_Error * this, long p
    //                              com_loby.cpp:69 (3)
    //         0042f364     MOV        dword ptr [ESI + 0x8],EBX
    //                               LAB_0042f367                                                 XREF[1]:     0042f34e(j)  
    //                              com_loby.cpp:73 (3)
    //         0042f367     MOV        byte ptr [ESI + 0x14],BL
    //                              com_loby.cpp:76 (3)
    //         0042f36a     MOV        dword ptr [ESI + 0xc],EBX
    //                              com_loby.cpp:77 (3)
    //         0042f36d     POP        ESI
    //         0042f36e     POP        EBX
    //         0042f36f     RET
}

// Offset: 0x0042F370
int IsLobbyLaunched(RGE_Lobby* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall RGE_Lobby::IsLobbyLaunched(void)                                               *
    //                              *********************************************************************************************************
    //                              int __thiscall IsLobbyLaunched(RGE_Lobby * this)
    //              int               EAX:4          <RETURN>
    //              RGE_Lobby *       ECX:4 (auto)   this
    //                               ?IsLobbyLaunched@RGE_Lobby@@QAEHXZ                           XREF[1]:     IsLobbyLaunched:0042d176(c)  
    //                               RGE_Lobby::IsLobbyLaunched
    //                              com_loby.cpp:80 (3)
    //         0042f370     PUSH       ESI
    //         0042f371     MOV        ESI,this
    //                              com_loby.cpp:81 (26)
    //         0042f373     MOV        this,dword ptr [L]                               = 00000000
    //         0042f379     XOR        EAX,EAX
    //         0042f37b     MOV        AL,byte ptr [ESI + 0x14]
    //         0042f37e     PUSH       EAX
    //         0042f37f     PUSH       s_LOBBY_GAME_LAUNCH_STATUS_=_%d                  = "LOBBY GAME LAUNCH STATUS = %d"
    //         0042f384     PUSH       this
    //         0042f385     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         0042f38a     ADD        ESP,0xc
    //                              com_loby.cpp:82 (5)
    //         0042f38d     XOR        EAX,EAX
    //         0042f38f     MOV        AL,byte ptr [ESI + 0x14]
    //                              com_loby.cpp:83 (2)
    //         0042f392     POP        ESI
    //         0042f393     RET
}

// Offset: 0x0042F3A0
int EnumPlayersCallbackLobby(ulong param_1, ulong param_2, DPNAME* param_3, ulong param_4, void* param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * int __stdcall EnumPlayersCallbackLobby(unsigned long,unsigned long,struct DPNAME *,unsigned long,v... *
    //                              *********************************************************************************************************
    //                              int __stdcall EnumPlayersCallbackLobby(ulong param_1, ulong param_2,
    //              int               EAX:4          <RETURN>
    //              ulong             Stack[0x4]:4   param_1                   XREF[1]:     0042f3a0(R)  
    //              ulong             Stack[0x8]:4   param_2
    //              DPNAME *          Stack[0xc]:4   param_3                   XREF[1]:     0042f3b7(R)  
    //              ulong             Stack[0x10]:4  param_4                   XREF[1]:     0042f3e7(R)  
    //              void *            Stack[0x14]:4  param_5
    //                               ?EnumPlayersCallbackLobby@@YGHKKPAUDPNAME@@KPAX@Z            XREF[1]:     CheckForLobbyLaunch:0042f606(*)  
    //                               EnumPlayersCallbackLobby
    //                              com_loby.cpp:92 (23)
    //         0042f3a0     MOV        EAX,dword ptr [ESP + param_1]
    //         0042f3a4     MOV        ECX,dword ptr [L]                                = 00000000
    //         0042f3aa     PUSH       EBX
    //         0042f3ab     PUSH       EAX
    //         0042f3ac     PUSH       s_ENUMPLAYER:_DPID_=_%ld                         = "ENUMPLAYER: DPID = %ld"
    //         0042f3b1     PUSH       ECX
    //         0042f3b2     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //                              com_loby.cpp:100 (28)
    //         0042f3b7     MOV        EDX,dword ptr [ESP + param_3]
    //         0042f3bb     MOV        ECX,dword ptr [L]                                = 00000000
    //         0042f3c1     ADD        ESP,0xc
    //         0042f3c4     MOV        EAX,dword ptr [EDX + 0x8]
    //         0042f3c7     PUSH       EAX
    //         0042f3c8     PUSH       s_ENUMPLAYER:_NAME_=_%s                          = "ENUMPLAYER: NAME = %s"
    //         0042f3cd     PUSH       ECX
    //         0042f3ce     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //                              com_loby.cpp:103 (20)
    //         0042f3d3     MOV        EDX,dword ptr [L]                                = 00000000
    //         0042f3d9     ADD        ESP,0xc
    //         0042f3dc     PUSH       s_+++_Enumeration_not_done                       = "+++ Enumeration not done"
    //         0042f3e1     PUSH       EDX
    //         0042f3e2     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //                              com_loby.cpp:105 (12)
    //         0042f3e7     MOV        BL,byte ptr [ESP + param_4]
    //         0042f3eb     ADD        ESP,0x8
    //         0042f3ee     TEST       BL,0x10
    //         0042f3f1     JZ         LAB_0042f406
    //                              com_loby.cpp:106 (19)
    //         0042f3f3     MOV        EAX,[L]                                          = 00000000
    //         0042f3f8     PUSH       s_Remote_Player                                  = "Remote Player"
    //         0042f3fd     PUSH       EAX
    //         0042f3fe     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         0042f403     ADD        ESP,0x8
    //                               LAB_0042f406                                                 XREF[1]:     0042f3f1(j)  
    //                              com_loby.cpp:108 (5)
    //         0042f406     TEST       BL,0x8
    //         0042f409     JZ         LAB_0042f41f
    //                              com_loby.cpp:109 (20)
    //         0042f40b     MOV        ECX,dword ptr [L]                                = 00000000
    //         0042f411     PUSH       s_Local_Player                                   = "Local Player"
    //         0042f416     PUSH       ECX
    //         0042f417     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         0042f41c     ADD        ESP,0x8
    //                               LAB_0042f41f                                                 XREF[1]:     0042f409(j)  
    //                              com_loby.cpp:111 (5)
    //         0042f41f     MOV        EAX,0x1
    //                              com_loby.cpp:112 (4)
    //         0042f424     POP        EBX
    //         0042f425     RET        0x14
}

// Offset: 0x0042F430
uchar CheckForLobbyLaunch(RGE_Lobby* this_, IDirectPlay3** param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall RGE_Lobby::CheckForLobbyLaunch(struct IDirectPlay3 * &)              *
    //                              *********************************************************************************************************
    //                              uchar __thiscall CheckForLobbyLaunch(RGE_Lobby * this, IDirectPlay3 
    //              uchar             AL:1           <RETURN>
    //              RGE_Lobby *       ECX:4 (auto)   this
    //              IDirectPlay3 *    Stack[0x4]:4   param_1                   XREF[1]:     0042f433(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0042f43b(W)  
    //              ulong             Stack[-0x8]:4  dwSize
    //                               ?CheckForLobbyLaunch@RGE_Lobby@@QAEEAAPAUIDirectPlay3@@@Z    XREF[1]:     LaunchLobbyGame:0042d19a(c)  
    //                               RGE_Lobby::CheckForLobbyLaunch
    //                              com_loby.cpp:117 (3)
    //         0042f430     PUSH       this
    //         0042f431     PUSH       EBX
    //         0042f432     PUSH       EBP
    //                              com_loby.cpp:127 (23)
    //         0042f433     MOV        EBP,dword ptr [ESP + param_1]
    //         0042f437     PUSH       ESI
    //         0042f438     PUSH       EDI
    //         0042f439     MOV        ESI,this
    //         0042f43b     MOV        dword ptr [ESP + local_4],0x29
    //         0042f443     MOV        dword ptr [EBP],0x0
    //                              com_loby.cpp:130 (5)
    //         0042f44a     CALL       RGE_Lobby::ClearLobbyInfo                        void ClearLobbyInfo(RGE_Lobby * this)
    //                              com_loby.cpp:139 (17)
    //         0042f44f     PUSH       0x0
    //         0042f451     LEA        EDI,[ESI + 0x4]
    //         0042f454     PUSH       0x0
    //         0042f456     PUSH       0x0
    //         0042f458     PUSH       EDI
    //         0042f459     PUSH       0x0
    //         0042f45b     CALL       _DirectPlayLobbyCreateA@20                       undefined _DirectPlayLobbyCreateA@20()
    //                              com_loby.cpp:140 (16)
    //         0042f460     MOV        this,dword ptr [ESI + 0x18]
    //         0042f463     MOV        EBX,EAX
    //         0042f465     PUSH       s_Lobby_Create                                   = "Lobby Create"
    //         0042f46a     PUSH       EBX
    //         0042f46b     CALL       RGE_Comm_Error::ShowReturn                       void ShowReturn(RGE_Comm_Error * this, long p
    //                              com_loby.cpp:142 (4)
    //         0042f470     TEST       EBX,EBX
    //         0042f472     JGE        LAB_0042f47e
    //                              com_loby.cpp:148 (2)
    //         0042f474     XOR        AL,AL
    //                              com_loby.cpp:239 (8)
    //         0042f476     POP        EDI
    //         0042f477     POP        ESI
    //         0042f478     POP        EBP
    //         0042f479     POP        EBX
    //         0042f47a     POP        this
    //         0042f47b     RET        0x4
    //                               LAB_0042f47e                                                 XREF[1]:     0042f472(j)  
    //                              com_loby.cpp:152 (16)
    //         0042f47e     MOV        EAX,dword ptr [EDI]
    //         0042f480     LEA        EDI,[ESI + 0x8]
    //         0042f483     PUSH       EDI
    //         0042f484     PUSH       _IID_IDirectPlayLobby2A                          = 80h
    //         0042f489     MOV        this,dword ptr [EAX]
    //         0042f48b     PUSH       EAX
    //         0042f48c     CALL       dword ptr [this->HostHWND]
    //                              com_loby.cpp:153 (6)
    //         0042f48e     MOV        EAX,dword ptr [EDI]
    //         0042f490     TEST       EAX,EAX
    //         0042f492     JNZ        LAB_0042f49e
    //                              com_loby.cpp:159 (2)
    //         0042f494     XOR        AL,AL
    //                              com_loby.cpp:239 (8)
    //         0042f496     POP        EDI
    //         0042f497     POP        ESI
    //         0042f498     POP        EBP
    //         0042f499     POP        EBX
    //         0042f49a     POP        this
    //         0042f49b     RET        0x4
    //                               LAB_0042f49e                                                 XREF[1]:     0042f492(j)  
    //                              com_loby.cpp:164 (15)
    //         0042f49e     MOV        EDX,dword ptr [EAX]
    //         0042f4a0     LEA        this,[ESP + 0x10]
    //         0042f4a4     PUSH       this
    //         0042f4a5     PUSH       0x0=>DAT_fffffff8
    //         0042f4a7     PUSH       0x0=>DAT_fffffff4
    //         0042f4a9     PUSH       EAX=>DAT_fffffff0
    //         0042f4aa     CALL       dword ptr [EDX + 0x20]
    //                              com_loby.cpp:168 (11)
    //         0042f4ad     MOV        EDX,dword ptr [ESP + 0x10]
    //         0042f4b1     INC        EDX
    //         0042f4b2     PUSH       EDX
    //         0042f4b3     CALL       operator_new                                     void * operator_new(uint param_1)
    //                              com_loby.cpp:171 (22)
    //         0042f4b8     MOV        this,dword ptr [EDI]
    //         0042f4ba     ADD        ESP,0x4
    //         0042f4bd     LEA        EBX,[ESP + 0x10]
    //         0042f4c1     MOV        dword ptr [ESI + 0x10],EAX
    //         0042f4c4     MOV        EDX,dword ptr [this->HostHWND]
    //         0042f4c6     PUSH       EBX
    //         0042f4c7     PUSH       EAX=>DAT_fffffff8
    //         0042f4c8     PUSH       0x0=>DAT_fffffff4
    //         0042f4ca     PUSH       this=>DAT_fffffff0
    //         0042f4cb     CALL       dword ptr [EDX + 0x20]
    //                              com_loby.cpp:173 (4)
    //         0042f4ce     TEST       EAX,EAX
    //         0042f4d0     JGE        LAB_0042f4e0
    //                              com_loby.cpp:176 (4)
    //         0042f4d2     MOV        byte ptr [ESI + 0x14],0x0
    //                              com_loby.cpp:177 (2)
    //         0042f4d6     XOR        AL,AL
    //                              com_loby.cpp:239 (8)
    //         0042f4d8     POP        EDI
    //         0042f4d9     POP        ESI
    //         0042f4da     POP        EBP
    //         0042f4db     POP        EBX
    //         0042f4dc     POP        this
    //         0042f4dd     RET        0x4
    //                               LAB_0042f4e0                                                 XREF[1]:     0042f4d0(j)  
    //                              com_loby.cpp:180 (16)
    //         0042f4e0     MOV        EAX,[L]                                          = 00000000
    //         0042f4e5     PUSH       s_LOBBY_LAUNCHED_GAME.                           = "LOBBY LAUNCHED GAME."
    //         0042f4ea     PUSH       EAX=>DAT_fffffff8
    //         0042f4eb     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //                              com_loby.cpp:184 (16)
    //         0042f4f0     MOV        this,dword ptr [ESI + 0x10]
    //         0042f4f3     ADD        ESP,0x8
    //         0042f4f6     MOV        EDX,dword ptr [ECX + this->glpDPL2]
    //         0042f4f9     MOV        dword ptr [EDX + 0x4],0x44
    //                              com_loby.cpp:187 (13)
    //         0042f500     MOV        EAX,dword ptr [ESI + 0x10]
    //         0042f503     MOV        this,dword ptr [EAX + 0x8]
    //         0042f506     MOV        dword ptr [this->HostHWND + 0x28],0x9
    //                              com_loby.cpp:190 (16)
    //         0042f50d     MOV        this,dword ptr [ESI + 0x10]
    //         0042f510     MOV        EAX,dword ptr [EDI]
    //         0042f512     PUSH       this
    //         0042f513     PUSH       0x0=>DAT_fffffff8
    //         0042f515     PUSH       0x0=>DAT_fffffff4
    //         0042f517     MOV        EDX,dword ptr [EAX]
    //         0042f519     PUSH       EAX=>DAT_fffffff0
    //         0042f51a     CALL       dword ptr [EDX + 0x30]
    //                              com_loby.cpp:194 (17)
    //         0042f51d     MOV        EDX,dword ptr [L]                                = 00000000
    //         0042f523     PUSH       s_Pre-connect                                    = "Pre-connect"
    //         0042f528     PUSH       EDX=>DAT_fffffff8
    //         0042f529     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //                              com_loby.cpp:196 (19)
    //         0042f52e     MOV        EDI,dword ptr [EDI]
    //         0042f530     ADD        ESP,0x8
    //         0042f533     LEA        EBX,[ESI + 0xc]
    //         0042f536     MOV        EAX,dword ptr [EDI]
    //         0042f538     PUSH       0x0
    //         0042f53a     PUSH       EBX=>DAT_fffffff8
    //         0042f53b     PUSH       0x0=>DAT_fffffff4
    //         0042f53d     PUSH       EDI=>DAT_fffffff0
    //         0042f53e     CALL       dword ptr [EAX + 0xc]
    //                              com_loby.cpp:198 (22)
    //         0042f541     MOV        this,dword ptr [L]                               = 00000000
    //         0042f547     PUSH       s_Post_Connect                                   = "Post Connect"
    //         0042f54c     PUSH       this=>DAT_fffffff8
    //         0042f54d     MOV        EDI,EAX
    //         0042f54f     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         0042f554     ADD        ESP,0x8
    //                              com_loby.cpp:200 (4)
    //         0042f557     TEST       EDI,EDI
    //         0042f559     JGE        LAB_0042f599
    //                              com_loby.cpp:202 (8)
    //         0042f55b     CMP        EDI,0x887700f0
    //         0042f561     JNZ        LAB_0042f56d
    //                              com_loby.cpp:206 (2)
    //         0042f563     OR         AL,0xff
    //                              com_loby.cpp:239 (8)
    //         0042f565     POP        EDI
    //         0042f566     POP        ESI
    //         0042f567     POP        EBP
    //         0042f568     POP        EBX
    //         0042f569     POP        this
    //         0042f56a     RET        0x4
    //                               LAB_0042f56d                                                 XREF[1]:     0042f561(j)  
    //                              com_loby.cpp:211 (17)
    //         0042f56d     MOV        EDX,dword ptr [L]                                = 00000000
    //         0042f573     PUSH       s_Failed_to_connect!                             = "Failed to connect!"
    //         0042f578     PUSH       EDX=>DAT_fffffff8
    //         0042f579     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //                              com_loby.cpp:212 (17)
    //         0042f57e     MOV        this,dword ptr [ESI + 0x18]
    //         0042f581     ADD        ESP,0x8
    //         0042f584     PUSH       s_Connect                                        = "Connect"
    //         0042f589     PUSH       EDI=>DAT_fffffff8
    //         0042f58a     CALL       RGE_Comm_Error::ShowReturn                       void ShowReturn(RGE_Comm_Error * this, long p
    //                              com_loby.cpp:213 (2)
    //         0042f58f     OR         AL,0xff
    //                              com_loby.cpp:239 (8)
    //         0042f591     POP        EDI
    //         0042f592     POP        ESI
    //         0042f593     POP        EBP
    //         0042f594     POP        EBX
    //         0042f595     POP        this
    //         0042f596     RET        0x4
    //                               LAB_0042f599                                                 XREF[1]:     0042f559(j)  
    //                              com_loby.cpp:220 (16)
    //         0042f599     MOV        EAX,[L]                                          = 00000000
    //         0042f59e     PUSH       s_Pre_QI                                         = "Pre QI"
    //         0042f5a3     PUSH       EAX=>DAT_fffffff8
    //         0042f5a4     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //                              com_loby.cpp:221 (16)
    //         0042f5a9     MOV        EBX,dword ptr [EBX]
    //         0042f5ab     ADD        ESP,0x8
    //         0042f5ae     MOV        this,dword ptr [EBX]
    //         0042f5b0     PUSH       EBP
    //         0042f5b1     PUSH       _IID_IDirectPlay3A                               = 41h    A
    //         0042f5b6     PUSH       EBX=>DAT_fffffff4
    //         0042f5b7     CALL       dword ptr [this->HostHWND]
    //                              com_loby.cpp:222 (16)
    //         0042f5b9     MOV        this,dword ptr [ESI + 0x18]
    //         0042f5bc     MOV        EDI,EAX
    //         0042f5be     PUSH       s_Lobby_QI                                       = "Lobby QI"
    //         0042f5c3     PUSH       EDI=>DAT_fffffff8
    //         0042f5c4     CALL       RGE_Comm_Error::ShowReturn                       void ShowReturn(RGE_Comm_Error * this, long p
    //                              com_loby.cpp:224 (4)
    //         0042f5c9     TEST       EDI,EDI
    //         0042f5cb     JGE        LAB_0042f5eb
    //                              com_loby.cpp:226 (20)
    //         0042f5cd     MOV        EDX,dword ptr [L]                                = 00000000
    //         0042f5d3     PUSH       s_Queryinterface_failed.                         = "Queryinterface failed."
    //         0042f5d8     PUSH       EDX=>DAT_fffffff8
    //         0042f5d9     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         0042f5de     ADD        ESP,0x8
    //                              com_loby.cpp:228 (2)
    //         0042f5e1     OR         AL,0xff
    //                              com_loby.cpp:239 (8)
    //         0042f5e3     POP        EDI
    //         0042f5e4     POP        ESI
    //         0042f5e5     POP        EBP
    //         0042f5e6     POP        EBX
    //         0042f5e7     POP        this
    //         0042f5e8     RET        0x4
    //                               LAB_0042f5eb                                                 XREF[1]:     0042f5cb(j)  
    //                              com_loby.cpp:233 (16)
    //         0042f5eb     MOV        EAX,[L]                                          = 00000000
    //         0042f5f0     PUSH       s_Calling_enumeration_of_players.                = "Calling enumeration of players."
    //         0042f5f5     PUSH       EAX=>DAT_fffffff8
    //         0042f5f6     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //                              com_loby.cpp:234 (22)
    //         0042f5fb     MOV        EAX,dword ptr [EBP]
    //         0042f5fe     ADD        ESP,0x8
    //         0042f601     MOV        this,dword ptr [EAX]
    //         0042f603     PUSH       0x0
    //         0042f605     PUSH       ESI=>DAT_fffffff8
    //         0042f606     PUSH       EnumPlayersCallbackLobby
    //         0042f60b     PUSH       0x0=>DAT_fffffff0
    //         0042f60d     PUSH       EAX
    //         0042f60e     CALL       dword ptr [this->HostHWND + 0x30]
    //                              com_loby.cpp:235 (20)
    //         0042f611     MOV        EDX,dword ptr [L]                                = 00000000
    //         0042f617     PUSH       s_Post_ENUMP                                     = "Post ENUMP"
    //         0042f61c     PUSH       EDX=>DAT_fffffff8
    //         0042f61d     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         0042f622     ADD        ESP,0x8
    //                              com_loby.cpp:237 (5)
    //         0042f625     MOV        AL,0x1
    //         0042f627     MOV        byte ptr [ESI + 0x14],AL
    //                              com_loby.cpp:239 (8)
    //         0042f62a     POP        EDI
    //         0042f62b     POP        ESI
    //         0042f62c     POP        EBP
    //         0042f62d     POP        EBX
    //         0042f62e     POP        this
    //         0042f62f     RET        0x4
}

// Offset: 0x0042F640
uchar IsThisHost(RGE_Lobby* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall RGE_Lobby::IsThisHost(void)                                          *
    //                              *********************************************************************************************************
    //                              uchar __thiscall IsThisHost(RGE_Lobby * this)
    //              uchar             AL:1           <RETURN>
    //              RGE_Lobby *       ECX:4 (auto)   this
    //                               ?IsThisHost@RGE_Lobby@@QAEEXZ                                XREF[1]:     LaunchLobbyGame:0042d253(c)  
    //                               RGE_Lobby::IsThisHost
    //                              com_loby.cpp:244 (7)
    //         0042f640     MOV        AL,byte ptr [ECX + this->lobby_game]
    //         0042f643     TEST       AL,AL
    //         0042f645     JNZ        LAB_0042f64a
    //                              com_loby.cpp:246 (2)
    //         0042f647     XOR        AL,AL
    //                              com_loby.cpp:252 (1)
    //         0042f649     RET
    //                               LAB_0042f64a                                                 XREF[1]:     0042f645(j)  
    //                              com_loby.cpp:248 (10)
    //         0042f64a     MOV        EAX,dword ptr [ECX + this->glpdplConnection]
    //         0042f64d     MOV        EAX,dword ptr [EAX + 0x4]
    //         0042f650     SHR        AL,0x1
    //         0042f652     AND        AL,0x1
    //                              com_loby.cpp:252 (1)
    //         0042f654     RET
}

// Offset: 0x0042F660
uchar GetPlayerInfo(RGE_Lobby* this_, char** param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall RGE_Lobby::GetPlayerInfo(char * *)                                   *
    //                              *********************************************************************************************************
    //                              uchar __thiscall GetPlayerInfo(RGE_Lobby * this, char * * param_1)
    //              uchar             AL:1           <RETURN>
    //              RGE_Lobby *       ECX:4 (auto)   this
    //              char * *          Stack[0x4]:4   param_1                   XREF[1]:     0042f672(R)  
    //                               ?GetPlayerInfo@RGE_Lobby@@QAEEPAPAD@Z                        XREF[1]:     LaunchLobbyGame:0042d22b(c)  
    //                               RGE_Lobby::GetPlayerInfo
    //                              com_loby.cpp:257 (7)
    //         0042f660     MOV        AL,byte ptr [ECX + this->lobby_game]
    //         0042f663     TEST       AL,AL
    //         0042f665     JNZ        LAB_0042f66c
    //                              com_loby.cpp:259 (2)
    //         0042f667     XOR        AL,AL
    //                              com_loby.cpp:263 (3)
    //         0042f669     RET        0x4
    //                               LAB_0042f66c                                                 XREF[1]:     0042f665(j)  
    //                              com_loby.cpp:261 (15)
    //         0042f66c     MOV        EAX,dword ptr [ECX + this->glpdplConnection]
    //         0042f66f     MOV        this,dword ptr [EAX + 0xc]
    //         0042f672     MOV        EAX,dword ptr [ESP + param_1]
    //         0042f676     MOV        EDX,dword ptr [ECX + this->glpDPL2]
    //         0042f679     MOV        dword ptr [EAX],EDX
    //                              com_loby.cpp:262 (2)
    //         0042f67b     MOV        AL,0x1
    //                              com_loby.cpp:263 (3)
    //         0042f67d     RET        0x4
}

// Offset: 0x0042F680
uchar GetSessionInfo(RGE_Lobby* this_, DPSESSIONDESC2* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall RGE_Lobby::GetSessionInfo(struct DPSESSIONDESC2 &)                   *
    //                              *********************************************************************************************************
    //                              uchar __thiscall GetSessionInfo(RGE_Lobby * this, DPSESSIONDESC2 * p
    //              uchar             AL:1           <RETURN>
    //              RGE_Lobby *       ECX:4 (auto)   this
    //              DPSESSIONDESC2    Stack[0x4]:4   param_1                   XREF[1]:     0042f690(R)  
    //                               ?GetSessionInfo@RGE_Lobby@@QAEEAAUDPSESSIONDESC2@@@Z         XREF[1]:     LaunchLobbyGame:0042d1ee(c)  
    //                               RGE_Lobby::GetSessionInfo
    //                              com_loby.cpp:268 (7)
    //         0042f680     MOV        AL,byte ptr [ECX + this->lobby_game]
    //         0042f683     TEST       AL,AL
    //         0042f685     JNZ        LAB_0042f68c
    //                              com_loby.cpp:270 (2)
    //         0042f687     XOR        AL,AL
    //                              com_loby.cpp:274 (3)
    //         0042f689     RET        0x4
    //                               LAB_0042f68c                                                 XREF[1]:     0042f685(j)  
    //                              com_loby.cpp:272 (20)
    //         0042f68c     MOV        EAX,dword ptr [ECX + this->glpdplConnection]
    //         0042f68f     PUSH       EDI
    //         0042f690     MOV        EDI,dword ptr [ESP + param_1]
    //         0042f694     PUSH       ESI
    //         0042f695     MOV        ESI,dword ptr [EAX + 0x8]
    //         0042f698     MOV        this,0x14
    //         0042f69d     MOVSD.REP  ES:EDI,ESI
    //         0042f69f     POP        ESI
    //                              com_loby.cpp:273 (3)
    //         0042f6a0     MOV        AL,0x1
    //         0042f6a2     POP        EDI
    //                              com_loby.cpp:274 (3)
    //         0042f6a3     RET        0x4
}

// Offset: 0x0042F6B0
long SendZoneHandshakeResponse(RGE_Lobby* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: long __thiscall RGE_Lobby::SendZoneHandshakeResponse(void)                                    *
    //                              *********************************************************************************************************
    //                              long __thiscall SendZoneHandshakeResponse(RGE_Lobby * this)
    //              long              EAX:4          <RETURN>
    //              RGE_Lobby *       ECX:4 (auto)   this
    //                               ?SendZoneHandshakeResponse@RGE_Lobby@@QAEJXZ
    //                               RGE_Lobby::SendZoneHandshakeResponse
    //                              com_loby.cpp:277 (10)
    //         0042f6b0     MOV        DL,byte ptr [ECX + this->lobby_game]
    //         0042f6b3     XOR        EAX,EAX
    //         0042f6b5     TEST       DL,DL
    //         0042f6b7     SETNZ      AL
    //                              com_loby.cpp:282 (1)
    //         0042f6ba     RET
}

// Offset: 0x0042F6C0
int GameIsOver(RGE_Lobby* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall RGE_Lobby::GameIsOver(void)                                                    *
    //                              *********************************************************************************************************
    //                              int __thiscall GameIsOver(RGE_Lobby * this)
    //              int               EAX:4          <RETURN>
    //              RGE_Lobby *       ECX:4 (auto)   this
    //                               ?GameIsOver@RGE_Lobby@@QAEHXZ
    //                               RGE_Lobby::GameIsOver
    //                              com_loby.cpp:285 (10)
    //         0042f6c0     MOV        DL,byte ptr [ECX + this->lobby_game]
    //         0042f6c3     XOR        EAX,EAX
    //         0042f6c5     TEST       DL,DL
    //         0042f6c7     SETNZ      AL
    //                              com_loby.cpp:292 (1)
    //         0042f6ca     RET
}

// Offset: 0x0042F6D0
long ReceiveZoneMessages(RGE_Lobby* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: long __thiscall RGE_Lobby::ReceiveZoneMessages(void)                                          *
    //                              *********************************************************************************************************
    //                              long __thiscall ReceiveZoneMessages(RGE_Lobby * this)
    //              long              EAX:4          <RETURN>
    //              RGE_Lobby *       ECX:4 (auto)   this
    //              char[2048]        Stack[-0x804   Data                      XREF[1,1]:   0042f6f4(*), 0042f6ed(*)  
    //              ulong             Stack[-0x808   dwRXFlags                 XREF[2]:     0042f6e8(*), 0042f6f8(W)  
    //              ulong             Stack[-0x80c   dwDataSize
    //                               ?ReceiveZoneMessages@RGE_Lobby@@QAEJXZ
    //                               RGE_Lobby::ReceiveZoneMessages
    //                              com_loby.cpp:295 (10)
    //         0042f6d0     SUB        ESP,0x808
    //         0042f6d6     PUSH       ESI
    //         0042f6d7     PUSH       EDI
    //         0042f6d8     MOV        EDI,this
    //                              com_loby.cpp:296 (5)
    //         0042f6da     MOV        AL,byte ptr [EDI + 0x14]
    //         0042f6dd     TEST       AL,AL
    //                              com_loby.cpp:297 (6)
    //         0042f6df     JZ         LAB_0042f813
    //                              com_loby.cpp:309 (36)
    //         0042f6e5     MOV        EAX,dword ptr [EDI + 0x4]
    //         0042f6e8     LEA        EDX=>dwRXFlags,[ESP + 0x8]
    //         0042f6ec     PUSH       EDX
    //         0042f6ed     LEA        EDX=>Data[4],[ESP + 0x14]
    //         0042f6f1     MOV        this,dword ptr [EAX]
    //         0042f6f3     PUSH       EDX
    //         0042f6f4     LEA        EDX=>Data,[ESP + 0x14]
    //         0042f6f8     MOV        dword ptr [ESP + dwRXFlags],0x800
    //         0042f700     PUSH       EDX
    //         0042f701     PUSH       0x0
    //         0042f703     PUSH       0x0
    //         0042f705     PUSH       EAX
    //         0042f706     CALL       dword ptr [this->HostHWND + 0x24]
    //                              com_loby.cpp:311 (16)
    //         0042f709     MOV        this,dword ptr [EDI + 0x18]
    //         0042f70c     MOV        ESI,EAX
    //         0042f70e     PUSH       s_RX_Lobby_Messages                              = "RX Lobby Messages"
    //         0042f713     PUSH       ESI=>DAT_fffffff8
    //         0042f714     CALL       RGE_Comm_Error::ShowReturn                       void ShowReturn(RGE_Comm_Error * this, long p
    //                              com_loby.cpp:315 (24)
    //         0042f719     CMP        ESI,0x887700be
    //         0042f71f     JZ         LAB_0042f813
    //         0042f725     MOV        EAX,dword ptr [ESP + 0x8]
    //         0042f729     TEST       EAX,EAX
    //         0042f72b     JZ         LAB_0042f813
    //                              com_loby.cpp:321 (4)
    //         0042f731     TEST       ESI,ESI
    //         0042f733     JZ         LAB_0042f74e
    //                              com_loby.cpp:324 (16)
    //         0042f735     MOV        this,dword ptr [EDI + 0x18]
    //         0042f738     PUSH       s_RxLOBBY_MSG                                    = "RxLOBBY MSG"
    //         0042f73d     PUSH       ESI=>DAT_fffffff8
    //         0042f73e     CALL       RGE_Comm_Error::ShowReturn                       void ShowReturn(RGE_Comm_Error * this, long p
    //         0042f743     XOR        EAX,EAX
    //                              com_loby.cpp:356 (9)
    //         0042f745     POP        EDI
    //         0042f746     POP        ESI
    //         0042f747     ADD        ESP,0x808
    //         0042f74d     RET
    //                               LAB_0042f74e                                                 XREF[1]:     0042f733(j)  
    //                              com_loby.cpp:328 (11)
    //         0042f74e     CMP        dword ptr [ESP + 0xc],0x1
    //         0042f753     JNZ        LAB_0042f813
    //                              com_loby.cpp:330 (16)
    //         0042f759     MOV        EAX,[L]                                          = 00000000
    //         0042f75e     PUSH       s_LOBBY:_System_Message                          = "LOBBY: System Message"
    //         0042f763     PUSH       EAX=>DAT_fffffff8
    //         0042f764     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //                              com_loby.cpp:335 (26)
    //         0042f769     MOV        this,dword ptr [ESP + 0x18]
    //         0042f76d     ADD        ESP,0x8
    //         0042f770     LEA        EAX,[this->HostHWND + -0x1]
    //         0042f773     CMP        EAX,0x3
    //         0042f776     JA         LAB_0042f7fe
    //                               switchD_0042f77c::switchD
    //         0042f77c     JMP        dword ptr [EAX*0x4 + switchD_0042f77c::switchd   = 0042f7a2
    //                               switchD_0042f77c::caseD_3                                    XREF[2]:     0042f77c(j), 0042f82c(*)  
    //                              com_loby.cpp:338 (22)
    //         0042f783     MOV        this,dword ptr [L]                               = 00000000
    //         0042f789     PUSH       s_!!!_Lobby:_Application_has_been_               = "!!! Lobby: Application has been terminated."
    //         0042f78e     PUSH       this=>DAT_fffffff8
    //         0042f78f     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         0042f794     ADD        ESP,0x8
    //         0042f797     XOR        EAX,EAX
    //                              com_loby.cpp:356 (9)
    //         0042f799     POP        EDI
    //         0042f79a     POP        ESI
    //         0042f79b     ADD        ESP,0x808
    //         0042f7a1     RET
    //                               switchD_0042f77c::caseD_0                                    XREF[2]:     0042f77c(j), 0042f820(*)  
    //                              com_loby.cpp:341 (22)
    //         0042f7a2     MOV        EDX,dword ptr [L]                                = 00000000
    //         0042f7a8     PUSH       s_Lobby_connection_settings_read.                = "Lobby connection settings read."
    //         0042f7ad     PUSH       EDX=>DAT_fffffff8
    //         0042f7ae     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         0042f7b3     ADD        ESP,0x8
    //         0042f7b6     XOR        EAX,EAX
    //                              com_loby.cpp:356 (9)
    //         0042f7b8     POP        EDI
    //         0042f7b9     POP        ESI
    //         0042f7ba     ADD        ESP,0x808
    //         0042f7c0     RET
    //                               switchD_0042f77c::caseD_1                                    XREF[2]:     0042f77c(j), 0042f824(*)  
    //                              com_loby.cpp:344 (21)
    //         0042f7c1     MOV        EAX,[L]                                          = 00000000
    //         0042f7c6     PUSH       s_!!!_Lobby:_Connection_failed.                  = "!!! Lobby: Connection failed."
    //         0042f7cb     PUSH       EAX=>DAT_fffffff8
    //         0042f7cc     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         0042f7d1     ADD        ESP,0x8
    //         0042f7d4     XOR        EAX,EAX
    //                              com_loby.cpp:356 (9)
    //         0042f7d6     POP        EDI
    //         0042f7d7     POP        ESI
    //         0042f7d8     ADD        ESP,0x808
    //         0042f7de     RET
    //                               switchD_0042f77c::caseD_2                                    XREF[2]:     0042f77c(j), 0042f828(*)  
    //                              com_loby.cpp:347 (22)
    //         0042f7df     MOV        this,dword ptr [L]                               = 00000000
    //         0042f7e5     PUSH       s_Lobby:_Connection_successful.                  = "Lobby: Connection successful."
    //         0042f7ea     PUSH       this=>DAT_fffffff8
    //         0042f7eb     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         0042f7f0     ADD        ESP,0x8
    //         0042f7f3     XOR        EAX,EAX
    //                              com_loby.cpp:356 (9)
    //         0042f7f5     POP        EDI
    //         0042f7f6     POP        ESI
    //         0042f7f7     ADD        ESP,0x808
    //         0042f7fd     RET
    //                               LAB_0042f7fe                                                 XREF[1]:     0042f776(j)  
    //                              com_loby.cpp:350 (21)
    //         0042f7fe     MOV        EDX,dword ptr [L]                                = 00000000
    //         0042f804     PUSH       this
    //         0042f805     PUSH       s_!!!_Lobby:_Unknown_message_from_               = "!!! Lobby: Unknown message from lobby. %d"
    //         0042f80a     PUSH       EDX=>DAT_fffffff4
    //         0042f80b     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         0042f810     ADD        ESP,0xc
    //                               LAB_0042f813                                                 XREF[4]:     0042f6df(j), 0042f71f(j), 
    //                                                                                                         0042f72b(j), 0042f753(j)  
    //                              com_loby.cpp:356 (29)
    //         0042f813     POP        EDI
    //         0042f814     XOR        EAX,EAX
    //         0042f816     POP        ESI
    //         0042f817     ADD        ESP,0x808
    //         0042f81d     RET
}

// Offset: 0x0042F81E
undefined FUN_0042f81e() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0042f81e()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0042f81e
    //         0042f81e     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_0042f77c::switchdataD_0042f820                       XREF[1]:     ReceiveZoneMessages:0042f77c(*)  
}

// Offset: 0x0042F830
long SendZoneMessage(RGE_Lobby* this_, char* param_2, ulong param_3, _GUID param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: long __thiscall RGE_Lobby::SendZoneMessage(char *,unsigned long,struct _GUID)                 *
    //                              *********************************************************************************************************
    //                              long __thiscall SendZoneMessage(RGE_Lobby * this, char * param_1, ul
    //              long              EAX:4          <RETURN>
    //              RGE_Lobby *       ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     0042f8cb(R)  
    //              ulong             Stack[0x8]:4   param_2                   XREF[1]:     0042f849(R)  
    //              _GUID             Stack[0xc]:16  param_3                   XREF[1,3]:   0042f8a4(R), 0042f8ae(R), 0042f8b8(R), 0042f8bf(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0042f834(*), 0042f8dd(R)  
    //                               ?SendZoneMessage@RGE_Lobby@@QAEJPADKU_GUID@@@Z               XREF[1]:     SendZoneMessage:0042f009(c)  
    //                               RGE_Lobby::SendZoneMessage
    //                              com_loby.cpp:360 (1)
    //         0042f830     PUSH       this
    //                              com_loby.cpp:363 (11)
    //         0042f831     MOV        AL,byte ptr [ECX + this->lobby_game]
    //         0042f834     MOV        dword ptr [ESP]=>local_4,this
    //         0042f838     TEST       AL,AL
    //         0042f83a     JNZ        LAB_0042f842
    //                              com_loby.cpp:364 (2)
    //         0042f83c     XOR        EAX,EAX
    //                              com_loby.cpp:400 (4)
    //         0042f83e     POP        this
    //         0042f83f     RET        0x18
    //                               LAB_0042f842                                                 XREF[1]:     0042f83a(j)  
    //                              com_loby.cpp:360 (1)
    //         0042f842     PUSH       EDI
    //                              com_loby.cpp:369 (31)
    //         0042f843     MOV        EAX,[L]                                          = 00000000
    //         0042f848     PUSH       ESI
    //         0042f849     MOV        ESI,dword ptr [ESP + param_2]
    //         0042f84d     PUSH       EBP
    //         0042f84e     PUSH       EBX
    //         0042f84f     LEA        EBP,[ESI + 0x30]
    //         0042f852     PUSH       EBP
    //         0042f853     PUSH       ESI
    //         0042f854     PUSH       s_Sending_%d_bytes_to_the_Zone_(To               = "Sending %d bytes to the Zone (Total messag
    //         0042f859     PUSH       EAX
    //         0042f85a     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         0042f85f     ADD        ESP,0x10
    //                              com_loby.cpp:371 (11)
    //         0042f862     PUSH       EBP
    //         0042f863     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0042f868     MOV        EBX,EAX
    //         0042f86a     ADD        ESP,0x4
    //                              com_loby.cpp:375 (6)
    //         0042f86d     MOV        dword ptr [EBX],0x5
    //                              com_loby.cpp:376 (7)
    //         0042f873     MOV        dword ptr [EBX + 0x4],0x0
    //                              com_loby.cpp:377 (9)
    //         0042f87a     MOV        EDX,dword ptr [_GUID_NULL]
    //         0042f880     LEA        this,[EBX + 0x8]
    //                              com_loby.cpp:381 (3)
    //         0042f883     LEA        EDI,[EBX + 0x2c]
    //                              com_loby.cpp:390 (100)
    //         0042f886     PUSH       EBP
    //         0042f887     MOV        dword ptr [this->HostHWND],EDX
    //         0042f889     MOV        EAX,[DAT_00577a2c]
    //         0042f88e     PUSH       EBX
    //         0042f88f     PUSH       0x0
    //         0042f891     MOV        dword ptr [ECX + this->glpDPL],EAX
    //         0042f894     MOV        EDX,dword ptr [DAT_00577a30]
    //         0042f89a     PUSH       0x0
    //         0042f89c     MOV        dword ptr [ECX + this->glpDPL2],EDX
    //         0042f89f     MOV        EAX,[DAT_00577a34]
    //         0042f8a4     MOV        EDX,dword ptr [ESP + param_3.Data1]
    //         0042f8a8     MOV        dword ptr [EBX + 0x28],EBP
    //         0042f8ab     MOV        dword ptr [ECX + this->glpDP],EAX
    //         0042f8ae     MOV        EAX,dword ptr [ESP + param_3.Data2]
    //         0042f8b2     LEA        this,[EBX + 0x18]
    //         0042f8b5     MOV        dword ptr [EBX + 0x18],EDX
    //         0042f8b8     MOV        EDX,dword ptr [ESP + param_3.Data4[0]]
    //         0042f8bc     MOV        dword ptr [ECX + this->glpDPL],EAX
    //         0042f8bf     MOV        EAX,dword ptr [ESP + param_3+0xc]
    //         0042f8c3     MOV        dword ptr [ECX + this->glpDPL2],EDX
    //         0042f8c6     MOV        dword ptr [ECX + this->glpDP],EAX
    //         0042f8c9     MOV        this,ESI
    //         0042f8cb     MOV        ESI,dword ptr [ESP + param_1]
    //         0042f8cf     MOV        EDX,this
    //         0042f8d1     SHR        this,0x2
    //         0042f8d4     MOVSD.REP  ES:EDI,ESI
    //         0042f8d6     MOV        this,EDX
    //         0042f8d8     AND        this,0x3
    //         0042f8db     MOVSB.REP  ES:EDI,ESI
    //         0042f8dd     MOV        EDI,dword ptr [ESP + local_4]
    //         0042f8e1     MOV        EAX,dword ptr [EDI + 0x8]
    //         0042f8e4     PUSH       EAX
    //         0042f8e5     MOV        this,dword ptr [EAX]
    //         0042f8e7     CALL       dword ptr [this->HostHWND + 0x2c]
    //                              com_loby.cpp:392 (11)
    //         0042f8ea     PUSH       EBX
    //         0042f8eb     MOV        ESI,EAX
    //         0042f8ed     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0042f8f2     ADD        ESP,0x4
    //                              com_loby.cpp:394 (4)
    //         0042f8f5     TEST       ESI,ESI
    //         0042f8f7     JNZ        LAB_0042f90d
    //                              com_loby.cpp:395 (20)
    //         0042f8f9     MOV        EDX,dword ptr [L]                                = 00000000
    //         0042f8ff     PUSH       s_SendLobbyMessage_returns_OK                    = "SendLobbyMessage returns OK"
    //         0042f904     PUSH       EDX
    //         0042f905     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         0042f90a     ADD        ESP,0x8
    //                               LAB_0042f90d                                                 XREF[1]:     0042f8f7(j)  
    //                              com_loby.cpp:397 (15)
    //         0042f90d     MOV        this,dword ptr [EDI + 0x18]
    //         0042f910     PUSH       s_Send_Lobby_Msg                                 = "Send Lobby Msg"
    //         0042f915     PUSH       ESI
    //         0042f916     CALL       RGE_Comm_Error::ShowReturn                       void ShowReturn(RGE_Comm_Error * this, long p
    //         0042f91b     POP        EBX
    //                              com_loby.cpp:399 (5)
    //         0042f91c     MOV        EAX,ESI
    //         0042f91e     POP        EBP
    //         0042f91f     POP        ESI
    //         0042f920     POP        EDI
    //                              com_loby.cpp:400 (4)
    //         0042f921     POP        this
    //         0042f922     RET        0x18
}

