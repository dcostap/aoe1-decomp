// Auto-generated scaffold unit: RGE_Action_Missile.asm
#include "../include/common.h"

// Offset: 0x00404C60
void* RGE_Action_Missile::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall RGE_Action_Missile::`vector deleting destructor'(unsigned int)      *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(RGE_Action_Missile * 
    //              void *            EAX:4          <RETURN>
    //              RGE_Action_Mis    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00404c68(R)  
    //                               ??_GRGE_Action_Missile@@UAEPAXI@Z                            XREF[1]:     0056e320(*)  
    //                               ??_ERGE_Action_Missile@@UAEPAXI@Z
    //                               RGE_Action_Missile::`vector_deleting_destructor'
    //         00404c60     PUSH       ESI
    //         00404c61     MOV        ESI,this
    //         00404c63     CALL       RGE_Action_Missile::~RGE_Action_Missile          void ~RGE_Action_Missile(RGE_Action_Missile *
    //         00404c68     TEST       byte ptr [ESP + param_1],0x1
    //         00404c6d     JZ         LAB_00404c78
    //         00404c6f     PUSH       ESI
    //         00404c70     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00404c75     ADD        ESP,0x4
    //                               LAB_00404c78                                                 XREF[1]:     00404c6d(j)  
    //         00404c78     MOV        EAX,ESI
    //         00404c7a     POP        ESI
    //         00404c7b     RET        0x4
}

