// Auto-generated scaffold unit: TRIBE_Panel_Text_Line.asm
#include "../include/common.h"

// Offset: 0x00520E00
void* TRIBE_Panel_Text_Line::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Panel_Text_Line::`scalar deleting destructor'(unsigned int)   *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TRIBE_Panel_Text_Line
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Panel_Te    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00520e08(R)  
    //                               ??_ETRIBE_Panel_Text_Line@@UAEPAXI@Z                         XREF[1]:     005770c8(*)  
    //                               ??_GTRIBE_Panel_Text_Line@@UAEPAXI@Z
    //                               TRIBE_Panel_Text_Line::`scalar_deleting_destructor'
    //         00520e00     PUSH       ESI
    //         00520e01     MOV        ESI,this
    //         00520e03     CALL       TRIBE_Panel_Text_Line::~TRIBE_Panel_Text_Line    void ~TRIBE_Panel_Text_Line(TRIBE_Panel_Text_
    //         00520e08     TEST       byte ptr [ESP + param_1],0x1
    //         00520e0d     JZ         LAB_00520e18
    //         00520e0f     PUSH       ESI
    //         00520e10     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00520e15     ADD        ESP,0x4
    //                               LAB_00520e18                                                 XREF[1]:     00520e0d(j)  
    //         00520e18     MOV        EAX,ESI
    //         00520e1a     POP        ESI
    //         00520e1b     RET        0x4
}

