// Auto-generated scaffold unit: RGE_Diamond_Map_View.asm
#include "../include/common.h"

// Offset: 0x0053D380
void* RGE_Diamond_Map_View::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall RGE_Diamond_Map_View::`scalar deleting destructor'(unsigned int)    *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(RGE_Diamond_Map_View 
    //              void *            EAX:4          <RETURN>
    //              RGE_Diamond_Ma    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0053d388(R)  
    //                               ??_ERGE_Diamond_Map_View@@UAEPAXI@Z                          XREF[1]:     005776e8(*)  
    //                               ??_GRGE_Diamond_Map_View@@UAEPAXI@Z
    //                               RGE_Diamond_Map_View::`scalar_deleting_destructor'
    //         0053d380     PUSH       ESI
    //         0053d381     MOV        ESI,this
    //         0053d383     CALL       RGE_Diamond_Map_View::~RGE_Diamond_Map_View      void ~RGE_Diamond_Map_View(RGE_Diamond_Map_Vi
    //         0053d388     TEST       byte ptr [ESP + param_1],0x1
    //         0053d38d     JZ         LAB_0053d398
    //         0053d38f     PUSH       ESI
    //         0053d390     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0053d395     ADD        ESP,0x4
    //                               LAB_0053d398                                                 XREF[1]:     0053d38d(j)  
    //         0053d398     MOV        EAX,ESI
    //         0053d39a     POP        ESI
    //         0053d39b     RET        0x4
}

