// Auto-generated scaffold unit: TribeSaveGameScreen.cpp.asm
#include "../include/common.h"

// Offset: 0x004A75A0
void* TribeSaveGameScreen::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TribeSaveGameScreen::`vector deleting destructor'(unsigned int)     *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TribeSaveGameScreen *
    //              void *            EAX:4          <RETURN>
    //              TribeSaveGameS    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004a75a8(R)  
    //                               ??_GTribeSaveGameScreen@@UAEPAXI@Z                           XREF[1]:     00573898(*)  
    //                               ??_ETribeSaveGameScreen@@UAEPAXI@Z
    //                               TribeSaveGameScreen::`vector_deleting_destructor'
    //         004a75a0     PUSH       ESI
    //         004a75a1     MOV        ESI,this
    //         004a75a3     CALL       TribeSaveGameScreen::~TribeSaveGameScreen        void ~TribeSaveGameScreen(TribeSaveGameScreen
    //         004a75a8     TEST       byte ptr [ESP + param_1],0x1
    //         004a75ad     JZ         LAB_004a75b8
    //         004a75af     PUSH       ESI
    //         004a75b0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004a75b5     ADD        ESP,0x4
    //                               LAB_004a75b8                                                 XREF[1]:     004a75ad(j)  
    //         004a75b8     MOV        EAX,ESI
    //         004a75ba     POP        ESI
    //         004a75bb     RET        0x4
}

