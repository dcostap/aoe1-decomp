// Auto-generated scaffold unit: RGE_Panel_Time.cpp.asm
#include "../include/common.h"

// Offset: 0x0048A710
void* RGE_Panel_Time::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall RGE_Panel_Time::`scalar deleting destructor'(unsigned int)          *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(RGE_Panel_Time * this
    //              void *            EAX:4          <RETURN>
    //              RGE_Panel_Time    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0048a718(R)  
    //                               ??_ERGE_Panel_Time@@UAEPAXI@Z                                XREF[1]:     00572040(*)  
    //                               ??_GRGE_Panel_Time@@UAEPAXI@Z
    //                               RGE_Panel_Time::`scalar_deleting_destructor'
    //         0048a710     PUSH       ESI
    //         0048a711     MOV        ESI,this
    //         0048a713     CALL       RGE_Panel_Time::~RGE_Panel_Time                  void ~RGE_Panel_Time(RGE_Panel_Time * this)
    //         0048a718     TEST       byte ptr [ESP + param_1],0x1
    //         0048a71d     JZ         LAB_0048a728
    //         0048a71f     PUSH       ESI
    //         0048a720     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0048a725     ADD        ESP,0x4
    //                               LAB_0048a728                                                 XREF[1]:     0048a71d(j)  
    //         0048a728     MOV        EAX,ESI
    //         0048a72a     POP        ESI
    //         0048a72b     RET        0x4
}

