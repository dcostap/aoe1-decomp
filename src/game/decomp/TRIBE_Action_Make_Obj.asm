// Auto-generated scaffold unit: TRIBE_Action_Make_Obj.asm
#include "../include/common.h"

// Offset: 0x004D0E90
void* TRIBE_Action_Make_Obj::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Action_Make_Obj::`vector deleting destructor'(unsigned int)   *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TRIBE_Action_Make_Obj
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Action_M    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004d0e98(R)  
    //                               ??_GTRIBE_Action_Make_Obj@@UAEPAXI@Z                         XREF[1]:     005751a8(*)  
    //                               ??_ETRIBE_Action_Make_Obj@@UAEPAXI@Z
    //                               TRIBE_Action_Make_Obj::`vector_deleting_destructor'
    //         004d0e90     PUSH       ESI
    //         004d0e91     MOV        ESI,this
    //         004d0e93     CALL       TRIBE_Action_Make_Obj::~TRIBE_Action_Make_Obj    void ~TRIBE_Action_Make_Obj(TRIBE_Action_Make
    //         004d0e98     TEST       byte ptr [ESP + param_1],0x1
    //         004d0e9d     JZ         LAB_004d0ea8
    //         004d0e9f     PUSH       ESI
    //         004d0ea0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004d0ea5     ADD        ESP,0x4
    //                               LAB_004d0ea8                                                 XREF[1]:     004d0e9d(j)  
    //         004d0ea8     MOV        EAX,ESI
    //         004d0eaa     POP        ESI
    //         004d0eab     RET        0x4
}

