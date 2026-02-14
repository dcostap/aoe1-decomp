// Auto-generated scaffold unit: TribeTowerUnitAIModule.asm
#include "../include/common.h"

// Offset: 0x005080E0
void* TribeTowerUnitAIModule::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TribeTowerUnitAIModule::`scalar deleting destructor'(unsigned int)  *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TribeTowerUnitAIModul
    //              void *            EAX:4          <RETURN>
    //              TribeTowerUnit    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     005080e8(R)  
    //                               ??_ETribeTowerUnitAIModule@@UAEPAXI@Z                        XREF[1]:     00576370(*)  
    //                               ??_GTribeTowerUnitAIModule@@UAEPAXI@Z
    //                               TribeTowerUnitAIModule::`scalar_deleting_destructor'
    //         005080e0     PUSH       ESI
    //         005080e1     MOV        ESI,this
    //         005080e3     CALL       TribeTowerUnitAIModule::~TribeTowerUnitAIModule  void ~TribeTowerUnitAIModule(TribeTowerUnitAI
    //         005080e8     TEST       byte ptr [ESP + param_1],0x1
    //         005080ed     JZ         LAB_005080f8
    //         005080ef     PUSH       ESI
    //         005080f0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         005080f5     ADD        ESP,0x4
    //                               LAB_005080f8                                                 XREF[1]:     005080ed(j)  
    //         005080f8     MOV        EAX,ESI
    //         005080fa     POP        ESI
    //         005080fb     RET        0x4
}

