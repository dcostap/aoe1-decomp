// Auto-generated scaffold unit: TribePreditorUnitAIModule.cpp.asm
#include "../include/common.h"

// Offset: 0x00504070
void* TribePreditorUnitAIModule::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TribePreditorUnitAIModule::`vector deleting destructor'(unsigned... *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TribePreditorUnitAIMo
    //              void *            EAX:4          <RETURN>
    //              TribePreditorU    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00504078(R)  
    //                               ??_GTribePreditorUnitAIModule@@UAEPAXI@Z                     XREF[1]:     005758e8(*)  
    //                               ??_ETribePreditorUnitAIModule@@UAEPAXI@Z
    //                               TribePreditorUnitAIModule::`vector_deleting_destructor'
    //         00504070     PUSH       ESI
    //         00504071     MOV        ESI,this
    //         00504073     CALL       TribePreditorUnitAIModule::~TribePreditorUnitA   void ~TribePreditorUnitAIModule(TribePreditor
    //         00504078     TEST       byte ptr [ESP + param_1],0x1
    //         0050407d     JZ         LAB_00504088
    //         0050407f     PUSH       ESI
    //         00504080     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00504085     ADD        ESP,0x4
    //                               LAB_00504088                                                 XREF[1]:     0050407d(j)  
    //         00504088     MOV        EAX,ESI
    //         0050408a     POP        ESI
    //         0050408b     RET        0x4
}

