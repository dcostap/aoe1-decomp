// Auto-generated scaffold unit: TribeAchievementsScreen.cpp.asm
#include "../include/common.h"

// Offset: 0x0048E1F0
void* TribeAchievementsScreen::vector_deleting_destructor(uint param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void * __thiscall TribeAchievementsScreen::`vector deleting destructor'(unsigned int) *
    //                              *********************************************************************************************************
    //                              void * __thiscall `vector_deleting_destructor'(TribeAchievementsScre
    //              void *            EAX:4          <RETURN>
    //              TribeAchieveme    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0048e1f8(R)  
    //                               ??_GTribeAchievementsScreen@@UAEPAXI@Z                       XREF[1]:     00572180(*)  
    //                               ??_ETribeAchievementsScreen@@UAEPAXI@Z
    //                               TribeAchievementsScreen::`vector_deleting_destructor'
    //         0048e1f0     PUSH       ESI
    //         0048e1f1     MOV        ESI,this
    //         0048e1f3     CALL       TribeAchievementsScreen::~TribeAchievementsScr   void ~TribeAchievementsScreen(TribeAchievemen
    //         0048e1f8     TEST       byte ptr [ESP + param_1],0x1
    //         0048e1fd     JZ         LAB_0048e208
    //         0048e1ff     PUSH       ESI
    //         0048e200     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0048e205     ADD        ESP,0x4
    //                               LAB_0048e208                                                 XREF[1]:     0048e1fd(j)  
    //         0048e208     MOV        EAX,ESI
    //         0048e20a     POP        ESI
    //         0048e20b     RET        0x4
}

