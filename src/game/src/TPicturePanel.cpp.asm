// Auto-generated scaffold unit: TPicturePanel.cpp.asm
#include "../include/common.h"

// Offset: 0x0047A230
void* TPicturePanel::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TPicturePanel::`scalar deleting destructor'(unsigned int)           *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TPicturePanel * this,
    //              void *            EAX:4          <RETURN>
    //              TPicturePanel *   ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0047a238(R)  
    //                               ??_ETPicturePanel@@UAEPAXI@Z                                 XREF[1]:     00571750(*)  
    //                               ??_GTPicturePanel@@UAEPAXI@Z
    //                               TPicturePanel::`scalar_deleting_destructor'
    //         0047a230     PUSH       ESI
    //         0047a231     MOV        ESI,this
    //         0047a233     CALL       TPicturePanel::~TPicturePanel                    void ~TPicturePanel(TPicturePanel * this)
    //         0047a238     TEST       byte ptr [ESP + param_1],0x1
    //         0047a23d     JZ         LAB_0047a248
    //         0047a23f     PUSH       ESI
    //         0047a240     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0047a245     ADD        ESP,0x4
    //                               LAB_0047a248                                                 XREF[1]:     0047a23d(j)  
    //         0047a248     MOV        EAX,ESI
    //         0047a24a     POP        ESI
    //         0047a24b     RET        0x4
}

