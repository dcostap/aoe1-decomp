// Auto-generated scaffold unit: ostream.cpp.asm
#include "../include/common.h"

// Offset: 0x0055A8D0
void* ostream::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall ostream::`scalar deleting destructor'(unsigned int)                 *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(ostream * this, uint 
    //              void *            EAX:4          <RETURN>
    //              ostream *         ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0055a8e6(R)  
    //                               ??_Eostream@@UAEPAXI@Z                                       XREF[1]:     00578034(*)  
    //                               ??_Gostream@@UAEPAXI@Z
    //                               ostream::`scalar_deleting_destructor'
    //         0055a8d0     PUSH       ESI
    //         0055a8d1     PUSH       EDI
    //         0055a8d2     LEA        EDI,[this->field0_0x0 + -0x8]
    //         0055a8d5     LEA        ESI,[EDI + 0x8]
    //         0055a8d8     MOV        this,ESI
    //         0055a8da     CALL       ostream::~ostream                                void ~ostream(ostream * this)
    //         0055a8df     MOV        this,ESI
    //         0055a8e1     CALL       ios::~ios                                        void ~ios(ios * this)
    //         0055a8e6     TEST       byte ptr [ESP + param_1],0x1
    //         0055a8eb     JZ         LAB_0055a8f6
    //         0055a8ed     PUSH       EDI
    //         0055a8ee     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0055a8f3     ADD        ESP,0x4
    //                               LAB_0055a8f6                                                 XREF[1]:     0055a8eb(j)  
    //         0055a8f6     MOV        EAX,EDI
    //         0055a8f8     POP        EDI
    //         0055a8f9     POP        ESI
    //         0055a8fa     RET        0x4
}

