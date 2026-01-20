// Auto-generated scaffold unit: TRIBE_Action_Artifact.cpp.asm
#include "../include/common.h"

// Offset: 0x004CCBD0
void* TRIBE_Action_Artifact::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Action_Artifact::`vector deleting destructor'(unsigned int)   *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TRIBE_Action_Artifact
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Action_A    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004ccbd8(R)  
    //                               ??_GTRIBE_Action_Artifact@@UAEPAXI@Z                         XREF[1]:     00574ea8(*)  
    //                               ??_ETRIBE_Action_Artifact@@UAEPAXI@Z
    //                               TRIBE_Action_Artifact::`vector_deleting_destructor'
    //         004ccbd0     PUSH       ESI
    //         004ccbd1     MOV        ESI,this
    //         004ccbd3     CALL       TRIBE_Action_Artifact::~TRIBE_Action_Artifact    void ~TRIBE_Action_Artifact(TRIBE_Action_Arti
    //         004ccbd8     TEST       byte ptr [ESP + param_1],0x1
    //         004ccbdd     JZ         LAB_004ccbe8
    //         004ccbdf     PUSH       ESI
    //         004ccbe0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004ccbe5     ADD        ESP,0x4
    //                               LAB_004ccbe8                                                 XREF[1]:     004ccbdd(j)  
    //         004ccbe8     MOV        EAX,ESI
    //         004ccbea     POP        ESI
    //         004ccbeb     RET        0x4
}

