// Auto-generated scaffold unit: TRIBE_Panel_Time.cpp.asm
#include "../include/common.h"

// Offset: 0x0051D890
void* TRIBE_Panel_Time::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Panel_Time::`scalar deleting destructor'(unsigned int)        *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TRIBE_Panel_Time * th
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Panel_Ti    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0051d898(R)  
    //                               ??_ETRIBE_Panel_Time@@UAEPAXI@Z                              XREF[1]:     00576ea8(*)  
    //                               ??_GTRIBE_Panel_Time@@UAEPAXI@Z
    //                               TRIBE_Panel_Time::`scalar_deleting_destructor'
    //         0051d890     PUSH       ESI
    //         0051d891     MOV        ESI,this
    //         0051d893     CALL       TRIBE_Panel_Time::~TRIBE_Panel_Time              void ~TRIBE_Panel_Time(TRIBE_Panel_Time * this)
    //         0051d898     TEST       byte ptr [ESP + param_1],0x1
    //         0051d89d     JZ         LAB_0051d8a8
    //         0051d89f     PUSH       ESI
    //         0051d8a0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0051d8a5     ADD        ESP,0x4
    //                               LAB_0051d8a8                                                 XREF[1]:     0051d89d(j)  
    //         0051d8a8     MOV        EAX,ESI
    //         0051d8aa     POP        ESI
    //         0051d8ab     RET        0x4
}

