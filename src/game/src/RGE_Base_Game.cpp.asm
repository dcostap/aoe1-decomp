// Auto-generated scaffold unit: RGE_Base_Game.cpp.asm
#include "../include/common.h"

// Offset: 0x0041BA80
void* RGE_Base_Game::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall RGE_Base_Game::`vector deleting destructor'(unsigned int)           *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(RGE_Base_Game * this,
    //              void *            EAX:4          <RETURN>
    //              RGE_Base_Game *   ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0041ba88(R)  
    //                               ??_GRGE_Base_Game@@UAEPAXI@Z                                 XREF[1]:     0056eed0(*)  
    //                               ??_ERGE_Base_Game@@UAEPAXI@Z
    //                               RGE_Base_Game::`vector_deleting_destructor'
    //         0041ba80     PUSH       ESI
    //         0041ba81     MOV        ESI,this
    //         0041ba83     CALL       RGE_Base_Game::~RGE_Base_Game                    void ~RGE_Base_Game(RGE_Base_Game * this)
    //         0041ba88     TEST       byte ptr [ESP + param_1],0x1
    //         0041ba8d     JZ         LAB_0041ba98
    //         0041ba8f     PUSH       ESI
    //         0041ba90     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0041ba95     ADD        ESP,0x4
    //                               LAB_0041ba98                                                 XREF[1]:     0041ba8d(j)  
    //         0041ba98     MOV        EAX,ESI
    //         0041ba9a     POP        ESI
    //         0041ba9b     RET        0x4
}

