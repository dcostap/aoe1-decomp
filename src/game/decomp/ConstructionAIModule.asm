// Auto-generated scaffold unit: ConstructionAIModule.asm
#include "../include/common.h"

// Offset: 0x0040AB90
void* ConstructionAIModule::scalar_deleting_destructor(uint param_1) const {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall ConstructionAIModule::`scalar deleting destructor'(unsigned int)    *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(ConstructionAIModule 
    //              void *            EAX:4          <RETURN>
    //              ConstructionAI    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0040ab98(R)  
    //                               ??_EConstructionAIModule@@UAEPAXI@Z                          XREF[1]:     0056e7a0(*)  
    //                               ??_GConstructionAIModule@@UAEPAXI@Z
    //                               ConstructionAIModule::`scalar_deleting_destructor'
    //         0040ab90     PUSH       ESI
    //         0040ab91     MOV        ESI,this
    //         0040ab93     CALL       ConstructionAIModule::~ConstructionAIModule      void ~ConstructionAIModule(ConstructionAIModu
    //         0040ab98     TEST       byte ptr [ESP + param_1],0x1
    //         0040ab9d     JZ         LAB_0040aba8
    //         0040ab9f     PUSH       ESI
    //         0040aba0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0040aba5     ADD        ESP,0x4
    //                               LAB_0040aba8                                                 XREF[1]:     0040ab9d(j)  
    //         0040aba8     MOV        EAX,ESI
    //         0040abaa     POP        ESI
    //         0040abab     RET        0x4
}

