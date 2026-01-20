// Auto-generated scaffold unit: TRIBE_Action_Wonder.cpp.asm
#include "../include/common.h"

// Offset: 0x004D34A0
void* TRIBE_Action_Wonder::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Action_Wonder::`vector deleting destructor'(unsigned int)     *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TRIBE_Action_Wonder *
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Action_W    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004d34a8(R)  
    //                               ??_GTRIBE_Action_Wonder@@UAEPAXI@Z                           XREF[1]:     00575378(*)  
    //                               ??_ETRIBE_Action_Wonder@@UAEPAXI@Z
    //                               TRIBE_Action_Wonder::`vector_deleting_destructor'
    //         004d34a0     PUSH       ESI
    //         004d34a1     MOV        ESI,this
    //         004d34a3     CALL       TRIBE_Action_Wonder::~TRIBE_Action_Wonder        void ~TRIBE_Action_Wonder(TRIBE_Action_Wonder
    //         004d34a8     TEST       byte ptr [ESP + param_1],0x1
    //         004d34ad     JZ         LAB_004d34b8
    //         004d34af     PUSH       ESI
    //         004d34b0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004d34b5     ADD        ESP,0x4
    //                               LAB_004d34b8                                                 XREF[1]:     004d34ad(j)  
    //         004d34b8     MOV        EAX,ESI
    //         004d34ba     POP        ESI
    //         004d34bb     RET        0x4
}

