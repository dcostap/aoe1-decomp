// Auto-generated scaffold unit: bucket_0431.asm
#include "../include/common.h"

// Offset: 0x00431790
void* vector_deleting_destructor(MsgQueue* this_, uint param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void * __thiscall MsgQueue::`vector deleting destructor'(unsigned int)                        *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(MsgQueue * this, uint
    //              void *            EAX:4          <RETURN>
    //              MsgQueue *        ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[2]:     00431790(R), 004317e5(R)  
    //                               ??_EMsgQueue@@QAEPAXI@Z
    //                               MsgQueue::`vector_deleting_destructor'
    //         00431790     MOV        AL,byte ptr [ESP + param_1]
    //         00431794     PUSH       EBX
    //         00431795     PUSH       ESI
    //         00431796     PUSH       EDI
    //         00431797     TEST       AL,0x2
    //         00431799     MOV        ESI,this
    //         0043179b     JZ         LAB_004317c2
    //         0043179d     MOV        EAX,dword ptr [ESI + -0x4]
    //         004317a0     LEA        EDI,[ESI + -0x4]
    //         004317a3     PUSH       MsgQueue::~MsgQueue
    //         004317a8     PUSH       EAX
    //         004317a9     PUSH       0x1c
    //         004317ab     PUSH       ESI
    //         004317ac     CALL       `eh_vector_destructor_iterator'                  void `eh_vector_destructor_iterator'(void * p
    //         004317b1     PUSH       EDI
    //         004317b2     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004317b7     ADD        ESP,0x4
    //         004317ba     MOV        EAX,ESI
    //         004317bc     POP        EDI
    //         004317bd     POP        ESI
    //         004317be     POP        EBX
    //         004317bf     RET        0x4
    //                               LAB_004317c2                                                 XREF[1]:     0043179b(j)  
    //         004317c2     MOV        EAX,dword ptr [ESI + 0xc]
    //         004317c5     XOR        EBX,EBX
    //         004317c7     CMP        EAX,EBX
    //         004317c9     MOV        dword ptr [ESI],EBX
    //         004317cb     MOV        dword ptr [ESI + 0x4],EBX
    //         004317ce     MOV        byte ptr [ESI + 0x8],BL
    //         004317d1     MOV        dword ptr [ESI + 0x10],EBX
    //         004317d4     MOV        dword ptr [ESI + 0x14],EBX
    //         004317d7     MOV        dword ptr [ESI + 0x18],EBX
    //         004317da     JZ         LAB_004317e5
    //         004317dc     PUSH       EAX
    //         004317dd     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004317e2     ADD        ESP,0x4
    //                               LAB_004317e5                                                 XREF[1]:     004317da(j)  
    //         004317e5     MOV        AL,byte ptr [ESP + param_1]
    //         004317e9     MOV        dword ptr [ESI + 0xc],EBX
    //         004317ec     TEST       AL,0x1
    //         004317ee     JZ         LAB_004317f9
    //         004317f0     PUSH       ESI
    //         004317f1     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004317f6     ADD        ESP,0x4
    //                               LAB_004317f9                                                 XREF[1]:     004317ee(j)  
    //         004317f9     MOV        EAX,ESI
    //         004317fb     POP        EDI
    //         004317fc     POP        ESI
    //         004317fd     POP        EBX
    //         004317fe     RET        0x4
}

