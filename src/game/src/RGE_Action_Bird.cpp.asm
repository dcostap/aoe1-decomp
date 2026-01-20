// Auto-generated scaffold unit: RGE_Action_Bird.cpp.asm
#include "../include/common.h"

// Offset: 0x00402010
void* RGE_Action_Bird::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall RGE_Action_Bird::`vector deleting destructor'(unsigned int)         *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(RGE_Action_Bird * thi
    //              void *            EAX:4          <RETURN>
    //              RGE_Action_Bir    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00402018(R)  
    //                               ??_GRGE_Action_Bird@@UAEPAXI@Z                               XREF[1]:     0056e0d8(*)  
    //                               ??_ERGE_Action_Bird@@UAEPAXI@Z
    //                               RGE_Action_Bird::`vector_deleting_destructor'
    //         00402010     PUSH       ESI
    //         00402011     MOV        ESI,this
    //         00402013     CALL       RGE_Action_Bird::~RGE_Action_Bird                void ~RGE_Action_Bird(RGE_Action_Bird * this)
    //         00402018     TEST       byte ptr [ESP + param_1],0x1
    //         0040201d     JZ         LAB_00402028
    //         0040201f     PUSH       ESI
    //         00402020     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00402025     ADD        ESP,0x4
    //                               LAB_00402028                                                 XREF[1]:     0040201d(j)  
    //         00402028     MOV        EAX,ESI
    //         0040202a     POP        ESI
    //         0040202b     RET        0x4
}

