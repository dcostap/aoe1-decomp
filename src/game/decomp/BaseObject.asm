// Auto-generated scaffold unit: BaseObject.asm
#include "../include/common.h"

// Offset: 0x0040A040
void* BaseObject::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall BaseObject::`vector deleting destructor'(unsigned int)              *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(BaseObject * this, ui
    //              void *            EAX:4          <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0040a048(R)  
    //                               ??_GBaseObject@@UAEPAXI@Z                                    XREF[1]:     0056e798(*)  
    //                               ??_EBaseObject@@UAEPAXI@Z
    //                               BaseObject::`vector_deleting_destructor'
    //         0040a040     PUSH       ESI
    //         0040a041     MOV        ESI,this
    //         0040a043     CALL       BaseObject::~BaseObject                          void ~BaseObject(BaseObject * this)
    //         0040a048     TEST       byte ptr [ESP + param_1],0x1
    //         0040a04d     JZ         LAB_0040a058
    //         0040a04f     PUSH       ESI
    //         0040a050     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0040a055     ADD        ESP,0x4
    //                               LAB_0040a058                                                 XREF[1]:     0040a04d(j)  
    //         0040a058     MOV        EAX,ESI
    //         0040a05a     POP        ESI
    //         0040a05b     RET        0x4
}

