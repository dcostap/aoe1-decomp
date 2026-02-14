// Auto-generated scaffold unit: TRIBE_World.asm
#include "../include/common.h"

// Offset: 0x0052E020
void* TRIBE_World::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_World::`scalar deleting destructor'(unsigned int)             *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TRIBE_World * this, u
    //              void *            EAX:4          <RETURN>
    //              TRIBE_World *     ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0052e028(R)  
    //                               ??_ETRIBE_World@@UAEPAXI@Z                                   XREF[1]:     005774f8(*)  
    //                               ??_GTRIBE_World@@UAEPAXI@Z
    //                               TRIBE_World::`scalar_deleting_destructor'
    //         0052e020     PUSH       ESI
    //         0052e021     MOV        ESI,this
    //         0052e023     CALL       TRIBE_World::~TRIBE_World                        void ~TRIBE_World(TRIBE_World * this)
    //         0052e028     TEST       byte ptr [ESP + param_1],0x1
    //         0052e02d     JZ         LAB_0052e038
    //         0052e02f     PUSH       ESI
    //         0052e030     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0052e035     ADD        ESP,0x4
    //                               LAB_0052e038                                                 XREF[1]:     0052e02d(j)  
    //         0052e038     MOV        EAX,ESI
    //         0052e03a     POP        ESI
    //         0052e03b     RET        0x4
}

