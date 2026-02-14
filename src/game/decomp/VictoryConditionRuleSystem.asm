// Auto-generated scaffold unit: VictoryConditionRuleSystem.asm
#include "../include/common.h"

// Offset: 0x004E7410
void* VictoryConditionRuleSystem::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall VictoryConditionRuleSystem::`scalar deleting destructor'(unsigne... *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(VictoryConditionRuleS
    //              void *            EAX:4          <RETURN>
    //              VictoryConditi    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004e7418(R)  
    //                               ??_EVictoryConditionRuleSystem@@UAEPAXI@Z                    XREF[1]:     00575678(*)  
    //                               ??_GVictoryConditionRuleSystem@@UAEPAXI@Z
    //                               VictoryConditionRuleSystem::`scalar_deleting_destructor'
    //         004e7410     PUSH       ESI
    //         004e7411     MOV        ESI,this
    //         004e7413     CALL       VictoryConditionRuleSystem::~VictoryConditionR   void ~VictoryConditionRuleSystem(VictoryCondi
    //         004e7418     TEST       byte ptr [ESP + param_1],0x1
    //         004e741d     JZ         LAB_004e7428
    //         004e741f     PUSH       ESI
    //         004e7420     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004e7425     ADD        ESP,0x4
    //                               LAB_004e7428                                                 XREF[1]:     004e741d(j)  
    //         004e7428     MOV        EAX,ESI
    //         004e742a     POP        ESI
    //         004e742b     RET        0x4
}

