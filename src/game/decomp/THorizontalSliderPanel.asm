// Auto-generated scaffold unit: THorizontalSliderPanel.asm
#include "../include/common.h"

// Offset: 0x0047BE10
void* THorizontalSliderPanel::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall THorizontalSliderPanel::`scalar deleting destructor'(unsigned int)  *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(THorizontalSliderPane
    //              void *            EAX:4          <RETURN>
    //              THorizontalSli    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0047be18(R)  
    //                               ??_ETHorizontalSliderPanel@@UAEPAXI@Z                        XREF[1]:     00571b18(*)  
    //                               ??_GTHorizontalSliderPanel@@UAEPAXI@Z
    //                               THorizontalSliderPanel::`scalar_deleting_destructor'
    //         0047be10     PUSH       ESI
    //         0047be11     MOV        ESI,this
    //         0047be13     CALL       THorizontalSliderPanel::~THorizontalSliderPanel  void ~THorizontalSliderPanel(THorizontalSlide
    //         0047be18     TEST       byte ptr [ESP + param_1],0x1
    //         0047be1d     JZ         LAB_0047be28
    //         0047be1f     PUSH       ESI
    //         0047be20     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0047be25     ADD        ESP,0x4
    //                               LAB_0047be28                                                 XREF[1]:     0047be1d(j)  
    //         0047be28     MOV        EAX,ESI
    //         0047be2a     POP        ESI
    //         0047be2b     RET        0x4
}

