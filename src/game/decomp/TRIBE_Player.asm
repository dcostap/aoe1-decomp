// Auto-generated scaffold unit: TRIBE_Player.asm
#include "../include/common.h"

// Offset: 0x00511E00
void* TRIBE_Player::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Player::`vector deleting destructor'(unsigned int)            *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TRIBE_Player * this, 
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Player *    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00511e08(R)  
    //                               ??_GTRIBE_Player@@UAEPAXI@Z                                  XREF[1]:     00576870(*)  
    //                               ??_ETRIBE_Player@@UAEPAXI@Z
    //                               TRIBE_Player::`vector_deleting_destructor'
    //         00511e00     PUSH       ESI
    //         00511e01     MOV        ESI,this
    //         00511e03     CALL       TRIBE_Player::~TRIBE_Player                      void ~TRIBE_Player(TRIBE_Player * this)
    //         00511e08     TEST       byte ptr [ESP + param_1],0x1
    //         00511e0d     JZ         LAB_00511e18
    //         00511e0f     PUSH       ESI
    //         00511e10     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00511e15     ADD        ESP,0x4
    //                               LAB_00511e18                                                 XREF[1]:     00511e0d(j)  
    //         00511e18     MOV        EAX,ESI
    //         00511e1a     POP        ESI
    //         00511e1b     RET        0x4
}

