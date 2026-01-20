// Auto-generated scaffold unit: TribeSendQuickMessageDialog.cpp.asm
#include "../include/common.h"

// Offset: 0x00441630
void* TribeSendQuickMessageDialog::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TribeSendQuickMessageDialog::`vector deleting destructor'(unsign... *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TribeSendQuickMessage
    //              void *            EAX:4          <RETURN>
    //              TribeSendQuick    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00441638(R)  
    //                               ??_GTribeSendQuickMessageDialog@@UAEPAXI@Z                   XREF[1]:     005700f0(*)  
    //                               ??_ETribeSendQuickMessageDialog@@UAEPAXI@Z
    //                               TribeSendQuickMessageDialog::`vector_deleting_destructor'
    //         00441630     PUSH       ESI
    //         00441631     MOV        ESI,this
    //         00441633     CALL       TribeSendQuickMessageDialog::~TribeSendQuickMe   void ~TribeSendQuickMessageDialog(TribeSendQu
    //         00441638     TEST       byte ptr [ESP + param_1],0x1
    //         0044163d     JZ         LAB_00441648
    //         0044163f     PUSH       ESI
    //         00441640     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00441645     ADD        ESP,0x4
    //                               LAB_00441648                                                 XREF[1]:     0044163d(j)  
    //         00441648     MOV        EAX,ESI
    //         0044164a     POP        ESI
    //         0044164b     RET        0x4
}

