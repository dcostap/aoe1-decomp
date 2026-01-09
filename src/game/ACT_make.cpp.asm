#include "common.h"
#include "ACT_make.h"

RGE_Action_Make::RGE_Action_Make(int param_1, RGE_Action_Object* param_2) {
    /* TODO: Stub */
    //                              undefined __thiscall RGE_Action_Make(RGE_Action_Make * this, int par
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Action_Mak    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004049b9(R)  
    //              RGE_Action_Obj    Stack[0x8]:4   param_2                   XREF[1]:     004049b0(R)  
    //                               ??0RGE_Action_Make@@QAE@HPAVRGE_Action_Object@@@Z            XREF[1]:     create_action:00404197(c)  
    //                               RGE_Action_Make::RGE_Action_Make
    //                              ACT_make.cpp:30 (28)
    //         004049b0     MOV        EAX,dword ptr [ESP + param_2]
    //         004049b4     PUSH       ESI
    //         004049b5     MOV        ESI,this
    //         004049b7     PUSH       0x1
    //         004049b9     MOV        this,dword ptr [ESP + param_1]
    //         004049bd     PUSH       EAX
    //         004049be     PUSH       this
    //         004049bf     MOV        this,ESI
    //         004049c1     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, int p
    //         004049c6     MOV        dword ptr [ESI],RGE_Action_Make::`vftable'       = 004049e0
    //                              ACT_make.cpp:31 (6)
    //         004049cc     MOV        word ptr [ESI + 0x4],0x15
    //                              ACT_make.cpp:32 (6)
    //         004049d2     MOV        EAX,ESI
    //         004049d4     POP        ESI
    //         004049d5     RET        0x8
    //         004049d8     ??         90h
    //         004049d9     NOP
    //         004049da     NOP
    //         004049db     NOP
    //         004049dc     NOP
    //         004049dd     NOP
    //         004049de     NOP
    //         004049df     NOP
}

RGE_Action_Make::RGE_Action_Make(RGE_Action_Object* param_1, RGE_Task* param_2) {
    /* TODO: Stub */
    //                              undefined __thiscall RGE_Action_Make(RGE_Action_Make * this, RGE_Act
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Action_Mak    ECX:4 (auto)   this
    //              RGE_Action_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00404a10(R)  
    //              RGE_Task *        Stack[0x8]:4   param_2                   XREF[1]:     00404a1f(R)  
    //                               ??0RGE_Action_Make@@QAE@PAVRGE_Action_Object@@PAVRGE_Task@@@Z XREF[1]:     create_task_action:00404455(c)  
    //                               RGE_Action_Make::RGE_Action_Make
    //                              ACT_make.cpp:37 (15)
    //         00404a10     MOV        EAX,dword ptr [ESP + param_1]
    //         00404a14     PUSH       ESI
    //         00404a15     PUSH       0x1
    //         00404a17     MOV        ESI,this
    //         00404a19     PUSH       EAX
    //         00404a1a     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, RGE_A
    //                              ACT_make.cpp:40 (19)
    //         00404a1f     MOV        this,dword ptr [ESP + param_2]
    //         00404a23     MOV        dword ptr [ESI],RGE_Action_Make::`vftable'       = 004049e0
    //         00404a29     MOV        word ptr [ESI + 0x4],0x15
    //         00404a2f     MOV        dword ptr [ESI + 0x30],this
    //                              ACT_make.cpp:41 (6)
    //         00404a32     MOV        EAX,ESI
    //         00404a34     POP        ESI
    //         00404a35     RET        0x8
    //         00404a38     ??         90h
    //         00404a39     NOP
    //         00404a3a     NOP
    //         00404a3b     NOP
    //         00404a3c     NOP
    //         00404a3d     NOP
    //         00404a3e     NOP
    //         00404a3f     NOP
}

void RGE_Action_Make::first_in_stack(uchar param_1) {
    /* TODO: Stub */
    //                              void __thiscall first_in_stack(RGE_Action_Make * this, uchar param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Mak    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1
    //                               ?first_in_stack@RGE_Action_Make@@UAEXE@Z                     XREF[1]:     0056e2d4(*)  
    //                               RGE_Action_Make::first_in_stack
    //                              ACT_make.cpp:45 (3)
    //         00404a40     PUSH       ESI
    //         00404a41     MOV        ESI,this
    //                              ACT_make.cpp:46 (7)
    //         00404a43     PUSH       0x6
    //         00404a45     MOV        EAX,dword ptr [ESI]
    //         00404a47     CALL       dword ptr [EAX + 0x5c]
    //                              ACT_make.cpp:47 (21)
    //         00404a4a     MOV        this,dword ptr [ESI + 0x30]
    //         00404a4d     MOV        AX,word ptr [ECX + this->field20_0x14]
    //         00404a51     TEST       AX,AX
    //         00404a54     JL         LAB_00404a6a
    //         00404a56     MOV        this,dword ptr [ESI + 0x8]
    //         00404a59     CMP        word ptr [this->field0_0x0 + 0x4c],AX
    //         00404a5d     JZ         LAB_00404a6a
    //                              ACT_make.cpp:48 (11)
    //         00404a5f     MOV        EDX,dword ptr [this->field0_0x0]
    //         00404a61     PUSH       0x0
    //         00404a63     PUSH       EAX=>DAT_fffffff8
    //         00404a64     CALL       dword ptr [EDX + 0x80]
    //                               LAB_00404a6a                                                 XREF[2]:     00404a54(j), 00404a5d(j)  
    //                              ACT_make.cpp:49 (4)
    //         00404a6a     POP        ESI
    //         00404a6b     RET        0x4
    //         00404a6e     ??         90h
    //         00404a6f     NOP
    return;
}

void RGE_Action_Make::set_state(uchar param_1) {
    /* TODO: Stub */
    //                              void __thiscall set_state(RGE_Action_Make * this, uchar param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Mak    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00404a70(R)  
    //                               ?set_state@RGE_Action_Make@@MAEXE@Z                          XREF[1]:     0056e314(*)  
    //                               RGE_Action_Make::set_state
    //                              ACT_make.cpp:53 (4)
    //         00404a70     MOV        AL,byte ptr [ESP + param_1]
    //                              ACT_make.cpp:56 (21)
    //         00404a74     MOV        EDX,dword ptr [ECX + this->field8_0x8]
    //         00404a77     MOV        byte ptr [ECX + this->field12_0xc],AL
    //         00404a7a     MOV        EAX,dword ptr [EDX + 0xc]
    //         00404a7d     MOV        EDX,dword ptr [EAX + 0x50]
    //         00404a80     MOV        EAX,dword ptr [EDX + 0x90]
    //         00404a86     MOV        dword ptr [ECX + this->field44_0x2c],EAX
    //                              ACT_make.cpp:57 (3)
    //         00404a89     RET        0x4
    //         00404a8c     ??         90h
    //         00404a8d     NOP
    //         00404a8e     NOP
    //         00404a8f     NOP
    return;
}

uchar RGE_Action_Make::update() {
    /* TODO: Stub */
    //                              uchar __thiscall update(RGE_Action_Make * this)
    //              uchar             AL:1           <RETURN>
    //              RGE_Action_Mak    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00404b51(W)  
    //              float             Stack[-0x8]:4  pre_attribute             XREF[3]:     00404b58(W), 00404b5e(R), 00404b71(R)  
    //              float             Stack[-0xc]:4  work
    //                               ?update@RGE_Action_Make@@UAEEXZ                              XREF[1]:     0056e2e0(*)  
    //                               RGE_Action_Make::update
    //                              ACT_make.cpp:61 (3)
    //         00404a90     SUB        ESP,0x8
    //                              ACT_make.cpp:65 (27)
    //         00404a93     XOR        EAX,EAX
    //         00404a95     PUSH       ESI
    //         00404a96     MOV        ESI,this
    //         00404a98     MOV        AL,byte ptr [ESI + 0xc]
    //         00404a9b     DEC        EAX
    //         00404a9c     JZ         LAB_00404b9e
    //         00404aa2     PUSH       EDI
    //         00404aa3     PUSH       EBP
    //         00404aa4     SUB        EAX,0x5
    //         00404aa7     PUSH       EBX
    //         00404aa8     JNZ        LAB_00404b94
    //                              ACT_make.cpp:68 (44)
    //         00404aae     FLD        float ptr [ESI + 0x2c]
    //         00404ab1     FCOMP      double ptr [DAT_0056e318]                        = align(8)
    //         00404ab7     FNSTSW     AX
    //         00404ab9     TEST       AH,0x41
    //         00404abc     JZ         LAB_00404b2e
    //         00404abe     MOV        EDI,dword ptr [ESI + 0x8]
    //         00404ac1     MOV        EBX,dword ptr [EDI + 0xc]
    //         00404ac4     MOV        EAX,dword ptr [EBX + 0x50]
    //         00404ac7     FLD        float ptr [EAX + 0x90]
    //         00404acd     FCOMP      double ptr [DAT_0056e318]                        = align(8)
    //         00404ad3     FNSTSW     AX
    //         00404ad5     TEST       AH,0x41
    //         00404ad8     JNZ        LAB_00404b2e
    //                              ACT_make.cpp:85 (20)
    //         00404ada     FLD        float ptr [EDI + 0x44]
    //         00404add     FCOMP      double ptr [DAT_0056e318]                        = align(8)
    //         00404ae3     FNSTSW     AX
    //         00404ae5     TEST       AH,0x41
    //         00404ae8     JZ         LAB_00404b94
    //                              ACT_make.cpp:87 (46)
    //         00404aee     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00404af4     FLD        float ptr [EDI + 0x3c]
    //         00404af7     MOV        EBP,dword ptr [this->field0_0x0]
    //         00404af9     CALL       __ftol                                           undefined __ftol()
    //         00404afe     FLD        float ptr [EDI + 0x38]
    //         00404b01     PUSH       EAX
    //         00404b02     CALL       __ftol                                           undefined __ftol()
    //         00404b07     MOV        EDX,dword ptr [EDI + 0x4]
    //         00404b0a     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00404b10     PUSH       EAX
    //         00404b11     PUSH       EDX
    //         00404b12     MOVSX      EAX,word ptr [EBX + 0x4a]
    //         00404b16     PUSH       EAX
    //                              language.dll match for 0x7e: "10"
    //         00404b17     PUSH       0x7e
    //         00404b19     CALL       dword ptr [EBP + 0x40]
    //                              ACT_make.cpp:88 (10)
    //         00404b1c     MOV        this,dword ptr [ESI + 0x8]
    //         00404b1f     MOV        EDX,dword ptr [this->field0_0x0]
    //         00404b21     CALL       dword ptr [EDX + 0x6c]
    //         00404b24     POP        EBX
    //         00404b25     POP        EBP
    //                              ACT_make.cpp:97 (3)
    //         00404b26     XOR        AL,AL
    //         00404b28     POP        EDI
    //                              ACT_make.cpp:98 (5)
    //         00404b29     POP        ESI
    //         00404b2a     ADD        ESP,0x8
    //         00404b2d     RET
    //                               LAB_00404b2e                                                 XREF[2]:     00404abc(j), 00404ad8(j)  
    //                              ACT_make.cpp:70 (12)
    //         00404b2e     MOV        EAX,dword ptr [ESI + 0x8]
    //         00404b31     MOV        EDX,dword ptr [ESI + 0x30]
    //         00404b34     MOV        this,dword ptr [EAX + 0xc]
    //         00404b37     MOV        EDI,dword ptr [EAX + 0x8]
    //                              ACT_make.cpp:74 (36)
    //         00404b3a     CMP        word ptr [EDX + 0x30],0x0
    //         00404b3f     MOV        EBX,dword ptr [ECX + this->field60_0x3c]
    //         00404b42     FLD        float ptr [EDI + 0xe4]
    //         00404b48     FMUL       float ptr [EBX + 0x84]
    //         00404b4e     MOV        EDI,dword ptr [EAX + 0x44]
    //         00404b51     MOV        dword ptr [ESP + local_4],EDI
    //         00404b55     FMUL       float ptr [EDX + 0x1c]
    //         00404b58     FSTP       float ptr [ESP + pre_attribute]
    //         00404b5c     JZ         LAB_00404b71
    //                              ACT_make.cpp:75 (17)
    //         00404b5e     MOV        EDI,dword ptr [ESP + pre_attribute]
    //         00404b62     MOV        DX,word ptr [EDX + 0x14]
    //         00404b66     MOV        EAX,dword ptr [this->field0_0x0]
    //         00404b68     PUSH       0x0
    //         00404b6a     PUSH       EDI
    //         00404b6b     PUSH       EDX
    //         00404b6c     CALL       dword ptr [EAX + 0x78]
    //                              ACT_make.cpp:76 (2)
    //         00404b6f     JMP        LAB_00404b84
    //                               LAB_00404b71                                                 XREF[1]:     00404b5c(j)  
    //                              ACT_make.cpp:77 (19)
    //         00404b71     MOV        this,dword ptr [ESP + pre_attribute]
    //         00404b75     MOV        EDX,dword ptr [EAX]
    //         00404b77     PUSH       0x1
    //         00404b79     PUSH       0x1
    //         00404b7b     PUSH       this
    //         00404b7c     MOV        this,EAX
    //         00404b7e     CALL       dword ptr [EDX + 0x84]
    //                               LAB_00404b84                                                 XREF[1]:     00404b6f(j)  
    //                              ACT_make.cpp:80 (18)
    //         00404b84     MOV        EDX,dword ptr [ESI + 0x8]
    //         00404b87     FLD        float ptr [EDX + 0x44]
    //         00404b8a     FSUB       float ptr [ESP + 0x14]
    //         00404b8e     FSUBR      float ptr [ESI + 0x2c]
    //         00404b91     FSTP       float ptr [ESI + 0x2c]
    //                               LAB_00404b94                                                 XREF[2]:     00404aa8(j), 00404ae8(j)  
    //         00404b94     POP        EBX
    //         00404b95     POP        EBP
    //                              ACT_make.cpp:97 (3)
    //         00404b96     XOR        AL,AL
    //         00404b98     POP        EDI
    //                              ACT_make.cpp:98 (5)
    //         00404b99     POP        ESI
    //         00404b9a     ADD        ESP,0x8
    //         00404b9d     RET
    //                               LAB_00404b9e                                                 XREF[1]:     00404a9c(j)  
    //                              ACT_make.cpp:94 (2)
    //         00404b9e     MOV        AL,0x1
    //                              ACT_make.cpp:98 (5)
    //         00404ba0     POP        ESI
    //         00404ba1     ADD        ESP,0x8
    //         00404ba4     RET
    //         00404ba5     ??         90h
    //         00404ba6     NOP
    //         00404ba7     NOP
    //         00404ba8     NOP
    //         00404ba9     NOP
    //         00404baa     NOP
    //         00404bab     NOP
    //         00404bac     NOP
    //         00404bad     NOP
    //         00404bae     NOP
    //         00404baf     NOP
    return 0;
}

RGE_Action_Make::~RGE_Action_Make() {
    /* TODO: Stub */
    //                              void __thiscall ~RGE_Action_Make(RGE_Action_Make * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Action_Mak    ECX:4 (auto)   this
    //                               ??1RGE_Action_Make@@UAE@XZ                                   XREF[1]:     `vector_deleting_destructor':00404
    //                               RGE_Action_Make::~RGE_Action_Make
    //         00404a00     JMP        RGE_Action::~RGE_Action
    //         00404a05     ??         90h
    //         00404a06     NOP
    //         00404a07     NOP
    //         00404a08     NOP
    //         00404a09     NOP
    //         00404a0a     NOP
    //         00404a0b     NOP
    //         00404a0c     NOP
    //         00404a0d     NOP
    //         00404a0e     NOP
    //         00404a0f     NOP
}

