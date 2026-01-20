// Auto-generated scaffold unit: TRIBE_Combat_Object.cpp.asm
#include "../include/common.h"

// Offset: 0x004CA180
void* TRIBE_Combat_Object::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Combat_Object::`vector deleting destructor'(unsigned int)     *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TRIBE_Combat_Object *
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Combat_O    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004ca188(R)  
    //                               ??_GTRIBE_Combat_Object@@UAEPAXI@Z                           XREF[1]:     00574a20(*)  
    //                               ??_ETRIBE_Combat_Object@@UAEPAXI@Z
    //                               TRIBE_Combat_Object::`vector_deleting_destructor'
    //         004ca180     PUSH       ESI
    //         004ca181     MOV        ESI,this
    //         004ca183     CALL       TRIBE_Combat_Object::~TRIBE_Combat_Object        void ~TRIBE_Combat_Object(TRIBE_Combat_Object
    //         004ca188     TEST       byte ptr [ESP + param_1],0x1
    //         004ca18d     JZ         LAB_004ca198
    //         004ca18f     PUSH       ESI
    //         004ca190     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004ca195     ADD        ESP,0x4
    //                               LAB_004ca198                                                 XREF[1]:     004ca18d(j)  
    //         004ca198     MOV        EAX,ESI
    //         004ca19a     POP        ESI
    //         004ca19b     RET        0x4
}

