// Auto-generated scaffold unit: CombatRuleSystem.asm
#include "../include/common.h"

// Offset: 0x004D68E0
void* CombatRuleSystem::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall CombatRuleSystem::`scalar deleting destructor'(unsigned int)        *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(CombatRuleSystem * th
    //              void *            EAX:4          <RETURN>
    //              CombatRuleSyst    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004d68e8(R)  
    //                               ??_ECombatRuleSystem@@UAEPAXI@Z                              XREF[1]:     0057550c(*)  
    //                               ??_GCombatRuleSystem@@UAEPAXI@Z
    //                               CombatRuleSystem::`scalar_deleting_destructor'
    //         004d68e0     PUSH       ESI
    //         004d68e1     MOV        ESI,this
    //         004d68e3     CALL       CombatRuleSystem::~CombatRuleSystem              void ~CombatRuleSystem(CombatRuleSystem * this)
    //         004d68e8     TEST       byte ptr [ESP + param_1],0x1
    //         004d68ed     JZ         LAB_004d68f8
    //         004d68ef     PUSH       ESI
    //         004d68f0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004d68f5     ADD        ESP,0x4
    //                               LAB_004d68f8                                                 XREF[1]:     004d68ed(j)  
    //         004d68f8     MOV        EAX,ESI
    //         004d68fa     POP        ESI
    //         004d68fb     RET        0x4
}

