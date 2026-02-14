// Auto-generated scaffold unit: TRIBE_Map.asm
#include "../include/common.h"

// Offset: 0x0050F740
void* TRIBE_Map::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Map::`scalar deleting destructor'(unsigned int)               *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TRIBE_Map * this, uin
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Map *       ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0050f748(R)  
    //                               ??_ETRIBE_Map@@UAEPAXI@Z                                     XREF[1]:     005767c8(*)  
    //                               ??_GTRIBE_Map@@UAEPAXI@Z
    //                               TRIBE_Map::`scalar_deleting_destructor'
    //         0050f740     PUSH       ESI
    //         0050f741     MOV        ESI,this
    //         0050f743     CALL       TRIBE_Map::~TRIBE_Map                            void ~TRIBE_Map(TRIBE_Map * this)
    //         0050f748     TEST       byte ptr [ESP + param_1],0x1
    //         0050f74d     JZ         LAB_0050f758
    //         0050f74f     PUSH       ESI
    //         0050f750     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0050f755     ADD        ESP,0x4
    //                               LAB_0050f758                                                 XREF[1]:     0050f74d(j)  
    //         0050f758     MOV        EAX,ESI
    //         0050f75a     POP        ESI
    //         0050f75b     RET        0x4
}

