// Auto-generated scaffold unit: bucket_0424.cpp.asm
#include "../include/common.h"

// Offset: 0x00424AC0
void* vector_deleting_destructor(IPAD* this_, uint param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void * __thiscall IPAD::`vector deleting destructor'(unsigned int)                            *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(IPAD * this, uint par
    //              void *            EAX:4          <RETURN>
    //              IPAD *            ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00424ac0(R)  
    //                               ??_EIPAD@@QAEPAXI@Z
    //                               IPAD::`vector_deleting_destructor'
    //         00424ac0     MOV        AL,byte ptr [ESP + param_1]
    //         00424ac4     PUSH       ESI
    //         00424ac5     TEST       AL,0x2
    //         00424ac7     PUSH       EDI
    //         00424ac8     MOV        ESI,this
    //         00424aca     JZ         LAB_00424af3
    //         00424acc     MOV        EAX,dword ptr [ESI + -0x4]
    //         00424acf     LEA        EDI,[ESI + -0x4]
    //         00424ad2     PUSH       IPAD::~IPAD
    //         00424ad7     PUSH       EAX
    //         00424ad8     PUSH       0xa0
    //         00424add     PUSH       ESI
    //         00424ade     CALL       `eh_vector_destructor_iterator'                  void `eh_vector_destructor_iterator'(void * p
    //         00424ae3     PUSH       EDI
    //         00424ae4     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00424ae9     ADD        ESP,0x4
    //         00424aec     MOV        EAX,ESI
    //         00424aee     POP        EDI
    //         00424aef     POP        ESI
    //         00424af0     RET        0x4
    //                               LAB_00424af3                                                 XREF[1]:     00424aca(j)  
    //         00424af3     TEST       AL,0x1
    //         00424af5     JZ         LAB_00424b00
    //         00424af7     PUSH       ESI
    //         00424af8     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00424afd     ADD        ESP,0x4
    //                               LAB_00424b00                                                 XREF[1]:     00424af5(j)  
    //         00424b00     MOV        EAX,ESI
    //         00424b02     POP        EDI
    //         00424b03     POP        ESI
    //         00424b04     RET        0x4
}

