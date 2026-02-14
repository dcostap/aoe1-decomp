// Auto-generated scaffold unit: TribeMainDecisionAIModule.asm
#include "../include/common.h"

// Offset: 0x004E4B60
void* TribeMainDecisionAIModule::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TribeMainDecisionAIModule::`scalar deleting destructor'(unsigned... *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TribeMainDecisionAIMo
    //              void *            EAX:4          <RETURN>
    //              TribeMainDecis    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004e4b68(R)  
    //                               ??_ETribeMainDecisionAIModule@@UAEPAXI@Z                     XREF[1]:     005755c8(*)  
    //                               ??_GTribeMainDecisionAIModule@@UAEPAXI@Z
    //                               TribeMainDecisionAIModule::`scalar_deleting_destructor'
    //         004e4b60     PUSH       ESI
    //         004e4b61     MOV        ESI,this
    //         004e4b63     CALL       TribeMainDecisionAIModule::~TribeMainDecisionA   void ~TribeMainDecisionAIModule(TribeMainDeci
    //         004e4b68     TEST       byte ptr [ESP + param_1],0x1
    //         004e4b6d     JZ         LAB_004e4b78
    //         004e4b6f     PUSH       ESI
    //         004e4b70     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004e4b75     ADD        ESP,0x4
    //                               LAB_004e4b78                                                 XREF[1]:     004e4b6d(j)  
    //         004e4b78     MOV        EAX,ESI
    //         004e4b7a     POP        ESI
    //         004e4b7b     RET        0x4
}

