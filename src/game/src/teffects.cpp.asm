// Auto-generated scaffold unit: teffects.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/teffects.cpp
#include "../include/common.h"

// Offset: 0x0050D460
undefined TRIBE_Effects(TRIBE_Effects* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TRIBE_Effects::TRIBE_Effects(int)                                                  *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TRIBE_Effects(TRIBE_Effects * this, int param_1)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TRIBE_Effects *   ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0050d460(R)  
    //                               ??0TRIBE_Effects@@QAE@H@Z                                    XREF[1]:     effects_init:0052e68a(c)  
    //                               TRIBE_Effects::TRIBE_Effects
    //                              teffects.cpp:22 (19)
    //         0050d460     MOV        EAX,dword ptr [ESP + param_1]
    //         0050d464     PUSH       ESI
    //         0050d465     MOV        ESI,this
    //         0050d467     PUSH       EAX
    //         0050d468     CALL       RGE_Effects::RGE_Effects                         undefined RGE_Effects(RGE_Effects * this, int
    //         0050d46d     MOV        dword ptr [ESI],TRIBE_Effects::`vftable'         = 0050d480
    //                              teffects.cpp:23 (6)
    //         0050d473     MOV        EAX,ESI
    //         0050d475     POP        ESI
    //         0050d476     RET        0x4
}

// Offset: 0x0050D4B0
undefined TRIBE_Effects(TRIBE_Effects* this_, char* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TRIBE_Effects::TRIBE_Effects(char *)                                               *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TRIBE_Effects(TRIBE_Effects * this, char * para
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TRIBE_Effects *   ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     0050d4b0(R)  
    //                               ??0TRIBE_Effects@@QAE@PAD@Z
    //                               TRIBE_Effects::TRIBE_Effects
    //                              teffects.cpp:29 (19)
    //         0050d4b0     MOV        EAX,dword ptr [ESP + param_1]
    //         0050d4b4     PUSH       ESI
    //         0050d4b5     MOV        ESI,this
    //         0050d4b7     PUSH       EAX
    //         0050d4b8     CALL       RGE_Effects::RGE_Effects                         undefined RGE_Effects(RGE_Effects * this, cha
    //         0050d4bd     MOV        dword ptr [ESI],TRIBE_Effects::`vftable'         = 0050d480
    //                              teffects.cpp:30 (6)
    //         0050d4c3     MOV        EAX,ESI
    //         0050d4c5     POP        ESI
    //         0050d4c6     RET        0x4
}

// Offset: 0x0050D4D0
void TRIBE_Effects::do_effect(short param_1, RGE_Player* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall TRIBE_Effects::do_effect(short,class RGE_Player *)                    *
    //                              *********************************************************************************************************
    //                              void __thiscall do_effect(TRIBE_Effects * this, short param_1, RGE_P
    //              void              <VOID>         <RETURN>
    //              TRIBE_Effects *   ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[2]:     0050d4d1(R), 0050d537(R)  
    //              RGE_Player *      Stack[0x8]:4   param_2                   XREF[1]:     0050d4f3(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0050d4dc(W), 0050d532(R)  
    //                               ?do_effect@TRIBE_Effects@@UAEXFPAVRGE_Player@@@Z
    //                               TRIBE_Effects::do_effect
    //                              teffects.cpp:36 (1)
    //         0050d4d0     PUSH       this
    //                              teffects.cpp:41 (17)
    //         0050d4d1     MOVSX      EAX,word ptr [ESP + param_1]
    //         0050d4d6     MOV        EDX,dword ptr [ECX + this->field8_0x8]
    //         0050d4d9     PUSH       ESI
    //         0050d4da     CMP        EAX,EDX
    //         0050d4dc     MOV        dword ptr [ESP + local_4],this
    //         0050d4e0     JGE        LAB_0050d544
    //                              teffects.cpp:44 (12)
    //         0050d4e2     LEA        EDX,[EAX + EAX*0x4]
    //         0050d4e5     LEA        EAX,[EAX + EDX*0x2]
    //         0050d4e8     MOV        EDX,dword ptr [ECX + this->field4_0x4]
    //         0050d4eb     LEA        ESI,[EDX + EAX*0x4]
    //                              teffects.cpp:46 (5)
    //         0050d4ee     TEST       ESI,ESI
    //         0050d4f0     JZ         LAB_0050d544
    //         0050d4f2     PUSH       EBP
    //                              teffects.cpp:49 (14)
    //         0050d4f3     MOV        EBP,dword ptr [ESP + param_2]
    //         0050d4f7     PUSH       EBX
    //         0050d4f8     XOR        EBX,EBX
    //         0050d4fa     CMP        word ptr [ESI + 0x24],BX
    //         0050d4fe     JLE        LAB_0050d537
    //         0050d500     PUSH       EDI
    //                              teffects.cpp:77 (16)
    //         0050d501     XOR        EDI,EDI
    //                               LAB_0050d503                                                 XREF[1]:     0050d530(j)  
    //         0050d503     MOV        EAX,dword ptr [ESI + 0x28]
    //         0050d506     XOR        this,this
    //         0050d508     ADD        EAX,EDI
    //         0050d50a     MOV        this,byte ptr [EAX]
    //         0050d50c     SUB        this,0x65
    //         0050d50f     JZ         LAB_0050d526
    //                              teffects.cpp:52 (3)
    //         0050d511     DEC        this
    //         0050d512     JNZ        LAB_0050d526
    //                              teffects.cpp:65 (35)
    //         0050d514     FLD        float ptr [EAX + 0x8]
    //         0050d517     PUSH       0x0
    //         0050d519     CALL       __ftol                                           undefined __ftol()
    //         0050d51e     PUSH       EAX
    //         0050d51f     MOV        this,EBP
    //         0050d521     CALL       TRIBE_Player::tech_abling                        void tech_abling(TRIBE_Player * this, long pa
    //                               LAB_0050d526                                                 XREF[2]:     0050d50f(j), 0050d512(j)  
    //         0050d526     MOVSX      EAX,word ptr [ESI + 0x24]
    //         0050d52a     INC        EBX
    //         0050d52b     ADD        EDI,0xc
    //         0050d52e     CMP        EBX,EAX
    //         0050d530     JL         LAB_0050d503
    //         0050d532     MOV        this,dword ptr [ESP + local_4]
    //         0050d536     POP        EDI
    //                               LAB_0050d537                                                 XREF[1]:     0050d4fe(j)  
    //                              teffects.cpp:76 (13)
    //         0050d537     MOV        EDX,dword ptr [ESP + param_1]
    //         0050d53b     PUSH       EBP
    //         0050d53c     PUSH       EDX
    //         0050d53d     CALL       RGE_Effects::do_effect                           void do_effect(RGE_Effects * this, short para
    //         0050d542     POP        EBX
    //         0050d543     POP        EBP
    //                               LAB_0050d544                                                 XREF[2]:     0050d4e0(j), 0050d4f0(j)  
    //                              teffects.cpp:77 (5)
    //         0050d544     POP        ESI
    //         0050d545     POP        this
    //         0050d546     RET        0x8
}

// Offset: 0x0050D550
void do_tech_effect(TRIBE_Effects* this_, short param_2, RGE_Player* param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TRIBE_Effects::do_tech_effect(short,class RGE_Player *)                       *
    //                              *********************************************************************************************************
    //                              void __thiscall do_tech_effect(TRIBE_Effects * this, short param_1, 
    //              void              <VOID>         <RETURN>
    //              TRIBE_Effects *   ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[1]:     0050d550(R)  
    //              RGE_Player *      Stack[0x8]:4   param_2                   XREF[1]:     0050d56e(R)  
    //                               ?do_tech_effect@TRIBE_Effects@@QAEXFPAVRGE_Player@@@Z        XREF[1]:     scenario_load:00512861(c)  
    //                               TRIBE_Effects::do_tech_effect
    //                              teffects.cpp:83 (13)
    //         0050d550     MOVSX      EAX,word ptr [ESP + param_1]
    //         0050d555     MOV        this,dword ptr [ECX + this->field4_0x4]
    //         0050d558     PUSH       EBX
    //         0050d559     LEA        EDX,[EAX + EAX*0x4]
    //         0050d55c     PUSH       ESI
    //                              teffects.cpp:88 (23)
    //         0050d55d     XOR        EBX,EBX
    //         0050d55f     LEA        EAX,[EAX + EDX*0x2]
    //         0050d562     CMP        word ptr [this->field0_0x0 + EAX*0x4 + 0x24],BX
    //         0050d567     LEA        ESI,[this->field0_0x0 + EAX*0x4]
    //         0050d56a     JLE        LAB_0050d5a5
    //         0050d56c     PUSH       EDI
    //         0050d56d     PUSH       EBP
    //         0050d56e     MOV        EBP,dword ptr [ESP + param_2]
    //         0050d572     XOR        EDI,EDI
    //                               LAB_0050d574                                                 XREF[1]:     0050d5a1(j)  
    //                              teffects.cpp:90 (3)
    //         0050d574     MOV        EAX,dword ptr [ESI + 0x28]
    //                              teffects.cpp:91 (14)
    //         0050d577     XOR        this,this
    //         0050d579     ADD        EAX,EDI
    //         0050d57b     MOV        this,byte ptr [EAX]
    //         0050d57d     SUB        this,0x65
    //         0050d580     JZ         LAB_0050d597
    //         0050d582     DEC        this
    //         0050d583     JNZ        LAB_0050d597
    //                              teffects.cpp:104 (32)
    //         0050d585     FLD        float ptr [EAX + 0x8]
    //         0050d588     PUSH       0x0
    //         0050d58a     CALL       __ftol                                           undefined __ftol()
    //         0050d58f     PUSH       EAX
    //         0050d590     MOV        this,EBP
    //         0050d592     CALL       TRIBE_Player::tech_abling                        void tech_abling(TRIBE_Player * this, long pa
    //                               LAB_0050d597                                                 XREF[2]:     0050d580(j), 0050d583(j)  
    //         0050d597     MOVSX      EDX,word ptr [ESI + 0x24]
    //         0050d59b     INC        EBX
    //         0050d59c     ADD        EDI,0xc
    //         0050d59f     CMP        EBX,EDX
    //         0050d5a1     JL         LAB_0050d574
    //         0050d5a3     POP        EBP
    //         0050d5a4     POP        EDI
    //                               LAB_0050d5a5                                                 XREF[1]:     0050d56a(j)  
    //                              teffects.cpp:114 (5)
    //         0050d5a5     POP        ESI
    //         0050d5a6     POP        EBX
    //         0050d5a7     RET        0x8
}

