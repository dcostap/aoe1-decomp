// Auto-generated scaffold unit: TRIBE_Action_Convert.asm
#include "../include/common.h"

// Offset: 0x004CDA60
void* TRIBE_Action_Convert::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Action_Convert::`vector deleting destructor'(unsigned int)    *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TRIBE_Action_Convert 
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Action_C    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004cda68(R)  
    //                               ??_GTRIBE_Action_Convert@@UAEPAXI@Z                          XREF[1]:     00574f90(*)  
    //                               ??_ETRIBE_Action_Convert@@UAEPAXI@Z
    //                               TRIBE_Action_Convert::`vector_deleting_destructor'
    //         004cda60     PUSH       ESI
    //         004cda61     MOV        ESI,this
    //         004cda63     CALL       TRIBE_Action_Convert::~TRIBE_Action_Convert      void ~TRIBE_Action_Convert(TRIBE_Action_Conve
    //         004cda68     TEST       byte ptr [ESP + param_1],0x1
    //         004cda6d     JZ         LAB_004cda78
    //         004cda6f     PUSH       ESI
    //         004cda70     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004cda75     ADD        ESP,0x4
    //                               LAB_004cda78                                                 XREF[1]:     004cda6d(j)  
    //         004cda78     MOV        EAX,ESI
    //         004cda7a     POP        ESI
    //         004cda7b     RET        0x4
}

