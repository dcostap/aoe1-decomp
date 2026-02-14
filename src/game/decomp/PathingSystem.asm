// Auto-generated scaffold unit: PathingSystem.asm
#include "../include/common.h"

// Offset: 0x0046B250
void* PathingSystem::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall PathingSystem::`vector deleting destructor'(unsigned int)           *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(PathingSystem * this,
    //              void *            EAX:4          <RETURN>
    //              PathingSystem *   ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0046b258(R)  
    //                               ??_GPathingSystem@@UAEPAXI@Z                                 XREF[1]:     00570e8c(*)  
    //                               ??_EPathingSystem@@UAEPAXI@Z
    //                               PathingSystem::`vector_deleting_destructor'
    //         0046b250     PUSH       ESI
    //         0046b251     MOV        ESI,this
    //         0046b253     CALL       PathingSystem::~PathingSystem                    void ~PathingSystem(PathingSystem * this)
    //         0046b258     TEST       byte ptr [ESP + param_1],0x1
    //         0046b25d     JZ         LAB_0046b268
    //         0046b25f     PUSH       ESI
    //         0046b260     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0046b265     ADD        ESP,0x4
    //                               LAB_0046b268                                                 XREF[1]:     0046b25d(j)  
    //         0046b268     MOV        EAX,ESI
    //         0046b26a     POP        ESI
    //         0046b26b     RET        0x4
}

