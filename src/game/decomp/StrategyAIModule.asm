// Auto-generated scaffold unit: StrategyAIModule.asm
#include "../include/common.h"

// Offset: 0x00412B20
void* StrategyAIModule::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall StrategyAIModule::`vector deleting destructor'(unsigned int)        *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(StrategyAIModule * th
    //              void *            EAX:4          <RETURN>
    //              StrategyAIModu    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00412b28(R)  
    //                               ??_GStrategyAIModule@@UAEPAXI@Z                              XREF[1]:     0056ea18(*)  
    //                               ??_EStrategyAIModule@@UAEPAXI@Z
    //                               StrategyAIModule::`vector_deleting_destructor'
    //         00412b20     PUSH       ESI
    //         00412b21     MOV        ESI,this
    //         00412b23     CALL       StrategyAIModule::~StrategyAIModule              void ~StrategyAIModule(StrategyAIModule * this)
    //         00412b28     TEST       byte ptr [ESP + param_1],0x1
    //         00412b2d     JZ         LAB_00412b38
    //         00412b2f     PUSH       ESI
    //         00412b30     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00412b35     ADD        ESP,0x4
    //                               LAB_00412b38                                                 XREF[1]:     00412b2d(j)  
    //         00412b38     MOV        EAX,ESI
    //         00412b3a     POP        ESI
    //         00412b3b     RET        0x4
}

