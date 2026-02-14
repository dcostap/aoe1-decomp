// Auto-generated scaffold unit: TribeConstructionAIModule.asm
#include "../include/common.h"

// Offset: 0x004D5E90
void* TribeConstructionAIModule::scalar_deleting_destructor(uint param_1) const {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TribeConstructionAIModule::`scalar deleting destructor'(unsigned... *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TribeConstructionAIMo
    //              void *            EAX:4          <RETURN>
    //              TribeConstruct    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004d5e98(R)  
    //                               ??_ETribeConstructionAIModule@@UAEPAXI@Z                     XREF[1]:     005754a0(*)  
    //                               ??_GTribeConstructionAIModule@@UAEPAXI@Z
    //                               TribeConstructionAIModule::`scalar_deleting_destructor'
    //         004d5e90     PUSH       ESI
    //         004d5e91     MOV        ESI,this
    //         004d5e93     CALL       TribeConstructionAIModule::~TribeConstructionA   void ~TribeConstructionAIModule(TribeConstruc
    //         004d5e98     TEST       byte ptr [ESP + param_1],0x1
    //         004d5e9d     JZ         LAB_004d5ea8
    //         004d5e9f     PUSH       ESI
    //         004d5ea0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004d5ea5     ADD        ESP,0x4
    //                               LAB_004d5ea8                                                 XREF[1]:     004d5e9d(j)  
    //         004d5ea8     MOV        EAX,ESI
    //         004d5eaa     POP        ESI
    //         004d5eab     RET        0x4
}

