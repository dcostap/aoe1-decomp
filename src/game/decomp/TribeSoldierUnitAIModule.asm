// Auto-generated scaffold unit: TribeSoldierUnitAIModule.asm
#include "../include/common.h"

// Offset: 0x00507170
void* TribeSoldierUnitAIModule::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TribeSoldierUnitAIModule::`scalar deleting destructor'(unsigned ... *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TribeSoldierUnitAIMod
    //              void *            EAX:4          <RETURN>
    //              TribeSoldierUn    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00507178(R)  
    //                               ??_ETribeSoldierUnitAIModule@@UAEPAXI@Z                      XREF[1]:     005761b0(*)  
    //                               ??_GTribeSoldierUnitAIModule@@UAEPAXI@Z
    //                               TribeSoldierUnitAIModule::`scalar_deleting_destructor'
    //         00507170     PUSH       ESI
    //         00507171     MOV        ESI,this
    //         00507173     CALL       TribeSoldierUnitAIModule::~TribeSoldierUnitAIM   void ~TribeSoldierUnitAIModule(TribeSoldierUn
    //         00507178     TEST       byte ptr [ESP + param_1],0x1
    //         0050717d     JZ         LAB_00507188
    //         0050717f     PUSH       ESI
    //         00507180     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00507185     ADD        ESP,0x4
    //                               LAB_00507188                                                 XREF[1]:     0050717d(j)  
    //         00507188     MOV        EAX,ESI
    //         0050718a     POP        ESI
    //         0050718b     RET        0x4
}

