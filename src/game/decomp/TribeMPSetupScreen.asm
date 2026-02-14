// Auto-generated scaffold unit: TribeMPSetupScreen.asm
#include "../include/common.h"

// Offset: 0x004A0D60
void* TribeMPSetupScreen::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TribeMPSetupScreen::`vector deleting destructor'(unsigned int)      *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TribeMPSetupScreen * 
    //              void *            EAX:4          <RETURN>
    //              TribeMPSetupSc    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004a0d68(R)  
    //                               ??_GTribeMPSetupScreen@@UAEPAXI@Z                            XREF[1]:     005732c8(*)  
    //                               ??_ETribeMPSetupScreen@@UAEPAXI@Z
    //                               TribeMPSetupScreen::`vector_deleting_destructor'
    //         004a0d60     PUSH       ESI
    //         004a0d61     MOV        ESI,this
    //         004a0d63     CALL       TribeMPSetupScreen::~TribeMPSetupScreen          void ~TribeMPSetupScreen(TribeMPSetupScreen *
    //         004a0d68     TEST       byte ptr [ESP + param_1],0x1
    //         004a0d6d     JZ         LAB_004a0d78
    //         004a0d6f     PUSH       ESI
    //         004a0d70     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004a0d75     ADD        ESP,0x4
    //                               LAB_004a0d78                                                 XREF[1]:     004a0d6d(j)  
    //         004a0d78     MOV        EAX,ESI
    //         004a0d7a     POP        ESI
    //         004a0d7b     RET        0x4
}

