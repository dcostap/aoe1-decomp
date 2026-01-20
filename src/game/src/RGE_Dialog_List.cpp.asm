// Auto-generated scaffold unit: RGE_Dialog_List.cpp.asm
#include "../include/common.h"

// Offset: 0x0047E690
void* RGE_Dialog_List::scalar_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall RGE_Dialog_List::`scalar deleting destructor'(unsigned int)         *
    //                              *********************************************************************************************************
    //                              void * __thiscall `scalar_deleting_destructor'(RGE_Dialog_List * thi
    //              void *            EAX:4          <RETURN>
    //              RGE_Dialog_Lis    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0047e698(R)  
    //                               ??_ERGE_Dialog_List@@UAEPAXI@Z                               XREF[1]:     00571cf0(*)  
    //                               ??_GRGE_Dialog_List@@UAEPAXI@Z
    //                               RGE_Dialog_List::`scalar_deleting_destructor'
    //         0047e690     PUSH       ESI
    //         0047e691     MOV        ESI,this
    //         0047e693     CALL       RGE_Dialog_List::~RGE_Dialog_List                void ~RGE_Dialog_List(RGE_Dialog_List * this)
    //         0047e698     TEST       byte ptr [ESP + param_1],0x1
    //         0047e69d     JZ         LAB_0047e6a8
    //         0047e69f     PUSH       ESI
    //         0047e6a0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0047e6a5     ADD        ESP,0x4
    //                               LAB_0047e6a8                                                 XREF[1]:     0047e69d(j)  
    //         0047e6a8     MOV        EAX,ESI
    //         0047e6aa     POP        ESI
    //         0047e6ab     RET        0x4
}

