// Auto-generated scaffold unit: TRIBE_Panel_Inven.cpp.asm
#include "../include/common.h"

// Offset: 0x0051A690
void* TRIBE_Panel_Inven::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Panel_Inven::`scalar deleting destructor'(unsigned int)       *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TRIBE_Panel_Inven * t
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Panel_In    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0051a698(R)  
    //                               ??_ETRIBE_Panel_Inven@@UAEPAXI@Z                             XREF[1]:     00576bb8(*)  
    //                               ??_GTRIBE_Panel_Inven@@UAEPAXI@Z
    //                               TRIBE_Panel_Inven::`scalar_deleting_destructor'
    //         0051a690     PUSH       ESI
    //         0051a691     MOV        ESI,this
    //         0051a693     CALL       TRIBE_Panel_Inven::~TRIBE_Panel_Inven            void ~TRIBE_Panel_Inven(TRIBE_Panel_Inven * t
    //         0051a698     TEST       byte ptr [ESP + param_1],0x1
    //         0051a69d     JZ         LAB_0051a6a8
    //         0051a69f     PUSH       ESI
    //         0051a6a0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0051a6a5     ADD        ESP,0x4
    //                               LAB_0051a6a8                                                 XREF[1]:     0051a69d(j)  
    //         0051a6a8     MOV        EAX,ESI
    //         0051a6aa     POP        ESI
    //         0051a6ab     RET        0x4
}

