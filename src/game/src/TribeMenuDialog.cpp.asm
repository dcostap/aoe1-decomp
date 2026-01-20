// Auto-generated scaffold unit: TribeMenuDialog.cpp.asm
#include "../include/common.h"

// Offset: 0x0043F690
void* TribeMenuDialog::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TribeMenuDialog::`scalar deleting destructor'(unsigned int)         *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TribeMenuDialog * thi
    //              void *            EAX:4          <RETURN>
    //              TribeMenuDialo    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0043f698(R)  
    //                               ??_ETribeMenuDialog@@UAEPAXI@Z                               XREF[1]:     0056fc30(*)  
    //                               ??_GTribeMenuDialog@@UAEPAXI@Z
    //                               TribeMenuDialog::`scalar_deleting_destructor'
    //         0043f690     PUSH       ESI
    //         0043f691     MOV        ESI,this
    //         0043f693     CALL       TribeMenuDialog::~TribeMenuDialog                void ~TribeMenuDialog(TribeMenuDialog * this)
    //         0043f698     TEST       byte ptr [ESP + param_1],0x1
    //         0043f69d     JZ         LAB_0043f6a8
    //         0043f69f     PUSH       ESI
    //         0043f6a0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0043f6a5     ADD        ESP,0x4
    //                               LAB_0043f6a8                                                 XREF[1]:     0043f69d(j)  
    //         0043f6a8     MOV        EAX,ESI
    //         0043f6aa     POP        ESI
    //         0043f6ab     RET        0x4
}

