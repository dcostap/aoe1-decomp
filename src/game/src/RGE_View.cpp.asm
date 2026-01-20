// Auto-generated scaffold unit: RGE_View.cpp.asm
#include "../include/common.h"

// Offset: 0x00533740
void* RGE_View::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall RGE_View::`vector deleting destructor'(unsigned int)                *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(RGE_View * this, uint
    //              void *            EAX:4          <RETURN>
    //              RGE_View *        ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00533748(R)  
    //                               ??_GRGE_View@@UAEPAXI@Z                                      XREF[1]:     005775b8(*)  
    //                               ??_ERGE_View@@UAEPAXI@Z
    //                               RGE_View::`vector_deleting_destructor'
    //         00533740     PUSH       ESI
    //         00533741     MOV        ESI,this
    //         00533743     CALL       RGE_View::~RGE_View                              void ~RGE_View(RGE_View * this)
    //         00533748     TEST       byte ptr [ESP + param_1],0x1
    //         0053374d     JZ         LAB_00533758
    //         0053374f     PUSH       ESI
    //         00533750     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00533755     ADD        ESP,0x4
    //                               LAB_00533758                                                 XREF[1]:     0053374d(j)  
    //         00533758     MOV        EAX,ESI
    //         0053375a     POP        ESI
    //         0053375b     RET        0x4
}

