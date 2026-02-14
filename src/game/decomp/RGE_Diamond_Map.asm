// Auto-generated scaffold unit: RGE_Diamond_Map.asm
#include "../include/common.h"

// Offset: 0x00436910
void* RGE_Diamond_Map::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall RGE_Diamond_Map::`vector deleting destructor'(unsigned int)         *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(RGE_Diamond_Map * thi
    //              void *            EAX:4          <RETURN>
    //              RGE_Diamond_Ma    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00436918(R)  
    //                               ??_GRGE_Diamond_Map@@UAEPAXI@Z                               XREF[1]:     0056f508(*)  
    //                               ??_ERGE_Diamond_Map@@UAEPAXI@Z
    //                               RGE_Diamond_Map::`vector_deleting_destructor'
    //         00436910     PUSH       ESI
    //         00436911     MOV        ESI,this
    //         00436913     CALL       RGE_Diamond_Map::~RGE_Diamond_Map                void ~RGE_Diamond_Map(RGE_Diamond_Map * this)
    //         00436918     TEST       byte ptr [ESP + param_1],0x1
    //         0043691d     JZ         LAB_00436928
    //         0043691f     PUSH       ESI
    //         00436920     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00436925     ADD        ESP,0x4
    //                               LAB_00436928                                                 XREF[1]:     0043691d(j)  
    //         00436928     MOV        EAX,ESI
    //         0043692a     POP        ESI
    //         0043692b     RET        0x4
}

