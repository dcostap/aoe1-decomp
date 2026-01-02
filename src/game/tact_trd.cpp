#include "../common.h"
#include "tact_trd.h"

TRIBE_Action_Trade::TRIBE_Action_Trade(int param_1, RGE_Action_Object* param_2) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Action_Trade(TRIBE_Action_Trade * this, R
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Action_T    ECX:4 (auto)   this
//              RGE_Action_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004d27a0(R)
//              RGE_Task *        Stack[0x8]:4   param_2                   XREF[1]:     004d27b3(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     004d27b7(R)
//              float             Stack[0x10]:4  param_4                   XREF[1]:     004d27af(R)
//              float             Stack[0x14]:4  param_5                   XREF[1]:     004d27c1(R)
//                               ??0TRIBE_Action_Trade@@QAE@PAVRGE_Action_Object@@PAVRGE_Tas  XREF[1]:     create_task_action:004d0ac1(c)
//                               TRIBE_Action_Trade::TRIBE_Action_Trade
//                              tact_trd.cpp:77 (15)
//         004d27a0     MOV        EAX,dword ptr [ESP + param_1]
//         004d27a4     PUSH       ESI
//         004d27a5     PUSH       0x1
//         004d27a7     MOV        ESI,this
//         004d27a9     PUSH       EAX
//         004d27aa     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, RGE_A
//                              tact_trd.cpp:81 (18)
//         004d27af     MOV        EAX,dword ptr [ESP + param_4]
//         004d27b3     MOV        this,dword ptr [ESP + param_2]
//         004d27b7     MOV        EDX,dword ptr [ESP + param_3]
//         004d27bb     MOV        dword ptr [ESI + 0x24],EAX
//         004d27be     MOV        dword ptr [ESI + 0x30],this
//                              tact_trd.cpp:82 (4)
//         004d27c1     MOV        this,dword ptr [ESP + param_5]
//                              tact_trd.cpp:84 (14)
//         004d27c5     MOV        EAX,0xbf800000
//         004d27ca     MOV        dword ptr [ESI],TRIBE_Action_Trade::`vftable'    = 004d26e0
//         004d27d0     MOV        dword ptr [ESI + 0x40],EAX
//                              tact_trd.cpp:85 (15)
//         004d27d3     MOV        dword ptr [ESI + 0x44],EAX
//         004d27d6     MOV        word ptr [ESI + 0x4],0x6f
//         004d27dc     MOV        dword ptr [ESI + 0x20],EDX
//         004d27df     MOV        dword ptr [ESI + 0x28],this
//                              tact_trd.cpp:91 (6)
//         004d27e2     MOV        EAX,ESI
//         004d27e4     POP        ESI
//         004d27e5     RET        0x14
//         004d27e8     ??         90h
//         004d27e9     NOP
//         004d27ea     NOP
//         004d27eb     NOP
//         004d27ec     NOP
//         004d27ed     NOP
//         004d27ee     NOP
//         004d27ef     NOP
}

TRIBE_Action_Trade::TRIBE_Action_Trade(RGE_Action_Object* param_1, RGE_Task* param_2, RGE_Static_Object* param_3) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Action_Trade(TRIBE_Action_Trade * this, R
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Action_T    ECX:4 (auto)   this
//              RGE_Action_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004d27a0(R)
//              RGE_Task *        Stack[0x8]:4   param_2                   XREF[1]:     004d27b3(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     004d27b7(R)
//              float             Stack[0x10]:4  param_4                   XREF[1]:     004d27af(R)
//              float             Stack[0x14]:4  param_5                   XREF[1]:     004d27c1(R)
//                               ??0TRIBE_Action_Trade@@QAE@PAVRGE_Action_Object@@PAVRGE_Tas  XREF[1]:     create_task_action:004d0ac1(c)
//                               TRIBE_Action_Trade::TRIBE_Action_Trade
//                              tact_trd.cpp:77 (15)
//         004d27a0     MOV        EAX,dword ptr [ESP + param_1]
//         004d27a4     PUSH       ESI
//         004d27a5     PUSH       0x1
//         004d27a7     MOV        ESI,this
//         004d27a9     PUSH       EAX
//         004d27aa     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, RGE_A
//                              tact_trd.cpp:81 (18)
//         004d27af     MOV        EAX,dword ptr [ESP + param_4]
//         004d27b3     MOV        this,dword ptr [ESP + param_2]
//         004d27b7     MOV        EDX,dword ptr [ESP + param_3]
//         004d27bb     MOV        dword ptr [ESI + 0x24],EAX
//         004d27be     MOV        dword ptr [ESI + 0x30],this
//                              tact_trd.cpp:82 (4)
//         004d27c1     MOV        this,dword ptr [ESP + param_5]
//                              tact_trd.cpp:84 (14)
//         004d27c5     MOV        EAX,0xbf800000
//         004d27ca     MOV        dword ptr [ESI],TRIBE_Action_Trade::`vftable'    = 004d26e0
//         004d27d0     MOV        dword ptr [ESI + 0x40],EAX
//                              tact_trd.cpp:85 (15)
//         004d27d3     MOV        dword ptr [ESI + 0x44],EAX
//         004d27d6     MOV        word ptr [ESI + 0x4],0x6f
//         004d27dc     MOV        dword ptr [ESI + 0x20],EDX
//         004d27df     MOV        dword ptr [ESI + 0x28],this
//                              tact_trd.cpp:91 (6)
//         004d27e2     MOV        EAX,ESI
//         004d27e4     POP        ESI
//         004d27e5     RET        0x14
//         004d27e8     ??         90h
//         004d27e9     NOP
//         004d27ea     NOP
//         004d27eb     NOP
//         004d27ec     NOP
//         004d27ed     NOP
//         004d27ee     NOP
//         004d27ef     NOP
}

TRIBE_Action_Trade::TRIBE_Action_Trade(RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Action_Trade(TRIBE_Action_Trade * this, R
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Action_T    ECX:4 (auto)   this
//              RGE_Action_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004d27a0(R)
//              RGE_Task *        Stack[0x8]:4   param_2                   XREF[1]:     004d27b3(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     004d27b7(R)
//              float             Stack[0x10]:4  param_4                   XREF[1]:     004d27af(R)
//              float             Stack[0x14]:4  param_5                   XREF[1]:     004d27c1(R)
//                               ??0TRIBE_Action_Trade@@QAE@PAVRGE_Action_Object@@PAVRGE_Tas  XREF[1]:     create_task_action:004d0ac1(c)
//                               TRIBE_Action_Trade::TRIBE_Action_Trade
//                              tact_trd.cpp:77 (15)
//         004d27a0     MOV        EAX,dword ptr [ESP + param_1]
//         004d27a4     PUSH       ESI
//         004d27a5     PUSH       0x1
//         004d27a7     MOV        ESI,this
//         004d27a9     PUSH       EAX
//         004d27aa     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, RGE_A
//                              tact_trd.cpp:81 (18)
//         004d27af     MOV        EAX,dword ptr [ESP + param_4]
//         004d27b3     MOV        this,dword ptr [ESP + param_2]
//         004d27b7     MOV        EDX,dword ptr [ESP + param_3]
//         004d27bb     MOV        dword ptr [ESI + 0x24],EAX
//         004d27be     MOV        dword ptr [ESI + 0x30],this
//                              tact_trd.cpp:82 (4)
//         004d27c1     MOV        this,dword ptr [ESP + param_5]
//                              tact_trd.cpp:84 (14)
//         004d27c5     MOV        EAX,0xbf800000
//         004d27ca     MOV        dword ptr [ESI],TRIBE_Action_Trade::`vftable'    = 004d26e0
//         004d27d0     MOV        dword ptr [ESI + 0x40],EAX
//                              tact_trd.cpp:85 (15)
//         004d27d3     MOV        dword ptr [ESI + 0x44],EAX
//         004d27d6     MOV        word ptr [ESI + 0x4],0x6f
//         004d27dc     MOV        dword ptr [ESI + 0x20],EDX
//         004d27df     MOV        dword ptr [ESI + 0x28],this
//                              tact_trd.cpp:91 (6)
//         004d27e2     MOV        EAX,ESI
//         004d27e4     POP        ESI
//         004d27e5     RET        0x14
//         004d27e8     ??         90h
//         004d27e9     NOP
//         004d27ea     NOP
//         004d27eb     NOP
//         004d27ec     NOP
//         004d27ed     NOP
//         004d27ee     NOP
//         004d27ef     NOP
}

void TRIBE_Action_Trade::save(int param_1) {
    /* TODO: Stub */
//                              void __thiscall save(TRIBE_Action_Trade * this, int param_1)
//              void              <VOID>         <RETURN>
//              TRIBE_Action_T    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004d27f2(R)
//                               ?save@TRIBE_Action_Trade@@UAEXH@Z                            XREF[1]:     005752fc(*)
//                               TRIBE_Action_Trade::save
//                              tact_trd.cpp:98 (2)
//         004d27f0     PUSH       ESI
//         004d27f1     PUSH       EDI
//                              tact_trd.cpp:99 (12)
//         004d27f2     MOV        EDI,dword ptr [ESP + param_1]
//         004d27f6     MOV        ESI,this
//         004d27f8     PUSH       EDI
//         004d27f9     CALL       RGE_Action::save                                 void save(RGE_Action * this, int param_1)
//                              tact_trd.cpp:101 (15)
//         004d27fe     LEA        EAX,[ESI + 0x40]
//         004d2801     PUSH       0x4
//         004d2803     PUSH       EAX
//         004d2804     PUSH       EDI
//         004d2805     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004d280a     ADD        ESP,0xc
//                              tact_trd.cpp:102 (15)
//         004d280d     ADD        ESI,0x44
//         004d2810     PUSH       0x4
//         004d2812     PUSH       ESI
//         004d2813     PUSH       EDI
//         004d2814     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004d2819     ADD        ESP,0xc
//                              tact_trd.cpp:103 (5)
//         004d281c     POP        EDI
//         004d281d     POP        ESI
//         004d281e     RET        0x4
//         004d2821     ??         90h
//         004d2822     NOP
//         004d2823     NOP
//         004d2824     NOP
//         004d2825     NOP
//         004d2826     NOP
//         004d2827     NOP
//         004d2828     NOP
//         004d2829     NOP
//         004d282a     NOP
//         004d282b     NOP
//         004d282c     NOP
//         004d282d     NOP
//         004d282e     NOP
//         004d282f     NOP
    return;
}

void TRIBE_Action_Trade::first_in_stack(uchar param_1) {
    /* TODO: Stub */
//                              void __thiscall first_in_stack(TRIBE_Action_Trade * this, uchar para
//              void              <VOID>         <RETURN>
//              TRIBE_Action_T    ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     004d284e(R)
//                               ?first_in_stack@TRIBE_Action_Trade@@UAEXE@Z                  XREF[1]:     00575304(*)
//                               TRIBE_Action_Trade::first_in_stack
//                              tact_trd.cpp:109 (24)
//         004d2830     MOV        EDX,dword ptr [ECX + this->_padding_]
//         004d2833     MOV        AX,word ptr [EDX + 0x4c]
//         004d2837     TEST       AX,AX
//         004d283a     JZ         LAB_004d284e
//         004d283c     CMP        AX,0x2
//         004d2840     JZ         LAB_004d284e
//         004d2842     CMP        AX,0x1
//         004d2846     JZ         LAB_004d284e
//                              tact_trd.cpp:117 (6)
//         004d2848     MOV        word ptr [EDX + 0x4c],0x1
//                               LAB_004d284e                                                 XREF[3]:     004d283a(j), 004d2840(j),
//                                                                                                         004d2846(j)
//                              tact_trd.cpp:119 (8)
//         004d284e     MOV        AL,byte ptr [ESP + param_1]
//         004d2852     TEST       AL,AL
//         004d2854     JZ         LAB_004d2871
//                              tact_trd.cpp:121 (7)
//         004d2856     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004d2859     TEST       EAX,EAX
//         004d285b     JZ         LAB_004d2867
//                              tact_trd.cpp:122 (4)
//         004d285d     MOV        EAX,dword ptr [this->_padding_]
//         004d285f     PUSH       0x4
//                              tact_trd.cpp:127 (3)
//         004d2861     CALL       dword ptr [EAX + 0x5c]
//                              tact_trd.cpp:128 (3)
//         004d2864     RET        0x4
//                               LAB_004d2867                                                 XREF[1]:     004d285b(j)
//                              tact_trd.cpp:124 (7)
//         004d2867     MOV        EDX,dword ptr [this->_padding_]
//         004d2869     PUSH       0x2
//         004d286b     CALL       dword ptr [EDX + 0x5c]
//                              tact_trd.cpp:128 (3)
//         004d286e     RET        0x4
//                               LAB_004d2871                                                 XREF[1]:     004d2854(j)
//                              tact_trd.cpp:127 (7)
//         004d2871     MOV        EAX,dword ptr [this->_padding_]
//         004d2873     PUSH       0x3
//         004d2875     CALL       dword ptr [EAX + 0x5c]
//                              tact_trd.cpp:128 (3)
//         004d2878     RET        0x4
//         004d287b     ??         90h
//         004d287c     NOP
//         004d287d     NOP
//         004d287e     NOP
//         004d287f     NOP
    return;
}

void TRIBE_Action_Trade::set_state(uchar param_1) {
    /* TODO: Stub */
//                              void __thiscall set_state(TRIBE_Action_Trade * this, uchar param_1)
//              void              <VOID>         <RETURN>
//              TRIBE_Action_T    ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[3]:     004d28a2(R), 004d2957(W), 004d2a1f(W)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     004d295d(W), 004d2990(W), 004d2a25(W), 004d2ba5(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     004d29c9(R), 004d2c68(R)
//                               ?set_state@TRIBE_Action_Trade@@MAEXE@Z                       XREF[1]:     00575344(*)
//                               TRIBE_Action_Trade::set_state
//                              tact_trd.cpp:134 (26)
//         004d2880     MOV        EAX,FS:[0x0]
//         004d2886     PUSH       -0x1
//         004d2888     PUSH       FUN_005601e1
//         004d288d     PUSH       EAX
//         004d288e     MOV        dword ptr FS:[0x0],ESP
//         004d2895     PUSH       EBX
//         004d2896     PUSH       ESI
//         004d2897     MOV        ESI,this
//         004d2899     PUSH       EDI
//                              tact_trd.cpp:143 (8)
//         004d289a     MOV        this,dword ptr [ESI + 0x34]
//         004d289d     CALL       RGE_Action_List::delete_list                     void delete_list(RGE_Action_List * this)
//                              tact_trd.cpp:145 (7)
//         004d28a2     MOV        EAX,dword ptr [ESP + param_1]
//         004d28a6     MOV        byte ptr [ESI + 0xc],AL
//                              tact_trd.cpp:147 (24)
//         004d28a9     AND        EAX,0xff
//         004d28ae     ADD        EAX,-0x2
//         004d28b1     CMP        EAX,0x9
//         004d28b4     JA         switchD_004d28ba::caseD_5
//                               switchD_004d28ba::switchD
//         004d28ba     JMP        dword ptr [EAX*0x4 + switchD_004d28ba::switchd   = 004d2906
//                               switchD_004d28ba::caseD_3                                    XREF[2]:     004d28ba(j), 004d2c80(*)
//                              tact_trd.cpp:150 (30)
//         004d28c1     MOV        this,dword ptr [ESI + 0x8]
//         004d28c4     PUSH       0x0
//         004d28c6     PUSH       0x0
//         004d28c8     PUSH       0x267
//         004d28cd     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004d28d0     MOV        EDX,dword ptr [this->_padding_]
//         004d28d2     PUSH       0x202
//         004d28d7     PUSH       EAX
//         004d28d8     PUSH       EAX
//         004d28d9     CALL       dword ptr [EDX + 0x148]
//                              tact_trd.cpp:151 (19)
//         004d28df     MOV        EAX,dword ptr [ESI + 0x8]
//         004d28e2     MOV        this,ESI
//         004d28e4     MOV        EDI,dword ptr [EAX]
//         004d28e6     CALL       TRIBE_Action_Trade::get_wait_sprite              RGE_Sprite * get_wait_sprite(TRIBE_Action_Tra
//         004d28eb     MOV        this,dword ptr [ESI + 0x8]
//         004d28ee     PUSH       EAX
//         004d28ef     CALL       dword ptr [EDI + 0x38]
//                              tact_trd.cpp:275 (20)
//         004d28f2     MOV        this,dword ptr [ESP + 0xc]
//         004d28f6     MOV        dword ptr FS:[0x0],this
//         004d28fd     POP        EDI
//         004d28fe     POP        ESI
//         004d28ff     POP        EBX
//         004d2900     ADD        ESP,0xc
//         004d2903     RET        0x4
//                               switchD_004d28ba::caseD_2                                    XREF[2]:     004d28ba(j), 004d2c7c(*)
//                              tact_trd.cpp:155 (19)
//         004d2906     MOV        this,dword ptr [ESI + 0x8]
//         004d2909     MOV        EDI,dword ptr [this->_padding_]
//         004d290b     MOV        this,ESI
//         004d290d     CALL       TRIBE_Action_Trade::get_wait_sprite              RGE_Sprite * get_wait_sprite(TRIBE_Action_Tra
//         004d2912     MOV        this,dword ptr [ESI + 0x8]
//         004d2915     PUSH       EAX
//         004d2916     CALL       dword ptr [EDI + 0x38]
//                              tact_trd.cpp:156 (9)
//         004d2919     MOV        EDI,dword ptr [ESI]
//         004d291b     PUSH       0x0
//         004d291d     MOV        this,ESI
//         004d291f     CALL       dword ptr [EDI + 0x54]
//                              tact_trd.cpp:157 (7)
//         004d2922     PUSH       0x0
//         004d2924     MOV        this,ESI
//         004d2926     CALL       dword ptr [EDI + 0x58]
//                              tact_trd.cpp:158 (8)
//         004d2929     MOV        EAX,0xbf800000
//         004d292e     MOV        dword ptr [ESI + 0x20],EAX
//                              tact_trd.cpp:159 (3)
//         004d2931     MOV        dword ptr [ESI + 0x24],EAX
//                              tact_trd.cpp:160 (3)
//         004d2934     MOV        dword ptr [ESI + 0x28],EAX
//                              tact_trd.cpp:275 (20)
//         004d2937     MOV        this,dword ptr [ESP + 0xc]
//         004d293b     MOV        dword ptr FS:[0x0],this
//         004d2942     POP        EDI
//         004d2943     POP        ESI
//         004d2944     POP        EBX
//         004d2945     ADD        ESP,0xc
//         004d2948     RET        0x4
//                               switchD_004d28ba::caseD_b                                    XREF[2]:     004d28ba(j), 004d2ca0(*)
//                              tact_trd.cpp:166 (67)
//         004d294b     PUSH       0x44
//         004d294d     CALL       operator_new                                     void * operator_new(uint param_1)
//         004d2952     MOV        EDI,EAX
//         004d2954     ADD        ESP,0x4
//         004d2957     MOV        dword ptr [ESP + param_1],EDI
//         004d295b     TEST       EDI,EDI
//         004d295d     MOV        dword ptr [ESP + local_4],0x0
//         004d2965     JZ         LAB_004d298c
//         004d2967     MOV        this,ESI
//         004d2969     CALL       TRIBE_Action_Trade::get_move_sprite              RGE_Sprite * get_move_sprite(TRIBE_Action_Tra
//         004d296e     MOV        EDX,dword ptr [ESI + 0x28]
//         004d2971     MOV        this,dword ptr [ESI + 0x20]
//         004d2974     PUSH       EAX
//         004d2975     MOV        EAX,dword ptr [ESI + 0x24]
//         004d2978     PUSH       0x0
//         004d297a     PUSH       EDX
//         004d297b     MOV        EDX,dword ptr [ESI + 0x8]
//         004d297e     PUSH       EAX
//         004d297f     PUSH       this
//         004d2980     PUSH       EDX
//         004d2981     MOV        this,EDI
//         004d2983     CALL       RGE_Action_Move_To::RGE_Action_Move_To           undefined RGE_Action_Move_To(RGE_Action_Move_
//         004d2988     MOV        EDI,EAX
//         004d298a     JMP        LAB_004d298e
//                               LAB_004d298c                                                 XREF[1]:     004d2965(j)
//         004d298c     XOR        EDI,EDI
//                               LAB_004d298e                                                 XREF[1]:     004d298a(j)
//                              tact_trd.cpp:167 (12)
//         004d298e     TEST       EDI,EDI
//         004d2990     MOV        dword ptr [ESP + local_4],0xffffffff
//         004d2998     JNZ        LAB_004d29b7
//                              tact_trd.cpp:169 (9)
//         004d299a     MOV        EAX,dword ptr [ESI]
//         004d299c     PUSH       0xd
//         004d299e     MOV        this,ESI
//         004d29a0     CALL       dword ptr [EAX + 0x5c]
//                              tact_trd.cpp:275 (20)
//         004d29a3     MOV        this,dword ptr [ESP + 0xc]
//         004d29a7     MOV        dword ptr FS:[0x0],this
//         004d29ae     POP        EDI
//         004d29af     POP        ESI
//         004d29b0     POP        EBX
//         004d29b1     ADD        ESP,0xc
//         004d29b4     RET        0x4
//                               LAB_004d29b7                                                 XREF[1]:     004d2998(j)
//                              tact_trd.cpp:172 (9)
//         004d29b7     PUSH       0x1
//         004d29b9     MOV        this,EDI
//         004d29bb     CALL       RGE_Action::setSubAction                         void setSubAction(RGE_Action * this, uchar pa
//                              tact_trd.cpp:173 (9)
//         004d29c0     MOV        this,dword ptr [ESI + 0x34]
//         004d29c3     PUSH       EDI
//         004d29c4     CALL       RGE_Action_List::add_action                      void add_action(RGE_Action_List * this, RGE_A
//                              tact_trd.cpp:275 (20)
//         004d29c9     MOV        this,dword ptr [ESP + local_c]
//         004d29cd     MOV        dword ptr FS:[0x0],this
//         004d29d4     POP        EDI
//         004d29d5     POP        ESI
//         004d29d6     POP        EBX
//         004d29d7     ADD        ESP,0xc
//         004d29da     RET        0x4
//                               switchD_004d28ba::caseD_4                                    XREF[2]:     004d28ba(j), 004d2c84(*)
//                              tact_trd.cpp:179 (7)
//         004d29dd     MOV        EAX,dword ptr [ESI + 0x10]
//         004d29e0     TEST       EAX,EAX
//         004d29e2     JNZ        LAB_004d2a01
//                              tact_trd.cpp:181 (9)
//         004d29e4     MOV        EDX,dword ptr [ESI]
//         004d29e6     PUSH       0xd
//         004d29e8     MOV        this,ESI
//         004d29ea     CALL       dword ptr [EDX + 0x5c]
//                              tact_trd.cpp:275 (20)
//         004d29ed     MOV        this,dword ptr [ESP + 0xc]
//         004d29f1     MOV        dword ptr FS:[0x0],this
//         004d29f8     POP        EDI
//         004d29f9     POP        ESI
//         004d29fa     POP        EBX
//         004d29fb     ADD        ESP,0xc
//         004d29fe     RET        0x4
//                               LAB_004d2a01                                                 XREF[1]:     004d29e2(j)
//                              tact_trd.cpp:185 (3)
//         004d2a01     MOV        this,dword ptr [EAX + 0x38]
//                              tact_trd.cpp:189 (64)
//         004d2a04     PUSH       0x44
//         004d2a06     MOV        dword ptr [ESI + 0x20],this
//         004d2a09     MOV        EDX,dword ptr [EAX + 0x3c]
//         004d2a0c     MOV        dword ptr [ESI + 0x24],EDX
//         004d2a0f     MOV        EAX,dword ptr [EAX + 0x40]
//         004d2a12     MOV        dword ptr [ESI + 0x28],EAX
//         004d2a15     CALL       operator_new                                     void * operator_new(uint param_1)
//         004d2a1a     MOV        EDI,EAX
//         004d2a1c     ADD        ESP,0x4
//         004d2a1f     MOV        dword ptr [ESP + param_1],EDI
//         004d2a23     TEST       EDI,EDI
//         004d2a25     MOV        dword ptr [ESP + local_4],0x1
//         004d2a2d     JZ         LAB_004d2ba1
//         004d2a33     MOV        this,ESI
//         004d2a35     CALL       TRIBE_Action_Trade::get_move_sprite              RGE_Sprite * get_move_sprite(TRIBE_Action_Tra
//         004d2a3a     MOV        this,dword ptr [ESI + 0x30]
//         004d2a3d     PUSH       EAX
//         004d2a3e     MOV        EAX,dword ptr [ESI + 0x10]
//         004d2a41     MOV        EDX,dword ptr [ECX + this->_padding_]
//                              tact_trd.cpp:247 (20)
//         004d2a44     MOV        this,dword ptr [ESI + 0x8]
//         004d2a47     PUSH       EDX
//         004d2a48     PUSH       EAX
//         004d2a49     PUSH       this
//         004d2a4a     MOV        this,EDI
//         004d2a4c     CALL       RGE_Action_Move_To::RGE_Action_Move_To           undefined RGE_Action_Move_To(RGE_Action_Move_
//         004d2a51     MOV        EDI,EAX
//         004d2a53     JMP        LAB_004d2ba3
//                               switchD_004d28ba::caseD_6                                    XREF[2]:     004d28ba(j), 004d2c8c(*)
//                              tact_trd.cpp:201 (19)
//         004d2a58     MOV        EAX,dword ptr [ESI + 0x8]
//         004d2a5b     MOV        this,ESI
//         004d2a5d     MOV        EDI,dword ptr [EAX]
//         004d2a5f     CALL       TRIBE_Action_Trade::get_move_sprite              RGE_Sprite * get_move_sprite(TRIBE_Action_Tra
//         004d2a64     MOV        this,dword ptr [ESI + 0x8]
//         004d2a67     PUSH       EAX
//         004d2a68     CALL       dword ptr [EDI + 0x38]
//                              tact_trd.cpp:275 (20)
//         004d2a6b     MOV        this,dword ptr [ESP + 0xc]
//         004d2a6f     MOV        dword ptr FS:[0x0],this
//         004d2a76     POP        EDI
//         004d2a77     POP        ESI
//         004d2a78     POP        EBX
//         004d2a79     ADD        ESP,0xc
//         004d2a7c     RET        0x4
//                               switchD_004d28ba::caseD_7                                    XREF[2]:     004d28ba(j), 004d2c90(*)
//                              tact_trd.cpp:212 (15)
//         004d2a7f     MOV        EAX,dword ptr [ESI + 0x30]
//         004d2a82     MOV        this,dword ptr [ESI + 0x8]
//         004d2a85     MOV        EAX,dword ptr [EAX + 0x38]
//         004d2a88     MOV        EDX,dword ptr [this->_padding_]
//         004d2a8a     PUSH       EAX
//         004d2a8b     CALL       dword ptr [EDX + 0x38]
//                              tact_trd.cpp:215 (10)
//         004d2a8e     MOV        this,dword ptr [ESI + 0x30]
//         004d2a91     MOV        this,dword ptr [ECX + this->pick_up_y]
//         004d2a94     TEST       this,this
//         004d2a96     JZ         LAB_004d2a9f
//                              tact_trd.cpp:216 (7)
//         004d2a98     PUSH       0x1
//         004d2a9a     CALL       RGE_Sound::play                                  void play(RGE_Sound * this, int param_1)
//                               LAB_004d2a9f                                                 XREF[1]:     004d2a96(j)
//                              tact_trd.cpp:218 (7)
//         004d2a9f     MOV        EAX,dword ptr [ESI + 0x10]
//         004d2aa2     TEST       EAX,EAX
//         004d2aa4     JZ         LAB_004d2ac6
//                              tact_trd.cpp:220 (6)
//         004d2aa6     MOV        EDX,dword ptr [EAX + 0x38]
//         004d2aa9     MOV        dword ptr [ESI + 0x40],EDX
//                              tact_trd.cpp:221 (6)
//         004d2aac     MOV        EAX,dword ptr [EAX + 0x3c]
//         004d2aaf     MOV        dword ptr [ESI + 0x44],EAX
//                              tact_trd.cpp:275 (20)
//         004d2ab2     MOV        this,dword ptr [ESP + 0xc]
//         004d2ab6     MOV        dword ptr FS:[0x0],this
//         004d2abd     POP        EDI
//         004d2abe     POP        ESI
//         004d2abf     POP        EBX
//         004d2ac0     ADD        ESP,0xc
//         004d2ac3     RET        0x4
//                               LAB_004d2ac6                                                 XREF[1]:     004d2aa4(j)
//                              tact_trd.cpp:225 (8)
//         004d2ac6     MOV        EAX,0xbf800000
//         004d2acb     MOV        dword ptr [ESI + 0x40],EAX
//                              tact_trd.cpp:226 (3)
//         004d2ace     MOV        dword ptr [ESI + 0x44],EAX
//                              tact_trd.cpp:275 (20)
//         004d2ad1     MOV        this,dword ptr [ESP + 0xc]
//         004d2ad5     MOV        dword ptr FS:[0x0],this
//         004d2adc     POP        EDI
//         004d2add     POP        ESI
//         004d2ade     POP        EBX
//         004d2adf     ADD        ESP,0xc
//         004d2ae2     RET        0x4
//                               switchD_004d28ba::caseD_8                                    XREF[2]:     004d28ba(j), 004d2c94(*)
//                              tact_trd.cpp:232 (23)
//         004d2ae5     MOV        this,dword ptr [ESI + 0x8]
//         004d2ae8     FLD        float ptr [ECX + this->pick_up_y]
//         004d2aeb     FCOMP      float ptr [DAT_00575348]                         = align(16)
//         004d2af1     FNSTSW     AX
//         004d2af3     TEST       AH,0x41
//         004d2af6     JNZ        LAB_004d2c2d
//                              tact_trd.cpp:235 (26)
//         004d2afc     MOV        EAX,dword ptr [ESI + 0x14]
//         004d2aff     TEST       EAX,EAX
//         004d2b01     JZ         LAB_004d2b16
//         004d2b03     MOV        EDX,dword ptr [EAX + 0x8]
//         004d2b06     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004d2b09     MOV        DX,word ptr [EDX + 0x10]
//         004d2b0d     CMP        DX,word ptr [EAX + 0xe8]
//         004d2b14     JZ         LAB_004d2b5d
//                               LAB_004d2b16                                                 XREF[1]:     004d2b01(j)
//                              tact_trd.cpp:237 (16)
//         004d2b16     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004d2b19     MOV        DX,word ptr [EAX + 0xe8]
//         004d2b20     CMP        DX,-0x1
//         004d2b24     JZ         LAB_004d2b54
//                              tact_trd.cpp:238 (44)
//         004d2b26     MOV        EBX,dword ptr [ECX + this->_padding_]
//         004d2b29     PUSH       this
//         004d2b2a     MOVSX      EAX,word ptr [EAX + 0xea]
//         004d2b31     PUSH       0x2
//         004d2b33     PUSH       0x1
//         004d2b35     PUSH       EBX
//         004d2b36     MOV        EBX,dword ptr [ECX + this->_padding_]
//         004d2b39     MOV        EDI,dword ptr [ESI]
//         004d2b3b     PUSH       EBX
//         004d2b3c     PUSH       EAX
//         004d2b3d     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004d2b40     MOVSX      EDX,DX
//         004d2b43     MOV        this,dword ptr [EAX + 0x28]
//         004d2b46     PUSH       EDX
//         004d2b47     CALL       RGE_Object_List::find_by_master_ids              RGE_Static_Object * find_by_master_ids(RGE_Ob
//         004d2b4c     PUSH       EAX
//         004d2b4d     MOV        this,ESI
//         004d2b4f     CALL       dword ptr [EDI + 0x58]
//                              tact_trd.cpp:239 (2)
//         004d2b52     JMP        LAB_004d2b5d
//                               LAB_004d2b54                                                 XREF[1]:     004d2b24(j)
//                              tact_trd.cpp:240 (9)
//         004d2b54     MOV        EDX,dword ptr [ESI]
//         004d2b56     PUSH       0x0
//         004d2b58     MOV        this,ESI
//         004d2b5a     CALL       dword ptr [EDX + 0x58]
//                               LAB_004d2b5d                                                 XREF[2]:     004d2b14(j), 004d2b52(j)
//                              tact_trd.cpp:243 (11)
//         004d2b5d     MOV        EAX,dword ptr [ESI + 0x14]
//         004d2b60     TEST       EAX,EAX
//         004d2b62     JZ         LAB_004d2bf2
//                              tact_trd.cpp:247 (59)
//         004d2b68     PUSH       0x44
//         004d2b6a     CALL       operator_new                                     void * operator_new(uint param_1)
//         004d2b6f     MOV        EDI,EAX
//         004d2b71     ADD        ESP,0x4
//         004d2b74     MOV        dword ptr [ESP + 0x1c],EDI
//         004d2b78     TEST       EDI,EDI
//         004d2b7a     MOV        dword ptr [ESP + 0x14],0x2
//         004d2b82     JZ         LAB_004d2ba1
//         004d2b84     MOV        this,ESI
//         004d2b86     CALL       TRIBE_Action_Trade::get_move_sprite              RGE_Sprite * get_move_sprite(TRIBE_Action_Tra
//         004d2b8b     MOV        this,dword ptr [ESI + 0x8]
//         004d2b8e     PUSH       EAX
//         004d2b8f     MOV        EAX,dword ptr [ESI + 0x14]
//         004d2b92     PUSH       0x0=>DAT_fffffff8
//         004d2b94     PUSH       EAX=>DAT_fffffff4
//         004d2b95     PUSH       this=>DAT_fffffff0
//         004d2b96     MOV        this,EDI
//         004d2b98     CALL       RGE_Action_Move_To::RGE_Action_Move_To           undefined RGE_Action_Move_To(RGE_Action_Move_
//         004d2b9d     MOV        EDI,EAX
//         004d2b9f     JMP        LAB_004d2ba3
//                               LAB_004d2ba1                                                 XREF[2]:     004d2a2d(j), 004d2b82(j)
//         004d2ba1     XOR        EDI,EDI
//                               LAB_004d2ba3                                                 XREF[2]:     004d2a53(j), 004d2b9f(j)
//                              tact_trd.cpp:248 (12)
//         004d2ba3     TEST       EDI,EDI
//         004d2ba5     MOV        dword ptr [ESP + local_4],0xffffffff
//         004d2bad     JNZ        LAB_004d2bcc
//                              tact_trd.cpp:250 (9)
//         004d2baf     MOV        EDX,dword ptr [ESI]
//         004d2bb1     PUSH       0xd
//         004d2bb3     MOV        this,ESI
//         004d2bb5     CALL       dword ptr [EDX + 0x5c]
//                              tact_trd.cpp:275 (20)
//         004d2bb8     MOV        this,dword ptr [ESP + 0xc]
//         004d2bbc     MOV        dword ptr FS:[0x0],this
//         004d2bc3     POP        EDI
//         004d2bc4     POP        ESI
//         004d2bc5     POP        EBX
//         004d2bc6     ADD        ESP,0xc
//         004d2bc9     RET        0x4
//                               LAB_004d2bcc                                                 XREF[1]:     004d2bad(j)
//                              tact_trd.cpp:253 (9)
//         004d2bcc     MOV        this,dword ptr [ESI + 0x34]
//         004d2bcf     PUSH       EDI
//         004d2bd0     CALL       RGE_Action_List::add_action                      void add_action(RGE_Action_List * this, RGE_A
//                              tact_trd.cpp:254 (9)
//         004d2bd5     PUSH       0x1
//         004d2bd7     MOV        this,EDI
//         004d2bd9     CALL       RGE_Action::setSubAction                         void setSubAction(RGE_Action * this, uchar pa
//                              tact_trd.cpp:275 (20)
//         004d2bde     MOV        this,dword ptr [ESP + 0xc]
//         004d2be2     MOV        dword ptr FS:[0x0],this
//         004d2be9     POP        EDI
//         004d2bea     POP        ESI
//         004d2beb     POP        EBX
//         004d2bec     ADD        ESP,0xc
//         004d2bef     RET        0x4
//                               LAB_004d2bf2                                                 XREF[1]:     004d2b62(j)
//                              tact_trd.cpp:259 (30)
//         004d2bf2     MOV        this,dword ptr [ESI + 0x8]
//         004d2bf5     PUSH       0x0
//         004d2bf7     PUSH       0x0=>DAT_fffffff8
//         004d2bf9     PUSH       offset DAT_fffffff4
//         004d2bfe     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004d2c01     MOV        EDX,dword ptr [this->_padding_]
//         004d2c03     PUSH       offset DAT_fffffff0
//         004d2c08     PUSH       EAX
//         004d2c09     PUSH       EAX
//         004d2c0a     CALL       dword ptr [EDX + 0x148]
//                              tact_trd.cpp:260 (9)
//         004d2c10     MOV        EAX,dword ptr [ESI]
//         004d2c12     PUSH       0xd
//         004d2c14     MOV        this,ESI
//         004d2c16     CALL       dword ptr [EAX + 0x5c]
//                              tact_trd.cpp:275 (20)
//         004d2c19     MOV        this,dword ptr [ESP + 0xc]
//         004d2c1d     MOV        dword ptr FS:[0x0],this
//         004d2c24     POP        EDI
//         004d2c25     POP        ESI
//         004d2c26     POP        EBX
//         004d2c27     ADD        ESP,0xc
//         004d2c2a     RET        0x4
//                               LAB_004d2c2d                                                 XREF[1]:     004d2af6(j)
//                              tact_trd.cpp:268 (43)
//         004d2c2d     MOV        EDX,dword ptr [ESI + 0x10]
//         004d2c30     TEST       EDX,EDX
//         004d2c32     JZ         switchD_004d28ba::caseD_5
//         004d2c34     FLD        float ptr [EDX + 0x44]
//         004d2c37     FCOMP      float ptr [DAT_00575348]                         = align(16)
//         004d2c3d     FNSTSW     AX
//         004d2c3f     TEST       AH,0x41
//         004d2c42     JZ         switchD_004d28ba::caseD_5
//         004d2c44     MOV        EDX,dword ptr [EDX + 0x8]
//         004d2c47     MOV        EAX,dword ptr [this->_padding_]
//         004d2c49     MOVSX      EDX,word ptr [EDX + 0x10]
//         004d2c4d     PUSH       EDX
//         004d2c4e     CALL       dword ptr [EAX + 0x138]
//         004d2c54     TEST       AL,AL
//         004d2c56     JNZ        switchD_004d28ba::caseD_5
//                              tact_trd.cpp:269 (9)
//         004d2c58     MOV        EDI,dword ptr [ESI]
//         004d2c5a     PUSH       0x0
//         004d2c5c     MOV        this,ESI
//         004d2c5e     CALL       dword ptr [EDI + 0x54]
//                              tact_trd.cpp:270 (7)
//         004d2c61     PUSH       0x3
//         004d2c63     MOV        this,ESI
//         004d2c65     CALL       dword ptr [EDI + 0x5c]
//                               switchD_004d28ba::caseD_9                                    XREF[8]:     004d28b4(j), 004d28ba(j),
//                               switchD_004d28ba::caseD_a                                                 004d2c32(j), 004d2c42(j),
//                               switchD_004d28ba::caseD_5                                                 004d2c56(j), 004d2c88(*),
//                                                                                                         004d2c98(*), 004d2c9c(*)
//                              tact_trd.cpp:275 (60)
//         004d2c68     MOV        this,dword ptr [ESP + local_c]
//         004d2c6c     POP        EDI
//         004d2c6d     POP        ESI
//         004d2c6e     MOV        dword ptr FS:[0x0],this
//         004d2c75     POP        EBX
//         004d2c76     ADD        ESP,0xc
//         004d2c79     RET        0x4
//                              Symbol Ref: No symbol: NONAME
//                               switchD_004d28ba::switchdataD_004d2c7c                       XREF[1]:     set_state:004d28ba(*)
//         004d2c7c     addr       switchD_004d28ba::caseD_2
//         004d2c80     addr       switchD_004d28ba::caseD_3
//         004d2c84     addr       switchD_004d28ba::caseD_4
//         004d2c88     addr       switchD_004d28ba::caseD_5
//         004d2c8c     addr       switchD_004d28ba::caseD_6
//         004d2c90     addr       switchD_004d28ba::caseD_7
//         004d2c94     addr       switchD_004d28ba::caseD_8
//         004d2c98     addr       switchD_004d28ba::caseD_5
//         004d2c9c     addr       switchD_004d28ba::caseD_5
//         004d2ca0     addr       switchD_004d28ba::caseD_b
//         004d2ca4     ??         90h
//         004d2ca5     ??         90h
//         004d2ca6     ??         90h
//         004d2ca7     ??         90h
//         004d2ca8     ??         90h
//         004d2ca9     ??         90h
//         004d2caa     ??         90h
//         004d2cab     ??         90h
//         004d2cac     ??         90h
//         004d2cad     ??         90h
//         004d2cae     ??         90h
//         004d2caf     ??         90h
    return;
}

uchar TRIBE_Action_Trade::update() {
    /* TODO: Stub */
//                              uchar __thiscall update(TRIBE_Action_Trade * this)
//              uchar             AL:1           <RETURN>
//              TRIBE_Action_T    ECX:4 (auto)   this
//              float             Stack[-0x8]:4  max_hold
//              float             Stack[-0xc]:4  take_amount
//                               ?update@TRIBE_Action_Trade@@UAEEXZ                           XREF[1]:     00575310(*)
//                               TRIBE_Action_Trade::update
//                              tact_trd.cpp:281 (7)
//         004d2cb0     SUB        ESP,0x8
//         004d2cb3     PUSH       ESI
//         004d2cb4     MOV        ESI,this
//         004d2cb6     PUSH       EDI
//                              tact_trd.cpp:320 (27)
//         004d2cb7     MOV        EAX,dword ptr [ESI + 0x18]
//         004d2cba     CMP        EAX,-0x1
//         004d2cbd     JZ         LAB_004d2cda
//         004d2cbf     PUSH       EAX
//         004d2cc0     MOV        EAX,dword ptr [ESI + 0x8]
//         004d2cc3     MOV        this,dword ptr [EAX + 0xc]
//         004d2cc6     MOV        this,dword ptr [ECX + this->_padding_]
//         004d2cc9     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
//         004d2cce     TEST       EAX,EAX
//         004d2cd0     JNZ        LAB_004d2cda
//                              tact_trd.cpp:321 (8)
//         004d2cd2     MOV        EDX,dword ptr [ESI]
//         004d2cd4     PUSH       EAX
//         004d2cd5     MOV        this,ESI
//         004d2cd7     CALL       dword ptr [EDX + 0x54]
//                               LAB_004d2cda                                                 XREF[2]:     004d2cbd(j), 004d2cd0(j)
//                              tact_trd.cpp:322 (27)
//         004d2cda     MOV        EAX,dword ptr [ESI + 0x1c]
//         004d2cdd     CMP        EAX,-0x1
//         004d2ce0     JZ         LAB_004d2cfd
//         004d2ce2     PUSH       EAX
//         004d2ce3     MOV        EAX,dword ptr [ESI + 0x8]
//         004d2ce6     MOV        this,dword ptr [EAX + 0xc]
//         004d2ce9     MOV        this,dword ptr [ECX + this->_padding_]
//         004d2cec     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
//         004d2cf1     TEST       EAX,EAX
//         004d2cf3     JNZ        LAB_004d2cfd
//                              tact_trd.cpp:323 (8)
//         004d2cf5     MOV        EDX,dword ptr [ESI]
//         004d2cf7     PUSH       EAX
//         004d2cf8     MOV        this,ESI
//         004d2cfa     CALL       dword ptr [EDX + 0x58]
//                               LAB_004d2cfd                                                 XREF[2]:     004d2ce0(j), 004d2cf3(j)
//                              tact_trd.cpp:325 (13)
//         004d2cfd     MOV        EAX,dword ptr [ESI + 0x10]
//         004d2d00     TEST       EAX,EAX
//         004d2d02     JZ         LAB_004d2d13
//         004d2d04     CMP        byte ptr [EAX + 0x48],0x7
//         004d2d08     JC         LAB_004d2d13
//                              tact_trd.cpp:326 (9)
//         004d2d0a     MOV        EAX,dword ptr [ESI]
//         004d2d0c     PUSH       0x0
//         004d2d0e     MOV        this,ESI
//         004d2d10     CALL       dword ptr [EAX + 0x54]
//                               LAB_004d2d13                                                 XREF[2]:     004d2d02(j), 004d2d08(j)
//                              tact_trd.cpp:327 (13)
//         004d2d13     MOV        EAX,dword ptr [ESI + 0x14]
//         004d2d16     TEST       EAX,EAX
//         004d2d18     JZ         LAB_004d2d29
//         004d2d1a     CMP        byte ptr [EAX + 0x48],0x7
//         004d2d1e     JC         LAB_004d2d29
//                              tact_trd.cpp:328 (9)
//         004d2d20     MOV        EDX,dword ptr [ESI]
//         004d2d22     PUSH       0x0
//         004d2d24     MOV        this,ESI
//         004d2d26     CALL       dword ptr [EDX + 0x58]
//                               LAB_004d2d29                                                 XREF[2]:     004d2d18(j), 004d2d1e(j)
//                              tact_trd.cpp:330 (26)
//         004d2d29     MOV        EDX,dword ptr [ESI + 0x10]
//         004d2d2c     TEST       EDX,EDX
//         004d2d2e     JZ         LAB_004d2d89
//         004d2d30     MOV        this,dword ptr [ESI + 0x8]
//         004d2d33     MOV        EAX,dword ptr [EDX + 0xc]
//         004d2d36     MOV        this,dword ptr [ECX + this->_padding_]
//         004d2d39     MOV        this,word ptr [this->_padding_ + 0x4a]
//         004d2d3d     CMP        this,word ptr [EAX + 0x4a]
//         004d2d41     JNZ        LAB_004d2d89
//                              tact_trd.cpp:332 (9)
//         004d2d43     MOV        EDI,dword ptr [ESI]
//         004d2d45     PUSH       0x0
//         004d2d47     MOV        this,ESI
//         004d2d49     CALL       dword ptr [EDI + 0x54]
//                              tact_trd.cpp:333 (7)
//         004d2d4c     PUSH       0x0
//         004d2d4e     MOV        this,ESI
//         004d2d50     CALL       dword ptr [EDI + 0x58]
//                              tact_trd.cpp:334 (7)
//         004d2d53     PUSH       0x1
//         004d2d55     MOV        this,ESI
//         004d2d57     CALL       dword ptr [EDI + 0x5c]
//                              tact_trd.cpp:335 (7)
//         004d2d5a     MOV        AL,byte ptr [ESI + 0x3c]
//         004d2d5d     TEST       AL,AL
//         004d2d5f     JNZ        LAB_004d2d81
//                              tact_trd.cpp:340 (32)
//         004d2d61     MOV        this,dword ptr [ESI + 0x8]
//         004d2d64     MOV        ESI,dword ptr [ESI + 0x18]
//         004d2d67     PUSH       0x0
//         004d2d69     PUSH       ESI
//         004d2d6a     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004d2d6d     MOV        EDX,dword ptr [this->_padding_]
//         004d2d6f     PUSH       0x267
//         004d2d74     PUSH       0x1fb
//         004d2d79     PUSH       EAX
//         004d2d7a     PUSH       EAX
//         004d2d7b     CALL       dword ptr [EDX + 0x148]
//                               LAB_004d2d81                                                 XREF[1]:     004d2d5f(j)
//                              tact_trd.cpp:342 (2)
//         004d2d81     MOV        AL,0x4
//                              tact_trd.cpp:626 (6)
//         004d2d83     POP        EDI
//         004d2d84     POP        ESI
//         004d2d85     ADD        ESP,0x8
//         004d2d88     RET
//                               LAB_004d2d89                                                 XREF[2]:     004d2d2e(j), 004d2d41(j)
//                              tact_trd.cpp:345 (22)
//         004d2d89     XOR        EAX,EAX
//         004d2d8b     MOV        AL,byte ptr [ESI + 0xc]
//         004d2d8e     DEC        EAX
//         004d2d8f     CMP        EAX,0xc
//         004d2d92     JA         switchD_004d2d98::caseD_1
//                               switchD_004d2d98::switchD
//         004d2d98     JMP        dword ptr [EAX*0x4 + switchD_004d2d98::switchd   = 004d3205
//                               switchD_004d2d98::caseD_a                                    XREF[2]:     004d2d98(j), 004d326c(*)
//                              tact_trd.cpp:350 (16)
//         004d2d9f     FLD        float ptr [ESI + 0x2c]
//         004d2da2     FCOMP      double ptr [null_00575350]                       = align(8)
//         004d2da8     FNSTSW     AX
//         004d2daa     TEST       AH,0x1
//         004d2dad     JZ         LAB_004d2df5
//                              tact_trd.cpp:353 (18)
//         004d2daf     MOV        EAX,dword ptr [ESI + 0x8]
//         004d2db2     MOV        this,dword ptr [EAX + 0xc]
//         004d2db5     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004d2db8     FLD        float ptr [EAX + 0x84]
//         004d2dbe     FADD       float ptr [ESI + 0x2c]
//                              tact_trd.cpp:354 (20)
//         004d2dc1     FCOM       double ptr [null_00575350]                       = align(8)
//         004d2dc7     FSTP       float ptr [ESI + 0x2c]
//         004d2dca     FNSTSW     AX
//         004d2dcc     TEST       AH,0x41
//         004d2dcf     JNZ        switchD_004d2d98::caseD_1
//                              tact_trd.cpp:357 (15)
//         004d2dd5     TEST       EDX,EDX
//         004d2dd7     MOV        dword ptr [ESI + 0x2c],0x0
//         004d2dde     JZ         switchD_004d2e0c::caseD_0
//                              tact_trd.cpp:358 (4)
//         004d2de4     MOV        EDX,dword ptr [ESI]
//         004d2de6     PUSH       0x4
//                              tact_trd.cpp:602 (5)
//         004d2de8     MOV        this,ESI
//         004d2dea     CALL       dword ptr [EDX + 0x5c]
//                              tact_trd.cpp:625 (2)
//         004d2ded     XOR        AL,AL
//                              tact_trd.cpp:626 (6)
//         004d2def     POP        EDI
//         004d2df0     POP        ESI
//         004d2df1     ADD        ESP,0x8
//         004d2df4     RET
//                               LAB_004d2df5                                                 XREF[1]:     004d2dad(j)
//                              tact_trd.cpp:366 (30)
//         004d2df5     MOV        this,dword ptr [ESI + 0x34]
//         004d2df8     MOV        EDX,dword ptr [this->_padding_]
//         004d2dfa     CALL       dword ptr [EDX + 0xc]
//         004d2dfd     AND        EAX,0xff
//         004d2e02     DEC        EAX
//         004d2e03     CMP        EAX,0x4
//         004d2e06     JA         switchD_004d2d98::caseD_1
//                               switchD_004d2e0c::switchD
//         004d2e0c     JMP        dword ptr [EAX*0x4 + switchD_004d2e0c::switchd   = 004d2f40
//                               switchD_004d2d98::caseD_3                                    XREF[2]:     004d2d98(j), 004d3250(*)
//                              tact_trd.cpp:390 (16)
//         004d2e13     FLD        float ptr [ESI + 0x2c]
//         004d2e16     FCOMP      double ptr [null_00575350]                       = align(8)
//         004d2e1c     FNSTSW     AX
//         004d2e1e     TEST       AH,0x1
//         004d2e21     JZ         LAB_004d2e69
//                              tact_trd.cpp:393 (18)
//         004d2e23     MOV        this,dword ptr [ESI + 0x8]
//         004d2e26     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004d2e29     MOV        this,dword ptr [EAX + 0x3c]
//         004d2e2c     FLD        float ptr [this->_padding_ + 0x84]
//         004d2e32     FADD       float ptr [ESI + 0x2c]
//                              tact_trd.cpp:394 (20)
//         004d2e35     FCOM       double ptr [null_00575350]                       = align(8)
//         004d2e3b     FSTP       float ptr [ESI + 0x2c]
//         004d2e3e     FNSTSW     AX
//         004d2e40     TEST       AH,0x41
//         004d2e43     JNZ        switchD_004d2d98::caseD_1
//                              tact_trd.cpp:397 (15)
//         004d2e49     TEST       EDX,EDX
//         004d2e4b     MOV        dword ptr [ESI + 0x2c],0x0
//         004d2e52     JZ         switchD_004d2e0c::caseD_0
//                              tact_trd.cpp:398 (4)
//         004d2e58     MOV        EDX,dword ptr [ESI]
//         004d2e5a     PUSH       0x4
//                              tact_trd.cpp:602 (5)
//         004d2e5c     MOV        this,ESI
//         004d2e5e     CALL       dword ptr [EDX + 0x5c]
//                              tact_trd.cpp:625 (2)
//         004d2e61     XOR        AL,AL
//                              tact_trd.cpp:626 (6)
//         004d2e63     POP        EDI
//         004d2e64     POP        ESI
//         004d2e65     ADD        ESP,0x8
//         004d2e68     RET
//                               LAB_004d2e69                                                 XREF[1]:     004d2e21(j)
//                              tact_trd.cpp:406 (30)
//         004d2e69     MOV        this,dword ptr [ESI + 0x34]
//         004d2e6c     MOV        EDX,dword ptr [this->_padding_]
//         004d2e6e     CALL       dword ptr [EDX + 0xc]
//         004d2e71     AND        EAX,0xff
//         004d2e76     DEC        EAX
//         004d2e77     CMP        EAX,0x4
//         004d2e7a     JA         switchD_004d2d98::caseD_1
//                               switchD_004d2e80::switchD
//         004d2e80     JMP        dword ptr [EAX*0x4 + switchD_004d2e80::switchd   = 004d2e87
//                               switchD_004d2e80::caseD_1                                    XREF[3]:     004d2e80(j), 004d328c(*),
//                               switchD_004d2e80::caseD_0                                                 004d3290(*)
//                              tact_trd.cpp:428 (9)
//         004d2e87     MOV        EAX,dword ptr [ESI]
//         004d2e89     PUSH       0x6
//         004d2e8b     MOV        this,ESI
//         004d2e8d     CALL       dword ptr [EAX + 0x5c]
//                              tact_trd.cpp:625 (2)
//         004d2e90     XOR        AL,AL
//                              tact_trd.cpp:626 (6)
//         004d2e92     POP        EDI
//         004d2e93     POP        ESI
//         004d2e94     ADD        ESP,0x8
//         004d2e97     RET
//                               switchD_004d2d98::caseD_5                                    XREF[2]:     004d2d98(j), 004d3258(*)
//                              tact_trd.cpp:436 (4)
//         004d2e98     TEST       EDX,EDX
//         004d2e9a     JNZ        LAB_004d2ead
//                              tact_trd.cpp:438 (9)
//         004d2e9c     MOV        EDX,dword ptr [ESI]
//         004d2e9e     PUSH       0x3
//         004d2ea0     MOV        this,ESI
//         004d2ea2     CALL       dword ptr [EDX + 0x5c]
//                              tact_trd.cpp:625 (2)
//         004d2ea5     XOR        AL,AL
//                              tact_trd.cpp:626 (6)
//         004d2ea7     POP        EDI
//         004d2ea8     POP        ESI
//         004d2ea9     ADD        ESP,0x8
//         004d2eac     RET
//                               LAB_004d2ead                                                 XREF[1]:     004d2e9a(j)
//                              tact_trd.cpp:443 (24)
//         004d2ead     MOV        this,dword ptr [ESI + 0x8]
//         004d2eb0     PUSH       0x0
//         004d2eb2     PUSH       0x0
//         004d2eb4     PUSH       EDX
//         004d2eb5     MOV        EAX,dword ptr [this->_padding_]
//         004d2eb7     CALL       dword ptr [EAX + 0x1f0]
//         004d2ebd     TEST       AL,AL
//         004d2ebf     JZ         switchD_004d2d98::caseD_1
//                              tact_trd.cpp:448 (42)
//         004d2ec5     MOV        EDX,dword ptr [ESI + 0x10]
//         004d2ec8     FLD        float ptr [EDX + 0x44]
//         004d2ecb     FCOMP      float ptr [DAT_00575348]                         = align(16)
//         004d2ed1     FNSTSW     AX
//         004d2ed3     TEST       AH,0x41
//         004d2ed6     JZ         LAB_004d2f07
//         004d2ed8     MOV        EDX,dword ptr [EDX + 0x8]
//         004d2edb     MOV        this,dword ptr [ESI + 0x8]
//         004d2ede     MOVSX      EDX,word ptr [EDX + 0x10]
//         004d2ee2     MOV        EAX,dword ptr [this->_padding_]
//         004d2ee4     PUSH       EDX
//         004d2ee5     CALL       dword ptr [EAX + 0x138]
//         004d2eeb     TEST       AL,AL
//         004d2eed     JNZ        LAB_004d2f07
//                               switchD_004d2e80::caseD_4                                    XREF[2]:     004d2e80(j), 004d329c(*)
//                              tact_trd.cpp:450 (9)
//         004d2eef     MOV        EDI,dword ptr [ESI]
//         004d2ef1     PUSH       0x0
//         004d2ef3     MOV        this,ESI
//         004d2ef5     CALL       dword ptr [EDI + 0x54]
//                              tact_trd.cpp:451 (7)
//         004d2ef8     PUSH       0x3
//         004d2efa     MOV        this,ESI
//         004d2efc     CALL       dword ptr [EDI + 0x5c]
//                              tact_trd.cpp:625 (2)
//         004d2eff     XOR        AL,AL
//                              tact_trd.cpp:626 (6)
//         004d2f01     POP        EDI
//         004d2f02     POP        ESI
//         004d2f03     ADD        ESP,0x8
//         004d2f06     RET
//                               LAB_004d2f07                                                 XREF[2]:     004d2ed6(j), 004d2eed(j)
//                              tact_trd.cpp:454 (9)
//         004d2f07     MOV        EAX,dword ptr [ESI]
//         004d2f09     PUSH       0x7
//         004d2f0b     MOV        this,ESI
//         004d2f0d     CALL       dword ptr [EAX + 0x5c]
//                              tact_trd.cpp:625 (2)
//         004d2f10     XOR        AL,AL
//                              tact_trd.cpp:626 (6)
//         004d2f12     POP        EDI
//         004d2f13     POP        ESI
//         004d2f14     ADD        ESP,0x8
//         004d2f17     RET
//                               switchD_004d2d98::caseD_6                                    XREF[2]:     004d2d98(j), 004d325c(*)
//                              tact_trd.cpp:465 (23)
//         004d2f18     MOV        this,dword ptr [ESI + 0x8]
//         004d2f1b     TEST       EDX,EDX
//         004d2f1d     JNZ        LAB_004d2f51
//         004d2f1f     FLD        float ptr [ECX + this->pick_up_y]
//         004d2f22     FCOMP      float ptr [DAT_00575348]                         = align(16)
//         004d2f28     FNSTSW     AX
//         004d2f2a     TEST       AH,0x41
//         004d2f2d     JNZ        switchD_004d2e0c::caseD_0
//                              tact_trd.cpp:466 (9)
//         004d2f2f     MOV        EDX,dword ptr [ESI]
//         004d2f31     PUSH       0x8
//         004d2f33     MOV        this,ESI
//         004d2f35     CALL       dword ptr [EDX + 0x5c]
//                              tact_trd.cpp:625 (2)
//         004d2f38     XOR        AL,AL
//                              tact_trd.cpp:626 (6)
//         004d2f3a     POP        EDI
//         004d2f3b     POP        ESI
//         004d2f3c     ADD        ESP,0x8
//         004d2f3f     RET
//                               switchD_004d2e0c::caseD_1                                    XREF[7]:     004d2dde(j), 004d2e0c(j),
//                               switchD_004d2e0c::caseD_4                                                 004d2e52(j), 004d2f2d(j),
//                               switchD_004d2e0c::caseD_0                                                 004d3278(*), 004d327c(*),
//                                                                                                         004d3288(*)
//                              tact_trd.cpp:468 (9)
//         004d2f40     MOV        EAX,dword ptr [ESI]
//         004d2f42     PUSH       0x3
//         004d2f44     MOV        this,ESI
//         004d2f46     CALL       dword ptr [EAX + 0x5c]
//                              tact_trd.cpp:625 (2)
//         004d2f49     XOR        AL,AL
//                              tact_trd.cpp:626 (6)
//         004d2f4b     POP        EDI
//         004d2f4c     POP        ESI
//         004d2f4d     ADD        ESP,0x8
//         004d2f50     RET
//                               LAB_004d2f51                                                 XREF[1]:     004d2f1d(j)
//                              tact_trd.cpp:479 (21)
//         004d2f51     MOV        AX,word ptr [this->_padding_ + 0x4c]
//         004d2f55     TEST       AX,AX
//         004d2f58     JZ         LAB_004d2f6c
//         004d2f5a     CMP        AX,0x2
//         004d2f5e     JZ         LAB_004d2f6c
//         004d2f60     CMP        AX,0x1
//         004d2f64     JZ         LAB_004d2f6c
//                              tact_trd.cpp:480 (6)
//         004d2f66     MOV        word ptr [this->_padding_ + 0x4c],0x1
//                               LAB_004d2f6c                                                 XREF[3]:     004d2f58(j), 004d2f5e(j),
//                                                                                                         004d2f64(j)
//                              tact_trd.cpp:483 (10)
//         004d2f6c     MOV        EAX,dword ptr [ESI + 0x8]
//         004d2f6f     MOV        this,dword ptr [EAX + 0x8]
//         004d2f72     MOVSX      EDX,word ptr [this->_padding_ + 0x7c]
//                              tact_trd.cpp:487 (49)
//         004d2f76     MOV        this,dword ptr [EAX + 0xc]
//         004d2f79     MOV        dword ptr [ESP + 0xc],EDX
//         004d2f7d     FILD       dword ptr [ESP + 0xc]
//         004d2f81     MOV        DX,word ptr [EAX + 0x4c]
//         004d2f85     MOV        EDI,dword ptr [this->_padding_ + 0x50]
//         004d2f88     FST        float ptr [ESP + 0xc]
//         004d2f8c     FSUB       float ptr [EAX + 0x44]
//         004d2f8f     MOVSX      EAX,DX
//         004d2f92     FSTP       float ptr [ESP + 0x8]
//         004d2f96     FLD        float ptr [EDI + EAX*0x4]
//         004d2f99     FCOMP      float ptr [ESP + 0x8]
//         004d2f9d     LEA        EDI,[EDI + EAX*0x4]
//         004d2fa0     FNSTSW     AX
//         004d2fa2     TEST       AH,0x1
//         004d2fa5     JZ         LAB_004d2fad
//                              tact_trd.cpp:488 (6)
//         004d2fa7     MOV        EAX,dword ptr [EDI]
//         004d2fa9     MOV        dword ptr [ESP + 0x8],EAX
//                               LAB_004d2fad                                                 XREF[1]:     004d2fa5(j)
//                              tact_trd.cpp:491 (23)
//         004d2fad     MOV        EAX,dword ptr [ESI + 0x10]
//         004d2fb0     MOV        EAX,dword ptr [EAX + 0xc]
//         004d2fb3     MOV        EDI,dword ptr [EAX + 0x50]
//         004d2fb6     FLD        float ptr [EDI + 0x24]
//         004d2fb9     FCOMP      float ptr [ESP + 0x8]
//         004d2fbd     FNSTSW     AX
//         004d2fbf     TEST       AH,0x1
//         004d2fc2     JZ         LAB_004d2fcb
//                              tact_trd.cpp:492 (7)
//         004d2fc4     MOV        EAX,dword ptr [EDI + 0x24]
//         004d2fc7     MOV        dword ptr [ESP + 0x8],EAX
//                               LAB_004d2fcb                                                 XREF[1]:     004d2fc2(j)
//                              tact_trd.cpp:495 (18)
//         004d2fcb     FLD        float ptr [ESP + 0x8]
//         004d2fcf     MOV        EAX,dword ptr [this->_padding_]
//         004d2fd1     PUSH       0x1
//         004d2fd3     PUSH       this
//         004d2fd4     FCHS
//         004d2fd6     FSTP       float ptr [ESP]
//         004d2fd9     PUSH       EDX
//         004d2fda     CALL       dword ptr [EAX + 0x78]
//                              tact_trd.cpp:496 (19)
//         004d2fdd     MOV        this,dword ptr [ESI + 0x10]
//         004d2fe0     MOV        EDX,dword ptr [ECX + this->_padding_]
//         004d2fe3     MOV        EAX,dword ptr [EDX + 0x50]
//         004d2fe6     FLD        float ptr [EAX + 0x24]
//         004d2fe9     FSUB       float ptr [ESP + 0x8]
//         004d2fed     FSTP       float ptr [EAX + 0x24]
//                              tact_trd.cpp:498 (13)
//         004d2ff0     MOV        EAX,dword ptr [ESI + 0x8]
//         004d2ff3     FLD        float ptr [ESP + 0x8]
//         004d2ff7     FADD       float ptr [EAX + 0x44]
//         004d2ffa     FSTP       float ptr [EAX + 0x44]
//                              tact_trd.cpp:502 (68)
//         004d2ffd     MOV        this,dword ptr [ESI + 0x8]
//         004d3000     FLD        float ptr [ECX + this->pick_up_y]
//         004d3003     FCOMP      float ptr [ESP + 0xc]
//         004d3007     FNSTSW     AX
//         004d3009     TEST       AH,0x1
//         004d300c     JZ         LAB_004d31f4
//         004d3012     MOV        EDX,dword ptr [ESI + 0x10]
//         004d3015     MOV        EAX,dword ptr [EDX + 0xc]
//         004d3018     MOV        EAX,dword ptr [EAX + 0x50]
//         004d301b     FLD        float ptr [EAX + 0x24]
//         004d301e     FCOMP      float ptr [DAT_00575348]                         = align(16)
//         004d3024     FNSTSW     AX
//         004d3026     TEST       AH,0x41
//         004d3029     JZ         switchD_004d2d98::caseD_1
//         004d302f     MOV        EDX,dword ptr [EDX + 0x8]
//         004d3032     MOV        EAX,dword ptr [this->_padding_]
//         004d3034     MOVSX      EDX,word ptr [EDX + 0x10]
//         004d3038     PUSH       EDX
//         004d3039     CALL       dword ptr [EAX + 0x138]
//         004d303f     TEST       AL,AL
//                              tact_trd.cpp:507 (15)
//         004d3041     JNZ        switchD_004d2d98::caseD_1
//         004d3047     MOV        EAX,dword ptr [ESI]
//         004d3049     PUSH       0x8
//         004d304b     MOV        this,ESI
//         004d304d     CALL       dword ptr [EAX + 0x5c]
//                              tact_trd.cpp:625 (2)
//         004d3050     XOR        AL,AL
//                              tact_trd.cpp:626 (6)
//         004d3052     POP        EDI
//         004d3053     POP        ESI
//         004d3054     ADD        ESP,0x8
//         004d3057     RET
//                               switchD_004d2d98::caseD_7                                    XREF[2]:     004d2d98(j), 004d3260(*)
//                              tact_trd.cpp:512 (16)
//         004d3058     FLD        float ptr [ESI + 0x2c]
//         004d305b     FCOMP      double ptr [null_00575350]                       = align(8)
//         004d3061     FNSTSW     AX
//         004d3063     TEST       AH,0x1
//         004d3066     JZ         LAB_004d30a6
//                              tact_trd.cpp:515 (18)
//         004d3068     MOV        this,dword ptr [ESI + 0x8]
//         004d306b     MOV        EDX,dword ptr [ECX + this->_padding_]
//         004d306e     MOV        EAX,dword ptr [EDX + 0x3c]
//         004d3071     FLD        float ptr [EAX + 0x84]
//         004d3077     FADD       float ptr [ESI + 0x2c]
//                              tact_trd.cpp:516 (20)
//         004d307a     FCOM       double ptr [null_00575350]                       = align(8)
//         004d3080     FSTP       float ptr [ESI + 0x2c]
//         004d3083     FNSTSW     AX
//         004d3085     TEST       AH,0x41
//         004d3088     JNZ        switchD_004d2d98::caseD_1
//                              tact_trd.cpp:519 (16)
//         004d308e     MOV        EDX,dword ptr [ESI]
//         004d3090     PUSH       0x8
//         004d3092     MOV        this,ESI
//         004d3094     MOV        dword ptr [ESI + 0x2c],0x0
//         004d309b     CALL       dword ptr [EDX + 0x5c]
//                              tact_trd.cpp:625 (2)
//         004d309e     XOR        AL,AL
//                              tact_trd.cpp:626 (6)
//         004d30a0     POP        EDI
//         004d30a1     POP        ESI
//         004d30a2     ADD        ESP,0x8
//         004d30a5     RET
//                               LAB_004d30a6                                                 XREF[1]:     004d3066(j)
//                              tact_trd.cpp:525 (30)
//         004d30a6     MOV        this,dword ptr [ESI + 0x34]
//         004d30a9     MOV        EAX,dword ptr [this->_padding_]
//         004d30ab     CALL       dword ptr [EAX + 0xc]
//         004d30ae     AND        EAX,0xff
//         004d30b3     DEC        EAX
//         004d30b4     CMP        EAX,0x4
//         004d30b7     JA         switchD_004d2d98::caseD_1
//                               switchD_004d30bd::switchD
//         004d30bd     JMP        dword ptr [EAX*0x4 + switchD_004d30bd::switchd   = 004d30d3
//                               switchD_004d2e0c::caseD_3                                    XREF[10]:    004d2e0c(j), 004d2e80(j),
//                               switchD_004d30bd::caseD_2                                                 004d30bd(j), 004d3280(*),
//                               switchD_004d30bd::caseD_3                                                 004d3284(*), 004d3294(*),
//                               switchD_004d30bd::caseD_4                                                 004d3298(*), 004d32a8(*),
//                               switchD_004d2e80::caseD_2                                                 004d32ac(*), 004d32b0(*)
//                               switchD_004d2e80::caseD_3
//                               switchD_004d2e0c::caseD_2
//                              tact_trd.cpp:534 (7)
//         004d30c4     MOV        dword ptr [ESI + 0x2c],0xbf000000
//                              tact_trd.cpp:625 (2)
//         004d30cb     XOR        AL,AL
//                              tact_trd.cpp:626 (6)
//         004d30cd     POP        EDI
//         004d30ce     POP        ESI
//         004d30cf     ADD        ESP,0x8
//         004d30d2     RET
//                               switchD_004d30bd::caseD_1                                    XREF[3]:     004d30bd(j), 004d32a0(*),
//                               switchD_004d30bd::caseD_0                                                 004d32a4(*)
//                              tact_trd.cpp:541 (11)
//         004d30d3     MOV        EAX,dword ptr [ESI + 0x14]
//         004d30d6     TEST       EAX,EAX
//         004d30d8     JZ         LAB_004d31f4
//                              tact_trd.cpp:543 (23)
//         004d30de     MOV        this,dword ptr [ESI + 0x8]
//         004d30e1     FLD        float ptr [ECX + this->pick_up_y]
//         004d30e4     FCOMP      double ptr [null_00575350]                       = align(8)
//         004d30ea     FNSTSW     AX
//         004d30ec     TEST       AH,0x41
//         004d30ef     JNZ        LAB_004d31cb
//                              tact_trd.cpp:548 (10)
//         004d30f5     MOV        EDX,dword ptr [ESI + 0x30]
//         004d30f8     MOV        this,dword ptr [EDX + 0x48]
//         004d30fb     TEST       this,this
//         004d30fd     JZ         LAB_004d3106
//                              tact_trd.cpp:549 (7)
//         004d30ff     PUSH       0x1
//         004d3101     CALL       RGE_Sound::play                                  void play(RGE_Sound * this, int param_1)
//                               LAB_004d3106                                                 XREF[1]:     004d30fd(j)
//                              tact_trd.cpp:559 (32)
//         004d3106     FLD        float ptr [ESI + 0x40]
//         004d3109     FCOMP      double ptr [null_00575350]                       = align(8)
//         004d310f     FNSTSW     AX
//         004d3111     TEST       AH,0x1
//         004d3114     JNZ        LAB_004d315b
//         004d3116     FLD        float ptr [ESI + 0x44]
//         004d3119     FCOMP      double ptr [null_00575350]                       = align(8)
//         004d311f     FNSTSW     AX
//         004d3121     TEST       AH,0x1
//         004d3124     JNZ        LAB_004d315b
//                              tact_trd.cpp:562 (23)
//         004d3126     FLD        float ptr [ESI + 0x44]
//         004d3129     MOV        EAX,dword ptr [ESI + 0x14]
//         004d312c     FLD        float ptr [ESI + 0x40]
//         004d312f     FSUB       float ptr [EAX + 0x38]
//         004d3132     FXCH
//         004d3134     FSUB       float ptr [EAX + 0x3c]
//         004d3137     FXCH
//         004d3139     FST        float ptr [ESP + 0xc]
//                              tact_trd.cpp:566 (28)
//         004d313d     FLD        ST1
//         004d313f     FXCH
//         004d3141     FMUL       float ptr [ESP + 0xc]
//         004d3145     FXCH
//         004d3147     FMUL       ST2
//         004d3149     FADDP
//         004d314b     FMUL       float ptr [DAT_00575358]                         = 0Ch
//         004d3151     FMUL       float ptr [DAT_0057535c]                         = 33h    3
//         004d3157     FSTP       ST1
//                              tact_trd.cpp:568 (2)
//         004d3159     JMP        LAB_004d3161
//                               LAB_004d315b                                                 XREF[2]:     004d3114(j), 004d3124(j)
//                              tact_trd.cpp:569 (6)
//         004d315b     FLD        float ptr [DAT_00575360]                         = 33h    3
//                               LAB_004d3161                                                 XREF[1]:     004d3159(j)
//                              tact_trd.cpp:578 (15)
//         004d3161     MOV        EDX,dword ptr [ESI + 0x8]
//         004d3164     MOV        this,dword ptr [EDX + 0xc]
//         004d3167     CMP        byte ptr [this->_padding_ + 0x105],0xf
//         004d316e     JNZ        LAB_004d3172
//                              tact_trd.cpp:579 (2)
//         004d3170     FADD       ST0,ST0
//                               LAB_004d3172                                                 XREF[1]:     004d316e(j)
//                              tact_trd.cpp:582 (15)
//         004d3172     FCOM       double ptr [DAT_00575368]                        = 66h    f
//         004d3178     FNSTSW     AX
//         004d317a     TEST       AH,0x1
//         004d317d     JZ         LAB_004d3187
//         004d317f     FSTP       ST0
//                              tact_trd.cpp:583 (6)
//         004d3181     FLD        float ptr [DAT_00575360]                         = 33h    3
//                               LAB_004d3187                                                 XREF[1]:     004d317d(j)
//                              tact_trd.cpp:585 (11)
//         004d3187     FLD        float ptr [EDX + 0x44]
//         004d318a     FMUL       ST1
//         004d318c     FSTP       float ptr [ESP + 0x8]
//         004d3190     FSTP       ST0
//                              tact_trd.cpp:588 (17)
//         004d3192     FLD        float ptr [ESP + 0x8]
//         004d3196     FCOMP      float ptr [DAT_00575370]
//         004d319c     FNSTSW     AX
//         004d319e     TEST       AH,0x41
//         004d31a1     JNZ        LAB_004d31ab
//                              tact_trd.cpp:589 (8)
//         004d31a3     MOV        dword ptr [ESP + 0x8],0x42960000
//                               LAB_004d31ab                                                 XREF[1]:     004d31a1(j)
//                              tact_trd.cpp:591 (14)
//         004d31ab     MOV        EDX,dword ptr [ESP + 0x8]
//         004d31af     MOV        EAX,dword ptr [this->_padding_]
//         004d31b1     PUSH       0x1
//         004d31b3     PUSH       EDX
//         004d31b4     PUSH       0x3
//         004d31b6     CALL       dword ptr [EAX + 0x78]
//                              tact_trd.cpp:592 (18)
//         004d31b9     MOV        this,dword ptr [ESI + 0x8]
//         004d31bc     PUSH       0x0
//         004d31be     MOV        DX,word ptr [this->_padding_ + 0x4c]
//         004d31c2     MOV        EAX,dword ptr [this->_padding_]
//         004d31c4     PUSH       EDX
//         004d31c5     CALL       dword ptr [EAX + 0x80]
//                               LAB_004d31cb                                                 XREF[1]:     004d30ef(j)
//                              tact_trd.cpp:599 (7)
//         004d31cb     MOV        EAX,dword ptr [ESI + 0x10]
//         004d31ce     TEST       EAX,EAX
//         004d31d0     JZ         LAB_004d31e3
//                              tact_trd.cpp:600 (9)
//         004d31d2     MOV        EAX,dword ptr [ESI]
//         004d31d4     PUSH       0x4
//         004d31d6     MOV        this,ESI
//         004d31d8     CALL       dword ptr [EAX + 0x5c]
//                              tact_trd.cpp:625 (2)
//         004d31db     XOR        AL,AL
//                              tact_trd.cpp:626 (6)
//         004d31dd     POP        EDI
//         004d31de     POP        ESI
//         004d31df     ADD        ESP,0x8
//         004d31e2     RET
//                               LAB_004d31e3                                                 XREF[1]:     004d31d0(j)
//                              tact_trd.cpp:602 (9)
//         004d31e3     MOV        EDX,dword ptr [ESI]
//         004d31e5     PUSH       0x3
//         004d31e7     MOV        this,ESI
//         004d31e9     CALL       dword ptr [EDX + 0x5c]
//                              tact_trd.cpp:625 (2)
//         004d31ec     XOR        AL,AL
//                              tact_trd.cpp:626 (6)
//         004d31ee     POP        EDI
//         004d31ef     POP        ESI
//         004d31f0     ADD        ESP,0x8
//         004d31f3     RET
//                               LAB_004d31f4                                                 XREF[2]:     004d300c(j), 004d30d8(j)
//                              tact_trd.cpp:605 (9)
//         004d31f4     MOV        EAX,dword ptr [ESI]
//         004d31f6     PUSH       0x8
//         004d31f8     MOV        this,ESI
//         004d31fa     CALL       dword ptr [EAX + 0x5c]
//                              tact_trd.cpp:625 (2)
//         004d31fd     XOR        AL,AL
//                              tact_trd.cpp:626 (6)
//         004d31ff     POP        EDI
//         004d3200     POP        ESI
//         004d3201     ADD        ESP,0x8
//         004d3204     RET
//                               switchD_004d2d98::caseD_0                                    XREF[2]:     004d2d98(j), 004d3244(*)
//                              tact_trd.cpp:616 (2)
//         004d3205     MOV        AL,0x1
//                              tact_trd.cpp:626 (6)
//         004d3207     POP        EDI
//         004d3208     POP        ESI
//         004d3209     ADD        ESP,0x8
//         004d320c     RET
//                               switchD_004d2d98::caseD_c                                    XREF[2]:     004d2d98(j), 004d3274(*)
//                              tact_trd.cpp:620 (30)
//         004d320d     MOV        this,dword ptr [ESI + 0x8]
//         004d3210     PUSH       0x0
//         004d3212     PUSH       0x0
//         004d3214     PUSH       0x267
//         004d3219     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004d321c     MOV        EDX,dword ptr [this->_padding_]
//         004d321e     PUSH       0x1f9
//         004d3223     PUSH       EAX
//         004d3224     PUSH       EAX
//         004d3225     CALL       dword ptr [EDX + 0x148]
//                              tact_trd.cpp:621 (9)
//         004d322b     MOV        EAX,dword ptr [ESI]
//         004d322d     PUSH       0x2
//         004d322f     MOV        this,ESI
//         004d3231     CALL       dword ptr [EAX + 0x5c]
//                              tact_trd.cpp:622 (2)
//         004d3234     MOV        AL,0x3
//                              tact_trd.cpp:626 (126)
//         004d3236     POP        EDI
//         004d3237     POP        ESI
//         004d3238     ADD        ESP,0x8
//         004d323b     RET
//                               switchD_004d2d98::caseD_2                                    XREF[17]:    004d2d92(j), 004d2d98(j),
//                               switchD_004d2d98::caseD_4                                                 004d2dcf(j), 004d2e06(j),
//                               switchD_004d2d98::caseD_8                                                 004d2e43(j), 004d2e7a(j),
//                               switchD_004d2d98::caseD_9                                                 004d2ebf(j), 004d3029(j),
//                               switchD_004d2d98::caseD_b                                                 004d3041(j), 004d3088(j),
//                               switchD_004d2e0c::default                                                 004d30b7(j), 004d3248(*),
//                               switchD_004d30bd::default                                                 004d324c(*), 004d3254(*),
//                               switchD_004d2e80::default                                                 004d3264(*), 004d3268(*),
//                               switchD_004d2d98::caseD_1                                                 004d3270(*)
//         004d323c     POP        EDI
//         004d323d     XOR        AL,AL
//         004d323f     POP        ESI
//         004d3240     ADD        ESP,0x8
//         004d3243     RET
//                              Symbol Ref: No symbol: NONAME
//                               switchD_004d2d98::switchdataD_004d3244                       XREF[1]:     update:004d2d98(*)
//         004d3244     addr       switchD_004d2d98::caseD_0
//         004d3248     addr       switchD_004d2d98::caseD_1
//         004d324c     addr       switchD_004d2d98::caseD_1
//         004d3250     addr       switchD_004d2d98::caseD_3
//         004d3254     addr       switchD_004d2d98::caseD_1
//         004d3258     addr       switchD_004d2d98::caseD_5
//         004d325c     addr       switchD_004d2d98::caseD_6
//         004d3260     addr       switchD_004d2d98::caseD_7
//         004d3264     addr       switchD_004d2d98::caseD_1
//         004d3268     addr       switchD_004d2d98::caseD_1
//         004d326c     addr       switchD_004d2d98::caseD_a
//         004d3270     addr       switchD_004d2d98::caseD_1
//         004d3274     addr       switchD_004d2d98::caseD_c
//                              Symbol Ref: No symbol: NONAME
//                               switchD_004d2e0c::switchdataD_004d3278                       XREF[1]:     update:004d2e0c(*)
//         004d3278     addr       switchD_004d2e0c::caseD_0
//         004d327c     addr       switchD_004d2e0c::caseD_0
//         004d3280     addr       switchD_004d2e0c::caseD_2
//         004d3284     addr       switchD_004d2e0c::caseD_2
//         004d3288     addr       switchD_004d2e0c::caseD_0
//                              Symbol Ref: No symbol: NONAME
//                               switchD_004d2e80::switchdataD_004d328c                       XREF[1]:     update:004d2e80(*)
//         004d328c     addr       switchD_004d2e80::caseD_0
//         004d3290     addr       switchD_004d2e80::caseD_0
//         004d3294     addr       switchD_004d2e0c::caseD_2
//         004d3298     addr       switchD_004d2e0c::caseD_2
//         004d329c     addr       switchD_004d2e80::caseD_4
//                              Symbol Ref: No symbol: NONAME
//                               switchD_004d30bd::switchdataD_004d32a0                       XREF[1]:     update:004d30bd(*)
//         004d32a0     addr       switchD_004d30bd::caseD_0
//         004d32a4     addr       switchD_004d30bd::caseD_0
//         004d32a8     addr       switchD_004d2e0c::caseD_2
//         004d32ac     addr       switchD_004d2e0c::caseD_2
//         004d32b0     addr       switchD_004d2e0c::caseD_2
//         004d32b4     ??         90h
//         004d32b5     ??         90h
//         004d32b6     ??         90h
//         004d32b7     ??         90h
//         004d32b8     ??         90h
//         004d32b9     ??         90h
//         004d32ba     ??         90h
//         004d32bb     ??         90h
//         004d32bc     ??         90h
//         004d32bd     ??         90h
//         004d32be     ??         90h
//         004d32bf     ??         90h
    return 0;
}

RGE_Sprite* TRIBE_Action_Trade::get_move_sprite() {
    /* TODO: Stub */
//                              RGE_Sprite * __thiscall get_move_sprite(TRIBE_Action_Trade * this)
//              RGE_Sprite *      EAX:4          <RETURN>
//              TRIBE_Action_T    ECX:4 (auto)   this
//                               ?get_move_sprite@TRIBE_Action_Trade@@IAEPAVRGE_Sprite@@XZ    XREF[4]:     set_state:004d2969(c),
//                               TRIBE_Action_Trade::get_move_sprite                                       set_state:004d2a35(c),
//                                                                                                         set_state:004d2a5f(c),
//                                                                                                         set_state:004d2b86(c)
//                              tact_trd.cpp:632 (1)
//         004d32c0     PUSH       ESI
//                              tact_trd.cpp:633 (7)
//         004d32c1     MOV        ESI,dword ptr [ECX + this->_padding_]
//         004d32c4     MOV        AX,word ptr [ESI + 0x14]
//                              tact_trd.cpp:636 (32)
//         004d32c8     CMP        AX,0xffff
//         004d32cc     JZ         LAB_004d32ea
//         004d32ce     MOV        this,dword ptr [ECX + this->_padding_]
//         004d32d1     CMP        word ptr [this->_padding_ + 0x4c],AX
//         004d32d5     JNZ        LAB_004d32ea
//         004d32d7     FLD        float ptr [ECX + this->pick_up_y]
//         004d32da     CALL       __ftol                                           undefined __ftol()
//         004d32df     TEST       EAX,EAX
//         004d32e1     JLE        LAB_004d32ea
//         004d32e3     MOV        EAX,dword ptr [ESI + 0x40]
//         004d32e6     TEST       EAX,EAX
//                              tact_trd.cpp:637 (2)
//         004d32e8     JNZ        LAB_004d32ed
//                               LAB_004d32ea                                                 XREF[3]:     004d32cc(j), 004d32d5(j),
//                                                                                                         004d32e1(j)
//                              tact_trd.cpp:639 (3)
//         004d32ea     MOV        EAX,dword ptr [ESI + 0x34]
//                               LAB_004d32ed                                                 XREF[1]:     004d32e8(j)
//                              tact_trd.cpp:640 (2)
//         004d32ed     POP        ESI
//         004d32ee     RET
//         004d32ef     ??         90h
    return 0;
}

RGE_Sprite* TRIBE_Action_Trade::get_wait_sprite() {
    /* TODO: Stub */
//                              RGE_Sprite * __thiscall get_wait_sprite(TRIBE_Action_Trade * this)
//              RGE_Sprite *      EAX:4          <RETURN>
//              TRIBE_Action_T    ECX:4 (auto)   this
//                               ?get_wait_sprite@TRIBE_Action_Trade@@IAEPAVRGE_Sprite@@XZ    XREF[2]:     set_state:004d28e6(c),
//                               TRIBE_Action_Trade::get_wait_sprite                                       set_state:004d290d(c)
//                              tact_trd.cpp:646 (4)
//         004d32f0     PUSH       ESI
//         004d32f1     MOV        ESI,this
//         004d32f3     PUSH       EDI
//                              tact_trd.cpp:649 (39)
//         004d32f4     MOV        EDI,dword ptr [ESI + 0x30]
//         004d32f7     MOV        AX,word ptr [EDI + 0x14]
//         004d32fb     CMP        AX,0xffff
//         004d32ff     JZ         LAB_004d331d
//         004d3301     MOV        this,dword ptr [ESI + 0x8]
//         004d3304     CMP        AX,word ptr [this->_padding_ + 0x4c]
//         004d3308     JNZ        LAB_004d331d
//         004d330a     FLD        float ptr [ECX + this->pick_up_y]
//         004d330d     CALL       __ftol                                           undefined __ftol()
//         004d3312     TEST       EAX,EAX
//         004d3314     JLE        LAB_004d331d
//         004d3316     MOV        EAX,dword ptr [EDI + 0x40]
//         004d3319     TEST       EAX,EAX
//                              tact_trd.cpp:650 (2)
//         004d331b     JNZ        LAB_004d3326
//                               LAB_004d331d                                                 XREF[3]:     004d32ff(j), 004d3308(j),
//                                                                                                         004d3314(j)
//                              tact_trd.cpp:652 (9)
//         004d331d     MOV        EAX,dword ptr [ESI + 0x8]
//         004d3320     MOV        this,dword ptr [EAX + 0x8]
//         004d3323     MOV        EAX,dword ptr [ECX + this->_padding_]
//                               LAB_004d3326                                                 XREF[1]:     004d331b(j)
//                              tact_trd.cpp:653 (3)
//         004d3326     POP        EDI
//         004d3327     POP        ESI
//         004d3328     RET
//         004d3329     ??         90h
//         004d332a     NOP
//         004d332b     NOP
//         004d332c     NOP
//         004d332d     NOP
//         004d332e     NOP
//         004d332f     NOP
    return 0;
}

int TRIBE_Action_Trade::stop() {
    /* TODO: Stub */
//                              int __thiscall stop(TRIBE_Action_Trade * this)
//              int               EAX:4          <RETURN>
//              TRIBE_Action_T    ECX:4 (auto)   this
//                               ?stop@TRIBE_Action_Trade@@UAEHXZ                             XREF[1]:     00575314(*)
//                               TRIBE_Action_Trade::stop
//                              tact_trd.cpp:659 (7)
//         004d3330     MOV        EAX,dword ptr [this->_padding_]
//         004d3332     PUSH       0x2
//         004d3334     CALL       dword ptr [EAX + 0x5c]
//                              tact_trd.cpp:661 (5)
//         004d3337     MOV        EAX,0x1
//                              tact_trd.cpp:662 (1)
//         004d333c     RET
//         004d333d     ??         90h
//         004d333e     NOP
//         004d333f     NOP
    return 0;
}

int TRIBE_Action_Trade::move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    /* TODO: Stub */
//                              int __thiscall move_to(TRIBE_Action_Trade * this, RGE_Static_Object
//              int               EAX:4          <RETURN>
//              TRIBE_Action_T    ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004d3340(R)
//              float             Stack[0x8]:4   param_2                   XREF[1]:     004d3392(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     004d338e(R)
//              float             Stack[0x10]:4  param_4                   XREF[1]:     004d3396(R)
//                               ?move_to@TRIBE_Action_Trade@@UAEHPAVRGE_Static_Object@@MMM@Z XREF[1]:     00575318(*)
//                               TRIBE_Action_Trade::move_to
//                              tact_trd.cpp:669 (42)
//         004d3340     MOV        EAX,dword ptr [ESP + param_1]
//         004d3344     PUSH       ESI
//         004d3345     TEST       EAX,EAX
//         004d3347     PUSH       EDI
//         004d3348     MOV        ESI,this
//         004d334a     JZ         LAB_004d338e
//         004d334c     MOV        this,dword ptr [ESI + 0x8]
//         004d334f     MOV        EDX,dword ptr [EAX + 0xc]
//         004d3352     CMP        EDX,dword ptr [ECX + this->_padding_]
//         004d3355     JNZ        LAB_004d338e
//         004d3357     MOV        EDX,dword ptr [EAX + 0x8]
//         004d335a     MOV        this,dword ptr [ECX + this->_padding_]
//         004d335d     MOV        DX,word ptr [EDX + 0x10]
//         004d3361     CMP        DX,word ptr [this->_padding_ + 0xe8]
//         004d3368     JNZ        LAB_004d338e
//                              tact_trd.cpp:675 (9)
//         004d336a     CMP        EAX,dword ptr [ESI + 0x14]
//         004d336d     JNZ        LAB_004d3375
//         004d336f     CMP        byte ptr [ESI + 0xc],0x8
//                              tact_trd.cpp:676 (2)
//         004d3373     JZ         LAB_004d33b3
//                               LAB_004d3375                                                 XREF[1]:     004d336d(j)
//                              tact_trd.cpp:678 (8)
//         004d3375     MOV        EDI,dword ptr [ESI]
//         004d3377     PUSH       EAX
//         004d3378     MOV        this,ESI
//         004d337a     CALL       dword ptr [EDI + 0x58]
//                              tact_trd.cpp:679 (2)
//         004d337d     PUSH       0x8
//                              tact_trd.cpp:687 (5)
//         004d337f     MOV        this,ESI
//         004d3381     CALL       dword ptr [EDI + 0x5c]
//                              tact_trd.cpp:689 (5)
//         004d3384     MOV        EAX,0x1
//                              tact_trd.cpp:690 (5)
//         004d3389     POP        EDI
//         004d338a     POP        ESI
//         004d338b     RET        0x10
//                               LAB_004d338e                                                 XREF[3]:     004d334a(j), 004d3355(j),
//                                                                                                         004d3368(j)
//                              tact_trd.cpp:684 (8)
//         004d338e     MOV        this,dword ptr [ESP + param_3]
//         004d3392     MOV        EAX,dword ptr [ESP + param_2]
//                              tact_trd.cpp:685 (4)
//         004d3396     MOV        EDX,dword ptr [ESP + param_4]
//                              tact_trd.cpp:686 (18)
//         004d339a     MOV        EDI,dword ptr [ESI]
//         004d339c     MOV        dword ptr [ESI + 0x24],this
//         004d339f     PUSH       0x0
//         004d33a1     MOV        this,ESI
//         004d33a3     MOV        dword ptr [ESI + 0x20],EAX
//         004d33a6     MOV        dword ptr [ESI + 0x28],EDX
//         004d33a9     CALL       dword ptr [EDI + 0x54]
//                              tact_trd.cpp:687 (7)
//         004d33ac     PUSH       0xb
//         004d33ae     MOV        this,ESI
//         004d33b0     CALL       dword ptr [EDI + 0x5c]
//                               LAB_004d33b3                                                 XREF[1]:     004d3373(j)
//                              tact_trd.cpp:690 (10)
//         004d33b3     POP        EDI
//         004d33b4     MOV        EAX,0x1
//         004d33b9     POP        ESI
//         004d33ba     RET        0x10
//         004d33bd     ??         90h
//         004d33be     NOP
//         004d33bf     NOP
    return 0;
}

int TRIBE_Action_Trade::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    /* TODO: Stub */
//                              int __thiscall work(TRIBE_Action_Trade * this, RGE_Static_Object * p
//              int               EAX:4          <RETURN>
//              TRIBE_Action_T    ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004d33c0(R)
//              float             Stack[0x8]:4   param_2                   XREF[1]:     004d3437(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     004d3433(R)
//              float             Stack[0x10]:4  param_4                   XREF[1]:     004d343b(R)
//                               ?work@TRIBE_Action_Trade@@UAEHPAVRGE_Static_Object@@MMM@Z    XREF[1]:     0057531c(*)
//                               TRIBE_Action_Trade::work
//                              tact_trd.cpp:697 (12)
//         004d33c0     MOV        EAX,dword ptr [ESP + param_1]
//         004d33c4     PUSH       ESI
//         004d33c5     TEST       EAX,EAX
//         004d33c7     PUSH       EDI
//         004d33c8     MOV        ESI,this
//         004d33ca     JZ         LAB_004d3433
//                              tact_trd.cpp:703 (21)
//         004d33cc     CMP        EAX,dword ptr [ESI + 0x10]
//         004d33cf     JNZ        LAB_004d33e3
//         004d33d1     MOV        this,byte ptr [ESI + 0xc]
//         004d33d4     CMP        this,0x4
//         004d33d7     JZ         LAB_004d3458
//         004d33d9     CMP        this,0x6
//         004d33dc     JZ         LAB_004d3458
//         004d33de     CMP        this,0x7
//                              tact_trd.cpp:704 (2)
//         004d33e1     JZ         LAB_004d3458
//                               LAB_004d33e3                                                 XREF[1]:     004d33cf(j)
//                              tact_trd.cpp:707 (30)
//         004d33e3     MOV        this,dword ptr [ESI + 0x8]
//         004d33e6     MOV        EDX,dword ptr [EAX + 0xc]
//         004d33e9     CMP        EDX,dword ptr [ECX + this->_padding_]
//         004d33ec     JNZ        LAB_004d341a
//         004d33ee     MOV        EDX,dword ptr [EAX + 0x8]
//         004d33f1     MOV        this,dword ptr [ECX + this->_padding_]
//         004d33f4     MOV        DX,word ptr [EDX + 0x10]
//         004d33f8     CMP        DX,word ptr [this->_padding_ + 0xe8]
//         004d33ff     JNZ        LAB_004d341a
//                              tact_trd.cpp:709 (8)
//         004d3401     MOV        EDI,dword ptr [ESI]
//         004d3403     PUSH       EAX
//         004d3404     MOV        this,ESI
//         004d3406     CALL       dword ptr [EDI + 0x58]
//                              tact_trd.cpp:710 (2)
//         004d3409     PUSH       0x8
//                              tact_trd.cpp:724 (5)
//         004d340b     MOV        this,ESI
//         004d340d     CALL       dword ptr [EDI + 0x5c]
//                              tact_trd.cpp:726 (5)
//         004d3410     MOV        EAX,0x1
//                              tact_trd.cpp:727 (5)
//         004d3415     POP        EDI
//         004d3416     POP        ESI
//         004d3417     RET        0x10
//                               LAB_004d341a                                                 XREF[2]:     004d33ec(j), 004d33ff(j)
//                              tact_trd.cpp:714 (8)
//         004d341a     MOV        EDI,dword ptr [ESI]
//         004d341c     PUSH       EAX
//         004d341d     MOV        this,ESI
//         004d341f     CALL       dword ptr [EDI + 0x54]
//                              tact_trd.cpp:715 (2)
//         004d3422     PUSH       0x4
//                              tact_trd.cpp:724 (5)
//         004d3424     MOV        this,ESI
//         004d3426     CALL       dword ptr [EDI + 0x5c]
//                              tact_trd.cpp:726 (5)
//         004d3429     MOV        EAX,0x1
//                              tact_trd.cpp:727 (5)
//         004d342e     POP        EDI
//         004d342f     POP        ESI
//         004d3430     RET        0x10
//                               LAB_004d3433                                                 XREF[1]:     004d33ca(j)
//                              tact_trd.cpp:721 (8)
//         004d3433     MOV        this,dword ptr [ESP + param_3]
//         004d3437     MOV        EAX,dword ptr [ESP + param_2]
//                              tact_trd.cpp:722 (4)
//         004d343b     MOV        EDX,dword ptr [ESP + param_4]
//                              tact_trd.cpp:723 (18)
//         004d343f     MOV        EDI,dword ptr [ESI]
//         004d3441     MOV        dword ptr [ESI + 0x24],this
//         004d3444     PUSH       0x0
//         004d3446     MOV        this,ESI
//         004d3448     MOV        dword ptr [ESI + 0x20],EAX
//         004d344b     MOV        dword ptr [ESI + 0x28],EDX
//         004d344e     CALL       dword ptr [EDI + 0x54]
//                              tact_trd.cpp:724 (7)
//         004d3451     PUSH       0xb
//         004d3453     MOV        this,ESI
//         004d3455     CALL       dword ptr [EDI + 0x5c]
//                               LAB_004d3458                                                 XREF[3]:     004d33d7(j), 004d33dc(j),
//                                                                                                         004d33e1(j)
//                              tact_trd.cpp:727 (10)
//         004d3458     POP        EDI
//         004d3459     MOV        EAX,0x1
//         004d345e     POP        ESI
//         004d345f     RET        0x10
//         004d3462     ??         90h
//         004d3463     NOP
//         004d3464     NOP
//         004d3465     NOP
//         004d3466     NOP
//         004d3467     NOP
//         004d3468     NOP
//         004d3469     NOP
//         004d346a     NOP
//         004d346b     NOP
//         004d346c     NOP
//         004d346d     NOP
//         004d346e     NOP
//         004d346f     NOP
    return 0;
}

TRIBE_Action_Trade::~TRIBE_Action_Trade() {
    /* TODO: Stub */
//                              void __thiscall ~TRIBE_Action_Trade(TRIBE_Action_Trade * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Action_T    ECX:4 (auto)   this
//                               ??1TRIBE_Action_Trade@@UAE@XZ                                XREF[1]:     `scalar_deleting_destructor':004d2
//                               TRIBE_Action_Trade::~TRIBE_Action_Trade
//         004d2700     JMP        RGE_Action::~RGE_Action
//         004d2705     ??         90h
//         004d2706     NOP
//         004d2707     NOP
//         004d2708     NOP
//         004d2709     NOP
//         004d270a     NOP
//         004d270b     NOP
//         004d270c     NOP
//         004d270d     NOP
//         004d270e     NOP
//         004d270f     NOP
}

