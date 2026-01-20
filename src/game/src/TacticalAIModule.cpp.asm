// Auto-generated scaffold unit: TacticalAIModule.cpp.asm
#include "../include/common.h"

// Offset: 0x00412B80
void* TacticalAIModule::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TacticalAIModule::`vector deleting destructor'(unsigned int)        *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TacticalAIModule * th
    //              void *            EAX:4          <RETURN>
    //              TacticalAIModu    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00412b88(R)  
    //                               ??_GTacticalAIModule@@UAEPAXI@Z                              XREF[1]:     0056ea58(*)  
    //                               ??_ETacticalAIModule@@UAEPAXI@Z
    //                               TacticalAIModule::`vector_deleting_destructor'
    //         00412b80     PUSH       ESI
    //         00412b81     MOV        ESI,this
    //         00412b83     CALL       TacticalAIModule::~TacticalAIModule              void ~TacticalAIModule(TacticalAIModule * this)
    //         00412b88     TEST       byte ptr [ESP + param_1],0x1
    //         00412b8d     JZ         LAB_00412b98
    //         00412b8f     PUSH       ESI
    //         00412b90     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00412b95     ADD        ESP,0x4
    //                               LAB_00412b98                                                 XREF[1]:     00412b8d(j)  
    //         00412b98     MOV        EAX,ESI
    //         00412b9a     POP        ESI
    //         00412b9b     RET        0x4
}

