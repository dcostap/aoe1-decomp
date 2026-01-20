// Auto-generated scaffold unit: TribeTacticalAIModule.cpp.asm
#include "../include/common.h"

// Offset: 0x004ED4D0
void* TribeTacticalAIModule::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TribeTacticalAIModule::`scalar deleting destructor'(unsigned int)   *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TribeTacticalAIModule
    //              void *            EAX:4          <RETURN>
    //              TribeTacticalA    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004ed4d8(R)  
    //                               ??_ETribeTacticalAIModule@@UAEPAXI@Z                         XREF[1]:     00575788(*)  
    //                               ??_GTribeTacticalAIModule@@UAEPAXI@Z
    //                               TribeTacticalAIModule::`scalar_deleting_destructor'
    //         004ed4d0     PUSH       ESI
    //         004ed4d1     MOV        ESI,this
    //         004ed4d3     CALL       TribeTacticalAIModule::~TribeTacticalAIModule    void ~TribeTacticalAIModule(TribeTacticalAIMo
    //         004ed4d8     TEST       byte ptr [ESP + param_1],0x1
    //         004ed4dd     JZ         LAB_004ed4e8
    //         004ed4df     PUSH       ESI
    //         004ed4e0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004ed4e5     ADD        ESP,0x4
    //                               LAB_004ed4e8                                                 XREF[1]:     004ed4dd(j)  
    //         004ed4e8     MOV        EAX,ESI
    //         004ed4ea     POP        ESI
    //         004ed4eb     RET        0x4
}

