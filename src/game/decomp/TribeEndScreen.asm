// Auto-generated scaffold unit: TribeEndScreen.asm
#include "../include/common.h"

// Offset: 0x00493BE0
void* TribeEndScreen::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TribeEndScreen::`scalar deleting destructor'(unsigned int)          *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TribeEndScreen * this
    //              void *            EAX:4          <RETURN>
    //              TribeEndScreen    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00493be8(R)  
    //                               ??_ETribeEndScreen@@UAEPAXI@Z                                XREF[1]:     00572980(*)  
    //                               ??_GTribeEndScreen@@UAEPAXI@Z
    //                               TribeEndScreen::`scalar_deleting_destructor'
    //         00493be0     PUSH       ESI
    //         00493be1     MOV        ESI,this
    //         00493be3     CALL       TribeEndScreen::~TribeEndScreen                  void ~TribeEndScreen(TribeEndScreen * this)
    //         00493be8     TEST       byte ptr [ESP + param_1],0x1
    //         00493bed     JZ         LAB_00493bf8
    //         00493bef     PUSH       ESI
    //         00493bf0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00493bf5     ADD        ESP,0x4
    //                               LAB_00493bf8                                                 XREF[1]:     00493bed(j)  
    //         00493bf8     MOV        EAX,ESI
    //         00493bfa     POP        ESI
    //         00493bfb     RET        0x4
}

