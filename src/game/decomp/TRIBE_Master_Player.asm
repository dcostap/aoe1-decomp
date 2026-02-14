// Auto-generated scaffold unit: TRIBE_Master_Player.asm
#include "../include/common.h"

// Offset: 0x005117E0
void* TRIBE_Master_Player::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Master_Player::`scalar deleting destructor'(unsigned int)     *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TRIBE_Master_Player *
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Master_P    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     005117e8(R)  
    //                               ??_ETRIBE_Master_Player@@UAEPAXI@Z                           XREF[1]:     00576800(*)  
    //                               ??_GTRIBE_Master_Player@@UAEPAXI@Z
    //                               TRIBE_Master_Player::`scalar_deleting_destructor'
    //         005117e0     PUSH       ESI
    //         005117e1     MOV        ESI,this
    //         005117e3     CALL       TRIBE_Master_Player::~TRIBE_Master_Player        void ~TRIBE_Master_Player(TRIBE_Master_Player
    //         005117e8     TEST       byte ptr [ESP + param_1],0x1
    //         005117ed     JZ         LAB_005117f8
    //         005117ef     PUSH       ESI
    //         005117f0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         005117f5     ADD        ESP,0x4
    //                               LAB_005117f8                                                 XREF[1]:     005117ed(j)  
    //         005117f8     MOV        EAX,ESI
    //         005117fa     POP        ESI
    //         005117fb     RET        0x4
}

