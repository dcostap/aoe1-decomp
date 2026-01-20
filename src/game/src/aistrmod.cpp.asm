// Auto-generated scaffold unit: aistrmod.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/aistrmod.cpp
#include "../include/common.h"

// Offset: 0x00412AF0
undefined StrategyAIModule(StrategyAIModule* this_, void* param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall StrategyAIModule::StrategyAIModule(void *,int)                                     *
    //                              *********************************************************************************************************
    //                              undefined __thiscall StrategyAIModule(StrategyAIModule * this, void 
    //              undefined         <UNASSIGNED>   <RETURN>
    //              StrategyAIModu    ECX:4 (auto)   this
    //              void *            Stack[0x4]:4   param_1                   XREF[1]:     00412af0(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     00412af8(R)  
    //                               ??0StrategyAIModule@@QAE@PAXH@Z                              XREF[2]:     TribeStrategyAIModule:004e912c(c), 
    //                               StrategyAIModule::StrategyAIModule                                        TribeStrategyAIModule:004e928a(c)  
    //                              aistrmod.cpp:22 (36)
    //         00412af0     MOV        EAX,dword ptr [ESP + param_1]
    //         00412af4     PUSH       ESI
    //         00412af5     MOV        ESI,this
    //         00412af7     PUSH       EAX
    //         00412af8     MOV        this,dword ptr [ESP + param_2]
    //         00412afc     PUSH       this
    //         00412afd     PUSH       0x3f0
    //         00412b02     PUSH       s_Strategy_AI                                    = "Strategy AI"
    //         00412b07     MOV        this,ESI
    //         00412b09     CALL       AIModule::AIModule                               undefined AIModule(AIModule * this, char * pa
    //         00412b0e     MOV        dword ptr [ESI],StrategyAIModule::`vftable'      = 00412b20
    //                              aistrmod.cpp:24 (6)
    //         00412b14     MOV        EAX,ESI
    //         00412b16     POP        ESI
    //         00412b17     RET        0x8
}

// Offset: 0x00412B40
void StrategyAIModule(StrategyAIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall StrategyAIModule::~StrategyAIModule(void)                                  *
    //                              *********************************************************************************************************
    //                              void __thiscall ~StrategyAIModule(StrategyAIModule * this)
    //              void              <VOID>         <RETURN>
    //              StrategyAIModu    ECX:4 (auto)   this
    //                               ??1StrategyAIModule@@UAE@XZ                                  XREF[2]:     `vector_deleting_destructor':00412
    //                               StrategyAIModule::~StrategyAIModule                                       ~TribeStrategyAIModule:004e9802(c)
    //                              aistrmod.cpp:29 (11)
    //         00412b40     MOV        dword ptr [this->field0_0x0],StrategyAIModule:   = 00412b20
    //         00412b46     JMP        AIModule::~AIModule                              void ~AIModule(AIModule * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

