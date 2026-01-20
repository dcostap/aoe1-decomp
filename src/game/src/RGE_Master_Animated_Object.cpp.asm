// Auto-generated scaffold unit: RGE_Master_Animated_Object.cpp.asm
#include "../include/common.h"

// Offset: 0x0044FA20
void* RGE_Master_Animated_Object::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall RGE_Master_Animated_Object::`vector deleting destructor'(unsigne... *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(RGE_Master_Animated_O
    //              void *            EAX:4          <RETURN>
    //              RGE_Master_Ani    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0044fa28(R)  
    //                               ??_GRGE_Master_Animated_Object@@UAEPAXI@Z                    XREF[1]:     00570488(*)  
    //                               ??_ERGE_Master_Animated_Object@@UAEPAXI@Z
    //                               RGE_Master_Animated_Object::`vector_deleting_destructor'
    //         0044fa20     PUSH       ESI
    //         0044fa21     MOV        ESI,this
    //         0044fa23     CALL       RGE_Master_Animated_Object::~RGE_Master_Animat   void ~RGE_Master_Animated_Object(RGE_Master_A
    //         0044fa28     TEST       byte ptr [ESP + param_1],0x1
    //         0044fa2d     JZ         LAB_0044fa38
    //         0044fa2f     PUSH       ESI
    //         0044fa30     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0044fa35     ADD        ESP,0x4
    //                               LAB_0044fa38                                                 XREF[1]:     0044fa2d(j)  
    //         0044fa38     MOV        EAX,ESI
    //         0044fa3a     POP        ESI
    //         0044fa3b     RET        0x4
}

