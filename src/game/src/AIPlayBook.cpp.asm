// Auto-generated scaffold unit: AIPlayBook.cpp.asm
#include "../include/common.h"

// Offset: 0x004101D0
void* AIPlayBook::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall AIPlayBook::`vector deleting destructor'(unsigned int)              *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(AIPlayBook * this, ui
    //              void *            EAX:4          <RETURN>
    //              AIPlayBook *      ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004101d8(R)  
    //                               ??_GAIPlayBook@@UAEPAXI@Z                                    XREF[1]:     0056e970(*)  
    //                               ??_EAIPlayBook@@UAEPAXI@Z
    //                               AIPlayBook::`vector_deleting_destructor'
    //         004101d0     PUSH       ESI
    //         004101d1     MOV        ESI,this
    //         004101d3     CALL       AIPlayBook::~AIPlayBook                          void ~AIPlayBook(AIPlayBook * this)
    //         004101d8     TEST       byte ptr [ESP + param_1],0x1
    //         004101dd     JZ         LAB_004101e8
    //         004101df     PUSH       ESI
    //         004101e0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004101e5     ADD        ESP,0x4
    //                               LAB_004101e8                                                 XREF[1]:     004101dd(j)  
    //         004101e8     MOV        EAX,ESI
    //         004101ea     POP        ESI
    //         004101eb     RET        0x4
}

