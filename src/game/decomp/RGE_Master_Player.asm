// Auto-generated scaffold unit: RGE_Master_Player.asm
#include "../include/common.h"

// Offset: 0x004610A0
void* RGE_Master_Player::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall RGE_Master_Player::`vector deleting destructor'(unsigned int)       *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(RGE_Master_Player * t
    //              void *            EAX:4          <RETURN>
    //              RGE_Master_Pla    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004610a8(R)  
    //                               ??_GRGE_Master_Player@@UAEPAXI@Z                             XREF[1]:     00570c08(*)  
    //                               ??_ERGE_Master_Player@@UAEPAXI@Z
    //                               RGE_Master_Player::`vector_deleting_destructor'
    //         004610a0     PUSH       ESI
    //         004610a1     MOV        ESI,this
    //         004610a3     CALL       RGE_Master_Player::~RGE_Master_Player            void ~RGE_Master_Player(RGE_Master_Player * t
    //         004610a8     TEST       byte ptr [ESP + param_1],0x1
    //         004610ad     JZ         LAB_004610b8
    //         004610af     PUSH       ESI
    //         004610b0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004610b5     ADD        ESP,0x4
    //                               LAB_004610b8                                                 XREF[1]:     004610ad(j)  
    //         004610b8     MOV        EAX,ESI
    //         004610ba     POP        ESI
    //         004610bb     RET        0x4
}

