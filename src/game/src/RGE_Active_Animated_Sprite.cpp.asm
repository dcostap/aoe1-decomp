// Auto-generated scaffold unit: RGE_Active_Animated_Sprite.cpp.asm
#include "../include/common.h"

// Offset: 0x0041B120
void* RGE_Active_Animated_Sprite::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall RGE_Active_Animated_Sprite::`vector deleting destructor'(unsigne... *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(RGE_Active_Animated_S
    //              void *            EAX:4          <RETURN>
    //              RGE_Active_Ani    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0041b128(R)  
    //                               ??_GRGE_Active_Animated_Sprite@@UAEPAXI@Z                    XREF[1]:     0056ee90(*)  
    //                               ??_ERGE_Active_Animated_Sprite@@UAEPAXI@Z
    //                               RGE_Active_Animated_Sprite::`vector_deleting_destructor'
    //         0041b120     PUSH       ESI
    //         0041b121     MOV        ESI,this
    //         0041b123     CALL       RGE_Active_Animated_Sprite::~RGE_Active_Animat   void ~RGE_Active_Animated_Sprite(RGE_Active_A
    //         0041b128     TEST       byte ptr [ESP + param_1],0x1
    //         0041b12d     JZ         LAB_0041b138
    //         0041b12f     PUSH       ESI
    //         0041b130     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0041b135     ADD        ESP,0x4
    //                               LAB_0041b138                                                 XREF[1]:     0041b12d(j)  
    //         0041b138     MOV        EAX,ESI
    //         0041b13a     POP        ESI
    //         0041b13b     RET        0x4
}

