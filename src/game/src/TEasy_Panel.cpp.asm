// Auto-generated scaffold unit: TEasy_Panel.cpp.asm
#include "../include/common.h"

// Offset: 0x00466A70
void* TEasy_Panel::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TEasy_Panel::`scalar deleting destructor'(unsigned int)             *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TEasy_Panel * this, u
    //              void *            EAX:4          <RETURN>
    //              TEasy_Panel *     ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00466a78(R)  
    //                               ??_ETEasy_Panel@@UAEPAXI@Z                                   XREF[1]:     00570d18(*)  
    //                               ??_GTEasy_Panel@@UAEPAXI@Z
    //                               TEasy_Panel::`scalar_deleting_destructor'
    //         00466a70     PUSH       ESI
    //         00466a71     MOV        ESI,this
    //         00466a73     CALL       TEasy_Panel::~TEasy_Panel                        void ~TEasy_Panel(TEasy_Panel * this)
    //         00466a78     TEST       byte ptr [ESP + param_1],0x1
    //         00466a7d     JZ         LAB_00466a88
    //         00466a7f     PUSH       ESI
    //         00466a80     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00466a85     ADD        ESP,0x4
    //                               LAB_00466a88                                                 XREF[1]:     00466a7d(j)  
    //         00466a88     MOV        EAX,ESI
    //         00466a8a     POP        ESI
    //         00466a8b     RET        0x4
}

