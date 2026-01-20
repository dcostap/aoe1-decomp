// Auto-generated scaffold unit: TMessageDialog.cpp.asm
#include "../include/common.h"

// Offset: 0x0043FCB0
void* TMessageDialog::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TMessageDialog::`scalar deleting destructor'(unsigned int)          *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TMessageDialog * this
    //              void *            EAX:4          <RETURN>
    //              TMessageDialog    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0043fcb8(R)  
    //                               ??_ETMessageDialog@@UAEPAXI@Z                                XREF[1]:     0056fd60(*)  
    //                               ??_GTMessageDialog@@UAEPAXI@Z
    //                               TMessageDialog::`scalar_deleting_destructor'
    //         0043fcb0     PUSH       ESI
    //         0043fcb1     MOV        ESI,this
    //         0043fcb3     CALL       TMessageDialog::~TMessageDialog                  void ~TMessageDialog(TMessageDialog * this)
    //         0043fcb8     TEST       byte ptr [ESP + param_1],0x1
    //         0043fcbd     JZ         LAB_0043fcc8
    //         0043fcbf     PUSH       ESI
    //         0043fcc0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0043fcc5     ADD        ESP,0x4
    //                               LAB_0043fcc8                                                 XREF[1]:     0043fcbd(j)  
    //         0043fcc8     MOV        EAX,ESI
    //         0043fcca     POP        ESI
    //         0043fccb     RET        0x4
}

