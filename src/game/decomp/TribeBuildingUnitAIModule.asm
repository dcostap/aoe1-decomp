// Auto-generated scaffold unit: TribeBuildingUnitAIModule.asm
#include "../include/common.h"

// Offset: 0x005082F0
void* TribeBuildingUnitAIModule::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TribeBuildingUnitAIModule::`scalar deleting destructor'(unsigned... *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TribeBuildingUnitAIMo
    //              void *            EAX:4          <RETURN>
    //              TribeBuildingU    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     005082f8(R)  
    //                               ??_ETribeBuildingUnitAIModule@@UAEPAXI@Z                     XREF[1]:     00576450(*)  
    //                               ??_GTribeBuildingUnitAIModule@@UAEPAXI@Z
    //                               TribeBuildingUnitAIModule::`scalar_deleting_destructor'
    //         005082f0     PUSH       ESI
    //         005082f1     MOV        ESI,this
    //         005082f3     CALL       TribeBuildingUnitAIModule::~TribeBuildingUnitA   void ~TribeBuildingUnitAIModule(TribeBuilding
    //         005082f8     TEST       byte ptr [ESP + param_1],0x1
    //         005082fd     JZ         LAB_00508308
    //         005082ff     PUSH       ESI
    //         00508300     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00508305     ADD        ESP,0x4
    //                               LAB_00508308                                                 XREF[1]:     005082fd(j)  
    //         00508308     MOV        EAX,ESI
    //         0050830a     POP        ESI
    //         0050830b     RET        0x4
}

