// Auto-generated scaffold unit: TribeSelectTribeScreen.cpp.asm
#include "../include/common.h"

// Offset: 0x004B7DD0
void* TribeSelectTribeScreen::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TribeSelectTribeScreen::`scalar deleting destructor'(unsigned int)  *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TribeSelectTribeScree
    //              void *            EAX:4          <RETURN>
    //              TribeSelectTri    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004b7dd8(R)  
    //                               ??_ETribeSelectTribeScreen@@UAEPAXI@Z                        XREF[1]:     005741f0(*)  
    //                               ??_GTribeSelectTribeScreen@@UAEPAXI@Z
    //                               TribeSelectTribeScreen::`scalar_deleting_destructor'
    //         004b7dd0     PUSH       ESI
    //         004b7dd1     MOV        ESI,this
    //         004b7dd3     CALL       TribeSelectTribeScreen::~TribeSelectTribeScreen  void ~TribeSelectTribeScreen(TribeSelectTribe
    //         004b7dd8     TEST       byte ptr [ESP + param_1],0x1
    //         004b7ddd     JZ         LAB_004b7de8
    //         004b7ddf     PUSH       ESI
    //         004b7de0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004b7de5     ADD        ESP,0x4
    //                               LAB_004b7de8                                                 XREF[1]:     004b7ddd(j)  
    //         004b7de8     MOV        EAX,ESI
    //         004b7dea     POP        ESI
    //         004b7deb     RET        0x4
}

