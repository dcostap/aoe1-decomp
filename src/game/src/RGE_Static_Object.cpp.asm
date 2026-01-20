// Auto-generated scaffold unit: RGE_Static_Object.cpp.asm
#include "../include/common.h"

// Offset: 0x004C11C0
void* RGE_Static_Object::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall RGE_Static_Object::`scalar deleting destructor'(unsigned int)       *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(RGE_Static_Object * t
    //              void *            EAX:4          <RETURN>
    //              RGE_Static_Obj    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004c11c8(R)  
    //                               ??_ERGE_Static_Object@@UAEPAXI@Z                             XREF[1]:     00574530(*)  
    //                               ??_GRGE_Static_Object@@UAEPAXI@Z
    //                               RGE_Static_Object::`scalar_deleting_destructor'
    //         004c11c0     PUSH       ESI
    //         004c11c1     MOV        ESI,this
    //         004c11c3     CALL       RGE_Static_Object::~RGE_Static_Object            void ~RGE_Static_Object(RGE_Static_Object * t
    //         004c11c8     TEST       byte ptr [ESP + param_1],0x1
    //         004c11cd     JZ         LAB_004c11d8
    //         004c11cf     PUSH       ESI
    //         004c11d0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004c11d5     ADD        ESP,0x4
    //                               LAB_004c11d8                                                 XREF[1]:     004c11cd(j)  
    //         004c11d8     MOV        EAX,ESI
    //         004c11da     POP        ESI
    //         004c11db     RET        0x4
}

