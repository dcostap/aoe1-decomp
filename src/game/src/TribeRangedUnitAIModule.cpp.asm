// Auto-generated scaffold unit: TribeRangedUnitAIModule.cpp.asm
#include "../include/common.h"

// Offset: 0x00504720
void* TribeRangedUnitAIModule::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TribeRangedUnitAIModule::`vector deleting destructor'(unsigned int) *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TribeRangedUnitAIModu
    //              void *            EAX:4          <RETURN>
    //              TribeRangedUni    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00504728(R)  
    //                               ??_GTribeRangedUnitAIModule@@UAEPAXI@Z                       XREF[1]:     00575b88(*)  
    //                               ??_ETribeRangedUnitAIModule@@UAEPAXI@Z
    //                               TribeRangedUnitAIModule::`vector_deleting_destructor'
    //         00504720     PUSH       ESI
    //         00504721     MOV        ESI,this
    //         00504723     CALL       TribeRangedUnitAIModule::~TribeRangedUnitAIMod   void ~TribeRangedUnitAIModule(TribeRangedUnit
    //         00504728     TEST       byte ptr [ESP + param_1],0x1
    //         0050472d     JZ         LAB_00504738
    //         0050472f     PUSH       ESI
    //         00504730     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00504735     ADD        ESP,0x4
    //                               LAB_00504738                                                 XREF[1]:     0050472d(j)  
    //         00504738     MOV        EAX,ESI
    //         0050473a     POP        ESI
    //         0050473b     RET        0x4
}

