// Auto-generated scaffold unit: RGE_Main_View.cpp.asm
#include "../include/common.h"

// Offset: 0x0053DB10
void* RGE_Main_View::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall RGE_Main_View::`vector deleting destructor'(unsigned int)           *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(RGE_Main_View * this,
    //              void *            EAX:4          <RETURN>
    //              RGE_Main_View *   ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0053db18(R)  
    //                               ??_GRGE_Main_View@@UAEPAXI@Z                                 XREF[1]:     005777f0(*)  
    //                               ??_ERGE_Main_View@@UAEPAXI@Z
    //                               RGE_Main_View::`vector_deleting_destructor'
    //         0053db10     PUSH       ESI
    //         0053db11     MOV        ESI,this
    //         0053db13     CALL       RGE_Main_View::~RGE_Main_View                    void ~RGE_Main_View(RGE_Main_View * this)
    //         0053db18     TEST       byte ptr [ESP + param_1],0x1
    //         0053db1d     JZ         LAB_0053db28
    //         0053db1f     PUSH       ESI
    //         0053db20     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0053db25     ADD        ESP,0x4
    //                               LAB_0053db28                                                 XREF[1]:     0053db1d(j)  
    //         0053db28     MOV        EAX,ESI
    //         0053db2a     POP        ESI
    //         0053db2b     RET        0x4
}

