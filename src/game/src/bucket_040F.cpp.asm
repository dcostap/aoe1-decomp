// Auto-generated scaffold unit: bucket_040F.cpp.asm
#include "../include/common.h"

// Offset: 0x0040F0E0
void vector_constructor_iterator(void* param_1, uint param_2, int param_3, _func_void_void_ptr* param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * void __stdcall `vector constructor iterator'(void *,unsigned int,int,void (__thiscall*)(void *))      *
    //                              *********************************************************************************************************
    //                              void __stdcall `vector_constructor_iterator'(void * param_1, uint pa
    //              void              <VOID>         <RETURN>
    //              void *            Stack[0x4]:4   param_1                   XREF[1]:     0040f0e9(R)  
    //              uint              Stack[0x8]:4   param_2                   XREF[1]:     0040f0ee(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0040f0e0(R)  
    //              _func_void_voi    Stack[0x10]:4  param_4                   XREF[1]:     0040f0f3(R)  
    //                               ??_H@YGXPAXIHP6EX0@Z@Z
    //                               `vector_constructor_iterator'
    //         0040f0e0     MOV        EAX,dword ptr [ESP + param_3]
    //         0040f0e4     DEC        EAX
    //         0040f0e5     JS         LAB_0040f107
    //         0040f0e7     PUSH       EDI
    //         0040f0e8     PUSH       ESI
    //         0040f0e9     MOV        ESI,dword ptr [ESP + param_1]
    //         0040f0ed     PUSH       EBP
    //         0040f0ee     MOV        EBP,dword ptr [ESP + param_2]
    //         0040f0f2     PUSH       EBX
    //         0040f0f3     MOV        EBX,dword ptr [ESP + param_4]
    //         0040f0f7     LEA        EDI,[EAX + 0x1]
    //                               LAB_0040f0fa                                                 XREF[1]:     0040f101(j)  
    //         0040f0fa     MOV        ECX,ESI
    //         0040f0fc     CALL       EBX
    //         0040f0fe     ADD        ESI,EBP
    //         0040f100     DEC        EDI
    //         0040f101     JNZ        LAB_0040f0fa
    //         0040f103     POP        EBX
    //         0040f104     POP        EBP
    //         0040f105     POP        ESI
    //         0040f106     POP        EDI
    //                               LAB_0040f107                                                 XREF[1]:     0040f0e5(j)  
    //         0040f107     RET        0x10
}

