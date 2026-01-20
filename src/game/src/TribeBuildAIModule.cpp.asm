// Auto-generated scaffold unit: TribeBuildAIModule.cpp.asm
#include "../include/common.h"

// Offset: 0x004D3AB0
void* TribeBuildAIModule::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TribeBuildAIModule::`vector deleting destructor'(unsigned int)      *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TribeBuildAIModule * 
    //              void *            EAX:4          <RETURN>
    //              TribeBuildAIMo    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004d3ab8(R)  
    //                               ??_GTribeBuildAIModule@@UAEPAXI@Z                            XREF[1]:     00575440(*)  
    //                               ??_ETribeBuildAIModule@@UAEPAXI@Z
    //                               TribeBuildAIModule::`vector_deleting_destructor'
    //         004d3ab0     PUSH       ESI
    //         004d3ab1     MOV        ESI,this
    //         004d3ab3     CALL       TribeBuildAIModule::~TribeBuildAIModule          void ~TribeBuildAIModule(TribeBuildAIModule *
    //         004d3ab8     TEST       byte ptr [ESP + param_1],0x1
    //         004d3abd     JZ         LAB_004d3ac8
    //         004d3abf     PUSH       ESI
    //         004d3ac0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004d3ac5     ADD        ESP,0x4
    //                               LAB_004d3ac8                                                 XREF[1]:     004d3abd(j)  
    //         004d3ac8     MOV        EAX,ESI
    //         004d3aca     POP        ESI
    //         004d3acb     RET        0x4
}

