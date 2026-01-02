#include "../common.h"
#include "aistrmod.h"

StrategyAIModule::StrategyAIModule(void* param_1, int param_2) {
    /* TODO: Stub */
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
//         00412b1a     ??         90h
//         00412b1b     NOP
//         00412b1c     NOP
//         00412b1d     NOP
//         00412b1e     NOP
//         00412b1f     NOP
}

StrategyAIModule::~StrategyAIModule() {
    /* TODO: Stub */
//                              void __thiscall ~StrategyAIModule(StrategyAIModule * this)
//              void              <VOID>         <RETURN>
//              StrategyAIModu    ECX:4 (auto)   this
//                               ??1StrategyAIModule@@UAE@XZ                                  XREF[2]:     `vector_deleting_destructor':00412
//                               StrategyAIModule::~StrategyAIModule                                       ~TribeStrategyAIModule:004e9802(c)
//                              aistrmod.cpp:29 (11)
//         00412b40     MOV        dword ptr [this->field0_0x0],StrategyAIModule:   = 00412b20
//         00412b46     JMP        AIModule::~AIModule                              void ~AIModule(AIModule * this)
//                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
//         00412b4b     ??         90h
//         00412b4c     NOP
//         00412b4d     NOP
//         00412b4e     NOP
//         00412b4f     NOP
}

