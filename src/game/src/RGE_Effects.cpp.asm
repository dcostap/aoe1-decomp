// Auto-generated scaffold unit: RGE_Effects.cpp.asm
#include "../include/common.h"

// Offset: 0x00449240
void* RGE_Effects::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall RGE_Effects::`vector deleting destructor'(unsigned int)             *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(RGE_Effects * this, u
    //              void *            EAX:4          <RETURN>
    //              RGE_Effects *     ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00449248(R)  
    //                               ??_GRGE_Effects@@UAEPAXI@Z                                   XREF[1]:     00570430(*)  
    //                               ??_ERGE_Effects@@UAEPAXI@Z
    //                               RGE_Effects::`vector_deleting_destructor'
    //         00449240     PUSH       ESI
    //         00449241     MOV        ESI,this
    //         00449243     CALL       RGE_Effects::~RGE_Effects                        void ~RGE_Effects(RGE_Effects * this)
    //         00449248     TEST       byte ptr [ESP + param_1],0x1
    //         0044924d     JZ         LAB_00449258
    //         0044924f     PUSH       ESI
    //         00449250     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00449255     ADD        ESP,0x4
    //                               LAB_00449258                                                 XREF[1]:     0044924d(j)  
    //         00449258     MOV        EAX,ESI
    //         0044925a     POP        ESI
    //         0044925b     RET        0x4
}

