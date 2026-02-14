// Auto-generated scaffold unit: TribeFishingShipUnitAIModule.asm
#include "../include/common.h"

// Offset: 0x00506C40
void* TribeFishingShipUnitAIModule::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TribeFishingShipUnitAIModule::`scalar deleting destructor'(unsig... *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TribeFishingShipUnitA
    //              void *            EAX:4          <RETURN>
    //              TribeFishingSh    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00506c48(R)  
    //                               ??_ETribeFishingShipUnitAIModule@@UAEPAXI@Z                  XREF[1]:     005760d0(*)  
    //                               ??_GTribeFishingShipUnitAIModule@@UAEPAXI@Z
    //                               TribeFishingShipUnitAIModule::`scalar_deleting_destructor'
    //         00506c40     PUSH       ESI
    //         00506c41     MOV        ESI,this
    //         00506c43     CALL       TribeFishingShipUnitAIModule::~TribeFishingShi   void ~TribeFishingShipUnitAIModule(TribeFishi
    //         00506c48     TEST       byte ptr [ESP + param_1],0x1
    //         00506c4d     JZ         LAB_00506c58
    //         00506c4f     PUSH       ESI
    //         00506c50     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00506c55     ADD        ESP,0x4
    //                               LAB_00506c58                                                 XREF[1]:     00506c4d(j)  
    //         00506c58     MOV        EAX,ESI
    //         00506c5a     POP        ESI
    //         00506c5b     RET        0x4
}

