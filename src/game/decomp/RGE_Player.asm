// Auto-generated scaffold unit: RGE_Player.asm
#include "../include/common.h"

// Offset: 0x0046E750
void* RGE_Player::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall RGE_Player::`scalar deleting destructor'(unsigned int)              *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(RGE_Player * this, ui
    //              void *            EAX:4          <RETURN>
    //              RGE_Player *      ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0046e758(R)  
    //                               ??_ERGE_Player@@UAEPAXI@Z                                    XREF[1]:     00570ed0(*)  
    //                               ??_GRGE_Player@@UAEPAXI@Z
    //                               RGE_Player::`scalar_deleting_destructor'
    //         0046e750     PUSH       ESI
    //         0046e751     MOV        ESI,this
    //         0046e753     CALL       RGE_Player::~RGE_Player                          void ~RGE_Player(RGE_Player * this)
    //         0046e758     TEST       byte ptr [ESP + param_1],0x1
    //         0046e75d     JZ         LAB_0046e768
    //         0046e75f     PUSH       ESI
    //         0046e760     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0046e765     ADD        ESP,0x4
    //                               LAB_0046e768                                                 XREF[1]:     0046e75d(j)  
    //         0046e768     MOV        EAX,ESI
    //         0046e76a     POP        ESI
    //         0046e76b     RET        0x4
}

