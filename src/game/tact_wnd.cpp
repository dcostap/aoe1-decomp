#include "../common.h"
#include "tact_wnd.h"

TRIBE_Action_Wonder::TRIBE_Action_Wonder(int param_1, RGE_Action_Object* param_2) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Action_Wonder(TRIBE_Action_Wonder * this,
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Action_W    ECX:4 (auto)   this
//              RGE_Action_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004d34c0(R)
//                               ??0TRIBE_Action_Wonder@@QAE@PAVRGE_Action_Object@@@Z         XREF[1]:     create_task_action:004d0879(c)
//                               TRIBE_Action_Wonder::TRIBE_Action_Wonder
//                              tact_wnd.cpp:42 (21)
//         004d34c0     MOV        EAX,dword ptr [ESP + param_1]
//         004d34c4     PUSH       ESI
//         004d34c5     PUSH       0x1
//         004d34c7     MOV        ESI,this
//         004d34c9     PUSH       EAX
//         004d34ca     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, RGE_A
//         004d34cf     MOV        dword ptr [ESI],TRIBE_Action_Wonder::`vftable'   = 004d34a0
//                              tact_wnd.cpp:43 (6)
//         004d34d5     MOV        word ptr [ESI + 0x4],0x78
//                              tact_wnd.cpp:44 (7)
//         004d34db     MOV        dword ptr [ESI + 0x2c],0x0
//                              tact_wnd.cpp:45 (6)
//         004d34e2     MOV        EAX,ESI
//         004d34e4     POP        ESI
//         004d34e5     RET        0x4
//         004d34e8     ??         90h
//         004d34e9     NOP
//         004d34ea     NOP
//         004d34eb     NOP
//         004d34ec     NOP
//         004d34ed     NOP
//         004d34ee     NOP
//         004d34ef     NOP
}

TRIBE_Action_Wonder::TRIBE_Action_Wonder(RGE_Action_Object* param_1) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Action_Wonder(TRIBE_Action_Wonder * this,
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Action_W    ECX:4 (auto)   this
//              RGE_Action_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004d34c0(R)
//                               ??0TRIBE_Action_Wonder@@QAE@PAVRGE_Action_Object@@@Z         XREF[1]:     create_task_action:004d0879(c)
//                               TRIBE_Action_Wonder::TRIBE_Action_Wonder
//                              tact_wnd.cpp:42 (21)
//         004d34c0     MOV        EAX,dword ptr [ESP + param_1]
//         004d34c4     PUSH       ESI
//         004d34c5     PUSH       0x1
//         004d34c7     MOV        ESI,this
//         004d34c9     PUSH       EAX
//         004d34ca     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, RGE_A
//         004d34cf     MOV        dword ptr [ESI],TRIBE_Action_Wonder::`vftable'   = 004d34a0
//                              tact_wnd.cpp:43 (6)
//         004d34d5     MOV        word ptr [ESI + 0x4],0x78
//                              tact_wnd.cpp:44 (7)
//         004d34db     MOV        dword ptr [ESI + 0x2c],0x0
//                              tact_wnd.cpp:45 (6)
//         004d34e2     MOV        EAX,ESI
//         004d34e4     POP        ESI
//         004d34e5     RET        0x4
//         004d34e8     ??         90h
//         004d34e9     NOP
//         004d34ea     NOP
//         004d34eb     NOP
//         004d34ec     NOP
//         004d34ed     NOP
//         004d34ee     NOP
//         004d34ef     NOP
}

TRIBE_Action_Wonder::~TRIBE_Action_Wonder() {
    /* TODO: Stub */
//                              void __thiscall ~TRIBE_Action_Wonder(TRIBE_Action_Wonder * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Action_W    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004d351a(W), 004d3667(W)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004d350b(W)
//              undefined4        Stack[-0x14]:4 local_14                  XREF[1]:     004d3540(W)
//              RGE_Player * *    Stack[-0x18]:4 players
//                               ??1TRIBE_Action_Wonder@@UAE@XZ                               XREF[1]:     `vector_deleting_destructor':004d3
//                               TRIBE_Action_Wonder::~TRIBE_Action_Wonder
//                              tact_wnd.cpp:50 (37)
//         004d34f0     PUSH       -0x1
//         004d34f2     PUSH       FUN_005601f8
//         004d34f7     MOV        EAX,FS:[0x0]
//         004d34fd     PUSH       EAX
//         004d34fe     MOV        dword ptr FS:[0x0],ESP
//         004d3505     SUB        ESP,0x8
//         004d3508     PUSH       EBX
//         004d3509     MOV        EBX,this
//         004d350b     MOV        dword ptr [ESP + local_10],EBX
//         004d350f     MOV        dword ptr [EBX],TRIBE_Action_Wonder::`vftable'   = 004d34a0
//                              tact_wnd.cpp:55 (31)
//         004d3515     MOV        EAX,[rge_base_game]                              = 00000000
//         004d351a     MOV        dword ptr [ESP + local_4],0x0
//         004d3522     MOV        EAX,dword ptr [EAX + 0x3f4]
//         004d3528     MOV        this,byte ptr [EAX + 0x1d]
//         004d352b     TEST       this,this
//         004d352d     JNZ        LAB_004d3665
//         004d3533     PUSH       EDI
//                              tact_wnd.cpp:57 (5)
//         004d3534     MOV        EDI,dword ptr [EAX + 0x40]
//         004d3537     PUSH       ESI
//         004d3538     PUSH       EBP
//                              tact_wnd.cpp:58 (4)
//         004d3539     MOVSX      EBP,word ptr [EAX + 0x3c]
//                              tact_wnd.cpp:61 (11)
//         004d353d     MOV        AL,byte ptr [EBX + 0xc]
//         004d3540     MOV        dword ptr [ESP + local_14],EDI
//         004d3544     CMP        AL,0x2
//         004d3546     JNZ        LAB_004d357d
//                              tact_wnd.cpp:62 (9)
//         004d3548     MOV        ESI,0x1
//         004d354d     CMP        EBP,ESI
//         004d354f     JLE        LAB_004d357d
//                              tact_wnd.cpp:97 (3)
//         004d3551     ADD        EDI,0x4
//                               LAB_004d3554                                                 XREF[1]:     004d3577(j)
//                              tact_wnd.cpp:63 (14)
//         004d3554     MOV        this,dword ptr [EBX + 0x8]
//         004d3557     MOV        EDX,dword ptr [ECX + this->field12_0xc]
//         004d355a     MOVSX      EAX,word ptr [EDX + 0x4a]
//         004d355e     CMP        ESI,EAX
//         004d3560     JZ         LAB_004d3571
//                              tact_wnd.cpp:64 (23)
//         004d3562     MOV        EAX,dword ptr [EDI]
//         004d3564     MOV        EDX,dword ptr [this->field0_0x0]
//         004d3566     PUSH       -0x1
//         004d3568     PUSH       offset DAT_fffffff8
//         004d356a     PUSH       EAX=>DAT_fffffff4
//         004d356b     CALL       dword ptr [EDX + 0xdc]
//                               LAB_004d3571                                                 XREF[1]:     004d3560(j)
//         004d3571     INC        ESI
//         004d3572     ADD        EDI,0x4
//         004d3575     CMP        ESI,EBP
//         004d3577     JL         LAB_004d3554
//                              tact_wnd.cpp:62 (4)
//         004d3579     MOV        EDI,dword ptr [ESP + 0x10]
//                               LAB_004d357d                                                 XREF[2]:     004d3546(j), 004d354f(j)
//                              tact_wnd.cpp:66 (10)
//         004d357d     CMP        byte ptr [EBX + 0xc],0x6
//         004d3581     JNZ        LAB_004d3634
//                              tact_wnd.cpp:68 (9)
//         004d3587     MOV        ESI,0x1
//         004d358c     CMP        EBP,ESI
//         004d358e     JLE        LAB_004d35b8
//                              tact_wnd.cpp:97 (3)
//         004d3590     ADD        EDI,0x4
//                               LAB_004d3593                                                 XREF[1]:     004d35b6(j)
//                              tact_wnd.cpp:69 (14)
//         004d3593     MOV        this,dword ptr [EBX + 0x8]
//         004d3596     MOV        EDX,dword ptr [ECX + this->field12_0xc]
//         004d3599     MOVSX      EAX,word ptr [EDX + 0x4a]
//         004d359d     CMP        ESI,EAX
//         004d359f     JZ         LAB_004d35b0
//                              tact_wnd.cpp:70 (23)
//         004d35a1     MOV        EAX,dword ptr [EDI]
//         004d35a3     MOV        EDX,dword ptr [this->field0_0x0]
//         004d35a5     PUSH       -0x1
//         004d35a7     PUSH       0x0=>DAT_fffffff8
//         004d35a9     PUSH       EAX=>DAT_fffffff4
//         004d35aa     CALL       dword ptr [EDX + 0xdc]
//                               LAB_004d35b0                                                 XREF[1]:     004d359f(j)
//         004d35b0     INC        ESI
//         004d35b1     ADD        EDI,0x4
//         004d35b4     CMP        ESI,EBP
//         004d35b6     JL         LAB_004d3593
//                               LAB_004d35b8                                                 XREF[1]:     004d358e(j)
//                              tact_wnd.cpp:72 (22)
//         004d35b8     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004d35be     MOV        EDX,dword ptr [this->field0_0x0 + 0x3f4]
//         004d35c4     MOV        EAX,dword ptr [EDX + 0x108]
//         004d35ca     TEST       EAX,EAX
//         004d35cc     JNZ        LAB_004d3634
//                              tact_wnd.cpp:79 (18)
//         004d35ce     MOV        EDX,dword ptr [EBX + 0x8]
//         004d35d1     XOR        EDI,EDI
//         004d35d3     MOV        ESI,dword ptr [EDX + 0xc]
//         004d35d6     MOV        EAX,dword ptr [ESI + 0x28]
//         004d35d9     MOV        this,dword ptr [EAX + 0x4]
//         004d35dc     TEST       this,this
//         004d35de     JZ         LAB_004d3605
//                               LAB_004d35e0                                                 XREF[1]:     004d35fc(j)
//                              tact_wnd.cpp:81 (23)
//         004d35e0     MOV        EAX,dword ptr [this->field0_0x0]
//         004d35e2     CMP        EAX,EDX
//         004d35e4     JZ         LAB_004d35f7
//         004d35e6     MOV        EBP,dword ptr [EAX + 0x8]
//         004d35e9     CMP        word ptr [EBP + 0x10],0x114
//         004d35ef     JNZ        LAB_004d35f7
//         004d35f1     CMP        byte ptr [EAX + 0x48],0x2
//         004d35f5     JNC        LAB_004d3600
//                               LAB_004d35f7                                                 XREF[2]:     004d35e4(j), 004d35ef(j)
//                              tact_wnd.cpp:79 (9)
//         004d35f7     MOV        this,dword ptr [ECX + this->field4_0x4]
//         004d35fa     TEST       this,this
//         004d35fc     JNZ        LAB_004d35e0
//         004d35fe     JMP        LAB_004d3605
//                               LAB_004d3600                                                 XREF[1]:     004d35f5(j)
//                              tact_wnd.cpp:83 (5)
//         004d3600     MOV        EDI,0x1
//                               LAB_004d3605                                                 XREF[2]:     004d35de(j), 004d35fe(j)
//                              tact_wnd.cpp:89 (16)
//         004d3605     MOVSX      this,word ptr [ESI + 0x4a]
//         004d3609     PUSH       this
//         004d360a     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004d3610     CALL       RGE_Base_Game::reset_countdown_timer             void reset_countdown_timer(RGE_Base_Game * th
//                              tact_wnd.cpp:90 (4)
//         004d3615     TEST       EDI,EDI
//         004d3617     JZ         LAB_004d3634
//                              tact_wnd.cpp:91 (27)
//         004d3619     MOV        EDX,dword ptr [EBX + 0x8]
//                              language.dll match for 0x7d0: "place holder"
//         004d361c     PUSH       0x7d0
//         004d3621     MOV        EAX,dword ptr [EDX + 0xc]
//         004d3624     MOVSX      this,word ptr [EAX + 0x4a]
//         004d3628     PUSH       this=>DAT_fffffff8
//         004d3629     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004d362f     CALL       RGE_Base_Game::set_countdown_timer               void set_countdown_timer(RGE_Base_Game * this
//                               LAB_004d3634                                                 XREF[3]:     004d3581(j), 004d35cc(j),
//                                                                                                         004d3617(j)
//                              tact_wnd.cpp:95 (51)
//         004d3634     MOV        ESI,dword ptr [EBX + 0x8]
//         004d3637     MOV        EDI,dword ptr [rge_base_game]                    = 00000000
//         004d363d     PUSH       0x0
//         004d363f     FLD        float ptr [ESI + 0x3c]
//         004d3642     MOV        EBP,dword ptr [EDI]
//         004d3644     CALL       __ftol                                           undefined __ftol()
//         004d3649     FLD        float ptr [ESI + 0x38]
//         004d364c     PUSH       EAX=>DAT_fffffff8
//         004d364d     CALL       __ftol                                           undefined __ftol()
//         004d3652     MOV        EDX,dword ptr [ESI + 0xc]
//         004d3655     PUSH       EAX=>DAT_fffffff4
//         004d3656     MOV        this,EDI
//         004d3658     MOVSX      EAX,word ptr [EDX + 0x4a]
//         004d365c     PUSH       EAX=>DAT_fffffff0
//                              language.dll match for 0x6e: "Copperplate Gothic Light"
//         004d365d     PUSH       0x6e
//         004d365f     CALL       dword ptr [EBP + 0x40]
//         004d3662     POP        EBP
//         004d3663     POP        ESI
//         004d3664     POP        EDI
//                               LAB_004d3665                                                 XREF[1]:     004d352d(j)
//         004d3665     MOV        this,EBX
//                              tact_wnd.cpp:97 (29)
//         004d3667     MOV        dword ptr [ESP + local_4],0xffffffff
//         004d366f     CALL       RGE_Action::~RGE_Action                          void ~RGE_Action(RGE_Action * this)
//         004d3674     MOV        this,dword ptr [ESP + 0xc]
//         004d3678     POP        EBX
//         004d3679     MOV        dword ptr FS:[0x0],this
//         004d3680     ADD        ESP,0x14
//         004d3683     RET
//         004d3684     ??         90h
//         004d3685     NOP
//         004d3686     NOP
//         004d3687     NOP
//         004d3688     NOP
//         004d3689     NOP
//         004d368a     NOP
//         004d368b     NOP
//         004d368c     NOP
//         004d368d     NOP
//         004d368e     NOP
//         004d368f     NOP
}

void TRIBE_Action_Wonder::first_in_stack(uchar param_1) {
    /* TODO: Stub */
//                              void __thiscall first_in_stack(TRIBE_Action_Wonder * this, uchar par
//              void              <VOID>         <RETURN>
//              TRIBE_Action_W    ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     004d3690(R)
//                               ?first_in_stack@TRIBE_Action_Wonder@@UAEXE@Z                 XREF[1]:     00575394(*)
//                               TRIBE_Action_Wonder::first_in_stack
//                              tact_wnd.cpp:101 (8)
//         004d3690     MOV        AL,byte ptr [ESP + param_1]
//         004d3694     TEST       AL,AL
//         004d3696     JZ         LAB_004d369f
//                              tact_wnd.cpp:103 (7)
//         004d3698     MOV        EAX,dword ptr [this->field0_0x0]
//         004d369a     PUSH       0x2
//         004d369c     CALL       dword ptr [EAX + 0x5c]
//                               LAB_004d369f                                                 XREF[1]:     004d3696(j)
//                              tact_wnd.cpp:104 (3)
//         004d369f     RET        0x4
//         004d36a2     ??         90h
//         004d36a3     NOP
//         004d36a4     NOP
//         004d36a5     NOP
//         004d36a6     NOP
//         004d36a7     NOP
//         004d36a8     NOP
//         004d36a9     NOP
//         004d36aa     NOP
//         004d36ab     NOP
//         004d36ac     NOP
//         004d36ad     NOP
//         004d36ae     NOP
//         004d36af     NOP
    return;
}

void TRIBE_Action_Wonder::set_state(uchar param_1) {
    /* TODO: Stub */
//                              void __thiscall set_state(TRIBE_Action_Wonder * this, uchar param_1)
//              void              <VOID>         <RETURN>
//              TRIBE_Action_W    ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     004d36b0(R)
//                               ?set_state@TRIBE_Action_Wonder@@UAEXE@Z                      XREF[1]:     005753d4(*)
//                               TRIBE_Action_Wonder::set_state
//                              tact_wnd.cpp:108 (13)
//         004d36b0     MOV        EAX,dword ptr [ESP + param_1]
//         004d36b4     PUSH       EBX
//         004d36b5     MOV        EBX,this
//         004d36b7     PUSH       EBP
//         004d36b8     PUSH       ESI
//         004d36b9     PUSH       EDI
//         004d36ba     MOV        byte ptr [EBX + 0xc],AL
//                              tact_wnd.cpp:115 (23)
//         004d36bd     AND        EAX,0xff
//         004d36c2     SUB        EAX,0x2
//         004d36c5     JZ         LAB_004d378d
//         004d36cb     SUB        EAX,0x4
//         004d36ce     JNZ        LAB_004d3802
//                              tact_wnd.cpp:132 (6)
//         004d36d4     MOV        this,dword ptr [rge_base_game]                   = 00000000
//                              tact_wnd.cpp:135 (22)
//         004d36da     MOV        EDI,0x1
//         004d36df     MOV        EAX,dword ptr [this->field0_0x0 + 0x3f4]
//         004d36e5     MOVSX      EBP,word ptr [EAX + 0x3c]
//         004d36e9     MOV        ESI,dword ptr [EAX + 0x40]
//         004d36ec     CMP        EBP,EDI
//         004d36ee     JLE        LAB_004d3730
//                              tact_wnd.cpp:148 (3)
//         004d36f0     ADD        ESI,0x4
//                               LAB_004d36f3                                                 XREF[1]:     004d3728(j)
//                              tact_wnd.cpp:136 (14)
//         004d36f3     MOV        this,dword ptr [EBX + 0x8]
//         004d36f6     MOV        EAX,dword ptr [ECX + this->field12_0xc]
//         004d36f9     MOVSX      EDX,word ptr [EAX + 0x4a]
//         004d36fd     CMP        EDI,EDX
//         004d36ff     JZ         LAB_004d3722
//                              tact_wnd.cpp:138 (15)
//         004d3701     MOV        EDX,dword ptr [ESI]
//         004d3703     MOV        EAX,dword ptr [this->field0_0x0]
//         004d3705     PUSH       -0x1
//         004d3707     PUSH       offset DAT_fffffff8
//         004d3709     PUSH       EDX=>DAT_fffffff4
//         004d370a     CALL       dword ptr [EAX + 0xdc]
//                              tact_wnd.cpp:139 (26)
//         004d3710     MOV        this,dword ptr [EBX + 0x8]
//         004d3713     MOV        EDX,dword ptr [ESI]
//         004d3715     PUSH       -0x1
//         004d3717     PUSH       0x0=>DAT_fffffff8
//         004d3719     MOV        EAX,dword ptr [this->field0_0x0]
//         004d371b     PUSH       EDX=>DAT_fffffff4
//         004d371c     CALL       dword ptr [EAX + 0xd8]
//                               LAB_004d3722                                                 XREF[1]:     004d36ff(j)
//         004d3722     INC        EDI
//         004d3723     ADD        ESI,0x4
//         004d3726     CMP        EDI,EBP
//         004d3728     JL         LAB_004d36f3
//                              tact_wnd.cpp:135 (6)
//         004d372a     MOV        this,dword ptr [rge_base_game]                   = 00000000
//                               LAB_004d3730                                                 XREF[1]:     004d36ee(j)
//                              tact_wnd.cpp:142 (16)
//         004d3730     MOV        EAX,dword ptr [this->field0_0x0 + 0x3f4]
//         004d3736     MOV        EDX,dword ptr [EAX + 0x108]
//         004d373c     TEST       EDX,EDX
//         004d373e     JNZ        LAB_004d3755
//                              tact_wnd.cpp:143 (21)
//         004d3740     MOV        EDX,dword ptr [EBX + 0x8]
//                              language.dll match for 0x7d0: "place holder"
//         004d3743     PUSH       0x7d0
//         004d3748     MOV        EAX,dword ptr [EDX + 0xc]
//         004d374b     MOVSX      EDX,word ptr [EAX + 0x4a]
//         004d374f     PUSH       EDX=>DAT_fffffff8
//         004d3750     CALL       RGE_Base_Game::set_countdown_timer               void set_countdown_timer(RGE_Base_Game * this
//                               LAB_004d3755                                                 XREF[1]:     004d373e(j)
//                              tact_wnd.cpp:144 (49)
//         004d3755     MOV        EBX,dword ptr [EBX + 0x8]
//         004d3758     MOV        EAX,[rge_base_game]                              = 00000000
//         004d375d     PUSH       0x0
//         004d375f     FLD        float ptr [EBX + 0x3c]
//         004d3762     MOV        ESI,dword ptr [EAX]
//         004d3764     CALL       __ftol                                           undefined __ftol()
//         004d3769     FLD        float ptr [EBX + 0x38]
//         004d376c     PUSH       EAX=>DAT_fffffff8
//         004d376d     CALL       __ftol                                           undefined __ftol()
//         004d3772     MOV        this,dword ptr [EBX + 0xc]
//         004d3775     PUSH       EAX=>DAT_fffffff4
//         004d3776     MOVSX      EDX,word ptr [this->field0_0x0 + 0x4a]
//         004d377a     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004d3780     PUSH       EDX=>DAT_fffffff0
//         004d3781     PUSH       0x6d
//         004d3783     CALL       dword ptr [ESI + 0x40]
//                              tact_wnd.cpp:148 (7)
//         004d3786     POP        EDI
//         004d3787     POP        ESI
//         004d3788     POP        EBP
//         004d3789     POP        EBX
//         004d378a     RET        0x4
//                               LAB_004d378d                                                 XREF[1]:     004d36c5(j)
//                              tact_wnd.cpp:120 (5)
//         004d378d     MOV        EAX,[rge_base_game]                              = 00000000
//                              tact_wnd.cpp:123 (22)
//         004d3792     MOV        ESI,0x1
//         004d3797     MOV        EAX,dword ptr [EAX + 0x3f4]
//         004d379d     MOVSX      EBP,word ptr [EAX + 0x3c]
//         004d37a1     MOV        EDI,dword ptr [EAX + 0x40]
//         004d37a4     CMP        EBP,ESI
//         004d37a6     JLE        LAB_004d37d0
//                              tact_wnd.cpp:148 (3)
//         004d37a8     ADD        EDI,0x4
//                               LAB_004d37ab                                                 XREF[1]:     004d37ce(j)
//                              tact_wnd.cpp:124 (14)
//         004d37ab     MOV        this,dword ptr [EBX + 0x8]
//         004d37ae     MOV        EDX,dword ptr [ECX + this->field12_0xc]
//         004d37b1     MOVSX      EAX,word ptr [EDX + 0x4a]
//         004d37b5     CMP        ESI,EAX
//         004d37b7     JZ         LAB_004d37c8
//                              tact_wnd.cpp:125 (23)
//         004d37b9     MOV        EAX,dword ptr [EDI]
//         004d37bb     MOV        EDX,dword ptr [this->field0_0x0]
//         004d37bd     PUSH       -0x1
//         004d37bf     PUSH       offset DAT_fffffff8
//         004d37c1     PUSH       EAX=>DAT_fffffff4
//         004d37c2     CALL       dword ptr [EDX + 0xd8]
//                               LAB_004d37c8                                                 XREF[1]:     004d37b7(j)
//         004d37c8     INC        ESI
//         004d37c9     ADD        EDI,0x4
//         004d37cc     CMP        ESI,EBP
//         004d37ce     JL         LAB_004d37ab
//                               LAB_004d37d0                                                 XREF[1]:     004d37a6(j)
//                              tact_wnd.cpp:127 (50)
//         004d37d0     MOV        EBX,dword ptr [EBX + 0x8]
//         004d37d3     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004d37d9     PUSH       0x0
//         004d37db     FLD        float ptr [EBX + 0x3c]
//         004d37de     MOV        ESI,dword ptr [this->field0_0x0]
//         004d37e0     CALL       __ftol                                           undefined __ftol()
//         004d37e5     FLD        float ptr [EBX + 0x38]
//         004d37e8     PUSH       EAX=>DAT_fffffff8
//         004d37e9     CALL       __ftol                                           undefined __ftol()
//         004d37ee     MOV        EDX,dword ptr [EBX + 0xc]
//         004d37f1     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004d37f7     PUSH       EAX=>DAT_fffffff4
//         004d37f8     MOVSX      EAX,word ptr [EDX + 0x4a]
//         004d37fc     PUSH       EAX=>DAT_fffffff0
//         004d37fd     PUSH       0x6c
//         004d37ff     CALL       dword ptr [ESI + 0x40]
//                               LAB_004d3802                                                 XREF[1]:     004d36ce(j)
//                              tact_wnd.cpp:148 (7)
//         004d3802     POP        EDI
//         004d3803     POP        ESI
//         004d3804     POP        EBP
//         004d3805     POP        EBX
//         004d3806     RET        0x4
//         004d3809     ??         90h
//         004d380a     NOP
//         004d380b     NOP
//         004d380c     NOP
//         004d380d     NOP
//         004d380e     NOP
//         004d380f     NOP
    return;
}

uchar TRIBE_Action_Wonder::update() {
    /* TODO: Stub */
//                              uchar __thiscall update(TRIBE_Action_Wonder * this)
//              uchar             AL:1           <RETURN>
//              TRIBE_Action_W    ECX:4 (auto)   this
//                               ?update@TRIBE_Action_Wonder@@UAEEXZ                          XREF[1]:     005753a0(*)
//                               TRIBE_Action_Wonder::update
//                              tact_wnd.cpp:152 (4)
//         004d3810     PUSH       EBX
//         004d3811     PUSH       ESI
//         004d3812     MOV        ESI,this
//                              tact_wnd.cpp:153 (24)
//         004d3814     XOR        EAX,EAX
//         004d3816     PUSH       EDI
//         004d3817     MOV        AL,byte ptr [ESI + 0xc]
//         004d381a     SUB        EAX,0x2
//         004d381d     JZ         LAB_004d38bc
//         004d3823     SUB        EAX,0x4
//         004d3826     JNZ        LAB_004d38d6
//                              tact_wnd.cpp:161 (20)
//         004d382c     FLD        float ptr [ESI + 0x2c]
//         004d382f     FCOMP      float ptr [DAT_005753d8]                         = align(2)
//         004d3835     FNSTSW     AX
//         004d3837     TEST       AH,0x1
//         004d383a     JZ         LAB_004d38d6
//                              tact_wnd.cpp:163 (23)
//         004d3840     MOV        EDI,dword ptr [ESI + 0x8]
//         004d3843     MOV        EAX,dword ptr [EDI + 0xc]
//         004d3846     MOV        this,dword ptr [EAX + 0x3c]
//         004d3849     FLD        float ptr [this->field0_0x0 + 0x84]
//         004d384f     FADD       ST0,ST0
//         004d3851     FADD       float ptr [ESI + 0x2c]
//         004d3854     FST        float ptr [ESI + 0x2c]
//                              tact_wnd.cpp:164 (22)
//         004d3857     MOV        EBX,dword ptr [rge_base_game]                    = 00000000
//         004d385d     MOV        EDX,dword ptr [EBX + 0x3f4]
//         004d3863     MOV        EAX,dword ptr [EDX + 0x108]
//         004d3869     TEST       EAX,EAX
//         004d386b     JNZ        LAB_004d38d4
//                              tact_wnd.cpp:166 (31)
//         004d386d     FLD        float ptr [DAT_005753d8]                         = align(2)
//         004d3873     FSUB       ST0,ST1
//         004d3875     CALL       __ftol                                           undefined __ftol()
//         004d387a     PUSH       EAX
//         004d387b     MOV        EAX,dword ptr [EDI + 0xc]
//         004d387e     FSTP       ST0
//         004d3880     MOVSX      this,word ptr [EAX + 0x4a]
//         004d3884     PUSH       this
//         004d3885     MOV        this,EBX
//         004d3887     CALL       RGE_Base_Game::set_countdown_timer               void set_countdown_timer(RGE_Base_Game * this
//                              tact_wnd.cpp:167 (16)
//         004d388c     FLD        float ptr [ESI + 0x2c]
//         004d388f     FCOMP      float ptr [DAT_005753d8]                         = align(2)
//         004d3895     FNSTSW     AX
//         004d3897     TEST       AH,0x1
//         004d389a     JNZ        LAB_004d38d6
//                              tact_wnd.cpp:169 (11)
//         004d389c     MOV        EDX,dword ptr [ESI + 0x8]
//         004d389f     MOV        this,dword ptr [EDX + 0xc]
//         004d38a2     CALL       RGE_Player::win_game_now                         void win_game_now(RGE_Player * this)
//                              tact_wnd.cpp:170 (11)
//         004d38a7     MOV        EAX,[rge_base_game]                              = 00000000
//         004d38ac     MOV        this,dword ptr [EAX + 0x3f4]
//                              tact_wnd.cpp:178 (6)
//         004d38b2     XOR        AL,AL
//         004d38b4     MOV        byte ptr [ECX + this->field30_0x1e],0x64
//                              tact_wnd.cpp:179 (4)
//         004d38b8     POP        EDI
//         004d38b9     POP        ESI
//         004d38ba     POP        EBX
//         004d38bb     RET
//                               LAB_004d38bc                                                 XREF[1]:     004d381d(j)
//                              tact_wnd.cpp:157 (9)
//         004d38bc     MOV        EDX,dword ptr [ESI + 0x8]
//         004d38bf     CMP        byte ptr [EDX + 0x48],0x2
//         004d38c3     JNZ        LAB_004d38d6
//                              tact_wnd.cpp:158 (9)
//         004d38c5     MOV        EAX,dword ptr [ESI]
//         004d38c7     PUSH       0x6
//         004d38c9     MOV        this,ESI
//         004d38cb     CALL       dword ptr [EAX + 0x5c]
//                              tact_wnd.cpp:178 (2)
//         004d38ce     XOR        AL,AL
//                              tact_wnd.cpp:179 (4)
//         004d38d0     POP        EDI
//         004d38d1     POP        ESI
//         004d38d2     POP        EBX
//         004d38d3     RET
//                               LAB_004d38d4                                                 XREF[1]:     004d386b(j)
//                              tact_wnd.cpp:163 (2)
//         004d38d4     FSTP       ST0
//                               LAB_004d38d6                                                 XREF[4]:     004d3826(j), 004d383a(j),
//                                                                                                         004d389a(j), 004d38c3(j)
//                              tact_wnd.cpp:179 (6)
//         004d38d6     POP        EDI
//         004d38d7     POP        ESI
//         004d38d8     XOR        AL,AL
//         004d38da     POP        EBX
//         004d38db     RET
//         004d38dc     ??         90h
//         004d38dd     NOP
//         004d38de     NOP
//         004d38df     NOP
    return 0;
}

