// Auto-generated scaffold unit: TMessagePanel.cpp.asm
#include "../include/common.h"

// Offset: 0x00479030
void* TMessagePanel::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TMessagePanel::`scalar deleting destructor'(unsigned int)           *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TMessagePanel * this,
    //              void *            EAX:4          <RETURN>
    //              TMessagePanel *   ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00479038(R)  
    //                               ??_ETMessagePanel@@UAEPAXI@Z                                 XREF[1]:     00571668(*)  
    //                               ??_GTMessagePanel@@UAEPAXI@Z
    //                               TMessagePanel::`scalar_deleting_destructor'
    //         00479030     PUSH       ESI
    //         00479031     MOV        ESI,this
    //         00479033     CALL       TMessagePanel::~TMessagePanel                    void ~TMessagePanel(TMessagePanel * this)
    //         00479038     TEST       byte ptr [ESP + param_1],0x1
    //         0047903d     JZ         LAB_00479048
    //         0047903f     PUSH       ESI
    //         00479040     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00479045     ADD        ESP,0x4
    //                               LAB_00479048                                                 XREF[1]:     0047903d(j)  
    //         00479048     MOV        EAX,ESI
    //         0047904a     POP        ESI
    //         0047904b     RET        0x4
}

