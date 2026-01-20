// Auto-generated scaffold unit: istream.cpp.asm
#include "../include/common.h"

// Offset: 0x0055B4B0
void* istream::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall istream::`scalar deleting destructor'(unsigned int)                 *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(istream * this, uint 
    //              void *            EAX:4          <RETURN>
    //              istream *         ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0055b4c6(R)  
    //                               ??_Eistream@@UAEPAXI@Z                                       XREF[1]:     0057807c(*)  
    //                               ??_Gistream@@UAEPAXI@Z
    //                               istream::`scalar_deleting_destructor'
    //         0055b4b0     PUSH       ESI
    //         0055b4b1     PUSH       EDI
    //         0055b4b2     LEA        EDI,[this->field0_0x0 + -0xc]
    //         0055b4b5     LEA        ESI,[EDI + 0xc]
    //         0055b4b8     MOV        this,ESI
    //         0055b4ba     CALL       istream::~istream                                void ~istream(istream * this)
    //         0055b4bf     MOV        this,ESI
    //         0055b4c1     CALL       ios::~ios                                        void ~ios(ios * this)
    //         0055b4c6     TEST       byte ptr [ESP + param_1],0x1
    //         0055b4cb     JZ         LAB_0055b4d6
    //         0055b4cd     PUSH       EDI
    //         0055b4ce     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0055b4d3     ADD        ESP,0x4
    //                               LAB_0055b4d6                                                 XREF[1]:     0055b4cb(j)  
    //         0055b4d6     MOV        EAX,EDI
    //         0055b4d8     POP        EDI
    //         0055b4d9     POP        ESI
    //         0055b4da     RET        0x4
}

