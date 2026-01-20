// Auto-generated scaffold unit: TribeSendMessageDialog.cpp.asm
#include "../include/common.h"

// Offset: 0x00440E00
void* TribeSendMessageDialog::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TribeSendMessageDialog::`scalar deleting destructor'(unsigned int)  *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TribeSendMessageDialo
    //              void *            EAX:4          <RETURN>
    //              TribeSendMessa    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00440e08(R)  
    //                               ??_ETribeSendMessageDialog@@UAEPAXI@Z                        XREF[1]:     0056ffc0(*)  
    //                               ??_GTribeSendMessageDialog@@UAEPAXI@Z
    //                               TribeSendMessageDialog::`scalar_deleting_destructor'
    //         00440e00     PUSH       ESI
    //         00440e01     MOV        ESI,this
    //         00440e03     CALL       TribeSendMessageDialog::~TribeSendMessageDialog  void ~TribeSendMessageDialog(TribeSendMessage
    //         00440e08     TEST       byte ptr [ESP + param_1],0x1
    //         00440e0d     JZ         LAB_00440e18
    //         00440e0f     PUSH       ESI
    //         00440e10     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00440e15     ADD        ESP,0x4
    //                               LAB_00440e18                                                 XREF[1]:     00440e0d(j)  
    //         00440e18     MOV        EAX,ESI
    //         00440e1a     POP        ESI
    //         00440e1b     RET        0x4
}

