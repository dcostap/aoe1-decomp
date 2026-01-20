// Auto-generated scaffold unit: TScrollBarPanel.cpp.asm
#include "../include/common.h"

// Offset: 0x0047A880
void* TScrollBarPanel::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TScrollBarPanel::`scalar deleting destructor'(unsigned int)         *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TScrollBarPanel * thi
    //              void *            EAX:4          <RETURN>
    //              TScrollBarPane    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0047a888(R)  
    //                               ??_ETScrollBarPanel@@UAEPAXI@Z                               XREF[1]:     00571830(*)  
    //                               ??_GTScrollBarPanel@@UAEPAXI@Z
    //                               TScrollBarPanel::`scalar_deleting_destructor'
    //         0047a880     PUSH       ESI
    //         0047a881     MOV        ESI,this
    //         0047a883     CALL       TScrollBarPanel::~TScrollBarPanel                void ~TScrollBarPanel(TScrollBarPanel * this)
    //         0047a888     TEST       byte ptr [ESP + param_1],0x1
    //         0047a88d     JZ         LAB_0047a898
    //         0047a88f     PUSH       ESI
    //         0047a890     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0047a895     ADD        ESP,0x4
    //                               LAB_0047a898                                                 XREF[1]:     0047a88d(j)  
    //         0047a898     MOV        EAX,ESI
    //         0047a89a     POP        ESI
    //         0047a89b     RET        0x4
}

