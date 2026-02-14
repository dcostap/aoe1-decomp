// Auto-generated scaffold unit: TribeSPMenuScreen.asm
#include "../include/common.h"

// Offset: 0x004B6BE0
void* TribeSPMenuScreen::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TribeSPMenuScreen::`vector deleting destructor'(unsigned int)       *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TribeSPMenuScreen * t
    //              void *            EAX:4          <RETURN>
    //              TribeSPMenuScr    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004b6be8(R)  
    //                               ??_GTribeSPMenuScreen@@UAEPAXI@Z                             XREF[1]:     00573fa0(*)  
    //                               ??_ETribeSPMenuScreen@@UAEPAXI@Z
    //                               TribeSPMenuScreen::`vector_deleting_destructor'
    //         004b6be0     PUSH       ESI
    //         004b6be1     MOV        ESI,this
    //         004b6be3     CALL       TribeSPMenuScreen::~TribeSPMenuScreen            void ~TribeSPMenuScreen(TribeSPMenuScreen * t
    //         004b6be8     TEST       byte ptr [ESP + param_1],0x1
    //         004b6bed     JZ         LAB_004b6bf8
    //         004b6bef     PUSH       ESI
    //         004b6bf0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004b6bf5     ADD        ESP,0x4
    //                               LAB_004b6bf8                                                 XREF[1]:     004b6bed(j)  
    //         004b6bf8     MOV        EAX,ESI
    //         004b6bfa     POP        ESI
    //         004b6bfb     RET        0x4
}

