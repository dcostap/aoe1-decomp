// Auto-generated scaffold unit: TRIBE_Screen_Wait.cpp.asm
#include "../include/common.h"

// Offset: 0x004A6030
void* TRIBE_Screen_Wait::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Screen_Wait::`scalar deleting destructor'(unsigned int)       *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TRIBE_Screen_Wait * t
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Screen_W    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004a6038(R)  
    //                               ??_ETRIBE_Screen_Wait@@UAEPAXI@Z                             XREF[1]:     005733f0(*)  
    //                               ??_GTRIBE_Screen_Wait@@UAEPAXI@Z
    //                               TRIBE_Screen_Wait::`scalar_deleting_destructor'
    //         004a6030     PUSH       ESI
    //         004a6031     MOV        ESI,this
    //         004a6033     CALL       TRIBE_Screen_Wait::~TRIBE_Screen_Wait            void ~TRIBE_Screen_Wait(TRIBE_Screen_Wait * t
    //         004a6038     TEST       byte ptr [ESP + param_1],0x1
    //         004a603d     JZ         LAB_004a6048
    //         004a603f     PUSH       ESI
    //         004a6040     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004a6045     ADD        ESP,0x4
    //                               LAB_004a6048                                                 XREF[1]:     004a603d(j)  
    //         004a6048     MOV        EAX,ESI
    //         004a604a     POP        ESI
    //         004a604b     RET        0x4
}

