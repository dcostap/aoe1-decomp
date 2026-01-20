// Auto-generated scaffold unit: MainDecisionAIModule.cpp.asm
#include "../include/common.h"

// Offset: 0x0040CE70
void* MainDecisionAIModule::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall MainDecisionAIModule::`vector deleting destructor'(unsigned int)    *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(MainDecisionAIModule 
    //              void *            EAX:4          <RETURN>
    //              MainDecisionAI    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0040ce78(R)  
    //                               ??_GMainDecisionAIModule@@UAEPAXI@Z                          XREF[1]:     0056e8d8(*)  
    //                               ??_EMainDecisionAIModule@@UAEPAXI@Z
    //                               MainDecisionAIModule::`vector_deleting_destructor'
    //         0040ce70     PUSH       ESI
    //         0040ce71     MOV        ESI,this
    //         0040ce73     CALL       MainDecisionAIModule::~MainDecisionAIModule      void ~MainDecisionAIModule(MainDecisionAIModu
    //         0040ce78     TEST       byte ptr [ESP + param_1],0x1
    //         0040ce7d     JZ         LAB_0040ce88
    //         0040ce7f     PUSH       ESI
    //         0040ce80     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0040ce85     ADD        ESP,0x4
    //                               LAB_0040ce88                                                 XREF[1]:     0040ce7d(j)  
    //         0040ce88     MOV        EAX,ESI
    //         0040ce8a     POP        ESI
    //         0040ce8b     RET        0x4
}

