// Auto-generated scaffold unit: TTextPanel.cpp.asm
#include "../include/common.h"

// Offset: 0x0047C090
void* TTextPanel::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TTextPanel::`scalar deleting destructor'(unsigned int)              *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TTextPanel * this, ui
    //              void *            EAX:4          <RETURN>
    //              TTextPanel *      ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0047c098(R)  
    //                               ??_ETTextPanel@@UAEPAXI@Z                                    XREF[1]:     00571bf8(*)  
    //                               ??_GTTextPanel@@UAEPAXI@Z
    //                               TTextPanel::`scalar_deleting_destructor'
    //         0047c090     PUSH       ESI
    //         0047c091     MOV        ESI,this
    //         0047c093     CALL       TTextPanel::~TTextPanel                          void ~TTextPanel(TTextPanel * this)
    //         0047c098     TEST       byte ptr [ESP + param_1],0x1
    //         0047c09d     JZ         LAB_0047c0a8
    //         0047c09f     PUSH       ESI
    //         0047c0a0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0047c0a5     ADD        ESP,0x4
    //                               LAB_0047c0a8                                                 XREF[1]:     0047c09d(j)  
    //         0047c0a8     MOV        EAX,ESI
    //         0047c0aa     POP        ESI
    //         0047c0ab     RET        0x4
}

