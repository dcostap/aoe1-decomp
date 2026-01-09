#include "common.h"
#include "com_err.h"

RGE_Comm_Error::RGE_Comm_Error(void* param_1) {
    /* TODO: Stub */
    //                              undefined __thiscall RGE_Comm_Error(RGE_Comm_Error * this, void * pa
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Comm_Error    ECX:4 (auto)   this
    //              void *            Stack[0x4]:4   param_1                   XREF[1]:     00424e42(R)  
    //                               ??0RGE_Comm_Error@@QAE@PAX@Z                                 XREF[2]:     TCommunications_Handler:00425dbf(c
    //                               RGE_Comm_Error::RGE_Comm_Error                                            RGE_Lobby:0042f2cb(c)  
    //                              com_err.cpp:6 (2)
    //         00424e40     MOV        EAX,this
    //                              com_err.cpp:7 (6)
    //         00424e42     MOV        this,dword ptr [ESP + param_1]
    //         00424e46     MOV        dword ptr [EAX],this
    //                              com_err.cpp:8 (7)
    //         00424e48     MOV        dword ptr [EAX + 0x4],0x0
    //                              com_err.cpp:9 (3)
    //         00424e4f     RET        0x4
    //         00424e52     ??         90h
    //         00424e53     NOP
    //         00424e54     NOP
    //         00424e55     NOP
    //         00424e56     NOP
    //         00424e57     NOP
    //         00424e58     NOP
    //         00424e59     NOP
    //         00424e5a     NOP
    //         00424e5b     NOP
    //         00424e5c     NOP
    //         00424e5d     NOP
    //         00424e5e     NOP
    //         00424e5f     NOP
}

void RGE_Comm_Error::NotifyWindowParam(COMMMESSAGES param_1, long param_2) {
    /* TODO: Stub */
    //                              void __thiscall NotifyWindowParam(RGE_Comm_Error * this, COMMMESSAGE
    //              void              <VOID>         <RETURN>
    //              RGE_Comm_Error    ECX:4 (auto)   this
    //              COMMMESSAGES      Stack[0x4]:4   param_1                   XREF[1]:     00424e68(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     00424e63(R)  
    //                               ?NotifyWindowParam@RGE_Comm_Error@@QAEXW4COMMMESSAGES@@J@Z   XREF[8]:     ShowReturn:00424f6b(c), 
    //                               RGE_Comm_Error::NotifyWindowParam                                         ShowReturn:00424f7f(c), 
    //                                                                                                         ShowReturn:004253a8(c), 
    //                                                                                                         ShowReturn:004253d0(c), 
    //                                                                                                         ShowReturn:00425413(c), 
    //                                                                                                         ShowReturn:004254ae(c), 
    //                                                                                                         ShowReturn:004254d6(c), 
    //                                                                                                         ShowReturn:00425500(c)  
    //                              com_err.cpp:12 (26)
    //         00424e60     MOV        EAX,dword ptr [this->HostHWND]
    //         00424e62     PUSH       ESI
    //         00424e63     MOV        ESI,dword ptr [ESP + param_2]
    //         00424e67     PUSH       EDI
    //         00424e68     MOV        EDI,dword ptr [ESP + param_1]
    //         00424e6c     PUSH       ESI
    //         00424e6d     PUSH       EDI
    //         00424e6e     PUSH       0x400
    //         00424e73     PUSH       EAX
    //         00424e74     CALL       dword ptr [->USER32.DLL::PostMessageA]           = 0048afc2
    //                              com_err.cpp:14 (22)
    //         00424e7a     MOV        this,dword ptr [L]                               = 00000000
    //         00424e80     PUSH       ESI
    //         00424e81     PUSH       EDI
    //         00424e82     PUSH       s_COMM:_Send_msg_to_window_WM_USER               = "COMM: Send msg to window WM_USER  Msg=%d  
    //         00424e87     PUSH       this
    //         00424e88     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00424e8d     ADD        ESP,0x10
    //                              com_err.cpp:15 (5)
    //         00424e90     POP        EDI
    //         00424e91     POP        ESI
    //         00424e92     RET        0x8
    //         00424e95     ??         90h
    //         00424e96     NOP
    //         00424e97     NOP
    //         00424e98     NOP
    //         00424e99     NOP
    //         00424e9a     NOP
    //         00424e9b     NOP
    //         00424e9c     NOP
    //         00424e9d     NOP
    //         00424e9e     NOP
    //         00424e9f     NOP
    return;
}

RGE_Comm_Error::~RGE_Comm_Error() {
    /* TODO: Stub */
    //                              void __thiscall ~RGE_Comm_Error(RGE_Comm_Error * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Comm_Error    ECX:4 (auto)   this
    //                               ??1RGE_Comm_Error@@QAE@XZ                                    XREF[2]:     ~TCommunications_Handler:0042633a(
    //                               RGE_Comm_Error::~RGE_Comm_Error                                           ~RGE_Lobby:0042f30d(c)  
    //                              com_err.cpp:19 (1)
    //         00424ea0     RET
    //         00424ea1     ??         90h
    //         00424ea2     NOP
    //         00424ea3     NOP
    //         00424ea4     NOP
    //         00424ea5     NOP
    //         00424ea6     NOP
    //         00424ea7     NOP
    //         00424ea8     NOP
    //         00424ea9     NOP
    //         00424eaa     NOP
    //         00424eab     NOP
    //         00424eac     NOP
    //         00424ead     NOP
    //         00424eae     NOP
    //         00424eaf     NOP
}

void RGE_Comm_Error::ShowReturn(long param_1, char* param_2) {
    /* TODO: Stub */
    //                              void __thiscall ShowReturn(RGE_Comm_Error * this, long param_1, char
    //              void              <VOID>         <RETURN>
    //              RGE_Comm_Error    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     00424eb2(R)  
    //              char *            Stack[0x8]:4   param_2                   XREF[1]:     00424ec1(R)  
    //                               ?ShowReturn@RGE_Comm_Error@@QAEXJPAD@Z                       XREF[38]:    NewCommand:0042657c(c), 
    //                               RGE_Comm_Error::ShowReturn                                                ReceiveGameMessages:00426f67(c), 
    //                                                                                                         GetDPLAYMessages:004272c3(c), 
    //                                                                                                         FastSend:004275ed(c), 
    //                                                                                                         PreprocessMessages:00427bb8(c), 
    //                                                                                                         PreprocessMessages:00427c2a(c), 
    //                                                                                                         SendSharedData:0042892e(c), 
    //                                                                                                         TXChat:00429a19(c), 
    //                                                                                                         SendChecksumMessage:00429d77(c), 
    //                                                                                                         TXAcknowledgeMessage:0042a642(c), 
    //                                                                                                         SendStoredMessages:0042abb3(c), 
    //                                                                                                         TXResendReply:0042af19(c), 
    //                                                                                                         CommOut:0042b638(c), 
    //                                                                                                         CommOut:0042b7e8(c), 
    //                                                                                                         AddSelfPlayer:0042d9f1(c), 
    //                                                                                                         GetMyMultiPlayerCaps:0042ddd1(c), 
    //                                                                                                         DPlayGetSessionDesc:0042e6d4(c), 
    //                                                                                                         CommGetCaps:0042e76b(c), 
    //                                                                                                         CommGetCaps:0042e790(c), 
    //                                                                                                         SendZoneMessage:0042f028(c), [more]
    //                              com_err.cpp:23 (2)
    //         00424eb0     PUSH       EBX
    //         00424eb1     PUSH       ESI
    //                              com_err.cpp:24 (15)
    //         00424eb2     MOV        ESI,dword ptr [ESP + param_1]
    //         00424eb6     PUSH       EDI
    //         00424eb7     TEST       ESI,ESI
    //         00424eb9     MOV        EDI,this
    //         00424ebb     JZ         LAB_00425732
    //                              com_err.cpp:32 (25)
    //         00424ec1     MOV        EBX,dword ptr [ESP + param_2]
    //         00424ec5     MOV        EAX,[L]                                          = 00000000
    //         00424eca     PUSH       EBX
    //         00424ecb     PUSH       ESI
    //         00424ecc     PUSH       s_+++COMM______DP_CALL_FAILED_(Cod               = "+++COMM______DP CALL FAILED_(Code %u)_____
    //         00424ed1     PUSH       EAX
    //         00424ed2     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00424ed7     ADD        ESP,0x10
    //                              com_err.cpp:36 (25)
    //         00424eda     CMP        ESI,0x80004001
    //         00424ee0     MOV        dword ptr [EDI + 0x4],ESI
    //         00424ee3     JG         LAB_00424f27
    //         00424ee5     JZ         LAB_00424f0d
    //         00424ee7     CMP        ESI,0x8000000a
    //         00424eed     JNZ        switchD_00424f48::default
    //                              com_err.cpp:372 (20)
    //         00424ef3     MOV        this,dword ptr [L]                               = 00000000
    //         00424ef9     PUSH       s_COM_Error_pending                              = "COM Error pending"
    //         00424efe     PUSH       this
    //         00424eff     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00424f04     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         00424f07     POP        EDI
    //         00424f08     POP        ESI
    //         00424f09     POP        EBX
    //         00424f0a     RET        0x8
    //                               LAB_00424f0d                                                 XREF[1]:     00424ee5(j)  
    //                              com_err.cpp:304 (20)
    //         00424f0d     MOV        EDX,dword ptr [L]                                = 00000000
    //         00424f13     PUSH       s_!!!_Unsupported.                               = "!!! Unsupported."
    //         00424f18     PUSH       EDX
    //         00424f19     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00424f1e     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         00424f21     POP        EDI
    //         00424f22     POP        ESI
    //         00424f23     POP        EBX
    //         00424f24     RET        0x8
    //                               LAB_00424f27                                                 XREF[1]:     00424ee3(j)  
    //                              com_err.cpp:36 (40)
    //         00424f27     CMP        ESI,0x80040110
    //         00424f2d     JG         LAB_00424feb
    //         00424f33     JZ         LAB_00424fd1
    //         00424f39     LEA        EAX,[ESI + 0x7fffbffe]
    //         00424f3f     CMP        EAX,0x3
    //         00424f42     JA         switchD_00424f48::default
    //                               switchD_00424f48::switchD
    //         00424f48     JMP        dword ptr [EAX*0x4 + switchD_00424f48::switchd   = 00424f76
    //                               switchD_00424f48::caseD_80004005                             XREF[2]:     00424f48(j), 00425744(*)  
    //                              com_err.cpp:139 (19)
    //         00424f4f     MOV        EAX,[L]                                          = 00000000
    //         00424f54     PUSH       s_!!!_GENERIC_(Undefined)_ERROR_                 = "!!! GENERIC (Undefined) ERROR "
    //         00424f59     PUSH       EAX
    //         00424f5a     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00424f5f     ADD        ESP,0x8
    //                              com_err.cpp:140 (14)
    //         00424f62     MOV        this,EDI
    //         00424f64     PUSH       0x0
    //         00424f66     PUSH       0x17ac
    //         00424f6b     CALL       RGE_Comm_Error::NotifyWindowParam                void NotifyWindowParam(RGE_Comm_Error * this,
    //                              com_err.cpp:380 (6)
    //         00424f70     POP        EDI
    //         00424f71     POP        ESI
    //         00424f72     POP        EBX
    //         00424f73     RET        0x8
    //                               switchD_00424f48::caseD_80004002                             XREF[2]:     00424f48(j), 00425738(*)  
    //                              com_err.cpp:204 (14)
    //         00424f76     PUSH       0x0
    //         00424f78     PUSH       0x17ac
    //         00424f7d     MOV        this,EDI
    //         00424f7f     CALL       RGE_Comm_Error::NotifyWindowParam                void NotifyWindowParam(RGE_Comm_Error * this,
    //                              com_err.cpp:205 (20)
    //         00424f84     MOV        this,dword ptr [L]                               = 00000000
    //         00424f8a     PUSH       s_!!!_No_Interface                               = "!!! No Interface"
    //         00424f8f     PUSH       this
    //         00424f90     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00424f95     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         00424f98     POP        EDI
    //         00424f99     POP        ESI
    //         00424f9a     POP        EBX
    //         00424f9b     RET        0x8
    //                               switchD_00424f48::caseD_80004003                             XREF[2]:     00424f48(j), 0042573c(*)  
    //                              com_err.cpp:349 (20)
    //         00424f9e     MOV        EDX,dword ptr [L]                                = 00000000
    //         00424fa4     PUSH       s_COM_Invalid_Pointer                            = "COM Invalid Pointer"
    //         00424fa9     PUSH       EDX
    //         00424faa     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00424faf     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         00424fb2     POP        EDI
    //         00424fb3     POP        ESI
    //         00424fb4     POP        EBX
    //         00424fb5     RET        0x8
    //                               switchD_00424f48::caseD_80004004                             XREF[2]:     00424f48(j), 00425740(*)  
    //                              com_err.cpp:109 (5)
    //         00424fb8     MOV        EAX,[L]                                          = 00000000
    //                              com_err.cpp:357 (14)
    //         00424fbd     PUSH       s_COM_Aborted                                    = "COM Aborted"
    //         00424fc2     PUSH       EAX
    //         00424fc3     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00424fc8     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         00424fcb     POP        EDI
    //         00424fcc     POP        ESI
    //         00424fcd     POP        EBX
    //         00424fce     RET        0x8
    //                               LAB_00424fd1                                                 XREF[1]:     00424f33(j)  
    //                              com_err.cpp:320 (20)
    //         00424fd1     MOV        this,dword ptr [L]                               = 00000000
    //         00424fd7     PUSH       s_!!!_COMM:_CLASS_NO_AGGREGATION.                = "!!! COMM: CLASS NO AGGREGATION."
    //         00424fdc     PUSH       this
    //         00424fdd     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00424fe2     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         00424fe5     POP        EDI
    //         00424fe6     POP        ESI
    //         00424fe7     POP        EBX
    //         00424fe8     RET        0x8
    //                               LAB_00424feb                                                 XREF[1]:     00424f2d(j)  
    //                              com_err.cpp:36 (30)
    //         00424feb     CMP        ESI,0x8007000e
    //         00424ff1     JG         LAB_0042504d
    //         00424ff3     JZ         LAB_00425033
    //         00424ff5     CMP        ESI,0x80070005
    //         00424ffb     JZ         LAB_00425023
    //         00424ffd     CMP        ESI,0x80070006
    //         00425003     JNZ        switchD_00424f48::default
    //                              com_err.cpp:353 (20)
    //         00425009     MOV        EDX,dword ptr [L]                                = 00000000
    //         0042500f     PUSH       s_COM_Invalid_Handle                             = "COM Invalid Handle"
    //         00425014     PUSH       EDX
    //         00425015     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         0042501a     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         0042501d     POP        EDI
    //         0042501e     POP        ESI
    //         0042501f     POP        EBX
    //         00425020     RET        0x8
    //                               LAB_00425023                                                 XREF[1]:     00424ffb(j)  
    //                              com_err.cpp:325 (11)
    //         00425023     MOV        EAX,[L]                                          = 00000000
    //         00425028     PUSH       s_COM_error_Access_Denied                        = "COM error Access Denied"
    //         0042502d     PUSH       EAX
    //                              com_err.cpp:327 (5)
    //         0042502e     JMP        LAB_004254c5
    //                               LAB_00425033                                                 XREF[1]:     00424ff3(j)  
    //                              com_err.cpp:250 (20)
    //         00425033     MOV        this,dword ptr [L]                               = 00000000
    //         00425039     PUSH       s_!!!_Out_Of_Memory                              = "!!! Out Of Memory"
    //         0042503e     PUSH       this
    //         0042503f     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00425044     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         00425047     POP        EDI
    //         00425048     POP        ESI
    //         00425049     POP        EBX
    //         0042504a     RET        0x8
    //                               LAB_0042504d                                                 XREF[1]:     00424ff1(j)  
    //                              com_err.cpp:36 (22)
    //         0042504d     CMP        ESI,0x88770005
    //         00425053     JG         LAB_00425096
    //         00425055     JZ         LAB_0042507d
    //         00425057     CMP        ESI,0x80070057
    //         0042505d     JNZ        switchD_00424f48::default
    //                              com_err.cpp:173 (20)
    //         00425063     MOV        EDX,dword ptr [L]                                = 00000000
    //         00425069     PUSH       s_!!!_Invalid_Params                             = "!!! Invalid Params"
    //         0042506e     PUSH       EDX
    //         0042506f     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00425074     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         00425077     POP        EDI
    //         00425078     POP        ESI
    //         00425079     POP        EBX
    //         0042507a     RET        0x8
    //                               LAB_0042507d                                                 XREF[1]:     00425055(j)  
    //                              com_err.cpp:109 (19)
    //         0042507d     MOV        EAX,[L]                                          = 00000000
    //         00425082     PUSH       s_!!!_Already_Initialized                        = "!!! Already Initialized"
    //         00425087     PUSH       EAX
    //         00425088     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         0042508d     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         00425090     POP        EDI
    //         00425091     POP        ESI
    //         00425092     POP        EBX
    //         00425093     RET        0x8
    //                               LAB_00425096                                                 XREF[1]:     00425053(j)  
    //                              com_err.cpp:36 (22)
    //         00425096     CMP        ESI,0x88770014
    //         0042509c     JG         LAB_004250d7
    //         0042509e     JZ         LAB_004250bd
    //         004250a0     CMP        ESI,0x8877000a
    //         004250a6     JNZ        switchD_00424f48::default
    //                              com_err.cpp:45 (12)
    //         004250ac     MOV        this,dword ptr [L]                               = 00000000
    //         004250b2     PUSH       s_!!!_Access_Denied_-_busy_service               = "!!! Access Denied - busy service or invali
    //         004250b7     PUSH       this
    //                              com_err.cpp:47 (5)
    //         004250b8     JMP        LAB_004254c5
    //                               LAB_004250bd                                                 XREF[1]:     0042509e(j)  
    //                              com_err.cpp:50 (12)
    //         004250bd     MOV        EDX,dword ptr [L]                                = 00000000
    //         004250c3     PUSH       s_!!!_Active_Players_-_command_inv               = "!!! Active Players - command invalid with 
    //         004250c8     PUSH       EDX
    //                              com_err.cpp:109 (8)
    //         004250c9     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         004250ce     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         004250d1     POP        EDI
    //         004250d2     POP        ESI
    //         004250d3     POP        EBX
    //         004250d4     RET        0x8
    //                               LAB_004250d7                                                 XREF[1]:     0042509c(j)  
    //                              com_err.cpp:36 (22)
    //         004250d7     CMP        ESI,0x88770028
    //         004250dd     JG         LAB_00425117
    //         004250df     JZ         LAB_00425106
    //         004250e1     CMP        ESI,0x8877001e
    //         004250e7     JNZ        switchD_00424f48::default
    //                              com_err.cpp:109 (19)
    //         004250ed     MOV        EAX,[L]                                          = 00000000
    //         004250f2     PUSH       s_!!!_Buffer_size_failure_(SMALL)                = "!!! Buffer size failure (SMALL)"
    //         004250f7     PUSH       EAX
    //         004250f8     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         004250fd     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         00425100     POP        EDI
    //         00425101     POP        ESI
    //         00425102     POP        EBX
    //         00425103     RET        0x8
    //                               LAB_00425106                                                 XREF[1]:     004250df(j)  
    //                              com_err.cpp:87 (12)
    //         00425106     MOV        this,dword ptr [L]                               = 00000000
    //         0042510c     PUSH       s_!!!_Can't_Add_Player                           = "!!! Can't Add Player"
    //         00425111     PUSH       this
    //                              com_err.cpp:89 (5)
    //         00425112     JMP        LAB_004253bf
    //                               LAB_00425117                                                 XREF[1]:     004250dd(j)  
    //                              com_err.cpp:36 (22)
    //         00425117     CMP        ESI,0x8877003c
    //         0042511d     JG         LAB_00425160
    //         0042511f     JZ         LAB_00425147
    //         00425121     CMP        ESI,0x88770032
    //         00425127     JNZ        switchD_00424f48::default
    //                              com_err.cpp:92 (12)
    //         0042512d     MOV        EDX,dword ptr [L]                                = 00000000
    //         00425133     PUSH       s_!!!_Can't_Create_Group                         = "!!! Can't Create Group"
    //         00425138     PUSH       EDX
    //                              com_err.cpp:109 (8)
    //         00425139     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         0042513e     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         00425141     POP        EDI
    //         00425142     POP        ESI
    //         00425143     POP        EBX
    //         00425144     RET        0x8
    //                               LAB_00425147                                                 XREF[1]:     0042511f(j)  
    //                              com_err.cpp:109 (19)
    //         00425147     MOV        EAX,[L]                                          = 00000000
    //         0042514c     PUSH       s_!!!_Can't_create_player.                       = "!!! Can't create player."
    //         00425151     PUSH       EAX
    //         00425152     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00425157     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         0042515a     POP        EDI
    //         0042515b     POP        ESI
    //         0042515c     POP        EBX
    //         0042515d     RET        0x8
    //                               LAB_00425160                                                 XREF[1]:     0042511d(j)  
    //                              com_err.cpp:36 (22)
    //         00425160     CMP        ESI,0x88770050
    //         00425166     JG         LAB_004251bd
    //         00425168     JZ         LAB_00425190
    //         0042516a     CMP        ESI,0x88770046
    //         00425170     JNZ        switchD_00424f48::default
    //                              com_err.cpp:105 (12)
    //         00425176     MOV        this,dword ptr [L]                               = 00000000
    //         0042517c     PUSH       s_!!!_Can't_create_session.                      = "!!! Can't create session."
    //         00425181     PUSH       this
    //                              com_err.cpp:109 (8)
    //         00425182     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00425187     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         0042518a     POP        EDI
    //         0042518b     POP        ESI
    //         0042518c     POP        EBX
    //         0042518d     RET        0x8
    //                               LAB_00425190                                                 XREF[1]:     00425168(j)  
    //                              com_err.cpp:121 (25)
    //         00425190     MOV        EDX,dword ptr [L]                                = 00000000
    //         00425196     PUSH       s_!!!_Device_caps_are_not_availabl               = "!!! Device caps are not available."
    //         0042519b     PUSH       EDX
    //         0042519c     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         004251a1     MOV        EAX,[L]                                          = 00000000
    //         004251a6     ADD        ESP,0x8
    //                              com_err.cpp:122 (14)
    //         004251a9     PUSH       s_!!!_ERROR!                                     = "!!! ERROR!"
    //         004251ae     PUSH       EAX
    //         004251af     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         004251b4     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         004251b7     POP        EDI
    //         004251b8     POP        ESI
    //         004251b9     POP        EBX
    //         004251ba     RET        0x8
    //                               LAB_004251bd                                                 XREF[1]:     00425166(j)  
    //                              com_err.cpp:36 (22)
    //         004251bd     CMP        ESI,0x88770078
    //         004251c3     JG         LAB_00425207
    //         004251c5     JZ         LAB_004251ed
    //         004251c7     CMP        ESI,0x8877005a
    //         004251cd     JNZ        switchD_00424f48::default
    //                              com_err.cpp:134 (20)
    //         004251d3     MOV        this,dword ptr [L]                               = 00000000
    //         004251d9     PUSH       s_!!!_Exception_Raised                           = "!!! Exception Raised"
    //         004251de     PUSH       this
    //         004251df     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         004251e4     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         004251e7     POP        EDI
    //         004251e8     POP        ESI
    //         004251e9     POP        EBX
    //         004251ea     RET        0x8
    //                               LAB_004251ed                                                 XREF[1]:     004251c5(j)  
    //                              com_err.cpp:151 (20)
    //         004251ed     MOV        EDX,dword ptr [L]                                = 00000000
    //         004251f3     PUSH       s_!!!_Invalid_Flags                              = "!!! Invalid Flags"
    //         004251f8     PUSH       EDX
    //         004251f9     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         004251fe     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         00425201     POP        EDI
    //         00425202     POP        ESI
    //         00425203     POP        EBX
    //         00425204     RET        0x8
    //                               LAB_00425207                                                 XREF[1]:     004251c3(j)  
    //                              com_err.cpp:36 (22)
    //         00425207     CMP        ESI,0x88770096
    //         0042520d     JG         LAB_00425250
    //         0042520f     JZ         LAB_00425236
    //         00425211     CMP        ESI,0x88770082
    //         00425217     JNZ        switchD_00424f48::default
    //                              com_err.cpp:109 (5)
    //         0042521d     MOV        EAX,[L]                                          = 00000000
    //                              com_err.cpp:169 (14)
    //         00425222     PUSH       s_!!!_Invalid_Object                             = "!!! Invalid Object"
    //         00425227     PUSH       EAX
    //         00425228     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         0042522d     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         00425230     POP        EDI
    //         00425231     POP        ESI
    //         00425232     POP        EBX
    //         00425233     RET        0x8
    //                               LAB_00425236                                                 XREF[1]:     0042520f(j)  
    //                              com_err.cpp:179 (20)
    //         00425236     MOV        this,dword ptr [L]                               = 00000000
    //         0042523c     PUSH       s_!!!_Invalid_Player                             = "!!! Invalid Player"
    //         00425241     PUSH       this
    //         00425242     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00425247     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         0042524a     POP        EDI
    //         0042524b     POP        ESI
    //         0042524c     POP        EBX
    //         0042524d     RET        0x8
    //                               LAB_00425250                                                 XREF[1]:     0042520d(j)  
    //                              com_err.cpp:36 (22)
    //         00425250     CMP        ESI,0x887700a0
    //         00425256     JG         LAB_00425299
    //         00425258     JZ         LAB_00425280
    //         0042525a     CMP        ESI,0x8877009b
    //         00425260     JNZ        switchD_00424f48::default
    //                              com_err.cpp:156 (20)
    //         00425266     MOV        EDX,dword ptr [L]                                = 00000000
    //         0042526c     PUSH       s_!!!_Invalid_Group                              = "!!! Invalid Group"
    //         00425271     PUSH       EDX
    //         00425272     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00425277     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         0042527a     POP        EDI
    //         0042527b     POP        ESI
    //         0042527c     POP        EBX
    //         0042527d     RET        0x8
    //                               LAB_00425280                                                 XREF[1]:     00425258(j)  
    //                              com_err.cpp:109 (5)
    //         00425280     MOV        EAX,[L]                                          = 00000000
    //                              com_err.cpp:194 (14)
    //         00425285     PUSH       s_!!!_Not_able_to_do_multipayer!                 = "!!! Not able to do multipayer!"
    //         0042528a     PUSH       EAX
    //         0042528b     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00425290     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         00425293     POP        EDI
    //         00425294     POP        ESI
    //         00425295     POP        EBX
    //         00425296     RET        0x8
    //                               LAB_00425299                                                 XREF[1]:     00425256(j)  
    //                              com_err.cpp:36 (22)
    //         00425299     CMP        ESI,0x887700be
    //         0042529f     JG         LAB_004252e3
    //         004252a1     JZ         LAB_004252c9
    //         004252a3     CMP        ESI,0x887700aa
    //         004252a9     JNZ        switchD_00424f48::default
    //                              com_err.cpp:199 (20)
    //         004252af     MOV        this,dword ptr [L]                               = 00000000
    //         004252b5     PUSH       s_!!!_No_Connection                              = "!!! No Connection"
    //         004252ba     PUSH       this
    //         004252bb     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         004252c0     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         004252c3     POP        EDI
    //         004252c4     POP        ESI
    //         004252c5     POP        EBX
    //         004252c6     RET        0x8
    //                               LAB_004252c9                                                 XREF[1]:     004252a1(j)  
    //                              com_err.cpp:215 (20)
    //         004252c9     MOV        EDX,dword ptr [L]                                = 00000000
    //         004252cf     PUSH       s_!!!_No_messages                                = "!!! No messages"
    //         004252d4     PUSH       EDX
    //         004252d5     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         004252da     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         004252dd     POP        EDI
    //         004252de     POP        ESI
    //         004252df     POP        EBX
    //         004252e0     RET        0x8
    //                               LAB_004252e3                                                 XREF[1]:     0042529f(j)  
    //                              com_err.cpp:36 (22)
    //         004252e3     CMP        ESI,0x887700d2
    //         004252e9     JG         LAB_0042532c
    //         004252eb     JZ         LAB_00425312
    //         004252ed     CMP        ESI,0x887700c8
    //         004252f3     JNZ        switchD_00424f48::default
    //                              com_err.cpp:109 (5)
    //         004252f9     MOV        EAX,[L]                                          = 00000000
    //                              com_err.cpp:220 (14)
    //         004252fe     PUSH       s_!!!_No_name_server_running!                    = "!!! No name server running!"
    //         00425303     PUSH       EAX
    //         00425304     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00425309     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         0042530c     POP        EDI
    //         0042530d     POP        ESI
    //         0042530e     POP        EBX
    //         0042530f     RET        0x8
    //                               LAB_00425312                                                 XREF[1]:     004252eb(j)  
    //                              com_err.cpp:231 (20)
    //         00425312     MOV        this,dword ptr [L]                               = 00000000
    //         00425318     PUSH       s_!!!_No_players_are_connected!                  = "!!! No players are connected!"
    //         0042531d     PUSH       this
    //         0042531e     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00425323     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         00425326     POP        EDI
    //         00425327     POP        ESI
    //         00425328     POP        EBX
    //         00425329     RET        0x8
    //                               LAB_0042532c                                                 XREF[1]:     004252e9(j)  
    //                              com_err.cpp:36 (22)
    //         0042532c     CMP        ESI,0x887700e6
    //         00425332     JG         LAB_00425375
    //         00425334     JZ         LAB_0042535c
    //         00425336     CMP        ESI,0x887700dc
    //         0042533c     JNZ        switchD_00424f48::default
    //                              com_err.cpp:241 (20)
    //         00425342     MOV        EDX,dword ptr [L]                                = 00000000
    //         00425348     PUSH       s_!!!_No_sessions_are_available                  = "!!! No sessions are available"
    //         0042534d     PUSH       EDX
    //         0042534e     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00425353     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         00425356     POP        EDI
    //         00425357     POP        ESI
    //         00425358     POP        EBX
    //         00425359     RET        0x8
    //                               LAB_0042535c                                                 XREF[1]:     00425334(j)  
    //                              com_err.cpp:109 (5)
    //         0042535c     MOV        EAX,[L]                                          = 00000000
    //                              com_err.cpp:261 (14)
    //         00425361     PUSH       s_!!!_Send_overflow!                             = "!!! Send overflow!"
    //         00425366     PUSH       EAX
    //         00425367     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         0042536c     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         0042536f     POP        EDI
    //         00425370     POP        ESI
    //         00425371     POP        EBX
    //         00425372     RET        0x8
    //                               LAB_00425375                                                 XREF[1]:     00425332(j)  
    //                              com_err.cpp:36 (22)
    //         00425375     CMP        ESI,0x887700fa
    //         0042537b     JG         LAB_004253db
    //         0042537d     JZ         LAB_004253b3
    //         0042537f     CMP        ESI,0x887700f0
    //         00425385     JNZ        switchD_00424f48::default
    //                              com_err.cpp:275 (20)
    //         0042538b     MOV        this,dword ptr [L]                               = 00000000
    //         00425391     PUSH       s_!!!_COMM_TIMEOUT_Rcvd_from_HOST_               = "!!! COMM TIMEOUT Rcvd from HOST connection."
    //         00425396     PUSH       this
    //         00425397     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         0042539c     ADD        ESP,0x8
    //                              com_err.cpp:276 (14)
    //         0042539f     MOV        this,EDI
    //         004253a1     PUSH       0x0
    //         004253a3     PUSH       0x17b9
    //         004253a8     CALL       RGE_Comm_Error::NotifyWindowParam                void NotifyWindowParam(RGE_Comm_Error * this,
    //                              com_err.cpp:380 (6)
    //         004253ad     POP        EDI
    //         004253ae     POP        ESI
    //         004253af     POP        EBX
    //         004253b0     RET        0x8
    //                               LAB_004253b3                                                 XREF[1]:     0042537d(j)  
    //                              com_err.cpp:287 (20)
    //         004253b3     MOV        EDX,dword ptr [L]                                = 00000000
    //         004253b9     PUSH       s_!!!_Communications_/_Session_is_               = "!!! Communications / Session is Unavailable"
    //         004253be     PUSH       EDX
    //                               LAB_004253bf                                                 XREF[1]:     00425112(j)  
    //         004253bf     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         004253c4     ADD        ESP,0x8
    //                              com_err.cpp:288 (14)
    //         004253c7     MOV        this,EDI
    //         004253c9     PUSH       0x0
    //         004253cb     PUSH       0x17ab
    //         004253d0     CALL       RGE_Comm_Error::NotifyWindowParam                void NotifyWindowParam(RGE_Comm_Error * this,
    //                              com_err.cpp:380 (6)
    //         004253d5     POP        EDI
    //         004253d6     POP        ESI
    //         004253d7     POP        EBX
    //         004253d8     RET        0x8
    //                               LAB_004253db                                                 XREF[1]:     0042537b(j)  
    //                              com_err.cpp:36 (22)
    //         004253db     CMP        ESI,0x88770118
    //         004253e1     JG         LAB_00425432
    //         004253e3     JZ         LAB_0042540a
    //         004253e5     CMP        ESI,0x8877010e
    //         004253eb     JNZ        switchD_00424f48::default
    //                              com_err.cpp:109 (19)
    //         004253f1     MOV        EAX,[L]                                          = 00000000
    //         004253f6     PUSH       s_!!!_Busy_Rcvd                                  = "!!! Busy Rcvd"
    //         004253fb     PUSH       EAX
    //         004253fc     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00425401     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         00425404     POP        EDI
    //         00425405     POP        ESI
    //         00425406     POP        EBX
    //         00425407     RET        0x8
    //                               LAB_0042540a                                                 XREF[1]:     004253e3(j)  
    //                              com_err.cpp:312 (14)
    //         0042540a     PUSH       0x0
    //         0042540c     PUSH       0x17ae
    //         00425411     MOV        this,EDI
    //         00425413     CALL       RGE_Comm_Error::NotifyWindowParam                void NotifyWindowParam(RGE_Comm_Error * this,
    //                              com_err.cpp:313 (20)
    //         00425418     MOV        this,dword ptr [L]                               = 00000000
    //         0042541e     PUSH       s_!!!_User_Cancel                                = "!!! User Cancel"
    //         00425423     PUSH       this
    //         00425424     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00425429     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         0042542c     POP        EDI
    //         0042542d     POP        ESI
    //         0042542e     POP        EBX
    //         0042542f     RET        0x8
    //                               LAB_00425432                                                 XREF[1]:     004253e1(j)  
    //                              com_err.cpp:36 (22)
    //         00425432     CMP        ESI,0x8877012c
    //         00425438     JG         LAB_0042547b
    //         0042543a     JZ         LAB_00425462
    //         0042543c     CMP        ESI,0x88770122
    //         00425442     JNZ        switchD_00424f48::default
    //                              com_err.cpp:82 (12)
    //         00425448     MOV        EDX,dword ptr [L]                                = 00000000
    //         0042544e     PUSH       s_!!!_Unable_to_create_server                    = "!!! Unable to create server"
    //         00425453     PUSH       EDX
    //                              com_err.cpp:109 (8)
    //         00425454     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00425459     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         0042545c     POP        EDI
    //         0042545d     POP        ESI
    //         0042545e     POP        EBX
    //         0042545f     RET        0x8
    //                               LAB_00425462                                                 XREF[1]:     0042543a(j)  
    //                              com_err.cpp:109 (5)
    //         00425462     MOV        EAX,[L]                                          = 00000000
    //                              com_err.cpp:255 (14)
    //         00425467     PUSH       s_!!!_Player_Lost_connection.                    = "!!! Player Lost connection."
    //         0042546c     PUSH       EAX
    //         0042546d     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00425472     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         00425475     POP        EDI
    //         00425476     POP        ESI
    //         00425477     POP        EBX
    //         00425478     RET        0x8
    //                               LAB_0042547b                                                 XREF[1]:     00425438(j)  
    //                              com_err.cpp:36 (22)
    //         0042547b     CMP        ESI,0x88770140
    //         00425481     JG         LAB_004254e1
    //         00425483     JZ         LAB_004254b9
    //         00425485     CMP        ESI,0x88770136
    //         0042548b     JNZ        switchD_00424f48::default
    //                              com_err.cpp:266 (20)
    //         00425491     MOV        this,dword ptr [L]                               = 00000000
    //         00425497     PUSH       s_!!!_Lost_connection_to_session.                = "!!! Lost connection to session."
    //         0042549c     PUSH       this
    //         0042549d     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         004254a2     ADD        ESP,0x8
    //                              com_err.cpp:267 (14)
    //         004254a5     MOV        this,EDI
    //         004254a7     PUSH       0x0
    //         004254a9     PUSH       0x17a8
    //         004254ae     CALL       RGE_Comm_Error::NotifyWindowParam                void NotifyWindowParam(RGE_Comm_Error * this,
    //                              com_err.cpp:380 (6)
    //         004254b3     POP        EDI
    //         004254b4     POP        ESI
    //         004254b5     POP        EBX
    //         004254b6     RET        0x8
    //                               LAB_004254b9                                                 XREF[1]:     00425483(j)  
    //                              com_err.cpp:292 (20)
    //         004254b9     MOV        EDX,dword ptr [L]                                = 00000000
    //         004254bf     PUSH       s_!!!_Unknown_application_specifie               = "!!! Unknown application specified"
    //         004254c4     PUSH       EDX
    //                               LAB_004254c5                                                 XREF[2]:     0042502e(j), 004250b8(j)  
    //         004254c5     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         004254ca     ADD        ESP,0x8
    //                              com_err.cpp:293 (14)
    //         004254cd     MOV        this,EDI
    //         004254cf     PUSH       0x0
    //         004254d1     PUSH       0x17ae
    //         004254d6     CALL       RGE_Comm_Error::NotifyWindowParam                void NotifyWindowParam(RGE_Comm_Error * this,
    //                              com_err.cpp:380 (6)
    //         004254db     POP        EDI
    //         004254dc     POP        ESI
    //         004254dd     POP        EBX
    //         004254de     RET        0x8
    //                               LAB_004254e1                                                 XREF[1]:     00425481(j)  
    //                              com_err.cpp:36 (22)
    //         004254e1     CMP        ESI,0x88770154
    //         004254e7     JG         LAB_00425538
    //         004254e9     JZ         LAB_0042551e
    //         004254eb     CMP        ESI,0x8877014a
    //         004254f1     JNZ        switchD_00424f48::default
    //                              com_err.cpp:225 (19)
    //         004254f7     PUSH       0x0
    //         004254f9     PUSH       0x17ab
    //         004254fe     MOV        this,EDI
    //         00425500     CALL       RGE_Comm_Error::NotifyWindowParam                void NotifyWindowParam(RGE_Comm_Error * this,
    //         00425505     MOV        EAX,[L]                                          = 00000000
    //                              com_err.cpp:226 (14)
    //         0042550a     PUSH       s_!!!_The_session_is_in_the_proces               = "!!! The session is in the process of conne
    //         0042550f     PUSH       EAX
    //         00425510     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00425515     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         00425518     POP        EDI
    //         00425519     POP        ESI
    //         0042551a     POP        EBX
    //         0042551b     RET        0x8
    //                               LAB_0042551e                                                 XREF[1]:     004254e9(j)  
    //                              com_err.cpp:186 (20)
    //         0042551e     MOV        this,dword ptr [L]                               = 00000000
    //         00425524     PUSH       s_!!!_The_secure_password_is_inval               = "!!! The secure password is invalid."
    //         00425529     PUSH       this
    //         0042552a     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         0042552f     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         00425532     POP        EDI
    //         00425533     POP        ESI
    //         00425534     POP        EBX
    //         00425535     RET        0x8
    //                               LAB_00425538                                                 XREF[1]:     004254e7(j)  
    //                              com_err.cpp:36 (22)
    //         00425538     CMP        ESI,0x887703e8
    //         0042553e     JG         LAB_00425581
    //         00425540     JZ         LAB_00425568
    //         00425542     CMP        ESI,0x8877015e
    //         00425548     JNZ        switchD_00424f48::default
    //                              com_err.cpp:126 (20)
    //         0042554e     MOV        EDX,dword ptr [L]                                = 00000000
    //         00425554     PUSH       s_!!!_The_session_is_in_the_proces               = "!!! The session is in the process of conne
    //         00425559     PUSH       EDX
    //         0042555a     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         0042555f     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         00425562     POP        EDI
    //         00425563     POP        ESI
    //         00425564     POP        EBX
    //         00425565     RET        0x8
    //                               LAB_00425568                                                 XREF[1]:     00425540(j)  
    //                              com_err.cpp:109 (19)
    //         00425568     MOV        EAX,[L]                                          = 00000000
    //         0042556d     PUSH       s_!!!_Buffer_size_failure_(LARGE)                = "!!! Buffer size failure (LARGE)"
    //         00425572     PUSH       EAX
    //         00425573     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00425578     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         0042557b     POP        EDI
    //         0042557c     POP        ESI
    //         0042557d     POP        EBX
    //         0042557e     RET        0x8
    //                               LAB_00425581                                                 XREF[1]:     0042553e(j)  
    //                              com_err.cpp:36 (22)
    //         00425581     CMP        ESI,0x887703fc
    //         00425587     JG         LAB_004255cb
    //         00425589     JZ         LAB_004255b1
    //         0042558b     CMP        ESI,0x887703f2
    //         00425591     JNZ        switchD_00424f48::default
    //                              com_err.cpp:100 (12)
    //         00425597     MOV        this,dword ptr [L]                               = 00000000
    //         0042559d     PUSH       s_!!!_Can't_start_the_application.               = "!!! Can't start the application."
    //         004255a2     PUSH       this
    //                              com_err.cpp:109 (8)
    //         004255a3     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         004255a8     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         004255ab     POP        EDI
    //         004255ac     POP        ESI
    //         004255ad     POP        EBX
    //         004255ae     RET        0x8
    //                               LAB_004255b1                                                 XREF[1]:     00425589(j)  
    //                              com_err.cpp:58 (12)
    //         004255b1     MOV        EDX,dword ptr [L]                                = 00000000
    //         004255b7     PUSH       s_!!!_Application_has_not_been_sta               = "!!! Application has not been started yet."
    //         004255bc     PUSH       EDX
    //                              com_err.cpp:109 (8)
    //         004255bd     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         004255c2     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         004255c5     POP        EDI
    //         004255c6     POP        ESI
    //         004255c7     POP        EBX
    //         004255c8     RET        0x8
    //                               LAB_004255cb                                                 XREF[1]:     00425587(j)  
    //                              com_err.cpp:36 (22)
    //         004255cb     CMP        ESI,0x8877041a
    //         004255d1     JG         LAB_00425600
    //         004255d3     JZ         LAB_004255e7
    //         004255d5     CMP        ESI,0x88770410
    //         004255db     JNZ        switchD_00424f48::default
    //                              com_err.cpp:380 (6)
    //         004255e1     POP        EDI
    //         004255e2     POP        ESI
    //         004255e3     POP        EBX
    //         004255e4     RET        0x8
    //                               LAB_004255e7                                                 XREF[1]:     004255d3(j)  
    //                              com_err.cpp:109 (5)
    //         004255e7     MOV        EAX,[L]                                          = 00000000
    //                              com_err.cpp:299 (14)
    //         004255ec     PUSH       s_!!!_Unknown_application_specifie               = "!!! Unknown application specified"
    //         004255f1     PUSH       EAX
    //         004255f2     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         004255f7     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         004255fa     POP        EDI
    //         004255fb     POP        ESI
    //         004255fc     POP        EBX
    //         004255fd     RET        0x8
    //                               LAB_00425600                                                 XREF[1]:     004255d1(j)  
    //                              com_err.cpp:36 (22)
    //         00425600     CMP        ESI,0x887707d0
    //         00425606     JG         LAB_0042564a
    //         00425608     JZ         LAB_00425630
    //         0042560a     CMP        ESI,0x8877042e
    //         00425610     JNZ        switchD_00424f48::default
    //                              com_err.cpp:245 (20)
    //         00425616     MOV        this,dword ptr [L]                               = 00000000
    //         0042561c     PUSH       s_!!!_Not_A_Lobby_Session                        = "!!! Not A Lobby Session"
    //         00425621     PUSH       this
    //         00425622     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00425627     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         0042562a     POP        EDI
    //         0042562b     POP        ESI
    //         0042562c     POP        EBX
    //         0042562d     RET        0x8
    //                               LAB_00425630                                                 XREF[1]:     00425608(j)  
    //                              com_err.cpp:63 (12)
    //         00425630     MOV        EDX,dword ptr [L]                                = 00000000
    //         00425636     PUSH       s_!!!_Security_authentify_failed.                = "!!! Security authentify failed."
    //         0042563b     PUSH       EDX
    //                              com_err.cpp:109 (8)
    //         0042563c     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00425641     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         00425644     POP        EDI
    //         00425645     POP        ESI
    //         00425646     POP        EBX
    //         00425647     RET        0x8
    //                               LAB_0042564a                                                 XREF[1]:     00425606(j)  
    //                              com_err.cpp:36 (22)
    //         0042564a     CMP        ESI,0x887707e4
    //         00425650     JG         LAB_00425693
    //         00425652     JZ         LAB_00425679
    //         00425654     CMP        ESI,0x887707da
    //         0042565a     JNZ        switchD_00424f48::default
    //                              com_err.cpp:109 (5)
    //         00425660     MOV        EAX,[L]                                          = 00000000
    //                              com_err.cpp:117 (14)
    //         00425665     PUSH       s_!!!_Can't_load_security_SSPI_pac               = "!!! Can't load security SSPI package."
    //         0042566a     PUSH       EAX
    //         0042566b     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00425670     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         00425673     POP        EDI
    //         00425674     POP        ESI
    //         00425675     POP        EBX
    //         00425676     RET        0x8
    //                               LAB_00425679                                                 XREF[1]:     00425652(j)  
    //                              com_err.cpp:130 (20)
    //         00425679     MOV        this,dword ptr [L]                               = 00000000
    //         0042567f     PUSH       s_!!!_The_encryption_failed.                     = "!!! The encryption failed."
    //         00425684     PUSH       this
    //         00425685     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         0042568a     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         0042568d     POP        EDI
    //         0042568e     POP        ESI
    //         0042568f     POP        EBX
    //         00425690     RET        0x8
    //                               LAB_00425693                                                 XREF[1]:     00425650(j)  
    //                              com_err.cpp:36 (18)
    //         00425693     CMP        ESI,0x887707f8
    //         00425699     JG         LAB_004256d8
    //         0042569b     JZ         LAB_004256bf
    //         0042569d     CMP        ESI,0x887707ee
    //         004256a3     JNZ        switchD_00424f48::default
    //                              com_err.cpp:271 (20)
    //         004256a5     MOV        EDX,dword ptr [L]                                = 00000000
    //         004256ab     PUSH       s_!!!_The_security_sign_failed.                  = "!!! The security sign failed."
    //         004256b0     PUSH       EDX
    //         004256b1     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         004256b6     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         004256b9     POP        EDI
    //         004256ba     POP        ESI
    //         004256bb     POP        EBX
    //         004256bc     RET        0x8
    //                               LAB_004256bf                                                 XREF[1]:     0042569b(j)  
    //                              com_err.cpp:109 (5)
    //         004256bf     MOV        EAX,[L]                                          = 00000000
    //                              com_err.cpp:113 (14)
    //         004256c4     PUSH       s_!!!_Can't_load_security_package.               = "!!! Can't load security package."
    //         004256c9     PUSH       EAX
    //         004256ca     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         004256cf     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         004256d2     POP        EDI
    //         004256d3     POP        ESI
    //         004256d4     POP        EBX
    //         004256d5     RET        0x8
    //                               LAB_004256d8                                                 XREF[1]:     00425699(j)  
    //                              com_err.cpp:36 (16)
    //         004256d8     CMP        ESI,0x8877080c
    //         004256de     JZ         LAB_0042571f
    //         004256e0     CMP        ESI,0x88770820
    //         004256e6     JZ         LAB_00425705
    //                               switchD_00424f48::default                                    XREF[25]:    00424eed(j), 00424f42(j), 
    //                                                                                                         00425003(j), 0042505d(j), 
    //                                                                                                         004250a6(j), 004250e7(j), 
    //                                                                                                         00425127(j), 00425170(j), 
    //                                                                                                         004251cd(j), 00425217(j), 
    //                                                                                                         00425260(j), 004252a9(j), 
    //                                                                                                         004252f3(j), 0042533c(j), 
    //                                                                                                         00425385(j), 004253eb(j), 
    //                                                                                                         00425442(j), 0042548b(j), 
    //                                                                                                         004254f1(j), 00425548(j), [more]
    //                              com_err.cpp:376 (23)
    //         004256e8     MOV        this,dword ptr [L]                               = 00000000
    //         004256ee     PUSH       ESI
    //         004256ef     PUSH       ESI
    //         004256f0     PUSH       EBX
    //         004256f1     PUSH       s_!!!_%s:_Unhandled_DP_ERROR/excep               = "!!! %s: Unhandled DP ERROR/exception in ca
    //         004256f6     PUSH       this
    //         004256f7     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         004256fc     ADD        ESP,0x14
    //                              com_err.cpp:380 (6)
    //         004256ff     POP        EDI
    //         00425700     POP        ESI
    //         00425701     POP        EBX
    //         00425702     RET        0x8
    //                               LAB_00425705                                                 XREF[1]:     004256e6(j)  
    //                              com_err.cpp:190 (20)
    //         00425705     MOV        EDX,dword ptr [L]                                = 00000000
    //         0042570b     PUSH       s_!!!_The_secure_logon_failed.                   = "!!! The secure logon failed."
    //         00425710     PUSH       EDX
    //         00425711     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00425716     ADD        ESP,0x8
    //                              com_err.cpp:380 (6)
    //         00425719     POP        EDI
    //         0042571a     POP        ESI
    //         0042571b     POP        EBX
    //         0042571c     RET        0x8
    //                               LAB_0042571f                                                 XREF[1]:     004256de(j)  
    //                              com_err.cpp:109 (19)
    //         0042571f     MOV        EAX,[L]                                          = 00000000
    //         00425724     PUSH       s_!!!_Can't_load_CAPI                            = "!!! Can't load CAPI"
    //         00425729     PUSH       EAX
    //         0042572a     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         0042572f     ADD        ESP,0x8
    //                               LAB_00425732                                                 XREF[1]:     00424ebb(j)  
    //                              com_err.cpp:380 (22)
    //         00425732     POP        EDI
    //         00425733     POP        ESI
    //         00425734     POP        EBX
    //         00425735     RET        0x8
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_00424f48::switchdataD_00425738                       XREF[1]:     ShowReturn:00424f48(*)  
    //         00425738     addr       switchD_00424f48::caseD_80004002
    //         0042573c     addr       switchD_00424f48::caseD_80004003
    //         00425740     addr       switchD_00424f48::caseD_80004004
    //         00425744     addr       switchD_00424f48::caseD_80004005
    //         00425748     ??         90h
    //         00425749     ??         90h
    //         0042574a     ??         90h
    //         0042574b     ??         90h
    //         0042574c     ??         90h
    //         0042574d     ??         90h
    //         0042574e     ??         90h
    //         0042574f     ??         90h
    return;
}

