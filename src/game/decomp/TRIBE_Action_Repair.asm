// Auto-generated scaffold unit: TRIBE_Action_Repair.asm
#include "../include/common.h"

// Offset: 0x004D16F0
void* TRIBE_Action_Repair::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Action_Repair::`vector deleting destructor'(unsigned int)     *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TRIBE_Action_Repair *
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Action_R    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004d16f8(R)  
    //                               ??_GTRIBE_Action_Repair@@UAEPAXI@Z                           XREF[1]:     00575208(*)  
    //                               ??_ETRIBE_Action_Repair@@UAEPAXI@Z
    //                               TRIBE_Action_Repair::`vector_deleting_destructor'
    //         004d16f0     PUSH       ESI
    //         004d16f1     MOV        ESI,this
    //         004d16f3     CALL       TRIBE_Action_Repair::~TRIBE_Action_Repair        void ~TRIBE_Action_Repair(TRIBE_Action_Repair
    //         004d16f8     TEST       byte ptr [ESP + param_1],0x1
    //         004d16fd     JZ         LAB_004d1708
    //         004d16ff     PUSH       ESI
    //         004d1700     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004d1705     ADD        ESP,0x4
    //                               LAB_004d1708                                                 XREF[1]:     004d16fd(j)  
    //         004d1708     MOV        EAX,ESI
    //         004d170a     POP        ESI
    //         004d170b     RET        0x4
}

