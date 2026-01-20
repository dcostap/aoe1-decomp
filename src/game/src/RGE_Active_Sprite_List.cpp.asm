// Auto-generated scaffold unit: RGE_Active_Sprite_List.cpp.asm
#include "../include/common.h"

// Offset: 0x0041A660
void* RGE_Active_Sprite_List::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall RGE_Active_Sprite_List::`vector deleting destructor'(unsigned int)  *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(RGE_Active_Sprite_Lis
    //              void *            EAX:4          <RETURN>
    //              RGE_Active_Spr    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0041a668(R)  
    //                               ??_GRGE_Active_Sprite_List@@UAEPAXI@Z                        XREF[1]:     0056ee08(*)  
    //                               ??_ERGE_Active_Sprite_List@@UAEPAXI@Z
    //                               RGE_Active_Sprite_List::`vector_deleting_destructor'
    //         0041a660     PUSH       ESI
    //         0041a661     MOV        ESI,this
    //         0041a663     CALL       RGE_Active_Sprite_List::~RGE_Active_Sprite_List  void ~RGE_Active_Sprite_List(RGE_Active_Sprit
    //         0041a668     TEST       byte ptr [ESP + param_1],0x1
    //         0041a66d     JZ         LAB_0041a678
    //         0041a66f     PUSH       ESI
    //         0041a670     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0041a675     ADD        ESP,0x4
    //                               LAB_0041a678                                                 XREF[1]:     0041a66d(j)  
    //         0041a678     MOV        EAX,ESI
    //         0041a67a     POP        ESI
    //         0041a67b     RET        0x4
}

