#include "common.h"
#include "aitrdmod.h"

TradeAIModule::TradeAIModule(void* param_1, int param_2) {
    /* TODO: Stub */
    //                              undefined __thiscall TradeAIModule(TradeAIModule * this, void * para
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TradeAIModule *   ECX:4 (auto)   this
    //              void *            Stack[0x4]:4   param_1                   XREF[1]:     00412e40(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     00412e48(R)  
    //                               ??0TradeAIModule@@QAE@PAXH@Z                                 XREF[1]:     TribeMainDecisionAIModule:004e48e4
    //                               TradeAIModule::TradeAIModule
    //                              aitrdmod.cpp:23 (46)
    //         00412e40     MOV        EAX,dword ptr [ESP + param_1]
    //         00412e44     PUSH       ESI
    //         00412e45     MOV        ESI,this
    //         00412e47     PUSH       EAX
    //         00412e48     MOV        this,dword ptr [ESP + param_2]
    //         00412e4c     PUSH       this
    //         00412e4d     PUSH       0x3f2
    //         00412e52     PUSH       s_Trade_AI                                       = "Trade AI"
    //         00412e57     MOV        this,ESI
    //         00412e59     CALL       AIModule::AIModule                               undefined AIModule(AIModule * this, char * pa
    //         00412e5e     MOV        dword ptr [ESI + 0xf0],0x0
    //         00412e68     MOV        dword ptr [ESI],TradeAIModule::`vftable'         = 00412e80
    //                              aitrdmod.cpp:24 (6)
    //         00412e6e     MOV        EAX,ESI
    //         00412e70     POP        ESI
    //         00412e71     RET        0x8
    //         00412e74     ??         90h
    //         00412e75     NOP
    //         00412e76     NOP
    //         00412e77     NOP
    //         00412e78     NOP
    //         00412e79     NOP
    //         00412e7a     NOP
    //         00412e7b     NOP
    //         00412e7c     NOP
    //         00412e7d     NOP
    //         00412e7e     NOP
    //         00412e7f     NOP
}

TradeAIModule::TradeAIModule(int param_1, int param_2) {
    /* TODO: Stub */
    //                              undefined __thiscall TradeAIModule(TradeAIModule * this, int param_1
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TradeAIModule *   ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00412ea0(R)  
    //              int               Stack[0x8]:4   param_2
    //                               ??0TradeAIModule@@QAE@HH@Z                                   XREF[1]:     TribeMainDecisionAIModule:004e4c54
    //                               TradeAIModule::TradeAIModule
    //                              aitrdmod.cpp:31 (41)
    //         00412ea0     MOV        EAX,dword ptr [ESP + param_1]
    //         00412ea4     PUSH       ESI
    //         00412ea5     PUSH       0x0
    //         00412ea7     PUSH       EAX
    //         00412ea8     PUSH       0x3f2
    //         00412ead     MOV        ESI,this
    //         00412eaf     PUSH       s_Trade_AI                                       = "Trade AI"
    //         00412eb4     CALL       AIModule::AIModule                               undefined AIModule(AIModule * this, char * pa
    //         00412eb9     MOV        dword ptr [ESI + 0xf0],0x0
    //         00412ec3     MOV        dword ptr [ESI],TradeAIModule::`vftable'         = 00412e80
    //                              aitrdmod.cpp:32 (6)
    //         00412ec9     MOV        EAX,ESI
    //         00412ecb     POP        ESI
    //         00412ecc     RET        0x8
    //         00412ecf     ??         90h
}

TradeAIModule::~TradeAIModule() {
    /* TODO: Stub */
    //                              void __thiscall ~TradeAIModule(TradeAIModule * this)
    //              void              <VOID>         <RETURN>
    //              TradeAIModule *   ECX:4 (auto)   this
    //                               ??1TradeAIModule@@UAE@XZ                                     XREF[3]:     `scalar_deleting_destructor':00412
    //                               TradeAIModule::~TradeAIModule                                             ~TribeMainDecisionAIModule:004e4ef
    //                                                                                                         FUN_00560698:005606a1(c)  
    //                              aitrdmod.cpp:37 (11)
    //         00412ed0     MOV        dword ptr [this->_padding_],TradeAIModule::`vf   = 00412e80
    //         00412ed6     JMP        AIModule::~AIModule                              void ~AIModule(AIModule * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
    //         00412edb     ??         90h
    //         00412edc     NOP
    //         00412edd     NOP
    //         00412ede     NOP
    //         00412edf     NOP
}

void TradeAIModule::setMainDecisionAI(MainDecisionAIModule* param_1) {
    /* TODO: Stub */
    //                              void __thiscall setMainDecisionAI(TradeAIModule * this, MainDecision
    //              void              <VOID>         <RETURN>
    //              TradeAIModule *   ECX:4 (auto)   this
    //              MainDecisionAI    Stack[0x4]:4   param_1                   XREF[1]:     00412ee0(R)  
    //                               ?setMainDecisionAI@TradeAIModule@@QAEXPAVMainDecisionAIModu  XREF[2]:     TribeMainDecisionAIModule:004e49d9
    //                               TradeAIModule::setMainDecisionAI                                          TribeMainDecisionAIModule:004e4d20
    //                              aitrdmod.cpp:43 (10)
    //         00412ee0     MOV        EAX,dword ptr [ESP + param_1]
    //         00412ee4     MOV        dword ptr [ECX + this->md],EAX
    //                              aitrdmod.cpp:45 (3)
    //         00412eea     RET        0x4
    //         00412eed     ??         90h
    //         00412eee     NOP
    //         00412eef     NOP
    return;
}

int TradeAIModule::save(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall save(TradeAIModule * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              TradeAIModule *   ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //                               ?save@TradeAIModule@@UAEHH@Z                                 XREF[1]:     0056ead4(*)  
    //                               TradeAIModule::save
    //                              aitrdmod.cpp:50 (5)
    //         00412ef0     MOV        EAX,0x1
    //                              aitrdmod.cpp:52 (3)
    //         00412ef5     RET        0x4
    //         00412ef8     ??         90h
    //         00412ef9     NOP
    //         00412efa     NOP
    //         00412efb     NOP
    //         00412efc     NOP
    //         00412efd     NOP
    //         00412efe     NOP
    //         00412eff     NOP
    return 0;
}

