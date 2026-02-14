// Auto-generated scaffold unit: EmotionalAIModule.asm
#include "../include/common.h"

// Offset: 0x0040C900
void* EmotionalAIModule::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall EmotionalAIModule::`vector deleting destructor'(unsigned int)       *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(EmotionalAIModule * t
    //              void *            EAX:4          <RETURN>
    //              EmotionalAIMod    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0040c908(R)  
    //                               ??_GEmotionalAIModule@@UAEPAXI@Z                             XREF[1]:     0056e858(*)  
    //                               ??_EEmotionalAIModule@@UAEPAXI@Z
    //                               EmotionalAIModule::`vector_deleting_destructor'
    //         0040c900     PUSH       ESI
    //         0040c901     MOV        ESI,this
    //         0040c903     CALL       EmotionalAIModule::~EmotionalAIModule            void ~EmotionalAIModule(EmotionalAIModule * t
    //         0040c908     TEST       byte ptr [ESP + param_1],0x1
    //         0040c90d     JZ         LAB_0040c918
    //         0040c90f     PUSH       ESI
    //         0040c910     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0040c915     ADD        ESP,0x4
    //                               LAB_0040c918                                                 XREF[1]:     0040c90d(j)  
    //         0040c918     MOV        EAX,ESI
    //         0040c91a     POP        ESI
    //         0040c91b     RET        0x4
}

