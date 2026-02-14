// Auto-generated scaffold unit: TRIBE_Action_Heal.asm
#include "../include/common.h"

// Offset: 0x004CE960
void* TRIBE_Action_Heal::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Action_Heal::`scalar deleting destructor'(unsigned int)       *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TRIBE_Action_Heal * t
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Action_H    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004ce968(R)  
    //                               ??_ETRIBE_Action_Heal@@UAEPAXI@Z                             XREF[1]:     00575080(*)  
    //                               ??_GTRIBE_Action_Heal@@UAEPAXI@Z
    //                               TRIBE_Action_Heal::`scalar_deleting_destructor'
    //         004ce960     PUSH       ESI
    //         004ce961     MOV        ESI,this
    //         004ce963     CALL       TRIBE_Action_Heal::~TRIBE_Action_Heal            void ~TRIBE_Action_Heal(TRIBE_Action_Heal * t
    //         004ce968     TEST       byte ptr [ESP + param_1],0x1
    //         004ce96d     JZ         LAB_004ce978
    //         004ce96f     PUSH       ESI
    //         004ce970     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004ce975     ADD        ESP,0x4
    //                               LAB_004ce978                                                 XREF[1]:     004ce96d(j)  
    //         004ce978     MOV        EAX,ESI
    //         004ce97a     POP        ESI
    //         004ce97b     RET        0x4
}

