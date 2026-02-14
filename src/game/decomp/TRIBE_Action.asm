// Auto-generated scaffold unit: TRIBE_Action.asm
#include "../include/common.h"

// Offset: 0x004D3950
void* TRIBE_Action::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Action::`vector deleting destructor'(unsigned int)            *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TRIBE_Action * this, 
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Action *    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004d3958(R)  
    //                               ??_GTRIBE_Action@@UAEPAXI@Z                                  XREF[1]:     005753e0(*)  
    //                               ??_ETRIBE_Action@@UAEPAXI@Z
    //                               TRIBE_Action::`vector_deleting_destructor'
    //         004d3950     PUSH       ESI
    //         004d3951     MOV        ESI,this
    //         004d3953     CALL       TRIBE_Action::~TRIBE_Action                      void ~TRIBE_Action(TRIBE_Action * this)
    //         004d3958     TEST       byte ptr [ESP + param_1],0x1
    //         004d395d     JZ         LAB_004d3968
    //         004d395f     PUSH       ESI
    //         004d3960     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004d3965     ADD        ESP,0x4
    //                               LAB_004d3968                                                 XREF[1]:     004d395d(j)  
    //         004d3968     MOV        EAX,ESI
    //         004d396a     POP        ESI
    //         004d396b     RET        0x4
}

