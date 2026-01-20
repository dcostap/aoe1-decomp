// Auto-generated scaffold unit: ios.cpp.asm
#include "../include/common.h"

// Offset: 0x0055B150
void* ios::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall ios::`vector deleting destructor'(unsigned int)                     *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(ios * this, uint para
    //              void *            EAX:4          <RETURN>
    //              ios *             ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0055b158(R)  
    //                               ??_Gios@@UAEPAXI@Z                                           XREF[1]:     00578074(*)  
    //                               ??_Eios@@UAEPAXI@Z
    //                               ios::`vector_deleting_destructor'
    //         0055b150     PUSH       ESI
    //         0055b151     MOV        ESI,this
    //         0055b153     CALL       ios::~ios                                        void ~ios(ios * this)
    //         0055b158     TEST       byte ptr [ESP + param_1],0x1
    //         0055b15d     JZ         LAB_0055b168
    //         0055b15f     PUSH       ESI
    //         0055b160     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0055b165     ADD        ESP,0x4
    //                               LAB_0055b168                                                 XREF[1]:     0055b15d(j)  
    //         0055b168     MOV        EAX,ESI
    //         0055b16a     POP        ESI
    //         0055b16b     RET        0x4
}

