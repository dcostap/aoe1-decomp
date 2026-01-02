#include "../common.h"
#include "registry.h"

TRegistry::TRegistry(char* param_1) {
    /* TODO: Stub */
//                              undefined __thiscall TRegistry(TRegistry * this, char * param_1)
//              undefined         <UNASSIGNED>   <RETURN>
//              TRegistry *       ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     0047eb86(R)
//                               ??0TRegistry@@QAE@PBD@Z                                      XREF[1]:     setup_registry:0041edb2(c)
//                               TRegistry::TRegistry
//                              registry.cpp:12 (6)
//         0047eb80     PUSH       EBX
//         0047eb81     PUSH       EBP
//         0047eb82     PUSH       ESI
//         0047eb83     MOV        ESI,this
//         0047eb85     PUSH       EDI
//                              registry.cpp:32 (58)
//         0047eb86     MOV        EBP,dword ptr [ESP + param_1]
//         0047eb8a     LEA        EDI,[ESI + 0xc]
//         0047eb8d     LEA        EAX,[ESI + 0x4]
//         0047eb90     PUSH       EDI
//         0047eb91     PUSH       EAX
//         0047eb92     PUSH       0x0
//         0047eb94     PUSH       0xf003f
//         0047eb99     PUSH       0x0
//         0047eb9b     PUSH       0x0
//         0047eb9d     LEA        EBX,[ESI + 0x8]
//         0047eba0     PUSH       0x0
//         0047eba2     PUSH       EBP
//         0047eba3     PUSH       0x80000001
//         0047eba8     MOV        dword ptr [ESI],0x0
//         0047ebae     MOV        dword ptr [EAX],0x0
//         0047ebb4     MOV        dword ptr [EBX],0x0
//         0047ebba     CALL       dword ptr [->ADVAPI32.DLL::RegCreateKeyExA]      = 0048b386
//                              registry.cpp:44 (27)
//         0047ebc0     PUSH       EDI
//         0047ebc1     PUSH       ESI=>DAT_fffffff8
//         0047ebc2     PUSH       0x0=>DAT_fffffff4
//         0047ebc4     PUSH       offset DAT_fffffff0
//         0047ebc9     PUSH       0x0
//         0047ebcb     PUSH       0x0
//         0047ebcd     PUSH       0x0
//         0047ebcf     PUSH       EBP
//         0047ebd0     PUSH       0x80000002
//         0047ebd5     CALL       dword ptr [->ADVAPI32.DLL::RegCreateKeyExA]      = 0048b386
//                              registry.cpp:56 (24)
//         0047ebdb     PUSH       EDI
//         0047ebdc     PUSH       EBX=>DAT_fffffff8
//         0047ebdd     PUSH       0x0=>DAT_fffffff4
//         0047ebdf     PUSH       offset DAT_fffffff0
//         0047ebe1     PUSH       0x0
//         0047ebe3     PUSH       0x0
//         0047ebe5     PUSH       0x0
//         0047ebe7     PUSH       EBP
//         0047ebe8     PUSH       0x80000002
//         0047ebed     CALL       dword ptr [->ADVAPI32.DLL::RegCreateKeyExA]      = 0048b386
//                              registry.cpp:59 (9)
//         0047ebf3     MOV        EAX,ESI
//         0047ebf5     POP        EDI
//         0047ebf6     POP        ESI
//         0047ebf7     POP        EBP
//         0047ebf8     POP        EBX
//         0047ebf9     RET        0x4
//         0047ebfc     ??         90h
//         0047ebfd     NOP
//         0047ebfe     NOP
//         0047ebff     NOP
}

TRegistry::~TRegistry() {
    /* TODO: Stub */
//                              void __thiscall ~TRegistry(TRegistry * this)
//              void              <VOID>         <RETURN>
//              TRegistry *       ECX:4 (auto)   this
//                               ??1TRegistry@@QAE@XZ                                         XREF[1]:     ~RGE_Base_Game:0041c5e2(c)
//                               TRegistry::~TRegistry
//                              registry.cpp:63 (4)
//         0047ec00     PUSH       ESI
//         0047ec01     MOV        ESI,this
//         0047ec03     PUSH       EDI
//                              registry.cpp:64 (13)
//         0047ec04     MOV        EDI,dword ptr [->ADVAPI32.DLL::RegCloseKey]      = 0048b398
//         0047ec0a     MOV        EAX,dword ptr [ESI + 0x4]
//         0047ec0d     TEST       EAX,EAX
//         0047ec0f     JZ         LAB_0047ec1b
//                              registry.cpp:66 (3)
//         0047ec11     PUSH       EAX
//         0047ec12     CALL       EDI=>ADVAPI32.DLL::RegCloseKey
//                              registry.cpp:67 (7)
//         0047ec14     MOV        dword ptr [ESI + 0x4],0x0
//                               LAB_0047ec1b                                                 XREF[1]:     0047ec0f(j)
//                              registry.cpp:70 (6)
//         0047ec1b     MOV        EAX,dword ptr [ESI]
//         0047ec1d     TEST       EAX,EAX
//         0047ec1f     JZ         LAB_0047ec2a
//                              registry.cpp:72 (3)
//         0047ec21     PUSH       EAX
//         0047ec22     CALL       EDI=>ADVAPI32.DLL::RegCloseKey
//                              registry.cpp:73 (6)
//         0047ec24     MOV        dword ptr [ESI],0x0
//                               LAB_0047ec2a                                                 XREF[1]:     0047ec1f(j)
//                              registry.cpp:76 (7)
//         0047ec2a     MOV        EAX,dword ptr [ESI + 0x8]
//         0047ec2d     TEST       EAX,EAX
//         0047ec2f     JZ         LAB_0047ec3b
//                              registry.cpp:78 (3)
//         0047ec31     PUSH       EAX
//         0047ec32     CALL       EDI=>ADVAPI32.DLL::RegCloseKey
//                              registry.cpp:79 (7)
//         0047ec34     MOV        dword ptr [ESI + 0x8],0x0
//                               LAB_0047ec3b                                                 XREF[1]:     0047ec2f(j)
//                              registry.cpp:83 (3)
//         0047ec3b     POP        EDI
//         0047ec3c     POP        ESI
//         0047ec3d     RET
//         0047ec3e     ??         90h
//         0047ec3f     NOP
}

int TRegistry::RegSet(int param_1, char* param_2, uchar* param_3, ulong param_4) {
    /* TODO: Stub */
//                              int __thiscall RegSet(TRegistry * this, int param_1, char * param_2,
//              int               EAX:4          <RETURN>
//              TRegistry *       ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0047ec40(R)
//              char *            Stack[0x8]:4   param_2                   XREF[2]:     0047ec54(R), 0047ec7a(R)
//              uchar *           Stack[0xc]:4   param_3                   XREF[2]:     0047ec4c(R), 0047ec75(R)
//              ulong             Stack[0x10]:4  param_4                   XREF[2]:     0047ec48(R), 0047ec71(R)
//                               ?RegSet@TRegistry@@QAEHHPBDPAEK@Z
//                               TRegistry::RegSet
//                              registry.cpp:87 (8)
//         0047ec40     MOV        EAX,dword ptr [ESP + param_1]
//         0047ec44     TEST       EAX,EAX
//         0047ec46     JZ         LAB_0047ec71
//                              registry.cpp:91 (23)
//         0047ec48     MOV        EAX,dword ptr [ESP + param_4]
//         0047ec4c     MOV        EDX,dword ptr [ESP + param_3]
//         0047ec50     MOV        this,dword ptr [ECX + this->ghUserKey]
//         0047ec53     PUSH       EAX
//         0047ec54     MOV        EAX,dword ptr [ESP + param_2]
//         0047ec58     PUSH       EDX
//         0047ec59     PUSH       0x4
//         0047ec5b     PUSH       0x0
//         0047ec5d     PUSH       EAX
//         0047ec5e     PUSH       this
//                              registry.cpp:93 (6)
//         0047ec5f     CALL       dword ptr [->ADVAPI32.DLL::RegSetValueExA]       = 0048b3a6
//                              registry.cpp:95 (9)
//         0047ec65     XOR        this,this
//         0047ec67     TEST       EAX,EAX
//         0047ec69     SETZ       this
//         0047ec6c     MOV        EAX,this
//                              registry.cpp:105 (3)
//         0047ec6e     RET        0x10
//                               LAB_0047ec71                                                 XREF[1]:     0047ec46(j)
//                              registry.cpp:93 (28)
//         0047ec71     MOV        EDX,dword ptr [ESP + param_4]
//         0047ec75     MOV        EAX,dword ptr [ESP + param_3]
//         0047ec79     PUSH       EDX
//         0047ec7a     MOV        EDX,dword ptr [ESP + param_2]
//         0047ec7e     PUSH       EAX
//         0047ec7f     MOV        EAX,dword ptr [this->ghMachineKey]
//         0047ec81     PUSH       0x4
//         0047ec83     PUSH       0x0
//         0047ec85     PUSH       EDX
//         0047ec86     PUSH       EAX
//         0047ec87     CALL       dword ptr [->ADVAPI32.DLL::RegSetValueExA]       = 0048b3a6
//                              registry.cpp:95 (9)
//         0047ec8d     XOR        this,this
//         0047ec8f     TEST       EAX,EAX
//         0047ec91     SETZ       this
//         0047ec94     MOV        EAX,this
//                              registry.cpp:105 (3)
//         0047ec96     RET        0x10
//         0047ec99     ??         90h
//         0047ec9a     NOP
//         0047ec9b     NOP
//         0047ec9c     NOP
//         0047ec9d     NOP
//         0047ec9e     NOP
//         0047ec9f     NOP
    return 0;
}

int TRegistry::RegSetInt(int param_1, char* param_2, int param_3) {
    /* TODO: Stub */
//                              int __thiscall RegSetInt(TRegistry * this, int param_1, char * param
//              int               EAX:4          <RETURN>
//              TRegistry *       ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0047eca0(R)
//              char *            Stack[0x8]:4   param_2                   XREF[2]:     0047ecaa(R), 0047ecce(R)
//              int               Stack[0xc]:4   param_3                   XREF[2]:     0047ecae(*), 0047ecd4(*)
//                               ?RegSetInt@TRegistry@@QAEHHPBDH@Z                            XREF[13]:    setup:0041c0a2(c),
//                               TRegistry::RegSetInt                                                      ~RGE_Base_Game:0041c2b7(c),
//                                                                                                         ~RGE_Base_Game:0041c2d7(c),
//                                                                                                         ~RGE_Base_Game:0041c2fc(c),
//                                                                                                         ~RGE_Base_Game:0041c320(c),
//                                                                                                         ~RGE_Base_Game:0041c339(c),
//                                                                                                         ~RGE_Base_Game:0041c359(c),
//                                                                                                         ~RGE_Base_Game:0041c379(c),
//                                                                                                         ~RGE_Base_Game:0041c395(c),
//                                                                                                         setup_mouse:0041ec34(c),
//                                                                                                         stop_sound_system:0041f8e4(c),
//                                                                                                         shutdown_music_system:0041fabc(c),
//                                                                                                         action:0043c591(c)
//                              registry.cpp:108 (4)
//         0047eca0     MOV        EAX,dword ptr [ESP + param_1]
//                              registry.cpp:112 (24)
//         0047eca4     PUSH       0x4
//         0047eca6     TEST       EAX,EAX
//         0047eca8     JZ         LAB_0047ecce
//         0047ecaa     MOV        EDX,dword ptr [ESP + param_2]
//         0047ecae     LEA        EAX=>param_3,[ESP + 0x10]
//         0047ecb2     PUSH       EAX
//         0047ecb3     MOV        EAX,dword ptr [ECX + this->ghUserKey]
//         0047ecb6     PUSH       0x4
//         0047ecb8     PUSH       0x0
//         0047ecba     PUSH       EDX
//         0047ecbb     PUSH       EAX
//                              registry.cpp:114 (6)
//         0047ecbc     CALL       dword ptr [->ADVAPI32.DLL::RegSetValueExA]       = 0048b3a6
//                              registry.cpp:116 (9)
//         0047ecc2     XOR        EDX,EDX
//         0047ecc4     TEST       EAX,EAX
//         0047ecc6     SETZ       DL
//         0047ecc9     MOV        EAX,EDX
//                              registry.cpp:125 (3)
//         0047eccb     RET        0xc
//                               LAB_0047ecce                                                 XREF[1]:     0047eca8(j)
//                              registry.cpp:114 (23)
//         0047ecce     MOV        EAX,dword ptr [ESP + param_2]
//         0047ecd2     MOV        this,dword ptr [this->ghMachineKey]
//         0047ecd4     LEA        EDX=>param_3,[ESP + 0x10]
//         0047ecd8     PUSH       EDX
//         0047ecd9     PUSH       0x4
//         0047ecdb     PUSH       0x0
//         0047ecdd     PUSH       EAX
//         0047ecde     PUSH       this
//         0047ecdf     CALL       dword ptr [->ADVAPI32.DLL::RegSetValueExA]       = 0048b3a6
//                              registry.cpp:116 (9)
//         0047ece5     XOR        EDX,EDX
//         0047ece7     TEST       EAX,EAX
//         0047ece9     SETZ       DL
//         0047ecec     MOV        EAX,EDX
//                              registry.cpp:125 (3)
//         0047ecee     RET        0xc
//         0047ecf1     ??         90h
//         0047ecf2     NOP
//         0047ecf3     NOP
//         0047ecf4     NOP
//         0047ecf5     NOP
//         0047ecf6     NOP
//         0047ecf7     NOP
//         0047ecf8     NOP
//         0047ecf9     NOP
//         0047ecfa     NOP
//         0047ecfb     NOP
//         0047ecfc     NOP
//         0047ecfd     NOP
//         0047ecfe     NOP
//         0047ecff     NOP
    return 0;
}

int TRegistry::RegSetAscii(int param_1, char* param_2, uchar* param_3, ulong param_4) {
    /* TODO: Stub */
//                              int __thiscall RegSetAscii(TRegistry * this, int param_1, char * par
//              int               EAX:4          <RETURN>
//              TRegistry *       ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0047ed00(R)
//              char *            Stack[0x8]:4   param_2                   XREF[2]:     0047ed14(R), 0047ed3a(R)
//              uchar *           Stack[0xc]:4   param_3                   XREF[2]:     0047ed0c(R), 0047ed35(R)
//              ulong             Stack[0x10]:4  param_4                   XREF[2]:     0047ed08(R), 0047ed31(R)
//                               ?RegSetAscii@TRegistry@@QAEHHPBDPAEK@Z                       XREF[3]:     action:00492473(c),
//                               TRegistry::RegSetAscii                                                    action:0049fb44(c),
//                                                                                                         action:0049fb79(c)
//                              registry.cpp:131 (8)
//         0047ed00     MOV        EAX,dword ptr [ESP + param_1]
//         0047ed04     TEST       EAX,EAX
//         0047ed06     JZ         LAB_0047ed31
//                              registry.cpp:136 (23)
//         0047ed08     MOV        EAX,dword ptr [ESP + param_4]
//         0047ed0c     MOV        EDX,dword ptr [ESP + param_3]
//         0047ed10     MOV        this,dword ptr [ECX + this->ghUserKey]
//         0047ed13     PUSH       EAX
//         0047ed14     MOV        EAX,dword ptr [ESP + param_2]
//         0047ed18     PUSH       EDX
//         0047ed19     PUSH       0x1
//         0047ed1b     PUSH       0x0
//         0047ed1d     PUSH       EAX
//         0047ed1e     PUSH       this
//                              registry.cpp:138 (6)
//         0047ed1f     CALL       dword ptr [->ADVAPI32.DLL::RegSetValueExA]       = 0048b3a6
//                              registry.cpp:140 (9)
//         0047ed25     XOR        this,this
//         0047ed27     TEST       EAX,EAX
//         0047ed29     SETZ       this
//         0047ed2c     MOV        EAX,this
//                              registry.cpp:149 (3)
//         0047ed2e     RET        0x10
//                               LAB_0047ed31                                                 XREF[1]:     0047ed06(j)
//                              registry.cpp:138 (28)
//         0047ed31     MOV        EDX,dword ptr [ESP + param_4]
//         0047ed35     MOV        EAX,dword ptr [ESP + param_3]
//         0047ed39     PUSH       EDX
//         0047ed3a     MOV        EDX,dword ptr [ESP + param_2]
//         0047ed3e     PUSH       EAX
//         0047ed3f     MOV        EAX,dword ptr [this->ghMachineKey]
//         0047ed41     PUSH       0x1
//         0047ed43     PUSH       0x0
//         0047ed45     PUSH       EDX
//         0047ed46     PUSH       EAX
//         0047ed47     CALL       dword ptr [->ADVAPI32.DLL::RegSetValueExA]       = 0048b3a6
//                              registry.cpp:140 (9)
//         0047ed4d     XOR        this,this
//         0047ed4f     TEST       EAX,EAX
//         0047ed51     SETZ       this
//         0047ed54     MOV        EAX,this
//                              registry.cpp:149 (3)
//         0047ed56     RET        0x10
//         0047ed59     ??         90h
//         0047ed5a     NOP
//         0047ed5b     NOP
//         0047ed5c     NOP
//         0047ed5d     NOP
//         0047ed5e     NOP
//         0047ed5f     NOP
    return 0;
}

char* TRegistry::RegGetAscii(int param_1, char* param_2) {
    /* TODO: Stub */
//                              char * __thiscall RegGetAscii(TRegistry * this, int param_1, char *
//              char *            EAX:4          <RETURN>
//              TRegistry *       ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0047ed63(R)
//              char *            Stack[0x8]:4   param_2                   XREF[2]:     0047ed87(R), 0047eda0(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0047ed6a(W), 0047ed8b(*), 0047ed9b(*)
//              ulong             Stack[-0x8]:4  dwType                    XREF[3]:     0047ed72(W), 0047ed82(*), 0047ed97(*)
//              ulong             Stack[-0xc]:4  dwSize
//                               ?RegGetAscii@TRegistry@@QAEPADHPBD@Z                         XREF[10]:    check_for_cd:0041fd41(c),
//                               TRegistry::RegGetAscii                                                    TribeAboutDialog:0043b189(c),
//                                                                                                         TribeMPCreateDialog:004921d7(c),
//                                                                                                         TribeMPCreateDialog:004921ed(c),
//                                                                                                         TribeMPStartupScreen:0049f483(c),
//                                                                                                         TribeMPStartupScreen:0049f499(c),
//                                                                                                         TribeMPStartupScreen:0049f7ab(c),
//                                                                                                         fillList:0049ff3a(c),
//                                                                                                         fillList:0049ff50(c),
//                                                                                                         start_video:005238cb(c)
//                              registry.cpp:153 (3)
//         0047ed60     SUB        ESP,0x8
//                              registry.cpp:161 (23)
//         0047ed63     MOV        EAX,dword ptr [ESP + param_1]
//         0047ed67     PUSH       ESI
//         0047ed68     TEST       EAX,EAX
//         0047ed6a     MOV        dword ptr [ESP + local_4],0x1
//         0047ed72     MOV        dword ptr [ESP + dwType],0xff
//                              registry.cpp:167 (27)
//         0047ed7a     LEA        ESI,[ECX + this->Data[0]]
//         0047ed7d     JZ         LAB_0047ed97
//         0047ed7f     MOV        this,dword ptr [ECX + this->ghUserKey]
//         0047ed82     LEA        EAX=>dwType,[ESP + 0x4]
//         0047ed86     PUSH       EAX
//         0047ed87     MOV        EAX,dword ptr [ESP + param_2]
//         0047ed8b     LEA        EDX=>local_4,[ESP + 0xc]
//         0047ed8f     PUSH       ESI
//         0047ed90     PUSH       EDX
//         0047ed91     PUSH       0x0
//         0047ed93     PUSH       EAX
//         0047ed94     PUSH       this
//                              registry.cpp:168 (2)
//         0047ed95     JMP        LAB_0047edad
//                               LAB_0047ed97                                                 XREF[1]:     0047ed7d(j)
//                              registry.cpp:174 (28)
//         0047ed97     LEA        EDX=>dwType,[ESP + 0x4]
//         0047ed9b     LEA        EAX=>local_4,[ESP + 0x8]
//         0047ed9f     PUSH       EDX
//         0047eda0     MOV        EDX,dword ptr [ESP + param_2]
//         0047eda4     PUSH       ESI
//         0047eda5     PUSH       EAX
//         0047eda6     MOV        EAX,dword ptr [ECX + this->ghMachineKeyRead]
//         0047eda9     PUSH       0x0
//         0047edab     PUSH       EDX
//         0047edac     PUSH       EAX
//                               LAB_0047edad                                                 XREF[1]:     0047ed95(j)
//         0047edad     CALL       dword ptr [->ADVAPI32.DLL::RegQueryValueExA]     = 0048b3b8
//                              registry.cpp:176 (8)
//         0047edb3     NEG        EAX
//         0047edb5     SBB        EAX,EAX
//         0047edb7     NOT        EAX
//         0047edb9     AND        EAX,ESI
//                              registry.cpp:187 (7)
//         0047edbb     POP        ESI
//         0047edbc     ADD        ESP,0x8
//         0047edbf     RET        0x8
//         0047edc2     ??         90h
//         0047edc3     NOP
//         0047edc4     NOP
//         0047edc5     NOP
//         0047edc6     NOP
//         0047edc7     NOP
//         0047edc8     NOP
//         0047edc9     NOP
//         0047edca     NOP
//         0047edcb     NOP
//         0047edcc     NOP
//         0047edcd     NOP
//         0047edce     NOP
//         0047edcf     NOP
    return 0;
}

long TRegistry::RegGet(int param_1, char* param_2, uchar* param_3, ulong* param_4) {
    /* TODO: Stub */
//                              long __thiscall RegGet(TRegistry * this, int param_1, char * param_2
//              long              EAX:4          <RETURN>
//              TRegistry *       ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0047edd0(R)
//              char *            Stack[0x8]:4   param_2                   XREF[2]:     0047ede6(R), 0047ee0c(R)
//              uchar *           Stack[0xc]:4   param_3                   XREF[2]:     0047eddc(R), 0047edff(R)
//              ulong *           Stack[0x10]:4  param_4                   XREF[4]:     0047edd8(R), 0047ede1(*), 0047edfb(R), 0047ee07(*)
//                               ?RegGet@TRegistry@@QAEJHPBDPAEPAK@Z
//                               TRegistry::RegGet
//                              registry.cpp:192 (8)
//         0047edd0     MOV        EAX,dword ptr [ESP + param_1]
//         0047edd4     TEST       EAX,EAX
//         0047edd6     JZ         LAB_0047edfb
//                              registry.cpp:197 (26)
//         0047edd8     MOV        EAX,dword ptr [ESP + param_4]
//         0047eddc     MOV        EDX,dword ptr [ESP + param_3]
//         0047ede0     PUSH       EAX
//         0047ede1     LEA        EAX=>param_4,[ESP + 0x14]
//         0047ede5     PUSH       EDX
//         0047ede6     MOV        EDX,dword ptr [ESP + param_2]
//         0047edea     PUSH       EAX
//         0047edeb     MOV        EAX,dword ptr [ECX + this->ghUserKey]
//         0047edee     PUSH       0x0
//         0047edf0     PUSH       EDX
//         0047edf1     PUSH       EAX
//                              registry.cpp:199 (6)
//         0047edf2     CALL       dword ptr [->ADVAPI32.DLL::RegQueryValueExA]     = 0048b3b8
//                              registry.cpp:203 (3)
//         0047edf8     RET        0x10
//                               LAB_0047edfb                                                 XREF[1]:     0047edd6(j)
//                              registry.cpp:199 (32)
//         0047edfb     MOV        EDX,dword ptr [ESP + param_4]
//         0047edff     MOV        EAX,dword ptr [ESP + param_3]
//         0047ee03     MOV        this,dword ptr [ECX + this->ghMachineKeyRead]
//         0047ee06     PUSH       EDX
//         0047ee07     LEA        EDX=>param_4,[ESP + 0x14]
//         0047ee0b     PUSH       EAX
//         0047ee0c     MOV        EAX,dword ptr [ESP + param_2]
//         0047ee10     PUSH       EDX
//         0047ee11     PUSH       0x0
//         0047ee13     PUSH       EAX
//         0047ee14     PUSH       this
//         0047ee15     CALL       dword ptr [->ADVAPI32.DLL::RegQueryValueExA]     = 0048b3b8
//                              registry.cpp:203 (3)
//         0047ee1b     RET        0x10
//         0047ee1e     ??         90h
//         0047ee1f     NOP
    return 0;
}

int TRegistry::RegGetInt(int param_1, char* param_2) {
    /* TODO: Stub */
//                              int __thiscall RegGetInt(TRegistry * this, int param_1, char * param
//              int               EAX:4          <RETURN>
//              TRegistry *       ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0047ee30(R)
//              char *            Stack[0x8]:4   param_2                   XREF[4]:     0047ee3c(*), 0047ee46(*), 0047ee5c(*), 0047ee65(*)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0047ee2c(W), 0047ee41(*), 0047ee60(*)
//              ulong             Stack[-0x8]:4  dwType                    XREF[3]:     0047ee28(*), 0047ee38(*), 0047ee57(*)
//              ulong             Stack[-0xc]:4  Size
//                               ?RegGetInt@TRegistry@@QAEHHPBD@Z                             XREF[20]:    setup:0041baf7(c),
//                               TRegistry::RegGetInt                                                      setup:0041bb8a(c),
//                                                                                                         setup:0041bbb6(c),
//                                                                                                         setup:0041bbe5(c),
//                                                                                                         setup:0041bc0f(c),
//                                                                                                         setup:0041bc2b(c),
//                                                                                                         setup:0041bc4f(c),
//                                                                                                         setup:0041bc73(c),
//                                                                                                         setup:0041bfff(c),
//                                                                                                         setup:0041c015(c),
//                                                                                                         ~RGE_Base_Game:0041c40d(c),
//                                                                                                         ~RGE_Base_Game:0041c422(c),
//                                                                                                         setup_mouse:0041ec17(c),
//                                                                                                         setup_sound_system:0041f0d9(c),
//                                                                                                         setup_music_system:0041f153(c),
//                                                                                                         TRIBE_Screen_Sed:004a832a(c),
//                                                                                                         command_save:004ad855(c),
//                                                                                                         scenario_get_default_name:004adaa3
//                                                                                                         scenario_save_defaulted:004adba8(c
//                                                                                                         scenario_save_defaulted:004adc0d(c
//                              registry.cpp:206 (3)
//         0047ee20     SUB        ESP,0x8
//                              registry.cpp:212 (9)
//         0047ee23     MOV        EAX,0x4
//         0047ee28     MOV        dword ptr [ESP]=>dwType,EAX
//                              registry.cpp:213 (4)
//         0047ee2c     MOV        dword ptr [ESP + local_4],EAX
//                              registry.cpp:215 (8)
//         0047ee30     MOV        EAX,dword ptr [ESP + param_1]
//         0047ee34     TEST       EAX,EAX
//         0047ee36     JZ         LAB_0047ee54
//                              registry.cpp:216 (26)
//         0047ee38     LEA        EAX=>dwType,[ESP]
//         0047ee3c     LEA        EDX=>param_2,[ESP + 0x10]
//         0047ee40     PUSH       EAX
//         0047ee41     LEA        EAX=>local_4,[ESP + 0x8]
//         0047ee45     PUSH       EDX
//         0047ee46     MOV        EDX=>param_2,dword ptr [ESP + 0x18]
//         0047ee4a     PUSH       EAX
//         0047ee4b     MOV        EAX,dword ptr [ECX + this->ghUserKey]
//         0047ee4e     PUSH       0x0
//         0047ee50     PUSH       EDX
//         0047ee51     PUSH       EAX
//                              registry.cpp:217 (2)
//         0047ee52     JMP        LAB_0047ee6e
//                               LAB_0047ee54                                                 XREF[1]:     0047ee36(j)
//                              registry.cpp:218 (32)
//         0047ee54     MOV        this,dword ptr [ECX + this->ghMachineKeyRead]
//         0047ee57     LEA        EDX=>dwType,[ESP]
//         0047ee5b     PUSH       EDX
//         0047ee5c     LEA        EAX=>param_2,[ESP + 0x14]
//         0047ee60     LEA        EDX=>local_4,[ESP + 0x8]
//         0047ee64     PUSH       EAX
//         0047ee65     MOV        EAX=>param_2,dword ptr [ESP + 0x18]
//         0047ee69     PUSH       EDX
//         0047ee6a     PUSH       0x0
//         0047ee6c     PUSH       EAX
//         0047ee6d     PUSH       this
//                               LAB_0047ee6e                                                 XREF[1]:     0047ee52(j)
//         0047ee6e     CALL       dword ptr [->ADVAPI32.DLL::RegQueryValueExA]     = 0048b3b8
//                              registry.cpp:220 (4)
//         0047ee74     TEST       EAX,EAX
//         0047ee76     JNZ        LAB_0047ee82
//                              registry.cpp:223 (4)
//         0047ee78     MOV        EAX,dword ptr [ESP + 0x10]
//                              registry.cpp:231 (6)
//         0047ee7c     ADD        ESP,0x8
//         0047ee7f     RET        0x8
//                               LAB_0047ee82                                                 XREF[1]:     0047ee76(j)
//                              registry.cpp:230 (3)
//         0047ee82     OR         EAX,0xffffffff
//                              registry.cpp:231 (6)
//         0047ee85     ADD        ESP,0x8
//         0047ee88     RET        0x8
//         0047ee8b     ??         90h
//         0047ee8c     NOP
//         0047ee8d     NOP
//         0047ee8e     NOP
//         0047ee8f     NOP
    return 0;
}

