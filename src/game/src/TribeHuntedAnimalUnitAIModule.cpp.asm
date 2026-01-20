// Auto-generated scaffold unit: TribeHuntedAnimalUnitAIModule.cpp.asm
#include "../include/common.h"

// Offset: 0x00503D00
void* TribeHuntedAnimalUnitAIModule::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TribeHuntedAnimalUnitAIModule::`scalar deleting destructor'(unsi... *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TribeHuntedAnimalUnit
    //              void *            EAX:4          <RETURN>
    //              TribeHuntedAni    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00503d08(R)  
    //                               ??_ETribeHuntedAnimalUnitAIModule@@UAEPAXI@Z                 XREF[1]:     005757d0(*)  
    //                               ??_GTribeHuntedAnimalUnitAIModule@@UAEPAXI@Z
    //                               TribeHuntedAnimalUnitAIModule::`scalar_deleting_destructor'
    //         00503d00     PUSH       ESI
    //         00503d01     MOV        ESI,this
    //         00503d03     CALL       TribeHuntedAnimalUnitAIModule::~TribeHuntedAni   void ~TribeHuntedAnimalUnitAIModule(TribeHunt
    //         00503d08     TEST       byte ptr [ESP + param_1],0x1
    //         00503d0d     JZ         LAB_00503d18
    //         00503d0f     PUSH       ESI
    //         00503d10     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00503d15     ADD        ESP,0x4
    //                               LAB_00503d18                                                 XREF[1]:     00503d0d(j)  
    //         00503d18     MOV        EAX,ESI
    //         00503d1a     POP        ESI
    //         00503d1b     RET        0x4
}

