// Auto-generated scaffold unit: InfluenceMap.asm
#include "../include/common.h"

// Offset: 0x0044E030
void* InfluenceMap::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall InfluenceMap::`scalar deleting destructor'(unsigned int)            *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(InfluenceMap * this, 
    //              void *            EAX:4          <RETURN>
    //              InfluenceMap *    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0044e038(R)  
    //                               ??_EInfluenceMap@@UAEPAXI@Z                                  XREF[1]:     00570444(*)  
    //                               ??_GInfluenceMap@@UAEPAXI@Z
    //                               InfluenceMap::`scalar_deleting_destructor'
    //         0044e030     PUSH       ESI
    //         0044e031     MOV        ESI,this
    //         0044e033     CALL       InfluenceMap::~InfluenceMap                      void ~InfluenceMap(InfluenceMap * this)
    //         0044e038     TEST       byte ptr [ESP + param_1],0x1
    //         0044e03d     JZ         LAB_0044e048
    //         0044e03f     PUSH       ESI
    //         0044e040     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0044e045     ADD        ESP,0x4
    //                               LAB_0044e048                                                 XREF[1]:     0044e03d(j)  
    //         0044e048     MOV        EAX,ESI
    //         0044e04a     POP        ESI
    //         0044e04b     RET        0x4
}

