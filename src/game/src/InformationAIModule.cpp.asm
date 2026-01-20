// Auto-generated scaffold unit: InformationAIModule.cpp.asm
#include "../include/common.h"

// Offset: 0x0040CDC0
void* InformationAIModule::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall InformationAIModule::`vector deleting destructor'(unsigned int)     *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(InformationAIModule *
    //              void *            EAX:4          <RETURN>
    //              InformationAIM    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0040cdc8(R)  
    //                               ??_GInformationAIModule@@UAEPAXI@Z                           XREF[1]:     0056e898(*)  
    //                               ??_EInformationAIModule@@UAEPAXI@Z
    //                               InformationAIModule::`vector_deleting_destructor'
    //         0040cdc0     PUSH       ESI
    //         0040cdc1     MOV        ESI,this
    //         0040cdc3     CALL       InformationAIModule::~InformationAIModule        void ~InformationAIModule(InformationAIModule
    //         0040cdc8     TEST       byte ptr [ESP + param_1],0x1
    //         0040cdcd     JZ         LAB_0040cdd8
    //         0040cdcf     PUSH       ESI
    //         0040cdd0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0040cdd5     ADD        ESP,0x4
    //                               LAB_0040cdd8                                                 XREF[1]:     0040cdcd(j)  
    //         0040cdd8     MOV        EAX,ESI
    //         0040cdda     POP        ESI
    //         0040cddb     RET        0x4
}

