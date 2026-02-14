// Auto-generated scaffold unit: TRIBE_Action_Build.asm
#include "../include/common.h"

// Offset: 0x004CD1E0
void* TRIBE_Action_Build::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Action_Build::`vector deleting destructor'(unsigned int)      *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TRIBE_Action_Build * 
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Action_B    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004cd1e8(R)  
    //                               ??_GTRIBE_Action_Build@@UAEPAXI@Z                            XREF[1]:     00574f18(*)  
    //                               ??_ETRIBE_Action_Build@@UAEPAXI@Z
    //                               TRIBE_Action_Build::`vector_deleting_destructor'
    //         004cd1e0     PUSH       ESI
    //         004cd1e1     MOV        ESI,this
    //         004cd1e3     CALL       TRIBE_Action_Build::~TRIBE_Action_Build          void ~TRIBE_Action_Build(TRIBE_Action_Build *
    //         004cd1e8     TEST       byte ptr [ESP + param_1],0x1
    //         004cd1ed     JZ         LAB_004cd1f8
    //         004cd1ef     PUSH       ESI
    //         004cd1f0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004cd1f5     ADD        ESP,0x4
    //                               LAB_004cd1f8                                                 XREF[1]:     004cd1ed(j)  
    //         004cd1f8     MOV        EAX,ESI
    //         004cd1fa     POP        ESI
    //         004cd1fb     RET        0x4
}

