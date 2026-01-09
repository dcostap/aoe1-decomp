#include "common.h"
#include "taiuaimd.h"

TribeHuntedAnimalUnitAIModule::~TribeHuntedAnimalUnitAIModule() {
    /* TODO: Stub */
    //                              void __thiscall ~TribeHuntedAnimalUnitAIModule(TribeHuntedAnimalUnit
    //              void              <VOID>         <RETURN>
    //              TribeHuntedAni    ECX:4 (auto)   this
    //                               ??1TribeHuntedAnimalUnitAIModule@@UAE@XZ                     XREF[1]:     `scalar_deleting_destructor':00503
    //                               TribeHuntedAnimalUnitAIModule::~TribeHuntedAnimalUnitAIModule
    //         00503d20     JMP        UnitAIModule::~UnitAIModule
    //         00503d25     ??         90h
    //         00503d26     NOP
    //         00503d27     NOP
    //         00503d28     NOP
    //         00503d29     NOP
    //         00503d2a     NOP
    //         00503d2b     NOP
    //         00503d2c     NOP
    //         00503d2d     NOP
    //         00503d2e     NOP
    //         00503d2f     NOP
    //                              * protected: virtual int __thiscall TribeHuntedAnimalUnitAIModule::processNotify(struct NotifyEvent ... *
    //                              int __thiscall processNotify(TribeHuntedAnimalUnitAIModule * this, N
    //              int               EAX:4          <RETURN>
    //              TribeHuntedAni    ECX:4 (auto)   this
    //              NotifyEvent *     Stack[0x4]:4   param_1                   XREF[1]:     00503d30(R)  
    //              ulong             Stack[0x8]:4   param_2                   XREF[2]:     00503d4a(R), 00503d71(R)  
    //                               ?processNotify@TribeHuntedAnimalUnitAIModule@@MAEHPAUNotify  XREF[1]:     0057589c(*)  
    //                               TribeHuntedAnimalUnitAIModule::processNotify
    //                              taiuaimd.cpp:99 (26)
    //         00503d30     MOV        EAX,dword ptr [ESP + param_1]
    //         00503d34     PUSH       EBX
    //         00503d35     PUSH       EBP
    //         00503d36     PUSH       ESI
    //         00503d37     MOV        ESI,this
    //         00503d39     PUSH       EDI
    //         00503d3a     MOV        this,dword ptr [EAX + 0x8]
    //         00503d3d     SUB        this,0x1f4
    //         00503d43     JZ         LAB_00503d6a
    //         00503d45     SUB        this,0x1b
    //         00503d48     JZ         LAB_00503d5e
    //                              taiuaimd.cpp:135 (13)
    //         00503d4a     MOV        this,dword ptr [ESP + param_2]
    //         00503d4e     PUSH       this
    //         00503d4f     PUSH       EAX
    //         00503d50     MOV        this,ESI
    //         00503d52     CALL       UnitAIModule::processNotify                      int processNotify(UnitAIModule * this, Notify
    //                              taiuaimd.cpp:136 (7)
    //         00503d57     POP        EDI
    //         00503d58     POP        ESI
    //         00503d59     POP        EBP
    //         00503d5a     POP        EBX
    //         00503d5b     RET        0x8
    //                               LAB_00503d5e                                                 XREF[1]:     00503d48(j)  
    //                              taiuaimd.cpp:108 (5)
    //         00503d5e     MOV        EAX,0x2
    //                              taiuaimd.cpp:136 (7)
    //         00503d63     POP        EDI
    //         00503d64     POP        ESI
    //         00503d65     POP        EBP
    //         00503d66     POP        EBX
    //         00503d67     RET        0x8
    //                               LAB_00503d6a                                                 XREF[1]:     00503d43(j)  
    //                              taiuaimd.cpp:116 (7)
    //         00503d6a     MOV        this,dword ptr [EAX + 0x10]
    //         00503d6d     TEST       this,this
    //         00503d6f     JG         LAB_00503d89
    //                              taiuaimd.cpp:120 (12)
    //         00503d71     MOV        EDX,dword ptr [ESP + param_2]
    //         00503d75     MOV        this,ESI
    //         00503d77     PUSH       EDX
    //         00503d78     CALL       UnitAIModule::purgeNotifyQueue                   void purgeNotifyQueue(UnitAIModule * this, ul
    //                              taiuaimd.cpp:121 (5)
    //         00503d7d     MOV        EAX,0x4
    //                              taiuaimd.cpp:136 (7)
    //         00503d82     POP        EDI
    //         00503d83     POP        ESI
    //         00503d84     POP        EBP
    //         00503d85     POP        EBX
    //         00503d86     RET        0x8
    //                               LAB_00503d89                                                 XREF[1]:     00503d6f(j)  
    //                              taiuaimd.cpp:124 (130)
    //         00503d89     MOV        EBP,dword ptr [EAX]
    //         00503d8b     MOV        this,dword ptr [ESI + 0x64]
    //         00503d8e     XOR        EAX,EAX
    //         00503d90     TEST       this,this
    //         00503d92     JLE        LAB_00503da8
    //         00503d94     MOV        EDX,dword ptr [ESI + 0x6c]
    //                               LAB_00503d97                                                 XREF[1]:     00503da6(j)  
    //         00503d97     CMP        EAX,EDX
    //         00503d99     JGE        LAB_00503da8
    //         00503d9b     MOV        EDI,dword ptr [ESI + 0x60]
    //         00503d9e     CMP        dword ptr [EDI + EAX*0x4],EBP
    //         00503da1     JZ         LAB_00503e0b
    //         00503da3     INC        EAX
    //         00503da4     CMP        EAX,this
    //         00503da6     JL         LAB_00503d97
    //                               LAB_00503da8                                                 XREF[2]:     00503d92(j), 00503d99(j)  
    //         00503da8     MOV        EAX,dword ptr [ESI + 0x6c]
    //         00503dab     DEC        EAX
    //         00503dac     CMP        this,EAX
    //         00503dae     JLE        LAB_00503dfb
    //         00503db0     LEA        EBX,[ECX + this->field1_0x1]
    //         00503db3     LEA        this,[EBX*0x4 + 0x0]
    //         00503dba     PUSH       this
    //         00503dbb     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00503dc0     MOV        EDI,EAX
    //         00503dc2     ADD        ESP,0x4
    //         00503dc5     TEST       EDI,EDI
    //         00503dc7     JZ         LAB_00503dfb
    //         00503dc9     MOV        this,dword ptr [ESI + 0x6c]
    //         00503dcc     XOR        EAX,EAX
    //         00503dce     TEST       this,this
    //         00503dd0     JLE        LAB_00503de9
    //                               LAB_00503dd2                                                 XREF[1]:     00503de7(j)  
    //         00503dd2     CMP        EAX,EBX
    //         00503dd4     JGE        LAB_00503de9
    //         00503dd6     MOV        EDX,dword ptr [ESI + 0x60]
    //         00503dd9     INC        EAX
    //         00503dda     MOV        this,dword ptr [EDX + EAX*0x4 + -0x4]
    //         00503dde     MOV        dword ptr [EDI + EAX*0x4 + -0x4],this
    //         00503de2     MOV        this,dword ptr [ESI + 0x6c]
    //         00503de5     CMP        EAX,this
    //         00503de7     JL         LAB_00503dd2
    //                               LAB_00503de9                                                 XREF[2]:     00503dd0(j), 00503dd4(j)  
    //         00503de9     MOV        EDX,dword ptr [ESI + 0x60]
    //         00503dec     PUSH       EDX
    //         00503ded     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00503df2     ADD        ESP,0x4
    //         00503df5     MOV        dword ptr [ESI + 0x60],EDI
    //         00503df8     MOV        dword ptr [ESI + 0x6c],EBX
    //                               LAB_00503dfb                                                 XREF[2]:     00503dae(j), 00503dc7(j)  
    //         00503dfb     MOV        EAX,dword ptr [ESI + 0x64]
    //         00503dfe     MOV        this,dword ptr [ESI + 0x60]
    //         00503e01     MOV        dword ptr [this->field0_0x0 + EAX*0x4],EBP
    //         00503e04     MOV        EAX,dword ptr [ESI + 0x64]
    //         00503e07     INC        EAX
    //         00503e08     MOV        dword ptr [ESI + 0x64],EAX
    //                               LAB_00503e0b                                                 XREF[1]:     00503da1(j)  
    //                              taiuaimd.cpp:125 (13)
    //         00503e0b     MOV        this,dword ptr [ESI + 0x4]
    //         00503e0e     PUSH       0x1
    //         00503e10     MOV        EDX,dword ptr [this->field0_0x0]
    //         00503e12     CALL       dword ptr [EDX + 0xec]
    //                              taiuaimd.cpp:131 (12)
    //         00503e18     MOV        EAX,dword ptr [ESI]
    //         00503e1a     PUSH       0x1
    //         00503e1c     MOV        this,ESI
    //         00503e1e     CALL       dword ptr [EAX + 0xa4]
    //                              taiuaimd.cpp:136 (12)
    //         00503e24     POP        EDI
    //         00503e25     POP        ESI
    //         00503e26     POP        EBP
    //         00503e27     MOV        EAX,0x3
    //         00503e2c     POP        EBX
    //         00503e2d     RET        0x8
}

int TribeHuntedAnimalUnitAIModule::processIdle(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall processIdle(TribeHuntedAnimalUnitAIModule * this, int
    //              int               EAX:4          <RETURN>
    //              TribeHuntedAni    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //              float             Stack[-0x8]:4  xDiff
    //              float             Stack[-0xc]:4  yDiff
    //                               ?processIdle@TribeHuntedAnimalUnitAIModule@@MAEHH@Z          XREF[1]:     005758a4(*)  
    //                               TribeHuntedAnimalUnitAIModule::processIdle
    //                              taiuaimd.cpp:141 (8)
    //         00503e30     SUB        ESP,0x8
    //         00503e33     PUSH       EBX
    //         00503e34     PUSH       ESI
    //         00503e35     PUSH       EDI
    //         00503e36     MOV        ESI,this
    //                              taiuaimd.cpp:144 (15)
    //         00503e38     PUSH       0x0
    //         00503e3a     PUSH       -0x1
    //         00503e3c     MOV        EBX,dword ptr [ESI]
    //         00503e3e     PUSH       -0x1
    //         00503e40     PUSH       -0x1
    //         00503e42     PUSH       -0x1
    //         00503e44     CALL       dword ptr [EBX + 0x40]
    //                              taiuaimd.cpp:145 (9)
    //         00503e47     CMP        EAX,-0x1
    //         00503e4a     JZ         LAB_00503f07
    //                              taiuaimd.cpp:151 (17)
    //         00503e50     PUSH       EAX
    //         00503e51     MOV        EAX,dword ptr [ESI + 0x4]
    //         00503e54     MOV        this,dword ptr [EAX + 0xc]
    //         00503e57     MOV        this,dword ptr [ECX + this->field60_0x3c]
    //         00503e5a     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //         00503e5f     MOV        EDI,EAX
    //                              taiuaimd.cpp:153 (2)
    //         00503e61     TEST       EDI,EDI
    //                              taiuaimd.cpp:154 (6)
    //         00503e63     JZ         LAB_00503f07
    //                              taiuaimd.cpp:159 (11)
    //         00503e69     MOV        this,dword ptr [ESI + 0x4]
    //         00503e6c     MOV        EDX,dword ptr [this->field0_0x0]
    //         00503e6e     CALL       dword ptr [EDX + 0xfc]
    //                              taiuaimd.cpp:165 (133)
    //         00503e74     FLD        float ptr [EDI + 0x3c]
    //         00503e77     MOV        EAX,dword ptr [ESI + 0x4]
    //         00503e7a     PUSH       0x1
    //         00503e7c     FLD        float ptr [EDI + 0x38]
    //         00503e7f     FSUB       float ptr [EAX + 0x38]
    //         00503e82     FXCH
    //         00503e84     FSUB       float ptr [EAX + 0x3c]
    //         00503e87     FXCH       ST2
    //         00503e89     FMUL       float ptr [DAT_005758b0]                         = align(2)
    //         00503e8f     FXCH
    //         00503e91     FST        float ptr [ESP + 0x14]
    //         00503e95     FXCH       ST2
    //         00503e97     FST        float ptr [ESP + 0x10]
    //         00503e9b     FXCH       ST2
    //         00503e9d     FMUL       float ptr [ESP + 0x14]
    //         00503ea1     FLD        float ptr [ESP + 0x10]
    //         00503ea5     FXCH       ST3
    //         00503ea7     FMUL       float ptr [ESP + 0x10]
    //         00503eab     FLD        float ptr [ESP + 0x14]
    //         00503eaf     FXCH       ST3
    //         00503eb1     FSTP       float ptr [ESP + 0x10]
    //         00503eb5     MOV        EDX,dword ptr [EAX + 0x40]
    //         00503eb8     MOV        this,ESI
    //         00503eba     FADDP
    //         00503ebc     PUSH       EDX
    //         00503ebd     PUSH       this
    //         00503ebe     FSQRT
    //         00503ec0     FSTP       float ptr [ESP + 0x1c]
    //         00503ec4     FXCH
    //         00503ec6     FDIV       float ptr [ESP + 0x1c]
    //         00503eca     FXCH
    //         00503ecc     FDIV       float ptr [ESP + 0x1c]
    //         00503ed0     FXCH
    //         00503ed2     FMUL       float ptr [ESP + 0x18]
    //         00503ed6     FXCH
    //         00503ed8     FMUL       float ptr [ESP + 0x18]
    //         00503edc     FXCH
    //         00503ede     FCHS
    //         00503ee0     FADD       float ptr [EAX + 0x3c]
    //         00503ee3     FXCH
    //         00503ee5     FCHS
    //         00503ee7     FADD       float ptr [EAX + 0x38]
    //         00503eea     FXCH
    //         00503eec     FSTP       float ptr [ESP]
    //         00503eef     PUSH       this
    //         00503ef0     FSTP       float ptr [ESP]
    //         00503ef3     CALL       dword ptr [EBX + 0x9c]
    //                              taiuaimd.cpp:166 (5)
    //         00503ef9     MOV        EAX,0x6
    //                              taiuaimd.cpp:169 (23)
    //         00503efe     POP        EDI
    //         00503eff     POP        ESI
    //         00503f00     POP        EBX
    //         00503f01     ADD        ESP,0x8
    //         00503f04     RET        0x4
    //                               LAB_00503f07                                                 XREF[2]:     00503e4a(j), 00503e63(j)  
    //         00503f07     POP        EDI
    //         00503f08     POP        ESI
    //         00503f09     MOV        EAX,0x5
    //         00503f0e     POP        EBX
    //         00503f0f     ADD        ESP,0x8
    //         00503f12     RET        0x4
    //         00503f15     ??         90h
    //         00503f16     NOP
    //         00503f17     NOP
    //         00503f18     NOP
    //         00503f19     NOP
    //         00503f1a     NOP
    //         00503f1b     NOP
    //         00503f1c     NOP
    //         00503f1d     NOP
    //         00503f1e     NOP
    //         00503f1f     NOP
    //                              * public: __thiscall TribePreditorUnitAIModule::TribePreditorUnitAIModule(class RGE_Static_Object *,... *
    //                              undefined __thiscall TribePreditorUnitAIModule(TribePreditorUnitAIMo
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TribePreditorU    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00503f3e(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     00503f36(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00503f50(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00504054(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00503f42(W)  
    //                               ??0TribePreditorUnitAIModule@@QAE@PAVRGE_Static_Object@@H@Z  XREF[1]:     initUnitAI:004cbb0a(c)  
    //                               TribePreditorUnitAIModule::TribePreditorUnitAIModule
    //                              taiuaimd.cpp:177 (46)
    //         00503f20     PUSH       -0x1
    //         00503f22     PUSH       FUN_00560c28
    //         00503f27     MOV        EAX,FS:[0x0]
    //         00503f2d     PUSH       EAX
    //         00503f2e     MOV        dword ptr FS:[0x0],ESP
    //         00503f35     PUSH       this
    //         00503f36     MOV        EAX,dword ptr [ESP + param_2]
    //         00503f3a     PUSH       ESI
    //         00503f3b     MOV        ESI,this
    //         00503f3d     PUSH       EAX
    //         00503f3e     MOV        this,dword ptr [ESP + param_1]
    //         00503f42     MOV        dword ptr [ESP + local_10],ESI
    //         00503f46     PUSH       this
    //         00503f47     MOV        this,ESI
    //         00503f49     CALL       UnitAIModule::UnitAIModule                       undefined UnitAIModule(UnitAIModule * this, R
    //                              taiuaimd.cpp:182 (40)
    //         00503f4e     PUSH       0x44
    //         00503f50     MOV        dword ptr [ESP + local_4],0x0
    //         00503f58     MOV        dword ptr [ESI],TribePreditorUnitAIModule::`vf   = 00504070
    //         00503f5e     MOV        dword ptr [ESI + 0x128],0x11
    //         00503f68     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00503f6d     ADD        ESP,0x4
    //         00503f70     MOV        dword ptr [ESI + 0x124],EAX
    //                              taiuaimd.cpp:183 (8)
    //         00503f76     TEST       EAX,EAX
    //         00503f78     JZ         LAB_00504054
    //                              taiuaimd.cpp:184 (6)
    //         00503f7e     MOV        dword ptr [EAX],0x1d
    //                              taiuaimd.cpp:185 (13)
    //         00503f84     MOV        EDX,dword ptr [ESI + 0x124]
    //         00503f8a     MOV        dword ptr [EDX + 0x4],0x9
    //                              taiuaimd.cpp:186 (13)
    //         00503f91     MOV        EAX,dword ptr [ESI + 0x124]
    //         00503f97     MOV        dword ptr [EAX + 0x8],0x0
    //                              taiuaimd.cpp:187 (13)
    //         00503f9e     MOV        this,dword ptr [ESI + 0x124]
    //         00503fa4     MOV        dword ptr [ECX + this->field12_0xc],0x4
    //                              taiuaimd.cpp:188 (13)
    //         00503fab     MOV        EDX,dword ptr [ESI + 0x124]
    //         00503fb1     MOV        dword ptr [EDX + 0x10],0x1a
    //                              taiuaimd.cpp:189 (13)
    //         00503fb8     MOV        EAX,dword ptr [ESI + 0x124]
    //         00503fbe     MOV        dword ptr [EAX + 0x14],0x18
    //                              taiuaimd.cpp:190 (13)
    //         00503fc5     MOV        this,dword ptr [ESI + 0x124]
    //         00503fcb     MOV        dword ptr [ECX + this->field24_0x18],0x6
    //                              taiuaimd.cpp:191 (13)
    //         00503fd2     MOV        EDX,dword ptr [ESI + 0x124]
    //         00503fd8     MOV        dword ptr [EDX + 0x1c],0x19
    //                              taiuaimd.cpp:192 (13)
    //         00503fdf     MOV        EAX,dword ptr [ESI + 0x124]
    //         00503fe5     MOV        dword ptr [EAX + 0x20],0x11
    //                              taiuaimd.cpp:193 (13)
    //         00503fec     MOV        this,dword ptr [ESI + 0x124]
    //         00503ff2     MOV        dword ptr [ECX + this->field36_0x24],0xd
    //                              taiuaimd.cpp:194 (13)
    //         00503ff9     MOV        EDX,dword ptr [ESI + 0x124]
    //         00503fff     MOV        dword ptr [EDX + 0x28],0xc
    //                              taiuaimd.cpp:195 (13)
    //         00504006     MOV        EAX,dword ptr [ESI + 0x124]
    //         0050400c     MOV        dword ptr [EAX + 0x2c],0x23
    //                              taiuaimd.cpp:196 (13)
    //         00504013     MOV        this,dword ptr [ESI + 0x124]
    //         00504019     MOV        dword ptr [ECX + this->field48_0x30],0x17
    //                              taiuaimd.cpp:197 (13)
    //         00504020     MOV        EDX,dword ptr [ESI + 0x124]
    //         00504026     MOV        dword ptr [EDX + 0x34],0x24
    //                              taiuaimd.cpp:198 (13)
    //         0050402d     MOV        EAX,dword ptr [ESI + 0x124]
    //         00504033     MOV        dword ptr [EAX + 0x38],0x1c
    //                              taiuaimd.cpp:199 (13)
    //         0050403a     MOV        this,dword ptr [ESI + 0x124]
    //         00504040     MOV        dword ptr [ECX + this->field60_0x3c],0x12
    //                              taiuaimd.cpp:200 (13)
    //         00504047     MOV        EDX,dword ptr [ESI + 0x124]
    //         0050404d     MOV        dword ptr [EDX + 0x40],0x27
    //                               LAB_00504054                                                 XREF[1]:     00503f78(j)  
    //                              taiuaimd.cpp:202 (20)
    //         00504054     MOV        this,dword ptr [ESP + local_c]
    //         00504058     MOV        EAX,ESI
    //         0050405a     MOV        dword ptr FS:[0x0],this
    //         00504061     POP        ESI
    //         00504062     ADD        ESP,0x10
    //         00504065     RET        0x8
    //         00504068     ??         90h
    //         00504069     NOP
    //         0050406a     NOP
    //         0050406b     NOP
    //         0050406c     NOP
    //         0050406d     NOP
    //         0050406e     NOP
    //         0050406f     NOP
    //                              * public: virtual void * __thiscall TribePreditorUnitAIModule::`vector deleting destructor'(unsigned... *
    //                              void * __thiscall `vector_deleting_destructor'(TribePreditorUnitAIMo
    //              void *            EAX:4          <RETURN>
    //              TribePreditorU    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00504078(R)  
    //                               ??_GTribePreditorUnitAIModule@@UAEPAXI@Z                     XREF[1]:     005758e8(*)  
    //                               ??_ETribePreditorUnitAIModule@@UAEPAXI@Z
    //                               TribePreditorUnitAIModule::`vector_deleting_destructor'
    //         00504070     PUSH       ESI
    //         00504071     MOV        ESI,this
    //         00504073     CALL       TribePreditorUnitAIModule::~TribePreditorUnitA   void ~TribePreditorUnitAIModule(TribePreditor
    //         00504078     TEST       byte ptr [ESP + param_1],0x1
    //         0050407d     JZ         LAB_00504088
    //         0050407f     PUSH       ESI
    //         00504080     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00504085     ADD        ESP,0x4
    //                               LAB_00504088                                                 XREF[1]:     0050407d(j)  
    //         00504088     MOV        EAX,ESI
    //         0050408a     POP        ESI
    //         0050408b     RET        0x4
    //                              *                                            THUNK FUNCTION                                             *
    //                              thunk void __thiscall ~UnitAIModule(UnitAIModule * this)
    //                                Thunked-Function: UnitAIModule::~UnitAIMo
    //              void              <VOID>         <RETURN>
    //              UnitAIModule *    ECX:4 (auto)   this
    //                               UnitAIModule::~UnitAIModule
    //         0050408e     NOP
    //         0050408f     NOP
    return 0;
}

int TribePreditorUnitAIModule::canAttackUnitAtNeutrality(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall canAttackUnitAtNeutrality(TribePreditorUnitAIModule *
    //              int               EAX:4          <RETURN>
    //              TribePreditorU    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //                               ?canAttackUnitAtNeutrality@TribePreditorUnitAIModule@@UAEHH@Z XREF[1]:     0057593c(*)  
    //                               TribePreditorUnitAIModule::canAttackUnitAtNeutrality
    //                              taiuaimd.cpp:207 (5)
    //         005040a0     MOV        EAX,0x1
    //                              taiuaimd.cpp:210 (3)
    //         005040a5     RET        0x4
    //         005040a8     ??         90h
    //         005040a9     NOP
    //         005040aa     NOP
    //         005040ab     NOP
    //         005040ac     NOP
    //         005040ad     NOP
    //         005040ae     NOP
    //         005040af     NOP
    //                              * protected: virtual int __thiscall TribePreditorUnitAIModule::processNotify(struct NotifyEvent *,un... *
    //                              int __thiscall processNotify(TribePreditorUnitAIModule * this, Notif
    //              int               EAX:4          <RETURN>
    //              TribePreditorU    ECX:4 (auto)   this
    //              NotifyEvent *     Stack[0x4]:4   param_1                   XREF[1]:     005040b1(R)  
    //              ulong             Stack[0x8]:4   param_2                   XREF[1]:     00504156(R)  
    //                               ?processNotify@TribePreditorUnitAIModule@@MAEHPAUNotifyEven  XREF[1]:     005759b4(*)  
    //                               TribePreditorUnitAIModule::processNotify
    //                              taiuaimd.cpp:216 (1)
    //         005040b0     PUSH       EBX
    //                              taiuaimd.cpp:227 (22)
    //         005040b1     MOV        EBX,dword ptr [ESP + param_1]
    //         005040b5     PUSH       ESI
    //         005040b6     PUSH       EDI
    //         005040b7     MOV        EAX,dword ptr [EBX + 0x8]
    //         005040ba     MOV        ESI,this
    //         005040bc     CMP        EAX,0x1fc
    //         005040c1     JNZ        LAB_00504156
    //                              taiuaimd.cpp:230 (18)
    //         005040c7     MOV        this,dword ptr [ESI + 0x4]
    //         005040ca     MOV        EAX,dword ptr [ESI + 0x34]
    //         005040cd     PUSH       EAX
    //         005040ce     MOV        EDX,dword ptr [ECX + this->field12_0xc]
    //         005040d1     MOV        this,dword ptr [EDX + 0x3c]
    //         005040d4     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //                              taiuaimd.cpp:236 (4)
    //         005040d9     TEST       EAX,EAX
    //         005040db     JZ         LAB_0050410e
    //                              taiuaimd.cpp:237 (25)
    //         005040dd     MOV        this,dword ptr [ESI + 0x4]
    //         005040e0     PUSH       EAX
    //         005040e1     CALL       RGE_Static_Object::distance_to_object            float distance_to_object(RGE_Static_Object * 
    //         005040e6     MOV        EAX,dword ptr [ESI + 0x4]
    //         005040e9     MOV        this,dword ptr [EAX + 0x8]
    //         005040ec     FCOMP      float ptr [ECX + this->field40_0x28]
    //         005040ef     FNSTSW     AX
    //         005040f1     TEST       AH,0x41
    //         005040f4     JZ         LAB_0050410e
    //                              taiuaimd.cpp:241 (13)
    //         005040f6     MOV        EAX,dword ptr [ESI + 0x34]
    //         005040f9     MOV        EDX,dword ptr [ESI]
    //         005040fb     PUSH       0x1
    //         005040fd     PUSH       EAX
    //         005040fe     MOV        this,ESI
    //         00504100     CALL       dword ptr [EDX + 0x5c]
    //                              taiuaimd.cpp:242 (5)
    //         00504103     MOV        EAX,0x3
    //                              taiuaimd.cpp:258 (6)
    //         00504108     POP        EDI
    //         00504109     POP        ESI
    //         0050410a     POP        EBX
    //         0050410b     RET        0x8
    //                               LAB_0050410e                                                 XREF[2]:     005040db(j), 005040f4(j)  
    //                              taiuaimd.cpp:248 (7)
    //         0050410e     MOV        this,ESI
    //         00504110     CALL       UnitAIModule::removeCurrentTarget                void removeCurrentTarget(UnitAIModule * this)
    //                              taiuaimd.cpp:250 (50)
    //         00504115     MOV        this,dword ptr [actionFile]                      = 00000000
    //         0050411b     TEST       this,this
    //         0050411d     JZ         LAB_00504147
    //         0050411f     MOV        EAX,dword ptr [ESI + 0x4]
    //         00504122     TEST       EAX,EAX
    //         00504124     JZ         LAB_0050412b
    //         00504126     MOV        EAX,dword ptr [EAX + 0x4]
    //         00504129     JMP        LAB_0050412e
    //                               LAB_0050412b                                                 XREF[1]:     00504124(j)  
    //         0050412b     OR         EAX,0xffffffff
    //                               LAB_0050412e                                                 XREF[1]:     00504129(j)  
    //         0050412e     PUSH       0xfa
    //         00504133     PUSH       s_C:\msdev\work\age1_x1\taiuaimd.c               = "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp"
    //         00504138     PUSH       EAX
    //         00504139     PUSH       s_#%d_call_stopObject_%s_%d_                     = "#%d call stopObject %s %d\n"
    //         0050413e     PUSH       this
    //         0050413f     CALL       fprintf                                          undefined fprintf()
    //         00504144     ADD        ESP,0x14
    //                               LAB_00504147                                                 XREF[1]:     0050411d(j)  
    //                              taiuaimd.cpp:252 (9)
    //         00504147     MOV        EDI,dword ptr [ESI]
    //         00504149     PUSH       0x1
    //         0050414b     MOV        this,ESI
    //         0050414d     CALL       dword ptr [EDI + 0x58]
    //                              taiuaimd.cpp:253 (6)
    //         00504150     PUSH       EBX
    //         00504151     MOV        this,ESI
    //         00504153     CALL       dword ptr [EDI + 0x1c]
    //                               LAB_00504156                                                 XREF[1]:     005040c1(j)  
    //                              taiuaimd.cpp:257 (13)
    //         00504156     MOV        this,dword ptr [ESP + param_2]
    //         0050415a     PUSH       this
    //         0050415b     PUSH       EBX=>DAT_fffffff8
    //         0050415c     MOV        this,ESI
    //         0050415e     CALL       UnitAIModule::processNotify                      int processNotify(UnitAIModule * this, Notify
    //                              taiuaimd.cpp:258 (6)
    //         00504163     POP        EDI
    //         00504164     POP        ESI
    //         00504165     POP        EBX
    //         00504166     RET        0x8
    //         00504169     ??         90h
    //         0050416a     NOP
    //         0050416b     NOP
    //         0050416c     NOP
    //         0050416d     NOP
    //         0050416e     NOP
    //         0050416f     NOP
    //                              * public: __thiscall TribeElephantUnitAIModule::TribeElephantUnitAIModule(class RGE_Static_Object *,... *
    //                              undefined __thiscall TribeElephantUnitAIModule(TribeElephantUnitAIMo
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TribeElephantU    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00504178(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     00504170(R)  
    //                               ??0TribeElephantUnitAIModule@@QAE@PAVRGE_Static_Object@@H@Z  XREF[1]:     initUnitAI:004cba8d(c)  
    //                               TribeElephantUnitAIModule::TribeElephantUnitAIModule
    //                              taiuaimd.cpp:266 (26)
    //         00504170     MOV        EAX,dword ptr [ESP + param_2]
    //         00504174     PUSH       ESI
    //         00504175     MOV        ESI,this
    //         00504177     PUSH       EAX
    //         00504178     MOV        this,dword ptr [ESP + param_1]
    //         0050417c     PUSH       this
    //         0050417d     MOV        this,ESI
    //         0050417f     CALL       UnitAIModule::UnitAIModule                       undefined UnitAIModule(UnitAIModule * this, R
    //         00504184     MOV        dword ptr [ESI],TribeElephantUnitAIModule::`vf   = 00504190
    //                              taiuaimd.cpp:268 (6)
    //         0050418a     MOV        EAX,ESI
    //         0050418c     POP        ESI
    //         0050418d     RET        0x8
    //                              * public: virtual void * __thiscall TribeElephantUnitAIModule::`vector deleting destructor'(unsigned... *
    //                              void * __thiscall `vector_deleting_destructor'(TribeElephantUnitAIMo
    //              void *            EAX:4          <RETURN>
    //              TribeElephantU    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00504198(R)  
    //                               ??_GTribeElephantUnitAIModule@@UAEPAXI@Z                     XREF[1]:     005759c8(*)  
    //                               ??_ETribeElephantUnitAIModule@@UAEPAXI@Z
    //                               TribeElephantUnitAIModule::`vector_deleting_destructor'
    //         00504190     PUSH       ESI
    //         00504191     MOV        ESI,this
    //         00504193     CALL       TribeElephantUnitAIModule::~TribeElephantUnitA   void ~TribeElephantUnitAIModule(TribeElephant
    //         00504198     TEST       byte ptr [ESP + param_1],0x1
    //         0050419d     JZ         LAB_005041a8
    //         0050419f     PUSH       ESI
    //         005041a0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         005041a5     ADD        ESP,0x4
    //                               LAB_005041a8                                                 XREF[1]:     0050419d(j)  
    //         005041a8     MOV        EAX,ESI
    //         005041aa     POP        ESI
    //         005041ab     RET        0x4
    //                              *                                            THUNK FUNCTION                                             *
    //                              thunk void __thiscall ~UnitAIModule(UnitAIModule * this)
    //                                Thunked-Function: UnitAIModule::~UnitAIMo
    //              void              <VOID>         <RETURN>
    //              UnitAIModule *    ECX:4 (auto)   this
    //                               UnitAIModule::~UnitAIModule
    //         005041ae     NOP
    //         005041af     NOP
    return 0;
}

TribeElephantUnitAIModule::~TribeElephantUnitAIModule() {
    /* TODO: Stub */
    //                              void __thiscall ~TribeElephantUnitAIModule(TribeElephantUnitAIModule
    //              void              <VOID>         <RETURN>
    //              TribeElephantU    ECX:4 (auto)   this
    //                               ??1TribeElephantUnitAIModule@@UAE@XZ                         XREF[1]:     `vector_deleting_destructor':00504
    //                               TribeElephantUnitAIModule::~TribeElephantUnitAIModule
    //         005041b0     JMP        UnitAIModule::~UnitAIModule
    //         005041b5     ??         90h
    //         005041b6     NOP
    //         005041b7     NOP
    //         005041b8     NOP
    //         005041b9     NOP
    //         005041ba     NOP
    //         005041bb     NOP
    //         005041bc     NOP
    //         005041bd     NOP
    //         005041be     NOP
    //         005041bf     NOP
    //                              * protected: virtual int __thiscall TribeElephantUnitAIModule::processNotify(struct NotifyEvent *,un... *
    //                              int __thiscall processNotify(TribeElephantUnitAIModule * this, Notif
    //              int               EAX:4          <RETURN>
    //              TribeElephantU    ECX:4 (auto)   this
    //              NotifyEvent *     Stack[0x4]:4   param_1                   XREF[1]:     005041c0(R)  
    //              ulong             Stack[0x8]:4   param_2                   XREF[2]:     005041da(R), 00504201(R)  
    //                               ?processNotify@TribeElephantUnitAIModule@@MAEHPAUNotifyEven  XREF[1]:     00575a94(*)  
    //                               TribeElephantUnitAIModule::processNotify
    //                              taiuaimd.cpp:274 (26)
    //         005041c0     MOV        EAX,dword ptr [ESP + param_1]
    //         005041c4     PUSH       EBX
    //         005041c5     PUSH       EBP
    //         005041c6     PUSH       ESI
    //         005041c7     MOV        ESI,this
    //         005041c9     PUSH       EDI
    //         005041ca     MOV        this,dword ptr [EAX + 0x8]
    //         005041cd     SUB        this,0x1f4
    //         005041d3     JZ         LAB_005041fa
    //         005041d5     SUB        this,0x1b
    //         005041d8     JZ         LAB_005041ee
    //                              taiuaimd.cpp:316 (13)
    //         005041da     MOV        this,dword ptr [ESP + param_2]
    //         005041de     PUSH       this
    //         005041df     PUSH       EAX
    //         005041e0     MOV        this,ESI
    //         005041e2     CALL       UnitAIModule::processNotify                      int processNotify(UnitAIModule * this, Notify
    //                              taiuaimd.cpp:317 (7)
    //         005041e7     POP        EDI
    //         005041e8     POP        ESI
    //         005041e9     POP        EBP
    //         005041ea     POP        EBX
    //         005041eb     RET        0x8
    //                               LAB_005041ee                                                 XREF[1]:     005041d8(j)  
    //                              taiuaimd.cpp:287 (5)
    //         005041ee     MOV        EAX,0x2
    //                              taiuaimd.cpp:317 (7)
    //         005041f3     POP        EDI
    //         005041f4     POP        ESI
    //         005041f5     POP        EBP
    //         005041f6     POP        EBX
    //         005041f7     RET        0x8
    //                               LAB_005041fa                                                 XREF[1]:     005041d3(j)  
    //                              taiuaimd.cpp:295 (7)
    //         005041fa     MOV        this,dword ptr [EAX + 0x10]
    //         005041fd     TEST       this,this
    //         005041ff     JG         LAB_00504219
    //                              taiuaimd.cpp:299 (12)
    //         00504201     MOV        EDX,dword ptr [ESP + param_2]
    //         00504205     MOV        this,ESI
    //         00504207     PUSH       EDX
    //         00504208     CALL       UnitAIModule::purgeNotifyQueue                   void purgeNotifyQueue(UnitAIModule * this, ul
    //                              taiuaimd.cpp:300 (5)
    //         0050420d     MOV        EAX,0x4
    //                              taiuaimd.cpp:317 (7)
    //         00504212     POP        EDI
    //         00504213     POP        ESI
    //         00504214     POP        EBP
    //         00504215     POP        EBX
    //         00504216     RET        0x8
    //                               LAB_00504219                                                 XREF[1]:     005041ff(j)  
    //                              taiuaimd.cpp:303 (130)
    //         00504219     MOV        EBP,dword ptr [EAX]
    //         0050421b     MOV        this,dword ptr [ESI + 0x64]
    //         0050421e     XOR        EAX,EAX
    //         00504220     TEST       this,this
    //         00504222     JLE        LAB_00504238
    //         00504224     MOV        EDX,dword ptr [ESI + 0x6c]
    //                               LAB_00504227                                                 XREF[1]:     00504236(j)  
    //         00504227     CMP        EAX,EDX
    //         00504229     JGE        LAB_00504238
    //         0050422b     MOV        EDI,dword ptr [ESI + 0x60]
    //         0050422e     CMP        dword ptr [EDI + EAX*0x4],EBP
    //         00504231     JZ         LAB_0050429b
    //         00504233     INC        EAX
    //         00504234     CMP        EAX,this
    //         00504236     JL         LAB_00504227
    //                               LAB_00504238                                                 XREF[2]:     00504222(j), 00504229(j)  
    //         00504238     MOV        EAX,dword ptr [ESI + 0x6c]
    //         0050423b     DEC        EAX
    //         0050423c     CMP        this,EAX
    //         0050423e     JLE        LAB_0050428b
    //         00504240     LEA        EBX,[ECX + this->field1_0x1]
    //         00504243     LEA        this,[EBX*0x4 + 0x0]
    //         0050424a     PUSH       this
    //         0050424b     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00504250     MOV        EDI,EAX
    //         00504252     ADD        ESP,0x4
    //         00504255     TEST       EDI,EDI
    //         00504257     JZ         LAB_0050428b
    //         00504259     MOV        this,dword ptr [ESI + 0x6c]
    //         0050425c     XOR        EAX,EAX
    //         0050425e     TEST       this,this
    //         00504260     JLE        LAB_00504279
    //                               LAB_00504262                                                 XREF[1]:     00504277(j)  
    //         00504262     CMP        EAX,EBX
    //         00504264     JGE        LAB_00504279
    //         00504266     MOV        EDX,dword ptr [ESI + 0x60]
    //         00504269     INC        EAX
    //         0050426a     MOV        this,dword ptr [EDX + EAX*0x4 + -0x4]
    //         0050426e     MOV        dword ptr [EDI + EAX*0x4 + -0x4],this
    //         00504272     MOV        this,dword ptr [ESI + 0x6c]
    //         00504275     CMP        EAX,this
    //         00504277     JL         LAB_00504262
    //                               LAB_00504279                                                 XREF[2]:     00504260(j), 00504264(j)  
    //         00504279     MOV        EDX,dword ptr [ESI + 0x60]
    //         0050427c     PUSH       EDX
    //         0050427d     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00504282     ADD        ESP,0x4
    //         00504285     MOV        dword ptr [ESI + 0x60],EDI
    //         00504288     MOV        dword ptr [ESI + 0x6c],EBX
    //                               LAB_0050428b                                                 XREF[2]:     0050423e(j), 00504257(j)  
    //         0050428b     MOV        EAX,dword ptr [ESI + 0x64]
    //         0050428e     MOV        this,dword ptr [ESI + 0x60]
    //         00504291     MOV        dword ptr [this->field0_0x0 + EAX*0x4],EBP
    //         00504294     MOV        EAX,dword ptr [ESI + 0x64]
    //         00504297     INC        EAX
    //         00504298     MOV        dword ptr [ESI + 0x64],EAX
    //                               LAB_0050429b                                                 XREF[1]:     00504231(j)  
    //                              taiuaimd.cpp:304 (13)
    //         0050429b     MOV        this,dword ptr [ESI + 0x4]
    //         0050429e     PUSH       0x1
    //         005042a0     MOV        EDX,dword ptr [this->field0_0x0]
    //         005042a2     CALL       dword ptr [EDX + 0xec]
    //                              taiuaimd.cpp:306 (9)
    //         005042a8     MOV        EDI,dword ptr [ESI]
    //         005042aa     PUSH       0x0
    //         005042ac     MOV        this,ESI
    //         005042ae     CALL       dword ptr [EDI + 0x3c]
    //                              taiuaimd.cpp:312 (8)
    //         005042b1     PUSH       0x0
    //         005042b3     PUSH       EAX=>DAT_fffffff8
    //         005042b4     MOV        this,ESI
    //         005042b6     CALL       dword ptr [EDI + 0x5c]
    //                              taiuaimd.cpp:317 (12)
    //         005042b9     POP        EDI
    //         005042ba     POP        ESI
    //         005042bb     POP        EBP
    //         005042bc     MOV        EAX,0x3
    //         005042c1     POP        EBX
    //         005042c2     RET        0x8
    //         005042c5     ??         90h
    //         005042c6     NOP
    //         005042c7     NOP
    //         005042c8     NOP
    //         005042c9     NOP
    //         005042ca     NOP
    //         005042cb     NOP
    //         005042cc     NOP
    //         005042cd     NOP
    //         005042ce     NOP
    //         005042cf     NOP
}

int TribeElephantUnitAIModule::processIdle(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall processIdle(TribeElephantUnitAIModule * this, int par
    //              int               EAX:4          <RETURN>
    //              TribeElephantU    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //                               ?processIdle@TribeElephantUnitAIModule@@MAEHH@Z              XREF[1]:     00575a9c(*)  
    //                               TribeElephantUnitAIModule::processIdle
    //                              taiuaimd.cpp:322 (5)
    //         005042d0     MOV        EAX,0x5
    //                              taiuaimd.cpp:325 (3)
    //         005042d5     RET        0x4
    //         005042d8     ??         90h
    //         005042d9     NOP
    //         005042da     NOP
    //         005042db     NOP
    //         005042dc     NOP
    //         005042dd     NOP
    //         005042de     NOP
    //         005042df     NOP
    return 0;
}

TribeLionUnitAIModule::TribeLionUnitAIModule(RGE_Static_Object* param_1, int param_2) {
    /* TODO: Stub */
    //                              undefined __thiscall TribeLionUnitAIModule(TribeLionUnitAIModule * t
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TribeLionUnitA    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     005042fe(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     005042f6(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00504310(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00504425(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00504302(W)  
    //                               ??0TribeLionUnitAIModule@@QAE@PAVRGE_Static_Object@@H@Z      XREF[1]:     initUnitAI:004cbad1(c)  
    //                               TribeLionUnitAIModule::TribeLionUnitAIModule
    //                              taiuaimd.cpp:333 (46)
    //         005042e0     PUSH       -0x1
    //         005042e2     PUSH       FUN_00560c48
    //         005042e7     MOV        EAX,FS:[0x0]
    //         005042ed     PUSH       EAX
    //         005042ee     MOV        dword ptr FS:[0x0],ESP
    //         005042f5     PUSH       this
    //         005042f6     MOV        EAX,dword ptr [ESP + param_2]
    //         005042fa     PUSH       ESI
    //         005042fb     MOV        ESI,this
    //         005042fd     PUSH       EAX
    //         005042fe     MOV        this,dword ptr [ESP + param_1]
    //         00504302     MOV        dword ptr [ESP + local_10],ESI
    //         00504306     PUSH       this
    //         00504307     MOV        this,ESI
    //         00504309     CALL       UnitAIModule::UnitAIModule                       undefined UnitAIModule(UnitAIModule * this, R
    //                              taiuaimd.cpp:338 (40)
    //         0050430e     PUSH       0x44
    //         00504310     MOV        dword ptr [ESP + local_4],0x0
    //         00504318     MOV        dword ptr [ESI],TribeLionUnitAIModule::`vftable' = 00504440
    //         0050431e     MOV        dword ptr [ESI + 0x128],0x11
    //         00504328     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0050432d     ADD        ESP,0x4
    //         00504330     MOV        dword ptr [ESI + 0x124],EAX
    //                              taiuaimd.cpp:339 (8)
    //         00504336     TEST       EAX,EAX
    //         00504338     JZ         LAB_00504414
    //                              taiuaimd.cpp:340 (6)
    //         0050433e     MOV        dword ptr [EAX],0x1d
    //                              taiuaimd.cpp:341 (13)
    //         00504344     MOV        EDX,dword ptr [ESI + 0x124]
    //         0050434a     MOV        dword ptr [EDX + 0x4],0x9
    //                              taiuaimd.cpp:342 (13)
    //         00504351     MOV        EAX,dword ptr [ESI + 0x124]
    //         00504357     MOV        dword ptr [EAX + 0x8],0x0
    //                              taiuaimd.cpp:343 (13)
    //         0050435e     MOV        this,dword ptr [ESI + 0x124]
    //         00504364     MOV        dword ptr [ECX + this->field12_0xc],0x4
    //                              taiuaimd.cpp:344 (13)
    //         0050436b     MOV        EDX,dword ptr [ESI + 0x124]
    //         00504371     MOV        dword ptr [EDX + 0x10],0x1a
    //                              taiuaimd.cpp:345 (13)
    //         00504378     MOV        EAX,dword ptr [ESI + 0x124]
    //         0050437e     MOV        dword ptr [EAX + 0x14],0x18
    //                              taiuaimd.cpp:346 (13)
    //         00504385     MOV        this,dword ptr [ESI + 0x124]
    //         0050438b     MOV        dword ptr [ECX + this->field24_0x18],0x6
    //                              taiuaimd.cpp:347 (13)
    //         00504392     MOV        EDX,dword ptr [ESI + 0x124]
    //         00504398     MOV        dword ptr [EDX + 0x1c],0x19
    //                              taiuaimd.cpp:348 (13)
    //         0050439f     MOV        EAX,dword ptr [ESI + 0x124]
    //         005043a5     MOV        dword ptr [EAX + 0x20],0x11
    //                              taiuaimd.cpp:349 (13)
    //         005043ac     MOV        this,dword ptr [ESI + 0x124]
    //         005043b2     MOV        dword ptr [ECX + this->field36_0x24],0xd
    //                              taiuaimd.cpp:350 (13)
    //         005043b9     MOV        EDX,dword ptr [ESI + 0x124]
    //         005043bf     MOV        dword ptr [EDX + 0x28],0xc
    //                              taiuaimd.cpp:351 (13)
    //         005043c6     MOV        EAX,dword ptr [ESI + 0x124]
    //         005043cc     MOV        dword ptr [EAX + 0x2c],0x23
    //                              taiuaimd.cpp:352 (13)
    //         005043d3     MOV        this,dword ptr [ESI + 0x124]
    //         005043d9     MOV        dword ptr [ECX + this->field48_0x30],0x17
    //                              taiuaimd.cpp:353 (13)
    //         005043e0     MOV        EDX,dword ptr [ESI + 0x124]
    //         005043e6     MOV        dword ptr [EDX + 0x34],0x24
    //                              taiuaimd.cpp:354 (13)
    //         005043ed     MOV        EAX,dword ptr [ESI + 0x124]
    //         005043f3     MOV        dword ptr [EAX + 0x38],0x1c
    //                              taiuaimd.cpp:355 (13)
    //         005043fa     MOV        this,dword ptr [ESI + 0x124]
    //         00504400     MOV        dword ptr [ECX + this->field60_0x3c],0x12
    //                              taiuaimd.cpp:356 (13)
    //         00504407     MOV        EDX,dword ptr [ESI + 0x124]
    //         0050440d     MOV        dword ptr [EDX + 0x40],0x27
    //                               LAB_00504414                                                 XREF[1]:     00504338(j)  
    //                              taiuaimd.cpp:360 (17)
    //         00504414     MOV        this,ESI
    //         00504416     MOV        dword ptr [ESI + 0x100],0x1770
    //         00504420     CALL       UnitAIModule::setAdjustedIdleTimeout             void setAdjustedIdleTimeout(UnitAIModule * th
    //                              taiuaimd.cpp:361 (20)
    //         00504425     MOV        this,dword ptr [ESP + local_c]
    //         00504429     MOV        EAX,ESI
    //         0050442b     MOV        dword ptr FS:[0x0],this
    //         00504432     POP        ESI
    //         00504433     ADD        ESP,0x10
    //         00504436     RET        0x8
    //         00504439     ??         90h
    //         0050443a     NOP
    //         0050443b     NOP
    //         0050443c     NOP
    //         0050443d     NOP
    //         0050443e     NOP
    //         0050443f     NOP
}

int TribeLionUnitAIModule::canAttackUnitAtNeutrality(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall canAttackUnitAtNeutrality(TribeLionUnitAIModule * thi
    //              int               EAX:4          <RETURN>
    //              TribeLionUnitA    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //                               ?canAttackUnitAtNeutrality@TribeLionUnitAIModule@@UAEHH@Z    XREF[1]:     00575afc(*)  
    //                               TribeLionUnitAIModule::canAttackUnitAtNeutrality
    //                              taiuaimd.cpp:366 (5)
    //         00504470     MOV        EAX,0x1
    //                              taiuaimd.cpp:369 (3)
    //         00504475     RET        0x4
    //         00504478     ??         90h
    //         00504479     NOP
    //         0050447a     NOP
    //         0050447b     NOP
    //         0050447c     NOP
    //         0050447d     NOP
    //         0050447e     NOP
    //         0050447f     NOP
    //                              * protected: virtual int __thiscall TribeLionUnitAIModule::processNotify(struct NotifyEvent *,unsign... *
    //                              int __thiscall processNotify(TribeLionUnitAIModule * this, NotifyEve
    //              int               EAX:4          <RETURN>
    //              TribeLionUnitA    ECX:4 (auto)   this
    //              NotifyEvent *     Stack[0x4]:4   param_1                   XREF[1]:     00504481(R)  
    //              ulong             Stack[0x8]:4   param_2                   XREF[1]:     005045ea(R)  
    //                               ?processNotify@TribeLionUnitAIModule@@MAEHPAUNotifyEvent@@K@Z XREF[1]:     00575b74(*)  
    //                               TribeLionUnitAIModule::processNotify
    //                              taiuaimd.cpp:375 (1)
    //         00504480     PUSH       EBX
    //                              taiuaimd.cpp:380 (31)
    //         00504481     MOV        EBX,dword ptr [ESP + param_1]
    //         00504485     PUSH       ESI
    //         00504486     PUSH       EDI
    //         00504487     MOV        EAX,dword ptr [EBX + 0x8]
    //         0050448a     MOV        ESI,this
    //         0050448c     SUB        EAX,0x1fa
    //         00504491     JZ         LAB_00504542
    //         00504497     SUB        EAX,0x2
    //         0050449a     JNZ        LAB_005045ea
    //                              taiuaimd.cpp:408 (18)
    //         005044a0     MOV        this,dword ptr [ESI + 0x4]
    //         005044a3     MOV        EAX,dword ptr [ESI + 0x34]
    //         005044a6     PUSH       EAX
    //         005044a7     MOV        EDX,dword ptr [ECX + this->field12_0xc]
    //         005044aa     MOV        this,dword ptr [EDX + 0x3c]
    //         005044ad     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //                              taiuaimd.cpp:414 (4)
    //         005044b2     TEST       EAX,EAX
    //         005044b4     JZ         LAB_005044e7
    //                              taiuaimd.cpp:415 (25)
    //         005044b6     MOV        this,dword ptr [ESI + 0x4]
    //         005044b9     PUSH       EAX
    //         005044ba     CALL       RGE_Static_Object::distance_to_object            float distance_to_object(RGE_Static_Object * 
    //         005044bf     MOV        EAX,dword ptr [ESI + 0x4]
    //         005044c2     MOV        this,dword ptr [EAX + 0x8]
    //         005044c5     FCOMP      float ptr [ECX + this->field40_0x28]
    //         005044c8     FNSTSW     AX
    //         005044ca     TEST       AH,0x41
    //         005044cd     JZ         LAB_005044e7
    //                              taiuaimd.cpp:419 (13)
    //         005044cf     MOV        EAX,dword ptr [ESI + 0x34]
    //         005044d2     MOV        EDX,dword ptr [ESI]
    //         005044d4     PUSH       0x1
    //         005044d6     PUSH       EAX
    //         005044d7     MOV        this,ESI
    //         005044d9     CALL       dword ptr [EDX + 0x5c]
    //                              taiuaimd.cpp:420 (5)
    //         005044dc     MOV        EAX,0x3
    //                              taiuaimd.cpp:436 (6)
    //         005044e1     POP        EDI
    //         005044e2     POP        ESI
    //         005044e3     POP        EBX
    //         005044e4     RET        0x8
    //                               LAB_005044e7                                                 XREF[2]:     005044b4(j), 005044cd(j)  
    //                              taiuaimd.cpp:426 (7)
    //         005044e7     MOV        this,ESI
    //         005044e9     CALL       UnitAIModule::removeCurrentTarget                void removeCurrentTarget(UnitAIModule * this)
    //                              taiuaimd.cpp:428 (50)
    //         005044ee     MOV        this,dword ptr [actionFile]                      = 00000000
    //         005044f4     TEST       this,this
    //         005044f6     JZ         LAB_00504520
    //         005044f8     MOV        EAX,dword ptr [ESI + 0x4]
    //         005044fb     TEST       EAX,EAX
    //         005044fd     JZ         LAB_00504504
    //         005044ff     MOV        EAX,dword ptr [EAX + 0x4]
    //         00504502     JMP        LAB_00504507
    //                               LAB_00504504                                                 XREF[1]:     005044fd(j)  
    //         00504504     OR         EAX,0xffffffff
    //                               LAB_00504507                                                 XREF[1]:     00504502(j)  
    //         00504507     PUSH       0x1ac
    //         0050450c     PUSH       s_C:\msdev\work\age1_x1\taiuaimd.c               = "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp"
    //         00504511     PUSH       EAX
    //         00504512     PUSH       s_#%d_call_stopObject_%s_%d_                     = "#%d call stopObject %s %d\n"
    //         00504517     PUSH       this
    //         00504518     CALL       fprintf                                          undefined fprintf()
    //         0050451d     ADD        ESP,0x14
    //                               LAB_00504520                                                 XREF[1]:     005044f6(j)  
    //                              taiuaimd.cpp:430 (9)
    //         00504520     MOV        EDI,dword ptr [ESI]
    //         00504522     PUSH       0x1
    //         00504524     MOV        this,ESI
    //         00504526     CALL       dword ptr [EDI + 0x58]
    //                              taiuaimd.cpp:431 (6)
    //         00504529     PUSH       EBX
    //         0050452a     MOV        this,ESI
    //         0050452c     CALL       dword ptr [EDI + 0x1c]
    //                              taiuaimd.cpp:435 (13)
    //         0050452f     MOV        EAX,dword ptr [ESP + 0x14]
    //         00504533     MOV        this,ESI
    //         00504535     PUSH       EAX
    //         00504536     PUSH       EBX=>DAT_fffffff8
    //         00504537     CALL       UnitAIModule::processNotify                      int processNotify(UnitAIModule * this, Notify
    //                              taiuaimd.cpp:436 (6)
    //         0050453c     POP        EDI
    //         0050453d     POP        ESI
    //         0050453e     POP        EBX
    //         0050453f     RET        0x8
    //                               LAB_00504542                                                 XREF[1]:     00504491(j)  
    //                              taiuaimd.cpp:388 (13)
    //         00504542     CMP        dword ptr [EBX + 0xc],0x258
    //         00504549     JNZ        LAB_005045ea
    //                              taiuaimd.cpp:392 (32)
    //         0050454f     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00504555     CALL       RGE_Base_Game::scenarioGame                      int scenarioGame(RGE_Base_Game * this)
    //         0050455a     CMP        EAX,0x1
    //         0050455d     JNZ        LAB_00504597
    //         0050455f     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00504565     CALL       RGE_Base_Game::singlePlayerGame                  int singlePlayerGame(RGE_Base_Game * this)
    //         0050456a     CMP        EAX,0x1
    //         0050456d     JNZ        LAB_00504597
    //                              taiuaimd.cpp:393 (14)
    //         0050456f     MOV        this,dword ptr [ESI + 0x4]
    //         00504572     MOV        EDX,dword ptr [ECX + this->field12_0xc]
    //         00504575     MOV        this,dword ptr [EDX + 0x3c]
    //         00504578     CALL       RGE_Game_World::difficultyLevel                  int difficultyLevel(RGE_Game_World * this)
    //                              taiuaimd.cpp:394 (24)
    //         0050457d     ADD        EAX,0x3
    //         00504580     LEA        EAX,[EAX + EAX*0x4]
    //         00504583     LEA        EAX,[EAX + EAX*0x4]
    //         00504586     LEA        EAX,[EAX + EAX*0x4]
    //         00504589     LEA        EAX,[EAX + EAX*0x4]
    //         0050458c     SHL        EAX,0x3
    //         0050458f     MOV        dword ptr [ESI + 0x100],EAX
    //                              taiuaimd.cpp:396 (2)
    //         00504595     JMP        LAB_005045a1
    //                               LAB_00504597                                                 XREF[2]:     0050455d(j), 0050456d(j)  
    //                              taiuaimd.cpp:397 (10)
    //         00504597     MOV        dword ptr [ESI + 0x100],0x61a8
    //                               LAB_005045a1                                                 XREF[1]:     00504595(j)  
    //                              taiuaimd.cpp:398 (7)
    //         005045a1     MOV        this,ESI
    //         005045a3     CALL       UnitAIModule::setAdjustedIdleTimeout             void setAdjustedIdleTimeout(UnitAIModule * th
    //                              taiuaimd.cpp:399 (7)
    //         005045a8     MOV        this,ESI
    //         005045aa     CALL       UnitAIModule::removeCurrentTarget                void removeCurrentTarget(UnitAIModule * this)
    //                              taiuaimd.cpp:401 (50)
    //         005045af     MOV        this,dword ptr [actionFile]                      = 00000000
    //         005045b5     TEST       this,this
    //         005045b7     JZ         LAB_005045e1
    //         005045b9     MOV        EAX,dword ptr [ESI + 0x4]
    //         005045bc     TEST       EAX,EAX
    //         005045be     JZ         LAB_005045c5
    //         005045c0     MOV        EAX,dword ptr [EAX + 0x4]
    //         005045c3     JMP        LAB_005045c8
    //                               LAB_005045c5                                                 XREF[1]:     005045be(j)  
    //         005045c5     OR         EAX,0xffffffff
    //                               LAB_005045c8                                                 XREF[1]:     005045c3(j)  
    //         005045c8     PUSH       0x191
    //         005045cd     PUSH       s_C:\msdev\work\age1_x1\taiuaimd.c               = "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp"
    //         005045d2     PUSH       EAX
    //         005045d3     PUSH       s_#%d_call_stopObject_%s_%d_                     = "#%d call stopObject %s %d\n"
    //         005045d8     PUSH       this
    //         005045d9     CALL       fprintf                                          undefined fprintf()
    //         005045de     ADD        ESP,0x14
    //                               LAB_005045e1                                                 XREF[1]:     005045b7(j)  
    //                              taiuaimd.cpp:403 (9)
    //         005045e1     MOV        EDX,dword ptr [ESI]
    //         005045e3     PUSH       0x1
    //         005045e5     MOV        this,ESI
    //         005045e7     CALL       dword ptr [EDX + 0x58]
    //                               LAB_005045ea                                                 XREF[2]:     0050449a(j), 00504549(j)  
    //                              taiuaimd.cpp:435 (13)
    //         005045ea     MOV        EAX,dword ptr [ESP + param_2]
    //         005045ee     MOV        this,ESI
    //         005045f0     PUSH       EAX
    //         005045f1     PUSH       EBX=>DAT_fffffff8
    //         005045f2     CALL       UnitAIModule::processNotify                      int processNotify(UnitAIModule * this, Notify
    //                              taiuaimd.cpp:436 (6)
    //         005045f7     POP        EDI
    //         005045f8     POP        ESI
    //         005045f9     POP        EBX
    //         005045fa     RET        0x8
    //         005045fd     ??         90h
    //         005045fe     NOP
    //         005045ff     NOP
    return 0;
}

int TribeLionUnitAIModule::processIdle(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall processIdle(TribeLionUnitAIModule * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              TribeLionUnitA    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //              RGE_Static_Obj    Stack[-0x8]:4  newTarget
    //              float             Stack[-0xc]:4  maxReactDistance
    //                               ?processIdle@TribeLionUnitAIModule@@MAEHH@Z                  XREF[1]:     00575b7c(*)  
    //                               TribeLionUnitAIModule::processIdle
    //                              taiuaimd.cpp:441 (9)
    //         00504600     SUB        ESP,0x8
    //         00504603     PUSH       EBX
    //         00504604     PUSH       EBP
    //         00504605     PUSH       ESI
    //         00504606     MOV        ESI,this
    //         00504608     PUSH       EDI
    //                              taiuaimd.cpp:447 (10)
    //         00504609     MOV        dword ptr [ESI + 0x100],0x1770
    //                              taiuaimd.cpp:448 (5)
    //         00504613     CALL       UnitAIModule::setAdjustedIdleTimeout             void setAdjustedIdleTimeout(UnitAIModule * th
    //                              taiuaimd.cpp:451 (19)
    //         00504618     MOV        EBX,dword ptr [ESI]
    //         0050461a     PUSH       0x0
    //         0050461c     PUSH       -0x1
    //         0050461e     PUSH       -0x1
    //         00504620     PUSH       -0x1
    //         00504622     PUSH       -0x1
    //         00504624     MOV        this,ESI
    //         00504626     CALL       dword ptr [EBX + 0x40]
    //         00504629     MOV        EDI,EAX
    //                              taiuaimd.cpp:455 (8)
    //         0050462b     MOV        this,ESI
    //         0050462d     PUSH       EDI
    //         0050462e     CALL       UnitAIModule::lookupObject                       RGE_Static_Object * lookupObject(UnitAIModule
    //                              taiuaimd.cpp:456 (21)
    //         00504633     CMP        EDI,-0x1
    //         00504636     MOV        dword ptr [ESP + 0x14],EAX
    //         0050463a     JZ         LAB_005046ec
    //         00504640     TEST       EAX,EAX
    //         00504642     JZ         LAB_005046ec
    //                              taiuaimd.cpp:460 (14)
    //         00504648     MOV        EAX,dword ptr [ESI + 0x4]
    //         0050464b     MOV        this,dword ptr [EAX + 0xc]
    //         0050464e     MOV        this,dword ptr [ECX + this->field60_0x3c]
    //         00504651     CALL       RGE_Game_World::difficultyLevel                  int difficultyLevel(RGE_Game_World * this)
    //                              taiuaimd.cpp:463 (39)
    //         00504656     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0050465c     MOV        EBP,EAX
    //         0050465e     CALL       RGE_Base_Game::scenarioGame                      int scenarioGame(RGE_Base_Game * this)
    //         00504663     CMP        EAX,0x1
    //         00504666     JNZ        LAB_005046b1
    //         00504668     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0050466e     CALL       RGE_Base_Game::singlePlayerGame                  int singlePlayerGame(RGE_Base_Game * this)
    //         00504673     CMP        EAX,0x1
    //         00504676     JNZ        LAB_005046b1
    //         00504678     CMP        EBP,0x3
    //         0050467b     JL         LAB_005046b1
    //                              taiuaimd.cpp:468 (2)
    //         0050467d     JNZ        LAB_00504687
    //                              taiuaimd.cpp:469 (6)
    //         0050467f     FLD        float ptr [DAT_005758b4]
    //                              taiuaimd.cpp:470 (2)
    //         00504685     JMP        LAB_0050468d
    //                               LAB_00504687                                                 XREF[1]:     0050467d(j)  
    //                              taiuaimd.cpp:471 (6)
    //         00504687     FLD        float ptr [DAT_005758b8]
    //                               LAB_0050468d                                                 XREF[1]:     00504685(j)  
    //                              taiuaimd.cpp:479 (13)
    //         0050468d     MOV        this,dword ptr [ESI + 0x4]
    //         00504690     MOV        EDX,dword ptr [ECX + this->field8_0x8]
    //         00504693     FMUL       float ptr [EDX + 0x28]
    //         00504696     FST        float ptr [ESP + 0x10]
    //                              taiuaimd.cpp:480 (13)
    //         0050469a     FCOMP      float ptr [DAT_005758bc]
    //         005046a0     FNSTSW     AX
    //         005046a2     TEST       AH,0x1
    //         005046a5     JZ         LAB_005046c0
    //                              taiuaimd.cpp:484 (8)
    //         005046a7     MOV        dword ptr [ESP + 0x10],0x3f800000
    //                              taiuaimd.cpp:492 (2)
    //         005046af     JMP        LAB_005046c0
    //                               LAB_005046b1                                                 XREF[3]:     00504666(j), 00504676(j), 
    //                                                                                                         0050467b(j)  
    //                              taiuaimd.cpp:496 (15)
    //         005046b1     MOV        this,dword ptr [ESI + 0x4]
    //         005046b4     MOV        EAX,dword ptr [ECX + this->field8_0x8]
    //         005046b7     FLD        float ptr [EAX + 0x28]
    //         005046ba     FADD       ST0,ST0
    //         005046bc     FSTP       float ptr [ESP + 0x10]
    //                               LAB_005046c0                                                 XREF[2]:     005046a5(j), 005046af(j)  
    //                              taiuaimd.cpp:500 (19)
    //         005046c0     MOV        EDX,dword ptr [ESP + 0x14]
    //         005046c4     PUSH       EDX
    //         005046c5     CALL       RGE_Static_Object::distance_to_object            float distance_to_object(RGE_Static_Object * 
    //         005046ca     FCOMP      float ptr [ESP + 0x10]
    //         005046ce     FNSTSW     AX
    //         005046d0     TEST       AH,0x41
    //                              taiuaimd.cpp:504 (2)
    //         005046d3     JZ         LAB_005046ec
    //                              taiuaimd.cpp:510 (8)
    //         005046d5     PUSH       0x0
    //         005046d7     PUSH       EDI=>DAT_fffffff8
    //         005046d8     MOV        this,ESI
    //         005046da     CALL       dword ptr [EBX + 0x5c]
    //                              taiuaimd.cpp:511 (5)
    //         005046dd     MOV        EAX,0x6
    //                              taiuaimd.cpp:515 (25)
    //         005046e2     POP        EDI
    //         005046e3     POP        ESI
    //         005046e4     POP        EBP
    //         005046e5     POP        EBX
    //         005046e6     ADD        ESP,0x8
    //         005046e9     RET        0x4
    //                               LAB_005046ec                                                 XREF[3]:     0050463a(j), 00504642(j), 
    //                                                                                                         005046d3(j)  
    //         005046ec     POP        EDI
    //         005046ed     POP        ESI
    //         005046ee     POP        EBP
    //         005046ef     MOV        EAX,0x5
    //         005046f4     POP        EBX
    //         005046f5     ADD        ESP,0x8
    //         005046f8     RET        0x4
    //         005046fb     ??         90h
    //         005046fc     NOP
    //         005046fd     NOP
    //         005046fe     NOP
    //         005046ff     NOP
    return 0;
}

TribeRangedUnitAIModule::TribeRangedUnitAIModule(RGE_Static_Object* param_1, int param_2) {
    /* TODO: Stub */
    //                              undefined __thiscall TribeRangedUnitAIModule(TribeRangedUnitAIModule
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TribeRangedUni    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00504708(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     00504700(R)  
    //                               ??0TribeRangedUnitAIModule@@QAE@PAVRGE_Static_Object@@H@Z
    //                               TribeRangedUnitAIModule::TribeRangedUnitAIModule
    //                              taiuaimd.cpp:523 (26)
    //         00504700     MOV        EAX,dword ptr [ESP + param_2]
    //         00504704     PUSH       ESI
    //         00504705     MOV        ESI,this
    //         00504707     PUSH       EAX
    //         00504708     MOV        this,dword ptr [ESP + param_1]
    //         0050470c     PUSH       this
    //         0050470d     MOV        this,ESI
    //         0050470f     CALL       UnitAIModule::UnitAIModule                       undefined UnitAIModule(UnitAIModule * this, R
    //         00504714     MOV        dword ptr [ESI],TribeRangedUnitAIModule::`vfta   = 00504720
    //                              taiuaimd.cpp:524 (6)
    //         0050471a     MOV        EAX,ESI
    //         0050471c     POP        ESI
    //         0050471d     RET        0x8
}

TribeRangedUnitAIModule::~TribeRangedUnitAIModule() {
    /* TODO: Stub */
    //                              void __thiscall ~TribeRangedUnitAIModule(TribeRangedUnitAIModule * t
    //              void              <VOID>         <RETURN>
    //              TribeRangedUni    ECX:4 (auto)   this
    //                               ??1TribeRangedUnitAIModule@@UAE@XZ                           XREF[1]:     `vector_deleting_destructor':00504
    //                               TribeRangedUnitAIModule::~TribeRangedUnitAIModule
    //         00504740     JMP        UnitAIModule::~UnitAIModule
    //         00504745     ??         90h
    //         00504746     NOP
    //         00504747     NOP
    //         00504748     NOP
    //         00504749     NOP
    //         0050474a     NOP
    //         0050474b     NOP
    //         0050474c     NOP
    //         0050474d     NOP
    //         0050474e     NOP
    //         0050474f     NOP
    //                              * protected: virtual int __thiscall TribeRangedUnitAIModule::processNotify(struct NotifyEvent *,unsi... *
    //                              int __thiscall processNotify(TribeRangedUnitAIModule * this, NotifyE
    //              int               EAX:4          <RETURN>
    //              TribeRangedUni    ECX:4 (auto)   this
    //              NotifyEvent *     Stack[0x4]:4   param_1                   XREF[1]:     00504750(R)  
    //              ulong             Stack[0x8]:4   param_2                   XREF[1]:     00504763(R)  
    //                               ?processNotify@TribeRangedUnitAIModule@@MAEHPAUNotifyEvent@  XREF[1]:     00575c54(*)  
    //                               TribeRangedUnitAIModule::processNotify
    //                              taiuaimd.cpp:529 (19)
    //         00504750     MOV        EAX,dword ptr [ESP + param_1]
    //         00504754     PUSH       EBX
    //         00504755     PUSH       EBP
    //         00504756     PUSH       ESI
    //         00504757     MOV        ESI,this
    //         00504759     PUSH       EDI
    //         0050475a     CMP        dword ptr [EAX + 0x8],0x200
    //         00504761     JZ         LAB_00504777
    //                              taiuaimd.cpp:585 (13)
    //         00504763     MOV        this,dword ptr [ESP + param_2]
    //         00504767     PUSH       this
    //         00504768     PUSH       EAX
    //         00504769     MOV        this,ESI
    //         0050476b     CALL       UnitAIModule::processNotify                      int processNotify(UnitAIModule * this, Notify
    //                              taiuaimd.cpp:586 (7)
    //         00504770     POP        EDI
    //         00504771     POP        ESI
    //         00504772     POP        EBP
    //         00504773     POP        EBX
    //         00504774     RET        0x8
    //                               LAB_00504777                                                 XREF[1]:     00504761(j)  
    //                              taiuaimd.cpp:546 (13)
    //         00504777     CMP        dword ptr [ESI + 0x30],0x258
    //         0050477e     JNZ        LAB_0050486a
    //                              taiuaimd.cpp:550 (20)
    //         00504784     MOV        EAX,dword ptr [ESI + 0x4]
    //         00504787     MOV        EDX,dword ptr [ESI + 0x34]
    //         0050478a     PUSH       EDX
    //         0050478b     MOV        this,dword ptr [EAX + 0xc]
    //         0050478e     MOV        this,dword ptr [ECX + this->field60_0x3c]
    //         00504791     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //         00504796     MOV        EBX,EAX
    //                              taiuaimd.cpp:552 (35)
    //         00504798     TEST       EBX,EBX
    //         0050479a     JZ         LAB_0050486a
    //         005047a0     MOV        EDX,dword ptr [EBX]
    //         005047a2     MOV        this,EBX
    //         005047a4     CALL       dword ptr [EDX + 0xf4]
    //         005047aa     FCOMP      float ptr [DAT_005758c4]
    //         005047b0     FNSTSW     AX
    //         005047b2     TEST       AH,0x40
    //         005047b5     JNZ        LAB_0050486a
    //                              taiuaimd.cpp:559 (49)
    //         005047bb     MOV        EAX,dword ptr [ESI + 0x2c]
    //         005047be     MOV        this,dword ptr [ESI + 0x48]
    //         005047c1     MOV        EDX,dword ptr [ESI + 0x44]
    //         005047c4     PUSH       EAX
    //         005047c5     MOV        EAX,dword ptr [ESI + 0x40]
    //         005047c8     PUSH       offset DAT_fffffff8
    //         005047ca     PUSH       0x0=>DAT_fffffff4
    //         005047cc     MOV        EBP,dword ptr [ESI]
    //         005047ce     PUSH       this=>DAT_fffffff0
    //         005047cf     MOV        this,dword ptr [ESI + 0x3c]
    //         005047d2     PUSH       EDX
    //         005047d3     MOV        EDX,dword ptr [ESI + 0x34]
    //         005047d6     PUSH       EAX
    //         005047d7     MOV        EAX,dword ptr [ESI + 0x4]
    //         005047da     PUSH       this
    //         005047db     PUSH       -0x1
    //         005047dd     MOV        this,dword ptr [EAX + 0x4]
    //         005047e0     PUSH       EDX
    //         005047e1     PUSH       0x2bc
    //         005047e6     PUSH       this
    //         005047e7     MOV        this,ESI
    //         005047e9     CALL       dword ptr [EBP + 0x10]
    //                              taiuaimd.cpp:564 (31)
    //         005047ec     MOV        EDI,dword ptr [ESI + 0x4]
    //         005047ef     MOV        this,EDI
    //         005047f1     MOV        EDX,dword ptr [EDI]
    //         005047f3     CALL       dword ptr [EDX + 0x100]
    //         005047f9     MOV        EAX,dword ptr [EDI]
    //         005047fb     MOV        this,EDI
    //         005047fd     FSTP       float ptr [ESP + 0x14]
    //         00504801     CALL       dword ptr [EAX + 0xfc]
    //         00504807     FMUL       float ptr [ESP + 0x14]
    //                              taiuaimd.cpp:568 (3)
    //         0050480b     MOV        EAX,dword ptr [ESI + 0x4]
    //                              taiuaimd.cpp:579 (80)
    //         0050480e     PUSH       0x1
    //         00504810     FMUL       float ptr [DAT_005758b0]                         = align(2)
    //         00504816     FLD        float ptr [EBX + 0x38]
    //         00504819     FSUB       float ptr [EAX + 0x38]
    //         0050481c     FLD        float ptr [EBX + 0x3c]
    //         0050481f     FSUB       float ptr [EAX + 0x3c]
    //         00504822     FLD        ST1
    //         00504824     FMUL       ST2
    //         00504826     FLD        ST1
    //         00504828     FMUL       ST2
    //         0050482a     MOV        this,dword ptr [EAX + 0x40]
    //         0050482d     PUSH       this=>DAT_fffffff8
    //         0050482e     PUSH       this=>DAT_fffffff4
    //         0050482f     FADDP
    //         00504831     FSQRT
    //         00504833     FSTP       float ptr [ESP + 0x20]
    //         00504837     FDIV       float ptr [ESP + 0x20]
    //         0050483b     FMUL       ST2
    //         0050483d     FCHS
    //         0050483f     FADD       float ptr [EAX + 0x3c]
    //         00504842     FSTP       float ptr [ESP]=>DAT_fffffff4
    //         00504845     PUSH       this=>DAT_fffffff0
    //         00504846     MOV        this,ESI
    //         00504848     FDIV       float ptr [ESP + 0x24]
    //         0050484c     FMUL       ST1
    //         0050484e     FCHS
    //         00504850     FADD       float ptr [EAX + 0x38]
    //         00504853     FSTP       float ptr [ESP]=>DAT_fffffff0
    //         00504856     FSTP       ST0
    //         00504858     CALL       dword ptr [EBP + 0x9c]
    //                              taiuaimd.cpp:581 (5)
    //         0050485e     MOV        EAX,0x3
    //                              taiuaimd.cpp:586 (19)
    //         00504863     POP        EDI
    //         00504864     POP        ESI
    //         00504865     POP        EBP
    //         00504866     POP        EBX
    //         00504867     RET        0x8
    //                               LAB_0050486a                                                 XREF[3]:     0050477e(j), 0050479a(j), 
    //                                                                                                         005047b5(j)  
    //         0050486a     POP        EDI
    //         0050486b     POP        ESI
    //         0050486c     POP        EBP
    //         0050486d     MOV        EAX,0x2
    //         00504872     POP        EBX
    //         00504873     RET        0x8
    //         00504876     ??         90h
    //         00504877     NOP
    //         00504878     NOP
    //         00504879     NOP
    //         0050487a     NOP
    //         0050487b     NOP
    //         0050487c     NOP
    //         0050487d     NOP
    //         0050487e     NOP
    //         0050487f     NOP
}

TribeRangedUnitAIModule2::TribeRangedUnitAIModule2(RGE_Static_Object* param_1, int param_2) {
    /* TODO: Stub */
    //                              undefined __thiscall TribeRangedUnitAIModule2(TribeRangedUnitAIModul
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TribeRangedUni    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00504888(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     00504880(R)  
    //                               ??0TribeRangedUnitAIModule2@@QAE@PAVRGE_Static_Object@@H@Z
    //                               TribeRangedUnitAIModule2::TribeRangedUnitAIModule2
    //                              taiuaimd.cpp:594 (26)
    //         00504880     MOV        EAX,dword ptr [ESP + param_2]
    //         00504884     PUSH       ESI
    //         00504885     MOV        ESI,this
    //         00504887     PUSH       EAX
    //         00504888     MOV        this,dword ptr [ESP + param_1]
    //         0050488c     PUSH       this
    //         0050488d     MOV        this,ESI
    //         0050488f     CALL       UnitAIModule::UnitAIModule                       undefined UnitAIModule(UnitAIModule * this, R
    //         00504894     MOV        dword ptr [ESI],TribeRangedUnitAIModule2::`vft   = 005048a0
    //                              taiuaimd.cpp:595 (6)
    //         0050489a     MOV        EAX,ESI
    //         0050489c     POP        ESI
    //         0050489d     RET        0x8
    //                              * public: virtual void * __thiscall TribeRangedUnitAIModule2::`vector deleting destructor'(unsigned ... *
    //                              void * __thiscall `vector_deleting_destructor'(TribeRangedUnitAIModu
    //              void *            EAX:4          <RETURN>
    //              TribeRangedUni    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     005048a8(R)  
    //                               ??_GTribeRangedUnitAIModule2@@UAEPAXI@Z                      XREF[1]:     00575c68(*)  
    //                               ??_ETribeRangedUnitAIModule2@@UAEPAXI@Z
    //                               TribeRangedUnitAIModule2::`vector_deleting_destructor'
    //         005048a0     PUSH       ESI
    //         005048a1     MOV        ESI,this
    //         005048a3     CALL       TribeRangedUnitAIModule2::~TribeRangedUnitAIMo   void ~TribeRangedUnitAIModule2(TribeRangedUni
    //         005048a8     TEST       byte ptr [ESP + param_1],0x1
    //         005048ad     JZ         LAB_005048b8
    //         005048af     PUSH       ESI
    //         005048b0     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         005048b5     ADD        ESP,0x4
    //                               LAB_005048b8                                                 XREF[1]:     005048ad(j)  
    //         005048b8     MOV        EAX,ESI
    //         005048ba     POP        ESI
    //         005048bb     RET        0x4
    //                              *                                            THUNK FUNCTION                                             *
    //                              thunk void __thiscall ~UnitAIModule(UnitAIModule * this)
    //                                Thunked-Function: UnitAIModule::~UnitAIMo
    //              void              <VOID>         <RETURN>
    //              UnitAIModule *    ECX:4 (auto)   this
    //                               UnitAIModule::~UnitAIModule
    //         005048be     NOP
    //         005048bf     NOP
}

TribeRangedUnitAIModule2::~TribeRangedUnitAIModule2() {
    /* TODO: Stub */
    //                              void __thiscall ~TribeRangedUnitAIModule2(TribeRangedUnitAIModule2 *
    //              void              <VOID>         <RETURN>
    //              TribeRangedUni    ECX:4 (auto)   this
    //                               ??1TribeRangedUnitAIModule2@@UAE@XZ                          XREF[1]:     `vector_deleting_destructor':00504
    //                               TribeRangedUnitAIModule2::~TribeRangedUnitAIModule2
    //         005048c0     JMP        UnitAIModule::~UnitAIModule
    //         005048c5     ??         90h
    //         005048c6     NOP
    //         005048c7     NOP
    //         005048c8     NOP
    //         005048c9     NOP
    //         005048ca     NOP
    //         005048cb     NOP
    //         005048cc     NOP
    //         005048cd     NOP
    //         005048ce     NOP
    //         005048cf     NOP
    //                              * protected: virtual int __thiscall TribeRangedUnitAIModule2::processNotify(struct NotifyEvent *,uns... *
    //                              int __thiscall processNotify(TribeRangedUnitAIModule2 * this, Notify
    //              int               EAX:4          <RETURN>
    //              TribeRangedUni    ECX:4 (auto)   this
    //              NotifyEvent *     Stack[0x4]:4   param_1                   XREF[1]:     005048d0(R)  
    //              ulong             Stack[0x8]:4   param_2                   XREF[1]:     005048e8(R)  
    //              float             Stack[-0xc]:4  evasiveMoveDistance
    //                               ?processNotify@TribeRangedUnitAIModule2@@MAEHPAUNotifyEvent  XREF[1]:     00575d34(*)  
    //                               TribeRangedUnitAIModule2::processNotify
    //                              taiuaimd.cpp:600 (24)
    //         005048d0     MOV        EAX,dword ptr [ESP + param_1]
    //         005048d4     SUB        ESP,0x8
    //         005048d7     PUSH       EBX
    //         005048d8     PUSH       EBP
    //         005048d9     PUSH       ESI
    //         005048da     MOV        ESI,this
    //         005048dc     MOV        this,dword ptr [EAX + 0x8]
    //         005048df     PUSH       EDI
    //         005048e0     CMP        this,0x200
    //         005048e6     JZ         LAB_005048ff
    //                              taiuaimd.cpp:677 (13)
    //         005048e8     MOV        this,dword ptr [ESP + param_2]
    //         005048ec     PUSH       this
    //         005048ed     PUSH       EAX
    //         005048ee     MOV        this,ESI
    //         005048f0     CALL       UnitAIModule::processNotify                      int processNotify(UnitAIModule * this, Notify
    //                              taiuaimd.cpp:678 (10)
    //         005048f5     POP        EDI
    //         005048f6     POP        ESI
    //         005048f7     POP        EBP
    //         005048f8     POP        EBX
    //         005048f9     ADD        ESP,0x8
    //         005048fc     RET        0x8
    //                               LAB_005048ff                                                 XREF[1]:     005048e6(j)  
    //                              taiuaimd.cpp:617 (13)
    //         005048ff     CMP        dword ptr [ESI + 0x30],0x258
    //         00504906     JNZ        LAB_00504b44
    //                              taiuaimd.cpp:621 (20)
    //         0050490c     MOV        EAX,dword ptr [ESI + 0x4]
    //         0050490f     MOV        EDX,dword ptr [ESI + 0x34]
    //         00504912     PUSH       EDX
    //         00504913     MOV        this,dword ptr [EAX + 0xc]
    //         00504916     MOV        this,dword ptr [ECX + this->field60_0x3c]
    //         00504919     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //         0050491e     MOV        EBX,EAX
    //                              taiuaimd.cpp:623 (35)
    //         00504920     TEST       EBX,EBX
    //         00504922     JZ         LAB_00504b44
    //         00504928     MOV        EDX,dword ptr [EBX]
    //         0050492a     MOV        this,EBX
    //         0050492c     CALL       dword ptr [EDX + 0xf4]
    //         00504932     FCOMP      float ptr [DAT_005758c4]
    //         00504938     FNSTSW     AX
    //         0050493a     TEST       AH,0x40
    //         0050493d     JNZ        LAB_00504b44
    //                              taiuaimd.cpp:630 (53)
    //         00504943     MOV        EAX,dword ptr [ESI + 0x2c]
    //         00504946     MOV        this,dword ptr [ESI + 0x48]
    //         00504949     MOV        EDX,dword ptr [ESI + 0x44]
    //         0050494c     PUSH       EAX
    //         0050494d     MOV        EAX,dword ptr [ESI + 0x40]
    //         00504950     PUSH       offset DAT_fffffff8
    //         00504952     PUSH       0x0=>DAT_fffffff4
    //         00504954     MOV        EBP,dword ptr [ESI]
    //         00504956     PUSH       this=>DAT_fffffff0
    //         00504957     MOV        this,dword ptr [ESI + 0x3c]
    //         0050495a     PUSH       EDX
    //         0050495b     MOV        EDX,dword ptr [ESI + 0x34]
    //         0050495e     PUSH       EAX
    //         0050495f     MOV        EAX,dword ptr [ESI + 0x4]
    //         00504962     PUSH       this
    //         00504963     PUSH       -0x1
    //         00504965     MOV        this,dword ptr [EAX + 0x4]
    //         00504968     PUSH       EDX
    //         00504969     PUSH       0x2bc
    //         0050496e     PUSH       this
    //         0050496f     MOV        this,ESI
    //         00504971     MOV        dword ptr [ESP + 0x40],EBP
    //         00504975     CALL       dword ptr [EBP + 0x10]
    //                              taiuaimd.cpp:635 (31)
    //         00504978     MOV        EDI,dword ptr [ESI + 0x4]
    //         0050497b     MOV        this,EDI
    //         0050497d     MOV        EDX,dword ptr [EDI]
    //         0050497f     CALL       dword ptr [EDX + 0x100]
    //         00504985     MOV        EAX,dword ptr [EDI]
    //         00504987     MOV        this,EDI
    //         00504989     FSTP       float ptr [ESP + 0x1c]
    //         0050498d     CALL       dword ptr [EAX + 0xfc]
    //         00504993     FMUL       float ptr [ESP + 0x1c]
    //                              taiuaimd.cpp:639 (23)
    //         00504997     MOV        EAX,dword ptr [ESI + 0x4]
    //         0050499a     FMUL       float ptr [DAT_005758b0]                         = align(2)
    //         005049a0     FSTP       float ptr [ESP + 0x10]
    //         005049a4     FLD        float ptr [EBX + 0x38]
    //         005049a7     FSUB       float ptr [EAX + 0x38]
    //         005049aa     FSTP       float ptr [ESP + 0x20]
    //                              taiuaimd.cpp:640 (6)
    //         005049ae     FLD        float ptr [EBX + 0x3c]
    //         005049b1     FSUB       float ptr [EAX + 0x3c]
    //                              taiuaimd.cpp:646 (15)
    //         005049b4     MOV        EAX,dword ptr [ESI + 0x64]
    //         005049b7     TEST       EAX,EAX
    //         005049b9     FSTP       float ptr [ESP + 0x1c]
    //         005049bd     JLE        LAB_00504ad4
    //                              taiuaimd.cpp:647 (10)
    //         005049c3     XOR        EBP,EBP
    //         005049c5     TEST       EAX,EAX
    //         005049c7     JLE        LAB_00504ad0
    //                               LAB_005049cd                                                 XREF[1]:     00504aca(j)  
    //                              taiuaimd.cpp:648 (100)
    //         005049cd     MOV        this,dword ptr [ESI + 0x6c]
    //         005049d0     DEC        this
    //         005049d1     CMP        EBP,this
    //         005049d3     JLE        LAB_00504a20
    //         005049d5     LEA        EDX,[EBP*0x4 + 0x4]
    //         005049dc     LEA        EBX,[EBP + 0x1]
    //         005049df     PUSH       EDX
    //         005049e0     CALL       operator_new                                     void * operator_new(uint param_1)
    //         005049e5     MOV        EDI,EAX
    //         005049e7     ADD        ESP,0x4
    //         005049ea     TEST       EDI,EDI
    //         005049ec     JZ         LAB_00504a20
    //         005049ee     MOV        this,dword ptr [ESI + 0x6c]
    //         005049f1     XOR        EAX,EAX
    //         005049f3     TEST       this,this
    //         005049f5     JLE        LAB_00504a0e
    //                               LAB_005049f7                                                 XREF[1]:     00504a0c(j)  
    //         005049f7     CMP        EAX,EBX
    //         005049f9     JGE        LAB_00504a0e
    //         005049fb     MOV        this,dword ptr [ESI + 0x60]
    //         005049fe     INC        EAX
    //         005049ff     MOV        EDX,dword ptr [this->field0_0x0 + EAX*0x4 + -0
    //         00504a03     MOV        dword ptr [EDI + EAX*0x4 + -0x4],EDX
    //         00504a07     MOV        this,dword ptr [ESI + 0x6c]
    //         00504a0a     CMP        EAX,this
    //         00504a0c     JL         LAB_005049f7
    //                               LAB_00504a0e                                                 XREF[2]:     005049f5(j), 005049f9(j)  
    //         00504a0e     MOV        EAX,dword ptr [ESI + 0x60]
    //         00504a11     PUSH       EAX
    //         00504a12     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00504a17     ADD        ESP,0x4
    //         00504a1a     MOV        dword ptr [ESI + 0x60],EDI
    //         00504a1d     MOV        dword ptr [ESI + 0x6c],EBX
    //                               LAB_00504a20                                                 XREF[2]:     005049d3(j), 005049ec(j)  
    //         00504a20     MOV        this,dword ptr [ESI + 0x60]
    //         00504a23     MOV        EAX,dword ptr [ESI + 0x34]
    //         00504a26     MOV        EDX,dword ptr [this->field0_0x0 + EBP*0x4]
    //         00504a29     CMP        EDX,EAX
    //         00504a2b     JZ         LAB_00504ac4
    //                              taiuaimd.cpp:650 (104)
    //         00504a31     MOV        EAX,dword ptr [ESI + 0x6c]
    //         00504a34     DEC        EAX
    //         00504a35     CMP        EBP,EAX
    //         00504a37     JLE        LAB_00504a84
    //         00504a39     LEA        this,[EBP*0x4 + 0x4]
    //         00504a40     LEA        EBX,[EBP + 0x1]
    //         00504a43     PUSH       this
    //         00504a44     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00504a49     MOV        EDI,EAX
    //         00504a4b     ADD        ESP,0x4
    //         00504a4e     TEST       EDI,EDI
    //         00504a50     JZ         LAB_00504a84
    //         00504a52     MOV        this,dword ptr [ESI + 0x6c]
    //         00504a55     XOR        EAX,EAX
    //         00504a57     TEST       this,this
    //         00504a59     JLE        LAB_00504a72
    //                               LAB_00504a5b                                                 XREF[1]:     00504a70(j)  
    //         00504a5b     CMP        EAX,EBX
    //         00504a5d     JGE        LAB_00504a72
    //         00504a5f     MOV        EDX,dword ptr [ESI + 0x60]
    //         00504a62     INC        EAX
    //         00504a63     MOV        this,dword ptr [EDX + EAX*0x4 + -0x4]
    //         00504a67     MOV        dword ptr [EDI + EAX*0x4 + -0x4],this
    //         00504a6b     MOV        this,dword ptr [ESI + 0x6c]
    //         00504a6e     CMP        EAX,this
    //         00504a70     JL         LAB_00504a5b
    //                               LAB_00504a72                                                 XREF[2]:     00504a59(j), 00504a5d(j)  
    //         00504a72     MOV        EDX,dword ptr [ESI + 0x60]
    //         00504a75     PUSH       EDX
    //         00504a76     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00504a7b     ADD        ESP,0x4
    //         00504a7e     MOV        dword ptr [ESI + 0x60],EDI
    //         00504a81     MOV        dword ptr [ESI + 0x6c],EBX
    //                               LAB_00504a84                                                 XREF[2]:     00504a37(j), 00504a50(j)  
    //         00504a84     MOV        EAX,dword ptr [ESI + 0x60]
    //         00504a87     MOV        EDX,dword ptr [ESI + 0x4]
    //         00504a8a     MOV        this,dword ptr [EAX + EBP*0x4]
    //         00504a8d     MOV        EAX,dword ptr [EDX + 0xc]
    //         00504a90     PUSH       this
    //         00504a91     MOV        this,dword ptr [EAX + 0x3c]
    //         00504a94     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //                              taiuaimd.cpp:651 (4)
    //         00504a99     TEST       EAX,EAX
    //         00504a9b     JZ         LAB_00504ac4
    //                              taiuaimd.cpp:654 (51)
    //         00504a9d     FLD        float ptr [EAX + 0x3c]
    //         00504aa0     MOV        this,dword ptr [ESI + 0x4]
    //         00504aa3     FLD        float ptr [EAX + 0x38]
    //         00504aa6     FSUB       float ptr [ECX + this->field56_0x38]
    //         00504aa9     FXCH
    //         00504aab     FSUB       float ptr [ECX + this->field60_0x3c]
    //         00504aae     FXCH
    //         00504ab0     FADD       float ptr [ESP + 0x20]
    //         00504ab4     FXCH
    //         00504ab6     FADD       float ptr [ESP + 0x1c]
    //         00504aba     FXCH
    //         00504abc     FSTP       float ptr [ESP + 0x20]
    //         00504ac0     FSTP       float ptr [ESP + 0x1c]
    //                               LAB_00504ac4                                                 XREF[2]:     00504a2b(j), 00504a9b(j)  
    //         00504ac4     MOV        EAX,dword ptr [ESI + 0x64]
    //         00504ac7     INC        EBP
    //         00504ac8     CMP        EBP,EAX
    //         00504aca     JL         LAB_005049cd
    //                               LAB_00504ad0                                                 XREF[1]:     005049c7(j)  
    //                              taiuaimd.cpp:647 (4)
    //         00504ad0     MOV        EBP,dword ptr [ESP + 0x14]
    //                               LAB_00504ad4                                                 XREF[1]:     005049bd(j)  
    //                              taiuaimd.cpp:662 (12)
    //         00504ad4     FLD        float ptr [ESP + 0x1c]
    //         00504ad8     FLD        float ptr [ESP + 0x20]
    //         00504adc     FMUL       float ptr [ESP + 0x20]
    //                              taiuaimd.cpp:671 (4)
    //         00504ae0     FLD        float ptr [ESP + 0x1c]
    //                              taiuaimd.cpp:675 (86)
    //         00504ae4     FXCH       ST2
    //         00504ae6     FMUL       float ptr [ESP + 0x1c]
    //         00504aea     FLD        float ptr [ESP + 0x20]
    //         00504aee     FXCH
    //         00504af0     FADDP      ST2,ST0
    //         00504af2     FXCH
    //         00504af4     MOV        EAX,dword ptr [ESI + 0x4]
    //         00504af7     PUSH       0x1
    //         00504af9     MOV        this,ESI
    //         00504afb     FSQRT
    //         00504afd     MOV        EDX,dword ptr [EAX + 0x40]
    //         00504b00     PUSH       EDX=>DAT_fffffff8
    //         00504b01     PUSH       this=>DAT_fffffff4
    //         00504b02     FXCH       ST2
    //         00504b04     FDIV       ST0,ST2
    //         00504b06     FXCH
    //         00504b08     FDIV       ST0,ST2
    //         00504b0a     FXCH
    //         00504b0c     FMUL       float ptr [ESP + 0x1c]
    //         00504b10     FXCH
    //         00504b12     FMUL       float ptr [ESP + 0x1c]
    //         00504b16     FXCH
    //         00504b18     FCHS
    //         00504b1a     FADD       float ptr [EAX + 0x3c]
    //         00504b1d     FXCH
    //         00504b1f     FCHS
    //         00504b21     FADD       float ptr [EAX + 0x38]
    //         00504b24     FXCH
    //         00504b26     FSTP       float ptr [ESP]=>DAT_fffffff4
    //         00504b29     PUSH       this=>DAT_fffffff0
    //         00504b2a     FSTP       float ptr [ESP]=>DAT_fffffff0
    //         00504b2d     FSTP       ST0
    //         00504b2f     CALL       dword ptr [EBP + 0x9c]
    //         00504b35     MOV        EAX,0x3
    //                              taiuaimd.cpp:678 (25)
    //         00504b3a     POP        EDI
    //         00504b3b     POP        ESI
    //         00504b3c     POP        EBP
    //         00504b3d     POP        EBX
    //         00504b3e     ADD        ESP,0x8
    //         00504b41     RET        0x8
    //                               LAB_00504b44                                                 XREF[3]:     00504906(j), 00504922(j), 
    //                                                                                                         0050493d(j)  
    //         00504b44     POP        EDI
    //         00504b45     POP        ESI
    //         00504b46     POP        EBP
    //         00504b47     MOV        EAX,0x2
    //         00504b4c     POP        EBX
    //         00504b4d     ADD        ESP,0x8
    //         00504b50     RET        0x8
    //         00504b53     ??         90h
    //         00504b54     NOP
    //         00504b55     NOP
    //         00504b56     NOP
    //         00504b57     NOP
    //         00504b58     NOP
    //         00504b59     NOP
    //         00504b5a     NOP
    //         00504b5b     NOP
    //         00504b5c     NOP
    //         00504b5d     NOP
    //         00504b5e     NOP
    //         00504b5f     NOP
    //                              * public: __thiscall TribeCivilianUnitAIModule::TribeCivilianUnitAIModule(class RGE_Static_Object *,... *
    //                              undefined __thiscall TribeCivilianUnitAIModule(TribeCivilianUnitAIMo
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TribeCivilianU    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00504b7e(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     00504b76(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00504b90(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00504c46(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00504b82(W)  
    //                               ??0TribeCivilianUnitAIModule@@QAE@PAVRGE_Static_Object@@H@Z  XREF[1]:     initUnitAI:004cb985(c)  
    //                               TribeCivilianUnitAIModule::TribeCivilianUnitAIModule
    //                              taiuaimd.cpp:686 (46)
    //         00504b60     PUSH       -0x1
    //         00504b62     PUSH       FUN_00560c68
    //         00504b67     MOV        EAX,FS:[0x0]
    //         00504b6d     PUSH       EAX
    //         00504b6e     MOV        dword ptr FS:[0x0],ESP
    //         00504b75     PUSH       this
    //         00504b76     MOV        EAX,dword ptr [ESP + param_2]
    //         00504b7a     PUSH       ESI
    //         00504b7b     MOV        ESI,this
    //         00504b7d     PUSH       EAX
    //         00504b7e     MOV        this,dword ptr [ESP + param_1]
    //         00504b82     MOV        dword ptr [ESP + local_10],ESI
    //         00504b86     PUSH       this
    //         00504b87     MOV        this,ESI
    //         00504b89     CALL       UnitAIModule::UnitAIModule                       undefined UnitAIModule(UnitAIModule * this, R
    //                              taiuaimd.cpp:691 (40)
    //         00504b8e     PUSH       0x2c
    //         00504b90     MOV        dword ptr [ESP + local_4],0x0
    //         00504b98     MOV        dword ptr [ESI],TribeCivilianUnitAIModule::`vf   = 00504c60
    //         00504b9e     MOV        dword ptr [ESI + 0x128],0xb
    //         00504ba8     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00504bad     ADD        ESP,0x4
    //         00504bb0     MOV        dword ptr [ESI + 0x124],EAX
    //                              taiuaimd.cpp:692 (8)
    //         00504bb6     TEST       EAX,EAX
    //         00504bb8     JZ         LAB_00504c46
    //                              taiuaimd.cpp:693 (6)
    //         00504bbe     MOV        dword ptr [EAX],0x3
    //                              taiuaimd.cpp:694 (13)
    //         00504bc4     MOV        EDX,dword ptr [ESI + 0x124]
    //         00504bca     MOV        dword ptr [EDX + 0x4],0x7
    //                              taiuaimd.cpp:695 (13)
    //         00504bd1     MOV        EAX,dword ptr [ESI + 0x124]
    //         00504bd7     MOV        dword ptr [EAX + 0x8],0x8
    //                              taiuaimd.cpp:696 (13)
    //         00504bde     MOV        this,dword ptr [ESI + 0x124]
    //         00504be4     MOV        dword ptr [ECX + this->field12_0xc],0x9
    //                              taiuaimd.cpp:697 (13)
    //         00504beb     MOV        EDX,dword ptr [ESI + 0x124]
    //         00504bf1     MOV        dword ptr [EDX + 0x10],0xa
    //                              taiuaimd.cpp:698 (13)
    //         00504bf8     MOV        EAX,dword ptr [ESI + 0x124]
    //         00504bfe     MOV        dword ptr [EAX + 0x14],0xf
    //                              taiuaimd.cpp:699 (13)
    //         00504c05     MOV        this,dword ptr [ESI + 0x124]
    //         00504c0b     MOV        dword ptr [ECX + this->field24_0x18],0x11
    //                              taiuaimd.cpp:700 (13)
    //         00504c12     MOV        EDX,dword ptr [ESI + 0x124]
    //         00504c18     MOV        dword ptr [EDX + 0x1c],0x12
    //                              taiuaimd.cpp:701 (13)
    //         00504c1f     MOV        EAX,dword ptr [ESI + 0x124]
    //         00504c25     MOV        dword ptr [EAX + 0x20],0x20
    //                              taiuaimd.cpp:702 (13)
    //         00504c2c     MOV        this,dword ptr [ESI + 0x124]
    //         00504c32     MOV        dword ptr [ECX + this->field36_0x24],0x21
    //                              taiuaimd.cpp:703 (13)
    //         00504c39     MOV        EDX,dword ptr [ESI + 0x124]
    //         00504c3f     MOV        dword ptr [EDX + 0x28],0x1b
    //                               LAB_00504c46                                                 XREF[1]:     00504bb8(j)  
    //                              taiuaimd.cpp:705 (20)
    //         00504c46     MOV        this,dword ptr [ESP + local_c]
    //         00504c4a     MOV        EAX,ESI
    //         00504c4c     MOV        dword ptr FS:[0x0],this
    //         00504c53     POP        ESI
    //         00504c54     ADD        ESP,0x10
    //         00504c57     RET        0x8
    //         00504c5a     ??         90h
    //         00504c5b     NOP
    //         00504c5c     NOP
    //         00504c5d     NOP
    //         00504c5e     NOP
    //         00504c5f     NOP
    //                              * public: virtual void * __thiscall TribeCivilianUnitAIModule::`scalar deleting destructor'(unsigned... *
    //                              void * __thiscall `scalar_deleting_destructor'(TribeCivilianUnitAIMo
    //              void *            EAX:4          <RETURN>
    //              TribeCivilianU    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00504c68(R)  
    //                               ??_ETribeCivilianUnitAIModule@@UAEPAXI@Z                     XREF[1]:     00575d48(*)  
    //                               ??_GTribeCivilianUnitAIModule@@UAEPAXI@Z
    //                               TribeCivilianUnitAIModule::`scalar_deleting_destructor'
    //         00504c60     PUSH       ESI
    //         00504c61     MOV        ESI,this
    //         00504c63     CALL       TribeCivilianUnitAIModule::~TribeCivilianUnitA   void ~TribeCivilianUnitAIModule(TribeCivilian
    //         00504c68     TEST       byte ptr [ESP + param_1],0x1
    //         00504c6d     JZ         LAB_00504c78
    //         00504c6f     PUSH       ESI
    //         00504c70     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00504c75     ADD        ESP,0x4
    //                               LAB_00504c78                                                 XREF[1]:     00504c6d(j)  
    //         00504c78     MOV        EAX,ESI
    //         00504c7a     POP        ESI
    //         00504c7b     RET        0x4
    //                              *                                            THUNK FUNCTION                                             *
    //                              thunk void __thiscall ~UnitAIModule(UnitAIModule * this)
    //                                Thunked-Function: UnitAIModule::~UnitAIMo
    //              void              <VOID>         <RETURN>
    //              UnitAIModule *    ECX:4 (auto)   this
    //                               UnitAIModule::~UnitAIModule
    //         00504c7e     NOP
    //         00504c7f     NOP
}

int TribeCivilianUnitAIModule::importantWhenDead(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall importantWhenDead(TribeCivilianUnitAIModule * this, i
    //              int               EAX:4          <RETURN>
    //              TribeCivilianU    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00504c90(R)  
    //                               ?importantWhenDead@TribeCivilianUnitAIModule@@UAEHH@Z        XREF[1]:     00575d6c(*)  
    //                               TribeCivilianUnitAIModule::importantWhenDead
    //                              taiuaimd.cpp:710 (34)
    //         00504c90     MOV        EAX,dword ptr [ESP + param_1]
    //         00504c94     CMP        EAX,0x7
    //         00504c97     JZ         LAB_00504cb7
    //         00504c99     CMP        EAX,0x9
    //         00504c9c     JZ         LAB_00504cb7
    //         00504c9e     CMP        EAX,0xa
    //         00504ca1     JZ         LAB_00504cb7
    //         00504ca3     CMP        EAX,0xf
    //         00504ca6     JZ         LAB_00504cb7
    //         00504ca8     CMP        EAX,0x8
    //         00504cab     JZ         LAB_00504cb7
    //         00504cad     CMP        EAX,0x20
    //         00504cb0     JZ         LAB_00504cb7
    //                              taiuaimd.cpp:720 (2)
    //         00504cb2     XOR        EAX,EAX
    //                              taiuaimd.cpp:721 (3)
    //         00504cb4     RET        0x4
    //                               LAB_00504cb7                                                 XREF[6]:     00504c97(j), 00504c9c(j), 
    //                                                                                                         00504ca1(j), 00504ca6(j), 
    //                                                                                                         00504cab(j), 00504cb0(j)  
    //                              taiuaimd.cpp:719 (5)
    //         00504cb7     MOV        EAX,0x1
    //                              taiuaimd.cpp:721 (3)
    //         00504cbc     RET        0x4
    //         00504cbf     ??         90h
    return 0;
}

int TribeCivilianUnitAIModule::attackObject(int param_1, int param_2) {
    /* TODO: Stub */
    //                              int __thiscall attackObject(TribeCivilianUnitAIModule * this, int pa
    //              int               EAX:4          <RETURN>
    //              TribeCivilianU    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00504cc4(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[2]:     00504cf6(R), 00504d08(R)  
    //                               ?attackObject@TribeCivilianUnitAIModule@@UAEHHH@Z            XREF[1]:     00575da4(*)  
    //                               TribeCivilianUnitAIModule::attackObject
    //                              taiuaimd.cpp:726 (4)
    //         00504cc0     PUSH       ESI
    //         00504cc1     MOV        ESI,this
    //         00504cc3     PUSH       EDI
    //                              taiuaimd.cpp:729 (19)
    //         00504cc4     MOV        EDI,dword ptr [ESP + param_1]
    //         00504cc8     MOV        EAX,dword ptr [ESI + 0x4]
    //         00504ccb     PUSH       EDI
    //         00504ccc     MOV        this,dword ptr [EAX + 0xc]
    //         00504ccf     MOV        this,dword ptr [ECX + this->field60_0x3c]
    //         00504cd2     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //                              taiuaimd.cpp:730 (4)
    //         00504cd7     TEST       EAX,EAX
    //         00504cd9     JNZ        LAB_00504ce0
    //                              taiuaimd.cpp:741 (5)
    //         00504cdb     POP        EDI
    //         00504cdc     POP        ESI
    //         00504cdd     RET        0x8
    //                               LAB_00504ce0                                                 XREF[1]:     00504cd9(j)  
    //                              taiuaimd.cpp:735 (7)
    //         00504ce0     MOV        EDX,dword ptr [EAX + 0x8]
    //         00504ce3     MOVSX      EAX,word ptr [EDX + 0x14]
    //                              taiuaimd.cpp:738 (15)
    //         00504ce7     CMP        EAX,0x9
    //         00504cea     JZ         LAB_00504d08
    //         00504cec     CMP        EAX,0xa
    //         00504cef     JZ         LAB_00504d08
    //         00504cf1     CMP        EAX,0xf
    //         00504cf4     JZ         LAB_00504d08
    //                              taiuaimd.cpp:740 (13)
    //         00504cf6     MOV        EAX,dword ptr [ESP + param_2]
    //         00504cfa     MOV        this,ESI
    //         00504cfc     PUSH       EAX
    //         00504cfd     PUSH       EDI
    //         00504cfe     CALL       UnitAIModule::attackObject                       int attackObject(UnitAIModule * this, int par
    //                              taiuaimd.cpp:741 (5)
    //         00504d03     POP        EDI
    //         00504d04     POP        ESI
    //         00504d05     RET        0x8
    //                               LAB_00504d08                                                 XREF[3]:     00504cea(j), 00504cef(j), 
    //                                                                                                         00504cf4(j)  
    //                              taiuaimd.cpp:739 (13)
    //         00504d08     MOV        EAX,dword ptr [ESP + param_2]
    //         00504d0c     MOV        EDX,dword ptr [ESI]
    //         00504d0e     PUSH       EAX
    //         00504d0f     PUSH       EDI
    //         00504d10     MOV        this,ESI
    //         00504d12     CALL       dword ptr [EDX + 0x64]
    //                              taiuaimd.cpp:741 (5)
    //         00504d15     POP        EDI
    //         00504d16     POP        ESI
    //         00504d17     RET        0x8
    //         00504d1a     ??         90h
    //         00504d1b     NOP
    //         00504d1c     NOP
    //         00504d1d     NOP
    //         00504d1e     NOP
    //         00504d1f     NOP
    return 0;
}

int TribeCivilianUnitAIModule::canAttackUnit(RGE_Static_Object* param_1) {
    /* TODO: Stub */
    //                              int __thiscall canAttackUnit(TribeCivilianUnitAIModule * this, RGE_S
    //              int               EAX:4          <RETURN>
    //              TribeCivilianU    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00504d20(R)  
    //                               ?canAttackUnit@TribeCivilianUnitAIModule@@UAEHPAVRGE_Static  XREF[1]:     00575d98(*)  
    //                               TribeCivilianUnitAIModule::canAttackUnit
    //                              taiuaimd.cpp:746 (8)
    //         00504d20     MOV        EAX,dword ptr [ESP + param_1]
    //         00504d24     TEST       EAX,EAX
    //         00504d26     JNZ        LAB_00504d2b
    //                              taiuaimd.cpp:753 (3)
    //         00504d28     RET        0x4
    //                               LAB_00504d2b                                                 XREF[1]:     00504d26(j)  
    //                              taiuaimd.cpp:750 (15)
    //         00504d2b     MOV        EAX,dword ptr [EAX + 0x8]
    //         00504d2e     XOR        this,this
    //         00504d30     CMP        word ptr [EAX + 0x14],0x1
    //         00504d35     SETNZ      this
    //         00504d38     MOV        EAX,this
    //                              taiuaimd.cpp:753 (3)
    //         00504d3a     RET        0x4
    //         00504d3d     ??         90h
    //         00504d3e     NOP
    //         00504d3f     NOP
    return 0;
}

int TribeCivilianUnitAIModule::canAttackUnitAtNeutrality(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall canAttackUnitAtNeutrality(TribeCivilianUnitAIModule *
    //              int               EAX:4          <RETURN>
    //              TribeCivilianU    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //                               ?canAttackUnitAtNeutrality@TribeCivilianUnitAIModule@@UAEHH@Z XREF[1]:     00575d9c(*)  
    //                               TribeCivilianUnitAIModule::canAttackUnitAtNeutrality
    //                              taiuaimd.cpp:758 (2)
    //         00504d40     XOR        EAX,EAX
    //                              taiuaimd.cpp:761 (3)
    //         00504d42     RET        0x4
    //         00504d45     ??         90h
    //         00504d46     NOP
    //         00504d47     NOP
    //         00504d48     NOP
    //         00504d49     NOP
    //         00504d4a     NOP
    //         00504d4b     NOP
    //         00504d4c     NOP
    //         00504d4d     NOP
    //         00504d4e     NOP
    //         00504d4f     NOP
    return 0;
}

int TribeCivilianUnitAIModule::retryableOrder(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall retryableOrder(TribeCivilianUnitAIModule * this, int 
    //              int               EAX:4          <RETURN>
    //              TribeCivilianU    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00504d50(R)  
    //                               ?retryableOrder@TribeCivilianUnitAIModule@@UAEHH@Z           XREF[1]:     00575d70(*)  
    //                               TribeCivilianUnitAIModule::retryableOrder
    //                              taiuaimd.cpp:766 (25)
    //         00504d50     MOV        EAX,dword ptr [ESP + param_1]
    //         00504d54     CMP        EAX,0x2c1
    //         00504d59     JZ         LAB_00504d6e
    //         00504d5b     CMP        EAX,0x2c5
    //         00504d60     JZ         LAB_00504d6e
    //         00504d62     CMP        EAX,0x2c9
    //         00504d67     JZ         LAB_00504d6e
    //                              taiuaimd.cpp:772 (2)
    //         00504d69     XOR        EAX,EAX
    //                              taiuaimd.cpp:773 (3)
    //         00504d6b     RET        0x4
    //                               LAB_00504d6e                                                 XREF[3]:     00504d59(j), 00504d60(j), 
    //                                                                                                         00504d67(j)  
    //                              taiuaimd.cpp:771 (5)
    //         00504d6e     MOV        EAX,0x1
    //                              taiuaimd.cpp:773 (3)
    //         00504d73     RET        0x4
    //         00504d76     ??         90h
    //         00504d77     NOP
    //         00504d78     NOP
    //         00504d79     NOP
    //         00504d7a     NOP
    //         00504d7b     NOP
    //         00504d7c     NOP
    //         00504d7d     NOP
    //         00504d7e     NOP
    //         00504d7f     NOP
    return 0;
}

int TribeCivilianUnitAIModule::convertToLOSResourceType(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall convertToLOSResourceType(TribeCivilianUnitAIModule * 
    //              int               EAX:4          <RETURN>
    //              TribeCivilianU    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00504d80(R)  
    //                               ?convertToLOSResourceType@TribeCivilianUnitAIModule@@UAEHH@Z XREF[1]:     00575e08(*)  
    //                               TribeCivilianUnitAIModule::convertToLOSResourceType
    //                              taiuaimd.cpp:778 (27)
    //         00504d80     MOV        EAX,dword ptr [ESP + param_1]
    //         00504d84     ADD        EAX,-0x5
    //         00504d87     CMP        EAX,0x1c
    //         00504d8a     JA         switchD_00504d94::caseD_6
    //         00504d8c     XOR        this,this
    //         00504d8e     MOV        this,byte ptr [EAX + 0x504de8]=>PTR_caseD_5_00
    //                               switchD_00504d94::switchD
    //         00504d94     JMP        dword ptr [this->field0_0x0*0x4 + switchD_0050   = 00504db8
    //                               switchD_00504d94::caseD_7                                    XREF[2]:     00504d94(j), 00504dcc(*)  
    //                              taiuaimd.cpp:781 (5)
    //         00504d9b     MOV        EAX,0x1
    //                              taiuaimd.cpp:794 (3)
    //         00504da0     RET        0x4
    //                               switchD_00504d94::caseD_20                                   XREF[2]:     00504d94(j), 00504ddc(*)  
    //                              taiuaimd.cpp:783 (5)
    //         00504da3     MOV        EAX,0x4
    //                              taiuaimd.cpp:794 (3)
    //         00504da8     RET        0x4
    //                               switchD_00504d94::caseD_8                                    XREF[2]:     00504d94(j), 00504dd0(*)  
    //                              taiuaimd.cpp:785 (5)
    //         00504dab     MOV        EAX,0x3
    //                              taiuaimd.cpp:794 (3)
    //         00504db0     RET        0x4
    //                               switchD_00504d94::caseD_f                                    XREF[2]:     00504d94(j), 00504dd4(*)  
    //                              taiuaimd.cpp:787 (2)
    //         00504db3     XOR        EAX,EAX
    //                              taiuaimd.cpp:794 (3)
    //         00504db5     RET        0x4
    //                               switchD_00504d94::caseD_1f                                   XREF[4]:     00504d94(j), 00504dc8(*), 
    //                               switchD_00504d94::caseD_21                                                00504dd8(*), 00504de0(*)  
    //                               switchD_00504d94::caseD_5
    //                              taiuaimd.cpp:791 (5)
    //         00504db8     MOV        EAX,0x2
    //                              taiuaimd.cpp:794 (3)
    //         00504dbd     RET        0x4
    //                               switchD_00504d94::caseD_9                                    XREF[3]:     00504d8a(j), 00504d94(j), 
    //                               switchD_00504d94::caseD_a                                                 00504de4(*)  
    //                               switchD_00504d94::caseD_b
    //                               switchD_00504d94::caseD_c
    //                               switchD_00504d94::caseD_d
    //                               switchD_00504d94::caseD_e
    //                               switchD_00504d94::caseD_10
    //                               switchD_00504d94::caseD_11
    //                               switchD_00504d94::caseD_12
    //                               switchD_00504d94::caseD_13
    //                               switchD_00504d94::caseD_14
    //                               switchD_00504d94::caseD_15
    //                               switchD_00504d94::caseD_16
    //                               switchD_00504d94::caseD_17
    //                               switchD_00504d94::caseD_18
    //                               switchD_00504d94::caseD_19
    //                               switchD_00504d94::caseD_1a
    //                               switchD_00504d94::caseD_1b
    //                               switchD_00504d94::caseD_1c
    //                               switchD_00504d94::caseD_1d
    //                               switchD_00504d94::caseD_1e
    //                               switchD_00504d94::caseD_6
    //                              taiuaimd.cpp:793 (3)
    //         00504dc0     OR         EAX,0xffffffff
    //                              taiuaimd.cpp:794 (66)
    //         00504dc3     RET        0x4
    //                              *                                               FUNCTION                                                *
    //                              undefined FUN_00504dc6()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00504dc6
    //         00504dc6     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_00504d94::switchdataD_00504dc8                       XREF[1]:     convertToLOSResourceType:00504d94(
    //         00504dc8     addr       switchD_00504d94::caseD_5
    //         00504dcc     addr       switchD_00504d94::caseD_7
    //         00504dd0     addr       switchD_00504d94::caseD_8
    //         00504dd4     addr       switchD_00504d94::caseD_f
    //         00504dd8     addr       switchD_00504d94::caseD_5
    //         00504ddc     addr       switchD_00504d94::caseD_20
    //                               PTR_caseD_5_00504de0+3                                       XREF[0,1]:   convertToLOSResourceType:00504d8e(
    //         00504de0     addr       switchD_00504d94::caseD_5
    //         00504de4     addr       switchD_00504d94::caseD_6
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_00504d94::switchdataD_00504de8
    //         00504de8     db         0h
    //         00504de9     db         7h
    //         00504dea     db         1h
    //         00504deb     db         2h
    //         00504dec     db         7h
    //         00504ded     db         7h
    //         00504dee     db         7h
    //         00504def     db         7h
    //         00504df0     db         7h
    //         00504df1     db         7h
    //         00504df2     db         3h
    //         00504df3     db         7h
    //         00504df4     db         7h
    //         00504df5     db         7h
    //         00504df6     db         7h
    //         00504df7     db         7h
    //         00504df8     db         7h
    //         00504df9     db         7h
    //         00504dfa     db         7h
    //         00504dfb     db         7h
    //         00504dfc     db         7h
    //         00504dfd     db         7h
    //         00504dfe     db         7h
    //         00504dff     db         7h
    //         00504e00     db         7h
    //         00504e01     db         7h
    //         00504e02     db         4h
    //         00504e03     db         5h
    //         00504e04     db         6h
    //         00504e05     ??         90h
    //         00504e06     ??         90h
    //         00504e07     ??         90h
    //         00504e08     ??         90h
    //         00504e09     ??         90h
    //         00504e0a     ??         90h
    //         00504e0b     ??         90h
    //         00504e0c     ??         90h
    //         00504e0d     ??         90h
    //         00504e0e     ??         90h
    //         00504e0f     ??         90h
    //                              * protected: virtual int __thiscall TribeCivilianUnitAIModule::processNotify(struct NotifyEvent *,un... *
    //                              int __thiscall processNotify(TribeCivilianUnitAIModule * this, Notif
    //              int               EAX:4          <RETURN>
    //              TribeCivilianU    ECX:4 (auto)   this
    //              NotifyEvent *     Stack[0x4]:4   param_1                   XREF[2]:     00504e12(R), 00505747(R)  
    //              ulong             Stack[0x8]:4   param_2                   XREF[3]:     00504eac(W), 0050566a(*), 005057a9(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00504eb7(W), 00505670(*)  
    //              int               Stack[-0x8]:4  tileX
    //                               ?processNotify@TribeCivilianUnitAIModule@@MAEHPAUNotifyEven  XREF[1]:     00575e14(*)  
    //                               TribeCivilianUnitAIModule::processNotify
    //                              taiuaimd.cpp:800 (2)
    //         00504e10     PUSH       this
    //         00504e11     PUSH       EBX
    //                              taiuaimd.cpp:809 (41)
    //         00504e12     MOV        EBX,dword ptr [ESP + param_1]
    //         00504e16     PUSH       EBP
    //         00504e17     PUSH       ESI
    //         00504e18     MOV        EAX,dword ptr [EBX + 0x8]
    //         00504e1b     PUSH       EDI
    //         00504e1c     ADD        EAX,0xfffffe0c
    //         00504e21     MOV        ESI,this
    //         00504e23     CMP        EAX,0x1b
    //         00504e26     JA         switchD_00504e34::caseD_1f5
    //         00504e2c     XOR        this,this
    //         00504e2e     MOV        this,byte ptr [EAX + switchD_00504e34::switchd
    //                               switchD_00504e34::switchD
    //         00504e34     JMP        dword ptr [this->field0_0x0*0x4 + switchD_0050   = 00504e5b
    //                               switchD_00504e34::caseD_20f                                  XREF[2]:     00504e34(j), 005057d4(*)  
    //                              taiuaimd.cpp:814 (19)
    //         00504e3b     MOV        EDX,dword ptr [ESI + 0x4]
    //         00504e3e     MOV        EAX,dword ptr [EDX + 0xc]
    //         00504e41     MOV        this,dword ptr [EAX + 0x3c]
    //         00504e44     CALL       RGE_Game_World::difficultyLevel                  int difficultyLevel(RGE_Game_World * this)
    //         00504e49     CMP        EAX,0x3
    //         00504e4c     JL         switchD_00504e34::caseD_1f4
    //                              taiuaimd.cpp:815 (5)
    //         00504e4e     MOV        EAX,0x2
    //                              taiuaimd.cpp:1237 (8)
    //         00504e53     POP        EDI
    //         00504e54     POP        ESI
    //         00504e55     POP        EBP
    //         00504e56     POP        EBX
    //         00504e57     POP        this
    //         00504e58     RET        0x8
    //                               switchD_00504e34::caseD_1f4                                  XREF[3]:     00504e34(j), 00504e4c(j), 
    //                                                                                                         005057c0(*)  
    //                              taiuaimd.cpp:823 (7)
    //         00504e5b     MOV        EAX,dword ptr [EBX + 0x10]
    //         00504e5e     TEST       EAX,EAX
    //         00504e60     JG         LAB_00504e9a
    //                              taiuaimd.cpp:828 (31)
    //         00504e62     MOV        EAX,dword ptr [ESI + 0x4]
    //         00504e65     MOV        EDI,dword ptr [EBX]
    //         00504e67     PUSH       0x0
    //         00504e69     PUSH       0x0
    //         00504e6b     MOV        this,dword ptr [EAX + 0xc]
    //         00504e6e     MOV        EAX,dword ptr [EAX + 0x4]
    //         00504e71     PUSH       EDI
    //         00504e72     PUSH       0x209
    //         00504e77     MOV        EDX,dword ptr [this->field0_0x0]
    //         00504e79     PUSH       EAX
    //         00504e7a     PUSH       EAX
    //         00504e7b     CALL       dword ptr [EDX + 0xe8]
    //                              taiuaimd.cpp:829 (12)
    //         00504e81     MOV        EAX,dword ptr [ESP + 0x1c]
    //         00504e85     MOV        this,ESI
    //         00504e87     PUSH       EAX
    //         00504e88     CALL       UnitAIModule::purgeNotifyQueue                   void purgeNotifyQueue(UnitAIModule * this, ul
    //                              taiuaimd.cpp:830 (5)
    //         00504e8d     MOV        EAX,0x4
    //                              taiuaimd.cpp:1237 (8)
    //         00504e92     POP        EDI
    //         00504e93     POP        ESI
    //         00504e94     POP        EBP
    //         00504e95     POP        EBX
    //         00504e96     POP        this
    //         00504e97     RET        0x8
    //                               LAB_00504e9a                                                 XREF[1]:     00504e60(j)  
    //                              taiuaimd.cpp:834 (10)
    //         00504e9a     MOV        this,dword ptr [EBX]
    //         00504e9c     PUSH       this
    //         00504e9d     MOV        this,ESI
    //         00504e9f     CALL       UnitAIModule::lookupObject                       RGE_Static_Object * lookupObject(UnitAIModule
    //                              taiuaimd.cpp:835 (17)
    //         00504ea4     MOV        EDX,dword ptr [ESI + 0x34]
    //         00504ea7     MOV        EDI,EAX
    //         00504ea9     PUSH       EDX
    //         00504eaa     MOV        this,ESI
    //         00504eac     MOV        dword ptr [ESP + param_2],EDI
    //         00504eb0     CALL       UnitAIModule::lookupObject                       RGE_Static_Object * lookupObject(UnitAIModule
    //                              taiuaimd.cpp:836 (8)
    //         00504eb5     TEST       EDI,EDI
    //         00504eb7     MOV        dword ptr [ESP + local_4],EAX
    //         00504ebb     JNZ        LAB_00504eca
    //                              taiuaimd.cpp:840 (5)
    //         00504ebd     MOV        EAX,0x2
    //                              taiuaimd.cpp:1237 (8)
    //         00504ec2     POP        EDI
    //         00504ec3     POP        ESI
    //         00504ec4     POP        EBP
    //         00504ec5     POP        EBX
    //         00504ec6     POP        this
    //         00504ec7     RET        0x8
    //                               LAB_00504eca                                                 XREF[1]:     00504ebb(j)  
    //                              taiuaimd.cpp:845 (16)
    //         00504eca     MOV        EAX,dword ptr [ESI + 0x4]
    //         00504ecd     MOV        this,dword ptr [EAX + 0xc]
    //         00504ed0     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
    //         00504ed5     CMP        EAX,0x1
    //         00504ed8     JNZ        LAB_00504ef7
    //                              taiuaimd.cpp:847 (27)
    //         00504eda     MOV        this,dword ptr [EDI + 0xc]
    //         00504edd     MOV        AX,word ptr [ECX + this->field74_0x4a]
    //         00504ee1     TEST       AX,AX
    //         00504ee4     JNZ        LAB_00504efe
    //         00504ee6     MOV        EDX,dword ptr [EDI + 0x4]
    //         00504ee9     MOV        this,dword ptr [ESI + 0x34]
    //         00504eec     CMP        EDX,this
    //         00504eee     JNZ        LAB_00504efe
    //         00504ef0     TEST       AX,AX
    //         00504ef3     JZ         LAB_00504f1d
    //                              taiuaimd.cpp:852 (9)
    //         00504ef5     JMP        LAB_00504efe
    //                               LAB_00504ef7                                                 XREF[1]:     00504ed8(j)  
    //         00504ef7     MOV        EAX,dword ptr [ESI + 0x64]
    //         00504efa     TEST       EAX,EAX
    //         00504efc     JNZ        LAB_00504f1d
    //                               LAB_00504efe                                                 XREF[3]:     00504ee4(j), 00504eee(j), 
    //                                                                                                         00504ef5(j)  
    //                              taiuaimd.cpp:854 (31)
    //         00504efe     MOV        EAX,dword ptr [ESI + 0x4]
    //         00504f01     MOV        EDI,dword ptr [EBX]
    //         00504f03     PUSH       0x0
    //         00504f05     PUSH       0x0
    //         00504f07     MOV        this,dword ptr [EAX + 0xc]
    //         00504f0a     MOV        EAX,dword ptr [EAX + 0x4]
    //         00504f0d     PUSH       EDI
    //         00504f0e     PUSH       0x201
    //         00504f13     MOV        EDX,dword ptr [this->field0_0x0]
    //         00504f15     PUSH       EAX
    //         00504f16     PUSH       EAX
    //         00504f17     CALL       dword ptr [EDX + 0xe8]
    //                               LAB_00504f1d                                                 XREF[2]:     00504ef3(j), 00504efc(j)  
    //                              taiuaimd.cpp:862 (57)
    //         00504f1d     MOV        this,dword ptr [ESI + 0x64]
    //         00504f20     XOR        EAX,EAX
    //         00504f22     TEST       this,this
    //         00504f24     JLE        LAB_00504f3e
    //         00504f26     MOV        EDX,dword ptr [ESI + 0x6c]
    //                               LAB_00504f29                                                 XREF[1]:     00504f3c(j)  
    //         00504f29     CMP        EAX,EDX
    //         00504f2b     JGE        LAB_00504f3e
    //         00504f2d     MOV        EDI,dword ptr [ESI + 0x60]
    //         00504f30     MOV        EBP,dword ptr [EBX]
    //         00504f32     MOV        EDI,dword ptr [EDI + EAX*0x4]
    //         00504f35     CMP        EDI,EBP
    //         00504f37     JZ         LAB_00504f5e
    //         00504f39     INC        EAX
    //         00504f3a     CMP        EAX,this
    //         00504f3c     JL         LAB_00504f29
    //                               LAB_00504f3e                                                 XREF[2]:     00504f24(j), 00504f2b(j)  
    //         00504f3e     MOV        EAX,dword ptr [ESI + 0x4]
    //         00504f41     MOV        this,dword ptr [EAX + 0xc]
    //         00504f44     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
    //         00504f49     TEST       EAX,EAX
    //         00504f4b     JNZ        LAB_00504f5e
    //         00504f4d     MOV        EAX,dword ptr [EBX]
    //         00504f4f     MOV        this,dword ptr [ESI + 0x34]
    //         00504f52     CMP        this,EAX
    //         00504f54     JZ         LAB_00504f5e
    //                              taiuaimd.cpp:863 (8)
    //         00504f56     PUSH       EAX
    //         00504f57     MOV        this,ESI
    //         00504f59     CALL       UnitAIModule::askForHelp                         void askForHelp(UnitAIModule * this, int para
    //                               LAB_00504f5e                                                 XREF[3]:     00504f37(j), 00504f4b(j), 
    //                                                                                                         00504f54(j)  
    //                              taiuaimd.cpp:865 (134)
    //         00504f5e     MOV        this,dword ptr [ESI + 0x64]
    //         00504f61     MOV        EBP,dword ptr [EBX]
    //         00504f63     XOR        EAX,EAX
    //         00504f65     TEST       this,this
    //         00504f67     JLE        LAB_00504f7d
    //         00504f69     MOV        EDX,dword ptr [ESI + 0x6c]
    //                               LAB_00504f6c                                                 XREF[1]:     00504f7b(j)  
    //         00504f6c     CMP        EAX,EDX
    //         00504f6e     JGE        LAB_00504f7d
    //         00504f70     MOV        EDI,dword ptr [ESI + 0x60]
    //         00504f73     CMP        dword ptr [EDI + EAX*0x4],EBP
    //         00504f76     JZ         LAB_00504fe4
    //         00504f78     INC        EAX
    //         00504f79     CMP        EAX,this
    //         00504f7b     JL         LAB_00504f6c
    //                               LAB_00504f7d                                                 XREF[2]:     00504f67(j), 00504f6e(j)  
    //         00504f7d     MOV        EDX,dword ptr [ESI + 0x6c]
    //         00504f80     DEC        EDX
    //         00504f81     CMP        this,EDX
    //         00504f83     JLE        LAB_00504fd4
    //         00504f85     LEA        EBX,[ECX + this->field1_0x1]
    //         00504f88     LEA        EAX,[EBX*0x4 + 0x0]
    //         00504f8f     PUSH       EAX
    //         00504f90     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00504f95     MOV        EDI,EAX
    //         00504f97     ADD        ESP,0x4
    //         00504f9a     TEST       EDI,EDI
    //         00504f9c     JZ         LAB_00504fd0
    //         00504f9e     MOV        this,dword ptr [ESI + 0x6c]
    //         00504fa1     XOR        EAX,EAX
    //         00504fa3     TEST       this,this
    //         00504fa5     JLE        LAB_00504fbe
    //                               LAB_00504fa7                                                 XREF[1]:     00504fbc(j)  
    //         00504fa7     CMP        EAX,EBX
    //         00504fa9     JGE        LAB_00504fbe
    //         00504fab     MOV        this,dword ptr [ESI + 0x60]
    //         00504fae     INC        EAX
    //         00504faf     MOV        EDX,dword ptr [this->field0_0x0 + EAX*0x4 + -0
    //         00504fb3     MOV        dword ptr [EDI + EAX*0x4 + -0x4],EDX
    //         00504fb7     MOV        this,dword ptr [ESI + 0x6c]
    //         00504fba     CMP        EAX,this
    //         00504fbc     JL         LAB_00504fa7
    //                               LAB_00504fbe                                                 XREF[2]:     00504fa5(j), 00504fa9(j)  
    //         00504fbe     MOV        EAX,dword ptr [ESI + 0x60]
    //         00504fc1     PUSH       EAX
    //         00504fc2     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00504fc7     ADD        ESP,0x4
    //         00504fca     MOV        dword ptr [ESI + 0x60],EDI
    //         00504fcd     MOV        dword ptr [ESI + 0x6c],EBX
    //                               LAB_00504fd0                                                 XREF[1]:     00504f9c(j)  
    //         00504fd0     MOV        EBX,dword ptr [ESP + 0x18]
    //                               LAB_00504fd4                                                 XREF[1]:     00504f83(j)  
    //         00504fd4     MOV        this,dword ptr [ESI + 0x64]
    //         00504fd7     MOV        EDX,dword ptr [ESI + 0x60]
    //         00504fda     MOV        dword ptr [EDX + this->field0_0x0*0x4],EBP
    //         00504fdd     MOV        EAX,dword ptr [ESI + 0x64]
    //         00504fe0     INC        EAX
    //         00504fe1     MOV        dword ptr [ESI + 0x64],EAX
    //                               LAB_00504fe4                                                 XREF[1]:     00504f76(j)  
    //                              taiuaimd.cpp:866 (13)
    //         00504fe4     MOV        this,dword ptr [ESI + 0x4]
    //         00504fe7     PUSH       0x1
    //         00504fe9     MOV        EAX,dword ptr [this->field0_0x0]
    //         00504feb     CALL       dword ptr [EAX + 0xec]
    //                              taiuaimd.cpp:868 (11)
    //         00504ff1     MOV        this,dword ptr [ESI + 0x4]
    //         00504ff4     MOV        EDX,dword ptr [this->field0_0x0]
    //         00504ff6     CALL       dword ptr [EDX + 0xf4]
    //                              taiuaimd.cpp:869 (15)
    //         00504ffc     MOV        this,dword ptr [ESI + 0x4]
    //         00504fff     FSTP       float ptr [ESP + 0x18]
    //         00505003     MOV        EAX,dword ptr [this->field0_0x0]
    //         00505005     CALL       dword ptr [EAX + 0x134]
    //                              taiuaimd.cpp:878 (112)
    //         0050500b     MOV        this,dword ptr [ESI + 0x28]
    //         0050500e     AND        EAX,0xff
    //         00505013     CMP        this,0x2c6
    //         00505019     MOV        EDX,EAX
    //         0050501b     JNZ        LAB_00505032
    //         0050501d     FLD        float ptr [ESP + 0x18]
    //         00505021     FCOMP      float ptr [DAT_005758c4]
    //         00505027     FNSTSW     AX
    //         00505029     TEST       AH,0x41
    //         0050502c     JZ         LAB_0050579c
    //                               LAB_00505032                                                 XREF[1]:     0050501b(j)  
    //         00505032     CMP        this,0x2bc
    //         00505038     JZ         LAB_0050579c
    //         0050503e     CMP        this,0x2c9
    //         00505044     JNZ        LAB_0050506f
    //         00505046     CMP        EDX,0xc
    //         00505049     JNZ        LAB_0050506f
    //         0050504b     MOV        EAX,dword ptr [ESP + 0x10]
    //         0050504f     TEST       EAX,EAX
    //         00505051     JZ         LAB_0050506f
    //         00505053     MOV        EDX,dword ptr [EAX + 0x8]
    //         00505056     CMP        word ptr [EDX + 0x14],0xa
    //         0050505b     JNZ        LAB_0050506f
    //         0050505d     MOV        EAX,dword ptr [ESP + 0x1c]
    //         00505061     MOV        EDX,dword ptr [EAX + 0xc]
    //         00505064     CMP        word ptr [EDX + 0x4a],0x0
    //         00505069     JZ         LAB_0050579c
    //                               LAB_0050506f                                                 XREF[4]:     00505044(j), 00505049(j), 
    //                                                                                                         00505051(j), 0050505b(j)  
    //         0050506f     CMP        this,0x2ce
    //         00505075     JZ         LAB_0050579c
    //                              taiuaimd.cpp:887 (14)
    //         0050507b     MOV        EAX,dword ptr [ESP + 0x1c]
    //         0050507f     MOV        EDX,dword ptr [EAX + 0xc]
    //         00505082     CMP        word ptr [EDX + 0x4a],0x0
    //         00505087     JNZ        LAB_00505100
    //                              taiuaimd.cpp:891 (5)
    //         00505089     CMP        this,-0x1
    //         0050508c     JZ         LAB_005050e7
    //                              taiuaimd.cpp:898 (45)
    //         0050508e     MOV        EAX,dword ptr [ESI + 0x2c]
    //         00505091     MOV        EDX,dword ptr [ESI + 0x48]
    //         00505094     PUSH       EAX
    //         00505095     MOV        EAX,dword ptr [ESI + 0x44]
    //         00505098     PUSH       0x0
    //         0050509a     PUSH       0x0
    //         0050509c     PUSH       EDX
    //         0050509d     MOV        EDX,dword ptr [ESI + 0x40]
    //         005050a0     PUSH       EAX
    //         005050a1     MOV        EAX,dword ptr [ESI + 0x3c]
    //         005050a4     MOV        EDI,dword ptr [ESI]
    //         005050a6     PUSH       EDX
    //         005050a7     MOV        EDX,dword ptr [ESI + 0x34]
    //         005050aa     PUSH       EAX
    //         005050ab     MOV        EAX,dword ptr [ESI + 0x4]
    //         005050ae     PUSH       -0x1
    //         005050b0     PUSH       EDX
    //         005050b1     PUSH       this
    //         005050b2     MOV        this,dword ptr [EAX + 0x4]
    //         005050b5     PUSH       this
    //         005050b6     MOV        this,ESI
    //         005050b8     CALL       dword ptr [EDI + 0x10]
    //                              taiuaimd.cpp:899 (7)
    //         005050bb     MOV        dword ptr [ESI + 0x28],0x2bc
    //                              taiuaimd.cpp:900 (7)
    //         005050c2     MOV        dword ptr [ESI + 0x2c],0x64
    //                              taiuaimd.cpp:901 (10)
    //         005050c9     MOV        EDX,dword ptr [EBX]
    //         005050cb     PUSH       0x1
    //         005050cd     PUSH       EDX
    //         005050ce     MOV        this,ESI
    //         005050d0     CALL       dword ptr [EDI + 0x5c]
    //                              taiuaimd.cpp:902 (7)
    //         005050d3     MOV        byte ptr [ESI + 0x130],0x1
    //                              taiuaimd.cpp:1211 (5)
    //         005050da     MOV        EAX,0x3
    //                              taiuaimd.cpp:1237 (8)
    //         005050df     POP        EDI
    //         005050e0     POP        ESI
    //         005050e1     POP        EBP
    //         005050e2     POP        EBX
    //         005050e3     POP        this
    //         005050e4     RET        0x8
    //                               LAB_005050e7                                                 XREF[1]:     0050508c(j)  
    //                              taiuaimd.cpp:908 (12)
    //         005050e7     MOV        this,dword ptr [EBX]
    //         005050e9     MOV        EAX,dword ptr [ESI]
    //         005050eb     PUSH       0x1
    //         005050ed     PUSH       this
    //         005050ee     MOV        this,ESI
    //         005050f0     CALL       dword ptr [EAX + 0x5c]
    //                              taiuaimd.cpp:910 (5)
    //         005050f3     MOV        EAX,0x3
    //                              taiuaimd.cpp:1237 (8)
    //         005050f8     POP        EDI
    //         005050f9     POP        ESI
    //         005050fa     POP        EBP
    //         005050fb     POP        EBX
    //         005050fc     POP        this
    //         005050fd     RET        0x8
    //                               LAB_00505100                                                 XREF[1]:     00505087(j)  
    //                              taiuaimd.cpp:912 (30)
    //         00505100     CMP        dword ptr [ESI + 0x30],0x262
    //         00505107     JNZ        LAB_0050511e
    //         00505109     FLD        float ptr [ESP + 0x18]
    //         0050510d     FCOMP      float ptr [DAT_005758c4]
    //         00505113     FNSTSW     AX
    //         00505115     TEST       AH,0x40
    //         00505118     JZ         LAB_005056f0
    //                               LAB_0050511e                                                 XREF[1]:     00505107(j)  
    //                              taiuaimd.cpp:920 (45)
    //         0050511e     MOV        EDX,dword ptr [ESI + 0x2c]
    //         00505121     MOV        EAX,dword ptr [ESI + 0x48]
    //         00505124     PUSH       EDX
    //         00505125     MOV        EDX,dword ptr [ESI + 0x44]
    //         00505128     PUSH       0x0
    //         0050512a     PUSH       0x0
    //         0050512c     PUSH       EAX
    //         0050512d     MOV        EAX,dword ptr [ESI + 0x40]
    //         00505130     PUSH       EDX
    //         00505131     MOV        EDX,dword ptr [ESI + 0x3c]
    //         00505134     PUSH       EAX
    //         00505135     MOV        EAX,dword ptr [ESI + 0x34]
    //         00505138     MOV        EDI,dword ptr [ESI]
    //         0050513a     PUSH       EDX
    //         0050513b     PUSH       -0x1
    //         0050513d     PUSH       EAX
    //         0050513e     PUSH       this
    //         0050513f     MOV        this,dword ptr [ESI + 0x4]
    //         00505142     MOV        EDX,dword ptr [ECX + this->field4_0x4]
    //         00505145     MOV        this,ESI
    //         00505147     PUSH       EDX
    //         00505148     CALL       dword ptr [EDI + 0x10]
    //                              taiuaimd.cpp:922 (50)
    //         0050514b     MOV        this,dword ptr [actionFile]                      = 00000000
    //         00505151     TEST       this,this
    //         00505153     JZ         LAB_0050517d
    //         00505155     MOV        EAX,dword ptr [ESI + 0x4]
    //         00505158     TEST       EAX,EAX
    //         0050515a     JZ         LAB_00505161
    //         0050515c     MOV        EAX,dword ptr [EAX + 0x4]
    //         0050515f     JMP        LAB_00505164
    //                               LAB_00505161                                                 XREF[1]:     0050515a(j)  
    //         00505161     OR         EAX,0xffffffff
    //                               LAB_00505164                                                 XREF[1]:     0050515f(j)  
    //         00505164     PUSH       0x39a
    //         00505169     PUSH       s_C:\msdev\work\age1_x1\taiuaimd.c               = "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp"
    //         0050516e     PUSH       EAX
    //         0050516f     PUSH       s_#%d_call_stopObject_%s_%d_                     = "#%d call stopObject %s %d\n"
    //         00505174     PUSH       this
    //         00505175     CALL       fprintf                                          undefined fprintf()
    //         0050517a     ADD        ESP,0x14
    //                               LAB_0050517d                                                 XREF[1]:     00505153(j)  
    //                              taiuaimd.cpp:924 (7)
    //         0050517d     PUSH       0x1
    //         0050517f     MOV        this,ESI
    //         00505181     CALL       dword ptr [EDI + 0x58]
    //                              taiuaimd.cpp:925 (10)
    //         00505184     PUSH       0x1
    //         00505186     MOV        this,ESI
    //         00505188     CALL       dword ptr [EDI + 0xa4]
    //                              taiuaimd.cpp:927 (5)
    //         0050518e     MOV        EAX,0x3
    //                              taiuaimd.cpp:1237 (8)
    //         00505193     POP        EDI
    //         00505194     POP        ESI
    //         00505195     POP        EBP
    //         00505196     POP        EBX
    //         00505197     POP        this
    //         00505198     RET        0x8
    //                               switchD_00504e34::caseD_1fa                                  XREF[2]:     00504e34(j), 005057c8(*)  
    //                              taiuaimd.cpp:935 (14)
    //         0050519b     MOV        EAX,dword ptr [ESI + 0x30]
    //         0050519e     MOV        this,dword ptr [EBX + 0xc]
    //         005051a1     CMP        EAX,this
    //         005051a3     JNZ        LAB_0050579c
    //                              taiuaimd.cpp:936 (7)
    //         005051a9     MOV        this,ESI
    //         005051ab     CALL       UnitAIModule::removeCurrentTarget                void removeCurrentTarget(UnitAIModule * this)
    //                              taiuaimd.cpp:938 (51)
    //         005051b0     MOV        this,dword ptr [actionFile]                      = 00000000
    //         005051b6     TEST       this,this
    //         005051b8     JZ         LAB_0050578d
    //         005051be     MOV        EAX,dword ptr [ESI + 0x4]
    //         005051c1     TEST       EAX,EAX
    //         005051c3     JZ         LAB_005051ca
    //         005051c5     MOV        EAX,dword ptr [EAX + 0x4]
    //         005051c8     JMP        LAB_005051cd
    //                               LAB_005051ca                                                 XREF[1]:     005051c3(j)  
    //         005051ca     OR         EAX,0xffffffff
    //                               LAB_005051cd                                                 XREF[1]:     005051c8(j)  
    //         005051cd     PUSH       0x3aa
    //         005051d2     PUSH       s_C:\msdev\work\age1_x1\taiuaimd.c               = "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp"
    //         005051d7     PUSH       EAX
    //         005051d8     PUSH       s_#%d_call_stopObject_%s_%d_                     = "#%d call stopObject %s %d\n"
    //         005051dd     PUSH       this
    //         005051de     CALL       fprintf                                          undefined fprintf()
    //                              taiuaimd.cpp:940 (12)
    //         005051e3     MOV        EDI,dword ptr [ESI]
    //         005051e5     ADD        ESP,0x14
    //         005051e8     MOV        this,ESI
    //         005051ea     PUSH       0x1
    //         005051ec     CALL       dword ptr [EDI + 0x58]
    //                              taiuaimd.cpp:941 (6)
    //         005051ef     PUSH       EBX
    //         005051f0     MOV        this,ESI
    //         005051f2     CALL       dword ptr [EDI + 0x1c]
    //                              taiuaimd.cpp:943 (5)
    //         005051f5     MOV        EAX,0x2
    //                              taiuaimd.cpp:1237 (8)
    //         005051fa     POP        EDI
    //         005051fb     POP        ESI
    //         005051fc     POP        EBP
    //         005051fd     POP        EBX
    //         005051fe     POP        this
    //         005051ff     RET        0x8
    //                               switchD_00504e34::caseD_1f9                                  XREF[2]:     00504e34(j), 005057c4(*)  
    //                              taiuaimd.cpp:950 (14)
    //         00505202     MOV        this,dword ptr [ESI + 0x30]
    //         00505205     MOV        EAX,dword ptr [EBX + 0xc]
    //         00505208     CMP        this,EAX
    //         0050520a     JNZ        LAB_0050579c
    //                              taiuaimd.cpp:951 (7)
    //         00505210     MOV        this,ESI
    //         00505212     CALL       UnitAIModule::removeCurrentTarget                void removeCurrentTarget(UnitAIModule * this)
    //                              taiuaimd.cpp:953 (51)
    //         00505217     MOV        this,dword ptr [actionFile]                      = 00000000
    //         0050521d     TEST       this,this
    //         0050521f     JZ         LAB_0050578d
    //         00505225     MOV        EAX,dword ptr [ESI + 0x4]
    //         00505228     TEST       EAX,EAX
    //         0050522a     JZ         LAB_00505231
    //         0050522c     MOV        EAX,dword ptr [EAX + 0x4]
    //         0050522f     JMP        LAB_00505234
    //                               LAB_00505231                                                 XREF[1]:     0050522a(j)  
    //         00505231     OR         EAX,0xffffffff
    //                               LAB_00505234                                                 XREF[1]:     0050522f(j)  
    //         00505234     PUSH       0x3b9
    //         00505239     PUSH       s_C:\msdev\work\age1_x1\taiuaimd.c               = "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp"
    //         0050523e     PUSH       EAX
    //         0050523f     PUSH       s_#%d_call_stopObject_%s_%d_                     = "#%d call stopObject %s %d\n"
    //         00505244     PUSH       this
    //         00505245     CALL       fprintf                                          undefined fprintf()
    //                              taiuaimd.cpp:955 (12)
    //         0050524a     MOV        EDI,dword ptr [ESI]
    //         0050524c     ADD        ESP,0x14
    //         0050524f     MOV        this,ESI
    //         00505251     PUSH       0x1
    //         00505253     CALL       dword ptr [EDI + 0x58]
    //                              taiuaimd.cpp:956 (6)
    //         00505256     PUSH       EBX
    //         00505257     MOV        this,ESI
    //         00505259     CALL       dword ptr [EDI + 0x1c]
    //                              taiuaimd.cpp:958 (5)
    //         0050525c     MOV        EAX,0x2
    //                              taiuaimd.cpp:1237 (8)
    //         00505261     POP        EDI
    //         00505262     POP        ESI
    //         00505263     POP        EBP
    //         00505264     POP        EBX
    //         00505265     POP        this
    //         00505266     RET        0x8
    //                               switchD_00504e34::caseD_202                                  XREF[3]:     00504e34(j), 005057cc(*), 
    //                               switchD_00504e34::caseD_1fb                                               005057d0(*)  
    //                              taiuaimd.cpp:968 (14)
    //         00505269     MOV        EAX,dword ptr [ESI + 0x30]
    //         0050526c     CMP        EAX,0x265
    //         00505271     JNZ        LAB_005053b9
    //                              taiuaimd.cpp:969 (3)
    //         00505277     MOV        EBX,dword ptr [ESI + 0x38]
    //                              taiuaimd.cpp:970 (5)
    //         0050527a     CMP        EBX,-0x1
    //         0050527d     JNZ        LAB_005052e0
    //                              taiuaimd.cpp:971 (3)
    //         0050527f     MOV        EBX,dword ptr [ESI + 0x5c]
    //                              taiuaimd.cpp:972 (5)
    //         00505282     CMP        EBX,-0x1
    //         00505285     JNZ        LAB_005052e0
    //                              taiuaimd.cpp:977 (7)
    //         00505287     MOV        this,ESI
    //         00505289     CALL       UnitAIModule::removeCurrentTarget                void removeCurrentTarget(UnitAIModule * this)
    //                              taiuaimd.cpp:979 (50)
    //         0050528e     MOV        this,dword ptr [actionFile]                      = 00000000
    //         00505294     TEST       this,this
    //         00505296     JZ         LAB_005052c0
    //         00505298     MOV        EAX,dword ptr [ESI + 0x4]
    //         0050529b     TEST       EAX,EAX
    //         0050529d     JZ         LAB_005052a4
    //         0050529f     MOV        EAX,dword ptr [EAX + 0x4]
    //         005052a2     JMP        LAB_005052a7
    //                               LAB_005052a4                                                 XREF[1]:     0050529d(j)  
    //         005052a4     OR         EAX,0xffffffff
    //                               LAB_005052a7                                                 XREF[1]:     005052a2(j)  
    //         005052a7     PUSH       0x3d3
    //         005052ac     PUSH       s_C:\msdev\work\age1_x1\taiuaimd.c               = "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp"
    //         005052b1     PUSH       EAX
    //         005052b2     PUSH       s_#%d_call_stopObject_%s_%d_                     = "#%d call stopObject %s %d\n"
    //         005052b7     PUSH       this
    //         005052b8     CALL       fprintf                                          undefined fprintf()
    //         005052bd     ADD        ESP,0x14
    //                               LAB_005052c0                                                 XREF[1]:     00505296(j)  
    //                              taiuaimd.cpp:981 (9)
    //         005052c0     MOV        EDI,dword ptr [ESI]
    //         005052c2     PUSH       0x1
    //         005052c4     MOV        this,ESI
    //         005052c6     CALL       dword ptr [EDI + 0x58]
    //                              taiuaimd.cpp:982 (10)
    //         005052c9     MOV        EDX,dword ptr [ESP + 0x18]
    //         005052cd     MOV        this,ESI
    //         005052cf     PUSH       EDX
    //         005052d0     CALL       dword ptr [EDI + 0x1c]
    //                              taiuaimd.cpp:983 (5)
    //         005052d3     MOV        EAX,0x2
    //                              taiuaimd.cpp:1237 (8)
    //         005052d8     POP        EDI
    //         005052d9     POP        ESI
    //         005052da     POP        EBP
    //         005052db     POP        EBX
    //         005052dc     POP        this
    //         005052dd     RET        0x8
    //                               LAB_005052e0                                                 XREF[2]:     0050527d(j), 00505285(j)  
    //                              taiuaimd.cpp:986 (11)
    //         005052e0     MOV        EDI,dword ptr [ESI]
    //         005052e2     PUSH       EBX
    //         005052e3     MOV        this,ESI
    //         005052e5     CALL       dword ptr [EDI + 0xc0]
    //                              taiuaimd.cpp:994 (3)
    //         005052eb     CMP        EAX,-0x1
    //                              taiuaimd.cpp:995 (10)
    //         005052ee     PUSH       0x0
    //         005052f0     JZ         LAB_005052fa
    //         005052f2     PUSH       EAX
    //         005052f3     MOV        this,ESI
    //         005052f5     CALL       dword ptr [EDI + 0x44]
    //                              taiuaimd.cpp:996 (2)
    //         005052f8     JMP        LAB_00505306
    //                               LAB_005052fa                                                 XREF[1]:     005052f0(j)  
    //                              taiuaimd.cpp:997 (12)
    //         005052fa     PUSH       -0x1
    //         005052fc     PUSH       -0x1
    //         005052fe     PUSH       -0x1
    //         00505300     PUSH       EBX
    //         00505301     MOV        this,ESI
    //         00505303     CALL       dword ptr [EDI + 0x40]
    //                               LAB_00505306                                                 XREF[1]:     005052f8(j)  
    //                              taiuaimd.cpp:1002 (5)
    //         00505306     CMP        EAX,-0x1
    //         00505309     JZ         LAB_0050536f
    //                              taiuaimd.cpp:1006 (13)
    //         0050530b     PUSH       0x1
    //         0050530d     PUSH       EAX
    //         0050530e     MOV        this,ESI
    //         00505310     CALL       dword ptr [EDI + 0x64]
    //         00505313     CMP        EAX,0x1
    //         00505316     JNZ        LAB_00505325
    //                              taiuaimd.cpp:1007 (5)
    //         00505318     MOV        EAX,0x3
    //                              taiuaimd.cpp:1237 (8)
    //         0050531d     POP        EDI
    //         0050531e     POP        ESI
    //         0050531f     POP        EBP
    //         00505320     POP        EBX
    //         00505321     POP        this
    //         00505322     RET        0x8
    //                               LAB_00505325                                                 XREF[1]:     00505316(j)  
    //                              taiuaimd.cpp:1012 (7)
    //         00505325     MOV        this,ESI
    //         00505327     CALL       UnitAIModule::removeCurrentTarget                void removeCurrentTarget(UnitAIModule * this)
    //                              taiuaimd.cpp:1014 (50)
    //         0050532c     MOV        this,dword ptr [actionFile]                      = 00000000
    //         00505332     TEST       this,this
    //         00505334     JZ         LAB_0050535e
    //         00505336     MOV        EAX,dword ptr [ESI + 0x4]
    //         00505339     TEST       EAX,EAX
    //         0050533b     JZ         LAB_00505342
    //         0050533d     MOV        EAX,dword ptr [EAX + 0x4]
    //         00505340     JMP        LAB_00505345
    //                               LAB_00505342                                                 XREF[1]:     0050533b(j)  
    //         00505342     OR         EAX,0xffffffff
    //                               LAB_00505345                                                 XREF[1]:     00505340(j)  
    //         00505345     PUSH       0x3f6
    //         0050534a     PUSH       s_C:\msdev\work\age1_x1\taiuaimd.c               = "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp"
    //         0050534f     PUSH       EAX
    //         00505350     PUSH       s_#%d_call_stopObject_%s_%d_                     = "#%d call stopObject %s %d\n"
    //         00505355     PUSH       this
    //         00505356     CALL       fprintf                                          undefined fprintf()
    //         0050535b     ADD        ESP,0x14
    //                               LAB_0050535e                                                 XREF[1]:     00505334(j)  
    //                              taiuaimd.cpp:1016 (7)
    //         0050535e     PUSH       0x1
    //         00505360     MOV        this,ESI
    //         00505362     CALL       dword ptr [EDI + 0x58]
    //                              taiuaimd.cpp:1017 (5)
    //         00505365     MOV        EAX,dword ptr [ESP + 0x18]
    //         00505369     PUSH       EAX
    //                              taiuaimd.cpp:1020 (25)
    //         0050536a     JMP        LAB_00505742
    //                               LAB_0050536f                                                 XREF[1]:     00505309(j)  
    //         0050536f     MOV        this,dword ptr [ESI + 0x4]
    //         00505372     MOV        this,dword ptr [ECX + this->field12_0xc]
    //         00505375     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
    //         0050537a     CMP        EAX,0x1
    //         0050537d     JNZ        LAB_00505747
    //                              taiuaimd.cpp:1037 (7)
    //         00505383     MOV        this,ESI
    //         00505385     CALL       UnitAIModule::removeCurrentTarget                void removeCurrentTarget(UnitAIModule * this)
    //                              taiuaimd.cpp:1039 (29)
    //         0050538a     MOV        this,dword ptr [actionFile]                      = 00000000
    //         00505390     TEST       this,this
    //         00505392     JZ         LAB_00505736
    //         00505398     MOV        EAX,dword ptr [ESI + 0x4]
    //         0050539b     TEST       EAX,EAX
    //         0050539d     JZ         LAB_005053ac
    //         0050539f     MOV        EAX,dword ptr [EAX + 0x4]
    //         005053a2     PUSH       0x40f
    //                              taiuaimd.cpp:1045 (5)
    //         005053a7     JMP        LAB_00505722
    //                               LAB_005053ac                                                 XREF[1]:     0050539d(j)  
    //                              taiuaimd.cpp:1039 (8)
    //         005053ac     OR         EAX,0xffffffff
    //         005053af     PUSH       0x40f
    //                              taiuaimd.cpp:1045 (16)
    //         005053b4     JMP        LAB_00505722
    //                               LAB_005053b9                                                 XREF[1]:     00505271(j)  
    //         005053b9     CMP        EAX,0x261
    //         005053be     JNZ        LAB_00505592
    //                              taiuaimd.cpp:1046 (3)
    //         005053c4     MOV        EBX,dword ptr [ESI + 0x38]
    //                              taiuaimd.cpp:1047 (5)
    //         005053c7     CMP        EBX,-0x1
    //         005053ca     JNZ        LAB_0050542d
    //                              taiuaimd.cpp:1048 (3)
    //         005053cc     MOV        EBX,dword ptr [ESI + 0x5c]
    //                              taiuaimd.cpp:1050 (5)
    //         005053cf     CMP        EBX,-0x1
    //         005053d2     JNZ        LAB_0050542d
    //                              taiuaimd.cpp:1055 (7)
    //         005053d4     MOV        this,ESI
    //         005053d6     CALL       UnitAIModule::removeCurrentTarget                void removeCurrentTarget(UnitAIModule * this)
    //                              taiuaimd.cpp:1057 (50)
    //         005053db     MOV        this,dword ptr [actionFile]                      = 00000000
    //         005053e1     TEST       this,this
    //         005053e3     JZ         LAB_0050540d
    //         005053e5     MOV        EAX,dword ptr [ESI + 0x4]
    //         005053e8     TEST       EAX,EAX
    //         005053ea     JZ         LAB_005053f1
    //         005053ec     MOV        EAX,dword ptr [EAX + 0x4]
    //         005053ef     JMP        LAB_005053f4
    //                               LAB_005053f1                                                 XREF[1]:     005053ea(j)  
    //         005053f1     OR         EAX,0xffffffff
    //                               LAB_005053f4                                                 XREF[1]:     005053ef(j)  
    //         005053f4     PUSH       0x421
    //         005053f9     PUSH       s_C:\msdev\work\age1_x1\taiuaimd.c               = "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp"
    //         005053fe     PUSH       EAX
    //         005053ff     PUSH       s_#%d_call_stopObject_%s_%d_                     = "#%d call stopObject %s %d\n"
    //         00505404     PUSH       this
    //         00505405     CALL       fprintf                                          undefined fprintf()
    //         0050540a     ADD        ESP,0x14
    //                               LAB_0050540d                                                 XREF[1]:     005053e3(j)  
    //                              taiuaimd.cpp:1059 (9)
    //         0050540d     MOV        EDI,dword ptr [ESI]
    //         0050540f     PUSH       0x1
    //         00505411     MOV        this,ESI
    //         00505413     CALL       dword ptr [EDI + 0x58]
    //                              taiuaimd.cpp:1060 (10)
    //         00505416     MOV        EAX,dword ptr [ESP + 0x18]
    //         0050541a     MOV        this,ESI
    //         0050541c     PUSH       EAX
    //         0050541d     CALL       dword ptr [EDI + 0x1c]
    //                              taiuaimd.cpp:1061 (5)
    //         00505420     MOV        EAX,0x2
    //                              taiuaimd.cpp:1237 (8)
    //         00505425     POP        EDI
    //         00505426     POP        ESI
    //         00505427     POP        EBP
    //         00505428     POP        EBX
    //         00505429     POP        this
    //         0050542a     RET        0x8
    //                               LAB_0050542d                                                 XREF[2]:     005053ca(j), 005053d2(j)  
    //                              taiuaimd.cpp:1064 (11)
    //         0050542d     MOV        EDI,dword ptr [ESI]
    //         0050542f     PUSH       EBX
    //         00505430     MOV        this,ESI
    //         00505432     CALL       dword ptr [EDI + 0xc0]
    //                              taiuaimd.cpp:1070 (10)
    //         00505438     CMP        EAX,-0x1
    //         0050543b     MOV        EBP,0x32
    //         00505440     JZ         LAB_0050544c
    //                              taiuaimd.cpp:1071 (8)
    //         00505442     PUSH       0x0
    //         00505444     PUSH       EAX
    //         00505445     MOV        this,ESI
    //         00505447     CALL       dword ptr [EDI + 0x44]
    //                              taiuaimd.cpp:1072 (2)
    //         0050544a     JMP        LAB_00505468
    //                               LAB_0050544c                                                 XREF[1]:     00505440(j)  
    //                              taiuaimd.cpp:1073 (4)
    //         0050544c     MOV        this,dword ptr [ESP + 0x18]
    //                              taiuaimd.cpp:1074 (11)
    //         00505450     PUSH       0x0
    //         00505452     CMP        dword ptr [ECX + this->field16_0x10],EBP
    //         00505455     JZ         LAB_0050545d
    //         00505457     PUSH       -0x1
    //         00505459     PUSH       -0x1
    //                              taiuaimd.cpp:1075 (2)
    //         0050545b     JMP        LAB_00505460
    //                               LAB_0050545d                                                 XREF[1]:     00505455(j)  
    //                              taiuaimd.cpp:1076 (11)
    //         0050545d     PUSH       EBP
    //         0050545e     PUSH       0x2
    //                               LAB_00505460                                                 XREF[1]:     0050545b(j)  
    //         00505460     PUSH       -0x1
    //         00505462     PUSH       EBX
    //         00505463     MOV        this,ESI
    //         00505465     CALL       dword ptr [EDI + 0x40]
    //                               LAB_00505468                                                 XREF[1]:     0050544a(j)  
    //                              taiuaimd.cpp:1082 (5)
    //         00505468     CMP        EAX,-0x1
    //         0050546b     JZ         LAB_005054bd
    //                              taiuaimd.cpp:1086 (13)
    //         0050546d     PUSH       0x1
    //         0050546f     PUSH       EAX
    //         00505470     MOV        this,ESI
    //         00505472     CALL       dword ptr [EDI + 0x68]
    //         00505475     CMP        EAX,0x1
    //         00505478     JNZ        LAB_00505487
    //                              taiuaimd.cpp:1087 (5)
    //         0050547a     MOV        EAX,0x3
    //                              taiuaimd.cpp:1237 (8)
    //         0050547f     POP        EDI
    //         00505480     POP        ESI
    //         00505481     POP        EBP
    //         00505482     POP        EBX
    //         00505483     POP        this
    //         00505484     RET        0x8
    //                               LAB_00505487                                                 XREF[1]:     00505478(j)  
    //                              taiuaimd.cpp:1092 (7)
    //         00505487     MOV        this,ESI
    //         00505489     CALL       UnitAIModule::removeCurrentTarget                void removeCurrentTarget(UnitAIModule * this)
    //                              taiuaimd.cpp:1094 (29)
    //         0050548e     MOV        this,dword ptr [actionFile]                      = 00000000
    //         00505494     TEST       this,this
    //         00505496     JZ         LAB_00505736
    //         0050549c     MOV        EAX,dword ptr [ESI + 0x4]
    //         0050549f     TEST       EAX,EAX
    //         005054a1     JZ         LAB_005054b0
    //         005054a3     MOV        EAX,dword ptr [EAX + 0x4]
    //         005054a6     PUSH       0x446
    //                              taiuaimd.cpp:1100 (5)
    //         005054ab     JMP        LAB_00505722
    //                               LAB_005054b0                                                 XREF[1]:     005054a1(j)  
    //                              taiuaimd.cpp:1094 (8)
    //         005054b0     OR         EAX,0xffffffff
    //         005054b3     PUSH       0x446
    //                              taiuaimd.cpp:1100 (5)
    //         005054b8     JMP        LAB_00505722
    //                               LAB_005054bd                                                 XREF[1]:     0050546b(j)  
    //                              taiuaimd.cpp:1101 (16)
    //         005054bd     MOV        EAX,dword ptr [ESI + 0x4]
    //         005054c0     MOV        this,dword ptr [EAX + 0xc]
    //         005054c3     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
    //         005054c8     CMP        EAX,0x1
    //         005054cb     JNZ        LAB_0050551b
    //                              taiuaimd.cpp:1105 (7)
    //         005054cd     MOV        this,ESI
    //         005054cf     CALL       UnitAIModule::removeCurrentTarget                void removeCurrentTarget(UnitAIModule * this)
    //                              taiuaimd.cpp:1107 (54)
    //         005054d4     MOV        this,dword ptr [actionFile]                      = 00000000
    //         005054da     TEST       this,this
    //         005054dc     JZ         LAB_005056e2
    //         005054e2     MOV        EAX,dword ptr [ESI + 0x4]
    //         005054e5     TEST       EAX,EAX
    //         005054e7     JZ         LAB_005054ee
    //         005054e9     MOV        EAX,dword ptr [EAX + 0x4]
    //         005054ec     JMP        LAB_005054f1
    //                               LAB_005054ee                                                 XREF[1]:     005054e7(j)  
    //         005054ee     OR         EAX,0xffffffff
    //                              language.dll match for 0x453: "Saving game..."
    //                               LAB_005054f1                                                 XREF[1]:     005054ec(j)  
    //         005054f1     PUSH       0x453
    //         005054f6     PUSH       s_C:\msdev\work\age1_x1\taiuaimd.c               = "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp"
    //         005054fb     PUSH       EAX
    //         005054fc     PUSH       s_#%d_call_stopObject_%s_%d_                     = "#%d call stopObject %s %d\n"
    //         00505501     PUSH       this
    //         00505502     CALL       fprintf                                          undefined fprintf()
    //         00505507     ADD        ESP,0x14
    //                              taiuaimd.cpp:1109 (7)
    //         0050550a     MOV        this,ESI
    //         0050550c     PUSH       0x1
    //         0050550e     CALL       dword ptr [EDI + 0x58]
    //                              taiuaimd.cpp:1110 (5)
    //         00505511     MOV        this,dword ptr [ESP + 0x18]
    //         00505515     PUSH       this
    //                              taiuaimd.cpp:1113 (18)
    //         00505516     JMP        LAB_00505742
    //                               LAB_0050551b                                                 XREF[1]:     005054cb(j)  
    //         0050551b     MOV        EDX,dword ptr [ESP + 0x18]
    //         0050551f     CMP        dword ptr [EDX + 0x10],EBP
    //         00505522     JNZ        LAB_00505747
    //                              taiuaimd.cpp:1115 (12)
    //         00505528     MOV        this,dword ptr [ESI + 0x4]
    //         0050552b     FLD        float ptr [ECX + this->field56_0x38]
    //         0050552e     FCOMP      float ptr [DAT_005758c8]
    //                              taiuaimd.cpp:1116 (16)
    //         00505534     FLD        float ptr [ECX + this->field56_0x38]
    //         00505537     FNSTSW     AX
    //         00505539     TEST       AH,0x41
    //         0050553c     JNZ        LAB_00505546
    //         0050553e     FSUB       float ptr [DAT_005758cc]
    //                              taiuaimd.cpp:1117 (2)
    //         00505544     JMP        LAB_0050554c
    //                               LAB_00505546                                                 XREF[1]:     0050553c(j)  
    //                              taiuaimd.cpp:1118 (10)
    //         00505546     FSUB       float ptr [DAT_005758d0]
    //                               LAB_0050554c                                                 XREF[1]:     00505544(j)  
    //         0050554c     FSTP       float ptr [ESP + 0x10]
    //                              taiuaimd.cpp:1120 (9)
    //         00505550     FLD        float ptr [ECX + this->field60_0x3c]
    //         00505553     FCOMP      float ptr [DAT_005758c8]
    //                              taiuaimd.cpp:1121 (16)
    //         00505559     FLD        float ptr [ECX + this->field60_0x3c]
    //         0050555c     FNSTSW     AX
    //         0050555e     TEST       AH,0x41
    //         00505561     JNZ        LAB_0050556b
    //         00505563     FSUB       float ptr [DAT_005758cc]
    //                              taiuaimd.cpp:1122 (2)
    //         00505569     JMP        LAB_00505571
    //                               LAB_0050556b                                                 XREF[1]:     00505561(j)  
    //                              taiuaimd.cpp:1123 (10)
    //         0050556b     FSUB       float ptr [DAT_005758d0]
    //                               LAB_00505571                                                 XREF[1]:     00505569(j)  
    //         00505571     FSTP       float ptr [ESP + 0x1c]
    //                              taiuaimd.cpp:1124 (24)
    //         00505575     MOV        EAX,dword ptr [ECX + this->field64_0x40]
    //         00505578     MOV        this,dword ptr [ESP + 0x1c]
    //         0050557c     MOV        EDX,dword ptr [ESP + 0x10]
    //         00505580     PUSH       0x1
    //         00505582     PUSH       EAX
    //         00505583     PUSH       this
    //         00505584     PUSH       EDX
    //         00505585     MOV        this,ESI
    //         00505587     CALL       dword ptr [EDI + 0x9c]
    //                              taiuaimd.cpp:1128 (16)
    //         0050558d     JMP        LAB_00505747
    //                               LAB_00505592                                                 XREF[1]:     005053be(j)  
    //         00505592     CMP        EAX,0x25a
    //         00505597     JNZ        LAB_0050565d
    //                              taiuaimd.cpp:1136 (23)
    //         0050559d     MOV        EBP,dword ptr [ESI]
    //         0050559f     MOV        EAX,dword ptr [ESI + 0x38]
    //         005055a2     PUSH       0x0
    //         005055a4     PUSH       -0x1
    //         005055a6     MOV        EBX,dword ptr [EBP + 0x40]
    //         005055a9     PUSH       0x0
    //         005055ab     PUSH       0x3
    //         005055ad     PUSH       EAX
    //         005055ae     MOV        this,ESI
    //         005055b0     CALL       EBX
    //         005055b2     MOV        EDI,EAX
    //                              taiuaimd.cpp:1137 (5)
    //         005055b4     CMP        EDI,-0x1
    //         005055b7     JNZ        LAB_005055d9
    //                              taiuaimd.cpp:1141 (3)
    //         005055b9     MOV        EAX,dword ptr [ESI + 0x38]
    //                              taiuaimd.cpp:1143 (14)
    //         005055bc     PUSH       0x0
    //         005055be     PUSH       EDI
    //         005055bf     CMP        EAX,0x1b
    //         005055c2     PUSH       0x0
    //         005055c4     PUSH       0x3
    //         005055c6     JNZ        LAB_005055cc
    //         005055c8     PUSH       0x3
    //                              taiuaimd.cpp:1144 (2)
    //         005055ca     JMP        LAB_005055ce
    //                               LAB_005055cc                                                 XREF[1]:     005055c6(j)  
    //                              taiuaimd.cpp:1146 (8)
    //         005055cc     PUSH       0x1b
    //                               LAB_005055ce                                                 XREF[1]:     005055ca(j)  
    //         005055ce     MOV        this,ESI
    //         005055d0     CALL       EBX
    //         005055d2     MOV        EDI,EAX
    //                              taiuaimd.cpp:1154 (35)
    //         005055d4     CMP        EDI,-0x1
    //         005055d7     JZ         LAB_00505614
    //                               LAB_005055d9                                                 XREF[1]:     005055b7(j)  
    //         005055d9     MOV        this,dword ptr [ESI + 0x4]
    //         005055dc     PUSH       -0x1
    //         005055de     PUSH       -0x1
    //         005055e0     PUSH       0x0
    //         005055e2     MOV        EDX,dword ptr [this->field0_0x0]
    //         005055e4     PUSH       0x0
    //         005055e6     PUSH       0x3f800000
    //         005055eb     PUSH       EDI
    //         005055ec     CALL       dword ptr [EDX + 0x194]
    //         005055f2     CMP        EAX,0x1
    //         005055f5     JNZ        LAB_00505614
    //                              taiuaimd.cpp:1158 (16)
    //         005055f7     PUSH       EAX
    //         005055f8     PUSH       EDI
    //         005055f9     MOV        this,ESI
    //         005055fb     CALL       dword ptr [EBP + 0x78]
    //         005055fe     CMP        EAX,0x1
    //         00505601     JNZ        LAB_00505747
    //                              taiuaimd.cpp:1159 (5)
    //         00505607     MOV        EAX,0x3
    //                              taiuaimd.cpp:1237 (8)
    //         0050560c     POP        EDI
    //         0050560d     POP        ESI
    //         0050560e     POP        EBP
    //         0050560f     POP        EBX
    //         00505610     POP        this
    //         00505611     RET        0x8
    //                               LAB_00505614                                                 XREF[2]:     005055d7(j), 005055f5(j)  
    //                              taiuaimd.cpp:1177 (11)
    //         00505614     MOV        EAX,dword ptr [ESI + 0x34]
    //         00505617     MOV        this,ESI
    //         00505619     PUSH       EAX
    //         0050561a     CALL       UnitAIModule::lookupObject                       RGE_Static_Object * lookupObject(UnitAIModule
    //                              taiuaimd.cpp:1178 (4)
    //         0050561f     TEST       EAX,EAX
    //         00505621     JZ         LAB_0050563d
    //                              taiuaimd.cpp:1180 (26)
    //         00505623     MOV        this,dword ptr [ESI + 0x4]
    //         00505626     PUSH       EAX
    //         00505627     CALL       RGE_Static_Object::distance_to_object            float distance_to_object(RGE_Static_Object * 
    //         0050562c     FCOMP      float ptr [DAT_005758bc]
    //         00505632     FNSTSW     AX
    //         00505634     TEST       AH,0x41
    //         00505637     JNZ        LAB_00505747
    //                               LAB_0050563d                                                 XREF[1]:     00505621(j)  
    //                              taiuaimd.cpp:1184 (27)
    //         0050563d     MOV        this,dword ptr [ESI + 0x44]
    //         00505640     MOV        EDX,dword ptr [ESI + 0x40]
    //         00505643     MOV        EAX,dword ptr [ESI + 0x3c]
    //         00505646     PUSH       0x1
    //         00505648     PUSH       0x3f800000
    //         0050564d     PUSH       this
    //         0050564e     PUSH       EDX
    //         0050564f     PUSH       EAX
    //         00505650     MOV        this,ESI
    //         00505652     CALL       dword ptr [EBP + 0x90]
    //                              taiuaimd.cpp:1187 (16)
    //         00505658     JMP        LAB_00505747
    //                               LAB_0050565d                                                 XREF[1]:     00505597(j)  
    //         0050565d     CMP        EAX,0x25d
    //         00505662     JNZ        LAB_00505747
    //                              taiuaimd.cpp:1193 (24)
    //         00505668     MOV        EDI,dword ptr [ESI]
    //         0050566a     LEA        this=>param_2,[ESP + 0x1c]
    //         0050566e     PUSH       0x1
    //         00505670     LEA        EDX=>local_4,[ESP + 0x14]
    //         00505674     PUSH       this
    //         00505675     PUSH       EDX
    //         00505676     MOV        this,ESI
    //         00505678     CALL       dword ptr [EDI + 0x48]
    //         0050567b     CMP        EAX,0x1
    //         0050567e     JNZ        LAB_005056fd
    //                              taiuaimd.cpp:1194 (17)
    //         00505680     MOV        EAX,dword ptr [ESP + 0x1c]
    //         00505684     MOV        this,dword ptr [ESP + 0x10]
    //         00505688     PUSH       EAX
    //         00505689     PUSH       this
    //         0050568a     MOV        this,ESI
    //         0050568c     CALL       UnitAIModule::addToWaypointQueue                 int addToWaypointQueue(UnitAIModule * this, i
    //                              taiuaimd.cpp:1198 (24)
    //         00505691     MOV        EDX,dword ptr [ESP + 0x1c]
    //         00505695     MOV        EAX,dword ptr [ESP + 0x10]
    //         00505699     PUSH       0x1
    //         0050569b     PUSH       EDX
    //         0050569c     PUSH       EAX
    //         0050569d     MOV        this,ESI
    //         0050569f     CALL       dword ptr [EDI + 0x80]
    //         005056a5     TEST       EAX,EAX
    //         005056a7     JNZ        LAB_005056f0
    //                              taiuaimd.cpp:1202 (7)
    //         005056a9     MOV        this,ESI
    //         005056ab     CALL       UnitAIModule::removeCurrentTarget                void removeCurrentTarget(UnitAIModule * this)
    //                              taiuaimd.cpp:1204 (50)
    //         005056b0     MOV        this,dword ptr [actionFile]                      = 00000000
    //         005056b6     TEST       this,this
    //         005056b8     JZ         LAB_005056e2
    //         005056ba     MOV        EAX,dword ptr [ESI + 0x4]
    //         005056bd     TEST       EAX,EAX
    //         005056bf     JZ         LAB_005056c6
    //         005056c1     MOV        EAX,dword ptr [EAX + 0x4]
    //         005056c4     JMP        LAB_005056c9
    //                               LAB_005056c6                                                 XREF[1]:     005056bf(j)  
    //         005056c6     OR         EAX,0xffffffff
    //                              language.dll match for 0x4b4: "Waiting"
    //                               LAB_005056c9                                                 XREF[1]:     005056c4(j)  
    //         005056c9     PUSH       0x4b4
    //         005056ce     PUSH       s_C:\msdev\work\age1_x1\taiuaimd.c               = "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp"
    //         005056d3     PUSH       EAX
    //         005056d4     PUSH       s_#%d_call_stopObject_%s_%d_                     = "#%d call stopObject %s %d\n"
    //         005056d9     PUSH       this
    //         005056da     CALL       fprintf                                          undefined fprintf()
    //         005056df     ADD        ESP,0x14
    //                               LAB_005056e2                                                 XREF[2]:     005054dc(j), 005056b8(j)  
    //                              taiuaimd.cpp:1206 (7)
    //         005056e2     PUSH       0x1
    //         005056e4     MOV        this,ESI
    //         005056e6     CALL       dword ptr [EDI + 0x58]
    //                              taiuaimd.cpp:1207 (5)
    //         005056e9     MOV        this,dword ptr [ESP + 0x18]
    //         005056ed     PUSH       this
    //                              taiuaimd.cpp:1213 (2)
    //         005056ee     JMP        LAB_00505742
    //                               LAB_005056f0                                                 XREF[2]:     00505118(j), 005056a7(j)  
    //                              taiuaimd.cpp:1211 (5)
    //         005056f0     MOV        EAX,0x3
    //                              taiuaimd.cpp:1237 (8)
    //         005056f5     POP        EDI
    //         005056f6     POP        ESI
    //         005056f7     POP        EBP
    //         005056f8     POP        EBX
    //         005056f9     POP        this
    //         005056fa     RET        0x8
    //                               LAB_005056fd                                                 XREF[1]:     0050567e(j)  
    //                              taiuaimd.cpp:1217 (7)
    //         005056fd     MOV        this,ESI
    //         005056ff     CALL       UnitAIModule::removeCurrentTarget                void removeCurrentTarget(UnitAIModule * this)
    //                              taiuaimd.cpp:1219 (50)
    //         00505704     MOV        this,dword ptr [actionFile]                      = 00000000
    //         0050570a     TEST       this,this
    //         0050570c     JZ         LAB_00505736
    //         0050570e     MOV        EAX,dword ptr [ESI + 0x4]
    //         00505711     TEST       EAX,EAX
    //         00505713     JZ         LAB_0050571a
    //         00505715     MOV        EAX,dword ptr [EAX + 0x4]
    //         00505718     JMP        LAB_0050571d
    //                               LAB_0050571a                                                 XREF[1]:     00505713(j)  
    //         0050571a     OR         EAX,0xffffffff
    //                              language.dll match for 0x4c3: "Creating multiplayer game...\\
    //                               LAB_0050571d                                                 XREF[1]:     00505718(j)  
    //         0050571d     PUSH       0x4c3
    //                               LAB_00505722                                                 XREF[4]:     005053a7(j), 005053b4(j), 
    //                                                                                                         005054ab(j), 005054b8(j)  
    //         00505722     PUSH       s_C:\msdev\work\age1_x1\taiuaimd.c               = "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp"
    //         00505727     PUSH       EAX
    //         00505728     PUSH       s_#%d_call_stopObject_%s_%d_                     = "#%d call stopObject %s %d\n"
    //         0050572d     PUSH       this
    //         0050572e     CALL       fprintf                                          undefined fprintf()
    //         00505733     ADD        ESP,0x14
    //                               LAB_00505736                                                 XREF[3]:     00505392(j), 00505496(j), 
    //                                                                                                         0050570c(j)  
    //                              taiuaimd.cpp:1221 (7)
    //         00505736     PUSH       0x1
    //         00505738     MOV        this,ESI
    //         0050573a     CALL       dword ptr [EDI + 0x58]
    //                              taiuaimd.cpp:1222 (10)
    //         0050573d     MOV        EDX,dword ptr [ESP + 0x18]
    //         00505741     PUSH       EDX
    //                               LAB_00505742                                                 XREF[3]:     0050536a(j), 00505516(j), 
    //                                                                                                         005056ee(j)  
    //         00505742     MOV        this,ESI
    //         00505744     CALL       dword ptr [EDI + 0x1c]
    //                               LAB_00505747                                                 XREF[7]:     0050537d(j), 00505522(j), 
    //                                                                                                         0050558d(j), 00505601(j), 
    //                                                                                                         00505637(j), 00505658(j), 
    //                                                                                                         00505662(j)  
    //                              taiuaimd.cpp:1225 (13)
    //         00505747     MOV        EBX,dword ptr [ESP + param_1]
    //         0050574b     CMP        dword ptr [EBX + 0x8],0x202
    //         00505752     JZ         LAB_0050579c
    //                              taiuaimd.cpp:1226 (7)
    //         00505754     MOV        this,ESI
    //         00505756     CALL       UnitAIModule::removeCurrentTarget                void removeCurrentTarget(UnitAIModule * this)
    //                              taiuaimd.cpp:1228 (50)
    //         0050575b     MOV        this,dword ptr [actionFile]                      = 00000000
    //         00505761     TEST       this,this
    //         00505763     JZ         LAB_0050578d
    //         00505765     MOV        EAX,dword ptr [ESI + 0x4]
    //         00505768     TEST       EAX,EAX
    //         0050576a     JZ         LAB_00505771
    //         0050576c     MOV        EAX,dword ptr [EAX + 0x4]
    //         0050576f     JMP        LAB_00505774
    //                               LAB_00505771                                                 XREF[1]:     0050576a(j)  
    //         00505771     OR         EAX,0xffffffff
    //                               LAB_00505774                                                 XREF[1]:     0050576f(j)  
    //         00505774     PUSH       0x4cc
    //         00505779     PUSH       s_C:\msdev\work\age1_x1\taiuaimd.c               = "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp"
    //         0050577e     PUSH       EAX
    //         0050577f     PUSH       s_#%d_call_stopObject_%s_%d_                     = "#%d call stopObject %s %d\n"
    //         00505784     PUSH       this
    //         00505785     CALL       fprintf                                          undefined fprintf()
    //         0050578a     ADD        ESP,0x14
    //                               LAB_0050578d                                                 XREF[3]:     005051b8(j), 0050521f(j), 
    //                                                                                                         00505763(j)  
    //                              taiuaimd.cpp:1230 (9)
    //         0050578d     MOV        EDI,dword ptr [ESI]
    //         0050578f     PUSH       0x1
    //         00505791     MOV        this,ESI
    //         00505793     CALL       dword ptr [EDI + 0x58]
    //                              taiuaimd.cpp:1231 (6)
    //         00505796     PUSH       EBX
    //         00505797     MOV        this,ESI
    //         00505799     CALL       dword ptr [EDI + 0x1c]
    //                               LAB_0050579c                                                 XREF[7]:     0050502c(j), 00505038(j), 
    //                                                                                                         00505069(j), 00505075(j), 
    //                                                                                                         005051a3(j), 0050520a(j), 
    //                                                                                                         00505752(j)  
    //                              taiuaimd.cpp:1233 (5)
    //         0050579c     MOV        EAX,0x2
    //                              taiuaimd.cpp:1237 (8)
    //         005057a1     POP        EDI
    //         005057a2     POP        ESI
    //         005057a3     POP        EBP
    //         005057a4     POP        EBX
    //         005057a5     POP        this
    //         005057a6     RET        0x8
    //                               switchD_00504e34::caseD_1f6                                  XREF[3]:     00504e26(j), 00504e34(j), 
    //                               switchD_00504e34::caseD_1f7                                               005057d8(*)  
    //                               switchD_00504e34::caseD_1f8
    //                               switchD_00504e34::caseD_1fc
    //                               switchD_00504e34::caseD_1fd
    //                               switchD_00504e34::caseD_1fe
    //                               switchD_00504e34::caseD_1ff
    //                               switchD_00504e34::caseD_200
    //                               switchD_00504e34::caseD_201
    //                               switchD_00504e34::caseD_203
    //                               switchD_00504e34::caseD_204
    //                               switchD_00504e34::caseD_205
    //                               switchD_00504e34::caseD_206
    //                               switchD_00504e34::caseD_207
    //                               switchD_00504e34::caseD_208
    //                               switchD_00504e34::caseD_209
    //                               switchD_00504e34::caseD_20a
    //                               switchD_00504e34::caseD_20b
    //                               switchD_00504e34::caseD_20c
    //                               switchD_00504e34::caseD_20d
    //                               switchD_00504e34::caseD_20e
    //                               switchD_00504e34::caseD_1f5
    //                              taiuaimd.cpp:1236 (13)
    //         005057a9     MOV        EAX,dword ptr [ESP + param_2]
    //         005057ad     MOV        this,ESI
    //         005057af     PUSH       EAX
    //         005057b0     PUSH       EBX
    //         005057b1     CALL       UnitAIModule::processNotify                      int processNotify(UnitAIModule * this, Notify
    //                              taiuaimd.cpp:1237 (66)
    //         005057b6     POP        EDI
    //         005057b7     POP        ESI
    //         005057b8     POP        EBP
    //         005057b9     POP        EBX
    //         005057ba     POP        this
    //         005057bb     RET        0x8
    //                              *                                               FUNCTION                                                *
    //                              undefined FUN_005057be()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_005057be
    //         005057be     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_00504e34::switchdataD_005057c0                       XREF[1]:     processNotify:00504e34(*)  
    //         005057c0     addr       switchD_00504e34::caseD_1f4
    //         005057c4     addr       switchD_00504e34::caseD_1f9
    //         005057c8     addr       switchD_00504e34::caseD_1fa
    //         005057cc     addr       switchD_00504e34::caseD_1fb
    //         005057d0     addr       switchD_00504e34::caseD_1fb
    //         005057d4     addr       switchD_00504e34::caseD_20f
    //         005057d8     addr       switchD_00504e34::caseD_1f5
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_00504e34::switchdataD_005057dc                       XREF[1]:     processNotify:00504e2e(*)  
    //         005057dc     db         0h
    //         005057dd     db         6h
    //         005057de     db         6h
    //         005057df     db         6h
    //         005057e0     db         6h
    //         005057e1     db         1h
    //         005057e2     db         2h
    //         005057e3     db         3h
    //         005057e4     db         6h
    //         005057e5     db         6h
    //         005057e6     db         6h
    //         005057e7     db         6h
    //         005057e8     db         6h
    //         005057e9     db         6h
    //         005057ea     db         4h
    //         005057eb     db         6h
    //         005057ec     db         6h
    //         005057ed     db         6h
    //         005057ee     db         6h
    //         005057ef     db         6h
    //         005057f0     db         6h
    //         005057f1     db         6h
    //         005057f2     db         6h
    //         005057f3     db         6h
    //         005057f4     db         6h
    //         005057f5     db         6h
    //         005057f6     db         6h
    //         005057f7     db         5h
    //         005057f8     ??         90h
    //         005057f9     ??         90h
    //         005057fa     ??         90h
    //         005057fb     ??         90h
    //         005057fc     ??         90h
    //         005057fd     ??         90h
    //         005057fe     ??         90h
    //         005057ff     ??         90h
    return 0;
}

int TribeCivilianUnitAIModule::processIdle(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall processIdle(TribeCivilianUnitAIModule * this, int par
    //              int               EAX:4          <RETURN>
    //              TribeCivilianU    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //                               ?processIdle@TribeCivilianUnitAIModule@@MAEHH@Z              XREF[1]:     00575e1c(*)  
    //                               TribeCivilianUnitAIModule::processIdle
    //                              taiuaimd.cpp:1242 (5)
    //         00505800     MOV        EAX,0x5
    //                              taiuaimd.cpp:1245 (3)
    //         00505805     RET        0x4
    //         00505808     ??         90h
    //         00505809     NOP
    //         0050580a     NOP
    //         0050580b     NOP
    //         0050580c     NOP
    //         0050580d     NOP
    //         0050580e     NOP
    //         0050580f     NOP
    return 0;
}

int TribeCivilianUnitAIModule::processMisc() {
    /* TODO: Stub */
    //                              int __thiscall processMisc(TribeCivilianUnitAIModule * this)
    //              int               EAX:4          <RETURN>
    //              TribeCivilianU    ECX:4 (auto)   this
    //                               ?processMisc@TribeCivilianUnitAIModule@@MAEHXZ               XREF[1]:     00575e20(*)  
    //                               TribeCivilianUnitAIModule::processMisc
    //                              taiuaimd.cpp:1250 (5)
    //         00505810     MOV        EAX,0x9
    //                              taiuaimd.cpp:1300 (1)
    //         00505815     RET
    //         00505816     ??         90h
    //         00505817     NOP
    //         00505818     NOP
    //         00505819     NOP
    //         0050581a     NOP
    //         0050581b     NOP
    //         0050581c     NOP
    //         0050581d     NOP
    //         0050581e     NOP
    //         0050581f     NOP
    return 0;
}

TribePriestUnitAIModule::TribePriestUnitAIModule(RGE_Static_Object* param_1, int param_2) {
    /* TODO: Stub */
    //                              undefined __thiscall TribePriestUnitAIModule(TribePriestUnitAIModule
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TribePriestUni    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     0050583e(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     00505836(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00505850(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00505954(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00505842(W)  
    //                               ??0TribePriestUnitAIModule@@QAE@PAVRGE_Static_Object@@H@Z    XREF[1]:     initUnitAI:004cb9c3(c)  
    //                               TribePriestUnitAIModule::TribePriestUnitAIModule
    //                              taiuaimd.cpp:1308 (46)
    //         00505820     PUSH       -0x1
    //         00505822     PUSH       FUN_00560c88
    //         00505827     MOV        EAX,FS:[0x0]
    //         0050582d     PUSH       EAX
    //         0050582e     MOV        dword ptr FS:[0x0],ESP
    //         00505835     PUSH       this
    //         00505836     MOV        EAX,dword ptr [ESP + param_2]
    //         0050583a     PUSH       ESI
    //         0050583b     MOV        ESI,this
    //         0050583d     PUSH       EAX
    //         0050583e     MOV        this,dword ptr [ESP + param_1]
    //         00505842     MOV        dword ptr [ESP + local_10],ESI
    //         00505846     PUSH       this
    //         00505847     MOV        this,ESI
    //         00505849     CALL       UnitAIModule::UnitAIModule                       undefined UnitAIModule(UnitAIModule * this, R
    //                              taiuaimd.cpp:1313 (40)
    //         0050584e     PUSH       0x44
    //         00505850     MOV        dword ptr [ESP + local_4],0x0
    //         00505858     MOV        dword ptr [ESI],TribePriestUnitAIModule::`vfta   = 00505970
    //         0050585e     MOV        dword ptr [ESI + 0x128],0x11
    //         00505868     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0050586d     ADD        ESP,0x4
    //         00505870     MOV        dword ptr [ESI + 0x124],EAX
    //                              taiuaimd.cpp:1314 (8)
    //         00505876     TEST       EAX,EAX
    //         00505878     JZ         LAB_00505954
    //                              taiuaimd.cpp:1315 (6)
    //         0050587e     MOV        dword ptr [EAX],0x3
    //                              taiuaimd.cpp:1316 (13)
    //         00505884     MOV        EDX,dword ptr [ESI + 0x124]
    //         0050588a     MOV        dword ptr [EDX + 0x4],0x0
    //                              taiuaimd.cpp:1317 (13)
    //         00505891     MOV        EAX,dword ptr [ESI + 0x124]
    //         00505897     MOV        dword ptr [EAX + 0x8],0x4
    //                              taiuaimd.cpp:1318 (13)
    //         0050589e     MOV        this,dword ptr [ESI + 0x124]
    //         005058a4     MOV        dword ptr [ECX + this->field12_0xc],0x1a
    //                              taiuaimd.cpp:1319 (13)
    //         005058ab     MOV        EDX,dword ptr [ESI + 0x124]
    //         005058b1     MOV        dword ptr [EDX + 0x10],0x18
    //                              taiuaimd.cpp:1320 (13)
    //         005058b8     MOV        EAX,dword ptr [ESI + 0x124]
    //         005058be     MOV        dword ptr [EAX + 0x14],0x6
    //                              taiuaimd.cpp:1321 (13)
    //         005058c5     MOV        this,dword ptr [ESI + 0x124]
    //         005058cb     MOV        dword ptr [ECX + this->field24_0x18],0x19
    //                              taiuaimd.cpp:1322 (13)
    //         005058d2     MOV        EDX,dword ptr [ESI + 0x124]
    //         005058d8     MOV        dword ptr [EDX + 0x1c],0x11
    //                              taiuaimd.cpp:1323 (13)
    //         005058df     MOV        EAX,dword ptr [ESI + 0x124]
    //         005058e5     MOV        dword ptr [EAX + 0x20],0xa
    //                              taiuaimd.cpp:1324 (13)
    //         005058ec     MOV        this,dword ptr [ESI + 0x124]
    //         005058f2     MOV        dword ptr [ECX + this->field36_0x24],0xc
    //                              taiuaimd.cpp:1325 (13)
    //         005058f9     MOV        EDX,dword ptr [ESI + 0x124]
    //         005058ff     MOV        dword ptr [EDX + 0x28],0x23
    //                              taiuaimd.cpp:1326 (13)
    //         00505906     MOV        EAX,dword ptr [ESI + 0x124]
    //         0050590c     MOV        dword ptr [EAX + 0x2c],0x17
    //                              taiuaimd.cpp:1327 (13)
    //         00505913     MOV        this,dword ptr [ESI + 0x124]
    //         00505919     MOV        dword ptr [ECX + this->field48_0x30],0x24
    //                              taiuaimd.cpp:1328 (13)
    //         00505920     MOV        EDX,dword ptr [ESI + 0x124]
    //         00505926     MOV        dword ptr [EDX + 0x34],0x1c
    //                              taiuaimd.cpp:1329 (13)
    //         0050592d     MOV        EAX,dword ptr [ESI + 0x124]
    //         00505933     MOV        dword ptr [EAX + 0x38],0x12
    //                              taiuaimd.cpp:1330 (13)
    //         0050593a     MOV        this,dword ptr [ESI + 0x124]
    //         00505940     MOV        dword ptr [ECX + this->field60_0x3c],0xd
    //                              taiuaimd.cpp:1331 (13)
    //         00505947     MOV        EDX,dword ptr [ESI + 0x124]
    //         0050594d     MOV        dword ptr [EDX + 0x40],0x27
    //                               LAB_00505954                                                 XREF[1]:     00505878(j)  
    //                              taiuaimd.cpp:1333 (20)
    //         00505954     MOV        this,dword ptr [ESP + local_c]
    //         00505958     MOV        EAX,ESI
    //         0050595a     MOV        dword ptr FS:[0x0],this
    //         00505961     POP        ESI
    //         00505962     ADD        ESP,0x10
    //         00505965     RET        0x8
    //         00505968     ??         90h
    //         00505969     NOP
    //         0050596a     NOP
    //         0050596b     NOP
    //         0050596c     NOP
    //         0050596d     NOP
    //         0050596e     NOP
    //         0050596f     NOP
}

int TribePriestUnitAIModule::attackObject(int param_1, int param_2) {
    /* TODO: Stub */
    //                              int __thiscall attackObject(TribePriestUnitAIModule * this, int para
    //              int               EAX:4          <RETURN>
    //              TribePriestUni    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     005059a1(R)  
    //              int               Stack[0x8]:4   param_2
    //                               ?attackObject@TribePriestUnitAIModule@@UAEHHH@Z              XREF[1]:     00575e84(*)  
    //                               TribePriestUnitAIModule::attackObject
    //                              taiuaimd.cpp:1338 (1)
    //         005059a0     PUSH       EBX
    //                              taiuaimd.cpp:1339 (21)
    //         005059a1     MOV        EBX,dword ptr [ESP + param_1]
    //         005059a5     PUSH       ESI
    //         005059a6     MOV        ESI,this
    //         005059a8     PUSH       EDI
    //         005059a9     PUSH       EBX
    //         005059aa     MOV        EDI,dword ptr [ESI]
    //         005059ac     CALL       dword ptr [EDI + 0xc4]
    //         005059b2     TEST       EAX,EAX
    //         005059b4     JNZ        LAB_005059f6
    //                              taiuaimd.cpp:1342 (21)
    //         005059b6     CMP        dword ptr [ESI + 0x28],-0x1
    //         005059ba     JNZ        LAB_005059ee
    //         005059bc     MOV        EAX,dword ptr [ESI + 0x4]
    //         005059bf     MOV        this,dword ptr [EAX + 0xc]
    //         005059c2     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
    //         005059c7     TEST       EAX,EAX
    //         005059c9     JZ         LAB_005059ee
    //                              taiuaimd.cpp:1345 (29)
    //         005059cb     MOV        this,dword ptr [ESI + 0x4]
    //         005059ce     MOV        EDX,dword ptr [ESP + 0x14]
    //         005059d2     PUSH       EDX
    //         005059d3     MOV        EAX,dword ptr [this->field0_0x0]
    //         005059d5     CALL       dword ptr [EAX + 0x10c]
    //         005059db     PUSH       this
    //         005059dc     MOV        this,ESI
    //         005059de     FSTP       float ptr [ESP]
    //         005059e1     PUSH       EBX=>DAT_fffffff8
    //         005059e2     CALL       dword ptr [EDI + 0x94]
    //                              taiuaimd.cpp:1349 (6)
    //         005059e8     POP        EDI
    //         005059e9     POP        ESI
    //         005059ea     POP        EBX
    //         005059eb     RET        0x8
    //                               LAB_005059ee                                                 XREF[2]:     005059ba(j), 005059c9(j)  
    //                              taiuaimd.cpp:1343 (2)
    //         005059ee     XOR        EAX,EAX
    //                              taiuaimd.cpp:1349 (6)
    //         005059f0     POP        EDI
    //         005059f1     POP        ESI
    //         005059f2     POP        EBX
    //         005059f3     RET        0x8
    //                               LAB_005059f6                                                 XREF[1]:     005059b4(j)  
    //                              taiuaimd.cpp:1348 (11)
    //         005059f6     MOV        this,dword ptr [ESP + 0x14]
    //         005059fa     PUSH       this
    //         005059fb     PUSH       EBX=>DAT_fffffff8
    //         005059fc     MOV        this,ESI
    //         005059fe     CALL       dword ptr [EDI + 0x6c]
    //                              taiuaimd.cpp:1349 (6)
    //         00505a01     POP        EDI
    //         00505a02     POP        ESI
    //         00505a03     POP        EBX
    //         00505a04     RET        0x8
    //         00505a07     ??         90h
    //         00505a08     NOP
    //         00505a09     NOP
    //         00505a0a     NOP
    //         00505a0b     NOP
    //         00505a0c     NOP
    //         00505a0d     NOP
    //         00505a0e     NOP
    //         00505a0f     NOP
    return 0;
}

int TribePriestUnitAIModule::retryableOrder(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall retryableOrder(TribePriestUnitAIModule * this, int pa
    //              int               EAX:4          <RETURN>
    //              TribePriestUni    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00505a10(R)  
    //                               ?retryableOrder@TribePriestUnitAIModule@@UAEHH@Z             XREF[1]:     00575e50(*)  
    //                               TribePriestUnitAIModule::retryableOrder
    //                              taiuaimd.cpp:1354 (18)
    //         00505a10     MOV        EAX,dword ptr [ESP + param_1]
    //         00505a14     CMP        EAX,0x2c0
    //         00505a19     JZ         LAB_00505a27
    //         00505a1b     CMP        EAX,0x2bf
    //         00505a20     JZ         LAB_00505a27
    //                              taiuaimd.cpp:1359 (2)
    //         00505a22     XOR        EAX,EAX
    //                              taiuaimd.cpp:1360 (3)
    //         00505a24     RET        0x4
    //                               LAB_00505a27                                                 XREF[2]:     00505a19(j), 00505a20(j)  
    //                              taiuaimd.cpp:1358 (5)
    //         00505a27     MOV        EAX,0x1
    //                              taiuaimd.cpp:1360 (3)
    //         00505a2c     RET        0x4
    //         00505a2f     ??         90h
    return 0;
}

int TribePriestUnitAIModule::canConvert(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall canConvert(TribePriestUnitAIModule * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              TribePriestUni    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00505a4d(R)  
    //                               ?canConvert@TribePriestUnitAIModule@@UAEHH@Z                 XREF[1]:     00575eec(*)  
    //                               TribePriestUnitAIModule::canConvert
    //                              taiuaimd.cpp:1365 (3)
    //         00505a30     PUSH       ESI
    //         00505a31     MOV        ESI,this
    //                              taiuaimd.cpp:1368 (17)
    //         00505a33     MOV        this,dword ptr [ESI + 0x4]
    //         00505a36     FLD        float ptr [ECX + this->field68_0x44]
    //         00505a39     FCOMP      float ptr [DAT_005758d4]
    //         00505a3f     FNSTSW     AX
    //         00505a41     TEST       AH,0x1
    //                              taiuaimd.cpp:1369 (6)
    //         00505a44     JNZ        LAB_00505ad6
    //                              taiuaimd.cpp:1372 (16)
    //         00505a4a     MOV        this,dword ptr [ECX + this->field12_0xc]
    //         00505a4d     MOV        EAX,dword ptr [ESP + param_1]
    //         00505a51     PUSH       EAX
    //         00505a52     MOV        this,dword ptr [ECX + this->field60_0x3c]
    //         00505a55     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //                              taiuaimd.cpp:1373 (2)
    //         00505a5a     TEST       EAX,EAX
    //                              taiuaimd.cpp:1374 (2)
    //         00505a5c     JZ         LAB_00505ad6
    //                              taiuaimd.cpp:1375 (7)
    //         00505a5e     MOV        EAX,dword ptr [EAX + 0x8]
    //         00505a61     MOVSX      this,word ptr [EAX + 0x14]
    //                              taiuaimd.cpp:1378 (8)
    //         00505a65     MOV        AX,word ptr [EAX + 0x10]
    //         00505a69     CMP        AX,0x6d
    //                              taiuaimd.cpp:1379 (2)
    //         00505a6d     JZ         LAB_00505ad6
    //                              taiuaimd.cpp:1381 (3)
    //         00505a6f     CMP        this,0x1b
    //                              taiuaimd.cpp:1382 (2)
    //         00505a72     JZ         LAB_00505ad6
    //                              taiuaimd.cpp:1384 (4)
    //         00505a74     CMP        AX,0x9f
    //                              taiuaimd.cpp:1385 (2)
    //         00505a78     JZ         LAB_00505ad6
    //                              taiuaimd.cpp:1387 (4)
    //         00505a7a     CMP        AX,0x114
    //                              taiuaimd.cpp:1388 (2)
    //         00505a7e     JZ         LAB_00505ad6
    //                              taiuaimd.cpp:1391 (12)
    //         00505a80     CMP        AX,0x9e
    //         00505a84     JZ         LAB_00505ad6
    //         00505a86     CMP        AX,0xa3
    //         00505a8a     JZ         LAB_00505ad6
    //                              taiuaimd.cpp:1394 (3)
    //         00505a8c     CMP        this,0x1e
    //                              taiuaimd.cpp:1395 (2)
    //         00505a8f     JZ         LAB_00505ad6
    //                              taiuaimd.cpp:1400 (28)
    //         00505a91     CMP        this,0x12
    //         00505a94     JNZ        LAB_00505aaf
    //         00505a96     MOV        EDX,dword ptr [ESI + 0x4]
    //         00505a99     MOV        EAX,dword ptr [EDX + 0xc]
    //         00505a9c     MOV        EDX,dword ptr [EAX + 0x50]
    //         00505a9f     FLD        float ptr [EDX + 0x6c]
    //         00505aa2     FCOMP      float ptr [DAT_005758c4]
    //         00505aa8     FNSTSW     AX
    //         00505aaa     TEST       AH,0x41
    //                              taiuaimd.cpp:1401 (2)
    //         00505aad     JNZ        LAB_00505ad6
    //                               LAB_00505aaf                                                 XREF[1]:     00505a94(j)  
    //                              taiuaimd.cpp:1405 (28)
    //         00505aaf     CMP        this,0x3
    //         00505ab2     JNZ        LAB_00505acd
    //         00505ab4     MOV        EAX,dword ptr [ESI + 0x4]
    //         00505ab7     MOV        this,dword ptr [EAX + 0xc]
    //         00505aba     MOV        EDX,dword ptr [ECX + this->field80_0x50]
    //         00505abd     FLD        float ptr [EDX + 0x70]
    //         00505ac0     FCOMP      float ptr [DAT_005758c4]
    //         00505ac6     FNSTSW     AX
    //         00505ac8     TEST       AH,0x41
    //                              taiuaimd.cpp:1406 (2)
    //         00505acb     JNZ        LAB_00505ad6
    //                               LAB_00505acd                                                 XREF[1]:     00505ab2(j)  
    //                              taiuaimd.cpp:1408 (5)
    //         00505acd     MOV        EAX,0x1
    //                              taiuaimd.cpp:1409 (4)
    //         00505ad2     POP        ESI
    //         00505ad3     RET        0x4
    //                               LAB_00505ad6                                                 XREF[11]:    00505a44(j), 00505a5c(j), 
    //                                                                                                         00505a6d(j), 00505a72(j), 
    //                                                                                                         00505a78(j), 00505a7e(j), 
    //                                                                                                         00505a84(j), 00505a8a(j), 
    //                                                                                                         00505a8f(j), 00505aad(j), 
    //                                                                                                         00505acb(j)  
    //                              taiuaimd.cpp:1392 (2)
    //         00505ad6     XOR        EAX,EAX
    //                              taiuaimd.cpp:1409 (4)
    //         00505ad8     POP        ESI
    //         00505ad9     RET        0x4
    //         00505adc     ??         90h
    //         00505add     NOP
    //         00505ade     NOP
    //         00505adf     NOP
    return 0;
}

int TribePriestUnitAIModule::canAttackUnit(RGE_Static_Object* param_1) {
    /* TODO: Stub */
    //                              int __thiscall canAttackUnit(TribePriestUnitAIModule * this, RGE_Sta
    //              int               EAX:4          <RETURN>
    //              TribePriestUni    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00505ae0(R)  
    //                               ?canAttackUnit@TribePriestUnitAIModule@@UAEHPAVRGE_Static_O  XREF[1]:     00575e78(*)  
    //                               TribePriestUnitAIModule::canAttackUnit
    //                              taiuaimd.cpp:1414 (8)
    //         00505ae0     MOV        EAX,dword ptr [ESP + param_1]
    //         00505ae4     TEST       EAX,EAX
    //         00505ae6     JZ         LAB_00505af7
    //                              taiuaimd.cpp:1416 (12)
    //         00505ae8     MOV        EAX,dword ptr [EAX + 0x4]
    //         00505aeb     MOV        EDX,dword ptr [this->field0_0x0]
    //         00505aed     PUSH       EAX
    //         00505aee     CALL       dword ptr [EDX + 0xc4]
    //                              taiuaimd.cpp:1418 (3)
    //         00505af4     RET        0x4
    //                               LAB_00505af7                                                 XREF[1]:     00505ae6(j)  
    //                              taiuaimd.cpp:1417 (2)
    //         00505af7     XOR        EAX,EAX
    //                              taiuaimd.cpp:1418 (3)
    //         00505af9     RET        0x4
    //         00505afc     ??         90h
    //         00505afd     NOP
    //         00505afe     NOP
    //         00505aff     NOP
    return 0;
}

int TribePriestUnitAIModule::bestUnitToHeal(int param_1, float* param_2) {
    /* TODO: Stub */
    //                              int __thiscall bestUnitToHeal(TribePriestUnitAIModule * this, int pa
    //              int               EAX:4          <RETURN>
    //              TribePriestUni    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //              float *           Stack[0x8]:4   param_2
    //              int               Stack[-0x10]:4 a
    //              int               Stack[-0x14]:4 i
    //              float             Stack[-0x18]:4 allyNeed
    //              int               Stack[-0x1c]:4 maxLimit
    //              int               Stack[-0x20]:4 allyToHealID
    //                               ?bestUnitToHeal@TribePriestUnitAIModule@@MAEHHPAM@Z          XREF[1]:     00575f08(*)  
    //                               TribePriestUnitAIModule::bestUnitToHeal
    //                              taiuaimd.cpp:1424 (9)
    //         00505b00     SUB        ESP,0x1c
    //         00505b03     PUSH       EBX
    //         00505b04     PUSH       EBP
    //         00505b05     MOV        EBP,this
    //         00505b07     PUSH       ESI
    //         00505b08     PUSH       EDI
    //                              taiuaimd.cpp:1429 (6)
    //         00505b09     MOV        EAX,dword ptr [EBP]
    //         00505b0c     CALL       dword ptr [EAX + 0x20]
    //                              taiuaimd.cpp:1436 (36)
    //         00505b0f     MOV        this,dword ptr [EBP + 0x4]
    //         00505b12     OR         EAX,0xffffffff
    //         00505b15     MOV        dword ptr [ESP + 0x10],EAX
    //         00505b19     MOV        dword ptr [ESP + 0x18],0x0
    //         00505b21     MOV        EDX,dword ptr [ECX + this->field12_0xc]
    //         00505b24     MOV        dword ptr [ESP + 0x14],0x2
    //         00505b2c     CMP        word ptr [EDX + 0x4a],0x0
    //         00505b31     JNZ        LAB_00505b3b
    //                              taiuaimd.cpp:1437 (8)
    //         00505b33     MOV        dword ptr [ESP + 0x14],0x4
    //                               LAB_00505b3b                                                 XREF[1]:     00505b31(j)  
    //                              taiuaimd.cpp:1439 (27)
    //         00505b3b     MOV        EDX,dword ptr [ESP + 0x14]
    //         00505b3f     MOV        this,0x1
    //         00505b44     CMP        EDX,this
    //         00505b46     MOV        dword ptr [ESP + 0x20],this
    //         00505b4a     JL         LAB_00505cb0
    //         00505b50     XOR        EDX,EDX
    //         00505b52     MOV        dword ptr [ESP + 0x24],EDX
    //                               LAB_00505b56                                                 XREF[1]:     00505caa(j)  
    //                              taiuaimd.cpp:1440 (20)
    //         00505b56     MOV        ESI,dword ptr [EDX + DAT_0087d7cc]               = align(4)
    //         00505b5c     XOR        this,this
    //         00505b5e     TEST       ESI,ESI
    //         00505b60     MOV        dword ptr [ESP + 0x1c],this
    //         00505b64     JLE        LAB_00505c8f
    //                              taiuaimd.cpp:1439 (6)
    //         00505b6a     LEA        ESI,[EDX + DAT_0087d7e4]
    //                               LAB_00505b70                                                 XREF[1]:     00505c85(j)  
    //                              taiuaimd.cpp:1442 (24)
    //         00505b70     MOV        EAX,dword ptr [ESI]=>DAT_0087d7e4                = align(4)
    //         00505b72     LEA        EBX,[this->field0_0x0*0x8 + 0x0]
    //         00505b79     MOV        this,dword ptr [EBP + 0x4]
    //         00505b7c     MOV        EDX,dword ptr [EBX + EAX*0x1]
    //         00505b7f     CMP        EDX,dword ptr [ECX + this->field4_0x4]
    //         00505b82     JZ         LAB_00505c70
    //                              taiuaimd.cpp:1445 (15)
    //         00505b88     MOV        EAX,dword ptr [ESI]=>DAT_0087d7e4                = align(4)
    //         00505b8a     MOV        this,dword ptr [EBX + EAX*0x1]
    //         00505b8d     PUSH       this
    //         00505b8e     MOV        this,EBP
    //         00505b90     CALL       UnitAIModule::lookupObject                       RGE_Static_Object * lookupObject(UnitAIModule
    //         00505b95     MOV        EDI,EAX
    //                              taiuaimd.cpp:1446 (8)
    //         00505b97     TEST       EDI,EDI
    //         00505b99     JZ         LAB_00505c70
    //                              taiuaimd.cpp:1450 (14)
    //         00505b9f     MOV        EAX,dword ptr [EDI + 0x8]
    //         00505ba2     CMP        word ptr [EAX + 0x14],0x3
    //         00505ba7     JZ         LAB_00505c70
    //                              taiuaimd.cpp:1459 (26)
    //         00505bad     MOVSX      EDX,word ptr [EAX + 0x26]
    //         00505bb1     MOV        dword ptr [ESP + 0x28],EDX
    //         00505bb5     FILD       dword ptr [ESP + 0x28]
    //         00505bb9     FCOMP      float ptr [EDI + 0x30]
    //         00505bbc     FNSTSW     AX
    //         00505bbe     TEST       AH,0x41
    //         00505bc1     JNZ        LAB_00505c70
    //                              taiuaimd.cpp:1466 (10)
    //         00505bc7     CMP        byte ptr [EDI + 0x48],0x3
    //         00505bcb     JNC        LAB_00505c70
    //                              taiuaimd.cpp:1476 (21)
    //         00505bd1     MOV        EAX,dword ptr [ESP + 0x30]
    //         00505bd5     TEST       EAX,EAX
    //         00505bd7     JNZ        LAB_00505be6
    //         00505bd9     MOV        EAX,dword ptr [ESI]=>DAT_0087d7e4
    //         00505bdb     CMP        byte ptr [EBX + EAX*0x1 + 0x4],0x4
    //         00505be0     JA         LAB_00505c70
    //                               LAB_00505be6                                                 XREF[1]:     00505bd7(j)  
    //                              taiuaimd.cpp:1482 (22)
    //         00505be6     MOV        this,dword ptr [EBP + 0x4]
    //         00505be9     MOV        EDX,dword ptr [ECX + this->field12_0xc]
    //         00505bec     CMP        word ptr [EDX + 0x4a],0x0
    //         00505bf1     JNZ        LAB_00505bfc
    //         00505bf3     MOV        EAX,dword ptr [ESI]=>DAT_0087d7e4
    //         00505bf5     CMP        byte ptr [EBX + EAX*0x1 + 0x4],0x2
    //         00505bfa     JA         LAB_00505c70
    //                               LAB_00505bfc                                                 XREF[1]:     00505bf1(j)  
    //                              taiuaimd.cpp:1486 (31)
    //         00505bfc     MOV        EAX,dword ptr [ESI]=>DAT_0087d7e4
    //         00505bfe     MOV        EDX,dword ptr [this->field0_0x0]
    //         00505c00     PUSH       -0x1
    //         00505c02     PUSH       offset DAT_fffffff8
    //         00505c04     MOV        EAX,dword ptr [EBX + EAX*0x1]
    //         00505c07     PUSH       0x0=>DAT_fffffff4
    //         00505c09     PUSH       0x0=>DAT_fffffff0
    //         00505c0b     PUSH       0x3f800000
    //         00505c10     PUSH       EAX
    //         00505c11     CALL       dword ptr [EDX + 0x194]
    //         00505c17     TEST       EAX,EAX
    //         00505c19     JZ         LAB_00505c70
    //                              taiuaimd.cpp:1491 (2)
    //         00505c1b     MOV        this,dword ptr [ESI]=>DAT_0087d7e4
    //                              taiuaimd.cpp:1493 (17)
    //         00505c1d     MOV        EAX,dword ptr [EDI + 0x8]
    //         00505c20     XOR        EDX,EDX
    //         00505c22     MOV        DL,byte ptr [EBX + this->field0_0x0*0x1 + 0x4]
    //         00505c26     MOVSX      this,word ptr [EAX + 0x26]
    //         00505c2a     MOV        dword ptr [ESP + 0x28],EDX
    //                              taiuaimd.cpp:1498 (39)
    //         00505c2e     MOV        EAX,dword ptr [ESP + 0x10]
    //         00505c32     FILD       dword ptr [ESP + 0x28]
    //         00505c36     MOV        dword ptr [ESP + 0x28],this
    //         00505c3a     CMP        EAX,-0x1
    //         00505c3d     FILD       dword ptr [ESP + 0x28]
    //         00505c41     FLD        float ptr [EDI + 0x30]
    //         00505c44     FDIV       ST0,ST2
    //         00505c46     FSUBP
    //         00505c48     JZ         LAB_00505c55
    //         00505c4a     FCOM       float ptr [ESP + 0x18]
    //         00505c4e     FNSTSW     AX
    //         00505c50     TEST       AH,0x1
    //         00505c53     JZ         LAB_00505c6c
    //                               LAB_00505c55                                                 XREF[1]:     00505c48(j)  
    //                              taiuaimd.cpp:1501 (19)
    //         00505c55     MOV        EAX,dword ptr [ESP + 0x34]
    //         00505c59     MOV        EDX,dword ptr [EDI + 0x4]
    //         00505c5c     FSTP       float ptr [ESP + 0x18]
    //         00505c60     TEST       EAX,EAX
    //         00505c62     MOV        dword ptr [ESP + 0x10],EDX
    //         00505c66     JZ         LAB_00505c6e
    //                              taiuaimd.cpp:1502 (2)
    //         00505c68     FSTP       float ptr [EAX]
    //                              taiuaimd.cpp:1498 (4)
    //         00505c6a     JMP        LAB_00505c70
    //                               LAB_00505c6c                                                 XREF[1]:     00505c53(j)  
    //         00505c6c     FSTP       ST0
    //                               LAB_00505c6e                                                 XREF[1]:     00505c66(j)  
    //                              taiuaimd.cpp:1500 (2)
    //         00505c6e     FSTP       ST0
    //                               LAB_00505c70                                                 XREF[9]:     00505b82(j), 00505b99(j), 
    //                                                                                                         00505ba7(j), 00505bc1(j), 
    //                                                                                                         00505bcb(j), 00505be0(j), 
    //                                                                                                         00505bfa(j), 00505c19(j), 
    //                                                                                                         00505c6a(j)  
    //                              taiuaimd.cpp:1440 (31)
    //         00505c70     MOV        EDX,dword ptr [ESP + 0x24]
    //         00505c74     MOV        this,dword ptr [ESP + 0x1c]
    //         00505c78     INC        this
    //         00505c79     MOV        EAX,dword ptr [EDX + DAT_0087d7cc]               = align(4)
    //         00505c7f     MOV        dword ptr [ESP + 0x1c],this
    //         00505c83     CMP        this,EAX
    //         00505c85     JL         LAB_00505b70
    //         00505c8b     MOV        EAX,dword ptr [ESP + 0x10]
    //                               LAB_00505c8f                                                 XREF[1]:     00505b64(j)  
    //                              taiuaimd.cpp:1508 (33)
    //         00505c8f     CMP        EAX,-0x1
    //         00505c92     JNZ        LAB_00505cb3
    //         00505c94     MOV        this,dword ptr [ESP + 0x20]
    //         00505c98     MOV        ESI,dword ptr [ESP + 0x14]
    //         00505c9c     INC        this
    //         00505c9d     ADD        EDX,0x4
    //         00505ca0     CMP        this,ESI
    //         00505ca2     MOV        dword ptr [ESP + 0x20],this
    //         00505ca6     MOV        dword ptr [ESP + 0x24],EDX
    //         00505caa     JLE        LAB_00505b56
    //                               LAB_00505cb0                                                 XREF[1]:     00505b4a(j)  
    //                              taiuaimd.cpp:1511 (3)
    //         00505cb0     OR         EAX,0xffffffff
    //                               LAB_00505cb3                                                 XREF[1]:     00505c92(j)  
    //                              taiuaimd.cpp:1512 (10)
    //         00505cb3     POP        EDI
    //         00505cb4     POP        ESI
    //         00505cb5     POP        EBP
    //         00505cb6     POP        EBX
    //         00505cb7     ADD        ESP,0x1c
    //         00505cba     RET        0x8
    //         00505cbd     ??         90h
    //         00505cbe     NOP
    //         00505cbf     NOP
    return 0;
}

int TribePriestUnitAIModule::bestUnitToConvert(float* param_1) {
    /* TODO: Stub */
    //                              int __thiscall bestUnitToConvert(TribePriestUnitAIModule * this, flo
    //              int               EAX:4          <RETURN>
    //              TribePriestUni    ECX:4 (auto)   this
    //              float *           Stack[0x4]:4   param_1
    //              int               Stack[-0xc]:4  i
    //              float             Stack[-0x10]:4 targetValue
    //                               ?bestUnitToConvert@TribePriestUnitAIModule@@MAEHPAM@Z        XREF[1]:     00575f0c(*)  
    //                               TribePriestUnitAIModule::bestUnitToConvert
    //                              taiuaimd.cpp:1517 (7)
    //         00505cc0     SUB        ESP,0xc
    //         00505cc3     PUSH       EBP
    //         00505cc4     PUSH       EDI
    //         00505cc5     MOV        EDI,this
    //                              taiuaimd.cpp:1522 (5)
    //         00505cc7     MOV        EAX,dword ptr [EDI]
    //         00505cc9     CALL       dword ptr [EAX + 0x20]
    //                              taiuaimd.cpp:1527 (33)
    //         00505ccc     MOV        this,dword ptr [DAT_0087d7d8]
    //         00505cd2     OR         EBP,0xffffffff
    //         00505cd5     XOR        EAX,EAX
    //         00505cd7     MOV        dword ptr [ESP + 0x8],0x0
    //         00505cdf     TEST       this,this
    //         00505ce1     MOV        dword ptr [ESP + 0xc],EAX
    //         00505ce5     JLE        LAB_00505dbd
    //         00505ceb     PUSH       ESI
    //         00505cec     PUSH       EBX=>DAT_fffffff8
    //                               LAB_00505ced                                                 XREF[1]:     00505db5(j)  
    //                              taiuaimd.cpp:1529 (39)
    //         00505ced     MOV        this,dword ptr [EDI + 0x4]
    //         00505cf0     MOV        ESI,dword ptr [DAT_0087d7f0]
    //         00505cf6     LEA        EBX,[EAX*0x8 + 0x0]
    //         00505cfd     XOR        EAX,EAX
    //         00505cff     MOV        this,dword ptr [ECX + this->field12_0xc]
    //         00505d02     MOV        AL,byte ptr [ESI + EBX*0x1 + 0x5]
    //         00505d06     MOV        EDX,dword ptr [this->field0_0x0]
    //         00505d08     PUSH       EAX=>DAT_fffffff4
    //         00505d09     CALL       dword ptr [EDX + 0x18]
    //         00505d0c     TEST       EAX,EAX
    //         00505d0e     JZ         LAB_00505da4
    //                              taiuaimd.cpp:1531 (19)
    //         00505d14     MOV        this,dword ptr [DAT_0087d7f0]
    //         00505d1a     MOV        EDX,dword ptr [this->field0_0x0 + EBX*0x1]
    //         00505d1d     MOV        this,EDI
    //         00505d1f     PUSH       EDX
    //         00505d20     CALL       UnitAIModule::lookupObject                       RGE_Static_Object * lookupObject(UnitAIModule
    //         00505d25     MOV        ESI,EAX
    //                              taiuaimd.cpp:1532 (4)
    //         00505d27     TEST       ESI,ESI
    //         00505d29     JZ         LAB_00505da4
    //                              taiuaimd.cpp:1535 (6)
    //         00505d2b     CMP        byte ptr [ESI + 0x48],0x3
    //         00505d2f     JNC        LAB_00505da4
    //                              taiuaimd.cpp:1538 (18)
    //         00505d31     MOV        EAX,dword ptr [ESI + 0x4]
    //         00505d34     MOV        this,EDI
    //         00505d36     PUSH       EAX
    //         00505d37     MOV        EAX,dword ptr [EDI]
    //         00505d39     CALL       dword ptr [EAX + 0xc4]
    //         00505d3f     TEST       EAX,EAX
    //         00505d41     JZ         LAB_00505da4
    //                              taiuaimd.cpp:1543 (20)
    //         00505d43     MOV        EDX,dword ptr [DAT_0087d7f0]
    //         00505d49     XOR        this,this
    //         00505d4b     MOV        this,byte ptr [EDX + EBX*0x1 + 0x4]
    //         00505d4f     MOV        dword ptr [ESP + 0x18],this
    //         00505d53     FILD       dword ptr [ESP + 0x18]
    //                              taiuaimd.cpp:1544 (15)
    //         00505d57     FCOM       float ptr [DAT_005758bc]
    //         00505d5d     FNSTSW     AX
    //         00505d5f     TEST       AH,0x1
    //         00505d62     JZ         LAB_00505d6c
    //         00505d64     FSTP       ST0
    //                              taiuaimd.cpp:1545 (6)
    //         00505d66     FLD        float ptr [DAT_005758bc]
    //                               LAB_00505d6c                                                 XREF[1]:     00505d62(j)  
    //                              taiuaimd.cpp:1546 (3)
    //         00505d6c     MOV        EAX,dword ptr [ESI + 0x8]
    //                              taiuaimd.cpp:1549 (30)
    //         00505d6f     CMP        EBP,-0x1
    //         00505d72     MOVSX      this,word ptr [EAX + 0x26]
    //         00505d76     MOV        dword ptr [ESP + 0x18],this
    //         00505d7a     FILD       dword ptr [ESP + 0x18]
    //         00505d7e     FDIV       ST0,ST1
    //         00505d80     JZ         LAB_00505d8d
    //         00505d82     FCOM       float ptr [ESP + 0x10]
    //         00505d86     FNSTSW     AX
    //         00505d88     TEST       AH,0x41
    //         00505d8b     JNZ        LAB_00505da0
    //                               LAB_00505d8d                                                 XREF[1]:     00505d80(j)  
    //                              taiuaimd.cpp:1552 (15)
    //         00505d8d     MOV        EAX,dword ptr [ESP + 0x20]
    //         00505d91     MOV        EBP,dword ptr [ESI + 0x4]
    //         00505d94     FSTP       float ptr [ESP + 0x10]
    //         00505d98     TEST       EAX,EAX
    //         00505d9a     JZ         LAB_00505da2
    //                              taiuaimd.cpp:1553 (4)
    //         00505d9c     FSTP       float ptr [EAX]
    //         00505d9e     JMP        LAB_00505da4
    //                               LAB_00505da0                                                 XREF[1]:     00505d8b(j)  
    //                              taiuaimd.cpp:1549 (2)
    //         00505da0     FSTP       ST0
    //                               LAB_00505da2                                                 XREF[1]:     00505d9a(j)  
    //                              taiuaimd.cpp:1551 (2)
    //         00505da2     FSTP       ST0
    //                               LAB_00505da4                                                 XREF[5]:     00505d0e(j), 00505d29(j), 
    //                                                                                                         00505d2f(j), 00505d41(j), 
    //                                                                                                         00505d9e(j)  
    //                              taiuaimd.cpp:1527 (25)
    //         00505da4     MOV        EAX,dword ptr [ESP + 0x14]
    //         00505da8     MOV        this,dword ptr [DAT_0087d7d8]
    //         00505dae     INC        EAX
    //         00505daf     CMP        EAX,this
    //         00505db1     MOV        dword ptr [ESP + 0x14],EAX
    //         00505db5     JL         LAB_00505ced
    //         00505dbb     POP        EBX
    //         00505dbc     POP        ESI
    //                               LAB_00505dbd                                                 XREF[1]:     00505ce5(j)  
    //                              taiuaimd.cpp:1557 (2)
    //         00505dbd     MOV        EAX,EBP
    //                              taiuaimd.cpp:1558 (8)
    //         00505dbf     POP        EDI
    //         00505dc0     POP        EBP
    //         00505dc1     ADD        ESP,0xc
    //         00505dc4     RET        0x4
    //                              *                                               FUNCTION                                                *
    //                              undefined FUN_00505dc7()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00505dc7                                                 XREF[1]:     processNotify:00505dec(*)  
    //         00505dc7     NOP
    //         00505dc8     NOP
    //         00505dc9     NOP
    //         00505dca     NOP
    //         00505dcb     NOP
    //         00505dcc     NOP
    //         00505dcd     NOP
    //         00505dce     NOP
    //         00505dcf     NOP
    //                              * protected: virtual int __thiscall TribePriestUnitAIModule::processNotify(struct NotifyEvent *,unsi... *
    //                              int __thiscall processNotify(TribePriestUnitAIModule * this, NotifyE
    //              int               EAX:4          <RETURN>
    //              TribePriestUni    ECX:4 (auto)   this
    //              NotifyEvent *     Stack[0x4]:4   param_1                   XREF[1]:     00505dd1(R)  
    //              ulong             Stack[0x8]:4   param_2                   XREF[1]:     00505f96(R)  
    //                               ?processNotify@TribePriestUnitAIModule@@MAEHPAUNotifyEvent@  XREF[1]:     00575ef4(*)  
    //                               TribePriestUnitAIModule::processNotify
    //                              taiuaimd.cpp:1564 (1)
    //         00505dd0     PUSH       EBX
    //                              taiuaimd.cpp:1573 (40)
    //         00505dd1     MOV        EBX,dword ptr [ESP + param_1]
    //         00505dd5     PUSH       ESI
    //         00505dd6     PUSH       EDI
    //         00505dd7     MOV        EAX,dword ptr [EBX + 0x8]
    //         00505dda     MOV        ESI,this
    //         00505ddc     ADD        EAX,0xfffffe07
    //         00505de1     CMP        EAX,0x9
    //         00505de4     JA         switchD_00505df2::caseD_1fa
    //         00505dea     XOR        this,this
    //         00505dec     MOV        this,byte ptr [EAX + 0x505fc0]=>FUN_00505dc7
    //                               switchD_00505df2::switchD
    //         00505df2     JMP        dword ptr [this->field0_0x0*0x4 + switchD_0050   = 00505df9
    //                               switchD_00505df2::caseD_1fb                                  XREF[4]:     00505df2(j), 00505fac(*), 
    //                               switchD_00505df2::caseD_202                                               00505fb0(*), 00505fb8(*)  
    //                               switchD_00505df2::caseD_1f9
    //                              taiuaimd.cpp:1592 (24)
    //         00505df9     MOV        EDX,dword ptr [ESI + 0x4]
    //         00505dfc     MOV        this,dword ptr [EDX + 0xc]
    //         00505dff     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
    //         00505e04     TEST       EAX,EAX
    //         00505e06     JNZ        LAB_00505e53
    //         00505e08     CMP        dword ptr [ESI + 0x30],0x25c
    //         00505e0f     JNZ        LAB_00505e53
    //                              taiuaimd.cpp:1593 (7)
    //         00505e11     MOV        this,ESI
    //         00505e13     CALL       UnitAIModule::removeCurrentTarget                void removeCurrentTarget(UnitAIModule * this)
    //                              taiuaimd.cpp:1595 (50)
    //         00505e18     MOV        this,dword ptr [actionFile]                      = 00000000
    //         00505e1e     TEST       this,this
    //         00505e20     JZ         LAB_00505e4a
    //         00505e22     MOV        EAX,dword ptr [ESI + 0x4]
    //         00505e25     TEST       EAX,EAX
    //         00505e27     JZ         LAB_00505e2e
    //         00505e29     MOV        EAX,dword ptr [EAX + 0x4]
    //         00505e2c     JMP        LAB_00505e31
    //                               LAB_00505e2e                                                 XREF[1]:     00505e27(j)  
    //         00505e2e     OR         EAX,0xffffffff
    //                               LAB_00505e31                                                 XREF[1]:     00505e2c(j)  
    //         00505e31     PUSH       0x63b
    //         00505e36     PUSH       s_C:\msdev\work\age1_x1\taiuaimd.c               = "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp"
    //         00505e3b     PUSH       EAX
    //         00505e3c     PUSH       s_#%d_call_stopObject_%s_%d_                     = "#%d call stopObject %s %d\n"
    //         00505e41     PUSH       this
    //         00505e42     CALL       fprintf                                          undefined fprintf()
    //         00505e47     ADD        ESP,0x14
    //                               LAB_00505e4a                                                 XREF[1]:     00505e20(j)  
    //                              taiuaimd.cpp:1597 (4)
    //         00505e4a     MOV        EDI,dword ptr [ESI]
    //         00505e4c     PUSH       0x1
    //                              taiuaimd.cpp:1599 (5)
    //         00505e4e     JMP        LAB_00505ef5
    //                               LAB_00505e53                                                 XREF[2]:     00505e06(j), 00505e0f(j)  
    //                              taiuaimd.cpp:1603 (10)
    //         00505e53     MOV        EAX,dword ptr [ESI + 0x30]
    //         00505e56     CMP        EAX,0x25c
    //         00505e5b     JNZ        LAB_00505e86
    //                              taiuaimd.cpp:1607 (12)
    //         00505e5d     MOV        EDI,dword ptr [ESI]
    //         00505e5f     PUSH       0x0
    //         00505e61     MOV        this,ESI
    //         00505e63     CALL       dword ptr [EDI + 0xe4]
    //                              taiuaimd.cpp:1611 (5)
    //         00505e69     CMP        EAX,-0x1
    //         00505e6c     JZ         LAB_00505eb8
    //                              taiuaimd.cpp:1615 (13)
    //         00505e6e     PUSH       0x1
    //         00505e70     PUSH       EAX=>DAT_fffffff8
    //         00505e71     MOV        this,ESI
    //         00505e73     CALL       dword ptr [EDI + 0x6c]
    //         00505e76     CMP        EAX,0x1
    //         00505e79     JNZ        LAB_00505eb8
    //                              taiuaimd.cpp:1616 (5)
    //         00505e7b     MOV        EAX,0x3
    //                              taiuaimd.cpp:1687 (6)
    //         00505e80     POP        EDI
    //         00505e81     POP        ESI
    //         00505e82     POP        EBX
    //         00505e83     RET        0x8
    //                               LAB_00505e86                                                 XREF[1]:     00505e5b(j)  
    //                              taiuaimd.cpp:1627 (7)
    //         00505e86     CMP        EAX,0x25b
    //         00505e8b     JNZ        LAB_00505eb8
    //                              taiuaimd.cpp:1631 (14)
    //         00505e8d     MOV        EDI,dword ptr [ESI]
    //         00505e8f     PUSH       0x0
    //         00505e91     PUSH       0x0
    //         00505e93     MOV        this,ESI
    //         00505e95     CALL       dword ptr [EDI + 0xe0]
    //                              taiuaimd.cpp:1635 (5)
    //         00505e9b     CMP        EAX,-0x1
    //         00505e9e     JZ         LAB_00505eb8
    //                              taiuaimd.cpp:1639 (13)
    //         00505ea0     PUSH       0x1
    //         00505ea2     PUSH       EAX=>DAT_fffffff8
    //         00505ea3     MOV        this,ESI
    //         00505ea5     CALL       dword ptr [EDI + 0x70]
    //         00505ea8     CMP        EAX,0x1
    //         00505eab     JNZ        LAB_00505eb8
    //                              taiuaimd.cpp:1640 (5)
    //         00505ead     MOV        EAX,0x3
    //                              taiuaimd.cpp:1687 (6)
    //         00505eb2     POP        EDI
    //         00505eb3     POP        ESI
    //         00505eb4     POP        EBX
    //         00505eb5     RET        0x8
    //                               LAB_00505eb8                                                 XREF[5]:     00505e6c(j), 00505e79(j), 
    //                                                                                                         00505e8b(j), 00505e9e(j), 
    //                                                                                                         00505eab(j)  
    //                              taiuaimd.cpp:1651 (7)
    //         00505eb8     MOV        this,ESI
    //         00505eba     CALL       UnitAIModule::removeCurrentTarget                void removeCurrentTarget(UnitAIModule * this)
    //                              taiuaimd.cpp:1653 (50)
    //         00505ebf     MOV        this,dword ptr [actionFile]                      = 00000000
    //         00505ec5     TEST       this,this
    //         00505ec7     JZ         LAB_00505ef1
    //         00505ec9     MOV        EAX,dword ptr [ESI + 0x4]
    //         00505ecc     TEST       EAX,EAX
    //         00505ece     JZ         LAB_00505ed5
    //         00505ed0     MOV        EAX,dword ptr [EAX + 0x4]
    //         00505ed3     JMP        LAB_00505ed8
    //                               LAB_00505ed5                                                 XREF[1]:     00505ece(j)  
    //         00505ed5     OR         EAX,0xffffffff
    //                               LAB_00505ed8                                                 XREF[1]:     00505ed3(j)  
    //         00505ed8     PUSH       0x675
    //         00505edd     PUSH       s_C:\msdev\work\age1_x1\taiuaimd.c               = "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp"
    //         00505ee2     PUSH       EAX=>DAT_fffffff4
    //         00505ee3     PUSH       s_#%d_call_stopObject_%s_%d_                     = "#%d call stopObject %s %d\n"
    //         00505ee8     PUSH       this
    //         00505ee9     CALL       fprintf                                          undefined fprintf()
    //         00505eee     ADD        ESP,0x14
    //                               LAB_00505ef1                                                 XREF[1]:     00505ec7(j)  
    //                              taiuaimd.cpp:1655 (9)
    //         00505ef1     MOV        EDI,dword ptr [ESI]
    //         00505ef3     PUSH       0x0
    //                               LAB_00505ef5                                                 XREF[1]:     00505e4e(j)  
    //         00505ef5     MOV        this,ESI
    //         00505ef7     CALL       dword ptr [EDI + 0x58]
    //                              taiuaimd.cpp:1656 (6)
    //         00505efa     PUSH       EBX
    //         00505efb     MOV        this,ESI
    //         00505efd     CALL       dword ptr [EDI + 0x1c]
    //                              taiuaimd.cpp:1657 (5)
    //         00505f00     MOV        EAX,0x2
    //                              taiuaimd.cpp:1687 (6)
    //         00505f05     POP        EDI
    //         00505f06     POP        ESI
    //         00505f07     POP        EBX
    //         00505f08     RET        0x8
    //                               switchD_00505df2::caseD_1fc                                  XREF[2]:     00505df2(j), 00505fb4(*)  
    //                              taiuaimd.cpp:1666 (13)
    //         00505f0b     MOV        EAX,dword ptr [ESI + 0x34]
    //         00505f0e     MOV        this,ESI
    //         00505f10     PUSH       EAX
    //         00505f11     CALL       UnitAIModule::lookupObject                       RGE_Static_Object * lookupObject(UnitAIModule
    //         00505f16     MOV        EDI,EAX
    //                              taiuaimd.cpp:1667 (4)
    //         00505f18     TEST       EDI,EDI
    //         00505f1a     JZ         LAB_00505f4e
    //                              taiuaimd.cpp:1670 (35)
    //         00505f1c     FLD        float ptr [EDI + 0x3c]
    //         00505f1f     CALL       __ftol                                           undefined __ftol()
    //         00505f24     FLD        float ptr [EDI + 0x38]
    //         00505f27     PUSH       EAX
    //         00505f28     CALL       __ftol                                           undefined __ftol()
    //         00505f2d     MOV        this,dword ptr [ESI + 0x4]
    //         00505f30     PUSH       EAX
    //         00505f31     MOV        EDX,dword ptr [ECX + this->field12_0xc]
    //         00505f34     MOV        this,ESI
    //         00505f36     MOV        EAX,dword ptr [EDX + 0x38]
    //         00505f39     PUSH       EAX
    //         00505f3a     CALL       UnitAIModule::visibleStatus                      uchar visibleStatus(UnitAIModule * this, RGE_
    //                              taiuaimd.cpp:1673 (4)
    //         00505f3f     CMP        AL,0xf
    //         00505f41     JNZ        LAB_00505f4e
    //                              taiuaimd.cpp:1674 (5)
    //         00505f43     MOV        EAX,0x2
    //                              taiuaimd.cpp:1687 (6)
    //         00505f48     POP        EDI
    //         00505f49     POP        ESI
    //         00505f4a     POP        EBX
    //         00505f4b     RET        0x8
    //                               LAB_00505f4e                                                 XREF[2]:     00505f1a(j), 00505f41(j)  
    //                              taiuaimd.cpp:1677 (7)
    //         00505f4e     MOV        this,ESI
    //         00505f50     CALL       UnitAIModule::removeCurrentTarget                void removeCurrentTarget(UnitAIModule * this)
    //                              taiuaimd.cpp:1679 (50)
    //         00505f55     MOV        this,dword ptr [actionFile]                      = 00000000
    //         00505f5b     TEST       this,this
    //         00505f5d     JZ         LAB_00505f87
    //         00505f5f     MOV        EAX,dword ptr [ESI + 0x4]
    //         00505f62     TEST       EAX,EAX
    //         00505f64     JZ         LAB_00505f6b
    //         00505f66     MOV        EAX,dword ptr [EAX + 0x4]
    //         00505f69     JMP        LAB_00505f6e
    //                               LAB_00505f6b                                                 XREF[1]:     00505f64(j)  
    //         00505f6b     OR         EAX,0xffffffff
    //                               LAB_00505f6e                                                 XREF[1]:     00505f69(j)  
    //         00505f6e     PUSH       0x68f
    //         00505f73     PUSH       s_C:\msdev\work\age1_x1\taiuaimd.c               = "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp"
    //         00505f78     PUSH       EAX
    //         00505f79     PUSH       s_#%d_call_stopObject_%s_%d_                     = "#%d call stopObject %s %d\n"
    //         00505f7e     PUSH       this
    //         00505f7f     CALL       fprintf                                          undefined fprintf()
    //         00505f84     ADD        ESP,0x14
    //                               LAB_00505f87                                                 XREF[1]:     00505f5d(j)  
    //                              taiuaimd.cpp:1681 (9)
    //         00505f87     MOV        EDI,dword ptr [ESI]
    //         00505f89     PUSH       0x1
    //         00505f8b     MOV        this,ESI
    //         00505f8d     CALL       dword ptr [EDI + 0x58]
    //                              taiuaimd.cpp:1682 (6)
    //         00505f90     PUSH       EBX
    //         00505f91     MOV        this,ESI
    //         00505f93     CALL       dword ptr [EDI + 0x1c]
    //                               switchD_00505df2::caseD_1fd                                  XREF[3]:     00505de4(j), 00505df2(j), 
    //                               switchD_00505df2::caseD_1fe                                               00505fbc(*)  
    //                               switchD_00505df2::caseD_1ff
    //                               switchD_00505df2::caseD_200
    //                               switchD_00505df2::caseD_201
    //                               switchD_00505df2::caseD_1fa
    //                              taiuaimd.cpp:1686 (13)
    //         00505f96     MOV        this,dword ptr [ESP + param_2]
    //         00505f9a     PUSH       this
    //         00505f9b     PUSH       EBX=>DAT_fffffff8
    //         00505f9c     MOV        this,ESI
    //         00505f9e     CALL       UnitAIModule::processNotify                      int processNotify(UnitAIModule * this, Notify
    //                              taiuaimd.cpp:1687 (39)
    //         00505fa3     POP        EDI
    //         00505fa4     POP        ESI
    //         00505fa5     POP        EBX
    //         00505fa6     RET        0x8
    //                              *                                               FUNCTION                                                *
    //                              undefined FUN_00505fa9()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00505fa9
    //         00505fa9     NOP
    //         00505faa     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_00505df2::switchdataD_00505fac                       XREF[1]:     processNotify:00505df2(*)  
    //         00505fac     addr       switchD_00505df2::caseD_1f9
    //         00505fb0     addr       switchD_00505df2::caseD_1f9
    //         00505fb4     addr       switchD_00505df2::caseD_1fc
    //         00505fb8     addr       switchD_00505df2::caseD_1f9
    //         00505fbc     addr       switchD_00505df2::caseD_1fa
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_00505df2::switchdataD_00505fc0
    //         00505fc0     db         0h
    //         00505fc1     db         4h
    //         00505fc2     db         1h
    //         00505fc3     db         2h
    //         00505fc4     db         4h
    //         00505fc5     db         4h
    //         00505fc6     db         4h
    //         00505fc7     db         4h
    //         00505fc8     db         4h
    //         00505fc9     db         3h
    //         00505fca     ??         90h
    //         00505fcb     ??         90h
    //         00505fcc     ??         90h
    //         00505fcd     ??         90h
    //         00505fce     ??         90h
    //         00505fcf     ??         90h
    return 0;
}

int TribePriestUnitAIModule::processIdle(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall processIdle(TribePriestUnitAIModule * this, int param
    //              int               EAX:4          <RETURN>
    //              TribePriestUni    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //              undefined         Stack[-0x4]:1  local_4                   XREF[1]:     00506028(*)  
    //              float             Stack[-0x8]:4  distanceDiff
    //              float             Stack[-0xc]:4  xDiff
    //              float             Stack[-0x10]:4 yDiff
    //                               ?processIdle@TribePriestUnitAIModule@@MAEHH@Z                XREF[1]:     00575efc(*)  
    //                               TribePriestUnitAIModule::processIdle
    //                              taiuaimd.cpp:1692 (7)
    //         00505fd0     SUB        ESP,0xc
    //         00505fd3     PUSH       ESI
    //         00505fd4     MOV        ESI,this
    //         00505fd6     PUSH       EDI
    //                              taiuaimd.cpp:1698 (13)
    //         00505fd7     MOV        EAX,dword ptr [ESI + 0x4]
    //         00505fda     MOV        this,dword ptr [EAX + 0xc]
    //         00505fdd     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
    //         00505fe2     TEST       EAX,EAX
    //                              taiuaimd.cpp:1699 (6)
    //         00505fe4     JZ         LAB_0050612b
    //                              taiuaimd.cpp:1703 (14)
    //         00505fea     PUSH       0x1
    //         00505fec     MOV        this,ESI
    //         00505fee     CALL       UnitAIModule::processIdle                        int processIdle(UnitAIModule * this, int para
    //         00505ff3     CMP        EAX,0x6
    //         00505ff6     JNZ        LAB_00506000
    //                              taiuaimd.cpp:1756 (8)
    //         00505ff8     POP        EDI
    //         00505ff9     POP        ESI
    //         00505ffa     ADD        ESP,0xc
    //         00505ffd     RET        0x4
    //                               LAB_00506000                                                 XREF[1]:     00505ff6(j)  
    //                              taiuaimd.cpp:1707 (6)
    //         00506000     MOV        EDI,dword ptr [DAT_0087d7d8]
    //                              taiuaimd.cpp:1708 (24)
    //         00506006     PUSH       0x6ac
    //         0050600b     PUSH       s_C:\msdev\work\age1_x1\taiuaimd.c               = "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp"
    //         00506010     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         00506015     CDQ
    //         00506016     LEA        this,[EDI + 0x2]
    //         00506019     ADD        ESP,0x8
    //         0050601c     IDIV       this
    //                              taiuaimd.cpp:1711 (8)
    //         0050601e     TEST       EDI,EDI
    //         00506020     JLE        LAB_00506051
    //         00506022     CMP        EDX,EDI
    //         00506024     JLE        LAB_00506051
    //                              taiuaimd.cpp:1714 (17)
    //         00506026     MOV        EDI,dword ptr [ESI]
    //         00506028     LEA        EDX=>local_4,[ESP + 0x10]
    //         0050602c     PUSH       EDX
    //         0050602d     PUSH       0x1
    //         0050602f     MOV        this,ESI
    //         00506031     CALL       dword ptr [EDI + 0xe0]
    //                              taiuaimd.cpp:1715 (5)
    //         00506037     CMP        EAX,-0x1
    //         0050603a     JZ         LAB_00506051
    //                              taiuaimd.cpp:1720 (8)
    //         0050603c     PUSH       0x0
    //         0050603e     PUSH       EAX
    //         0050603f     MOV        this,ESI
    //         00506041     CALL       dword ptr [EDI + 0x70]
    //                              taiuaimd.cpp:1721 (5)
    //         00506044     MOV        EAX,0x6
    //                              taiuaimd.cpp:1756 (8)
    //         00506049     POP        EDI
    //         0050604a     POP        ESI
    //         0050604b     ADD        ESP,0xc
    //         0050604e     RET        0x4
    //                               LAB_00506051                                                 XREF[3]:     00506020(j), 00506024(j), 
    //                                                                                                         0050603a(j)  
    //                              taiuaimd.cpp:1731 (17)
    //         00506051     MOV        EDI,dword ptr [ESI]
    //         00506053     PUSH       0x0
    //         00506055     PUSH       -0x1
    //         00506057     PUSH       -0x1
    //         00506059     PUSH       0x2
    //         0050605b     PUSH       -0x1
    //         0050605d     MOV        this,ESI
    //         0050605f     CALL       dword ptr [EDI + 0x40]
    //                              taiuaimd.cpp:1732 (9)
    //         00506062     CMP        EAX,-0x1
    //         00506065     JZ         LAB_0050612b
    //                              taiuaimd.cpp:1736 (15)
    //         0050606b     PUSH       EAX
    //         0050606c     MOV        EAX,dword ptr [ESI + 0x4]
    //         0050606f     MOV        this,dword ptr [EAX + 0xc]
    //         00506072     MOV        this,dword ptr [ECX + this->field60_0x3c]
    //         00506075     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //                              taiuaimd.cpp:1738 (2)
    //         0050607a     TEST       EAX,EAX
    //                              taiuaimd.cpp:1739 (6)
    //         0050607c     JZ         LAB_0050612b
    //                              taiuaimd.cpp:1742 (19)
    //         00506082     FLD        float ptr [EAX + 0x3c]
    //         00506085     MOV        this,dword ptr [ESI + 0x4]
    //         00506088     FLD        float ptr [EAX + 0x38]
    //         0050608b     FSUB       float ptr [ECX + this->field56_0x38]
    //         0050608e     FXCH
    //         00506090     FSUB       float ptr [ECX + this->field60_0x3c]
    //         00506093     FXCH
    //                              taiuaimd.cpp:1745 (38)
    //         00506095     MOV        EDX,dword ptr [this->field0_0x0]
    //         00506097     FST        float ptr [ESP + 0xc]
    //         0050609b     FXCH
    //         0050609d     FST        float ptr [ESP + 0x8]
    //         005060a1     FXCH
    //         005060a3     FMUL       float ptr [ESP + 0xc]
    //         005060a7     FXCH
    //         005060a9     FMUL       float ptr [ESP + 0x8]
    //         005060ad     FADDP
    //         005060af     FSQRT
    //         005060b1     FSTP       float ptr [ESP + 0x10]
    //         005060b5     CALL       dword ptr [EDX + 0x10c]
    //                              taiuaimd.cpp:1746 (4)
    //         005060bb     FSUB       float ptr [ESP + 0x10]
    //                              taiuaimd.cpp:1747 (15)
    //         005060bf     FCOM       float ptr [DAT_005758c4]
    //         005060c5     FNSTSW     AX
    //         005060c7     TEST       AH,0x41
    //         005060ca     JZ         LAB_005060db
    //         005060cc     FSTP       ST0
    //                              taiuaimd.cpp:1755 (5)
    //         005060ce     MOV        EAX,0x5
    //                              taiuaimd.cpp:1756 (8)
    //         005060d3     POP        EDI
    //         005060d4     POP        ESI
    //         005060d5     ADD        ESP,0xc
    //         005060d8     RET        0x4
    //                               LAB_005060db                                                 XREF[1]:     005060ca(j)  
    //                              taiuaimd.cpp:1751 (67)
    //         005060db     FLD        float ptr [ESP + 0x8]
    //         005060df     FDIV       float ptr [ESP + 0x10]
    //         005060e3     MOV        EAX,dword ptr [ESI + 0x4]
    //         005060e6     PUSH       0x1
    //         005060e8     MOV        this,ESI
    //         005060ea     MOV        EDX,dword ptr [EAX + 0x40]
    //         005060ed     PUSH       EDX
    //         005060ee     PUSH       this
    //         005060ef     FLD        float ptr [ESP + 0x18]
    //         005060f3     FDIV       float ptr [ESP + 0x1c]
    //         005060f7     FXCH
    //         005060f9     FMUL       ST2
    //         005060fb     FXCH
    //         005060fd     FMUL       ST2
    //         005060ff     FXCH
    //         00506101     FCHS
    //         00506103     FADD       float ptr [EAX + 0x3c]
    //         00506106     FXCH
    //         00506108     FCHS
    //         0050610a     FADD       float ptr [EAX + 0x38]
    //         0050610d     FXCH
    //         0050610f     FSTP       float ptr [ESP]
    //         00506112     PUSH       this
    //         00506113     FSTP       float ptr [ESP]
    //         00506116     FSTP       ST0
    //         00506118     CALL       dword ptr [EDI + 0x9c]
    //                              taiuaimd.cpp:1752 (5)
    //         0050611e     MOV        EAX,0x6
    //                              taiuaimd.cpp:1756 (21)
    //         00506123     POP        EDI
    //         00506124     POP        ESI
    //         00506125     ADD        ESP,0xc
    //         00506128     RET        0x4
    //                               LAB_0050612b                                                 XREF[3]:     00505fe4(j), 00506065(j), 
    //                                                                                                         0050607c(j)  
    //         0050612b     POP        EDI
    //         0050612c     MOV        EAX,0x5
    //         00506131     POP        ESI
    //         00506132     ADD        ESP,0xc
    //         00506135     RET        0x4
    //         00506138     ??         90h
    //         00506139     NOP
    //         0050613a     NOP
    //         0050613b     NOP
    //         0050613c     NOP
    //         0050613d     NOP
    //         0050613e     NOP
    //         0050613f     NOP
    return 0;
}

int TribePriestUnitAIModule::processMisc() {
    /* TODO: Stub */
    //                              int __thiscall processMisc(TribePriestUnitAIModule * this)
    //              int               EAX:4          <RETURN>
    //              TribePriestUni    ECX:4 (auto)   this
    //                               ?processMisc@TribePriestUnitAIModule@@MAEHXZ                 XREF[1]:     00575f00(*)  
    //                               TribePriestUnitAIModule::processMisc
    //                              taiuaimd.cpp:1761 (5)
    //         00506140     PUSH       EBX
    //         00506141     PUSH       ESI
    //         00506142     MOV        ESI,this
    //         00506144     PUSH       EDI
    //                              taiuaimd.cpp:1763 (20)
    //         00506145     MOV        EAX,dword ptr [ESI + 0x4]
    //         00506148     MOV        this,dword ptr [EAX + 0xc]
    //         0050614b     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
    //         00506150     CMP        EAX,0x1
    //         00506153     JNZ        LAB_0050622e
    //                              taiuaimd.cpp:1765 (17)
    //         00506159     MOV        EDI,dword ptr [ESI + 0x4]
    //         0050615c     FLD        float ptr [EDI + 0x44]
    //         0050615f     FCOMP      float ptr [DAT_005758d4]
    //         00506165     FNSTSW     AX
    //         00506167     TEST       AH,0x1
    //                              taiuaimd.cpp:1766 (6)
    //         0050616a     JNZ        LAB_0050622e
    //                              taiuaimd.cpp:1771 (30)
    //         00506170     MOV        this,dword ptr [EDI + 0x184]
    //         00506176     CALL       RGE_Action_List::have_action                     uchar have_action(RGE_Action_List * this)
    //         0050617b     CMP        AL,0x1
    //         0050617d     JNZ        LAB_00506194
    //         0050617f     MOV        this,dword ptr [EDI + 0x184]
    //         00506185     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
    //         0050618a     CMP        byte ptr [EAX + 0xc],0x7
    //                              taiuaimd.cpp:1772 (6)
    //         0050618e     JZ         LAB_0050622e
    //                               LAB_00506194                                                 XREF[1]:     0050617d(j)  
    //                              taiuaimd.cpp:1775 (15)
    //         00506194     MOV        EDI,dword ptr [ESI]
    //         00506196     PUSH       0x0
    //         00506198     PUSH       0x1
    //         0050619a     PUSH       0x1
    //         0050619c     MOV        this,ESI
    //         0050619e     CALL       dword ptr [EDI + 0x30]
    //         005061a1     MOV        EBX,EAX
    //                              taiuaimd.cpp:1777 (16)
    //         005061a3     CMP        EBX,-0x1
    //         005061a6     JZ         LAB_0050622e
    //         005061ac     MOV        this,dword ptr [ESI + 0x34]
    //         005061af     CMP        this,EBX
    //         005061b1     JZ         LAB_0050622e
    //                              taiuaimd.cpp:1779 (8)
    //         005061b3     MOV        EAX,dword ptr [ESI + 0x28]
    //         005061b6     CMP        EAX,-0x1
    //         005061b9     JZ         LAB_0050621c
    //                              taiuaimd.cpp:1782 (40)
    //         005061bb     MOV        EDX,dword ptr [ESI + 0x2c]
    //         005061be     PUSH       EDX
    //         005061bf     MOV        EDX,dword ptr [ESI + 0x48]
    //         005061c2     PUSH       0x0=>DAT_fffffff8
    //         005061c4     PUSH       0x0=>DAT_fffffff4
    //         005061c6     PUSH       EDX=>DAT_fffffff0
    //         005061c7     MOV        EDX,dword ptr [ESI + 0x44]
    //         005061ca     PUSH       EDX
    //         005061cb     MOV        EDX,dword ptr [ESI + 0x40]
    //         005061ce     PUSH       EDX
    //         005061cf     MOV        EDX,dword ptr [ESI + 0x3c]
    //         005061d2     PUSH       EDX
    //         005061d3     PUSH       -0x1
    //         005061d5     PUSH       this
    //         005061d6     PUSH       EAX
    //         005061d7     MOV        EAX,dword ptr [ESI + 0x4]
    //         005061da     MOV        this,dword ptr [EAX + 0x4]
    //         005061dd     PUSH       this
    //         005061de     MOV        this,ESI
    //         005061e0     CALL       dword ptr [EDI + 0x10]
    //                              taiuaimd.cpp:1784 (50)
    //         005061e3     MOV        this,dword ptr [actionFile]                      = 00000000
    //         005061e9     TEST       this,this
    //         005061eb     JZ         LAB_00506215
    //         005061ed     MOV        EAX,dword ptr [ESI + 0x4]
    //         005061f0     TEST       EAX,EAX
    //         005061f2     JZ         LAB_005061f9
    //         005061f4     MOV        EAX,dword ptr [EAX + 0x4]
    //         005061f7     JMP        LAB_005061fc
    //                               LAB_005061f9                                                 XREF[1]:     005061f2(j)  
    //         005061f9     OR         EAX,0xffffffff
    //                               LAB_005061fc                                                 XREF[1]:     005061f7(j)  
    //         005061fc     PUSH       0x6f8
    //         00506201     PUSH       s_C:\msdev\work\age1_x1\taiuaimd.c               = "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp"
    //         00506206     PUSH       EAX=>DAT_fffffff4
    //         00506207     PUSH       s_#%d_call_stopObject_%s_%d_                     = "#%d call stopObject %s %d\n"
    //         0050620c     PUSH       this
    //         0050620d     CALL       fprintf                                          undefined fprintf()
    //         00506212     ADD        ESP,0x14
    //                               LAB_00506215                                                 XREF[1]:     005061eb(j)  
    //                              taiuaimd.cpp:1786 (7)
    //         00506215     PUSH       0x1
    //         00506217     MOV        this,ESI
    //         00506219     CALL       dword ptr [EDI + 0x58]
    //                               LAB_0050621c                                                 XREF[1]:     005061b9(j)  
    //                              taiuaimd.cpp:1789 (11)
    //         0050621c     PUSH       0x1
    //         0050621e     PUSH       EBX=>DAT_fffffff8
    //         0050621f     MOV        this,ESI
    //         00506221     CALL       dword ptr [EDI + 0x5c]
    //         00506224     CMP        EAX,0x1
    //                              taiuaimd.cpp:1790 (7)
    //         00506227     MOV        EAX,0xa
    //         0050622c     JZ         LAB_00506233
    //                               LAB_0050622e                                                 XREF[5]:     00506153(j), 0050616a(j), 
    //                                                                                                         0050618e(j), 005061a6(j), 
    //                                                                                                         005061b1(j)  
    //                              taiuaimd.cpp:1795 (5)
    //         0050622e     MOV        EAX,0x9
    //                               LAB_00506233                                                 XREF[1]:     0050622c(j)  
    //                              taiuaimd.cpp:1796 (4)
    //         00506233     POP        EDI
    //         00506234     POP        ESI
    //         00506235     POP        EBX
    //         00506236     RET
    //         00506237     ??         90h
    //         00506238     NOP
    //         00506239     NOP
    //         0050623a     NOP
    //         0050623b     NOP
    //         0050623c     NOP
    //         0050623d     NOP
    //         0050623e     NOP
    //         0050623f     NOP
    //                              * public: __thiscall TribeTradeShipUnitAIModule::TribeTradeShipUnitAIModule(class RGE_Static_Object ... *
    //                              undefined __thiscall TribeTradeShipUnitAIModule(TribeTradeShipUnitAI
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TribeTradeShip    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     0050625e(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     00506256(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00506270(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     005062d4(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00506262(W)  
    //                               ??0TribeTradeShipUnitAIModule@@QAE@PAVRGE_Static_Object@@H@Z XREF[1]:     initUnitAI:004cbb86(c)  
    //                               TribeTradeShipUnitAIModule::TribeTradeShipUnitAIModule
    //                              taiuaimd.cpp:1804 (46)
    //         00506240     PUSH       -0x1
    //         00506242     PUSH       FUN_00560ca8
    //         00506247     MOV        EAX,FS:[0x0]
    //         0050624d     PUSH       EAX
    //         0050624e     MOV        dword ptr FS:[0x0],ESP
    //         00506255     PUSH       this
    //         00506256     MOV        EAX,dword ptr [ESP + param_2]
    //         0050625a     PUSH       ESI
    //         0050625b     MOV        ESI,this
    //         0050625d     PUSH       EAX
    //         0050625e     MOV        this,dword ptr [ESP + param_1]
    //         00506262     MOV        dword ptr [ESP + local_10],ESI
    //         00506266     PUSH       this
    //         00506267     MOV        this,ESI
    //         00506269     CALL       UnitAIModule::UnitAIModule                       undefined UnitAIModule(UnitAIModule * this, R
    //                              taiuaimd.cpp:1809 (40)
    //         0050626e     PUSH       0x14
    //         00506270     MOV        dword ptr [ESP + local_4],0x0
    //         00506278     MOV        dword ptr [ESI],TribeTradeShipUnitAIModule::`v   = 005062f0
    //         0050627e     MOV        dword ptr [ESI + 0x128],0x5
    //         00506288     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0050628d     ADD        ESP,0x4
    //         00506290     MOV        dword ptr [ESI + 0x124],EAX
    //                              taiuaimd.cpp:1810 (4)
    //         00506296     TEST       EAX,EAX
    //         00506298     JZ         LAB_005062d4
    //                              taiuaimd.cpp:1811 (6)
    //         0050629a     MOV        dword ptr [EAX],0x3
    //                              taiuaimd.cpp:1812 (13)
    //         005062a0     MOV        EDX,dword ptr [ESI + 0x124]
    //         005062a6     MOV        dword ptr [EDX + 0x4],0x16
    //                              taiuaimd.cpp:1813 (13)
    //         005062ad     MOV        EAX,dword ptr [ESI + 0x124]
    //         005062b3     MOV        dword ptr [EAX + 0x8],0x14
    //                              taiuaimd.cpp:1814 (13)
    //         005062ba     MOV        this,dword ptr [ESI + 0x124]
    //         005062c0     MOV        dword ptr [ECX + this->field12_0xc],0x2
    //                              taiuaimd.cpp:1815 (13)
    //         005062c7     MOV        EDX,dword ptr [ESI + 0x124]
    //         005062cd     MOV        dword ptr [EDX + 0x10],0x15
    //                               LAB_005062d4                                                 XREF[1]:     00506298(j)  
    //                              taiuaimd.cpp:1817 (20)
    //         005062d4     MOV        this,dword ptr [ESP + local_c]
    //         005062d8     MOV        EAX,ESI
    //         005062da     MOV        dword ptr FS:[0x0],this
    //         005062e1     POP        ESI
    //         005062e2     ADD        ESP,0x10
    //         005062e5     RET        0x8
    //         005062e8     ??         90h
    //         005062e9     NOP
    //         005062ea     NOP
    //         005062eb     NOP
    //         005062ec     NOP
    //         005062ed     NOP
    //         005062ee     NOP
    //         005062ef     NOP
    //                              * public: virtual void * __thiscall TribeTradeShipUnitAIModule::`scalar deleting destructor'(unsigne... *
    //                              void * __thiscall `scalar_deleting_destructor'(TribeTradeShipUnitAIM
    //              void *            EAX:4          <RETURN>
    //              TribeTradeShip    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     005062f8(R)  
    //                               ??_ETribeTradeShipUnitAIModule@@UAEPAXI@Z                    XREF[1]:     00575f10(*)  
    //                               ??_GTribeTradeShipUnitAIModule@@UAEPAXI@Z
    //                               TribeTradeShipUnitAIModule::`scalar_deleting_destructor'
    //         005062f0     PUSH       ESI
    //         005062f1     MOV        ESI,this
    //         005062f3     CALL       TribeTradeShipUnitAIModule::~TribeTradeShipUni   void ~TribeTradeShipUnitAIModule(TribeTradeSh
    //         005062f8     TEST       byte ptr [ESP + param_1],0x1
    //         005062fd     JZ         LAB_00506308
    //         005062ff     PUSH       ESI
    //         00506300     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00506305     ADD        ESP,0x4
    //                               LAB_00506308                                                 XREF[1]:     005062fd(j)  
    //         00506308     MOV        EAX,ESI
    //         0050630a     POP        ESI
    //         0050630b     RET        0x4
    //                              *                                            THUNK FUNCTION                                             *
    //                              thunk void __thiscall ~UnitAIModule(UnitAIModule * this)
    //                                Thunked-Function: UnitAIModule::~UnitAIMo
    //              void              <VOID>         <RETURN>
    //              UnitAIModule *    ECX:4 (auto)   this
    //                               UnitAIModule::~UnitAIModule
    //         0050630e     NOP
    //         0050630f     NOP
    return 0;
}

TribeTradeShipUnitAIModule::~TribeTradeShipUnitAIModule() {
    /* TODO: Stub */
    //                              void __thiscall ~TribeTradeShipUnitAIModule(TribeTradeShipUnitAIModu
    //              void              <VOID>         <RETURN>
    //              TribeTradeShip    ECX:4 (auto)   this
    //                               ??1TribeTradeShipUnitAIModule@@UAE@XZ                        XREF[1]:     `scalar_deleting_destructor':00506
    //                               TribeTradeShipUnitAIModule::~TribeTradeShipUnitAIModule
    //         00506310     JMP        UnitAIModule::~UnitAIModule
    //         00506315     ??         90h
    //         00506316     NOP
    //         00506317     NOP
    //         00506318     NOP
    //         00506319     NOP
    //         0050631a     NOP
    //         0050631b     NOP
    //         0050631c     NOP
    //         0050631d     NOP
    //         0050631e     NOP
    //         0050631f     NOP
    //                              * protected: virtual int __thiscall TribeTradeShipUnitAIModule::processNotify(struct NotifyEvent *,u... *
    //                              int __thiscall processNotify(TribeTradeShipUnitAIModule * this, Noti
    //              int               EAX:4          <RETURN>
    //              TribeTradeShip    ECX:4 (auto)   this
    //              NotifyEvent *     Stack[0x4]:4   param_1                   XREF[2]:     00506322(R), 005063da(*)  
    //              ulong             Stack[0x8]:4   param_2                   XREF[2]:     00506346(R), 005063d4(*)  
    //                               ?processNotify@TribeTradeShipUnitAIModule@@MAEHPAUNotifyEve  XREF[1]:     00575fdc(*)  
    //                               TribeTradeShipUnitAIModule::processNotify
    //                              taiuaimd.cpp:1823 (2)
    //         00506320     PUSH       EBX
    //         00506321     PUSH       EBP
    //                              taiuaimd.cpp:1832 (36)
    //         00506322     MOV        EBP,dword ptr [ESP + param_1]
    //         00506326     PUSH       ESI
    //         00506327     PUSH       EDI
    //         00506328     MOV        ESI,this
    //         0050632a     MOV        EAX,dword ptr [EBP + 0x8]
    //         0050632d     SUB        EAX,0x1f4
    //         00506332     JZ         LAB_005064d9
    //         00506338     SUB        EAX,0xe
    //         0050633b     JZ         LAB_00506358
    //         0050633d     SUB        EAX,0xd
    //         00506340     JZ         LAB_005064d9
    //                              taiuaimd.cpp:1975 (11)
    //         00506346     MOV        EAX,dword ptr [ESP + param_2]
    //         0050634a     PUSH       EAX
    //         0050634b     PUSH       EBP
    //         0050634c     CALL       UnitAIModule::processNotify                      int processNotify(UnitAIModule * this, Notify
    //                              taiuaimd.cpp:1976 (7)
    //         00506351     POP        EDI
    //         00506352     POP        ESI
    //         00506353     POP        EBP
    //         00506354     POP        EBX
    //         00506355     RET        0x8
    //                               LAB_00506358                                                 XREF[1]:     0050633b(j)  
    //                              taiuaimd.cpp:1908 (10)
    //         00506358     MOV        EAX,dword ptr [ESI + 0x30]
    //         0050635b     CMP        EAX,0x267
    //         00506360     JNZ        LAB_005063c7
    //                              taiuaimd.cpp:1914 (19)
    //         00506362     MOV        EBX,dword ptr [ESI]
    //         00506364     PUSH       0x0
    //         00506366     PUSH       0x2d
    //         00506368     PUSH       0x2
    //         0050636a     MOV        EDI,dword ptr [EBX + 0x40]
    //         0050636d     PUSH       0x0
    //         0050636f     PUSH       -0x1
    //         00506371     MOV        this,ESI
    //         00506373     CALL       EDI
    //                              taiuaimd.cpp:1918 (5)
    //         00506375     CMP        EAX,-0x1
    //         00506378     JZ         LAB_00506393
    //                              taiuaimd.cpp:1919 (13)
    //         0050637a     PUSH       0x1
    //         0050637c     PUSH       EAX=>DAT_fffffff8
    //         0050637d     MOV        this,ESI
    //         0050637f     CALL       dword ptr [EBX + 0x7c]
    //         00506382     CMP        EAX,0x1
    //         00506385     JNZ        LAB_00506393
    //                              taiuaimd.cpp:1920 (5)
    //         00506387     MOV        EAX,0x6
    //                              taiuaimd.cpp:1976 (7)
    //         0050638c     POP        EDI
    //         0050638d     POP        ESI
    //         0050638e     POP        EBP
    //         0050638f     POP        EBX
    //         00506390     RET        0x8
    //                               LAB_00506393                                                 XREF[2]:     00506378(j), 00506385(j)  
    //                              taiuaimd.cpp:1922 (14)
    //         00506393     PUSH       0x0
    //         00506395     PUSH       offset DAT_fffffff8
    //         00506397     PUSH       offset DAT_fffffff4
    //         00506399     PUSH       offset DAT_fffffff0
    //         0050639b     PUSH       -0x1
    //         0050639d     MOV        this,ESI
    //         0050639f     CALL       EDI
    //                              taiuaimd.cpp:1926 (9)
    //         005063a1     CMP        EAX,-0x1
    //         005063a4     JZ         LAB_00506485
    //                              taiuaimd.cpp:1927 (17)
    //         005063aa     PUSH       0x1
    //         005063ac     PUSH       EAX=>DAT_fffffff8
    //         005063ad     MOV        this,ESI
    //         005063af     CALL       dword ptr [EBX + 0x7c]
    //         005063b2     CMP        EAX,0x1
    //         005063b5     JNZ        LAB_00506485
    //                              taiuaimd.cpp:1928 (5)
    //         005063bb     MOV        EAX,0x6
    //                              taiuaimd.cpp:1976 (7)
    //         005063c0     POP        EDI
    //         005063c1     POP        ESI
    //         005063c2     POP        EBP
    //         005063c3     POP        EBX
    //         005063c4     RET        0x8
    //                               LAB_005063c7                                                 XREF[1]:     00506360(j)  
    //                              taiuaimd.cpp:1934 (11)
    //         005063c7     CMP        EAX,0x25d
    //         005063cc     JNZ        LAB_00506485
    //                              taiuaimd.cpp:1940 (24)
    //         005063d2     MOV        EDI,dword ptr [ESI]
    //         005063d4     LEA        this=>param_2,[ESP + 0x18]
    //         005063d8     PUSH       0x1
    //         005063da     LEA        EDX=>param_1,[ESP + 0x18]
    //         005063de     PUSH       this
    //         005063df     PUSH       EDX
    //         005063e0     MOV        this,ESI
    //         005063e2     CALL       dword ptr [EDI + 0x48]
    //         005063e5     CMP        EAX,0x1
    //         005063e8     JNZ        LAB_0050643f
    //                              taiuaimd.cpp:1941 (17)
    //         005063ea     MOV        EAX,dword ptr [ESP + 0x18]
    //         005063ee     MOV        this,dword ptr [ESP + 0x14]
    //         005063f2     PUSH       EAX
    //         005063f3     PUSH       this=>DAT_fffffff8
    //         005063f4     MOV        this,ESI
    //         005063f6     CALL       UnitAIModule::addToWaypointQueue                 int addToWaypointQueue(UnitAIModule * this, i
    //                              taiuaimd.cpp:1945 (24)
    //         005063fb     MOV        EDX,dword ptr [ESP + 0x18]
    //         005063ff     MOV        EAX,dword ptr [ESP + 0x14]
    //         00506403     PUSH       0x1
    //         00506405     PUSH       EDX=>DAT_fffffff8
    //         00506406     PUSH       EAX=>DAT_fffffff4
    //         00506407     MOV        this,ESI
    //         00506409     CALL       dword ptr [EDI + 0x80]
    //         0050640f     TEST       EAX,EAX
    //         00506411     JNZ        LAB_00506485
    //                              taiuaimd.cpp:1946 (7)
    //         00506413     MOV        this,ESI
    //         00506415     CALL       UnitAIModule::removeCurrentTarget                void removeCurrentTarget(UnitAIModule * this)
    //                              taiuaimd.cpp:1948 (25)
    //         0050641a     MOV        this,dword ptr [actionFile]                      = 00000000
    //         00506420     TEST       this,this
    //         00506422     JZ         LAB_00506478
    //         00506424     MOV        EAX,dword ptr [ESI + 0x4]
    //         00506427     TEST       EAX,EAX
    //         00506429     JZ         LAB_00506435
    //         0050642b     MOV        EAX,dword ptr [EAX + 0x4]
    //         0050642e     PUSH       0x79c
    //                              taiuaimd.cpp:1954 (2)
    //         00506433     JMP        LAB_00506464
    //                               LAB_00506435                                                 XREF[1]:     00506429(j)  
    //                              taiuaimd.cpp:1948 (8)
    //         00506435     OR         EAX,0xffffffff
    //         00506438     PUSH       0x79c
    //                              taiuaimd.cpp:1954 (2)
    //         0050643d     JMP        LAB_00506464
    //                               LAB_0050643f                                                 XREF[1]:     005063e8(j)  
    //                              taiuaimd.cpp:1958 (7)
    //         0050643f     MOV        this,ESI
    //         00506441     CALL       UnitAIModule::removeCurrentTarget                void removeCurrentTarget(UnitAIModule * this)
    //                              taiuaimd.cpp:1960 (50)
    //         00506446     MOV        this,dword ptr [actionFile]                      = 00000000
    //         0050644c     TEST       this,this
    //         0050644e     JZ         LAB_00506478
    //         00506450     MOV        EAX,dword ptr [ESI + 0x4]
    //         00506453     TEST       EAX,EAX
    //         00506455     JZ         LAB_0050645c
    //         00506457     MOV        EAX,dword ptr [EAX + 0x4]
    //         0050645a     JMP        LAB_0050645f
    //                               LAB_0050645c                                                 XREF[1]:     00506455(j)  
    //         0050645c     OR         EAX,0xffffffff
    //                               LAB_0050645f                                                 XREF[1]:     0050645a(j)  
    //         0050645f     PUSH       0x7a8
    //                               LAB_00506464                                                 XREF[2]:     00506433(j), 0050643d(j)  
    //         00506464     PUSH       s_C:\msdev\work\age1_x1\taiuaimd.c               = "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp"
    //         00506469     PUSH       EAX=>DAT_fffffff4
    //         0050646a     PUSH       s_#%d_call_stopObject_%s_%d_                     = "#%d call stopObject %s %d\n"
    //         0050646f     PUSH       this
    //         00506470     CALL       fprintf                                          undefined fprintf()
    //         00506475     ADD        ESP,0x14
    //                               LAB_00506478                                                 XREF[2]:     00506422(j), 0050644e(j)  
    //                              taiuaimd.cpp:1962 (7)
    //         00506478     PUSH       0x1
    //         0050647a     MOV        this,ESI
    //         0050647c     CALL       dword ptr [EDI + 0x58]
    //                              taiuaimd.cpp:1963 (6)
    //         0050647f     PUSH       EBP
    //         00506480     MOV        this,ESI
    //         00506482     CALL       dword ptr [EDI + 0x1c]
    //                               LAB_00506485                                                 XREF[4]:     005063a4(j), 005063b5(j), 
    //                                                                                                         005063cc(j), 00506411(j)  
    //                              taiuaimd.cpp:1966 (7)
    //         00506485     MOV        this,ESI
    //         00506487     CALL       UnitAIModule::removeCurrentTarget                void removeCurrentTarget(UnitAIModule * this)
    //                              taiuaimd.cpp:1968 (50)
    //         0050648c     MOV        this,dword ptr [actionFile]                      = 00000000
    //         00506492     TEST       this,this
    //         00506494     JZ         LAB_005064be
    //         00506496     MOV        EAX,dword ptr [ESI + 0x4]
    //         00506499     TEST       EAX,EAX
    //         0050649b     JZ         LAB_005064a2
    //         0050649d     MOV        EAX,dword ptr [EAX + 0x4]
    //         005064a0     JMP        LAB_005064a5
    //                               LAB_005064a2                                                 XREF[1]:     0050649b(j)  
    //         005064a2     OR         EAX,0xffffffff
    //                               LAB_005064a5                                                 XREF[1]:     005064a0(j)  
    //         005064a5     PUSH       0x7b0
    //         005064aa     PUSH       s_C:\msdev\work\age1_x1\taiuaimd.c               = "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp"
    //         005064af     PUSH       EAX=>DAT_fffffff4
    //         005064b0     PUSH       s_#%d_call_stopObject_%s_%d_                     = "#%d call stopObject %s %d\n"
    //         005064b5     PUSH       this
    //         005064b6     CALL       fprintf                                          undefined fprintf()
    //         005064bb     ADD        ESP,0x14
    //                               LAB_005064be                                                 XREF[1]:     00506494(j)  
    //                              taiuaimd.cpp:1970 (9)
    //         005064be     MOV        EDI,dword ptr [ESI]
    //         005064c0     PUSH       0x1
    //         005064c2     MOV        this,ESI
    //         005064c4     CALL       dword ptr [EDI + 0x58]
    //                              taiuaimd.cpp:1971 (6)
    //         005064c7     PUSH       EBP
    //         005064c8     MOV        this,ESI
    //         005064ca     CALL       dword ptr [EDI + 0x1c]
    //                              taiuaimd.cpp:1972 (5)
    //         005064cd     MOV        EAX,0x2
    //                              taiuaimd.cpp:1976 (7)
    //         005064d2     POP        EDI
    //         005064d3     POP        ESI
    //         005064d4     POP        EBP
    //         005064d5     POP        EBX
    //         005064d6     RET        0x8
    //                               LAB_005064d9                                                 XREF[2]:     00506332(j), 00506340(j)  
    //                              taiuaimd.cpp:1841 (7)
    //         005064d9     MOV        EAX,dword ptr [EBP + 0x10]
    //         005064dc     TEST       EAX,EAX
    //         005064de     JG         LAB_00506518
    //                              taiuaimd.cpp:1846 (32)
    //         005064e0     MOV        EAX,dword ptr [ESI + 0x4]
    //         005064e3     MOV        EDI,dword ptr [EBP]
    //         005064e6     PUSH       0x0
    //         005064e8     PUSH       0x0
    //         005064ea     MOV        this,dword ptr [EAX + 0xc]
    //         005064ed     MOV        EAX,dword ptr [EAX + 0x4]
    //         005064f0     PUSH       EDI
    //         005064f1     PUSH       0x209
    //         005064f6     MOV        EDX,dword ptr [this->field0_0x0]
    //         005064f8     PUSH       EAX
    //         005064f9     PUSH       EAX
    //         005064fa     CALL       dword ptr [EDX + 0xe8]
    //                              taiuaimd.cpp:1847 (12)
    //         00506500     MOV        EAX,dword ptr [ESP + 0x18]
    //         00506504     MOV        this,ESI
    //         00506506     PUSH       EAX
    //         00506507     CALL       UnitAIModule::purgeNotifyQueue                   void purgeNotifyQueue(UnitAIModule * this, ul
    //                              taiuaimd.cpp:1848 (5)
    //         0050650c     MOV        EAX,0x4
    //                              taiuaimd.cpp:1976 (7)
    //         00506511     POP        EDI
    //         00506512     POP        ESI
    //         00506513     POP        EBP
    //         00506514     POP        EBX
    //         00506515     RET        0x8
    //                               LAB_00506518                                                 XREF[1]:     005064de(j)  
    //                              taiuaimd.cpp:1854 (23)
    //         00506518     MOV        EAX,dword ptr [ESI + 0x64]
    //         0050651b     TEST       EAX,EAX
    //         0050651d     JZ         LAB_0050652f
    //         0050651f     MOV        this,dword ptr [ESI + 0x4]
    //         00506522     MOV        this,dword ptr [ECX + this->field12_0xc]
    //         00506525     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
    //         0050652a     CMP        EAX,0x1
    //         0050652d     JNZ        LAB_0050654f
    //                               LAB_0050652f                                                 XREF[1]:     0050651d(j)  
    //                              taiuaimd.cpp:1856 (32)
    //         0050652f     MOV        EAX,dword ptr [ESI + 0x4]
    //         00506532     MOV        EDI,dword ptr [EBP]
    //         00506535     PUSH       0x0
    //         00506537     PUSH       0x0
    //         00506539     MOV        this,dword ptr [EAX + 0xc]
    //         0050653c     MOV        EAX,dword ptr [EAX + 0x4]
    //         0050653f     PUSH       EDI
    //         00506540     PUSH       0x201
    //         00506545     MOV        EDX,dword ptr [this->field0_0x0]
    //         00506547     PUSH       EAX
    //         00506548     PUSH       EAX
    //         00506549     CALL       dword ptr [EDX + 0xe8]
    //                               LAB_0050654f                                                 XREF[1]:     0050652d(j)  
    //                              taiuaimd.cpp:1864 (59)
    //         0050654f     MOV        this,dword ptr [ESI + 0x64]
    //         00506552     XOR        EAX,EAX
    //         00506554     TEST       this,this
    //         00506556     JLE        LAB_00506571
    //         00506558     MOV        EDX,dword ptr [ESI + 0x6c]
    //                               LAB_0050655b                                                 XREF[1]:     0050656f(j)  
    //         0050655b     CMP        EAX,EDX
    //         0050655d     JGE        LAB_00506571
    //         0050655f     MOV        EDI,dword ptr [ESI + 0x60]
    //         00506562     MOV        EBX,dword ptr [EBP]
    //         00506565     MOV        EDI,dword ptr [EDI + EAX*0x4]
    //         00506568     CMP        EDI,EBX
    //         0050656a     JZ         LAB_00506592
    //         0050656c     INC        EAX
    //         0050656d     CMP        EAX,this
    //         0050656f     JL         LAB_0050655b
    //                               LAB_00506571                                                 XREF[2]:     00506556(j), 0050655d(j)  
    //         00506571     MOV        EAX,dword ptr [ESI + 0x4]
    //         00506574     MOV        this,dword ptr [EAX + 0xc]
    //         00506577     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
    //         0050657c     TEST       EAX,EAX
    //         0050657e     JNZ        LAB_00506592
    //         00506580     MOV        EAX,dword ptr [EBP]
    //         00506583     MOV        this,dword ptr [ESI + 0x34]
    //         00506586     CMP        this,EAX
    //         00506588     JZ         LAB_00506592
    //                              taiuaimd.cpp:1865 (8)
    //         0050658a     PUSH       EAX
    //         0050658b     MOV        this,ESI
    //         0050658d     CALL       UnitAIModule::askForHelp                         void askForHelp(UnitAIModule * this, int para
    //                               LAB_00506592                                                 XREF[3]:     0050656a(j), 0050657e(j), 
    //                                                                                                         00506588(j)  
    //                              taiuaimd.cpp:1867 (131)
    //         00506592     MOV        this,dword ptr [ESI + 0x64]
    //         00506595     MOV        EBP,dword ptr [EBP]
    //         00506598     XOR        EAX,EAX
    //         0050659a     TEST       this,this
    //         0050659c     JLE        LAB_005065b2
    //         0050659e     MOV        EDX,dword ptr [ESI + 0x6c]
    //                               LAB_005065a1                                                 XREF[1]:     005065b0(j)  
    //         005065a1     CMP        EAX,EDX
    //         005065a3     JGE        LAB_005065b2
    //         005065a5     MOV        EDI,dword ptr [ESI + 0x60]
    //         005065a8     CMP        dword ptr [EDI + EAX*0x4],EBP
    //         005065ab     JZ         LAB_00506615
    //         005065ad     INC        EAX
    //         005065ae     CMP        EAX,this
    //         005065b0     JL         LAB_005065a1
    //                               LAB_005065b2                                                 XREF[2]:     0050659c(j), 005065a3(j)  
    //         005065b2     MOV        EDX,dword ptr [ESI + 0x6c]
    //         005065b5     DEC        EDX
    //         005065b6     CMP        this,EDX
    //         005065b8     JLE        LAB_00506605
    //         005065ba     LEA        EBX,[ECX + this->field1_0x1]
    //         005065bd     LEA        EAX,[EBX*0x4 + 0x0]
    //         005065c4     PUSH       EAX
    //         005065c5     CALL       operator_new                                     void * operator_new(uint param_1)
    //         005065ca     MOV        EDI,EAX
    //         005065cc     ADD        ESP,0x4
    //         005065cf     TEST       EDI,EDI
    //         005065d1     JZ         LAB_00506605
    //         005065d3     MOV        this,dword ptr [ESI + 0x6c]
    //         005065d6     XOR        EAX,EAX
    //         005065d8     TEST       this,this
    //         005065da     JLE        LAB_005065f3
    //                               LAB_005065dc                                                 XREF[1]:     005065f1(j)  
    //         005065dc     CMP        EAX,EBX
    //         005065de     JGE        LAB_005065f3
    //         005065e0     MOV        this,dword ptr [ESI + 0x60]
    //         005065e3     INC        EAX
    //         005065e4     MOV        EDX,dword ptr [this->field0_0x0 + EAX*0x4 + -0
    //         005065e8     MOV        dword ptr [EDI + EAX*0x4 + -0x4],EDX
    //         005065ec     MOV        this,dword ptr [ESI + 0x6c]
    //         005065ef     CMP        EAX,this
    //         005065f1     JL         LAB_005065dc
    //                               LAB_005065f3                                                 XREF[2]:     005065da(j), 005065de(j)  
    //         005065f3     MOV        EAX,dword ptr [ESI + 0x60]
    //         005065f6     PUSH       EAX
    //         005065f7     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         005065fc     ADD        ESP,0x4
    //         005065ff     MOV        dword ptr [ESI + 0x60],EDI
    //         00506602     MOV        dword ptr [ESI + 0x6c],EBX
    //                               LAB_00506605                                                 XREF[2]:     005065b8(j), 005065d1(j)  
    //         00506605     MOV        this,dword ptr [ESI + 0x64]
    //         00506608     MOV        EDX,dword ptr [ESI + 0x60]
    //         0050660b     MOV        dword ptr [EDX + this->field0_0x0*0x4],EBP
    //         0050660e     MOV        EAX,dword ptr [ESI + 0x64]
    //         00506611     INC        EAX
    //         00506612     MOV        dword ptr [ESI + 0x64],EAX
    //                               LAB_00506615                                                 XREF[1]:     005065ab(j)  
    //                              taiuaimd.cpp:1868 (13)
    //         00506615     MOV        this,dword ptr [ESI + 0x4]
    //         00506618     PUSH       0x1
    //         0050661a     MOV        EAX,dword ptr [this->field0_0x0]
    //         0050661c     CALL       dword ptr [EAX + 0xec]
    //                              taiuaimd.cpp:1872 (21)
    //         00506622     MOV        this,dword ptr [ESI + 0x4]
    //         00506625     MOV        this,dword ptr [ECX + this->field12_0xc]
    //         00506628     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
    //         0050662d     TEST       EAX,EAX
    //         0050662f     JNZ        LAB_00506643
    //         00506631     CMP        dword ptr [ESI + 0x28],-0x1
    //         00506635     JZ         LAB_00506643
    //                              taiuaimd.cpp:1876 (5)
    //         00506637     MOV        EAX,0x2
    //                              taiuaimd.cpp:1976 (7)
    //         0050663c     POP        EDI
    //         0050663d     POP        ESI
    //         0050663e     POP        EBP
    //         0050663f     POP        EBX
    //         00506640     RET        0x8
    //                               LAB_00506643                                                 XREF[2]:     0050662f(j), 00506635(j)  
    //                              taiuaimd.cpp:1879 (9)
    //         00506643     CMP        dword ptr [ESI + 0x30],0x262
    //         0050664a     JZ         LAB_005066b5
    //                              taiuaimd.cpp:1887 (48)
    //         0050664c     MOV        EDX,dword ptr [ESI + 0x2c]
    //         0050664f     MOV        EAX,dword ptr [ESI + 0x48]
    //         00506652     MOV        this,dword ptr [ESI + 0x44]
    //         00506655     PUSH       EDX
    //         00506656     MOV        EDX,dword ptr [ESI + 0x40]
    //         00506659     PUSH       0x0=>DAT_fffffff8
    //         0050665b     PUSH       0x0=>DAT_fffffff4
    //         0050665d     PUSH       EAX=>DAT_fffffff0
    //         0050665e     MOV        EAX,dword ptr [ESI + 0x3c]
    //         00506661     MOV        EDI,dword ptr [ESI]
    //         00506663     PUSH       this
    //         00506664     MOV        this,dword ptr [ESI + 0x34]
    //         00506667     PUSH       EDX
    //         00506668     MOV        EDX,dword ptr [ESI + 0x28]
    //         0050666b     PUSH       EAX
    //         0050666c     MOV        EAX,dword ptr [ESI + 0x4]
    //         0050666f     PUSH       -0x1
    //         00506671     PUSH       this
    //         00506672     MOV        this,dword ptr [EAX + 0x4]
    //         00506675     PUSH       EDX
    //         00506676     PUSH       this
    //         00506677     MOV        this,ESI
    //         00506679     CALL       dword ptr [EDI + 0x10]
    //                              taiuaimd.cpp:1889 (50)
    //         0050667c     MOV        this,dword ptr [actionFile]                      = 00000000
    //         00506682     TEST       this,this
    //         00506684     JZ         LAB_005066ae
    //         00506686     MOV        EAX,dword ptr [ESI + 0x4]
    //         00506689     TEST       EAX,EAX
    //         0050668b     JZ         LAB_00506692
    //         0050668d     MOV        EAX,dword ptr [EAX + 0x4]
    //         00506690     JMP        LAB_00506695
    //                               LAB_00506692                                                 XREF[1]:     0050668b(j)  
    //         00506692     OR         EAX,0xffffffff
    //                               LAB_00506695                                                 XREF[1]:     00506690(j)  
    //         00506695     PUSH       0x761
    //         0050669a     PUSH       s_C:\msdev\work\age1_x1\taiuaimd.c               = "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp"
    //         0050669f     PUSH       EAX=>DAT_fffffff4
    //         005066a0     PUSH       s_#%d_call_stopObject_%s_%d_                     = "#%d call stopObject %s %d\n"
    //         005066a5     PUSH       this
    //         005066a6     CALL       fprintf                                          undefined fprintf()
    //         005066ab     ADD        ESP,0x14
    //                               LAB_005066ae                                                 XREF[1]:     00506684(j)  
    //                              taiuaimd.cpp:1891 (7)
    //         005066ae     PUSH       0x1
    //         005066b0     MOV        this,ESI
    //         005066b2     CALL       dword ptr [EDI + 0x58]
    //                               LAB_005066b5                                                 XREF[1]:     0050664a(j)  
    //                              taiuaimd.cpp:1899 (12)
    //         005066b5     MOV        EDX,dword ptr [ESI]
    //         005066b7     PUSH       0x1
    //         005066b9     MOV        this,ESI
    //         005066bb     CALL       dword ptr [EDX + 0xa4]
    //                              taiuaimd.cpp:1976 (12)
    //         005066c1     POP        EDI
    //         005066c2     POP        ESI
    //         005066c3     POP        EBP
    //         005066c4     MOV        EAX,0x3
    //         005066c9     POP        EBX
    //         005066ca     RET        0x8
    //         005066cd     ??         90h
    //         005066ce     NOP
    //         005066cf     NOP
}

int TribeTradeShipUnitAIModule::processIdle(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall processIdle(TribeTradeShipUnitAIModule * this, int pa
    //              int               EAX:4          <RETURN>
    //              TribeTradeShip    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //              float             Stack[-0x8]:4  xDiff
    //              float             Stack[-0xc]:4  yDiff
    //                               ?processIdle@TribeTradeShipUnitAIModule@@MAEHH@Z             XREF[1]:     00575fe4(*)  
    //                               TribeTradeShipUnitAIModule::processIdle
    //                              taiuaimd.cpp:1981 (8)
    //         005066d0     SUB        ESP,0x8
    //         005066d3     PUSH       EBX
    //         005066d4     PUSH       ESI
    //         005066d5     MOV        ESI,this
    //         005066d7     PUSH       EDI
    //                              taiuaimd.cpp:2003 (13)
    //         005066d8     MOV        EAX,dword ptr [ESI + 0x4]
    //         005066db     MOV        this,dword ptr [EAX + 0xc]
    //         005066de     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
    //         005066e3     TEST       EAX,EAX
    //                              taiuaimd.cpp:2004 (6)
    //         005066e5     JZ         LAB_005067bc
    //                              taiuaimd.cpp:2007 (17)
    //         005066eb     MOV        EBX,dword ptr [ESI]
    //         005066ed     PUSH       0x0
    //         005066ef     PUSH       -0x1
    //         005066f1     PUSH       -0x1
    //         005066f3     PUSH       -0x1
    //         005066f5     PUSH       -0x1
    //         005066f7     MOV        this,ESI
    //         005066f9     CALL       dword ptr [EBX + 0x40]
    //                              taiuaimd.cpp:2008 (9)
    //         005066fc     CMP        EAX,-0x1
    //         005066ff     JZ         LAB_005067bc
    //                              taiuaimd.cpp:2009 (17)
    //         00506705     MOV        this,dword ptr [ESI + 0x4]
    //         00506708     PUSH       EAX
    //         00506709     MOV        EDX,dword ptr [ECX + this->field12_0xc]
    //         0050670c     MOV        this,dword ptr [EDX + 0x3c]
    //         0050670f     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //         00506714     MOV        EDI,EAX
    //                              taiuaimd.cpp:2011 (2)
    //         00506716     TEST       EDI,EDI
    //                              taiuaimd.cpp:2012 (6)
    //         00506718     JZ         LAB_005067bc
    //                              taiuaimd.cpp:2017 (11)
    //         0050671e     MOV        this,dword ptr [ESI + 0x4]
    //         00506721     MOV        EAX,dword ptr [this->field0_0x0]
    //         00506723     CALL       dword ptr [EAX + 0xfc]
    //                              taiuaimd.cpp:2023 (133)
    //         00506729     FLD        float ptr [EDI + 0x3c]
    //         0050672c     MOV        EAX,dword ptr [ESI + 0x4]
    //         0050672f     PUSH       0x1
    //         00506731     FLD        float ptr [EDI + 0x38]
    //         00506734     FSUB       float ptr [EAX + 0x38]
    //         00506737     FXCH
    //         00506739     FSUB       float ptr [EAX + 0x3c]
    //         0050673c     FXCH       ST2
    //         0050673e     FMUL       float ptr [DAT_005758d8]
    //         00506744     FXCH
    //         00506746     FST        float ptr [ESP + 0x14]
    //         0050674a     FXCH       ST2
    //         0050674c     FST        float ptr [ESP + 0x10]
    //         00506750     FXCH       ST2
    //         00506752     FMUL       float ptr [ESP + 0x14]
    //         00506756     FLD        float ptr [ESP + 0x10]
    //         0050675a     FXCH       ST3
    //         0050675c     FMUL       float ptr [ESP + 0x10]
    //         00506760     FLD        float ptr [ESP + 0x14]
    //         00506764     FXCH       ST3
    //         00506766     FSTP       float ptr [ESP + 0x10]
    //         0050676a     MOV        EDX,dword ptr [EAX + 0x40]
    //         0050676d     MOV        this,ESI
    //         0050676f     FADDP
    //         00506771     PUSH       EDX=>DAT_fffffff8
    //         00506772     PUSH       this=>DAT_fffffff4
    //         00506773     FSQRT
    //         00506775     FSTP       float ptr [ESP + 0x1c]
    //         00506779     FXCH
    //         0050677b     FDIV       float ptr [ESP + 0x1c]
    //         0050677f     FXCH
    //         00506781     FDIV       float ptr [ESP + 0x1c]
    //         00506785     FXCH
    //         00506787     FMUL       float ptr [ESP + 0x18]
    //         0050678b     FXCH
    //         0050678d     FMUL       float ptr [ESP + 0x18]
    //         00506791     FXCH
    //         00506793     FCHS
    //         00506795     FADD       float ptr [EAX + 0x3c]
    //         00506798     FXCH
    //         0050679a     FCHS
    //         0050679c     FADD       float ptr [EAX + 0x38]
    //         0050679f     FXCH
    //         005067a1     FSTP       float ptr [ESP]=>DAT_fffffff4
    //         005067a4     PUSH       this=>DAT_fffffff0
    //         005067a5     FSTP       float ptr [ESP]=>DAT_fffffff0
    //         005067a8     CALL       dword ptr [EBX + 0x9c]
    //                              taiuaimd.cpp:2024 (5)
    //         005067ae     MOV        EAX,0x6
    //                              taiuaimd.cpp:2027 (23)
    //         005067b3     POP        EDI
    //         005067b4     POP        ESI
    //         005067b5     POP        EBX
    //         005067b6     ADD        ESP,0x8
    //         005067b9     RET        0x4
    //                               LAB_005067bc                                                 XREF[3]:     005066e5(j), 005066ff(j), 
    //                                                                                                         00506718(j)  
    //         005067bc     POP        EDI
    //         005067bd     POP        ESI
    //         005067be     MOV        EAX,0x5
    //         005067c3     POP        EBX
    //         005067c4     ADD        ESP,0x8
    //         005067c7     RET        0x4
    //         005067ca     ??         90h
    //         005067cb     NOP
    //         005067cc     NOP
    //         005067cd     NOP
    //         005067ce     NOP
    //         005067cf     NOP
    //                              * public: __thiscall TribeTransportShipUnitAIModule::TribeTransportShipUnitAIModule(class RGE_Static... *
    //                              undefined __thiscall TribeTransportShipUnitAIModule(TribeTransportSh
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TribeTransport    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     005067ee(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     005067e6(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00506800(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00506864(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     005067f2(W)  
    //                               ??0TribeTransportShipUnitAIModule@@QAE@PAVRGE_Static_Object  XREF[1]:     initUnitAI:004cbbc4(c)  
    //                               TribeTransportShipUnitAIModule::TribeTransportShipUnitAIMod
    //                              taiuaimd.cpp:2035 (46)
    //         005067d0     PUSH       -0x1
    //         005067d2     PUSH       FUN_00560cc8
    //         005067d7     MOV        EAX,FS:[0x0]
    //         005067dd     PUSH       EAX
    //         005067de     MOV        dword ptr FS:[0x0],ESP
    //         005067e5     PUSH       this
    //         005067e6     MOV        EAX,dword ptr [ESP + param_2]
    //         005067ea     PUSH       ESI
    //         005067eb     MOV        ESI,this
    //         005067ed     PUSH       EAX
    //         005067ee     MOV        this,dword ptr [ESP + param_1]
    //         005067f2     MOV        dword ptr [ESP + local_10],ESI
    //         005067f6     PUSH       this
    //         005067f7     MOV        this,ESI
    //         005067f9     CALL       UnitAIModule::UnitAIModule                       undefined UnitAIModule(UnitAIModule * this, R
    //                              taiuaimd.cpp:2037 (40)
    //         005067fe     PUSH       0x14
    //         00506800     MOV        dword ptr [ESP + local_4],0x0
    //         00506808     MOV        dword ptr [ESI],TribeTransportShipUnitAIModule   = 00506880
    //         0050680e     MOV        dword ptr [ESI + 0x128],0x5
    //         00506818     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0050681d     ADD        ESP,0x4
    //         00506820     MOV        dword ptr [ESI + 0x124],EAX
    //                              taiuaimd.cpp:2038 (4)
    //         00506826     TEST       EAX,EAX
    //         00506828     JZ         LAB_00506864
    //                              taiuaimd.cpp:2039 (6)
    //         0050682a     MOV        dword ptr [EAX],0x3
    //                              taiuaimd.cpp:2040 (13)
    //         00506830     MOV        EDX,dword ptr [ESI + 0x124]
    //         00506836     MOV        dword ptr [EDX + 0x4],0x16
    //                              taiuaimd.cpp:2041 (13)
    //         0050683d     MOV        EAX,dword ptr [ESI + 0x124]
    //         00506843     MOV        dword ptr [EAX + 0x8],0x14
    //                              taiuaimd.cpp:2042 (13)
    //         0050684a     MOV        this,dword ptr [ESI + 0x124]
    //         00506850     MOV        dword ptr [ECX + this->field12_0xc],0x2
    //                              taiuaimd.cpp:2043 (13)
    //         00506857     MOV        EDX,dword ptr [ESI + 0x124]
    //         0050685d     MOV        dword ptr [EDX + 0x10],0x15
    //                               LAB_00506864                                                 XREF[1]:     00506828(j)  
    //                              taiuaimd.cpp:2045 (20)
    //         00506864     MOV        this,dword ptr [ESP + local_c]
    //         00506868     MOV        EAX,ESI
    //         0050686a     MOV        dword ptr FS:[0x0],this
    //         00506871     POP        ESI
    //         00506872     ADD        ESP,0x10
    //         00506875     RET        0x8
    //         00506878     ??         90h
    //         00506879     NOP
    //         0050687a     NOP
    //         0050687b     NOP
    //         0050687c     NOP
    //         0050687d     NOP
    //         0050687e     NOP
    //         0050687f     NOP
    //                              * public: virtual void * __thiscall TribeTransportShipUnitAIModule::`scalar deleting destructor'(uns... *
    //                              void * __thiscall `scalar_deleting_destructor'(TribeTransportShipUni
    //              void *            EAX:4          <RETURN>
    //              TribeTransport    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00506888(R)  
    //                               ??_ETribeTransportShipUnitAIModule@@UAEPAXI@Z                XREF[1]:     00575ff0(*)  
    //                               ??_GTribeTransportShipUnitAIModule@@UAEPAXI@Z
    //                               TribeTransportShipUnitAIModule::`scalar_deleting_destructor'
    //         00506880     PUSH       ESI
    //         00506881     MOV        ESI,this
    //         00506883     CALL       TribeTransportShipUnitAIModule::~TribeTranspor   void ~TribeTransportShipUnitAIModule(TribeTra
    //         00506888     TEST       byte ptr [ESP + param_1],0x1
    //         0050688d     JZ         LAB_00506898
    //         0050688f     PUSH       ESI
    //         00506890     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00506895     ADD        ESP,0x4
    //                               LAB_00506898                                                 XREF[1]:     0050688d(j)  
    //         00506898     MOV        EAX,ESI
    //         0050689a     POP        ESI
    //         0050689b     RET        0x4
    //                              *                                            THUNK FUNCTION                                             *
    //                              thunk void __thiscall ~UnitAIModule(UnitAIModule * this)
    //                                Thunked-Function: UnitAIModule::~UnitAIMo
    //              void              <VOID>         <RETURN>
    //              UnitAIModule *    ECX:4 (auto)   this
    //                               UnitAIModule::~UnitAIModule
    //         0050689e     NOP
    //         0050689f     NOP
    return 0;
}

TribeTransportShipUnitAIModule::~TribeTransportShipUnitAIModule() {
    /* TODO: Stub */
    //                              void __thiscall ~TribeTransportShipUnitAIModule(TribeTransportShipUn
    //              void              <VOID>         <RETURN>
    //              TribeTransport    ECX:4 (auto)   this
    //                               ??1TribeTransportShipUnitAIModule@@UAE@XZ                    XREF[1]:     `scalar_deleting_destructor':00506
    //                               TribeTransportShipUnitAIModule::~TribeTransportShipUnitAIMo
    //         005068a0     JMP        UnitAIModule::~UnitAIModule
    //         005068a5     ??         90h
    //         005068a6     NOP
    //         005068a7     NOP
    //         005068a8     NOP
    //         005068a9     NOP
    //         005068aa     NOP
    //         005068ab     NOP
    //         005068ac     NOP
    //         005068ad     NOP
    //         005068ae     NOP
    //         005068af     NOP
    //                              * protected: virtual int __thiscall TribeTransportShipUnitAIModule::processNotify(struct NotifyEvent... *
    //                              int __thiscall processNotify(TribeTransportShipUnitAIModule * this, 
    //              int               EAX:4          <RETURN>
    //              TribeTransport    ECX:4 (auto)   this
    //              NotifyEvent *     Stack[0x4]:4   param_1                   XREF[1]:     005068b4(R)  
    //              ulong             Stack[0x8]:4   param_2                   XREF[1]:     005068c9(R)  
    //                               ?processNotify@TribeTransportShipUnitAIModule@@MAEHPAUNotif  XREF[1]:     005760bc(*)  
    //                               TribeTransportShipUnitAIModule::processNotify
    //                              taiuaimd.cpp:2051 (4)
    //         005068b0     PUSH       EBX
    //         005068b1     PUSH       EBP
    //         005068b2     PUSH       ESI
    //         005068b3     PUSH       EDI
    //                              taiuaimd.cpp:2056 (21)
    //         005068b4     MOV        EDI,dword ptr [ESP + param_1]
    //         005068b8     MOV        ESI,this
    //         005068ba     MOV        EAX,dword ptr [EDI + 0x8]
    //         005068bd     SUB        EAX,0x1f4
    //         005068c2     JZ         LAB_005068db
    //         005068c4     SUB        EAX,0x1b
    //         005068c7     JZ         LAB_005068db
    //                              taiuaimd.cpp:2116 (11)
    //         005068c9     MOV        EAX,dword ptr [ESP + param_2]
    //         005068cd     PUSH       EAX
    //         005068ce     PUSH       EDI
    //         005068cf     CALL       UnitAIModule::processNotify                      int processNotify(UnitAIModule * this, Notify
    //                              taiuaimd.cpp:2117 (7)
    //         005068d4     POP        EDI
    //         005068d5     POP        ESI
    //         005068d6     POP        EBP
    //         005068d7     POP        EBX
    //         005068d8     RET        0x8
    //                               LAB_005068db                                                 XREF[2]:     005068c2(j), 005068c7(j)  
    //                              taiuaimd.cpp:2066 (7)
    //         005068db     MOV        EAX,dword ptr [EDI + 0x10]
    //         005068de     TEST       EAX,EAX
    //         005068e0     JG         LAB_00506919
    //                              taiuaimd.cpp:2071 (31)
    //         005068e2     MOV        EAX,dword ptr [ESI + 0x4]
    //         005068e5     MOV        EDI,dword ptr [EDI]
    //         005068e7     PUSH       0x0
    //         005068e9     PUSH       0x0
    //         005068eb     MOV        this,dword ptr [EAX + 0xc]
    //         005068ee     MOV        EAX,dword ptr [EAX + 0x4]
    //         005068f1     PUSH       EDI
    //         005068f2     PUSH       0x209
    //         005068f7     MOV        EDX,dword ptr [this->field0_0x0]
    //         005068f9     PUSH       EAX
    //         005068fa     PUSH       EAX
    //         005068fb     CALL       dword ptr [EDX + 0xe8]
    //                              taiuaimd.cpp:2072 (12)
    //         00506901     MOV        EAX,dword ptr [ESP + 0x18]
    //         00506905     MOV        this,ESI
    //         00506907     PUSH       EAX
    //         00506908     CALL       UnitAIModule::purgeNotifyQueue                   void purgeNotifyQueue(UnitAIModule * this, ul
    //                              taiuaimd.cpp:2073 (5)
    //         0050690d     MOV        EAX,0x4
    //                              taiuaimd.cpp:2117 (7)
    //         00506912     POP        EDI
    //         00506913     POP        ESI
    //         00506914     POP        EBP
    //         00506915     POP        EBX
    //         00506916     RET        0x8
    //                               LAB_00506919                                                 XREF[1]:     005068e0(j)  
    //                              taiuaimd.cpp:2079 (23)
    //         00506919     MOV        EAX,dword ptr [ESI + 0x64]
    //         0050691c     TEST       EAX,EAX
    //         0050691e     JZ         LAB_00506930
    //         00506920     MOV        this,dword ptr [ESI + 0x4]
    //         00506923     MOV        this,dword ptr [ECX + this->field12_0xc]
    //         00506926     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
    //         0050692b     CMP        EAX,0x1
    //         0050692e     JNZ        LAB_0050694f
    //                               LAB_00506930                                                 XREF[1]:     0050691e(j)  
    //                              taiuaimd.cpp:2081 (31)
    //         00506930     MOV        EAX,dword ptr [ESI + 0x4]
    //         00506933     MOV        EBX,dword ptr [EDI]
    //         00506935     PUSH       0x0
    //         00506937     PUSH       0x0
    //         00506939     MOV        this,dword ptr [EAX + 0xc]
    //         0050693c     MOV        EAX,dword ptr [EAX + 0x4]
    //         0050693f     PUSH       EBX
    //         00506940     PUSH       0x201
    //         00506945     MOV        EDX,dword ptr [this->field0_0x0]
    //         00506947     PUSH       EAX
    //         00506948     PUSH       EAX
    //         00506949     CALL       dword ptr [EDX + 0xe8]
    //                               LAB_0050694f                                                 XREF[1]:     0050692e(j)  
    //                              taiuaimd.cpp:2089 (57)
    //         0050694f     MOV        this,dword ptr [ESI + 0x64]
    //         00506952     XOR        EAX,EAX
    //         00506954     TEST       this,this
    //         00506956     JLE        LAB_00506970
    //         00506958     MOV        EDX,dword ptr [ESI + 0x6c]
    //                               LAB_0050695b                                                 XREF[1]:     0050696e(j)  
    //         0050695b     CMP        EAX,EDX
    //         0050695d     JGE        LAB_00506970
    //         0050695f     MOV        EBX,dword ptr [ESI + 0x60]
    //         00506962     MOV        EBP,dword ptr [EDI]
    //         00506964     MOV        EBX,dword ptr [EBX + EAX*0x4]
    //         00506967     CMP        EBX,EBP
    //         00506969     JZ         LAB_00506990
    //         0050696b     INC        EAX
    //         0050696c     CMP        EAX,this
    //         0050696e     JL         LAB_0050695b
    //                               LAB_00506970                                                 XREF[2]:     00506956(j), 0050695d(j)  
    //         00506970     MOV        EAX,dword ptr [ESI + 0x4]
    //         00506973     MOV        this,dword ptr [EAX + 0xc]
    //         00506976     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
    //         0050697b     TEST       EAX,EAX
    //         0050697d     JNZ        LAB_00506990
    //         0050697f     MOV        EAX,dword ptr [EDI]
    //         00506981     MOV        this,dword ptr [ESI + 0x34]
    //         00506984     CMP        this,EAX
    //         00506986     JZ         LAB_00506990
    //                              taiuaimd.cpp:2090 (8)
    //         00506988     PUSH       EAX
    //         00506989     MOV        this,ESI
    //         0050698b     CALL       UnitAIModule::askForHelp                         void askForHelp(UnitAIModule * this, int para
    //                               LAB_00506990                                                 XREF[3]:     00506969(j), 0050697d(j), 
    //                                                                                                         00506986(j)  
    //                              taiuaimd.cpp:2092 (130)
    //         00506990     MOV        this,dword ptr [ESI + 0x64]
    //         00506993     MOV        EDI,dword ptr [EDI]
    //         00506995     XOR        EAX,EAX
    //         00506997     TEST       this,this
    //         00506999     JLE        LAB_005069af
    //         0050699b     MOV        EDX,dword ptr [ESI + 0x6c]
    //                               LAB_0050699e                                                 XREF[1]:     005069ad(j)  
    //         0050699e     CMP        EAX,EDX
    //         005069a0     JGE        LAB_005069af
    //         005069a2     MOV        EBX,dword ptr [ESI + 0x60]
    //         005069a5     CMP        dword ptr [EBX + EAX*0x4],EDI
    //         005069a8     JZ         LAB_00506a12
    //         005069aa     INC        EAX
    //         005069ab     CMP        EAX,this
    //         005069ad     JL         LAB_0050699e
    //                               LAB_005069af                                                 XREF[2]:     00506999(j), 005069a0(j)  
    //         005069af     MOV        EDX,dword ptr [ESI + 0x6c]
    //         005069b2     DEC        EDX
    //         005069b3     CMP        this,EDX
    //         005069b5     JLE        LAB_00506a02
    //         005069b7     LEA        EBP,[ECX + this->field1_0x1]
    //         005069ba     LEA        EAX,[EBP*0x4 + 0x0]
    //         005069c1     PUSH       EAX
    //         005069c2     CALL       operator_new                                     void * operator_new(uint param_1)
    //         005069c7     MOV        EBX,EAX
    //         005069c9     ADD        ESP,0x4
    //         005069cc     TEST       EBX,EBX
    //         005069ce     JZ         LAB_00506a02
    //         005069d0     MOV        this,dword ptr [ESI + 0x6c]
    //         005069d3     XOR        EAX,EAX
    //         005069d5     TEST       this,this
    //         005069d7     JLE        LAB_005069f0
    //                               LAB_005069d9                                                 XREF[1]:     005069ee(j)  
    //         005069d9     CMP        EAX,EBP
    //         005069db     JGE        LAB_005069f0
    //         005069dd     MOV        this,dword ptr [ESI + 0x60]
    //         005069e0     INC        EAX
    //         005069e1     MOV        EDX,dword ptr [this->field0_0x0 + EAX*0x4 + -0
    //         005069e5     MOV        dword ptr [EBX + EAX*0x4 + -0x4],EDX
    //         005069e9     MOV        this,dword ptr [ESI + 0x6c]
    //         005069ec     CMP        EAX,this
    //         005069ee     JL         LAB_005069d9
    //                               LAB_005069f0                                                 XREF[2]:     005069d7(j), 005069db(j)  
    //         005069f0     MOV        EAX,dword ptr [ESI + 0x60]
    //         005069f3     PUSH       EAX
    //         005069f4     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         005069f9     ADD        ESP,0x4
    //         005069fc     MOV        dword ptr [ESI + 0x60],EBX
    //         005069ff     MOV        dword ptr [ESI + 0x6c],EBP
    //                               LAB_00506a02                                                 XREF[2]:     005069b5(j), 005069ce(j)  
    //         00506a02     MOV        this,dword ptr [ESI + 0x64]
    //         00506a05     MOV        EDX,dword ptr [ESI + 0x60]
    //         00506a08     MOV        dword ptr [EDX + this->field0_0x0*0x4],EDI
    //         00506a0b     MOV        EAX,dword ptr [ESI + 0x64]
    //         00506a0e     INC        EAX
    //         00506a0f     MOV        dword ptr [ESI + 0x64],EAX
    //                               LAB_00506a12                                                 XREF[1]:     005069a8(j)  
    //                              taiuaimd.cpp:2093 (13)
    //         00506a12     MOV        this,dword ptr [ESI + 0x4]
    //         00506a15     PUSH       0x1
    //         00506a17     MOV        EAX,dword ptr [this->field0_0x0]
    //         00506a19     CALL       dword ptr [EAX + 0xec]
    //                              taiuaimd.cpp:2096 (6)
    //         00506a1f     CMP        dword ptr [ESI + 0x28],-0x1
    //         00506a23     JZ         LAB_00506a31
    //                              taiuaimd.cpp:2100 (5)
    //         00506a25     MOV        EAX,0x2
    //                              taiuaimd.cpp:2117 (7)
    //         00506a2a     POP        EDI
    //         00506a2b     POP        ESI
    //         00506a2c     POP        EBP
    //         00506a2d     POP        EBX
    //         00506a2e     RET        0x8
    //                               LAB_00506a31                                                 XREF[1]:     00506a23(j)  
    //                              taiuaimd.cpp:2109 (3)
    //         00506a31     MOV        EDI,dword ptr [ESI + 0x4]
    //                              taiuaimd.cpp:2111 (32)
    //         00506a34     MOV        this,dword ptr [EDI + 0x184]
    //         00506a3a     CALL       RGE_Action_List::have_action                     uchar have_action(RGE_Action_List * this)
    //         00506a3f     TEST       AL,AL
    //         00506a41     JZ         LAB_00506a54
    //         00506a43     MOV        this,dword ptr [EDI + 0x184]
    //         00506a49     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
    //         00506a4e     CMP        byte ptr [EAX + 0xc],0x2
    //         00506a52     JNZ        LAB_00506a60
    //                               LAB_00506a54                                                 XREF[1]:     00506a41(j)  
    //                              taiuaimd.cpp:2112 (12)
    //         00506a54     MOV        EDX,dword ptr [ESI]
    //         00506a56     PUSH       0x1
    //         00506a58     MOV        this,ESI
    //         00506a5a     CALL       dword ptr [EDX + 0xa4]
    //                               LAB_00506a60                                                 XREF[1]:     00506a52(j)  
    //                              taiuaimd.cpp:2117 (12)
    //         00506a60     POP        EDI
    //         00506a61     POP        ESI
    //         00506a62     POP        EBP
    //         00506a63     MOV        EAX,0x3
    //         00506a68     POP        EBX
    //         00506a69     RET        0x8
    //         00506a6c     ??         90h
    //         00506a6d     NOP
    //         00506a6e     NOP
    //         00506a6f     NOP
}

int TribeTransportShipUnitAIModule::processIdle(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall processIdle(TribeTransportShipUnitAIModule * this, in
    //              int               EAX:4          <RETURN>
    //              TribeTransport    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //              float             Stack[-0x8]:4  xDiff
    //              float             Stack[-0xc]:4  yDiff
    //                               ?processIdle@TribeTransportShipUnitAIModule@@MAEHH@Z         XREF[1]:     005760c4(*)  
    //                               TribeTransportShipUnitAIModule::processIdle
    //                              taiuaimd.cpp:2122 (8)
    //         00506a70     SUB        ESP,0x8
    //         00506a73     PUSH       EBX
    //         00506a74     PUSH       ESI
    //         00506a75     MOV        ESI,this
    //         00506a77     PUSH       EDI
    //                              taiuaimd.cpp:2123 (13)
    //         00506a78     MOV        EAX,dword ptr [ESI + 0x4]
    //         00506a7b     MOV        this,dword ptr [EAX + 0xc]
    //         00506a7e     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
    //         00506a83     TEST       EAX,EAX
    //                              taiuaimd.cpp:2124 (6)
    //         00506a85     JZ         LAB_00506b5c
    //                              taiuaimd.cpp:2127 (17)
    //         00506a8b     MOV        EBX,dword ptr [ESI]
    //         00506a8d     PUSH       0x0
    //         00506a8f     PUSH       -0x1
    //         00506a91     PUSH       -0x1
    //         00506a93     PUSH       -0x1
    //         00506a95     PUSH       -0x1
    //         00506a97     MOV        this,ESI
    //         00506a99     CALL       dword ptr [EBX + 0x40]
    //                              taiuaimd.cpp:2128 (9)
    //         00506a9c     CMP        EAX,-0x1
    //         00506a9f     JZ         LAB_00506b5c
    //                              taiuaimd.cpp:2129 (17)
    //         00506aa5     MOV        this,dword ptr [ESI + 0x4]
    //         00506aa8     PUSH       EAX
    //         00506aa9     MOV        EDX,dword ptr [ECX + this->field12_0xc]
    //         00506aac     MOV        this,dword ptr [EDX + 0x3c]
    //         00506aaf     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //         00506ab4     MOV        EDI,EAX
    //                              taiuaimd.cpp:2131 (2)
    //         00506ab6     TEST       EDI,EDI
    //                              taiuaimd.cpp:2132 (6)
    //         00506ab8     JZ         LAB_00506b5c
    //                              taiuaimd.cpp:2137 (11)
    //         00506abe     MOV        this,dword ptr [ESI + 0x4]
    //         00506ac1     MOV        EAX,dword ptr [this->field0_0x0]
    //         00506ac3     CALL       dword ptr [EAX + 0xfc]
    //                              taiuaimd.cpp:2143 (133)
    //         00506ac9     FLD        float ptr [EDI + 0x3c]
    //         00506acc     MOV        EAX,dword ptr [ESI + 0x4]
    //         00506acf     PUSH       0x1
    //         00506ad1     FLD        float ptr [EDI + 0x38]
    //         00506ad4     FSUB       float ptr [EAX + 0x38]
    //         00506ad7     FXCH
    //         00506ad9     FSUB       float ptr [EAX + 0x3c]
    //         00506adc     FXCH       ST2
    //         00506ade     FMUL       float ptr [DAT_005758d8]
    //         00506ae4     FXCH
    //         00506ae6     FST        float ptr [ESP + 0x14]
    //         00506aea     FXCH       ST2
    //         00506aec     FST        float ptr [ESP + 0x10]
    //         00506af0     FXCH       ST2
    //         00506af2     FMUL       float ptr [ESP + 0x14]
    //         00506af6     FLD        float ptr [ESP + 0x10]
    //         00506afa     FXCH       ST3
    //         00506afc     FMUL       float ptr [ESP + 0x10]
    //         00506b00     FLD        float ptr [ESP + 0x14]
    //         00506b04     FXCH       ST3
    //         00506b06     FSTP       float ptr [ESP + 0x10]
    //         00506b0a     MOV        EDX,dword ptr [EAX + 0x40]
    //         00506b0d     MOV        this,ESI
    //         00506b0f     FADDP
    //         00506b11     PUSH       EDX=>DAT_fffffff8
    //         00506b12     PUSH       this=>DAT_fffffff4
    //         00506b13     FSQRT
    //         00506b15     FSTP       float ptr [ESP + 0x1c]
    //         00506b19     FXCH
    //         00506b1b     FDIV       float ptr [ESP + 0x1c]
    //         00506b1f     FXCH
    //         00506b21     FDIV       float ptr [ESP + 0x1c]
    //         00506b25     FXCH
    //         00506b27     FMUL       float ptr [ESP + 0x18]
    //         00506b2b     FXCH
    //         00506b2d     FMUL       float ptr [ESP + 0x18]
    //         00506b31     FXCH
    //         00506b33     FCHS
    //         00506b35     FADD       float ptr [EAX + 0x3c]
    //         00506b38     FXCH
    //         00506b3a     FCHS
    //         00506b3c     FADD       float ptr [EAX + 0x38]
    //         00506b3f     FXCH
    //         00506b41     FSTP       float ptr [ESP]=>DAT_fffffff4
    //         00506b44     PUSH       this=>DAT_fffffff0
    //         00506b45     FSTP       float ptr [ESP]=>DAT_fffffff0
    //         00506b48     CALL       dword ptr [EBX + 0x9c]
    //                              taiuaimd.cpp:2144 (5)
    //         00506b4e     MOV        EAX,0x6
    //                              taiuaimd.cpp:2147 (23)
    //         00506b53     POP        EDI
    //         00506b54     POP        ESI
    //         00506b55     POP        EBX
    //         00506b56     ADD        ESP,0x8
    //         00506b59     RET        0x4
    //                               LAB_00506b5c                                                 XREF[3]:     00506a85(j), 00506a9f(j), 
    //                                                                                                         00506ab8(j)  
    //         00506b5c     POP        EDI
    //         00506b5d     POP        ESI
    //         00506b5e     MOV        EAX,0x5
    //         00506b63     POP        EBX
    //         00506b64     ADD        ESP,0x8
    //         00506b67     RET        0x4
    //         00506b6a     ??         90h
    //         00506b6b     NOP
    //         00506b6c     NOP
    //         00506b6d     NOP
    //         00506b6e     NOP
    //         00506b6f     NOP
    //                              * public: __thiscall TribeFishingShipUnitAIModule::TribeFishingShipUnitAIModule(class RGE_Static_Obj... *
    //                              undefined __thiscall TribeFishingShipUnitAIModule(TribeFishingShipUn
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TribeFishingSh    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00506b8e(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     00506b86(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00506ba0(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00506c2b(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00506b92(W)  
    //                               ??0TribeFishingShipUnitAIModule@@QAE@PAVRGE_Static_Object@@  XREF[1]:     initUnitAI:004cbb48(c)  
    //                               TribeFishingShipUnitAIModule::TribeFishingShipUnitAIModule
    //                              taiuaimd.cpp:2155 (46)
    //         00506b70     PUSH       -0x1
    //         00506b72     PUSH       FUN_00560ce8
    //         00506b77     MOV        EAX,FS:[0x0]
    //         00506b7d     PUSH       EAX
    //         00506b7e     MOV        dword ptr FS:[0x0],ESP
    //         00506b85     PUSH       this
    //         00506b86     MOV        EAX,dword ptr [ESP + param_2]
    //         00506b8a     PUSH       ESI
    //         00506b8b     MOV        ESI,this
    //         00506b8d     PUSH       EAX
    //         00506b8e     MOV        this,dword ptr [ESP + param_1]
    //         00506b92     MOV        dword ptr [ESP + local_10],ESI
    //         00506b96     PUSH       this
    //         00506b97     MOV        this,ESI
    //         00506b99     CALL       UnitAIModule::UnitAIModule                       undefined UnitAIModule(UnitAIModule * this, R
    //                              taiuaimd.cpp:2157 (40)
    //         00506b9e     PUSH       0x20
    //         00506ba0     MOV        dword ptr [ESP + local_4],0x0
    //         00506ba8     MOV        dword ptr [ESI],TribeFishingShipUnitAIModule::   = 00506c40
    //         00506bae     MOV        dword ptr [ESI + 0x128],0x8
    //         00506bb8     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00506bbd     ADD        ESP,0x4
    //         00506bc0     MOV        dword ptr [ESI + 0x124],EAX
    //                              taiuaimd.cpp:2158 (4)
    //         00506bc6     TEST       EAX,EAX
    //         00506bc8     JZ         LAB_00506c2b
    //                              taiuaimd.cpp:2159 (6)
    //         00506bca     MOV        dword ptr [EAX],0x3
    //                              taiuaimd.cpp:2160 (13)
    //         00506bd0     MOV        EDX,dword ptr [ESI + 0x124]
    //         00506bd6     MOV        dword ptr [EDX + 0x4],0x16
    //                              taiuaimd.cpp:2161 (13)
    //         00506bdd     MOV        EAX,dword ptr [ESI + 0x124]
    //         00506be3     MOV        dword ptr [EAX + 0x8],0x14
    //                              taiuaimd.cpp:2162 (13)
    //         00506bea     MOV        this,dword ptr [ESI + 0x124]
    //         00506bf0     MOV        dword ptr [ECX + this->field12_0xc],0x2
    //                              taiuaimd.cpp:2163 (13)
    //         00506bf7     MOV        EDX,dword ptr [ESI + 0x124]
    //         00506bfd     MOV        dword ptr [EDX + 0x10],0x15
    //                              taiuaimd.cpp:2164 (13)
    //         00506c04     MOV        EAX,dword ptr [ESI + 0x124]
    //         00506c0a     MOV        dword ptr [EAX + 0x14],0x5
    //                              taiuaimd.cpp:2165 (13)
    //         00506c11     MOV        this,dword ptr [ESI + 0x124]
    //         00506c17     MOV        dword ptr [ECX + this->field24_0x18],0x1f
    //                              taiuaimd.cpp:2166 (13)
    //         00506c1e     MOV        EDX,dword ptr [ESI + 0x124]
    //         00506c24     MOV        dword ptr [EDX + 0x1c],0x21
    //                               LAB_00506c2b                                                 XREF[1]:     00506bc8(j)  
    //                              taiuaimd.cpp:2168 (20)
    //         00506c2b     MOV        this,dword ptr [ESP + local_c]
    //         00506c2f     MOV        EAX,ESI
    //         00506c31     MOV        dword ptr FS:[0x0],this
    //         00506c38     POP        ESI
    //         00506c39     ADD        ESP,0x10
    //         00506c3c     RET        0x8
    //         00506c3f     ??         90h
    //                              * public: virtual void * __thiscall TribeFishingShipUnitAIModule::`scalar deleting destructor'(unsig... *
    //                              void * __thiscall `scalar_deleting_destructor'(TribeFishingShipUnitA
    //              void *            EAX:4          <RETURN>
    //              TribeFishingSh    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00506c48(R)  
    //                               ??_ETribeFishingShipUnitAIModule@@UAEPAXI@Z                  XREF[1]:     005760d0(*)  
    //                               ??_GTribeFishingShipUnitAIModule@@UAEPAXI@Z
    //                               TribeFishingShipUnitAIModule::`scalar_deleting_destructor'
    //         00506c40     PUSH       ESI
    //         00506c41     MOV        ESI,this
    //         00506c43     CALL       TribeFishingShipUnitAIModule::~TribeFishingShi   void ~TribeFishingShipUnitAIModule(TribeFishi
    //         00506c48     TEST       byte ptr [ESP + param_1],0x1
    //         00506c4d     JZ         LAB_00506c58
    //         00506c4f     PUSH       ESI
    //         00506c50     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00506c55     ADD        ESP,0x4
    //                               LAB_00506c58                                                 XREF[1]:     00506c4d(j)  
    //         00506c58     MOV        EAX,ESI
    //         00506c5a     POP        ESI
    //         00506c5b     RET        0x4
    //                              *                                            THUNK FUNCTION                                             *
    //                              thunk void __thiscall ~UnitAIModule(UnitAIModule * this)
    //                                Thunked-Function: UnitAIModule::~UnitAIMo
    //              void              <VOID>         <RETURN>
    //              UnitAIModule *    ECX:4 (auto)   this
    //                               UnitAIModule::~UnitAIModule
    //         00506c5e     NOP
    //         00506c5f     NOP
    return 0;
}

int TribeFishingShipUnitAIModule::importantWhenDead(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall importantWhenDead(TribeFishingShipUnitAIModule * this
    //              int               EAX:4          <RETURN>
    //              TribeFishingSh    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00506c70(R)  
    //                               ?importantWhenDead@TribeFishingShipUnitAIModule@@UAEHH@Z     XREF[1]:     005760f4(*)  
    //                               TribeFishingShipUnitAIModule::importantWhenDead
    //                              taiuaimd.cpp:2173 (14)
    //         00506c70     MOV        EAX,dword ptr [ESP + param_1]
    //         00506c74     CMP        EAX,0x1f
    //         00506c77     JZ         LAB_00506c83
    //         00506c79     CMP        EAX,0x5
    //         00506c7c     JZ         LAB_00506c83
    //                              taiuaimd.cpp:2179 (2)
    //         00506c7e     XOR        EAX,EAX
    //                              taiuaimd.cpp:2180 (3)
    //         00506c80     RET        0x4
    //                               LAB_00506c83                                                 XREF[2]:     00506c77(j), 00506c7c(j)  
    //                              taiuaimd.cpp:2178 (5)
    //         00506c83     MOV        EAX,0x1
    //                              taiuaimd.cpp:2180 (3)
    //         00506c88     RET        0x4
    //         00506c8b     ??         90h
    //         00506c8c     NOP
    //         00506c8d     NOP
    //         00506c8e     NOP
    //         00506c8f     NOP
    return 0;
}

int TribeFishingShipUnitAIModule::convertToLOSResourceType(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall convertToLOSResourceType(TribeFishingShipUnitAIModule
    //              int               EAX:4          <RETURN>
    //              TribeFishingSh    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00506c90(R)  
    //                               ?convertToLOSResourceType@TribeFishingShipUnitAIModule@@UAE  XREF[1]:     00576190(*)  
    //                               TribeFishingShipUnitAIModule::convertToLOSResourceType
    //                              taiuaimd.cpp:2185 (19)
    //         00506c90     MOV        EAX,dword ptr [ESP + param_1]
    //         00506c94     CMP        EAX,0x1f
    //         00506c97     JZ         LAB_00506ca9
    //         00506c99     CMP        EAX,0x5
    //         00506c9c     JZ         LAB_00506ca9
    //         00506c9e     CMP        EAX,0x21
    //         00506ca1     JZ         LAB_00506ca9
    //                              taiuaimd.cpp:2190 (3)
    //         00506ca3     OR         EAX,0xffffffff
    //                              taiuaimd.cpp:2191 (3)
    //         00506ca6     RET        0x4
    //                               LAB_00506ca9                                                 XREF[3]:     00506c97(j), 00506c9c(j), 
    //                                                                                                         00506ca1(j)  
    //                              taiuaimd.cpp:2189 (5)
    //         00506ca9     MOV        EAX,0x2
    //                              taiuaimd.cpp:2191 (3)
    //         00506cae     RET        0x4
    //         00506cb1     ??         90h
    //         00506cb2     NOP
    //         00506cb3     NOP
    //         00506cb4     NOP
    //         00506cb5     NOP
    //         00506cb6     NOP
    //         00506cb7     NOP
    //         00506cb8     NOP
    //         00506cb9     NOP
    //         00506cba     NOP
    //         00506cbb     NOP
    //         00506cbc     NOP
    //         00506cbd     NOP
    //         00506cbe     NOP
    //         00506cbf     NOP
    //                              * protected: virtual int __thiscall TribeFishingShipUnitAIModule::processNotify(struct NotifyEvent *... *
    //                              int __thiscall processNotify(TribeFishingShipUnitAIModule * this, No
    //              int               EAX:4          <RETURN>
    //              TribeFishingSh    ECX:4 (auto)   this
    //              NotifyEvent *     Stack[0x4]:4   param_1                   XREF[1]:     00506cc4(R)  
    //              ulong             Stack[0x8]:4   param_2                   XREF[1]:     00506cd9(R)  
    //                               ?processNotify@TribeFishingShipUnitAIModule@@MAEHPAUNotifyE  XREF[1]:     0057619c(*)  
    //                               TribeFishingShipUnitAIModule::processNotify
    //                              taiuaimd.cpp:2197 (4)
    //         00506cc0     PUSH       EBX
    //         00506cc1     PUSH       EBP
    //         00506cc2     PUSH       ESI
    //         00506cc3     PUSH       EDI
    //                              taiuaimd.cpp:2202 (21)
    //         00506cc4     MOV        EDI,dword ptr [ESP + param_1]
    //         00506cc8     MOV        ESI,this
    //         00506cca     MOV        EAX,dword ptr [EDI + 0x8]
    //         00506ccd     SUB        EAX,0x1f4
    //         00506cd2     JZ         LAB_00506ceb
    //         00506cd4     SUB        EAX,0x1b
    //         00506cd7     JZ         LAB_00506ceb
    //                              taiuaimd.cpp:2275 (11)
    //         00506cd9     MOV        EAX,dword ptr [ESP + param_2]
    //         00506cdd     PUSH       EAX
    //         00506cde     PUSH       EDI
    //         00506cdf     CALL       UnitAIModule::processNotify                      int processNotify(UnitAIModule * this, Notify
    //                              taiuaimd.cpp:2276 (7)
    //         00506ce4     POP        EDI
    //         00506ce5     POP        ESI
    //         00506ce6     POP        EBP
    //         00506ce7     POP        EBX
    //         00506ce8     RET        0x8
    //                               LAB_00506ceb                                                 XREF[2]:     00506cd2(j), 00506cd7(j)  
    //                              taiuaimd.cpp:2212 (7)
    //         00506ceb     MOV        EAX,dword ptr [EDI + 0x10]
    //         00506cee     TEST       EAX,EAX
    //         00506cf0     JG         LAB_00506d29
    //                              taiuaimd.cpp:2217 (31)
    //         00506cf2     MOV        EAX,dword ptr [ESI + 0x4]
    //         00506cf5     MOV        EDI,dword ptr [EDI]
    //         00506cf7     PUSH       0x0
    //         00506cf9     PUSH       0x0
    //         00506cfb     MOV        this,dword ptr [EAX + 0xc]
    //         00506cfe     MOV        EAX,dword ptr [EAX + 0x4]
    //         00506d01     PUSH       EDI
    //         00506d02     PUSH       0x209
    //         00506d07     MOV        EDX,dword ptr [this->field0_0x0]
    //         00506d09     PUSH       EAX
    //         00506d0a     PUSH       EAX
    //         00506d0b     CALL       dword ptr [EDX + 0xe8]
    //                              taiuaimd.cpp:2218 (12)
    //         00506d11     MOV        EAX,dword ptr [ESP + 0x18]
    //         00506d15     MOV        this,ESI
    //         00506d17     PUSH       EAX
    //         00506d18     CALL       UnitAIModule::purgeNotifyQueue                   void purgeNotifyQueue(UnitAIModule * this, ul
    //                              taiuaimd.cpp:2219 (5)
    //         00506d1d     MOV        EAX,0x4
    //                              taiuaimd.cpp:2276 (7)
    //         00506d22     POP        EDI
    //         00506d23     POP        ESI
    //         00506d24     POP        EBP
    //         00506d25     POP        EBX
    //         00506d26     RET        0x8
    //                               LAB_00506d29                                                 XREF[1]:     00506cf0(j)  
    //                              taiuaimd.cpp:2225 (23)
    //         00506d29     MOV        EAX,dword ptr [ESI + 0x64]
    //         00506d2c     TEST       EAX,EAX
    //         00506d2e     JZ         LAB_00506d40
    //         00506d30     MOV        this,dword ptr [ESI + 0x4]
    //         00506d33     MOV        this,dword ptr [ECX + this->field12_0xc]
    //         00506d36     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
    //         00506d3b     CMP        EAX,0x1
    //         00506d3e     JNZ        LAB_00506d5f
    //                               LAB_00506d40                                                 XREF[1]:     00506d2e(j)  
    //                              taiuaimd.cpp:2227 (31)
    //         00506d40     MOV        EAX,dword ptr [ESI + 0x4]
    //         00506d43     MOV        EBX,dword ptr [EDI]
    //         00506d45     PUSH       0x0
    //         00506d47     PUSH       0x0
    //         00506d49     MOV        this,dword ptr [EAX + 0xc]
    //         00506d4c     MOV        EAX,dword ptr [EAX + 0x4]
    //         00506d4f     PUSH       EBX
    //         00506d50     PUSH       0x201
    //         00506d55     MOV        EDX,dword ptr [this->field0_0x0]
    //         00506d57     PUSH       EAX
    //         00506d58     PUSH       EAX
    //         00506d59     CALL       dword ptr [EDX + 0xe8]
    //                               LAB_00506d5f                                                 XREF[1]:     00506d3e(j)  
    //                              taiuaimd.cpp:2235 (57)
    //         00506d5f     MOV        this,dword ptr [ESI + 0x64]
    //         00506d62     XOR        EAX,EAX
    //         00506d64     TEST       this,this
    //         00506d66     JLE        LAB_00506d80
    //         00506d68     MOV        EDX,dword ptr [ESI + 0x6c]
    //                               LAB_00506d6b                                                 XREF[1]:     00506d7e(j)  
    //         00506d6b     CMP        EAX,EDX
    //         00506d6d     JGE        LAB_00506d80
    //         00506d6f     MOV        EBX,dword ptr [ESI + 0x60]
    //         00506d72     MOV        EBP,dword ptr [EDI]
    //         00506d74     MOV        EBX,dword ptr [EBX + EAX*0x4]
    //         00506d77     CMP        EBX,EBP
    //         00506d79     JZ         LAB_00506da0
    //         00506d7b     INC        EAX
    //         00506d7c     CMP        EAX,this
    //         00506d7e     JL         LAB_00506d6b
    //                               LAB_00506d80                                                 XREF[2]:     00506d66(j), 00506d6d(j)  
    //         00506d80     MOV        EAX,dword ptr [ESI + 0x4]
    //         00506d83     MOV        this,dword ptr [EAX + 0xc]
    //         00506d86     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
    //         00506d8b     TEST       EAX,EAX
    //         00506d8d     JNZ        LAB_00506da0
    //         00506d8f     MOV        EAX,dword ptr [EDI]
    //         00506d91     MOV        this,dword ptr [ESI + 0x34]
    //         00506d94     CMP        this,EAX
    //         00506d96     JZ         LAB_00506da0
    //                              taiuaimd.cpp:2236 (8)
    //         00506d98     PUSH       EAX
    //         00506d99     MOV        this,ESI
    //         00506d9b     CALL       UnitAIModule::askForHelp                         void askForHelp(UnitAIModule * this, int para
    //                               LAB_00506da0                                                 XREF[3]:     00506d79(j), 00506d8d(j), 
    //                                                                                                         00506d96(j)  
    //                              taiuaimd.cpp:2238 (130)
    //         00506da0     MOV        this,dword ptr [ESI + 0x64]
    //         00506da3     MOV        EDI,dword ptr [EDI]
    //         00506da5     XOR        EAX,EAX
    //         00506da7     TEST       this,this
    //         00506da9     JLE        LAB_00506dbf
    //         00506dab     MOV        EDX,dword ptr [ESI + 0x6c]
    //                               LAB_00506dae                                                 XREF[1]:     00506dbd(j)  
    //         00506dae     CMP        EAX,EDX
    //         00506db0     JGE        LAB_00506dbf
    //         00506db2     MOV        EBX,dword ptr [ESI + 0x60]
    //         00506db5     CMP        dword ptr [EBX + EAX*0x4],EDI
    //         00506db8     JZ         LAB_00506e22
    //         00506dba     INC        EAX
    //         00506dbb     CMP        EAX,this
    //         00506dbd     JL         LAB_00506dae
    //                               LAB_00506dbf                                                 XREF[2]:     00506da9(j), 00506db0(j)  
    //         00506dbf     MOV        EDX,dword ptr [ESI + 0x6c]
    //         00506dc2     DEC        EDX
    //         00506dc3     CMP        this,EDX
    //         00506dc5     JLE        LAB_00506e12
    //         00506dc7     LEA        EBP,[ECX + this->field1_0x1]
    //         00506dca     LEA        EAX,[EBP*0x4 + 0x0]
    //         00506dd1     PUSH       EAX
    //         00506dd2     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00506dd7     MOV        EBX,EAX
    //         00506dd9     ADD        ESP,0x4
    //         00506ddc     TEST       EBX,EBX
    //         00506dde     JZ         LAB_00506e12
    //         00506de0     MOV        this,dword ptr [ESI + 0x6c]
    //         00506de3     XOR        EAX,EAX
    //         00506de5     TEST       this,this
    //         00506de7     JLE        LAB_00506e00
    //                               LAB_00506de9                                                 XREF[1]:     00506dfe(j)  
    //         00506de9     CMP        EAX,EBP
    //         00506deb     JGE        LAB_00506e00
    //         00506ded     MOV        this,dword ptr [ESI + 0x60]
    //         00506df0     INC        EAX
    //         00506df1     MOV        EDX,dword ptr [this->field0_0x0 + EAX*0x4 + -0
    //         00506df5     MOV        dword ptr [EBX + EAX*0x4 + -0x4],EDX
    //         00506df9     MOV        this,dword ptr [ESI + 0x6c]
    //         00506dfc     CMP        EAX,this
    //         00506dfe     JL         LAB_00506de9
    //                               LAB_00506e00                                                 XREF[2]:     00506de7(j), 00506deb(j)  
    //         00506e00     MOV        EAX,dword ptr [ESI + 0x60]
    //         00506e03     PUSH       EAX
    //         00506e04     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00506e09     ADD        ESP,0x4
    //         00506e0c     MOV        dword ptr [ESI + 0x60],EBX
    //         00506e0f     MOV        dword ptr [ESI + 0x6c],EBP
    //                               LAB_00506e12                                                 XREF[2]:     00506dc5(j), 00506dde(j)  
    //         00506e12     MOV        this,dword ptr [ESI + 0x64]
    //         00506e15     MOV        EDX,dword ptr [ESI + 0x60]
    //         00506e18     MOV        dword ptr [EDX + this->field0_0x0*0x4],EDI
    //         00506e1b     MOV        EAX,dword ptr [ESI + 0x64]
    //         00506e1e     INC        EAX
    //         00506e1f     MOV        dword ptr [ESI + 0x64],EAX
    //                               LAB_00506e22                                                 XREF[1]:     00506db8(j)  
    //                              taiuaimd.cpp:2239 (13)
    //         00506e22     MOV        this,dword ptr [ESI + 0x4]
    //         00506e25     PUSH       0x1
    //         00506e27     MOV        EAX,dword ptr [this->field0_0x0]
    //         00506e29     CALL       dword ptr [EAX + 0xec]
    //                              taiuaimd.cpp:2243 (21)
    //         00506e2f     MOV        this,dword ptr [ESI + 0x4]
    //         00506e32     MOV        this,dword ptr [ECX + this->field12_0xc]
    //         00506e35     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
    //         00506e3a     TEST       EAX,EAX
    //         00506e3c     JNZ        LAB_00506e50
    //         00506e3e     CMP        dword ptr [ESI + 0x28],-0x1
    //         00506e42     JZ         LAB_00506e50
    //                              taiuaimd.cpp:2247 (5)
    //         00506e44     MOV        EAX,0x2
    //                              taiuaimd.cpp:2276 (7)
    //         00506e49     POP        EDI
    //         00506e4a     POP        ESI
    //         00506e4b     POP        EBP
    //         00506e4c     POP        EBX
    //         00506e4d     RET        0x8
    //                               LAB_00506e50                                                 XREF[2]:     00506e3c(j), 00506e42(j)  
    //                              taiuaimd.cpp:2250 (9)
    //         00506e50     CMP        dword ptr [ESI + 0x30],0x262
    //         00506e57     JZ         LAB_00506ec2
    //                              taiuaimd.cpp:2258 (48)
    //         00506e59     MOV        EDX,dword ptr [ESI + 0x2c]
    //         00506e5c     MOV        EAX,dword ptr [ESI + 0x48]
    //         00506e5f     MOV        this,dword ptr [ESI + 0x44]
    //         00506e62     PUSH       EDX
    //         00506e63     MOV        EDX,dword ptr [ESI + 0x40]
    //         00506e66     PUSH       0x0=>DAT_fffffff8
    //         00506e68     PUSH       0x0=>DAT_fffffff4
    //         00506e6a     PUSH       EAX=>DAT_fffffff0
    //         00506e6b     MOV        EAX,dword ptr [ESI + 0x3c]
    //         00506e6e     MOV        EDI,dword ptr [ESI]
    //         00506e70     PUSH       this
    //         00506e71     MOV        this,dword ptr [ESI + 0x34]
    //         00506e74     PUSH       EDX
    //         00506e75     MOV        EDX,dword ptr [ESI + 0x28]
    //         00506e78     PUSH       EAX
    //         00506e79     MOV        EAX,dword ptr [ESI + 0x4]
    //         00506e7c     PUSH       -0x1
    //         00506e7e     PUSH       this
    //         00506e7f     MOV        this,dword ptr [EAX + 0x4]
    //         00506e82     PUSH       EDX
    //         00506e83     PUSH       this
    //         00506e84     MOV        this,ESI
    //         00506e86     CALL       dword ptr [EDI + 0x10]
    //                              taiuaimd.cpp:2260 (50)
    //         00506e89     MOV        this,dword ptr [actionFile]                      = 00000000
    //         00506e8f     TEST       this,this
    //         00506e91     JZ         LAB_00506ebb
    //         00506e93     MOV        EAX,dword ptr [ESI + 0x4]
    //         00506e96     TEST       EAX,EAX
    //         00506e98     JZ         LAB_00506e9f
    //         00506e9a     MOV        EAX,dword ptr [EAX + 0x4]
    //         00506e9d     JMP        LAB_00506ea2
    //                               LAB_00506e9f                                                 XREF[1]:     00506e98(j)  
    //         00506e9f     OR         EAX,0xffffffff
    //                               LAB_00506ea2                                                 XREF[1]:     00506e9d(j)  
    //         00506ea2     PUSH       0x8d4
    //         00506ea7     PUSH       s_C:\msdev\work\age1_x1\taiuaimd.c               = "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp"
    //         00506eac     PUSH       EAX=>DAT_fffffff4
    //         00506ead     PUSH       s_#%d_call_stopObject_%s_%d_                     = "#%d call stopObject %s %d\n"
    //         00506eb2     PUSH       this
    //         00506eb3     CALL       fprintf                                          undefined fprintf()
    //         00506eb8     ADD        ESP,0x14
    //                               LAB_00506ebb                                                 XREF[1]:     00506e91(j)  
    //                              taiuaimd.cpp:2262 (7)
    //         00506ebb     PUSH       0x1
    //         00506ebd     MOV        this,ESI
    //         00506ebf     CALL       dword ptr [EDI + 0x58]
    //                               LAB_00506ec2                                                 XREF[1]:     00506e57(j)  
    //                              taiuaimd.cpp:2270 (12)
    //         00506ec2     MOV        EDX,dword ptr [ESI]
    //         00506ec4     PUSH       0x1
    //         00506ec6     MOV        this,ESI
    //         00506ec8     CALL       dword ptr [EDX + 0xa4]
    //                              taiuaimd.cpp:2276 (12)
    //         00506ece     POP        EDI
    //         00506ecf     POP        ESI
    //         00506ed0     POP        EBP
    //         00506ed1     MOV        EAX,0x3
    //         00506ed6     POP        EBX
    //         00506ed7     RET        0x8
    //         00506eda     ??         90h
    //         00506edb     NOP
    //         00506edc     NOP
    //         00506edd     NOP
    //         00506ede     NOP
    //         00506edf     NOP
    return 0;
}

int TribeFishingShipUnitAIModule::processIdle(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall processIdle(TribeFishingShipUnitAIModule * this, int 
    //              int               EAX:4          <RETURN>
    //              TribeFishingSh    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //              float             Stack[-0x8]:4  xDiff
    //              float             Stack[-0xc]:4  yDiff
    //                               ?processIdle@TribeFishingShipUnitAIModule@@MAEHH@Z           XREF[1]:     005761a4(*)  
    //                               TribeFishingShipUnitAIModule::processIdle
    //                              taiuaimd.cpp:2281 (8)
    //         00506ee0     SUB        ESP,0x8
    //         00506ee3     PUSH       EBX
    //         00506ee4     PUSH       ESI
    //         00506ee5     MOV        ESI,this
    //         00506ee7     PUSH       EDI
    //                              taiuaimd.cpp:2282 (13)
    //         00506ee8     MOV        EAX,dword ptr [ESI + 0x4]
    //         00506eeb     MOV        this,dword ptr [EAX + 0xc]
    //         00506eee     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
    //         00506ef3     TEST       EAX,EAX
    //                              taiuaimd.cpp:2283 (6)
    //         00506ef5     JZ         LAB_00506fcc
    //                              taiuaimd.cpp:2286 (17)
    //         00506efb     MOV        EBX,dword ptr [ESI]
    //         00506efd     PUSH       0x0
    //         00506eff     PUSH       -0x1
    //         00506f01     PUSH       -0x1
    //         00506f03     PUSH       -0x1
    //         00506f05     PUSH       -0x1
    //         00506f07     MOV        this,ESI
    //         00506f09     CALL       dword ptr [EBX + 0x40]
    //                              taiuaimd.cpp:2287 (9)
    //         00506f0c     CMP        EAX,-0x1
    //         00506f0f     JZ         LAB_00506fcc
    //                              taiuaimd.cpp:2288 (17)
    //         00506f15     MOV        this,dword ptr [ESI + 0x4]
    //         00506f18     PUSH       EAX
    //         00506f19     MOV        EDX,dword ptr [ECX + this->field12_0xc]
    //         00506f1c     MOV        this,dword ptr [EDX + 0x3c]
    //         00506f1f     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //         00506f24     MOV        EDI,EAX
    //                              taiuaimd.cpp:2290 (2)
    //         00506f26     TEST       EDI,EDI
    //                              taiuaimd.cpp:2291 (6)
    //         00506f28     JZ         LAB_00506fcc
    //                              taiuaimd.cpp:2296 (11)
    //         00506f2e     MOV        this,dword ptr [ESI + 0x4]
    //         00506f31     MOV        EAX,dword ptr [this->field0_0x0]
    //         00506f33     CALL       dword ptr [EAX + 0xfc]
    //                              taiuaimd.cpp:2302 (133)
    //         00506f39     FLD        float ptr [EDI + 0x3c]
    //         00506f3c     MOV        EAX,dword ptr [ESI + 0x4]
    //         00506f3f     PUSH       0x1
    //         00506f41     FLD        float ptr [EDI + 0x38]
    //         00506f44     FSUB       float ptr [EAX + 0x38]
    //         00506f47     FXCH
    //         00506f49     FSUB       float ptr [EAX + 0x3c]
    //         00506f4c     FXCH       ST2
    //         00506f4e     FMUL       float ptr [DAT_005758d8]
    //         00506f54     FXCH
    //         00506f56     FST        float ptr [ESP + 0x14]
    //         00506f5a     FXCH       ST2
    //         00506f5c     FST        float ptr [ESP + 0x10]
    //         00506f60     FXCH       ST2
    //         00506f62     FMUL       float ptr [ESP + 0x14]
    //         00506f66     FLD        float ptr [ESP + 0x10]
    //         00506f6a     FXCH       ST3
    //         00506f6c     FMUL       float ptr [ESP + 0x10]
    //         00506f70     FLD        float ptr [ESP + 0x14]
    //         00506f74     FXCH       ST3
    //         00506f76     FSTP       float ptr [ESP + 0x10]
    //         00506f7a     MOV        EDX,dword ptr [EAX + 0x40]
    //         00506f7d     MOV        this,ESI
    //         00506f7f     FADDP
    //         00506f81     PUSH       EDX=>DAT_fffffff8
    //         00506f82     PUSH       this=>DAT_fffffff4
    //         00506f83     FSQRT
    //         00506f85     FSTP       float ptr [ESP + 0x1c]
    //         00506f89     FXCH
    //         00506f8b     FDIV       float ptr [ESP + 0x1c]
    //         00506f8f     FXCH
    //         00506f91     FDIV       float ptr [ESP + 0x1c]
    //         00506f95     FXCH
    //         00506f97     FMUL       float ptr [ESP + 0x18]
    //         00506f9b     FXCH
    //         00506f9d     FMUL       float ptr [ESP + 0x18]
    //         00506fa1     FXCH
    //         00506fa3     FCHS
    //         00506fa5     FADD       float ptr [EAX + 0x3c]
    //         00506fa8     FXCH
    //         00506faa     FCHS
    //         00506fac     FADD       float ptr [EAX + 0x38]
    //         00506faf     FXCH
    //         00506fb1     FSTP       float ptr [ESP]=>DAT_fffffff4
    //         00506fb4     PUSH       this=>DAT_fffffff0
    //         00506fb5     FSTP       float ptr [ESP]=>DAT_fffffff0
    //         00506fb8     CALL       dword ptr [EBX + 0x9c]
    //                              taiuaimd.cpp:2303 (5)
    //         00506fbe     MOV        EAX,0x6
    //                              taiuaimd.cpp:2306 (23)
    //         00506fc3     POP        EDI
    //         00506fc4     POP        ESI
    //         00506fc5     POP        EBX
    //         00506fc6     ADD        ESP,0x8
    //         00506fc9     RET        0x4
    //                               LAB_00506fcc                                                 XREF[3]:     00506ef5(j), 00506f0f(j), 
    //                                                                                                         00506f28(j)  
    //         00506fcc     POP        EDI
    //         00506fcd     POP        ESI
    //         00506fce     MOV        EAX,0x5
    //         00506fd3     POP        EBX
    //         00506fd4     ADD        ESP,0x8
    //         00506fd7     RET        0x4
    //         00506fda     ??         90h
    //         00506fdb     NOP
    //         00506fdc     NOP
    //         00506fdd     NOP
    //         00506fde     NOP
    //         00506fdf     NOP
    return 0;
}

TribeSoldierUnitAIModule::TribeSoldierUnitAIModule(RGE_Static_Object* param_1, int param_2) {
    /* TODO: Stub */
    //                              undefined __thiscall TribeSoldierUnitAIModule(TribeSoldierUnitAIModu
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TribeSoldierUn    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00506ffe(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     00506ff6(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00507010(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00507159(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00507002(W)  
    //                               ??0TribeSoldierUnitAIModule@@QAE@PAVRGE_Static_Object@@H@Z   XREF[1]:     initUnitAI:004cbc9e(c)  
    //                               TribeSoldierUnitAIModule::TribeSoldierUnitAIModule
    //                              taiuaimd.cpp:2314 (46)
    //         00506fe0     PUSH       -0x1
    //         00506fe2     PUSH       FUN_00560d08
    //         00506fe7     MOV        EAX,FS:[0x0]
    //         00506fed     PUSH       EAX
    //         00506fee     MOV        dword ptr FS:[0x0],ESP
    //         00506ff5     PUSH       this
    //         00506ff6     MOV        EAX,dword ptr [ESP + param_2]
    //         00506ffa     PUSH       ESI
    //         00506ffb     MOV        ESI,this
    //         00506ffd     PUSH       EAX
    //         00506ffe     MOV        this,dword ptr [ESP + param_1]
    //         00507002     MOV        dword ptr [ESP + local_10],ESI
    //         00507006     PUSH       this
    //         00507007     MOV        this,ESI
    //         00507009     CALL       UnitAIModule::UnitAIModule                       undefined UnitAIModule(UnitAIModule * this, R
    //                              taiuaimd.cpp:2319 (40)
    //         0050700e     PUSH       0x54
    //         00507010     MOV        dword ptr [ESP + local_4],0x0
    //         00507018     MOV        dword ptr [ESI],TribeSoldierUnitAIModule::`vft   = 00507170
    //         0050701e     MOV        dword ptr [ESI + 0x128],0x15
    //         00507028     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0050702d     ADD        ESP,0x4
    //         00507030     MOV        dword ptr [ESI + 0x124],EAX
    //                              taiuaimd.cpp:2320 (8)
    //         00507036     TEST       EAX,EAX
    //         00507038     JZ         LAB_00507148
    //                              taiuaimd.cpp:2321 (6)
    //         0050703e     MOV        dword ptr [EAX],0x0
    //                              taiuaimd.cpp:2322 (13)
    //         00507044     MOV        EDX,dword ptr [ESI + 0x124]
    //         0050704a     MOV        dword ptr [EDX + 0x4],0x3
    //                              taiuaimd.cpp:2323 (13)
    //         00507051     MOV        EAX,dword ptr [ESI + 0x124]
    //         00507057     MOV        dword ptr [EAX + 0x8],0x4
    //                              taiuaimd.cpp:2324 (13)
    //         0050705e     MOV        this,dword ptr [ESI + 0x124]
    //         00507064     MOV        dword ptr [ECX + this->field12_0xc],0x1a
    //                              taiuaimd.cpp:2325 (13)
    //         0050706b     MOV        EDX,dword ptr [ESI + 0x124]
    //         00507071     MOV        dword ptr [EDX + 0x10],0x18
    //                              taiuaimd.cpp:2326 (13)
    //         00507078     MOV        EAX,dword ptr [ESI + 0x124]
    //         0050707e     MOV        dword ptr [EAX + 0x14],0x6
    //                              taiuaimd.cpp:2327 (13)
    //         00507085     MOV        this,dword ptr [ESI + 0x124]
    //         0050708b     MOV        dword ptr [ECX + this->field24_0x18],0x23
    //                              taiuaimd.cpp:2328 (13)
    //         00507092     MOV        EDX,dword ptr [ESI + 0x124]
    //         00507098     MOV        dword ptr [EDX + 0x1c],0x19
    //                              taiuaimd.cpp:2329 (13)
    //         0050709f     MOV        EAX,dword ptr [ESI + 0x124]
    //         005070a5     MOV        dword ptr [EAX + 0x20],0x11
    //                              taiuaimd.cpp:2330 (13)
    //         005070ac     MOV        this,dword ptr [ESI + 0x124]
    //         005070b2     MOV        dword ptr [ECX + this->field36_0x24],0xc
    //                              taiuaimd.cpp:2331 (13)
    //         005070b9     MOV        EDX,dword ptr [ESI + 0x124]
    //         005070bf     MOV        dword ptr [EDX + 0x28],0x17
    //                              taiuaimd.cpp:2332 (13)
    //         005070c6     MOV        EAX,dword ptr [ESI + 0x124]
    //         005070cc     MOV        dword ptr [EAX + 0x2c],0x24
    //                              taiuaimd.cpp:2333 (13)
    //         005070d3     MOV        this,dword ptr [ESI + 0x124]
    //         005070d9     MOV        dword ptr [ECX + this->field48_0x30],0x1c
    //                              taiuaimd.cpp:2334 (13)
    //         005070e0     MOV        EDX,dword ptr [ESI + 0x124]
    //         005070e6     MOV        dword ptr [EDX + 0x34],0x12
    //                              taiuaimd.cpp:2335 (13)
    //         005070ed     MOV        EAX,dword ptr [ESI + 0x124]
    //         005070f3     MOV        dword ptr [EAX + 0x38],0xd
    //                              taiuaimd.cpp:2336 (13)
    //         005070fa     MOV        this,dword ptr [ESI + 0x124]
    //         00507100     MOV        dword ptr [ECX + this->field60_0x3c],0x1b
    //                              taiuaimd.cpp:2337 (13)
    //         00507107     MOV        EDX,dword ptr [ESI + 0x124]
    //         0050710d     MOV        dword ptr [EDX + 0x40],0x16
    //                              taiuaimd.cpp:2338 (13)
    //         00507114     MOV        EAX,dword ptr [ESI + 0x124]
    //         0050711a     MOV        dword ptr [EAX + 0x44],0x14
    //                              taiuaimd.cpp:2339 (13)
    //         00507121     MOV        this,dword ptr [ESI + 0x124]
    //         00507127     MOV        dword ptr [ECX + this->field72_0x48],0x2
    //                              taiuaimd.cpp:2340 (13)
    //         0050712e     MOV        EDX,dword ptr [ESI + 0x124]
    //         00507134     MOV        dword ptr [EDX + 0x4c],0x15
    //                              taiuaimd.cpp:2341 (13)
    //         0050713b     MOV        EAX,dword ptr [ESI + 0x124]
    //         00507141     MOV        dword ptr [EAX + 0x50],0x27
    //                               LAB_00507148                                                 XREF[1]:     00507038(j)  
    //                              taiuaimd.cpp:2345 (17)
    //         00507148     MOV        this,ESI
    //         0050714a     MOV        dword ptr [ESI + 0x100],0x5dc
    //         00507154     CALL       UnitAIModule::setAdjustedIdleTimeout             void setAdjustedIdleTimeout(UnitAIModule * th
    //                              taiuaimd.cpp:2346 (20)
    //         00507159     MOV        this,dword ptr [ESP + local_c]
    //         0050715d     MOV        EAX,ESI
    //         0050715f     MOV        dword ptr FS:[0x0],this
    //         00507166     POP        ESI
    //         00507167     ADD        ESP,0x10
    //         0050716a     RET        0x8
    //         0050716d     ??         90h
    //         0050716e     NOP
    //         0050716f     NOP
    //                              * public: virtual void * __thiscall TribeSoldierUnitAIModule::`scalar deleting destructor'(unsigned ... *
    //                              void * __thiscall `scalar_deleting_destructor'(TribeSoldierUnitAIMod
    //              void *            EAX:4          <RETURN>
    //              TribeSoldierUn    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00507178(R)  
    //                               ??_ETribeSoldierUnitAIModule@@UAEPAXI@Z                      XREF[1]:     005761b0(*)  
    //                               ??_GTribeSoldierUnitAIModule@@UAEPAXI@Z
    //                               TribeSoldierUnitAIModule::`scalar_deleting_destructor'
    //         00507170     PUSH       ESI
    //         00507171     MOV        ESI,this
    //         00507173     CALL       TribeSoldierUnitAIModule::~TribeSoldierUnitAIM   void ~TribeSoldierUnitAIModule(TribeSoldierUn
    //         00507178     TEST       byte ptr [ESP + param_1],0x1
    //         0050717d     JZ         LAB_00507188
    //         0050717f     PUSH       ESI
    //         00507180     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00507185     ADD        ESP,0x4
    //                               LAB_00507188                                                 XREF[1]:     0050717d(j)  
    //         00507188     MOV        EAX,ESI
    //         0050718a     POP        ESI
    //         0050718b     RET        0x4
    //                              *                                            THUNK FUNCTION                                             *
    //                              thunk void __thiscall ~UnitAIModule(UnitAIModule * this)
    //                                Thunked-Function: UnitAIModule::~UnitAIMo
    //              void              <VOID>         <RETURN>
    //              UnitAIModule *    ECX:4 (auto)   this
    //                               UnitAIModule::~UnitAIModule
    //         0050718e     NOP
    //         0050718f     NOP
}

int TribeSoldierUnitAIModule::canAttackUnit(RGE_Static_Object* param_1) {
    /* TODO: Stub */
    //                              int __thiscall canAttackUnit(TribeSoldierUnitAIModule * this, RGE_St
    //              int               EAX:4          <RETURN>
    //              TribeSoldierUn    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     005071a0(R)  
    //                               ?canAttackUnit@TribeSoldierUnitAIModule@@UAEHPAVRGE_Static_  XREF[1]:     00576200(*)  
    //                               TribeSoldierUnitAIModule::canAttackUnit
    //                              taiuaimd.cpp:2351 (8)
    //         005071a0     MOV        EAX,dword ptr [ESP + param_1]
    //         005071a4     TEST       EAX,EAX
    //         005071a6     JNZ        LAB_005071ab
    //                              taiuaimd.cpp:2358 (3)
    //         005071a8     RET        0x4
    //                               LAB_005071ab                                                 XREF[1]:     005071a6(j)  
    //                              taiuaimd.cpp:2355 (15)
    //         005071ab     MOV        EAX,dword ptr [EAX + 0x8]
    //         005071ae     XOR        this,this
    //         005071b0     CMP        word ptr [EAX + 0x14],0x1
    //         005071b5     SETNZ      this
    //         005071b8     MOV        EAX,this
    //                              taiuaimd.cpp:2358 (3)
    //         005071ba     RET        0x4
    //         005071bd     ??         90h
    //         005071be     NOP
    //         005071bf     NOP
    return 0;
}

int TribeSoldierUnitAIModule::canAttackUnitAtNeutrality(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall canAttackUnitAtNeutrality(TribeSoldierUnitAIModule * 
    //              int               EAX:4          <RETURN>
    //              TribeSoldierUn    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     005071c0(R)  
    //                               ?canAttackUnitAtNeutrality@TribeSoldierUnitAIModule@@UAEHH@Z XREF[1]:     00576204(*)  
    //                               TribeSoldierUnitAIModule::canAttackUnitAtNeutrality
    //                              taiuaimd.cpp:2363 (34)
    //         005071c0     MOV        EAX,dword ptr [ESP + param_1]
    //         005071c4     CMP        EAX,0x3
    //         005071c7     JZ         LAB_005071ea
    //         005071c9     CMP        EAX,0x1b
    //         005071cc     JZ         LAB_005071ea
    //         005071ce     CMP        EAX,0x4
    //         005071d1     JZ         LAB_005071ea
    //         005071d3     CMP        EAX,0x15
    //         005071d6     JZ         LAB_005071ea
    //         005071d8     CMP        EAX,0x2
    //         005071db     JZ         LAB_005071ea
    //         005071dd     CMP        EAX,0x14
    //         005071e0     JZ         LAB_005071ea
    //                              taiuaimd.cpp:2373 (5)
    //         005071e2     MOV        EAX,0x1
    //                              taiuaimd.cpp:2374 (3)
    //         005071e7     RET        0x4
    //                               LAB_005071ea                                                 XREF[6]:     005071c7(j), 005071cc(j), 
    //                                                                                                         005071d1(j), 005071d6(j), 
    //                                                                                                         005071db(j), 005071e0(j)  
    //                              taiuaimd.cpp:2372 (2)
    //         005071ea     XOR        EAX,EAX
    //                              taiuaimd.cpp:2374 (3)
    //         005071ec     RET        0x4
    //         005071ef     ??         90h
    //                              * protected: virtual int __thiscall TribeSoldierUnitAIModule::processNotify(struct NotifyEvent *,uns... *
    //                              int __thiscall processNotify(TribeSoldierUnitAIModule * this, Notify
    //              int               EAX:4          <RETURN>
    //              TribeSoldierUn    ECX:4 (auto)   this
    //              NotifyEvent *     Stack[0x4]:4   param_1                   XREF[1]:     005071f4(R)  
    //              ulong             Stack[0x8]:4   param_2                   XREF[1]:     00507623(R)  
    //              float             Stack[-0xc]:4  evasiveMoveDistance
    //                               ?processNotify@TribeSoldierUnitAIModule@@MAEHPAUNotifyEvent  XREF[1]:     0057627c(*)  
    //                               TribeSoldierUnitAIModule::processNotify
    //                              taiuaimd.cpp:2380 (4)
    //         005071f0     SUB        ESP,0x8
    //         005071f3     PUSH       EBX
    //                              taiuaimd.cpp:2391 (32)
    //         005071f4     MOV        EBX,dword ptr [ESP + param_1]
    //         005071f8     PUSH       EBP
    //         005071f9     PUSH       ESI
    //         005071fa     MOV        EAX,dword ptr [EBX + 0x8]
    //         005071fd     PUSH       EDI
    //         005071fe     SUB        EAX,0x200
    //         00507203     MOV        ESI,this
    //         00507205     JZ         LAB_005073a1
    //         0050720b     SUB        EAX,0xf
    //         0050720e     JNZ        LAB_00507623
    //                              taiuaimd.cpp:2394 (19)
    //         00507214     MOV        EAX,dword ptr [ESI + 0x4]
    //         00507217     MOV        this,dword ptr [EAX + 0xc]
    //         0050721a     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
    //         0050721f     TEST       EAX,EAX
    //         00507221     JZ         LAB_00507623
    //                              taiuaimd.cpp:2397 (17)
    //         00507227     MOV        EDX,dword ptr [ESI + 0x4]
    //         0050722a     MOV        this,dword ptr [EBX]
    //         0050722c     PUSH       this
    //         0050722d     MOV        EAX,dword ptr [EDX + 0xc]
    //         00507230     MOV        this,dword ptr [EAX + 0x3c]
    //         00507233     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //                              taiuaimd.cpp:2398 (8)
    //         00507238     TEST       EAX,EAX
    //         0050723a     JZ         LAB_00507623
    //                              taiuaimd.cpp:2401 (23)
    //         00507240     MOV        this,dword ptr [EAX + 0x8]
    //         00507243     MOV        AX,word ptr [ECX + this->field16_0x10]
    //         00507247     CMP        AX,0x23
    //         0050724b     JZ         LAB_00507257
    //         0050724d     CMP        AX,0x24
    //         00507251     JNZ        LAB_00507623
    //                               LAB_00507257                                                 XREF[1]:     0050724b(j)  
    //                              taiuaimd.cpp:2410 (10)
    //         00507257     CMP        dword ptr [ESI + 0x30],-0x1
    //         0050725b     JZ         LAB_00507623
    //                              taiuaimd.cpp:2418 (8)
    //         00507261     MOV        EAX,dword ptr [ESI + 0x28]
    //         00507264     CMP        EAX,-0x1
    //         00507267     JZ         LAB_00507296
    //                              taiuaimd.cpp:2424 (45)
    //         00507269     MOV        this,dword ptr [ESI + 0x2c]
    //         0050726c     MOV        EDX,dword ptr [ESI]
    //         0050726e     PUSH       this
    //         0050726f     MOV        this,dword ptr [ESI + 0x48]
    //         00507272     PUSH       0x0
    //         00507274     PUSH       0x0
    //         00507276     PUSH       this
    //         00507277     MOV        this,dword ptr [ESI + 0x44]
    //         0050727a     PUSH       this
    //         0050727b     MOV        this,dword ptr [ESI + 0x40]
    //         0050727e     PUSH       this
    //         0050727f     MOV        this,dword ptr [ESI + 0x3c]
    //         00507282     PUSH       this
    //         00507283     MOV        this,dword ptr [ESI + 0x34]
    //         00507286     PUSH       -0x1
    //         00507288     PUSH       this
    //         00507289     PUSH       EAX
    //         0050728a     MOV        EAX,dword ptr [ESI + 0x4]
    //         0050728d     MOV        this,dword ptr [EAX + 0x4]
    //         00507290     PUSH       this
    //         00507291     MOV        this,ESI
    //         00507293     CALL       dword ptr [EDX + 0x10]
    //                               LAB_00507296                                                 XREF[1]:     00507267(j)  
    //                              taiuaimd.cpp:2428 (56)
    //         00507296     MOV        EDI,dword ptr [ESI + 0x4]
    //         00507299     PUSH       0x97c
    //         0050729e     PUSH       s_C:\msdev\work\age1_x1\taiuaimd.c               = "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp"
    //         005072a3     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         005072a8     CDQ
    //         005072a9     XOR        EAX,EDX
    //         005072ab     ADD        ESP,0x8
    //         005072ae     SUB        EAX,EDX
    //         005072b0     AND        EAX,0x7
    //         005072b3     XOR        EAX,EDX
    //         005072b5     SUB        EAX,EDX
    //         005072b7     MOV        dword ptr [ESP + 0x1c],EAX
    //         005072bb     FILD       dword ptr [ESP + 0x1c]
    //         005072bf     FLD        float ptr [EDI + 0x38]
    //         005072c2     FSUB       float ptr [DAT_005758dc]
    //         005072c8     FADDP
    //         005072ca     FST        float ptr [ESP + 0x10]
    //                              taiuaimd.cpp:2429 (10)
    //         005072ce     FCOMP      float ptr [EDI + 0x38]
    //         005072d1     FNSTSW     AX
    //         005072d3     TEST       AH,0x40
    //         005072d6     JZ         LAB_005072ff
    //                              taiuaimd.cpp:2430 (10)
    //         005072d8     FLD        float ptr [ESP + 0x10]
    //         005072dc     FCOMP      float ptr [DAT_005758e0]
    //                              taiuaimd.cpp:2431 (17)
    //         005072e2     FLD        float ptr [ESP + 0x10]
    //         005072e6     FNSTSW     AX
    //         005072e8     TEST       AH,0x41
    //         005072eb     JNZ        LAB_005072f5
    //         005072ed     FSUB       float ptr [DAT_005758c0]
    //                              taiuaimd.cpp:2432 (2)
    //         005072f3     JMP        LAB_005072fb
    //                               LAB_005072f5                                                 XREF[1]:     005072eb(j)  
    //                              taiuaimd.cpp:2433 (10)
    //         005072f5     FSUB       float ptr [DAT_005758e4]
    //                               LAB_005072fb                                                 XREF[1]:     005072f3(j)  
    //         005072fb     FSTP       float ptr [ESP + 0x10]
    //                               LAB_005072ff                                                 XREF[1]:     005072d6(j)  
    //                              taiuaimd.cpp:2435 (56)
    //         005072ff     MOV        EDI,dword ptr [ESI + 0x4]
    //         00507302     PUSH       0x983
    //         00507307     PUSH       s_C:\msdev\work\age1_x1\taiuaimd.c               = "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp"
    //         0050730c     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         00507311     CDQ
    //         00507312     XOR        EAX,EDX
    //         00507314     ADD        ESP,0x8
    //         00507317     SUB        EAX,EDX
    //         00507319     AND        EAX,0x7
    //         0050731c     XOR        EAX,EDX
    //         0050731e     SUB        EAX,EDX
    //         00507320     MOV        dword ptr [ESP + 0x1c],EAX
    //         00507324     FILD       dword ptr [ESP + 0x1c]
    //         00507328     FLD        float ptr [EDI + 0x3c]
    //         0050732b     FSUB       float ptr [DAT_005758dc]
    //         00507331     FADDP
    //         00507333     FST        float ptr [ESP + 0x1c]
    //                              taiuaimd.cpp:2436 (10)
    //         00507337     FCOMP      float ptr [EDI + 0x3c]
    //         0050733a     FNSTSW     AX
    //         0050733c     TEST       AH,0x40
    //         0050733f     JZ         LAB_00507368
    //                              taiuaimd.cpp:2437 (10)
    //         00507341     FLD        float ptr [ESP + 0x1c]
    //         00507345     FCOMP      float ptr [DAT_005758e0]
    //                              taiuaimd.cpp:2438 (17)
    //         0050734b     FLD        float ptr [ESP + 0x1c]
    //         0050734f     FNSTSW     AX
    //         00507351     TEST       AH,0x41
    //         00507354     JNZ        LAB_0050735e
    //         00507356     FSUB       float ptr [DAT_005758c0]
    //                              taiuaimd.cpp:2439 (2)
    //         0050735c     JMP        LAB_00507364
    //                               LAB_0050735e                                                 XREF[1]:     00507354(j)  
    //                              taiuaimd.cpp:2440 (10)
    //         0050735e     FSUB       float ptr [DAT_005758e4]
    //                               LAB_00507364                                                 XREF[1]:     0050735c(j)  
    //         00507364     FSTP       float ptr [ESP + 0x1c]
    //                               LAB_00507368                                                 XREF[1]:     0050733f(j)  
    //                              taiuaimd.cpp:2446 (37)
    //         00507368     MOV        EAX,dword ptr [EDI + 0x40]
    //         0050736b     MOV        this,dword ptr [ESP + 0x1c]
    //         0050736f     MOV        EDX,dword ptr [ESI]
    //         00507371     PUSH       0x1
    //         00507373     PUSH       offset DAT_fffffff8
    //         00507375     PUSH       EAX=>DAT_fffffff4
    //         00507376     MOV        EAX,dword ptr [ESP + 0x1c]
    //         0050737a     PUSH       this=>DAT_fffffff0
    //         0050737b     PUSH       EAX
    //         0050737c     MOV        this,ESI
    //         0050737e     CALL       dword ptr [EDX + 0xa0]
    //         00507384     CMP        EAX,0x1
    //         00507387     JNZ        LAB_00507623
    //                              taiuaimd.cpp:2448 (5)
    //         0050738d     MOV        [taskedThisUpdate],EAX
    //                              taiuaimd.cpp:2452 (5)
    //         00507392     MOV        EAX,0x3
    //                              taiuaimd.cpp:2536 (10)
    //         00507397     POP        EDI
    //         00507398     POP        ESI
    //         00507399     POP        EBP
    //         0050739a     POP        EBX
    //         0050739b     ADD        ESP,0x8
    //         0050739e     RET        0x8
    //                               LAB_005073a1                                                 XREF[1]:     00507205(j)  
    //                              taiuaimd.cpp:2461 (64)
    //         005073a1     MOV        this,dword ptr [ESI + 0x4]
    //         005073a4     MOV        this,dword ptr [ECX + this->field12_0xc]
    //         005073a7     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
    //         005073ac     TEST       EAX,EAX
    //         005073ae     JZ         LAB_00507623
    //         005073b4     MOV        this,dword ptr [ESI + 0x4]
    //         005073b7     MOV        EDX,dword ptr [this->field0_0x0]
    //         005073b9     CALL       dword ptr [EDX + 0x10c]
    //         005073bf     FCOMP      float ptr [DAT_005758bc]
    //         005073c5     FNSTSW     AX
    //         005073c7     TEST       AH,0x1
    //         005073ca     JNZ        LAB_00507623
    //         005073d0     MOV        EAX,dword ptr [ESI + 0x4]
    //         005073d3     MOV        this,dword ptr [EAX + 0x8]
    //         005073d6     CMP        word ptr [ECX + this->field20_0x14],0x1a
    //         005073db     JZ         LAB_00507623
    //                              taiuaimd.cpp:2470 (13)
    //         005073e1     CMP        dword ptr [ESI + 0x30],0x258
    //         005073e8     JNZ        LAB_00507614
    //                              taiuaimd.cpp:2474 (17)
    //         005073ee     MOV        EAX,dword ptr [EAX + 0xc]
    //         005073f1     MOV        EDX,dword ptr [ESI + 0x34]
    //         005073f4     PUSH       EDX
    //         005073f5     MOV        this,dword ptr [EAX + 0x3c]
    //         005073f8     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //         005073fd     MOV        EDI,EAX
    //                              taiuaimd.cpp:2476 (8)
    //         005073ff     TEST       EDI,EDI
    //         00507401     JZ         LAB_00507623
    //                              taiuaimd.cpp:2483 (32)
    //         00507407     MOV        this,dword ptr [ESI + 0x4]
    //         0050740a     MOV        EDX,dword ptr [this->field0_0x0]
    //         0050740c     CALL       dword ptr [EDX + 0x10c]
    //         00507412     FSTP       float ptr [ESP + 0x1c]
    //         00507416     MOV        this,dword ptr [ESI + 0x4]
    //         00507419     PUSH       EDI
    //         0050741a     CALL       RGE_Static_Object::distance_to_object            float distance_to_object(RGE_Static_Object * 
    //         0050741f     FSUBR      float ptr [ESP + 0x1c]
    //         00507423     FST        float ptr [ESP + 0x10]
    //                              taiuaimd.cpp:2484 (17)
    //         00507427     FCOMP      float ptr [DAT_005758bc]
    //         0050742d     FNSTSW     AX
    //         0050742f     TEST       AH,0x1
    //         00507432     JNZ        LAB_00507623
    //                              taiuaimd.cpp:2489 (3)
    //         00507438     MOV        EAX,dword ptr [ESI + 0x4]
    //                              taiuaimd.cpp:2496 (70)
    //         0050743b     MOV        this,dword ptr [ESI + 0x2c]
    //         0050743e     FLD        float ptr [EDI + 0x38]
    //         00507441     FSUB       float ptr [EAX + 0x38]
    //         00507444     MOV        EDX,dword ptr [ESI + 0x48]
    //         00507447     PUSH       this
    //         00507448     MOV        this,dword ptr [ESI + 0x44]
    //         0050744b     PUSH       offset DAT_fffffff8
    //         0050744d     PUSH       0x0=>DAT_fffffff4
    //         0050744f     PUSH       EDX=>DAT_fffffff0
    //         00507450     FSTP       float ptr [ESP + 0x30]
    //         00507454     MOV        EDX,dword ptr [ESI + 0x40]
    //         00507457     PUSH       this
    //         00507458     FLD        float ptr [EDI + 0x3c]
    //         0050745b     MOV        this,dword ptr [ESI + 0x3c]
    //         0050745e     MOV        EDI,dword ptr [ESI]
    //         00507460     FSUB       float ptr [EAX + 0x3c]
    //         00507463     MOV        EAX,dword ptr [EAX + 0x4]
    //         00507466     PUSH       EDX
    //         00507467     MOV        EDX,dword ptr [ESI + 0x34]
    //         0050746a     PUSH       this
    //         0050746b     PUSH       -0x1
    //         0050746d     PUSH       EDX
    //         0050746e     FSTP       float ptr [ESP + 0x40]
    //         00507472     PUSH       0x2bc
    //         00507477     PUSH       EAX
    //         00507478     MOV        this,ESI
    //         0050747a     MOV        dword ptr [ESP + 0x40],EDI
    //         0050747e     CALL       dword ptr [EDI + 0x10]
    //                              taiuaimd.cpp:2502 (11)
    //         00507481     MOV        EAX,dword ptr [ESI + 0x64]
    //         00507484     TEST       EAX,EAX
    //         00507486     JLE        LAB_0050759d
    //                              taiuaimd.cpp:2503 (10)
    //         0050748c     XOR        EBP,EBP
    //         0050748e     TEST       EAX,EAX
    //         00507490     JLE        LAB_0050759d
    //                               LAB_00507496                                                 XREF[1]:     00507593(j)  
    //                              taiuaimd.cpp:2504 (100)
    //         00507496     MOV        this,dword ptr [ESI + 0x6c]
    //         00507499     DEC        this
    //         0050749a     CMP        EBP,this
    //         0050749c     JLE        LAB_005074e9
    //         0050749e     LEA        EDX,[EBP*0x4 + 0x4]
    //         005074a5     LEA        EBX,[EBP + 0x1]
    //         005074a8     PUSH       EDX
    //         005074a9     CALL       operator_new                                     void * operator_new(uint param_1)
    //         005074ae     MOV        EDI,EAX
    //         005074b0     ADD        ESP,0x4
    //         005074b3     TEST       EDI,EDI
    //         005074b5     JZ         LAB_005074e9
    //         005074b7     MOV        this,dword ptr [ESI + 0x6c]
    //         005074ba     XOR        EAX,EAX
    //         005074bc     TEST       this,this
    //         005074be     JLE        LAB_005074d7
    //                               LAB_005074c0                                                 XREF[1]:     005074d5(j)  
    //         005074c0     CMP        EAX,EBX
    //         005074c2     JGE        LAB_005074d7
    //         005074c4     MOV        this,dword ptr [ESI + 0x60]
    //         005074c7     INC        EAX
    //         005074c8     MOV        EDX,dword ptr [this->field0_0x0 + EAX*0x4 + -0
    //         005074cc     MOV        dword ptr [EDI + EAX*0x4 + -0x4],EDX
    //         005074d0     MOV        this,dword ptr [ESI + 0x6c]
    //         005074d3     CMP        EAX,this
    //         005074d5     JL         LAB_005074c0
    //                               LAB_005074d7                                                 XREF[2]:     005074be(j), 005074c2(j)  
    //         005074d7     MOV        EAX,dword ptr [ESI + 0x60]
    //         005074da     PUSH       EAX
    //         005074db     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         005074e0     ADD        ESP,0x4
    //         005074e3     MOV        dword ptr [ESI + 0x60],EDI
    //         005074e6     MOV        dword ptr [ESI + 0x6c],EBX
    //                               LAB_005074e9                                                 XREF[2]:     0050749c(j), 005074b5(j)  
    //         005074e9     MOV        this,dword ptr [ESI + 0x60]
    //         005074ec     MOV        EAX,dword ptr [ESI + 0x34]
    //         005074ef     MOV        EDX,dword ptr [this->field0_0x0 + EBP*0x4]
    //         005074f2     CMP        EDX,EAX
    //         005074f4     JZ         LAB_0050758d
    //                              taiuaimd.cpp:2506 (104)
    //         005074fa     MOV        EAX,dword ptr [ESI + 0x6c]
    //         005074fd     DEC        EAX
    //         005074fe     CMP        EBP,EAX
    //         00507500     JLE        LAB_0050754d
    //         00507502     LEA        this,[EBP*0x4 + 0x4]
    //         00507509     LEA        EBX,[EBP + 0x1]
    //         0050750c     PUSH       this
    //         0050750d     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00507512     MOV        EDI,EAX
    //         00507514     ADD        ESP,0x4
    //         00507517     TEST       EDI,EDI
    //         00507519     JZ         LAB_0050754d
    //         0050751b     MOV        this,dword ptr [ESI + 0x6c]
    //         0050751e     XOR        EAX,EAX
    //         00507520     TEST       this,this
    //         00507522     JLE        LAB_0050753b
    //                               LAB_00507524                                                 XREF[1]:     00507539(j)  
    //         00507524     CMP        EAX,EBX
    //         00507526     JGE        LAB_0050753b
    //         00507528     MOV        EDX,dword ptr [ESI + 0x60]
    //         0050752b     INC        EAX
    //         0050752c     MOV        this,dword ptr [EDX + EAX*0x4 + -0x4]
    //         00507530     MOV        dword ptr [EDI + EAX*0x4 + -0x4],this
    //         00507534     MOV        this,dword ptr [ESI + 0x6c]
    //         00507537     CMP        EAX,this
    //         00507539     JL         LAB_00507524
    //                               LAB_0050753b                                                 XREF[2]:     00507522(j), 00507526(j)  
    //         0050753b     MOV        EDX,dword ptr [ESI + 0x60]
    //         0050753e     PUSH       EDX
    //         0050753f     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00507544     ADD        ESP,0x4
    //         00507547     MOV        dword ptr [ESI + 0x60],EDI
    //         0050754a     MOV        dword ptr [ESI + 0x6c],EBX
    //                               LAB_0050754d                                                 XREF[2]:     00507500(j), 00507519(j)  
    //         0050754d     MOV        EAX,dword ptr [ESI + 0x60]
    //         00507550     MOV        EDX,dword ptr [ESI + 0x4]
    //         00507553     MOV        this,dword ptr [EAX + EBP*0x4]
    //         00507556     MOV        EAX,dword ptr [EDX + 0xc]
    //         00507559     PUSH       this
    //         0050755a     MOV        this,dword ptr [EAX + 0x3c]
    //         0050755d     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //                              taiuaimd.cpp:2507 (4)
    //         00507562     TEST       EAX,EAX
    //         00507564     JZ         LAB_0050758d
    //                              taiuaimd.cpp:2510 (51)
    //         00507566     FLD        float ptr [EAX + 0x3c]
    //         00507569     MOV        this,dword ptr [ESI + 0x4]
    //         0050756c     FLD        float ptr [EAX + 0x38]
    //         0050756f     FSUB       float ptr [ECX + this->field56_0x38]
    //         00507572     FXCH
    //         00507574     FSUB       float ptr [ECX + this->field60_0x3c]
    //         00507577     FXCH
    //         00507579     FADD       float ptr [ESP + 0x20]
    //         0050757d     FXCH
    //         0050757f     FADD       float ptr [ESP + 0x1c]
    //         00507583     FXCH
    //         00507585     FSTP       float ptr [ESP + 0x20]
    //         00507589     FSTP       float ptr [ESP + 0x1c]
    //                               LAB_0050758d                                                 XREF[2]:     005074f4(j), 00507564(j)  
    //         0050758d     MOV        EAX,dword ptr [ESI + 0x64]
    //         00507590     INC        EBP
    //         00507591     CMP        EBP,EAX
    //         00507593     JL         LAB_00507496
    //                              taiuaimd.cpp:2503 (4)
    //         00507599     MOV        EDI,dword ptr [ESP + 0x14]
    //                               LAB_0050759d                                                 XREF[2]:     00507486(j), 00507490(j)  
    //                              taiuaimd.cpp:2518 (12)
    //         0050759d     FLD        float ptr [ESP + 0x1c]
    //         005075a1     FLD        float ptr [ESP + 0x20]
    //         005075a5     FMUL       float ptr [ESP + 0x20]
    //                              taiuaimd.cpp:2527 (4)
    //         005075a9     FLD        float ptr [ESP + 0x1c]
    //                              taiuaimd.cpp:2535 (88)
    //         005075ad     FXCH       ST2
    //         005075af     FMUL       float ptr [ESP + 0x1c]
    //         005075b3     FLD        float ptr [ESP + 0x20]
    //         005075b7     FXCH
    //         005075b9     FADDP      ST2,ST0
    //         005075bb     FXCH
    //         005075bd     MOV        EAX,dword ptr [ESI + 0x4]
    //         005075c0     PUSH       0x1
    //         005075c2     PUSH       0x0=>DAT_fffffff8
    //         005075c4     FSQRT
    //         005075c6     MOV        this,dword ptr [EAX + 0x40]
    //         005075c9     PUSH       this=>DAT_fffffff4
    //         005075ca     MOV        this,ESI
    //         005075cc     PUSH       this=>DAT_fffffff0
    //         005075cd     FXCH       ST2
    //         005075cf     FDIV       ST0,ST2
    //         005075d1     FXCH
    //         005075d3     FDIV       ST0,ST2
    //         005075d5     FXCH
    //         005075d7     FMUL       float ptr [ESP + 0x20]
    //         005075db     FXCH
    //         005075dd     FMUL       float ptr [ESP + 0x20]
    //         005075e1     FXCH
    //         005075e3     FCHS
    //         005075e5     FADD       float ptr [EAX + 0x3c]
    //         005075e8     FXCH
    //         005075ea     FCHS
    //         005075ec     FADD       float ptr [EAX + 0x38]
    //         005075ef     FXCH
    //         005075f1     FSTP       float ptr [ESP]=>DAT_fffffff0
    //         005075f4     PUSH       this
    //         005075f5     FSTP       float ptr [ESP]
    //         005075f8     FSTP       ST0
    //         005075fa     CALL       dword ptr [EDI + 0xa0]
    //         00507600     CMP        EAX,0x1
    //         00507603     JNZ        LAB_00507614
    //                              taiuaimd.cpp:2528 (5)
    //         00507605     MOV        EAX,0x3
    //                              taiuaimd.cpp:2536 (10)
    //         0050760a     POP        EDI
    //         0050760b     POP        ESI
    //         0050760c     POP        EBP
    //         0050760d     POP        EBX
    //         0050760e     ADD        ESP,0x8
    //         00507611     RET        0x8
    //                               LAB_00507614                                                 XREF[2]:     005073e8(j), 00507603(j)  
    //                              taiuaimd.cpp:2530 (5)
    //         00507614     MOV        EAX,0x2
    //                              taiuaimd.cpp:2536 (10)
    //         00507619     POP        EDI
    //         0050761a     POP        ESI
    //         0050761b     POP        EBP
    //         0050761c     POP        EBX
    //         0050761d     ADD        ESP,0x8
    //         00507620     RET        0x8
    //                               LAB_00507623                                                 XREF[11]:    0050720e(j), 00507221(j), 
    //                                                                                                         0050723a(j), 00507251(j), 
    //                                                                                                         0050725b(j), 00507387(j), 
    //                                                                                                         005073ae(j), 005073ca(j), 
    //                                                                                                         005073db(j), 00507401(j), 
    //                                                                                                         00507432(j)  
    //                              taiuaimd.cpp:2535 (13)
    //         00507623     MOV        EDX,dword ptr [ESP + param_2]
    //         00507627     MOV        this,ESI
    //         00507629     PUSH       EDX
    //         0050762a     PUSH       EBX=>DAT_fffffff8
    //         0050762b     CALL       UnitAIModule::processNotify                      int processNotify(UnitAIModule * this, Notify
    //                              taiuaimd.cpp:2536 (10)
    //         00507630     POP        EDI
    //         00507631     POP        ESI
    //         00507632     POP        EBP
    //         00507633     POP        EBX
    //         00507634     ADD        ESP,0x8
    //         00507637     RET        0x8
    //         0050763a     ??         90h
    //         0050763b     NOP
    //         0050763c     NOP
    //         0050763d     NOP
    //         0050763e     NOP
    //         0050763f     NOP
    return 0;
}

int TribeSoldierUnitAIModule::processIdle(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall processIdle(TribeSoldierUnitAIModule * this, int para
    //              int               EAX:4          <RETURN>
    //              TribeSoldierUn    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00507641(R)  
    //              float             Stack[-0x8]:4  xDiff
    //                               ?processIdle@TribeSoldierUnitAIModule@@MAEHH@Z               XREF[1]:     00576284(*)  
    //                               TribeSoldierUnitAIModule::processIdle
    //                              taiuaimd.cpp:2541 (1)
    //         00507640     PUSH       this
    //                              taiuaimd.cpp:2542 (14)
    //         00507641     MOV        EAX,dword ptr [ESP + param_1]
    //         00507645     PUSH       EBX
    //         00507646     PUSH       ESI
    //         00507647     CMP        EAX,0x1
    //         0050764a     PUSH       EDI
    //         0050764b     MOV        ESI,this
    //         0050764d     JNZ        LAB_00507668
    //                              taiuaimd.cpp:2544 (13)
    //         0050764f     MOV        EAX,dword ptr [ESI]
    //         00507651     CALL       dword ptr [EAX + 0xdc]
    //         00507657     CMP        EAX,0x8
    //         0050765a     JNZ        LAB_00507668
    //                              taiuaimd.cpp:2545 (5)
    //         0050765c     MOV        EAX,0x6
    //                              taiuaimd.cpp:2629 (7)
    //         00507661     POP        EDI
    //         00507662     POP        ESI
    //         00507663     POP        EBX
    //         00507664     POP        this
    //         00507665     RET        0x4
    //                               LAB_00507668                                                 XREF[2]:     0050764d(j), 0050765a(j)  
    //                              taiuaimd.cpp:2549 (11)
    //         00507668     MOV        this,dword ptr [ESI + 0x4]
    //         0050766b     MOV        this,dword ptr [ECX + this->field12_0xc]
    //         0050766e     CMP        word ptr [ECX + this->field74_0x4a],0x0
    //                              taiuaimd.cpp:2550 (6)
    //         00507673     JZ         LAB_00507868
    //                              taiuaimd.cpp:2554 (21)
    //         00507679     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
    //         0050767e     TEST       EAX,EAX
    //         00507680     JNZ        LAB_00507694
    //         00507682     MOV        EDX,dword ptr [ESI + 0x4]
    //         00507685     MOV        EAX,dword ptr [EDX + 0x8]
    //         00507688     CMP        word ptr [EAX + 0x10],0x12b
    //                              taiuaimd.cpp:2555 (6)
    //         0050768e     JZ         LAB_00507868
    //                               LAB_00507694                                                 XREF[1]:     00507680(j)  
    //                              taiuaimd.cpp:2561 (43)
    //         00507694     CMP        dword ptr [ESI + 0x28],0x2d5
    //         0050769b     JNZ        LAB_005076c5
    //         0050769d     MOV        this,dword ptr [ESI + 0x4]
    //         005076a0     MOV        EDX,dword ptr [ECX + this->field8_0x8]
    //         005076a3     MOV        AX,word ptr [EDX + 0x10]
    //         005076a7     CMP        AX,0x23
    //         005076ab     JZ         LAB_00507868
    //         005076b1     CMP        AX,0x24
    //         005076b5     JZ         LAB_00507868
    //         005076bb     CMP        AX,0xfa
    //                              taiuaimd.cpp:2562 (6)
    //         005076bf     JZ         LAB_00507868
    //                               LAB_005076c5                                                 XREF[1]:     0050769b(j)  
    //                              taiuaimd.cpp:2565 (13)
    //         005076c5     MOV        EBX,dword ptr [ESI]
    //         005076c7     PUSH       0x0
    //         005076c9     PUSH       0x0=>DAT_fffffff8
    //         005076cb     PUSH       offset DAT_fffffff4
    //         005076cd     MOV        this,ESI
    //         005076cf     CALL       dword ptr [EBX + 0x30]
    //                              taiuaimd.cpp:2569 (5)
    //         005076d2     CMP        EAX,-0x1
    //         005076d5     JZ         LAB_005076f0
    //                              taiuaimd.cpp:2570 (13)
    //         005076d7     PUSH       0x1
    //         005076d9     PUSH       EAX=>DAT_fffffff8
    //         005076da     MOV        this,ESI
    //         005076dc     CALL       dword ptr [EBX + 0x5c]
    //         005076df     CMP        EAX,0x1
    //         005076e2     JNZ        LAB_005076f0
    //                              taiuaimd.cpp:2574 (5)
    //         005076e4     MOV        EAX,0x6
    //                              taiuaimd.cpp:2629 (7)
    //         005076e9     POP        EDI
    //         005076ea     POP        ESI
    //         005076eb     POP        EBX
    //         005076ec     POP        this
    //         005076ed     RET        0x4
    //                               LAB_005076f0                                                 XREF[2]:     005076d5(j), 005076e2(j)  
    //                              taiuaimd.cpp:2584 (36)
    //         005076f0     MOV        EAX,dword ptr [ESI + 0x4]
    //         005076f3     MOV        this,dword ptr [EAX + 0xc]
    //         005076f6     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
    //         005076fb     TEST       EAX,EAX
    //         005076fd     JZ         LAB_00507868
    //         00507703     MOV        this,dword ptr [ESI + 0x4]
    //         00507706     CALL       RGE_Static_Object::inGroup                       int inGroup(RGE_Static_Object * this)
    //         0050770b     CMP        EAX,0x1
    //         0050770e     JZ         LAB_00507868
    //                              taiuaimd.cpp:2588 (14)
    //         00507714     MOV        this,dword ptr [ESI + 0x4]
    //         00507717     MOV        EDX,dword ptr [ECX + this->field12_0xc]
    //         0050771a     MOV        this,dword ptr [EDX + 0x3c]
    //         0050771d     CALL       RGE_Game_World::difficultyLevel                  int difficultyLevel(RGE_Game_World * this)
    //                              taiuaimd.cpp:2594 (90)
    //         00507722     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00507728     CALL       RGE_Base_Game::scenarioGame                      int scenarioGame(RGE_Base_Game * this)
    //         0050772d     CMP        EAX,0x1
    //         00507730     JNZ        LAB_0050775a
    //         00507732     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00507738     CALL       RGE_Base_Game::singlePlayerGame                  int singlePlayerGame(RGE_Base_Game * this)
    //         0050773d     CMP        EAX,0x1
    //         00507740     JNZ        LAB_0050775a
    //         00507742     MOV        EAX,dword ptr [ESI + 0x4]
    //         00507745     PUSH       0x8f
    //         0050774a     MOV        this,dword ptr [EAX + 0xc]
    //         0050774d     MOV        EDX,dword ptr [this->field0_0x0]
    //         0050774f     CALL       dword ptr [EDX + 0x3c]
    //         00507752     TEST       EAX,EAX
    //         00507754     JZ         LAB_00507868
    //                               LAB_0050775a                                                 XREF[2]:     00507730(j), 00507740(j)  
    //         0050775a     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00507760     CALL       RGE_Base_Game::singlePlayerGame                  int singlePlayerGame(RGE_Base_Game * this)
    //         00507765     CMP        EAX,0x1
    //         00507768     JNZ        LAB_00507782
    //         0050776a     MOV        EAX,dword ptr [ESI + 0x4]
    //         0050776d     PUSH       0x8f
    //         00507772     MOV        this,dword ptr [EAX + 0xc]
    //         00507775     MOV        EDX,dword ptr [this->field0_0x0]
    //         00507777     CALL       dword ptr [EDX + 0x3c]
    //         0050777a     TEST       EAX,EAX
    //                              taiuaimd.cpp:2595 (6)
    //         0050777c     JZ         LAB_00507868
    //                               LAB_00507782                                                 XREF[1]:     00507768(j)  
    //                              taiuaimd.cpp:2599 (25)
    //         00507782     MOV        EAX,dword ptr [ESI + 0x28]
    //         00507785     CMP        EAX,0x2bd
    //         0050778a     JZ         LAB_00507868
    //         00507790     CMP        EAX,0x2d5
    //         00507795     JZ         LAB_00507868
    //                              taiuaimd.cpp:2603 (15)
    //         0050779b     PUSH       0x0
    //         0050779d     PUSH       offset DAT_fffffff8
    //         0050779f     PUSH       offset DAT_fffffff4
    //         005077a1     PUSH       offset DAT_fffffff0
    //         005077a3     PUSH       -0x1
    //         005077a5     MOV        this,ESI
    //         005077a7     CALL       dword ptr [EBX + 0x40]
    //                              taiuaimd.cpp:2604 (9)
    //         005077aa     CMP        EAX,-0x1
    //         005077ad     JZ         LAB_00507868
    //                              taiuaimd.cpp:2608 (17)
    //         005077b3     PUSH       EAX
    //         005077b4     MOV        EAX,dword ptr [ESI + 0x4]
    //         005077b7     MOV        this,dword ptr [EAX + 0xc]
    //         005077ba     MOV        this,dword ptr [ECX + this->field60_0x3c]
    //         005077bd     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //         005077c2     MOV        EDI,EAX
    //                              taiuaimd.cpp:2610 (2)
    //         005077c4     TEST       EDI,EDI
    //                              taiuaimd.cpp:2611 (6)
    //         005077c6     JZ         LAB_00507868
    //                              taiuaimd.cpp:2616 (11)
    //         005077cc     MOV        this,dword ptr [ESI + 0x4]
    //         005077cf     MOV        EDX,dword ptr [this->field0_0x0]
    //         005077d1     CALL       dword ptr [EDX + 0xfc]
    //                              taiuaimd.cpp:2625 (133)
    //         005077d7     FLD        float ptr [EDI + 0x3c]
    //         005077da     MOV        EAX,dword ptr [ESI + 0x4]
    //         005077dd     PUSH       0x1
    //         005077df     FLD        float ptr [EDI + 0x38]
    //         005077e2     FSUB       float ptr [EAX + 0x38]
    //         005077e5     FXCH
    //         005077e7     FSUB       float ptr [EAX + 0x3c]
    //         005077ea     FXCH       ST2
    //         005077ec     FMUL       float ptr [DAT_005758b0]                         = align(2)
    //         005077f2     FXCH
    //         005077f4     FST        float ptr [ESP + 0x10]
    //         005077f8     FXCH       ST2
    //         005077fa     FST        float ptr [ESP + 0x18]
    //         005077fe     FXCH       ST2
    //         00507800     FMUL       float ptr [ESP + 0x10]
    //         00507804     FLD        float ptr [ESP + 0x18]
    //         00507808     FXCH       ST3
    //         0050780a     FMUL       float ptr [ESP + 0x18]
    //         0050780e     FLD        float ptr [ESP + 0x10]
    //         00507812     FXCH       ST3
    //         00507814     FSTP       float ptr [ESP + 0x10]
    //         00507818     MOV        EDX,dword ptr [EAX + 0x40]
    //         0050781b     MOV        this,ESI
    //         0050781d     FADDP
    //         0050781f     PUSH       EDX=>DAT_fffffff8
    //         00507820     PUSH       this=>DAT_fffffff4
    //         00507821     FSQRT
    //         00507823     FSTP       float ptr [ESP + 0x20]
    //         00507827     FXCH
    //         00507829     FDIV       float ptr [ESP + 0x20]
    //         0050782d     FXCH
    //         0050782f     FDIV       float ptr [ESP + 0x20]
    //         00507833     FXCH
    //         00507835     FMUL       float ptr [ESP + 0x18]
    //         00507839     FXCH
    //         0050783b     FMUL       float ptr [ESP + 0x18]
    //         0050783f     FXCH
    //         00507841     FCHS
    //         00507843     FADD       float ptr [EAX + 0x3c]
    //         00507846     FXCH
    //         00507848     FCHS
    //         0050784a     FADD       float ptr [EAX + 0x38]
    //         0050784d     FXCH
    //         0050784f     FSTP       float ptr [ESP]=>DAT_fffffff4
    //         00507852     PUSH       this=>DAT_fffffff0
    //         00507853     FSTP       float ptr [ESP]=>DAT_fffffff0
    //         00507856     CALL       dword ptr [EBX + 0x9c]
    //                              taiuaimd.cpp:2626 (5)
    //         0050785c     MOV        EAX,0x6
    //                              taiuaimd.cpp:2629 (19)
    //         00507861     POP        EDI
    //         00507862     POP        ESI
    //         00507863     POP        EBX
    //         00507864     POP        this
    //         00507865     RET        0x4
    //                               LAB_00507868                                                 XREF[13]:    00507673(j), 0050768e(j), 
    //                                                                                                         005076ab(j), 005076b5(j), 
    //                                                                                                         005076bf(j), 005076fd(j), 
    //                                                                                                         0050770e(j), 00507754(j), 
    //                                                                                                         0050777c(j), 0050778a(j), 
    //                                                                                                         00507795(j), 005077ad(j), 
    //                                                                                                         005077c6(j)  
    //         00507868     POP        EDI
    //         00507869     POP        ESI
    //         0050786a     MOV        EAX,0x5
    //         0050786f     POP        EBX
    //         00507870     POP        this
    //         00507871     RET        0x4
    //         00507874     ??         90h
    //         00507875     NOP
    //         00507876     NOP
    //         00507877     NOP
    //         00507878     NOP
    //         00507879     NOP
    //         0050787a     NOP
    //         0050787b     NOP
    //         0050787c     NOP
    //         0050787d     NOP
    //         0050787e     NOP
    //         0050787f     NOP
    //                              * public: __thiscall TribeArtifactUnitAIModule::TribeArtifactUnitAIModule(class RGE_Static_Object *,... *
    //                              undefined __thiscall TribeArtifactUnitAIModule(TribeArtifactUnitAIMo
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TribeArtifactU    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     0050789e(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     00507896(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     005078b0(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     005079df(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     005078a2(W)  
    //                               ??0TribeArtifactUnitAIModule@@QAE@PAVRGE_Static_Object@@H@Z  XREF[1]:     initUnitAI:004cb947(c)  
    //                               TribeArtifactUnitAIModule::TribeArtifactUnitAIModule
    //                              taiuaimd.cpp:2637 (46)
    //         00507880     PUSH       -0x1
    //         00507882     PUSH       FUN_00560d28
    //         00507887     MOV        EAX,FS:[0x0]
    //         0050788d     PUSH       EAX
    //         0050788e     MOV        dword ptr FS:[0x0],ESP
    //         00507895     PUSH       this
    //         00507896     MOV        EAX,dword ptr [ESP + param_2]
    //         0050789a     PUSH       ESI
    //         0050789b     MOV        ESI,this
    //         0050789d     PUSH       EAX
    //         0050789e     MOV        this,dword ptr [ESP + param_1]
    //         005078a2     MOV        dword ptr [ESP + local_10],ESI
    //         005078a6     PUSH       this
    //         005078a7     MOV        this,ESI
    //         005078a9     CALL       UnitAIModule::UnitAIModule                       undefined UnitAIModule(UnitAIModule * this, R
    //                              taiuaimd.cpp:2642 (40)
    //         005078ae     PUSH       0x4c
    //         005078b0     MOV        dword ptr [ESP + local_4],0x0
    //         005078b8     MOV        dword ptr [ESI],TribeArtifactUnitAIModule::`vf   = 00507a00
    //         005078be     MOV        dword ptr [ESI + 0x128],0x13
    //         005078c8     CALL       operator_new                                     void * operator_new(uint param_1)
    //         005078cd     ADD        ESP,0x4
    //         005078d0     MOV        dword ptr [ESI + 0x124],EAX
    //                              taiuaimd.cpp:2643 (8)
    //         005078d6     TEST       EAX,EAX
    //         005078d8     JZ         LAB_005079ce
    //                              taiuaimd.cpp:2644 (6)
    //         005078de     MOV        dword ptr [EAX],0x0
    //                              taiuaimd.cpp:2645 (13)
    //         005078e4     MOV        EDX,dword ptr [ESI + 0x124]
    //         005078ea     MOV        dword ptr [EDX + 0x4],0x4
    //                              taiuaimd.cpp:2646 (13)
    //         005078f1     MOV        EAX,dword ptr [ESI + 0x124]
    //         005078f7     MOV        dword ptr [EAX + 0x8],0x1a
    //                              taiuaimd.cpp:2647 (13)
    //         005078fe     MOV        this,dword ptr [ESI + 0x124]
    //         00507904     MOV        dword ptr [ECX + this->field12_0xc],0x18
    //                              taiuaimd.cpp:2648 (13)
    //         0050790b     MOV        EDX,dword ptr [ESI + 0x124]
    //         00507911     MOV        dword ptr [EDX + 0x10],0x6
    //                              taiuaimd.cpp:2649 (13)
    //         00507918     MOV        EAX,dword ptr [ESI + 0x124]
    //         0050791e     MOV        dword ptr [EAX + 0x14],0x23
    //                              taiuaimd.cpp:2650 (13)
    //         00507925     MOV        this,dword ptr [ESI + 0x124]
    //         0050792b     MOV        dword ptr [ECX + this->field24_0x18],0x19
    //                              taiuaimd.cpp:2651 (13)
    //         00507932     MOV        EDX,dword ptr [ESI + 0x124]
    //         00507938     MOV        dword ptr [EDX + 0x1c],0x11
    //                              taiuaimd.cpp:2652 (13)
    //         0050793f     MOV        EAX,dword ptr [ESI + 0x124]
    //         00507945     MOV        dword ptr [EAX + 0x20],0xc
    //                              taiuaimd.cpp:2653 (13)
    //         0050794c     MOV        this,dword ptr [ESI + 0x124]
    //         00507952     MOV        dword ptr [ECX + this->field36_0x24],0x17
    //                              taiuaimd.cpp:2654 (13)
    //         00507959     MOV        EDX,dword ptr [ESI + 0x124]
    //         0050795f     MOV        dword ptr [EDX + 0x28],0x24
    //                              taiuaimd.cpp:2655 (13)
    //         00507966     MOV        EAX,dword ptr [ESI + 0x124]
    //         0050796c     MOV        dword ptr [EAX + 0x2c],0x1c
    //                              taiuaimd.cpp:2656 (13)
    //         00507973     MOV        this,dword ptr [ESI + 0x124]
    //         00507979     MOV        dword ptr [ECX + this->field48_0x30],0x12
    //                              taiuaimd.cpp:2657 (13)
    //         00507980     MOV        EDX,dword ptr [ESI + 0x124]
    //         00507986     MOV        dword ptr [EDX + 0x34],0xd
    //                              taiuaimd.cpp:2658 (13)
    //         0050798d     MOV        EAX,dword ptr [ESI + 0x124]
    //         00507993     MOV        dword ptr [EAX + 0x38],0x16
    //                              taiuaimd.cpp:2659 (13)
    //         0050799a     MOV        this,dword ptr [ESI + 0x124]
    //         005079a0     MOV        dword ptr [ECX + this->field60_0x3c],0x14
    //                              taiuaimd.cpp:2660 (13)
    //         005079a7     MOV        EDX,dword ptr [ESI + 0x124]
    //         005079ad     MOV        dword ptr [EDX + 0x40],0x2
    //                              taiuaimd.cpp:2661 (13)
    //         005079b4     MOV        EAX,dword ptr [ESI + 0x124]
    //         005079ba     MOV        dword ptr [EAX + 0x44],0x15
    //                              taiuaimd.cpp:2662 (13)
    //         005079c1     MOV        this,dword ptr [ESI + 0x124]
    //         005079c7     MOV        dword ptr [ECX + this->field72_0x48],0x27
    //                               LAB_005079ce                                                 XREF[1]:     005078d8(j)  
    //                              taiuaimd.cpp:2667 (17)
    //         005079ce     MOV        this,ESI
    //         005079d0     MOV        dword ptr [ESI + 0x100],0x1388
    //         005079da     CALL       UnitAIModule::setAdjustedIdleTimeout             void setAdjustedIdleTimeout(UnitAIModule * th
    //                              taiuaimd.cpp:2668 (20)
    //         005079df     MOV        this,dword ptr [ESP + local_c]
    //         005079e3     MOV        EAX,ESI
    //         005079e5     MOV        dword ptr FS:[0x0],this
    //         005079ec     POP        ESI
    //         005079ed     ADD        ESP,0x10
    //         005079f0     RET        0x8
    //         005079f3     ??         90h
    //         005079f4     NOP
    //         005079f5     NOP
    //         005079f6     NOP
    //         005079f7     NOP
    //         005079f8     NOP
    //         005079f9     NOP
    //         005079fa     NOP
    //         005079fb     NOP
    //         005079fc     NOP
    //         005079fd     NOP
    //         005079fe     NOP
    //         005079ff     NOP
    //                              * public: virtual void * __thiscall TribeArtifactUnitAIModule::`vector deleting destructor'(unsigned... *
    //                              void * __thiscall `vector_deleting_destructor'(TribeArtifactUnitAIMo
    //              void *            EAX:4          <RETURN>
    //              TribeArtifactU    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00507a08(R)  
    //                               ??_GTribeArtifactUnitAIModule@@UAEPAXI@Z                     XREF[1]:     00576290(*)  
    //                               ??_ETribeArtifactUnitAIModule@@UAEPAXI@Z
    //                               TribeArtifactUnitAIModule::`vector_deleting_destructor'
    //         00507a00     PUSH       ESI
    //         00507a01     MOV        ESI,this
    //         00507a03     CALL       TribeArtifactUnitAIModule::~TribeArtifactUnitA   void ~TribeArtifactUnitAIModule(TribeArtifact
    //         00507a08     TEST       byte ptr [ESP + param_1],0x1
    //         00507a0d     JZ         LAB_00507a18
    //         00507a0f     PUSH       ESI
    //         00507a10     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00507a15     ADD        ESP,0x4
    //                               LAB_00507a18                                                 XREF[1]:     00507a0d(j)  
    //         00507a18     MOV        EAX,ESI
    //         00507a1a     POP        ESI
    //         00507a1b     RET        0x4
    //                              *                                            THUNK FUNCTION                                             *
    //                              thunk void __thiscall ~UnitAIModule(UnitAIModule * this)
    //                                Thunked-Function: UnitAIModule::~UnitAIMo
    //              void              <VOID>         <RETURN>
    //              UnitAIModule *    ECX:4 (auto)   this
    //                               UnitAIModule::~UnitAIModule
    //         00507a1e     NOP
    //         00507a1f     NOP
    return 0;
}

TribeArtifactUnitAIModule::~TribeArtifactUnitAIModule() {
    /* TODO: Stub */
    //                              void __thiscall ~TribeArtifactUnitAIModule(TribeArtifactUnitAIModule
    //              void              <VOID>         <RETURN>
    //              TribeArtifactU    ECX:4 (auto)   this
    //                               ??1TribeArtifactUnitAIModule@@UAE@XZ                         XREF[1]:     `vector_deleting_destructor':00507
    //                               TribeArtifactUnitAIModule::~TribeArtifactUnitAIModule
    //         00507a20     JMP        UnitAIModule::~UnitAIModule
    //         00507a25     ??         90h
    //         00507a26     NOP
    //         00507a27     NOP
    //         00507a28     NOP
    //         00507a29     NOP
    //         00507a2a     NOP
    //         00507a2b     NOP
    //         00507a2c     NOP
    //         00507a2d     NOP
    //         00507a2e     NOP
    //         00507a2f     NOP
    //                              * protected: virtual int __thiscall TribeArtifactUnitAIModule::processNotify(struct NotifyEvent *,un... *
    //                              int __thiscall processNotify(TribeArtifactUnitAIModule * this, Notif
    //              int               EAX:4          <RETURN>
    //              TribeArtifactU    ECX:4 (auto)   this
    //              NotifyEvent *     Stack[0x4]:4   param_1                   XREF[1]:     00507a31(R)  
    //              ulong             Stack[0x8]:4   param_2
    //                               ?processNotify@TribeArtifactUnitAIModule@@MAEHPAUNotifyEven  XREF[1]:     0057635c(*)  
    //                               TribeArtifactUnitAIModule::processNotify
    //                              taiuaimd.cpp:2674 (1)
    //         00507a30     PUSH       EBX
    //                              taiuaimd.cpp:2685 (43)
    //         00507a31     MOV        EBX,dword ptr [ESP + param_1]
    //         00507a35     PUSH       EBP
    //         00507a36     PUSH       ESI
    //         00507a37     MOV        EAX,dword ptr [EBX + 0x8]
    //         00507a3a     PUSH       EDI
    //         00507a3b     ADD        EAX,0xfffffe0c
    //         00507a40     MOV        ESI,this
    //         00507a42     CMP        EAX,0xc7
    //         00507a47     JA         switchD_00507a55::caseD_1f5
    //         00507a4d     XOR        this,this
    //         00507a4f     MOV        this,byte ptr [EAX + switchD_00507a55::switchd
    //                               switchD_00507a55::switchD
    //         00507a55     JMP        dword ptr [this->field0_0x0*0x4 + switchD_0050   = 00507d74
    //                               switchD_00507a55::caseD_1fc                                  XREF[2]:     00507a55(j), 00507d94(*)  
    //                              taiuaimd.cpp:2692 (20)
    //         00507a5c     MOV        EAX,dword ptr [ESI + 0x4]
    //         00507a5f     MOV        EDX,dword ptr [ESI + 0x34]
    //         00507a62     PUSH       EDX
    //         00507a63     MOV        this,dword ptr [EAX + 0xc]
    //         00507a66     MOV        this,dword ptr [ECX + this->field60_0x3c]
    //         00507a69     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //         00507a6e     MOV        EDI,EAX
    //                              taiuaimd.cpp:2693 (4)
    //         00507a70     TEST       EDI,EDI
    //         00507a72     JZ         LAB_00507a9c
    //                              taiuaimd.cpp:2701 (34)
    //         00507a74     FLD        float ptr [EDI + 0x3c]
    //         00507a77     CALL       __ftol                                           undefined __ftol()
    //         00507a7c     FLD        float ptr [EDI + 0x38]
    //         00507a7f     PUSH       EAX
    //         00507a80     CALL       __ftol                                           undefined __ftol()
    //         00507a85     MOV        EDX,dword ptr [ESI + 0x4]
    //         00507a88     PUSH       EAX
    //         00507a89     MOV        EAX,dword ptr [EDX + 0xc]
    //         00507a8c     MOV        this,dword ptr [EAX + 0x38]
    //         00507a8f     CALL       RGE_Visible_Map::get_visible                     uchar get_visible(RGE_Visible_Map * this, int
    //         00507a94     CMP        AL,0xf
    //                              taiuaimd.cpp:2705 (6)
    //         00507a96     JZ         switchD_00507a55::caseD_1f4
    //                               LAB_00507a9c                                                 XREF[1]:     00507a72(j)  
    //                              taiuaimd.cpp:2717 (7)
    //         00507a9c     MOV        this,ESI
    //         00507a9e     CALL       UnitAIModule::removeCurrentTarget                void removeCurrentTarget(UnitAIModule * this)
    //                              taiuaimd.cpp:2719 (29)
    //         00507aa3     MOV        this,dword ptr [actionFile]                      = 00000000
    //         00507aa9     TEST       this,this
    //         00507aab     JZ         LAB_00507d65
    //         00507ab1     MOV        EAX,dword ptr [ESI + 0x4]
    //         00507ab4     TEST       EAX,EAX
    //         00507ab6     JZ         LAB_00507ac5
    //         00507ab8     MOV        EAX,dword ptr [EAX + 0x4]
    //         00507abb     PUSH       0xa9f
    //                              taiuaimd.cpp:2723 (5)
    //         00507ac0     JMP        LAB_00507d51
    //                               LAB_00507ac5                                                 XREF[1]:     00507ab6(j)  
    //                              taiuaimd.cpp:2719 (8)
    //         00507ac5     OR         EAX,0xffffffff
    //         00507ac8     PUSH       0xa9f
    //                              taiuaimd.cpp:2723 (5)
    //         00507acd     JMP        LAB_00507d51
    //                               switchD_00507a55::caseD_1fa                                  XREF[2]:     00507a55(j), 00507d8c(*)  
    //                              taiuaimd.cpp:2731 (18)
    //         00507ad2     MOV        EAX,dword ptr [ESI + 0x28]
    //         00507ad5     CMP        EAX,-0x1
    //         00507ad8     JZ         LAB_00507b23
    //         00507ada     MOV        this,dword ptr [ESI + 0x30]
    //         00507add     ADD        this,0x64
    //         00507ae0     CMP        this,EAX
    //         00507ae2     JNZ        LAB_00507b1a
    //                              taiuaimd.cpp:2732 (7)
    //         00507ae4     MOV        this,ESI
    //         00507ae6     CALL       UnitAIModule::removeCurrentTarget                void removeCurrentTarget(UnitAIModule * this)
    //                              taiuaimd.cpp:2734 (29)
    //         00507aeb     MOV        this,dword ptr [actionFile]                      = 00000000
    //         00507af1     TEST       this,this
    //         00507af3     JZ         LAB_00507d65
    //         00507af9     MOV        EAX,dword ptr [ESI + 0x4]
    //         00507afc     TEST       EAX,EAX
    //         00507afe     JZ         LAB_00507b0d
    //         00507b00     MOV        EAX,dword ptr [EAX + 0x4]
    //         00507b03     PUSH       0xaae
    //                              taiuaimd.cpp:2739 (5)
    //         00507b08     JMP        LAB_00507d51
    //                               LAB_00507b0d                                                 XREF[1]:     00507afe(j)  
    //                              taiuaimd.cpp:2734 (8)
    //         00507b0d     OR         EAX,0xffffffff
    //         00507b10     PUSH       0xaae
    //                              taiuaimd.cpp:2739 (5)
    //         00507b15     JMP        LAB_00507d51
    //                               LAB_00507b1a                                                 XREF[1]:     00507ae2(j)  
    //                              taiuaimd.cpp:2740 (23)
    //         00507b1a     CMP        EAX,-0x1
    //         00507b1d     JNZ        switchD_00507a55::caseD_1f4
    //                               LAB_00507b23                                                 XREF[1]:     00507ad8(j)  
    //         00507b23     MOV        EDX,dword ptr [ESI + 0x30]
    //         00507b26     MOV        EAX,dword ptr [EBX + 0xc]
    //         00507b29     CMP        EDX,EAX
    //         00507b2b     JNZ        switchD_00507a55::caseD_1f4
    //                              taiuaimd.cpp:2741 (7)
    //         00507b31     MOV        this,ESI
    //         00507b33     CALL       UnitAIModule::removeCurrentTarget                void removeCurrentTarget(UnitAIModule * this)
    //                              taiuaimd.cpp:2743 (29)
    //         00507b38     MOV        this,dword ptr [actionFile]                      = 00000000
    //         00507b3e     TEST       this,this
    //         00507b40     JZ         LAB_00507d65
    //         00507b46     MOV        EAX,dword ptr [ESI + 0x4]
    //         00507b49     TEST       EAX,EAX
    //         00507b4b     JZ         LAB_00507b5a
    //         00507b4d     MOV        EAX,dword ptr [EAX + 0x4]
    //         00507b50     PUSH       0xab7
    //                              taiuaimd.cpp:2748 (5)
    //         00507b55     JMP        LAB_00507d51
    //                               LAB_00507b5a                                                 XREF[1]:     00507b4b(j)  
    //                              taiuaimd.cpp:2743 (8)
    //         00507b5a     OR         EAX,0xffffffff
    //         00507b5d     PUSH       0xab7
    //                              taiuaimd.cpp:2748 (5)
    //         00507b62     JMP        LAB_00507d51
    //                               switchD_00507a55::caseD_1f9                                  XREF[2]:     00507a55(j), 00507d88(*)  
    //                              taiuaimd.cpp:2755 (18)
    //         00507b67     MOV        EAX,dword ptr [ESI + 0x28]
    //         00507b6a     CMP        EAX,-0x1
    //         00507b6d     JZ         LAB_00507bb8
    //         00507b6f     MOV        this,dword ptr [ESI + 0x30]
    //         00507b72     ADD        this,0x64
    //         00507b75     CMP        this,EAX
    //         00507b77     JNZ        LAB_00507baf
    //                              taiuaimd.cpp:2756 (7)
    //         00507b79     MOV        this,ESI
    //         00507b7b     CALL       UnitAIModule::removeCurrentTarget                void removeCurrentTarget(UnitAIModule * this)
    //                              taiuaimd.cpp:2758 (29)
    //         00507b80     MOV        this,dword ptr [actionFile]                      = 00000000
    //         00507b86     TEST       this,this
    //         00507b88     JZ         LAB_00507d65
    //         00507b8e     MOV        EAX,dword ptr [ESI + 0x4]
    //         00507b91     TEST       EAX,EAX
    //         00507b93     JZ         LAB_00507ba2
    //         00507b95     MOV        EAX,dword ptr [EAX + 0x4]
    //         00507b98     PUSH       0xac6
    //                              taiuaimd.cpp:2763 (5)
    //         00507b9d     JMP        LAB_00507d51
    //                               LAB_00507ba2                                                 XREF[1]:     00507b93(j)  
    //                              taiuaimd.cpp:2758 (8)
    //         00507ba2     OR         EAX,0xffffffff
    //         00507ba5     PUSH       0xac6
    //                              taiuaimd.cpp:2763 (5)
    //         00507baa     JMP        LAB_00507d51
    //                               LAB_00507baf                                                 XREF[1]:     00507b77(j)  
    //                              taiuaimd.cpp:2764 (23)
    //         00507baf     CMP        EAX,-0x1
    //         00507bb2     JNZ        switchD_00507a55::caseD_1f4
    //                               LAB_00507bb8                                                 XREF[1]:     00507b6d(j)  
    //         00507bb8     MOV        EDX,dword ptr [ESI + 0x30]
    //         00507bbb     MOV        EAX,dword ptr [EBX + 0xc]
    //         00507bbe     CMP        EDX,EAX
    //         00507bc0     JNZ        switchD_00507a55::caseD_1f4
    //                              taiuaimd.cpp:2765 (7)
    //         00507bc6     MOV        this,ESI
    //         00507bc8     CALL       UnitAIModule::removeCurrentTarget                void removeCurrentTarget(UnitAIModule * this)
    //                              taiuaimd.cpp:2767 (29)
    //         00507bcd     MOV        this,dword ptr [actionFile]                      = 00000000
    //         00507bd3     TEST       this,this
    //         00507bd5     JZ         LAB_00507d65
    //         00507bdb     MOV        EAX,dword ptr [ESI + 0x4]
    //         00507bde     TEST       EAX,EAX
    //         00507be0     JZ         LAB_00507bef
    //         00507be2     MOV        EAX,dword ptr [EAX + 0x4]
    //         00507be5     PUSH       0xacf
    //                              taiuaimd.cpp:2772 (5)
    //         00507bea     JMP        LAB_00507d51
    //                               LAB_00507bef                                                 XREF[1]:     00507be0(j)  
    //                              taiuaimd.cpp:2767 (8)
    //         00507bef     OR         EAX,0xffffffff
    //         00507bf2     PUSH       0xacf
    //                              taiuaimd.cpp:2772 (5)
    //         00507bf7     JMP        LAB_00507d51
    //                               switchD_00507a55::caseD_1fb                                  XREF[2]:     00507a55(j), 00507d90(*)  
    //                              taiuaimd.cpp:2779 (18)
    //         00507bfc     MOV        EAX,dword ptr [ESI + 0x28]
    //         00507bff     CMP        EAX,-0x1
    //         00507c02     JZ         LAB_00507c4d
    //         00507c04     MOV        this,dword ptr [ESI + 0x30]
    //         00507c07     ADD        this,0x64
    //         00507c0a     CMP        this,EAX
    //         00507c0c     JNZ        LAB_00507c44
    //                              taiuaimd.cpp:2780 (7)
    //         00507c0e     MOV        this,ESI
    //         00507c10     CALL       UnitAIModule::removeCurrentTarget                void removeCurrentTarget(UnitAIModule * this)
    //                              taiuaimd.cpp:2782 (29)
    //         00507c15     MOV        this,dword ptr [actionFile]                      = 00000000
    //         00507c1b     TEST       this,this
    //         00507c1d     JZ         LAB_00507d65
    //         00507c23     MOV        EAX,dword ptr [ESI + 0x4]
    //         00507c26     TEST       EAX,EAX
    //         00507c28     JZ         LAB_00507c37
    //         00507c2a     MOV        EAX,dword ptr [EAX + 0x4]
    //         00507c2d     PUSH       0xade
    //                              taiuaimd.cpp:2787 (5)
    //         00507c32     JMP        LAB_00507d51
    //                               LAB_00507c37                                                 XREF[1]:     00507c28(j)  
    //                              taiuaimd.cpp:2782 (8)
    //         00507c37     OR         EAX,0xffffffff
    //         00507c3a     PUSH       0xade
    //                              taiuaimd.cpp:2787 (5)
    //         00507c3f     JMP        LAB_00507d51
    //                               LAB_00507c44                                                 XREF[1]:     00507c0c(j)  
    //                              taiuaimd.cpp:2788 (23)
    //         00507c44     CMP        EAX,-0x1
    //         00507c47     JNZ        switchD_00507a55::caseD_1f4
    //                               LAB_00507c4d                                                 XREF[1]:     00507c02(j)  
    //         00507c4d     MOV        EDX,dword ptr [ESI + 0x30]
    //         00507c50     MOV        EAX,dword ptr [EBX + 0xc]
    //         00507c53     CMP        EDX,EAX
    //         00507c55     JNZ        switchD_00507a55::caseD_1f4
    //                              taiuaimd.cpp:2789 (7)
    //         00507c5b     MOV        this,ESI
    //         00507c5d     CALL       UnitAIModule::removeCurrentTarget                void removeCurrentTarget(UnitAIModule * this)
    //                              taiuaimd.cpp:2791 (29)
    //         00507c62     MOV        this,dword ptr [actionFile]                      = 00000000
    //         00507c68     TEST       this,this
    //         00507c6a     JZ         LAB_00507d65
    //         00507c70     MOV        EAX,dword ptr [ESI + 0x4]
    //         00507c73     TEST       EAX,EAX
    //         00507c75     JZ         LAB_00507c84
    //         00507c77     MOV        EAX,dword ptr [EAX + 0x4]
    //         00507c7a     PUSH       0xae7
    //                              taiuaimd.cpp:2796 (5)
    //         00507c7f     JMP        LAB_00507d51
    //                               LAB_00507c84                                                 XREF[1]:     00507c75(j)  
    //                              taiuaimd.cpp:2791 (8)
    //         00507c84     OR         EAX,0xffffffff
    //         00507c87     PUSH       0xae7
    //                              taiuaimd.cpp:2796 (5)
    //         00507c8c     JMP        LAB_00507d51
    //                               switchD_00507a55::caseD_258                                  XREF[2]:     00507a55(j), 00507da8(*)  
    //                              taiuaimd.cpp:2819 (130)
    //         00507c91     MOV        this,dword ptr [ESI + 0x64]
    //         00507c94     MOV        EBP,dword ptr [EBX]
    //         00507c96     XOR        EAX,EAX
    //         00507c98     TEST       this,this
    //         00507c9a     JLE        LAB_00507cb0
    //         00507c9c     MOV        EDX,dword ptr [ESI + 0x6c]
    //                               LAB_00507c9f                                                 XREF[1]:     00507cae(j)  
    //         00507c9f     CMP        EAX,EDX
    //         00507ca1     JGE        LAB_00507cb0
    //         00507ca3     MOV        EDI,dword ptr [ESI + 0x60]
    //         00507ca6     CMP        dword ptr [EDI + EAX*0x4],EBP
    //         00507ca9     JZ         LAB_00507d13
    //         00507cab     INC        EAX
    //         00507cac     CMP        EAX,this
    //         00507cae     JL         LAB_00507c9f
    //                               LAB_00507cb0                                                 XREF[2]:     00507c9a(j), 00507ca1(j)  
    //         00507cb0     MOV        EAX,dword ptr [ESI + 0x6c]
    //         00507cb3     DEC        EAX
    //         00507cb4     CMP        this,EAX
    //         00507cb6     JLE        LAB_00507d03
    //         00507cb8     LEA        EBX,[ECX + this->field1_0x1]
    //         00507cbb     LEA        this,[EBX*0x4 + 0x0]
    //         00507cc2     PUSH       this
    //         00507cc3     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00507cc8     MOV        EDI,EAX
    //         00507cca     ADD        ESP,0x4
    //         00507ccd     TEST       EDI,EDI
    //         00507ccf     JZ         LAB_00507d03
    //         00507cd1     MOV        this,dword ptr [ESI + 0x6c]
    //         00507cd4     XOR        EAX,EAX
    //         00507cd6     TEST       this,this
    //         00507cd8     JLE        LAB_00507cf1
    //                               LAB_00507cda                                                 XREF[1]:     00507cef(j)  
    //         00507cda     CMP        EAX,EBX
    //         00507cdc     JGE        LAB_00507cf1
    //         00507cde     MOV        EDX,dword ptr [ESI + 0x60]
    //         00507ce1     INC        EAX
    //         00507ce2     MOV        this,dword ptr [EDX + EAX*0x4 + -0x4]
    //         00507ce6     MOV        dword ptr [EDI + EAX*0x4 + -0x4],this
    //         00507cea     MOV        this,dword ptr [ESI + 0x6c]
    //         00507ced     CMP        EAX,this
    //         00507cef     JL         LAB_00507cda
    //                               LAB_00507cf1                                                 XREF[2]:     00507cd8(j), 00507cdc(j)  
    //         00507cf1     MOV        EDX,dword ptr [ESI + 0x60]
    //         00507cf4     PUSH       EDX
    //         00507cf5     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00507cfa     ADD        ESP,0x4
    //         00507cfd     MOV        dword ptr [ESI + 0x60],EDI
    //         00507d00     MOV        dword ptr [ESI + 0x6c],EBX
    //                               LAB_00507d03                                                 XREF[2]:     00507cb6(j), 00507ccf(j)  
    //         00507d03     MOV        EAX,dword ptr [ESI + 0x64]
    //         00507d06     MOV        this,dword ptr [ESI + 0x60]
    //         00507d09     MOV        dword ptr [this->field0_0x0 + EAX*0x4],EBP
    //         00507d0c     MOV        EAX,dword ptr [ESI + 0x64]
    //         00507d0f     INC        EAX
    //         00507d10     MOV        dword ptr [ESI + 0x64],EAX
    //                               LAB_00507d13                                                 XREF[1]:     00507ca9(j)  
    //                              taiuaimd.cpp:2820 (13)
    //         00507d13     MOV        this,dword ptr [ESI + 0x4]
    //         00507d16     PUSH       0x1
    //         00507d18     MOV        EDX,dword ptr [this->field0_0x0]
    //         00507d1a     CALL       dword ptr [EDX + 0xec]
    //                              taiuaimd.cpp:2855 (5)
    //         00507d20     MOV        EAX,0x2
    //                              taiuaimd.cpp:2856 (7)
    //         00507d25     POP        EDI
    //         00507d26     POP        ESI
    //         00507d27     POP        EBP
    //         00507d28     POP        EBX
    //         00507d29     RET        0x8
    //                               switchD_00507a55::caseD_201                                  XREF[3]:     00507a47(j), 00507a55(j), 
    //                               switchD_00507a55::caseD_204                                               00507db8(*)  
    //                               switchD_00507a55::caseD_205
    //                               switchD_00507a55::caseD_206
    //                               switchD_00507a55::caseD_207
    //                               switchD_00507a55::caseD_208
    //                               switchD_00507a55::caseD_209
    //                               switchD_00507a55::caseD_20a
    //                               switchD_00507a55::caseD_20c
    //                               switchD_00507a55::caseD_20d
    //                               switchD_00507a55::caseD_20e
    //                               switchD_00507a55::caseD_210
    //                               switchD_00507a55::caseD_211
    //                               switchD_00507a55::caseD_212
    //                               switchD_00507a55::caseD_213
    //                               switchD_00507a55::caseD_214
    //                               switchD_00507a55::caseD_215
    //                               switchD_00507a55::caseD_216
    //                               switchD_00507a55::caseD_217
    //                               switchD_00507a55::caseD_218
    //                               switchD_00507a55::caseD_219
    //                               switchD_00507a55::caseD_21a
    //                               switchD_00507a55::caseD_21b
    //                               switchD_00507a55::caseD_21c
    //                               switchD_00507a55::caseD_21d
    //                               switchD_00507a55::caseD_21e
    //                               switchD_00507a55::caseD_21f
    //                               switchD_00507a55::caseD_220
    //                               switchD_00507a55::caseD_221
    //                               switchD_00507a55::caseD_222
    //                               switchD_00507a55::caseD_223
    //                               switchD_00507a55::caseD_224
    //                               switchD_00507a55::caseD_225
    //                               switchD_00507a55::caseD_226
    //                               switchD_00507a55::caseD_227
    //                               switchD_00507a55::caseD_228
    //                               switchD_00507a55::caseD_229
    //                               switchD_00507a55::caseD_22a
    //                               switchD_00507a55::caseD_22b
    //                               switchD_00507a55::caseD_22c
    //                               switchD_00507a55::caseD_22d
    //                               switchD_00507a55::caseD_22e
    //                               switchD_00507a55::caseD_22f
    //                               switchD_00507a55::caseD_230
    //                               switchD_00507a55::caseD_231
    //                               switchD_00507a55::caseD_232
    //                               switchD_00507a55::caseD_233
    //                               switchD_00507a55::caseD_234
    //                               switchD_00507a55::caseD_235
    //                               switchD_00507a55::caseD_236
    //                               switchD_00507a55::caseD_237
    //                               switchD_00507a55::caseD_238
    //                               switchD_00507a55::caseD_239
    //                               switchD_00507a55::caseD_23a
    //                               switchD_00507a55::caseD_23b
    //                               switchD_00507a55::caseD_23c
    //                               switchD_00507a55::caseD_23d
    //                               switchD_00507a55::caseD_23e
    //                               switchD_00507a55::caseD_23f
    //                               switchD_00507a55::caseD_240
    //                               switchD_00507a55::caseD_241
    //                               switchD_00507a55::caseD_242
    //                               switchD_00507a55::caseD_243
    //                               switchD_00507a55::caseD_244
    //                               switchD_00507a55::caseD_245
    //                               switchD_00507a55::caseD_246
    //                               switchD_00507a55::caseD_247
    //                               switchD_00507a55::caseD_248
    //                               switchD_00507a55::caseD_249
    //                               switchD_00507a55::caseD_24a
    //                               switchD_00507a55::caseD_24b
    //                               switchD_00507a55::caseD_24c
    //                               switchD_00507a55::caseD_24d
    //                               switchD_00507a55::caseD_24e
    //                               switchD_00507a55::caseD_24f
    //                               switchD_00507a55::caseD_250
    //                               switchD_00507a55::caseD_251
    //                               switchD_00507a55::caseD_252
    //                               switchD_00507a55::caseD_253
    //                               switchD_00507a55::caseD_254
    //                               switchD_00507a55::caseD_255
    //                               switchD_00507a55::caseD_256
    //                               switchD_00507a55::caseD_257
    //                               switchD_00507a55::caseD_263
    //                               switchD_00507a55::caseD_264
    //                               switchD_00507a55::caseD_26a
    //                               switchD_00507a55::caseD_26b
    //                               switchD_00507a55::caseD_26c
    //                               switchD_00507a55::caseD_26d
    //                               switchD_00507a55::caseD_26e
    //                               switchD_00507a55::caseD_26f
    //                               switchD_00507a55::caseD_270
    //                               switchD_00507a55::caseD_271
    //                               switchD_00507a55::caseD_272
    //                               switchD_00507a55::caseD_273
    //                               switchD_00507a55::caseD_274
    //                               switchD_00507a55::caseD_275
    //                               switchD_00507a55::caseD_276
    //                               switchD_00507a55::caseD_277
    //                               switchD_00507a55::caseD_278
    //                               switchD_00507a55::caseD_279
    //                               switchD_00507a55::caseD_27a
    //                               switchD_00507a55::caseD_27b
    //                               switchD_00507a55::caseD_27c
    //                               switchD_00507a55::caseD_27d
    //                               switchD_00507a55::caseD_27e
    //                               switchD_00507a55::caseD_27f
    //                               switchD_00507a55::caseD_280
    //                               switchD_00507a55::caseD_281
    //                               switchD_00507a55::caseD_282
    //                               switchD_00507a55::caseD_283
    //                               switchD_00507a55::caseD_284
    //                               switchD_00507a55::caseD_285
    //                               switchD_00507a55::caseD_286
    //                               switchD_00507a55::caseD_287
    //                               switchD_00507a55::caseD_288
    //                               switchD_00507a55::caseD_289
    //                               switchD_00507a55::caseD_28a
    //                               switchD_00507a55::caseD_28b
    //                               switchD_00507a55::caseD_28c
    //                               switchD_00507a55::caseD_28d
    //                               switchD_00507a55::caseD_28e
    //                               switchD_00507a55::caseD_28f
    //                               switchD_00507a55::caseD_290
    //                               switchD_00507a55::caseD_291
    //                               switchD_00507a55::caseD_292
    //                               switchD_00507a55::caseD_293
    //                               switchD_00507a55::caseD_294
    //                               switchD_00507a55::caseD_295
    //                               switchD_00507a55::caseD_296
    //                               switchD_00507a55::caseD_297
    //                               switchD_00507a55::caseD_298
    //                               switchD_00507a55::caseD_299
    //                               switchD_00507a55::caseD_29a
    //                               switchD_00507a55::caseD_29b
    //                               switchD_00507a55::caseD_29c
    //                               switchD_00507a55::caseD_29d
    //                               switchD_00507a55::caseD_29e
    //                               switchD_00507a55::caseD_29f
    //                               switchD_00507a55::caseD_2a0
    //                               switchD_00507a55::caseD_2a1
    //                               switchD_00507a55::caseD_2a2
    //                               switchD_00507a55::caseD_2a3
    //                               switchD_00507a55::caseD_2a4
    //                               switchD_00507a55::caseD_2a5
    //                               switchD_00507a55::caseD_2a6
    //                               switchD_00507a55::caseD_2a7
    //                               switchD_00507a55::caseD_2a8
    //                               switchD_00507a55::caseD_2a9
    //                               switchD_00507a55::caseD_2aa
    //                               switchD_00507a55::caseD_2ab
    //                               switchD_00507a55::caseD_2ac
    //                               switchD_00507a55::caseD_2ad
    //                               switchD_00507a55::caseD_2ae
    //                               switchD_00507a55::caseD_2af
    //                               switchD_00507a55::caseD_2b0
    //                               switchD_00507a55::caseD_2b1
    //                               switchD_00507a55::caseD_2b2
    //                               switchD_00507a55::caseD_2b3
    //                               switchD_00507a55::caseD_2b4
    //                               switchD_00507a55::caseD_2b5
    //                               switchD_00507a55::caseD_2b6
    //                               switchD_00507a55::caseD_2b7
    //                               switchD_00507a55::caseD_2b8
    //                               switchD_00507a55::caseD_2b9
    //                               switchD_00507a55::caseD_2ba
    //                               switchD_00507a55::caseD_1f5
    //                              taiuaimd.cpp:2845 (7)
    //         00507d2c     MOV        this,ESI
    //         00507d2e     CALL       UnitAIModule::removeCurrentTarget                void removeCurrentTarget(UnitAIModule * this)
    //                              taiuaimd.cpp:2847 (50)
    //         00507d33     MOV        this,dword ptr [actionFile]                      = 00000000
    //         00507d39     TEST       this,this
    //         00507d3b     JZ         LAB_00507d65
    //         00507d3d     MOV        EAX,dword ptr [ESI + 0x4]
    //         00507d40     TEST       EAX,EAX
    //         00507d42     JZ         LAB_00507d49
    //         00507d44     MOV        EAX,dword ptr [EAX + 0x4]
    //         00507d47     JMP        LAB_00507d4c
    //                               LAB_00507d49                                                 XREF[1]:     00507d42(j)  
    //         00507d49     OR         EAX,0xffffffff
    //                               LAB_00507d4c                                                 XREF[1]:     00507d47(j)  
    //         00507d4c     PUSH       0xb1f
    //                               LAB_00507d51                                                 XREF[14]:    00507ac0(j), 00507acd(j), 
    //                                                                                                         00507b08(j), 00507b15(j), 
    //                                                                                                         00507b55(j), 00507b62(j), 
    //                                                                                                         00507b9d(j), 00507baa(j), 
    //                                                                                                         00507bea(j), 00507bf7(j), 
    //                                                                                                         00507c32(j), 00507c3f(j), 
    //                                                                                                         00507c7f(j), 00507c8c(j)  
    //         00507d51     PUSH       s_C:\msdev\work\age1_x1\taiuaimd.c               = "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp"
    //         00507d56     PUSH       EAX
    //         00507d57     PUSH       s_#%d_call_stopObject_%s_%d_                     = "#%d call stopObject %s %d\n"
    //         00507d5c     PUSH       this
    //         00507d5d     CALL       fprintf                                          undefined fprintf()
    //         00507d62     ADD        ESP,0x14
    //                               LAB_00507d65                                                 XREF[8]:     00507aab(j), 00507af3(j), 
    //                                                                                                         00507b40(j), 00507b88(j), 
    //                                                                                                         00507bd5(j), 00507c1d(j), 
    //                                                                                                         00507c6a(j), 00507d3b(j)  
    //                              taiuaimd.cpp:2849 (9)
    //         00507d65     MOV        EDI,dword ptr [ESI]
    //         00507d67     PUSH       0x1
    //         00507d69     MOV        this,ESI
    //         00507d6b     CALL       dword ptr [EDI + 0x58]
    //                              taiuaimd.cpp:2850 (6)
    //         00507d6e     PUSH       EBX
    //         00507d6f     MOV        this,ESI
    //         00507d71     CALL       dword ptr [EDI + 0x1c]
    //                               switchD_00507a55::caseD_1f6                                  XREF[17]:    00507a55(j), 00507a96(j), 
    //                               switchD_00507a55::caseD_1f7                                               00507b1d(j), 00507b2b(j), 
    //                               switchD_00507a55::caseD_1f8                                               00507bb2(j), 00507bc0(j), 
    //                               switchD_00507a55::caseD_1fd                                               00507c47(j), 00507c55(j), 
    //                               switchD_00507a55::caseD_1fe                                               00507d80(*), 00507d84(*), 
    //                               switchD_00507a55::caseD_1ff                                               00507d98(*), 00507d9c(*), 
    //                               switchD_00507a55::caseD_200                                               00507da0(*), 00507da4(*), 
    //                               switchD_00507a55::caseD_202                                               00507dac(*), 00507db0(*), 
    //                               switchD_00507a55::caseD_203                                               00507db4(*)  
    //                               switchD_00507a55::caseD_20b
    //                               switchD_00507a55::caseD_20f
    //                               switchD_00507a55::caseD_259
    //                               switchD_00507a55::caseD_25a
    //                               switchD_00507a55::caseD_25b
    //                               switchD_00507a55::caseD_25c
    //                               switchD_00507a55::caseD_25d
    //                               switchD_00507a55::caseD_25e
    //                               switchD_00507a55::caseD_25f
    //                               switchD_00507a55::caseD_260
    //                               switchD_00507a55::caseD_261
    //                               switchD_00507a55::caseD_262
    //                               switchD_00507a55::caseD_265
    //                               switchD_00507a55::caseD_266
    //                               switchD_00507a55::caseD_267
    //                               switchD_00507a55::caseD_268
    //                               switchD_00507a55::caseD_269
    //                               switchD_00507a55::caseD_2bb
    //                               switchD_00507a55::caseD_1f4
    //                              taiuaimd.cpp:2856 (272)
    //         00507d74     POP        EDI
    //         00507d75     POP        ESI
    //         00507d76     POP        EBP
    //         00507d77     MOV        EAX,0x2
    //         00507d7c     POP        EBX
    //         00507d7d     RET        0x8
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_00507a55::switchdataD_00507d80                       XREF[1]:     processNotify:00507a55(*)  
    //         00507d80     addr       switchD_00507a55::caseD_1f4
    //         00507d84     addr       switchD_00507a55::caseD_1f4
    //         00507d88     addr       switchD_00507a55::caseD_1f9
    //         00507d8c     addr       switchD_00507a55::caseD_1fa
    //         00507d90     addr       switchD_00507a55::caseD_1fb
    //         00507d94     addr       switchD_00507a55::caseD_1fc
    //         00507d98     addr       switchD_00507a55::caseD_1f4
    //         00507d9c     addr       switchD_00507a55::caseD_1f4
    //         00507da0     addr       switchD_00507a55::caseD_1f4
    //         00507da4     addr       switchD_00507a55::caseD_1f4
    //         00507da8     addr       switchD_00507a55::caseD_258
    //         00507dac     addr       switchD_00507a55::caseD_1f4
    //         00507db0     addr       switchD_00507a55::caseD_1f4
    //         00507db4     addr       switchD_00507a55::caseD_1f4
    //         00507db8     addr       switchD_00507a55::caseD_1f5
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_00507a55::switchdataD_00507dbc                       XREF[1]:     processNotify:00507a4f(*)  
    //         00507dbc     db         0h
    //         00507dbd     db         Eh
    //         00507dbe     db         1h
    //         00507dbf     db         1h
    //         00507dc0     db         1h
    //         00507dc1     db         2h
    //         00507dc2     db         3h
    //         00507dc3     db         4h
    //         00507dc4     db         5h
    //         00507dc5     db         6h
    //         00507dc6     db         6h
    //         00507dc7     db         6h
    //         00507dc8     db         6h
    //         00507dc9     db         Eh
    //         00507dca     db         7h
    //         00507dcb     db         7h
    //         00507dcc     db         Eh
    //         00507dcd     db         Eh
    //         00507dce     db         Eh
    //         00507dcf     db         Eh
    //         00507dd0     db         Eh
    //         00507dd1     db         Eh
    //         00507dd2     db         Eh
    //         00507dd3     db         8h
    //         00507dd4     db         Eh
    //         00507dd5     db         Eh
    //         00507dd6     db         Eh
    //         00507dd7     db         9h
    //         00507dd8     db         Eh
    //         00507dd9     db         Eh
    //         00507dda     db         Eh
    //         00507ddb     db         Eh
    //         00507ddc     db         Eh
    //         00507ddd     db         Eh
    //         00507dde     db         Eh
    //         00507ddf     db         Eh
    //         00507de0     db         Eh
    //         00507de1     db         Eh
    //         00507de2     db         Eh
    //         00507de3     db         Eh
    //         00507de4     db         Eh
    //         00507de5     db         Eh
    //         00507de6     db         Eh
    //         00507de7     db         Eh
    //         00507de8     db         Eh
    //         00507de9     db         Eh
    //         00507dea     db         Eh
    //         00507deb     db         Eh
    //         00507dec     db         Eh
    //         00507ded     db         Eh
    //         00507dee     db         Eh
    //         00507def     db         Eh
    //         00507df0     db         Eh
    //         00507df1     db         Eh
    //         00507df2     db         Eh
    //         00507df3     db         Eh
    //         00507df4     db         Eh
    //         00507df5     db         Eh
    //         00507df6     db         Eh
    //         00507df7     db         Eh
    //         00507df8     db         Eh
    //         00507df9     db         Eh
    //         00507dfa     db         Eh
    //         00507dfb     db         Eh
    //         00507dfc     db         Eh
    //         00507dfd     db         Eh
    //         00507dfe     db         Eh
    //         00507dff     db         Eh
    //         00507e00     db         Eh
    //         00507e01     db         Eh
    //         00507e02     db         Eh
    //         00507e03     db         Eh
    //         00507e04     db         Eh
    //         00507e05     db         Eh
    //         00507e06     db         Eh
    //         00507e07     db         Eh
    //         00507e08     db         Eh
    //         00507e09     db         Eh
    //         00507e0a     db         Eh
    //         00507e0b     db         Eh
    //         00507e0c     db         Eh
    //         00507e0d     db         Eh
    //         00507e0e     db         Eh
    //         00507e0f     db         Eh
    //         00507e10     db         Eh
    //         00507e11     db         Eh
    //         00507e12     db         Eh
    //         00507e13     db         Eh
    //         00507e14     db         Eh
    //         00507e15     db         Eh
    //         00507e16     db         Eh
    //         00507e17     db         Eh
    //         00507e18     db         Eh
    //         00507e19     db         Eh
    //         00507e1a     db         Eh
    //         00507e1b     db         Eh
    //         00507e1c     db         Eh
    //         00507e1d     db         Eh
    //         00507e1e     db         Eh
    //         00507e1f     db         Eh
    //         00507e20     db         Ah
    //         00507e21     db         Bh
    //         00507e22     db         Bh
    //         00507e23     db         Bh
    //         00507e24     db         Bh
    //         00507e25     db         Bh
    //         00507e26     db         Bh
    //         00507e27     db         Bh
    //         00507e28     db         Bh
    //         00507e29     db         Bh
    //         00507e2a     db         Bh
    //         00507e2b     db         Eh
    //         00507e2c     db         Eh
    //         00507e2d     db         Ch
    //         00507e2e     db         Ch
    //         00507e2f     db         Ch
    //         00507e30     db         Ch
    //         00507e31     db         Ch
    //         00507e32     db         Eh
    //         00507e33     db         Eh
    //         00507e34     db         Eh
    //         00507e35     db         Eh
    //         00507e36     db         Eh
    //         00507e37     db         Eh
    //         00507e38     db         Eh
    //         00507e39     db         Eh
    //         00507e3a     db         Eh
    //         00507e3b     db         Eh
    //         00507e3c     db         Eh
    //         00507e3d     db         Eh
    //         00507e3e     db         Eh
    //         00507e3f     db         Eh
    //         00507e40     db         Eh
    //         00507e41     db         Eh
    //         00507e42     db         Eh
    //         00507e43     db         Eh
    //         00507e44     db         Eh
    //         00507e45     db         Eh
    //         00507e46     db         Eh
    //         00507e47     db         Eh
    //         00507e48     db         Eh
    //         00507e49     db         Eh
    //         00507e4a     db         Eh
    //         00507e4b     db         Eh
    //         00507e4c     db         Eh
    //         00507e4d     db         Eh
    //         00507e4e     db         Eh
    //         00507e4f     db         Eh
    //         00507e50     db         Eh
    //         00507e51     db         Eh
    //         00507e52     db         Eh
    //         00507e53     db         Eh
    //         00507e54     db         Eh
    //         00507e55     db         Eh
    //         00507e56     db         Eh
    //         00507e57     db         Eh
    //         00507e58     db         Eh
    //         00507e59     db         Eh
    //         00507e5a     db         Eh
    //         00507e5b     db         Eh
    //         00507e5c     db         Eh
    //         00507e5d     db         Eh
    //         00507e5e     db         Eh
    //         00507e5f     db         Eh
    //         00507e60     db         Eh
    //         00507e61     db         Eh
    //         00507e62     db         Eh
    //         00507e63     db         Eh
    //         00507e64     db         Eh
    //         00507e65     db         Eh
    //         00507e66     db         Eh
    //         00507e67     db         Eh
    //         00507e68     db         Eh
    //         00507e69     db         Eh
    //         00507e6a     db         Eh
    //         00507e6b     db         Eh
    //         00507e6c     db         Eh
    //         00507e6d     db         Eh
    //         00507e6e     db         Eh
    //         00507e6f     db         Eh
    //         00507e70     db         Eh
    //         00507e71     db         Eh
    //         00507e72     db         Eh
    //         00507e73     db         Eh
    //         00507e74     db         Eh
    //         00507e75     db         Eh
    //         00507e76     db         Eh
    //         00507e77     db         Eh
    //         00507e78     db         Eh
    //         00507e79     db         Eh
    //         00507e7a     db         Eh
    //         00507e7b     db         Eh
    //         00507e7c     db         Eh
    //         00507e7d     db         Eh
    //         00507e7e     db         Eh
    //         00507e7f     db         Eh
    //         00507e80     db         Eh
    //         00507e81     db         Eh
    //         00507e82     db         Eh
    //         00507e83     db         Dh
    //         00507e84     ??         90h
    //         00507e85     ??         90h
    //         00507e86     ??         90h
    //         00507e87     ??         90h
    //         00507e88     ??         90h
    //         00507e89     ??         90h
    //         00507e8a     ??         90h
    //         00507e8b     ??         90h
    //         00507e8c     ??         90h
    //         00507e8d     ??         90h
    //         00507e8e     ??         90h
    //         00507e8f     ??         90h
}

int TribeArtifactUnitAIModule::processIdle(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall processIdle(TribeArtifactUnitAIModule * this, int par
    //              int               EAX:4          <RETURN>
    //              TribeArtifactU    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //                               ?processIdle@TribeArtifactUnitAIModule@@MAEHH@Z              XREF[1]:     00576364(*)  
    //                               TribeArtifactUnitAIModule::processIdle
    //                              taiuaimd.cpp:2861 (3)
    //         00507e90     PUSH       ESI
    //         00507e91     MOV        ESI,this
    //                              taiuaimd.cpp:2868 (15)
    //         00507e93     PUSH       0x0
    //         00507e95     PUSH       -0x1
    //         00507e97     MOV        EAX,dword ptr [ESI]
    //         00507e99     PUSH       -0x1
    //         00507e9b     PUSH       -0x1
    //         00507e9d     PUSH       -0x1
    //         00507e9f     CALL       dword ptr [EAX + 0x40]
    //                              taiuaimd.cpp:2871 (7)
    //         00507ea2     CMP        dword ptr [numberDifferentPlayerObjectsVisible
    //                              taiuaimd.cpp:2872 (2)
    //         00507ea9     JG         LAB_00507edd
    //                              taiuaimd.cpp:2874 (5)
    //         00507eab     CMP        EAX,-0x1
    //         00507eae     JZ         LAB_00507edd
    //                              taiuaimd.cpp:2875 (15)
    //         00507eb0     MOV        this,dword ptr [ESI + 0x4]
    //         00507eb3     PUSH       EAX
    //         00507eb4     MOV        EDX,dword ptr [ECX + this->field12_0xc]
    //         00507eb7     MOV        this,dword ptr [EDX + 0x3c]
    //         00507eba     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
    //                              taiuaimd.cpp:2876 (2)
    //         00507ebf     TEST       EAX,EAX
    //                              taiuaimd.cpp:2877 (2)
    //         00507ec1     JZ         LAB_00507edd
    //                              taiuaimd.cpp:2883 (11)
    //         00507ec3     MOV        this,dword ptr [ESI + 0x4]
    //         00507ec6     MOV        EAX,dword ptr [EAX + 0xc]
    //         00507ec9     CMP        dword ptr [ECX + this->field12_0xc],EAX
    //         00507ecc     JZ         LAB_00507edd
    //                              taiuaimd.cpp:2887 (6)
    //         00507ece     MOV        EDX,dword ptr [this->field0_0x0]
    //         00507ed0     PUSH       EAX
    //         00507ed1     CALL       dword ptr [EDX + 0x44]
    //                              taiuaimd.cpp:2888 (5)
    //         00507ed4     MOV        EAX,0x6
    //                              taiuaimd.cpp:2892 (4)
    //         00507ed9     POP        ESI
    //         00507eda     RET        0x4
    //                               LAB_00507edd                                                 XREF[4]:     00507ea9(j), 00507eae(j), 
    //                                                                                                         00507ec1(j), 00507ecc(j)  
    //                              taiuaimd.cpp:2891 (5)
    //         00507edd     MOV        EAX,0x5
    //                              taiuaimd.cpp:2892 (4)
    //         00507ee2     POP        ESI
    //         00507ee3     RET        0x4
    //         00507ee6     ??         90h
    //         00507ee7     NOP
    //         00507ee8     NOP
    //         00507ee9     NOP
    //         00507eea     NOP
    //         00507eeb     NOP
    //         00507eec     NOP
    //         00507eed     NOP
    //         00507eee     NOP
    //         00507eef     NOP
    return 0;
}

int TribeArtifactUnitAIModule::processMisc() {
    /* TODO: Stub */
    //                              int __thiscall processMisc(TribeArtifactUnitAIModule * this)
    //              int               EAX:4          <RETURN>
    //              TribeArtifactU    ECX:4 (auto)   this
    //                               ?processMisc@TribeArtifactUnitAIModule@@MAEHXZ               XREF[1]:     00576368(*)  
    //                               TribeArtifactUnitAIModule::processMisc
    //                              taiuaimd.cpp:2897 (4)
    //         00507ef0     PUSH       ESI
    //         00507ef1     MOV        ESI,this
    //         00507ef3     PUSH       EDI
    //                              taiuaimd.cpp:2909 (15)
    //         00507ef4     PUSH       0x1
    //         00507ef6     MOV        EDI,dword ptr [ESI]
    //         00507ef8     CALL       dword ptr [EDI + 0xd4]
    //         00507efe     CMP        EAX,0x6
    //         00507f01     JNZ        LAB_00507f55
    //                              taiuaimd.cpp:2910 (7)
    //         00507f03     MOV        this,ESI
    //         00507f05     CALL       UnitAIModule::removeCurrentTarget                void removeCurrentTarget(UnitAIModule * this)
    //                              taiuaimd.cpp:2912 (50)
    //         00507f0a     MOV        this,dword ptr [actionFile]                      = 00000000
    //         00507f10     TEST       this,this
    //         00507f12     JZ         LAB_00507f3c
    //         00507f14     MOV        EAX,dword ptr [ESI + 0x4]
    //         00507f17     TEST       EAX,EAX
    //         00507f19     JZ         LAB_00507f20
    //         00507f1b     MOV        EAX,dword ptr [EAX + 0x4]
    //         00507f1e     JMP        LAB_00507f23
    //                               LAB_00507f20                                                 XREF[1]:     00507f19(j)  
    //         00507f20     OR         EAX,0xffffffff
    //                               LAB_00507f23                                                 XREF[1]:     00507f1e(j)  
    //         00507f23     PUSH       0xb60
    //         00507f28     PUSH       s_C:\msdev\work\age1_x1\taiuaimd.c               = "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp"
    //         00507f2d     PUSH       EAX=>DAT_fffffff4
    //         00507f2e     PUSH       s_#%d_call_stopObject_%s_%d_                     = "#%d call stopObject %s %d\n"
    //         00507f33     PUSH       this
    //         00507f34     CALL       fprintf                                          undefined fprintf()
    //         00507f39     ADD        ESP,0x14
    //                               LAB_00507f3c                                                 XREF[1]:     00507f12(j)  
    //                              taiuaimd.cpp:2914 (7)
    //         00507f3c     PUSH       0x1
    //         00507f3e     MOV        this,ESI
    //         00507f40     CALL       dword ptr [EDI + 0x58]
    //                              taiuaimd.cpp:2915 (10)
    //         00507f43     MOV        dword ptr [ESI + 0xf8],0x0
    //                              taiuaimd.cpp:2916 (5)
    //         00507f4d     MOV        EAX,0xa
    //                              taiuaimd.cpp:2919 (11)
    //         00507f52     POP        EDI
    //         00507f53     POP        ESI
    //         00507f54     RET
    //                               LAB_00507f55                                                 XREF[1]:     00507f01(j)  
    //         00507f55     POP        EDI
    //         00507f56     MOV        EAX,0x9
    //         00507f5b     POP        ESI
    //         00507f5c     RET
    //         00507f5d     ??         90h
    //         00507f5e     NOP
    //         00507f5f     NOP
    return 0;
}

TribeTowerUnitAIModule::TribeTowerUnitAIModule(RGE_Static_Object* param_1, int param_2) {
    /* TODO: Stub */
    //                              undefined __thiscall TribeTowerUnitAIModule(TribeTowerUnitAIModule *
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TribeTowerUnit    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00507f7e(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     00507f76(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00507f90(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     005080c8(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00507f82(W)  
    //                               ??0TribeTowerUnitAIModule@@QAE@PAVRGE_Static_Object@@H@Z     XREF[1]:     initUnitAI:004cbc64(c)  
    //                               TribeTowerUnitAIModule::TribeTowerUnitAIModule
    //                              taiuaimd.cpp:2927 (46)
    //         00507f60     PUSH       -0x1
    //         00507f62     PUSH       FUN_00560d48
    //         00507f67     MOV        EAX,FS:[0x0]
    //         00507f6d     PUSH       EAX
    //         00507f6e     MOV        dword ptr FS:[0x0],ESP
    //         00507f75     PUSH       this
    //         00507f76     MOV        EAX,dword ptr [ESP + param_2]
    //         00507f7a     PUSH       ESI
    //         00507f7b     MOV        ESI,this
    //         00507f7d     PUSH       EAX
    //         00507f7e     MOV        this,dword ptr [ESP + param_1]
    //         00507f82     MOV        dword ptr [ESP + local_10],ESI
    //         00507f86     PUSH       this
    //         00507f87     MOV        this,ESI
    //         00507f89     CALL       UnitAIModule::UnitAIModule                       undefined UnitAIModule(UnitAIModule * this, R
    //                              taiuaimd.cpp:2932 (40)
    //         00507f8e     PUSH       0x54
    //         00507f90     MOV        dword ptr [ESP + local_4],0x0
    //         00507f98     MOV        dword ptr [ESI],TribeTowerUnitAIModule::`vftab   = 005080e0
    //         00507f9e     MOV        dword ptr [ESI + 0x128],0x15
    //         00507fa8     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00507fad     ADD        ESP,0x4
    //         00507fb0     MOV        dword ptr [ESI + 0x124],EAX
    //                              taiuaimd.cpp:2933 (8)
    //         00507fb6     TEST       EAX,EAX
    //         00507fb8     JZ         LAB_005080c8
    //                              taiuaimd.cpp:2934 (6)
    //         00507fbe     MOV        dword ptr [EAX],0x0
    //                              taiuaimd.cpp:2935 (13)
    //         00507fc4     MOV        EDX,dword ptr [ESI + 0x124]
    //         00507fca     MOV        dword ptr [EDX + 0x4],0x3
    //                              taiuaimd.cpp:2936 (13)
    //         00507fd1     MOV        EAX,dword ptr [ESI + 0x124]
    //         00507fd7     MOV        dword ptr [EAX + 0x8],0x4
    //                              taiuaimd.cpp:2937 (13)
    //         00507fde     MOV        this,dword ptr [ESI + 0x124]
    //         00507fe4     MOV        dword ptr [ECX + this->field12_0xc],0x1a
    //                              taiuaimd.cpp:2938 (13)
    //         00507feb     MOV        EDX,dword ptr [ESI + 0x124]
    //         00507ff1     MOV        dword ptr [EDX + 0x10],0x18
    //                              taiuaimd.cpp:2939 (13)
    //         00507ff8     MOV        EAX,dword ptr [ESI + 0x124]
    //         00507ffe     MOV        dword ptr [EAX + 0x14],0x6
    //                              taiuaimd.cpp:2940 (13)
    //         00508005     MOV        this,dword ptr [ESI + 0x124]
    //         0050800b     MOV        dword ptr [ECX + this->field24_0x18],0x23
    //                              taiuaimd.cpp:2941 (13)
    //         00508012     MOV        EDX,dword ptr [ESI + 0x124]
    //         00508018     MOV        dword ptr [EDX + 0x1c],0x19
    //                              taiuaimd.cpp:2942 (13)
    //         0050801f     MOV        EAX,dword ptr [ESI + 0x124]
    //         00508025     MOV        dword ptr [EAX + 0x20],0x11
    //                              taiuaimd.cpp:2943 (13)
    //         0050802c     MOV        this,dword ptr [ESI + 0x124]
    //         00508032     MOV        dword ptr [ECX + this->field36_0x24],0xc
    //                              taiuaimd.cpp:2944 (13)
    //         00508039     MOV        EDX,dword ptr [ESI + 0x124]
    //         0050803f     MOV        dword ptr [EDX + 0x28],0x17
    //                              taiuaimd.cpp:2945 (13)
    //         00508046     MOV        EAX,dword ptr [ESI + 0x124]
    //         0050804c     MOV        dword ptr [EAX + 0x2c],0x24
    //                              taiuaimd.cpp:2946 (13)
    //         00508053     MOV        this,dword ptr [ESI + 0x124]
    //         00508059     MOV        dword ptr [ECX + this->field48_0x30],0x1c
    //                              taiuaimd.cpp:2947 (13)
    //         00508060     MOV        EDX,dword ptr [ESI + 0x124]
    //         00508066     MOV        dword ptr [EDX + 0x34],0x12
    //                              taiuaimd.cpp:2948 (13)
    //         0050806d     MOV        EAX,dword ptr [ESI + 0x124]
    //         00508073     MOV        dword ptr [EAX + 0x38],0xd
    //                              taiuaimd.cpp:2949 (13)
    //         0050807a     MOV        this,dword ptr [ESI + 0x124]
    //         00508080     MOV        dword ptr [ECX + this->field60_0x3c],0x1b
    //                              taiuaimd.cpp:2950 (13)
    //         00508087     MOV        EDX,dword ptr [ESI + 0x124]
    //         0050808d     MOV        dword ptr [EDX + 0x40],0x16
    //                              taiuaimd.cpp:2951 (13)
    //         00508094     MOV        EAX,dword ptr [ESI + 0x124]
    //         0050809a     MOV        dword ptr [EAX + 0x44],0x14
    //                              taiuaimd.cpp:2952 (13)
    //         005080a1     MOV        this,dword ptr [ESI + 0x124]
    //         005080a7     MOV        dword ptr [ECX + this->field72_0x48],0x2
    //                              taiuaimd.cpp:2953 (13)
    //         005080ae     MOV        EDX,dword ptr [ESI + 0x124]
    //         005080b4     MOV        dword ptr [EDX + 0x4c],0x15
    //                              taiuaimd.cpp:2954 (13)
    //         005080bb     MOV        EAX,dword ptr [ESI + 0x124]
    //         005080c1     MOV        dword ptr [EAX + 0x50],0x27
    //                               LAB_005080c8                                                 XREF[1]:     00507fb8(j)  
    //                              taiuaimd.cpp:2956 (20)
    //         005080c8     MOV        this,dword ptr [ESP + local_c]
    //         005080cc     MOV        EAX,ESI
    //         005080ce     MOV        dword ptr FS:[0x0],this
    //         005080d5     POP        ESI
    //         005080d6     ADD        ESP,0x10
    //         005080d9     RET        0x8
    //         005080dc     ??         90h
    //         005080dd     NOP
    //         005080de     NOP
    //         005080df     NOP
}

int TribeTowerUnitAIModule::canAttackUnit(RGE_Static_Object* param_1) {
    /* TODO: Stub */
    //                              int __thiscall canAttackUnit(TribeTowerUnitAIModule * this, RGE_Stat
    //              int               EAX:4          <RETURN>
    //              TribeTowerUnit    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00508110(R)  
    //                               ?canAttackUnit@TribeTowerUnitAIModule@@UAEHPAVRGE_Static_Ob  XREF[1]:     005763c0(*)  
    //                               TribeTowerUnitAIModule::canAttackUnit
    //                              taiuaimd.cpp:2961 (8)
    //         00508110     MOV        EAX,dword ptr [ESP + param_1]
    //         00508114     TEST       EAX,EAX
    //         00508116     JNZ        LAB_0050811b
    //                              taiuaimd.cpp:2970 (3)
    //         00508118     RET        0x4
    //                               LAB_0050811b                                                 XREF[1]:     00508116(j)  
    //                              taiuaimd.cpp:2964 (10)
    //         0050811b     MOV        EAX,dword ptr [EAX + 0x8]
    //         0050811e     CMP        word ptr [EAX + 0x14],0x1
    //         00508123     JNZ        LAB_0050812a
    //                              taiuaimd.cpp:2965 (2)
    //         00508125     XOR        EAX,EAX
    //                              taiuaimd.cpp:2970 (3)
    //         00508127     RET        0x4
    //                               LAB_0050812a                                                 XREF[1]:     00508123(j)  
    //                              taiuaimd.cpp:2967 (10)
    //         0050812a     MOV        this,dword ptr [ECX + this->field4_0x4]
    //         0050812d     CMP        byte ptr [ECX + this->field72_0x48],0x2
    //         00508131     SBB        EAX,EAX
    //         00508133     INC        EAX
    //                              taiuaimd.cpp:2970 (3)
    //         00508134     RET        0x4
    //         00508137     ??         90h
    //         00508138     NOP
    //         00508139     NOP
    //         0050813a     NOP
    //         0050813b     NOP
    //         0050813c     NOP
    //         0050813d     NOP
    //         0050813e     NOP
    //         0050813f     NOP
    return 0;
}

int TribeTowerUnitAIModule::canAttackUnitAtNeutrality(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall canAttackUnitAtNeutrality(TribeTowerUnitAIModule * th
    //              int               EAX:4          <RETURN>
    //              TribeTowerUnit    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00508140(R)  
    //                               ?canAttackUnitAtNeutrality@TribeTowerUnitAIModule@@UAEHH@Z   XREF[1]:     005763c4(*)  
    //                               TribeTowerUnitAIModule::canAttackUnitAtNeutrality
    //                              taiuaimd.cpp:2975 (29)
    //         00508140     MOV        EAX,dword ptr [ESP + param_1]
    //         00508144     CMP        EAX,0x3
    //         00508147     JZ         LAB_00508165
    //         00508149     CMP        EAX,0x1b
    //         0050814c     JZ         LAB_00508165
    //         0050814e     CMP        EAX,0x4
    //         00508151     JZ         LAB_00508165
    //         00508153     CMP        EAX,0x15
    //         00508156     JZ         LAB_00508165
    //         00508158     CMP        EAX,0x2
    //         0050815b     JZ         LAB_00508165
    //                              taiuaimd.cpp:2984 (5)
    //         0050815d     MOV        EAX,0x1
    //                              taiuaimd.cpp:2985 (3)
    //         00508162     RET        0x4
    //                               LAB_00508165                                                 XREF[5]:     00508147(j), 0050814c(j), 
    //                                                                                                         00508151(j), 00508156(j), 
    //                                                                                                         0050815b(j)  
    //                              taiuaimd.cpp:2983 (2)
    //         00508165     XOR        EAX,EAX
    //                              taiuaimd.cpp:2985 (3)
    //         00508167     RET        0x4
    //         0050816a     ??         90h
    //         0050816b     NOP
    //         0050816c     NOP
    //         0050816d     NOP
    //         0050816e     NOP
    //         0050816f     NOP
    //                              * public: __thiscall TribeBuildingUnitAIModule::TribeBuildingUnitAIModule(class RGE_Static_Object *,... *
    //                              undefined __thiscall TribeBuildingUnitAIModule(TribeBuildingUnitAIMo
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TribeBuildingU    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     0050818e(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     00508186(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     005081a0(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     005082d8(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00508192(W)  
    //                               ??0TribeBuildingUnitAIModule@@QAE@PAVRGE_Static_Object@@H@Z  XREF[1]:     initUnitAI:004cbc2a(c)  
    //                               TribeBuildingUnitAIModule::TribeBuildingUnitAIModule
    //                              taiuaimd.cpp:2993 (46)
    //         00508170     PUSH       -0x1
    //         00508172     PUSH       FUN_00560d68
    //         00508177     MOV        EAX,FS:[0x0]
    //         0050817d     PUSH       EAX
    //         0050817e     MOV        dword ptr FS:[0x0],ESP
    //         00508185     PUSH       this
    //         00508186     MOV        EAX,dword ptr [ESP + param_2]
    //         0050818a     PUSH       ESI
    //         0050818b     MOV        ESI,this
    //         0050818d     PUSH       EAX
    //         0050818e     MOV        this,dword ptr [ESP + param_1]
    //         00508192     MOV        dword ptr [ESP + local_10],ESI
    //         00508196     PUSH       this
    //         00508197     MOV        this,ESI
    //         00508199     CALL       UnitAIModule::UnitAIModule                       undefined UnitAIModule(UnitAIModule * this, R
    //                              taiuaimd.cpp:2997 (40)
    //         0050819e     PUSH       0x54
    //         005081a0     MOV        dword ptr [ESP + local_4],0x0
    //         005081a8     MOV        dword ptr [ESI],TribeBuildingUnitAIModule::`vf   = 005082f0
    //         005081ae     MOV        dword ptr [ESI + 0x128],0x15
    //         005081b8     CALL       operator_new                                     void * operator_new(uint param_1)
    //         005081bd     ADD        ESP,0x4
    //         005081c0     MOV        dword ptr [ESI + 0x124],EAX
    //                              taiuaimd.cpp:2998 (8)
    //         005081c6     TEST       EAX,EAX
    //         005081c8     JZ         LAB_005082d8
    //                              taiuaimd.cpp:2999 (6)
    //         005081ce     MOV        dword ptr [EAX],0x0
    //                              taiuaimd.cpp:3000 (13)
    //         005081d4     MOV        EDX,dword ptr [ESI + 0x124]
    //         005081da     MOV        dword ptr [EDX + 0x4],0x3
    //                              taiuaimd.cpp:3001 (13)
    //         005081e1     MOV        EAX,dword ptr [ESI + 0x124]
    //         005081e7     MOV        dword ptr [EAX + 0x8],0x4
    //                              taiuaimd.cpp:3002 (13)
    //         005081ee     MOV        this,dword ptr [ESI + 0x124]
    //         005081f4     MOV        dword ptr [ECX + this->field12_0xc],0x1a
    //                              taiuaimd.cpp:3003 (13)
    //         005081fb     MOV        EDX,dword ptr [ESI + 0x124]
    //         00508201     MOV        dword ptr [EDX + 0x10],0x18
    //                              taiuaimd.cpp:3004 (13)
    //         00508208     MOV        EAX,dword ptr [ESI + 0x124]
    //         0050820e     MOV        dword ptr [EAX + 0x14],0x6
    //                              taiuaimd.cpp:3005 (13)
    //         00508215     MOV        this,dword ptr [ESI + 0x124]
    //         0050821b     MOV        dword ptr [ECX + this->field24_0x18],0x23
    //                              taiuaimd.cpp:3006 (13)
    //         00508222     MOV        EDX,dword ptr [ESI + 0x124]
    //         00508228     MOV        dword ptr [EDX + 0x1c],0x19
    //                              taiuaimd.cpp:3007 (13)
    //         0050822f     MOV        EAX,dword ptr [ESI + 0x124]
    //         00508235     MOV        dword ptr [EAX + 0x20],0x11
    //                              taiuaimd.cpp:3008 (13)
    //         0050823c     MOV        this,dword ptr [ESI + 0x124]
    //         00508242     MOV        dword ptr [ECX + this->field36_0x24],0xc
    //                              taiuaimd.cpp:3009 (13)
    //         00508249     MOV        EDX,dword ptr [ESI + 0x124]
    //         0050824f     MOV        dword ptr [EDX + 0x28],0x17
    //                              taiuaimd.cpp:3010 (13)
    //         00508256     MOV        EAX,dword ptr [ESI + 0x124]
    //         0050825c     MOV        dword ptr [EAX + 0x2c],0x24
    //                              taiuaimd.cpp:3011 (13)
    //         00508263     MOV        this,dword ptr [ESI + 0x124]
    //         00508269     MOV        dword ptr [ECX + this->field48_0x30],0x1c
    //                              taiuaimd.cpp:3012 (13)
    //         00508270     MOV        EDX,dword ptr [ESI + 0x124]
    //         00508276     MOV        dword ptr [EDX + 0x34],0x12
    //                              taiuaimd.cpp:3013 (13)
    //         0050827d     MOV        EAX,dword ptr [ESI + 0x124]
    //         00508283     MOV        dword ptr [EAX + 0x38],0xd
    //                              taiuaimd.cpp:3014 (13)
    //         0050828a     MOV        this,dword ptr [ESI + 0x124]
    //         00508290     MOV        dword ptr [ECX + this->field60_0x3c],0x1b
    //                              taiuaimd.cpp:3015 (13)
    //         00508297     MOV        EDX,dword ptr [ESI + 0x124]
    //         0050829d     MOV        dword ptr [EDX + 0x40],0x16
    //                              taiuaimd.cpp:3016 (13)
    //         005082a4     MOV        EAX,dword ptr [ESI + 0x124]
    //         005082aa     MOV        dword ptr [EAX + 0x44],0x14
    //                              taiuaimd.cpp:3017 (13)
    //         005082b1     MOV        this,dword ptr [ESI + 0x124]
    //         005082b7     MOV        dword ptr [ECX + this->field72_0x48],0x2
    //                              taiuaimd.cpp:3018 (13)
    //         005082be     MOV        EDX,dword ptr [ESI + 0x124]
    //         005082c4     MOV        dword ptr [EDX + 0x4c],0x15
    //                              taiuaimd.cpp:3019 (13)
    //         005082cb     MOV        EAX,dword ptr [ESI + 0x124]
    //         005082d1     MOV        dword ptr [EAX + 0x50],0x27
    //                               LAB_005082d8                                                 XREF[1]:     005081c8(j)  
    //                              taiuaimd.cpp:3021 (20)
    //         005082d8     MOV        this,dword ptr [ESP + local_c]
    //         005082dc     MOV        EAX,ESI
    //         005082de     MOV        dword ptr FS:[0x0],this
    //         005082e5     POP        ESI
    //         005082e6     ADD        ESP,0x10
    //         005082e9     RET        0x8
    //         005082ec     ??         90h
    //         005082ed     NOP
    //         005082ee     NOP
    //         005082ef     NOP
    //                              * public: virtual void * __thiscall TribeBuildingUnitAIModule::`scalar deleting destructor'(unsigned... *
    //                              void * __thiscall `scalar_deleting_destructor'(TribeBuildingUnitAIMo
    //              void *            EAX:4          <RETURN>
    //              TribeBuildingU    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     005082f8(R)  
    //                               ??_ETribeBuildingUnitAIModule@@UAEPAXI@Z                     XREF[1]:     00576450(*)  
    //                               ??_GTribeBuildingUnitAIModule@@UAEPAXI@Z
    //                               TribeBuildingUnitAIModule::`scalar_deleting_destructor'
    //         005082f0     PUSH       ESI
    //         005082f1     MOV        ESI,this
    //         005082f3     CALL       TribeBuildingUnitAIModule::~TribeBuildingUnitA   void ~TribeBuildingUnitAIModule(TribeBuilding
    //         005082f8     TEST       byte ptr [ESP + param_1],0x1
    //         005082fd     JZ         LAB_00508308
    //         005082ff     PUSH       ESI
    //         00508300     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00508305     ADD        ESP,0x4
    //                               LAB_00508308                                                 XREF[1]:     005082fd(j)  
    //         00508308     MOV        EAX,ESI
    //         0050830a     POP        ESI
    //         0050830b     RET        0x4
    //                              *                                            THUNK FUNCTION                                             *
    //                              thunk void __thiscall ~UnitAIModule(UnitAIModule * this)
    //                                Thunked-Function: UnitAIModule::~UnitAIMo
    //              void              <VOID>         <RETURN>
    //              UnitAIModule *    ECX:4 (auto)   this
    //                               UnitAIModule::~UnitAIModule
    //         0050830e     NOP
    //         0050830f     NOP
    return 0;
}

TribeBuildingUnitAIModule::~TribeBuildingUnitAIModule() {
    /* TODO: Stub */
    //                              void __thiscall ~TribeBuildingUnitAIModule(TribeBuildingUnitAIModule
    //              void              <VOID>         <RETURN>
    //              TribeBuildingU    ECX:4 (auto)   this
    //                               ??1TribeBuildingUnitAIModule@@UAE@XZ                         XREF[1]:     `scalar_deleting_destructor':00508
    //                               TribeBuildingUnitAIModule::~TribeBuildingUnitAIModule
    //         00508310     JMP        UnitAIModule::~UnitAIModule
    //         00508315     ??         90h
    //         00508316     NOP
    //         00508317     NOP
    //         00508318     NOP
    //         00508319     NOP
    //         0050831a     NOP
    //         0050831b     NOP
    //         0050831c     NOP
    //         0050831d     NOP
    //         0050831e     NOP
    //         0050831f     NOP
    //                              * protected: virtual int __thiscall TribeBuildingUnitAIModule::processNotify(struct NotifyEvent *,un... *
    //                              int __thiscall processNotify(TribeBuildingUnitAIModule * this, Notif
    //              int               EAX:4          <RETURN>
    //              TribeBuildingU    ECX:4 (auto)   this
    //              NotifyEvent *     Stack[0x4]:4   param_1                   XREF[1]:     00508321(R)  
    //              ulong             Stack[0x8]:4   param_2
    //                               ?processNotify@TribeBuildingUnitAIModule@@MAEHPAUNotifyEven  XREF[1]:     0057651c(*)  
    //                               TribeBuildingUnitAIModule::processNotify
    //                              taiuaimd.cpp:3027 (1)
    //         00508320     PUSH       EBX
    //                              taiuaimd.cpp:3039 (43)
    //         00508321     MOV        EBX,dword ptr [ESP + param_1]
    //         00508325     PUSH       EBP
    //         00508326     PUSH       ESI
    //         00508327     MOV        EAX,dword ptr [EBX + 0x8]
    //         0050832a     PUSH       EDI
    //         0050832b     ADD        EAX,0xfffffe0c
    //         00508330     MOV        ESI,this
    //         00508332     CMP        EAX,0xc7
    //         00508337     JA         switchD_00508345::caseD_1f5
    //         0050833d     XOR        this,this
    //         0050833f     MOV        this,byte ptr [EAX + switchD_00508345::switchd
    //                               switchD_00508345::switchD
    //         00508345     JMP        dword ptr [this->field0_0x0*0x4 + switchD_0050   = 0050834c
    //                               switchD_00508345::caseD_1f4                                  XREF[2]:     00508345(j), 00508578(*)  
    //                              taiuaimd.cpp:3047 (7)
    //         0050834c     MOV        EAX,dword ptr [EBX + 0x10]
    //         0050834f     TEST       EAX,EAX
    //         00508351     JG         LAB_0050838a
    //                              taiuaimd.cpp:3052 (31)
    //         00508353     MOV        EAX,dword ptr [ESI + 0x4]
    //         00508356     MOV        EDI,dword ptr [EBX]
    //         00508358     PUSH       0x0
    //         0050835a     PUSH       0x0
    //         0050835c     MOV        this,dword ptr [EAX + 0xc]
    //         0050835f     MOV        EAX,dword ptr [EAX + 0x4]
    //         00508362     PUSH       EDI
    //         00508363     PUSH       0x209
    //         00508368     MOV        EDX,dword ptr [this->field0_0x0]
    //         0050836a     PUSH       EAX
    //         0050836b     PUSH       EAX
    //         0050836c     CALL       dword ptr [EDX + 0xe8]
    //                              taiuaimd.cpp:3053 (12)
    //         00508372     MOV        EAX,dword ptr [ESP + 0x18]
    //         00508376     MOV        this,ESI
    //         00508378     PUSH       EAX
    //         00508379     CALL       UnitAIModule::purgeNotifyQueue                   void purgeNotifyQueue(UnitAIModule * this, ul
    //                              taiuaimd.cpp:3054 (5)
    //         0050837e     MOV        EAX,0x4
    //                              taiuaimd.cpp:3115 (7)
    //         00508383     POP        EDI
    //         00508384     POP        ESI
    //         00508385     POP        EBP
    //         00508386     POP        EBX
    //         00508387     RET        0x8
    //                               LAB_0050838a                                                 XREF[1]:     00508351(j)  
    //                              taiuaimd.cpp:3065 (23)
    //         0050838a     MOV        EAX,dword ptr [ESI + 0x64]
    //         0050838d     TEST       EAX,EAX
    //         0050838f     JZ         LAB_005083a1
    //         00508391     MOV        this,dword ptr [ESI + 0x4]
    //         00508394     MOV        this,dword ptr [ECX + this->field12_0xc]
    //         00508397     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
    //         0050839c     CMP        EAX,0x1
    //         0050839f     JNZ        LAB_005083c0
    //                               LAB_005083a1                                                 XREF[1]:     0050838f(j)  
    //                              taiuaimd.cpp:3067 (31)
    //         005083a1     MOV        EAX,dword ptr [ESI + 0x4]
    //         005083a4     MOV        EDI,dword ptr [EBX]
    //         005083a6     PUSH       0x0
    //         005083a8     PUSH       0x0
    //         005083aa     MOV        this,dword ptr [EAX + 0xc]
    //         005083ad     MOV        EAX,dword ptr [EAX + 0x4]
    //         005083b0     PUSH       EDI
    //         005083b1     PUSH       0x201
    //         005083b6     MOV        EDX,dword ptr [this->field0_0x0]
    //         005083b8     PUSH       EAX
    //         005083b9     PUSH       EAX
    //         005083ba     CALL       dword ptr [EDX + 0xe8]
    //                               LAB_005083c0                                                 XREF[1]:     0050839f(j)  
    //                              taiuaimd.cpp:3075 (58)
    //         005083c0     MOV        this,dword ptr [ESI + 0x64]
    //         005083c3     LEA        EDI,[ESI + 0x60]
    //         005083c6     XOR        EAX,EAX
    //         005083c8     TEST       this,this
    //         005083ca     JLE        LAB_005083e2
    //         005083cc     MOV        EDX,dword ptr [EDI + 0xc]
    //                               LAB_005083cf                                                 XREF[1]:     005083e0(j)  
    //         005083cf     CMP        EAX,EDX
    //         005083d1     JGE        LAB_005083e2
    //         005083d3     MOV        EBP,dword ptr [EDI]
    //         005083d5     MOV        EBP,dword ptr [EBP + EAX*0x4]
    //         005083d9     CMP        EBP,dword ptr [EBX]
    //         005083db     JZ         LAB_00508402
    //         005083dd     INC        EAX
    //         005083de     CMP        EAX,this
    //         005083e0     JL         LAB_005083cf
    //                               LAB_005083e2                                                 XREF[2]:     005083ca(j), 005083d1(j)  
    //         005083e2     MOV        EAX,dword ptr [ESI + 0x4]
    //         005083e5     MOV        this,dword ptr [EAX + 0xc]
    //         005083e8     CALL       RGE_Player::computerPlayer                       int computerPlayer(RGE_Player * this)
    //         005083ed     TEST       EAX,EAX
    //         005083ef     JNZ        LAB_00508402
    //         005083f1     MOV        EAX,dword ptr [EBX]
    //         005083f3     MOV        this,dword ptr [ESI + 0x34]
    //         005083f6     CMP        this,EAX
    //         005083f8     JZ         LAB_00508402
    //                              taiuaimd.cpp:3076 (8)
    //         005083fa     PUSH       EAX
    //         005083fb     MOV        this,ESI
    //         005083fd     CALL       UnitAIModule::askForHelp                         void askForHelp(UnitAIModule * this, int para
    //                               LAB_00508402                                                 XREF[3]:     005083db(j), 005083ef(j), 
    //                                                                                                         005083f8(j)  
    //                              taiuaimd.cpp:3079 (57)
    //         00508402     MOV        this,dword ptr [EDI + 0x4]
    //         00508405     MOV        EBX,dword ptr [EBX]
    //         00508407     XOR        EAX,EAX
    //         00508409     TEST       this,this
    //         0050840b     JLE        LAB_00508425
    //         0050840d     MOV        EDX,dword ptr [EDI + 0xc]
    //                               LAB_00508410                                                 XREF[1]:     00508423(j)  
    //         00508410     CMP        EAX,EDX
    //         00508412     JGE        LAB_00508425
    //         00508414     MOV        EBP,dword ptr [EDI]
    //         00508416     CMP        dword ptr [EBP + EAX*0x4],EBX
    //         0050841a     JZ         LAB_005084e0
    //         00508420     INC        EAX
    //         00508421     CMP        EAX,this
    //         00508423     JL         LAB_00508410
    //                               LAB_00508425                                                 XREF[2]:     0050840b(j), 00508412(j)  
    //         00508425     MOV        EDX,dword ptr [EDI + 0xc]
    //         00508428     DEC        EDX
    //         00508429     CMP        this,EDX
    //         0050842b     JLE        LAB_00508436
    //         0050842d     INC        this
    //         0050842e     PUSH       this
    //         0050842f     MOV        this,EDI
    //         00508431     CALL       ManagedArray<int>::resize                        int resize(ManagedArray<int> * this, int para
    //                               LAB_00508436                                                 XREF[1]:     0050842b(j)  
    //         00508436     MOV        EAX,dword ptr [EDI + 0x4]
    //         00508439     MOV        this,dword ptr [EDI]
    //                              taiuaimd.cpp:3080 (23)
    //         0050843b     PUSH       0x1
    //         0050843d     MOV        dword ptr [this->field0_0x0 + EAX*0x4],EBX
    //         00508440     MOV        EAX,dword ptr [EDI + 0x4]
    //         00508443     INC        EAX
    //         00508444     MOV        dword ptr [EDI + 0x4],EAX
    //         00508447     MOV        this,dword ptr [ESI + 0x4]
    //         0050844a     MOV        EDX,dword ptr [this->field0_0x0]
    //         0050844c     CALL       dword ptr [EDX + 0xec]
    //                              taiuaimd.cpp:3114 (5)
    //         00508452     MOV        EAX,0x2
    //                              taiuaimd.cpp:3115 (7)
    //         00508457     POP        EDI
    //         00508458     POP        ESI
    //         00508459     POP        EBP
    //         0050845a     POP        EBX
    //         0050845b     RET        0x8
    //                               switchD_00508345::caseD_258                                  XREF[2]:     00508345(j), 00508580(*)  
    //                              taiuaimd.cpp:3090 (130)
    //         0050845e     MOV        this,dword ptr [ESI + 0x64]
    //         00508461     MOV        EBX,dword ptr [EBX]
    //         00508463     XOR        EAX,EAX
    //         00508465     TEST       this,this
    //         00508467     JLE        LAB_0050847d
    //         00508469     MOV        EDX,dword ptr [ESI + 0x6c]
    //                               LAB_0050846c                                                 XREF[1]:     0050847b(j)  
    //         0050846c     CMP        EAX,EDX
    //         0050846e     JGE        LAB_0050847d
    //         00508470     MOV        EDI,dword ptr [ESI + 0x60]
    //         00508473     CMP        dword ptr [EDI + EAX*0x4],EBX
    //         00508476     JZ         LAB_005084e0
    //         00508478     INC        EAX
    //         00508479     CMP        EAX,this
    //         0050847b     JL         LAB_0050846c
    //                               LAB_0050847d                                                 XREF[2]:     00508467(j), 0050846e(j)  
    //         0050847d     MOV        EAX,dword ptr [ESI + 0x6c]
    //         00508480     DEC        EAX
    //         00508481     CMP        this,EAX
    //         00508483     JLE        LAB_005084d0
    //         00508485     LEA        EBP,[ECX + this->field1_0x1]
    //         00508488     LEA        this,[EBP*0x4 + 0x0]
    //         0050848f     PUSH       this
    //         00508490     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00508495     MOV        EDI,EAX
    //         00508497     ADD        ESP,0x4
    //         0050849a     TEST       EDI,EDI
    //         0050849c     JZ         LAB_005084d0
    //         0050849e     MOV        this,dword ptr [ESI + 0x6c]
    //         005084a1     XOR        EAX,EAX
    //         005084a3     TEST       this,this
    //         005084a5     JLE        LAB_005084be
    //                               LAB_005084a7                                                 XREF[1]:     005084bc(j)  
    //         005084a7     CMP        EAX,EBP
    //         005084a9     JGE        LAB_005084be
    //         005084ab     MOV        EDX,dword ptr [ESI + 0x60]
    //         005084ae     INC        EAX
    //         005084af     MOV        this,dword ptr [EDX + EAX*0x4 + -0x4]
    //         005084b3     MOV        dword ptr [EDI + EAX*0x4 + -0x4],this
    //         005084b7     MOV        this,dword ptr [ESI + 0x6c]
    //         005084ba     CMP        EAX,this
    //         005084bc     JL         LAB_005084a7
    //                               LAB_005084be                                                 XREF[2]:     005084a5(j), 005084a9(j)  
    //         005084be     MOV        EDX,dword ptr [ESI + 0x60]
    //         005084c1     PUSH       EDX
    //         005084c2     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         005084c7     ADD        ESP,0x4
    //         005084ca     MOV        dword ptr [ESI + 0x60],EDI
    //         005084cd     MOV        dword ptr [ESI + 0x6c],EBP
    //                               LAB_005084d0                                                 XREF[2]:     00508483(j), 0050849c(j)  
    //         005084d0     MOV        EAX,dword ptr [ESI + 0x64]
    //         005084d3     MOV        this,dword ptr [ESI + 0x60]
    //         005084d6     MOV        dword ptr [this->field0_0x0 + EAX*0x4],EBX
    //         005084d9     MOV        EAX,dword ptr [ESI + 0x64]
    //         005084dc     INC        EAX
    //         005084dd     MOV        dword ptr [ESI + 0x64],EAX
    //                               LAB_005084e0                                                 XREF[2]:     0050841a(j), 00508476(j)  
    //                              taiuaimd.cpp:3091 (13)
    //         005084e0     MOV        this,dword ptr [ESI + 0x4]
    //         005084e3     PUSH       0x1
    //         005084e5     MOV        EDX,dword ptr [this->field0_0x0]
    //         005084e7     CALL       dword ptr [EDX + 0xec]
    //                              taiuaimd.cpp:3114 (5)
    //         005084ed     MOV        EAX,0x2
    //                              taiuaimd.cpp:3115 (7)
    //         005084f2     POP        EDI
    //         005084f3     POP        ESI
    //         005084f4     POP        EBP
    //         005084f5     POP        EBX
    //         005084f6     RET        0x8
    //                               switchD_00508345::caseD_2bb                                  XREF[2]:     00508345(j), 00508584(*)  
    //                              taiuaimd.cpp:3102 (33)
    //         005084f9     MOV        this,dword ptr [ESI + 0x64]
    //         005084fc     XOR        EAX,EAX
    //         005084fe     TEST       this,this
    //         00508500     JLE        switchD_00508345::caseD_1f5
    //         00508502     MOV        EDX,dword ptr [ESI + 0x6c]
    //                               LAB_00508505                                                 XREF[1]:     00508518(j)  
    //         00508505     CMP        EAX,EDX
    //         00508507     JGE        switchD_00508345::caseD_1f5
    //         00508509     MOV        EDI,dword ptr [ESI + 0x60]
    //         0050850c     MOV        EBP,dword ptr [EBX]
    //         0050850e     MOV        EDI,dword ptr [EDI + EAX*0x4]
    //         00508511     CMP        EDI,EBP
    //         00508513     JZ         LAB_00508526
    //         00508515     INC        EAX
    //         00508516     CMP        EAX,this
    //         00508518     JL         LAB_00508505
    //                              taiuaimd.cpp:3114 (5)
    //         0050851a     MOV        EAX,0x2
    //                              taiuaimd.cpp:3115 (7)
    //         0050851f     POP        EDI
    //         00508520     POP        ESI
    //         00508521     POP        EBP
    //         00508522     POP        EBX
    //         00508523     RET        0x8
    //                               LAB_00508526                                                 XREF[1]:     00508513(j)  
    //                              taiuaimd.cpp:3107 (70)
    //         00508526     MOV        this,dword ptr [ESI + 0x6c]
    //         00508529     MOV        EBX,dword ptr [EBX]
    //         0050852b     XOR        EAX,EAX
    //         0050852d     TEST       this,this
    //         0050852f     JLE        LAB_00508540
    //         00508531     MOV        EDX,dword ptr [ESI + 0x60]
    //                               LAB_00508534                                                 XREF[1]:     0050853e(j)  
    //         00508534     CMP        dword ptr [EDX],EBX
    //         00508536     JZ         LAB_00508540
    //         00508538     INC        EAX
    //         00508539     ADD        EDX,0x4
    //         0050853c     CMP        EAX,this
    //         0050853e     JL         LAB_00508534
    //                               LAB_00508540                                                 XREF[2]:     0050852f(j), 00508536(j)  
    //         00508540     CMP        EAX,this
    //         00508542     JGE        switchD_00508345::caseD_1f5
    //         00508544     DEC        this
    //         00508545     CMP        EAX,this
    //         00508547     JGE        LAB_0050855c
    //                               LAB_00508549                                                 XREF[1]:     0050855a(j)  
    //         00508549     MOV        this,dword ptr [ESI + 0x60]
    //         0050854c     INC        EAX
    //         0050854d     MOV        EDX,dword ptr [this->field0_0x0 + EAX*0x4]
    //         00508550     MOV        dword ptr [this->field0_0x0 + EAX*0x4 + -0x4],
    //         00508554     MOV        this,dword ptr [ESI + 0x6c]
    //         00508557     DEC        this
    //         00508558     CMP        EAX,this
    //         0050855a     JL         LAB_00508549
    //                               LAB_0050855c                                                 XREF[1]:     00508547(j)  
    //         0050855c     MOV        EAX,dword ptr [ESI + 0x64]
    //         0050855f     DEC        EAX
    //         00508560     MOV        dword ptr [ESI + 0x64],EAX
    //         00508563     JNS        switchD_00508345::caseD_1f5
    //         00508565     MOV        dword ptr [ESI + 0x64],0x0
    //                               switchD_00508345::caseD_1f6                                  XREF[8]:     00508337(j), 00508345(j), 
    //                               switchD_00508345::caseD_1f7                                               00508500(j), 00508507(j), 
    //                               switchD_00508345::caseD_1f8                                               00508542(j), 00508563(j), 
    //                               switchD_00508345::caseD_1f9                                               0050857c(*), 00508588(*)  
    //                               switchD_00508345::caseD_1fa
    //                               switchD_00508345::caseD_1fb
    //                               switchD_00508345::caseD_1fc
    //                               switchD_00508345::caseD_1fd
    //                               switchD_00508345::caseD_1fe
    //                               switchD_00508345::caseD_1ff
    //                               switchD_00508345::caseD_200
    //                               switchD_00508345::caseD_201
    //                               switchD_00508345::caseD_202
    //                               switchD_00508345::caseD_203
    //                               switchD_00508345::caseD_204
    //                               switchD_00508345::caseD_205
    //                               switchD_00508345::caseD_206
    //                               switchD_00508345::caseD_207
    //                               switchD_00508345::caseD_208
    //                               switchD_00508345::caseD_209
    //                               switchD_00508345::caseD_20a
    //                               switchD_00508345::caseD_20b
    //                               switchD_00508345::caseD_20c
    //                               switchD_00508345::caseD_20d
    //                               switchD_00508345::caseD_20e
    //                               switchD_00508345::caseD_20f
    //                               switchD_00508345::caseD_210
    //                               switchD_00508345::caseD_211
    //                               switchD_00508345::caseD_212
    //                               switchD_00508345::caseD_213
    //                               switchD_00508345::caseD_214
    //                               switchD_00508345::caseD_215
    //                               switchD_00508345::caseD_216
    //                               switchD_00508345::caseD_217
    //                               switchD_00508345::caseD_218
    //                               switchD_00508345::caseD_219
    //                               switchD_00508345::caseD_21a
    //                               switchD_00508345::caseD_21b
    //                               switchD_00508345::caseD_21c
    //                               switchD_00508345::caseD_21d
    //                               switchD_00508345::caseD_21e
    //                               switchD_00508345::caseD_21f
    //                               switchD_00508345::caseD_220
    //                               switchD_00508345::caseD_221
    //                               switchD_00508345::caseD_222
    //                               switchD_00508345::caseD_223
    //                               switchD_00508345::caseD_224
    //                               switchD_00508345::caseD_225
    //                               switchD_00508345::caseD_226
    //                               switchD_00508345::caseD_227
    //                               switchD_00508345::caseD_228
    //                               switchD_00508345::caseD_229
    //                               switchD_00508345::caseD_22a
    //                               switchD_00508345::caseD_22b
    //                               switchD_00508345::caseD_22c
    //                               switchD_00508345::caseD_22d
    //                               switchD_00508345::caseD_22e
    //                               switchD_00508345::caseD_22f
    //                               switchD_00508345::caseD_230
    //                               switchD_00508345::caseD_231
    //                               switchD_00508345::caseD_232
    //                               switchD_00508345::caseD_233
    //                               switchD_00508345::caseD_234
    //                               switchD_00508345::caseD_235
    //                               switchD_00508345::caseD_236
    //                               switchD_00508345::caseD_237
    //                               switchD_00508345::caseD_238
    //                               switchD_00508345::caseD_239
    //                               switchD_00508345::caseD_23a
    //                               switchD_00508345::caseD_23b
    //                               switchD_00508345::caseD_23c
    //                               switchD_00508345::caseD_23d
    //                               switchD_00508345::caseD_23e
    //                               switchD_00508345::caseD_23f
    //                               switchD_00508345::caseD_240
    //                               switchD_00508345::caseD_241
    //                               switchD_00508345::caseD_242
    //                               switchD_00508345::caseD_243
    //                               switchD_00508345::caseD_244
    //                               switchD_00508345::caseD_245
    //                               switchD_00508345::caseD_246
    //                               switchD_00508345::caseD_247
    //                               switchD_00508345::caseD_248
    //                               switchD_00508345::caseD_249
    //                               switchD_00508345::caseD_24a
    //                               switchD_00508345::caseD_24b
    //                               switchD_00508345::caseD_24c
    //                               switchD_00508345::caseD_24d
    //                               switchD_00508345::caseD_24e
    //                               switchD_00508345::caseD_24f
    //                               switchD_00508345::caseD_250
    //                               switchD_00508345::caseD_251
    //                               switchD_00508345::caseD_252
    //                               switchD_00508345::caseD_253
    //                               switchD_00508345::caseD_254
    //                               switchD_00508345::caseD_255
    //                               switchD_00508345::caseD_256
    //                               switchD_00508345::caseD_257
    //                               switchD_00508345::caseD_259
    //                               switchD_00508345::caseD_25a
    //                               switchD_00508345::caseD_25b
    //                               switchD_00508345::caseD_25c
    //                               switchD_00508345::caseD_25d
    //                               switchD_00508345::caseD_25e
    //                               switchD_00508345::caseD_25f
    //                               switchD_00508345::caseD_260
    //                               switchD_00508345::caseD_261
    //                               switchD_00508345::caseD_262
    //                               switchD_00508345::caseD_263
    //                               switchD_00508345::caseD_264
    //                               switchD_00508345::caseD_265
    //                               switchD_00508345::caseD_266
    //                               switchD_00508345::caseD_267
    //                               switchD_00508345::caseD_268
    //                               switchD_00508345::caseD_269
    //                               switchD_00508345::caseD_26a
    //                               switchD_00508345::caseD_26b
    //                               switchD_00508345::caseD_26c
    //                               switchD_00508345::caseD_26d
    //                               switchD_00508345::caseD_26e
    //                               switchD_00508345::caseD_26f
    //                               switchD_00508345::caseD_270
    //                               switchD_00508345::caseD_271
    //                               switchD_00508345::caseD_272
    //                               switchD_00508345::caseD_273
    //                               switchD_00508345::caseD_274
    //                               switchD_00508345::caseD_275
    //                               switchD_00508345::caseD_276
    //                               switchD_00508345::caseD_277
    //                               switchD_00508345::caseD_278
    //                               switchD_00508345::caseD_279
    //                               switchD_00508345::caseD_27a
    //                               switchD_00508345::caseD_27b
    //                               switchD_00508345::caseD_27c
    //                               switchD_00508345::caseD_27d
    //                               switchD_00508345::caseD_27e
    //                               switchD_00508345::caseD_27f
    //                               switchD_00508345::caseD_280
    //                               switchD_00508345::caseD_281
    //                               switchD_00508345::caseD_282
    //                               switchD_00508345::caseD_283
    //                               switchD_00508345::caseD_284
    //                               switchD_00508345::caseD_285
    //                               switchD_00508345::caseD_286
    //                               switchD_00508345::caseD_287
    //                               switchD_00508345::caseD_288
    //                               switchD_00508345::caseD_289
    //                               switchD_00508345::caseD_28a
    //                               switchD_00508345::caseD_28b
    //                               switchD_00508345::caseD_28c
    //                               switchD_00508345::caseD_28d
    //                               switchD_00508345::caseD_28e
    //                               switchD_00508345::caseD_28f
    //                               switchD_00508345::caseD_290
    //                               switchD_00508345::caseD_291
    //                               switchD_00508345::caseD_292
    //                               switchD_00508345::caseD_293
    //                               switchD_00508345::caseD_294
    //                               switchD_00508345::caseD_295
    //                               switchD_00508345::caseD_296
    //                               switchD_00508345::caseD_297
    //                               switchD_00508345::caseD_298
    //                               switchD_00508345::caseD_299
    //                               switchD_00508345::caseD_29a
    //                               switchD_00508345::caseD_29b
    //                               switchD_00508345::caseD_29c
    //                               switchD_00508345::caseD_29d
    //                               switchD_00508345::caseD_29e
    //                               switchD_00508345::caseD_29f
    //                               switchD_00508345::caseD_2a0
    //                               switchD_00508345::caseD_2a1
    //                               switchD_00508345::caseD_2a2
    //                               switchD_00508345::caseD_2a3
    //                               switchD_00508345::caseD_2a4
    //                               switchD_00508345::caseD_2a5
    //                               switchD_00508345::caseD_2a6
    //                               switchD_00508345::caseD_2a7
    //                               switchD_00508345::caseD_2a8
    //                               switchD_00508345::caseD_2a9
    //                               switchD_00508345::caseD_2aa
    //                               switchD_00508345::caseD_2ab
    //                               switchD_00508345::caseD_2ac
    //                               switchD_00508345::caseD_2ad
    //                               switchD_00508345::caseD_2ae
    //                               switchD_00508345::caseD_2af
    //                               switchD_00508345::caseD_2b0
    //                               switchD_00508345::caseD_2b1
    //                               switchD_00508345::caseD_2b2
    //                               switchD_00508345::caseD_2b3
    //                               switchD_00508345::caseD_2b4
    //                               switchD_00508345::caseD_2b5
    //                               switchD_00508345::caseD_2b6
    //                               switchD_00508345::caseD_2b7
    //                               switchD_00508345::caseD_2b8
    //                               switchD_00508345::caseD_2b9
    //                               switchD_00508345::caseD_2ba
    //                               switchD_00508345::caseD_1f5
    //                              taiuaimd.cpp:3115 (232)
    //         0050856c     POP        EDI
    //         0050856d     POP        ESI
    //         0050856e     POP        EBP
    //         0050856f     MOV        EAX,0x2
    //         00508574     POP        EBX
    //         00508575     RET        0x8
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_00508345::switchdataD_00508578                       XREF[1]:     processNotify:00508345(*)  
    //         00508578     addr       switchD_00508345::caseD_1f4
    //         0050857c     addr       switchD_00508345::caseD_1f5
    //         00508580     addr       switchD_00508345::caseD_258
    //         00508584     addr       switchD_00508345::caseD_2bb
    //         00508588     addr       switchD_00508345::caseD_1f5
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_00508345::switchdataD_0050858c                       XREF[1]:     processNotify:0050833f(*)  
    //         0050858c     db         0h
    //         0050858d     db         4h
    //         0050858e     db         4h
    //         0050858f     db         4h
    //         00508590     db         4h
    //         00508591     db         4h
    //         00508592     db         4h
    //         00508593     db         4h
    //         00508594     db         4h
    //         00508595     db         4h
    //         00508596     db         4h
    //         00508597     db         4h
    //         00508598     db         4h
    //         00508599     db         4h
    //         0050859a     db         4h
    //         0050859b     db         4h
    //         0050859c     db         4h
    //         0050859d     db         4h
    //         0050859e     db         4h
    //         0050859f     db         4h
    //         005085a0     db         4h
    //         005085a1     db         4h
    //         005085a2     db         4h
    //         005085a3     db         4h
    //         005085a4     db         4h
    //         005085a5     db         4h
    //         005085a6     db         4h
    //         005085a7     db         1h
    //         005085a8     db         4h
    //         005085a9     db         4h
    //         005085aa     db         4h
    //         005085ab     db         4h
    //         005085ac     db         4h
    //         005085ad     db         4h
    //         005085ae     db         4h
    //         005085af     db         4h
    //         005085b0     db         4h
    //         005085b1     db         4h
    //         005085b2     db         4h
    //         005085b3     db         4h
    //         005085b4     db         4h
    //         005085b5     db         4h
    //         005085b6     db         4h
    //         005085b7     db         4h
    //         005085b8     db         4h
    //         005085b9     db         4h
    //         005085ba     db         4h
    //         005085bb     db         4h
    //         005085bc     db         4h
    //         005085bd     db         4h
    //         005085be     db         4h
    //         005085bf     db         4h
    //         005085c0     db         4h
    //         005085c1     db         4h
    //         005085c2     db         4h
    //         005085c3     db         4h
    //         005085c4     db         4h
    //         005085c5     db         4h
    //         005085c6     db         4h
    //         005085c7     db         4h
    //         005085c8     db         4h
    //         005085c9     db         4h
    //         005085ca     db         4h
    //         005085cb     db         4h
    //         005085cc     db         4h
    //         005085cd     db         4h
    //         005085ce     db         4h
    //         005085cf     db         4h
    //         005085d0     db         4h
    //         005085d1     db         4h
    //         005085d2     db         4h
    //         005085d3     db         4h
    //         005085d4     db         4h
    //         005085d5     db         4h
    //         005085d6     db         4h
    //         005085d7     db         4h
    //         005085d8     db         4h
    //         005085d9     db         4h
    //         005085da     db         4h
    //         005085db     db         4h
    //         005085dc     db         4h
    //         005085dd     db         4h
    //         005085de     db         4h
    //         005085df     db         4h
    //         005085e0     db         4h
    //         005085e1     db         4h
    //         005085e2     db         4h
    //         005085e3     db         4h
    //         005085e4     db         4h
    //         005085e5     db         4h
    //         005085e6     db         4h
    //         005085e7     db         4h
    //         005085e8     db         4h
    //         005085e9     db         4h
    //         005085ea     db         4h
    //         005085eb     db         4h
    //         005085ec     db         4h
    //         005085ed     db         4h
    //         005085ee     db         4h
    //         005085ef     db         4h
    //         005085f0     db         2h
    //         005085f1     db         4h
    //         005085f2     db         4h
    //         005085f3     db         4h
    //         005085f4     db         4h
    //         005085f5     db         4h
    //         005085f6     db         4h
    //         005085f7     db         4h
    //         005085f8     db         4h
    //         005085f9     db         4h
    //         005085fa     db         4h
    //         005085fb     db         4h
    //         005085fc     db         4h
    //         005085fd     db         4h
    //         005085fe     db         4h
    //         005085ff     db         4h
    //         00508600     db         4h
    //         00508601     db         4h
    //         00508602     db         4h
    //         00508603     db         4h
    //         00508604     db         4h
    //         00508605     db         4h
    //         00508606     db         4h
    //         00508607     db         4h
    //         00508608     db         4h
    //         00508609     db         4h
    //         0050860a     db         4h
    //         0050860b     db         4h
    //         0050860c     db         4h
    //         0050860d     db         4h
    //         0050860e     db         4h
    //         0050860f     db         4h
    //         00508610     db         4h
    //         00508611     db         4h
    //         00508612     db         4h
    //         00508613     db         4h
    //         00508614     db         4h
    //         00508615     db         4h
    //         00508616     db         4h
    //         00508617     db         4h
    //         00508618     db         4h
    //         00508619     db         4h
    //         0050861a     db         4h
    //         0050861b     db         4h
    //         0050861c     db         4h
    //         0050861d     db         4h
    //         0050861e     db         4h
    //         0050861f     db         4h
    //         00508620     db         4h
    //         00508621     db         4h
    //         00508622     db         4h
    //         00508623     db         4h
    //         00508624     db         4h
    //         00508625     db         4h
    //         00508626     db         4h
    //         00508627     db         4h
    //         00508628     db         4h
    //         00508629     db         4h
    //         0050862a     db         4h
    //         0050862b     db         4h
    //         0050862c     db         4h
    //         0050862d     db         4h
    //         0050862e     db         4h
    //         0050862f     db         4h
    //         00508630     db         4h
    //         00508631     db         4h
    //         00508632     db         4h
    //         00508633     db         4h
    //         00508634     db         4h
    //         00508635     db         4h
    //         00508636     db         4h
    //         00508637     db         4h
    //         00508638     db         4h
    //         00508639     db         4h
    //         0050863a     db         4h
    //         0050863b     db         4h
    //         0050863c     db         4h
    //         0050863d     db         4h
    //         0050863e     db         4h
    //         0050863f     db         4h
    //         00508640     db         4h
    //         00508641     db         4h
    //         00508642     db         4h
    //         00508643     db         4h
    //         00508644     db         4h
    //         00508645     db         4h
    //         00508646     db         4h
    //         00508647     db         4h
    //         00508648     db         4h
    //         00508649     db         4h
    //         0050864a     db         4h
    //         0050864b     db         4h
    //         0050864c     db         4h
    //         0050864d     db         4h
    //         0050864e     db         4h
    //         0050864f     db         4h
    //         00508650     db         4h
    //         00508651     db         4h
    //         00508652     db         4h
    //         00508653     db         3h
    //         00508654     ??         90h
    //         00508655     ??         90h
    //         00508656     ??         90h
    //         00508657     ??         90h
    //         00508658     ??         90h
    //         00508659     ??         90h
    //         0050865a     ??         90h
    //         0050865b     ??         90h
    //         0050865c     ??         90h
    //         0050865d     ??         90h
    //         0050865e     ??         90h
    //         0050865f     ??         90h
}

int TribeBuildingUnitAIModule::processIdle(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall processIdle(TribeBuildingUnitAIModule * this, int par
    //              int               EAX:4          <RETURN>
    //              TribeBuildingU    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //                               ?processIdle@TribeBuildingUnitAIModule@@MAEHH@Z              XREF[1]:     00576524(*)  
    //                               TribeBuildingUnitAIModule::processIdle
    //                              taiuaimd.cpp:3120 (5)
    //         00508660     MOV        EAX,0x5
    //                              taiuaimd.cpp:3123 (3)
    //         00508665     RET        0x4
    //         00508668     ??         90h
    //         00508669     NOP
    //         0050866a     NOP
    //         0050866b     NOP
    //         0050866c     NOP
    //         0050866d     NOP
    //         0050866e     NOP
    //         0050866f     NOP
    return 0;
}

TribeHuntedAnimalUnitAIModule::TribeHuntedAnimalUnitAIModule(RGE_Static_Object* param_1, int param_2) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
}

int TribeHuntedAnimalUnitAIModule::processNotify(NotifyEvent* param_1, ulong param_2) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

TribePreditorUnitAIModule::TribePreditorUnitAIModule(RGE_Static_Object* param_1, int param_2) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
}

TribePreditorUnitAIModule::~TribePreditorUnitAIModule() {
    /* TODO: Stub */
    //                              void __thiscall ~TribePreditorUnitAIModule(TribePreditorUnitAIModule
    //              void              <VOID>         <RETURN>
    //              TribePreditorU    ECX:4 (auto)   this
    //                               ??1TribePreditorUnitAIModule@@UAE@XZ                         XREF[1]:     `vector_deleting_destructor':00504
    //                               TribePreditorUnitAIModule::~TribePreditorUnitAIModule
    //         00504090     JMP        UnitAIModule::~UnitAIModule
    //         00504095     ??         90h
    //         00504096     NOP
    //         00504097     NOP
    //         00504098     NOP
    //         00504099     NOP
    //         0050409a     NOP
    //         0050409b     NOP
    //         0050409c     NOP
    //         0050409d     NOP
    //         0050409e     NOP
    //         0050409f     NOP
}

int TribePreditorUnitAIModule::processNotify(NotifyEvent* param_1, ulong param_2) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

TribeElephantUnitAIModule::TribeElephantUnitAIModule(RGE_Static_Object* param_1, int param_2) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
}

int TribeElephantUnitAIModule::processNotify(NotifyEvent* param_1, ulong param_2) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

TribeLionUnitAIModule::~TribeLionUnitAIModule() {
    /* TODO: Stub */
    //                              void __thiscall ~TribeLionUnitAIModule(TribeLionUnitAIModule * this)
    //              void              <VOID>         <RETURN>
    //              TribeLionUnitA    ECX:4 (auto)   this
    //                               ??1TribeLionUnitAIModule@@UAE@XZ                             XREF[1]:     `vector_deleting_destructor':00504
    //                               TribeLionUnitAIModule::~TribeLionUnitAIModule
    //         00504460     JMP        UnitAIModule::~UnitAIModule
    //         00504465     ??         90h
    //         00504466     NOP
    //         00504467     NOP
    //         00504468     NOP
    //         00504469     NOP
    //         0050446a     NOP
    //         0050446b     NOP
    //         0050446c     NOP
    //         0050446d     NOP
    //         0050446e     NOP
    //         0050446f     NOP
}

int TribeLionUnitAIModule::processNotify(NotifyEvent* param_1, ulong param_2) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

int TribeRangedUnitAIModule::processNotify(NotifyEvent* param_1, ulong param_2) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

int TribeRangedUnitAIModule2::processNotify(NotifyEvent* param_1, ulong param_2) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

TribeCivilianUnitAIModule::TribeCivilianUnitAIModule(RGE_Static_Object* param_1, int param_2) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
}

TribeCivilianUnitAIModule::~TribeCivilianUnitAIModule() {
    /* TODO: Stub */
    //                              void __thiscall ~TribeCivilianUnitAIModule(TribeCivilianUnitAIModule
    //              void              <VOID>         <RETURN>
    //              TribeCivilianU    ECX:4 (auto)   this
    //                               ??1TribeCivilianUnitAIModule@@UAE@XZ                         XREF[1]:     `scalar_deleting_destructor':00504
    //                               TribeCivilianUnitAIModule::~TribeCivilianUnitAIModule
    //         00504c80     JMP        UnitAIModule::~UnitAIModule
    //         00504c85     ??         90h
    //         00504c86     NOP
    //         00504c87     NOP
    //         00504c88     NOP
    //         00504c89     NOP
    //         00504c8a     NOP
    //         00504c8b     NOP
    //         00504c8c     NOP
    //         00504c8d     NOP
    //         00504c8e     NOP
    //         00504c8f     NOP
}

int TribeCivilianUnitAIModule::processNotify(NotifyEvent* param_1, ulong param_2) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

TribePriestUnitAIModule::~TribePriestUnitAIModule() {
    /* TODO: Stub */
    //                              void __thiscall ~TribePriestUnitAIModule(TribePriestUnitAIModule * t
    //              void              <VOID>         <RETURN>
    //              TribePriestUni    ECX:4 (auto)   this
    //                               ??1TribePriestUnitAIModule@@UAE@XZ                           XREF[1]:     `vector_deleting_destructor':00505
    //                               TribePriestUnitAIModule::~TribePriestUnitAIModule
    //         00505990     JMP        UnitAIModule::~UnitAIModule
    //         00505995     ??         90h
    //         00505996     NOP
    //         00505997     NOP
    //         00505998     NOP
    //         00505999     NOP
    //         0050599a     NOP
    //         0050599b     NOP
    //         0050599c     NOP
    //         0050599d     NOP
    //         0050599e     NOP
    //         0050599f     NOP
}

int TribePriestUnitAIModule::processNotify(NotifyEvent* param_1, ulong param_2) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

TribeTradeShipUnitAIModule::TribeTradeShipUnitAIModule(RGE_Static_Object* param_1, int param_2) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
}

int TribeTradeShipUnitAIModule::processNotify(NotifyEvent* param_1, ulong param_2) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

TribeTransportShipUnitAIModule::TribeTransportShipUnitAIModule(RGE_Static_Object* param_1, int param_2) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
}

int TribeTransportShipUnitAIModule::processNotify(NotifyEvent* param_1, ulong param_2) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

TribeFishingShipUnitAIModule::TribeFishingShipUnitAIModule(RGE_Static_Object* param_1, int param_2) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
}

TribeFishingShipUnitAIModule::~TribeFishingShipUnitAIModule() {
    /* TODO: Stub */
    //                              void __thiscall ~TribeFishingShipUnitAIModule(TribeFishingShipUnitAI
    //              void              <VOID>         <RETURN>
    //              TribeFishingSh    ECX:4 (auto)   this
    //                               ??1TribeFishingShipUnitAIModule@@UAE@XZ                      XREF[1]:     `scalar_deleting_destructor':00506
    //                               TribeFishingShipUnitAIModule::~TribeFishingShipUnitAIModule
    //         00506c60     JMP        UnitAIModule::~UnitAIModule
    //         00506c65     ??         90h
    //         00506c66     NOP
    //         00506c67     NOP
    //         00506c68     NOP
    //         00506c69     NOP
    //         00506c6a     NOP
    //         00506c6b     NOP
    //         00506c6c     NOP
    //         00506c6d     NOP
    //         00506c6e     NOP
    //         00506c6f     NOP
}

int TribeFishingShipUnitAIModule::processNotify(NotifyEvent* param_1, ulong param_2) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

TribeSoldierUnitAIModule::~TribeSoldierUnitAIModule() {
    /* TODO: Stub */
    //                              void __thiscall ~TribeSoldierUnitAIModule(TribeSoldierUnitAIModule *
    //              void              <VOID>         <RETURN>
    //              TribeSoldierUn    ECX:4 (auto)   this
    //                               ??1TribeSoldierUnitAIModule@@UAE@XZ                          XREF[1]:     `scalar_deleting_destructor':00507
    //                               TribeSoldierUnitAIModule::~TribeSoldierUnitAIModule
    //         00507190     JMP        UnitAIModule::~UnitAIModule
    //         00507195     ??         90h
    //         00507196     NOP
    //         00507197     NOP
    //         00507198     NOP
    //         00507199     NOP
    //         0050719a     NOP
    //         0050719b     NOP
    //         0050719c     NOP
    //         0050719d     NOP
    //         0050719e     NOP
    //         0050719f     NOP
}

int TribeSoldierUnitAIModule::processNotify(NotifyEvent* param_1, ulong param_2) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

TribeArtifactUnitAIModule::TribeArtifactUnitAIModule(RGE_Static_Object* param_1, int param_2) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
}

int TribeArtifactUnitAIModule::processNotify(NotifyEvent* param_1, ulong param_2) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

TribeTowerUnitAIModule::~TribeTowerUnitAIModule() {
    /* TODO: Stub */
    //                              void __thiscall ~TribeTowerUnitAIModule(TribeTowerUnitAIModule * this)
    //              void              <VOID>         <RETURN>
    //              TribeTowerUnit    ECX:4 (auto)   this
    //                               ??1TribeTowerUnitAIModule@@UAE@XZ                            XREF[1]:     `scalar_deleting_destructor':00508
    //                               TribeTowerUnitAIModule::~TribeTowerUnitAIModule
    //         00508100     JMP        UnitAIModule::~UnitAIModule
    //         00508105     ??         90h
    //         00508106     NOP
    //         00508107     NOP
    //         00508108     NOP
    //         00508109     NOP
    //         0050810a     NOP
    //         0050810b     NOP
    //         0050810c     NOP
    //         0050810d     NOP
    //         0050810e     NOP
    //         0050810f     NOP
}

TribeBuildingUnitAIModule::TribeBuildingUnitAIModule(RGE_Static_Object* param_1, int param_2) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
}

int TribeBuildingUnitAIModule::processNotify(NotifyEvent* param_1, ulong param_2) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

