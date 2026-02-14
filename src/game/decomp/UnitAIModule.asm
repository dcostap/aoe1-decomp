// Auto-generated scaffold unit: UnitAIModule.asm
#include "../include/common.h"

// Offset: 0x00413070
void* UnitAIModule::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall UnitAIModule::`scalar deleting destructor'(unsigned int)            *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(UnitAIModule * this, 
    //              void *            EAX:4          <RETURN>
    //              UnitAIModule *    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00413078(R)  
    //                               ??_EUnitAIModule@@UAEPAXI@Z                                  XREF[1]:     0056ead8(*)  
    //                               ??_GUnitAIModule@@UAEPAXI@Z
    //                               UnitAIModule::`scalar_deleting_destructor'
    //         00413070     PUSH       ESI
    //         00413071     MOV        ESI,this
    //         00413073     CALL       UnitAIModule::~UnitAIModule                      void ~UnitAIModule(UnitAIModule * this)
    //         00413078     TEST       byte ptr [ESP + param_1],0x1
    //         0041307d     JZ         LAB_00413088
    //         0041307f     PUSH       ESI
    //         00413080     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00413085     ADD        ESP,0x4
    //                               LAB_00413088                                                 XREF[1]:     0041307d(j)  
    //         00413088     MOV        EAX,ESI
    //         0041308a     POP        ESI
    //         0041308b     RET        0x4
}

