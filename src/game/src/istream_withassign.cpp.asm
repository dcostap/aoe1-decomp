// Auto-generated scaffold unit: istream_withassign.cpp.asm
#include "../include/common.h"

// Offset: 0x0055BA10
void* istream_withassign::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall istream_withassign::`vector deleting destructor'(unsigned int)      *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(istream_withassign * 
    //              void *            EAX:4          <RETURN>
    //              istream_withas    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0055ba26(R)  
    //                               ??_Gistream_withassign@@UAEPAXI@Z                            XREF[1]:     0057808c(*)  
    //                               ??_Eistream_withassign@@UAEPAXI@Z
    //                               istream_withassign::`vector_deleting_destructor'
    //         0055ba10     PUSH       ESI
    //         0055ba11     PUSH       EDI
    //         0055ba12     LEA        EDI,[this + -0xc]
    //         0055ba15     LEA        ESI,[EDI + 0xc]
    //         0055ba18     MOV        this,ESI
    //         0055ba1a     CALL       istream_withassign::~istream_withassign          void ~istream_withassign(istream_withassign *
    //         0055ba1f     MOV        this,ESI
    //         0055ba21     CALL       ios::~ios                                        void ~ios(ios * this)
    //         0055ba26     TEST       byte ptr [ESP + param_1],0x1
    //         0055ba2b     JZ         LAB_0055ba36
    //         0055ba2d     PUSH       EDI
    //         0055ba2e     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0055ba33     ADD        ESP,0x4
    //                               LAB_0055ba36                                                 XREF[1]:     0055ba2b(j)  
    //         0055ba36     MOV        EAX,EDI
    //         0055ba38     POP        EDI
    //         0055ba39     POP        ESI
    //         0055ba3a     RET        0x4
}

