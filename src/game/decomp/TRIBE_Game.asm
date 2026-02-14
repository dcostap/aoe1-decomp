// Auto-generated scaffold unit: TRIBE_Game.asm
#include "../include/common.h"

// Offset: 0x00521380
void* TRIBE_Game::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Game::`vector deleting destructor'(unsigned int)              *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TRIBE_Game * this, ui
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Game *      ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00521388(R)  
    //                               ??_GTRIBE_Game@@UAEPAXI@Z                                    XREF[1]:     005771a8(*)  
    //                               ??_ETRIBE_Game@@UAEPAXI@Z
    //                               TRIBE_Game::`vector_deleting_destructor'
    //         00521380     PUSH       ESI
    //         00521381     MOV        ESI,this
    //         00521383     CALL       TRIBE_Game::~TRIBE_Game                          void ~TRIBE_Game(TRIBE_Game * this)
    //         00521388     TEST       byte ptr [ESP + param_1],0x1
    //         0052138d     JZ         LAB_00521398
    //         0052138f     PUSH       ESI
    //         00521390     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00521395     ADD        ESP,0x4
    //                               LAB_00521398                                                 XREF[1]:     0052138d(j)  
    //         00521398     MOV        EAX,ESI
    //         0052139a     POP        ESI
    //         0052139b     RET        0x4
}

