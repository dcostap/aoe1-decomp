// Auto-generated scaffold unit: TribeLoadSavedGameScreen.asm
#include "../include/common.h"

// Offset: 0x0049E080
void* TribeLoadSavedGameScreen::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TribeLoadSavedGameScreen::`vector deleting destructor'(unsigned ... *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TribeLoadSavedGameScr
    //              void *            EAX:4          <RETURN>
    //              TribeLoadSaved    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0049e088(R)  
    //                               ??_GTribeLoadSavedGameScreen@@UAEPAXI@Z                      XREF[1]:     00572e28(*)  
    //                               ??_ETribeLoadSavedGameScreen@@UAEPAXI@Z
    //                               TribeLoadSavedGameScreen::`vector_deleting_destructor'
    //         0049e080     PUSH       ESI
    //         0049e081     MOV        ESI,this
    //         0049e083     CALL       TribeLoadSavedGameScreen::~TribeLoadSavedGameS   void ~TribeLoadSavedGameScreen(TribeLoadSaved
    //         0049e088     TEST       byte ptr [ESP + param_1],0x1
    //         0049e08d     JZ         LAB_0049e098
    //         0049e08f     PUSH       ESI
    //         0049e090     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0049e095     ADD        ESP,0x4
    //                               LAB_0049e098                                                 XREF[1]:     0049e08d(j)  
    //         0049e098     MOV        EAX,ESI
    //         0049e09a     POP        ESI
    //         0049e09b     RET        0x4
}

