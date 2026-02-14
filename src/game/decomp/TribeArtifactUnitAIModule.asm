// Auto-generated scaffold unit: TribeArtifactUnitAIModule.asm
#include "../include/common.h"

// Offset: 0x00507A00
void* TribeArtifactUnitAIModule::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TribeArtifactUnitAIModule::`vector deleting destructor'(unsigned... *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TribeArtifactUnitAIMo
    //              void *            EAX:4          <RETURN>
    //              TribeArtifactU    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00507a08(R)  
    //                               ??_GTribeArtifactUnitAIModule@@UAEPAXI@Z                     XREF[1]:     00576290(*)  
    //                               ??_ETribeArtifactUnitAIModule@@UAEPAXI@Z
    //                               TribeArtifactUnitAIModule::`vector_deleting_destructor'
    //         00507a00     PUSH       ESI
    //         00507a01     MOV        ESI,this
    //         00507a03     CALL       TribeArtifactUnitAIModule::~TribeArtifactUnitA   void ~TribeArtifactUnitAIModule(TribeArtifact
    //         00507a08     TEST       byte ptr [ESP + param_1],0x1
    //         00507a0d     JZ         LAB_00507a18
    //         00507a0f     PUSH       ESI
    //         00507a10     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00507a15     ADD        ESP,0x4
    //                               LAB_00507a18                                                 XREF[1]:     00507a0d(j)  
    //         00507a18     MOV        EAX,ESI
    //         00507a1a     POP        ESI
    //         00507a1b     RET        0x4
}

