// Auto-generated scaffold unit: THelpDialog.cpp.asm
#include "../include/common.h"

// Offset: 0x0043E8C0
void* THelpDialog::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall THelpDialog::`scalar deleting destructor'(unsigned int)             *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(THelpDialog * this, u
    //              void *            EAX:4          <RETURN>
    //              THelpDialog *     ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0043e8c8(R)  
    //                               ??_ETHelpDialog@@UAEPAXI@Z                                   XREF[1]:     0056f9c8(*)  
    //                               ??_GTHelpDialog@@UAEPAXI@Z
    //                               THelpDialog::`scalar_deleting_destructor'
    //         0043e8c0     PUSH       ESI
    //         0043e8c1     MOV        ESI,this
    //         0043e8c3     CALL       THelpDialog::~THelpDialog                        void ~THelpDialog(THelpDialog * this)
    //         0043e8c8     TEST       byte ptr [ESP + param_1],0x1
    //         0043e8cd     JZ         LAB_0043e8d8
    //         0043e8cf     PUSH       ESI
    //         0043e8d0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0043e8d5     ADD        ESP,0x4
    //                               LAB_0043e8d8                                                 XREF[1]:     0043e8cd(j)  
    //         0043e8d8     MOV        EAX,ESI
    //         0043e8da     POP        ESI
    //         0043e8db     RET        0x4
}

