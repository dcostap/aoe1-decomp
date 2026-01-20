// Auto-generated scaffold unit: RGE_Missile_Object.cpp.asm
#include "../include/common.h"

// Offset: 0x0045A7D0
void* RGE_Missile_Object::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall RGE_Missile_Object::`scalar deleting destructor'(unsigned int)      *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(RGE_Missile_Object * 
    //              void *            EAX:4          <RETURN>
    //              RGE_Missile_Ob    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0045a7d8(R)  
    //                               ??_ERGE_Missile_Object@@UAEPAXI@Z                            XREF[1]:     005706f0(*)  
    //                               ??_GRGE_Missile_Object@@UAEPAXI@Z
    //                               RGE_Missile_Object::`scalar_deleting_destructor'
    //         0045a7d0     PUSH       ESI
    //         0045a7d1     MOV        ESI,this
    //         0045a7d3     CALL       RGE_Missile_Object::~RGE_Missile_Object          void ~RGE_Missile_Object(RGE_Missile_Object *
    //         0045a7d8     TEST       byte ptr [ESP + param_1],0x1
    //         0045a7dd     JZ         LAB_0045a7e8
    //         0045a7df     PUSH       ESI
    //         0045a7e0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0045a7e5     ADD        ESP,0x4
    //                               LAB_0045a7e8                                                 XREF[1]:     0045a7dd(j)  
    //         0045a7e8     MOV        EAX,ESI
    //         0045a7ea     POP        ESI
    //         0045a7eb     RET        0x4
}

