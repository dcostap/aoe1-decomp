// Auto-generated scaffold unit: TRIBE_Action_Make_Tech.cpp.asm
#include "../include/common.h"

// Offset: 0x004D2230
void* TRIBE_Action_Make_Tech::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Action_Make_Tech::`vector deleting destructor'(unsigned int)  *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TRIBE_Action_Make_Tec
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Action_M    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004d2238(R)  
    //                               ??_GTRIBE_Action_Make_Tech@@UAEPAXI@Z                        XREF[1]:     00575280(*)  
    //                               ??_ETRIBE_Action_Make_Tech@@UAEPAXI@Z
    //                               TRIBE_Action_Make_Tech::`vector_deleting_destructor'
    //         004d2230     PUSH       ESI
    //         004d2231     MOV        ESI,this
    //         004d2233     CALL       TRIBE_Action_Make_Tech::~TRIBE_Action_Make_Tech  void ~TRIBE_Action_Make_Tech(TRIBE_Action_Mak
    //         004d2238     TEST       byte ptr [ESP + param_1],0x1
    //         004d223d     JZ         LAB_004d2248
    //         004d223f     PUSH       ESI
    //         004d2240     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004d2245     ADD        ESP,0x4
    //                               LAB_004d2248                                                 XREF[1]:     004d223d(j)  
    //         004d2248     MOV        EAX,ESI
    //         004d224a     POP        ESI
    //         004d224b     RET        0x4
}

