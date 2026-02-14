// Auto-generated scaffold unit: TScreenPanel.asm
#include "../include/common.h"

// Offset: 0x0047BA90
void* TScreenPanel::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TScreenPanel::`vector deleting destructor'(unsigned int)            *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TScreenPanel * this, 
    //              void *            EAX:4          <RETURN>
    //              TScreenPanel *    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0047ba98(R)  
    //                               ??_GTScreenPanel@@UAEPAXI@Z                                  XREF[1]:     00571910(*)  
    //                               ??_ETScreenPanel@@UAEPAXI@Z
    //                               TScreenPanel::`vector_deleting_destructor'
    //         0047ba90     PUSH       ESI
    //         0047ba91     MOV        ESI,this
    //         0047ba93     CALL       TScreenPanel::~TScreenPanel                      void ~TScreenPanel(TScreenPanel * this)
    //         0047ba98     TEST       byte ptr [ESP + param_1],0x1
    //         0047ba9d     JZ         LAB_0047baa8
    //         0047ba9f     PUSH       ESI
    //         0047baa0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0047baa5     ADD        ESP,0x4
    //                               LAB_0047baa8                                                 XREF[1]:     0047ba9d(j)  
    //         0047baa8     MOV        EAX,ESI
    //         0047baaa     POP        ESI
    //         0047baab     RET        0x4
}

