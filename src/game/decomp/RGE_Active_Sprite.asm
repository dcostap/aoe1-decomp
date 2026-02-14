// Auto-generated scaffold unit: RGE_Active_Sprite.asm
#include "../include/common.h"

// Offset: 0x0041AD40
void* RGE_Active_Sprite::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall RGE_Active_Sprite::`scalar deleting destructor'(unsigned int)       *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(RGE_Active_Sprite * t
    //              void *            EAX:4          <RETURN>
    //              RGE_Active_Spr    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0041ad48(R)  
    //                               ??_ERGE_Active_Sprite@@UAEPAXI@Z                             XREF[1]:     0056ee38(*)  
    //                               ??_GRGE_Active_Sprite@@UAEPAXI@Z
    //                               RGE_Active_Sprite::`scalar_deleting_destructor'
    //         0041ad40     PUSH       ESI
    //         0041ad41     MOV        ESI,this
    //         0041ad43     CALL       RGE_Active_Sprite::~RGE_Active_Sprite            void ~RGE_Active_Sprite(RGE_Active_Sprite * t
    //         0041ad48     TEST       byte ptr [ESP + param_1],0x1
    //         0041ad4d     JZ         LAB_0041ad58
    //         0041ad4f     PUSH       ESI
    //         0041ad50     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0041ad55     ADD        ESP,0x4
    //                               LAB_0041ad58                                                 XREF[1]:     0041ad4d(j)  
    //         0041ad58     MOV        EAX,ESI
    //         0041ad5a     POP        ESI
    //         0041ad5b     RET        0x4
}

