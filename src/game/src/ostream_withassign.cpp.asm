// Auto-generated scaffold unit: ostream_withassign.cpp.asm
#include "../include/common.h"

// Offset: 0x0055AB60
void* ostream_withassign::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall ostream_withassign::`vector deleting destructor'(unsigned int)      *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(ostream_withassign * 
    //              void *            EAX:4          <RETURN>
    //              ostream_withas    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0055ab76(R)  
    //                               ??_Gostream_withassign@@UAEPAXI@Z                            XREF[1]:     00578044(*)  
    //                               ??_Eostream_withassign@@UAEPAXI@Z
    //                               ostream_withassign::`vector_deleting_destructor'
    //         0055ab60     PUSH       ESI
    //         0055ab61     PUSH       EDI
    //         0055ab62     LEA        EDI,[this + -0x8]
    //         0055ab65     LEA        ESI,[EDI + 0x8]
    //         0055ab68     MOV        this,ESI
    //         0055ab6a     CALL       ostream_withassign::~ostream_withassign          void ~ostream_withassign(ostream_withassign *
    //         0055ab6f     MOV        this,ESI
    //         0055ab71     CALL       ios::~ios                                        void ~ios(ios * this)
    //         0055ab76     TEST       byte ptr [ESP + param_1],0x1
    //         0055ab7b     JZ         LAB_0055ab86
    //         0055ab7d     PUSH       EDI
    //         0055ab7e     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0055ab83     ADD        ESP,0x4
    //                               LAB_0055ab86                                                 XREF[1]:     0055ab7b(j)  
    //         0055ab86     MOV        EAX,EDI
    //         0055ab88     POP        EDI
    //         0055ab89     POP        ESI
    //         0055ab8a     RET        0x4
}

