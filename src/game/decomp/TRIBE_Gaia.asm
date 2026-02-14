// Auto-generated scaffold unit: TRIBE_Gaia.asm
#include "../include/common.h"

// Offset: 0x00519BA0
void* TRIBE_Gaia::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Gaia::`vector deleting destructor'(unsigned int)              *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TRIBE_Gaia * this, ui
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Gaia *      ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00519ba8(R)  
    //                               ??_GTRIBE_Gaia@@UAEPAXI@Z                                    XREF[1]:     005769a0(*)  
    //                               ??_ETRIBE_Gaia@@UAEPAXI@Z
    //                               TRIBE_Gaia::`vector_deleting_destructor'
    //         00519ba0     PUSH       ESI
    //         00519ba1     MOV        ESI,this
    //         00519ba3     CALL       TRIBE_Gaia::~TRIBE_Gaia                          void ~TRIBE_Gaia(TRIBE_Gaia * this)
    //         00519ba8     TEST       byte ptr [ESP + param_1],0x1
    //         00519bad     JZ         LAB_00519bb8
    //         00519baf     PUSH       ESI
    //         00519bb0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00519bb5     ADD        ESP,0x4
    //                               LAB_00519bb8                                                 XREF[1]:     00519bad(j)  
    //         00519bb8     MOV        EAX,ESI
    //         00519bba     POP        ESI
    //         00519bbb     RET        0x4
}

