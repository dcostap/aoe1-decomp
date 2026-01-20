// Auto-generated scaffold unit: ResearchAIModule.cpp.asm
#include "../include/common.h"

// Offset: 0x00411720
void* ResearchAIModule::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall ResearchAIModule::`scalar deleting destructor'(unsigned int)        *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(ResearchAIModule * th
    //              void *            EAX:4          <RETURN>
    //              ResearchAIModu    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00411728(R)  
    //                               ??_EResearchAIModule@@UAEPAXI@Z                              XREF[1]:     0056e988(*)  
    //                               ??_GResearchAIModule@@UAEPAXI@Z
    //                               ResearchAIModule::`scalar_deleting_destructor'
    //         00411720     PUSH       ESI
    //         00411721     MOV        ESI,this
    //         00411723     CALL       ResearchAIModule::~ResearchAIModule              void ~ResearchAIModule(ResearchAIModule * this)
    //         00411728     TEST       byte ptr [ESP + param_1],0x1
    //         0041172d     JZ         LAB_00411738
    //         0041172f     PUSH       ESI
    //         00411730     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00411735     ADD        ESP,0x4
    //                               LAB_00411738                                                 XREF[1]:     0041172d(j)  
    //         00411738     MOV        EAX,ESI
    //         0041173a     POP        ESI
    //         0041173b     RET        0x4
}

