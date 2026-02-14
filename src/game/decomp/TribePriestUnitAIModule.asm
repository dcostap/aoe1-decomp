// Auto-generated scaffold unit: TribePriestUnitAIModule.asm
#include "../include/common.h"

// Offset: 0x00505970
void* TribePriestUnitAIModule::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TribePriestUnitAIModule::`vector deleting destructor'(unsigned int) *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TribePriestUnitAIModu
    //              void *            EAX:4          <RETURN>
    //              TribePriestUni    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00505978(R)  
    //                               ??_GTribePriestUnitAIModule@@UAEPAXI@Z                       XREF[1]:     00575e28(*)  
    //                               ??_ETribePriestUnitAIModule@@UAEPAXI@Z
    //                               TribePriestUnitAIModule::`vector_deleting_destructor'
    //         00505970     PUSH       ESI
    //         00505971     MOV        ESI,this
    //         00505973     CALL       TribePriestUnitAIModule::~TribePriestUnitAIMod   void ~TribePriestUnitAIModule(TribePriestUnit
    //         00505978     TEST       byte ptr [ESP + param_1],0x1
    //         0050597d     JZ         LAB_00505988
    //         0050597f     PUSH       ESI
    //         00505980     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00505985     ADD        ESP,0x4
    //                               LAB_00505988                                                 XREF[1]:     0050597d(j)  
    //         00505988     MOV        EAX,ESI
    //         0050598a     POP        ESI
    //         0050598b     RET        0x4
}

