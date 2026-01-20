// Auto-generated scaffold unit: RGE_Master_Missile_Object.cpp.asm
#include "../include/common.h"

// Offset: 0x004514A0
void* RGE_Master_Missile_Object::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall RGE_Master_Missile_Object::`vector deleting destructor'(unsigned... *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(RGE_Master_Missile_Ob
    //              void *            EAX:4          <RETURN>
    //              RGE_Master_Mis    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004514a8(R)  
    //                               ??_GRGE_Master_Missile_Object@@UAEPAXI@Z                     XREF[1]:     00570560(*)  
    //                               ??_ERGE_Master_Missile_Object@@UAEPAXI@Z
    //                               RGE_Master_Missile_Object::`vector_deleting_destructor'
    //         004514a0     PUSH       ESI
    //         004514a1     MOV        ESI,this
    //         004514a3     CALL       RGE_Master_Missile_Object::~RGE_Master_Missile   void ~RGE_Master_Missile_Object(RGE_Master_Mi
    //         004514a8     TEST       byte ptr [ESP + param_1],0x1
    //         004514ad     JZ         LAB_004514b8
    //         004514af     PUSH       ESI
    //         004514b0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004514b5     ADD        ESP,0x4
    //                               LAB_004514b8                                                 XREF[1]:     004514ad(j)  
    //         004514b8     MOV        EAX,ESI
    //         004514ba     POP        ESI
    //         004514bb     RET        0x4
}

