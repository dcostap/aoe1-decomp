// Auto-generated scaffold unit: TRIBE_Action_Discovery_Artifact.cpp.asm
#include "../include/common.h"

// Offset: 0x004CE5C0
void* TRIBE_Action_Discovery_Artifact::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Action_Discovery_Artifact::`vector deleting destructor'(un... *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TRIBE_Action_Discover
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Action_D    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004ce5c8(R)  
    //                               ??_GTRIBE_Action_Discovery_Artifact@@UAEPAXI@Z               XREF[1]:     00575010(*)  
    //                               ??_ETRIBE_Action_Discovery_Artifact@@UAEPAXI@Z
    //                               TRIBE_Action_Discovery_Artifact::`vector_deleting_destructor'
    //         004ce5c0     PUSH       ESI
    //         004ce5c1     MOV        ESI,this
    //         004ce5c3     CALL       TRIBE_Action_Discovery_Artifact::~TRIBE_Action   void ~TRIBE_Action_Discovery_Artifact(TRIBE_A
    //         004ce5c8     TEST       byte ptr [ESP + param_1],0x1
    //         004ce5cd     JZ         LAB_004ce5d8
    //         004ce5cf     PUSH       ESI
    //         004ce5d0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004ce5d5     ADD        ESP,0x4
    //                               LAB_004ce5d8                                                 XREF[1]:     004ce5cd(j)  
    //         004ce5d8     MOV        EAX,ESI
    //         004ce5da     POP        ESI
    //         004ce5db     RET        0x4
}

