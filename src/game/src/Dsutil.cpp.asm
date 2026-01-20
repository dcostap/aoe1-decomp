// Auto-generated scaffold unit: Dsutil.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/Dsutil.c
#include "../include/common.h"

// Offset: 0x004477D0
undefined ShowErrMsg() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined _ShowErrMsg()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _ShowErrMsg
    //                              Dsutil.c:38 (1)
    //         004477d0     RET
}

// Offset: 0x004477E0
undefined DSLoadSoundBuffer() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined _DSLoadSoundBuffer()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004477fe(W), 00447802(*)  
    //              _DSBUFFERDESC     Stack[-0x18]   dsBD                      XREF[3,8]:   0044780b(W), 0044782b(*), 00447882(*), 00447813(W), 
    //                                                                                     00447834(*), 0044783a(W), 004477e9(W), 00447842(W), 
    //                                                                                     004477e5(*), 004477f1(W), 004477fa(W)  
    //              IDirectSoundBu    Stack[-0x1c]:4 pDSB
    //                               _DSLoadSoundBuffer                                           XREF[2]:     _SndObjCreate:004479b9(c), 
    //                                                                                                         _SndObjCreate:004479e3(c)  
    //                              Dsutil.c:72 (3)
    //         004477e0     SUB        ESP,0x18
    //                              Dsutil.c:74 (2)
    //         004477e3     XOR        EAX,EAX
    //                              Dsutil.c:77 (66)
    //         004477e5     LEA        ECX=>dsBD.dwReserved,[ESP + 0xc]
    //         004477e9     MOV        dword ptr [ESP + dsBD.dwBufferBytes],EAX
    //         004477ed     LEA        EDX=>Stack[0x8],[ESP + 0x20]
    //         004477f1     MOV        dword ptr [ESP + dsBD.dwReserved],EAX
    //         004477f5     PUSH       ECX
    //         004477f6     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         004477fa     MOV        dword ptr [ESP + dsBD.lpwfxFormat],EAX
    //         004477fe     MOV        dword ptr [ESP + local_4],EAX
    //         00447802     LEA        EAX=>local_4,[ESP + 0x18]
    //         00447806     PUSH       EDX
    //         00447807     PUSH       EAX
    //         00447808     PUSH       ECX
    //         00447809     PUSH       0x0
    //         0044780b     MOV        dword ptr [ESP + dsBD.dwSize],0x0
    //         00447813     MOV        dword ptr [ESP + dsBD.dwFlags],0x0
    //         0044781b     CALL       _DSGetWaveResource                               undefined _DSGetWaveResource()
    //         00447820     ADD        ESP,0x14
    //         00447823     TEST       EAX,EAX
    //         00447825     JZ         LAB_00447882
    //                              Dsutil.c:82 (42)
    //         00447827     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0044782b     LEA        ECX=>dsBD,[ESP]
    //         0044782f     PUSH       0x0
    //         00447831     PUSH       ECX
    //         00447832     MOV        EDX,dword ptr [EAX]
    //         00447834     LEA        ECX=>dsBD.dwFlags,[ESP + 0xc]
    //         00447838     PUSH       ECX
    //         00447839     PUSH       EAX
    //         0044783a     MOV        dword ptr [ESP + dsBD.dwFlags],0x14
    //         00447842     MOV        dword ptr [ESP + dsBD.dwBufferBytes],0xe2
    //         0044784a     CALL       dword ptr [EDX + 0xc]
    //         0044784d     TEST       EAX,EAX
    //         0044784f     JL         LAB_0044787c
    //                              Dsutil.c:84 (27)
    //         00447851     MOV        EDX,dword ptr [ESP + 0xc]
    //         00447855     MOV        EAX,dword ptr [ESP + 0x20]
    //         00447859     MOV        ECX,dword ptr [ESP]
    //         0044785d     PUSH       EDX
    //         0044785e     PUSH       EAX=>DAT_fffffff8
    //         0044785f     PUSH       ECX=>DAT_fffffff4
    //         00447860     CALL       _DSFillSoundBuffer                               undefined _DSFillSoundBuffer()
    //         00447865     ADD        ESP,0xc
    //         00447868     TEST       EAX,EAX
    //         0044786a     JNZ        LAB_00447882
    //                              Dsutil.c:86 (10)
    //         0044786c     MOV        EAX,dword ptr [ESP]
    //         00447870     PUSH       EAX
    //         00447871     MOV        EDX,dword ptr [EAX]
    //         00447873     CALL       dword ptr [EDX + 0x8]
    //                              Dsutil.c:87 (2)
    //         00447876     XOR        EAX,EAX
    //                              Dsutil.c:97 (4)
    //         00447878     ADD        ESP,0x18
    //         0044787b     RET
    //                               LAB_0044787c                                                 XREF[1]:     0044784f(j)  
    //                              Dsutil.c:92 (2)
    //         0044787c     XOR        EAX,EAX
    //                              Dsutil.c:97 (4)
    //         0044787e     ADD        ESP,0x18
    //         00447881     RET
    //                               LAB_00447882                                                 XREF[2]:     00447825(j), 0044786a(j)  
    //                              Dsutil.c:92 (4)
    //         00447882     MOV        EAX,dword ptr [ESP]=>dsBD
    //                              Dsutil.c:97 (4)
    //         00447886     ADD        ESP,0x18
    //         00447889     RET
}

// Offset: 0x00447890
undefined DSReloadSoundBuffer() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined _DSReloadSoundBuffer()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined         Stack[-0x4]:1  local_4                   XREF[1]:     0044789b(*)  
    //              uchar *           Stack[-0x8]:4  pbWaveData
    //                               _DSReloadSoundBuffer
    //                              Dsutil.c:106 (1)
    //         00447890     PUSH       ECX
    //                              Dsutil.c:111 (33)
    //         00447891     MOV        EDX,dword ptr [ESP + Stack[0x8]]
    //         00447895     PUSH       ESI
    //         00447896     LEA        EAX=>Stack[0x8],[ESP + 0x10]
    //         0044789a     PUSH       EDI
    //         0044789b     LEA        ECX=>local_4,[ESP + 0x8]
    //         0044789f     XOR        ESI,ESI
    //         004478a1     PUSH       EAX
    //         004478a2     PUSH       ECX
    //         004478a3     PUSH       ESI
    //         004478a4     PUSH       EDX
    //         004478a5     PUSH       ESI
    //         004478a6     CALL       _DSGetWaveResource                               undefined _DSGetWaveResource()
    //         004478ab     ADD        ESP,0x14
    //         004478ae     TEST       EAX,EAX
    //         004478b0     JZ         LAB_004478dc
    //                              Dsutil.c:114 (37)
    //         004478b2     MOV        EDI,dword ptr [ESP + Stack[0x4]]
    //         004478b6     PUSH       EDI
    //         004478b7     MOV        EAX,dword ptr [EDI]
    //         004478b9     CALL       dword ptr [EAX + 0x50]
    //         004478bc     TEST       EAX,EAX
    //         004478be     JL         LAB_004478dc
    //         004478c0     MOV        ECX,dword ptr [ESP + 0x14]
    //         004478c4     MOV        EDX,dword ptr [ESP + 0x8]
    //         004478c8     PUSH       ECX
    //         004478c9     PUSH       EDX=>DAT_fffffff8
    //         004478ca     PUSH       EDI=>DAT_fffffff4
    //         004478cb     CALL       _DSFillSoundBuffer                               undefined _DSFillSoundBuffer()
    //         004478d0     ADD        ESP,0xc
    //         004478d3     TEST       EAX,EAX
    //         004478d5     JZ         LAB_004478dc
    //                              Dsutil.c:116 (5)
    //         004478d7     MOV        ESI,0x1
    //                               LAB_004478dc                                                 XREF[3]:     004478b0(j), 004478be(j), 
    //                                                                                                         004478d5(j)  
    //                              Dsutil.c:120 (2)
    //         004478dc     MOV        EAX,ESI
    //                              Dsutil.c:121 (4)
    //         004478de     POP        EDI
    //         004478df     POP        ESI
    //         004478e0     POP        ECX
    //         004478e1     RET
}

// Offset: 0x004478F0
undefined DSGetWaveResource() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined _DSGetWaveResource()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _DSGetWaveResource                                           XREF[3]:     _DSLoadSoundBuffer:0044781b(c), 
    //                                                                                                         _DSReloadSoundBuffer:004478a6(c), 
    //                                                                                                         _SndObjCreate:0044796e(c)  
    //                              Dsutil.c:131 (77)
    //         004478f0     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         004478f4     PUSH       ESI
    //         004478f5     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         004478f9     PUSH       PTR_FUN_00570428                                 = 00564157
    //         004478fe     PUSH       EAX
    //         004478ff     PUSH       ESI
    //         00447900     CALL       dword ptr [->KERNEL32.DLL::FindResourceA]        = 0048ab3c
    //         00447906     TEST       EAX,EAX
    //         00447908     JZ         LAB_00447944
    //         0044790a     PUSH       EAX
    //         0044790b     PUSH       ESI
    //         0044790c     CALL       dword ptr [->KERNEL32.DLL::LoadResource]         = 0048ab2c
    //         00447912     TEST       EAX,EAX
    //         00447914     JZ         LAB_00447944
    //         00447916     PUSH       EAX
    //         00447917     CALL       dword ptr [->KERNEL32.DLL::LockResource]         = 0048ab1c
    //         0044791d     TEST       EAX,EAX
    //         0044791f     JZ         LAB_00447944
    //         00447921     MOV        ECX,dword ptr [ESP + 0x18]
    //         00447925     MOV        EDX,dword ptr [ESP + 0x14]
    //         00447929     PUSH       ECX
    //         0044792a     MOV        ECX,dword ptr [ESP + 0x14]
    //         0044792e     PUSH       EDX=>DAT_fffffff8
    //         0044792f     PUSH       ECX=>DAT_fffffff4
    //         00447930     PUSH       EAX=>DAT_fffffff0
    //         00447931     CALL       _DSParseWaveResource                             undefined _DSParseWaveResource()
    //         00447936     ADD        ESP,0x10
    //         00447939     TEST       EAX,EAX
    //         0044793b     JZ         LAB_00447944
    //                              Dsutil.c:141 (5)
    //         0044793d     MOV        EAX,0x1
    //                              Dsutil.c:145 (2)
    //         00447942     POP        ESI
    //         00447943     RET
    //                               LAB_00447944                                                 XREF[4]:     00447908(j), 00447914(j), 
    //                                                                                                         0044791f(j), 0044793b(j)  
    //                              Dsutil.c:144 (2)
    //         00447944     XOR        EAX,EAX
    //                              Dsutil.c:145 (2)
    //         00447946     POP        ESI
    //         00447947     RET
}

// Offset: 0x00447950
undefined SndObjCreate() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined _SndObjCreate()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined         Stack[-0x4]:1  local_4                   XREF[1]:     0044795b(*)  
    //              tWAVEFORMATEX *   Stack[-0x8]:4  pWaveHeader               XREF[1]:     00447953(*)  
    //              uint              Stack[-0xc]:4  cbData                    XREF[1]:     00447957(*)  
    //              uchar *           Stack[-0x10]:4 pbData
    //                               _SndObjCreate
    //                              Dsutil.c:152 (3)
    //         00447950     SUB        ESP,0xc
    //                              Dsutil.c:158 (43)
    //         00447953     LEA        EAX=>pWaveHeader,[ESP + 0x4]
    //         00447957     LEA        ECX=>cbData,[ESP]
    //         0044795b     LEA        EDX=>local_4,[ESP + 0x8]
    //         0044795f     PUSH       EBX
    //         00447960     MOV        EBX,dword ptr [ESP + Stack[0x8]]
    //         00447964     PUSH       EBP
    //         00447965     PUSH       ESI
    //         00447966     PUSH       EDI
    //         00447967     PUSH       EAX
    //         00447968     PUSH       ECX
    //         00447969     XOR        ESI,ESI
    //         0044796b     PUSH       EDX
    //         0044796c     PUSH       EBX
    //         0044796d     PUSH       ESI
    //         0044796e     CALL       _DSGetWaveResource                               undefined _DSGetWaveResource()
    //         00447973     ADD        ESP,0x14
    //         00447976     TEST       EAX,EAX
    //         00447978     JZ         LAB_00447a11
    //                              Dsutil.c:160 (13)
    //         0044797e     MOV        EDI,dword ptr [ESP + Stack[0xc]]
    //         00447982     MOV        EBP,0x1
    //         00447987     CMP        EDI,EBP
    //         00447989     JGE        LAB_0044798d
    //                              Dsutil.c:161 (2)
    //         0044798b     MOV        EDI,EBP
    //                               LAB_0044798d                                                 XREF[1]:     00447989(j)  
    //                              Dsutil.c:164 (22)
    //         0044798d     LEA        EAX,[EDI*0x4 + 0x10]
    //         00447994     PUSH       EAX
    //         00447995     PUSH       0x40
    //         00447997     CALL       dword ptr [->KERNEL32.DLL::LocalAlloc]           = 0048ab80
    //         0044799d     MOV        ESI,EAX
    //         0044799f     TEST       ESI,ESI
    //         004479a1     JZ         LAB_00447a11
    //                              Dsutil.c:168 (3)
    //         004479a3     MOV        dword ptr [ESI + 0x8],EDI
    //                              Dsutil.c:169 (4)
    //         004479a6     MOV        ECX,dword ptr [ESP + 0x10]
    //                              Dsutil.c:171 (23)
    //         004479aa     PUSH       EBX
    //         004479ab     MOV        EBX,dword ptr [ESP + 0x24]
    //         004479af     MOV        dword ptr [ESI],ECX
    //         004479b1     MOV        EDX,dword ptr [ESP + 0x18]
    //         004479b5     PUSH       EBX=>DAT_fffffff8
    //         004479b6     MOV        dword ptr [ESI + 0x4],EDX
    //         004479b9     CALL       _DSLoadSoundBuffer                               undefined _DSLoadSoundBuffer()
    //         004479be     MOV        dword ptr [ESI + 0x10],EAX
    //                              Dsutil.c:173 (10)
    //         004479c1     MOV        EAX,dword ptr [ESI + 0x8]
    //         004479c4     ADD        ESP,0x8
    //         004479c7     CMP        EAX,EBP
    //         004479c9     JLE        LAB_00447a11
    //                              Dsutil.c:190 (3)
    //         004479cb     LEA        EDI,[ESI + 0x14]
    //                               LAB_004479ce                                                 XREF[1]:     004479fa(j)  
    //                              Dsutil.c:176 (15)
    //         004479ce     MOV        ECX,dword ptr [ESI + 0x10]
    //         004479d1     MOV        EAX,dword ptr [EBX]
    //         004479d3     PUSH       EDI
    //         004479d4     PUSH       ECX=>DAT_fffffff8
    //         004479d5     PUSH       EBX=>DAT_fffffff4
    //         004479d6     CALL       dword ptr [EAX + 0x14]
    //         004479d9     TEST       EAX,EAX
    //         004479db     JGE        LAB_004479f1
    //                              Dsutil.c:178 (16)
    //         004479dd     MOV        EDX,dword ptr [ESP + 0x24]
    //         004479e1     PUSH       EDX
    //         004479e2     PUSH       EBX=>DAT_fffffff8
    //         004479e3     CALL       _DSLoadSoundBuffer                               undefined _DSLoadSoundBuffer()
    //         004479e8     ADD        ESP,0x8
    //         004479eb     MOV        dword ptr [EDI],EAX
    //                              Dsutil.c:179 (4)
    //         004479ed     TEST       EAX,EAX
    //         004479ef     JZ         LAB_00447a06
    //                               LAB_004479f1                                                 XREF[1]:     004479db(j)  
    //                              Dsutil.c:173 (11)
    //         004479f1     MOV        EAX,dword ptr [ESI + 0x8]
    //         004479f4     INC        EBP
    //         004479f5     ADD        EDI,0x4
    //         004479f8     CMP        EBP,EAX
    //         004479fa     JL         LAB_004479ce
    //                              Dsutil.c:189 (2)
    //         004479fc     MOV        EAX,ESI
    //                              Dsutil.c:190 (8)
    //         004479fe     POP        EDI
    //         004479ff     POP        ESI
    //         00447a00     POP        EBP
    //         00447a01     POP        EBX
    //         00447a02     ADD        ESP,0xc
    //         00447a05     RET
    //                               LAB_00447a06                                                 XREF[1]:     004479ef(j)  
    //                              Dsutil.c:180 (9)
    //         00447a06     PUSH       ESI
    //         00447a07     CALL       _SndObjDestroy                                   undefined _SndObjDestroy()
    //         00447a0c     ADD        ESP,0x4
    //                              Dsutil.c:181 (2)
    //         00447a0f     XOR        ESI,ESI
    //                               LAB_00447a11                                                 XREF[3]:     00447978(j), 004479a1(j), 
    //                                                                                                         004479c9(j)  
    //                              Dsutil.c:189 (2)
    //         00447a11     MOV        EAX,ESI
    //                              Dsutil.c:190 (8)
    //         00447a13     POP        EDI
    //         00447a14     POP        ESI
    //         00447a15     POP        EBP
    //         00447a16     POP        EBX
    //         00447a17     ADD        ESP,0xc
    //         00447a1a     RET
}

// Offset: 0x00447A20
undefined SndObjDestroy() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined _SndObjDestroy()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _SndObjDestroy                                               XREF[1]:     _SndObjCreate:00447a07(c)  
    //                              Dsutil.c:196 (1)
    //         00447a20     PUSH       EBX
    //                              Dsutil.c:197 (8)
    //         00447a21     MOV        EBX,dword ptr [ESP + Stack[0x4]]
    //         00447a25     TEST       EBX,EBX
    //         00447a27     JZ         LAB_00447a5d
    //                              Dsutil.c:201 (11)
    //         00447a29     MOV        EAX,dword ptr [EBX + 0x8]
    //         00447a2c     PUSH       EDI
    //         00447a2d     XOR        EDI,EDI
    //         00447a2f     TEST       EAX,EAX
    //         00447a31     JLE        LAB_00447a55
    //         00447a33     PUSH       ESI
    //                              Dsutil.c:211 (32)
    //         00447a34     LEA        ESI,[EBX + 0x10]
    //                               LAB_00447a37                                                 XREF[1]:     00447a52(j)  
    //         00447a37     MOV        EAX,dword ptr [ESI]
    //         00447a39     TEST       EAX,EAX
    //         00447a3b     JZ         LAB_00447a49
    //         00447a3d     MOV        ECX,dword ptr [EAX]
    //         00447a3f     PUSH       EAX
    //         00447a40     CALL       dword ptr [ECX + 0x8]
    //         00447a43     MOV        dword ptr [ESI],0x0
    //                               LAB_00447a49                                                 XREF[1]:     00447a3b(j)  
    //         00447a49     MOV        EAX,dword ptr [EBX + 0x8]
    //         00447a4c     INC        EDI
    //         00447a4d     ADD        ESI,0x4
    //         00447a50     CMP        EDI,EAX
    //         00447a52     JL         LAB_00447a37
    //                              Dsutil.c:196 (1)
    //         00447a54     POP        ESI
    //                               LAB_00447a55                                                 XREF[1]:     00447a31(j)  
    //                              Dsutil.c:209 (8)
    //         00447a55     PUSH       EBX
    //         00447a56     CALL       dword ptr [->KERNEL32.DLL::LocalFree]            = 0048ab74
    //         00447a5c     POP        EDI
    //                               LAB_00447a5d                                                 XREF[1]:     00447a27(j)  
    //                              Dsutil.c:211 (2)
    //         00447a5d     POP        EBX
    //         00447a5e     RET
}

// Offset: 0x00447A60
undefined SndObjGetFreeBuffer() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined _SndObjGetFreeBuffer()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _SndObjGetFreeBuffer                                         XREF[1]:     _SndObjPlay:00447b3e(c)  
    //                              Dsutil.c:217 (1)
    //         00447a60     PUSH       EDI
    //                              Dsutil.c:220 (8)
    //         00447a61     MOV        EDI,dword ptr [ESP + Stack[0x4]]
    //         00447a65     TEST       EDI,EDI
    //         00447a67     JNZ        LAB_00447a6d
    //                              Dsutil.c:221 (2)
    //         00447a69     XOR        EAX,EAX
    //                              Dsutil.c:266 (2)
    //         00447a6b     POP        EDI
    //         00447a6c     RET
    //                               LAB_00447a6d                                                 XREF[1]:     00447a67(j)  
    //                              Dsutil.c:223 (16)
    //         00447a6d     MOV        EAX,dword ptr [EDI + 0xc]
    //         00447a70     PUSH       ESI
    //         00447a71     MOV        ESI,dword ptr [EDI + EAX*0x4 + 0x10]
    //         00447a75     TEST       ESI,ESI
    //         00447a77     JZ         LAB_00447b1a
    //                              Dsutil.c:228 (11)
    //         00447a7d     MOV        ECX,dword ptr [ESI]
    //         00447a7f     LEA        EDX=>Stack[0x4],[ESP + 0xc]
    //         00447a83     PUSH       EDX
    //         00447a84     PUSH       ESI
    //         00447a85     CALL       dword ptr [ECX + 0x24]
    //                              Dsutil.c:230 (4)
    //         00447a88     TEST       EAX,EAX
    //         00447a8a     JGE        LAB_00447a94
    //                              Dsutil.c:231 (8)
    //         00447a8c     MOV        dword ptr [ESP + 0xc],0x0
    //                               LAB_00447a94                                                 XREF[1]:     00447a8a(j)  
    //                              Dsutil.c:233 (11)
    //         00447a94     MOV        EAX,dword ptr [ESP + 0xc]
    //         00447a98     AND        EAX,0x1
    //         00447a9b     CMP        AL,0x1
    //         00447a9d     JNZ        LAB_00447aef
    //                              Dsutil.c:235 (8)
    //         00447a9f     MOV        EAX,dword ptr [EDI + 0x8]
    //         00447aa2     CMP        EAX,0x1
    //         00447aa5     JLE        LAB_00447aed
    //                              Dsutil.c:237 (13)
    //         00447aa7     MOV        EDX,dword ptr [EDI + 0xc]
    //         00447aaa     INC        EDX
    //         00447aab     MOV        ECX,EDX
    //         00447aad     MOV        dword ptr [EDI + 0xc],EDX
    //         00447ab0     CMP        ECX,EAX
    //         00447ab2     JL         LAB_00447abb
    //                              Dsutil.c:238 (7)
    //         00447ab4     MOV        dword ptr [EDI + 0xc],0x0
    //                               LAB_00447abb                                                 XREF[1]:     00447ab2(j)  
    //                              Dsutil.c:240 (3)
    //         00447abb     MOV        ECX,dword ptr [EDI + 0xc]
    //                              Dsutil.c:241 (15)
    //         00447abe     LEA        EAX,[ESP + 0xc]
    //         00447ac2     PUSH       EAX
    //         00447ac3     MOV        ESI,dword ptr [EDI + ECX*0x4 + 0x10]
    //         00447ac7     PUSH       ESI=>DAT_fffffff8
    //         00447ac8     MOV        EDX,dword ptr [ESI]
    //         00447aca     CALL       dword ptr [EDX + 0x24]
    //                              Dsutil.c:243 (16)
    //         00447acd     TEST       EAX,EAX
    //         00447acf     JL         LAB_00447aef
    //         00447ad1     MOV        ECX,dword ptr [ESP + 0xc]
    //         00447ad5     AND        ECX,0x1
    //         00447ad8     CMP        CL,0x1
    //         00447adb     JNZ        LAB_00447aef
    //                              Dsutil.c:245 (6)
    //         00447add     MOV        EDX,dword ptr [ESI]
    //         00447adf     PUSH       ESI
    //         00447ae0     CALL       dword ptr [EDX + 0x48]
    //                              Dsutil.c:246 (8)
    //         00447ae3     MOV        EAX,dword ptr [ESI]
    //         00447ae5     PUSH       0x0
    //         00447ae7     PUSH       ESI=>DAT_fffffff8
    //         00447ae8     CALL       dword ptr [EAX + 0x34]
    //                              Dsutil.c:249 (2)
    //         00447aeb     JMP        LAB_00447aef
    //                               LAB_00447aed                                                 XREF[1]:     00447aa5(j)  
    //                              Dsutil.c:251 (2)
    //         00447aed     XOR        ESI,ESI
    //                               LAB_00447aef                                                 XREF[4]:     00447a9d(j), 00447acf(j), 
    //                                                                                                         00447adb(j), 00447aeb(j)  
    //                              Dsutil.c:255 (11)
    //         00447aef     TEST       ESI,ESI
    //         00447af1     JZ         LAB_00447b1a
    //         00447af3     TEST       byte ptr [ESP + 0xc],0x2
    //         00447af8     JZ         LAB_00447b1a
    //                              Dsutil.c:258 (30)
    //         00447afa     MOV        ECX,dword ptr [ESI]
    //         00447afc     PUSH       ESI
    //         00447afd     CALL       dword ptr [ECX + 0x50]
    //         00447b00     TEST       EAX,EAX
    //         00447b02     JL         LAB_00447b18
    //         00447b04     MOV        EDX,dword ptr [EDI + 0x4]
    //         00447b07     MOV        EAX,dword ptr [EDI]
    //         00447b09     PUSH       EDX
    //         00447b0a     PUSH       EAX=>DAT_fffffff8
    //         00447b0b     PUSH       ESI=>DAT_fffffff4
    //         00447b0c     CALL       _DSFillSoundBuffer                               undefined _DSFillSoundBuffer()
    //         00447b11     ADD        ESP,0xc
    //         00447b14     TEST       EAX,EAX
    //         00447b16     JNZ        LAB_00447b1a
    //                               LAB_00447b18                                                 XREF[1]:     00447b02(j)  
    //                              Dsutil.c:260 (2)
    //         00447b18     XOR        ESI,ESI
    //                               LAB_00447b1a                                                 XREF[4]:     00447a77(j), 00447af1(j), 
    //                                                                                                         00447af8(j), 00447b16(j)  
    //                              Dsutil.c:265 (3)
    //         00447b1a     MOV        EAX,ESI
    //         00447b1c     POP        ESI
    //                              Dsutil.c:266 (2)
    //         00447b1d     POP        EDI
    //         00447b1e     RET
}

// Offset: 0x00447B20
undefined SndObjPlay() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined _SndObjPlay()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _SndObjPlay
    //                              Dsutil.c:272 (11)
    //         00447b20     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00447b24     PUSH       ESI
    //         00447b25     XOR        ESI,ESI
    //         00447b27     TEST       EAX,EAX
    //         00447b29     JNZ        LAB_00447b2d
    //                              Dsutil.c:287 (2)
    //         00447b2b     POP        ESI
    //         00447b2c     RET
    //                               LAB_00447b2d                                                 XREF[1]:     00447b29(j)  
    //                              Dsutil.c:272 (1)
    //         00447b2d     PUSH       EBX
    //                              Dsutil.c:278 (15)
    //         00447b2e     MOV        EBX,dword ptr [ESP + Stack[0x8]]
    //         00447b32     TEST       BL,0x1
    //         00447b35     JZ         LAB_00447b3d
    //         00447b37     CMP        dword ptr [EAX + 0x8],0x1
    //         00447b3b     JNZ        LAB_00447b5e
    //                               LAB_00447b3d                                                 XREF[1]:     00447b35(j)  
    //                              Dsutil.c:280 (9)
    //         00447b3d     PUSH       EAX
    //         00447b3e     CALL       _SndObjGetFreeBuffer                             undefined _SndObjGetFreeBuffer()
    //         00447b43     ADD        ESP,0x4
    //                              Dsutil.c:281 (4)
    //         00447b46     TEST       EAX,EAX
    //         00447b48     JZ         LAB_00447b5e
    //                              Dsutil.c:282 (20)
    //         00447b4a     MOV        ECX,dword ptr [EAX]
    //         00447b4c     PUSH       EBX
    //         00447b4d     PUSH       0x0
    //         00447b4f     PUSH       0x0
    //         00447b51     PUSH       EAX
    //         00447b52     CALL       dword ptr [ECX + 0x30]
    //         00447b55     XOR        EDX,EDX
    //         00447b57     TEST       EAX,EAX
    //         00447b59     SETGE      DL
    //         00447b5c     MOV        ESI,EDX
    //                               LAB_00447b5e                                                 XREF[2]:     00447b3b(j), 00447b48(j)  
    //                              Dsutil.c:286 (3)
    //         00447b5e     MOV        EAX,ESI
    //         00447b60     POP        EBX
    //                              Dsutil.c:287 (2)
    //         00447b61     POP        ESI
    //         00447b62     RET
}

// Offset: 0x00447B70
undefined SndObjStop() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined _SndObjStop()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _SndObjStop
    //                              Dsutil.c:293 (1)
    //         00447b70     PUSH       EBX
    //                              Dsutil.c:296 (8)
    //         00447b71     MOV        EBX,dword ptr [ESP + Stack[0x4]]
    //         00447b75     TEST       EBX,EBX
    //         00447b77     JNZ        LAB_00447b7d
    //                              Dsutil.c:297 (2)
    //         00447b79     XOR        EAX,EAX
    //                              Dsutil.c:306 (2)
    //         00447b7b     POP        EBX
    //         00447b7c     RET
    //                               LAB_00447b7d                                                 XREF[1]:     00447b77(j)  
    //                              Dsutil.c:299 (11)
    //         00447b7d     MOV        EAX,dword ptr [EBX + 0x8]
    //         00447b80     PUSH       EDI
    //         00447b81     XOR        EDI,EDI
    //         00447b83     TEST       EAX,EAX
    //         00447b85     JLE        LAB_00447ba9
    //         00447b87     PUSH       ESI
    //                              Dsutil.c:306 (32)
    //         00447b88     LEA        ESI,[EBX + 0x10]
    //                               LAB_00447b8b                                                 XREF[1]:     00447ba6(j)  
    //         00447b8b     MOV        EAX,dword ptr [ESI]
    //         00447b8d     PUSH       EAX
    //         00447b8e     MOV        ECX,dword ptr [EAX]
    //         00447b90     CALL       dword ptr [ECX + 0x48]
    //         00447b93     MOV        EAX,dword ptr [ESI]
    //         00447b95     PUSH       0x0
    //         00447b97     PUSH       EAX=>DAT_fffffff8
    //         00447b98     MOV        EDX,dword ptr [EAX]
    //         00447b9a     CALL       dword ptr [EDX + 0x34]
    //         00447b9d     MOV        EAX,dword ptr [EBX + 0x8]
    //         00447ba0     INC        EDI
    //         00447ba1     ADD        ESI,0x4
    //         00447ba4     CMP        EDI,EAX
    //         00447ba6     JL         LAB_00447b8b
    //                              Dsutil.c:293 (2)
    //         00447ba8     POP        ESI
    //                               LAB_00447ba9                                                 XREF[1]:     00447b85(j)  
    //         00447ba9     POP        EDI
    //                              Dsutil.c:305 (5)
    //         00447baa     MOV        EAX,0x1
    //                              Dsutil.c:306 (2)
    //         00447baf     POP        EBX
    //         00447bb0     RET
}

// Offset: 0x00447BC0
undefined DSFillSoundBuffer() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined _DSFillSoundBuffer()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined         Stack[-0x4]:1  local_4                   XREF[1]:     00447bf2(*)  
    //              void *            Stack[-0x8]:4  pMem1
    //                               _DSFillSoundBuffer                                           XREF[3]:     _DSLoadSoundBuffer:00447860(c), 
    //                                                                                                         _DSReloadSoundBuffer:004478cb(c), 
    //                                                                                                         _SndObjGetFreeBuffer:00447b0c(c)  
    //                              Dsutil.c:312 (2)
    //         00447bc0     PUSH       ECX
    //         00447bc1     PUSH       ESI
    //                              Dsutil.c:313 (29)
    //         00447bc2     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         00447bc6     TEST       ESI,ESI
    //         00447bc8     PUSH       EDI
    //         00447bc9     JZ         LAB_00447c55
    //         00447bcf     MOV        EDI,dword ptr [ESP + Stack[0x8]]
    //         00447bd3     TEST       EDI,EDI
    //         00447bd5     JZ         LAB_00447c55
    //         00447bd7     MOV        EAX,dword ptr [ESP + Stack[0xc]]
    //         00447bdb     TEST       EAX,EAX
    //         00447bdd     JZ         LAB_00447c55
    //                              Dsutil.c:319 (35)
    //         00447bdf     LEA        EDX=>Stack[0x8],[ESP + 0x14]
    //         00447be3     PUSH       0x0
    //         00447be5     PUSH       EDX
    //         00447be6     LEA        EDX=>Stack[0xc],[ESP + 0x20]
    //         00447bea     MOV        ECX,dword ptr [ESI]
    //         00447bec     PUSH       EDX
    //         00447bed     LEA        EDX=>Stack[0x4],[ESP + 0x1c]
    //         00447bf1     PUSH       EDX
    //         00447bf2     LEA        EDX=>local_4,[ESP + 0x18]
    //         00447bf6     PUSH       EDX
    //         00447bf7     PUSH       EAX
    //         00447bf8     PUSH       0x0
    //         00447bfa     PUSH       ESI
    //         00447bfb     CALL       dword ptr [ECX + 0x2c]
    //         00447bfe     TEST       EAX,EAX
    //         00447c00     JL         LAB_00447c55
    //                              Dsutil.c:321 (16)
    //         00447c02     MOV        EAX,dword ptr [ESP + 0x10]
    //         00447c06     MOV        ECX,dword ptr [ESP + 0x8]
    //         00447c0a     PUSH       EAX
    //         00447c0b     PUSH       EDI=>DAT_fffffff8
    //         00447c0c     PUSH       ECX=>DAT_fffffff4
    //         00447c0d     CALL       memcpy                                           undefined memcpy()
    //                              Dsutil.c:323 (11)
    //         00447c12     MOV        EAX,dword ptr [ESP + 0x20]
    //         00447c16     ADD        ESP,0xc
    //         00447c19     TEST       EAX,EAX
    //         00447c1b     JZ         LAB_00447c36
    //                              Dsutil.c:324 (25)
    //         00447c1d     MOV        EDX,dword ptr [ESP + 0x10]
    //         00447c21     PUSH       EAX
    //         00447c22     MOV        EAX,dword ptr [ESP + 0x1c]
    //         00447c26     ADD        EDX,EDI
    //         00447c28     PUSH       EDX=>DAT_fffffff8
    //         00447c29     PUSH       EAX=>DAT_fffffff4
    //         00447c2a     CALL       memcpy                                           undefined memcpy()
    //         00447c2f     MOV        EAX,dword ptr [ESP + 0x20]
    //         00447c33     ADD        ESP,0xc
    //                               LAB_00447c36                                                 XREF[1]:     00447c1b(j)  
    //                              Dsutil.c:326 (22)
    //         00447c36     MOV        EDX,dword ptr [ESP + 0x18]
    //         00447c3a     MOV        ECX,dword ptr [ESI]
    //         00447c3c     PUSH       EAX
    //         00447c3d     MOV        EAX,dword ptr [ESP + 0x14]
    //         00447c41     PUSH       EDX=>DAT_fffffff8
    //         00447c42     MOV        EDX,dword ptr [ESP + 0x10]
    //         00447c46     PUSH       EAX=>DAT_fffffff4
    //         00447c47     PUSH       EDX=>DAT_fffffff0
    //         00447c48     PUSH       ESI
    //         00447c49     CALL       dword ptr [ECX + 0x4c]
    //                              Dsutil.c:327 (5)
    //         00447c4c     MOV        EAX,0x1
    //                              Dsutil.c:332 (10)
    //         00447c51     POP        EDI
    //         00447c52     POP        ESI
    //         00447c53     POP        ECX
    //         00447c54     RET
    //                               LAB_00447c55                                                 XREF[4]:     00447bc9(j), 00447bd5(j), 
    //                                                                                                         00447bdd(j), 00447c00(j)  
    //         00447c55     POP        EDI
    //         00447c56     XOR        EAX,EAX
    //         00447c58     POP        ESI
    //         00447c59     POP        ECX
    //         00447c5a     RET
}

// Offset: 0x00447C60
undefined DSParseWaveResource() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined _DSParseWaveResource()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _DSParseWaveResource                                         XREF[1]:     _DSGetWaveResource:00447931(c)  
    //                              Dsutil.c:338 (2)
    //         00447c60     PUSH       EBX
    //         00447c61     PUSH       EBP
    //                              Dsutil.c:345 (10)
    //         00447c62     MOV        EBP,dword ptr [ESP + Stack[0x8]]
    //         00447c66     PUSH       ESI
    //         00447c67     TEST       EBP,EBP
    //         00447c69     PUSH       EDI
    //         00447c6a     JZ         LAB_00447c73
    //                              Dsutil.c:346 (7)
    //         00447c6c     MOV        dword ptr [EBP],0x0
    //                               LAB_00447c73                                                 XREF[1]:     00447c6a(j)  
    //                              Dsutil.c:348 (8)
    //         00447c73     MOV        EDI,dword ptr [ESP + Stack[0xc]]
    //         00447c77     TEST       EDI,EDI
    //         00447c79     JZ         LAB_00447c81
    //                              Dsutil.c:349 (6)
    //         00447c7b     MOV        dword ptr [EDI],0x0
    //                               LAB_00447c81                                                 XREF[1]:     00447c79(j)  
    //                              Dsutil.c:351 (8)
    //         00447c81     MOV        EBX,dword ptr [ESP + Stack[0x10]]
    //         00447c85     TEST       EBX,EBX
    //         00447c87     JZ         LAB_00447c8f
    //                              Dsutil.c:352 (6)
    //         00447c89     MOV        dword ptr [EBX],0x0
    //                               LAB_00447c8f                                                 XREF[1]:     00447c87(j)  
    //                              Dsutil.c:355 (4)
    //         00447c8f     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //                              Dsutil.c:356 (9)
    //         00447c93     MOV        EDX,dword ptr [ECX + 0x4]
    //         00447c96     LEA        EAX,[ECX + 0x4]
    //         00447c99     ADD        EAX,0x4
    //                              Dsutil.c:357 (5)
    //         00447c9c     MOV        ESI,dword ptr [EAX]
    //         00447c9e     ADD        EAX,0x4
    //                              Dsutil.c:359 (12)
    //         00447ca1     CMP        dword ptr [ECX],0x46464952
    //         00447ca7     JNZ        LAB_00447d49
    //                              Dsutil.c:362 (12)
    //         00447cad     CMP        ESI,0x45564157
    //         00447cb3     JNZ        LAB_00447d49
    //                              Dsutil.c:365 (4)
    //         00447cb9     LEA        ESI,[EDX + EAX*0x1 + -0x4]
    //                              Dsutil.c:367 (8)
    //         00447cbd     CMP        EAX,ESI
    //         00447cbf     JNC        LAB_00447d49
    //                               LAB_00447cc5                                                 XREF[1]:     00447d36(j)  
    //                              Dsutil.c:369 (2)
    //         00447cc5     MOV        ECX,dword ptr [EAX]
    //                              Dsutil.c:370 (9)
    //         00447cc7     MOV        EDX,dword ptr [EAX + 0x4]
    //         00447cca     ADD        EAX,0x4
    //         00447ccd     ADD        EAX,0x4
    //                              Dsutil.c:372 (16)
    //         00447cd0     CMP        ECX,0x20746d66
    //         00447cd6     JZ         LAB_00447d0a
    //         00447cd8     CMP        ECX,0x61746164
    //         00447cde     JNZ        LAB_00447d2e
    //                              Dsutil.c:392 (18)
    //         00447ce0     TEST       EDI,EDI
    //         00447ce2     JZ         LAB_00447ce9
    //         00447ce4     CMP        dword ptr [EDI],0x0
    //         00447ce7     JZ         LAB_00447cf2
    //                               LAB_00447ce9                                                 XREF[1]:     00447ce2(j)  
    //         00447ce9     TEST       EBX,EBX
    //         00447ceb     JZ         LAB_00447d2e
    //         00447ced     CMP        dword ptr [EBX],0x0
    //         00447cf0     JNZ        LAB_00447d2e
    //                               LAB_00447cf2                                                 XREF[1]:     00447ce7(j)  
    //                              Dsutil.c:394 (4)
    //         00447cf2     TEST       EDI,EDI
    //         00447cf4     JZ         LAB_00447cf8
    //                              Dsutil.c:395 (2)
    //         00447cf6     MOV        dword ptr [EDI],EAX
    //                               LAB_00447cf8                                                 XREF[1]:     00447cf4(j)  
    //                              Dsutil.c:397 (4)
    //         00447cf8     TEST       EBX,EBX
    //         00447cfa     JZ         LAB_00447cfe
    //                              Dsutil.c:398 (2)
    //         00447cfc     MOV        dword ptr [EBX],EDX
    //                               LAB_00447cfe                                                 XREF[1]:     00447cfa(j)  
    //                              Dsutil.c:400 (10)
    //         00447cfe     TEST       EBP,EBP
    //         00447d00     JZ         LAB_00447d3f
    //         00447d02     CMP        dword ptr [EBP],0x0
    //         00447d06     JNZ        LAB_00447d3f
    //                              Dsutil.c:403 (2)
    //         00447d08     JMP        LAB_00447d2e
    //                               LAB_00447d0a                                                 XREF[1]:     00447cd6(j)  
    //                              Dsutil.c:375 (10)
    //         00447d0a     TEST       EBP,EBP
    //         00447d0c     JZ         LAB_00447d2e
    //         00447d0e     CMP        dword ptr [EBP],0x0
    //         00447d12     JNZ        LAB_00447d2e
    //                              Dsutil.c:377 (5)
    //         00447d14     CMP        EDX,0xe
    //         00447d17     JC         LAB_00447d49
    //                              Dsutil.c:383 (21)
    //         00447d19     TEST       EDI,EDI
    //         00447d1b     MOV        dword ptr [EBP],EAX
    //         00447d1e     JZ         LAB_00447d25
    //         00447d20     CMP        dword ptr [EDI],0x0
    //         00447d23     JZ         LAB_00447d2e
    //                               LAB_00447d25                                                 XREF[1]:     00447d1e(j)  
    //         00447d25     TEST       EBX,EBX
    //         00447d27     JZ         LAB_00447d3f
    //         00447d29     CMP        dword ptr [EBX],0x0
    //         00447d2c     JNZ        LAB_00447d3f
    //                               LAB_00447d2e                                                 XREF[7]:     00447cde(j), 00447ceb(j), 
    //                                                                                                         00447cf0(j), 00447d08(j), 
    //                                                                                                         00447d0c(j), 00447d12(j), 
    //                                                                                                         00447d23(j)  
    //                              Dsutil.c:406 (10)
    //         00447d2e     INC        EDX
    //         00447d2f     AND        EDX,0xfffffffe
    //         00447d32     ADD        EAX,EDX
    //         00447d34     CMP        EAX,ESI
    //         00447d36     JC         LAB_00447cc5
    //                              Dsutil.c:410 (2)
    //         00447d38     XOR        EAX,EAX
    //                              Dsutil.c:411 (5)
    //         00447d3a     POP        EDI
    //         00447d3b     POP        ESI
    //         00447d3c     POP        EBP
    //         00447d3d     POP        EBX
    //         00447d3e     RET
    //                               LAB_00447d3f                                                 XREF[4]:     00447d00(j), 00447d06(j), 
    //                                                                                                         00447d27(j), 00447d2c(j)  
    //                              Dsutil.c:385 (5)
    //         00447d3f     MOV        EAX,0x1
    //                              Dsutil.c:411 (12)
    //         00447d44     POP        EDI
    //         00447d45     POP        ESI
    //         00447d46     POP        EBP
    //         00447d47     POP        EBX
    //         00447d48     RET
    //                              Symbol Ref: No symbol: exit
    //                               LAB_00447d49                                                 XREF[4]:     00447ca7(j), 00447cb3(j), 
    //                                                                                                         00447cbf(j), 00447d17(j)  
    //         00447d49     POP        EDI
    //         00447d4a     POP        ESI
    //         00447d4b     POP        EBP
    //         00447d4c     XOR        EAX,EAX
    //         00447d4e     POP        EBX
    //         00447d4f     RET
}

// Offset: 0x00447D50
undefined WaveOpenFile() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined _WaveOpenFile()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              _MMCKINFO         Stack[-0x18]   ckIn
    //              pcmwaveformat_    Stack[-0x28]   pcmWaveFormat
    //                               _WaveOpenFile                                                XREF[2]:     _WaveLoadFile:00448506(c), 
    //                                                                                                         ds_stream_file:00448731(c)  
    //                              Dsutil.c:496 (4)
    //         00447d50     MOV        EAX,dword ptr [ESP + Stack[0xc]]
    //                              Dsutil.c:509 (37)
    //         00447d54     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         00447d58     SUB        ESP,0x24
    //         00447d5b     MOV        dword ptr [EAX],0x0
    //         00447d61     PUSH       EBX
    //         00447d62     PUSH       EBP
    //         00447d63     PUSH       ESI
    //         00447d64     PUSH       EDI
    //         00447d65     PUSH       0x10000
    //         00447d6a     PUSH       0x0
    //         00447d6c     PUSH       ECX
    //         00447d6d     CALL       dword ptr [->WINMM.DLL::mmioOpenA]               = 0048b48e
    //         00447d73     MOV        EDI,EAX
    //         00447d75     TEST       EDI,EDI
    //         00447d77     JNZ        LAB_00447d83
    //                              Dsutil.c:511 (5)
    //         00447d79     MOV        ESI,0xe100
    //                              Dsutil.c:512 (5)
    //         00447d7e     JMP        LAB_00447eb8
    //                               LAB_00447d83                                                 XREF[1]:     00447d77(j)  
    //                              Dsutil.c:515 (28)
    //         00447d83     MOV        EBX,dword ptr [ESP + 0x44]
    //         00447d87     MOV        EBP,dword ptr [->WINMM.DLL::mmioDescend]         = 0048b480
    //         00447d8d     PUSH       0x0
    //         00447d8f     PUSH       0x0
    //         00447d91     PUSH       EBX
    //         00447d92     PUSH       EDI
    //         00447d93     CALL       EBP=>WINMM.DLL::mmioDescend
    //         00447d95     MOV        ESI,EAX
    //         00447d97     TEST       ESI,ESI
    //         00447d99     JNZ        LAB_00447eb8
    //                              Dsutil.c:521 (25)
    //         00447d9f     CMP        dword ptr [EBX],0x46464952
    //         00447da5     JNZ        LAB_00447eb3
    //         00447dab     CMP        dword ptr [EBX + 0x8],0x45564157
    //         00447db2     JNZ        LAB_00447eb3
    //                              Dsutil.c:529 (29)
    //         00447db8     PUSH       0x10
    //         00447dba     LEA        EDX,[ESP + 0x24]
    //         00447dbe     PUSH       EBX
    //         00447dbf     PUSH       EDX
    //         00447dc0     PUSH       EDI
    //         00447dc1     MOV        dword ptr [ESP + 0x30],0x20746d66
    //         00447dc9     CALL       EBP=>WINMM.DLL::mmioDescend
    //         00447dcb     MOV        ESI,EAX
    //         00447dcd     TEST       ESI,ESI
    //         00447dcf     JNZ        LAB_00447eb8
    //                              Dsutil.c:537 (5)
    //         00447dd5     CMP        dword ptr [ESP + 0x24],0x10
    //                              Dsutil.c:540 (6)
    //         00447dda     JC         LAB_00447eb3
    //                              Dsutil.c:544 (21)
    //         00447de0     MOV        EBX,dword ptr [->WINMM.DLL::mmioRead]            = 0048b474
    //         00447de6     LEA        EAX,[ESP + 0x10]
    //         00447dea     PUSH       0x10
    //         00447dec     PUSH       EAX
    //         00447ded     PUSH       EDI
    //         00447dee     CALL       EBX=>WINMM.DLL::mmioRead
    //         00447df0     CMP        EAX,0x10
    //         00447df3     JZ         LAB_00447dff
    //                              Dsutil.c:546 (5)
    //         00447df5     MOV        ESI,0xe102
    //                              Dsutil.c:547 (5)
    //         00447dfa     JMP        LAB_00447eb8
    //                               LAB_00447dff                                                 XREF[1]:     00447df3(j)  
    //                              Dsutil.c:554 (8)
    //         00447dff     CMP        word ptr [ESP + 0x10],0x1
    //         00447e05     JNZ        LAB_00447e0f
    //                              Dsutil.c:555 (6)
    //         00447e07     XOR        EAX,EAX
    //         00447e09     MOV        dword ptr [ESP + 0x38],EAX
    //                              Dsutil.c:557 (2)
    //         00447e0d     JMP        LAB_00447e2c
    //                               LAB_00447e0f                                                 XREF[1]:     00447e05(j)  
    //                              Dsutil.c:561 (15)
    //         00447e0f     LEA        ECX,[ESP + 0x38]
    //         00447e13     PUSH       0x2
    //         00447e15     PUSH       ECX
    //         00447e16     PUSH       EDI
    //         00447e17     CALL       EBX=>WINMM.DLL::mmioRead
    //         00447e19     CMP        EAX,0x2
    //         00447e1c     JZ         LAB_00447e28
    //                              Dsutil.c:563 (5)
    //         00447e1e     MOV        ESI,0xe102
    //                              Dsutil.c:564 (9)
    //         00447e23     JMP        LAB_00447eb8
    //                               LAB_00447e28                                                 XREF[1]:     00447e1c(j)  
    //         00447e28     MOV        EAX,dword ptr [ESP + 0x38]
    //                               LAB_00447e2c                                                 XREF[1]:     00447e0d(j)  
    //                              Dsutil.c:570 (27)
    //         00447e2c     AND        EAX,0xffff
    //         00447e31     ADD        EAX,0x12
    //         00447e34     PUSH       EAX
    //         00447e35     PUSH       0x0
    //         00447e37     CALL       dword ptr [->KERNEL32.DLL::GlobalAlloc]          = 0048ab8e
    //         00447e3d     MOV        ESI,dword ptr [ESP + 0x40]
    //         00447e41     TEST       EAX,EAX
    //         00447e43     MOV        dword ptr [ESI],EAX
    //         00447e45     JNZ        LAB_00447e4e
    //                              Dsutil.c:572 (5)
    //         00447e47     MOV        ESI,0xe000
    //                              Dsutil.c:573 (2)
    //         00447e4c     JMP        LAB_00447eb8
    //                               LAB_00447e4e                                                 XREF[1]:     00447e45(j)  
    //                              Dsutil.c:577 (13)
    //         00447e4e     LEA        EDX,[ESP + 0x10]
    //         00447e52     PUSH       0x10
    //         00447e54     PUSH       EDX
    //         00447e55     PUSH       EAX
    //         00447e56     CALL       memcpy                                           undefined memcpy()
    //                              Dsutil.c:578 (14)
    //         00447e5b     MOV        EAX,dword ptr [ESI]
    //         00447e5d     MOV        CX,word ptr [ESP + 0x44]
    //         00447e62     ADD        ESP,0xc
    //         00447e65     MOV        word ptr [EAX + 0x10],CX
    //                              Dsutil.c:581 (9)
    //         00447e69     MOV        EAX,dword ptr [ESP + 0x38]
    //         00447e6d     TEST       AX,AX
    //         00447e70     JZ         LAB_00447e8f
    //                              Dsutil.c:584 (27)
    //         00447e72     MOV        EDX,dword ptr [ESI]
    //         00447e74     AND        EAX,0xffff
    //         00447e79     ADD        EDX,0x12
    //         00447e7c     PUSH       EAX
    //         00447e7d     PUSH       EDX
    //         00447e7e     PUSH       EDI
    //         00447e7f     CALL       EBX=>WINMM.DLL::mmioRead
    //         00447e81     MOV        ECX,dword ptr [ESP + 0x38]
    //         00447e85     AND        ECX,0xffff
    //         00447e8b     CMP        EAX,ECX
    //                              Dsutil.c:587 (2)
    //         00447e8d     JNZ        LAB_00447eb3
    //                               LAB_00447e8f                                                 XREF[1]:     00447e70(j)  
    //                              Dsutil.c:592 (20)
    //         00447e8f     LEA        EDX,[ESP + 0x20]
    //         00447e93     PUSH       0x0
    //         00447e95     PUSH       EDX
    //         00447e96     PUSH       EDI
    //         00447e97     CALL       dword ptr [->WINMM.DLL::mmioAscend]              = 0048b466
    //         00447e9d     MOV        ESI,EAX
    //         00447e9f     TEST       ESI,ESI
    //         00447ea1     JNZ        LAB_00447eb8
    //                              Dsutil.c:615 (6)
    //         00447ea3     MOV        EAX,dword ptr [ESP + 0x3c]
    //         00447ea7     MOV        dword ptr [EAX],EDI
    //                              Dsutil.c:617 (2)
    //         00447ea9     MOV        EAX,ESI
    //                              Dsutil.c:619 (8)
    //         00447eab     POP        EDI
    //         00447eac     POP        ESI
    //         00447ead     POP        EBP
    //         00447eae     POP        EBX
    //         00447eaf     ADD        ESP,0x24
    //         00447eb2     RET
    //                               LAB_00447eb3                                                 XREF[4]:     00447da5(j), 00447db2(j), 
    //                                                                                                         00447dda(j), 00447e8d(j)  
    //                              Dsutil.c:523 (5)
    //         00447eb3     MOV        ESI,0xe101
    //                              Symbol Ref: No symbol: ERROR_READING_WAVE
    //                               LAB_00447eb8                                                 XREF[7]:     00447d7e(j), 00447d99(j), 
    //                                                                                                         00447dcf(j), 00447dfa(j), 
    //                                                                                                         00447e23(j), 00447e4c(j), 
    //                                                                                                         00447ea1(j)  
    //                              Dsutil.c:602 (10)
    //         00447eb8     MOV        EBX,dword ptr [ESP + 0x40]
    //         00447ebc     MOV        EAX,dword ptr [EBX]
    //         00447ebe     TEST       EAX,EAX
    //         00447ec0     JZ         LAB_00447ecf
    //                              Dsutil.c:604 (7)
    //         00447ec2     PUSH       EAX
    //         00447ec3     CALL       dword ptr [->KERNEL32.DLL::GlobalFree]           = 0048aad0
    //                              Dsutil.c:605 (6)
    //         00447ec9     MOV        dword ptr [EBX],0x0
    //                               LAB_00447ecf                                                 XREF[1]:     00447ec0(j)  
    //                              Dsutil.c:608 (4)
    //         00447ecf     TEST       EDI,EDI
    //         00447ed1     JZ         LAB_00447ede
    //                              Dsutil.c:610 (9)
    //         00447ed3     PUSH       0x0
    //         00447ed5     PUSH       EDI
    //         00447ed6     CALL       dword ptr [->WINMM.DLL::mmioClose]               = 0048b45a
    //                              Dsutil.c:611 (2)
    //         00447edc     XOR        EDI,EDI
    //                              Symbol Ref: No symbol: TEMPCLEANUP
    //                               LAB_00447ede                                                 XREF[1]:     00447ed1(j)  
    //                              Dsutil.c:615 (6)
    //         00447ede     MOV        EAX,dword ptr [ESP + 0x3c]
    //         00447ee2     MOV        dword ptr [EAX],EDI
    //                              Dsutil.c:617 (2)
    //         00447ee4     MOV        EAX,ESI
    //                              Dsutil.c:619 (8)
    //         00447ee6     POP        EDI
    //         00447ee7     POP        ESI
    //         00447ee8     POP        EBP
    //         00447ee9     POP        EBX
    //         00447eea     ADD        ESP,0x24
    //         00447eed     RET
}

// Offset: 0x00447EF0
undefined WaveStartDataRead() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined _WaveStartDataRead()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _WaveStartDataRead                                           XREF[5]:     _WaveLoadFile:00448523(c), 
    //                                                                                                         ds_stream_file:00448782(c), 
    //                                                                                                         ds_stream_file:004488de(c), 
    //                                                                                                         ds_stream_time_func:00448eae(c), 
    //                                                                                                         ds_stream_time_func:00449010(c)  
    //                              Dsutil.c:631 (1)
    //         00447ef0     PUSH       ESI
    //                              Dsutil.c:637 (32)
    //         00447ef1     MOV        ESI,dword ptr [ESP + Stack[0xc]]
    //         00447ef5     PUSH       EDI
    //         00447ef6     MOV        EDI,dword ptr [ESP + Stack[0x4]]
    //         00447efa     MOV        EAX,dword ptr [ESI + 0xc]
    //         00447efd     PUSH       0x0
    //         00447eff     MOV        ECX,dword ptr [EDI]
    //         00447f01     ADD        EAX,0x4
    //         00447f04     PUSH       EAX
    //         00447f05     PUSH       ECX
    //         00447f06     CALL       dword ptr [->WINMM.DLL::mmioSeek]                = 0048b49a
    //         00447f0c     CMP        EAX,-0x1
    //         00447f0f     JNZ        LAB_00447f19
    //                              Dsutil.c:640 (5)
    //         00447f11     MOV        EAX,0x1
    //                              Dsutil.c:657 (3)
    //         00447f16     POP        EDI
    //         00447f17     POP        ESI
    //         00447f18     RET
    //                               LAB_00447f19                                                 XREF[1]:     00447f0f(j)  
    //                              Dsutil.c:645 (4)
    //         00447f19     MOV        EAX,dword ptr [ESP + 0x10]
    //                              Dsutil.c:646 (19)
    //         00447f1d     PUSH       0x10
    //         00447f1f     PUSH       ESI=>DAT_fffffff8
    //         00447f20     PUSH       EAX=>DAT_fffffff4
    //         00447f21     MOV        dword ptr [EAX],0x61746164
    //         00447f27     MOV        EDX,dword ptr [EDI]
    //         00447f29     PUSH       EDX=>DAT_fffffff0
    //         00447f2a     CALL       dword ptr [->WINMM.DLL::mmioDescend]             = 0048b480
    //                              Dsutil.c:657 (3)
    //         00447f30     POP        EDI
    //         00447f31     POP        ESI
    //         00447f32     RET
}

// Offset: 0x00447F40
undefined WaveReadFile() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined _WaveReadFile()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              _MMIOINFO         Stack[-0x4c]   mmioinfoIn                XREF[0,1]:   00447f47(*)  
    //                               _WaveReadFile                                                XREF[7]:     _WaveLoadFile:0044855f(c), 
    //                                                                                                         ds_stream_file:004488a3(c), 
    //                                                                                                         ds_stream_file:004488fd(c), 
    //                                                                                                         ds_stream_time_func:00448de9(c), 
    //                                                                                                         ds_stream_time_func:00448ecd(c), 
    //                                                                                                         ds_stream_time_func:00448f47(c), 
    //                                                                                                         ds_stream_time_func:0044902f(c)  
    //                              Dsutil.c:680 (37)
    //         00447f40     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         00447f44     SUB        ESP,0x48
    //         00447f47     LEA        EAX=>mmioinfoIn.fccIOProc,[ESP]
    //         00447f4b     PUSH       EBX
    //         00447f4c     PUSH       EBP
    //         00447f4d     PUSH       ESI
    //         00447f4e     PUSH       EDI
    //         00447f4f     PUSH       0x0
    //         00447f51     PUSH       EAX
    //         00447f52     PUSH       ECX
    //         00447f53     CALL       dword ptr [->WINMM.DLL::mmioGetInfo]             = 0048b4c2
    //         00447f59     NEG        EAX
    //         00447f5b     SBB        EAX,EAX
    //         00447f5d     NEG        EAX
    //         00447f5f     JNZ        LAB_00447ffb
    //                              Dsutil.c:694 (15)
    //         00447f65     MOV        ECX,dword ptr [ESP + 0x68]
    //         00447f69     MOV        EBX,dword ptr [ESP + 0x60]
    //         00447f6d     MOV        EAX,dword ptr [ECX + 0x4]
    //         00447f70     CMP        EBX,EAX
    //         00447f72     JBE        LAB_00447f76
    //                              Dsutil.c:695 (2)
    //         00447f74     MOV        EBX,EAX
    //                               LAB_00447f76                                                 XREF[1]:     00447f72(j)  
    //                              Dsutil.c:697 (2)
    //         00447f76     SUB        EAX,EBX
    //                              Dsutil.c:699 (17)
    //         00447f78     XOR        EDI,EDI
    //         00447f7a     TEST       EBX,EBX
    //         00447f7c     MOV        dword ptr [ECX + 0x4],EAX
    //         00447f7f     JBE        LAB_00447fe5
    //         00447f81     MOV        EBP,dword ptr [ESP + 0x64]
    //         00447f85     MOV        ECX,dword ptr [ESP + 0x2c]
    //                               LAB_00447f89                                                 XREF[1]:     00447fe3(j)  
    //                              Dsutil.c:702 (8)
    //         00447f89     MOV        ESI,dword ptr [ESP + 0x30]
    //         00447f8d     CMP        ECX,ESI
    //         00447f8f     JNZ        LAB_00447fb3
    //                              Dsutil.c:704 (22)
    //         00447f91     MOV        EAX,dword ptr [ESP + 0x5c]
    //         00447f95     LEA        EDX,[ESP + 0x10]
    //         00447f99     PUSH       0x0
    //         00447f9b     PUSH       EDX=>DAT_fffffff8
    //         00447f9c     PUSH       EAX=>DAT_fffffff4
    //         00447f9d     CALL       dword ptr [->WINMM.DLL::mmioAdvance]             = 0048b4b4
    //         00447fa3     TEST       EAX,EAX
    //         00447fa5     JNZ        LAB_00447ffb
    //                              Dsutil.c:708 (12)
    //         00447fa7     MOV        ECX,dword ptr [ESP + 0x2c]
    //         00447fab     MOV        ESI,dword ptr [ESP + 0x30]
    //         00447faf     CMP        ECX,ESI
    //         00447fb1     JZ         LAB_0044801b
    //                               LAB_00447fb3                                                 XREF[1]:     00447f8f(j)  
    //                              Dsutil.c:717 (6)
    //         00447fb3     MOV        EAX,EBX
    //         00447fb5     SUB        ESI,ECX
    //         00447fb7     SUB        EAX,EDI
    //                              Dsutil.c:718 (4)
    //         00447fb9     CMP        EAX,ESI
    //         00447fbb     JNC        LAB_00447fc7
    //                              Dsutil.c:721 (8)
    //         00447fbd     PUSH       EAX
    //         00447fbe     PUSH       ECX=>DAT_fffffff8
    //         00447fbf     LEA        ECX,[EDI + EBP*0x1]
    //         00447fc2     MOV        ESI,EAX
    //         00447fc4     PUSH       ECX=>DAT_fffffff4
    //                              Dsutil.c:723 (2)
    //         00447fc5     JMP        LAB_00447fcd
    //                               LAB_00447fc7                                                 XREF[1]:     00447fbb(j)  
    //                              Dsutil.c:725 (11)
    //         00447fc7     PUSH       ESI
    //         00447fc8     LEA        EDX,[EDI + EBP*0x1]
    //         00447fcb     PUSH       ECX=>DAT_fffffff8
    //         00447fcc     PUSH       EDX=>DAT_fffffff4
    //                               LAB_00447fcd                                                 XREF[1]:     00447fc5(j)  
    //         00447fcd     CALL       memcpy                                           undefined memcpy()
    //                              Dsutil.c:728 (19)
    //         00447fd2     MOV        ECX,dword ptr [ESP + 0x38]
    //         00447fd6     ADD        EDI,ESI
    //         00447fd8     ADD        ESP,0xc
    //         00447fdb     ADD        ECX,ESI
    //         00447fdd     CMP        EDI,EBX
    //         00447fdf     MOV        dword ptr [ESP + 0x2c],ECX
    //         00447fe3     JC         LAB_00447f89
    //                               LAB_00447fe5                                                 XREF[1]:     00447f7f(j)  
    //                              Dsutil.c:731 (22)
    //         00447fe5     MOV        ECX,dword ptr [ESP + 0x5c]
    //         00447fe9     LEA        EAX,[ESP + 0x10]
    //         00447fed     PUSH       0x0
    //         00447fef     PUSH       EAX=>DAT_fffffff8
    //         00447ff0     PUSH       ECX=>DAT_fffffff4
    //         00447ff1     CALL       dword ptr [->WINMM.DLL::mmioSetInfo]             = 0048b4a6
    //         00447ff7     TEST       EAX,EAX
    //         00447ff9     JZ         LAB_0044800d
    //                              Symbol Ref: No symbol: ERROR_CANNOT_READ
    //                               LAB_00447ffb                                                 XREF[2]:     00447f5f(j), 00447fa5(j)  
    //                              Dsutil.c:740 (10)
    //         00447ffb     MOV        EDX,dword ptr [ESP + 0x6c]
    //         00447fff     MOV        dword ptr [EDX],0x0
    //                              Dsutil.c:745 (8)
    //         00448005     POP        EDI
    //         00448006     POP        ESI
    //         00448007     POP        EBP
    //         00448008     POP        EBX
    //         00448009     ADD        ESP,0x48
    //         0044800c     RET
    //                               LAB_0044800d                                                 XREF[1]:     00447ff9(j)  
    //                              Dsutil.c:736 (6)
    //         0044800d     MOV        ECX,dword ptr [ESP + 0x6c]
    //         00448011     MOV        dword ptr [ECX],EBX
    //                              Dsutil.c:745 (8)
    //         00448013     POP        EDI
    //         00448014     POP        ESI
    //         00448015     POP        EBP
    //         00448016     POP        EBX
    //         00448017     ADD        ESP,0x48
    //         0044801a     RET
    //                               LAB_0044801b                                                 XREF[1]:     00447fb1(j)  
    //                              Dsutil.c:740 (4)
    //         0044801b     MOV        EDX,dword ptr [ESP + 0x6c]
    //                              Dsutil.c:745 (19)
    //         0044801f     POP        EDI
    //         00448020     POP        ESI
    //         00448021     POP        EBP
    //         00448022     MOV        EAX,0xe103
    //         00448027     MOV        dword ptr [EDX],0x0
    //         0044802d     POP        EBX
    //         0044802e     ADD        ESP,0x48
    //         00448031     RET
}

// Offset: 0x00448040
undefined WaveCloseReadFile() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined _WaveCloseReadFile()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _WaveCloseReadFile                                           XREF[3]:     ds_stream_file:00448761(c), 
    //                                                                                                         ds_stream_file:00448798(c), 
    //                                                                                                         ds_stream_stop:00448aec(c)  
    //                              Dsutil.c:758 (1)
    //         00448040     PUSH       ESI
    //                              Dsutil.c:760 (10)
    //         00448041     MOV        ESI,dword ptr [ESP + Stack[0x8]]
    //         00448045     MOV        EAX,dword ptr [ESI]
    //         00448047     TEST       EAX,EAX
    //         00448049     JZ         LAB_00448058
    //                              Dsutil.c:762 (7)
    //         0044804b     PUSH       EAX
    //         0044804c     CALL       dword ptr [->KERNEL32.DLL::GlobalFree]           = 0048aad0
    //                              Dsutil.c:763 (6)
    //         00448052     MOV        dword ptr [ESI],0x0
    //                               LAB_00448058                                                 XREF[1]:     00448049(j)  
    //                              Dsutil.c:766 (10)
    //         00448058     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         0044805c     MOV        EAX,dword ptr [ESI]
    //         0044805e     TEST       EAX,EAX
    //         00448060     JZ         LAB_00448071
    //                              Dsutil.c:768 (9)
    //         00448062     PUSH       0x0
    //         00448064     PUSH       EAX
    //         00448065     CALL       dword ptr [->WINMM.DLL::mmioClose]               = 0048b45a
    //                              Dsutil.c:769 (6)
    //         0044806b     MOV        dword ptr [ESI],0x0
    //                               LAB_00448071                                                 XREF[1]:     00448060(j)  
    //                              Dsutil.c:772 (2)
    //         00448071     XOR        EAX,EAX
    //                              Dsutil.c:774 (2)
    //         00448073     POP        ESI
    //         00448074     RET
}

// Offset: 0x00448080
undefined WaveCreateFile() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined _WaveCreateFile()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              _MMCKINFO         Stack[-0x18]   ckOut1                    XREF[1]:     00448093(W)  
    //              ulong             Stack[-0x1c]:4 dwFactChunk
    //                               _WaveCreateFile                                              XREF[1]:     _WaveSaveFile:004485df(c)  
    //                              Dsutil.c:793 (3)
    //         00448080     SUB        ESP,0x18
    //                              Dsutil.c:803 (34)
    //         00448083     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00448087     PUSH       EBX
    //         00448088     PUSH       EBP
    //         00448089     PUSH       ESI
    //         0044808a     PUSH       EDI
    //         0044808b     PUSH       0x11002
    //         00448090     PUSH       0x0
    //         00448092     PUSH       EAX
    //         00448093     MOV        dword ptr [ESP + ckOut1.ckid],0xffffffff
    //         0044809b     CALL       dword ptr [->WINMM.DLL::mmioOpenA]               = 0048b48e
    //         004480a1     MOV        ESI,dword ptr [ESP + 0x30]
    //                              Dsutil.c:805 (4)
    //         004480a5     TEST       EAX,EAX
    //         004480a7     MOV        dword ptr [ESI],EAX
    //                              Dsutil.c:808 (6)
    //         004480a9     JZ         LAB_00448192
    //                              Dsutil.c:813 (4)
    //         004480af     MOV        EAX,dword ptr [ESP + 0x3c]
    //                              Dsutil.c:815 (36)
    //         004480b3     MOV        EBP,dword ptr [->WINMM.DLL::mmioCreateChunk]     = 0048b4dc
    //         004480b9     PUSH       0x20
    //         004480bb     PUSH       EAX=>DAT_fffffff8
    //         004480bc     MOV        dword ptr [EAX + 0x8],0x45564157
    //         004480c3     MOV        dword ptr [EAX + 0x4],0x0
    //         004480ca     MOV        ECX,dword ptr [ESI]
    //         004480cc     PUSH       ECX=>DAT_fffffff4
    //         004480cd     CALL       EBP=>WINMM.DLL::mmioCreateChunk
    //         004480cf     TEST       EAX,EAX
    //         004480d1     JNZ        LAB_00448197
    //                              Dsutil.c:825 (4)
    //         004480d7     MOV        EDI,dword ptr [ESP + 0x38]
    //                              Dsutil.c:827 (28)
    //         004480db     PUSH       EAX
    //         004480dc     PUSH       EDI=>DAT_fffffff8
    //         004480dd     MOV        dword ptr [EDI],0x20746d66
    //         004480e3     MOV        dword ptr [EDI + 0x4],0x10
    //         004480ea     MOV        EDX,dword ptr [ESI]
    //         004480ec     PUSH       EDX=>DAT_fffffff4
    //         004480ed     CALL       EBP=>WINMM.DLL::mmioCreateChunk
    //         004480ef     TEST       EAX,EAX
    //         004480f1     JNZ        LAB_00448197
    //                              Dsutil.c:833 (10)
    //         004480f7     MOV        EBX,dword ptr [ESP + 0x34]
    //         004480fb     CMP        word ptr [EBX],0x1
    //         004480ff     JNZ        LAB_0044811f
    //                              Dsutil.c:836 (17)
    //         00448101     MOV        EAX,dword ptr [ESI]
    //         00448103     PUSH       0x10
    //         00448105     PUSH       EBX=>DAT_fffffff8
    //         00448106     PUSH       EAX=>DAT_fffffff4
    //         00448107     CALL       dword ptr [->WINMM.DLL::mmioWrite]               = 0048b4d0
    //         0044810d     CMP        EAX,0x10
    //         00448110     JZ         LAB_00448140
    //                              Dsutil.c:880 (5)
    //         00448112     MOV        EAX,0xe104
    //                              Dsutil.c:895 (8)
    //         00448117     POP        EDI
    //         00448118     POP        ESI
    //         00448119     POP        EBP
    //         0044811a     POP        EBX
    //         0044811b     ADD        ESP,0x18
    //         0044811e     RET
    //                               LAB_0044811f                                                 XREF[1]:     004480ff(j)  
    //                              Dsutil.c:847 (31)
    //         0044811f     MOV        EDX,dword ptr [ESI]
    //         00448121     XOR        ECX,ECX
    //         00448123     MOV        CX,word ptr [EBX + 0x10]
    //         00448127     ADD        ECX,0x12
    //         0044812a     PUSH       ECX
    //         0044812b     PUSH       EBX=>DAT_fffffff8
    //         0044812c     PUSH       EDX=>DAT_fffffff4
    //         0044812d     CALL       dword ptr [->WINMM.DLL::mmioWrite]               = 0048b4d0
    //         00448133     XOR        ECX,ECX
    //         00448135     MOV        CX,word ptr [EBX + 0x10]
    //         00448139     ADD        ECX,0x12
    //         0044813c     CMP        EAX,ECX
    //                              Dsutil.c:850 (2)
    //         0044813e     JNZ        LAB_00448192
    //                               LAB_00448140                                                 XREF[1]:     00448110(j)  
    //                              Dsutil.c:857 (18)
    //         00448140     MOV        EDX,dword ptr [ESI]
    //         00448142     PUSH       0x0
    //         00448144     PUSH       EDI=>DAT_fffffff8
    //         00448145     MOV        EDI,dword ptr [->WINMM.DLL::mmioAscend]          = 0048b466
    //         0044814b     PUSH       EDX=>DAT_fffffff4
    //         0044814c     CALL       EDI=>WINMM.DLL::mmioAscend
    //         0044814e     TEST       EAX,EAX
    //         00448150     JNZ        LAB_00448197
    //                              Dsutil.c:866 (27)
    //         00448152     MOV        ECX,dword ptr [ESI]
    //         00448154     MOV        dword ptr [ESP + 0x18],EAX
    //         00448158     PUSH       EAX
    //         00448159     LEA        EAX,[ESP + 0x18]
    //         0044815d     PUSH       EAX=>DAT_fffffff8
    //         0044815e     PUSH       ECX=>DAT_fffffff4
    //         0044815f     MOV        dword ptr [ESP + 0x20],0x74636166
    //         00448167     CALL       EBP=>WINMM.DLL::mmioCreateChunk
    //         00448169     TEST       EAX,EAX
    //         0044816b     JNZ        LAB_00448197
    //                              Dsutil.c:871 (19)
    //         0044816d     MOV        EAX,dword ptr [ESI]
    //         0044816f     LEA        EDX,[ESP + 0x10]
    //         00448173     PUSH       0x4
    //         00448175     PUSH       EDX=>DAT_fffffff8
    //         00448176     PUSH       EAX=>DAT_fffffff4
    //         00448177     CALL       dword ptr [->WINMM.DLL::mmioWrite]               = 0048b4d0
    //         0044817d     CMP        EAX,0x4
    //                              Dsutil.c:874 (2)
    //         00448180     JNZ        LAB_00448192
    //                              Dsutil.c:878 (16)
    //         00448182     MOV        EDX,dword ptr [ESI]
    //         00448184     LEA        ECX,[ESP + 0x14]
    //         00448188     PUSH       0x0
    //         0044818a     PUSH       ECX=>DAT_fffffff8
    //         0044818b     PUSH       EDX=>DAT_fffffff4
    //         0044818c     CALL       EDI=>WINMM.DLL::mmioAscend
    //         0044818e     TEST       EAX,EAX
    //         00448190     JZ         LAB_00448197
    //                               LAB_00448192                                                 XREF[3]:     004480a9(j), 0044813e(j), 
    //                                                                                                         00448180(j)  
    //                              Dsutil.c:880 (5)
    //         00448192     MOV        EAX,0xe104
    //                              Symbol Ref: No symbol: ERROR_CANNOT_WRITE
    //                              Symbol Ref: No symbol: DONE_CREATE
    //                               LAB_00448197                                                 XREF[5]:     004480d1(j), 004480f1(j), 
    //                                                                                                         00448150(j), 0044816b(j), 
    //                                                                                                         00448190(j)  
    //                              Dsutil.c:895 (8)
    //         00448197     POP        EDI
    //         00448198     POP        ESI
    //         00448199     POP        EBP
    //         0044819a     POP        EBX
    //         0044819b     ADD        ESP,0x18
    //         0044819e     RET
}

// Offset: 0x004481A0
undefined WaveStartDataWrite() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined _WaveStartDataWrite()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _WaveStartDataWrite                                          XREF[1]:     _WaveSaveFile:004485fa(c)  
    //                              Dsutil.c:906 (5)
    //         004481a0     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         004481a4     PUSH       ESI
    //                              Dsutil.c:914 (33)
    //         004481a5     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         004481a9     PUSH       0x0
    //         004481ab     MOV        dword ptr [EAX],0x61746164
    //         004481b1     MOV        dword ptr [EAX + 0x4],0x0
    //         004481b8     PUSH       EAX
    //         004481b9     MOV        EAX,dword ptr [ESI]
    //         004481bb     PUSH       EAX
    //         004481bc     CALL       dword ptr [->WINMM.DLL::mmioCreateChunk]         = 0048b4dc
    //         004481c2     TEST       EAX,EAX
    //         004481c4     JNZ        LAB_004481d5
    //                              Dsutil.c:919 (15)
    //         004481c6     MOV        ECX,dword ptr [ESP + 0x10]
    //         004481ca     MOV        EDX,dword ptr [ESI]
    //         004481cc     PUSH       EAX
    //         004481cd     PUSH       ECX=>DAT_fffffff8
    //         004481ce     PUSH       EDX=>DAT_fffffff4
    //         004481cf     CALL       dword ptr [->WINMM.DLL::mmioGetInfo]             = 0048b4c2
    //                              Symbol Ref: No symbol: ERROR_CANNOT_WRITE
    //                               LAB_004481d5                                                 XREF[1]:     004481c4(j)  
    //                              Dsutil.c:929 (2)
    //         004481d5     POP        ESI
    //         004481d6     RET
}

// Offset: 0x004481E0
undefined WaveWriteFile() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined _WaveWriteFile()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _WaveWriteFile                                               XREF[1]:     _WaveSaveFile:0044862a(c)  
    //                              Dsutil.c:952 (22)
    //         004481e0     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         004481e4     PUSH       EBX
    //         004481e5     MOV        EBX,dword ptr [ESP + Stack[0x14]]
    //         004481e9     PUSH       EBP
    //         004481ea     PUSH       ESI
    //         004481eb     PUSH       EDI
    //         004481ec     XOR        EAX,EAX
    //         004481ee     XOR        EDI,EDI
    //         004481f0     TEST       ECX,ECX
    //         004481f2     MOV        dword ptr [EBX],EAX
    //         004481f4     JBE        LAB_00448241
    //                              Dsutil.c:964 (18)
    //         004481f6     MOV        ESI,dword ptr [ESP + Stack[0x18]]
    //         004481fa     MOV        EBP,dword ptr [ESP + Stack[0x4]]
    //                               LAB_004481fe                                                 XREF[1]:     0044823f(j)  
    //         004481fe     MOV        ECX,dword ptr [ESI + 0x1c]
    //         00448201     MOV        EDX,dword ptr [ESI + 0x24]
    //         00448204     CMP        ECX,EDX
    //         00448206     JNZ        LAB_00448220
    //                              Dsutil.c:966 (2)
    //         00448208     MOV        EDX,dword ptr [ESI]
    //                              Dsutil.c:967 (22)
    //         0044820a     PUSH       0x1
    //         0044820c     OR         EDX,0x10000000
    //         00448212     PUSH       ESI=>DAT_fffffff8
    //         00448213     PUSH       EBP=>DAT_fffffff4
    //         00448214     MOV        dword ptr [ESI],EDX
    //         00448216     CALL       dword ptr [->WINMM.DLL::mmioAdvance]             = 0048b4b4
    //         0044821c     TEST       EAX,EAX
    //         0044821e     JNZ        LAB_00448241
    //                               LAB_00448220                                                 XREF[1]:     00448206(j)  
    //                              Dsutil.c:972 (19)
    //         00448220     MOV        ECX,dword ptr [ESP + 0x1c]
    //         00448224     MOV        EDX,dword ptr [ESI + 0x1c]
    //         00448227     MOV        CL,byte ptr [EDI + ECX*0x1]
    //         0044822a     MOV        byte ptr [EDX],CL
    //         0044822c     MOV        EDX,dword ptr [ESI + 0x1c]
    //         0044822f     INC        EDX
    //         00448230     MOV        dword ptr [ESI + 0x1c],EDX
    //                              Dsutil.c:973 (14)
    //         00448233     MOV        ECX,dword ptr [EBX]
    //         00448235     INC        ECX
    //         00448236     INC        EDI
    //         00448237     MOV        dword ptr [EBX],ECX
    //         00448239     MOV        ECX,dword ptr [ESP + 0x18]
    //         0044823d     CMP        EDI,ECX
    //         0044823f     JC         LAB_004481fe
    //                              Symbol Ref: No symbol: ERROR_CANNOT_WRITE
    //                               LAB_00448241                                                 XREF[2]:     004481f4(j), 0044821e(j)  
    //                              Dsutil.c:983 (5)
    //         00448241     POP        EDI
    //         00448242     POP        ESI
    //         00448243     POP        EBP
    //         00448244     POP        EBX
    //         00448245     RET
}

// Offset: 0x00448250
undefined WaveCloseWriteFile() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined _WaveCloseWriteFile()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _WaveCloseWriteFile                                          XREF[1]:     _WaveSaveFile:00448652(c)  
    //                              Dsutil.c:1007 (3)
    //         00448250     PUSH       EBX
    //         00448251     PUSH       EBP
    //         00448252     PUSH       ESI
    //                              Dsutil.c:1013 (10)
    //         00448253     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         00448257     PUSH       EDI
    //         00448258     CMP        dword ptr [ESI],0x0
    //         0044825b     JNZ        LAB_00448264
    //                              Dsutil.c:1014 (2)
    //         0044825d     XOR        EAX,EAX
    //                              Dsutil.c:1076 (5)
    //         0044825f     POP        EDI
    //         00448260     POP        ESI
    //         00448261     POP        EBP
    //         00448262     POP        EBX
    //         00448263     RET
    //                               LAB_00448264                                                 XREF[1]:     0044825b(j)  
    //                              Dsutil.c:1016 (4)
    //         00448264     MOV        EAX,dword ptr [ESP + Stack[0x10]]
    //                              Dsutil.c:1017 (32)
    //         00448268     PUSH       0x0
    //         0044826a     PUSH       EAX
    //         0044826b     MOV        EBX,dword ptr [EAX]
    //         0044826d     OR         EBX,0x10000000
    //         00448273     MOV        dword ptr [EAX],EBX
    //         00448275     MOV        EAX,dword ptr [ESI]
    //         00448277     PUSH       EAX
    //         00448278     CALL       dword ptr [->WINMM.DLL::mmioSetInfo]             = 0048b4a6
    //         0044827e     MOV        EDI,EAX
    //         00448280     TEST       EDI,EDI
    //         00448282     JNZ        LAB_0044830e
    //                              Dsutil.c:1026 (21)
    //         00448288     MOV        EBP,dword ptr [ESP + 0x18]
    //         0044828c     MOV        ECX,dword ptr [ESI]
    //         0044828e     PUSH       EAX
    //         0044828f     PUSH       EBP=>DAT_fffffff8
    //         00448290     PUSH       ECX=>DAT_fffffff4
    //         00448291     CALL       dword ptr [->WINMM.DLL::mmioAscend]              = 0048b466
    //         00448297     MOV        EDI,EAX
    //         00448299     TEST       EDI,EDI
    //         0044829b     JNZ        LAB_0044830e
    //                              Dsutil.c:1031 (21)
    //         0044829d     MOV        EBX,dword ptr [ESP + 0x1c]
    //         004482a1     MOV        EDX,dword ptr [ESI]
    //         004482a3     PUSH       EAX
    //         004482a4     PUSH       EBX=>DAT_fffffff8
    //         004482a5     PUSH       EDX=>DAT_fffffff4
    //         004482a6     CALL       dword ptr [->WINMM.DLL::mmioAscend]              = 0048b466
    //         004482ac     MOV        EDI,EAX
    //         004482ae     TEST       EDI,EDI
    //         004482b0     JNZ        LAB_0044830e
    //                              Dsutil.c:1035 (11)
    //         004482b2     PUSH       EAX
    //         004482b3     PUSH       EAX=>DAT_fffffff8
    //         004482b4     MOV        EAX,dword ptr [ESI]
    //         004482b6     PUSH       EAX=>DAT_fffffff4
    //         004482b7     CALL       dword ptr [->WINMM.DLL::mmioSeek]                = 0048b49a
    //                              Dsutil.c:1036 (18)
    //         004482bd     MOV        ECX,dword ptr [ESI]
    //         004482bf     PUSH       EDI
    //         004482c0     PUSH       EDI=>DAT_fffffff8
    //         004482c1     PUSH       EBX=>DAT_fffffff4
    //         004482c2     PUSH       ECX=>DAT_fffffff0
    //         004482c3     CALL       dword ptr [->WINMM.DLL::mmioDescend]             = 0048b480
    //         004482c9     MOV        EDI,EAX
    //         004482cb     TEST       EDI,EDI
    //         004482cd     JNZ        LAB_0044830e
    //                              Dsutil.c:1042 (7)
    //         004482cf     MOV        dword ptr [EBP],0x74636166
    //                              Dsutil.c:1043 (17)
    //         004482d6     MOV        EDX,dword ptr [ESI]
    //         004482d8     PUSH       0x10
    //         004482da     PUSH       EBX=>DAT_fffffff8
    //         004482db     PUSH       EBP=>DAT_fffffff4
    //         004482dc     PUSH       EDX=>DAT_fffffff0
    //         004482dd     CALL       dword ptr [->WINMM.DLL::mmioDescend]             = 0048b480
    //         004482e3     TEST       EAX,EAX
    //         004482e5     JNZ        LAB_0044832a
    //                              Dsutil.c:1047 (16)
    //         004482e7     MOV        ECX,dword ptr [ESI]
    //         004482e9     LEA        EAX,[ESP + 0x24]
    //         004482ed     PUSH       0x4
    //         004482ef     PUSH       EAX=>DAT_fffffff8
    //         004482f0     PUSH       ECX=>DAT_fffffff4
    //         004482f1     CALL       dword ptr [->WINMM.DLL::mmioWrite]               = 0048b4d0
    //                              Dsutil.c:1048 (13)
    //         004482f7     MOV        EDX,dword ptr [ESI]
    //         004482f9     PUSH       EDI
    //         004482fa     MOV        EDI,dword ptr [->WINMM.DLL::mmioAscend]          = 0048b466
    //         00448300     PUSH       EBP=>DAT_fffffff8
    //         00448301     PUSH       EDX=>DAT_fffffff4
    //         00448302     CALL       EDI=>WINMM.DLL::mmioAscend
    //                              Dsutil.c:1062 (10)
    //         00448304     MOV        EAX,dword ptr [ESI]
    //         00448306     PUSH       0x0
    //         00448308     PUSH       EBX=>DAT_fffffff8
    //         00448309     PUSH       EAX=>DAT_fffffff4
    //         0044830a     CALL       EDI=>WINMM.DLL::mmioAscend
    //         0044830c     MOV        EDI,EAX
    //                              Symbol Ref: No symbol: ERROR_CANNOT_WRITE
    //                               LAB_0044830e                                                 XREF[4]:     00448282(j), 0044829b(j), 
    //                                                                                                         004482b0(j), 004482cd(j)  
    //                              Dsutil.c:1068 (6)
    //         0044830e     MOV        EAX,dword ptr [ESI]
    //         00448310     TEST       EAX,EAX
    //         00448312     JZ         LAB_00448323
    //                              Dsutil.c:1070 (9)
    //         00448314     PUSH       0x0
    //         00448316     PUSH       EAX=>DAT_fffffff8
    //         00448317     CALL       dword ptr [->WINMM.DLL::mmioClose]               = 0048b45a
    //                              Dsutil.c:1071 (6)
    //         0044831d     MOV        dword ptr [ESI],0x0
    //                               LAB_00448323                                                 XREF[1]:     00448312(j)  
    //                              Dsutil.c:1074 (2)
    //         00448323     MOV        EAX,EDI
    //                              Dsutil.c:1076 (15)
    //         00448325     POP        EDI
    //         00448326     POP        ESI
    //         00448327     POP        EBP
    //         00448328     POP        EBX
    //         00448329     RET
    //                               LAB_0044832a                                                 XREF[1]:     004482e5(j)  
    //         0044832a     POP        EDI
    //         0044832b     POP        ESI
    //         0044832c     POP        EBP
    //         0044832d     MOV        EAX,0x1
    //         00448332     POP        EBX
    //         00448333     RET
}

// Offset: 0x00448340
undefined WaveCopyUselessChunks() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined _WaveCopyUselessChunks()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _WaveCopyUselessChunks
    //                              Dsutil.c:1102 (1)
    //         00448340     PUSH       EBX
    //                              Dsutil.c:1108 (33)
    //         00448341     MOV        EBX,dword ptr [ESP + Stack[0xc]]
    //         00448345     PUSH       ESI
    //         00448346     PUSH       EDI
    //         00448347     MOV        EAX,dword ptr [EBX + 0xc]
    //         0044834a     MOV        EDI,dword ptr [ESP + Stack[0x4]]
    //         0044834e     ADD        EAX,0x4
    //         00448351     PUSH       0x0
    //         00448353     MOV        ECX,dword ptr [EDI]
    //         00448355     PUSH       EAX
    //         00448356     PUSH       ECX
    //         00448357     CALL       dword ptr [->WINMM.DLL::mmioSeek]                = 0048b49a
    //         0044835d     CMP        EAX,-0x1
    //         00448360     JNZ        LAB_00448369
    //                              Dsutil.c:1110 (5)
    //         00448362     MOV        ESI,0xe102
    //                              Dsutil.c:1111 (2)
    //         00448367     JMP        LAB_004483e5
    //                               LAB_00448369                                                 XREF[1]:     00448360(j)  
    //                              Dsutil.c:1116 (32)
    //         00448369     MOV        ESI,dword ptr [ESP + 0x14]
    //         0044836d     MOV        EDX,dword ptr [EDI]
    //         0044836f     PUSH       EBP
    //         00448370     MOV        EBP,dword ptr [->WINMM.DLL::mmioDescend]         = 0048b480
    //         00448376     PUSH       0x0=>DAT_fffffff8
    //         00448378     PUSH       EBX=>DAT_fffffff4
    //         00448379     PUSH       ESI=>DAT_fffffff0
    //         0044837a     PUSH       EDX
    //         0044837b     MOV        dword ptr [ESP + 0x2c],0x0
    //         00448383     CALL       EBP=>WINMM.DLL::mmioDescend
    //         00448385     TEST       EAX,EAX
    //         00448387     JNZ        LAB_004483e0
    //                               LAB_00448389                                                 XREF[1]:     004483de(j)  
    //                              Dsutil.c:1120 (20)
    //         00448389     MOV        EAX,dword ptr [EBX + 0x4]
    //         0044838c     MOV        ECX,dword ptr [EBX + 0xc]
    //         0044838f     MOV        EDX,dword ptr [ESI + 0x4]
    //         00448392     ADD        EAX,ECX
    //         00448394     MOV        ECX,dword ptr [ESI + 0xc]
    //         00448397     ADD        ECX,EDX
    //         00448399     CMP        ECX,EAX
    //         0044839b     JA         LAB_004483e0
    //                              Dsutil.c:1123 (23)
    //         0044839d     MOV        EAX,dword ptr [ESI]
    //         0044839f     CMP        EAX,0x20444150
    //         004483a4     JZ         LAB_004483c7
    //         004483a6     CMP        EAX,0x50534944
    //         004483ab     JZ         LAB_004483b4
    //         004483ad     CMP        EAX,0x74736c70
    //         004483b2     JNZ        LAB_004483c7
    //                               LAB_004483b4                                                 XREF[1]:     004483ab(j)  
    //                              Dsutil.c:1151 (19)
    //         004483b4     MOV        EDX,dword ptr [ESP + 0x20]
    //         004483b8     MOV        ECX,dword ptr [EDI]
    //         004483ba     PUSH       ESI
    //         004483bb     MOV        EAX,dword ptr [EDX]
    //         004483bd     PUSH       EAX=>DAT_fffffff8
    //         004483be     PUSH       ECX=>DAT_fffffff4
    //         004483bf     CALL       riffCopyChunk                                    undefined riffCopyChunk()
    //         004483c4     ADD        ESP,0xc
    //                               LAB_004483c7                                                 XREF[2]:     004483a4(j), 004483b2(j)  
    //                              Dsutil.c:1162 (25)
    //         004483c7     MOV        EDX,dword ptr [EDI]
    //         004483c9     PUSH       0x0
    //         004483cb     PUSH       ESI=>DAT_fffffff8
    //         004483cc     PUSH       EDX=>DAT_fffffff4
    //         004483cd     CALL       dword ptr [->WINMM.DLL::mmioAscend]              = 0048b466
    //         004483d3     MOV        EAX,dword ptr [EDI]
    //         004483d5     PUSH       0x0
    //         004483d7     PUSH       EBX=>DAT_fffffff8
    //         004483d8     PUSH       ESI=>DAT_fffffff4
    //         004483d9     PUSH       EAX=>DAT_fffffff0
    //         004483da     CALL       EBP=>WINMM.DLL::mmioDescend
    //         004483dc     TEST       EAX,EAX
    //         004483de     JZ         LAB_00448389
    //                               LAB_004483e0                                                 XREF[2]:     00448387(j), 0044839b(j)  
    //                              Dsutil.c:1116 (5)
    //         004483e0     MOV        ESI,dword ptr [ESP + 0x1c]
    //         004483e4     POP        EBP
    //                              Symbol Ref: No symbol: ERROR_IN_PROC
    //                               LAB_004483e5                                                 XREF[1]:     00448367(j)  
    //                              Dsutil.c:1169 (18)
    //         004483e5     MOV        ECX,dword ptr [EBX + 0xc]
    //         004483e8     MOV        EDX,dword ptr [EDI]
    //         004483ea     ADD        ECX,0x4
    //         004483ed     PUSH       0x0
    //         004483ef     PUSH       ECX=>DAT_fffffff8
    //         004483f0     PUSH       EDX=>DAT_fffffff4
    //         004483f1     CALL       dword ptr [->WINMM.DLL::mmioSeek]                = 0048b49a
    //                              Dsutil.c:1172 (2)
    //         004483f7     MOV        EAX,ESI
    //                              Dsutil.c:1173 (4)
    //         004483f9     POP        EDI
    //         004483fa     POP        ESI
    //         004483fb     POP        EBX
    //         004483fc     RET
}

// Offset: 0x00448400
undefined riffCopyChunk() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * riffCopyChunk                                                                                         *
    //                              *********************************************************************************************************
    //                              undefined __cdecl riffCopyChunk()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              _MMCKINFO         Stack[-0x18]   ck
    //                               _riffCopyChunk                                               XREF[1]:     _WaveCopyUselessChunks:004483bf(c)
    //                               riffCopyChunk
    //                              Dsutil.c:1191 (6)
    //         00448400     SUB        ESP,0x14
    //         00448403     PUSH       EBX
    //         00448404     PUSH       EBP
    //         00448405     PUSH       ESI
    //                              Dsutil.c:1198 (26)
    //         00448406     MOV        ESI,dword ptr [ESP + Stack[0xc]]
    //         0044840a     PUSH       EDI
    //         0044840b     MOV        EAX,dword ptr [ESI + 0x4]
    //         0044840e     PUSH       EAX
    //         0044840f     PUSH       0x42
    //         00448411     CALL       dword ptr [->KERNEL32.DLL::GlobalAlloc]          = 0048ab8e
    //         00448417     PUSH       EAX
    //         00448418     CALL       dword ptr [->KERNEL32.DLL::GlobalLock]           = 0048aade
    //         0044841e     MOV        EDI,EAX
    //                              Dsutil.c:1199 (4)
    //         00448420     TEST       EDI,EDI
    //         00448422     JNZ        LAB_0044842c
    //                              Dsutil.c:1227 (8)
    //         00448424     POP        EDI
    //         00448425     POP        ESI
    //         00448426     POP        EBP
    //         00448427     POP        EBX
    //         00448428     ADD        ESP,0x14
    //         0044842b     RET
    //                               LAB_0044842c                                                 XREF[1]:     00448422(j)  
    //                              Dsutil.c:1204 (35)
    //         0044842c     MOV        EBP,dword ptr [ESP + 0x2c]
    //         00448430     MOV        ECX,dword ptr [ESI]
    //         00448432     MOV        EDX,dword ptr [ESI + 0x4]
    //         00448435     LEA        EAX,[ESP + 0x10]
    //         00448439     PUSH       0x0
    //         0044843b     PUSH       EAX=>DAT_fffffff8
    //         0044843c     PUSH       EBP=>DAT_fffffff4
    //         0044843d     MOV        dword ptr [ESP + 0x1c],ECX
    //         00448441     MOV        dword ptr [ESP + 0x20],EDX
    //         00448445     CALL       dword ptr [->WINMM.DLL::mmioCreateChunk]         = 0048b4dc
    //         0044844b     TEST       EAX,EAX
    //         0044844d     JNZ        LAB_00448485
    //                              Dsutil.c:1207 (22)
    //         0044844f     MOV        EBX,dword ptr [ESI + 0x4]
    //         00448452     MOV        EDX,dword ptr [ESP + 0x28]
    //         00448456     MOV        ECX,EBX
    //         00448458     PUSH       ECX
    //         00448459     PUSH       EDI=>DAT_fffffff8
    //         0044845a     PUSH       EDX=>DAT_fffffff4
    //         0044845b     CALL       dword ptr [->WINMM.DLL::mmioRead]                = 0048b474
    //         00448461     CMP        EAX,EBX
    //         00448463     JNZ        LAB_00448485
    //                              Dsutil.c:1210 (14)
    //         00448465     PUSH       EBX
    //         00448466     PUSH       EDI=>DAT_fffffff8
    //         00448467     PUSH       EBP=>DAT_fffffff4
    //         00448468     CALL       dword ptr [->WINMM.DLL::mmioWrite]               = 0048b4d0
    //         0044846e     CMP        EAX,dword ptr [ESI + 0x4]
    //         00448471     JNZ        LAB_00448485
    //                              Dsutil.c:1213 (18)
    //         00448473     LEA        EAX,[ESP + 0x10]
    //         00448477     PUSH       0x0
    //         00448479     PUSH       EAX=>DAT_fffffff8
    //         0044847a     PUSH       EBP=>DAT_fffffff4
    //         0044847b     CALL       dword ptr [->WINMM.DLL::mmioAscend]              = 0048b466
    //         00448481     TEST       EAX,EAX
    //         00448483     JZ         LAB_004484a9
    //                              Symbol Ref: No symbol: rscc_Error
    //                               LAB_00448485                                                 XREF[3]:     0044844d(j), 00448463(j), 
    //                                                                                                         00448471(j)  
    //                              Dsutil.c:1224 (26)
    //         00448485     MOV        ESI,dword ptr [->KERNEL32.DLL::GlobalHandle]     = 0048ab0c
    //         0044848b     PUSH       EDI
    //         0044848c     CALL       ESI=>KERNEL32.DLL::GlobalHandle
    //         0044848e     PUSH       EAX
    //         0044848f     CALL       dword ptr [->KERNEL32.DLL::GlobalUnlock]         = 0048aafc
    //         00448495     PUSH       EDI
    //         00448496     CALL       ESI=>KERNEL32.DLL::GlobalHandle
    //         00448498     PUSH       EAX
    //         00448499     CALL       dword ptr [->KERNEL32.DLL::GlobalFree]           = 0048aad0
    //                              Dsutil.c:1226 (2)
    //         0044849f     XOR        EAX,EAX
    //                              Dsutil.c:1227 (8)
    //         004484a1     POP        EDI
    //         004484a2     POP        ESI
    //         004484a3     POP        EBP
    //         004484a4     POP        EBX
    //         004484a5     ADD        ESP,0x14
    //         004484a8     RET
    //                               LAB_004484a9                                                 XREF[1]:     00448483(j)  
    //                              Dsutil.c:1217 (26)
    //         004484a9     MOV        ESI,dword ptr [->KERNEL32.DLL::GlobalHandle]     = 0048ab0c
    //         004484af     PUSH       EDI
    //         004484b0     CALL       ESI=>KERNEL32.DLL::GlobalHandle
    //         004484b2     PUSH       EAX
    //         004484b3     CALL       dword ptr [->KERNEL32.DLL::GlobalUnlock]         = 0048aafc
    //         004484b9     PUSH       EDI
    //         004484ba     CALL       ESI=>KERNEL32.DLL::GlobalHandle
    //         004484bc     PUSH       EAX
    //         004484bd     CALL       dword ptr [->KERNEL32.DLL::GlobalFree]           = 0048aad0
    //                              Dsutil.c:1227 (13)
    //         004484c3     POP        EDI
    //         004484c4     POP        ESI
    //         004484c5     POP        EBP
    //         004484c6     MOV        EAX,0x1
    //         004484cb     POP        EBX
    //         004484cc     ADD        ESP,0x14
    //         004484cf     RET
}

// Offset: 0x004484D0
undefined WaveLoadFile() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined _WaveLoadFile()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              _MMCKINFO         Stack[-0x18]   ckInRiff                  XREF[0,2]:   004484d7(*), 00448514(*)  
    //              _MMCKINFO         Stack[-0x2c]   ckIn                      XREF[0,2]:   00448518(*), 00448531(R)  
    //                               _WaveLoadFile
    //                              Dsutil.c:1251 (3)
    //         004484d0     SUB        ESP,0x28
    //                              Dsutil.c:1263 (65)
    //         004484d3     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         004484d7     LEA        EAX=>ckInRiff.cksize,[ESP + 0x14]
    //         004484db     LEA        ECX=>Stack[0x14],[ESP + 0x3c]
    //         004484df     PUSH       EBX
    //         004484e0     MOV        EBX,dword ptr [ESP + Stack[0x10]]
    //         004484e4     PUSH       EBP
    //         004484e5     MOV        EBP,dword ptr [ESP + Stack[0x8]]
    //         004484e9     PUSH       ESI
    //         004484ea     MOV        ESI,dword ptr [ESP + Stack[0x14]]
    //         004484ee     PUSH       EDI
    //         004484ef     PUSH       EAX
    //         004484f0     PUSH       EBX
    //         004484f1     MOV        dword ptr [ESI],0x0
    //         004484f7     PUSH       ECX
    //         004484f8     MOV        dword ptr [EBX],0x0
    //         004484fe     PUSH       EDX
    //         004484ff     MOV        dword ptr [EBP],0x0
    //         00448506     CALL       _WaveOpenFile                                    undefined _WaveOpenFile()
    //         0044850b     MOV        EDI,EAX
    //         0044850d     ADD        ESP,0x10
    //         00448510     TEST       EDI,EDI
    //         00448512     JNZ        LAB_0044856d
    //                              Dsutil.c:1268 (29)
    //         00448514     LEA        EAX=>ckInRiff.cksize,[ESP + 0x24]
    //         00448518     LEA        ECX=>ckIn.cksize,[ESP + 0x10]
    //         0044851c     PUSH       EAX
    //         0044851d     LEA        EDX=>Stack[0x14],[ESP + 0x50]
    //         00448521     PUSH       ECX
    //         00448522     PUSH       EDX
    //         00448523     CALL       _WaveStartDataRead                               undefined _WaveStartDataRead()
    //         00448528     MOV        EDI,EAX
    //         0044852a     ADD        ESP,0xc
    //         0044852d     TEST       EDI,EDI
    //         0044852f     JNZ        LAB_0044856d
    //                              Dsutil.c:1274 (18)
    //         00448531     MOV        EAX,dword ptr [ESP + ckIn.fccType]
    //         00448535     PUSH       EAX
    //         00448536     PUSH       EDI
    //         00448537     CALL       dword ptr [->KERNEL32.DLL::GlobalAlloc]          = 0048ab8e
    //         0044853d     TEST       EAX,EAX
    //         0044853f     MOV        dword ptr [ESI],EAX
    //         00448541     JNZ        LAB_0044854a
    //                              Dsutil.c:1276 (5)
    //         00448543     MOV        EDI,0xe000
    //                              Dsutil.c:1277 (2)
    //         00448548     JMP        LAB_0044856d
    //                               LAB_0044854a                                                 XREF[1]:     00448541(j)  
    //                              Dsutil.c:1280 (35)
    //         0044854a     LEA        ECX,[ESP + 0x48]
    //         0044854e     LEA        EDX,[ESP + 0x10]
    //         00448552     PUSH       ECX
    //         00448553     MOV        ECX,dword ptr [ESP + 0x50]
    //         00448557     PUSH       EDX
    //         00448558     PUSH       EAX
    //         00448559     MOV        EAX,dword ptr [ESP + 0x20]
    //         0044855d     PUSH       EAX
    //         0044855e     PUSH       ECX
    //         0044855f     CALL       _WaveReadFile                                    undefined _WaveReadFile()
    //         00448564     MOV        EDI,EAX
    //         00448566     ADD        ESP,0x14
    //         00448569     TEST       EDI,EDI
    //         0044856b     JZ         LAB_00448593
    //                              Symbol Ref: No symbol: ERROR_LOADING
    //                               LAB_0044856d                                                 XREF[3]:     00448512(j), 0044852f(j), 
    //                                                                                                         00448548(j)  
    //                              Dsutil.c:1289 (12)
    //         0044856d     MOV        EAX,dword ptr [ESI]
    //         0044856f     MOV        EBP,dword ptr [->KERNEL32.DLL::GlobalFree]       = 0048aad0
    //         00448575     TEST       EAX,EAX
    //         00448577     JZ         LAB_00448582
    //                              Dsutil.c:1291 (3)
    //         00448579     PUSH       EAX
    //         0044857a     CALL       EBP=>KERNEL32.DLL::GlobalFree
    //                              Dsutil.c:1292 (6)
    //         0044857c     MOV        dword ptr [ESI],0x0
    //                               LAB_00448582                                                 XREF[1]:     00448577(j)  
    //                              Dsutil.c:1294 (6)
    //         00448582     MOV        EAX,dword ptr [EBX]
    //         00448584     TEST       EAX,EAX
    //         00448586     JZ         LAB_0044859a
    //                              Dsutil.c:1296 (3)
    //         00448588     PUSH       EAX
    //         00448589     CALL       EBP=>KERNEL32.DLL::GlobalFree
    //                              Dsutil.c:1297 (8)
    //         0044858b     MOV        dword ptr [EBX],0x0
    //         00448591     JMP        LAB_0044859a
    //                               LAB_00448593                                                 XREF[1]:     0044856b(j)  
    //                              Dsutil.c:1285 (7)
    //         00448593     MOV        EDX,dword ptr [ESP + 0x48]
    //         00448597     MOV        dword ptr [EBP],EDX
    //                              Symbol Ref: No symbol: DONE_LOADING
    //                               LAB_0044859a                                                 XREF[2]:     00448586(j), 00448591(j)  
    //                              Dsutil.c:1302 (8)
    //         0044859a     MOV        EAX,dword ptr [ESP + 0x4c]
    //         0044859e     TEST       EAX,EAX
    //         004485a0     JZ         LAB_004485ab
    //                              Dsutil.c:1304 (9)
    //         004485a2     PUSH       0x0
    //         004485a4     PUSH       EAX
    //         004485a5     CALL       dword ptr [->WINMM.DLL::mmioClose]               = 0048b45a
    //                               LAB_004485ab                                                 XREF[1]:     004485a0(j)  
    //                              Dsutil.c:1308 (2)
    //         004485ab     MOV        EAX,EDI
    //                              Dsutil.c:1310 (8)
    //         004485ad     POP        EDI
    //         004485ae     POP        ESI
    //         004485af     POP        EBP
    //         004485b0     POP        EBX
    //         004485b1     ADD        ESP,0x28
    //         004485b4     RET
}

// Offset: 0x004485C0
undefined WaveSaveFile() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined _WaveSaveFile()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              _MMIOINFO         Stack[-0x4c]   mmioinfoOut               XREF[0,3]:   004485eb(*), 00448606(*), 0044863d(*)  
    //              _MMCKINFO         Stack[-0x60]   ckOutRIFF                 XREF[0,2]:   004485c7(*), 00448642(*)  
    //              _MMCKINFO         Stack[-0x74]   ckOut                     XREF[1,4]:   0044860a(*), 004485cb(*), 004485ef(*), 00448616(*), 
    //                                                                                     00448647(*)  
    //              uint              Stack[-0x78]:4 cbActualWrite             XREF[4]:     004485d8(*), 004485f4(*), 00448623(R), 0044864c(*)  
    //              void *            Stack[-0x7c]:4 hmmioOut
    //                               _WaveSaveFile
    //                              Dsutil.c:1327 (43)
    //         004485c0     MOV        EDX,dword ptr [ESP + Stack[0x10]]
    //         004485c4     SUB        ESP,0x78
    //         004485c7     LEA        EAX=>ckOutRIFF.cksize,[ESP + 0x1c]
    //         004485cb     LEA        ECX=>ckOut.cksize,[ESP + 0x8]
    //         004485cf     PUSH       EAX
    //         004485d0     PUSH       ECX
    //         004485d1     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         004485d8     LEA        EAX=>cbActualWrite,[ESP + 0x8]
    //         004485dc     PUSH       EDX
    //         004485dd     PUSH       EAX
    //         004485de     PUSH       ECX
    //         004485df     CALL       _WaveCreateFile                                  undefined _WaveCreateFile()
    //         004485e4     ADD        ESP,0x14
    //         004485e7     TEST       EAX,EAX
    //         004485e9     JNZ        LAB_0044865a
    //                              Dsutil.c:1341 (27)
    //         004485eb     LEA        EDX=>mmioinfoOut.fccIOProc,[ESP + 0x30]
    //         004485ef     LEA        EAX=>ckOut.cksize,[ESP + 0x8]
    //         004485f3     PUSH       EDX
    //         004485f4     LEA        ECX=>cbActualWrite,[ESP + 0x4]
    //         004485f8     PUSH       EAX
    //         004485f9     PUSH       ECX
    //         004485fa     CALL       _WaveStartDataWrite                              undefined _WaveStartDataWrite()
    //         004485ff     ADD        ESP,0xc
    //         00448602     TEST       EAX,EAX
    //         00448604     JNZ        LAB_0044865a
    //                              Dsutil.c:1346 (48)
    //         00448606     LEA        EDX=>mmioinfoOut.fccIOProc,[ESP + 0x30]
    //         0044860a     LEA        EAX=>ckOut,[ESP + 0x4]
    //         0044860e     PUSH       EDX
    //         0044860f     MOV        EDX,dword ptr [ESP + Stack[0x14]]
    //         00448616     LEA        ECX=>ckOut.cksize,[ESP + 0xc]
    //         0044861a     PUSH       EAX
    //         0044861b     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         00448622     PUSH       ECX
    //         00448623     MOV        ECX,dword ptr [ESP + cbActualWrite]
    //         00448627     PUSH       EDX
    //         00448628     PUSH       EAX
    //         00448629     PUSH       ECX
    //         0044862a     CALL       _WaveWriteFile                                   undefined _WaveWriteFile()
    //         0044862f     ADD        ESP,0x18
    //         00448632     TEST       EAX,EAX
    //         00448634     JNZ        LAB_0044865a
    //                              Dsutil.c:1351 (36)
    //         00448636     MOV        EDX,dword ptr [ESP + Stack[0xc]]
    //         0044863d     LEA        EAX=>mmioinfoOut.fccIOProc,[ESP + 0x30]
    //         00448641     PUSH       EDX
    //         00448642     LEA        ECX=>ckOutRIFF.cksize,[ESP + 0x20]
    //         00448646     PUSH       EAX
    //         00448647     LEA        EDX=>ckOut.cksize,[ESP + 0x10]
    //         0044864b     PUSH       ECX
    //         0044864c     LEA        EAX=>cbActualWrite,[ESP + 0xc]
    //         00448650     PUSH       EDX
    //         00448651     PUSH       EAX
    //         00448652     CALL       _WaveCloseWriteFile                              undefined _WaveCloseWriteFile()
    //         00448657     ADD        ESP,0x14
    //                              Symbol Ref: No symbol: ERROR_SAVING
    //                               LAB_0044865a                                                 XREF[3]:     004485e9(j), 00448604(j), 
    //                                                                                                         00448634(j)  
    //                              Dsutil.c:1360 (4)
    //         0044865a     ADD        ESP,0x78
    //         0044865d     RET
}

// Offset: 0x00448660
undefined ds_stream_init() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * ds_stream_init                                                                                        *
    //                              *********************************************************************************************************
    //                              undefined __cdecl ds_stream_init()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _ds_stream_init                                              XREF[1]:     init:004bc78a(c)  
    //                               ds_stream_init
    //                              Dsutil.c:1392 (4)
    //         00448660     MOV        ECX,dword ptr [ESP + Stack[0xc]]
    //                              Dsutil.c:1403 (50)
    //         00448664     MOV        EDX,dword ptr [ESP + Stack[0x8]]
    //         00448668     XOR        EAX,EAX
    //         0044866a     MOV        dword ptr [_uLastPercent],0x64
    //         00448674     MOV        [_lpDSBStreamBuffer],EAX
    //         00448679     MOV        [_bFileOpen],EAX
    //         0044867e     MOV        [_bPlaying],EAX
    //         00448683     MOV        [_bTimerInstalled],EAX
    //         00448688     MOV        [_uTimerID],EAX
    //         0044868d     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00448691     MOV        [_main_wnd],EAX
    //                              Dsutil.c:1405 (22)
    //         00448696     MOV        EAX,0x1
    //         0044869b     MOV        dword ptr [_lpBuffer],ECX                        = align(8)
    //         004486a1     MOV        dword ptr [_lpDS],EDX
    //         004486a7     MOV        [_ds_ready],EAX
    //                              Dsutil.c:1408 (1)
    //         004486ac     RET
}

// Offset: 0x004486B0
undefined ds_stream_exit() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * ds_stream_exit                                                                                        *
    //                              *********************************************************************************************************
    //                              undefined __cdecl ds_stream_exit()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _ds_stream_exit                                              XREF[1]:     exit:004bc7cd(c)  
    //                               ds_stream_exit
    //                              Dsutil.c:1415 (9)
    //         004486b0     MOV        EAX,[_ds_ready]
    //         004486b5     TEST       EAX,EAX
    //         004486b7     JZ         LAB_004486e3
    //                              Dsutil.c:1418 (27)
    //         004486b9     MOV        EAX,[_bFileOpen]
    //         004486be     TEST       EAX,EAX
    //         004486c0     JNZ        LAB_004486d4
    //         004486c2     MOV        EAX,[_bPlaying]
    //         004486c7     TEST       EAX,EAX
    //         004486c9     JNZ        LAB_004486d4
    //         004486cb     MOV        EAX,[_bTimerInstalled]
    //         004486d0     TEST       EAX,EAX
    //         004486d2     JZ         LAB_004486d9
    //                               LAB_004486d4                                                 XREF[2]:     004486c0(j), 004486c9(j)  
    //                              Dsutil.c:1419 (5)
    //         004486d4     CALL       ds_stream_stop                                   undefined ds_stream_stop()
    //                               LAB_004486d9                                                 XREF[1]:     004486d2(j)  
    //                              Dsutil.c:1421 (10)
    //         004486d9     MOV        dword ptr [_ds_ready],0x0
    //                               LAB_004486e3                                                 XREF[1]:     004486b7(j)  
    //                              Dsutil.c:1423 (1)
    //         004486e3     RET
}

// Offset: 0x004486F0
undefined ds_stream_file() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * ds_stream_file                                                                                        *
    //                              *********************************************************************************************************
    //                              undefined __cdecl ds_stream_file()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00448802(W)  
    //              _DSBUFFERDESC     Stack[-0x18]   dsbd                      XREF[0,5]:   004487d9(*), 00448806(*), 0044880b(W), 00448813(W), 
    //                                                                                     0044881b(W)  
    //              ulong             Stack[-0x1c]:4 dwLen2
    //              uchar *           Stack[-0x20]:4 lpWrite2
    //              uint              Stack[-0x24]:4 uChkErr
    //              uchar *           Stack[-0x28]:4 lpWrite1
    //              ulong             Stack[-0x2c]:4 dwLen1
    //                               _ds_stream_file                                              XREF[1]:     stream_file:004bc91a(c)  
    //                               ds_stream_file
    //                              Dsutil.c:1429 (34)
    //         004486f0     MOV        EAX,[_bFileOpen]
    //         004486f5     SUB        ESP,0x28
    //         004486f8     PUSH       EBX
    //         004486f9     XOR        EBX,EBX
    //         004486fb     PUSH       EBP
    //         004486fc     PUSH       ESI
    //         004486fd     CMP        EAX,EBX
    //         004486ff     PUSH       EDI
    //         00448700     JNZ        LAB_00448712
    //         00448702     CMP        dword ptr [_bPlaying],EBX
    //         00448708     JNZ        LAB_00448712
    //         0044870a     CMP        dword ptr [_bTimerInstalled],EBX
    //         00448710     JZ         LAB_00448717
    //                               LAB_00448712                                                 XREF[2]:     00448700(j), 00448708(j)  
    //                              Dsutil.c:1439 (5)
    //         00448712     CALL       ds_stream_stop                                   undefined ds_stream_stop()
    //                               LAB_00448717                                                 XREF[1]:     00448710(j)  
    //                              Dsutil.c:1447 (38)
    //         00448717     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0044871b     PUSH       null_0088847c                                    = align(4)
    //         00448720     PUSH       _wiWave
    //         00448725     PUSH       DAT_00888464
    //         0044872a     PUSH       EAX
    //         0044872b     MOV        dword ptr [_stream_paused],EBX
    //         00448731     CALL       _WaveOpenFile                                    undefined _WaveOpenFile()
    //         00448736     ADD        ESP,0x10
    //         00448739     CMP        EAX,EBX
    //         0044873b     JZ         LAB_00448747
    //                              Dsutil.c:1451 (2)
    //         0044873d     XOR        EAX,EAX
    //                              Dsutil.c:1595 (8)
    //         0044873f     POP        EDI
    //         00448740     POP        ESI
    //         00448741     POP        EBP
    //         00448742     POP        EBX
    //         00448743     ADD        ESP,0x28
    //         00448746     RET
    //                               LAB_00448747                                                 XREF[1]:     0044873b(j)  
    //                              Dsutil.c:1454 (16)
    //         00448747     MOV        ECX,dword ptr [_wiWave]
    //         0044874d     MOV        EBP,0x1
    //         00448752     CMP        word ptr [ECX],BP
    //         00448755     JZ         LAB_00448773
    //                              Dsutil.c:1457 (18)
    //         00448757     PUSH       _wiWave
    //         0044875c     PUSH       DAT_00888464
    //         00448761     CALL       _WaveCloseReadFile                               undefined _WaveCloseReadFile()
    //         00448766     ADD        ESP,0x8
    //                              Dsutil.c:1459 (2)
    //         00448769     XOR        EAX,EAX
    //                              Dsutil.c:1595 (8)
    //         0044876b     POP        EDI
    //         0044876c     POP        ESI
    //         0044876d     POP        EBP
    //         0044876e     POP        EBX
    //         0044876f     ADD        ESP,0x28
    //         00448772     RET
    //                               LAB_00448773                                                 XREF[1]:     00448755(j)  
    //                              Dsutil.c:1463 (27)
    //         00448773     PUSH       null_0088847c                                    = align(4)
    //         00448778     PUSH       DAT_00888468                                     = align(24)
    //         0044877d     PUSH       DAT_00888464
    //         00448782     CALL       _WaveStartDataRead                               undefined _WaveStartDataRead()
    //         00448787     ADD        ESP,0xc
    //         0044878a     CMP        EAX,EBX
    //         0044878c     JZ         LAB_004487aa
    //                              Dsutil.c:1466 (18)
    //         0044878e     PUSH       _wiWave
    //         00448793     PUSH       DAT_00888464
    //         00448798     CALL       _WaveCloseReadFile                               undefined _WaveCloseReadFile()
    //         0044879d     ADD        ESP,0x8
    //                              Dsutil.c:1468 (2)
    //         004487a0     XOR        EAX,EAX
    //                              Dsutil.c:1595 (8)
    //         004487a2     POP        EDI
    //         004487a3     POP        ESI
    //         004487a4     POP        EBP
    //         004487a5     POP        EBX
    //         004487a6     ADD        ESP,0x28
    //         004487a9     RET
    //                               LAB_004487aa                                                 XREF[1]:     0044878c(j)  
    //                              Dsutil.c:1479 (6)
    //         004487aa     MOV        EDX,dword ptr [_wiWave]
    //                              Dsutil.c:1490 (62)
    //         004487b0     PUSH       0x14
    //         004487b2     PUSH       EBX
    //         004487b3     MOV        EAX,dword ptr [EDX + 0x8]
    //         004487b6     LEA        EAX,[EAX + EAX*0x2]
    //         004487b9     LEA        ECX,[EAX + EAX*0x4]
    //         004487bc     MOV        EAX,0x51eb851f
    //         004487c1     SHL        ECX,0x3
    //         004487c4     MUL        ECX
    //         004487c6     SHR        EDX,0x5
    //         004487c9     MOV        EAX,0xaaaaaaab
    //         004487ce     MUL        EDX
    //         004487d0     SHR        EDX,0x2
    //         004487d3     MOV        dword ptr [DAT_00888498],EDX
    //         004487d9     LEA        EAX=>dsbd.dwFlags,[ESP + 0x2c]
    //         004487dd     LEA        EDX,[EDX + EDX*0x2]
    //         004487e0     PUSH       EAX
    //         004487e1     SHL        EDX,0x1
    //         004487e3     MOV        dword ptr [DAT_00888494],EDX
    //         004487e9     CALL       memset                                           undefined memset()
    //                              Dsutil.c:1496 (12)
    //         004487ee     MOV        EDX,dword ptr [_wiWave]
    //         004487f4     MOV        ECX,dword ptr [DAT_00888494]
    //                              Dsutil.c:1497 (49)
    //         004487fa     MOV        EAX,[_lpDS]
    //         004487ff     ADD        ESP,0xc
    //         00448802     MOV        dword ptr [ESP + local_4],EDX
    //         00448806     LEA        EDX=>dsbd.dwFlags,[ESP + 0x24]
    //         0044880a     PUSH       EBX
    //         0044880b     MOV        dword ptr [ESP + dsbd.dwFlags],0x14
    //         00448813     MOV        dword ptr [ESP + dsbd.dwBufferBytes],0xe0
    //         0044881b     MOV        dword ptr [ESP + dsbd.dwReserved],ECX
    //         0044881f     MOV        ECX,dword ptr [EAX]
    //         00448821     PUSH       _lpDSBStreamBuffer
    //         00448826     PUSH       EDX
    //         00448827     PUSH       EAX
    //         00448828     CALL       dword ptr [ECX + 0xc]
    //                              Dsutil.c:1498 (4)
    //         0044882b     CMP        EAX,EBX
    //         0044882d     JZ         LAB_00448839
    //                              Dsutil.c:1502 (2)
    //         0044882f     XOR        EAX,EAX
    //                              Dsutil.c:1595 (8)
    //         00448831     POP        EDI
    //         00448832     POP        ESI
    //         00448833     POP        EBP
    //         00448834     POP        EBX
    //         00448835     ADD        ESP,0x28
    //         00448838     RET
    //                               LAB_00448839                                                 XREF[1]:     0044882d(j)  
    //                              Dsutil.c:1512 (57)
    //         00448839     LEA        EDX,[ESP + 0x20]
    //         0044883d     PUSH       EBX
    //         0044883e     PUSH       EDX=>DAT_fffffff8
    //         0044883f     LEA        EDX,[ESP + 0x24]
    //         00448843     MOV        EAX,[_lpDSBStreamBuffer]
    //         00448848     PUSH       EDX=>DAT_fffffff4
    //         00448849     LEA        EDX,[ESP + 0x1c]
    //         0044884d     MOV        [DAT_00888490],EAX
    //         00448852     PUSH       EDX=>DAT_fffffff0
    //         00448853     LEA        EDX,[ESP + 0x24]
    //         00448857     PUSH       EDX
    //         00448858     MOV        EDX,dword ptr [DAT_00888494]
    //         0044885e     MOV        dword ptr [DAT_008884b0],EBX
    //         00448864     MOV        dword ptr [DAT_008884b4],EBX
    //         0044886a     MOV        ECX,dword ptr [EAX]
    //         0044886c     PUSH       EDX
    //         0044886d     PUSH       EBX
    //         0044886e     PUSH       EAX
    //         0044886f     CALL       dword ptr [ECX + 0x2c]
    //                              Dsutil.c:1513 (4)
    //         00448872     CMP        EAX,EBX
    //         00448874     JZ         LAB_00448880
    //                              Dsutil.c:1516 (2)
    //         00448876     XOR        EAX,EAX
    //                              Dsutil.c:1595 (8)
    //         00448878     POP        EDI
    //         00448879     POP        ESI
    //         0044887a     POP        EBP
    //         0044887b     POP        EBX
    //         0044887c     ADD        ESP,0x28
    //         0044887f     RET
    //                               LAB_00448880                                                 XREF[1]:     00448874(j)  
    //                              Dsutil.c:1519 (12)
    //         00448880     MOV        ESI,dword ptr [ESP + 0x10]
    //         00448884     CMP        ESI,EBX
    //         00448886     JZ         LAB_00448955
    //                              Dsutil.c:1522 (28)
    //         0044888c     MOV        ECX,dword ptr [ESP + 0x14]
    //         00448890     MOV        EDX,dword ptr [DAT_00888464]
    //         00448896     LEA        EAX,[ESP + 0x18]
    //         0044889a     PUSH       EAX
    //         0044889b     PUSH       DAT_00888468                                     = align(24)
    //         004488a0     PUSH       ECX=>DAT_fffffff4
    //         004488a1     PUSH       ESI=>DAT_fffffff0
    //         004488a2     PUSH       EDX
    //         004488a3     CALL       _WaveReadFile                                    undefined _WaveReadFile()
    //                              Dsutil.c:1523 (19)
    //         004488a8     MOV        ECX,dword ptr [ESP + 0x2c]
    //         004488ac     MOV        ESI,dword ptr [ESP + 0x24]
    //         004488b0     ADD        ESP,0x14
    //         004488b3     CMP        ECX,ESI
    //         004488b5     JNC        LAB_00448955
    //                              Dsutil.c:1525 (8)
    //         004488bb     CMP        dword ptr [DAT_008884ac],EBX
    //         004488c1     JZ         LAB_00448913
    //                              Dsutil.c:1531 (4)
    //         004488c3     MOV        EDI,dword ptr [ESP + 0x14]
    //                               LAB_004488c7                                                 XREF[1]:     0044890f(j)  
    //                              Dsutil.c:1544 (28)
    //         004488c7     PUSH       null_0088847c                                    = align(4)
    //         004488cc     SUB        ESI,ECX
    //         004488ce     PUSH       DAT_00888468                                     = align(24)
    //         004488d3     PUSH       DAT_00888464
    //         004488d8     ADD        EDI,ECX
    //         004488da     MOV        dword ptr [ESP + 0x1c],ESI
    //         004488de     CALL       _WaveStartDataRead                               undefined _WaveStartDataRead()
    //                              Dsutil.c:1547 (31)
    //         004488e3     MOV        ECX,dword ptr [ESP + 0x1c]
    //         004488e7     MOV        EDX,dword ptr [DAT_00888464]
    //         004488ed     ADD        ESP,0xc
    //         004488f0     LEA        EAX,[ESP + 0x18]
    //         004488f4     PUSH       EAX
    //         004488f5     PUSH       DAT_00888468                                     = align(24)
    //         004488fa     PUSH       EDI=>DAT_fffffff4
    //         004488fb     PUSH       ECX=>DAT_fffffff0
    //         004488fc     PUSH       EDX
    //         004488fd     CALL       _WaveReadFile                                    undefined _WaveReadFile()
    //                              Dsutil.c:1548 (15)
    //         00448902     MOV        ECX,dword ptr [ESP + 0x2c]
    //         00448906     MOV        ESI,dword ptr [ESP + 0x24]
    //         0044890a     ADD        ESP,0x14
    //         0044890d     CMP        ECX,ESI
    //         0044890f     JC         LAB_004488c7
    //                              Dsutil.c:1550 (2)
    //         00448911     JMP        LAB_00448955
    //                               LAB_00448913                                                 XREF[1]:     004488c1(j)  
    //                              Dsutil.c:1554 (10)
    //         00448913     MOV        EAX,ECX
    //         00448915     XOR        EDX,EDX
    //         00448917     DIV        dword ptr [DAT_00888498]
    //                              Dsutil.c:1559 (56)
    //         0044891d     MOV        EDX,dword ptr [_wiWave]
    //         00448923     MOV        dword ptr [DAT_008884b0],EBP
    //         00448929     SUB        ESI,ECX
    //         0044892b     PUSH       ESI
    //         0044892c     MOV        [DAT_008884b4],EAX
    //         00448931     XOR        EAX,EAX
    //         00448933     CMP        word ptr [EDX + 0xe],0x8
    //         00448938     SETNZ      AL
    //         0044893b     DEC        EAX
    //         0044893c     AND        EAX,0x80
    //         00448941     PUSH       EAX=>DAT_fffffff8
    //         00448942     MOV        EAX,dword ptr [ESP + 0x1c]
    //         00448946     ADD        ECX,EAX
    //         00448948     PUSH       ECX=>DAT_fffffff4
    //         00448949     CALL       memset                                           undefined memset()
    //         0044894e     MOV        ESI,dword ptr [ESP + 0x1c]
    //         00448952     ADD        ESP,0xc
    //                               LAB_00448955                                                 XREF[3]:     00448886(j), 004488b5(j), 
    //                                                                                                         00448911(j)  
    //                              Dsutil.c:1564 (23)
    //         00448955     MOV        EDX,dword ptr [ESP + 0x1c]
    //         00448959     MOV        EAX,[_lpDSBStreamBuffer]
    //         0044895e     PUSH       EBX
    //         0044895f     PUSH       EDX=>DAT_fffffff8
    //         00448960     MOV        EDX,dword ptr [ESP + 0x1c]
    //         00448964     MOV        ECX,dword ptr [EAX]
    //         00448966     PUSH       ESI=>DAT_fffffff4
    //         00448967     PUSH       EDX=>DAT_fffffff0
    //         00448968     PUSH       EAX
    //         00448969     CALL       dword ptr [ECX + 0x4c]
    //                              Dsutil.c:1567 (4)
    //         0044896c     MOV        EAX,dword ptr [ESP + 0x40]
    //                              Dsutil.c:1571 (60)
    //         00448970     MOV        ECX,dword ptr [_main_wnd]
    //         00448976     PUSH       EBX
    //         00448977     PUSH       EBX=>DAT_fffffff8
    //         00448978     AND        EAX,0xff
    //         0044897d     PUSH       offset DAT_fffffff4
    //         00448982     PUSH       ECX=>DAT_fffffff0
    //         00448983     MOV        dword ptr [DAT_008884a4],EBX
    //         00448989     MOV        dword ptr [DAT_008884a0],EBX
    //         0044898f     MOV        dword ptr [DAT_0088849c],EBX
    //         00448995     MOV        dword ptr [DAT_008884a8],EBX
    //         0044899b     MOV        [DAT_008884ac],EAX
    //         004489a0     MOV        dword ptr [_bFileOpen],EBP
    //         004489a6     CALL       dword ptr [->USER32.DLL::SendMessageA]           = 0048ad08
    //                              Dsutil.c:1574 (12)
    //         004489ac     MOV        EAX,[_lpDSBStreamBuffer]
    //         004489b1     PUSH       EBX
    //         004489b2     PUSH       EAX=>DAT_fffffff8
    //         004489b3     MOV        EDX,dword ptr [EAX]
    //         004489b5     CALL       dword ptr [EDX + 0x34]
    //                              Dsutil.c:1575 (16)
    //         004489b8     MOV        EAX,[_lpDSBStreamBuffer]
    //         004489bd     MOV        EDX,dword ptr [ESP + 0x44]
    //         004489c1     PUSH       EDX
    //         004489c2     PUSH       EAX=>DAT_fffffff8
    //         004489c3     MOV        ECX,dword ptr [EAX]
    //         004489c5     CALL       dword ptr [ECX + 0x3c]
    //                              Dsutil.c:1576 (14)
    //         004489c8     MOV        EAX,[_lpDSBStreamBuffer]
    //         004489cd     PUSH       EBP
    //         004489ce     PUSH       EBX=>DAT_fffffff8
    //         004489cf     PUSH       EBX=>DAT_fffffff4
    //         004489d0     MOV        ECX,dword ptr [EAX]
    //         004489d2     PUSH       EAX=>DAT_fffffff0
    //         004489d3     CALL       dword ptr [ECX + 0x30]
    //                              Dsutil.c:1578 (12)
    //         004489d6     PUSH       0x32
    //         004489d8     CALL       dword ptr [->WINMM.DLL::timeBeginPeriod]         = 0048b4fe
    //         004489de     TEST       EAX,EAX
    //         004489e0     JZ         LAB_00448a03
    //                              Dsutil.c:1581 (11)
    //         004489e2     MOV        EAX,[_lpDSBStreamBuffer]
    //         004489e7     PUSH       EAX
    //         004489e8     MOV        EDX,dword ptr [EAX]
    //         004489ea     CALL       dword ptr [EDX + 0x48]
    //                              Dsutil.c:1582 (12)
    //         004489ed     MOV        dword ptr [_bTimerInstalled],EBX
    //         004489f3     MOV        dword ptr [_bPlaying],EBX
    //                              Dsutil.c:1584 (2)
    //         004489f9     XOR        EAX,EAX
    //                              Dsutil.c:1595 (8)
    //         004489fb     POP        EDI
    //         004489fc     POP        ESI
    //         004489fd     POP        EBP
    //         004489fe     POP        EBX
    //         004489ff     ADD        ESP,0x28
    //         00448a02     RET
    //                               LAB_00448a03                                                 XREF[1]:     004489e0(j)  
    //                              Dsutil.c:1588 (26)
    //         00448a03     PUSH       EBP
    //         00448a04     PUSH       EBX=>DAT_fffffff8
    //         00448a05     PUSH       ds_stream_time_func
    //         00448a0a     PUSH       offset DAT_fffffff0
    //         00448a0c     PUSH       0x32
    //         00448a0e     CALL       dword ptr [->WINMM.DLL::timeSetEvent]            = 0048b4ee
    //         00448a14     CMP        EAX,EBX
    //         00448a16     MOV        [_uTimerID],EAX
    //         00448a1b     JZ         LAB_00448a23
    //                              Dsutil.c:1589 (6)
    //         00448a1d     MOV        dword ptr [_bTimerInstalled],EBP
    //                               LAB_00448a23                                                 XREF[1]:     00448a1b(j)  
    //                              Dsutil.c:1595 (16)
    //         00448a23     POP        EDI
    //         00448a24     MOV        dword ptr [_bPlaying],EBP
    //         00448a2a     MOV        EAX,EBP
    //         00448a2c     POP        ESI
    //         00448a2d     POP        EBP
    //         00448a2e     POP        EBX
    //         00448a2f     ADD        ESP,0x28
    //         00448a32     RET
}

// Offset: 0x00448A40
undefined ds_stream_volume() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * ds_stream_volume                                                                                      *
    //                              *********************************************************************************************************
    //                              undefined __cdecl ds_stream_volume()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _ds_stream_volume                                            XREF[1]:     set_stream_volume:004bc93f(c)  
    //                               ds_stream_volume
    //                              Dsutil.c:1602 (9)
    //         00448a40     MOV        EAX,[_lpDSBStreamBuffer]
    //         00448a45     TEST       EAX,EAX
    //         00448a47     JNZ        LAB_00448a4a
    //                              Dsutil.c:1614 (1)
    //         00448a49     RET
    //                               LAB_00448a4a                                                 XREF[1]:     00448a47(j)  
    //                              Dsutil.c:1608 (11)
    //         00448a4a     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         00448a4e     MOV        ECX,dword ptr [EAX]
    //         00448a50     PUSH       EDX
    //         00448a51     PUSH       EAX
    //         00448a52     CALL       dword ptr [ECX + 0x3c]
    //                              Dsutil.c:1610 (9)
    //         00448a55     XOR        ECX,ECX
    //         00448a57     TEST       EAX,EAX
    //         00448a59     SETZ       CL
    //         00448a5c     MOV        EAX,ECX
    //                              Dsutil.c:1614 (1)
    //         00448a5e     RET
}

// Offset: 0x00448A60
undefined ds_stream_pause() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * ds_stream_pause                                                                                       *
    //                              *********************************************************************************************************
    //                              undefined __cdecl ds_stream_pause()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _ds_stream_pause                                             XREF[1]:     pause_stream:004bc958(c)  
    //                               ds_stream_pause
    //                              Dsutil.c:1620 (10)
    //         00448a60     MOV        EAX,0x1
    //         00448a65     MOV        [_stream_paused],EAX
    //                              Dsutil.c:1623 (1)
    //         00448a6a     RET
}

// Offset: 0x00448A70
undefined ds_stream_resume() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * ds_stream_resume                                                                                      *
    //                              *********************************************************************************************************
    //                              undefined __cdecl ds_stream_resume()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _ds_stream_resume                                            XREF[1]:     resume_stream:004bc968(c)  
    //                               ds_stream_resume
    //                              Dsutil.c:1629 (10)
    //         00448a70     MOV        dword ptr [_stream_paused],0x0
    //                              Dsutil.c:1631 (5)
    //         00448a7a     MOV        EAX,0x1
    //                              Dsutil.c:1632 (1)
    //         00448a7f     RET
}

// Offset: 0x00448A80
undefined ds_stream_stop() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * ds_stream_stop                                                                                        *
    //                              *********************************************************************************************************
    //                              undefined __cdecl ds_stream_stop()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _ds_stream_stop                                              XREF[4]:     ds_stream_exit:004486d4(c), 
    //                               ds_stream_stop                                                            ds_stream_file:00448712(c), 
    //                                                                                                         ds_stream_messages:00448b8e(c), 
    //                                                                                                         stop_stream:004bc978(c)  
    //                              Dsutil.c:1638 (22)
    //         00448a80     MOV        EAX,[_bTimerInstalled]
    //         00448a85     PUSH       ESI
    //         00448a86     XOR        ESI,ESI
    //         00448a88     MOV        dword ptr [DAT_008884a8],0x1
    //         00448a92     CMP        EAX,ESI
    //         00448a94     JZ         LAB_00448ab0
    //                              Dsutil.c:1646 (18)
    //         00448a96     MOV        EAX,[_uTimerID]
    //         00448a9b     MOV        dword ptr [_bTimerInstalled],ESI
    //         00448aa1     PUSH       EAX
    //         00448aa2     CALL       dword ptr [->WINMM.DLL::timeKillEvent]           = 0048b520
    //                              Dsutil.c:1647 (8)
    //         00448aa8     PUSH       0x32
    //         00448aaa     CALL       dword ptr [->WINMM.DLL::timeEndPeriod]           = 0048b510
    //                               LAB_00448ab0                                                 XREF[1]:     00448a94(j)  
    //                              Dsutil.c:1650 (8)
    //         00448ab0     CMP        dword ptr [_bPlaying],ESI
    //         00448ab6     JZ         LAB_00448acd
    //                              Dsutil.c:1653 (15)
    //         00448ab8     MOV        EAX,[_lpDSBStreamBuffer]
    //         00448abd     MOV        dword ptr [_bPlaying],ESI
    //         00448ac3     CMP        EAX,ESI
    //         00448ac5     JZ         LAB_00448ad2
    //                              Dsutil.c:1654 (11)
    //         00448ac7     MOV        ECX,dword ptr [EAX]
    //         00448ac9     PUSH       EAX
    //         00448aca     CALL       dword ptr [ECX + 0x48]
    //                               LAB_00448acd                                                 XREF[1]:     00448ab6(j)  
    //         00448acd     MOV        EAX,[_lpDSBStreamBuffer]
    //                               LAB_00448ad2                                                 XREF[1]:     00448ac5(j)  
    //                              Dsutil.c:1661 (8)
    //         00448ad2     CMP        dword ptr [_bFileOpen],ESI
    //         00448ad8     JZ         LAB_00448b1b
    //                              Dsutil.c:1663 (8)
    //         00448ada     CMP        dword ptr [_wiWave],ESI
    //         00448ae0     JZ         LAB_00448aff
    //                              Dsutil.c:1665 (15)
    //         00448ae2     PUSH       _wiWave
    //         00448ae7     PUSH       DAT_00888464
    //         00448aec     CALL       _WaveCloseReadFile                               undefined _WaveCloseReadFile()
    //                              Dsutil.c:1666 (14)
    //         00448af1     MOV        EAX,[_lpDSBStreamBuffer]
    //         00448af6     ADD        ESP,0x8
    //         00448af9     MOV        dword ptr [_wiWave],ESI
    //                               LAB_00448aff                                                 XREF[1]:     00448ae0(j)  
    //                              Dsutil.c:1668 (4)
    //         00448aff     CMP        EAX,ESI
    //         00448b01     JZ         LAB_00448b15
    //                              Dsutil.c:1670 (6)
    //         00448b03     MOV        EDX,dword ptr [EAX]
    //         00448b05     PUSH       EAX
    //         00448b06     CALL       dword ptr [EDX + 0x8]
    //                              Dsutil.c:1671 (6)
    //         00448b09     MOV        dword ptr [_lpDSBStreamBuffer],ESI
    //                              Dsutil.c:1672 (6)
    //         00448b0f     MOV        dword ptr [DAT_00888490],ESI
    //                               LAB_00448b15                                                 XREF[1]:     00448b01(j)  
    //                              Dsutil.c:1674 (6)
    //         00448b15     MOV        dword ptr [_bFileOpen],ESI
    //                               LAB_00448b1b                                                 XREF[1]:     00448ad8(j)  
    //                              Dsutil.c:1677 (5)
    //         00448b1b     MOV        EAX,0x1
    //                              Dsutil.c:1678 (2)
    //         00448b20     POP        ESI
    //         00448b21     RET
}

// Offset: 0x00448B30
undefined ds_stream_messages() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * ds_stream_messages                                                                                    *
    //                              *********************************************************************************************************
    //                              undefined __cdecl ds_stream_messages()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined8        Stack[-0x8]:8  local_8                   XREF[2,1]:   00448b6e(*), 00448b72(*), 00448b5e(W)  
    //                               _ds_stream_messages                                          XREF[1]:     handle_messages:004bc99e(c)  
    //                               ds_stream_messages
    //                              Dsutil.c:1684 (19)
    //         00448b30     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         00448b34     SUB        ESP,0x8
    //         00448b37     SUB        EAX,0x500
    //         00448b3c     JZ         LAB_00448b8e
    //         00448b3e     SUB        EAX,0x2
    //         00448b41     JNZ        LAB_00448b93
    //                              Dsutil.c:1693 (15)
    //         00448b43     MOV        EAX,[DAT_008884a4]
    //         00448b48     MOV        ECX,dword ptr [DAT_00888480]
    //         00448b4e     CMP        EAX,ECX
    //         00448b50     JBE        LAB_00448b59
    //                              Dsutil.c:1694 (7)
    //         00448b52     SUB        EAX,ECX
    //         00448b54     MOV        [DAT_008884a4],EAX
    //                               LAB_00448b59                                                 XREF[1]:     00448b50(j)  
    //                              Dsutil.c:1699 (34)
    //         00448b59     LEA        EAX,[EAX + EAX*0x4]
    //         00448b5c     XOR        EDX,EDX
    //         00448b5e     MOV        dword ptr [ESP + local_8+0x4],0x0
    //         00448b66     LEA        EAX,[EAX + EAX*0x4]
    //         00448b69     SHL        EAX,0x2
    //         00448b6c     DIV        ECX
    //         00448b6e     MOV        dword ptr [ESP]=>local_8,EAX
    //         00448b72     FILD       qword ptr [ESP]=>local_8
    //         00448b76     CALL       __ftol                                           undefined __ftol()
    //                              Dsutil.c:1700 (8)
    //         00448b7b     CMP        EAX,dword ptr [_uLastPercent]
    //         00448b81     JZ         LAB_00448b93
    //                              Dsutil.c:1702 (5)
    //         00448b83     MOV        [_uLastPercent],EAX
    //                              Dsutil.c:1717 (2)
    //         00448b88     XOR        EAX,EAX
    //                              Dsutil.c:1718 (4)
    //         00448b8a     ADD        ESP,0x8
    //         00448b8d     RET
    //                               LAB_00448b8e                                                 XREF[1]:     00448b3c(j)  
    //                              Dsutil.c:1714 (5)
    //         00448b8e     CALL       ds_stream_stop                                   undefined ds_stream_stop()
    //                               LAB_00448b93                                                 XREF[2]:     00448b41(j), 00448b81(j)  
    //                              Dsutil.c:1717 (2)
    //         00448b93     XOR        EAX,EAX
    //                              Dsutil.c:1718 (4)
    //         00448b95     ADD        ESP,0x8
    //         00448b98     RET
}

// Offset: 0x00448BA0
undefined ds_stream_time_func() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * __stdcall ds_stream_time_func,20                                                                      *
    //                              *********************************************************************************************************
    //                              undefined __stdcall ds_stream_time_func()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined         Stack[-0x4]:1  local_4                   XREF[1]:     00448be8(*)  
    //              ulong             Stack[-0x8]:4  dwWrite                   XREF[1]:     00448bed(*)  
    //              ulong             Stack[-0xc]:4  dwPlay
    //              uchar *           Stack[-0x10]:4 lpWrite2
    //              uint              Stack[-0x14]:4 uChkErr
    //              uchar *           Stack[-0x18]:4 lpWrite1
    //              ulong             Stack[-0x1c]:4 dwLen2
    //              ulong             Stack[-0x20]:4 dwLen1
    //                               _ds_stream_time_func@20                                      XREF[1]:     ds_stream_file:00448a05(*)  
    //                               ds_stream_time_func
    //                              Dsutil.c:1726 (33)
    //         00448ba0     MOV        EAX,[DAT_0062e658]
    //         00448ba5     SUB        ESP,0x1c
    //         00448ba8     PUSH       EBX
    //         00448ba9     PUSH       EBP
    //         00448baa     XOR        EBP,EBP
    //         00448bac     PUSH       ESI
    //         00448bad     CMP        EAX,EBP
    //         00448baf     JNZ        LAB_004490cb
    //         00448bb5     CMP        dword ptr [_stream_paused],EBP
    //         00448bbb     JNZ        LAB_004490cb
    //                              Dsutil.c:1738 (37)
    //         00448bc1     MOV        EAX,[DAT_008884a8]
    //         00448bc6     MOV        EBX,0x1
    //         00448bcb     CMP        EAX,EBP
    //         00448bcd     MOV        dword ptr [DAT_0062e658],EBX
    //         00448bd3     JNZ        LAB_004490c5
    //         00448bd9     MOV        EAX,[DAT_00888490]
    //         00448bde     CMP        EAX,EBP
    //         00448be0     JZ         LAB_004490c5
    //                              Dsutil.c:1746 (16)
    //         00448be6     MOV        ECX,dword ptr [EAX]
    //         00448be8     LEA        EDX=>local_4,[ESP + 0x24]
    //         00448bec     PUSH       EDX
    //         00448bed     LEA        EDX=>dwWrite,[ESP + 0x24]
    //         00448bf1     PUSH       EDX
    //         00448bf2     PUSH       EAX
    //         00448bf3     CALL       dword ptr [ECX + 0x10]
    //                              Dsutil.c:1754 (24)
    //         00448bf6     MOV        ECX,dword ptr [DAT_0088849c]
    //         00448bfc     MOV        EAX,dword ptr [ESP + 0x20]
    //         00448c00     CMP        ECX,EAX
    //         00448c02     JNC        LAB_00448c14
    //         00448c04     MOV        EDX,dword ptr [DAT_00888498]
    //         00448c0a     ADD        ECX,EDX
    //         00448c0c     CMP        ECX,EAX
    //                              Dsutil.c:1757 (6)
    //         00448c0e     JA         LAB_004490c5
    //                               LAB_00448c14                                                 XREF[1]:     00448c02(j)  
    //                              Dsutil.c:1761 (16)
    //         00448c14     CMP        dword ptr [DAT_008884b0],EBP
    //         00448c1a     JZ         LAB_00448c58
    //         00448c1c     CMP        dword ptr [DAT_008884b4],EBP
    //         00448c22     JNZ        LAB_00448c58
    //                              Dsutil.c:1763 (12)
    //         00448c24     CMP        dword ptr [DAT_008884a8],EBP
    //         00448c2a     JNZ        LAB_004490c5
    //                              Dsutil.c:1766 (31)
    //         00448c30     MOV        EAX,[_main_wnd]
    //         00448c35     PUSH       EBP
    //         00448c36     PUSH       EBP=>DAT_fffffff8
    //         00448c37     PUSH       offset DAT_fffffff4
    //         00448c3c     PUSH       EAX=>DAT_fffffff0
    //         00448c3d     MOV        dword ptr [DAT_008884a8],EBX
    //         00448c43     CALL       dword ptr [->USER32.DLL::PostMessageA]           = 0048afc2
    //         00448c49     MOV        dword ptr [DAT_0062e658],EBP
    //                              Dsutil.c:1983 (9)
    //         00448c4f     POP        ESI
    //         00448c50     POP        EBP
    //         00448c51     POP        EBX
    //         00448c52     ADD        ESP,0x1c
    //         00448c55     RET        0x14
    //                               LAB_00448c58                                                 XREF[2]:     00448c1a(j), 00448c22(j)  
    //                              Dsutil.c:1772 (10)
    //         00448c58     MOV        ECX,dword ptr [DAT_008884a0]
    //         00448c5e     CMP        EAX,ECX
    //         00448c60     JNC        LAB_00448c6c
    //                              Dsutil.c:1773 (8)
    //         00448c62     MOV        EDX,dword ptr [DAT_00888494]
    //         00448c68     ADD        EDX,EAX
    //                              Dsutil.c:1774 (2)
    //         00448c6a     JMP        LAB_00448c6e
    //                               LAB_00448c6c                                                 XREF[1]:     00448c60(j)  
    //                              Dsutil.c:1775 (10)
    //         00448c6c     MOV        EDX,EAX
    //                               LAB_00448c6e                                                 XREF[1]:     00448c6a(j)  
    //         00448c6e     SUB        EDX,ECX
    //         00448c70     MOV        ECX,dword ptr [DAT_008884a4]
    //                              Dsutil.c:1776 (5)
    //         00448c76     MOV        [DAT_008884a0],EAX
    //                              Dsutil.c:1777 (27)
    //         00448c7b     MOV        EAX,[_main_wnd]
    //         00448c80     PUSH       EBP
    //         00448c81     PUSH       EBP=>DAT_fffffff8
    //         00448c82     ADD        ECX,EDX
    //         00448c84     PUSH       offset DAT_fffffff4
    //         00448c89     PUSH       EAX=>DAT_fffffff0
    //         00448c8a     MOV        dword ptr [DAT_008884a4],ECX
    //         00448c90     CALL       dword ptr [->USER32.DLL::PostMessageA]           = 0048afc2
    //                              Dsutil.c:1784 (25)
    //         00448c96     CMP        dword ptr [DAT_008884b0],EBP
    //         00448c9c     JZ         LAB_00448d7b
    //         00448ca2     MOV        EAX,[DAT_008884b4]
    //         00448ca7     CMP        EAX,EBP
    //         00448ca9     JZ         LAB_00448d7b
    //                              Dsutil.c:1786 (1)
    //         00448caf     DEC        EAX
    //                              Dsutil.c:1788 (26)
    //         00448cb0     CMP        EAX,EBX
    //         00448cb2     MOV        [DAT_008884b4],EAX
    //         00448cb7     JLE        LAB_004490c5
    //         00448cbd     MOV        EAX,[DAT_00888490]
    //         00448cc2     CMP        EAX,EBP
    //         00448cc4     JZ         LAB_004490c5
    //                              Dsutil.c:1795 (43)
    //         00448cca     LEA        EDX,[ESP + 0x10]
    //         00448cce     PUSH       EBP
    //         00448ccf     PUSH       EDX=>DAT_fffffff8
    //         00448cd0     LEA        EDX,[ESP + 0x24]
    //         00448cd4     PUSH       EDX=>DAT_fffffff4
    //         00448cd5     LEA        EDX,[ESP + 0x18]
    //         00448cd9     PUSH       EDX=>DAT_fffffff0
    //         00448cda     MOV        ECX,dword ptr [EAX]
    //         00448cdc     LEA        EDX,[ESP + 0x24]
    //         00448ce0     PUSH       EDX
    //         00448ce1     MOV        EDX,dword ptr [DAT_00888498]
    //         00448ce7     PUSH       EDX
    //         00448ce8     MOV        EDX,dword ptr [DAT_0088849c]
    //         00448cee     PUSH       EDX
    //         00448cef     PUSH       EAX
    //         00448cf0     CALL       dword ptr [ECX + 0x2c]
    //         00448cf3     TEST       EAX,EAX
    //                              Dsutil.c:1799 (6)
    //         00448cf5     JNZ        LAB_004490c5
    //                              Dsutil.c:1803 (17)
    //         00448cfb     MOV        EAX,[_wiWave]
    //         00448d00     CMP        EAX,EBP
    //         00448d02     JZ         LAB_00448d37
    //         00448d04     MOV        ECX,dword ptr [ESP + 0x14]
    //         00448d08     CMP        ECX,EBP
    //         00448d0a     JZ         LAB_00448d37
    //                              Dsutil.c:1805 (10)
    //         00448d0c     MOV        AX,word ptr [EAX + 0xe]
    //         00448d10     CMP        AX,0x8
    //         00448d14     JNZ        LAB_00448d22
    //                              Dsutil.c:1806 (10)
    //         00448d16     MOV        EAX,dword ptr [ESP + 0xc]
    //         00448d1a     PUSH       EAX
    //                              language.dll match for 0x80: "Arial"
    //         00448d1b     PUSH       offset DAT_fffffff8
    //                              Dsutil.c:1807 (8)
    //         00448d20     JMP        LAB_00448d2e
    //                               LAB_00448d22                                                 XREF[1]:     00448d14(j)  
    //         00448d22     CMP        AX,0x10
    //         00448d26     JNZ        LAB_00448d37
    //                              Dsutil.c:1808 (15)
    //         00448d28     MOV        EDX,dword ptr [ESP + 0xc]
    //         00448d2c     PUSH       EDX
    //         00448d2d     PUSH       EBP=>DAT_fffffff8
    //                               LAB_00448d2e                                                 XREF[1]:     00448d20(j)  
    //         00448d2e     PUSH       ECX=>DAT_fffffff4
    //         00448d2f     CALL       memset                                           undefined memset()
    //         00448d34     ADD        ESP,0xc
    //                               LAB_00448d37                                                 XREF[3]:     00448d02(j), 00448d0a(j), 
    //                                                                                                         00448d26(j)  
    //                              Dsutil.c:1813 (31)
    //         00448d37     MOV        EDX,dword ptr [ESP + 0x10]
    //         00448d3b     MOV        EAX,[DAT_00888490]
    //         00448d40     PUSH       EDX
    //         00448d41     MOV        EDX,dword ptr [ESP + 0x20]
    //         00448d45     MOV        ECX,dword ptr [EAX]
    //         00448d47     PUSH       EDX=>DAT_fffffff8
    //         00448d48     MOV        EDX,dword ptr [ESP + 0x14]
    //         00448d4c     PUSH       EDX=>DAT_fffffff4
    //         00448d4d     MOV        EDX,dword ptr [ESP + 0x20]
    //         00448d51     PUSH       EDX=>DAT_fffffff0
    //         00448d52     PUSH       EAX
    //         00448d53     CALL       dword ptr [ECX + 0x4c]
    //                              Dsutil.c:1820 (11)
    //         00448d56     MOV        EAX,[DAT_0088849c]
    //         00448d5b     MOV        ESI,dword ptr [DAT_00888498]
    //                              Dsutil.c:1821 (21)
    //         00448d61     MOV        ECX,dword ptr [DAT_00888494]
    //         00448d67     ADD        EAX,ESI
    //         00448d69     CMP        EAX,ECX
    //         00448d6b     MOV        [DAT_0088849c],EAX
    //         00448d70     JC         LAB_004490c5
    //                              Dsutil.c:1826 (5)
    //         00448d76     JMP        LAB_004490be
    //                               LAB_00448d7b                                                 XREF[2]:     00448c9c(j), 00448ca9(j)  
    //                              Dsutil.c:1830 (7)
    //         00448d7b     MOV        EAX,[DAT_00888490]
    //         00448d80     CMP        EAX,EBP
    //                              Dsutil.c:1833 (6)
    //         00448d82     JZ         LAB_004490c5
    //                              Dsutil.c:1841 (43)
    //         00448d88     LEA        EDX,[ESP + 0x10]
    //         00448d8c     PUSH       EBP
    //         00448d8d     PUSH       EDX=>DAT_fffffff8
    //         00448d8e     LEA        EDX,[ESP + 0x24]
    //         00448d92     PUSH       EDX=>DAT_fffffff4
    //         00448d93     LEA        EDX,[ESP + 0x18]
    //         00448d97     PUSH       EDX=>DAT_fffffff0
    //         00448d98     MOV        ECX,dword ptr [EAX]
    //         00448d9a     LEA        EDX,[ESP + 0x24]
    //         00448d9e     PUSH       EDX
    //         00448d9f     MOV        EDX,dword ptr [DAT_00888498]
    //         00448da5     PUSH       EDX
    //         00448da6     MOV        EDX,dword ptr [DAT_0088849c]
    //         00448dac     PUSH       EDX
    //         00448dad     PUSH       EAX
    //         00448dae     CALL       dword ptr [ECX + 0x2c]
    //         00448db1     TEST       EAX,EAX
    //                              Dsutil.c:1845 (6)
    //         00448db3     JNZ        LAB_004490c5
    //                              Dsutil.c:1849 (26)
    //         00448db9     MOV        EAX,dword ptr [ESP + 0xc]
    //         00448dbd     MOV        ECX,dword ptr [DAT_008884a8]
    //         00448dc3     CMP        EAX,EBP
    //         00448dc5     JZ         LAB_00448ee3
    //         00448dcb     CMP        ECX,EBP
    //         00448dcd     JNZ        LAB_00448ee3
    //                              Dsutil.c:1852 (27)
    //         00448dd3     MOV        EDX,dword ptr [ESP + 0x14]
    //         00448dd7     LEA        ECX,[ESP + 0x18]
    //         00448ddb     PUSH       ECX
    //         00448ddc     PUSH       DAT_00888468                                     = align(24)
    //         00448de1     PUSH       EDX=>DAT_fffffff4
    //         00448de2     PUSH       EAX=>DAT_fffffff0
    //         00448de3     MOV        EAX,[DAT_00888464]
    //         00448de8     PUSH       EAX
    //         00448de9     CALL       _WaveReadFile                                    undefined _WaveReadFile()
    //                              Dsutil.c:1853 (19)
    //         00448dee     MOV        EAX,dword ptr [ESP + 0x2c]
    //         00448df2     MOV        ESI,dword ptr [ESP + 0x20]
    //         00448df6     ADD        ESP,0x14
    //         00448df9     CMP        EAX,ESI
    //         00448dfb     JNC        LAB_00448f18
    //                              Dsutil.c:1855 (8)
    //         00448e01     CMP        dword ptr [DAT_008884ac],EBP
    //         00448e07     JNZ        LAB_00448e87
    //                              Dsutil.c:1858 (18)
    //         00448e09     MOV        ECX,dword ptr [_wiWave]
    //         00448e0f     CMP        ECX,EBP
    //         00448e11     JZ         LAB_00448e44
    //         00448e13     MOV        EDX,dword ptr [ESP + 0x14]
    //         00448e17     CMP        EDX,EBP
    //         00448e19     JZ         LAB_00448e44
    //                              Dsutil.c:1860 (10)
    //         00448e1b     MOV        CX,word ptr [ECX + 0xe]
    //         00448e1f     CMP        CX,0x8
    //         00448e23     JNZ        LAB_00448e2f
    //                              Dsutil.c:1861 (8)
    //         00448e25     SUB        ESI,EAX
    //         00448e27     PUSH       ESI
    //                              language.dll match for 0x80: "Arial"
    //         00448e28     PUSH       offset DAT_fffffff8
    //                              Dsutil.c:1862 (8)
    //         00448e2d     JMP        LAB_00448e39
    //                               LAB_00448e2f                                                 XREF[1]:     00448e23(j)  
    //         00448e2f     CMP        CX,0x10
    //         00448e33     JNZ        LAB_00448e44
    //                              Dsutil.c:1863 (15)
    //         00448e35     SUB        ESI,EAX
    //         00448e37     PUSH       ESI
    //         00448e38     PUSH       EBP=>DAT_fffffff8
    //                               LAB_00448e39                                                 XREF[1]:     00448e2d(j)  
    //         00448e39     ADD        EAX,EDX
    //         00448e3b     PUSH       EAX=>DAT_fffffff4
    //         00448e3c     CALL       memset                                           undefined memset()
    //         00448e41     ADD        ESP,0xc
    //                               LAB_00448e44                                                 XREF[3]:     00448e11(j), 00448e19(j), 
    //                                                                                                         00448e33(j)  
    //                              Dsutil.c:1867 (19)
    //         00448e44     MOV        ECX,dword ptr [ESP + 0x20]
    //         00448e48     MOV        EAX,[DAT_0088849c]
    //         00448e4d     CMP        ECX,EAX
    //         00448e4f     MOV        dword ptr [DAT_008884b0],EBX
    //         00448e55     JBE        LAB_00448e73
    //                              Dsutil.c:1870 (23)
    //         00448e57     MOV        EDX,dword ptr [DAT_00888494]
    //         00448e5d     ADD        EAX,EDX
    //         00448e5f     XOR        EDX,EDX
    //         00448e61     SUB        EAX,ECX
    //         00448e63     DIV        dword ptr [DAT_00888498]
    //         00448e69     MOV        [DAT_008884b4],EAX
    //                              Dsutil.c:1871 (5)
    //         00448e6e     JMP        LAB_00448f18
    //                               LAB_00448e73                                                 XREF[1]:     00448e55(j)  
    //                              Dsutil.c:1874 (15)
    //         00448e73     SUB        EAX,ECX
    //         00448e75     XOR        EDX,EDX
    //         00448e77     DIV        dword ptr [DAT_00888498]
    //         00448e7d     MOV        [DAT_008884b4],EAX
    //                              Dsutil.c:1876 (17)
    //         00448e82     JMP        LAB_00448f18
    //                               LAB_00448e87                                                 XREF[1]:     00448e07(j)  
    //         00448e87     MOV        ESI,dword ptr [ESP + 0x14]
    //         00448e8b     CMP        ESI,EBP
    //         00448e8d     JZ         LAB_00448f18
    //                               LAB_00448e93                                                 XREF[1]:     00448edf(j)  
    //                              Dsutil.c:1887 (4)
    //         00448e93     MOV        ECX,dword ptr [ESP + 0xc]
    //                              Dsutil.c:1890 (28)
    //         00448e97     PUSH       null_0088847c                                    = align(4)
    //         00448e9c     SUB        ECX,EAX
    //         00448e9e     PUSH       DAT_00888468                                     = align(24)
    //         00448ea3     PUSH       DAT_00888464
    //         00448ea8     ADD        ESI,EAX
    //         00448eaa     MOV        dword ptr [ESP + 0x18],ECX
    //         00448eae     CALL       _WaveStartDataRead                               undefined _WaveStartDataRead()
    //                              Dsutil.c:1893 (31)
    //         00448eb3     MOV        ECX,dword ptr [ESP + 0x18]
    //         00448eb7     MOV        EDX,dword ptr [DAT_00888464]
    //         00448ebd     ADD        ESP,0xc
    //         00448ec0     LEA        EAX,[ESP + 0x18]
    //         00448ec4     PUSH       EAX
    //         00448ec5     PUSH       DAT_00888468                                     = align(24)
    //         00448eca     PUSH       ESI=>DAT_fffffff4
    //         00448ecb     PUSH       ECX=>DAT_fffffff0
    //         00448ecc     PUSH       EDX
    //         00448ecd     CALL       _WaveReadFile                                    undefined _WaveReadFile()
    //                              Dsutil.c:1894 (15)
    //         00448ed2     MOV        EAX,dword ptr [ESP + 0x2c]
    //         00448ed6     MOV        ECX,dword ptr [ESP + 0x20]
    //         00448eda     ADD        ESP,0x14
    //         00448edd     CMP        EAX,ECX
    //         00448edf     JC         LAB_00448e93
    //                              Dsutil.c:1904 (10)
    //         00448ee1     JMP        LAB_00448f18
    //                               LAB_00448ee3                                                 XREF[2]:     00448dc5(j), 00448dcd(j)  
    //         00448ee3     CMP        EAX,EBP
    //         00448ee5     JZ         LAB_00448f18
    //         00448ee7     CMP        ECX,EBP
    //         00448ee9     JZ         LAB_00448f18
    //                              Dsutil.c:1907 (18)
    //         00448eeb     MOV        ESI,dword ptr [_wiWave]
    //         00448ef1     CMP        ESI,EBP
    //         00448ef3     JZ         LAB_00448f18
    //         00448ef5     MOV        ECX,dword ptr [ESP + 0x14]
    //         00448ef9     CMP        ECX,EBP
    //         00448efb     JZ         LAB_00448f18
    //                              Dsutil.c:1910 (27)
    //         00448efd     PUSH       EAX
    //         00448efe     XOR        EAX,EAX
    //         00448f00     CMP        word ptr [ESI + 0xe],0x8
    //         00448f05     SETNZ      AL
    //         00448f08     DEC        EAX
    //         00448f09     AND        EAX,0x80
    //         00448f0e     PUSH       EAX=>DAT_fffffff8
    //         00448f0f     PUSH       ECX=>DAT_fffffff4
    //         00448f10     CALL       memset                                           undefined memset()
    //         00448f15     ADD        ESP,0xc
    //                               LAB_00448f18                                                 XREF[9]:     00448dfb(j), 00448e6e(j), 
    //                                                                                                         00448e82(j), 00448e8d(j), 
    //                                                                                                         00448ee1(j), 00448ee5(j), 
    //                                                                                                         00448ee9(j), 00448ef3(j), 
    //                                                                                                         00448efb(j)  
    //                              Dsutil.c:1913 (24)
    //         00448f18     MOV        ECX,dword ptr [ESP + 0x10]
    //         00448f1c     CMP        ECX,EBP
    //         00448f1e     JZ         LAB_00449083
    //         00448f24     CMP        dword ptr [DAT_008884a8],EBP
    //         00448f2a     JNZ        LAB_00449045
    //                              Dsutil.c:1916 (28)
    //         00448f30     MOV        EAX,dword ptr [ESP + 0x1c]
    //         00448f34     LEA        EDX,[ESP + 0x18]
    //         00448f38     PUSH       EDX
    //         00448f39     PUSH       DAT_00888468                                     = align(24)
    //         00448f3e     PUSH       EAX=>DAT_fffffff4
    //         00448f3f     PUSH       ECX=>DAT_fffffff0
    //         00448f40     MOV        ECX,dword ptr [DAT_00888464]
    //         00448f46     PUSH       ECX
    //         00448f47     CALL       _WaveReadFile                                    undefined _WaveReadFile()
    //                              Dsutil.c:1917 (19)
    //         00448f4c     MOV        EAX,dword ptr [ESP + 0x2c]
    //         00448f50     MOV        ECX,dword ptr [ESP + 0x24]
    //         00448f54     ADD        ESP,0x14
    //         00448f57     CMP        EAX,ECX
    //         00448f59     JNC        LAB_00449083
    //                              Dsutil.c:1919 (12)
    //         00448f5f     CMP        dword ptr [DAT_008884ac],EBP
    //         00448f65     JNZ        LAB_00448fed
    //                              Dsutil.c:1922 (18)
    //         00448f6b     MOV        EDX,dword ptr [_wiWave]
    //         00448f71     CMP        EDX,EBP
    //         00448f73     JZ         LAB_00448faa
    //         00448f75     MOV        ESI,dword ptr [ESP + 0x1c]
    //         00448f79     CMP        ESI,EBP
    //         00448f7b     JZ         LAB_00448faa
    //                              Dsutil.c:1924 (10)
    //         00448f7d     MOV        DX,word ptr [EDX + 0xe]
    //         00448f81     CMP        DX,0x8
    //         00448f85     JNZ        LAB_00448f91
    //                              Dsutil.c:1925 (8)
    //         00448f87     SUB        ECX,EAX
    //         00448f89     PUSH       ECX
    //                              language.dll match for 0x80: "Arial"
    //         00448f8a     PUSH       offset DAT_fffffff8
    //                              Dsutil.c:1926 (8)
    //         00448f8f     JMP        LAB_00448f9b
    //                               LAB_00448f91                                                 XREF[1]:     00448f85(j)  
    //         00448f91     CMP        DX,0x10
    //         00448f95     JNZ        LAB_00448faa
    //                              Dsutil.c:1927 (19)
    //         00448f97     SUB        ECX,EAX
    //         00448f99     PUSH       ECX
    //         00448f9a     PUSH       EBP=>DAT_fffffff8
    //                               LAB_00448f9b                                                 XREF[1]:     00448f8f(j)  
    //         00448f9b     ADD        EAX,ESI
    //         00448f9d     PUSH       EAX=>DAT_fffffff4
    //         00448f9e     CALL       memset                                           undefined memset()
    //         00448fa3     MOV        ECX,dword ptr [ESP + 0x1c]
    //         00448fa7     ADD        ESP,0xc
    //                               LAB_00448faa                                                 XREF[3]:     00448f73(j), 00448f7b(j), 
    //                                                                                                         00448f95(j)  
    //                              Dsutil.c:1933 (19)
    //         00448faa     MOV        EDX,dword ptr [ESP + 0x20]
    //         00448fae     MOV        EAX,[DAT_0088849c]
    //         00448fb3     CMP        EDX,EAX
    //         00448fb5     MOV        dword ptr [DAT_008884b0],EBX
    //         00448fbb     JBE        LAB_00448fd9
    //                              Dsutil.c:1936 (23)
    //         00448fbd     MOV        ESI,dword ptr [DAT_00888494]
    //         00448fc3     ADD        EAX,ESI
    //         00448fc5     SUB        EAX,EDX
    //         00448fc7     XOR        EDX,EDX
    //         00448fc9     DIV        dword ptr [DAT_00888498]
    //         00448fcf     MOV        [DAT_008884b4],EAX
    //                              Dsutil.c:1937 (5)
    //         00448fd4     JMP        LAB_00449083
    //                               LAB_00448fd9                                                 XREF[1]:     00448fbb(j)  
    //                              Dsutil.c:1940 (15)
    //         00448fd9     SUB        EAX,EDX
    //         00448fdb     XOR        EDX,EDX
    //         00448fdd     DIV        dword ptr [DAT_00888498]
    //         00448fe3     MOV        [DAT_008884b4],EAX
    //                              Dsutil.c:1942 (17)
    //         00448fe8     JMP        LAB_00449083
    //                               LAB_00448fed                                                 XREF[1]:     00448f65(j)  
    //         00448fed     MOV        ESI,dword ptr [ESP + 0x1c]
    //         00448ff1     CMP        ESI,EBP
    //         00448ff3     JZ         LAB_00449083
    //                               LAB_00448ff9                                                 XREF[1]:     00449041(j)  
    //                              Dsutil.c:1956 (28)
    //         00448ff9     PUSH       null_0088847c                                    = align(4)
    //         00448ffe     SUB        ECX,EAX
    //         00449000     PUSH       DAT_00888468                                     = align(24)
    //         00449005     PUSH       DAT_00888464
    //         0044900a     ADD        ESI,EAX
    //         0044900c     MOV        dword ptr [ESP + 0x1c],ECX
    //         00449010     CALL       _WaveStartDataRead                               undefined _WaveStartDataRead()
    //                              Dsutil.c:1959 (31)
    //         00449015     MOV        EAX,dword ptr [ESP + 0x1c]
    //         00449019     MOV        ECX,dword ptr [DAT_00888464]
    //         0044901f     ADD        ESP,0xc
    //         00449022     LEA        EDX,[ESP + 0x18]
    //         00449026     PUSH       EDX
    //         00449027     PUSH       DAT_00888468                                     = align(24)
    //         0044902c     PUSH       ESI=>DAT_fffffff4
    //         0044902d     PUSH       EAX=>DAT_fffffff0
    //         0044902e     PUSH       ECX
    //         0044902f     CALL       _WaveReadFile                                    undefined _WaveReadFile()
    //                              Dsutil.c:1960 (15)
    //         00449034     MOV        EAX,dword ptr [ESP + 0x2c]
    //         00449038     MOV        ECX,dword ptr [ESP + 0x24]
    //         0044903c     ADD        ESP,0x14
    //         0044903f     CMP        EAX,ECX
    //         00449041     JC         LAB_00448ff9
    //                              Dsutil.c:1964 (32)
    //         00449043     JMP        LAB_00449083
    //                               LAB_00449045                                                 XREF[1]:     00448f2a(j)  
    //         00449045     CMP        ECX,EBP
    //         00449047     JZ         LAB_00449083
    //         00449049     CMP        dword ptr [DAT_008884a8],EBP
    //         0044904f     JZ         LAB_00449083
    //         00449051     MOV        EDX,dword ptr [_wiWave]
    //         00449057     CMP        EDX,EBP
    //         00449059     JZ         LAB_00449083
    //         0044905b     MOV        EAX,dword ptr [ESP + 0x1c]
    //         0044905f     CMP        EAX,EBP
    //         00449061     JZ         LAB_00449083
    //                              Dsutil.c:1969 (32)
    //         00449063     PUSH       ECX
    //         00449064     XOR        ECX,ECX
    //         00449066     CMP        word ptr [EDX + 0xe],0x8
    //         0044906b     SETNZ      CL
    //         0044906e     DEC        ECX
    //         0044906f     AND        ECX,0x80
    //         00449075     PUSH       ECX=>DAT_fffffff8
    //         00449076     PUSH       EAX=>DAT_fffffff4
    //         00449077     CALL       memset                                           undefined memset()
    //         0044907c     MOV        ECX,dword ptr [ESP + 0x1c]
    //         00449080     ADD        ESP,0xc
    //                               LAB_00449083                                                 XREF[10]:    00448f1e(j), 00448f59(j), 
    //                                                                                                         00448fd4(j), 00448fe8(j), 
    //                                                                                                         00448ff3(j), 00449043(j), 
    //                                                                                                         00449047(j), 0044904f(j), 
    //                                                                                                         00449059(j), 00449061(j)  
    //                              Dsutil.c:1972 (9)
    //         00449083     MOV        EAX,[DAT_00888490]
    //         00449088     CMP        EAX,EBP
    //         0044908a     JZ         LAB_004490a2
    //                              Dsutil.c:1975 (22)
    //         0044908c     PUSH       ECX
    //         0044908d     MOV        ECX,dword ptr [ESP + 0x20]
    //         00449091     MOV        EDX,dword ptr [EAX]
    //         00449093     PUSH       ECX=>DAT_fffffff8
    //         00449094     MOV        ECX,dword ptr [ESP + 0x14]
    //         00449098     PUSH       ECX=>DAT_fffffff4
    //         00449099     MOV        ECX,dword ptr [ESP + 0x20]
    //         0044909d     PUSH       ECX=>DAT_fffffff0
    //         0044909e     PUSH       EAX
    //         0044909f     CALL       dword ptr [EDX + 0x4c]
    //                               LAB_004490a2                                                 XREF[1]:     0044908a(j)  
    //                              Dsutil.c:1977 (11)
    //         004490a2     MOV        EAX,[DAT_0088849c]
    //         004490a7     MOV        ESI,dword ptr [DAT_00888498]
    //                              Dsutil.c:1978 (17)
    //         004490ad     MOV        ECX,dword ptr [DAT_00888494]
    //         004490b3     ADD        EAX,ESI
    //         004490b5     CMP        EAX,ECX
    //         004490b7     MOV        [DAT_0088849c],EAX
    //         004490bc     JC         LAB_004490c5
    //                               LAB_004490be                                                 XREF[1]:     00448d76(j)  
    //                              Dsutil.c:1979 (7)
    //         004490be     SUB        EAX,ECX
    //         004490c0     MOV        [DAT_0088849c],EAX
    //                               LAB_004490c5                                                 XREF[11]:    00448bd3(j), 00448be0(j), 
    //                                                                                                         00448c0e(j), 00448c2a(j), 
    //                                                                                                         00448cb7(j), 00448cc4(j), 
    //                                                                                                         00448cf5(j), 00448d70(j), 
    //                                                                                                         00448d82(j), 00448db3(j), 
    //                                                                                                         004490bc(j)  
    //                              Dsutil.c:1740 (6)
    //         004490c5     MOV        dword ptr [DAT_0062e658],EBP
    //                               LAB_004490cb                                                 XREF[2]:     00448baf(j), 00448bbb(j)  
    //                              Dsutil.c:1983 (9)
    //         004490cb     POP        ESI
    //         004490cc     POP        EBP
    //         004490cd     POP        EBX
    //         004490ce     ADD        ESP,0x1c
    //         004490d1     RET        0x14
}

