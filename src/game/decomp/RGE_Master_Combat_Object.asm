// Auto-generated scaffold unit: RGE_Master_Combat_Object.asm
#include "../include/common.h"

// Offset: 0x0044FEA0
void* RGE_Master_Combat_Object::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall RGE_Master_Combat_Object::`vector deleting destructor'(unsigned ... *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(RGE_Master_Combat_Obj
    //              void *            EAX:4          <RETURN>
    //              RGE_Master_Com    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0044fea8(R)  
    //                               ??_GRGE_Master_Combat_Object@@UAEPAXI@Z                      XREF[1]:     005704c0(*)  
    //                               ??_ERGE_Master_Combat_Object@@UAEPAXI@Z
    //                               RGE_Master_Combat_Object::`vector_deleting_destructor'
    //         0044fea0     PUSH       ESI
    //         0044fea1     MOV        ESI,this
    //         0044fea3     CALL       RGE_Master_Combat_Object::~RGE_Master_Combat_O   void ~RGE_Master_Combat_Object(RGE_Master_Com
    //         0044fea8     TEST       byte ptr [ESP + param_1],0x1
    //         0044fead     JZ         LAB_0044feb8
    //         0044feaf     PUSH       ESI
    //         0044feb0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0044feb5     ADD        ESP,0x4
    //                               LAB_0044feb8                                                 XREF[1]:     0044fead(j)  
    //         0044feb8     MOV        EAX,ESI
    //         0044feba     POP        ESI
    //         0044febb     RET        0x4
}

