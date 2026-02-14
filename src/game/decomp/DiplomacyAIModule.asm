// Auto-generated scaffold unit: DiplomacyAIModule.asm
#include "../include/common.h"

// Offset: 0x0040BF20
void* DiplomacyAIModule::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall DiplomacyAIModule::`scalar deleting destructor'(unsigned int)       *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(DiplomacyAIModule * t
    //              void *            EAX:4          <RETURN>
    //              DiplomacyAIMod    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0040bf28(R)  
    //                               ??_EDiplomacyAIModule@@UAEPAXI@Z                             XREF[1]:     0056e818(*)  
    //                               ??_GDiplomacyAIModule@@UAEPAXI@Z
    //                               DiplomacyAIModule::`scalar_deleting_destructor'
    //         0040bf20     PUSH       ESI
    //         0040bf21     MOV        ESI,this
    //         0040bf23     CALL       DiplomacyAIModule::~DiplomacyAIModule            void ~DiplomacyAIModule(DiplomacyAIModule * t
    //         0040bf28     TEST       byte ptr [ESP + param_1],0x1
    //         0040bf2d     JZ         LAB_0040bf38
    //         0040bf2f     PUSH       ESI
    //         0040bf30     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0040bf35     ADD        ESP,0x4
    //                               LAB_0040bf38                                                 XREF[1]:     0040bf2d(j)  
    //         0040bf38     MOV        EAX,ESI
    //         0040bf3a     POP        ESI
    //         0040bf3b     RET        0x4
}

