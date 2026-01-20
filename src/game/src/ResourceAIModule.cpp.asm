// Auto-generated scaffold unit: ResourceAIModule.cpp.asm
#include "../include/common.h"

// Offset: 0x00412460
void* ResourceAIModule::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall ResourceAIModule::`vector deleting destructor'(unsigned int)        *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(ResourceAIModule * th
    //              void *            EAX:4          <RETURN>
    //              ResourceAIModu    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00412468(R)  
    //                               ??_GResourceAIModule@@UAEPAXI@Z                              XREF[1]:     0056e9d8(*)  
    //                               ??_EResourceAIModule@@UAEPAXI@Z
    //                               ResourceAIModule::`vector_deleting_destructor'
    //         00412460     PUSH       ESI
    //         00412461     MOV        ESI,this
    //         00412463     CALL       ResourceAIModule::~ResourceAIModule              void ~ResourceAIModule(ResourceAIModule * this)
    //         00412468     TEST       byte ptr [ESP + param_1],0x1
    //         0041246d     JZ         LAB_00412478
    //         0041246f     PUSH       ESI
    //         00412470     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00412475     ADD        ESP,0x4
    //                               LAB_00412478                                                 XREF[1]:     0041246d(j)  
    //         00412478     MOV        EAX,ESI
    //         0041247a     POP        ESI
    //         0041247b     RET        0x4
}

