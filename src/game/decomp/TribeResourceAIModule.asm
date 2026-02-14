// Auto-generated scaffold unit: TribeResourceAIModule.asm
#include "../include/common.h"

// Offset: 0x004E6B80
void* TribeResourceAIModule::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TribeResourceAIModule::`scalar deleting destructor'(unsigned int)   *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TribeResourceAIModule
    //              void *            EAX:4          <RETURN>
    //              TribeResourceA    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004e6b88(R)  
    //                               ??_ETribeResourceAIModule@@UAEPAXI@Z                         XREF[1]:     00575638(*)  
    //                               ??_GTribeResourceAIModule@@UAEPAXI@Z
    //                               TribeResourceAIModule::`scalar_deleting_destructor'
    //         004e6b80     PUSH       ESI
    //         004e6b81     MOV        ESI,this
    //         004e6b83     CALL       TribeResourceAIModule::~TribeResourceAIModule    void ~TribeResourceAIModule(TribeResourceAIMo
    //         004e6b88     TEST       byte ptr [ESP + param_1],0x1
    //         004e6b8d     JZ         LAB_004e6b98
    //         004e6b8f     PUSH       ESI
    //         004e6b90     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004e6b95     ADD        ESP,0x4
    //                               LAB_004e6b98                                                 XREF[1]:     004e6b8d(j)  
    //         004e6b98     MOV        EAX,ESI
    //         004e6b9a     POP        ESI
    //         004e6b9b     RET        0x4
}

