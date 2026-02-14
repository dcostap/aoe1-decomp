// Auto-generated scaffold unit: RGE_Combat_Object.asm
#include "../include/common.h"

// Offset: 0x0042F9C0
void* RGE_Combat_Object::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall RGE_Combat_Object::`vector deleting destructor'(unsigned int)       *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(RGE_Combat_Object * t
    //              void *            EAX:4          <RETURN>
    //              RGE_Combat_Obj    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0042f9c8(R)  
    //                               ??_GRGE_Combat_Object@@UAEPAXI@Z                             XREF[1]:     0056f258(*)  
    //                               ??_ERGE_Combat_Object@@UAEPAXI@Z
    //                               RGE_Combat_Object::`vector_deleting_destructor'
    //         0042f9c0     PUSH       ESI
    //         0042f9c1     MOV        ESI,this
    //         0042f9c3     CALL       RGE_Combat_Object::~RGE_Combat_Object            void ~RGE_Combat_Object(RGE_Combat_Object * t
    //         0042f9c8     TEST       byte ptr [ESP + param_1],0x1
    //         0042f9cd     JZ         LAB_0042f9d8
    //         0042f9cf     PUSH       ESI
    //         0042f9d0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0042f9d5     ADD        ESP,0x4
    //                               LAB_0042f9d8                                                 XREF[1]:     0042f9cd(j)  
    //         0042f9d8     MOV        EAX,ESI
    //         0042f9da     POP        ESI
    //         0042f9db     RET        0x4
}

