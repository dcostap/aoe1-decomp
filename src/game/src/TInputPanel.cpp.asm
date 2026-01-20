// Auto-generated scaffold unit: TInputPanel.cpp.asm
#include "../include/common.h"

// Offset: 0x00476CD0
void* TInputPanel::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TInputPanel::`scalar deleting destructor'(unsigned int)             *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TInputPanel * this, u
    //              void *            EAX:4          <RETURN>
    //              TInputPanel *     ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00476cd8(R)  
    //                               ??_ETInputPanel@@UAEPAXI@Z                                   XREF[1]:     00571488(*)  
    //                               ??_GTInputPanel@@UAEPAXI@Z
    //                               TInputPanel::`scalar_deleting_destructor'
    //         00476cd0     PUSH       ESI
    //         00476cd1     MOV        ESI,this
    //         00476cd3     CALL       TInputPanel::~TInputPanel                        void ~TInputPanel(TInputPanel * this)
    //         00476cd8     TEST       byte ptr [ESP + param_1],0x1
    //         00476cdd     JZ         LAB_00476ce8
    //         00476cdf     PUSH       ESI
    //         00476ce0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00476ce5     ADD        ESP,0x4
    //                               LAB_00476ce8                                                 XREF[1]:     00476cdd(j)  
    //         00476ce8     MOV        EAX,ESI
    //         00476cea     POP        ESI
    //         00476ceb     RET        0x4
}

