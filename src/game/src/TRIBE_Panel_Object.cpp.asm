// Auto-generated scaffold unit: TRIBE_Panel_Object.cpp.asm
#include "../include/common.h"

// Offset: 0x0051B050
void* TRIBE_Panel_Object::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TRIBE_Panel_Object::`scalar deleting destructor'(unsigned int)      *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(TRIBE_Panel_Object * 
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Panel_Ob    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0051b058(R)  
    //                               ??_ETRIBE_Panel_Object@@UAEPAXI@Z                            XREF[1]:     00576c98(*)  
    //                               ??_GTRIBE_Panel_Object@@UAEPAXI@Z
    //                               TRIBE_Panel_Object::`scalar_deleting_destructor'
    //         0051b050     PUSH       ESI
    //         0051b051     MOV        ESI,this
    //         0051b053     CALL       TRIBE_Panel_Object::~TRIBE_Panel_Object          void ~TRIBE_Panel_Object(TRIBE_Panel_Object *
    //         0051b058     TEST       byte ptr [ESP + param_1],0x1
    //         0051b05d     JZ         LAB_0051b068
    //         0051b05f     PUSH       ESI
    //         0051b060     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0051b065     ADD        ESP,0x4
    //                               LAB_0051b068                                                 XREF[1]:     0051b05d(j)  
    //         0051b068     MOV        EAX,ESI
    //         0051b06a     POP        ESI
    //         0051b06b     RET        0x4
}

