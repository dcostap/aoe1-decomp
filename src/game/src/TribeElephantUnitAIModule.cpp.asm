// Auto-generated scaffold unit: TribeElephantUnitAIModule.cpp.asm
#include "../include/common.h"

// Offset: 0x00504190
void* TribeElephantUnitAIModule::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TribeElephantUnitAIModule::`vector deleting destructor'(unsigned... *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TribeElephantUnitAIMo
    //              void *            EAX:4          <RETURN>
    //              TribeElephantU    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00504198(R)  
    //                               ??_GTribeElephantUnitAIModule@@UAEPAXI@Z                     XREF[1]:     005759c8(*)  
    //                               ??_ETribeElephantUnitAIModule@@UAEPAXI@Z
    //                               TribeElephantUnitAIModule::`vector_deleting_destructor'
    //         00504190     PUSH       ESI
    //         00504191     MOV        ESI,this
    //         00504193     CALL       TribeElephantUnitAIModule::~TribeElephantUnitA   void ~TribeElephantUnitAIModule(TribeElephant
    //         00504198     TEST       byte ptr [ESP + param_1],0x1
    //         0050419d     JZ         LAB_005041a8
    //         0050419f     PUSH       ESI
    //         005041a0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         005041a5     ADD        ESP,0x4
    //                               LAB_005041a8                                                 XREF[1]:     0050419d(j)  
    //         005041a8     MOV        EAX,ESI
    //         005041aa     POP        ESI
    //         005041ab     RET        0x4
}

