// Auto-generated scaffold unit: TRIBE_Dialog_List.cpp.asm
#include "../include/common.h"

// Offset: 0x0050B470
void* TRIBE_Dialog_List::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Dialog_List::`scalar deleting destructor'(unsigned int)       *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TRIBE_Dialog_List * t
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Dialog_L    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0050b478(R)  
    //                               ??_ETRIBE_Dialog_List@@UAEPAXI@Z                             XREF[1]:     00576580(*)  
    //                               ??_GTRIBE_Dialog_List@@UAEPAXI@Z
    //                               TRIBE_Dialog_List::`scalar_deleting_destructor'
    //         0050b470     PUSH       ESI
    //         0050b471     MOV        ESI,this
    //         0050b473     CALL       TRIBE_Dialog_List::~TRIBE_Dialog_List            void ~TRIBE_Dialog_List(TRIBE_Dialog_List * t
    //         0050b478     TEST       byte ptr [ESP + param_1],0x1
    //         0050b47d     JZ         LAB_0050b488
    //         0050b47f     PUSH       ESI
    //         0050b480     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0050b485     ADD        ESP,0x4
    //                               LAB_0050b488                                                 XREF[1]:     0050b47d(j)  
    //         0050b488     MOV        EAX,ESI
    //         0050b48a     POP        ESI
    //         0050b48b     RET        0x4
}

