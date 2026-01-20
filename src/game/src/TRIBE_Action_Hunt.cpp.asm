// Auto-generated scaffold unit: TRIBE_Action_Hunt.cpp.asm
#include "../include/common.h"

// Offset: 0x004CF100
void* TRIBE_Action_Hunt::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Action_Hunt::`scalar deleting destructor'(unsigned int)       *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TRIBE_Action_Hunt * t
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Action_H    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004cf108(R)  
    //                               ??_ETRIBE_Action_Hunt@@UAEPAXI@Z                             XREF[1]:     005750f0(*)  
    //                               ??_GTRIBE_Action_Hunt@@UAEPAXI@Z
    //                               TRIBE_Action_Hunt::`scalar_deleting_destructor'
    //         004cf100     PUSH       ESI
    //         004cf101     MOV        ESI,this
    //         004cf103     CALL       TRIBE_Action_Hunt::~TRIBE_Action_Hunt            void ~TRIBE_Action_Hunt(TRIBE_Action_Hunt * t
    //         004cf108     TEST       byte ptr [ESP + param_1],0x1
    //         004cf10d     JZ         LAB_004cf118
    //         004cf10f     PUSH       ESI
    //         004cf110     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004cf115     ADD        ESP,0x4
    //                               LAB_004cf118                                                 XREF[1]:     004cf10d(j)  
    //         004cf118     MOV        EAX,ESI
    //         004cf11a     POP        ESI
    //         004cf11b     RET        0x4
}

