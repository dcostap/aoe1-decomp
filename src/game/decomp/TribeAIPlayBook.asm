// Auto-generated scaffold unit: TribeAIPlayBook.asm
#include "../include/common.h"

// Offset: 0x004E68D0
void* TribeAIPlayBook::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TribeAIPlayBook::`vector deleting destructor'(unsigned int)         *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TribeAIPlayBook * thi
    //              void *            EAX:4          <RETURN>
    //              TribeAIPlayBoo    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004e68d8(R)  
    //                               ??_GTribeAIPlayBook@@UAEPAXI@Z                               XREF[1]:     00575620(*)  
    //                               ??_ETribeAIPlayBook@@UAEPAXI@Z
    //                               TribeAIPlayBook::`vector_deleting_destructor'
    //         004e68d0     PUSH       ESI
    //         004e68d1     MOV        ESI,this
    //         004e68d3     CALL       TribeAIPlayBook::~TribeAIPlayBook                void ~TribeAIPlayBook(TribeAIPlayBook * this)
    //         004e68d8     TEST       byte ptr [ESP + param_1],0x1
    //         004e68dd     JZ         LAB_004e68e8
    //         004e68df     PUSH       ESI
    //         004e68e0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004e68e5     ADD        ESP,0x4
    //                               LAB_004e68e8                                                 XREF[1]:     004e68dd(j)  
    //         004e68e8     MOV        EAX,ESI
    //         004e68ea     POP        ESI
    //         004e68eb     RET        0x4
}

