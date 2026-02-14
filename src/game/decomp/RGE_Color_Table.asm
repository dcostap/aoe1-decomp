// Auto-generated scaffold unit: RGE_Color_Table.asm
#include "../include/common.h"

// Offset: 0x00424420
void* RGE_Color_Table::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall RGE_Color_Table::`scalar deleting destructor'(unsigned int)         *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(RGE_Color_Table * thi
    //              void *            EAX:4          <RETURN>
    //              RGE_Color_Tabl    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00424428(R)  
    //                               ??_ERGE_Color_Table@@UAEPAXI@Z                               XREF[1]:     0056f038(*)  
    //                               ??_GRGE_Color_Table@@UAEPAXI@Z
    //                               RGE_Color_Table::`scalar_deleting_destructor'
    //         00424420     PUSH       ESI
    //         00424421     MOV        ESI,this
    //         00424423     CALL       RGE_Color_Table::~RGE_Color_Table                void ~RGE_Color_Table(RGE_Color_Table * this)
    //         00424428     TEST       byte ptr [ESP + param_1],0x1
    //         0042442d     JZ         LAB_00424438
    //         0042442f     PUSH       ESI
    //         00424430     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00424435     ADD        ESP,0x4
    //                               LAB_00424438                                                 XREF[1]:     0042442d(j)  
    //         00424438     MOV        EAX,ESI
    //         0042443a     POP        ESI
    //         0042443b     RET        0x4
}

