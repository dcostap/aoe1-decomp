// Auto-generated scaffold unit: TribeConfigDialog.cpp.asm
#include "../include/common.h"

// Offset: 0x0043C0A0
void* TribeConfigDialog::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TribeConfigDialog::`scalar deleting destructor'(unsigned int)       *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TribeConfigDialog * t
    //              void *            EAX:4          <RETURN>
    //              TribeConfigDia    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0043c0a8(R)  
    //                               ??_ETribeConfigDialog@@UAEPAXI@Z                             XREF[1]:     0056f750(*)  
    //                               ??_GTribeConfigDialog@@UAEPAXI@Z
    //                               TribeConfigDialog::`scalar_deleting_destructor'
    //         0043c0a0     PUSH       ESI
    //         0043c0a1     MOV        ESI,this
    //         0043c0a3     CALL       TribeConfigDialog::~TribeConfigDialog            void ~TribeConfigDialog(TribeConfigDialog * t
    //         0043c0a8     TEST       byte ptr [ESP + param_1],0x1
    //         0043c0ad     JZ         LAB_0043c0b8
    //         0043c0af     PUSH       ESI
    //         0043c0b0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0043c0b5     ADD        ESP,0x4
    //                               LAB_0043c0b8                                                 XREF[1]:     0043c0ad(j)  
    //         0043c0b8     MOV        EAX,ESI
    //         0043c0ba     POP        ESI
    //         0043c0bb     RET        0x4
}

