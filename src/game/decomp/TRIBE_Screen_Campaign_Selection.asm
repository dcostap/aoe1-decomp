// Auto-generated scaffold unit: TRIBE_Screen_Campaign_Selection.asm
#include "../include/common.h"

// Offset: 0x00490E10
void* TRIBE_Screen_Campaign_Selection::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Screen_Campaign_Selection::`vector deleting destructor'(un... *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TRIBE_Screen_Campaign
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Screen_C    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00490e18(R)  
    //                               ??_GTRIBE_Screen_Campaign_Selection@@UAEPAXI@Z               XREF[1]:     005723d0(*)  
    //                               ??_ETRIBE_Screen_Campaign_Selection@@UAEPAXI@Z
    //                               TRIBE_Screen_Campaign_Selection::`vector_deleting_destructor'
    //         00490e10     PUSH       ESI
    //         00490e11     MOV        ESI,this
    //         00490e13     CALL       TRIBE_Screen_Campaign_Selection::~TRIBE_Screen   void ~TRIBE_Screen_Campaign_Selection(TRIBE_S
    //         00490e18     TEST       byte ptr [ESP + param_1],0x1
    //         00490e1d     JZ         LAB_00490e28
    //         00490e1f     PUSH       ESI
    //         00490e20     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00490e25     ADD        ESP,0x4
    //                               LAB_00490e28                                                 XREF[1]:     00490e1d(j)  
    //         00490e28     MOV        EAX,ESI
    //         00490e2a     POP        ESI
    //         00490e2b     RET        0x4
}

