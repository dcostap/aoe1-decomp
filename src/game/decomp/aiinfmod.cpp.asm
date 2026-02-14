// Auto-generated scaffold unit: aiinfmod.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/aiinfmod.cpp
#include "../include/common.h"

// Offset: 0x0040CD90
undefined InformationAIModule(InformationAIModule* this_, void* param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall InformationAIModule::InformationAIModule(void *,int)                               *
    //                              *********************************************************************************************************
    //                              undefined __thiscall InformationAIModule(InformationAIModule * this,
    //              undefined         <UNASSIGNED>   <RETURN>
    //              InformationAIM    ECX:4 (auto)   this
    //              void *            Stack[0x4]:4   param_1                   XREF[1]:     0040cd90(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0040cd98(R)  
    //                               ??0InformationAIModule@@QAE@PAXH@Z                           XREF[2]:     TribeInformationAIModule:004d6bdc(
    //                               InformationAIModule::InformationAIModule                                  TribeInformationAIModule:004d709a(
    //                              aiinfmod.cpp:22 (36)
    //         0040cd90     MOV        EAX,dword ptr [ESP + param_1]
    //         0040cd94     PUSH       ESI
    //         0040cd95     MOV        ESI,this
    //         0040cd97     PUSH       EAX
    //         0040cd98     MOV        this,dword ptr [ESP + param_2]
    //         0040cd9c     PUSH       this
    //         0040cd9d     PUSH       0x3ed
    //         0040cda2     PUSH       s_InfAI                                          = "InfAI"
    //         0040cda7     MOV        this,ESI
    //         0040cda9     CALL       AIModule::AIModule                               undefined AIModule(AIModule * this, char * pa
    //         0040cdae     MOV        dword ptr [ESI],InformationAIModule::`vftable'   = 0040cdc0
    //                              aiinfmod.cpp:24 (6)
    //         0040cdb4     MOV        EAX,ESI
    //         0040cdb6     POP        ESI
    //         0040cdb7     RET        0x8
}

// Offset: 0x0040CDE0
void InformationAIModule(InformationAIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall InformationAIModule::~InformationAIModule(void)                            *
    //                              *********************************************************************************************************
    //                              void __thiscall ~InformationAIModule(InformationAIModule * this)
    //              void              <VOID>         <RETURN>
    //              InformationAIM    ECX:4 (auto)   this
    //                               ??1InformationAIModule@@UAE@XZ                               XREF[2]:     `vector_deleting_destructor':0040c
    //                               InformationAIModule::~InformationAIModule                                 ~TribeInformationAIModule:004d8258
    //                              aiinfmod.cpp:29 (11)
    //         0040cde0     MOV        dword ptr [this->field0_0x0],InformationAIModu   = 0040cdc0
    //         0040cde6     JMP        AIModule::~AIModule                              void ~AIModule(AIModule * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

