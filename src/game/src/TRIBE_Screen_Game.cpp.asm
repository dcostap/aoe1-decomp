// Auto-generated scaffold unit: TRIBE_Screen_Game.cpp.asm
#include "../include/common.h"

// Offset: 0x00495450
void* TRIBE_Screen_Game::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Screen_Game::`vector deleting destructor'(unsigned int)       *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TRIBE_Screen_Game * t
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Screen_G    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00495458(R)  
    //                               ??_GTRIBE_Screen_Game@@UAEPAXI@Z                             XREF[1]:     00572bb8(*)  
    //                               ??_ETRIBE_Screen_Game@@UAEPAXI@Z
    //                               TRIBE_Screen_Game::`vector_deleting_destructor'
    //         00495450     PUSH       ESI
    //         00495451     MOV        ESI,this
    //         00495453     CALL       TRIBE_Screen_Game::~TRIBE_Screen_Game            void ~TRIBE_Screen_Game(TRIBE_Screen_Game * t
    //         00495458     TEST       byte ptr [ESP + param_1],0x1
    //         0049545d     JZ         LAB_00495468
    //         0049545f     PUSH       ESI
    //         00495460     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00495465     ADD        ESP,0x4
    //                               LAB_00495468                                                 XREF[1]:     0049545d(j)  
    //         00495468     MOV        EAX,ESI
    //         0049546a     POP        ESI
    //         0049546b     RET        0x4
}

