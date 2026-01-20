// Auto-generated scaffold unit: RGE_Panel_Tool_Box.cpp.asm
#include "../include/common.h"

// Offset: 0x00489E70
void* RGE_Panel_Tool_Box::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall RGE_Panel_Tool_Box::`vector deleting destructor'(unsigned int)      *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(RGE_Panel_Tool_Box * 
    //              void *            EAX:4          <RETURN>
    //              RGE_Panel_Tool    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00489e78(R)  
    //                               ??_GRGE_Panel_Tool_Box@@UAEPAXI@Z                            XREF[1]:     00571f60(*)  
    //                               ??_ERGE_Panel_Tool_Box@@UAEPAXI@Z
    //                               RGE_Panel_Tool_Box::`vector_deleting_destructor'
    //         00489e70     PUSH       ESI
    //         00489e71     MOV        ESI,this
    //         00489e73     CALL       RGE_Panel_Tool_Box::~RGE_Panel_Tool_Box          void ~RGE_Panel_Tool_Box(RGE_Panel_Tool_Box *
    //         00489e78     TEST       byte ptr [ESP + param_1],0x1
    //         00489e7d     JZ         LAB_00489e88
    //         00489e7f     PUSH       ESI
    //         00489e80     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00489e85     ADD        ESP,0x4
    //                               LAB_00489e88                                                 XREF[1]:     00489e7d(j)  
    //         00489e88     MOV        EAX,ESI
    //         00489e8a     POP        ESI
    //         00489e8b     RET        0x4
}

