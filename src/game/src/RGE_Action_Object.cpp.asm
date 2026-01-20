// Auto-generated scaffold unit: RGE_Action_Object.cpp.asm
#include "../include/common.h"

// Offset: 0x00405F70
void* RGE_Action_Object::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall RGE_Action_Object::`vector deleting destructor'(unsigned int)       *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(RGE_Action_Object * t
    //              void *            EAX:4          <RETURN>
    //              RGE_Action_Obj    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00405f78(R)  
    //                               ??_GRGE_Action_Object@@UAEPAXI@Z                             XREF[1]:     0056e420(*)  
    //                               ??_ERGE_Action_Object@@UAEPAXI@Z
    //                               RGE_Action_Object::`vector_deleting_destructor'
    //         00405f70     PUSH       ESI
    //         00405f71     MOV        ESI,this
    //         00405f73     CALL       RGE_Action_Object::~RGE_Action_Object            void ~RGE_Action_Object(RGE_Action_Object * t
    //         00405f78     TEST       byte ptr [ESP + param_1],0x1
    //         00405f7d     JZ         LAB_00405f88
    //         00405f7f     PUSH       ESI
    //         00405f80     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00405f85     ADD        ESP,0x4
    //                               LAB_00405f88                                                 XREF[1]:     00405f7d(j)  
    //         00405f88     MOV        EAX,ESI
    //         00405f8a     POP        ESI
    //         00405f8b     RET        0x4
}

