// Auto-generated scaffold unit: TribeStrategyAIModule.asm
#include "../include/common.h"

// Offset: 0x004E9240
void* TribeStrategyAIModule::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TribeStrategyAIModule::`vector deleting destructor'(unsigned int)   *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TribeStrategyAIModule
    //              void *            EAX:4          <RETURN>
    //              TribeStrategyA    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004e9248(R)  
    //                               ??_GTribeStrategyAIModule@@UAEPAXI@Z                         XREF[1]:     00575698(*)  
    //                               ??_ETribeStrategyAIModule@@UAEPAXI@Z
    //                               TribeStrategyAIModule::`vector_deleting_destructor'
    //         004e9240     PUSH       ESI
    //         004e9241     MOV        ESI,this
    //         004e9243     CALL       TribeStrategyAIModule::~TribeStrategyAIModule    void ~TribeStrategyAIModule(TribeStrategyAIMo
    //         004e9248     TEST       byte ptr [ESP + param_1],0x1
    //         004e924d     JZ         LAB_004e9258
    //         004e924f     PUSH       ESI
    //         004e9250     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004e9255     ADD        ESP,0x4
    //                               LAB_004e9258                                                 XREF[1]:     004e924d(j)  
    //         004e9258     MOV        EAX,ESI
    //         004e925a     POP        ESI
    //         004e925b     RET        0x4
}

