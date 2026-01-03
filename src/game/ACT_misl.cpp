#include "../common.h"
#include "ACT_misl.h"

RGE_Action_Missile::RGE_Action_Missile(int param_1, RGE_Action_Object* param_2) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Action_Missile(RGE_Action_Missile * this, i
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Action_Mis    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00404bcc(R)
//              RGE_Action_Obj    Stack[0x8]:4   param_2                   XREF[1]:     00404bc6(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00404be6(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00404c3b(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00404bd6(W)
//                               ??0RGE_Action_Missile@@QAE@HPAVRGE_Action_Object@@@Z         XREF[1]:     create_action:0040411f(c)
//                               RGE_Action_Missile::RGE_Action_Missile
//                              ACT_misl.cpp:30 (47)
//         00404bb0     PUSH       -0x1
//         00404bb2     PUSH       FUN_0055c2c8
//         00404bb7     MOV        EAX,FS:[0x0]
//         00404bbd     PUSH       EAX
//         00404bbe     MOV        dword ptr FS:[0x0],ESP
//         00404bc5     PUSH       this
//         00404bc6     MOV        EAX,dword ptr [ESP + param_2]
//         00404bca     PUSH       ESI
//         00404bcb     PUSH       EDI
//         00404bcc     MOV        EDI,dword ptr [ESP + param_1]
//         00404bd0     PUSH       0x1
//         00404bd2     MOV        ESI,this
//         00404bd4     PUSH       EAX
//         00404bd5     PUSH       EDI
//         00404bd6     MOV        dword ptr [ESP + local_10],ESI
//         00404bda     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, int p
//                              ACT_misl.cpp:33 (35)
//         00404bdf     LEA        this,[ESI + 0x40]
//         00404be2     PUSH       0x4
//         00404be4     PUSH       this
//         00404be5     PUSH       EDI
//         00404be6     MOV        dword ptr [ESP + local_4],0x0
//         00404bee     MOV        dword ptr [ESI],RGE_Action_Missile::`vftable'    = 00404c60
//         00404bf4     MOV        word ptr [ESI + 0x4],0x8
//         00404bfa     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00404bff     ADD        ESP,0xc
//                              ACT_misl.cpp:34 (15)
//         00404c02     LEA        EDX,[ESI + 0x44]
//         00404c05     PUSH       0x4
//         00404c07     PUSH       EDX
//         00404c08     PUSH       EDI
//         00404c09     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00404c0e     ADD        ESP,0xc
//                              ACT_misl.cpp:35 (15)
//         00404c11     LEA        EAX,[ESI + 0x48]
//         00404c14     PUSH       0x4
//         00404c16     PUSH       EAX
//         00404c17     PUSH       EDI
//         00404c18     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00404c1d     ADD        ESP,0xc
//                              ACT_misl.cpp:36 (15)
//         00404c20     LEA        this,[ESI + 0x4c]
//         00404c23     PUSH       0x4
//         00404c25     PUSH       this
//         00404c26     PUSH       EDI
//         00404c27     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         00404c2c     ADD        ESP,0xc
//                              ACT_misl.cpp:37 (12)
//         00404c2f     LEA        EDX,[ESI + 0x50]
//         00404c32     PUSH       0x4
//         00404c34     PUSH       EDX
//         00404c35     PUSH       EDI
//         00404c36     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              ACT_misl.cpp:38 (24)
//         00404c3b     MOV        this,dword ptr [ESP + local_c]
//         00404c3f     ADD        ESP,0xc
//         00404c42     MOV        EAX,ESI
//         00404c44     MOV        dword ptr FS:[0x0],this
//         00404c4b     POP        EDI
//         00404c4c     POP        ESI
//         00404c4d     ADD        ESP,0x10
//         00404c50     RET        0x8
//         00404c53     ??         90h
//         00404c54     NOP
//         00404c55     NOP
//         00404c56     NOP
//         00404c57     NOP
//         00404c58     NOP
//         00404c59     NOP
//         00404c5a     NOP
//         00404c5b     NOP
//         00404c5c     NOP
//         00404c5d     NOP
//         00404c5e     NOP
//         00404c5f     NOP
}

RGE_Action_Missile::RGE_Action_Missile(RGE_Action_Object* param_1, RGE_Static_Object* param_2, RGE_Static_Object* param_3, float param_4, float param_5, float param_6) {
    /* TODO: Stub */
//                              undefined __thiscall RGE_Action_Missile(RGE_Action_Missile * this, R
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_Action_Mis    ECX:4 (auto)   this
//              RGE_Action_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00404ca6(R)
//              RGE_Static_Obj    Stack[0x8]:4   param_2                   XREF[1]:     00404cee(R)
//              RGE_Static_Obj    Stack[0xc]:4   param_3                   XREF[1]:     00404cc8(R)
//              float             Stack[0x10]:4  param_4                   XREF[1]:     00404cb9(R)
//              float             Stack[0x14]:4  param_5                   XREF[1]:     00404cbd(R)
//              float             Stack[0x18]:4  param_6                   XREF[1]:     00404cc1(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00404ccc(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00404cfa(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00404cb0(W)
//                               ??0RGE_Action_Missile@@QAE@PAVRGE_Action_Object@@PAVRGE_Sta  XREF[2]:     init_missile:0045a99c(c),
//                               RGE_Action_Missile::RGE_Action_Missile                                    init_missile:0045aa2c(c)
//                              ACT_misl.cpp:44 (41)
//         00404c90     PUSH       -0x1
//         00404c92     PUSH       FUN_0055c2e8
//         00404c97     MOV        EAX,FS:[0x0]
//         00404c9d     PUSH       EAX
//         00404c9e     MOV        dword ptr FS:[0x0],ESP
//         00404ca5     PUSH       this
//         00404ca6     MOV        EAX,dword ptr [ESP + param_1]
//         00404caa     PUSH       ESI
//         00404cab     MOV        ESI,this
//         00404cad     PUSH       0x1
//         00404caf     PUSH       EAX
//         00404cb0     MOV        dword ptr [ESP + local_10],ESI
//         00404cb4     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, RGE_A
//                              ACT_misl.cpp:47 (4)
//         00404cb9     MOV        this,dword ptr [ESP + param_4]
//                              ACT_misl.cpp:48 (4)
//         00404cbd     MOV        EDX,dword ptr [ESP + param_5]
//                              ACT_misl.cpp:49 (7)
//         00404cc1     MOV        EAX,dword ptr [ESP + param_6]
//         00404cc5     MOV        dword ptr [ESI + 0x20],this
//                              ACT_misl.cpp:51 (38)
//         00404cc8     MOV        this,dword ptr [ESP + param_3]
//         00404ccc     MOV        dword ptr [ESP + local_4],0x0
//         00404cd4     PUSH       this
//         00404cd5     MOV        this,ESI
//         00404cd7     MOV        dword ptr [ESI],RGE_Action_Missile::`vftable'    = 00404c60
//         00404cdd     MOV        word ptr [ESI + 0x4],0x8
//         00404ce3     MOV        dword ptr [ESI + 0x24],EDX
//         00404ce6     MOV        dword ptr [ESI + 0x28],EAX
//         00404ce9     CALL       RGE_Action::set_target_obj                       void set_target_obj(RGE_Action * this, RGE_St
//                              ACT_misl.cpp:52 (12)
//         00404cee     MOV        EDX,dword ptr [ESP + param_2]
//         00404cf2     MOV        this,ESI
//         00404cf4     PUSH       EDX
//         00404cf5     CALL       RGE_Action::set_target_obj2                      void set_target_obj2(RGE_Action * this, RGE_S
//                              ACT_misl.cpp:53 (20)
//         00404cfa     MOV        this,dword ptr [ESP + local_c]
//         00404cfe     MOV        EAX,ESI
//         00404d00     MOV        dword ptr FS:[0x0],this
//         00404d07     POP        ESI
//         00404d08     ADD        ESP,0x10
//         00404d0b     RET        0x18
//         00404d0e     ??         90h
//         00404d0f     NOP
}

void RGE_Action_Missile::first_in_stack(uchar param_1) {
    /* TODO: Stub */
//                              void __thiscall first_in_stack(RGE_Action_Missile * this, uchar para
//              void              <VOID>         <RETURN>
//              RGE_Action_Mis    ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00404d10(R)
//                               ?first_in_stack@RGE_Action_Missile@@UAEXE@Z                  XREF[1]:     0056e33c(*)
//                               RGE_Action_Missile::first_in_stack
//                              ACT_misl.cpp:58 (8)
//         00404d10     MOV        AL,byte ptr [ESP + param_1]
//         00404d14     TEST       AL,AL
//         00404d16     JZ         LAB_00404d44
//                              ACT_misl.cpp:61 (24)
//         00404d18     MOV        EAX,dword ptr [ECX + this->_padding_]
//         00404d1b     TEST       EAX,EAX
//         00404d1d     JNZ        LAB_00404d3a
//         00404d1f     MOV        EDX,dword ptr [ECX + this->_padding_]
//         00404d22     MOV        EAX,0xbf800000
//         00404d27     CMP        EDX,EAX
//         00404d29     JZ         LAB_00404d30
//         00404d2b     CMP        dword ptr [ECX + this->_padding_],EAX
//         00404d2e     JNZ        LAB_00404d3a
//                               LAB_00404d30                                                 XREF[1]:     00404d29(j)
//                              ACT_misl.cpp:64 (4)
//         00404d30     MOV        EAX,dword ptr [this->_padding_]
//         00404d32     PUSH       0x1
//                              ACT_misl.cpp:67 (3)
//         00404d34     CALL       dword ptr [EAX + 0x5c]
//                              ACT_misl.cpp:68 (3)
//         00404d37     RET        0x4
//                               LAB_00404d3a                                                 XREF[2]:     00404d1d(j), 00404d2e(j)
//                              ACT_misl.cpp:62 (7)
//         00404d3a     MOV        EDX,dword ptr [this->_padding_]
//         00404d3c     PUSH       0x3
//         00404d3e     CALL       dword ptr [EDX + 0x5c]
//                              ACT_misl.cpp:68 (3)
//         00404d41     RET        0x4
//                               LAB_00404d44                                                 XREF[1]:     00404d16(j)
//                              ACT_misl.cpp:67 (7)
//         00404d44     MOV        EAX,dword ptr [this->_padding_]
//         00404d46     PUSH       0x4
//         00404d48     CALL       dword ptr [EAX + 0x5c]
//                              ACT_misl.cpp:68 (3)
//         00404d4b     RET        0x4
//         00404d4e     ??         90h
//         00404d4f     NOP
    return;
}

void RGE_Action_Missile::intercept(float* param_1, float* param_2, float* param_3) {
    /* TODO: Stub */
//                              void __thiscall intercept(RGE_Action_Missile * this, float * param_1
//              void              <VOID>         <RETURN>
//              RGE_Action_Mis    ECX:4 (auto)   this
//              float *           Stack[0x4]:4   param_1                   XREF[2]:     00404d57(R), 00404d78(R)
//              float *           Stack[0x8]:4   param_2                   XREF[2]:     00404d60(R), 00404d84(R)
//              float *           Stack[0xc]:4   param_3                   XREF[2]:     00404d6c(R), 00404d9c(R)
//                               ?intercept@RGE_Action_Missile@@IAEXAAM00@Z                   XREF[1]:     set_state:00404de3(c)
//                               RGE_Action_Missile::intercept
//                              ACT_misl.cpp:73 (7)
//         00404d50     MOV        EAX,dword ptr [ECX + this->_padding_]
//         00404d53     TEST       EAX,EAX
//         00404d55     JNZ        LAB_00404d75
//                              ACT_misl.cpp:76 (9)
//         00404d57     MOV        EDX,dword ptr [ESP + param_1]
//         00404d5b     MOV        EAX,dword ptr [ECX + this->_padding_]
//         00404d5e     MOV        dword ptr [EDX],EAX
//                              ACT_misl.cpp:77 (9)
//         00404d60     MOV        EDX,dword ptr [ESP + param_2]
//         00404d64     MOV        EAX,dword ptr [ECX + this->_padding_]
//         00404d67     MOV        dword ptr [EDX],EAX
//                              ACT_misl.cpp:78 (9)
//         00404d69     MOV        EAX,dword ptr [ECX + this->_padding_]
//         00404d6c     MOV        this,dword ptr [ESP + param_3]
//         00404d70     MOV        dword ptr [this->_padding_],EAX
//                              ACT_misl.cpp:86 (3)
//         00404d72     RET        0xc
//                               LAB_00404d75                                                 XREF[1]:     00404d55(j)
//                              ACT_misl.cpp:82 (9)
//         00404d75     MOV        EDX,dword ptr [EAX + 0x38]
//         00404d78     MOV        EAX,dword ptr [ESP + param_1]
//         00404d7c     MOV        dword ptr [EAX],EDX
//                              ACT_misl.cpp:83 (12)
//         00404d7e     MOV        EDX,dword ptr [ECX + this->_padding_]
//         00404d81     MOV        EAX,dword ptr [EDX + 0x3c]
//         00404d84     MOV        EDX,dword ptr [ESP + param_2]
//         00404d88     MOV        dword ptr [EDX],EAX
//                              ACT_misl.cpp:84 (24)
//         00404d8a     MOV        this,dword ptr [ECX + this->_padding_]
//         00404d8d     MOV        EAX,dword ptr [ECX + this->_padding_]
//         00404d90     FLD        float ptr [EAX + 0x38]
//         00404d93     FMUL       float ptr [DAT_0056e380]                         = align(3)
//         00404d99     FADD       float ptr [ECX + this->velocity_x]
//         00404d9c     MOV        this,dword ptr [ESP + param_3]
//         00404da0     FSTP       float ptr [this->_padding_]
//                              ACT_misl.cpp:86 (3)
//         00404da2     RET        0xc
//         00404da5     ??         90h
//         00404da6     NOP
//         00404da7     NOP
//         00404da8     NOP
//         00404da9     NOP
//         00404daa     NOP
//         00404dab     NOP
//         00404dac     NOP
//         00404dad     NOP
//         00404dae     NOP
//         00404daf     NOP
    return;
}

void RGE_Action_Missile::set_state(uchar param_1) {
    /* TODO: Stub */
//                              void __thiscall set_state(RGE_Action_Missile * this, uchar param_1)
//              void              <VOID>         <RETURN>
//              RGE_Action_Mis    ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[3]:     00404db0(R), 00404e0e(W), 00404e20(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00404dd2(*), 00404df0(R)
//              float             Stack[-0x8]:4  tz                        XREF[2]:     00404dd6(*), 00404dec(R)
//              float             Stack[-0xc]:4  ty                        XREF[2]:     00404ddb(*), 00404de8(R)
//              float             Stack[-0x10]:4 tx
//              float             Stack[-0x14]:4 target_vy
//              float             Stack[-0x18]:4 target_vx                 XREF[2]:     00404e33(W), 00404e37(R)
//              undefined4        Stack[-0x1c]:4 local_1c                  XREF[2]:     00404e1a(W), 00404e26(R)
//              float             Stack[-0x20]:4 dz
//              float             Stack[-0x24]:4 speed                     XREF[1]:     00404e44(W)
//              float             Stack[-0x28]:4 d                         XREF[2]:     00404e08(W), 00404e14(R)
//              float             Stack[-0x2c]:4 dx
//                               ?set_state@RGE_Action_Missile@@MAEXE@Z                       XREF[1]:     0056e37c(*)
//                               RGE_Action_Missile::set_state
//                              ACT_misl.cpp:91 (13)
//         00404db0     MOV        EAX,dword ptr [ESP + param_1]
//         00404db4     SUB        ESP,0x28
//         00404db7     PUSH       ESI
//         00404db8     MOV        ESI,this
//         00404dba     MOV        byte ptr [ESI + 0xc],AL
//                              ACT_misl.cpp:104 (21)
//         00404dbd     AND        EAX,0xff
//         00404dc2     DEC        EAX
//         00404dc3     JZ         LAB_004050c6
//         00404dc9     SUB        EAX,0x2
//         00404dcc     JNZ        LAB_004050ce
//                              ACT_misl.cpp:107 (22)
//         00404dd2     LEA        EAX=>local_4,[ESP + 0x28]
//         00404dd6     LEA        this=>tz,[ESP + 0x24]
//         00404dda     PUSH       EAX
//         00404ddb     LEA        EDX=>ty,[ESP + 0x24]
//         00404ddf     PUSH       this
//         00404de0     PUSH       EDX
//         00404de1     MOV        this,ESI
//         00404de3     CALL       RGE_Action_Missile::intercept                    void intercept(RGE_Action_Missile * this, flo
//                              ACT_misl.cpp:108 (4)
//         00404de8     FLD        float ptr [ESP + ty]
//                              ACT_misl.cpp:109 (4)
//         00404dec     FLD        float ptr [ESP + tz]
//                              ACT_misl.cpp:110 (24)
//         00404df0     FLD        float ptr [ESP + local_4]
//         00404df4     FXCH       ST2
//         00404df6     MOV        EAX,dword ptr [ESI + 0x8]
//         00404df9     FSUB       float ptr [EAX + 0x38]
//         00404dfc     FXCH
//         00404dfe     FSUB       float ptr [EAX + 0x3c]
//         00404e01     FXCH       ST2
//         00404e03     FSUB       float ptr [EAX + 0x40]
//         00404e06     FXCH
//                              ACT_misl.cpp:114 (106)
//         00404e08     FST        float ptr [ESP + d]
//         00404e0c     FXCH       ST2
//         00404e0e     FST        float ptr [ESP + param_1]
//         00404e12     FXCH       ST2
//         00404e14     FMUL       float ptr [ESP + d]
//         00404e18     FXCH
//         00404e1a     FST        float ptr [ESP + local_1c]
//         00404e1e     FXCH       ST2
//         00404e20     FMUL       float ptr [ESP + param_1]
//         00404e24     FXCH       ST2
//         00404e26     FMUL       float ptr [ESP + local_1c]
//         00404e2a     FXCH       ST2
//         00404e2c     FADDP
//         00404e2e     FXCH
//         00404e30     MOV        EAX,dword ptr [EAX + 0x8]
//         00404e33     FSTP       float ptr [ESP + target_vx]
//         00404e37     FADD       float ptr [ESP + target_vx]
//         00404e3b     CMP        byte ptr [EAX + 0x149],0x1
//         00404e42     FSQRT
//         00404e44     FSTP       float ptr [ESP + speed]
//         00404e48     JNZ        LAB_00404f87
//         00404e4e     MOV        this,dword ptr [ESI + 0x10]
//         00404e51     TEST       this,this
//         00404e53     JZ         LAB_00404f87
//         00404e59     MOV        EDX,dword ptr [this->_padding_]
//         00404e5b     CALL       dword ptr [EDX + 0xf4]
//         00404e61     FCOMP      double ptr [DAT_0056e388]
//         00404e67     FNSTSW     AX
//         00404e69     TEST       AH,0x41
//         00404e6c     JNZ        LAB_00404f87
//                              ACT_misl.cpp:124 (11)
//         00404e72     MOV        this,dword ptr [ESI + 0x10]
//         00404e75     MOV        EAX,dword ptr [this->_padding_]
//         00404e77     CALL       dword ptr [EAX + 0xf4]
//                              ACT_misl.cpp:127 (36)
//         00404e7d     MOV        EAX,dword ptr [ESI + 0x14]
//         00404e80     FSTP       float ptr [ESP + 0xc]
//         00404e84     TEST       EAX,EAX
//         00404e86     JZ         LAB_00404eba
//         00404e88     MOV        this,dword ptr [EAX + 0x8]
//         00404e8b     MOV        AX,word ptr [ECX + this->_padding_]
//         00404e8f     CMP        AX,0x23
//         00404e93     JZ         LAB_00404ea1
//         00404e95     CMP        AX,0x24
//         00404e99     JZ         LAB_00404ea1
//         00404e9b     CMP        AX,0x118
//         00404e9f     JNZ        LAB_00404eba
//                               LAB_00404ea1                                                 XREF[2]:     00404e93(j), 00404e99(j)
//                              ACT_misl.cpp:128 (17)
//         00404ea1     FLD        float ptr [ESP + 0xc]
//         00404ea5     FCOMP      float ptr [DAT_0056e390]
//         00404eab     FNSTSW     AX
//         00404ead     TEST       AH,0x41
//         00404eb0     JNZ        LAB_00404eba
//                              ACT_misl.cpp:129 (8)
//         00404eb2     MOV        dword ptr [ESP + 0xc],0x3f800000
//                               LAB_00404eba                                                 XREF[3]:     00404e86(j), 00404e9f(j),
//                                                                                                         00404eb0(j)
//                              ACT_misl.cpp:131 (13)
//         00404eba     MOV        this,dword ptr [ESI + 0x10]
//         00404ebd     MOV        EDX,dword ptr [this->_padding_]
//         00404ebf     CALL       dword ptr [EDX + 0xf8]
//         00404ec5     FCOS
//                              ACT_misl.cpp:132 (21)
//         00404ec7     MOV        this,dword ptr [ESI + 0x10]
//         00404eca     MOV        EAX,dword ptr [this->_padding_]
//         00404ecc     FMUL       float ptr [ESP + 0xc]
//         00404ed0     FSTP       float ptr [ESP + 0x18]
//         00404ed4     CALL       dword ptr [EAX + 0xf8]
//         00404eda     FSIN
//                              ACT_misl.cpp:137 (48)
//         00404edc     MOV        this,dword ptr [ESI + 0x8]
//         00404edf     MOV        EAX,dword ptr [ECX + this->_padding_]
//         00404ee2     FMUL       float ptr [ESP + 0xc]
//         00404ee6     FLD        float ptr [ESP + 0x18]
//         00404eea     FADD       float ptr [ESP + 0x4]
//         00404eee     FXCH
//         00404ef0     FST        float ptr [ESP + 0x1c]
//         00404ef4     FADD       float ptr [ESP + 0x30]
//         00404ef8     FXCH
//         00404efa     FST        float ptr [ESP + 0xc]
//         00404efe     FMUL       float ptr [ESP + 0xc]
//         00404f02     FXCH
//         00404f04     FST        float ptr [ESP + 0xc]
//         00404f08     FMUL       float ptr [ESP + 0xc]
//                              ACT_misl.cpp:138 (55)
//         00404f0c     FLD        float ptr [EAX + 0xb8]
//         00404f12     FMUL       float ptr [DAT_0056e380]                         = align(3)
//         00404f18     FXCH
//         00404f1a     FADDP      ST2,ST0
//         00404f1c     FXCH
//         00404f1e     FADD       float ptr [ESP + 0x14]
//         00404f22     FSQRT
//         00404f24     FST        float ptr [ESP + 0xc]
//         00404f28     FSUBR      float ptr [ESP + 0x8]
//         00404f2c     FST        float ptr [ESP + 0xc]
//         00404f30     FADD       float ptr [EAX + 0xb8]
//         00404f36     FST        float ptr [ESP + 0xc]
//         00404f3a     FCOMPP
//         00404f3c     FNSTSW     AX
//         00404f3e     TEST       AH,0x41
//         00404f41     JNZ        LAB_00404f87
//                              ACT_misl.cpp:140 (8)
//         00404f43     FLD        float ptr [ESP + 0x8]
//         00404f47     FDIV       float ptr [ESP + 0xc]
//                              ACT_misl.cpp:141 (2)
//         00404f4b     FLD        ST0
//                              ACT_misl.cpp:142 (30)
//         00404f4d     FMUL       float ptr [ESP + 0x18]
//         00404f51     FXCH
//         00404f53     FMUL       float ptr [ESP + 0x1c]
//         00404f57     FXCH
//         00404f59     FADD       float ptr [ESP + 0x4]
//         00404f5d     FXCH
//         00404f5f     FADD       float ptr [ESP + 0x30]
//         00404f63     FXCH
//         00404f65     FST        float ptr [ESP + 0x4]
//         00404f69     FXCH
//                              ACT_misl.cpp:143 (28)
//         00404f6b     FST        float ptr [ESP + 0x30]
//         00404f6f     FXCH
//         00404f71     FMUL       float ptr [ESP + 0x4]
//         00404f75     FXCH
//         00404f77     FMUL       float ptr [ESP + 0x30]
//         00404f7b     FADDP
//         00404f7d     FADD       float ptr [ESP + 0x14]
//         00404f81     FSQRT
//         00404f83     FSTP       float ptr [ESP + 0x8]
//                               LAB_00404f87                                                 XREF[4]:     00404e48(j), 00404e53(j),
//                                                                                                         00404e6c(j), 00404f41(j)
//                              ACT_misl.cpp:148 (30)
//         00404f87     MOV        this,dword ptr [ESI + 0x8]
//         00404f8a     XOR        EAX,EAX
//         00404f8c     MOV        EDX,dword ptr [ECX + this->_padding_]
//         00404f8f     MOV        AL,byte ptr [EDX + 0x148]
//         00404f95     CMP        EAX,0x3
//         00404f98     JA         switchD_00404f9e::default
//                               switchD_00404f9e::switchD
//         00404f9e     JMP        dword ptr [EAX*0x4 + switchD_00404f9e::switchd   = 00404fa5
//                               switchD_00404f9e::caseD_0                                    XREF[2]:     00404f9e(j), 004050d8(*)
//                              ACT_misl.cpp:152 (8)
//         00404fa5     FLD        float ptr [ESP + 0x4]
//         00404fa9     FDIV       float ptr [ESP + 0x8]
//                              ACT_misl.cpp:155 (41)
//         00404fad     MOV        EAX,dword ptr [this->_padding_]
//         00404faf     PUSH       this
//         00404fb0     FST        float ptr [ESI + 0x40]
//         00404fb3     FLD        float ptr [ESP + 0x34]
//         00404fb7     FDIV       float ptr [ESP + 0xc]
//         00404fbb     FST        float ptr [ESI + 0x44]
//         00404fbe     FLD        float ptr [ESP + 0x14]
//         00404fc2     FDIV       float ptr [ESP + 0xc]
//         00404fc6     FSTP       float ptr [ESI + 0x48]
//         00404fc9     FXCH
//         00404fcb     FPATAN
//         00404fcd     FSTP       float ptr [ESP]
//         00404fd0     CALL       dword ptr [EAX + 0xb4]
//                              ACT_misl.cpp:156 (7)
//         00404fd6     MOV        dword ptr [ESI + 0x2c],0x0
//                              ACT_misl.cpp:157 (2)
//         00404fdd     JMP        switchD_00404f9e::default
//                               switchD_00404f9e::caseD_1                                    XREF[2]:     00404f9e(j), 004050dc(*)
//                              ACT_misl.cpp:161 (9)
//         00404fdf     MOV        EDX,dword ptr [ESI]
//         00404fe1     PUSH       0x4
//         00404fe3     MOV        this,ESI
//         00404fe5     CALL       dword ptr [EDX + 0x5c]
//                              ACT_misl.cpp:162 (2)
//         00404fe8     JMP        switchD_00404f9e::default
//                               switchD_00404f9e::caseD_2                                    XREF[2]:     00404f9e(j), 004050e0(*)
//                              ACT_misl.cpp:166 (9)
//         00404fea     MOV        EAX,dword ptr [ESI]
//         00404fec     PUSH       0x4
//         00404fee     MOV        this,ESI
//         00404ff0     CALL       dword ptr [EAX + 0x5c]
//                              ACT_misl.cpp:167 (2)
//         00404ff3     JMP        switchD_00404f9e::default
//                               switchD_00404f9e::caseD_3                                    XREF[2]:     00404f9e(j), 004050e4(*)
//                              ACT_misl.cpp:172 (43)
//         00404ff5     FLD        float ptr [ESP + 0x30]
//         00404ff9     FLD        float ptr [ESP + 0x4]
//         00404ffd     FPATAN
//         00404fff     MOV        EDX,dword ptr [ESP + 0x4]
//         00405003     MOV        EAX,dword ptr [ESP + 0x30]
//         00405007     MOV        dword ptr [ESI + 0x40],EDX
//         0040500a     MOV        EDX,dword ptr [ESP + 0x10]
//         0040500e     MOV        dword ptr [ESI + 0x44],EAX
//         00405011     MOV        EAX,dword ptr [this->_padding_]
//         00405013     PUSH       this
//         00405014     MOV        dword ptr [ESI + 0x48],EDX
//         00405017     FSTP       float ptr [ESP]
//         0040501a     CALL       dword ptr [EAX + 0xb4]
//                               switchD_00404f9e::default                                    XREF[4]:     00404f98(j), 00404fdd(j),
//                                                                                                         00404fe8(j), 00404ff3(j)
//                              ACT_misl.cpp:177 (25)
//         00405020     MOV        this,dword ptr [ESI + 0x8]
//         00405023     MOV        this,dword ptr [ECX + this->_padding_]
//         00405026     FLD        float ptr [this->_padding_ + 0x150]
//         0040502c     FCOMP      double ptr [DAT_0056e388]
//         00405032     FNSTSW     AX
//         00405034     TEST       AH,0x41
//         00405037     JNZ        LAB_004050a8
//                              ACT_misl.cpp:179 (19)
//         00405039     FLD        float ptr [this->_padding_ + 0xb8]
//         0040503f     FCOMP      float ptr [DAT_0056e394]
//         00405045     FNSTSW     AX
//         00405047     TEST       AH,0x41
//         0040504a     JNZ        LAB_00405058
//                              ACT_misl.cpp:180 (10)
//         0040504c     FLD        float ptr [ESP + 0x8]
//         00405050     FDIV       float ptr [this->_padding_ + 0xb8]
//                              ACT_misl.cpp:181 (2)
//         00405056     JMP        LAB_0040505e
//                               LAB_00405058                                                 XREF[1]:     0040504a(j)
//                              ACT_misl.cpp:182 (6)
//         00405058     FLD        float ptr [DAT_0056e394]
//                               LAB_0040505e                                                 XREF[1]:     00405056(j)
//                              ACT_misl.cpp:185 (30)
//         0040505e     FLD        float ptr [ESP + 0x8]
//         00405062     FXCH
//         00405064     FMUL       float ptr [DAT_0056e380]                         = align(3)
//         0040506a     FXCH
//         0040506c     FMUL       float ptr [this->_padding_ + 0x150]
//         00405072     FLD        ST1
//         00405074     FMUL       ST2
//         00405076     FXCH
//         00405078     FCHS
//         0040507a     FADD       ST0,ST0
//                              ACT_misl.cpp:186 (4)
//         0040507c     FXCH
//         0040507e     FDIVP
//                              ACT_misl.cpp:193 (33)
//         00405080     MOV        EDX,dword ptr [ESI]
//         00405082     PUSH       0x4
//         00405084     MOV        this,ESI
//         00405086     FSTP       float ptr [ESP + 0x34]
//         0040508a     FMUL       float ptr [ESP + 0x34]
//         0040508e     FLD        float ptr [ESP + 0x34]
//         00405092     FXCH
//         00405094     FCHS
//         00405096     FXCH
//         00405098     FSTP       float ptr [ESI + 0x50]
//         0040509b     FSTP       float ptr [ESI + 0x4c]
//         0040509e     CALL       dword ptr [EDX + 0x5c]
//                              ACT_misl.cpp:200 (7)
//         004050a1     POP        ESI
//         004050a2     ADD        ESP,0x28
//         004050a5     RET        0x4
//                               LAB_004050a8                                                 XREF[1]:     00405037(j)
//                              ACT_misl.cpp:193 (23)
//         004050a8     MOV        EDX,dword ptr [ESI]
//         004050aa     PUSH       0x4
//         004050ac     MOV        this,ESI
//         004050ae     MOV        dword ptr [ESI + 0x4c],0x0
//         004050b5     MOV        dword ptr [ESI + 0x50],0x0
//         004050bc     CALL       dword ptr [EDX + 0x5c]
//                              ACT_misl.cpp:200 (7)
//         004050bf     POP        ESI
//         004050c0     ADD        ESP,0x28
//         004050c3     RET        0x4
//                               LAB_004050c6                                                 XREF[1]:     00404dc3(j)
//                              ACT_misl.cpp:197 (8)
//         004050c6     MOV        this,dword ptr [ESI + 0x8]
//         004050c9     MOV        EAX,dword ptr [this->_padding_]
//         004050cb     CALL       dword ptr [EAX + 0x6c]
//                               LAB_004050ce                                                 XREF[1]:     00404dcc(j)
//                              ACT_misl.cpp:200 (26)
//         004050ce     POP        ESI
//         004050cf     ADD        ESP,0x28
//         004050d2     RET        0x4
    return;
}

uchar RGE_Action_Missile::update() {
    /* TODO: Stub */
//                              uchar __thiscall update(RGE_Action_Missile * this)
//              uchar             AL:1           <RETURN>
//              RGE_Action_Mis    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004050f9(W)
//              RGE_Check_List    Stack[-0x8]:4  bounds                    XREF[1]:     0040510a(W)
//              float             Stack[-0xc]:4  vy                        XREF[2]:     0040512f(W), 00405133(R)
//              float             Stack[-0x10]:4 t                         XREF[1]:     00405137(W)
//              float             Stack[-0x14]:4 s                         XREF[1]:     00405118(W)
//              float             Stack[-0x18]:4 vz
//              uchar             Stack[-0x19]:1 hit_ground
//                               ?update@RGE_Action_Missile@@UAEEXZ                           XREF[1]:     0056e348(*)
//                               RGE_Action_Missile::update
//                              ACT_misl.cpp:205 (9)
//         004050f0     SUB        ESP,0x18
//         004050f3     PUSH       EBX
//         004050f4     PUSH       EBP
//         004050f5     PUSH       ESI
//         004050f6     MOV        ESI,this
//         004050f8     PUSH       EDI
//                              ACT_misl.cpp:216 (78)
//         004050f9     MOV        dword ptr [ESP + local_4],0x0
//         00405101     MOV        EAX,dword ptr [ESI + 0x8]
//         00405104     MOV        EDX,dword ptr [ESI + 0x18]
//         00405107     CMP        EDX,-0x1
//         0040510a     MOV        dword ptr [ESP + bounds],0x0
//         00405112     MOV        this,dword ptr [EAX + 0xc]
//         00405115     MOV        EAX,dword ptr [EAX + 0x8]
//         00405118     MOV        dword ptr [ESP + s],0x0
//         00405120     MOV        this,dword ptr [ECX + this->_padding_]
//         00405123     FLD        float ptr [EAX + 0xb8]
//         00405129     MOV        EDI,dword ptr [this->_padding_ + 0x84]
//         0040512f     MOV        dword ptr [ESP + vy],EDI
//         00405133     FMUL       float ptr [ESP + vy]
//         00405137     FSTP       float ptr [ESP + t]
//         0040513b     JZ         LAB_0040514f
//         0040513d     PUSH       EDX
//         0040513e     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
//         00405143     TEST       EAX,EAX
//         00405145     JNZ        LAB_0040514f
//                              ACT_misl.cpp:217 (8)
//         00405147     MOV        EDX,dword ptr [ESI]
//         00405149     PUSH       EAX
//         0040514a     MOV        this,ESI
//         0040514c     CALL       dword ptr [EDX + 0x54]
//                               LAB_0040514f                                                 XREF[2]:     0040513b(j), 00405145(j)
//                              ACT_misl.cpp:218 (27)
//         0040514f     MOV        EAX,dword ptr [ESI + 0x1c]
//         00405152     CMP        EAX,-0x1
//         00405155     JZ         LAB_00405172
//         00405157     PUSH       EAX
//         00405158     MOV        EAX,dword ptr [ESI + 0x8]
//         0040515b     MOV        this,dword ptr [EAX + 0xc]
//         0040515e     MOV        this,dword ptr [ECX + this->_padding_]
//         00405161     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
//         00405166     TEST       EAX,EAX
//         00405168     JNZ        LAB_00405172
//                              ACT_misl.cpp:219 (8)
//         0040516a     MOV        EDX,dword ptr [ESI]
//         0040516c     PUSH       EAX
//         0040516d     MOV        this,ESI
//         0040516f     CALL       dword ptr [EDX + 0x58]
//                               LAB_00405172                                                 XREF[2]:     00405155(j), 00405168(j)
//                              ACT_misl.cpp:222 (16)
//         00405172     MOV        this,dword ptr [ESI + 0x10]
//         00405175     TEST       this,this
//         00405177     JZ         LAB_0040518b
//         00405179     CALL       RGE_Static_Object::is_dying                      uchar is_dying(RGE_Static_Object * this)
//         0040517e     TEST       AL,AL
//         00405180     JZ         LAB_0040518b
//                              ACT_misl.cpp:223 (9)
//         00405182     MOV        EAX,dword ptr [ESI]
//         00405184     PUSH       0x0
//         00405186     MOV        this,ESI
//         00405188     CALL       dword ptr [EAX + 0x54]
//                               LAB_0040518b                                                 XREF[2]:     00405177(j), 00405180(j)
//                              ACT_misl.cpp:224 (16)
//         0040518b     MOV        this,dword ptr [ESI + 0x14]
//         0040518e     TEST       this,this
//         00405190     JZ         LAB_004051a4
//         00405192     CALL       RGE_Static_Object::is_dying                      uchar is_dying(RGE_Static_Object * this)
//         00405197     TEST       AL,AL
//         00405199     JZ         LAB_004051a4
//                              ACT_misl.cpp:225 (9)
//         0040519b     MOV        EDX,dword ptr [ESI]
//         0040519d     PUSH       0x0
//         0040519f     MOV        this,ESI
//         004051a1     CALL       dword ptr [EDX + 0x58]
//                               LAB_004051a4                                                 XREF[2]:     00405190(j), 00405199(j)
//                              ACT_misl.cpp:227 (21)
//         004051a4     XOR        EAX,EAX
//         004051a6     MOV        AL,byte ptr [ESI + 0xc]
//         004051a9     DEC        EAX
//         004051aa     JZ         LAB_004054a1
//         004051b0     SUB        EAX,0x3
//         004051b3     JNZ        LAB_00405497
//                              ACT_misl.cpp:231 (21)
//         004051b9     MOV        EAX,dword ptr [ESI + 0x8]
//         004051bc     MOV        this,dword ptr [EAX + 0x8]
//         004051bf     MOV        this,byte ptr [this->_padding_ + 0x148]
//         004051c5     TEST       this,this
//         004051c7     JZ         LAB_004051e5
//         004051c9     CMP        this,0x3
//         004051cc     JNZ        LAB_00405234
//                              ACT_misl.cpp:249 (3)
//         004051ce     MOV        EDX,dword ptr [ESI + 0x40]
//                              ACT_misl.cpp:250 (3)
//         004051d1     MOV        EAX,dword ptr [ESI + 0x44]
//                              ACT_misl.cpp:251 (15)
//         004051d4     MOV        this,dword ptr [ESI + 0x48]
//         004051d7     MOV        dword ptr [ESP + 0x24],EDX
//         004051db     MOV        dword ptr [ESP + 0x20],EAX
//         004051df     MOV        dword ptr [ESP + 0x14],this
//                              ACT_misl.cpp:252 (2)
//         004051e3     JMP        LAB_00405234
//                               LAB_004051e5                                                 XREF[1]:     004051c7(j)
//                              ACT_misl.cpp:238 (18)
//         004051e5     FLD        float ptr [ESP + 0x18]
//         004051e9     FADD       float ptr [ESI + 0x2c]
//         004051ec     FLD        float ptr [ESI + 0x40]
//         004051ef     FLD        float ptr [ESI + 0x44]
//         004051f2     FLD        float ptr [ESI + 0x48]
//         004051f5     FLD        ST3
//                              ACT_misl.cpp:239 (52)
//         004051f7     FSTP       float ptr [ESI + 0x2c]
//         004051fa     FXCH       ST3
//         004051fc     FCOMP      float ptr [EAX + 0x1c4]
//         00405202     FXCH
//         00405204     FMUL       float ptr [ESP + 0x18]
//         00405208     FXCH
//         0040520a     FMUL       float ptr [ESP + 0x18]
//         0040520e     FXCH       ST2
//         00405210     FMUL       float ptr [ESP + 0x18]
//         00405214     FXCH
//         00405216     FSTP       float ptr [ESP + 0x24]
//         0040521a     FXCH
//         0040521c     FSTP       float ptr [ESP + 0x20]
//         00405220     FNSTSW     AX
//         00405222     FSTP       float ptr [ESP + 0x14]
//         00405226     TEST       AH,0x1
//         00405229     JNZ        LAB_00405234
//                              ACT_misl.cpp:240 (9)
//         0040522b     MOV        EDX,dword ptr [ESI]
//         0040522d     PUSH       0x1
//         0040522f     MOV        this,ESI
//         00405231     CALL       dword ptr [EDX + 0x5c]
//                               LAB_00405234                                                 XREF[3]:     004051cc(j), 004051e3(j),
//                                                                                                         00405229(j)
//                              ACT_misl.cpp:255 (25)
//         00405234     MOV        this,dword ptr [ESI + 0x8]
//         00405237     MOV        EAX,dword ptr [ECX + this->_padding_]
//         0040523a     FLD        float ptr [EAX + 0x150]
//         00405240     FCOMP      double ptr [DAT_0056e388]
//         00405246     FNSTSW     AX
//         00405248     TEST       AH,0x41
//         0040524b     JNZ        LAB_00405277
//                              ACT_misl.cpp:257 (15)
//         0040524d     FLD        float ptr [ESI + 0x50]
//         00405250     FMUL       float ptr [ESP + 0x1c]
//         00405254     FLD        ST0
//         00405256     FMUL       float ptr [DAT_0056e380]                         = align(3)
//                              ACT_misl.cpp:258 (27)
//         0040525c     FXCH
//         0040525e     FADD       float ptr [ESI + 0x4c]
//         00405261     FXCH
//         00405263     FADD       float ptr [ESI + 0x4c]
//         00405266     FXCH
//         00405268     FSTP       float ptr [ESI + 0x4c]
//         0040526b     FMUL       float ptr [ESP + 0x1c]
//         0040526f     FADD       float ptr [ESP + 0x14]
//         00405273     FSTP       float ptr [ESP + 0x14]
//                               LAB_00405277                                                 XREF[1]:     0040524b(j)
//                              ACT_misl.cpp:261 (20)
//         00405277     MOV        EDX,dword ptr [ESP + 0x14]
//         0040527b     MOV        EAX,dword ptr [ESP + 0x20]
//         0040527f     PUSH       EDX
//         00405280     MOV        EDX,dword ptr [ESP + 0x28]
//         00405284     PUSH       EAX
//         00405285     PUSH       EDX
//         00405286     CALL       RGE_Moving_Object::set_velocity                  void set_velocity(RGE_Moving_Object * this, f
//                              ACT_misl.cpp:264 (8)
//         0040528b     MOV        this,dword ptr [ESI + 0x8]
//         0040528e     CALL       RGE_Missile_Object::missile_move                 uchar missile_move(RGE_Missile_Object * this)
//                              ACT_misl.cpp:267 (28)
//         00405293     MOV        this,dword ptr [ESI + 0x8]
//         00405296     MOV        byte ptr [ESP + 0x13],AL
//         0040529a     MOV        EAX,dword ptr [ECX + this->_padding_]
//         0040529d     MOV        AL,byte ptr [EAX + 0x148]
//         004052a3     CMP        AL,0x2
//         004052a5     JBE        LAB_00405306
//         004052a7     CMP        AL,0x3
//         004052a9     JNZ        LAB_0040544a
//                              ACT_misl.cpp:328 (7)
//         004052af     MOV        EAX,dword ptr [ESI + 0x14]
//         004052b2     TEST       EAX,EAX
//         004052b4     JZ         LAB_004052df
//                              ACT_misl.cpp:329 (21)
//         004052b6     MOV        EDI,dword ptr [ECX + this->velocity_x]
//         004052b9     MOV        EDX,dword ptr [EAX]
//         004052bb     PUSH       EDI
//         004052bc     MOV        EDI,dword ptr [ECX + this->_padding_]
//         004052bf     MOV        this,dword ptr [ECX + this->_padding_]
//         004052c2     PUSH       EDI
//         004052c3     PUSH       this
//         004052c4     MOV        this,dword ptr [ESI + 0x10]
//         004052c7     PUSH       EAX
//         004052c8     PUSH       this
//         004052c9     MOV        this,EAX
//                              ACT_misl.cpp:331 (6)
//         004052cb     CALL       dword ptr [EDX + 0x228]
//                              ACT_misl.cpp:332 (9)
//         004052d1     MOV        EDX,dword ptr [ESI]
//         004052d3     PUSH       0x1
//         004052d5     MOV        this,ESI
//         004052d7     CALL       dword ptr [EDX + 0x5c]
//                              ACT_misl.cpp:333 (5)
//         004052da     JMP        LAB_0040544a
//                               LAB_004052df                                                 XREF[1]:     004052b4(j)
//                              ACT_misl.cpp:331 (25)
//         004052df     MOV        EAX,dword ptr [ECX + this->velocity_x]
//         004052e2     MOV        EDX,dword ptr [this->_padding_]
//         004052e4     PUSH       EAX
//         004052e5     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004052e8     PUSH       EAX
//         004052e9     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004052ec     PUSH       EAX
//         004052ed     MOV        EAX,dword ptr [ESI + 0x10]
//         004052f0     PUSH       this
//         004052f1     PUSH       EAX
//         004052f2     CALL       dword ptr [EDX + 0x228]
//                              ACT_misl.cpp:332 (9)
//         004052f8     MOV        EDX,dword ptr [ESI]
//         004052fa     PUSH       0x1
//         004052fc     MOV        this,ESI
//         004052fe     CALL       dword ptr [EDX + 0x5c]
//                              ACT_misl.cpp:333 (5)
//         00405301     JMP        LAB_0040544a
//                               LAB_00405306                                                 XREF[1]:     004052a5(j)
//                              ACT_misl.cpp:272 (12)
//         00405306     MOV        EAX,dword ptr [ESP + 0x18]
//         0040530a     PUSH       EAX
//         0040530b     CALL       RGE_Missile_Object::make_object_collision_list   RGE_Check_List * make_object_collision_list(R
//         00405310     MOV        EDI,EAX
//                              ACT_misl.cpp:274 (12)
//         00405312     TEST       EDI,EDI
//         00405314     MOV        dword ptr [ESP + 0x24],EDI
//         00405318     JZ         LAB_0040544a
//                              ACT_misl.cpp:276 (10)
//         0040531e     MOV        EBP,dword ptr [EDI]
//         00405320     TEST       EBP,EBP
//         00405322     JZ         LAB_0040543a
//                               LAB_00405328                                                 XREF[1]:     00405430(j)
//                              ACT_misl.cpp:279 (35)
//         00405328     MOV        EAX,dword ptr [ESI + 0x8]
//         0040532b     XOR        EDX,EDX
//         0040532d     MOV        this,dword ptr [EAX + 0x8]
//         00405330     MOV        DL,byte ptr [this->_padding_ + 0x14a]
//         00405336     MOV        this,EDX
//         00405338     SUB        this,0x0
//         0040533b     JZ         LAB_004053e7
//         00405341     DEC        this
//         00405342     JZ         LAB_004053ba
//         00405344     DEC        this
//         00405345     JNZ        LAB_0040542b
//                              ACT_misl.cpp:302 (3)
//         0040534b     MOV        this,dword ptr [ESI + 0x14]
//                              ACT_misl.cpp:304 (15)
//         0040534e     MOV        EDX,dword ptr [EBP]
//         00405351     TEST       this,this
//         00405353     JZ         LAB_0040538e
//         00405355     CMP        EDX,this
//         00405357     JZ         LAB_0040542b
//                              ACT_misl.cpp:306 (15)
//         0040535d     MOV        EDI,dword ptr [EDX + 0xc]
//         00405360     MOV        EBX,dword ptr [EAX + 0xc]
//         00405363     CMP        EDI,EBX
//         00405365     JZ         LAB_00405372
//         00405367     CMP        word ptr [EDI + 0x4a],0x0
//                              ACT_misl.cpp:308 (6)
//         0040536c     JNZ        LAB_004053f8
//                               LAB_00405372                                                 XREF[1]:     00405365(j)
//                              ACT_misl.cpp:309 (23)
//         00405372     MOV        EDI,dword ptr [EAX + 0x40]
//         00405375     MOV        EDX,dword ptr [this->_padding_]
//         00405377     PUSH       0x0
//         00405379     PUSH       this
//         0040537a     PUSH       EDI
//         0040537b     MOV        EDI,dword ptr [EAX + 0x3c]
//         0040537e     MOV        EAX,dword ptr [EAX + 0x38]
//         00405381     PUSH       EDI
//         00405382     PUSH       EAX
//         00405383     CALL       dword ptr [EDX + 0x21c]
//                              ACT_misl.cpp:313 (5)
//         00405389     JMP        LAB_00405422
//                               LAB_0040538e                                                 XREF[1]:     00405353(j)
//                              ACT_misl.cpp:315 (15)
//         0040538e     MOV        this,dword ptr [EDX + 0xc]
//         00405391     MOV        EDI,dword ptr [EAX + 0xc]
//         00405394     CMP        this,EDI
//         00405396     JZ         LAB_0040539f
//         00405398     CMP        word ptr [ECX + this+0x4a],0x0
//                              ACT_misl.cpp:317 (2)
//         0040539d     JNZ        LAB_0040540a
//                               LAB_0040539f                                                 XREF[1]:     00405396(j)
//                              ACT_misl.cpp:318 (25)
//         0040539f     MOV        this,dword ptr [EAX + 0x40]
//         004053a2     MOV        EDX,dword ptr [EAX]
//         004053a4     PUSH       0x0
//         004053a6     PUSH       EAX
//         004053a7     PUSH       this
//         004053a8     MOV        this,dword ptr [EAX + 0x3c]
//         004053ab     PUSH       this
//         004053ac     MOV        this,dword ptr [EAX + 0x38]
//         004053af     PUSH       this
//         004053b0     MOV        this,EAX
//         004053b2     CALL       dword ptr [EDX + 0x21c]
//                              ACT_misl.cpp:321 (2)
//         004053b8     JMP        LAB_00405422
//                               LAB_004053ba                                                 XREF[1]:     00405342(j)
//                              ACT_misl.cpp:292 (20)
//         004053ba     MOV        EDX,dword ptr [EBP]
//         004053bd     MOV        EDI,dword ptr [EAX + 0xc]
//         004053c0     MOV        this,dword ptr [EDX + 0xc]
//         004053c3     CMP        this,EDI
//         004053c5     JZ         LAB_0040542b
//         004053c7     CMP        word ptr [ECX + this+0x4a],0x0
//         004053cc     JZ         LAB_0040542b
//                              ACT_misl.cpp:294 (7)
//         004053ce     MOV        this,dword ptr [ESI + 0x14]
//         004053d1     TEST       this,this
//         004053d3     JZ         LAB_0040540a
//                              ACT_misl.cpp:295 (16)
//         004053d5     MOV        EBX,dword ptr [EAX + 0x40]
//         004053d8     MOV        EDI,dword ptr [this->_padding_]
//         004053da     PUSH       EBX
//         004053db     MOV        EBX,dword ptr [EAX + 0x3c]
//         004053de     MOV        EAX,dword ptr [EAX + 0x38]
//         004053e1     PUSH       EBX
//         004053e2     PUSH       EAX
//         004053e3     PUSH       this
//         004053e4     PUSH       EDX
//                              ACT_misl.cpp:296 (2)
//         004053e5     JMP        LAB_0040541c
//                               LAB_004053e7                                                 XREF[1]:     0040533b(j)
//                              ACT_misl.cpp:282 (10)
//         004053e7     MOV        EDX,dword ptr [ESI + 0x10]
//         004053ea     MOV        this,dword ptr [EBP]
//         004053ed     CMP        this,EDX
//         004053ef     JNZ        LAB_0040542b
//                              ACT_misl.cpp:284 (7)
//         004053f1     MOV        this,dword ptr [ESI + 0x14]
//         004053f4     TEST       this,this
//         004053f6     JZ         LAB_0040540a
//                               LAB_004053f8                                                 XREF[1]:     0040536c(j)
//                              ACT_misl.cpp:285 (16)
//         004053f8     MOV        EBX,dword ptr [EAX + 0x40]
//         004053fb     MOV        EDI,dword ptr [this->_padding_]
//         004053fd     PUSH       EBX
//         004053fe     MOV        EBX,dword ptr [EAX + 0x3c]
//         00405401     MOV        EAX,dword ptr [EAX + 0x38]
//         00405404     PUSH       EBX
//         00405405     PUSH       EAX
//         00405406     PUSH       this
//         00405407     PUSH       EDX
//                              ACT_misl.cpp:286 (2)
//         00405408     JMP        LAB_0040541c
//                               LAB_0040540a                                                 XREF[3]:     0040539d(j), 004053d3(j),
//                                                                                                         004053f6(j)
//                              ACT_misl.cpp:287 (24)
//         0040540a     MOV        this,dword ptr [EAX + 0x40]
//         0040540d     MOV        EDI,dword ptr [EAX]
//         0040540f     PUSH       this
//         00405410     MOV        this,dword ptr [EAX + 0x3c]
//         00405413     PUSH       this
//         00405414     MOV        this,dword ptr [EAX + 0x38]
//         00405417     PUSH       this
//         00405418     PUSH       EAX
//         00405419     PUSH       EDX
//         0040541a     MOV        this,EAX
//                               LAB_0040541c                                                 XREF[2]:     004053e5(j), 00405408(j)
//         0040541c     CALL       dword ptr [EDI + 0x228]
//                               LAB_00405422                                                 XREF[2]:     00405389(j), 004053b8(j)
//                              ACT_misl.cpp:288 (20)
//         00405422     MOV        EDX,dword ptr [ESI]
//         00405424     PUSH       0x1
//         00405426     MOV        this,ESI
//         00405428     CALL       dword ptr [EDX + 0x5c]
//                               LAB_0040542b                                                 XREF[5]:     00405345(j), 00405357(j),
//                                                                                                         004053c5(j), 004053cc(j),
//                                                                                                         004053ef(j)
//         0040542b     MOV        EBP,dword ptr [EBP + 0x10]
//         0040542e     TEST       EBP,EBP
//         00405430     JNZ        LAB_00405328
//                              ACT_misl.cpp:276 (4)
//         00405436     MOV        EDI,dword ptr [ESP + 0x24]
//                               LAB_0040543a                                                 XREF[1]:     00405322(j)
//                              ACT_misl.cpp:324 (16)
//         0040543a     MOV        this,EDI
//         0040543c     CALL       RGE_Check_List::~RGE_Check_List                  void ~RGE_Check_List(RGE_Check_List * this)
//         00405441     PUSH       EDI
//         00405442     CALL       operator_delete                                  void operator_delete(void * param_1)
//         00405447     ADD        ESP,0x4
//                               LAB_0040544a                                                 XREF[4]:     004052a9(j), 004052da(j),
//                                                                                                         00405301(j), 00405318(j)
//                              ACT_misl.cpp:337 (14)
//         0040544a     MOV        AL,byte ptr [ESP + 0x13]
//         0040544e     TEST       AL,AL
//         00405450     JZ         LAB_00405497
//         00405452     CMP        byte ptr [ESI + 0xc],0x1
//         00405456     JZ         LAB_00405497
//                              ACT_misl.cpp:340 (7)
//         00405458     MOV        this,dword ptr [ESI + 0x14]
//         0040545b     TEST       this,this
//         0040545d     JZ         LAB_00405474
//                              ACT_misl.cpp:341 (19)
//         0040545f     MOV        EAX,dword ptr [ESI + 0x8]
//         00405462     MOV        EDX,dword ptr [this->_padding_]
//         00405464     PUSH       0x0
//         00405466     PUSH       this
//         00405467     MOV        EDI,dword ptr [EAX + 0x40]
//         0040546a     PUSH       EDI
//         0040546b     MOV        EDI,dword ptr [EAX + 0x3c]
//         0040546e     MOV        EAX,dword ptr [EAX + 0x38]
//         00405471     PUSH       EDI
//                              ACT_misl.cpp:342 (2)
//         00405472     JMP        LAB_00405487
//                               LAB_00405474                                                 XREF[1]:     0040545d(j)
//                              ACT_misl.cpp:343 (26)
//         00405474     MOV        this,dword ptr [ESI + 0x8]
//         00405477     PUSH       0x0
//         00405479     PUSH       this
//         0040547a     MOV        EAX,dword ptr [ECX + this->velocity_x]
//         0040547d     MOV        EDX,dword ptr [this->_padding_]
//         0040547f     PUSH       EAX
//         00405480     MOV        EAX,dword ptr [ECX + this->_padding_]
//         00405483     PUSH       EAX
//         00405484     MOV        EAX,dword ptr [ECX + this->_padding_]
//                               LAB_00405487                                                 XREF[1]:     00405472(j)
//         00405487     PUSH       EAX
//         00405488     CALL       dword ptr [EDX + 0x21c]
//                              ACT_misl.cpp:344 (9)
//         0040548e     MOV        EDX,dword ptr [ESI]
//         00405490     PUSH       0x1
//         00405492     MOV        this,ESI
//         00405494     CALL       dword ptr [EDX + 0x5c]
//                               LAB_00405497                                                 XREF[3]:     004051b3(j), 00405450(j),
//                                                                                                         00405456(j)
//                              ACT_misl.cpp:355 (2)
//         00405497     XOR        AL,AL
//                              ACT_misl.cpp:356 (18)
//         00405499     POP        EDI
//         0040549a     POP        ESI
//         0040549b     POP        EBP
//         0040549c     POP        EBX
//         0040549d     ADD        ESP,0x18
//         004054a0     RET
//                               LAB_004054a1                                                 XREF[1]:     004051aa(j)
//         004054a1     POP        EDI
//         004054a2     POP        ESI
//         004054a3     POP        EBP
//         004054a4     MOV        AL,0x1
//         004054a6     POP        EBX
//         004054a7     ADD        ESP,0x18
//         004054aa     RET
//         004054ab     ??         90h
//         004054ac     NOP
//         004054ad     NOP
//         004054ae     NOP
//         004054af     NOP
    return 0;
}

void RGE_Action_Missile::save(int param_1) {
    /* TODO: Stub */
//                              void __thiscall save(RGE_Action_Missile * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_Action_Mis    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004054b2(R)
//                               ?save@RGE_Action_Missile@@UAEXH@Z                            XREF[1]:     0056e334(*)
//                               RGE_Action_Missile::save
//                              ACT_misl.cpp:361 (2)
//         004054b0     PUSH       ESI
//         004054b1     PUSH       EDI
//                              ACT_misl.cpp:362 (12)
//         004054b2     MOV        EDI,dword ptr [ESP + param_1]
//         004054b6     MOV        ESI,this
//         004054b8     PUSH       EDI
//         004054b9     CALL       RGE_Action::save                                 void save(RGE_Action * this, int param_1)
//                              ACT_misl.cpp:364 (15)
//         004054be     LEA        EAX,[ESI + 0x40]
//         004054c1     PUSH       0x4
//         004054c3     PUSH       EAX
//         004054c4     PUSH       EDI
//         004054c5     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004054ca     ADD        ESP,0xc
//                              ACT_misl.cpp:365 (15)
//         004054cd     LEA        this,[ESI + 0x44]
//         004054d0     PUSH       0x4
//         004054d2     PUSH       this
//         004054d3     PUSH       EDI
//         004054d4     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004054d9     ADD        ESP,0xc
//                              ACT_misl.cpp:366 (15)
//         004054dc     LEA        EDX,[ESI + 0x48]
//         004054df     PUSH       0x4
//         004054e1     PUSH       EDX
//         004054e2     PUSH       EDI
//         004054e3     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004054e8     ADD        ESP,0xc
//                              ACT_misl.cpp:367 (15)
//         004054eb     LEA        EAX,[ESI + 0x4c]
//         004054ee     PUSH       0x4
//         004054f0     PUSH       EAX
//         004054f1     PUSH       EDI
//         004054f2     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004054f7     ADD        ESP,0xc
//                              ACT_misl.cpp:368 (15)
//         004054fa     ADD        ESI,0x50
//         004054fd     PUSH       0x4
//         004054ff     PUSH       ESI
//         00405500     PUSH       EDI
//         00405501     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         00405506     ADD        ESP,0xc
//                              ACT_misl.cpp:369 (5)
//         00405509     POP        EDI
//         0040550a     POP        ESI
//         0040550b     RET        0x4
//         0040550e     ??         90h
//         0040550f     NOP
    return;
}

RGE_Action_Missile::~RGE_Action_Missile() {
    /* TODO: Stub */
//                              void __thiscall ~RGE_Action_Missile(RGE_Action_Missile * this)
//              void              <VOID>         <RETURN>
//              RGE_Action_Mis    ECX:4 (auto)   this
//                               ??1RGE_Action_Missile@@UAE@XZ                                XREF[1]:     `vector_deleting_destructor':00404
//                               RGE_Action_Missile::~RGE_Action_Missile
//         00404c80     JMP        RGE_Action::~RGE_Action
//         00404c85     ??         90h
//         00404c86     NOP
//         00404c87     NOP
//         00404c88     NOP
//         00404c89     NOP
//         00404c8a     NOP
//         00404c8b     NOP
//         00404c8c     NOP
//         00404c8d     NOP
//         00404c8e     NOP
//         00404c8f     NOP
}

