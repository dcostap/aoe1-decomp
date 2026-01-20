// Auto-generated scaffold unit: TRIBE_Action_Trade.cpp.asm
#include "../include/common.h"

// Offset: 0x004D26E0
void* TRIBE_Action_Trade::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Action_Trade::`scalar deleting destructor'(unsigned int)      *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TRIBE_Action_Trade * 
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Action_T    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004d26e8(R)  
    //                               ??_ETRIBE_Action_Trade@@UAEPAXI@Z                            XREF[1]:     005752e8(*)  
    //                               ??_GTRIBE_Action_Trade@@UAEPAXI@Z
    //                               TRIBE_Action_Trade::`scalar_deleting_destructor'
    //         004d26e0     PUSH       ESI
    //         004d26e1     MOV        ESI,this
    //         004d26e3     CALL       TRIBE_Action_Trade::~TRIBE_Action_Trade          void ~TRIBE_Action_Trade(TRIBE_Action_Trade *
    //         004d26e8     TEST       byte ptr [ESP + param_1],0x1
    //         004d26ed     JZ         LAB_004d26f8
    //         004d26ef     PUSH       ESI
    //         004d26f0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004d26f5     ADD        ESP,0x4
    //                               LAB_004d26f8                                                 XREF[1]:     004d26ed(j)  
    //         004d26f8     MOV        EAX,ESI
    //         004d26fa     POP        ESI
    //         004d26fb     RET        0x4
}

