#include "common.h"
#include "aitacmod.h"

TacticalAIModule::TacticalAIModule(void* param_1, int param_2) {
    /* TODO: Stub */
    //                              undefined __thiscall TacticalAIModule(TacticalAIModule * this, void 
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TacticalAIModu    ECX:4 (auto)   this
    //              void *            Stack[0x4]:4   param_1                   XREF[1]:     00412b50(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     00412b58(R)  
    //                               ??0TacticalAIModule@@QAE@PAXH@Z                              XREF[2]:     TribeTacticalAIModule:004ed1ec(c), 
    //                               TacticalAIModule::TacticalAIModule                                        TribeTacticalAIModule:004ed51a(c)  
    //                              aitacmod.cpp:24 (36)
    //         00412b50     MOV        EAX,dword ptr [ESP + param_1]
    //         00412b54     PUSH       ESI
    //         00412b55     MOV        ESI,this
    //         00412b57     PUSH       EAX
    //         00412b58     MOV        this,dword ptr [ESP + param_2]
    //         00412b5c     PUSH       this
    //         00412b5d     PUSH       0x3f1
    //         00412b62     PUSH       s_TacAI                                          = "TacAI"
    //         00412b67     MOV        this,ESI
    //         00412b69     CALL       AIModule::AIModule                               undefined AIModule(AIModule * this, char * pa
    //         00412b6e     MOV        dword ptr [ESI],TacticalAIModule::`vftable'      = 00412b80
    //                              aitacmod.cpp:26 (6)
    //         00412b74     MOV        EAX,ESI
    //         00412b76     POP        ESI
    //         00412b77     RET        0x8
    //         00412b7a     ??         90h
    //         00412b7b     NOP
    //         00412b7c     NOP
    //         00412b7d     NOP
    //         00412b7e     NOP
    //         00412b7f     NOP
}

TacticalAIModule::~TacticalAIModule() {
    /* TODO: Stub */
    //                              void __thiscall ~TacticalAIModule(TacticalAIModule * this)
    //              void              <VOID>         <RETURN>
    //              TacticalAIModu    ECX:4 (auto)   this
    //                               ??1TacticalAIModule@@UAE@XZ                                  XREF[2]:     `vector_deleting_destructor':00412
    //                               TacticalAIModule::~TacticalAIModule                                       ~TribeTacticalAIModule:004eee1e(c)
    //                              aitacmod.cpp:31 (11)
    //         00412ba0     MOV        dword ptr [this->field0_0x0],TacticalAIModule:   = 00412b80
    //         00412ba6     JMP        AIModule::~AIModule                              void ~AIModule(AIModule * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
    //         00412bab     ??         90h
    //         00412bac     NOP
    //         00412bad     NOP
    //         00412bae     NOP
    //         00412baf     NOP
}

