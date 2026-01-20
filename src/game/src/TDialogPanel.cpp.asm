// Auto-generated scaffold unit: TDialogPanel.cpp.asm
#include "../include/common.h"

// Offset: 0x00473C60
void* TDialogPanel::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TDialogPanel::`vector deleting destructor'(unsigned int)            *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TDialogPanel * this, 
    //              void *            EAX:4          <RETURN>
    //              TDialogPanel *    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00473c68(R)  
    //                               ??_GTDialogPanel@@UAEPAXI@Z                                  XREF[1]:     005710b0(*)  
    //                               ??_ETDialogPanel@@UAEPAXI@Z
    //                               TDialogPanel::`vector_deleting_destructor'
    //         00473c60     PUSH       ESI
    //         00473c61     MOV        ESI,this
    //         00473c63     CALL       TDialogPanel::~TDialogPanel                      void ~TDialogPanel(TDialogPanel * this)
    //         00473c68     TEST       byte ptr [ESP + param_1],0x1
    //         00473c6d     JZ         LAB_00473c78
    //         00473c6f     PUSH       ESI
    //         00473c70     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00473c75     ADD        ESP,0x4
    //                               LAB_00473c78                                                 XREF[1]:     00473c6d(j)  
    //         00473c78     MOV        EAX,ESI
    //         00473c7a     POP        ESI
    //         00473c7b     RET        0x4
}

