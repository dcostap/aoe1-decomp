#include "common.h"
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
    //                              * void __cdecl RESFILE_open_new_resource_file(char *,char *,char *,int)                                 *
    //                              void __cdecl RESFILE_open_new_resource_file(char * param_1, char * p
    //              void              <VOID>         <RETURN>
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     0047ee9f(R)  
    //              char *            Stack[0x8]:4   param_2
    //              char *            Stack[0xc]:4   param_3                   XREF[1]:     0047ee99(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[2]:     0047eec3(R), 0047efb7(R)  
    //              uchar *           Stack[-0x8]:4  mapped_file_data          XREF[3]:     0047eeb0(W), 0047ef4d(W), 0047efca(R)  
    //              int               Stack[-0xc]:4  fHandle                   XREF[3]:     0047eeb7(W), 0047efde(R), 0047f139(W)  
    //              resfile_header    Stack[-0x4c]   rHeader                   XREF[1,3]:   0047eff7(*), 0047f027(R), 0047f040(R), 0047f051(R)  
    //              char[80]          Stack[-0x9c]   error_msg                 XREF[2]:     0047f148(*), 0047f157(*)  
    //              char[260]         Stack[-0x1a0   resFile                   XREF[3]:     0047eea2(*), 0047eede(*), 0047f122(*)  
    //                               ?RESFILE_open_new_resource_file@@YAXPAD00H@Z                 XREF[8]:     setup:0052187b(c), 
    //                               RESFILE_open_new_resource_file                                            setup:00521899(c), 
    //                                                                                                         setup:005218b7(c), 
    //                                                                                                         setup:005218cf(c), 
    //                                                                                                         setup:005218e8(c), 
    //                                                                                                         setup:00521901(c), 
    //                                                                                                         setup:0052191a(c), 
    //                                                                                                         setup:00521933(c)  
    //                              Res_file.cpp:70 (9)
    //         0047ee90     PUSH       EBP
    //         0047ee91     MOV        EBP,ESP
    //         0047ee93     SUB        ESP,0x19c
    //                              Res_file.cpp:84 (42)
    //         0047ee99     MOV        EAX,dword ptr [EBP + param_3]
    //         0047ee9c     PUSH       EBX
    //         0047ee9d     PUSH       ESI
    //         0047ee9e     PUSH       EDI
    //         0047ee9f     MOV        EDI,dword ptr [EBP + param_1]
    //         0047eea2     LEA        ECX=>resFile,[EBP + 0xfffffe64]
    //         0047eea8     PUSH       EDI
    //         0047eea9     PUSH       EAX
    //         0047eeaa     PUSH       s_%s%s                                           = "%s%s"
    //         0047eeaf     PUSH       ECX
    //         0047eeb0     MOV        dword ptr [EBP + mapped_file_data],0x0
    //         0047eeb7     MOV        dword ptr [EBP + fHandle],0xffffffff
    //         0047eebe     CALL       sprintf                                          undefined sprintf()
    //                              Res_file.cpp:88 (14)
    //         0047eec3     MOV        EAX,dword ptr [EBP + param_4]
    //         0047eec6     ADD        ESP,0x10
    //         0047eec9     TEST       EAX,EAX
    //         0047eecb     JNZ        LAB_0047f122
    //                              Res_file.cpp:91 (33)
    //         0047eed1     PUSH       0x0
    //                              language.dll match for 0x80: "Arial"
    //         0047eed3     PUSH       0x80
    //         0047eed8     PUSH       0x4
    //         0047eeda     PUSH       0x0
    //         0047eedc     PUSH       0x1
    //         0047eede     LEA        EDX=>resFile,[EBP + 0xfffffe64]
    //         0047eee4     PUSH       0x80000000
    //         0047eee9     PUSH       EDX
    //         0047eeea     CALL       dword ptr [->KERNEL32.DLL::CreateFileA]          = 0048ac1c
    //         0047eef0     MOV        ESI,EAX
    //                              Res_file.cpp:93 (5)
    //         0047eef2     CMP        ESI,-0x1
    //         0047eef5     JNZ        LAB_0047ef02
    //                              Res_file.cpp:96 (6)
    //         0047eef7     PUSH       EDI
    //         0047eef8     PUSH       s_Error:_Open_new_ResFile,_mapped_               = "Error: Open_new_ResFile, mapped file %s no
    //                              Res_file.cpp:99 (5)
    //         0047eefd     JMP        LAB_0047f148
    //                               LAB_0047ef02                                                 XREF[1]:     0047eef5(j)  
    //                              Res_file.cpp:102 (17)
    //         0047ef02     PUSH       0x0
    //         0047ef04     PUSH       0x0=>DAT_fffffff8
    //         0047ef06     PUSH       0x0=>DAT_fffffff4
    //         0047ef08     PUSH       offset DAT_fffffff0
    //         0047ef0a     PUSH       0x0
    //         0047ef0c     PUSH       ESI
    //         0047ef0d     CALL       dword ptr [->KERNEL32.DLL::CreateFileMappingA]   = 0048ac06
    //                              Res_file.cpp:104 (11)
    //         0047ef13     PUSH       ESI
    //         0047ef14     MOV        ESI,dword ptr [->KERNEL32.DLL::CloseHandle]      = 0048aa26
    //         0047ef1a     MOV        EBX,EAX
    //         0047ef1c     CALL       ESI=>KERNEL32.DLL::CloseHandle
    //                              Res_file.cpp:106 (4)
    //         0047ef1e     TEST       EBX,EBX
    //         0047ef20     JNZ        LAB_0047ef3c
    //                              Res_file.cpp:109 (12)
    //         0047ef22     PUSH       0x30
    //         0047ef24     PUSH       s_RESOURCE_ERROR                                 = "RESOURCE ERROR"
    //         0047ef29     PUSH       s_Error:_Open_Mapped_ResFile,_Coul               = "Error: Open_Mapped_ResFile, Could not map 
    //                              Res_file.cpp:228 (7)
    //         0047ef2e     PUSH       EBX=>DAT_fffffff0
    //         0047ef2f     CALL       dword ptr [->USER32.DLL::MessageBoxA]            = 0048b00c
    //                              Res_file.cpp:233 (7)
    //         0047ef35     POP        EDI
    //         0047ef36     POP        ESI
    //         0047ef37     POP        EBX
    //         0047ef38     MOV        ESP,EBP
    //         0047ef3a     POP        EBP
    //         0047ef3b     RET
    //                               LAB_0047ef3c                                                 XREF[1]:     0047ef20(j)  
    //                              Res_file.cpp:116 (15)
    //         0047ef3c     PUSH       0x0
    //         0047ef3e     PUSH       0x0=>DAT_fffffff8
    //         0047ef40     PUSH       0x0=>DAT_fffffff4
    //         0047ef42     PUSH       offset DAT_fffffff0
    //         0047ef44     PUSH       EBX
    //         0047ef45     CALL       dword ptr [->KERNEL32.DLL::MapViewOfFile]        = 0048abf6
    //                              Res_file.cpp:118 (7)
    //         0047ef4b     TEST       EAX,EAX
    //         0047ef4d     MOV        dword ptr [EBP + mapped_file_data],EAX
    //         0047ef50     JNZ        LAB_0047ef6c
    //                              Res_file.cpp:121 (12)
    //         0047ef52     PUSH       0x30
    //         0047ef54     PUSH       s_RESOURCE_ERROR                                 = "RESOURCE ERROR"
    //         0047ef59     PUSH       s_Error:_Open_Mapped_ResFile,_Coul               = "Error: Open_Mapped_ResFile, Could not map 
    //                              Res_file.cpp:228 (7)
    //         0047ef5e     PUSH       EAX=>DAT_fffffff0
    //         0047ef5f     CALL       dword ptr [->USER32.DLL::MessageBoxA]            = 0048b00c
    //                              Res_file.cpp:233 (7)
    //         0047ef65     POP        EDI
    //         0047ef66     POP        ESI
    //         0047ef67     POP        EBX
    //         0047ef68     MOV        ESP,EBP
    //         0047ef6a     POP        EBP
    //         0047ef6b     RET
    //                               LAB_0047ef6c                                                 XREF[1]:     0047ef50(j)  
    //                              Res_file.cpp:126 (3)
    //         0047ef6c     PUSH       EBX
    //         0047ef6d     CALL       ESI=>KERNEL32.DLL::CloseHandle
    //                               LAB_0047ef6f                                                 XREF[1]:     0047f13c(j)  
    //                              Res_file.cpp:147 (15)
    //         0047ef6f     PUSH       0x114
    //         0047ef74     CALL       malloc                                           undefined malloc()
    //         0047ef79     MOV        EBX,EAX
    //         0047ef7b     ADD        ESP,0x4
    //                              Res_file.cpp:149 (4)
    //         0047ef7e     TEST       EBX,EBX
    //         0047ef80     JNZ        LAB_0047ef9c
    //                              Res_file.cpp:152 (12)
    //         0047ef82     PUSH       0x30
    //         0047ef84     PUSH       s_RESOURCE_ERROR                                 = "RESOURCE ERROR"
    //         0047ef89     PUSH       s_Error:_Out_of_memory_in_Open_res               = "Error: Out of memory in Open_resfile."
    //                              Res_file.cpp:228 (7)
    //         0047ef8e     PUSH       EAX=>DAT_fffffff0
    //         0047ef8f     CALL       dword ptr [->USER32.DLL::MessageBoxA]            = 0048b00c
    //                              Res_file.cpp:233 (7)
    //         0047ef95     POP        EDI
    //         0047ef96     POP        ESI
    //         0047ef97     POP        EBX
    //         0047ef98     MOV        ESP,EBP
    //         0047ef9a     POP        EBP
    //         0047ef9b     RET
    //                               LAB_0047ef9c                                                 XREF[1]:     0047ef80(j)  
    //                              Res_file.cpp:159 (27)
    //         0047ef9c     OR         ECX,0xffffffff
    //         0047ef9f     XOR        EAX,EAX
    //         0047efa1     SCASB.RE   ES:EDI
    //         0047efa3     NOT        ECX
    //         0047efa5     SUB        EDI,ECX
    //         0047efa7     LEA        EDX,[EBX + 0x10]
    //         0047efaa     MOV        EAX,ECX
    //         0047efac     MOV        ESI,EDI
    //         0047efae     MOV        EDI,EDX
    //         0047efb0     SHR        ECX,0x2
    //         0047efb3     MOVSD.REP  ES:EDI,ESI
    //         0047efb5     MOV        ECX,EAX
    //                              Res_file.cpp:162 (19)
    //         0047efb7     MOV        EAX,dword ptr [EBP + param_4]
    //         0047efba     AND        ECX,0x3
    //         0047efbd     MOVSB.REP  ES:EDI,ESI
    //         0047efbf     TEST       EAX,EAX
    //         0047efc1     MOV        dword ptr [EBX + 0xc],0x0
    //         0047efc8     JNZ        LAB_0047efde
    //                              Res_file.cpp:164 (3)
    //         0047efca     MOV        EAX,dword ptr [EBP + mapped_file_data]
    //                              Res_file.cpp:166 (12)
    //         0047efcd     MOV        dword ptr [EBX + 0x4],0xffffffff
    //         0047efd4     MOV        dword ptr [EBX],EAX
    //         0047efd6     MOV        dword ptr [EBX + 0x8],EAX
    //                              Res_file.cpp:169 (5)
    //         0047efd9     JMP        FUN_0047f076                                     undefined FUN_0047f076()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
    //                               LAB_0047efde                                                 XREF[1]:     0047efc8(j)  
    //                              Res_file.cpp:171 (3)
    //         0047efde     MOV        ESI,dword ptr [EBP + fHandle]
    //                              Res_file.cpp:174 (22)
    //         0047efe1     PUSH       0x1
    //         0047efe3     PUSH       0x0=>DAT_fffffff8
    //         0047efe5     PUSH       ESI=>DAT_fffffff4
    //         0047efe6     MOV        dword ptr [EBX + 0x4],ESI
    //         0047efe9     MOV        dword ptr [EBX],0x0
    //         0047efef     CALL       lseek                                            undefined lseek()
    //         0047eff4     ADD        ESP,0xc
    //                              Res_file.cpp:176 (15)
    //         0047eff7     LEA        ECX=>rHeader,[EBP + -0x48]
    //         0047effa     PUSH       0x40
    //         0047effc     PUSH       ECX=>DAT_fffffff8
    //         0047effd     PUSH       ESI=>DAT_fffffff4
    //         0047effe     CALL       read                                             undefined read()
    //         0047f003     ADD        ESP,0xc
    //                              Res_file.cpp:178 (5)
    //         0047f006     CMP        EAX,0x40
    //         0047f009     JZ         LAB_0047f027
    //                              Res_file.cpp:181 (1)
    //         0047f00b     INT3
    //                              *                                               FUNCTION                                                *
    //                              undefined FUN_0047f00c()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0047f00c
    //                              Res_file.cpp:182 (12)
    //         0047f00c     PUSH       0x30
    //         0047f00e     PUSH       s_RESOURCE_ERROR                                 = "RESOURCE ERROR"
    //         0047f013     PUSH       s_Error:_Reading_resfile_header.                 = "Error: Reading resfile header."
    //                              Res_file.cpp:228 (8)
    //         0047f018     PUSH       0x0
    //         0047f01a     CALL       dword ptr [->USER32.DLL::MessageBoxA]            = 0048b00c
    //                              Res_file.cpp:233 (7)
    //         0047f020     POP        EDI
    //         0047f021     POP        ESI
    //         0047f022     POP        EBX
    //         0047f023     MOV        ESP,EBP
    //         0047f025     POP        EBP
    //         0047f026     RET
    //                               LAB_0047f027                                                 XREF[1]:     0047f009(j)  
    //                              Res_file.cpp:187 (15)
    //         0047f027     MOV        EDX,dword ptr [EBP + rHeader.directory_size]
    //         0047f02a     PUSH       EDX
    //         0047f02b     CALL       malloc                                           undefined malloc()
    //         0047f030     ADD        ESP,0x4
    //         0047f033     MOV        dword ptr [EBX + 0x8],EAX
    //                              Res_file.cpp:188 (10)
    //         0047f036     PUSH       0x0
    //         0047f038     PUSH       0x0=>DAT_fffffff8
    //         0047f03a     PUSH       ESI=>DAT_fffffff4
    //         0047f03b     CALL       lseek                                            undefined lseek()
    //                              Res_file.cpp:189 (17)
    //         0047f040     MOV        EAX,dword ptr [EBP + rHeader.directory_size]
    //         0047f043     MOV        ECX,dword ptr [EBX + 0x8]
    //         0047f046     ADD        ESP,0xc
    //         0047f049     PUSH       EAX
    //         0047f04a     PUSH       ECX=>DAT_fffffff8
    //         0047f04b     PUSH       ESI=>DAT_fffffff4
    //         0047f04c     CALL       read                                             undefined read()
    //                              Res_file.cpp:191 (10)
    //         0047f051     MOV        ECX,dword ptr [EBP + rHeader.directory_size]
    //         0047f054     ADD        ESP,0xc
    //         0047f057     CMP        EAX,ECX
    //         0047f059     JZ         FUN_0047f076
    //                              Res_file.cpp:194 (12)
    //         0047f05b     PUSH       0x30
    //         0047f05d     PUSH       s_RESOURCE_ERROR                                 = "RESOURCE ERROR"
    //         0047f062     PUSH       s_Error:_Reading_resfile_header_da               = "Error: Reading resfile header data."
    //                              Res_file.cpp:228 (8)
    //         0047f067     PUSH       0x0=>DAT_fffffff0
    //         0047f069     CALL       dword ptr [->USER32.DLL::MessageBoxA]            = 0048b00c
    //                              Res_file.cpp:233 (7)
    //         0047f06f     POP        EDI
    //         0047f070     POP        ESI
    //         0047f071     POP        EBX
    //         0047f072     MOV        ESP,EBP
    //         0047f074     POP        EBP
    //         0047f075     RET
    //                              *                                               FUNCTION                                                *
    //                              undefined FUN_0047f076()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0047f076                                                 XREF[2]:     RESFILE_open_new_resource_file:004
    //                                                                                                         RESFILE_open_new_resource_file:004
    //                              Res_file.cpp:202 (10)
    //         0047f076     MOV        ECX,dword ptr [DAT_0086b254]
    //         0047f07c     TEST       ECX,ECX
    //         0047f07e     JNZ        LAB_0047f088
    //                              Res_file.cpp:204 (6)
    //         0047f080     MOV        dword ptr [DAT_0086b254],EBX
    //                              Res_file.cpp:206 (2)
    //         0047f086     JMP        LAB_0047f09b
    //                               LAB_0047f088                                                 XREF[1]:     0047f07e(j)  
    //                              Res_file.cpp:209 (16)
    //         0047f088     MOV        EAX,dword ptr [ECX + 0xc]
    //         0047f08b     TEST       EAX,EAX
    //         0047f08d     JZ         LAB_0047f098
    //                               LAB_0047f08f                                                 XREF[1]:     0047f096(j)  
    //         0047f08f     MOV        ECX,EAX
    //         0047f091     MOV        EAX,dword ptr [ECX + 0xc]
    //         0047f094     TEST       EAX,EAX
    //         0047f096     JNZ        LAB_0047f08f
    //                               LAB_0047f098                                                 XREF[1]:     0047f08d(j)  
    //                              Res_file.cpp:210 (3)
    //         0047f098     MOV        dword ptr [ECX + 0xc],EBX
    //                               LAB_0047f09b                                                 XREF[1]:     0047f086(j)  
    //                              Res_file.cpp:215 (58)
    //         0047f09b     MOV        EDI,dword ptr [EBX + 0x8]
    //         0047f09e     MOV        ESI,dword ptr [EBP + 0xc]
    //         0047f0a1     LEA        EAX,[EDI + 0x2c]
    //                               LAB_0047f0a4                                                 XREF[1]:     0047f0c6(j)  
    //         0047f0a4     MOV        DL,byte ptr [EAX]
    //         0047f0a6     MOV        BL,byte ptr [ESI]
    //         0047f0a8     MOV        CL,DL
    //         0047f0aa     CMP        DL,BL
    //         0047f0ac     JNZ        LAB_0047f0cc
    //         0047f0ae     TEST       CL,CL
    //         0047f0b0     JZ         LAB_0047f0c8
    //         0047f0b2     MOV        DL,byte ptr [EAX + 0x1]
    //         0047f0b5     MOV        BL,byte ptr [ESI + 0x1]
    //         0047f0b8     MOV        CL,DL
    //         0047f0ba     CMP        DL,BL
    //         0047f0bc     JNZ        LAB_0047f0cc
    //         0047f0be     ADD        EAX,0x2
    //         0047f0c1     ADD        ESI,0x2
    //         0047f0c4     TEST       CL,CL
    //         0047f0c6     JNZ        LAB_0047f0a4
    //                               LAB_0047f0c8                                                 XREF[1]:     0047f0b0(j)  
    //         0047f0c8     XOR        EAX,EAX
    //         0047f0ca     JMP        LAB_0047f0d1
    //                               LAB_0047f0cc                                                 XREF[2]:     0047f0ac(j), 0047f0bc(j)  
    //         0047f0cc     SBB        EAX,EAX
    //         0047f0ce     SBB        EAX,-0x1
    //                               LAB_0047f0d1                                                 XREF[1]:     0047f0ca(j)  
    //         0047f0d1     TEST       EAX,EAX
    //         0047f0d3     JZ         LAB_0047f0f0
    //                              Res_file.cpp:218 (12)
    //         0047f0d5     PUSH       0x30
    //         0047f0d7     PUSH       s_RESOURCE_ERROR                                 = "RESOURCE ERROR"
    //         0047f0dc     PUSH       s_Error:_Open_ResFile,_Corruption_               = "Error: Open_ResFile, Corruption detected i
    //                              Res_file.cpp:228 (8)
    //         0047f0e1     PUSH       0x0=>DAT_fffffff0
    //         0047f0e3     CALL       dword ptr [->USER32.DLL::MessageBoxA]            = 0048b00c
    //                              Res_file.cpp:233 (7)
    //         0047f0e9     POP        EDI
    //         0047f0ea     POP        ESI
    //         0047f0eb     POP        EBX
    //         0047f0ec     MOV        ESP,EBP
    //         0047f0ee     POP        EBP
    //         0047f0ef     RET
    //                               LAB_0047f0f0                                                 XREF[1]:     0047f0d3(j)  
    //                              Res_file.cpp:225 (23)
    //         0047f0f0     PUSH       0x4
    //         0047f0f2     ADD        EDI,0x28
    //         0047f0f5     PUSH       s_1.00                                           = "1.00"
    //         0047f0fa     PUSH       EDI=>DAT_fffffff4
    //         0047f0fb     CALL       strncmp                                          undefined strncmp()
    //         0047f100     ADD        ESP,0xc
    //         0047f103     TEST       EAX,EAX
    //         0047f105     JZ         LAB_0047f11b
    //                              Res_file.cpp:228 (20)
    //         0047f107     PUSH       0x30
    //         0047f109     PUSH       s_RESOURCE_ERROR                                 = "RESOURCE ERROR"
    //         0047f10e     PUSH       s_Error:_Open_ResFile,_Resfile_not               = "Error: Open_ResFile, Resfile not correct."
    //         0047f113     PUSH       0x0=>DAT_fffffff0
    //         0047f115     CALL       dword ptr [->USER32.DLL::MessageBoxA]            = 0048b00c
    //                               LAB_0047f11b                                                 XREF[1]:     0047f105(j)  
    //                              Res_file.cpp:233 (7)
    //         0047f11b     POP        EDI
    //         0047f11c     POP        ESI
    //         0047f11d     POP        EBX
    //         0047f11e     MOV        ESP,EBP
    //         0047f120     POP        EBP
    //         0047f121     RET
    //                               LAB_0047f122                                                 XREF[1]:     0047eecb(j)  
    //                              Res_file.cpp:131 (20)
    //         0047f122     LEA        EDX=>resFile,[EBP + 0xfffffe64]
    //         0047f128     PUSH       0x8000
    //         0047f12d     PUSH       EDX
    //         0047f12e     CALL       __open                                           undefined __open()
    //         0047f133     ADD        ESP,0x8
    //                              Res_file.cpp:133 (12)
    //         0047f136     CMP        EAX,-0x1
    //         0047f139     MOV        dword ptr [EBP + fHandle],EAX
    //         0047f13c     JNZ        LAB_0047ef6f
    //                              Res_file.cpp:136 (21)
    //         0047f142     PUSH       EDI
    //         0047f143     PUSH       s_Error:_Open_new_ResFile,_file_%s               = "Error: Open_new_ResFile, file %s not Found."
    //                               LAB_0047f148                                                 XREF[1]:     0047eefd(j)  
    //         0047f148     LEA        EAX=>error_msg,[EBP + 0xffffff68]
    //         0047f14e     PUSH       EAX=>DAT_fffffff4
    //         0047f14f     CALL       sprintf                                          undefined sprintf()
    //         0047f154     ADD        ESP,0xc
    //                              Res_file.cpp:137 (14)
    //         0047f157     LEA        ECX=>error_msg,[EBP + 0xffffff68]
    //         0047f15d     PUSH       0x30
    //         0047f15f     PUSH       s_RESOURCE_ERROR                                 = "RESOURCE ERROR"
    //         0047f164     PUSH       ECX=>DAT_fffffff4
    //                              Res_file.cpp:228 (8)
    //         0047f165     PUSH       0x0=>DAT_fffffff0
    //         0047f167     CALL       dword ptr [->USER32.DLL::MessageBoxA]            = 0048b00c
    //                              Res_file.cpp:233 (7)
    //         0047f16d     POP        EDI
    //         0047f16e     POP        ESI
    //         0047f16f     POP        EBX
    //         0047f170     MOV        ESP,EBP
    //         0047f172     POP        EBP
    //         0047f173     RET
    //         0047f174     ??         90h
    //         0047f175     NOP
    //         0047f176     NOP
    //         0047f177     NOP
    //         0047f178     NOP
    //         0047f179     NOP
    //         0047f17a     NOP
    //         0047f17b     NOP
    //         0047f17c     NOP
    //         0047f17d     NOP
    //         0047f17e     NOP
    //         0047f17f     NOP
    //                              * void __cdecl RESFILE_close_new_resource_file(char *)                                                  *
    //                              void __cdecl RESFILE_close_new_resource_file(char * param_1)
    //              void              <VOID>         <RETURN>
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     0047f194(R)  
    //                               ?RESFILE_close_new_resource_file@@YAXPAD@Z                   XREF[5]:     ~TRIBE_Game:0052159f(c), 
    //                               RESFILE_close_new_resource_file                                           ~TRIBE_Game:005215ac(c), 
    //                                                                                                         ~TRIBE_Game:005215b9(c), 
    //                                                                                                         ~TRIBE_Game:005215c6(c), 
    //                                                                                                         ~TRIBE_Game:005215d3(c)  
    //                              Res_file.cpp:240 (4)
    //         0047f180     PUSH       EBX
    //         0047f181     PUSH       EBP
    //         0047f182     PUSH       ESI
    //         0047f183     PUSH       EDI
    //                              Res_file.cpp:243 (20)
    //         0047f184     MOV        EDI,dword ptr [DAT_0086b254]
    //         0047f18a     XOR        EBX,EBX
    //         0047f18c     TEST       EDI,EDI
    //         0047f18e     JZ         LAB_0047f225
    //         0047f194     MOV        EBP,dword ptr [ESP + param_1]
    //                               LAB_0047f198                                                 XREF[1]:     0047f1d1(j)  
    //                              Res_file.cpp:245 (59)
    //         0047f198     LEA        ESI,[EDI + 0x10]
    //         0047f19b     MOV        EAX,EBP
    //                               LAB_0047f19d                                                 XREF[1]:     0047f1bb(j)  
    //         0047f19d     MOV        DL,byte ptr [EAX]
    //         0047f19f     MOV        CL,DL
    //         0047f1a1     CMP        DL,byte ptr [ESI]
    //         0047f1a3     JNZ        LAB_0047f1c1
    //         0047f1a5     TEST       CL,CL
    //         0047f1a7     JZ         LAB_0047f1bd
    //         0047f1a9     MOV        DL,byte ptr [EAX + 0x1]
    //         0047f1ac     MOV        CL,DL
    //         0047f1ae     CMP        DL,byte ptr [ESI + 0x1]
    //         0047f1b1     JNZ        LAB_0047f1c1
    //         0047f1b3     ADD        EAX,0x2
    //         0047f1b6     ADD        ESI,0x2
    //         0047f1b9     TEST       CL,CL
    //         0047f1bb     JNZ        LAB_0047f19d
    //                               LAB_0047f1bd                                                 XREF[1]:     0047f1a7(j)  
    //         0047f1bd     XOR        EAX,EAX
    //         0047f1bf     JMP        LAB_0047f1c6
    //                               LAB_0047f1c1                                                 XREF[2]:     0047f1a3(j), 0047f1b1(j)  
    //         0047f1c1     SBB        EAX,EAX
    //         0047f1c3     SBB        EAX,-0x1
    //                               LAB_0047f1c6                                                 XREF[1]:     0047f1bf(j)  
    //         0047f1c6     TEST       EAX,EAX
    //         0047f1c8     JZ         LAB_0047f1d8
    //         0047f1ca     MOV        EBX,EDI
    //         0047f1cc     MOV        EDI,dword ptr [EDI + 0xc]
    //         0047f1cf     TEST       EDI,EDI
    //         0047f1d1     JNZ        LAB_0047f198
    //                              Res_file.cpp:286 (5)
    //         0047f1d3     POP        EDI
    //         0047f1d4     POP        ESI
    //         0047f1d5     POP        EBP
    //         0047f1d6     POP        EBX
    //         0047f1d7     RET
    //                               LAB_0047f1d8                                                 XREF[1]:     0047f1c8(j)  
    //                              Res_file.cpp:249 (5)
    //         0047f1d8     CMP        dword ptr [EDI],0x0
    //         0047f1db     JNZ        LAB_0047f1e9
    //                              Res_file.cpp:251 (12)
    //         0047f1dd     MOV        EAX,dword ptr [EDI + 0x8]
    //         0047f1e0     PUSH       EAX
    //         0047f1e1     CALL       free                                             undefined free()
    //         0047f1e6     ADD        ESP,0x4
    //                               LAB_0047f1e9                                                 XREF[1]:     0047f1db(j)  
    //                              Res_file.cpp:256 (4)
    //         0047f1e9     TEST       EBX,EBX
    //         0047f1eb     JZ         LAB_0047f1f5
    //                              Res_file.cpp:258 (6)
    //         0047f1ed     MOV        ECX,dword ptr [EDI + 0xc]
    //         0047f1f0     MOV        dword ptr [EBX + 0xc],ECX
    //                              Res_file.cpp:260 (2)
    //         0047f1f3     JMP        LAB_0047f1fe
    //                               LAB_0047f1f5                                                 XREF[1]:     0047f1eb(j)  
    //                              Res_file.cpp:262 (9)
    //         0047f1f5     MOV        EDX,dword ptr [EDI + 0xc]
    //         0047f1f8     MOV        dword ptr [DAT_0086b254],EDX
    //                               LAB_0047f1fe                                                 XREF[1]:     0047f1f3(j)  
    //                              Res_file.cpp:267 (8)
    //         0047f1fe     MOV        EAX,dword ptr [EDI + 0x4]
    //         0047f201     CMP        EAX,-0x1
    //         0047f204     JZ         LAB_0047f20f
    //                              Res_file.cpp:269 (9)
    //         0047f206     PUSH       EAX
    //         0047f207     CALL       close                                            undefined close()
    //         0047f20c     ADD        ESP,0x4
    //                               LAB_0047f20f                                                 XREF[1]:     0047f204(j)  
    //                              Res_file.cpp:274 (6)
    //         0047f20f     MOV        EAX,dword ptr [EDI]
    //         0047f211     TEST       EAX,EAX
    //         0047f213     JZ         LAB_0047f21c
    //                              Res_file.cpp:276 (7)
    //         0047f215     PUSH       EAX
    //         0047f216     CALL       dword ptr [->KERNEL32.DLL::UnmapViewOfFile]      = 0048ac2a
    //                               LAB_0047f21c                                                 XREF[1]:     0047f213(j)  
    //                              Res_file.cpp:281 (9)
    //         0047f21c     PUSH       EDI
    //         0047f21d     CALL       free                                             undefined free()
    //         0047f222     ADD        ESP,0x4
    //                               LAB_0047f225                                                 XREF[1]:     0047f18e(j)  
    //                              Res_file.cpp:286 (5)
    //         0047f225     POP        EDI
    //         0047f226     POP        ESI
    //         0047f227     POP        EBP
    //         0047f228     POP        EBX
    //         0047f229     RET
    //         0047f22a     ??         90h
    //         0047f22b     NOP
    //         0047f22c     NOP
    //         0047f22d     NOP
    //         0047f22e     NOP
    //         0047f22f     NOP
    //                              * int __cdecl RESFILE_locate_resource(unsigned long,unsigned long,int &,int &,unsigned char * &,int &)  *
    //                              int __cdecl RESFILE_locate_resource(ulong param_1, ulong param_2, in
    //              int               EAX:4          <RETURN>
    //              ulong             Stack[0x4]:4   param_1                   XREF[1]:     0047f28b(R)  
    //              ulong             Stack[0x8]:4   param_2                   XREF[4]:     0047f26f(R), 0047f276(W), 0047f2b2(R), 0047f2bf(W)  
    //              int *             Stack[0xc]:4   param_3                   XREF[2]:     0047f231(R), 0047f2dc(R)  
    //              int *             Stack[0x10]:4  param_4                   XREF[2]:     0047f235(R), 0047f2eb(R)  
    //              uchar * *         Stack[0x14]:4  param_5                   XREF[2]:     0047f239(R), 0047f2f4(R)  
    //              int *             Stack[0x18]:4  param_6                   XREF[2]:     0047f24c(R), 0047f2fc(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     0047f25f(W), 0047f2ae(R), 0047f2ca(W), 0047f2d8(R)  
    //              ResFileHdr *      Stack[-0x8]:4  p
    //                               ?RESFILE_locate_resource@@YAHKKAAH0AAPAE0@Z                  XREF[1]:     RESFILE_load:0047f35f(c)  
    //                               RESFILE_locate_resource
    //                              Res_file.cpp:293 (1)
    //         0047f230     PUSH       ECX
    //                              Res_file.cpp:303 (4)
    //         0047f231     MOV        EAX,dword ptr [ESP + param_3]
    //                              Res_file.cpp:304 (4)
    //         0047f235     MOV        ECX,dword ptr [ESP + param_4]
    //                              Res_file.cpp:305 (19)
    //         0047f239     MOV        EDX,dword ptr [ESP + param_5]
    //         0047f23d     PUSH       EBX
    //         0047f23e     PUSH       EBP
    //         0047f23f     PUSH       ESI
    //         0047f240     MOV        ESI,dword ptr [DAT_0086b254]
    //         0047f246     MOV        dword ptr [EAX],0xffffffff
    //                              Res_file.cpp:306 (17)
    //         0047f24c     MOV        EAX,dword ptr [ESP + param_6]
    //         0047f250     MOV        dword ptr [ECX],0x0
    //         0047f256     MOV        dword ptr [EDX],0x0
    //         0047f25c     PUSH       EDI
    //                              Res_file.cpp:310 (22)
    //         0047f25d     TEST       ESI,ESI
    //         0047f25f     MOV        dword ptr [ESP + local_4],ESI
    //         0047f263     MOV        dword ptr [EAX],0x0
    //         0047f269     JZ         LAB_0047f310
    //         0047f26f     MOV        EBP,dword ptr [ESP + param_2]
    //                               LAB_0047f273                                                 XREF[1]:     0047f2ce(j)  
    //                              Res_file.cpp:314 (3)
    //         0047f273     MOV        EBX,dword ptr [ESI + 0x8]
    //                              Res_file.cpp:317 (15)
    //         0047f276     MOV        dword ptr [ESP + param_2],0x0
    //         0047f27e     MOV        EAX,dword ptr [EBX + 0x38]
    //         0047f281     TEST       EAX,EAX
    //         0047f283     JLE        LAB_0047f2c5
    //                              Res_file.cpp:314 (3)
    //         0047f285     LEA        EDI,[EBX + 0x48]
    //                               LAB_0047f288                                                 XREF[1]:     0047f2c3(j)  
    //                              Res_file.cpp:319 (11)
    //         0047f288     MOV        ECX,dword ptr [EDI + -0x8]
    //         0047f28b     MOV        EAX,dword ptr [ESP + param_1]
    //         0047f28f     CMP        ECX,EAX
    //         0047f291     JNZ        LAB_0047f2b2
    //                              Res_file.cpp:323 (3)
    //         0047f293     MOV        EDX,dword ptr [EDI + -0x4]
    //                              Res_file.cpp:324 (4)
    //         0047f296     MOV        ECX,dword ptr [EDI]
    //         0047f298     ADD        EDX,EBX
    //                              Res_file.cpp:339 (6)
    //         0047f29a     XOR        EAX,EAX
    //         0047f29c     TEST       ECX,ECX
    //         0047f29e     JLE        LAB_0047f2b2
    //                              Res_file.cpp:411 (2)
    //         0047f2a0     MOV        ESI,EDX
    //                               LAB_0047f2a2                                                 XREF[1]:     0047f2ac(j)  
    //                              Res_file.cpp:341 (12)
    //         0047f2a2     CMP        dword ptr [ESI],EBP
    //         0047f2a4     JZ         LAB_0047f2d8
    //         0047f2a6     INC        EAX
    //         0047f2a7     ADD        ESI,0xc
    //         0047f2aa     CMP        EAX,ECX
    //         0047f2ac     JL         LAB_0047f2a2
    //                              Res_file.cpp:339 (4)
    //         0047f2ae     MOV        ESI,dword ptr [ESP + local_4]
    //                               LAB_0047f2b2                                                 XREF[2]:     0047f291(j), 0047f29e(j)  
    //                              Res_file.cpp:317 (19)
    //         0047f2b2     MOV        EAX,dword ptr [ESP + param_2]
    //         0047f2b6     MOV        ECX,dword ptr [EBX + 0x38]
    //         0047f2b9     INC        EAX
    //         0047f2ba     ADD        EDI,0xc
    //         0047f2bd     CMP        EAX,ECX
    //         0047f2bf     MOV        dword ptr [ESP + param_2],EAX
    //         0047f2c3     JL         LAB_0047f288
    //                               LAB_0047f2c5                                                 XREF[1]:     0047f283(j)  
    //                              Res_file.cpp:353 (11)
    //         0047f2c5     MOV        ESI,dword ptr [ESI + 0xc]
    //         0047f2c8     TEST       ESI,ESI
    //         0047f2ca     MOV        dword ptr [ESP + local_4],ESI
    //         0047f2ce     JNZ        LAB_0047f273
    //                              Res_file.cpp:357 (2)
    //         0047f2d0     XOR        EAX,EAX
    //                              Res_file.cpp:411 (6)
    //         0047f2d2     POP        EDI
    //         0047f2d3     POP        ESI
    //         0047f2d4     POP        EBP
    //         0047f2d5     POP        EBX
    //         0047f2d6     POP        ECX
    //         0047f2d7     RET
    //                               LAB_0047f2d8                                                 XREF[1]:     0047f2a4(j)  
    //                              Res_file.cpp:343 (8)
    //         0047f2d8     MOV        ECX,dword ptr [ESP + local_4]
    //         0047f2dc     MOV        EDI,dword ptr [ESP + param_3]
    //                              Res_file.cpp:344 (20)
    //         0047f2e0     LEA        EAX,[EAX + EAX*0x2]
    //         0047f2e3     MOV        ESI,dword ptr [ECX + 0x4]
    //         0047f2e6     LEA        EAX,[EDX + EAX*0x4]
    //         0047f2e9     MOV        dword ptr [EDI],ESI
    //         0047f2eb     MOV        ESI,dword ptr [ESP + param_4]
    //         0047f2ef     MOV        EDX,dword ptr [EAX + 0x4]
    //         0047f2f2     MOV        dword ptr [ESI],EDX
    //                              Res_file.cpp:345 (8)
    //         0047f2f4     MOV        EDX,dword ptr [ESP + param_5]
    //         0047f2f8     MOV        ECX,dword ptr [ECX]
    //         0047f2fa     MOV        dword ptr [EDX],ECX
    //                              Res_file.cpp:346 (9)
    //         0047f2fc     MOV        ECX,dword ptr [ESP + param_6]
    //         0047f300     MOV        EAX,dword ptr [EAX + 0x8]
    //         0047f303     MOV        dword ptr [ECX],EAX
    //                              Res_file.cpp:347 (5)
    //         0047f305     MOV        EAX,0x1
    //                              Res_file.cpp:411 (14)
    //         0047f30a     POP        EDI
    //         0047f30b     POP        ESI
    //         0047f30c     POP        EBP
    //         0047f30d     POP        EBX
    //         0047f30e     POP        ECX
    //         0047f30f     RET
    //                               LAB_0047f310                                                 XREF[1]:     0047f269(j)  
    //         0047f310     POP        EDI
    //         0047f311     POP        ESI
    //         0047f312     POP        EBP
    //         0047f313     XOR        EAX,EAX
    //         0047f315     POP        EBX
    //         0047f316     POP        ECX
    //         0047f317     RET
    //         0047f318     ??         90h
    //         0047f319     NOP
    //         0047f31a     NOP
    //         0047f31b     NOP
    //         0047f31c     NOP
    //         0047f31d     NOP
    //         0047f31e     NOP
    //         0047f31f     NOP
    //                              * unsigned char * __cdecl RESFILE_load(unsigned long,unsigned long,int &,int &)                         *
    //                              uchar * __cdecl RESFILE_load(ulong param_1, ulong param_2, int * par
    //              uchar *           EAX:4          <RETURN>
    //              ulong             Stack[0x4]:4   param_1                   XREF[3]:     0047f327(*), 0047f335(R), 0047f3aa(R)  
    //              ulong             Stack[0x8]:4   param_2                   XREF[4]:     0047f330(R), 0047f348(*), 0047f41e(R), 0047f432(R)  
    //              int *             Stack[0xc]:4   param_3                   XREF[7]:     0047f323(*), 0047f33a(R), 0047f3b9(R), 0047f3d5(R), 
    //                                                                                     0047f3e8(R), 0047f42b(R), 0047f444(R)  
    //              int *             Stack[0x10]:4  param_4                   XREF[4]:     0047f32b(*), 0047f33f(R), 0047f3b2(R), 0047f417(R)  
    //              char[100]         Stack[-0x68]   error_string              XREF[0,2]:   0047f37a(*), 0047f38c(*)  
    //                               ?RESFILE_load@@YAPAEKKAAH0@Z                                 XREF[6]:     ReadPalette:00439805(c), 
    //                               RESFILE_load                                                              setup:00466cb2(c), 
    //                                                                                                         RESFILE_Extract_to_File:0047f4ac(c
    //                                                                                                         TShape:004b8d62(c), 
    //                                                                                                         TShape:004b8d9d(c), 
    //                                                                                                         load:004bd0b7(c)  
    //                              Res_file.cpp:420 (3)
    //         0047f320     SUB        ESP,0x64
    //                              Res_file.cpp:433 (72)
    //         0047f323     LEA        EAX=>param_3,[ESP + 0x70]
    //         0047f327     LEA        ECX=>param_1,[ESP + 0x68]
    //         0047f32b     LEA        EDX=>param_4,[ESP + 0x74]
    //         0047f32f     PUSH       EBX
    //         0047f330     MOV        EBX,dword ptr [ESP + param_2]
    //         0047f334     PUSH       EBP
    //         0047f335     MOV        EBP,dword ptr [ESP + param_1]
    //         0047f339     PUSH       ESI
    //         0047f33a     MOV        ESI,dword ptr [ESP + param_3]
    //         0047f33e     PUSH       EDI
    //         0047f33f     MOV        EDI,dword ptr [ESP + param_4]
    //         0047f346     PUSH       EAX
    //         0047f347     PUSH       ECX
    //         0047f348     LEA        EAX=>param_2,[ESP + 0x84]
    //         0047f34f     PUSH       EDX
    //         0047f350     PUSH       EAX
    //         0047f351     PUSH       EBX
    //         0047f352     MOV        dword ptr [ESI],0xffffffff
    //         0047f358     PUSH       EBP
    //         0047f359     MOV        dword ptr [EDI],0x0
    //         0047f35f     CALL       RESFILE_locate_resource                          int RESFILE_locate_resource(ulong param_1, ul
    //         0047f364     ADD        ESP,0x18
    //         0047f367     TEST       EAX,EAX
    //         0047f369     JNZ        LAB_0047f3aa
    //                              Res_file.cpp:435 (13)
    //         0047f36b     MOV        EAX,[DAT_0086b258]
    //         0047f370     TEST       EAX,EAX
    //         0047f372     JZ         LAB_0047f466
    //                              Res_file.cpp:438 (20)
    //         0047f378     PUSH       EBX
    //         0047f379     PUSH       EBP
    //         0047f37a     LEA        ECX=>error_string[4],[ESP + 0x18]
    //         0047f37e     PUSH       s_ERROR:_res_read_bin,_resource_ty               = "ERROR: res_read_bin, resource type %4.4c ,
    //         0047f383     PUSH       ECX
    //         0047f384     CALL       sprintf                                          undefined sprintf()
    //         0047f389     ADD        ESP,0x10
    //                              Res_file.cpp:439 (20)
    //         0047f38c     LEA        EDX=>error_string[4],[ESP + 0x10]
    //         0047f390     PUSH       0x30
    //         0047f392     PUSH       s_RESOURCE_ERROR                                 = "RESOURCE ERROR"
    //         0047f397     PUSH       EDX
    //         0047f398     PUSH       0x0
    //         0047f39a     CALL       dword ptr [->USER32.DLL::MessageBoxA]            = 0048b00c
    //                              Res_file.cpp:442 (2)
    //         0047f3a0     XOR        EAX,EAX
    //                              Res_file.cpp:484 (8)
    //         0047f3a2     POP        EDI
    //         0047f3a3     POP        ESI
    //         0047f3a4     POP        EBP
    //         0047f3a5     POP        EBX
    //         0047f3a6     ADD        ESP,0x64
    //         0047f3a9     RET
    //                               LAB_0047f3aa                                                 XREF[1]:     0047f369(j)  
    //                              Res_file.cpp:446 (8)
    //         0047f3aa     MOV        EAX,dword ptr [ESP + param_1]
    //         0047f3ae     TEST       EAX,EAX
    //         0047f3b0     JZ         LAB_0047f3d5
    //                              Res_file.cpp:451 (7)
    //         0047f3b2     MOV        ECX,dword ptr [ESP + param_4]
    //                              Res_file.cpp:452 (18)
    //         0047f3b9     MOV        EDX,dword ptr [ESP + param_3]
    //         0047f3c0     MOV        dword ptr [ESI],0x0
    //         0047f3c6     MOV        dword ptr [EDI],EDX
    //         0047f3c8     LEA        ESI,[ECX + EAX*0x1]
    //                              Res_file.cpp:483 (2)
    //         0047f3cb     MOV        EAX,ESI
    //                              Res_file.cpp:484 (8)
    //         0047f3cd     POP        EDI
    //         0047f3ce     POP        ESI
    //         0047f3cf     POP        EBP
    //         0047f3d0     POP        EBX
    //         0047f3d1     ADD        ESP,0x64
    //         0047f3d4     RET
    //                               LAB_0047f3d5                                                 XREF[1]:     0047f3b0(j)  
    //                              Res_file.cpp:459 (19)
    //         0047f3d5     MOV        EAX,dword ptr [ESP + param_3]
    //         0047f3dc     MOV        dword ptr [ESI],0x1
    //         0047f3e2     PUSH       EAX
    //         0047f3e3     CALL       malloc                                           undefined malloc()
    //                              Res_file.cpp:460 (14)
    //         0047f3e8     MOV        ECX,dword ptr [ESP + param_3]
    //         0047f3ef     MOV        ESI,EAX
    //         0047f3f1     ADD        ESP,0x4
    //         0047f3f4     MOV        dword ptr [EDI],ECX
    //                              Res_file.cpp:462 (4)
    //         0047f3f6     TEST       ESI,ESI
    //         0047f3f8     JNZ        LAB_0047f417
    //                              Res_file.cpp:465 (19)
    //         0047f3fa     PUSH       0x30
    //         0047f3fc     PUSH       s_RESOURCE_ERROR                                 = "RESOURCE ERROR"
    //         0047f401     PUSH       s_Error:_Out_of_memory_in_res_read               = "Error: Out of memory in res_read_bin."
    //         0047f406     PUSH       EAX
    //         0047f407     CALL       dword ptr [->USER32.DLL::MessageBoxA]            = 0048b00c
    //                              Res_file.cpp:467 (2)
    //         0047f40d     XOR        EAX,EAX
    //                              Res_file.cpp:484 (8)
    //         0047f40f     POP        EDI
    //         0047f410     POP        ESI
    //         0047f411     POP        EBP
    //         0047f412     POP        EBX
    //         0047f413     ADD        ESP,0x64
    //         0047f416     RET
    //                               LAB_0047f417                                                 XREF[1]:     0047f3f8(j)  
    //                              Res_file.cpp:472 (20)
    //         0047f417     MOV        EDX,dword ptr [ESP + param_4]
    //         0047f41e     MOV        EAX,dword ptr [ESP + param_2]
    //         0047f422     PUSH       0x0
    //         0047f424     PUSH       EDX
    //         0047f425     PUSH       EAX
    //         0047f426     CALL       lseek                                            undefined lseek()
    //                              Res_file.cpp:473 (25)
    //         0047f42b     MOV        ECX,dword ptr [ESP + param_3]
    //         0047f432     MOV        EDX,dword ptr [ESP + param_2]
    //         0047f439     ADD        ESP,0xc
    //         0047f43c     PUSH       ECX
    //         0047f43d     PUSH       ESI
    //         0047f43e     PUSH       EDX
    //         0047f43f     CALL       read                                             undefined read()
    //                              Res_file.cpp:474 (14)
    //         0047f444     MOV        ECX,dword ptr [ESP + param_3]
    //         0047f44b     ADD        ESP,0xc
    //         0047f44e     CMP        EAX,ECX
    //         0047f450     JZ         LAB_0047f470
    //                              Res_file.cpp:477 (20)
    //         0047f452     PUSH       0x30
    //         0047f454     PUSH       s_RESOURCE_ERROR                                 = "RESOURCE ERROR"
    //         0047f459     PUSH       s_Error:_unable_to_read_resource                 = "Error: unable to read resource"
    //         0047f45e     PUSH       0x0
    //         0047f460     CALL       dword ptr [->USER32.DLL::MessageBoxA]            = 0048b00c
    //                               LAB_0047f466                                                 XREF[1]:     0047f372(j)  
    //                              Res_file.cpp:479 (2)
    //         0047f466     XOR        EAX,EAX
    //                              Res_file.cpp:484 (8)
    //         0047f468     POP        EDI
    //         0047f469     POP        ESI
    //         0047f46a     POP        EBP
    //         0047f46b     POP        EBX
    //         0047f46c     ADD        ESP,0x64
    //         0047f46f     RET
    //                               LAB_0047f470                                                 XREF[1]:     0047f450(j)  
    //                              Res_file.cpp:483 (2)
    //         0047f470     MOV        EAX,ESI
    //                              Res_file.cpp:484 (8)
    //         0047f472     POP        EDI
    //         0047f473     POP        ESI
    //         0047f474     POP        EBP
    //         0047f475     POP        EBX
    //         0047f476     ADD        ESP,0x64
    //         0047f479     RET
    //         0047f47a     ??         90h
    //         0047f47b     NOP
    //         0047f47c     NOP
    //         0047f47d     NOP
    //         0047f47e     NOP
    //         0047f47f     NOP
    //                              * int __cdecl RESFILE_Extract_to_File(unsigned long,unsigned long,char *,struct _iobuf * &)             *
    //                              int __cdecl RESFILE_Extract_to_File(ulong param_1, ulong param_2, ch
    //              int               EAX:4          <RETURN>
    //              ulong             Stack[0x4]:4   param_1                   XREF[1]:     0047f49c(R)  
    //              ulong             Stack[0x8]:4   param_2                   XREF[1]:     0047f480(R)  
    //              char *            Stack[0xc]:4   param_3
    //              _iobuf * *        Stack[0x10]:4  param_4                   XREF[1]:     0047f493(R)  
    //              char[260]         Stack[-0x108   temp_path                 XREF[1,1]:   0047f48a(*), 0047f4c4(*)  
    //              int               Stack[-0x10c   rDataSize                 XREF[1]:     0047f48e(*)  
    //              int               Stack[-0x110   rLoadType
    //                               ?RESFILE_Extract_to_File@@YAHKKPADAAPAU_iobuf@@@Z            XREF[1]:     Load:0046e111(c)  
    //                               RESFILE_Extract_to_File
    //                              Res_file.cpp:496 (58)
    //         0047f480     MOV        EDX,dword ptr [ESP + param_2]
    //         0047f484     SUB        ESP,0x10c
    //         0047f48a     LEA        EAX=>temp_path,[ESP + 0x4]
    //         0047f48e     LEA        ECX=>rDataSize,[ESP]
    //         0047f492     PUSH       EBX
    //         0047f493     MOV        EBX,dword ptr [ESP + param_4]
    //         0047f49a     PUSH       EBP
    //         0047f49b     PUSH       EAX
    //         0047f49c     MOV        EAX,dword ptr [ESP + param_1]
    //         0047f4a3     PUSH       ECX
    //         0047f4a4     PUSH       EDX
    //         0047f4a5     PUSH       EAX
    //         0047f4a6     MOV        dword ptr [EBX],0x0
    //         0047f4ac     CALL       RESFILE_load                                     uchar * RESFILE_load(ulong param_1, ulong par
    //         0047f4b1     MOV        EBP,EAX
    //         0047f4b3     ADD        ESP,0x10
    //         0047f4b6     TEST       EBP,EBP
    //         0047f4b8     JNZ        LAB_0047f4c3
    //                              Res_file.cpp:536 (9)
    //         0047f4ba     POP        EBP
    //         0047f4bb     POP        EBX
    //         0047f4bc     ADD        ESP,0x10c
    //         0047f4c2     RET
    //                               LAB_0047f4c3                                                 XREF[1]:     0047f4b8(j)  
    //                              Res_file.cpp:496 (1)
    //         0047f4c3     PUSH       EDI
    //                              Res_file.cpp:512 (21)
    //         0047f4c4     LEA        ECX=>temp_path[4],[ESP + 0x14]
    //         0047f4c8     PUSH       ESI
    //         0047f4c9     PUSH       ECX
    //         0047f4ca     PUSH       0x104
    //         0047f4cf     CALL       dword ptr [->KERNEL32.DLL::GetTempPathA]         = 0048ac50
    //         0047f4d5     TEST       EAX,EAX
    //         0047f4d7     JNZ        LAB_0047f4fd
    //                              Res_file.cpp:513 (36)
    //         0047f4d9     MOV        EDI,s_.                                          = 2Eh
    //         0047f4de     OR         ECX,0xffffffff
    //         0047f4e1     SCASB.RE   ES:EDI=>s_.                                      = 2Eh
    //         0047f4e3     NOT        ECX
    //         0047f4e5     SUB        EDI,ECX
    //         0047f4e7     LEA        EDX,[ESP + 0x18]
    //         0047f4eb     MOV        EAX,ECX
    //         0047f4ed     MOV        ESI,EDI
    //         0047f4ef     MOV        EDI,EDX
    //         0047f4f1     SHR        ECX,0x2
    //         0047f4f4     MOVSD.REP  ES:EDI,ESI
    //         0047f4f6     MOV        ECX,EAX
    //         0047f4f8     AND        ECX,0x3
    //         0047f4fb     MOVSB.REP  ES:EDI,ESI
    //                               LAB_0047f4fd                                                 XREF[1]:     0047f4d7(j)  
    //                              Res_file.cpp:517 (30)
    //         0047f4fd     MOV        ESI,dword ptr [ESP + 0x128]
    //         0047f504     LEA        ECX,[ESP + 0x18]
    //         0047f508     PUSH       ESI
    //         0047f509     PUSH       0x0=>DAT_fffffff8
    //         0047f50b     PUSH       s_temp                                           = "temp"
    //         0047f510     PUSH       ECX=>DAT_fffffff0
    //         0047f511     CALL       dword ptr [->KERNEL32.DLL::GetTempFileNameA]     = 0048ac3c
    //         0047f517     TEST       EAX,EAX
    //         0047f519     JZ         LAB_0047f553
    //                              Res_file.cpp:519 (16)
    //         0047f51b     PUSH       s_w+                                             = "w+"
    //         0047f520     PUSH       ESI=>DAT_fffffff8
    //         0047f521     CALL       fopen                                            undefined fopen()
    //         0047f526     ADD        ESP,0x8
    //         0047f529     MOV        dword ptr [EBX],EAX
    //                              Res_file.cpp:520 (4)
    //         0047f52b     TEST       EAX,EAX
    //         0047f52d     JZ         LAB_0047f553
    //                              Res_file.cpp:522 (8)
    //         0047f52f     MOV        ECX,dword ptr [ESP + 0x14]
    //         0047f533     TEST       ECX,ECX
    //         0047f535     JLE        LAB_0047f553
    //                              Res_file.cpp:524 (10)
    //         0047f537     PUSH       EAX
    //         0047f538     PUSH       offset DAT_fffffff8
    //         0047f53a     PUSH       ECX=>DAT_fffffff4
    //         0047f53b     PUSH       EBP=>DAT_fffffff0
    //         0047f53c     CALL       fwrite                                           undefined fwrite()
    //                              Res_file.cpp:525 (18)
    //         0047f541     MOV        EDX,dword ptr [EBX]
    //         0047f543     ADD        ESP,0x10
    //         0047f546     PUSH       0x0
    //         0047f548     PUSH       0x0=>DAT_fffffff8
    //         0047f54a     PUSH       EDX=>DAT_fffffff4
    //         0047f54b     CALL       fseek                                            undefined fseek()
    //         0047f550     ADD        ESP,0xc
    //                               LAB_0047f553                                                 XREF[3]:     0047f519(j), 0047f52d(j), 
    //                                                                                                         0047f535(j)  
    //                              Res_file.cpp:532 (16)
    //         0047f553     CMP        dword ptr [ESP + 0x10],0x1
    //         0047f558     JNZ        LAB_0047f563
    //         0047f55a     PUSH       EBP
    //         0047f55b     CALL       free                                             undefined free()
    //         0047f560     ADD        ESP,0x4
    //                               LAB_0047f563                                                 XREF[1]:     0047f558(j)  
    //                              Res_file.cpp:534 (8)
    //         0047f563     MOV        ECX,dword ptr [EBX]
    //         0047f565     XOR        EAX,EAX
    //         0047f567     POP        ESI
    //         0047f568     POP        EDI
    //         0047f569     TEST       ECX,ECX
    //                              Res_file.cpp:536 (12)
    //         0047f56b     POP        EBP
    //         0047f56c     POP        EBX
    //         0047f56d     SETNZ      AL
    //         0047f570     ADD        ESP,0x10c
    //         0047f576     RET
    //         0047f577     ??         90h
    //         0047f578     NOP
    //         0047f579     NOP
    //         0047f57a     NOP
    //         0047f57b     NOP
    //         0047f57c     NOP
    //         0047f57d     NOP
    //         0047f57e     NOP
    //         0047f57f     NOP
    //                              * void __cdecl RESFILE_Set_Missing_Flag(int)                                                            *
    //                              void __cdecl RESFILE_Set_Missing_Flag(int param_1)
    //              void              <VOID>         <RETURN>
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0047f580(R)  
    //                               ?RESFILE_Set_Missing_Flag@@YAXH@Z                            XREF[1]:     setup_cmd_options:0041de47(c)  
    //                               RESFILE_Set_Missing_Flag
    //                              Res_file.cpp:544 (9)
    //         0047f580     MOV        EAX,dword ptr [ESP + param_1]
    //         0047f584     MOV        [DAT_0086b258],EAX
    //                              Res_file.cpp:546 (1)
    //         0047f589     RET
    //         0047f58a     ??         90h
    //         0047f58b     NOP
    //         0047f58c     NOP
    //         0047f58d     NOP
    //         0047f58e     NOP
    //         0047f58f     NOP
    //                              * int __cdecl RESFILE_Decommit_Mapped_Memory(unsigned char *,int)                                       *
    //                              int __cdecl RESFILE_Decommit_Mapped_Memory(uchar * param_1, int para
    //              int               EAX:4          <RETURN>
    //              uchar *           Stack[0x4]:4   param_1                   XREF[1]:     0047f590(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0047f598(R)  
    //                               ?RESFILE_Decommit_Mapped_Memory@@YAHPAEH@Z                   XREF[2]:     ~TShape:004b8df9(c), 
    //                               RESFILE_Decommit_Mapped_Memory                                            ~TShape:004b8e22(c)  
    //                              Res_file.cpp:555 (16)
    //         0047f590     MOV        ECX,dword ptr [ESP + param_1]
    //         0047f594     TEST       ECX,ECX
    //         0047f596     JZ         LAB_0047f5ae
    //         0047f598     MOV        EAX,dword ptr [ESP + param_2]
    //         0047f59c     TEST       EAX,EAX
    //         0047f59e     JLE        LAB_0047f5ae
    //                              Res_file.cpp:559 (13)
    //         0047f5a0     PUSH       0x4000
    //         0047f5a5     PUSH       EAX
    //         0047f5a6     PUSH       ECX
    //         0047f5a7     CALL       dword ptr [->KERNEL32.DLL::VirtualFree]          = 0048ac60
    //                              Res_file.cpp:563 (1)
    //         0047f5ad     RET
    //                               LAB_0047f5ae                                                 XREF[2]:     0047f596(j), 0047f59e(j)  
    //                              Res_file.cpp:562 (2)
    //         0047f5ae     XOR        EAX,EAX
    //                              Res_file.cpp:563 (1)
    //         0047f5b0     RET
    //         0047f5b1     ??         90h
    //         0047f5b2     NOP
    //         0047f5b3     NOP
    //         0047f5b4     NOP
    //         0047f5b5     NOP
    //         0047f5b6     NOP
    //         0047f5b7     NOP
    //         0047f5b8     NOP
    //         0047f5b9     NOP
    //         0047f5ba     NOP
    //         0047f5bb     NOP
    //         0047f5bc     NOP
    //         0047f5bd     NOP
    //         0047f5be     NOP
    //         0047f5bf     NOP
    //                              * int __cdecl RESFILE_build_res_file(char *,char *,char *)                                              *
    //                              int __cdecl RESFILE_build_res_file(char * param_1, char * param_2, c
    //              int               EAX:4          <RETURN>
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     0047f5d1(R)  
    //              char *            Stack[0x8]:4   param_2                   XREF[2]:     0047f5c6(R), 0047f6b4(R)  
    //              char *            Stack[0xc]:4   param_3                   XREF[1]:     0047f651(R)  
    //              char[260]         Stack[-0x108   build_filename            XREF[0,2]:   0047f5da(*), 0047f5f9(*)  
    //              char[260]         Stack[-0x20c   resource_filename         XREF[0,3]:   0047f662(*), 0047f93a(*), 0047f95f(*)  
    //              char[260]         Stack[-0x310   temp_filename             XREF[0,6]:   0047f63d(*), 0047f65b(*), 0047f679(*), 0047f6bb(*), 
    //                                                                                     0047f6d9(*), 0047f8a5(*)  
    //              char[260]         Stack[-0x414   data_filename             XREF[0,7]:   0047f6c4(*), 0047f7a0(*), 0047f7d8(*), 0047f7f4(*), 
    //                                                                                     0047f8d8(*), 0047f909(*), 0047f922(*)  
    //              char[40]          Stack[-0x43c   rPassword                 XREF[1,2]:   0047fa74(W), 0047f639(*), 0047fa3e(*)  
    //              resfile_header    Stack[-0x47c   theHeader                 XREF[1,6]:   0047fab7(W), 0047f9de(*), 0047f9e2(*), 0047fa6a(*), 
    //                                                                                     0047fa1e(*), 0047fa4c(*), 0047fa6e(W)  
    //              resfile_type_d    Stack[-0x488   typeDirNode               XREF[1,3]:   0047fb02(W), 0047faa3(W), 0047faaa(*), 0047faae(W)  
    //              resfile_id_dir    Stack[-0x494   idDirNode                 XREF[3,3]:   0047f698(*), 0047f768(R), 0047f79c(R), 0047faee(W), 
    //                                                                                     0047faf5(*), 0047faf9(W)  
    //              ulong             Stack[-0x498   rId                       XREF[3]:     0047f5ed(W), 0047f755(RW), 0047f988(R)  
    //              int               Stack[-0x49c   numResTypes               XREF[6]:     0047f612(W), 0047f810(R), 0047f893(R), 0047f959(W), 
    //                                                                                     0047fb71(R), 0047fbdd(R)  
    //              _iobuf *          Stack[-0x4a0   buildFile                 XREF[9]:     0047f75c(W), 0047f778(W), 0047f81c(R), 0047f9f6(W), 
    //                                                                                     0047f9fe(R), 0047fa26(W), 0047fa2c(R), 0047fa54(W), 
    //                                                                                     0047fa5a(R)  
    //              BuildRes_id_no    Stack[-0x4a4   iq                        XREF[9]:     0047f5e9(W), 0047f6f3(R), 0047f746(W), 0047f98c(R), 
    //                                                                                     0047fa92(R), 0047fad6(R), 0047fb24(R), 0047fb55(R), 
    //                                                                                     0047fb96(R)  
    //              BuildRes_type_    Stack[-0x4a8   ID_List
    //                               ?RESFILE_build_res_file@@YAHPAD00@Z                          XREF[3]:     setup:00521822(c), 
    //                               RESFILE_build_res_file                                                    setup:0052183e(c), 
    //                                                                                                         setup:0052185a(c)  
    //                              Res_file.cpp:574 (6)
    //         0047f5c0     SUB        ESP,0x4a4
    //                              Res_file.cpp:604 (51)
    //         0047f5c6     MOV        EAX,dword ptr [ESP + param_2]
    //         0047f5cd     PUSH       EBX
    //         0047f5ce     PUSH       EBP
    //         0047f5cf     PUSH       ESI
    //         0047f5d0     PUSH       EDI
    //         0047f5d1     MOV        EDI,dword ptr [ESP + param_1]
    //         0047f5d8     PUSH       EDI
    //         0047f5d9     PUSH       EAX
    //         0047f5da     LEA        ECX=>build_filename[4],[ESP + 0x3b8]
    //         0047f5e1     XOR        EBX,EBX
    //         0047f5e3     PUSH       s_%s%s                                           = "%s%s"
    //         0047f5e8     PUSH       ECX
    //         0047f5e9     MOV        dword ptr [ESP + iq],EBX
    //         0047f5ed     MOV        dword ptr [ESP + rId],EBX
    //         0047f5f1     CALL       sprintf                                          undefined sprintf()
    //         0047f5f6     ADD        ESP,0x10
    //                              Res_file.cpp:606 (31)
    //         0047f5f9     LEA        EDX=>build_filename[4],[ESP + 0x3b0]
    //         0047f600     PUSH       s_r                                              = "r"
    //         0047f605     PUSH       EDX
    //         0047f606     CALL       fopen                                            undefined fopen()
    //         0047f60b     MOV        ESI,EAX
    //         0047f60d     ADD        ESP,0x8
    //         0047f610     CMP        ESI,EBX
    //         0047f612     MOV        dword ptr [ESP + numResTypes],ESI
    //         0047f616     JNZ        LAB_0047f639
    //                              Res_file.cpp:608 (20)
    //         0047f618     MOV        EAX,[L]                                          = 00000000
    //         0047f61d     PUSH       EDI
    //         0047f61e     PUSH       s_Error:_could_not_find_resource_b               = "Error: could not find resource build file:
    //         0047f623     PUSH       EAX
    //         0047f624     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         0047f629     ADD        ESP,0xc
    //                              Res_file.cpp:609 (2)
    //         0047f62c     XOR        EAX,EAX
    //                              Res_file.cpp:935 (11)
    //         0047f62e     POP        EDI
    //         0047f62f     POP        ESI
    //         0047f630     POP        EBP
    //         0047f631     POP        EBX
    //         0047f632     ADD        ESP,0x4a4
    //         0047f638     RET
    //                               LAB_0047f639                                                 XREF[1]:     0047f616(j)  
    //                              Res_file.cpp:614 (24)
    //         0047f639     LEA        ECX=>rPassword[4],[ESP + 0x7c]
    //         0047f63d     LEA        EDX=>temp_filename[4],[ESP + 0x1a8]
    //         0047f644     PUSH       ECX
    //         0047f645     PUSH       EDX
    //         0047f646     PUSH       s_%s_%s                                          = "%s %s"
    //         0047f64b     PUSH       ESI
    //         0047f64c     CALL       fscanf                                           undefined fscanf()
    //                              Res_file.cpp:615 (40)
    //         0047f651     MOV        ECX,dword ptr [ESP + param_3]
    //         0047f658     ADD        ESP,0x10
    //         0047f65b     LEA        EAX=>temp_filename[4],[ESP + 0x1a8]
    //         0047f662     LEA        EDX=>resource_filename[4],[ESP + 0x2ac]
    //         0047f669     PUSH       EAX
    //         0047f66a     PUSH       ECX
    //         0047f66b     PUSH       s_%s%s                                           = "%s%s"
    //         0047f670     PUSH       EDX
    //         0047f671     CALL       sprintf                                          undefined sprintf()
    //         0047f676     ADD        ESP,0x10
    //                               LAB_0047f679                                                 XREF[2]:     0047f817(j), 0047f89a(j)  
    //                              Res_file.cpp:623 (31)
    //         0047f679     LEA        EAX=>temp_filename[4],[ESP + 0x1a8]
    //         0047f680     PUSH       EAX
    //         0047f681     PUSH       s_%s                                             = "%s"
    //         0047f686     PUSH       ESI
    //         0047f687     CALL       fscanf                                           undefined fscanf()
    //         0047f68c     ADD        ESP,0xc
    //         0047f68f     CMP        EAX,-0x1
    //         0047f692     JZ         LAB_0047f931
    //                              Res_file.cpp:624 (28)
    //         0047f698     LEA        ECX=>idDirNode,[ESP + 0x20]
    //         0047f69c     PUSH       ECX
    //         0047f69d     PUSH       s_%d                                             = 6425h
    //         0047f6a2     PUSH       ESI
    //         0047f6a3     CALL       fscanf                                           undefined fscanf()
    //         0047f6a8     ADD        ESP,0xc
    //         0047f6ab     CMP        EAX,-0x1
    //         0047f6ae     JZ         LAB_0047f931
    //                              Res_file.cpp:628 (37)
    //         0047f6b4     MOV        EAX,dword ptr [ESP + param_2]
    //         0047f6bb     LEA        EDX=>temp_filename[4],[ESP + 0x1a8]
    //         0047f6c2     PUSH       EDX
    //         0047f6c3     PUSH       EAX
    //         0047f6c4     LEA        ECX=>data_filename[4],[ESP + 0xac]
    //         0047f6cb     PUSH       s_%s%s                                           = "%s%s"
    //         0047f6d0     PUSH       ECX
    //         0047f6d1     CALL       sprintf                                          undefined sprintf()
    //         0047f6d6     ADD        ESP,0x10
    //                              Res_file.cpp:629 (26)
    //         0047f6d9     LEA        EDX=>temp_filename[4],[ESP + 0x1a8]
    //         0047f6e0     PUSH       EDX
    //         0047f6e1     CALL       BUILDRES_get_files_resource_type                 ulong BUILDRES_get_files_resource_type(char *
    //         0047f6e6     MOV        ESI,EAX
    //         0047f6e8     ADD        ESP,0x4
    //         0047f6eb     TEST       ESI,ESI
    //         0047f6ed     JZ         LAB_0047f89f
    //                              Res_file.cpp:637 (14)
    //         0047f6f3     MOV        EBX,dword ptr [ESP + iq]
    //         0047f6f7     XOR        EDI,EDI
    //         0047f6f9     XOR        EBP,EBP
    //         0047f6fb     MOV        EAX,EBX
    //         0047f6fd     TEST       EBX,EBX
    //         0047f6ff     JZ         LAB_0047f716
    //                               LAB_0047f701                                                 XREF[1]:     0047f710(j)  
    //                              Res_file.cpp:639 (6)
    //         0047f701     MOV        ECX,dword ptr [EAX]
    //         0047f703     CMP        ECX,ESI
    //         0047f705     JZ         LAB_0047f714
    //                              Res_file.cpp:644 (4)
    //         0047f707     JNC        LAB_0047f70b
    //         0047f709     MOV        EDI,EAX
    //                               LAB_0047f70b                                                 XREF[1]:     0047f707(j)  
    //                              Res_file.cpp:637 (9)
    //         0047f70b     MOV        EAX,dword ptr [EAX + 0x10]
    //         0047f70e     TEST       EAX,EAX
    //         0047f710     JNZ        LAB_0047f701
    //         0047f712     JMP        LAB_0047f716
    //                               LAB_0047f714                                                 XREF[1]:     0047f705(j)  
    //                              Res_file.cpp:641 (2)
    //         0047f714     MOV        EBP,EAX
    //                               LAB_0047f716                                                 XREF[2]:     0047f6ff(j), 0047f712(j)  
    //                              Res_file.cpp:649 (4)
    //         0047f716     TEST       EBP,EBP
    //         0047f718     JNZ        LAB_0047f759
    //                              Res_file.cpp:651 (9)
    //         0047f71a     PUSH       0x14
    //         0047f71c     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0047f721     MOV        EBP,EAX
    //                              Res_file.cpp:652 (13)
    //         0047f723     XOR        EAX,EAX
    //         0047f725     ADD        ESP,0x4
    //         0047f728     CMP        EBP,EAX
    //         0047f72a     JZ         LAB_0047f8c8
    //                              Res_file.cpp:668 (19)
    //         0047f730     CMP        EDI,EAX
    //         0047f732     MOV        dword ptr [EBP],ESI
    //         0047f735     MOV        dword ptr [EBP + 0x4],EAX
    //         0047f738     MOV        dword ptr [EBP + 0x8],EAX
    //         0047f73b     MOV        dword ptr [EBP + 0xc],EAX
    //         0047f73e     MOV        dword ptr [EBP + 0x10],EAX
    //         0047f741     JNZ        LAB_0047f74c
    //                              Res_file.cpp:670 (3)
    //         0047f743     MOV        dword ptr [EBP + 0x10],EBX
    //                              Res_file.cpp:671 (4)
    //         0047f746     MOV        dword ptr [ESP + iq],EBP
    //                              Res_file.cpp:673 (2)
    //         0047f74a     JMP        LAB_0047f755
    //                               LAB_0047f74c                                                 XREF[1]:     0047f741(j)  
    //                              Res_file.cpp:675 (6)
    //         0047f74c     MOV        EAX,dword ptr [EDI + 0x10]
    //         0047f74f     MOV        dword ptr [EBP + 0x10],EAX
    //                              Res_file.cpp:676 (3)
    //         0047f752     MOV        dword ptr [EDI + 0x10],EBP
    //                               LAB_0047f755                                                 XREF[1]:     0047f74a(j)  
    //                              Res_file.cpp:679 (4)
    //         0047f755     INC        dword ptr [ESP + rId]
    //                               LAB_0047f759                                                 XREF[1]:     0047f718(j)  
    //                              Res_file.cpp:684 (19)
    //         0047f759     MOV        EAX,dword ptr [EBP + 0xc]
    //         0047f75c     MOV        dword ptr [ESP + buildFile],0x0
    //         0047f764     TEST       EAX,EAX
    //         0047f766     JZ         LAB_0047f783
    //         0047f768     MOV        EDX,dword ptr [ESP + idDirNode.id]
    //                               LAB_0047f76c                                                 XREF[1]:     0047f781(j)  
    //                              Res_file.cpp:686 (10)
    //         0047f76c     MOV        ECX,dword ptr [EAX]
    //         0047f76e     CMP        ECX,EDX
    //         0047f770     JZ         LAB_0047f8d2
    //                              Res_file.cpp:692 (6)
    //         0047f776     JNC        LAB_0047f77c
    //         0047f778     MOV        dword ptr [ESP + buildFile],EAX
    //                               LAB_0047f77c                                                 XREF[1]:     0047f776(j)  
    //                              Res_file.cpp:684 (7)
    //         0047f77c     MOV        EAX,dword ptr [EAX + 0x10]
    //         0047f77f     TEST       EAX,EAX
    //         0047f781     JNZ        LAB_0047f76c
    //                               LAB_0047f783                                                 XREF[1]:     0047f766(j)  
    //                              Res_file.cpp:697 (12)
    //         0047f783     PUSH       0x118
    //         0047f788     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0047f78d     MOV        EBX,EAX
    //                              Res_file.cpp:698 (13)
    //         0047f78f     XOR        EAX,EAX
    //         0047f791     ADD        ESP,0x4
    //         0047f794     CMP        EBX,EAX
    //         0047f796     JZ         LAB_0047f8ff
    //                              Res_file.cpp:706 (4)
    //         0047f79c     MOV        ECX,dword ptr [ESP + idDirNode.id]
    //                              Res_file.cpp:711 (39)
    //         0047f7a0     LEA        EDI=>data_filename[4],[ESP + 0xa4]
    //         0047f7a7     MOV        dword ptr [EBX],ECX
    //         0047f7a9     OR         ECX,0xffffffff
    //         0047f7ac     MOV        dword ptr [EBX + 0x4],EAX
    //         0047f7af     MOV        dword ptr [EBX + 0x8],EAX
    //         0047f7b2     MOV        dword ptr [EBX + 0xc],EAX
    //         0047f7b5     MOV        dword ptr [EBX + 0x10],EAX
    //         0047f7b8     SCASB.RE   ES:EDI
    //         0047f7ba     NOT        ECX
    //         0047f7bc     SUB        EDI,ECX
    //         0047f7be     LEA        EDX,[EBX + 0x14]
    //         0047f7c1     MOV        EAX,ECX
    //         0047f7c3     MOV        ESI,EDI
    //         0047f7c5     MOV        EDI,EDX
    //                              Res_file.cpp:715 (40)
    //         0047f7c7     PUSH       0x8000
    //         0047f7cc     SHR        ECX,0x2
    //         0047f7cf     MOVSD.REP  ES:EDI,ESI
    //         0047f7d1     MOV        ECX,EAX
    //         0047f7d3     AND        ECX,0x3
    //         0047f7d6     MOVSB.REP  ES:EDI,ESI
    //         0047f7d8     LEA        ECX=>data_filename[4],[ESP + 0xa8]
    //         0047f7df     PUSH       ECX
    //         0047f7e0     CALL       __open                                           undefined __open()
    //         0047f7e5     MOV        EDI,EAX
    //         0047f7e7     ADD        ESP,0x8
    //         0047f7ea     CMP        EDI,-0x1
    //         0047f7ed     JNZ        LAB_0047f81c
    //                              Res_file.cpp:717 (27)
    //         0047f7ef     MOV        EAX,[L]                                          = 00000000
    //         0047f7f4     LEA        EDX=>data_filename[4],[ESP + 0xa4]
    //         0047f7fb     PUSH       EDX
    //         0047f7fc     PUSH       s_Error:_unable_to_open_file:_%s                 = "Error: unable to open file: %s"
    //         0047f801     PUSH       EAX
    //         0047f802     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         0047f807     ADD        ESP,0xc
    //                              Res_file.cpp:722 (6)
    //         0047f80a     PUSH       EBX
    //         0047f80b     CALL       operator_delete                                  void operator_delete(void * param_1)
    //                              Res_file.cpp:726 (12)
    //         0047f810     MOV        ESI,dword ptr [ESP + numResTypes]
    //         0047f814     ADD        ESP,0x4
    //         0047f817     JMP        LAB_0047f679
    //                               LAB_0047f81c                                                 XREF[1]:     0047f7ed(j)  
    //                              Res_file.cpp:730 (8)
    //         0047f81c     MOV        EAX,dword ptr [ESP + buildFile]
    //         0047f820     TEST       EAX,EAX
    //         0047f822     JNZ        LAB_0047f82f
    //                              Res_file.cpp:732 (6)
    //         0047f824     MOV        ECX,dword ptr [EBP + 0xc]
    //         0047f827     MOV        dword ptr [EBX + 0x10],ECX
    //                              Res_file.cpp:733 (3)
    //         0047f82a     MOV        dword ptr [EBP + 0xc],EBX
    //                              Res_file.cpp:735 (2)
    //         0047f82d     JMP        LAB_0047f838
    //                               LAB_0047f82f                                                 XREF[1]:     0047f822(j)  
    //                              Res_file.cpp:737 (6)
    //         0047f82f     MOV        EDX,dword ptr [EAX + 0x10]
    //         0047f832     MOV        dword ptr [EBX + 0x10],EDX
    //                              Res_file.cpp:738 (3)
    //         0047f835     MOV        dword ptr [EAX + 0x10],EBX
    //                               LAB_0047f838                                                 XREF[1]:     0047f82d(j)  
    //                              Res_file.cpp:741 (3)
    //         0047f838     MOV        EAX,dword ptr [EBP + 0x8]
    //                              Res_file.cpp:745 (19)
    //         0047f83b     PUSH       0x2
    //         0047f83d     INC        EAX
    //         0047f83e     PUSH       0x0
    //         0047f840     PUSH       EDI
    //         0047f841     MOV        dword ptr [EBP + 0x8],EAX
    //         0047f844     CALL       lseek                                            undefined lseek()
    //         0047f849     ADD        ESP,0xc
    //         0047f84c     MOV        ESI,EAX
    //                              Res_file.cpp:746 (13)
    //         0047f84e     PUSH       0x0
    //         0047f850     PUSH       0x0
    //         0047f852     PUSH       EDI
    //         0047f853     CALL       lseek                                            undefined lseek()
    //         0047f858     ADD        ESP,0xc
    //                              Res_file.cpp:748 (8)
    //         0047f85b     TEST       ESI,ESI
    //         0047f85d     JLE        LAB_0047f909
    //                              Res_file.cpp:756 (12)
    //         0047f863     PUSH       ESI
    //         0047f864     CALL       malloc                                           undefined malloc()
    //         0047f869     ADD        ESP,0x4
    //         0047f86c     MOV        dword ptr [EBX + 0x8],EAX
    //                              Res_file.cpp:757 (8)
    //         0047f86f     TEST       EAX,EAX
    //         0047f871     JZ         LAB_0047f918
    //                              Res_file.cpp:765 (22)
    //         0047f877     PUSH       ESI
    //         0047f878     PUSH       EAX
    //         0047f879     PUSH       EDI
    //         0047f87a     MOV        dword ptr [EBX + 0xc],ESI
    //         0047f87d     CALL       read                                             undefined read()
    //         0047f882     ADD        ESP,0xc
    //         0047f885     CMP        EAX,ESI
    //         0047f887     JNZ        LAB_0047f922
    //                              Res_file.cpp:773 (18)
    //         0047f88d     PUSH       EDI
    //         0047f88e     CALL       close                                            undefined close()
    //         0047f893     MOV        ESI,dword ptr [ESP + numResTypes]
    //         0047f897     ADD        ESP,0x4
    //         0047f89a     JMP        LAB_0047f679
    //                               LAB_0047f89f                                                 XREF[1]:     0047f6ed(j)  
    //                              Res_file.cpp:631 (28)
    //         0047f89f     MOV        ECX,dword ptr [L]                                = 00000000
    //         0047f8a5     LEA        EAX=>temp_filename[4],[ESP + 0x1a8]
    //         0047f8ac     PUSH       EAX
    //         0047f8ad     PUSH       s_Error:_could_not_determine_file_               = "Error: could not determine file type of: %s"
    //         0047f8b2     PUSH       ECX
    //         0047f8b3     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         0047f8b8     ADD        ESP,0xc
    //                              Res_file.cpp:632 (2)
    //         0047f8bb     XOR        EAX,EAX
    //                              Res_file.cpp:935 (11)
    //         0047f8bd     POP        EDI
    //         0047f8be     POP        ESI
    //         0047f8bf     POP        EBP
    //         0047f8c0     POP        EBX
    //         0047f8c1     ADD        ESP,0x4a4
    //         0047f8c7     RET
    //                               LAB_0047f8c8                                                 XREF[1]:     0047f72a(j)  
    //                              Res_file.cpp:654 (5)
    //         0047f8c8     PUSH       s_Error:_out_of_memory_#1                        = "Error: out of memory #1"
    //                              Res_file.cpp:655 (5)
    //         0047f8cd     JMP        LAB_0047fba1
    //                               LAB_0047f8d2                                                 XREF[1]:     0047f770(j)  
    //                              Res_file.cpp:688 (32)
    //         0047f8d2     MOV        EDX,dword ptr [L]                                = 00000000
    //         0047f8d8     LEA        ECX=>data_filename[4],[ESP + 0xa4]
    //         0047f8df     ADD        EAX,0x14
    //         0047f8e2     PUSH       ECX
    //         0047f8e3     PUSH       EAX
    //         0047f8e4     PUSH       s_Error:_duplicate_resources:_%s_&               = "Error: duplicate resources: %s & %s"
    //         0047f8e9     PUSH       EDX
    //         0047f8ea     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         0047f8ef     ADD        ESP,0x10
    //                              Res_file.cpp:689 (2)
    //         0047f8f2     XOR        EAX,EAX
    //                              Res_file.cpp:935 (11)
    //         0047f8f4     POP        EDI
    //         0047f8f5     POP        ESI
    //         0047f8f6     POP        EBP
    //         0047f8f7     POP        EBX
    //         0047f8f8     ADD        ESP,0x4a4
    //         0047f8fe     RET
    //                               LAB_0047f8ff                                                 XREF[1]:     0047f796(j)  
    //                              Res_file.cpp:700 (5)
    //         0047f8ff     PUSH       s_Error:_out_of_memory_#2                        = "Error: out of memory #2"
    //                              Res_file.cpp:701 (5)
    //         0047f904     JMP        LAB_0047fbc2
    //                               LAB_0047f909                                                 XREF[1]:     0047f85d(j)  
    //                              Res_file.cpp:750 (13)
    //         0047f909     LEA        ECX=>data_filename[4],[ESP + 0xa4]
    //         0047f910     PUSH       ECX
    //         0047f911     PUSH       s_Error:_file_is_empty/NULL:_%s                  = "Error: file is empty/NULL: %s"
    //                              Res_file.cpp:751 (2)
    //         0047f916     JMP        LAB_0047f96c
    //                               LAB_0047f918                                                 XREF[1]:     0047f871(j)  
    //                              Res_file.cpp:759 (5)
    //         0047f918     PUSH       s_Error:_out_of_memory_#3                        = "Error: out of memory #3"
    //                              Res_file.cpp:760 (5)
    //         0047f91d     JMP        LAB_0047fbc2
    //                               LAB_0047f922                                                 XREF[1]:     0047f887(j)  
    //                              Res_file.cpp:767 (13)
    //         0047f922     LEA        ECX=>data_filename[4],[ESP + 0xa4]
    //         0047f929     PUSH       ECX
    //         0047f92a     PUSH       s_Error:_error_reading_file:_%s                  = "Error: error reading file: %s"
    //                              Res_file.cpp:768 (2)
    //         0047f92f     JMP        LAB_0047f96c
    //                               LAB_0047f931                                                 XREF[2]:     0047f692(j), 0047f6ae(j)  
    //                              Res_file.cpp:779 (9)
    //         0047f931     PUSH       ESI
    //         0047f932     CALL       fclose                                           undefined fclose()
    //         0047f937     ADD        ESP,0x4
    //                              Res_file.cpp:787 (28)
    //         0047f93a     LEA        EAX=>resource_filename[4],[ESP + 0x2ac]
    //         0047f941     PUSH       0x180
    //         0047f946     PUSH       0x8301
    //         0047f94b     PUSH       EAX
    //         0047f94c     CALL       __open                                           undefined __open()
    //         0047f951     MOV        EBX,EAX
    //         0047f953     ADD        ESP,0xc
    //                              Res_file.cpp:788 (9)
    //         0047f956     CMP        EBX,-0x1
    //         0047f959     MOV        dword ptr [ESP + numResTypes],EBX
    //         0047f95d     JNZ        LAB_0047f988
    //                              Res_file.cpp:790 (28)
    //         0047f95f     LEA        ECX=>resource_filename[4],[ESP + 0x2ac]
    //         0047f966     PUSH       ECX
    //         0047f967     PUSH       s_Error:_unable_to_create_resource               = "Error: unable to create resource file file
    //                               LAB_0047f96c                                                 XREF[2]:     0047f916(j), 0047f92f(j)  
    //         0047f96c     MOV        EDX,dword ptr [L]                                = 00000000
    //         0047f972     PUSH       EDX
    //         0047f973     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         0047f978     ADD        ESP,0xc
    //                              Res_file.cpp:791 (2)
    //         0047f97b     XOR        EAX,EAX
    //                              Res_file.cpp:935 (11)
    //         0047f97d     POP        EDI
    //         0047f97e     POP        ESI
    //         0047f97f     POP        EBP
    //         0047f980     POP        EBX
    //         0047f981     ADD        ESP,0x4a4
    //         0047f987     RET
    //                               LAB_0047f988                                                 XREF[1]:     0047f95d(j)  
    //                              Res_file.cpp:796 (4)
    //         0047f988     MOV        EBP,dword ptr [ESP + rId]
    //                              Res_file.cpp:800 (21)
    //         0047f98c     MOV        ESI,dword ptr [ESP + iq]
    //         0047f990     TEST       ESI,ESI
    //         0047f992     LEA        EAX,[EBP + EBP*0x2]
    //         0047f996     LEA        EDX,[EAX*0x4 + 0x40]
    //         0047f99d     MOV        EAX,ESI
    //         0047f99f     JZ         LAB_0047f9b4
    //                               LAB_0047f9a1                                                 XREF[1]:     0047f9b2(j)  
    //                              Res_file.cpp:803 (19)
    //         0047f9a1     MOV        ECX,dword ptr [EAX + 0x8]
    //         0047f9a4     MOV        dword ptr [EAX + 0x4],EDX
    //         0047f9a7     MOV        EAX,dword ptr [EAX + 0x10]
    //         0047f9aa     LEA        ECX,[ECX + ECX*0x2]
    //         0047f9ad     TEST       EAX,EAX
    //         0047f9af     LEA        EDX,[EDX + ECX*0x4]
    //         0047f9b2     JNZ        LAB_0047f9a1
    //                               LAB_0047f9b4                                                 XREF[1]:     0047f99f(j)  
    //                              Res_file.cpp:810 (6)
    //         0047f9b4     TEST       ESI,ESI
    //         0047f9b6     MOV        ECX,EDX
    //         0047f9b8     JZ         LAB_0047f9d7
    //                               LAB_0047f9ba                                                 XREF[1]:     0047f9d5(j)  
    //                              Res_file.cpp:812 (7)
    //         0047f9ba     MOV        EAX,dword ptr [ESI + 0xc]
    //         0047f9bd     TEST       EAX,EAX
    //         0047f9bf     JZ         LAB_0047f9d0
    //                               LAB_0047f9c1                                                 XREF[1]:     0047f9ce(j)  
    //                              Res_file.cpp:815 (15)
    //         0047f9c1     MOV        EDI,dword ptr [EAX + 0xc]
    //         0047f9c4     MOV        dword ptr [EAX + 0x4],ECX
    //         0047f9c7     MOV        EAX,dword ptr [EAX + 0x10]
    //         0047f9ca     ADD        ECX,EDI
    //         0047f9cc     TEST       EAX,EAX
    //         0047f9ce     JNZ        LAB_0047f9c1
    //                               LAB_0047f9d0                                                 XREF[1]:     0047f9bf(j)  
    //                              Res_file.cpp:810 (7)
    //         0047f9d0     MOV        ESI,dword ptr [ESI + 0x10]
    //         0047f9d3     TEST       ESI,ESI
    //         0047f9d5     JNZ        LAB_0047f9ba
    //                               LAB_0047f9d7                                                 XREF[1]:     0047f9b8(j)  
    //                              Res_file.cpp:821 (11)
    //         0047f9d7     MOV        ECX,0x10
    //         0047f9dc     XOR        EAX,EAX
    //         0047f9de     LEA        EDI=>theHeader+0x4,[ESP + 0x3c]
    //                              Res_file.cpp:823 (32)
    //         0047f9e2     LEA        ESI=>theHeader+0x4,[ESP + 0x3c]
    //         0047f9e6     STOSD.REP  ES:EDI
    //         0047f9e8     MOV        EDI,header_message                               = 79706f43
    //         0047f9ed     OR         ECX,0xffffffff
    //         0047f9f0     SCASB.RE   ES:EDI=>header_message                           = 79706f43
    //         0047f9f2     NOT        ECX
    //         0047f9f4     SUB        EDI,ECX
    //         0047f9f6     MOV        dword ptr [ESP + buildFile],ESI
    //         0047f9fa     MOV        EAX,ECX
    //         0047f9fc     MOV        ESI,EDI
    //         0047f9fe     MOV        EDI,dword ptr [ESP + buildFile]
    //                              Res_file.cpp:830 (134)
    //         0047fa02     PUSH       0x40
    //         0047fa04     SHR        ECX,0x2
    //         0047fa07     MOVSD.REP  ES:EDI,ESI=>header_message                       = 79706f43
    //         0047fa09     MOV        ECX,EAX
    //         0047fa0b     XOR        EAX,EAX
    //         0047fa0d     AND        ECX,0x3
    //         0047fa10     MOVSB.REP  ES:EDI,ESI=>header_message                       = 79706f43
    //         0047fa12     MOV        EDI,s_1.00                                       = "1.00"
    //         0047fa17     OR         ECX,0xffffffff
    //         0047fa1a     SCASB.RE   ES:EDI=>s_1.00                                   = "1.00"
    //                                                                                  = ".00"
    //         0047fa1c     NOT        ECX
    //         0047fa1e     LEA        ESI=>theHeader.password,[ESP + 0x68]
    //         0047fa22     SUB        EDI,ECX
    //         0047fa24     MOV        EAX,ECX
    //         0047fa26     MOV        dword ptr [ESP + buildFile],ESI
    //         0047fa2a     MOV        ESI,EDI
    //         0047fa2c     MOV        EDI,dword ptr [ESP + buildFile]
    //         0047fa30     SHR        ECX,0x2
    //         0047fa33     MOVSD.REP  ES:EDI,ESI=>s_1.00                               = "1.00"
    //         0047fa35     MOV        ECX,EAX
    //         0047fa37     XOR        EAX,EAX
    //         0047fa39     AND        ECX,0x3
    //         0047fa3c     MOVSB.REP  ES:EDI,ESI=>s_1.00                               = "1.00"
    //         0047fa3e     LEA        EDI=>rPassword[4],[ESP + 0x80]
    //         0047fa45     OR         ECX,0xffffffff
    //         0047fa48     SCASB.RE   ES:EDI
    //         0047fa4a     NOT        ECX
    //         0047fa4c     LEA        ESI=>theHeader+0x30,[ESP + 0x6c]
    //         0047fa50     SUB        EDI,ECX
    //         0047fa52     MOV        EAX,ECX
    //         0047fa54     MOV        dword ptr [ESP + buildFile],ESI
    //         0047fa58     MOV        ESI,EDI
    //         0047fa5a     MOV        EDI,dword ptr [ESP + buildFile]
    //         0047fa5e     SHR        ECX,0x2
    //         0047fa61     MOVSD.REP  ES:EDI,ESI
    //         0047fa63     MOV        ECX,EAX
    //         0047fa65     AND        ECX,0x3
    //         0047fa68     MOVSB.REP  ES:EDI,ESI
    //         0047fa6a     LEA        ECX=>theHeader+0x4,[ESP + 0x40]
    //         0047fa6e     MOV        dword ptr [ESP + theHeader.directory_size],EBP
    //         0047fa72     PUSH       ECX
    //         0047fa73     PUSH       EBX
    //         0047fa74     MOV        dword ptr [ESP + rPassword[0]],EDX
    //         0047fa7b     CALL       write                                            undefined write()
    //         0047fa80     ADD        ESP,0xc
    //         0047fa83     CMP        EAX,0x40
    //         0047fa86     JZ         LAB_0047fa92
    //                              Res_file.cpp:832 (5)
    //         0047fa88     PUSH       s_Error_writing_resource_file_head               = "Error writing resource file header"
    //                              Res_file.cpp:833 (5)
    //         0047fa8d     JMP        LAB_0047fba1
    //                               LAB_0047fa92                                                 XREF[1]:     0047fa86(j)  
    //                              Res_file.cpp:840 (13)
    //         0047fa92     MOV        ESI,dword ptr [ESP + iq]
    //         0047fa96     MOV        EBP,0x40
    //         0047fa9b     TEST       ESI,ESI
    //         0047fa9d     JZ         LAB_0047fad6
    //                               LAB_0047fa9f                                                 XREF[1]:     0047fad4(j)  
    //                              Res_file.cpp:842 (2)
    //         0047fa9f     MOV        EAX,dword ptr [ESI]
    //                              Res_file.cpp:846 (46)
    //         0047faa1     PUSH       0xc
    //         0047faa3     MOV        dword ptr [ESP + typeDirNode.dirOffset],EAX
    //         0047faa7     MOV        ECX,dword ptr [ESI + 0x4]
    //         0047faaa     LEA        EAX=>typeDirNode.dirOffset,[ESP + 0x34]
    //         0047faae     MOV        dword ptr [ESP + typeDirNode.numID],ECX
    //         0047fab2     MOV        EDX,dword ptr [ESI + 0x8]
    //         0047fab5     PUSH       EAX
    //         0047fab6     PUSH       EBX
    //         0047fab7     MOV        dword ptr [ESP + theHeader.banner_msg[0]],EDX
    //         0047fabb     CALL       write                                            undefined write()
    //         0047fac0     ADD        ESP,0xc
    //         0047fac3     CMP        EAX,0xc
    //         0047fac6     JNZ        LAB_0047fc3b
    //         0047facc     MOV        ESI,dword ptr [ESI + 0x10]
    //                              Res_file.cpp:852 (7)
    //         0047facf     ADD        EBP,0xc
    //         0047fad2     TEST       ESI,ESI
    //         0047fad4     JNZ        LAB_0047fa9f
    //                               LAB_0047fad6                                                 XREF[1]:     0047fa9d(j)  
    //                              Res_file.cpp:858 (8)
    //         0047fad6     MOV        EDI,dword ptr [ESP + iq]
    //         0047fada     TEST       EDI,EDI
    //         0047fadc     JZ         LAB_0047fb55
    //                               LAB_0047fade                                                 XREF[1]:     0047fb22(j)  
    //                              Res_file.cpp:860 (5)
    //         0047fade     CMP        EBP,dword ptr [EDI + 0x4]
    //         0047fae1     JNZ        LAB_0047fb2a
    //                              Res_file.cpp:866 (7)
    //         0047fae3     MOV        ESI,dword ptr [EDI + 0xc]
    //         0047fae6     TEST       ESI,ESI
    //         0047fae8     JZ         LAB_0047fb1d
    //                               LAB_0047faea                                                 XREF[1]:     0047fb1b(j)  
    //                              Res_file.cpp:868 (2)
    //         0047faea     MOV        EDX,dword ptr [ESI]
    //                              Res_file.cpp:872 (42)
    //         0047faec     PUSH       0xc
    //         0047faee     MOV        dword ptr [ESP + idDirNode.itemOffset],EDX
    //         0047faf2     MOV        EAX,dword ptr [ESI + 0x4]
    //         0047faf5     LEA        EDX=>idDirNode.itemOffset,[ESP + 0x28]
    //         0047faf9     MOV        dword ptr [ESP + idDirNode.itemSize],EAX
    //         0047fafd     MOV        ECX,dword ptr [ESI + 0xc]
    //         0047fb00     PUSH       EDX
    //         0047fb01     PUSH       EBX
    //         0047fb02     MOV        dword ptr [ESP + typeDirNode.type],ECX
    //         0047fb06     CALL       write                                            undefined write()
    //         0047fb0b     ADD        ESP,0xc
    //         0047fb0e     CMP        EAX,0xc
    //         0047fb11     JNZ        LAB_0047fb34
    //         0047fb13     MOV        ESI,dword ptr [ESI + 0x10]
    //                              Res_file.cpp:878 (7)
    //         0047fb16     ADD        EBP,0xc
    //         0047fb19     TEST       ESI,ESI
    //         0047fb1b     JNZ        LAB_0047faea
    //                               LAB_0047fb1d                                                 XREF[1]:     0047fae8(j)  
    //                              Res_file.cpp:858 (13)
    //         0047fb1d     MOV        EDI,dword ptr [EDI + 0x10]
    //         0047fb20     TEST       EDI,EDI
    //         0047fb22     JNZ        LAB_0047fade
    //         0047fb24     MOV        EDI,dword ptr [ESP + iq]
    //         0047fb28     JMP        LAB_0047fb55
    //                               LAB_0047fb2a                                                 XREF[1]:     0047fae1(j)  
    //                              Res_file.cpp:862 (5)
    //         0047fb2a     PUSH       s_Error_writing_resource_file:_pos               = "Error writing resource file: pos out of sy
    //                              Res_file.cpp:863 (5)
    //         0047fb2f     JMP        LAB_0047fbc2
    //                               LAB_0047fb34                                                 XREF[1]:     0047fb11(j)  
    //                              Res_file.cpp:874 (20)
    //         0047fb34     PUSH       s_Error_writing_resource_file_head               = "Error writing resource file header: id node"
    //                               LAB_0047fb39                                                 XREF[1]:     0047fc40(j)  
    //         0047fb39     MOV        ECX,dword ptr [L]                                = 00000000
    //         0047fb3f     PUSH       ECX
    //         0047fb40     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         0047fb45     ADD        ESP,0x8
    //                              Res_file.cpp:875 (2)
    //         0047fb48     XOR        EAX,EAX
    //                              Res_file.cpp:935 (11)
    //         0047fb4a     POP        EDI
    //         0047fb4b     POP        ESI
    //         0047fb4c     POP        EBP
    //         0047fb4d     POP        EBX
    //         0047fb4e     ADD        ESP,0x4a4
    //         0047fb54     RET
    //                               LAB_0047fb55                                                 XREF[2]:     0047fadc(j), 0047fb28(j)  
    //                              Res_file.cpp:884 (10)
    //         0047fb55     MOV        ESI,dword ptr [ESP + iq]
    //         0047fb59     MOV        EBX,EDI
    //         0047fb5b     TEST       ESI,ESI
    //         0047fb5d     JZ         LAB_0047fbdd
    //                               LAB_0047fb5f                                                 XREF[1]:     0047fb94(j)  
    //                              Res_file.cpp:886 (7)
    //         0047fb5f     MOV        ESI,dword ptr [EBX + 0xc]
    //         0047fb62     TEST       ESI,ESI
    //         0047fb64     JZ         LAB_0047fb8f
    //                               LAB_0047fb66                                                 XREF[1]:     0047fb8d(j)  
    //                              Res_file.cpp:888 (5)
    //         0047fb66     CMP        EBP,dword ptr [ESI + 0x4]
    //         0047fb69     JNZ        LAB_0047fb9c
    //                              Res_file.cpp:893 (30)
    //         0047fb6b     MOV        EDI,dword ptr [ESI + 0xc]
    //         0047fb6e     MOV        EAX,dword ptr [ESI + 0x8]
    //         0047fb71     MOV        ECX,dword ptr [ESP + numResTypes]
    //         0047fb75     MOV        EDX,EDI
    //         0047fb77     PUSH       EDX
    //         0047fb78     PUSH       EAX
    //         0047fb79     PUSH       ECX
    //         0047fb7a     CALL       write                                            undefined write()
    //         0047fb7f     ADD        ESP,0xc
    //         0047fb82     CMP        EAX,EDI
    //         0047fb84     JNZ        LAB_0047fbbd
    //         0047fb86     MOV        ESI,dword ptr [ESI + 0x10]
    //                              Res_file.cpp:899 (6)
    //         0047fb89     ADD        EBP,EDI
    //         0047fb8b     TEST       ESI,ESI
    //         0047fb8d     JNZ        LAB_0047fb66
    //                               LAB_0047fb8f                                                 XREF[1]:     0047fb64(j)  
    //                              Res_file.cpp:884 (13)
    //         0047fb8f     MOV        EBX,dword ptr [EBX + 0x10]
    //         0047fb92     TEST       EBX,EBX
    //         0047fb94     JNZ        LAB_0047fb5f
    //         0047fb96     MOV        ESI,dword ptr [ESP + iq]
    //         0047fb9a     JMP        LAB_0047fbdd
    //                               LAB_0047fb9c                                                 XREF[1]:     0047fb69(j)  
    //                              Res_file.cpp:890 (20)
    //         0047fb9c     PUSH       s_Error_writing_resource_file_data               = "Error writing resource file data: pos out 
    //                               LAB_0047fba1                                                 XREF[2]:     0047f8cd(j), 0047fa8d(j)  
    //         0047fba1     MOV        EDX,dword ptr [L]                                = 00000000
    //         0047fba7     PUSH       EDX
    //         0047fba8     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         0047fbad     ADD        ESP,0x8
    //                              Res_file.cpp:891 (2)
    //         0047fbb0     XOR        EAX,EAX
    //                              Res_file.cpp:935 (11)
    //         0047fbb2     POP        EDI
    //         0047fbb3     POP        ESI
    //         0047fbb4     POP        EBP
    //         0047fbb5     POP        EBX
    //         0047fbb6     ADD        ESP,0x4a4
    //         0047fbbc     RET
    //                               LAB_0047fbbd                                                 XREF[1]:     0047fb84(j)  
    //                              Res_file.cpp:895 (19)
    //         0047fbbd     PUSH       s_Error_writing_resource_file_data               = "Error writing resource file data"
    //                               LAB_0047fbc2                                                 XREF[3]:     0047f904(j), 0047f91d(j), 
    //                                                                                                         0047fb2f(j)  
    //         0047fbc2     MOV        EAX,[L]                                          = 00000000
    //         0047fbc7     PUSH       EAX
    //         0047fbc8     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         0047fbcd     ADD        ESP,0x8
    //                              Res_file.cpp:896 (2)
    //         0047fbd0     XOR        EAX,EAX
    //                              Res_file.cpp:935 (11)
    //         0047fbd2     POP        EDI
    //         0047fbd3     POP        ESI
    //         0047fbd4     POP        EBP
    //         0047fbd5     POP        EBX
    //         0047fbd6     ADD        ESP,0x4a4
    //         0047fbdc     RET
    //                               LAB_0047fbdd                                                 XREF[2]:     0047fb5d(j), 0047fb9a(j)  
    //                              Res_file.cpp:905 (13)
    //         0047fbdd     MOV        ECX,dword ptr [ESP + numResTypes]
    //         0047fbe1     PUSH       ECX
    //         0047fbe2     CALL       close                                            undefined close()
    //         0047fbe7     ADD        ESP,0x4
    //                              Res_file.cpp:911 (2)
    //         0047fbea     MOV        EBP,ESI
    //                              Res_file.cpp:913 (4)
    //         0047fbec     TEST       ESI,ESI
    //         0047fbee     JZ         LAB_0047fc2b
    //                               LAB_0047fbf0                                                 XREF[1]:     0047fc29(j)  
    //                              Res_file.cpp:917 (3)
    //         0047fbf0     MOV        ESI,dword ptr [EBP + 0xc]
    //                              Res_file.cpp:919 (4)
    //         0047fbf3     TEST       ESI,ESI
    //         0047fbf5     JZ         LAB_0047fc19
    //                               LAB_0047fbf7                                                 XREF[1]:     0047fc17(j)  
    //                              Res_file.cpp:921 (16)
    //         0047fbf7     MOV        EAX,dword ptr [ESI + 0x8]
    //         0047fbfa     TEST       EAX,EAX
    //         0047fbfc     JZ         LAB_0047fc07
    //         0047fbfe     PUSH       EAX
    //         0047fbff     CALL       free                                             undefined free()
    //         0047fc04     ADD        ESP,0x4
    //                               LAB_0047fc07                                                 XREF[1]:     0047fbfc(j)  
    //                              Res_file.cpp:923 (3)
    //         0047fc07     MOV        EDI,dword ptr [ESI + 0x10]
    //                              Res_file.cpp:924 (9)
    //         0047fc0a     PUSH       ESI
    //         0047fc0b     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0047fc10     ADD        ESP,0x4
    //                              Res_file.cpp:925 (6)
    //         0047fc13     MOV        ESI,EDI
    //         0047fc15     TEST       EDI,EDI
    //         0047fc17     JNZ        LAB_0047fbf7
    //                               LAB_0047fc19                                                 XREF[1]:     0047fbf5(j)  
    //                              Res_file.cpp:928 (3)
    //         0047fc19     MOV        ESI,dword ptr [EBP + 0x10]
    //                              Res_file.cpp:929 (9)
    //         0047fc1c     PUSH       EBP
    //         0047fc1d     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0047fc22     ADD        ESP,0x4
    //                              Res_file.cpp:930 (6)
    //         0047fc25     MOV        EBP,ESI
    //         0047fc27     TEST       ESI,ESI
    //         0047fc29     JNZ        LAB_0047fbf0
    //                               LAB_0047fc2b                                                 XREF[1]:     0047fbee(j)  
    //                              Res_file.cpp:935 (16)
    //         0047fc2b     POP        EDI
    //         0047fc2c     POP        ESI
    //         0047fc2d     POP        EBP
    //         0047fc2e     MOV        EAX,0x1
    //         0047fc33     POP        EBX
    //         0047fc34     ADD        ESP,0x4a4
    //         0047fc3a     RET
    //                               LAB_0047fc3b                                                 XREF[1]:     0047fac6(j)  
    //                              Res_file.cpp:848 (5)
    //         0047fc3b     PUSH       s_Error_writing_resource_file_head               = "Error writing resource file header: type n
    //                              Res_file.cpp:849 (5)
    //         0047fc40     JMP        LAB_0047fb39
    //         0047fc45     ??         90h
    //         0047fc46     NOP
    //         0047fc47     NOP
    //         0047fc48     NOP
    //         0047fc49     NOP
    //         0047fc4a     NOP
    //         0047fc4b     NOP
    //         0047fc4c     NOP
    //         0047fc4d     NOP
    //         0047fc4e     NOP
    //         0047fc4f     NOP
    //                              * unsigned long __cdecl BUILDRES_get_files_resource_type(char *)                                        *
    //                              ulong __cdecl BUILDRES_get_files_resource_type(char * param_1)
    //              ulong             EAX:4          <RETURN>
    //              char *            Stack[0x4]:4   param_1                   XREF[3]:     0047fc50(R), 0047fc9c(W), 0047fcca(R)  
    //              char[8]           Stack[-0xc]:8  extension                 XREF[0,1]:   0047fcea(*)  
    //                               ?BUILDRES_get_files_resource_type@@YAKPAD@Z                  XREF[1]:     RESFILE_build_res_file:0047f6e1(c)
    //                               BUILDRES_get_files_resource_type
    //                              Res_file.cpp:943 (23)
    //         0047fc50     MOV        EDX,dword ptr [ESP + param_1]
    //         0047fc54     SUB        ESP,0x8
    //         0047fc57     OR         ECX,0xffffffff
    //         0047fc5a     XOR        EAX,EAX
    //         0047fc5c     PUSH       EBX
    //         0047fc5d     PUSH       EBP
    //         0047fc5e     PUSH       ESI
    //         0047fc5f     PUSH       EDI
    //         0047fc60     MOV        EDI,EDX
    //         0047fc62     SCASB.RE   ES:EDI
    //         0047fc64     NOT        ECX
    //         0047fc66     DEC        ECX
    //                              Res_file.cpp:952 (21)
    //         0047fc67     CMP        ECX,0x5
    //         0047fc6a     JL         LAB_0047fd1f
    //         0047fc70     CMP        ECX,0x104
    //         0047fc76     JGE        LAB_0047fd1f
    //                              Res_file.cpp:954 (3)
    //         0047fc7c     LEA        EAX,[ECX + -0x1]
    //                              Res_file.cpp:956 (15)
    //         0047fc7f     TEST       EAX,EAX
    //         0047fc81     JLE        LAB_0047fc90
    //                               LAB_0047fc83                                                 XREF[1]:     0047fc8c(j)  
    //         0047fc83     CMP        byte ptr [EAX + EDX*0x1],0x2e
    //         0047fc87     JZ         LAB_0047fc8e
    //         0047fc89     DEC        EAX
    //         0047fc8a     TEST       EAX,EAX
    //         0047fc8c     JG         LAB_0047fc83
    //                               LAB_0047fc8e                                                 XREF[1]:     0047fc87(j)  
    //                              Res_file.cpp:958 (8)
    //         0047fc8e     TEST       EAX,EAX
    //                               LAB_0047fc90                                                 XREF[1]:     0047fc81(j)  
    //         0047fc90     JZ         LAB_0047fd1f
    //                              Res_file.cpp:960 (3)
    //         0047fc96     SUB        ECX,EAX
    //         0047fc98     DEC        ECX
    //                              Res_file.cpp:962 (9)
    //         0047fc99     CMP        ECX,0x3
    //         0047fc9c     MOV        dword ptr [ESP + param_1],ECX
    //         0047fca0     JG         LAB_0047fd1f
    //                              Res_file.cpp:966 (10)
    //         0047fca2     XOR        ESI,ESI
    //         0047fca4     TEST       ECX,ECX
    //         0047fca6     JL         LAB_0047fcd9
    //         0047fca8     LEA        EBP,[EAX + EDX*0x1 + 0x1]
    //                               LAB_0047fcac                                                 XREF[1]:     0047fcd5(j)  
    //                              Res_file.cpp:968 (3)
    //         0047fcac     MOV        BL,byte ptr [ESI + EBP*0x1]
    //                              Res_file.cpp:969 (31)
    //         0047fcaf     MOVSX      EDI,BL
    //         0047fcb2     PUSH       EDI
    //         0047fcb3     CALL       isupper                                          undefined isupper()
    //         0047fcb8     ADD        ESP,0x4
    //         0047fcbb     TEST       EAX,EAX
    //         0047fcbd     JZ         LAB_0047fcca
    //         0047fcbf     PUSH       EDI
    //         0047fcc0     CALL       tolower                                          undefined tolower()
    //         0047fcc5     ADD        ESP,0x4
    //         0047fcc8     MOV        BL,AL
    //                               LAB_0047fcca                                                 XREF[1]:     0047fcbd(j)  
    //         0047fcca     MOV        EAX,dword ptr [ESP + param_1]
    //                              Res_file.cpp:970 (9)
    //         0047fcce     MOV        byte ptr [ESP + ESI*0x1 + 0x10],BL
    //         0047fcd2     INC        ESI
    //         0047fcd3     CMP        ESI,EAX
    //         0047fcd5     JLE        LAB_0047fcac
    //                              Res_file.cpp:966 (2)
    //         0047fcd7     MOV        ECX,EAX
    //                               LAB_0047fcd9                                                 XREF[1]:     0047fca6(j)  
    //                              Res_file.cpp:977 (14)
    //         0047fcd9     MOV        EAX,[DAT_00585524]                               = 766F6320h
    //         0047fcde     MOV        ESI,res_extension_table                          = 00636f76
    //         0047fce3     TEST       EAX,EAX
    //         0047fce5     JZ         LAB_0047fd07
    //                              Res_file.cpp:979 (25)
    //         0047fce7     LEA        EDI,[ECX + 0x1]
    //                               LAB_0047fcea                                                 XREF[1]:     0047fd05(j)  
    //         0047fcea     LEA        EAX=>extension[4],[ESP + 0x10]
    //         0047fcee     PUSH       EDI
    //         0047fcef     PUSH       EAX
    //         0047fcf0     PUSH       ESI=>res_extension_table                         = 00636f76
    //                                                                                  = 00766177
    //         0047fcf1     CALL       strncmp                                          undefined strncmp()
    //         0047fcf6     ADD        ESP,0xc
    //         0047fcf9     TEST       EAX,EAX
    //         0047fcfb     JZ         LAB_0047fd14
    //         0047fcfd     MOV        EAX,dword ptr [ESI + 0xc]=>s_vawxmi_0058552c     = " vawxmi"
    //                              Res_file.cpp:983 (7)
    //         0047fd00     ADD        ESI,0x8
    //         0047fd03     TEST       EAX,EAX
    //         0047fd05     JNZ        LAB_0047fcea
    //                               LAB_0047fd07                                                 XREF[1]:     0047fce5(j)  
    //                              Res_file.cpp:988 (5)
    //         0047fd07     MOV        EAX,0x62696e61
    //                              Res_file.cpp:990 (8)
    //         0047fd0c     POP        EDI
    //         0047fd0d     POP        ESI
    //         0047fd0e     POP        EBP
    //         0047fd0f     POP        EBX
    //         0047fd10     ADD        ESP,0x8
    //         0047fd13     RET
    //                               LAB_0047fd14                                                 XREF[1]:     0047fcfb(j)  
    //                              Res_file.cpp:981 (3)
    //         0047fd14     MOV        EAX,dword ptr [ESI + 0x4]=>DAT_00585524          = 766F6320h
    //                              Res_file.cpp:990 (18)
    //         0047fd17     POP        EDI
    //         0047fd18     POP        ESI
    //         0047fd19     POP        EBP
    //         0047fd1a     POP        EBX
    //         0047fd1b     ADD        ESP,0x8
    //         0047fd1e     RET
    //                               LAB_0047fd1f                                                 XREF[4]:     0047fc6a(j), 0047fc76(j), 
    //                                                                                                         0047fc90(j), 0047fca0(j)  
    //         0047fd1f     POP        EDI
    //         0047fd20     POP        ESI
    //         0047fd21     POP        EBP
    //         0047fd22     XOR        EAX,EAX
    //         0047fd24     POP        EBX
    //         0047fd25     ADD        ESP,0x8
    //         0047fd28     RET
    //         0047fd29     ??         90h
    //         0047fd2a     NOP
    //         0047fd2b     NOP
    //         0047fd2c     NOP
    //         0047fd2d     NOP
    //         0047fd2e     NOP
    //         0047fd2f     NOP
    //                              * int __cdecl rge_fake_open(int,int)                                                                    *
    //                              int __cdecl rge_fake_open(int param_1, int param_2)
    //              int               EAX:4          <RETURN>
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0047fd31(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0047fd60(R)  
    //                               ?rge_fake_open@@YAHHH@Z                                      XREF[1]:     open_scenario:004236eb(c)  
    //                               rge_fake_open
    //                              rge_fio.cpp:49 (1)
    //         0047fd30     PUSH       ESI
    //                              rge_fio.cpp:50 (8)
    //         0047fd31     MOV        ESI,dword ptr [ESP + param_1]
    //         0047fd35     TEST       ESI,ESI
    //         0047fd37     JL         LAB_0047fd86
    //                              rge_fio.cpp:55 (34)
    //         0047fd39     PUSH       0x1
    //         0047fd3b     PUSH       0x10000
    //         0047fd40     MOV        byte ptr [DAT_0086b264],0x2
    //         0047fd47     MOV        dword ptr [DAT_0086b268],0x0
    //         0047fd51     CALL       calloc                                           undefined calloc()
    //         0047fd56     MOV        [DAT_0086b270],EAX
    //                              rge_fio.cpp:56 (5)
    //         0047fd5b     MOV        [DAT_0086b278],EAX
    //                              rge_fio.cpp:61 (38)
    //         0047fd60     MOV        EAX,dword ptr [ESP + param_2]
    //         0047fd64     ADD        ESP,0x8
    //         0047fd67     MOV        dword ptr [DAT_0086b280],0x0
    //         0047fd71     MOV        dword ptr [DAT_0086b26c],0x0
    //         0047fd7b     MOV        dword ptr [DAT_0086b260],ESI
    //         0047fd81     MOV        [DAT_0086b27c],EAX
    //                               LAB_0047fd86                                                 XREF[1]:     0047fd37(j)  
    //                              rge_fio.cpp:64 (2)
    //         0047fd86     MOV        EAX,ESI
    //                              rge_fio.cpp:65 (2)
    //         0047fd88     POP        ESI
    //         0047fd89     RET
    //         0047fd8a     ??         90h
    //         0047fd8b     NOP
    //         0047fd8c     NOP
    //         0047fd8d     NOP
    //         0047fd8e     NOP
    //         0047fd8f     NOP
    //                              * int __cdecl rge_open(char *,int)                                                                      *
    //                              int __cdecl rge_open(char * param_1, int param_2)
    //              int               EAX:4          <RETURN>
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     0047fd94(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0047fd90(R)  
    //                               ?rge_open@@YAHPADH@Z                                         XREF[10]:    get_scenario_info:0041cbdf(c), 
    //                               rge_open                                                                  get_scenario_header:0041ccff(c), 
    //                                                                                                         RGE_Game_Info:0044d204(c), 
    //                                                                                                         RGE_Scenario_File_Info:0048cecd(c)
    //                                                                                                         reload_scenarios:0048d3a2(c), 
    //                                                                                                         loadLearnInfo:004e12bb(c), 
    //                                                                                                         loadUnitHistory:004e4561(c), 
    //                                                                                                         init:00541dd4(c), 
    //                                                                                                         load_game:005423b3(c), 
    //                                                                                                         load_scenario:00543e51(c)  
    //                              rge_fio.cpp:69 (19)
    //         0047fd90     MOV        EAX,dword ptr [ESP + param_2]
    //         0047fd94     MOV        ECX,dword ptr [ESP + param_1]
    //         0047fd98     PUSH       ESI
    //         0047fd99     PUSH       EDI
    //         0047fd9a     PUSH       EAX
    //         0047fd9b     PUSH       ECX
    //         0047fd9c     CALL       __open                                           undefined __open()
    //         0047fda1     MOV        ESI,EAX
    //                              rge_fio.cpp:74 (9)
    //         0047fda3     XOR        EDI,EDI
    //         0047fda5     ADD        ESP,0x8
    //         0047fda8     CMP        ESI,EDI
    //         0047fdaa     JL         LAB_0047fe0f
    //                              rge_fio.cpp:78 (33)
    //         0047fdac     PUSH       0x1
    //         0047fdae     PUSH       0x10000
    //         0047fdb3     MOV        byte ptr [DAT_0086b264],0x2
    //         0047fdba     MOV        dword ptr [DAT_0086b268],EDI
    //         0047fdc0     CALL       calloc                                           undefined calloc()
    //         0047fdc5     ADD        ESP,0x8
    //         0047fdc8     MOV        [DAT_0086b270],EAX
    //                              rge_fio.cpp:79 (5)
    //         0047fdcd     MOV        [DAT_0086b278],EAX
    //                              rge_fio.cpp:80 (6)
    //         0047fdd2     MOV        dword ptr [DAT_0086b280],EDI
    //                              rge_fio.cpp:85 (24)
    //         0047fdd8     PUSH       0x2
    //         0047fdda     PUSH       EDI
    //         0047fddb     PUSH       ESI
    //         0047fddc     MOV        dword ptr [DAT_0086b26c],EDI
    //         0047fde2     MOV        dword ptr [DAT_0086b260],ESI
    //         0047fde8     CALL       lseek                                            undefined lseek()
    //         0047fded     ADD        ESP,0xc
    //                              rge_fio.cpp:86 (14)
    //         0047fdf0     PUSH       ESI
    //         0047fdf1     CALL       __tell                                           undefined __tell()
    //         0047fdf6     ADD        ESP,0x4
    //         0047fdf9     MOV        [DAT_0086b27c],EAX
    //                              rge_fio.cpp:87 (6)
    //         0047fdfe     MOV        dword ptr [DAT_0086b274],EDI
    //                              rge_fio.cpp:88 (11)
    //         0047fe04     PUSH       EDI
    //         0047fe05     PUSH       EDI
    //         0047fe06     PUSH       ESI
    //         0047fe07     CALL       lseek                                            undefined lseek()
    //         0047fe0c     ADD        ESP,0xc
    //                               LAB_0047fe0f                                                 XREF[1]:     0047fdaa(j)  
    //                              rge_fio.cpp:91 (2)
    //         0047fe0f     MOV        EAX,ESI
    //                              rge_fio.cpp:92 (3)
    //         0047fe11     POP        EDI
    //         0047fe12     POP        ESI
    //         0047fe13     RET
    //         0047fe14     ??         90h
    //         0047fe15     NOP
    //         0047fe16     NOP
    //         0047fe17     NOP
    //         0047fe18     NOP
    //         0047fe19     NOP
    //         0047fe1a     NOP
    //         0047fe1b     NOP
    //         0047fe1c     NOP
    //         0047fe1d     NOP
    //         0047fe1e     NOP
    //         0047fe1f     NOP
    //                              * int __cdecl rge_open(char *,int,int)                                                                  *
    //                              int __cdecl rge_open(char * param_1, int param_2, int param_3)
    //              int               EAX:4          <RETURN>
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     0047fe28(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0047fe24(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0047fe20(R)  
    //                               ?rge_open@@YAHPADHH@Z                                        XREF[7]:     save:0044d3fa(c), 
    //                               rge_open                                                                  save:0048d04f(c), 
    //                                                                                                         ~TribeInformationAIModule:004d7d3c
    //                                                                                                         ~TribeInformationAIModule:004d8069
    //                                                                                                         save_game:005437bd(c), 
    //                                                                                                         base_save:005439d3(c), 
    //                                                                                                         save_scenario:00543aa5(c)  
    //                              rge_fio.cpp:96 (24)
    //         0047fe20     MOV        EAX,dword ptr [ESP + param_3]
    //         0047fe24     MOV        ECX,dword ptr [ESP + param_2]
    //         0047fe28     MOV        EDX,dword ptr [ESP + param_1]
    //         0047fe2c     PUSH       ESI
    //         0047fe2d     PUSH       EDI
    //         0047fe2e     PUSH       EAX
    //         0047fe2f     PUSH       ECX
    //         0047fe30     PUSH       EDX
    //         0047fe31     CALL       __open                                           undefined __open()
    //         0047fe36     MOV        ESI,EAX
    //                              rge_fio.cpp:101 (9)
    //         0047fe38     XOR        EDI,EDI
    //         0047fe3a     ADD        ESP,0xc
    //         0047fe3d     CMP        ESI,EDI
    //         0047fe3f     JL         LAB_0047fea4
    //                              rge_fio.cpp:105 (33)
    //         0047fe41     PUSH       0x1
    //         0047fe43     PUSH       0x10000
    //         0047fe48     MOV        byte ptr [DAT_0086b264],0x2
    //         0047fe4f     MOV        dword ptr [DAT_0086b268],EDI
    //         0047fe55     CALL       calloc                                           undefined calloc()
    //         0047fe5a     ADD        ESP,0x8
    //         0047fe5d     MOV        [DAT_0086b270],EAX
    //                              rge_fio.cpp:106 (5)
    //         0047fe62     MOV        [DAT_0086b278],EAX
    //                              rge_fio.cpp:107 (6)
    //         0047fe67     MOV        dword ptr [DAT_0086b280],EDI
    //                              rge_fio.cpp:112 (24)
    //         0047fe6d     PUSH       0x2
    //         0047fe6f     PUSH       EDI
    //         0047fe70     PUSH       ESI
    //         0047fe71     MOV        dword ptr [DAT_0086b26c],EDI
    //         0047fe77     MOV        dword ptr [DAT_0086b260],ESI
    //         0047fe7d     CALL       lseek                                            undefined lseek()
    //         0047fe82     ADD        ESP,0xc
    //                              rge_fio.cpp:113 (14)
    //         0047fe85     PUSH       ESI
    //         0047fe86     CALL       __tell                                           undefined __tell()
    //         0047fe8b     ADD        ESP,0x4
    //         0047fe8e     MOV        [DAT_0086b27c],EAX
    //                              rge_fio.cpp:114 (6)
    //         0047fe93     MOV        dword ptr [DAT_0086b274],EDI
    //                              rge_fio.cpp:115 (11)
    //         0047fe99     PUSH       EDI
    //         0047fe9a     PUSH       EDI
    //         0047fe9b     PUSH       ESI
    //         0047fe9c     CALL       lseek                                            undefined lseek()
    //         0047fea1     ADD        ESP,0xc
    //                               LAB_0047fea4                                                 XREF[1]:     0047fe3f(j)  
    //                              rge_fio.cpp:118 (2)
    //         0047fea4     MOV        EAX,ESI
    //                              rge_fio.cpp:119 (3)
    //         0047fea6     POP        EDI
    //         0047fea7     POP        ESI
    //         0047fea8     RET
    //         0047fea9     ??         90h
    //         0047feaa     NOP
    //         0047feab     NOP
    //         0047feac     NOP
    //         0047fead     NOP
    //         0047feae     NOP
    //         0047feaf     NOP
    //                              * int __cdecl rge_fake_close(int)                                                                       *
    //                              int __cdecl rge_fake_close(int param_1)
    //              int               EAX:4          <RETURN>
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0047feb1(R)  
    //                               ?rge_fake_close@@YAHH@Z
    //                               rge_fake_close
    //                              rge_fio.cpp:123 (1)
    //         0047feb0     PUSH       EDI
    //                              rge_fio.cpp:124 (16)
    //         0047feb1     MOV        EDI,dword ptr [ESP + param_1]
    //         0047feb5     TEST       EDI,EDI
    //         0047feb7     JL         LAB_0047ff1f
    //         0047feb9     CMP        EDI,dword ptr [DAT_0086b260]
    //         0047febf     JNZ        LAB_0047ff1f
    //                              rge_fio.cpp:126 (9)
    //         0047fec1     MOV        EAX,[DAT_0086b270]
    //         0047fec6     TEST       EAX,EAX
    //         0047fec8     JZ         LAB_0047fedd
    //                              rge_fio.cpp:128 (9)
    //         0047feca     PUSH       EAX
    //         0047fecb     CALL       free                                             undefined free()
    //         0047fed0     ADD        ESP,0x4
    //                              rge_fio.cpp:129 (10)
    //         0047fed3     MOV        dword ptr [DAT_0086b270],0x0
    //                               LAB_0047fedd                                                 XREF[1]:     0047fec8(j)  
    //                              rge_fio.cpp:132 (9)
    //         0047fedd     MOV        EAX,[DAT_0086b26c]
    //         0047fee2     TEST       EAX,EAX
    //         0047fee4     JZ         LAB_0047fef9
    //                              rge_fio.cpp:134 (9)
    //         0047fee6     PUSH       EAX
    //         0047fee7     CALL       free                                             undefined free()
    //         0047feec     ADD        ESP,0x4
    //                              rge_fio.cpp:135 (10)
    //         0047feef     MOV        dword ptr [DAT_0086b26c],0x0
    //                               LAB_0047fef9                                                 XREF[1]:     0047fee4(j)  
    //                              rge_fio.cpp:138 (9)
    //         0047fef9     MOV        EAX,[DAT_0086b280]
    //         0047fefe     TEST       EAX,EAX
    //         0047ff00     JZ         LAB_0047ff15
    //                              rge_fio.cpp:140 (9)
    //         0047ff02     PUSH       EAX
    //         0047ff03     CALL       free                                             undefined free()
    //         0047ff08     ADD        ESP,0x4
    //                              rge_fio.cpp:141 (10)
    //         0047ff0b     MOV        dword ptr [DAT_0086b280],0x0
    //                               LAB_0047ff15                                                 XREF[1]:     0047ff00(j)  
    //                              rge_fio.cpp:143 (10)
    //         0047ff15     MOV        dword ptr [DAT_0086b260],0xffffffff
    //                               LAB_0047ff1f                                                 XREF[2]:     0047feb7(j), 0047febf(j)  
    //                              rge_fio.cpp:146 (2)
    //         0047ff1f     MOV        EAX,EDI
    //                              rge_fio.cpp:147 (2)
    //         0047ff21     POP        EDI
    //         0047ff22     RET
    //         0047ff23     ??         90h
    //         0047ff24     NOP
    //         0047ff25     NOP
    //         0047ff26     NOP
    //         0047ff27     NOP
    //         0047ff28     NOP
    //         0047ff29     NOP
    //         0047ff2a     NOP
    //         0047ff2b     NOP
    //         0047ff2c     NOP
    //         0047ff2d     NOP
    //         0047ff2e     NOP
    //         0047ff2f     NOP
    //                              * int __cdecl rge_close(int)                                                                            *
    //                              int __cdecl rge_close(int param_1)
    //              int               EAX:4          <RETURN>
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0047ff31(R)  
    //                               ?rge_close@@YAHH@Z                                           XREF[37]:    get_scenario_info:0041cc34(c), 
    //                               rge_close                                                                 get_scenario_info:0041cc7d(c), 
    //                                                                                                         get_scenario_header:0041cd87(c), 
    //                                                                                                         RGE_Game_Info:0044d2b7(c), 
    //                                                                                                         RGE_Game_Info:0044d2c5(c), 
    //                                                                                                         save:0044d456(c), 
    //                                                                                                         RGE_Scenario_File_Info:0048cf6f(c)
    //                                                                                                         RGE_Scenario_File_Info:0048cf8e(c)
    //                                                                                                         save:0048d0cb(c), 
    //                                                                                                         reload_scenarios:0048d3d1(c), 
    //                                                                                                         ~TribeInformationAIModule:004d8029
    //                                                                                                         ~TribeInformationAIModule:004d808b
    //                                                                                                         loadUnitHistory:004e4583(c), 
    //                                                                                                         init:00541e2a(c), 
    //                                                                                                         init:00541e4e(c), 
    //                                                                                                         load_scenario5:00544eaf(c), 
    //                                                                                                         load_scenario5:00545119(c), 
    //                                                                                                         load_scenario6:005451df(c), 
    //                                                                                                         load_scenario6:00545449(c), 
    //                                                                                                         load_scenario7:0054550f(c), [more]
    //                              rge_fio.cpp:151 (1)
    //         0047ff30     PUSH       EDI
    //                              rge_fio.cpp:152 (24)
    //         0047ff31     MOV        EDI,dword ptr [ESP + param_1]
    //         0047ff35     TEST       EDI,EDI
    //         0047ff37     JL         LAB_0047fff0
    //         0047ff3d     CMP        EDI,dword ptr [DAT_0086b260]
    //         0047ff43     JNZ        LAB_0047fff0
    //                              rge_fio.cpp:154 (18)
    //         0047ff49     CMP        byte ptr [DAT_0086b264],0x1
    //         0047ff50     JNZ        LAB_0047ff87
    //         0047ff52     MOV        EAX,[DAT_0086b26c]
    //         0047ff57     TEST       EAX,EAX
    //         0047ff59     JZ         LAB_0047ff87
    //                              rge_fio.cpp:156 (20)
    //         0047ff5b     PUSH       0x1
    //         0047ff5d     PUSH       0x0
    //         0047ff5f     PUSH       0x0
    //         0047ff61     PUSH       EAX
    //         0047ff62     CALL       deflate_data                                     undefined deflate_data()
    //         0047ff67     ADD        ESP,0x10
    //         0047ff6a     CMP        EAX,0x2
    //         0047ff6d     JNZ        LAB_0047ff79
    //                              rge_fio.cpp:157 (10)
    //         0047ff6f     MOV        dword ptr [rge_write_error],0x1
    //                               LAB_0047ff79                                                 XREF[1]:     0047ff6d(j)  
    //                              rge_fio.cpp:158 (14)
    //         0047ff79     MOV        EAX,[DAT_0086b26c]
    //         0047ff7e     PUSH       EAX
    //         0047ff7f     CALL       deflate_deinit                                   undefined deflate_deinit()
    //         0047ff84     ADD        ESP,0x4
    //                               LAB_0047ff87                                                 XREF[2]:     0047ff50(j), 0047ff59(j)  
    //                              rge_fio.cpp:166 (19)
    //         0047ff87     MOV        EAX,[DAT_0086b270]
    //         0047ff8c     MOV        dword ptr [DAT_0086b260],0xffffffff
    //         0047ff96     TEST       EAX,EAX
    //         0047ff98     JZ         LAB_0047ffad
    //                              rge_fio.cpp:168 (9)
    //         0047ff9a     PUSH       EAX
    //         0047ff9b     CALL       free                                             undefined free()
    //         0047ffa0     ADD        ESP,0x4
    //                              rge_fio.cpp:169 (10)
    //         0047ffa3     MOV        dword ptr [DAT_0086b270],0x0
    //                               LAB_0047ffad                                                 XREF[1]:     0047ff98(j)  
    //                              rge_fio.cpp:172 (9)
    //         0047ffad     MOV        EAX,[DAT_0086b26c]
    //         0047ffb2     TEST       EAX,EAX
    //         0047ffb4     JZ         LAB_0047ffc9
    //                              rge_fio.cpp:174 (9)
    //         0047ffb6     PUSH       EAX
    //         0047ffb7     CALL       free                                             undefined free()
    //         0047ffbc     ADD        ESP,0x4
    //                              rge_fio.cpp:175 (10)
    //         0047ffbf     MOV        dword ptr [DAT_0086b26c],0x0
    //                               LAB_0047ffc9                                                 XREF[1]:     0047ffb4(j)  
    //                              rge_fio.cpp:178 (9)
    //         0047ffc9     MOV        EAX,[DAT_0086b280]
    //         0047ffce     TEST       EAX,EAX
    //         0047ffd0     JZ         LAB_0047ffe5
    //                              rge_fio.cpp:180 (9)
    //         0047ffd2     PUSH       EAX
    //         0047ffd3     CALL       free                                             undefined free()
    //         0047ffd8     ADD        ESP,0x4
    //                              rge_fio.cpp:181 (10)
    //         0047ffdb     MOV        dword ptr [DAT_0086b280],0x0
    //                               LAB_0047ffe5                                                 XREF[1]:     0047ffd0(j)  
    //                              rge_fio.cpp:184 (11)
    //         0047ffe5     PUSH       EDI
    //         0047ffe6     CALL       close                                            undefined close()
    //         0047ffeb     ADD        ESP,0x4
    //         0047ffee     MOV        EDI,EAX
    //                               LAB_0047fff0                                                 XREF[2]:     0047ff37(j), 0047ff43(j)  
    //                              rge_fio.cpp:187 (2)
    //         0047fff0     MOV        EAX,EDI
    //                              rge_fio.cpp:188 (2)
    //         0047fff2     POP        EDI
    //         0047fff3     RET
    //         0047fff4     ??         90h
    //         0047fff5     NOP
    //         0047fff6     NOP
    //         0047fff7     NOP
    //         0047fff8     NOP
    //         0047fff9     NOP
    //         0047fffa     NOP
    //         0047fffb     NOP
    //         0047fffc     NOP
    //         0047fffd     NOP
    //         0047fffe     NOP
    //         0047ffff     NOP
    //                              * void __cdecl rge_read_uncompressed(int,void *,int)                                                    *
    //                              void __cdecl rge_read_uncompressed(int param_1, void * param_2, int 
    //              void              <VOID>         <RETURN>
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00480000(R)  
    //              void *            Stack[0x8]:4   param_2                   XREF[1]:     00480010(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     00480015(R)  
    //                               ?rge_read_uncompressed@@YAXHPAXH@Z                           XREF[33]:    get_scenario_info:0041cc04(c), 
    //                               rge_read_uncompressed                                                     get_scenario_info:0041cc14(c), 
    //                                                                                                         get_scenario_info:0041cc51(c), 
    //                                                                                                         get_scenario_header:0041cd24(c), 
    //                                                                                                         RGE_Scenario_Header:0048abdc(c), 
    //                                                                                                         RGE_Scenario_Header:0048abe8(c), 
    //                                                                                                         RGE_Scenario_Header:0048abfb(c), 
    //                                                                                                         RGE_Scenario_Header:0048ac0b(c), 
    //                                                                                                         RGE_Scenario_Header:0048ac43(c), 
    //                                                                                                         RGE_Scenario_File_Info:0048ceea(c)
    //                                                                                                         RGE_Scenario_File_Info:0048cf26(c)
    //                                                                                                         RGE_Scenario_File_Info:0048cf3f(c)
    //                                                                                                         reload_scenarios:0048d3b9(c), 
    //                                                                                                         TRIBE_Scenario_Header:0052aa44(c), 
    //                                                                                                         TRIBE_Scenario_Header:0052aa50(c), 
    //                                                                                                         load_scenario5:00544e8f(c), 
    //                                                                                                         load_scenario5:00544ec8(c), 
    //                                                                                                         load_scenario6:005451bf(c), 
    //                                                                                                         load_scenario6:005451f8(c), 
    //                                                                                                         load_scenario7:005454ef(c), [more]
    //                              rge_fio.cpp:194 (16)
    //         00480000     MOV        EAX,dword ptr [ESP + param_1]
    //         00480004     TEST       EAX,EAX
    //         00480006     JL         LAB_00480031
    //         00480008     CMP        EAX,dword ptr [DAT_0086b260]
    //         0048000e     JNZ        LAB_00480031
    //                              rge_fio.cpp:197 (17)
    //         00480010     MOV        ECX,dword ptr [ESP + param_2]
    //         00480014     PUSH       ESI
    //         00480015     MOV        ESI,dword ptr [ESP + param_3]
    //         00480019     PUSH       ESI
    //         0048001a     PUSH       ECX
    //         0048001b     PUSH       EAX
    //         0048001c     CALL       read                                             undefined read()
    //                              rge_fio.cpp:198 (16)
    //         00480021     MOV        EAX,[DAT_0086b27c]
    //         00480026     ADD        ESP,0xc
    //         00480029     SUB        EAX,ESI
    //         0048002b     MOV        [DAT_0086b27c],EAX
    //         00480030     POP        ESI
    //                               LAB_00480031                                                 XREF[2]:     00480006(j), 0048000e(j)  
    //                              rge_fio.cpp:202 (1)
    //         00480031     RET
    //         00480032     ??         90h
    //         00480033     NOP
    //         00480034     NOP
    //         00480035     NOP
    //         00480036     NOP
    //         00480037     NOP
    //         00480038     NOP
    //         00480039     NOP
    //         0048003a     NOP
    //         0048003b     NOP
    //         0048003c     NOP
    //         0048003d     NOP
    //         0048003e     NOP
    //         0048003f     NOP
    //                              * void __cdecl rge_write_uncompressed(int,void *,int)                                                   *
    //                              void __cdecl rge_write_uncompressed(int param_1, void * param_2, int
    //              void              <VOID>         <RETURN>
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00480040(R)  
    //              void *            Stack[0x8]:4   param_2                   XREF[1]:     00480054(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     00480050(R)  
    //                               ?rge_write_uncompressed@@YAXHPAXH@Z                          XREF[12]:    write_scenario_header:0041cdec(c), 
    //                               rge_write_uncompressed                                                    save:0048acdc(c), 
    //                                                                                                         save:0048aceb(c), 
    //                                                                                                         save:0048ad01(c), 
    //                                                                                                         save:0048ad2f(c), 
    //                                                                                                         save:0048ad45(c), 
    //                                                                                                         save:0048d06a(c), 
    //                                                                                                         save:0048d088(c), 
    //                                                                                                         save:0048d0a1(c), 
    //                                                                                                         save:0052aa95(c), 
    //                                                                                                         save:0052aaa4(c), 
    //                                                                                                         save_scenario:00543ae5(c)  
    //                              rge_fio.cpp:208 (16)
    //         00480040     MOV        EAX,dword ptr [ESP + param_1]
    //         00480044     TEST       EAX,EAX
    //         00480046     JL         LAB_00480071
    //         00480048     CMP        EAX,dword ptr [DAT_0086b260]
    //         0048004e     JNZ        LAB_00480071
    //                              rge_fio.cpp:211 (23)
    //         00480050     MOV        ECX,dword ptr [ESP + param_3]
    //         00480054     MOV        EDX,dword ptr [ESP + param_2]
    //         00480058     PUSH       ECX
    //         00480059     PUSH       EDX
    //         0048005a     PUSH       EAX
    //         0048005b     CALL       write                                            undefined write()
    //         00480060     ADD        ESP,0xc
    //         00480063     TEST       EAX,EAX
    //         00480065     JG         LAB_00480071
    //                              rge_fio.cpp:212 (10)
    //         00480067     MOV        dword ptr [rge_write_error],0x1
    //                               LAB_00480071                                                 XREF[3]:     00480046(j), 0048004e(j), 
    //                                                                                                         00480065(j)  
    //                              rge_fio.cpp:216 (1)
    //         00480071     RET
    //         00480072     ??         90h
    //         00480073     NOP
    //         00480074     NOP
    //         00480075     NOP
    //         00480076     NOP
    //         00480077     NOP
    //         00480078     NOP
    //         00480079     NOP
    //         0048007a     NOP
    //         0048007b     NOP
    //         0048007c     NOP
    //         0048007d     NOP
    //         0048007e     NOP
    //         0048007f     NOP
    //                              * void __cdecl rge_read(int,void *,int)                                                                 *
    //                              void __cdecl rge_read(int param_1, void * param_2, int param_3)
    //              void              <VOID>         <RETURN>
    //              int               Stack[0x4]:4   param_1                   XREF[4]:     00480096(R), 004800dd(R), 0048014c(W), 00480162(*)  
    //              void *            Stack[0x8]:4   param_2                   XREF[3]:     00480086(R), 00480090(W), 004801bf(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[2]:     004800ae(R), 0048019c(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00480148(*), 00480175(W)  
    //              int               Stack[-0x8]:4  temp_max
    //                               ?rge_read@@YAXHPAXH@Z                                        XREF[1083]:  load:00403ef1(c), 
    //                               rge_read                                                                  setup:00407557(c), 
    //                                                                                                         setup:00407567(c), 
    //                                                                                                         setup:00407588(c), 
    //                                                                                                         setup:004075a8(c), 
    //                                                                                                         setup:004075b7(c), 
    //                                                                                                         setup:004075c6(c), 
    //                                                                                                         setup:004075d5(c), 
    //                                                                                                         setup:004075e4(c), 
    //                                                                                                         setup:004075f3(c), 
    //                                                                                                         setup:00407603(c), 
    //                                                                                                         setup:00407639(c), 
    //                                                                                                         setup:00407652(c), 
    //                                                                                                         RGE_Sound:004bbf56(c), 
    //                                                                                                         RGE_Sound:004bbf62(c), 
    //                                                                                                         RGE_Sound:004bbf71(c), 
    //                                                                                                         RGE_Sound:004bbf80(c), 
    //                                                                                                         RGE_Sound:004bbfbb(c), 
    //                                                                                                         RGE_Sound:004bbfce(c), 
    //                                                                                                         TRIBE_Action_Discovery_Artifact:00
    //                                                                                                         [more]
    //                              rge_fio.cpp:222 (1)
    //         00480080     PUSH       ECX
    //                              rge_fio.cpp:230 (21)
    //         00480081     MOV        EAX,[ENABLE_COMPRESSION]                         = 1h
    //         00480086     MOV        ECX,dword ptr [ESP + param_2]
    //         0048008a     PUSH       EBX
    //         0048008b     PUSH       EBP
    //         0048008c     PUSH       ESI
    //         0048008d     PUSH       EDI
    //         0048008e     TEST       EAX,EAX
    //         00480090     MOV        dword ptr [ESP + param_2],ECX
    //         00480094     JNZ        LAB_004800dd
    //                              rge_fio.cpp:232 (24)
    //         00480096     MOV        EAX,dword ptr [ESP + param_1]
    //         0048009a     TEST       EAX,EAX
    //         0048009c     JL         LAB_00480285
    //         004800a2     CMP        EAX,dword ptr [DAT_0086b260]
    //         004800a8     JNZ        LAB_00480285
    //                              rge_fio.cpp:234 (12)
    //         004800ae     MOV        ESI,dword ptr [ESP + param_3]
    //         004800b2     PUSH       ESI
    //         004800b3     PUSH       ECX
    //         004800b4     PUSH       EAX
    //         004800b5     CALL       read                                             undefined read()
    //                              rge_fio.cpp:235 (6)
    //         004800ba     MOV        ECX,dword ptr [DAT_0086b27c]
    //                              rge_fio.cpp:236 (23)
    //         004800c0     MOV        EAX,[DAT_0086b274]
    //         004800c5     ADD        ESP,0xc
    //         004800c8     SUB        ECX,ESI
    //         004800ca     ADD        EAX,ESI
    //         004800cc     MOV        dword ptr [DAT_0086b27c],ECX
    //         004800d2     MOV        [DAT_0086b274],EAX
    //                              rge_fio.cpp:306 (6)
    //         004800d7     POP        EDI
    //         004800d8     POP        ESI
    //         004800d9     POP        EBP
    //         004800da     POP        EBX
    //         004800db     POP        ECX
    //         004800dc     RET
    //                               LAB_004800dd                                                 XREF[1]:     00480094(j)  
    //                              rge_fio.cpp:248 (24)
    //         004800dd     MOV        ESI,dword ptr [ESP + param_1]
    //         004800e1     TEST       ESI,ESI
    //         004800e3     JL         LAB_00480285
    //         004800e9     CMP        ESI,dword ptr [DAT_0086b260]
    //         004800ef     JNZ        LAB_00480285
    //                              rge_fio.cpp:250 (13)
    //         004800f5     MOV        AL,[DAT_0086b264]
    //         004800fa     TEST       AL,AL
    //         004800fc     JZ         LAB_0048019c
    //                              rge_fio.cpp:252 (5)
    //         00480102     CALL       _Inf32BufSize                                    undefined _Inf32BufSize()
    //                              rge_fio.cpp:253 (16)
    //         00480107     PUSH       0x1
    //         00480109     PUSH       EAX
    //         0048010a     CALL       calloc                                           undefined calloc()
    //         0048010f     ADD        ESP,0x8
    //         00480112     MOV        [DAT_0086b26c],EAX
    //                              rge_fio.cpp:256 (13)
    //         00480117     MOV        EAX,[DAT_0086b27c]
    //         0048011c     PUSH       0x1
    //         0048011e     PUSH       EAX
    //         0048011f     CALL       calloc                                           undefined calloc()
    //                              rge_fio.cpp:257 (22)
    //         00480124     MOV        ECX,dword ptr [DAT_0086b27c]
    //         0048012a     ADD        ESP,0x8
    //         0048012d     MOV        [DAT_0086b280],EAX
    //         00480132     PUSH       ECX
    //         00480133     PUSH       EAX
    //         00480134     PUSH       ESI
    //         00480135     CALL       read                                             undefined read()
    //                              rge_fio.cpp:260 (6)
    //         0048013a     MOV        EDX,dword ptr [DAT_0086b27c]
    //                              rge_fio.cpp:266 (66)
    //         00480140     MOV        EAX,[DAT_0086b26c]
    //         00480145     ADD        ESP,0xc
    //         00480148     LEA        ECX=>local_4,[ESP + 0x10]
    //         0048014c     MOV        dword ptr [ESP + param_1],EDX
    //         00480150     MOV        EDX,dword ptr [DAT_0086b270]
    //         00480156     PUSH       0x1
    //         00480158     PUSH       EAX
    //         00480159     PUSH       ECX
    //         0048015a     MOV        ECX,dword ptr [DAT_0086b280]
    //         00480160     PUSH       0x0
    //         00480162     LEA        EAX=>param_1,[ESP + 0x28]
    //         00480166     PUSH       EDX
    //         00480167     PUSH       EAX
    //         00480168     PUSH       0x0
    //         0048016a     PUSH       ECX
    //         0048016b     MOV        dword ptr [DAT_0086b25c],0x0
    //         00480175     MOV        dword ptr [ESP + local_4],0x10000
    //         0048017d     CALL       _Inf32Decode                                     undefined _Inf32Decode()
    //                              rge_fio.cpp:268 (19)
    //         00480182     MOV        EDX,dword ptr [ESP + 0x38]
    //         00480186     MOV        EAX,[DAT_0086b25c]
    //         0048018b     ADD        ESP,0x20
    //         0048018e     ADD        EAX,EDX
    //         00480190     MOV        [DAT_0086b25c],EAX
    //                              rge_fio.cpp:270 (7)
    //         00480195     MOV        byte ptr [DAT_0086b264],0x0
    //                               LAB_0048019c                                                 XREF[1]:     004800fc(j)  
    //                              rge_fio.cpp:274 (35)
    //         0048019c     MOV        EBX,dword ptr [ESP + param_3]
    //         004801a0     MOV        EAX,[DAT_0086b268]
    //         004801a5     MOV        ESI,dword ptr [DAT_0086b278]
    //         004801ab     LEA        ECX,[EBX + EAX*0x1]
    //         004801ae     CMP        ECX,0x10000
    //         004801b4     JL         LAB_00480253
    //                               LAB_004801ba                                                 XREF[1]:     0048024d(j)  
    //         004801ba     MOV        EBP,0x10000
    //                              rge_fio.cpp:277 (6)
    //         004801bf     MOV        EDI,dword ptr [ESP + param_2]
    //         004801c3     SUB        EBP,EAX
    //                              rge_fio.cpp:286 (78)
    //         004801c5     PUSH       0x1
    //         004801c7     MOV        ECX,EBP
    //         004801c9     MOV        EDX,ECX
    //         004801cb     SHR        ECX,0x2
    //         004801ce     MOVSD.REP  ES:EDI,ESI
    //         004801d0     MOV        ECX,EDX
    //         004801d2     LEA        EDX,[ESP + 0x14]
    //         004801d6     AND        ECX,0x3
    //         004801d9     MOVSB.REP  ES:EDI,ESI
    //         004801db     MOV        EAX,[DAT_0086b27c]
    //         004801e0     MOV        ECX,dword ptr [DAT_0086b26c]
    //         004801e6     MOV        dword ptr [ESP + 0x1c],EAX
    //         004801ea     MOV        EAX,[DAT_0086b270]
    //         004801ef     PUSH       ECX
    //         004801f0     PUSH       EDX
    //         004801f1     MOV        EDX,dword ptr [DAT_0086b25c]
    //         004801f7     PUSH       0x0
    //         004801f9     LEA        ECX,[ESP + 0x28]
    //         004801fd     PUSH       EAX
    //         004801fe     MOV        EAX,[DAT_0086b280]
    //         00480203     PUSH       ECX
    //         00480204     PUSH       EDX
    //         00480205     PUSH       EAX
    //         00480206     MOV        dword ptr [ESP + 0x30],0x10000
    //         0048020e     CALL       _Inf32Decode                                     undefined _Inf32Decode()
    //                              rge_fio.cpp:288 (10)
    //         00480213     MOV        ECX,dword ptr [ESP + 0x38]
    //         00480217     MOV        EDI,dword ptr [DAT_0086b25c]
    //                              rge_fio.cpp:292 (4)
    //         0048021d     MOV        EDX,dword ptr [ESP + 0x3c]
    //                              rge_fio.cpp:293 (50)
    //         00480221     MOV        ESI,dword ptr [DAT_0086b270]
    //         00480227     SUB        EBX,EBP
    //         00480229     ADD        ESP,0x20
    //         0048022c     ADD        EDI,ECX
    //         0048022e     XOR        EAX,EAX
    //         00480230     ADD        EDX,EBP
    //         00480232     CMP        EBX,0x10000
    //         00480238     MOV        dword ptr [DAT_0086b25c],EDI
    //         0048023e     MOV        [DAT_0086b268],EAX
    //         00480243     MOV        dword ptr [ESP + 0x1c],EDX
    //         00480247     MOV        dword ptr [DAT_0086b278],ESI
    //         0048024d     JGE        LAB_004801ba
    //                               LAB_00480253                                                 XREF[1]:     004801b4(j)  
    //                              rge_fio.cpp:297 (4)
    //         00480253     TEST       EBX,EBX
    //         00480255     JLE        LAB_00480285
    //                              rge_fio.cpp:299 (20)
    //         00480257     MOV        EDI,dword ptr [ESP + 0x1c]
    //         0048025b     MOV        ECX,EBX
    //         0048025d     MOV        EDX,ECX
    //         0048025f     SHR        ECX,0x2
    //         00480262     MOVSD.REP  ES:EDI,ESI
    //         00480264     MOV        ECX,EDX
    //         00480266     AND        ECX,0x3
    //         00480269     MOVSB.REP  ES:EDI,ESI
    //                              rge_fio.cpp:300 (6)
    //         0048026b     MOV        ECX,dword ptr [DAT_0086b268]
    //                              rge_fio.cpp:301 (20)
    //         00480271     MOV        EAX,[DAT_0086b278]
    //         00480276     ADD        ECX,EBX
    //         00480278     ADD        EAX,EBX
    //         0048027a     MOV        dword ptr [DAT_0086b268],ECX
    //         00480280     MOV        [DAT_0086b278],EAX
    //                               LAB_00480285                                                 XREF[5]:     0048009c(j), 004800a8(j), 
    //                                                                                                         004800e3(j), 004800ef(j), 
    //                                                                                                         00480255(j)  
    //                              rge_fio.cpp:306 (6)
    //         00480285     POP        EDI
    //         00480286     POP        ESI
    //         00480287     POP        EBP
    //         00480288     POP        EBX
    //         00480289     POP        ECX
    //         0048028a     RET
    //         0048028b     ??         90h
    //         0048028c     NOP
    //         0048028d     NOP
    //         0048028e     NOP
    //         0048028f     NOP
    //                              * int __cdecl rge_buffer_full(unsigned char *,int)                                                      *
    //                              int __cdecl rge_buffer_full(uchar * param_1, int param_2)
    //              int               EAX:4          <RETURN>
    //              uchar *           Stack[0x4]:4   param_1                   XREF[1]:     00480294(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     00480290(R)  
    //                               ?rge_buffer_full@@YAHPAEH@Z                                  XREF[1]:     rge_write:0048033e(*)  
    //                               rge_buffer_full
    //                              rge_fio.cpp:310 (29)
    //         00480290     MOV        EAX,dword ptr [ESP + param_2]
    //         00480294     MOV        ECX,dword ptr [ESP + param_1]
    //         00480298     MOV        EDX,dword ptr [DAT_0086b260]
    //         0048029e     PUSH       EAX
    //         0048029f     PUSH       ECX
    //         004802a0     PUSH       EDX
    //         004802a1     CALL       write                                            undefined write()
    //         004802a6     ADD        ESP,0xc
    //         004802a9     TEST       EAX,EAX
    //         004802ab     JG         LAB_004802b7
    //                              rge_fio.cpp:313 (10)
    //         004802ad     MOV        dword ptr [rge_write_error],0x1
    //                               LAB_004802b7                                                 XREF[1]:     004802ab(j)  
    //                              rge_fio.cpp:318 (2)
    //         004802b7     XOR        EAX,EAX
    //                              rge_fio.cpp:320 (1)
    //         004802b9     RET
    //         004802ba     ??         90h
    //         004802bb     NOP
    //         004802bc     NOP
    //         004802bd     NOP
    //         004802be     NOP
    //         004802bf     NOP
    //                              * void __cdecl rge_write(int,void *,int)                                                                *
    //                              void __cdecl rge_write(int param_1, void * param_2, int param_3)
    //              void              <VOID>         <RETURN>
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004802c7(R)  
    //              void *            Stack[0x8]:4   param_2                   XREF[2]:     004802e5(R), 0048035c(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[2]:     004802e1(R), 00480358(R)  
    //                               ?rge_write@@YAXHPAXH@Z                                       XREF[974]:   save:0040d0bb(c), 
    //                               rge_write                                                                 save:0040d156(c), 
    //                                                                                                         Save:0046e031(c), 
    //                                                                                                         Save:0046e040(c), 
    //                                                                                                         Save:0046e04f(c), 
    //                                                                                                         Save:0046e05e(c), 
    //                                                                                                         Save:0046e07c(c), 
    //                                                                                                         Save:0046e095(c), 
    //                                                                                                         save:004d8502(c), 
    //                                                                                                         save:004e5e54(c), 
    //                                                                                                         save:004e5e66(c), 
    //                                                                                                         save:004e5e78(c), 
    //                                                                                                         save:004e5e8a(c), 
    //                                                                                                         save:004e5e9c(c), 
    //                                                                                                         save:004e5eae(c), 
    //                                                                                                         save:004e5ec0(c), 
    //                                                                                                         save:004e5ed2(c), 
    //                                                                                                         save:004e5ee4(c), 
    //                                                                                                         save:004e5ef6(c), 
    //                                                                                                         save:004e5f08(c), [more]
    //                              rge_fio.cpp:326 (7)
    //         004802c0     MOV        EAX,[ENABLE_COMPRESSION]                         = 1h
    //         004802c5     TEST       EAX,EAX
    //                              rge_fio.cpp:332 (26)
    //         004802c7     MOV        EAX,dword ptr [ESP + param_1]
    //         004802cb     JNZ        LAB_00480307
    //         004802cd     TEST       EAX,EAX
    //         004802cf     JL         LAB_00480382
    //         004802d5     CMP        EAX,dword ptr [DAT_0086b260]
    //         004802db     JNZ        LAB_00480382
    //                              rge_fio.cpp:334 (27)
    //         004802e1     MOV        ECX,dword ptr [ESP + param_3]
    //         004802e5     MOV        EDX,dword ptr [ESP + param_2]
    //         004802e9     PUSH       ECX
    //         004802ea     PUSH       EDX
    //         004802eb     PUSH       EAX
    //         004802ec     CALL       write                                            undefined write()
    //         004802f1     ADD        ESP,0xc
    //         004802f4     TEST       EAX,EAX
    //         004802f6     JG         LAB_00480382
    //                              rge_fio.cpp:356 (10)
    //         004802fc     MOV        dword ptr [rge_write_error],0x1
    //                              rge_fio.cpp:360 (1)
    //         00480306     RET
    //                               LAB_00480307                                                 XREF[1]:     004802cb(j)  
    //                              rge_fio.cpp:343 (12)
    //         00480307     TEST       EAX,EAX
    //         00480309     JL         LAB_00480382
    //         0048030b     CMP        EAX,dword ptr [DAT_0086b260]
    //         00480311     JNZ        LAB_00480382
    //                              rge_fio.cpp:345 (9)
    //         00480313     CMP        byte ptr [DAT_0086b264],0x1
    //         0048031a     JZ         LAB_00480358
    //                              rge_fio.cpp:347 (7)
    //         0048031c     MOV        byte ptr [DAT_0086b264],0x1
    //                              rge_fio.cpp:349 (5)
    //         00480323     CALL       deflate_buf_size                                 undefined deflate_buf_size()
    //                              rge_fio.cpp:350 (8)
    //         00480328     PUSH       0x1
    //         0048032a     PUSH       EAX
    //         0048032b     CALL       calloc                                           undefined calloc()
    //                              rge_fio.cpp:352 (40)
    //         00480330     MOV        ECX,dword ptr [DAT_0086b270]
    //         00480336     ADD        ESP,0x8
    //         00480339     MOV        [DAT_0086b26c],EAX
    //         0048033e     PUSH       rge_buffer_full
    //         00480343     PUSH       0x10000
    //         00480348     PUSH       ECX
    //         00480349     PUSH       0x1
    //         0048034b     PUSH       0x2
    //         0048034d     PUSH       0x4b
    //         0048034f     PUSH       EAX
    //         00480350     CALL       deflate_init                                     undefined deflate_init()
    //         00480355     ADD        ESP,0x1c
    //                               LAB_00480358                                                 XREF[1]:     0048031a(j)  
    //                              rge_fio.cpp:355 (32)
    //         00480358     MOV        EDX,dword ptr [ESP + param_3]
    //         0048035c     MOV        EAX,dword ptr [ESP + param_2]
    //         00480360     MOV        ECX,dword ptr [DAT_0086b26c]
    //         00480366     PUSH       0x0
    //         00480368     PUSH       EDX
    //         00480369     PUSH       EAX
    //         0048036a     PUSH       ECX
    //         0048036b     CALL       deflate_data                                     undefined deflate_data()
    //         00480370     ADD        ESP,0x10
    //         00480373     CMP        EAX,0x2
    //         00480376     JNZ        LAB_00480382
    //                              rge_fio.cpp:356 (10)
    //         00480378     MOV        dword ptr [rge_write_error],0x1
    //                               LAB_00480382                                                 XREF[6]:     004802cf(j), 004802db(j), 
    //                                                                                                         004802f6(j), 00480309(j), 
    //                                                                                                         00480311(j), 00480376(j)  
    //                              rge_fio.cpp:360 (1)
    //         00480382     RET
    //         00480383     ??         90h
    //         00480384     NOP
    //         00480385     NOP
    //         00480386     NOP
    //         00480387     NOP
    //         00480388     NOP
    //         00480389     NOP
    //         0048038a     NOP
    //         0048038b     NOP
    //         0048038c     NOP
    //         0048038d     NOP
    //         0048038e     NOP
    //         0048038f     NOP
    return 0;
}

