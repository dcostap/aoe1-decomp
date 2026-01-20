// Auto-generated scaffold unit: aitrdmod.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/aitrdmod.cpp
#include "../include/common.h"

// Offset: 0x00412E40
undefined TradeAIModule(TradeAIModule* this_, void* param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TradeAIModule::TradeAIModule(void *,int)                                           *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00412EA0
undefined TradeAIModule(TradeAIModule* this_, int param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TradeAIModule::TradeAIModule(int,int)                                              *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00412ED0
void TradeAIModule(TradeAIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall TradeAIModule::~TradeAIModule(void)                                        *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00412EE0
void setMainDecisionAI(TradeAIModule* this_, MainDecisionAIModule* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TradeAIModule::setMainDecisionAI(class MainDecisionAIModule *)                *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00412EF0
int TradeAIModule::save(int param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual int __thiscall TradeAIModule::save(int)                                               *
    //                              *********************************************************************************************************
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
}

