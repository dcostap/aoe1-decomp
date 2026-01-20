// Auto-generated scaffold unit: RGE_Animated_Object.cpp.asm
#include "../include/common.h"

// Offset: 0x0041A1E0
void* RGE_Animated_Object::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall RGE_Animated_Object::`scalar deleting destructor'(unsigned int)     *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(RGE_Animated_Object *
    //              void *            EAX:4          <RETURN>
    //              RGE_Animated_O    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0041a1e8(R)  
    //                               ??_ERGE_Animated_Object@@UAEPAXI@Z                           XREF[1]:     0056ec10(*)  
    //                               ??_GRGE_Animated_Object@@UAEPAXI@Z
    //                               RGE_Animated_Object::`scalar_deleting_destructor'
    //         0041a1e0     PUSH       ESI
    //         0041a1e1     MOV        ESI,this
    //         0041a1e3     CALL       RGE_Animated_Object::~RGE_Animated_Object        void ~RGE_Animated_Object(RGE_Animated_Object
    //         0041a1e8     TEST       byte ptr [ESP + param_1],0x1
    //         0041a1ed     JZ         LAB_0041a1f8
    //         0041a1ef     PUSH       ESI
    //         0041a1f0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0041a1f5     ADD        ESP,0x4
    //                               LAB_0041a1f8                                                 XREF[1]:     0041a1ed(j)  
    //         0041a1f8     MOV        EAX,ESI
    //         0041a1fa     POP        ESI
    //         0041a1fb     RET        0x4
}

