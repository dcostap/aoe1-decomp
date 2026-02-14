// Auto-generated scaffold unit: TRIBE_Effects.asm
#include "../include/common.h"

// Offset: 0x0050D480
void* TRIBE_Effects::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Effects::`vector deleting destructor'(unsigned int)           *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TRIBE_Effects * this,
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Effects *   ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0050d488(R)  
    //                               ??_GTRIBE_Effects@@UAEPAXI@Z                                 XREF[1]:     005766e8(*)  
    //                               ??_ETRIBE_Effects@@UAEPAXI@Z
    //                               TRIBE_Effects::`vector_deleting_destructor'
    //         0050d480     PUSH       ESI
    //         0050d481     MOV        ESI,this
    //         0050d483     CALL       TRIBE_Effects::~TRIBE_Effects                    void ~TRIBE_Effects(TRIBE_Effects * this)
    //         0050d488     TEST       byte ptr [ESP + param_1],0x1
    //         0050d48d     JZ         LAB_0050d498
    //         0050d48f     PUSH       ESI
    //         0050d490     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0050d495     ADD        ESP,0x4
    //                               LAB_0050d498                                                 XREF[1]:     0050d48d(j)  
    //         0050d498     MOV        EAX,ESI
    //         0050d49a     POP        ESI
    //         0050d49b     RET        0x4
}

