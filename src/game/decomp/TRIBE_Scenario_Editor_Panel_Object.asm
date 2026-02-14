// Auto-generated scaffold unit: TRIBE_Scenario_Editor_Panel_Object.asm
#include "../include/common.h"

// Offset: 0x004BEE10
void* TRIBE_Scenario_Editor_Panel_Object::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Scenario_Editor_Panel_Object::`scalar deleting destructor'... *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TRIBE_Scenario_Editor
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Scenario    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004bee18(R)  
    //                               ??_ETRIBE_Scenario_Editor_Panel_Object@@UAEPAXI@Z            XREF[1]:     00574440(*)  
    //                               ??_GTRIBE_Scenario_Editor_Panel_Object@@UAEPAXI@Z
    //                               TRIBE_Scenario_Editor_Panel_Object::`scalar_deleting_destru
    //         004bee10     PUSH       ESI
    //         004bee11     MOV        ESI,this
    //         004bee13     CALL       TRIBE_Scenario_Editor_Panel_Object::~TRIBE_Sce   void ~TRIBE_Scenario_Editor_Panel_Object(TRIB
    //         004bee18     TEST       byte ptr [ESP + param_1],0x1
    //         004bee1d     JZ         LAB_004bee28
    //         004bee1f     PUSH       ESI
    //         004bee20     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004bee25     ADD        ESP,0x4
    //                               LAB_004bee28                                                 XREF[1]:     004bee1d(j)  
    //         004bee28     MOV        EAX,ESI
    //         004bee2a     POP        ESI
    //         004bee2b     RET        0x4
}

