// Auto-generated scaffold unit: TRIBE_Panel_Button.cpp.asm
#include "../include/common.h"

// Offset: 0x00519E70
void* TRIBE_Panel_Button::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Panel_Button::`scalar deleting destructor'(unsigned int)      *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TRIBE_Panel_Button * 
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Panel_Bu    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00519e78(R)  
    //                               ??_ETRIBE_Panel_Button@@UAEPAXI@Z                            XREF[1]:     00576ad0(*)  
    //                               ??_GTRIBE_Panel_Button@@UAEPAXI@Z
    //                               TRIBE_Panel_Button::`scalar_deleting_destructor'
    //         00519e70     PUSH       ESI
    //         00519e71     MOV        ESI,this
    //         00519e73     CALL       TRIBE_Panel_Button::~TRIBE_Panel_Button          void ~TRIBE_Panel_Button(TRIBE_Panel_Button *
    //         00519e78     TEST       byte ptr [ESP + param_1],0x1
    //         00519e7d     JZ         LAB_00519e88
    //         00519e7f     PUSH       ESI
    //         00519e80     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00519e85     ADD        ESP,0x4
    //                               LAB_00519e88                                                 XREF[1]:     00519e7d(j)  
    //         00519e88     MOV        EAX,ESI
    //         00519e8a     POP        ESI
    //         00519e8b     RET        0x4
}

