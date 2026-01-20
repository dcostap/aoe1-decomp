// Auto-generated scaffold unit: type_info.cpp.asm
#include "../include/common.h"

// Offset: 0x0055BF40
void* type_info::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall type_info::`vector deleting destructor'(unsigned int)               *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(type_info * this, uin
    //              void *            EAX:4          <RETURN>
    //              type_info *       ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0055bf48(R)  
    //                               ??_Gtype_info@@UAEPAXI@Z                                     XREF[1]:     0057809c(*)  
    //                               ??_Etype_info@@UAEPAXI@Z
    //                               type_info::`vector_deleting_destructor'
    //         0055bf40     PUSH       ESI
    //         0055bf41     MOV        ESI,this
    //         0055bf43     CALL       type_info::~type_info                            void ~type_info(type_info * this)
    //         0055bf48     TEST       byte ptr [ESP + param_1],0x1
    //         0055bf4d     JZ         LAB_0055bf58
    //         0055bf4f     PUSH       ESI
    //         0055bf50     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0055bf55     ADD        ESP,0x4
    //                               LAB_0055bf58                                                 XREF[1]:     0055bf4d(j)  
    //         0055bf58     MOV        EAX,ESI
    //         0055bf5a     POP        ESI
    //         0055bf5b     RET        0x4
}

