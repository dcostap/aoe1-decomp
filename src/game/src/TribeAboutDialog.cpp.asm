// Auto-generated scaffold unit: TribeAboutDialog.cpp.asm
#include "../include/common.h"

// Offset: 0x0043B2E0
void* TribeAboutDialog::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TribeAboutDialog::`scalar deleting destructor'(unsigned int)        *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TribeAboutDialog * th
    //              void *            EAX:4          <RETURN>
    //              TribeAboutDial    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0043b2e8(R)  
    //                               ??_ETribeAboutDialog@@UAEPAXI@Z                              XREF[1]:     0056f610(*)  
    //                               ??_GTribeAboutDialog@@UAEPAXI@Z
    //                               TribeAboutDialog::`scalar_deleting_destructor'
    //         0043b2e0     PUSH       ESI
    //         0043b2e1     MOV        ESI,this
    //         0043b2e3     CALL       TribeAboutDialog::~TribeAboutDialog              void ~TribeAboutDialog(TribeAboutDialog * this)
    //         0043b2e8     TEST       byte ptr [ESP + param_1],0x1
    //         0043b2ed     JZ         LAB_0043b2f8
    //         0043b2ef     PUSH       ESI
    //         0043b2f0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0043b2f5     ADD        ESP,0x4
    //                               LAB_0043b2f8                                                 XREF[1]:     0043b2ed(j)  
    //         0043b2f8     MOV        EAX,ESI
    //         0043b2fa     POP        ESI
    //         0043b2fb     RET        0x4
}

