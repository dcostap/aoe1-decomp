// Auto-generated scaffold unit: TribeJoinScreen.asm
#include "../include/common.h"

// Offset: 0x00491970
void* TribeJoinScreen::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TribeJoinScreen::`scalar deleting destructor'(unsigned int)         *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TribeJoinScreen * thi
    //              void *            EAX:4          <RETURN>
    //              TribeJoinScree    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00491978(R)  
    //                               ??_ETribeJoinScreen@@UAEPAXI@Z                               XREF[1]:     005724f8(*)  
    //                               ??_GTribeJoinScreen@@UAEPAXI@Z
    //                               TribeJoinScreen::`scalar_deleting_destructor'
    //         00491970     PUSH       ESI
    //         00491971     MOV        ESI,this
    //         00491973     CALL       TribeJoinScreen::~TribeJoinScreen                void ~TribeJoinScreen(TribeJoinScreen * this)
    //         00491978     TEST       byte ptr [ESP + param_1],0x1
    //         0049197d     JZ         LAB_00491988
    //         0049197f     PUSH       ESI
    //         00491980     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00491985     ADD        ESP,0x4
    //                               LAB_00491988                                                 XREF[1]:     0049197d(j)  
    //         00491988     MOV        EAX,ESI
    //         0049198a     POP        ESI
    //         0049198b     RET        0x4
}

