// Auto-generated scaffold unit: TribeGameSettingsScreen.cpp.asm
#include "../include/common.h"

// Offset: 0x004B57F0
void* TribeGameSettingsScreen::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TribeGameSettingsScreen::`vector deleting destructor'(unsigned int) *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TribeGameSettingsScre
    //              void *            EAX:4          <RETURN>
    //              TribeGameSetti    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004b57f8(R)  
    //                               ??_GTribeGameSettingsScreen@@UAEPAXI@Z                       XREF[1]:     00573e78(*)  
    //                               ??_ETribeGameSettingsScreen@@UAEPAXI@Z
    //                               TribeGameSettingsScreen::`vector_deleting_destructor'
    //         004b57f0     PUSH       ESI
    //         004b57f1     MOV        ESI,this
    //         004b57f3     CALL       TribeGameSettingsScreen::~TribeGameSettingsScr   void ~TribeGameSettingsScreen(TribeGameSettin
    //         004b57f8     TEST       byte ptr [ESP + param_1],0x1
    //         004b57fd     JZ         LAB_004b5808
    //         004b57ff     PUSH       ESI
    //         004b5800     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004b5805     ADD        ESP,0x4
    //                               LAB_004b5808                                                 XREF[1]:     004b57fd(j)  
    //         004b5808     MOV        EAX,ESI
    //         004b580a     POP        ESI
    //         004b580b     RET        0x4
}

