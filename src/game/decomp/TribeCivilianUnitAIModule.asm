// Auto-generated scaffold unit: TribeCivilianUnitAIModule.asm
#include "../include/common.h"

// Offset: 0x00504C60
void* TribeCivilianUnitAIModule::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TribeCivilianUnitAIModule::`scalar deleting destructor'(unsigned... *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TribeCivilianUnitAIMo
    //              void *            EAX:4          <RETURN>
    //              TribeCivilianU    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00504c68(R)  
    //                               ??_ETribeCivilianUnitAIModule@@UAEPAXI@Z                     XREF[1]:     00575d48(*)  
    //                               ??_GTribeCivilianUnitAIModule@@UAEPAXI@Z
    //                               TribeCivilianUnitAIModule::`scalar_deleting_destructor'
    //         00504c60     PUSH       ESI
    //         00504c61     MOV        ESI,this
    //         00504c63     CALL       TribeCivilianUnitAIModule::~TribeCivilianUnitA   void ~TribeCivilianUnitAIModule(TribeCivilian
    //         00504c68     TEST       byte ptr [ESP + param_1],0x1
    //         00504c6d     JZ         LAB_00504c78
    //         00504c6f     PUSH       ESI
    //         00504c70     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00504c75     ADD        ESP,0x4
    //                               LAB_00504c78                                                 XREF[1]:     00504c6d(j)  
    //         00504c78     MOV        EAX,ESI
    //         00504c7a     POP        ESI
    //         00504c7b     RET        0x4
}

