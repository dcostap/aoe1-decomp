// Auto-generated scaffold unit: TribeMPStartupScreen.asm
#include "../include/common.h"

// Offset: 0x0049F870
void* TribeMPStartupScreen::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TribeMPStartupScreen::`vector deleting destructor'(unsigned int)    *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TribeMPStartupScreen 
    //              void *            EAX:4          <RETURN>
    //              TribeMPStartup    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0049f878(R)  
    //                               ??_GTribeMPStartupScreen@@UAEPAXI@Z                          XREF[1]:     005731a0(*)  
    //                               ??_ETribeMPStartupScreen@@UAEPAXI@Z
    //                               TribeMPStartupScreen::`vector_deleting_destructor'
    //         0049f870     PUSH       ESI
    //         0049f871     MOV        ESI,this
    //         0049f873     CALL       TribeMPStartupScreen::~TribeMPStartupScreen      void ~TribeMPStartupScreen(TribeMPStartupScre
    //         0049f878     TEST       byte ptr [ESP + param_1],0x1
    //         0049f87d     JZ         LAB_0049f888
    //         0049f87f     PUSH       ESI
    //         0049f880     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0049f885     ADD        ESP,0x4
    //                               LAB_0049f888                                                 XREF[1]:     0049f87d(j)  
    //         0049f888     MOV        EAX,ESI
    //         0049f88a     POP        ESI
    //         0049f88b     RET        0x4
}

