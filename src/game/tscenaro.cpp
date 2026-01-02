#include "../common.h"
#include "tscenaro.h"

TRIBE_Scenario_Header::TRIBE_Scenario_Header(T_Scenario* param_1) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Scenario_Header(TRIBE_Scenario_Header * t
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Scenario    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052aa07(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0052aa22(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0052aa58(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0052aa10(W)
//                               ??0TRIBE_Scenario_Header@@QAE@H@Z                            XREF[1]:     new_scenario_header:00523547(c)
//                               TRIBE_Scenario_Header::TRIBE_Scenario_Header
//                              tscenaro.cpp:56 (41)
//         0052a9f0     PUSH       -0x1
//         0052a9f2     PUSH       FUN_00561868
//         0052a9f7     MOV        EAX,FS:[0x0]
//         0052a9fd     PUSH       EAX
//         0052a9fe     MOV        dword ptr FS:[0x0],ESP
//         0052aa05     PUSH       this
//         0052aa06     PUSH       EBX
//         0052aa07     MOV        EBX,dword ptr [ESP + param_1]
//         0052aa0b     PUSH       ESI
//         0052aa0c     PUSH       EDI
//         0052aa0d     MOV        ESI,this
//         0052aa0f     PUSH       EBX
//         0052aa10     MOV        dword ptr [ESP + local_10],ESI
//         0052aa14     CALL       RGE_Scenario_Header::RGE_Scenario_Header         undefined RGE_Scenario_Header(RGE_Scenario_He
//                              tscenaro.cpp:61 (39)
//         0052aa19     MOV        this,dword ptr [ESI + 0x4]
//         0052aa1c     LEA        EAX,[ESI + 0x14]
//         0052aa1f     LEA        EDI,[ESI + 0x18]
//         0052aa22     MOV        dword ptr [ESP + local_4],0x0
//         0052aa2a     TEST       this,this
//         0052aa2c     MOV        dword ptr [ESI],TRIBE_Scenario_Header::`vftable' = 0052aa70
//         0052aa32     MOV        dword ptr [EAX],0x0
//         0052aa38     MOV        dword ptr [EDI],0x0
//         0052aa3e     JNZ        LAB_0052aa58
//                              tscenaro.cpp:64 (12)
//         0052aa40     PUSH       0x4
//         0052aa42     PUSH       EAX
//         0052aa43     PUSH       EBX
//         0052aa44     CALL       rge_read_uncompressed                            void rge_read_uncompressed(int param_1, void
//         0052aa49     ADD        ESP,0xc
//                              tscenaro.cpp:65 (12)
//         0052aa4c     PUSH       0x4
//         0052aa4e     PUSH       EDI
//         0052aa4f     PUSH       EBX
//         0052aa50     CALL       rge_read_uncompressed                            void rge_read_uncompressed(int param_1, void
//         0052aa55     ADD        ESP,0xc
//                               LAB_0052aa58                                                 XREF[1]:     0052aa3e(j)
//                              tscenaro.cpp:66 (22)
//         0052aa58     MOV        this,dword ptr [ESP + local_c]
//         0052aa5c     MOV        EAX,ESI
//         0052aa5e     POP        EDI
//         0052aa5f     POP        ESI
//         0052aa60     MOV        dword ptr FS:[0x0],this
//         0052aa67     POP        EBX
//         0052aa68     ADD        ESP,0x10
//         0052aa6b     RET        0x4
//         0052aa6e     ??         90h
//         0052aa6f     NOP
}

TRIBE_Scenario_Header::TRIBE_Scenario_Header(int param_1) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Scenario_Header(TRIBE_Scenario_Header * t
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Scenario    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052aa07(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0052aa22(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0052aa58(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0052aa10(W)
//                               ??0TRIBE_Scenario_Header@@QAE@H@Z                            XREF[1]:     new_scenario_header:00523547(c)
//                               TRIBE_Scenario_Header::TRIBE_Scenario_Header
//                              tscenaro.cpp:56 (41)
//         0052a9f0     PUSH       -0x1
//         0052a9f2     PUSH       FUN_00561868
//         0052a9f7     MOV        EAX,FS:[0x0]
//         0052a9fd     PUSH       EAX
//         0052a9fe     MOV        dword ptr FS:[0x0],ESP
//         0052aa05     PUSH       this
//         0052aa06     PUSH       EBX
//         0052aa07     MOV        EBX,dword ptr [ESP + param_1]
//         0052aa0b     PUSH       ESI
//         0052aa0c     PUSH       EDI
//         0052aa0d     MOV        ESI,this
//         0052aa0f     PUSH       EBX
//         0052aa10     MOV        dword ptr [ESP + local_10],ESI
//         0052aa14     CALL       RGE_Scenario_Header::RGE_Scenario_Header         undefined RGE_Scenario_Header(RGE_Scenario_He
//                              tscenaro.cpp:61 (39)
//         0052aa19     MOV        this,dword ptr [ESI + 0x4]
//         0052aa1c     LEA        EAX,[ESI + 0x14]
//         0052aa1f     LEA        EDI,[ESI + 0x18]
//         0052aa22     MOV        dword ptr [ESP + local_4],0x0
//         0052aa2a     TEST       this,this
//         0052aa2c     MOV        dword ptr [ESI],TRIBE_Scenario_Header::`vftable' = 0052aa70
//         0052aa32     MOV        dword ptr [EAX],0x0
//         0052aa38     MOV        dword ptr [EDI],0x0
//         0052aa3e     JNZ        LAB_0052aa58
//                              tscenaro.cpp:64 (12)
//         0052aa40     PUSH       0x4
//         0052aa42     PUSH       EAX
//         0052aa43     PUSH       EBX
//         0052aa44     CALL       rge_read_uncompressed                            void rge_read_uncompressed(int param_1, void
//         0052aa49     ADD        ESP,0xc
//                              tscenaro.cpp:65 (12)
//         0052aa4c     PUSH       0x4
//         0052aa4e     PUSH       EDI
//         0052aa4f     PUSH       EBX
//         0052aa50     CALL       rge_read_uncompressed                            void rge_read_uncompressed(int param_1, void
//         0052aa55     ADD        ESP,0xc
//                               LAB_0052aa58                                                 XREF[1]:     0052aa3e(j)
//                              tscenaro.cpp:66 (22)
//         0052aa58     MOV        this,dword ptr [ESP + local_c]
//         0052aa5c     MOV        EAX,ESI
//         0052aa5e     POP        EDI
//         0052aa5f     POP        ESI
//         0052aa60     MOV        dword ptr FS:[0x0],this
//         0052aa67     POP        EBX
//         0052aa68     ADD        ESP,0x10
//         0052aa6b     RET        0x4
//         0052aa6e     ??         90h
//         0052aa6f     NOP
}

long TRIBE_Scenario_Header::get_size() {
    /* TODO: Stub */
//                              long __thiscall get_size(TRIBE_Scenario_Header * this)
//              long              EAX:4          <RETURN>
//              TRIBE_Scenario    ECX:4 (auto)   this
//                               ?get_size@TRIBE_Scenario_Header@@UAEJXZ                      XREF[1]:     00577300(*)
//                               TRIBE_Scenario_Header::get_size
//                              tscenaro.cpp:70 (8)
//         0052aa70     CALL       RGE_Scenario_Header::get_size                    long get_size(RGE_Scenario_Header * this)
//         0052aa75     ADD        EAX,0x8
//                              tscenaro.cpp:78 (1)
//         0052aa78     RET
//         0052aa79     ??         90h
//         0052aa7a     NOP
//         0052aa7b     NOP
//         0052aa7c     NOP
//         0052aa7d     NOP
//         0052aa7e     NOP
//         0052aa7f     NOP
    return 0;
}

void TRIBE_Scenario_Header::save(int param_1) {
    /* TODO: Stub */
//                              void __thiscall save(TRIBE_Scenario_Header * this, int param_1)
//              void              <VOID>         <RETURN>
//              TRIBE_Scenario    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052aa82(R)
//                               ?save@TRIBE_Scenario_Header@@UAEXH@Z
//                               TRIBE_Scenario_Header::save
//                              tscenaro.cpp:82 (2)
//         0052aa80     PUSH       ESI
//         0052aa81     PUSH       EDI
//                              tscenaro.cpp:83 (12)
//         0052aa82     MOV        EDI,dword ptr [ESP + param_1]
//         0052aa86     MOV        ESI,this
//         0052aa88     PUSH       EDI
//         0052aa89     CALL       RGE_Scenario_Header::save                        void save(RGE_Scenario_Header * this, int par
//                              tscenaro.cpp:85 (15)
//         0052aa8e     LEA        EAX,[ESI + 0x14]
//         0052aa91     PUSH       0x4
//         0052aa93     PUSH       EAX
//         0052aa94     PUSH       EDI
//         0052aa95     CALL       rge_write_uncompressed                           void rge_write_uncompressed(int param_1, void
//         0052aa9a     ADD        ESP,0xc
//                              tscenaro.cpp:86 (15)
//         0052aa9d     ADD        ESI,0x18
//         0052aaa0     PUSH       0x4
//         0052aaa2     PUSH       ESI
//         0052aaa3     PUSH       EDI
//         0052aaa4     CALL       rge_write_uncompressed                           void rge_write_uncompressed(int param_1, void
//         0052aaa9     ADD        ESP,0xc
//                              tscenaro.cpp:87 (5)
//         0052aaac     POP        EDI
//         0052aaad     POP        ESI
//         0052aaae     RET        0x4
//         0052aab1     ??         90h
//         0052aab2     NOP
//         0052aab3     NOP
//         0052aab4     NOP
//         0052aab5     NOP
//         0052aab6     NOP
//         0052aab7     NOP
//         0052aab8     NOP
//         0052aab9     NOP
//         0052aaba     NOP
//         0052aabb     NOP
//         0052aabc     NOP
//         0052aabd     NOP
//         0052aabe     NOP
//         0052aabf     NOP
    return;
}

T_Scenario::T_Scenario(RGE_Game_World* param_1) {
    /* TODO: Stub */
//                              undefined __thiscall T_Scenario(T_Scenario * this, int param_1, RGE_
//              undefined         <UNASSIGNED>   <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[4]:     0052abad(R), 0052ac7b(W), 0052acc8(R), 0052acd6(W)
//              RGE_Game_World    Stack[0x8]:4   param_2                   XREF[5]:     0052aba6(R), 0052abcd(W), 0052acef(*), 0052add7(*),
//                                                                                     0052aeec(*)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0052abc3(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0052af09(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0052abb6(W)
//                               ??0T_Scenario@@QAE@HPAVRGE_Game_World@@@Z                    XREF[2]:     new_scenario_info:0052360c(c),
//                               T_Scenario::T_Scenario                                                    scenario_init:0052e5d2(c)
//                              tscenaro.cpp:114 (49)
//         0052ab90     PUSH       -0x1
//         0052ab92     PUSH       FUN_005618a8
//         0052ab97     MOV        EAX,FS:[0x0]
//         0052ab9d     PUSH       EAX
//         0052ab9e     MOV        dword ptr FS:[0x0],ESP
//         0052aba5     PUSH       this
//         0052aba6     MOV        EAX,dword ptr [ESP + param_2]
//         0052abaa     PUSH       EBX
//         0052abab     PUSH       EBP
//         0052abac     PUSH       ESI
//         0052abad     MOV        ESI,dword ptr [ESP + param_1]
//         0052abb1     PUSH       EDI
//         0052abb2     MOV        EDI,this
//         0052abb4     PUSH       EAX
//         0052abb5     PUSH       ESI
//         0052abb6     MOV        dword ptr [ESP + local_10],EDI
//         0052abba     CALL       RGE_Scenario::RGE_Scenario                       undefined RGE_Scenario(RGE_Scenario * this, i
//         0052abbf     XOR        EBX,EBX
//                              tscenaro.cpp:119 (21)
//         0052abc1     MOV        this,EDI
//         0052abc3     MOV        dword ptr [ESP + local_4],EBX
//         0052abc7     MOV        dword ptr [EDI],T_Scenario::`vftable'            = 0052c080
//         0052abcd     MOV        dword ptr [ESP + param_2],EBX
//         0052abd1     CALL       T_Scenario::InitializeVictoryValues              void InitializeVictoryValues(T_Scenario * this)
//                              tscenaro.cpp:120 (7)
//         0052abd6     MOV        this,EDI
//         0052abd8     CALL       T_Scenario::InitializeFriendlinessValues         void InitializeFriendlinessValues(T_Scenario
//                              tscenaro.cpp:121 (7)
//         0052abdd     MOV        this,EDI
//         0052abdf     CALL       T_Scenario::ClearDisabledTechnologies            void ClearDisabledTechnologies(T_Scenario * t
//                              tscenaro.cpp:129 (57)
//         0052abe4     FLD        float ptr [EDI + 0x1888]
//         0052abea     FCOMP      float ptr [DAT_00577318]                         = D7h
//         0052abf0     MOV        dword ptr [EDI + 0x5140],EBX
//         0052abf6     MOV        dword ptr [EDI + 0x5144],0x384
//         0052ac00     MOV        dword ptr [EDI + 0x5148],0x2328
//         0052ac0a     MOV        dword ptr [EDI + 0x4be8],EBX
//         0052ac10     MOV        dword ptr [EDI + 0x4bf0],EBX
//         0052ac16     FNSTSW     AX
//         0052ac18     TEST       AH,0x41
//         0052ac1b     JZ         LAB_0052ac3d
//                              tscenaro.cpp:207 (32)
//         0052ac1d     LEA        EBX,[EDI + 0xd]
//         0052ac20     MOV        EBP,0x10
//                               LAB_0052ac25                                                 XREF[1]:     0052ac3b(j)
//         0052ac25     PUSH       0x100
//         0052ac2a     PUSH       EBX
//         0052ac2b     PUSH       ESI
//         0052ac2c     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052ac31     ADD        ESP,0xc
//         0052ac34     ADD        EBX,0x100
//         0052ac3a     DEC        EBP
//         0052ac3b     JNZ        LAB_0052ac25
//                               LAB_0052ac3d                                                 XREF[1]:     0052ac1b(j)
//                              tscenaro.cpp:133 (19)
//         0052ac3d     FLD        float ptr [EDI + 0x1888]
//         0052ac43     FCOMP      float ptr [DAT_00577318]                         = D7h
//         0052ac49     FNSTSW     AX
//         0052ac4b     TEST       AH,0x41
//         0052ac4e     JNZ        LAB_0052ac6f
//                              tscenaro.cpp:207 (29)
//         0052ac50     LEA        EBX,[EDI + 0x1990]
//         0052ac56     MOV        EBP,0x10
//                               LAB_0052ac5b                                                 XREF[1]:     0052ac6b(j)
//         0052ac5b     PUSH       0x10
//         0052ac5d     PUSH       EBX
//         0052ac5e     PUSH       ESI
//         0052ac5f     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052ac64     ADD        ESP,0xc
//         0052ac67     ADD        EBX,0x10
//         0052ac6a     DEC        EBP
//         0052ac6b     JNZ        LAB_0052ac5b
//                              tscenaro.cpp:136 (2)
//         0052ac6d     JMP        LAB_0052acdc
//                               LAB_0052ac6f                                                 XREF[1]:     0052ac4e(j)
//                              tscenaro.cpp:207 (109)
//         0052ac6f     LEA        EBX,[EDI + 0x18cc]
//         0052ac75     LEA        EBP,[EDI + 0x1990]
//         0052ac7b     MOV        dword ptr [ESP + param_1],0x10
//                               LAB_0052ac83                                                 XREF[1]:     0052acda(j)
//         0052ac83     LEA        this,[EBX + 0x80]
//         0052ac89     PUSH       0x4
//         0052ac8b     PUSH       this
//         0052ac8c     PUSH       ESI
//         0052ac8d     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052ac92     ADD        ESP,0xc
//         0052ac95     PUSH       0x10
//         0052ac97     PUSH       EBP
//         0052ac98     PUSH       ESI
//         0052ac99     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052ac9e     ADD        ESP,0xc
//         0052aca1     PUSH       0x4
//         0052aca3     PUSH       EBX
//         0052aca4     PUSH       ESI
//         0052aca5     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052acaa     ADD        ESP,0xc
//         0052acad     LEA        EDX,[EBX + 0x40]
//         0052acb0     PUSH       0x4
//         0052acb2     PUSH       EDX
//         0052acb3     PUSH       ESI
//         0052acb4     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052acb9     ADD        ESP,0xc
//         0052acbc     LEA        EAX,[EBX + -0x40]
//         0052acbf     PUSH       0x4
//         0052acc1     PUSH       EAX
//         0052acc2     PUSH       ESI
//         0052acc3     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052acc8     MOV        EAX,dword ptr [ESP + param_1]
//         0052accc     ADD        ESP,0xc
//         0052accf     ADD        EBP,0x10
//         0052acd2     ADD        EBX,0x4
//         0052acd5     DEC        EAX
//         0052acd6     MOV        dword ptr [ESP + param_1],EAX
//         0052acda     JNZ        LAB_0052ac83
//                               LAB_0052acdc                                                 XREF[1]:     0052ac6d(j)
//                              tscenaro.cpp:146 (19)
//         0052acdc     FLD        float ptr [EDI + 0x1888]
//         0052ace2     FCOMP      float ptr [DAT_0057731c]                         = 5Ch    \
//         0052ace8     FNSTSW     AX
//         0052acea     TEST       AH,0x41
//         0052aced     JNZ        LAB_0052acff
//                              tscenaro.cpp:147 (16)
//         0052acef     LEA        this=>param_2,[ESP + 0x28]
//         0052acf3     PUSH       0x4
//         0052acf5     PUSH       this
//         0052acf6     PUSH       ESI
//         0052acf7     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052acfc     ADD        ESP,0xc
//                               LAB_0052acff                                                 XREF[1]:     0052aced(j)
//                              tscenaro.cpp:149 (18)
//         0052acff     LEA        EAX,[EDI + 0x1a90]
//         0052ad05     PUSH       0x18
//         0052ad07     PUSH       EAX
//         0052ad08     PUSH       ESI
//         0052ad09     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052ad0e     ADD        ESP,0xc
//                              tscenaro.cpp:150 (15)
//         0052ad11     LEA        EAX,[EDI + 0x4be8]
//         0052ad17     PUSH       0x4
//         0052ad19     PUSH       EAX
//         0052ad1a     PUSH       ESI
//         0052ad1b     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              tscenaro.cpp:152 (22)
//         0052ad20     FLD        float ptr [EDI + 0x1888]
//         0052ad26     FCOMP      float ptr [DAT_00577318]                         = D7h
//         0052ad2c     ADD        ESP,0xc
//         0052ad2f     FNSTSW     AX
//         0052ad31     TEST       AH,0x1
//         0052ad34     JNZ        LAB_0052ad6e
//                              tscenaro.cpp:154 (18)
//         0052ad36     LEA        EAX,[EDI + 0x5140]
//         0052ad3c     PUSH       0x4
//         0052ad3e     PUSH       EAX
//         0052ad3f     PUSH       ESI
//         0052ad40     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052ad45     ADD        ESP,0xc
//                              tscenaro.cpp:155 (18)
//         0052ad48     LEA        EAX,[EDI + 0x5144]
//         0052ad4e     PUSH       0x4
//         0052ad50     PUSH       EAX
//         0052ad51     PUSH       ESI
//         0052ad52     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052ad57     ADD        ESP,0xc
//                              tscenaro.cpp:156 (18)
//         0052ad5a     LEA        EAX,[EDI + 0x5148]
//         0052ad60     PUSH       0x4
//         0052ad62     PUSH       EAX
//         0052ad63     PUSH       ESI
//         0052ad64     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052ad69     ADD        ESP,0xc
//                              tscenaro.cpp:158 (2)
//         0052ad6c     JMP        LAB_0052ad8c
//                               LAB_0052ad6e                                                 XREF[1]:     0052ad34(j)
//                              tscenaro.cpp:160 (10)
//         0052ad6e     MOV        dword ptr [EDI + 0x5140],0x4
//                              tscenaro.cpp:161 (10)
//         0052ad78     MOV        dword ptr [EDI + 0x5144],0x384
//                              tscenaro.cpp:162 (10)
//         0052ad82     MOV        dword ptr [EDI + 0x5148],0x2328
//                               LAB_0052ad8c                                                 XREF[1]:     0052ad6c(j)
//                              tscenaro.cpp:166 (32)
//         0052ad8c     LEA        EDX,[EDI + 0x47a8]
//         0052ad92     PUSH       0x400
//         0052ad97     PUSH       EDX
//         0052ad98     PUSH       ESI
//         0052ad99     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052ad9e     ADD        ESP,0xc
//         0052ada1     LEA        EBX,[EDI + 0x1aa8]
//         0052ada7     MOV        EBP,0x10
//                               LAB_0052adac                                                 XREF[1]:     0052adc2(j)
//                              tscenaro.cpp:168 (24)
//         0052adac     PUSH       0x2d0
//         0052adb1     PUSH       EBX
//         0052adb2     PUSH       ESI
//         0052adb3     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052adb8     ADD        ESP,0xc
//         0052adbb     ADD        EBX,0x2d0
//         0052adc1     DEC        EBP
//         0052adc2     JNZ        LAB_0052adac
//                              tscenaro.cpp:170 (19)
//         0052adc4     FLD        float ptr [EDI + 0x1888]
//         0052adca     FCOMP      float ptr [DAT_0057731c]                         = 5Ch    \
//         0052add0     FNSTSW     AX
//         0052add2     TEST       AH,0x41
//         0052add5     JNZ        LAB_0052ade7
//                              tscenaro.cpp:171 (16)
//         0052add7     LEA        EAX=>param_2,[ESP + 0x28]
//         0052addb     PUSH       0x4
//         0052addd     PUSH       EAX
//         0052adde     PUSH       ESI
//         0052addf     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052ade4     ADD        ESP,0xc
//                               LAB_0052ade7                                                 XREF[1]:     0052add5(j)
//                              tscenaro.cpp:172 (12)
//         0052ade7     CMP        dword ptr [EDI + 0x1888],0x3f8147ae
//         0052adf1     JNZ        LAB_0052ae0d
//                              tscenaro.cpp:175 (6)
//         0052adf3     LEA        EBP,[EDI + 0x4ba8]
//                              tscenaro.cpp:207 (20)
//         0052adf9     MOV        EBX,0x10
//                               LAB_0052adfe                                                 XREF[1]:     0052ae0b(j)
//         0052adfe     PUSH       0x40
//         0052ae00     PUSH       EBP
//         0052ae01     PUSH       ESI
//         0052ae02     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052ae07     ADD        ESP,0xc
//         0052ae0a     DEC        EBX
//         0052ae0b     JNZ        LAB_0052adfe
//                               LAB_0052ae0d                                                 XREF[1]:     0052adf1(j)
//                              tscenaro.cpp:177 (19)
//         0052ae0d     FLD        float ptr [EDI + 0x1888]
//         0052ae13     FCOMP      float ptr [DAT_0057731c]                         = 5Ch    \
//         0052ae19     FNSTSW     AX
//         0052ae1b     TEST       AH,0x1
//         0052ae1e     JNZ        LAB_0052ae32
//                              tscenaro.cpp:179 (18)
//         0052ae20     LEA        this,[EDI + 0x4ba8]
//         0052ae26     PUSH       0x40
//         0052ae28     PUSH       this
//         0052ae29     PUSH       ESI
//         0052ae2a     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052ae2f     ADD        ESP,0xc
//                               LAB_0052ae32                                                 XREF[1]:     0052ae1e(j)
//                              tscenaro.cpp:182 (19)
//         0052ae32     FLD        float ptr [EDI + 0x1888]
//         0052ae38     FCOMP      float ptr [DAT_00577320]                         = 0Ah
//         0052ae3e     FNSTSW     AX
//         0052ae40     TEST       AH,0x41
//         0052ae43     JNZ        LAB_0052ae5a
//                              tscenaro.cpp:184 (21)
//         0052ae45     LEA        EDX,[EDI + 0x4bf4]
//         0052ae4b     PUSH       0x500
//         0052ae50     PUSH       EDX
//         0052ae51     PUSH       ESI
//         0052ae52     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052ae57     ADD        ESP,0xc
//                               LAB_0052ae5a                                                 XREF[1]:     0052ae43(j)
//                              tscenaro.cpp:187 (19)
//         0052ae5a     FLD        float ptr [EDI + 0x1888]
//         0052ae60     FCOMP      float ptr [DAT_00577324]                         = B8h
//         0052ae66     FNSTSW     AX
//         0052ae68     TEST       AH,0x41
//         0052ae6b     JNZ        LAB_0052aeb4
//                              tscenaro.cpp:189 (19)
//         0052ae6d     FLD        float ptr [EDI + 0x1888]
//         0052ae73     FCOMP      float ptr [DAT_00577328]                         = 29h    )
//         0052ae79     FNSTSW     AX
//         0052ae7b     TEST       AH,0x1
//         0052ae7e     JZ         LAB_0052aea2
//                              tscenaro.cpp:191 (18)
//         0052ae80     LEA        EAX,[EDI + 0x50f4]
//         0052ae86     PUSH       0x4
//         0052ae88     PUSH       EAX
//         0052ae89     PUSH       ESI
//         0052ae8a     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052ae8f     ADD        ESP,0xc
//                              tscenaro.cpp:192 (8)
//         0052ae92     XOR        EAX,EAX
//         0052ae94     MOV        dword ptr [EDI + 0x50f8],EAX
//                              tscenaro.cpp:193 (6)
//         0052ae9a     MOV        dword ptr [EDI + 0x50fc],EAX
//                              tscenaro.cpp:195 (2)
//         0052aea0     JMP        LAB_0052aeb4
//                               LAB_0052aea2                                                 XREF[1]:     0052ae7e(j)
//                              tscenaro.cpp:196 (18)
//         0052aea2     LEA        this,[EDI + 0x50f4]
//         0052aea8     PUSH       0xc
//         0052aeaa     PUSH       this
//         0052aeab     PUSH       ESI
//         0052aeac     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052aeb1     ADD        ESP,0xc
//                               LAB_0052aeb4                                                 XREF[2]:     0052ae6b(j), 0052aea0(j)
//                              tscenaro.cpp:199 (19)
//         0052aeb4     FLD        float ptr [EDI + 0x1888]
//         0052aeba     FCOMP      float ptr [DAT_0057732c]                         = 66h    f
//         0052aec0     FNSTSW     AX
//         0052aec2     TEST       AH,0x41
//         0052aec5     JNZ        LAB_0052aed9
//                              tscenaro.cpp:200 (18)
//         0052aec7     LEA        EDX,[EDI + 0x5100]
//         0052aecd     PUSH       0x40
//         0052aecf     PUSH       EDX
//         0052aed0     PUSH       ESI
//         0052aed1     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052aed6     ADD        ESP,0xc
//                               LAB_0052aed9                                                 XREF[1]:     0052aec5(j)
//                              tscenaro.cpp:202 (19)
//         0052aed9     FLD        float ptr [EDI + 0x1888]
//         0052aedf     FCOMP      float ptr [DAT_0057731c]                         = 5Ch    \
//         0052aee5     FNSTSW     AX
//         0052aee7     TEST       AH,0x41
//         0052aeea     JNZ        LAB_0052aefc
//                              tscenaro.cpp:203 (16)
//         0052aeec     LEA        EAX=>param_2,[ESP + 0x28]
//         0052aef0     PUSH       0x4
//         0052aef2     PUSH       EAX
//         0052aef3     PUSH       ESI
//         0052aef4     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052aef9     ADD        ESP,0xc
//                               LAB_0052aefc                                                 XREF[1]:     0052aeea(j)
//                              tscenaro.cpp:206 (2)
//         0052aefc     XOR        this,this
//                              tscenaro.cpp:207 (32)
//         0052aefe     MOV        EAX,EDI
//         0052af00     MOV        this,byte ptr [EDI + 0xc]
//         0052af03     MOV        dword ptr [EDI + 0x1a90],this
//         0052af09     MOV        this,dword ptr [ESP + local_c]
//         0052af0d     POP        EDI
//         0052af0e     POP        ESI
//         0052af0f     POP        EBP
//         0052af10     MOV        dword ptr FS:[0x0],this
//         0052af17     POP        EBX
//         0052af18     ADD        ESP,0x10
//         0052af1b     RET        0x8
//         0052af1e     ??         90h
//         0052af1f     NOP
}

T_Scenario::T_Scenario(int param_1, RGE_Game_World* param_2) {
    /* TODO: Stub */
//                              undefined __thiscall T_Scenario(T_Scenario * this, int param_1, RGE_
//              undefined         <UNASSIGNED>   <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[4]:     0052abad(R), 0052ac7b(W), 0052acc8(R), 0052acd6(W)
//              RGE_Game_World    Stack[0x8]:4   param_2                   XREF[5]:     0052aba6(R), 0052abcd(W), 0052acef(*), 0052add7(*),
//                                                                                     0052aeec(*)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0052abc3(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0052af09(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0052abb6(W)
//                               ??0T_Scenario@@QAE@HPAVRGE_Game_World@@@Z                    XREF[2]:     new_scenario_info:0052360c(c),
//                               T_Scenario::T_Scenario                                                    scenario_init:0052e5d2(c)
//                              tscenaro.cpp:114 (49)
//         0052ab90     PUSH       -0x1
//         0052ab92     PUSH       FUN_005618a8
//         0052ab97     MOV        EAX,FS:[0x0]
//         0052ab9d     PUSH       EAX
//         0052ab9e     MOV        dword ptr FS:[0x0],ESP
//         0052aba5     PUSH       this
//         0052aba6     MOV        EAX,dword ptr [ESP + param_2]
//         0052abaa     PUSH       EBX
//         0052abab     PUSH       EBP
//         0052abac     PUSH       ESI
//         0052abad     MOV        ESI,dword ptr [ESP + param_1]
//         0052abb1     PUSH       EDI
//         0052abb2     MOV        EDI,this
//         0052abb4     PUSH       EAX
//         0052abb5     PUSH       ESI
//         0052abb6     MOV        dword ptr [ESP + local_10],EDI
//         0052abba     CALL       RGE_Scenario::RGE_Scenario                       undefined RGE_Scenario(RGE_Scenario * this, i
//         0052abbf     XOR        EBX,EBX
//                              tscenaro.cpp:119 (21)
//         0052abc1     MOV        this,EDI
//         0052abc3     MOV        dword ptr [ESP + local_4],EBX
//         0052abc7     MOV        dword ptr [EDI],T_Scenario::`vftable'            = 0052c080
//         0052abcd     MOV        dword ptr [ESP + param_2],EBX
//         0052abd1     CALL       T_Scenario::InitializeVictoryValues              void InitializeVictoryValues(T_Scenario * this)
//                              tscenaro.cpp:120 (7)
//         0052abd6     MOV        this,EDI
//         0052abd8     CALL       T_Scenario::InitializeFriendlinessValues         void InitializeFriendlinessValues(T_Scenario
//                              tscenaro.cpp:121 (7)
//         0052abdd     MOV        this,EDI
//         0052abdf     CALL       T_Scenario::ClearDisabledTechnologies            void ClearDisabledTechnologies(T_Scenario * t
//                              tscenaro.cpp:129 (57)
//         0052abe4     FLD        float ptr [EDI + 0x1888]
//         0052abea     FCOMP      float ptr [DAT_00577318]                         = D7h
//         0052abf0     MOV        dword ptr [EDI + 0x5140],EBX
//         0052abf6     MOV        dword ptr [EDI + 0x5144],0x384
//         0052ac00     MOV        dword ptr [EDI + 0x5148],0x2328
//         0052ac0a     MOV        dword ptr [EDI + 0x4be8],EBX
//         0052ac10     MOV        dword ptr [EDI + 0x4bf0],EBX
//         0052ac16     FNSTSW     AX
//         0052ac18     TEST       AH,0x41
//         0052ac1b     JZ         LAB_0052ac3d
//                              tscenaro.cpp:207 (32)
//         0052ac1d     LEA        EBX,[EDI + 0xd]
//         0052ac20     MOV        EBP,0x10
//                               LAB_0052ac25                                                 XREF[1]:     0052ac3b(j)
//         0052ac25     PUSH       0x100
//         0052ac2a     PUSH       EBX
//         0052ac2b     PUSH       ESI
//         0052ac2c     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052ac31     ADD        ESP,0xc
//         0052ac34     ADD        EBX,0x100
//         0052ac3a     DEC        EBP
//         0052ac3b     JNZ        LAB_0052ac25
//                               LAB_0052ac3d                                                 XREF[1]:     0052ac1b(j)
//                              tscenaro.cpp:133 (19)
//         0052ac3d     FLD        float ptr [EDI + 0x1888]
//         0052ac43     FCOMP      float ptr [DAT_00577318]                         = D7h
//         0052ac49     FNSTSW     AX
//         0052ac4b     TEST       AH,0x41
//         0052ac4e     JNZ        LAB_0052ac6f
//                              tscenaro.cpp:207 (29)
//         0052ac50     LEA        EBX,[EDI + 0x1990]
//         0052ac56     MOV        EBP,0x10
//                               LAB_0052ac5b                                                 XREF[1]:     0052ac6b(j)
//         0052ac5b     PUSH       0x10
//         0052ac5d     PUSH       EBX
//         0052ac5e     PUSH       ESI
//         0052ac5f     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052ac64     ADD        ESP,0xc
//         0052ac67     ADD        EBX,0x10
//         0052ac6a     DEC        EBP
//         0052ac6b     JNZ        LAB_0052ac5b
//                              tscenaro.cpp:136 (2)
//         0052ac6d     JMP        LAB_0052acdc
//                               LAB_0052ac6f                                                 XREF[1]:     0052ac4e(j)
//                              tscenaro.cpp:207 (109)
//         0052ac6f     LEA        EBX,[EDI + 0x18cc]
//         0052ac75     LEA        EBP,[EDI + 0x1990]
//         0052ac7b     MOV        dword ptr [ESP + param_1],0x10
//                               LAB_0052ac83                                                 XREF[1]:     0052acda(j)
//         0052ac83     LEA        this,[EBX + 0x80]
//         0052ac89     PUSH       0x4
//         0052ac8b     PUSH       this
//         0052ac8c     PUSH       ESI
//         0052ac8d     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052ac92     ADD        ESP,0xc
//         0052ac95     PUSH       0x10
//         0052ac97     PUSH       EBP
//         0052ac98     PUSH       ESI
//         0052ac99     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052ac9e     ADD        ESP,0xc
//         0052aca1     PUSH       0x4
//         0052aca3     PUSH       EBX
//         0052aca4     PUSH       ESI
//         0052aca5     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052acaa     ADD        ESP,0xc
//         0052acad     LEA        EDX,[EBX + 0x40]
//         0052acb0     PUSH       0x4
//         0052acb2     PUSH       EDX
//         0052acb3     PUSH       ESI
//         0052acb4     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052acb9     ADD        ESP,0xc
//         0052acbc     LEA        EAX,[EBX + -0x40]
//         0052acbf     PUSH       0x4
//         0052acc1     PUSH       EAX
//         0052acc2     PUSH       ESI
//         0052acc3     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052acc8     MOV        EAX,dword ptr [ESP + param_1]
//         0052accc     ADD        ESP,0xc
//         0052accf     ADD        EBP,0x10
//         0052acd2     ADD        EBX,0x4
//         0052acd5     DEC        EAX
//         0052acd6     MOV        dword ptr [ESP + param_1],EAX
//         0052acda     JNZ        LAB_0052ac83
//                               LAB_0052acdc                                                 XREF[1]:     0052ac6d(j)
//                              tscenaro.cpp:146 (19)
//         0052acdc     FLD        float ptr [EDI + 0x1888]
//         0052ace2     FCOMP      float ptr [DAT_0057731c]                         = 5Ch    \
//         0052ace8     FNSTSW     AX
//         0052acea     TEST       AH,0x41
//         0052aced     JNZ        LAB_0052acff
//                              tscenaro.cpp:147 (16)
//         0052acef     LEA        this=>param_2,[ESP + 0x28]
//         0052acf3     PUSH       0x4
//         0052acf5     PUSH       this
//         0052acf6     PUSH       ESI
//         0052acf7     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052acfc     ADD        ESP,0xc
//                               LAB_0052acff                                                 XREF[1]:     0052aced(j)
//                              tscenaro.cpp:149 (18)
//         0052acff     LEA        EAX,[EDI + 0x1a90]
//         0052ad05     PUSH       0x18
//         0052ad07     PUSH       EAX
//         0052ad08     PUSH       ESI
//         0052ad09     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052ad0e     ADD        ESP,0xc
//                              tscenaro.cpp:150 (15)
//         0052ad11     LEA        EAX,[EDI + 0x4be8]
//         0052ad17     PUSH       0x4
//         0052ad19     PUSH       EAX
//         0052ad1a     PUSH       ESI
//         0052ad1b     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//                              tscenaro.cpp:152 (22)
//         0052ad20     FLD        float ptr [EDI + 0x1888]
//         0052ad26     FCOMP      float ptr [DAT_00577318]                         = D7h
//         0052ad2c     ADD        ESP,0xc
//         0052ad2f     FNSTSW     AX
//         0052ad31     TEST       AH,0x1
//         0052ad34     JNZ        LAB_0052ad6e
//                              tscenaro.cpp:154 (18)
//         0052ad36     LEA        EAX,[EDI + 0x5140]
//         0052ad3c     PUSH       0x4
//         0052ad3e     PUSH       EAX
//         0052ad3f     PUSH       ESI
//         0052ad40     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052ad45     ADD        ESP,0xc
//                              tscenaro.cpp:155 (18)
//         0052ad48     LEA        EAX,[EDI + 0x5144]
//         0052ad4e     PUSH       0x4
//         0052ad50     PUSH       EAX
//         0052ad51     PUSH       ESI
//         0052ad52     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052ad57     ADD        ESP,0xc
//                              tscenaro.cpp:156 (18)
//         0052ad5a     LEA        EAX,[EDI + 0x5148]
//         0052ad60     PUSH       0x4
//         0052ad62     PUSH       EAX
//         0052ad63     PUSH       ESI
//         0052ad64     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052ad69     ADD        ESP,0xc
//                              tscenaro.cpp:158 (2)
//         0052ad6c     JMP        LAB_0052ad8c
//                               LAB_0052ad6e                                                 XREF[1]:     0052ad34(j)
//                              tscenaro.cpp:160 (10)
//         0052ad6e     MOV        dword ptr [EDI + 0x5140],0x4
//                              tscenaro.cpp:161 (10)
//         0052ad78     MOV        dword ptr [EDI + 0x5144],0x384
//                              tscenaro.cpp:162 (10)
//         0052ad82     MOV        dword ptr [EDI + 0x5148],0x2328
//                               LAB_0052ad8c                                                 XREF[1]:     0052ad6c(j)
//                              tscenaro.cpp:166 (32)
//         0052ad8c     LEA        EDX,[EDI + 0x47a8]
//         0052ad92     PUSH       0x400
//         0052ad97     PUSH       EDX
//         0052ad98     PUSH       ESI
//         0052ad99     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052ad9e     ADD        ESP,0xc
//         0052ada1     LEA        EBX,[EDI + 0x1aa8]
//         0052ada7     MOV        EBP,0x10
//                               LAB_0052adac                                                 XREF[1]:     0052adc2(j)
//                              tscenaro.cpp:168 (24)
//         0052adac     PUSH       0x2d0
//         0052adb1     PUSH       EBX
//         0052adb2     PUSH       ESI
//         0052adb3     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052adb8     ADD        ESP,0xc
//         0052adbb     ADD        EBX,0x2d0
//         0052adc1     DEC        EBP
//         0052adc2     JNZ        LAB_0052adac
//                              tscenaro.cpp:170 (19)
//         0052adc4     FLD        float ptr [EDI + 0x1888]
//         0052adca     FCOMP      float ptr [DAT_0057731c]                         = 5Ch    \
//         0052add0     FNSTSW     AX
//         0052add2     TEST       AH,0x41
//         0052add5     JNZ        LAB_0052ade7
//                              tscenaro.cpp:171 (16)
//         0052add7     LEA        EAX=>param_2,[ESP + 0x28]
//         0052addb     PUSH       0x4
//         0052addd     PUSH       EAX
//         0052adde     PUSH       ESI
//         0052addf     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052ade4     ADD        ESP,0xc
//                               LAB_0052ade7                                                 XREF[1]:     0052add5(j)
//                              tscenaro.cpp:172 (12)
//         0052ade7     CMP        dword ptr [EDI + 0x1888],0x3f8147ae
//         0052adf1     JNZ        LAB_0052ae0d
//                              tscenaro.cpp:175 (6)
//         0052adf3     LEA        EBP,[EDI + 0x4ba8]
//                              tscenaro.cpp:207 (20)
//         0052adf9     MOV        EBX,0x10
//                               LAB_0052adfe                                                 XREF[1]:     0052ae0b(j)
//         0052adfe     PUSH       0x40
//         0052ae00     PUSH       EBP
//         0052ae01     PUSH       ESI
//         0052ae02     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052ae07     ADD        ESP,0xc
//         0052ae0a     DEC        EBX
//         0052ae0b     JNZ        LAB_0052adfe
//                               LAB_0052ae0d                                                 XREF[1]:     0052adf1(j)
//                              tscenaro.cpp:177 (19)
//         0052ae0d     FLD        float ptr [EDI + 0x1888]
//         0052ae13     FCOMP      float ptr [DAT_0057731c]                         = 5Ch    \
//         0052ae19     FNSTSW     AX
//         0052ae1b     TEST       AH,0x1
//         0052ae1e     JNZ        LAB_0052ae32
//                              tscenaro.cpp:179 (18)
//         0052ae20     LEA        this,[EDI + 0x4ba8]
//         0052ae26     PUSH       0x40
//         0052ae28     PUSH       this
//         0052ae29     PUSH       ESI
//         0052ae2a     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052ae2f     ADD        ESP,0xc
//                               LAB_0052ae32                                                 XREF[1]:     0052ae1e(j)
//                              tscenaro.cpp:182 (19)
//         0052ae32     FLD        float ptr [EDI + 0x1888]
//         0052ae38     FCOMP      float ptr [DAT_00577320]                         = 0Ah
//         0052ae3e     FNSTSW     AX
//         0052ae40     TEST       AH,0x41
//         0052ae43     JNZ        LAB_0052ae5a
//                              tscenaro.cpp:184 (21)
//         0052ae45     LEA        EDX,[EDI + 0x4bf4]
//         0052ae4b     PUSH       0x500
//         0052ae50     PUSH       EDX
//         0052ae51     PUSH       ESI
//         0052ae52     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052ae57     ADD        ESP,0xc
//                               LAB_0052ae5a                                                 XREF[1]:     0052ae43(j)
//                              tscenaro.cpp:187 (19)
//         0052ae5a     FLD        float ptr [EDI + 0x1888]
//         0052ae60     FCOMP      float ptr [DAT_00577324]                         = B8h
//         0052ae66     FNSTSW     AX
//         0052ae68     TEST       AH,0x41
//         0052ae6b     JNZ        LAB_0052aeb4
//                              tscenaro.cpp:189 (19)
//         0052ae6d     FLD        float ptr [EDI + 0x1888]
//         0052ae73     FCOMP      float ptr [DAT_00577328]                         = 29h    )
//         0052ae79     FNSTSW     AX
//         0052ae7b     TEST       AH,0x1
//         0052ae7e     JZ         LAB_0052aea2
//                              tscenaro.cpp:191 (18)
//         0052ae80     LEA        EAX,[EDI + 0x50f4]
//         0052ae86     PUSH       0x4
//         0052ae88     PUSH       EAX
//         0052ae89     PUSH       ESI
//         0052ae8a     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052ae8f     ADD        ESP,0xc
//                              tscenaro.cpp:192 (8)
//         0052ae92     XOR        EAX,EAX
//         0052ae94     MOV        dword ptr [EDI + 0x50f8],EAX
//                              tscenaro.cpp:193 (6)
//         0052ae9a     MOV        dword ptr [EDI + 0x50fc],EAX
//                              tscenaro.cpp:195 (2)
//         0052aea0     JMP        LAB_0052aeb4
//                               LAB_0052aea2                                                 XREF[1]:     0052ae7e(j)
//                              tscenaro.cpp:196 (18)
//         0052aea2     LEA        this,[EDI + 0x50f4]
//         0052aea8     PUSH       0xc
//         0052aeaa     PUSH       this
//         0052aeab     PUSH       ESI
//         0052aeac     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052aeb1     ADD        ESP,0xc
//                               LAB_0052aeb4                                                 XREF[2]:     0052ae6b(j), 0052aea0(j)
//                              tscenaro.cpp:199 (19)
//         0052aeb4     FLD        float ptr [EDI + 0x1888]
//         0052aeba     FCOMP      float ptr [DAT_0057732c]                         = 66h    f
//         0052aec0     FNSTSW     AX
//         0052aec2     TEST       AH,0x41
//         0052aec5     JNZ        LAB_0052aed9
//                              tscenaro.cpp:200 (18)
//         0052aec7     LEA        EDX,[EDI + 0x5100]
//         0052aecd     PUSH       0x40
//         0052aecf     PUSH       EDX
//         0052aed0     PUSH       ESI
//         0052aed1     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052aed6     ADD        ESP,0xc
//                               LAB_0052aed9                                                 XREF[1]:     0052aec5(j)
//                              tscenaro.cpp:202 (19)
//         0052aed9     FLD        float ptr [EDI + 0x1888]
//         0052aedf     FCOMP      float ptr [DAT_0057731c]                         = 5Ch    \
//         0052aee5     FNSTSW     AX
//         0052aee7     TEST       AH,0x41
//         0052aeea     JNZ        LAB_0052aefc
//                              tscenaro.cpp:203 (16)
//         0052aeec     LEA        EAX=>param_2,[ESP + 0x28]
//         0052aef0     PUSH       0x4
//         0052aef2     PUSH       EAX
//         0052aef3     PUSH       ESI
//         0052aef4     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         0052aef9     ADD        ESP,0xc
//                               LAB_0052aefc                                                 XREF[1]:     0052aeea(j)
//                              tscenaro.cpp:206 (2)
//         0052aefc     XOR        this,this
//                              tscenaro.cpp:207 (32)
//         0052aefe     MOV        EAX,EDI
//         0052af00     MOV        this,byte ptr [EDI + 0xc]
//         0052af03     MOV        dword ptr [EDI + 0x1a90],this
//         0052af09     MOV        this,dword ptr [ESP + local_c]
//         0052af0d     POP        EDI
//         0052af0e     POP        ESI
//         0052af0f     POP        EBP
//         0052af10     MOV        dword ptr FS:[0x0],this
//         0052af17     POP        EBX
//         0052af18     ADD        ESP,0x10
//         0052af1b     RET        0x8
//         0052af1e     ??         90h
//         0052af1f     NOP
}

void T_Scenario::save(int param_1) {
    /* TODO: Stub */
//                              void __thiscall save(T_Scenario * this, int param_1)
//              void              <VOID>         <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052af34(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     0052af27(W), 0052af5d(*), 0052afff(*), 0052b05a(*)
//              int               Stack[-0x8]:4  checksum
//                               ?save@T_Scenario@@UAEXH@Z                                    XREF[1]:     00577314(*)
//                               T_Scenario::save
//                              tscenaro.cpp:212 (7)
//         0052af20     PUSH       this
//         0052af21     PUSH       EBX
//         0052af22     PUSH       EBP
//         0052af23     PUSH       ESI
//         0052af24     PUSH       EDI
//         0052af25     MOV        EDI,this
//                              tscenaro.cpp:213 (8)
//         0052af27     MOV        dword ptr [ESP + local_4],0xffffff9d
//                              tscenaro.cpp:216 (5)
//         0052af2f     CALL       T_Scenario::WriteDisabledTechnologiesToMainSys   void WriteDisabledTechnologiesToMainSystem(T_
//                              tscenaro.cpp:217 (23)
//         0052af34     MOV        ESI,dword ptr [ESP + param_1]
//         0052af38     MOV        this,EDI
//         0052af3a     PUSH       ESI
//         0052af3b     CALL       RGE_Scenario::save                               void save(RGE_Scenario * this, int param_1)
//         0052af40     LEA        EBX,[EDI + 0x1990]
//         0052af46     MOV        EBP,0x10
//                               LAB_0052af4b                                                 XREF[1]:     0052af5b(j)
//                              tscenaro.cpp:225 (18)
//         0052af4b     PUSH       0x10
//         0052af4d     PUSH       EBX
//         0052af4e     PUSH       ESI
//         0052af4f     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0052af54     ADD        ESP,0xc
//         0052af57     ADD        EBX,0x10
//         0052af5a     DEC        EBP
//         0052af5b     JNZ        LAB_0052af4b
//                              tscenaro.cpp:231 (16)
//         0052af5d     LEA        EAX=>local_4,[ESP + 0x10]
//         0052af61     PUSH       0x4
//         0052af63     PUSH       EAX
//         0052af64     PUSH       ESI
//         0052af65     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0052af6a     ADD        ESP,0xc
//                              tscenaro.cpp:234 (18)
//         0052af6d     LEA        this,[EDI + 0x1a90]
//         0052af73     PUSH       0x18
//         0052af75     PUSH       this
//         0052af76     PUSH       ESI
//         0052af77     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0052af7c     ADD        ESP,0xc
//                              tscenaro.cpp:235 (18)
//         0052af7f     LEA        EDX,[EDI + 0x4be8]
//         0052af85     PUSH       0x4
//         0052af87     PUSH       EDX
//         0052af88     PUSH       ESI
//         0052af89     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0052af8e     ADD        ESP,0xc
//                              tscenaro.cpp:236 (18)
//         0052af91     LEA        EAX,[EDI + 0x5140]
//         0052af97     PUSH       0x4
//         0052af99     PUSH       EAX
//         0052af9a     PUSH       ESI
//         0052af9b     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0052afa0     ADD        ESP,0xc
//                              tscenaro.cpp:237 (18)
//         0052afa3     LEA        this,[EDI + 0x5144]
//         0052afa9     PUSH       0x4
//         0052afab     PUSH       this
//         0052afac     PUSH       ESI
//         0052afad     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0052afb2     ADD        ESP,0xc
//                              tscenaro.cpp:238 (18)
//         0052afb5     LEA        EDX,[EDI + 0x5148]
//         0052afbb     PUSH       0x4
//         0052afbd     PUSH       EDX
//         0052afbe     PUSH       ESI
//         0052afbf     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0052afc4     ADD        ESP,0xc
//                              tscenaro.cpp:240 (21)
//         0052afc7     LEA        EAX,[EDI + 0x47a8]
//         0052afcd     PUSH       0x400
//         0052afd2     PUSH       EAX
//         0052afd3     PUSH       ESI
//         0052afd4     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0052afd9     ADD        ESP,0xc
//                              tscenaro.cpp:255 (150)
//         0052afdc     LEA        EBX,[EDI + 0x1aa8]
//         0052afe2     MOV        EBP,0x10
//                               LAB_0052afe7                                                 XREF[1]:     0052affd(j)
//         0052afe7     PUSH       0x2d0
//         0052afec     PUSH       EBX
//         0052afed     PUSH       ESI
//         0052afee     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0052aff3     ADD        ESP,0xc
//         0052aff6     ADD        EBX,0x2d0
//         0052affc     DEC        EBP
//         0052affd     JNZ        LAB_0052afe7
//         0052afff     LEA        this=>local_4,[ESP + 0x10]
//         0052b003     PUSH       0x4
//         0052b005     PUSH       this
//         0052b006     PUSH       ESI
//         0052b007     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0052b00c     ADD        ESP,0xc
//         0052b00f     LEA        EDX,[EDI + 0x4ba8]
//         0052b015     PUSH       0x40
//         0052b017     PUSH       EDX
//         0052b018     PUSH       ESI
//         0052b019     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0052b01e     ADD        ESP,0xc
//         0052b021     LEA        EAX,[EDI + 0x4bf4]
//         0052b027     PUSH       0x500
//         0052b02c     PUSH       EAX
//         0052b02d     PUSH       ESI
//         0052b02e     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0052b033     ADD        ESP,0xc
//         0052b036     LEA        this,[EDI + 0x50f4]
//         0052b03c     PUSH       0xc
//         0052b03e     PUSH       this
//         0052b03f     PUSH       ESI
//         0052b040     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0052b045     ADD        ESP,0xc
//         0052b048     ADD        EDI,0x5100
//         0052b04e     PUSH       0x40
//         0052b050     PUSH       EDI
//         0052b051     PUSH       ESI
//         0052b052     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0052b057     ADD        ESP,0xc
//         0052b05a     LEA        EDX=>local_4,[ESP + 0x10]
//         0052b05e     PUSH       0x4
//         0052b060     PUSH       EDX
//         0052b061     PUSH       ESI
//         0052b062     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         0052b067     ADD        ESP,0xc
//         0052b06a     POP        EDI
//         0052b06b     POP        ESI
//         0052b06c     POP        EBP
//         0052b06d     POP        EBX
//         0052b06e     POP        this
//         0052b06f     RET        0x4
//         0052b072     ??         90h
//         0052b073     NOP
//         0052b074     NOP
//         0052b075     NOP
//         0052b076     NOP
//         0052b077     NOP
//         0052b078     NOP
//         0052b079     NOP
//         0052b07a     NOP
//         0052b07b     NOP
//         0052b07c     NOP
//         0052b07d     NOP
//         0052b07e     NOP
//         0052b07f     NOP
    return;
}

void T_Scenario::InitializePlayerValues() {
    /* TODO: Stub */
//                              void __thiscall InitializePlayerValues(T_Scenario * this)
//              void              <VOID>         <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0052b08f(W), 0052b0eb(R)
//                               ?InitializePlayerValues@T_Scenario@@QAEXXZ                   XREF[1]:     T_Scenario:0052aaf6(c)
//                               T_Scenario::InitializePlayerValues
//                              tscenaro.cpp:260 (5)
//         0052b080     PUSH       this
//         0052b081     PUSH       EBX
//         0052b082     PUSH       EBP
//         0052b083     PUSH       ESI
//         0052b084     PUSH       EDI
//                              tscenaro.cpp:261 (20)
//         0052b085     LEA        EAX,[ECX + this->_padding_]
//         0052b08b     XOR        EDI,EDI
//         0052b08d     XOR        EDX,EDX
//         0052b08f     MOV        dword ptr [ESP + local_4],EAX
//         0052b093     ADD        this,0x1998
//                               LAB_0052b099                                                 XREF[1]:     0052b0e9(j)
//                              tscenaro.cpp:264 (29)
//         0052b099     LEA        ESI,[this->_padding_ + -0x8]
//         0052b09c     XOR        EBX,EBX
//         0052b09e     MOV        EBP,ESI
//         0052b0a0     INC        EDX
//         0052b0a1     ADD        this,0x10
//         0052b0a4     ADD        EAX,0x4
//         0052b0a7     MOV        dword ptr [EBP],EBX
//         0052b0aa     CMP        EDX,0x10
//         0052b0ad     MOV        dword ptr [EBP + 0x4],EBX
//         0052b0b0     MOV        dword ptr [EBP + 0x8],EBX
//         0052b0b3     MOV        dword ptr [EBP + 0xc],EBX
//                              tscenaro.cpp:265 (3)
//         0052b0b6     MOV        dword ptr [EAX + 0x7c],EDI
//                              tscenaro.cpp:266 (2)
//         0052b0b9     MOV        dword ptr [ESI],EDI
//                              tscenaro.cpp:267 (7)
//         0052b0bb     MOV        dword ptr [this->_padding_ + -0x14],0xc8
//                              tscenaro.cpp:268 (7)
//         0052b0c2     MOV        dword ptr [this->_padding_ + -0x10],0xc8
//                              tscenaro.cpp:269 (7)
//         0052b0c9     MOV        dword ptr [this->_padding_ + -0xc],0x96
//                              tscenaro.cpp:270 (3)
//         0052b0d0     MOV        dword ptr [EAX + -0x4],EDI
//                              tscenaro.cpp:271 (3)
//         0052b0d3     MOV        dword ptr [EAX + 0x3c],EDX
//                              tscenaro.cpp:272 (7)
//         0052b0d6     MOV        dword ptr [EAX + -0x44],0x4
//                              tscenaro.cpp:273 (6)
//         0052b0dd     MOV        dword ptr [EAX + 0x32d8],EDI
//                              tscenaro.cpp:274 (8)
//         0052b0e3     MOV        dword ptr [EAX + 0x3830],EDI
//         0052b0e9     JL         LAB_0052b099
//                              tscenaro.cpp:276 (4)
//         0052b0eb     MOV        EAX,dword ptr [ESP + local_4]
//                              tscenaro.cpp:277 (12)
//         0052b0ef     POP        EDI
//         0052b0f0     POP        ESI
//         0052b0f1     POP        EBP
//         0052b0f2     MOV        dword ptr [EAX],0x1
//         0052b0f8     POP        EBX
//         0052b0f9     POP        this
//         0052b0fa     RET
//         0052b0fb     ??         90h
//         0052b0fc     NOP
//         0052b0fd     NOP
//         0052b0fe     NOP
//         0052b0ff     NOP
    return;
}

void T_Scenario::ClearDisabledTechnologies() {
    /* TODO: Stub */
//                              void __thiscall ClearDisabledTechnologies(T_Scenario * this)
//              void              <VOID>         <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//                               ?ClearDisabledTechnologies@T_Scenario@@AAEXXZ                XREF[2]:     T_Scenario:0052ab45(c),
//                               T_Scenario::ClearDisabledTechnologies                                     T_Scenario:0052abdf(c)
//                              tscenaro.cpp:282 (1)
//         0052b100     PUSH       EDI
//                              tscenaro.cpp:283 (6)
//         0052b101     LEA        EDI,[ECX + this->DisabledTechnology[0][0]]
//                              tscenaro.cpp:285 (12)
//         0052b107     MOV        this,0x140
//         0052b10c     MOV        EAX,0x1
//         0052b111     STOSD.REP  ES:EDI
//                              tscenaro.cpp:286 (2)
//         0052b113     POP        EDI
//         0052b114     RET
//         0052b115     ??         90h
//         0052b116     NOP
//         0052b117     NOP
//         0052b118     NOP
//         0052b119     NOP
//         0052b11a     NOP
//         0052b11b     NOP
//         0052b11c     NOP
//         0052b11d     NOP
//         0052b11e     NOP
//         0052b11f     NOP
    return;
}

void T_Scenario::InitializeAIInformation() {
    /* TODO: Stub */
//                              void __thiscall InitializeAIInformation(T_Scenario * this)
//              void              <VOID>         <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//                               ?InitializeAIInformation@T_Scenario@@QAEXXZ
//                               T_Scenario::InitializeAIInformation
//                              tscenaro.cpp:290 (5)
//         0052b120     PUSH       EBX
//         0052b121     PUSH       ESI
//         0052b122     PUSH       EDI
//         0052b123     MOV        EDI,this
//                              tscenaro.cpp:291 (2)
//         0052b125     XOR        ESI,ESI
//                               LAB_0052b127                                                 XREF[1]:     0052b167(j)
//                              tscenaro.cpp:294 (66)
//         0052b127     MOV        EAX,dword ptr [EDI + 0x8]
//         0052b12a     PUSH       -0x1
//         0052b12c     PUSH       offset DAT_fffffff8
//         0052b12e     PUSH       offset DAT_fffffff4
//         0052b130     MOV        this,dword ptr [EAX + 0x40]
//         0052b133     PUSH       ESI=>DAT_fffffff0
//         0052b134     MOV        EDX,dword ptr [this->_padding_ + ESI*0x4]
//         0052b137     MOV        this,EDI
//         0052b139     MOV        EBX,dword ptr [EDX]
//         0052b13b     CALL       RGE_Scenario::Get_player_AI                      char * Get_player_AI(RGE_Scenario * this, int
//         0052b140     PUSH       EAX
//         0052b141     PUSH       0x1
//         0052b143     PUSH       ESI
//         0052b144     MOV        this,EDI
//         0052b146     CALL       RGE_Scenario::Get_CityPlan                       char * Get_CityPlan(RGE_Scenario * this, int
//         0052b14b     PUSH       EAX
//         0052b14c     PUSH       0x1
//         0052b14e     PUSH       ESI
//         0052b14f     MOV        this,EDI
//         0052b151     CALL       RGE_Scenario::Get_BuildList                      char * Get_BuildList(RGE_Scenario * this, int
//         0052b156     PUSH       EAX
//         0052b157     MOV        EAX,dword ptr [EDI + 0x8]
//         0052b15a     MOV        this,dword ptr [EAX + 0x40]
//         0052b15d     MOV        this,dword ptr [this->_padding_ + ESI*0x4]
//         0052b160     CALL       dword ptr [EBX + 0x2c]
//         0052b163     INC        ESI
//         0052b164     CMP        ESI,0x10
//         0052b167     JL         LAB_0052b127
//                              tscenaro.cpp:295 (4)
//         0052b169     POP        EDI
//         0052b16a     POP        ESI
//         0052b16b     POP        EBX
//         0052b16c     RET
//         0052b16d     ??         90h
//         0052b16e     NOP
//         0052b16f     NOP
    return;
}

void T_Scenario::Set_victory_all_flag(int param_1) {
    /* TODO: Stub */
//                              void __thiscall Set_victory_all_flag(T_Scenario * this, int param_1)
//              void              <VOID>         <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052b170(R)
//                               ?Set_victory_all_flag@T_Scenario@@QAEXH@Z                    XREF[3]:     save_multi_victory_cond_in_scenari
//                               T_Scenario::Set_victory_all_flag                                          save_victory_cond_in_scenario:004a
//                                                                                                         new_game:0052f7bb(c)
//                              tscenaro.cpp:299 (8)
//         0052b170     MOV        EAX,dword ptr [ESP + param_1]
//         0052b174     TEST       EAX,EAX
//         0052b176     JGE        LAB_0052b17a
//                              tscenaro.cpp:301 (2)
//         0052b178     XOR        EAX,EAX
//                               LAB_0052b17a                                                 XREF[1]:     0052b176(j)
//                              tscenaro.cpp:302 (5)
//         0052b17a     CMP        EAX,0x1
//         0052b17d     JLE        LAB_0052b184
//                              tscenaro.cpp:303 (5)
//         0052b17f     MOV        EAX,0x1
//                               LAB_0052b184                                                 XREF[1]:     0052b17d(j)
//                              tscenaro.cpp:304 (6)
//         0052b184     MOV        dword ptr [ECX + this->victory_all_flag],EAX
//                              tscenaro.cpp:305 (3)
//         0052b18a     RET        0x4
//         0052b18d     ??         90h
//         0052b18e     NOP
//         0052b18f     NOP
    return;
}

int T_Scenario::Get_victory_all_flag() {
    /* TODO: Stub */
//                              int __thiscall Get_victory_all_flag(T_Scenario * this)
//              int               EAX:4          <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//                               ?Get_victory_all_flag@T_Scenario@@QAEHXZ                     XREF[2]:     load_victory_cond_from_scenario:00
//                               T_Scenario::Get_victory_all_flag                                          load_multi_victory_cond_from_scena
//                              tscenaro.cpp:309 (6)
//         0052b190     MOV        EAX,dword ptr [ECX + this->victory_all_flag]
//                              tscenaro.cpp:311 (1)
//         0052b196     RET
//         0052b197     ??         90h
//         0052b198     NOP
//         0052b199     NOP
//         0052b19a     NOP
//         0052b19b     NOP
//         0052b19c     NOP
//         0052b19d     NOP
//         0052b19e     NOP
//         0052b19f     NOP
    return 0;
}

void T_Scenario::SetMPVictory(int param_1) {
    /* TODO: Stub */
//                              void __thiscall SetMPVictory(T_Scenario * this, int param_1)
//              void              <VOID>         <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052b1a0(R)
//                               ?SetMPVictory@T_Scenario@@QAEXH@Z                            XREF[2]:     save_multi_victory_cond_in_scenari
//                               T_Scenario::SetMPVictory                                                  save_multi_victory_cond_in_scenari
//                              tscenaro.cpp:315 (4)
//         0052b1a0     MOV        EAX,dword ptr [ESP + param_1]
//                              tscenaro.cpp:317 (11)
//         0052b1a4     CMP        EAX,0x4
//         0052b1a7     MOV        dword ptr [ECX + this->mp_victory_type],EAX
//         0052b1ad     JZ         LAB_0052b1b3
//                              tscenaro.cpp:318 (4)
//         0052b1af     MOV        byte ptr [ECX + this->_padding_],0x1
//                               LAB_0052b1b3                                                 XREF[1]:     0052b1ad(j)
//                              tscenaro.cpp:319 (3)
//         0052b1b3     RET        0x4
//         0052b1b6     ??         90h
//         0052b1b7     NOP
//         0052b1b8     NOP
//         0052b1b9     NOP
//         0052b1ba     NOP
//         0052b1bb     NOP
//         0052b1bc     NOP
//         0052b1bd     NOP
//         0052b1be     NOP
//         0052b1bf     NOP
    return;
}

int T_Scenario::GetMPVictory() {
    /* TODO: Stub */
//                              int __thiscall GetMPVictory(T_Scenario * this)
//              int               EAX:4          <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//                               ?GetMPVictory@T_Scenario@@QAEHXZ                             XREF[2]:     load_multi_victory_cond_from_scena
//                               T_Scenario::GetMPVictory                                                  new_game:0052f935(c)
//                              tscenaro.cpp:323 (6)
//         0052b1c0     MOV        EAX,dword ptr [ECX + this->mp_victory_type]
//                              tscenaro.cpp:325 (1)
//         0052b1c6     RET
//         0052b1c7     ??         90h
//         0052b1c8     NOP
//         0052b1c9     NOP
//         0052b1ca     NOP
//         0052b1cb     NOP
//         0052b1cc     NOP
//         0052b1cd     NOP
//         0052b1ce     NOP
//         0052b1cf     NOP
    return 0;
}

void T_Scenario::SetVictoryScore(int param_1) {
    /* TODO: Stub */
//                              void __thiscall SetVictoryScore(T_Scenario * this, int param_1)
//              void              <VOID>         <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052b1d0(R)
//                               ?SetVictoryScore@T_Scenario@@QAEXH@Z                         XREF[2]:     save_multi_victory_cond_in_scenari
//                               T_Scenario::SetVictoryScore                                               save_multi_victory_cond_in_scenari
//                              tscenaro.cpp:329 (10)
//         0052b1d0     MOV        EAX,dword ptr [ESP + param_1]
//         0052b1d4     MOV        dword ptr [ECX + this->victory_score],EAX
//                              tscenaro.cpp:331 (3)
//         0052b1da     RET        0x4
//         0052b1dd     ??         90h
//         0052b1de     NOP
//         0052b1df     NOP
    return;
}

int T_Scenario::GetVictoryScore() {
    /* TODO: Stub */
//                              int __thiscall GetVictoryScore(T_Scenario * this)
//              int               EAX:4          <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//                               ?GetVictoryScore@T_Scenario@@QAEHXZ                          XREF[2]:     load_multi_victory_cond_from_scena
//                               T_Scenario::GetVictoryScore                                               new_game:0052f990(c)
//                              tscenaro.cpp:335 (6)
//         0052b1e0     MOV        EAX,dword ptr [ECX + this->victory_score]
//                              tscenaro.cpp:337 (1)
//         0052b1e6     RET
//         0052b1e7     ??         90h
//         0052b1e8     NOP
//         0052b1e9     NOP
//         0052b1ea     NOP
//         0052b1eb     NOP
//         0052b1ec     NOP
//         0052b1ed     NOP
//         0052b1ee     NOP
//         0052b1ef     NOP
    return 0;
}

void T_Scenario::SetVictoryTime(int param_1) {
    /* TODO: Stub */
//                              void __thiscall SetVictoryTime(T_Scenario * this, int param_1)
//              void              <VOID>         <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052b1f0(R)
//                               ?SetVictoryTime@T_Scenario@@QAEXH@Z                          XREF[2]:     save_multi_victory_cond_in_scenari
//                               T_Scenario::SetVictoryTime                                                save_multi_victory_cond_in_scenari
//                              tscenaro.cpp:341 (10)
//         0052b1f0     MOV        EAX,dword ptr [ESP + param_1]
//         0052b1f4     MOV        dword ptr [ECX + this->victory_time],EAX
//                              tscenaro.cpp:343 (3)
//         0052b1fa     RET        0x4
//         0052b1fd     ??         90h
//         0052b1fe     NOP
//         0052b1ff     NOP
    return;
}

int T_Scenario::GetVictoryTime() {
    /* TODO: Stub */
//                              int __thiscall GetVictoryTime(T_Scenario * this)
//              int               EAX:4          <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//                               ?GetVictoryTime@T_Scenario@@QAEHXZ                           XREF[2]:     load_multi_victory_cond_from_scena
//                               T_Scenario::GetVictoryTime                                                new_game:0052f96e(c)
//                              tscenaro.cpp:347 (6)
//         0052b200     MOV        EAX,dword ptr [ECX + this->victory_time]
//                              tscenaro.cpp:349 (1)
//         0052b206     RET
//         0052b207     ??         90h
//         0052b208     NOP
//         0052b209     NOP
//         0052b20a     NOP
//         0052b20b     NOP
//         0052b20c     NOP
//         0052b20d     NOP
//         0052b20e     NOP
//         0052b20f     NOP
    return 0;
}

void T_Scenario::SetSPWhich(int param_1) {
    /* TODO: Stub */
//                              void __thiscall SetSPWhich(T_Scenario * this, int param_1)
//              void              <VOID>         <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052b210(R)
//                               ?SetSPWhich@T_Scenario@@QAEXH@Z                              XREF[3]:     action:004ac0ec(c),
//                               T_Scenario::SetSPWhich                                                    load_victory_cond_from_scenario:00
//                                                                                                         any_sp_victory:0052c1f6(c)
//                              tscenaro.cpp:353 (8)
//         0052b210     MOV        EAX,dword ptr [ESP + param_1]
//         0052b214     TEST       EAX,EAX
//         0052b216     JGE        LAB_0052b21a
//                              tscenaro.cpp:355 (2)
//         0052b218     XOR        EAX,EAX
//                               LAB_0052b21a                                                 XREF[1]:     0052b216(j)
//                              tscenaro.cpp:356 (5)
//         0052b21a     CMP        EAX,0x10
//         0052b21d     JLE        LAB_0052b224
//                              tscenaro.cpp:357 (5)
//         0052b21f     MOV        EAX,0xf
//                               LAB_0052b224                                                 XREF[1]:     0052b21d(j)
//                              tscenaro.cpp:358 (6)
//         0052b224     MOV        dword ptr [ECX + this->which_player],EAX
//                              tscenaro.cpp:359 (3)
//         0052b22a     RET        0x4
//         0052b22d     ??         90h
//         0052b22e     NOP
//         0052b22f     NOP
    return;
}

int T_Scenario::GetSPWhich() {
    /* TODO: Stub */
//                              int __thiscall GetSPWhich(T_Scenario * this)
//              int               EAX:4          <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//                               ?GetSPWhich@T_Scenario@@QAEHXZ
//                               T_Scenario::GetSPWhich
//                              tscenaro.cpp:363 (6)
//         0052b230     MOV        EAX,dword ptr [ECX + this->which_player]
//                              tscenaro.cpp:365 (1)
//         0052b236     RET
//         0052b237     ??         90h
//         0052b238     NOP
//         0052b239     NOP
//         0052b23a     NOP
//         0052b23b     NOP
//         0052b23c     NOP
//         0052b23d     NOP
//         0052b23e     NOP
//         0052b23f     NOP
    return 0;
}

void T_Scenario::InitializeVictoryValues() {
    /* TODO: Stub */
//                              void __thiscall InitializeVictoryValues(T_Scenario * this)
//              void              <VOID>         <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//                               ?InitializeVictoryValues@T_Scenario@@QAEXXZ                  XREF[2]:     T_Scenario:0052aafd(c),
//                               T_Scenario::InitializeVictoryValues                                       T_Scenario:0052abd1(c)
//                              tscenaro.cpp:370 (19)
//         0052b240     XOR        EAX,EAX
//         0052b242     PUSH       EDI
//         0052b243     MOV        dword ptr [ECX + this->victory.MP_Conquest],0x1
//         0052b24d     MOV        dword ptr [ECX + this+0x1a94],EAX
//                              tscenaro.cpp:374 (6)
//         0052b253     MOV        dword ptr [ECX + this+0x1a98],EAX
//                              tscenaro.cpp:375 (6)
//         0052b259     MOV        dword ptr [ECX + this+0x1a9c],EAX
//                              tscenaro.cpp:376 (6)
//         0052b25f     MOV        dword ptr [ECX + this+0x1aa0],EAX
//                              tscenaro.cpp:377 (12)
//         0052b265     MOV        dword ptr [ECX + this+0x1aa4],EAX
//         0052b26b     LEA        EDI,[ECX + this->sp_victory[0][0].ObjType]
//                              tscenaro.cpp:383 (7)
//         0052b271     MOV        this,0xb40
//         0052b276     STOSD.REP  ES:EDI
//                              tscenaro.cpp:384 (2)
//         0052b278     POP        EDI
//         0052b279     RET
//         0052b27a     ??         90h
//         0052b27b     NOP
//         0052b27c     NOP
//         0052b27d     NOP
//         0052b27e     NOP
//         0052b27f     NOP
    return;
}

void T_Scenario::ClearSPVictoryCondition(int param_1) {
    /* TODO: Stub */
//                              void __thiscall ClearSPVictoryCondition(T_Scenario * this, int param
//              void              <VOID>         <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052b284(R)
//                               ?ClearSPVictoryCondition@T_Scenario@@QAEXH@Z                 XREF[1]:     save_victory_cond_in_scenario:004a
//                               T_Scenario::ClearSPVictoryCondition
//                              tscenaro.cpp:388 (4)
//         0052b280     MOV        EDX,this
//         0052b282     PUSH       ESI
//         0052b283     PUSH       EDI
//                              tscenaro.cpp:389 (38)
//         0052b284     MOV        EDI,dword ptr [ESP + param_1]
//         0052b288     MOV        ESI,dword ptr [EDX + 0x4bf0]
//         0052b28e     MOV        this,0xf
//         0052b293     XOR        EAX,EAX
//         0052b295     LEA        ESI,[ESI + ESI*0x2]
//         0052b298     LEA        ESI,[EDI + ESI*0x4]
//         0052b29b     LEA        ESI,[ESI + ESI*0x2]
//         0052b29e     LEA        ESI,[ESI + ESI*0x4]
//         0052b2a1     LEA        EDI,[EDX + ESI*0x4 + 0x1aa8]
//         0052b2a8     STOSD.REP  ES:EDI
//                              tscenaro.cpp:390 (5)
//         0052b2aa     POP        EDI
//         0052b2ab     POP        ESI
//         0052b2ac     RET        0x4
//         0052b2af     ??         90h
    return;
}

void T_Scenario::InitializeFriendlinessValues() {
    /* TODO: Stub */
//                              void __thiscall InitializeFriendlinessValues(T_Scenario * this)
//              void              <VOID>         <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//                               ?InitializeFriendlinessValues@T_Scenario@@QAEXXZ             XREF[2]:     T_Scenario:0052ab04(c),
//                               T_Scenario::InitializeFriendlinessValues                                  T_Scenario:0052abd8(c)
//                              tscenaro.cpp:396 (1)
//         0052b2b0     PUSH       EDI
//                              tscenaro.cpp:397 (6)
//         0052b2b1     LEA        EDI,[ECX + this->Opponent[0].Attitude[0]]
//                              tscenaro.cpp:401 (12)
//         0052b2b7     MOV        this,0x100
//         0052b2bc     MOV        EAX,0x3
//         0052b2c1     STOSD.REP  ES:EDI
//                              tscenaro.cpp:404 (2)
//         0052b2c3     POP        EDI
//         0052b2c4     RET
//         0052b2c5     ??         90h
//         0052b2c6     NOP
//         0052b2c7     NOP
//         0052b2c8     NOP
//         0052b2c9     NOP
//         0052b2ca     NOP
//         0052b2cb     NOP
//         0052b2cc     NOP
//         0052b2cd     NOP
//         0052b2ce     NOP
//         0052b2cf     NOP
    return;
}

void T_Scenario::Set_player_attitude(int param_1, int param_2, int param_3) {
    /* TODO: Stub */
//                              void __thiscall Set_player_attitude(T_Scenario * this, int param_1,
//              void              <VOID>         <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052b2e3(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0052b2f0(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     0052b2d1(R)
//                               ?Set_player_attitude@T_Scenario@@QAEXHHH@Z                   XREF[1]:     save_diplomacy_in_scenario:004aed1
//                               T_Scenario::Set_player_attitude
//                              tscenaro.cpp:409 (1)
//         0052b2d0     PUSH       ESI
//                              tscenaro.cpp:410 (18)
//         0052b2d1     MOV        ESI,dword ptr [ESP + param_3]
//         0052b2d5     CMP        ESI,0x1
//         0052b2d8     JZ         LAB_0052b2e3
//         0052b2da     CMP        ESI,0x3
//         0052b2dd     JZ         LAB_0052b2e3
//         0052b2df     TEST       ESI,ESI
//         0052b2e1     JNZ        LAB_0052b309
//                               LAB_0052b2e3                                                 XREF[2]:     0052b2d8(j), 0052b2dd(j)
//                              tscenaro.cpp:413 (13)
//         0052b2e3     MOV        EAX,dword ptr [ESP + param_1]
//         0052b2e7     TEST       EAX,EAX
//         0052b2e9     JL         LAB_0052b309
//         0052b2eb     CMP        EAX,0x10
//         0052b2ee     JGE        LAB_0052b309
//                              tscenaro.cpp:416 (13)
//         0052b2f0     MOV        EDX,dword ptr [ESP + param_2]
//         0052b2f4     TEST       EDX,EDX
//         0052b2f6     JL         LAB_0052b309
//         0052b2f8     CMP        EDX,0x10
//         0052b2fb     JGE        LAB_0052b309
//                              tscenaro.cpp:419 (12)
//         0052b2fd     SHL        EAX,0x4
//         0052b300     ADD        EAX,EDX
//         0052b302     MOV        dword ptr [ECX + EAX*0x4 + this->Opponent[0].A
//                               LAB_0052b309                                                 XREF[5]:     0052b2e1(j), 0052b2e9(j),
//                                                                                                         0052b2ee(j), 0052b2f6(j),
//                                                                                                         0052b2fb(j)
//                              tscenaro.cpp:420 (4)
//         0052b309     POP        ESI
//         0052b30a     RET        0xc
//         0052b30d     ??         90h
//         0052b30e     NOP
//         0052b30f     NOP
    return;
}

int T_Scenario::Get_player_attitude(int param_1, int param_2) {
    /* TODO: Stub */
//                              int __thiscall Get_player_attitude(T_Scenario * this, int param_1, i
//              int               EAX:4          <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052b310(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0052b31d(R)
//                               ?Get_player_attitude@T_Scenario@@QAEHHH@Z                    XREF[1]:     load_diplomacy_from_scenario:004ae
//                               T_Scenario::Get_player_attitude
//                              tscenaro.cpp:425 (13)
//         0052b310     MOV        EAX,dword ptr [ESP + param_1]
//         0052b314     TEST       EAX,EAX
//         0052b316     JL         LAB_0052b33a
//         0052b318     CMP        EAX,0x10
//         0052b31b     JGE        LAB_0052b33a
//                              tscenaro.cpp:429 (13)
//         0052b31d     MOV        EDX,dword ptr [ESP + param_2]
//         0052b321     TEST       EDX,EDX
//         0052b323     JL         LAB_0052b33a
//         0052b325     CMP        EDX,0x10
//         0052b328     JGE        LAB_0052b33a
//                              tscenaro.cpp:432 (13)
//         0052b32a     SHL        EAX,0x6
//         0052b32d     LEA        EAX,[ECX + EAX*0x1 + this->Opponent[0].Attitud
//         0052b334     MOV        EAX,dword ptr [EAX + EDX*0x4]
//                              tscenaro.cpp:433 (3)
//         0052b337     RET        0x8
//                               LAB_0052b33a                                                 XREF[4]:     0052b316(j), 0052b31b(j),
//                                                                                                         0052b323(j), 0052b328(j)
//                              tscenaro.cpp:427 (3)
//         0052b33a     OR         EAX,0xffffffff
//                              tscenaro.cpp:433 (3)
//         0052b33d     RET        0x8
    return 0;
}

void T_Scenario::Set_player_Gold(int param_1, int param_2) {
    /* TODO: Stub */
//                              void __thiscall Set_player_Gold(T_Scenario * this, int param_1, int
//              void              <VOID>         <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052b340(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0052b34d(R)
//                               ?Set_player_Gold@T_Scenario@@QAEXHH@Z                        XREF[1]:     set_player:004aaf43(c)
//                               T_Scenario::Set_player_Gold
//                              tscenaro.cpp:438 (13)
//         0052b340     MOV        EAX,dword ptr [ESP + param_1]
//         0052b344     TEST       EAX,EAX
//         0052b346     JL         LAB_0052b35c
//         0052b348     CMP        EAX,0x10
//         0052b34b     JGE        LAB_0052b35c
//                              tscenaro.cpp:441 (15)
//         0052b34d     MOV        EDX,dword ptr [ESP + param_2]
//         0052b351     ADD        EAX,0x199
//         0052b356     SHL        EAX,0x4
//         0052b359     MOV        dword ptr [EAX + this->_padding_*0x1],EDX
//                               LAB_0052b35c                                                 XREF[2]:     0052b346(j), 0052b34b(j)
//                              tscenaro.cpp:442 (3)
//         0052b35c     RET        0x8
//         0052b35f     ??         90h
    return;
}

void T_Scenario::Set_player_Wood(int param_1, int param_2) {
    /* TODO: Stub */
//                              void __thiscall Set_player_Wood(T_Scenario * this, int param_1, int
//              void              <VOID>         <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052b360(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0052b36d(R)
//                               ?Set_player_Wood@T_Scenario@@QAEXHH@Z                        XREF[1]:     set_player:004aaeb9(c)
//                               T_Scenario::Set_player_Wood
//                              tscenaro.cpp:446 (13)
//         0052b360     MOV        EAX,dword ptr [ESP + param_1]
//         0052b364     TEST       EAX,EAX
//         0052b366     JL         LAB_0052b37b
//         0052b368     CMP        EAX,0x10
//         0052b36b     JGE        LAB_0052b37b
//                              tscenaro.cpp:449 (14)
//         0052b36d     MOV        EDX,dword ptr [ESP + param_2]
//         0052b371     SHL        EAX,0x4
//         0052b374     MOV        dword ptr [EAX + this->_padding_*0x1 + 0x1994]
//                               LAB_0052b37b                                                 XREF[2]:     0052b366(j), 0052b36b(j)
//                              tscenaro.cpp:450 (3)
//         0052b37b     RET        0x8
//         0052b37e     ??         90h
//         0052b37f     NOP
    return;
}

void T_Scenario::Set_player_Food(int param_1, int param_2) {
    /* TODO: Stub */
//                              void __thiscall Set_player_Food(T_Scenario * this, int param_1, int
//              void              <VOID>         <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052b380(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0052b38d(R)
//                               ?Set_player_Food@T_Scenario@@QAEXHH@Z                        XREF[1]:     set_player:004aae75(c)
//                               T_Scenario::Set_player_Food
//                              tscenaro.cpp:454 (13)
//         0052b380     MOV        EAX,dword ptr [ESP + param_1]
//         0052b384     TEST       EAX,EAX
//         0052b386     JL         LAB_0052b39b
//         0052b388     CMP        EAX,0x10
//         0052b38b     JGE        LAB_0052b39b
//                              tscenaro.cpp:457 (14)
//         0052b38d     MOV        EDX,dword ptr [ESP + param_2]
//         0052b391     SHL        EAX,0x4
//         0052b394     MOV        dword ptr [EAX + this->_padding_*0x1 + 0x1998]
//                               LAB_0052b39b                                                 XREF[2]:     0052b386(j), 0052b38b(j)
//                              tscenaro.cpp:458 (3)
//         0052b39b     RET        0x8
//         0052b39e     ??         90h
//         0052b39f     NOP
    return;
}

void T_Scenario::Set_player_Stone(int param_1, int param_2) {
    /* TODO: Stub */
//                              void __thiscall Set_player_Stone(T_Scenario * this, int param_1, int
//              void              <VOID>         <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052b3a0(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0052b3ad(R)
//                               ?Set_player_Stone@T_Scenario@@QAEXHH@Z                       XREF[1]:     set_player:004aaefe(c)
//                               T_Scenario::Set_player_Stone
//                              tscenaro.cpp:462 (13)
//         0052b3a0     MOV        EAX,dword ptr [ESP + param_1]
//         0052b3a4     TEST       EAX,EAX
//         0052b3a6     JL         LAB_0052b3bb
//         0052b3a8     CMP        EAX,0x10
//         0052b3ab     JGE        LAB_0052b3bb
//                              tscenaro.cpp:465 (14)
//         0052b3ad     MOV        EDX,dword ptr [ESP + param_2]
//         0052b3b1     SHL        EAX,0x4
//         0052b3b4     MOV        dword ptr [EAX + this->_padding_*0x1 + 0x199c]
//                               LAB_0052b3bb                                                 XREF[2]:     0052b3a6(j), 0052b3ab(j)
//                              tscenaro.cpp:466 (3)
//         0052b3bb     RET        0x8
//         0052b3be     ??         90h
//         0052b3bf     NOP
    return;
}

void T_Scenario::Set_player_Info(int param_1, Player_Start_Info* param_2) {
    /* TODO: Stub */
//                              void __thiscall Set_player_Info(T_Scenario * this, int param_1, Play
//              void              <VOID>         <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052b3c0(R)
//              Player_Start_I    Stack[0x8]:4   param_2                   XREF[1]:     0052b3d7(R)
//                               ?Set_player_Info@T_Scenario@@QAEXHPAUPlayer_Start_Info@@@Z
//                               T_Scenario::Set_player_Info
//                              tscenaro.cpp:470 (13)
//         0052b3c0     MOV        EAX,dword ptr [ESP + param_1]
//         0052b3c4     TEST       EAX,EAX
//         0052b3c6     JL         LAB_0052b3f1
//         0052b3c8     CMP        EAX,0x10
//         0052b3cb     JGE        LAB_0052b3f1
//                              tscenaro.cpp:473 (36)
//         0052b3cd     ADD        EAX,0x199
//         0052b3d2     SHL        EAX,0x4
//         0052b3d5     ADD        EAX,this
//         0052b3d7     MOV        this,dword ptr [ESP + param_2]
//         0052b3db     MOV        EDX,dword ptr [this->_padding_]
//         0052b3dd     MOV        dword ptr [EAX],EDX
//         0052b3df     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0052b3e2     MOV        dword ptr [EAX + 0x4],EDX
//         0052b3e5     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0052b3e8     MOV        dword ptr [EAX + 0x8],EDX
//         0052b3eb     MOV        this,dword ptr [ECX + this->_padding_]
//         0052b3ee     MOV        dword ptr [EAX + 0xc],this
//                               LAB_0052b3f1                                                 XREF[2]:     0052b3c6(j), 0052b3cb(j)
//                              tscenaro.cpp:474 (3)
//         0052b3f1     RET        0x8
//         0052b3f4     ??         90h
//         0052b3f5     NOP
//         0052b3f6     NOP
//         0052b3f7     NOP
//         0052b3f8     NOP
//         0052b3f9     NOP
//         0052b3fa     NOP
//         0052b3fb     NOP
//         0052b3fc     NOP
//         0052b3fd     NOP
//         0052b3fe     NOP
//         0052b3ff     NOP
    return;
}

void T_Scenario::Set_Multi_Conquest(int param_1) {
    /* TODO: Stub */
//                              void __thiscall Set_Multi_Conquest(T_Scenario * this, int param_1)
//              void              <VOID>         <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052b400(R)
//                               ?Set_Multi_Conquest@T_Scenario@@QAEXH@Z                      XREF[8]:     action:004accc5(c),
//                               T_Scenario::Set_Multi_Conquest                                            save_multi_victory_cond_in_scenari
//                                                                                                         save_victory_cond_in_scenario:004a
//                                                                                                         new_game:0052f7c4(c),
//                                                                                                         new_game:0052f82d(c),
//                                                                                                         new_game:0052f843(c),
//                                                                                                         new_game:0052f859(c),
//                                                                                                         new_game:0052f86f(c)
//                              tscenaro.cpp:479 (8)
//         0052b400     MOV        EAX,dword ptr [ESP + param_1]
//         0052b404     TEST       EAX,EAX
//         0052b406     JZ         LAB_0052b41c
//                              tscenaro.cpp:483 (12)
//         0052b408     PUSH       0x1
//         0052b40a     MOV        dword ptr [ECX + this->victory.MP_Conquest],0x1
//                              tscenaro.cpp:488 (5)
//         0052b414     CALL       RGE_Scenario::Set_conquest_victory               void Set_conquest_victory(RGE_Scenario * this
//                              tscenaro.cpp:490 (3)
//         0052b419     RET        0x4
//                               LAB_0052b41c                                                 XREF[1]:     0052b406(j)
//                              tscenaro.cpp:488 (17)
//         0052b41c     PUSH       0x0
//         0052b41e     MOV        dword ptr [ECX + this->victory.MP_Conquest],0x0
//         0052b428     CALL       RGE_Scenario::Set_conquest_victory               void Set_conquest_victory(RGE_Scenario * this
//                              tscenaro.cpp:490 (3)
//         0052b42d     RET        0x4
    return;
}

void T_Scenario::Set_Multi_Ruins(int param_1) {
    /* TODO: Stub */
//                              void __thiscall Set_Multi_Ruins(T_Scenario * this, int param_1)
//              void              <VOID>         <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052b430(R)
//                               ?Set_Multi_Ruins@T_Scenario@@QAEXH@Z                         XREF[3]:     save_multi_victory_cond_in_scenari
//                               T_Scenario::Set_Multi_Ruins                                               new_game:0052f7cd(c),
//                                                                                                         new_game:0052f87a(c)
//                              tscenaro.cpp:494 (10)
//         0052b430     MOV        EAX,dword ptr [ESP + param_1]
//         0052b434     MOV        dword ptr [ECX + this+0x1a94],EAX
//                              tscenaro.cpp:496 (3)
//         0052b43a     RET        0x4
//         0052b43d     ??         90h
//         0052b43e     NOP
//         0052b43f     NOP
    return;
}

void T_Scenario::Set_Multi_Artifacts(int param_1) {
    /* TODO: Stub */
//                              void __thiscall Set_Multi_Artifacts(T_Scenario * this, int param_1)
//              void              <VOID>         <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052b440(R)
//                               ?Set_Multi_Artifacts@T_Scenario@@QAEXH@Z                     XREF[3]:     save_multi_victory_cond_in_scenari
//                               T_Scenario::Set_Multi_Artifacts                                           new_game:0052f7d6(c),
//                                                                                                         new_game:0052f885(c)
//                              tscenaro.cpp:500 (10)
//         0052b440     MOV        EAX,dword ptr [ESP + param_1]
//         0052b444     MOV        dword ptr [ECX + this+0x1a98],EAX
//                              tscenaro.cpp:502 (3)
//         0052b44a     RET        0x4
//         0052b44d     ??         90h
//         0052b44e     NOP
//         0052b44f     NOP
    return;
}

void T_Scenario::Set_Multi_Discoveries(int param_1) {
    /* TODO: Stub */
//                              void __thiscall Set_Multi_Discoveries(T_Scenario * this, int param_1)
//              void              <VOID>         <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052b450(R)
//                               ?Set_Multi_Discoveries@T_Scenario@@QAEXH@Z                   XREF[3]:     save_multi_victory_cond_in_scenari
//                               T_Scenario::Set_Multi_Discoveries                                         new_game:0052f7df(c),
//                                                                                                         new_game:0052f890(c)
//                              tscenaro.cpp:506 (10)
//         0052b450     MOV        EAX,dword ptr [ESP + param_1]
//         0052b454     MOV        dword ptr [ECX + this+0x1a9c],EAX
//                              tscenaro.cpp:508 (3)
//         0052b45a     RET        0x4
//         0052b45d     ??         90h
//         0052b45e     NOP
//         0052b45f     NOP
    return;
}

void T_Scenario::Set_Multi_Exploration(int param_1) {
    /* TODO: Stub */
//                              void __thiscall Set_Multi_Exploration(T_Scenario * this, int param_1)
//              void              <VOID>         <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052b460(R)
//                               ?Set_Multi_Exploration@T_Scenario@@QAEXH@Z                   XREF[3]:     save_multi_victory_cond_in_scenari
//                               T_Scenario::Set_Multi_Exploration                                         new_game:0052f7e8(c),
//                                                                                                         new_game:0052f89b(c)
//                              tscenaro.cpp:512 (10)
//         0052b460     MOV        EAX,dword ptr [ESP + param_1]
//         0052b464     MOV        dword ptr [ECX + this+0x1aa0],EAX
//                              tscenaro.cpp:514 (3)
//         0052b46a     RET        0x4
//         0052b46d     ??         90h
//         0052b46e     NOP
//         0052b46f     NOP
    return;
}

void T_Scenario::Set_Multi_Gold(int param_1) {
    /* TODO: Stub */
//                              void __thiscall Set_Multi_Gold(T_Scenario * this, int param_1)
//              void              <VOID>         <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052b470(R)
//                               ?Set_Multi_Gold@T_Scenario@@QAEXH@Z                          XREF[4]:     save_multi_victory_cond_in_scenari
//                               T_Scenario::Set_Multi_Gold                                                save_multi_victory_cond_in_scenari
//                                                                                                         new_game:0052f7f1(c),
//                                                                                                         new_game:0052f8a6(c)
//                              tscenaro.cpp:518 (10)
//         0052b470     MOV        EAX,dword ptr [ESP + param_1]
//         0052b474     MOV        dword ptr [ECX + this+0x1aa4],EAX
//                              tscenaro.cpp:520 (3)
//         0052b47a     RET        0x4
//         0052b47d     ??         90h
//         0052b47e     NOP
//         0052b47f     NOP
    return;
}

void T_Scenario::SetSPRectangle(int param_1, float param_2, float param_3, float param_4, float param_5) {
    /* TODO: Stub */
//                              void __thiscall SetSPRectangle(T_Scenario * this, int param_1, float
//              void              <VOID>         <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052b48d(R)
//              float             Stack[0x8]:4   param_2                   XREF[1]:     0052b486(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     0052b4a4(R)
//              float             Stack[0x10]:4  param_4                   XREF[1]:     0052b4c1(R)
//              float             Stack[0x14]:4  param_5                   XREF[1]:     0052b4de(R)
//                               ?SetSPRectangle@T_Scenario@@QAEXHMMMM@Z                      XREF[2]:     save_victory_cond_in_scenario:004a
//                               T_Scenario::SetSPRectangle                                                save_victory_cond_in_scenario:004a
//                              tscenaro.cpp:524 (30)
//         0052b480     MOV        EAX,dword ptr [ECX + this->which_player]
//         0052b486     FLD        float ptr [ESP + param_2]
//         0052b48a     LEA        EDX,[EAX + EAX*0x2]
//         0052b48d     MOV        EAX,dword ptr [ESP + param_1]
//         0052b491     LEA        EDX,[EAX + EDX*0x4 + 0x72]
//         0052b495     LEA        EDX,[EDX + EDX*0x2]
//         0052b498     LEA        EDX,[EDX + EDX*0x4]
//         0052b49b     FSTP       float ptr [this->_padding_ + EDX*0x4]
//                              tscenaro.cpp:526 (29)
//         0052b49e     MOV        EDX,dword ptr [ECX + this->which_player]
//         0052b4a4     FLD        float ptr [ESP + param_3]
//         0052b4a8     LEA        EDX,[EDX + EDX*0x2]
//         0052b4ab     LEA        EDX,[EAX + EDX*0x4]
//         0052b4ae     LEA        EDX,[EDX + EDX*0x2]
//         0052b4b1     LEA        EDX,[EDX + EDX*0x4]
//         0052b4b4     FSTP       float ptr [ECX + EDX*0x4 + this+0x1abc]
//                              tscenaro.cpp:527 (29)
//         0052b4bb     MOV        EDX,dword ptr [ECX + this->which_player]
//         0052b4c1     FLD        float ptr [ESP + param_4]
//         0052b4c5     LEA        EDX,[EDX + EDX*0x2]
//         0052b4c8     LEA        EDX,[EAX + EDX*0x4]
//         0052b4cb     LEA        EDX,[EDX + EDX*0x2]
//         0052b4ce     LEA        EDX,[EDX + EDX*0x4]
//         0052b4d1     FSTP       float ptr [ECX + EDX*0x4 + this+0x1ac0]
//                              tscenaro.cpp:528 (29)
//         0052b4d8     MOV        EDX,dword ptr [ECX + this->which_player]
//         0052b4de     FLD        float ptr [ESP + param_5]
//         0052b4e2     LEA        EDX,[EDX + EDX*0x2]
//         0052b4e5     LEA        EAX,[EAX + EDX*0x4]
//         0052b4e8     LEA        EAX,[EAX + EAX*0x2]
//         0052b4eb     LEA        EAX,[EAX + EAX*0x4]
//         0052b4ee     FSTP       float ptr [ECX + EAX*0x4 + this+0x1ac4]
//                              tscenaro.cpp:529 (3)
//         0052b4f5     RET        0x14
//         0052b4f8     ??         90h
//         0052b4f9     NOP
//         0052b4fa     NOP
//         0052b4fb     NOP
//         0052b4fc     NOP
//         0052b4fd     NOP
//         0052b4fe     NOP
//         0052b4ff     NOP
    return;
}

void T_Scenario::SetSPObjectType(int param_1, int param_2) {
    /* TODO: Stub */
//                              void __thiscall SetSPObjectType(T_Scenario * this, int param_1, int
//              void              <VOID>         <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052b506(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0052b510(R)
//                               ?SetSPObjectType@T_Scenario@@QAEXHH@Z                        XREF[4]:     save_victory_cond_in_scenario:004a
//                               T_Scenario::SetSPObjectType                                               save_victory_cond_in_scenario:004a
//                                                                                                         save_victory_cond_in_scenario:004a
//                                                                                                         save_victory_cond_in_scenario:004a
//                              tscenaro.cpp:533 (33)
//         0052b500     MOV        EAX,dword ptr [ECX + this->which_player]
//         0052b506     MOV        EDX,dword ptr [ESP + param_1]
//         0052b50a     LEA        EAX,[EAX + EAX*0x2]
//         0052b50d     LEA        EAX,[EDX + EAX*0x4]
//         0052b510     MOV        EDX,dword ptr [ESP + param_2]
//         0052b514     LEA        EAX,[EAX + EAX*0x2]
//         0052b517     LEA        EAX,[EAX + EAX*0x4]
//         0052b51a     MOV        dword ptr [ECX + EAX*0x4 + this->sp_victory[0]
//                              tscenaro.cpp:535 (3)
//         0052b521     RET        0x8
//         0052b524     ??         90h
//         0052b525     NOP
//         0052b526     NOP
//         0052b527     NOP
//         0052b528     NOP
//         0052b529     NOP
//         0052b52a     NOP
//         0052b52b     NOP
//         0052b52c     NOP
//         0052b52d     NOP
//         0052b52e     NOP
//         0052b52f     NOP
    return;
}

void T_Scenario::SetSPPlayerID(int param_1, int param_2) {
    /* TODO: Stub */
//                              void __thiscall SetSPPlayerID(T_Scenario * this, int param_1, int pa
//              void              <VOID>         <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052b536(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0052b540(R)
//                               ?SetSPPlayerID@T_Scenario@@QAEXHH@Z                          XREF[3]:     save_victory_cond_in_scenario:004a
//                               T_Scenario::SetSPPlayerID                                                 save_victory_cond_in_scenario:004a
//                                                                                                         save_victory_cond_in_scenario:004a
//                              tscenaro.cpp:539 (33)
//         0052b530     MOV        EAX,dword ptr [ECX + this->which_player]
//         0052b536     MOV        EDX,dword ptr [ESP + param_1]
//         0052b53a     LEA        EAX,[EAX + EAX*0x2]
//         0052b53d     LEA        EAX,[EDX + EAX*0x4]
//         0052b540     MOV        EDX,dword ptr [ESP + param_2]
//         0052b544     LEA        EAX,[EAX + EAX*0x2]
//         0052b547     LEA        EAX,[EAX + EAX*0x4]
//         0052b54a     MOV        dword ptr [ECX + EAX*0x4 + this+0x1ab0],EDX
//                              tscenaro.cpp:541 (3)
//         0052b551     RET        0x8
//         0052b554     ??         90h
//         0052b555     NOP
//         0052b556     NOP
//         0052b557     NOP
//         0052b558     NOP
//         0052b559     NOP
//         0052b55a     NOP
//         0052b55b     NOP
//         0052b55c     NOP
//         0052b55d     NOP
//         0052b55e     NOP
//         0052b55f     NOP
    return;
}

void T_Scenario::SetSPAllFlag(int param_1, int param_2) {
    /* TODO: Stub */
//                              void __thiscall SetSPAllFlag(T_Scenario * this, int param_1, int par
//              void              <VOID>         <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052b566(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0052b570(R)
//                               ?SetSPAllFlag@T_Scenario@@QAEXHH@Z                           XREF[1]:     save_victory_cond_in_scenario:004a
//                               T_Scenario::SetSPAllFlag
//                              tscenaro.cpp:545 (33)
//         0052b560     MOV        EAX,dword ptr [ECX + this->which_player]
//         0052b566     MOV        EDX,dword ptr [ESP + param_1]
//         0052b56a     LEA        EAX,[EAX + EAX*0x2]
//         0052b56d     LEA        EAX,[EDX + EAX*0x4]
//         0052b570     MOV        EDX,dword ptr [ESP + param_2]
//         0052b574     LEA        EAX,[EAX + EAX*0x2]
//         0052b577     LEA        EAX,[EAX + EAX*0x4]
//         0052b57a     MOV        dword ptr [ECX + EAX*0x4 + this+0x1aac],EDX
//                              tscenaro.cpp:547 (3)
//         0052b581     RET        0x8
//         0052b584     ??         90h
//         0052b585     NOP
//         0052b586     NOP
//         0052b587     NOP
//         0052b588     NOP
//         0052b589     NOP
//         0052b58a     NOP
//         0052b58b     NOP
//         0052b58c     NOP
//         0052b58d     NOP
//         0052b58e     NOP
//         0052b58f     NOP
    return;
}

void T_Scenario::SetSPAttribType(int param_1, int param_2) {
    /* TODO: Stub */
//                              void __thiscall SetSPAttribType(T_Scenario * this, int param_1, int
//              void              <VOID>         <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052b596(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0052b5a0(R)
//                               ?SetSPAttribType@T_Scenario@@QAEXHH@Z                        XREF[3]:     save_victory_cond_in_scenario:004a
//                               T_Scenario::SetSPAttribType                                               save_victory_cond_in_scenario:004a
//                                                                                                         save_victory_cond_in_scenario:004a
//                              tscenaro.cpp:551 (33)
//         0052b590     MOV        EAX,dword ptr [ECX + this->which_player]
//         0052b596     MOV        EDX,dword ptr [ESP + param_1]
//         0052b59a     LEA        EAX,[EAX + EAX*0x2]
//         0052b59d     LEA        EAX,[EDX + EAX*0x4]
//         0052b5a0     MOV        EDX,dword ptr [ESP + param_2]
//         0052b5a4     LEA        EAX,[EAX + EAX*0x2]
//         0052b5a7     LEA        EAX,[EAX + EAX*0x4]
//         0052b5aa     MOV        dword ptr [ECX + EAX*0x4 + this+0x1ad0],EDX
//                              tscenaro.cpp:553 (3)
//         0052b5b1     RET        0x8
//         0052b5b4     ??         90h
//         0052b5b5     NOP
//         0052b5b6     NOP
//         0052b5b7     NOP
//         0052b5b8     NOP
//         0052b5b9     NOP
//         0052b5ba     NOP
//         0052b5bb     NOP
//         0052b5bc     NOP
//         0052b5bd     NOP
//         0052b5be     NOP
//         0052b5bf     NOP
    return;
}

void T_Scenario::SetSPVictoryType(int param_1, int param_2) {
    /* TODO: Stub */
//                              void __thiscall SetSPVictoryType(T_Scenario * this, int param_1, int
//              void              <VOID>         <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052b5c6(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0052b5d0(R)
//                               ?SetSPVictoryType@T_Scenario@@QAEXHH@Z                       XREF[18]:    save_victory_cond_in_scenario:004a
//                               T_Scenario::SetSPVictoryType                                              save_victory_cond_in_scenario:004a
//                                                                                                         save_victory_cond_in_scenario:004a
//                                                                                                         save_victory_cond_in_scenario:004a
//                                                                                                         save_victory_cond_in_scenario:004a
//                                                                                                         save_victory_cond_in_scenario:004a
//                                                                                                         save_victory_cond_in_scenario:004a
//                                                                                                         save_victory_cond_in_scenario:004a
//                                                                                                         save_victory_cond_in_scenario:004a
//                                                                                                         save_victory_cond_in_scenario:004a
//                                                                                                         save_victory_cond_in_scenario:004a
//                                                                                                         save_victory_cond_in_scenario:004a
//                                                                                                         save_victory_cond_in_scenario:004a
//                                                                                                         save_victory_cond_in_scenario:004a
//                                                                                                         save_victory_cond_in_scenario:004a
//                                                                                                         save_victory_cond_in_scenario:004a
//                                                                                                         save_victory_cond_in_scenario:004a
//                                                                                                         save_victory_cond_in_scenario:004a
//                              tscenaro.cpp:557 (33)
//         0052b5c0     MOV        EAX,dword ptr [ECX + this->which_player]
//         0052b5c6     MOV        EDX,dword ptr [ESP + param_1]
//         0052b5ca     LEA        EAX,[EAX + EAX*0x2]
//         0052b5cd     LEA        EAX,[EDX + EAX*0x4]
//         0052b5d0     MOV        EDX,dword ptr [ESP + param_2]
//         0052b5d4     LEA        EAX,[EAX + EAX*0x2]
//         0052b5d7     LEA        EAX,[EAX + EAX*0x4]
//         0052b5da     MOV        dword ptr [ECX + EAX*0x4 + this+0x1ac8],EDX
//                              tscenaro.cpp:559 (3)
//         0052b5e1     RET        0x8
//         0052b5e4     ??         90h
//         0052b5e5     NOP
//         0052b5e6     NOP
//         0052b5e7     NOP
//         0052b5e8     NOP
//         0052b5e9     NOP
//         0052b5ea     NOP
//         0052b5eb     NOP
//         0052b5ec     NOP
//         0052b5ed     NOP
//         0052b5ee     NOP
//         0052b5ef     NOP
    return;
}

void T_Scenario::SetSPObject(int param_1, RGE_Static_Object* param_2) {
    /* TODO: Stub */
//                              void __thiscall SetSPObject(T_Scenario * this, int param_1, RGE_Stat
//              void              <VOID>         <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052b60d(R)
//              RGE_Static_Obj    Stack[0x8]:4   param_2                   XREF[1]:     0052b5f0(R)
//                               ?SetSPObject@T_Scenario@@QAEXHPAVRGE_Static_Object@@@Z       XREF[4]:     save_victory_cond_in_scenario:004a
//                               T_Scenario::SetSPObject                                                   save_victory_cond_in_scenario:004a
//                                                                                                         save_victory_cond_in_scenario:004a
//                                                                                                         save_victory_cond_in_scenario:004a
//                              tscenaro.cpp:563 (11)
//         0052b5f0     MOV        EAX,dword ptr [ESP + param_2]
//         0052b5f4     PUSH       ESI
//         0052b5f5     TEST       EAX,EAX
//         0052b5f7     MOV        ESI,this
//         0052b5f9     JZ         LAB_0052b621
//                              tscenaro.cpp:565 (38)
//         0052b5fb     PUSH       EAX
//         0052b5fc     CALL       T_Scenario::get_object_ID                        int get_object_ID(T_Scenario * this, RGE_Stat
//         0052b601     MOV        this,EAX
//         0052b603     MOV        EAX,dword ptr [ESI + 0x4bf0]
//         0052b609     INC        this
//         0052b60a     LEA        EDX,[EAX + EAX*0x2]
//         0052b60d     MOV        EAX,dword ptr [ESP + param_1]
//         0052b611     LEA        EAX,[EAX + EDX*0x4]
//         0052b614     LEA        EAX,[EAX + EAX*0x2]
//         0052b617     LEA        EDX,[EAX + EAX*0x4]
//         0052b61a     MOV        dword ptr [ESI + EDX*0x4 + 0x1ad4],this
//                               LAB_0052b621                                                 XREF[1]:     0052b5f9(j)
//                              tscenaro.cpp:567 (4)
//         0052b621     POP        ESI
//         0052b622     RET        0x8
//         0052b625     ??         90h
//         0052b626     NOP
//         0052b627     NOP
//         0052b628     NOP
//         0052b629     NOP
//         0052b62a     NOP
//         0052b62b     NOP
//         0052b62c     NOP
//         0052b62d     NOP
//         0052b62e     NOP
//         0052b62f     NOP
    return;
}

void T_Scenario::SetSPDestObjectID(int param_1, RGE_Static_Object* param_2) {
    /* TODO: Stub */
//                              void __thiscall SetSPDestObjectID(T_Scenario * this, int param_1, RG
//              void              <VOID>         <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052b64d(R)
//              RGE_Static_Obj    Stack[0x8]:4   param_2                   XREF[1]:     0052b630(R)
//                               ?SetSPDestObjectID@T_Scenario@@QAEXHPAVRGE_Static_Object@@@Z XREF[1]:     save_victory_cond_in_scenario:004a
//                               T_Scenario::SetSPDestObjectID
//                              tscenaro.cpp:571 (11)
//         0052b630     MOV        EAX,dword ptr [ESP + param_2]
//         0052b634     PUSH       ESI
//         0052b635     TEST       EAX,EAX
//         0052b637     MOV        ESI,this
//         0052b639     JZ         LAB_0052b661
//                              tscenaro.cpp:573 (38)
//         0052b63b     PUSH       EAX
//         0052b63c     CALL       T_Scenario::get_object_ID                        int get_object_ID(T_Scenario * this, RGE_Stat
//         0052b641     MOV        this,EAX
//         0052b643     MOV        EAX,dword ptr [ESI + 0x4bf0]
//         0052b649     INC        this
//         0052b64a     LEA        EDX,[EAX + EAX*0x2]
//         0052b64d     MOV        EAX,dword ptr [ESP + param_1]
//         0052b651     LEA        EAX,[EAX + EDX*0x4]
//         0052b654     LEA        EAX,[EAX + EAX*0x2]
//         0052b657     LEA        EDX,[EAX + EAX*0x4]
//         0052b65a     MOV        dword ptr [ESI + EDX*0x4 + 0x1ad8],this
//                               LAB_0052b661                                                 XREF[1]:     0052b639(j)
//                              tscenaro.cpp:575 (4)
//         0052b661     POP        ESI
//         0052b662     RET        0x8
//         0052b665     ??         90h
//         0052b666     NOP
//         0052b667     NOP
//         0052b668     NOP
//         0052b669     NOP
//         0052b66a     NOP
//         0052b66b     NOP
//         0052b66c     NOP
//         0052b66d     NOP
//         0052b66e     NOP
//         0052b66f     NOP
    return;
}

void T_Scenario::SetSPAmount(int param_1, int param_2) {
    /* TODO: Stub */
//                              void __thiscall SetSPAmount(T_Scenario * this, int param_1, int para
//              void              <VOID>         <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052b676(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0052b680(R)
//                               ?SetSPAmount@T_Scenario@@QAEXHH@Z                            XREF[4]:     save_victory_cond_in_scenario:004a
//                               T_Scenario::SetSPAmount                                                   save_victory_cond_in_scenario:004a
//                                                                                                         save_victory_cond_in_scenario:004a
//                                                                                                         save_victory_cond_in_scenario:004a
//                              tscenaro.cpp:579 (33)
//         0052b670     MOV        EAX,dword ptr [ECX + this->which_player]
//         0052b676     MOV        EDX,dword ptr [ESP + param_1]
//         0052b67a     LEA        EAX,[EAX + EAX*0x2]
//         0052b67d     LEA        EAX,[EDX + EAX*0x4]
//         0052b680     MOV        EDX,dword ptr [ESP + param_2]
//         0052b684     LEA        EAX,[EAX + EAX*0x2]
//         0052b687     LEA        EAX,[EAX + EAX*0x4]
//         0052b68a     MOV        dword ptr [ECX + EAX*0x4 + this+0x1acc],EDX
//                              tscenaro.cpp:581 (3)
//         0052b691     RET        0x8
//         0052b694     ??         90h
//         0052b695     NOP
//         0052b696     NOP
//         0052b697     NOP
//         0052b698     NOP
//         0052b699     NOP
//         0052b69a     NOP
//         0052b69b     NOP
//         0052b69c     NOP
//         0052b69d     NOP
//         0052b69e     NOP
//         0052b69f     NOP
    return;
}

void T_Scenario::SetPlayerAlliedVictory(int param_1, int param_2) {
    /* TODO: Stub */
//                              void __thiscall SetPlayerAlliedVictory(T_Scenario * this, int param_
//              void              <VOID>         <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052b6a0(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0052b6a4(R)
//                               ?SetPlayerAlliedVictory@T_Scenario@@QAEXHH@Z                 XREF[1]:     save_diplomacy_in_scenario:004aed3
//                               T_Scenario::SetPlayerAlliedVictory
//                              tscenaro.cpp:585 (15)
//         0052b6a0     MOV        EDX,dword ptr [ESP + param_1]
//         0052b6a4     MOV        EAX,dword ptr [ESP + param_2]
//         0052b6a8     MOV        dword ptr [ECX + EDX*0x4 + this->AlliedVictory
//                              tscenaro.cpp:587 (3)
//         0052b6af     RET        0x8
//         0052b6b2     ??         90h
//         0052b6b3     NOP
//         0052b6b4     NOP
//         0052b6b5     NOP
//         0052b6b6     NOP
//         0052b6b7     NOP
//         0052b6b8     NOP
//         0052b6b9     NOP
//         0052b6ba     NOP
//         0052b6bb     NOP
//         0052b6bc     NOP
//         0052b6bd     NOP
//         0052b6be     NOP
//         0052b6bf     NOP
    return;
}

void T_Scenario::SetDisabledTechnology(int param_1, int param_2, int param_3) {
    /* TODO: Stub */
//                              void __thiscall SetDisabledTechnology(T_Scenario * this, int param_1
//              void              <VOID>         <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052b6c0(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0052b6c4(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     0052b6ce(R)
//                               ?SetDisabledTechnology@T_Scenario@@QAEXHHH@Z                 XREF[1]:     SaveDisabledItemsInScenario:004adc
//                               T_Scenario::SetDisabledTechnology
//                              tscenaro.cpp:591 (25)
//         0052b6c0     MOV        EAX,dword ptr [ESP + param_1]
//         0052b6c4     MOV        EDX,dword ptr [ESP + param_2]
//         0052b6c8     LEA        EAX,[EAX + EAX*0x4]
//         0052b6cb     LEA        EAX,[EDX + EAX*0x4]
//         0052b6ce     MOV        EDX,dword ptr [ESP + param_3]
//         0052b6d2     MOV        dword ptr [ECX + EAX*0x4 + this->DisabledTechn
//                              tscenaro.cpp:593 (3)
//         0052b6d9     RET        0xc
//         0052b6dc     ??         90h
//         0052b6dd     NOP
//         0052b6de     NOP
//         0052b6df     NOP
    return;
}

void T_Scenario::SetScenarioOption(int param_1, int param_2) {
    /* TODO: Stub */
//                              void __thiscall SetScenarioOption(T_Scenario * this, int param_1, in
//              void              <VOID>         <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052b6e0(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0052b6e4(R)
//                               ?SetScenarioOption@T_Scenario@@QAEXHH@Z                      XREF[1]:     action:004ace42(c)
//                               T_Scenario::SetScenarioOption
//                              tscenaro.cpp:597 (15)
//         0052b6e0     MOV        EDX,dword ptr [ESP + param_1]
//         0052b6e4     MOV        EAX,dword ptr [ESP + param_2]
//         0052b6e8     MOV        dword ptr [ECX + EDX*0x4 + this->ScenarioOptio
//                              tscenaro.cpp:599 (3)
//         0052b6ef     RET        0x8
//         0052b6f2     ??         90h
//         0052b6f3     NOP
//         0052b6f4     NOP
//         0052b6f5     NOP
//         0052b6f6     NOP
//         0052b6f7     NOP
//         0052b6f8     NOP
//         0052b6f9     NOP
//         0052b6fa     NOP
//         0052b6fb     NOP
//         0052b6fc     NOP
//         0052b6fd     NOP
//         0052b6fe     NOP
//         0052b6ff     NOP
    return;
}

void T_Scenario::SetPlayerAge(int param_1, int param_2) {
    /* TODO: Stub */
//                              void __thiscall SetPlayerAge(T_Scenario * this, int param_1, int par
//              void              <VOID>         <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052b700(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0052b704(R)
//                               ?SetPlayerAge@T_Scenario@@QAEXHH@Z                           XREF[2]:     action:004ac977(c),
//                               T_Scenario::SetPlayerAge                                                  action:004aca22(c)
//                              tscenaro.cpp:603 (15)
//         0052b700     MOV        EDX,dword ptr [ESP + param_1]
//         0052b704     MOV        EAX,dword ptr [ESP + param_2]
//         0052b708     MOV        dword ptr [ECX + EDX*0x4 + this->PlayerAge[0]]
//                              tscenaro.cpp:605 (3)
//         0052b70f     RET        0x8
//         0052b712     ??         90h
//         0052b713     NOP
//         0052b714     NOP
//         0052b715     NOP
//         0052b716     NOP
//         0052b717     NOP
//         0052b718     NOP
//         0052b719     NOP
//         0052b71a     NOP
//         0052b71b     NOP
//         0052b71c     NOP
//         0052b71d     NOP
//         0052b71e     NOP
//         0052b71f     NOP
    return;
}

int T_Scenario::Get_player_Gold(int param_1) {
    /* TODO: Stub */
//                              int __thiscall Get_player_Gold(T_Scenario * this, int param_1)
//              int               EAX:4          <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052b720(R)
//                               ?Get_player_Gold@T_Scenario@@QAEHH@Z                         XREF[2]:     set_player:004ab0e9(c),
//                               T_Scenario::Get_player_Gold                                               SaveAttributesIntoPlayers:0052bb08
//                              tscenaro.cpp:612 (13)
//         0052b720     MOV        EAX,dword ptr [ESP + param_1]
//         0052b724     TEST       EAX,EAX
//         0052b726     JL         LAB_0052b73a
//         0052b728     CMP        EAX,0x10
//         0052b72b     JGE        LAB_0052b73a
//                              tscenaro.cpp:615 (10)
//         0052b72d     SHL        EAX,0x4
//         0052b730     MOV        EAX,dword ptr [ECX + EAX*0x1 + this->player_in
//                              tscenaro.cpp:616 (3)
//         0052b737     RET        0x4
//                               LAB_0052b73a                                                 XREF[2]:     0052b726(j), 0052b72b(j)
//                              tscenaro.cpp:614 (2)
//         0052b73a     XOR        EAX,EAX
//                              tscenaro.cpp:616 (3)
//         0052b73c     RET        0x4
//         0052b73f     ??         90h
    return 0;
}

int T_Scenario::Get_player_Wood(int param_1) {
    /* TODO: Stub */
//                              int __thiscall Get_player_Wood(T_Scenario * this, int param_1)
//              int               EAX:4          <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052b740(R)
//                               ?Get_player_Wood@T_Scenario@@QAEHH@Z                         XREF[2]:     set_player:004ab085(c),
//                               T_Scenario::Get_player_Wood                                               SaveAttributesIntoPlayers:0052bb2c
//                              tscenaro.cpp:620 (13)
//         0052b740     MOV        EAX,dword ptr [ESP + param_1]
//         0052b744     TEST       EAX,EAX
//         0052b746     JL         LAB_0052b75a
//         0052b748     CMP        EAX,0x10
//         0052b74b     JGE        LAB_0052b75a
//                              tscenaro.cpp:623 (10)
//         0052b74d     SHL        EAX,0x4
//         0052b750     MOV        EAX,dword ptr [ECX + EAX*0x1 + this+0x1994]
//                              tscenaro.cpp:624 (3)
//         0052b757     RET        0x4
//                               LAB_0052b75a                                                 XREF[2]:     0052b746(j), 0052b74b(j)
//                              tscenaro.cpp:622 (2)
//         0052b75a     XOR        EAX,EAX
//                              tscenaro.cpp:624 (3)
//         0052b75c     RET        0x4
//         0052b75f     ??         90h
    return 0;
}

int T_Scenario::Get_player_Food(int param_1) {
    /* TODO: Stub */
//                              int __thiscall Get_player_Food(T_Scenario * this, int param_1)
//              int               EAX:4          <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052b760(R)
//                               ?Get_player_Food@T_Scenario@@QAEHH@Z                         XREF[2]:     set_player:004ab053(c),
//                               T_Scenario::Get_player_Food                                               SaveAttributesIntoPlayers:0052bac0
//                              tscenaro.cpp:628 (13)
//         0052b760     MOV        EAX,dword ptr [ESP + param_1]
//         0052b764     TEST       EAX,EAX
//         0052b766     JL         LAB_0052b77a
//         0052b768     CMP        EAX,0x10
//         0052b76b     JGE        LAB_0052b77a
//                              tscenaro.cpp:631 (10)
//         0052b76d     SHL        EAX,0x4
//         0052b770     MOV        EAX,dword ptr [ECX + EAX*0x1 + this+0x1998]
//                              tscenaro.cpp:632 (3)
//         0052b777     RET        0x4
//                               LAB_0052b77a                                                 XREF[2]:     0052b766(j), 0052b76b(j)
//                              tscenaro.cpp:630 (2)
//         0052b77a     XOR        EAX,EAX
//                              tscenaro.cpp:632 (3)
//         0052b77c     RET        0x4
//         0052b77f     ??         90h
    return 0;
}

int T_Scenario::Get_player_Stone(int param_1) {
    /* TODO: Stub */
//                              int __thiscall Get_player_Stone(T_Scenario * this, int param_1)
//              int               EAX:4          <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052b780(R)
//                               ?Get_player_Stone@T_Scenario@@QAEHH@Z                        XREF[2]:     set_player:004ab0b7(c),
//                               T_Scenario::Get_player_Stone                                              SaveAttributesIntoPlayers:0052bae4
//                              tscenaro.cpp:636 (13)
//         0052b780     MOV        EAX,dword ptr [ESP + param_1]
//         0052b784     TEST       EAX,EAX
//         0052b786     JL         LAB_0052b79a
//         0052b788     CMP        EAX,0x10
//         0052b78b     JGE        LAB_0052b79a
//                              tscenaro.cpp:639 (10)
//         0052b78d     SHL        EAX,0x4
//         0052b790     MOV        EAX,dword ptr [ECX + EAX*0x1 + this+0x199c]
//                              tscenaro.cpp:640 (3)
//         0052b797     RET        0x4
//                               LAB_0052b79a                                                 XREF[2]:     0052b786(j), 0052b78b(j)
//                              tscenaro.cpp:638 (2)
//         0052b79a     XOR        EAX,EAX
//                              tscenaro.cpp:640 (3)
//         0052b79c     RET        0x4
//         0052b79f     ??         90h
    return 0;
}

Player_Start_Info* T_Scenario::Get_player_Info(int param_1) {
    /* TODO: Stub */
//                              Player_Start_Info * __thiscall Get_player_Info(T_Scenario * this, in
//              Player_Start_I    EAX:4          <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052b7a0(R)
//                               ?Get_player_Info@T_Scenario@@QAEPAUPlayer_Start_Info@@H@Z
//                               T_Scenario::Get_player_Info
//                              tscenaro.cpp:644 (13)
//         0052b7a0     MOV        EAX,dword ptr [ESP + param_1]
//         0052b7a4     TEST       EAX,EAX
//         0052b7a6     JL         LAB_0052b7ba
//         0052b7a8     CMP        EAX,0x10
//         0052b7ab     JGE        LAB_0052b7ba
//                              tscenaro.cpp:647 (10)
//         0052b7ad     ADD        EAX,0x199
//         0052b7b2     SHL        EAX,0x4
//         0052b7b5     ADD        EAX,this
//                              tscenaro.cpp:648 (3)
//         0052b7b7     RET        0x4
//                               LAB_0052b7ba                                                 XREF[2]:     0052b7a6(j), 0052b7ab(j)
//                              tscenaro.cpp:646 (2)
//         0052b7ba     XOR        EAX,EAX
//                              tscenaro.cpp:648 (3)
//         0052b7bc     RET        0x4
//         0052b7bf     ??         90h
    return 0;
}

int T_Scenario::Get_Multi_Conquest() {
    /* TODO: Stub */
//                              int __thiscall Get_Multi_Conquest(T_Scenario * this)
//              int               EAX:4          <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//                               ?Get_Multi_Conquest@T_Scenario@@QAEHXZ                       XREF[1]:     load_multi_victory_cond_from_scena
//                               T_Scenario::Get_Multi_Conquest
//                              tscenaro.cpp:653 (6)
//         0052b7c0     MOV        EAX,dword ptr [ECX + this->victory.MP_Conquest]
//                              tscenaro.cpp:655 (1)
//         0052b7c6     RET
//         0052b7c7     ??         90h
//         0052b7c8     NOP
//         0052b7c9     NOP
//         0052b7ca     NOP
//         0052b7cb     NOP
//         0052b7cc     NOP
//         0052b7cd     NOP
//         0052b7ce     NOP
//         0052b7cf     NOP
    return 0;
}

int T_Scenario::Get_Multi_Ruins() {
    /* TODO: Stub */
//                              int __thiscall Get_Multi_Ruins(T_Scenario * this)
//              int               EAX:4          <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//                               ?Get_Multi_Ruins@T_Scenario@@QAEHXZ                          XREF[2]:     load_multi_victory_cond_from_scena
//                               T_Scenario::Get_Multi_Ruins                                               new_game:0052faaf(c)
//                              tscenaro.cpp:659 (6)
//         0052b7d0     MOV        EAX,dword ptr [ECX + this+0x1a94]
//                              tscenaro.cpp:661 (1)
//         0052b7d6     RET
//         0052b7d7     ??         90h
//         0052b7d8     NOP
//         0052b7d9     NOP
//         0052b7da     NOP
//         0052b7db     NOP
//         0052b7dc     NOP
//         0052b7dd     NOP
//         0052b7de     NOP
//         0052b7df     NOP
    return 0;
}

int T_Scenario::Get_Multi_Artifacts() {
    /* TODO: Stub */
//                              int __thiscall Get_Multi_Artifacts(T_Scenario * this)
//              int               EAX:4          <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//                               ?Get_Multi_Artifacts@T_Scenario@@QAEHXZ                      XREF[2]:     load_multi_victory_cond_from_scena
//                               T_Scenario::Get_Multi_Artifacts                                           new_game:0052fa00(c)
//                              tscenaro.cpp:665 (6)
//         0052b7e0     MOV        EAX,dword ptr [ECX + this+0x1a98]
//                              tscenaro.cpp:667 (1)
//         0052b7e6     RET
//         0052b7e7     ??         90h
//         0052b7e8     NOP
//         0052b7e9     NOP
//         0052b7ea     NOP
//         0052b7eb     NOP
//         0052b7ec     NOP
//         0052b7ed     NOP
//         0052b7ee     NOP
//         0052b7ef     NOP
    return 0;
}

int T_Scenario::Get_Multi_Discoveries() {
    /* TODO: Stub */
//                              int __thiscall Get_Multi_Discoveries(T_Scenario * this)
//              int               EAX:4          <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//                               ?Get_Multi_Discoveries@T_Scenario@@QAEHXZ                    XREF[2]:     load_multi_victory_cond_from_scena
//                               T_Scenario::Get_Multi_Discoveries                                         new_game:0052fa5a(c)
//                              tscenaro.cpp:671 (6)
//         0052b7f0     MOV        EAX,dword ptr [ECX + this+0x1a9c]
//                              tscenaro.cpp:673 (1)
//         0052b7f6     RET
//         0052b7f7     ??         90h
//         0052b7f8     NOP
//         0052b7f9     NOP
//         0052b7fa     NOP
//         0052b7fb     NOP
//         0052b7fc     NOP
//         0052b7fd     NOP
//         0052b7fe     NOP
//         0052b7ff     NOP
    return 0;
}

int T_Scenario::Get_Multi_Exploration() {
    /* TODO: Stub */
//                              int __thiscall Get_Multi_Exploration(T_Scenario * this)
//              int               EAX:4          <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//                               ?Get_Multi_Exploration@T_Scenario@@QAEHXZ                    XREF[1]:     load_multi_victory_cond_from_scena
//                               T_Scenario::Get_Multi_Exploration
//                              tscenaro.cpp:677 (6)
//         0052b800     MOV        EAX,dword ptr [ECX + this+0x1aa0]
//                              tscenaro.cpp:679 (1)
//         0052b806     RET
//         0052b807     ??         90h
//         0052b808     NOP
//         0052b809     NOP
//         0052b80a     NOP
//         0052b80b     NOP
//         0052b80c     NOP
//         0052b80d     NOP
//         0052b80e     NOP
//         0052b80f     NOP
    return 0;
}

int T_Scenario::Get_Multi_Gold() {
    /* TODO: Stub */
//                              int __thiscall Get_Multi_Gold(T_Scenario * this)
//              int               EAX:4          <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//                               ?Get_Multi_Gold@T_Scenario@@QAEHXZ                           XREF[1]:     load_multi_victory_cond_from_scena
//                               T_Scenario::Get_Multi_Gold
//                              tscenaro.cpp:683 (6)
//         0052b810     MOV        EAX,dword ptr [ECX + this+0x1aa4]
//                              tscenaro.cpp:685 (1)
//         0052b816     RET
//         0052b817     ??         90h
//         0052b818     NOP
//         0052b819     NOP
//         0052b81a     NOP
//         0052b81b     NOP
//         0052b81c     NOP
//         0052b81d     NOP
//         0052b81e     NOP
//         0052b81f     NOP
    return 0;
}

void T_Scenario::GetSPRectangle(int param_1, float* param_2, float* param_3, float* param_4, float* param_5) {
    /* TODO: Stub */
//                              void __thiscall GetSPRectangle(T_Scenario * this, int param_1, float
//              void              <VOID>         <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052b82e(R)
//              float *           Stack[0x8]:4   param_2                   XREF[1]:     0052b827(R)
//              float *           Stack[0xc]:4   param_3                   XREF[1]:     0052b847(R)
//              float *           Stack[0x10]:4  param_4                   XREF[1]:     0052b866(R)
//              float *           Stack[0x14]:4  param_5                   XREF[1]:     0052b88c(R)
//                               ?GetSPRectangle@T_Scenario@@QAEXHPAM000@Z                    XREF[2]:     load_victory_cond_from_scenario:00
//                               T_Scenario::GetSPRectangle                                                load_victory_cond_from_scenario:00
//                              tscenaro.cpp:689 (33)
//         0052b820     MOV        EAX,dword ptr [ECX + this->which_player]
//         0052b826     PUSH       ESI
//         0052b827     MOV        ESI,dword ptr [ESP + param_2]
//         0052b82b     LEA        EDX,[EAX + EAX*0x2]
//         0052b82e     MOV        EAX,dword ptr [ESP + param_1]
//         0052b832     LEA        EDX,[EAX + EDX*0x4 + 0x72]
//         0052b836     LEA        EDX,[EDX + EDX*0x2]
//         0052b839     LEA        EDX,[EDX + EDX*0x4]
//         0052b83c     MOV        EDX,dword ptr [this->_padding_ + EDX*0x4]
//         0052b83f     MOV        dword ptr [ESI],EDX
//                              tscenaro.cpp:691 (31)
//         0052b841     MOV        EDX,dword ptr [ECX + this->which_player]
//         0052b847     MOV        ESI,dword ptr [ESP + param_3]
//         0052b84b     LEA        EDX,[EDX + EDX*0x2]
//         0052b84e     LEA        EDX,[EAX + EDX*0x4]
//         0052b851     LEA        EDX,[EDX + EDX*0x2]
//         0052b854     LEA        EDX,[EDX + EDX*0x4]
//         0052b857     MOV        EDX,dword ptr [ECX + EDX*0x4 + this+0x1abc]
//         0052b85e     MOV        dword ptr [ESI],EDX
//                              tscenaro.cpp:692 (31)
//         0052b860     MOV        EDX,dword ptr [ECX + this->which_player]
//         0052b866     MOV        ESI,dword ptr [ESP + param_4]
//         0052b86a     LEA        EDX,[EDX + EDX*0x2]
//         0052b86d     LEA        EDX,[EAX + EDX*0x4]
//         0052b870     LEA        EDX,[EDX + EDX*0x2]
//         0052b873     LEA        EDX,[EDX + EDX*0x4]
//         0052b876     MOV        EDX,dword ptr [ECX + EDX*0x4 + this+0x1ac0]
//         0052b87d     MOV        dword ptr [ESI],EDX
//                              tscenaro.cpp:693 (6)
//         0052b87f     MOV        EDX,dword ptr [ECX + this->which_player]
//                              tscenaro.cpp:694 (29)
//         0052b885     POP        ESI
//         0052b886     LEA        EDX,[EDX + EDX*0x2]
//         0052b889     LEA        EAX,[EAX + EDX*0x4]
//         0052b88c     MOV        EDX,dword ptr [ESP + param_5]
//         0052b890     LEA        EAX,[EAX + EAX*0x2]
//         0052b893     LEA        EAX,[EAX + EAX*0x4]
//         0052b896     MOV        this,dword ptr [ECX + EAX*0x4 + this+0x1ac4]
//         0052b89d     MOV        dword ptr [EDX],this
//         0052b89f     RET        0x14
//         0052b8a2     ??         90h
//         0052b8a3     NOP
//         0052b8a4     NOP
//         0052b8a5     NOP
//         0052b8a6     NOP
//         0052b8a7     NOP
//         0052b8a8     NOP
//         0052b8a9     NOP
//         0052b8aa     NOP
//         0052b8ab     NOP
//         0052b8ac     NOP
//         0052b8ad     NOP
//         0052b8ae     NOP
//         0052b8af     NOP
    return;
}

int T_Scenario::GetSPObjectType(int param_1) {
    /* TODO: Stub */
//                              int __thiscall GetSPObjectType(T_Scenario * this, int param_1)
//              int               EAX:4          <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052b8c6(R)
//                               ?GetSPObjectType@T_Scenario@@QAEHH@Z                         XREF[1]:     load_victory_cond_from_scenario:00
//                               T_Scenario::GetSPObjectType
//                              tscenaro.cpp:698 (36)
//         0052b8b0     MOV        EAX,dword ptr [ECX + this->which_player]
//         0052b8b6     LEA        EAX,[EAX + EAX*0x4]
//         0052b8b9     LEA        EAX,[EAX + EAX*0x8]
//         0052b8bc     SHL        EAX,0x4
//         0052b8bf     LEA        this,[ECX + EAX*0x1 + this->sp_victory[0][0].O
//         0052b8c6     MOV        EAX,dword ptr [ESP + param_1]
//         0052b8ca     MOV        EDX,EAX
//         0052b8cc     SHL        EDX,0x4
//         0052b8cf     SUB        EDX,EAX
//         0052b8d1     MOV        EAX,dword ptr [this->_padding_ + EDX*0x4]
//                              tscenaro.cpp:700 (3)
//         0052b8d4     RET        0x4
//         0052b8d7     ??         90h
//         0052b8d8     NOP
//         0052b8d9     NOP
//         0052b8da     NOP
//         0052b8db     NOP
//         0052b8dc     NOP
//         0052b8dd     NOP
//         0052b8de     NOP
//         0052b8df     NOP
    return 0;
}

int T_Scenario::GetSPPlayerID(int param_1) {
    /* TODO: Stub */
//                              int __thiscall GetSPPlayerID(T_Scenario * this, int param_1)
//              int               EAX:4          <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052b8f6(R)
//                               ?GetSPPlayerID@T_Scenario@@QAEHH@Z                           XREF[1]:     load_victory_cond_from_scenario:00
//                               T_Scenario::GetSPPlayerID
//                              tscenaro.cpp:704 (37)
//         0052b8e0     MOV        EAX,dword ptr [ECX + this->which_player]
//         0052b8e6     LEA        EAX,[EAX + EAX*0x4]
//         0052b8e9     LEA        EAX,[EAX + EAX*0x8]
//         0052b8ec     SHL        EAX,0x4
//         0052b8ef     LEA        this,[ECX + EAX*0x1 + this->sp_victory[0][0].O
//         0052b8f6     MOV        EAX,dword ptr [ESP + param_1]
//         0052b8fa     MOV        EDX,EAX
//         0052b8fc     SHL        EDX,0x4
//         0052b8ff     SUB        EDX,EAX
//         0052b901     MOV        EAX,dword ptr [ECX + EDX*0x4 + this->_padding_]
//                              tscenaro.cpp:706 (3)
//         0052b905     RET        0x4
//         0052b908     ??         90h
//         0052b909     NOP
//         0052b90a     NOP
//         0052b90b     NOP
//         0052b90c     NOP
//         0052b90d     NOP
//         0052b90e     NOP
//         0052b90f     NOP
    return 0;
}

int T_Scenario::GetSPAllFlag(int param_1) {
    /* TODO: Stub */
//                              int __thiscall GetSPAllFlag(T_Scenario * this, int param_1)
//              int               EAX:4          <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052b926(R)
//                               ?GetSPAllFlag@T_Scenario@@QAEHH@Z                            XREF[1]:     load_victory_cond_from_scenario:00
//                               T_Scenario::GetSPAllFlag
//                              tscenaro.cpp:710 (37)
//         0052b910     MOV        EAX,dword ptr [ECX + this->which_player]
//         0052b916     LEA        EAX,[EAX + EAX*0x4]
//         0052b919     LEA        EAX,[EAX + EAX*0x8]
//         0052b91c     SHL        EAX,0x4
//         0052b91f     LEA        this,[ECX + EAX*0x1 + this->sp_victory[0][0].O
//         0052b926     MOV        EAX,dword ptr [ESP + param_1]
//         0052b92a     MOV        EDX,EAX
//         0052b92c     SHL        EDX,0x4
//         0052b92f     SUB        EDX,EAX
//         0052b931     MOV        EAX,dword ptr [ECX + EDX*this->_padding_ + 0x4]
//                              tscenaro.cpp:712 (3)
//         0052b935     RET        0x4
//         0052b938     ??         90h
//         0052b939     NOP
//         0052b93a     NOP
//         0052b93b     NOP
//         0052b93c     NOP
//         0052b93d     NOP
//         0052b93e     NOP
//         0052b93f     NOP
    return 0;
}

int T_Scenario::GetSPAttribType(int param_1) {
    /* TODO: Stub */
//                              int __thiscall GetSPAttribType(T_Scenario * this, int param_1)
//              int               EAX:4          <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052b956(R)
//                               ?GetSPAttribType@T_Scenario@@QAEHH@Z                         XREF[1]:     load_victory_cond_from_scenario:00
//                               T_Scenario::GetSPAttribType
//                              tscenaro.cpp:716 (37)
//         0052b940     MOV        EAX,dword ptr [ECX + this->which_player]
//         0052b946     LEA        EAX,[EAX + EAX*0x4]
//         0052b949     LEA        EAX,[EAX + EAX*0x8]
//         0052b94c     SHL        EAX,0x4
//         0052b94f     LEA        this,[ECX + EAX*0x1 + this->sp_victory[0][0].O
//         0052b956     MOV        EAX,dword ptr [ESP + param_1]
//         0052b95a     MOV        EDX,EAX
//         0052b95c     SHL        EDX,0x4
//         0052b95f     SUB        EDX,EAX
//         0052b961     MOV        EAX,dword ptr [ECX + EDX*0x4 + this->_padding_]
//                              tscenaro.cpp:718 (3)
//         0052b965     RET        0x4
//         0052b968     ??         90h
//         0052b969     NOP
//         0052b96a     NOP
//         0052b96b     NOP
//         0052b96c     NOP
//         0052b96d     NOP
//         0052b96e     NOP
//         0052b96f     NOP
    return 0;
}

int T_Scenario::GetSPAmount(int param_1) {
    /* TODO: Stub */
//                              int __thiscall GetSPAmount(T_Scenario * this, int param_1)
//              int               EAX:4          <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052b986(R)
//                               ?GetSPAmount@T_Scenario@@QAEHH@Z                             XREF[2]:     load_victory_cond_from_scenario:00
//                               T_Scenario::GetSPAmount                                                   load_victory_cond_from_scenario:00
//                              tscenaro.cpp:722 (37)
//         0052b970     MOV        EAX,dword ptr [ECX + this->which_player]
//         0052b976     LEA        EAX,[EAX + EAX*0x4]
//         0052b979     LEA        EAX,[EAX + EAX*0x8]
//         0052b97c     SHL        EAX,0x4
//         0052b97f     LEA        this,[ECX + EAX*0x1 + this->sp_victory[0][0].O
//         0052b986     MOV        EAX,dword ptr [ESP + param_1]
//         0052b98a     MOV        EDX,EAX
//         0052b98c     SHL        EDX,0x4
//         0052b98f     SUB        EDX,EAX
//         0052b991     MOV        EAX,dword ptr [ECX + EDX*0x4 + this->_padding_]
//                              tscenaro.cpp:724 (3)
//         0052b995     RET        0x4
//         0052b998     ??         90h
//         0052b999     NOP
//         0052b99a     NOP
//         0052b99b     NOP
//         0052b99c     NOP
//         0052b99d     NOP
//         0052b99e     NOP
//         0052b99f     NOP
    return 0;
}

int T_Scenario::GetSPVictoryType(int param_1) {
    /* TODO: Stub */
//                              int __thiscall GetSPVictoryType(T_Scenario * this, int param_1)
//              int               EAX:4          <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052b9b6(R)
//                               ?GetSPVictoryType@T_Scenario@@QAEHH@Z                        XREF[3]:     load_victory_cond_from_scenario:00
//                               T_Scenario::GetSPVictoryType                                              activate_victory_panel:004b2a05(c)
//                                                                                                         any_sp_victory:0052c200(c)
//                              tscenaro.cpp:728 (37)
//         0052b9a0     MOV        EAX,dword ptr [ECX + this->which_player]
//         0052b9a6     LEA        EAX,[EAX + EAX*0x4]
//         0052b9a9     LEA        EAX,[EAX + EAX*0x8]
//         0052b9ac     SHL        EAX,0x4
//         0052b9af     LEA        this,[ECX + EAX*0x1 + this->sp_victory[0][0].O
//         0052b9b6     MOV        EAX,dword ptr [ESP + param_1]
//         0052b9ba     MOV        EDX,EAX
//         0052b9bc     SHL        EDX,0x4
//         0052b9bf     SUB        EDX,EAX
//         0052b9c1     MOV        EAX,dword ptr [ECX + EDX*0x4 + this->_padding_]
//                              tscenaro.cpp:730 (3)
//         0052b9c5     RET        0x4
//         0052b9c8     ??         90h
//         0052b9c9     NOP
//         0052b9ca     NOP
//         0052b9cb     NOP
//         0052b9cc     NOP
//         0052b9cd     NOP
//         0052b9ce     NOP
//         0052b9cf     NOP
    return 0;
}

RGE_Static_Object* T_Scenario::GetSPDestObjectID(int param_1) {
    /* TODO: Stub */
//                              RGE_Static_Object * __thiscall GetSPDestObjectID(T_Scenario * this,
//              RGE_Static_Obj    EAX:4          <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052b9d7(R)
//                               ?GetSPDestObjectID@T_Scenario@@QAEPAVRGE_Static_Object@@H@Z  XREF[1]:     load_victory_cond_from_scenario:00
//                               T_Scenario::GetSPDestObjectID
//                              tscenaro.cpp:734 (35)
//         0052b9d0     MOV        EAX,dword ptr [ECX + this->which_player]
//         0052b9d6     PUSH       ESI
//         0052b9d7     MOV        ESI,dword ptr [ESP + param_1]
//         0052b9db     MOV        EDX,dword ptr [this->_padding_]
//         0052b9dd     LEA        EAX,[EAX + EAX*0x2]
//         0052b9e0     LEA        EAX,[ESI + EAX*0x4]
//         0052b9e3     LEA        EAX,[EAX + EAX*0x2]
//         0052b9e6     LEA        EAX,[EAX + EAX*0x4]
//         0052b9e9     MOV        EAX,dword ptr [ECX + EAX*0x4 + this+0x1ad8]
//         0052b9f0     PUSH       EAX
//         0052b9f1     CALL       dword ptr [EDX]
//                              tscenaro.cpp:737 (4)
//         0052b9f3     POP        ESI
//         0052b9f4     RET        0x4
//         0052b9f7     ??         90h
//         0052b9f8     NOP
//         0052b9f9     NOP
//         0052b9fa     NOP
//         0052b9fb     NOP
//         0052b9fc     NOP
//         0052b9fd     NOP
//         0052b9fe     NOP
//         0052b9ff     NOP
    return 0;
}

RGE_Static_Object* T_Scenario::GetSPObject(int param_1) {
    /* TODO: Stub */
//                              RGE_Static_Object * __thiscall GetSPObject(T_Scenario * this, int pa
//              RGE_Static_Obj    EAX:4          <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052ba07(R)
//                               ?GetSPObject@T_Scenario@@QAEPAVRGE_Static_Object@@H@Z        XREF[1]:     load_victory_cond_from_scenario:00
//                               T_Scenario::GetSPObject
//                              tscenaro.cpp:741 (35)
//         0052ba00     MOV        EAX,dword ptr [ECX + this->which_player]
//         0052ba06     PUSH       ESI
//         0052ba07     MOV        ESI,dword ptr [ESP + param_1]
//         0052ba0b     MOV        EDX,dword ptr [this->_padding_]
//         0052ba0d     LEA        EAX,[EAX + EAX*0x2]
//         0052ba10     LEA        EAX,[ESI + EAX*0x4]
//         0052ba13     LEA        EAX,[EAX + EAX*0x2]
//         0052ba16     LEA        EAX,[EAX + EAX*0x4]
//         0052ba19     MOV        EAX,dword ptr [ECX + EAX*0x4 + this+0x1ad4]
//         0052ba20     PUSH       EAX
//         0052ba21     CALL       dword ptr [EDX]
//                              tscenaro.cpp:744 (4)
//         0052ba23     POP        ESI
//         0052ba24     RET        0x4
//         0052ba27     ??         90h
//         0052ba28     NOP
//         0052ba29     NOP
//         0052ba2a     NOP
//         0052ba2b     NOP
//         0052ba2c     NOP
//         0052ba2d     NOP
//         0052ba2e     NOP
//         0052ba2f     NOP
    return 0;
}

int T_Scenario::GetPlayerAlliedVictory(int param_1) {
    /* TODO: Stub */
//                              int __thiscall GetPlayerAlliedVictory(T_Scenario * this, int param_1)
//              int               EAX:4          <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052ba30(R)
//                               ?GetPlayerAlliedVictory@T_Scenario@@QAEHH@Z                  XREF[1]:     load_diplomacy_from_scenario:004ae
//                               T_Scenario::GetPlayerAlliedVictory
//                              tscenaro.cpp:748 (11)
//         0052ba30     MOV        EAX,dword ptr [ESP + param_1]
//         0052ba34     MOV        EAX,dword ptr [ECX + EAX*0x4 + this->AlliedVic
//                              tscenaro.cpp:750 (3)
//         0052ba3b     RET        0x4
//         0052ba3e     ??         90h
//         0052ba3f     NOP
    return 0;
}

int T_Scenario::GetDisabledTechnology(int param_1, int param_2) {
    /* TODO: Stub */
//                              int __thiscall GetDisabledTechnology(T_Scenario * this, int param_1,
//              int               EAX:4          <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052ba40(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0052ba44(R)
//                               ?GetDisabledTechnology@T_Scenario@@QAEHHH@Z                  XREF[1]:     LoadDisabledItemsFromScenario:004a
//                               T_Scenario::GetDisabledTechnology
//                              tscenaro.cpp:754 (24)
//         0052ba40     MOV        EAX,dword ptr [ESP + param_1]
//         0052ba44     MOV        EDX,dword ptr [ESP + param_2]
//         0052ba48     LEA        EAX,[EAX + EAX*0x4]
//         0052ba4b     SHL        EAX,0x4
//         0052ba4e     LEA        this,[ECX + EAX*0x1 + this->DisabledTechnology
//         0052ba55     MOV        EAX,dword ptr [this->_padding_ + EDX*0x4]
//                              tscenaro.cpp:756 (3)
//         0052ba58     RET        0x8
//         0052ba5b     ??         90h
//         0052ba5c     NOP
//         0052ba5d     NOP
//         0052ba5e     NOP
//         0052ba5f     NOP
    return 0;
}

int T_Scenario::GetScenarioOption(int param_1) {
    /* TODO: Stub */
//                              int __thiscall GetScenarioOption(T_Scenario * this, int param_1)
//              int               EAX:4          <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052ba60(R)
//                               ?GetScenarioOption@T_Scenario@@QAEHH@Z                       XREF[3]:     set_scenario_mode:004aa5cc(c),
//                               T_Scenario::GetScenarioOption                                             scenario_load:0051283b(c),
//                                                                                                         new_game:0052fd13(c)
//                              tscenaro.cpp:760 (11)
//         0052ba60     MOV        EAX,dword ptr [ESP + param_1]
//         0052ba64     MOV        EAX,dword ptr [ECX + EAX*0x4 + this->ScenarioO
//                              tscenaro.cpp:762 (3)
//         0052ba6b     RET        0x4
//         0052ba6e     ??         90h
//         0052ba6f     NOP
    return 0;
}

int T_Scenario::GetPlayerAge(int param_1) {
    /* TODO: Stub */
//                              int __thiscall GetPlayerAge(T_Scenario * this, int param_1)
//              int               EAX:4          <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052ba70(R)
//                               ?GetPlayerAge@T_Scenario@@QAEHH@Z                            XREF[2]:     set_scenario_mode:004a9e94(c),
//                               T_Scenario::GetPlayerAge                                                  action:004ac9ad(c)
//                              tscenaro.cpp:766 (11)
//         0052ba70     MOV        EAX,dword ptr [ESP + param_1]
//         0052ba74     MOV        EAX,dword ptr [ECX + EAX*0x4 + this->PlayerAge
//                              tscenaro.cpp:768 (3)
//         0052ba7b     RET        0x4
//         0052ba7e     ??         90h
//         0052ba7f     NOP
    return 0;
}

void T_Scenario::update() {
    /* TODO: Stub */
//                              void __thiscall update(T_Scenario * this)
//              void              <VOID>         <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//                               ?update@T_Scenario@@QAEXXZ
//                               T_Scenario::update
//                              tscenaro.cpp:773 (8)
//         0052ba80     MOV        this,dword ptr [ECX + this->_padding_]
//         0052ba83     JMP        RGE_Timeline::update                             void update(RGE_Timeline * this)
//                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
//         0052ba88     ??         90h
//         0052ba89     NOP
//         0052ba8a     NOP
//         0052ba8b     NOP
//         0052ba8c     NOP
//         0052ba8d     NOP
//         0052ba8e     NOP
//         0052ba8f     NOP
    return;
}

void T_Scenario::SaveAttributesIntoPlayers() {
    /* TODO: Stub */
//                              void __thiscall SaveAttributesIntoPlayers(T_Scenario * this)
//              void              <VOID>         <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[8]:     0052bac8(W), 0052bacc(R), 0052bae9(W), 0052baf1(R),
//                                                                                     0052bb0d(W), 0052bb14(R), 0052bb34(W), 0052bb38(R)
//              undefined4        Stack[-0x8]:4  local_8                   XREF[3]:     0052bab6(W), 0052bb81(R), 0052bba3(W)
//              undefined4        Stack[-0x1c]:4 local_1c                  XREF[4]:     0052bad4(*), 0052baf8(*), 0052bb1c(*), 0052bb40(*)
//                               ?SaveAttributesIntoPlayers@T_Scenario@@AAEXXZ                XREF[1]:     Save_victory_conditions_into_playe
//                               T_Scenario::SaveAttributesIntoPlayers
//                              tscenaro.cpp:778 (7)
//         0052ba90     SUB        ESP,0x8
//         0052ba93     PUSH       EBX
//         0052ba94     PUSH       ESI
//         0052ba95     MOV        ESI,this
//                              tscenaro.cpp:779 (35)
//         0052ba97     MOV        EBX,0x1
//         0052ba9c     MOV        EAX,dword ptr [ESI + 0x8]
//         0052ba9f     CMP        word ptr [EAX + 0x3c],BX
//         0052baa3     JLE        LAB_0052bbaf
//         0052baa9     PUSH       EDI
//         0052baaa     LEA        this,[ESI + 0x4ba8]
//         0052bab0     PUSH       EBP
//         0052bab1     MOV        EBP,0x11e9
//         0052bab6     MOV        dword ptr [ESP + local_8],this
//                               LAB_0052baba                                                 XREF[1]:     0052bba7(j)
//                              tscenaro.cpp:781 (39)
//         0052baba     LEA        EDI,[EBX + -0x1]
//         0052babd     MOV        this,ESI
//         0052babf     PUSH       EDI
//         0052bac0     CALL       T_Scenario::Get_player_Food                      int Get_player_Food(T_Scenario * this, int pa
//         0052bac5     MOV        EDX,dword ptr [ESI + 0x8]
//         0052bac8     MOV        dword ptr [ESP + local_4],EAX
//         0052bacc     FILD       dword ptr [ESP + local_4]
//         0052bad0     MOV        EAX,dword ptr [EDX + 0x40]
//         0052bad3     PUSH       this
//         0052bad4     FSTP       float ptr [ESP]=>local_1c
//         0052bad7     MOV        this,dword ptr [EAX + EBX*0x4]
//         0052bada     PUSH       0x0
//         0052badc     CALL       RGE_Player::new_attribute_num                    void new_attribute_num(RGE_Player * this, sho
//                              tscenaro.cpp:782 (36)
//         0052bae1     PUSH       EDI
//         0052bae2     MOV        this,ESI
//         0052bae4     CALL       T_Scenario::Get_player_Stone                     int Get_player_Stone(T_Scenario * this, int p
//         0052bae9     MOV        dword ptr [ESP + local_4],EAX
//         0052baed     PUSH       this
//         0052baee     MOV        this,dword ptr [ESI + 0x8]
//         0052baf1     FILD       dword ptr [ESP + local_4]
//         0052baf5     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0052baf8     FSTP       float ptr [ESP]=>local_1c
//         0052bafb     MOV        this,dword ptr [EDX + EBX*0x4]
//         0052bafe     PUSH       0x2
//         0052bb00     CALL       RGE_Player::new_attribute_num                    void new_attribute_num(RGE_Player * this, sho
//                              tscenaro.cpp:783 (36)
//         0052bb05     PUSH       EDI
//         0052bb06     MOV        this,ESI
//         0052bb08     CALL       T_Scenario::Get_player_Gold                      int Get_player_Gold(T_Scenario * this, int pa
//         0052bb0d     MOV        dword ptr [ESP + local_4],EAX
//         0052bb11     MOV        EAX,dword ptr [ESI + 0x8]
//         0052bb14     FILD       dword ptr [ESP + local_4]
//         0052bb18     PUSH       this
//         0052bb19     MOV        this,dword ptr [EAX + 0x40]
//         0052bb1c     FSTP       float ptr [ESP]=>local_1c
//         0052bb1f     MOV        this,dword ptr [this->_padding_ + EBX*0x4]
//         0052bb22     PUSH       0x3
//         0052bb24     CALL       RGE_Player::new_attribute_num                    void new_attribute_num(RGE_Player * this, sho
//                              tscenaro.cpp:784 (36)
//         0052bb29     PUSH       EDI
//         0052bb2a     MOV        this,ESI
//         0052bb2c     CALL       T_Scenario::Get_player_Wood                      int Get_player_Wood(T_Scenario * this, int pa
//         0052bb31     MOV        EDX,dword ptr [ESI + 0x8]
//         0052bb34     MOV        dword ptr [ESP + local_4],EAX
//         0052bb38     FILD       dword ptr [ESP + local_4]
//         0052bb3c     MOV        EAX,dword ptr [EDX + 0x40]
//         0052bb3f     PUSH       this
//         0052bb40     FSTP       float ptr [ESP]=>local_1c
//         0052bb43     MOV        this,dword ptr [EAX + EBX*0x4]
//         0052bb46     PUSH       0x1
//         0052bb48     CALL       RGE_Player::new_attribute_num                    void new_attribute_num(RGE_Player * this, sho
//                              tscenaro.cpp:785 (14)
//         0052bb4d     MOV        EAX,dword ptr [ESI + 0x8]
//         0052bb50     MOV        EDI,0x1
//         0052bb55     CMP        word ptr [EAX + 0x3c],DI
//         0052bb59     JLE        LAB_0052bb7e
//                               LAB_0052bb5b                                                 XREF[1]:     0052bb7c(j)
//                              tscenaro.cpp:786 (4)
//         0052bb5b     CMP        EDI,EBX
//         0052bb5d     JZ         LAB_0052bb72
//                              tscenaro.cpp:787 (31)
//         0052bb5f     MOV        EAX,dword ptr [EAX + 0x40]
//         0052bb62     LEA        this,[EDI + EBP*0x1]
//         0052bb65     MOV        DL,byte ptr [ESI + this->_padding_*0x4]
//         0052bb68     MOV        this,dword ptr [EAX + EBX*0x4]
//         0052bb6b     PUSH       EDX
//         0052bb6c     PUSH       EDI
//         0052bb6d     CALL       RGE_Player::set_relation                         void set_relation(RGE_Player * this, long par
//                               LAB_0052bb72                                                 XREF[1]:     0052bb5d(j)
//         0052bb72     MOV        EAX,dword ptr [ESI + 0x8]
//         0052bb75     INC        EDI
//         0052bb76     MOVSX      this,word ptr [EAX + 0x3c]
//         0052bb7a     CMP        EDI,this
//         0052bb7c     JL         LAB_0052bb5b
//                               LAB_0052bb7e                                                 XREF[1]:     0052bb59(j)
//                              tscenaro.cpp:789 (49)
//         0052bb7e     MOV        EAX,dword ptr [ESI + 0x8]
//         0052bb81     MOV        EDI,dword ptr [ESP + local_8]
//         0052bb85     MOV        this,dword ptr [EAX + 0x40]
//         0052bb88     MOV        DL,byte ptr [EDI]
//         0052bb8a     PUSH       EDX
//         0052bb8b     MOV        this,dword ptr [this->_padding_ + EBX*0x4]
//         0052bb8e     CALL       RGE_Player::set_allied_victory                   void set_allied_victory(RGE_Player * this, uc
//         0052bb93     MOV        EDX,dword ptr [ESI + 0x8]
//         0052bb96     INC        EBX
//         0052bb97     ADD        EBP,0x10
//         0052bb9a     ADD        EDI,0x4
//         0052bb9d     MOVSX      EAX,word ptr [EDX + 0x3c]
//         0052bba1     CMP        EBX,EAX
//         0052bba3     MOV        dword ptr [ESP + local_8],EDI
//         0052bba7     JL         LAB_0052baba
//         0052bbad     POP        EBP
//         0052bbae     POP        EDI
//                               LAB_0052bbaf                                                 XREF[1]:     0052baa3(j)
//                              tscenaro.cpp:791 (6)
//         0052bbaf     POP        ESI
//         0052bbb0     POP        EBX
//         0052bbb1     ADD        ESP,0x8
//         0052bbb4     RET
//         0052bbb5     ??         90h
//         0052bbb6     NOP
//         0052bbb7     NOP
//         0052bbb8     NOP
//         0052bbb9     NOP
//         0052bbba     NOP
//         0052bbbb     NOP
//         0052bbbc     NOP
//         0052bbbd     NOP
//         0052bbbe     NOP
//         0052bbbf     NOP
    return;
}

void T_Scenario::Save_victory_conditions_into_players(int param_1) {
    /* TODO: Stub */
//                              void __thiscall Save_victory_conditions_into_players(T_Scenario * th
//              void              <VOID>         <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[5]:     0052bbc0(R), 0052bd75(W), 0052bf3c(R), 0052c028(R),
//                                                                                     0052c037(W)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0052bf22(W), 0052bf36(R)
//              undefined4        Stack[-0x8]:4  local_8                   XREF[3]:     0052bd60(W), 0052c030(R), 0052c046(W)
//              int               Stack[-0xc]:4  j                         XREF[4]:     0052bd7d(W), 0052bd8e(R), 0052c02c(R), 0052c042(W)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[3]:     0052bd9a(W), 0052c013(R), 0052c01e(W)
//              int               Stack[-0x14]:4 i
//                               ?Save_victory_conditions_into_players@T_Scenario@@QAEXH@Z    XREF[5]:     command_save:004ad732(c),
//                               T_Scenario::Save_victory_conditions_into_players                          command_save_as:004ad990(c),
//                                                                                                         scenario_save_defaulted:004adb25(c
//                                                                                                         load_multi_victory_cond_from_scena
//                                                                                                         new_game:0052f8af(c)
//                              tscenaro.cpp:795 (17)
//         0052bbc0     MOV        EAX,dword ptr [ESP + param_1]
//         0052bbc4     SUB        ESP,0x10
//         0052bbc7     TEST       EAX,EAX
//         0052bbc9     PUSH       EBX
//         0052bbca     PUSH       EBP
//         0052bbcb     PUSH       ESI
//         0052bbcc     PUSH       EDI
//         0052bbcd     MOV        EBX,this
//         0052bbcf     JZ         LAB_0052bbd6
//                              tscenaro.cpp:801 (5)
//         0052bbd1     CALL       T_Scenario::SaveAttributesIntoPlayers            void SaveAttributesIntoPlayers(T_Scenario * t
//                               LAB_0052bbd6                                                 XREF[1]:     0052bbcf(j)
//                              tscenaro.cpp:803 (16)
//         0052bbd6     MOV        EAX,dword ptr [EBX + 0x8]
//         0052bbd9     MOV        EBP,0x1
//         0052bbde     MOV        ESI,EBP
//         0052bbe0     CMP        word ptr [EAX + 0x3c],BP
//         0052bbe4     JLE        LAB_0052bc00
//                               LAB_0052bbe6                                                 XREF[1]:     0052bbfe(j)
//                              tscenaro.cpp:804 (26)
//         0052bbe6     MOV        EAX,dword ptr [EAX + 0x40]
//         0052bbe9     MOV        this,dword ptr [EAX + ESI*0x4]
//         0052bbec     MOV        this,dword ptr [ECX + this->_padding_]
//         0052bbef     CALL       RGE_Victory_Conditions::destroy_all              void destroy_all(RGE_Victory_Conditions * this)
//         0052bbf4     MOV        EAX,dword ptr [EBX + 0x8]
//         0052bbf7     INC        ESI
//         0052bbf8     MOVSX      EDX,word ptr [EAX + 0x3c]
//         0052bbfc     CMP        ESI,EDX
//         0052bbfe     JL         LAB_0052bbe6
//                               LAB_0052bc00                                                 XREF[1]:     0052bbe4(j)
//                              tscenaro.cpp:806 (13)
//         0052bc00     CMP        dword ptr [EBX + 0x5140],0x4
//         0052bc07     JNZ        LAB_0052bd5d
//                              tscenaro.cpp:808 (14)
//         0052bc0d     MOV        EAX,dword ptr [EBX + 0x4be8]
//         0052bc13     TEST       EAX,EAX
//         0052bc15     JZ         LAB_0052bcc3
//                              tscenaro.cpp:810 (15)
//         0052bc1b     MOV        EAX,dword ptr [EBX + 0x8]
//         0052bc1e     MOV        EDI,EBP
//         0052bc20     CMP        word ptr [EAX + 0x3c],BP
//         0052bc24     JLE        LAB_0052bcb5
//                               LAB_0052bc2a                                                 XREF[1]:     0052bcaf(j)
//                              tscenaro.cpp:812 (6)
//         0052bc2a     MOV        EAX,dword ptr [EAX + 0x40]
//         0052bc2d     MOV        this,dword ptr [EAX + EDI*0x4]
//                              tscenaro.cpp:813 (13)
//         0052bc30     MOV        EAX,dword ptr [EBX + 0x1aa0]
//         0052bc36     TEST       EAX,EAX
//         0052bc38     MOV        ESI,dword ptr [ECX + this->_padding_]
//         0052bc3b     JZ         LAB_0052bc48
//                              tscenaro.cpp:814 (11)
//         0052bc3d     PUSH       EBP
//         0052bc3e     PUSH       EAX
//         0052bc3f     PUSH       0x8
//         0052bc41     MOV        this,ESI
//         0052bc43     CALL       RGE_Victory_Conditions::add_explore              uchar add_explore(RGE_Victory_Conditions * th
//                               LAB_0052bc48                                                 XREF[1]:     0052bc3b(j)
//                              tscenaro.cpp:815 (10)
//         0052bc48     MOV        EAX,dword ptr [EBX + 0x1a94]
//         0052bc4e     TEST       EAX,EAX
//         0052bc50     JZ         LAB_0052bc5f
//                              tscenaro.cpp:816 (13)
//         0052bc52     PUSH       EBP
//         0052bc53     PUSH       EAX
//         0052bc54     PUSH       0xe
//         0052bc56     PUSH       0x8
//         0052bc58     MOV        this,ESI
//         0052bc5a     CALL       RGE_Victory_Conditions::add_attributes           uchar add_attributes(RGE_Victory_Conditions *
//                               LAB_0052bc5f                                                 XREF[1]:     0052bc50(j)
//                              tscenaro.cpp:817 (10)
//         0052bc5f     MOV        EAX,dword ptr [EBX + 0x1a98]
//         0052bc65     TEST       EAX,EAX
//         0052bc67     JZ         LAB_0052bc76
//                              tscenaro.cpp:818 (13)
//         0052bc69     PUSH       EBP
//         0052bc6a     PUSH       EAX
//         0052bc6b     PUSH       0x7
//         0052bc6d     PUSH       0x8
//         0052bc6f     MOV        this,ESI
//         0052bc71     CALL       RGE_Victory_Conditions::add_attributes           uchar add_attributes(RGE_Victory_Conditions *
//                               LAB_0052bc76                                                 XREF[1]:     0052bc67(j)
//                              tscenaro.cpp:819 (10)
//         0052bc76     MOV        EAX,dword ptr [EBX + 0x1a9c]
//         0052bc7c     TEST       EAX,EAX
//         0052bc7e     JZ         LAB_0052bc8e
//                              tscenaro.cpp:820 (14)
//         0052bc80     PUSH       0x0
//         0052bc82     PUSH       EAX
//         0052bc83     PUSH       0xd
//         0052bc85     PUSH       0x8
//         0052bc87     MOV        this,ESI
//         0052bc89     CALL       RGE_Victory_Conditions::add_attributes           uchar add_attributes(RGE_Victory_Conditions *
//                               LAB_0052bc8e                                                 XREF[1]:     0052bc7e(j)
//                              tscenaro.cpp:821 (10)
//         0052bc8e     MOV        EAX,dword ptr [EBX + 0x1aa4]
//         0052bc94     TEST       EAX,EAX
//         0052bc96     JZ         LAB_0052bca5
//                              tscenaro.cpp:822 (29)
//         0052bc98     PUSH       EBP
//         0052bc99     PUSH       EAX
//         0052bc9a     PUSH       0x3
//         0052bc9c     PUSH       0x8
//         0052bc9e     MOV        this,ESI
//         0052bca0     CALL       RGE_Victory_Conditions::add_attributes           uchar add_attributes(RGE_Victory_Conditions *
//                               LAB_0052bca5                                                 XREF[1]:     0052bc96(j)
//         0052bca5     MOV        EAX,dword ptr [EBX + 0x8]
//         0052bca8     INC        EDI
//         0052bca9     MOVSX      EDX,word ptr [EAX + 0x3c]
//         0052bcad     CMP        EDI,EDX
//         0052bcaf     JL         LAB_0052bc2a
//                               LAB_0052bcb5                                                 XREF[1]:     0052bc24(j)
//                              tscenaro.cpp:826 (14)
//         0052bcb5     MOV        EAX,dword ptr [EBX + 0x4be8]
//         0052bcbb     TEST       EAX,EAX
//         0052bcbd     JNZ        LAB_0052bd5d
//                               LAB_0052bcc3                                                 XREF[1]:     0052bc15(j)
//                              tscenaro.cpp:828 (15)
//         0052bcc3     MOV        EAX,dword ptr [EBX + 0x8]
//         0052bcc6     MOV        EDI,EBP
//         0052bcc8     CMP        word ptr [EAX + 0x3c],BP
//         0052bccc     JLE        LAB_0052bd5d
//                               LAB_0052bcd2                                                 XREF[1]:     0052bd57(j)
//                              tscenaro.cpp:830 (6)
//         0052bcd2     MOV        EAX,dword ptr [EAX + 0x40]
//         0052bcd5     MOV        this,dword ptr [EAX + EDI*0x4]
//                              tscenaro.cpp:831 (13)
//         0052bcd8     MOV        EAX,dword ptr [EBX + 0x1aa0]
//         0052bcde     TEST       EAX,EAX
//         0052bce0     MOV        ESI,dword ptr [ECX + this->_padding_]
//         0052bce3     JZ         LAB_0052bcf0
//                              tscenaro.cpp:832 (11)
//         0052bce5     PUSH       EBP
//         0052bce6     PUSH       EAX
//         0052bce7     PUSH       0x8
//         0052bce9     MOV        this,ESI
//         0052bceb     CALL       RGE_Victory_Conditions::add_explore              uchar add_explore(RGE_Victory_Conditions * th
//                               LAB_0052bcf0                                                 XREF[1]:     0052bce3(j)
//                              tscenaro.cpp:833 (10)
//         0052bcf0     MOV        EAX,dword ptr [EBX + 0x1a94]
//         0052bcf6     TEST       EAX,EAX
//         0052bcf8     JZ         LAB_0052bd07
//                              tscenaro.cpp:834 (13)
//         0052bcfa     PUSH       EBP
//         0052bcfb     PUSH       EAX
//         0052bcfc     PUSH       0xe
//         0052bcfe     PUSH       0x9
//         0052bd00     MOV        this,ESI
//         0052bd02     CALL       RGE_Victory_Conditions::add_attributes           uchar add_attributes(RGE_Victory_Conditions *
//                               LAB_0052bd07                                                 XREF[1]:     0052bcf8(j)
//                              tscenaro.cpp:835 (10)
//         0052bd07     MOV        EAX,dword ptr [EBX + 0x1a98]
//         0052bd0d     TEST       EAX,EAX
//         0052bd0f     JZ         LAB_0052bd1e
//                              tscenaro.cpp:836 (13)
//         0052bd11     PUSH       EBP
//         0052bd12     PUSH       EAX
//         0052bd13     PUSH       0x7
//         0052bd15     PUSH       0xa
//         0052bd17     MOV        this,ESI
//         0052bd19     CALL       RGE_Victory_Conditions::add_attributes           uchar add_attributes(RGE_Victory_Conditions *
//                               LAB_0052bd1e                                                 XREF[1]:     0052bd0f(j)
//                              tscenaro.cpp:837 (10)
//         0052bd1e     MOV        EAX,dword ptr [EBX + 0x1a9c]
//         0052bd24     TEST       EAX,EAX
//         0052bd26     JZ         LAB_0052bd36
//                              tscenaro.cpp:838 (14)
//         0052bd28     PUSH       0x0
//         0052bd2a     PUSH       EAX
//         0052bd2b     PUSH       0xd
//         0052bd2d     PUSH       0xb
//         0052bd2f     MOV        this,ESI
//         0052bd31     CALL       RGE_Victory_Conditions::add_attributes           uchar add_attributes(RGE_Victory_Conditions *
//                               LAB_0052bd36                                                 XREF[1]:     0052bd26(j)
//                              tscenaro.cpp:839 (10)
//         0052bd36     MOV        EAX,dword ptr [EBX + 0x1aa4]
//         0052bd3c     TEST       EAX,EAX
//         0052bd3e     JZ         LAB_0052bd4d
//                              tscenaro.cpp:840 (29)
//         0052bd40     PUSH       EBP
//         0052bd41     PUSH       EAX
//         0052bd42     PUSH       0x3
//         0052bd44     PUSH       0xc
//         0052bd46     MOV        this,ESI
//         0052bd48     CALL       RGE_Victory_Conditions::add_attributes           uchar add_attributes(RGE_Victory_Conditions *
//                               LAB_0052bd4d                                                 XREF[1]:     0052bd3e(j)
//         0052bd4d     MOV        EAX,dword ptr [EBX + 0x8]
//         0052bd50     INC        EDI
//         0052bd51     MOVSX      EDX,word ptr [EAX + 0x3c]
//         0052bd55     CMP        EDI,EDX
//         0052bd57     JL         LAB_0052bcd2
//                               LAB_0052bd5d                                                 XREF[3]:     0052bc07(j), 0052bcbd(j),
//                                                                                                         0052bccc(j)
//                              tscenaro.cpp:845 (46)
//         0052bd5d     MOV        EAX,dword ptr [EBX + 0x8]
//         0052bd60     MOV        dword ptr [ESP + local_8],0x0
//         0052bd68     MOVSX      this,word ptr [EAX + 0x3c]
//         0052bd6c     DEC        this
//         0052bd6d     TEST       this,this
//         0052bd6f     JLE        LAB_0052c057
//         0052bd75     MOV        dword ptr [ESP + param_1],0x72
//         0052bd7d     MOV        dword ptr [ESP + j],0x4
//         0052bd85     LEA        ESI,[EBX + 0x1ad0]
//                               LAB_0052bd8b                                                 XREF[1]:     0052c051(j)
//                              tscenaro.cpp:848 (13)
//         0052bd8b     MOV        EDX,dword ptr [EAX + 0x40]
//         0052bd8e     MOV        EAX,dword ptr [ESP + j]
//         0052bd92     MOV        this,dword ptr [EDX + EAX*0x1]
//         0052bd95     MOV        EDI,dword ptr [ECX + this->_padding_]
//                              tscenaro.cpp:851 (6)
//         0052bd98     XOR        this,this
//         0052bd9a     MOV        dword ptr [ESP + local_10],this
//                               LAB_0052bd9e                                                 XREF[1]:     0052c022(j)
//                              tscenaro.cpp:854 (11)
//         0052bd9e     MOV        EAX,dword ptr [ESI + -0x8]
//         0052bda1     TEST       EAX,EAX
//         0052bda3     JZ         LAB_0052c013
//                              tscenaro.cpp:857 (9)
//         0052bda9     CMP        EAX,0x4
//         0052bdac     JNZ        LAB_0052be70
//                              tscenaro.cpp:859 (7)
//         0052bdb2     MOV        EAX,dword ptr [ESI]
//         0052bdb4     CMP        EAX,0x6
//         0052bdb7     JNZ        LAB_0052bdcd
//                              tscenaro.cpp:861 (15)
//         0052bdb9     MOV        EDX,dword ptr [ESI + -0x4]
//         0052bdbc     PUSH       0x1
//         0052bdbe     PUSH       EDX
//         0052bdbf     PUSH       0x1
//         0052bdc1     MOV        this,EDI
//         0052bdc3     CALL       RGE_Victory_Conditions::add_explore              uchar add_explore(RGE_Victory_Conditions * th
//                              tscenaro.cpp:863 (10)
//         0052bdc8     JMP        LAB_0052c013
//                               LAB_0052bdcd                                                 XREF[1]:     0052bdb7(j)
//         0052bdcd     CMP        EAX,0x4
//         0052bdd0     JNZ        LAB_0052bde8
//                              tscenaro.cpp:865 (17)
//         0052bdd2     MOV        EAX,dword ptr [ESI + -0x4]
//         0052bdd5     PUSH       0x0
//         0052bdd7     PUSH       EAX
//         0052bdd8     PUSH       0xb
//         0052bdda     PUSH       0x1
//         0052bddc     MOV        this,EDI
//         0052bdde     CALL       RGE_Victory_Conditions::add_attributes           uchar add_attributes(RGE_Victory_Conditions *
//                              tscenaro.cpp:867 (10)
//         0052bde3     JMP        LAB_0052c013
//                               LAB_0052bde8                                                 XREF[1]:     0052bdd0(j)
//         0052bde8     CMP        EAX,0x3
//         0052bdeb     JNZ        LAB_0052be03
//                              tscenaro.cpp:869 (17)
//         0052bded     MOV        this,dword ptr [ESI + -0x4]
//         0052bdf0     PUSH       0x0
//         0052bdf2     PUSH       this
//         0052bdf3     PUSH       0x0
//         0052bdf5     PUSH       0x1
//         0052bdf7     MOV        this,EDI
//         0052bdf9     CALL       RGE_Victory_Conditions::add_attributes           uchar add_attributes(RGE_Victory_Conditions *
//                              tscenaro.cpp:871 (10)
//         0052bdfe     JMP        LAB_0052c013
//                               LAB_0052be03                                                 XREF[1]:     0052bdeb(j)
//         0052be03     CMP        EAX,0x2
//         0052be06     JNZ        LAB_0052be1d
//                              tscenaro.cpp:873 (16)
//         0052be08     MOV        EDX,dword ptr [ESI + -0x4]
//         0052be0b     PUSH       0x0
//         0052be0d     PUSH       EDX
//         0052be0e     PUSH       EAX
//         0052be0f     PUSH       0x1
//         0052be11     MOV        this,EDI
//         0052be13     CALL       RGE_Victory_Conditions::add_attributes           uchar add_attributes(RGE_Victory_Conditions *
//                              tscenaro.cpp:875 (10)
//         0052be18     JMP        LAB_0052c013
//                               LAB_0052be1d                                                 XREF[1]:     0052be06(j)
//         0052be1d     CMP        EAX,0x1
//         0052be20     JNZ        LAB_0052be38
//                              tscenaro.cpp:877 (17)
//         0052be22     MOV        EAX,dword ptr [ESI + -0x4]
//         0052be25     PUSH       0x0
//         0052be27     PUSH       EAX
//         0052be28     PUSH       0x1
//         0052be2a     PUSH       0x1
//         0052be2c     MOV        this,EDI
//         0052be2e     CALL       RGE_Victory_Conditions::add_attributes           uchar add_attributes(RGE_Victory_Conditions *
//                              tscenaro.cpp:879 (9)
//         0052be33     JMP        LAB_0052c013
//                               LAB_0052be38                                                 XREF[1]:     0052be20(j)
//         0052be38     TEST       EAX,EAX
//         0052be3a     JNZ        LAB_0052be51
//                              tscenaro.cpp:881 (16)
//         0052be3c     MOV        this,dword ptr [ESI + -0x4]
//         0052be3f     PUSH       EAX
//         0052be40     PUSH       this
//         0052be41     PUSH       0x3
//         0052be43     PUSH       0x1
//         0052be45     MOV        this,EDI
//         0052be47     CALL       RGE_Victory_Conditions::add_attributes           uchar add_attributes(RGE_Victory_Conditions *
//                              tscenaro.cpp:883 (14)
//         0052be4c     JMP        LAB_0052c013
//                               LAB_0052be51                                                 XREF[1]:     0052be3a(j)
//         0052be51     CMP        EAX,0x5
//         0052be54     JNZ        LAB_0052c013
//                              tscenaro.cpp:885 (17)
//         0052be5a     MOV        EDX,dword ptr [ESI + -0x4]
//         0052be5d     PUSH       0x0
//         0052be5f     PUSH       EDX
//         0052be60     PUSH       0x6
//         0052be62     PUSH       0x1
//         0052be64     MOV        this,EDI
//         0052be66     CALL       RGE_Victory_Conditions::add_attributes           uchar add_attributes(RGE_Victory_Conditions *
//                              tscenaro.cpp:888 (10)
//         0052be6b     JMP        LAB_0052c013
//                               LAB_0052be70                                                 XREF[1]:     0052bdac(j)
//         0052be70     CMP        EAX,0x6
//         0052be73     JNZ        LAB_0052be8c
//                              tscenaro.cpp:889 (18)
//         0052be75     MOV        EAX,dword ptr [ESI + -0x4]
//         0052be78     MOV        this,dword ptr [ESI]
//         0052be7a     PUSH       0x0
//         0052be7c     PUSH       EAX
//         0052be7d     PUSH       this
//         0052be7e     PUSH       0x1
//         0052be80     MOV        this,EDI
//         0052be82     CALL       RGE_Victory_Conditions::add_attributes           uchar add_attributes(RGE_Victory_Conditions *
//                              tscenaro.cpp:891 (10)
//         0052be87     JMP        LAB_0052c013
//                               LAB_0052be8c                                                 XREF[1]:     0052be73(j)
//         0052be8c     CMP        EAX,0x5
//         0052be8f     JNZ        LAB_0052beac
//                              tscenaro.cpp:893 (22)
//         0052be91     MOV        EAX,dword ptr [ESI + 0x4]
//         0052be94     MOV        EDX,dword ptr [EBX]
//         0052be96     PUSH       0x1
//         0052be98     PUSH       EAX
//         0052be99     MOV        this,EBX
//         0052be9b     CALL       dword ptr [EDX]
//         0052be9d     PUSH       EAX
//         0052be9e     PUSH       offset DAT_fffffff8
//         0052bea0     MOV        this,EDI
//         0052bea2     CALL       RGE_Victory_Conditions::add_capture              uchar add_capture(RGE_Victory_Conditions * th
//                              tscenaro.cpp:895 (10)
//         0052bea7     JMP        LAB_0052c013
//                               LAB_0052beac                                                 XREF[1]:     0052be8f(j)
//         0052beac     CMP        EAX,0x3
//         0052beaf     JNZ        LAB_0052bf18
//                              tscenaro.cpp:897 (16)
//         0052beb1     MOV        this,dword ptr [EBX]
//         0052beb3     MOV        EDX,dword ptr [ESI + 0x8]
//         0052beb6     PUSH       EDX
//         0052beb7     MOV        EBP,dword ptr [this->_padding_]
//         0052beb9     MOV        this,EBX
//         0052bebb     CALL       EBP
//         0052bebd     TEST       EAX,EAX
//         0052bebf     JZ         LAB_0052bee1
//                              tscenaro.cpp:898 (27)
//         0052bec1     MOV        EAX,dword ptr [ESI + 0x8]
//         0052bec4     MOV        this,EBX
//         0052bec6     PUSH       EAX
//         0052bec7     CALL       EBP
//         0052bec9     MOV        this,dword ptr [ESI + 0x4]
//         0052becc     PUSH       EAX
//         0052becd     PUSH       this=>DAT_fffffff8
//         0052bece     MOV        this,EBX
//         0052bed0     CALL       EBP
//         0052bed2     PUSH       EAX
//         0052bed3     PUSH       offset DAT_fffffff8
//         0052bed5     MOV        this,EDI
//         0052bed7     CALL       RGE_Victory_Conditions::add_bring                uchar add_bring(RGE_Victory_Conditions * this
//                              tscenaro.cpp:899 (5)
//         0052bedc     JMP        LAB_0052c013
//                               LAB_0052bee1                                                 XREF[1]:     0052bebf(j)
//                              tscenaro.cpp:902 (50)
//         0052bee1     MOV        EDX,dword ptr [ESI + -0xc]
//         0052bee4     MOV        EAX,dword ptr [ESI + -0x10]
//         0052bee7     MOV        this,dword ptr [ESI + -0x14]
//         0052beea     PUSH       EDX
//         0052beeb     MOV        EDX,dword ptr [ESP + 0x14]
//         0052beef     PUSH       EAX=>DAT_fffffff8
//         0052bef0     MOV        EAX,dword ptr [ESP + 0x2c]
//         0052bef4     PUSH       this=>DAT_fffffff4
//         0052bef5     ADD        EAX,EDX
//         0052bef7     LEA        EAX,[EAX + EAX*0x2]
//         0052befa     LEA        this,[EAX + EAX*0x4]
//         0052befd     MOV        EAX,dword ptr [ESI + 0x4]
//         0052bf00     MOV        EDX,dword ptr [EBX + this->_padding_*0x4]
//         0052bf03     MOV        this,EBX
//         0052bf05     PUSH       EDX=>DAT_fffffff0
//         0052bf06     PUSH       EAX
//         0052bf07     CALL       EBP
//         0052bf09     PUSH       EAX
//         0052bf0a     PUSH       offset DAT_fffffff8
//         0052bf0c     MOV        this,EDI
//         0052bf0e     CALL       RGE_Victory_Conditions::add_bring                uchar add_bring(RGE_Victory_Conditions * this
//                              tscenaro.cpp:904 (10)
//         0052bf13     JMP        LAB_0052c013
//                               LAB_0052bf18                                                 XREF[1]:     0052beaf(j)
//         0052bf18     CMP        EAX,0x2
//         0052bf1b     JNZ        LAB_0052bf7c
//                              tscenaro.cpp:906 (3)
//         0052bf1d     FLD        float ptr [ESI + -0x10]
//                              tscenaro.cpp:909 (65)
//         0052bf20     PUSH       0x0
//         0052bf22     FST        float ptr [ESP + local_4]
//         0052bf26     FCOMP      double ptr [DAT_00577330]
//         0052bf2c     FNSTSW     AX
//         0052bf2e     TEST       AH,0x41
//         0052bf31     JNZ        LAB_0052bf66
//         0052bf33     MOV        EDX,dword ptr [ESI + -0xc]
//         0052bf36     MOV        EAX,dword ptr [ESP + local_4]
//         0052bf3a     PUSH       EDX
//         0052bf3b     PUSH       EAX
//         0052bf3c     MOV        EAX,dword ptr [ESP + param_1]
//         0052bf40     MOV        EDX,dword ptr [ESI + -0x14]
//         0052bf43     ADD        EAX,this
//         0052bf45     PUSH       EDX
//         0052bf46     LEA        EAX,[EAX + EAX*0x2]
//         0052bf49     LEA        this,[EAX + EAX*0x4]
//         0052bf4c     MOV        EAX,dword ptr [ESI + -0x4]
//         0052bf4f     MOV        EDX,dword ptr [EBX + this->_padding_*0x4]
//         0052bf52     MOV        this,dword ptr [ESI + -0x28]
//         0052bf55     PUSH       EDX
//         0052bf56     PUSH       EAX
//         0052bf57     PUSH       this
//         0052bf58     PUSH       0x1
//         0052bf5a     MOV        this,EDI
//         0052bf5c     CALL       RGE_Victory_Conditions::add_create               uchar add_create(RGE_Victory_Conditions * thi
//                              tscenaro.cpp:910 (5)
//         0052bf61     JMP        LAB_0052c013
//                               LAB_0052bf66                                                 XREF[1]:     0052bf31(j)
//                              tscenaro.cpp:911 (17)
//         0052bf66     MOV        EDX,dword ptr [ESI + -0x4]
//         0052bf69     MOV        EAX,dword ptr [ESI + -0x28]
//         0052bf6c     PUSH       EDX
//         0052bf6d     PUSH       EAX
//         0052bf6e     PUSH       0x1
//         0052bf70     MOV        this,EDI
//         0052bf72     CALL       RGE_Victory_Conditions::add_create               uchar add_create(RGE_Victory_Conditions * thi
//                              tscenaro.cpp:913 (10)
//         0052bf77     JMP        LAB_0052c013
//                               LAB_0052bf7c                                                 XREF[1]:     0052bf1b(j)
//         0052bf7c     CMP        EAX,0x7
//         0052bf7f     JNZ        LAB_0052bf92
//                              tscenaro.cpp:914 (12)
//         0052bf81     MOV        this,dword ptr [ESI]
//         0052bf83     PUSH       this
//         0052bf84     PUSH       0x1
//         0052bf86     MOV        this,EDI
//         0052bf88     CALL       TRIBE_Victory_Conditions::add_tech               uchar add_tech(TRIBE_Victory_Conditions * thi
//                              tscenaro.cpp:915 (10)
//         0052bf8d     JMP        LAB_0052c013
//                               LAB_0052bf92                                                 XREF[1]:     0052bf7f(j)
//         0052bf92     CMP        EAX,0x1
//         0052bf95     JNZ        LAB_0052c013
//                              tscenaro.cpp:918 (14)
//         0052bf97     MOV        this,dword ptr [ESI + -0x28]
//         0052bf9a     TEST       this,this
//         0052bf9c     JZ         LAB_0052bfb3
//         0052bf9e     MOV        EAX,dword ptr [ESI + -0x24]
//         0052bfa1     TEST       EAX,EAX
//         0052bfa3     JZ         LAB_0052bfb3
//                              tscenaro.cpp:920 (12)
//         0052bfa5     PUSH       0x0
//         0052bfa7     PUSH       this
//         0052bfa8     PUSH       0x1
//         0052bfaa     MOV        this,EDI
//         0052bfac     CALL       RGE_Victory_Conditions::add_destroy              uchar add_destroy(RGE_Victory_Conditions * th
//                              tscenaro.cpp:922 (13)
//         0052bfb1     JMP        LAB_0052c013
//                               LAB_0052bfb3                                                 XREF[2]:     0052bf9c(j), 0052bfa3(j)
//         0052bfb3     MOV        EAX,dword ptr [ESI + -0x20]
//         0052bfb6     TEST       EAX,EAX
//         0052bfb8     JZ         LAB_0052bff1
//         0052bfba     TEST       this,this
//         0052bfbc     JZ         LAB_0052bfd8
//                              tscenaro.cpp:925 (24)
//         0052bfbe     MOV        EDX,dword ptr [EBX + 0x8]
//         0052bfc1     MOV        EDX,dword ptr [EDX + 0x40]
//         0052bfc4     MOV        EAX,dword ptr [EDX + EAX*0x4]
//         0052bfc7     MOV        EDX,dword ptr [ESI + -0x4]
//         0052bfca     PUSH       EAX
//         0052bfcb     PUSH       EDX
//         0052bfcc     PUSH       this
//         0052bfcd     PUSH       0x1
//         0052bfcf     MOV        this,EDI
//         0052bfd1     CALL       RGE_Victory_Conditions::add_destroy              uchar add_destroy(RGE_Victory_Conditions * th
//                              tscenaro.cpp:927 (6)
//         0052bfd6     JMP        LAB_0052c013
//                               LAB_0052bfd8                                                 XREF[1]:     0052bfbc(j)
//         0052bfd8     TEST       EAX,EAX
//         0052bfda     JZ         LAB_0052bff1
//                              tscenaro.cpp:929 (19)
//         0052bfdc     MOV        this,dword ptr [EBX + 0x8]
//         0052bfdf     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0052bfe2     MOV        this,EDI
//         0052bfe4     MOV        EAX,dword ptr [EDX + EAX*0x4]
//         0052bfe7     PUSH       EAX
//         0052bfe8     PUSH       0x1
//         0052bfea     CALL       RGE_Victory_Conditions::add_destroy              uchar add_destroy(RGE_Victory_Conditions * th
//                              tscenaro.cpp:931 (18)
//         0052bfef     JMP        LAB_0052c013
//                               LAB_0052bff1                                                 XREF[2]:     0052bfb8(j), 0052bfda(j)
//         0052bff1     MOV        this,dword ptr [EBX]
//         0052bff3     MOV        EDX,dword ptr [ESI + 0x4]
//         0052bff6     PUSH       EDX
//         0052bff7     MOV        EBP,dword ptr [this->_padding_]
//         0052bff9     MOV        this,EBX
//         0052bffb     CALL       EBP
//         0052bffd     TEST       EAX,EAX
//         0052bfff     JZ         LAB_0052c013
//                              tscenaro.cpp:933 (86)
//         0052c001     MOV        EAX,dword ptr [ESI + 0x4]
//         0052c004     MOV        this,EBX
//         0052c006     PUSH       EAX
//         0052c007     CALL       EBP
//         0052c009     PUSH       EAX
//         0052c00a     PUSH       offset DAT_fffffff8
//         0052c00c     MOV        this,EDI
//         0052c00e     CALL       RGE_Victory_Conditions::add_destroy              uchar add_destroy(RGE_Victory_Conditions * th
//                               LAB_0052c013                                                 XREF[21]:    0052bda3(j), 0052bdc8(j),
//                                                                                                         0052bde3(j), 0052bdfe(j),
//                                                                                                         0052be18(j), 0052be33(j),
//                                                                                                         0052be4c(j), 0052be54(j),
//                                                                                                         0052be6b(j), 0052be87(j),
//                                                                                                         0052bea7(j), 0052bedc(j),
//                                                                                                         0052bf13(j), 0052bf61(j),
//                                                                                                         0052bf77(j), 0052bf8d(j),
//                                                                                                         0052bf95(j), 0052bfb1(j),
//                                                                                                         0052bfd6(j), 0052bfef(j), [more]
//         0052c013     MOV        this,dword ptr [ESP + local_10]
//         0052c017     ADD        ESI,0x3c
//         0052c01a     INC        this
//         0052c01b     CMP        this,0xc
//         0052c01e     MOV        dword ptr [ESP + local_10],this
//         0052c022     JL         LAB_0052bd9e
//         0052c028     MOV        EAX,dword ptr [ESP + param_1]
//         0052c02c     MOV        EDX,dword ptr [ESP + j]
//         0052c030     MOV        this,dword ptr [ESP + local_8]
//         0052c034     ADD        EAX,0xc
//         0052c037     MOV        dword ptr [ESP + param_1],EAX
//         0052c03b     MOV        EAX,dword ptr [EBX + 0x8]
//         0052c03e     ADD        EDX,0x4
//         0052c041     INC        this
//         0052c042     MOV        dword ptr [ESP + j],EDX
//         0052c046     MOV        dword ptr [ESP + local_8],this
//         0052c04a     MOVSX      EDX,word ptr [EAX + 0x3c]
//         0052c04e     DEC        EDX
//         0052c04f     CMP        this,EDX
//         0052c051     JL         LAB_0052bd8b
//                               LAB_0052c057                                                 XREF[1]:     0052bd6f(j)
//                              tscenaro.cpp:938 (10)
//         0052c057     POP        EDI
//         0052c058     POP        ESI
//         0052c059     POP        EBP
//         0052c05a     POP        EBX
//         0052c05b     ADD        ESP,0x10
//         0052c05e     RET        0x4
//         0052c061     ??         90h
//         0052c062     NOP
//         0052c063     NOP
//         0052c064     NOP
//         0052c065     NOP
//         0052c066     NOP
//         0052c067     NOP
//         0052c068     NOP
//         0052c069     NOP
//         0052c06a     NOP
//         0052c06b     NOP
//         0052c06c     NOP
//         0052c06d     NOP
//         0052c06e     NOP
//         0052c06f     NOP
    return;
}

void T_Scenario::rehook() {
    /* TODO: Stub */
//                              void __thiscall rehook(T_Scenario * this)
//              void              <VOID>         <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//                               ?rehook@T_Scenario@@UAEXXZ                                   XREF[1]:     00577310(*)
//                               T_Scenario::rehook
//                              tscenaro.cpp:942 (1)
//         0052c070     RET
//         0052c071     ??         90h
//         0052c072     NOP
//         0052c073     NOP
//         0052c074     NOP
//         0052c075     NOP
//         0052c076     NOP
//         0052c077     NOP
//         0052c078     NOP
//         0052c079     NOP
//         0052c07a     NOP
//         0052c07b     NOP
//         0052c07c     NOP
//         0052c07d     NOP
//         0052c07e     NOP
//         0052c07f     NOP
    return;
}

RGE_Static_Object* T_Scenario::get_object_pointer(int param_1) {
    /* TODO: Stub */
//                              RGE_Static_Object * __thiscall get_object_pointer(T_Scenario * this,
//              RGE_Static_Obj    EAX:4          <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0052c080(R)
//                               ?get_object_pointer@T_Scenario@@EAEPAVRGE_Static_Object@@H@Z XREF[1]:     00577308(*)
//                               T_Scenario::get_object_pointer
//                              tscenaro.cpp:968 (10)
//         0052c080     MOV        EDX,dword ptr [ESP + param_1]
//         0052c084     XOR        EAX,EAX
//         0052c086     TEST       EDX,EDX
//         0052c088     JLE        LAB_0052c094
//                              tscenaro.cpp:974 (10)
//         0052c08a     MOV        this,dword ptr [ECX + this->_padding_]
//         0052c08d     DEC        EDX
//         0052c08e     PUSH       EDX
//         0052c08f     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
//                               LAB_0052c094                                                 XREF[1]:     0052c088(j)
//                              tscenaro.cpp:983 (3)
//         0052c094     RET        0x4
//         0052c097     ??         90h
//         0052c098     NOP
//         0052c099     NOP
//         0052c09a     NOP
//         0052c09b     NOP
//         0052c09c     NOP
//         0052c09d     NOP
//         0052c09e     NOP
//         0052c09f     NOP
    return 0;
}

int T_Scenario::get_object_ID(RGE_Static_Object* param_1) {
    /* TODO: Stub */
//                              int __thiscall get_object_ID(T_Scenario * this, RGE_Static_Object *
//              int               EAX:4          <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     0052c0a0(R)
//                               ?get_object_ID@T_Scenario@@AAEHPAVRGE_Static_Object@@@Z      XREF[2]:     SetSPObject:0052b5fc(c),
//                               T_Scenario::get_object_ID                                                 SetSPDestObjectID:0052b63c(c)
//                              tscenaro.cpp:987 (7)
//         0052c0a0     MOV        EAX,dword ptr [ESP + param_1]
//         0052c0a4     MOV        EAX,dword ptr [EAX + 0x4]
//                              tscenaro.cpp:989 (3)
//         0052c0a7     RET        0x4
//         0052c0aa     ??         90h
//         0052c0ab     NOP
//         0052c0ac     NOP
//         0052c0ad     NOP
//         0052c0ae     NOP
//         0052c0af     NOP
    return 0;
}

void T_Scenario::WriteDisabledTechnologiesToMainSystem() {
    /* TODO: Stub */
//                              void __thiscall WriteDisabledTechnologiesToMainSystem(T_Scenario * t
//              void              <VOID>         <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//                               ?WriteDisabledTechnologiesToMainSystem@T_Scenario@@AAEXXZ    XREF[1]:     save:0052af2f(c)
//                               T_Scenario::WriteDisabledTechnologiesToMainSystem
//                              tscenaro.cpp:993 (4)
//         0052c0b0     PUSH       EBX
//         0052c0b1     PUSH       EBP
//         0052c0b2     MOV        EBP,this
//                              tscenaro.cpp:995 (11)
//         0052c0b4     MOV        EAX,dword ptr [EBP + 0x8]
//         0052c0b7     TEST       EAX,EAX
//         0052c0b9     JZ         LAB_0052c1d7
//                              tscenaro.cpp:996 (17)
//         0052c0bf     MOV        EBX,0x1
//         0052c0c4     CMP        word ptr [EAX + 0x3c],BX
//         0052c0c8     JLE        LAB_0052c1d7
//         0052c0ce     PUSH       EDI
//         0052c0cf     PUSH       ESI
//                              tscenaro.cpp:1018 (266)
//         0052c0d0     LEA        ESI,[EBP + 0x4bf8]
//                               LAB_0052c0d6                                                 XREF[1]:     0052c1cf(j)
//         0052c0d6     MOV        this,dword ptr [EAX + 0x40]
//         0052c0d9     MOV        EDI,dword ptr [this->_padding_ + EBX*0x4]
//         0052c0dc     MOV        this,dword ptr [EBP + 0x50f4]
//         0052c0e2     TEST       this,this
//         0052c0e4     JZ         LAB_0052c0f3
//         0052c0e6     MOV        EAX,dword ptr [EAX + 0x4c]
//         0052c0e9     PUSH       EDI
//         0052c0ea     PUSH       offset DAT_fffffff8
//         0052c0ec     MOV        this,EAX
//         0052c0ee     MOV        EDX,dword ptr [EAX]
//         0052c0f0     CALL       dword ptr [EDX + 0x8]
//                               LAB_0052c0f3                                                 XREF[1]:     0052c0e4(j)
//         0052c0f3     MOV        AL,byte ptr [ESI + -0x4]
//         0052c0f6     MOV        this,EDI
//         0052c0f8     PUSH       EAX
//         0052c0f9     PUSH       offset DAT_fffffff8
//         0052c0fb     CALL       TRIBE_Player::tech_abling                        void tech_abling(TRIBE_Player * this, long pa
//         0052c100     MOV        this,byte ptr [ESI]
//         0052c102     PUSH       this
//         0052c103     PUSH       offset DAT_fffffff8
//         0052c105     MOV        this,EDI
//         0052c107     CALL       TRIBE_Player::tech_abling                        void tech_abling(TRIBE_Player * this, long pa
//         0052c10c     MOV        DL,byte ptr [ESI + 0x4]
//         0052c10f     MOV        this,EDI
//         0052c111     PUSH       EDX
//         0052c112     PUSH       offset DAT_fffffff8
//         0052c114     CALL       TRIBE_Player::tech_abling                        void tech_abling(TRIBE_Player * this, long pa
//         0052c119     MOV        AL,byte ptr [ESI + 0x8]
//         0052c11c     MOV        this,EDI
//         0052c11e     PUSH       EAX
//         0052c11f     PUSH       offset DAT_fffffff8
//         0052c121     CALL       TRIBE_Player::tech_abling                        void tech_abling(TRIBE_Player * this, long pa
//         0052c126     MOV        this,byte ptr [ESI + 0xc]
//         0052c129     PUSH       this
//         0052c12a     PUSH       offset DAT_fffffff8
//         0052c12c     MOV        this,EDI
//         0052c12e     CALL       TRIBE_Player::tech_abling                        void tech_abling(TRIBE_Player * this, long pa
//         0052c133     MOV        DL,byte ptr [ESI + 0x10]
//         0052c136     MOV        this,EDI
//         0052c138     PUSH       EDX
//         0052c139     PUSH       offset DAT_fffffff8
//         0052c13b     CALL       TRIBE_Player::tech_abling                        void tech_abling(TRIBE_Player * this, long pa
//         0052c140     MOV        AL,byte ptr [ESI + 0x14]
//         0052c143     MOV        this,EDI
//         0052c145     PUSH       EAX
//         0052c146     PUSH       offset DAT_fffffff8
//         0052c148     CALL       TRIBE_Player::tech_abling                        void tech_abling(TRIBE_Player * this, long pa
//         0052c14d     MOV        this,byte ptr [ESI + 0x18]
//         0052c150     PUSH       this
//         0052c151     PUSH       offset DAT_fffffff8
//         0052c153     MOV        this,EDI
//         0052c155     CALL       TRIBE_Player::tech_abling                        void tech_abling(TRIBE_Player * this, long pa
//         0052c15a     MOV        DL,byte ptr [ESI + 0x1c]
//         0052c15d     MOV        this,EDI
//         0052c15f     PUSH       EDX
//         0052c160     PUSH       offset DAT_fffffff8
//         0052c162     CALL       TRIBE_Player::tech_abling                        void tech_abling(TRIBE_Player * this, long pa
//         0052c167     MOV        AL,byte ptr [ESI + 0x20]
//         0052c16a     MOV        this,EDI
//         0052c16c     PUSH       EAX
//         0052c16d     PUSH       offset DAT_fffffff8
//         0052c16f     CALL       TRIBE_Player::tech_abling                        void tech_abling(TRIBE_Player * this, long pa
//         0052c174     MOV        this,byte ptr [ESI + 0x24]
//         0052c177     PUSH       this
//         0052c178     PUSH       offset DAT_fffffff8
//         0052c17a     MOV        this,EDI
//         0052c17c     CALL       TRIBE_Player::tech_abling                        void tech_abling(TRIBE_Player * this, long pa
//         0052c181     MOV        DL,byte ptr [ESI + 0x28]
//         0052c184     MOV        this,EDI
//         0052c186     PUSH       EDX
//                              language.dll match for 0x65: "1"
//         0052c187     PUSH       offset DAT_fffffff8
//         0052c189     CALL       TRIBE_Player::tech_abling                        void tech_abling(TRIBE_Player * this, long pa
//         0052c18e     MOV        AL,byte ptr [ESI + 0x2c]
//         0052c191     MOV        this,EDI
//         0052c193     PUSH       EAX
//                              language.dll match for 0x66: "Copperplate Gothic Light"
//         0052c194     PUSH       offset DAT_fffffff8
//         0052c196     CALL       TRIBE_Player::tech_abling                        void tech_abling(TRIBE_Player * this, long pa
//         0052c19b     MOV        this,byte ptr [ESI + 0x30]
//         0052c19e     PUSH       this
//                              language.dll match for 0x67: "Comic Sans MS"
//         0052c19f     PUSH       offset DAT_fffffff8
//         0052c1a1     MOV        this,EDI
//         0052c1a3     CALL       TRIBE_Player::tech_abling                        void tech_abling(TRIBE_Player * this, long pa
//         0052c1a8     MOV        DL,byte ptr [ESI + 0x34]
//         0052c1ab     MOV        this,EDI
//         0052c1ad     PUSH       EDX
//                              language.dll match for 0x73: "B"
//         0052c1ae     PUSH       offset DAT_fffffff8
//         0052c1b0     CALL       TRIBE_Player::tech_abling                        void tech_abling(TRIBE_Player * this, long pa
//         0052c1b5     MOV        AL,byte ptr [ESI + 0x38]
//         0052c1b8     MOV        this,EDI
//         0052c1ba     PUSH       EAX
//                              language.dll match for 0x74: "Copperplate Gothic Light"
//         0052c1bb     PUSH       offset DAT_fffffff8
//         0052c1bd     CALL       TRIBE_Player::tech_abling                        void tech_abling(TRIBE_Player * this, long pa
//         0052c1c2     INC        EBX
//         0052c1c3     MOV        EAX,dword ptr [EBP + 0x8]
//         0052c1c6     ADD        ESI,0x50
//         0052c1c9     MOVSX      this,word ptr [EAX + 0x3c]
//         0052c1cd     CMP        EBX,this
//         0052c1cf     JL         LAB_0052c0d6
//         0052c1d5     POP        ESI
//         0052c1d6     POP        EDI
//                               LAB_0052c1d7                                                 XREF[2]:     0052c0b9(j), 0052c0c8(j)
//         0052c1d7     POP        EBP
//         0052c1d8     POP        EBX
//         0052c1d9     RET
//         0052c1da     ??         90h
//         0052c1db     NOP
//         0052c1dc     NOP
//         0052c1dd     NOP
//         0052c1de     NOP
//         0052c1df     NOP
    return;
}

int T_Scenario::any_sp_victory() {
    /* TODO: Stub */
//                              int __thiscall any_sp_victory(T_Scenario * this)
//              int               EAX:4          <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//                               ?any_sp_victory@T_Scenario@@QAEHXZ                           XREF[2]:     updateSummary:004a4300(c),
//                               T_Scenario::any_sp_victory                                                TRIBE_Scenario_Header:0052a9c8(c)
//                              tscenaro.cpp:1023 (5)
//         0052c1e0     PUSH       EBX
//         0052c1e1     PUSH       ESI
//         0052c1e2     PUSH       EDI
//         0052c1e3     MOV        EDI,this
//                              tscenaro.cpp:1026 (2)
//         0052c1e5     XOR        EBX,EBX
//                               LAB_0052c1e7                                                 XREF[1]:     0052c213(j)
//                              tscenaro.cpp:1028 (12)
//         0052c1e7     PUSH       EBX
//         0052c1e8     MOV        this,EDI
//         0052c1ea     CALL       RGE_Scenario::Get_player_Active                  int Get_player_Active(RGE_Scenario * this, in
//         0052c1ef     TEST       EAX,EAX
//         0052c1f1     JZ         LAB_0052c20f
//                              tscenaro.cpp:1031 (8)
//         0052c1f3     PUSH       EBX
//         0052c1f4     MOV        this,EDI
//         0052c1f6     CALL       T_Scenario::SetSPWhich                           void SetSPWhich(T_Scenario * this, int param_1)
//                              tscenaro.cpp:1032 (2)
//         0052c1fb     XOR        ESI,ESI
//                               LAB_0052c1fd                                                 XREF[1]:     0052c20d(j)
//                              tscenaro.cpp:1034 (18)
//         0052c1fd     PUSH       ESI
//         0052c1fe     MOV        this,EDI
//         0052c200     CALL       T_Scenario::GetSPVictoryType                     int GetSPVictoryType(T_Scenario * this, int p
//         0052c205     TEST       EAX,EAX
//         0052c207     JNZ        LAB_0052c21b
//         0052c209     INC        ESI
//         0052c20a     CMP        ESI,0xc
//         0052c20d     JL         LAB_0052c1fd
//                               LAB_0052c20f                                                 XREF[1]:     0052c1f1(j)
//                              tscenaro.cpp:1026 (6)
//         0052c20f     INC        EBX
//         0052c210     CMP        EBX,0x10
//         0052c213     JL         LAB_0052c1e7
//                              tscenaro.cpp:1040 (2)
//         0052c215     XOR        EAX,EAX
//                              tscenaro.cpp:1041 (4)
//         0052c217     POP        EDI
//         0052c218     POP        ESI
//         0052c219     POP        EBX
//         0052c21a     RET
//                               LAB_0052c21b                                                 XREF[1]:     0052c207(j)
//                              tscenaro.cpp:1035 (5)
//         0052c21b     MOV        EAX,0x1
//                              tscenaro.cpp:1041 (4)
//         0052c220     POP        EDI
//         0052c221     POP        ESI
//         0052c222     POP        EBX
//         0052c223     RET
//         0052c224     ??         90h
//         0052c225     NOP
//         0052c226     NOP
//         0052c227     NOP
//         0052c228     NOP
//         0052c229     NOP
//         0052c22a     NOP
//         0052c22b     NOP
//         0052c22c     NOP
//         0052c22d     NOP
//         0052c22e     NOP
//         0052c22f     NOP
    return 0;
}

void T_Scenario::set_player_tech(TRIBE_Player* param_1) {
    /* TODO: Stub */
//                              void __thiscall set_player_tech(T_Scenario * this, TRIBE_Player * pa
//              void              <VOID>         <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//              TRIBE_Player *    Stack[0x4]:4   param_1                   XREF[1]:     0052c233(R)
//                               ?set_player_tech@T_Scenario@@QAEXPAVTRIBE_Player@@@Z         XREF[1]:     scenario_load:0051287c(c)
//                               T_Scenario::set_player_tech
//                              tscenaro.cpp:1045 (3)
//         0052c230     PUSH       EBX
//         0052c231     PUSH       EBP
//         0052c232     PUSH       ESI
//                              tscenaro.cpp:1046 (12)
//         0052c233     MOV        ESI,dword ptr [ESP + param_1]
//         0052c237     PUSH       EDI
//         0052c238     MOV        EBP,this
//         0052c23a     MOVSX      EBX,word ptr [ESI + 0x4a]
//         0052c23e     DEC        EBX
//                              tscenaro.cpp:1047 (6)
//         0052c23f     JS         LAB_0052c3cc
//                              tscenaro.cpp:1050 (26)
//         0052c245     LEA        EAX,[EBX + EBX*0x4]
//         0052c248     SHL        EAX,0x4
//         0052c24b     MOV        this,byte ptr [EAX + EBP*0x1 + 0x4bf4]
//         0052c252     LEA        EDI,[EAX + EBP*0x1]
//         0052c255     PUSH       this
//         0052c256     PUSH       0x58
//         0052c258     MOV        this,ESI
//         0052c25a     CALL       TRIBE_Player::tech_abling                        void tech_abling(TRIBE_Player * this, long pa
//                              tscenaro.cpp:1051 (16)
//         0052c25f     MOV        DL,byte ptr [EDI + 0x4bf8]
//         0052c265     MOV        this,ESI
//         0052c267     PUSH       EDX
//         0052c268     PUSH       0x59
//         0052c26a     CALL       TRIBE_Player::tech_abling                        void tech_abling(TRIBE_Player * this, long pa
//                              tscenaro.cpp:1052 (16)
//         0052c26f     MOV        AL,byte ptr [EDI + 0x4bfc]
//         0052c275     MOV        this,ESI
//         0052c277     PUSH       EAX
//         0052c278     PUSH       0x5a
//         0052c27a     CALL       TRIBE_Player::tech_abling                        void tech_abling(TRIBE_Player * this, long pa
//                              tscenaro.cpp:1053 (16)
//         0052c27f     MOV        this,byte ptr [EDI + 0x4c00]
//         0052c285     PUSH       this
//         0052c286     PUSH       0x5b
//         0052c288     MOV        this,ESI
//         0052c28a     CALL       TRIBE_Player::tech_abling                        void tech_abling(TRIBE_Player * this, long pa
//                              tscenaro.cpp:1054 (16)
//         0052c28f     MOV        DL,byte ptr [EDI + 0x4c04]
//         0052c295     MOV        this,ESI
//         0052c297     PUSH       EDX
//         0052c298     PUSH       0x5e
//         0052c29a     CALL       TRIBE_Player::tech_abling                        void tech_abling(TRIBE_Player * this, long pa
//                              tscenaro.cpp:1055 (16)
//         0052c29f     MOV        AL,byte ptr [EDI + 0x4c08]
//         0052c2a5     MOV        this,ESI
//         0052c2a7     PUSH       EAX
//         0052c2a8     PUSH       0x5f
//         0052c2aa     CALL       TRIBE_Player::tech_abling                        void tech_abling(TRIBE_Player * this, long pa
//                              tscenaro.cpp:1056 (16)
//         0052c2af     MOV        this,byte ptr [EDI + 0x4c0c]
//         0052c2b5     PUSH       this
//         0052c2b6     PUSH       0x61
//         0052c2b8     MOV        this,ESI
//         0052c2ba     CALL       TRIBE_Player::tech_abling                        void tech_abling(TRIBE_Player * this, long pa
//                              tscenaro.cpp:1057 (16)
//         0052c2bf     MOV        DL,byte ptr [EDI + 0x4c10]
//         0052c2c5     MOV        this,ESI
//         0052c2c7     PUSH       EDX
//         0052c2c8     PUSH       0x62
//         0052c2ca     CALL       TRIBE_Player::tech_abling                        void tech_abling(TRIBE_Player * this, long pa
//                              tscenaro.cpp:1058 (16)
//         0052c2cf     MOV        AL,byte ptr [EDI + 0x4c14]
//         0052c2d5     MOV        this,ESI
//         0052c2d7     PUSH       EAX
//         0052c2d8     PUSH       0x5d
//         0052c2da     CALL       TRIBE_Player::tech_abling                        void tech_abling(TRIBE_Player * this, long pa
//                              tscenaro.cpp:1059 (16)
//         0052c2df     MOV        this,byte ptr [EDI + 0x4c18]
//         0052c2e5     PUSH       this
//         0052c2e6     PUSH       0x60
//         0052c2e8     MOV        this,ESI
//         0052c2ea     CALL       TRIBE_Player::tech_abling                        void tech_abling(TRIBE_Player * this, long pa
//                              tscenaro.cpp:1060 (16)
//         0052c2ef     MOV        DL,byte ptr [EDI + 0x4c1c]
//         0052c2f5     MOV        this,ESI
//         0052c2f7     PUSH       EDX
//         0052c2f8     PUSH       0x5c
//         0052c2fa     CALL       TRIBE_Player::tech_abling                        void tech_abling(TRIBE_Player * this, long pa
//                              tscenaro.cpp:1061 (16)
//         0052c2ff     MOV        AL,byte ptr [EDI + 0x4c20]
//         0052c305     MOV        this,ESI
//         0052c307     PUSH       EAX
//                              language.dll match for 0x65: "1"
//         0052c308     PUSH       0x65
//         0052c30a     CALL       TRIBE_Player::tech_abling                        void tech_abling(TRIBE_Player * this, long pa
//                              tscenaro.cpp:1062 (16)
//         0052c30f     MOV        this,byte ptr [EDI + 0x4c24]
//         0052c315     PUSH       this
//                              language.dll match for 0x66: "Copperplate Gothic Light"
//         0052c316     PUSH       0x66
//         0052c318     MOV        this,ESI
//         0052c31a     CALL       TRIBE_Player::tech_abling                        void tech_abling(TRIBE_Player * this, long pa
//                              tscenaro.cpp:1063 (16)
//         0052c31f     MOV        DL,byte ptr [EDI + 0x4c28]
//         0052c325     MOV        this,ESI
//         0052c327     PUSH       EDX
//                              language.dll match for 0x67: "Comic Sans MS"
//         0052c328     PUSH       0x67
//         0052c32a     CALL       TRIBE_Player::tech_abling                        void tech_abling(TRIBE_Player * this, long pa
//                              tscenaro.cpp:1064 (16)
//         0052c32f     MOV        AL,byte ptr [EDI + 0x4c2c]
//         0052c335     MOV        this,ESI
//         0052c337     PUSH       EAX
//                              language.dll match for 0x73: "B"
//         0052c338     PUSH       0x73
//         0052c33a     CALL       TRIBE_Player::tech_abling                        void tech_abling(TRIBE_Player * this, long pa
//                              tscenaro.cpp:1065 (16)
//         0052c33f     MOV        this,byte ptr [EDI + 0x4c30]
//         0052c345     PUSH       this
//                              language.dll match for 0x74: "Copperplate Gothic Light"
//         0052c346     PUSH       0x74
//         0052c348     MOV        this,ESI
//         0052c34a     CALL       TRIBE_Player::tech_abling                        void tech_abling(TRIBE_Player * this, long pa
//                              tscenaro.cpp:1067 (11)
//         0052c34f     MOV        this,dword ptr [ESI + 0x220]
//         0052c355     CALL       TRIBE_Player_Tech::check_for_new_tech            uchar check_for_new_tech(TRIBE_Player_Tech *
//                              tscenaro.cpp:1070 (10)
//         0052c35a     MOV        EAX,dword ptr [EBP + 0x50f4]
//         0052c360     TEST       EAX,EAX
//         0052c362     JZ         LAB_0052c372
//                              tscenaro.cpp:1071 (14)
//         0052c364     MOV        EDX,dword ptr [EBP + 0x8]
//         0052c367     PUSH       ESI
//         0052c368     PUSH       0x64
//         0052c36a     MOV        this,dword ptr [EDX + 0x4c]
//         0052c36d     MOV        EAX,dword ptr [this->_padding_]
//         0052c36f     CALL       dword ptr [EAX + 0x8]
//                               LAB_0052c372                                                 XREF[1]:     0052c362(j)
//                              tscenaro.cpp:1074 (15)
//         0052c372     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0052c378     CMP        dword ptr [ECX + this->_padding_],0x7
//         0052c37f     JZ         switchD_0052c390::default
//                              tscenaro.cpp:1075 (22)
//         0052c381     MOV        EBX,dword ptr [EBP + EBX*0x4 + 0x5100]
//         0052c388     LEA        EAX,[EBX + -0x1]
//         0052c38b     CMP        EAX,0x3
//         0052c38e     JA         switchD_0052c390::default
//                               switchD_0052c390::switchD
//         0052c390     JMP        dword ptr [EAX*0x4 + switchD_0052c390::switchd   = 0052c397
//                               switchD_0052c390::caseD_1                                    XREF[2]:     0052c390(j), 0052c3d4(*)
//                              tscenaro.cpp:1078 (2)
//         0052c397     PUSH       0x19
//                              tscenaro.cpp:1079 (2)
//         0052c399     JMP        LAB_0052c3a5
//                               switchD_0052c390::caseD_2                                    XREF[2]:     0052c390(j), 0052c3d8(*)
//                              tscenaro.cpp:1081 (2)
//         0052c39b     PUSH       0x17
//                              tscenaro.cpp:1082 (2)
//         0052c39d     JMP        LAB_0052c3a5
//                               switchD_0052c390::caseD_3                                    XREF[2]:     0052c390(j), 0052c3dc(*)
//                              tscenaro.cpp:1084 (2)
//         0052c39f     PUSH       0x18
//                              tscenaro.cpp:1085 (2)
//         0052c3a1     JMP        LAB_0052c3a5
//                               switchD_0052c390::caseD_4                                    XREF[2]:     0052c390(j), 0052c3e0(*)
//                              tscenaro.cpp:1087 (9)
//         0052c3a3     PUSH       0x1
//                               LAB_0052c3a5                                                 XREF[3]:     0052c399(j), 0052c39d(j),
//                                                                                                         0052c3a1(j)
//         0052c3a5     MOV        this,ESI
//         0052c3a7     CALL       TRIBE_Player::rev_tech                           void rev_tech(TRIBE_Player * this, long param
//                               switchD_0052c390::default                                    XREF[2]:     0052c37f(j), 0052c38e(j)
//                              tscenaro.cpp:1091 (19)
//         0052c3ac     FILD       dword ptr [EDI + 0x4c2c]
//         0052c3b2     FCOMP      float ptr [DAT_00577338]
//         0052c3b8     FNSTSW     AX
//         0052c3ba     TEST       AH,0x40
//         0052c3bd     JZ         LAB_0052c3cc
//                              tscenaro.cpp:1092 (13)
//         0052c3bf     MOV        EDX,dword ptr [ESI + 0x50]
//         0052c3c2     MOV        dword ptr [EDX + 0xc0],0x3f800000
//                               LAB_0052c3cc                                                 XREF[2]:     0052c23f(j), 0052c3bd(j)
//                              tscenaro.cpp:1093 (24)
//         0052c3cc     POP        EDI
//         0052c3cd     POP        ESI
//         0052c3ce     POP        EBP
//         0052c3cf     POP        EBX
//         0052c3d0     RET        0x4
//         0052c3d3     ??         90h
//                              Symbol Ref: No symbol: NONAME
//                               switchD_0052c390::switchdataD_0052c3d4                       XREF[1]:     set_player_tech:0052c390(*)
//         0052c3d4     addr       switchD_0052c390::caseD_1
//         0052c3d8     addr       switchD_0052c390::caseD_2
//         0052c3dc     addr       switchD_0052c390::caseD_3
//         0052c3e0     addr       switchD_0052c390::caseD_4
//         0052c3e4     ??         90h
//         0052c3e5     ??         90h
//         0052c3e6     ??         90h
//         0052c3e7     ??         90h
//         0052c3e8     ??         90h
//         0052c3e9     ??         90h
//         0052c3ea     ??         90h
//         0052c3eb     ??         90h
//         0052c3ec     ??         90h
//         0052c3ed     ??         90h
//         0052c3ee     ??         90h
//         0052c3ef     ??         90h
    return;
}

T_Scenario::~T_Scenario() {
    /* TODO: Stub */
//                              void __thiscall ~T_Scenario(T_Scenario * this)
//              void              <VOID>         <RETURN>
//              T_Scenario *      ECX:4 (auto)   this
//                               ??1T_Scenario@@UAE@XZ                                        XREF[1]:     `vector_deleting_destructor':0052a
//                               T_Scenario::~T_Scenario
//         0052ab80     JMP        RGE_Scenario::~RGE_Scenario
//         0052ab85     ??         90h
//         0052ab86     NOP
//         0052ab87     NOP
//         0052ab88     NOP
//         0052ab89     NOP
//         0052ab8a     NOP
//         0052ab8b     NOP
//         0052ab8c     NOP
//         0052ab8d     NOP
//         0052ab8e     NOP
//         0052ab8f     NOP
}

