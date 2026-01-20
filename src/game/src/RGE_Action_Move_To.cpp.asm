// Auto-generated scaffold unit: RGE_Action_Move_To.cpp.asm
#include "../include/common.h"

// Offset: 0x00405580
void* RGE_Action_Move_To::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall RGE_Action_Move_To::`scalar deleting destructor'(unsigned int)      *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(RGE_Action_Move_To * 
    //              void *            EAX:4          <RETURN>
    //              RGE_Action_Mov    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00405588(R)  
    //                               ??_ERGE_Action_Move_To@@UAEPAXI@Z                            XREF[1]:     0056e3a0(*)  
    //                               ??_GRGE_Action_Move_To@@UAEPAXI@Z
    //                               RGE_Action_Move_To::`scalar_deleting_destructor'
    //         00405580     PUSH       ESI
    //         00405581     MOV        ESI,this
    //         00405583     CALL       RGE_Action_Move_To::~RGE_Action_Move_To          void ~RGE_Action_Move_To(RGE_Action_Move_To *
    //         00405588     TEST       byte ptr [ESP + param_1],0x1
    //         0040558d     JZ         LAB_00405598
    //         0040558f     PUSH       ESI
    //         00405590     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00405595     ADD        ESP,0x4
    //                               LAB_00405598                                                 XREF[1]:     0040558d(j)  
    //         00405598     MOV        EAX,ESI
    //         0040559a     POP        ESI
    //         0040559b     RET        0x4
}

