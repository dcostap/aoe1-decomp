// Auto-generated scaffold unit: RGE_Scenario.cpp.asm
#include "../include/common.h"

// Offset: 0x0048ADF0
void* RGE_Scenario::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall RGE_Scenario::`scalar deleting destructor'(unsigned int)            *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(RGE_Scenario * this, 
    //              void *            EAX:4          <RETURN>
    //              RGE_Scenario *    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0048adf8(R)  
    //                               ??_ERGE_Scenario@@UAEPAXI@Z                                  XREF[1]:     0057212c(*)  
    //                               ??_GRGE_Scenario@@UAEPAXI@Z
    //                               RGE_Scenario::`scalar_deleting_destructor'
    //         0048adf0     PUSH       ESI
    //         0048adf1     MOV        ESI,this
    //         0048adf3     CALL       RGE_Scenario::~RGE_Scenario                      void ~RGE_Scenario(RGE_Scenario * this)
    //         0048adf8     TEST       byte ptr [ESP + param_1],0x1
    //         0048adfd     JZ         LAB_0048ae08
    //         0048adff     PUSH       ESI
    //         0048ae00     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0048ae05     ADD        ESP,0x4
    //                               LAB_0048ae08                                                 XREF[1]:     0048adfd(j)  
    //         0048ae08     MOV        EAX,ESI
    //         0048ae0a     POP        ESI
    //         0048ae0b     RET        0x4
}

