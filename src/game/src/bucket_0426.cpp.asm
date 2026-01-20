// Auto-generated scaffold unit: bucket_0426.cpp.asm
#include "../include/common.h"

// Offset: 0x004260F0
void* vector_deleting_destructor(RESENDER* this_, uint param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void * __thiscall RESENDER::`vector deleting destructor'(unsigned int)                        *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(RESENDER * this, uint
    //              void *            EAX:4          <RETURN>
    //              RESENDER *        ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004260f1(R)  
    //                               ??_ERESENDER@@QAEPAXI@Z
    //                               RESENDER::`vector_deleting_destructor'
    //         004260f0     PUSH       EBX
    //         004260f1     MOV        BL,byte ptr [ESP + param_1]
    //         004260f5     PUSH       ESI
    //         004260f6     PUSH       EDI
    //         004260f7     TEST       BL,0x2
    //         004260fa     MOV        ESI,this
    //         004260fc     JZ         LAB_00426123
    //         004260fe     MOV        EAX,dword ptr [ESI + -0x4]
    //         00426101     LEA        EDI,[ESI + -0x4]
    //         00426104     PUSH       RESENDER::~RESENDER
    //         00426109     PUSH       EAX
    //         0042610a     PUSH       0x38
    //         0042610c     PUSH       ESI
    //         0042610d     CALL       `eh_vector_destructor_iterator'                  void `eh_vector_destructor_iterator'(void * p
    //         00426112     PUSH       EDI
    //         00426113     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00426118     ADD        ESP,0x4
    //         0042611b     MOV        EAX,ESI
    //         0042611d     POP        EDI
    //         0042611e     POP        ESI
    //         0042611f     POP        EBX
    //         00426120     RET        0x4
    //                               LAB_00426123                                                 XREF[1]:     004260fc(j)  
    //         00426123     MOV        EAX,dword ptr [ESI + 0x8]
    //         00426126     XOR        EDI,EDI
    //         00426128     CMP        EAX,EDI
    //         0042612a     MOV        dword ptr [ESI],EDI
    //         0042612c     JZ         LAB_00426137
    //         0042612e     PUSH       EAX
    //         0042612f     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00426134     ADD        ESP,0x4
    //                               LAB_00426137                                                 XREF[1]:     0042612c(j)  
    //         00426137     MOV        dword ptr [ESI + 0x8],EDI
    //         0042613a     MOV        dword ptr [ESI + 0x4],EDI
    //         0042613d     MOV        dword ptr [ESI + 0xc],EDI
    //         00426140     LEA        EDI,[ESI + 0x10]
    //         00426143     MOV        this,0xa
    //         00426148     XOR        EAX,EAX
    //         0042614a     TEST       BL,0x1
    //         0042614d     STOSD.REP  ES:EDI
    //         0042614f     JZ         LAB_0042615a
    //         00426151     PUSH       ESI
    //         00426152     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00426157     ADD        ESP,0x4
    //                               LAB_0042615a                                                 XREF[1]:     0042614f(j)  
    //         0042615a     MOV        EAX,ESI
    //         0042615c     POP        EDI
    //         0042615d     POP        ESI
    //         0042615e     POP        EBX
    //         0042615f     RET        0x4
}

// Offset: 0x00426170
void* vector_deleting_destructor(HOLDER* this_, uint param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void * __thiscall HOLDER::`vector deleting destructor'(unsigned int)                          *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(HOLDER * this, uint p
    //              void *            EAX:4          <RETURN>
    //              HOLDER *          ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00426171(R)  
    //                               ??_EHOLDER@@QAEPAXI@Z
    //                               HOLDER::`vector_deleting_destructor'
    //         00426170     PUSH       EBX
    //         00426171     MOV        BL,byte ptr [ESP + param_1]
    //         00426175     PUSH       ESI
    //         00426176     PUSH       EDI
    //         00426177     TEST       BL,0x2
    //         0042617a     MOV        ESI,this
    //         0042617c     JZ         LAB_004261a3
    //         0042617e     MOV        EAX,dword ptr [ESI + -0x4]
    //         00426181     LEA        EDI,[ESI + -0x4]
    //         00426184     PUSH       HOLDER::~HOLDER
    //         00426189     PUSH       EAX
    //         0042618a     PUSH       0x18
    //         0042618c     PUSH       ESI
    //         0042618d     CALL       `eh_vector_destructor_iterator'                  void `eh_vector_destructor_iterator'(void * p
    //         00426192     PUSH       EDI
    //         00426193     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00426198     ADD        ESP,0x4
    //         0042619b     MOV        EAX,ESI
    //         0042619d     POP        EDI
    //         0042619e     POP        ESI
    //         0042619f     POP        EBX
    //         004261a0     RET        0x4
    //                               LAB_004261a3                                                 XREF[1]:     0042617c(j)  
    //         004261a3     MOV        EAX,dword ptr [ESI]
    //         004261a5     XOR        EDI,EDI
    //         004261a7     CMP        EAX,EDI
    //         004261a9     JZ         LAB_004261b4
    //         004261ab     PUSH       EAX
    //         004261ac     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004261b1     ADD        ESP,0x4
    //                               LAB_004261b4                                                 XREF[1]:     004261a9(j)  
    //         004261b4     TEST       BL,0x1
    //         004261b7     MOV        dword ptr [ESI],EDI
    //         004261b9     MOV        dword ptr [ESI + 0x4],EDI
    //         004261bc     MOV        dword ptr [ESI + 0x8],EDI
    //         004261bf     MOV        dword ptr [ESI + 0xc],EDI
    //         004261c2     MOV        dword ptr [ESI + 0x10],EDI
    //         004261c5     JZ         LAB_004261d0
    //         004261c7     PUSH       ESI
    //         004261c8     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004261cd     ADD        ESP,0x4
    //                               LAB_004261d0                                                 XREF[1]:     004261c5(j)  
    //         004261d0     MOV        EAX,ESI
    //         004261d2     POP        EDI
    //         004261d3     POP        ESI
    //         004261d4     POP        EBX
    //         004261d5     RET        0x4
}

