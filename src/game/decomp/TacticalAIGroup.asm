// Auto-generated scaffold unit: TacticalAIGroup.asm
#include "../include/common.h"

// Offset: 0x004EA990
void* TacticalAIGroup::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TacticalAIGroup::`scalar deleting destructor'(unsigned int)         *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TacticalAIGroup * thi
    //              void *            EAX:4          <RETURN>
    //              TacticalAIGrou    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004ea998(R)  
    //                               ??_ETacticalAIGroup@@UAEPAXI@Z                               XREF[1]:     005756d8(*)  
    //                               ??_GTacticalAIGroup@@UAEPAXI@Z
    //                               TacticalAIGroup::`scalar_deleting_destructor'
    //         004ea990     PUSH       ESI
    //         004ea991     MOV        ESI,this
    //         004ea993     CALL       TacticalAIGroup::~TacticalAIGroup                void ~TacticalAIGroup(TacticalAIGroup * this)
    //         004ea998     TEST       byte ptr [ESP + param_1],0x1
    //         004ea99d     JZ         LAB_004ea9a8
    //         004ea99f     PUSH       ESI
    //         004ea9a0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004ea9a5     ADD        ESP,0x4
    //                               LAB_004ea9a8                                                 XREF[1]:     004ea99d(j)  
    //         004ea9a8     MOV        EAX,ESI
    //         004ea9aa     POP        ESI
    //         004ea9ab     RET        0x4
}

