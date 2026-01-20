// Auto-generated scaffold unit: RGE_Map.cpp.asm
#include "../include/common.h"

// Offset: 0x00455080
void* RGE_Map::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall RGE_Map::`vector deleting destructor'(unsigned int)                 *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(RGE_Map * this, uint 
    //              void *            EAX:4          <RETURN>
    //              RGE_Map *         ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00455088(R)  
    //                               ??_GRGE_Map@@UAEPAXI@Z                                       XREF[1]:     00570678(*)  
    //                               ??_ERGE_Map@@UAEPAXI@Z
    //                               RGE_Map::`vector_deleting_destructor'
    //         00455080     PUSH       ESI
    //         00455081     MOV        ESI,this
    //         00455083     CALL       RGE_Map::~RGE_Map                                void ~RGE_Map(RGE_Map * this)
    //         00455088     TEST       byte ptr [ESP + param_1],0x1
    //         0045508d     JZ         LAB_00455098
    //         0045508f     PUSH       ESI
    //         00455090     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00455095     ADD        ESP,0x4
    //                               LAB_00455098                                                 XREF[1]:     0045508d(j)  
    //         00455098     MOV        EAX,ESI
    //         0045509a     POP        ESI
    //         0045509b     RET        0x4
}

