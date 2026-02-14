// Auto-generated scaffold unit: TVerticalSliderPanel.asm
#include "../include/common.h"

// Offset: 0x0047BD10
void* TVerticalSliderPanel::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TVerticalSliderPanel::`scalar deleting destructor'(unsigned int)    *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TVerticalSliderPanel 
    //              void *            EAX:4          <RETURN>
    //              TVerticalSlide    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0047bd18(R)  
    //                               ??_ETVerticalSliderPanel@@UAEPAXI@Z                          XREF[1]:     00571a38(*)  
    //                               ??_GTVerticalSliderPanel@@UAEPAXI@Z
    //                               TVerticalSliderPanel::`scalar_deleting_destructor'
    //         0047bd10     PUSH       ESI
    //         0047bd11     MOV        ESI,this
    //         0047bd13     CALL       TVerticalSliderPanel::~TVerticalSliderPanel      void ~TVerticalSliderPanel(TVerticalSliderPan
    //         0047bd18     TEST       byte ptr [ESP + param_1],0x1
    //         0047bd1d     JZ         LAB_0047bd28
    //         0047bd1f     PUSH       ESI
    //         0047bd20     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0047bd25     ADD        ESP,0x4
    //                               LAB_0047bd28                                                 XREF[1]:     0047bd1d(j)  
    //         0047bd28     MOV        EAX,ESI
    //         0047bd2a     POP        ESI
    //         0047bd2b     RET        0x4
}

