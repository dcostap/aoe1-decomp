// Auto-generated scaffold unit: RGE_Action_Attack.asm
#include "../include/common.h"

// Offset: 0x00401150
void* RGE_Action_Attack::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall RGE_Action_Attack::`vector deleting destructor'(unsigned int)       *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(RGE_Action_Attack * t
    //              void *            EAX:4          <RETURN>
    //              RGE_Action_Att    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00401158(R)  
    //                               ??_GRGE_Action_Attack@@UAEPAXI@Z                             XREF[1]:     0056e058(*)  
    //                               ??_ERGE_Action_Attack@@UAEPAXI@Z
    //                               RGE_Action_Attack::`vector_deleting_destructor'
    //         00401150     PUSH       ESI
    //         00401151     MOV        ESI,this
    //         00401153     CALL       RGE_Action_Attack::~RGE_Action_Attack            void ~RGE_Action_Attack(RGE_Action_Attack * t
    //         00401158     TEST       byte ptr [ESP + param_1],0x1
    //         0040115d     JZ         LAB_00401168
    //         0040115f     PUSH       ESI
    //         00401160     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00401165     ADD        ESP,0x4
    //                               LAB_00401168                                                 XREF[1]:     0040115d(j)  
    //         00401168     MOV        EAX,ESI
    //         0040116a     POP        ESI
    //         0040116b     RET        0x4
}

